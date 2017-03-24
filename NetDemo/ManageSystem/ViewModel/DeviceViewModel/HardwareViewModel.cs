using ManageSystem.Model;
using ManageSystem.Server;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ManageSystem.ViewModel.DeviceViewModel
{
    public class HardwareViewModel : NotificationObject
    {

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

        public HardwareViewModel()
        {

        }

    }
}
