#include "stdafx.h"
#include "Server.h"
#include "SqliteData.h"
#include <time.h>

CServer* CServer::m_pServer				= NULL;

CServer::CServer()
{
	m_mutexHandle						= CreateMutex(NULL, FALSE, NULL);
	
	HMODULE hNetDll						= LoadLibrary(_T("NetDll.dll"));

	m_startServerFunc					= (_startServerType)GetProcAddress(hNetDll, "startServer");
	m_stopServerFunc					= (_stopServerType)GetProcAddress(hNetDll, "stopServer");
	m_isServerStopedFunc				= (_isServerStoped)GetProcAddress(hNetDll, "isServerStoped");
	m_curServerConnectionsFunc			= (_curServerConnections)GetProcAddress(hNetDll, "curServerConnections");
	m_getIdByIPFunc						= (_getIdByIP)GetProcAddress(hNetDll, "getClientIDByIP");
}

CServer::~CServer()
{
	StopServer();
}

void CServer::OnReceiveCallBackFunc(long userID, BYTE* buf, int len, int errorcode, const char* errormsg)
{
	if (errorcode == 0)
	{
		if (buf != NULL && len > 0)
		{
			netmsg::MsgPack msgPack;
			if (msgPack.ParseFromArray(buf, len))
			{
				netmsg::MsgPack packResult;
				packResult.mutable_head()->set_globalpacknumber(msgPack.head().globalpacknumber());
				packResult.mutable_head()->set_totalpack(1);
				packResult.mutable_head()->set_packindex(0);

				if (msgPack.has_registtype())
				{
					WaitForSingleObject(CServer::GetInstance()->m_mutexHandle, INFINITE);
					CServer::GetInstance()->m_mapDevice[userID] = msgPack.registtype().bdevice();
					ReleaseMutex(CServer::GetInstance()->m_mutexHandle);
				}
				else if (msgPack.has_query())
				{
					string QueryStr = msgPack.query().msg();
					string strError = "";
					string dataStr  = "";
					CSqliteData::GetInstance()->QueryTable(QueryStr, dataStr, strError);


					if (strError.empty())
					{
						if (dataStr.empty())
						{
							packResult.mutable_querymsgresult()->set_resultdata("");
							packResult.mutable_querymsgresult()->set_resulterror("未查询到数据！");
						}
						else
						{
							packResult.mutable_querymsgresult()->set_resultdata(dataStr);
							packResult.mutable_querymsgresult()->set_resulterror("");
						}
					}
					else
					{
						packResult.mutable_querymsgresult()->set_resultdata("");
						packResult.mutable_querymsgresult()->set_resulterror(strError);
					}

					CServer::GetInstance()->SendMsgBuf(userID, packResult);
				}
				else if (msgPack.has_add())
				{
					string tableNameStr = msgPack.add().tablename();
					string addStr		= msgPack.add().msg();
					string strError		= "";
					CSqliteData::GetInstance()->AddTable((char*)tableNameStr.c_str(), (char*)addStr.c_str(), strError);

					if (strError.empty())
					{
						packResult.mutable_addmsgresult()->set_resulterror("");
					}
					else
					{
						packResult.mutable_addmsgresult()->set_resulterror(strError);
					}

					CServer::GetInstance()->SendMsgBuf(userID, packResult);
				}
				else if (msgPack.has_querydevcntmsg())
				{
					WaitForSingleObject(CServer::GetInstance()->m_mutexHandle, INFINITE);
					int cnt = 0;
					for (std::map<DWORD, bool>::iterator it = CServer::GetInstance()->m_mapDevice.begin(); it != CServer::GetInstance()->m_mapDevice.end(); ++it)
					{
						if (it->second == true) cnt++;
					}
					ReleaseMutex(CServer::GetInstance()->m_mutexHandle);

					packResult.mutable_querydevcntmsgresult()->set_devcnt(cnt);

					CServer::GetInstance()->SendMsgBuf(userID, packResult);
				}
				else if (msgPack.has_excutesqlmsg())
				{
					string sqlStr = msgPack.excutesqlmsg().msg();
					string strError		= "";
					CSqliteData::GetInstance()->ExcuteSql((char*)sqlStr.c_str(), strError);

					if (strError.empty())
					{
						packResult.mutable_excutesqlmsgresult()->set_resulterror("");
					}
					else
					{
						packResult.mutable_excutesqlmsgresult()->set_resulterror(strError);
					}

					CServer::GetInstance()->SendMsgBuf(userID, packResult);
				}
				else if (msgPack.has_querydevspeedmsg())
				{
					int souraskuserID	= msgPack.querydevspeedmsg().askuserid();
					string  sourdesIP	= msgPack.querydevspeedmsg().ipstr();

					if (souraskuserID == -1)
					{	//asker
						int desid		= CServer::GetInstance()->m_getIdByIPFunc((char*)sourdesIP.c_str());

						if (desid == 0)
						{
							packResult.mutable_querydevspeedmsgresult()->set_speed(0);
							packResult.mutable_querydevspeedmsgresult()->set_resulterror("设备不在线");
							CServer::GetInstance()->SendMsgBuf(userID, packResult);
						}
						else
						{
							clock_t startTime = clock();
							msgPack.mutable_head()->set_totalpack(1);

							string ipData;
							ipData.resize(150000);
							msgPack.mutable_querydevspeedmsg()->set_ipstr(ipData);
							msgPack.mutable_querydevspeedmsg()->set_askuserid(userID);
							msgPack.mutable_querydevspeedmsg()->set_starttime(startTime);

							msgPack.mutable_head()->set_packindex(0);
							CServer::GetInstance()->SendMsgBuf(desid, msgPack);

						}
					}
					else
					{	//deser
						if (msgPack.head().totalpack() == (msgPack.head().packindex() + 1))
						{
							clock_t curclk		= clock();
							clock_t startclk	= msgPack.querydevspeedmsg().starttime();
							int totalPack		= msgPack.head().totalpack();
							int packsize		= msgPack.ByteSize();

							int speed = packsize * totalPack * 2 * 1000 /(curclk - startclk);

							packResult.mutable_querydevspeedmsgresult()->set_speed(speed);
							packResult.mutable_querydevspeedmsgresult()->set_resulterror("");
							CServer::GetInstance()->SendMsgBuf(souraskuserID, packResult);
						}
					}
				}
				else
				{

				}
			}
		}
	}
	else
	{
		WaitForSingleObject(CServer::GetInstance()->m_mutexHandle, INFINITE);
		std::map<DWORD, bool>::iterator it = CServer::GetInstance()->m_mapDevice.find(userID);
		if (it != CServer::GetInstance()->m_mapDevice.end()) CServer::GetInstance()->m_mapDevice.erase(it);
		ReleaseMutex(CServer::GetInstance()->m_mutexHandle);
	}
}

CServer* CServer::GetInstance()
{
	if (m_pServer == NULL)
	{
		m_pServer = new CServer();
	}

	return m_pServer;
}

void CServer::ReleaseInstance()
{
	if (m_pServer)
	{
		delete m_pServer;
		m_pServer = NULL;
	}
}

bool CServer::StartServer(char *ip, int port)
{
	// TODO:  在此添加控件通知处理程序代码
	if (m_startServerFunc)
	{
		return m_startServerFunc(ip, port, CServer::OnReceiveCallBackFunc, m_sendDataFunc);
	}

	return false;
}

bool CServer::StopServer()
{
	// TODO:  在此添加控件通知处理程序代码
	bool bRet = false;
	if (m_stopServerFunc)
	{
		bRet = m_stopServerFunc();
	}

	WaitForSingleObject(m_mutexHandle, INFINITE);
	m_mapDevice.clear();
	ReleaseMutex(m_mutexHandle);

	return false;
}

bool CServer::ServerStoped()
{
	if (m_isServerStopedFunc)
		return m_isServerStopedFunc();
	return true;
}

int CServer::CurServerConnections()
{
	if (m_curServerConnectionsFunc)
		return m_curServerConnectionsFunc();
	return 0;
}

void CServer::SendMsgBuf(long userID, ::google::protobuf::Message& msg)
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

		m_sendDataFunc(userID, pBuffer, msgLen);
		delete[] pBuffer;
	}
}