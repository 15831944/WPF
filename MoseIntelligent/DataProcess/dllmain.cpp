// dllmain.cpp : DllMain 的实现。

#include "stdafx.h"
#include "resource.h"
#include "DataProcess_i.h"
#include "dllmain.h"
#include "xdlldata.h"

CDataProcessModule _AtlModule;

class CDataProcessApp : public CWinApp
{
public:

// 重写
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CDataProcessApp, CWinApp)
END_MESSAGE_MAP()

CDataProcessApp theApp;

BOOL CDataProcessApp::InitInstance()
{
#ifdef _MERGE_PROXYSTUB
	if (!PrxDllMain(m_hInstance, DLL_PROCESS_ATTACH, NULL))
		return FALSE;
#endif
	return CWinApp::InitInstance();
}

int CDataProcessApp::ExitInstance()
{
	return CWinApp::ExitInstance();
}
