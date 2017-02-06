m_bCmdFinished
m_bCmdFinished
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

	if (buf != NULL && len > 0)
	{
		netmsg::MsgPack msgPack;
		if (msgPack.ParseFromArray(buf, len))
		{
			if (msgPack.has_msgcmd())
			{
				switch (msgPack.head().packtype())
				{
				case netmsg::NetMsgType_DatabaseQueryError:
				case netmsg::NetMsgType_DatabaseQuerySuccess:
				{
					CClient::GetInstance()->m_bCmdFinished = true;
				}
				break;
				case netmsg::NetMsgType_DatabaseAddAsk:
					break;
				case netmsg::NetMsgType_DatabaseDeleteAsk:
					break;
				}
			}
			else if (msgPack.has_msgidcardapplydata())
			{

				if (msgPack.head().totalpack() == msgPack.head().packindex())
					CClient::GetInstance()->m_bCmdFinished = true;
			}
		}
	}
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
		return m_startClientFunc(ip, port, CClient::OnReceiveCallBackFunc, m_sendDataFunc);
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
void CClient::SendMsgBuf(::google::protobuf::Message& msg)
{
	if (m_sendDataFunc)
	{
		//int msgLen			= msg.ByteSize();
		//LPBYTE pBuffer		= new BYTE[msgLen + 4];
		//msg.SerializeToArray(pBuffer + 4, msgLen);
		//(*(int*)pBuffer)	= msgLen;

		//m_sendDataFunc(pBuffer, msgLen + 4);


		int msgLen			= msg.ByteSize();
		LPBYTE pBuffer		= new BYTE[msgLen];
		msg.SerializeToArray(pBuffer, msgLen);

		m_sendDataFunc(pBuffer, msgLen);
		delete[] pBuffer;
	}
}

void CClient::QueryIDCARDAPPLY(char* querySqlStr, QueryIDCARDAPPLYCallBack callBack)
{
	m_QueryIDCARDAPPLYCallBack = callBack;
	if (m_QueryIDCARDAPPLYCallBack != NULL)
	{
		if (m_bCmdFinished)
		{
			m_bCmdFinished = false;

			netmsg::MsgPack pack;
			pack.mutable_head()->set_totalpack(1);
			pack.mutable_head()->set_packindex(1);
			pack.mutable_head()->set_packtype(netmsg::NetMsgType_DatabaseQueryAsk);
			
			pack.mutable_msgcmd()->set_cmd(querySqlStr);
			SendMsgBuf(pack);
		}
	}
}
