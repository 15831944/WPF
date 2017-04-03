using ManageSystem.Model;
using ManageSystem.Server;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Linq;
using System.Net;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Threading;
using System.Xml;
using ExcutesqlCallBackDelegate = ManageSystem.Server.AddTableCallBackDelegate;

namespace ManageSystem.ViewModel.DeviceViewModel
{
    public class DataGridSelectConvert : IValueConverter
    {
        #region IValueConverter 成员
        public object Convert(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            return value;
        }
        public object ConvertBack(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            if (value == null)
                return Activator.CreateInstance(targetType);
            else
            {
                object retval = Activator.CreateInstance(value.GetType());
                FieldInfo[] fields = value.GetType().GetFields(BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.Static);
                foreach (FieldInfo field in fields)
                {
                    try { field.SetValue(retval, field.GetValue(value)); }
                    catch { }
                }
                return  retval;
                //return Common.DeepCopy(value);
            }
        }
        #endregion
    }
    public enum OperateEnum
    {
        OperateEnum_Add,
        OperateEnum_Modify,
    }
   public  class DevicemaViewModel : NotificationObject
    {
        public QueryTableCallBackDelegate   _querytablecallbackdelegate = null;
        public AddTableCallBackDelegate     _addtablecallbackdelegate = null;
        public ExcutesqlCallBackDelegate    _excutesqlCallBackDelegate = null;

        public ObservableCollection<SHEBEIGUANLIModel> _tableListTemp = new ObservableCollection<SHEBEIGUANLIModel>();

        public DelegateCommand<object> AddCommand { get; set; }
        public DelegateCommand<object> ModifyCommand { get; set; }
        public DelegateCommand<object> OperateCommand { get; set; }

        public DelegateCommand<object> DeleteCommand { get; set; }
        public DelegateCommand<object> QueryCommand { get; set; }
        public DelegateCommand<object> FirstPageCommand { get; set; }
        public DelegateCommand<object> PrePageCommand { get; set; }
        public DelegateCommand<object> NextPageCommand { get; set; }
        public DelegateCommand<object> GotoPageCommand { get; set; }

        private int _numofpage;
        public int numofpage
        {
            get
            {
                return _numofpage;
            }
            set
            {
                _numofpage = value;
                this.RaisePropertyChanged("numofpage");
            }
        }

        private string _pagePercent;
        public string pagePercent
        {
            get
            {
                return _pagePercent;
            }
            set
            {
                _pagePercent = value;
                this.RaisePropertyChanged("pagePercent");
            }
        }

        private OperateEnum _operateenum;
        public OperateEnum operateenum
        {
            get
            {
                return _operateenum;
            }
            set
            {
                _operateenum = value;
                this.RaisePropertyChanged("operateenum");
            }
        }

        public static ObservableCollection<DeviceModel> _deviceList;
        public ObservableCollection<DeviceModel> deviceList
        {
            get { return _deviceList; }
            set
            {
                _deviceList = value;
                this.RaisePropertyChanged("deviceList");
            }
        }

        private ObservableCollection<SHEBEIGUANLIModel> _tableList;
        public ObservableCollection<SHEBEIGUANLIModel> tableList
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

        private SHEBEIGUANLIModel _customInfo;
        public SHEBEIGUANLIModel customInfo
        {
            get
            {
                return _customInfo;
            }
            set
            {
                _customInfo = value;
                this.RaisePropertyChanged("customInfo");
            }
        }

        private SHEBEIGUANLIModel _customInfo1;
        public SHEBEIGUANLIModel customInfo1
        {
            get
            {
                return _customInfo1;
            }
            set
            {
                _customInfo1 = value;
                this.RaisePropertyChanged("customInfo1");
            }
        }

        private ObservableCollection<string> _city;
        public ObservableCollection<string> city
        {
            get
            {
                return _city;
            }
            set
            {
                _city = value;
                this.RaisePropertyChanged("city");
            }
        }

        private ObservableCollection<string> _ju;
        public ObservableCollection<string> ju
        {
            get
            {
                return _ju;
            }
            set
            {
                _ju = value;
                this.RaisePropertyChanged("ju");
            }
        }

        private ObservableCollection<string> _danwei;
        public ObservableCollection<string> danwei
        {
            get
            {
                return _danwei;
            }
            set
            {
                _danwei = value;
                this.RaisePropertyChanged("danwei");
            }
        }



        public DevicemaViewModel()
        {
            _querytablecallbackdelegate                 = new QueryTableCallBackDelegate(QueryTableCallBack);
            _addtablecallbackdelegate                   = new AddTableCallBackDelegate(AddTableCallBack);
            _excutesqlCallBackDelegate                  = new ExcutesqlCallBackDelegate(ExcutesqlCallBack);
             AddCommand                                 = new DelegateCommand<object>(Add);
             ModifyCommand                              = new DelegateCommand<object>(Modify);
             OperateCommand                             = new DelegateCommand<object>(Operate);
             DeleteCommand                              = new DelegateCommand<object>(Delete);
            QueryCommand                                = new DelegateCommand<object>(QueryShebeiguanli);

            FirstPageCommand                            = new DelegateCommand<object>(FirstPage);
            PrePageCommand                              = new DelegateCommand<object>(PrePage);
            NextPageCommand                             = new DelegateCommand<object>(NextPage);
            GotoPageCommand                             = new DelegateCommand<object>(GotoPage);



            _deviceList                                 = new ObservableCollection<DeviceModel>();
            _city                                       = new ObservableCollection<string>();
            _ju                                         = new ObservableCollection<string>();
            _danwei                                     = new ObservableCollection<string>();
            _tableList                                  = new ObservableCollection<SHEBEIGUANLIModel>();
            _customInfo                                 = new SHEBEIGUANLIModel();
            _customInfo1                                = new SHEBEIGUANLIModel();
            _pagePercent                                = "0/0";

        }
 
        public void ShowPage(int pageindex)
        {
            App.Current.Dispatcher.BeginInvoke(new Action(() =>
            {
                if (numofpage > 0)
                {
                    int count = _tableListTemp.Count;            //获取记录总数  
                    int pageSize = 0;                       //pageSize表示总页数  
                    if (count % numofpage == 0)
                        pageSize = count / numofpage;
                    else
                        pageSize = count / numofpage + 1;

                    if (pageindex < 1 || pageindex > pageSize)
                        return;

                    tableList = new ObservableCollection<SHEBEIGUANLIModel>(_tableListTemp.Take(numofpage * pageindex).Skip(numofpage * (pageindex - 1)).ToList());   //刷选第currentSize页要显示的记录集  
                    pagePercent = pageindex + "/" + pageSize;
                }
            }));
        }  

        private void GotoPage(object obj)
        {
            try
            {
                int Number = Convert.ToInt32(obj);
                ShowPage(Number);
            }
            catch { }
        }

        private void NextPage(object obj)
        {
            try
            {
                string[] str = pagePercent.Split('/');
                ShowPage(Convert.ToInt32(str[0]) + 1);
            }
            catch { }
        }

        private void PrePage(object obj)
        {
            try
            {
                string[] str = pagePercent.Split('/');
                ShowPage(Convert.ToInt32(str[0]) - 1);
            }
            catch { }
        }

        private void FirstPage(object obj)
        {
            try
            {
                ShowPage(1);
            }
            catch { }
        }

        private void ExcutesqlCallBack(string errorStr)
        {
            if (errorStr != null && errorStr.Length != 0)
            {
                MessageBox.Show(errorStr);
            }
        }

        private void AddTableCallBack(string errorStr)
        {
            if(errorStr != null && errorStr.Length != 0)
            {
               MessageBox.Show(errorStr);
            }
        }

        private void Add(object obj)
        {
           operateenum = OperateEnum.OperateEnum_Add;
        }

        private void Modify(object obj)
        {
            operateenum = OperateEnum.OperateEnum_Modify;
        }

        private void Operate(object obj)
        {
            switch (operateenum)
            {
                case OperateEnum.OperateEnum_Add:
                    {
                        string tableName    = "Shebeiguanli";
                        int     addCount    = 1;
                        Random ran          = new Random();
                        Type type           = typeof(SHEBEIGUANLIModel);

                        if (type != null)
                        {
                            System.Reflection.PropertyInfo[] properties = type.GetProperties(System.Reflection.BindingFlags.Instance | System.Reflection.BindingFlags.Public);

                            DateTime time = DateTime.Now;
                            string addXml = "";
                            for (int i = 0; i < addCount; ++i)
                            {
                                foreach (System.Reflection.PropertyInfo item in properties)
                                {
                                    if (item.PropertyType.Name.StartsWith("Int32"))
                                    {
                                        addXml += item.Name;
                                        addXml += ":";
                                        switch (item.Name)
                                        {
                                            case "Xuhao":
                                                addXml += "0";
                                                break;
                                            default:
                                                addXml += item.GetValue(customInfo1, null);
                                                break;
                                        }
                                    }
                                    else if (item.PropertyType.Name.StartsWith("Int64"))
                                    {
                                        addXml += item.Name;
                                        addXml += ":";
                                        addXml += item.GetValue(customInfo1, null);
                                    }
                                    else if (item.PropertyType.Name.StartsWith("Single"))
                                    {
                                        addXml += item.Name;
                                        addXml += ":";
                                        addXml += item.GetValue(customInfo1, null);
                                    }
                                    else if (item.PropertyType.Name.StartsWith("String"))
                                    {
                                        addXml += item.Name;
                                        addXml += ":";

                                        switch (item.Name)
                                        {
                                            case "Chengshibianhao":
                                            case "Jubianhao":
                                            case "Shiyongdanweibianhao":
                                                {
                                                    string temp = (string)item.GetValue(customInfo1, null);
                                                    foreach (KeyValuePair<int, string> kvp in MainWindowViewModel._yingshelList)
                                                    {
                                                        if (kvp.Value == temp)
                                                            addXml += kvp.Key;
                                                    }
                                                }
                                                break;
                                            case "IP":
                                                {
                                                    string temp = (string)item.GetValue(customInfo1, null);
                                                    IPAddress addr;
                                                    if (customInfo1.IP != null && customInfo1.IP.Length != 0 && IPAddress.TryParse(temp, out addr))
                                                        addXml += Convert.ToInt32(IPAddress.HostToNetworkOrder((Int32)Common.IpToInt(temp)));
                                                }
                                                break;
                                            case "Chuangjianshijian":
                                                addXml += Common.ConvertDateTimeInt(DateTime.Now);
                                                break;
                                            default:
                                                addXml += item.GetValue(customInfo1, null);
                                                break;
                                        }
                                    }
                                    else if (item.PropertyType.Name.StartsWith("Boolean"))
                                    {
                                        addXml += item.Name;
                                        addXml += ":";
                                        addXml += (i%2 == 0) ? "0" : "1";
                                    }
                                    else
                                    {
                                        ;
                                    }
                                    addXml += ",";
                                }
                                addXml += ";";
                            }

                            if (tableName != null && tableName.Length != 0)
                            {
                                customInfo1.Xuhao = -1;
                                WorkServer.addTable(tableName, addXml, Marshal.GetFunctionPointerForDelegate(_addtablecallbackdelegate), true);
                                QueryShebeiguanli(null);
                            }
                        }
                    }
                    break;
                case OperateEnum.OperateEnum_Modify:
                    {
                        string sqlStr = "update shebeiguanli set ";

                        int begin = 0;
                        foreach (KeyValuePair<int, string> kvp in MainWindowViewModel._yingshelList)
                        {
                            if (kvp.Value == customInfo1.Chengshibianhao)
                                sqlStr  += "Chengshibianhao='" + kvp.Key + "'";
                        }

                        foreach (KeyValuePair<int, string> kvp in MainWindowViewModel._yingshelList)
                        {
                            if (kvp.Value == customInfo1.Jubianhao)
                                sqlStr  += ",Jubianhao='" + kvp.Key + "'";
                            else if (kvp.Value == customInfo1.Shiyongdanweibianhao)
                                sqlStr  += ",Shiyongdanweibianhao='" + kvp.Key + "'";
                        }


                        IPAddress addr;
                        if (!string.IsNullOrEmpty(customInfo1.IP) && IPAddress.TryParse(customInfo1.IP, out addr))
                            sqlStr  += ",IP='" + Convert.ToInt32(IPAddress.HostToNetworkOrder((Int32)Common.IpToInt(customInfo1.IP))) + "'";

                        if (!string.IsNullOrEmpty(customInfo1.Shebeichangjia))
                            sqlStr  += ",Shebeichangjia='" + customInfo1.Shebeichangjia + "'";

                        if (!string.IsNullOrEmpty(customInfo1.Shebeimingcheng))
                            sqlStr  += ",Shebeimingcheng='" + customInfo1.Shebeimingcheng + "'";

                        if (!string.IsNullOrEmpty(customInfo1.Shebeileixing))
                            sqlStr  += ",Shebeileixing='" + customInfo1.Shebeileixing + "'";

                        if (!string.IsNullOrEmpty(customInfo1.Jingdu))
                            sqlStr  += ",Jingdu='" + customInfo1.Jingdu + "'";

                        if (!string.IsNullOrEmpty(customInfo1.Weidu))
                            sqlStr  += ",Weidu='" + customInfo1.Weidu + "'";

                        if (!string.IsNullOrEmpty(customInfo1.Ruanjianxinxi))
                            sqlStr  += ",Ruanjianxinxi='" + customInfo1.Ruanjianxinxi + "'";

                        if (!string.IsNullOrEmpty(customInfo1.Yingjianxinxi))
                            sqlStr  += ",Yingjianxinxi='" + customInfo1.Yingjianxinxi + "'";

                        sqlStr += " where ";
                        int index = 0;
                        foreach (var item in tableList)
                        {
                            if (item.bSel)
                            {
                                if (index == 0)
                                    sqlStr += " Shebeiguanli.[Xuhao]=" + item.Xuhao;
                                else
                                    sqlStr += " or Shebeiguanli.[Xuhao]=" + item.Xuhao;

                                index++;
                            }
                        }

                        if (index >= 0)
                        {
                            WorkServer.excuteSql(sqlStr, Marshal.GetFunctionPointerForDelegate(_excutesqlCallBackDelegate), true);
                            QueryShebeiguanli(null);
                        }
                    }
                    break;
            }
        }

        private void Delete(object obj)
        {
            string sqlStr = "delete from shebeiguanli where ";

            int index = 0;
            foreach(var item in tableList)
            {
                if(item.bSel)
                {
                    if(index == 0)
                        sqlStr += " Shebeiguanli.[Xuhao]=" + item.Xuhao;
                    else
                        sqlStr += " or Shebeiguanli.[Xuhao]=" + item.Xuhao;

                    index++;
                }
            }


            if (index > 0)
            {
                WorkServer.excuteSql(sqlStr, Marshal.GetFunctionPointerForDelegate(_excutesqlCallBackDelegate), true);
                QueryShebeiguanli(null);
            }
        }

        public void QueryTableCallBack(string resultStr, string errorStr)
        {
            Type type = typeof(SHEBEIGUANLIModel);

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
                                        case "Chuangjianshijian":
                                            DateTime datetime = Common.ConvertIntDateTime(Convert.ToInt64(keyvalue[1]));
                                            item.SetValue(model, datetime.ToString("yyyy-MM-dd HH:mm:ss"), null);
                                            break;
                                        case "IP":
                                            if(keyvalue[1].Length > 0)
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
                    (model as SHEBEIGUANLIModel).operateinfomodel.operatemodel = OperateModelEnum.OperateModel_Modify;
                    _tableListTemp.Add(model as SHEBEIGUANLIModel);
                }
            }

            Application.Current.Dispatcher.Invoke(
            new Action(() =>
            {
                ShowPage(1);

                Dictionary<string, Dictionary<string, Dictionary<string, HashSet<SHEBEIGUANLIModel>>>> _devicelistMap = new Dictionary<string, Dictionary<string, Dictionary<string, HashSet<SHEBEIGUANLIModel>>>>();
                foreach (SHEBEIGUANLIModel modelTemp in _tableListTemp)
                {
                    if (modelTemp.Chengshibianhao == null       || modelTemp.Chengshibianhao.Length == 0        ||
                    modelTemp.Jubianhao == null             || modelTemp.Jubianhao.Length == 0              ||
                    modelTemp.Shiyongdanweibianhao == null  || modelTemp.Shiyongdanweibianhao.Length == 0
                        )
                        continue;

                    if (!_devicelistMap.Keys.Contains(modelTemp.Chengshibianhao))
                        _devicelistMap[modelTemp.Chengshibianhao] = new Dictionary<string, Dictionary<string, HashSet<SHEBEIGUANLIModel>>>();
                    if (!_devicelistMap[modelTemp.Chengshibianhao].Keys.Contains(modelTemp.Jubianhao))
                        _devicelistMap[modelTemp.Chengshibianhao][modelTemp.Jubianhao] = new Dictionary<string, HashSet<SHEBEIGUANLIModel>>();
                    if (!_devicelistMap[modelTemp.Chengshibianhao][modelTemp.Jubianhao].Keys.Contains(modelTemp.Shiyongdanweibianhao))
                        _devicelistMap[modelTemp.Chengshibianhao][modelTemp.Jubianhao][modelTemp.Shiyongdanweibianhao] = new HashSet<SHEBEIGUANLIModel>();

                    _devicelistMap[modelTemp.Chengshibianhao][modelTemp.Jubianhao][modelTemp.Shiyongdanweibianhao].Add(modelTemp);
                }

                foreach (KeyValuePair<string, Dictionary<string, Dictionary<string, HashSet<SHEBEIGUANLIModel>>>> kvp0 in _devicelistMap)
                {
                    DeviceModel device0                 = new DeviceModel();
                    device0.text                        = kvp0.Key;
                    device0.leftMargin                  = "0,0,0,0";
                    foreach (KeyValuePair<string, Dictionary<string, HashSet<SHEBEIGUANLIModel>>> kvp1 in kvp0.Value)
                    {
                        DeviceModel device1             = new DeviceModel();
                        device1.text                    = kvp1.Key;
                        device1.leftMargin              = "16, 0, 0, 0";
                        foreach (KeyValuePair<string, HashSet<SHEBEIGUANLIModel>> kvp2 in kvp1.Value)
                        {
                            DeviceModel device2         = new DeviceModel();
                            device2.text                = kvp2.Key;
                            device2.leftMargin          = "32, 0, 0, 0";
                            foreach (SHEBEIGUANLIModel model in kvp2.Value)
                            {
                                DeviceModel device3     = new DeviceModel();
                                device3.lonstr          = model.Jingdu;
                                device3.latstr          = model.Weidu;
                                device3.text            = model.IP;
                                device3.leftMargin      = "48, 0, 0, 0";
                                device2.Children.Add(device3);
                            }
                            device1.Children.Add(device2);
                        }
                        device0.Children.Add(device1);
                    }
                    deviceList.Add(device0);
                }

                foreach (KeyValuePair<int ,string> kvp in MainWindowViewModel._yingshelList)
                {
                    if (kvp.Key >= 0 && kvp.Key < 2000)
                        city.Add(kvp.Value);
                    if (kvp.Key >= 2001 && kvp.Key < 3000)
                        ju.Add(kvp.Value);
                    if (kvp.Key >= 3001 && kvp.Key < 4000)
                        danwei.Add(kvp.Value);
                }

            }));
        }

        public void QueryShebeiguanli(object obj)
        {
            city.Clear();
            ju.Clear();
            danwei.Clear();
            deviceList.Clear();
            _tableListTemp.Clear();
            tableList.Clear();
            WorkServer.QueryTable(MakeQuerySql(obj), Marshal.GetFunctionPointerForDelegate(_querytablecallbackdelegate));
        }

        string MakeQuerySql(object obj)
        {
            string str = "select * from Shebeiguanli where Xuhao>=-1";

            foreach (KeyValuePair<int, string> kvp0 in MainWindowViewModel._yingshelList)
            {
                if (kvp0.Value == customInfo.Chengshibianhao)
                    str += " and Shebeiguanli.[Chengshibianhao]=" + kvp0.Key.ToString();
                if (kvp0.Value == customInfo.Jubianhao)
                    str += " and Shebeiguanli.[Jubianhao]=" + kvp0.Key.ToString();
                if (kvp0.Value == customInfo.Shiyongdanweibianhao)
                    str += " and Shebeiguanli.[Shiyongdanweibianhao]=" + kvp0.Key.ToString();
            }

            if (!string.IsNullOrEmpty(customInfo.IP))
                str += " and Shebeiguanli.[IP]=" + Convert.ToInt32(IPAddress.HostToNetworkOrder((Int32)Common.IpToInt(customInfo.IP)));

            if (!string.IsNullOrEmpty(customInfo.Shebeichangjia))
                str += " and Shebeiguanli.[Shebeichangjia]=" + customInfo.Shebeichangjia;

            if (!string.IsNullOrEmpty(customInfo.Shebeimingcheng))
                str += " and Shebeiguanli.[Shebeimingcheng]=" + customInfo.Shebeimingcheng;

            if (!string.IsNullOrEmpty(customInfo.Shebeileixing))
                str += " and Shebeiguanli.[Shebeileixing]=" + customInfo.Shebeileixing;

            if (!string.IsNullOrEmpty(customInfo.Jingdu))
                str += " and Shebeiguanli.[Jingdu]=" + customInfo.Jingdu;

            if (!string.IsNullOrEmpty(customInfo.Weidu))
                str += " and Shebeiguanli.[Weidu]=" + customInfo.Weidu;

            return str;
        }

        public void DoLogon()
        {
            city.Clear();
            ju.Clear();
            danwei.Clear();
            deviceList.Clear();
            _tableListTemp.Clear();
            tableList.Clear();
            WorkServer.QueryTable(MakeQuerySql(null), Marshal.GetFunctionPointerForDelegate(_querytablecallbackdelegate), true);
        }

    }
}
