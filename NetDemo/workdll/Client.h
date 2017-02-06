#pragma once
#include "stdafx.h"
#include "WorkDll.h"

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



	bool								m_bCmdFinished;
	QueryIDCARDAPPLYCallBack			m_QueryIDCARDAPPLYCallBack;
public:
	static CClient* 					GetInstance();
	static void 						ReleaseInstance();
	bool								StartClient(char *ip, int port);
	bool								StopClient();
	bool								ClientStoped();


	void								QueryIDCARDAPPLY(char* querySqlStr, QueryIDCARDAPPLYCallBack callBack);
};

