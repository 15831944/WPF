#include "stdafx.h"
#include "Client.h"

CClient* CClient::m_pClient				= NULL;

CClient::CClient()
{
	HMODULE hNetDll						= LoadLibrary(_T("NetDll.dll"));

	m_startClientFunc					= (_startClientType)GetProcAddress(hNetDll, "startClient");
	m_stopClientFunc					= (_stopClientType)GetProcAddress(hNetDll, "stopClient");
	m_isClientStopedFunc				= (_isClientStoped)GetProcAddress(hNetDll, "isClientStoped");

	m_globalPackNumber					= 0;
}


CClient::~CClient()
{
}

void CClient::OnReceiveCallBackFunc(long userID, BYTE* buf, int len, int errorcode, const char* errormsg)
{

	if (buf != NULL && len > 0 && errorcode == 0)
	{
		netmsg::MsgPack msgPack;
		if (msgPack.ParseFromArray(buf, len))
		{
			pair<DWORD, void*> pairValue;
			DWORD key = msgPack.head().globalpacknumber();
			if (CClient::GetInstance()->m_requestMap.Pop(key, pairValue))
			{
				if (msgPack.has_querymsgresult())
				{
					string resultstr = msgPack.querymsgresult().resultdata();
					string resulterror = msgPack.querymsgresult().resulterror();
					if (pairValue.second)
						((QueryTableCallBack)pairValue.second)((char*)resultstr.c_str(), (char*)resulterror.c_str());
				}
				else if (msgPack.has_addmsgresult())
				{
					if (pairValue.second)
						((AddDataCallBack)pairValue.second)((char*)msgPack.addmsgresult().resulterror().c_str());
				}
				else if (msgPack.has_querydevcntmsgresult())
				{
					int cnt = msgPack.querydevcntmsgresult().devcnt();
					char ch[MAX_PATH] = {0};
					sprintf_s(ch, "count:%d,;", cnt);
					if (pairValue.second)
						((QueryTableCallBack)pairValue.second)(ch, "");
				}
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

bool CClient::StartClient(char *ip, int port, bool bDevice)
{
	// TODO:  在此添加控件通知处理程序代码
	if (m_startClientFunc && m_startClientFunc(ip, port, CClient::OnReceiveCallBackFunc, m_sendDataFunc))
	{
		RegistType(bDevice);
		return true;
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

void CClient::RegistType(bool bDevice)
{
	if (m_sendDataFunc)
	{
		netmsg::MsgPack pack;
		pack.mutable_head()->set_globalpacknumber(0xFFFFFFFF);
		pack.mutable_head()->set_totalpack(1);
		pack.mutable_head()->set_packindex(1);
		pack.mutable_head()->set_packtype(netmsg::NetMsgType_RegistType);

		pack.mutable_registtype()->set_bdevice(bDevice);

		int msgLen			= pack.ByteSize();
		LPBYTE pBuffer		= new BYTE[msgLen];
		pack.SerializeToArray(pBuffer, msgLen);

		m_sendDataFunc(pBuffer, msgLen);
		delete[] pBuffer;
	}
}


void CClient::QueryOnlieDevCnt(QueryTableCallBack callBack, bool bSync)
{
	if (m_sendDataFunc)
	{
		DWORD numberTemp				= InterlockedIncrement(&m_globalPackNumber);
		m_requestMap.Push(numberTemp, callBack);
		netmsg::MsgPack pack;
		pack.mutable_head()->set_globalpacknumber(numberTemp);
		pack.mutable_head()->set_totalpack(1);
		pack.mutable_head()->set_packindex(1);
		pack.mutable_head()->set_packtype(netmsg::NetMsgType_QueryDevCnt);

		pack.mutable_querydevcntmsg();

		int msgLen			= pack.ByteSize();
		LPBYTE pBuffer		= new BYTE[msgLen];
		pack.SerializeToArray(pBuffer, msgLen);

		m_sendDataFunc(pBuffer, msgLen);
		delete[] pBuffer;

		if (bSync)
		{
			MSG msg;
			while (m_requestMap.Exist(numberTemp))
			{
				if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
				{
					::TranslateMessage(&msg);
					::DispatchMessage(&msg);
				}
				Sleep(100);
			}
		}
	}
}

void CClient::QueryTable(char* QuerySql, QueryTableCallBack callBack, bool bSync)
{
	if (m_sendDataFunc)
	{
		DWORD numberTemp				= InterlockedIncrement(&m_globalPackNumber);
		m_requestMap.Push(numberTemp, callBack);
		netmsg::MsgPack pack;
		pack.mutable_head()->set_globalpacknumber(numberTemp);
		pack.mutable_head()->set_totalpack(1);
		pack.mutable_head()->set_packindex(1);
		pack.mutable_head()->set_packtype(netmsg::NetMsgType_DatabaseQueryAsk);

		pack.mutable_query()->set_msg(QuerySql);

		int msgLen			= pack.ByteSize();
		LPBYTE pBuffer		= new BYTE[msgLen];
		pack.SerializeToArray(pBuffer, msgLen);

		m_sendDataFunc(pBuffer, msgLen);
		delete[] pBuffer;

		if (bSync)
		{
			MSG msg;
			while (m_requestMap.Exist(numberTemp))
			{
				if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
				{
					::TranslateMessage(&msg);
					::DispatchMessage(&msg);
				}
				Sleep(100);
			}
		}
	}
}

void CClient::AddTable(char* tableName, char* dataStr, AddDataCallBack callBack, bool bSync)
{
	if (m_sendDataFunc)
	{
		netmsg::MsgPack pack;
		DWORD numberTemp			= InterlockedIncrement(&m_globalPackNumber);
		m_requestMap.Push(numberTemp, callBack);
		pack.mutable_head()->set_globalpacknumber(numberTemp);
		pack.mutable_head()->set_totalpack(1);
		pack.mutable_head()->set_packindex(1);
		pack.mutable_head()->set_packtype(netmsg::NetMsgType_DatabaseAddAsk);

		pack.mutable_add()->set_tablename(tableName);
		pack.mutable_add()->set_msg(dataStr);

		int msgLen			= pack.ByteSize();
		LPBYTE pBuffer		= new BYTE[msgLen];
		pack.SerializeToArray(pBuffer, msgLen);

		m_sendDataFunc(pBuffer, msgLen);
		delete[] pBuffer;

		if (bSync)
		{
			MSG msg;
			while (m_requestMap.Exist(numberTemp))
			{
				if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
				{
					::TranslateMessage(&msg);
					::DispatchMessage(&msg);
				}
				Sleep(100);
			}
		}
	}
}