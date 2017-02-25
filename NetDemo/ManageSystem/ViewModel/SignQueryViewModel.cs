using ManageSystem.Model;
using ManageSystem.Server;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Diagnostics;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;

namespace ManageSystem.ViewModel
{
    class SignQueryViewModel : NotificationObject
    {
        public QueryTableCallBackDelegate               _querytablecallbackdelegate = null;
        public QueryZHIQIANSHUJUCallBackDelegate        _queryzhiqianshujucallbackdelegate = null;
        public Dictionary<string, string>               _columnNameMap = new Dictionary<string, string>
        {
           {"Xuhao",				"序号"},
           {"Chengshibianhao",		"城市编号"},
           {"Jubianhao",			"局编号"},
           {"Shiyongdanweibianhao",	"使用单位编号"},
           {"IP",					"ip地址"},
           {"Bendiyewu",			"是否本地业务"},
           {"Shebeibaifangweizhi",	"设备摆放位置"},
           {"Riqi",					"日期"},
           {"Yewubianhao",			"业务编号"},
           {"YuanZhengjianhaoma",	"原证件号码"},
           {"Xingming",				"姓名"},
           {"Qianzhuzhonglei",		"签注种类"},
           {"ZhikaZhuangtai",		"制卡状态"},
           {"Zhengjianhaoma",		"证件号码"},
           {"Jiekoufanhuijieguo",	"接口返回结果"},
           {"Lianxidianhua",		"联系电话"},
        };
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

        private ObservableCollection<ZHIQIANSHUJUModel> _tableList;
        public ObservableCollection<ZHIQIANSHUJUModel> tableList
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

        public SignQueryViewModel()
        {
            _querytablecallbackdelegate                 = new QueryTableCallBackDelegate(QueryTableCallBack);
            _queryzhiqianshujucallbackdelegate          = new Server.QueryZHIQIANSHUJUCallBackDelegate(QueryZHIQIANSHUJUCallBack);
            QueryCommand                                = new DelegateCommand<object>(new Action<object>(this.Query));
            SelectedItemCommand                         = new DelegateCommand<object>(new Action<object>(this.SelectedItem));
            UnSelectedItemCommand                       = new DelegateCommand<object>(new Action<object>(this.UnSelectedItem));

            _bShowPage                                  = Visibility.Visible;
            _deviceList                                 = new ObservableCollection<DeviceModel>();
            _cardstatus                                 = new ObservableCollection<string>();
            _businesstype                               = new ObservableCollection<string>();
            _tableList                                  = new ObservableCollection<ZHIQIANSHUJUModel>();
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
            if (_columnNameMap.ContainsKey(headername))
            {
                e.Column.Header = _columnNameMap[headername];
            }
        }
        public void QueryTableCallBack(string resultStr)
        {
            System.Reflection.PropertyInfo[] properties = typeof(ZHIQIANSHUJUModel).GetProperties(System.Reflection.BindingFlags.Instance | System.Reflection.BindingFlags.Public);

            string[] rows = resultStr.Split(';');
            foreach (string row in rows)
            {
                if (row.Length > 0)
                {
                    ZHIQIANSHUJUModel model     = new ZHIQIANSHUJUModel();

                    string[] cells = row.Split(',');
                    foreach (string cell in cells)
                    {
                        string[] keyvalue = cell.Split(':');
                        if (keyvalue.Length != 2)
                            continue;

                        foreach (System.Reflection.PropertyInfo item in properties)
                        {
                            if (item.Name == keyvalue[0])
                            {
                                if (item.PropertyType.Name.StartsWith("Int32"))
                                {
                                    item.SetValue(model, Convert.ToInt32(keyvalue[1]), null);
                                }
                                else if (item.PropertyType.Name.StartsWith("Int64"))
                                {
                                    item.SetValue(model, Convert.ToInt64(keyvalue[1]), null);
                                }
                                else if (item.PropertyType.Name.StartsWith("String"))
                                {
                                    item.SetValue(model, keyvalue[1], null);
                                }
                                else if (item.PropertyType.Name.StartsWith("Boolean"))
                                {
                                    item.SetValue(model, Convert.ToBoolean(Convert.ToInt32(keyvalue[1])), null);
                                }
                                else
                                {
                                    ;
                                }
                                break;
                            }
                        }
                    }
                    tableList.Add(model);
                }
            }
        }
        public void QueryZHIQIANSHUJUCallBack(
                int Xuhao,
                int Chengshibianhao,
                int Jubianhao,
                int Shiyongdanweibianhao,
                int IP,
                bool Bendiyewu,
                int Shebeibaifangweizhi,
                Int64 Riqi,
                string Yewubianhao,
                string YuanZhengjianhaoma,
                string Xingming,
                int Qianzhuzhonglei,
                int ZhikaZhuangtai,
                string Zhengjianhaoma,
                string Jiekoufanhuijieguo,
                string Lianxidianhua
        )
        {

            ZHIQIANSHUJUModel model     = new ZHIQIANSHUJUModel();
            model.Xuhao				    = Xuhao;
            model.Chengshibianhao		= Chengshibianhao;
            model.Jubianhao			    = Jubianhao;
            model.Shiyongdanweibianhao  = Shiyongdanweibianhao;
            model.IP					= IP;
            model.Bendiyewu			    = Bendiyewu;
            model.Shebeibaifangweizhi	= Shebeibaifangweizhi;
            model.Riqi				    = Riqi;
            model.Yewubianhao			= Yewubianhao;
            model.YuanZhengjianhaoma	= YuanZhengjianhaoma;
            model.Xingming			    = Xingming;
            model.Qianzhuzhonglei		= Qianzhuzhonglei;
            model.ZhikaZhuangtai		= ZhikaZhuangtai;
            model.Zhengjianhaoma		= Zhengjianhaoma;
            model.Jiekoufanhuijieguo	= Jiekoufanhuijieguo;
            model.Lianxidianhua		    = Lianxidianhua;

            //Debug.WriteLine(tableList.Count);
            tableList.Add(model);
        }
        public void Query(object obj)
        {
            tableList.Clear();
            WorkServer.GetInstance().QueryTable("select * from Zhiqianshuju", Marshal.GetFunctionPointerForDelegate(_querytablecallbackdelegate));
            //WorkServer.GetInstance().QueryZHIQIANSHUJU("select * from Zhiqianshuju", Marshal.GetFunctionPointerForDelegate(_queryzhiqianshujucallbackdelegate));
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
