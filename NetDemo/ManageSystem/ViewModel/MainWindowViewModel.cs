using System;
using System.Collections.Generic;
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
namespace ManageSystem.ViewModel
{
    enum PageVisibleEnum
    {
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
            QueryOperate_Shebeiguanli,
        }
        public static Dictionary<string, Dictionary<string, Dictionary<string, HashSet<string>>>> _devicelistMap = new Dictionary<string, Dictionary<string, Dictionary<string, HashSet<string>>>>();

        public QueryTableCallBackDelegate               _querytablecallbackdelegate = null;
        public QueryOperate                             _queryoperate = QueryOperate.QueryOperate_None;
        public static Dictionary<Int32, string>         _yingshelList               = new Dictionary<Int32, string> ();
 
        public DelegateCommand<object>                  HomePageCommand { get; set; }
        public DelegateCommand<object>                  SummaryStatCommand { get; set; }
        public DelegateCommand<object>                  SignStatCommand { get; set; }
        public DelegateCommand<object>                  SignAnomalyStatCommand { get; set; }
        public DelegateCommand<object>                  SignQueryCommand { get; set; }
        public DelegateCommand<object>                  CardQueryCommand { get; set; }
        public DelegateCommand<object>                  EndorsementQueryCommand { get; set; }
        public DelegateCommand<object>                  PaymentQueryCommand { get; set; }
        public DelegateCommand<object>                  QueryQueryCommand { get; set; }
        public DelegateCommand<object>                  PreAcceptQueryCommand { get; set; }

        public DelegateCommand<object>                  SelectedItemCommand { get; set; }
        public DelegateCommand<object>                  UnSelectedItemCommand { get; set; }

        public DelegateCommand<object>                  ExitCommand { get; set; }
        public DelegateCommand<object>                  MaxCommand { get; set; }
        public DelegateCommand<object>                  MinCommand { get; set; }
        public DelegateCommand<object>                  DragWndCommand { get; set; }
        public DelegateCommand<RoutedEventArgs>         DoubleClickCommand {get; set; }

        public HomePageViewModel                        _HomePageViewModel { get; set; }
        public SummaryStatModel                         _SummaryStatViewModel { get; set; }
        public SignStatViewModel                        _SignStatViewModel { get; set; }
        public SignAnomalyStatViewModel                 _SignAnomalyStatViewModel { get; set; }
        public SignQueryViewModel                       _SignQueryViewModel { get; set; }
        public CardQueryViewModel                       _CardQueryViewModel { get; set; }
        public EndorsementQueryViewModel                _EndorsementQueryViewModel { get; set; }
        public PaymentQueryViewModel                    _PaymentQueryViewModel { get; set; }
        public QueryQueryViewModel                      _QueryQueryViewModel { get; set; }
        public PreAcceptQueryViewModel                  _PreAcceptQueryViewModel { get; set; }

        private ObservableCollection<DeviceModel> _deviceList;
        public ObservableCollection<DeviceModel> deviceList
        {
            get { return _deviceList; }
            set
            {
                _deviceList = value;
                this.RaisePropertyChanged("deviceList");
            }
        }
        private ObservableCollection<string> _businesstype;
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

        private ObservableCollection<string> _paymentStatus;
        public ObservableCollection<string> paymentStatus
        {
            get
            {
                return _paymentStatus;
            }
            set
            {
                _paymentStatus = value;
                this.RaisePropertyChanged("paymentStatus");
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
        public MainWindowViewModel()
        {
            _querytablecallbackdelegate                 = new QueryTableCallBackDelegate(QueryYingSheTableCallBack);

            HomePageCommand                             = new DelegateCommand<object>(new Action<object>(this.mainPageShow));
            SummaryStatCommand                          = new DelegateCommand<object>(new Action<object>(this.SummaryStatShow));
            SignStatCommand                             = new DelegateCommand<object>(new Action<object>(this.SignStatShow));
            SignAnomalyStatCommand                      = new DelegateCommand<object>(new Action<object>(this.SignAnomalyShow));
            SignQueryCommand                            = new DelegateCommand<object>(new Action<object>(this.SignQueryShow));
            CardQueryCommand                            = new DelegateCommand<object>(new Action<object>(this.CardQueryShow));
            EndorsementQueryCommand                     = new DelegateCommand<object>(new Action<object>(this.EndorsementQueryShow));
            PaymentQueryCommand                         = new DelegateCommand<object>(new Action<object>(this.PaymentQueryShow));
            QueryQueryCommand                           = new DelegateCommand<object>(new Action<object>(this.QueryQueryShow));
            PreAcceptQueryCommand                       = new DelegateCommand<object>(new Action<object>(this.PreAcceptQueryShow));

            SelectedItemCommand                         = new DelegateCommand<object>(new Action<object>(this.SelectedItem));
            UnSelectedItemCommand                       = new DelegateCommand<object>(new Action<object>(this.UnSelectedItem));

            ExitCommand                                 = new DelegateCommand<object>(new Action<object>(this.ExitWnd));
            MaxCommand                                  = new DelegateCommand<object>(new Action<object>(this.MaxWnd));
            MinCommand                                  = new DelegateCommand<object>(new Action<object>(this.MinWnd));
            DragWndCommand                              = new DelegateCommand<object>(new Action<object>(this.DragWnd));
            DoubleClickCommand                          = new DelegateCommand<RoutedEventArgs>(new Action<RoutedEventArgs>(this.DoubleClickWnd));

            _HomePageViewModel                          = new HomePageViewModel();
            _SummaryStatViewModel                       = new SummaryStatModel();
            _SignStatViewModel                          = new SignStatViewModel();
            _SignAnomalyStatViewModel                   = new SignAnomalyStatViewModel();
            _SignQueryViewModel                         = new SignQueryViewModel();
            _CardQueryViewModel                         = new CardQueryViewModel();
            _EndorsementQueryViewModel                  = new EndorsementQueryViewModel();
            _PaymentQueryViewModel                      = new PaymentQueryViewModel();
            _QueryQueryViewModel                        = new QueryQueryViewModel();
            _PreAcceptQueryViewModel                    = new PreAcceptQueryViewModel();

            _deviceList                                 = new ObservableCollection<DeviceModel>();
            _cardstatus                                 = new ObservableCollection<string>();
            _certificateType                            = new ObservableCollection<string>();
            _paymentStatus                              = new ObservableCollection<string>();
            _businesstype                               = new ObservableCollection<string>();

            _bShowPage                                  = PageVisibleEnum.PageVisibleEnum_SignQuery;
            _titleheight                                = 25;

            QueryYingshebiao(null);
            QueryShebeiguanli(null);
        }

        public void QueryYingSheTableCallBack(string resultStr)
        {
            
            Type type = null;
            switch(_queryoperate)
            {
                case QueryOperate.QueryOperate_Shebeiguanli:
                    type = typeof(SHEBEIGUANLIModel);
                    break;
                case QueryOperate.QueryOperate_YingSheTable:
                    type = typeof(YINGSHEBIAOModel);
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
                        case QueryOperate.QueryOperate_Shebeiguanli:
                            {
                                SHEBEIGUANLIModel modelTemp = model as SHEBEIGUANLIModel;

                                if(!_devicelistMap.Keys.Contains(modelTemp.Chengshibianhao))
                                    _devicelistMap[modelTemp.Chengshibianhao] = new Dictionary<string, Dictionary<string, HashSet<string>>>();
                                if(!_devicelistMap[modelTemp.Chengshibianhao].Keys.Contains(modelTemp.Jubianhao))
                                    _devicelistMap[modelTemp.Chengshibianhao][modelTemp.Jubianhao] = new Dictionary<string, HashSet<string>>();
                                if(!_devicelistMap[modelTemp.Chengshibianhao][modelTemp.Jubianhao].Keys.Contains(modelTemp.Shiyongdanweibianhao))
                                    _devicelistMap[modelTemp.Chengshibianhao][modelTemp.Jubianhao][modelTemp.Shiyongdanweibianhao] = new HashSet<string>();

                                _devicelistMap[modelTemp.Chengshibianhao][modelTemp.Jubianhao][modelTemp.Shiyongdanweibianhao].Add(modelTemp.IP);
                            }
                            break;
                        case QueryOperate.QueryOperate_YingSheTable:
                            {
                                YINGSHEBIAOModel modelTemp = model as YINGSHEBIAOModel;
                                _yingshelList[modelTemp.Bianhao] = modelTemp.Mingcheng;
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
            paymentStatus.Clear();
            WorkServer.GetInstance().QueryTable("select * from Yingshebiao", Marshal.GetFunctionPointerForDelegate(_querytablecallbackdelegate));

            cardstatus.Add("全部");
            businesstype.Add("全部");
            certificateType.Add("全部");
            paymentStatus.Add("全部");
            foreach(KeyValuePair<int, string> kvp0 in _yingshelList)
            {
                if(kvp0.Key >= 7000 && kvp0.Key < 8000)
                {
                    cardstatus.Add(kvp0.Value);
                }

                if (kvp0.Key >= 4000 && kvp0.Key < 5000)
                {
                    businesstype.Add(kvp0.Value);
                }

                if (kvp0.Key >= 9000 && kvp0.Key < 9011)
                {
                    certificateType.Add(kvp0.Value);
                }

                if (kvp0.Key >= 10000 && kvp0.Key < 10011)
                {
                    paymentStatus.Add(kvp0.Value);
                }
            }
        }
      
        public void QueryShebeiguanli(object obj)
        {
            _queryoperate = QueryOperate.QueryOperate_Shebeiguanli;
            deviceList.Clear();
            WorkServer.GetInstance().QueryTable("select * from Shebeiguanli", Marshal.GetFunctionPointerForDelegate(_querytablecallbackdelegate));

            foreach(KeyValuePair<string, Dictionary<string, Dictionary<string, HashSet<string>>>> kvp0 in _devicelistMap)
            {
                DeviceModel device0                 = new DeviceModel();
                device0.text                        = kvp0.Key;
                device0.leftMargin                  = "0,0,0,0";
                foreach (KeyValuePair<string, Dictionary<string, HashSet<string>>> kvp1 in kvp0.Value)
                {
                    DeviceModel device1             = new DeviceModel();
                    device1.text                    = kvp1.Key;
                    device1.leftMargin              = "16, 0, 0, 0";
                    foreach (KeyValuePair<string, HashSet<string>> kvp2 in kvp1.Value)
                    {
                        DeviceModel device2         = new DeviceModel();
                        device2.text                = kvp2.Key;
                        device2.leftMargin          = "32, 0, 0, 0";
                        foreach (string ipstr in kvp2.Value)
                        {
                            DeviceModel device3     = new DeviceModel();
                            device3.text            = ipstr;
                            device3.leftMargin      = "48, 0, 0, 0";
                            device2.Children.Add(device3);
                        }
                        device1.Children.Add(device2);
                    }
                    device0.Children.Add(device1);
                }
                deviceList.Add(device0);
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
            foreach (DeviceModel parent0 in deviceList)
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
                System.Windows.Application.Current.Shutdown();
            }
            catch (Exception ex)
            {
            }
        }

        public void mainPageShow(object obj)
        {
            bShowPage                                   = PageVisibleEnum.PageVisibleEnum_Home;
        }

        private void SummaryStatShow(object obj)
        {
            bShowPage                                   = PageVisibleEnum.PageVisibleEnum_SummaryStat;
        }

        private void SignStatShow(object obj)
        {
            bShowPage                                   = PageVisibleEnum.PageVisibleEnum_SignStat;
        }

        private void SignAnomalyShow(object obj)
        {
            bShowPage                                   = PageVisibleEnum.PageVisibleEnum_SignAnomalyStat;
        }

        private void SignQueryShow(object obj)
        {
            bShowPage                                   = PageVisibleEnum.PageVisibleEnum_SignQuery;
        }

        private void CardQueryShow(object obj)
        {
            bShowPage                                   = PageVisibleEnum.PageVisibleEnum_CardQuery;
        }

        private void EndorsementQueryShow(object obj)
        {
            bShowPage                                   = PageVisibleEnum.PageVisibleEnum_EndorsementQuery;
        }

        private void PaymentQueryShow(object obj)
        {
            bShowPage                                   = PageVisibleEnum.PageVisibleEnum_PaymentQuery;
        }

        private void QueryQueryShow(object obj)
        {
            bShowPage                                   = PageVisibleEnum.PageVisibleEnum_QueryQuery;
        }

        private void PreAcceptQueryShow(object obj)
        {
            bShowPage                                   = PageVisibleEnum.PageVisibleEnum_PreAcceptQuery;
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
               System.Windows.Point pp = Mouse.GetPosition(null);//WPF方法
               if (pp.Y > 0 && pp.Y < titleheight)
               {
                   MaxWnd(null);
               }
           }
        }
    }
}
