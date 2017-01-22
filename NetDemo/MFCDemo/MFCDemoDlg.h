
// MFCDemoDlg.h : ͷ�ļ�
//

#pragma once



typedef bool(*_startClientType)(char *ip, int port, IN OnReceiveCallBack callback, OUT ClientSendData& CallSendData);
typedef bool(*_stopClientType)();

// CMFCDemoDlg �Ի���
class CMFCDemoDlg : public CDialogEx
{
// ����
public:
	CMFCDemoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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


