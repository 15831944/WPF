
// MFCDemoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCDemo.h"
#include "MFCDemoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCDemoDlg 对话框

ClientSendData g_pSendData = NULL;
long g_userID = 0;
void OnReceiveCallBack1(long userID, BYTE* buf, int len, int errorcode, const char* errormsg)
{
	g_userID = userID;
	//g_pSendData = CallSendData;
}


typedef bool(__cdecl *_startServer)(IN char *ip, IN int port, IN OnReceiveCallBack callback, OUT ServerSendData& CallSendData);
typedef bool(__cdecl *_stopServer)();
CMFCDemoDlg::CMFCDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCDemoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCDemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDB_SEND, &CMFCDemoDlg::OnBnClickedSend)
	ON_BN_CLICKED(IDB_STARTCLIENT, &CMFCDemoDlg::OnBnClickedStartclient)
	ON_BN_CLICKED(IDB_STOPCLIENT, &CMFCDemoDlg::OnBnClickedStopclient)
END_MESSAGE_MAP()


// CMFCDemoDlg 消息处理程序
_startServer startServertemp;
_stopServer stopServertemp;

BOOL CMFCDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	SetDlgItemText(IDE_IP, _T("127.0.0.1"));
	SetDlgItemText(IDE_Port, _T("60000"));



	HMODULE hNetDll					= LoadLibrary(_T("NetDll.dll"));

	 startServertemp				= (_startServer)GetProcAddress(hNetDll, "startServer");
	stopServertemp					= (_stopServer)GetProcAddress(hNetDll, "stopServer");

	ServerSendData dd;
	startServertemp("127.0.0.1", 60000, nullptr, dd);
	_startClient					= (_startClientType)GetProcAddress(hNetDll, "startClient");
	_stopClient						= (_stopClientType)GetProcAddress(hNetDll, "stopClient");

	//HMODULE hDatabase				= LoadLibrary(_T("database.dll"));
	/*_AddIDCARDAPPLY addidcardapply	= (_AddIDCARDAPPLY)GetProcAddress(hDatabase, "AddIDCARDAPPLY");
	tagIDCARDAPPLY tagidcardapply;

	tagidcardapply.name				= "1";
	tagidcardapply.gender			= "2";
	tagidcardapply.Nation			= "3";
	tagidcardapply.Birthday			= "4";
	tagidcardapply.Address			= "5";
	tagidcardapply.IdNumber			= "6";
	tagidcardapply.SigDepart		= "7";
	tagidcardapply.SLH				= "99";
	tagidcardapply.fpData			= "9";
	tagidcardapply.fpFeature		= "10";
	tagidcardapply.XCZP				= "11";
	tagidcardapply.XZQH				= "12";
	tagidcardapply.sannerId 		= "13";
	tagidcardapply.scannerName		= "14";
	tagidcardapply.legal			= false;
	tagidcardapply.operatorID		= "15";
	tagidcardapply.operatorName		= "16";
	tagidcardapply.opDate			= "17";*/

	string strError = "";
	//addidcardapply(tagidcardapply, strError);

	//vector<tagIDCARDAPPLY> array;
	//_QueryIDCARDAPPLY queryidcardapply	= (_QueryIDCARDAPPLY)GetProcAddress(hDatabase, "QueryIDCARDAPPLY");
	//queryidcardapply("select * from idcardapply", array, strError);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCDemoDlg::OnBnClickedSend()
{
	// TODO:  在此添加控件通知处理程序代码
	//if (g_pSendData != NULL)
	//{
	//	TCHAR szPath[MAX_PATH] ={ 0 };
	//	HMODULE hModule = 0;
	//	GetModuleFileName(hModule, szPath, MAX_PATH);
	//	TCHAR *pChar = _tcsrchr(szPath, _T('\\'));
	//	if (pChar)
	//		pChar[0] = _T('\0');
	//	CString path = szPath;
	//	path += _T("\\test1.xml");
	//	
	//	HANDLE hFile = ::CreateFile(path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	//	DWORD dwFileSize = GetFileSize(hFile, NULL);
	//	LPBYTE  pBuf = new BYTE[dwFileSize];
	//	DWORD readLen = 0;
	//	::ReadFile(hFile, pBuf, dwFileSize, &readLen, NULL);

	//	g_pSendData(pBuf, readLen);
	//}
	stopServertemp();
}


void CMFCDemoDlg::OnBnClickedStartclient()
{
	// TODO:  在此添加控件通知处理程序代码


	if (_startClient)
	{
		CString ipStr;
		int  port;
		GetDlgItemText(IDE_IP, ipStr);
		port = GetDlgItemInt(IDE_Port);
		_startClient(CT2A(ipStr), port, OnReceiveCallBack1, g_pSendData);
	}

}


void CMFCDemoDlg::OnBnClickedStopclient()
{
	// TODO:  在此添加控件通知处理程序代码
	if(_stopClient)
		_stopClient();
}
