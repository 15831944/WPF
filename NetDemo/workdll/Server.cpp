m_sendDataFunc
m_sendDataFunc
m_sendDataFunc
#include "stdafx.h"
#include "Server.h"
#include "SqliteData.h"

CServer* CServer::m_pServer				= NULL;

CServer::CServer()
{
	HMODULE hNetDll						= LoadLibrary(_T("NetDll.dll"));

	m_startServerFunc					= (_startServerType)GetProcAddress(hNetDll, "startServer");
	m_stopServerFunc					= (_stopServerType)GetProcAddress(hNetDll, "stopServer");
	m_isServerStopedFunc				= (_isServerStoped)GetProcAddress(hNetDll, "isServerStoped");
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
				if (msgPack.has_msgcmd())
				{
					switch (msgPack.head().packtype())
					{
					case netmsg::NetMsgType_DatabaseQueryAsk:
					{
						string strCmd = msgPack.msgcmd().cmd();
						if (strCmd.find(T_IDCARDAPPLY))
						{
							std::vector<tagIDCARDAPPLY>  lcArray;
							string strError = "";
							CSqliteData::GetInstance()->QueryIDCARDAPPLY(strCmd, lcArray, strError);

							netmsg::MsgPack pack;
							pack.mutable_head()->set_totalpack(1);
							pack.mutable_head()->set_packindex(1);
							if (strError.empty())
							{
								pack.mutable_head()->set_packtype(netmsg::NetMsgType_DatabaseQuerySuccess);
								if (lcArray.empty())
								{
									pack.mutable_msgcmd()->set_cmd("未查询到数据！");
								}
								else
								{
									pack.mutable_head()->set_totalpack(lcArray.size());
									for (int i = 0; i < lcArray.size(); ++i)
									{
										pack.mutable_head()->set_packindex(i + 1);
										pack.mutable_msgidcardapplydata()->set_name(lcArray[i].name.c_str(), lcArray[i].name.size());
										pack.mutable_msgidcardapplydata()->set_gender(lcArray[i].gender.c_str(), lcArray[i].gender.size());
										pack.mutable_msgidcardapplydata()->set_nation(lcArray[i].Nation.c_str(), lcArray[i].Nation.size());
										pack.mutable_msgidcardapplydata()->set_birthday(lcArray[i].Birthday.c_str(), lcArray[i].Birthday.size());
										pack.mutable_msgidcardapplydata()->set_address(lcArray[i].Address.c_str(), lcArray[i].Address.size());
										pack.mutable_msgidcardapplydata()->set_idnumber(lcArray[i].IdNumber.c_str(), lcArray[i].IdNumber.size());
										pack.mutable_msgidcardapplydata()->set_sigdepart(lcArray[i].SigDepart.c_str(), lcArray[i].SigDepart.size());
										pack.mutable_msgidcardapplydata()->set_slh(lcArray[i].SLH.c_str(), lcArray[i].SLH.size());
										pack.mutable_msgidcardapplydata()->set_fpdata(lcArray[i].fpData.c_str(), lcArray[i].fpData.size());
										pack.mutable_msgidcardapplydata()->set_fpfeature(lcArray[i].fpFeature.c_str(), lcArray[i].fpFeature.size());
										pack.mutable_msgidcardapplydata()->set_xczp(lcArray[i].XCZP.c_str(), lcArray[i].XCZP.size());
										pack.mutable_msgidcardapplydata()->set_xzqh(lcArray[i].XZQH.c_str(), lcArray[i].XZQH.size());
										pack.mutable_msgidcardapplydata()->set_sannerid(lcArray[i].sannerId.c_str(), lcArray[i].sannerId.size());
										pack.mutable_msgidcardapplydata()->set_scannername(lcArray[i].scannerName.c_str(), lcArray[i].scannerName.size());
										pack.mutable_msgidcardapplydata()->set_legal(lcArray[i].legal);
										pack.mutable_msgidcardapplydata()->set_operatorid(lcArray[i].operatorID.c_str(), lcArray[i].operatorID.size());
										pack.mutable_msgidcardapplydata()->set_operatorname(lcArray[i].operatorName.c_str(), lcArray[i].operatorName.size());
										pack.mutable_msgidcardapplydata()->set_opdate(lcArray[i].opDate.c_str(), lcArray[i].opDate.size());
									
										CServer::GetInstance()->SendMsgBuf(userID, pack);
									}
								}
							}
							else
							{
								pack.mutable_msgcmd()->set_cmd(strError);
							}
						}
						else if (strCmd.find(T_ONLINESTATUS))
						{

						}
						else if (strCmd.find(T_SHULIANGHUIZONG))
						{

						}
						else if (strCmd.find(T_XIANGXITONGJI))
						{

						}
						else if (strCmd.find(T_ZHIQIANSHUJU))
						{

						}
						else if (strCmd.find(T_SHOUZHENGSHUJU))
						{

						}
						else if (strCmd.find(T_QIANZHUSHUJU))
						{

						}
						else if (strCmd.find(T_JIAOKUANSHUJU))
						{

						}
						else if (strCmd.find(T_CHAXUNSHUJU))
						{

						}
						else if (strCmd.find(T_YUSHOULISHUJU))
						{

						}
						else if (strCmd.find(T_SHEBEIYICHANGSHUJU))
						{

						}
						else if (strCmd.find(T_GUANLIYUAN))
						{

						}
						else if (strCmd.find(T_GUANLIYUANCAOZUOJILU))
						{

						}
						else if (strCmd.find(T_SHEBEIGUANLI))
						{

						}
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
					;
				}
				else
				{
					;
				}
			}
		}
	}
	else
	{

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
	if (m_stopServerFunc)
		return m_stopServerFunc();

	return false;
}

bool CServer::ServerStoped()
{
	if (m_isServerStopedFunc)
		return m_isServerStopedFunc();
	return true;
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