//********************************************************************
// SQLITEDATADEFINE.H 文件注释
// 文件名 　: SQLITEDATADEFINE.H
// 文件路径 : E:\PROJECT\RIM3.0\SRC\SDK\RIM30TOOLKIT/
// 作者 　　: 张永
// 创建时间 : 2015/4/23 14:28
// 文件描述 : 
//*********************************************************************
#pragma once

/*******************************/

/** 自助设备本地数据库（业务审核） */
#define T_IDCARDAPPLY															"idCardApply"
#define T_IDCARDAPPLY_NAME														"name"
#define T_IDCARDAPPLY_GENDER													"gender"
#define T_IDCARDAPPLY_NATION													"Nation"
#define T_IDCARDAPPLY_BIRTHDAY													"Birthday"
#define T_IDCARDAPPLY_ADDRESS													"Address"
#define T_IDCARDAPPLY_IDNUMBER													"IdNumber"
#define T_IDCARDAPPLY_SLH														"SLH"
#define T_IDCARDAPPLY_FPDATA													"fpData"
#define T_IDCARDAPPLY_FPFEATURE													"fpFeature"
#define T_IDCARDAPPLY_XCZP														"XCZP"
#define T_IDCARDAPPLY_XZQH														"XZQH"
#define T_IDCARDAPPLY_SANNERID													"sannerId
#define T_IDCARDAPPLY_SCANNERNAME												"scannerName"
#define T_IDCARDAPPLY_LEGAL														"legal"
#define T_IDCARDAPPLY_OPERATORID												"operatorID"
#define T_IDCARDAPPLY_OPERATORNAME												"operatorName"
#define T_IDCARDAPPLY_OPDATE													"opDate"

/** 服务器数据库 */
#define T_ONLINESTATUS															"OnlineStatus"
#define T_ONLINESTATUS_MACHINEID												"machineId"
#define T_ONLINESTATUS_MACHINENAME												"machineName"
#define T_ONLINESTATUS_MACHINEIP												"machineIP"
#define T_ONLINESTATUS_MACHINELONGI												"machineLongi"
#define T_ONLINESTATUS_MACHINELAT												"machineLat"
#define T_ONLINESTATUS_CURRENTBUSINESS											"currentBusiness"
#define T_ONLINESTATUS_BUSINESSSTARTTIME										"businessStartTime"
#define T_ONLINESTATUS_BUSINESSENDTIME											"businessEndTime"
#define T_ONLINESTATUS_BUSINESSDONE												"businessDone"

/** 数量汇总（该表只有一条记录，需要实时更新） */
#define T_SHULIANGHUIZONG														"Shulianghuizong"
#define T_SHULIANGHUIZONG_XUHAO													"Xuhao"
#define T_SHULIANGHUIZONG_SHIYONGDANWEI											"Shiyongdanwei"
#define T_SHULIANGHUIZONG_SHEBEIZONGSHULIANG									"Shebeizongshuliang"
#define T_SHULIANGHUIZONG_QIYONGSHEBEI											"Qiyongshebei"
#define T_SHULIANGHUIZONG_YUYUEYEWU												"Yuyueyewu"
#define T_SHULIANGHUIZONG_YUSHOULIYEWU											"Yushouliyewu"
#define T_SHULIANGHUIZONG_JIAOFEIYEWU											"Jiaofeiyewu"
#define T_SHULIANGHUIZONG_CHAXUNYEWU											"Xuhao"
#define T_SHULIANGHUIZONG_SHEBEISHOUZHENG										"Shebeishouzheng"
#define T_SHULIANGHUIZONG_XUQIANYEWU											"Xuqianyewu"
#define T_SHULIANGHUIZONG_BENSHITONGXINGZHENG									"Benshitongxingzheng"
#define T_SHULIANGHUIZONG_DIANZITONGXINGZHENG									"Dianzitongxingzheng"
#define T_SHULIANGHUIZONG_TONGXINGZHENGZHIKA									"Tongxingzhengzhika"
#define T_SHULIANGHUIZONG_LIDENGKEQU											"Lidengkequ"
#define T_SHULIANGHUIZONG_FEILIDENGKEQU											"Feilidengkequ"

/**详细统计（精确到分钟） */
#define T_XIANGXITONGJI															"Xiangxitongji"
#define T_XIANGXITONGJI_XUHAO													"Xuhao"
#define T_XIANGXITONGJI_NIAN													"Nian"
#define T_XIANGXITONGJI_YUE														"Yue"
#define T_XIANGXITONGJI_RI														"Ri"
#define T_XIANGXITONGJI_XIAOSHI													"Xiaoshi"
#define T_XIANGXITONGJI_FENZHONG												"Fenzhong"
#define T_XIANGXITONGJI_SHIYONGDANWEI											"Shiyongdanwei"
#define T_XIANGXITONGJI_QIYONGSHEBEI											"Qiyongshebei"
#define T_XIANGXITONGJI_YUYUEYEWU												"Yuyueyewu"
#define T_XIANGXITONGJI_YUSHOULIYEWU											"Yushouliyewu"
#define T_XIANGXITONGJI_JIAOFEIYEWU												"Jiaofeiyewu"
#define T_XIANGXITONGJI_CHAXUNYEWU												"Chaxunyewu"
#define T_XIANGXITONGJI_SHEBEISHOUZHENG											"Shebeishouzheng"
#define T_XIANGXITONGJI_XUQIANYEWU												"Xuqianyewu"
#define T_XIANGXITONGJI_BENSHITONGXINGZHENG										"Benshitongxingzheng"
#define T_XIANGXITONGJI_DIANZITONGXINGZHENG										"Dianzitongxingzheng"
#define T_XIANGXITONGJI_TONGXINGZHENGZHIKA										"Tongxingzhengzhika"
#define T_XIANGXITONGJI_LIDENGKEQU												"Lidengkequ"
#define T_XIANGXITONGJI_FEILIDENGKEQU											"Feilidengkequ"

/**制签详细数据 */
#define T_ZHIQIANSHUJU															"Zhiqianshuju"
#define T_ZHIQIANSHUJU_XUHAO													"Xuhao"
#define T_ZHIQIANSHUJU_RIQI														"Riqi"
#define T_ZHIQIANSHUJU_SHEBEIIP													"ShebeiIP"
#define T_ZHIQIANSHUJU_YEWUBIANHAO												"Yewubianhao"
#define T_ZHIQIANSHUJU_YUANZHENGJIANHAOMA										"YuanZhengjianhaoma"
#define T_ZHIQIANSHUJU_XINGMING													"Xingming"
#define T_ZHIQIANSHUJU_QIANZHUZHONGLEI											"Qianzhuzhonglei"
#define T_ZHIQIANSHUJU_ZHIKAZHUANGTAI											"ZhikaZhuangtai"
#define T_ZHIQIANSHUJU_ZHENGJIANHAOMA											"Zhengjianhaoma"
#define T_ZHIQIANSHUJU_JIEKOUFANHUIJIEGUO										"Jiekoufanhuijieguo"
#define T_ZHIQIANSHUJU_LIANXIDIANHUA											"Lianxidianhua"

/**收证详细数据 */
#define T_SHOUZHENGSHUJU														"Shouzhengshuju"
#define T_SHOUZHENGSHUJU_XUHAO													"Xuhao"
#define T_SHOUZHENGSHUJU_RIQI													"Riqi"
#define T_SHOUZHENGSHUJU_SHEBEIIP												"ShebeiIP"
#define T_SHOUZHENGSHUJU_ZHENGJIANLEIXING										"Zhengjianleixing"
#define T_SHOUZHENGSHUJU_ZHENGJIANHAOMA											"Zhengjianhaoma"
#define T_SHOUZHENGSHUJU_XINGMING												"Xingming"
#define T_SHOUZHENGSHUJU_SHOULIBIANHAO											"Shoulibianhao"
#define T_SHOUZHENGSHUJU_SHIFOUJIAOFEI											"Shifoujiaofei"

/**签注详细数据 */
#define T_QIANZHUSHUJU															"Qianzhushuju"
#define T_QIANZHUSHUJU_XUHAO													"Xuhao"
#define T_QIANZHUSHUJU_RIQI														"Riqi"
#define T_QIANZHUSHUJU_SHEBEIIP													"ShebeiIP"
#define T_QIANZHUSHUJU_YUANZHENGJIANHAOMA										"YuanZhengjianhaoma"
#define T_QIANZHUSHUJU_XINGMING													"Xingming"
#define T_QIANZHUSHUJU_XINGBIE													"Xingbie"
#define T_QIANZHUSHUJU_CHUSHENGRIQI												"Chushengriqi"
#define T_QIANZHUSHUJU_LIANXIDIANHUA											"Lianxidianhua"
#define T_QIANZHUSHUJU_YEWULEIXING												"Yewuleixing"
#define T_QIANZHUSHUJU_SHOULIREN												"Shouliren"

/**缴款详细数据 */
#define T_JIAOKUANSHUJU															"Jiaokuanshuju"
#define T_JIAOKUANSHUJU_XUHAO													"Xuhao"
#define T_JIAOKUANSHUJU_RIQI													"Riqi"
#define T_JIAOKUANSHUJU_SHEBEIIP												"ShebeiIP"
#define T_JIAOKUANSHUJU_ZHISHOUDANWEIDAIMA										"Zhishoudanweidaima"
#define T_JIAOKUANSHUJU_JIAOKUANTONGZHISHUHAOMA									"Jiaokuantongzhishuhaoma"
#define T_JIAOKUANSHUJU_JIAOKUANRENXINGMING										"Jiaokuanrenxingming"
#define T_JIAOKUANSHUJU_YINGKOUKUANHEJI											"Yingkoukuanheji"
#define T_JIAOKUANSHUJU_JIAOYIRIQI												"Jiaoyiriqi"

/**查询详细数据 */
#define T_CHAXUNSHUJU															"Chaxunshuju"
#define T_CHAXUNSHUJU_XUHAO														"Xuhao"
#define T_CHAXUNSHUJU_RIQI														"Riqi"
#define T_CHAXUNSHUJU_SHEBEIIP													"ShebeiIP"
#define T_CHAXUNSHUJU_CHAXUNHAOMA												"Chaxunhaoma"
#define T_CHAXUNSHUJU_CHAXUNLEIXING												"Chaxunleixing"
#define T_CHAXUNSHUJU_SHIFOUCHAXUNCHENGGONG										"Shifouchaxunchenggong"

/**预受理详细数据 */
#define T_YUSHOULISHUJU															"Yushoulishuju"
#define T_YUSHOULISHUJU_XUHAO													"Xuhao"
#define T_YUSHOULISHUJU_RIQI													"Riqi"
#define T_YUSHOULISHUJU_SHEBEIIP												"ShebeiIP"
#define T_YUSHOULISHUJU_YEWUBIANHAO												"Yewubianhao"
#define T_YUSHOULISHUJU_XINGMING												"Xingming"
#define T_YUSHOULISHUJU_LIANXIDIANHUA											"Lianxidianhua"
#define T_YUSHOULISHUJU_CHUGUOSHIYOU											"Chuguoshiyou"
#define T_YUSHOULISHUJU_YUANZHENGJIANHAOMA										"YuanZhengjianhaoma"
#define T_YUSHOULISHUJU_QIANZHUZHONGLEI											"Qianzhuzhonglei"
#define T_YUSHOULISHUJU_XINGBIE													"Xingbie"
#define T_YUSHOULISHUJU_HUKOUSUOZAIDI											"Hukousuozaidi"
#define T_YUSHOULISHUJU_MINZU													"Minzu"

/**自助设备异常详细数据 */
#define T_SHEBEIYICHANGSHUJU													"Shebeiyichangshuju"
#define T_SHEBEIYICHANGSHUJU_XUHAO												"Xuhao"
#define T_SHEBEIYICHANGSHUJU_RIQI												"Riqi"
#define T_SHEBEIYICHANGSHUJU_SHIYONGDANWEI										"Shiyongdanwei"
#define T_SHEBEIYICHANGSHUJU_YICHANGSHEJIMOKUAI									"Yichangshejimokuai"
#define T_SHEBEIYICHANGSHUJU_YICHANGYUANYIN										"Yichangyuanyin"
#define T_SHEBEIYICHANGSHUJU_YICHANGXIANGXINEIRONG								"Yichangxiangxineirong"

/**管理员 */
#define T_GUANLIYUAN															"Guanliyuan"
#define T_GUANLIYUAN_XUHAO														"Xuhao"
#define T_GUANLIYUAN_YONGHUMING													"Yonghuming"
#define T_GUANLIYUAN_MIMA														"Mima"
#define T_GUANLIYUAN_YOUXIAOQI													"Youxiaoqi"
#define T_GUANLIYUAN_QUANXIANJIBIE												"Quanxianjibie"

/**管理员操作记录 */
#define T_GUANLIYUANCAOZUOJILU													"Guanliyuancaozuojilu"
#define T_GUANLIYUANCAOZUOJILU_YONGHUMING										"Yonghuming"
#define T_GUANLIYUANCAOZUOJILU_RIQI												"Riqi"
#define T_GUANLIYUANCAOZUOJILU_CAOZUOLEIBIE										"Caozuoleibie"
#define T_GUANLIYUANCAOZUOJILU_CAOZUONEIRONG									"Caozuoneirong"

/**设备管理 */
#define T_SHEBEIGUANLI															"Shebeiguanli"
#define T_SHEBEIGUANLI_XUHAO													"Xuhao"
#define T_SHEBEIGUANLI_SHENG													"Sheng"
#define T_SHEBEIGUANLI_SHI														"Shi"
#define T_SHEBEIGUANLI_QU														"Qu"
#define T_SHEBEIGUANLI_SHIYONGDANWEI											"Shiyongdanwei"
#define T_SHEBEIGUANLI_IP														"IP"
#define T_SHEBEIGUANLI_SHEBEILEIXING											"Shebeileixing"
#define T_SHEBEIGUANLI_JINGDU													"Jingdu"
#define T_SHEBEIGUANLI_WEIDU													"Weidu"
#define T_SHEBEIGUANLI_CHUANGJIANSHIJIAN										"Chuangjianshijian"



#define  BOSD_RIM_XML_PARAM_FRAME "<?xml version=\"1.0\"  encoding=\"gb2312\" >\n"\
	"<!-- 设备参数框架 -->"\
	"<config>\n"\
	"<device name=\"\" >\n"\
	"</device>\n"\
	"</config>"
////////////////////////////////////////////////////////结构定义BEGIN////////////////////////////////////////////////////////

/**
* @class  tagIDCARDAPPLY 
*
* @brief 
****************************************************************************
*/
typedef class tagIDCARDAPPLY
{
public:
	tagIDCARDAPPLY::tagIDCARDAPPLY()
	{
		name				= "";
		gender				= "";
		Nation				= 0;
		Birthday			= "";
		Address				= 0;
		IdNumber			= 0;
		SigDepart			= 0;
		SLH					= 0;
		fpData				= "";
		fpFeature			= "";
		XCZP				= "";
		XZQH				= 0;
		sannerId 			= "";
		scannerName			= 0;
		legal				= 0;
		operatorID			= "";
		operatorName		= "";
		opDate				= "";
	}

	std::string  			name;
	std::string  			gender;
	std::string  			Nation;
	std::string  			Birthday;
	std::string  			Address;
	std::string  			IdNumber;
	std::string  			SigDepart;
	std::string  			SLH;
	std::string  			fpData;
	std::string  			fpFeature;
	std::string  			XCZP;
	std::string  			XZQH;
	std::string  			sannerId;
	std::string  			scannerName;
	bool		  			legal;
	std::string  			operatorID;
	std::string  			operatorName;
	std::string  			opDate;

}IDCARDAPPLY, *LPIDCARDAPPLY;
/**
* @class  RTKDEVICE
*
* @brief 
****************************************************************************
*/
typedef class tagRTMDEVICE
{
public:
	tagRTMDEVICE()
	{
		sStationNO			= "";	         
		sDeviceNO			= "";	         
		sDeviceModel		= "";	       
		sName 				= "";	             
		sDesc 				= "";	             
		nDeviceType			= 0;	       
		nBuyTime			= 0;	           
		sSupplier			= "";	         
		sRepairTel			= "";	         
		sDeviceCurAddress	= "";	 
		nStatus				= 0;	           
		sResponer			= "";	         
		nMaxRunNUM			= 0;	           
		sDriverIP			= "";	         
		nDriverPort			= 0;	       
		nDeviceProtocol		= 0;	
		bIsintegrated		= 0;
	}
	

	std::string 			sStationNO;	         
	std::string 			sDeviceNO;	         
	std::string 			sDeviceModel;	       
	std::string 			sName;	             
	std::string 			sDesc;	             
	long					nDeviceType;	               
	LONG64					nBuyTime;	               
	std::string 			sSupplier;	         
	std::string 			sRepairTel;	         
	std::string 			sDeviceCurAddress;	 
	long					nStatus;	                   
	std::string				sResponer;	         
	long					nMaxRunNUM;	               
	std::string				sDriverIP;	         
	short					nDriverPort;	             
	long 					nDeviceProtocol;	
	bool 					bIsintegrated ;
}RTMDEVICE, *LPRTMDEVICE;

/**
* @class  tagSTATIONDEVICEFUNC 
*
* @brief 
****************************************************************************
*/
typedef class tagRTMDEVICEFUNC
{
public:
	tagRTMDEVICEFUNC()
	{
		sStationNO			=  "";	         
		sDeviceNO			=  "";	         
		nFunNO				=  0;	       
	}
	tagRTMDEVICEFUNC(const tagRTMDEVICEFUNC& ob)
	{
		*this = ob;
	}
	tagRTMDEVICEFUNC& operator=(const tagRTMDEVICEFUNC& ob)
	{
		sStationNO			= ob.sStationNO;	            
		sDeviceNO			= ob.sDeviceNO;	         	       
		nFunNO				= ob.nFunNO;		            

		return *this;
	}

	std::string 			sStationNO;	         
	std::string 			sDeviceNO;	         
	long					nFunNO;		
}RTMDEVICEFUNC, *LPRTMDEVICEFUNC;

/**
* @class  tagRTMREFDEVICEFUNC 
*
* @brief 
****************************************************************************
*/
typedef class tagRTMREFDEVICEFUNC
{
public:
	tagRTMREFDEVICEFUNC()
	{
		nFuncID				=  0;	         
		sFuncName			=  "";	         
		sFuncKey			=  "";	       
	}
	tagRTMREFDEVICEFUNC(const tagRTMREFDEVICEFUNC& ob)
	{
		*this = ob;
	}
	tagRTMREFDEVICEFUNC& operator=(const tagRTMREFDEVICEFUNC& ob)
	{
		nFuncID				= ob.nFuncID;	        
		sFuncName			= ob.sFuncName;	 	       
		sFuncKey			= ob.sFuncKey;	        

		return *this;
	}

	long        			nFuncID;	
	std::string 			sFuncName;	
	std::string 			sFuncKey;	
}RTMREFDEVICEFUNC, *LPRTMREFDEVICEFUNC;

/**
* @class  tagCOMREGIONNO 
*
* @brief 
****************************************************************************
*/
typedef class tagCOMREGIONNO
{
public:
	tagCOMREGIONNO()
	{
		sRegionNo			=  "";	         
		sRegionName			=  "";	       
	}
	tagCOMREGIONNO(const tagCOMREGIONNO& ob)
	{
		*this = ob;
	}
	tagCOMREGIONNO& operator=(const tagCOMREGIONNO& ob)
	{
		sRegionNo			= ob.sRegionNo;	 	       
		sRegionName			= ob.sRegionName;	        

		return *this;
	}

	std::string 			sRegionNo;	
	std::string 			sRegionName;	
}COMREGIONNO, *LPCOMREGIONNO;

/**
* @class  tagRTMREFDEVICEPROTOCOL 
*
* @brief 
****************************************************************************
*/
typedef class tagRTMREFDEVICEPROTOCOL
{
public:
	tagRTMREFDEVICEPROTOCOL()
	{
		nNoID				=  0;	         
		sName				=  "";	         
		sNote				=  "";	       
	}
	tagRTMREFDEVICEPROTOCOL(const tagRTMREFDEVICEPROTOCOL& ob)
	{
		*this = ob;
	}
	tagRTMREFDEVICEPROTOCOL& operator=(const tagRTMREFDEVICEPROTOCOL& ob)
	{
		nNoID				= ob.nNoID;	        
		sName				= ob.sName;	 	       
		sNote				= ob.sNote;	        

		return *this;
	}

	long        			nNoID;	
	std::string 			sName;	
	std::string 			sNote;	
}RTMREFDEVICEPROTOCOL, *LPRTMREFDEVICEPROTOCOL;

/**
* @class  tagRTMREFSTATIONTYPE 
*
* @brief 
****************************************************************************
*/
typedef class tagRTMREFSTATIONTYPE
{
public:
	tagRTMREFSTATIONTYPE()
	{
		nTypeNo				=  0;	         
		sTypeName			=  "";	       
	}
	tagRTMREFSTATIONTYPE(const tagRTMREFSTATIONTYPE& ob)
	{
		*this = ob;
	}
	tagRTMREFSTATIONTYPE& operator=(const tagRTMREFSTATIONTYPE& ob)
	{
		nTypeNo				= ob.nTypeNo;	 	       
		sTypeName			= ob.sTypeName;	        

		return *this;
	}

	long					nTypeNo;	
	std::string 			sTypeName;	
}RTMREFSTATIONTYPE, *LPRTMREFSTATIONTYPE;

/**
* @class  tagRTMREFDEVICETYPE 
*
* @brief 
****************************************************************************
*/
typedef class tagRTMREFDEVICETYPE
{
public:
	tagRTMREFDEVICETYPE()
	{
		nTypeNo				=  0;	         
		sTypeName			=  "";	       
	}
	tagRTMREFDEVICETYPE(const tagRTMREFDEVICETYPE& ob)
	{
		*this = ob;
	}
	tagRTMREFDEVICETYPE& operator=(const tagRTMREFDEVICETYPE& ob)
	{
		nTypeNo				= ob.nTypeNo;	 	       
		sTypeName			= ob.sTypeName;	        

		return *this;
	}

	long					nTypeNo;	
	std::string 			sTypeName;	
}RTMREFDEVICETYPE, *LPRTMREFDEVICETYPE;

/**
* @class  tagRTMMONORG 
*
* @brief 
****************************************************************************
*/
typedef class tagRTMMONORG
{
public:
	tagRTMMONORG()
	{
		sOrgNO	 			=  "";	       
		sName	 			=  "";	       
		sAddress	 		=  "";	       
		sPost				=  "";	       
		sResponpersion		=  "";	       
		sContact	 		=  "";	       
		sBrief 				=  "";	       
		sNote	 			=  "";	       
	}
	tagRTMMONORG(const tagRTMMONORG& ob)
	{
		*this = ob;
	}
	tagRTMMONORG& operator=(const tagRTMMONORG& ob)
	{
		sOrgNO	 			= ob.sOrgNO;	   
		sName	 			= ob.sName;	 
		sAddress	 		= ob.sAddress;	   
		sPost				= ob.sPost; 
		sResponpersion		= ob.sResponpersion;	  
		sContact	 		= ob.sContact;	 
		sBrief 				= ob.sBrief;	   
		sNote	 			= ob.sNote;	 

		return *this;
	}
	std::string 			sOrgNO;	 
	std::string 			sName;	 
	std::string 			sAddress;	 
	std::string 			sPost; 
	std::string 			sResponpersion;	 
	std::string 			sContact;	 
	std::string 			sBrief;	 
	std::string 			sNote;	 
}RTMMONORG, *LPRTMMONORG;

/**
* @class  tagRTMMONCTRLCENTER 
*
* @brief 
****************************************************************************
*/
typedef class tagRTMMONCTRLCENTER
{
public:
	tagRTMMONCTRLCENTER()
	{
		sCenterNO			=  "";	       
		sName	 			=  "";	       
		sAddress			=  "";	       
		fLong 				=  0;	       
		fLati	 			=  0;	       
		sNote	 			=  "";	       
	}
	tagRTMMONCTRLCENTER(const tagRTMMONCTRLCENTER& ob)
	{
		*this = ob;
	}
	tagRTMMONCTRLCENTER& operator=(const tagRTMMONCTRLCENTER& ob)
	{
		sCenterNO 			= ob.sCenterNO; 
		sName	 			= ob.sName;	 
		sAddress	 		= ob.sAddress;	 
		fLong 				= ob.fLong; 
		fLati	 			= ob.fLati;	  
		sNote	 			= ob.sNote;	 

		return *this;
	}
	std::string 			sCenterNO; 
	std::string 			sName;	 
	std::string 			sAddress;	 
	double 					fLong; 
	double 					fLati;	 
	std::string 			sNote;	 
}RTMMONCTRLCENTER, *LPRTMMONCTRLCENTER;

/**
* @class  tagRTMSTATIONDEVICEFUNCANT
*
* @brief  
****************************************************************************
*/
typedef class tagRTMSTATIONDEVICEFUNCANT
{
public:
	tagRTMSTATIONDEVICEFUNCANT()
	{
		sStationNO 			=  "";	       
		sDeviceNO  			=  "";	       
		nFunNO   			=  0;	       
		sAnt 				=  "";	       
		sDes 				=  "";	       
	}
	tagRTMSTATIONDEVICEFUNCANT(const tagRTMSTATIONDEVICEFUNCANT& ob)
	{
		*this = ob;
	}
	tagRTMSTATIONDEVICEFUNCANT& operator=(const tagRTMSTATIONDEVICEFUNCANT& ob)
	{
		sStationNO 			= ob.sStationNO;	      
		sDeviceNO  			= ob.sDeviceNO;	      
		nFunNO   			= ob.nFunNO;	  
		sAnt 				= ob.sAnt ;
		sDes 				= ob.sDes ;

		return *this;
	}
	std::string 			sStationNO;	         
	std::string 			sDeviceNO;	         
	long        			nFunNO;	  
	std::string 			sAnt ;
	std::string 			sDes ;
}RTMSTATIONDEVICEFUNCANT, *LPRTMSTATIONDEVICEFUNCANT;

/**
* @class  tagRTMANT
*
* @brief  
****************************************************************************
*/
typedef class tagRTMANT
{
public:
	tagRTMANT()
	{
		sStationNO			=  "";	       
		sAntName			=  "";	       
		sAntFactor			=  "";	       
		nBeginFreq			=  0;	       
		nEndFreq			=  0;	       
		nAntHeight			=  0;	       
	}
	tagRTMANT(const tagRTMANT& ob)
	{
		*this = ob;
	}
	tagRTMANT& operator=(const tagRTMANT& ob)
	{
		sStationNO			= ob.sStationNO;	    
		sAntName			= ob.sAntName;	
		sAntFactor			= ob.sAntFactor;	
		nBeginFreq			= ob.nBeginFreq; 
		nEndFreq			= ob.nEndFreq;	
		nAntHeight			= ob.nAntHeight;	

		return *this;
	}
	std::string 			sStationNO;	 
	std::string 			sAntName;	 
	std::string 			sAntFactor;	 
	LONG64      			nBeginFreq; 
	LONG64      			nEndFreq;	 
	long        			nAntHeight;	  
}RTMANT, *LPRTMANT;

/**
* @class  tagRTMDEVICEMODELFUNC
*
* @brief  
****************************************************************************
*/
typedef class tagRTMREFDEVICEMODEL
{
public:
	tagRTMREFDEVICEMODEL()
	{
		sNoId				=  "";	       
		sName				=  "";	       
		sNote				=  "";	        
	}
	tagRTMREFDEVICEMODEL(const tagRTMREFDEVICEMODEL& ob)
	{
		*this = ob;
	}
	tagRTMREFDEVICEMODEL& operator=(const tagRTMREFDEVICEMODEL& ob)
	{
		sNoId				= ob.sNoId;	    
		sName				= ob.sName;	
		sNote				= ob.sNote;	

		return *this;
	}

	std::string				sNoId;	
	std::string 			sName;	
	std::string 			sNote;	
}RTMREFDEVICEMODEL, *LPRTMREFDEVICEMODEL;

/**
* @class  tagRTMREFDEVICEMODELPARAM
*
* @brief  
****************************************************************************
*/
typedef class tagRTMREFDEVICEMODELFUNCPARAM
{
public:
	tagRTMREFDEVICEMODELFUNCPARAM()
	{
		sModel				=  "";	       
		nFuncID				=  0;	       
		sParam				=  "";	        
	}
	tagRTMREFDEVICEMODELFUNCPARAM(const tagRTMREFDEVICEMODELFUNCPARAM& ob)
	{
		*this = ob;
	}
	tagRTMREFDEVICEMODELFUNCPARAM& operator=(const tagRTMREFDEVICEMODELFUNCPARAM& ob)
	{
		sModel				= ob.sModel;	
		nFuncID				= ob.nFuncID;	    
		sParam				= ob.sParam;	

		return *this;
	}

	std::string 			sModel;	
	long					nFuncID;	
	std::string 			sParam;	
}RTMREFDEVICEMODELFUNCPARAM, *LPRTMREFDEVICEMODELFUNCPARAM;

/**
* @class  tagRIM30RTMRNC
*
* @brief  
****************************************************************************
*/
typedef class tagRIM30RTMRNC
{
public:
	tagRIM30RTMRNC()
	{
		sSTATNo             =  "";             
		sRncName            =  "";             
		sRncAddr            =  "";             
		nRncPort			=  0;               
		sDevName            =  "";             
		sCtrlPort           =  0;               
		bHasOS              =  0;               
		sOSIP				=  "";             
		nOSPort             =  0;               
		nType				=  0;               
	}
	tagRIM30RTMRNC(const tagRIM30RTMRNC& ob)
	{
		*this = ob;
	}
	tagRIM30RTMRNC& operator=(const tagRIM30RTMRNC& ob)
	{
		sSTATNo             = ob.sSTATNo;     
		sRncName            = ob.sRncName;      
		sRncAddr            = ob.sRncAddr;         
		nRncPort            = ob.nRncPort; 
		sDevName            = ob.sDevName;      
		sCtrlPort           = ob.sCtrlPort;          
		bHasOS              = ob.bHasOS;   
		sOSIP               = ob.sOSIP;       
		nOSPort             = ob.nOSPort;  
		nType				= ob.nType;  

		return *this;
	}
	std::string          	sSTATNo; 
	std::string          	sRncName;      
	std::string          	sRncAddr;         
	short                   nRncPort; 
	std::string             sDevName;      
	short                   sCtrlPort;          
	bool                    bHasOS;   
	std::string             sOSIP;       
	short                   nOSPort;    
	short                   nType;    
}RIM30RTMRNC, *LPRIM30RTMRNC;

/**
* @class  tagRIM30COMAUTHSYSDATASTATION
*
* @brief  
****************************************************************************
*/
typedef class tagRIM30COMAUTHSYSDATASTATION
{
public:
	tagRIM30COMAUTHSYSDATASTATION()
	{
		sSTATNo             =  "";             
		sNote				=  "";                        
	}
	tagRIM30COMAUTHSYSDATASTATION(const tagRIM30COMAUTHSYSDATASTATION& ob)
	{
		*this = ob;
	}
	tagRIM30COMAUTHSYSDATASTATION& operator=(const tagRIM30COMAUTHSYSDATASTATION& ob)
	{
		sSTATNo             = ob.sSTATNo;     
		sNote				= ob.sNote;      

		return *this;
	}
	std::string          	sSTATNo; 
	std::string          	sNote;         
}RIM30COMAUTHSYSDATASTATION, *LPRIM30COMAUTHSYSDATASTATION;

/**
* @class  tagRIM30COMAUTHSYSFUNC
*
* @brief  
****************************************************************************
*/
typedef class tagRIM30COMAUTHSYSFUNC
{
public:
	tagRIM30COMAUTHSYSFUNC()
	{
		sSysFuncNo          =  "";             
		sNote				=  "";                        
	}
	tagRIM30COMAUTHSYSFUNC(const tagRIM30COMAUTHSYSFUNC& ob)
	{
		*this = ob;
	}
	tagRIM30COMAUTHSYSFUNC& operator=(const tagRIM30COMAUTHSYSFUNC& ob)
	{
		sSysFuncNo           = ob.sSysFuncNo;     
		sNote				= ob.sNote;      

		return *this;
	}
	std::string          	sSysFuncNo; 
	std::string          	sNote;         
}RIM30COMAUTHSYSFUNC, *LPRIM30COMAUTHSYSFUNC;

/**
* @class  tagRIM30USERINFO
*
* @brief  
****************************************************************************
*/
typedef class tagRIM30USERINFO
{
public:
	tagRIM30USERINFO()
	{
		UserID				=  "";	       
		UserName			=  "";	       
		EmpNO				=  "";	       
		AreaCode			=  "";	       
		DeptID				=  "";	       
		DeptName			=  "";	       
	}
	tagRIM30USERINFO(const tagRIM30USERINFO& ob)
	{
		*this = ob;
	}
	tagRIM30USERINFO& operator=(const tagRIM30USERINFO& ob)
	{
		UserID				= ob.UserID;
		UserName			= ob.UserName;
		EmpNO				= ob.EmpNO;	
		AreaCode			= ob.AreaCode;
		DeptID				= ob.DeptID;
		DeptName			= ob.DeptName;

		return *this;
	}

	std::string 			UserID;
	std::string 			UserName;	
	std::string 			EmpNO;	
	std::string 			AreaCode;	
	std::string 			DeptID;
	std::string 			DeptName;	

}RIM30USERINFO, *LPRIM30USERINFO;


/**
* @class  tagRIM30BRANCHINFO
*
* @brief  
****************************************************************************
*/
typedef class tagRIM30BRANCHINFO
{
public:
	tagRIM30BRANCHINFO()
	{
		Deptname			=  "";	       
		Parentid			=  "";	       
		Tel					=  "";	       
		Fax					=  "";	       
		Email				=  "";	       
		Manager				=  "";	       
		Note				=  "";	       
		Deptlevel			=  "";	       
		Deptid				=  "";	       
		Delflag				=  "";	       
	}
	tagRIM30BRANCHINFO(const tagRIM30BRANCHINFO& ob)
	{
		*this = ob;
	}
	tagRIM30BRANCHINFO& operator=(const tagRIM30BRANCHINFO& ob)
	{
		Deptname			= ob.Deptname;
		Parentid			= ob.Parentid;
		Tel					= ob.Tel;	
		Fax					= ob.Fax;	
		Email				= ob.Email;	
		Manager				= ob.Manager;
		Note				= ob.Note;	
		Deptlevel			= ob.Deptlevel;
		Deptid				= ob.Deptid;	
		Delflag				= ob.Delflag;

		return *this;
	}

	std::string 			Deptname;
	std::string 			Parentid;
	std::string 			Tel;	
	std::string 			Fax;	
	std::string 			Email;	
	std::string 			Manager;
	std::string 			Note;	
	std::string 			Deptlevel;
	std::string 			Deptid;	
	std::string 			Delflag;

}RIM30BRANCHINFO, *LPRIM30BRANCHINFO;

/**
* @class  tagRIMCOMFREQLAYOUT
*
* @brief  
****************************************************************************
*/
typedef class tagRIMCOMFREQLAYOUT
{
public:
	tagRIMCOMFREQLAYOUT()
	{
		sName				=  "";	       
		nStartFreq			=  0;	       
		nEndFreq			=  0;	       
		sGroupName			=  "";	       
		nDistince			=  0;	       
		nEmitWidth			=  0;	              
	}
	tagRIMCOMFREQLAYOUT(const tagRIMCOMFREQLAYOUT& ob)
	{
		*this = ob;
	}
	tagRIMCOMFREQLAYOUT& operator=(const tagRIMCOMFREQLAYOUT& ob)
	{
		sName				= ob.sName;
		nStartFreq			= ob.nStartFreq;
		nEndFreq			= ob.nEndFreq;	
		sGroupName			= ob.sGroupName;	
		nDistince			= ob.nDistince;	
		nEmitWidth			= ob.nEmitWidth;	

		return *this;
	}

	std::string 			sName;
	int 					nStartFreq;
	int 					nEndFreq;	
	std::string 			sGroupName;	
	int 					nDistince;	
	int 					nEmitWidth;	

}RIMCOMFREQLAYOUT, *LPRIMCOMFREQLAYOUT;

////////////////////////////////////////////////////////结构定义END////////////////////////////////////////////////////////


#define BOSD_T_RIM_RTM_STATION_TYPE_INIT_DATA(table,id,name)  "DELETE FROM " ##table ";"\
	"INSERT INTO "##table "("##id","##name ") VALUES('1','固定站');"\
	"INSERT INTO "##table "("##id","##name ") VALUES('2','可搬移站');"\
	"INSERT INTO "##table "("##id","##name ") VALUES('3','移动站');"\
	"INSERT INTO "##table "("##id","##name ") VALUES('4','临时站');"\
	"INSERT INTO "##table "("##id","##name ") VALUES('5','小型站');"

#define BOSD_T_RIM_RTM_FUNC_TYPE_INIT_DATA(table,id,name,key)  "DELETE FROM " ##table ";"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(10,'单频测量','FIXFQ');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(11,'中频分析','IF_FQ');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(12,'单频测向','FIXDF');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(13,'中频测向','IF_DF');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(14,'离散扫描','MSCAN');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(15,'频段扫描','FSCAN');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(16,'数字扫描','DSCAN');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(17,'频谱扫描','PSCAN');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(18,'频谱分析','SPECTRUM');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(19,'时域分析','TIMEDOM');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(20,'搜索测向','MULTIDF');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(21,'频率测向','SCANDF');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(22,'离散信号搜索','MSCANE');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(23,'信号搜索','FSCANE');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(24,'ITU测量','ITU');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(25,'宽带监测测向','WB_DF');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(26,'中频宽带测向','IFDFEXT');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(27,'跳频监测','LPI');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(28,'宽带监测','WB_FQ');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(29,'数字解调','DIGDEM');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(30,'宽带扫描','WMON');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(31,'能量探测','EDETN');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(32,'离散测向','MDF');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(33,'信息测量','SIGNALMEAS');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(34,'信号识别','MODREC');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(35,'信号告警','SINA');"

#define BOSD_T_RIM_REGION_NO_INIT_DATA(table,no,name) "DELETE FROM " ##table ";"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('000000','国家中心' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('110000','北京市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('120000','天津市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('130000','河北省' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('130100','石家庄市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('130200','唐山市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('130300','秦皇岛市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('130400','邯郸市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('130500','邢台市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('130600','保定市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('130700','张家口市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('130800','承德市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('130900','沧州市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('131000','廊坊市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('131100','衡水市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('140000','山西省' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('140100','太原市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('140200','大同市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('140300','阳泉市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('140400','长治市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('140500','晋城市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('140600','朔州市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('140700','晋中市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('140800','运城市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('140900','忻州市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('141000','临汾市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('141100','吕梁市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('150000','内蒙古自治区' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('150100','呼和浩特市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('150200','包头市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('150300','乌海市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('150400','赤峰市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('150500','通辽市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('150600','鄂尔多斯市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('150700','呼伦贝尔市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('150800','巴彦淖尔市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('150900','乌兰察布市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('152200','兴安盟' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('152500','锡林郭勒盟' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('152900','阿拉善盟' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('210000','辽宁省' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('210100','沈阳市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('210200','大连市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('210300','鞍山市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('210400','抚顺市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('210500','本溪市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('210600','丹东市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('210700','锦州市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('210800','营口市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('210900','阜新市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('211000','辽阳市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('211100','盘锦市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('211200','铁岭市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('211300','朝阳市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('211400','葫芦岛市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('220000','吉林省' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('220100','长春市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('220200','吉林市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('220300','四平市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('220400','辽源市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('220500','通化市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('220600','白山市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('220700','松原市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('220800','白城市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('222400','延边朝鲜族自治州' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('230000','黑龙江省' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('230100','哈尔滨市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('230200','齐齐哈尔市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('230300','鸡西市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('230400','鹤岗市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('230500','双鸭山市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('230600','大庆市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('230700','伊春市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('230800','佳木斯市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('230900','七台河市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('231000','牡丹江市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('231100','黑河市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('231200','绥化市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('232700','大兴安岭地区(加格达奇)' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('310000','上海市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('320000','江苏省' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('320100','南京市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('320200','无锡市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('320300','徐州市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('320400','常州市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('320500','苏州市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('320600','南通市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('320700','连云港市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('320800','淮安市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('320900','盐城市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('321000','扬州市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('321100','镇江市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('321200','泰州市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('321300','宿迁市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('330000','浙江省' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('330100','杭州市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('330200','宁波市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('330300','温州市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('330400','嘉兴市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('330500','湖州市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('330600','绍兴市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('330700','金华市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('330800','衢州市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('330900','舟山市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('331000','台州市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('331100','丽水市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('340000','安徽省' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('340100','合肥市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('340200','芜湖市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('340300','蚌埠市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('340400','淮南市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('340500','马鞍山市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('340600','淮北市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('340700','铜陵市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('340800','安庆市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('341000','黄山市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('341100','滁州市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('341200','阜阳市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('341300','宿州市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('341400','巢湖市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('341500','六安市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('341600','亳州市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('341700','池州市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('341800','宣城市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('350000','福建省' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('350100','福州市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('350200','厦门市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('350300','莆田市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('350400','三明市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('350500','泉州市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('350600','漳州市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('350700','南平市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('350800','龙岩市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('350900','宁德市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('360000','江西省' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('360100','南昌市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('360200','景德镇市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('360300','萍乡市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('360400','九江市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('360500','新余市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('360600','鹰潭市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('360700','赣州市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('360800','吉安市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('360900','宜春市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('361000','抚州市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('361100','上饶市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('370000','山东省' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('370100','济南市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('370200','青岛市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('370300','淄博市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('370400','枣庄市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('370500','东营市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('370600','烟台市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('370700','潍坊市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('370800','济宁市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('370900','泰安市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('371000','威海市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('371100','日照市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('371200','莱芜市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('371300','临沂市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('371400','德州市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('371500','聊城市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('371600','滨州市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('371700','荷泽市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('410000','河南省' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('410100','郑州市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('410200','开封市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('410300','洛阳市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('410400','平顶山市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('410500','安阳市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('410600','鹤壁市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('410700','新乡市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('410800','焦作市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('410900','濮阳市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('411000','许昌市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('411100','漯河市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('411200','三门峡市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('411300','南阳市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('411400','商丘市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('411500','信阳市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('411600','周口市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('411700','驻马店市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('420000','湖北省' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('420100','武汉市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('420200','黄石市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('420300','十堰市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('420500','宜昌市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('420600','襄樊市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('420700','鄂州市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('420800','荆门市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('420900','孝感市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('421000','荆州市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('421100','黄冈市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('421200','咸宁市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('421300','随州市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('422800','恩施土家族自治州' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('430000','湖南省' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('430100','长沙市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('430200','株洲市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('430300','湘潭市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('430400','衡阳市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('430500','邵阳市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('430600','岳阳市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('430700','常德市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('430800','张家界市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('430900','益阳市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('431000','郴州市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('431100','永州市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('431200','怀化市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('431300','娄底市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('433100','湘西土家族苗族自治州' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('440000','广东省' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('440100','广州市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('440200','韶关市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('440300','深圳市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('440400','珠海市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('440500','汕头市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('440600','佛山市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('440700','江门市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('440800','湛江市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('440900','茂名市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('441200','肇庆市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('441300','惠州市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('441400','梅州市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('441500','汕尾市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('441600','河源市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('441700','阳江市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('441800','清远市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('441900','东莞市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('442000','中山市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('445100','潮州市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('445200','揭阳市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('445300','云浮市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('450000','广西壮族自治区' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('450100','南宁市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('450200','柳州市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('450300','桂林市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('450400','梧州市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('450500','北海市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('450600','防城港市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('450700','钦州市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('450800','贵港市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('450900','玉林市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('451000','百色市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('451100','贺州市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('451200','河池市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('451300','来宾市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('451400','崇左市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('460000','海南省' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('460100','海口市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('460200','三亚市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('500000','重庆市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('502100','万州区' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('502200','涪陵区' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('502300','黔江区' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('510000','四川省' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('510100','成都市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('510300','自贡市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('510400','攀枝花市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('510500','泸州市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('510600','德阳市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('510700','绵阳市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('510800','广元市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('510900','遂宁市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('511000','内江市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('511100','乐山市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('511300','南充市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('511400','眉山市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('511500','宜宾市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('511600','广安市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('511700','达州市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('511800','雅安市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('511900','巴中市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('512000','资阳市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('513200','阿坝藏族羌族自治州' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('513300','甘孜藏族自治州' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('513400','凉山彝族自治州' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('520000','贵州省' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('520100','贵阳市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('520200','六盘水市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('520300','遵义市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('520400','安顺市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('522200','铜仁地区' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('522300','黔西南布依族苗族自治州' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('522400','毕节地区' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('522600','黔东南苗族侗族自治州' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('522700','黔南布依族苗族自治州' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('530000','云南省' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('530100','昆明市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('530300','曲靖市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('530400','玉溪市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('530500','保山市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('530600','昭通市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('530700','丽江市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('530800','普洱市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('530900','临沧市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('532300','楚雄彝族自治州' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('532500','红河哈尼族彝族自治州' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('532600','文山壮族苗族自治州' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('532800','西双版纳傣族自治州' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('532900','大理白族自治州' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('533100','德宏傣族景颇族自治州' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('533300','怒江傈僳族自治州' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('533400','迪庆藏族自治州' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('540000','西藏自治区' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('540100','拉萨市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('542100','昌都地区' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('542200','山南地区' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('542300','日喀则地区' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('542400','那曲地区' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('542500','阿里地区' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('542600','林芝地区' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('610000','陕西省' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('610100','西安市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('610200','铜川市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('610300','宝鸡市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('610400','咸阳市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('610500','渭南市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('610600','延安市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('610700','汉中市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('610800','榆林市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('610900','安康市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('611000','商洛市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('620000','甘肃省' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('620100','兰州市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('620200','嘉峪关市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('620300','金昌市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('620400','白银市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('620500','天水市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('620600','武威市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('620700','张掖市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('620800','平凉市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('620900','酒泉市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('621000','庆阳市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('621100','定西市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('621200','陇南市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('622900','临夏回族自治州' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('623000','甘南藏族自治州' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('630000','青海省' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('630100','西宁市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('632100','海东地区' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('632200','海北藏族自治州' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('632300','黄南藏族自治州' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('632500','海南藏族自治州' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('632600','果洛藏族自治州' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('632700','玉树藏族自治州' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('632800','海西蒙古族藏族自治州' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('640000','宁夏回族自治区' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('640100','银川市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('640200','石嘴山市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('640300','吴忠市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('640400','固原市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('640500','中卫市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('650000','新疆维吾尔自治区' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('650100','乌鲁木齐市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('650200','克拉玛依市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('650800','石河子市' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('652100','吐鲁番地区' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('652200','哈密地区' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('652300','昌吉回族自治州' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('652700','博尔塔拉蒙古自治州' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('652800','巴音郭楞蒙古自治州' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('652900','阿克苏地区');"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('653000','克孜勒苏柯尔克孜自治州');"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('653100','喀什地区');"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('653200','和田地区');"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('654000','伊犁哈萨克自治州');"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('654200','塔城地区');"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('654300','阿勒泰地区');"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('654400','奎屯市');"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('710000','台湾省');"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('810000','香港特别行政区');"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('820000','澳门特别行政区');"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('632900','格尔木');"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('633000','油田');"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('411800','济源市');"
