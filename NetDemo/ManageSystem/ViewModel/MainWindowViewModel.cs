using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;

namespace ManageSystem.ViewModel
{
    class MainWindowViewModel : NotificationObject
    {
        public DelegateCommand<object>                  HomePageCommand { get; set; }
        public DelegateCommand<object>                  StatisticsCommand { get; set; }
        public DelegateCommand<object>                  QueryCommand { get; set; }
        public DelegateCommand<object>                  DeviceManagementCommand { get; set; }
        public DelegateCommand<object>                  ElectronicMapCommand { get; set; }
        public DelegateCommand<object>                  OptionCommand { get; set; }
        public DelegateCommand<object>                  ResListCommand { get; set; }

        public HomePageViewModel                        _HomePageViewModel { get; set; }
        public StatisticsViewModel                      _StatisticsViewModel { get; set; }
        public QueryViewModel                           _QueryViewModel { get; set; }
        public DeviceManagementViewModel                _DeviceManagementViewModel { get; set; }
        public ElectronicMapViewModel                   _ElectronicMapViewModel { get; set; }
        public ResListViewModel                         _ResListViewModel { get; set; }
        public OptionViewModel                          _OptionViewModel { get; set; }

        public MainWindowViewModel()
        {
            HomePageCommand                             = new DelegateCommand<object>(new Action<object>(this.mainPageShow));
            StatisticsCommand                           = new DelegateCommand<object>(new Action<object>(this.StatisticsShow));
            QueryCommand                                = new DelegateCommand<object>(new Action<object>(this.QueryShow));
            DeviceManagementCommand                     = new DelegateCommand<object>(new Action<object>(this.DeviceManagementShow));
            ElectronicMapCommand                        = new DelegateCommand<object>(new Action<object>(this.ElectronicMapShow));
            ResListCommand                              = new DelegateCommand<object>(new Action<object>(this.ResListShow));
            OptionCommand                               = new DelegateCommand<object>(new Action<object>(this.OptionShow));

            _HomePageViewModel                          = new HomePageViewModel();
            _StatisticsViewModel                        = new StatisticsViewModel();
            _QueryViewModel                             = new QueryViewModel();
            _DeviceManagementViewModel                  = new DeviceManagementViewModel();
            _ElectronicMapViewModel                     = new ElectronicMapViewModel();
            _ResListViewModel                           = new ResListViewModel();
            _OptionViewModel                            = new OptionViewModel();

            _HomePageViewModel.bShowPage                = Visibility.Visible;
            _StatisticsViewModel.bShowPage              = Visibility.Hidden;
            _QueryViewModel.bShowPage                   = Visibility.Hidden;
            _DeviceManagementViewModel.bShowPage        = Visibility.Hidden;
            _ElectronicMapViewModel.bShowPage           = Visibility.Hidden;
            _ResListViewModel.bShowPage                 = Visibility.Hidden;
            _OptionViewModel.bShowPage                  = Visibility.Hidden;
        }

        public void mainPageShow(object obj)
        {
            _HomePageViewModel.bShowPage                = Visibility.Visible;
            _StatisticsViewModel.bShowPage              = Visibility.Hidden;
            _QueryViewModel.bShowPage                   = Visibility.Hidden;
            _DeviceManagementViewModel.bShowPage        = Visibility.Hidden;
            _ElectronicMapViewModel.bShowPage           = Visibility.Hidden;
            _ResListViewModel.bShowPage                 = Visibility.Hidden;
            _OptionViewModel.bShowPage                  = Visibility.Hidden;
        }

        public void StatisticsShow(object obj)
        {
            _HomePageViewModel.bShowPage                = Visibility.Hidden;
            _StatisticsViewModel.bShowPage              = Visibility.Visible;
            _QueryViewModel.bShowPage                   = Visibility.Hidden;
            _DeviceManagementViewModel.bShowPage        = Visibility.Hidden;
            _ElectronicMapViewModel.bShowPage           = Visibility.Hidden;
            _ResListViewModel.bShowPage                 = Visibility.Hidden;
            _OptionViewModel.bShowPage                  = Visibility.Hidden;
        }
        public void QueryShow(object obj)
        {
            _HomePageViewModel.bShowPage                = Visibility.Hidden;
            _StatisticsViewModel.bShowPage              = Visibility.Hidden;
            _QueryViewModel.bShowPage                   = Visibility.Visible;
            _DeviceManagementViewModel.bShowPage        = Visibility.Hidden;
            _ElectronicMapViewModel.bShowPage           = Visibility.Hidden;
            _ResListViewModel.bShowPage                 = Visibility.Hidden;
            _OptionViewModel.bShowPage                  = Visibility.Hidden;
        }
        public void DeviceManagementShow(object obj)
        {
            _HomePageViewModel.bShowPage                = Visibility.Hidden;
            _StatisticsViewModel.bShowPage              = Visibility.Hidden;
            _QueryViewModel.bShowPage                   = Visibility.Hidden;
            _DeviceManagementViewModel.bShowPage        = Visibility.Visible;
            _ElectronicMapViewModel.bShowPage           = Visibility.Hidden;
            _ResListViewModel.bShowPage                 = Visibility.Hidden;
            _OptionViewModel.bShowPage                  = Visibility.Hidden;
        }
        public void ElectronicMapShow(object obj)
        {
            _HomePageViewModel.bShowPage                = Visibility.Hidden;
            _StatisticsViewModel.bShowPage              = Visibility.Hidden;
            _QueryViewModel.bShowPage                   = Visibility.Hidden;
            _DeviceManagementViewModel.bShowPage        = Visibility.Hidden;
            _ElectronicMapViewModel.bShowPage           = Visibility.Visible;
            _ResListViewModel.bShowPage                 = Visibility.Hidden;
            _OptionViewModel.bShowPage                  = Visibility.Hidden;
        }
        public void ResListShow(object obj)
        {
            _HomePageViewModel.bShowPage                = Visibility.Hidden;
            _StatisticsViewModel.bShowPage              = Visibility.Hidden;
            _QueryViewModel.bShowPage                   = Visibility.Hidden;
            _DeviceManagementViewModel.bShowPage        = Visibility.Hidden;
            _ElectronicMapViewModel.bShowPage           = Visibility.Hidden;
            _ResListViewModel.bShowPage                 = Visibility.Visible;
            _OptionViewModel.bShowPage                  = Visibility.Hidden;
        }
        public void OptionShow(object obj)
        {
            _HomePageViewModel.bShowPage                = Visibility.Hidden;
            _StatisticsViewModel.bShowPage              = Visibility.Hidden;
            _QueryViewModel.bShowPage                   = Visibility.Hidden;
            _DeviceManagementViewModel.bShowPage        = Visibility.Hidden;
            _ElectronicMapViewModel.bShowPage           = Visibility.Hidden;
            _ResListViewModel.bShowPage                 = Visibility.Hidden;
            _OptionViewModel.bShowPage                  = Visibility.Visible;
        }
    }
}
