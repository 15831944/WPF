#pragma once
#include "stdafx.h"

class CServer
{
public:
	~CServer();
protected:
	CServer();

	typedef bool						(*_startServerType)(char *ip, int port, IN OnReceiveCallBack callback, OUT ServerSendData& CallSendData);
	typedef bool						(*_stopServerType)();
	typedef bool						(*_isServerStoped)();

	_startServerType					m_startServerFunc;
	_stopServerType						m_stopServerFunc;
	_isServerStoped						m_isServerStopedFunc;

	ServerSendData						m_sendDataFunc;

	static CServer*						m_pServer;	//内部实例指针
	static void							OnReceiveCallBack(long userID, BYTE* buf, int len, int errorcode, const char* errormsg);
public:
	static CServer* 					GetInstance();
	static void 						ReleaseInstance();
	bool								StartServer(char *ip, int port);
	bool								StopServer();
	bool								ServerStoped();
};

