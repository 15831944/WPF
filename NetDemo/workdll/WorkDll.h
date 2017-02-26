#pragma once


/***************************************Server*******************************************/
bool				startServer(char *ip, int port);
bool				stopServer();
bool				isServerStoped();



/***************************************Client*******************************************/
bool				startClient(char *ip, int port);
bool				stopClient();
bool				isClientStoped();

typedef				void(__cdecl *QueryTableCallBack)(
					char*	  					dataStr
					);
void				queryTable(char* QuerySql, QueryTableCallBack callBack);


typedef				void(__cdecl *AddDataCallBack)(
	char*			strError
	);

void				addTable(char* tableName, char* dataStr, AddDataCallBack callBack);

void addZHIQIANSHUJU(
	int 						Xuhao,
	int							Chengshibianhao,
	int							Jubianhao,
	int							Shiyongdanweibianhao,
	int							IP,
	bool						Bendiyewu,
	int							Shebeibaifangweizhi,
	__int64						Riqi,
	char*	  					Yewubianhao,
	char*	  					YuanZhengjianhaoma,
	char*	  					Xingming,
	int	  						Qianzhuzhonglei,
	int	  						ZhikaZhuangtai,
	char*	  					Zhengjianhaoma,
	char*	  					Jiekoufanhuijieguo,
	char*	  					Lianxidianhua,
	AddDataCallBack				callBack
	);

void    addSHOUZHENGSHUJU(
	int							Xuhao,
	int							Chengshibianhao,
	int							Jubianhao,
	int							Shiyongdanweibianhao,
	int							IP,
	bool						Bendiyewu,
	int							Shebeibaifangweizhi,
	__int64						Riqi,
	int							Zhengjianleixing,
	char*						Zhengjianhaoma,
	char*						Xingming,
	char*						Shoulibianhao,
	bool						Shifoujiaofei,
	AddDataCallBack				callBack
	);

void    addQIANZHUSHUJU(
	int							Xuhao,
	int							Chengshibianhao,
	int							Jubianhao,
	int							Shiyongdanweibianhao,
	int							IP,
	bool						Bendiyewu,
	int							Shebeibaifangweizhi,
	__int64						Riqi,
	char*						YuanZhengjianhaoma,
	char*						Xingming,
	int							Xingbie,
	__int64						Chushengriqi,
	char*						Lianxidianhua,
	int							Yewuleixing,
	char*						Shouliren,
	AddDataCallBack				callBack
	);
void    addJIAOKUANSHUJU(
	int							Xuhao,
	int							Chengshibianhao,
	int							Jubianhao,
	int							Shiyongdanweibianhao,
	int							IP,
	bool						Bendiyewu,
	int							Shebeibaifangweizhi,
	__int64						Riqi,
	char*						Zhishoudanweidaima,
	char*						Jiaokuantongzhishuhaoma,
	char*						Jiaokuanrenxingming,
	float						Yingkoukuanheji,
	__int64						Jiaoyiriqi,
	AddDataCallBack				callBack
	);
void    addCHAXUNSHUJU(
	int							Xuhao,
	int		  					Chengshibianhao,
	int		  					Jubianhao,
	int		  					Shiyongdanweibianhao,
	int		  					IP,
	bool						Bendiyewu,
	int							Shebeibaifangweizhi,
	__int64						Riqi,
	char*						Chaxunhaoma,
	char*						Chaxunleixing,
	bool						Shifouchaxunchenggong,
	__int64						Chuangjianshijian,
	AddDataCallBack				callBack
	);
void    addYUSHOULISHUJU(
	int							Xuhao,
	int		  					Chengshibianhao,
	int		  					Jubianhao,
	int		  					Shiyongdanweibianhao,
	int		  					IP,
	bool	  					Bendiyewu,
	int		  					Shebeibaifangweizhi,
	__int64		  				Riqi,
	char*	  					Yewubianhao,
	char*	  					Xingming,
	char*	  					Lianxidianhua,
	char*	  					Chuguoshiyou,
	char*  						YuanZhengjianhaoma,
	int		  					Qianzhuzhonglei,
	int		  					Xingbie,
	char*	  					Hukousuozaidi,
	char*	  					Minzu,
	__int64  					Chuangjianshijian,
	AddDataCallBack				callBack
	);
void    addSHEBEIZHUANGTAI(
	int							Xuhao,
	int							Chengshibianhao,
	int							Jubianhao,
	int							Shiyongdanweibianhao,
	int							IP,
	bool						Bendiyewu,
	int							Shebeibaifangweizhi,
	__int64						Riqi,
	bool						Shifouzaixian,
	AddDataCallBack				callBack
	);
void    addSHEBEIYICHANGSHUJU(
	int							Xuhao,
	int		  					Chengshibianhao,
	int		  					Jubianhao,
	int		  					Shiyongdanweibianhao,
	int		  					IP,
	bool	  					Bendiyewu,
	int							Shebeibaifangweizhi,
	__int64						Riqi,
	char*						Yichangshejimokuai,
	char*						Yichangyuanyin,
	char*						Yichangxiangxineirong,
	AddDataCallBack				callBack
	);
void    addGUANLIYUAN(
	int  						Xuhao,
	char*  						Yonghuming,
	char*  						Mima,
	int  						Youxiaoqikaishi,
	int  						Youxiaoqijieshu,
	int  						Quanxianjibie,
	AddDataCallBack				callBack
	);
void    addGUANLIYUANCAOZUOJILU(
	int  						Xuhao,
	char*  						Yonghuming,
	__int64  					Riqi,
	char*  						Caozuoleibie,
	char*  						Caozuoneirong,
	AddDataCallBack				callBack
	);
void    addSHEBEIGUANLI(
	int							Xuhao,
	int							Chengshibianhao,
	int							Jubianhao,
	int							Shiyongdanweibianhao,
	int							IP,
	char*						Shebeichangjia,
	char*						Shebeimingcheng,
	char*						Shebeileixing,
	float						Jingdu,
	float						Weidu,
	__int64						Chuangjianshijian,
	AddDataCallBack				callBack
	);
void    addYINGSHEBIAO(
	int							Bianhao,
	char*						Mingcheng,
	AddDataCallBack				callBack
	);
