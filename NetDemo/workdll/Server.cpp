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
	m_getIPByIDFunc						= (_getIPByID)GetProcAddress(hNetDll, "getClientIPByID");
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
					msgPack.mutable_registtype()->set_serverip(CServer::GetInstance()->m_getIPByIDFunc(userID));
					WaitForSingleObject(CServer::GetInstance()->m_mutexHandle, INFINITE);
					CServer::GetInstance()->m_mapDevice[userID] = msgPack.registtype();
					ReleaseMutex(CServer::GetInstance()->m_mutexHandle);

					packResult.mutable_registtypemsgresult();
					CServer::GetInstance()->SendMsgBuf(userID, packResult);
					OutputDebugStringA("\ntest: SendMsgBuf：mutable_registtypemsgresult");
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
					OutputDebugStringA("\ntest: SendMsgBuf：mutable_querymsgresult");
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
					OutputDebugStringA("\ntest: SendMsgBuf：mutable_addmsgresult");
				}
				else if (msgPack.has_querydevcntmsg())
				{
					WaitForSingleObject(CServer::GetInstance()->m_mutexHandle, INFINITE);
					int cnt = 0;
					for (std::map<DWORD, netmsg::RegistTypeMsg>::iterator it = CServer::GetInstance()->m_mapDevice.begin(); it != CServer::GetInstance()->m_mapDevice.end(); ++it)
					{
						if (it->second.bdevice() == true) cnt++;
					}
					ReleaseMutex(CServer::GetInstance()->m_mutexHandle);

					packResult.mutable_querydevcntmsgresult()->set_devcnt(cnt);

					CServer::GetInstance()->SendMsgBuf(userID, packResult);
					OutputDebugStringA("\ntest: SendMsgBuf：mutable_querydevcntmsgresult");
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
					OutputDebugStringA("\ntest: SendMsgBuf：mutable_excutesqlmsgresult");
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

							OutputDebugStringA("\ntest: SendMsgBuf：mutable_querydevspeedmsgresult");
						}
						else
						{
							clock_t startTime = clock();
							msgPack.mutable_head()->set_totalpack(1);

							string ipData;
							ipData.resize(9000);
							msgPack.mutable_querydevspeedmsg()->set_ipstr(ipData);
							msgPack.mutable_querydevspeedmsg()->set_askuserid(userID);
							msgPack.mutable_querydevspeedmsg()->set_starttime(startTime);

							msgPack.mutable_head()->set_packindex(0);
							CServer::GetInstance()->SendMsgBuf(desid, msgPack);

							OutputDebugStringA("\ntest: SendMsgBuf：mutable_querydevspeedmsgresult");
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
							OutputDebugStringA("\ntest: SendMsgBuf：mutable_querydevspeedmsgresult");
						}
					}
				}
				else if (msgPack.has_queryconnectionsstrmsg())
				{
					const char *pChar = CServer::GetInstance()->CurConnections();
					
					if (pChar)
					{
						packResult.mutable_queryconnectionsstrmsgresult()->set_resultdata(pChar);
						packResult.mutable_queryconnectionsstrmsgresult()->set_resulterror("");
					}
					else
					{
						packResult.mutable_queryconnectionsstrmsgresult()->set_resultdata("");
						packResult.mutable_queryconnectionsstrmsgresult()->set_resulterror("没有设备！");
					}

					CServer::GetInstance()->SendMsgBuf(userID, packResult);

					OutputDebugStringA("\ntest: SendMsgBuf：mutable_queryconnectionsstrmsgresult");
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
		std::map<DWORD, netmsg::RegistTypeMsg>::iterator it = CServer::GetInstance()->m_mapDevice.find(userID);
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

int CServer::CntConnections()
{
	if (m_curServerConnectionsFunc)
		return m_curServerConnectionsFunc();
	return 0;
}

//#pragma optimize( "", off )
const char* CServer::CurConnections()
{
	static string connectionsStr = "";
	connectionsStr.resize(0);
	WaitForSingleObject(CServer::GetInstance()->m_mutexHandle, INFINITE);
	for (std::map<DWORD, netmsg::RegistTypeMsg>::iterator it = CServer::GetInstance()->m_mapDevice.begin(); it != CServer::GetInstance()->m_mapDevice.end(); ++it)
	{
		char ch[1000] ={ 0 };
		bool bDevice = it->second.bdevice();
		bool bNormal = it->second.bnormal();

		sprintf_s(ch, 1000, "bDevice:%d,ip:%s,serverip:%s,bNormal:%d,;", it->second.bdevice(), it->second.ip().c_str(), it->second.serverip().c_str(), it->second.bnormal());
		connectionsStr += ch;
	}
	ReleaseMutex(CServer::GetInstance()->m_mutexHandle);


	{
		char ch[1000] ={ 0 };
		sprintf_s(ch, 1000, "\nconnectionsStr size:%d,", connectionsStr.size());
		OutputDebugStringA(ch);
	}
	return connectionsStr.c_str();
}
//#pragma optimize( "", on ) 

void CServer::SendMsgBuf(long userID, ::google::protobuf::Message& msg)
{
	if (m_sendDataFunc)
	{
		int msgLen			= msg.ByteSize();
		LPBYTE pBuffer		= new BYTE[msgLen];
		msg.SerializeToArray(pBuffer, msgLen);

		m_sendDataFunc(userID, pBuffer, msgLen);
		delete[] pBuffer;
	}
}