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
	CClient::GetInstance()->QueryQIANZHUSHUJU(querySqlStr, callBack);
}

void queryJIAOKUANSHUJU(char* querySqlStr, QueryJIAOKUANSHUJUCallBack callBack)
{
	CClient::GetInstance()->QueryJIAOKUANSHUJU(querySqlStr, callBack);
}

void queryCHAXUNSHUJU(char* querySqlStr, QueryCHAXUNSHUJUCallBack callBack)
{
	CClient::GetInstance()->QueryCHAXUNSHUJU(querySqlStr, callBack);
}

void queryYUSHOULISHUJU(char* querySqlStr, QueryYUSHOULISHUJUCallBack callBack)
{
	CClient::GetInstance()->QueryYUSHOULISHUJU(querySqlStr, callBack);
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
