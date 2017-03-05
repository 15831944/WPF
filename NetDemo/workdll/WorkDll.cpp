// NetDll.cpp : 定义 DLL 应用程序的导出函数。
//
#include "stdafx.h"
#include "WorkDll.h"
#include "Client.h"
#include "Server.h"

#include "SqliteData.h"

#ifdef _DEBUG
#define _CONMIUNICATION_NET
#else
#define _CONMIUNICATION_LOCAL
#endif // _DEBUG

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

int curServerConnections()
{
	return CServer::GetInstance()->CurServerConnections();
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

void queryTable(char* QuerySql, QueryTableCallBack callBack, bool bSync)
{
#ifdef _CONMIUNICATION_NET
	CClient::GetInstance()->QueryTable(QuerySql, callBack, bSync);
#else
	string strError = "";
	string resultStr = "";
	resultStr.reserve(0x100000);
	CSqliteData::GetInstance()->QueryTable(QuerySql, resultStr, strError);

	if (callBack)
	{
		callBack((char*)resultStr.c_str(), (char*)strError.c_str());
	}
#endif // _CONMIUNICATION_NET
}

void addTable(char* tableName, char* dataStr, AddDataCallBack callBack, bool bSync)
{
#ifdef _CONMIUNICATION_NET
	CClient::GetInstance()->AddTable(tableName, dataStr, callBack, bSync);
#else
	string strError = "";
	CSqliteData::GetInstance()->AddTable(tableName, dataStr, strError);

	if (callBack)
	{
		callBack((char*)strError.c_str());
	}
#endif // _CONMIUNICATION_NET
}