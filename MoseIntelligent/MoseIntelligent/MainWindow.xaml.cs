using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Diagnostics;
using System.Linq;
using System.Runtime.InteropServices;
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
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        public delegate bool DelegateWriteSerialPortData(byte[] data);
        public delegate byte[] DelegateCreateSerialData80(
            bool bCtrl0, bool bShift0, bool bAlt0, byte key0,
            bool bCtrl1, bool bShift1, bool bAlt1, byte key1,
            ushort appName, ushort randomCode, byte keyType
            );

        //窗口
        SerialPortCnt _subForm0;
        KeyCfgCtrl _subForm1;
        //三个根节点
        //三个根节点
        TreeKey touchCntNode;
        TreeKey pressCntNode;

        public MainWindow()
        {
            InitializeComponent();

            _subForm0 = new SerialPortCnt();
            Grid.SetColumn(_subForm0, 1);
            Grid.SetColumnSpan(_subForm0, 2);
            _mainGridPanel.Children.Add(_subForm0);

            _subForm1 = new KeyCfgCtrl();
            _mainGridPanelCol1.Children.Add(_subForm1);

            _subForm0.Visibility = Visibility.Visible;
            _subForm1.Visibility = Visibility.Hidden;

            _subForm0._OnOtherProcessDataCompleteDelegate = OnProcessDataCompleteEvent;
            _subForm1._WriteDelegate = WriteSerialPortData;
            _subForm1._CreateSerial80 = CreateSerialData80;
            //InitTressList();

            //Win32APIs.AnimateWindow(this.Handle, 300, Win32APIs.AW_HOR_POSITIVE);//开始窗体动画

            //List<TreeKey> keyTreeList = _mainTreeView.ItemsSource as List<TreeKey>;
            //touchCntNode = keyTreeList[1].Children[0];
            //pressCntNode = keyTreeList[1].Children[1];

        }

        private void ExpandAllItems(ItemsControl control)
        {
            if (control == null)
            {
                return;
            }

            foreach (Object item in control.Items)
            {
                System.Windows.Controls.TreeViewItem treeItem = control.ItemContainerGenerator.ContainerFromItem(item) as TreeViewItem;

                if (treeItem == null || !treeItem.HasItems)
                {
                    continue;
                }

                treeItem.IsExpanded = true;
                ExpandAllItems(treeItem as ItemsControl);
            }
        }
        private void _mainTreeView_SelectedItemChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            if(e.NewValue != null && e.NewValue.GetType() == typeof(TreeKey))
            {
                TreeKey treeKey = e.NewValue as TreeKey;
                if(treeKey.Text == "串口连接")
                {
                    _subForm0.Visibility = Visibility.Visible;
                    _subForm1.Visibility = Visibility.Hidden;
                }
                else
                {
                    _subForm0.Visibility = Visibility.Hidden;
                    _subForm1.Visibility = Visibility.Visible;
                    if(treeKey._treeTag != null)
                    {
                        _subForm1._subListViewTouch.ItemsSource = treeKey._treeTag.userShortcutMap;
                        _subForm1._subListViewTouch.Tag = treeKey._treeTag;
                    }
                }
            }
        }

        void PrintLogicalTree(int depth, object obj)
        {
            Debug.WriteLine(new string(' ', depth * 2) + obj);
            if (!(obj is DependencyObject)) return;
            foreach (object child in LogicalTreeHelper.GetChildren(obj as DependencyObject))
                PrintLogicalTree(depth + 1, child);
        }
        void PrintVisualTree(int depth, DependencyObject obj)
        {
            Debug.WriteLine(new string(' ', depth * 2) + obj);
            for (int i = 0; i < VisualTreeHelper.GetChildrenCount(obj); i++)
                PrintVisualTree(depth + 1, VisualTreeHelper.GetChild(obj, i));
        }

        private void Window_ContentRendered(object sender, EventArgs e)
        {
            //base.OnContentRendered(e);
            Debug.WriteLine("视觉树");

            //PrintVisualTree(0, this);
            //foreach(object item in _mainTreeView.Items)
            //{
            //    System.Windows.Controls.TreeViewItem treeItem = _mainTreeView.ItemContainerGenerator.ContainerFromItem(item) as TreeViewItem;
            //    treeItem.ExpandSubtree();
            //}
        }

        public bool WriteSerialPortData(byte[] data)
        {
            return _subForm0.WriteSerialData(data);
        }

        public byte[] CreateSerialData80(
            bool bCtrl0, bool bShift0, bool bAlt0, byte key0,
            bool bCtrl1, bool bShift1, bool bAlt1, byte key1,
            ushort appName, ushort randomCode, byte keyType
            )
        {
            return _subForm0.CreateSerialData80(
                bCtrl0, bShift0, bAlt0, key0,
                bCtrl1, bShift1, bAlt1, key1,
                appName, randomCode, keyType
                );
        }

        public void OnProcessDataCompleteEvent(uint flag, object result)
        {
            try
            {
                if (flag == 0x80)
                {//80帧初始化  鼠标用户定义信息初始化
                    ProcessDataComplete80(result);
                }

                if (flag == 0x26)
                {//鼠标键消息处理

                    unsafe
                    {
                        byte[] byteAry = result as byte[];
                        fixed (byte* pBuffer = &(byteAry[0]))
                        {
                            ushort keyType = *((ushort*)(pBuffer + 4));
                            ushort KeyLastTime = *((ushort*)(pBuffer + 6));
                            //if (KeyLastTime == 0)
                            {
                                IntPtr ptr = Win32APIs.GetForegroundWindow();
                                IntPtr IDPtr = Marshal.AllocHGlobal(Marshal.SizeOf(typeof(IntPtr))); ;
                                Win32APIs.GetWindowThreadProcessId(ptr, IDPtr);
                                Int32 processID = 0;
                                processID = (Int32)Marshal.PtrToStructure(IDPtr, typeof(Int32));
                                Marshal.FreeHGlobal(IDPtr);
                                //Process process = Process.GetProcessById(processID);
                                //Process process = Process.GetProcessById(processID);
                                //string processDic = Path.GetDirectoryName(process.MainModule.FileName);
                                string processExePath = _subForm0.GetProcessWorkPath(processID);
                                switch (keyType)
                                {
                                    case GlobalConfig.KEY_TOUCH_LEFT_BIT://KEY_TOUCH_LEFT  = 0x01,
                                        {
                                            PressShortCutInfoKey(processExePath, touchCntNode.Children[0]._treeTag as KeyTreeNodeTag);
                                        }
                                        break;
                                    case GlobalConfig.KEY_TOUCH_RIGHT_BIT://KEY_TOUCH_RIGHT = 0x02,
                                        {
                                            PressShortCutInfoKey(processExePath, touchCntNode.Children[1]._treeTag as KeyTreeNodeTag);
                                        }
                                        break;
                                    case GlobalConfig.KEY_TOUCH_MID_BIT://KEY_TOUCH_MID   = 0x03,
                                        {
                                            PressShortCutInfoKey(processExePath, touchCntNode.Children[2]._treeTag as KeyTreeNodeTag);
                                        }
                                        break;
                                    case GlobalConfig.KEY_TOUCH_UP_BIT://KEY_TOUCH_UP    = 0x04,
                                        {
                                            PressShortCutInfoKey(processExePath, touchCntNode.Children[3]._treeTag as KeyTreeNodeTag);
                                        }
                                        break;
                                    case GlobalConfig.KEY_TOUCH_DOWN_BIT://KEY_TOUCH_DOWN  = 0x05,
                                        {
                                            PressShortCutInfoKey(processExePath, touchCntNode.Children[4]._treeTag as KeyTreeNodeTag);
                                        }
                                        break;
                                    case GlobalConfig.KEY_PRESS_LEFT_BIT://KEY_PRESS_LEFT  = 0x11,		
                                        {
                                            PressShortCutInfoKey(processExePath, pressCntNode.Children[0]._treeTag as KeyTreeNodeTag);
                                        }
                                        break;
                                    case GlobalConfig.KEY_PRESS_RIGHT_BIT://KEY_PRESS_RIGHT = 0x12,
                                        {
                                            PressShortCutInfoKey(processExePath, pressCntNode.Children[1]._treeTag as KeyTreeNodeTag);
                                        }
                                        break;
                                    case GlobalConfig.KEY_PRESS_MID_BIT://KEY_PRESS_MID   = 0x13,
                                        {
                                            PressShortCutInfoKey(processExePath, pressCntNode.Children[2]._treeTag as KeyTreeNodeTag);
                                        }
                                        break;
                                    case GlobalConfig.KEY_PRESS_UP_BIT://KEY_PRESS_UP    = 0x14,	
                                        {
                                            PressShortCutInfoKey(processExePath, pressCntNode.Children[3]._treeTag as KeyTreeNodeTag);
                                        }
                                        break;
                                    case GlobalConfig.KEY_PRESS_DOWN_BIT://KEY_PRESS_DOWN  = 0x15
                                        {
                                            PressShortCutInfoKey(processExePath, pressCntNode.Children[4]._treeTag as KeyTreeNodeTag);
                                        }
                                        break;
                                }
                            }
                        }
                    }
                }
            }
            catch (Exception e)
            {

            }
        }
        public void ProcessDataComplete80(object result)
        {
            try
            {
                unsafe
                {
                    byte[] byteAry = result as byte[];

                    fixed (byte* pByte = &(byteAry[0]))
                    {
                        byte Ctr_Alt_Shift0 = *(pByte + 8);
                        byte Key0 = *(pByte + 9);
                        byte Ctr_Alt_Shift1 = *(pByte + 10);
                        byte Key1 = *(pByte + 11);
                        ushort AppName = *((ushort*)(pByte + 12));
                        byte KeyType = *(pByte + 16);
                        if (ShortCutInfo._constSuportApps.ContainsKey(AppName))//是否包含APPID
                        {
                            foreach (KeyValuePair<string, string> kvp in ShortCutInfo._computerApps)
                            {
                                if (kvp.Value.Contains(ShortCutInfo._constSuportApps[AppName]))//安装路径中是否包含EXE文件名称
                                {
                                    switch (KeyType)
                                    {
                                        case 0x01://KEY_TOUCH_LEFT  = 0x01,
                                            {
                                                KeyTreeNodeTag taginfo = touchCntNode.Children[0]._treeTag as KeyTreeNodeTag;
                                                bool bFind = false;
                                                foreach (ShortCutInfo info in taginfo.userShortcutMap)
                                                {
                                                    if (info.AppShowName == kvp.Key)
                                                    {
                                                        bFind = true;
                                                        break;
                                                    }
                                                }
                                                if (false == bFind)
                                                {
                                                    ShortCutInfo shortCutTemp = new ShortCutInfo();
                                                    shortCutTemp.Control0 = (Ctr_Alt_Shift0 & 0x01) != 0;
                                                    shortCutTemp.Shift0 = (Ctr_Alt_Shift0 & 0x02) != 0;
                                                    shortCutTemp.Alt0 = (Ctr_Alt_Shift0 & 0x04) != 0;
                                                    shortCutTemp.key0 = (Key)Key0;
                                                    shortCutTemp.Control1 = (Ctr_Alt_Shift1 & 0x01) != 0;
                                                    shortCutTemp.Shift1 = (Ctr_Alt_Shift1 & 0x02) != 0;
                                                    shortCutTemp.Alt1 = (Ctr_Alt_Shift1 & 0x04) != 0;
                                                    shortCutTemp.key1 = (Key)Key1;

                                                    shortCutTemp.AppShowName = kvp.Key;
                                                    taginfo.userShortcutMap.Add(shortCutTemp);
                                                }
                                            }
                                            break;
                                        case 0x02://KEY_TOUCH_RIGHT = 0x02,
                                            {
                                                KeyTreeNodeTag taginfo = touchCntNode.Children[1]._treeTag as KeyTreeNodeTag;
                                                bool bFind = false;
                                                foreach (ShortCutInfo info in taginfo.userShortcutMap)
                                                {
                                                    if (info.AppShowName == kvp.Key)
                                                    {
                                                        bFind = true;
                                                        break;
                                                    }
                                                }
                                                if (false == bFind)
                                                {
                                                    ShortCutInfo shortCutTemp = new ShortCutInfo();
                                                    shortCutTemp.Control0 = (Ctr_Alt_Shift0 & 0x01) != 0;
                                                    shortCutTemp.Shift0 = (Ctr_Alt_Shift0 & 0x02) != 0;
                                                    shortCutTemp.Alt0 = (Ctr_Alt_Shift0 & 0x04) != 0;
                                                    shortCutTemp.key0 = (Key)Key0;
                                                    shortCutTemp.Control1 = (Ctr_Alt_Shift1 & 0x01) != 0;
                                                    shortCutTemp.Shift1 = (Ctr_Alt_Shift1 & 0x02) != 0;
                                                    shortCutTemp.Alt1 = (Ctr_Alt_Shift1 & 0x04) != 0;
                                                    shortCutTemp.key1 = (Key)Key1;

                                                    shortCutTemp.AppShowName = kvp.Key;
                                                    taginfo.userShortcutMap.Add(shortCutTemp);
                                                }
                                            }
                                            break;
                                        case 0x03://KEY_TOUCH_MID   = 0x03,
                                            {
                                                KeyTreeNodeTag taginfo = touchCntNode.Children[2]._treeTag as KeyTreeNodeTag;
                                                bool bFind = false;
                                                foreach (ShortCutInfo info in taginfo.userShortcutMap)
                                                {
                                                    if (info.AppShowName == kvp.Key)
                                                    {
                                                        bFind = true;
                                                        break;
                                                    }
                                                }
                                                if (false == bFind)
                                                {
                                                    ShortCutInfo shortCutTemp = new ShortCutInfo();
                                                    shortCutTemp.Control0 = (Ctr_Alt_Shift0 & 0x01) != 0;
                                                    shortCutTemp.Shift0 = (Ctr_Alt_Shift0 & 0x02) != 0;
                                                    shortCutTemp.Alt0 = (Ctr_Alt_Shift0 & 0x04) != 0;
                                                    shortCutTemp.key0 = (Key)Key0;
                                                    shortCutTemp.Control1 = (Ctr_Alt_Shift1 & 0x01) != 0;
                                                    shortCutTemp.Shift1 = (Ctr_Alt_Shift1 & 0x02) != 0;
                                                    shortCutTemp.Alt1 = (Ctr_Alt_Shift1 & 0x04) != 0;
                                                    shortCutTemp.key1 = (Key)Key1;

                                                    shortCutTemp.AppShowName = kvp.Key;
                                                    taginfo.userShortcutMap.Add(shortCutTemp);
                                                }
                                            }
                                            break;
                                        case 0x04://KEY_TOUCH_UP    = 0x04,
                                            {
                                                KeyTreeNodeTag taginfo = touchCntNode.Children[3]._treeTag as KeyTreeNodeTag;
                                                bool bFind = false;
                                                foreach (ShortCutInfo info in taginfo.userShortcutMap)
                                                {
                                                    if (info.AppShowName == kvp.Key)
                                                    {
                                                        bFind = true;
                                                        break;
                                                    }
                                                }
                                                if (false == bFind)
                                                {
                                                    ShortCutInfo shortCutTemp = new ShortCutInfo();
                                                    shortCutTemp.Control0 = (Ctr_Alt_Shift0 & 0x01) != 0;
                                                    shortCutTemp.Shift0 = (Ctr_Alt_Shift0 & 0x02) != 0;
                                                    shortCutTemp.Alt0 = (Ctr_Alt_Shift0 & 0x04) != 0;
                                                    shortCutTemp.key0 = (Key)Key0;
                                                    shortCutTemp.Control1 = (Ctr_Alt_Shift1 & 0x01) != 0;
                                                    shortCutTemp.Shift1 = (Ctr_Alt_Shift1 & 0x02) != 0;
                                                    shortCutTemp.Alt1 = (Ctr_Alt_Shift1 & 0x04) != 0;
                                                    shortCutTemp.key1 = (Key)Key1;

                                                    shortCutTemp.AppShowName = kvp.Key;
                                                    taginfo.userShortcutMap.Add(shortCutTemp);
                                                }
                                            }
                                            break;
                                        case 0x05://KEY_TOUCH_DOWN  = 0x05,
                                            {
                                                KeyTreeNodeTag taginfo = touchCntNode.Children[4]._treeTag as KeyTreeNodeTag;
                                                bool bFind = false;
                                                foreach (ShortCutInfo info in taginfo.userShortcutMap)
                                                {
                                                    if (info.AppShowName == kvp.Key)
                                                    {
                                                        bFind = true;
                                                        break;
                                                    }
                                                }
                                                if (false == bFind)
                                                {
                                                    ShortCutInfo shortCutTemp = new ShortCutInfo();
                                                    shortCutTemp.Control0 = (Ctr_Alt_Shift0 & 0x01) != 0;
                                                    shortCutTemp.Shift0 = (Ctr_Alt_Shift0 & 0x02) != 0;
                                                    shortCutTemp.Alt0 = (Ctr_Alt_Shift0 & 0x04) != 0;
                                                    shortCutTemp.key0 = (Key)Key0;
                                                    shortCutTemp.Control1 = (Ctr_Alt_Shift1 & 0x01) != 0;
                                                    shortCutTemp.Shift1 = (Ctr_Alt_Shift1 & 0x02) != 0;
                                                    shortCutTemp.Alt1 = (Ctr_Alt_Shift1 & 0x04) != 0;
                                                    shortCutTemp.key1 = (Key)Key1;

                                                    shortCutTemp.AppShowName = kvp.Key;
                                                    taginfo.userShortcutMap.Add(shortCutTemp);
                                                }
                                            }
                                            break;
                                        case 0x11://KEY_PRESS_LEFT  = 0x11,		
                                            {
                                                KeyTreeNodeTag taginfo = touchCntNode.Children[5]._treeTag as KeyTreeNodeTag;
                                                bool bFind = false;
                                                foreach (ShortCutInfo info in taginfo.userShortcutMap)
                                                {
                                                    if (info.AppShowName == kvp.Key)
                                                    {
                                                        bFind = true;
                                                        break;
                                                    }
                                                }
                                                if (false == bFind)
                                                {
                                                    ShortCutInfo shortCutTemp = new ShortCutInfo();
                                                    shortCutTemp.Control0 = (Ctr_Alt_Shift0 & 0x01) != 0;
                                                    shortCutTemp.Shift0 = (Ctr_Alt_Shift0 & 0x02) != 0;
                                                    shortCutTemp.Alt0 = (Ctr_Alt_Shift0 & 0x04) != 0;
                                                    shortCutTemp.key0 = (Key)Key0;
                                                    shortCutTemp.Control1 = (Ctr_Alt_Shift1 & 0x01) != 0;
                                                    shortCutTemp.Shift1 = (Ctr_Alt_Shift1 & 0x02) != 0;
                                                    shortCutTemp.Alt1 = (Ctr_Alt_Shift1 & 0x04) != 0;
                                                    shortCutTemp.key1 = (Key)Key1;

                                                    shortCutTemp.AppShowName = kvp.Key;
                                                    taginfo.userShortcutMap.Add(shortCutTemp);
                                                }
                                            }
                                            break;
                                        case 0x12://KEY_PRESS_RIGHT = 0x12,
                                            {
                                                KeyTreeNodeTag taginfo = touchCntNode.Children[6]._treeTag as KeyTreeNodeTag;
                                                bool bFind = false;
                                                foreach (ShortCutInfo info in taginfo.userShortcutMap)
                                                {
                                                    if (info.AppShowName == kvp.Key)
                                                    {
                                                        bFind = true;
                                                        break;
                                                    }
                                                }
                                                if (false == bFind)
                                                {
                                                    ShortCutInfo shortCutTemp = new ShortCutInfo();
                                                    shortCutTemp.Control0 = (Ctr_Alt_Shift0 & 0x01) != 0;
                                                    shortCutTemp.Shift0 = (Ctr_Alt_Shift0 & 0x02) != 0;
                                                    shortCutTemp.Alt0 = (Ctr_Alt_Shift0 & 0x04) != 0;
                                                    shortCutTemp.key0 = (Key)Key0;
                                                    shortCutTemp.Control1 = (Ctr_Alt_Shift1 & 0x01) != 0;
                                                    shortCutTemp.Shift1 = (Ctr_Alt_Shift1 & 0x02) != 0;
                                                    shortCutTemp.Alt1 = (Ctr_Alt_Shift1 & 0x04) != 0;
                                                    shortCutTemp.key1 = (Key)Key1;

                                                    shortCutTemp.AppShowName = kvp.Key;
                                                    taginfo.userShortcutMap.Add(shortCutTemp);
                                                }
                                            }
                                            break;
                                        case 0x13://KEY_PRESS_MID   = 0x13,
                                            {
                                                KeyTreeNodeTag taginfo = touchCntNode.Children[7]._treeTag as KeyTreeNodeTag;
                                                bool bFind = false;
                                                foreach (ShortCutInfo info in taginfo.userShortcutMap)
                                                {
                                                    if (info.AppShowName == kvp.Key)
                                                    {
                                                        bFind = true;
                                                        break;
                                                    }
                                                }
                                                if (false == bFind)
                                                {
                                                    ShortCutInfo shortCutTemp = new ShortCutInfo();
                                                    shortCutTemp.Control0 = (Ctr_Alt_Shift0 & 0x01) != 0;
                                                    shortCutTemp.Shift0 = (Ctr_Alt_Shift0 & 0x02) != 0;
                                                    shortCutTemp.Alt0 = (Ctr_Alt_Shift0 & 0x04) != 0;
                                                    shortCutTemp.key0 = (Key)Key0;
                                                    shortCutTemp.Control1 = (Ctr_Alt_Shift1 & 0x01) != 0;
                                                    shortCutTemp.Shift1 = (Ctr_Alt_Shift1 & 0x02) != 0;
                                                    shortCutTemp.Alt1 = (Ctr_Alt_Shift1 & 0x04) != 0;
                                                    shortCutTemp.key1 = (Key)Key1;

                                                    shortCutTemp.AppShowName = kvp.Key;
                                                    taginfo.userShortcutMap.Add(shortCutTemp);
                                                }
                                            }
                                            break;
                                        case 0x14://KEY_PRESS_UP    = 0x14,	
                                            {
                                                KeyTreeNodeTag taginfo = touchCntNode.Children[8]._treeTag as KeyTreeNodeTag;
                                                bool bFind = false;
                                                foreach (ShortCutInfo info in taginfo.userShortcutMap)
                                                {
                                                    if (info.AppShowName == kvp.Key)
                                                    {
                                                        bFind = true;
                                                        break;
                                                    }
                                                }
                                                if (false == bFind)
                                                {
                                                    ShortCutInfo shortCutTemp = new ShortCutInfo();
                                                    shortCutTemp.Control0 = (Ctr_Alt_Shift0 & 0x01) != 0;
                                                    shortCutTemp.Shift0 = (Ctr_Alt_Shift0 & 0x02) != 0;
                                                    shortCutTemp.Alt0 = (Ctr_Alt_Shift0 & 0x04) != 0;
                                                    shortCutTemp.key0 = (Key)Key0;
                                                    shortCutTemp.Control1 = (Ctr_Alt_Shift1 & 0x01) != 0;
                                                    shortCutTemp.Shift1 = (Ctr_Alt_Shift1 & 0x02) != 0;
                                                    shortCutTemp.Alt1 = (Ctr_Alt_Shift1 & 0x04) != 0;
                                                    shortCutTemp.key1 = (Key)Key1;

                                                    shortCutTemp.AppShowName = kvp.Key;
                                                    taginfo.userShortcutMap.Add(shortCutTemp);
                                                }
                                            }
                                            break;
                                        case 0x15://KEY_PRESS_DOWN  = 0x15
                                            {
                                                KeyTreeNodeTag taginfo = touchCntNode.Children[9]._treeTag as KeyTreeNodeTag;
                                                bool bFind = false;
                                                foreach (ShortCutInfo info in taginfo.userShortcutMap)
                                                {
                                                    if (info.AppShowName == kvp.Key)
                                                    {
                                                        bFind = true;
                                                        break;
                                                    }
                                                }
                                                if (false == bFind)
                                                {
                                                    ShortCutInfo shortCutTemp = new ShortCutInfo();
                                                    shortCutTemp.Control0 = (Ctr_Alt_Shift0 & 0x01) != 0;
                                                    shortCutTemp.Shift0 = (Ctr_Alt_Shift0 & 0x02) != 0;
                                                    shortCutTemp.Alt0 = (Ctr_Alt_Shift0 & 0x04) != 0;
                                                    shortCutTemp.key0 = (Key)Key0;
                                                    shortCutTemp.Control1 = (Ctr_Alt_Shift1 & 0x01) != 0;
                                                    shortCutTemp.Shift1 = (Ctr_Alt_Shift1 & 0x02) != 0;
                                                    shortCutTemp.Alt1 = (Ctr_Alt_Shift1 & 0x04) != 0;
                                                    shortCutTemp.key1 = (Key)Key1;

                                                    shortCutTemp.AppShowName = kvp.Key;
                                                    taginfo.userShortcutMap.Add(shortCutTemp);
                                                }
                                            }
                                            break;
                                    }
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            catch (System.Exception ex)
            {
                string str = ex.Message;
            }

        }
        //hWnd 窗口句柄  //processDic 目标进程目录  //结点信息
        private void PressShortCutInfoKey(string processExePath, KeyTreeNodeTag taginfo)
        {
            foreach (ShortCutInfo info in taginfo.userShortcutMap)
            {
                string processDic = System.IO.Path.GetDirectoryName(processExePath).ToLower();    //子进程的目录要比父进程的深吧
                string processexeName = System.IO.Path.GetFileName(processExePath);

                string tempDic = System.IO.Path.GetDirectoryName(ShortCutInfo._computerApps[info.AppShowName]).ToLower();
                string tempExe = info.AppShowName;

                Debug.WriteLine(processDic);
                if (processDic.Contains(tempDic))                                       //最前的进程目录要包含定义的目录
                {
                    string sysDicX86 = Environment.GetFolderPath(Environment.SpecialFolder.SystemX86).ToLower();
                    string sysDic = Environment.GetFolderPath(Environment.SpecialFolder.System).ToLower();
                    if (processDic.Contains(sysDicX86) || processDic.Contains(sysDic))   //如果是系统进程目录内的目录的EXE则要求EXE名称必须相同
                    {
                        if (tempExe != processexeName)
                            continue;
                    }

                    if (info.key0 != 0)  //按键消息
                    {
                        if (info.Control0)
                            Win32APIs.keybd_event(Win32APIs.VK_CONTROL, 0, 0, 0);
                        if (info.Shift0)
                            Win32APIs.keybd_event(Win32APIs.VK_SHIFT, 0, 0, 0);
                        if (info.Alt0)
                            Win32APIs.keybd_event(Win32APIs.VK_MENU, 0, 0, 0);
                        Win32APIs.keybd_event(Convert.ToByte(KeyInterop.VirtualKeyFromKey(info.key0)), 0, 0, 0);
                        Win32APIs.keybd_event(Convert.ToByte(KeyInterop.VirtualKeyFromKey(info.key0)), 0, 2, 0);
                        if (info.Alt0)
                            Win32APIs.keybd_event(Win32APIs.VK_MENU, 0, 2, 0);
                        if (info.Shift0)
                            Win32APIs.keybd_event(Win32APIs.VK_SHIFT, 0, 2, 0);
                        if (info.Control0)
                            Win32APIs.keybd_event(Win32APIs.VK_CONTROL, 0, 2, 0);
                        if (info.key1 != 0)
                        {
                            if (info.Control1)
                                Win32APIs.keybd_event(Win32APIs.VK_CONTROL, 0, 0, 0);
                            if (info.Shift1)
                                Win32APIs.keybd_event(Win32APIs.VK_SHIFT, 0, 0, 0);
                            if (info.Alt1)
                                Win32APIs.keybd_event(Win32APIs.VK_MENU, 0, 0, 0);
                            Win32APIs.keybd_event(Convert.ToByte(KeyInterop.VirtualKeyFromKey(info.key1)), 0, 0, 0);
                            Win32APIs.keybd_event(Convert.ToByte(KeyInterop.VirtualKeyFromKey(info.key1)), 0, 2, 0);
                            if (info.Alt1)
                                Win32APIs.keybd_event(Win32APIs.VK_MENU, 0, 2, 0);
                            if (info.Shift1)
                                Win32APIs.keybd_event(Win32APIs.VK_SHIFT, 0, 2, 0);
                            if (info.Control1)
                                Win32APIs.keybd_event(Win32APIs.VK_CONTROL, 0, 2, 0);
                        }
                    }
                }
            }
        }

        private void Window_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            if (e.LeftButton == MouseButtonState.Pressed)
            {
                this.DragMove();
            }
        }

        private void ToggleButton_Click(object sender, RoutedEventArgs e)
        {
            ToggleButton button = sender as ToggleButton;

            if(button == _buttonSerial)
            {
                _subForm0.Visibility = Visibility.Visible;
                _subForm1.Visibility = Visibility.Hidden;
            }
            else
            {
                _subForm0.Visibility = Visibility.Hidden;
                _subForm1.Visibility = Visibility.Visible;
            }

            if (_buttonMid == button)
                _buttonMid.IsChecked = true;
            else
                _buttonMid.IsChecked = false;

            if (_buttonLeft == button)
                _buttonLeft.IsChecked = true;
            else
                _buttonLeft.IsChecked = false;

            if (_buttonRight == button)
                _buttonRight.IsChecked = true;
            else
                _buttonRight.IsChecked = false;

            if (_buttonUp == button)
                _buttonUp.IsChecked = true;
            else
                _buttonUp.IsChecked = false;

            if (_buttonDown == button)
                _buttonDown.IsChecked = true;
            else
                _buttonDown.IsChecked = false;

            if (_buttonSerial == button)
                _buttonSerial.IsChecked = true;
            else
                _buttonSerial.IsChecked = false;
        }

        private void ToggleButton_Checked(object sender, RoutedEventArgs e)
        {
            ToggleButton button = sender as ToggleButton;
            if (button != null && button.IsChecked == true)
            {
                TreeKey treeKey = button.DataContext as TreeKey;
                TreeKey treeKey0 = treeKey.Children[0];
                TreeKey treeKey1 = treeKey.Children[1];
 
                if (treeKey0 != null && treeKey1 != null)
                {
                    _subForm1._subListViewTouch.ItemsSource = treeKey0._treeTag.userShortcutMap;
                    _subForm1._subListViewTouch.Tag = treeKey0._treeTag;
                    _subForm1._subListViewPress.ItemsSource = treeKey1._treeTag.userShortcutMap;
                    _subForm1._subListViewPress.Tag = treeKey1._treeTag;
                }
            }
        }

        private void Close_MouseDown(object sender, MouseButtonEventArgs e)
        {
            Application.Current.Shutdown();
        }

        private void ToggleButton_Checked_1(object sender, RoutedEventArgs e)
        {
            if (_GraidFirst.Width > 0)
                _GraidFirst.Width = 0;
            else
                _GraidFirst.Width = 200;
        }


        //private void MainForm_FormClosing(object sender, FormClosingEventArgs e)
        //{
        //    if (subForm0 != null)
        //        subForm0.Close();
        //    if (subForm1 != null)
        //        subForm1.Close();
        //    Win32APIs.AnimateWindow(this.Handle, 300, Win32APIs.AW_SLIDE + Win32APIs.AW_VER_NEGATIVE + Win32APIs.AW_HIDE);

        //}

        //private void _mainTreeView_DrawNode(object sender, DrawTreeNodeEventArgs e)
        //{
        //    e.DrawDefault = true; //我这里用默认颜色即可，只需要在TreeView失去焦点时选中节点仍然突显
        //    return;

        //    if ((e.State & TreeNodeStates.Selected) != 0)
        //    {
        //        //演示为绿底白字
        //        e.Graphics.FillRectangle(Brushes.DarkBlue, e.Node.Bounds);

        //        Font nodeFont = e.Node.NodeFont;
        //        if (nodeFont == null) nodeFont = ((TreeView)sender).Font;
        //        e.Graphics.DrawString(e.Node.Text, nodeFont, Brushes.White, Rectangle.Inflate(e.Bounds, 2, 0));
        //    }
        //    else
        //    {
        //        e.DrawDefault = true;
        //    }

        //    if ((e.State & TreeNodeStates.Focused) != 0)
        //    {
        //        using (Pen focusPen = new Pen(Color.Black))
        //        {
        //            focusPen.DashStyle = System.Drawing.Drawing2D.DashStyle.Dot;
        //            Rectangle focusBounds = e.Node.Bounds;
        //            focusBounds.Size = new Size(focusBounds.Width - 1,
        //            focusBounds.Height - 1);
        //            e.Graphics.DrawRectangle(focusPen, focusBounds);
        //        }
        //    }

        //}
    }
}
