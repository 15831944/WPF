using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace ManageSystem.Server
{
    class HistogramServer
    {

        [DllImport("Histogram.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "InitializeHistogramModule")]
        public static extern bool InitializeHistogramModule();
        [DllImport("Histogram.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "UninitializeHistogramModule")]
        public static extern bool UninitializeHistogramModule();
        [DllImport("Histogram.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "AddHistogramChart")]
        public static extern int AddHistogramChart(IntPtr hWnd,  ref tagRECT rcChart, int nHistogramCount, int clLeftSide, int clBottom, int clBackground);
        [DllImport("Histogram.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "RemoveHistogramChart")]
        public static extern bool RemoveHistogramChart(int nChartIndex);
        [DllImport("Histogram.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "RandomHistogramValues")]
        public static extern bool RandomHistogramValues(int nChartIndex);
        [DllImport("Histogram.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "SetHistogramBasicInfo")]
        public static extern bool SetHistogramBasicInfo(int nChartIndex, int nHistogramIndex, int nValue, int clCubic);
        [DllImport("Histogram.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "MoveChart")]
        public static extern bool MoveChart(int nChartIndex,  ref tagRECT rcWnd, bool bRedraw);
        [DllImport("Histogram.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "RedrawChart")]
        public static extern bool RedrawChart(int nChartIndex,  ref tagRECT rcWnd);
        [DllImport("Histogram.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "ShowChart")]
        public static extern bool ShowChart(int nChartIndex, bool bShow);
        [DllImport("Histogram.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "ShowHistogramList")]
        public static extern bool ShowHistogramList(int nChartIndex, bool bShow);
    }
}
