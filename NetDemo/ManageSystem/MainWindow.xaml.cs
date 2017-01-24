using ManageSystem.ViewModel;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace ManageSystem
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        MainWindowViewModel  mainModel;
        int  _i = 0;
        public MainWindow()
        {
            InitializeComponent();

            mainModel = this.TryFindResource("MainWindowViewModelKey") as MainWindowViewModel;
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
             mainModel._HomePageViewModel.bShowPage=mainModel._HomePageViewModel.bShowPage==Visibility.Visible?Visibility.Hidden:Visibility.Visible;
            //mainModel.bShowPage2 = Visibility.Collapsed;
            //mainModel.bShowPage3 = Visibility.Collapsed;
            //mainModel.bShowPage4 = Visibility.Collapsed;
            //mainModel.bShowPage5 = Visibility.Collapsed;
            //mainModel.bShowPage6 = Visibility.Collapsed;
            //mainModel.bShowPage7 = Visibility.Collapsed;
            object data = content1.DataContext;

            //content1.Visibility = mainModel._HomePageViewModel.bShowPage;
            //content2.Visibility = Visibility.Hidden;
            //content3.Visibility = Visibility.Hidden;
            //content4.Visibility = Visibility.Hidden;
            //content5.Visibility = Visibility.Hidden;
            //content6.Visibility = Visibility.Hidden;
            //content7.Visibility = Visibility.Hidden;
            //switch (_i)
            //{
            //    case 0:
            //content1.Visibility = Visibility.Visible;
            //        break;
            //    case 1:
            //content2.Visibility = Visibility.Visible;
            //        break;
            //    case 2:
            //content3.Visibility = Visibility.Visible;
            //        break;
            //    case 3:
            //content4.Visibility = Visibility.Visible;
            //        break;
            //    case 4:
            //content5.Visibility = Visibility.Visible;
            //        break;
            //    case 5:
            //content6.Visibility = Visibility.Visible;
            //        break;
            //    case 6:
            //        content7.Visibility = Visibility.Visible;
            //        break;

            //}
            //_i++;
        }

    }
}
