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
	typedef bool(*_isClientStoped)();
	typedef int(*_clientSendBufLen)();

	_startClientType					m_startClientFunc;
	_stopClientType						m_stopClientFunc;
	_isClientStoped						m_isClientStopedFunc;
	_clientSendBufLen					m_clientSendBufLenFunc;

	ClientSendData						m_sendDataFunc;

	DWORD								m_globalPackNumber;	//总的包号
	ThreadMap<DWORD, void*>				m_requestMap;
	bool								m_bDevice;
	vector<string>						m_ipList;
	string								m_ipStr;

public:
	static CClient* 					GetInstance();
	static void 						ReleaseInstance();
	bool								StartClient(char *ip, int port, bool bDevice);
	bool								StopClient();
	bool								ClientStoped();

	void								QueryTable(char* QuerySql, CallBack callBack, bool bWait);
	void								AddTable(char* tableName, char* dataStr, CallBack callBack, bool bWait);
	void								AddVersion(char* Bianhao, char* Banbenhao, LPBYTE Anzhuangbao, int datalen, CallBack callBack, bool bWait);
	void								ReportProgress(int packLen, CallBack callBack);
	void								QueryOnlieDevCnt(CallBack callBack, bool bWait);
	void								ExcuteSql(char* sqlStr, CallBack callBack, bool bWait);
	void								QueryDevSpeed(char* ipStr, CallBack callBack, bool bWait);
	void								UpdateClientStatus(bool bNormal, bool bWait);
	void								QueryConnectionsStr(CallBack callBack, bool bWait);
	void								Upgrade(char* dataStr, CallBack callBack, bool bWait);
};

#pragma  once


