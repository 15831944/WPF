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
                return Common.DeepCopy(value);
            }
        }
        #endregion
    }

    class DevicemaViewModel : NotificationObject
    {
        public QueryTableCallBackDelegate   _querytablecallbackdelegate = null;
        public AddTableCallBackDelegate     _addtablecallbackdelegate = null;
        public ExcutesqlCallBackDelegate    _excutesqlCallBackDelegate = null;
        public Dictionary<string, string> _columnNameMap = new Dictionary<string, string>
        {
            {"Xuhao",					"序号"},
            {"Chengshibianhao",			"城市编号"},
            {"Jubianhao",				"局编号"},
            {"Shiyongdanweibianhao",	"使用单位编号"},
            {"IP",						"ip地址"},
            {"Shebeichangjia",			"设备厂家"},		
            {"Shebeimingcheng",		    "设备名称"},		
            {"Shebeileixing",			"设备类型"},		
            {"Jingdu",					"经度"},			
            {"Weidu",					"纬度"},			
            {"Chuangjianshijian",		"创建时间"},		
            {"Yingjianxinxi",			"硬件信息"},	
            {"Ruanjianxinxi",			"软件信息"},	
            {"Ruanjianshengjixinxi",	"软件升级信息"},	
        };

        public DelegateCommand<object> AddCommand { get; set; }
        public DelegateCommand<object> DeleteCommand { get; set; }
        public DelegateCommand<object> ModifyCommand { get; set; }

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
             DeleteCommand                              = new DelegateCommand<object>(Delete);
             ModifyCommand                              = new DelegateCommand<object>(Modify);

            _deviceList                                 = new ObservableCollection<DeviceModel>();
            _city                                       = new ObservableCollection<string>();
            _ju                                         = new ObservableCollection<string>();
            _danwei                                     = new ObservableCollection<string>();
            _tableList                                  = new ObservableCollection<SHEBEIGUANLIModel>();
            _customInfo                                 = new SHEBEIGUANLIModel();
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
                                    addXml += ran.Next().ToString();
                                    break;
                            }
                        }
                        else if (item.PropertyType.Name.StartsWith("Int64"))
                        {
                            addXml += item.Name;
                            addXml += ":";
                            addXml += ran.Next().ToString();
                        }
                        else if (item.PropertyType.Name.StartsWith("Single"))
                        {
                            addXml += item.Name;
                            addXml += ":";
                            addXml += ran.Next().ToString();
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
                                        string temp = (string)item.GetValue(customInfo, null);
                                        foreach (KeyValuePair<int, string> kvp in MainWindowViewModel._yingshelList)
                                        {
                                            if (kvp.Value == temp)
                                                addXml += kvp.Key;
                                        }
                                    }
                                    break;
                                default:
                                    addXml += item.GetValue(customInfo, null);
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
                    WorkServer.addTable(tableName, addXml, Marshal.GetFunctionPointerForDelegate(_addtablecallbackdelegate), true);
                    QueryShebeiguanli(null);
                }
            }
        }

        private void Modify(object obj)
        {
            string sqlStr = "update shebeiguanli set ";

            int begin = 0;
            foreach (KeyValuePair<int, string> kvp in MainWindowViewModel._yingshelList)
            {
                if (kvp.Value == customInfo.Chengshibianhao)
                    sqlStr  += "Chengshibianhao='" + kvp.Key + "'";
            }


            foreach (KeyValuePair<int, string> kvp in MainWindowViewModel._yingshelList)
            {
                if (kvp.Value == customInfo.Jubianhao)
                    sqlStr  += ",Jubianhao='" + kvp.Key + "'";
                else if (kvp.Value == customInfo.Shiyongdanweibianhao)
                    sqlStr  += ",Shiyongdanweibianhao='" + kvp.Key + "'";
            }

            IPAddress addr;
            if(customInfo.IP != null && customInfo.IP.Length != 0 && IPAddress.TryParse(customInfo.IP, out addr))
                sqlStr  += ",IP='" + customInfo.IP + "'";

            if (customInfo.Shebeichangjia != null && customInfo.Shebeichangjia.Length != 0)
                sqlStr  += ",Shebeichangjia='" + customInfo.Shebeichangjia + "'";

            if (customInfo.Shebeimingcheng != null && customInfo.Shebeimingcheng.Length != 0)
                sqlStr  += ",Shebeimingcheng='" + customInfo.Shebeimingcheng + "'";

            if (customInfo.Shebeileixing != null && customInfo.Shebeileixing.Length != 0)
                sqlStr  += ",Shebeileixing='" + customInfo.Shebeileixing + "'";

            if (customInfo.Jingdu != null && customInfo.Jingdu.Length != 0)
                sqlStr  += ",Jingdu='" + customInfo.Jingdu + "'";

            if (customInfo.Weidu != null && customInfo.Weidu.Length != 0)
                sqlStr  += ",Weidu='" + customInfo.Weidu + "'";

            sqlStr += " where shebeiguanli.[Xuhao]=" + customInfo.Xuhao;
            if(customInfo.Xuhao >= 0)
            {
                customInfo.Xuhao = -1;
                WorkServer.excuteSql(sqlStr, Marshal.GetFunctionPointerForDelegate(_excutesqlCallBackDelegate), true);
                QueryShebeiguanli(null);
            }
        }

        private void Delete(object obj)
        {
            string sqlStr = "delete from shebeiguanli where shebeiguanli.[Xuhao]=" + customInfo.Xuhao;
            if (customInfo.Xuhao >= 0)
            {
                customInfo.Xuhao = -1;
                WorkServer.excuteSql(sqlStr, Marshal.GetFunctionPointerForDelegate(_excutesqlCallBackDelegate), true);
                QueryShebeiguanli(null);
            }
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
                                            if(keyvalue[1].Length > 0)
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

                    SHEBEIGUANLIModel modelTemp = model as SHEBEIGUANLIModel;
                    tableList.Add(modelTemp); 
                }
            }
        }

        public void QueryShebeiguanli(object obj)
        {
            city.Clear();
            ju.Clear();
            danwei.Clear();
            deviceList.Clear();
            tableList.Clear();
            WorkServer.QueryTable("select * from Shebeiguanli", Marshal.GetFunctionPointerForDelegate(_querytablecallbackdelegate), true);

            Dictionary<string, Dictionary<string, Dictionary<string, HashSet<SHEBEIGUANLIModel>>>> _devicelistMap = new Dictionary<string, Dictionary<string, Dictionary<string, HashSet<SHEBEIGUANLIModel>>>>();
            foreach (SHEBEIGUANLIModel modelTemp in tableList)
            {
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
        }

    }
}
