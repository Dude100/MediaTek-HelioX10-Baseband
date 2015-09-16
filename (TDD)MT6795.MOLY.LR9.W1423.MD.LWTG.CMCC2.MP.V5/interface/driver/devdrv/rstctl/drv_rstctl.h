#ifndef __DRV_RSTCTL_H__
#define __DRV_RSTCTL_H__

#if defined(MT6290)

/*Set wdt timeout interval as 4 sec(32768*4=0x20000)*/
#define WDT_RSTINTERVAL_VALUE	(0x20000)

typedef enum
{
	RST_TARGET_MIN=0,
	RST_SDCTL,
	RST_MDGDMA,
	RST_USIM0,
	RST_USIM1,
	RST_MDUART,
	RST_SUART0,
	RST_SUART1,
	RST_MDGPTM,
	RST_MDMISC,
	RST_MDCIRQ,
	RST_LED,
	RST_I2C,
	RST_SDCTL_CIS,
	RST_DBGSYS,
	RST_DBGCV,
	RST_DBGSIB,
	RST_GPIOMUX,
	RST_APTOPSM,
	RST_MDTOPSM,
	RST_APOST,
	RST_MDOST,
	RST_MDCFGCTL,
	RST_DRAMC_AO,
	RST_EMI_AO,
	RST_ARM7_HRST,
	RST_ARM7_SRST,
	RST_ARM7SYS,
	RST_CAIF,
	RST_L2COP,
	RST_MEMSYS,
	RST_MDINFRA_MISC,
	RST_MDINFRA_BUSMON,
	RST_MDINFRA_BOOTROM,
	RST_ABM,
	RST_CR4,
	RST_CR4_NRESET,
	RST_CR4_BUSMON,
	RST_ALC,
	RST_PF,
	RST_PCMON_FIFO,
	RST_PCMON_REG,
	RST_AP_RSTMD,
	RST_MDCLK,
	RST_APCLK,
	RST_EFUSE,
	RST_MML1,
	RST_MML1OFF,
	RST_TDD,
	RST_2G3G,
	RST_2G3G_DSP,
	RST_EXT_RST,
	RST_BSICTL,
	RST_RFIC1_BSISPI,
	RST_RFIC2_BSISPI,
	RST_PMIC_BSISPI,
	RST_MIPI0_BSISPI,
	RST_MIPI1_BSISPI,
	RST_BSI_ALL,
	RST_IDC,
	RST_MML1_BPICTRL,
	RST_MML1_PERISYS_MISC,
	RST_MML1_PERI_MBIST_CONFIG,
	RST_AUXADC,
	RST_MML1_PERISYS_XRESET,
	RST_MIXEDSYS,
	RST_SSUSB,
	RST_APUART,
	RST_APCCIF,
	RST_CLDMA,
	RST_NFI,
	RST_SPI,
	RST_USB,
	RST_IPSEC,
	RST_HIF0,
	RST_PFC,
	RST_NLI,
	RST_MSDC0P,
	RST_MSDC1P,
	RST_APGPTM,
	RST_APGDMA,
	RST_APINFRA_BUSMON,
	RST_AP_MISC,
	RST_APTZCTL,
	RST_ETHER_NIC,
	RST_TRACE,
	RST_CA7_DBG,
	RST_CA7_NRESET,
	RST_CA7_BUSMON,
	RST_MDALL,
	RST_APALL,
	RST_MDALL_WO_SPI,
	RST_MDALL_WO_USB,
	RST_TARGET_MAX		/**< Maximum value of reset item : for correctness check */
} rst_target_e;

typedef enum
{
	WDT_RESET,
	WDT_IRQ_ONLY,
} wdt_irq_e;


//definition for WDT status
#define MD_HWDT		(1 << 0)
#define MD_SWDT		(1 << 1)
#define AP_HWDT		(1 << 2)
#define AP_SWDT 	(1 << 3)
#define AP_SWR		(1 << 4)
#define MD_WDT_CNT_MASK		(0xF << 8)
#define AP_WDT_CNT_MASK		(0xF << 12)

typedef struct rstctl_ext_cfg_s {
	kal_bool	EXT_RST_EA;
	kal_bool	MD_POL;
	kal_bool	PAD_OUT_EA;
} rstctl_ext_cfg_t;

/*****************************************************************************
 *						 function declaration                                *
 *****************************************************************************/
void drv_rstctl_sw_wd_reset(kal_uint32 wdTarget);
void drv_rstctl_wd_reset(wdt_irq_e irq_en, rst_target_e wdTarget, kal_uint32 wdtInterval);
void drv_rstctl_wd_disable(void);
void drv_rstctl_sw_reset(rst_target_e targetIP);
kal_uint16 drv_rstctl_wd_getInterval(void);
void drv_rstctl_restartWDT(void);

/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_getSta
*
* DESCRIPTION
*  This function is used to get wdt status
*
* PARAMETERS
*	none
*
* RETURN VALUES
*  bit[15:12]:AP WDT CNT : AP wd reset increase one. can be reset by disable WDT
*  bit[11:8]:MD WDT CNT : MD wd reset increase one. can be reset by disable WDT
*  bit[4]:AP reset MD indicator
*  bit[3]:AP sw WD reset indicator
*  bit[2]:AP hw WD reset indicator
*  bit[1]:MD sw WD reset indicator
*  bit[0]:MD hw WD reset indicator
*************************************************************************/
kal_uint32 drv_rstctl_wd_getSta(void);

/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_clrCnt
*
* DESCRIPTION
*  This function is used to clear wdt cnt
*
* PARAMETERS
*	cntMaskToClear
*   0: clear both AP/MD WD Cnt
*   MD_WDCNT_CLR: clear MD WD Cnt
*   AP_WDCNT_CLR: clear AP WD Cnt
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_wd_clrCnt(kal_uint32 cntMaskToClear);

/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_clrSta
*
* DESCRIPTION
*  This function is used to clear wdt status
*
* PARAMETERS
*	none
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_wd_clrSta(void);

/*************************************************************************
* FUNCTION
*  drv_rstctl_extrst_setCfg
*
* DESCRIPTION
*  This function is used to config EXT_RST
*
* PARAMETERS
*	rstctl_ext_cfg_t ext_cfg
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_extrst_setCfg(rstctl_ext_cfg_t ext_cfg);

/*************************************************************************
* FUNCTION
*  drv_rstctl_extrst_getSta
*
* DESCRIPTION
*  This function is used to get EXT_RST status
*
* PARAMETERS
*	none
* RETURN VALUES
*	1: ext rst assert
*	0: ext rst de-assert

*************************************************************************/
kal_bool drv_rstctl_extrst_getSta(void);


//for DCL driver
void drv_rstctl_wdt_setInterval(kal_uint32 wdtInterval);
void drv_rstctl_wdt_enable(kal_bool en);
void drv_rstctl_wdt_enableInterrupt(kal_bool enable);
void drv_rstctl_wdt_enableDebugMode(kal_bool enable);
void drv_rstctl_wdt_init(void);
void drv_rstctl_wdt_reset(void);
void drv_rstctl_wdt_abnReset(void);

/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_rst_set_bitmap
*
* DESCRIPTION
*  This function is used to set WD reset bit map for USB suspend
*
* PARAMETERS
*	none
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_wd_rst_set_bitmap(kal_uint8 type);


/*******************************************/
#elif defined(MT6595) || (defined(MT6752) && defined(__MD1__))

/*Set wdt timeout interval as 4 sec(32768*4/512=0x100)*/
#define WDT_RSTINTERVAL_VALUE	(0x100)

typedef enum
{
	WDT_RESET,
	WDT_IRQ_ONLY,
} wdt_irq_e;

typedef enum
{
    RST_A7_DEASSERT = 0,
    RST_A7_ASSERT = 1,
}rst_a7_asrt_e;

typedef enum
{
    RST_A7_LOCK = 0,
    RST_A7_UNLOCK = 1,
}rst_a7_lock_e;

/*For easy implementation, move these two definition from rstctl_reg.h*/
/*REG_WDT_MD_STA*/
#define RSTCTL_STA_WDT_BIT             (15)
#define RSTCTL_STA_SW_WDT_BIT          (14)

#define MD_HWDT		(0x1 << RSTCTL_STA_WDT_BIT)
#define MD_SWDT		(0x1 << RSTCTL_STA_SW_WDT_BIT)

typedef enum
{
	RST_MD_SWRST = 0,
	RST_2GDSP,
	RST_CLDMA,
	RST_PCMON_REG,
	RST_PCMON_FIFO,
	RST_L2COP,
	RST_CAIF,
	RST_ARM7_SRST,
	RST_ARM7_HRST,
	RST_ARM7SYS,
	RST_MML1STS,
	RST_MML1_PERISYS_XRESET,
	RST_MML1_PERI_MBIST_CONFIG,
	RST_MML1_PERISYS_MISC,
	RST_MML1_BPICTRL,
	RST_IDC,
	RST_MIPI1_BSISPI,
	RST_MIPI0_BSISPI,
	RST_PMIC_BSISPI,
    RST_RFIC2_BSISPI,
	RST_RFIC1_BSISPI,
	RST_PF_BSICTRL,
	RST_TARGET_MAX,		/**< Maximum value of reset item : for correctness check */

    /*Following is for backward compatible*/
    RST_MDALL,

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}rst_target_e;


typedef enum
{
    WDT_RETN_FLAG_0 = (0x1 << 0),
    WDT_RETN_FLAG_1 = (0x1 << 1),
    WDT_RETN_FLAG_2 = (0x1 << 2),
    WDT_RETN_FLAG_3 = (0x1 << 3),
    WDT_RETN_FLAG_4 = (0x1 << 4),
    WDT_RETN_FLAG_5 = (0x1 << 5),
    WDT_RETN_FLAG_6 = (0x1 << 6),
    WDT_RETN_FLAG_7 = (0x1 << 7),
    WDT_RETN_FLAG_ALL = 0xFF,
}rst_retn_flag_e;

/*************************************************************************
* FUNCTION
*  drv_rstctl_ws_wdReset
*
* DESCRIPTION
*  This function is used to control top rgu to make whole system reset
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_ws_wdReset(void);

/*************************************************************************
* FUNCTION
*  drv_rstctl_top_retn_data
*
* DESCRIPTION
*  This function is used to read/write retention data
*
* PARAMETERS
*	bRead: 1: read data
*           0: write data
*    pData:
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_top_retn_data(kal_bool bRead, kal_uint32 *pData);

/*************************************************************************
* FUNCTION
*  drv_rstctl_A7_unlock
*
* DESCRIPTION
*  This function is used to unlock ARM7 hrst
*
* PARAMETERS
*	lock:   RST_A7_LOCK:
*            RST_A7_UNLOCK:
*
* RETURN VALUES
*	none
*
*************************************************************************/
void drv_rstctl_A7_unlock(rst_a7_lock_e lock);

/*************************************************************************
* FUNCTION
*  drv_rstctl_sw_reset
*
* DESCRIPTION
*  This function is used to do SW ARM7 reset
*
* PARAMETERS
*	assert: 1: set reset assert
*            0: set reset de-assert
*    targetIP: only support RST_A7_CCIF/RST_A7_SRST/RST_A7_HRST/RST_A7_SYS
*
* RETURN VALUES
*	none
*
* NOTE: Please set assert at least one 32K cycle
*************************************************************************/
extern void drv_rstctl_sw_A7_reset(rst_a7_asrt_e asrt, rst_target_e targetIP);

/*************************************************************************
* FUNCTION
*  drv_rstctl_sw_reset
*
* DESCRIPTION
*  This function is used to do SW reset
*
* PARAMETERS
*	targetIP: sw module defined in RGU
*
* RETURN VALUES
*	none
*************************************************************************/
extern void drv_rstctl_sw_reset(rst_target_e targetIP);


/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_reset
*
* DESCRIPTION
*  This function is used to config wd timer and start
*
* PARAMETERS
*    irq_en: wd reset issued irq istead of reset
*    wdtInterval: watchdog timerout period, unit as 512*T32K=15.6ms
*
* RETURN VALUES
*	none
*************************************************************************/
extern void drv_rstctl_wd_reset(wdt_irq_e irq_en, rst_target_e wdTarget, kal_uint32 wdtInterval);

/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_getSta
*
* DESCRIPTION
*  This function is used to get wdt status
*
* PARAMETERS
*	none
*
* RETURN VALUES
*    wdt_sta_e: no reset, sw reset, wd timer reset, sw and wd timer reset
*
*************************************************************************/
extern kal_uint32 drv_rstctl_wd_getSta(void);

/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_kick
*
* DESCRIPTION
*  This function is used to retart wd tiemr
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*************************************************************************/
extern void drv_rstctl_wd_kick(void);

/*************************************************************************
* FUNCTION
*  drv_rstctl_retn_flag_set
*
* DESCRIPTION
*  This function is used to set retention flag
*
* PARAMETERS
*	flag: rst_retn_flag_e
*
* RETURN VALUES
*	none
*************************************************************************/
extern void drv_rstctl_retn_flag_set(rst_retn_flag_e flag);

/*************************************************************************
* FUNCTION
*  drv_rstctl_retn_flag_set
*
* DESCRIPTION
*  This function is used to get retention flag
*
* PARAMETERS
*	none
*
* RETURN VALUES
*	retetion flag value
*************************************************************************/
extern kal_uint16 drv_rstctl_retn_flag_get(void);

/*************************************************************************
* FUNCTION
*  drv_rstctl_retn_flag_set
*
* DESCRIPTION
*  This function is used to clear retention flag
*
* PARAMETERS
*	flag: rst_retn_flag_e
*
* RETURN VALUES
*	none
*************************************************************************/
extern void drv_rstctl_retn_flag_clr(rst_retn_flag_e flag);


/*************************************************************************
* FUNCTION
*  drv_rstctl_retn_data
*
* DESCRIPTION
*  This function is used to read/write retention data
*
* PARAMETERS
*	bRead: 1: read data
*           0: write data
*    pData:
*
* RETURN VALUES
*	none
*************************************************************************/
extern void drv_rstctl_retn_data(kal_bool bRead, kal_uint32 *pData);

/*************************************************************************
*              Following is used by WDT DCL (Driver Common Layer)        *
*************************************************************************/

/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_disable
*
* DESCRIPTION
*  This function is used to disable wd timer
*
* PARAMETERS
*	none
*
* RETURN VALUES
*	none
*************************************************************************/
extern void drv_rstctl_wd_disable(void);

/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_clrSta
*
* DESCRIPTION
*  This function is used to clear wdt status
*
* PARAMETERS
*	none
*
* RETURN VALUES
*	none
*************************************************************************/
extern void drv_rstctl_wd_clrSta(void);

/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_clrSta
*
* DESCRIPTION
*  This function is used to get wd timer interval(uint:512*T(32k))
*
* PARAMETERS
*	none
*
* RETURN VALUES
*	none
*************************************************************************/
extern kal_uint16 drv_rstctl_wd_getInterval(void);

/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_kick
*
* DESCRIPTION
*  This function is used to retart wd tiemr
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*************************************************************************/
extern void drv_rstctl_restartWDT(void);

/*************************************************************************
* FUNCTION
*  drv_rstctl_wdt_setInterval
*
* DESCRIPTION
*  This function is used to set wd tiemr
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*
* NOTE
*    Need to restart wdt timer to apply this value
*************************************************************************/
extern void drv_rstctl_wdt_setInterval(kal_uint32 wdtInterval);

/*************************************************************************
* FUNCTION
*  drv_rstctl_wdt_enable
*
* DESCRIPTION
*  This function is used to on/off wd timer
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*
* NOTE
*    Need to restart wdt timer to apply this value
*************************************************************************/
extern void drv_rstctl_wdt_enable(kal_bool en);

/*************************************************************************
* FUNCTION
*  drv_rstctl_wdt_abnReset
*
* DESCRIPTION
*  This function is used to do abnormal reset
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*
*************************************************************************/
extern void drv_rstctl_wdt_abnReset(void);

/*************************************************************************
* FUNCTION
*  drv_rstctl_wdt_enableInterrupt
*
* DESCRIPTION
*  This function is used to on/off irq mode
*       reset or trigger interrupt while watchdog timout happening
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*
*************************************************************************/
extern void drv_rstctl_wdt_enableInterrupt(kal_bool enable);

/*************************************************************************
* FUNCTION
*  drv_rstctl_wdt_32k_irq_pulse
*
* DESCRIPTION
*  This function is used to on/off 32k interrupt pulse mode
*
*
* PARAMETERS
*    enable 32k interrupt pulse mode (TRUE) or 16T bus clock mode (FALSE)
*
* RETURN VALUES
*	none
*
*************************************************************************/
extern void drv_rstctl_wdt_32k_irq_pulse(kal_bool enable);


/*Legacy part for DCL*/
/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_clrCnt
*
* DESCRIPTION
*  This function is used to clear wdt cnt
*
* PARAMETERS
*	cntMaskToClear
*   0: clear both AP/MD WD Cnt
*   MD_WDCNT_CLR: clear MD WD Cnt
*   AP_WDCNT_CLR: clear AP WD Cnt
*
* RETURN VALUES
*	none
*************************************************************************/
extern void drv_rstctl_wd_clrCnt(kal_uint32 cntMaskToClear);

/*************************************************************************
* FUNCTION
*  drv_rstctl_wdt_enableDebugMode
*
* DESCRIPTION
*  This function is used to on/off debug mode
*
* PARAMETERS
*	cntMaskToClear
*   0: clear both AP/MD WD Cnt
*   MD_WDCNT_CLR: clear MD WD Cnt
*   AP_WDCNT_CLR: clear AP WD Cnt
*
* RETURN VALUES
*	none
*************************************************************************/
extern void drv_rstctl_wdt_enableDebugMode(kal_bool enable);

/*************************************************************************
* FUNCTION
*  drv_rstctl_wdt_init
*
* DESCRIPTION
*  This function is to initialize the WDT module
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*
*************************************************************************/
extern void drv_rstctl_wdt_init(void);

/*************************************************************************
* FUNCTION
*  drv_rstctl_wdt_reset
*
* DESCRIPTION
*  This function is to do wdt reset
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*
*************************************************************************/
extern void drv_rstctl_wdt_reset(void);

#else
#error Not support rstctrl in this chip type

#endif /*MT6290*/


kal_uint32 Get_WATCHDOG_BASE(void);

kal_uint32 Get_WATCHDOG_RESTART_CMD(void);

kal_bool Is_WDT_Init(void);

/*nucleus schedule for WDT restart******************************************/
extern const kal_uint32 g_WATCHDOG_RESTART_REG;
extern const kal_uint32 g_WATCHDOG_RESTART_VALUE;
extern const kal_uint32 g_ABNORMAL_RST_REG;
extern const kal_uint32 g_ABNORMAL_RST_VAL;

#endif /* end of __DRV_RSTCLT_H__ */

