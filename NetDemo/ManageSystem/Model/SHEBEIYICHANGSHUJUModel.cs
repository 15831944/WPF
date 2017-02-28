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

        private string _Yichangleixing;
        public string Yichangleixing
        {
            get
            {
                return _Yichangleixing;
            }
            set
            {
                _Yichangleixing = value;
                this.RaisePropertyChanged("Yichangleixing");
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
