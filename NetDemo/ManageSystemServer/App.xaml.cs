using ManageSystem.Server;
using MiniDumpUtilNameSpace;
using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Windows;

namespace ManageSystemServer
{
    /// <summary>
    /// App.xaml 的交互逻辑
    /// </summary>
    public partial class App : Application
    {
        void CurrentDomain_UnhandledException(object sender, UnhandledExceptionEventArgs e)
        {
            string dtNow = DateTime.Now.ToString("yyyy-MM-dd-HH-mm-ss");
            string file = dtNow + ".dmp";
            MiniDumpUtil.TryWriteMiniDump(System.Windows.Forms.Application.StartupPath + "\\" + file,
                MiniDumpType.MiniDumpWithFullMemory);
        }

        protected override void OnStartup(StartupEventArgs e)
        {
            AppDomain.CurrentDomain.UnhandledException += CurrentDomain_UnhandledException;
            base.OnStartup(e);
        }

        protected override void OnExit(ExitEventArgs e)
        {
            WorkServer.stopServer();

            base.OnExit(e);
        }
    }
}
