using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace ManageSystem.Server
{
    [UnmanagedFunctionPointerAttribute(CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
    public delegate void QueryTableCallBackDelegate(string resultStr);

    public sealed class WorkServer
    {
        private static readonly WorkServer instance = new WorkServer();

        private WorkServer()
        {
        }

        public static WorkServer GetInstance()
        {
            return instance;
        }

        [DllImport("WorkDll.dll", CharSet=CharSet.Ansi, CallingConvention=CallingConvention.Cdecl, EntryPoint = "startServer")]
        private static extern bool _startServer(string ip, int port);
        [DllImport("WorkDll.dll", CallingConvention=CallingConvention.Cdecl, EntryPoint = "stopServer")]
        private static extern bool _stopServer();
        [DllImport("WorkDll.dll", CallingConvention=CallingConvention.Cdecl, EntryPoint = "isServerStoped")]
        private static extern bool _isServerStoped();

        [DllImport("WorkDll.dll", CharSet=CharSet.Ansi, CallingConvention=CallingConvention.Cdecl, EntryPoint = "startClient")]
        private static extern bool _startClient(string ip, int port);
        [DllImport("WorkDll.dll", CallingConvention=CallingConvention.Cdecl, EntryPoint = "stopClient")]
        private static extern bool _stopClient();
        [DllImport("WorkDll.dll", CallingConvention=CallingConvention.Cdecl, EntryPoint = "isClientStoped")]
        private static extern bool _isClientStoped();

        [DllImport("WorkDll.dll", CallingConvention=CallingConvention.Cdecl, EntryPoint = "queryTable")]
        private static extern bool _queryTable(string querySqlStr, IntPtr callback);
 
        /// <summary>
        /// Server
        /// </summary>
        /// <param name="ip"></param>
        /// <param name="port"></param>
        /// <returns></returns>
        /// <summary>
        /// Server
        /// </summary>
        /// <param name="ip"></param>
        /// <param name="port"></param>
        /// <returns></returns>
        public bool startServer(string ip, int port)
        {
        	return _startServer(ip, port);
        }
        
        public bool stopServer()
        {
        	return _stopServer();
        }
        public bool isServerStoped()
        {
        	return _isServerStoped();
        }
        
        /// <summary>
        /// Client
        /// </summary>
        /// <param name="ip"></param>
        /// <param name="port"></param>
        /// <returns></returns>
        public bool startClient(string ip, int port)
        {
        	return _startClient(ip, port);
        }
        
        public bool stopClient()
        {
        	return _stopClient();
        }
        
        public bool isClientStoped()
        {
        	return _isClientStoped();
        }

        public void QueryTable(string querySqlStr, IntPtr callback)
        {
            _queryTable(querySqlStr, callback);
        } 
    }
}
