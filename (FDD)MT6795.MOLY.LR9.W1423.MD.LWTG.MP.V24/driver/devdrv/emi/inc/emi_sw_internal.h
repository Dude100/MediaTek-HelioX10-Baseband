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
 *   emi_sw_internal.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Definition for CONFIG hardware registers
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __EMI_SW_INTERNAL_H__
#define __EMI_SW_INTERNAL_H__

/* RHR Add */
#include "kal_general_types.h"
#include "emi_hw.h"

/*********************************************
  *
  * High-level EMI feature definition.
  *
  ********************************************/




/**
   * Define EMI driver compilation.
   */
#if defined(__FUE__)

#define __EMI_INTERNAL_OPTIONAL_DRIVER__

#endif /* __FUE__ */

#if !defined(__FUE__)

#define __EMI_INTERNAL_OPTIONAL_DRIVER__
#define __EMI_INTERNAL_NECESSARY_DRIVER__
//#define __EMI_INTERNAL_TEST_DRIVER__

#endif /* !__FUE__ */





#define __EMI_SNORCODE_LOCATE_INTSRAM__


/*********************************************
  *
  * Constant/define
  *
  ********************************************/

/**
   * SFI boot-mode configuration.
   */
#define SFI_MAP_FLASH_NA 0x0
#define SFI_REMAP_MASK 0x10000

/**
   * EMI boot-mode configuration.
   */
#define EMI_MAP_EXTERNALBOOT_FLASH_SRAM  2
#define EMI_MAP_EXTERNALBOOT_SRAM_FLASH  3
#define EMI_REMAP_MASK 3


#define EMI_Dummy_Read_Base 0x00600000




/*********************************************
  *
  * Enum
  *
  ********************************************/

typedef enum
{
    EMI_CS0 = 0,
    EMI_CS1 = 1,
    EMI_CS2 = 2,
    EMI_CS3 = 3,
    EMI_MAX_CS = 3,
    EMI_UNKNOWN_CS = 0xff
} EMI_CHIP_SELECT;


typedef enum
{
    EMI_FLASH = 0,
    EMI_RAM = 1,
    EMI_MAX_MEMTYPE = 1
} EMI_MEMTYPE;


typedef enum
{
    EMI_UNKNOWN_MODE = 0,
    EMI_ASYNC_MODE,
    EMI_PAGE_MODE,
    EMI_BURST_MODE,
    EMI_SDR_16_MODE,
    EMI_SDR_32_MODE,
    EMI_DDRI_16_MODE,
    EMI_DDRI_32_MODE,
    EMI_DDRII_16_MODE,
    EMI_DDRII_32_MODE,
    EMI_DDRIII_16_MODE
} EMI_DEVICE_MODE;


/**
   * Define scenarios for requiring different GMC EMI bandwidth.
    */
enum 
{ 
    MM_SCE_MMI = 0, 
    MM_SCE_CAM_PREV, 
    MM_SCE_CAP, 
    MM_SCE_VIDEO_REC, 
    MM_SCE_VIDEO_PLAY,
    MM_SCE_END
};



/*********************************************
  *
  * Struct
  *
  ********************************************/

/**
   * This information is used to query EMI run-time configuration and show on the engineering mode.
   */
typedef struct 
{
    kal_uint32 reg_num;


    kal_uint32 EMI_CONI_value;
    kal_uint32 EMI_CONJ_value;
    kal_uint32 EMI_CONK_value;
    kal_uint32 EMI_CONL_value;
    kal_uint32 EMI_CONM_value;
    kal_uint32 EMI_CONN_value;	
 
    kal_uint32 EMI_GENA_value;
    kal_uint32 EMI_DRCT_value;
    kal_uint32 EMI_DDRV_value;
    kal_uint32 EMI_GEND_value;
    
    kal_uint32 EMI_ARBA_value;
    kal_uint32 EMI_ARBB_value;
    kal_uint32 EMI_ARBC_value;
    kal_uint32 EMI_ARBD_value;

} EMI_RUNTIME_Info;


/**
   * Record the EMI BW allocation for different EMI port. The bandwidth allocation here is in terms of %, for example, setting mcu_port_bw to be 11 means giving MCU 11% EMI BW.
   */
typedef struct 
{
    unsigned int dummy_port_bw;
} EMI_MASTER_BW;


/**
   * Record the EMI BW soft-mode or hard-mode allocation for different EMI port.
   */
typedef struct 
{
    unsigned int dummy_port_softmode;
} EMI_MASTER_SOFTMODE;


/**
   * High-level structure wrap EMI bandwidth allocation and soft/hard-mode configuration for EMI bandwidth control.
   */
typedef struct 
{
    EMI_MASTER_BW emi_bw;
    EMI_MASTER_SOFTMODE emi_softmode;

} EMI_MASTER_LIMITER;



/*********************************************
  *
  * Macro
  *
  ********************************************/


/******
   *
   * API for block all EMI transactions.
   *
   *****/
#if defined(MT6276) || defined(MT6256) || defined(MT6255) || defined(MT6280)

#define __EMI_BlockAllTransactions()  \
        do {    \
            *EMI_CONM = 0x003F; \
        } while (0)

#define __EMI_UnblockAllTransactions()  \
        do {    \
            *EMI_CONM = 0x0000; \
        } while (0)

#else /* MT6276 */

#define __EMI_BlockAllTransactions()
#define __EMI_UnblockAllTransactions()

#endif /* MT6276 */


/******
   *
   * API for disable dummy read.
   *
   *****/
#if defined(MT6276) || defined(MT6256) || defined(MT6255) || defined(MT6280)

#define __EMI_DisableDummyRead()  \
        do {    \
            *EMI_DRCT &= ~0x1; \
        } while (0)

#define __EMI_EnableDummyRead()  \
        do {    \
            *EMI_DRCT |= 0x1; \
        } while (0)

#else /* MT6276 */

#define __EMI_DisableDummyRead()
#define __EMI_EnableDummyRead() 

#endif /* MT6276 */


/******
   *
   * API for blocking under EMI enter idle state.
   *
   *****/
#if defined(MT6276) || defined(MT6256) || defined(MT6255) || defined(MT6280)

#define __EMI_WaitEmiEnterIdleState()  \
        do {    \
            while( ( *EMI_CONN & (1<<10) ) == 0 ); \
        } while (0)

#else /* MT6276 */

#define __EMI_WaitEmiEnterIdleState()

#endif /* MT6276 */




/*********************************************
 *
 * (HAL) Internal APIs.
 *
 ********************************************/
 
// Expose
//extern kal_int32 EMI_QueryCurSetting(EMI_RUNTIME_Info* emi_setting);

extern EMI_DEVICE_MODE EMI_QueryDeviceModeByMemType(EMI_MEMTYPE mem_type);		
extern kal_int32 EMI_SetScenarioBW(kal_uint32 scenario);
extern void EMI_reg_dump_init(void);
#endif  /* !__EMI_SW_INTERNAL_H__ */

