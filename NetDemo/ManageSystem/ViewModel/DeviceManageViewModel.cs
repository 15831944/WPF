using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using ManageSystem.ViewModel.DeviceViewModel;

namespace ManageSystem.ViewModel
{
    enum DeviceVisibleEnum
    {
        DeviceVisibleEnum_None,
        DeviceVisibleEnum_Device,
        DeviceVisibleEnum_User,
        DeviceVisibleEnum_Net,
        DeviceVisibleEnum_Upgrade,
        DeviceVisibleEnum_Abnormal,
    }

    class DeviceManageViewModel : NotificationObject
    {
        public DelegateCommand<object> DevicemaCommand { get; set; }
        public DelegateCommand<object> UseCommand { get; set; }
        public DelegateCommand<object> NetCommand { get; set; }
        public DelegateCommand<object> UpgradeCommand { get; set; }
        public DelegateCommand<object> AbnormalCommand { get; set; }


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
            DevicemaCommand                 = new DelegateCommand<object>(DevicemaShow);
            UseCommand                      = new DelegateCommand<object>(UseShow);
            NetCommand                      = new DelegateCommand<object>(NetShow);
            UpgradeCommand                  = new DelegateCommand<object>(UpgradeShow);
            AbnormalCommand                 = new DelegateCommand<object>(AbnormalShow);


            _DevicemaViewModel              = new DevicemaViewModel();
            _UserViewModel                  = new UserViewModel();
            _NetViewModel                   = new NetViewModel();
            _UpgradeViewModel               = new UpgradeViewModel();
            _AbnormalViewModel              = new AbnormalViewModel();




            bShowPage = DeviceVisibleEnum.DeviceVisibleEnum_Upgrade;
        }

        private void AbnormalShow(object obj)
        {
            bShowPage = DeviceVisibleEnum.DeviceVisibleEnum_Abnormal;
        }

        private void UpgradeShow(object obj)
        {
            bShowPage = DeviceVisibleEnum.DeviceVisibleEnum_Upgrade;
        }

        private void NetShow(object obj)
        {
            bShowPage = DeviceVisibleEnum.DeviceVisibleEnum_Net;
        }

        private void UseShow(object obj)
        {
            bShowPage = DeviceVisibleEnum.DeviceVisibleEnum_User;
        }

        private void DevicemaShow(object obj)
        {
            bShowPage = DeviceVisibleEnum.DeviceVisibleEnum_Device;
        }
    }
}
