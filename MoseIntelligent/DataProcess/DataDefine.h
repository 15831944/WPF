
#pragma  once
#include "stdafx.h"

#define SERIALFRAME_FRAMEID_PRINT		0x00					//打印帧 自定义
#define SERIALFRAME_FRAMEID_MOVE		0x22					//鼠标位移帧
#define SERIALFRAME_FRAMEID_MIXKEY		0x80					//鼠标按键同步帧
#define SERIALFRAME_FRAMEID_ANGLE		0x25					//AIR角度帧
#define SERIALFRAME_FRAMEID_SACN		0x26					//按键扫描帧
#define SERIALFRAME_FRAMEID_SHAKE		0xFF					//握手帧


#pragma pack(push) //保存对齐状态

#pragma pack(1)//设定为4字节对齐

enum KEY_TYPE
{
	// Touch key
	KEY_TOUCH_LEFT  = 0x01,		// touch key left
	KEY_TOUCH_RIGHT = 0x02,		// touch key right
	KEY_TOUCH_MID   = 0x03,		// touch key middle
	KEY_TOUCH_UP    = 0x04,		// touch key up
	KEY_TOUCH_DOWN  = 0x05,		// touch key down

	// Real key
	KEY_PRESS_LEFT  = 0x11,		// pressed button left
	KEY_PRESS_RIGHT = 0x12,		// pressed button right
	KEY_PRESS_MID   = 0x13,		// pressed button middle
	KEY_PRESS_UP    = 0x14,		// pressed button up
	KEY_PRESS_DOWN  = 0x15		// pressed button down
}; 

//帧头
typedef struct {
	byte				ConstDataLow;			// default value is: 0xaa
	byte				ConstDataHigh;			// default value is: 0x55
	byte				FrameId;	            // frame ID
	byte				FrameCnt;				// frame counter
}SERIALFRAMEHEADER, *PSERIALFRAMEHEADER;

//鼠标位移帧
typedef struct {
	SERIALFRAMEHEADER   FrameHeader;
	// frme body
	float				AccX;					                // x direction value
	float				AccY;					                // y direction value
	float				AccZ;					                // z direction value
	USHORT				TimeStamp;		                        // current second and ms
	byte				Resv;					                // 

	byte Sum8;
}SERIALMOVEFRAME, *PSERIALMOVEFRAME;

//鼠标按键同步帧
typedef struct{
	SERIALFRAMEHEADER   FrameHeader;					//0
	// frme body
	int					UsrID;				            //4 usr id
	byte				Ctr_Alt_Shift0;					//8
	byte				Key0;							//9
	byte				Ctr_Alt_Shift1;					//10
	byte				Key1;							//11
	unsigned short		AppName;						//12
	unsigned short		RandomCode;				        //14
	byte				KeyType;				        //16 
	byte				Resv1;							//17
	byte				Sum8;							//18
}SERIALMIXKEYFRAME, *PSERIALMIXKEYFRAME;

//AIR角度帧
typedef struct{
	SERIALFRAMEHEADER	FrameHeader;					// 

	// frme body
	float				AngleX;							// x
	float				AngleY;							// y
	float				AngleZ;							// z
	unsigned short		TimeStamp_Ms;					// current ms
	byte				Resv;							// 
	byte				Sum8;
}SERIALANGLEFRAME, *PSERIALANGLEFRAME;

//按键扫描帧
typedef struct {
	SERIALFRAMEHEADER	FrameHeader;					//0 

	// frme body
	unsigned short		KeyUnion;						//4 current key value 组合
	unsigned short		KeyLastTime;					//6 key valid last time
	byte				Resv[11];						//8 
	byte				Sum8;							//19
}SERIALSACNFRAME, *PSERIALSACNFRAME;

//握手帧
typedef struct {
	SERIALFRAMEHEADER FrameHeader;	//

	// frme body
	unsigned int		UsrID;
	unsigned int		MyAirID;
	unsigned short		AirFirmwareInfo;
	unsigned short		AirHardwareInfo;
	byte				Resv0;							//19
	byte				Resv1;							//19
	byte                Sum8;
}SERIALSHAKEHANDFRAME, *PSERIALSHAKEHANDFRAME;

#pragma pack(pop)//恢复对齐状态