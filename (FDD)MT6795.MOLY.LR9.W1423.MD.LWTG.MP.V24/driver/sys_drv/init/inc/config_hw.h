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
 *   config_hw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Definition for CONFIG hardware registers
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __CONFIG_HW_H__
#define __CONFIG_HW_H__

/*******************************************************************************
 * Include header files
 *******************************************************************************/
//MSBB remove #include "kal_non_specific_general_types.h"
#include "reg_base.h"


/*******************************************************************************
 * header files body
 *******************************************************************************/


/*******************************************************************************
 * Version
 *******************************************************************************/
#define HW_VER                   ((volatile UINT16P)(CONFIG_base+0x0000))
#define FW_VER                   ((volatile UINT16P)(CONFIG_base+0x0004))
#define SW_VER                   FW_VER
#define HW_CODE                  ((volatile UINT16P)(CONFIG_base+0x0008))
#if ( defined(MT6280) || defined(MT6290)) 
#define HW_SUBCODE               ((volatile UINT16P)(CONFIG_base+0x000C))
#endif


/*******************************************************************************
 * System special register
 *******************************************************************************/
#define SW_MISC_L                ((volatile UINT32P)(CONFIG_base+0x10))
#define SW_MISC_H                ((volatile UINT32P)(CONFIG_base+0x14))

/*******************************************************************************
 * CLK registers
 *******************************************************************************/

#if defined(MT6280)

#define CLKSQ_CON0                  							((volatile UINT16P)(MIXED_Base+0x0020))   			/* Clock control */
#define PLL_CON1                                  ((volatile UINT16P)(MIXED_Base+0x0044))
#define MPLL_CON0                                 ((volatile UINT16P)(MIXED_Base+0x0100)) 	
#define MPLL_CON1                                 ((volatile UINT16P)(MIXED_Base+0x0104)) 	
#define MPLL_CON2                                 ((volatile UINT16P)(MIXED_Base+0x0108)) 	
#define MPLL_CON3                                 ((volatile UINT16P)(MIXED_Base+0x010C)) 	
#define UPLL_CON0                                 ((volatile UINT16P)(MIXED_Base+0x0140)) 	
#define UPLL_CON1                                 ((volatile UINT16P)(MIXED_Base+0x0144)) 	
#define UPLL_CON2                                 ((volatile UINT16P)(MIXED_Base+0x0148)) 	
#define UPLL_CON3                                 ((volatile UINT16P)(MIXED_Base+0x014C)) 	
#define WPLL_CON0                                 ((volatile UINT16P)(MIXED_Base+0x01C0)) 	
#define WPLL_CON1                                 ((volatile UINT16P)(MIXED_Base+0x01C4)) 	
#define WPLL_CON2                                 ((volatile UINT16P)(MIXED_Base+0x01C8)) 	
#define WPLL_CON3                                 ((volatile UINT16P)(MIXED_Base+0x01CC)) 	
#define EPLL_CON0                                 ((volatile UINT16P)(MIXED_Base+0x0200)) 	
#define EPLL_CON1                                 ((volatile UINT16P)(MIXED_Base+0x0204)) 	
#define EPLL_CON2                                 ((volatile UINT16P)(MIXED_Base+0x0208)) 	
#define EPLL_CON3                                 ((volatile UINT16P)(MIXED_Base+0x020C)) 	

#define SIMLS_CON0                                ((volatile UINT16P)(MIXED_Base+0x0320)) 
#define SIMLS_CON1                                ((volatile UINT16P)(MIXED_Base+0x0324)) 

#define MD_CHIP_STATUS                          ((volatile UINT32P)(CONFIG_base+0x0018))
#define MD_MCU_CON0                             ((volatile UINT32P)(CONFIG_base+0x0020))
#define MD_BUS_CON0                             ((volatile UINT32P)(CONFIG_base+0x0040))
#define MD_BUS_STATUS0                          ((volatile UINT32P)(CONFIG_base+0x0050))

#define AP_OST_STA                              ((volatile kal_uint32*)(AP_OSTIMER_base+0x0008))

#endif /* MT6280 */

#if defined(MT6575) || defined(MT6577)

#define PLL_CON0                  ((volatile UINT16P)(MIX_ABB_base+0x100))
#define PLL_CON1                  ((volatile UINT16P)(MIX_ABB_base+0x104))
#define PLL_CON2                  ((volatile UINT16P)(MIX_ABB_base+0x108))
#define PLL_CON3                  ((volatile UINT16P)(MIX_ABB_base+0x10C))
#define PLL_CON4                  ((volatile UINT16P)(MIX_ABB_base+0x110))
#define PLL_CON5                  ((volatile UINT16P)(MIX_ABB_base+0x114))
#define MPLL_CON0                  ((volatile UINT16P)(MIX_ABB_base+0x140))
#define MPLL_CON1                  ((volatile UINT16P)(MIX_ABB_base+0x144))
#define MPLL_CON2                  ((volatile UINT16P)(MIX_ABB_base+0x148))
#define MPLL_CON3                  ((volatile UINT16P)(MIX_ABB_base+0x14C))
#define DPLL_CON0                  ((volatile UINT16P)(MIX_ABB_base+0x180))
#define DPLL_CON1                  ((volatile UINT16P)(MIX_ABB_base+0x184))
#define DPLL_CON2                  ((volatile UINT16P)(MIX_ABB_base+0x188))
#define DPLL_CON3                  ((volatile UINT16P)(MIX_ABB_base+0x18C))
#define EPLL_CON0                  ((volatile UINT16P)(MIX_ABB_base+0x1C0))
#define EPLL_CON1                  ((volatile UINT16P)(MIX_ABB_base+0x1C4))
#define EPLL_CON2                  ((volatile UINT16P)(MIX_ABB_base+0x1C8))
#define EPLL_CON3                  ((volatile UINT16P)(MIX_ABB_base+0x1CC))
#define CPLL_CON0                  ((volatile UINT16P)(MIX_ABB_base+0x200))
#define WPLL_CON0                  ((volatile UINT16P)(MIX_ABB_base+0x240))
#define GPLL_CON0                  ((volatile UINT16P)(MIX_ABB_base+0x280))

#define PDN_CON                    ((volatile UINT16P)(MIXED_base+0x010))    /* Power down control */

#define AP_ARM_FSEL             ((volatile UINT16P)(AP_CONFIG_base+0x100))
#define DSP_FSEL                ((volatile UINT16P)(AP_CONFIG_base+0x104))
#define EMI_FSEL                ((volatile UINT16P)(AP_CONFIG_base+0x108))
#define FBUS_FSEL               ((volatile UINT16P)(AP_CONFIG_base+0x10C))
#define SBUS_FSEL               ((volatile UINT16P)(AP_CONFIG_base+0x110))
#define DSP_IDLE_FSEL           ((volatile UINT16P)(AP_CONFIG_base+0x114))
#define EMI_IDLE_FSEL           ((volatile UINT16P)(AP_CONFIG_base+0x118))
#define FBUS_IDLE_FSEL          ((volatile UINT16P)(AP_CONFIG_base+0x11C))
#define SBUS_IDLE_FSEL          ((volatile UINT16P)(AP_CONFIG_base+0x120))
#define RG_CK_ALW_ON            ((volatile UINT16P)(AP_CONFIG_base+0x124))
#define RG_CK_DCM_EN            ((volatile UINT16P)(AP_CONFIG_base+0x128))
#define RG_EMI_DBC              ((volatile UINT16P)(AP_CONFIG_base+0x12C))
#define RG_BUS_DBC              ((volatile UINT16P)(AP_CONFIG_base+0x130))

#endif /* MT6575 || MT6577 */


/* boot mode control register */
/* New chip will have SW_MISC_L, plesae do not specify specific address */
#define BOOT_CONFIG_ADDR         SW_MISC_L

#if defined(MT6290)
//Use 0x0 as fake address since the chip does not have boot slave
#define BOOT_SLAVE_ADDR_PTR     ((volatile UINT32P)0x0)
#else
#define BOOT_SLAVE_ADDR_PTR     ((volatile UINT32P)0xFFFF0020)
#endif
#endif  /* !__CONFIG_HW_H__ */

