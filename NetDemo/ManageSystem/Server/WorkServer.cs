using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Text;

namespace ManageSystem.Server
{
    [UnmanagedFunctionPointerAttribute(CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
    public delegate void QueryTableCallBackDelegate(string resultStr);

    public sealed class WorkServer
    {
        [DllImport("WorkDll.dll", CharSet=CharSet.Ansi, CallingConvention=CallingConvention.Cdecl, EntryPoint = "startServer")]
        private static extern bool startServer(string ip, int port);
        [DllImport("WorkDll.dll", CallingConvention=CallingConvention.Cdecl, EntryPoint = "stopServer")]
        private static extern bool stopServer();
        [DllImport("WorkDll.dll", CallingConvention=CallingConvention.Cdecl, EntryPoint = "isServerStoped")]
        private static extern bool isServerStoped();

        [DllImport("WorkDll.dll", CharSet=CharSet.Ansi, CallingConvention=CallingConvention.Cdecl, EntryPoint = "startClient")]
        private static extern bool startClient(string ip, int port);
        [DllImport("WorkDll.dll", CallingConvention=CallingConvention.Cdecl, EntryPoint = "stopClient")]
        private static extern bool stopClient();
        [DllImport("WorkDll.dll", CallingConvention=CallingConvention.Cdecl, EntryPoint = "isClientStoped")]
        private static extern bool isClientStoped();

        [DllImport("WorkDll.dll", CharSet=CharSet.Ansi,  CallingConvention=CallingConvention.Cdecl, EntryPoint = "queryTable")]
        private static extern bool queryTable(string querySqlStr, IntPtr callback);

        public static bool QueryTable(string querySqlStr, IntPtr callback)
        {//可以避免 直接绑定到Command上面 导致axml找不到模块
           return (bool)typeof(WorkServer).InvokeMember("queryTable",
          BindingFlags.Static | BindingFlags.NonPublic | BindingFlags.InvokeMethod, null, null, new object[] {querySqlStr, callback});
        }
    }
}
