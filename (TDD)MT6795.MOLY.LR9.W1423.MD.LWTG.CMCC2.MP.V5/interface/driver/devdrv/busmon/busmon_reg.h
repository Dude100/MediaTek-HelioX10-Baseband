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
 *   busmon_reg.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Busmon register definition
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
 * 6595 busmon deriver porting
 *
 * removed!
 * removed!
 * Merge MT6595_E1_DEV  into MOLY trunk
 *
 * removed!
 * removed!
 *
 ****************************************************************************/

#ifndef __BUSMON_REG_H__
#define __BUSMON_REG_H__

#include <reg_base.h>

/*
  Device Type                                             Strongly-ordered Type
  #define BASE_ADDR_MDMCUBUSMON (0xBF420000)              #define BASE_MADDR_MDMCUBUSMON (0xFF420000)
  #define BASE_ADDR_MDMAXIMON0 (0xBF420000)               #define BASE_MADDR_MDMAXIMON (0xFF420000)
  #define BASE_ADDR_MDMAXIMON1 (0xBF424000) // ?

  #define BASE_ADDR_MDINFRABUSMON (0xBF320000)            #define BASE_MADDR_MDINFRABUSMON (0xFF320000)
  #define BASE_ADDR_MDPAXIMON0 (0xBF320000)               #define BASE_MADDR_MDPAXIMON0 (0xFF320000)
  #define BASE_ADDR_MDPAHBMON0 (0xBF324000)               #define BASE_MADDR_MDPAXIMON1 (0xFF324000)
  #define BASE_ADDR_MDPAHBMON1 (0xBF328000)               #define BASE_MADDR_MDPAHBMON0 (0xFF328000)
                                                          #define BASE_MADDR_MDPAHBMON1 (0xFF32C000) // ?

  #define BASE_ADDR_APMCUBUSMON (0xBE450000)              #define BASE_MADDR_APMCUBUSMON (0xFE450000)
  #define BASE_ADDR_APMAXIMON0 (0xBE450000)               #define BASE_MADDR_APMAXIMON (0xFE450000)
  #define BASE_ADDR_APMAXIMON1 (0xBE454000) // ?

  #define BASE_ADDR_APPERIBUSMON (0xBE4A0000)             #define BASE_MADDR_APPERIBUSMON (0xFE4A0000)
  #define BASE_ADDR_APPAXIMON0 (0xBE4A0000)               #define BASE_MADDR_APPAXIMON0 (0xFE4A0000)
  #define BASE_ADDR_APPAHBMON0 (0xBE4A4000)               #define BASE_MADDR_APPAHBMON0 (0xFE4A4000)
                                                          #define BASE_MADDR_APPAHBMON1 (0xFE4A8000) // ?
                                                          #define BASE_MADDR_APPAHBMON2 (0xFE4AC000) // ?

*/


/*
 * AXI Bus Monitor
 */
#define AXIMON_BASE                             (0)

#define AXIMON_COD_VERSION                      (AXIMON_BASE + 0x0000)
#define AXIMON_DMY_REG                          (AXIMON_BASE + 0x0004)
#define AXIMON_CTL                              (AXIMON_BASE + 0x0010)
#define AXIMON_TST                              (AXIMON_BASE + 0x0014)
#define AXIMON_STS                              (AXIMON_BASE + 0x0018)
#define AXIMON_INT                              (AXIMON_BASE + 0x0020)
#define AXIMON_INT_MSK                          (AXIMON_BASE + 0x0024)
#define AXIMON_IP0_TG                           (AXIMON_BASE + 0x0030)
#define AXIMON_IP0_TMR                          (AXIMON_BASE + 0x0034)
#define AXIMON_IP0_ADDR                         (AXIMON_BASE + 0x0040)
#define AXIMON_IP0_ADDRMSK                      (AXIMON_BASE + 0x0044)
#define AXIMON_IP0_DATAL                        (AXIMON_BASE + 0x0050)
#define AXIMON_IP0_DATAH                        (AXIMON_BASE + 0x0054)
#define AXIMON_IP0_DATAMSKL                     (AXIMON_BASE + 0x0058)
#define AXIMON_IP0_DATAMSKH                     (AXIMON_BASE + 0x005C)
#define AXIMON_IP1_TG                           (AXIMON_BASE + 0x0060)
#define AXIMON_IP1_TMR                          (AXIMON_BASE + 0x0064)
#define AXIMON_IP1_ADDR                         (AXIMON_BASE + 0x0070)
#define AXIMON_IP1_ADDR_MSK                     (AXIMON_BASE + 0x0074)
#define AXIMON_IP1_DATAL                        (AXIMON_BASE + 0x0080)
#define AXIMON_IP1_DATAH                        (AXIMON_BASE + 0x0084)
#define AXIMON_IP1_DATAMSKL                     (AXIMON_BASE + 0x0088)
#define AXIMON_IP1_DATAMSKH                     (AXIMON_BASE + 0x008C)
#define AXIMON_TOT_BUS_CYC                      (AXIMON_BASE + 0x0100)
#define AXIMON_IP0_NON_OV_TRANS_NUM             (AXIMON_BASE + 0x0200)
#define AXIMON_IP0_OV_TRANS_NUM                 (AXIMON_BASE + 0x0204)
#define AXIMON_IP0_NON_WGT_TRANS_CYC            (AXIMON_BASE + 0x0208)
#define AXIMON_IP0_WGT_TRANS_CYC                (AXIMON_BASE + 0x020C)
#define AXIMON_IP0_MAX_TRANS_CYC                (AXIMON_BASE + 0x0210)
#define AXIMON_IP0_MAX_OST_TRANS_NUM            (AXIMON_BASE + 0x0214)
#define AXIMON_IP0_AW_TOT_DEV_CYC               (AXIMON_BASE + 0x0220)
#define AXIMON_IP0_AW_MAX_DEV_CYC               (AXIMON_BASE + 0x0224)
#define AXIMON_IP0_AW2W_TOT_MST_CYC             (AXIMON_BASE + 0x0230)
#define AXIMON_IP0_AW2W_MAX_MST_CYC             (AXIMON_BASE + 0x0234)
#define AXIMON_IP0_AW2W_TOT_DEV_CYC             (AXIMON_BASE + 0x0238)
#define AXIMON_IP0_AW2W_MAX_DEV_CYC             (AXIMON_BASE + 0x023C)
#define AXIMON_IP0_AW2W_MAX_WT_CYC              (AXIMON_BASE + 0x0240)
#define AXIMON_IP0_W_TOT_MST_CYC                (AXIMON_BASE + 0x0250)
#define AXIMON_IP0_W_MAX_MST_CYC                (AXIMON_BASE + 0x0254)
#define AXIMON_IP0_W_TOT_DEV_CYC                (AXIMON_BASE + 0x0258)
#define AXIMON_IP0_W_MAX_DEV_CYC                (AXIMON_BASE + 0x025C)
#define AXIMON_IP0_W_TOT_DATA_CYC               (AXIMON_BASE + 0x0260)
#define AXIMON_IP0_W_TOT_DATA_CNT               (AXIMON_BASE + 0x0264)
#define AXIMON_IP0_W2B_TOT_DEV_CYC              (AXIMON_BASE + 0x0270)
#define AXIMON_IP0_W2B_MAX_DEV_CYC              (AXIMON_BASE + 0x0274)
#define AXIMON_IP0_AR_TOT_DEV_CYC               (AXIMON_BASE + 0x0280)
#define AXIMON_IP0_AR_MAX_DEV_CYC               (AXIMON_BASE + 0x0284)
#define AXIMON_IP0_AR2R_TOT_MST_CYC             (AXIMON_BASE + 0x0290)
#define AXIMON_IP0_AR2R_MAX_MST_CYC             (AXIMON_BASE + 0x0294)
#define AXIMON_IP0_AR2R_TOT_DEV_CYC             (AXIMON_BASE + 0x0298)
#define AXIMON_IP0_AR2R_MAX_DEV_CYC             (AXIMON_BASE + 0x029C)
#define AXIMON_IP0_AR2R_MAX_WT_CYC              (AXIMON_BASE + 0x02A0)
#define AXIMON_IP0_R_TOT_MST_CYC                (AXIMON_BASE + 0x02B0)
#define AXIMON_IP0_R_MAX_MST_CYC                (AXIMON_BASE + 0x02B4)
#define AXIMON_IP0_R_TOT_DEV_CYC                (AXIMON_BASE + 0x02B8)
#define AXIMON_IP0_R_MAX_DEV_CYC                (AXIMON_BASE + 0x02BC)
#define AXIMON_IP0_R_TOT_DATA_CYC               (AXIMON_BASE + 0x02C0)
#define AXIMON_IP0_R_TOT_DATA_CNT               (AXIMON_BASE + 0x02C4)
#define AXIMON_IP0_SNAP_INFO0                   (AXIMON_BASE + 0x0300)
#define AXIMON_IP0_SNAP_INFO1                   (AXIMON_BASE + 0x0304)
#define AXIMON_IP0_SNAP_INFO2                   (AXIMON_BASE + 0x0308)
#define AXIMON_IP0_SNAP_INFO3                   (AXIMON_BASE + 0x030C)
#define AXIMON_IP0_SNAP_INFO4                   (AXIMON_BASE + 0x0310)
#define AXIMON_IP0_SNAP_INFO5                   (AXIMON_BASE + 0x0314)
#define AXIMON_IP0_SNAP_INFO6                   (AXIMON_BASE + 0x0318)
#define AXIMON_IP0_SNAP_INFO7                   (AXIMON_BASE + 0x031C)
#define AXIMON_IP1_NON_OV_TRANS_NUM             (AXIMON_BASE + 0x0400)
#define AXIMON_IP1_OV_TRANS_NUM                 (AXIMON_BASE + 0x0404)
#define AXIMON_IP1_NON_WGT_TRANS_CYC            (AXIMON_BASE + 0x0408)
#define AXIMON_IP1_WGT_TRANS_CYC                (AXIMON_BASE + 0x040C)
#define AXIMON_IP1_MAX_TRANS_CYC                (AXIMON_BASE + 0x0410)
#define AXIMON_IP1_MAX_OST_TRANS_NUM            (AXIMON_BASE + 0x0414)
#define AXIMON_IP1_AW_TOT_DEV_CYC               (AXIMON_BASE + 0x0420)
#define AXIMON_IP1_AW_MAX_DEV_CYC               (AXIMON_BASE + 0x0424)
#define AXIMON_IP1_AW2W_TOT_MST_CYC             (AXIMON_BASE + 0x0430)
#define AXIMON_IP1_AW2W_MAX_MST_CYC             (AXIMON_BASE + 0x0434)
#define AXIMON_IP1_AW2W_TOT_DEV_CYC             (AXIMON_BASE + 0x0438)
#define AXIMON_IP1_AW2W_MAX_DEV_CYC             (AXIMON_BASE + 0x043C)
#define AXIMON_IP1_AW2W_MAX_WT_CYC              (AXIMON_BASE + 0x0440)
#define AXIMON_IP1_W_TOT_MST_CYC                (AXIMON_BASE + 0x0450)
#define AXIMON_IP1_W_MAX_MST_CYC                (AXIMON_BASE + 0x0454)
#define AXIMON_IP1_W_TOT_DEV_CYC                (AXIMON_BASE + 0x0458)
#define AXIMON_IP1_W_MAX_DEV_CYC                (AXIMON_BASE + 0x045C)
#define AXIMON_IP1_W_TOT_DATA_CYC               (AXIMON_BASE + 0x0460)
#define AXIMON_IP1_W_TOT_DATA_CNT               (AXIMON_BASE + 0x0464)
#define AXIMON_IP1_W2B_TOT_DEV_CYC              (AXIMON_BASE + 0x0470)
#define AXIMON_IP1_W2B_MAX_DEV_CYC              (AXIMON_BASE + 0x0474)
#define AXIMON_IP1_AR_TOT_DEV_CYC               (AXIMON_BASE + 0x0480)
#define AXIMON_IP1_AR_MAX_DEV_CYC               (AXIMON_BASE + 0x0484)
#define AXIMON_IP1_AR2R_TOT_MST_CYC             (AXIMON_BASE + 0x0490)
#define AXIMON_IP1_AR2R_MAX_MST_CYC             (AXIMON_BASE + 0x0494)
#define AXIMON_IP1_AR2R_TOT_DEV_CYC             (AXIMON_BASE + 0x0498)
#define AXIMON_IP1_AR2R_MAX_DEV_CYC             (AXIMON_BASE + 0x049C)
#define AXIMON_IP1_AR2R_MAX_WT_CYC              (AXIMON_BASE + 0x04A0)
#define AXIMON_IP1_R_TOT_MST_CYC                (AXIMON_BASE + 0x04B0)
#define AXIMON_IP1_R_MAX_MST_CYC                (AXIMON_BASE + 0x04B4)
#define AXIMON_IP1_R_TOT_DEV_CYC                (AXIMON_BASE + 0x04B8)
#define AXIMON_IP1_R_MAX_DEV_CYC                (AXIMON_BASE + 0x04BC)
#define AXIMON_IP1_R_TOT_DATA_CYC               (AXIMON_BASE + 0x04C0)
#define AXIMON_IP1_R_TOT_DATA_CNT               (AXIMON_BASE + 0x04C4)
#define AXIMON_IP1_SNAP_INFO0                   (AXIMON_BASE + 0x0500)
#define AXIMON_IP1_SNAP_INFO1                   (AXIMON_BASE + 0x0504)
#define AXIMON_IP1_SNAP_INFO2                   (AXIMON_BASE + 0x0508)
#define AXIMON_IP1_SNAP_INFO3                   (AXIMON_BASE + 0x050C)
#define AXIMON_IP1_SNAP_INFO4                   (AXIMON_BASE + 0x0510)
#define AXIMON_IP1_SNAP_INFO5                   (AXIMON_BASE + 0x0514)
#define AXIMON_IP1_SNAP_INFO6                   (AXIMON_BASE + 0x0518)
#define AXIMON_IP1_SNAP_INFO7                   (AXIMON_BASE + 0x051C)
#define AXIMON_DBG_CTL0                         (AXIMON_BASE + 0x0600)
#define AXIMON_DBG_CTL1                         (AXIMON_BASE + 0x0604)
#define AXIMON_DBG_CTL2                         (AXIMON_BASE + 0x0608)

#define AXIMON_CFG_OFFSET                       (0x30)
#define AXIMON_INFO_OFFSET                      (0x200)

/* Default Vaule */
#define AXIMON_COD_VERSION_DEFAULT              (0x20120907)
#define AXIMON_TST_DEFAULT                      (0x40000)

/* Bit Field & Mask */
#define AXIMON_CODA_VERSION_MASK                (0xFFFFFFFF)   /* [31:0] */
#define AXIMON_CODA_VERSION_SHIFT               (0)            /* [31:0] */

#define AXIMON_CTL_START_MASK                   (0x1)          /* [0] */
#define AXIMON_CTL_START_SHIFT                  (0)            /* [0] */
#define AXIMON_CTL_PAUSE_MASK                   (0x1)          /* [1] */
#define AXIMON_CTL_PAUSE_SHIFT                  (1)            /* [1] */
#define AXIMON_CTL_RESUME_MASK                  (0x1)          /* [2] */
#define AXIMON_CTL_RESUME_SHIFT                 (2)            /* [2] */

#if (defined(MT6290))
#define AXIMON_TST_SEQ_TRG_MODE_MASK            (0x1)          /* [0] */
#define AXIMON_TST_SEQ_TRG_MODE_SHIFT           (0)            /* [0] */
#define AXIMON_TST_SPEED_SIM_MASK               (0x1)          /* [8] */
#define AXIMON_TST_SPEED_SIM_SHIFT              (8)            /* [8] */
#define AXIMON_TST_LYR_AXI_SEL_MASK             (0x3)          /* [17:16] */
#define AXIMON_TST_LYR_AXI_SEL_SHIFT            (16)           /* [17:16] */
#define AXIMON_TST_CTL_ACTIVE_MASK              (0x1)          /* [18] */
#define AXIMON_TST_CTL_ACTIVE_SHIFT             (18)           /* [18] */

#elif (defined(MT6595))
#define AXIMON_TST_SEQ_TRG_MODE_MASK            (0x1)          /* [0] */
#define AXIMON_TST_SEQ_TRG_MODE_SHIFT           (0)            /* [0] */
#define AXIMON_TST_SPEED_SIM_MASK               (0x1)          /* [8] */
#define AXIMON_TST_SPEED_SIM_SHIFT              (8)            /* [8] */
#define AXIMON_TST_LYR_AXI_SEL_MASK             (0x7)          /* [18:16] */
#define AXIMON_TST_LYR_AXI_SEL_SHIFT            (16)           /* [18:16] */
#define AXIMON_TST_CTL_ACTIVE_MASK              (0x1)          /* [19] */
#define AXIMON_TST_CTL_ACTIVE_SHIFT             (19)           /* [19] */

#endif

#define AXIMON_STS_STAT0_MASK                   (0x1)          /* [0] */
#define AXIMON_STS_STAT0_SHIFT                  (0)            /* [0] */
#define AXIMON_STS_STAT1_MASK                   (0x1)          /* [1] */
#define AXIMON_STS_STAT1_SHIFT                  (1)            /* [1] */
#define AXIMON_STS_ARW_FIFO_OVERFLOW_MASK       (0x3)          /* [9:8] */
#define AXIMON_STS_ARW_FIFO_OVERFLOW_SHIFT      (8)            /* [9:8] */
#define AXIMON_STS_RW_FIFO_OVERFLOW_MASK        (0x3)          /* [11:10] */
#define AXIMON_STS_RW_FIFO_OVERFLOW_SHIFT       (10)           /* [11:10] */

#define AXIMON_INT_MASK                         (0x1)          /* [0] */
#define AXIMON_INT_SHIFT                        (0)            /* [0] */

#define AXIMON_INT_MSK_MASK                     (0x1)          /* [0] */
#define AXIMON_INT_MSK_SHIFT                    (0)            /* [0] */

#define AXIMON_TG_MON_MASTER_MASK               (0xFF)         /* [7:0] */
#define AXIMON_TG_MON_MASTER_SHIFT              (0)            /* [7:0] */
#define AXIMON_TG_MON_ALL_MST_MASK              (0x1)          /* [7] */
#define AXIMON_TG_MON_ALL_MST_SHIFT             (7)            /* [7] */
#define AXIMON_TG_MON_RWSEL_MASK                (0x1)          /* [8] */
#define AXIMON_TG_MON_RWSEL_SHIFT               (8)            /* [8] */
#define AXIMON_TG_MON_MODE_MASK                 (0x1)          /* [9] */
#define AXIMON_TG_MON_MODE_SHIFT                (9)            /* [9] */
#define AXIMON_TG_MON_ENABLE_MASK               (0x1)          /* [10] */
#define AXIMON_TG_MON_ENABLE_SHIFT              (10)           /* [10] */
#define AXIMON_TG_TRG_MODE_MASK                 (0x1)          /* [11] */
#define AXIMON_TG_TRG_MODE_SHIFT                (11)           /* [11] */
#define AXIMON_TG_MON_CNT_MASK                  (0xFFFF)       /* [31:16] */
#define AXIMON_TG_MON_CNT_SHIFT                 (16)           /* [31:16] */

#define AXIMON_TMR_MON_TRG_CYC_MASK             (0xFFFF)       /* [15:0] */
#define AXIMON_TMR_MON_TRG_CYC_SHIFT            (0)            /* [15:0] */

#define AXIMON_ADDR_MASK                        (0xFFFFFFFF)   /* [31:0] */
#define AXIMON_ADDR_SHIFT                       (0)            /* [31:0] */

#define AXIMON_ADDRMSK_MASK                     (0xFFFFFFFF)   /* [31:0] */
#define AXIMON_ADDRMSK_SHIFT                    (0)            /* [31:0] */

#define AXIMON_DATAL_MASK                       (0xFFFFFFFF)   /* [31:0] */
#define AXIMON_DATAL_SHIFT                      (0)            /* [31:0] */

#define AXIMON_DATAH_MASK                       (0xFFFFFFFF)   /* [31:0] */
#define AXIMON_DATAH_SHIFT                      (0)            /* [31:0] */

#define AXIMON_DATAMSKL_MASK                    (0xFFFFFFFF)   /* [31:0] */
#define AXIMON_DATAMSKL_SHIFT                   (0)            /* [31:0] */

#define AXIMON_DATAMSKH_MASK                    (0xFFFFFFFF)   /* [31:0] */
#define AXIMON_DATAMSKH_SHIFT                   (0)            /* [31:0] */

#define AXIMON_TOT_BUS_CYC_MASK                 (0xFFFFFFFF)   /* [31:0] */
#define AXIMON_TOT_BUS_CYC_SHIFT                (0)            /* [31:0] */

#define AXIMON_NON_OV_TRANS_NUM_MASK            (0xFFFFFF)     /* [23:0] */
#define AXIMON_NON_OV_TRANS_NUM_SHIFT           (0)            /* [23:0] */

#define AXIMON_OV_TRANS_NUM_MASK                (0xFFFFFF)     /* [23:0] */
#define AXIMON_OV_TRANS_NUM_SHIFT               (0)            /* [23:0] */

#define AXIMON_NON_WGT_TRANS_CYC_MASK           (0xFFFFFFF)    /* [27:0] */
#define AXIMON_NON_WGT_TRANS_CYC_SHIFT          (0)            /* [27:0] */

#define AXIMON_WGT_TRANS_CYC_MASK               (0xFFFFFFFF)   /* [31:0] */
#define AXIMON_WGT_TRANS_CYC_SHIFT              (0)            /* [31:0] */

#define AXIMON_MAX_TRANS_CYC_MASK               (0xFFFF)       /* [15:0] */
#define AXIMON_MAX_TRANS_CYC_SHIFT              (0)            /* [15:0] */

#define AXIMON_MAX_OST_TRANS_NUM_MASK           (0x1F)         /* [4:0] */
#define AXIMON_MAX_OST_TRANS_NUM_SHIFT          (0)            /* [4:0] */

#define AXIMON_AW_TOT_DEV_CYC_MASK              (0xFFFFFF)     /* [23:0] */
#define AXIMON_AW_TOT_DEV_CYC_SHIFT             (0)            /* [23:0] */

#define AXIMON_AW_MAX_DEV_CYC_MASK              (0xFFF)        /* [11:0] */
#define AXIMON_AW_MAX_DEV_CYC_SHIFT             (0)            /* [11:0] */

#define AXIMON_AW2W_TOT_MST_CYC_MASK            (0xFFFFFF)     /* [23:0] */
#define AXIMON_AW2W_TOT_MST_CYC_SHIFT           (0)            /* [23:0] */

#define AXIMON_AW2W_MAX_MST_CYC_MASK            (0xFFF)        /* [11:0] */
#define AXIMON_AW2W_MAX_MST_CYC_SHIFT           (0)            /* [11:0] */

#define AXIMON_AW2W_TOT_DEV_CYC_MASK            (0xFFFFFF)     /* [23:0] */
#define AXIMON_AW2W_TOT_DEV_CYC_SHIFT           (0)            /* [23:0] */

#define AXIMON_AW2W_MAX_DEV_CYC_MASK            (0xFFF)        /* [11:0] */
#define AXIMON_AW2W_MAX_DEV_CYC_SHIFT           (0)            /* [11:0] */

#define AXIMON_AW2W_MAX_WT_CYC_MASK             (0xFFFF)       /* [15:0] */
#define AXIMON_AW2W_MAX_WT_CYC_SHIFT            (0)            /* [15:0] */

#define AXIMON_W_TOT_MST_CYC_MASK               (0xFFFFFF)     /* [23:0] */
#define AXIMON_W_TOT_MST_CYC_SHIFT              (0)            /* [23:0] */

#define AXIMON_W_MAX_MST_CYC_MASK               (0xFFF)        /* [11:0] */
#define AXIMON_W_MAX_MST_CYC_SHIFT              (0)            /* [11:0] */

#define AXIMON_W_TOT_DEV_CYC_MASK               (0xFFFFFF)     /* [23:0] */
#define AXIMON_W_TOT_DEV_CYC_SHIFT              (0)            /* [23:0] */

#define AXIMON_W_MAX_DEV_CYC_MASK               (0xFFF)        /* [11:0] */
#define AXIMON_W_MAX_DEV_CYC_SHIFT              (0)            /* [11:0] */

#define AXIMON_W_TOT_DATA_CYC_MASK              (0xFFFFFFF)    /* [27:0] */
#define AXIMON_W_TOT_DATA_CYC_SHIFT             (0)            /* [27:0] */

#define AXIMON_W_TOT_DATA_CNT_MASK              (0xFFFFFFFF)   /* [31:0] */
#define AXIMON_W_TOT_DATA_CNT_SHIFT             (0)            /* [31:0] */

#define AXIMON_W2B_TOT_DEV_CYC_MASK             (0xFFFFFF)     /* [23:0] */
#define AXIMON_W2B_TOT_DEV_CYC_SHIFT            (0)            /* [23:0] */

#define AXIMON_W2B_MAX_DEV_CYC_MASK             (0xFFF)        /* [11:0] */
#define AXIMON_W2B_MAX_DEV_CYC_SHIFT            (0)            /* [11:0] */

#define AXIMON_AR_TOT_DEV_CYC_MASK              (0xFFFFFF)     /* [23:0] */
#define AXIMON_AR_TOT_DEV_CYC_SHIFT             (0)            /* [23:0] */

#define AXIMON_AR_MAX_DEV_CYC_MASK              (0xFFF)        /* [11:0] */
#define AXIMON_AR_MAX_DEV_CYC_SHIFT             (0)            /* [11:0] */

#define AXIMON_AR2R_TOT_MST_CYC_MASK            (0xFFFFFF)     /* [23:0] */
#define AXIMON_AR2R_TOT_MST_CYC_SHIFT           (0)            /* [23:0] */

#define AXIMON_AR2R_MAX_MST_CYC_MASK            (0xFFF)        /* [11:0] */
#define AXIMON_AR2R_MAX_MST_CYC_SHIFT           (0)            /* [11:0] */

#define AXIMON_AR2R_TOT_DEV_CYC_MASK            (0xFFFFFF)     /* [23:0] */
#define AXIMON_AR2R_TOT_DEV_CYC_SHIFT           (0)            /* [23:0] */

#define AXIMON_AR2R_MAX_DEV_CYC_MASK            (0xFFF)        /* [11:0] */
#define AXIMON_AR2R_MAX_DEV_CYC_SHIFT           (0)            /* [11:0] */

#define AXIMON_AR2R_MAX_WT_CYC_MASK             (0xFFFF)       /* [15:0] */
#define AXIMON_AR2R_MAX_WT_CYC_SHIFT            (0)            /* [15:0] */

#define AXIMON_R_TOT_MST_CYC_MASK               (0xFFFFFF)     /* [23:0] */
#define AXIMON_R_TOT_MST_CYC_SHIFT              (0)            /* [23:0] */

#define AXIMON_R_MAX_MST_CYC_MASK               (0xFFF)        /* [11:0] */
#define AXIMON_R_MAX_MST_CYC_SHIFT              (0)            /* [11:0] */

#define AXIMON_R_TOT_DEV_CYC_MASK               (0xFFFFFF)     /* [23:0] */
#define AXIMON_R_TOT_DEV_CYC_SHIFT              (0)            /* [23:0] */

#define AXIMON_R_MAX_DEV_CYC_MASK               (0xFFF)        /* [11:0] */
#define AXIMON_R_MAX_DEV_CYC_SHIFT              (0)            /* [11:0] */

#define AXIMON_R_TOT_DATA_CYC_MASK              (0xFFFFFFF)    /* [27:0] */
#define AXIMON_R_TOT_DATA_CYC_SHIFT             (0)            /* [27:0] */

#define AXIMON_R_TOT_DATA_CNT_MASK              (0xFFFFFFFF)   /* [31:0] */
#define AXIMON_R_TOT_DATA_CNT_SHIFT             (0)            /* [31:0] */

#define AXIMON_SNAP_INFO0_QID_MASK              (0x7F)          /* [6:0] */
#define AXIMON_SNAP_INFO0_QID_SHIFT             (0)             /* [6:0] */
#define AXIMON_SNAP_INFO0_LEN_MASK              (0xF)           /* [11:8] */
#define AXIMON_SNAP_INFO0_LEN_SHIFT             (8)             /* [11:8] */
#define AXIMON_SNAP_INFO0_SIZE_MASK             (0x7)           /* [14:12] */
#define AXIMON_SNAP_INFO0_SIZE_SHIFT            (12)            /* [14:12] */
#define AXIMON_SNAP_INFO0_HP_MASK               (0x1)           /* [15] */
#define AXIMON_SNAP_INFO0_HP_SHIFT              (15)            /* [15] */
#define AXIMON_SNAP_INFO0_BURST_MASK            (0x3)           /* [17:16] */
#define AXIMON_SNAP_INFO0_BURST_SHIFT           (16)            /* [17:16] */
#define AXIMON_SNAP_INFO0_LOCK_MASK             (0x3)           /* [19:18] */
#define AXIMON_SNAP_INFO0_LOCK_SHIFT            (18)            /* [19:18] */
#define AXIMON_SNAP_INFO0_CACHE_MASK            (0xF)           /* [23:20] */
#define AXIMON_SNAP_INFO0_CACHE_SHIFT           (20)            /* [23:20] */
#define AXIMON_SNAP_INFO0_PROT_MASK             (0x7)           /* [26:24] */
#define AXIMON_SNAP_INFO0_PROT_SHIFT            (24)            /* [26:24] */
#define AXIMON_SNAP_INFO0_RESP_MASK             (0x3)           /* [29:28] */
#define AXIMON_SNAP_INFO0_RESP_SHIFT            (28)            /* [29:28] */

#define AXIMON_SNAP_INFO1_DEV_CYC_MASK          (0xFFFF)        /* [15:0] */
#define AXIMON_SNAP_INFO1_DEV_CYC_SHIFT         (0)             /* [15:0] */

#define AXIMON_SNAP_INFO2_CNT_MASK              (0xFFFF)        /* [15:0] */
#define AXIMON_SNAP_INFO2_CNT_SHIFT             (0)             /* [15:0] */
#define AXIMON_SNAP_INFO2_STRB0_MASK            (0xFF)          /* [23:16] */
#define AXIMON_SNAP_INFO2_STRB0_SHIFT           (16)            /* [23:16] */
#define AXIMON_SNAP_INFO2_STRB1_MASK            (0xFF)          /* [31:24] */
#define AXIMON_SNAP_INFO2_STRB1_SHIFT           (24)            /* [31:24] */

#define AXIMON_SNAP_INFO3_ADDRESS_MASK          (0xFFFFFFFF)    /* [31:0] */
#define AXIMON_SNAP_INFO3_ADDRESS_SHIFT         (0)             /* [31:0] */

#define AXIMON_SNAP_INFO4_DATA0L_MASK           (0xFFFFFFFF)    /* [31:0] */
#define AXIMON_SNAP_INFO4_DATA0L_SHIFT          (0)             /* [31:0] */

#define AXIMON_SNAP_INFO5_DATA0H_MASK           (0xFFFFFFFF)    /* [31:0] */
#define AXIMON_SNAP_INFO5_DATA0H_SHIFT          (0)             /* [31:0] */

#define AXIMON_SNAP_INFO6_DATA1L_MASK           (0xFFFFFFFF)    /* [31:0] */
#define AXIMON_SNAP_INFO6_DATA1L_SHIFT          (0)             /* [31:0] */

#define AXIMON_SNAP_INFO7_DATA1H_MASK           (0xFFFFFFFF)    /* [31:0] */
#define AXIMON_SNAP_INFO7_DATA1H_SHIFT          (0)             /* [31:0] */

#define AXIMON_MATCH_NONE                       (0xFFFFFFFF)
#define AXIMON_MATCH_ALL                        (0)

/*
 * AHB Bus Monitor
 */
#define AHBMON_BASE                             (0)

#define AHBMON_CODE_VERSION                     (AHBMON_BASE + 0x00)
#define AHBMON_DMY_REG                          (AHBMON_BASE + 0x04)
#define AHBMON_INT                              (AHBMON_BASE + 0x08)
#define AHBMON_INT_MSK                          (AHBMON_BASE + 0x0C)
#define AHBMON_CTL                              (AHBMON_BASE + 0x10)
#define AHBMON_TST                              (AHBMON_BASE + 0x14)
#define AHBMON_STS                              (AHBMON_BASE + 0x18)
#define AHBMON_IP0_TG                           (AHBMON_BASE + 0x20)
#define AHBMON_IP0_CYC                          (AHBMON_BASE + 0x24)
#define AHBMON_IP0_ADDR                         (AHBMON_BASE + 0x30)
#define AHBMON_IP0_ADDRMSK                      (AHBMON_BASE + 0x34)
#define AHBMON_IP0_DATA                         (AHBMON_BASE + 0x40)
#define AHBMON_IP0_DATAMSK                      (AHBMON_BASE + 0x48)
#define AHBMON_IP1_TG                           (AHBMON_BASE + 0x60)
#define AHBMON_IP1_CYC                          (AHBMON_BASE + 0x64)
#define AHBMON_IP1_ADDR                         (AHBMON_BASE + 0x70)
#define AHBMON_IP1_ADDRMSK                      (AHBMON_BASE + 0x74)
#define AHBMON_IP1_DATA                         (AHBMON_BASE + 0x80)
#define AHBMON_IP1_DATAMSK                      (AHBMON_BASE + 0x88)
#define AHBMON_TOT_BUS_CYC                      (AHBMON_BASE + 0x100)
#define AHBMON_TOT_IDLE_CYC                     (AHBMON_BASE + 0x120)
#define AHBMON_BUS_XAC_STS                      (AHBMON_BASE + 0x124)
#define AHBMON_IP0_TRANS_NUM                    (AHBMON_BASE + 0x200)
#define AHBMON_IP0_TOT_ARB_CYC                  (AHBMON_BASE + 0x204)
#define AHBMON_IP0_MAX_ARB_CYC                  (AHBMON_BASE + 0x208)
#define AHBMON_IP0_ARB_NUM                      (AHBMON_BASE + 0x20C)
#define AHBMON_IP0_DEV_CYC                      (AHBMON_BASE + 0x210)
#define AHBMON_IP0_DATA_CYC                     (AHBMON_BASE + 0x214)
#define AHBMON_IP0_RDY_CYC                      (AHBMON_BASE + 0x218)
#define AHBMON_IP0_XAC_CYC                      (AHBMON_BASE + 0x21C)
#define AHBMON_IP0_DATA_SIZE                    (AHBMON_BASE + 0x220)
#define AHBMON_IP0_MAX_CYC_STS                  (AHBMON_BASE + 0x224)
#define AHBMON_IP0_MAX_CYC_STS1                 (AHBMON_BASE + 0x228)
#define AHBMON_IP0_SNAP_INFO0                   (AHBMON_BASE + 0x240)
#define AHBMON_IP0_SNAP_INFO1                   (AHBMON_BASE + 0x244)
#define AHBMON_IP0_SNAP_INFO2                   (AHBMON_BASE + 0x248)
#define AHBMON_IP0_SNAP_INFO3                   (AHBMON_BASE + 0x24C)
#define AHBMON_IP0_SNAP_INFO4                   (AHBMON_BASE + 0x250)
#define AHBMON_IP1_TRANS_NUM                    (AHBMON_BASE + 0x300)
#define AHBMON_IP1_TOT_ARB_CYC                  (AHBMON_BASE + 0x304)
#define AHBMON_IP1_MAX_ARB_CYC                  (AHBMON_BASE + 0x308)
#define AHBMON_IP1_ARB_NUM                      (AHBMON_BASE + 0x30C)
#define AHBMON_IP1_DEV_CYC                      (AHBMON_BASE + 0x310)
#define AHBMON_IP1_DATA_CYC                     (AHBMON_BASE + 0x314)
#define AHBMON_IP1_RDY_CYC                      (AHBMON_BASE + 0x318)
#define AHBMON_IP1_XAC_CYC                      (AHBMON_BASE + 0x31C)
#define AHBMON_IP1_DATA_SIZE                    (AHBMON_BASE + 0x320)
#define AHBMON_IP1_MAX_CYC_STS                  (AHBMON_BASE + 0x324)
#define AHBMON_IP1_MAX_CYC_STS1                 (AHBMON_BASE + 0x328)
#define AHBMON_IP1_SNAP_INFO0                   (AHBMON_BASE + 0x340)
#define AHBMON_IP1_SNAP_INFO1                   (AHBMON_BASE + 0x344)
#define AHBMON_IP1_SNAP_INFO2                   (AHBMON_BASE + 0x348)
#define AHBMON_IP1_SNAP_INFO3                   (AHBMON_BASE + 0x34C)
#define AHBMON_IP1_SNAP_INFO4                   (AHBMON_BASE + 0x350)

#define AHBMON_CFG_OFFSET                       (0x40)
#define AHBMON_INFO_OFFSET                      (0x100)
#define AHBMON_TG_ALL_MASTER                    (0xF)

/* Default Value */
#define AHBMON_CODE_VERSION_DEFAULT             (0x20120722)
#define AHBMON_TST_DEFAULT                      (0x40000)

/* Bit Field & Mask */
#define AHBMON_CODE_VERSION_MASK                (0xFFFFFFFF)    /* [31:0] */
#define AHBMON_CODE_VERSION_SHIFT               (0)             /* [31:0] */

#define AHBMON_DMY_REG_MASK                     (0xFFFFFFFF)    /* [31:0] */
#define AHBMON_DMY_REG_SHIFT                    (0)             /* [31:0] */

#define AHBMON_INT_MASK                         (0x1)           /* [0] */
#define AHBMON_INT_SHIFT                        (0)             /* [0] */

#define AHBMON_INT_MSK_MASK                     (0x1)           /* [0] */
#define AHBMON_INT_MSK_SHIFT                    (0)             /* [0] */

#define AHBMON_CTL_START_MASK                   (0x1)           /* [0] */
#define AHBMON_CTL_START_SHIFT                  (0)             /* [0] */
#define AHBMON_CTL_PAUSE_MASK                   (0x1)           /* [1] */
#define AHBMON_CTL_PAUSE_SHIFT                  (1)             /* [1] */
#define AHBMON_CTL_RESUME_MASK                  (0x1)           /* [2] */
#define AHBMON_CTL_RESUME_SHIFT                 (2)             /* [2] */

#define AHBMON_TST_SEQ_TRG_MODE_MASK            (0x1)           /* [0] */
#define AHBMON_TST_SEQ_TRG_MODE_SHIFT           (0)             /* [0] */
#define AHBMON_TST_SPEED_SIM_MASK               (0x1)           /* [8] */
#define AHBMON_TST_SPEED_SIM_SHIFT              (8)             /* [8] */
#define AHBMON_TST_LYR_AHB_SEL_MASK             (0x3)           /* [17:16] */
#define AHBMON_TST_LYR_AHB_SEL_SHIFT            (16)            /* [17:16] */

#define AHBMON_STS_STAT0_MASK                   (0x1)           /* [0] */
#define AHBMON_STS_STAT0_SHIFT                  (0)             /* [0] */
#define AHBMON_STS_STAT1_MASK                   (0x1)           /* [1] */
#define AHBMON_STS_STAT1_SHIFT                  (1)             /* [1] */

#define AHBMON_TG_MON_MASTER_MASK               (0xF)           /* [3:0] */
#define AHBMON_TG_MON_MASTER_SHIFT              (0)             /* [3:0] */
#define AHBMON_TG_MON_RWSEL_MASK                (0x3)           /* [5:4] */
#define AHBMON_TG_MON_RWSEL_SHIFT               (4)             /* [5:4] */
#define AHBMON_TG_MON_MODE_MASK                 (0x1)           /* [8] */
#define AHBMON_TG_MON_MODE_SHIFT                (8)             /* [8] */
#define AHBMON_TG_MON_ENABLE_MASK               (0x1)           /* [9] */
#define AHBMON_TG_MON_ENABLE_SHIFT              (9)             /* [9] */
#define AHBMON_TG_TRG_MODE_MASK                 (0x1)           /* [10] */
#define AHBMON_TG_TRG_MODE_SHIFT                (10)            /* [10] */
#define AHBMON_TG_CYC_TRG_SEL_MASK              (0xF)           /* [15:12] */
#define AHBMON_TG_CYC_TRG_SEL_SHIFT             (12)            /* [15:12] */
#define AHBMON_TG_MON_CNT_MASK                  (0xFFFF)        /* [31:16] */
#define AHBMON_TG_MON_CNT_SHIFT                 (16)            /* [31:16] */

#define AHBMON_CYC_TRG_CYC_MASK                 (0xFFFF)        /* [15:0] */
#define AHBMON_CYC_TRG_CYC_SHIFT                (0)             /* [15:0] */

#define AHBMON_ADDR_MASK                        (0xFFFFFFFF)    /* [31:0] */
#define AHBMON_ADDR_SHIFT                       (0)             /* [31:0] */

#define AHBMON_ADDRMSK_MASK                     (0xFFFFFFFF)    /* [31:0] */
#define AHBMON_ADDRMSK_SHIFT                    (0)             /* [31:0] */

#define AHBMON_DATA_MASK                        (0xFFFFFFFF)    /* [31:0] */
#define AHBMON_DATA_SHIFT                       (0)             /* [31:0] */

#define AHBMON_DATAMASK_MASK                    (0xFFFFFFFF)    /* [31:0] */
#define AHBMON_DATAMASK_SHIFT                   (0)             /* [31:0] */

#define AHBMON_TOT_BUS_CYC_MASK                 (0xFFFFFFFF)    /* [31:0] */
#define AHBMON_TOT_BUS_CYC_SHIFT                (0)             /* [31:0] */

#define AHBMON_TOT_IDLE_CYC_MASK                (0xFFFFFFFF)    /* [31:0] */
#define AHBMON_TOT_IDLE_CYC_SHIFT               (0)             /* [31:0] */

#define AHBMON_BUS_XAC_STS_MAX_XAC_CYC_MASK     (0xFFFF)        /* [15:0] */
#define AHBMON_BUS_XAC_STS_MAX_XAC_CYC_SHIFT    (0)             /* [15:0] */

#define AHBMON_TRANS_NUM_MASK                   (0xFFFFF)       /* [19:0] */
#define AHBMON_TRANS_NUM_SHIFT                  (0)             /* [19:0] */

#define AHBMON_TOT_ARB_CYC_MASK                 (0xFFFFFF)      /* [23:0] */
#define AHBMON_TOT_ARB_CYC_SHIFT                (0)             /* [23:0] */

#define AHBMON_MAX_ARB_CYC_MASK                 (0xFFFF)        /* [15:0] */
#define AHBMON_MAX_ARB_CYC_SHIFT                (0)             /* [15:0] */

#define AHBMON_ARB_NUM_TOT_ARB_NUM_MASK         (0xFFFFF)       /* [19:0] */
#define AHBMON_ARB_NUM_TOT_ARB_NUM_SHIFT        (0)             /* [19:0] */
#define AHBMON_ARB_NUM_MAX_ARB_NUM_MASK         (0xFF)          /* [31:24] */
#define AHBMON_ARB_NUM_MAX_ARB_NUM_SHIFT        (24)            /* [31:24] */

#define AHBMON_DEV_CYC_MASK                     (0xFFFFFF)      /* [23:0] */
#define AHBMON_DEV_CYC_SHIFT                    (0)             /* [23:0] */

#define AHBMON_DATA_CYC_MASK                    (0xFFFFFF)      /* [23:0] */
#define AHBMON_DATA_CYC_SHIFT                   (0)             /* [23:0] */

#define AHBMON_RDY_CYC_MASK                     (0xFFFFFF)      /* [23:0] */
#define AHBMON_RDY_CYC_SHIFT                    (0)             /* [23:0] */

#define AHBMON_XAC_CYC_MASK                     (0xFFFFFFF)     /* [27:0] */
#define AHBMON_XAC_CYC_SHIFT                    (0)             /* [27:0] */

#define AHBMON_DATA_SIZE_TOT_DATA_SIZE_MASK     (0xFFFFFFFF)    /* [31:0] */
#define AHBMON_DATA_SIZE_TOT_DATA_SIZE_SHIFT    (0)             /* [31:0] */

#define AHBMON_MAX_CYC_STS0_MAX_DEV_CYC_MASK    (0xFFF)         /* [11:0] */
#define AHBMON_MAX_CYC_STS0_MAX_DEV_CYC_SHIFT   (0)             /* [11:0] */
#define AHBMON_MAX_CYC_STS0_MAX_DATA_CYC_MASK   (0xFFF)         /* [27:16] */
#define AHBMON_MAX_CYC_STS0_MAX_DATA_CYC_SHIFT  (16)            /* [27:16] */

#define AHBMON_MAX_CYC_STS1_MAX_XAC_CYC_MASK    (0xFFFF)        /* [15:0] */
#define AHBMON_MAX_CYC_STS1_MAX_XAC_CYC_SHIFT   (0)             /* [15:0] */

#define AHBMON_SNAP_INFO0_REQ_MASK              (0xFFFF)        /* [15:0] */
#define AHBMON_SNAP_INFO0_REQ_SHIFT             (0)             /* [15:0] */
#define AHBMON_SNAP_INFO0_TRANS_MASK            (0x3)           /* [17:16] */
#define AHBMON_SNAP_INFO0_TRANS_SHIFT           (16)            /* [17:16] */
#define AHBMON_SNAP_INFO0_WRITE_MASK            (0x1)           /* [18] */
#define AHBMON_SNAP_INFO0_WRITE_SHIFT           (18)            /* [18] */
#define AHBMON_SNAP_INFO0_BURST_MASK            (0x7)           /* [22:20] */
#define AHBMON_SNAP_INFO0_BURST_SHIFT           (20)            /* [22:20] */
#define AHBMON_SNAP_INFO0_SIZE_MASK             (0x3)           /* [25:24] */
#define AHBMON_SNAP_INFO0_SIZE_SHIFT            (24)            /* [25:24] */
#define AHBMON_SNAP_INFO0_GNT_MASK              (0xF)           /* [31:28] */
#define AHBMON_SNAP_INFO0_GNT_SHIFT             (28)            /* [31:28] */

#define AHBMON_SNAP_INFO1_CNT_MASK              (0xFFFF)        /* [15:0] */
#define AHBMON_SNAP_INFO1_CNT_SHIFT             (0)             /* [15:0] */

#define AHBMON_SNAP_INFO2_ADDRESS_MASK          (0xFFFFFFFF)    /* [31:0] */
#define AHBMON_SNAP_INFO2_ADDRESS_SHIFT         (0)             /* [31:0] */

#define AHBMON_SNAP_INFO3_DATA0_MASK            (0xFFFFFFFF)    /* [31:0] */
#define AHBMON_SNAP_INFO3_DATA0_SHIFT           (0)             /* [31:0] */

#define AHBMON_SNAP_INFO4_DATA1_MASK            (0xFFFFFFFF)    /* [31:0] */
#define AHBMON_SNAP_INFO4_DATA1_SHIFT           (0)             /* [31:0] */

#define AHBMON_MATCH_NONE                       (0xFFFFFFFF)
#define AHBMON_MATCH_ALL                        (0)

/*
 *  MDINFRA BusMon
 */
#if defined(MT6290)
#define MDINFRA_BUSMON_BASE                     (BASE_MADDR_MDPAHBMON1)
#else //Brian: temp version to skip build alert
#define MDINFRA_BUSMON_BASE                     (0)
#endif


#define BUSMON_CODA_VERSION                     (MDINFRA_BUSMON_BASE + 0x00)
#define BUSMON_DMY_REG                          (MDINFRA_BUSMON_BASE + 0x04)
#define BUSMON_INT_EN                           (MDINFRA_BUSMON_BASE + 0x08)
#define BUSMON_INT_STS                          (MDINFRA_BUSMON_BASE + 0x0C)


/* Default Value */
#define BUSMON_CODA_VERSION_DEFAULT             (0x20120724)

/* Bit Field & Mask */
#define BUSMON_CODA_VERSION_MASK                (0xFFFFFFFF)    /* [31:0] */
#define BUSMON_CODA_VERSION_SHIFT               (0)             /* [31:0] */

#define BUSMON_DMY_REG_MASK                     (0xFFFFFFFF)    /* [31:0] */
#define BUSMON_DMY_REG_SHIFT                    (0)             /* [31:0] */

#define BUSMON_INT_EN_MASK                      (0x1FF)         /* [8:0] */
#define BUSMON_INT_EN_SHIFT                     (0)             /* [8:0] */

#define BUSMON_INT_STS_MASK                     (0x1FF)         /* [8:0] */
#define BUSMON_INT_APMCU_AXI_MASK               (0x1)           /* [0] */
#define BUSMON_INT_APMCU_AXI_SHIFT              (0)             /* [0] */
#define BUSMON_INT_APPERI_AHB_MASK              (0x1)           /* [2] */
#define BUSMON_INT_APPERI_AHB_SHIFT             (2)             /* [2] */
#define BUSMON_INT_APPERI_AXI_MASK              (0x1)           /* [3] */
#define BUSMON_INT_APPERI_AXI_SHIFT             (3)             /* [3] */
#define BUSMON_INT_MDMCU_AXI_MASK               (0x1)           /* [4] */
#define BUSMON_INT_MDMCU_AXI_SHIFT              (4)             /* [4] */
#define BUSMON_INT_MDINFRA_AXI_MASK             (0x1)           /* [6] */
#define BUSMON_INT_MDINFRA_AXI_SHIFT            (6)             /* [6] */
#define BUSMON_INT_MDINFRA_AHB0_MASK            (0x1)           /* [7] */
#define BUSMON_INT_MDINFRA_AHB0_SHIFT           (7)             /* [7] */
#define BUSMON_INT_MDINFRA_AHB1_MASK            (0x1)           /* [8] */
#define BUSMON_INT_MDINFRA_AHB1_SHIFT           (8)             /* [8] */

#define BUSMON_INT_BITS                         (9)

#endif /* end of __BUSMON_REG_H__ */

