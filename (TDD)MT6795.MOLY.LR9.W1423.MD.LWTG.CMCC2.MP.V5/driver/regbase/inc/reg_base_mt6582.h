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
 *   reg_base_mt6582.h
 *
 * Project:
 * --------
 *   MOLY_Software
 *
 * Description:
 * ------------
 *   Definition for chipset register base and global configuration registers
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *----------------------------------------------------------------------------
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
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __REG_BASE_MT6582_H__
#define __REG_BASE_MT6582_H__

/********************************************
 * MT6582 MD Strongly Ordered Peripheral Base
 ********************************************/
 //MD PSYS APB
#define CONFIG_base               (0x80000000)
#define CIRQ_base                 (0x80010000)
#define CIRQ_EINT_base            (0x80010000)
#define TOPSM_base                (0x80030000)
#define OSTIMER_base              (0x80040000)
#define RGU_base                  (0x80050000)
#define GPT_base                  (0x80060000)
#define UART1_base                (0x80070000)
#define DEBUG_MD_base             (0x80090000)
#define DMA_base                  (0x800B0000)
#define SIM0_base                 (0x800C0000)
#define SIM1_base                 (0x800D0000)
#define MD_MBIST_CONFIG_base      (0x800E0000)
#define PLL_MIXEDSYS_base         (0x80120000)
#define ABB_MIXEDSYS_base         (0x80130000)
#define MIX_ABB_base              (ABB_MIXEDSYS_base)
#define ASM_base                  (0x80140000)
#define ADOE_base                 (0x80150000)
#define BOOT_SLAVE_base           (0x80190000)

//MD2GSYS AHB
#define IDMA_base                 (0x82000000)
#define DPRAM_CPU_base            (0x82200000)  //need it??
#define AHB2DSPIO_base            (0x82800000)

//MD2G APB
#define MD2GCONFG_base            (0x82C00000)
#define MD2G_MBIST_CONFIG_base    (0x82C10000)
#define APC_base                  (0x82C30000)
#define CSD_ACC_base              (0x82C70000)
#define SHARE_base                (0x82CA0000)
#define IRDMA_base                (0x82CB0000)
#define IRDBG_base                (IRDMA_base)
#define PATCH_base                (0x82CC0000)
#define AFE_base                  (0x82CD0000)
#define BFE_base                  (0x82CE0000)

//MODEMSYS_TOP APB
#define MDCONFIG_base             (0x83000000)
#define SLP_CTRL_base             (0x83010000)
#define TDMA_base                 (0x83020000)
#define SHAREG2_base              (0x83030000)
#define DIVIDER_base              (0x83040000)
#define FCS_base                  (0x83050000)
#define GCU_base                  (0x83060000)
#define BSI_base                  (0x83070000)
#define BPI_base                  (0x83080000)
#define AFC_base                  (0x83090000)
#define WCDMA_TIMER_base          (0x830A0000)
#define DPA_BC_base               (0x8B0B0000)     /* Device type access */

//HSPASYS_1 APB
#define HSPASYS_CONFIG1_base      (0x83200000)
#define HSEQ_base                 (0x83210000)
#define HSCE_base                 (0x83220000)
#define HSPASYS_1_MBIST_base      (0x83230000)

//HSPASYS_2 APB
#define HSPASYS_CONFIG2_base      (0x83400000) //need it??
#define HSEQ_DC_base              (0x83410000) //need it??
#define HSCE_DC_base              (0x83420000) //need it??
#define RAKEDC_base               (0x83430000) //need it??
#define HSPASYS_2_MBIST_base      (0x83440000) //need it??

//HSPASYS_3 APB
#define F8F9_1_base               (0x8B600000)    /* Device type access */
#define F8F9_base                 (0x8B610000)    /* Device type access */
#define F8F9_2_base               (0x8B610000)    /* Request by Alfred Lee */ /* Device type access */
#define DPA_RLC_base              (0x8B620000)    /* Device type access */
#define DPA_MAC_base              (0x8B630000)    /* Device type access */
#define HSUPA_base                (UPA_base)
#define UPA_base                  (0x8B640000)    /* Device type access */
#define HRXBRP_base               (0x83650000)
#define RXBRP_base                (0x83660000)
#define HSPASYS_CONFIG3_base      (0x83670000)
#define TXBRP_base                (0x83680000)
#define TXCRP_base                (0x83690000)
#define UTXBRP_base               (0x836A0000)
#define TXUPC_base                (0x836B0000)
#define BITCP_base                (0x836C0000)
#define HSPA3_DBG_base            (0x836D0000)
#define HSPASYS_3_MBIST_base      (0x836E0000)

//HSPASYS_4 APB
#define RXSRP_base                (0x83800000)
#define INDEC_base                (0x83810000)
#define RXCRP0_base               (0x83820000)
#define RXCRP1_base               (0x83830000)
#define RXCRP2_base               (0x83840000)
#define SRCHR_base                (0x83850000)
#define RXDFE_base                (0x83860000)
#define HSPASYS_CONFIG4_base      (0x83870000)
#define HSPA4_DBG_base            (0x83880000)
#define DBG_WRAPPER0_base         (0x83890000)
#define LOG3G_base                (0x838A0000)
#define HSPASYS_4_MBIST_base      (0x838B0000)
#define DBG_WRAPPER1_base         (0x838C0000)
#define SIMPLE_DMA_base           (0x838D0000)

/********************************************
 * MT6582 MD Device Type Peripheral Base
 ********************************************/
 //MD PSYS APB
#define CONFIG_SD_base            (0x88000000)
#define CIRQ_SD_base              (0x88010000)
#define CIRQ_EINT_SD_base         (0x88010000)
#define TOPSM_SD_base             (0x88030000)
#define OSTIMER_SD_base           (0x88040000)
#define RGU_SD_base               (0x88050000)
#define GPT_SD_base               (0x88060000)
#define UART1_SD_base             (0x88070000)
#define DEBUG_MD_SD_base          (0x88090000)
#define DMA_SD_base               (0x880B0000)
#define SIM0_SD_base              (0x880C0000)
#define SIM1_SD_base              (0x880D0000)
#define MD_MBIST_CONFIG_SD_base   (0x880E0000)
#define PLL_MIXEDSYS_SD_base      (0x88120000)
#define ABB_MIXEDSYS_SD_base      (0x88130000)
#define MIX_ABB_SD_base           (ABB_MIXEDSYS_SD_base)
#define ASM_SD_base               (0x88140000)
#define ADOE_SD_base              (0x88150000)
#define BOOT_SLAVE_SD_base        (0x88190000)

//MD2GSYS AHB
#define IDMA_SD_base              (0x8A000000)
#define DPRAM_CPU_SD_base         (0x8A200000)
#define AHB2DSPIO_SD_base         (0x8A800000)

//MD2G APB
#define MD2GCONFG_SD_base         (0x8AC00000)
#define MD2G_MBIST_CONFIG_SD_base (0x8AC10000)
#define APC_SD_base               (0x8AC30000)
#define CSD_ACC_SD_base           (0x8AC70000)
#define SHARE_SD_base             (0x8ACA0000)
#define IRDMA_SD_base             (0x8ACB0000)
#define IRDBG_SD_base             (IRDMA_SD_base)
#define PATCH_SD_base             (0x8ACC0000)
#define AFE_SD_base               (0x8ACD0000)
#define BFE_SD_base               (0x8ACE0000)

//MODEMSYS_TOP APB
#define MDCONFIG_SD_base          (0x8B000000)
#define SLP_CTRL_SD_base          (0x8B010000)
#define TDMA_SD_base              (0x8B020000)
#define SHAREG2_SD_base           (0x8B030000)
#define DIVIDER_SD_base           (0x8B040000)
#define FCS_SD_base               (0x8B050000)
#define GCU_SD_base               (0x8B060000)
#define BSI_SD_base               (0x8B070000)
#define BPI_SD_base               (0x8B080000)
#define AFC_SD_base               (0x8B090000)
#define WCDMA_TIMER_SD_base       (0x8B0A0000)
#define DPA_BC_SD_base            (0x8B0B0000)

//HSPASYS_1 APB
#define HSPASYS_CONFIG1_SD_base   (0x8B200000)
#define HSEQ_SD_base              (0x8B210000)
#define HSCE_SD_base              (0x8B220000)
#define HSPASYS_1_MBIST_SD_base   (0x8B230000)

//HSPASYS_2 APB
#define HSPASYS_CONFIG2_SD_base   (0x8B400000)
#define HSEQ_DC_SD_base           (0x8B410000)
#define HSCE_DC_SD_base           (0x8B420000)
#define RAKEDC_SD_base            (0x8B430000)
#define HSPASYS_2_MBIST_SD_base   (0x8B440000)

//HSPASYS_3 APB
#define F8F9_1_SD_base            (0x8B600000)
#define F8F9_SD_base              (0x8B610000)
#define F8F9_2_SD_base            (0x8B610000)
#define DPA_RLC_SD_base           (0x8B620000)
#define DPA_MAC_SD_base           (0x8B630000)
#define HSUPA_SD_base             (UPA_SD_base)
#define UPA_SD_base               (0x8B640000)
#define HRXBRP_SD_base            (0x8B650000)
#define RXBRP_SD_base             (0x8B660000)
#define HSPASYS_CONFIG3_SD_base   (0x8B670000)
#define TXBRP_SD_base             (0x8B680000)
#define TXCRP_SD_base             (0x8B690000)
#define UTXBRP_SD_base            (0x8B6A0000)
#define TXUPC_SD_base             (0x8B6B0000)
#define BITCP_SD_base             (0x8B6C0000)
#define HSPA3_DBG_SD_base         (0x8B6D0000)
#define HSPASYS_3_MBIST_SD_base   (0x8B6E0000)

//HSPASYS_4 APB
#define RXSRP_SD_base             (0x8B800000)
#define INDEC_SD_base             (0x8B810000)
#define RXCRP0_SD_base            (0x8B820000)
#define RXCRP1_SD_base            (0x8B830000)
#define RXCRP2_SD_base            (0x8B840000)
#define SRCHR_SD_base             (0x8B850000)
#define RXDFE_SD_base             (0x8B860000)
#define HSPASYS_CONFIG4_SD_base   (0x8B870000)
#define HSPA4_DBG_SD_base         (0x8B880000)
#define DBG_WRAPPER0_SD_base      (0x8B890000)
#define LOG3G_SD_base             (0x8B8A0000)
#define HSPASYS_4_MBIST_SD_base   (0x8B8B0000)
#define DBG_WRAPPER1_SD_base      (0x8B8C0000)
#define SIMPLE_DMA_SD_base        (0x8B8D0000)




#define AP_MDCCIF_base            (0xA020A000)  //AP CCIF
#define MDCCIF_base               (0xA020B000)  //MD CCIF

/////////////////////////////////////////////////////////////////////////


/********************************************
 * MT6582 AP Peripheral Register Base
 ********************************************/

/// AP Infrastructure, Mixmode & MCU System

/// AP Infrastructure MCU System
#define AP_EMI_base               (0xA0203000)  //EMI Bus Interface //Request by CM, JH
#define EMI_base                  (AP_EMI_base) //EMI Bus Interface
#define AP_DRAMC_base             (0xA0004000)  //dramc nao region Register
#define AP_TOP_CLOCK_CTRL_BASE    (0xA0000000)  //Request by Anderson Tasi
#define AP_TOPRGU_BASE            (0xA0007000)  //Request by Anderson Tasi
#define AP_GPIO_base              (0xA0005000)  //GPIO Controller //Request by Dongming Li
#define AP_PMIC_WRAP_BASE         (0xA000D000)  //PMIC_WRAP Control Register //Request by Anderson Tasi
#define AP_CKSYS_BASE             (0xA0000000)  //Requested by Anderson Tsai
#define AP_INFRACFG_AO_BASE       (0xA0001000)  //Requested by Anderson Tsai
#define EFUSE_base                (0xA0206000 )  /*EFUSE base */

/// AP Peripheral system
#define AP_AUDSYS_base            (0xA1220000)  //Audio AHB slave //Request by Sheila Chen
#define USB_base                  (0xA1200000)  //USB2.0 --> requested by Arvin wang
#define AP_USBSIF_base            (0xA1210000)  //USBSIF
#define USBSIF_base               (AP_USBSIF_base)//USBSIF --> requested by Arvin Wang

#define BTSRAM_base               (0xA8080000)  //BT SCO SW codec interface // Requested by Wn Chen
#define BTPKT_base                (0xA8000000)  //BT SCO SW codec interface // Requested by Wn Chen

///Infrastructure MCU System

#endif  /* __REG_BASE_MT6582_H__ */
