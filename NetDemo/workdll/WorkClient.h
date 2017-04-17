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
// Qualifier: 在随机线程中通过此回调函数返回相关信息给客户
// Parameter: 

/*
1. 每个属性与对应的值之间以 ： 号分隔
2. 属性与属性之间以 , 号分隔
3. 每行以 ; 号分隔
4. 行与行之间无字符
datastr Format:

propertyName1_0:propertyValue1_0,propertyName1_1:propertyValue1_1,propertyName1_2:propertyValue1_2,……;
propertyName2_0:propertyValue2_0,propertyName2_1:propertyValue2_1,propertyName2_2:propertyValue2_2,……;
propertyName3_0:propertyValue3_0,propertyName3_1:propertyValue3_1,propertyName3_2:propertyValue3_2,……;
*/
//errorStr : 错误信息
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
//									ex:  errorStr 根据长度判断，不为空即有错误
// Parameter: bool bWait			是否同步执行
//************************************
void				queryTable(char* QuerySql, CallBack callBack, bool bWait);
//************************************
// Method:    queryOnlieDevCnt
// FullName:  queryOnlieDevCnt
// Access:    public 
// Returns:   void
// Qualifier:						查询当前服务端在线设备数量
// Parameter: CallBack callBack		ex: dataStr= count:2,;
// Parameter: bool bWait			是否等待执行完成
//************************************
void				queryOnlieDevCnt(CallBack callBack, bool bWait);

//************************************
// Method:    addTable
// FullName:  addTable
// Access:    public 
// Returns:   void
// Qualifier: 向数据库插入数据
// Parameter: char * tableName		要添加数据的 表名 ex: Shebeiguanli
// Parameter: char * dataStr		ex:Chengshibianhao:0,Shebeimingcheng:02103963852,...,Ruanjianshengjixinxi:1,;
// Parameter: CallBack callBack		datastr=""(默认)
// Parameter: bool bWait			是否等待执行完成
//************************************
void				addTable(char* tableName, char* dataStr, CallBack callBack, bool bWait);
//************************************
// Method:    addRuanjianbao
// FullName:  addRuanjianbao
// Access:    public 
// Returns:   void
// Qualifier: 添加软件包
// Parameter: char * Bianhao		编号
// Parameter: char * Banbenhao		版本号
// Parameter: LPBYTE Anzhuangbao	安装包二进制缓存区
// Parameter: int datalen			缓存区长度
// Parameter: CallBack callBack		datastr=""(默认)
// Parameter: bool bWait			是否等待执行完成
//************************************
void				addRuanjianbao(char* Bianhao, char* Banbenhao, LPBYTE Anzhuangbao, int datalen, CallBack callBack, bool bWait);
//************************************
// Method:    excuteSql
// FullName:  excuteSql
// Access:    public 
// Returns:   void
// Qualifier: 执行sql语句
// Parameter: char * sqlStr			ex: delete from Guanliyuan where  Guanliyuan.[Xuhao]=0
// Parameter: CallBack callBack		datastr=""(默认)
// Parameter: bool bWait			是否等待执行完成
//************************************
void				excuteSql(char* sqlStr, CallBack callBack, bool bWait);
//************************************
// Method:    queryDevSpeed
// FullName:  queryDevSpeed
// Access:    public 
// Returns:   void
// Qualifier:						根据IP查询当前在线设备与服务端之间的网速
// Parameter: char * ipStr			ip4地址
// Parameter: CallBack callBack		ex:	dataStr=speed:%d,;
// Parameter: bool bWait			是否等待执行完成
//************************************
void				queryDevSpeed(char* ipStr, CallBack callBack, bool bWait);
//************************************
// Method:    updateClientStatus
// FullName:  updateClientStatus
// Access:    public 
// Returns:   void
// Qualifier:						更新当前客户端的状态
// Parameter: bool bNormal			是否是正常状态 1 正常 0 异常
// Parameter: bool bWait			是否等待执行完成
//************************************
void				updateClientStatus(bool bNormal, bool bWait);
//************************************
// Method:    queryConnectionsStr
// FullName:  queryConnectionsStr
// Access:    public 
// Returns:   void
// Qualifier:						查询服务器端所有连接 状态信息
// Parameter: CallBack callBack		ex:	dataStr= bDevice:1,ip:192.168.1.107,serverip:192.168.1.107,bNormal:1,;bDevice:0,ip:192.168.1.106,serverip:192.168.1.106,bNormal:1,;
// Parameter: bool bWait			是否等待执行完成
//************************************
void				queryConnectionsStr(CallBack callBack, bool bWait);
//void				upgrade(char* dataStr, CallBack callBack, bool bWait);
