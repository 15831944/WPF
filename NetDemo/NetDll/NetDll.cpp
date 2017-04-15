// NetDll.cpp : 定义 DLL 应用程序的导出函数。
//
#include "stdafx.h"
#include "NetDll.h"
#include "Server.h"
#include "Client.h"

boost::mutex									m_sockMutexserver;				//asio::socket不是线程安全的，一把大锁解决问题
boost::asio::io_service							g_io_service;
unique_ptr<server>								g_serverPtr;
bool startServer(char *ip, int port, OnReceiveCallBack callback, OUT ServerSendData& CallSendData)
{
	boost::mutex::scoped_lock Lock(m_sockMutexserver);

	if (g_serverPtr == nullptr || isServerStoped())
	{
		boost::asio::ip::address_v4 v4;
		if (strlen(ip))
			v4 = boost::asio::ip::address_v4::from_string(ip);
		else
			v4 = boost::asio::ip::address_v4::any();
		boost::asio::ip::tcp::endpoint	endpoint(v4, port);

		g_io_service.reset();
		g_serverPtr.reset(new server(g_io_service, endpoint, callback));
		g_serverPtr->run();

		CallSendData = server::send;
	}

	return true;
}

bool stopServer()
{
	boost::mutex::scoped_lock Lock(m_sockMutexserver);

	if (g_serverPtr != nullptr)
	{
		g_serverPtr->stop();
		g_serverPtr			= nullptr;
	}

	return true;
}
bool isServerStoped()
{
	bool bRet = true;

	if (g_serverPtr != nullptr)
		bRet	= g_serverPtr->stoped();

	return bRet;
}

int curServerConnections()
{
	int Ret = 0;

	if (g_serverPtr != nullptr)
		Ret = g_serverPtr->connections();

	return Ret;
}

int getClientIDByIP(char* ip)
{
	int Ret = 0;

	if (g_serverPtr != nullptr)
		Ret = g_serverPtr->getidbyip(ip);

	return Ret;
}

const char* getClientIPByID(int ID)
{
	const char* pRet = nullptr;
	if (g_serverPtr != nullptr)
		pRet = g_serverPtr->getipbyid(ID);

	return pRet;
}

int serverSendBufLen(int ID)
{
	int len = 0;
	if (g_serverPtr != nullptr)
		len = g_serverPtr->curwritebufLen(ID);

	return len;
}

boost::mutex									m_sockMutexclient;				//asio::socket不是线程安全的，一把大锁解决问题
boost::asio::io_service							g_io_service_client;
unique_ptr<client>								g_clientPtr;
bool startClient(char *ip, int port, OnReceiveCallBack callback, OUT ClientSendData& CallSendData)
{
	bool bRet = true;
	boost::mutex::scoped_lock Lock(m_sockMutexclient);
	if (g_clientPtr == nullptr || isClientStoped())
	{
		boost::asio::ip::tcp::endpoint	endpoint(boost::asio::ip::address_v4::from_string(ip), port);

		g_io_service_client.reset();
		g_clientPtr.reset(new client(g_io_service_client, endpoint, callback));
		if (!g_clientPtr->m_pSession->bstarted())
		{
			g_clientPtr->stop();
			g_clientPtr				= nullptr;
			bRet					= false;
		}
		else
		{
			g_clientPtr->run();
			CallSendData = client::send;
		}
	}

	return bRet;
}
bool stopClient()
{
	boost::mutex::scoped_lock Lock(m_sockMutexclient);
	if (g_clientPtr != nullptr)
	{
		g_clientPtr->stop();
		g_clientPtr					= nullptr;
	}

	return true;
}

bool isClientStoped()
{
	if (g_clientPtr != nullptr)
		return g_clientPtr->stoped();

	return true;
}

int clientSendBufLen()
{
	if (g_clientPtr != nullptr)
		return g_clientPtr->curwritebufLen();

	return 0;
}