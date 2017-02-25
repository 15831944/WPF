using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ManageSystem.Model
{
    class CHAXUNSHUJUModel : NotificationObject
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

        private Int64 _Chuangjianshijian;
        public Int64 Chuangjianshijian
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
    }
}
