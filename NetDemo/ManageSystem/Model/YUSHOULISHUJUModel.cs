using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ManageSystem.Model
{
    class YUSHOULISHUJUModel : NotificationObject
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

        private string _Chuguoshiyou;
        public string Chuguoshiyou
        {
            get
            {
                return _Chuguoshiyou;
            }
            set
            {
                _Chuguoshiyou = value;
                this.RaisePropertyChanged("Chuguoshiyou");
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

        private int _Qianzhuzhonglei;
        public int Qianzhuzhonglei
        {
            get
            {
                return _Qianzhuzhonglei;
            }
            set
            {
                _Qianzhuzhonglei = value;
                this.RaisePropertyChanged("Qianzhuzhonglei");
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

        private string _Hukousuozaidi;
        public string Hukousuozaidi
        {
            get
            {
                return _Hukousuozaidi;
            }
            set
            {
                _Hukousuozaidi = value;
                this.RaisePropertyChanged("Hukousuozaidi");
            }
        }

        private string _Minzu;
        public string Minzu
        {
            get
            {
                return _Minzu;
            }
            set
            {
                _Minzu = value;
                this.RaisePropertyChanged("Minzu");
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
