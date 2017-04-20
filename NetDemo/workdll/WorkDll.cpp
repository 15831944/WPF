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

void queryTable(char* QuerySql, CallBack callBack, bool bWait)
{
	CClient::GetInstance()->QueryTable(QuerySql, callBack, bWait);

	//string strError = "";
	//string resultStr = "";
	//resultStr.reserve(0x100000);
	//CSqliteData::GetInstance()->QueryTable(QuerySql, resultStr, strError);

	//if (callBack)
	//{
	//	callBack((char*)resultStr.c_str(), (char*)strError.c_str());
	//}
}

void queryOnlieDevCnt(CallBack callBack, bool bWait)
{
	CClient::GetInstance()->QueryOnlieDevCnt(callBack, bWait);
}

void addTable(char* tableName, char* dataStr, CallBack callBack, bool bWait)
{
	CClient::GetInstance()->AddTable(tableName, dataStr, callBack, bWait);

	//string strError = "";
	//CSqliteData::GetInstance()->AddTable(tableName, dataStr, strError);

	//if (callBack)
	//{
	//	callBack("", (char*)strError.c_str());
	//}
}

void addRuanjianbao(char* Bianhao, char* Banbenhao, LPBYTE Anzhuangbao, int datalen, CallBack callBack, bool bWait)
{
	CClient::GetInstance()->AddVersion(Bianhao, Banbenhao, Anzhuangbao, datalen, callBack, bWait);

	//string strError = "";
	//CSqliteData::GetInstance()->AddTable(tableName, dataStr, strError);

	//if (callBack)
	//{
	//	callBack("", (char*)strError.c_str());
	//}
}

void excuteSql(char* sqlStr, CallBack callBack, bool bWait)
{
	CClient::GetInstance()->ExcuteSql(sqlStr, callBack, bWait);

	//string strError = "";
	//CSqliteData::GetInstance()->ExcuteSql(sqlStr, strError);

	//if (callBack)
	//{
	//	callBack((char*)strError.c_str());
	//}
}

void queryDevSpeed(char* ipStr, CallBack callBack, bool bWait)
{
	CClient::GetInstance()->QueryDevSpeed(ipStr, callBack, bWait);
}

void updateClientStatus(bool bNormal, bool bWait)
{
	CClient::GetInstance()->UpdateClientStatus(bNormal, bWait);
}

void queryConnectionsStr(CallBack callBack, bool bWait)
{
	CClient::GetInstance()->QueryConnectionsStr(callBack, bWait);
}

//void upgrade(char* dataStr, CallBack callBack, bool bWait)
//{
//	CClient::GetInstance()->Upgrade(dataStr, callBack, bWait);
//}