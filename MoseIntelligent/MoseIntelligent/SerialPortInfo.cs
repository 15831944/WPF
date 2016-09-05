using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;
using System.IO;
using System.ComponentModel;
using System.Windows.Input;
using System.Collections.ObjectModel;
using System.Windows.Data;
using Microsoft.Win32;
using System.Windows;
using System.Windows.Media;

namespace MoseIntelligent
{
    public class Win32APIs
    {
        [DllImport("user32.dll", EntryPoint = "GetForegroundWindow")]
        public static extern IntPtr GetForegroundWindow();
        [DllImport("user32.dll")]
        public static extern uint GetWindowThreadProcessId(IntPtr hWnd, IntPtr ProcessId);//第二个参数可以用IntPtr.0
        [DllImport("User32.dll", EntryPoint = "PostMessage")]
        public static extern int PostMessage(
        int hWnd,       //   handle   to   destination   window   
        int Msg,        //   message   
        int wParam,     //   first   message   parameter   
        int lParam      //   second   message   parameter   
        );
        [DllImport("user32.dll")]
        public static extern void keybd_event(byte bVk, byte bScan, uint dwFlags, uint dwExtraInfo);
        public const int WM_KEYDOWN = 0x0100;
        public const int WM_KEYUP = 0x0101;
        public const int VK_SHIFT = 0x10;
        public const int VK_CONTROL = 0x11;
        public const int VK_MENU = 0x12;

        [DllImportAttribute("user32.dll")]
        public static extern bool AnimateWindow(IntPtr hwnd, int dwTime, int dwFlags);
        public const Int32 AW_HOR_POSITIVE  = 0x00000001;
        public const Int32 AW_HOR_NEGATIVE  = 0x00000002;
        public const Int32 AW_VER_POSITIVE  = 0x00000004;
        public const Int32 AW_VER_NEGATIVE  = 0x00000008;
        public const Int32 AW_CENTER        = 0x00000010;
        public const Int32 AW_HIDE          = 0x00010000;
        public const Int32 AW_ACTIVATE      = 0x00020000;
        public const Int32 AW_SLIDE         = 0x00040000;
        public const Int32 AW_BLEND     = 0x00080000;
        [System.Runtime.InteropServices.DllImportAttribute("user32.dll")]
        public static extern bool FlashWindow(IntPtr handle, bool bInvert);//handle：表示将要闪烁的窗体。bInvert：是否恢复状态。
    }

    public class GlobalConfig
    {
        //鼠标相关常量定义
        // Touch key
        public const ushort KEY_TOUCH_LEFT_BIT = 1 << 5;		// touch key left
        public const ushort KEY_TOUCH_RIGHT_BIT = 1 << 9;		// touch key right
        public const ushort KEY_TOUCH_MID_BIT = 1 << 6;		// touch key middle
        public const ushort KEY_TOUCH_UP_BIT = 1 << 8;		// touch key up
        public const ushort KEY_TOUCH_DOWN_BIT = 1 << 7;		// touch key down
        // Real key
        public const ushort KEY_PRESS_LEFT_BIT = 1 << 0;		// pressed button left
        public const ushort KEY_PRESS_RIGHT_BIT = 1 << 4;		// pressed button right
        public const ushort KEY_PRESS_MID_BIT = 1 << 1;		// pressed button middle
        public const ushort KEY_PRESS_UP_BIT = 1 << 3;		// pressed button up
        public const ushort KEY_PRESS_DOWN_BIT = 1 << 2;		// pressed button down

        public static byte CalcSum8(byte[] startData)
        {
            int length = startData.Count();
            if (length > 256 || length < 1)
                return 0;
            byte TmpData = 0;

            int i = 0;
            for (; i < length - 1; ++i)
                TmpData += startData[i];
            return TmpData;
        }

        //检验数据
        public static bool ChkSum8(byte[] startData)
        {
            int length = startData.Count();
            if (length > 256 || length < 1)
                return false;
            byte TmpData = 0;

            int i = 0;
            for (; i < length - 1; ++i )
                TmpData += startData[i];
            return (TmpData == startData[i]);
        }

        public static T GetChildObject<T>(DependencyObject obj, string name) where T : FrameworkElement
        {
            DependencyObject child = null;
            T grandChild = null;

            for (int i = 0; i <= VisualTreeHelper.GetChildrenCount(obj) - 1; i++)
            {
                child = VisualTreeHelper.GetChild(obj, i);

                if (child is T && (((T)child).Name == name | string.IsNullOrEmpty(name)))
                {
                    return (T)child;
                }
                else
                {
                    grandChild = GetChildObject<T>(child, name);
                    if (grandChild != null)
                        return grandChild;
                }
            }
            return null;
        }

        public static T GetParentObject<T>(DependencyObject obj, string name) where T : FrameworkElement
        {
            DependencyObject parent = VisualTreeHelper.GetParent(obj);

            while (parent != null)
            {
                if (parent is T && (((T)parent).Name == name | string.IsNullOrEmpty(name)))
                {
                    return (T)parent;
                }
                parent = VisualTreeHelper.GetParent(parent);
            }
            return null;
        }
    }

    public class SerialPortInfo : NotificationObject
    {
        public SerialPortInfo()
        {
            _serialPortName = "未知端口";
            _bConnect = false;
        }

        private string _serialPortName;
        public string SerialPortName
        {
            get
            {
                return _serialPortName;
            }
            set
            {
                _serialPortName = value;
                RaisePropertyChanged("SerialPortName");
            }
        }
        private bool _bConnect;
        public bool bConnect
        {
            get
            {
                return _bConnect;
            }
            set
            {
                _bConnect = value;
                RaisePropertyChanged("bConnect");
            }
        }
    }

    public class SubListItemInfo
    {
        public string serialPortName = "未知端口";
        public bool bConnect = false;
    }

    public class ShortCutInfo : NotificationObject
    {

        public bool         Shift0 = false;
        public bool         Alt0 = false;
        public bool         Control0 = false;
        public Key          key0;

        public bool         Shift1 = false;
        public bool         Alt1 = false;
        public bool         Control1 = false;
        public Key          key1;


        public ShortCutInfo()
        {
            isOk = false;
        }

        private bool isOk;    //
        public bool IsOK
        {
            get
            {
                return isOk;
            }
            set
            {
                isOk = value;
                RaisePropertyChanged("IsOK");
            }
        }

        private string       appShowName;    //应用程序显示名称
        public string       AppShowName
        {
            get
            {
                return appShowName;
            }
            set
            {
                appShowName = value;
                if (shortCutString != "" && shortCutString != null && appShowName != null && appShowName != "")
                    IsOK = true;
                else
                    IsOK = false;

                RaisePropertyChanged("AppShowName");
            }
        }

        private string shortCutString;
        public string ShortCutString
        {
            get
            {
                return shortCutString = GetShortCutString();
            }
            set
            {
                shortCutString = value;
                if (shortCutString != "" && shortCutString != null && appShowName != null && appShowName != "")
                    IsOK = true;
                else
                    IsOK = false;
                RaisePropertyChanged("ShortCutString");
            }
        }

        private static ObservableCollection<string> appShowNames;
        public static ObservableCollection<string> AppShowNames
        {
            get
            {
                return appShowNames;
            }
            //set
            //{
            //    appShowNames = value;
            //    OnPropertyChanged(new PropertyChangedEventArgs("AppShowName"));
            //}
        }

        public void Empty()
        {
            Control0 = false;   Control1 = false;
            Shift0 = false;     Shift1 = false;
            Alt0 = false;       Alt1 = false;
            key0 = Key.None;    key1 = Key.None;
            ShortCutString = ""; //通知控件，取消显示
            AppShowName = ""; //通知控件，取消显示
        }

        private string GetShortCutString()
        {
            string shortString = "";
            string key1str = "";
            if (Control0)
                key1str += "Ctrl" + "+";
            if (Shift0)
                key1str += "Shift" + "+";
            if (Alt0)
                key1str += "Alt" + "+";
            if (Convert.ToInt32(key0) != 0)
                key1str += key0;

            string key2str = "";
            if (Control1)
                key2str += "Ctrl" + "+";
            if (Shift1)
                key2str += "Shift" + "+";
            if (Alt1)
                key2str += "Alt" + "+";
            if (Convert.ToInt32(key1) != 0)
                key2str += key1;

            if (key2str.Length != 0)
                shortString += key1str + "," + key2str;
            else
                shortString += key1str;

            return shortString;
        }


        public const int _maxSystemAppCount = 20;
        public static Dictionary<ushort, string> _constSuportApps = new Dictionary<ushort, string>{//前20(0~19)个为系统应用ID
                             {0, "notepad.exe"}         ,{1, ""}    ,{2, ""}    ,{3, ""}    ,{4, ""}    ,{5, ""}    ,{6, ""}    ,{7, ""}    ,{8, ""}    ,{9, ""},
                             {10, ""}                   ,{11, ""}   ,{12, ""}   ,{13, ""}   ,{14, ""}   ,{15, ""}   ,{16, ""}   ,{17, ""}   ,{18, ""}   ,{19, ""},
                             {20, "Foxit Reader.exe"}   ,{21, "chrome.exe"}   ,{22, "Xmp.exe"}   ,{23, "Thunder.exe"}   ,{24, "qq.exe"}   ,{25, ""}   ,{26, ""}   ,{27, ""}   ,{28, ""}   ,{29, ""},
                         };
        public static Dictionary<string, string> _computerApps = new Dictionary<string, string>();//应用程序显示名   应用程序路径
        static ShortCutInfo()
        {
            Dictionary<string, string> apps = new Dictionary<string, string>();
            using (RegistryKey key = Microsoft.Win32.Registry.LocalMachine.OpenSubKey(@"Software\Microsoft\Windows\CurrentVersion\Uninstall", false))
            {
                if (key != null)
                {
                    foreach (string keyName in key.GetSubKeyNames())
                    {
                        using (RegistryKey key2 = key.OpenSubKey(keyName, false))
                        {
                            if (key2 != null)
                            {
                                string softwareName = key2.GetValue("DisplayName", "").ToString();
                                string installLocation = key2.GetValue("InstallLocation", "").ToString();
                                if (!string.IsNullOrEmpty(installLocation))
                                {
                                    string[] files = null;
                                    if (Directory.Exists(installLocation) && !apps.ContainsKey(softwareName))       //注册表中的某此值可能不存在
                                    {
                                        files = Directory.GetFiles(installLocation, "*.exe", SearchOption.AllDirectories);//查找当前及子目录下的所有EXE文件
                                        string displayExePath = "";
                                        foreach (string file in files)
                                        {
                                            //获取可支持的APPS
                                            foreach (KeyValuePair<ushort, string> kvp in _constSuportApps)
                                            {
                                                string fileLower = file.ToLower();  //文件名只能有一个，这里兼容大小写
                                                string exeLower = kvp.Value.ToLower();
                                                if (!string.IsNullOrEmpty(kvp.Value) && fileLower.Contains(exeLower))
                                                {
                                                    displayExePath = file;     //从安装根目录中查找将要支持的EXE
                                                }
                                            }

                                            if (!string.IsNullOrEmpty(displayExePath))
                                            {
                                                apps.Add(softwareName, displayExePath);
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            } //将取得的结果，


            _computerApps.Clear();
            //分两部分拷贝，第一部分只拷贝系统应用
            string sysPath = Environment.GetFolderPath(Environment.SpecialFolder.System);
            string sysPathX86 = Environment.GetFolderPath(Environment.SpecialFolder.SystemX86);
            string[] exeFiles = Directory.GetFiles(sysPath, "*.exe", SearchOption.TopDirectoryOnly);
            string[] exeFilesX86 = Directory.GetFiles(sysPathX86, "*.exe", SearchOption.TopDirectoryOnly);
            foreach (string file in exeFiles)
            {
                for (int i = 0; i < _maxSystemAppCount; ++i)
                {//系统APP组织成    应用程序名   应用程序路径
                    if (_constSuportApps.ElementAt(i).Value.Length > 0)
                    {
                        string fileLower = file.ToLower();  //文件名只能有一个，这里兼容大小写
                        string exeLower = _constSuportApps.ElementAt(i).Value.ToLower();
                        if (fileLower.Contains(exeLower) && !_computerApps.ContainsKey(_constSuportApps.ElementAt(i).Value))
                            _computerApps.Add(_constSuportApps.ElementAt(i).Value, file);
                    }
                }
            }

            foreach (string file in exeFilesX86)
            {
                for (int i = 0; i < _maxSystemAppCount; ++i)
                {//系统APP组织成    应用程序名   应用程序路径
                    if (_constSuportApps.ElementAt(i).Value.Length > 0)
                    {
                        string fileLower = file.ToLower();  //文件名只能有一个，这里兼容大小写
                        string exeLower = _constSuportApps.ElementAt(i).Value.ToLower();
                        if (fileLower.Contains(exeLower) && !_computerApps.ContainsKey(_constSuportApps.ElementAt(i).Value))
                            _computerApps.Add(_constSuportApps.ElementAt(i).Value, file);
                    }
                }
            }

            Dictionary<string, string> temp = apps;
            foreach (KeyValuePair<string, string> kvp in temp)
            {
                if (false == _computerApps.ContainsKey(kvp.Key))
                    _computerApps.Add(kvp.Key, kvp.Value);
            }

            //初始化appShowNames列表
            appShowNames = new ObservableCollection<string>();
            foreach(KeyValuePair<String, string> kvp in _computerApps)
            {
                appShowNames.Add(kvp.Key);
            }
        }
    }

    public class KeyTreeNodeTag //应用程序路径  快捷键
    {
        public byte keyType = 0;    //按键的类型
        public ObservableCollection<ShortCutInfo> userShortcutMap = new ObservableCollection<ShortCutInfo>();
        //public Dictionary<string, ShortCutInfo> userShortcutMap = new Dictionary<string, ShortCutInfo>();
    }

    public class ShortCutInfoConvert : IValueConverter
    {
        #region IValueConverter 成员
        public object Convert(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            if (value != null && value.GetType() == typeof(ShortCutInfo) && ((ShortCutInfo)value).AppShowName != null)
                return "减";
            else
                return "加";

            return null;
        }
        public object ConvertBack(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            string mypric = value.ToString();
            decimal pri;
            if (decimal.TryParse(mypric, System.Globalization.NumberStyles.Any, culture, out pri))
            {
                return pri;
            }
            return value;
        }
        #endregion
    }
    public class ShortCutInfoImageConvert : IValueConverter
    {
        #region IValueConverter 成员
        public object Convert(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            if (value != null && value.GetType() == typeof(ShortCutInfo) && ((ShortCutInfo)value).IsOK)
                //if (value != null && value.GetType() == typeof(bool) && ((bool)value))
                return "Images/Minus.png";
            else
                return "Images/Add.png";

            return null;
        }
        public object ConvertBack(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            string mypric = value.ToString();
            decimal pri;
            if (decimal.TryParse(mypric, System.Globalization.NumberStyles.Any, culture, out pri))
            {
                return pri;
            }
            return value;
        }
        #endregion
    }
    public class ConnectBtnEnableConverter : IValueConverter
    {
        #region IValueConverter 成员
        public object Convert(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            if (value != null && value.GetType() == typeof(Boolean))
            {
                Boolean b = (Boolean)value;
                return !b; //未连接，则enable=true, 否则enable=false
            }

            return null;
        }
        public object ConvertBack(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            string mypric = value.ToString();
            decimal pri;
            if (decimal.TryParse(mypric, System.Globalization.NumberStyles.Any, culture, out pri))
            {
                return pri;
            }
            return value;
        }
        #endregion
    }
    public class TreeKey : INotifyPropertyChanged
    {
        //////////////// 这里缺少PropertyChanged相关的代码的话，在动态修改内存时，不会反应到界面上
        public event PropertyChangedEventHandler PropertyChanged;
        public void OnPropertyChanged(PropertyChangedEventArgs e)
        {
            if (PropertyChanged != null)
                PropertyChanged(this, e);
        }
        ////////////////////////////////////////////////////////

        public TreeKey()
        {
            _text = "UnKnown";
            _children = new List<TreeKey>();
        }

        public TreeKey(string name)
        {
            _text = "UnKnown";
            _children = new List<TreeKey>();
        }

        private string _text;
        public string Text{
            get
            {
                return _text;
            }
            set
            {
                _text = value;
                OnPropertyChanged(new PropertyChangedEventArgs("Text"));
            }
        }

        private List<TreeKey> _children;
        public List<TreeKey> Children
        {
            get
            {
                return _children;
            }
            set
            {
                _children = value;
                OnPropertyChanged(new PropertyChangedEventArgs("Children"));
            }
        }

        public KeyTreeNodeTag _treeTag = null;
        public override string ToString()
        {
            return _text;
        }
    }
 
    public class KeyCfgListViewHeader
    {   //只用来显示单向的
        public string column0 { get; set; }
        public string column1 { get; set; }
        public string column2 { get; set; }

        public KeyCfgListViewHeader()
        {
            column0 = "序号";
            column1 = "应用程序";
            column2 = "快捷键";
        }
    }

    public class SerialUIDataFactory
    {
        public SerialUIDataFactory()
        {

        }

        public static IEnumerable<TreeKey> GetSeiralTreeData()
        {//构造列表树
            List<TreeKey> Nodes = new List<TreeKey>();
            TreeKey rootNode0 = new TreeKey();            rootNode0.Text = "串口连接";
            TreeKey rootNode1 = new TreeKey();            rootNode1.Text = "鼠标设置";
            TreeKey rootNode1Sub0 = new TreeKey();        rootNode1Sub0.Text = "触摸"; rootNode1.Children.Add(rootNode1Sub0);
            TreeKey rootNode1Sub0_Sub0 = new TreeKey(); rootNode1Sub0_Sub0.Text = "左键"; rootNode1Sub0.Children.Add(rootNode1Sub0_Sub0); rootNode1Sub0_Sub0._treeTag = new KeyTreeNodeTag(); rootNode1Sub0_Sub0._treeTag.keyType = 0x01;
//             ShortCutInfo shortCut0 = new ShortCutInfo(); shortCut0.AppShowName = "notepad.exe";
//             ShortCutInfo shortCut1 = new ShortCutInfo(); shortCut1.AppShowName = "Foxit Reader.exe";
//             ShortCutInfo shortCut2 = new ShortCutInfo(); shortCut2.AppShowName = "chrome.exe";
//             rootNode1Sub0_Sub0._treeTag.userShortcutMap.Add(shortCut0);
//             rootNode1Sub0_Sub0._treeTag.userShortcutMap.Add(shortCut1);
//             rootNode1Sub0_Sub0._treeTag.userShortcutMap.Add(shortCut2);
            TreeKey rootNode1Sub0_Sub1 = new TreeKey(); rootNode1Sub0_Sub1.Text = "右键"; rootNode1Sub0.Children.Add(rootNode1Sub0_Sub1); rootNode1Sub0_Sub1._treeTag = new KeyTreeNodeTag(); rootNode1Sub0_Sub1._treeTag.keyType = 0x02;
            TreeKey rootNode1Sub0_Sub2 = new TreeKey(); rootNode1Sub0_Sub2.Text = "中键"; rootNode1Sub0.Children.Add(rootNode1Sub0_Sub2); rootNode1Sub0_Sub2._treeTag = new KeyTreeNodeTag(); rootNode1Sub0_Sub2._treeTag.keyType = 0x03;
            TreeKey rootNode1Sub0_Sub3 = new TreeKey(); rootNode1Sub0_Sub3.Text = "上键"; rootNode1Sub0.Children.Add(rootNode1Sub0_Sub3); rootNode1Sub0_Sub3._treeTag = new KeyTreeNodeTag(); rootNode1Sub0_Sub3._treeTag.keyType = 0x04;
            TreeKey rootNode1Sub0_Sub4 = new TreeKey(); rootNode1Sub0_Sub4.Text = "下键"; rootNode1Sub0.Children.Add(rootNode1Sub0_Sub4); rootNode1Sub0_Sub4._treeTag = new KeyTreeNodeTag(); rootNode1Sub0_Sub4._treeTag.keyType = 0x05;
            TreeKey rootNode1Sub1 = new TreeKey(); rootNode1Sub1.Text = "按压"; rootNode1.Children.Add(rootNode1Sub1);
            TreeKey rootNode1Sub1_Sub0 = new TreeKey(); rootNode1Sub1_Sub0.Text = "左键"; rootNode1Sub1.Children.Add(rootNode1Sub1_Sub0); rootNode1Sub1_Sub0._treeTag = new KeyTreeNodeTag(); rootNode1Sub1_Sub0._treeTag.keyType = 0x11;
            TreeKey rootNode1Sub1_Sub1 = new TreeKey(); rootNode1Sub1_Sub1.Text = "右键"; rootNode1Sub1.Children.Add(rootNode1Sub1_Sub1); rootNode1Sub1_Sub1._treeTag = new KeyTreeNodeTag(); rootNode1Sub1_Sub1._treeTag.keyType = 0x12;
            TreeKey rootNode1Sub1_Sub2 = new TreeKey(); rootNode1Sub1_Sub2.Text = "中键"; rootNode1Sub1.Children.Add(rootNode1Sub1_Sub2); rootNode1Sub1_Sub2._treeTag = new KeyTreeNodeTag(); rootNode1Sub1_Sub2._treeTag.keyType = 0x13;
            TreeKey rootNode1Sub1_Sub3 = new TreeKey(); rootNode1Sub1_Sub3.Text = "上键"; rootNode1Sub1.Children.Add(rootNode1Sub1_Sub3); rootNode1Sub1_Sub3._treeTag = new KeyTreeNodeTag(); rootNode1Sub1_Sub3._treeTag.keyType = 0x14;
            TreeKey rootNode1Sub1_Sub4 = new TreeKey(); rootNode1Sub1_Sub4.Text = "下键"; rootNode1Sub1.Children.Add(rootNode1Sub1_Sub4); rootNode1Sub1_Sub4._treeTag = new KeyTreeNodeTag(); rootNode1Sub1_Sub4._treeTag.keyType = 0x15;

            Nodes.Add(rootNode0);
            Nodes.Add(rootNode1);
            return Nodes;
        }

        public static IEnumerable<TreeKey> GetButtonSeiralTreeData()
        {//构造列表树
            List<TreeKey> Nodes = new List<TreeKey>();

            
            TreeKey buttonDataKey0 = new TreeKey(); buttonDataKey0.Text = "左键";
            TreeKey buttonDataKey0_Sub1 = new TreeKey(); buttonDataKey0_Sub1.Text = "左键触摸"; buttonDataKey0.Children.Add(buttonDataKey0_Sub1); buttonDataKey0_Sub1._treeTag = new KeyTreeNodeTag(); buttonDataKey0_Sub1._treeTag.keyType = 0x01;
            TreeKey buttonDataKey0_Sub2 = new TreeKey(); buttonDataKey0_Sub2.Text = "左键按压"; buttonDataKey0.Children.Add(buttonDataKey0_Sub2); buttonDataKey0_Sub2._treeTag = new KeyTreeNodeTag(); buttonDataKey0_Sub2._treeTag.keyType = 0x11;
            TreeKey buttonDataKey1 = new TreeKey(); buttonDataKey1.Text = "右键";
            TreeKey buttonDataKey1_Sub1 = new TreeKey(); buttonDataKey1_Sub1.Text = "左键触摸"; buttonDataKey1.Children.Add(buttonDataKey1_Sub1); buttonDataKey1_Sub1._treeTag = new KeyTreeNodeTag(); buttonDataKey1_Sub1._treeTag.keyType = 0x02;
            TreeKey buttonDataKey1_Sub2 = new TreeKey(); buttonDataKey1_Sub2.Text = "左键按压"; buttonDataKey1.Children.Add(buttonDataKey1_Sub2); buttonDataKey1_Sub2._treeTag = new KeyTreeNodeTag(); buttonDataKey1_Sub2._treeTag.keyType = 0x12;
            TreeKey buttonDataKey2 = new TreeKey(); buttonDataKey2.Text = "中键";
            TreeKey buttonDataKey2_Sub1 = new TreeKey(); buttonDataKey2_Sub1.Text = "左键触摸"; buttonDataKey2.Children.Add(buttonDataKey2_Sub1); buttonDataKey2_Sub1._treeTag = new KeyTreeNodeTag(); buttonDataKey2_Sub1._treeTag.keyType = 0x03;
            TreeKey buttonDataKey2_Sub2 = new TreeKey(); buttonDataKey2_Sub2.Text = "左键按压"; buttonDataKey2.Children.Add(buttonDataKey2_Sub2); buttonDataKey2_Sub2._treeTag = new KeyTreeNodeTag(); buttonDataKey2_Sub2._treeTag.keyType = 0x13;
            TreeKey buttonDataKey3 = new TreeKey(); buttonDataKey3.Text = "上键";
            TreeKey buttonDataKey3_Sub1 = new TreeKey(); buttonDataKey3_Sub1.Text = "左键触摸"; buttonDataKey3.Children.Add(buttonDataKey3_Sub1); buttonDataKey3_Sub1._treeTag = new KeyTreeNodeTag(); buttonDataKey3_Sub1._treeTag.keyType = 0x04;
            TreeKey buttonDataKey3_Sub2 = new TreeKey(); buttonDataKey3_Sub2.Text = "左键按压"; buttonDataKey3.Children.Add(buttonDataKey3_Sub2); buttonDataKey3_Sub2._treeTag = new KeyTreeNodeTag(); buttonDataKey3_Sub2._treeTag.keyType = 0x14;
            TreeKey buttonDataKey4 = new TreeKey(); buttonDataKey4.Text = "下键";
            TreeKey buttonDataKey4_Sub1 = new TreeKey(); buttonDataKey4_Sub1.Text = "左键触摸"; buttonDataKey4.Children.Add(buttonDataKey4_Sub1); buttonDataKey4_Sub1._treeTag = new KeyTreeNodeTag(); buttonDataKey4_Sub1._treeTag.keyType = 0x05;
            TreeKey buttonDataKey4_Sub2 = new TreeKey(); buttonDataKey4_Sub2.Text = "左键按压"; buttonDataKey4.Children.Add(buttonDataKey4_Sub2); buttonDataKey4_Sub2._treeTag = new KeyTreeNodeTag(); buttonDataKey4_Sub2._treeTag.keyType = 0x15;

            Nodes.Add(buttonDataKey0);
            Nodes.Add(buttonDataKey1);
            Nodes.Add(buttonDataKey2);
            Nodes.Add(buttonDataKey3);
            Nodes.Add(buttonDataKey4);
            return Nodes;
        }
    }
}
