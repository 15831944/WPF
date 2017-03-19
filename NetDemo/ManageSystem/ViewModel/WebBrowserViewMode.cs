using ManageSystem.ViewModel.DeviceViewModel;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Xml;

namespace ManageSystem.ViewModel
{
    [System.Runtime.InteropServices.ComVisible(true)]
    public class ObjectForScripingHelper
    {
        public ObjectForScripingHelper()
        {

        }

        public void Test(string msg)
        {
            MessageBox.Show("msg");
        }
    }

    class WebBrowserViewMode : NotificationObject
    {
        WebBrowser webbrowser;
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

        public WebBrowserViewMode()
        {
            LoadedCommand                               = new DelegateCommand<object>(new Action<object>(this.Loaded));
            LoadCompletedCommand                        = new DelegateCommand<object>(new Action<object>(this.LoadCompleted));

            _url                                        = "http://120.76.148.9/testgis/map/gis.html";
        }

        private void LoadCompleted(object obj)
        {
            object objj = webbrowser.InvokeScript("Get");
        }

        public void Loaded(object obj)
        {
            webbrowser = obj as WebBrowser;
            webbrowser.ObjectForScripting   = new ObjectForScripingHelper();
        }

        public void DoLogon()
        {
            string urlTemp = "http://120.76.148.9/testgis/map/gis.html";
            if(url != urlTemp)
                url = urlTemp;

            webbrowser.InvokeScript("LoadData", DevicemaViewModel._sitesString);
        }
    }
}
