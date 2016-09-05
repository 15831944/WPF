// ProcessData.h : CProcessData ������

#pragma once
#include "resource.h"       // ������



#include "DataProcess_i.h"
#include "_IProcessDataEvents_CP.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
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
		int DPIX = GetDeviceCaps(hdc, LOGPIXELSX);  //һӢ���������  һӢ��25��4����
		int DPIY = GetDeviceCaps(hdc, LOGPIXELSY);	//һӢ���������  һӢ��25��4����
		m_multiX		= DPIX / 25.4;				//һ���׶�������
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
	float							m_multiX;						//һ����������
	float							m_multiY;

	byte							m_frameInfoCatch[256];			//Ϊ���������֡��Ϣ������
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
