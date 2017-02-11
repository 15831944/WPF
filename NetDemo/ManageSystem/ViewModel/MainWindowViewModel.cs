using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using ManageSystem.Server;
using System.Windows.Data;
namespace ManageSystem.ViewModel
{
    enum PageVisibleEnum
    {
        PageVisibleEnum_Home,
        PageVisibleEnum_SummaryStat,
        PageVisibleEnum_SignStat,
        PageVisibleEnum_SignAnomalyStat,
        PageVisibleEnum_SignQuery,
        PageVisibleEnum_CardQuery,
        PageVisibleEnum_EndorsementQuery,
        PageVisibleEnum_PaymentQuery,
        PageVisibleEnum_QueryQuery,
        PageVisibleEnum_PreAcceptQuery,
    }

    //public class ShortCutInfoImageConvert : IValueConverter
    //{
    //    #region IValueConverter 成员
    //    public object Convert(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
    //    {
    //        if (value != null && value.GetType() == typeof(MainWindowViewModel))
    //            //if (value != null && value.GetType() == typeof(bool) && ((bool)value))
    //        {
    //            MainWindowViewModel model = value as MainWindowViewModel;
    //            if(model.bShowPage == PageVisibleEnum.PageVisibleEnum_Home)
    //                return Visibility.Visible;
    //            return Visibility.Hidden;
    //        }
    //        else
    //            return Visibility.Hidden;

    //        return null;
    //    }
    //    public object ConvertBack(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
    //    {
    //        string mypric = value.ToString();
    //        decimal pri;
    //        if (decimal.TryParse(mypric, System.Globalization.NumberStyles.Any, culture, out pri))
    //        {
    //            return pri;
    //        }
    //        return value;
    //    }
    //    #endregion
    //}

    class MainWindowViewModel : NotificationObject
    {
        public DelegateCommand<object>                  HomePageCommand { get; set; }
        public DelegateCommand<object>                  SummaryStatCommand { get; set; }
        public DelegateCommand<object>                  SignStatCommand { get; set; }
        public DelegateCommand<object>                  SignAnomalyStatCommand { get; set; }
        public DelegateCommand<object>                  SignQueryCommand { get; set; }
        public DelegateCommand<object>                  CardQueryCommand { get; set; }
        public DelegateCommand<object>                  EndorsementQueryCommand { get; set; }
        public DelegateCommand<object>                  PaymentQueryCommand { get; set; }
        public DelegateCommand<object>                  QueryQueryCommand { get; set; }
        public DelegateCommand<object>                  PreAcceptQueryCommand { get; set; }


        public DelegateCommand<object>                  DragWndCommand { get; set; }

        public HomePageViewModel                        _HomePageViewModel { get; set; }
        public SummaryStatModel                         _SummaryStatViewModel { get; set; }
        public SignStatViewModel                        _SignStatViewModel { get; set; }
        public SignAnomalyStatViewModel                 _SignAnomalyStatViewModel { get; set; }
        public SignQueryViewModel                       _SignQueryViewModel { get; set; }
        public CardQueryViewModel                       _CardQueryViewModel { get; set; }
        public EndorsementQueryViewModel                _EndorsementQueryViewModel { get; set; }
        public PaymentQueryViewModel                    _PaymentQueryViewModel { get; set; }
        public QueryQueryViewModel                      _QueryQueryViewModel { get; set; }
        public PreAcceptQueryViewModel                  _PreAcceptQueryViewModel { get; set; }


        private PageVisibleEnum _bShowPage;
        public PageVisibleEnum bShowPage
        {
            get { return _bShowPage; }
            set
            {
                _bShowPage = value;
                this.RaisePropertyChanged("bShowPage");
            }
        }

        public MainWindowViewModel()
        {
            HomePageCommand                             = new DelegateCommand<object>(new Action<object>(this.mainPageShow));
            SummaryStatCommand                          = new DelegateCommand<object>(new Action<object>(this.SummaryStatShow));
            SignStatCommand                             = new DelegateCommand<object>(new Action<object>(this.SignStatShow));
            SignAnomalyStatCommand                      = new DelegateCommand<object>(new Action<object>(this.SignAnomalyShow));
            SignQueryCommand                            = new DelegateCommand<object>(new Action<object>(this.SignQueryShow));
            CardQueryCommand                            = new DelegateCommand<object>(new Action<object>(this.CardQueryShow));
            EndorsementQueryCommand                     = new DelegateCommand<object>(new Action<object>(this.EndorsementQueryShow));
            PaymentQueryCommand                         = new DelegateCommand<object>(new Action<object>(this.PaymentQueryShow));
            QueryQueryCommand                           = new DelegateCommand<object>(new Action<object>(this.QueryQueryShow));
            PreAcceptQueryCommand                       = new DelegateCommand<object>(new Action<object>(this.PreAcceptQueryShow));
            DragWndCommand                              = new DelegateCommand<object>(new Action<object>(this.DragWnd));

            _HomePageViewModel                          = new HomePageViewModel();
            _SummaryStatViewModel                       = new SummaryStatModel();
            _SignStatViewModel                          = new SignStatViewModel();
            _SignAnomalyStatViewModel                   = new SignAnomalyStatViewModel();
            _SignQueryViewModel                         = new SignQueryViewModel();
            _CardQueryViewModel                         = new CardQueryViewModel();
            _EndorsementQueryViewModel                  = new EndorsementQueryViewModel();
            _PaymentQueryViewModel                      = new PaymentQueryViewModel();
            _QueryQueryViewModel                        = new QueryQueryViewModel();
            _PreAcceptQueryViewModel                    = new PreAcceptQueryViewModel();

            _bShowPage                                  = PageVisibleEnum.PageVisibleEnum_EndorsementQuery;

            _HomePageViewModel              .bShowPage                = Visibility.Hidden;
            _SummaryStatViewModel           .bShowPage                = Visibility.Hidden;
            _SignStatViewModel              .bShowPage                = Visibility.Hidden;
            _SignAnomalyStatViewModel       .bShowPage                = Visibility.Hidden;
            _SignQueryViewModel             .bShowPage                = Visibility.Hidden;
            _CardQueryViewModel             .bShowPage                = Visibility.Hidden;
            _EndorsementQueryViewModel      .bShowPage                = Visibility.Hidden;
            _PaymentQueryViewModel          .bShowPage                = Visibility.Hidden;
            _QueryQueryViewModel            .bShowPage                = Visibility.Hidden;
            _PreAcceptQueryViewModel        .bShowPage                = Visibility.Hidden;

        }


        public void mainPageShow(object obj)
        {
            bShowPage                                  = PageVisibleEnum.PageVisibleEnum_Home;
         
        }

        private void SummaryStatShow(object obj)
        {
            bShowPage                                  = PageVisibleEnum.PageVisibleEnum_SummaryStat;
        }

        private void SignStatShow(object obj)
        {
            bShowPage                                  = PageVisibleEnum.PageVisibleEnum_SignStat;
        }

        private void SignAnomalyShow(object obj)
        {
            bShowPage                                  = PageVisibleEnum.PageVisibleEnum_SignAnomalyStat;
        }

        private void SignQueryShow(object obj)
        {
            bShowPage                                  = PageVisibleEnum.PageVisibleEnum_SignQuery;
        }

        private void CardQueryShow(object obj)
        {
            bShowPage                                  = PageVisibleEnum.PageVisibleEnum_CardQuery;
        }

        private void EndorsementQueryShow(object obj)
        {
            bShowPage                                  = PageVisibleEnum.PageVisibleEnum_EndorsementQuery;
        }

        private void PaymentQueryShow(object obj)
        {
            bShowPage                                  = PageVisibleEnum.PageVisibleEnum_PaymentQuery;
        }

        private void QueryQueryShow(object obj)
        {
            bShowPage                                  = PageVisibleEnum.PageVisibleEnum_QueryQuery;
        }

        private void PreAcceptQueryShow(object obj)
        {
            bShowPage                                  = PageVisibleEnum.PageVisibleEnum_PreAcceptQuery;
        }

        private void DragWnd(object obj)
        {
            Window wnd = obj as Window;
            System.Windows.Point pp = Mouse.GetPosition(wnd);//WPF方法
            //if (pp.X > 0 && pp.X < windowWidth && pp.Y > 0 && pp.Y < 18)
                wnd.DragMove();
        }
    }
}
