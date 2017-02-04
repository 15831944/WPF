//********************************************************************
// SQLITEDATADEFINE.H �ļ�ע��
// �ļ��� ��: SQLITEDATADEFINE.H
// �ļ�·�� : E:\PROJECT\RIM3.0\SRC\SDK\RIM30TOOLKIT/
// ���� ����: ����
// ����ʱ�� : 2015/4/23 14:28
// �ļ����� : 
//*********************************************************************
#pragma once

/*******************************/
#pragma region macrodefinition

/** �����豸�������ݿ⣨ҵ����ˣ� */
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

/** ���������ݿ� */
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

/** �������ܣ��ñ�ֻ��һ����¼����Ҫʵʱ���£� */
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

/**��ϸͳ�ƣ���ȷ�����ӣ� */
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

/**��ǩ��ϸ���� */
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

/**��֤��ϸ���� */
#define T_SHOUZHENGSHUJU														"Shouzhengshuju"
#define T_SHOUZHENGSHUJU_XUHAO													"Xuhao"
#define T_SHOUZHENGSHUJU_RIQI													"Riqi"
#define T_SHOUZHENGSHUJU_SHEBEIIP												"ShebeiIP"
#define T_SHOUZHENGSHUJU_ZHENGJIANLEIXING										"Zhengjianleixing"
#define T_SHOUZHENGSHUJU_ZHENGJIANHAOMA											"Zhengjianhaoma"
#define T_SHOUZHENGSHUJU_XINGMING												"Xingming"
#define T_SHOUZHENGSHUJU_SHOULIBIANHAO											"Shoulibianhao"
#define T_SHOUZHENGSHUJU_SHIFOUJIAOFEI											"Shifoujiaofei"

/**ǩע��ϸ���� */
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

/**�ɿ���ϸ���� */
#define T_JIAOKUANSHUJU															"Jiaokuanshuju"
#define T_JIAOKUANSHUJU_XUHAO													"Xuhao"
#define T_JIAOKUANSHUJU_RIQI													"Riqi"
#define T_JIAOKUANSHUJU_SHEBEIIP												"ShebeiIP"
#define T_JIAOKUANSHUJU_ZHISHOUDANWEIDAIMA										"Zhishoudanweidaima"
#define T_JIAOKUANSHUJU_JIAOKUANTONGZHISHUHAOMA									"Jiaokuantongzhishuhaoma"
#define T_JIAOKUANSHUJU_JIAOKUANRENXINGMING										"Jiaokuanrenxingming"
#define T_JIAOKUANSHUJU_YINGKOUKUANHEJI											"Yingkoukuanheji"
#define T_JIAOKUANSHUJU_JIAOYIRIQI												"Jiaoyiriqi"

/**��ѯ��ϸ���� */
#define T_CHAXUNSHUJU															"Chaxunshuju"
#define T_CHAXUNSHUJU_XUHAO														"Xuhao"
#define T_CHAXUNSHUJU_RIQI														"Riqi"
#define T_CHAXUNSHUJU_SHEBEIIP													"ShebeiIP"
#define T_CHAXUNSHUJU_CHAXUNHAOMA												"Chaxunhaoma"
#define T_CHAXUNSHUJU_CHAXUNLEIXING												"Chaxunleixing"
#define T_CHAXUNSHUJU_SHIFOUCHAXUNCHENGGONG										"Shifouchaxunchenggong"

/**Ԥ������ϸ���� */
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

/**�����豸�쳣��ϸ���� */
#define T_SHEBEIYICHANGSHUJU													"Shebeiyichangshuju"
#define T_SHEBEIYICHANGSHUJU_XUHAO												"Xuhao"
#define T_SHEBEIYICHANGSHUJU_RIQI												"Riqi"
#define T_SHEBEIYICHANGSHUJU_SHIYONGDANWEI										"Shiyongdanwei"
#define T_SHEBEIYICHANGSHUJU_YICHANGSHEJIMOKUAI									"Yichangshejimokuai"
#define T_SHEBEIYICHANGSHUJU_YICHANGYUANYIN										"Yichangyuanyin"
#define T_SHEBEIYICHANGSHUJU_YICHANGXIANGXINEIRONG								"Yichangxiangxineirong"

/**����Ա */
#define T_GUANLIYUAN															"Guanliyuan"
#define T_GUANLIYUAN_XUHAO														"Xuhao"
#define T_GUANLIYUAN_YONGHUMING													"Yonghuming"
#define T_GUANLIYUAN_MIMA														"Mima"
#define T_GUANLIYUAN_YOUXIAOQI													"Youxiaoqi"
#define T_GUANLIYUAN_QUANXIANJIBIE												"Quanxianjibie"

/**����Ա������¼ */
#define T_GUANLIYUANCAOZUOJILU													"Guanliyuancaozuojilu"
#define T_GUANLIYUANCAOZUOJILU_YONGHUMING										"Yonghuming"
#define T_GUANLIYUANCAOZUOJILU_RIQI												"Riqi"
#define T_GUANLIYUANCAOZUOJILU_CAOZUOLEIBIE										"Caozuoleibie"
#define T_GUANLIYUANCAOZUOJILU_CAOZUONEIRONG									"Caozuoneirong"

/**�豸���� */
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
	"<!-- �豸������� -->"\
	"<config>\n"\
	"<device name=\"\" >\n"\
	"</device>\n"\
	"</config>"

#pragma endregion macrodefinition

////////////////////////////////////////////////////////�ṹ����BEGIN////////////////////////////////////////////////////////
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

	std::string  			name;						//����
	std::string  			gender;						//�Ա�
	std::string  			Nation;						//����
	std::string  			Birthday;					//��������
	std::string  			Address;					//��ַ
	std::string  			IdNumber;					//���֤����
	std::string  			SigDepart;					//ǩ������
	std::string  			SLH;						//�����
	std::string  			fpData;						//lob ָ������
	std::string  			fpFeature;					//lob ָ����������
	std::string  			XCZP;						//lob �ֳ���Ƭ
	std::string  			XZQH;						//��������
	std::string  			sannerId;					//ָ���Ǳ��
	std::string  			scannerName;				//ָ��������
	bool		  			legal;						//�Ƿ�Ϸ�
	std::string  			operatorID;					//���Ա���
	std::string  			operatorName;				//���Ա����
	std::string  			opDate;						//��������

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

	std::string  			machineId;					//�����豸���
	std::string  			machineName;				//�����豸����
	std::string  			machineIP;					//�����豸IP��ַ
	std::string  			machineLongi;				//�����豸����
	std::string  			machineLat;					//�����豸γ��
	std::string  			currentBusiness;			//��ǰ����ҵ�񻷽�
	std::string  			businessStartTime;			//��ʼ����ҵ��ʱ��
	std::string  			businessEndTime;			//��������ҵ��ʱ��
	bool		  			businessDone;				//ҵ���Ƿ����ɹ�

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

	int  						Xuhao;					//���
	int  						Shiyongdanwei;			//ʹ�õ�λ����
	int  						Shebeizongshuliang;		//�豸������
	int  						Qiyongshebei;			//�豸��������
	int  						Yuyueyewu;				//ԤԼҵ��
	int  						Yushouliyewu;			//Ԥ����ҵ��
	int  						Jiaofeiyewu;			//�ɷ�ҵ��
	int  						Chaxunyewu;				//��ѯҵ��
	int		  					Shebeishouzheng;		//�豸��֤
	int		  					Xuqianyewu;				//��ǩҵ������
	int		  					Benshitongxingzheng;	//��ʽͨ��֤
	int		  					Dianzitongxingzheng;	//����ͨ��֤
	int		  					Tongxingzhengzhika;		//ͨ��֤�ƿ�����
	int		  					Lidengkequ;				//���ȿ�ȡ
	int		  					Feilidengkequ;			//�����ȿ�ȡ

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

	int  						Xuhao;					//���
	int  						Nian;					//���
	int  						Yue;					//��
	int  						Ri;						//��
	int  						Xiaoshi;				//Сʱ
	int  						Fenzhong;				//����
	int  						Shiyongdanwei;			//ʹ�õ�λ����
	int  						Qiyongshebei;			//�豸��������
	int		  					Yuyueyewu;				//ԤԼҵ��
	int		  					Yushouliyewu;			//Ԥ����ҵ��
	int		  					Jiaofeiyewu;			//�ɷ�ҵ��
	int		  					Chaxunyewu;				//��ѯҵ��
	int		  					Shebeishouzheng;		//�豸��֤
	int		  					Xuqianyewu;				//��ǩҵ������
	int		  					Benshitongxingzheng;	//��ʽͨ��֤
	int		  					Dianzitongxingzheng;	//����ͨ��֤
	int		  					Tongxingzhengzhika;		//ͨ��֤�ƿ�����
	int		  					Lidengkequ;				//���ȿ�ȡ
	int		  					Feilidengkequ;			//�����ȿ�ȡ

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

	int  						Xuhao;					//���
	string  					Riqi;					//����
	string  					ShebeiIP;				//�豸IP��ַ
	string  					Yewubianhao;			//ҵ����
	string  					YuanZhengjianhaoma;		//ԭ֤������
	string  					Xingming;				//����
	string  					Qianzhuzhonglei;		//ǩע����
	string  					ZhikaZhuangtai;			//�ƿ�״̬
	string		  				Zhengjianhaoma;			//֤������
	string		  				Jiekoufanhuijieguo;		//�ӿڷ��ؽ��
	string		  				Lianxidianhua;			//��ϵ�绰

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

	int  						Xuhao;					//���
	string  					Riqi;					//����
	string  					ShebeiIP;				//�豸IP��ַ
	string  					Zhengjianleixing;		//֤������
	string  					Zhengjianhaoma;			//֤������
	string  					Xingming;				//����
	string  					Shoulibianhao;			//������
	string  					Shifoujiaofei;			//�Ƿ�ɷ�

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

	int  						Xuhao;					//���
	string  					Riqi;					//����
	string  					ShebeiIP;				//�豸IP��ַ
	string  					YuanZhengjianhaoma;		//ԭ֤������
	string  					Xingming;				//����
	string  					Xingbie;				//�Ա�
	string  					Chushengriqi;			//��������
	string  					Lianxidianhua;			//��ϵ�绰
	string  					Yewuleixing;			//ҵ������
	string  					Shouliren;				//������

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

	int  						Xuhao;					//���
	string  					Riqi;					//����
	string  					ShebeiIP;				//�豸IP��ַ
	string  					Zhishoudanweidaima;		//ִ�յ�λ����
	string  					Jiaokuantongzhishuhaoma;//�ɿ�֪ͨ�����
	string  					Jiaokuanrenxingming;	//�ɿ�������
	float  						Yingkoukuanheji;		//Ӧ�ۿ�ϼ�
	string  					Jiaoyiriqi;				//��������

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

	int  						Xuhao;					//���
	string  					Riqi;					//����
	string  					ShebeiIP;				//�豸IP��ַ
	string  					Chaxunhaoma;			//��ѯ����
	string  					Chaxunleixing;			//��ѯ����
	bool  						Shifouchaxunchenggong;	//�Ƿ��ѯ�ɹ�

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

	int  						Xuhao;					//���
	string  					Riqi;					//����
	string  					ShebeiIP;				//�豸IP��ַ
	string  					Yewubianhao;			//ҵ����
	string  					Xingming;				//����
	string  					Lianxidianhua;			//��ϵ�绰
	string  					Chuguoshiyou;			//��������
	string  					YuanZhengjianhaoma;		//ԭ֤������
	string  					Qianzhuzhonglei;		//ǩע����
	string  					Xingbie;				//�Ա�
	string  					Hukousuozaidi;			//�������ڵ�
	string  					Minzu;					//����

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

	int  						Xuhao;					//���
	string  					Riqi;					//����
	string  					Shiyongdanwei;			//ʹ�õ�λ
	string  					Yichangshejimokuai;		//�쳣�漰ģ��
	string  					Yichangyuanyin;			//�쳣ԭ��
	string  					Yichangxiangxineirong;	//�쳣��ϸ����

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

	int  						Xuhao;					//���
	string  					Yonghuming;				//�û���
	string  					Mima;					//����
	string  					Youxiaoqi;				//��Ч��
	int  						Quanxianjibie;			//Ȩ�޼���

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

	int  						Xuhao;					//���
	string  					Yonghuming;				//�û���
	string  					Riqi;					//��������
	string  					Caozuoleibie;			//�������
	string  					Caozuoneirong;			//��������

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

	int  						Xuhao;					//���
	string  					Sheng;					//����ʡ��
	string  					Shi;					//������
	string  					Qu;						//������
	string  					Shiyongdanwei;			//ʹ�õ�λ
	string  					IP;						//�豸IP��ַ
	string  					Shebeileixing;			//�豸����
	string  					Jingdu;					//����
	string  					Weidu;					//γ��
	string  					Chuangjianshijian;		//����ʱ��

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

////////////////////////////////////////////////////////�ṹ����END////////////////////////////////////////////////////////


#define BOSD_T_RIM_RTM_STATION_TYPE_INIT_DATA(table,id,name)  "DELETE FROM " ##table ";"\
	"INSERT INTO "##table "("##id","##name ") VALUES('1','�̶�վ');"\
	"INSERT INTO "##table "("##id","##name ") VALUES('2','�ɰ���վ');"\
	"INSERT INTO "##table "("##id","##name ") VALUES('3','�ƶ�վ');"\
	"INSERT INTO "##table "("##id","##name ") VALUES('4','��ʱվ');"\
	"INSERT INTO "##table "("##id","##name ") VALUES('5','С��վ');"

#define BOSD_T_RIM_RTM_FUNC_TYPE_INIT_DATA(table,id,name,key)  "DELETE FROM " ##table ";"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(10,'��Ƶ����','FIXFQ');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(11,'��Ƶ����','IF_FQ');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(12,'��Ƶ����','FIXDF');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(13,'��Ƶ����','IF_DF');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(14,'��ɢɨ��','MSCAN');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(15,'Ƶ��ɨ��','FSCAN');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(16,'����ɨ��','DSCAN');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(17,'Ƶ��ɨ��','PSCAN');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(18,'Ƶ�׷���','SPECTRUM');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(19,'ʱ�����','TIMEDOM');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(20,'��������','MULTIDF');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(21,'Ƶ�ʲ���','SCANDF');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(22,'��ɢ�ź�����','MSCANE');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(23,'�ź�����','FSCANE');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(24,'ITU����','ITU');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(25,'���������','WB_DF');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(26,'��Ƶ�������','IFDFEXT');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(27,'��Ƶ���','LPI');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(28,'������','WB_FQ');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(29,'���ֽ��','DIGDEM');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(30,'���ɨ��','WMON');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(31,'����̽��','EDETN');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(32,'��ɢ����','MDF');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(33,'��Ϣ����','SIGNALMEAS');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(34,'�ź�ʶ��','MODREC');"\
	"INSERT INTO "##table "("##id","##name "," ##key ")  VALUES(35,'�źŸ澯','SINA');"

#define BOSD_T_RIM_REGION_NO_INIT_DATA(table,no,name) "DELETE FROM " ##table ";"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('000000','��������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('110000','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('120000','�����' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('130000','�ӱ�ʡ' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('130100','ʯ��ׯ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('130200','��ɽ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('130300','�ػʵ���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('130400','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('130500','��̨��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('130600','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('130700','�żҿ���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('130800','�е���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('130900','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('131000','�ȷ���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('131100','��ˮ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('140000','ɽ��ʡ' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('140100','̫ԭ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('140200','��ͬ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('140300','��Ȫ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('140400','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('140500','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('140600','˷����' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('140700','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('140800','�˳���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('140900','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('141000','�ٷ���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('141100','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('150000','���ɹ�������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('150100','���ͺ�����' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('150200','��ͷ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('150300','�ں���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('150400','�����' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('150500','ͨ����' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('150600','������˹��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('150700','���ױ�����' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('150800','�����׶���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('150900','�����첼��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('152200','�˰���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('152500','���ֹ�����' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('152900','��������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('210000','����ʡ' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('210100','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('210200','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('210300','��ɽ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('210400','��˳��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('210500','��Ϫ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('210600','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('210700','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('210800','Ӫ����' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('210900','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('211000','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('211100','�̽���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('211200','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('211300','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('211400','��«����' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('220000','����ʡ' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('220100','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('220200','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('220300','��ƽ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('220400','��Դ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('220500','ͨ����' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('220600','��ɽ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('220700','��ԭ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('220800','�׳���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('222400','�ӱ߳�����������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('230000','������ʡ' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('230100','��������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('230200','���������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('230300','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('230400','�׸���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('230500','˫Ѽɽ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('230600','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('230700','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('230800','��ľ˹��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('230900','��̨����' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('231000','ĵ������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('231100','�ں���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('231200','�绯��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('232700','���˰������(�Ӹ����)' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('310000','�Ϻ���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('320000','����ʡ' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('320100','�Ͼ���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('320200','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('320300','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('320400','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('320500','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('320600','��ͨ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('320700','���Ƹ���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('320800','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('320900','�γ���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('321000','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('321100','����' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('321200','̩����' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('321300','��Ǩ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('330000','�㽭ʡ' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('330100','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('330200','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('330300','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('330400','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('330500','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('330600','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('330700','����' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('330800','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('330900','��ɽ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('331000','̨����' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('331100','��ˮ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('340000','����ʡ' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('340100','�Ϸ���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('340200','�ߺ���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('340300','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('340400','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('340500','��ɽ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('340600','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('340700','ͭ����' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('340800','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('341000','��ɽ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('341100','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('341200','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('341300','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('341400','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('341500','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('341600','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('341700','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('341800','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('350000','����ʡ' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('350100','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('350200','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('350300','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('350400','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('350500','Ȫ����' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('350600','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('350700','��ƽ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('350800','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('350900','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('360000','����ʡ' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('360100','�ϲ���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('360200','��������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('360300','Ƽ����' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('360400','�Ž���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('360500','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('360600','ӥ̶��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('360700','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('360800','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('360900','�˴���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('361000','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('361100','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('370000','ɽ��ʡ' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('370100','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('370200','�ൺ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('370300','�Ͳ���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('370400','��ׯ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('370500','��Ӫ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('370600','��̨��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('370700','Ϋ����' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('370800','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('370900','̩����' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('371000','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('371100','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('371200','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('371300','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('371400','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('371500','�ĳ���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('371600','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('371700','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('410000','����ʡ' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('410100','֣����' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('410200','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('410300','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('410400','ƽ��ɽ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('410500','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('410600','�ױ���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('410700','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('410800','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('410900','�����' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('411000','�����' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('411100','�����' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('411200','����Ͽ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('411300','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('411400','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('411500','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('411600','�ܿ���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('411700','פ�����' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('420000','����ʡ' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('420100','�人��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('420200','��ʯ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('420300','ʮ����' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('420500','�˲���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('420600','�差��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('420700','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('420800','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('420900','Т����' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('421000','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('421100','�Ƹ���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('421200','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('421300','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('422800','��ʩ������������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('430000','����ʡ' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('430100','��ɳ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('430200','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('430300','��̶��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('430400','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('430500','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('430600','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('430700','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('430800','�żҽ���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('430900','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('431000','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('431100','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('431200','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('431300','¦����' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('433100','��������������������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('440000','�㶫ʡ' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('440100','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('440200','�ع���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('440300','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('440400','�麣��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('440500','��ͷ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('440600','��ɽ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('440700','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('440800','տ����' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('440900','ï����' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('441200','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('441300','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('441400','÷����' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('441500','��β��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('441600','��Դ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('441700','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('441800','��Զ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('441900','��ݸ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('442000','��ɽ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('445100','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('445200','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('445300','�Ƹ���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('450000','����׳��������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('450100','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('450200','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('450300','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('450400','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('450500','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('450600','���Ǹ���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('450700','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('450800','�����' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('450900','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('451000','��ɫ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('451100','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('451200','�ӳ���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('451300','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('451400','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('460000','����ʡ' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('460100','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('460200','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('500000','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('502100','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('502200','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('502300','ǭ����' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('510000','�Ĵ�ʡ' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('510100','�ɶ���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('510300','�Թ���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('510400','��֦����' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('510500','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('510600','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('510700','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('510800','��Ԫ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('510900','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('511000','�ڽ���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('511100','��ɽ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('511300','�ϳ���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('511400','üɽ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('511500','�˱���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('511600','�㰲��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('511700','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('511800','�Ű���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('511900','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('512000','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('513200','���Ӳ���Ǽ��������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('513300','���β���������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('513400','��ɽ����������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('520000','����ʡ' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('520100','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('520200','����ˮ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('520300','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('520400','��˳��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('522200','ͭ�ʵ���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('522300','ǭ���ϲ���������������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('522400','�Ͻڵ���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('522600','ǭ�������嶱��������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('522700','ǭ�ϲ���������������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('530000','����ʡ' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('530100','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('530300','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('530400','��Ϫ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('530500','��ɽ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('530600','��ͨ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('530700','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('530800','�ն���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('530900','�ٲ���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('532300','��������������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('532500','��ӹ���������������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('532600','��ɽ׳������������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('532800','��˫���ɴ���������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('532900','�������������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('533100','�º���徰����������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('533300','ŭ��������������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('533400','�������������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('540000','����������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('540100','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('542100','��������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('542200','ɽ�ϵ���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('542300','�տ������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('542400','��������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('542500','�������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('542600','��֥����' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('610000','����ʡ' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('610100','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('610200','ͭ����' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('610300','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('610400','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('610500','μ����' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('610600','�Ӱ���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('610700','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('610800','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('610900','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('611000','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('620000','����ʡ' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('620100','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('620200','��������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('620300','�����' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('620400','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('620500','��ˮ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('620600','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('620700','��Ҵ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('620800','ƽ����' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('620900','��Ȫ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('621000','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('621100','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('621200','¤����' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('622900','���Ļ���������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('623000','���ϲ���������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('630000','�ຣʡ' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('630100','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('632100','��������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('632200','��������������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('632300','���ϲ���������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('632500','���ϲ���������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('632600','�������������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('632700','��������������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('632800','�����ɹ������������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('640000','���Ļ���������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('640100','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('640200','ʯ��ɽ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('640300','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('640400','��ԭ��' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('640500','������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('650000','�½�ά���������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('650100','��³ľ����' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('650200','����������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('650800','ʯ������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('652100','��³������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('652200','���ܵ���' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('652300','��������������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('652700','���������ɹ�������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('652800','���������ɹ�������' );"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('652900','�����յ���');"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('653000','�������տ¶�����������');"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('653100','��ʲ����');"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('653200','�������');"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('654000','���������������');"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('654200','���ǵ���');"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('654300','����̩����');"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('654400','������');"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('710000','̨��ʡ');"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('810000','����ر�������');"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('820000','�����ر�������');"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('632900','���ľ');"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('633000','����');"\
	"INSERT INTO "##table "("##no","##name ") VALUES ('411800','��Դ��');"
