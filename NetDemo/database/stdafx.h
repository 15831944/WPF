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
#include <memory>
#include <vector>
#include <string>
#include <map>
using namespace std;

#include <tchar.h>
#include <stdlib.h>
#include <io.h>
#include <string>
#include "../SQLite3/sqlite3.h"

#ifdef _DEBUG
#pragma comment(lib,"../../output/SQlite3/Debug/sqlite3.lib")
#else
#pragma comment(lib,"../../output/SQlite3/Release/sqlite3.lib")
#endif

#include "ReadWriteLock.h"
#include "SqliteDataDefine.h"
#include "CommonFuntion.h"
#include "Sqlite.h"
extern string				RIM_RTK_BSD_DB_FILE;
extern CReadWriteLock		g_ReadWriteLock;				//读写锁
