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

void queryIDCARDAPPLY(char* querySqlStr, QueryIDCARDAPPLYCallBack callBack)
{
	CClient::GetInstance()->QueryIDCARDAPPLY(querySqlStr, callBack);
}

void queryONLINESTATUS(char* querySqlStr, QueryONLINESTATUSCallBack callBack)
{
	CClient::GetInstance()->QueryONLINESTATUS(querySqlStr, callBack);
}

void querySHULIANGHUIZONG(char* querySqlStr, QuerySHULIANGHUIZONGCallBack callBack)
{
	CClient::GetInstance()->QuerySHULIANGHUIZONG(querySqlStr, callBack);
}

void queryXIANGXITONGJI(char* querySqlStr, QueryXIANGXITONGJICallBack callBack)
{
	CClient::GetInstance()->QueryXIANGXITONGJI(querySqlStr, callBack);
}

void queryZHIQIANSHUJU(char* querySqlStr, QueryZHIQIANSHUJUCallBack callBack)
{
	std::vector<tagZHIQIANSHUJU>  lcArray;
	string strError = "";
	CSqliteData::GetInstance()->QueryZHIQIANSHUJU(querySqlStr, lcArray, strError);
	 
	if (callBack)
	{
		for (int i = 0; i < lcArray.size(); ++i)
		{
			callBack(
				lcArray[i].Xuhao,
				(char*)lcArray[i].Riqi.c_str(),
				(char*)lcArray[i].ShebeiIP.c_str(),
				(char*)lcArray[i].Yewubianhao.c_str(),
				(char*)lcArray[i].YuanZhengjianhaoma.c_str(),
				(char*)lcArray[i].Xingming.c_str(),
				(char*)lcArray[i].Qianzhuzhonglei.c_str(),
				(char*)lcArray[i].ZhikaZhuangtai.c_str(),
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
		for (int i = 0; i < lcArray.size(); ++i)
		{
			callBack(
				lcArray[i].Xuhao, 
				(char*)lcArray[i].Riqi				.c_str(),
				(char*)lcArray[i].ShebeiIP			.c_str(),
				(char*)lcArray[i].Zhengjianleixing	.c_str(),
				(char*)lcArray[i].Zhengjianhaoma	.c_str(),
				(char*)lcArray[i].Xingming			.c_str(),
				(char*)lcArray[i].Shoulibianhao		.c_str(),
				(char*)lcArray[i].Shifoujiaofei		.c_str()
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
		for (int i = 0; i < lcArray.size(); ++i)
		{
			callBack(
				lcArray[i].Xuhao,
				(char*)lcArray[i].Riqi.c_str(),
				(char*)lcArray[i].ShebeiIP.c_str(),
				(char*)lcArray[i].YuanZhengjianhaoma.c_str(),
				(char*)lcArray[i].Xingming.c_str(),
				(char*)lcArray[i].Xingbie.c_str(),
				(char*)lcArray[i].Chushengriqi.c_str(),
				(char*)lcArray[i].Lianxidianhua.c_str(),
				(char*)lcArray[i].Yewuleixing.c_str(),
				(char*)lcArray[i].Shouliren.c_str()
				);
		}
	}
	//CClient::GetInstance()->QueryJIAOKUANSHUJU(querySqlStr, callBack);
}

void queryJIAOKUANSHUJU(char* querySqlStr, QueryJIAOKUANSHUJUCallBack callBack)
{
	std::vector<tagJIAOKUANSHUJU>  lcArray;
	string strError = "";
	CSqliteData::GetInstance()->QueryJIAOKUANSHUJU(querySqlStr, lcArray, strError);

	if (callBack)
	{
		for (int i = 0; i < lcArray.size(); ++i)
		{
			callBack(
				lcArray[i].Xuhao,
				(char*)lcArray[i].Riqi.c_str(),
				(char*)lcArray[i].ShebeiIP.c_str(),
				(char*)lcArray[i].Zhishoudanweidaima.c_str(),
				(char*)lcArray[i].Jiaokuantongzhishuhaoma.c_str(),
				(char*)lcArray[i].Jiaokuanrenxingming.c_str(),
				lcArray[i].Yingkoukuanheji,
				(char*)lcArray[i].Jiaoyiriqi.c_str()
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
		for (int i = 0; i < lcArray.size(); ++i)
		{
			callBack(
				lcArray[i].Xuhao,
				(char*)lcArray[i].Riqi.c_str(),
				(char*)lcArray[i].ShebeiIP.c_str(),
				(char*)lcArray[i].Chaxunhaoma.c_str(),
				(char*)lcArray[i].Chaxunleixing.c_str(),
				lcArray[i].Shifouchaxunchenggong
				);
		}
	}
	//CClient::GetInstance()->QueryJIAOKUANSHUJU(querySqlStr, callBack);
}

void queryYUSHOULISHUJU(char* querySqlStr, QueryYUSHOULISHUJUCallBack callBack)
{
	std::vector<tagYUSHOULISHUJU>  lcArray;
	string strError = "";
	CSqliteData::GetInstance()->QueryYUSHOULISHUJU(querySqlStr, lcArray, strError);

	if (callBack)
	{
		for (int i = 0; i < lcArray.size(); ++i)
		{
			callBack(
				lcArray[i].Xuhao,
				(char*)lcArray[i].Riqi.c_str(),
				(char*)lcArray[i].ShebeiIP.c_str(),
				(char*)lcArray[i].Yewubianhao.c_str(),
				(char*)lcArray[i].Xingming.c_str(),
				(char*)lcArray[i].Lianxidianhua.c_str(),
				(char*)lcArray[i].Chuguoshiyou.c_str(),
				(char*)lcArray[i].YuanZhengjianhaoma.c_str(),
				(char*)lcArray[i].Qianzhuzhonglei.c_str(),
				(char*)lcArray[i].Xingbie.c_str(),
				(char*)lcArray[i].Hukousuozaidi.c_str(),
				(char*)lcArray[i].Minzu.c_str()
				);
		}
	}
	//CClient::GetInstance()->QueryJIAOKUANSHUJU(querySqlStr, callBack);
}

void querySHEBEIYICHANGSHUJU(char* querySqlStr, QuerySHEBEIYICHANGSHUJUCallBack callBack)
{
	CClient::GetInstance()->QuerySHEBEIYICHANGSHUJU(querySqlStr, callBack);
}

void queryGUANLIYUAN(char* querySqlStr, QueryGUANLIYUANCallBack callBack)
{
	CClient::GetInstance()->QueryGUANLIYUAN(querySqlStr, callBack);
}

void queryGUANLIYUANCAOZUOJILU(char* querySqlStr, QueryGUANLIYUANCAOZUOJILUCallBack callBack)
{
	CClient::GetInstance()->QueryGUANLIYUANCAOZUOJILU(querySqlStr, callBack);
}

void querySHEBEIGUANLI(char* querySqlStr, QuerySHEBEIGUANLICallBack callBack)
{
	CClient::GetInstance()->QuerySHEBEIGUANLI(querySqlStr, callBack);
}
