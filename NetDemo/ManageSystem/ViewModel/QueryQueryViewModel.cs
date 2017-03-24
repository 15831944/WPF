using ManageSystem.Model;
using ManageSystem.Server;
using ManageSystem.ViewModel.DeviceViewModel;
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
   public  class QueryQueryViewModel : NotificationObject
    {
        public QueryTableCallBackDelegate               _querytablecallbackdelegate = null;
        public Dictionary<string, string>               _columnNameMap = new Dictionary<string, string>
        {
           {"Xuhao",						"序号"},			
           {"Chengshibianhao",		        "城市编号"},		
           {"Jubianhao",					"局编号"},		
           {"Shiyongdanweibianhao",	        "使用单位编号"},	
           {"IP",							"ip地址"},		
           {"Bendiyewu",					"是否本地业务"},	
           {"Shebeibaifangweizhi",	        "设备摆放位置"},	
           {"Riqi",					        "日期"},			
           {"Chaxunhaoma",				    "查询号码"},		
           {"Chaxunleixing",			    "查询类型"},		
           {"Shifouchaxunchenggong",	    "是否查询成功"},	
           {"Chuangjianshijian",		    "创建时间"},		
        };
        public DelegateCommand<object>                  QueryCommand { get; set; }

        private string _queryNumber;
        public string queryNumber
        {
            get { return _queryNumber; }
            set
            {
                _queryNumber = value;
                this.RaisePropertyChanged("queryNumber");
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

        private string _queryStatuText;
        public string queryStatuText
        {
            get { return _queryStatuText; }
            set
            {
                _queryStatuText = value;
                this.RaisePropertyChanged("queryStatuText");
            }
        }

        private ObservableCollection<CHAXUNSHUJUModel> _tableList;
        public ObservableCollection<CHAXUNSHUJUModel> tableList
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

        public QueryQueryViewModel()
        {
            _querytablecallbackdelegate                 = new QueryTableCallBackDelegate(QueryTableCallBack);
            QueryCommand                                = new DelegateCommand<object>(new Action<object>(this.Query));
            _tableList                                  = new ObservableCollection<CHAXUNSHUJUModel>();

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
   
        public void QueryTableCallBack(string resultStr, string errorStr)
        {
            System.Reflection.PropertyInfo[] properties = typeof(CHAXUNSHUJUModel).GetProperties(System.Reflection.BindingFlags.Instance | System.Reflection.BindingFlags.Public);

            string[] rows = resultStr.Split(';');
            foreach (string row in rows)
            {
                if (row.Length > 0)
                {
                    CHAXUNSHUJUModel model     = new CHAXUNSHUJUModel();

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
                    Application.Current.Dispatcher.Invoke(
                    new Action(() =>
                    {
                        tableList.Add(model);
                    }));
                }
            }
        }
        
        public void Query(object obj)
        {
            tableList.Clear();
            WorkServer.QueryTable(MakeQuerySql(obj), Marshal.GetFunctionPointerForDelegate(_querytablecallbackdelegate));
        }

        string MakeQuerySql(object obj)
        {
            string str = "select * from Chaxunshuju where Xuhao>=-1";

            foreach (DeviceModel model0 in DevicemaViewModel._deviceList)
            {
                if (model0.isSel)
                {
                    foreach (KeyValuePair<int, string> kvp0 in MainWindowViewModel._yingshelList)
                    {
                        if (kvp0.Value == model0.text)
                            str += " and Chaxunshuju.[Chengshibianhao]=" + kvp0.Key.ToString();
                    }
                }

                foreach (DeviceModel model1 in model0.Children)
                {
                    if (model1.isSel)
                    {
                        foreach (KeyValuePair<int, string> kvp0 in MainWindowViewModel._yingshelList)
                        {
                            if (kvp0.Value == model1.text)
                                str += " and Chaxunshuju.[Jubianhao]=" + kvp0.Key.ToString();
                        }
                    }

                    foreach (DeviceModel model2 in model1.Children)
                    {
                        if (model2.isSel)
                        {
                            foreach (KeyValuePair<int, string> kvp0 in MainWindowViewModel._yingshelList)
                            {
                                if (kvp0.Value == model2.text)
                                    str += " and Chaxunshuju.[Shiyongdanweibianhao]=" + kvp0.Key.ToString();
                            }
                        }
                        foreach (DeviceModel model3 in model2.Children)
                        {
                            if (model3.isSel)
                            {
                                str += " and Chaxunshuju.[IP]=" + Convert.ToInt32(IPAddress.HostToNetworkOrder((Int32)Common.IpToInt(model3.text)));
                            }
                        }
                    }
                }
            }

            if (queryNumber!=null && queryNumber.Length != 0)
                str += " and Chaxunshuju.[Chaxunhaoma]=" + queryNumber;
            if (startTime != null && startTime.Length != 0)
                str += " and Chaxunshuju.[Riqi]>=" + Common.ConvertDateTimeInt(DateTime.Parse(startTime));
            if (endTime != null && endTime.Length != 0)
                str += " and Chaxunshuju.[Riqi]<=" + Common.ConvertDateTimeInt(DateTime.Parse(endTime));
            if (queryStatuText != null && queryStatuText.Length != 0 && queryStatuText != "全部")
            {
                if (queryStatuText == "成功")
                    str += " and Chaxunshuju.[Shifouchaxunchenggong]=" + "1";
                else
                    str += " and Chaxunshuju.[Shifouchaxunchenggong]=" + "0";
            }

            return str;
        }
    }
}
