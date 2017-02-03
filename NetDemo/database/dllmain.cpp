// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "stdafx.h"

string RIM_RTK_BSD_DB_FILE = "";
BOOL APIENTRY DllMain(HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	{
		//char szPath[MAX_PATH] ={ 0 };
		//GetModuleFileNameA(hModule, szPath, MAX_PATH);
		//*(strrchr(szPath, '\\')) = NULL;
		//*(strrchr(szPath, '\\')) = NULL;
		//RIM_RTK_BSD_DB_FILE = szPath;
		//RIM_RTK_BSD_DB_FILE += "\\data\\BOSD.SDB";

		RIM_RTK_BSD_DB_FILE = "e:\\gitcode\\zhangyong\\WPF\\NetDemo\\设计资料\\test.db";
	}
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

