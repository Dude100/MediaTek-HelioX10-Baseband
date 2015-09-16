/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2013
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
 *   bl_cfgclt.c
 *
 * Project:
 * --------
 *   Bootloader
 *
 * Description:
 * ------------
 *   MDCFGCTL driver
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
 * 	<saved by Perforce>
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * 	.
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
 * .
 ****************************************************************************/
#include "kal_general_types.h"
#include "bl_drv_common.h"
#include "bl_cfgctl.h"

#define SPECIAL_REG_KEY               (0x34680000)

void bl_cfgctl_ownership_init()
{
    kal_uint32 val;

    //Always disable cache back door access to avoid abnormal access
    val = DRV_Reg32(REG_AXI_OWN) & (~(MD_CACHE_DEBUG_MASK));

#if defined(__SMART_PHONE_MODEM__) && !(defined(__X_BOOTING__))        //router

    //MISC own
    val = DRV_Reg32(REG_MISC_OWN) & (~(AUXADC_OWN_MASK));
    DRV_WriteReg32(REG_MISC_OWN, val | AUXADC_OWN_AP);

    //AXI own
    val = DRV_Reg32(REG_AXI_OWN) & (~(LTE_PHY_MASK));
    DRV_WriteReg32(REG_AXI_OWN, val | LTE_PHY_MD|LTE_PHY_AP);

    //APAHB own
    val = DRV_Reg32(REG_APAHB_OWN) & (~(EHPI_SLAVE_MASK | USB30_MAC_MASK|USB30_PHY_MASK|SPI_REG_MASK|USB20_MAC_MASK|USB20_PHY_MASK|MSDC_0_MASK|MSDC_1_MASK));
    DRV_WriteReg32(REG_APAHB_OWN, val |EHPI_SLAVE_MD |USB30_MAC_AP|USB30_PHY_AP|SPI_REG_AP|USB20_MAC_AP|USB20_PHY_AP|MSDC_0_AP|MSDC_1_AP);

    //APPERIAPB own
    val = DRV_Reg32(REG_APPERIAPB_OWN) & (~(EHPI_HOST_MASK|NLI_ARB_MASK|IPSEC_MASK|NIC_MASK|PFC_MASK));
    DRV_WriteReg32(REG_APPERIAPB_OWN, val |EHPI_HOST_AP|NLI_ARB_AP|IPSEC_AP|NIC_AP|PFC_AP);

    //MDPERIAPB own
    //todo:I2C need owner confirm
    val = DRV_Reg32(REG_MDPERIAPB_OWN) & (~(SHARED_UART0_MASK|I2C_MASK|RTC_MASK));
    DRV_WriteReg32(REG_MDPERIAPB_OWN, val | SHARED_UART0_AP|I2C_AP|RTC_AP);

    //CFGAPB own
    val = DRV_Reg32(REG_CFGAPB_OWN) & (~(MD_TOPSM_MASK |AP_CLKCTL_MASK|AP_TOPSM_MASK | APGPIO_EINT_MASK));
    DRV_WriteReg32(REG_CFGAPB_OWN, val | MD_TOPSM_MD | MD_TOPSM_AP |AP_CLKCTL_MD|AP_CLKCTL_AP|AP_TOPSM_MD|AP_TOPSM_AP|APGPIO_EINT_MD|APGPIO_EINT_AP);

#elif defined(__MODEM_CARD__) && !(defined(__TRADITIONAL_MODEM_CARD__)) && !(defined(__X_BOOTING__))        //hosted dongle

    //MISC own
    val = DRV_Reg32(REG_MISC_OWN) & (~(AUXADC_OWN_MASK));
    DRV_WriteReg32(REG_MISC_OWN, val | AUXADC_OWN_AP);

    //AXI own
    val = DRV_Reg32(REG_AXI_OWN) & (~(LTE_PHY_MASK));
    DRV_WriteReg32(REG_AXI_OWN, val | LTE_PHY_MD|LTE_PHY_AP);

    //APAHB own
    val = DRV_Reg32(REG_APAHB_OWN) & (~(EHPI_SLAVE_MASK));
    DRV_WriteReg32(REG_APAHB_OWN, val |EHPI_SLAVE_MD);

    //APPERIAPB own
    val = DRV_Reg32(REG_APPERIAPB_OWN) & (~(IPSEC_MASK|NIC_MASK));
    DRV_WriteReg32(REG_APPERIAPB_OWN, val |IPSEC_AP|NIC_AP);

    //MDPERIAPB own
    val = DRV_Reg32(REG_MDPERIAPB_OWN) & (~(RTC_MASK));
    DRV_WriteReg32(REG_MDPERIAPB_OWN, val |RTC_AP); 

    //CFGAPB own
    val = DRV_Reg32(REG_CFGAPB_OWN) & (~(MD_TOPSM_MASK | AP_CLKCTL_MASK|AP_TOPSM_MASK| APGPIO_EINT_MASK));
    DRV_WriteReg32(REG_CFGAPB_OWN, val | MD_TOPSM_MD | MD_TOPSM_AP | AP_CLKCTL_MD|AP_CLKCTL_AP|AP_TOPSM_MD|AP_TOPSM_AP|APGPIO_EINT_MD|APGPIO_EINT_AP);

#else //traditional dongle or external phone

    //MISC own

    //AXI own

    //APAHB own
    val = DRV_Reg32(REG_APAHB_OWN) & (~(EHPI_SLAVE_MASK));
    DRV_WriteReg32(REG_APAHB_OWN, val |EHPI_SLAVE_MD);

    //APPERIAPB own
    val = DRV_Reg32(REG_APPERIAPB_OWN) & (~(NIC_MASK));
    DRV_WriteReg32(REG_APPERIAPB_OWN, val |NIC_MD);

    //MDPERIAPB own

    //CFGAPB own

#endif
    
}

void bl_cfgctl_clear_misc()
{
    DRV_WriteReg32(REG_SW_MISC, SPECIAL_REG_KEY);
}

void bl_cfgctl_set_misc(kal_uint32 data)
{
    DRV_WriteReg32(REG_SW_MISC, SPECIAL_REG_KEY|data);
}

kal_uint32 bl_cfgctl_save_and_set_usbown(kal_uint32 own)
{
    kal_uint32 own_state;
    kal_uint32 val;

    //Save original ownership status
    own_state = DRV_Reg32(REG_APAHB_OWN) & (USB30_MAC_MASK|USB30_PHY_MASK);

    //Clear USB ownership setting
    val = DRV_Reg32(REG_APAHB_OWN) & (~(USB30_MAC_MASK|USB30_PHY_MASK));

    //Set USB to MD own
    DRV_WriteReg32(REG_APAHB_OWN, val |own);

    return own_state;
}

void bl_cfgctl_restore_usbown(kal_uint32 own)
{
    kal_uint32 val;

    //Clear USB ownership setting
    val = DRV_Reg32(REG_APAHB_OWN) & (~(USB30_MAC_MASK|USB30_PHY_MASK));

    //Restore USB own
    DRV_WriteReg32(REG_APAHB_OWN, val |own);
}
