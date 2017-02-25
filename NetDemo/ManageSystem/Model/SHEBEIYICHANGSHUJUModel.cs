using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ManageSystem.Model
{
    class SHEBEIYICHANGSHUJUModel : NotificationObject
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

        private string _Yichangshejimokuai;
        public string Yichangshejimokuai
        {
            get
            {
                return _Yichangshejimokuai;
            }
            set
            {
                _Yichangshejimokuai = value;
                this.RaisePropertyChanged("Yichangshejimokuai");
            }
        }

        private string _Yichangyuanyin;
        public string Yichangyuanyin
        {
            get
            {
                return _Yichangyuanyin;
            }
            set
            {
                _Yichangyuanyin = value;
                this.RaisePropertyChanged("Yichangyuanyin");
            }
        }

        private string _Yichangxiangxineirong;
        public string Yichangxiangxineirong
        {
            get
            {
                return _Yichangxiangxineirong;
            }
            set
            {
                _Yichangxiangxineirong = value;
                this.RaisePropertyChanged("Yichangxiangxineirong");
            }
        }
    }
}
