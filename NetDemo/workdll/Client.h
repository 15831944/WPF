#pragma once
#include "stdafx.h"
#include "WorkDll.h"
#include "ThreadMap.h"

class CClient
{
public:
	~CClient();
protected:
	CClient();
	static CClient*						m_pClient;	//内部实例指针
	static void							OnReceiveCallBackFunc(long userID, BYTE* buf, int len, int errorcode, const char* errormsg);

	typedef bool						(*_startClientType)(char *ip, int port, IN OnReceiveCallBack callback, OUT ClientSendData& CallSendData);
	typedef bool						(*_stopClientType)();
	typedef bool						(*_isClientStoped)();

	_startClientType					m_startClientFunc;
	_stopClientType						m_stopClientFunc;
	_isClientStoped						m_isClientStopedFunc;

	ClientSendData						m_sendDataFunc;

	DWORD								m_globalPackNumber;	//总的包号
	ThreadMap<DWORD, void*>				m_requestMap;
	bool								m_bDevice;

	void								RegistType(bool bDevice);
public:
	static CClient* 					GetInstance();
	static void 						ReleaseInstance();
	bool								StartClient(char *ip, int port, bool bDevice);
	bool								StopClient();
	bool								ClientStoped();

	void								QueryTable(char* QuerySql, QueryTableCallBack callBack, bool bSync);
	void								AddTable(char* tableName, char* dataStr, AddDataCallBack callBack, bool bSync);
	void								QueryOnlieDevCnt(QueryTableCallBack callBack, bool bSync);
	void								ExcuteSql(char* sqlStr, ExcuteSqlCallBack callBack, bool bSync);
	void								QueryDevSpeed(char* ipStr, QueryTableCallBack callBack, bool bSync);
};

#pragma  once


