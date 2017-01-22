
// MFCDemoDlg.h : 头文件
//

#pragma once



typedef bool(*_startClientType)(char *ip, int port, IN OnReceiveCallBack callback, OUT ClientSendData& CallSendData);
typedef bool(*_stopClientType)();

// CMFCDemoDlg 对话框
class CMFCDemoDlg : public CDialogEx
{
// 构造
public:
	CMFCDemoDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFCDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL										OnInitDialog();
	afx_msg void										OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void										OnPaint();
	afx_msg HCURSOR										OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedSend();
	afx_msg void OnBnClickedStartclient();
	afx_msg void OnBnClickedStopclient();



	_startClientType _startClient;
	_stopClientType _stopClient;
};


