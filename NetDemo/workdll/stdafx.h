// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             //  �� Windows ͷ�ļ����ų�����ʹ�õ���Ϣ
// Windows ͷ�ļ�: 
#include <windows.h>



// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�

#ifdef _DEBUG
#pragma comment( lib, "libprotobuf_MDd.lib" )
#else
#pragma comment( lib, "libprotobuf_MT.lib" )
#endif

#include <tchar.h>
#include <queue>

#include "../NetDll/NetDll.h"
#include "../database/database.h"
#include "netmsg.pb.h"

#include <WinSock2.h>
#include <imagehlp.h>
#include <IPHlpApi.h>
#pragma comment(lib, "wsock32.lib")
#pragma comment(lib, "imagehlp.lib")
#pragma comment(lib, "Iphlpapi.lib")


bool		GetAvalibleIpAddress(vector<string> &ipArray);
void		OutDebugLineLogs(string file, int line, string func, string log);
