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
	void								QuerySendMsg(char* querySqlStr);

	QueryZHIQIANSHUJUCallBack			m_QueryZHIQIANSHUJUCallBack;
	QuerySHOUZHENGSHUJUCallBack			m_QuerySHOUZHENGSHUJUCallBack;
	QueryQIANZHUSHUJUCallBack			m_QueryQIANZHUSHUJUCallBack;
	QueryJIAOKUANSHUJUCallBack			m_QueryJIAOKUANSHUJUCallBack;
	QueryCHAXUNSHUJUCallBack			m_QueryCHAXUNSHUJUCallBack;
	QueryYUSHOULISHUJUCallBack			m_QueryYUSHOULISHUJUCallBack;
	QuerySHEBEIZHUANGTAICallBack		m_QuerySHEBEIZHUANGTAICallBack;
	QuerySHEBEIYICHANGSHUJUCallBack		m_QuerySHEBEIYICHANGSHUJUCallBack;
	QueryGUANLIYUANCallBack				m_QueryGUANLIYUANCallBack;
	QueryGUANLIYUANCAOZUOJILUCallBack	m_QueryGUANLIYUANCAOZUOJILUCallBack;
	QuerySHEBEIGUANLICallBack			m_QuerySHEBEIGUANLICallBack;
	QueryYINGSHEBIAOCallBack			m_QueryYINGSHEBIAOCallBack;
public:
	static CClient* 					GetInstance();
	static void 						ReleaseInstance();
	bool								StartClient(char *ip, int port);
	bool								StopClient();
	bool								ClientStoped();


	void								QueryZHIQIANSHUJU(char* querySqlStr, QueryZHIQIANSHUJUCallBack callBack);
	void								QuerySHOUZHENGSHUJU(char* querySqlStr, QuerySHOUZHENGSHUJUCallBack callBack);
	void								QueryQIANZHUSHUJU(char* querySqlStr, QueryQIANZHUSHUJUCallBack callBack);
	void								QueryJIAOKUANSHUJU(char* querySqlStr, QueryJIAOKUANSHUJUCallBack callBack);
	void								QueryCHAXUNSHUJU(char* querySqlStr, QueryCHAXUNSHUJUCallBack callBack);
	void								QueryYUSHOULISHUJU(char* querySqlStr, QueryYUSHOULISHUJUCallBack callBack);
	void								QuerySHEBEIZHUANGTAI(char* querySqlStr, QuerySHEBEIZHUANGTAICallBack callBack);
	void								QuerySHEBEIYICHANGSHUJU(char* querySqlStr, QuerySHEBEIYICHANGSHUJUCallBack callBack);
	void								QueryGUANLIYUAN(char* querySqlStr, QueryGUANLIYUANCallBack callBack);
	void								QueryGUANLIYUANCAOZUOJILU(char* querySqlStr, QueryGUANLIYUANCAOZUOJILUCallBack callBack);
	void								QuerySHEBEIGUANLI(char* querySqlStr, QuerySHEBEIGUANLICallBack callBack);
	void								QueryYINGSHEBIAO(char* querySqlStr, QueryYINGSHEBIAOCallBack callBack);
};

