/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   dcl_rtc.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file of DCL (Driver Common Layer) for RTC.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef DCL_DEFINITION_STRUCT
#ifndef __DCL_RTC_H_STRUCT__
#define __DCL_RTC_H_STRUCT__

/*******************************************************************************
 * DCL_OPTIONS for RTC
 *******************************************************************************/
#define RTC_OPTIONS

 /*******************************************************************************
 * DCL_CONFIGURE_T for RTC
 *******************************************************************************/
#define RTC_CONFIGS

/*******************************************************************************
 * DCL_EVENT for RTC
 *******************************************************************************/
#define RTC_EVENTS \
    EVENT_RTC_ALARM =           0x00000001,\
    EVENT_RTC_TC    =           0x00000002,

/*******************************************************************************
 * DCL_CTRL_CMD for RTC
 *******************************************************************************/
#ifdef __BUILD_DOM__
/* The RTC Command Values in DCL_CTRL_CMD_T Enum of dcl.h */
typedef enum {
    RTC_CMD_BOOTLOADER_POWERON, /* For RTC Bootloader Power On */
    RTC_CMD_CLEAR_PDN_BITS, /* To Clear RTC PDN Bits */
    RTC_CMD_CONFIG_AL_TC, /* To Configure the RTC Interrupt */
    RTC_CMD_DELAY, /* To Delay */
    RTC_CMD_FT_POWEROFF, /* For Flash Tool Power Off */
    RTC_CMD_GET_ALARM_TIME, /* To Get Alarm Time */
    RTC_CMD_GET_TIME, /* To Get Time*/
    RTC_CMD_GPIO_GET_INPUT, /* To Get GPIO Input */
    RTC_CMD_GPIO_SET_EXPORT_32K, /* To Set Export 32K for GPIO */
    RTC_CMD_GPIO_SET_EXPORT_COREDETB, /* To Set Export COREDETB  for GPIO */
    RTC_CMD_GPIO_SET_INPUT_MODE, /* To Set GPIO Input Mode */
    RTC_CMD_GPIO_SET_OUTPUT_MODE, /* To Set GPIO Output Mode */
    RTC_CMD_HW_INIT, /* To Initialize RTC HW */
    RTC_CMD_INIT, /* To Initialize RTC SW */
    RTC_CMD_INIT_TC_AL_INTR, /* To Initialize RTC SW (RTC_TCintr,RTC_ALintr) */
    RTC_CMD_IS_CONFIG_VALID, /* To Check If RTC Configure Valid or Not */
    RTC_CMD_IS_FIRST_ON, /* To Check If RTC Is First On or Not */
    RTC_CMD_IS_MS_FIRSTPOWERON, /* To Check If RTC Is First On or Not (for MMI Only) */
    RTC_CMD_IS_TIME_VALID, /* To Check If RTC Time Is Valid or Not */
    RTC_CMD_PWIC_CHECK_POWERON, /* To Check RTC Power On (for PWIC Only) */
    RTC_CMD_PWIC_FIRST_POWERON_INIT_RTCTIME, /* To Initialize RTC Time When First Power On (for PWIC Only) */
    RTC_CMD_PWIC_MASK_AL, /* To Diable All Alarm Mask (for PWIC Only) */
    RTC_CMD_PWIC_POWEROFF_RTC_INIT, /* To Do RTC Initalize When Power Off (for PWIC Only) */
    RTC_CMD_PWIC_POWERON_RTC_INIT, /* To Do RTC Initalize When Power On (for PWIC Only) */
    RTC_CMD_READ_PDN_BITS, /* To Read RTC PDN Bits */
    RTC_CMD_READ_SPAR, /* To Read SPAR Register */
    RTC_CMD_READ_XOSC_REG, /* To Read RTC XOSC Register */
    RTC_CMD_RELOAD, /* To Do RTC Reload */
    RTC_CMD_SET_ALARM_TIME, /* To Set Alarm Time */
    RTC_CMD_SET_FIRST_POWERON, /* To Set First Power On */
    RTC_CMD_SET_PDN_BITS, /* To Set RTC PDN Bits */
    RTC_CMD_SET_PWR_KEY, /* To Set Power Key */
    RTC_CMD_SET_TIME, /* To Set Time */
    RTC_CMD_SETBBPU, /* To Set BBPU */
    RTC_CMD_SETXOSC, /* To Set XOSC */
    RTC_CMD_START_CALI, /* To Start Calibration */
    RTC_CMD_WAIT_DEBOUNCE, /* To Wait De-bounce */
    RTC_CMD_WRITE_PDN_BITS, /* To Write RTC PDN Bits */
    RTC_CMD_WRITE_SPAR, /* To Write SPAR Register */    
    RTC_CMD_WRITE_TRIGGER, /* To Set Write Trigger */
    RTC_CMD_WRITE_TRIGGER_WAIT, /* To Set Write Trigger And Wait */
    RTC_CMD_WRITE_XOSC_REG, /* To Write RTC XOSC Register */
    RTC_CMD_PROT_UNLOCK, /* To Unlock RTC PROT */
    RTC_CMD_REGISTER_MODULE_TO_SEND_RTCTIME, /* To register ilm infomation by other modules to request RTC time */
    RTC_CMD_WRITE_OSC32CON_REG, /* To Write RTC OSC32CON Register */
} DCL_CTRL_CMD_T;
#else /* __BUILD_DOM__ */
#define RTC_CMDS \
    RTC_CMD_BOOTLOADER_POWERON, \
    RTC_CMD_CLEAR_PDN_BITS, \
    RTC_CMD_CONFIG_AL_TC, \
    RTC_CMD_DELAY, \
    RTC_CMD_FT_POWEROFF, \
    RTC_CMD_GET_ALARM_TIME, \
    RTC_CMD_GET_TIME, \
    RTC_CMD_GPIO_GET_INPUT, \
    RTC_CMD_GPIO_SET_EXPORT_32K, \
    RTC_CMD_GPIO_SET_EXPORT_COREDETB, \
    RTC_CMD_GPIO_SET_INPUT_MODE, \
    RTC_CMD_GPIO_SET_OUTPUT_MODE, \
    RTC_CMD_HW_INIT, \
    RTC_CMD_INIT, \
    RTC_CMD_INIT_TC_AL_INTR, \
    RTC_CMD_IS_CONFIG_VALID,\
    RTC_CMD_IS_FIRST_ON, \
    RTC_CMD_IS_MS_FIRSTPOWERON, \
    RTC_CMD_IS_TIME_VALID, \
    RTC_CMD_PWIC_CHECK_POWERON, \
    RTC_CMD_PWIC_FIRST_POWERON_INIT_RTCTIME, \
    RTC_CMD_PWIC_MASK_AL, \
    RTC_CMD_PWIC_POWEROFF_RTC_INIT, \
    RTC_CMD_PWIC_POWERON_RTC_INIT, \
    RTC_CMD_READ_PDN_BITS, \
    RTC_CMD_READ_SPAR, \
    RTC_CMD_READ_XOSC_REG, \
    RTC_CMD_RELOAD, \
    RTC_CMD_SET_ALARM_TIME, \
    RTC_CMD_SET_FIRST_POWERON, \
    RTC_CMD_SET_PDN_BITS, \
    RTC_CMD_SET_PWR_KEY, \
    RTC_CMD_SET_TIME, \
    RTC_CMD_SETBBPU, \
    RTC_CMD_SETXOSC, \
    RTC_CMD_START_CALI, \
    RTC_CMD_WAIT_DEBOUNCE, \
    RTC_CMD_WRITE_PDN_BITS, \
    RTC_CMD_WRITE_SPAR, \
    RTC_CMD_WRITE_TRIGGER, \
    RTC_CMD_WRITE_TRIGGER_WAIT, \
    RTC_CMD_WRITE_XOSC_REG, \
    RTC_CMD_PROT_UNLOCK, \
    RTC_CMD_REGISTER_MODULE_TO_SEND_RTCTIME, \
    RTC_CMD_WRITE_OSC32CON_REG,
#endif /* __BUILD_DOM__ */

/*******************************************************************************
 * Define the Data and Time Interrupt Control Bit
 *******************************************************************************/
 
/* Y:Year, M:Month, W:DOW, D:DOM, H:Hour, M:Min, S:SEC */

/* Alarm Enable None */
#define AL_EN_None		               0
/* Alarm Enable Check Sec */
#define AL_EN_ChkS                     1 
/* Alarm Enable Check Min & Sec */
#define AL_EN_ChkMS                    2
/* Alarm Enable Check Hour, Min & Sec */
#define AL_EN_ChkHMS                   3
/* Alarm Enable Check DOM, Hour, Min & Sec */
#define AL_EN_ChkDHMS                  4 
/* Alarm Enable Check DOW, Hour, Min & Sec */
#define AL_EN_ChkWHMS                  5
/* Alarm Enable Check Month, DOM, Hour, Min & Sec */
#define AL_EN_ChkMDHMS                 6
/* Alarm Enable Check Year, Month, DOM, Hour, Min & Sec */
#define AL_EN_ChkYMDHMS                7
/* Alarm Enable No Change */
#define AL_EN_NoChange                 8

/* Time Counter Enable None */
#define TC_EN_None		               0
/* Time Counter Enable Check Sec */
#define TC_EN_ChkS                     1
/* Time Counter Enable Check Min & Sec */
#define TC_EN_ChkM                     2
/* Time Counter Enable Check Hour, Min & Sec */
#define TC_EN_ChkH                     3
/* Time Counter Enable Check DOM, Hour, Min & Sec */
#define TC_EN_ChkD                     4
/* Time Counter Enable Check DOW, Hour, Min & Sec */
#define TC_EN_ChkW                     5
/* Time Counter Enable Check Month, DOM, Hour, Min & Sec */
#define TC_EN_ChkMon                   6
/* Time Counter Enable Check Year, Month, DOM, Hour, Min & Sec */
#define TC_EN_ChkY                     7
/* Time Counter Enable No Change */
#define TC_EN_NoChange                 8

/*******************************************************************************
 * RTC PDN Bits Definitions
 *******************************************************************************/

/* PDN 1 Bit[7], META Reset RTC */
#define DRV_COMM_REG1_META_RESET_RTC        0x0080
/* PDN 2 Bit[7], Normal Reset */
#define DRV_COMM_REG2_NORMAL_RESET          0x0080
/* PDN 2 Bit[6], Charge Power On */
#define DRV_COMM_REG2_CHRPWRON              0x0040
/* PDN 2 Bit[5], USB Mass Storage Power On */
#define DRV_COMM_REG2_USBMS_PWRON           0x0020
/* PDN 2 Bit[4], RTC Power On */
#define DRV_COMM_REG2_RTCPWRON              0x0010
/* PDN 2 Bit[3], USB Mass Storage Power Off */
#define DRV_COMM_REG2_USBMS_PWROFF          0x0008
/* PDN 2 Bit[2], RTC NVRAM Valid */
#define DRV_COMM_REG2_RTC_NVRAM             0x0004
/* PDN 2 Bit[1], Swich To IDLE Power On */
#define DRV_COMM_REG2_SWITCH2IDLE_PWRON		0x0002
/* PDN 2 Bit[0], BTMT Watchdog Reset Power On */
#define DRV_COMM_REG2_BTMT_WDTRET_PWRON		0x0001

/* Reserved for bootrom security, support it after 6227 */
#if defined(DRV_RTC_COMM_REG1_SECURITY)
/* Bootrom Security 1 */
#define DRV_COMM_REG1_BOOTROM_SECURITY1     0x0001
/* Bootrom Security 2 */
#define DRV_COMM_REG1_BOOTROM_SECURITY2     0x0010
/* Bootrom Security 3 */
#define DRV_COMM_REG1_BOOTROM_SECURITY3     0x0020
/* Bootrom Security 4 */
#define DRV_COMM_REG1_BOOTROM_SECURITY4     0x0040
#endif

/* RTC PDN1, use RTC INFO1 as DRV_COMM_REG1 */
#define DRV_COMM_REG1                  (RTC_base+0x0058)
/* RTC PDN1, use RTC INFO2 as DRV_COMM_REG2 */
#define DRV_COMM_REG2                  (RTC_base+0x005c)

/*******************************************************************************
 * DCL_CTRL_DATA_T: Define the Control data structure for each module's command
 *******************************************************************************/

/* RTC Data Stucture for Save Information Only (Cannot be used for function's parameter) */
typedef struct 
{
	DCL_UINT8		rtc_sec;    /* Seconds after the minute   - [0,59]  */
	DCL_UINT8		rtc_min;    /* Minutes after the hour     - [0,59]  */
	DCL_UINT8		rtc_hour;   /* Hours after the midnight   - [0,23]  */
	DCL_UINT8		rtc_day;    /* Day of the month           - [1,31]  */
	DCL_UINT8		rtc_mon;    /* Months 		              - [1,12]  */
	DCL_UINT8		rtc_wday;   /* Days in a week 		      - [1,7]   */
	DCL_UINT8		rtc_year;   /* Years                      - [0,127] */
}DCL_RTC_DATA_T;

/* For RTC_CMD_BOOTLOADER_POWERON command. */
typedef struct
{
   	DCL_BOOLEAN fgBootloaderPowerOn; /* Output : TRUE: Indicate Device Is First On; FALSE: Device Is Not First On */
}RTC_CTRL_BOOTLOADER_POWERON_T;

/* Enum of PDN Registers */
typedef enum
{
    DCL_RTC_PDN1 = 0, /* PDN1 */
    DCL_RTC_PDN2, /* PDN2 */
	DCL_RTC_MAX_INDEX /* Maximum PDN Register */
}DCL_RTC_PDN_INDEX_T;

/* For RTC_CMD_CLEAR_PDN_BITS, RTC_CMD_READ_PDN_BITS, RTC_CMD_SET_PDN_BITS, RTC_CMD_WRITE_PDN_BITS commands. */
typedef struct
{
	DCL_RTC_PDN_INDEX_T PDNIndex; /* Input : Number of PDN Register */
	DCL_UINT16 fgConfigBit; /* Input : PDN Bit for Configuration */
	DCL_UINT16 PDNValue; /* Output : Value of PDN Register */
}RTC_CTRL_CONFIG_PDN_BIT_T;

/* For RTC_CMD_CONFIG_AL_TC command. */
typedef struct
{
    DCL_UINT8 u1ALEn; /* Input : Alarm Enable */
    DCL_UINT8 u1TCEn; /* Input : Time Counter Enable */
}RTC_CTRL_CONFIG_AL_TC_T;

/* For RTC_CMD_DELAY command. */
// RTC_CMD_DELAY does NOT need parameters

/* For RTC_CMD_FT_POWEROFF command. */
typedef struct
{
	DCL_BOOLEAN fgMetaReset; /* Output : If DRV_COMM_REG1_META_RESET_RTC set or not*/
}RTC_CTRL_FT_POWEROFF_T;

/* For RTC_CMD_GET_ALARM_TIME command. */
typedef struct
{
    DCL_UINT8 u1Sec;		/* Output : Seconds after the minute   - [0,59]  */
    DCL_UINT8 u1Min;		/* Output : Minutes after the hour     - [0,59]  */
    DCL_UINT8 u1Hour;	    /* Output : Hours after the midnight   - [0,23]  */
    DCL_UINT8 u1Day;		/* Output : Day of the month           - [1,31]  */
    DCL_UINT8 u1Mon;		/* Output : Months 		              - [1,12]  */
    DCL_UINT8 u1WDay;	    /* Output : Days in a week 		      - [1,7]   */
    DCL_UINT8 u1Year;	    /* Output : Years                      - [0,127] */
    DCL_BOOLEAN ALEnBit;    /* Output : The status of AL enable bit of RTC_IRQ_EN */
}RTC_CTRL_GET_ALARM_TIME_T;

/* For RTC_CMD_GET_TIME command. */
typedef struct
{
    DCL_UINT8 u1Sec;		/* Output : Seconds after the minute   - [0,59]  */
    DCL_UINT8 u1Min;		/* Output : Minutes after the hour     - [0,59]  */
    DCL_UINT8 u1Hour;		/* Output : Hours after the midnight   - [0,23]  */
    DCL_UINT8 u1Day;		/* Output : Day of the month           - [1,31]  */
    DCL_UINT8 u1Mon;		/* Output : Months 		              - [1,12]  */
    DCL_UINT8 u1WDay;		/* Output : Days in a week 		      - [1,7]   */
    DCL_UINT8 u1Year;		/* Output : Years                      - [0,127] */
}RTC_CTRL_GET_TIME_T;

/* For RTC GPIO Pulling Type */
typedef enum {
    DCL_RTC_GPIO_NO_PULL = 0,   /* No Pull */
    DCL_RTC_GPIO_PULL_DOWN,     /* Pull Down */
    DCL_RTC_GPIO_PULL_UP        /* Pull Up */
}DCL_RTC_GPIO_PULL_TYPE_T;

/* For RTC GPIO Driving Strength */
typedef enum {
    DCL_RTC_GPIO_DS_4mA = 0,    /* 4mA */
    DCL_RTC_GPIO_DS_8mA,        /* 8mA */
    DCL_RTC_GPIO_DS_12mA,       /* 12mA */
    DCL_RTC_GPIO_DS_16mA        /* 16mA */
}DCL_RTC_GPIO_DRIVING_STRENGTH_T;

/* For RTC_CMD_GPIO_CONFIG_MODE command. */
typedef struct
{
    DCL_RTC_GPIO_PULL_TYPE_T rPullType; /* Input : Pull Type */
    DCL_RTC_GPIO_DRIVING_STRENGTH_T rPullStrength; /* Input : Drving Strength */
    DCL_BOOLEAN InputValue; /* Output : Value of GPIO Input */
    DCL_BOOLEAN OutputValue; /* Input : Value of GPIO Output */ 
    DCL_BOOLEAN is_SmithTrigger; /* Input : Is Smith Triggter Or Not */ 
    DCL_BOOLEAN is_SlewRateControl; /* Input : Is Slew Rate Control Or Not */ 
}RTC_CTRL_GPIO_TIME_T;

/* For RTC_CMD_HW_INIT command. */
// RTC_CMD_HW_INIT does NOT need parameters

/* For RTC_CMD_INIT command. */
typedef struct
{
    void (*RTC_TCCallback)(void); /* Input : Callback Function for Timer Count */
    void (*RTC_ALCallback)(void); /* Input : Callback Function for Alarm */
}RTC_CTRL_INIT_T;

/* For RTC_CMD_INIT_TC_AL_INTR command. */
// RTC_CMD_INIT_TC_AL_INTR does NOT need parameters

/* For RTC_CMD_IS_CONFIG_VALID command. */
typedef struct
{	
	DCL_BOOLEAN fgIsValid; /* Output : RTC Config Is Valid Or Not */
}RTC_CTRL_IS_CONFIG_VALID_T;

/* For RTC_CMD_IS_FIRST_ON command. */
typedef struct
{
   	DCL_BOOLEAN fgFirstOn; /* Output : TRUE: Indicate Device Is First On; FALSE: Device Is Not First On */
}RTC_CTRL_IS_FIRST_ON_T;

/* For RTC_CMD_IS_MS_FIRSTPOWERON command. */
typedef struct
{	
	DCL_BOOLEAN fgMSFirstPowerOn; /* Output : TRUE: Indicate Device Is First On; FALSE: Device Is Not First On */
}RTC_CTRL_IS_MS_FIRSTPOWERON_T;

/* For RTC_CMD_IS_TIME_VALID command. */
typedef struct
{
    DCL_UINT8 u1Sec;		/* Input : Seconds after the minute   - [0,59]  */
    DCL_UINT8 u1Min;		/* Input : Minutes after the hour     - [0,59]  */
    DCL_UINT8 u1Hour;		/* Input : Hours after the midnight   - [0,23]  */
    DCL_UINT8 u1Day;		/* Input : Day of the month           - [1,31]  */
    DCL_UINT8 u1Mon;		/* Input : Months 		              - [1,12]  */
    DCL_UINT8 u1WDay;		/* Input : Days in a week 		      - [1,7]   */
    DCL_UINT8 u1Year;		/* Input : Years                      - [0,127] */
    DCL_BOOLEAN isTimeValid;    /* Output: If time is valid                     */
}RTC_CTRL_IS_TIME_VALID_T;

/* For RTC_CMD_PWIC_CHECK_POWERON command. */
typedef struct
{	
	DCL_BOOLEAN fgIsPowerOn; /* Output : If Power On Or Not */
}RTC_CTRL_PWIC_CHECK_POWERON_T;

/* For RTC_CMD_PWIC_FIRST_POWERON_INIT_RTCTIME command. */
typedef struct
{
    DCL_UINT8 u1Sec;		/* Input : Seconds after the minute   - [0,59]  */
    DCL_UINT8 u1Min;		/* Input : Minutes after the hour     - [0,59]  */
    DCL_UINT8 u1Hour;		/* Input : Hours after the midnight   - [0,23]  */
    DCL_UINT8 u1Day;		/* Input : Day of the month           - [1,31]  */
    DCL_UINT8 u1Mon;		/* Input : Months 		              - [1,12]  */
    DCL_UINT8 u1WDay;		/* Input : Days in a week 		      - [1,7]   */
    DCL_UINT8 u1Year;		/* Input : Years                      - [0,127] */
}RTC_CTRL_PWIC_FIRST_POWERON_INIT_RTCTIME_T;

/* For RTC_CMD_PWIC_MASK_AL command. */
// RTC_CMD_PWIC_MASK_AL does NOT need parameters

/* For RTC_CMD_PWIC_POWEROFF_RTC_INIT command. */
// RTC_CMD_PWIC_POWEROFF_RTC_INIT does NOT need parameters

/* For RTC_CMD_PWIC_POWERON_RTC_INIT command. */
// RTC_CMD_PWIC_POWERON_RTC_INIT does NOT need parameters

/* Enum of SPAR Registers */
typedef enum
{
    DCL_RTC_SPAR0 = 0, /* SPAR0 */
    DCL_RTC_SPAR1, /* SPAR1 */
	DCL_RTC_SPAR_MAX_INDEX /* Maximum SPAR Register */
}DCL_RTC_SPAR_INDEX_T;

/* For RTC_CMD_READ_SPAR, RTC_CMD_WRITE_SPAR commands. */
typedef struct
{
	DCL_RTC_SPAR_INDEX_T SPARIndex; /* Input : Number of SPAR Register */
	DCL_UINT16 WriteValue; /* Input : Value of SPAR for Configuration */
	DCL_UINT16 ReadValue; /* Output : Value of SPAR Register */
}RTC_CTRL_CONFIG_SPAR_T;

/* For RTC_CMD_READ_XOSC_REG command. */
typedef struct
{	
	DCL_UINT8 XOSCValue; /* Output : The Result of XOSCCALI */ 
}RTC_CTRL_READ_XOSC_REG_T;

/* For RTC_CMD_RELOAD command. */
// RTC_CMD_RELOAD does NOT need parameters

/* For RTC_CMD_SET_ALARM_TIME command. */
typedef struct
{
    DCL_UINT8 u1Sec;		/* Input : Seconds after the minute   - [0,59]  */
    DCL_UINT8 u1Min;		/* Input : Minutes after the hour     - [0,59]  */
    DCL_UINT8 u1Hour;		/* Input : Hours after the midnight   - [0,23]  */
    DCL_UINT8 u1Day;		/* Input : Day of the month           - [1,31]  */
    DCL_UINT8 u1Mon;		/* Input : Months 		              - [1,12]  */
    DCL_UINT8 u1WDay;		/* Input : Days in a week 		      - [1,7]   */
    DCL_UINT8 u1Year;		/* Input : Years                      - [0,127] */
}RTC_CTRL_SET_ALARM_TIME_T;

/* For RTC_CMD_SET_FIRST_POWERON command. */
typedef struct
{	
	DCL_BOOLEAN fgPowerOn; /* Input : Set First Power On */
}RTC_CTRL_SET_FIRST_POWERON_T;

/* For RTC_CMD_SET_PWR_KEY command. */
// RTC_CMD_SET_PWR_KEY does NOT need parameters

/* For RTC_CMD_SET_TIME command. */
typedef struct
{
    DCL_UINT8 u1Sec;		/* Input : Seconds after the minute   - [0,59]  */
    DCL_UINT8 u1Min;		/* Input : Minutes after the hour     - [0,59]  */
    DCL_UINT8 u1Hour;	    /* Input : Hours after the midnight   - [0,23]  */
    DCL_UINT8 u1Day;		/* Input : Day of the month           - [1,31]  */
    DCL_UINT8 u1Mon;		/* Input : Months 		              - [1,12]  */
    DCL_UINT8 u1WDay;	    /* Input : Days in a week 		      - [1,7]   */
    DCL_UINT8 u1Year;	    /* Input : Years                      - [0,127] */
}RTC_CTRL_SET_TIME_T;

/* For RTC_CMD_SETBBPU command. */
typedef struct
{	
	DCL_UINT16 BBPUReg; /* Input : Set BBPU Register */
}RTC_CTRL_SETBBPU_T;

/* For RTC_CMD_SETXOSC command. */
// RTC_CMD_SETXOSC does NOT need parameters

/* For RTC_CMD_START_CALI command. */
// RTC_CMD_START_CALI does NOT need parameters

/* For RTC_CMD_WAIT_DEBOUNCE command. */
// RTC_CMD_WAIT_DEBOUNCE does NOT need parameters

/* For RTC_CMD_WRITE_TRIGGER command. */
// RTC_CMD_WRITE_TRIGGER does NOT need parameters

/* For RTC_CMD_WRITE_TRIGGER_WAIT command. */
// RTC_CMD_WRITE_TRIGGER_WAIT does NOT need parameters

/* For RTC_CMD_WRITE_XOSC_REG command. */
typedef struct
{	
	DCL_UINT8 XOSC_Reg; /* Input : Set XOSCCALI Register */
}RTC_CTRL_WRITE_XOSC_REG_T;

typedef struct
{
    DCL_UINT32  dest_mod_id;
    DCL_UINT32  sap_id;
    DCL_UINT32  msg_id;
    DCL_BOOLEAN fgRegisterILM;
}RTC_CTRL_REGISTER_MODULE_ILM_INFO_T;

/* For RTC_CMD_WRITE_XOSC_REG command. */
typedef struct
{	
	DCL_UINT16 OSC32CON_Reg; /* Input : Set XOSCCALI Register */
}RTC_CTRL_WRITE_OSC32CON_REG_T;

#ifdef __BUILD_DOM__
/* The RTC Command Parameter Data Structure for Each Command in DCL_CTRL_DATA_T Enum of dcl.h */
typedef struct
{
    RTC_CTRL_BOOTLOADER_POWERON_T rBootloaderPowerOn; /* Data Structure for RTC_CMD_BOOTLOADER_POWERON */
    RTC_CTRL_CONFIG_AL_TC_T rConfigALTC; /* Data Structure for RTC_CMD_CONFIG_AL_TC */
    RTC_CTRL_CONFIG_PDN_BIT_T rConfigPDNBit; /* Data Structure for RTC_CMD_CLEAR_PDN_BITS, RTC_CMD_READ_PDN_BITS, RTC_CMD_SET_PDN_BITS, and RTC_CMD_WRITE_PDN_BITS */
	RTC_CTRL_FT_POWEROFF_T rFTPowerOff; /* Data Structure for RTC_CMD_FT_POWEROFF */
    RTC_CTRL_GET_ALARM_TIME_T rGetAlarmTime; /* Data Structure for RTC_CMD_GET_ALARM_TIME */
    RTC_CTRL_GET_TIME_T rGetTime; /* Data Structure for RTC_CMD_GET_TIME */
    RTC_CTRL_GPIO_TIME_T rGPIO; /* Data Structure for RTC_CMD_GPIO_GET_INPUT, RTC_CMD_GPIO_SET_INPUT_MODE, and RTC_CMD_GPIO_SET_OUTPUT_MODE */
    RTC_CTRL_INIT_T rInit; /* Data Structure for RTC_CMD_INIT */
    RTC_CTRL_IS_CONFIG_VALID_T rIsConfigValid; /* Data Structure for RTC_CMD_IS_CONFIG_VALID */
    RTC_CTRL_IS_FIRST_ON_T rIsFirstOn; /* Data Structure for RTC_CMD_IS_FIRST_ON */
    RTC_CTRL_IS_MS_FIRSTPOWERON_T rIsMSFirstPowerOn; /* Data Structure for RTC_CMD_IS_MS_FIRSTPOWERON */
    RTC_CTRL_IS_TIME_VALID_T rIsTimeValid; /* Data Structure for RTC_CMD_IS_TIME_VALID */
 	RTC_CTRL_PWIC_CHECK_POWERON_T rPwicCheckPowerOn; /* Data Structure for RTC_CMD_PWIC_CHECK_POWERON */
 	RTC_CTRL_PWIC_FIRST_POWERON_INIT_RTCTIME_T rPwicFirstPowerOnInitRTCTime; /* Data Structure for RTC_CMD_PWIC_FIRST_POWERON_INIT_RTCTIME */
    RTC_CTRL_CONFIG_SPAR_T rConfigSPARReg; /* Data Structure for RTC_CMD_READ_SPAR, and RTC_CMD_WRITE_SPAR */
 	RTC_CTRL_READ_XOSC_REG_T rReadXOSCReg; /* Data Structure for RTC_CMD_READ_XOSC_REG */
	RTC_CTRL_SET_ALARM_TIME_T rSetAlarmTime; /* Data Structure for RTC_CMD_SET_ALARM_TIME */
	RTC_CTRL_SET_FIRST_POWERON_T rSetFirstPowerOn; /* Data Structure for RTC_CMD_SET_FIRST_POWERON */
   	RTC_CTRL_SET_TIME_T rSetTime; /* Data Structure for RTC_CMD_SET_TIME */
	RTC_CTRL_SETBBPU_T rSetBBPU; /* Data Structure for RTC_CMD_SETBBPU */
	RTC_CTRL_WRITE_XOSC_REG_T rWriteXOSCRef; /* Data Structure for RTC_CMD_WRITE_XOSC_REG */   
    RTC_CTRL_REGISTER_MODULE_ILM_INFO_T rRegisterModILMInfo; /* Data Structure for ilm to send to other modules */
    RTC_CTRL_WRITE_OSC32CON_REG_T rWriteOSC32CONReg;  /* Data Structure for RTC_CMD_REGISTER_MODULE_TO_SEND_RTCTIME */ 
}DCL_CTRL_DATA_T;
#else /* __BUILD_DOM__ */

#define RTC_CTRLS \
    RTC_CTRL_BOOTLOADER_POWERON_T rBootloaderPowerOn; \
    RTC_CTRL_CONFIG_AL_TC_T rConfigALTC; \
    RTC_CTRL_CONFIG_PDN_BIT_T rConfigPDNBit; \
	RTC_CTRL_FT_POWEROFF_T rFTPowerOff; \
    RTC_CTRL_GET_ALARM_TIME_T rGetAlarmTime; \
    RTC_CTRL_GET_TIME_T rGetTime; \
    RTC_CTRL_GPIO_TIME_T rGPIO; \
    RTC_CTRL_INIT_T rInit; \
    RTC_CTRL_IS_CONFIG_VALID_T rIsConfigValid; \
    RTC_CTRL_IS_FIRST_ON_T rIsFirstOn; \
    RTC_CTRL_IS_MS_FIRSTPOWERON_T rIsMSFirstPowerOn; \
    RTC_CTRL_IS_TIME_VALID_T rIsTimeValid; \
 	RTC_CTRL_PWIC_CHECK_POWERON_T rPwicCheckPowerOn; \
 	RTC_CTRL_PWIC_FIRST_POWERON_INIT_RTCTIME_T rPwicFirstPowerOnInitRTCTime; \
 	RTC_CTRL_CONFIG_SPAR_T rConfigSPARReg; \
 	RTC_CTRL_READ_XOSC_REG_T rReadXOSCReg; \
	RTC_CTRL_SET_ALARM_TIME_T rSetAlarmTime; \
	RTC_CTRL_SET_FIRST_POWERON_T rSetFirstPowerOn; \
   	RTC_CTRL_SET_TIME_T rSetTime; \
	RTC_CTRL_SETBBPU_T rSetBBPU; \
	RTC_CTRL_WRITE_XOSC_REG_T rWriteXOSCRef; \
    RTC_CTRL_REGISTER_MODULE_ILM_INFO_T rRegisterModILMInfo; \
	RTC_CTRL_WRITE_OSC32CON_REG_T rWriteOSC32CONReg;

#endif /* __BUILD_DOM__ */

#endif // #ifndef __DCL_RTC_H_STRUCT__
#endif // #ifdef DCL_DEFINITION_STRUCT   


#ifdef DCL_DEFINITION_PROTOTYPE
#ifndef __DCL_RTC_H_PROTOTYPE__
#define __DCL_RTC_H_PROTOTYPE__

/*************************************************************************
* FUNCTION
*  DclRTC_Initialize
*
* DESCRIPTION
*  This function is to initialize RTC module
*
* PARAMETERS
*  None
*
* RETURNS
*  Return the status of DclRTC_Initialize
*
* RETURN VALUES
*  STATUS_OK: Initialize Finished
*
*************************************************************************/
extern DCL_STATUS DclRTC_Initialize(void);
/*************************************************************************
* FUNCTION
*  DclRTC_Open
*
* DESCRIPTION
*  This function is to open the RTC module and return a handle
*
* PARAMETERS
*  dev: [IN] Only valid for DCL_RTC
*  flags: [IN] No sepcial flags is needed. Please use FLAGS_NONE
*
* RETURNS
*  Return DCL_HANDLE of RTC
*
* RETURN VALUES
*  DCL_HANDLE_INVALID : Open failed
*  Other value : A valid handle
*
*************************************************************************/
extern DCL_HANDLE DclRTC_Open(DCL_DEV dev, DCL_FLAGS flags);
/*************************************************************************
* FUNCTION
*  DclRTC_ReadData
*
* DESCRIPTION
*  This function is not supported for the RTC module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclRTC_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options);
/*************************************************************************
* FUNCTION
*  DclRTC_WriteData
*
* DESCRIPTION
*  This function is not supported for the RTC module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclRTC_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options);
/*************************************************************************
* FUNCTION
*  DclRTC_Configure
*
* DESCRIPTION
*  This function is not supported for the RTC module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclRTC_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure);
/*************************************************************************
* FUNCTION
*  DclRTC_RegisterCallback
*
* DESCRIPTION
*  This function is to set callback function for the RTC module.
*
* PARAMETERS
*  handle: [IN] The returned handle value of DclRTC_Open
*  event: [IN] Supported events:
*          1.EVENT_RTC_ALARM: RTC alarm interrupt
*          2.EVENT_RTC_TC: RTC tick interrupt
*  callback: [IN] the callback function for registered events
*
* RETURNS
*  Return the status of DclRTC_RegisterCallback
*
* RETURN VALUES
*  STATUS_OK: Successfully register the callback function.
*  STATUS_INVALID_DCL_HANDLE: It's a invalid handle.
*  STATUS_NOT_OPENED: The module has not been opened.
*  STATUS_INVALID_EVENT: The event parameter is invalid.
*
*************************************************************************/
extern DCL_STATUS DclRTC_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback);
/*************************************************************************
* FUNCTION
*  DclRTC_Control
*
* DESCRIPTION
*  This function is to send command to control the RTC module.
*
* PARAMETERS
*  handle: [IN] The handle value returned from DclRTC_Open
*  cmd: [IN] A control command for RTC module
*           1. RTC_CMD_BOOTLOADER_POWERON: to check RTC Power On in bootloader
*           2. RTC_CMD_CLEAR_PDN_BITS: to clear RTC PDN bits
*           3. RTC_CMD_CONFIG_AL_TC: to set alarm mask and tick mask
*           4. RTC_CMD_DELAY: to Delay 2000 counts
*           5. RTC_CMD_FT_POWEROFF: to Power Off for FlashTool
*          	6. RTC_CMD_GET_ALARM_TIME: to get alarm time
*           7. RTC_CMD_GET_TIME: to get time              
*           8. RTC_CMD_GPIO_GET_INPUT: to get RTC_GPIO_GPI register value
*           9. RTC_CMD_GPIO_SET_EXPORT_32K: to export 32.768KHz clock on RTC_GPIO
*          10. RTC_CMD_GPIO_SET_EXPORT_COREDETB: to export COREDETB on RTC_GPIO
*          11. RTC_CMD_GPIO_SET_INPUT_MODE: to set RTC_GPIO input mode
*          12. RTC_CMD_GPIO_SET_OUTPUT_MODE: to set RTC_GPIO output mode
*          13. RTC_CMD_HW_INIT: to initialize RTC hardware
*          14. RTC_CMD_INIT: to initialize RTC software
*          15. RTC_CMD_INIT_TC_AL_INTR: to initialize RTC TC & AL INTR
*          16. RTC_CMD_IS_CONFIG_VALID: to check if RTC time and Alarm are valid
*          17. RTC_CMD_IS_FIRST_ON: to check if device is first on               
*          18. RTC_CMD_IS_MS_FIRSTPOWERON: to check whether RTC is first power on(for MMI)
*          19. RTC_CMD_IS_TIME_VALID: to check if time are valid
*          20. RTC_CMD_PWIC_CHECK_POWERON: to check if power on (for PWIC)
*          21. RTC_CMD_PWIC_FIRST_POWERON_INIT_RTCTIME: to init RTC time at first power on (for PWIC)
*          22. RTC_CMD_PWIC_MASK_AL: to control RTC Alarm mask (for PWIC)
*          23. RTC_CMD_PWIC_POWEROFF_RTC_INIT: to init RTC at power off (for PWIC)
*          24. RTC_CMD_PWIC_POWERON_RTC_INIT: to init RTC at power on (for PWIC)
*          25. RTC_CMD_READ_PDN_BITS: to read RTC PDN bits
*          26. RTC_CMD_READ_SPAR: to read RTC SPAR Register
*          27. RTC_CMD_READ_XOSC_REG: to read RTC XOSCCALI register
*          28. RTC_CMD_RELOAD: to load RTC whole register info from RTC module
*          29. RTC_CMD_SET_ALARM_TIME: to set alarm time
*          30. RTC_CMD_SET_FIRST_POWERON: to set first power on
*          31. RTC_CMD_SET_PDN_BITS: to set RTC PDN bits
*          32. RTC_CMD_SET_PWR_KEY: to set PWR KEY
*          33. RTC_CMD_SET_TIME: to set time
*          34. RTC_CMD_SETBBPU: to set RTC_BBPU
*          35. RTC_CMD_SETXOSC: to set RTC XOSCCALI register
*          36. RTC_CMD_START_CALI: to start calibration process
*          37. RTC_CMD_WAIT_DEBOUNCE: to wait until debounce bit becomes 0
*          38. RTC_CMD_WRITE_PDN_BITS: to write RTC PDN bits
*          39. RTC_CMD_WRITE_SPAR: to write RTC SPAR Register
*          40. RTC_CMD_WRITE_TRIGGER: to set write trigger
*          41. RTC_CMD_WRITE_TRIGGER_WAIT: to set write trigger and wait until BUSY bit becomes 0
*          42. RTC_CMD_WRITE_XOSC_REG: to write RTC XOSCCALI register
*
*  data: The data of the control command
*           1. RTC_CMD_BOOTLOADER_POWERON: pointer to a RTC_CTRL_BOOTLOADER_POWERON_T structure
*           2. RTC_CMD_CLEAR_PDN_BITS: pointer to a RTC_CTRL_CONFIG_PDN_BIT_T structure
*           3. RTC_CMD_CONFIG_AL_TC: pointer to a RTC_CTRL_CONFIG_AL_TC_T structure
*           4. RTC_CMD_DELAY: A null pointer
*           5. RTC_CMD_FT_POWEROFF: A null pointer
*          	6. RTC_CMD_GET_ALARM_TIME: pointer to a RTC_CTRL_GET_ALARM_TIME_T structure
*           7. RTC_CMD_GET_TIME: pointer to a RTC_CTRL_GET_TIME_T structure       
*           8. RTC_CMD_GPIO_GET_INPUT: pointer to a RTC_CTRL_GPIO_TIME_T structure
*           9. RTC_CMD_GPIO_SET_EXPORT_32K: pointer to a RTC_CTRL_GPIO_TIME_T structure
*          10. RTC_CMD_GPIO_SET_EXPORT_COREDETB: pointer to a RTC_CTRL_GPIO_TIME_T structure
*          11. RTC_CMD_GPIO_SET_INPUT_MODE: pointer to a RTC_CTRL_GPIO_TIME_T structure
*          12. RTC_CMD_GPIO_SET_OUTPUT_MODE: pointer to a RTC_CTRL_GPIO_TIME_T structure
*          13. RTC_CMD_HW_INIT: A null pointer
*          14. RTC_CMD_INIT: pointer to a RTC_CTRL_INIT_T structure
*          15. RTC_CMD_INIT_TC_AL_INTR: A null pointer
*          16. RTC_CMD_IS_CONFIG_VALID: pointer to a RTC_CTRL_IS_CONFIG_VALID_T structure
*          17. RTC_CMD_IS_FIRST_ON: pointer to a RTC_CTRL_IS_FIRST_ON_T structure             
*          18. RTC_CMD_IS_MS_FIRSTPOWERON: pointer to a RTC_CTRL_IS_MS_FIRSTPOWERON_T structure
*          19. RTC_CMD_IS_TIME_VALID: pointer to a RTC_CTRL_IS_TIME_VALID_T structure
*          20. RTC_CMD_PWIC_CHECK_POWERON: pointer to a RTC_CTRL_PWIC_CHECK_POWERON_T structure
*          21. RTC_CMD_PWIC_FIRST_POWERON_INIT_RTCTIME: pointer to a RTC_CTRL_PWIC_FIRST_POWERON_INIT_RTCTIME_T structure
*          22. RTC_CMD_PWIC_MASK_AL: A null pointer
*          23. RTC_CMD_PWIC_POWEROFF_RTC_INIT: A null pointer
*          24. RTC_CMD_PWIC_POWERON_RTC_INIT: A null pointer
*          25. RTC_CMD_READ_PDN_BITS: pointer to a RTC_CTRL_CONFIG_PDN_BIT_T structure
*          26. RTC_CMD_READ_SPAR: pointer to a RTC_CTRL_CONFIG_SPAR_T structure
*          27. RTC_CMD_READ_XOSC_REG: pointer to a RTC_CTRL_READ_XOSC_REG_T structure
*          28. RTC_CMD_RELOAD: A null pointer
*          29. RTC_CMD_SET_ALARM_TIME: pointer to a RTC_CTRL_SET_ALARM_TIME_T structure
*          30. RTC_CMD_SET_FIRST_POWERON: pointer to a RTC_CTRL_SET_FIRST_POWERON_T structure
*          31. RTC_CMD_SET_PDN_BITS: pointer to a RTC_CTRL_CONFIG_PDN_BIT_T structure
*          32. RTC_CMD_SET_PWR_KEY: A null pointer
*          33. RTC_CMD_SET_TIME: pointer to a RTC_CTRL_SET_TIME_T structure
*          34. RTC_CMD_SETBBPU: pointer to a RTC_CTRL_SETBBPU_T structure
*          35. RTC_CMD_SETXOSC: A null pointer
*          36. RTC_CMD_START_CALI: A null pointer
*          37. RTC_CMD_WAIT_DEBOUNCE: A null pointer
*          38. RTC_CMD_WRITE_PDN_BITS: pointer to a RTC_CTRL_CONFIG_PDN_BIT_T structure
*          39. RTC_CMD_WRITE_SPAR: pointer to a RTC_CTRL_CONFIG_SPAR_T structure
*          40. RTC_CMD_WRITE_TRIGGER: A null pointer
*          41. RTC_CMD_WRITE_TRIGGER_WAIT: A null pointer
*          42. RTC_CMD_WRITE_XOSC_REG: pointer to a RTC_CTRL_WRITE_XOSC_REG_T structure
*
* RETURNS
*  Return the status of DclRTC_Control
*
* RETURN VALUES
*  STATUS_OK: Command is executed successfully.
*  STATUS_FAIL: Command is failed.
*  STATUS_INVALID_CMD: It's a invalid command.
*
*************************************************************************/
extern DCL_STATUS DclRTC_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);
/*************************************************************************
* FUNCTION
*  DclRTC_Close
*
* DESCRIPTION
*  This function is to close the RTC module.
*
* PARAMETERS
*  handle: [IN] The returned handle value of DclRTC_Open
*
* RETURNS
*  Return the status of DclRTC_Close
*
* RETURN VALUES
*  STATUS_OK
*
*************************************************************************/
extern DCL_STATUS DclRTC_Close(DCL_HANDLE handle);


#endif // #ifndef __DCL_RTC_H_PROTOTYPE__
#endif // #ifdef DCL_DEFINITION_PROTOTYPE

