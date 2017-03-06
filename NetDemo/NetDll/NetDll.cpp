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

	if (g_serverPtr == nullptr)
	{
		boost::asio::ip::tcp::endpoint	endpoint(boost::asio::ip::address_v4::from_string(ip), port);

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
	if (g_serverPtr != nullptr)
		return g_serverPtr->stoped();

	return true;
}

int curServerConnections()
{
	if (g_serverPtr != nullptr)
		return g_serverPtr->connections();

	return 0;
}


boost::mutex									m_sockMutexclient;				//asio::socket不是线程安全的，一把大锁解决问题
boost::asio::io_service							g_io_service_client;
unique_ptr<client>								g_clientPtr;
bool startClient(char *ip, int port, OnReceiveCallBack callback, OUT ClientSendData& CallSendData)
{
	boost::mutex::scoped_lock Lock(m_sockMutexclient);
	if (g_clientPtr == nullptr)
	{
		boost::asio::ip::tcp::endpoint	endpoint(boost::asio::ip::address_v4::from_string(ip), port);

		g_io_service_client.reset();
		g_clientPtr.reset(new client(g_io_service_client, endpoint, callback));
		if (!g_clientPtr->m_pSession->bstarted())
		{
			g_clientPtr->stop();
			g_clientPtr					= nullptr;
			return false;
		}
		g_clientPtr->run();
		CallSendData = client::send;
	}

	return true;
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
//std::string geterrormessage(int ev)
//{
//	LPVOID lpMsgBuf = 0;
//	DWORD retval = ::FormatMessageA(
//		FORMAT_MESSAGE_ALLOCATE_BUFFER |
//		FORMAT_MESSAGE_FROM_SYSTEM |
//		FORMAT_MESSAGE_IGNORE_INSERTS,
//		NULL,
//		ev,
//		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
//		(LPSTR)&lpMsgBuf,
//		0,
//		NULL
//		);
//	if (retval == 0)
//		return std::string("Unknown error");
//
//	std::string str(static_cast<LPCSTR>(lpMsgBuf));
//	LocalFree(lpMsgBuf);
//
//	while (str.size()
//		&& (str[str.size()-1] == '\n' || str[str.size()-1] == '\r'))
//		str.erase(str.size()-1);
//	if (str.size() && str[str.size()-1] == '.')
//	{
//		str.erase(str.size()-1);
//	}
//	return str;
//} 