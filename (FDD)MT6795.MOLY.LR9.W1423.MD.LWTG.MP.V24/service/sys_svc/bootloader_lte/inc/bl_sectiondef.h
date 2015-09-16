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
 *   bl_seciondef.h
 *
 * Project:
 * --------
 *   Bootloader
 *
 * Description:
 * ------------
 *   Bootloader header, define bootloader realted section name
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _BL_SECTIONDEF_H
#define _BL_SECTIONDEF_H

#if defined(__MTK_TARGET__)

#if defined(__ARMCC_VERSION)
#define __zero_init__                  __attribute__((zero_init)) 
#elif defined(__GNUC__)
#define __zero_init__
#endif

#define __bootloader_gfh__             __attribute__ ((section("BOOTLOADER_GFH")))
#define __bootloader_gfh_ext__         __attribute__ ((section("BOOTLOADER_GFH_EXT")))

#define __bl_signature_section__       __attribute__ ((section("BL_SIGNATURE_SECTION")))
#define __ext_bootloader_gfh__         __attribute__ ((section("EXT_BOOTLOADER_GFH")))
#define __ext_bl_signature_section__   __attribute__ ((section("EXT_BL_SIGNATURE_SECTION")))

#define __ext_un_init_zi__             __attribute__ ((section("EXT_UN_INIT_ZI"))) __zero_init__

#define __bl_alg_table__               __attribute__ ((section("BL_ALG_TABLE")))


#define __interncode__                 __attribute__ ((section("INTERNCODE")))
#define __interndata__                 __attribute__ ((section("INTERNDATA")))
#define __internzi__                   __attribute__ ((section("INTERNZI"))) __zero_init__

#define __bl_info_shared_zi__          __attribute__ ((section("BL_INFO_SHARED_ZI"))) __zero_init__

#define __bl_resv_region__             __attribute__ ((section("BL_RESV_REGION")))
 
#define __head_bl__                    __attribute__ ((section("HEAD_BL")))

#define __mini_ext_da_share__          __attribute__ ((section("MINI_EXT_DA_SHARE"))) __zero_init__


#endif

#endif /* _BL_SECTIONDEF_H */
