#pragma once


/***************************************Server*******************************************/

//************************************
// Method:    startServer
// FullName:  startServer
// Access:    public 
// Returns:   bool						True 执行成功， False 执行失败
// Qualifier:							启动服务	
// Parameter: char * ip					服务要绑定的IP 可置NULL或 ""
// Parameter: int port					服务要绑定的端口
//************************************
bool				startServer(char *ip, int port);
//************************************
// Method:    stopServer
// FullName:  stopServer
// Access:    public 
// Returns:   bool						True 执行成功， False 执行失败
// Qualifier:							停止服务
//************************************
bool				stopServer();
//************************************
// Method:    isServerStoped
// FullName:  isServerStoped
// Access:    public 
// Returns:   bool						True 已停止， False 未停止
// Qualifier:							判断服务是否停止
//************************************
bool				isServerStoped();
//************************************
// Method:    cntServerConnections
// FullName:  cntServerConnections
// Access:    public 
// Returns:   int						在线设备数量
// Qualifier:							查询当前服务端在线设备数量
//************************************
int					cntServerConnections();
//************************************
// Method:    curConnectionsStr
// FullName:  curConnectionsStr
// Access:    public 
// Returns:								const char*	ex:	bDevice:1,ip:192.168.1.107,serverip:192.168.1.107,bNormal:1,;bDevice:0,ip:192.168.1.106,serverip:192.168.1.106,bNormal:1,;
// Qualifier:							查询服务器端所有连接 状态信息
//************************************
const char*			curConnectionsStr();