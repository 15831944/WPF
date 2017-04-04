#pragma once

#include "stdafx.h"
#include "NetDll.h"

enum PackTypeEnum
{
	PackTypeEnum_heart								= 0,
	PackTypeEnum_normal								= 1,
};

#pragma pack(push, 1)
//包头
typedef struct tagPACKAGEHEAD
{
	BYTE											head1;			//0xff
	BYTE											head2;			//0xfe
	BYTE											packType;		//包类型
	bool											bcompressed;	//是否压缩
	INT												len;			//包长度
}PACKAGEHEAD;
#pragma pack(pop)

void OutDebugLineLogs(string file, int line, string func, string log);
