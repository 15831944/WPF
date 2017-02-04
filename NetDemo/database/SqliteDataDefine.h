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
#pragma region macrodefinition

/** 自助设备本地数据库（业务审核） */
#define T_IDCARDAPPLY															"idCardApply"
#define T_IDCARDAPPLY_NAME														"name"
#define T_IDCARDAPPLY_GENDER													"gender"
#define T_IDCARDAPPLY_NATION													"Nation"
#define T_IDCARDAPPLY_BIRTHDAY													"Birthday"
#define T_IDCARDAPPLY_ADDRESS													"Address"
#define T_IDCARDAPPLY_IDNUMBER													"IdNumber"
#define T_IDCARDAPPLY_SIGDEPART													"SigDepart"
#define T_IDCARDAPPLY_SLH														"SLH"
#define T_IDCARDAPPLY_FPDATA													"fpData"
#define T_IDCARDAPPLY_FPFEATURE													"fpFeature"
#define T_IDCARDAPPLY_XCZP														"XCZP"
#define T_IDCARDAPPLY_XZQH														"XZQH"
#define T_IDCARDAPPLY_SANNERID													"sannerId"
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

#pragma endregion macrodefinition

////////////////////////////////////////////////////////结构定义BEGIN////////////////////////////////////////////////////////
//typedef class tagBUFFER
//{
//public:
//	//tagBUFFER()
//	//{
//	//	byteLen				=  0;
//	//	pBuffer				= NULL
//	//}
//
//	tagBUFFER(LPBYTE buffer, long bufLen)
//	{
//		if (buffer == NULL)
//		{
//			m_pBuffer		= NULL;
//			m_byteLen		= 0;
//		}
//		else
//		{
//			m_pBuffer		= new BYTE[bufLen];
//			m_byteLen		= bufLen;
//			memcpy(m_pBuffer, buffer, bufLen);
//		}
//	}
//
//	tagBUFFER(const tagBUFFER& ob)
//	{
//		*this = ob;
//	}
//	tagBUFFER& operator=(const tagBUFFER& ob)
//	{
//		if (m_pBuffer)
//			delete[] m_pBuffer;
//
//		m_pBuffer		= new BYTE[ob.m_byteLen];
//		m_byteLen		= ob.m_byteLen;
//		memcpy(m_pBuffer, buffer, bufLen);
//
//		return *this;
//	}
//	~tagBUFFER()
//	{
//		if (m_pBuffer)
//			delete[] m_pBuffer;
//
//		m_pBuffer		= NULL;
//		m_byteLen		= 0;
//	}
//
//	long				m_byteLen;
//	LPBYTE				m_pBuffer;
//}BUFFER, *LPBUFFER;
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
		Nation				= "";
		Birthday			= "";
		Address				= "";
		IdNumber			= "";
		SigDepart			= "";
		SLH					= "";
		fpData				= "";
		fpFeature			= "";
		XCZP				= "";
		XZQH				= "";
		sannerId 			= "";
		scannerName			= "";
		legal				= false;
		operatorID			= "";
		operatorName		= "";
		opDate				= "";
	}

	std::string  			name;						//姓名
	std::string  			gender;						//性别
	std::string  			Nation;						//民族
	std::string  			Birthday;					//出生日期
	std::string  			Address;					//地址
	std::string  			IdNumber;					//身份证号码
	std::string  			SigDepart;					//签发机关
	std::string  			SLH;						//受理号
	std::string  			fpData;						//lob 指纹数据
	std::string  			fpFeature;					//lob 指纹特征数据
	std::string  			XCZP;						//lob 现场照片
	std::string  			XZQH;						//行政区划
	std::string  			sannerId;					//指纹仪编号
	std::string  			scannerName;				//指纹仪名称
	bool		  			legal;						//是否合法
	std::string  			operatorID;					//审核员编号
	std::string  			operatorName;				//审核员姓名
	std::string  			opDate;						//操作日期

}IDCARDAPPLY, *LPIDCARDAPPLY;
/**
* @class  tagONLINESTATUS
*
* @brief
****************************************************************************
*/
typedef class tagONLINESTATUS
{
public:
	tagONLINESTATUS::tagONLINESTATUS()
	{
		machineId				= "";
		machineName				= "";
		machineIP				= "";
		machineLongi			= "";
		machineLat				= "";
		currentBusiness			= "";
		businessStartTime		= "";
		businessEndTime			= "";
		businessDone			= false;
	}

	std::string  			machineId;					//自助设备编号
	std::string  			machineName;				//自助设备名称
	std::string  			machineIP;					//自助设备IP地址
	std::string  			machineLongi;				//自助设备经度
	std::string  			machineLat;					//自助设备纬度
	std::string  			currentBusiness;			//当前办理业务环节
	std::string  			businessStartTime;			//开始办理业务时间
	std::string  			businessEndTime;			//结束办理业务时间
	bool		  			businessDone;				//业务是否办理成功

}ONLINESTATUS, *LPONLINESTATUS;

/**
* @class  tagSHULIANGHUIZONG
*
* @brief
****************************************************************************
*/
typedef class tagSHULIANGHUIZONG
{
public:
	tagSHULIANGHUIZONG::tagSHULIANGHUIZONG()
	{
		Xuhao					= 0;
		Shiyongdanwei			= 0;
		Shebeizongshuliang		= 0;
		Qiyongshebei			= 0;
		Yuyueyewu				= 0;
		Yushouliyewu			= 0;
		Jiaofeiyewu				= 0;
		Chaxunyewu				= 0;
		Shebeishouzheng			= 0;
		Xuqianyewu				= 0;
		Benshitongxingzheng		= 0;
		Dianzitongxingzheng		= 0;
		Tongxingzhengzhika		= 0;
		Lidengkequ				= 0;
		Feilidengkequ			= 0;
	}

	int  						Xuhao;					//序号
	int  						Shiyongdanwei;			//使用单位数量
	int  						Shebeizongshuliang;		//设备总数量
	int  						Qiyongshebei;			//设备在线数量
	int  						Yuyueyewu;				//预约业务
	int  						Yushouliyewu;			//预受理业务
	int  						Jiaofeiyewu;			//缴费业务
	int  						Chaxunyewu;				//查询业务
	int		  					Shebeishouzheng;		//设备收证
	int		  					Xuqianyewu;				//续签业务总数
	int		  					Benshitongxingzheng;	//本式通行证
	int		  					Dianzitongxingzheng;	//电子通行证
	int		  					Tongxingzhengzhika;		//通行证制卡总数
	int		  					Lidengkequ;				//立等可取
	int		  					Feilidengkequ;			//非立等可取

}SHULIANGHUIZONG, *LPSHULIANGHUIZONG;
/**
* @class  tagXIANGXITONGJI
*
* @brief
****************************************************************************
*/
typedef class tagXIANGXITONGJI
{
public:
	tagXIANGXITONGJI::tagXIANGXITONGJI()
	{
		
		Xuhao					= 0;
		Nian					= 0;
		Yue						= 0;
		Ri						= 0;
		Xiaoshi					= 0;
		Fenzhong				= 0;
		Shiyongdanwei			= 0;
		Qiyongshebei			= 0;
		Yuyueyewu				= 0;
		Yushouliyewu			= 0;
		Jiaofeiyewu				= 0;
		Chaxunyewu				= 0;
		Shebeishouzheng			= 0;
		Xuqianyewu				= 0;
		Benshitongxingzheng		= 0;
		Dianzitongxingzheng		= 0;
		Tongxingzhengzhika		= 0;
		Lidengkequ				= 0;
		Feilidengkequ			= 0;	
	}

	int  						Xuhao;					//序号
	int  						Nian;					//年份
	int  						Yue;					//月
	int  						Ri;						//日
	int  						Xiaoshi;				//小时
	int  						Fenzhong;				//分钟
	int  						Shiyongdanwei;			//使用单位数量
	int  						Qiyongshebei;			//设备在线数量
	int		  					Yuyueyewu;				//预约业务
	int		  					Yushouliyewu;			//预受理业务
	int		  					Jiaofeiyewu;			//缴费业务
	int		  					Chaxunyewu;				//查询业务
	int		  					Shebeishouzheng;		//设备收证
	int		  					Xuqianyewu;				//续签业务总数
	int		  					Benshitongxingzheng;	//本式通行证
	int		  					Dianzitongxingzheng;	//电子通行证
	int		  					Tongxingzhengzhika;		//通行证制卡总数
	int		  					Lidengkequ;				//立等可取
	int		  					Feilidengkequ;			//非立等可取

}XIANGXITONGJI, *LPXIANGXITONGJI;
/**
* @class  tagZHIQIANSHUJU
*
* @brief
****************************************************************************
*/
typedef class tagZHIQIANSHUJU
{
public:
	tagZHIQIANSHUJU::tagZHIQIANSHUJU()
	{
		Xuhao					= 0;
		Riqi					= "";
		ShebeiIP				= "";
		Yewubianhao				= "";
		YuanZhengjianhaoma		= "";
		Xingming				= "";
		Qianzhuzhonglei			= "";
		ZhikaZhuangtai			= "";
		Zhengjianhaoma			= "";
		Jiekoufanhuijieguo		= "";
		Lianxidianhua			= "";
	}

	int  						Xuhao;					//序号
	string  					Riqi;					//日期
	string  					ShebeiIP;				//设备IP地址
	string  					Yewubianhao;			//业务编号
	string  					YuanZhengjianhaoma;		//原证件号码
	string  					Xingming;				//姓名
	string  					Qianzhuzhonglei;		//签注种类
	string  					ZhikaZhuangtai;			//制卡状态
	string		  				Zhengjianhaoma;			//证件号码
	string		  				Jiekoufanhuijieguo;		//接口返回结果
	string		  				Lianxidianhua;			//联系电话

}ZHIQIANSHUJU, *LPZHIQIANSHUJU;
/**
* @class  tagSHOUZHENGSHUJU
*
* @brief
****************************************************************************
*/
typedef class tagSHOUZHENGSHUJU
{
public:
	tagSHOUZHENGSHUJU::tagSHOUZHENGSHUJU()
	{
		Xuhao					= 0;
		Riqi					= "";
		ShebeiIP				= "";
		Zhengjianleixing		= "";
		Zhengjianhaoma			= "";
		Xingming				= "";
		Shoulibianhao			= "";
		Shifoujiaofei			= "";
	}

	int  						Xuhao;					//序号
	string  					Riqi;					//日期
	string  					ShebeiIP;				//设备IP地址
	string  					Zhengjianleixing;		//证件类型
	string  					Zhengjianhaoma;			//证件号码
	string  					Xingming;				//姓名
	string  					Shoulibianhao;			//受理编号
	string  					Shifoujiaofei;			//是否缴费

}SHOUZHENGSHUJU, *LPSHOUZHENGSHUJU;
/**
* @class  tagQIANZHUSHUJU
*
* @brief
****************************************************************************
*/
typedef class tagQIANZHUSHUJU
{
public:
	tagQIANZHUSHUJU::tagQIANZHUSHUJU()
	{
		Xuhao					= 0;
		Riqi					= "";
		ShebeiIP				= "";
		YuanZhengjianhaoma		= "";
		Xingming				= "";
		Xingbie					= "";
		Chushengriqi			= "";
		Lianxidianhua			= "";
		Yewuleixing				= "";
		Shouliren				= "";
	}

	int  						Xuhao;					//序号
	string  					Riqi;					//日期
	string  					ShebeiIP;				//设备IP地址
	string  					YuanZhengjianhaoma;		//原证件号码
	string  					Xingming;				//姓名
	string  					Xingbie;				//性别
	string  					Chushengriqi;			//出生日期
	string  					Lianxidianhua;			//联系电话
	string  					Yewuleixing;			//业务类型
	string  					Shouliren;				//受理人

}QIANZHUSHUJU, *LPQIANZHUSHUJU;
/**
* @class  tagJIAOKUANSHUJU
*
* @brief
****************************************************************************
*/
typedef class tagJIAOKUANSHUJU
{
public:
	tagJIAOKUANSHUJU::tagJIAOKUANSHUJU()
	{
		Xuhao					= 0;
		Riqi					= "";
		ShebeiIP				= "";
		Zhishoudanweidaima		= "";
		Jiaokuantongzhishuhaoma = "";
		Jiaokuanrenxingming		= "";
		Yingkoukuanheji			= 0.0;
		Jiaoyiriqi				= "";
	}

	int  						Xuhao;					//序号
	string  					Riqi;					//日期
	string  					ShebeiIP;				//设备IP地址
	string  					Zhishoudanweidaima;		//执收单位代码
	string  					Jiaokuantongzhishuhaoma;//缴款通知书号码
	string  					Jiaokuanrenxingming;	//缴款人姓名
	float  						Yingkoukuanheji;		//应扣款合计
	string  					Jiaoyiriqi;				//交易日期

}JIAOKUANSHUJU, *LPJIAOKUANSHUJU;
/**
* @class  tagCHAXUNSHUJU
*
* @brief
****************************************************************************
*/
typedef class tagCHAXUNSHUJU
{
public:
	tagCHAXUNSHUJU::tagCHAXUNSHUJU()
	{
		Xuhao					= 0;
		Riqi					= "";
		ShebeiIP				= "";
		Chaxunhaoma				= "";
		Chaxunleixing			= "";
		Shifouchaxunchenggong	= false;
	}

	int  						Xuhao;					//序号
	string  					Riqi;					//日期
	string  					ShebeiIP;				//设备IP地址
	string  					Chaxunhaoma;			//查询号码
	string  					Chaxunleixing;			//查询类型
	bool  						Shifouchaxunchenggong;	//是否查询成功

}CHAXUNSHUJU, *LPCHAXUNSHUJU;
/**
* @class  tagYUSHOULISHUJU
*
* @brief
****************************************************************************
*/
typedef class tagYUSHOULISHUJU
{
public:
	tagYUSHOULISHUJU::tagYUSHOULISHUJU()
	{
		Xuhao					= 0;
		Riqi					= "";
		ShebeiIP				= "";
		Yewubianhao				= "";
		Xingming				= "";
		Lianxidianhua			= "";
		Chuguoshiyou			= "";
		YuanZhengjianhaoma		= "";
		Qianzhuzhonglei			= "";
		Xingbie					= "";
		Hukousuozaidi			= "";
		Minzu					= "";
	}

	int  						Xuhao;					//序号
	string  					Riqi;					//日期
	string  					ShebeiIP;				//设备IP地址
	string  					Yewubianhao;			//业务编号
	string  					Xingming;				//姓名
	string  					Lianxidianhua;			//联系电话
	string  					Chuguoshiyou;			//出国事由
	string  					YuanZhengjianhaoma;		//原证件号码
	string  					Qianzhuzhonglei;		//签注种类
	string  					Xingbie;				//性别
	string  					Hukousuozaidi;			//户口所在地
	string  					Minzu;					//民族

}YUSHOULISHUJU, *LPYUSHOULISHUJU;
/**
* @class  tagSHEBEIYICHANGSHUJU
*
* @brief
****************************************************************************
*/
typedef class tagSHEBEIYICHANGSHUJU
{
public:
	tagSHEBEIYICHANGSHUJU::tagSHEBEIYICHANGSHUJU()
	{
		Xuhao					= 0;
		Riqi					= "";
		Shiyongdanwei			= "";
		Yichangshejimokuai		= "";
		Yichangyuanyin			= "";
		Yichangxiangxineirong	= "";
	}

	int  						Xuhao;					//序号
	string  					Riqi;					//日期
	string  					Shiyongdanwei;			//使用单位
	string  					Yichangshejimokuai;		//异常涉及模块
	string  					Yichangyuanyin;			//异常原因
	string  					Yichangxiangxineirong;	//异常详细内容

}SHEBEIYICHANGSHUJU, *LPSHEBEIYICHANGSHUJU;
/**
* @class  tagGUANLIYUAN
*
* @brief
****************************************************************************
*/
typedef class tagGUANLIYUAN
{
public:
	tagGUANLIYUAN::tagGUANLIYUAN()
	{
		Xuhao					= 0;
		Yonghuming				= "";
		Mima					= "";
		Youxiaoqi				= "";
		Quanxianjibie			= 0;
	}

	int  						Xuhao;					//序号
	string  					Yonghuming;				//用户名
	string  					Mima;					//密码
	string  					Youxiaoqi;				//有效期
	int  						Quanxianjibie;			//权限级别

}GUANLIYUAN, *LPGUANLIYUAN;
/**
* @class  tagGUANLIYUANCAOZUOJILU
*
* @brief
****************************************************************************
*/
typedef class tagGUANLIYUANCAOZUOJILU
{
public:
	tagGUANLIYUANCAOZUOJILU::tagGUANLIYUANCAOZUOJILU()
	{
		Xuhao					= 0;
		Yonghuming				= "";
		Riqi					= "";
		Caozuoleibie			= "";
		Caozuoneirong			= "";
	}

	int  						Xuhao;					//序号
	string  					Yonghuming;				//用户名
	string  					Riqi;					//操作日期
	string  					Caozuoleibie;			//操作类别
	string  					Caozuoneirong;			//操作内容

}GUANLIYUANCAOZUOJILU, *LPGUANLIYUANCAOZUOJILU;
/**
* @class  tagSHEBEIGUANLI
*
* @brief
****************************************************************************
*/
typedef class tagSHEBEIGUANLI
{
public:
	tagSHEBEIGUANLI::tagSHEBEIGUANLI()
	{
		Xuhao					= 0;
		Sheng					= "";
		Shi						= "";
		Qu						= "";
		Shiyongdanwei			= "";
		IP						= "";
		Shebeileixing			= "";
		Jingdu					= "";
		Weidu					= "";
		Chuangjianshijian		= "";
	}	

	int  						Xuhao;					//序号
	string  					Sheng;					//所属省份
	string  					Shi;					//所属市
	string  					Qu;						//所属区
	string  					Shiyongdanwei;			//使用单位
	string  					IP;						//设备IP地址
	string  					Shebeileixing;			//设备类型
	string  					Jingdu;					//经度
	string  					Weidu;					//纬度
	string  					Chuangjianshijian;		//创建时间

}SHEBEIGUANLI, *LPSHEBEIGUANLI;
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
