using ManageSystem.Model;
using ManageSystem.Server;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.IO;
using System.Linq;
using System.Net;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Windows;

namespace ManageSystem.ViewModel.DeviceViewModel
{
   public  class NetViewModel : NotificationObject
    {
        private Dictionary<Int32, Int32> _netdatamap = new Dictionary<int,int>
            {
                {1024*1024*0     ,-130 + 26*0   },
                {1024*1024*1     ,-130 + 26*1   },
                {1024*1024*2     ,-130 + 26*2   },
                {1024*1024*5     ,-130 + 26*3   },
                {1024*1024*10    ,-130 + 26*4   },
                {1024*1024*20    ,-130 + 26*5   },
                {1024*1024*50    ,-130 + 26*6   },
                {1024*1024*100   ,-130 + 26*7   },
                {1024*1024*200   ,-130 + 26*8   },
                {1024*1024*500   ,-130 + 26*9   },
                {1024*1024*1000  ,-130 + 26*10  },
            };
        BackgroundWorker                speedbgw = new BackgroundWorker();

        public QueryTableCallBackDelegate   _querytablecallbackdelegate = null;
        private OperateEnum                    _queryEnum = OperateEnum.OperateEnum_None;

        private ObservableCollection<SHEBEIGUANLIModel> _tableListTemp = new ObservableCollection<SHEBEIGUANLIModel>();

        public DelegateCommand<object> QueryCommand { get; set; }
        public DelegateCommand<object> TestCommand { get; set; }
        public DelegateCommand<object> OperateCommand { get; set; }

        public DelegateCommand<object> FirstPageCommand { get; set; }
        public DelegateCommand<object> PrePageCommand { get; set; }
        public DelegateCommand<object> NextPageCommand { get; set; }
        public DelegateCommand<object> GotoPageCommand { get; set; }
        public DelegateCommand<object> UpgradeCommand { get; set; }

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
        private SHEBEIGUANLIModel _customInfo1;
        public SHEBEIGUANLIModel customInfo1
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

        private string _statusText;
        public string statusText
        {
            get
            {
                return _statusText;
            }
            set
            {
                _statusText = value;
                this.RaisePropertyChanged("statusText");
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

        private string _testCnt;
        public string testCnt
        {
            get
            {
                return _testCnt;
            }
            set
            {
                _testCnt = value;
                this.RaisePropertyChanged("testCnt");
            }
        }
        private string _dataLen;
        public string dataLen
        {
            get
            {
                return _dataLen;
            }
            set
            {
                _dataLen = value;
                this.RaisePropertyChanged("dataLen");
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

        public NetViewModel()
        {
            _querytablecallbackdelegate                 = new QueryTableCallBackDelegate(QueryTableCallBack);

            TestCommand                                 = new DelegateCommand<object>(QuerySpeed);
            QueryCommand                                = new DelegateCommand<object>(QueryShebeiguanli);
            OperateCommand                              = new DelegateCommand<object>(Operate);

            FirstPageCommand                            = new DelegateCommand<object>(FirstPage);
            PrePageCommand                              = new DelegateCommand<object>(PrePage);
            NextPageCommand                             = new DelegateCommand<object>(NextPage);
            GotoPageCommand                             = new DelegateCommand<object>(GotoPage);

            ExportExcelCommand                          = new DelegateCommand<object>(ExportExcel);
            ExportTXTCommand                            = new DelegateCommand<object>(ExportTXT);

            _tableList                                  = new ObservableCollection<SHEBEIGUANLIModel>();
            _customInfo                                 = new SHEBEIGUANLIModel();
            _customInfo1                                = new SHEBEIGUANLIModel();
            _pagePercent                                = "0/0";
            _dataLen                                    = "" + 10000;
            _statusText                                 = "";
            _Angle                                      = -130;
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

                int rowCount = 1 + 1;  //DataTable行数+GirdHead
                int colCount = 1; //DataTable列数

                for (int j = 0; j < rowCount; j++)
                {
                    for (int k = 0; k < colCount; k++)
                    {
                        if (j == 0)
                        {
                            writer.Write("测试速度:" + "\t");
                        }
                        else
                        {
                            writer.Write(statusText + "\t");
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

                int rowCount = 1;  //DataTable行数+GirdHead
                int colCount = 1; //DataTable列数

                //利用二维数组批量写入
                string[,] arr = new string[rowCount, colCount];

                for (int j = 0; j < rowCount; j++)
                {
                    for (int k = 0; k < colCount; k++)
                    {
                        if (j == 0)
                        {
                            arr[j, k] = "测试速度:";

                        }
                        else
                        {
                            arr[j, k] = statusText;
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
                case OperateEnum.OperateEnum_QueryTestSpeed:
                    type = typeof(object);
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

                        switch(_queryEnum)
                        {
                            case OperateEnum.OperateEnum_QueryTestSpeed:
                                Application.Current.Dispatcher.Invoke(
                                 new Action(() =>
                                 {
                                     if (keyvalue[0] == "speed")
                                     {
                                         double speed = Convert.ToDouble(keyvalue[1]);

                                         for(int index = 0; index < _netdatamap.Count; ++index)
                                         {
                                             KeyValuePair<Int32, Int32> kvp = _netdatamap.ElementAt(index);

                                             if((index + 1) != _netdatamap.Count)
                                             {
                                                KeyValuePair<Int32, Int32> kvp1 = _netdatamap.ElementAt(index + 1);
                                                if(speed > kvp.Key && speed < kvp1.Key)
                                                {
                                                   if(speedbgw.IsBusy)
                                                       break;

                                                    double angleCur     = -130;
                                                    double angleDes     = (speed - kvp.Key)/(kvp1.Key - kvp.Key) * 26 + kvp.Value;

                                                    speedbgw = new BackgroundWorker();
                                                    speedbgw.WorkerSupportsCancellation = true;
                                                    speedbgw.WorkerReportsProgress = true;

                                                    speedbgw.DoWork += (object sender, DoWorkEventArgs ee) =>
                                                    {
                                                        for (int i = 0; i < 100; ++i)
                                                        {
                                                            Thread.Sleep(50);
                                                            double span = (angleDes - (-130))/100;
                                                            angleCur += span;
                                                            (sender as BackgroundWorker).ReportProgress(0, angleCur);

                                                            if (Angle >= angleDes)
                                                                break;
                                                        }
                                                    };

                                                    speedbgw.ProgressChanged += (object sender, ProgressChangedEventArgs ee) =>
                                                    {
                                                        Angle = (double)ee.UserState;
                                                        for (int inx = 0; inx < _netdatamap.Count; ++inx)
                                                        {
                                                            KeyValuePair<Int32, Int32> kvpp = _netdatamap.ElementAt(inx);

                                                            if ((inx + 1) != _netdatamap.Count)
                                                            {
                                                                KeyValuePair<Int32, Int32> kvpp1 = _netdatamap.ElementAt(inx + 1);
                                                                if (Angle > kvpp.Value && Angle < kvpp1.Value)
                                                                {
                                                                   double curspeed = (Angle - kvpp.Value)/(kvpp1.Value - kvpp.Value) * (kvpp1.Key - kvpp.Key) + kvpp.Key;
                                                                   if (curspeed > 1024 * 1024)
                                                                   {
                                                                       curspeed /= 1024*1024;
                                                                       statusText = String.Format("{0:0.000} MByte/s", curspeed);
                                                                   }
                                                                   else if (curspeed > 1024)
                                                                   {
                                                                       curspeed /= 1024;
                                                                       statusText = String.Format("{0:0.000} KByte/s", curspeed);
                                                                   }
                                                                   else
                                                                   {
                                                                       statusText = String.Format("{0:0.000} Byte/s", curspeed);
                                                                   }
                                                                   break;
                                                                }
                                                            }
                                                        }
                                                    };
                                                    speedbgw.RunWorkerCompleted += (object sender, RunWorkerCompletedEventArgs ee) =>
                                                    {
                                                        if (speed > 1024 * 1024)
                                                        {
                                                            speed /= 1024*1024;
                                                            statusText = String.Format("{0:0.000} MByte/s", speed);
                                                        }
                                                        else if (speed > 1024)
                                                        {
                                                            speed /= 1024;
                                                            statusText = String.Format("{0:0.000} KByte/s", speed);
                                                        }
                                                        else
                                                        {
                                                            statusText = String.Format("{0:0.000} Byte/s", speed);
                                                        }
                                                    };

                                                    speedbgw.RunWorkerAsync();
                                                    break;
                                                }
                                             }
                                             else
                                             {
                                                speed /= 1024*1024;
                                                statusText = String.Format("{0:0.000} MByte/s", speed);
                                                break;
                                             }
                                         }
                                     }
                                 }));
                                break;
                            case OperateEnum.OperateEnum_QueryDevice:
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
                                break;
                        }
                    }
                    switch (_queryEnum)
                    {
                        case OperateEnum.OperateEnum_QueryDevice:
                            (model as SHEBEIGUANLIModel).operateinfomodel.operatemodel = OperateModelEnum.OperateModel_TestSpeed;
                            _tableListTemp.Add(model as SHEBEIGUANLIModel);
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

        private void QuerySpeed(object obj)
        {
            testIP = customInfo.IP;
        }

        private void Operate(object obj)
        {
            if(speedbgw!=null && !speedbgw.IsBusy)
            {
                _queryEnum  = OperateEnum.OperateEnum_QueryTestSpeed;
                statusText  = "测速中……";
                Angle       = -130;
                IPAddress addr;
                if (IPAddress.TryParse(testIP, out addr))
                    WorkServer.queryDevSpeed(testIP, Marshal.GetFunctionPointerForDelegate(_querytablecallbackdelegate), true);
            }
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
            QueryShebeiguanli(null);
        }
    }
}
