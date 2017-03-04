﻿using ManageSystem.Model;
using ManageSystem.Server;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Windows;


namespace ManageSystem.ViewModel
{
    class SignStatViewModel : NotificationObject
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

        }


        private void QueryTableCallBack(string resultStr)
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
                        if (keyvalue.Length != 2)
                            continue;

                        LineChartServer.SetCurvePointInfo(_lineCharIndex, Convert.ToInt32(keyvalue[0]), Convert.ToInt32(keyvalue[1]));
                        {
                            int rowIndex        = Convert.ToInt32(keyvalue[0]);
                            int clr0_1          = Color.Azure.ToArgb() + 100 * (rowIndex + 0);
                            int clr0_2          = Color.Azure.ToArgb() + 100 * (rowIndex + 1);
                            int clr0_3          = Color.Azure.ToArgb() + 100 * (rowIndex + 2);
                            int clr0_4          = Color.Azure.ToArgb() + 100 * (rowIndex + 3);

                            PieChartServer.SetPieBasicInfo(_pieCharIndex, Convert.ToInt32(keyvalue[0]), (float)(Convert.ToDouble(keyvalue[1])),
                                ref clr0_1,
                                ref clr0_2,
                                ref clr0_3,
                                ref clr0_4
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

        }

        private void Statistics(object obj)
        {
            WorkServer.QueryTable(MakeStatisticsQuerySql(obj), Marshal.GetFunctionPointerForDelegate(_querytablecallbackdelegate));
        }

        string MakeStatisticsQuerySql(object obj)
        {
            DateTime realstartTime  = DateTime.Parse(startTime);
            DateTime realendTime   = DateTime.Parse(endTime);

            string str = "select ";
            string strCondition = "";
            int index = 0;
            if (dataTypeText.Contains("天"))
            {
                do
                {
                    strCondition += " ( ";
                    strCondition += "select count(*) as totalCnt from Zhiqianshuju where Xuhao>=-1";
                    strCondition += " and Zhiqianshuju.[Riqi]>=" + Common.ConvertDateTimeInt(realstartTime);

                    realstartTime = realstartTime.AddDays(1);
                    if (realstartTime < realendTime)
                    {
                        str             += " and Zhiqianshuju.[Riqi]<" + Common.ConvertDateTimeInt(realstartTime);
                    }
                    else
                    {
                        str             += " and Zhiqianshuju.[Riqi]<" + Common.ConvertDateTimeInt(realendTime);
                    }
                    strCondition += " ) as " +  "'" + index + "'";

                    index++;
                    if (realstartTime < realendTime && index < 12)
                        strCondition    += ",";
                }while(realstartTime < realendTime && index < 12);
            }
            else if (dataTypeText.Contains("周"))
            {
                do
                {
                    strCondition += " ( ";
                    strCondition += "select count(*) as totalCnt from Zhiqianshuju where Xuhao>=-1";
                    strCondition += " and Zhiqianshuju.[Riqi]>=" + Common.ConvertDateTimeInt(realstartTime);

                    realstartTime = realstartTime.AddDays(7);
                    if (realstartTime < realendTime)
                    {
                        str             += " and Zhiqianshuju.[Riqi]<" + Common.ConvertDateTimeInt(realstartTime);
                    }
                    else
                    {
                        str             += " and Zhiqianshuju.[Riqi]<" + Common.ConvertDateTimeInt(realendTime);
                    }
                    strCondition += " ) as " +  "'" + index + "'";

                    index++;
                    if (realstartTime < realendTime && index < 12)
                        strCondition    += ",";
                } while (realstartTime < realendTime);
            }
            else if (dataTypeText.Contains("月"))
            {
                do
                {
                    strCondition += " ( ";
                    strCondition += "select count(*) as totalCnt from Zhiqianshuju where Xuhao>=-1";
                    strCondition += " and Zhiqianshuju.[Riqi]>=" + Common.ConvertDateTimeInt(realstartTime);

                    realstartTime = realstartTime.AddMonths(1);
                    if (realstartTime < realendTime)
                    {
                        str             += " and Zhiqianshuju.[Riqi]<" + Common.ConvertDateTimeInt(realstartTime);
                    }
                    else
                    {
                        str             += " and Zhiqianshuju.[Riqi]<" + Common.ConvertDateTimeInt(realendTime);
                    }
                    strCondition += " ) as " +  "'" + index + "'";

                    index++;
                    if (realstartTime < realendTime && index < 12)
                        strCondition    += ",";
                } while (realstartTime < realendTime);
            }
            else if (dataTypeText.Contains("年"))
            {
                do
                {
                    strCondition += " ( ";
                    strCondition += "select count(*) as totalCnt from Zhiqianshuju where Xuhao>=-1";
                    strCondition += " and Zhiqianshuju.[Riqi]>=" + Common.ConvertDateTimeInt(realstartTime);

                    realstartTime = realstartTime.AddYears(1);
                    if (realstartTime < realendTime)
                    {
                        str             += " and Zhiqianshuju.[Riqi]<" + Common.ConvertDateTimeInt(realstartTime);
                    }
                    else
                    {
                        str             += " and Zhiqianshuju.[Riqi]<" + Common.ConvertDateTimeInt(realendTime);
                    }
                    strCondition += " ) as " +  "'" + index + "'";

                    index++;
                    if (realstartTime < realendTime && index < 12)
                        strCondition    += ",";
                } while (realstartTime < realendTime);
            }

            Application.Current.Dispatcher.Invoke(
                new Action(()=>
             {
                 IntPtr hwnd = new System.Windows.Interop.WindowInteropHelper(Application.Current.MainWindow).Handle;
                 tagRECT rcClient = new tagRECT();

                PieChartServer.RemovePieChart(_pieCharIndex);
                LineChartServer.RemoveCurveChart(_lineCharIndex);
                HistogramServer.RemoveHistogramChart(_histogramCharIndex);

                _pieCharIndex       = PieChartServer.AddPieChart(hwnd, ref rcClient, index);
                _lineCharIndex      = LineChartServer.AddCurveChart(hwnd, ref rcClient, 13, index, 12000);
                _histogramCharIndex = HistogramServer.AddHistogramChart(hwnd, ref rcClient, index, Color.Red.ToArgb(), Color.Black.ToArgb(), Color.Green.ToArgb());


                for (int i = 0; i < index; ++i)
                {
                    PieChartServer.SetPieBasicInfo(_pieCharIndex, i, i, ref i, ref i, ref i, ref i);
                    LineChartServer.SetCurvePointInfo(_lineCharIndex, i, 0);
                    HistogramServer.SetHistogramBasicInfo(_histogramCharIndex, i, 0, 0);
                }
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
            IntPtr hwnd = new System.Windows.Interop.WindowInteropHelper(Application.Current.MainWindow).Handle;
            tagRECT rcClient = new tagRECT();

            _pieCharIndex       = PieChartServer.AddPieChart(hwnd, ref rcClient, 12);
            _lineCharIndex      = LineChartServer.AddCurveChart(hwnd,  ref rcClient, 13, 12, 12000);
            _histogramCharIndex = HistogramServer.AddHistogramChart(hwnd,  ref rcClient, 12, Color.Red.ToArgb(), Color.Black.ToArgb(), Color.Green.ToArgb());


            for(int i = 0; i < 12; ++i)
            {
                PieChartServer.SetPieBasicInfo(_pieCharIndex, i, i, ref i,ref i,ref i,ref i);
                LineChartServer.SetCurvePointInfo(_lineCharIndex, i, 0);
                //HistogramServer.SetHistogramBasicInfo(_histogramCharIndex, i, 0, Color.Black.ToArgb());
            }
            HistogramServer.RandomHistogramValues(_histogramCharIndex);

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
