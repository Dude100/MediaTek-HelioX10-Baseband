/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
 *   bl_Init.c
 *
 * Project:
 * --------
 *   Bootloader
 *
 * Description:
 * ------------
 *   This file defines the initialization functions of bootloader
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_general_types.h"
//Special workaround for RHR: include init.h first to get correct PDN address
#include "init.h"
#include "config_hw.h"
#include "reg_base.h"
#include "bl_MTK_BB_REG.H"
#include "bl_INIT.H"
#include "bl_common.h"
#include "bl_features.h"
#include "bl_custom.h"
#include "bl_loader.h"
#include "bl_sectiondef.h"

#include "br_time_stamp.h"
#ifdef __TIME_STAMP__ 
#include "br_time_stamp_cb.h"
#include "bl_time_stamp_id.h"
#endif

#if defined(__ARMCC_VERSION)
#include <rt_misc.h>   /* for __rt_lib_init() */
#endif

#include "SST_secure.h"

//#include "init.h"
#include "feature_def.h"
#include "dcl.h"
#include "dcl_gpio.h"
#include "dcl_f32k_clk.h"
#include "pll.h"
#include "drvpdn.h"

#ifdef __SV5_ENABLED__
#include "bl_GFH_body.h"
#include "br_GFH_file_info.h"
#include "br_GFH_arm_bl_info.h"
#include "br_GFH_maui_info.h"
#include "br_GFH.h"
#include "maui_GFH_body.h"
#include "br_bl_param.h"
#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)
#include "br_GFH_emi_list.h"
#endif
#endif /* __SV5_ENABLED__ */

#ifdef __LCD_DRIVER_IN_BL__
#include "device.h"
#endif /* __LCD_DRIVER_IN_BL__ */

/*************************************************************************
 * Macro and const definition
 *************************************************************************/
#define REMAPPING_MASK (custom_RAM_baseaddr()-1)

/*************************************************************************
 * Structure definition
 *************************************************************************/
typedef struct 
{
    kal_uint32 size;
    kal_uint32 payload[8];
} BL_SWB_STRUCT;

typedef enum
{
   BL_LCD_UNINIT       = 0x00000000,
   BL_LCD_INITED       = 0x00000001,
   BL_LCD_BACKLIGHT_ON = 0x00000002
} E_BL_LCD_STATUS;

/*************************************************************************
 * External reference definition
 *************************************************************************/

#ifdef __LCD_DRIVER_IN_BL__
extern kal_bool custom_uem_gpio_set_level(kal_uint8 gpio_dev_type, kal_uint8 gpio_dev_level);
/* LCD HW init related functions */
extern void PWM_initialize(void);

#endif /* __LCD_DRIVER_IN_BL__ */

extern kal_int8 custom_setEMI(void);
extern kal_int8 custom_setAdvEMI(void);
extern kal_int8 custom_setSFI(void);
extern kal_int8 custom_setAdvSFI(void);

extern void NFIReconfigure2(void);
extern kal_uint32 SST_Get_MAUI_Paired_Version(kal_uint32 rom_base);
extern kal_uint32 SST_Get_MAUI_Feature_Combination(kal_uint32 rom_base, kal_uint32 *pFeatureCombination);
extern kal_uint32 SwitchToLogicalFTL();

extern void HW_wait_32k_start(void);
extern void HW_TDMA_Start(void);

extern void lpwr_init(void);
extern void DRVPDN_ini(void);
extern void BL_Raise_Charger_Current(void);

extern void pmic_swReset();
extern void L1D_Xmode_Latch();

extern const LOG_LEVEL bootloader_debug_level;

#ifdef __SV5_ENABLED__
extern GFH_MAUI_INFO_v1 *bl_GetMAUIInfo(void);
#endif

/*************************************************************************
 * Forward declearaion
 *************************************************************************/

/*************************************************************************
 * Global variables definition
 *************************************************************************/

__bl_resv_region__ BL_SWB_STRUCT g_bl_swb_struct = {sizeof(BL_SWB_STRUCT)-4};

ECO_VERSION eco_version = (ECO_VERSION)(0xff); /* only used in PLL setup, force it to be in RW */

#ifdef __LCD_DRIVER_IN_BL__
E_BL_LCD_STATUS g_lcd_status = BL_LCD_UNINIT;
#endif /* __LCD_DRIVER_IN_BL__ */

/*************************************************************************
 * Main code
 *************************************************************************/

/**********************************************************
Description : Setting MCU PLL.
Input       : None
Output      : None
***********************************************************/
void INT_RestorePLL(void)
{

}

/**********************************************************
Description : Restart watchdog counter.
Input       : None
Output      : None
***********************************************************/

void WacthDogRestart(void)
{
   *(volatile kal_uint32 *)(WDT_RESTART) = WDT_RESTART_CMD;
}

/**********************************************************
Description : Disable watchdog counter.
Input       : None
Output      : None
***********************************************************/

void WacthDogDisable(void)
{
   *(volatile kal_uint32 *)(WDT_MODE) = WDT_DISABLE_CMD;
}

/**********************************************************
Description : Trigger Software Reset
Input       : None
Output      : None
***********************************************************/
void WatchDogResetAll(void)
{
   *(volatile kal_uint16 *)(WDT_SWRST) = WDT_SWRST_CMD;
   while(1);
}

#ifdef __MINI_BOOTLOADER__

/**********************************************************
Description : Wait for 32KHz clock srouce stable.
Input       : None
Output      : None
***********************************************************/
void WaitFor32KStable(void)
{
#if ( defined(MT6516) && defined(__APPLICATION_PROCESSOR__) ) || defined(MT6270A)

   return;

#else /* MT6516 && __APPLICATION_PROCESSOR__ */

   kal_uint32 i;


   /* 32K calibration */
   HW_TDMA_Start();
   for (i = 0; i < 1000; i++) {
   }
   HW_wait_32k_start();

#endif /* MT6516 && __APPLICATION_PROCESSOR__ */

}

/*************************************************************************
* FUNCTION SYMBOL
*  pmu6276_efuse_calibration_bl
*
* DESCRIPTION
*  API to do pmu setting for 76
*
*************************************************************************/
#if defined(MT6276)
void pmu6276_efuse_calibration_bl(void)
{
   // E-FUSE calibration
   kal_uint32 val32;
   kal_uint16 val16;
   
   // 1. *(BASE+0x104)[7:4]   RG_STRUP_IREF_TRIM (4b)
   val32 = *(volatile kal_uint32 *)(EFUSE_base+0x104);
   
   // 2. *(BASE+0x104)[21]         RG_VPROC_VFBADJ enable (1b)
   //     *(BASE+0x104)[20:16]         RG_VPROC_VFBADJ (5b)
   if (val32 & 0x00200000) // Bit28: Trim enable bit
   {
      val16 = (kal_uint16)((val32 & 0x001f0000)>>16); 
   }
   else
   {
      val16 = 7;
   }
   
   //PMU_DRV_SetData16(0x81150940, 0x01f0, val16<<4);   
   *(volatile kal_uint16 *)(0x81150940) = ((*(volatile kal_uint16 *)(0x81150940)) & (~0x01f0)) | (val16<<4);   
   
   //dummy loop for 50us at least
   for(val32=0; val32<2000; val32++)
   {
      ;
   }
}
#endif /* MT6276 */

/**********************************************************
Description : initialization of internal RAM/mpu/HW
Input       : None
Output      : None
***********************************************************/
void PreInit(void)
{
   
#if defined(MT6276)
   //Power on MM sysram
   *(volatile kal_uint32*)(MMSYS_CONFG_base+0x0344) = 0x00000002;

   pmu6276_efuse_calibration_bl();

#endif

#if defined(__CR4__)
   CachePreInitMini();
#endif /* __CR4__ */

}

/**********************************************************
Description : Device initialization according to definition.
Input       : None
Output      : None
***********************************************************/
void NFIDriverInit(void)
{
#if defined(_NAND_FLASH_BOOTING_)
#if defined(MT6236) || defined(MT6236B)
   //Carlos: Bootloader turns on the NFI power as temp sol since the driver got wrong address of PDN
   PDN_CLR(PDN_NFI);
#endif

#ifndef __NFI_SHARED_DRV__
   /* Without bootloader header, we have no idea about the characteristic of mounted NAND flash. */
   NFIReconfigure();
#endif

#if defined(MT6255) && defined(__NFI_SHARED_DRV__)
   #define MCU_SFC_CTRL_SET 		((volatile kal_uint32*)(CONFIG_base+0x61C))
   *MCU_SFC_CTRL_SET	&= ~0x20;	//Disable NLD share with SF.
#endif

#endif

   // Disable power-down control of DMA
#ifndef __OLD_PDN_ARCH__
   PDN_CLR(PDN_DMA);
#elif defined(MT6235) || defined(MT6235B) 
   *(volatile kal_uint16 *)(DRVPDN_CON0_CLR) = DRVPDN_CON0_DMA;
#elif defined(MT6268) || defined(MT6268T)
   *(volatile kal_uint16 *)(CG_CLR0) = CG_CON0_DMA;
#endif

}

__emiinitrw__ static kal_bool isUSBMetaFromBootROM = KAL_FALSE;

__emiinitcode__ kal_bool BL_Init_isUSBMetaFromBootROM(void)
{
   return isUSBMetaFromBootROM;
}

__emiinitcode__ void SetPLLEMI(void *pParam)
{
#ifdef __MTK_INTERNAL__   
   kal_int32 i;
   const kal_char EMI_PLL_INIT_STR[] = "EMI/PLL Init\r\n";
#ifdef MT6280_S00
   const kal_char GLITCH_STR[] = "Switch to single ended 26Mhz\n\r";
#endif /* MT6280_S00 */
#endif /* __MTK_INTERNAL */

   pll_init_mode pllInitMode = PLL_MODE_MAUI;
   
   pmic_swReset();
   
#ifdef MT6280_S00
#ifdef __MTK_INTERNAL__   
   for(i=0; i<sizeof(GLITCH_STR); i++)
   {
      PutUARTByte(GLITCH_STR[i]);
   }
#endif /* __MTK_INTERNAL */

   // 26MHz glitch debug code -->   
   *(volatile kal_uint32 *)(0xA00C0020) |= 0x00000010;
   // 26MHz glitch debug code <--
#endif /* MT6280_S00 */

   TS_BEGIN(TSID_BL_SET_PLLEMI);

   //Here we only restart WDT. WDT will be disabled if necessary when features are initiated
   WacthDogRestart();

   isUSBMetaFromBootROM = KAL_FALSE;

#ifdef __SV5_ENABLED__

   if(((BL_Param_v3*)(pParam))->m_brom_flags & BL_PARAM_USB_COM_ENABLED)
   {
      pllInitMode = PLL_MODE_USB_META;
      isUSBMetaFromBootROM = KAL_TRUE;
   }

#endif /* __SV5_ENABLED__ */

#if defined(MT6280)

#ifdef __MTK_INTERNAL__   
   for(i=0; i<sizeof(EMI_PLL_INIT_STR); i++)
   {
      PutUARTByte(EMI_PLL_INIT_STR[i]);
   }
#endif /* __MTK_INTERNAL */

   TS_BEGIN(TSID_BL_SET_EMI);
   custom_setEMI();
   custom_setSFI();
   TS_END(TSID_BL_SET_EMI);   

   TS_BEGIN(TSID_BL_SET_PLL);
   INT_SetPLL(pllInitMode);
   TS_END(TSID_BL_SET_PLL);

   TS_BEGIN(TSID_BL_SET_ADVEMI);
   custom_setAdvEMI();
   custom_setAdvSFI();
   TS_END(TSID_BL_SET_ADVEMI);      

#else

#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)
   TS_BEGIN(TSID_BL_SET_PLL);
   INT_SetPLL(pllInitMode);
   TS_END(TSID_BL_SET_PLL);

   TS_BEGIN(TSID_BL_SET_EMI);
   custom_setEMI();
   TS_END(TSID_BL_SET_EMI);   
#else   
   if (BlFeatureCombination() & MAUI_FC_NOR_FLASH_BOOTING)
   {
      INT_SetPLL(pllInitMode);
      custom_setEMI();
   }
   else
   {
      custom_setEMI();

#if defined(MT6253L_S01) || defined(MT6252) || defined(__SERIAL_FLASH_EN__)
      custom_setSFI();
#endif

      INT_SetPLL(pllInitMode);

#if defined(MT6253) || defined(MT6236) || defined(MT6236B) || defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252) || defined(MT6276) || defined(MT6256)
      TS_BEGIN(TSID_BL_SET_ADVEMI);
      custom_setAdvEMI();
      TS_END(TSID_BL_SET_ADVEMI);      
#endif

#if defined(MT6253L_S01) || defined(MT6252) || defined(MT6251) || defined(__SERIAL_FLASH_EN__)
      TS_BEGIN(TSID_BL_SET_ADVEMI);
      custom_setAdvSFI();
      TS_END(TSID_BL_SET_ADVEMI);  
#endif
   }
#endif

#endif /* MT6255 and new EMI flow */

   TS_END(TSID_BL_SET_PLLEMI);
}

void Init32KSource(void)
{
   *((volatile unsigned short*)(GPIO_base+0x1604)) |= 0x0040;                 // switch to PWMC mode
   *((volatile unsigned int*)(0x810D0000+0x0320)) = 0x0100;                   // Enable PWM clock gating
   *((volatile unsigned int*)(0x80180000+0x0090)) = 0x3A05;                   // PWM3_CON
   *((volatile unsigned int*)(0x80180000+0x00B0)) = 0x3FFF8000;               // PWM3_SEND_DATA0
   *((volatile unsigned int*)(0x80180000+0x00B4)) = 0x00000000;               // PWM3_SEND_DATA1
   *((volatile unsigned int*)(0x80180000+0x0000)) = 0x4;                      // PWM_ENABLE
}

kal_bool With32KCrystal(void)
{
#if defined(MT6276)
   if(INT_ChipName() == CHIP_MT6276M)
   {
      //GPIO_MODE to GPIO
      *((volatile unsigned short*)(GPIO_base+0x1E00)) &= (~0x7000); 

      //GPIO_DIR to IN
      *((volatile unsigned short*)(GPIO_base+0x0100)) &= (~0x0400); 

      //GPIO_PULLEN
      *((volatile unsigned short*)(GPIO_base+0x0300)) |= 0x7000; 

      //GPIO_PULLSEL
      *((volatile unsigned short*)(GPIO_base+0x0500)) |= 0x7000; 
      
      //GPIO DIN
      if((*((volatile unsigned short*)(GPIO_base+0x0B00)) & 0x0400) == 0)
      {
         return KAL_FALSE;
      }
   }
#endif

   return KAL_TRUE;
}

void TimeStampInit(void)
{
#ifdef __TIME_STAMP__

   WacthDogRestart();
   
   if(With32KCrystal())
   {
      DclF32K_Initialize();

      WaitFor32KStable();
   }
   else
   {  
      Init32KSource();
   }
   
   WacthDogRestart();

   TS_Init(KAL_TRUE);

   TS_BEGIN(TSID_BL_TOTAL);
   TS_BEGIN(TSID_BL_BOOTLOADER);

#endif
}

void Init(kal_uint32 random_seed, kal_uint32 param)
{
   extern kal_uint32 g_randomSeed;
   extern kal_bool SST_SWB_Init(kal_uint32 *pBootloader);
#if defined(MT6256)
   extern kal_uint8  g_emi_param[2];
#endif

#if defined(__CRYPTO_SHARED_DRV__)
   kal_uint32 sss_init_param = 0;
#endif /* __CRYPTO_SHARED_DRV__ */

   TS_BEGIN(TSID_BL_INIT);

   //Init UART
   uart_init();

   set_debug_level(bootloader_debug_level);
   
   BL_PRINT(LOG_INFO, "Init Start\n\r");

   //32K
   WacthDogRestart();
   
   if(With32KCrystal())
   {
      DclF32K_Initialize();

      WaitFor32KStable();
      
   }
   else
   {  
      Init32KSource();
   }
   
   WacthDogRestart();

   //Init PDN
#if !defined(__16_3_SEG__) && !defined(__32_32_SEG__) && !defined(__BRINGUP_SUPPORT__) && !defined(MT6250)
   /* PDN control initialization */
   lpwr_init();
   DRVPDN_ini();
#endif /* !__16_3_SEG__ && !__32_32_SEG__  && !__BRINGUP_SUPPORT__ && !MT6250 */

   //Init NFI
#if !defined(_NAND_FLASH_BOOTING_) && !defined(__EMMC_BOOTING__)
   if (BlFeatureCombination() & MAUI_FC_NOR_FLASH_BOOTING)
#endif
   {
      NFIDriverInit();
   }

   //Init bootloader internal service & dummy reference
   g_randomSeed = random_seed;

   //EMI owner requested. Only for 6256
#if defined(MT6256)
   __EMI_StoreEmiData(g_emi_param);
#endif

   bl_print(LOG_NONE, "", g_bl_swb_struct.size);

#ifdef __SV5_ENABLED__
   {
      extern BL_Param_v3 *g_pBROM_BL_Param;
      extern kal_bool g_bromCmdModeDisabled;
      
      g_pBROM_BL_Param = (BL_Param_v3*)param;
#if defined(__CRYPTO_SHARED_DRV__)
      sss_init_param = g_pBROM_BL_Param->m_sd_crypto_lib_tbl_addr;
#endif /* __CRYPTO_SHARED_DRV__ */

      g_bromCmdModeDisabled = bl_Is_Brom_Cmd_Mode_Disabled();
      
      DummyReference();
   }

#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)
   {
      //Temp dummy reference
      extern const GFH_EMI_LIST_v5 EMI_INFO_2;
      bl_print(LOG_NONE, "", &EMI_INFO_2);
   }
#endif /* _NAND_FLASH_BOOTING_ || __EMMC_BOOTING__ */

#endif /* __SV5_ENABLED__ */

   //Init feature-related services
#if !defined(__16_3_SEG__) && !defined(__BRINGUP_SUPPORT__)

#if defined(__CRYPTO_SHARED_DRV__)
   SSS_Init_Share_Crypto_Drv(TS_RECORD_FUNC, TS_INFO_FUNC, sss_init_param);
#else
   SSS_Init_Crypto_Drv(TS_RECORD_FUNC, TS_INFO_FUNC);
#endif /* __CRYPTO_SHARED_DRV__ */

   {
#ifdef __SV5_ENABLED__
      extern kal_uint32 Image$$BL_GFH_SECTION$$Base;
      SST_SWB_Init((kal_uint32*)&Image$$BL_GFH_SECTION$$Base);
#else
      extern kal_uint32 Image$$READ_ONLY$$Base;
      SST_SWB_Init((kal_uint32*)&Image$$READ_ONLY$$Base);
#endif
   }

#endif /* !__16_3_SEG__ && !__BRINGUP_SUPPORT__ */

	// Switch GPIO 99 for RF
	L1D_Xmode_Latch();


   BL_PRINT(LOG_INFO, "Init done, %x\n\r", g_randomSeed);
   TS_END(TSID_BL_INIT);

#ifdef MT6276
   TS_BEGIN(TSID_BL_INIT2);
   evb_fail_detection();
   TS_END(TSID_BL_INIT2);   
#endif /* MT6276 */

}

#endif /* __MINI_BOOTLOADER__ */

kal_uint32 BlFeatureCombination(void)
{
#ifndef __SV5_ENABLED__
   return g_ExtBootloaderInfo.m_feature_combination;
#else

#ifdef __MINI_BOOTLOADER__
   return g_bootloader_gfh.gfh_arm_bl_info.m_feature_combination;
#else
   return g_ext_bootloader_gfh.gfh_arm_bl_info.m_feature_combination;
#endif

#endif /* __SV5_ENABLED__ */
   return 0;
}


#ifdef __EXT_BOOTLOADER__

void InitFPU(void)
{
#if defined (__ARM_FPUV2__)
   extern kal_uint32 cp15_enable_cp(void);
   extern void set_fpu_runfastmode(void);
   extern void enable_arm_fpu(void);

   cp15_enable_cp();
   enable_arm_fpu();
   set_fpu_runfastmode();
#endif
}

void ShutDownModule(void)
{
#if defined(MT6250)
   PDN_SET(PDN_ROM);
#endif
}

#if defined(__USB_DOWNLOAD__) || defined(__UART_DOWNLOAD__)
void InitUSBDLGPIO(void)
{
#ifdef __CUST_NEW__    
   if ( gpio_usbdl_pin != NO_USBDL_GPIO )
   {
      DCL_HANDLE handle;
      handle = DclGPIO_Open(DCL_GPIO, gpio_usbdl_pin);
      
      //GPIO_ModeSetup( gpio_usbdl_pin, 0 );
      DclGPIO_Control(handle, GPIO_CMD_SET_MODE_0, 0);
      
      //GPIO_InitIO( 0, gpio_usbdl_pin );
      DclGPIO_Control(handle, GPIO_CMD_SET_DIR_IN, 0);
      
      //GPIO_PullenSetup(gpio_usbdl_pin, KAL_TRUE);
      DclGPIO_Control(handle, GPIO_CMD_ENABLE_PULL, 0);
      
      //GPIO_PullSelSetup(gpio_usbdl_pin, KAL_TRUE);
      DclGPIO_Control(handle, GPIO_CMD_SET_PULL_HIGH, 0);
      
      DclGPIO_Close(handle);
   }
#endif /* __CUST_NEW__ */   
}
#endif /* __USB_DOWNLOAD__ || __UART_DOWNLOAD__ */

#if defined(__USB_DOWNLOAD__) || defined(__UART_DOWNLOAD__) || defined(__CARD_DOWNLOAD__)

void SwitchGPIOToKeypad(kal_uint8 keypadPin, kal_uint8 setModeCmd, kal_bool setPullEn)
{
   DCL_HANDLE handle;

   if(keypadPin != 0xff)
   {
      handle = DclGPIO_Open(DCL_GPIO, keypadPin);
      
      DclGPIO_Control(handle, setModeCmd, NULL);
      
      if(setPullEn)
      {
         DclGPIO_Control(handle, GPIO_CMD_ENABLE_PULL, NULL);
         DclGPIO_Control(handle, GPIO_CMD_SET_PULL_HIGH, NULL);
      }
      
      DclGPIO_Close(handle);
   }
}

void InitKeypadGPIO(void)
{
#ifdef __CUST_NEW__

#define KEYPAD_GPIO_INIT(x, pullEn) \
{\
    extern const kal_uint8 gpio_keypad_##x##_pin;\
    extern const kal_uint8 gpio_keypad_##x##_pin_M_DEFAULT;\
       SwitchGPIOToKeypad(gpio_keypad_##x##_pin, gpio_keypad_##x##_pin_M_DEFAULT, pullEn);\
}
      
   KEYPAD_GPIO_INIT(col0, KAL_TRUE);
   KEYPAD_GPIO_INIT(col1, KAL_TRUE);
   KEYPAD_GPIO_INIT(col2, KAL_TRUE);
   KEYPAD_GPIO_INIT(col3, KAL_TRUE);
   KEYPAD_GPIO_INIT(col4, KAL_TRUE);
   KEYPAD_GPIO_INIT(col5, KAL_TRUE);
   KEYPAD_GPIO_INIT(col6, KAL_TRUE);
   KEYPAD_GPIO_INIT(col7, KAL_TRUE);
   KEYPAD_GPIO_INIT(col8, KAL_TRUE);
   KEYPAD_GPIO_INIT(col9, KAL_TRUE);

   KEYPAD_GPIO_INIT(row0, KAL_FALSE);
   KEYPAD_GPIO_INIT(row1, KAL_FALSE);
   KEYPAD_GPIO_INIT(row2, KAL_FALSE);
   KEYPAD_GPIO_INIT(row3, KAL_FALSE);
   KEYPAD_GPIO_INIT(row4, KAL_FALSE);
   KEYPAD_GPIO_INIT(row5, KAL_FALSE);
   KEYPAD_GPIO_INIT(row6, KAL_FALSE);
   KEYPAD_GPIO_INIT(row7, KAL_FALSE);
   KEYPAD_GPIO_INIT(row8, KAL_FALSE);
   KEYPAD_GPIO_INIT(row9, KAL_FALSE);
    
#endif

}

#endif /* __USB_DOWNLOAD__ || __UART_DOWNLOAD__ || __CARD_DOWNLOAD__ */

void InitExt(void)
{
   TS_BEGIN(TSID_BL_EXT_INIT);

#ifdef _NAND_FLASH_BOOTING_      
   NFIReconfigure2();
#endif /* _NAND_FLASH_BOOTING_ */

#if defined(__USB_DOWNLOAD__) || defined(__UART_DOWNLOAD__)
   InitUSBDLGPIO();
#endif /* __USB_DOWNLOAD__  || __UART_DOWNLOAD__ */   

#if defined(__USB_DOWNLOAD__) || defined(__UART_DOWNLOAD__) || defined(__CARD_DOWNLOAD__)
   InitKeypadGPIO();
#endif /* __USB_DOWNLOAD__  || __UART_DOWNLOAD__ ||__CARD_DOWNLOAD__ */

#if defined(__CARD_DOWNLOAD__) && defined(__NANDFDM_TOTAL_BBM__)
   Custom_NAND_Init();
#endif /* __CARD_DOWNLOAD__ */

//PMU owner confirmd that new chips always have this. (MT6256 is the first one)
//Only disable it on older chips and remove them when phased out
#if ! (defined(MT6235) || defined(MT6235B) || defined(MT6268) || defined(MT6268A) || defined(TK6516) || defined(TK6270) || \
       defined(MT6236) || defined(MT6236B) || defined(MT6253) || defined(MT6253T) || defined(MT6253E) || defined(MT6253L) || \
       defined(MT6252) || defined(MT6252H) || defined(MT6251) || defined(MT6276) || defined(TK6280) )

#ifndef __DISABLE_RAISE_CHARGE_CURRENT_IN_BOOTLOADER__
   if(!IsInWithOutBatteryMode())
   {
      BL_Raise_Charger_Current();
   }
#endif

#endif

#if !defined(__16_3_SEG__) && !defined(__32_32_SEG__)
   /* PDN control initialization */
   lpwr_init();
   DRVPDN_ini();
   DclPMU_Initialize();
#endif /* !__16_3_SEG__ && !__32_32_SEG__ */

#ifdef __SV5_ENABLED__

   TS_BEGIN(TSID_BL_INIT_EXT_FLASH_DRV);
   InitFlashDriver();
   TS_END(TSID_BL_INIT_EXT_FLASH_DRV);

   DummyReference();
#endif /* __SV5_ENABLED__ */

#if !defined(__16_3_SEG__) && !defined(__32_32_SEG__) && !defined(__BRINGUP_SUPPORT__)
   SSS_Init_Crypto_Drv(TS_RECORD_FUNC, TS_INFO_FUNC);
#endif /* !__16_3_SEG__ && !__32_32_SEG__ && !__BRINGUP_SUPPORT__ */

   TS_END(TSID_BL_EXT_INIT);
}

kal_uint32 MauiFeatureCombination(void)
{
   return g_mauiFeatureCombination;
}

void GetFeatureCombination(void)
{
#ifndef __SV5_ENABLED__
   kal_uint32 addr;
#endif

   TS_BEGIN(TSID_BL_GET_FATURE_COMINATION);
      
   BL_DEBUG_PRINT("GetFeatureCombination()\n\r");

   g_mauiFeatureCombination = 0;
   
#ifdef __SV5_ENABLED__
{
      GFH_MAUI_INFO_v1 *pMauiInfo = bl_GetMAUIInfo();

      if(pMauiInfo)
      {
         g_mauiFeatureCombination = pMauiInfo->m_feature_combination;
      }
}
#else

#ifdef _NAND_FLASH_BOOTING_
   addr = (kal_uint32)GetVersionInfoAddress();
#else
   addr = (kal_uint32)(MAUI_START_ADDR_NOR & REMAPPING_MASK);
#endif   

   SST_Get_MAUI_Feature_Combination(addr, &g_mauiFeatureCombination);
   
   BL_DEBUG_PRINT("g_mauiFeatureCombination=%x, bl combination=%d\n\r", g_mauiFeatureCombination);

#endif   

   TS_END(TSID_BL_GET_FATURE_COMINATION);
}

kal_bool CheckPairedVersion(void)
{
#ifdef __SV5_ENABLED__

   GFH_MAUI_INFO_v1 *pMauiInfo = bl_GetMAUIInfo();

   if(pMauiInfo)
   {
       if( pMauiInfo->m_bl_maui_paired_ver != g_ext_bootloader_gfh.gfh_arm_bl_info.m_bl_maui_paired_ver)
       {
          BL_PRINT(LOG_ERROR, "Paired version mismatched, %d, %d\n\r", pMauiInfo->m_bl_maui_paired_ver, g_ext_bootloader_gfh.gfh_arm_bl_info.m_bl_maui_paired_ver);
          return KAL_FALSE;
       }
   }

#else
   kal_uint32 paired_version;
   kal_uint32 addr;
   
#ifdef _NAND_FLASH_BOOTING_
   addr = (kal_uint32)GetVersionInfoAddress();
#else
   addr = (kal_uint32)(MAUI_START_ADDR_NOR & REMAPPING_MASK);
#endif   

   paired_version = SST_Get_MAUI_Paired_Version(addr);

   if ( paired_version != 0 && paired_version != g_ExtBootloaderInfo.m_bl_maui_paired_ver )
   {
      dbg_print("Paired version mismatched, %d, %d\n\r", g_ExtBootloaderInfo.m_bl_maui_paired_ver, paired_version);
      return KAL_FALSE;
   }
#endif /* __SV5_ENABLED__ */

   return KAL_TRUE;   
}


kal_bool CheckFeatureCompatibility(kal_uint32 mauiFeatureSet)
{
   kal_uint32 blFeatureSet = BlFeatureCombination();

   kal_bool featureIncomp = KAL_FALSE;

   if( (blFeatureSet & MAUI_FC_SECURE) != (mauiFeatureSet & MAUI_FC_SECURE) )
   {
      featureIncomp = KAL_TRUE;
   }

   if( !(blFeatureSet & MAUI_FC_FOTA) && (mauiFeatureSet & MAUI_FC_FOTA) )
   {
      featureIncomp = KAL_TRUE;
   }

   if( !(blFeatureSet & MAUI_FC_NOR_FLASH_BOOTING) && (mauiFeatureSet & MAUI_FC_NOR_FLASH_BOOTING) )
   {
      featureIncomp = KAL_TRUE;
   }

   if( (blFeatureSet & MAUI_FC_FAST_LOGO) != (mauiFeatureSet & MAUI_FC_FAST_LOGO) )
   {
      featureIncomp = KAL_TRUE;
   }

   return (!featureIncomp);

}

kal_bool CheckFeatureCombination(void)
{
#ifdef __SV5_ENABLED__
   if(g_maui_load_addr != INVALID_START_ADDR)
#endif /* __SV5_ENABLED__ */
   {
      if( CheckFeatureCompatibility(g_mauiFeatureCombination) == KAL_FALSE )
      {
         BL_PRINT(LOG_ERROR, "Incompatible features, mauiFeature=%d\n\r", g_mauiFeatureCombination);
         return KAL_FALSE;
      }
   }

   return KAL_TRUE;   
}


#ifdef __LCD_DRIVER_IN_BL__

void BL_LCDHWInit(void)
{
#ifndef __L1_STANDALONE__
   if((g_lcd_status & BL_LCD_INITED) == 0)
   {
      /* HW initialization */
      DclPW_Initialize();
      
      //GPIO_init();          //Not init GIPO here or other one's setting will be overwritten
      DclGPIO_Initialize();

      DclPWM_Initialize();
      PWM_initialize();
      DclPMU_Initialize();
      g_lcd_status |= BL_LCD_INITED;
   }
#endif /* !__L1_STANDALONE__ */
}

/**********************************************************
Description : BL_LCDSetBackLight.
Input       : None
Output      : None
***********************************************************/
void BL_LCDSetBackLight(void)
{
   if((g_lcd_status & BL_LCD_BACKLIGHT_ON) == 0)
   {
      kal_uint32 BBPU;
      kal_uint32 count = 0;

#ifndef __L1_STANDALONE__
      custom_uem_gpio_set_level(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);
#endif /* !__L1_STANDALONE__ */
      g_lcd_status |= BL_LCD_BACKLIGHT_ON;
   }
}


#endif /* __LCD_DRIVER_IN_BL__ */

void SetWDTNormalResetFlag(void)
{
   DCL_HANDLE rtc_handler;
   RTC_CTRL_CONFIG_PDN_BIT_T rtc_cmd_data8;

   rtc_handler = DclRTC_Open(DCL_RTC,FLAGS_NONE);
   DclRTC_Control(rtc_handler, RTC_CMD_PROT_UNLOCK, (DCL_CTRL_DATA_T *)NULL);
   
   rtc_cmd_data8.PDNIndex = DCL_RTC_PDN2;
   rtc_cmd_data8.fgConfigBit = DRV_COMM_REG2_NORMAL_RESET;
   DclRTC_Control(rtc_handler, RTC_CMD_SET_PDN_BITS, (DCL_CTRL_DATA_T *)&rtc_cmd_data8); // New API with CMD & DATA	
   DclRTC_Close(rtc_handler);
}

#endif /* __EXT_BOOTLOADER__ */

#ifdef __RVCT__
/*************************************************************************
* FUNCTION
*  __user_initial_stackheap
*
* DESCRIPTION
*  This dummy function is implemented to make the linker happy for RVCT.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
__value_in_regs struct __initial_stackheap __user_initial_stackheap(unsigned i0, unsigned i1, unsigned i2, unsigned i3)
{
   struct __initial_stackheap config;

   config.heap_base = i1;
   config.heap_limit = i1;
   config.stack_base = i1; 
   config.stack_limit = 0;

   return config;
}

/*************************************************************************
* FUNCTION
*  __ARM_get_argv
*
* DESCRIPTION
*  This dummy function is implemented to suppress argc,argv processing
*  in standard C library
*
* CALLS
* PARAMETERS
* RETURNS
* GLOBALS AFFECTED
*************************************************************************/
__value_in_regs struct __argc_argv $Sub$$__ARM_get_argv(void *ptr)
{
    struct __argc_argv a = {0};
    return a;
}

/*************************************************************************
* FUNCTION SYMBOL
*  __use_no_heap
*
* DESCRIPTION
*  You can reference the __use_no_heap or __use_no_heap_region symbols in
*  your code in order to guarantee that no heap using functions are linked
*  in from the ARM library.
*
*************************************************************************/
//#pragma import(__use_no_heap)

#pragma import(__user_initial_stackheap)
#endif   /* __RVCT__ */

/**********************************************************
Description : initialization of DTLB
Input       : None
Output      : None
***********************************************************/
void Init_DTLB(void)
{
#if defined(__MTK_SECURE_PLATFORM__) && !defined(__SV5_ENABLED__)
   extern void SST_DTLB_InitInBL(kal_uint32);
   kal_uint32 dummy[4];
   kal_uint32 addr = (kal_uint32)(dummy);

#if (defined(MT6235) || defined(MT6235B) || defined(MT6238) || defined(MT6239)) && defined(_NAND_FLASH_BOOTING_)
   addr = 0x40000000;
#endif

   SST_DTLB_InitInBL(addr);
   
#endif /* __MTK_SECURE_PLATFORM__ && !__SV5_ENABLED__ */  

}

#ifdef __MINI_BOOTLOADER__

/**********************************************************
Description : Generation of the random seed
Input       : None
Output      : Generated seed
***********************************************************/

#if defined(MT6238) || defined(MT6235) || defined(MT6239) || defined(MT6235B) || defined(MT6236)  || defined(MT6236B)
static const kal_uint32 RAND_GEN_START_ADDR = 0x4000A000;
#elif defined(MT6268A) || defined(MT6268)
static const kal_uint32 RAND_GEN_START_ADDR = 0x9200A000;
#elif defined(MT6516) && defined(__APPLICATION_PROCESSOR__)
static const kal_uint32 RAND_GEN_START_ADDR = 0x4000A000;
#else
static const kal_uint32 RAND_GEN_START_ADDR = 0x40002000;
#endif

kal_uint32 GenerateRandomSeed()
{
#if !defined(__GNUC__)	
   const kal_uint32 SEED_REGION_SIZE = 1024;
#endif
   kal_uint32 *p, *q, seed;
   
#ifdef __SV5_ENABLED__

#if defined(__GNUC__)
   //GCC_TODO
   q = (kal_uint32*)0x70020000;
   p = (kal_uint32*)0x7001f000;
#else
   extern kal_uint32 Image$$DUMMY_END$$Base;

   q = (kal_uint32*)&Image$$DUMMY_END$$Base;
   p = q-SEED_REGION_SIZE/4;
#endif

#else

   p = (kal_uint32 *)RAND_GEN_START_ADDR;
   q = (kal_uint32 *)(RAND_GEN_START_ADDR + SEED_REGION_SIZE);

#endif

   /* generate a random number via reading internal SRAM or 32K-clock calibration */
   for (seed = 0; p < q; p++) {
      /* XOR memory data */
      seed = seed ^ *p;
   }

   return seed;

}
#endif /* __MINI_BOOTLOADER__ */

