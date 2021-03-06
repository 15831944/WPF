﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Text;

namespace ManageSystem.Server
{
    [UnmanagedFunctionPointerAttribute(CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
    public delegate void QueryTableCallBackDelegate(string resultStr, string errorStr);

    public sealed class WorkServer
    {
        [DllImport("WorkDll.dll", CharSet=CharSet.Ansi, CallingConvention=CallingConvention.Cdecl, EntryPoint = "startServer")]
        public static extern bool startServer(string ip, int port);
        [DllImport("WorkDll.dll", CallingConvention=CallingConvention.Cdecl, EntryPoint = "stopServer")]
        public static extern bool stopServer();
        [DllImport("WorkDll.dll", CallingConvention=CallingConvention.Cdecl, EntryPoint = "isServerStoped")]
        public static extern bool isServerStoped();
        [DllImport("WorkDll.dll", CallingConvention=CallingConvention.Cdecl, EntryPoint = "cntServerConnections")]
        public static extern int cntServerConnections();
        [DllImport("WorkDll.dll", CharSet=CharSet.Ansi, CallingConvention=CallingConvention.Cdecl, EntryPoint = "curConnectionsStr")]
        public static extern IntPtr curConnectionsStr();

        [DllImport("WorkDll.dll", CharSet=CharSet.Ansi, CallingConvention=CallingConvention.Cdecl, EntryPoint = "startClient")]
        public static extern bool startClient(string ip, int port, bool bDevice);
        [DllImport("WorkDll.dll", CallingConvention=CallingConvention.Cdecl, EntryPoint = "stopClient")]
        public static extern bool stopClient();
        [DllImport("WorkDll.dll", CallingConvention=CallingConvention.Cdecl, EntryPoint = "isClientStoped")]
        public static extern bool isClientStoped();

        [DllImport("WorkDll.dll", CharSet=CharSet.Ansi,  CallingConvention=CallingConvention.Cdecl, EntryPoint = "queryTable")]
        private static extern bool queryTable(string querySqlStr, IntPtr callback, bool bWait);
        [DllImport("WorkDll.dll", CharSet=CharSet.Ansi, CallingConvention=CallingConvention.Cdecl, EntryPoint = "queryOnlieDevCnt")]
        public static extern int queryOnlieDevCnt(IntPtr callback, bool bWait);

        public static bool QueryTable(string querySqlStr, IntPtr callback, bool bWait = false)
        {//可以避免 直接绑定到Command上面 导致axml找不到模块
           return (bool)typeof(WorkServer).InvokeMember("queryTable",
          BindingFlags.Static | BindingFlags.NonPublic | BindingFlags.InvokeMethod, null, null, new object[] {querySqlStr, callback, bWait});
        }
    }
}
