#include "stdafx.h"
#include "Client.h"

CClient* CClient::m_pClient				= NULL;

CClient::CClient()
{
	m_bCmdFinished						= true;
	HMODULE hNetDll						= LoadLibrary(_T("NetDll.dll"));

	m_startClientFunc					= (_startClientType)GetProcAddress(hNetDll, "startClient");
	m_stopClientFunc					= (_stopClientType)GetProcAddress(hNetDll, "stopClient");
	m_isClientStopedFunc				= (_isClientStoped)GetProcAddress(hNetDll, "isClientStoped");

}


CClient::~CClient()
{
}

void CClient::OnReceiveCallBackFunc(long userID, BYTE* buf, int len, int errorcode, const char* errormsg)
{

	//m_bCmdFinished = true;
}

CClient* CClient::GetInstance()
{
	if (m_pClient == NULL)
		m_pClient = new CClient();

	return m_pClient;
}

void CClient::ReleaseInstance()
{
	if (m_pClient)
	{
		delete m_pClient;
		m_pClient = NULL;
	}
}

bool CClient::StartClient(char *ip, int port)
{
	// TODO:  在此添加控件通知处理程序代码
	if (m_startClientFunc)
	{
		return m_startClientFunc(ip, port, OnReceiveCallBackFunc, m_sendDataFunc);
	}

	return false;
}

bool CClient::StopClient()
{
	// TODO:  在此添加控件通知处理程序代码
	if (m_stopClientFunc)
		return m_stopClientFunc();

	return false;
}

bool CClient::ClientStoped()
{
	if (m_isClientStopedFunc)
		return m_isClientStopedFunc();
	return true;
}

void CClient::QueryIDCARDAPPLY(char* querySqlStr, QueryIDCARDAPPLYCallBack callBack)
{
	m_QueryIDCARDAPPLYCallBack = callBack;
	if (m_QueryIDCARDAPPLYCallBack != NULL)
	{
		if (m_bCmdFinished)
		{
			m_bCmdFinished = false;

			netmsg::MsgString data;
			data.set_str();

		}
	}
}
