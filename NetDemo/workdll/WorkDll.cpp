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
bool startClient(char *ip, int port, bool bDevice)
{
	return CClient::GetInstance()->StartClient(ip, port, bDevice);
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
	CClient::GetInstance()->QueryTable(QuerySql, callBack, bSync);

	//string strError = "";
	//string resultStr = "";
	//resultStr.reserve(0x100000);
	//CSqliteData::GetInstance()->QueryTable(QuerySql, resultStr, strError);

	//if (callBack)
	//{
	//	callBack((char*)resultStr.c_str(), (char*)strError.c_str());
	//}
}

void queryOnlieDevCnt(QueryTableCallBack callBack, bool bSync)
{
	CClient::GetInstance()->QueryOnlieDevCnt(callBack, bSync);
}

void addTable(char* tableName, char* dataStr, AddDataCallBack callBack, bool bSync)
{
	CClient::GetInstance()->AddTable(tableName, dataStr, callBack, bSync);

	//string strError = "";
	//CSqliteData::GetInstance()->AddTable(tableName, dataStr, strError);

	//if (callBack)
	//{
	//	callBack((char*)strError.c_str());
	//}
}