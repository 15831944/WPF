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

    public class DataGridItemSourceConvert : IValueConverter
    {
        #region IValueConverter 成员
        public object Convert(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            string str = value.GetType().ToString();
            if (value.GetType() == typeof(DataGrid))
            {
                DataGrid grid = value as DataGrid;

                string strtype = grid.DataContext.GetType().ToString();
                if (grid.DataContext.GetType() == typeof(SignQueryViewModel))
                {
                    SignQueryViewModel model = grid.DataContext as SignQueryViewModel;
                    grid.AutoGeneratingColumn += model.DG1_AutoGeneratingColumn;

                    return model.tableList;
                }
                else if (grid.DataContext.GetType() == typeof(CardQueryViewModel))
                {
                    CardQueryViewModel model = grid.DataContext as CardQueryViewModel;
                    grid.AutoGeneratingColumn += model.DG1_AutoGeneratingColumn;    

                    return model.tableList;
                }
                else if (grid.DataContext.GetType() == typeof(EndorsementQueryViewModel))
                {
                    EndorsementQueryViewModel model = grid.DataContext as EndorsementQueryViewModel;
                    grid.AutoGeneratingColumn += model.DG1_AutoGeneratingColumn;

                    return model.tableList;
                }
                else if (grid.DataContext.GetType() == typeof(PaymentQueryViewModel))
                {
                    PaymentQueryViewModel model = grid.DataContext as PaymentQueryViewModel;
                    grid.AutoGeneratingColumn += model.DG1_AutoGeneratingColumn;

                    return model.tableList;
                }
                else if (grid.DataContext.GetType() == typeof(QueryQueryViewModel))
                {
                    QueryQueryViewModel model = grid.DataContext as QueryQueryViewModel;
                    grid.AutoGeneratingColumn += model.DG1_AutoGeneratingColumn;

                    return model.tableList;
                }
                else if (grid.DataContext.GetType() == typeof(PreAcceptQueryViewModel))
                {
                    PreAcceptQueryViewModel model = grid.DataContext as PreAcceptQueryViewModel;
                    grid.AutoGeneratingColumn += model.DG1_AutoGeneratingColumn;

                    return model.tableList;
                }
            }

            return null;
        }
        public object ConvertBack(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            return null;
        }
        #endregion
    }

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


        public DelegateCommand<object>                  ExitCommand { get; set; }
        public DelegateCommand<object>                  MaxCommand { get; set; }
        public DelegateCommand<object>                  MinCommand { get; set; }
        public DelegateCommand<object>                  DragWndCommand { get; set; }
        public DelegateCommand<RoutedEventArgs>         DoubleClickCommand {get; set; }

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

        private WindowState _wndState;
        public WindowState wndState
        {
            get { return _wndState; }
            set
            {
                _wndState = value;
                this.RaisePropertyChanged("wndState");
            }
        }
        private double _titleheight;
        public double titleheight
        {
            get { return _titleheight; }
            set
            {
                _titleheight = value;
                this.RaisePropertyChanged("titleheight");
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

            ExitCommand                                 = new DelegateCommand<object>(new Action<object>(this.ExitWnd));
            MaxCommand                                  = new DelegateCommand<object>(new Action<object>(this.MaxWnd));
            MinCommand                                  = new DelegateCommand<object>(new Action<object>(this.MinWnd));
            DragWndCommand                              = new DelegateCommand<object>(new Action<object>(this.DragWnd));
            DoubleClickCommand                          = new DelegateCommand<RoutedEventArgs>(new Action<RoutedEventArgs>(this.DoubleClickWnd));

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

            _bShowPage                                  = PageVisibleEnum.PageVisibleEnum_SignQuery;
            _titleheight                                = 18;
        }

        private void MaxWnd(object obj)
        {
            if(wndState == WindowState.Maximized)
                wndState = WindowState.Normal;
            else
                wndState = WindowState.Maximized;
        }
        private void MinWnd(object obj)
        {
            wndState = WindowState.Minimized;
        }
        public void ExitWnd(object obj)
        {
            try
            {
                System.Windows.Application.Current.Shutdown();
            }
            catch (Exception ex)
            {
            }
        }

        public void mainPageShow(object obj)
        {
            bShowPage                                   = PageVisibleEnum.PageVisibleEnum_Home;
        }

        private void SummaryStatShow(object obj)
        {
            bShowPage                                   = PageVisibleEnum.PageVisibleEnum_SummaryStat;
        }

        private void SignStatShow(object obj)
        {
            bShowPage                                   = PageVisibleEnum.PageVisibleEnum_SignStat;
        }

        private void SignAnomalyShow(object obj)
        {
            bShowPage                                   = PageVisibleEnum.PageVisibleEnum_SignAnomalyStat;
        }

        private void SignQueryShow(object obj)
        {
            bShowPage                                   = PageVisibleEnum.PageVisibleEnum_SignQuery;
        }

        private void CardQueryShow(object obj)
        {
            bShowPage                                   = PageVisibleEnum.PageVisibleEnum_CardQuery;
        }

        private void EndorsementQueryShow(object obj)
        {
            bShowPage                                   = PageVisibleEnum.PageVisibleEnum_EndorsementQuery;
        }

        private void PaymentQueryShow(object obj)
        {
            bShowPage                                   = PageVisibleEnum.PageVisibleEnum_PaymentQuery;
        }

        private void QueryQueryShow(object obj)
        {
            bShowPage                                   = PageVisibleEnum.PageVisibleEnum_QueryQuery;
        }

        private void PreAcceptQueryShow(object obj)
        {
            bShowPage                                   = PageVisibleEnum.PageVisibleEnum_PreAcceptQuery;
        }

        private void DragWnd(object obj)
        {
            Window wnd = obj as Window;
            System.Windows.Point pp = Mouse.GetPosition(wnd);//WPF方法
            if (pp.Y > 0 && pp.Y < titleheight)
                wnd.DragMove();
        }

        private void DoubleClickWnd(RoutedEventArgs e)
        {
            MouseButtonEventArgs args = e as MouseButtonEventArgs;
           if(args.ChangedButton == MouseButton.Left)
           {
               System.Windows.Point pp = Mouse.GetPosition(null);//WPF方法
               if (pp.Y > 0 && pp.Y < titleheight)
               {
                   MaxWnd(null);
               }
           }
        }
    }
}
