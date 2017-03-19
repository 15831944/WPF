using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;

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

        private string  _leftMargin;
        public string  leftMargin
        {
            get
            {
                return _leftMargin;
            }
            set
            {
                _leftMargin = value;
                this.RaisePropertyChanged("leftMargin");
            }
        }

        private bool _isSel;
        public bool isSel
        {
            get
            {
                return _isSel;
            }
            set
            {
                _isSel = value;
                this.RaisePropertyChanged("isSel");
            }
        }

        private string _text;
        public string text
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

        private string _lonstr;
        public string lonstr
        {
            get
            {
                return _lonstr;
            }
            set
            {
                _lonstr = value;
                this.RaisePropertyChanged("lonstr");
            }
        }

        private string _latstr;
        public string latstr
        {
            get
            {
                return _latstr;
            }
            set
            {
                _latstr = value;
                this.RaisePropertyChanged("latstr");
            }
        }

        private int _bStatus;
        public int bStatus
        {
            get
            {
                return _bStatus;
            }
            set
            {
                _bStatus = value;
                this.RaisePropertyChanged("bStatus");
            }
        }
    }
}
