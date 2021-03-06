#pragma once
#include "stdafx.h"

class CServer
{
public:
	~CServer();
protected:
	CServer();
	static CServer*									m_pServer;	//�ڲ�ʵ��ָ��
	static unsigned __stdcall						ThreadUpgrade(LPVOID lParam);
	static void										OnReceiveCallBackFunc(long userID, BYTE* buf, int len, int errorcode, const char* errormsg);

	typedef bool									(*_startServerType)(char *ip, int port, IN OnReceiveCallBack callback, OUT ServerSendData& CallSendData);
	typedef bool									(*_stopServerType)();
	typedef bool									(*_isServerStoped)();
	typedef int										(*_curServerConnections)();
	typedef int										(*_getIdByIP)(char *ip);
	typedef const char*								(*_getIPByID)(int ID);
	typedef int(*_serverSendBufLen)(int ID);

	_startServerType								m_startServerFunc;
	_stopServerType									m_stopServerFunc;
	_isServerStoped									m_isServerStopedFunc;
	_curServerConnections							m_curServerConnectionsFunc;
	_getIdByIP										m_getIdByIPFunc;
	_getIPByID										m_getIPByIDFunc;
	_serverSendBufLen								m_serverSendBufLenFunc;

	ServerSendData									m_sendDataFunc;

	std::map<DWORD, netmsg::RegistTypeMsg>			m_mapDevice;
	HANDLE											m_mutexHandle;
	void											SendMsgBuf(long userID, ::google::protobuf::Message& msg);

public:
	static CServer* 								GetInstance();
	static void 									ReleaseInstance();
	bool											StartServer(char *ip, int port);
	bool											StopServer();
	bool											ServerStoped();
	int												CntConnections();
	const char*										CurConnections();
};

