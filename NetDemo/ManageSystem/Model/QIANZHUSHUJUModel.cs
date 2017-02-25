using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ManageSystem.Model
{
    class QIANZHUSHUJUModel : NotificationObject
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

        private int _Xingbie;
        public int Xingbie
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

        private Int64 _Chushengriqi;
        public Int64 Chushengriqi
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

        private int _Yewuleixing;
        public int Yewuleixing
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
