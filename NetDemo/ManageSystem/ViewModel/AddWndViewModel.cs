using ManageSystem.Model;
using ManageSystem.Server;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Configuration;
using System.Linq;
using System.Net;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using ExcutesqlCallBackDelegate = ManageSystem.Server.AddTableCallBackDelegate;

namespace ManageSystem.ViewModel
{
    public class AddWndViewModel : NotificationObject
    {
        public QueryTableCallBackDelegate   _querytablecallbackdelegate = null;
        public AddTableCallBackDelegate     _addtablecallbackdelegate = null;
        public ExcutesqlCallBackDelegate    _excutesqlCallBackDelegate = null;

        string  tableName   = "Zhiqianshuju";
        public DelegateCommand<object> SelectedCommand { get; set; }
        public DelegateCommand<object> AddCommand { get; set; }
        public DelegateCommand<object> QueryCommand { get; set; }
        public DelegateCommand<object> DeleteCommand { get; set; }
        public DelegateCommand<object> AddItemCommand { get; set; }
        public DelegateCommand<object> CopyItemCommand { get; set; }
        public DelegateCommand<object> DeleteItemCommand { get; set; }
        public DelegateCommand<object> UpdateAllRiqiCommand { get; set; }
        
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

        private string _curCnt;
        public string curCnt
        {
            get
            {
                return _curCnt;
            }
            set
            {
                _curCnt = value;
                this.RaisePropertyChanged("curCnt");
            }
        }

        private string _status;
        public string status
        {
            get
            {
                return _status;
            }
            set
            {
                _status = value;
                this.RaisePropertyChanged("status");
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


        private object _customInfo;
        public object customInfo
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

        private bool _ignoreXuhao;
        public bool ignoreXuhao
        {
            get
            {
                return _ignoreXuhao;
            }
            set
            {
                _ignoreXuhao = value;
                this.RaisePropertyChanged("ignoreXuhao");
            }
        }

        private bool _bSetAllcurtime;
        public bool bSetAllcurtime
        {
            get
            {
                return _bSetAllcurtime;
            }
            set
            {
                _bSetAllcurtime = value;
                this.RaisePropertyChanged("bSetAllcurtime");
            }
        }

        private string _Riqi;
        public string Riqi
        {
            get { return _Riqi; }
            set
            {
                _Riqi = value;
                this.RaisePropertyChanged("Riqi");
            }
        }

        public AddWndViewModel()
        {
            _querytablecallbackdelegate                 = new QueryTableCallBackDelegate(QueryTableCallBack);
            _addtablecallbackdelegate                   = new AddTableCallBackDelegate(AddTableCallBack);
            _excutesqlCallBackDelegate                  = new ExcutesqlCallBackDelegate(ExcutesqlCallBack);


            SelectedCommand                             = new DelegateCommand<object>(Selected);
            AddCommand                                  = new DelegateCommand<object>(Add);
            QueryCommand                                = new DelegateCommand<object>(Query);
            AddItemCommand                              = new DelegateCommand<object>(AddItem);
            DeleteCommand                               = new DelegateCommand<object>(Delete);
            CopyItemCommand                             = new DelegateCommand<object>(CopyItem);
            DeleteItemCommand                           = new DelegateCommand<object>(DeleteItem);
            UpdateAllRiqiCommand                        = new DelegateCommand<object>(UpdateAllRiqi);

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

            curCnt = "当前数量：" + tableList0.Count;
            _ignoreXuhao = true;
            _bSetAllcurtime = true;

            Riqi                                   = DateTime.Now.AddDays(-7).ToString("yyyy-MM-dd HH:mm:ss");

        }

        private void UpdateAllRiqi(object obj)
        {
            DataGrid grid = obj as DataGrid;

            ObservableCollection<object> temp = new ObservableCollection<object>();
            foreach (var item in grid.SelectedItems)
            {
                System.Reflection.PropertyInfo propertyinfo = item.GetType().GetProperty("Riqi");
                if(propertyinfo == null)
                    break;
                else
                {
                    propertyinfo.SetValue(item, Riqi, null);
                }
            }
        }

        private void AddTableCallBack(string resultStr, string errorStr)
        {
            if (errorStr != null && errorStr.Length != 0)
            {
                status = errorStr;
            }
            else
            {
                status = "操作成功";
            }
        }
        private void ExcutesqlCallBack(string resultStr, string errorStr)
        {
            if (errorStr != null && errorStr.Length != 0)
            {
                status = errorStr;
            }
            else
            {
                status = "操作成功";
            }
        }

        public void QueryTableCallBack(string resultStr, string errorStr)
        {
            Type type = typeof(SHEBEIGUANLIModel);
            switch (selvalue)
            {
                case "制签详细数据":
                    type = typeof(ZHIQIANSHUJUModel);
                    break;
                case "收证详细数据":
                    type = typeof(SHOUZHENGSHUJUModel);
                    break;
                case "签注详细数据":
                    type = typeof(QIANZHUSHUJUModel);
                    break;
                case "缴款详细数据":
                    type = typeof(JIAOKUANSHUJUModel);
                    break;
                case "查询详细数据":
                    type = typeof(CHAXUNSHUJUModel);
                    break;
                case "预受理详细数据":
                    type = typeof(YUSHOULISHUJUModel);
                    break;
                case "自助设备状态表":
                    type = typeof(SHEBEIZHUANGTAIModel);
                    break;
                case "自助设备异常详细数据":
                    type = typeof(SHEBEIYICHANGSHUJUModel);
                    break;
                case "管理员":
                    type = typeof(GUANLIYUANModel);
                    break;
                case "管理员操作记录":
                    type = typeof(GUANLIYUANCAOZUOJILUModel);
                    break;
                case "设备管理":
                    type = typeof(SHEBEIGUANLIModel);
                    break;
                case "映射表":
                    type = typeof(YINGSHEBIAOModel);
                    break;
            }

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
                                            if (keyvalue[1].Length > 0)
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

                    Application.Current.Dispatcher.BeginInvoke(
                    new Action<object>((modeltemp) =>
                    {
                        tableList0.Add(modeltemp);
                        curCnt = "当前数量：" + tableList0.Count;
                    }), model);
                }
            }

            if (errorStr != null && errorStr.Length != 0)
            {
                status = errorStr;
            }
            else
            {
                status = "操作成功";
            }
        }

        private void Query(object obj)
        {
            status = "";
            tableList0.Clear();
            string sql = "select * from " + tableName;
            WorkServer.QueryTable(sql, Marshal.GetFunctionPointerForDelegate(_querytablecallbackdelegate));

        }

        private void Delete(object obj)
        {
            string sqlStr = "delete from " + tableName + " where ";

            DataGrid grid = obj as DataGrid;

            int index = 0;
            foreach (var item in grid.SelectedItems)
            {
                if(item.GetType() != typeof(YINGSHEBIAOModel))
                {
                    if (index == 0)
                        sqlStr += " " + tableName + ".[Xuhao]=" + item.GetType().GetProperty("Xuhao").GetValue(item, null);
                    else
                        sqlStr += " or" + " " + tableName + ".[Xuhao]=" + item.GetType().GetProperty("Xuhao").GetValue(item, null);
                }
                else
                {
                    if (index == 0)
                        sqlStr += " " + tableName + ".[Bianhao]=" + item.GetType().GetProperty("Bianhao").GetValue(item, null);
                    else
                        sqlStr += " or" + " " + tableName + ".[Bianhao]=" + item.GetType().GetProperty("Bianhao").GetValue(item, null);
                }

                index++;
            }


            if (index > 0)
            {
                WorkServer.excuteSql(sqlStr, Marshal.GetFunctionPointerForDelegate(_excutesqlCallBackDelegate), true);
                Query(null);
            }
        }

        private void Add(object obj)
        {
            DataGrid grid = obj as DataGrid;
            if (grid.SelectedItems.Count == 0)
                return;

            Type    type        = grid.SelectedItems[0].GetType();
            int     addCount    = grid.SelectedItems.Count;

            if (type != null)
            {
                System.Reflection.PropertyInfo[] properties = type.GetProperties(System.Reflection.BindingFlags.Instance | System.Reflection.BindingFlags.Public);

                DateTime time = DateTime.Now;
                string addXml = "";
                for (int i = 0; i < addCount; ++i)
                {
                    object  modelTemp   = grid.SelectedItems[i];

                    foreach (System.Reflection.PropertyInfo item in properties)
                    {
                        if (item.PropertyType.Name.StartsWith("Int32"))
                        {
                            addXml += item.Name;
                            addXml += ":";
                            switch (item.Name)
                            {
                                case "Xuhao":
                                    if (ignoreXuhao)
                                        addXml += "0";
                                    else
                                        addXml += item.GetValue(modelTemp, null);
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
                                case "Jubianhao":
                                case "Shiyongdanweibianhao":
                                case "Shebeibaifangweizhi":
                                case "Qianzhuzhonglei":
                                case "ZhikaZhuangtai":
                                case "Zhengjianleixing":
                                case "Xingbie":
                                case "Yewuleixing":
                                    {
                                        string temp = (string)item.GetValue(modelTemp, null);
                                        foreach (KeyValuePair<int, string> kvp in MainWindowViewModel._yingshelList)
                                        {
                                            if (kvp.Value == temp)
                                                addXml += kvp.Key;
                                        }
                                    }
                                    break;
                                case "IP":
                                    {
                                        string temp = (string)item.GetValue(modelTemp, null);
                                        IPAddress addr;
                                        if (temp != null && temp.Length != 0 && IPAddress.TryParse(temp, out addr))
                                            addXml += (UInt32)(IPAddress.HostToNetworkOrder((Int32)Common.IpToInt(temp)));
                                    }
                                    break;
                                case "Riqi":
                                case "Chushengriqi":
                                case "Jiaoyiriqi":
                                case "Chuangjianshijian":
                                    {
                                        if(bSetAllcurtime)
                                        {
                                            addXml += Common.ConvertDateTimeInt(DateTime.Now);
                                        }
                                        else
                                        {
                                            string temp = (string)item.GetValue(modelTemp, null);
                                            if (temp != null && temp.Length != 0)
                                            {
                                                DateTime val;
                                                if (DateTime.TryParse(temp, out val))
                                                    addXml += Common.ConvertDateTimeInt(val);
                                            }
                                        }
                                    }
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

                status = "";
                if (tableName != null && tableName.Length != 0 && addCount > 0)
                {
                    WorkServer.addTable(tableName, addXml, Marshal.GetFunctionPointerForDelegate(_addtablecallbackdelegate), true);
                    Query(null);
                }
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
                    curCnt = "当前数量：" + tableList0.Count;
            }
        }

        private void CopyItem(object obj)
        {
            DataGrid grid = obj as DataGrid;

            ObservableCollection<object> temp = new ObservableCollection<object>();
            foreach (var item in grid.SelectedItems)
            {
                temp.Add(item);
            }
            foreach (var item in temp)
            {
                object retval = Activator.CreateInstance(item.GetType());
                FieldInfo[] fields = item.GetType().GetFields(BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.Static);
                foreach (FieldInfo field in fields)
                {
                    try { field.SetValue(retval, field.GetValue(item)); }
                    catch { }
                }

                tableList0.Add(retval);
            }

            curCnt = "当前数量：" + tableList0.Count;
        }

        private void DeleteItem(object obj)
        {
            DataGrid grid = obj as DataGrid;

            ObservableCollection<object> temp = new ObservableCollection<object>();
            foreach (var item in grid.SelectedItems)
            {
                temp.Add(item);
            }
            foreach (var item in temp)
            {
                tableList0.Remove(item);
            }

            curCnt = "当前数量：" + tableList0.Count;
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
            curCnt = "当前数量：" + tableList0.Count;
        }




    }
}
