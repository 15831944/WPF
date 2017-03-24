using ManageSystem.Model;
using ManageSystem.Server;
using ManageSystem.ViewModel.DeviceViewModel;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Drawing;
using System.Linq;
using System.Net;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Windows;


namespace ManageSystem.ViewModel
{
   public  class SignStatViewModel : NotificationObject
    {
        int                                             _lineCharIndex;
        int                                             _histogramCharIndex;
        int                                             _pieCharIndex;

        public QueryTableCallBackDelegate               _querytablecallbackdelegate = null;

        public DelegateCommand<object>                  LoadedCommand { get; set; }
        public DelegateCommand<object>                  SizeChangedCommand { get; set; }
        public DelegateCommand<object>                  ShowPieChartCommand { get; set; }
        public DelegateCommand<object>                  ShowLineChartCommand { get; set; }
        public DelegateCommand<object>                  ShowHistogramChartCommand { get; set; }
        public DelegateCommand<object>                  StatisticsCommand { get; set; }

        private ShowChartEnum _bShowChart;
        public ShowChartEnum bShowChart
        {
            get { return _bShowChart; }
            set
            {
                _bShowChart = value;
                this.RaisePropertyChanged("bShowChart");
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

        private string _dataTypeText;
        public string dataTypeText
        {
            get { return _dataTypeText; }
            set
            {
                _dataTypeText = value;
                this.RaisePropertyChanged("dataTypeText");
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

        private string _devicePositionText;
        public string devicePositionText
        {
            get { return _devicePositionText; }
            set
            {
                _devicePositionText = value;
                this.RaisePropertyChanged("devicePositionText");
            }
        }

        private int _leftListWidth;
        public int leftListWidth
        {
            get { return _leftListWidth; }
            set
            {
                _leftListWidth = value;
                this.RaisePropertyChanged("leftListWidth");
            }
        }

        private int _topHeight;
        public int topHeight
        {
            get { return _topHeight; }
            set
            {
                _topHeight = value;
                this.RaisePropertyChanged("topHeight");
            }
        }

        private int _regionTextHeight;
        public int regionTextHeight
        {
            get { return _regionTextHeight; }
            set
            {
                _regionTextHeight = value;
                this.RaisePropertyChanged("regionTextHeight");
            }
        }

        private string _region0Text;
        public string region0Text
        {
            get { return _region0Text; }
            set
            {
                _region0Text = value;
                this.RaisePropertyChanged("region0Text");
            }
        }
        public SignStatViewModel()
        {
            _querytablecallbackdelegate                 = new QueryTableCallBackDelegate(QueryTableCallBack);
            LoadedCommand                               = new DelegateCommand<object>(new Action<object>(this.Loaded));
            SizeChangedCommand                          = new DelegateCommand<object>(new Action<object>(this.SizeChanged));
            ShowPieChartCommand                         = new DelegateCommand<object>(new Action<object>(this.ShowPieChart));
            ShowLineChartCommand                        = new DelegateCommand<object>(new Action<object>(this.ShowLineChart));
            ShowHistogramChartCommand                   = new DelegateCommand<object>(new Action<object>(this.ShowHistogramChart));
            StatisticsCommand                           = new DelegateCommand<object>(new Action<object>(this.Statistics));

            startTime                                   = DateTime.Now.AddDays(-7).ToString("dddd, MMMM d, yyyy h:mm:ss tt");
            endTime                                     = DateTime.Now.AddDays(7).ToString("dddd, MMMM d, yyyy h:mm:ss tt");
            _leftListWidth                              = 150;
            _topHeight                                  = 60;
            _regionTextHeight                           = 50;
            _bShowChart                                 = ShowChartEnum.ShowChartEnum_Histogram;

            _lineCharIndex                              = -1;
            _histogramCharIndex                         = -1;
            _pieCharIndex                               = -1;
        }


        private void QueryTableCallBack(string resultStr, string errorStr)
        {
            string[] rows   = resultStr.Split(';');
            foreach (string row in rows)
            {
                if (row.Length > 0)
                {
                    string[] cells  = row.Split(',');
                    foreach (string cell in cells)
                    {
                        string[] keyvalue = cell.Split(':');
                        if (keyvalue.Length != 2 || keyvalue[1] == null || keyvalue[1].Length == 0)
                            continue;

                        LineChartServer.SetCurvePointInfo(_lineCharIndex, Convert.ToInt32(keyvalue[0]), Convert.ToInt32(keyvalue[1]));
                        {
                            int rowIndex        = Convert.ToInt32(keyvalue[0]);
                            int clr0_1          = Color.Azure.ToArgb() + 100 * (rowIndex + 0);
                            int clr0_2          = Color.Azure.ToArgb() + 100 * (rowIndex + 1);
                            int clr0_3          = Color.Azure.ToArgb() + 100 * (rowIndex + 2);
                            int clr0_4          = Color.Azure.ToArgb() + 100 * (rowIndex + 3);

                            PieChartServer.SetPieBasicInfo(_pieCharIndex, Convert.ToInt32(keyvalue[0]), (float)(Convert.ToDouble(keyvalue[1])),
                                 clr0_1,
                                 clr0_2,
                                 clr0_3,
                                 clr0_4
                                );
                        }

                        {
                            int rowIndex        = Convert.ToInt32(keyvalue[0]);
                            int clr1            = Color.BlueViolet.ToArgb() + 100 * rowIndex;
                            HistogramServer.SetHistogramBasicInfo(_lineCharIndex, Convert.ToInt32(keyvalue[0]), Convert.ToInt32(keyvalue[1]), clr1);
                        }
                    }
                }
            }

            PieChartServer.RedrawChart(_pieCharIndex);
            LineChartServer.RedrawChart(_lineCharIndex);
            HistogramServer.RedrawChart(_histogramCharIndex);
        }

        private void Statistics(object obj)
        {
            WorkServer.QueryTable(MakeStatisticsQuerySql(obj), Marshal.GetFunctionPointerForDelegate(_querytablecallbackdelegate), true);
        }
        public string MakeDeviceConditionSql(string tableName)
        {
            string str = "";
            foreach (DeviceModel model0 in DevicemaViewModel._deviceList)
            {
                if (model0.isSel)
                {
                    foreach (KeyValuePair<int, string> kvp0 in MainWindowViewModel._yingshelList)
                    {
                        if (kvp0.Value == model0.text)
                            str += " and "+ tableName + ".[Chengshibianhao]=" + kvp0.Key.ToString();
                    }
                }

                foreach (DeviceModel model1 in model0.Children)
                {
                    if (model1.isSel)
                    {
                        foreach (KeyValuePair<int, string> kvp0 in MainWindowViewModel._yingshelList)
                        {
                            if (kvp0.Value == model1.text)
                                str += " and "+ tableName + ".[Jubianhao]=" + kvp0.Key.ToString();
                        }
                    }

                    foreach (DeviceModel model2 in model1.Children)
                    {
                        if (model2.isSel)
                        {
                            foreach (KeyValuePair<int, string> kvp0 in MainWindowViewModel._yingshelList)
                            {
                                if (kvp0.Value == model2.text)
                                    str += " and "+ tableName + ".[Shiyongdanweibianhao]=" + kvp0.Key.ToString();
                            }
                        }
                        foreach (DeviceModel model3 in model2.Children)
                        {
                            if (model3.isSel)
                            {
                                str += " and "+ tableName + ".[IP]=" + Convert.ToInt32(IPAddress.HostToNetworkOrder((Int32)Common.IpToInt(model3.text)));
                            }
                        }
                    }
                }
            }
            return str;
        }
        string MakeStatisticsQuerySql(object obj)
        {
            DateTime realstartTime  = DateTime.Parse(startTime);
            DateTime realendTime   = DateTime.Parse(endTime);

            string str = "select ";
            string strCondition = "";
            int index = 0;

            do
            {
                strCondition += " ( ";
                strCondition += "select count(*) as totalCnt from Zhiqianshuju where Xuhao>=-1";
                strCondition +=  MakeDeviceConditionSql("Zhiqianshuju");
                strCondition += " and Zhiqianshuju.[Riqi]>=" + Common.ConvertDateTimeInt(realstartTime);

                if (dataTypeText.Contains("天"))
                    realstartTime = realstartTime.AddDays(1);
                else if (dataTypeText.Contains("周"))
                    realstartTime = realstartTime.AddDays(7);
                else if (dataTypeText.Contains("月"))
                    realstartTime = realstartTime.AddMonths(1);
                else if (dataTypeText.Contains("年"))
                    realstartTime = realstartTime.AddYears(1);

                if (realstartTime < realendTime)
                    strCondition             += " and Zhiqianshuju.[Riqi]<" + Common.ConvertDateTimeInt(realstartTime);
                else
                    strCondition             += " and Zhiqianshuju.[Riqi]<" + Common.ConvertDateTimeInt(realendTime);
                strCondition += " ) as " +  "'" + index + "'";

                index++;
                if (realstartTime < realendTime && index < 12)
                    strCondition    += ",";
            } while (realstartTime < realendTime && index < 12);
         

            Application.Current.Dispatcher.Invoke(
                new Action(()=>
             {
                 IntPtr hwnd = new System.Windows.Interop.WindowInteropHelper(Application.Current.MainWindow).Handle;
                 tagRECT rcClient = new tagRECT();

                PieChartServer.RemovePieChart(_pieCharIndex);
                LineChartServer.RemoveCurveChart(_lineCharIndex);
                HistogramServer.RemoveHistogramChart(_histogramCharIndex);

                _pieCharIndex       = PieChartServer.AddPieChart(hwnd,  rcClient);
                _lineCharIndex      = LineChartServer.AddCurveChart(hwnd,  rcClient);
                _histogramCharIndex = HistogramServer.AddHistogramChart(hwnd,  rcClient, 0, 3000, 300, Color.Red.ToArgb(), Color.Black.ToArgb(), Color.Green.ToArgb());
                ResizeShowCharts();

                PieChartServer.AddData(_pieCharIndex, index);
                LineChartServer.AddData(_lineCharIndex, 13, index, 3600);
                HistogramServer.AddData(_histogramCharIndex, index);
            }));

            return str + strCondition;
        }

        private void ShowHistogramChart(object obj)
        {
            bShowChart = ShowChartEnum.ShowChartEnum_Histogram;
            ResizeShowCharts();
        }

        private void ShowLineChart(object obj)
        {
            bShowChart = ShowChartEnum.ShowChartEnum_Line;
            ResizeShowCharts();
        }

        private void ShowPieChart(object obj)
        {
            bShowChart = ShowChartEnum.ShowChartEnum_Pie;
            ResizeShowCharts();
        }

        private void SizeChanged(object obj)
        {
            ResizeShowCharts();
        }

        private void Loaded(object obj)
        {

        }

        public void DoLogon()
        {
            IntPtr hwnd = new System.Windows.Interop.WindowInteropHelper(Application.Current.MainWindow).Handle;
            tagRECT rcClient = new tagRECT();

            _pieCharIndex       = PieChartServer.AddPieChart(hwnd, rcClient);
            _lineCharIndex      = LineChartServer.AddCurveChart(hwnd, rcClient);
            _histogramCharIndex = HistogramServer.AddHistogramChart(hwnd, rcClient, 0, 3000, 300, Color.Red.ToArgb(), Color.Black.ToArgb(), Color.Green.ToArgb());

            ResizeShowCharts();
        }

        public void ResizeShowCharts()
        {
            tagRECT rect1 = new tagRECT();
            tagRECT rect2 = new tagRECT();
            tagRECT rect3 = new tagRECT();
            tagRECT rect4 = new tagRECT();

            MainWindowViewModel mainModel               = Application.Current.MainWindow.DataContext as MainWindowViewModel;
            Window              mainWnd                 = Application.Current.MainWindow;

            if(mainModel.bShowPage == PageVisibleEnum.PageVisibleEnum_SignStat)
            {
                double totalTitleHeight                     = mainModel.titleheight + topHeight;
                System.Windows.Point  ptOriginalDlg         = new System.Windows.Point(0, 0);
                System.Windows.Point  ptTopLeftDlg1         = new System.Windows.Point(mainModel.leftWidth + leftListWidth, totalTitleHeight + regionTextHeight);
                System.Windows.Point  ptBotRightDlg1        = new System.Windows.Point(mainWnd.Width, mainWnd.Height);

                ptOriginalDlg                               = mainWnd.PointToScreen(ptOriginalDlg);
                ptTopLeftDlg1                               = mainWnd.PointToScreen(ptTopLeftDlg1);
                ptBotRightDlg1                              = mainWnd.PointToScreen(ptBotRightDlg1);

                rect1.left                                  = Convert.ToInt32(ptTopLeftDlg1.X - ptOriginalDlg.X);
                rect1.top                                   = Convert.ToInt32(ptTopLeftDlg1.Y - ptOriginalDlg.Y);
                rect1.right                                 = Convert.ToInt32(ptBotRightDlg1.X - ptOriginalDlg.X);
                rect1.bottom                                = Convert.ToInt32(ptBotRightDlg1.Y - ptOriginalDlg.Y);

                PieChartServer.MoveChart(_pieCharIndex,  rect1, true);
                LineChartServer.MoveChart(_lineCharIndex,  rect1, true);
                HistogramServer.MoveChart(_histogramCharIndex,  rect1, true);
                switch (bShowChart)
                {
                    case ShowChartEnum.ShowChartEnum_Pie:
                        region0Text = "制签饼图";
                        PieChartServer.ShowChart(_pieCharIndex, true);
                        LineChartServer.ShowChart(_lineCharIndex, false);
                        HistogramServer.ShowChart(_histogramCharIndex, false);
                        break;
                    case ShowChartEnum.ShowChartEnum_Line:
                        region0Text = "制签统计图";
                        PieChartServer.ShowChart(_pieCharIndex, false);
                        LineChartServer.ShowChart(_lineCharIndex, true);
                        HistogramServer.ShowChart(_histogramCharIndex, false);
                        break;
                    case ShowChartEnum.ShowChartEnum_Histogram:
                        region0Text = "制签直方图";
                        PieChartServer.ShowChart(_pieCharIndex, false);
                        LineChartServer.ShowChart(_lineCharIndex, false);
                        HistogramServer.ShowChart(_histogramCharIndex, true);
                        break;
                }
            }
            else
            {
                PieChartServer.ShowChart(_pieCharIndex, false);
                LineChartServer.ShowChart(_lineCharIndex, false);
                HistogramServer.ShowChart(_histogramCharIndex, false);
            }
        }
    }
}
