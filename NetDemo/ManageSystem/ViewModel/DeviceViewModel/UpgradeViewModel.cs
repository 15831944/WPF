using ManageSystem.Model;
using ManageSystem.Resources.DataGridAttachRes;
using ManageSystem.Server;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Diagnostics;
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
   public  class UpgradeViewModel : NotificationObject
    {
       BackgroundWorker                     addbgw = new BackgroundWorker();

       public QueryTableCallBackDelegate   _querytablecallbackdelegate = null;
       public AddTableCallBackDelegate     _addtablecallbackdelegate = null;
       public UpgradeCallBackDelegate      _upgradecallbackdelegate = null;
       private OperateEnum                 _queryEnum = OperateEnum.OperateEnum_None;

       private ObservableCollection<SHEBEIGUANLIModel> _tableListTemp = new ObservableCollection<SHEBEIGUANLIModel>();


       public DelegateCommand<object> QueryCommand { get; set; }
       public DelegateCommand<object> OperateCommand { get; set; }

       public DelegateCommand<object> FirstPageCommand { get; set; }
       public DelegateCommand<object> PrePageCommand { get; set; }
       public DelegateCommand<object> NextPageCommand { get; set; }
       public DelegateCommand<object> GotoPageCommand { get; set; }
       public DelegateCommand<object> UpgradeVersionCommand { get; set; }
       public DelegateCommand<object> UpgradeCommand { get; set; }
       public DelegateCommand<object> PowerUpgradeCommand { get; set; }
       public DelegateCommand<object> ExportExcelCommand { get; set; }
       public DelegateCommand<object> ExportTXTCommand { get; set; }

       public DelegateCommand<object> SelectSteupCommand { get; set; }

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

        private string _testIP;
        public string testIP
        {
            get
            {
                return _testIP;
            }
            set
            {
                _testIP = value;
                this.RaisePropertyChanged("testIP");
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

        private string _version;
        public string version
        {
            get
            {
                return _version;
            }
            set
            {
                _version = value;
                this.RaisePropertyChanged("version");
            }
        }

        private string _filePath;
        public string filePath
        {
            get
            {
                return _filePath;
            }
            set
            {
                _filePath = value;
                this.RaisePropertyChanged("filePath");
            }
        }

        private string _displayMsg;
        public string displayMsg
        {
            get { return _displayMsg; }
            set
            {
                _displayMsg = value;
                this.RaisePropertyChanged("displayMsg");
            }
        }

        private double _Angle;
        public double Angle
        {
            get
            {
                return _Angle;
            }
            set
            {
                _Angle = value;
                this.RaisePropertyChanged("Angle");
            }
        }

        public UpgradeViewModel()
        {
            _querytablecallbackdelegate                 = new QueryTableCallBackDelegate(QueryTableCallBack);
            _addtablecallbackdelegate                   = new AddTableCallBackDelegate(AddTableCallBack);
            _upgradecallbackdelegate                    = new UpgradeCallBackDelegate(UpgradeCallBack);

            QueryCommand                                = new DelegateCommand<object>(QueryShebeiguanli);
            OperateCommand                              = new DelegateCommand<object>(Operate);

            FirstPageCommand                            = new DelegateCommand<object>(FirstPage);
            PrePageCommand                              = new DelegateCommand<object>(PrePage);
            NextPageCommand                             = new DelegateCommand<object>(NextPage);
            GotoPageCommand                             = new DelegateCommand<object>(GotoPage);
            UpgradeVersionCommand                       = new DelegateCommand<object>(UpgradeVersion);
            UpgradeCommand                              = new DelegateCommand<object>(Upgrade);
            PowerUpgradeCommand                         = new DelegateCommand<object>(PowerUpgrade);
            ExportExcelCommand                          = new DelegateCommand<object>(ExportExcel);
            ExportTXTCommand                            = new DelegateCommand<object>(ExportTXT);
            SelectSteupCommand                          = new DelegateCommand<object>(SelectSteup);

            _tableList                                  = new ObservableCollection<SHEBEIGUANLIModel>();
            _ruanjianList                               = new ObservableCollection<RUANJIANBAOModel>();
            _customInfo                                 = new SHEBEIGUANLIModel();
            _pagePercent                                = "0/0";

            _operateenum                                = OperateEnum.OperateEnum_None;
            _displayMsg                                 = "";
            _version                                    = "";
            _filePath                                   = "";
            _Angle                                      = -130;
        }

        private void AddTableCallBack(string resultStr, string errorStr)
        {
            if (errorStr != null && errorStr.Length != 0)
            {
                displayMsg = errorStr;
            }
            else
            {
                if(string.IsNullOrEmpty(resultStr))
                {
                    Angle = 360 + -130;
                }
                else
                {
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
                                if (keyvalue.Length != 2 || keyvalue[1] == null || keyvalue[1].Length == 0)
                                    continue;

                                if (keyvalue[0] == "progress")
                                {
                                    double progress = Convert.ToDouble(keyvalue[1]);

                                    Angle = progress * 3.6 + -130;
                                    Debug.WriteLine(progress);
                                }
                            }
                        }
                    }
                }
            }
        }
        private void Operate(object obj)
        {
            switch (operateenum)
            {
                case OperateEnum.OperateEnum_UpgradeVersion:
                    {
                        if ((Angle != -130) && Angle != (-130 + 360))
                            break;

                        new Thread(() =>
                        {
                            if (string.IsNullOrEmpty(version))
                            {
                                displayMsg = "版本号不能为空！";
                                return;
                            }
                            foreach (var item in ruanjianList)
                            {
                                if (item.Banbenhao == version)
                                {
                                    displayMsg = "版本号已存在！";
                                    return;
                                }
                            }

                            if (!File.Exists(filePath))
                            {
                                displayMsg = "请输入有效文件路径！";
                                return;
                            }
                            else
                            {
                                FileInfo fileinfo = new FileInfo(filePath);
                                if (fileinfo.Length > 0x6400000)
                                {
                                    displayMsg = "文件不能大于100M";
                                    return;
                                }
                            }

                            displayMsg  = "";
                            Angle       = -130 + 1;

                            try
                            {
                                FileStream stream = new FileStream(filePath, FileMode.Open, FileAccess.Read);

                                byte[] array = new byte[stream.Length];
                                stream.Read(array, 0, (int)stream.Length);
                                stream.Close();

                                WorkServer.addRuanjianbao("0", version, Marshal.UnsafeAddrOfPinnedArrayElement(array, 0), array.Length, Marshal.GetFunctionPointerForDelegate(_addtablecallbackdelegate), true);
                                QueryRuanjianbao(null);
                            }
                            catch (Exception e)
                            {
                                string str = e.Message;
                            }
                        }).Start();
                    }
                    break;
            }
        }
       
        private void SelectSteup(object obj)
        {
            System.Windows.Forms.OpenFileDialog opf = new System.Windows.Forms.OpenFileDialog();
            opf.FileName = DateTime.Now.ToString("yyyyMMddHHmmss");
            opf.Filter = "*.exe|*.exe|所有文件(*.*)|*.*";
            if (opf.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                filePath = opf.FileName;
            }
        }
        private void UpgradeVersion(object obj)
        {
            operateenum = OperateEnum.OperateEnum_UpgradeVersion;
        }
        private void UpgradeCallBack(string resultStr, string errorStr)
        {
            if (errorStr != null && errorStr.Length != 0)
            {
                MessageBox.Show(errorStr);
            }
            else
            {
                if (string.IsNullOrEmpty(resultStr))
                {
                    Angle = 360 + -130;
                }
                else
                {
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
                                if (keyvalue.Length != 2 || keyvalue[1] == null || keyvalue[1].Length == 0)
                                    continue;

                                if (keyvalue[0] == "downloadprogress")
                                {
                                    double progress = Convert.ToDouble(keyvalue[1]);

                                    Angle = progress * 3.6 + -130;
                                }
                            }
                        }
                    }
                }
            }
        }
        private void PowerUpgrade(object obj)
        {
            //string str = "version:0.0.0.3,ip:192.168.1.107,;";
            //WorkServer.upgrade(str, Marshal.GetFunctionPointerForDelegate(_upgradecallbackdelegate), false);
            Upgrade(obj);
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
                case OperateEnum.OperateEnum_QueryDevice:
                    type = typeof(SHEBEIGUANLIModel);
                    break;
                case OperateEnum.OperateEnum_QueryUpgrade:
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
                        case OperateEnum.OperateEnum_QueryDevice:
                            (model as SHEBEIGUANLIModel).operateinfomodel.operatemodel = OperateModelEnum.OperateModel_Upgrade;
                            _tableListTemp.Add(model as SHEBEIGUANLIModel);
                            break;
                        case OperateEnum.OperateEnum_QueryUpgrade:
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
                case OperateEnum.OperateEnum_QueryDevice:
                    Application.Current.Dispatcher.Invoke(
                     new Action(() =>
                     {
                         ShowPage(1);
                     }));
                    break;
                case OperateEnum.OperateEnum_QueryUpgrade:
                    break;
            }

            _queryEnum = OperateEnum.OperateEnum_None;
        }

        public void QueryShebeiguanli(object obj)
        {
            _queryEnum = OperateEnum.OperateEnum_QueryDevice;
            _tableListTemp.Clear();
            tableList.Clear();
            WorkServer.QueryTable(MakeQuerySql(obj), Marshal.GetFunctionPointerForDelegate(_querytablecallbackdelegate));
        }

        public void QueryRuanjianbao(object obj)
        {
            _queryEnum = OperateEnum.OperateEnum_QueryUpgrade;
            ruanjianList.Clear();
            WorkServer.QueryTable("Select Bianhao as Bianhao,Banbenhao as Banbenhao From Ruanjianbao", Marshal.GetFunctionPointerForDelegate(_querytablecallbackdelegate), false);
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
