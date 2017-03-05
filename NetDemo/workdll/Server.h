#pragma once
#include "stdafx.h"

class CServer
{
public:
	~CServer();
protected:
	CServer();
	static CServer*						m_pServer;	//内部实例指针
	static void							OnReceiveCallBackFunc(long userID, BYTE* buf, int len, int errorcode, const char* errormsg);

	typedef bool						(*_startServerType)(char *ip, int port, IN OnReceiveCallBack callback, OUT ServerSendData& CallSendData);
	typedef bool						(*_stopServerType)();
	typedef bool						(*_isServerStoped)();
	typedef bool						(*_curServerConnections)();

	_startServerType					m_startServerFunc;
	_stopServerType						m_stopServerFunc;
	_isServerStoped						m_isServerStopedFunc;
	_curServerConnections				m_curServerConnectionsFunc;

	ServerSendData						m_sendDataFunc;


	void								SendMsgBuf(long userID, ::google::protobuf::Message& msg);
public:
	static CServer* 					GetInstance();
	static void 						ReleaseInstance();
	bool								StartServer(char *ip, int port);
	bool								StopServer();
	bool								ServerStoped();
	bool								CurServerConnections();
};

