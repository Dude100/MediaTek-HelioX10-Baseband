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
 *   drvpdn_inline_mt6290.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   PDN Driver (C Inline Implementation) for MT6290
 *      - PDN_SET(), PDN_CLR() is for Bus Clock Gating/Ungating
 *      - IPCG_SET(). IPCG_CLR() is for Non-Bus Clock Gating/Ungating
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
 ****************************************************************************/

#ifndef __DRVPDN_INLINE_MT6290_H__
#define __DRVPDN_INLINE_MT6290_H__

/*******************************************************************************
 * Locally Used Options
 *******************************************************************************/
#define EXTRA_EXPORT            0
#define INTERRUPT_PROTECT       1
#define DISABLE_PDN_FOR_6290M   0 // Temporary for Issue Clarification

/*******************************************************************************
 * Include header files
 *******************************************************************************/
#include "kal_general_types.h"
#include "intrCtrl.h"
#include "pdn_hw_mt6290_series.h"

typedef enum {
    /*
    PDN_CR4,
    PDN_ARM7,
    PDN_EMI,
    PDN_DBGSYS,
    #if EXTRA_EXPORT
    PDN_BUS,
    #endif
    PDN_CA7,
    PDN_TRACE,
    */

    PDN_ABM,
    PDN_LTEL2,
    PDN_TDD,
    PDN_MODEM3G,
    PDN_MODEM2G,
    PDN_MDCAIF,
    PDN_CR4PCMON,
    PDN_MDMCU_BUSMON,
    PDN_MDINFRA_BUSMON,
    PDN_RTC,
    PDN_MDCIRQ,
    PDN_MDGDMA,
    PDN_GPIO,
    PDN_MDGPTM,
    PDN_LED,
    PDN_I2C,
    PDN_SUART1,
    PDN_SUART0,
    PDN_MDUART,
    PDN_USIM2,
    PDN_USIM1,
    PDN_BOOTROM,
    PDN_SDIO,
    PDN_EHPI_SLAVE,
    PDN_APPERI_BUSMON,
    PDN_APMCU_BUSMON,
    PDN_APUART,
    PDN_APGDMA,
    PDN_APGPTM,
    PDN_CLDMA,
    PDN_CCIF,
    PDN_IPSEC,
    PDN_NLI,
    PDN_NFI,
    PDN_PFC,
    PDN_EHPI_MASTER,

    PDN_NIC,
    PDN_SPI,
    PDN_MSDC1,
    PDN_MSDC0,
    PDN_U2,
    PDN_U3,

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


typedef enum {
    IPCG_ARM7,
    IPCG_DBGSYS,
    IPCG_CA7,
    IPCG_TRACE,

    IPCG_NIC,
    IPCG_SPI,
    IPCG_MSDC1,
    IPCG_MSDC0,
    IPCG_U2,
    IPCG_U3,

    IPCG_MAX_DEV

} IPCG_DEVICE;


#define DRVPDN_REG(addr)                            *(volatile kal_uint32 *)(addr)
#define DRVPDN_REG16(addr)                          *(volatile kal_uint16 *)(addr)

#define DRVPDN_IPCLK_OFF(sys, module)               DRVPDN_REG(REG_MDCLKCTL_ ## sys ## TOPSM_SW_CTL) = ((DRVPDN_REG(REG_MDCLKCTL_ ## sys ## TOPSM_SW_CTL) | (sys ## TOPSM_ ## module ## _CK_REQ_SW_OWN)) & (~sys ## TOPSM_ ## module ## _CK_REQ_SW_CTL))
#define DRVPDN_LTECLK_OFF(clk)                      DRVPDN_REG(REG_MDCLKCTL_LTEL1_TOPSM_SW_CTL) = ((DRVPDN_REG(REG_MDCLKCTL_LTEL1_TOPSM_SW_CTL) | (LTEL1_TOPSM_ ## clk ## _REQ_SW_OWN)) & (~LTEL1_TOPSM_ ## clk ## _REQ_SW_CTL))
#define DRVPDN_WCDMACLK_OFF(clk)                    DRVPDN_REG(REG_MDCLKCTL_MODEM_TOPSM_SW_CTL) = ((DRVPDN_REG(REG_MDCLKCTL_MODEM_TOPSM_SW_CTL) | (MODEM_ ## clk ## _REQ_SW_OWN)) & (~MODEM_ ## clk ## _REQ_SW_CTL))
#define DRVPDN_GSMCLK_OFF(clk)                      DRVPDN_REG(REG_MDCLKCTL_MODEM_TOPSM_SW_CTL) = ((DRVPDN_REG(REG_MDCLKCTL_MODEM_TOPSM_SW_CTL) | (MODEM2_ ## clk ## _REQ_SW_OWN)) & (~MODEM2_ ## clk ## _REQ_SW_CTL))
#define DRVPDN_TDDCLK_OFF()                         DRVPDN_REG(REG_MDCLKCTL_MODEM_TOPSM_SW_CTL) = ((DRVPDN_REG(REG_MDCLKCTL_MODEM_TOPSM_SW_CTL) | (TDD_TOPSM_CLKEN_REQ_SW_OWN)) & (~TDD_TOPSM_CLKEN_REQ_SW_CTL))

#define DRVPDN_MDIP_BUSCLK_OFF(module)              DRVPDN_REG(REG_MDCLKCTL_MDCLKONCTL) = (DRVPDN_REG(REG_MDCLKCTL_MDCLKONCTL) & (~MD_ ## module ## _CKEN))
#define DRVPDN_APIP_BUSCLK_OFF(module)              DRVPDN_REG(REG_MDCLKCTL_APCLKONCTL) = (DRVPDN_REG(REG_MDCLKCTL_APCLKONCTL) & (~MD_ ## module ## _CKEN))

#define DRVPDN_2GIP_OFF(regnum, module)             DRVPDN_REG(REG_MODEM_CG_SET ## regnum) = (CG_ ## module)
#define DRVPDN_3GIP_OFF(regnum, module)             DRVPDN_REG(REG_MODEM_CG_SET ## regnum) = (CG_ ## module)
#define DRVPDN_MD2GSYSIP_OFF(regnum, module)        DRVPDN_REG16(REG_MD2GSYS_CG_SET ## regnum) = (CG_ ## module)

#define DRVPDN_IPCLK_ON(sys, module)                DRVPDN_REG(REG_MDCLKCTL_ ## sys ## TOPSM_SW_CTL) = (DRVPDN_REG(REG_MDCLKCTL_ ## sys ## TOPSM_SW_CTL) | (sys ## TOPSM_ ## module ## _CK_REQ_SW_OWN) | (sys ## TOPSM_ ## module ## _CK_REQ_SW_CTL))
#define DRVPDN_LTECLK_ON(clk)                       DRVPDN_REG(REG_MDCLKCTL_LTEL1_TOPSM_SW_CTL) = (DRVPDN_REG(REG_MDCLKCTL_LTEL1_TOPSM_SW_CTL) | (LTEL1_TOPSM_ ## clk ## _REQ_SW_OWN) | (LTEL1_TOPSM_ ## clk ## _REQ_SW_CTL))
#define DRVPDN_WCDMACLK_ON(clk)                     DRVPDN_REG(REG_MDCLKCTL_MODEM_TOPSM_SW_CTL) = (DRVPDN_REG(REG_MDCLKCTL_MODEM_TOPSM_SW_CTL) | (MODEM_ ## clk ## _REQ_SW_OWN) | (MODEM_ ## clk ## _REQ_SW_CTL))
#define DRVPDN_GSMCLK_ON(clk)                       DRVPDN_REG(REG_MDCLKCTL_MODEM_TOPSM_SW_CTL) = (DRVPDN_REG(REG_MDCLKCTL_MODEM_TOPSM_SW_CTL) | (MODEM2_ ## clk ## _REQ_SW_OWN) | (MODEM2_ ## clk ## _REQ_SW_CTL))
#define DRVPDN_TDDCLK_ON()                          DRVPDN_REG(REG_MDCLKCTL_MODEM_TOPSM_SW_CTL) = (DRVPDN_REG(REG_MDCLKCTL_MODEM_TOPSM_SW_CTL) | (TDD_TOPSM_CLKEN_REQ_SW_OWN) | (TDD_TOPSM_CLKEN_REQ_SW_CTL))

#define DRVPDN_MDIP_BUSCLK_ON(module)               DRVPDN_REG(REG_MDCLKCTL_MDCLKONCTL) = (DRVPDN_REG(REG_MDCLKCTL_MDCLKONCTL) | (MD_ ## module ## _CKEN))
#define DRVPDN_APIP_BUSCLK_ON(module)               DRVPDN_REG(REG_MDCLKCTL_APCLKONCTL) = (DRVPDN_REG(REG_MDCLKCTL_APCLKONCTL) | (MD_ ## module ## _CKEN))

#define DRVPDN_2GIP_ON(regnum, module)              DRVPDN_REG(REG_MODEM_CG_CLR ## regnum) = (CG_ ## module)
#define DRVPDN_3GIP_ON(regnum, module)              DRVPDN_REG(REG_MODEM_CG_CLR ## regnum) = (CG_ ## module)
#define DRVPDN_MD2GSYSIP_ON(regnum, module)         DRVPDN_REG16(REG_MD2GSYS_CG_CLR ## regnum) = (CG_ ## module)

#define DRVPDN_IPCLK_STS(sys, module)               !((DRVPDN_REG(REG_MDCLKCTL_ ## sys ## TOPSM_SW_CTL) & (sys ## TOPSM_ ## module ## _CK_REQ_SW_OWN)) &&  (DRVPDN_REG(REG_MDCLKCTL_ ## sys ## TOPSM_SW_CTL) & (sys ## TOPSM_ ## module ## _CK_REQ_SW_CTL)))
#define DRVPDN_LTECLK_STS(clk)                      !((DRVPDN_REG(REG_MDCLKCTL_LTEL1_TOPSM_SW_CTL) & (LTEL1_TOPSM_ ## clk ## _REQ_SW_OWN)) && (DRVPDN_REG(REG_MDCLKCTL_LTEL1_TOPSM_SW_CTL) & (LTEL1_TOPSM_ ## clk ## _REQ_SW_CTL)))
#define DRVPDN_WCDMACLK_STS(clk)                    !((DRVPDN_REG(REG_MDCLKCTL_MODEM_TOPSM_SW_CTL) & (MODEM_ ## clk ## _REQ_SW_OWN)) && (DRVPDN_REG(REG_MDCLKCTL_MODEM_TOPSM_SW_CTL) & (MODEM_ ## clk ## _REQ_SW_CTL)))
#define DRVPDN_GSMCLK_STS(clk)                      !((DRVPDN_REG(REG_MDCLKCTL_MODEM_TOPSM_SW_CTL) & (MODEM2_ ## clk ## _REQ_SW_OWN)) && (DRVPDN_REG(REG_MDCLKCTL_MODEM_TOPSM_SW_CTL) & (MODEM2_ ## clk ## _REQ_SW_CTL)))
#define DRVPDN_TDDCLK_STS()                         !((DRVPDN_REG(REG_MDCLKCTL_MODEM_TOPSM_SW_CTL) & (TDD_TOPSM_CLKEN_REQ_SW_OWN)) && (DRVPDN_REG(REG_MDCLKCTL_MODEM_TOPSM_SW_CTL) & (TDD_TOPSM_CLKEN_REQ_SW_CTL)))

#define DRVPDN_MDIP_BUSCLK_STS(module)              !(DRVPDN_REG(REG_MDCLKCTL_MDCLKONCTL) & (MD_ ## module ## _CKEN))
#define DRVPDN_APIP_BUSCLK_STS(module)              !(DRVPDN_REG(REG_MDCLKCTL_APCLKONCTL) & (MD_ ## module ## _CKEN))

#define DRVPDN_2GIP_STS(regnum, module)             (DRVPDN_REG(REG_MODEM_CG_CON ## regnum) & (CG_ ## module))
#define DRVPDN_3GIP_STS(regnum, module)             (DRVPDN_REG(REG_MODEM_CG_CON ## regnum) & (CG_ ## module))
#define DRVPDN_MD2GSYSIP_STS(regnum, module)        (DRVPDN_REG16(REG_MD2GSYS_CG_CON ## regnum) & (CG_ ## module))

DRVPDN_INLINE_MODIFIER DRVPDN_INLINE void PDN_SET(PDN_DEVICE dev)
{
#if defined(__SMART_PHONE_MODEM__) && defined(__X_BOOTING__) && DISABLE_PDN_FOR_6290M


#else
    #if INTERRUPT_PROTECT
    kal_uint32 mask;
    mask = SaveAndSetIRQMask();
    #endif

    switch (dev)
    {
        /* IPs with only PLL clock */

        /*
        case PDN_CR4:
            DRVPDN_IPCLK_OFF(MD, CR4);
            break;
        case PDN_ARM7:
            DRVPDN_IPCLK_OFF(MD, ARM7);
            break;
        case PDN_EMI:
            DRVPDN_IPCLK_OFF(MD, EMI);
            DRVPDN_LTECLK_OFF(MEMSYS_CK);
            break;
        case PDN_DBGSYS:
            DRVPDN_IPCLK_OFF(MD, DBG);
            DRVPDN_LTECLK_OFF(DBGSYS_CK);
            break;
        #if EXTRA_EXPORT
        case PDN_BUS:
            DRVPDN_IPCLK_OFF(MD, BUS2X);
            DRVPDN_IPCLK_OFF(AP, BUS2X);
            DRVPDN_LTECLK_OFF(BUS1X_CK);
            DRVPDN_WCDMACLK_OFF(BUSCLK);
            DRVPDN_GSMCLK_OFF(BUSCLK);
            //DRVPDN_TDDCLK_OFF(BUSCLK);   // whole TDD off
            break;
        #endif
        case PDN_CA7:
            DRVPDN_IPCLK_OFF(AP, CA7);
            break;
        case PDN_TRACE:
            DRVPDN_IPCLK_OFF(AP, TRACE);
            break;
        */

        /* IPs with only bus clock */
        case PDN_ABM:
            DRVPDN_MDIP_BUSCLK_OFF(ABM);
            break;
        case PDN_LTEL2:
            DRVPDN_MDIP_BUSCLK_OFF(LTEL2);
            break;
        case PDN_TDD:
            DRVPDN_MDIP_BUSCLK_OFF(TDD);
            break;
        case PDN_MODEM3G:
            DRVPDN_MDIP_BUSCLK_OFF(MODEM3G);
            break;
        case PDN_MODEM2G:
            DRVPDN_MDIP_BUSCLK_OFF(MODEM2G);
            break;
        case PDN_MDCAIF:
            DRVPDN_MDIP_BUSCLK_OFF(MDCAIF);
            break;
        case PDN_CR4PCMON:
            DRVPDN_MDIP_BUSCLK_OFF(CR4PCMON);
            break;
        case PDN_MDMCU_BUSMON:
            DRVPDN_MDIP_BUSCLK_OFF(MDMCU_BUSMON);
            break;
        case PDN_MDINFRA_BUSMON:
            DRVPDN_MDIP_BUSCLK_OFF(MDINFRA_BUSMON);
            break;
        case PDN_RTC:
            DRVPDN_MDIP_BUSCLK_OFF(RTC);
            break;
        case PDN_MDCIRQ:
            DRVPDN_MDIP_BUSCLK_OFF(MDCIRQ);
            break;
        case PDN_MDGDMA:
            DRVPDN_MDIP_BUSCLK_OFF(MDGDMA);
            break;
        case PDN_GPIO:
            DRVPDN_MDIP_BUSCLK_OFF(GPIO);
            break;
        case PDN_MDGPTM:
            DRVPDN_MDIP_BUSCLK_OFF(MDGPTM);
            break;
        case PDN_LED:
            DRVPDN_MDIP_BUSCLK_OFF(LED);
            break;
        case PDN_I2C:
            DRVPDN_MDIP_BUSCLK_OFF(I2C);
            break;
        case PDN_SUART1:
            DRVPDN_MDIP_BUSCLK_OFF(SUART1);
            break;
        case PDN_SUART0:
            DRVPDN_MDIP_BUSCLK_OFF(SUART0);
            break;
        case PDN_MDUART:
            DRVPDN_MDIP_BUSCLK_OFF(MDUART);
            break;
        case PDN_USIM2:
            DRVPDN_MDIP_BUSCLK_OFF(USIM2);
            break;
        case PDN_USIM1:
            DRVPDN_MDIP_BUSCLK_OFF(USIM1);
            break;
        case PDN_BOOTROM:
            DRVPDN_MDIP_BUSCLK_OFF(BOOTROM);
            break;
        case PDN_SDIO:
            DRVPDN_MDIP_BUSCLK_OFF(SDIO);
            break;
            
        case PDN_EHPI_SLAVE:
            DRVPDN_APIP_BUSCLK_OFF(SDCTL_EHPI);
            break;
        case PDN_APPERI_BUSMON:
            DRVPDN_APIP_BUSCLK_OFF(APPERI_BUSMON);
            break;
        case PDN_APMCU_BUSMON:
            DRVPDN_APIP_BUSCLK_OFF(APMCU_BUSMON);
            break;
        case PDN_APUART:
            DRVPDN_APIP_BUSCLK_OFF(APUART);
            break;
        case PDN_APGDMA:
            DRVPDN_APIP_BUSCLK_OFF(APGDMA);
            break;
        case PDN_APGPTM:
            DRVPDN_APIP_BUSCLK_OFF(APGPTM);
            break;
        case PDN_CLDMA:
            DRVPDN_APIP_BUSCLK_OFF(CLDMA);
            break;
        case PDN_CCIF:
            DRVPDN_APIP_BUSCLK_OFF(CCIF);
            break;
        case PDN_IPSEC:
            DRVPDN_APIP_BUSCLK_OFF(IPSEC);
            break;
        case PDN_NLI:        
            DRVPDN_APIP_BUSCLK_OFF(NLI_ARB);
            break;
        case PDN_NFI:
            DRVPDN_APIP_BUSCLK_OFF(NFI);
            break;
        case PDN_PFC:
            DRVPDN_APIP_BUSCLK_OFF(PFC);
            break;
        case PDN_EHPI_MASTER:
            DRVPDN_APIP_BUSCLK_OFF(HIF);
            break;

        /* IPs with both specific clock and bus clock */
        case PDN_NIC:
            DRVPDN_APIP_BUSCLK_OFF(NIC);
            //DRVPDN_IPCLK_OFF(AP, NIC);            
            break;
        case PDN_SPI:
            DRVPDN_APIP_BUSCLK_OFF(SPI);
            //DRVPDN_IPCLK_OFF(AP, SPI);
            break;
        case PDN_MSDC1:
            DRVPDN_APIP_BUSCLK_OFF(MSDC1);
            //DRVPDN_IPCLK_OFF(AP, MSDC1P);
            break;
        case PDN_MSDC0:
            DRVPDN_APIP_BUSCLK_OFF(MSDC0);
            //DRVPDN_IPCLK_OFF(AP, MSDC0P);
            break;
        case PDN_U2:
            DRVPDN_APIP_BUSCLK_OFF(U2);
            //DRVPDN_IPCLK_OFF(AP, USB);
            break;
        case PDN_U3:
            DRVPDN_APIP_BUSCLK_OFF(U3);
            //DRVPDN_IPCLK_OFF(AP, SSUSB);
            break;

        /* 4G IPs with specific clock */
        /*
        case PDN_BSISPI:
            DRVPDN_LTECLK_OFF(BSISPIC_CK); // Still Need to Off TDDSYS, 2G BUSCLK, 3G BUSCLK. But This May Cause Side-Effects, So No Export
            break;
        case PDN_LTEPHY:
            DRVPDN_LTECLK_OFF(PHY_CK); // Platform Need Not Off LTEPHY, So No Export
            break;
        */

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
#endif    
}

DRVPDN_INLINE_MODIFIER DRVPDN_INLINE void PDN_CLR(PDN_DEVICE dev)
{
#if defined(__SMART_PHONE_MODEM__) && defined(__X_BOOTING__) && DISABLE_PDN_FOR_6290M


#else
    #if INTERRUPT_PROTECT
    kal_uint32 mask;
    mask = SaveAndSetIRQMask();
    #endif

    switch (dev)
    {
        /* IPs with only PLL clock */

        /*
        case PDN_CR4:
            DRVPDN_IPCLK_ON(MD, CR4);
            break;
        case PDN_ARM7:
            DRVPDN_IPCLK_ON(MD, ARM7);
            break;
        case PDN_EMI:
            DRVPDN_IPCLK_ON(MD, EMI);
            DRVPDN_LTECLK_ON(MEMSYS_CK);
            break;
        case PDN_DBGSYS:
            DRVPDN_IPCLK_ON(MD, DBG);
            DRVPDN_LTECLK_ON(DBGSYS_CK);
            break;
        #if EXTRA_EXPORT
        case PDN_BUS:
            DRVPDN_IPCLK_ON(MD, BUS2X);
            DRVPDN_IPCLK_ON(AP, BUS2X);
            DRVPDN_LTECLK_ON(BUS1X_CK);
            DRVPDN_LTECLK_ON(BUS1X_CK);
            DRVPDN_WCDMACLK_ON(BUSCLK);
            DRVPDN_GSMCLK_ON(BUSCLK);
            //DRVPDN_TDDCLK_ON(BUSCLK);   // whole TDD off
            break;
        #endif
        case PDN_CA7:
            DRVPDN_IPCLK_ON(AP, CA7);
            break;
        case PDN_TRACE:
            DRVPDN_IPCLK_ON(AP, TRACE);
            break;
        */

        /* IPs with only bus clock */
        case PDN_ABM:
            DRVPDN_MDIP_BUSCLK_ON(ABM);
            break;
        case PDN_LTEL2:
            DRVPDN_MDIP_BUSCLK_ON(LTEL2);
            break;
        case PDN_TDD:
            DRVPDN_MDIP_BUSCLK_ON(TDD);
            break;
        case PDN_MODEM3G:
            DRVPDN_MDIP_BUSCLK_ON(MODEM3G);
            break;
        case PDN_MODEM2G:
            DRVPDN_MDIP_BUSCLK_ON(MODEM2G);
            break;
        case PDN_MDCAIF:
            DRVPDN_MDIP_BUSCLK_ON(MDCAIF);
            break;
        case PDN_CR4PCMON:
            DRVPDN_MDIP_BUSCLK_ON(CR4PCMON);
            break;
        case PDN_MDMCU_BUSMON:
            DRVPDN_MDIP_BUSCLK_ON(MDMCU_BUSMON);
            break;
        case PDN_MDINFRA_BUSMON:
            DRVPDN_MDIP_BUSCLK_ON(MDINFRA_BUSMON);
            break;
        case PDN_RTC:
            DRVPDN_MDIP_BUSCLK_ON(RTC);
            break;
        case PDN_MDCIRQ:
            DRVPDN_MDIP_BUSCLK_ON(MDCIRQ);
            break;
        case PDN_MDGDMA:
            DRVPDN_MDIP_BUSCLK_ON(MDGDMA);
            break;
        case PDN_GPIO:
            DRVPDN_MDIP_BUSCLK_ON(GPIO);
            break;
        case PDN_MDGPTM:
            DRVPDN_MDIP_BUSCLK_ON(MDGPTM);
            break;
        case PDN_LED:
            DRVPDN_MDIP_BUSCLK_ON(LED);
            break;
        case PDN_I2C:
            DRVPDN_MDIP_BUSCLK_ON(I2C);
            break;
        case PDN_SUART1:
            DRVPDN_MDIP_BUSCLK_ON(SUART1);
            break;
        case PDN_SUART0:
            DRVPDN_MDIP_BUSCLK_ON(SUART0);
            break;
        case PDN_MDUART:
            DRVPDN_MDIP_BUSCLK_ON(MDUART);
            break;
        case PDN_USIM2:
            DRVPDN_MDIP_BUSCLK_ON(USIM2);
            break;
        case PDN_USIM1:
            DRVPDN_MDIP_BUSCLK_ON(USIM1);
            break;
        case PDN_BOOTROM:
            DRVPDN_MDIP_BUSCLK_ON(BOOTROM);
            break;
        case PDN_SDIO:
            DRVPDN_MDIP_BUSCLK_ON(SDIO);
            break;
            
        case PDN_EHPI_SLAVE:
            DRVPDN_APIP_BUSCLK_ON(SDCTL_EHPI);
            break;
        case PDN_APPERI_BUSMON:
            DRVPDN_APIP_BUSCLK_ON(APPERI_BUSMON);
            break;
        case PDN_APMCU_BUSMON:
            DRVPDN_APIP_BUSCLK_ON(APMCU_BUSMON);
            break;
        case PDN_APUART:
            DRVPDN_APIP_BUSCLK_ON(APUART);
            break;
        case PDN_APGDMA:
            DRVPDN_APIP_BUSCLK_ON(APGDMA);
            break;
        case PDN_APGPTM:
            DRVPDN_APIP_BUSCLK_ON(APGPTM);
            break;
        case PDN_CLDMA:
            DRVPDN_APIP_BUSCLK_ON(CLDMA);
            break;
        case PDN_CCIF:
            DRVPDN_APIP_BUSCLK_ON(CCIF);
            break;
        case PDN_IPSEC:
            DRVPDN_APIP_BUSCLK_ON(IPSEC);
            break;
        case PDN_NLI:        
            DRVPDN_APIP_BUSCLK_ON(NLI_ARB);
            break;
        case PDN_NFI:
            DRVPDN_APIP_BUSCLK_ON(NFI);
            break;
        case PDN_PFC:
            DRVPDN_APIP_BUSCLK_ON(PFC);
            break;
        case PDN_EHPI_MASTER:
            DRVPDN_APIP_BUSCLK_ON(HIF);
            break;

        /* IPs with both specific clock and bus clock */
        case PDN_NIC:
            DRVPDN_APIP_BUSCLK_ON(NIC);
            //DRVPDN_IPCLK_ON(AP, NIC);            
            break;
        case PDN_SPI:
            DRVPDN_APIP_BUSCLK_ON(SPI);
            //DRVPDN_IPCLK_ON(AP, SPI);
            break;
        case PDN_MSDC1:
            DRVPDN_APIP_BUSCLK_ON(MSDC1);
            //DRVPDN_IPCLK_ON(AP, MSDC1P);
            break;
        case PDN_MSDC0:
            DRVPDN_APIP_BUSCLK_ON(MSDC0);
            //DRVPDN_IPCLK_ON(AP, MSDC0P);
            break;
        case PDN_U2:
            DRVPDN_APIP_BUSCLK_ON(U2);
            //DRVPDN_IPCLK_ON(AP, USB);
            break;
        case PDN_U3:
            DRVPDN_APIP_BUSCLK_ON(U3);
            //DRVPDN_IPCLK_ON(AP, SSUSB);
            break;

        /* 4G IPs with specific clock */
        /*
        case PDN_BSISPI:
            DRVPDN_LTECLK_ON(BSISPIC_CK);
            break;
        case PDN_LTEPHY:
            DRVPDN_LTECLK_ON(PHY_CK);
            break;
        */

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
#endif
}


DRVPDN_INLINE_MODIFIER DRVPDN_INLINE kal_uint32 PDN_STS(PDN_DEVICE dev)
{
    kal_uint32 ret;
    
#if defined(__SMART_PHONE_MODEM__) && defined(__X_BOOTING__) && DISABLE_PDN_FOR_6290M


#else
    #if INTERRUPT_PROTECT
    kal_uint32 mask;
    mask = SaveAndSetIRQMask();
    #endif

    switch (dev)
    {
        /* IPs with only PLL clock */

        /*
        case PDN_CR4:
            ret = DRVPDN_IPCLK_STS(MD, CR4);
            break;
        case PDN_ARM7:
            ret = DRVPDN_IPCLK_STS(MD, ARM7);
            break;
        case PDN_EMI:
            ret = DRVPDN_IPCLK_STS(MD, EMI) && DRVPDN_LTECLK_STS(MEMSYS_CK);
            break;
        case PDN_DBGSYS:
            ret = DRVPDN_IPCLK_STS(MD, DBG) && DRVPDN_LTECLK_STS(DBGSYS_CK);
            break;
        #if EXTRA_EXPORT
        case PDN_BUS:
            ret = DRVPDN_IPCLK_STS(MD, BUS2X) && DRVPDN_IPCLK_STS(AP, BUS2X) && DRVPDN_LTECLK_STS(BUS1X_CK) &&
                  DRVPDN_WCDMACLK_STS(BUSCLK) && DRVPDN_GSMCLK_STS(BUSCLK);

            //DRVPDN_TDDCLK_ON(BUSCLK);   // whole TDD off
            break;
        #endif
        case PDN_CA7:
            ret = DRVPDN_IPCLK_STS(AP, CA7);
            break;
        case PDN_TRACE:
            ret = DRVPDN_IPCLK_STS(AP, TRACE);
            break;
        */

        /* IPs with only bus clock */
        case PDN_ABM:            
            ret = DRVPDN_MDIP_BUSCLK_STS(ABM);
            break;
        case PDN_LTEL2:
            ret = DRVPDN_MDIP_BUSCLK_STS(LTEL2);
            break;
        case PDN_TDD:
            ret = DRVPDN_MDIP_BUSCLK_STS(TDD);
            break;
        case PDN_MODEM3G:
            ret = DRVPDN_MDIP_BUSCLK_STS(MODEM3G);
            break;
        case PDN_MODEM2G:
            ret = DRVPDN_MDIP_BUSCLK_STS(MODEM2G);
            break;
        case PDN_MDCAIF:
            ret = DRVPDN_MDIP_BUSCLK_STS(MDCAIF);
            break;
        case PDN_CR4PCMON:
            ret = DRVPDN_MDIP_BUSCLK_STS(CR4PCMON);
            break;
        case PDN_MDMCU_BUSMON:
            ret = DRVPDN_MDIP_BUSCLK_STS(MDMCU_BUSMON);
            break;
        case PDN_MDINFRA_BUSMON:
            ret = DRVPDN_MDIP_BUSCLK_STS(MDINFRA_BUSMON);
            break;
        case PDN_RTC:
            ret = DRVPDN_MDIP_BUSCLK_STS(RTC);
            break;
        case PDN_MDCIRQ:
            ret = DRVPDN_MDIP_BUSCLK_STS(MDCIRQ);
            break;
        case PDN_MDGDMA:
            ret = DRVPDN_MDIP_BUSCLK_STS(MDGDMA);
            break;
        case PDN_GPIO:
            ret = DRVPDN_MDIP_BUSCLK_STS(GPIO);
            break;
        case PDN_MDGPTM:
            ret = DRVPDN_MDIP_BUSCLK_STS(MDGPTM);
            break;
        case PDN_LED:
            ret = DRVPDN_MDIP_BUSCLK_STS(LED);
            break;
        case PDN_I2C:
            ret = DRVPDN_MDIP_BUSCLK_STS(I2C);
            break;
        case PDN_SUART1:
            ret = DRVPDN_MDIP_BUSCLK_STS(SUART1);
            break;
        case PDN_SUART0:
            ret = DRVPDN_MDIP_BUSCLK_STS(SUART0);
            break;
        case PDN_MDUART:
            ret = DRVPDN_MDIP_BUSCLK_STS(MDUART);
            break;
        case PDN_USIM2:
            ret = DRVPDN_MDIP_BUSCLK_STS(USIM2);
            break;
        case PDN_USIM1:
            ret = DRVPDN_MDIP_BUSCLK_STS(USIM1);
            break;
        case PDN_BOOTROM:
            ret = DRVPDN_MDIP_BUSCLK_STS(BOOTROM);
            break;
        case PDN_SDIO:
            ret = DRVPDN_MDIP_BUSCLK_STS(SDIO);
            break;

        case PDN_EHPI_SLAVE:
            ret = DRVPDN_APIP_BUSCLK_STS(SDCTL_EHPI);
            break;
        case PDN_APPERI_BUSMON:
            ret = DRVPDN_APIP_BUSCLK_STS(APPERI_BUSMON);
            break;
        case PDN_APMCU_BUSMON:
            ret = DRVPDN_APIP_BUSCLK_STS(APMCU_BUSMON);
            break;
        case PDN_APUART:
            ret = DRVPDN_APIP_BUSCLK_STS(APUART);
            break;
        case PDN_APGDMA:
            ret = DRVPDN_APIP_BUSCLK_STS(APGDMA);
            break;
        case PDN_APGPTM:
            ret = DRVPDN_APIP_BUSCLK_STS(APGPTM);
            break;
        case PDN_CLDMA:
            ret = DRVPDN_APIP_BUSCLK_STS(CLDMA);
            break;
        case PDN_CCIF:
            ret = DRVPDN_APIP_BUSCLK_STS(CCIF);
            break;
        case PDN_IPSEC:
            ret = DRVPDN_APIP_BUSCLK_STS(IPSEC);
            break;
        case PDN_NLI:
            ret = DRVPDN_APIP_BUSCLK_STS(NLI_ARB);
            break;
        case PDN_NFI:
            ret = DRVPDN_APIP_BUSCLK_STS(NFI);
            break;
        case PDN_PFC:
            ret = DRVPDN_APIP_BUSCLK_STS(PFC);
            break;
        case PDN_EHPI_MASTER:
            ret = DRVPDN_APIP_BUSCLK_STS(HIF);
            break;

        /* IPs with both specific clock and bus clock */
        case PDN_NIC:
            //ret = DRVPDN_BUSCLK_STS_FROM_MD(NIC) && DRVPDN_BUSCLK_STS_FROM_AP(NIC) && DRVPDN_IPCLK_STS(AP, NIC);
            ret = DRVPDN_APIP_BUSCLK_STS(NIC);
            break;
        case PDN_SPI:
            //ret = DRVPDN_BUSCLK_STS_FROM_MD(SPI) && DRVPDN_BUSCLK_STS_FROM_AP(SPI) && DRVPDN_IPCLK_STS(AP, SPI);
            ret = DRVPDN_APIP_BUSCLK_STS(SPI);
            break;
        case PDN_MSDC1:
            //ret = DRVPDN_BUSCLK_STS_FROM_MD(MSDC1) && DRVPDN_BUSCLK_STS_FROM_AP(MSDC1) && DRVPDN_IPCLK_STS(AP, MSDC1P);
            ret = DRVPDN_APIP_BUSCLK_STS(MSDC1);
            break;
        case PDN_MSDC0:
            //ret = DRVPDN_BUSCLK_STS_FROM_MD(MSDC0) && DRVPDN_BUSCLK_STS_FROM_AP(MSDC0) && DRVPDN_IPCLK_STS(AP, MSDC0P);
            ret = DRVPDN_APIP_BUSCLK_STS(MSDC0);
            break;
        case PDN_U2:
            //ret = DRVPDN_BUSCLK_STS_FROM_MD(U2) && DRVPDN_BUSCLK_STS_FROM_AP(U2) && DRVPDN_IPCLK_STS(AP, USB);
            ret = DRVPDN_APIP_BUSCLK_STS(U2);
            break;
        case PDN_U3:
            //ret = DRVPDN_BUSCLK_STS_FROM_MD(U3) && DRVPDN_BUSCLK_STS_FROM_AP(U3) && DRVPDN_IPCLK_STS(AP, SSUSB);
            ret = DRVPDN_APIP_BUSCLK_STS(U3);
            break;

        /* 4G IPs with specific clock */
        /*
        case PDN_BSISPI:
            ret = DRVPDN_LTECLK_STS(BSISPIC_CK);
            break;
        case PDN_LTEPHY:
            ret = DRVPDN_LTECLK_STS(PHY_CK);
            break;
        */

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
#endif

    return ret;
}


DRVPDN_INLINE_MODIFIER DRVPDN_INLINE void IPCG_SET(IPCG_DEVICE dev)
{
#if defined(__SMART_PHONE_MODEM__) && defined(__X_BOOTING__) && DISABLE_PDN_FOR_6290M


#else
    #if INTERRUPT_PROTECT
    kal_uint32 mask;
    mask = SaveAndSetIRQMask();
    #endif

    switch (dev)
    {
        /* IPs with only PLL clock */
        case IPCG_ARM7:
            DRVPDN_IPCLK_OFF(MD, ARM7);
            break;
        case IPCG_DBGSYS:
            DRVPDN_IPCLK_OFF(MD, DBG);
            DRVPDN_LTECLK_OFF(DBGSYS_CK);
            break;
        case IPCG_CA7:
            DRVPDN_IPCLK_OFF(AP, CA7);
            break;
        case IPCG_TRACE:
            DRVPDN_IPCLK_OFF(AP, TRACE);
            break;

        /* IPs with both specific clock and bus clock */
        case IPCG_NIC:
            DRVPDN_IPCLK_OFF(AP, NIC);            
            break;
        case IPCG_SPI:
            DRVPDN_IPCLK_OFF(AP, SPI);
            break;
        case IPCG_MSDC1:
            DRVPDN_IPCLK_OFF(AP, MSDC1P);
            break;
        case IPCG_MSDC0:
            DRVPDN_IPCLK_OFF(AP, MSDC0P);
            break;
        case IPCG_U2:
            DRVPDN_IPCLK_OFF(AP, USB);
            break;
        case IPCG_U3:
            DRVPDN_IPCLK_OFF(AP, SSUSB);
            break;

        case IPCG_MAX_DEV:
            break;
    }

    #if INTERRUPT_PROTECT
    RestoreIRQMask(mask);
    #endif
#endif    
}


DRVPDN_INLINE_MODIFIER DRVPDN_INLINE void IPCG_CLR(IPCG_DEVICE dev)
{
#if defined(__SMART_PHONE_MODEM__) && defined(__X_BOOTING__) && DISABLE_PDN_FOR_6290M


#else
    #if INTERRUPT_PROTECT
    kal_uint32 mask;
    mask = SaveAndSetIRQMask();
    #endif

    switch (dev)
    {
        /* IPs with only PLL clock */
        case IPCG_ARM7:
            DRVPDN_IPCLK_ON(MD, ARM7);
            break;
        case IPCG_DBGSYS:
            DRVPDN_IPCLK_ON(MD, DBG);
            DRVPDN_LTECLK_ON(DBGSYS_CK);
            break;
        case IPCG_CA7:
            DRVPDN_IPCLK_ON(AP, CA7);
            break;
        case IPCG_TRACE:
            DRVPDN_IPCLK_ON(AP, TRACE);
            break;

        /* IPs with both specific clock and bus clock */
        case IPCG_NIC:
            DRVPDN_IPCLK_ON(AP, NIC);            
            break;
        case IPCG_SPI:
            DRVPDN_IPCLK_ON(AP, SPI);
            break;
        case IPCG_MSDC1:
            DRVPDN_IPCLK_ON(AP, MSDC1P);
            break;
        case IPCG_MSDC0:
            DRVPDN_IPCLK_ON(AP, MSDC0P);
            break;
        case IPCG_U2:
            DRVPDN_IPCLK_ON(AP, USB);
            break;
        case IPCG_U3:
            DRVPDN_IPCLK_ON(AP, SSUSB);
            break;

        case IPCG_MAX_DEV:
            break;
    }

    #if INTERRUPT_PROTECT
    RestoreIRQMask(mask);
    #endif
#endif    
}


DRVPDN_INLINE_MODIFIER DRVPDN_INLINE kal_uint32 IPCG_STS(IPCG_DEVICE dev)
{
    kal_uint32 ret = 0;

#if defined(__SMART_PHONE_MODEM__) && defined(__X_BOOTING__) && DISABLE_PDN_FOR_6290M


#else
    #if INTERRUPT_PROTECT
    kal_uint32 mask;
    mask = SaveAndSetIRQMask();
    #endif

    switch (dev)
    {
        /* IPs with only PLL clock */
        case IPCG_ARM7:
            ret = DRVPDN_IPCLK_STS(MD, ARM7);
            break;
        case IPCG_DBGSYS:
            ret = DRVPDN_IPCLK_STS(MD, DBG) && DRVPDN_LTECLK_STS(DBGSYS_CK);
            break;
        case IPCG_CA7:
            ret = DRVPDN_IPCLK_STS(AP, CA7);
            break;
        case IPCG_TRACE:
            ret = DRVPDN_IPCLK_STS(AP, TRACE);
            break;

        /* IPs with both specific clock and bus clock */
        case IPCG_NIC:
            ret = DRVPDN_IPCLK_STS(AP, NIC);
            break;
        case IPCG_SPI:
            ret = DRVPDN_IPCLK_STS(AP, SPI);
            break;
        case IPCG_MSDC1:
            ret = DRVPDN_IPCLK_STS(AP, MSDC1P);
            break;
        case IPCG_MSDC0:
            ret = DRVPDN_IPCLK_STS(AP, MSDC0P);
            break;
        case IPCG_U2:
            ret = DRVPDN_IPCLK_STS(AP, USB);
            break;
        case IPCG_U3:
            ret = DRVPDN_IPCLK_STS(AP, SSUSB);
            break;
            
        case IPCG_MAX_DEV:
            break;
    }

    #if INTERRUPT_PROTECT
    RestoreIRQMask(mask);
    #endif
#endif
    
    return ret;
}


#undef DRVPDN_REG
#undef DRVPDN_IPCLK_OFF
#undef DRVPDN_LTECLK_OFF
#undef DRVPDN_WCDMACLK_OFF
#undef DRVPDN_GSMCLK_OFF
#undef DRVPDN_TDDCLK_OFF
#undef DRVPDN_BUSCLK_OFF_FROM_MD
#undef DRVPDN_BUSCLK_OFF_FROM_AP
#undef DRVPDN_2GIP_OFF
#undef DRVPDN_3GIP_OFF
#undef DRVPDN_MD2GSYSIP_OFF

#undef DRVPDN_IPCLK_ON
#undef DRVPDN_LTECLK_ON
#undef DRVPDN_WCDMACLK_ON
#undef DRVPDN_GSMCLK_ON
#undef DRVPDN_TDDCLK_ON
#undef DRVPDN_BUSCLK_ON_FROM_MD
#undef DRVPDN_BUSCLK_ON_FROM_AP
#undef DRVPDN_2GIP_ON
#undef DRVPDN_3GIP_ON
#undef DRVPDN_MD2GSYSIP_ON

#undef DRVPDN_IPCLK_STS
#undef DRVPDN_LTECLK_STS
#undef DRVPDN_WCDMACLK_STS
#undef DRVPDN_GSMCLK_STS
#undef DRVPDN_TDDCLK_STS
#undef DRVPDN_BUSCLK_STS_FROM_MD
#undef DRVPDN_BUSCLK_STS_FROM_AP
#undef DRVPDN_2GIP_STS
#undef DRVPDN_3GIP_STS
#undef DRVPDN_MD2GSYSIP_STS

#endif /* !__DRVPDN_INLINE_MT6290_H__ */
