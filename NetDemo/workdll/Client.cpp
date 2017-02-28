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
					case netmsg::NetMsgType_DatabaseAddError:
					case netmsg::NetMsgType_DatabaseAddSuccess:
					{
						CClient::GetInstance()->m_bCmdFinished = true;
					}
					break;
					case netmsg::NetMsgType_DatabaseDeleteError:
					case netmsg::NetMsgType_DatabaseDeleteSuccess:
					{
						CClient::GetInstance()->m_bCmdFinished = true;
					}
					break;
				}
			}
			else if (msgPack.has_msgidcardapplydata())
			{
				/*CClient::GetInstance()->m_QueryIDCARDAPPLYCallBack(
					(char*)msgPack.msgidcardapplydata().name().c_str(),
					(char*)msgPack.msgidcardapplydata().gender().c_str(),
					(char*)msgPack.msgidcardapplydata().nation().c_str(),
					(char*)msgPack.msgidcardapplydata().birthday().c_str(),
					(char*)msgPack.msgidcardapplydata().address().c_str(),
					(char*)msgPack.msgidcardapplydata().idnumber().c_str(),
					(char*)msgPack.msgidcardapplydata().sigdepart().c_str(),
					(char*)msgPack.msgidcardapplydata().slh().c_str(),
					(LPBYTE)msgPack.msgidcardapplydata().fpdata().c_str(),
					msgPack.msgidcardapplydata().fpdata().size(),
					(LPBYTE)msgPack.msgidcardapplydata().fpfeature().c_str(),
					msgPack.msgidcardapplydata().fpfeature().size(),
					(LPBYTE)msgPack.msgidcardapplydata().xczp().c_str(),
					msgPack.msgidcardapplydata().xczp().size(),
					(char*)msgPack.msgidcardapplydata().xzqh().c_str(),
					(char*)msgPack.msgidcardapplydata().sannerid().c_str(),
					(char*)msgPack.msgidcardapplydata().scannername().c_str(),
					msgPack.msgidcardapplydata().legal(),
					(char*)msgPack.msgidcardapplydata().operatorid().c_str(),
					(char*)msgPack.msgidcardapplydata().operatorname().c_str(),
					(char*)msgPack.msgidcardapplydata().opdate().c_str()
					);

				if (msgPack.head().totalpack() == msgPack.head().packindex())
					CClient::GetInstance()->m_bCmdFinished = true;*/
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
void CClient::QuerySendMsg(char* querySqlStr)
{
	if (m_bCmdFinished && m_sendDataFunc)
	{
		m_bCmdFinished = false;

		netmsg::MsgPack pack;
		pack.mutable_head()->set_totalpack(1);
		pack.mutable_head()->set_packindex(1);
		pack.mutable_head()->set_packtype(netmsg::NetMsgType_DatabaseQueryAsk);

		pack.mutable_msgcmd()->set_cmd(querySqlStr);

		int msgLen			= pack.ByteSize();
		LPBYTE pBuffer		= new BYTE[msgLen];
		pack.SerializeToArray(pBuffer, msgLen);

		m_sendDataFunc(pBuffer, msgLen);
		delete[] pBuffer;
	}
}

