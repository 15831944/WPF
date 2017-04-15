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

void split(const string& str, vector<string>& ret_, string sep/* = ","*/)
{
	if (str.empty())
	{
		return;
	}

	string tmp;
	string::size_type pos_begin = str.find_first_not_of(sep);
	string::size_type comma_pos = 0;

	while (pos_begin != string::npos)
	{
		comma_pos = str.find(sep, pos_begin);
		if (comma_pos != string::npos)
		{
			tmp = str.substr(pos_begin, comma_pos - pos_begin);
			pos_begin = comma_pos + sep.length();
		}
		else
		{
			tmp = str.substr(pos_begin);
			pos_begin = comma_pos;
		}

		if (!tmp.empty())
		{
			ret_.push_back(tmp);
			tmp.clear();
		}
	}

	return;
}

unsigned char EncodeIndex[] =
{//编码索引表
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
	'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
	'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
	'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/', '='
};
//解码字母在数组中的序号       A]0(0x00)                 a]26(0x1A)                0]52(0x34) +]62(0x3E) /]63(0x3F) =]64(0x40)
unsigned char Base64Code[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
unsigned char DecodeIndex[] =
{//解码索引表
	0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,//0  00-15
	0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,//1  16-31
	0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x3E, 0x40, 0x40, 0x40, 0x3F,//2  32-47    43[+](0x38)  47[/](0x39)
	0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,//3  48-63    48[0](0x34)- 57[9](0x3D)  61[=](0x40)
	0x40, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E,//4  64-79    65[A](0x00)- 79[O](0x0E)
	0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x40, 0x40, 0x40, 0x40, 0x40,//5  80-95    80[P](0x0F)- 90[Z](0x19)
	0x40, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28,//6  96-111   97[a](0x1A)-111[o](0x28)
	0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 0x30, 0x31, 0x32, 0x33, 0x40, 0x40, 0x40, 0x40, 0x40 //7 112-127  122[p](0x29)-122[z](0x33)
};
//转换前 aaaaaabb ccccdddd eeffffff
//转换后 00aaaaaa 00bbcccc 00ddddee 00ffffff
//方式1,每个字符通过查找太浪费时间

void Base64_Encode(unsigned char* src, unsigned char* dest, int srclen)
{//编码函数
	int sign = 0;
	for (int i = 0; i!= srclen; i++, src++, dest++)
	{
		switch (sign)
		{
			case 0://编码第1字节
				*(dest) = EncodeIndex[*src >> 2];
				break;
			case 1://编码第2字节
				*dest = EncodeIndex[((*(src-1)  & 0x03) << 4) | (((*src) & 0xF0) >> 4)];
				break;
			case 2://编码第3字节
				*dest = EncodeIndex[((*(src-1) &0x0F) << 2) | ((*(src)& 0xC0) >> 6)];
				*(++dest) = EncodeIndex[(*(src)&0x3F)];//编码第4字节
				break;
		}
		(sign == 2)?(sign = 0):(sign++);
	}

	switch (sign)
	{//3的余数字节，后补=处理
		case 0:
			break;
		case 1:
			// *(dest++) = EncodeIndex[((*(src-1)  & 0x03) << 4) | (((*src) & 0xF0) >> 4)];
			*(dest++) = EncodeIndex[((*(src-1)  & 0x03) << 4)];
			*(dest++) = '=';
			*(dest++) = '=';
			break;
		case 2:
			// *(dest++) = EncodeIndex[((*(src-1) &0x0F) << 2) | ((*(src) & 0xC0) >> 6)];
			*(dest++) = EncodeIndex[((*(src-1) &0x0F) << 2)];
			*(dest++) = '=';
			break;
		default:
			break;
	}
}
//方式2比较好,通过数组直接得到其值,比较快
void Base64_Decode(unsigned char* src, unsigned char* dest, int srclen)
{//解码处理函数 //len%4 == 0总为true;
	for (int i = 0; i != srclen/4; i++)//对于不足4个的不作计算
	{//每个字符,通过数组直接得到其值,比较快
		*dest = (DecodeIndex[*src] << 2) | ((DecodeIndex[*(src+1)] & 0x30) >> 4);
		*(dest+1) = (DecodeIndex[*(src+1)] << 4) | ((DecodeIndex[*(src+2)] &0x3C) >> 2);
		*(dest+2) = ((DecodeIndex[*(src+2)] & 0x03) << 6) | (DecodeIndex[*(src+3)] & 0x3F);
		src += 4;
		dest += 3;
	}
}

//*/
int GetEncodeNewLen(const char * src)
{//求编码后的长度
	int len = strlen((char*)src);
	return (len +(len%3 == 0? 0:(3-len%3)))/3*4 + 1;
}
int GetDecodeNewLen(const char* src)
{//求解码后的长度
	int len = strlen(src);
	return len/4*3+1;
}