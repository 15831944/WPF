using ManageSystem.Model;
using ManageSystem.Server;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Windows;
using System.Windows.Controls;

namespace ManageSystem.ViewModel
{
    class PaymentQueryViewModel : NotificationObject
    {
        public QueryJIAOKUANSHUJUCallBackDelegate        _queryjiaokuanshujucallbackdelegate = null;

        public DelegateCommand<object>                  QueryCommand { get; set; }
        public DelegateCommand<object>                  SelectedItemCommand { get; set; }
        public DelegateCommand<object>                  UnSelectedItemCommand { get; set; }

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
        private ObservableCollection<string> _itemList;
        public ObservableCollection<string> itemList
        {
            get { return _itemList; }
            set
            {
                _itemList = value;
                this.RaisePropertyChanged("itemList");
            }
        }

        private ObservableCollection<string> _businesstype;
        public ObservableCollection<string> businesstype
        {
            get
            {
                return _businesstype;
            }
            set
            {
                _businesstype = value;
                this.RaisePropertyChanged("businesstype");
            }
        }

        private ObservableCollection<string> _cardstatus;
        public ObservableCollection<string> cardstatus
        {
            get
            {
                return _cardstatus;
            }
            set
            {
                _cardstatus = value;
                this.RaisePropertyChanged("cardstatus");
            }
        }

        private ObservableCollection<JIAOKUANSHUJUModel> _tableList;
        public ObservableCollection<JIAOKUANSHUJUModel> tableList
        {
            get
            {
                return _tableList;
            }
            set
            {
                _tableList = value;
                this.RaisePropertyChanged("tableList");
            }
        }

        public PaymentQueryViewModel()
        {
            _queryjiaokuanshujucallbackdelegate         = new Server.QueryJIAOKUANSHUJUCallBackDelegate(QueryJIAOKUANSHUJUCallBack);
            QueryCommand                                = new DelegateCommand<object>(new Action<object>(this.Query));
            SelectedItemCommand                         = new DelegateCommand<object>(new Action<object>(this.SelectedItem));
            UnSelectedItemCommand                       = new DelegateCommand<object>(new Action<object>(this.UnSelectedItem));

            _bShowPage                                  = Visibility.Visible;
            _deviceList                                 = new ObservableCollection<DeviceModel>();
            _cardstatus                                 = new ObservableCollection<string>();
            _businesstype                               = new ObservableCollection<string>();
            _tableList                                  = new ObservableCollection<JIAOKUANSHUJUModel>();
            {   //for test
                DeviceModel model_1                     = new DeviceModel();
                model_1.Text                            = "深圳市";
                model_1.leftMargin                      = "0,0,0,0";
                DeviceModel model_1_0                   = new DeviceModel();
                model_1_0.Text                          = "市局";
                model_1_0.leftMargin                    = "16, 0, 0, 0";
                model_1.Children.Add(model_1_0);
                DeviceModel model_1_1                   = new DeviceModel();
                model_1_1.Text                          = "宝安分局";
                model_1_1.leftMargin                    = "16, 0, 0, 0";
                model_1.Children.Add(model_1_1);
                DeviceModel model_1_2                   = new DeviceModel();
                model_1_2.Text                          = "南山分局";
                model_1_2.leftMargin                    = "16, 0, 0, 0";
                model_1.Children.Add(model_1_2);
                DeviceModel model_1_2_1                 = new DeviceModel();
                model_1_2_1.Text                        = "南山分局管理科";
                model_1_2_1.leftMargin                  = "32, 0, 0, 0";
                model_1_2.Children.Add(model_1_2_1);

                DeviceModel model_1_2_1_1               = new DeviceModel();
                model_1_2_1_1.Text                      = "127.0.0.1";
                model_1_2_1_1.leftMargin                = "48, 0, 0, 0";
                model_1_2_1.Children.Add(model_1_2_1_1);

                //DeviceModel model_2                     = new DeviceModel();
                //model_2.Text                            = "2";
                //DeviceModel model_2_0                   = new DeviceModel();
                //model_2_0.Text                          = "2_0";
                //model_2.Children.Add(model_2_0);
                //DeviceModel model_2_1                   = new DeviceModel();
                //model_2_1.Text                          = "2_1";
                //model_2.Children.Add(model_2_1);
                //DeviceModel model_2_2                   = new DeviceModel();
                //model_2_2.Text                          = "2_2";
                //model_2.Children.Add(model_2_2);        

                _deviceList.Add(model_1);
                //_deviceList.Add(model_2);
            }
            {
                _cardstatus.Add("全部");
                _cardstatus.Add("成功");
                _cardstatus.Add("失败");
                _cardstatus.Add("异常");
            }
            {
                _businesstype.Add("全部");
                _businesstype.Add("本地");
                _businesstype.Add("异地");
            }
        }

        //Access and update columns during autogeneration
        public void DG1_AutoGeneratingColumn(object sender, DataGridAutoGeneratingColumnEventArgs e)
        {
            string headername = e.Column.Header.ToString();
            //Cancel the column you don't want to generate
            if (headername == "Xuhao")
            {
                e.Column.Header = "序号";
            }
            else if (headername == "Riqi")
            {
                e.Column.Header = "日期";
            }
             else   if (headername == "ShebeiIP")
            {
                e.Column.Header = "设备IP地址";
            }
            else if (headername == "Zhishoudanweidaima")
            {
                e.Column.Header = "执收单位代码";
            }
            else if (headername == "Jiaokuantongzhishuhaoma")
            {
                e.Column.Header = "缴款通知书号码";
            }
            else if (headername == "Jiaokuanrenxingming")
            {
                e.Column.Header = "缴款人姓名";
            }
            else if (headername == "Yingkoukuanheji")
            {
                e.Column.Header = "应扣款合计";
            }
            else if (headername == "Jiaoyiriqi")
            {
                e.Column.Header = "交易日期";
            }
        }
   
        public void QueryJIAOKUANSHUJUCallBack(
                int Xuhao,
                string Riqi,
                string ShebeiIP,
                string Zhishoudanweidaima,
                string Jiaokuantongzhishuhaoma,
                string Jiaokuanrenxingming,
                float  Yingkoukuanheji,
                string Jiaoyiriqi
        )
        {

            JIAOKUANSHUJUModel model        = new JIAOKUANSHUJUModel();
            model.Xuhao                     = Xuhao.ToString();
            model.Riqi                      = Riqi;
            model.ShebeiIP                  = ShebeiIP;
            model.Zhishoudanweidaima        = Zhishoudanweidaima;
            model.Jiaokuantongzhishuhaoma   = Jiaokuantongzhishuhaoma;
            model.Jiaokuanrenxingming       = Jiaokuanrenxingming;
            model.Yingkoukuanheji           = Yingkoukuanheji;
            model.Jiaoyiriqi                = Jiaoyiriqi;

            tableList.Add(model);
        }
        public void Query(object obj)
        {
            tableList.Clear();
            WorkServer.GetInstance().QueryJIAOKUANSHUJU("select * from Jiaokuanshuju", Marshal.GetFunctionPointerForDelegate(_queryjiaokuanshujucallbackdelegate));
        }


        public void SelectedItem(object obj)
        {
            CheckBox changebox = obj as CheckBox;
            if(changebox.IsFocused == false)
                return;
            DeviceModel deviceModelChange = changebox.DataContext as DeviceModel;

            ////MakeChildrens
            foreach (DeviceModel child0 in deviceModelChange.Children)
            {
                child0.isSel  = true;
                foreach (DeviceModel child1 in child0.Children)
                {
                    child1.isSel  = true;
                    foreach (DeviceModel child2 in child1.Children)
                    {
                        child2.isSel  = true;
                    }
                }
            }

            ////MakeParent
            bool bBreak = false;
            foreach (DeviceModel parent0 in deviceList)
            {
                foreach (DeviceModel parent1 in parent0.Children)
                {
                    if (parent1 == deviceModelChange)
                    {
                        bBreak = true;
                        parent0.isSel = true;
                        break;
                    }
                    foreach (DeviceModel parent2 in parent1.Children)
                    {
                        if (parent2 == deviceModelChange)
                        {
                            bBreak = true;
                            parent0.isSel = true;
                            parent1.isSel = true;
                            break;
                        }

                        foreach (DeviceModel parent3 in parent2.Children)
                        {
                            if (parent0 == deviceModelChange)
                            {
                                bBreak = true;
                                parent0.isSel = true;
                                parent1.isSel = true;
                                parent2.isSel = true;
                                break;
                            }
                        }

                        if (bBreak) break;
                    }
                    if (bBreak) break;
                }
                if (bBreak) break;
            }
        }
        public void UnSelectedItem(object obj)
        {
            CheckBox changebox = obj as CheckBox;
            DeviceModel deviceModelChange = changebox.DataContext as DeviceModel;

            ////MakeChildrens
            foreach (DeviceModel child0 in deviceModelChange.Children)
            {
                child0.isSel  = false;
                foreach (DeviceModel child1 in child0.Children)
                {
                    child1.isSel  = false;
                    foreach (DeviceModel child2 in child1.Children)
                    {
                        child2.isSel  = false;
                    }
                }
            }
        }
    }
}
