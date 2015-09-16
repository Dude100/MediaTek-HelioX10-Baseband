#ifndef __RSTCTL_REG_H__
#define __RSTCTL_REG_H__

#include <reg_base.h>
#include <irqid.h>

#if defined(MT6290)

/* Register Address Definition */
#define BASE_ADDR_RSTCTL	BASE_ADDR_MDRSTCTL

#define REG_MDRSTCTL_WDTCR              (BASE_ADDR_RSTCTL+0x0100)
#define REG_MDRSTCTL_WDTIR              (BASE_ADDR_RSTCTL+0x0104)
#define REG_MDRSTCTL_WDTRR              (BASE_ADDR_RSTCTL+0x0108)
#define REG_MDRSTCTL_WDTSR              (BASE_ADDR_RSTCTL+0x0134)
#define REG_MDRSTCTL_WDTER_MDON			(BASE_ADDR_RSTCTL+0x010C)
#define REG_MDRSTCTL_WDTER_MDMCU		(BASE_ADDR_RSTCTL+0x0110)
#define REG_MDRSTCTL_WDTER_MDINFRA		(BASE_ADDR_RSTCTL+0x0114)
#define REG_MDRSTCTL_WDTER_LTEL2		(BASE_ADDR_RSTCTL+0x0118)
#define REG_MDRSTCTL_WDTER_MEMSYS		(BASE_ADDR_RSTCTL+0x011C)
#define REG_MDRSTCTL_WDTER_ARM7			(BASE_ADDR_RSTCTL+0x0120)
#define REG_MDRSTCTL_WDTER_APMCU		(BASE_ADDR_RSTCTL+0x0124)
#define REG_MDRSTCTL_WDTER_APPERI		(BASE_ADDR_RSTCTL+0x0128)
#define REG_MDRSTCTL_WDTER_SSUSB		(BASE_ADDR_RSTCTL+0x012C)
#define REG_MDRSTCTL_WDTER_APON			(BASE_ADDR_RSTCTL+0x0130)
#define REG_MDRSTCTL_WDTSR				(BASE_ADDR_RSTCTL+0x0134)

#define REG_MDRSTCTL_SRSTR_MDON         (BASE_ADDR_RSTCTL+0x013C)
#define REG_MDRSTCTL_SRSTR_MDMCU        (BASE_ADDR_RSTCTL+0x0140)
#define REG_MDRSTCTL_SRSTR_MDINFRA      (BASE_ADDR_RSTCTL+0x0144)
#define REG_MDRSTCTL_SRSTR_LTEL2        (BASE_ADDR_RSTCTL+0x0148)
#define REG_MDRSTCTL_SRSTR_MEMSYS       (BASE_ADDR_RSTCTL+0x014C)
#define REG_MDRSTCTL_SRSTR_ARM7         (BASE_ADDR_RSTCTL+0x0150)
#define REG_MDRSTCTL_SRSTR_APMCU        (BASE_ADDR_RSTCTL+0x0154)
#define REG_MDRSTCTL_SRSTR_APPERI       (BASE_ADDR_RSTCTL+0x0158)
#define REG_MDRSTCTL_SRSTR_SSUSB        (BASE_ADDR_RSTCTL+0x015C)
#define REG_MDRSTCTL_SRSTR_APON         (BASE_ADDR_RSTCTL+0x0160)
#define REG_MDRSTCTL_EXTRST		        (BASE_ADDR_RSTCTL+0x0164)
#define REG_MDRSTCTL_RESET_UNLOCK       (BASE_ADDR_RSTCTL+0x0168)


#define REG_MDRSTCTL_SRCMR              (BASE_ADDR_RSTCTL+0x0300)
#define REG_MDRSTCTL_SRCMR_SWDT    		(BASE_ADDR_RSTCTL+0x0304)
#define REG_MDRSTCTL_SRBER_MDON         (BASE_ADDR_RSTCTL+0x0308)
#define REG_MDRSTCTL_SRBER_MDMCU        (BASE_ADDR_RSTCTL+0x030C)
#define REG_MDRSTCTL_SRBER_MDINFRA      (BASE_ADDR_RSTCTL+0x0310)
#define REG_MDRSTCTL_SRBER_LTEL2        (BASE_ADDR_RSTCTL+0x0314)
#define REG_MDRSTCTL_SRBER_MEMSYS       (BASE_ADDR_RSTCTL+0x0318)
#define REG_MDRSTCTL_SRBER_ARM7         (BASE_ADDR_RSTCTL+0x031C)
#define REG_MDRSTCTL_SRBER_APMCU        (BASE_ADDR_RSTCTL+0x0320)
#define REG_MDRSTCTL_SRBER_APPERI       (BASE_ADDR_RSTCTL+0x0324)
#define REG_MDRSTCTL_SRBER_SSUSB        (BASE_ADDR_RSTCTL+0x0328)
#define REG_MDRSTCTL_SRBER_APON         (BASE_ADDR_RSTCTL+0x032C)


#define REG_MDRSTCTL_DUMMY      (BASE_ADDR_MDRSTCTL+0x0040)

#define _RST_DURATION_LOOP_DEFAULT_VALUE	(100)		/* Just a magic number for reset duration */
/**< REG_MDRSTCTL_SRCMR */
#define RSTCTL_SRCMR_KEY_SWDT_MASK			(0xffff)		/* Key of reset command */
#define RSTCTL_SRCMR_KEY_SWDT_OFFSET		(16)
#define RSTCTL_SRCMR_KEY_SWDT				((0x1688 << RSTCTL_SRCMR_KEY_SWDT_OFFSET) | 0x1)	/* Key to enable software watch dog reset */
#define RSTCTL_SRCMR_KEY_SWRST				((0x2593 << RSTCTL_SRCMR_KEY_SWDT_OFFSET) | 0x1)	/* Key to enable software reset */
/**< REG_MDRSTCTL_SRBER */
#define RSTCTL_SRBER_MDON_MASK			(0xFFFFFFFF)		/**< Mask of software reset modules for RSTCTL_SSRR control */
#define RSTCTL_SRBER_SDCTL_RST				(1 << 0)		/**< Soft reset of SDCLT :  */
#define RSTCTL_SRBER_MDGDMA_RST				(1 << 1)		/**< Soft reset of L2COP : only valid for MDARM */
#define RSTCTL_SRBER_USIM0_RST				(1 << 2)		/**< Soft reset of USIM0 : only valid for MDARM */
#define RSTCTL_SRBER_USIM1_RST				(1 << 3)		/**< Soft reset of USIM1 : only valid for MDARM */
#define RSTCTL_SRBER_MDUART_RST				(1 << 4)		/**< Soft reset of UART : only valid for MDARM */
#define RSTCTL_SRBER_SUART0_RST				(1 << 5)		/**< Soft reset of UART : only valid for MDARM */
#define RSTCTL_SRBER_SUART1_RST				(1 << 6)		/**< Soft reset of UART : only valid for MDARM */
#define RSTCTL_SRBER_MDGPTM_RST				(1 << 7)		/**< Soft reset of UART : only valid for MDARM */
//#define RSTCTL_SRBER_MDGPIO_RST				(1 << 8)		/**< Soft reset of UART : only valid for MDARM */
#define RSTCTL_SRBER_MDMISC_RST				(1 << 9)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_MDCIRQ_RST				(1 << 10)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_LED_RST				(1 << 11)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_I2C_RST				(1 << 12)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_SDCTL_CIS_RST			(1 << 13)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_DBGSYS_RST				(1 << 14)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_DBGCV_RST				(1 << 15)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_DBGSIB_RST				(1 << 16)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_GPIOMUX_RST			(1 << 17)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_APTOPSM_RST			(1 << 18)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_MDTOPSM_RST			(1 << 19)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_APOST_RST				(1 << 20)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_MDOST_RST				(1 << 21)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_MDCFGCTL_RST			(1 << 22)		/**< FPGA0827 add  */
#define RSTCTL_SRBER_DRAMC_AO_RST			(1 << 23)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_EMI_AO_RST				(1 << 24)		/**< Soft reset of MISC :  */

//#define RSTCTL_SRBER_NLIPAD_RST				(1 << 22)		/**< Soft reset of MISC :  */

#define RSTCTL_SRBER_ARM7_MASK			(0xC0000003)		/**< Mask of software reset modules for RSTCTL_SSRR control */
#define RSTCTL_SRBER_ARM7_HRST_RST			(1 << 0)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_ARM7_SRST_RST			(1 << 1)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_CAIF_RST				(1 << 2)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_ARM7SYS_RST            (RSTCTL_SRBER_ARM7_HRST_RST|RSTCTL_SRBER_ARM7_SRST_RST|RSTCTL_SRBER_CAIF_RST)


#define RSTCTL_SRBER_LTEL2_MASK			(0xC0000001)		/**< Mask of software reset modules for RSTCTL_SSRR control */
#define RSTCTL_SRBER_LTEL2_RST				(1 << 0)		/**< Soft reset of MISC :  */

#define RSTCTL_SRBER_MEMSYS_MASK		(0xC000003F)		/**< Mask of software reset modules for RSTCTL_SSRR control */
#define RSTCTL_SRBER_DRAMC_RST				(1 << 0)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_EMI_RST				(1 << 1)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_CPHY_RST				(1 << 2)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_DDRPHY_COMB0_RST		(1 << 3)		/**< Soft reset of MISC :  */


#define RSTCTL_SRBER_MDINFRA_MASK		(0xC0000003)		/**< Mask of software reset modules for RSTCTL_SSRR control */
#define RSTCTL_SRBER_MDINFRA_MISC_RST		(1 << 0)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_MDINFRA_BUSMON_RST		(1 << 1)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_BOOTROM_RST			(1 << 2)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_ABM_RST				(1 << 3)		/**< Soft reset of MISC :  */


#define RSTCTL_SRBER_MDMCU_MASK			(0xC00000FF)		/**< Mask of software reset modules for RSTCTL_SSRR control */
#define RSTCTL_SRBER_CR4_DBG_RST			(1 << 0)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_CR4_NRESET_RST			(1 << 1)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_CR4_BUSMON_RST			(1 << 2)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_ALC_RST				(1 << 3)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_PF_RST					(1 << 4)		/**< Soft reset of MISC :  */
//#define RSTCTL_SRBER_MDMCU_MISC_RST			(1 << 5)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_PCMON_FIFO_RST			(1 << 6)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_PCMON_REG_RST			(1 << 7)		/**< Soft reset of MISC :  */



#define RSTCTL_SRBER_APON_MASK			(0xC000000F)		/**< Mask of software reset modules for RSTCTL_SSRR control */
#define RSTCTL_SRBER_AP_RSTMD_RST			(1 << 1)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_MDCLK_RST				(1 << 2)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_APCLK_RST				(1 << 3)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_EFUSE_RST				(1 << 4)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_MML1_RST				(1 << 5)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_MML1OFF_RST			(1 << 6)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_TDD_RST				(1 << 7)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_2G3G_RST				(1 << 8)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_2G3G_DSP_RST			(1 << 9)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_EXT_RST_RST			(1 << 10)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_BSICTL					(1 << 11)
#define RSTCTL_SRBER_RFIC1_BSISPI			(1 << 12)
#define RSTCTL_SRBER_RFIC2_BSISPI			(1 << 13)
#define RSTCTL_SRBER_PMIC_BSISPI			(1 << 14)
#define RSTCTL_SRBER_MIPI0_BSISPI			(1 << 15)
#define RSTCTL_SRBER_MIPI1_BSISPI			(1 << 16)
#define RSTCTL_SRBER_IDC					(1 << 17)
#define RSTCTL_SRBER_MML1_BPICTRL			(1 << 18)
#define RSTCTL_SRBER_MML1_PERISYS_MISC		(1 << 19)
#define RSTCTL_SRBER_MML1_PERI_MBIST_CONFIG	(1 << 20)
#define RSTCTL_SRBER_AUXADC					(1 << 21)
#define RSTCTL_SRBER_MML1_PERISYS11			(1 << 22)
#define RSTCTL_SRBER_MML1_PERISYS12			(1 << 23)
#define RSTCTL_SRBER_MML1_PERISYS13			(1 << 24)
#define RSTCTL_SRBER_MML1_PERISYS14			(1 << 25)
#define RSTCTL_SRBER_MML1_PERISYS_XRESET	(1 << 26)
#define RSTCTL_SRBER_MIXEDSYS				(1 << 27)



#define RSTCTL_SRBER_SSUSB_MASK			(0xC0000001)		/**< Mask of software reset modules for RSTCTL_SSRR control */
#define RSTCTL_SRBER_SSUSB_RST				(1 << 0)		/**< Soft reset of MISC :  */

#define RSTCTL_SRBER_APPERI_MASK		(0xC00DDFFF)		/**< Mask of software reset modules for RSTCTL_SSRR control */
#define RSTCTL_SRBER_APUART_RST				(1 << 0)		/**< Soft reset of SDCLT :  */
#define RSTCTL_SRBER_APCCIF_RST				(1 << 1)		/**< Soft reset of L2COP : only valid for MDARM */
#define RSTCTL_SRBER_CLDMA_RST				(1 << 2)		/**< Soft reset of USIM0 : only valid for MDARM */
#define RSTCTL_SRBER_NFI_RST				(1 << 3)		/**< Soft reset of USIM1 : only valid for MDARM */
#define RSTCTL_SRBER_SF_RST					(1 << 4)		/**< Soft reset of UART : only valid for MDARM */
#define RSTCTL_SRBER_USB_RST				(1 << 5)		/**< Soft reset of UART : only valid for MDARM */
#define RSTCTL_SRBER_IPSEC_RST				(1 << 6)		/**< Soft reset of UART : only valid for MDARM */
#define RSTCTL_SRBER_HIF0_RST				(1 << 7)		/**< Soft reset of UART : only valid for MDARM */
#define RSTCTL_SRBER_PFC_RST				(1 << 8)		/**< Soft reset of UART : only valid for MDARM */
#define RSTCTL_SRBER_NLI_RST				(1 << 9)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_MSDC0P_RST				(1 << 10)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_MSDC1P_RST				(1 << 11)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_APGPTM_RST				(1 << 12)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_APEHPI_RST				(1 << 13)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_APGDMA_RST				(1 << 14)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_AP_BUSMON_RST			(1 << 15)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_AP_MISC_RST			(1 << 16)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_APTZCTL_RST			(1 << 17)		/**< FPGA0827 remove  */
#define RSTCTL_SRBER_ETHER_NIC_RST			(1 << 18)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_TRACE_RST				(1 << 19)		/**< Soft reset of MISC :  */


#define RSTCTL_SRBER_CA7_DBG_RST			(1 << 0)		/**< Soft reset of SDCLT :  */
#define RSTCTL_SRBER_CA7_NRESET_RST			(1 << 1)		/**< Soft reset of L2COP : only valid for MDARM */
#define RSTCTL_SRBER_CA7_BUSMON_RST			(1 << 2)		/**< Soft reset of USIM0 : only valid for MDARM */


#define RSTCTL_SRSTR_MASK					(0x3f0fffff)
/**< REG_MDRSTCTL_WDTCR */
#define RSTCTL_WDTCR_KEY_CONTROL_MASK		(0xff)		/* Key of control setting */
#define RSTCTL_WDTCR_KEY_CONTROL_OFFSET		(24)
#define RSTCTL_WDTCR_KEY					(0x55 << RSTCTL_WDTCR_KEY_CONTROL_OFFSET)
#define RSTCTL_WDTCR_HF_RSTQMU				(1 << 15)	/* Reset QMU or not for host-functional-reset (Only valid in modem configuration) */
#define RSTCTL_WDTCR_WDT_RSTNTY				(1 << 14)	/* Notify HIF or not when watchdog-reset occurs (Only valid in modem configuration) */
#define RSTCTL_WDTCR_RST_TARGET_MASK		(0x1fff)		/* Target mask of watchdog reset (detail definition is in rst_ioctl_wdt_MD_target_e) */
#define RSTCTL_WDTCR_RST_TARGET_OFFSET		(3)
#define RSTCTL_WDTCR_WDT_IRQEN				(1 << 3)		/* Watch dog timer interrupt enable (select "intterrupt" or "reset" when watch dog timeout) */
#define RSTCTL_WDTCR_WDT_EN					(1<< 0)		/* watch dog timer enable */
/**< REG_MDRSTCTL_WDTSR */
#define RSTCTL_WDTSR_KEY_MASK				0xffff		/* Key of status clear */
#define RSTCTL_WDTSR_KEY_OFFSET				16
#define RSTCTL_WDTSR_KEY					(0x7662 << RSTCTL_WDTSR_KEY_OFFSET)
#define RSTCTL_WDTSR_STATUS_MASK			0x1F		/* Watchdog status (detail definition is in rst_ioctl_wdt_status_e) */
#define RSTCTL_WDTSR_STATUS_OFFSET			0
#define RSTCTL_WDTSR_CNT_CLR_MASK		    0x3
#define RSTCTL_WDTSR_CNT_CLR_OFFSET		    6
/**< REG_MDRSTCTL_WDTIR */
#define RSTCTL_WDTIR_KEY_INTV_MASK			0xff		/* Key of interval setting */
#define RSTCTL_WDTIR_KEY_INTV_OFFSET		24
#define RSTCTL_WDTIR_KEY					(0x67 << RSTCTL_WDTIR_KEY_INTV_OFFSET)
#define RSTCTL_WDTIR_INTERVAL_MASK			0x3FFFFF		/* Watch dog timer down count interval (the real interval is 1/32.768k */
#define RSTCTL_WDTIR_INTERVAL_OFFSET		0
/**< REG_MDRSTCTL_WDTRR */
#define RSTCTL_WDTRR_KEY_RESTART_MASK		0xffff		/* Key of watchdog couter restarting */
#define RSTCTL_WDTRR_KEY_RESTART_OFFSET		16
#define RSTCTL_WDTRR_KEY					(0x7208 << RSTCTL_WDTRR_KEY_RESTART_OFFSET)
/**< REG_MDRSTCTL_EXTRST */
#define RSTCTL_EXTRST_KEY					(0x7766 << 16)
#define EXT_WDT_STS                         (1 << 15)
#define EXTRST_OE                           (1 << 1)
#define POLARITY_OFFSET                     0

#elif defined(MT6595) || (defined(MT6752) && defined(__MD1__))

#if defined(MT6595)
#define SW_RST_READ_STATUS_SHITF_8
#endif

#define BASE_MADDR_RSTCTL	(MD_RGU_BASE)


#define REG_WDT_MD_MODE              (BASE_MADDR_RSTCTL+0x0000)
#define REG_WDT_MD_LENGTH            (BASE_MADDR_RSTCTL+0x0004)
#define REG_WDT_MD_RESTART           (BASE_MADDR_RSTCTL+0x0008)
#define REG_WDT_MD_STA               (BASE_MADDR_RSTCTL+0x000C)
#define REG_WDT_SW_DSP_RSTN          (BASE_MADDR_RSTCTL+0x0014)
#define REG_WDT_MD_SWRST             (BASE_MADDR_RSTCTL+0x001C)
#define REG_WDT_SW_GRP0_RST          (BASE_MADDR_RSTCTL+0x0020)
#define REG_WDT_SW_GRP1_RST          (BASE_MADDR_RSTCTL+0x0024)

#define REG_WDT_RETN_FLAG            (BASE_MADDR_RSTCTL+0x0800)
#define REG_WDT_RETN_SET             (BASE_MADDR_RSTCTL+0x0804)
#define REG_WDT_RETN_CLR             (BASE_MADDR_RSTCTL+0x0808)
#define REG_WDT_RETN_DAT0            (BASE_MADDR_RSTCTL+0x0814)


#define RSTCTL_MAX_PERIOD_NUM              (0x7FF)

#define RSTCTL_MD_MODE_KEY             (0x22 << 8)
#define RSTCTL_MD_LENGTH_KEY           (0x8)
#define RSTCTL_RESTART_TIMER_KEY       (0x1971)
#define RSTCTL_MDSYS_SWRST_KEY         (0x1209)
#define RSTCTL_DSP_RST_KEY             (0x22)
#define RSTCTL_GRP0_RST_KEY            (0x5A << 24)
#define RSTCTL_GRP1_RST_KEY            (0x5A << 24)
#define RSTCTL_RETN_FLAG_SET_KEY       (0x4e << 24)

/*REG_WDT_MD_MODE*/
#define	RSTCTL_IRQ_MODE_BIT            (3)
#define	RSTCTL_SEL_32K_BIT             (1)
#define	RSTCTL_WDT_EN_BIT              (0)

/*REG_WDT_MD_LENGTH*/
#define RSTCTL_TIMEOUT_BIT             (5)

/*For easy implementation, move these two definition to drv_rstctl.h*/
/*REG_WDT_MD_STA*/
//#define RSTCTL_STA_WDT_BIT             (15)
//#define RSTCTL_STA_SW_WDT_BIT          (14)

/*REG_WDT_SW_DSP_RSTN*/
#define	RSTCTL_2GDSP_BIT               (15)
/*REG_WDT_SW_GRP0_RST*/
#define	RSTCTL_CLDMA_BIT               (6)
#define	RSTCTL_PCMON_REG_BIT           (5)
#define	RSTCTL_PCMON_FIFO_BIT          (4)
#define	RSTCTL_LTEL2_BIT               (3)
#define	RSTCTL_A7_CCIF_BIT             (2)
#define	RSTCTL_A7_SRST_BIT             (1)
#define	RSTCTL_A7_RSTUNLOCK_BIT        (15)
#define	RSTCTL_A7_HRST_BIT             (0)
/*REG_WDT_SW_GRP1_RST*/
#define	RSTCTL_MML1STS_BIT             (16)
#define	RSTCTL_XRESET_BIT              (15)
#define	RSTCTL_MML1_PERI_MBIST_BIT     (9)
#define	RSTCTL_MML1_PERI_MISC_BIT      (8)
#define	RSTCTL_MML1_BPICTRL_BIT        (7)
#define	RSTCTL_IDC_BIT                 (6)
#define	RSTCTL_MIPI1_BSISPI_BIT        (5)
#define	RSTCTL_MIPI0_BSISPI_BIT        (4)
#define	RSTCTL_PMIC_BSISPI_BIT         (3)
#define RSTCTL_RFIC2_BSISPI_BIT        (2)
#define	RSTCTL_RFIC1_BSISPI_BIT        (1)
#define	RSTCTL_PF_BSICTRL_BIT          (0)


#else
#error Not support rstctrl in this chip type
#endif /*MT6290*/

#endif /* end of __GPT_REG_H__ */

