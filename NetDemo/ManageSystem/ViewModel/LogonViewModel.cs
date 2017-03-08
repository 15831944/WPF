using ManageSystem.Interface;
using ManageSystem.Model;
using ManageSystem.Server;
using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.Net;
using System.Runtime.InteropServices;
using System.Text;
using System.Windows;
using System.Windows.Input;

namespace ManageSystem.ViewModel
{

    class LogonViewModel : NotificationObject
    {
        public IWindowFactory                       windowFactory{get;set;}
        public QueryTableCallBackDelegate           _querytablecallbackdelegate = null;
        public Dictionary<string, GUANLIYUANModel>  _guliyuanList               = new Dictionary<string,GUANLIYUANModel>();

        public DelegateCommand<object>              LogonCommand { get; set; }
        public DelegateCommand<object>              LoadedCommand { get; set; }
        public DelegateCommand<object>              ExitCommand { get; set; }
        public DelegateCommand<object>              MaxCommand { get; set; }
        public DelegateCommand<object>              MinCommand { get; set; }
        public DelegateCommand<object>              DragWndCommand { get; set; }
        public DelegateCommand<RoutedEventArgs>     DoubleClickCommand { get; set; }

        private string _displayMsg;
        public string displayMsg
        {
            get { return _displayMsg; }
            set
            {
                _displayMsg = value;
                this.RaisePropertyChanged("displayMsg");
            }
        }

        private double _titleheight;
        public double titleheight
        {
            get { return _titleheight; }
            set
            {
                _titleheight = value;
                this.RaisePropertyChanged("titleheight");
            }
        }

        private WindowState _wndState;
        public WindowState wndState
        {
            get { return _wndState; }
            set
            {
                _wndState = value;
                this.RaisePropertyChanged("wndState");
            }
        }

        private Visibility _visibility;
        public Visibility visibility
        {
            get { return _visibility; }
            set
            {
                _visibility = value;
                this.RaisePropertyChanged("visibility");
            }
        }

        private string _logonName;
        public string logonName
        {
            get { return _logonName; }
            set
            {
                _logonName = value;
                this.RaisePropertyChanged("logonName");
            }
        }

        private string _logonPassword;
        public string logonPassword
        {
            get { return _logonPassword; }
            set
            {
                _logonPassword = value;
                this.RaisePropertyChanged("logonPassword");
            }
        }

        public LogonViewModel()
        {
            _querytablecallbackdelegate                 = new QueryTableCallBackDelegate(QueryTableCallBack);
            LogonCommand                                = new DelegateCommand<object>(new Action<object>(this.Logon));
            LoadedCommand                               = new DelegateCommand<object>(new Action<object>(this.Loaded));
            ExitCommand                                 = new DelegateCommand<object>(new Action<object>(this.ExitWnd));
            MaxCommand                                  = new DelegateCommand<object>(new Action<object>(this.MaxWnd));
            MinCommand                                  = new DelegateCommand<object>(new Action<object>(this.MinWnd));
            DragWndCommand                              = new DelegateCommand<object>(new Action<object>(this.DragWnd));
            DoubleClickCommand                          = new DelegateCommand<RoutedEventArgs>(new Action<RoutedEventArgs>(this.DoubleClickWnd));

            _logonPassword                              ="";
            _titleheight                                = 30;
        }

        public void Logon(object obj)
        {

            windowFactory.ShowMainWindow();
            visibility = Visibility.Hidden;
            return;

            string  ip      = "";
            int     port    = 0;
            foreach (string key in ConfigurationManager.AppSettings)
            {    //检索当前选中的分辨率
                if (key == "ServerIP")
                {
                    ip = ConfigurationManager.AppSettings[key];
                }
                else if (key == "ServerPort")
                {
                    port = Convert.ToInt32(ConfigurationManager.AppSettings[key]);
                }
            }
            if(logonName == null || logonName.Length == 0)
            {
                displayMsg = "用户名不能为空!";
                return;
            }
            if (logonPassword == null || logonPassword.Length == 0)
            {
                displayMsg = "不能为空!";
                return;
            }

            if (WorkServer.startClient(ip, port, true))
            {
                displayMsg = "连接服务端成功!";
                if (windowFactory != null)
                {
                    QueryGuanliyuan(null);

                    if(_guliyuanList.Keys.Count > 0)
                    {
                        if(_guliyuanList.Keys.Contains(logonName))
                        {
                            if(_guliyuanList[logonName].Mima == logonPassword)
                            {
                                windowFactory.ShowMainWindow();
                                visibility = Visibility.Hidden;
                            }
                            else
                                displayMsg = "密码错误!";
                        }
                        else
                            displayMsg = "不存在的用户!";
                    }
                    else
                        displayMsg = "数据库用户表为空!";
                }
            }
            else
                displayMsg = "连接服务端失败!";
        }

        public void QueryTableCallBack(string resultStr, string errorStr)
        {
            Type type = typeof(GUANLIYUANModel);
            System.Reflection.PropertyInfo[] properties = type.GetProperties(System.Reflection.BindingFlags.Instance | System.Reflection.BindingFlags.Public);

            string[] rows = resultStr.Split(';');
            foreach (string row in rows)
            {
                if (row.Length > 0)
                {
                    var model= Activator.CreateInstance(type);

                    string[] cells = row.Split(',');
                    foreach (string cell in cells)
                    {
                        string[] keyvalue = cell.Split(':');
                        if (keyvalue.Length != 2)
                            continue;

                        foreach (System.Reflection.PropertyInfo item in properties)
                        {
                            if (item.Name == keyvalue[0])
                            {
                                if (item.PropertyType.Name.StartsWith("Int32"))
                                {
                                    item.SetValue(model, Convert.ToInt32(keyvalue[1]), null);
                                }
                                else if (item.PropertyType.Name.StartsWith("Int64"))
                                {
                                    item.SetValue(model, Convert.ToInt64(keyvalue[1]), null);
                                }
                                else if (item.PropertyType.Name.StartsWith("String"))
                                {
                                    switch (item.Name)
                                    {
                                        case "Chengshibianhao":
                                        case "Jubianhao":
                                        case "Shiyongdanweibianhao":
                                        case "Shebeibaifangweizhi":
                                        case "Qianzhuzhonglei":
                                        case "ZhikaZhuangtai":
                                        case "Zhengjianleixing":
                                        case "Xingbie":
                                        case "Yewuleixing":
                                            if (MainWindowViewModel._yingshelList.Keys.Contains(Convert.ToInt32(keyvalue[1])))
                                                item.SetValue(model, MainWindowViewModel._yingshelList[Convert.ToInt32(keyvalue[1])], null);
                                            break;
                                        case "Riqi":
                                        case "Chushengriqi":
                                        case "Jiaoyiriqi":
                                            DateTime datetime = Common.ConvertIntDateTime(Convert.ToInt64(keyvalue[1]));
                                            item.SetValue(model, datetime.ToShortDateString(), null);
                                            break;
                                        case "IP":
                                            item.SetValue(model, Common.IntToIp(IPAddress.NetworkToHostOrder(Convert.ToInt32(keyvalue[1]))), null);
                                            break;
                                        default:
                                            item.SetValue(model, keyvalue[1], null);
                                            break;
                                    }
                                }
                                else if (item.PropertyType.Name.StartsWith("Boolean"))
                                {
                                    item.SetValue(model, Convert.ToBoolean(Convert.ToInt32(keyvalue[1])), null);
                                }
                                else
                                {
                                    ;
                                }
                                break;
                            }
                        }
                    }  
                    GUANLIYUANModel modelTemp = model as GUANLIYUANModel;
                    _guliyuanList[modelTemp.Yonghuming] = modelTemp;
                }
            }
        }

        public void QueryGuanliyuan(object obj)
        {
            _guliyuanList.Clear();
            WorkServer.QueryTable("select * from Guanliyuan", Marshal.GetFunctionPointerForDelegate(_querytablecallbackdelegate), true);
        }
        public void Loaded(object obj)
        {

        }

        private void MaxWnd(object obj)
        {
            if (wndState == WindowState.Maximized)
                wndState = WindowState.Normal;
            else
                wndState = WindowState.Maximized;
        }
        private void MinWnd(object obj)
        {
            wndState = WindowState.Minimized;
        }
        public void ExitWnd(object obj)
        {
            try
            {
                WorkServer.stopClient();
                LineChartServer.UninitializeCurveModule();
                HistogramServer.UninitializeHistogramModule();
                OccupancyChartServer.UninitializeOccupancyModule();
                PieChartServer.UninitializePieModule();
                App.Current.Shutdown();
            }
            catch (Exception ex)
            {
            }
        }

        private void DragWnd(object obj)
        {
            Window wnd = obj as Window;
            System.Windows.Point pp = Mouse.GetPosition(wnd);//WPF方法
            if (pp.Y > 0 && pp.Y < titleheight)
                wnd.DragMove();
        }

        private void DoubleClickWnd(RoutedEventArgs e)
        {
            MouseButtonEventArgs args = e as MouseButtonEventArgs;
            if (args.ChangedButton == MouseButton.Left)
            {
                System.Windows.Point pp = Mouse.GetPosition(null);//WPF方法
                if (pp.Y > 0 && pp.Y < titleheight)
                {
                    MaxWnd(null);
                }
            }
        }
    }
}
