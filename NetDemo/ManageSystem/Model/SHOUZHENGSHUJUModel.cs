﻿using System;
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

        private int _Zhengjianleixing;
        public int Zhengjianleixing
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
