#include "stdafx.h"
#include "Client.h"

CClient* CClient::m_pClient				= NULL;

CClient::CClient()
{
	HMODULE hNetDll						= LoadLibrary(_T("NetDll.dll"));

	m_startClientFunc					= (_startClientType)GetProcAddress(hNetDll, "startClient");
	m_stopClientFunc					= (_stopClientType)GetProcAddress(hNetDll, "stopClient");
	m_isClientStopedFunc				= (_isClientStoped)GetProcAddress(hNetDll, "isClientStoped");

}


CClient::~CClient()
{
}

void CClient::OnReceiveCallBack(long userID, BYTE* buf, int len, int errorcode, const char* errormsg)
{

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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (m_startClientFunc)
	{
		return m_startClientFunc(ip, port, OnReceiveCallBack, m_sendDataFunc);
	}

	return false;
}

bool CClient::StopClient()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
