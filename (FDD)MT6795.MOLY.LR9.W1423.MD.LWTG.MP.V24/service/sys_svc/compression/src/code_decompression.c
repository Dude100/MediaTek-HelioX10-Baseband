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
 *   mmu.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the functionality of Code and Data cache.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#if defined(__ZIMAGE_SUPPORT__)

#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "code_decompression.h"
#include "dcl.h"
#include "dcl_pw.h"

#include "device.h"

#if !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI)
extern void MMICheckDiskDisplay_bootup(void);
#endif

kal_bool ZIMAGEImageLoaded = 0;

static void zimage_dispaly_logo(void)
{
#if defined(__MTK_TARGET__)
    DCL_HANDLE handle;
    PW_CTRL_GET_POWERON_REASON poweron_type;

    handle=DclPW_Open(DCL_PW, FLAGS_NONE);
    DclPW_Control(handle, PW_CMD_GET_POWERON_REASON,(DCL_CTRL_DATA_T *)&poweron_type);
    DclPW_Close(handle);
	  
#if !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI)
    MMICheckDiskDisplay_bootup();
#endif

#if defined(__NEP_ZIMAGE_SUPPORT__)
#if !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI)
        custom_uem_gpio_set_level(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);
#endif
#endif /* __NEP_ZIMAGE_SUPPORT__ */

    if(poweron_type.powerOnReason != RTCPWRON &&
       poweron_type.powerOnReason != ABNRESET &&
       poweron_type.powerOnReason != UNKNOWN_PWRON)
    {
        handle=DclPW_Open(DCL_PW, FLAGS_NONE);
        DclPW_Control(handle,PW_CMD_POWERON,NULL);
        DclPW_Close(handle);

#if !defined(__NEP_ZIMAGE_SUPPORT__)
#if !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI)
        custom_uem_gpio_set_level(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);
#endif
#endif /* __NEP_ZIMAGE_SUPPORT__ */
    }
#endif /* __MTK_TARGET__ */
}

static void zimage_progress_notify(kal_uint32 dec_size, kal_uint32 total_size)
{
#if defined(__MTK_TARGET__)
#if !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI)
    MMICheckDiskDisplay_bootup();
#endif
#endif /* __MTK_TARGET__ */
}

int ZImageDecompress(void)
{
#if defined(__MTK_TARGET__)
#define ZIMAGE_DECOMPRESS_LEN            (64*1024)

      zimage_dispaly_logo();

      ZImageDecompressHal(ZIMAGE_DECOMPRESS_LEN, zimage_progress_notify);

      ZIMAGEImageLoaded = KAL_TRUE;

#endif /* __MTK_TARGET__ */
      return 0;
}

#endif /* __ZIMAGE_SUPPORT__ */
