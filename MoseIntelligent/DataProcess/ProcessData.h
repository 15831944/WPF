// ProcessData.h : CProcessData 的声明

#pragma once
#include "resource.h"       // 主符号



#include "DataProcess_i.h"
#include "_IProcessDataEvents_CP.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif

using namespace ATL;



// CProcessData

class ATL_NO_VTABLE CProcessData :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CProcessData, &CLSID_ProcessData>,
	public IConnectionPointContainerImpl<CProcessData>,
	public CProxy_IProcessDataEvents<CProcessData>,
	public IDispatchImpl<IProcessData, &IID_IProcessData, &LIBID_DataProcessLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CProcessData()
	{
		m_cathDataLen = 0;
		memset(m_serialCatch, 0, sizeof(m_serialCatch));
		memset(m_frameInfoCatch, 0, sizeof(m_frameInfoCatch));

		m_bThreadStop		= false;
		m_DataThreadHandle	= (HANDLE)_beginthreadex(NULL, 0, ThreadProcessData, (LPVOID)this, 0, NULL);

		HDC hdc = GetDC(NULL);
		m_screenWidth	= GetSystemMetrics(SM_CXSCREEN);
		m_screenHeight	= GetSystemMetrics(SM_CYSCREEN);
		int DPIX = GetDeviceCaps(hdc, LOGPIXELSX);  //一英寸多少像素  一英寸25。4毫米
		int DPIY = GetDeviceCaps(hdc, LOGPIXELSY);	//一英寸多少像素  一英寸25。4毫米
		m_multiX		= DPIX / 25.4;				//一毫米多少像素
		m_multiY		= DPIY / 25.4;
		ReleaseDC(NULL, hdc);
	}

	~CProcessData()
	{
		m_bThreadStop = true;
		if (m_DataThreadHandle)
		{
			DWORD ret = WaitForSingleObject(m_DataThreadHandle, 3000);
			if (ret == WAIT_TIMEOUT)
				TerminateThread(m_DataThreadHandle, 0);
			CloseHandle(m_DataThreadHandle);
		}

		for (int i = 0; i < m_dataCatchQueue.size(); ++i)
		{
			delete[] m_dataCatchQueue.front();
			m_dataCatchQueue.pop();
		}
	}
DECLARE_REGISTRY_RESOURCEID(IDR_PROCESSDATA)


BEGIN_COM_MAP(CProcessData)
	COM_INTERFACE_ENTRY(IProcessData)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CProcessData)
	CONNECTION_POINT_ENTRY(__uuidof(_IProcessDataEvents))
END_CONNECTION_POINT_MAP()


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}
protected:
	enum DataType
	{
		DATATYPE_SERIALPORT = 0
	};

	bool							m_bThreadStop;

	int								m_screenWidth;
	int								m_screenHeight;
	float							m_multiX;						//一毫米像素数
	float							m_multiY;

	byte							m_frameInfoCatch[256];			//为了提高性能帧信息缓冲区
	byte							m_serialCatch[512];
	unsigned short					m_cathDataLen;
	void							ProcessSerialData(VARIANT data);

	queue<LPBYTE>					m_dataCatchQueue;
	CCriticalSection				m_lock;
	HANDLE							m_DataThreadHandle;
	static UINT __stdcall 			ThreadProcessData(LPVOID lParam);

public:
	STDMETHOD(ProcessData)(ULONG flag, VARIANT data);
	STDMETHOD(GetProcessWorkPath32_64)(LONG processID, BSTR* path);
};

OBJECT_ENTRY_AUTO(__uuidof(ProcessData), CProcessData)
