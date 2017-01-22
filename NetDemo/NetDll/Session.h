#pragma once
#include "Common.h"
#include "NetDll.h"

class session : public boost::enable_shared_from_this<session>
{
public:
	session(boost::asio::io_service &io_service, OnReceiveCallBack pReceiveCallBack);
	~session();

private:
	clock_t											m_lastdatatime;
	boost::asio::deadline_timer						m_hearpackTimer;
	boost::asio::ip::tcp::socket					m_socket;
	boost::asio::streambuf							m_ReadBuffer;
	boost::asio::streambuf							m_WriteBuffer;
	boost::mutex									m_writebufMutex;				
	bool											m_bStarted;
	int												m_heartbeatcnt;
	int												m_receive_totalbyte;
	string											m_logbase;
	OnReceiveCallBack								m_pReceiveCallBack;


	void											heartpack_handler(const boost::system::error_code& ec);
	void											send_handler(const boost::system::error_code &ec, const size_t bytesTransferred);
	void											receive_handler(const boost::system::error_code &ec, std::size_t bytes_transferred);
	void											write1500();

public:
	boost::asio::ip::tcp::socket &					socket();
	bool											bstarted() const;

	void											start();
	void											stop();
	void											send(BYTE* SendBuf, int dataLen);
};
typedef boost::shared_ptr<session> session_ptr;