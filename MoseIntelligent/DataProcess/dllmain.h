// dllmain.h : 模块类的声明。

class CDataProcessModule : public ATL::CAtlDllModuleT< CDataProcessModule >
{
public :
	DECLARE_LIBID(LIBID_DataProcessLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_DATAPROCESS, "{9124409A-1E21-4265-B7F8-972ADB2AD029}")
};

extern class CDataProcessModule _AtlModule;
