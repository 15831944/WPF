#pragma once


/***************************************Server*******************************************/

//************************************
// Method:    startServer
// FullName:  startServer
// Access:    public 
// Returns:   bool						True ִ�гɹ��� False ִ��ʧ��
// Qualifier:							��������	
// Parameter: char * ip					����Ҫ�󶨵�IP ����NULL�� ""
// Parameter: int port					����Ҫ�󶨵Ķ˿�
//************************************
bool				startServer(char *ip, int port);
//************************************
// Method:    stopServer
// FullName:  stopServer
// Access:    public 
// Returns:   bool						True ִ�гɹ��� False ִ��ʧ��
// Qualifier:							ֹͣ����
//************************************
bool				stopServer();
//************************************
// Method:    isServerStoped
// FullName:  isServerStoped
// Access:    public 
// Returns:   bool						True ��ֹͣ�� False δֹͣ
// Qualifier:							�жϷ����Ƿ�ֹͣ
//************************************
bool				isServerStoped();
//************************************
// Method:    cntServerConnections
// FullName:  cntServerConnections
// Access:    public 
// Returns:   int						�����豸����
// Qualifier:							��ѯ��ǰ����������豸����
//************************************
int					cntServerConnections();
//************************************
// Method:    curConnectionsStr
// FullName:  curConnectionsStr
// Access:    public 
// Returns:								const char*	ex:	bDevice:1,ip:192.168.1.107,serverip:192.168.1.107,bNormal:1,;bDevice:0,ip:192.168.1.106,serverip:192.168.1.106,bNormal:1,;
// Qualifier:							��ѯ���������������� ״̬��Ϣ
//************************************
const char*			curConnectionsStr();