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
 *  drv_features_gcu.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is for the GCU driver features
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __DRV_FEATURES_GCU_H__
#define __DRV_FEATURES_GCU_H__

#include "drv_features_chip_select.h"

#if 0   // Reference only
#if    defined(MT6223) || defined(MT6223P) \
    || defined(MT6225) \
    || defined(MT6229) || defined(MT6230) \
    || defined(MT6235) || defined(MT6235B) \
    || defined(MT6236) || defined(MT6236B) \
    || defined(MT6238) || defined(MT6239) \
    || defined(MT6251) \
    || defined(MT6253) || defined(MT6253T) \
    || defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H) \
    || defined(MT6256) \
    || defined(MT6268) || defined(MT6268A) || defined(MT6268H) || defined(MT6268T) \
    || defined(MT6270A) || defined(MT6276) \
    || defined(MT6516) || defined(TK6516) \
    || defined(MT6573) || defined(MT6575)
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#if defined(MT6217) || defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228)
/* under construction !*/
#endif
/* under construction !*/
#if defined(MT6208)
/* under construction !*/
#endif
#endif  // 0

#if defined(DRV_GCU_6208_SERIES)
    #ifndef __GCU_SUPPORT__
    #define __GCU_SUPPORT__
    #endif  // #ifndef __GCU_SUPPORT__

    #define DRV_GCU_REG_16BITS
#elif defined(DRV_GCU_6217_SERIES)
    #ifndef __GCU_SUPPORT__
    #define __GCU_SUPPORT__
    #endif  // #ifndef __GCU_SUPPORT__

    #define DRV_GCU_REG_32BITS
#elif defined(DRV_GCU_6218B_SERIES)
    #ifndef __GCU_SUPPORT__
    #define __GCU_SUPPORT__
    #endif  // #ifndef __GCU_SUPPORT__

    #define DRV_GCU_REG_32BITS
    #define DRV_GCU_REV_BIT_DISABLE
#elif defined(DRV_GCU_6225_SERIES)
    // FYI: It seems __GCU_SUPPORT__ is defined in drv_features_<chip>.h, <chip> is a SP project.
    #ifndef __GCU_SUPPORT__
    #define __GCU_SUPPORT__
    #endif  // #ifndef __GCU_SUPPORT__

    #define DRV_GCU_REG_32BITS
    #define DRV_GCU_GEA3
#endif

#endif  // #ifndef __DRV_FEATURES_GCU_H__

