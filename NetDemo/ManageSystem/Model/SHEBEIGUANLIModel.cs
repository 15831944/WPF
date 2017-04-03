using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ManageSystem.Model
{
   public enum OperateModelEnum
   {
       OperateModel_None,
       OperateModel_Modify,
       OperateModel_UserModify,
       OperateModel_Upgrade,
       OperateModel_TestSpeed
   }
   public  class OperateInfoModel : NotificationObject
   {
       private OperateModelEnum _operatemodel;
       public OperateModelEnum operatemodel
       {
           get
           {
               return _operatemodel;
           }
           set
           {
               _operatemodel = value;
               this.RaisePropertyChanged("operatemodel");
           }
       }

       private string  _operatedisplayText = "选择升级版本";
       public string operatedisplayText
       {
           get { return _operatedisplayText; }
           set
           {
               _operatedisplayText = value;
               this.RaisePropertyChanged("operatedisplayText");
           }
       }

       private int _progess = 0;
       public int progess
       {
           get
           {
               return _progess;
           }
           set
           {
               _progess = value;
               this.RaisePropertyChanged("progess");
           }
       }
   }

   public  class SHEBEIGUANLIModel : NotificationObject
    {
        private bool _bSel = false;
        public bool bSel
        {
            get
            {
                return _bSel;
            }
            set
            {
                _bSel = value;
                this.RaisePropertyChanged("bSel");
            }
        }

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

        private string _Jingdu;
        public string Jingdu
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

        private string _Weidu;
        public string Weidu
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

        private OperateInfoModel _operateinfomodel = new OperateInfoModel();
        public OperateInfoModel operateinfomodel
        {
            get
            {
                return _operateinfomodel;
            }
            set
            {
                _operateinfomodel = value;
                this.RaisePropertyChanged("operateinfomodel");
            }
        }
    }
}
