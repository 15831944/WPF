using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace ManageSystem.Server
{
    class LineChartServer
    {
        [DllImport("LineChart.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "InitializeCurveModule")]
        public static extern bool InitializeCurveModule();
        [DllImport("LineChart.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "UninitializeCurveModule")]
        public static extern bool UninitializeCurveModule();

        [DllImport("LineChart.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "AddCurveChart")]
        public static extern int AddCurveChart(IntPtr hWnd,  tagRECT rcChart);
        [DllImport("LineChart.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "RemoveCurveChart")]
        public static extern bool RemoveCurveChart(int nChartIndex);

        [DllImport("LineChart.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "RandomCurvePoints")]
        public static extern bool RandomCurvePoints(int nChartIndex);
        [DllImport("LineChart.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "SetCurvePointInfo")]
        public static extern bool SetCurvePointInfo(int nChartIndex, int nPointIndex, float fValueY);
        [DllImport("LineChart.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "DrawCurveChart")]
        public static extern bool DrawCurveChart(int nChartIndex,  tagRECT rcWnd, int nMouseX, int nMouseY);

        [DllImport("LineChart.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "MoveChart")]
        public static extern bool MoveChart(int nChartIndex,  tagRECT rcWnd, bool bRedraw);
        [DllImport("LineChart.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "RedrawChart")]
        public static extern bool RedrawChart(int nChartIndex);
        [DllImport("LineChart.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "ShowChart")]
        public static extern bool _ShowChart(int nChartIndex, bool bShow);

        [DllImport("LineChart.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "AddData")]
        public static extern bool AddData(int nChartIndex, int nHLines, int nVLines, int nYMax);
        [DllImport("LineChart.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "RemoveData")]
        public static extern bool RemoveData(int nChartIndex);

        public static bool ShowChart(int nChartIndex, bool bShow)
        {
            return _ShowChart(nChartIndex, bShow);    
        }
    }
}
