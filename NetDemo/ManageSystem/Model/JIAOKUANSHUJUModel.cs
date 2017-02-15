using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ManageSystem.Model
{
    class JIAOKUANSHUJUModel : NotificationObject
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
        private string _Zhishoudanweidaima;
        public string Zhishoudanweidaima
        {
            get
            {
                return _Zhishoudanweidaima;
            }
            set
            {
                _Zhishoudanweidaima = value;
                this.RaisePropertyChanged("Zhishoudanweidaima");
            }
        }
        private string _Jiaokuantongzhishuhaoma;
        public string Jiaokuantongzhishuhaoma
        {
            get
            {
                return _Jiaokuantongzhishuhaoma;
            }
            set
            {
                _Jiaokuantongzhishuhaoma = value;
                this.RaisePropertyChanged("Jiaokuantongzhishuhaoma");
            }
        }
        private string _Jiaokuanrenxingming;
        public string Jiaokuanrenxingming
        {
            get
            {
                return _Jiaokuanrenxingming;
            }
            set
            {
                _Jiaokuanrenxingming = value;
                this.RaisePropertyChanged("Jiaokuanrenxingming");
            }
        }
        private float _Yingkoukuanheji;
        public float Yingkoukuanheji
        {
            get
            {
                return _Yingkoukuanheji;
            }
            set
            {
                _Yingkoukuanheji = value;
                this.RaisePropertyChanged("Yingkoukuanheji");
            }
        }
        private string _Jiaoyiriqi;
        public string Jiaoyiriqi
        {
            get
            {
                return _Jiaoyiriqi;
            }
            set
            {
                _Jiaoyiriqi = value;
                this.RaisePropertyChanged("Jiaoyiriqi");
            }
        }
    }
}
