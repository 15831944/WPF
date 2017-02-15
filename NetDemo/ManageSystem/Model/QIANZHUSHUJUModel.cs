using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ManageSystem.Model
{
    class QIANZHUSHUJUModel : NotificationObject
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
        private string _YuanZhengjianhaoma;
        public string YuanZhengjianhaoma
        {
            get
            {
                return _YuanZhengjianhaoma;
            }
            set
            {
                _YuanZhengjianhaoma = value;
                this.RaisePropertyChanged("YuanZhengjianhaoma");
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
        private string _Xingbie;
        public string Xingbie
        {
            get
            {
                return _Xingbie;
            }
            set
            {
                _Xingbie = value;
                this.RaisePropertyChanged("Xingbie");
            }
        }
        private string _Chushengriqi;
        public string Chushengriqi
        {
            get
            {
                return _Chushengriqi;
            }
            set
            {
                _Chushengriqi = value;
                this.RaisePropertyChanged("Chushengriqi");
            }
        }
        private string _Lianxidianhua;
        public string Lianxidianhua
        {
            get
            {
                return _Lianxidianhua;
            }
            set
            {
                _Lianxidianhua = value;
                this.RaisePropertyChanged("Lianxidianhua");
            }
        }
        private string _Yewuleixing;
        public string Yewuleixing
        {
            get
            {
                return _Yewuleixing;
            }
            set
            {
                _Yewuleixing = value;
                this.RaisePropertyChanged("Yewuleixing");
            }
        }
        private string _Shouliren;
        public string Shouliren
        {
            get
            {
                return _Shouliren;
            }
            set
            {
                _Shouliren = value;
                this.RaisePropertyChanged("Shouliren");
            }
        }
    }
}
