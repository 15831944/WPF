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
using ExcutesqlCallBackDelegate = ManageSystem.Server.AddTableCallBackDelegate;

namespace ManageSystem.ViewModel.DeviceViewModel
{
    class UserViewModel : NotificationObject
    {
        public QueryTableCallBackDelegate   _querytablecallbackdelegate = null;
        public AddTableCallBackDelegate     _addtablecallbackdelegate = null;
        public ExcutesqlCallBackDelegate    _excutesqlCallBackDelegate = null;

        public static Dictionary<string, string> _columnNameMap = new Dictionary<string, string>
        {
            {"Xuhao",	        "序号"},
            {"Yonghuming",	    "用户名"},
            {"Mima",	        "密码"},
            {"Youxiaoqikaishi",	"有效期起始"},
            {"Youxiaoqijieshu",	"有效期截至"},
            {"Quanxianjibie",	"权限级别"},
        };

        public DelegateCommand<object> AddCommand { get; set; }
        public DelegateCommand<object> DeleteCommand { get; set; }
        public DelegateCommand<object> ModifyCommand { get; set; }

        private ObservableCollection<GUANLIYUANModel> _tableList;
        public ObservableCollection<GUANLIYUANModel> tableList
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

        private GUANLIYUANModel _customInfo;
        public GUANLIYUANModel customInfo
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

        public UserViewModel()
        {
            _querytablecallbackdelegate         = new QueryTableCallBackDelegate(QueryTableCallBack);
            _addtablecallbackdelegate           = new AddTableCallBackDelegate(AddTableCallBack);
            _excutesqlCallBackDelegate          = new ExcutesqlCallBackDelegate(ExcutesqlCallBack);

            AddCommand                          = new DelegateCommand<object>(Add);
            DeleteCommand                       = new DelegateCommand<object>(Delete);
            ModifyCommand                       = new DelegateCommand<object>(Modify);


            _customInfo                         = new GUANLIYUANModel();
            _tableList                          = new ObservableCollection<GUANLIYUANModel>();
        }
        //Access and update columns during autogeneration
        public static void DG1_AutoGeneratingColumn(object sender, DataGridAutoGeneratingColumnEventArgs e)
        {
            string headername = e.Column.Header.ToString();
            //Cancel the column you don't want to generate
            if (_columnNameMap.ContainsKey(headername))
            {
                e.Column.Header = _columnNameMap[headername];
            }
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
            if (errorStr != null && errorStr.Length != 0)
            {
                MessageBox.Show(errorStr);
            }
        }

        public void QueryTableCallBack(string resultStr, string errorStr)
        {
            Type type = typeof(GUANLIYUANModel);

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

                    GUANLIYUANModel modelTemp = model as GUANLIYUANModel;
                    tableList.Add(modelTemp);
                }
            }
        }

        public void QueryYongHuguanli(object obj)
        {
            tableList.Clear();
            WorkServer.QueryTable("select * from Guanliyuan", Marshal.GetFunctionPointerForDelegate(_querytablecallbackdelegate), true);
        }

        private void Add(object obj)
        {
            string tableName    = "Guanliyuan";
            int     addCount    = 1;
            Random ran          = new Random();
            Type type           = typeof(GUANLIYUANModel);

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
                                //case "Yonghuming":
                                //case "Quanxianjibie":

                                //    break;
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
                    QueryYongHuguanli(null);
                }
            }
        }

        private void Modify(object obj)
        {
            string sqlStr = "update Guanliyuan set ";


            if (customInfo.Yonghuming != null && customInfo.Yonghuming.Length != 0)
                sqlStr  += "Yonghuming='" + customInfo.Yonghuming + "'";
            else
                return;

            if (customInfo.Mima != null && customInfo.Mima.Length != 0)
                sqlStr  += ",Mima='" + customInfo.Mima + "'";

            if (customInfo.Youxiaoqikaishi != null && customInfo.Youxiaoqikaishi.Length != 0)
                sqlStr  += ",Youxiaoqikaishi='" + customInfo.Youxiaoqikaishi + "'";

            if (customInfo.Youxiaoqijieshu != null && customInfo.Youxiaoqijieshu.Length != 0)
                sqlStr  += ",Youxiaoqijieshu='" + customInfo.Youxiaoqijieshu + "'";

            if (customInfo.Quanxianjibie != null && customInfo.Quanxianjibie.Length != 0)
                sqlStr  += ",Quanxianjibie='" + customInfo.Quanxianjibie + "'";

            sqlStr += " where Guanliyuan.[Xuhao]=" + customInfo.Xuhao;
            if (customInfo.Xuhao >= 0)
            {
                customInfo.Xuhao = -1;
                WorkServer.excuteSql(sqlStr, Marshal.GetFunctionPointerForDelegate(_excutesqlCallBackDelegate), true);
                QueryYongHuguanli(null);
            }
        }

        private void Delete(object obj)
        {
            //string sqlStr = "delete from Guanliyuan where Guanliyuan.[Xuhao]=" + customInfo.Xuhao;
            //if (customInfo.Xuhao >= 0)
            //{
            //    customInfo.Xuhao = -1;
            //    WorkServer.excuteSql(sqlStr, Marshal.GetFunctionPointerForDelegate(_excutesqlCallBackDelegate), true);
            //    QueryShebeiguanli(null);
            //}
        }

    }
}
