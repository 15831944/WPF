#include "stdafx.h"
#include "Server.h"
list<session_ptr>	server::m_sessions;
boost::mutex		server::m_sessionsMutex;
OnReceiveCallBack	server::m_pReceiveCallBack = NULL;
server::server(boost::asio::io_service &io_service, boost::asio::ip::tcp::endpoint &endpoint, OnReceiveCallBack pReceiveCallBack)
	: m_io_service(io_service)
	, m_acceptor(io_service, endpoint)
	, m_work(new boost::asio::io_service::work(io_service))
{
	m_pReceiveCallBack		= pReceiveCallBack;
	session_ptr new_session(new session(m_io_service, &server::OnServerCallBack));

	//each new client connection will then trigger another asynchronous wait
	m_acceptor.async_accept(new_session->socket(),
		boost::bind(&server::handle_accept,
		this,
		new_session,
		boost::asio::placeholders::error));
}

void server::OnServerCallBack(OUT long userID /*Only for Server*/, OUT BYTE* buf, OUT int len, OUT int errorcode, OUT const char* errormsg)
{
	if (errorcode != 0)
	{
		boost::mutex::scoped_lock Lock(m_sessionsMutex);
		for (list<session_ptr>::iterator it = m_sessions.begin(); it != m_sessions.end();)
		{	////清除已无用的连接对象
			if (!(*it)->bstarted() || int((*it).get()) == userID)
			{
				(*it)->stop();
				(*it) = nullptr;
				it = m_sessions.erase(it);
			}
			else
				++it;
		}
		Lock.unlock();
	}

	if (m_pReceiveCallBack)
		m_pReceiveCallBack(userID, buf, len, errorcode, errormsg);
}

void server::handle_accept(session_ptr new_session, const boost::system::error_code& error) {
	if (error) 
	{
		string str = string("\nhandle_accept:") + error.message();
		OutputDebugStringA(str.c_str());
		return;
	}

	//we need to monitor for the client list change event ,a new client connects or one client gets disconnected,
	// and notify all clients when this happens.Thus,we need to keep an array of clients,

	boost::mutex::scoped_lock Lock(m_sessionsMutex);
	m_sessions.push_back(new_session);
	Lock.unlock();

	new_session->start();
	session_ptr next_session(new session(m_io_service, &server::OnServerCallBack));

	m_acceptor.async_accept(next_session->socket(),
		boost::bind(&server::handle_accept,
		this,
		next_session,
		boost::asio::placeholders::error));
}

void server::run() {

	//boost::thread t(boost::bind(&boost::asio::io_service::run, boost::ref(m_io_service)));


	int thread_count=(std::max)(static_cast<int>(boost::thread::hardware_concurrency()), 1);

	for (int i=0; i<thread_count; i++)
	{
		//tg.create_thread(boost::bind(&boost::asio::io_service::run, boost::ref(m_io_service)));
		m_tg.create_thread(std::bind(&server::WorkThread, this));

		boost::this_thread::sleep(boost::posix_time::microseconds(100));
	}

}

void server::WorkThread()
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

void server::stop()
{
	boost::mutex::scoped_lock Lock(m_sessionsMutex);

	m_acceptor.close();
	for (list<session_ptr>::iterator it = m_sessions.begin(); it != m_sessions.end(); ++it)
	{
		(*it)->stop(); 
		(*it) = nullptr;
	}
	m_sessions.clear(); 

	m_io_service.stop();
	m_tg.interrupt_all();
	m_tg.join_all();

	Lock.unlock();
}

void server::send(long userID, BYTE* SendBuf, int dataLen)
{
	try
	{
		if (userID != 0)
		{
			session *pSession = (session *)userID;
			boost::mutex::scoped_lock Lock(m_sessionsMutex);
			for (list<session_ptr>::iterator it = m_sessions.begin(); it != m_sessions.end(); ++it)
			{
				if ((*it).get() == pSession)
				{
					if (pSession->bstarted() == 1)
					{
						pSession->send(SendBuf, dataLen);
					}
				}
			}
			Lock.unlock();
		}
	}
	catch (...)
	{
	}
}

bool server::stoped()
{
	return m_io_service.stopped();
}

int server::connections()
{
	boost::mutex::scoped_lock Lock(m_sessionsMutex);
	return m_sessions.size();
	Lock.unlock();
}
