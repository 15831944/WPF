using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;

namespace ManageSystem.ViewModel
{
    class QueryViewModel : NotificationObject
    {
        private Visibility _bShowPage;
        public Visibility bShowPage
        {
            get { return _bShowPage; }
            set
            {
                _bShowPage = value;
                this.RaisePropertyChanged("bShowPage");
            }
        }
    }
}
