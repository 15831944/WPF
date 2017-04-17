#pragma once



/***************************************Client*******************************************/

//************************************
// Method:    startClient
// FullName:  startClient
// Access:    public 
// Returns:   bool
// Qualifier:
// Parameter: char * ip
// Parameter: int port
// Parameter: bool bDevice
//************************************
bool				startClient(char *ip, int port, bool bDevice);
//************************************
// Method:    stopClient
// FullName:  stopClient
// Access:    public 
// Returns:   bool
// Qualifier:
//************************************
bool				stopClient();
//************************************
// Method:    isClientStoped
// FullName:  isClientStoped
// Access:    public 
// Returns:   bool
// Qualifier:
//************************************
bool				isClientStoped();


//************************************
// Method:    CallBack
// FullName:  CallBack
// Access:    public 
// Returns:   void
// Qualifier: ������߳���ͨ���˻ص��������������Ϣ���ͻ�
// Parameter: 

/*
1. ÿ���������Ӧ��ֵ֮���� �� �ŷָ�
2. ����������֮���� , �ŷָ�
3. ÿ���� ; �ŷָ�
4. ������֮�����ַ�
datastr Format:

propertyName1_0:propertyValue1_0,propertyName1_1:propertyValue1_1,propertyName1_2:propertyValue1_2,����;
propertyName2_0:propertyValue2_0,propertyName2_1:propertyValue2_1,propertyName2_2:propertyValue2_2,����;
propertyName3_0:propertyValue3_0,propertyName3_1:propertyValue3_1,propertyName3_2:propertyValue3_2,����;
*/
//errorStr : ������Ϣ
//************************************
typedef				void(__cdecl *CallBack)(
	char*	  					dataStr,
	char*	  					errorStr
	);
//************************************
// Method:    queryTable
// FullName:  queryTable
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: char * QuerySql		ex:	select * from Zhiqianshuju where Xuhao>=-1
// Parameter: CallBack callBack	
//									ex:	dataStr= Xuhao:1, Chengshibianhao:0, Jubianhao:2001, Shiyongdanweibianhao:3001, ..., ; Xuhao:2, Chengshibianhao:1, Jubianhao:2002, Shiyongdanweibianhao:3002, ..., ;
//									ex:  errorStr ���ݳ����жϣ���Ϊ�ռ��д���
// Parameter: bool bWait			�Ƿ�ͬ��ִ��
//************************************
void				queryTable(char* QuerySql, CallBack callBack, bool bWait);
//************************************
// Method:    queryOnlieDevCnt
// FullName:  queryOnlieDevCnt
// Access:    public 
// Returns:   void
// Qualifier:						��ѯ��ǰ����������豸����
// Parameter: CallBack callBack		ex: dataStr= count:2,;
// Parameter: bool bWait			�Ƿ�ȴ�ִ�����
//************************************
void				queryOnlieDevCnt(CallBack callBack, bool bWait);

//************************************
// Method:    addTable
// FullName:  addTable
// Access:    public 
// Returns:   void
// Qualifier: �����ݿ��������
// Parameter: char * tableName		Ҫ������ݵ� ���� ex: Shebeiguanli
// Parameter: char * dataStr		ex:Chengshibianhao:0,Shebeimingcheng:02103963852,...,Ruanjianshengjixinxi:1,;
// Parameter: CallBack callBack		datastr=""(Ĭ��)
// Parameter: bool bWait			�Ƿ�ȴ�ִ�����
//************************************
void				addTable(char* tableName, char* dataStr, CallBack callBack, bool bWait);
//************************************
// Method:    addRuanjianbao
// FullName:  addRuanjianbao
// Access:    public 
// Returns:   void
// Qualifier: ��������
// Parameter: char * Bianhao		���
// Parameter: char * Banbenhao		�汾��
// Parameter: LPBYTE Anzhuangbao	��װ�������ƻ�����
// Parameter: int datalen			����������
// Parameter: CallBack callBack		datastr=""(Ĭ��)
// Parameter: bool bWait			�Ƿ�ȴ�ִ�����
//************************************
void				addRuanjianbao(char* Bianhao, char* Banbenhao, LPBYTE Anzhuangbao, int datalen, CallBack callBack, bool bWait);
//************************************
// Method:    excuteSql
// FullName:  excuteSql
// Access:    public 
// Returns:   void
// Qualifier: ִ��sql���
// Parameter: char * sqlStr			ex: delete from Guanliyuan where  Guanliyuan.[Xuhao]=0
// Parameter: CallBack callBack		datastr=""(Ĭ��)
// Parameter: bool bWait			�Ƿ�ȴ�ִ�����
//************************************
void				excuteSql(char* sqlStr, CallBack callBack, bool bWait);
//************************************
// Method:    queryDevSpeed
// FullName:  queryDevSpeed
// Access:    public 
// Returns:   void
// Qualifier:						����IP��ѯ��ǰ�����豸������֮�������
// Parameter: char * ipStr			ip4��ַ
// Parameter: CallBack callBack		ex:	dataStr=speed:%d,;
// Parameter: bool bWait			�Ƿ�ȴ�ִ�����
//************************************
void				queryDevSpeed(char* ipStr, CallBack callBack, bool bWait);
//************************************
// Method:    updateClientStatus
// FullName:  updateClientStatus
// Access:    public 
// Returns:   void
// Qualifier:						���µ�ǰ�ͻ��˵�״̬
// Parameter: bool bNormal			�Ƿ�������״̬ 1 ���� 0 �쳣
// Parameter: bool bWait			�Ƿ�ȴ�ִ�����
//************************************
void				updateClientStatus(bool bNormal, bool bWait);
//************************************
// Method:    queryConnectionsStr
// FullName:  queryConnectionsStr
// Access:    public 
// Returns:   void
// Qualifier:						��ѯ���������������� ״̬��Ϣ
// Parameter: CallBack callBack		ex:	dataStr= bDevice:1,ip:192.168.1.107,serverip:192.168.1.107,bNormal:1,;bDevice:0,ip:192.168.1.106,serverip:192.168.1.106,bNormal:1,;
// Parameter: bool bWait			�Ƿ�ȴ�ִ�����
//************************************
void				queryConnectionsStr(CallBack callBack, bool bWait);
//void				upgrade(char* dataStr, CallBack callBack, bool bWait);
