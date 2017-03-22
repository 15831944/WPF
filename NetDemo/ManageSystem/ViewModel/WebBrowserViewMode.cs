using ManageSystem.Model;
using ManageSystem.Server;
using ManageSystem.ViewModel.DeviceViewModel;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Net;
using System.Runtime.InteropServices;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Xml;

namespace ManageSystem.ViewModel
{
   public  class DeviceStatus : NotificationObject
    {
        private string _ip;
        public string ip
        {
            get { return _ip; }
            set
            {
                _ip = value;
                this.RaisePropertyChanged("ip");
            }
        }

        private string _serverip;
        public string serverip
        {
            get { return _serverip; }
            set
            {
                _serverip = value;
                this.RaisePropertyChanged("serverip");
            }
        }


        private bool _bDevice;
        public bool bDevice
        {
            get { return _bDevice; }
            set
            {
                _bDevice = value;
                this.RaisePropertyChanged("bDevice");
            }
        }

        private bool _bNormal;
        public bool bNormal
        {
            get { return _bNormal; }
            set
            {
                _bNormal = value;
                this.RaisePropertyChanged("bNormal");
            }
        }
    }
   public  class WebBrowserViewMode : NotificationObject
    {
        public static string                            _connectionsStr = "";
        WebBrowser webbrowser;
        public QueryTableCallBackDelegate               _querytablecallbackdelegate = null;

        public DelegateCommand<object>                  LoadedCommand { get; set; }
        public DelegateCommand<object>                  LoadCompletedCommand { get; set; }


        private string _url;
        public string url
        {
            get { return _url; }
            set
            {
                _url = value;
                this.RaisePropertyChanged("url");
            }
        }

        private ObservableCollection<DeviceStatus> _tableList;
        public ObservableCollection<DeviceStatus> tableList
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

        private string _xmlData;
        public string xmlData
        {
            get { return _xmlData; }
            set
            {
                _xmlData = value;
                this.RaisePropertyChanged("xmlData");
            }
        }

        public WebBrowserViewMode()
        {
            _querytablecallbackdelegate                 = new QueryTableCallBackDelegate(QueryTableCallBack);

            LoadedCommand                               = new DelegateCommand<object>(new Action<object>(this.Loaded));
            LoadCompletedCommand                        = new DelegateCommand<object>(new Action<object>(this.LoadCompleted));

            _url                                        = "http://120.76.148.9/testgis/map/gis.html";
            _xmlData                                    = "";
        }

        public void QueryTableCallBack(string resultStr, string errorStr)
        {
            if (resultStr != _connectionsStr)
                _connectionsStr = resultStr;
            else
                return;

            if (resultStr == null || resultStr.Length == 0)
                return;

            Type type = typeof(DeviceStatus);

            if (type == null)
                return;

            System.Reflection.PropertyInfo[] properties = type.GetProperties(System.Reflection.BindingFlags.Instance | System.Reflection.BindingFlags.Public);

            string[] rows = resultStr.Split(';');
            foreach (string row in rows)
            {
                if (row.Length > 0)
                {
                    var model= Activator.CreateInstance(type);

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
                                    switch (item.Name)
                                    {
                                        case "Chengshibianhao":
                                        case "Jubianhao":
                                        case "Shiyongdanweibianhao":
                                        case "Shebeibaifangweizhi":
                                        case "Qianzhuzhonglei":
                                        case "ZhikaZhuangtai":
                                        case "Zhengjianleixing":
                                        case "Xingbie":
                                        case "Yewuleixing":
                                            if (MainWindowViewModel._yingshelList.Keys.Contains(Convert.ToInt32(keyvalue[1])))
                                                item.SetValue(model, MainWindowViewModel._yingshelList[Convert.ToInt32(keyvalue[1])], null);
                                            break;
                                        case "Riqi":
                                        case "Chushengriqi":
                                        case "Jiaoyiriqi":
                                            DateTime datetime = Common.ConvertIntDateTime(Convert.ToInt64(keyvalue[1]));
                                            item.SetValue(model, datetime.ToShortDateString(), null);
                                            break;
                                        case "IP":
                                            if (keyvalue[1].Length > 0)
                                                item.SetValue(model, Common.IntToIp(IPAddress.NetworkToHostOrder(Convert.ToInt32(keyvalue[1]))), null);
                                            break;
                                        default:
                                            item.SetValue(model, keyvalue[1], null);
                                            break;
                                    }
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
                    DeviceStatus modelTemp = model as DeviceStatus;

                    foreach (DeviceModel model0 in DevicemaViewModel._deviceList){//市
                        foreach (DeviceModel model1 in model0.Children){//局
                            foreach (DeviceModel model2 in model1.Children){//单位
                                foreach (DeviceModel model3 in model2.Children){//IP
                                    if (model3.text == modelTemp.ip)
                                    {
                                        model3.bStatus = Convert.ToInt32(modelTemp.bNormal);
                                    }
                                }
                            }
                        }
                    }
                }
            }


            XmlDocument doc = new XmlDocument();
            XmlDeclaration dec = doc.CreateXmlDeclaration("1.0", "UTF-8", null);
            doc.AppendChild(dec);
            XmlElement root = doc.CreateElement("xml");
            doc.AppendChild(root);
            foreach (DeviceModel model0 in DevicemaViewModel._deviceList){//市
                foreach (DeviceModel model1 in model0.Children){//局
                    foreach (DeviceModel model2 in model1.Children){//单位
                        XmlElement station          = doc.CreateElement("station");
                        XmlElement id               = doc.CreateElement("id"); 
                        id.InnerText                = model2.text;
                        XmlElement name             = doc.CreateElement("name"); 
                        name.InnerText              = model2.text;
                        XmlElement lonstr           = doc.CreateElement("lonstr"); 
                        lonstr.InnerText            = "";
                        XmlElement latstr           = doc.CreateElement("latstr"); 
                        latstr.InnerText            = "";
                        XmlElement lon              = doc.CreateElement("lon");
                        lon.InnerText               = "";
                        XmlElement lat              = doc.CreateElement("lat");
                        lat.InnerText               = "";
                        XmlElement color            = doc.CreateElement("color");
                        color.InnerText             = "";
                        XmlElement desc             = doc.CreateElement("desc");
                        desc.InnerText              = model2.text;
                        XmlElement items             = doc.CreateElement("items");

                        int grayCnt     = 0;
                        int yichangCnt  = 0;
                        foreach (DeviceModel model3 in model2.Children){//IP

                            lon.InnerText               = model3.lonstr;
                            lat.InnerText               = model3.latstr;
                            lonstr.InnerText            = model3.lonstr;
                            latstr.InnerText            = model3.latstr;

                            XmlElement item             = doc.CreateElement("item");
                            item.SetAttribute("id", model3.text);
                            item.SetAttribute("sid", model2.text);
                            item.SetAttribute("name", model3.text);

                            if (model3.bStatus == 0)
                            {
                                item.SetAttribute("color", "red");
                                yichangCnt++;
                            }
                            if (model3.bStatus == 1)
                            {
                                item.SetAttribute("color", "lime");
                            }
                            if (model3.bStatus == 2)
                            {
                                item.SetAttribute("color", "lime");
                                grayCnt++;
                            }

                            XmlElement option0             = doc.CreateElement("option");
                            option0.SetAttribute("img", "汇总统计.png");
                            option0.SetAttribute("callback", "汇总统计");
                            option0.SetAttribute("param", "id,sid");
                            XmlElement option1             = doc.CreateElement("option");
                            option1.SetAttribute("img", "制签统计.png");
                            option1.SetAttribute("callback", "制签统计");
                            option1.SetAttribute("param", "id,sid");
                            XmlElement option2             = doc.CreateElement("option");
                            option2.SetAttribute("img", "制签异常统计.png");
                            option2.SetAttribute("callback", "制签异常统计");
                            option2.SetAttribute("param", "id,sid");

                            XmlElement option3             = doc.CreateElement("option");
                            option3.SetAttribute("img", "制签记录查询.png");
                            option3.SetAttribute("callback", "制签记录查询");
                            option3.SetAttribute("param", "id,sid");
                            XmlElement option4             = doc.CreateElement("option");
                            option4.SetAttribute("img", "收证记录查询.png");
                            option4.SetAttribute("callback", "收证记录查询");
                            option4.SetAttribute("param", "id,sid");
                            XmlElement option5             = doc.CreateElement("option");
                            option5.SetAttribute("img", "签注记录查询.png");
                            option5.SetAttribute("callback", "签注记录查询");
                            option5.SetAttribute("param", "id,sid");
                            XmlElement option6             = doc.CreateElement("option");
                            option6.SetAttribute("img", "缴款记录查询.png");
                            option6.SetAttribute("callback", "缴款记录查询");
                            option6.SetAttribute("param", "id,sid");
                            XmlElement option7             = doc.CreateElement("option");
                            option7.SetAttribute("img", "查询记录查询.png");
                            option7.SetAttribute("callback", "查询记录查询");
                            option7.SetAttribute("param", "id,sid");
                            XmlElement option8             = doc.CreateElement("option");
                            option8.SetAttribute("img", "预受理记录查询.png");
                            option8.SetAttribute("callback", "预受理记录查询");
                            option8.SetAttribute("param", "id,sid");
                            XmlElement option9             = doc.CreateElement("option");
                            option9.SetAttribute("img", "设备管理.png");
                            option9.SetAttribute("callback", "设备管理");
                            option9.SetAttribute("param", "id,sid");

                            item.AppendChild(option0); 
                            item.AppendChild(option1); 
                            item.AppendChild(option2);
                            item.AppendChild(option3);
                            item.AppendChild(option4);
                            item.AppendChild(option5);
                            item.AppendChild(option6);
                            item.AppendChild(option7);
                            item.AppendChild(option8);
                            item.AppendChild(option9); 
                            items.AppendChild(item); 
                        }

                        if (yichangCnt == 0)
                            color.InnerText = "blue";
                        if(yichangCnt == (model2.Children.Count - grayCnt))
                            color.InnerText = "red";
                        if (yichangCnt < (model2.Children.Count - grayCnt))
                            color.InnerText = "yellow";
                        if (grayCnt == model2.Children.Count)
                            color.InnerText = "lime";
                        
                        station.AppendChild(id);
                        station.AppendChild(name);
                        station.AppendChild(lonstr);
                        station.AppendChild(latstr);
                        station.AppendChild(lon);
                        station.AppendChild(lat);
                        station.AppendChild(color);
                        station.AppendChild(desc);
                        station.AppendChild(items);
                        root.AppendChild(station);
                    }
                }
            }
            //Application.Current.Dispatcher.Invoke(
            //new Action(() =>
            //{
            //    webbrowser.InvokeScript("LoadData", doc.InnerXml);
            //}));
            xmlData = doc.InnerXml;
        }

        public void QueryConnectionsStatu(object obj)
        {
            foreach (DeviceModel model0 in DevicemaViewModel._deviceList)
            {//市
                foreach (DeviceModel model1 in model0.Children)
                {//局
                    foreach (DeviceModel model2 in model1.Children)
                    {//单位
                        foreach (DeviceModel model3 in model2.Children)
                        {//IP
                            model3.bStatus = 2;////不在线
                        }
                    }
                }
            }
            WorkServer.queryConnectionsStr(Marshal.GetFunctionPointerForDelegate(_querytablecallbackdelegate), true);
        }

        private void LoadCompleted(object obj)
        {
        }

        public void Loaded(object obj)
        {
        }

        public void DoLogon()
        {
            string urlTemp = "http://120.76.148.9/testgis/map/gis.html";
            if(url != urlTemp)
                url = urlTemp;

            //int a = IPAddress.HostToNetworkOrder((Int32)Common.IpToInt("192.168.1.106"));

            QueryConnectionsStatu(null);
        }
    }
}
