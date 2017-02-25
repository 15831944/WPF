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
        AddDataWindow addwnd = new AddDataWindow();
        MainWindowViewModel  mainModel;
        int  _i = 0;
        public MainWindow()
        {
            InitializeComponent();
            this.Loaded +=MainWindow_Loaded;
            this.Initialized +=MainWindow_Initialized;
            mainModel = this.TryFindResource("MainWindowViewModelKey") as MainWindowViewModel;

        }

        void MainWindow_Initialized(object sender, EventArgs e)
        {
        }

        void MainWindow_Loaded(object sender, RoutedEventArgs e)
        {
            addwnd.WindowStartupLocation = System.Windows.WindowStartupLocation.CenterScreen;
            addwnd.Owner = this;
            addwnd.Show();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
           
        }

        private void _subListViewTouch_AutoGeneratingColumn(object sender, DataGridAutoGeneratingColumnEventArgs e)
        {

        }

    }
}
