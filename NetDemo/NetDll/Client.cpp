#include "stdafx.h"
#include "Client.h"

client::client(boost::asio::io_service &io_service, boost::asio::ip::tcp::endpoint &endpoint, OnReceiveCallBack pReceiveCallBack)
	: m_io_service(io_service)
	, m_pReceiveCallBack(pReceiveCallBack)
{
	m_pSession = session_ptr(new session(m_io_service, m_pReceiveCallBack));
	//we need to monitor for the client list change event ,a new client connects or one client gets disconnected,
	// and notify all clients when this happens.Thus,we need to keep an array of clients,

	boost::system::error_code ec;
	m_pSession->socket().connect(endpoint, ec);
	if (ec == 0)
		m_pSession->start();
}

void client::run() {

	m_thread = boost::thread(boost::bind(&client::WorkThread, this));
}

void client::WorkThread()
{
	try
	{
		m_io_service.run();
	}
	catch (std::exception &e)
	{
		string str = string("\nIOCP:") + e.what();
		OutputDebugStringA(str.c_str());
	}
}

void client::stop()
{
	if (m_pSession != NULL)
	{
		m_pSession->stop();
	}

	m_io_service.stop(); 
	m_thread.join();
	m_pSession = NULL;
}

void client::send(BYTE* SendBuf, int dataLen)
{
	if (g_clientPtr != NULL && g_clientPtr->m_pSession != NULL && g_clientPtr->m_pSession->bstarted() == 1)
	{
		g_clientPtr->m_pSession->send(SendBuf, dataLen);
	}
}

bool client::stoped()
{
	return m_io_service.stopped();
}
