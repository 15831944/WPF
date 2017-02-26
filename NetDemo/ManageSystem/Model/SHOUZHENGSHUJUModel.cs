using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ManageSystem.Model
{
    class SHOUZHENGSHUJUModel : NotificationObject
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

        private string _Zhengjianleixing;
        public string Zhengjianleixing
        {
            get
            {
                return _Zhengjianleixing;
            }
            set
            {
                _Zhengjianleixing = value;
                this.RaisePropertyChanged("Zhengjianleixing");
            }
        }

        private string _Zhengjianhaoma;
        public string Zhengjianhaoma
        {
            get
            {
                return _Zhengjianhaoma;
            }
            set
            {
                _Zhengjianhaoma = value;
                this.RaisePropertyChanged("Zhengjianhaoma");
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

        private string _Shoulibianhao;
        public string Shoulibianhao
        {
            get
            {
                return _Shoulibianhao;
            }
            set
            {
                _Shoulibianhao = value;
                this.RaisePropertyChanged("Shoulibianhao");
            }
        }

        private bool _Shifoujiaofei;
        public bool Shifoujiaofei
        {
            get
            {
                return _Shifoujiaofei;
            }
            set
            {
                _Shifoujiaofei = value;
                this.RaisePropertyChanged("Shifoujiaofei");
            }
        }
    }
}
