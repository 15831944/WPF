using ManageSystem.Model;
using ManageSystem.Server;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Runtime.InteropServices;
using System.Text;

namespace ManageSystem.ViewModel.DeviceViewModel
{
    class NetViewModel : NotificationObject
    {
        public QueryTableCallBackDelegate   _querytablecallbackdelegate = null;

        public DelegateCommand<object> TestCommand { get; set; }

        private SHEBEIGUANLIModel _customInfo;
        public SHEBEIGUANLIModel customInfo
        {
            get
            {
                return _customInfo;
            }
            set
            {
                _customInfo = value;
                this.RaisePropertyChanged("customInfo");
            }
        }

        private string _statusText;
        public string statusText
        {
            get
            {
                return _statusText;
            }
            set
            {
                _statusText = value;
                this.RaisePropertyChanged("statusText");
            }
        }

        public NetViewModel()
        {
            _querytablecallbackdelegate         = new QueryTableCallBackDelegate(QueryTableCallBack);

            TestCommand                         = new DelegateCommand<object>(Test);

            _statusText                         = "";
            _customInfo                         = new SHEBEIGUANLIModel();
        }

        public void QueryTableCallBack(string resultStr, string errorStr)
        {
            
            if(errorStr.Length == 0)
            {
                string[] rows = resultStr.Split(';');
                foreach (string row in rows)
                {
                    if (row.Length > 0)
                    {
                        string[] cells = row.Split(',');
                        foreach (string cell in cells)
                        {
                            string[] keyvalue = cell.Split(':');
                            if (keyvalue.Length != 2)
                                continue;

                            if(keyvalue[0] == "speed")
                            {
                                double speed = Convert.ToDouble(keyvalue[1]);
                                statusText = "当前网速：";
                                if(speed > 1024 * 1024)
                                {
                                    speed /= 1024*1024;
                                    statusText += speed + " MByte/s";
                                }
                                else if(speed > 1024)
                                {
                                    speed /= 1024;
                                    statusText += speed + " KByte/s";
                                }
                                else
                                {
                                    statusText += speed + " Byte/s";
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                statusText = errorStr;
            }
        }

        private void Test(object obj)
        {
            IPAddress addr;
            if(IPAddress.TryParse(customInfo.IP, out addr))
                WorkServer.queryDevSpeed(customInfo.IP, Marshal.GetFunctionPointerForDelegate(_querytablecallbackdelegate), true);
        }


    }
}
