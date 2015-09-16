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
 ****************************************************************************/

/*****************************************************************************
 * Filename:
 * ---------
 *   drvpdn_inline_mt6752_md1.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   PDN Driver (C Inline Implementation) for MT6752
 *      - PDN_SET(), PDN_CLR() is for Bus Clock Gating/Ungating
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
 * Fix some MD2 build error and code cleanup
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 ****************************************************************************/

#ifndef __DRVPDN_INLINE_MT6752_MD1_H__
#define __DRVPDN_INLINE_MT6752_MD1_H__

#if defined(__DRVPDN_INLINE_MT6752_MD2_H__)
    #error "MD1 & MD2 header should not be included at the same time"
#endif

/*****************************************************************************
 * Locally Used Options
 ****************************************************************************/
#define INTERRUPT_PROTECT       1

/*****************************************************************************
 * Include header files
 ****************************************************************************/
#include "kal_general_types.h"
#include "intrCtrl.h"
#include "pdn_hw_mt6752_md1_series.h"

/*****************************************************************************
 * Locally Used Macros and Data Types
 ****************************************************************************/
typedef enum {

    PDN_MDGDMA,
    PDN_BOOT_SLV,
    PDN_ABM,
    PDN_ADOE,
    PDN_MDUART,
    PDN_DBG,
    PDN_OSTIMER,
    PDN_GPT,
    PDN_LPM,
    PDN_TOPSM,
    PDN_USIM1,
    PDN_USIM2,
    PDN_CLDMA,
    PDN_RSVD13,
    PDN_MDMCU_BUSMON,
    PDN_MDINFRA_BUSMON,
    PDN_ELM,
    PDN_ALC,
    PDN_PFB,

    PDN_ATB,
    PDN_BYCACC,
    PDN_AFC3G,
    PDN_WCDMATIMER,
    PDN_BPI3G,
    PDN_BSI3G,

    PDN_GCU,
    PDN_FCS,
    PDN_DIV,
    PDN_AFC2G_T,
    PDN_BPI2G_T,
    PDN_BSI2G_T,
    PDN_TDMA,

    PDN_AFC2G,
    PDN_BPI2G,
    PDN_BSI2G,

    PDN_AHB2DSPIO,
    PDN_IRDBG,
    PDN_TXBUF,
    PDN_RXBUF,
    PDN_IRDMA,
    PDN_GCC,

    PDN_BFE,
    PDN_VAFE,
    PDN_APC_PRE,

    PDN_APC,

    PDN_MAX_DEV

} PDN_DEVICE;


#define DRVPDN_REG(addr)                            *(volatile kal_uint32 *)(addr)
#define DRVPDN_REG16(addr)                          *(volatile kal_uint16 *)(addr)

#define DRVPDN_4GIP_OFF(regnum, module)             DRVPDN_REG(MD_GLOBAL_SET ## regnum) = (CG_ ## module)
#define DRVPDN_2GIP_OFF(regnum, module)             DRVPDN_REG(REG_MODEM_CG_SET ## regnum) = (CG_ ## module)
#define DRVPDN_3GIP_OFF(regnum, module)             DRVPDN_REG(REG_MODEM_CG_SET ## regnum) = (CG_ ## module)
#define DRVPDN_MD2GSYSIP_OFF(regnum, module)        DRVPDN_REG16(REG_MD2GSYS_CG_SET ## regnum) = (CG_ ## module)
#define DRVPDN_4GIP_MISC_OFF(regnum, module)        DRVPDN_REG(MD_MCU_MISC ## regnum) = (DRVPDN_REG(MD_MCU_MISC ## regnum) | (CG_ ## module))

#define DRVPDN_4GIP_ON(regnum, module)              DRVPDN_REG(MD_GLOBAL_CLR ## regnum) = (CG_ ## module)
#define DRVPDN_2GIP_ON(regnum, module)              DRVPDN_REG(REG_MODEM_CG_CLR ## regnum) = (CG_ ## module)
#define DRVPDN_3GIP_ON(regnum, module)              DRVPDN_REG(REG_MODEM_CG_CLR ## regnum) = (CG_ ## module)
#define DRVPDN_MD2GSYSIP_ON(regnum, module)         DRVPDN_REG16(REG_MD2GSYS_CG_CLR ## regnum) = (CG_ ## module)
#define DRVPDN_4GIP_MISC_ON(regnum, module)         DRVPDN_REG(MD_MCU_MISC ## regnum) = (DRVPDN_REG(MD_MCU_MISC ## regnum) & ~(CG_ ## module))

#define DRVPDN_4GIP_STS(regnum, module)             (DRVPDN_REG(MD_GLOBAL_CON ## regnum) & (CG_ ## module))
#define DRVPDN_2GIP_STS(regnum, module)             (DRVPDN_REG(REG_MODEM_CG_CON ## regnum) & (CG_ ## module))
#define DRVPDN_3GIP_STS(regnum, module)             (DRVPDN_REG(REG_MODEM_CG_CON ## regnum) & (CG_ ## module))
#define DRVPDN_MD2GSYSIP_STS(regnum, module)        (DRVPDN_REG16(REG_MD2GSYS_CG_CON ## regnum) & (CG_ ## module))
#define DRVPDN_4GIP_MISC_STS(regnum, module)        (DRVPDN_REG(MD_MCU_MISC ## regnum) & (CG_ ## module))


DRVPDN_INLINE_MODIFIER DRVPDN_INLINE void PDN_SET(PDN_DEVICE dev)
{
    #if INTERRUPT_PROTECT
    kal_uint32 mask;
    mask = SaveAndSetIRQMask();
    #endif

    switch (dev)
    {
        case PDN_MDGDMA:
            DRVPDN_4GIP_OFF(0, MDGDMA);
            break;
        case PDN_BOOT_SLV:
            DRVPDN_4GIP_OFF(0, BOOT_SLV);
            break;
        case PDN_ABM:
            DRVPDN_4GIP_OFF(0, ABM);
            break;
        case PDN_ADOE:
            DRVPDN_4GIP_OFF(0, ADOE);
            break;
        case PDN_MDUART:
            DRVPDN_4GIP_OFF(0, MDUART);
            break;
        case PDN_DBG:
            DRVPDN_4GIP_OFF(0, DBG);
            break;
        case PDN_OSTIMER:
            DRVPDN_4GIP_OFF(0, OSTIMER);
            break;
        case PDN_GPT:
            DRVPDN_4GIP_OFF(0, GPT);
            break;
        case PDN_TOPSM:
            DRVPDN_4GIP_OFF(0, TOPSM);
            break;
        case PDN_LPM:
            DRVPDN_4GIP_OFF(0, LPM);
            break;
        case PDN_USIM1:
            DRVPDN_4GIP_OFF(0, USIM1);
            break;
        case PDN_USIM2:
            DRVPDN_4GIP_OFF(0, USIM2);
            break;
        case PDN_CLDMA:
            DRVPDN_4GIP_OFF(0, CLDMA);
            break;
        case PDN_RSVD13:
            DRVPDN_4GIP_OFF(0, RSVD13);
            break;
        case PDN_MDMCU_BUSMON:
            DRVPDN_4GIP_MISC_OFF(1, MDMCU_BUSMON_HF);
            DRVPDN_4GIP_MISC_OFF(1, MDMCU_BUSMON_HS);
            break;
        case PDN_MDINFRA_BUSMON:
            DRVPDN_4GIP_OFF(0, MDINFRA_BUSMON_HF);
            DRVPDN_4GIP_OFF(0, MDINFRA_BUSMON_HS);
            break;
        case PDN_ELM:
            DRVPDN_4GIP_OFF(0, ELM);
            break;
        case PDN_ALC:
            DRVPDN_4GIP_OFF(0, ALC);
            break;
        case PDN_PFB:
            DRVPDN_4GIP_OFF(0, PFB);
            break;

        /* IPs reside in 3G Block */
        case PDN_ATB:
            DRVPDN_3GIP_OFF(0, ATB);
            break;
        case PDN_BYCACC:
            DRVPDN_3GIP_OFF(0, BYC_ACC);
            break;
        case PDN_AFC3G:
            DRVPDN_3GIP_OFF(0, AFC_3G);
            break;
        case PDN_WCDMATIMER:
            DRVPDN_3GIP_OFF(0, WTIMER);
            break;
        case PDN_BPI3G:
            DRVPDN_3GIP_OFF(0, BPI_3G);
            break;
        case PDN_BSI3G:
            DRVPDN_3GIP_OFF(0, BSI_3G);
            break;

        /* IPs reside in 2G Block */
        case PDN_GCU:
            DRVPDN_2GIP_OFF(2, GCU);
            break;
        case PDN_FCS:
            DRVPDN_2GIP_OFF(2, FCS);
            break;
        case PDN_DIV:
            DRVPDN_2GIP_OFF(2, DIVIDER);
            break;
        case PDN_AFC2G_T:
            DRVPDN_2GIP_OFF(2, AFC_2G_T);
            break;
        case PDN_BPI2G_T:
            DRVPDN_2GIP_OFF(2, BPI_2G_T);
            break;
        case PDN_BSI2G_T:
            DRVPDN_2GIP_OFF(2, BSI_2G_T);
            break;
        case PDN_TDMA:
            DRVPDN_2GIP_OFF(2, TDMA);
            break;

        case PDN_AFC2G:
            DRVPDN_2GIP_OFF(4, AFC_2G);
            break;
        case PDN_BPI2G:
            DRVPDN_2GIP_OFF(4, BPI_2G);
            break;
        case PDN_BSI2G:
            DRVPDN_2GIP_OFF(4, BSI_2G);
            break;

        case PDN_AHB2DSPIO:
            DRVPDN_MD2GSYSIP_OFF(0, AHB2SDIO);
            break;
        case PDN_IRDBG:
            DRVPDN_MD2GSYSIP_OFF(0, IRDBG);
            break;
        case PDN_TXBUF:
            DRVPDN_MD2GSYSIP_OFF(0, TXBUF);
            break;
        case PDN_RXBUF:
            DRVPDN_MD2GSYSIP_OFF(0, RXBUF);
            break;
        case PDN_IRDMA:
            DRVPDN_MD2GSYSIP_OFF(0, IRDMA);
            break;
        case PDN_GCC:
            DRVPDN_MD2GSYSIP_OFF(0, GCC);
            break;

        case PDN_BFE:
            DRVPDN_MD2GSYSIP_OFF(2, BFE);
            break;
        case PDN_VAFE:
            DRVPDN_MD2GSYSIP_OFF(2, VAFE);
            break;
        case PDN_APC_PRE:
            DRVPDN_MD2GSYSIP_OFF(2, APC_PRE);
            break;

        case PDN_APC:
            DRVPDN_MD2GSYSIP_OFF(4, APC);
            break;

        case PDN_MAX_DEV:
            break;
    }

    #if INTERRUPT_PROTECT
    RestoreIRQMask(mask);
    #endif
}

DRVPDN_INLINE_MODIFIER DRVPDN_INLINE void PDN_CLR(PDN_DEVICE dev)
{
    #if INTERRUPT_PROTECT
    kal_uint32 mask;
    mask = SaveAndSetIRQMask();
    #endif

    switch (dev)
    {
        case PDN_MDGDMA:
            DRVPDN_4GIP_ON(0, MDGDMA);
            break;
        case PDN_BOOT_SLV:
            DRVPDN_4GIP_ON(0, BOOT_SLV);
            break;
        case PDN_ABM:
            DRVPDN_4GIP_ON(0, ABM);
            break;
        case PDN_ADOE:
            DRVPDN_4GIP_ON(0, ADOE);
            break;
        case PDN_MDUART:
            DRVPDN_4GIP_ON(0, MDUART);
            break;
        case PDN_DBG:
            DRVPDN_4GIP_ON(0, DBG);
            break;
        case PDN_OSTIMER:
            DRVPDN_4GIP_ON(0, OSTIMER);
            break;
        case PDN_GPT:
            DRVPDN_4GIP_ON(0, GPT);
            break;
        case PDN_TOPSM:
            DRVPDN_4GIP_ON(0, TOPSM);
            break;
        case PDN_LPM:
            DRVPDN_4GIP_ON(0, LPM);
            break;
        case PDN_USIM1:
            DRVPDN_4GIP_ON(0, USIM1);
            break;
        case PDN_USIM2:
            DRVPDN_4GIP_ON(0, USIM2);
            break;
        case PDN_CLDMA:
            DRVPDN_4GIP_ON(0, CLDMA);
            break;
        case PDN_RSVD13:
            DRVPDN_4GIP_ON(0, RSVD13);
            break;
        case PDN_MDMCU_BUSMON:
            DRVPDN_4GIP_MISC_ON(1, MDMCU_BUSMON_HF);
            DRVPDN_4GIP_MISC_ON(1, MDMCU_BUSMON_HS);
            break;
        case PDN_MDINFRA_BUSMON:
            DRVPDN_4GIP_ON(0, MDINFRA_BUSMON_HF);
            DRVPDN_4GIP_ON(0, MDINFRA_BUSMON_HS);
            break;
        case PDN_ELM:
            DRVPDN_4GIP_ON(0, ELM);
            break;
        case PDN_ALC:
            DRVPDN_4GIP_ON(0, ALC);
            break;
        case PDN_PFB:
            DRVPDN_4GIP_ON(0, PFB);
            break;

        /* IPs reside in 3G Block */
        case PDN_ATB:
            DRVPDN_3GIP_ON(0, ATB);
            break;
        case PDN_BYCACC:
            DRVPDN_3GIP_ON(0, BYC_ACC);
            break;
        case PDN_AFC3G:
            DRVPDN_3GIP_ON(0, AFC_3G);
            break;
        case PDN_WCDMATIMER:
            DRVPDN_3GIP_ON(0, WTIMER);
            break;
        case PDN_BPI3G:
            DRVPDN_3GIP_ON(0, BPI_3G);
            break;
        case PDN_BSI3G:
            DRVPDN_3GIP_ON(0, BSI_3G);
            break;

        /* IPs reside in 2G Block */
        case PDN_GCU:
            DRVPDN_2GIP_ON(2, GCU);
            break;
        case PDN_FCS:
            DRVPDN_2GIP_ON(2, FCS);
            break;
        case PDN_DIV:
            DRVPDN_2GIP_ON(2, DIVIDER);
            break;
        case PDN_AFC2G_T:
            DRVPDN_2GIP_ON(2, AFC_2G_T);
            break;
        case PDN_BPI2G_T:
            DRVPDN_2GIP_ON(2, BPI_2G_T);
            break;
        case PDN_BSI2G_T:
            DRVPDN_2GIP_ON(2, BSI_2G_T);
            break;
        case PDN_TDMA:
            DRVPDN_2GIP_ON(2, TDMA);
            break;

        case PDN_AFC2G:
            DRVPDN_2GIP_ON(4, AFC_2G);
            break;
        case PDN_BPI2G:
            DRVPDN_2GIP_ON(4, BPI_2G);
            break;
        case PDN_BSI2G:
            DRVPDN_2GIP_ON(4, BSI_2G);
            break;

        case PDN_AHB2DSPIO:
            DRVPDN_MD2GSYSIP_ON(0, AHB2SDIO);
            break;
        case PDN_IRDBG:
            DRVPDN_MD2GSYSIP_ON(0, IRDBG);
            break;
        case PDN_TXBUF:
            DRVPDN_MD2GSYSIP_ON(0, TXBUF);
            break;
        case PDN_RXBUF:
            DRVPDN_MD2GSYSIP_ON(0, RXBUF);
            break;
        case PDN_IRDMA:
            DRVPDN_MD2GSYSIP_ON(0, IRDMA);
            break;
        case PDN_GCC:
            DRVPDN_MD2GSYSIP_ON(0, GCC);
            break;

        case PDN_BFE:
            DRVPDN_MD2GSYSIP_ON(2, BFE);
            break;
        case PDN_VAFE:
            DRVPDN_MD2GSYSIP_ON(2, VAFE);
            break;
        case PDN_APC_PRE:
            DRVPDN_MD2GSYSIP_ON(2, APC_PRE);
            break;

        case PDN_APC:
            DRVPDN_MD2GSYSIP_ON(4, APC);
            break;

        case PDN_MAX_DEV:
            break;
    }

    #if INTERRUPT_PROTECT
    RestoreIRQMask(mask);
    #endif
}


DRVPDN_INLINE_MODIFIER DRVPDN_INLINE kal_uint32 PDN_STS(PDN_DEVICE dev)
{
    kal_uint32 ret = 0;

    #if INTERRUPT_PROTECT
    kal_uint32 mask;
    mask = SaveAndSetIRQMask();
    #endif

    switch (dev)
    {
        case PDN_MDGDMA:
            ret = DRVPDN_4GIP_STS(0, MDGDMA);
            break;
        case PDN_BOOT_SLV:
            ret = DRVPDN_4GIP_STS(0, BOOT_SLV);
            break;
        case PDN_ABM:
            ret = DRVPDN_4GIP_STS(0, ABM);
            break;
        case PDN_ADOE:
            ret = DRVPDN_4GIP_STS(0, ADOE);
            break;
        case PDN_MDUART:
            ret = DRVPDN_4GIP_STS(0, MDUART);
            break;
        case PDN_DBG:
            ret = DRVPDN_4GIP_STS(0, DBG);
            break;
        case PDN_OSTIMER:
            ret = DRVPDN_4GIP_STS(0, OSTIMER);
            break;
        case PDN_GPT:
            ret = DRVPDN_4GIP_STS(0, GPT);
            break;
        case PDN_TOPSM:
            ret = DRVPDN_4GIP_STS(0, TOPSM);
            break;
        case PDN_LPM:
            ret = DRVPDN_4GIP_STS(0, LPM);
            break;
        case PDN_USIM1:
            ret = DRVPDN_4GIP_STS(0, USIM1);
            break;
        case PDN_USIM2:
            ret = DRVPDN_4GIP_STS(0, USIM2);
            break;
        case PDN_CLDMA:
            ret = DRVPDN_4GIP_STS(0, CLDMA);
            break;
        case PDN_RSVD13:
            ret = DRVPDN_4GIP_STS(0, RSVD13);
            break;
        case PDN_MDMCU_BUSMON:
            ret = DRVPDN_4GIP_MISC_STS(1, MDMCU_BUSMON_HF) && DRVPDN_4GIP_MISC_STS(1, MDMCU_BUSMON_HS);
            break;
        case PDN_MDINFRA_BUSMON:
            ret = DRVPDN_4GIP_STS(0, MDINFRA_BUSMON_HF) && DRVPDN_4GIP_STS(0, MDINFRA_BUSMON_HS);
            break;
        case PDN_ELM:
            ret = DRVPDN_4GIP_STS(0, ELM);
            break;
        case PDN_ALC:
            ret = DRVPDN_4GIP_STS(0, ALC);
            break;
        case PDN_PFB:
            ret = DRVPDN_4GIP_STS(0, PFB);
            break;

        /* IPs reside in 3G Block */
        case PDN_ATB:
            ret = DRVPDN_3GIP_STS(0, ATB);
            break;
        case PDN_BYCACC:
            ret = DRVPDN_3GIP_STS(0, BYC_ACC);
            break;
        case PDN_AFC3G:
            ret = DRVPDN_3GIP_STS(0, AFC_3G);
            break;
        case PDN_WCDMATIMER:
            ret = DRVPDN_3GIP_STS(0, WTIMER);
            break;
        case PDN_BPI3G:
            ret = DRVPDN_3GIP_STS(0, BPI_3G);
            break;
        case PDN_BSI3G:
            ret = DRVPDN_3GIP_STS(0, BSI_3G);
            break;

        /* IPs reside in 2G Block */
        case PDN_GCU:
            ret = DRVPDN_2GIP_STS(2, GCU);
            break;
        case PDN_FCS:
            ret = DRVPDN_2GIP_STS(2, FCS);
            break;
        case PDN_DIV:
            ret = DRVPDN_2GIP_STS(2, DIVIDER);
            break;
        case PDN_AFC2G_T:
            ret = DRVPDN_2GIP_STS(2, AFC_2G_T);
            break;
        case PDN_BPI2G_T:
            ret = DRVPDN_2GIP_STS(2, BPI_2G_T);
            break;
        case PDN_BSI2G_T:
            ret = DRVPDN_2GIP_STS(2, BSI_2G_T);
            break;
        case PDN_TDMA:
            ret = DRVPDN_2GIP_STS(2, TDMA);
            break;

        case PDN_AFC2G:
            ret = DRVPDN_2GIP_STS(4, AFC_2G);
            break;
        case PDN_BPI2G:
            ret = DRVPDN_2GIP_STS(4, BPI_2G);
            break;
        case PDN_BSI2G:
            ret = DRVPDN_2GIP_STS(4, BSI_2G);
            break;

        case PDN_AHB2DSPIO:
            ret = DRVPDN_MD2GSYSIP_STS(0, AHB2SDIO);
            break;
        case PDN_IRDBG:
            ret = DRVPDN_MD2GSYSIP_STS(0, IRDBG);
            break;
        case PDN_TXBUF:
            ret = DRVPDN_MD2GSYSIP_STS(0, TXBUF);
            break;
        case PDN_RXBUF:
            ret = DRVPDN_MD2GSYSIP_STS(0, RXBUF);
            break;
        case PDN_IRDMA:
            ret = DRVPDN_MD2GSYSIP_STS(0, IRDMA);
            break;
        case PDN_GCC:
            ret = DRVPDN_MD2GSYSIP_STS(0, GCC);
            break;

        case PDN_BFE:
            ret = DRVPDN_MD2GSYSIP_STS(2, BFE);
            break;
        case PDN_VAFE:
            ret = DRVPDN_MD2GSYSIP_STS(2, VAFE);
            break;
        case PDN_APC_PRE:
            ret = DRVPDN_MD2GSYSIP_STS(2, APC_PRE);
            break;

        case PDN_APC:
            ret = DRVPDN_MD2GSYSIP_STS(4, APC);
            break;

        case PDN_MAX_DEV:
            break;
    }

    #if INTERRUPT_PROTECT
    RestoreIRQMask(mask);
    #endif

    return ret;
}

#undef DRVPDN_REG
#undef DRVPDN_REG16
#undef DRVPDN_4GIP_OFF
#undef DRVPDN_2GIP_OFF
#undef DRVPDN_3GIP_OFF
#undef DRVPDN_MD2GSYSIP_OFF
#undef DRVPDN_4GIP_MISC_OFF

#undef DRVPDN_4GIP_ON
#undef DRVPDN_2GIP_ON
#undef DRVPDN_3GIP_ON
#undef DRVPDN_MD2GSYSIP_ON
#undef DRVPDN_4GIP_MISC_ON

#undef DRVPDN_4GIP_STS
#undef DRVPDN_2GIP_STS
#undef DRVPDN_3GIP_STS
#undef DRVPDN_MD2GSYSIP_STS
#undef DRVPDN_4GIP_MISC_STS

#endif /* !__DRVPDN_INLINE_MT6752_MD1_H__ */
