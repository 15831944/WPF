using ManageSystem.Model;
using ManageSystem.Server;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Windows;

namespace ManageSystem.ViewModel
{
    class SummaryStatViewModel : NotificationObject
    {
        public enum QueryOperate
        {
            QueryOperate_None,
            QueryOperate_LineChart,
            QueryOperate_PieChart,
            QueryOperate_HistogramChart,
        }

        int                                             _lineCharIndex;
        int                                             _histogramCharIndex;
        int                                             _pieCharIndex;

        public QueryTableCallBackDelegate               _querytablecallbackdelegate = null;
        public QueryOperate                             _queryoperate = QueryOperate.QueryOperate_None;

        public DelegateCommand<object> LoadedCommand { get; set; }
        public DelegateCommand<object> SizeChangedCommand { get; set; }
        public DelegateCommand<object> ShowPieChartCommand { get; set; }
        public DelegateCommand<object> ShowLineChartCommand { get; set; }
        public DelegateCommand<object> ShowHistogramChartCommand { get; set; }

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

        public SummaryStatViewModel()
        {
            _querytablecallbackdelegate                 = new QueryTableCallBackDelegate(QueryTableCallBack);
            LoadedCommand                               = new DelegateCommand<object>(new Action<object>(this.Loaded));
            SizeChangedCommand                          = new DelegateCommand<object>(new Action<object>(this.SizeChanged));
            ShowPieChartCommand                         = new DelegateCommand<object>(new Action<object>(this.ShowPieChart));
            ShowLineChartCommand                        = new DelegateCommand<object>(new Action<object>(this.ShowLineChart));
            ShowHistogramChartCommand                   = new DelegateCommand<object>(new Action<object>(this.ShowHistogramChart));

            startTime                                   = DateTime.Now.AddDays(-7).ToString("dddd, MMMM d, yyyy h:mm:ss tt");
            endTime                                     = DateTime.Now.AddDays(7).ToString("dddd, MMMM d, yyyy h:mm:ss tt");
            _leftListWidth                              = 150;
            _topHeight                                  = 60;
            _regionTextHeight                           = 50;
            _bShowChart                                 = ShowChartEnum.ShowChartEnum_Line;

        }

        private void QueryTableCallBack(string resultStr)
        {
            string[] rows   = resultStr.Split(';');
            int rowIndex    = 0;
            foreach (string row in rows)
            {
                if (row.Length > 0)
                {
                    string[] cells  = row.Split(',');
                    foreach (string cell in cells)
                    {
                        string[] keyvalue = cell.Split(':');
                        if (keyvalue.Length != 2)
                            continue;

                        switch (_queryoperate)
                        {

                            case QueryOperate.QueryOperate_LineChart:
                            case QueryOperate.QueryOperate_PieChart:
                            case QueryOperate.QueryOperate_HistogramChart:
                                {
                                    LineChartServer.SetCurvePointInfo(_lineCharIndex, rowIndex, Convert.ToInt32(keyvalue[1]));
                                    if(rowIndex < 3)
                                    {
                                        int clr0_1          = Color.BlueViolet.ToArgb() + 100 * (rowIndex + 0);
                                        int clr0_2          = Color.BlueViolet.ToArgb() + 100 * (rowIndex + 1);
                                        int clr0_3          = Color.BlueViolet.ToArgb() + 100 * (rowIndex + 2);
                                        int clr0_4          = Color.BlueViolet.ToArgb() + 100 * (rowIndex + 3);

                                        PieChartServer.SetPieBasicInfo(_pieCharIndex, rowIndex, Convert.ToInt32(keyvalue[1]),
                                           ref clr0_1,
                                           ref clr0_2,
                                           ref clr0_3,
                                           ref clr0_4
                                           );
                                    }

                                    int clr1    = Color.BlueViolet.ToArgb() + 100 * rowIndex;
                                    HistogramServer.SetHistogramBasicInfo(_lineCharIndex, rowIndex, Convert.ToInt32(keyvalue[1]), clr1);
                                }
                                break;
                        }
                        rowIndex++;
                    }
                }
            }

            _queryoperate = QueryOperate.QueryOperate_None;
        }

        public void QueryLineChartData(object obj)
        {
            _queryoperate = QueryOperate.QueryOperate_LineChart;
            WorkServer.QueryTable(MakeLineChartQuerySql(obj), Marshal.GetFunctionPointerForDelegate(_querytablecallbackdelegate));
        }
        string MakeBenyuebanliyewuCurMonthQuerySql(object obj, DateTime BeginTime)
        {
            string str = "SELECT sum(totalCnt) as totalCnt FROM ( ";

            str += "select count(*) as totalCnt from Zhiqianshuju where Xuhao>=-1";
            str += " and Zhiqianshuju.[Riqi]>=" + Common.ConvertDateTimeInt(Common.FirstDayOfMonth(BeginTime));
            str += " and Zhiqianshuju.[Riqi]<=" + Common.ConvertDateTimeInt(Common.LastDayOfMonth(BeginTime));
            str += " union ALL ";

            str += "select count(*) as totalCnt from Shouzhengshuju where Xuhao>=-1";
            str += " and Shouzhengshuju.[Riqi]>=" + Common.ConvertDateTimeInt(Common.FirstDayOfMonth(BeginTime));
            str += " and Shouzhengshuju.[Riqi]<=" + Common.ConvertDateTimeInt(Common.LastDayOfMonth(BeginTime));
            str += " union ALL ";

            str += "select count(*) as totalCnt from Qianzhushuju where Xuhao>=-1";
            str += " and Qianzhushuju.[Riqi]>=" + Common.ConvertDateTimeInt(Common.FirstDayOfMonth(BeginTime));
            str += " and Qianzhushuju.[Riqi]<=" + Common.ConvertDateTimeInt(Common.LastDayOfMonth(BeginTime));
            str += " union ALL ";

            str += "select count(*) as totalCnt from Jiaokuanshuju where Xuhao>=-1";
            str += " and Jiaokuanshuju.[Riqi]>=" + Common.ConvertDateTimeInt(Common.FirstDayOfMonth(BeginTime));
            str += " and Jiaokuanshuju.[Riqi]<=" + Common.ConvertDateTimeInt(Common.LastDayOfMonth(BeginTime));
            str += " union ALL ";

            str += "select count(*) as totalCnt from Chaxunshuju where Xuhao>=-1";
            str += " and Chaxunshuju.[Riqi]>=" + Common.ConvertDateTimeInt(Common.FirstDayOfMonth(BeginTime));
            str += " and Chaxunshuju.[Riqi]<=" + Common.ConvertDateTimeInt(Common.LastDayOfMonth(BeginTime));
            str += " union ALL ";

            str += "select count(*) as totalCnt from Yushoulishuju where Xuhao>=-1";
            str += " and Yushoulishuju.[Riqi]>=" + Common.ConvertDateTimeInt(Common.FirstDayOfMonth(BeginTime));
            str += " and Yushoulishuju.[Riqi]<=" + Common.ConvertDateTimeInt(Common.LastDayOfMonth(BeginTime));

            str +=")";
            return str;
        }
        string MakeLineChartQuerySql(object obj)
        {
            string str = "";
            DateTime beginTime = new DateTime(DateTime.Now.Year, 1, 1, 0, 0, 0);
            for (int i = 0; i < 12; ++i)
            {
                str += MakeBenyuebanliyewuCurMonthQuerySql(obj, beginTime);
                if ((i + 1) != 12)
                    str += " union ALL ";
                beginTime = beginTime.AddMonths(1);
            }
            return str;
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
            IntPtr hwnd = new System.Windows.Interop.WindowInteropHelper(Application.Current.MainWindow).Handle;
            tagRECT rcClient = new tagRECT();

            _pieCharIndex       = PieChartServer.AddPieChart(hwnd, ref rcClient, 3);
            _lineCharIndex      = LineChartServer.AddCurveChart(hwnd,  ref rcClient, 13, 12, 12000);
            _histogramCharIndex = HistogramServer.AddHistogramChart(hwnd,  ref rcClient, 12, Color.Red.ToArgb(), Color.Black.ToArgb(), Color.Green.ToArgb());


            PieChartServer.RandomPieValues(_pieCharIndex);
            LineChartServer.RandomCurvePoints(_lineCharIndex);
            HistogramServer.RandomHistogramValues(_histogramCharIndex);

            ResizeShowCharts();

            //QueryLineChartData(null);
        }

        public void ResizeShowCharts()
        {
            tagRECT rect1 = new tagRECT();
            tagRECT rect2 = new tagRECT();
            tagRECT rect3 = new tagRECT();
            tagRECT rect4 = new tagRECT();

            MainWindowViewModel mainModel               = Application.Current.MainWindow.DataContext as MainWindowViewModel;
            Window              mainWnd                 = Application.Current.MainWindow;

            if(mainModel.bShowPage == PageVisibleEnum.PageVisibleEnum_SummaryStat)
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

                PieChartServer.MoveChart(_pieCharIndex, ref rect1, true);
                LineChartServer.MoveChart(_lineCharIndex, ref rect1, true);
                HistogramServer.MoveChart(_histogramCharIndex, ref rect1, true);
                switch (bShowChart)
                {
                    case ShowChartEnum.ShowChartEnum_Pie:
                        PieChartServer.ShowChart(_pieCharIndex, true);
                        LineChartServer.ShowChart(_lineCharIndex, false);
                        HistogramServer.ShowChart(_histogramCharIndex, false);
                        break;
                    case ShowChartEnum.ShowChartEnum_Line:
                        PieChartServer.ShowChart(_pieCharIndex, false);
                        LineChartServer.ShowChart(_lineCharIndex, true);
                        HistogramServer.ShowChart(_histogramCharIndex, false);
                        break;
                    case ShowChartEnum.ShowChartEnum_Histogram:
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
