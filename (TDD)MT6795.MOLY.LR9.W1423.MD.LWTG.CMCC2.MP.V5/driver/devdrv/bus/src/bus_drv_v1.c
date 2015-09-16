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
 *   bus_drv.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intended for BUS driver.
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

#include "bus_drv.h"
#include "config_hw.h"
#include "drvpdn.h"

#include "cp15.h"
#include "dcm_sw.h"
#include "kal_public_api.h"
#include "sync_data.h"

#define MD_MCU_CON2              (volatile kal_uint32 *)(CONFIG_base + 0x0108)
#define MD_MCU2EMI_CON0          (volatile kal_uint32 *)(CONFIG_base + 0x0200)
#define MD_MCU2EMI_STATUS0       (volatile kal_uint32 *)(CONFIG_base + 0x0204)

#define MD2EMI_ULTRA_HIGH_SET0   (volatile kal_uint32 *)(CONFIG_base + 0x0404)
#define MD2EMI_ULTRA_HIGH_CLR0   (volatile kal_uint32 *)(CONFIG_base + 0x0408)

extern kal_uint32 SaveAndSetIRQMask(void);
extern void RestoreIRQMask(kal_uint32);

/*************************************************************************
* FUNCTION
*  enableVirtualMapping
*
* DESCRIPTION
*  Enable cacheable virtual address mapping: bank F remap to bank 0.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
*************************************************************************/
void enableVirtualMapping(void)
{
    return;
}

/*************************************************************************
* FUNCTION
*  disableVirtualMapping
*
* DESCRIPTION
*  Disable cacheable virtual address mapping: bank F no remap.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
*************************************************************************/
void disableVirtualMapping(void)
{
    return;
}

/*************************************************************************
* FUNCTION
*  enableMcuOutstanding
*
* DESCRIPTION
*  Enable MCU to EMI AXI bus outstanding.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
*************************************************************************/
void enableMcuOutstanding(void)
{
    return;
}

/*************************************************************************
* FUNCTION
*  enablePrefetchBuffer
*
* DESCRIPTION
*  Enable instruction prefetch buffer.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
*************************************************************************/
#if defined(__MTK_TARGET__)
__attribute__ ((section("INTSRAM_ROCODE"))) void enablePrefetchBuffer(void)
#else
void enablePrefetchBuffer(void)
#endif
{
#if defined(MT6752) && defined(__MD2__)
    if( cp15_is_icache_enabled() )
    {
        // clear PFB CG
        PDN_CLR(PDN_PF_BUFF);
        *MD_MCU2EMI_CON0 |= 0x00000001;
    }
    else
    {
        ASSERT(0);
    }
#endif /* defined(MT6752) && defined(__MD2__) */
    return;
}

/*************************************************************************
* FUNCTION
*  disablePrefetchBuffer
*
* DESCRIPTION
*  Disable instruction prefetch buffer.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
*************************************************************************/
#if defined(__MTK_TARGET__)
__attribute__ ((section("INTSRAM_ROCODE"))) void disablePrefetchBuffer(void)
#else
void disablePrefetchBuffer(void)
#endif
{
#if defined(MT6752) && defined(__MD2__)
    
#if defined(DCM_ENABLE)
    DCM_MCUBUS_DCM_OFF(1);
#endif

        *MD_MCU2EMI_CON0 &= ~0x00000001;
        while( !(*MD_MCU2EMI_STATUS0 & 0x00000001) )  ;
        
    Inst_Sync_Barrier();
    
#if defined(DCM_ENABLE)
    DCM_MCUBUS_DCM_OFF(0);
#endif
    
#endif /* defined(MT6752) && defined(__MD2__) */

    return;
}

void Bus_Init(void)
{   
#if defined(MT6752) && defined(__MD2__)
    //enable pfb    
    //enablePrefetchBuffer();

    //ultra high to ap EMI, must set on MD2 case
    *MD2EMI_ULTRA_HIGH_SET0 = 0x00000003;

    //*MD_MCU_CON2 |= 0x00000005;
#endif /* defined(MT6752) && defined(__MD2__) */
    return;
}


