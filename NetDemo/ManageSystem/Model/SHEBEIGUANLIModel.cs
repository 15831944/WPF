using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ManageSystem.Model
{
    class SHEBEIGUANLIModel : NotificationObject
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

        private string _Shebeichangjia;
        public string Shebeichangjia
        {
            get
            {
                return _Shebeichangjia;
            }
            set
            {
                _Shebeichangjia = value;
                this.RaisePropertyChanged("Shebeichangjia");
            }
        }

        private string _Shebeimingcheng;
        public string Shebeimingcheng
        {
            get
            {
                return _Shebeimingcheng;
            }
            set
            {
                _Shebeimingcheng = value;
                this.RaisePropertyChanged("Shebeimingcheng");
            }
        }

        private string _Shebeileixing;
        public string Shebeileixing
        {
            get
            {
                return _Shebeileixing;
            }
            set
            {
                _Shebeileixing = value;
                this.RaisePropertyChanged("Shebeileixing");
            }
        }

        private float _Jingdu;
        public float Jingdu
        {
            get
            {
                return _Jingdu;
            }
            set
            {
                _Jingdu = value;
                this.RaisePropertyChanged("Jingdu");
            }
        }

        private float _Weidu;
        public float Weidu
        {
            get
            {
                return _Weidu;
            }
            set
            {
                _Weidu = value;
                this.RaisePropertyChanged("Weidu");
            }
        }

        private string _Chuangjianshijian;
        public string Chuangjianshijian
        {
            get
            {
                return _Chuangjianshijian;
            }
            set
            {
                _Chuangjianshijian = value;
                this.RaisePropertyChanged("Chuangjianshijian");
            }
        }

        private string _Yingjianxinxi;
        public string Yingjianxinxi
        {
            get
            {
                return _Yingjianxinxi;
            }
            set
            {
                _Yingjianxinxi = value;
                this.RaisePropertyChanged("Yingjianxinxi");
            }
        }

        private string _Ruanjianxinxi;
        public string Ruanjianxinxi
        {
            get
            {
                return _Ruanjianxinxi;
            }
            set
            {
                _Ruanjianxinxi = value;
                this.RaisePropertyChanged("Ruanjianxinxi");
            }
        }

        private string _Ruanjianshengjixinxi;
        public string Ruanjianshengjixinxi
        {
            get
            {
                return _Ruanjianshengjixinxi;
            }
            set
            {
                _Ruanjianshengjixinxi = value;
                this.RaisePropertyChanged("Ruanjianshengjixinxi");
            }
        }
    }
}
