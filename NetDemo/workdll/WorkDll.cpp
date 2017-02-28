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
	resultStr.reserve(0x100000);
	CSqliteData::GetInstance()->QueryTable(QuerySql, resultStr, strError);

	if (callBack)
	{
		callBack((char*)resultStr.c_str());
	}
}

void addTable(char* tableName, char* dataStr, AddDataCallBack callBack)
{
	string strError = "";


	CSqliteData::GetInstance()->AddTable(tableName, dataStr, strError);

	if (callBack)
	{
		callBack((char*)strError.c_str());
	}
}