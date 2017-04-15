#pragma once


/***************************************Server*******************************************/
bool				startServer(char *ip, int port);
bool				stopServer();
bool				isServerStoped();
int					cntServerConnections();
const char*			curConnectionsStr();

/***************************************Client*******************************************/
bool				startClient(char *ip, int port, bool bDevice);
bool				stopClient();
bool				isClientStoped();



/*****************************************************************************************/
typedef				void(__cdecl *CallBack)(
					char*	  					dataStr,
					char*	  					errorStr
					);
void				queryTable(char* QuerySql, CallBack callBack, bool bSync);
void				queryOnlieDevCnt(CallBack callBack, bool bSync);

void				addTable(char* tableName, char* dataStr, CallBack callBack, bool bSync);
void				addVersion(char* Bianhao, char* Banbenhao, LPBYTE Anzhuangbao, int datalen, CallBack callBack, bool bSync);
void				excuteSql(char* sqlStr, CallBack callBack, bool bSync);
void				upgrade(char* dataStr, CallBack callBack, bool bSync);
void				queryDevSpeed(char* ipStr, CallBack callBack, bool bSync);
void				updateClientStatus(bool bNormal, bool bSync);
void				queryConnectionsStr(CallBack callBack, bool bSync);
