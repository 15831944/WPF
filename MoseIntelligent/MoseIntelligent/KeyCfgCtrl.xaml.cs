using Microsoft.Win32;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Data;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace MoseIntelligent
{
    /// <summary>
    /// KeyCfgCtrl.xaml 的交互逻辑
    /// </summary>
    public partial class KeyCfgCtrl : UserControl
    {
        public MainWindow.DelegateCreateSerialData80 _CreateSerial80;
        public MainWindow.DelegateWriteSerialPortData _WriteDelegate;      //向串口中写数据

        List<SubListItemInfo> _serialPortList = new List<SubListItemInfo>();
        ShortCutInfo _shortCutInfoTemp = new ShortCutInfo();

        public KeyCfgCtrl()
        {
            InitializeComponent();

        }
        void ChangeInputLanguage()
        {
            //改变当前输入法为英文的。
            if (InputLanguageManager.Current.CurrentInputLanguage.Name.StartsWith("en"))
            {
                return;
            }
            foreach (var lang in InputLanguageManager.Current.AvailableInputLanguages)
            {
                var langCultureInfo = lang as CultureInfo;
                if (langCultureInfo.Name.StartsWith("en"))
                {
                    InputLanguageManager.Current.CurrentInputLanguage = langCultureInfo;
                    break;
                }
            }
        }

        private void _textbox2_PreviewKeyDown(object sender, KeyEventArgs e)
        {
            TextBox textbox = sender as TextBox;
            if (e.Key == Key.LeftCtrl   || 
                e.Key == Key.LeftShift  ||
                e.Key == Key.LeftAlt    ||
                e.Key == Key.RightCtrl  ||
                e.Key == Key.RightShift ||
                e.Key == Key.RightAlt   
                )  //如果现在有这三个键按下
            {
                e.Handled = true;
            }
            else
            {
                if (e.Key == Key.Back)
                {
                    if (_shortCutInfoTemp.key1 != 0)
                    {
                        _shortCutInfoTemp.Control1 = false;
                        _shortCutInfoTemp.Shift1 = false;
                        _shortCutInfoTemp.Alt1 = false;
                        _shortCutInfoTemp.key1 = 0;

                        string key1str = "";
                        if (_shortCutInfoTemp.Control0)
                            key1str += "Ctrl" + "+";
                        if (_shortCutInfoTemp.Shift0)
                            key1str += "Shift" + "+";
                        if (_shortCutInfoTemp.Alt0)
                            key1str += "Alt" + "+";
                        key1str += _shortCutInfoTemp.key0;

                        textbox.Text = key1str;//1字符串
                        textbox.SelectionStart = textbox.Text.Length;
                        e.Handled = true;
                    }
                    else if (_shortCutInfoTemp.key0 != 0)
                    {
                        _shortCutInfoTemp.Control0 = false; _shortCutInfoTemp.Control1 = false;
                        _shortCutInfoTemp.Shift0 = false; _shortCutInfoTemp.Shift1 = false;
                        _shortCutInfoTemp.Alt0 = false; _shortCutInfoTemp.Alt1 = false;
                        _shortCutInfoTemp.key0 = Key.None; _shortCutInfoTemp.key1 = Key.None;

                        e.Handled = true;
                        textbox.Text = "";//置空
                        textbox.SelectionStart = textbox.Text.Length;
                    }
                    return;
                }
                string text = textbox.Text;
                foreach (int keyValue in Enum.GetValues(typeof(Key)))
                {
                    if (keyValue == Convert.ToInt32(e.Key))
                    {
                        if (_shortCutInfoTemp.key0 != 0)//已经有了一个组合了
                        {
                            if ((e.KeyboardDevice.Modifiers & ModifierKeys.Control) == ModifierKeys.Control ||
                                (e.KeyboardDevice.Modifiers & ModifierKeys.Shift) == ModifierKeys.Shift ||
                                (e.KeyboardDevice.Modifiers & ModifierKeys.Alt) == ModifierKeys.Alt)  //如果现在有这三个键按下
                            {
                                if (_shortCutInfoTemp.Control0 || _shortCutInfoTemp.Shift0 || _shortCutInfoTemp.Alt0)//之前的组合如果有这三个键则继续//第一个组合已经包含了三个键之一
                                {
                                    if (_shortCutInfoTemp.key1 == 0)    //为0则赋值
                                    {
                                        string key2str = "";
                                        if (_shortCutInfoTemp.Control1 = (Keyboard.IsKeyDown(Key.LeftCtrl) || Keyboard.IsKeyDown(Key.RightCtrl)))
                                            key2str += "Ctrl" + "+";
                                        if (_shortCutInfoTemp.Shift1 = (Keyboard.IsKeyDown(Key.LeftShift) || Keyboard.IsKeyDown(Key.RightShift)))
                                            key2str += "Shift" + "+";
                                        if (_shortCutInfoTemp.Alt1 = (Keyboard.IsKeyDown(Key.LeftAlt) || Keyboard.IsKeyDown(Key.RightAlt)))
                                            key2str += "Alt" + "+";
                                        key2str += e.Key;
                                        _shortCutInfoTemp.key1 = e.Key;

                                        text += "," + key2str; //覆盖2
                                    }
                                    else//不为0则替换
                                    {
                                        //更新内存
                                        _shortCutInfoTemp.Control0 = false; _shortCutInfoTemp.Control1 = false;
                                        _shortCutInfoTemp.Shift0 = false; _shortCutInfoTemp.Shift1 = false;
                                        _shortCutInfoTemp.Alt0 = false; _shortCutInfoTemp.Alt1 = false;
                                        _shortCutInfoTemp.key0 = Key.None; _shortCutInfoTemp.key1 = Key.None;

                                        string key3str = "";
                                        if (_shortCutInfoTemp.Control0 = (Keyboard.IsKeyDown(Key.LeftCtrl) || Keyboard.IsKeyDown(Key.RightCtrl)))
                                            key3str += "Ctrl" + "+";
                                        if (_shortCutInfoTemp.Shift0 = (Keyboard.IsKeyDown(Key.LeftShift) || Keyboard.IsKeyDown(Key.RightShift)))
                                            key3str += "Shift" + "+";
                                        if (_shortCutInfoTemp.Alt0 = (Keyboard.IsKeyDown(Key.LeftAlt) || Keyboard.IsKeyDown(Key.RightAlt)))
                                            key3str += "Alt" + "+";
                                        key3str += e.Key;
                                        _shortCutInfoTemp.key0 = e.Key;

                                        text = key3str;//替换从1开始
                                    }
                                }
                                else//之前的组合如果没有这三个键则把前面的冲掉
                                {
                                    string key1str = "";
                                    if (_shortCutInfoTemp.Control0 = (Keyboard.IsKeyDown(Key.LeftCtrl) || Keyboard.IsKeyDown(Key.RightCtrl)))
                                        key1str += "Ctrl" + "+";
                                    if (_shortCutInfoTemp.Shift0 = (Keyboard.IsKeyDown(Key.LeftShift) || Keyboard.IsKeyDown(Key.RightShift)))
                                        key1str += "Shift" + "+";
                                    if (_shortCutInfoTemp.Alt0 = (Keyboard.IsKeyDown(Key.LeftAlt) || Keyboard.IsKeyDown(Key.RightAlt)))
                                        key1str += "Alt" + "+";
                                    key1str += e.Key;
                                    _shortCutInfoTemp.key0 = e.Key;

                                    text = key1str;//覆盖1
                                }
                            }
                            else//现在没有这三个键按下 而第一个键已经有了
                            {
                                if (_shortCutInfoTemp.key1 == 0)    //为0则赋值
                                {
                                    string key2str = "";
                                    if (_shortCutInfoTemp.Control1 = (Keyboard.IsKeyDown(Key.LeftCtrl) || Keyboard.IsKeyDown(Key.RightCtrl)))
                                        key2str += "Ctrl" + "+";
                                    if (_shortCutInfoTemp.Shift1 = (Keyboard.IsKeyDown(Key.LeftShift) || Keyboard.IsKeyDown(Key.RightShift)))
                                        key2str += "Shift" + "+";
                                    if (_shortCutInfoTemp.Alt1 = (Keyboard.IsKeyDown(Key.LeftAlt) || Keyboard.IsKeyDown(Key.RightAlt)))
                                        key2str += "Alt" + "+";
                                    key2str += e.Key;
                                    _shortCutInfoTemp.key1 = e.Key;

                                    text += "," + key2str; //覆盖2
                                }
                                else//不为0则替换
                                {
                                    //更新内存
                                    _shortCutInfoTemp.Control0 = false; _shortCutInfoTemp.Control1 = false;
                                    _shortCutInfoTemp.Shift0 = false; _shortCutInfoTemp.Shift1 = false;
                                    _shortCutInfoTemp.Alt0 = false; _shortCutInfoTemp.Alt1 = false;
                                    _shortCutInfoTemp.key0 = Key.None; _shortCutInfoTemp.key1 = Key.None;

                                    string key3str = "";
                                    if (_shortCutInfoTemp.Control0 = (Keyboard.IsKeyDown(Key.LeftCtrl) || Keyboard.IsKeyDown(Key.RightCtrl)))
                                        key3str += "Ctrl" + "+";
                                    if (_shortCutInfoTemp.Shift0 = (Keyboard.IsKeyDown(Key.LeftShift) || Keyboard.IsKeyDown(Key.RightShift)))
                                        key3str += "Shift" + "+";
                                    if (_shortCutInfoTemp.Alt0 = (Keyboard.IsKeyDown(Key.LeftAlt) || Keyboard.IsKeyDown(Key.RightAlt)))
                                        key3str += "Alt" + "+";
                                    key3str += e.Key;
                                    _shortCutInfoTemp.key0 = e.Key;

                                    text = key3str;//替换从1开始
                                }
                            }
                        }
                        else //第一个键还不存在
                        {
                            string key1str = "";
                            if (_shortCutInfoTemp.Control0 = (Keyboard.IsKeyDown(Key.LeftCtrl) || Keyboard.IsKeyDown(Key.RightCtrl)))
                                key1str += "Ctrl" + "+";
                            if (_shortCutInfoTemp.Shift0 = (Keyboard.IsKeyDown(Key.LeftShift) || Keyboard.IsKeyDown(Key.RightShift)))
                                key1str += "Shift" + "+";
                            if (_shortCutInfoTemp.Alt0 = (Keyboard.IsKeyDown(Key.LeftAlt) || Keyboard.IsKeyDown(Key.RightAlt)))
                                key1str += "Alt" + "+";
                            key1str += e.Key;
                            _shortCutInfoTemp.key0 = e.Key;

                            text = key1str;//覆盖1
                        }
                        break;
                    }
                }
                textbox.Text = text;
                textbox.SelectionStart = textbox.Text.Length;
                e.Handled = true;
            }
        }

        private void taskCombo_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            ComboBox box = sender as ComboBox;
            ShortCutInfo oldInfo = box.DataContext as ShortCutInfo;
            ObservableCollection<ShortCutInfo> userShortcutMap = null;

            DataGrid dataGrid = GlobalConfig.GetParentObject<DataGrid>(box, "_subListViewTouch");//查找第一列的Textbox
            if (dataGrid == null)
                dataGrid = GlobalConfig.GetParentObject<DataGrid>(box, "_subListViewPress");//查找第一列的Textbox

            userShortcutMap = dataGrid.ItemsSource as ObservableCollection<ShortCutInfo>;

            foreach(ShortCutInfo info in userShortcutMap)
            {
                if(info.AppShowName == box.SelectedValue)
                {
                    box.SelectedValue = oldInfo.AppShowName;
                }
            }
            if (box.SelectedValue != null)
                _shortCutInfoTemp.AppShowName = box.SelectedValue as string;
        }

        private void _subListView_RowEditEnding(object sender, DataGridRowEditEndingEventArgs e)
        {
            DataGrid dataGrid = sender as DataGrid;
            ObservableCollection<ShortCutInfo> userShortcutMap = dataGrid.ItemsSource as ObservableCollection<ShortCutInfo>;

            //TextBlock textBlock0 = GlobalConfig.GetChildObject<TextBlock>(dataGrid.ContainerFromElement(e.Row), "TextBlock0");//查找第一列的Textbox

            if (e.Row.IsNewItem || e.Row.IsEditing)
            {
                if (_shortCutInfoTemp.AppShowName == null || _shortCutInfoTemp.AppShowName == "" || _shortCutInfoTemp.ShortCutString == null || _shortCutInfoTemp.ShortCutString == "")
                {
                    ShortCutInfo sInfo = e.Row.DataContext as ShortCutInfo;

                    sInfo.Empty();
                    if (e.Row.IsNewItem)
                        userShortcutMap.Remove(sInfo);
                    else if (e.Row.IsEditing)
                        e.Cancel = true;
                }
                else
                {
//                     if (textBlock0 != null)
//                     {
                        string str1 = _shortCutInfoTemp.AppShowName;
                        string str2 = _shortCutInfoTemp.ShortCutString;
                        KeyTreeNodeTag tag = dataGrid.Tag as KeyTreeNodeTag;

                        string processPath = ShortCutInfo._computerApps[str1];//应包含应用程序显示名称
                        if (processPath.Length != 0)
                        {
                            _shortCutInfoTemp.AppShowName = str1;
                            ushort appID = 0xffff;
                            foreach (KeyValuePair<ushort, string> kvp in ShortCutInfo._constSuportApps) //路径中应包含相应的EXE
                            {
                                if (kvp.Value.Length > 0 && processPath.Contains(kvp.Value))
                                {
                                    appID = kvp.Key;
                                    break;
                                }
                            }

                            if (_CreateSerial80 != null && _WriteDelegate != null)
                            {
                                byte[] data = _CreateSerial80(_shortCutInfoTemp.Control0, _shortCutInfoTemp.Shift0, _shortCutInfoTemp.Alt0, Convert.ToByte(_shortCutInfoTemp.key0),
                                    _shortCutInfoTemp.Control1, _shortCutInfoTemp.Shift1, _shortCutInfoTemp.Alt1, Convert.ToByte(_shortCutInfoTemp.key1),
                                    appID, 0, tag.keyType
                                    );

                                if (_WriteDelegate(data))//对于记录应用信息只需保存安装目录即可
                                {
                                    //textBlock0.Text = " ";
                                }
                                else
                                {
                                    ShortCutInfo sInfo = e.Row.DataContext as ShortCutInfo;

                                    sInfo.Empty();
                                    if (e.Row.IsNewItem)
                                        userShortcutMap.Remove(sInfo);
                                    else if (e.Row.IsEditing)
                                        e.Cancel = true;
                                    dataGrid.UpdateLayout();
                                }
                            }
 /*                       }*/
                    }
                }
            }
        }

        private void _subListView_BeginningEdit(object sender, DataGridBeginningEditEventArgs e)
        {
            if (e.Column.DisplayIndex <= 0) //第0列即使进入编辑状态，TextBlock也不能编辑
            {
                e.Cancel = true;
                return;
            }
            _shortCutInfoTemp = e.Row.DataContext as ShortCutInfo;
            ChangeInputLanguage();
        }

        private void TextBlock_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {//点击第0列
            //DataGridRow row = _subListView.SelectedItem as DataGridRow;
        }

        private void TextBlock_MouseEnter(object sender, MouseEventArgs e)
        {
            Cursor = Cursors.Hand;
        }

        private void TextBlock_MouseLeave(object sender, MouseEventArgs e)
        {
            Cursor = Cursors.Arrow;
        }

        private void _subListView_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            _subListViewTouch.CommitEdit(DataGridEditingUnit.Row, true);  //点南其它地方时要提交编辑
            _subListViewPress.CommitEdit(DataGridEditingUnit.Row, true);  //点南其它地方时要提交编辑
        }

        private void _subListView_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            //DataGrid dataGrid = sender as DataGrid;
            //DataGridRow row = dataGrid.ItemContainerGenerator.ContainerFromItem(dataGrid.Items[dataGrid.SelectedIndex]) as DataGridRow;
            //row.Background = Brushes.Green;
            //dataGrid.RowBackground = Brushes.Green;
        }
    }
}
