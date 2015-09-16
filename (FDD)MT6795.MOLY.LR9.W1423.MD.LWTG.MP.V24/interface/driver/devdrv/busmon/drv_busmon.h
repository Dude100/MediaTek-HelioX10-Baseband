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
 *   drv_busmon.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Header file for Bus monitor control
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
 * bus monitor bug
 *
 * removed!
 * removed!
 * Use non-post-write to get accurate counter
 *
 * removed!
 * removed!
 *
 ****************************************************************************/

/*
 * Please note that this file will be remove in custom release!!
 * Use it for debugging only.
 *
 * Example to use bus monitor:
 *
 * #include "bus_monitor.h"
 *
 * int foo()
 * {
 *     BUSMON_LOG_T log;
 *
 *     // set target filter: read or write
 *     BUSMON_SET_MONITOR_MODE(CR4, BUSMON_RWSEL_READ);
 *
 *     // begin of bus-monitor logging
 *     BUSMON_BEGIN_LOG_ALL(CR4);
 *
 *     // SW to be measured
 *
 *     // end of bus-monitor logging
 *     BUSMON_END_LOG_ALL(CR4);
 *
 *     // retrieve log
 *     BUSMON_GET_LOG(CR4, &log);
 *
 *     // print total data
 *     printf("accnt = %d\n", log.tot_data_byte_cnt);
 * }
 *
 * int foo()
 * {
 *     // set target filter: write
 *     BUSMON_SET_TRG_MODE(CR4, BUSMON_RWSEL_WRITE, 5);
 *
 *     // Optional: set address filter: 0x69ecxx
 *     BUSMON_ADD_ADDR_FILTER(CR4, 0x69ec00, 0xff);
 *
 *     // Optional: set data filter
 *     BUSMON_ADD_DATA_FILTER(CR4, XXXX, 0);
 *
 *     // Optional: set target filter: write, transaction number, transaction cycle
 *     BUSMON_SET_SECONDARY_CYCLE_TRG_MODE(CR4, BUSMON_RWSEL_READ, 6, 1);
 *
 *     // Optional: set address filter
 *     BUSMON_ADD_SECONDARY_ADDR_FILTER(CR4, xxxx, 0);
 *
 *     // Optional: set data filter
 *     BUSMON_ADD_SECONDARY_DATA_FILTER(CR4, xxx, 0);
 *
 *     // Optional: register callback
 *     BUSMON_SET_TRG_CALLBCK(CR4, intr_cb);
 *
 *     // begin of bus-monitor logging
 *     BUSMON_BEGIN_LOG_ALL(CR4);
 *
 *     // Optional: Check PCmon usage if needed
 *     // pcm_cfg.pcm_mode = PCM_MOD2
 *
 *     // SW to be measured
 *
 *     // Check the condition triggered
 *    if (BUSMON_IS_RUNNING(CR4) == KAL_FALSE) {
 *
 *    }
 *
 * }
 *
 */

#ifndef __DRV_BUSMON_H__
#define __DRV_BUSMON_H__

#include "kal_public_defs.h"
#include "busmon_reg.h"

/*******************************************************************************
 * Define Chip-dependet settings.
 *******************************************************************************/
#if (defined(MT6290))
/*
 * Busmon base address
 */
/* MD_AXImon_1 */
#define BUSMON_BASE_ADDR_CR4              BASE_ADDR_MDMAXIMON0
#define BUSMON_BASE_ADDR_ALC              BASE_ADDR_MDMAXIMON0
#define BUSMON_BASE_ADDR_ARM7             BASE_ADDR_MDMAXIMON0

/* MD_AXImon_2 */
#define BUSMON_BASE_ADDR_SDIO3_EHPI       BASE_ADDR_MDPAXIMON0
#define BUSMON_BASE_ADDR_2GMODEMDMA       BASE_ADDR_MDPAXIMON0
#define BUSMON_BASE_ADDR_3GMODEMDMA       BASE_ADDR_MDPAXIMON0
#define BUSMON_BASE_ADDR_LTEL2DMA         BASE_ADDR_MDPAXIMON0


/* MD_AHBmon_1 */
#define BUSMON_BASE_ADDR_MDGDMA           BASE_ADDR_MDPAHBMON0

/* MD_AHBmon_2 */
#define BUSMON_BASE_ADDR_LTEL1DMA         BASE_ADDR_MDPAHBMON1


/*
 * Busmon interrupt ID
 */
#define BUSMON_IRQID                      MD_IRQID_BUSMON

/*
 * Busmon interrupt mask
 */
/* MD_AXImon_1 */
#define BUSMON_INTMASK_CR4                (1 << BUSMON_INT_MDMCU_AXI_SHIFT)
#define BUSMON_INTMASK_ALC                (1 << BUSMON_INT_MDMCU_AXI_SHIFT)
#define BUSMON_INTMASK_ARM7               (1 << BUSMON_INT_MDMCU_AXI_SHIFT)

/* MD_AXImon_2 */
#define BUSMON_INTMASK_SDIO3_EHPI         (1 << BUSMON_INT_MDINFRA_AXI_SHIFT)
#define BUSMON_INTMASK_2GMODEMDMA         (1 << BUSMON_INT_MDINFRA_AXI_SHIFT)
#define BUSMON_INTMASK_3GMODEMDMA         (1 << BUSMON_INT_MDINFRA_AXI_SHIFT)
#define BUSMON_INTMASK_LTEL2DMA           (1 << BUSMON_INT_MDINFRA_AXI_SHIFT)

/* MD_AHBmon_1 */
#define BUSMON_INTMASK_MDGDMA             (1 << BUSMON_INT_MDINFRA_AHB0_SHIFT)

/* MD_AHBmon_2 */
#define BUSMON_INTMASK_LTEL1DMA           (1 << BUSMON_INT_MDINFRA_AHB1_SHIFT)
#elif (defined(MT6595))
/*
 * Busmon base address
 */

// APB Module md_aximon
//#define MD_INFRA_BUSMON_BASE (0x801A0000)
// APB Module md_aximon
//#define MDMCU_BUSMON_BASE (0x801B0000)

/* MD_AXImon_1 */
#define BUSMON_BASE_ADDR_CR4              MDMCU_BUSMON_BASE
#define BUSMON_BASE_ADDR_ARM7             MDMCU_BUSMON_BASE
#define BUSMON_BASE_ADDR_ALC              MDMCU_BUSMON_BASE
#define BUSMON_BASE_ADDR_PFB              MDMCU_BUSMON_BASE

/* MD_AXImon_2 */
#define BUSMON_BASE_ADDR_MDPSYS           MD_INFRA_BUSMON_BASE
#define BUSMON_BASE_ADDR_MODMEMSYS        MD_INFRA_BUSMON_BASE
#define BUSMON_BASE_ADDR_TDDSYS_LTEL1DMA  MD_INFRA_BUSMON_BASE
#define BUSMON_BASE_ADDR_MODEMHARQ        MD_INFRA_BUSMON_BASE
#define BUSMON_BASE_ADDR_LTEL2DMA         MD_INFRA_BUSMON_BASE

#define BUSMON_BASE_ADDR_SDIO3_EHPI       MD_INFRA_BUSMON_BASE
#define BUSMON_BASE_ADDR_2GMODEMDMA       MD_INFRA_BUSMON_BASE
#define BUSMON_BASE_ADDR_3GMODEMDMA       MD_INFRA_BUSMON_BASE
#define BUSMON_BASE_ADDR_LTEL2DMA         MD_INFRA_BUSMON_BASE

/*
 * Busmon interrupt ID
 */
#define BUSMON_MDMCU_IRQID                MD_IRQID_MDMCU_BUSMON
#define BUSMON_MDPERI_IRQID               MD_IRQID_BUSMON

#endif
/*******************************************************************************
 * Define constants.
 *******************************************************************************/

/****************************************
 * Busmon bus id
 ****************************************/

#if (defined(MT6290))
typedef enum {
   /* MD_AXImon_1 */
   BUSMON_BUSID_CR4=0,
   BUSMON_BUSID_ALC=1,
   BUSMON_BUSID_ARM7=2,

   /* MD_AXImon_2 */
   BUSMON_BUSID_SDIO3_EHPI=0,
   BUSMON_BUSID_2GMODEMDMA=1,
   BUSMON_BUSID_3GMODEMDMA=2,
   BUSMON_BUSID_LTEL2DMA=3,

   /* MD_AHBmon_1 */
   BUSMON_BUSID_MDGDMA=0,

   /* MD_AHBmon_2 */
   BUSMON_BUSID_LTEL1DMA=0
} busmon_busid_t;

#elif (defined(MT6595))
typedef enum {
   /* MD_AXImon_1 */
   BUSMON_BUSID_CR4=1,
   BUSMON_BUSID_ARM7=2,
   BUSMON_BUSID_ALC=3,
   BUSMON_BUSID_PFB=4,

   /* MD_AXImon_2 */

   BUSMON_BUSID_MODMEMSYS=1,
   BUSMON_BUSID_MODEMHARQ=2,
   BUSMON_BUSID_MDPSYS=3,
   BUSMON_BUSID_LTEL2DMA=4,
   BUSMON_BUSID_TDDSYS_LTEL1DMA=5,



} busmon_busid_t;
#endif

/***************************************
 * Busmon bus type
 ****************************************/

#if (defined(MT6290)) 
typedef enum {
   BUSMON_BUSTYPE_AHB,
   BUSMON_BUSTYPE_AXI,

   /* MD_AXImon_1 */
   BUSMON_BUSTYPE_CR4=BUSMON_BUSTYPE_AXI,
   BUSMON_BUSTYPE_ALC=BUSMON_BUSTYPE_AXI,
   BUSMON_BUSTYPE_ARM7=BUSMON_BUSTYPE_AXI,

   /* MD_AXImon_2 */
   BUSMON_BUSTYPE_SDIO3_EHPI=BUSMON_BUSTYPE_AXI,
   BUSMON_BUSTYPE_2GMODEMDMA=BUSMON_BUSTYPE_AXI,
   BUSMON_BUSTYPE_3GMODEMDMA=BUSMON_BUSTYPE_AXI,
   BUSMON_BUSTYPE_LTEL2DMA=BUSMON_BUSTYPE_AXI,

   /* MD_AHBmon_1 */
   BUSMON_BUSTYPE_MDGDMA=BUSMON_BUSTYPE_AHB,

   /* MD_AHBmon_2 */
   BUSMON_BUSTYPE_LTEL1DMA=BUSMON_BUSTYPE_AHB,
} busmon_bus_type_t;

#elif (defined(MT6595)) 
typedef enum {
   BUSMON_BUSTYPE_AHB,
   BUSMON_BUSTYPE_AXI,

   /* MD_AXImon_1 */
   BUSMON_BUSTYPE_CR4=BUSMON_BUSTYPE_AXI,
   BUSMON_BUSTYPE_ARM7=BUSMON_BUSTYPE_AXI,
   BUSMON_BUSTYPE_ALC=BUSMON_BUSTYPE_AXI,
   BUSMON_BUSTYPE_PFB=BUSMON_BUSTYPE_AXI,

   /* MD_AXImon_2 */
   BUSMON_BUSTYPE_MDPSYS=BUSMON_BUSTYPE_AXI,
   BUSMON_BUSTYPE_MODMEMSYS=BUSMON_BUSTYPE_AXI,
   BUSMON_BUSTYPE_TDDSYS_LTEL1DMA=BUSMON_BUSTYPE_AXI,
   BUSMON_BUSTYPE_MODEMHARQ=BUSMON_BUSTYPE_AXI,
   BUSMON_BUSTYPE_LTEL2DMA=BUSMON_BUSTYPE_AXI,   
} busmon_bus_type_t;

#endif


/*
 * Busmon Read/Write Selection
 */
typedef enum {
   BUSMON_RWSEL_WRITE,
   BUSMON_RWSEL_READ,

   BUSMON_RWSEL_MAX
} busmon_rwsel_t;

/*
 * Busmon Target Monitor Mode
 */
typedef enum {
   BUSMON_TG_MON_MODE_SNAP,
   BUSMON_TG_MON_MODE_MONITOR,

   BUSMON_TG_MON_MODE_MAX
} busmon_tg_mon_mode_t;

/* Busmon Trigger Mode */
typedef enum {
   BUSMON_TRG_ADDRDATA,                 /* Address & Data Trigger */
   BUSMON_TRG_CYCLE,                    /* Cycle Trigger */

   BUSMON_TRG_MAX
} busmon_trg_mode_t;

/* Busmon internal IP */
typedef enum {
   BUSMON_IP0,
   BUSMON_IP1,

   BUSMON_IP_MAX
} busmon_ip_t;

/* AXImon Read/Write Selection */
typedef enum {
   AXIMON_RWSEL_WRITE,
   AXIMON_RWSEL_READ,

   AXIMON_RWSEL_MAX
} aximon_rwsel_t;

/*
 * Busmon target selection - master id
 * For AXI, master id is to select transaction ID
 * For AHB, master id is to select master
 */
#if (defined(MT6290)) 
typedef enum {
   BUSMON_TGSEL_READ_CR4=3,
   BUSMON_TGSEL_WRITE_CR4=1,

   BUSMON_TGSEL_READ_ALC=0,
   BUSMON_TGSEL_WRITE_ALC=0,

   BUSMON_TGSEL_READ_ARM7=0,
   BUSMON_TGSEL_WRITE_ARM7=0,

   BUSMON_TGSEL_READ_SDIO3_EHPI=0,
   BUSMON_TGSEL_WRITE_SDIO3_EHPI=0,

   BUSMON_TGSEL_READ_2GMODEMDMA=0,
   BUSMON_TGSEL_WRITE_2GMODEMDMA=0,

   BUSMON_TGSEL_READ_3GMODEMDMA=0,
   BUSMON_TGSEL_WRITE_3GMODEMDMA=0,

   BUSMON_TGSEL_READ_LTEL2DMA=0,
   BUSMON_TGSEL_WRITE_LTEL2DMA=0,

   BUSMON_TGSEL_READ_MDGDMA=0,
   BUSMON_TGSEL_WRITE_MDGDMA=0,

   BUSMON_TGSEL_READ_LTEL1DMA=0,
   BUSMON_TGSEL_WRITE_LTEL1DMA=0,
} busmon_tgsel_t;
#elif (defined(MT6595)) 
typedef enum {

   /* MD_AXImon_1 */
   //0134567
   BUSMON_TGSEL_READ_CR4=3,
   //0 or 1
   BUSMON_TGSEL_WRITE_CR4=1,

   //1'bx
   BUSMON_TGSEL_READ_ARM7=0,
   //1'bx
   BUSMON_TGSEL_WRITE_ARM7=0,
  
   //ALC no read 
   //BUSMON_TGSEL_READ_ALC=x,   
   //1'bx
   BUSMON_TGSEL_WRITE_ALC=0,

   // 1
   BUSMON_TGSEL_READ_PFB=1,
   //PFB no write
   //BUSMON_TGSEL_WRITE_PFB=x,

   /* MD_AXImon_2 */
   // r/w 3'bxxx
   BUSMON_TGSEL_READ_MODEMSYS=0,
   BUSMON_TGSEL_WRITE_MODEMSYS=0,

   // r/w 1'bx
   BUSMON_TGSEL_READ_MODEMARQ=0,
   BUSMON_TGSEL_WRITE_MODEMARQ=0,
   
   // r/w 3'bxxx   
   // MDGDMA= 0
   // CLDMA_MD= 3'bx01
   // CLDMA_AP= 3'bx11
   // ABM = 3'bx10
   BUSMON_TGSEL_READ_MDPSYS=0,
   BUSMON_TGSEL_WRITE_MDPSYS=0,

   // r/w 1'bx
   BUSMON_TGSEL_READ_LTEL2DMA=0,
   BUSMON_TGSEL_WRITE_LTEL2DMA=0,

   // r/w  0 
   BUSMON_TGSEL_READ_TDDSYS_LTEL1DMA=0,
   BUSMON_TGSEL_WRITE_TDDSYS_LTEL1DMA=0,

} busmon_tgsel_t;
#endif

/* AHBmon Read/Write Selection */
typedef enum {
   AHBMON_RWSEL_READ_WRITE,
   AHBMON_RWSEL_WRITE,
   AHBMON_RWSEL_READ,

   AHBMON_RWSEL_MAX
} ahbmon_rwsel_t;

/* AHBmon Cycle Trigger Selection */
typedef enum {
   AHBMON_CYC_TRG_SEL_TOT_ARB_CYC,
   AHBMON_CYC_TRG_SEL_MAX_ARB_CYC,
   AHBMON_CYC_TRG_SEL_TOT_ARB_NUM,
   AHBMON_CYC_TRG_SEL_MAX_ARB_NUM,
   AHBMON_CYC_TRG_SEL_TOT_DEV_CYC,
   AHBMON_CYC_TRG_SEL_MAX_DEV_CYC,
   AHBMON_CYC_TRG_SEL_TOT_DAT_CYC,
   AHBMON_CYC_TRG_SEL_MAX_DAT_CYC,
   AHBMON_CYC_TRG_SEL_TOT_TRX_CYC,
   AHBMON_CYC_TRG_SEL_MAX_TRX_CYC,
   AHBMON_CYC_TRG_SEL_TOT_TRX_NUM,
   AHBMON_CYC_TRG_SEL_TOT_RDY_CYC,
   AHBMON_CYC_TRG_SEL_TOT_DAT_SIZ,

   AHBMON_CYC_TRG_SEL_MAX
} ahbmon_cyc_trg_sel_t;

/* CR4 target id (ref CR4 TRM 9.2.1) */
typedef enum {
   BUSMON_TGID_CR4_READ_INSTR=1,
   BUSMON_TGID_CR4_NONCACHE_READ_DATA=0,
   BUSMON_TGID_CR4_CACHE_READ_DATA0=3,
   BUSMON_TGID_CR4_CACHE_READ_DATA1=4,
   BUSMON_TGID_CR4_CACHE_READ_DATA2=5,
   BUSMON_TGID_CR4_CACHE_READ_DATA3=6,
   BUSMON_TGID_CR4_CACHE_READ_DATA4=7,
   BUSMON_TGID_CR4_NONCACHE_WRITE_DATA=0,
   BUSMON_TGID_CR4_CACHE_WRITE_DATA=1,
} busmon_cr4_tg_id_t;

/*******************************************************************************
 * Define data structures.
 *******************************************************************************/
/*
 * Busmon monitor log
 */
typedef struct {
   kal_uint32 tot_bus_cyc;          /* total bus cycle */
   kal_uint32 tot_trans_cyc;        /* total transaction cycle */
   kal_uint32 tot_trans_num;        /* total transaction number */
   kal_uint32 tot_data_byte_cnt;    /* total data byte count */
   kal_uint32 max_xac_cyc;          /* max transaction cycle */

   kal_uint32 bus_util;             /* bus utilization */
   kal_uint32 avg_data_rate;        /* average data rate */
   kal_uint32 avg_xac_cyc;          /* average transaction cycle */
} BUSMON_LOG_T;


/*******************************************************************************
 * Define data structures.
 *******************************************************************************/
/* AXImon extented log */
typedef struct {
   busmon_ip_t mon_ip;
   aximon_rwsel_t rw_sel;
   busmon_tg_mon_mode_t tg_mon_mode;

   kal_uint32 tot_bus_cyc;          /* total bus cycle (32 bits) */

   kal_uint32 non_ov_trans_num;     /* non-overlap transaction number (24 bits) */
   kal_uint32 ov_trans_num;         /* overlap transactino numbe r(24 bits) */
   kal_uint32 non_wgt_trans_cyc;    /* non-weighted transaction cycle (28 bits) */
   kal_uint32 wgt_trans_cyc;        /* weighted transaction cycle (32 bits) */
   kal_uint32 max_trans_cyc;        /* max transaction cycle (16 bits) */
   kal_uint8 max_ost_trans_num;     /* max out-standing transaction number (5 bits) */

   kal_uint32 aw_tot_dev_cyc;       /* AW bus total device cycle (24 bits) */
   kal_uint16 aw_max_dev_cyc;       /* AW max device cycle (12 bits) */
   kal_uint32 aw2w_tot_mst_cyc;     /* AW bus to W bus total master cycle (24 bits) */
   kal_uint16 aw2w_max_mst_cyc;     /* AW bus to W bus max master cycle (12 bits) */
   kal_uint32 aw2w_tot_dev_cyc;     /* AW bus to W bus total device cycle (24 bits) */
   kal_uint16 aw2w_max_dev_cyc;     /* AW bus to W bus max device cycle (12 bits) */
   kal_uint16 aw2w_max_wt_cyc;      /* AW bus to W bus max waiting cycle (16 bits) */
   kal_uint32 w_tot_mst_cyc;        /* W total master cycle (24 bits) */
   kal_uint16 w_max_mst_cyc;        /* W max master cycle (12 bits) */
   kal_uint32 w_tot_dev_cyc;        /* W total device cycle (24 bits) */
   kal_uint16 w_max_dev_cyc;        /* W max device cycle (12 bits) */
   kal_uint32 w_tot_data_cyc;       /* W total data cycle (28 bits) */
   kal_uint32 w_tot_data_cnt;       /* W total data count (32 bits) */
   kal_uint32 w2b_tot_dev_cyc;      /* W bus to B bus total device cycle (24 bits) */
   kal_uint16 w2b_max_dev_cyc;      /* W bus to B max device cycle (12 bits) */

   kal_uint32 ar_tot_dev_cyc;       /* AR bus total device cycle (24 bits) */
   kal_uint16 ar_max_dev_cyc;       /* AR bus max device cycle (12 bits) */
   kal_uint32 ar2r_tot_mst_cyc;     /* AR bus to R bus total master cycle (24 bits) */
   kal_uint16 ar2r_max_mst_cyc;     /* AR bus to R bus max master cycle (12 bits) */
   kal_uint32 ar2r_tot_dev_cyc;     /* AR bus to R bus total device cycle (24 bits) */
   kal_uint16 ar2r_max_dev_cyc;     /* AR bus to R bus max device cycle (12 bits) */
   kal_uint16 ar2r_max_wt_cyc;      /* AR bus to R bus max waiting cycle (16 bits) */
   kal_uint32 r_tot_mst_cyc;        /* R bus total master cycle (24 bits) */
   kal_uint16 r_max_mst_cyc;        /* R bus max master cycle (12 bits) */
   kal_uint32 r_tot_dev_cyc;        /* R bus total device cycle (24 bits) */
   kal_uint16 r_max_dev_cyc;        /* R bus max device cycle (12 bits) */
   kal_uint32 r_tot_data_cyc;       /* R bus total data cycle (28 bits) */
   kal_uint32 r_tot_data_cnt;       /* R bus total data count (32 bits) */

   kal_uint8 qid;                   /* AXI transaction ID */
   kal_uint8 len;                   /* AXI burst length */
   kal_uint8 size;                  /* AXI burst size */
   kal_uint8 hp;                    /* MTK high priority signal */
   kal_uint8 burst;                 /* AXI burst type */
   kal_uint8 lock;                  /* AXI locked access */
   kal_uint8 cache;                 /* AXI memory type */
   kal_uint8 prot;                  /* AXI access permission */
   kal_uint8 resp;                  /* AXI response */
   kal_uint16 snap_dev_cyc;         /* device cycle (16 bits) */
   kal_uint16 snap_cnt;             /* data counter (16 bits) */
   kal_uint8 snap_strb0;            /* snap strobe0 */
   kal_uint8 snap_strb1;            /* snap strobe1 */
   kal_uint32 snap_addr;            /* snap address */
   kal_uint32 snap_data0[2];        /* snap data0 */
   kal_uint32 snap_data1[2];        /* snap data1 */
} aximon_ext_log_t;

typedef aximon_ext_log_t AXIMON_EXTLOG_T;

/* AHBmon extended log */
typedef struct {
   busmon_ip_t mon_ip;
   kal_bool is_all_master;
   busmon_tg_mon_mode_t tg_mon_mode;

   kal_uint32 tot_bus_cyc;       /* total bus cycle (32 bits) */
   kal_uint32 tot_idle_cyc;      /* total idle cycle (32 bits) */
   kal_uint32 max_xac_sts;       /* max bus transaction cycle (16 bits) */
//in MT6290,  trans_num tot_arb_cyc tot_arb_cyc tot_arb_num can only count read + write transactions
   kal_uint32 trans_num;         /* transaction number (20 bits) */
   kal_uint32 tot_arb_cyc;       /* total arbitration cycle (24 bits) */
   kal_uint32 max_arb_cyc;       /* max arbitration cycle (16 bits) */
   kal_uint32 tot_arb_num;       /* total arbitration number (20 bits) */
//--   
   kal_uint8  max_arb_num;       /* max arbitration number (8 bits) */
   kal_uint32 dev_cyc;           /* device cycle (24 bits) */
   kal_uint32 data_cyc;          /* data cycle (24 bits) */
   kal_uint32 rdy_cyc;           /* ready cycle (24 bits) */
   kal_uint32 xac_cyc;           /* transaction cycle (28 bits) */
   kal_uint32 tot_data_size;     /* data size (32 bits) */
   kal_uint16 max_dev_cyc;       /* max device cycle (12 bits) */
   kal_uint16 max_data_cyc;      /* max dataa cycle (12 bits) */
   kal_uint16 max_xac_cyc;       /* max transaction cycle (16 bits) */
   kal_uint16 snap_req;          /* AHB req (16 bits) */
   kal_uint8 snap_trans;         /* AHB trans (2 bits) */
   kal_uint8 snap_write;         /* AHB write (1 bits) */
   kal_uint8 snap_burst;         /* AHB burst (3 bits) */
   kal_uint8 snap_size;          /* AHB size (2 bits) */
   kal_uint8 snap_gnt;           /* AHB grant (4 bits) */
   kal_uint16 snap_cnt;          /* match count (16 bits) */
   kal_uint32 snap_addr;         /* snap address (32 bits) */
   kal_uint32 snap_data0;        /* snap data0 (32 bits) */
   kal_uint32 snap_data1;        /* snap data1 (32 bits) */
} ahbmon_ext_log_t;

typedef ahbmon_ext_log_t AHBMON_EXTLOG_T;


typedef void (*busmon_intr_cb)(void);
void drv_aximon_dump_cfg(kal_uint32 base_addr, busmon_ip_t mon_ip);
void drv_aximon_get_extlog(kal_uint32 base_addr, busmon_ip_t mon_ip, aximon_ext_log_t *ext_log);
void drv_busmon_set_trg_cb(busmon_intr_cb callback);
void drv_ahbmon_dump_cfg(kal_uint32 base_addr, busmon_ip_t mon_ip);
void drv_ahbmon_get_extlog(kal_uint32 base_addr, busmon_ip_t mon_ip, ahbmon_ext_log_t *ext_log);


/*******************************************************************************
 * Define macros.
 *******************************************************************************/

/* Register field manipulation macro */
#define EXTRACT_REG_FIELD_VAL(field_val, field_name) (((field_val) >> (field_name##_SHIFT)) & (field_name##_MASK))
#define EXPAND_REG_FIELD_VAL(field_val, field_name) (((field_val) & (field_name##_MASK)) << (field_name##_SHIFT))
#define CLEAR_REG_FIELD(reg_val, field_name) ((reg_val) & (~((field_name##_MASK) << (field_name##_SHIFT))))
#define SET_REG_FIELD_VAL(reg_val, field_val, field_name) (CLEAR_REG_FIELD(reg_val, field_name) | EXPAND_REG_FIELD_VAL(field_val, field_name))

#define AXIMON_DISABLE_IP(_busmon_id, _mon_ip) \
{ \
   kal_uint32 _ip_cfg_base; \
   _ip_cfg_base = BUSMON_BASE_ADDR_##_busmon_id + _mon_ip * AXIMON_CFG_OFFSET; \
   DRV_WriteReg32(_ip_cfg_base + AXIMON_IP0_TG, 0); \
}

#define AXIMON_IS_RUNNING(_busmon_id) \
   ((DRV_Reg32(BUSMON_BASE_ADDR_##_busmon_id + AXIMON_STS)) & 0x03)

#define AXIMON_BEGIN_LOG_ALL(_busmon_id) \
{ \
   drv_aximon_dump_cfg(BUSMON_BASE_ADDR_##_busmon_id, BUSMON_IP0); \
   drv_aximon_dump_cfg(BUSMON_BASE_ADDR_##_busmon_id, BUSMON_IP1); \
   DRV_WriteReg32_NPW(BUSMON_BASE_ADDR_##_busmon_id + AXIMON_CTL, 1); \
}

#define AXIMON_END_LOG_ALL(_busmon_id) \
{ \
   DRV_WriteReg32_NPW(BUSMON_BASE_ADDR_##_busmon_id + AXIMON_CTL, 2); \
}

#define AXIMON_SET_MONITOR_MODE(_busmon_id, _mon_ip, _master_id, _all_master_enable, _rw_sel) \
{ \
   kal_uint32 _val, _ip_cfg_base; \
   _val = DRV_Reg32(BUSMON_BASE_ADDR_##_busmon_id + AXIMON_TST); \
   _val = SET_REG_FIELD_VAL(_val, BUSMON_BUSID_##_busmon_id, AXIMON_TST_LYR_AXI_SEL); \
   DRV_WriteReg32(BUSMON_BASE_ADDR_##_busmon_id + AXIMON_TST, _val); \
   _ip_cfg_base = BUSMON_BASE_ADDR_##_busmon_id + _mon_ip * AXIMON_CFG_OFFSET; \
   _val = EXPAND_REG_FIELD_VAL(_master_id, AXIMON_TG_MON_MASTER) \
        | EXPAND_REG_FIELD_VAL(_all_master_enable, AXIMON_TG_MON_ALL_MST) \
        | EXPAND_REG_FIELD_VAL(_rw_sel, AXIMON_TG_MON_RWSEL) \
        | EXPAND_REG_FIELD_VAL(BUSMON_TG_MON_MODE_MONITOR, AXIMON_TG_MON_MODE) \
        | EXPAND_REG_FIELD_VAL(1, AXIMON_TG_MON_ENABLE) \
        | EXPAND_REG_FIELD_VAL(0, AXIMON_TG_TRG_MODE) \
        | EXPAND_REG_FIELD_VAL(0, AXIMON_TG_MON_CNT); \
   DRV_WriteReg32(_ip_cfg_base + AXIMON_IP0_TG, _val); \
   DRV_WriteReg32(_ip_cfg_base + AXIMON_IP0_ADDR, 0); \
   DRV_WriteReg32(_ip_cfg_base + AXIMON_IP0_ADDRMSK, 0xffffffffUL); \
   DRV_WriteReg32(_ip_cfg_base + AXIMON_IP0_DATAL, 0); \
   DRV_WriteReg32(_ip_cfg_base + AXIMON_IP0_DATAH, 0); \
   DRV_WriteReg32(_ip_cfg_base + AXIMON_IP0_DATAMSKL, 0xffffffffUL); \
   DRV_WriteReg32(_ip_cfg_base + AXIMON_IP0_DATAMSKH, 0xffffffffUL); \
}

#define AXIMON_SET_MASTER_ID(_busmon_id, _mon_ip, _master_id) \
{ \
   kal_uint32 _val, _ip_cfg_base; \
   _ip_cfg_base = BUSMON_BASE_ADDR_##_busmon_id + _mon_ip * AXIMON_CFG_OFFSET; \
   _val = DRV_Reg32(_ip_cfg_base + AXIMON_IP0_TG); \
   _val = SET_REG_FIELD_VAL(_val, _master_id, AXIMON_TG_MON_MASTER); \
   DRV_WriteReg32(_ip_cfg_base + AXIMON_IP0_TG, _val); \
}

#define AXIMON_SET_ADDR_FILTER(_busmon_id, _mon_ip, _addr, _addr_mask) \
{ \
   kal_uint32 _ip_cfg_base; \
   _ip_cfg_base = BUSMON_BASE_ADDR_##_busmon_id + _mon_ip * AXIMON_CFG_OFFSET; \
   DRV_WriteReg32(_ip_cfg_base + AXIMON_IP0_ADDR, _addr); \
   DRV_WriteReg32(_ip_cfg_base + AXIMON_IP0_ADDRMSK, _addr_mask); \
}

#define AXIMON_SET_DATA_FILTER(_busmon_id, _mon_ip, _data, _data_mask) \
{  \
   kal_uint32 _ip_cfg_base; \
   _ip_cfg_base = BUSMON_BASE_ADDR_##_busmon_id + _mon_ip * AXIMON_CFG_OFFSET; \
   DRV_WriteReg32(_ip_cfg_base + AXIMON_IP0_DATAL, _data); \
   DRV_WriteReg32(_ip_cfg_base + AXIMON_IP0_DATAH, 0); \
   DRV_WriteReg32(_ip_cfg_base + AXIMON_IP0_DATAMSKL, _data_mask); \
   DRV_WriteReg32(_ip_cfg_base + AXIMON_IP0_DATAMSKH, 0xffffffffUL); \
}

#define AXIMON_GET_LOG(_busmon_id, _mon_ip, _log) \
{ \
   kal_uint32 _val, _ip_cfg_base, _ip_info_base; \
   _ip_cfg_base = BUSMON_BASE_ADDR_##_busmon_id + _mon_ip * AXIMON_CFG_OFFSET; \
   _ip_info_base = BUSMON_BASE_ADDR_##_busmon_id + _mon_ip * AXIMON_INFO_OFFSET; \
   _val = DRV_Reg32(_ip_cfg_base + AXIMON_IP0_TG); \
   (_log)->tot_bus_cyc = DRV_Reg32(BUSMON_BASE_ADDR_##_busmon_id + AXIMON_TOT_BUS_CYC); \
   (_log)->tot_trans_cyc = DRV_Reg32(_ip_info_base + AXIMON_IP0_NON_WGT_TRANS_CYC); \
   (_log)->tot_trans_num = DRV_Reg32(_ip_info_base + AXIMON_IP0_NON_OV_TRANS_NUM); \
   _val = EXTRACT_REG_FIELD_VAL(_val, AXIMON_TG_MON_RWSEL); \
   if (_val == AXIMON_RWSEL_WRITE) { \
      (_log)->tot_data_byte_cnt = DRV_Reg32(_ip_info_base + AXIMON_IP0_W_TOT_DATA_CNT); \
   } \
   else { \
      (_log)->tot_data_byte_cnt = DRV_Reg32(_ip_info_base + AXIMON_IP0_R_TOT_DATA_CNT); \
   } \
   (_log)->max_xac_cyc = DRV_Reg32(_ip_info_base + AXIMON_IP0_MAX_TRANS_CYC); \
   if ((_log)->tot_bus_cyc) { \
      (_log)->bus_util = ((_log)->tot_trans_cyc * 100) / (_log)->tot_bus_cyc; \
      (_log)->avg_data_rate = ((_log)->tot_data_byte_cnt * 1000) / (_log)->tot_bus_cyc; \
   } \
   else { \
      (_log)->bus_util = 0; \
      (_log)->avg_data_rate = 0; \
   } \
   if ((_log)->tot_trans_num) { \
      (_log)->avg_xac_cyc = (_log)->tot_trans_cyc/ (_log)->tot_trans_num; \
   } \
   else { \
      (_log)->avg_xac_cyc = 0; \
   } \
}

#define AXIMON_GET_EXTENDED_LOG(_busmon_id, _log) \
   drv_aximon_get_extlog(BUSMON_BASE_ADDR_##_busmon_id, BUSMON_IP0, _log)

#define AXIMON_SET_SNAP_MODE(_busmon_id, _mon_ip, _master_id, _rw_sel, _trg_mode, _mon_cnt, _cycle_cnt, _addr, _addr_mask, _data, _data_mask) \
{ \
   kal_uint32 _val, _ip_cfg_base; \
   _ip_cfg_base = BUSMON_BASE_ADDR_##_busmon_id + _mon_ip * AXIMON_CFG_OFFSET; \
   _val = EXPAND_REG_FIELD_VAL(_master_id, AXIMON_TG_MON_MASTER) \
        | EXPAND_REG_FIELD_VAL(0, AXIMON_TG_MON_ALL_MST) \
        | EXPAND_REG_FIELD_VAL(_rw_sel, AXIMON_TG_MON_RWSEL) \
        | EXPAND_REG_FIELD_VAL(BUSMON_TG_MON_MODE_SNAP, AXIMON_TG_MON_MODE) \
        | EXPAND_REG_FIELD_VAL(1, AXIMON_TG_MON_ENABLE) \
        | EXPAND_REG_FIELD_VAL(_trg_mode, AXIMON_TG_TRG_MODE) \
        | EXPAND_REG_FIELD_VAL(_mon_cnt, AXIMON_TG_MON_CNT); \
   DRV_WriteReg32(_ip_cfg_base + AXIMON_IP0_TG, _val); \
   DRV_WriteReg32(_ip_cfg_base + AXIMON_IP0_TMR, _cycle_cnt); \
   DRV_WriteReg32(_ip_cfg_base + AXIMON_IP0_ADDR, _addr); \
   DRV_WriteReg32(_ip_cfg_base + AXIMON_IP0_ADDRMSK, _addr_mask); \
   DRV_WriteReg32(_ip_cfg_base + AXIMON_IP0_DATAL, _data); \
   DRV_WriteReg32(_ip_cfg_base + AXIMON_IP0_DATAH, 0); \
   DRV_WriteReg32(_ip_cfg_base + AXIMON_IP0_DATAMSKL, _data_mask); \
   DRV_WriteReg32(_ip_cfg_base + AXIMON_IP0_DATAMSKH, 0xffffffffUL); \
}

#define AXIMON_SET_TRG_MODE(_busmon_id, _master_id, _rw_sel, _trg_mode, _mon_cnt, _cycle_cnt, _addr, _addr_mask, _data, _data_mask) \
{ \
   kal_uint32 _val; \
   _val = DRV_Reg32(BUSMON_BASE_ADDR_##_busmon_id + AXIMON_TST); \
   _val = SET_REG_FIELD_VAL(_val, BUSMON_BUSID_##_busmon_id, AXIMON_TST_LYR_AXI_SEL); \
   _val = SET_REG_FIELD_VAL(_val, 0, AXIMON_TST_SEQ_TRG_MODE); \
   DRV_WriteReg32(BUSMON_BASE_ADDR_##_busmon_id + AXIMON_TST, _val); \
   AXIMON_SET_SNAP_MODE(_busmon_id, BUSMON_IP0, _master_id, _rw_sel, _trg_mode, _mon_cnt, _cycle_cnt, _addr, _addr_mask, _data, _data_mask); \
   AXIMON_DISABLE_IP(_busmon_id, BUSMON_IP1); \
}

#define AXIMON_SET_SECONDARY_TRG_MODE(_busmon_id, _master_id, _rw_sel, _trg_mode, _mon_cnt, _cycle_cnt, _addr, _addr_mask, _data, _data_mask) \
{ \
   kal_uint32 _val; \
   _val = DRV_Reg32(BUSMON_BASE_ADDR_##_busmon_id + AXIMON_TST); \
   _val = SET_REG_FIELD_VAL(_val, BUSMON_BUSID_##_busmon_id, AXIMON_TST_LYR_AXI_SEL); \
   _val = SET_REG_FIELD_VAL(_val, 1, AXIMON_TST_SEQ_TRG_MODE); \
   DRV_WriteReg32(BUSMON_BASE_ADDR_##_busmon_id + AXIMON_TST, _val); \
   AXIMON_SET_SNAP_MODE(_busmon_id, BUSMON_IP1, _master_id, _rw_sel, _trg_mode, _mon_cnt, _cycle_cnt, _addr, _addr_mask, _data, _data_mask); \
}

#define AHBMON_DISABLE_IP(_busmon_id, _mon_ip) { \
   kal_uint32 _ip_cfg_base; \
   _ip_cfg_base = BUSMON_BASE_ADDR_##_busmon_id + _mon_ip * AHBMON_CFG_OFFSET; \
   DRV_WriteReg32(_ip_cfg_base + AHBMON_IP0_TG, 0); \
};

#define AHBMON_IS_RUNNING(_busmon_id) \
   (DRV_Reg32(BUSMON_BASE_ADDR_##_busmon_id + AHBMON_STS) & 0x03)

#define AHBMON_BEGIN_LOG_ALL(_busmon_id) \
{ \
   drv_ahbmon_dump_cfg(BUSMON_BASE_ADDR_##_busmon_id, BUSMON_IP0); \
   drv_ahbmon_dump_cfg(BUSMON_BASE_ADDR_##_busmon_id, BUSMON_IP1); \
   DRV_WriteReg32_NPW(BUSMON_BASE_ADDR_##_busmon_id + AHBMON_CTL, 1); \
}

#define AHBMON_END_LOG_ALL(_busmon_id) \
{ \
   DRV_WriteReg32_NPW(BUSMON_BASE_ADDR_##_busmon_id + AHBMON_CTL, 2); \
}

#define AHBMON_SET_MONITOR_MODE(_busmon_id, _mon_ip, _master_id, _all_master_enable, _rw_sel) \
{ \
   kal_uint32 _val, _ip_cfg_base; \
   _val = DRV_Reg32(BUSMON_BASE_ADDR_##_busmon_id + AHBMON_TST); \
   _val = SET_REG_FIELD_VAL(_val, BUSMON_BUSID_##_busmon_id, AHBMON_TST_LYR_AHB_SEL); \
   DRV_WriteReg32(BUSMON_BASE_ADDR_##_busmon_id + AHBMON_TST, _val); \
   _ip_cfg_base = BUSMON_BASE_ADDR_##_busmon_id + _mon_ip * AHBMON_CFG_OFFSET; \
   if (_all_master_enable == KAL_TRUE) { \
      _val = 0xf; \
   } \
   else { \
      _val = _master_id; \
   } \
   _val = EXPAND_REG_FIELD_VAL(_val, AHBMON_TG_MON_MASTER) \
        | EXPAND_REG_FIELD_VAL(_rw_sel, AHBMON_TG_MON_RWSEL) \
        | EXPAND_REG_FIELD_VAL(BUSMON_TG_MON_MODE_MONITOR, AHBMON_TG_MON_MODE) \
        | EXPAND_REG_FIELD_VAL(1, AHBMON_TG_MON_ENABLE) \
        | EXPAND_REG_FIELD_VAL(0, AHBMON_TG_TRG_MODE) \
        | EXPAND_REG_FIELD_VAL(0, AHBMON_TG_MON_CNT); \
   DRV_WriteReg32(_ip_cfg_base + AHBMON_IP0_TG, _val); \
   DRV_WriteReg32(_ip_cfg_base + AHBMON_IP0_ADDR, 0); \
   DRV_WriteReg32(_ip_cfg_base + AHBMON_IP0_ADDRMSK, 0xffffffffUL); \
   DRV_WriteReg32(_ip_cfg_base + AHBMON_IP0_DATA, 0); \
   DRV_WriteReg32(_ip_cfg_base + AHBMON_IP0_DATAMSK, 0xffffffffUL); \
}

#define AHBMON_SET_MASTER_ID(_busmon_id, _mon_ip, _master_id) \
{ \
   kal_uint32 _val, _ip_cfg_base; \
   _ip_cfg_base = BUSMON_BASE_ADDR_##_busmon_id + _mon_ip * AHBMON_CFG_OFFSET; \
   _val = DRV_Reg32(_ip_cfg_base + AHBMON_IP0_TG); \
   _val = SET_REG_FIELD_VAL(_val, _master_id, AHBMON_TG_MON_MASTER); \
   DRV_WriteReg32(_ip_cfg_base + AHBMON_IP0_TG, _val); \
}

#define AHBMON_SET_ADDR_FILTER(_busmon_id, _mon_ip, _addr, _addr_mask) \
{ \
   kal_uint32 _ip_cfg_base; \
   _ip_cfg_base = BUSMON_BASE_ADDR_##_busmon_id + _mon_ip * AHBMON_CFG_OFFSET; \
   DRV_WriteReg32(_ip_cfg_base + AHBMON_IP0_ADDR, _addr); \
   DRV_WriteReg32(_ip_cfg_base + AHBMON_IP0_ADDRMSK, _addr_mask); \
}

#define AHBMON_SET_DATA_FILTER(_busmon_id, _mon_ip, _data, _data_mask) \
{ \
   kal_uint32 _ip_cfg_base; \
   _ip_cfg_base = BUSMON_BASE_ADDR_##_busmon_id + _mon_ip * AHBMON_CFG_OFFSET; \
   DRV_WriteReg32(_ip_cfg_base + AHBMON_IP0_DATA, _data); \
   DRV_WriteReg32(_ip_cfg_base + AHBMON_IP0_DATAMSK, _data_mask); \
}

#define AHBMON_GET_LOG(_busmon_id, _mon_ip, _log) \
{ \
   kal_uint32 _ip_info_base, _tot_idle_cyc; \
   _ip_info_base = BUSMON_BASE_ADDR_##_busmon_id + _mon_ip * AHBMON_INFO_OFFSET; \
   _tot_idle_cyc = DRV_Reg32(BUSMON_BASE_ADDR_##_busmon_id + AHBMON_TOT_IDLE_CYC); \
   (_log)->tot_bus_cyc = DRV_Reg32(BUSMON_BASE_ADDR_##_busmon_id + AHBMON_TOT_BUS_CYC); \
   (_log)->tot_trans_cyc = (_log)->tot_bus_cyc - _tot_idle_cyc; \
   (_log)->tot_trans_num = DRV_Reg32(_ip_info_base + AHBMON_IP0_TRANS_NUM); \
   (_log)->tot_data_byte_cnt = DRV_Reg32(_ip_info_base + AHBMON_IP0_DATA_SIZE); \
   (_log)->max_xac_cyc = DRV_Reg32(_ip_info_base + AHBMON_IP0_MAX_CYC_STS1); \
   if ((_log)->tot_bus_cyc) { \
      (_log)->bus_util = ((_log)->tot_trans_cyc * 100) / (_log)->tot_bus_cyc; \
      (_log)->avg_data_rate = ((_log)->tot_data_byte_cnt * 1000) / (_log)->tot_bus_cyc; \
   } \
   else { \
      (_log)->bus_util = 0; \
      (_log)->avg_data_rate = 0; \
   } \
   if ((_log)->tot_trans_num) { \
      (_log)->avg_xac_cyc = (_log)->tot_trans_cyc / (_log)->tot_trans_num; \
   } \
   else { \
      (_log)->avg_xac_cyc = 0; \
   } \
}

#define AHBMON_GET_EXTENDED_LOG(_busmon_id, _log) \
   drv_ahbmon_get_extlog(BUSMON_BASE_ADDR_##_busmon_id, BUSMON_IP0, _log)

#define AHBMON_SET_SNAP_MODE(_busmon_id, _mon_ip, _master_id, _rw_sel, _trg_mode, _cyc_trg_sel, _mon_cnt, _cycle_cnt, _addr, _addr_mask, _data, _data_mask) \
{ \
   kal_uint32 _val, _ip_cfg_base; \
   _ip_cfg_base = BUSMON_BASE_ADDR_##_busmon_id + _mon_ip * AHBMON_CFG_OFFSET; \
   _val = EXPAND_REG_FIELD_VAL(_master_id, AHBMON_TG_MON_MASTER) \
        | EXPAND_REG_FIELD_VAL(_rw_sel, AHBMON_TG_MON_RWSEL) \
        | EXPAND_REG_FIELD_VAL(BUSMON_TG_MON_MODE_SNAP, AHBMON_TG_MON_MODE) \
        | EXPAND_REG_FIELD_VAL(1, AHBMON_TG_MON_ENABLE) \
        | EXPAND_REG_FIELD_VAL(_trg_mode, AHBMON_TG_TRG_MODE) \
        | EXPAND_REG_FIELD_VAL(_cyc_trg_sel, AHBMON_TG_CYC_TRG_SEL) \
        | EXPAND_REG_FIELD_VAL(_mon_cnt, AHBMON_TG_MON_CNT); \
   DRV_WriteReg32(_ip_cfg_base + AHBMON_IP0_TG, _val); \
   DRV_WriteReg32(_ip_cfg_base + AHBMON_IP0_CYC, _cycle_cnt); \
   DRV_WriteReg32(_ip_cfg_base + AHBMON_IP0_ADDR, _addr); \
   DRV_WriteReg32(_ip_cfg_base + AHBMON_IP0_ADDRMSK, _addr_mask); \
   DRV_WriteReg32(_ip_cfg_base + AHBMON_IP0_DATA, _data); \
   DRV_WriteReg32(_ip_cfg_base + AHBMON_IP0_DATAMSK, _data_mask); \
};

#define AHBMON_SET_TRG_MODE(_busmon_id, _master_id, _rw_sel, _trg_mode, _cyc_trg_sel, _mon_cnt, _cycle_cnt, _addr, _addr_mask, _data, _data_mask) \
{ \
   kal_uint32 _val; \
   AHBMON_SET_SNAP_MODE(_busmon_id, BUSMON_IP0, _master_id, _rw_sel, _trg_mode, _cyc_trg_sel, _mon_cnt, _cycle_cnt, _addr, _addr_mask, _data, _data_mask); \
   _val = DRV_Reg32(BUSMON_BASE_ADDR_##_busmon_id + AHBMON_TST); \
   _val = SET_REG_FIELD_VAL(_val, BUSMON_BUSID_##_busmon_id, AHBMON_TST_LYR_AHB_SEL); \
   _val = SET_REG_FIELD_VAL(_val, 0, AHBMON_TST_SEQ_TRG_MODE); \
   DRV_WriteReg32(BUSMON_BASE_ADDR_##_busmon_id + AHBMON_TST, _val); \
   AHBMON_DISABLE_IP(_busmon_id, BUSMON_IP1); \
};

#define AHBMON_SET_SECONDARY_TRG_MODE(_busmon_id, _master_id, _rw_sel, _trg_mode, _cyc_trg_sel, _mon_cnt, _cycle_cnt, _addr, _addr_mask, _data, _data_mask) \
{ \
   kal_uint32 _val; \
   _val = DRV_Reg32(BUSMON_BASE_ADDR_##_busmon_id + AHBMON_TST); \
   _val = SET_REG_FIELD_VAL(_val, BUSMON_BUSID_##_busmon_id, AHBMON_TST_LYR_AHB_SEL); \
   _val = SET_REG_FIELD_VAL(_val, 1, AHBMON_TST_SEQ_TRG_MODE); \
   DRV_WriteReg32(BUSMON_BASE_ADDR_##_busmon_id + AHBMON_TST, _val); \
   AHBMON_SET_SNAP_MODE(_busmon_id, BUSMON_IP1, _master_id, _rw_sel, _trg_mode, _cyc_trg_sel, _mon_cnt, _cycle_cnt, _addr, _addr_mask, _data, _data_mask); \
};

#define BUSMON_SET_MONITOR_MODE(_busmon_id, _rw_sel) \
{ \
   if (BUSMON_BUSTYPE_##_busmon_id == BUSMON_BUSTYPE_AXI) { \
      AXIMON_END_LOG_ALL(_busmon_id); \
      if (_rw_sel == BUSMON_RWSEL_READ) { \
         AXIMON_SET_MONITOR_MODE(_busmon_id, BUSMON_IP0, BUSMON_TGSEL_READ_##_busmon_id, KAL_FALSE, AXIMON_RWSEL_READ); \
      } \
      else { \
         AXIMON_SET_MONITOR_MODE(_busmon_id, BUSMON_IP0, BUSMON_TGSEL_WRITE_##_busmon_id, KAL_FALSE, AXIMON_RWSEL_WRITE); \
      } \
      AXIMON_DISABLE_IP(_busmon_id, BUSMON_IP1); \
   } \
   else { \
      AHBMON_END_LOG_ALL(_busmon_id); \
      if (_rw_sel == BUSMON_RWSEL_READ) { \
         AHBMON_SET_MONITOR_MODE(_busmon_id, BUSMON_IP0, BUSMON_TGSEL_READ_##_busmon_id, KAL_FALSE, AHBMON_RWSEL_READ); \
      } \
      else { \
         AHBMON_SET_MONITOR_MODE(_busmon_id, BUSMON_IP0, BUSMON_TGSEL_WRITE_##_busmon_id, KAL_FALSE, AHBMON_RWSEL_WRITE); \
      } \
      AHBMON_DISABLE_IP(_busmon_id, BUSMON_IP1); \
   } \
}

#define BUSMON_SET_MASTER_ID(_busmon_id, _master_id) \
{ \
   if (BUSMON_BUSTYPE_##_busmon_id == BUSMON_BUSTYPE_AXI) { \
      AXIMON_SET_MASTER_ID(_busmon_id, BUSMON_IP0, _master_id); \
   } \
   else { \
      AHBMON_SET_MASTER_ID(_busmon_id, BUSMON_IP0, _master_id); \
   } \
}

#define BUSMON_ADD_ADDR_FILTER(_busmon_id, _addr, _addr_mask) \
{ \
   if (BUSMON_BUSTYPE_##_busmon_id == BUSMON_BUSTYPE_AXI) { \
      AXIMON_SET_ADDR_FILTER(_busmon_id, BUSMON_IP0, _addr, _addr_mask); \
   } \
   else { \
      AHBMON_SET_ADDR_FILTER(_busmon_id, BUSMON_IP0, _addr, _addr_mask); \
   } \
}

#define BUSMON_ADD_DATA_FILTER(_busmon_id, _data, _data_mask) \
{ \
   if (BUSMON_BUSTYPE_##_busmon_id == BUSMON_BUSTYPE_AXI) { \
      AXIMON_SET_DATA_FILTER(_busmon_id, BUSMON_IP0, _data, _data_mask); \
   } \
   else { \
      AHBMON_SET_DATA_FILTER(_busmon_id, BUSMON_IP0, _data, _data_mask); \
   } \
}

#define BUSMON_BEGIN_LOG_ALL(_busmon_id) \
{ \
   if (BUSMON_BUSTYPE_##_busmon_id == BUSMON_BUSTYPE_AXI) { \
      AXIMON_BEGIN_LOG_ALL(_busmon_id); \
   } \
   else { \
      AHBMON_BEGIN_LOG_ALL(_busmon_id); \
   } \
}

#define BUSMON_END_LOG_ALL(_busmon_id) \
{ \
   if (BUSMON_BUSTYPE_##_busmon_id == BUSMON_BUSTYPE_AXI) { \
      AXIMON_END_LOG_ALL(_busmon_id); \
   } \
   else { \
      AHBMON_END_LOG_ALL(_busmon_id); \
   } \
}

#define BUSMON_GET_LOG(_busmon_id, _log) \
{ \
   if (BUSMON_BUSTYPE_##_busmon_id == BUSMON_BUSTYPE_AXI) { \
      AXIMON_GET_LOG(_busmon_id, BUSMON_IP0, _log); \
   } \
   else { \
      AHBMON_GET_LOG(_busmon_id, BUSMON_IP0, _log); \
   } \
}

#define BUSMON_SET_TRG_MODE(_busmon_id, _rw_sel, _mon_cnt) \
{ \
   if (BUSMON_BUSTYPE_##_busmon_id == BUSMON_BUSTYPE_AXI) { \
      AXIMON_END_LOG_ALL(_busmon_id); \
      if (_rw_sel == BUSMON_RWSEL_READ) { \
         AXIMON_SET_TRG_MODE(_busmon_id, BUSMON_TGSEL_READ_##_busmon_id, AXIMON_RWSEL_READ, BUSMON_TRG_ADDRDATA, _mon_cnt, 0, 0, 0xffffffffUL, 0, 0xffffffffUL); \
       } \
      else { \
         AXIMON_SET_TRG_MODE(_busmon_id, BUSMON_TGSEL_WRITE_##_busmon_id, AXIMON_RWSEL_WRITE, BUSMON_TRG_ADDRDATA, _mon_cnt, 0, 0, 0xffffffffUL, 0, 0xffffffffUL); \
      } \
   } \
   else { \
      AHBMON_END_LOG_ALL(_busmon_id); \
      if (_rw_sel == BUSMON_RWSEL_READ) { \
         AHBMON_SET_TRG_MODE(_busmon_id, BUSMON_TGSEL_READ_##_busmon_id, AHBMON_RWSEL_READ, BUSMON_TRG_ADDRDATA, 0, _mon_cnt, 0, 0, 0xffffffffUL, 0, 0xffffffffUL); \
      } \
      else { \
         AHBMON_SET_TRG_MODE(_busmon_id, BUSMON_TGSEL_WRITE_##_busmon_id, AHBMON_RWSEL_WRITE, BUSMON_TRG_ADDRDATA, 0, _mon_cnt, 0, 0, 0xffffffffUL, 0, 0xffffffffUL); \
      } \
   } \
}

#define BUSMON_SET_CYCLE_TRG_MODE(_busmon_id, _rw_sel, _mon_cnt, _cycle_cnt) \
{ \
   if (BUSMON_BUSTYPE_##_busmon_id == BUSMON_BUSTYPE_AXI) { \
      AXIMON_END_LOG_ALL(_busmon_id); \
      if (_rw_sel == BUSMON_RWSEL_READ) { \
         AXIMON_SET_TRG_MODE(_busmon_id, BUSMON_TGSEL_READ_##_busmon_id, AXIMON_RWSEL_READ, BUSMON_TRG_CYCLE, _mon_cnt, _cycle_cnt, 0, 0xffffffffUL, 0, 0xffffffffUL); \
      } \
      else { \
         AXIMON_SET_TRG_MODE(_busmon_id, BUSMON_TGSEL_WRITE_##_busmon_id, AXIMON_RWSEL_WRITE, BUSMON_TRG_CYCLE, _mon_cnt, _cycle_cnt, 0, 0xffffffffUL, 0, 0xffffffffUL); \
      } \
   } \
   else { \
      AHBMON_END_LOG_ALL(_busmon_id); \
      if (_rw_sel == BUSMON_RWSEL_READ) { \
         AHBMON_SET_TRG_MODE(_busmon_id, BUSMON_TGSEL_READ_##_busmon_id, AHBMON_RWSEL_READ, BUSMON_TRG_CYCLE, AHBMON_CYC_TRG_SEL_MAX_TRX_CYC, _mon_cnt, _cycle_cnt, 0, 0xffffffffUL, 0, 0xffffffffUL); \
      } \
      else { \
         AHBMON_SET_TRG_MODE(_busmon_id, BUSMON_TGSEL_WRITE_##_busmon_id, AHBMON_RWSEL_WRITE, BUSMON_TRG_CYCLE, AHBMON_CYC_TRG_SEL_MAX_TRX_CYC, _mon_cnt, _cycle_cnt, 0, 0xffffffffUL, 0, 0xffffffffUL); \
      } \
   } \
}

#define BUSMON_SET_SECONDARY_TRG_MODE(_busmon_id, _rw_sel, _mon_cnt) \
{ \
   if (BUSMON_BUSTYPE_##_busmon_id == BUSMON_BUSTYPE_AXI) { \
      if (_rw_sel == BUSMON_RWSEL_READ) { \
         AXIMON_SET_SECONDARY_TRG_MODE(_busmon_id, BUSMON_TGSEL_READ_##_busmon_id, AXIMON_RWSEL_READ, BUSMON_TRG_ADDRDATA, _mon_cnt, 1, 0, 0xffffffffUL, 0, 0xffffffffUL); \
      } \
      else { \
         AXIMON_SET_SECONDARY_TRG_MODE(_busmon_id, BUSMON_TGSEL_WRITE_##_busmon_id, AXIMON_RWSEL_WRITE, BUSMON_TRG_ADDRDATA, _mon_cnt, 1, 0, 0xffffffffUL, 0, 0xffffffffUL); \
      } \
   } \
   else { \
      if (_rw_sel == BUSMON_RWSEL_READ) { \
         AHBMON_SET_SECONDARY_TRG_MODE(_busmon_id, BUSMON_TGSEL_READ_##_busmon_id, AHBMON_RWSEL_READ, BUSMON_TRG_ADDRDATA, 0, _mon_cnt, 1, 0, 0xffffffffUL, 0, 0xffffffffUL); \
      } \
      else { \
         AHBMON_SET_SECONDARY_TRG_MODE(_busmon_id, BUSMON_TGSEL_WRITE_##_busmon_id, AHBMON_RWSEL_WRITE, BUSMON_TRG_ADDRDATA, 0, _mon_cnt, 1, 0, 0xffffffffUL, 0, 0xffffffffUL); \
      } \
   } \
}

#define BUSMON_SET_SECONDARY_MASTER_ID(_busmon_id, _master_id) \
{ \
   if (BUSMON_BUSTYPE_##_busmon_id == BUSMON_BUSTYPE_AXI) { \
      AXIMON_SET_MASTER_ID(_busmon_id, BUSMON_IP1, _master_id); \
   } \
   else { \
      AHBMON_SET_MASTER_ID(_busmon_id, BUSMON_IP1, _master_id); \
   } \
}

#define BUSMON_SET_SECONDARY_CYCLE_TRG_MODE(_busmon_id, _rw_sel, _mon_cnt, _cycle_cnt) \
{ \
   if (BUSMON_BUSTYPE_##_busmon_id == BUSMON_BUSTYPE_AXI) { \
      if (_rw_sel == BUSMON_RWSEL_READ) { \
         AXIMON_SET_SECONDARY_TRG_MODE(_busmon_id, BUSMON_TGSEL_READ_##_busmon_id, AXIMON_RWSEL_READ, BUSMON_TRG_CYCLE, _mon_cnt, _cycle_cnt, 0, 0xffffffffUL, 0, 0xffffffffUL); \
      } \
      else { \
         AXIMON_SET_SECONDARY_TRG_MODE(_busmon_id, BUSMON_TGSEL_WRITE_##_busmon_id, AXIMON_RWSEL_WRITE, BUSMON_TRG_CYCLE, _mon_cnt, _cycle_cnt, 0, 0xffffffffUL, 0, 0xffffffffUL); \
      } \
   } \
   else { \
      if (_rw_sel == BUSMON_RWSEL_READ) { \
         AHBMON_SET_SECONDARY_TRG_MODE(_busmon_id, BUSMON_TGSEL_READ_##_busmon_id, AHBMON_RWSEL_READ, BUSMON_TRG_CYCLE, AHBMON_CYC_TRG_SEL_MAX_TRX_CYC, _mon_cnt, _cycle_cnt, 0, 0xffffffffUL, 0, 0xffffffffUL); \
      } \
      else { \
         AHBMON_SET_SECONDARY_TRG_MODE(_busmon_id, BUSMON_TGSEL_WRITE_##_busmon_id, AHBMON_RWSEL_WRITE, BUSMON_TRG_CYCLE, AHBMON_CYC_TRG_SEL_MAX_TRX_CYC, _mon_cnt, _cycle_cnt, 0, 0xffffffffUL, 0, 0xffffffffUL); \
      } \
   } \
}

#define BUSMON_ADD_SECONDARY_ADDR_FILTER(_busmon_id, _addr, _addr_mask) \
{ \
   if (BUSMON_BUSTYPE_##_busmon_id == BUSMON_BUSTYPE_AXI) { \
      AXIMON_SET_ADDR_FILTER(_busmon_id, BUSMON_IP1, _addr, _addr_mask); \
   } \
   else { \
      AHBMON_SET_ADDR_FILTER(_busmon_id, BUSMON_IP1, _addr, _addr_mask); \
   } \
}

#define BUSMON_ADD_SECONDARY_DATA_FILTER(_busmon_id, _data, _data_mask) \
{ \
   if (BUSMON_BUSTYPE_##_busmon_id == BUSMON_BUSTYPE_AXI) { \
      AXIMON_SET_DATA_FILTER(_busmon_id, BUSMON_IP1, _data, _data_mask); \
   } \
   else { \
      AHBMON_SET_DATA_FILTER(_busmon_id, BUSMON_IP1, _data, _data_mask); \
   } \
}

#if(defined(MT6290))
#define BUSMON_SET_TRG_CALLBCK(_busmon_id, _callback) { \
   DRV_WriteReg32(BUSMON_INT_EN, BUSMON_INTMASK_##_busmon_id); \
   drv_busmon_set_trg_cb(_callback); \
}
#elif(defined(MT6595))
#define BUSMON_SET_MDMCU_TRG_CALLBCK(_busmon_id, _callback) { \
   drv_mdmcu_busmon_set_trg_cb(_callback); \
}
#define BUSMON_SET_MDPERI_TRG_CALLBCK(_busmon_id, _callback) { \
   drv_mdperi_busmon_set_trg_cb(_callback); \
}
#endif

#define BUSMON_IS_RUNNING(_busmon_id) \
((BUSMON_BUSTYPE_##_busmon_id == BUSMON_BUSTYPE_AXI) ? \
  AXIMON_IS_RUNNING(_busmon_id) : \
  AHBMON_IS_RUNNING(_busmon_id) \
)


#endif /* end of __DRV_BUSMON_H__ */

