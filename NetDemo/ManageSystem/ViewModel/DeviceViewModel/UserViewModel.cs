using ManageSystem.Model;
using ManageSystem.Server;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Net;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using ExcutesqlCallBackDelegate = ManageSystem.Server.AddTableCallBackDelegate;

namespace ManageSystem.ViewModel.DeviceViewModel
{
   public  class UserViewModel : NotificationObject
    {
        public QueryTableCallBackDelegate   _querytablecallbackdelegate = null;
        public AddTableCallBackDelegate     _addtablecallbackdelegate = null;
        public ExcutesqlCallBackDelegate    _excutesqlCallBackDelegate = null;

        public Dictionary<string, GUANLIYUANModel>      _guliyuanList           = new Dictionary<string, GUANLIYUANModel>();
        private ObservableCollection<GUANLIYUANModel> _tableListTemp            = new ObservableCollection<GUANLIYUANModel>();


        public DelegateCommand<object> AddCommand { get; set; }
        public DelegateCommand<object> ModifyCommand { get; set; }
        public DelegateCommand<object> OperateCommand { get; set; }

        public DelegateCommand<object> DeleteCommand { get; set; }
        public DelegateCommand<object> QueryCommand { get; set; }
        public DelegateCommand<object> FirstPageCommand { get; set; }
        public DelegateCommand<object> PrePageCommand { get; set; }
        public DelegateCommand<object> NextPageCommand { get; set; }
        public DelegateCommand<object> GotoPageCommand { get; set; }

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

        private GUANLIYUANModel _customInfo1;
        public GUANLIYUANModel customInfo1
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

        public UserViewModel()
        {
            _querytablecallbackdelegate             = new QueryTableCallBackDelegate(QueryTableCallBack);
            _addtablecallbackdelegate               = new AddTableCallBackDelegate(AddTableCallBack);
            _excutesqlCallBackDelegate              = new ExcutesqlCallBackDelegate(ExcutesqlCallBack);

            AddCommand                              = new DelegateCommand<object>(Add);
            DeleteCommand                           = new DelegateCommand<object>(Delete);
            ModifyCommand                           = new DelegateCommand<object>(Modify);
            OperateCommand                          = new DelegateCommand<object>(Operate);
            QueryCommand                            = new DelegateCommand<object>(QueryYongHuguanli);

            FirstPageCommand                        = new DelegateCommand<object>(FirstPage);
            PrePageCommand                          = new DelegateCommand<object>(PrePage);
            NextPageCommand                         = new DelegateCommand<object>(NextPage);
            GotoPageCommand                         = new DelegateCommand<object>(GotoPage);


            _tableList                              = new ObservableCollection<GUANLIYUANModel>();
            _customInfo                             = new GUANLIYUANModel();
            _customInfo1                            = new GUANLIYUANModel();
            _customInfo1.Youxiaoqikaishi            = DateTime.Now.AddDays(-7).ToString("yyyy-MM-dd HH:mm:ss");
            _customInfo1.Youxiaoqijieshu            = DateTime.Now.AddDays(7).ToString("yyyy-MM-dd HH:mm:ss");

            _pagePercent                            = "0/0";
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

                    tableList = new ObservableCollection<GUANLIYUANModel>(_tableListTemp.Take(numofpage * pageindex).Skip(numofpage * (pageindex - 1)).ToList());   //刷选第currentSize页要显示的记录集  
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

        private void ExcutesqlCallBack(string resultStr, string errorStr)
        {
            if (errorStr != null && errorStr.Length != 0)
            {
                MessageBox.Show(errorStr);
            }
        }

        private void AddTableCallBack(string resultStr, string errorStr)
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
                                        case "Youxiaoqikaishi":
                                        case "Youxiaoqijieshu":
                                            DateTime datetime = Common.ConvertIntDateTime(Convert.ToInt64(keyvalue[1]));
                                            item.SetValue(model, datetime.ToString("yyyy-MM-dd HH:mm:ss"), null);
                                            break;
                                        case "IP":
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

                    GUANLIYUANModel modelTemp = model as GUANLIYUANModel;

                    modelTemp.operateinfomodel.operatemodel = OperateModelEnum.OperateModel_UserModify;
                    _tableListTemp.Add(modelTemp);

                    _guliyuanList[modelTemp.Yonghuming] = modelTemp;
                }
            }

            Application.Current.Dispatcher.Invoke(
            new Action(() =>
            {
                ShowPage(1);
            }));
        }

        public void QueryYongHuguanli(object obj)
        {
            tableList.Clear();
            _tableListTemp.Clear();
            _guliyuanList.Clear();
            WorkServer.QueryTable(MakeQuerySql(null), Marshal.GetFunctionPointerForDelegate(_querytablecallbackdelegate), true);
        }
        string MakeQuerySql(object obj)
        {
            string str = "select * from Guanliyuan where Xuhao>=-1";

            if (!string.IsNullOrEmpty(customInfo.Yonghuming))
                str += " and Guanliyuan.[Yonghuming]=" + "'" + customInfo.Yonghuming + "'";

            if (!string.IsNullOrEmpty(customInfo.Mima))
                str += " and Guanliyuan.[Mima]="  + "'" + customInfo.Mima + "'";

            if (!string.IsNullOrEmpty(customInfo.Youxiaoqikaishi))
                str += " and Guanliyuan.[Youxiaoqikaishi]>=" + Common.ConvertDateTimeInt(DateTime.Parse(customInfo.Youxiaoqikaishi));

            if (!string.IsNullOrEmpty(customInfo.Youxiaoqijieshu))
                str += " and Guanliyuan.[Youxiaoqikaishi]<=" + Common.ConvertDateTimeInt(DateTime.Parse(customInfo.Youxiaoqijieshu));

            if (!string.IsNullOrEmpty(customInfo.Quanxianjibie))
                str += " and Guanliyuan.[Quanxianjibie]="  + "'" + customInfo.Quanxianjibie + "'";

            return str;
        }
        public void DoLogon()
        {
            _guliyuanList.Clear();
            QueryYongHuguanli(null);
        }

        private void Add(object obj)
        {
            operateenum = OperateEnum.OperateEnum_Add;
            customInfo1 = new GUANLIYUANModel();
        }

        private void Modify(object obj)
        {
            object retval = Activator.CreateInstance(customInfo.GetType());
            FieldInfo[] fields = customInfo.GetType().GetFields(BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.Static);
            foreach (FieldInfo field in fields)
            {
                try { field.SetValue(retval, field.GetValue(customInfo)); }
                catch { }
            }
            customInfo1 = retval as GUANLIYUANModel;
            operateenum = OperateEnum.OperateEnum_Modify;
        }

        private void Operate(object obj)
        {
            switch (operateenum)
            {
                case OperateEnum.OperateEnum_Add:
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
                                            case "Youxiaoqikaishi":
                                            case "Youxiaoqijieshu":
                                                addXml += Common.ConvertDateTimeInt(DateTime.Parse((string)item.GetValue(customInfo1, null)));

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
                                WorkServer.addTable(tableName, addXml, Marshal.GetFunctionPointerForDelegate(_addtablecallbackdelegate), true);
                                QueryYongHuguanli(null);
                            }
                        }
                    }
                    break;
                case OperateEnum.OperateEnum_Modify:
                    {
                        string sqlStr = "update Guanliyuan set ";


                        if (!string.IsNullOrEmpty(customInfo1.Yonghuming))
                            sqlStr  += "Yonghuming='" + customInfo1.Yonghuming + "'";
                        else
                            return;

                        if (!string.IsNullOrEmpty(customInfo1.Mima))
                            sqlStr  += ",Mima='" + customInfo1.Mima + "'";

                        if (!string.IsNullOrEmpty(customInfo1.Youxiaoqikaishi))
                            sqlStr  += ",Youxiaoqikaishi='" + Common.ConvertDateTimeInt(DateTime.Parse(customInfo1.Youxiaoqikaishi)) + "'";

                        if (!string.IsNullOrEmpty(customInfo1.Youxiaoqijieshu))
                            sqlStr  += ",Youxiaoqijieshu='" + Common.ConvertDateTimeInt(DateTime.Parse(customInfo1.Youxiaoqijieshu)) + "'";

                        if (!string.IsNullOrEmpty(customInfo1.Quanxianjibie))
                            sqlStr  += ",Quanxianjibie='" + customInfo1.Quanxianjibie + "'";

                        sqlStr += " where ";
                        int index = 0;
                        foreach (var item in tableList)
                        {
                            if (item.bSel)
                            {
                                if (index == 0)
                                    sqlStr += " Guanliyuan.[Xuhao]=" + item.Xuhao;
                                else
                                    sqlStr += " or Guanliyuan.[Xuhao]=" + item.Xuhao;

                                index++;
                            }
                        }

                        WorkServer.excuteSql(sqlStr, Marshal.GetFunctionPointerForDelegate(_excutesqlCallBackDelegate), true);
                        QueryYongHuguanli(null);
                    }
                    break;
            }
        }

        private void Delete(object obj)
        {
            string sqlStr = "delete from Guanliyuan where ";

            int index = 0;
            foreach (var item in tableList)
            {
                if (item.bSel)
                {
                    if (index == 0)
                        sqlStr += " Guanliyuan.[Xuhao]=" + item.Xuhao;
                    else
                        sqlStr += " or Guanliyuan.[Xuhao]=" + item.Xuhao;

                    index++;
                }
            }

            if (index > 0)
            {
                WorkServer.excuteSql(sqlStr, Marshal.GetFunctionPointerForDelegate(_excutesqlCallBackDelegate), true);
                QueryYongHuguanli(null);
            }
        }

    }
}
