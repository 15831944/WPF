using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ManageSystem.Model
{
    public class DeviceModel : NotificationObject
    {
        public DeviceModel()
        {
            _text       = "UnKnown";
            _children   = new List<DeviceModel>();
        }

        private List<DeviceModel> _children;
        public List<DeviceModel> Children
        {
            get
            {
                return _children;
            }
            set
            {
                _children = value;
                this.RaisePropertyChanged("Children");
            }
        }

        private string _text;
        public string Text
        {
            get
            {
                return _text;
            }
            set
            {
                _text = value;
                this.RaisePropertyChanged("Text");
            }
        }
    }
}
