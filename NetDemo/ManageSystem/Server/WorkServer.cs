using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace ManageSystem.Server
{
    [UnmanagedFunctionPointerAttribute(CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
    public delegate void QueryTableCallBackDelegate(string resultStr);

    [UnmanagedFunctionPointerAttribute(CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
    public delegate void QueryZHIQIANSHUJUCallBackDelegate(
                    int Xuhao,
                    int Chengshibianhao,
                    int Jubianhao,
                    int Shiyongdanweibianhao,
                    int IP,
                    bool Bendiyewu,
                    int Shebeibaifangweizhi,
                    Int64 Riqi,
                    string Yewubianhao,
                    string YuanZhengjianhaoma,
                    string Xingming,
                    int Qianzhuzhonglei,
                    int ZhikaZhuangtai,
                    string Zhengjianhaoma,
                    string Jiekoufanhuijieguo,
                    string Lianxidianhua
    );

    [UnmanagedFunctionPointerAttribute(CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
    public delegate void QuerySHOUZHENGSHUJUCallBackDelegate(
                    int Xuhao,
                    int Chengshibianhao,
                    int Jubianhao,
                    int Shiyongdanweibianhao,
                    int IP,
                    bool Bendiyewu,
                    int Shebeibaifangweizhi,
                    Int64 Riqi,
                    int Zhengjianleixing,
                    string Zhengjianhaoma,
                    string Xingming,
                    string Shoulibianhao,
                    bool Shifoujiaofei
    );
    [UnmanagedFunctionPointerAttribute(CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
    public delegate void QueryQIANZHUSHUJUCallBackDelegate(
                    int Xuhao,
                    int Chengshibianhao,
                    int Jubianhao,
                    int Shiyongdanweibianhao,
                    int IP,
                    bool Bendiyewu,
                    int Shebeibaifangweizhi,
                    Int64 Riqi,
                    string YuanZhengjianhaoma,
                    string Xingming,
                    int Xingbie,
                    Int64 Chushengriqi,
                    string Lianxidianhua,
                    int Yewuleixing,
                    string Shouliren
    );
    [UnmanagedFunctionPointerAttribute(CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
    public delegate void QueryJIAOKUANSHUJUCallBackDelegate(
                    int Xuhao,
                    int Chengshibianhao,
                    int Jubianhao,
                    int Shiyongdanweibianhao,
                    int IP,
                    bool Bendiyewu,
                    int Shebeibaifangweizhi,
                    Int64 Riqi,
                    string Zhishoudanweidaima,
                    string Jiaokuantongzhishuhaoma,
                    string Jiaokuanrenxingming,
                    float Yingkoukuanheji,
                    Int64 Jiaoyiriqi
    );
    [UnmanagedFunctionPointerAttribute(CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
    public delegate void QueryCHAXUNSHUJUCallBackDelegate(
                    int Xuhao,
                    int Chengshibianhao,
                    int Jubianhao,
                    int Shiyongdanweibianhao,
                    int IP,
                    bool Bendiyewu,
                    int Shebeibaifangweizhi,
                    Int64 Riqi,
                    string Chaxunhaoma,
                    string Chaxunleixing,
                    bool Shifouchaxunchenggong,
                    Int64 Chuangjianshijian
    );
    [UnmanagedFunctionPointerAttribute(CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
    public delegate void QueryYUSHOULISHUJUCallBackDelegate(
                    int Xuhao,
                    int Chengshibianhao,
                    int Jubianhao,
                    int Shiyongdanweibianhao,
                    int IP,
                    bool Bendiyewu,
                    int Shebeibaifangweizhi,
                    Int64 Riqi,
                    string Yewubianhao,
                    string Xingming,
                    string Lianxidianhua,
                    string Chuguoshiyou,
                    string YuanZhengjianhaoma,
                    int Qianzhuzhonglei,
                    int Xingbie,
                    string Hukousuozaidi,
                    string Minzu,
                    Int64 Chuangjianshijian
    );

    [UnmanagedFunctionPointerAttribute(CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
    public delegate void QuerySHEBEIZHUANGTAICallBackDelegate(
                    int Xuhao,
                    int Chengshibianhao,
                    int Jubianhao,
                    int Shiyongdanweibianhao,
                    int IP,
                    bool Bendiyewu,
                    int Shebeibaifangweizhi,
                    Int64 Riqi,
                    bool Shifouzaixian
    );
    [UnmanagedFunctionPointerAttribute(CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
    public delegate void QuerySHEBEIYICHANGSHUJUCallBackDelegate(
                    int Xuhao,
                    int Chengshibianhao,
                    int Jubianhao,
                    int Shiyongdanweibianhao,
                    int IP,
                    bool Bendiyewu,
                    int Shebeibaifangweizhi,
                    Int64 Riqi,
                    string Yichangshejimokuai,
                    string Yichangyuanyin,
                    string Yichangxiangxineirong
    );
    [UnmanagedFunctionPointerAttribute(CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
    public delegate void QueryGUANLIYUANCallBackDelegate(
                    int Xuhao,
                    string Yonghuming,
                    string Mima,
                    int Youxiaoqikaishi,
                    int Youxiaoqijieshu,
                    int Quanxianjibie
    );
    [UnmanagedFunctionPointerAttribute(CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
    public delegate void QueryGUANLIYUANCAOZUOJILUCallBackDelegate(
                    int Xuhao,
                    string Yonghuming,
                    Int64 Riqi,
                    string Caozuoleibie,
                    string Caozuoneirong
    );
    [UnmanagedFunctionPointerAttribute(CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
    public delegate void QuerySHEBEIGUANLICallBackDelegate(
                    int Xuhao,
                    int Chengshibianhao,
                    int Jubianhao,
                    int Shiyongdanweibianhao,
                    int IP,
                    string Shebeichangjia,
                    string Shebeimingcheng,
                    string Shebeileixing,
                    float Jingdu,
                    float Weidu,
                    Int64 Chuangjianshijian
    );
    [UnmanagedFunctionPointerAttribute(CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
    public delegate void QueryYINGSHEBIAOCallBackDelegate(
                    int Bianhao,
                    string Mingcheng
    );
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

        [DllImport("WorkDll.dll", CharSet=CharSet.Ansi, CallingConvention=CallingConvention.Cdecl, EntryPoint = "queryZHIQIANSHUJU")]
        private static extern void _queryZHIQIANSHUJU(string querySqlStr, IntPtr callback);
        [DllImport("WorkDll.dll", CharSet=CharSet.Ansi, CallingConvention=CallingConvention.Cdecl, EntryPoint = "querySHOUZHENGSHUJU")]
        private static extern void _querySHOUZHENGSHUJU(string querySqlStr, IntPtr callback);
        [DllImport("WorkDll.dll", CharSet=CharSet.Ansi, CallingConvention=CallingConvention.Cdecl, EntryPoint = "queryQIANZHUSHUJU")]
        private static extern void _queryQIANZHUSHUJU(string querySqlStr, IntPtr callback);
        [DllImport("WorkDll.dll", CharSet=CharSet.Ansi, CallingConvention=CallingConvention.Cdecl, EntryPoint = "queryJIAOKUANSHUJU")]
        private static extern void _queryJIAOKUANSHUJU(string querySqlStr, IntPtr callback);
        [DllImport("WorkDll.dll", CharSet=CharSet.Ansi, CallingConvention=CallingConvention.Cdecl, EntryPoint = "queryCHAXUNSHUJU")]
        private static extern void _queryCHAXUNSHUJU(string querySqlStr, IntPtr callback);
        [DllImport("WorkDll.dll", CharSet=CharSet.Ansi, CallingConvention=CallingConvention.Cdecl, EntryPoint = "queryYUSHOULISHUJU")]
        private static extern void _queryYUSHOULISHUJU(string querySqlStr, IntPtr callback);
        [DllImport("WorkDll.dll", CharSet=CharSet.Ansi, CallingConvention=CallingConvention.Cdecl, EntryPoint = "querySHEBEIZHUANGTAI")]
        private static extern void _querySHEBEIZHUANGTAI(string querySqlStr, IntPtr callback);
        [DllImport("WorkDll.dll", CharSet=CharSet.Ansi, CallingConvention=CallingConvention.Cdecl, EntryPoint = "querySHEBEIYICHANGSHUJU")]
        private static extern void _querySHEBEIYICHANGSHUJU(string querySqlStr, IntPtr callback);
        [DllImport("WorkDll.dll", CharSet=CharSet.Ansi, CallingConvention=CallingConvention.Cdecl, EntryPoint = "queryGUANLIYUAN")]
        private static extern void _queryGUANLIYUAN(string querySqlStr, IntPtr callback);
        [DllImport("WorkDll.dll", CharSet=CharSet.Ansi, CallingConvention=CallingConvention.Cdecl, EntryPoint = "queryGUANLIYUANCAOZUOJILU")]
        private static extern void _queryGUANLIYUANCAOZUOJILU(string querySqlStr, IntPtr callback);
        [DllImport("WorkDll.dll", CharSet=CharSet.Ansi, CallingConvention=CallingConvention.Cdecl, EntryPoint = "querySHEBEIGUANLI")]
        private static extern void _querySHEBEIGUANLI(string querySqlStr, IntPtr callback);
        [DllImport("WorkDll.dll", CharSet=CharSet.Ansi, CallingConvention=CallingConvention.Cdecl, EntryPoint = "queryYINGSHEBIAO")]
        private static extern void _queryYINGSHEBIAO(string querySqlStr, IntPtr callback);
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


        //public void QueryIDCARDAPPLY(string querySqlStr, IntPtr callback)
        //{
        //    //if (isServerStoped())
        //    //{
        //    //    startServer("127.0.0.1", 60000);
        //    //}

        //    //if(isClientStoped())
        //    //{
        //    //    startClient("127.0.0.1", 60000);
        //    //}

        //    _queryIDCARDAPPLY(querySqlStr, callback);
        //}

        public void QueryTable(string querySqlStr, IntPtr callback)
        {
            _queryTable(querySqlStr, callback);
        }

        public void QueryZHIQIANSHUJU(string querySqlStr, IntPtr callback)
        {
            _queryZHIQIANSHUJU(querySqlStr, callback);
        }
        public void QuerySHOUZHENGSHUJU(string querySqlStr, IntPtr callback)
        {
            _querySHOUZHENGSHUJU(querySqlStr, callback);
        }
        public void QueryQIANZHUSHUJU(string querySqlStr, IntPtr callback)
        {
            _queryQIANZHUSHUJU(querySqlStr, callback);
        }
        public void QueryJIAOKUANSHUJU(string querySqlStr, IntPtr callback)
        {
            _queryJIAOKUANSHUJU(querySqlStr, callback);
        }
        public void QueryCHAXUNSHUJU(string querySqlStr, IntPtr callback)
        {
            _queryCHAXUNSHUJU(querySqlStr, callback);
        }
        public void QueryYUSHOULISHUJU(string querySqlStr, IntPtr callback)
        {
            _queryYUSHOULISHUJU(querySqlStr, callback);
        }
        public void QuerySHEBEIZHUANGTAI(string querySqlStr, IntPtr callback)
        {
            _querySHEBEIZHUANGTAI(querySqlStr, callback);
        }
        public void QuerySHEBEIYICHANGSHUJU(string querySqlStr, IntPtr callback)
        {
            _querySHEBEIYICHANGSHUJU(querySqlStr, callback);
        }
        public void QueryGUANLIYUAN(string querySqlStr, IntPtr callback)
        {
            _queryGUANLIYUAN(querySqlStr, callback);
        }
        public void QueryGUANLIYUANCAOZUOJILU(string querySqlStr, IntPtr callback)
        {
            _queryGUANLIYUANCAOZUOJILU(querySqlStr, callback);
        }
        public void QuerySHEBEIGUANLI(string querySqlStr, IntPtr callback)
        {
            _querySHEBEIGUANLI(querySqlStr, callback);
        }
        public void QueryYINGSHEBIAO(string querySqlStr, IntPtr callback)
        {
            _queryYINGSHEBIAO(querySqlStr, callback);
        }
    }
}
