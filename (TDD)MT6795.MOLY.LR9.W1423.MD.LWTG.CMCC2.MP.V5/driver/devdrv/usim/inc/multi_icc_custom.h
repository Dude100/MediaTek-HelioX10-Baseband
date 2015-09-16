#ifndef __MULTI_ICC_CUSTOM_H__
#define __MULTI_ICC_CUSTOM_H__

#ifdef __GEMINI__
#ifdef GEMINI_PLUS
#define MAX_SIM_CARD_NUM (GEMINI_PLUS)
#else
#define MAX_SIM_CARD_NUM (2)
#endif // GEMINI_PLUS
#else
#define MAX_SIM_CARD_NUM (1)
#endif //  __GEMINI__


/* For sim hot plug callback function */
typedef void (*SIM_HOT_PLUG_CALLBACK)(kal_uint32 simIf);

typedef enum
{
	MTK_SIMIF0,
	MTK_SIMIF1
}SIM_hwCtrlInfo;

typedef enum
{
//	SIM_ICC_APPLICATION_PHONE1 = 0x00000001,
	SIM_ICC_APPLICATION_PHONE1 = 0x00000000, //in sim driver UT, we play a trick on this enum
	SIM_ICC_APPLICATION_PHONE2,
	SIM_ICC_APPLICATION_CMMB_SMD,
	SIM_ICC_APPLICATION_PHONE3,
	SIM_ICC_APPLICATION_PHONE4
}SIM_ICC_APPLICATION;

#define SIM_MT6302_INFO_UDF	0xff
#define SIM_ICC_MT6302_NONE	0xffffffff

typedef enum
{
	SIM_HOT_PLUG_EINT_NUMBER,
	SIM_HOT_PLUG_EINT_DEBOUNCETIME,
	SIM_HOT_PLUG_EINT_POLARITY,
	SIM_HOT_PLUG_EINT_SENSITIVITY,
	SIM_HOT_PLUG_EINT_SOCKETTYPE,
	SIM_HOT_PLUG_EINT_DEDICATEDEN,
	SIM_HOT_PLUG_EINT_SRCPIN
}SIM_hot_plug_eint_queryType;

typedef struct
{
	kal_bool polarity; /* hot swap EINT poarity */
	kal_bool removed;
	kal_bool registed;
	kal_uint32 logicalNum;
	SIM_ICC_APPLICATION application;
	kal_uint32 eintNo;
	kal_uint32 debounceTime; /* hot swap EINT debounce time */	
	kal_uint32 sensitivity;
	kal_uint32 socketType;
	SIM_HOT_PLUG_CALLBACK plugInCb;
	SIM_HOT_PLUG_CALLBACK plugOutcb;
}SIM_ICC_HOT_PLUG;

typedef struct
{
	kal_uint32 logicalNum;
	SIM_ICC_APPLICATION application;
	SIM_hwCtrlInfo hwCtrl;
	kal_uint8 needMT6302;
	kal_uint8 MT6302ChipNum; /*whip MT6302, if there are lots*/
	kal_uint8 MT6302PortNum; /*whip interface of this MT6302*/
	kal_uint8 hotSwap; /* support hot swap or not */
	kal_bool polarity; /* hot swap EINT poarity */
	kal_uint32 debounceTime; /* hot swap EINT debounce time */
} SIM_ICC_HW_SW_MAPPING;

typedef enum
{
	SIM_SWITCH_NONE,
	SIM_SWITCH_6302,
	SIM_SWITCH_6306,
	SIM_SWITCH_6314,
}SIM_ICC_SWITCHCONTROL;

typedef enum
{
   SIM_CUSTOM_T2D_GET_HOTSWAP_PROPERITY,
   SIM_CUSTOM_T2D_GET_HOTSWAP_DEBOUNDETIME,
   SIM_CUSTOM_T2D_UNKNOWN
}sim_custom_t2d;

extern kal_uint32 sim_get_ToalInterfaceCount(void);
extern void sim_dbg_print(char *fmt,...);
extern void sim_get_card_status(kal_uint32 logicalNum, kal_bool *isRemoved);
extern void sim_reg_hot_plug_cb(SIM_ICC_APPLICATION application, 
                      SIM_HOT_PLUG_CALLBACK hotPlugInCb, 
                      SIM_HOT_PLUG_CALLBACK hotPlugOutCb);
extern void sim_reg_hot_plug_eint(SIM_ICC_APPLICATION application, 
                           kal_uint32 eintNo, 
                           kal_uint32 debounceTime, 
                           kal_uint32 polarity, 
                           kal_uint32 sensitivity, 
                           kal_uint32 socketType);                      
extern kal_uint8 MT6306_getDeviceAddr(void);
extern kal_uint32 MT6306_getVIOLevel();
extern void SIM_PlugEvent_Cb(SIM_ICC_APPLICATION app);                           
#if defined(__SIM_HOT_SWAP_POLL_TIMER__) && defined(__SIM_HOT_SWAP_SUPPORT__)
extern void SIM_PlugEvent_Poll_Timer_Cb(SIM_ICC_APPLICATION app);
#endif
#endif
