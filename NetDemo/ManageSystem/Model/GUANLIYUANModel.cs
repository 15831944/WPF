using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ManageSystem.Model
{
    class GUANLIYUANModel : NotificationObject
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

        private string _Yonghuming;
        public string Yonghuming
        {
            get
            {
                return _Yonghuming;
            }
            set
            {
                _Yonghuming = value;
                this.RaisePropertyChanged("Yonghuming");
            }
        }

        private string _Mima;
        public string Mima
        {
            get
            {
                return _Mima;
            }
            set
            {
                _Mima = value;
                this.RaisePropertyChanged("Mima");
            }
        }

        private string _Youxiaoqikaishi;
        public string Youxiaoqikaishi
        {
            get
            {
                return _Youxiaoqikaishi;
            }
            set
            {
                _Youxiaoqikaishi = value;
                this.RaisePropertyChanged("Youxiaoqikaishi");
            }
        }

        private string _Youxiaoqijieshu;
        public string Youxiaoqijieshu
        {
            get
            {
                return _Youxiaoqijieshu;
            }
            set
            {
                _Youxiaoqijieshu = value;
                this.RaisePropertyChanged("Youxiaoqijieshu");
            }
        }

        private string _Quanxianjibie;
        public string Quanxianjibie
        {
            get
            {
                return _Quanxianjibie;
            }
            set
            {
                _Quanxianjibie = value;
                this.RaisePropertyChanged("Quanxianjibie");
            }
        }
    }
}
