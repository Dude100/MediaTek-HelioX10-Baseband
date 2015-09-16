/*****************************************************************************
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

/*******************************************************************************
 * Filename:
 * ---------
 *   drv_dcm.h
 *
 * Project:
 * --------
 *   MT6290
 *
 * Description:
 * ------------
 *   dcm driver
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
 * LR9.W1421 merge from MOLY CL#572419, CL#575172
 *
 * removed!
 * removed!
 * Merging
 *  	
 * 	//MOLY_CBr/chin-chieh.hung/MT6595E1_BRING_UP_DEV_W1402p7/mcu/driver/devdrv/dcm/inc/drv_dcm.h
 *  	
 * 	to //MOLY/TRUNK/MOLY/mcu/driver/devdrv/dcm/inc/drv_dcm.h
 *
 * removed!
 * removed!
 * Add DCM flow
 *
 * removed!
 * removed!
 * ROME Porting
 *
 * removed!
 * removed!
 * fix error setting
 *
 * removed!
 * removed!
 * .remove fakeAPI
 ****************************************************************************/

#ifndef __DCM_REG_H__
#define __DCM_REG_H__

#include <reg_base.h>
#include <intrCtrl.h>

#if defined(DCM_ENABLE)
#include "pll.h"

#if defined(__MD2__) && defined(MT6752)
# include "drv_dcm_mt6752_md2.h"
#else /* __MD1__ */

//#define MD_GLOBAL_CON0                 (CONFIG_base+0x0450)
//#define MD_GLOBAL_SET0                (CONFIG_base+0x0454)
//#define MD_GLOBAL_CLR0              (CONFIG_base+0x0458)
#define MD_GLOBAL_CON1                 (CONFIG_base+0x045c)
//#define MD_GLOBAL_CON2                 (CONFIG_base+0x0460)
#define MD_TOP_MDMCU_DCM_CON0        (CONFIG_base+0x0510)
#define MD_TOP_MDMCU_DCM_CON1        (CONFIG_base+0x0514)
#define MD_TOP_MDBUS_DCM_CON0        (CONFIG_base+0x0518)
#define MD_TOP_MDBUS_DCM_CON1        (CONFIG_base+0x051C)

#define MD_L1_LPM_CON0         ((volatile UINT32P)(CONFIG_base+0x0530))
#define MD_L1_LPM_STATUS0     ((volatile UINT32P)(CONFIG_base+0x0538))
#define MD_L1_LPM_STATUS1    ((volatile UINT32P)(CONFIG_base+0x053C))
#define MD_L1_LPM_STATUS2    ((volatile UINT32P)(CONFIG_base+0x0540))
#define MD_L1_LPM_STATUS3     ((volatile UINT32P)(CONFIG_base+0x0544))
#define MD_L1_LPM_STATUS4    ((volatile UINT32P)(CONFIG_base+0x0548))
#define MD_L1_LPM_STATUS5    ((volatile UINT32P)(CONFIG_base+0x054C))


#define MD_L2_LPM_CON0        ((volatile UINT32P)(CONFIG_base+0x0470))
#define MD_L2_LPM_STATUS0     ((volatile UINT32P)(CONFIG_base+0x0478))
#define MD_L2_LPM_STATUS1    ((volatile UINT32P)(CONFIG_base+0x047C))
#define MD_L2_LPM_STATUS2     ((volatile UINT32P)(CONFIG_base+0x0480))
#define MD_L2_LPM_STATUS3     ((volatile UINT32P)(CONFIG_base+0x0484))
#define MD_L2_LPM_STATUS4    ((volatile UINT32P)(CONFIG_base+0x0488))
#define MD_L2_LPM_STATUS5    ((volatile UINT32P)(CONFIG_base+0x048C))

#define DCM_LPM_ENABLE 1
#undef  DCM_LPM_ENABLE
#endif /* __MD2__ */
#endif /* DCM_ENABLE */

typedef enum {
    PLL_2G_TALKING = 0xFD00,
    PLL_3G_TALKING,
    PLL_VIDEO_PLAY
} pll_use_scenario_t;

extern kal_int32 arm_enter_standby_mode(kal_int32);

#endif /* end of __PCM_REG_H__ */
