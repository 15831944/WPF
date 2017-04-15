using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ManageSystem.Model
{
    public class RUANJIANBAOModel : NotificationObject
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

        private string _Banbenhao;
        public string Banbenhao
        {
            get
            {
                return _Banbenhao;
            }
            set
            {
                _Banbenhao = value;
                this.RaisePropertyChanged("Banbenhao");
            }
        }

        private Byte[] _Anzhuangbao;
        public Byte[] Anzhuangbao
        {
            get
            {
                return _Anzhuangbao;
            }
            set
            {
                _Anzhuangbao = value;
                this.RaisePropertyChanged("Anzhuangbao");
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
}
