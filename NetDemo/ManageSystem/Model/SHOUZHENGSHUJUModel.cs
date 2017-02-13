using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ManageSystem.Model
{
    class SHOUZHENGSHUJUModel : NotificationObject
    {
        private string _Xuhao;
        public string Xuhao
        {
            get
            {
                return _Xuhao;
            }
            set
            {
                _Xuhao = value;
                this.RaisePropertyChanged("Xuhao");
            }
        }

        private string _Riqi;
        public string Riqi
        {
            get
            {
                return _Riqi;
            }
            set
            {
                _Riqi = value;
                this.RaisePropertyChanged("Riqi");
            }
        }
        private string _ShebeiIP;
        public string ShebeiIP
        {
            get
            {
                return _ShebeiIP;
            }
            set
            {
                _ShebeiIP = value;
                this.RaisePropertyChanged("ShebeiIP");
            }
        }
        private string _Zhengjianleixing;
        public string Zhengjianleixing
        {
            get
            {
                return _Zhengjianleixing;
            }
            set
            {
                _Zhengjianleixing = value;
                this.RaisePropertyChanged("Zhengjianleixing");
            }
        }
        private string _Zhengjianhaoma;
        public string Zhengjianhaoma
        {
            get
            {
                return _Zhengjianhaoma;
            }
            set
            {
                _Zhengjianhaoma = value;
                this.RaisePropertyChanged("Zhengjianhaoma");
            }
        }
        private string _Xingming;
        public string Xingming
        {
            get
            {
                return _Xingming;
            }
            set
            {
                _Xingming = value;
                this.RaisePropertyChanged("Xingming");
            }
        }
        private string _Shoulibianhao;
        public string Shoulibianhao
        {
            get
            {
                return _Shoulibianhao;
            }
            set
            {
                _Shoulibianhao = value;
                this.RaisePropertyChanged("Shoulibianhao");
            }
        }
        private string _Shifoujiaofei;
        public string Shifoujiaofei
        {
            get
            {
                return _Shifoujiaofei;
            }
            set
            {
                _Shifoujiaofei = value;
                this.RaisePropertyChanged("Shifoujiaofei");
            }
        }
    }
}
