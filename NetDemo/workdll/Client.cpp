#include "stdafx.h"
#include "Client.h"
#include <WinSock2.h>
#include <imagehlp.h>
#include <IPHlpApi.h>
#pragma comment(lib, "wsock32.lib")
#pragma comment(lib, "imagehlp.lib")
#pragma comment(lib, "Iphlpapi.lib")

bool GetAvalibleIpAddress(vector<string> &ipArray)
{
	ipArray.clear();

	// 	CStringArray ipAddresses;

	ULONG ulTalbeSize = 0;
	DWORD res = ::GetIpAddrTable(NULL, &ulTalbeSize, TRUE);
	MIB_IPADDRTABLE *pIpAddTalbe = (MIB_IPADDRTABLE*)new BYTE[ulTalbeSize];
	DWORD ret = ::GetIpAddrTable(pIpAddTalbe, &ulTalbeSize, TRUE);
	if (NO_ERROR == ret)
	{
		DWORD ipAddress = 0;
		for (UINT i = 0; i < pIpAddTalbe->dwNumEntries; i++)
		{
			ipAddress = pIpAddTalbe->table[i].dwAddr;
			if (0 == ipAddress)
				continue;

			// 			ipAddresses.Add(Dword2IpString(pIpAddTalbe->table[i].dwAddr));
			// MIB_IPADDRROW has a dwBCastAddr member but docs say it is broken (and it is!)
			// addr | ~mask = broadcast
			//ipAddress |= ~(pIpAddTalbe->table[i].dwMask);

			ipAddress = ntohl(ipAddress);

			char ch[MAX_PATH] ={ 0 };
			sprintf_s(ch, MAX_PATH, "%d.%d.%d.%d",
				(ipAddress>>24)&0x000000ff,
				(ipAddress>>16)&0x000000ff,
				(ipAddress>>8)&0x000000ff,
				ipAddress&0x000000ff);

			ipArray.push_back(ch);
		}

		if (pIpAddTalbe)
			delete[] pIpAddTalbe;
		pIpAddTalbe = NULL;

		return true;
	}
	else{

		if (pIpAddTalbe)
			delete[] pIpAddTalbe;
		pIpAddTalbe = NULL;
		return false;
	}
}

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
	StopClient();
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
				else if (msgPack.has_excutesqlmsgresult())
				{
					string resulterror = msgPack.excutesqlmsgresult().resulterror();
					if (pairValue.second)
						((ExcuteSqlCallBack)pairValue.second)((char*)resulterror.c_str());
				}
				else if (msgPack.has_querydevspeedmsgresult())
				{
					int speed = msgPack.querydevspeedmsgresult().speed();
					string resulterror = msgPack.querydevspeedmsgresult().resulterror();

					char ch[MAX_PATH] ={ 0 };
					sprintf_s(ch, "speed:%d,;", speed);
					if (pairValue.second)
						((QueryTableCallBack)pairValue.second)(ch, (char*)resulterror.c_str());
				}
			}
			else if (msgPack.has_querydevspeedmsg()) 
			{
				int msgLen			= msgPack.ByteSize();
				LPBYTE pBuffer		= new BYTE[msgLen];
				msgPack.SerializeToArray(pBuffer, msgLen);
				CClient::GetInstance()->m_sendDataFunc(pBuffer, msgLen);
				delete[] pBuffer;
			}
		}
		else
		{
			OutputDebugStringA("\n Work.dll错误数据包");
		}
	}
	else
	{
		OutputDebugStringA("\n Work.dll没有数据");
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

	bool bRet = false;
	if (m_stopClientFunc)
		bRet = m_stopClientFunc();

	m_bDevice			= false;
	m_globalPackNumber	= 0;
	m_requestMap.Clear();

	return bRet;
}

bool CClient::ClientStoped()
{
	if (m_isClientStopedFunc)
		return m_isClientStopedFunc();

	return false;
}

void CClient::RegistType(bool bDevice)
{
	if (m_sendDataFunc)
	{
		netmsg::MsgPack pack;
		pack.mutable_head()->set_globalpacknumber(0xFFFFFFFF);
		pack.mutable_head()->set_totalpack(1);
		pack.mutable_head()->set_packindex(0);

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
		pack.mutable_head()->set_packindex(0);

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
		pack.mutable_head()->set_packindex(0);

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
		pack.mutable_head()->set_packindex(0);

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

void CClient::ExcuteSql(char* sqlStr, ExcuteSqlCallBack callBack, bool bSync)
{
	if (m_sendDataFunc)
	{
		netmsg::MsgPack pack;
		DWORD numberTemp			= InterlockedIncrement(&m_globalPackNumber);
		m_requestMap.Push(numberTemp, callBack);
		pack.mutable_head()->set_globalpacknumber(numberTemp);
		pack.mutable_head()->set_totalpack(1);
		pack.mutable_head()->set_packindex(0);

		pack.mutable_excutesqlmsg()->set_msg(sqlStr);

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

void  CClient::QueryDevSpeed(char* ipStr, QueryTableCallBack callBack, bool bSync)
{
	if (m_sendDataFunc)
	{
		netmsg::MsgPack pack;
		DWORD numberTemp			= InterlockedIncrement(&m_globalPackNumber);
		m_requestMap.Push(numberTemp, callBack);
		pack.mutable_head()->set_globalpacknumber(numberTemp);
		pack.mutable_head()->set_totalpack(1);
		pack.mutable_head()->set_packindex(0);

		pack.mutable_querydevspeedmsg()->set_ipstr(ipStr);
		pack.mutable_querydevspeedmsg()->set_askuserid(-1);
		pack.mutable_querydevspeedmsg()->set_starttime(-1);

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
