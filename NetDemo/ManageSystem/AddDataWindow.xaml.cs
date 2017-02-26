using ManageSystem.Model;
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


        [DllImport("WorkDll.dll", CharSet=CharSet.Ansi, CallingConvention=CallingConvention.Cdecl, EntryPoint = "addTable")]
        private static extern void _addTable(
                        string tableName,
                        string dataStr,
                        IntPtr callback);

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
                    {
                        System.Reflection.PropertyInfo[] properties = typeof(ZHIQIANSHUJUModel).GetProperties(System.Reflection.BindingFlags.Instance | System.Reflection.BindingFlags.Public);

                        DateTime time = DateTime.Now;
                        string addXml = "";
                        for (int i = 0; i < addCount; ++i)
                        {
                            foreach (System.Reflection.PropertyInfo item in properties)
                            {
                                if (item.PropertyType.Name.StartsWith("Int32"))
                                {
                                    addXml += item.Name;
                                    addXml += ":";
                                    switch (item.Name)
                                    {
                                        case "Xuhao":
                                            addXml += "0";
                                            break;
                                        default:
                                            addXml += ran.Next().ToString();
                                            break;
                                    }
                                }
                                else if (item.PropertyType.Name.StartsWith("Int64"))
                                {
                                    addXml += item.Name;
                                    addXml += ":";
                                    addXml += ran.Next().ToString();
                                }
                                else if (item.PropertyType.Name.StartsWith("String"))
                                {
                                    addXml += item.Name;
                                    addXml += ":";
                                    switch (item.Name)
                                    {
                                        case "Chengshibianhao":
                                            addXml += ((i%2 == 0) ? 0:1).ToString();
                                            break;
                                        case "Jubianhao":
                                            addXml += ((i%2 == 0) ? 2001:2002).ToString();
                                            break;
                                        case "Shiyongdanweibianhao":
                                            addXml += ((i%2 == 0) ? 3001:3002).ToString();
                                            break;
                                        case "IP":
                                            addXml += Convert.ToInt32(IPAddress.HostToNetworkOrder((Int32)Common.IpToInt("127.0.0.1")));
                                            break;
                                        case "Shebeibaifangweizhi":
                                            addXml += ((i%2 == 0) ? 5001:5002).ToString();
                                            break;
                                        case "Riqi":
                                            addXml += Common.ConvertDateTimeInt(DateTime.Now);
                                            break;
                                        case "Qianzhuzhonglei":
                                            addXml += ((i%2 == 0) ? 6001:6002).ToString();
                                            break;
                                        case "ZhikaZhuangtai":
                                            addXml += ((i%2 == 0) ? 7001:7002).ToString();
                                            break;
                                        default:
                                            addXml += ran.Next().ToString();
                                            break;
                                    }
                                }
                                else if (item.PropertyType.Name.StartsWith("Boolean"))
                                {
                                    addXml += item.Name;
                                    addXml += ":";
                                    addXml += "0";
                                }
                                else
                                {
                                    ;
                                }
                                addXml += ",";
                            }
                            addXml += ";";
                        }

                        _addTable("Zhiqianshuju", addXml, IntPtr.Zero);
                        TimeSpan span =  DateTime.Now - time;
                    }

                    //{
                    //    DateTime time = DateTime.Now;
                    //    for (int i = 0; i < addCount; ++i)
                    //    {
                    //        _addZHIQIANSHUJU(
                    //            0,
                    //            (i%2 == 0) ? 0:1, //城市编号
                    //            (i%2 == 0) ? 2001:2002,//局编号
                    //            (i%2 == 0) ? 3001:3002,//使用单位编号
                    //            Convert.ToInt32(IPAddress.HostToNetworkOrder((Int32)IpToInt("127.0.0.1"))),
                    //            false,
                    //            (i%2 == 0) ? 5001:5002,//设备摆放位置
                    //            (Int64)Common.ConvertDateTimeInt(DateTime.Now),
                    //            i.ToString() + ran.Next(),
                    //            i.ToString(),
                    //            i.ToString(),
                    //            (i%2 == 0) ? 6001:6002,//
                    //            (i%2 == 0) ? 7001:7002,//签注种类
                    //            i.ToString(),
                    //            i.ToString(),
                    //            i.ToString(),
                    //            IntPtr.Zero
                    //             );
                    //    }
                    //    TimeSpan span =  DateTime.Now - time;
                    //}
                    
                    break;
                case 1:
                    for (int i = 0; i < addCount; ++i)
                    {
                        _addSHOUZHENGSHUJU(
                            i,
                            (i%2 == 0) ? 0:1, //城市编号
                            (i%2 == 0) ? 2001:2002,//局编号
                            (i%2 == 0) ? 3001:3002,//使用单位编号
                            Convert.ToInt32(IPAddress.HostToNetworkOrder((Int32)Common.IpToInt("127.0.0.1"))),
                            false,
                            (i%2 == 0) ? 5001:5002,//设备摆放位置
                            (Int64)Common.ConvertDateTimeInt(DateTime.Now),
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
                            Convert.ToInt32(IPAddress.HostToNetworkOrder((Int32)Common.IpToInt("127.0.0.1"))),
                            false,
                            (i%2 == 0) ? 5001:5002,//设备摆放位置
                            (Int64)Common.ConvertDateTimeInt(DateTime.Now),
                            i.ToString() + ran.Next(),
                            i.ToString() + ran.Next(),
                            (i%2 == 0) ? 8001:8002,//性别
                            (Int64)Common.ConvertDateTimeInt(DateTime.Now),
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
                            Convert.ToInt32(IPAddress.HostToNetworkOrder((Int32)Common.IpToInt("127.0.0.1"))),
                            false,
                            (i%2 == 0) ? 5001:5002,//设备摆放位置
                            (Int64)Common.ConvertDateTimeInt(DateTime.Now),
                            i.ToString() + ran.Next(),
                            i.ToString() + ran.Next(),
                            i.ToString() + ran.Next(),
                            ran.Next(),
                            (Int64)Common.ConvertDateTimeInt(DateTime.Now),
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
                            Convert.ToInt32(IPAddress.HostToNetworkOrder((Int32)Common.IpToInt("127.0.0.1"))),
                            false,
                            (i%2 == 0) ? 5001:5002,//设备摆放位置
                            (Int64)Common.ConvertDateTimeInt(DateTime.Now),
                            i.ToString() + ran.Next(),
                            i.ToString() + ran.Next(),
                            false,
                            (Int64)Common.ConvertDateTimeInt(DateTime.Now),
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
                            Convert.ToInt32(IPAddress.HostToNetworkOrder((Int32)Common.IpToInt("127.0.0.1"))),
                            false,
                            (i%2 == 0) ? 5001:5002,//设备摆放位置
                            (Int64)Common.ConvertDateTimeInt(DateTime.Now),
                            i.ToString() + ran.Next(),
                            i.ToString() + ran.Next(),
                            i.ToString() + ran.Next(),
                            i.ToString() + ran.Next(),
                            i.ToString() + ran.Next(),
                            (i%2 == 0) ? 6001:6002,//签注种类
                            (i%2 == 0) ? 8001:8002,//性别
                            i.ToString() + ran.Next(),
                            "汉",
                            (Int64)Common.ConvertDateTimeInt(DateTime.Now),
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
                            Convert.ToInt32(IPAddress.HostToNetworkOrder((Int32)Common.IpToInt("127.0.0.1"))),
                            i.ToString() + ran.Next(),
                            i.ToString() + ran.Next(),
                            i.ToString() + ran.Next(),
                            ran.Next(),
                            ran.Next(),
                            (Int64)Common.ConvertDateTimeInt(DateTime.Now),
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
