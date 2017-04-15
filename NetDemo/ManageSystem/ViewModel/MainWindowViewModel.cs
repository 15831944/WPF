using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using ManageSystem.Server;
using System.Windows.Data;
using System.Collections.ObjectModel;
using ManageSystem.Model;
using System.Runtime.InteropServices;
using System.Net;
using System.Configuration;
using System.Windows.Threading;
using System.Threading;
using ManageSystem.ViewModel.DeviceViewModel;
using System.Xml;
using System.ComponentModel;
namespace ManageSystem.ViewModel
{
    public enum PageVisibleEnum
    {
        PageVisibleEnum_Logon,
        PageVisibleEnum_Home,
        PageVisibleEnum_SummaryStat,
        PageVisibleEnum_SignStat,
        PageVisibleEnum_SignAnomalyStat,
        PageVisibleEnum_SignQuery,
        PageVisibleEnum_CardQuery,
        PageVisibleEnum_EndorsementQuery,
        PageVisibleEnum_PaymentQuery,
        PageVisibleEnum_QueryQuery,
        PageVisibleEnum_PreAcceptQuery,
        PageVisibleEnum_WebBrowser,
        PageVisibleEnum_DeviceManage,
    }
    public enum ShowChartEnum
    {
        ShowChartEnum_Pie,
        ShowChartEnum_Line,
        ShowChartEnum_Histogram,
        ShowChartEnum_Occupancy,
    }

    [System.Runtime.InteropServices.ComVisible(true)]
    public class ObjectForScripingHelper
    {
        MainWindowViewModel mainwindowviewmodel = null;
        public ObjectForScripingHelper(MainWindowViewModel model)
        {
            mainwindowviewmodel = model;
        }

        public void ExternalCallBack4Gis(string callback, string msg)
        {
           if(msg != null && msg.Length > 0 && mainwindowviewmodel != null)
           {
               XmlDocument doc = new XmlDocument();
               doc.LoadXml(msg);
               XmlElement xml = doc.DocumentElement;;
               string ip = xml.GetElementsByTagName("id")[0].InnerText;
               string stationName = xml.GetElementsByTagName("sid")[0].InnerText;


               switch(callback)
               {
                   case "统计":
                   case "查询":
                        foreach (DeviceModel model0 in DevicemaViewModel._deviceList)
                       {//市
                           foreach (DeviceModel model1 in model0.Children)
                           {//局
                               foreach (DeviceModel model2 in model1.Children)
                               {//单位
                                   foreach (DeviceModel model3 in model2.Children)
                                   {//IP
                                       model0.isSel = false;
                                       model1.isSel = false;
                                       model2.isSel = false;
                                       model3.isSel = false;
                                   }
                               }
                           }
                       }

                       foreach (DeviceModel model0 in DevicemaViewModel._deviceList)
                       {//市
                           foreach (DeviceModel model1 in model0.Children)
                           {//局
                               foreach (DeviceModel model2 in model1.Children)
                               {//单位
                                   foreach (DeviceModel model3 in model2.Children)
                                   {//IP
                                       if (model2.text == stationName && model3.text == ip)
                                       {
                                           model0.isSel = true;
                                           model1.isSel = true;
                                           model2.isSel = true;
                                           model3.isSel = true;
                                       }
                                   }
                               }
                           }
                       }
                       break;
                   case "管理":
                       {
                           mainwindowviewmodel._DeviceManageViewModel._DevicemaViewModel.tableList.Clear();
                           foreach(var model in mainwindowviewmodel._DeviceManageViewModel._DevicemaViewModel._tableListTemp)
                           {
                               if (model.Shiyongdanweibianhao == stationName && model.IP == ip)
                               {
                                   mainwindowviewmodel._DeviceManageViewModel._DevicemaViewModel.tableList.Add(model);
                               }
                           }
                       }
                       break;
               }


               switch (callback)
               {
                   case "统计":
                       mainwindowviewmodel.StatisticsSelected(null);
                       break;
                   case "查询":
                       mainwindowviewmodel.QuerySelected(null);
                       break;
                   case "管理":
                       mainwindowviewmodel._DeviceManageViewModel.bShowPage = DeviceVisibleEnum.DeviceVisibleEnum_Device;
                       mainwindowviewmodel.DeviceManageShow(null);
                       break;
               }
           }
        }
    }

    public class MainWindowViewModel : NotificationObject
    {  
        public QueryTableCallBackDelegate               _querytablecallbackdelegate = null;
 
        public DelegateCommand<object>                  HomePageCommand { get; set; }
        public DelegateCommand<object>                  StatisticsCommand { get; set; }
        public DelegateCommand<object>                  SignStatCommand { get; set; }
        public DelegateCommand<object>                  SignAnomalyStatCommand { get; set; }
        public DelegateCommand<object>                  QueryCommand { get; set; }
        public DelegateCommand<object>                  CardQueryCommand { get; set; }
        public DelegateCommand<object>                  EndorsementQueryCommand { get; set; }
        public DelegateCommand<object>                  PaymentQueryCommand { get; set; }
        public DelegateCommand<object>                  QueryQueryCommand { get; set; }
        public DelegateCommand<object>                  PreAcceptQueryCommand { get; set; }
        public DelegateCommand<object>                  WebBrowserCommand { get; set; }
        public DelegateCommand<object>                  DeviceManageCommand { get; set; }

        public DelegateCommand<object>                  StatisticsSelectedCommand { get; set; }
        public DelegateCommand<object>                  QuerySelectedCommand { get; set; }
        public DelegateCommand<object>                  SelectedItemCommand { get; set; }
        public DelegateCommand<object>                  UnSelectedItemCommand { get; set; }

        public DelegateCommand<object>                  LoadedCommand { get; set; }
        public DelegateCommand<object>                  ExitCommand { get; set; }
        public DelegateCommand<object>                  MaxCommand { get; set; }
        public DelegateCommand<object>                  MinCommand { get; set; }
        public DelegateCommand<object>                  DragWndCommand { get; set; }
        public DelegateCommand<RoutedEventArgs>         DoubleClickCommand {get; set; }
        public DelegateCommand<object>                  LogonCommand { get; set; }

        public HomePageViewModel                        _HomePageViewModel { get; set; }
        public SummaryStatViewModel                     _SummaryStatViewModel { get; set; }
        public SignStatViewModel                        _SignStatViewModel { get; set; }
        public SignAnomalyStatViewModel                 _SignAnomalyStatViewModel { get; set; }
        public SignQueryViewModel                       _SignQueryViewModel { get; set; }
        public CardQueryViewModel                       _CardQueryViewModel { get; set; }
        public EndorsementQueryViewModel                _EndorsementQueryViewModel { get; set; }
        public PaymentQueryViewModel                    _PaymentQueryViewModel { get; set; }
        public QueryQueryViewModel                      _QueryQueryViewModel { get; set; }
        public PreAcceptQueryViewModel                  _PreAcceptQueryViewModel { get; set; }
        public WebBrowserViewMode                       _WebBrowserViewMode { get; set; }
        public DeviceManageViewModel                    _DeviceManageViewModel { get; set; }

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

        public static Dictionary<Int32, string> _yingshelList               = new Dictionary<Int32, string>();
        public Dictionary<Int32, string> yingshelList
        {
            get { return _yingshelList; }
            set
            {
                _yingshelList = value;
                this.RaisePropertyChanged("yingshelList");
            }
        }

        public static ObservableCollection<string> _businesstype;
        public ObservableCollection<string> businesstype
        {
            get
            {
                return _businesstype;
            }
            set
            {
                _businesstype = value;
                this.RaisePropertyChanged("businesstype");
            }
        }

        private ObservableCollection<string> _cardstatus;
        public ObservableCollection<string> cardstatus
        {
            get
            {
                return _cardstatus;
            }
            set
            {
                _cardstatus = value;
                this.RaisePropertyChanged("cardstatus");
            }
        }

        private ObservableCollection<string> _certificateType;
        public ObservableCollection<string> certificateType
        {
            get
            {
                return _certificateType;
            }
            set
            {
                _certificateType = value;
                this.RaisePropertyChanged("certificateType");
            }
        }

        private ObservableCollection<string> _devicePosition;
        public ObservableCollection<string> devicePosition
        {
            get
            {
                return _devicePosition;
            }
            set
            {
                _devicePosition = value;
                this.RaisePropertyChanged("devicePosition");
            }
        }

        private PageVisibleEnum _bShowPage;
        public PageVisibleEnum bShowPage
        {
            get { return _bShowPage; }
            set
            {
                _bShowPage = value;
                this.RaisePropertyChanged("bShowPage");
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

        private double _leftWidth;
        public double leftWidth
        {
            get { return _leftWidth; }
            set
            {
                _leftWidth = value;
                this.RaisePropertyChanged("leftWidth");
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

        private double  _progressValue;
        public double  progressValue
        {
            get { return _progressValue; }
            set
            {
                _progressValue = value;
                this.RaisePropertyChanged("progressValue");
            }
        }

        private ObservableCollection<string> _statisticsStrs;
        public ObservableCollection<string> statisticsStrs
        {
            get
            {
                return _statisticsStrs;
            }
            set
            {
                _statisticsStrs = value;
                this.RaisePropertyChanged("statisticsStrs");
            }
        }

        private int  _statisticsIndex;
        public int statisticsIndex
        {
            get { return _statisticsIndex; }
            set
            {
                _statisticsIndex = value;
                this.RaisePropertyChanged("statisticsIndex");
            }
        }

        private ObservableCollection<string> _queryStrs;
        public ObservableCollection<string> queryStrs
        {
            get
            {
                return _queryStrs;
            }
            set
            {
                _queryStrs = value;
                this.RaisePropertyChanged("queryStrs");
            }
        }

        private int  _queryIndex;
        public int queryIndex
        {
            get { return _queryIndex; }
            set
            {
                _queryIndex = value;
                this.RaisePropertyChanged("queryIndex");
            }
        }

        private string  _IP;
        public string IP
        {
            get { return _IP; }
            set
            {
                _IP = value;
                this.RaisePropertyChanged("IP");
            }
        }

        private int  _port;
        public int port
        {
            get { return _port; }
            set
            {
                _port = value;
                this.RaisePropertyChanged("port");
            }
        }

        private bool  _bDevice;
        public bool bDevice
        {
            get { return _bDevice; }
            set
            {
                _bDevice = value;
                this.RaisePropertyChanged("bDevice");
            }
        }

        private ObjectForScripingHelper  _scripinghelper;
        public ObjectForScripingHelper scripinghelper
        {
            get { return _scripinghelper; }
            set
            {
                _scripinghelper = value;
                this.RaisePropertyChanged("scripinghelper");
            }
        }

        public MainWindowViewModel()
        {
            _querytablecallbackdelegate                 = new QueryTableCallBackDelegate(QueryTableCallBack);

            HomePageCommand                             = new DelegateCommand<object>(new Action<object>(this.mainPageShow));
            StatisticsCommand                           = new DelegateCommand<object>(new Action<object>(this.StatisticsShow));
            QueryCommand                                = new DelegateCommand<object>(new Action<object>(this.QueryShow));
            WebBrowserCommand                           = new DelegateCommand<object>(new Action<object>(this.WebBrowserShow));
            DeviceManageCommand                         = new DelegateCommand<object>(new Action<object>(this.DeviceManageShow));
            
            LogonCommand                                = new DelegateCommand<object>(new Action<object>(this.Logon));

            
            StatisticsSelectedCommand                   = new DelegateCommand<object>(new Action<object>(this.StatisticsSelected));
            QuerySelectedCommand                        = new DelegateCommand<object>(new Action<object>(this.QuerySelected));
            SelectedItemCommand                         = new DelegateCommand<object>(new Action<object>(this.SelectedItem));
            UnSelectedItemCommand                       = new DelegateCommand<object>(new Action<object>(this.UnSelectedItem));

            LoadedCommand                               = new DelegateCommand<object>(new Action<object>(this.Loaded));
            ExitCommand                                 = new DelegateCommand<object>(new Action<object>(this.ExitWnd));
            MaxCommand                                  = new DelegateCommand<object>(new Action<object>(this.MaxWnd));
            MinCommand                                  = new DelegateCommand<object>(new Action<object>(this.MinWnd));
            DragWndCommand                              = new DelegateCommand<object>(new Action<object>(this.DragWnd));
            DoubleClickCommand                          = new DelegateCommand<RoutedEventArgs>(new Action<RoutedEventArgs>(this.DoubleClickWnd));

            _HomePageViewModel                          = new HomePageViewModel();
            _SummaryStatViewModel                       = new SummaryStatViewModel();
            _SignStatViewModel                          = new SignStatViewModel();
            _SignAnomalyStatViewModel                   = new SignAnomalyStatViewModel();
            _SignQueryViewModel                         = new SignQueryViewModel();
            _CardQueryViewModel                         = new CardQueryViewModel();
            _EndorsementQueryViewModel                  = new EndorsementQueryViewModel();
            _PaymentQueryViewModel                      = new PaymentQueryViewModel();
            _QueryQueryViewModel                        = new QueryQueryViewModel();
            _PreAcceptQueryViewModel                    = new PreAcceptQueryViewModel();
            _WebBrowserViewMode                         = new WebBrowserViewMode();
            _DeviceManageViewModel                      = new DeviceManageViewModel();

            _cardstatus                                 = new ObservableCollection<string>();
            _certificateType                            = new ObservableCollection<string>();
            _devicePosition                             = new ObservableCollection<string>();
            _businesstype                               = new ObservableCollection<string>();

            //_bShowPage                                  = PageVisibleEnum.PageVisibleEnum_Logon;
            _bShowPage                                  = PageVisibleEnum.PageVisibleEnum_DeviceManage;

            _titleheight                                = 25;
            _leftWidth                                  = 60;
            _progressValue                              = 0;

            _statisticsIndex                            = 0;
            _queryIndex                                 = 0;
            _statisticsStrs                             = new ObservableCollection<string>();
            _queryStrs                                  = new ObservableCollection<string>();
            _scripinghelper                             = new ObjectForScripingHelper(this);

            _statisticsStrs.Add("汇总统计");
            _statisticsStrs.Add("制签统计");
            _statisticsStrs.Add("异常统计");
            _queryStrs.Add("制签记录查询");
            _queryStrs.Add("收证记录查询");
            _queryStrs.Add("签注记录查询");
            _queryStrs.Add("缴款记录查询");
            _queryStrs.Add("查询业务");
            _queryStrs.Add("预受理记录查询");


            IPAddress addr;
            //string temp = "193.171.42.10";
            string temp = "10.42.171.193";
            int aa = 0;
            if(IPAddress.TryParse(temp, out addr))
                aa = Convert.ToInt32(IPAddress.HostToNetworkOrder((Int32)Common.IpToInt(temp)));

            Common.IntToIp(IPAddress.NetworkToHostOrder((Int32)Convert.ToInt64(aa)));

            try
            {
                foreach (string key in ConfigurationManager.AppSettings)
                {
                    if (key == "ServerIP")
                    {
                        IP = ConfigurationManager.AppSettings[key];
                    }
                    else if (key == "ServerPort")
                    {
                        port = Convert.ToInt32(ConfigurationManager.AppSettings[key]);
                    }
                    else if (key == "bDevice")
                    {
                        bDevice = Convert.ToBoolean(ConfigurationManager.AppSettings[key]);
                    }
                }
            }
            catch
            {

            }

            var _timer                                  = new DispatcherTimer();
            _timer.Interval                             = new TimeSpan(0, 0, 5);   //间隔1秒
            _timer.Tick                                 += new EventHandler(Timer_Tick);
            _timer.Start();
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            try
            {
                bOnline         = WorkServer.isClientStoped() == false;
            }
            catch { }
        }

        public void QueryTableCallBack(string resultStr, string errorStr)
        {
            Type type = typeof(YINGSHEBIAOModel);

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
                        if (keyvalue.Length != 2 || keyvalue[1] == null || keyvalue[1].Length == 0)
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
                                            item.SetValue(model, Common.IntToIp(IPAddress.NetworkToHostOrder((Int32)Convert.ToInt64(keyvalue[1]))), null);
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

                    YINGSHEBIAOModel modelTemp = model as YINGSHEBIAOModel;
                    _yingshelList[modelTemp.Bianhao] = modelTemp.Mingcheng;
                }
            }
        }

        public void QueryYingshebiao(object obj)
        {
            _yingshelList.Clear();
            cardstatus.Clear();
            businesstype.Clear();
            certificateType.Clear();
            WorkServer.QueryTable("select * from Yingshebiao", Marshal.GetFunctionPointerForDelegate(_querytablecallbackdelegate), true);

            cardstatus.Add("全部");
            businesstype.Add("全部");
            certificateType.Add("全部");
            foreach (KeyValuePair<int, string> kvp0 in _yingshelList)
            {
                if (kvp0.Key >= 7000 && kvp0.Key < 8000)
                {
                    cardstatus.Add(kvp0.Value);
                }

                if (kvp0.Key >= 4000 && kvp0.Key < 5000)
                {
                    businesstype.Add(kvp0.Value);
                }

                if (kvp0.Key >= 5000 && kvp0.Key < 6000)
                {
                    devicePosition.Add(kvp0.Value);
                }

                if (kvp0.Key >= 9000 && kvp0.Key < 9011)
                {
                    certificateType.Add(kvp0.Value);
                }
            }
        }

        public void StatisticsSelected(object obj)
        {
            int selIndex = statisticsIndex;

            switch(selIndex)
            {
                case 0:
                    SummaryStatShow(null);
                    break;
                case 1:
                    SignStatShow(null);
                    break;
                case 2:
                    SignAnomalyShow(null);
                    break;
            }
        }

        public void QuerySelected(object obj)
        {
            int selIndex = queryIndex;

            switch (selIndex)
            {
                case 0:
                    SignQueryShow(null);
                    break;
                case 1:
                    CardQueryShow(null);
                    break;
                case 2:
                    EndorsementQueryShow(null);
                    break;
                case 3:
                    PaymentQueryShow(null);
                    break;
                case 4:
                    QueryQueryShow(null);
                    break;
                case 5:
                    PreAcceptQueryShow(null);
                    break;
            }
        }

        public void SelectedItem(object obj)
        {
            CheckBox changebox = obj as CheckBox;
            if (changebox.IsFocused == false)
                return;
            DeviceModel deviceModelChange = changebox.DataContext as DeviceModel;

            ////MakeChildrens
            foreach (DeviceModel child0 in deviceModelChange.Children)
            {
                child0.isSel  = true;
                foreach (DeviceModel child1 in child0.Children)
                {
                    child1.isSel  = true;
                    foreach (DeviceModel child2 in child1.Children)
                    {
                        child2.isSel  = true;
                    }
                }
            }

            ////MakeParent
            bool bBreak = false;
            foreach (DeviceModel parent0 in _DeviceManageViewModel._DevicemaViewModel.deviceList)
            {
                foreach (DeviceModel parent1 in parent0.Children)
                {
                    if (parent1 == deviceModelChange)
                    {
                        bBreak = true;
                        parent0.isSel = true;
                        break;
                    }
                    foreach (DeviceModel parent2 in parent1.Children)
                    {
                        if (parent2 == deviceModelChange)
                        {
                            bBreak = true;
                            parent0.isSel = true;
                            parent1.isSel = true;
                            break;
                        }

                        foreach (DeviceModel parent3 in parent2.Children)
                        {
                            if (parent3 == deviceModelChange)
                            {
                                bBreak = true;
                                parent0.isSel = true;
                                parent1.isSel = true;
                                parent2.isSel = true;
                                break;
                            }
                        }

                        if (bBreak) break;
                    }
                    if (bBreak) break;
                }
                if (bBreak) break;
            }
        }

        public void UnSelectedItem(object obj)
        {
            CheckBox changebox = obj as CheckBox;
            DeviceModel deviceModelChange = changebox.DataContext as DeviceModel;

            ////MakeChildrens
            foreach (DeviceModel child0 in deviceModelChange.Children)
            {
                child0.isSel  = false;
                foreach (DeviceModel child1 in child0.Children)
                {
                    child1.isSel  = false;
                    foreach (DeviceModel child2 in child1.Children)
                    {
                        child2.isSel  = false;
                    }
                }
            }
        }

        public void Logon(object obj)
        {
            if (logonName == null || logonName.Length == 0)
            {
                displayMsg = "用户名不能为空!";
                return;
            }
            if (logonPassword == null || logonPassword.Length == 0)
            {
                displayMsg = "密码不能为空!";
                return;
            }

            if (WorkServer.startClient(IP, port, bDevice))
            {
                bOnline         = true;
                displayMsg      = "连接服务端成功!";
                 _DeviceManageViewModel._UserViewModel.DoLogon();

                if (_DeviceManageViewModel._UserViewModel._guliyuanList.Keys.Count > 0)
                {
                    if (_DeviceManageViewModel._UserViewModel._guliyuanList.Keys.Contains(logonName))
                    {
                        if (_DeviceManageViewModel._UserViewModel._guliyuanList[logonName].Mima == logonPassword)
                        {
                            BackgroundWorker bgw= new BackgroundWorker();
                            bgw.WorkerSupportsCancellation = true;
                            bgw.WorkerReportsProgress = true;

                            bgw.DoWork += (object sender, DoWorkEventArgs e) => {
                                int progress = 0;
                                displayMsg      = "0" + "%";

                                Application.Current.Dispatcher.Invoke(
                                new Action(() =>
                                {
                                    QueryYingshebiao(null);
                                }));
                                progress        += 10;
                                (sender as BackgroundWorker) .ReportProgress(progress);
                                Thread.Sleep(100);

                                Application.Current.Dispatcher.Invoke(
                                new Action(() =>
                                {
                                    _DeviceManageViewModel._DevicemaViewModel.DoLogon();
                                }));
                                progress        += 10;
                                (sender as BackgroundWorker).ReportProgress(progress);
                                Thread.Sleep(100);

                                Application.Current.Dispatcher.Invoke(
                               new Action(() =>
                               {
                                   _DeviceManageViewModel._UpgradeViewModel.DoLogon();
                               }));
                                progress        += 10;
                                (sender as BackgroundWorker).ReportProgress(progress);
                                Thread.Sleep(100);

                                Application.Current.Dispatcher.Invoke(
                                new Action(() =>
                                {
                                    _WebBrowserViewMode.DoLogon();
                                }));
                                progress        += 10;
                                (sender as BackgroundWorker).ReportProgress(progress);
                                Thread.Sleep(100);

                                Application.Current.Dispatcher.Invoke(
                                new Action(() =>
                                {
                                }));
                                progress        += 10;
                                (sender as BackgroundWorker).ReportProgress(progress);
                                Thread.Sleep(100);

                                Application.Current.Dispatcher.Invoke(
                                new Action(() =>
                                {
                                }));
                                progress        += 10;
                                (sender as BackgroundWorker).ReportProgress(progress);
                                Thread.Sleep(100);

                                Application.Current.Dispatcher.Invoke(
                                new Action(() =>
                                {
                                }));
                                progress        += 10;
                                (sender as BackgroundWorker).ReportProgress(progress);
                                Thread.Sleep(100);

                                progress        = 100;
                                (sender as BackgroundWorker).ReportProgress(progress);
                                Thread.Sleep(100);
                            };
                            bgw.ProgressChanged += (object sender, ProgressChangedEventArgs e)=>
                                {
                                    progressValue   = e.ProgressPercentage;
                                    displayMsg      =  e.ProgressPercentage + "%";
                                };
                            bgw.RunWorkerCompleted += (object sender, RunWorkerCompletedEventArgs e) =>
                                {
                                    WebBrowserShow(null);

                                    progressValue = 0;
                                    displayMsg =  "";
                                };

                            bgw.RunWorkerAsync();  
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
            else
                displayMsg = "连接服务端失败!";
        }

        public void Loaded(object obj)
        {
            new Thread(() =>
            {
                 WorkServer.startClient(IP, port, true);

                 Application.Current.Dispatcher.Invoke(
                new Action(() =>
                {
                    _DeviceManageViewModel._UserViewModel.DoLogon();
                }));

                 Application.Current.Dispatcher.Invoke(
                 new Action(() =>
                 {
                     QueryYingshebiao(null);
                 }));

                 Application.Current.Dispatcher.Invoke(
                new Action(() =>
                {
                    _DeviceManageViewModel._DevicemaViewModel.DoLogon();
                }));

                 Application.Current.Dispatcher.Invoke(
                new Action(() =>
                {
                    _DeviceManageViewModel._UpgradeViewModel.DoLogon();
                }));

                 Application.Current.Dispatcher.Invoke(
                 new Action(() =>
                 {
                     _WebBrowserViewMode.DoLogon();
                 }));

                // Application.Current.Dispatcher.Invoke(
                //new Action(() =>
                //{
                //    _DeviceManageViewModel._NetViewModel.DoLogon();
                //}));
                 
                // Application.Current.Dispatcher.Invoke(
                //new Action(() =>
                //{
                //    _DeviceManageViewModel._AbnormalViewModel.DoLogon();
                //}));

                 //Application.Current.Dispatcher.Invoke(
                 //new Action(() =>
                 //{
                 //    _DeviceManageViewModel._HardwareViewModel.DoLogon();
                 //}));

            }).Start();


            //_SummaryStatViewModel.DoLogon();
            //_SignStatViewModel.DoLogon();
            //_SignAnomalyStatViewModel.DoLogon();
        }

        private void MaxWnd(object obj)
        {
            if(wndState == WindowState.Maximized)
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
                App.Current.Shutdown();
            }
            catch (Exception ex)
            {
            }
        }

        public void mainPageShow(object obj)
        {
            bShowPage                                   = PageVisibleEnum.PageVisibleEnum_Home;
            _HomePageViewModel.ResizeShowCharts();
            _SummaryStatViewModel.ResizeShowCharts();
            _SignStatViewModel.ResizeShowCharts();
            _SignAnomalyStatViewModel.ResizeShowCharts();
        }

        public void StatisticsShow(object obj)
        {
            StatisticsSelected(obj);
        }

        private void SummaryStatShow(object obj)
        {
            bShowPage                                   = PageVisibleEnum.PageVisibleEnum_SummaryStat;
            _HomePageViewModel.ResizeShowCharts();
            _SummaryStatViewModel.ResizeShowCharts();
            _SignStatViewModel.ResizeShowCharts();
            _SignAnomalyStatViewModel.ResizeShowCharts();
        }

        private void SignStatShow(object obj)
        {
            bShowPage                                   = PageVisibleEnum.PageVisibleEnum_SignStat;
            _HomePageViewModel.ResizeShowCharts();
            _SummaryStatViewModel.ResizeShowCharts();
            _SignStatViewModel.ResizeShowCharts();
            _SignAnomalyStatViewModel.ResizeShowCharts();
        }

        private void SignAnomalyShow(object obj)
        {
            bShowPage                                   = PageVisibleEnum.PageVisibleEnum_SignAnomalyStat;
            _HomePageViewModel.ResizeShowCharts();
            _SummaryStatViewModel.ResizeShowCharts();
            _SignStatViewModel.ResizeShowCharts();
            _SignAnomalyStatViewModel.ResizeShowCharts();
        }


        public void QueryShow(object obj)
        {
            QuerySelected(obj);
        }

        private void SignQueryShow(object obj)
        {
            bShowPage                                   = PageVisibleEnum.PageVisibleEnum_SignQuery;
            _HomePageViewModel.ResizeShowCharts();
            _SummaryStatViewModel.ResizeShowCharts();
            _SignStatViewModel.ResizeShowCharts();
            _SignAnomalyStatViewModel.ResizeShowCharts();
        }

        private void CardQueryShow(object obj)
        {
            bShowPage                                   = PageVisibleEnum.PageVisibleEnum_CardQuery;
            _HomePageViewModel.ResizeShowCharts();
            _SummaryStatViewModel.ResizeShowCharts();
            _SignStatViewModel.ResizeShowCharts();
            _SignAnomalyStatViewModel.ResizeShowCharts();
        }

        private void EndorsementQueryShow(object obj)
        {
            bShowPage                                   = PageVisibleEnum.PageVisibleEnum_EndorsementQuery;
            _HomePageViewModel.ResizeShowCharts();
            _SummaryStatViewModel.ResizeShowCharts();
            _SignStatViewModel.ResizeShowCharts();
            _SignAnomalyStatViewModel.ResizeShowCharts();
        }

        private void PaymentQueryShow(object obj)
        {
            bShowPage                                   = PageVisibleEnum.PageVisibleEnum_PaymentQuery;
            _HomePageViewModel.ResizeShowCharts();
            _SummaryStatViewModel.ResizeShowCharts();
            _SignStatViewModel.ResizeShowCharts();
            _SignAnomalyStatViewModel.ResizeShowCharts();
        }

        private void QueryQueryShow(object obj)
        {
            bShowPage                                   = PageVisibleEnum.PageVisibleEnum_QueryQuery;
            _HomePageViewModel.ResizeShowCharts();
            _SummaryStatViewModel.ResizeShowCharts();
            _SignStatViewModel.ResizeShowCharts();
            _SignAnomalyStatViewModel.ResizeShowCharts();
        }

        private void PreAcceptQueryShow(object obj)
        {
            bShowPage                                   = PageVisibleEnum.PageVisibleEnum_PreAcceptQuery;
            _HomePageViewModel.ResizeShowCharts();
            _SummaryStatViewModel.ResizeShowCharts();
            _SignStatViewModel.ResizeShowCharts();
            _SignAnomalyStatViewModel.ResizeShowCharts();
        }

        private void WebBrowserShow(object obj)
        {
            bShowPage                                   = PageVisibleEnum.PageVisibleEnum_WebBrowser;
            _HomePageViewModel.ResizeShowCharts();
            _SummaryStatViewModel.ResizeShowCharts();
            _SignStatViewModel.ResizeShowCharts();
            _SignAnomalyStatViewModel.ResizeShowCharts();

            //_WebBrowserViewMode.DoLogon();
        }

        public void DeviceManageShow(object obj)
        {
            bShowPage                                   = PageVisibleEnum.PageVisibleEnum_DeviceManage;
            _HomePageViewModel.ResizeShowCharts();
            _SummaryStatViewModel.ResizeShowCharts();
            _SignStatViewModel.ResizeShowCharts();
            _SignAnomalyStatViewModel.ResizeShowCharts();

            //_DeviceManageViewModel.DoLogon();
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
           if(args.ChangedButton == MouseButton.Left)
           {
               System.Windows.Point pp = Mouse.GetPosition(Application.Current.MainWindow);//WPF方法
               if (pp.Y >= 0 && pp.Y < titleheight)
               {
                   MaxWnd(null);
               }
           }
        }
    }
}
