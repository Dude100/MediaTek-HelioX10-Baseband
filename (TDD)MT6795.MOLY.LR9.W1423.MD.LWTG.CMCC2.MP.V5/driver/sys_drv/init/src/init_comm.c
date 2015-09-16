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
 *   init.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the HW initialization.
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
 *
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
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
[MAUI_03149504] ([MAUI_03180970]) all time memory dump
[MAUI_03121063] remove PDN registers
[MAUI_03147344] Dummy read for early response HW
[MAUI_03161918] remove custom_setAdvEMI from bootarm.S
[MAUI_03157059] security use meta to write

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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*******************************************************************************
 * Include header files
 *******************************************************************************/

#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "kal_internal_api.h"
#include "kal_trace.h"
#include "reg_base.h"
#include "config_hw.h"
#include "emi_hw.h"
#include "init.h"
#include "intrCtrl.h"
#include "isrentry.h"
//MSBB remove #include "custom_config.h"
#include "stack_buff_pool.h"
#include "fat_fs.h"
#include "drv_comm.h"
//MSBB remove #include "wdt_hw.h"
#include "wdt_sw.h"
#include "bmt.h"
#include "dcl.h"
#include "drvpdn.h"
#include "SST_init.h"   /* for sw version check in INT_Version_Check() */
#include <stdio.h>
#include <string.h>
#if defined(__ARMCC_VERSION)
#include <rt_misc.h>   /* for __rt_lib_init() */
#endif
#include <stdlib.h>
#include "cache_sw.h"
#include "page.h"
#include "l1_interface.h"
#include "bl_features.h"
#include "bl_setting.h"
#include "bl_loader.h"
#include "system_trc.h"
#include "init_trc_api.h"
#include "ex_item.h"



#ifdef __CHIP_VERSION_CHECK__
#include "uart_sw.h"
#endif /* __CHIP_VERSION_CHECK__ */


#ifdef __MULTI_BOOT__
#include "syscomp_config.h"
#include "multiboot_config.h"
#endif   /* __MULTI_BOOT__ */
#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__)
#include "cp15.h"
#endif   /* __ARM9_MMU__ || __ARM11_MMU__ */

#if defined(__SMART_PHONE_MODEM__)
#include "ccci.h"
#endif /* __SMART_PHONE_MODEM__ */

#if defined(__DSP_FCORE4__)
#include "mdci.h"
#include "SST_dmdsp_ex.h"
#include "dmdsp_init.h"
#endif /* __DSP_FCORE4__ */
#if defined(__FOTA_DM__)
#include "fue_err.h"
#include "custom_fota.h"
#include "custom_img_config.h"
#include "fue.h"
#include "SSF_fue_support.h"
#endif
#if !defined(__UBL__) && !defined(__FUE__)
#ifdef __CENTRALIZED_SLEEP_MANAGER__
#include "ostd_public.h"
#endif /* __CENTRALIZED_SLEEP_MANAGER__ */
#endif

/*******************************************************************************
 * Define pragma
 *******************************************************************************/

/*******************************************************************************
 * Define global data
 *******************************************************************************/
/* [BB porting] please make sure the register address is correct and scatter file palced in the correct region */
#if defined(EMI_base)
const kal_uint32 g_EMI_BASE_REG		 	  = EMI_base;
#endif /* EMI_base */


/*******************************************************************************
 * Declare import data
 *******************************************************************************/

/*******************************************************************************
 * Declare import function prototype 
 *******************************************************************************/



/*************************************************************************
* FUNCTION
*  AnalogDieID
*
* DESCRIPTION
*  This function returns identification of analog die
*
* CALLS
*
* PARAMETERS
*  None
*
* RETURNS
*  Identification of analog die
*
* GLOBALS AFFECTED
*  None
*
*************************************************************************/
analog_die_id AnalogDieID()
{
   return UNKNOWN_ANALOG_DIE;
}


#if defined(__CHIP_VERSION_CHECK__) && !defined(__UBL__)
/*************************************************************************
* FUNCTION
*  INT_Version_Check
*
* DESCRIPTION
*   This function implements HW ID check with software load version
*
* CALLS
*  U_PutUARTByte
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
/* [BB porting] Please make sure the version register and build code is correct */
extern void U_PutUARTByte(UART_PORT port, kal_uint8 data);
void INT_Version_Check(void)
{
   volatile register kal_uint16 HwCode;
   register kal_uint8 HExtra = ' ';
   register kal_uint16 BuildCode;
   volatile register kal_int32 i;

   HwCode = *HW_CODE;

#if defined(MT6280)
   BuildCode = 0x6280;
#elif defined(MT6290)
   BuildCode = 0x6290;
#elif defined(MT6595)
   BuildCode = 0x6593; //HW code of MT6595 is 6593
#elif defined(MT6752)
   BuildCode = 0x6752; //HW code of MT6589 is 6583
#else
   BuildCode = 0;
#endif

#ifndef ExtraVer
   #define	ExtraVer ' '
#endif

   if ((HwCode != BuildCode) || (HExtra != ExtraVer))
   {
      U_PutUARTByte(uart_port1, '@');
      while(1)
      {
         U_PutUARTByte(uart_port1, ' ');
         U_PutUARTByte(uart_port1, 'H');
         U_PutUARTByte(uart_port1, 'W');
         U_PutUARTByte(uart_port1, '=');
         U_PutUARTByte(uart_port1, 'M');
         U_PutUARTByte(uart_port1, 'T');
         for(i = 12; i >= 0; i -= 4)
         {
            U_PutUARTByte(uart_port1, '0' + ((HwCode >> i) & 0x0F));
         }
         U_PutUARTByte(uart_port1, HExtra);
         U_PutUARTByte(uart_port1, ',');
         U_PutUARTByte(uart_port1, ' ');
         U_PutUARTByte(uart_port1, 'S');
         U_PutUARTByte(uart_port1, 'W');
         U_PutUARTByte(uart_port1, '=');
         U_PutUARTByte(uart_port1, 'M');
         U_PutUARTByte(uart_port1, 'T');
         for(i = 12; i >= 0; i -= 4)
         {
            U_PutUARTByte(uart_port1, '0' + ((BuildCode >> i) & 0x0F));
         }
         U_PutUARTByte(uart_port1, ExtraVer);
         U_PutUARTByte(uart_port1, ' ');
         U_PutUARTByte(uart_port1, '\r');
         U_PutUARTByte(uart_port1, '\n');	
         
         for(i = 0xFFFFF; i > 0; i--) ;
         U_PutUARTByte(uart_port1, '#');
      }
   }
}

/*************************************************************************
* FUNCTION
*  INT_SW_VersionCheck
*
* DESCRIPTION
*  This function checks if sw sec version is matched with chip sw sec version
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
void INT_SW_VersionCheck(void)
{
   kal_int8 chipSWSecVer;
   kal_int8 binSWSecVer;
   char tempStr[50];
   
   /* SW second version check */
   chipSWSecVer = *SW_VER & 0x00FF;
   binSWSecVer = SW_MINOR_VER;
   
   sprintf(tempStr, "Chip SW second version: %02d", chipSWSecVer);
   tst_sys_trace(tempStr);
   sprintf(tempStr, "Bin file SW second version: %02d", binSWSecVer);
   tst_sys_trace(tempStr);
   
   if(binSWSecVer < chipSWSecVer) {
      /* show catcher log warning */
      tst_sys_trace("[Warning] SW second version of bin file is smaller than chip!");
   }
}
#else /* __CHIP_VERSION_CHECK__ && !__UBL__ */
/* fake function */
void INT_Version_Check(void)
{
}

void INT_SW_VersionCheck(void)
{
}
#endif /* __CHIP_VERSION_CHECK__ && !__UBL__ */

/*************************************************************************
* FUNCTION
*  INT_ecoVersion
*
* DESCRIPTION
*  This function returns the ECO version number of baseband chipset
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
/* [BB porting] Please make sure the the correlated enum and code is added since the default case is ext_assert */
/* Please be aware that new chips may use INT_SW_SecVersion */
ECO_VERSION INT_ecoVersion(void)
{
#if  defined(MT6280)
   return    MT6270A_latest_chip;

#elif defined(MT6290)
   return    MT6290_latest_chip;

#elif defined(MT6575)
   return    MT6575_latest_chip;

#elif defined(MT6577)
   return    MT6577_latest_chip;

#elif defined(MT6595)
   return    MT6595_latest_chip;

#elif defined(MT6752) && defined(__MD1__)
    return    MT6752_MD1_latest_chip;

#elif defined(MT6752) && defined(__MD2__)
    return    MT6589_latest_chip;

#else 
   /* no one should invoke this function for unknown chip */
   ASSERT(0);
   return 0;

#endif
}


/*************************************************************************
* FUNCTION
*  INT_GetCurrentTime
*
* DESCRIPTION
*  This function access 32KHz Counter and return Counter Value
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*  Value of 32KHz Counter
*
* GLOBALS AFFECTED
*
*************************************************************************/

/* for SNOR, this function should be placed in RAM */
#if defined(__MTK_TARGET__)
#if defined(__UBL__) || defined(__FUE__)
//#pragma arm section code = "INTERNCODE"
#elif defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
//#pragma arm section code = "SNORCODE"
#endif
#endif //__MTK_TARGET__

/* [BB porting] confirm with L1 if the function is support in new chip */
kal_uint32 INT_GetCurrentTime(void)
{
#if (defined(MT6575) || defined(MT6577)) && defined(__APPLICATION_PROCESSOR__)
   return 0; // Not Support Yet
#elif defined(MT6290) || defined(ATEST_DRV_ENVIRON) || defined(__MAUI_BASIC__)
   return 0; // Not Support Yet
#else	
   /* 
    * Call API provided by L1
    */
   return (volatile kal_uint32)HW_TDMA_GET_32KCNT();
#endif /* (MT6575 || MT6577) && __APPLICATION_PROCESSOR__ */   
}


/*************************************************************************
* FUNCTION
*  INT_ChipName
*
* DESCRIPTION
*  This function is a special use for those users desire to run on
*  different chips with the same SW load.
*  
*
* PARAMETERS
*  none
*
* RETURNS
*  0
*
*************************************************************************/
/* [BB porting] Make sure if the rule is changed or need to add for a new chip */
CHIP_NAME INT_ChipName(void)
{
   /* no one should invoke this function for unknown chip */
   ASSERT(0);

   return 0;   
}


/*************************************************************************
* FUNCTION
*  INT_Init_MT6595_Eco_Magic
*
* DESCRIPTION
*  MT6595 E1 SW Second Version Software Workaround
*  Due to MT6595 ECO 1 sw second version didn't plus 1, we need the following sw workaround.
*  1. Add global Variable mt6595_eco_magic to record BUS Monitor's BASE_MADDR_PCMON[20] default value.
*  2. After region init stage, we need to init global variable mt6595_eco_magic by INT_Init_MT6595_Eco_Magic().
*     If BASE_MADDR_PCMON[20] is 0x0, set mt6595_eco_magic = 0, else set mt6595_eco_magic = 1.
*     If anyone need to check ECO version after INT_Init_MT6595_Eco_Magic(), please invoke INT_SW_SecVersion().
*  3. Before region init stage, if anyone need to check ECO version, please invoke MACRO INT_MT6595_ECO_MAGIC
*     defined in init.h
*
* PARAMETERS
*  none
*
* RETURNS
*  void
*
*************************************************************************/
#if defined(MT6595)
static kal_uint8 mt6595_eco_magic = 0xFF;

void INT_Init_MT6595_Eco_Magic(void)
{
    if(INT_MT6595_ECO_MAGIC == 0x00)
    {
        mt6595_eco_magic = 0x00;
    }
    else
    {
        mt6595_eco_magic = 0x01;
    }
}
#endif

/*************************************************************************
* FUNCTION
*  INT_SW_MajorVersion
*
* DESCRIPTION
*  This function is used for DSPs to query the software major version
*  
*  
*
* PARAMETERS
*  none
*
* RETURNS
*  0
*
*************************************************************************/
kal_uint8 INT_SW_MajorVersion(void)
{
    return ((*SW_VER & 0xFF00) >> 0x8);
}

/*************************************************************************
* FUNCTION
*  INT_SW_SecVersion
*
* DESCRIPTION
*  This function is used for SW to query the software secondary version
*  
*  
*
* PARAMETERS
*  none
*
* RETURNS
*  0
*
*************************************************************************/
/* [BB porting] Check if the chip support new version and if the SW secondary version is changed */
SW_SECVERSION INT_SW_SecVersion(void)
{
#if defined(MT6752)
    if ( (*SW_VER & 0x00FF) == 0x00)
    {
        return SW_SEC_0;
    }
    else if ((*SW_VER & 0x00FF) == 0x01)
    {
        return SW_SEC_1;
    }
	else if ((*SW_VER & 0x00FF) == 0x02)
    {
        return SW_SEC_2;
    }
    else
    {
        return SW_LATEST_SEC;
    }
#elif defined(MT6595)
    /* MT6595 E1 SW Second Version Software Workaround
    * Due to MT6595 ECO 1 sw second version didn't plus 1, we need the following sw workaround.
    * 1. Add global Variable mt6595_eco_magic to record BUS Monitor's BASE_MADDR_PCMON[20] default value.
    * 2. After region init stage, we need to init global variable mt6595_eco_magic by INT_Init_MT6595_Eco_Magic().
    *    If BASE_MADDR_PCMON[20] is 0x0, set mt6595_eco_magic = 0, else set mt6595_eco_magic = 1.
    *    If anyone need to check ECO version after INT_Init_MT6595_Eco_Magic(), please invoke INT_SW_SecVersion().
    * 3. Before region init stage, if anyone need to check ECO version, please invoke MACRO INT_MT6595_ECO_MAGIC
    *    defined in init.h
    */
    if (mt6595_eco_magic == 0x00)
    {
        return SW_SEC_0;
    }
    else if (mt6595_eco_magic == 0x01)
    {
        return SW_SEC_1;
    }
    else
    {
        ASSERT(0);
    }
#else

    ASSERT(0);
#endif

    return SW_SEC_UNDEF;
}

/*************************************************************************
* FUNCTION
*  INT_ChipGroup
*
* DESCRIPTION
*  This function is a special use for those users desire to run on
*  different chips with the same SW load.
*  
*
* PARAMETERS
*  none
*
* RETURNS
*  0
*
*************************************************************************/
/* [BB porting] May not need to maintain this, check if we could remove */
CHIP_GROUP INT_ChipGroup(void)
{
   /* no one should invoke this function for unknown chip */
   ASSERT(0);

   return 0;   
}


