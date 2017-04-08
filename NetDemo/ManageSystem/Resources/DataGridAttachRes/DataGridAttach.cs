using ManageSystem.Resources.AnimationAttachRes;
using ManageSystem.Server;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading;
using System.Windows;
using System.Windows.Controls;

namespace ManageSystem.Resources.DataGridAttachRes
{
    public class DataGridAttach : DependencyObject
    {
        public static Dictionary<string, string>               _columnNameMap = new Dictionary<string, string>
        {
            {"Xuhao",				    "序号"},
            {"Chengshibianhao",		    "城市编号"},
            {"Jubianhao",			    "局编号"},
            {"Shiyongdanweibianhao",	"使用单位编号"},
            {"IP",					    "ip地址"},
            {"Bendiyewu",			    "是否本地业务"},
            {"Shebeibaifangweizhi",	    "设备摆放位置"},
            {"Riqi",					"日期"},
            {"Yewubianhao",			    "业务编号"},
            {"YuanZhengjianhaoma",	    "原证件号码"},
            {"Xingming",				"姓名"},
            {"Qianzhuzhonglei",		    "签注种类"},
            {"ZhikaZhuangtai",		    "制卡状态"},
            {"Zhengjianhaoma",		    "证件号码"},
            {"Jiekoufanhuijieguo",	    "接口返回结果"},
            {"Lianxidianhua",		    "联系电话"},

            {"Xingbie",				    "性别"},			
            {"Chushengriqi",			"出生日期"},		
            {"Yewuleixing",			    "业务类型"},		
            {"Shouliren",				"受理人"},			
            {"Zhengjianleixing",		"证件类型"},			
            {"Shifoucharudajizhong",	"是否插入大集中"},	

            {"Shoulibianhao",			"受理编号"},
            {"Shifoujiaofei",			"是否缴费"},

            {"Zhishoudanweidaima",		"执收单位代码"},	
            {"Jiaokuantongzhishuhaoma", "缴款通知书号码"},	
            {"Jiaokuanrenxingming",	    "缴款人姓名"},		
            {"Yingkoukuanheji",		    "应扣款合计"},		
            {"Jiaoyiriqi",				"交易日期"},		
            {"Jiaofeizhuangtai",		"缴费状态"},		

            {"Chaxunhaoma",				"查询号码"},		
            {"Chaxunleixing",			"查询类型"},		
            {"Shifouchaxunchenggong",	"是否查询成功"},	
            {"Chuangjianshijian",		"创建时间"},
	
            {"Chuguoshiyou",			"出国事由"},
            {"Hukousuozaidi",			"户口所在地"},
            {"Minzu",					"民族"},
            {"Shenfenzhenghao", 		"身份证号"},

           
            {"Shebeichangjia",			"设备厂家"},		
            {"Shebeimingcheng",		    "设备名称"},		
            {"Shebeileixing",			"设备类型"},		
            {"Jingdu",					"经度"},			
            {"Weidu",					"纬度"},			
            {"Yingjianxinxi",			"硬件信息"},	
            {"Ruanjianxinxi",			"软件信息"},	
            {"Ruanjianshengjixinxi",	"软件升级信息"},	

                        
            {"Yonghuming",	            "用户名"},
            {"Mima",	                "密码"},
            {"Youxiaoqikaishi",	        "有效期起始"},
            {"Youxiaoqijieshu",	        "有效期截至"},
            {"Quanxianjibie",	        "权限级别"},

            {"Yichangleixing",	        "异常类型"},		
            {"Yichangshejimokuai",	    "异常涉及模块"},	
            {"Yichangyuanyin",	        "异常原因"},		
            {"Yichangxiangxineirong",	"异常详细内容"},	

            {"Bianhao",	                "编号"},		
            {"Mingcheng",	            "名称"},	

            {"operateinfomodel",	        "操作"},	
            {"bSel",	""},	
        };

        //Access and update columns during autogeneration
        public static void DG1_AutoGeneratingColumn(object sender, DataGridAutoGeneratingColumnEventArgs e)
        {
            string headername = e.Column.Header.ToString();

            //Cancel the column you don't want to generate
            if (_columnNameMap.ContainsKey(headername))
            {
                if(headername == "operateinfomodel")
                {
                    var obj = DataGridAttach.GetOperateCellStyle(sender as DependencyObject);
                    if (obj != null)
                        e.Column.CellStyle = obj;
                    else
                        e.Cancel = true;
                }
                //else if (headername == "bSel")
                //{
                //    var obj = DataGridAttach.GetOperateCellStyle(sender as DependencyObject);
                //    if (obj != null)
                //        e.Column.CellStyle = obj;
                //    else
                //        e.Cancel = true;
                //}
                e.Column.Header = _columnNameMap[headername];
            }
            else
                e.Cancel = true;
        }


        public static object GetGeneratColumnObj(DependencyObject obj)
        {
            return (object)obj.GetValue(GeneratColumnObjProperty);
        }

        public static void SetGeneratColumnObj(DependencyObject obj, object value)
        {
            obj.SetValue(GeneratColumnObjProperty, value);
        }

        // Using a DependencyProperty as the backing store for GeneratColumnObj.  This enables animation, styling, binding, etc...
        public static readonly DependencyProperty GeneratColumnObjProperty =
    DependencyProperty.RegisterAttached("GeneratColumnObj", typeof(object), typeof(DataGridAttach), new PropertyMetadata(null, OnGeneratColumnObjChanged));

        private static void OnGeneratColumnObjChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
        {
            DataGrid grid   = d as DataGrid;
            grid.AutoGeneratingColumn += DG1_AutoGeneratingColumn;
        }

        /******************************************************************************************/

        public static object GetGridBeginEditFunc(DependencyObject obj)
        {
            return (object)obj.GetValue(GridBeginEditFuncProperty);
        }

        public static void SetGridBeginEditFunc(DependencyObject obj, object value)
        {
            obj.SetValue(GridBeginEditFuncProperty, value);
        }

        // Using a DependencyProperty as the backing store for GridBeginEditFunc.  This enables animation, styling, binding, etc...
        public static readonly DependencyProperty GridBeginEditFuncProperty =
    DependencyProperty.RegisterAttached("GridBeginEditFunc", typeof(object), typeof(DataGridAttach), new PropertyMetadata(null, OnGridBeginEditFuncChanged));

        private static void OnGridBeginEditFuncChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
        {
            DataGrid grid       = d as DataGrid;
            grid.BeginningEdit  += GridBeginEditFunc;
        }

        private static void GridBeginEditFunc(object sender, DataGridBeginningEditEventArgs e)
        {
            if (e.Column.DisplayIndex > 0) //第0列即使进入编辑状态，TextBlock也不能编辑
            {
                e.Cancel = true;
                return;
            }
        }

        /******************************************************************************************/

        public static object  GetbSelectAll(DependencyObject obj)
        {
            return (object )obj.GetValue(bSelectAllProperty);
        }

        public static void SetbSelectAll(DependencyObject obj, object  value)
        {
            obj.SetValue(bSelectAllProperty, value);
        }

        // Using a DependencyProperty as the backing store for bSelectAll.  This enables animation, styling, binding, etc...
        public static readonly DependencyProperty bSelectAllProperty =
    DependencyProperty.RegisterAttached("bSelectAll", typeof(object ), typeof(DataGridAttach), new PropertyMetadata(null, OnbSelectAllChanged));

        private static void OnbSelectAllChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
        {
            if(e.NewValue != null && e.OldValue != null)
            {
                if (e.NewValue != e.OldValue)
                {
                    DataGrid data = Common.GetParentObject<DataGrid>(d, "");
                    foreach(var item in data.Items)
                    {
                        item.GetType().GetProperty("bSel").SetValue(item, e.NewValue, null);
                    }
                }
            }
        }

        /******************************************************************************************/

        public static object GetNumOfPage(DependencyObject obj)
        {
            return (object)obj.GetValue(NumOfPageProperty);
        }

        public static void SetNumOfPage(DependencyObject obj, object value)
        {
            obj.SetValue(NumOfPageProperty, value);
        }

        // Using a DependencyProperty as the backing store for NumOfPage.  This enables animation, styling, binding, etc...
        public static readonly DependencyProperty NumOfPageProperty =
    DependencyProperty.RegisterAttached("NumOfPage", typeof(object), typeof(DataGridAttach), new PropertyMetadata(0,OnNumOfPageChanged));

        private static void OnNumOfPageChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
        {
            try
            {
                DataGrid grid       = d as DataGrid;
                var viewmodel       = grid.DataContext;

                int num = Convert.ToInt32((grid.ActualHeight - 50) / 30);
                viewmodel.GetType().GetProperty("numofpage").SetValue(viewmodel, num > 0? num - 1: num, null);
                viewmodel.GetType().GetMethod("ShowPage").Invoke(viewmodel, new object[] { 1 });
            }
            catch (Exception ex)
            { 
                string str = ex.Message;
            }
        }

        /******************************************************************************************/

        public static Style GetOperateCellStyle(DependencyObject obj)
        {
            return (Style)obj.GetValue(OperateCellStyleProperty);
        }

        public static void SetOperateCellStyle(DependencyObject obj, Style value)
        {
            obj.SetValue(OperateCellStyleProperty, value);
        }

        // Using a DependencyProperty as the backing store for OperateCellStyle.  This enables animation, styling, binding, etc...
        public static readonly DependencyProperty OperateCellStyleProperty =
    DependencyProperty.RegisterAttached("OperateCellStyle", typeof(Style), typeof(DataGridAttach), new PropertyMetadata(null));

        /******************************************************************************************/



        public static object GetAttachGridAnimation(DependencyObject obj)
        {
            return (object)obj.GetValue(AttachGridAnimationProperty);
        }

        public static void SetAttachGridAnimation(DependencyObject obj, object value)
        {
            obj.SetValue(AttachGridAnimationProperty, value);
        }

        // Using a DependencyProperty as the backing store for AttachGridAnimation.  This enables animation, styling, binding, etc...
        public static readonly DependencyProperty AttachGridAnimationProperty =
    DependencyProperty.RegisterAttached("AttachGridAnimation", typeof(object), typeof(DataGridAttach), new PropertyMetadata(false, OnAttachGridAnimationChanged));

        private static void OnAttachGridAnimationChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
        {
            try
            {
                ColumnDefinition columndefinition = e.NewValue as ColumnDefinition;
                Button btn = d as Button;
                btn.Click += (sender, routedeventargs) =>
                    {
                        GridLengthAnimation animation = new GridLengthAnimation();
                        animation.From = columndefinition.Width;
                        animation.To = new GridLength(0.3, GridUnitType.Star);
                        animation.Duration = new Duration(TimeSpan.FromSeconds(0.5));

                        columndefinition.BeginAnimation(ColumnDefinition.WidthProperty, animation);
                    };
            }
            catch { }
        }

        /******************************************************************************************/
        

        public static object GetMyTest(DependencyObject obj)
        {
            return (object)obj.GetValue(MyTestProperty);
        }

        public static void SetMyTest(DependencyObject obj, object value)
        {
            obj.SetValue(MyTestProperty, value);
        }

        // Using a DependencyProperty as the backing store for MyTest.  This enables animation, styling, binding, etc...
        public static readonly DependencyProperty MyTestProperty =
    DependencyProperty.RegisterAttached("MyTest", typeof(object), typeof(DataGridAttach), new PropertyMetadata(null, OnMyTestChanged));

        private static void OnMyTestChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
        {
            try
            {
    
            }
            catch { }
        }
    }
}
