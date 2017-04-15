// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             //  从 Windows 头文件中排除极少使用的信息
// Windows 头文件: 
#include <windows.h>



// TODO:  在此处引用程序需要的其他头文件

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