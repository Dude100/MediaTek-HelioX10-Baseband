/******************************************************************************
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2012
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

/******************************************************************************
 * Filename:
 * ---------
 *   drv_dcm_mt6752_md2.h
 *
 * Project:
 * --------
 *   MT6752
 *
 * Description:
 * ------------
 *   MT6752 MD2 dcm driver
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 *
 ****************************************************************************/

#ifndef __DRV_DCM_MT6752_MD2__
#define __DRV_DCM_MT6752_MD2__

#include <reg_base.h>
#include <intrCtrl.h>
#include "pll.h"

#if !defined(__MD2__) || !defined(MT6752)
# error "This file should only be used for MT6752 MD2 (ARM926)"
#endif

#define DCM_ENABLE_CHECK (KAL_TRUE)
//# define DCM_LPM_ENABLE 1
#undef  DCM_LPM_ENABLE

/* Lv2 DCM */
#define MD_GLOBAL_CON1            ((volatile UINT32P)(CONFIG_base+0x045c))

/* Lv2 LPM */
#define MD_DCM_DEBUG_CON0         ((volatile UINT32P)(CONFIG_base+0x0470))
#define MD_DCM_DEBUG_STATUS0      ((volatile UINT32P)(CONFIG_base+0x0478))
#define MD_DCM_DEBUG_STATUS1      ((volatile UINT32P)(CONFIG_base+0x047C))
#define MD_DCM_DEBUG_STATUS2      ((volatile UINT32P)(CONFIG_base+0x0480))
#define MD_DCM_DEBUG_STATUS3      ((volatile UINT32P)(CONFIG_base+0x0484))
#define MD_DCM_DEBUG_STATUS4      ((volatile UINT32P)(CONFIG_base+0x0488))
#define MD_DCM_DEBUG_STATUS5      ((volatile UINT32P)(CONFIG_base+0x048C))
#define MD_TOP_CLKO_MODE          ((volatile UINT32P)(CONFIG_base+0x050C))

/* Lv1 DCM */
#define MD_TOP_MDMCU_DCM_CON0     ((volatile UINT32P)(CONFIG_base+0x0510))
#define MD_TOP_MDMCU_DCM_CON1     ((volatile UINT32P)(CONFIG_base+0x0514))
#define MD_TOP_MDBUS_DCM_CON0     ((volatile UINT32P)(CONFIG_base+0x0518))
#define MD_TOP_MDBUS_DCM_CON1     ((volatile UINT32P)(CONFIG_base+0x051C))

/* Lv1 LPM */
#define MD_TOP_DCM_DEBUG_CON0     ((volatile UINT32P)(CONFIG_base+0x0530))
#define MD_TOP_DCM_DEBUG_STATUS0  ((volatile UINT32P)(CONFIG_base+0x0538))
#define MD_TOP_DCM_DEBUG_STATUS1  ((volatile UINT32P)(CONFIG_base+0x053C))
#define MD_TOP_DCM_DEBUG_STATUS2  ((volatile UINT32P)(CONFIG_base+0x0540))
#define MD_TOP_DCM_DEBUG_STATUS3  ((volatile UINT32P)(CONFIG_base+0x0544))
#define MD_TOP_DCM_DEBUG_STATUS4  ((volatile UINT32P)(CONFIG_base+0x0548))
#define MD_TOP_DCM_DEBUG_STATUS5  ((volatile UINT32P)(CONFIG_base+0x054C))

/* alias to LPM */
#define MD_L1_LPM_CON0            (MD_TOP_DCM_DEBUG_CON0)
#define MD_L1_LPM_STATUS0         (MD_TOP_DCM_DEBUG_STATUS0)
#define MD_L1_LPM_STATUS1         (MD_TOP_DCM_DEBUG_STATUS1)
#define MD_L1_LPM_STATUS2         (MD_TOP_DCM_DEBUG_STATUS2)
#define MD_L1_LPM_STATUS3         (MD_TOP_DCM_DEBUG_STATUS3)
#define MD_L1_LPM_STATUS4         (MD_TOP_DCM_DEBUG_STATUS4)
#define MD_L1_LPM_STATUS5         (MD_TOP_DCM_DEBUG_STATUS5)
#define MD_L2_LPM_CON0            (MD_DCM_DEBUG_CON0)
#define MD_L2_LPM_STATUS0         (MD_DCM_DEBUG_STATUS0)
#define MD_L2_LPM_STATUS1         (MD_DCM_DEBUG_STATUS1)
#define MD_L2_LPM_STATUS2         (MD_DCM_DEBUG_STATUS2)
#define MD_L2_LPM_STATUS3         (MD_DCM_DEBUG_STATUS3)
#define MD_L2_LPM_STATUS4         (MD_DCM_DEBUG_STATUS4)
#define MD_L2_LPM_STATUS5         (MD_DCM_DEBUG_STATUS5)

/* workaround to OSTD header */
extern kal_bool OSTD_Infinite_Sleep_Query(void);

#endif /* __DRV_DCM_MT6752_MD2__ */
