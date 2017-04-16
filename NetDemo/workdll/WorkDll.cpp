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

int cntServerConnections()
{
	return CServer::GetInstance()->CntConnections();
}

const char* curConnectionsStr()
{
	return CServer::GetInstance()->CurConnections();
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

void queryTable(char* QuerySql, CallBack callBack, bool bSync)
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

void queryOnlieDevCnt(CallBack callBack, bool bSync)
{
	CClient::GetInstance()->QueryOnlieDevCnt(callBack, bSync);
}

void addTable(char* tableName, char* dataStr, CallBack callBack, bool bSync)
{
	CClient::GetInstance()->AddTable(tableName, dataStr, callBack, bSync);

	//string strError = "";
	//CSqliteData::GetInstance()->AddTable(tableName, dataStr, strError);

	//if (callBack)
	//{
	//	callBack("", (char*)strError.c_str());
	//}
}

void addVersion(char* Bianhao, char* Banbenhao, LPBYTE Anzhuangbao, int datalen, CallBack callBack, bool bSync)
{
	CClient::GetInstance()->AddVersion(Bianhao, Banbenhao, Anzhuangbao, datalen, callBack, bSync);

	//string strError = "";
	//CSqliteData::GetInstance()->AddTable(tableName, dataStr, strError);

	//if (callBack)
	//{
	//	callBack("", (char*)strError.c_str());
	//}
}

void excuteSql(char* sqlStr, CallBack callBack, bool bSync)
{
	CClient::GetInstance()->ExcuteSql(sqlStr, callBack, bSync);

	//string strError = "";
	//CSqliteData::GetInstance()->ExcuteSql(sqlStr, strError);

	//if (callBack)
	//{
	//	callBack((char*)strError.c_str());
	//}
}

void upgrade(char* dataStr, CallBack callBack, bool bSync)
{
	CClient::GetInstance()->Upgrade(dataStr, callBack, bSync);
}

void queryDevSpeed(char* ipStr, CallBack callBack, bool bSync)
{
	CClient::GetInstance()->QueryDevSpeed(ipStr, callBack, bSync);
}

void updateClientStatus(bool bNormal, bool bSync)
{
	CClient::GetInstance()->UpdateClientStatus(bNormal, bSync);
}

void queryConnectionsStr(CallBack callBack, bool bSync)
{
	CClient::GetInstance()->QueryConnectionsStr(callBack, bSync);
}
