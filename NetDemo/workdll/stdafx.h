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
#include <fstream>

#include "../NetDll/NetDll.h"
#include "../database/database.h"
#include "netmsg.pb.h"

#include <WinSock2.h>
#include <IPHlpApi.h>
#pragma comment(lib, "wsock32.lib")
#pragma comment(lib, "Iphlpapi.lib")


bool		GetAvalibleIpAddress(vector<string> &ipArray);
void		OutDebugLineLogs(string file, int line, string func, string log);
void		split(const string& str, vector<string>& ret_, string sep = ",");
void		Base64_Encode(unsigned char* src, unsigned char* dest, int srclen);
void		Base64_Decode(unsigned char* src, unsigned char* dest, int srclen);
int			GetEncodeNewLen(const char * src);
int			GetDecodeNewLen(const char* src);