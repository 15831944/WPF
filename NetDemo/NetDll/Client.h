#pragma once

#include "Session.h"

class client
{
public:
	client(boost::asio::io_service &io_service, boost::asio::ip::tcp::endpoint &endpoint, OnReceiveCallBack pReceiveCallBack);
private:
	boost::asio::io_service &						m_io_service;
	boost::thread									m_thread;
	OnReceiveCallBack								m_pReceiveCallBack;

	void											WorkThread();
public:
	session_ptr										m_pSession;

	void											run();
	void											stop();
	static void										send(BYTE* SendBuf, int dataLen);
	bool											stoped();
};
extern unique_ptr<client>							g_clientPtr;
