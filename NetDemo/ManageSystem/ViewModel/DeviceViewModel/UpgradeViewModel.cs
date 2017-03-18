using ManageSystem.Model;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;

namespace ManageSystem.ViewModel.DeviceViewModel
{
    class UpgradeViewModel : NotificationObject
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

        public static ObservableCollection<string> _versionList;
        public ObservableCollection<string> versionList
        {
            get { return _versionList; }
            set
            {
                _versionList = value;
                this.RaisePropertyChanged("versionList");
            }
        }

        public UpgradeViewModel()
        {

            _versionList            = new ObservableCollection<string>();

            versionList.Add("1.0");
            versionList.Add("1.1");
            versionList.Add("1.2");
            versionList.Add("1.3");
        }
    }
}
