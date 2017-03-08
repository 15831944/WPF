using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;

namespace ManageSystem.ViewModel
{
    class WebBrowserViewMode : NotificationObject
    {
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

        }

        public void DoLogon()
        {
            string urlTemp = "http://120.76.148.9/testgis/map/gis.html";
            if(url != urlTemp)
                url = urlTemp;
        }
    }
}
