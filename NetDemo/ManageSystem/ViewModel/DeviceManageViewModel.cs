using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using ManageSystem.ViewModel.DeviceViewModel;

namespace ManageSystem.ViewModel
{
    enum DeviceVisibleEnum
    {
        DeviceVisibleEnum_Device,
        DeviceVisibleEnum_User,
        DeviceVisibleEnum_Net,
        DeviceVisibleEnum_Upgrade,
        DeviceVisibleEnum_Abnormal,
    }

    class DeviceManageViewModel : NotificationObject
    {

        public DevicemaViewModel                _DevicemaViewModel { get; set; }
        public UserViewModel                    _UserViewModel { get; set; }
        public NetViewModel                     _NetViewModel { get; set; }
        public UpgradeViewModel                 _UpgradeViewModel { get; set; }
        public AbnormalViewModel                _AbnormalViewModel { get; set; }


        private DeviceVisibleEnum _bShowPage;
        public DeviceVisibleEnum bShowPage
        {
            get { return _bShowPage; }
            set
            {
                _bShowPage = value;
                this.RaisePropertyChanged("bShowPage");
            }
        }

        public DeviceManageViewModel()
        {
            _DevicemaViewModel              = new DevicemaViewModel();
            _UserViewModel                  = new UserViewModel();
            _NetViewModel                   = new NetViewModel();
            _UpgradeViewModel               = new UpgradeViewModel();
            _AbnormalViewModel              = new AbnormalViewModel();




            _bShowPage = DeviceVisibleEnum.DeviceVisibleEnum_Device;
        }
    }
}
