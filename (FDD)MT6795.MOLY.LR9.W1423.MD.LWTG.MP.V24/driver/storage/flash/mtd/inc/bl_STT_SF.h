/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *   bl_STT_SF.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the SFI (serial flash interface) STT test.
 *
 * Author:
 * -------
 * -------
 *
 *   
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if defined(__SERIAL_FLASH_STT_EN__)
#if defined(__MTK_INTERNAL__)

#ifndef __STT_H__
#define __STT_H__

#include "reg_base.h"

typedef volatile unsigned char *     P_U8;
typedef volatile signed char *       P_S8;
typedef volatile unsigned short *    P_U16;
typedef volatile signed short *      P_S16;
typedef volatile unsigned int *      P_U32;
typedef volatile signed int *        P_S32;
typedef unsigned long long *         P_U64;
typedef signed long long *           P_S64;

// #define SERIAL_FLASH_TUNING_TEST

void stt_main(void);

#define STT_BUFFER_SIZE 512+4

// Serial flash dummy cycle for fast read in QPI
#define SFC_DUMMY_CYC_1T_QPI        (0x00000000)
#define SFC_DUMMY_CYC_2T_QPI        (0x00001000)
#define SFC_DUMMY_CYC_3T_QPI        (0x00002000)
#define SFC_DUMMY_CYC_4T_QPI        (0x00003000)
#define SFC_DUMMY_CYC_5T_QPI        (0x00004000)
#define SFC_DUMMY_CYC_6T_QPI        (0x00005000)


// Serial flash dummy cycle for fast read in SPI
#define SFC_DUMMY_CYC_1T_SPI        (0x00000000)
#define SFC_DUMMY_CYC_2T_SPI        (0x00001000)
#define SFC_DUMMY_CYC_3T_SPI        (0x00002000)
#define SFC_DUMMY_CYC_4T_SPI        (0x00003000)
#define SFC_DUMMY_CYC_5T_SPI        (0x00004000)
#define SFC_DUMMY_CYC_6T_SPI        (0x00005000)
#define SFC_DUMMY_CYC_7T_SPI        (0x00006000)
#define SFC_DUMMY_CYC_8T_SPI        (0x00007000)


//-----------------------------------------------------------------------------
/*!
  @brief
    Serail Flash Tuning Test for MT6253L / MT6258 / MT6252
*/
//Previous MT6255 registers definition, still can be used (I'm lazy to remove this part)
#define SF_MAC_CTL      ((P_U32)(SFI_base + 0x0000))
#define SF_MAC_OUTL     ((P_U32)(SFI_base + 0x0010))
#define SF_MAC_INL      ((P_U32)(SFI_base + 0x0014))
#define SF_DIRECT_CTL   ((P_U32)(SFI_base + 0x0004))
#define SF_DLY_CTL      ((P_U32)(SFI_base + 0x0020))
#define SF_MISC_CTL     ((P_U32)(SFI_base + 0x0008))
#define SF_MISC_CTL2    ((P_U32)(SFI_base + 0x000C))
#define SF_DEBUG_OUT	((P_U32)(SFI_base + 0x0030))
#define SF_DEBUG		((P_U32)(SFI_base + 0x0040))
#define SF_GPRAM_DATA   ((P_U32)(SFI_base + 0x0800))

// 6250 SFI registers
#define STT_RW_SFI_MAC_CTL              ((P_U32)(SFI_base + 0x0000))
#define STT_RW_SFI_DIRECT_CTL           ((P_U32)(SFI_base + 0x0004))
#define STT_RW_SFI_MISC_CTL             ((P_U32)(SFI_base + 0x0008))
#define STT_RW_SFI_MISC_CTL2            ((P_U32)(SFI_base + 0x000C))
#define STT_RW_SFI_MAC_OUTL             ((P_U32)(SFI_base + 0x0010))
#define STT_RW_SFI_MAC_INL              ((P_U32)(SFI_base + 0x0014))
#define STT_RW_SFI_RESET_CTL            ((P_U32)(SFI_base + 0x0018))
#define STT_RW_SFI_DLY_CTL1             ((P_U32)(SFI_base + 0x0020))
#define STT_RW_SFI_DLY_CTL2             ((P_U32)(SFI_base + 0x0024))
#define STT_RW_SFI_DLY_CTL3             ((P_U32)(SFI_base + 0x0028))
#define STT_RW_SFI_MISC_CTL3            ((P_U32)(SFI_base + 0x0044))
#define STT_RW_SFI_GPRAM_DATA           ((P_U32)(SFI_base + 0x0800))

// 6250 PLL registers
#define CLK_CONDH   ((P_U32)(CONFIG_base + 0x11C))
#define CLK_CONDC   ((P_U32)(CONFIG_base + 0x108))

#define WDT_MODE    ((P_U32)(RGU_base+0x0000))

#endif


#endif //defined(__MTK_INTERNAL__)
#endif //defined(__SERIAL_FLASH_STT_EN__)

