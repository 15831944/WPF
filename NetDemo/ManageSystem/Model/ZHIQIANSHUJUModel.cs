using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ManageSystem.Model
{
    class ZHIQIANSHUJUModel : NotificationObject
    {
        private string  _Xuhao;
        public string   Xuhao
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

        private string  _Riqi;
        public string   Riqi
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
        private string  _ShebeiIP;
        public string   ShebeiIP
        {
            get
            {
                return _ShebeiIP;
            }
            set
            {
                _ShebeiIP = value;
                this.RaisePropertyChanged("ShebeiIP");
            }
        }
        private string  _Yewubianhao;
        public string   Yewubianhao
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
        private string  _YuanZhengjianhaoma;
        public string   YuanZhengjianhaoma
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
        private string  _Xingming;
        public string   Xingming
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
        private string  _Qianzhuzhonglei;
        public string   Qianzhuzhonglei
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
        private string  _ZhikaZhuangtai;
        public string   ZhikaZhuangtai
        {
            get
            {
                return _ZhikaZhuangtai;
            }
            set
            {
                _ZhikaZhuangtai = value;
                this.RaisePropertyChanged("ZhikaZhuangtai");
            }
        }
        private string  _Zhengjianhaoma;
        public string   Zhengjianhaoma
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
        private string  _Jiekoufanhuijieguo;
        public string   Jiekoufanhuijieguo
        {
            get
            {
                return _Jiekoufanhuijieguo;
            }
            set
            {
                _Jiekoufanhuijieguo = value;
                this.RaisePropertyChanged("Jiekoufanhuijieguo");
            }
        }

        private string  _Lianxidianhua;
        public string   Lianxidianhua
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
    }
}
