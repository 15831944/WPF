// ProcessData.cpp : CProcessData 的实现

#include "stdafx.h"
#include "ProcessData.h"
#include <comutil.h>
#include <stdlib.h>
#include <comdef.h>
#include <TlHelp32.h>
// CProcessData
#include <Psapi.h>
#pragma comment( lib, "PSAPI.LIB" )

wstring ANSI2Unicode(const string & strin)
{
	wstring strout;

	// 预计算所需空间大小（已包含结束字符）,单位wchar_t
	int dwNum = MultiByteToWideChar(CP_ACP, 0, strin.c_str(), -1, 0, 0);
	wchar_t * pBuffer = new wchar_t[dwNum + 1];
	if (!pBuffer)
	{
		return strout;
	}
	memset(pBuffer, 0, (dwNum + 1)*sizeof(wchar_t));

	if (MultiByteToWideChar(CP_ACP, 0, strin.c_str(), -1, pBuffer, dwNum) >= 0)
	{
		strout = pBuffer;
	}

	delete[] pBuffer;
	return strout;
}

string DosDevicePath2LogicalPath(LPCTSTR lpszDosPath)
{
	string strResult;

	// Translate path with device name to drive letters.
	TCHAR szTemp[MAX_PATH];
	szTemp[0] = '\0';

	if (lpszDosPath == NULL || !GetLogicalDriveStrings(_countof(szTemp) - 1, szTemp)){
		return strResult;
	}


	TCHAR szName[MAX_PATH];
	TCHAR szDrive[3] = TEXT(" :");
	BOOL bFound = FALSE;
	TCHAR* p = szTemp;

	do{
		// Copy the drive letter to the template string
		*szDrive = *p;

		// Look up each device name
		if (QueryDosDevice(szDrive, szName, _countof(szName))){
			UINT uNameLen = (UINT)_tcslen(szName);

			if (uNameLen < MAX_PATH)
			{
				bFound = _tcsnicmp(lpszDosPath, szName, uNameLen) == 0;

				if (bFound){
					// Reconstruct pszFilename using szTemp
					// Replace device path with DOS path
					TCHAR szTempFile[MAX_PATH];
					_stprintf_s(szTempFile, TEXT("%s%s"), szDrive, lpszDosPath + uNameLen);
					strResult = szTempFile;
				}
			}
		}

		// Go to the next NULL character.
		while (*p++);
	} while (!bFound && *p); // end of string

	return strResult;
}
static bool ChkSum8(byte *pStartData, byte FrameLength)
{
	byte TmpData = 0;
	while (--FrameLength)
		TmpData += *pStartData++;
	return(TmpData == *pStartData);
}

static byte CalcSum8(byte *pStartData, byte FrameLength)
{
	byte TmpData = 0;
	while (--FrameLength)
		TmpData += *pStartData++;
	return TmpData;
}

STDMETHODIMP CProcessData::ProcessData(ULONG flag, VARIANT data)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: 在此添加实现代码
	if (flag == DATATYPE_SERIALPORT)
	{
		ProcessSerialData(data);
	}

	//Fire_OnProcessDataComplete(flag);
	return S_OK;
}

void CProcessData::ProcessSerialData(VARIANT data)
{
	if (data.vt & VT_ARRAY)
	{
		if (m_dataCatchQueue.size() > 10000)
		{
			return;
		}

		m_lock.Lock();
		void *pData = NULL;
		ULONG newDataLen = data.parray->rgsabound[0].cElements;

		SafeArrayAccessData(data.parray, &pData);
		LPBYTE pTotalBuf = NULL;
		pTotalBuf = new byte[newDataLen + 4];
		*((UINT*)pTotalBuf) = newDataLen;	//前4字节为BUF长度
		memcpy(pTotalBuf + 4, pData, newDataLen);
		SafeArrayUnaccessData(data.parray);

		//string printBytes = "";
		//for (int i = 0; i < newDataLen; ++i)
		//{
		//	CString str;
		//	str.Format("%.2X", *(pTotalBuf + 4 + i));
		//	printBytes += string(str.GetBuffer()) + " ";
		//}
		//OutputDebugString(printBytes.c_str());

		m_dataCatchQueue.push(pTotalBuf);
		m_lock.Unlock();
	}

}

UINT CProcessData::ThreadProcessData(LPVOID lParam)
{
	CProcessData *pThis = (CProcessData*)lParam;
	while (pThis->m_bThreadStop == false)
	{
		if (pThis->m_dataCatchQueue.size())
		{
			LPBYTE pNewBuf = NULL;
			pThis->m_lock.Lock();
			pNewBuf = pThis->m_dataCatchQueue.front();
			pThis->m_dataCatchQueue.pop();
			pThis->m_lock.Unlock();

			CString str = "";
			str.Format("\nm_dataCatchQueue.size:%d\n", pThis->m_dataCatchQueue.size());
			OutputDebugString(str);
			if (pNewBuf)
			{
				try
				{
					void *pData = pNewBuf + 4;
					ULONG newDataLen = *((UINT*)pNewBuf);


					LPBYTE pTotalBuf = NULL;
					pTotalBuf = new byte[pThis->m_cathDataLen + newDataLen];
					memcpy(pTotalBuf, pThis->m_serialCatch, pThis->m_cathDataLen);
					memcpy(pTotalBuf + pThis->m_cathDataLen, pData, newDataLen);

					int totalLen = pThis->m_cathDataLen + newDataLen;
					pThis->m_cathDataLen = 0;//缓存清空
					if (pTotalBuf == NULL)
						continue;

					int headerLen = sizeof(SERIALFRAMEHEADER);

					int aaIndex = 0;
					int index = 0;
					while (true)
					{
						if ((totalLen - index) > headerLen)                        //包含头的长度
						{
							byte bt = (byte)pTotalBuf[index];
							switch (bt)
							{
							case 0xaa:
								aaIndex = index;
								index++;                                                //取0X55//从头删到index
								break;
							case 0x55:
								index++;                                                //取0X22 ……
								break;
							case SERIALFRAME_FRAMEID_MOVE:			//位移帧
							case SERIALFRAME_FRAMEID_MIXKEY:		//同步
							case SERIALFRAME_FRAMEID_ANGLE:			//角度
							case SERIALFRAME_FRAMEID_SACN:			//按键扫描帧
							case SERIALFRAME_FRAMEID_SHAKE:			//握手帧
								if ((index - aaIndex) != 2)
								{
									index++;
									break;
								}
								else
								{
									int		frameLen	= 0;
									LPBYTE	pFrameInfo	= NULL;

									if (bt == SERIALFRAME_FRAMEID_MOVE)
										frameLen = sizeof(SERIALMOVEFRAME);
									else if (bt == SERIALFRAME_FRAMEID_MIXKEY)
										frameLen = sizeof(SERIALMIXKEYFRAME);
									else if (bt == SERIALFRAME_FRAMEID_ANGLE)
										frameLen = sizeof(SERIALANGLEFRAME);
									else if (bt == SERIALFRAME_FRAMEID_SACN)
										frameLen = sizeof(SERIALSACNFRAME);
									else if (bt == SERIALFRAME_FRAMEID_SHAKE)
										frameLen = sizeof(SERIALSHAKEHANDFRAME);


									if ((totalLen - aaIndex) >= frameLen)
									{
										pFrameInfo = pThis->m_frameInfoCatch;
										memcpy(pFrameInfo, pTotalBuf + index - 2, frameLen);
										//if (ChkSum8(pFrameInfo, frameLen) == false)
										//{
										//	index++;
										//	break;
										//}
										index = aaIndex + frameLen;                  //重新轮循


										string printBytes = "";
										for (int i = 0; i < frameLen; ++i)
										{
											CString str;
											str.Format("%.2X", *(pTotalBuf + aaIndex + i));
											printBytes += string(str.GetBuffer()) + " ";

										}


										if (bt == SERIALFRAME_FRAMEID_MOVE)
										{
											PSERIALMOVEFRAME pFrame = (PSERIALMOVEFRAME)pFrameInfo;
											CString str;
											str.Format(" AccX:%f, AccY:%f, AccZ:%f", pFrame->AccX, pFrame->AccY, pFrame->AccZ);
											printBytes += str.GetBuffer();
											POINT pt;
											GetCursorPos(&pt);
											pt.x += pFrame->AccX * 1000 * pThis->m_multiX + 0.5;
											pt.y -= pFrame->AccZ * 1000 * pThis->m_multiY + 0.5;
											if (pt.x < 0) pt.x = 0;
											if (pt.y < 0) pt.y = 0;
											if (pt.x > pThis->m_screenWidth) pt.x	= pThis->m_screenWidth;
											if (pt.y > pThis->m_screenHeight) pt.y	= pThis->m_screenHeight;
											SetCursorPos(pt.x, pt.y);
											keybd_event(65, 0, 0, 0);
											keybd_event(65, 0, KEYEVENTF_KEYUP, 0);
										}
										else
										{//处理数据
											_variant_t var;
											var.parray = SafeArrayCreateVector(VT_UI1, 0, frameLen);
											var.vt = VT_UI1|VT_ARRAY;
											void *pData = NULL;
											SafeArrayAccessData(var.parray, &pData);
											memcpy(pData, pFrameInfo, frameLen);
											SafeArrayUnaccessData(var.parray);
											pThis->Fire_OnProcessDataComplete(bt, var);
										}

										_variant_t var = printBytes.c_str();
										pThis->Fire_OnProcessDataComplete(SERIALFRAME_FRAMEID_PRINT, var);

									}
									else
									{
										if (totalLen - 1 > index)
										{
											pThis->m_cathDataLen = totalLen - aaIndex;	//保存剩下的数据
											memcpy(pThis->m_serialCatch, pTotalBuf + aaIndex, pThis->m_cathDataLen);
										}
										index = totalLen;                      //数据正确但是不完整，应该跳出去从缓冲区取数据
									}
								}
								break;
							default:
								index++;
								break;
							}
						}
						else
							break;
					}
				}
				catch (CException* e)
				{
					MessageBox(NULL, "数据处理异常", "错误", MB_OK);
				}
				delete[] pNewBuf;
			}
		}
		else
			Sleep(1);
	}
	return 0;
}


STDMETHODIMP CProcessData::GetProcessWorkPath32_64(LONG processID, BSTR* path)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  在此添加实现代码
	HANDLE hProcess;
	char temp[MAX_PATH] = {0};


	hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, processID);
	//hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, false, processID);
	if (hProcess)
	{
		GetProcessImageFileName(hProcess, temp, sizeof(temp));
		CString str = DosDevicePath2LogicalPath(temp).c_str();
		*path = str.AllocSysString();
	}
	else
		path = NULL;

	if (hProcess != INVALID_HANDLE_VALUE)
		CloseHandle(hProcess);

	return S_OK;
}

