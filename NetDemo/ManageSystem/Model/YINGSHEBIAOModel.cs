using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ManageSystem.Model
{
   public  class YINGSHEBIAOModel : NotificationObject
    {
        private int _Bianhao;
        public int Bianhao
        {
            get
            {
                return _Bianhao;
            }
            set
            {
                _Bianhao = value;
                this.RaisePropertyChanged("Bianhao");
            }
        }

        private string _Mingcheng;
        public string Mingcheng
        {
            get
            {
                return _Mingcheng;
            }
            set
            {
                _Mingcheng = value;
                this.RaisePropertyChanged("Mingcheng");
            }
        }
    }
}
