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

        private int _Chengshibianhao;
        public int Chengshibianhao
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

        private int _Jubianhao;
        public int Jubianhao
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

        private int _Shiyongdanweibianhao;
        public int Shiyongdanweibianhao
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

        private int _IP;
        public int IP
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

        private int _Shebeibaifangweizhi;
        public int Shebeibaifangweizhi
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

        private Int64 _Riqi;
        public Int64 Riqi
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
        private Int64 _Jiaoyiriqi;
        public Int64 Jiaoyiriqi
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
