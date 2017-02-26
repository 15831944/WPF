using ManageSystem.Model;
using ManageSystem.Server;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Net;
using System.Runtime.InteropServices;
using System.Text;
using System.Windows;
using System.Windows.Controls;


namespace ManageSystem.ViewModel
{
    class PreAcceptQueryViewModel : NotificationObject
    {
        public QueryTableCallBackDelegate _querytablecallbackdelegate = null;
        public Dictionary<string, string> _columnNameMap = new Dictionary<string, string>
        {
            {"Xuhao",					"序号"},
            {"Chengshibianhao",			"城市编号"},
            {"Jubianhao",				"局编号"},
            {"Shiyongdanweibianhao",	"使用单位编号"},
            {"IP",						"ip地址"},
            {"Bendiyewu",				"是否本地业务"},
            {"Shebeibaifangweizhi",		"设备摆放位置"},
            {"Riqi",					"日期"},
            {"Yewubianhao",				"业务编号"},
            {"Xingming",				"姓名"},
            {"Lianxidianhua",			"联系电话"},
            {"Chuguoshiyou",			"出国事由"},
            {"YuanZhengjianhaoma",		"原证件号码"},
            {"Qianzhuzhonglei",			"签注种类"},
            {"Xingbie",					"性别"},
            {"Hukousuozaidi",			"户口所在地"},
            {"Minzu",					"民族"},
            {"Chuangjianshijian",		"创建时间"},
        };

        public DelegateCommand<object>                  QueryCommand { get; set; }

        private Visibility _bShowPage;
        public Visibility bShowPage
        {
            get { return _bShowPage; }
            set
            {
                _bShowPage = value;
                this.RaisePropertyChanged("bShowPage");
            }
        }

        private ObservableCollection<string> _itemList;
        public ObservableCollection<string> itemList
        {
            get { return _itemList; }
            set
            {
                _itemList = value;
                this.RaisePropertyChanged("itemList");
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

        private ObservableCollection<YUSHOULISHUJUModel> _tableList;
        public ObservableCollection<YUSHOULISHUJUModel> tableList
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

        public PreAcceptQueryViewModel()
        {
            _querytablecallbackdelegate                 = new QueryTableCallBackDelegate(QueryTableCallBack);
            QueryCommand                                = new DelegateCommand<object>(new Action<object>(this.Query));

            _bShowPage                                  = Visibility.Visible;
            _cardstatus                                 = new ObservableCollection<string>();
            _businesstype                               = new ObservableCollection<string>();
            _tableList                                  = new ObservableCollection<YUSHOULISHUJUModel>();

            {
                _cardstatus.Add("全部");
                _cardstatus.Add("成功");
                _cardstatus.Add("失败");
                _cardstatus.Add("异常");
            }
            {
                _businesstype.Add("全部");
                _businesstype.Add("本地");
                _businesstype.Add("异地");
            }
        }

        //Access and update columns during autogeneration
        public void DG1_AutoGeneratingColumn(object sender, DataGridAutoGeneratingColumnEventArgs e)
        {
            string headername = e.Column.Header.ToString();
            //Cancel the column you don't want to generate
            if(_columnNameMap.ContainsKey(headername))
            {
                e.Column.Header = _columnNameMap[headername];
            }
        }

        public void QueryTableCallBack(string resultStr)
        {
            System.Reflection.PropertyInfo[] properties = typeof(YUSHOULISHUJUModel).GetProperties(System.Reflection.BindingFlags.Instance | System.Reflection.BindingFlags.Public);

            string[] rows = resultStr.Split(';');
            foreach (string row in rows)
            {
                if (row.Length > 0)
                {
                    YUSHOULISHUJUModel model     = new YUSHOULISHUJUModel();

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
                    tableList.Add(model);
                }
            }
        }
       
        public void Query(object obj)
        {
            tableList.Clear();
            WorkServer.GetInstance().QueryTable("select * from Yushoulishuju", Marshal.GetFunctionPointerForDelegate(_querytablecallbackdelegate));
        }
    }
}
