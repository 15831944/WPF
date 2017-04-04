// stdafx.cpp : 只包括标准包含文件的源文件
// workdll.pch 将作为预编译头
// stdafx.obj 将包含预编译类型信息

#include "stdafx.h"

// TODO:  在 STDAFX.H 中
// 引用任何所需的附加头文件，而不是在此文件中引用

void OutDebugLineLogs(string file, int line, string func, string log)
{
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
}
bool GetAvalibleIpAddress(vector<string> &ipArray)
{
	ipArray.clear();

	// 	CStringArray ipAddresses;

	ULONG ulTalbeSize = 0;
	DWORD res = ::GetIpAddrTable(NULL, &ulTalbeSize, TRUE);
	MIB_IPADDRTABLE *pIpAddTalbe = (MIB_IPADDRTABLE*)new BYTE[ulTalbeSize];
	DWORD ret = ::GetIpAddrTable(pIpAddTalbe, &ulTalbeSize, TRUE);
	if (NO_ERROR == ret)
	{
		DWORD ipAddress = 0;
		for (UINT i = 0; i < pIpAddTalbe->dwNumEntries; i++)
		{
			ipAddress = pIpAddTalbe->table[i].dwAddr;
			if (0 == ipAddress)
				continue;

			// 			ipAddresses.Add(Dword2IpString(pIpAddTalbe->table[i].dwAddr));
			// MIB_IPADDRROW has a dwBCastAddr member but docs say it is broken (and it is!)
			// addr | ~mask = broadcast
			//ipAddress |= ~(pIpAddTalbe->table[i].dwMask);

			ipAddress = ntohl(ipAddress);

			char ch[MAX_PATH] ={ 0 };
			sprintf_s(ch, MAX_PATH, "%d.%d.%d.%d",
				(ipAddress>>24)&0x000000ff,
				(ipAddress>>16)&0x000000ff,
				(ipAddress>>8)&0x000000ff,
				ipAddress&0x000000ff);

			ipArray.push_back(ch);
		}

		if (pIpAddTalbe)
			delete[] pIpAddTalbe;
		pIpAddTalbe = NULL;

		return true;
	}
	else{

		if (pIpAddTalbe)
			delete[] pIpAddTalbe;
		pIpAddTalbe = NULL;
		return false;
	}
}