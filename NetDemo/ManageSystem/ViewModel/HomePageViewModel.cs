using ManageSystem.Model;
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
    public class HomePageViewModel : NotificationObject
    {
        public enum QueryOperate
        {
            QueryOperate_None,
            QueryOperate_Guzhang,
            QueryOperate_Yewu,
            QueryOperate_Hongkong,
            QueryOperate_Taiwan,
            QueryOperate_SheBeiZaiXian,
            QueryOperate_GuanLiCnt,
            QueryOperate_LineChart,
            QueryOperate_OccupancyChart,
            QueryOperate_PieChart,
            QueryOperate_HistogramChart,
        }

        int                                             _lineCharIndex;
        int                                             _histogramCharIndex;
        int                                             _occupancyCharIndex;
        int                                             _pieCharIndex;

        public QueryTableCallBackDelegate               _querytablecallbackdelegate = null;
        public QueryOperate                             _queryoperate = QueryOperate.QueryOperate_None;

        public DelegateCommand<object>                  InitializedCommand { get; set; }
        public DelegateCommand<object>                  LoadedCommand { get; set; }
        public DelegateCommand<object>                  SizeChangedCommand { get; set; }
        public DelegateCommand<object>                  ShowPieChartCommand { get; set; }
        public DelegateCommand<object>                  ShowLineChartCommand { get; set; }
        public DelegateCommand<object>                  ShowHistogramChartCommand { get; set; }

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

        private string _totalSheBeiGuZhang;
        public string totalSheBeiGuZhang
        {
            get { return _totalSheBeiGuZhang; }
            set
            {
                _totalSheBeiGuZhang = value;
                this.RaisePropertyChanged("totalSheBeiGuZhang");
            }
        }

        private string _totalBanLiYeWu;
        public string totalBanLiYeWu
        {
            get { return _totalBanLiYeWu; }
            set
            {
                _totalBanLiYeWu = value;
                this.RaisePropertyChanged("totalBanLiYeWu");
            }
        }

        private string _totalXiangGangWangLai;
        public string totalXiangGangWangLai
        {
            get { return _totalXiangGangWangLai; }
            set
            {
                _totalXiangGangWangLai = value;
                this.RaisePropertyChanged("totalXiangGangWangLai");
            }
        }

        private string _totalTaiWanWangLai;
        public string totalTaiWanWangLai
        {
            get { return _totalTaiWanWangLai; }
            set
            {
                _totalTaiWanWangLai = value;
                this.RaisePropertyChanged("totalTaiWanWangLai");
            }
        }

        private string _totalSheBeiZaiXian;
        public string totalSheBeiZaiXian
        {
            get { return _totalSheBeiZaiXian; }
            set
            {
                _totalSheBeiZaiXian = value;
                this.RaisePropertyChanged("totalSheBeiZaiXian");
            }
        }

        private string _totalGuanLiCiShu;
        public string totalGuanLiCiShu
        {
            get { return _totalGuanLiCiShu; }
            set
            {
                _totalGuanLiCiShu = value;
                this.RaisePropertyChanged("totalGuanLiCiShu");
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

        private int _regionRightWidth;
        public int regionRightWidth
        {
            get { return _regionRightWidth; }
            set
            {
                _regionRightWidth = value;
                this.RaisePropertyChanged("regionRightWidth");
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

        private string _region1Text;
        public string region1Text
        {
            get { return _region1Text; }
            set
            {
                _region1Text = value;
                this.RaisePropertyChanged("region1Text");
            }
        }

        private string _region2Text;
        public string region2Text
        {
            get { return _region2Text; }
            set
            {
                _region2Text = value;
                this.RaisePropertyChanged("region2Text");
            }
        }

        private string _region3Text;
        public string region3Text
        {
            get { return _region3Text; }
            set
            {
                _region3Text = value;
                this.RaisePropertyChanged("region3Text");
            }
        }
        public HomePageViewModel()
        {
            _querytablecallbackdelegate                 = new QueryTableCallBackDelegate(QueryTableCallBack);
            InitializedCommand                          = new DelegateCommand<object>(new Action<object>(this.Initialized));
            LoadedCommand                               = new DelegateCommand<object>(new Action<object>(this.Loaded));
            SizeChangedCommand                          = new DelegateCommand<object>(new Action<object>(this.SizeChanged));
            ShowPieChartCommand                         = new DelegateCommand<object>(new Action<object>(this.ShowPieChart));
            ShowLineChartCommand                        = new DelegateCommand<object>(new Action<object>(this.ShowLineChart));
            ShowHistogramChartCommand                   = new DelegateCommand<object>(new Action<object>(this.ShowHistogramChart));

            _totalSheBeiGuZhang                         = "1111";
            _totalBanLiYeWu                             = "2222";
            _totalXiangGangWangLai                      = "3333";
            _totalTaiWanWangLai                         = "4444";
            _totalSheBeiZaiXian                         = "5555";
            _totalGuanLiCiShu                           = "6666";

            _topHeight                                  = 60;
            _regionTextHeight                           = 50;
            _regionRightWidth                           = 200;
            _region0Text                                = "已受理业务统计图";
            _region1Text                                = "已受理业务概率图表";
            _region2Text                                = "已受理业务饼图表";
            _region3Text                                = "已受理业务直方图表";

            _lineCharIndex                              = -1;
            _histogramCharIndex                         = -1;
            _pieCharIndex                               = -1;
            _occupancyCharIndex                         = -1;

            _bShowChart                                 = ShowChartEnum.ShowChartEnum_Line;

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
                        if (keyvalue.Length != 2)
                            continue;

                        switch(_queryoperate)
                        {
                            case QueryOperate.QueryOperate_Guzhang:
                                totalSheBeiGuZhang = keyvalue[1];
                                break;
                            case QueryOperate.QueryOperate_Yewu:
                                totalBanLiYeWu = keyvalue[1];
                                break;
                            case QueryOperate.QueryOperate_Hongkong:
                                totalXiangGangWangLai = keyvalue[1];
                                break;
                            case QueryOperate.QueryOperate_Taiwan:
                                totalTaiWanWangLai = keyvalue[1];
                                break;
                            case QueryOperate.QueryOperate_SheBeiZaiXian:
                                totalSheBeiZaiXian = keyvalue[1];
                                break;
                            case QueryOperate.QueryOperate_GuanLiCnt:
                                totalGuanLiCiShu = keyvalue[1];
                                break;
                            case QueryOperate.QueryOperate_LineChart:
                                LineChartServer.SetCurvePointInfo(_lineCharIndex, Convert.ToInt32(keyvalue[0]), Convert.ToInt32(keyvalue[1]));
                                break;
                            case QueryOperate.QueryOperate_OccupancyChart:
                                OccupancyChartServer.SetOccupancyBasicInfo(_occupancyCharIndex, Convert.ToInt32(keyvalue[0]), Convert.ToInt32(keyvalue[1]));
                                break;
                            case QueryOperate.QueryOperate_PieChart:
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
                                break;
                            case QueryOperate.QueryOperate_HistogramChart:
                                {
                                    int rowIndex        = Convert.ToInt32(keyvalue[0]);
                                    int clr1            = Color.BlueViolet.ToArgb() + 100 * rowIndex;
                                    HistogramServer.SetHistogramBasicInfo(_lineCharIndex, Convert.ToInt32(keyvalue[0]), Convert.ToInt32(keyvalue[1]), clr1);
                                }
                                break;
                        }
                    }
                }
            }

            PieChartServer.RedrawChart(_pieCharIndex);
            LineChartServer.RedrawChart(_lineCharIndex);
            HistogramServer.RedrawChart(_histogramCharIndex);
            OccupancyChartServer.RedrawChart(_occupancyCharIndex);

            _queryoperate = QueryOperate.QueryOperate_None;
        }
        public void QueryShebeiguzhang(object obj)
        {
            _queryoperate = QueryOperate.QueryOperate_Guzhang;
            WorkServer.QueryTable(MakeShebeiguzhangCurMonthQuerySql(obj), Marshal.GetFunctionPointerForDelegate(_querytablecallbackdelegate), true);
        }
        string MakeShebeiguzhangCurMonthQuerySql(object obj)
        {
            string str = "select count(*) as totalCnt from shebeiyichangshuju where Xuhao>=-1";
             
            str += " and shebeiyichangshuju.[Riqi]>=" + Common.ConvertDateTimeInt(Common.FirstDayOfMonth(new DateTime(DateTime.Now.Year, DateTime.Now.Month, 1,  0, 0, 0)));
            str += " and shebeiyichangshuju.[Riqi]<=" + Common.ConvertDateTimeInt(Common.LastDayOfMonth(new DateTime(DateTime.Now.Year, DateTime.Now.Month, 1,  0, 0, 0)));

            return str;
        }
        public void QueryBenyuebanliyewu(object obj)
        {
            _queryoperate = QueryOperate.QueryOperate_Yewu;
            WorkServer.QueryTable(MakeBenyuebanliyewuCurMonthQuerySql(obj, new DateTime(DateTime.Now.Year, DateTime.Now.Month, 1,  0, 0, 0)), Marshal.GetFunctionPointerForDelegate(_querytablecallbackdelegate), true);
        }
        string MakeBenyuebanliyewuCurMonthQuerySql(object obj, DateTime BeginTime )
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
        public void QueryHongKongWangLai(object obj)
        {
            _queryoperate = QueryOperate.QueryOperate_Hongkong;
            WorkServer.QueryTable(MakeHongKongWangLaiCurMonthQuerySql(obj), Marshal.GetFunctionPointerForDelegate(_querytablecallbackdelegate), true);
        }
        string MakeHongKongWangLaiCurMonthQuerySql(object obj)
        {
            string str = "select count(*) as totalCnt from Qianzhushuju where Xuhao>=-1";

            str += " and Qianzhushuju.[Riqi]>=" + Common.ConvertDateTimeInt(Common.FistDayOfYear(new DateTime(DateTime.Now.Year, DateTime.Now.Month, 1,  0, 0, 0)));
            str += " and Qianzhushuju.[Riqi]<=" + Common.ConvertDateTimeInt(Common.LastDayOfYear(new DateTime(DateTime.Now.Year, DateTime.Now.Month, 1,  0, 0, 0)));

            foreach (string typeStr in MainWindowViewModel._businesstype)
            {
                if (typeStr.Contains("香港"))
                {
                    foreach (KeyValuePair<int, string> kvp0 in MainWindowViewModel._yingshelList)
                    {
                        if (kvp0.Value == typeStr)
                        {
                            str += " and Qianzhushuju.[Yewuleixing]=" + kvp0.Key.ToString();
                            break;
                        }
                    }
                }
            }

            return str;
        }
        public void QueryTaiWanWangLai(object obj)
        {
            _queryoperate = QueryOperate.QueryOperate_Taiwan;
            WorkServer.QueryTable(MakeTaiWanWangLaiCurMonthQuerySql(obj), Marshal.GetFunctionPointerForDelegate(_querytablecallbackdelegate), true);
        }
        string MakeTaiWanWangLaiCurMonthQuerySql(object obj)
        {
            string str = "select count(*) as totalCnt from Qianzhushuju where Xuhao>=-1";

            str += " and Qianzhushuju.[Riqi]>=" + Common.ConvertDateTimeInt(Common.FistDayOfYear(new DateTime(DateTime.Now.Year, DateTime.Now.Month, 1,  0, 0, 0)));
            str += " and Qianzhushuju.[Riqi]<=" + Common.ConvertDateTimeInt(Common.LastDayOfYear(new DateTime(DateTime.Now.Year, DateTime.Now.Month, 1,  0, 0, 0)));

            foreach (string typeStr in MainWindowViewModel._businesstype)
            {
                if (typeStr.Contains("台湾"))
                {
                    foreach (KeyValuePair<int, string> kvp0 in MainWindowViewModel._yingshelList)
                    {
                        if (kvp0.Value == typeStr)
                        {
                            str += " and Qianzhushuju.[Yewuleixing]=" + kvp0.Key.ToString();
                            break;
                        }
                    }
                }
            }
            return str;
        }
        public void QuerySheBeiZaiXian(object obj)
        {
            _queryoperate = QueryOperate.QueryOperate_SheBeiZaiXian;
            WorkServer.queryOnlieDevCnt(Marshal.GetFunctionPointerForDelegate(_querytablecallbackdelegate), true);
        }
        string MakeSheBeiZaiXianCurQuerySql(object obj)
        {
            string str = "select count(*) as totalCnt from Shebeizhuangtai where Xuhao>=-1";

            str += " and Shebeizhuangtai.[Shifouzaixian]=" + "1";
            return str;
        }
        public void QueryGuanLiCiShu(object obj)
        {
            _queryoperate = QueryOperate.QueryOperate_GuanLiCnt;
            WorkServer.QueryTable(MakeGuanLiCiShuQuerySql(obj), Marshal.GetFunctionPointerForDelegate(_querytablecallbackdelegate), true);
        }
        string MakeGuanLiCiShuQuerySql(object obj)
        {
            string str = "select count(*) as totalCnt from Guanliyuancaozuojilu where Xuhao>=-1";
            return str;
        }
        public void QueryLineChartData(object obj)
        {
            _queryoperate = QueryOperate.QueryOperate_LineChart;
            WorkServer.QueryTable(MakeLineChartQuerySql(obj), Marshal.GetFunctionPointerForDelegate(_querytablecallbackdelegate), true);
        }
        string MakeLineChartQuerySql(object obj)
        {
            string str = "select ";
            DateTime beginTime = new DateTime(DateTime.Now.Year, 1, 1,  0, 0, 0);
            string strCondition = "";
            for (int i = 0; i < 12; ++i)
            {
                strCondition += " ( ";
                strCondition += MakeBenyuebanliyewuCurMonthQuerySql(obj, beginTime);
                strCondition += " ) as " +  "'" + i + "'";

                if (i != 11)
                {
                    strCondition    += ",";
                }
                beginTime = beginTime.AddMonths(1);
            }

            return str + strCondition;
        }
        public void QueryOccupancyChartData(object obj)
        {
            _queryoperate = QueryOperate.QueryOperate_OccupancyChart;
            WorkServer.QueryTable(MakeOccupancyChartQuerySql(obj), Marshal.GetFunctionPointerForDelegate(_querytablecallbackdelegate), true);
        }
        string MakeOccupancyChartQuerySql(object obj)
        {
            string str = "select ";
            string strCondition = "";
            for (int i = 0; i < 12; ++i)
            {
                strCondition += " ( ";
                strCondition += "select count(*) from zhiqianshuju where  Xuhao>=-1";
                strCondition += " and zhiqianshuju.[Riqi]%(3600*12) >=(3600*" + i + ")";
                strCondition += " and zhiqianshuju.[Riqi]%(3600*12) < (3600*" + (i + 1) + ")";
                strCondition += " ) as " +  "'" + i + "'";

                if (i != 11)
                {
                    strCondition    += ",";
                }
            }

            return str + strCondition;
        }
        public void QueryPieChartData(object obj)
        {
            _queryoperate = QueryOperate.QueryOperate_PieChart;
            WorkServer.QueryTable(MakePieChartQuerySql(obj), Marshal.GetFunctionPointerForDelegate(_querytablecallbackdelegate), true);
        }
        string MakePieChartQuerySql(object obj)
        {
            string str = "select ";
            string strCondition = " (select ";
            List<string> strList = new List<string>();
            for (int i = 0; i < MainWindowViewModel._businesstype.Count; ++i)
            {
                string typestr = MainWindowViewModel._businesstype[i];

                foreach (KeyValuePair<int, string> kvp0 in MainWindowViewModel._yingshelList)
                {
                    if (kvp0.Value == typestr)
                    {
                        strList.Add("sum(" + "a" + i + ")");
                        strCondition += " ( ";
                        strCondition += "select count(*) as totalCnt from Qianzhushuju where Xuhao>=-1";
                        strCondition += " and Qianzhushuju.[Yewuleixing]=" + kvp0.Key;
                        strCondition += " ) as " +  "a" + i;

                        if ((i + 1) != MainWindowViewModel._businesstype.Count)
                        {
                            strCondition    += ",";
                        }
                        break;
                    }
                }
            }

            string strTotal = "(";
            for(int i = 0; i < strList.Count(); ++i)
            {
                strTotal += strList[i];
                if((i +1) != strList.Count())
                    strTotal += "+";
            }
            strTotal += ")";

            for (int i = 0; i < strList.Count(); ++i)
            {
                str += strList[i] + "*100.0/" + strTotal;
                str += " as " +  "'" + i +  "' ";
                if ((i +1) != strList.Count())
                    str += ",";
            }

            str             += " from ";
            strCondition    += " ) ";

            return str + strCondition;
        }
        public void QueryHistogramChartData(object obj)
        {
            _queryoperate = QueryOperate.QueryOperate_HistogramChart;
            WorkServer.QueryTable(MakeHistogramChartQuerySql(obj), Marshal.GetFunctionPointerForDelegate(_querytablecallbackdelegate), true);
        }
        string MakeHistogramChartQuerySql(object obj)
        {
            string str = "select ";
            DateTime beginTime = new DateTime(DateTime.Now.Year, 1, 1, 0, 0, 0);
            string strCondition = "";
            for (int i = 0; i < 12; ++i)
            {
                strCondition += " ( ";
                strCondition += "select count(*) as totalCnt from Zhiqianshuju where Xuhao>=-1";
                strCondition += " and Zhiqianshuju.[Riqi]>=" + Common.ConvertDateTimeInt(Common.FirstDayOfMonth(beginTime));
                strCondition += " and Zhiqianshuju.[Riqi]<=" + Common.ConvertDateTimeInt(Common.LastDayOfMonth(beginTime));
                strCondition += " ) as " +  "'" + i + "'";
                if (i != 11)
                {
                    strCondition    += ",";
                }
                beginTime = beginTime.AddMonths(1);
            }

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

        public void Initialized(object obj)
        {
            return;
            //IntPtr hwnd = new System.Windows.Interop.WindowInteropHelper(Application.Current.MainWindow).Handle;
            //tagRECT rcClient = new tagRECT();

            //_pieCharIndex       = PieChartServer.AddPieChart(hwnd,  rcClient, 3);
            //_lineCharIndex      = LineChartServer.AddCurveChart(hwnd,   rcClient, 13, 12, 12000);
            //_histogramCharIndex = HistogramServer.AddHistogramChart(hwnd,  rcClient, 12, Color.Red.ToArgb(), Color.Black.ToArgb(), Color.Green.ToArgb());
            //_occupancyCharIndex = OccupancyChartServer.AddOccupancyChart(hwnd,  rcClient);


            //PieChartServer.RandomPieValues(_pieCharIndex);
            //LineChartServer.RandomCurvePoints(_lineCharIndex);
            //HistogramServer.RandomHistogramValues(_histogramCharIndex);
            //OccupancyChartServer.RandomOccupancyValues(_occupancyCharIndex);


            //OccupancyChartServer.ShowOccupancyList(_occupancyCharIndex, false);
            //PieChartServer.ShowPieList(_pieCharIndex, false);
            //HistogramServer.ShowHistogramList(_histogramCharIndex, false);
            //ResizeShowCharts();

            ////Thread tProcess = new Thread(() =>
            ////{   ////循环查询过期IP并删除之
            ////    ManualResetEventSlim    _event      = _QueueData.GetQueueEvent();
            ////    while (!_bExit)
            ////    {
            ////        _event.Wait();
            ////        ProcessData();
            ////    }
            ////    Debug.WriteLine(GetType() + ":" + "exit");
            ////}
            ////);
            ////tProcess.IsBackground = true;
            ////tProcess.Start();
            //QueryShebeiguzhang(null);
            //QueryBenyuebanliyewu(null);
            //QueryHongKongWangLai(null);
            //QueryTaiWanWangLai(null);
            //QuerySheBeiZaiXian(null);
            //QueryGuanLiCiShu(null);
            //QueryLineChartData(null);
            //QueryPieChartData(null);
            //QueryHistogramChartData(null);
        }

        public void DoLogon()
        {
            IntPtr hwnd = new System.Windows.Interop.WindowInteropHelper(Application.Current.MainWindow).Handle;
            tagRECT rcClient = new tagRECT();

            _pieCharIndex       = PieChartServer.AddPieChart(hwnd, rcClient);
            _lineCharIndex      = LineChartServer.AddCurveChart(hwnd, rcClient);
            _histogramCharIndex = HistogramServer.AddHistogramChart(hwnd, rcClient, 0, 3000, 300, Color.Red.ToArgb(), Color.Black.ToArgb(), Color.Green.ToArgb());
            _occupancyCharIndex = OccupancyChartServer.AddOccupancyChart(hwnd, rcClient, 0, 3000, 300);


            PieChartServer.AddData(_pieCharIndex, MainWindowViewModel._businesstype.Count - 1);
            LineChartServer.AddData(_lineCharIndex, 13, 12, 1200);
            HistogramServer.AddData(_histogramCharIndex, 12);
            OccupancyChartServer.AddData(_occupancyCharIndex, 12);

            PieChartServer.ShowPieList(_pieCharIndex, false);
            HistogramServer.ShowHistogramList(_histogramCharIndex, false);
            OccupancyChartServer.ShowOccupancyList(_occupancyCharIndex, false);
            ResizeShowCharts();

            Thread tQuery = new Thread(() =>
            {   ////循环查询
                QueryShebeiguzhang(null);
                QueryBenyuebanliyewu(null);
                QueryHongKongWangLai(null);
                QueryTaiWanWangLai(null);
                QuerySheBeiZaiXian(null);
                QueryGuanLiCiShu(null);
                QueryLineChartData(null);
                QueryOccupancyChartData(null);
                QueryPieChartData(null);
                QueryHistogramChartData(null);
            }
            );
            tQuery.IsBackground = true;
            tQuery.Start();
        }

        public void Loaded(object obj)
        {
        }

        private void SizeChanged(object obj)
        {
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

            if(mainModel.bShowPage == PageVisibleEnum.PageVisibleEnum_Home)
            {
                double totalTitleHeight                     = mainModel.titleheight + topHeight;
                System.Windows.Point  ptOriginalDlg         = new System.Windows.Point(0, 0);
                System.Windows.Point  ptTopLeftDlg1         = new System.Windows.Point(mainModel.leftWidth, totalTitleHeight + regionTextHeight);
                System.Windows.Point  ptBotRightDlg1        = new System.Windows.Point(mainWnd.ActualWidth - regionRightWidth, mainWnd.ActualHeight);

                System.Windows.Point  ptTopLeftDlg2         = new System.Windows.Point(mainWnd.ActualWidth - regionRightWidth, totalTitleHeight + regionTextHeight);
                System.Windows.Point  ptBotRightDlg2        = new System.Windows.Point(mainWnd.ActualWidth, totalTitleHeight + (mainWnd.ActualHeight - totalTitleHeight)/3);

                System.Windows.Point  ptTopLeftDlg3         = new System.Windows.Point(mainWnd.ActualWidth - regionRightWidth, totalTitleHeight + (mainWnd.ActualHeight - totalTitleHeight)/3 + regionTextHeight);
                System.Windows.Point  ptBotRightDlg3        = new System.Windows.Point(mainWnd.ActualWidth, (mainWnd.ActualHeight - mainModel.titleheight - topHeight)*2/3 + mainModel.titleheight + topHeight);

                System.Windows.Point  ptTopLeftDlg4         = new System.Windows.Point(mainWnd.ActualWidth - regionRightWidth, totalTitleHeight + (mainWnd.ActualHeight - totalTitleHeight)*2/3 + regionTextHeight);
                System.Windows.Point  ptBotRightDlg4        = new System.Windows.Point(mainWnd.ActualWidth, mainWnd.ActualHeight);

                ptOriginalDlg                               = mainWnd.PointToScreen(ptOriginalDlg);
                ptTopLeftDlg1                               = mainWnd.PointToScreen(ptTopLeftDlg1);
                ptBotRightDlg1                              = mainWnd.PointToScreen(ptBotRightDlg1);
                ptTopLeftDlg2                               = mainWnd.PointToScreen(ptTopLeftDlg2);
                ptBotRightDlg2                              = mainWnd.PointToScreen(ptBotRightDlg2);
                ptTopLeftDlg3                               = mainWnd.PointToScreen(ptTopLeftDlg3);
                ptBotRightDlg3                              = mainWnd.PointToScreen(ptBotRightDlg3);
                ptTopLeftDlg4                               = mainWnd.PointToScreen(ptTopLeftDlg4);
                ptBotRightDlg4                              = mainWnd.PointToScreen(ptBotRightDlg4);

                rect1.left                                  = Convert.ToInt32(ptTopLeftDlg1.X - ptOriginalDlg.X);
                rect1.top                                   = Convert.ToInt32(ptTopLeftDlg1.Y - ptOriginalDlg.Y);
                rect1.right                                 = Convert.ToInt32(ptBotRightDlg1.X - ptOriginalDlg.X);
                rect1.bottom                                = Convert.ToInt32(ptBotRightDlg1.Y - ptOriginalDlg.Y);
                rect2.left                                  = Convert.ToInt32(ptTopLeftDlg2.X - ptOriginalDlg.X);
                rect2.top                                   = Convert.ToInt32(ptTopLeftDlg2.Y - ptOriginalDlg.Y);
                rect2.right                                 = Convert.ToInt32(ptBotRightDlg2.X - ptOriginalDlg.X);
                rect2.bottom                                = Convert.ToInt32(ptBotRightDlg2.Y - ptOriginalDlg.Y);
                rect3.left                                  = Convert.ToInt32(ptTopLeftDlg3.X - ptOriginalDlg.X);
                rect3.top                                   = Convert.ToInt32(ptTopLeftDlg3.Y - ptOriginalDlg.Y);
                rect3.right                                 = Convert.ToInt32(ptBotRightDlg3.X - ptOriginalDlg.X);
                rect3.bottom                                = Convert.ToInt32(ptBotRightDlg3.Y - ptOriginalDlg.Y);
                rect4.left                                  = Convert.ToInt32(ptTopLeftDlg4.X - ptOriginalDlg.X);
                rect4.top                                   = Convert.ToInt32(ptTopLeftDlg4.Y - ptOriginalDlg.Y);
                rect4.right                                 = Convert.ToInt32(ptBotRightDlg4.X - ptOriginalDlg.X);
                rect4.bottom                                = Convert.ToInt32(ptBotRightDlg4.Y - ptOriginalDlg.Y);

                OccupancyChartServer.MoveChart(_occupancyCharIndex,  rect2, true);
                switch (bShowChart)
                {
                    case ShowChartEnum.ShowChartEnum_Pie:
                        region0Text                                = "已受理业务饼图表";
                        region2Text                                = "已受理业务统计图";
                        region3Text                                = "已受理业务直方图表";
                        PieChartServer.MoveChart(_pieCharIndex,  rect1, true);
                        LineChartServer.MoveChart(_lineCharIndex,  rect3, true);
                        HistogramServer.MoveChart(_histogramCharIndex,  rect4, true);
                        break;
                    case ShowChartEnum.ShowChartEnum_Line:
                        region0Text                                = "已受理业务统计图";
                        region2Text                                = "已受理业务饼图表";
                        region3Text                                = "已受理业务直方图表";
                        LineChartServer.MoveChart(_lineCharIndex,  rect1, true);
                        PieChartServer.MoveChart(_pieCharIndex,  rect3, true);
                        HistogramServer.MoveChart(_histogramCharIndex,  rect4, true);
                        break;
                    case ShowChartEnum.ShowChartEnum_Histogram:
                        region0Text                                = "已受理业务直方图表";
                        region2Text                                = "已受理业务统计图";
                        region3Text                                = "已受理业务饼图表";
                        HistogramServer.MoveChart(_histogramCharIndex,  rect1, true);
                        LineChartServer.MoveChart(_lineCharIndex,  rect3, true);
                        PieChartServer.MoveChart(_pieCharIndex,  rect4, true);
                        break;
                }

                OccupancyChartServer.ShowChart(_occupancyCharIndex, true);
                PieChartServer.ShowChart(_pieCharIndex, true);
                LineChartServer.ShowChart(_lineCharIndex, true);
                HistogramServer.ShowChart(_histogramCharIndex, true);
            }
            else
            {
                OccupancyChartServer.ShowChart(_occupancyCharIndex, false);
                PieChartServer.ShowChart(_pieCharIndex, false);
                LineChartServer.ShowChart(_lineCharIndex, false);
                HistogramServer.ShowChart(_histogramCharIndex, false);
            }
        }
    }
}
