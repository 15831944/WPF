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
namespace ManageSystem.ViewModel
{
    enum PageVisibleEnum
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

    enum ShowChartEnum
    {
        ShowChartEnum_Pie,
        ShowChartEnum_Line,
        ShowChartEnum_Histogram,
        ShowChartEnum_Occupancy,
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
                if (grid.DataContext.GetType() == typeof(SignQueryViewModel))
                {
                    SignQueryViewModel model = grid.DataContext as SignQueryViewModel;
                    grid.AutoGeneratingColumn += model.DG1_AutoGeneratingColumn;

                    return model.tableList;
                }
                else if (grid.DataContext.GetType() == typeof(CardQueryViewModel))
                {
                    CardQueryViewModel model = grid.DataContext as CardQueryViewModel;
                    grid.AutoGeneratingColumn += model.DG1_AutoGeneratingColumn;    

                    return model.tableList;
                }
                else if (grid.DataContext.GetType() == typeof(EndorsementQueryViewModel))
                {
                    EndorsementQueryViewModel model = grid.DataContext as EndorsementQueryViewModel;
                    grid.AutoGeneratingColumn += model.DG1_AutoGeneratingColumn;

                    return model.tableList;
                }
                else if (grid.DataContext.GetType() == typeof(PaymentQueryViewModel))
                {
                    PaymentQueryViewModel model = grid.DataContext as PaymentQueryViewModel;
                    grid.AutoGeneratingColumn += model.DG1_AutoGeneratingColumn;

                    return model.tableList;
                }
                else if (grid.DataContext.GetType() == typeof(QueryQueryViewModel))
                {
                    QueryQueryViewModel model = grid.DataContext as QueryQueryViewModel;
                    grid.AutoGeneratingColumn += model.DG1_AutoGeneratingColumn;

                    return model.tableList;
                }
                else if (grid.DataContext.GetType() == typeof(PreAcceptQueryViewModel))
                {
                    PreAcceptQueryViewModel model = grid.DataContext as PreAcceptQueryViewModel;
                    grid.AutoGeneratingColumn += model.DG1_AutoGeneratingColumn;

                    return model.tableList;
                }
                else if (grid.DataContext.GetType() == typeof(DevicemaViewModel))
                {
                    DevicemaViewModel model = grid.DataContext as DevicemaViewModel;
                    grid.AutoGeneratingColumn += model.DG1_AutoGeneratingColumn;

                    return model.tableList;
                }
                else if (grid.DataContext.GetType() == typeof(UserViewModel))
                {
                    UserViewModel model = grid.DataContext as UserViewModel;
                    grid.AutoGeneratingColumn += UserViewModel.DG1_AutoGeneratingColumn;

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
        public enum QueryOperate
        {
            QueryOperate_None,
            QueryOperate_YingSheTable,
            QueryOperate_GuanLiYuan,
        }

        public QueryTableCallBackDelegate               _querytablecallbackdelegate = null;
        public QueryOperate                             _queryoperate = QueryOperate.QueryOperate_None;
        public Dictionary<string, GUANLIYUANModel>      _guliyuanList               = new Dictionary<string, GUANLIYUANModel>();
 
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
            _bShowPage                                  = PageVisibleEnum.PageVisibleEnum_WebBrowser;
            _titleheight                                = 25;
            _leftWidth                                  = 60;
            _progressValue                              = 0;

            _statisticsIndex                            = 0;
            _queryIndex                                 = 0;
            _statisticsStrs                             = new ObservableCollection<string>();
            _queryStrs                                  = new ObservableCollection<string>();
            _statisticsStrs.Add("汇总统计");
            _statisticsStrs.Add("制签统计");
            _statisticsStrs.Add("异常统计");
            _queryStrs.Add("签记录查询");
            _queryStrs.Add("收证记录查询");
            _queryStrs.Add("签注记录查询");
            _queryStrs.Add("缴款记录查询");
            _queryStrs.Add("查询业务");
            _queryStrs.Add("预受理记录查询");

            foreach (string key in ConfigurationManager.AppSettings)
            {    //检索当前选中的分辨率
                if (key == "ServerIP")
                {
                    _IP = ConfigurationManager.AppSettings[key];
                }
                else if (key == "ServerPort")
                {
                    _port = Convert.ToInt32(ConfigurationManager.AppSettings[key]);
                }
            }

            var _timer                                  = new DispatcherTimer();
            _timer.Interval                             = new TimeSpan(0, 0, 5);   //间隔1秒
            _timer.Tick                                 += new EventHandler(Timer_Tick);
            _timer.Start();
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            bOnline         = WorkServer.isClientStoped() == false;
        }

        public void QueryTableCallBack(string resultStr, string errorStr)
        {
            
            Type type = null;
            switch(_queryoperate)
            {
                case QueryOperate.QueryOperate_YingSheTable:
                    type = typeof(YINGSHEBIAOModel);
                    break;
                case QueryOperate.QueryOperate_GuanLiYuan:
                    type = typeof(GUANLIYUANModel);
                    break;
            }

            if(type == null)
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

                    switch (_queryoperate)
                    {
                        case QueryOperate.QueryOperate_YingSheTable:
                            {
                                YINGSHEBIAOModel modelTemp = model as YINGSHEBIAOModel;
                                _yingshelList[modelTemp.Bianhao] = modelTemp.Mingcheng;
                            }
                            break;
                        case QueryOperate.QueryOperate_GuanLiYuan:
                            {
                                GUANLIYUANModel modelTemp = model as GUANLIYUANModel;
                                _guliyuanList[modelTemp.Yonghuming] = modelTemp;
                            }
                            break;
                    }
                }
            }
            _queryoperate = QueryOperate.QueryOperate_None;
        }

        public void QueryYingshebiao(object obj)
        {
            _queryoperate = QueryOperate.QueryOperate_YingSheTable;
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
        public void QueryGuanliyuan(object obj)
        {
            _queryoperate = QueryOperate.QueryOperate_GuanLiYuan;
            _guliyuanList.Clear();
            WorkServer.QueryTable("select * from Guanliyuan", Marshal.GetFunctionPointerForDelegate(_querytablecallbackdelegate), true);
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

            if (WorkServer.startClient(IP, port, true))
            {
                bOnline         = true;
                displayMsg      = "连接服务端成功!";
                QueryGuanliyuan(null);

                if (_guliyuanList.Keys.Count > 0)
                {
                    if (_guliyuanList.Keys.Contains(logonName))
                    {
                        if (_guliyuanList[logonName].Mima == logonPassword)
                        {

                            Thread thread = new Thread(new ThreadStart(() =>
                            {
                                double progress = 0;
                                displayMsg      = "0" + "%";

                                progress        += 20;
                                progressValue   = progress;
                                displayMsg      =  progress + "%";
                                Thread.Sleep(10);

                                Application.Current.Dispatcher.Invoke(
                                new Action(() =>
                                {
                                    QueryYingshebiao(null);
                                }));
                                progress        += 10;
                                progressValue   = progress;
                                displayMsg      =  progress + "%";
                                Thread.Sleep(10);

                                Application.Current.Dispatcher.Invoke(
                                new Action(() =>
                                {
                                    _DeviceManageViewModel._DevicemaViewModel.QueryShebeiguanli(null);
                                }));
                                progress        += 10;
                                progressValue   = progress;
                                displayMsg      = progress + "%";
                                Thread.Sleep(10);

                                Application.Current.Dispatcher.Invoke(
                                new Action(() =>
                                {
                                    //_HomePageViewModel.DoLogon();
                                }));
                                progress        += 10;
                                progressValue   = progress;
                                displayMsg      =  progress + "%";
                                Thread.Sleep(10);

                                Application.Current.Dispatcher.Invoke(
                                new Action(() =>
                                {
                                    _SummaryStatViewModel.DoLogon();
                                }));
                                progress        += 10;
                                progressValue   = progress;
                                displayMsg      =  progress + "%";
                                Thread.Sleep(10);

                                Application.Current.Dispatcher.Invoke(
                                new Action(() =>
                                {
                                    _SignStatViewModel.DoLogon();
                                }));
                                progress        += 10;
                                progressValue   = progress;
                                displayMsg      =  progress + "%";
                                Thread.Sleep(10);

                                Application.Current.Dispatcher.Invoke(
                                new Action(() =>
                                {
                                    _SignAnomalyStatViewModel.DoLogon();
                                }));
                                progress        += 10;
                                progressValue   = progress;
                                displayMsg      =  progress + "%";
                                Thread.Sleep(10);

                                Application.Current.Dispatcher.Invoke(
                                new Action(() =>
                                {
                                    //_WebBrowserViewMode.DoLogon();
                                }));
                                progress        += 10;
                                progressValue   = progress;
                                displayMsg      =  progress + "%";
                                Thread.Sleep(10);

                                progress        = 100;
                                progressValue   = progress;
                                displayMsg      = progress + "%";
                                Thread.Sleep(10);


                                Application.Current.Dispatcher.Invoke(
                                new Action(() =>
                                {
                                    //mainPageShow(null);
                                    WebBrowserShow(null);
                                }));

                                progressValue = 0;
                                displayMsg =  "";
                            }));
                            thread.Start();
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
            WorkServer.startClient(IP, port, true);
            QueryYingshebiao(null);
            _DeviceManageViewModel._DevicemaViewModel.QueryShebeiguanli(null);
            _DeviceManageViewModel._UserViewModel.QueryYongHuguanli(null);

            _SummaryStatViewModel.DoLogon();
            _SignStatViewModel.DoLogon();
            _SignAnomalyStatViewModel.DoLogon();
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

        private void StatisticsShow(object obj)
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


        private void QueryShow(object obj)
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

            _WebBrowserViewMode.DoLogon();
        }

        private void DeviceManageShow(object obj)
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
               if (pp.Y > 0 && pp.Y < titleheight)
               {
                   MaxWnd(null);
               }
           }
        }
    }
}
