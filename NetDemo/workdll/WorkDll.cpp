// NetDll.cpp : 定义 DLL 应用程序的导出函数。
//
#include "stdafx.h"
#include "WorkDll.h"
#include "Client.h"
#include "Server.h"

#include "SqliteData.h"

/***************************************Server*******************************************/
bool startServer(char *ip, int port)
{
	return CServer::GetInstance()->StartServer(ip, port);
}

bool stopServer()
{
	return CServer::GetInstance()->StopServer();
}
bool isServerStoped()
{
	return CServer::GetInstance()->ServerStoped();
}


/***************************************Client*******************************************/
bool startClient(char *ip, int port)
{
	return CClient::GetInstance()->StartClient(ip, port);
}

bool stopClient()
{
	return CClient::GetInstance()->StopClient();
}

bool isClientStoped()
{
	return CClient::GetInstance()->ClientStoped();
}

void queryTable(char* QuerySql, QueryTableCallBack callBack)
{
	string strError = "";
	string resultStr = "";
	CSqliteData::GetInstance()->QueryTable(QuerySql, resultStr, strError);

	if (callBack)
	{
		callBack((char*)resultStr.c_str());
	}
}

void queryZHIQIANSHUJU(char* querySqlStr, QueryZHIQIANSHUJUCallBack callBack)
{
	std::vector<tagZHIQIANSHUJU>  lcArray;
	lcArray.reserve(10000);
	string strError = "";
	CSqliteData::GetInstance()->QueryZHIQIANSHUJU(querySqlStr, lcArray, strError);
	 
	if (callBack)
	{
		for (UINT i = 0; i < lcArray.size(); ++i)
		{
			callBack(
				lcArray[i].Xuhao,
				lcArray[i].Chengshibianhao,
				lcArray[i].Jubianhao,
				lcArray[i].Shiyongdanweibianhao,
				lcArray[i].IP,
				lcArray[i].Bendiyewu,
				lcArray[i].Shebeibaifangweizhi,
				lcArray[i].Riqi,
				(char*)lcArray[i].Yewubianhao.c_str(),
				(char*)lcArray[i].YuanZhengjianhaoma.c_str(),
				(char*)lcArray[i].Xingming.c_str(),
				lcArray[i].Qianzhuzhonglei,
				lcArray[i].ZhikaZhuangtai,
				(char*)lcArray[i].Zhengjianhaoma.c_str(),
				(char*)lcArray[i].Jiekoufanhuijieguo.c_str(),
				(char*)lcArray[i].Lianxidianhua.c_str()
				);
		}
	}

	//CClient::GetInstance()->QueryZHIQIANSHUJU(querySqlStr, callBack);
}

void querySHOUZHENGSHUJU(char* querySqlStr, QuerySHOUZHENGSHUJUCallBack callBack)
{
	std::vector<tagSHOUZHENGSHUJU>  lcArray;
	string strError = "";
	CSqliteData::GetInstance()->QuerySHOUZHENGSHUJU(querySqlStr, lcArray, strError);

	if (callBack)
	{
		for (UINT i = 0; i < lcArray.size(); ++i)
		{
			callBack(
				lcArray[i].Xuhao,
				lcArray[i].Chengshibianhao,
				lcArray[i].Jubianhao,
				lcArray[i].Shiyongdanweibianhao,
				lcArray[i].IP,
				lcArray[i].Bendiyewu,
				lcArray[i].Shebeibaifangweizhi,
				lcArray[i].Riqi,
				lcArray[i].Zhengjianleixing,
				(char*)lcArray[i].Zhengjianhaoma.c_str(),
				(char*)lcArray[i].Xingming.c_str(),
				(char*)lcArray[i].Shoulibianhao.c_str(),
				lcArray[i].Shifoujiaofei
				);
		}
	}
	//CClient::GetInstance()->QuerySHOUZHENGSHUJU(querySqlStr, callBack);
}

void queryQIANZHUSHUJU(char* querySqlStr, QueryQIANZHUSHUJUCallBack callBack)
{
	std::vector<tagQIANZHUSHUJU>  lcArray;
	string strError = "";
	CSqliteData::GetInstance()->QueryQIANZHUSHUJU(querySqlStr, lcArray, strError);

	if (callBack)
	{
		for (UINT i = 0; i < lcArray.size(); ++i)
		{
			callBack(
				lcArray[i].Xuhao,
				lcArray[i].Chengshibianhao,
				lcArray[i].Jubianhao,
				lcArray[i].Shiyongdanweibianhao,
				lcArray[i].IP,
				lcArray[i].Bendiyewu,
				lcArray[i].Shebeibaifangweizhi,
				lcArray[i].Riqi,
				(char*)lcArray[i].YuanZhengjianhaoma.c_str(),
				(char*)lcArray[i].Xingming.c_str(),
				lcArray[i].Xingbie,
				lcArray[i].Chushengriqi,
				(char*)lcArray[i].Lianxidianhua.c_str(),
				lcArray[i].Yewuleixing,
				(char*)lcArray[i].Shouliren.c_str()
				);
		}
	}
	//CClient::GetInstance()->QueryQIANZHUSHUJU(querySqlStr, callBack);
}

void queryJIAOKUANSHUJU(char* querySqlStr, QueryJIAOKUANSHUJUCallBack callBack)
{
	std::vector<tagJIAOKUANSHUJU>  lcArray;
	string strError = "";
	CSqliteData::GetInstance()->QueryJIAOKUANSHUJU(querySqlStr, lcArray, strError);

	if (callBack)
	{
		for (UINT i = 0; i < lcArray.size(); ++i)
		{
			callBack(
				lcArray[i].Xuhao,
				lcArray[i].Chengshibianhao,
				lcArray[i].Jubianhao,
				lcArray[i].Shiyongdanweibianhao,
				lcArray[i].IP,
				lcArray[i].Bendiyewu,
				lcArray[i].Shebeibaifangweizhi,
				lcArray[i].Riqi,
				(char*)lcArray[i].Zhishoudanweidaima.c_str(),
				(char*)lcArray[i].Jiaokuantongzhishuhaoma.c_str(),
				(char*)lcArray[i].Jiaokuanrenxingming.c_str(),
				lcArray[i].Yingkoukuanheji,
				lcArray[i].Jiaoyiriqi
				);
		}
	}
	//CClient::GetInstance()->QueryJIAOKUANSHUJU(querySqlStr, callBack);
}

void queryCHAXUNSHUJU(char* querySqlStr, QueryCHAXUNSHUJUCallBack callBack)
{
	std::vector<tagCHAXUNSHUJU>  lcArray;
	string strError = "";
	CSqliteData::GetInstance()->QueryCHAXUNSHUJU(querySqlStr, lcArray, strError);

	if (callBack)
	{
		for (UINT i = 0; i < lcArray.size(); ++i)
		{
			callBack(
				lcArray[i].Xuhao,
				lcArray[i].Chengshibianhao,
				lcArray[i].Jubianhao,
				lcArray[i].Shiyongdanweibianhao,
				lcArray[i].IP,
				lcArray[i].Bendiyewu,
				lcArray[i].Shebeibaifangweizhi,
				lcArray[i].Riqi,
				(char*)lcArray[i].Chaxunhaoma.c_str(),
				(char*)lcArray[i].Chaxunleixing.c_str(),
				lcArray[i].Shifouchaxunchenggong,
				lcArray[i].Chuangjianshijian
				);
		}
	}
	//CClient::GetInstance()->QueryCHAXUNSHUJU(querySqlStr, callBack);
}

void queryYUSHOULISHUJU(char* querySqlStr, QueryYUSHOULISHUJUCallBack callBack)
{
	std::vector<tagYUSHOULISHUJU>  lcArray;
	string strError = "";
	CSqliteData::GetInstance()->QueryYUSHOULISHUJU(querySqlStr, lcArray, strError);

	if (callBack)
	{
		for (UINT i = 0; i < lcArray.size(); ++i)
		{
			callBack(
				lcArray[i].Xuhao,
				lcArray[i].Chengshibianhao,
				lcArray[i].Jubianhao,
				lcArray[i].Shiyongdanweibianhao,
				lcArray[i].IP,
				lcArray[i].Bendiyewu,
				lcArray[i].Shebeibaifangweizhi,
				lcArray[i].Riqi,
				(char*)lcArray[i].Yewubianhao.c_str(),
				(char*)lcArray[i].Xingming.c_str(),
				(char*)lcArray[i].Lianxidianhua.c_str(),
				(char*)lcArray[i].Chuguoshiyou.c_str(),
				(char*)lcArray[i].YuanZhengjianhaoma.c_str(),
				lcArray[i].Qianzhuzhonglei,
				lcArray[i].Xingbie,
				(char*)lcArray[i].Hukousuozaidi.c_str(),
				(char*)lcArray[i].Minzu.c_str(),
				lcArray[i].Chuangjianshijian
				);
		}
	}
	//CClient::GetInstance()->QueryYUSHOULISHUJU(querySqlStr, callBack);
}

void querySHEBEIZHUANGTAI(char* querySqlStr, QuerySHEBEIZHUANGTAICallBack callBack)
{
	std::vector<tagSHEBEIZHUANGTAI>  lcArray;
	string strError = "";
	CSqliteData::GetInstance()->QuerySHEBEIZHUANGTAI(querySqlStr, lcArray, strError);

	if (callBack)
	{
		for (UINT i = 0; i < lcArray.size(); ++i)
		{
			callBack(
				lcArray[i].Xuhao,
				lcArray[i].Chengshibianhao,
				lcArray[i].Jubianhao,
				lcArray[i].Shiyongdanweibianhao,
				lcArray[i].IP,
				lcArray[i].Bendiyewu,
				lcArray[i].Shebeibaifangweizhi,
				lcArray[i].Riqi,
				lcArray[i].Shifouzaixian
				);
		}
	}
	//CClient::GetInstance()->QuerySHEBEIZHUANGTAI(querySqlStr, callBack);
}

void querySHEBEIYICHANGSHUJU(char* querySqlStr, QuerySHEBEIYICHANGSHUJUCallBack callBack)
{
	std::vector<tagSHEBEIYICHANGSHUJU>  lcArray;
	string strError = "";
	CSqliteData::GetInstance()->QuerySHEBEIYICHANGSHUJU(querySqlStr, lcArray, strError);

	if (callBack)
	{
		for (UINT i = 0; i < lcArray.size(); ++i)
		{
			callBack(
				lcArray[i].Xuhao,
				lcArray[i].Chengshibianhao,
				lcArray[i].Jubianhao,
				lcArray[i].Shiyongdanweibianhao,
				lcArray[i].IP,
				lcArray[i].Bendiyewu,
				lcArray[i].Shebeibaifangweizhi,
				lcArray[i].Riqi,
				(char*)lcArray[i].Yichangshejimokuai.c_str(),
				(char*)lcArray[i].Yichangyuanyin.c_str(),
				(char*)lcArray[i].Yichangxiangxineirong.c_str()
				);
		}
	}
	//CClient::GetInstance()->QuerySHEBEIYICHANGSHUJU(querySqlStr, callBack);
}

void queryGUANLIYUAN(char* querySqlStr, QueryGUANLIYUANCallBack callBack)
{
	std::vector<tagGUANLIYUAN>  lcArray;
	string strError = "";
	CSqliteData::GetInstance()->QueryGUANLIYUAN(querySqlStr, lcArray, strError);

	if (callBack)
	{
		for (UINT i = 0; i < lcArray.size(); ++i)
		{
			callBack(
				lcArray[i].Xuhao,
				(char*)lcArray[i].Yonghuming.c_str(),
				(char*)lcArray[i].Mima.c_str(),
				lcArray[i].Youxiaoqikaishi,
				lcArray[i].Youxiaoqijieshu,
				lcArray[i].Quanxianjibie
				);
		}
	}
	//CClient::GetInstance()->QueryGUANLIYUAN(querySqlStr, callBack);
}

void queryGUANLIYUANCAOZUOJILU(char* querySqlStr, QueryGUANLIYUANCAOZUOJILUCallBack callBack)
{
	std::vector<tagGUANLIYUANCAOZUOJILU>  lcArray;
	string strError = "";
	CSqliteData::GetInstance()->QueryGUANLIYUANCAOZUOJILU(querySqlStr, lcArray, strError);

	if (callBack)
	{
		for (UINT i = 0; i < lcArray.size(); ++i)
		{
			callBack(
				lcArray[i].Xuhao,
				(char*)lcArray[i].Yonghuming.c_str(),
				lcArray[i].Riqi,
				(char*)lcArray[i].Caozuoleibie.c_str(),
				(char*)lcArray[i].Caozuoneirong.c_str()
				);
		}
	}
	//CClient::GetInstance()->QueryGUANLIYUANCAOZUOJILU(querySqlStr, callBack);
}

void querySHEBEIGUANLI(char* querySqlStr, QuerySHEBEIGUANLICallBack callBack)
{
	std::vector<tagSHEBEIGUANLI>  lcArray;
	string strError = "";
	CSqliteData::GetInstance()->QuerySHEBEIGUANLI(querySqlStr, lcArray, strError);

	if (callBack)
	{
		for (UINT i = 0; i < lcArray.size(); ++i)
		{
			callBack(
				lcArray[i].Xuhao,
				lcArray[i].Chengshibianhao,
				lcArray[i].Jubianhao,
				lcArray[i].Shiyongdanweibianhao,
				lcArray[i].IP,
				(char*)lcArray[i].Shebeichangjia.c_str(),
				(char*)lcArray[i].Shebeimingcheng.c_str(),
				(char*)lcArray[i].Shebeileixing.c_str(),
				lcArray[i].Jingdu,
				lcArray[i].Weidu,
				lcArray[i].Chuangjianshijian
				);
		}
	}
	//CClient::GetInstance()->QuerySHEBEIGUANLI(querySqlStr, callBack);
}

void queryYINGSHEBIAO(char* querySqlStr, QueryYINGSHEBIAOCallBack callBack)
{
	std::vector<tagYINGSHEBIAO>  lcArray;
	string strError = "";
	CSqliteData::GetInstance()->QueryYINGSHEBIAO(querySqlStr, lcArray, strError);

	if (callBack)
	{
		for (UINT i = 0; i < lcArray.size(); ++i)
		{
			callBack(
				lcArray[i].Bianhao,
				(char*)lcArray[i].Mingcheng.c_str()
				);
		}
	}
	//CClient::GetInstance()->QueryYINGSHEBIAO(querySqlStr, callBack);
}

void addZHIQIANSHUJU(
	int 						Xuhao,
	int							Chengshibianhao,
	int							Jubianhao,
	int							Shiyongdanweibianhao,
	int							IP,
	bool						Bendiyewu,
	int							Shebeibaifangweizhi,
	__int64						Riqi,
	char*	  					Yewubianhao,
	char*	  					YuanZhengjianhaoma,
	char*	  					Xingming,
	int	  						Qianzhuzhonglei,
	int	  						ZhikaZhuangtai,
	char*	  					Zhengjianhaoma,
	char*	  					Jiekoufanhuijieguo,
	char*	  					Lianxidianhua,
	AddDataCallBack				callBack
	)
{
	tagZHIQIANSHUJU data;
	data.Xuhao									= Xuhao;
	data.Chengshibianhao						= Chengshibianhao;
	data.Jubianhao								= Jubianhao;
	data.Shiyongdanweibianhao					= Shiyongdanweibianhao;
	data.IP										= IP;
	data.Bendiyewu								= Bendiyewu;
	data.Shebeibaifangweizhi					= Shebeibaifangweizhi;
	data.Riqi									= Riqi;
	data.Yewubianhao							= Yewubianhao;
	data.YuanZhengjianhaoma						= YuanZhengjianhaoma;
	data.Xingming								= Xingming;
	data.Qianzhuzhonglei						= Qianzhuzhonglei;
	data.ZhikaZhuangtai							= ZhikaZhuangtai;
	data.Zhengjianhaoma							= Zhengjianhaoma;
	data.Jiekoufanhuijieguo						= Jiekoufanhuijieguo;
	data.Lianxidianhua							= Lianxidianhua;

	string strError = "";
	CSqliteData::GetInstance()->AddZHIQIANSHUJU(data, strError);

	if (callBack)
	{
		callBack((char*)strError.c_str());
	}
}

void    addSHOUZHENGSHUJU(
	int							Xuhao,
	int							Chengshibianhao,
	int							Jubianhao,
	int							Shiyongdanweibianhao,
	int							IP,
	bool						Bendiyewu,
	int							Shebeibaifangweizhi,
	__int64						Riqi,
	int							Zhengjianleixing,
	char*						Zhengjianhaoma,
	char*						Xingming,
	char*						Shoulibianhao,
	bool						Shifoujiaofei,
	AddDataCallBack				callBack
	)
{
	tagSHOUZHENGSHUJU data;
	data.Xuhao						= Xuhao;
	data.Chengshibianhao			= Chengshibianhao;
	data.Jubianhao					= Jubianhao;
	data.Shiyongdanweibianhao		= Shiyongdanweibianhao;
	data.IP							= IP;
	data.Bendiyewu					= Bendiyewu;
	data.Shebeibaifangweizhi		= Shebeibaifangweizhi;
	data.Riqi						= Riqi;
	data.Zhengjianleixing			= Zhengjianleixing;
	data.Zhengjianhaoma				= Zhengjianhaoma;
	data.Xingming					= Xingming;
	data.Shoulibianhao				= Shoulibianhao;
	data.Shifoujiaofei				= Shifoujiaofei;

	string strError = "";
	CSqliteData::GetInstance()->AddSHOUZHENGSHUJU(data, strError);

	if (callBack)
	{
		callBack((char*)strError.c_str());
	}
}
void    addQIANZHUSHUJU(
	int							Xuhao,
	int							Chengshibianhao,
	int							Jubianhao,
	int							Shiyongdanweibianhao,
	int							IP,
	bool						Bendiyewu,
	int							Shebeibaifangweizhi,
	__int64						Riqi,
	char*						YuanZhengjianhaoma,
	char*						Xingming,
	int							Xingbie,
	__int64						Chushengriqi,
	char*						Lianxidianhua,
	int							Yewuleixing,
	char*						Shouliren,
	AddDataCallBack				callBack
	)
{
	tagQIANZHUSHUJU data;
	data.Xuhao						= Xuhao;
	data.Chengshibianhao			= Chengshibianhao;
	data.Jubianhao					= Jubianhao;
	data.Shiyongdanweibianhao		= Shiyongdanweibianhao;
	data.IP							= IP;
	data.Bendiyewu					= Bendiyewu;
	data.Shebeibaifangweizhi		= Shebeibaifangweizhi;
	data.Riqi						= Riqi;
	data.YuanZhengjianhaoma			= YuanZhengjianhaoma;
	data.Xingming					= Xingming;
	data.Xingbie					= Xingbie;
	data.Chushengriqi				= Chushengriqi;
	data.Lianxidianhua				= Lianxidianhua;
	data.Yewuleixing				= Yewuleixing;
	data.Shouliren					= Shouliren;

	string strError = "";
	CSqliteData::GetInstance()->AddQIANZHUSHUJU(data, strError);

	if (callBack)
	{
		callBack((char*)strError.c_str());
	}
}
void    addJIAOKUANSHUJU(
	int							Xuhao,
	int							Chengshibianhao,
	int							Jubianhao,
	int							Shiyongdanweibianhao,
	int							IP,
	bool						Bendiyewu,
	int							Shebeibaifangweizhi,
	__int64						Riqi,
	char*						Zhishoudanweidaima,
	char*						Jiaokuantongzhishuhaoma,
	char*						Jiaokuanrenxingming,
	float						Yingkoukuanheji,
	__int64						Jiaoyiriqi,
	AddDataCallBack				callBack
	)
{
	tagJIAOKUANSHUJU data;
	data.Xuhao						= Xuhao;
	data.Chengshibianhao			= Chengshibianhao;
	data.Jubianhao					= Jubianhao;
	data.Shiyongdanweibianhao		= Shiyongdanweibianhao;
	data.IP							= IP;
	data.Bendiyewu					= Bendiyewu;
	data.Shebeibaifangweizhi		= Shebeibaifangweizhi;
	data.Riqi						= Riqi;
	data.Zhishoudanweidaima			= Zhishoudanweidaima;
	data.Jiaokuantongzhishuhaoma	= Jiaokuantongzhishuhaoma;
	data.Jiaokuanrenxingming		= Jiaokuanrenxingming;
	data.Yingkoukuanheji			= Yingkoukuanheji;
	data.Jiaoyiriqi					= Jiaoyiriqi;

	string strError = "";
	CSqliteData::GetInstance()->AddJIAOKUANSHUJU(data, strError);

	if (callBack)
	{
		callBack((char*)strError.c_str());
	}
}
void    addCHAXUNSHUJU(
	int							Xuhao,
	int		  					Chengshibianhao,
	int		  					Jubianhao,
	int		  					Shiyongdanweibianhao,
	int		  					IP,
	bool						Bendiyewu,
	int							Shebeibaifangweizhi,
	__int64						Riqi,
	char*						Chaxunhaoma,
	char*						Chaxunleixing,
	bool						Shifouchaxunchenggong,
	__int64						Chuangjianshijian,
	AddDataCallBack				callBack
	)
{
	tagCHAXUNSHUJU data;
	data.Xuhao						= Xuhao;
	data.Chengshibianhao			= Chengshibianhao;
	data.Jubianhao					= Jubianhao;
	data.Shiyongdanweibianhao		= Shiyongdanweibianhao;
	data.IP							= IP;
	data.Bendiyewu					= Bendiyewu;
	data.Shebeibaifangweizhi		= Shebeibaifangweizhi;
	data.Riqi						= Riqi;
	data.Chaxunhaoma				= Chaxunhaoma;
	data.Chaxunleixing				= Chaxunleixing;
	data.Shifouchaxunchenggong		= Shifouchaxunchenggong;
	data.Chuangjianshijian			= Chuangjianshijian;

	string strError = "";
	CSqliteData::GetInstance()->AddCHAXUNSHUJU(data, strError);

	if (callBack)
	{
		callBack((char*)strError.c_str());
	}
}
void    addYUSHOULISHUJU(
	int							Xuhao,
	int		  					Chengshibianhao,
	int		  					Jubianhao,
	int		  					Shiyongdanweibianhao,
	int		  					IP,
	bool	  					Bendiyewu,
	int		  					Shebeibaifangweizhi,
	__int64		  				Riqi,
	char*	  					Yewubianhao,
	char*	  					Xingming,
	char*	  					Lianxidianhua,
	char*	  					Chuguoshiyou,
	char*  						YuanZhengjianhaoma,
	int		  					Qianzhuzhonglei,
	int	  						Xingbie,
	char*	  					Hukousuozaidi,
	char*	  					Minzu,
	__int64  					Chuangjianshijian,
	AddDataCallBack				callBack
	)
{
	tagYUSHOULISHUJU data;
	data.Xuhao					= Xuhao;
	data.Chengshibianhao		= Chengshibianhao;
	data.Jubianhao				= Jubianhao;
	data.Shiyongdanweibianhao	= Shiyongdanweibianhao;
	data.IP						= IP;
	data.Bendiyewu				= Bendiyewu;
	data.Shebeibaifangweizhi	= Shebeibaifangweizhi;
	data.Riqi					= Riqi;
	data.Yewubianhao			= Yewubianhao;
	data.Xingming				= Xingming;
	data.Lianxidianhua			= Lianxidianhua;
	data.Chuguoshiyou			= Chuguoshiyou;
	data.YuanZhengjianhaoma		= YuanZhengjianhaoma;
	data.Qianzhuzhonglei		= Qianzhuzhonglei;
	data.Xingbie				= Xingbie;
	data.Hukousuozaidi			= Hukousuozaidi;
	data.Minzu					= Minzu;
	data.Chuangjianshijian		= Chuangjianshijian;

	string strError = "";
	CSqliteData::GetInstance()->AddYUSHOULISHUJU(data, strError);

	if (callBack)
	{
		callBack((char*)strError.c_str());
	}
}
void    addSHEBEIZHUANGTAI(
	int							Xuhao,
	int							Chengshibianhao,
	int							Jubianhao,
	int							Shiyongdanweibianhao,
	int							IP,
	bool						Bendiyewu,
	int							Shebeibaifangweizhi,
	__int64						Riqi,
	bool						Shifouzaixian,
	AddDataCallBack				callBack
	)
{
	tagSHEBEIZHUANGTAI data;
	data.Xuhao					= Xuhao;
	data.Chengshibianhao		= Chengshibianhao;
	data.Jubianhao				= Jubianhao;
	data.Shiyongdanweibianhao	= Shiyongdanweibianhao;
	data.IP						= IP;
	data.Bendiyewu				= Bendiyewu;
	data.Shebeibaifangweizhi	= Shebeibaifangweizhi;
	data.Riqi					= Riqi;
	data.Shifouzaixian			= Shifouzaixian;

	string strError = "";
	CSqliteData::GetInstance()->AddSHEBEIZHUANGTAI(data, strError);

	if (callBack)
	{
		callBack((char*)strError.c_str());
	}
}
void    addSHEBEIYICHANGSHUJU(
	int							Xuhao,
	int		  					Chengshibianhao,
	int		  					Jubianhao,
	int		  					Shiyongdanweibianhao,
	int		  					IP,
	bool	  					Bendiyewu,
	int							Shebeibaifangweizhi,
	__int64						Riqi,
	char*						Yichangshejimokuai,
	char*						Yichangyuanyin,
	char*						Yichangxiangxineirong,
	AddDataCallBack				callBack
	)
{
	tagSHEBEIYICHANGSHUJU data;
	data.Xuhao						= Xuhao;
	data.Chengshibianhao			= Chengshibianhao;
	data.Jubianhao					= Jubianhao;
	data.Shiyongdanweibianhao		= Shiyongdanweibianhao;
	data.IP							= IP;
	data.Bendiyewu					= Bendiyewu;
	data.Shebeibaifangweizhi		= Shebeibaifangweizhi;
	data.Riqi						= Riqi;
	data.Yichangshejimokuai			= Yichangshejimokuai;
	data.Yichangyuanyin				= Yichangyuanyin;
	data.Yichangxiangxineirong		= Yichangxiangxineirong;

	string strError = "";
	CSqliteData::GetInstance()->AddSHEBEIYICHANGSHUJU(data, strError);

	if (callBack)
	{
		callBack((char*)strError.c_str());
	}
}
void    addGUANLIYUAN(
	int  						Xuhao,
	char*  						Yonghuming,
	char*  						Mima,
	int  						Youxiaoqikaishi,
	int  						Youxiaoqijieshu,
	int  						Quanxianjibie,
	AddDataCallBack				callBack
	)
{
	tagGUANLIYUAN data;
	data.Xuhao					= Xuhao;
	data.Yonghuming				= Yonghuming;
	data.Mima					= Mima;
	data.Youxiaoqikaishi		= Youxiaoqikaishi;
	data.Youxiaoqijieshu		= Youxiaoqijieshu;
	data.Quanxianjibie			= Quanxianjibie;
	

	string strError = "";
	CSqliteData::GetInstance()->AddGUANLIYUAN(data, strError);

	if (callBack)
	{
		callBack((char*)strError.c_str());
	}
}
void    addGUANLIYUANCAOZUOJILU(
	int  						Xuhao,
	char*  						Yonghuming,
	__int64  					Riqi,
	char*  						Caozuoleibie,
	char*  						Caozuoneirong,
	AddDataCallBack				callBack
	)
{
	tagGUANLIYUANCAOZUOJILU data;
	data.Xuhao					= Xuhao;
	data.Yonghuming				= Yonghuming;
	data.Riqi					= Riqi;
	data.Caozuoleibie			= Caozuoleibie;
	data.Caozuoneirong			= Caozuoneirong;

	string strError = "";
	CSqliteData::GetInstance()->AddGUANLIYUANCAOZUOJILU(data, strError);

	if (callBack)
	{
		callBack((char*)strError.c_str());
	}
}
void    addSHEBEIGUANLI(
	int							Xuhao,
	int							Chengshibianhao,
	int							Jubianhao,
	int							Shiyongdanweibianhao,
	int							IP,
	char*						Shebeichangjia,
	char*						Shebeimingcheng,
	char*						Shebeileixing,
	float						Jingdu,
	float						Weidu,
	__int64						Chuangjianshijian,
	AddDataCallBack				callBack
	)
{
	tagSHEBEIGUANLI data;
	data.Xuhao					= Xuhao;
	data.Chengshibianhao		= Chengshibianhao;
	data.Jubianhao				= Jubianhao;
	data.Shiyongdanweibianhao	= Shiyongdanweibianhao;
	data.IP						= IP;
	data.Shebeichangjia			= Shebeichangjia;
	data.Shebeimingcheng		= Shebeimingcheng;
	data.Shebeileixing			= Shebeileixing;
	data.Jingdu					= Jingdu;
	data.Weidu					= Weidu;
	data.Chuangjianshijian		= Chuangjianshijian;

	string strError = "";
	CSqliteData::GetInstance()->AddSHEBEIGUANLI(data, strError);

	if (callBack)
	{
		callBack((char*)strError.c_str());
	}
}
void    addYINGSHEBIAO(
	int							Bianhao,
	char*						Mingcheng,
	AddDataCallBack				callBack
	)
{
	tagYINGSHEBIAO data;
	data.Bianhao				= Bianhao;
	data.Mingcheng				= Mingcheng;

	string strError = "";
	CSqliteData::GetInstance()->AddYINGSHEBIAO(data, strError);

	if (callBack)
	{
		callBack((char*)strError.c_str());
	}
}
