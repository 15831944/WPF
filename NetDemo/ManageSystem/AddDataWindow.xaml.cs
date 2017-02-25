using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Runtime.InteropServices;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace ManageSystem
{

    public partial class AddDataWindow : Window
    {
        public static long IpToInt(string ip)
        {
            char[] separator = new char[] { '.' };
            string[] items = ip.Split(separator);
            return long.Parse(items[0]) << 24
                    | long.Parse(items[1]) << 16
                    | long.Parse(items[2]) << 8 
                    | long.Parse(items[3]);
        }
        public static string IntToIp(long ipInt)
        {
            StringBuilder sb = new StringBuilder();
            sb.Append((ipInt >> 24) & 0xFF).Append(".");
            sb.Append((ipInt >> 16) & 0xFF).Append(".");
            sb.Append((ipInt >> 8) & 0xFF).Append(".");
            sb.Append(ipInt & 0xFF);
            return sb.ToString();
        }

        [DllImport("WorkDll.dll", CharSet=CharSet.Ansi, CallingConvention=CallingConvention.Cdecl, EntryPoint = "addZHIQIANSHUJU")]
        private static extern void _addZHIQIANSHUJU(
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
                        string Lianxidianhua,
                        IntPtr callback);

        [DllImport("WorkDll.dll", CharSet=CharSet.Ansi, CallingConvention=CallingConvention.Cdecl, EntryPoint = "addSHOUZHENGSHUJU")]
        private static extern void _addSHOUZHENGSHUJU(
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
                        bool Shifoujiaofei,
                        IntPtr callback);
        [DllImport("WorkDll.dll", CharSet=CharSet.Ansi, CallingConvention=CallingConvention.Cdecl, EntryPoint = "addQIANZHUSHUJU")]
        private static extern void _addQIANZHUSHUJU(
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
                        string Shouliren,
                        IntPtr callback);
        [DllImport("WorkDll.dll", CharSet=CharSet.Ansi, CallingConvention=CallingConvention.Cdecl, EntryPoint = "addJIAOKUANSHUJU")]
        private static extern void _addJIAOKUANSHUJU(
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
                        Int64 Jiaoyiriqi,
                        IntPtr callback);
        [DllImport("WorkDll.dll", CharSet=CharSet.Ansi, CallingConvention=CallingConvention.Cdecl, EntryPoint = "addCHAXUNSHUJU")]
        private static extern void _addCHAXUNSHUJU(
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
                        Int64 Chuangjianshijian,
                        IntPtr callback);
        [DllImport("WorkDll.dll", CharSet=CharSet.Ansi, CallingConvention=CallingConvention.Cdecl, EntryPoint = "addYUSHOULISHUJU")]
        private static extern void _addYUSHOULISHUJU(
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
                        Int64 Chuangjianshijian,
                        IntPtr callback);

        [DllImport("WorkDll.dll", CharSet=CharSet.Ansi, CallingConvention=CallingConvention.Cdecl, EntryPoint = "addSHEBEIZHUANGTAI")]
        private static extern void _addSHEBEIZHUANGTAI(
                        int Xuhao,
                        int Chengshibianhao,
                        int Jubianhao,
                        int Shiyongdanweibianhao,
                        int IP,
                        bool Bendiyewu,
                        int Shebeibaifangweizhi,
                        Int64 Riqi,
                        bool Shifouzaixian,
                        IntPtr callback);
        [DllImport("WorkDll.dll", CharSet=CharSet.Ansi, CallingConvention=CallingConvention.Cdecl, EntryPoint = "addSHEBEIYICHANGSHUJU")]
        private static extern void _addSHEBEIYICHANGSHUJU(
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
                        string Yichangxiangxineirong,
                        IntPtr callback);
        [DllImport("WorkDll.dll", CharSet=CharSet.Ansi, CallingConvention=CallingConvention.Cdecl, EntryPoint = "addGUANLIYUAN")]
        private static extern void _addGUANLIYUAN(
                        int Xuhao,
                        string Yonghuming,
                        string Mima,
                        int Youxiaoqikaishi,
                        int Youxiaoqijieshu,
                        int Quanxianjibie,
                        IntPtr callback);
        [DllImport("WorkDll.dll", CharSet=CharSet.Ansi, CallingConvention=CallingConvention.Cdecl, EntryPoint = "addGUANLIYUANCAOZUOJILU")]
        private static extern void _addGUANLIYUANCAOZUOJILU(
                        int Xuhao,
                        string Yonghuming,
                        Int64 Riqi,
                        string Caozuoleibie,
                        string Caozuoneirong,
                        IntPtr callback);
        [DllImport("WorkDll.dll", CharSet=CharSet.Ansi, CallingConvention=CallingConvention.Cdecl, EntryPoint = "addSHEBEIGUANLI")]
        private static extern void _addSHEBEIGUANLI(
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
                        Int64 Chuangjianshijian,
                        IntPtr callback);
        [DllImport("WorkDll.dll", CharSet=CharSet.Ansi, CallingConvention=CallingConvention.Cdecl, EntryPoint = "addYINGSHEBIAO")]
        private static extern void _addYINGSHEBIAO(
                        int Bianhao,
                        string Mingcheng,
                        IntPtr callback);

        Random ran=new Random();
        
        public AddDataWindow()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            int selIndex = selComb.SelectedIndex;
            int addCount = Convert.ToInt32(addCountbox.Text);

            switch(selIndex)
            {
                case 0:
                    for (int i = 0; i < addCount; ++i)
                    {
                        _addZHIQIANSHUJU(
                            0,
                            (i%2 == 0) ? 0:1, //城市编号
                            (i%2 == 0) ? 2001:2002,//局编号
                            (i%2 == 0) ? 3001:3002,//使用单位编号
                            Convert.ToInt32(IPAddress.HostToNetworkOrder((Int32)IpToInt("127.0.0.1"))),
                            false,
                            (i%2 == 0) ? 5001:5002,//设备摆放位置
                            (Int32)DateTime.Now.ToFileTime(),
                            i.ToString() + ran.Next(),
                            i.ToString(),
                            i.ToString(),
                            (i%2 == 0) ? 6001:6002,//
                            (i%2 == 0) ? 7001:7002,//签注种类
                            i.ToString(),
                            i.ToString(),
                            i.ToString(),
                            IntPtr.Zero
                             );
                    }       
                    break;
                case 1:
                    for (int i = 0; i < addCount; ++i)
                    {
                        _addSHOUZHENGSHUJU(
                            i,
                            (i%2 == 0) ? 0:1, //城市编号
                            (i%2 == 0) ? 2001:2002,//局编号
                            (i%2 == 0) ? 3001:3002,//使用单位编号
                            Convert.ToInt32(IPAddress.HostToNetworkOrder((Int32)IpToInt("127.0.0.1"))),
                            false,
                            (i%2 == 0) ? 5001:5002,//设备摆放位置
                            (Int32)DateTime.Now.ToFileTime(),
                            (i%2 == 0) ? 9001:9002,//证件类型
                            i.ToString() + ran.Next(),
                            i.ToString() + ran.Next(),
                            i.ToString() + ran.Next(),
                            false,
                            IntPtr.Zero
                             );
                    }   
                    break;
                case 2:
                    for (int i = 0; i < addCount; ++i)
                    {
                        _addQIANZHUSHUJU(
                            i,
                            (i%2 == 0) ? 0:1, //城市编号
                            (i%2 == 0) ? 2001:2002,//局编号
                            (i%2 == 0) ? 3001:3002,//使用单位编号
                            Convert.ToInt32(IPAddress.HostToNetworkOrder((Int32)IpToInt("127.0.0.1"))),
                            false,
                            (i%2 == 0) ? 5001:5002,//设备摆放位置
                            (Int32)DateTime.Now.ToFileTime(),
                            i.ToString() + ran.Next(),
                            i.ToString() + ran.Next(),
                            (i%2 == 0) ? 8001:8002,//性别
                            (Int32)DateTime.Now.ToFileTime(),
                            i.ToString() + ran.Next(),
                            (i%2 == 0) ? 4001:4002,//业务类型
                            i.ToString() + ran.Next(),
                            IntPtr.Zero
                             );
                    } 
                    break;
                case 3:
                    for (int i = 0; i < addCount; ++i)
                    {
                        _addJIAOKUANSHUJU(
                            i,
                            (i%2 == 0) ? 0:1, //城市编号
                            (i%2 == 0) ? 2001:2002,//局编号
                            (i%2 == 0) ? 3001:3002,//使用单位编号
                            Convert.ToInt32(IPAddress.HostToNetworkOrder((Int32)IpToInt("127.0.0.1"))),
                            false,
                            (i%2 == 0) ? 5001:5002,//设备摆放位置
                            (Int32)DateTime.Now.ToFileTime(),
                            i.ToString() + ran.Next(),
                            i.ToString() + ran.Next(),
                            i.ToString() + ran.Next(),
                            ran.Next(),
                            (Int32)DateTime.Now.ToFileTime(),
                            IntPtr.Zero
                             );
                    } 
                    break;
                case 4:
                    for (int i = 0; i < addCount; ++i)
                    {
                        _addCHAXUNSHUJU(
                            i,
                            (i%2 == 0) ? 0:1, //城市编号
                            (i%2 == 0) ? 2001:2002,//局编号
                            (i%2 == 0) ? 3001:3002,//使用单位编号
                            Convert.ToInt32(IPAddress.HostToNetworkOrder((Int32)IpToInt("127.0.0.1"))),
                            false,
                            (i%2 == 0) ? 5001:5002,//设备摆放位置
                            (Int32)DateTime.Now.ToFileTime(),
                            i.ToString() + ran.Next(),
                            i.ToString() + ran.Next(),
                            false,
                            (Int32)DateTime.Now.ToFileTime(),
                            IntPtr.Zero
                             );
                    } 
                    break;
                case 5:
                    for (int i = 0; i < addCount; ++i)
                    {
                        _addYUSHOULISHUJU(
                            i,
                            (i%2 == 0) ? 0:1, //城市编号
                            (i%2 == 0) ? 2001:2002,//局编号
                            (i%2 == 0) ? 3001:3002,//使用单位编号
                            Convert.ToInt32(IPAddress.HostToNetworkOrder((Int32)IpToInt("127.0.0.1"))),
                            false,
                            (i%2 == 0) ? 5001:5002,//设备摆放位置
                            (Int32)DateTime.Now.ToFileTime(),
                            i.ToString() + ran.Next(),
                            i.ToString() + ran.Next(),
                            i.ToString() + ran.Next(),
                            i.ToString() + ran.Next(),
                            i.ToString() + ran.Next(),
                            (i%2 == 0) ? 6001:6002,//签注种类
                            (i%2 == 0) ? 8001:8002,//性别
                            i.ToString() + ran.Next(),
                            "汉",
                            (Int32)DateTime.Now.ToFileTime(),
                            IntPtr.Zero
                             );
                    } 
                    break;
                case 6:
                    break;
                case 7:
                    break;
                case 8:
                    break;
                case 9:
                    break;
                case 10:
                    for (int i = 0; i < addCount; ++i)
                    {
                        _addSHEBEIGUANLI(
                            0,
                            (i%2 == 0) ? 0:1, //城市编号
                            (i%2 == 0) ? 2001:2002,//局编号
                            (i%2 == 0) ? 3001:3002,//使用单位编号
                            Convert.ToInt32(IPAddress.HostToNetworkOrder((Int32)IpToInt("127.0.0.1"))),
                            i.ToString() + ran.Next(),
                            i.ToString() + ran.Next(),
                            i.ToString() + ran.Next(),
                            ran.Next(),
                            ran.Next(),
                            (Int32)DateTime.Now.ToFileTime(),
                            IntPtr.Zero
                             );
                    } 
                    break;
                case 11:
                    break;
            }

        }
    }
}
