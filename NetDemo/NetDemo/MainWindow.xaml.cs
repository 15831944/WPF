using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace NetDemo
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        [DllImport("NetDll.dll", CharSet=CharSet.Ansi, CallingConvention=CallingConvention.Cdecl, EntryPoint = "startServer")]
        private static extern bool startServer(string ip, int port, IntPtr serverReceiveCallBack, ref IntPtr senddataCallBack);

        [DllImport("NetDll.dll", CallingConvention=CallingConvention.Cdecl, EntryPoint = "stopServer")]
        private static extern bool stopServer();

        [DllImport("NetDll.dll", CharSet=CharSet.Ansi, CallingConvention=CallingConvention.Cdecl, EntryPoint = "startClient")]
        private static extern bool startClient(string ip, int port, IntPtr clientReceiveCallBack, ref IntPtr senddataCallBack);

        [DllImport("NetDll.dll", CallingConvention=CallingConvention.Cdecl, EntryPoint = "stopClient")]
        private static extern bool stopClient();

        [UnmanagedFunctionPointerAttribute(CallingConvention.Cdecl)]
        public delegate void ServerSendDataDelegate(int userID, IntPtr ptr, int len);

        [UnmanagedFunctionPointerAttribute(CallingConvention.Cdecl)]
        public delegate void ClientSendDataDelegate(IntPtr ptr, int len);

        [UnmanagedFunctionPointerAttribute(CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        public delegate void ReceviceCallBackDelegate(int userID, IntPtr ptr, int len, int errorcode, StringBuilder errorMsg);


        public ReceviceCallBackDelegate serverReceiveCallBackDelegate = null;
        public ReceviceCallBackDelegate clientReceiveCallBackDelegate = null;


        ClientSendDataDelegate                _clientSendDataAction = null;
        ServerSendDataDelegate                _serverSendDataAction = null;
        int _userID;
        public MainWindow()
        {
            InitializeComponent();
        }

        public void serverReceiveCallBack(int userID, IntPtr ptr, int len, int errorcode, StringBuilder errorMsg)
        {

            byte[] data         = new byte[len];
            Marshal.Copy(ptr, data, 0, len);

            IntPtr pArray       = Marshal.UnsafeAddrOfPinnedArrayElement(data, 0);
            _serverSendDataAction(userID, pArray, data.Length);
            string str = Marshal.PtrToStringAnsi(ptr);

            serverReceivebox.Dispatcher.Invoke(new Action(() =>
                                    {   ////图片应当在UI线程中创建
                                        serverReceivebox.Text += str;
                                    }));
        }

        public void clientReceiveCallBack(int userID, IntPtr ptr, int len, int errorcode, StringBuilder errorMsg)
        {
            _userID = userID;

            //byte[] data         = new byte[len];
            //Marshal.Copy(ptr, data, 0, len);

            //IntPtr pArray       = Marshal.UnsafeAddrOfPinnedArrayElement(data, 0);
            //clientSendDataAction(userID, pArray, data.Length);
        }

        private void butStart_Click(object sender, RoutedEventArgs e)
        {

            IntPtr serverSendData = IntPtr.Zero;
            serverReceiveCallBackDelegate  = new ReceviceCallBackDelegate(serverReceiveCallBack);

            string unicodestring = "127.0.0.1";
            bool a = startServer(unicodestring, Convert.ToInt32(bindPortBox.Text), Marshal.GetFunctionPointerForDelegate(serverReceiveCallBackDelegate), ref serverSendData);

            _serverSendDataAction = (ServerSendDataDelegate)Marshal.GetDelegateForFunctionPointer((IntPtr)serverSendData, typeof(ServerSendDataDelegate));

        }

        private void butStop_Click(object sender, RoutedEventArgs e)
        {
            bool a = stopServer();
        }


        private void butStartClient_Click(object sender, RoutedEventArgs e)
        {
            IntPtr clientSendData = IntPtr.Zero;
            clientReceiveCallBackDelegate  = new ReceviceCallBackDelegate(clientReceiveCallBack);

            bool a = startClient(serverIP.Text, Convert.ToInt32(serverPort.Text), Marshal.GetFunctionPointerForDelegate(clientReceiveCallBackDelegate), ref clientSendData);

            _clientSendDataAction = (ClientSendDataDelegate)Marshal.GetDelegateForFunctionPointer((IntPtr)clientSendData, typeof(ClientSendDataDelegate));

        }
        
        private void butStopClient_Click(object sender, RoutedEventArgs e)
        {
            bool a = stopClient();
        }

        private void butSendDataClient_Click(object sender, RoutedEventArgs e)
        {
            byte[] b2 = System.Text.Encoding.Default.GetBytes(senddatabox.Text);
            //byte[] b2 = new byte[0x10000000];
            IntPtr pArray = Marshal.UnsafeAddrOfPinnedArrayElement(b2, 0);

            if(_clientSendDataAction != null)
                _clientSendDataAction(pArray, b2.Length);
        }
    }
}
