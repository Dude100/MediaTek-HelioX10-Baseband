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
 *    drv_sw_features_jpeg.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is merged for all graphics driver feature options.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * Merge hybrid jpeg encoder driver control.
 *
 * removed!
 * removed!
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClaseCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __DRV_SW_FEATURES_JPEG_H__
#define __DRV_SW_FEATURES_JPEG_H__

#include "drv_features_jpeg.h"

#if defined(__SW_JPEG_DECODER_BASIC_PROFILE_INTERNAL___)
   #define __SW_JPEG_DECODER_BASIC_PROFILE___
#endif

#if defined(__SW_JPEG_DECODER_FULL_PROFILE_INTERNAL___)
   #define __SW_JPEG_DECODER_FULL_PROFILE___
#endif

///#if defined(__SW_JPEG_ENCODER_BASIC_PROFILE_INTERNAL___)
///   #define __SW_JPEG_ENCODER_BASIC_PROFILE___
///#endif
///
///#if defined(__SW_JPEG_ENCODER_FULL_PROFILE_INTERNAL___)
///   #define __SW_JPEG_ENCODER_FULL_PROFILE___
///#endif

#if defined(__DRV_GRAPHICS_JPEG_6238_SERIES__) || defined(__DRV_GRAPHICS_JPEG_6236_SERIES__) || defined(__DRV_GRAPHICS_JPEG_6276_SERIES__) || defined(__DRV_GRAPHICS_JPEG_6268_SERIES__) || defined(__DRV_GRAPHICS_JPEG_6256_SERIES__)
   #define __JPEG_HW_SUPPORTED__
   #define __JPEG_ENC_HW_SUPPORTED__

   #if defined(__DRV_GRAPHICS_JPEG_6238_SERIES__) || defined(__DRV_GRAPHICS_JPEG_6276_SERIES__) || defined(__DRV_GRAPHICS_JPEG_6268_SERIES__) || defined(__DRV_GRAPHICS_JPEG_6256_SERIES__)
      #define __JPEG_DEC_HW_SUPPORTED__
   #endif
#endif


#endif /// __DRV_SW_FEATURES_JPEG_H__
