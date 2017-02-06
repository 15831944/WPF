using ManageSystem.Model;
using ManageSystem.Server;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Windows;

namespace ManageSystem.ViewModel
{
    class QueryViewModel : NotificationObject
    {
        public QueryIDCARDAPPLYCallBackDelegate         QueryIDCARDAPPLYCallBackDelegate = null;

        public DelegateCommand<object>                  QueryCommand { get; set; }

         private Visibility _bShowPage;
        public Visibility bShowPage
        {
            get { return _bShowPage; }
            set
            {
                _bShowPage = value;
                this.RaisePropertyChanged("bShowPage");
            }
        }

        private  ObservableCollection<DeviceModel> _deviceList;
        public ObservableCollection<DeviceModel> deviceList
        {
            get { return _deviceList; }
            set
            {
                _deviceList = value;
                this.RaisePropertyChanged("deviceList");
            }
        }

        public QueryViewModel()
        {
            QueryIDCARDAPPLYCallBackDelegate            = new Server.QueryIDCARDAPPLYCallBackDelegate(QueryIDCARDAPPLYCallBack);
            QueryCommand                                = new DelegateCommand<object>(new Action<object>(this.Query));

            _bShowPage                                  = Visibility.Visible;
            _deviceList                                 = new ObservableCollection<DeviceModel>();
            {   //for test
                DeviceModel model_1                     = new DeviceModel();
                model_1.Text                            = "1";
                DeviceModel model_1_0                   = new DeviceModel();
                model_1_0.Text                          = "1_0";
                model_1.Children.Add(model_1_0);
                DeviceModel model_1_1                   = new DeviceModel();
                model_1_1.Text                          = "1_1";
                model_1.Children.Add(model_1_1);
                DeviceModel model_1_2                   = new DeviceModel();
                model_1_2.Text                          = "1_2";
                model_1.Children.Add(model_1_2);

                DeviceModel model_2                     = new DeviceModel();
                model_2.Text                            = "2";
                DeviceModel model_2_0                   = new DeviceModel();
                model_2_0.Text                          = "2_0";
                model_2.Children.Add(model_2_0);
                DeviceModel model_2_1                   = new DeviceModel();
                model_2_1.Text                          = "2_1";
                model_2.Children.Add(model_2_1);
                DeviceModel model_2_2                   = new DeviceModel();
                model_2_2.Text                          = "2_2";
                model_2.Children.Add(model_2_2);        

                _deviceList.Add(model_1);
                _deviceList.Add(model_2);
            }
        }

        public void QueryIDCARDAPPLYCallBack(
                    string name,
                    string gender,
                    string Nation,
                    string Birthday,
                    string Address,
                    string IdNumber,
                    string SigDepart,
                    string SLH,
                    IntPtr fpData,
                    int fpDataSize,
                    IntPtr fpFeature,
                    int fpFeatureSize,
                    IntPtr XCZP,
                    int XCZPSize,
                    string XZQH,
                    string sannerId,
                    string scannerName,
                    bool legal,
                    string operatorID,
                    string operatorName,
                    string opDate
        )
        {

        }
        public void Query(object obj)
        {
            WorkServer.GetInstance().QueryIDCARDAPPLY("select * from idCardApply", Marshal.GetFunctionPointerForDelegate(QueryIDCARDAPPLYCallBackDelegate));
        }
    }
}
