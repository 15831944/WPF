using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ManageSystem.Model
{
    class JIAOKUANSHUJUModel : NotificationObject
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

        private string _Chengshibianhao;
        public string Chengshibianhao
        {
            get
            {
                return _Chengshibianhao;
            }
            set
            {
                _Chengshibianhao = value;
                this.RaisePropertyChanged("Chengshibianhao");
            }
        }

        private string _Jubianhao;
        public string Jubianhao
        {
            get
            {
                return _Jubianhao;
            }
            set
            {
                _Jubianhao = value;
                this.RaisePropertyChanged("Jubianhao");
            }
        }

        private string _Shiyongdanweibianhao;
        public string Shiyongdanweibianhao
        {
            get
            {
                return _Shiyongdanweibianhao;
            }
            set
            {
                _Shiyongdanweibianhao = value;
                this.RaisePropertyChanged("Shiyongdanweibianhao");
            }
        }

        private string _IP;
        public string IP
        {
            get
            {
                return _IP;
            }
            set
            {
                _IP = value;
                this.RaisePropertyChanged("IP");
            }
        }

        private bool _Bendiyewu;
        public bool Bendiyewu
        {
            get
            {
                return _Bendiyewu;
            }
            set
            {
                _Bendiyewu = value;
                this.RaisePropertyChanged("Bendiyewu");
            }
        }

        private string _Shebeibaifangweizhi;
        public string Shebeibaifangweizhi
        {
            get
            {
                return _Shebeibaifangweizhi;
            }
            set
            {
                _Shebeibaifangweizhi = value;
                this.RaisePropertyChanged("Shebeibaifangweizhi");
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

        private bool _Jiaofeizhuangtai;
        public bool Jiaofeizhuangtai
        {
            get
            {
                return _Jiaofeizhuangtai;
            }
            set
            {
                _Jiaofeizhuangtai = value;
                this.RaisePropertyChanged("Jiaofeizhuangtai");
            }
        }
        private string _Yewubianhao;
        public string Yewubianhao
        {
            get
            {
                return _Yewubianhao;
            }
            set
            {
                _Yewubianhao = value;
                this.RaisePropertyChanged("Yewubianhao");
            }
        }
    }
}
