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
 *   bl_setting.h
 *
 * Project:
 * --------
 *   Bootloader
 *
 * Description:
 * ------------
 *   BB-depended memory layout setting for bootloader
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __BL_SETTING_H__
#define __BL_SETTING_H__

#if defined(MT6276)
#define SYSRAM_BASE  0xc8000000
#elif defined(MT6256)
#define SYSRAM_BASE  0x91000000
#elif defined(MT6255)
#define SYSRAM_BASE  0x40000000
#elif defined(MT6268A) || defined(MT6268)
#define SYSRAM_BASE  0x92000000
#elif defined(MT6270A)
#define SYSRAM_BASE  0x90000000
#elif defined(MT6252H) || defined(MT6252)
#define SYSRAM_BASE  0x40008000
#elif defined(TK6280)
#define SYSRAM_BASE  0x58020000
#elif defined(MT6250)
#define SYSRAM_BASE  0x70004000
#elif defined(MT6280)
#define SYSRAM_BASE  0x70000000
#else
#define SYSRAM_BASE  0x40000000
#endif

#if defined(MT6268) || defined(MT6268A) || defined(MT6236) || defined(MT6236B) || defined(MT6276) || defined(MT6256) || defined(MT6255)
#define BOOTROM_ITCM_BASE 0x50000000
#define BOOTROM_DTCM_BASE 0x50040000
#elif defined(MT6238) || defined(MT6239) || defined(MT6235) || defined(MT6235B)
#define BOOTROM_ITCM_BASE 0x50000000
#define BOOTROM_DTCM_BASE 0x50020000
#elif defined(MT6270A)
#define BOOTROM_ITCM_BASE 0x58000000
#define BOOTROM_DTCM_BASE 0x58040000
#endif

#if defined(MT6251)
#define __N_PLUS_0_PROJECT__
#endif

#if defined(MT6238) || defined(MT6235) || defined(MT6235B) || defined(MT6239) || defined(MT6268A) || defined(MT6268) || defined(MT6236) || defined(MT6236B) || defined(MT6270A) || defined(MT6256) || defined(MT6276) || defined(MT6255) || defined(MT6280)
#define EMI_REMAP_OFFSET_MIXED
#endif

#if defined(MT6255) || defined(MT6250) || defined(MT6280)
#define __RAM_FLASH_REMAP_DONE_IN_EMI_INIT__
#endif

/* This option is to place bootloader's BROM BL param structure in External RAM, 
   Usable when original location of BROM BL overlapes with Bootloader's structure */
#if defined(MT6250)
#define __COPY_BROM_BL_PARAM_TO_EXTERNAL_RAM__
#endif

/* To reduce the internal RAM usage, use external RAM as NAND/eMMC read buffer, suffering a
   a little bit disadventage of debugging, especially in EMI problem */
#define __USE_EXTERNAL_READ_BUFFER__

/* Rule for SYS_RESV and BL Shared placement:
<ARM 9/11 project>
DTCM:
   SYS_RESV  (64B)      <-- SV5 only
SysRAM
   BL_SHARED (128B)

<ARM 7 project>
TCM:
   VectorTbl (64B)      <-- N+0 only
   SYS_RESV  (64B)      <-- SV5 only
   BL_SHARED (128B)
*/   

#if defined(__N_PLUS_0_PROJECT__)
#define N_PLUS_0_RESERVED_VECTOR_TBL   0x40
#else
#define N_PLUS_0_RESERVED_VECTOR_TBL   0
#endif

#ifdef MT6280
#define SYS_PARAM_BUF_BASE    (SYSRAM_BASE + N_PLUS_0_RESERVED_VECTOR_TBL)
#define BL_INFO_ADDR          (SYSRAM_BASE + N_PLUS_0_RESERVED_VECTOR_TBL)
#else
#ifdef BOOTROM_DTCM_BASE
#define SYS_PARAM_BUF_BASE    (BOOTROM_DTCM_BASE)
#define BL_INFO_ADDR          (SYSRAM_BASE)
#else
#ifdef __SV5_ENABLED__
#define SYS_PARAM_BUF_BASE    (SYSRAM_BASE + N_PLUS_0_RESERVED_VECTOR_TBL)
#define BL_INFO_ADDR          (SYSRAM_BASE + N_PLUS_0_RESERVED_VECTOR_TBL + sizeof(SYS_ParamBuffer))
#else
#define BL_INFO_ADDR          (SYSRAM_BASE + N_PLUS_0_RESERVED_VECTOR_TBL)
#endif /* __SV5_ENABLED__ */
#endif
#endif

#ifndef __SV5_ENABLED__
#if defined (MT6238) || defined(MT6235)  || defined(MT6239) || defined(MT6235B) || defined(MT6268A) || defined(MT6268) || defined(MT6516) || defined(MT6236) || defined(MT6236B)
#define BOOTLOADER_HEADER_ADDRESS 0x50000000
#elif defined(MT6270A)
#define BOOTLOADER_HEADER_ADDRESS 0x58000000
#else
#define BOOTLOADER_HEADER_ADDRESS 0xa0000000
#endif
#endif /* __SV5_ENABLED__ */

#define EMI_BANK_END         0x1fffffff

#endif /* __BL_SETTING_H__ */
