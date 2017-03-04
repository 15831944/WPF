using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace ManageSystem.Server
{
    class PieChartServer
    {
        [DllImport("PieChart.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "InitializePieModule")]
        public static extern bool InitializePieModule();
        [DllImport("PieChart.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "UninitializePieModule")]
        public static extern bool UninitializePieModule();
        [DllImport("PieChart.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "AddPieChart")]
        public static extern int AddPieChart(IntPtr hWnd,  ref tagRECT rcChart, int nPieCount);
        [DllImport("PieChart.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "RemovePieChart")]
        public static extern bool RemovePieChart(int nChartIndex);
        [DllImport("PieChart.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "RandomPieValues")]
        public static extern bool RandomPieValues(int nChartIndex);
        [DllImport("PieChart.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "SetPieBasicInfo")]
        public static extern bool SetPieBasicInfo(int nChartIndex, int nPieIndex, float fPercent, ref int pieColor, ref int SideColor, ref int startSideColor, ref int endSideColor);
        [DllImport("PieChart.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "MoveChart")]
        public static extern bool MoveChart(int nChartIndex,  ref tagRECT rcWnd, bool bRedraw);
        [DllImport("PieChart.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "RedrawChart")]
        public static extern bool RedrawChart(int nChartIndex,  ref tagRECT rcWnd);
        [DllImport("PieChart.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "ShowChart")]
        public static extern bool ShowChart(int nChartIndex, bool bShow);
        [DllImport("PieChart.dll", CallingConvention=CallingConvention.Winapi, EntryPoint = "ShowPieList")]
        public static extern bool ShowPieList(int nChartIndex, bool bShow);
    }
}
