using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace ManageSystem.Server
{
    class OccupancyChartServer
    {
        [DllImport("OccupancyChart.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "InitializeOccupancyModule")]
        public static extern bool InitializeOccupancyModule();
        [DllImport("OccupancyChart.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "UninitializeOccupancyModule")]
        public static extern bool UninitializeOccupancyModule();
        [DllImport("OccupancyChart.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "AddOccupancyChart")]
        public static extern int AddOccupancyChart(IntPtr hWnd,   tagRECT rcChart, int nMin, int nMax, int nStep);
        [DllImport("OccupancyChart.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "RemoveOccupancyChart")]
        public static extern bool RemoveOccupancyChart(int nChartIndex);
        [DllImport("OccupancyChart.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "RandomOccupancyValues")]
        public static extern bool RandomOccupancyValues(int nChartIndex);
        [DllImport("OccupancyChart.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "SetOccupancyBasicInfo")]
        public static extern bool SetOccupancyBasicInfo(int nChartIndex, int nOccupancyIndex, int nValue);
        [DllImport("OccupancyChart.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "MoveChart")]
        public static extern bool MoveChart(int nChartIndex,   tagRECT rcWnd, bool bRedraw);
        [DllImport("OccupancyChart.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "RedrawChart")]
        public static extern bool RedrawChart(int nChartIndex);
        [DllImport("OccupancyChart.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "ShowChart")]
        public static extern bool ShowChart(int nChartIndex, bool bShow);
        [DllImport("OccupancyChart.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "ShowOccupancyList")]
        public static extern bool ShowOccupancyList(int nChartIndex, bool bShow);
        [DllImport("OccupancyChart.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "AddData")]
        public static extern bool AddData(int nChartIndex, int nCount);
        [DllImport("OccupancyChart.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "RemoveData")]
        public static extern bool RemoveData(int nChartIndex);
    }
}
