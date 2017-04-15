#include "stdafx.h"
#include "Server.h"
#include "SqliteData.h"
#include <time.h>
#include <process.h>

struct UPGRADEARG{
	int sourID;
	netmsg::MsgPack msgpack;
};

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
	m_serverSendBufLenFunc				= (_serverSendBufLen)GetProcAddress(hNetDll, "serverSendBufLen");
}

CServer::~CServer()
{
	StopServer();
}

unsigned __stdcall CServer::ThreadUpgrade(LPVOID lParam)
{
	try
	{ 
		UPGRADEARG *upgradearg	= (UPGRADEARG *)lParam;
		netmsg::MsgPack *pPack	= &upgradearg->msgpack;
		int userID				= upgradearg->sourID;

		netmsg::MsgPack packResult;
		packResult.mutable_head()->set_globalpacknumber(pPack->head().globalpacknumber());
		packResult.mutable_head()->set_totalpack(1);
		packResult.mutable_head()->set_packindex(0);

		int desid		= CServer::GetInstance()->m_getIdByIPFunc((char*)pPack->upgrademsg().ip().c_str());
		if (desid == -1)
		{
			packResult.mutable_upgrademsgresult()->set_resulterror("目标主机不存在！");
		}
		else
		{
			string QueryStr = "Select Anzhuangbao as Anzhuangbao From Ruanjianbao where ";
			QueryStr += " Ruanjianbao.[Banbenhao]='";
			QueryStr += pPack->upgrademsg().version();
			QueryStr += "'";

			string strError = "";
			string Bianhao = "";
			string Banbenhao = "";
			string Anzhuangbao = "";

			CSqliteData::GetInstance()->QueryVersion(QueryStr, Bianhao, Banbenhao, Anzhuangbao, strError);

			if (strError.empty())
			{
				if (Anzhuangbao.empty())
				{
					packResult.mutable_upgrademsgresult()->set_resulterror("未查询到数据！");
					OutDebugLineLogs(__FILE__, __LINE__, __FUNCTION__, "server: SendMsgBuf：mutable_upgrademsgresult");
				}
				else
				{
					netmsg::MsgPack packDowload;
					packDowload.mutable_head()->set_globalpacknumber(pPack->head().globalpacknumber());
					packDowload.mutable_head()->set_totalpack(1);
					packDowload.mutable_head()->set_packindex(0);

					packDowload.mutable_upgradedownloadmsg()->set_seteupdata(Anzhuangbao.c_str(), Anzhuangbao.size());
					packDowload.mutable_upgradedownloadmsg()->set_resulterror("");
					CServer::GetInstance()->SendMsgBuf(desid, packDowload);
					OutDebugLineLogs(__FILE__, __LINE__, __FUNCTION__, "server: SendMsgBuf：mutable_upgradedownloadmsg");


					int packLen = packDowload.ByteSize();
					netmsg::MsgPack packDowloadResult;
					packDowloadResult.mutable_head()->set_globalpacknumber(pPack->head().globalpacknumber());
					packDowloadResult.mutable_head()->set_totalpack(1);
					packDowloadResult.mutable_head()->set_packindex(0);
					do
					{
						int len = CServer::GetInstance()->m_serverSendBufLenFunc(desid);
						char ch[MAX_PATH] ={ 0 };
						sprintf_s(ch, MAX_PATH, "downloadprogress:%d,;", int((packLen - len) * 100.0 / packLen));

						packDowloadResult.mutable_upgradedownloadmsgresult()->set_resultdata(ch);
						packDowloadResult.mutable_upgradedownloadmsgresult()->set_resulterror("");
						CServer::GetInstance()->SendMsgBuf(userID, packDowloadResult);
						OutDebugLineLogs(__FILE__, __LINE__, __FUNCTION__, "server: SendMsgBuf：mutable_upgradedownloadmsgresult");

						if (len == 0)
							break;
						Sleep(50);
					} while (1);


					packDowloadResult.mutable_upgradedownloadmsgresult()->set_resultdata("正在升级中");
					packDowloadResult.mutable_upgradedownloadmsgresult()->set_resulterror("");
					CServer::GetInstance()->SendMsgBuf(userID, packDowloadResult);
					OutDebugLineLogs(__FILE__, __LINE__, __FUNCTION__, "server: SendMsgBuf：mutable_upgradedownloadmsgresult");
					Sleep(2000);
					return 0;
				}
			}
			else
			{
				packResult.mutable_upgrademsgresult()->set_resulterror(strError);
				OutDebugLineLogs(__FILE__, __LINE__, __FUNCTION__, "server: SendMsgBuf：mutable_upgrademsgresult");
			}

			CServer::GetInstance()->SendMsgBuf(userID, packResult);
		}
	}
	catch (exception e)
	{
	}
	

	//BOOL bStop = *((BOOL*)lParam);
	//while (bStop == FALSE)
	//{
	//	string SETITInfoTemp = "";
	//	bool bReadOk = false;
	//	////////////【zy 2014-06-03 ↓】
	//	{//以独占方式文件 
	//		clock_t clk = clock();
	//		while ((clock() - clk < 3000) && (bReadOk == false)) //三秒内等待打开文件
	//		{
	//			try
	//			{
	//				//要求文件必须存在 独占方式
	//				HANDLE hFile = ::CreateFile(SETITFilePath.c_str(), GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	//				if (hFile != INVALID_HANDLE_VALUE)
	//				{
	//					DWORD    fileLen = 0;
	//					DWORD    readLen = 0;

	//					fileLen = GetFileSize(hFile, NULL);
	//					char *infoTemp = new char[fileLen + 1];
	//					memset(infoTemp, 0, fileLen + 1);

	//					::ReadFile(hFile, infoTemp, fileLen, &readLen, NULL);
	//					SETITInfoTemp = infoTemp;
	//					delete[] infoTemp;
	//					bReadOk = true;
	//					CloseHandle(hFile);
	//				}
	//				else if (GetLastError() == ERROR_FILE_NOT_FOUND)
	//				{
	//					SETITInfoTemp = "";
	//					bReadOk = true;
	//				}
	//			}
	//			catch (exception* e)
	//			{
	//			}
	//		}
	//	}
	//	////////////【zy 2014-06-03 ↑】

	//	if (bReadOk)
	//	{
	//		if (SETITInfoTemp == "")
	//		{
	//			KillProgram("Krs_MDClient.exe");
	//		}
	//		else if (SETITInfo != SETITInfoTemp)
	//		{
	//			EnumCmd eCmd;
	//			if (!Cmd_.GetEnumFrmStr(SETITInfoTemp.substr(0, 5), eCmd)){
	//				OutputDebugString("RMTP_HR_SETIT.txt 文件内容不正确");
	//				continue;
	//			}

	//			if (SETITInfoTemp[5] != ':')
	//			{
	//				OutputDebugString("RMTP_HR_SETIT.txt 文件内容不正确");
	//				continue;
	//			}

	//			KillProgram("Krs_MDClient.exe");
	//			string layoutStr = string("HR_LAYOUT_") + SETITInfoTemp.substr(0, 5);
	//			string measureparam = SETITInfoTemp.substr(6);

	//			string CmdStr = string(" -layout ") + layoutStr + string(" -measureparam ") + measureparam + " -u admin -p krs -h ";

	//			ShellExecute(NULL, "open", ClientEXEPath.c_str(), CmdStr.c_str(), NULL, 0);
	//		}

	//		SETITInfo = SETITInfoTemp;
	//	}

	//	Sleep(20);
	//}
	return 0;
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
					OutDebugLineLogs(__FILE__, __LINE__, __FUNCTION__,"server: SendMsgBuf：mutable_registtypemsgresult");
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
					OutDebugLineLogs(__FILE__, __LINE__, __FUNCTION__,"server: SendMsgBuf：mutable_querymsgresult");
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
					OutDebugLineLogs(__FILE__, __LINE__, __FUNCTION__,"server: SendMsgBuf：mutable_addmsgresult");
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
					OutDebugLineLogs(__FILE__, __LINE__, __FUNCTION__,"server: SendMsgBuf：mutable_querydevcntmsgresult");
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
					OutDebugLineLogs(__FILE__, __LINE__, __FUNCTION__,"server: SendMsgBuf：mutable_excutesqlmsgresult");
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

							OutDebugLineLogs(__FILE__, __LINE__, __FUNCTION__,"server: SendMsgBuf：mutable_querydevspeedmsgresult");
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

							OutDebugLineLogs(__FILE__, __LINE__, __FUNCTION__,"server: SendMsgBuf：mutable_querydevspeedmsgresult");
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
							OutDebugLineLogs(__FILE__, __LINE__, __FUNCTION__,"server: SendMsgBuf：mutable_querydevspeedmsgresult");
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

					OutDebugLineLogs(__FILE__, __LINE__, __FUNCTION__,"server: SendMsgBuf：mutable_queryconnectionsstrmsgresult");
				}
				else if (msgPack.has_addversionmsg())
				{

					string tableNameStr = msgPack.add().tablename();
					string addStr		= msgPack.add().msg();
					string strError		= "";
					CSqliteData::GetInstance()->AddVersion(
						(char*)msgPack.addversionmsg().bianhao().c_str(), 
						(char*)msgPack.addversionmsg().banbenhao().c_str(),
						(LPBYTE)msgPack.addversionmsg().anzhuangbao().c_str(),
						msgPack.addversionmsg().anzhuangbao().size(),
						strError
						);

					if (strError.empty())
					{
						packResult.mutable_addversionmsgresult()->set_resultdata("");
						packResult.mutable_addversionmsgresult()->set_resulterror("");
					}
					else
					{
						packResult.mutable_addversionmsgresult()->set_resultdata("");
						packResult.mutable_addversionmsgresult()->set_resulterror(strError);
					}

					CServer::GetInstance()->SendMsgBuf(userID, packResult);
					OutDebugLineLogs(__FILE__, __LINE__, __FUNCTION__, "client: client.receive：has_addversionmsg");
				}
				else if (msgPack.has_upgrademsg())
				{
					UPGRADEARG *upgradearg	= new UPGRADEARG();
					upgradearg->sourID		= userID;
					upgradearg->msgpack		=  netmsg::MsgPack(msgPack);
					_beginthreadex(NULL, 0, ThreadUpgrade, upgradearg, 0, NULL);
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