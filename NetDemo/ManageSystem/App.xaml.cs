using ManageSystem.Server;
using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Windows;

namespace ManageSystem
{
    /// <summary>
    /// App.xaml 的交互逻辑
    /// </summary>
    public partial class App : Application
    {
        protected override void OnStartup(StartupEventArgs e)
        {
            LineChartServer.InitializeCurveModule();
            HistogramServer.InitializeHistogramModule();
            OccupancyChartServer.InitializeOccupancyModule();
            PieChartServer.InitializePieModule();

            base.OnStartup(e);
        }

        protected override void OnExit(ExitEventArgs e)
        {
            WorkServer.stopClient();
            LineChartServer.UninitializeCurveModule();
            HistogramServer.UninitializeHistogramModule();
            OccupancyChartServer.UninitializeOccupancyModule();
            PieChartServer.UninitializePieModule();

            base.OnExit(e);
        }
    }
}
