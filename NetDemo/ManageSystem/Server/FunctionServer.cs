using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Controls;

namespace ManageSystem.Server
{
    public class FunctionServer
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

            {"bSel",	""},	
        };

        //Access and update columns during autogeneration
        public static void DG1_AutoGeneratingColumn(object sender, DataGridAutoGeneratingColumnEventArgs e)
        {
            string headername = e.Column.Header.ToString();
            //Cancel the column you don't want to generate
            if (_columnNameMap.ContainsKey(headername))
            {
                e.Column.Header = _columnNameMap[headername];
            }
        }
    }
}
