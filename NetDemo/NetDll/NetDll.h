

typedef				void(__cdecl *ClientSendData)(IN BYTE* SendBuf, IN int dataLen);
typedef				void(__cdecl *ServerSendData)(IN long userID, IN BYTE* SendBuf, IN int dataLen);
typedef				void(__cdecl *OnReceiveCallBack)(OUT long userID /*Only for Server*/, OUT BYTE* buf, OUT int len, OUT int errorcode, OUT const char* errormsg);

bool				startServer(IN char *ip, IN int port, IN OnReceiveCallBack callback, OUT ServerSendData& CallSendData);
bool				stopServer();
bool				isServerStoped();


bool				startClient(IN char *ip, IN int port, IN OnReceiveCallBack callback, OUT ClientSendData& CallSendData);
bool				stopClient();
bool				isClientStoped();
