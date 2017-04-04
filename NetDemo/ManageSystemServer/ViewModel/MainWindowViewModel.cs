
using ManageSystem.Server;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Configuration;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Threading;

namespace ManageSystemServer.ViewModel
{
    class DeviceStatus : NotificationObject
    {
        private string _ip;
        public string ip
        {
            get { return _ip; }
            set
            {
                _ip = value;
                this.RaisePropertyChanged("ip");
            }
        }

        private string _serverip;
        public string serverip
        {
            get { return _serverip; }
            set
            {
                _serverip = value;
                this.RaisePropertyChanged("serverip");
            }
        }


        private bool _bDevice;
        public bool bDevice
        {
            get { return _bDevice; }
            set
            {
                _bDevice = value;
                this.RaisePropertyChanged("bDevice");
            }
        }

        private bool _bNormal;
        public bool bNormal
        {
            get { return _bNormal; }
            set
            {
                _bNormal = value;
                this.RaisePropertyChanged("bNormal");
            }
        }
    }
    public class DataGridItemSourceConvert : IValueConverter
    {
        #region IValueConverter 成员
        public object Convert(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            string str = value.GetType().ToString();
            if (value.GetType() == typeof(DataGrid))
            {
                DataGrid grid = value as DataGrid;

                string strtype = grid.DataContext.GetType().ToString();
                if (grid.DataContext.GetType() == typeof(MainWindowViewModel))
                {
                    MainWindowViewModel model = grid.DataContext as MainWindowViewModel;
                    grid.AutoGeneratingColumn += model.DG1_AutoGeneratingColumn;

                    return model.tableList;
                } 
            }

            return null;
        }
        public object ConvertBack(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            return null;
        }
        #endregion
    }

    class MainWindowViewModel : NotificationObject
    {
        public string                           _connectionsStr;
        public Dictionary<string, string> _columnNameMap = new Dictionary<string, string>
        {
            {"bDevice",					"是否是设备"},
            {"ip",			            "IP地址"},
            {"serverip",			    "socket地址"},
            {"bNormal",				    "是否正常"},
        };

        public DelegateCommand<object>          StartServerCommand { get; set; }
        public DelegateCommand<object>          StopServerCommand { get; set; }
        public DelegateCommand<object>          ExitCommand { get; set; }

        private bool _bOnline;
        public bool bOnline
        {
            get { return _bOnline; }
            set
            {
                _bOnline = value;
                this.RaisePropertyChanged("bOnline");
            }
        }

        private string _curConnections;
        public string curConnections
        {
            get { return _curConnections; }
            set
            {
                _curConnections = value;
                this.RaisePropertyChanged("curConnections");
            }
        }

        private ObservableCollection<DeviceStatus> _tableList;
        public ObservableCollection<DeviceStatus> tableList
        {
            get
            {
                return _tableList;
            }
            set
            {
                _tableList = value;
                this.RaisePropertyChanged("tableList");
            }
        }

        public MainWindowViewModel()
        { 
            StartServerCommand      = new DelegateCommand<object>(this.StartServer);
            StopServerCommand       = new DelegateCommand<object>(this.StopServer);
            ExitCommand             = new DelegateCommand<object>(new Action<object>(this.ExitWnd));

            curConnections          = "未检测";
            _connectionsStr         = "";
            _tableList              = new ObservableCollection<DeviceStatus>();

            var _timer              = new DispatcherTimer();
            _timer.Interval         = new TimeSpan(0, 0, 5);   //间隔1秒
            _timer.Tick             += new EventHandler(Timer_Tick);
            _timer.Start();

        }

        //Access and update columns during autogeneration
        public void DG1_AutoGeneratingColumn(object sender, DataGridAutoGeneratingColumnEventArgs e)
        {
            string headername = e.Column.Header.ToString();
            //Cancel the column you don't want to generate
            if (_columnNameMap.ContainsKey(headername))
            {
                e.Column.Header = _columnNameMap[headername];
            }
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            try
            {
                bOnline         = WorkServer.isServerStoped() == false;
                curConnections  = WorkServer.cntServerConnections() + "个";

                IntPtr strPtr = WorkServer.curConnectionsStr();
                string resultStr =  Marshal.PtrToStringAnsi(strPtr);
                if (resultStr != _connectionsStr)
                {
                    _connectionsStr = resultStr;
                    tableList.Clear();
                    QueryTableCallBack(_connectionsStr, "");
                }
            }
            catch { }
        }

        public void QueryTableCallBack(string resultStr, string errorStr)
        {
            if(resultStr == null || resultStr.Length == 0)
                return;
            Type type = typeof(DeviceStatus);

            if (type == null)
                return;

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
                                    item.SetValue(model, keyvalue[1], null);
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

                    DeviceStatus modelTemp = model as DeviceStatus;
                    tableList.Add(modelTemp);
                }
            }
        }

        private void StopServer(object obj)
        {
            WorkServer.stopServer();
        }

        private void StartServer(object obj)
        {
            Configuration config                 = ConfigurationManager.OpenExeConfiguration("ManageSystem.exe");
            string  ip      = "";
            int     port    = 0;
            foreach (KeyValueConfigurationElement kv0 in config.AppSettings.Settings)
            {    //检索当前选中的分辨率
                if (kv0.Key == "ServerIP")
                {
                    ip = "";
                }
                else if (kv0.Key  == "ServerPort")
                {
                    port = Convert.ToInt32(kv0.Value);
                }
            }

            WorkServer.startServer(ip, port);
        }

        public void ExitWnd(object obj)
        {
            try
            {
                App.Current.Shutdown();
            }
            catch (Exception ex)
            {
            }
        }
    }
}
