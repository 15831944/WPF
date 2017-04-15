using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Text;
using ExcutesqlCallBackDelegate = ManageSystem.Server.AddTableCallBackDelegate;

namespace ManageSystem.Server
{
    [UnmanagedFunctionPointerAttribute(CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
    public delegate void QueryTableCallBackDelegate(string resultStr, string errorStr);
    [UnmanagedFunctionPointerAttribute(CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
    public delegate void QueryTableCallBackDelegate1(IntPtr resultStr, string errorStr);
    [UnmanagedFunctionPointerAttribute(CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
    public delegate void AddTableCallBackDelegate(string resultStr, string errorStr);
    [UnmanagedFunctionPointerAttribute(CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
    public delegate void UpgradeCallBackDelegate(string resultStr, string errorStr);

    public sealed class WorkServer
    {
        [DllImport("WorkDll.dll", CharSet=CharSet.Ansi, CallingConvention=CallingConvention.Cdecl, EntryPoint = "startServer")]
        public static extern bool startServer(string ip, int port);
        [DllImport("WorkDll.dll", CallingConvention=CallingConvention.Cdecl, EntryPoint = "stopServer")]
        public static extern bool stopServer();
        [DllImport("WorkDll.dll", CallingConvention=CallingConvention.Cdecl, EntryPoint = "isServerStoped")]
        public static extern bool isServerStoped();
        [DllImport("WorkDll.dll", CallingConvention=CallingConvention.Cdecl, EntryPoint = "curServerConnections")]
        public static extern int curServerConnections();
        [DllImport("WorkDll.dll", CallingConvention=CallingConvention.Cdecl, EntryPoint = "curConnectionsStr")]
        public static extern string curConnectionsStr();

        [DllImport("WorkDll.dll", CharSet=CharSet.Ansi, CallingConvention=CallingConvention.Cdecl, EntryPoint = "startClient")]
        public static extern bool startClient(string ip, int port, bool bDevice);
        [DllImport("WorkDll.dll", CallingConvention=CallingConvention.Cdecl, EntryPoint = "stopClient")]
        public static extern bool stopClient();
        [DllImport("WorkDll.dll", CallingConvention=CallingConvention.Cdecl, EntryPoint = "isClientStoped")]
        public static extern bool isClientStoped();

        [DllImport("WorkDll.dll", CharSet=CharSet.Ansi, CallingConvention=CallingConvention.Cdecl, EntryPoint = "queryOnlieDevCnt")]
        public static extern void queryOnlieDevCnt(IntPtr callback, bool bSync);
        [DllImport("WorkDll.dll", CharSet=CharSet.Ansi,  CallingConvention=CallingConvention.Cdecl, EntryPoint = "queryTable")]
        private static extern void queryTable(string querySqlStr, IntPtr callback, bool bSync);

        [DllImport("WorkDll.dll", CharSet=CharSet.Ansi, CallingConvention=CallingConvention.Cdecl, EntryPoint = "addTable")]
        public static extern void addTable(
                        string tableName,
                        string dataStr,
                        IntPtr callback,
                        bool bSync);
        [DllImport("WorkDll.dll", CharSet=CharSet.Ansi, CallingConvention=CallingConvention.Cdecl, EntryPoint = "addVersion")]
        public static extern void addVersion(
                        string bianhao,
                        string banbenhao,
                        IntPtr Anzhuangbao,
                        int datalen,
                        IntPtr callback,
                        bool bSync);

        [DllImport("WorkDll.dll", CharSet=CharSet.Ansi, CallingConvention=CallingConvention.Cdecl, EntryPoint = "excuteSql")]
        public static extern void excuteSql(string sqlStr, IntPtr callBack, bool bSync);
        [DllImport("WorkDll.dll", CallingConvention=CallingConvention.Cdecl, EntryPoint = "queryDevSpeed")]
        public static extern int queryDevSpeed(string ipStr, IntPtr callBack, bool bSync);
        [DllImport("WorkDll.dll", CallingConvention=CallingConvention.Cdecl, EntryPoint = "queryConnectionsStr")]
        public static extern int queryConnectionsStr(IntPtr callBack, bool bSync);

        [DllImport("WorkDll.dll", CallingConvention=CallingConvention.Cdecl, EntryPoint = "upgrade")]
        public static extern int upgrade(string dataStr,IntPtr callBack, bool bSync);

        public static void QueryTable(string querySqlStr, IntPtr callback, bool bSync = false)
        {//可以避免 直接绑定到Command上面 导致axml找不到模块
           typeof(WorkServer).InvokeMember("queryTable",
          BindingFlags.Static | BindingFlags.NonPublic | BindingFlags.InvokeMethod, null, null, new object[] {querySqlStr, callback, bSync});
        }
    }
}
