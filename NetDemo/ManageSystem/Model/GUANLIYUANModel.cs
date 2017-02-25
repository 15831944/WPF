using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ManageSystem.Model
{
    class GUANLIYUANModel : NotificationObject
    {
        private int _Xuhao;
        public int Xuhao
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

        private int _Riqi;
        public int Riqi
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

        private string _Caozuoleibie;
        public string Caozuoleibie
        {
            get
            {
                return _Caozuoleibie;
            }
            set
            {
                _Caozuoleibie = value;
                this.RaisePropertyChanged("Caozuoleibie");
            }
        }

        private string _Caozuoneirong;
        public string Caozuoneirong
        {
            get
            {
                return _Caozuoneirong;
            }
            set
            {
                _Caozuoneirong = value;
                this.RaisePropertyChanged("Caozuoneirong");
            }
        }
    }
}
