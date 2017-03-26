#pragma once
#include "stdafx.h"
#include "Common.h"

void OutDebugLogs(string file, int line, string func, string log)
{
	try
	{
		char ch[256] ={ 0 };
		sprintf_s(ch, 256, "%d", line);
		string str = file + "(" + ch + "):" + func + ":" + log;
		OutputDebugStringA(str.c_str());
	}
	catch (...)
	{
	}
}