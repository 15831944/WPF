
using ManageSystem.Server;
using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.Text;
using System.Windows.Threading;

namespace ManageSystemServer.ViewModel
{
    class MainWindowViewModel : NotificationObject
    {
        public DelegateCommand<object>          StartServerCommand { get; set; }
        public DelegateCommand<object>          StopServerCommand { get; set; }
        public DelegateCommand<object>          ExitCommand { get; set; }

        private bool _bOnline;
        public bool bOnline
        {
            get { return _bOnline; }
            set
            {
                _bOnline = value;
                this.RaisePropertyChanged("bOnline");
            }
        }

        private string _curConnections;
        public string curConnections
        {
            get { return _curConnections; }
            set
            {
                _curConnections = value;
                this.RaisePropertyChanged("curConnections");
            }
        }


        public MainWindowViewModel()
        { 
            StartServerCommand      = new DelegateCommand<object>(this.StartServer);
            StopServerCommand       = new DelegateCommand<object>(this.StopServer);
            ExitCommand             = new DelegateCommand<object>(new Action<object>(this.ExitWnd));
            curConnections          = "未检测";

            var _timer              = new DispatcherTimer();
            _timer.Interval         = new TimeSpan(0, 0, 5);   //间隔1秒
            _timer.Tick             += new EventHandler(Timer_Tick);
            _timer.Start();

        }
        private void Timer_Tick(object sender, EventArgs e)
        {
            bOnline         = WorkServer.isServerStoped() == false;
            curConnections  = WorkServer.curServerConnections() + "个";
        }

        private void StopServer(object obj)
        {
            WorkServer.stopServer();
        }

        private void StartServer(object obj)
        {
            Configuration config                 = ConfigurationManager.OpenExeConfiguration("ManageSystem.exe");
            string  ip      = "";
            int     port    = 0;
            foreach (KeyValueConfigurationElement kv0 in config.AppSettings.Settings)
            {    //检索当前选中的分辨率
                if (kv0.Key == "ServerIP")
                {
                    ip = kv0.Value;
                }
                else if (kv0.Key  == "ServerPort")
                {
                    port = Convert.ToInt32(kv0.Value);
                }
            }

            WorkServer.startServer(ip, port);
        }

        public void ExitWnd(object obj)
        {
            try
            {
                App.Current.Shutdown();
            }
            catch (Exception ex)
            {
            }
        }
    }
}
