/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2013
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*****************************************************************************
 *
 * Filename:
 * ---------
 *	  drv_iomux.h
 *
 * Project:
 * --------
 *	 drv_iomux
 *
 * Description:
 * ------------
 *	 This file is intends for iomux driver.
 *
 * Author:
 * -------
 * -------
 *
 *===========================================================
 ******************************************************************************/


#ifndef IOMUX_HW_H
#define IOMUX_HW_H

#include "drv_comm.h"
#include "kal_general_types.h"
#include "kal_debug.h"


#define BASE_ADDR_IOMUX		0xBF8A0000
//#define IOMUX_BASE_ADDR			BASE_ADDR_IOMUX

#define IOMUX_CODA_VERSION		(BASE_ADDR_IOMUX+0x0)		/* Read only */
#define IOMUX_DBG_FLAG_SEL_0	(BASE_ADDR_IOMUX+0x04)
#define IOMUX_DBG_FLAG_SEL_1	(BASE_ADDR_IOMUX+0x08)
#define IOMUX_DBG_MODSEL_0		(BASE_ADDR_IOMUX+0x0C)
#define IOMUX_DBG_MODSEL_1		(BASE_ADDR_IOMUX+0x10)
#define IOMUX_FLAGMON_0			(BASE_ADDR_IOMUX+0x14)
#define IOMUX_FLAGMON_1			(BASE_ADDR_IOMUX+0x18)
#define IOMUX_TOP_DUMMY			(BASE_ADDR_IOMUX+0x1C)
#define IOMUX_TOP_STATUS		(BASE_ADDR_IOMUX+0x20)
#define IOMUX_HSPA_CONFIG		(BASE_ADDR_IOMUX+0x24)
#define IOMUX_MODE_SEL			(BASE_ADDR_IOMUX+0x100)
#define IOMUX_MODE_SEL_0		(BASE_ADDR_IOMUX+0x100)
#define IOMUX_MODE_SEL_1		(BASE_ADDR_IOMUX+0x104)
#define IOMUX_MODE_SEL_2		(BASE_ADDR_IOMUX+0x108)
#define IOMUX_MODE_SEL_3		(BASE_ADDR_IOMUX+0x10C)
#define IOMUX_CFG_GLOBAL		(BASE_ADDR_IOMUX+0x110)
#define IOMUX_CFG_SPITOAHB		(BASE_ADDR_IOMUX+0x114)
#define IOMUX_CFG_CV			(BASE_ADDR_IOMUX+0x118)
#define IOMUX_CFG_SB			(BASE_ADDR_IOMUX+0x11C)
#define IOMUX_CFG_JTAG			(BASE_ADDR_IOMUX+0x120)
#define IOMUX_CFG_SPI_0			(BASE_ADDR_IOMUX+0x124)
#define IOMUX_CFG_SPI_1			(BASE_ADDR_IOMUX+0x128)
#define IOMUX_CFG_NFI_0			(BASE_ADDR_IOMUX+0x12C)
#define IOMUX_CFG_NFI_1			(BASE_ADDR_IOMUX+0x130)
#define IOMUX_CFG_NFI_2			(BASE_ADDR_IOMUX+0x134)
#define IOMUX_CFG_NFI_3			(BASE_ADDR_IOMUX+0x138)
#define IOMUX_CFG_NFI_4			(BASE_ADDR_IOMUX+0x13C)
#define IOMUX_CFG_MDUART		(BASE_ADDR_IOMUX+0x140)
#define IOMUX_CFG_APUART		(BASE_ADDR_IOMUX+0x144)
#define IOMUX_CFG_SUART0		(BASE_ADDR_IOMUX+0x148)
#define IOMUX_CFG_SUART1		(BASE_ADDR_IOMUX+0x14C)
#define IOMUX_CFG_SDIO			(BASE_ADDR_IOMUX+0x150)
#define IOMUX_CFG_MSDC0P_0		(BASE_ADDR_IOMUX+0x154)
#define IOMUX_CFG_MSDC0P_1		(BASE_ADDR_IOMUX+0x158)
#define IOMUX_CFG_MSDC0P_2		(BASE_ADDR_IOMUX+0x15C)
#define IOMUX_CFG_MSDC1P		(BASE_ADDR_IOMUX+0x16C)
#define IOMUX_CFG_PMIC_BSI_0	(BASE_ADDR_IOMUX+0x170)
#define IOMUX_CFG_PMIC_BSI_1	(BASE_ADDR_IOMUX+0x174)
#define IOMUX_CFG_RFIC0_BSI		(BASE_ADDR_IOMUX+0x178)
#define IOMUX_CFG_RFIC1_BSI		(BASE_ADDR_IOMUX+0x17C)
#define IOMUX_CFG_MISC_BSI_0	(BASE_ADDR_IOMUX+0x180)
#define IOMUX_CFG_MISC_BSI_1	(BASE_ADDR_IOMUX+0x184)
#define IOMUX_CFG_I2C			(BASE_ADDR_IOMUX+0x188)
#define IOMUX_CFG_BPI_0			(BASE_ADDR_IOMUX+0x18C)
#define IOMUX_CFG_BPI_1			(BASE_ADDR_IOMUX+0x190)
#define IOMUX_CFG_BPI_2			(BASE_ADDR_IOMUX+0x194)
#define IOMUX_CFG_BPI_3			(BASE_ADDR_IOMUX+0x198)
#define IOMUX_CFG_BPI_4			(BASE_ADDR_IOMUX+0x19C)
#define IOMUX_CFG_BPI_5			(BASE_ADDR_IOMUX+0x1A0)
#define IOMUX_CFG_USIM1			(BASE_ADDR_IOMUX+0x1A4)
#define IOMUX_CFG_USIM2			(BASE_ADDR_IOMUX+0x1A8)
#define IOMUX_CFG_GPIO_0		(BASE_ADDR_IOMUX+0x1AC)
#define IOMUX_CFG_GPIO_1		(BASE_ADDR_IOMUX+0x1B0)
#define IOMUX_CFG_GPIO_2		(BASE_ADDR_IOMUX+0x1B4)
#define IOMUX_CFG_GPIO_3		(BASE_ADDR_IOMUX+0x1B8)
#define IOMUX_CFG_GPIO_4		(BASE_ADDR_IOMUX+0x1BC)
#define IOMUX_CFG_SDIO_INT		(BASE_ADDR_IOMUX+0x1C4)
#define IOMUX_CFG_DDRPHY		(BASE_ADDR_IOMUX+0x1C8)
#define IOMUX_CFG_DMCMDPHY		(BASE_ADDR_IOMUX+0x1CC)
#define IOMUX_BIAS_TUNE			(BASE_ADDR_IOMUX+0x1D0)
#define IOMUX_TOPMISC_DUMMY		(BASE_ADDR_IOMUX+0x1D4)


/*IOMUX_DBG_FLAG_SEL_0*/
#define DBG_FLAG0_SEL			(0x00)
#define DBG_FLAG1_SEL			(0x08)
#define DBG_FLAG2_SEL			(0x10)
#define DBG_FLAG3_SEL			(0x18)

/*IOMUX_DBG_FLAG_SEL_1*/
#define DBG_FLAG4_SEL			(0x00)
#define DBG_FLAG5_SEL			(0x08)
#define DBG_FLAG6_SEL			(0x10)
#define DBG_FLAG7_SEL			(0x18)

/*IOMUX_MODE_SEL_0*/
#define DBG_MOD_SLE0			(0x00)
#define DBG_MOD_SLE1			(0x08)
#define DBG_MOD_SLE2			(0x10)
#define DBG_MOD_SLE3			(0x18)

/*IOMUX_MODE_SEL_1*/
#define DBG_MOD_SLE4			(0x00)
#define DBG_MOD_SLE5			(0x08)
#define DBG_MOD_SLE6			(0x10)
#define DBG_MOD_SLE7			(0x18)

/*IOMUX_FLAGMON_0*/
#define DBG_MON0				(0x00)
#define DBG_MON1				(0x08)
#define DBG_MON2				(0x10)
#define DBG_MON3				(0x18)

/*IOMUX_FLAGMON_1*/
#define DBG_MON4				(0x00)
#define DBG_MON5				(0x08)
#define DBG_MON6				(0x10)
#define DBG_MON7				(0x18)

/*IOMUX_TOP_DUMMY*/
/*IOMUX_TOP_STATUS*/
/*IOMUX_HSPA_CONFIG*/
#define HSPA_DL_TPUT0			(0x00)
#define HSPA_DL_TPUT1			(0x01)
#define HSPA_DL_TPUT2			(0x02)
#define HSPA_UL_TPUT0			(0x03)
#define HSPA_UL_TPUT1			(0x04)
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
#endif

/*IOMUX_BIAS_TUNE*/
#define BPI_BIAS_TUNE			(0x00)
#define NFI0_BIAS_TUNE			(0x04)
#define NFI1_BIAS_TUNE			(0x08)
#define SPI_BIAS_TUNE			(0x0C)
#define GPIO0_BIAS_TUNE			(0x10)
#define GPIO1_BIAS_TUNE			(0x14)
#define MSDC0P_BIAS_TUNE		(0x18)


/*IOMUX_TOPMISC_DUMMY*/
#define SEL_GPIO_0_1			(0x00)
#define SEL_GPIO_2_1			(0x00)
#define SEL_SRCLK_IN			(0x00)
#define SEL_IDC_RXD				(0x00)

/*CFG_XXX register */
#define IOPAD_RDSEL				(0x00)
#define IOPAD_TDSEL				(0x06)
#define IOPAD_DRIVE				(0x0A)

/* CFG_MSDC0P_1 and CFG_MSDC0P_2 */
#define IOPAD_MSDC0_SMT			(0x0D)
#define IOPAD_MSDC0_SR			(0x0E)

/*CFG_SDIO and CFG_MSDC1P*/
#define IOPAD_SDIO_R1			(0x0D)
#define IOPAD_SDIO_R0			(0x0E)
#define IOPAD_SDIO_SMT			(0x0F)
#define IOPAD_SDIO_SR			(0x10)



#define IOMUX_OK    (0)
#define IOMUX_FAIL  (-1)
#define IOMUX_MEM_SIZE 4096

#define EN_IOMUX_PRINTF 1
extern void dbg_print(char *fmt,...);

#if EN_IOMUX_PRINTF
#define IOMUX_PRINT(fmt, var ...)	do {dbg_print(fmt"\n\r", ##var);} while (0)
#define IOMUX_PRINTN(fmt, var ...)	do {dbg_print(fmt, ##var);} while (0)
#define IOMUX_ERR(fmt, var ...)		do {IOMUX_PRINT("ERROR [%s:%d]"fmt, __FUNCTION__, __LINE__, ##var);} while (0)
#define IOMUX_WARN(fmt, var ...)	do {IOMUX_PRINT("WARNING [%s:%d]"fmt, __FUNCTION__, __LINE__, ##var);} while (0)
#else 
#define IOMUX_PRINT(fmt, var ...)	
#define IOMUX_PRINTN(fmt, var ...)	
#define IOMUX_ERR(fmt, var ...)		
#define IOMUX_WARN(fmt, var ...)	
#endif



typedef enum{
/* IOMUX_MODE_SEL_0 */
	sel_nfi_0 = 0,
	sel_nfi_1,
	sel_nfi_2,
	sel_nfi_3,
	sel_nfi_4,
/* IOMUX_MODE_SEL_1 */
	sel_jtag ,
	sel_spi_0,
	sel_spi_1,
	sel_suart0,
	sel_sdio,
	sel_msdc0p_0,
	sel_msdc0p_1,
	sel_msdc0p_2,
	sel_msdc1p,
	sel_pmic_bsi,    //15
/*IOMUX_MODE_SEL_2 */
	sel_rfic1_bsi,
	sel_misc_bsi_0,
	sel_misc_bsi_1,
	sel_i2c,
	sel_bpi_0,
	sel_bpi_1,
	sel_bpi_2,
	sel_bpi_3,
	sel_bpi_4,
	sel_bpi_5,      //25
/*IOMUX_MODE_SEL_3*/
	sel_usim1,
	sel_usim2,
	sel_gpio_0_0,
	sel_gpio_1,
	sel_gpio_2_0,	
	sel_gpio_3,
	sel_gpio_4,
	sel_sdio_int,
	sel_dmcmdphy,  //34
/*IOMUX_TOPMISC_DUMMY*/
	sel_gpio_0_1,
	sel_gpio_2_1,
	sel_srclk_in,
	sel_idc_rxd,  //38
	sel_count    //39
}mod_sel_t;


typedef enum{
	cfg_globle,
	cfg_spitoahb,
	cfg_cv,
	cfg_sb,
	cfg_jtag,
	cfg_spi_0,
	cfg_spi_1,
	cfg_nfi_0,
	cfg_nfi_1,
	cfg_nfi_2,
	cfg_nfi_3,
	cfg_nfi_4,
	cfg_mduart,
	cfg_apuart,
	cfg_suart0,
	cfg_suart1,
	cfg_sdio,
	cfg_msdc0p_0,
	cfg_msdc0p_1,
	cfg_msdc0p_2,
	cfg_reserved0,
	cfg_reserved1,
	cfg_msdc1p,
	cfg_pmic_bsi_0,
	cfg_pmic_bsi_1,
	cfg_rfic0_bsi,
	cfg_misc_bsi_0,
	cfg_misc_bsi_1,
	cfg_i2c,
	cfg_bpi_0,
	cfg_bpi_1,
	cfg_bpi_2,
	cfg_bpi_3,
	cfg_bpi_4,
	cfg_bpi_5,
	cfg_usim1,
	cfg_usim2,
	cfg_gpio_0,
	cfg_gpio_1,
	cfg_gpio_2,
	cfg_gpio_3,
	cfg_gpio_4,
	cfg_sdio_int,
	cfg_ddrphy,
	cfg_dmcmdphy,
	cfg_count
}config_sel_t;


typedef enum{
	normal = 0,
	msdc0p,
	msdc1,
	sdio,
	ddrphy,
	dmcmdphy
}module_type_t;


typedef struct{
	config_sel_t  cfg_sel;
	module_type_t type;
	kal_uint32 rdsel;
	kal_uint32 tdsel;
	kal_uint32 drive;
	kal_uint8 r0;
	kal_uint8 r1;
	kal_uint8 smt;
	kal_uint8 sr;
	
	
}module_conf_t;

typedef struct{
  unsigned int mode0;
  unsigned int mode1;
  unsigned int mode2;
  unsigned int mode3;
  unsigned int mode4;
  unsigned int mode5;
}func_group_t;

/*
 *  @brief     Check the function num is valid or not for IOPAD group . 
 *  @param 
 *		funciton_num:  function mode selection  valid value 0~5;
 *		module_num:  IOPAD group selection, valied value please see enum module_sel;
 *  @return  
 *           0:  is valid setting;
 * 		1: invaild funtion setting;
 */	

extern kal_uint32 IOMUX_funcValid_check(kal_uint32 function_num, mod_sel_t mod_num);


/*
 *  @brief     set IOPAD group to special funciton mode
 *  @param 
 *		funciton_num:  function mode selection  valid value 0~5;
 *		mod_num:  IOPAD group selection, valied value please see enum module_sel;
 *		sip_flag: 		choose the chip is SIP or Non-SIP. 
 *					0: non-sip ; 1: sip
 *  @return  
 */
extern  void IOMUX_set_module_func(kal_uint32 function_num, mod_sel_t mod_num);

/*
 *  @brief     Get the special function mode of the IOPAD group.
 *  @param 
 *		mod_num:  IOPAD group selection, valied value please see enum module_sel;
 *  @return 
 		return the  function mode, valid value 0~5;
 */
extern kal_uint32 IOMUX_get_module_func(mod_sel_t module_num);


/*****************************************************************
*some fields control the IOPAD behavior when these IOPAD groups operate in non F0 mode.
*
******************************************************************/

extern void IOMUX_init(void);
extern void IOMUX_set_moduleconfig(module_conf_t* cfg);
extern module_conf_t* IOMUX_get_moduleconfig(config_sel_t cfg_sel, module_type_t  type);

#define CONFIG_ADDR(cfg_sel)			   ((kal_uint32)BASE_ADDR_IOMUX + 0x110 +  cfg_sel*0x04)
#define IOMUX_set_module_drive(cfg_sel, data) DRV_WriteReg32(CONFIG_ADDR(cfg_sel), ((DRV_Reg32(CONFIG_ADDR(cfg_sel)) & 0x03FF)| (data<<IOPAD_DRIVE)))
#define IOMUX_set_msdc_drive(cfg_sel, data)   DRV_WriteReg32(CONFIG_ADDR(cfg_sel), ((DRV_Reg32(CONFIG_ADDR(cfg_sel)) & 0x1E3FF)| (data<<IOPAD_DRIVE)))
#define IOMUX_set_module_tdsel(cfg_sel, data) DRV_WriteReg32(CONFIG_ADDR(cfg_sel), ((DRV_Reg32(CONFIG_ADDR(cfg_sel)) & 0x0C3F)| (data<<IOPAD_TDSEL)))
#define IOMUX_set_msdc_tdsel(cfg_sel, data)   DRV_WriteReg32(CONFIG_ADDR(cfg_sel), ((DRV_Reg32(CONFIG_ADDR(cfg_sel)) & 0x1FC3F)| (data<<IOPAD_TDSEL)))
#define IOMUX_set_module_rdsel(cfg_sel, data) DRV_WriteReg32(CONFIG_ADDR(cfg_sel), ((DRV_Reg32(CONFIG_ADDR(cfg_sel)) & 0x0FC0)| (data<<IOPAD_RDSEL)))
#define IOMUX_set_msdc_rdsel(cfg_sel, data)   DRV_WriteReg32(CONFIG_ADDR(cfg_sel), ((DRV_Reg32(CONFIG_ADDR(cfg_sel)) & 0x1FFC0)| (data<<IOPAD_TDSEL)))
#define IOMUX_set_msdc0_smt(cfg_sel, data)    DRV_WriteReg32(CONFIG_ADDR(cfg_sel), ((DRV_Reg32(CONFIG_ADDR(cfg_sel)) & 0x5FFF)| (data<<IOPAD_MSDC0_SR)))
#define IOMUX_set_msdc0_sr(cfg_sel, data)     DRV_WriteReg32(CONFIG_ADDR(cfg_sel), ((DRV_Reg32(CONFIG_ADDR(cfg_sel)) & 0x3FFF)| (data<<IOPAD_MSDC0_SMT)))
#define IOMUX_set_sdio_r1(cfg_sel, data)      DRV_WriteReg32(CONFIG_ADDR(cfg_sel), ((DRV_Reg32(CONFIG_ADDR(cfg_sel)) & 0x1DFFF)| (data<<IOPAD_SDIO_R1)))
#define IOMUX_set_sdio_r0(cfg_sel, data)      DRV_WriteReg32(CONFIG_ADDR(cfg_sel), ((DRV_Reg32(CONFIG_ADDR(cfg_sel)) & 0x1BFFF)| (data<<IOPAD_SDIO_R0)))
#define IOMUX_set_sdio_smt(cfg_sel, data)     DRV_WriteReg32(CONFIG_ADDR(cfg_sel), ((DRV_Reg32(CONFIG_ADDR(cfg_sel)) & 0x17FFF)| (data<<IOPAD_SDIO_SMT)))
#define IOMUX_set_sdio_sr(cfg_sel, data)      DRV_WriteReg32(CONFIG_ADDR(cfg_sel), ((DRV_Reg32(CONFIG_ADDR(cfg_sel)) & 0x0FFFF)| (data<<IOPAD_SDIO_SR)))
#define IOMUX_set_ddrphy_cfg(data)			  DRV_WriteReg32((kal_uint32)BASE_ADDR_IOMUX+0x1c8, data)
#define IOMUX_set_dmcmdphy_cfg(data)		  DRV_WriteReg32((kal_uint32)BASE_ADDR_IOMUX+0x1cc, data)




#define IOMUX_get_module_drive(cfg_sel) ((DRV_Reg32(CONFIG_ADDR(cfg_sel))>>10) & 0x3)
#define IOMUX_get_msdc_drive(cfg_sel)   ((DRV_Reg32(CONFIG_ADDR(cfg_sel))>>10) & 0x7)
#define IOMUX_get_module_tdsel(cfg_sel) ((DRV_Reg32(CONFIG_ADDR(cfg_sel))>>6) & 0x0F)
#define IOMUX_get_msdc_tdsel(cfg_sel)   ((DRV_Reg32(CONFIG_ADDR(cfg_sel))>>6) & 0x0F)
#define IOMUX_get_module_rdsel(cfg_sel) (DRV_Reg32(CONFIG_ADDR(cfg_sel)) && 0x3F)
#define IOMUX_get_msdc_rdsel(cfg_sel)   (DRV_Reg32(CONFIG_ADDR(cfg_sel)) && 0x3F)

#define IOMUX_get_msdc0_smt(cfg_sel)	((DRV_Reg32(CONFIG_ADDR(cfg_sel))>>0x0D) & 0x1)
#define IOMUX_get_msdc0_sr(cfg_sel)    ((DRV_Reg32(CONFIG_ADDR(cfg_sel))>>0x0E) & 0x1)


#define IOMUX_get_sdio_r0(cfg_sel)		((DRV_Reg32(CONFIG_ADDR(cfg_sel))>>0x0E) & 0x1)
#define IOMUX_get_sdio_r1(cfg_sel)		((DRV_Reg32(CONFIG_ADDR(cfg_sel))>>0x0D) & 0x1)
#define IOMUX_get_sdio_sr(cfg_sel)		((DRV_Reg32(CONFIG_ADDR(cfg_sel))>>0x10) & 0x1)
#define IOMUX_get_sdio_smt(cfg_sel)		((DRV_Reg32(CONFIG_ADDR(cfg_sel))>>0x0F) & 0x1)
#define IOMUX_get_ddrphy_cfg()			(DRV_Reg32((kal_uint32)BASE_ADDR_IOMUX+0x1c8) &0x0F)
#define IOMUX_get_dmcmdphy_cfg()		(DRV_Reg32((kal_uint32)BASE_ADDR_IOMUX+0x1cc) &0x0F)


#ifndef DRV_SetReg3
#define DRV_SetReg3(addr,offset,data) DRV_WriteReg32(addr, ((DRV_Reg32(addr) & ~(0x7<<offset))|(data << offset)))
#endif


#endif /*IOMUX_HW_H*/

