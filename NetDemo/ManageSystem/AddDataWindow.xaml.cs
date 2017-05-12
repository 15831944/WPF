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

        Random ran=new Random();
        
        public AddDataWindow()
        {
            InitializeComponent();

            Closing +=AddDataWindow_Closing;
        }

        void AddDataWindow_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            e.Cancel = true;
            Visibility = Visibility.Hidden;
        }


        //private void Button_Click(object sender, RoutedEventArgs e)
        //{
        //    int     selIndex    = selComb.SelectedIndex;
        //    int     addCount    = Convert.ToInt32(1);
        //    string  tableName   = "";
        //    Type    type        = null;

        //    switch(selIndex)
        //    {
        //        case 0:
        //            tableName   = "Zhiqianshuju";
        //            type        = typeof(SHEBEIGUANLIModel);
        //            break;
        //        case 1:
        //            tableName   = "Shouzhengshuju";
        //            type        = typeof(SHOUZHENGSHUJUModel);
        //            break;
        //        case 2:
        //            tableName   = "Qianzhushuju";
        //            type        = typeof(QIANZHUSHUJUModel);
        //            break;
        //        case 3:
        //            tableName   = "Jiaokuanshuju";
        //            type        = typeof(JIAOKUANSHUJUModel);
        //            break;
        //        case 4:
        //            tableName   = "Chaxunshuju";
        //            type        = typeof(CHAXUNSHUJUModel);
        //            break;
        //        case 5:
        //            tableName   = "Yushoulishuju";
        //            type        = typeof(YUSHOULISHUJUModel);
        //            break;
        //        case 6:
        //            tableName   = "Shebeizhuangtai";
        //            type        = typeof(SHEBEIZHUANGTAIModel);
        //            break;
        //        case 7:
        //            tableName   = "Shebeiyichangshuju";
        //            type        = typeof(SHEBEIYICHANGSHUJUModel);
        //            break;
        //        case 8:
        //            tableName   = "Guanliyuan";
        //            type        = typeof(GUANLIYUANModel);
        //            break;
        //        case 9:
        //            tableName   = "Guanliyuancaozuojilu";
        //            type        = typeof(GUANLIYUANCAOZUOJILUModel);
        //            break;
        //        case 10:
        //            tableName   = "Shebeiguanli";
        //            type        = typeof(SHEBEIGUANLIModel);
        //            break;
        //        case 11:
        //            tableName   = "Yingshebiao";
        //            type        = null;
        //            string addXml = 
        //                "Bianhao:0,Mingcheng:深圳市;"              +
        //                "Bianhao:1,Mingcheng:广州市;"              +
        //                "Bianhao:2001,Mingcheng:南山公安局;"         +
        //                "Bianhao:2002,Mingcheng:白云公安局;"         +
        //                "Bianhao:3001,Mingcheng:南山分局管理科;"         +
        //                "Bianhao:3002,Mingcheng:白云分局管理科;"         +
        //                "Bianhao:4001,Mingcheng:大陆;"                +
        //                "Bianhao:4002,Mingcheng:香港;"                +
        //                "Bianhao:4003,Mingcheng:台湾;"                +
        //                "Bianhao:5001,Mingcheng:深圳;"                +
        //                "Bianhao:5002,Mingcheng:广州;"                +
        //                "Bianhao:6001,Mingcheng:签注种类1;"         +
        //                "Bianhao:6002,Mingcheng:签注种类2;"         +
        //                "Bianhao:7001,Mingcheng:成功;"            +
        //                "Bianhao:7002,Mingcheng:失败;"            +
        //                "Bianhao:7003,Mingcheng:异常;"            +
        //                "Bianhao:8001,Mingcheng:男;"         +
        //                "Bianhao:8002,Mingcheng:女;"         +
        //                "Bianhao:9001,Mingcheng:本式;"         +
        //                "Bianhao:9002,Mingcheng:卡式;"         +
        //                "Bianhao:10001,Mingcheng:异常类型1;"         +
        //                "Bianhao:10002,Mingcheng:异常类型2;"         
        //                ;
                    
        //            if (tableName != null && tableName.Length != 0)
        //                _addTable(tableName, addXml, IntPtr.Zero, true);
        //            break;
        //    }

        //    if(type != null)
        //    {
        //        System.Reflection.PropertyInfo[] properties = type.GetProperties(System.Reflection.BindingFlags.Instance | System.Reflection.BindingFlags.Public);

        //        DateTime time = DateTime.Now;
        //        string addXml = "";
        //        for (int i = 0; i < addCount; ++i)
        //        {
        //            foreach (System.Reflection.PropertyInfo item in properties)
        //            {
        //                if (item.PropertyType.Name.StartsWith("Int32"))
        //                {
        //                    addXml += item.Name;
        //                    addXml += ":";
        //                    switch (item.Name)
        //                    {
        //                        case "Xuhao":
        //                            addXml += "0";
        //                            break;
        //                        default:
        //                            addXml += ran.Next().ToString();
        //                            break;
        //                    }
        //                }
        //                else if (item.PropertyType.Name.StartsWith("Int64"))
        //                {
        //                    addXml += item.Name;
        //                    addXml += ":";
        //                    addXml += ran.Next().ToString();
        //                }
        //                else if (item.PropertyType.Name.StartsWith("Single"))
        //                {
        //                    addXml += item.Name;
        //                    addXml += ":";
        //                    addXml += ran.Next().ToString();
        //                }
        //                else if (item.PropertyType.Name.StartsWith("String"))
        //                {
        //                    addXml += item.Name;
        //                    addXml += ":";
        //                    switch (item.Name)
        //                    {
        //                        case "Chengshibianhao":
        //                            addXml += ((i%2 == 0) ? 0:1).ToString();
        //                            break;
        //                        case "Jubianhao":
        //                            addXml += ((i%2 == 0) ? 2001:2002).ToString();
        //                            break;
        //                        case "Shiyongdanweibianhao":
        //                            addXml += ((i%2 == 0) ? 3001:3002).ToString();
        //                            break;
        //                        case "IP":
        //                            addXml += (UInt32)(IPAddress.HostToNetworkOrder((Int32)Common.IpToInt("127.0.0.1")));
        //                            break;
        //                        case "Yewuleixing":
        //                            addXml += ((i%2 == 0) ? 4001:4002).ToString();
        //                            break;
        //                        case "Shebeibaifangweizhi":
        //                            addXml += ((i%2 == 0) ? 5001:5002).ToString();
        //                            break;
        //                        case "Riqi":
        //                            addXml += Common.ConvertDateTimeInt(DateTime.Now);
        //                            break;
        //                        case "Qianzhuzhonglei":
        //                            addXml += ((i%2 == 0) ? 6001:6002).ToString();
        //                            break;
        //                        case "ZhikaZhuangtai":
        //                            addXml += ((i%2 == 0) ? 7001:7002).ToString();
        //                            break;
        //                        case "Xingbie":
        //                            addXml += ((i%2 == 0) ? 8001:8002).ToString();
        //                            break;
        //                        case "Zhengjianleixing":
        //                            addXml += ((i%2 == 0) ? 9001:9002).ToString();
        //                            break;
        //                        case "Yichangleixing":
        //                            addXml += ((i%2 == 0) ? 10001:10002).ToString();
        //                            break;
        //                        default:
        //                            addXml += ran.Next().ToString();
        //                            break;
        //                    }
        //                }
        //                else if (item.PropertyType.Name.StartsWith("Boolean"))
        //                {
        //                    addXml += item.Name;
        //                    addXml += ":";
        //                    addXml += (i%2 == 0) ? "0" : "1";
        //                }
        //                else
        //                {
        //                    ;
        //                }
        //                addXml += ",";
        //            }
        //            addXml += ";";
        //        }

        //        if (tableName != null && tableName.Length != 0)
        //            _addTable(tableName, addXml, IntPtr.Zero, true);
        //    }
        //}
    }
}
