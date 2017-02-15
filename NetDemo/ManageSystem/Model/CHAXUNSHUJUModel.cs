using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ManageSystem.Model
{
    class CHAXUNSHUJUModel : NotificationObject
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
        private string _Chaxunhaoma;
        public string Chaxunhaoma
        {
            get
            {
                return _Chaxunhaoma;
            }
            set
            {
                _Chaxunhaoma = value;
                this.RaisePropertyChanged("Chaxunhaoma");
            }
        }
        private string _Chaxunleixing;
        public string Chaxunleixing
        {
            get
            {
                return _Chaxunleixing;
            }
            set
            {
                _Chaxunleixing = value;
                this.RaisePropertyChanged("Chaxunleixing");
            }
        }
        private bool _Shifouchaxunchenggong;
        public bool Shifouchaxunchenggong
        {
            get
            {
                return _Shifouchaxunchenggong;
            }
            set
            {
                _Shifouchaxunchenggong = value;
                this.RaisePropertyChanged("Shifouchaxunchenggong");
            }
        }
    }
}
