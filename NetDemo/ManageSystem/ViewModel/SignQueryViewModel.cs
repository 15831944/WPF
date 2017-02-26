using ManageSystem.Model;
using ManageSystem.Server;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Diagnostics;
using System.Linq;
using System.Net;
using System.Runtime.InteropServices;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;

namespace ManageSystem.ViewModel
{
    class SignQueryViewModel : NotificationObject
    {
        public QueryTableCallBackDelegate               _querytablecallbackdelegate = null;
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
        public DelegateCommand<object>                  QueryCommand { get; set; }

        private string _cardNumber;
        public string cardNumber
        {
            get { return _cardNumber; }
            set
            {
                _cardNumber = value;
                this.RaisePropertyChanged("cardNumber");
            }
        }

        private string _businessNumber;
        public string businessNumber
        {
            get { return _businessNumber; }
            set
            {
                _businessNumber = value;
                this.RaisePropertyChanged("businessNumber");
            }
        }

        private string _startTime;
        public string startTime
        {
            get { return _startTime; }
            set
            {
                _startTime = value;
                this.RaisePropertyChanged("startTime");
            }
        }

        private string _endTime;
        public string endTime
        {
            get { return _endTime; }
            set
            {
                _endTime = value;
                this.RaisePropertyChanged("endTime");
            }
        }

        private string _cardStatuText;
        public string cardStatuText
        {
            get { return _cardStatuText; }
            set
            {
                _cardStatuText = value;
                this.RaisePropertyChanged("cardStatuText");
            }
        }

        private string _businessTypeText;
        public string businessTypeText
        {
            get { return _businessTypeText; }
            set
            {
                _businessTypeText = value;
                this.RaisePropertyChanged("businessTypeText");
            }
        }

        private ObservableCollection<ZHIQIANSHUJUModel> _tableList;
        public ObservableCollection<ZHIQIANSHUJUModel> tableList
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

        public SignQueryViewModel()
        {
            _querytablecallbackdelegate                 = new QueryTableCallBackDelegate(QueryTableCallBack);
            QueryCommand                                = new DelegateCommand<object>(new Action<object>(this.Query));
            _tableList                                  = new ObservableCollection<ZHIQIANSHUJUModel>();

            startTime                                   = DateTime.Now.AddDays(-7).ToString("dddd, MMMM d, yyyy h:mm:ss tt");
            endTime                                     = DateTime.Now.AddDays(7).ToString("dddd, MMMM d, yyyy h:mm:ss tt");
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
        public void QueryTableCallBack(string resultStr)
        {
            System.Reflection.PropertyInfo[] properties = typeof(ZHIQIANSHUJUModel).GetProperties(System.Reflection.BindingFlags.Instance | System.Reflection.BindingFlags.Public);

            string[] rows = resultStr.Split(';');
            foreach (string row in rows)
            {
                if (row.Length > 0)
                {
                    ZHIQIANSHUJUModel model     = new ZHIQIANSHUJUModel();

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
            WorkServer.GetInstance().QueryTable(MakeQuerySql(obj), Marshal.GetFunctionPointerForDelegate(_querytablecallbackdelegate));
        }

        string MakeQuerySql(object obj)
        {
            string str = "select * from Zhiqianshuju where Xuhao>=-1";
            
            MainWindowViewModel mainwindowviewmodel = obj as MainWindowViewModel;

            foreach(DeviceModel model0 in mainwindowviewmodel.deviceList)
            {
                if(model0.isSel)
                {
                    foreach(KeyValuePair<int, string> kvp0 in MainWindowViewModel._yingshelList)
                    {
                        if(kvp0.Value == model0.text)
                            str += " and zhiqianshuju.[Chengshibianhao]=" + kvp0.Key.ToString();
                    }
                }

                foreach(DeviceModel model1 in model0.Children)
                {
                    if (model1.isSel)
                    {
                        foreach (KeyValuePair<int, string> kvp0 in MainWindowViewModel._yingshelList)
                        {
                            if (kvp0.Value == model1.text)
                                str += " and zhiqianshuju.[Jubianhao]=" + kvp0.Key.ToString();
                        }
                    }

                    foreach (DeviceModel model2 in model1.Children)
                    {
                        if (model2.isSel)
                        {
                            foreach (KeyValuePair<int, string> kvp0 in MainWindowViewModel._yingshelList)
                            {
                                if (kvp0.Value == model2.text)
                                    str += " and zhiqianshuju.[Shiyongdanweibianhao]=" + kvp0.Key.ToString();
                            }
                        }
                        foreach (DeviceModel model3 in model2.Children)
                        {
                            if (model3.isSel)
                            {
                               str += " and zhiqianshuju.[IP]=" + Convert.ToInt32(IPAddress.HostToNetworkOrder((Int32)Common.IpToInt(model3.text)));
                            }
                        }
                    }
                }
            }

            if (cardNumber!=null && cardNumber.Length != 0)
                str += " and zhiqianshuju.[Zhengjianhaoma]=" + cardNumber;
            if (businessNumber != null && businessNumber.Length != 0)
                str += " and zhiqianshuju.[Yewubianhao]=" + businessNumber;
            if (startTime != null && startTime.Length != 0)
                str += " and zhiqianshuju.[Riqi]>" + Common.ConvertDateTimeInt(DateTime.Parse(startTime));
            if (endTime != null && endTime.Length != 0)
                str += " and zhiqianshuju.[Riqi]<" + Common.ConvertDateTimeInt(DateTime.Parse(endTime));
            if (cardStatuText != null && cardStatuText.Length != 0)
            {
                foreach (KeyValuePair<int, string> kvp0 in MainWindowViewModel._yingshelList)
                {
                    if (kvp0.Value == cardStatuText)
                    {
                        str += " and zhiqianshuju.[ZhikaZhuangtai]=" + kvp0.Key.ToString();
                        break;
                    }
                }
            }

            if (businessTypeText != null && businessTypeText.Length != 0)
            {
                if(businessTypeText == "本地业务")
                    str += " and zhiqianshuju.[Bendiyewu]=" + "1";
                else
                    str += " and zhiqianshuju.[Bendiyewu]=" + "0";
            }

            return str;
        }
    }
}
