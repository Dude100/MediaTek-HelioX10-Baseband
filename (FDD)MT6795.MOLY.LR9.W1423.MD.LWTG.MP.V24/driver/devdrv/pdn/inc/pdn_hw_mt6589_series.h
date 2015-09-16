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
 *    pdn_hw_mt6589_series.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines PDN HW registers for MT6589 series chips.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "reg_base.h"

#ifndef __PDN_HW_MT6752_SERIES_H__
#define __PDN_HW_MT6589_SERIES_H__

/* MD2GSYS */

#define DRVPDN_MD2GSYS_CG_CON0          (MD2GCONFG_base+0x0000)
#define DRVPDN_MD2GSYS_CG_CON2          (MD2GCONFG_base+0x0008)
#define DRVPDN_MD2GSYS_CG_CON4          (MD2GCONFG_base+0x0030)

#define DRVPDN_MD2GSYS_CG_SET0          (MD2GCONFG_base+0x0010)
#define DRVPDN_MD2GSYS_CG_SET2          (MD2GCONFG_base+0x0018)
#define DRVPDN_MD2GSYS_CG_SET4          (MD2GCONFG_base+0x0034)

#define DRVPDN_MD2GSYS_CG_CLR0          (MD2GCONFG_base+0x0020)
#define DRVPDN_MD2GSYS_CG_CLR2          (MD2GCONFG_base+0x0028)
#define DRVPDN_MD2GSYS_CG_CLR4          (MD2GCONFG_base+0x0038)

#define MD2GSYS_CG_CON0_GCC              0x0002
#define MD2GSYS_CG_CON0_IRDMA            0x0040
#define MD2GSYS_CG_CON0_RXBUF            0x0100
#define MD2GSYS_CG_CON0_TXBUF            0x0200
#define MD2GSYS_CG_CON0_IRDBG            0x2000
#define MD2GSYS_CG_CON0_AHB2DSPIO        0x8000

#define MD2GSYS_CG_CON2_APC_PRE          0x0020
#define MD2GSYS_CG_CON2_VAFE             0x0100
#define MD2GSYS_CG_CON2_BFE              0x0200

#define MD2GSYS_CG_CON4_APC              0x0020

/* MD sys global */

#define DRVPDN_MD_PWR_GLOBAL_CON0  (CONFIG_base+0x0450)

#define DRVPDN_MD_PWR_GLOBAL_SET0  (CONFIG_base+0x0454)

#define DRVPDN_MD_PWR_GLOBAL_CLR0  (CONFIG_base+0x0458)

#define MD_PWR_GLOBAL_CON0_DMA             0x00000001
#define MD_PWR_GLOBAL_CON0_BOOT_SLV        0x00000002
#define MD_PWR_GLOBAL_CON0_ABM             0x00000004
#define MD_PWR_GLOBAL_CON0_ADOE            0x00000008
#define MD_PWR_GLOBAL_CON0_UART            0x00000010
#define MD_PWR_GLOBAL_CON0_DBG             0x00000020
#define MD_PWR_GLOBAL_CON0_OSTIMER         0x00000040
#define MD_PWR_GLOBAL_CON0_GPT             0x00000080
#define MD_PWR_GLOBAL_CON0_TOPSM           0x00000100
#define MD_PWR_GLOBAL_CON0_SIM1            0x00000400
#define MD_PWR_GLOBAL_CON0_SIM2            0x00000800
#define MD_PWR_GLOBAL_CON0_ELM             0x00010000
#define MD_PWR_GLOBAL_CON0_ALC             0x00020000
#define MD_PWR_GLOBAL_CON0_PF_BUFF         0x00040000

/* MODEM sys */
#define DRVPDN_MODEM_CG_CON0         (MDCONFIG_base+0x0000)
#define DRVPDN_MODEM_CG_CON2         (MDCONFIG_base+0x0008)
#define DRVPDN_MODEM_CG_CON4         (MDCONFIG_base+0x0088)

#define DRVPDN_MODEM_CG_SET0         (MDCONFIG_base+0x0020)
#define DRVPDN_MODEM_CG_SET2         (MDCONFIG_base+0x0028)
#define DRVPDN_MODEM_CG_SET4         (MDCONFIG_base+0x00A8)

#define DRVPDN_MODEM_CG_CLR0         (MDCONFIG_base+0x0010)
#define DRVPDN_MODEM_CG_CLR2         (MDCONFIG_base+0x0018)
#define DRVPDN_MODEM_CG_CLR4         (MDCONFIG_base+0x0098)

#define MODEM_CG_CON0_BSI_PMIC       0x00000004
#define MODEM_CG_CON0_BPI_PMIC       0x00000008
#define MODEM_CG_CON0_BSI_3G         0x00000010
#define MODEM_CG_CON0_BPI_3G         0x00000020
#define MODEM_CG_CON0_WTIMER         0x00000040
#define MODEM_CG_CON0_AFC_3G         0x00000080
#define MODEM_CG_CON0_PFC_DEC        0x00000100
#define MODEM_CG_CON0_BYC_ACC        0x00000200
#define MODEM_CG_CON0_ATB            0x20000000
#define MODEM_CG_CON0_PFC_ENC        0x40000000

#define MODEM_CG_CON2_TDMA           0x00000001
#define MODEM_CG_CON2_BSI_2G_T       0x00000004
#define MODEM_CG_CON2_BPI_2G_T       0x00000008
#define MODEM_CG_CON2_AFC_2G_T       0x00000010
#define MODEM_CG_CON2_DIVIDER        0x00000800
#define MODEM_CG_CON2_FCS            0x00001000
#define MODEM_CG_CON2_GCU            0x00002000

#define MODEM_CG_CON4_BSI_2G         0x00000004
#define MODEM_CG_CON4_BPI_2G         0x00000008
#define MODEM_CG_CON4_AFC_2G         0x00000010

/* AP sys */
#if defined(__MD1__)
#define DRVPDN_AP_PERI_CG_CON0      (AP_PERICFG_base+0x0030)

#define DRVPDN_AP_PERI_CG_SET0      (AP_PERICFG_base+0x0020)

#define DRVPDN_AP_PERI_CG_CLR0      (AP_PERICFG_base+0x0028)

#elif defined(__MD2__)
#define DRVPDN_AP_PERI_CG_CON0      (AP_PERICFG_base+0x0034)

#define DRVPDN_AP_PERI_CG_SET0      (AP_PERICFG_base+0x0024)

#define DRVPDN_AP_PERI_CG_CLR0      (AP_PERICFG_base+0x002C)

#endif

#define AP_PERI_CG_CON0_NFI          0x00000001
#define AP_PERI_CG_CON0_THERM        0x00000002
#define AP_PERI_CG_CON0_PWM1         0x00000004
#define AP_PERI_CG_CON0_PWM2         0x00000008
#define AP_PERI_CG_CON0_PWM3         0x00000010
#define AP_PERI_CG_CON0_PWM4         0x00000020
#define AP_PERI_CG_CON0_PWM5         0x00000040
#define AP_PERI_CG_CON0_PWM6         0x00000080
#define AP_PERI_CG_CON0_PWM7         0x00000100
#define AP_PERI_CG_CON0_PWM          0x00000200
#define AP_PERI_CG_CON0_USB0         0x00000400
#define AP_PERI_CG_CON0_USB1         0x00000800
#define AP_PERI_CG_CON0_AP_DMA       0x00001000
#define AP_PERI_CG_CON0_MSDC20_1     0x00002000
#define AP_PERI_CG_CON0_MSDC20_2     0x00004000
#define AP_PERI_CG_CON0_MSDC30_1     0x00008000
#define AP_PERI_CG_CON0_MSDC30_2     0x00010000
#define AP_PERI_CG_CON0_MSDC30_3     0x00020000
#define AP_PERI_CG_CON0_AP_HIF       0x00040000
#define AP_PERI_CG_CON0_MD_HIF       0x00080000
#define AP_PERI_CG_CON0_NLI          0x00100000
#define AP_PERI_CG_CON0_IRDA         0x00200000
#define AP_PERI_CG_CON0_UART0        0x00400000
#define AP_PERI_CG_CON0_UART1        0x00800000
#define AP_PERI_CG_CON0_UART2        0x01000000
#define AP_PERI_CG_CON0_UART3        0x02000000
#define AP_PERI_CG_CON0_I2C0         0x04000000
#define AP_PERI_CG_CON0_I2C1         0x08000000
#define AP_PERI_CG_CON0_I2C2         0x10000000
#define AP_PERI_CG_CON0_I2C3         0x20000000
#define AP_PERI_CG_CON0_I2C4         0x40000000
#define AP_PERI_CG_CON0_I2C5         0x80000000
/// especial case to speed up HIF operation.
#define AP_PERI_CG_CON0_MD_HIF_COMBIN       (AP_PERI_CG_CON0_MD_HIF | AP_PERI_CG_CON0_AP_HIF | AP_PERI_CG_CON0_AP_DMA)



/** TOPCKEN PDN register **/
#define DRVPDN_AP_TOPCKGEN_CG_SET	(AP_CKGEN_base + 0x0170)
#define DRVPDN_AP_TOPCKGEN_CG_CLR	(AP_CKGEN_base + 0x0174)
#define DRVPDN_AP_TOPCKGEN_CG_CON	(AP_CKGEN_base + 0x0178)

#define AP_TOPCKG_CG_SET_PMICSPI		0x00000001
#define AP_TOPCKG_MD1_CG_SET_PMICSPI	0x00000002  //
#define AP_TOPCKG_MD2_CG_SET_PMICSPI	0x00000004  

#define AP_TOPCKG_CG_CON_PMICSPI		0x00000001
/* here is the violation from PDN API rule, 
 * that con_bit is not the same with set/clr-bit. 
 **/
#define AP_TOPCKG_MD1_CG_CON_PMICSPI	AP_TOPCKG_CG_CON_PMICSPI 
#define AP_TOPCKG_MD2_CG_CON_PMICSPI	AP_TOPCKG_CG_CON_PMICSPI 




/** INFRA PDN register **/
#define DRVPDN_AP_INFRA_CG_SET		(AP_INFRACFG_AO_base + 0x040)
#define DRVPDN_AP_INFRA_CG_CLR		(AP_INFRACFG_AO_base + 0x044)
#define DRVPDN_AP_INFRA_CG_CON		(AP_INFRACFG_AO_base + 0x048)

#define DRVPDN_AP_INFRA_MD1_CG_SET		(AP_INFRACFG_AO_base + 0x060)
#define DRVPDN_AP_INFRA_MD1_CG_CLR		(AP_INFRACFG_AO_base + 0x064)
#define DRVPDN_AP_INFRA_MD1_CG_CON		DRVPDN_AP_INFRA_CG_CON

#define DRVPDN_AP_INFRA_MD2_CG_SET		(AP_INFRACFG_AO_base + 0x068)
#define DRVPDN_AP_INFRA_MD2_CG_CLR		(AP_INFRACFG_AO_base + 0x06C)
#define DRVPDN_AP_INFRA_MD2_CG_CON		DRVPDN_AP_INFRA_CG_CON

#define AP_INFRA_CON_PMICWRAP		(1<<23)
#define AP_INFRA_CON_PMICSPI		(1<<22)

#define AP_INFRA_MD1_CON_PMICWRAP		AP_INFRA_CON_PMICWRAP
#define AP_INFRA_MD1_CON_PMICSPI		AP_INFRA_CON_PMICSPI

#define AP_INFRA_MD2_CON_PMICWRAP		AP_INFRA_CON_PMICWRAP
#define AP_INFRA_MD2_CON_PMICSPI		AP_INFRA_CON_PMICSPI





#endif  /* !__PDN_HW_MT6752_SERIES_H__ */

