using ManageSystem.Model;
using ManageSystem.Server;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Configuration;
using System.Linq;
using System.Net;
using System.Text;
using System.Windows;
using System.Windows.Controls;

namespace ManageSystem.ViewModel
{
    public class AddWndViewModel : NotificationObject
    {
        string  tableName   = "Zhiqianshuju";
        public Dictionary<string, string>               _columnNameMap = new Dictionary<string, string>
        {
           {"Xuhao",				"序号"},
           {"Chengshibianhao",		"城市编号"},
           {"Jubianhao",			"局编号"},
           {"Shiyongdanweibianhao",	"使用单位编号"},
           {"IP",					"ip地址"},
           {"Bendiyewu",			"是否本地业务"},
           {"Shebeibaifangweizhi",	"设备摆放位置"},
           {"Riqi",					"日期"},
           {"Yewubianhao",			"业务编号"},
           {"YuanZhengjianhaoma",	"原证件号码"},
           {"Xingming",				"姓名"},
           {"Qianzhuzhonglei",		"签注种类"},
           {"ZhikaZhuangtai",		"制卡状态"},
           {"Zhengjianhaoma",		"证件号码"},
           {"Jiekoufanhuijieguo",	"接口返回结果"},
           {"Lianxidianhua",		"联系电话"},
        };

        public DelegateCommand<object> SelectedCommand { get; set; }
        public DelegateCommand<object> AddCommand { get; set; }
        public DelegateCommand<object> ConvertCommand { get; set; }
        public DelegateCommand<object> AddItemCommand { get; set; }
        public DelegateCommand<object> DeleteItemCommand { get; set; }


        private Visibility _visible;
        public Visibility visible
        {
            get
            {
                return _visible;
            }
            set
            {
                _visible = value;
                this.RaisePropertyChanged("visible");
            }
        }

        private string _selvalue;
        public string selvalue
        {
            get
            {
                return _selvalue;
            }
            set
            {
                _selvalue = value;
                this.RaisePropertyChanged("selvalue");
            }
        }

        private string _ip0;
        public string ip0
        {
            get
            {
                return _ip0;
            }
            set
            {
                _ip0 = value;
                this.RaisePropertyChanged("ip0");
            }
        }

        private string _ip1;
        public string ip1
        {
            get
            {
                return _ip1;
            }
            set
            {
                _ip1 = value;
                this.RaisePropertyChanged("ip1");
            }
        }

        private ObservableCollection<object> _tableList0;
        public ObservableCollection<object> tableList0
        {
            get
            {
                return _tableList0;
            }
            set
            {
                _tableList0 = value;
                this.RaisePropertyChanged("tableList0");
            }
        }

        public AddWndViewModel()
        {
            SelectedCommand             = new DelegateCommand<object>(Selected);
            AddCommand                  = new DelegateCommand<object>(Add);
            ConvertCommand              = new DelegateCommand<object>(ConvertData);
            AddItemCommand              = new DelegateCommand<object>(AddItem);
            DeleteItemCommand           = new DelegateCommand<object>(DeleteItem);

            bool bAddWnd = false;
            foreach (string key in ConfigurationManager.AppSettings)
            {    //检索当前选中的分辨率
                if (key == "AddWnd")
                {
                    bAddWnd = Convert.ToBoolean(ConfigurationManager.AppSettings[key]);
                }
            }

            if(!bAddWnd)
                visible = Visibility.Hidden;
            else
                visible = Visibility.Visible;

            _tableList0 = new ObservableCollection<object>();
            _tableList0.Add(new ZHIQIANSHUJUModel());
        }

        private void DeleteItem(object obj)
        {
            if(tableList0.Count > 0)
                tableList0.Remove(tableList0.Last());
        }

        private void AddItem(object obj)
        {
            switch (selvalue)
            {
                case "制签详细数据":
                        tableList0.Add(new ZHIQIANSHUJUModel());
                    break;
                case "收证详细数据":
                        tableList0.Add(new SHOUZHENGSHUJUModel());
                    break;
                case "签注详细数据":
                        tableList0.Add(new QIANZHUSHUJUModel());
                    break;
                case "缴款详细数据":
                        tableList0.Add(new JIAOKUANSHUJUModel());
                    break;
                case "查询详细数据":
                        tableList0.Add(new CHAXUNSHUJUModel());
                    break;
                case "预受理详细数据":
                        tableList0.Add(new YUSHOULISHUJUModel());
                    break;
                case "自助设备状态表":
                        tableList0.Add(new SHEBEIZHUANGTAIModel());
                    break;
                case "自助设备异常详细数据":
                        tableList0.Add(new SHEBEIYICHANGSHUJUModel());
                    break;
                case "管理员":
                        tableList0.Add(new GUANLIYUANModel());
                    break;
                case "管理员操作记录":
                        tableList0.Add(new GUANLIYUANCAOZUOJILUModel());
                    break;
                case "设备管理":
                        tableList0.Add(new SHEBEIGUANLIModel());
                    break;
                case "映射表":
                        tableList0.Add(new YINGSHEBIAOModel());
                    break;
            }
        }

        private void ConvertData(object obj)
        {
            try
            {
                ip1 = "";
                if (ip0 != null && ip0.Length > 0)
                {
                    ip1 =  "" + Convert.ToInt32(IPAddress.HostToNetworkOrder((Int32)Common.IpToInt(ip0)));
                }
            }
            catch
            {

            }
        }

        private void Add(object obj)
        {
            if(_tableList0.Count == 0)
                return;
            Type    type        = _tableList0[0].GetType();
            int     addCount    = _tableList0.Count;

            if (type != null)
            {
                System.Reflection.PropertyInfo[] properties = type.GetProperties(System.Reflection.BindingFlags.Instance | System.Reflection.BindingFlags.Public);

                DateTime time = DateTime.Now;
                string addXml = "";
                for (int i = 0; i < addCount; ++i)
                {
                    object  modelTemp   = _tableList0[i];

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
                                    addXml += item.GetValue(modelTemp, null);
                                    break;
                            }
                        }
                        else if (item.PropertyType.Name.StartsWith("Int64"))
                        {
                            addXml += item.Name;
                            addXml += ":";
                            addXml += item.GetValue(modelTemp, null);
                        }
                        else if (item.PropertyType.Name.StartsWith("Single"))
                        {
                            addXml += item.Name;
                            addXml += ":";
                            addXml += item.GetValue(modelTemp, null);
                        }
                        else if (item.PropertyType.Name.StartsWith("String"))
                        {
                            addXml += item.Name;
                            addXml += ":";
                            switch (item.Name)
                            {
                                case "Chengshibianhao":
                                    addXml += item.GetValue(modelTemp, null);
                                    break;
                                case "Jubianhao":
                                    addXml += item.GetValue(modelTemp, null);
                                    break;
                                case "Shiyongdanweibianhao":
                                    addXml += item.GetValue(modelTemp, null);
                                    break;
                                case "IP":
                                    addXml += item.GetValue(modelTemp, null);
                                    break;
                                case "Yewuleixing":
                                    addXml += item.GetValue(modelTemp, null);
                                    break;
                                case "Shebeibaifangweizhi":
                                    addXml += item.GetValue(modelTemp, null);
                                    break;
                                case "Riqi":
                                    addXml += Common.ConvertDateTimeInt(DateTime.Now);
                                    break;
                                case "Qianzhuzhonglei":
                                    addXml += item.GetValue(modelTemp, null);
                                    break;
                                case "ZhikaZhuangtai":
                                    addXml += item.GetValue(modelTemp, null);
                                    break;
                                case "Xingbie":
                                    addXml += item.GetValue(modelTemp, null);
                                    break;
                                case "Zhengjianleixing":
                                    addXml += item.GetValue(modelTemp, null);
                                    break;
                                case "Yichangleixing":
                                    addXml += item.GetValue(modelTemp, null);
                                    break;
                                default:
                                    addXml += item.GetValue(modelTemp, null);
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
                   WorkServer.addTable(tableName, addXml, IntPtr.Zero, true);
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

        private void Selected(object obj)
        {
            switch(selvalue)
            {
                case "制签详细数据":
                    {
                        tableName   = "Zhiqianshuju";
                        tableList0 = null;
                        tableList0 = new ObservableCollection<object>();
                        tableList0.Add(new ZHIQIANSHUJUModel());
                    }
                    break;
                case "收证详细数据":
                    {
                        tableName   = "Shouzhengshuju";
                        tableList0 = null;
                        tableList0 = new ObservableCollection<object>();
                        tableList0.Add(new SHOUZHENGSHUJUModel());
                    }
                    break;
                case "签注详细数据":
                    {
                        tableName   = "Qianzhushuju";
                        tableList0 = null;
                        tableList0 = new ObservableCollection<object>();
                        tableList0.Add(new QIANZHUSHUJUModel());
                    }
                    break;
                case "缴款详细数据":
                    {
                        tableName   = "Jiaokuanshuju";
                        tableList0 = null;
                        tableList0 = new ObservableCollection<object>();
                        tableList0.Add(new JIAOKUANSHUJUModel());
                    }
                    break;
                case "查询详细数据":
                    {
                        tableName   = "Chaxunshuju";
                        tableList0 = null;
                        tableList0 = new ObservableCollection<object>();
                        tableList0.Add(new CHAXUNSHUJUModel());
                    }
                    break;
                case "预受理详细数据":
                    {
                        tableName   = "Yushoulishuju";
                        tableList0 = null;
                        tableList0 = new ObservableCollection<object>();
                        tableList0.Add(new YUSHOULISHUJUModel());
                    }
                    break;
                case "自助设备状态表":
                    {
                        tableName   = "Shebeizhuangtai";
                        tableList0 = null;
                        tableList0 = new ObservableCollection<object>();
                        tableList0.Add(new SHEBEIZHUANGTAIModel());
                    }
                    break;
                case "自助设备异常详细数据":
                    {
                        tableName   = "Shebeiyichangshuju";
                        tableList0 = null;
                        tableList0 = new ObservableCollection<object>();
                        tableList0.Add(new SHEBEIYICHANGSHUJUModel());
                    }
                    break;
                case "管理员":
                    {
                        tableName   = "Guanliyuan";
                        tableList0 = null;
                        tableList0 = new ObservableCollection<object>();
                        tableList0.Add(new GUANLIYUANModel());
                    }
                    break;
                case "管理员操作记录":
                    {
                        tableName   = "Guanliyuancaozuojilu";
                        tableList0 = null;
                        tableList0 = new ObservableCollection<object>();
                        tableList0.Add(new GUANLIYUANCAOZUOJILUModel());
                    }
                    break;
                case "设备管理":
                    {
                        tableName   = "Shebeiguanli";
                        tableList0 = null;
                        tableList0 = new ObservableCollection<object>();
                        tableList0.Add(new SHEBEIGUANLIModel());
                    }
                    break;
                case "映射表":
                    {
                        tableName   = "Yingshebiao";
                        tableList0 = null;
                        tableList0 = new ObservableCollection<object>();
                        tableList0.Add(new YINGSHEBIAOModel());
                    }
                    break;
            }
        }






    }
}
