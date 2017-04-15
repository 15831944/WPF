#pragma once
#include "stdafx.h"
#include "Common.h"

void OutDebugLineLogs(string file, int line, string func, string log)
{
#ifdef _DEBUG
	try
	{
		char ch[256] ={ 0 };
		sprintf_s(ch, 256, "%d", line);
		string str = string("\n") + file + "(" + ch + "):" + func + ":" + log;
		OutputDebugStringA(str.c_str());
	}
	catch (...)
	{
	}

#endif
}