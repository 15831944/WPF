#include "stdafx.h"
#include "Session.h"



session::session(boost::asio::io_service &io_service, OnReceiveCallBack pReceiveCallBack)
	: m_socket(io_service)
	, m_hearpackTimer(io_service)
	, m_pReceiveCallBack(pReceiveCallBack)
{
	m_ReadBuffer.prepare(0x1000);
	m_WriteBuffer.prepare(0x1000);
	m_heartbeatcnt						= 0;
	m_receive_totalbyte					= 0;
	m_bStarted							= false;
	m_logbase							= "";
}

session::~session()
{

}

bool session::bstarted() const
{
	return m_bStarted;
}

void session::start(bool bSendHeart)
{
	{
		char remote[256] ={ 0 };
		_itoa_s(m_socket.remote_endpoint().port(), remote, 10); 
		char local[256] ={ 0 };
		_itoa_s(m_socket.remote_endpoint().port(), local, 10);
		m_logbase = string("local:") + m_socket.local_endpoint().address().to_string() + ":" + local + "  remote:" + m_socket.remote_endpoint().address().to_string() + ":" + remote;

		string str = m_logbase + "   Connected!";
		OutDebugLineLogs(__FILE__, __LINE__, __FUNCTION__, str);
	}

	 
	m_lastdatatime		= clock();
	m_bStarted			= true;
	m_socket.async_read_some(m_ReadBuffer.prepare(4096), boost::bind(&session::receive_handler,
		this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));

	if (bSendHeart)
	{
		m_hearpackTimer.expires_from_now(boost::posix_time::seconds(5));
		m_hearpackTimer.async_wait(boost::bind(&session::heartpack_handler, this, boost::asio::placeholders::error));
	}
}

void session::heartpack_handler(const boost::system::error_code& ec)
{
	if (ec)
	{
		string str = m_logbase + "   " + ec.message();
		OutDebugLineLogs(__FILE__, __LINE__, __FUNCTION__, str);

		if (ec == boost::asio::error::basic_errors::operation_aborted)
			return;

		m_bStarted		= false;
		//if (m_pReceiveCallBack)//会话终止
		//	m_pReceiveCallBack((long)this, NULL, 0, ec.value(), ec.message().c_str());
		return;
	}

	if (!bstarted())
		return;

	if (clock() - m_lastdatatime > 10000)
	{
		sendheart();
		OutDebugLineLogs(__FILE__, __LINE__, __FUNCTION__, "heartpack_handler");
	}

	m_hearpackTimer.expires_from_now(boost::posix_time::seconds(5));
	m_hearpackTimer.async_wait(boost::bind(&session::heartpack_handler, this, boost::asio::placeholders::error));
	OutDebugLineLogs(__FILE__, __LINE__, __FUNCTION__, "heartpack_handler");
}

void session::receive_handler(const boost::system::error_code &ec, std::size_t bytes_transferred)
{
	m_lastdatatime = clock();
	if (ec)
	{
		string str = m_logbase + "   " + ec.message();
		OutDebugLineLogs(__FILE__, __LINE__, __FUNCTION__, str);

		m_bStarted		= false;
		if (m_pReceiveCallBack)//会话终止
			m_pReceiveCallBack((long)this, NULL, 0, ec.value(), ec.message().c_str());
		return;
	}

	if (!bstarted())
		return;

	{//log
		string str = m_logbase + "   ";
		m_receive_totalbyte += bytes_transferred;
		char buf[256] ={ 0 };
		_itoa_s(m_receive_totalbyte, buf, 10);
		str +=	string("  receivetotalbyte:") + buf;
		_itoa_s(bytes_transferred, buf, 10);
		str +=	string("  receivebyte:") + buf;
		OutDebugLineLogs(__FILE__, __LINE__, __FUNCTION__, str);
	}

	{
		m_ReadBuffer.commit(bytes_transferred);

		{//test
			//PACKAGEHEAD *pPackageHead = (PACKAGEHEAD *)boost::asio::buffer_cast<LPCSTR>(m_ReadBuffer.data());
			//if (m_pReceiveCallBack)
			//	m_pReceiveCallBack((long)this, ((BYTE*)pPackageHead), bytes_transferred, ec.value(), ec.message().c_str());
			//m_ReadBuffer.consume(bytes_transferred);	///删除数据
			//m_socket.async_read_some(m_ReadBuffer.prepare(4096), boost::bind(&session::receive_handler,
			//	this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
			//return;
		}

		int		packHeadLen					= sizeof(PACKAGEHEAD);
		int		curBufferLen				= m_ReadBuffer.size();
		int		leftdataLen					= 0;
		while (curBufferLen > packHeadLen) 
		{
			PACKAGEHEAD *pPackageHead = (PACKAGEHEAD *)boost::asio::buffer_cast<LPCSTR>(m_ReadBuffer.data());

			if (curBufferLen >= (packHeadLen + pPackageHead->len))
			{
				if (pPackageHead->head1 == 0xFF && pPackageHead->head2 == 0xFE)
				{
					if (pPackageHead->packType == PackTypeEnum_normal)
					{
						LPBYTE	pRealBuf	= NULL;
						DWORD	realBufLen	= 0;
						CZipData zipdata;
						if (pPackageHead->bcompressed)
							zipdata.uncompressdata(((BYTE*)pPackageHead + packHeadLen), pPackageHead->len, &pRealBuf, realBufLen);

						if (pRealBuf == NULL) pRealBuf = ((BYTE*)pPackageHead + packHeadLen);
						if (realBufLen == 0) realBufLen = pPackageHead->len;

						if (m_pReceiveCallBack)
							m_pReceiveCallBack((long)this, pRealBuf, realBufLen, ec.value(), ec.message().c_str());
						m_ReadBuffer.consume(packHeadLen + pPackageHead->len);	///删除数据
					}
					else if (pPackageHead->packType == PackTypeEnum_heart) 
					{
						OutDebugLineLogs(__FILE__, __LINE__, __FUNCTION__, "pPackageHead->packType == PackTypeEnum_heart");
						m_ReadBuffer.consume(packHeadLen + pPackageHead->len);	///删除数据
					}; 
				}
				else
				{
					string str = m_logbase + "   ";
					str +=	string("  接收数据错误！");
					OutDebugLineLogs(__FILE__, __LINE__, __FUNCTION__, str);
					//AfxMessageBox(_T("数据接收错误！"));
					m_ReadBuffer.consume(curBufferLen);	///删除数据
				}
			}
			else
			{
				leftdataLen = (pPackageHead->len + packHeadLen) - m_ReadBuffer.size();
				break;
			}

			curBufferLen				= m_ReadBuffer.size();
		}

		m_socket.async_read_some(m_ReadBuffer.prepare(leftdataLen > 4096 ? (leftdataLen + 1):4096), boost::bind(&session::receive_handler,
			this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
	}

}

void session::stop()
{
	m_hearpackTimer.cancel();
	if (!m_bStarted)
		return;
	m_bStarted=false;

	m_socket.close();
}

void session::send_handler(const boost::system::error_code &ec, const size_t bytesTransferred)
{
	m_lastdatatime = clock();

	if (ec)
	{//发送不成功的处理 
		string str = m_logbase + "   " + ec.message();
		OutDebugLineLogs(__FILE__, __LINE__, __FUNCTION__, str);

		m_bStarted = false;
		//if (m_pReceiveCallBack)//会话终止
		//	m_pReceiveCallBack((long)this, NULL, 0, ec.value(), ec.message().c_str());
		return;
	}

	if (!bstarted())
		return;

	boost::mutex::scoped_lock Lock(m_writebufMutex);
	m_WriteBuffer.consume(bytesTransferred);
	write1500();
	Lock.unlock();
}
boost::asio::ip::tcp::socket &session::socket()
{
	return m_socket;
}

void session::write1500()
{
	if (m_WriteBuffer.size() > 1500)
	{
		m_socket.async_write_some(
			boost::asio::buffer(m_WriteBuffer.data(), 1500),
			boost::bind(
			&session::send_handler,
			this,
			boost::asio::placeholders::error,
			boost::asio::placeholders::bytes_transferred
			)
			);
	}
	else if (m_WriteBuffer.size() > 0)
	{
		m_socket.async_write_some(
			boost::asio::buffer(m_WriteBuffer.data(), m_WriteBuffer.size()),
			boost::bind(
			&session::send_handler,
			this,
			boost::asio::placeholders::error,
			boost::asio::placeholders::bytes_transferred
			)
			);
	}
}

void session::sendheart()
{
	PACKAGEHEAD packHead;
	packHead.head1			= 0xff;
	packHead.head2			= 0xfe;
	packHead.packType		= PackTypeEnum_heart;
	packHead.bcompressed	= false;
	packHead.len			= 0;

	boost::mutex::scoped_lock Lock(m_writebufMutex);

	if (m_WriteBuffer.size() == 0)
	{// outstanding async_write
		m_WriteBuffer.prepare(sizeof(PACKAGEHEAD));
		m_WriteBuffer.sputn((char*)&packHead, sizeof(PACKAGEHEAD));
		write1500();
	}
	else
	{
		m_WriteBuffer.prepare(sizeof(PACKAGEHEAD));
		m_WriteBuffer.sputn((char*)&packHead, sizeof(PACKAGEHEAD));
	}
	Lock.unlock();
}

void session::send(BYTE* SendBuf, int dataLen)
{

	LPBYTE	pRealBuf	= NULL;
	DWORD	realBufLen	= 0; 

	CZipData zipdata;
	if (dataLen >= 10000)//压缩数据 
		zipdata.compressdata(SendBuf, dataLen, &pRealBuf, realBufLen);

	PACKAGEHEAD packHead;
	packHead.head1				= 0xff;
	packHead.head2				= 0xfe;
	packHead.packType			= PackTypeEnum_normal;

	if (realBufLen == 0){
		packHead.bcompressed	= false;
		pRealBuf				= SendBuf; 
		realBufLen				= dataLen;
	}
	else
		packHead.bcompressed	= true;
	packHead.len				= realBufLen;

	boost::mutex::scoped_lock Lock(m_writebufMutex);

	if (m_WriteBuffer.size() == 0)
	{// outstanding async_write

		m_WriteBuffer.prepare(realBufLen + sizeof(PACKAGEHEAD));
		m_WriteBuffer.sputn((char*)&packHead, sizeof(PACKAGEHEAD));
		m_WriteBuffer.sputn((char*)pRealBuf, realBufLen);
		write1500();
	}
	else
	{
		m_WriteBuffer.prepare(realBufLen + sizeof(PACKAGEHEAD));
		m_WriteBuffer.sputn((char*)&packHead, sizeof(PACKAGEHEAD));
		m_WriteBuffer.sputn((char*)pRealBuf, realBufLen);
	}
	Lock.unlock();
}


