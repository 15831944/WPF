using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ManageSystem.Model
{
   public  class YUSHOULISHUJUModel : NotificationObject
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

        private string _Qianzhuzhonglei;
        public string Qianzhuzhonglei
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

        private string _Xingbie;
        public string Xingbie
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
        private string _Shenfenzhenghao;
        public string Shenfenzhenghao
        {
            get
            {
                return _Shenfenzhenghao;
            }
            set
            {
                _Shenfenzhenghao = value;
                this.RaisePropertyChanged("Shenfenzhenghao");
            }
        }
        private bool _Shifoucharudajizhong;
        public bool Shifoucharudajizhong
        {
            get
            {
                return _Shifoucharudajizhong;
            }
            set
            {
                _Shifoucharudajizhong = value;
                this.RaisePropertyChanged("Shifoucharudajizhong");
            }
        }
    }
}
