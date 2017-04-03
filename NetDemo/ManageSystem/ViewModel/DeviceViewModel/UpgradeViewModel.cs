using ManageSystem.Model;
using ManageSystem.Resources.DataGridAttachRes;
using ManageSystem.Server;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.IO;
using System.Linq;
using System.Net;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Windows;

namespace ManageSystem.ViewModel.DeviceViewModel
{
    public enum QueryEnum
    {
        QueryEnum_None,
        QueryEnum_Device,
        QueryEnum_Upgrade,
        QueryEnum_TestSpeed,
        //QueryEnum_Abnormal,
        //QueryEnum_Hardware,
    }

   public  class UpgradeViewModel : NotificationObject
    {
        public QueryTableCallBackDelegate   _querytablecallbackdelegate = null;
       private QueryEnum                    _queryEnum = QueryEnum.QueryEnum_None;

       private ObservableCollection<SHEBEIGUANLIModel> _tableListTemp = new ObservableCollection<SHEBEIGUANLIModel>();


       public DelegateCommand<object> QueryCommand { get; set; }
       public DelegateCommand<object> FirstPageCommand { get; set; }
       public DelegateCommand<object> PrePageCommand { get; set; }
       public DelegateCommand<object> NextPageCommand { get; set; }
       public DelegateCommand<object> GotoPageCommand { get; set; }
       public DelegateCommand<object> UpgradeCommand { get; set; }
       public DelegateCommand<object> PowerUpgradeCommand { get; set; }
       public DelegateCommand<object> ExportExcelCommand { get; set; }
       public DelegateCommand<object> ExportTXTCommand { get; set; }

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

       private ObservableCollection<RUANJIANBAOModel> _ruanjianList;
       public ObservableCollection<RUANJIANBAOModel> ruanjianList
       {
           get
           {
               return _ruanjianList;
           }
           set
           {
               _ruanjianList = value;
               this.RaisePropertyChanged("ruanjianList");
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

        public UpgradeViewModel()
        {
            _querytablecallbackdelegate                 = new QueryTableCallBackDelegate(QueryTableCallBack);

            QueryCommand                                = new DelegateCommand<object>(QueryShebeiguanli);

            FirstPageCommand                            = new DelegateCommand<object>(FirstPage);
            PrePageCommand                              = new DelegateCommand<object>(PrePage);
            NextPageCommand                             = new DelegateCommand<object>(NextPage);
            GotoPageCommand                             = new DelegateCommand<object>(GotoPage);
            UpgradeCommand                              = new DelegateCommand<object>(Upgrade);
            PowerUpgradeCommand                         = new DelegateCommand<object>(PowerUpgrade);
            ExportExcelCommand                          = new DelegateCommand<object>(ExportExcel);
            ExportTXTCommand                            = new DelegateCommand<object>(ExportTXT);

            _tableList                                  = new ObservableCollection<SHEBEIGUANLIModel>();
            _ruanjianList                               = new ObservableCollection<RUANJIANBAOModel>();
            _customInfo                                 = new SHEBEIGUANLIModel();
            _pagePercent                                = "0/0";
        }

        private void PowerUpgrade(object obj)
        {
            Upgrade(null);
        }

        private void Upgrade(object obj)
        {
            int index = 0;
            foreach (var item0 in tableList)
            {
                if (item0.bSel)
                {
                    foreach(var item1 in ruanjianList)
                    {
                        if(item1.Banbenhao == item0.operateinfomodel.operatedisplayText)
                        {
                            if (item0.operateinfomodel.progess == 0)
                            {
                                BackgroundWorker bgw= new BackgroundWorker();
                                bgw.WorkerSupportsCancellation = true;
                                bgw.WorkerReportsProgress = true;

                                bgw.DoWork += (object sender, DoWorkEventArgs ee) =>
                                {
                                    for (int i = 0; i < 100; ++i)
                                    {
                                        Thread.Sleep(50);
                                        (sender as BackgroundWorker).ReportProgress(item0.operateinfomodel.progess += 1);

                                        if (item0.operateinfomodel.progess == 100)
                                            break;
                                    }
                                };

                                bgw.ProgressChanged += (object sender, ProgressChangedEventArgs ee) =>
                                {
                                    item0.operateinfomodel.operatedisplayText = item1.Banbenhao + "..." + ee.ProgressPercentage + "%";
                                };
                                bgw.RunWorkerCompleted += (object sender, RunWorkerCompletedEventArgs ee) =>
                                {
                                    item0.operateinfomodel.progess = 0;
                                };

                                bgw.RunWorkerAsync();
                            }
                        }
                    }

                    index++;
                }
            }
        }
        private void ExportTXT(object obj)
        {
            System.Windows.Forms.SaveFileDialog opf = new System.Windows.Forms.SaveFileDialog();
            opf.FileName = DateTime.Now.ToString("yyyyMMddHHmmss");
            opf.Filter = "*.txt|*.txt|所有文件(*.*)|*.*";
            if (opf.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                string filepath = opf.FileName;
                StreamWriter writer = new StreamWriter(filepath);

                Type type = typeof(SHEBEIGUANLIModel);
                int rowCount = tableList.Count + 1;  //DataTable行数+GirdHead
                int colCount = type.GetProperties().Count(); //DataTable列数
                FieldInfo[] members = type.GetFields();
                PropertyInfo[] info = type.GetProperties();
                //利用二维数组批量写入
                string[,] arr = new string[rowCount, colCount];

                for (int j = 0; j < rowCount; j++)
                {
                    for (int k = 0; k < info.Count(); ++k)
                    {
                        System.Reflection.PropertyInfo item = (System.Reflection.PropertyInfo)info.ElementAt(k);

                        if (j == 0)
                        {
                            if (item.Name != "operateinfomodel")
                                writer.Write(DataGridAttach._columnNameMap[item.Name] + "\t");
                        }
                        else if (item.PropertyType.Name.StartsWith("Int32"))
                        {
                            writer.Write(item.GetValue(tableList[j -1], null) + "\t");
                        }
                        else if (item.PropertyType.Name.StartsWith("Int64"))
                        {
                            writer.Write(item.GetValue(tableList[j -1], null) + "\t");
                        }
                        else if (item.PropertyType.Name.StartsWith("String"))
                        {
                            writer.Write(item.GetValue(tableList[j -1], null) + "\t");
                        }
                        else if (item.PropertyType.Name.StartsWith("Boolean"))
                        {
                            writer.Write(item.GetValue(tableList[j -1], null) + "\t");
                        }
                        else
                        {
                            ;
                        }
                    }
                    writer.WriteLine();
                }
                writer.Close();
            }
        }
        private void ExportExcel(object obj)
        {
            System.Windows.Forms.SaveFileDialog opf = new System.Windows.Forms.SaveFileDialog();
            opf.FileName = DateTime.Now.ToString("yyyyMMddHHmmss");
            opf.Filter = "*.xls|*.xls|所有文件(*.*)|*.*";
            if (opf.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                string filepath = opf.FileName;

                new Thread(() =>
                {

                    object missing = System.Reflection.Missing.Value;
                    Microsoft.Office.Interop.Excel.Application app = new Microsoft.Office.Interop.Excel.Application();
                    //创建一个Application对象并使其不可见
                    app.Visible=false;
                    //创建一个WorkBook对象
                    Microsoft.Office.Interop.Excel.Workbook workBook = app.Workbooks.Add(missing);
                    Microsoft.Office.Interop.Excel.Worksheet workSheet = null;
                    Microsoft.Office.Interop.Excel.Range range = null;

                    workSheet = (Microsoft.Office.Interop.Excel.Worksheet)workBook.Worksheets.Add(
                                                                                                Type.Missing,
                                                                                                workBook.ActiveSheet,
                                                                                                Type.Missing,
                                                                                                Type.Missing);
                    Type type = typeof(SHEBEIGUANLIModel);
                    int rowCount = tableList.Count + 1;  //DataTable行数+GirdHead
                    int colCount = type.GetProperties().Count(); //DataTable列数
                    FieldInfo[] members = type.GetFields();
                    PropertyInfo[] info = type.GetProperties();
                    //利用二维数组批量写入
                    string[,] arr = new string[rowCount, colCount];

                    for (int j = 0; j < rowCount; j++)
                    {
                        int col = 0;
                        for (int k = 0; k < info.Count(); ++k)
                        {
                            System.Reflection.PropertyInfo item = (System.Reflection.PropertyInfo)info.ElementAt(k);

                            if (j == 0)
                            {
                                if(item.Name != "operateinfomodel")
                                    arr[j, col] = DataGridAttach._columnNameMap[item.Name];
                            }
                            else if (item.PropertyType.Name.StartsWith("Int32"))
                            {
                                arr[j, k] += item.GetValue(tableList[j -1], null);
                            }
                            else if (item.PropertyType.Name.StartsWith("Int64"))
                            {
                                arr[j, k] += item.GetValue(tableList[j -1], null);
                            }
                            else if (item.PropertyType.Name.StartsWith("String"))
                            {
                                arr[j, k] += item.GetValue(tableList[j -1], null);
                            }
                            else if (item.PropertyType.Name.StartsWith("Boolean"))
                            {
                                arr[j, k] += item.GetValue(tableList[j -1], null);
                            }
                            else
                            {
                                ;
                            }
                        }
                    }

                    range           = (Microsoft.Office.Interop.Excel.Range)workSheet.Cells[1, 1]; //写入Exel的坐标
                    range           = range.get_Resize(rowCount, colCount);
                    range.Value2    = arr;

                    workBook.SaveAs(filepath, missing, missing, missing, missing, missing, Microsoft.Office.Interop.Excel.XlSaveAsAccessMode.xlExclusive, missing, missing, missing, missing, missing);

                    if (workBook.Saved)
                    {
                        workBook.Close(null, null, null);
                        app.Workbooks.Close();
                        app.Quit();
                    }

                    if (range != null)
                    {
                        System.Runtime.InteropServices.Marshal.ReleaseComObject(range);
                        range = null;
                    }

                    if (workSheet != null)
                    {
                        System.Runtime.InteropServices.Marshal.ReleaseComObject(workSheet);
                        workSheet = null;
                    }
                    if (workBook != null)
                    {
                        System.Runtime.InteropServices.Marshal.ReleaseComObject(workBook);
                        workBook = null;
                    }
                    if (app != null)
                    {
                        System.Runtime.InteropServices.Marshal.ReleaseComObject(app);
                        app = null;
                    }

                    GC.Collect();//强制代码垃圾回收

                }).Start();
            }
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

        public void QueryTableCallBack(string resultStr, string errorStr)
        {
            Type type = null;
            switch (_queryEnum)
            {
                case QueryEnum.QueryEnum_Device:
                    type = typeof(SHEBEIGUANLIModel);
                    break;
                case QueryEnum.QueryEnum_Upgrade:
                    type = typeof(RUANJIANBAOModel);
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
                    switch(_queryEnum)
                    {
                        case QueryEnum.QueryEnum_Device:
                            (model as SHEBEIGUANLIModel).operateinfomodel.operatemodel = OperateModelEnum.OperateModel_Upgrade;
                            _tableListTemp.Add(model as SHEBEIGUANLIModel);
                            break;
                        case QueryEnum.QueryEnum_Upgrade:
                            Application.Current.Dispatcher.Invoke(
                             new Action(() =>
                             {
                                 ruanjianList.Add(model as RUANJIANBAOModel);
                             }));
                            break;
                    }
                }
            }

            switch (_queryEnum)
            {
                case QueryEnum.QueryEnum_Device:
                    Application.Current.Dispatcher.Invoke(
                     new Action(() =>
                     {
                         ShowPage(1);
                     }));
                    break;
                case QueryEnum.QueryEnum_Upgrade:
                    break;
            }

            _queryEnum = QueryEnum.QueryEnum_None;
        }

        public void QueryShebeiguanli(object obj)
        {
            _queryEnum = QueryEnum.QueryEnum_Device;
            _tableListTemp.Clear();
            tableList.Clear();
            WorkServer.QueryTable(MakeQuerySql(obj), Marshal.GetFunctionPointerForDelegate(_querytablecallbackdelegate));
        }

        public void QueryRuanjianbao(object obj)
        {
            _queryEnum = QueryEnum.QueryEnum_Upgrade;
            ruanjianList.Clear();
            WorkServer.QueryTable("select * from Ruanjianbao", Marshal.GetFunctionPointerForDelegate(_querytablecallbackdelegate), false);
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
            QueryRuanjianbao(null);
        }
    }
}
