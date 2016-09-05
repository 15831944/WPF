// FrameCreator.h : CFrameCreator ������

#pragma once
#include "resource.h"       // ������



#include "DataProcess_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;


// CFrameCreator

class ATL_NO_VTABLE CFrameCreator :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CFrameCreator, &CLSID_FrameCreator>,
	public IDispatchImpl<IFrameCreator, &IID_IFrameCreator, &LIBID_DataProcessLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CFrameCreator()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_FRAMECREATOR)


BEGIN_COM_MAP(CFrameCreator)
	COM_INTERFACE_ENTRY(IFrameCreator)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:



};

OBJECT_ENTRY_AUTO(__uuidof(FrameCreator), CFrameCreator)
