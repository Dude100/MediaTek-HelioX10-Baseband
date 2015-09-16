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
 *   drv_busmon.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Bus monitor control
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
 * 6595 busmon driver porting
 *
 * removed!
 * removed!
 * 6595 busmon deriver porting
 *
 * removed!
 * removed!
 *
 ****************************************************************************/

#include <string.h>
#include "kal_public_api.h"
#include "drv_comm.h"
#include "irqid.h"
#include "intrCtrl.h"
#include "drv_hisr.h"
#include "drv_rstctl.h"
#include "drv_busmon.h"

/* Debug control */
//#define BUSMON_DEBUG

#ifdef BUSMON_DEBUG
typedef enum {
   BUSMON_MSG_VERBOSE,
   BUSMON_MSG_INFO,
   BUSMON_MSG_ERROR
} busmon_msg_level_t;

#define BUSMON_MSG_FLT     BUSMON_MSG_VERBOSE /* BUSMON_MSG_INFO */

#define BUSMON_MSG(level, ftm, var ...) \
do { \
   if (level >= BUSMON_MSG_FLT) { \
      dbg_print(ftm, ##var); \
   } \
} while (0);

#else
#define BUSMON_MSG(level, string_to_be_printed...)
#endif

#if (defined(MT6290)) 

static busmon_intr_cb busmon_int_cb;

void drv_busmon_lisr(kal_uint32 v)
{
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "[%s] irqid=0x%x\r\n", __FUNCTION__, v);

   ASSERT(BUSMON_IRQID == v);
   IRQMask(BUSMON_IRQID);
   drv_active_hisr(DRV_BUSMON_HISR_ID);
}

void drv_busmon_hisr(void)
{
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "[%s] int_sts=0x%x\r\n", __FUNCTION__, DRV_Reg32(BUSMON_INT_STS));

   if (busmon_int_cb)
      (*busmon_int_cb)();

   /* Clear interrupt status */
   DRV_WriteReg32(BUSMON_INT_STS, 0);

   IRQClearInt(BUSMON_IRQID);

   /* No interrupt expected to come */
   //IRQUnmask(BUSMON_IRQID);

   /* Reset callback function */
   busmon_int_cb = NULL;
}

void drv_busmon_set_trg_cb(busmon_intr_cb callback)
{
   busmon_int_cb = callback;

   /* Clear interrupt status */
   DRV_WriteReg32(BUSMON_INT_STS, 0);

   IRQ_Register_LISR(BUSMON_IRQID, drv_busmon_lisr, "BUSMONCB");
   DRV_Register_HISR(DRV_BUSMON_HISR_ID, drv_busmon_hisr);

   IRQSensitivity(BUSMON_IRQID, KAL_TRUE);
   IRQClearInt(BUSMON_IRQID);
   IRQUnmask(BUSMON_IRQID);
}

#elif (defined(MT6595)) 
static busmon_intr_cb mdmcu_busmon_int_cb;
static busmon_intr_cb mdperi_busmon_int_cb;

void drv_mdmcu_busmon_lisr(kal_uint32 v)
{
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "[%s] irqid=0x%x\r\n", __FUNCTION__, v);

   ASSERT(BUSMON_MDMCU_IRQID == v);
   IRQMask(BUSMON_MDMCU_IRQID);
   drv_active_hisr(DRV_BUSMON2_HISR_ID);
}

void drv_mdmcu_busmon_hisr(void)
{
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "[%s] int_sts=0x%x\r\n", __FUNCTION__, DRV_Reg32(MDMCU_BUSMON_BASE + AXIMON_STS));

   if (mdmcu_busmon_int_cb)
      (*mdmcu_busmon_int_cb)();

   /* Clear interrupt status */
   DRV_WriteReg32(MDMCU_BUSMON_BASE + AXIMON_INT, 0);

   IRQClearInt(BUSMON_MDMCU_IRQID);

   /* No interrupt expected to come */
   //IRQUnmask(BUSMON_IRQID);

   /* Reset callback function */
   mdmcu_busmon_int_cb = NULL;
}

void drv_mdmcu_busmon_set_trg_cb(busmon_intr_cb callback)
{
   mdmcu_busmon_int_cb = callback;

   /* Clear interrupt status */
   DRV_WriteReg32(MDMCU_BUSMON_BASE + AXIMON_INT, 0);

   IRQ_Register_LISR(BUSMON_MDMCU_IRQID, drv_mdmcu_busmon_lisr, "MCUBUSMONCB");
   DRV_Register_HISR(DRV_BUSMON2_HISR_ID, drv_mdmcu_busmon_hisr);

   IRQSensitivity(BUSMON_MDMCU_IRQID, KAL_TRUE);
   IRQClearInt(BUSMON_MDMCU_IRQID);
   IRQUnmask(BUSMON_MDMCU_IRQID);
}


void drv_mdperi_busmon_lisr(kal_uint32 v)
{
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "[%s] irqid=0x%x\r\n", __FUNCTION__, v);

   ASSERT(BUSMON_MDPERI_IRQID == v);
   IRQMask(BUSMON_MDPERI_IRQID);
   drv_active_hisr(DRV_BUSMON1_HISR_ID);
}

void drv_mdperi_busmon_hisr(void)
{
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "[%s] int_sts=0x%x\r\n", __FUNCTION__, DRV_Reg32(BUSMON_INT_STS));

   if (mdperi_busmon_int_cb)
      (*mdperi_busmon_int_cb)();

   /* Clear interrupt status */
   DRV_WriteReg32(MD_INFRA_BUSMON_BASE + AXIMON_INT, 0);

   IRQClearInt(BUSMON_MDPERI_IRQID);

   /* No interrupt expected to come */
   //IRQUnmask(BUSMON_IRQID);

   /* Reset callback function */
   mdperi_busmon_int_cb = NULL;
}

void drv_mdperi_busmon_set_trg_cb(busmon_intr_cb callback)
{
   mdperi_busmon_int_cb = callback;

   /* Clear interrupt status */
   DRV_WriteReg32(MD_INFRA_BUSMON_BASE + AXIMON_INT, 0);
   

   IRQ_Register_LISR(BUSMON_MDPERI_IRQID, drv_mdperi_busmon_lisr, "PERIBUSMONCB");
   DRV_Register_HISR(DRV_BUSMON2_HISR_ID, drv_mdperi_busmon_hisr);

   IRQSensitivity(BUSMON_MDPERI_IRQID, KAL_TRUE);
   IRQClearInt(BUSMON_MDPERI_IRQID);
   IRQUnmask(BUSMON_MDPERI_IRQID);
}

#endif

void drv_aximon_dump_cfg(kal_uint32 base_addr, busmon_ip_t mon_ip)
{
#ifdef BUSMON_DEBUG
   kal_uint32 val, tmp, ip_cfg_base;

   ip_cfg_base = base_addr + mon_ip * AXIMON_CFG_OFFSET;

   BUSMON_MSG(BUSMON_MSG_VERBOSE, "[%s] addr=0x%x\r\n", __FUNCTION__, base_addr);

   val = DRV_Reg32(base_addr + AXIMON_TST);
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AXIMON_TST=%x\r\n", val);

   tmp = EXTRACT_REG_FIELD_VAL(val, AXIMON_TST_SEQ_TRG_MODE);
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "        SEQ_TRG=%d\r\n", tmp);

   tmp = EXTRACT_REG_FIELD_VAL(val, AXIMON_TST_LYR_AXI_SEL);
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "        LYR_SEL=%d\r\n", tmp);

   tmp = EXTRACT_REG_FIELD_VAL(val, AXIMON_TST_CTL_ACTIVE);
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "        CTL_ACTIVE=%d\r\n", tmp);

   val = DRV_Reg32(ip_cfg_base + AXIMON_IP0_TG);
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AXIMON_IP%d_TG=%x\r\n", mon_ip, val);

   tmp = EXTRACT_REG_FIELD_VAL(val, AXIMON_TG_MON_MASTER);
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "        MASTER=%d\r\n", tmp);

   tmp = EXTRACT_REG_FIELD_VAL(val, AXIMON_TG_MON_ALL_MST);
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "        ALL_MST=%d\r\n", tmp);

   tmp = EXTRACT_REG_FIELD_VAL(val, AXIMON_TG_MON_RWSEL);
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "        RWSEL=%d\r\n", tmp);

   tmp = EXTRACT_REG_FIELD_VAL(val, AXIMON_TG_MON_MODE);
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "        MODE=%d\r\n", tmp);

   tmp = EXTRACT_REG_FIELD_VAL(val, AXIMON_TG_MON_ENABLE);
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "        ENABLE=%d\r\n", tmp);

   tmp = EXTRACT_REG_FIELD_VAL(val, AXIMON_TG_TRG_MODE);
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "        TRG=%d\r\n", tmp);

   tmp = EXTRACT_REG_FIELD_VAL(val, AXIMON_TG_MON_CNT);
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "        CNT=%d\r\n", tmp);

   val = DRV_Reg32(ip_cfg_base +  AXIMON_IP0_ADDR);
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AXIMON_IP%d_ADDR=%x\r\n", mon_ip, val);

   val = DRV_Reg32(ip_cfg_base +  AXIMON_IP0_ADDRMSK);
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AXIMON_IP%d_ADDRMSK=%x\r\n", mon_ip, val);

   val = DRV_Reg32(ip_cfg_base +  AXIMON_IP0_DATAL);
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AXIMON_IP%d_DATAL=%x\r\n", mon_ip, val);

   val = DRV_Reg32(ip_cfg_base +  AXIMON_IP0_DATAH);
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AXIMON_IP%d_DATAH=%x\r\n", mon_ip, val);

   val = DRV_Reg32(ip_cfg_base +  AXIMON_IP0_DATAMSKL);
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AXIMON_IP%d_DATAMSKL=%x\r\n", mon_ip, val);

   val = DRV_Reg32(ip_cfg_base + AXIMON_IP0_DATAMSKH);
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AXIMON_IP%d_DATAMSKH=%x\r\n", mon_ip, val);
#endif /* BUSMON_DEBUG */
}

void drv_aximon_dump_extlog(aximon_ext_log_t *ext_log)
{
#ifdef BUSMON_DEBUG
   busmon_ip_t mon_ip = ext_log->mon_ip;

   BUSMON_MSG(BUSMON_MSG_VERBOSE, "[%s]\r\n", __FUNCTION__);
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AXIMON_TOT_BUS_CYC=0x%x\r\n", ext_log->tot_bus_cyc);

   BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AXIMON_IP%d_NON_OV_TRANS_NUM=0x%x\r\n", mon_ip, ext_log->non_ov_trans_num);
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AXIMON_IP%d_OV_TRANS_NUM=0x%x\r\n", mon_ip, ext_log->ov_trans_num);
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AXIMON_IP%d_NON_WGT_TRANS_CYC=0x%x\r\n", mon_ip, ext_log->non_wgt_trans_cyc);
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AXIMON_IP%d_WGT_TRANS_CYC=0x%x\r\n", mon_ip, ext_log->wgt_trans_cyc);
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AXIMON_IP%d_MAX_TRANS_CYC=0x%x\r\n", mon_ip, ext_log->max_trans_cyc);
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AXIMON_IP%d_MAX_OST_TRANS_NUM=0x%x\r\n", mon_ip, ext_log->max_ost_trans_num);

   if (ext_log->rw_sel == AXIMON_RWSEL_WRITE) {
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AXIMON_IP%d_AW_TOT_DEV_CYC=0x%x\r\n", mon_ip, ext_log->aw_tot_dev_cyc);
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AXIMON_IP%d_AW_MAX_DEV_CYC=0x%x\r\n", mon_ip, ext_log->aw_max_dev_cyc);
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AXIMON_IP%d_AW2W_TOT_MST_CYC=0x%x\r\n", mon_ip, ext_log->aw2w_tot_mst_cyc);
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AXIMON_IP%d_AW2W_MAX_MST_CYC=0x%x\r\n", mon_ip, ext_log->aw2w_max_mst_cyc);
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AXIMON_IP%d_AW2W_TOT_DEV_CYC=0x%x\r\n", mon_ip, ext_log->aw2w_tot_dev_cyc);
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AXIMON_IP%d_AW2W_MAX_DEV_CYC=0x%x\r\n", mon_ip, ext_log->aw2w_max_dev_cyc);
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AXIMON_IP%d_AW2W_MAX_WT_CYC=0x%x\r\n", mon_ip, ext_log->aw2w_max_wt_cyc);
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AXIMON_IP%d_W_TOT_MST_CYC=0x%x\r\n", mon_ip, ext_log->w_tot_mst_cyc);
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AXIMON_IP%d_W_MAX_MST_CYC=0x%x\r\n", mon_ip, ext_log->w_max_mst_cyc);
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AXIMON_IP%d_W_TOT_DEV_CYC=0x%x\r\n", mon_ip, ext_log->w_tot_dev_cyc);
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AXIMON_IP%d_W_MAX_DEV_CYC=0x%x\r\n", mon_ip, ext_log->w_max_dev_cyc);
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AXIMON_IP%d_W_TOT_DATA_CYC=0x%x\r\n", mon_ip, ext_log->w_tot_data_cyc);
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AXIMON_IP%d_W_TOT_DATA_CNT=0x%x\r\n", mon_ip, ext_log->w_tot_data_cnt);
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AXIMON_IP%d_W2B_TOT_DEV_CYC=0x%x\r\n", mon_ip, ext_log->w2b_tot_dev_cyc);
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AXIMON_IP%d_W2B_MAX_DEV_CYC=0x%x\r\n", mon_ip, ext_log->w2b_max_dev_cyc);
   }
   else {
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AXIMON_IP%d_AR_TOT_DEV_CYC=0x%x\r\n", mon_ip, ext_log->ar_tot_dev_cyc);
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AXIMON_IP%d_AR_MAX_DEV_CYC=0x%x\r\n", mon_ip, ext_log->ar_max_dev_cyc);
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AXIMON_IP%d_AR2R_TOT_MST_CYC=0x%x\r\n", mon_ip, ext_log->ar2r_tot_mst_cyc);
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AXIMON_IP%d_AR2R_MAX_MST_CYC=0x%x\r\n", mon_ip, ext_log->ar2r_max_mst_cyc);
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AXIMON_IP%d_AR2R_TOT_DEV_CYC=0x%x\r\n", mon_ip, ext_log->ar2r_tot_dev_cyc);
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AXIMON_IP%d_AR2R_MAX_DEV_CYC=0x%x\r\n", mon_ip, ext_log->ar2r_max_dev_cyc);
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AXIMON_IP%d_AR2R_MAX_WT_CYC=0x%x\r\n", mon_ip, ext_log->ar2r_max_wt_cyc);
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AXIMON_IP%d_R_TOT_MST_CYC=0x%x\r\n", mon_ip, ext_log->r_tot_mst_cyc);
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AXIMON_IP%d_R_MAX_MST_CYC=0x%x\r\n", mon_ip, ext_log->r_max_mst_cyc);
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AXIMON_IP%d_R_TOT_DEV_CYC=0x%x\r\n", mon_ip, ext_log->r_tot_dev_cyc);
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AXIMON_IP%d_R_MAX_DEV_CYC=0x%x\r\n", mon_ip, ext_log->r_max_dev_cyc);
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AXIMON_IP%d_R_TOT_DATA_CYC=0x%x\r\n", mon_ip, ext_log->r_tot_data_cyc);
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AXIMON_IP%d_R_TOT_DATA_CNT=0x%x\r\n", mon_ip, ext_log->r_tot_data_cnt);
   }

   if (ext_log->tg_mon_mode == BUSMON_TG_MON_MODE_SNAP) {
      /* Info0 */
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "        QID=%d\r\n", ext_log->qid);
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "        LEN=%d\r\n", ext_log->len);
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "        SIZE=%d\r\n", ext_log->size);
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "        HP=%d\r\n", ext_log->hp);
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "        BURST=%d\r\n", ext_log->burst);
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "        LOCK=%d\r\n", ext_log->lock);
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "        CACHE=0x%x\r\n", ext_log->cache);
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "        PROT=%d\r\n", ext_log->prot);
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "        RESP=%d\r\n", ext_log->resp);

      /* Info1 */
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "        DEV_CYC=0x%x\r\n", ext_log->snap_dev_cyc);

      /* Info2 */
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "        CNT=0x%x\r\n", ext_log->snap_cnt);
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "        STRB0=0x%x\r\n", ext_log->snap_strb0);
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "        STRB1=0x%x\r\n", ext_log->snap_strb1);

      /* Info3 */
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "        ADDR=0x%x\r\n", ext_log->snap_addr);

      /* Info4 */
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "        DATA0L=0x%x\r\n", ext_log->snap_data0[0]);

      /* Info5 */
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "        DATA0H=0x%x\r\n", ext_log->snap_data0[1]);

      /* Info6 */
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "        DATA1L=0x%x\r\n", ext_log->snap_data1[0]);

      /* Info7 */
      BUSMON_MSG(BUSMON_MSG_VERBOSE, "        DATA1H=0x%x\r\n", ext_log->snap_data1[1]);
   }
#endif /* BUSMON_DEBUG */
}

void drv_aximon_get_extlog(kal_uint32 base_addr, busmon_ip_t mon_ip, aximon_ext_log_t *ext_log)
{
   kal_uint32 val, ip_cfg_base, ip_info_base;
   aximon_rwsel_t rw_sel;
   busmon_tg_mon_mode_t tg_mon_mode;

   memset(ext_log, 0, sizeof(aximon_ext_log_t));

   ip_cfg_base = base_addr + mon_ip * AXIMON_CFG_OFFSET;
   ip_info_base = base_addr + mon_ip * AXIMON_INFO_OFFSET;

   val = DRV_Reg32(ip_cfg_base + AXIMON_IP0_TG);
   rw_sel = EXTRACT_REG_FIELD_VAL(val, AXIMON_TG_MON_RWSEL);
   tg_mon_mode = EXTRACT_REG_FIELD_VAL(val, AXIMON_TG_MON_MODE);

   ext_log->mon_ip = mon_ip;
   ext_log->rw_sel = rw_sel;
   ext_log->tg_mon_mode = tg_mon_mode;

   ext_log->tot_bus_cyc = DRV_Reg32(base_addr + AXIMON_TOT_BUS_CYC);

   ext_log->non_ov_trans_num = DRV_Reg32(ip_info_base + AXIMON_IP0_NON_OV_TRANS_NUM);
   ext_log->ov_trans_num = DRV_Reg32(ip_info_base + AXIMON_IP0_OV_TRANS_NUM);
   ext_log->non_wgt_trans_cyc = DRV_Reg32(ip_info_base + AXIMON_IP0_NON_WGT_TRANS_CYC);
   ext_log->wgt_trans_cyc = DRV_Reg32(ip_info_base + AXIMON_IP0_WGT_TRANS_CYC);
   ext_log->max_trans_cyc = DRV_Reg32(ip_info_base + AXIMON_IP0_MAX_TRANS_CYC);
   ext_log->max_ost_trans_num = DRV_Reg32(ip_info_base + AXIMON_IP0_MAX_OST_TRANS_NUM);

   if (rw_sel == AXIMON_RWSEL_WRITE) {
      /* Write */
      ext_log->aw_tot_dev_cyc = DRV_Reg32(ip_info_base + AXIMON_IP0_AW_TOT_DEV_CYC);
      ext_log->aw_max_dev_cyc = DRV_Reg32(ip_info_base + AXIMON_IP0_AW_MAX_DEV_CYC);
      ext_log->aw2w_tot_mst_cyc = DRV_Reg32(ip_info_base + AXIMON_IP0_AW2W_TOT_MST_CYC);
      ext_log->aw2w_max_mst_cyc = DRV_Reg32(ip_info_base + AXIMON_IP0_AW2W_MAX_MST_CYC);
      ext_log->aw2w_tot_dev_cyc = DRV_Reg32(ip_info_base + AXIMON_IP0_AW2W_TOT_DEV_CYC);
      ext_log->aw2w_max_dev_cyc = DRV_Reg32(ip_info_base + AXIMON_IP0_AW2W_MAX_DEV_CYC);
      ext_log->aw2w_max_wt_cyc = DRV_Reg32(ip_info_base + AXIMON_IP0_AW2W_MAX_WT_CYC);
      ext_log->w_tot_mst_cyc = DRV_Reg32(ip_info_base + AXIMON_IP0_W_TOT_MST_CYC);
      ext_log->w_max_mst_cyc = DRV_Reg32(ip_info_base + AXIMON_IP0_W_MAX_MST_CYC);
      ext_log->w_tot_dev_cyc = DRV_Reg32(ip_info_base + AXIMON_IP0_W_TOT_DEV_CYC);
      ext_log->w_max_dev_cyc = DRV_Reg32(ip_info_base + AXIMON_IP0_W_MAX_DEV_CYC);
      ext_log->w_tot_data_cyc = DRV_Reg32(ip_info_base + AXIMON_IP0_W_TOT_DATA_CYC);
      ext_log->w_tot_data_cnt = DRV_Reg32(ip_info_base + AXIMON_IP0_W_TOT_DATA_CNT);
      ext_log->w2b_tot_dev_cyc = DRV_Reg32(ip_info_base + AXIMON_IP0_W2B_TOT_DEV_CYC);
      ext_log->w2b_max_dev_cyc = DRV_Reg32(ip_info_base + AXIMON_IP0_W2B_MAX_DEV_CYC);
   }
   else {
      /* Read */
      ext_log->ar_tot_dev_cyc = DRV_Reg32(ip_info_base + AXIMON_IP0_AR_TOT_DEV_CYC);
      ext_log->ar_max_dev_cyc = DRV_Reg32(ip_info_base + AXIMON_IP0_AR_MAX_DEV_CYC);
      ext_log->ar2r_tot_mst_cyc = DRV_Reg32(ip_info_base + AXIMON_IP0_AR2R_TOT_MST_CYC);
      ext_log->ar2r_max_mst_cyc = DRV_Reg32(ip_info_base + AXIMON_IP0_AR2R_MAX_MST_CYC);
      ext_log->ar2r_tot_dev_cyc = DRV_Reg32(ip_info_base + AXIMON_IP0_AR2R_TOT_DEV_CYC);
      ext_log->ar2r_max_dev_cyc = DRV_Reg32(ip_info_base + AXIMON_IP0_AR2R_MAX_DEV_CYC);
      ext_log->ar2r_max_wt_cyc = DRV_Reg32(ip_info_base + AXIMON_IP0_AR2R_MAX_WT_CYC);
      ext_log->r_tot_mst_cyc = DRV_Reg32(ip_info_base + AXIMON_IP0_R_TOT_MST_CYC);
      ext_log->r_max_mst_cyc = DRV_Reg32(ip_info_base + AXIMON_IP0_R_MAX_MST_CYC);
      ext_log->r_tot_dev_cyc = DRV_Reg32(ip_info_base + AXIMON_IP0_R_TOT_DEV_CYC);
      ext_log->r_max_dev_cyc = DRV_Reg32(ip_info_base + AXIMON_IP0_R_MAX_DEV_CYC);
      ext_log->r_tot_data_cyc = DRV_Reg32(ip_info_base + AXIMON_IP0_R_TOT_DATA_CYC);
      ext_log->r_tot_data_cnt = DRV_Reg32(ip_info_base + AXIMON_IP0_R_TOT_DATA_CNT);
   }

   if (tg_mon_mode == BUSMON_TG_MON_MODE_SNAP) {
      /* Snapshot/Trigger */
      /* Info 0 */
      val = DRV_Reg32(ip_info_base + AXIMON_IP0_SNAP_INFO0);
      ext_log->qid = EXTRACT_REG_FIELD_VAL(val, AXIMON_SNAP_INFO0_QID);
      ext_log->len = EXTRACT_REG_FIELD_VAL(val, AXIMON_SNAP_INFO0_LEN);
      ext_log->size = EXTRACT_REG_FIELD_VAL(val, AXIMON_SNAP_INFO0_SIZE);
      ext_log->hp = EXTRACT_REG_FIELD_VAL(val, AXIMON_SNAP_INFO0_HP);
      ext_log->burst = EXTRACT_REG_FIELD_VAL(val, AXIMON_SNAP_INFO0_BURST);
      ext_log->lock = EXTRACT_REG_FIELD_VAL(val, AXIMON_SNAP_INFO0_LOCK);
      ext_log->cache = EXTRACT_REG_FIELD_VAL(val, AXIMON_SNAP_INFO0_CACHE);
      ext_log->prot = EXTRACT_REG_FIELD_VAL(val, AXIMON_SNAP_INFO0_PROT);
      ext_log->resp = EXTRACT_REG_FIELD_VAL(val, AXIMON_SNAP_INFO0_RESP);

      /* Info 1 */
      ext_log->snap_dev_cyc = DRV_Reg32(ip_info_base + AXIMON_IP0_SNAP_INFO1);

      /* Info 2 */
      val = DRV_Reg32(ip_info_base + AXIMON_IP0_SNAP_INFO2);
      ext_log->snap_cnt = EXTRACT_REG_FIELD_VAL(val, AXIMON_SNAP_INFO2_CNT);
      ext_log->snap_strb0 = EXTRACT_REG_FIELD_VAL(val, AXIMON_SNAP_INFO2_STRB0);
      ext_log->snap_strb1 = EXTRACT_REG_FIELD_VAL(val, AXIMON_SNAP_INFO2_STRB1);

      /* Info 3 */
      ext_log->snap_addr = DRV_Reg32(ip_info_base + AXIMON_IP0_SNAP_INFO3);

      /* Info 4 */
      ext_log->snap_data0[0] = DRV_Reg32(ip_info_base + AXIMON_IP0_SNAP_INFO4);

      /* Info 5 */
      ext_log->snap_data0[1] = DRV_Reg32(ip_info_base + AXIMON_IP0_SNAP_INFO5);

      /* Info 6 */
      ext_log->snap_data1[0] = DRV_Reg32(ip_info_base + AXIMON_IP0_SNAP_INFO6);

      /* Info 7 */
      ext_log->snap_data1[1] = DRV_Reg32(ip_info_base + AXIMON_IP0_SNAP_INFO7);
   }

   drv_aximon_dump_extlog(ext_log);
}


void drv_ahbmon_dump_cfg(kal_uint32 base_addr, busmon_ip_t mon_ip)
{
#ifdef BUSMON_DEBUG
   kal_uint32 val, tmp, ip_cfg_base;

   ip_cfg_base = base_addr + mon_ip * AHBMON_CFG_OFFSET;

   BUSMON_MSG(BUSMON_MSG_VERBOSE, "[%s] addr=0x%x\r\n", __FUNCTION__, base_addr);

   val = DRV_Reg32(base_addr + AHBMON_TST);
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_TST=0x%x\r\n", val);

   val = DRV_Reg32(ip_cfg_base + AHBMON_IP0_TG);
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_TG=0x%x\r\n", mon_ip, val);

   tmp = EXTRACT_REG_FIELD_VAL(val, AHBMON_TG_MON_MASTER);
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "    MASTER=%d\r\n", tmp);

   tmp = EXTRACT_REG_FIELD_VAL(val, AHBMON_TG_MON_RWSEL);
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "    RWSEL=%d\r\n", tmp);

   tmp = EXTRACT_REG_FIELD_VAL(val, AHBMON_TG_MON_MODE);
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "    MODE=%d\r\n", tmp);

   tmp = EXTRACT_REG_FIELD_VAL(val, AHBMON_TG_MON_ENABLE);
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "    ENABLE=%d\r\n", tmp);

   tmp = EXTRACT_REG_FIELD_VAL(val, AHBMON_TG_TRG_MODE);
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "    TRG=%d\r\n", tmp);

   tmp = EXTRACT_REG_FIELD_VAL(val, AHBMON_TG_CYC_TRG_SEL);
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "    SEL=%d\r\n", tmp);

   tmp = EXTRACT_REG_FIELD_VAL(val, AHBMON_TG_MON_CNT);
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "    CNT=%d\r\n", tmp);

   val = DRV_Reg32(ip_cfg_base + AHBMON_IP0_CYC);
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_CYC=0x%x\r\n", mon_ip, val);

   val = DRV_Reg32(ip_cfg_base + AHBMON_IP0_ADDR);
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_ADDR=0x%x\r\n", mon_ip, val);

   val = DRV_Reg32(ip_cfg_base + AHBMON_IP0_ADDRMSK);
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_ADDRMSK=0x%x\r\n", mon_ip, val);

   val = DRV_Reg32(ip_cfg_base + AHBMON_IP0_DATA);
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_DATA=0x%x\r\n", mon_ip, val);

   val = DRV_Reg32(ip_cfg_base + AHBMON_IP0_DATAMSK);
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_DATAMSK=0x%x\r\n", mon_ip, val);
#endif /* BUSMON_DEBUG */
}

void drv_ahbmon_dump_extlog(ahbmon_ext_log_t *ext_log)
{
#ifdef BUSMON_DEBUG
   busmon_ip_t mon_ip = ext_log->mon_ip;
   busmon_tg_mon_mode_t tg_mon_mode = ext_log->tg_mon_mode;

   BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_TOT_BUS_CYC=0x%x\r\n", ext_log->tot_bus_cyc);
   BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_TOT_IDLE_CYC=0x%x\r\n", ext_log->tot_idle_cyc);

   if (tg_mon_mode == BUSMON_TG_MON_MODE_MONITOR) {
      /* Monitor */
      if (ext_log->is_all_master) {
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_DEV_CYC=0x%x\r\n", mon_ip, ext_log->dev_cyc);
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_DATA_CYC=0x%x\r\n", mon_ip, ext_log->data_cyc);
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_RDY_CYC=0x%x\r\n", mon_ip, ext_log->rdy_cyc);
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_TOT_DATA_SIZE=0x%x\r\n", mon_ip, ext_log->tot_data_size);
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_MAX_DEV_CYC=0x%x\r\n", mon_ip, ext_log->max_dev_cyc);
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_MAX_DATA_CYC=0x%x\r\n", mon_ip, ext_log->max_data_cyc);
      }
      else {
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_TRANS_NUM=0x%x\r\n", mon_ip, ext_log->trans_num);
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_TOT_ARB_CYC=0x%x\r\n", mon_ip, ext_log->tot_arb_cyc);
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_MAX_ARB_CYC=0x%x\r\n", mon_ip, ext_log->max_arb_cyc);
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_TOT_ARB_NUM=0x%x\r\n", mon_ip, ext_log->tot_arb_num);
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_MAX_ARB_NUM=0x%x\r\n", mon_ip, ext_log->max_arb_num);
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_DEV_CYC=0x%x\r\n", mon_ip, ext_log->dev_cyc);
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_DATA_CYC=0x%x\r\n", mon_ip, ext_log->data_cyc);
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_RDY_CYC=0x%x\r\n", mon_ip, ext_log->rdy_cyc);
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_XAC_CYC=0x%x\r\n", mon_ip, ext_log->xac_cyc);
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_TOT_DATA_SIZE=0x%x\r\n", mon_ip, ext_log->tot_data_size);
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_MAX_DEV_CYC=0x%x\r\n", mon_ip, ext_log->max_dev_cyc);
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_MAX_DATA_CYC=0x%x\r\n", mon_ip, ext_log->max_data_cyc);
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_MAX_XAC_CYC=0x%x\r\n", mon_ip, ext_log->max_xac_cyc);
      }
   }
   else {
      /* Trigger */
      if (ext_log->is_all_master) {
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_DEV_CYC=0x%x\r\n", mon_ip, ext_log->dev_cyc);
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_DATA_CYC=0x%x\r\n", mon_ip, ext_log->data_cyc);
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_REQ=%d\r\n", mon_ip, ext_log->snap_req);
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_TRANS=%d\r\n", mon_ip, ext_log->snap_trans);
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_WRITE=%d\r\n", mon_ip, ext_log->snap_write);
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_BURST=%d\r\n", mon_ip, ext_log->snap_burst);
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_SIZE=%d\r\n", mon_ip, ext_log->snap_size);
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_GNT=%d\r\n", mon_ip, ext_log->snap_gnt);
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_CNT=0x%x\r\n", mon_ip, ext_log->snap_cnt);
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_ADDR=0x%x\r\n", mon_ip, ext_log->snap_addr);
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_DATA0=0x%x\r\n", mon_ip, ext_log->snap_data0);
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_DATA1=0x%x\r\n", mon_ip, ext_log->snap_data1);
      }
      else {
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_DEV_CYC=0x%x\r\n", mon_ip, ext_log->dev_cyc);
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_DATA_CYC=0x%x\r\n", mon_ip, ext_log->data_cyc);
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_RDY_CYC=0x%x\r\n", mon_ip, ext_log->rdy_cyc);
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_XAC_CYC=0x%x\r\n", mon_ip, ext_log->xac_cyc);
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_TOT_DATA_SIZE=0x%x\r\n", mon_ip, ext_log->tot_data_size);
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_REQ=%d\r\n", mon_ip, ext_log->snap_req);
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_TRANS=%d\r\n", mon_ip, ext_log->snap_trans);
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_WRITE=%d\r\n", mon_ip, ext_log->snap_write);
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_BURST=%d\r\n", mon_ip, ext_log->snap_burst);
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_SIZE=%d\r\n", mon_ip, ext_log->snap_size);
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_GNT=%d\r\n", mon_ip, ext_log->snap_gnt);
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_CNT=0x%x\r\n", mon_ip, ext_log->snap_cnt);
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_ADDR=0x%x\r\n", mon_ip, ext_log->snap_addr);
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_DATA0=0x%x\r\n", mon_ip, ext_log->snap_data0);
         BUSMON_MSG(BUSMON_MSG_VERBOSE, "    AHBMON_IP%d_DATA1=0x%x\r\n", mon_ip, ext_log->snap_data1);
      }
   }
#endif /* BUSMON_DEBUG */
}


void drv_ahbmon_get_extlog(kal_uint32 base_addr, busmon_ip_t mon_ip, ahbmon_ext_log_t *ext_log)
{
   kal_uint32 val, ip_cfg_base, ip_info_base;
   kal_bool is_all_master;
   busmon_tg_mon_mode_t tg_mon_mode;

   memset(ext_log, 0, sizeof(ahbmon_ext_log_t));

   ip_cfg_base = base_addr + mon_ip * AHBMON_CFG_OFFSET;
   ip_info_base = base_addr + mon_ip * AHBMON_INFO_OFFSET;

   val = DRV_Reg32(ip_cfg_base + AHBMON_IP0_TG);
   tg_mon_mode = EXTRACT_REG_FIELD_VAL(val, AHBMON_TG_MON_MODE);
   is_all_master = (EXTRACT_REG_FIELD_VAL(val, AHBMON_TG_MON_MASTER) == 0xf) ? KAL_TRUE : KAL_FALSE;

   ext_log->mon_ip = mon_ip;
   ext_log->is_all_master = is_all_master;
   ext_log->tg_mon_mode = tg_mon_mode;

   /* Total */
   ext_log->tot_bus_cyc = DRV_Reg32(base_addr + AHBMON_TOT_BUS_CYC);
   ext_log->tot_idle_cyc = DRV_Reg32(base_addr + AHBMON_TOT_IDLE_CYC);
   ext_log->max_xac_sts = DRV_Reg32(base_addr + AHBMON_BUS_XAC_STS);

   /* IP */
   ext_log->trans_num = DRV_Reg32(ip_info_base + AHBMON_IP0_TRANS_NUM);
   ext_log->tot_arb_cyc = DRV_Reg32(ip_info_base + AHBMON_IP0_TOT_ARB_CYC);
   ext_log->max_arb_cyc = DRV_Reg32(ip_info_base + AHBMON_IP0_MAX_ARB_CYC);

   val = DRV_Reg32(ip_info_base + AHBMON_IP0_ARB_NUM);
   ext_log->tot_arb_num = EXTRACT_REG_FIELD_VAL(val, AHBMON_ARB_NUM_TOT_ARB_NUM);
   ext_log->max_arb_num = EXTRACT_REG_FIELD_VAL(val, AHBMON_ARB_NUM_MAX_ARB_NUM);

   ext_log->dev_cyc = DRV_Reg32(ip_info_base + AHBMON_IP0_DEV_CYC);
   ext_log->data_cyc = DRV_Reg32(ip_info_base + AHBMON_IP0_DATA_CYC);
   ext_log->rdy_cyc = DRV_Reg32(ip_info_base + AHBMON_IP0_RDY_CYC);
   ext_log->xac_cyc = DRV_Reg32(ip_info_base + AHBMON_IP0_XAC_CYC);
   ext_log->tot_data_size = DRV_Reg32(ip_info_base + AHBMON_IP0_DATA_SIZE);

   val = DRV_Reg32(ip_info_base + AHBMON_IP0_MAX_CYC_STS);
   ext_log->max_dev_cyc = EXTRACT_REG_FIELD_VAL(val, AHBMON_MAX_CYC_STS0_MAX_DEV_CYC);
   ext_log->max_data_cyc = EXTRACT_REG_FIELD_VAL(val, AHBMON_MAX_CYC_STS0_MAX_DATA_CYC);

   ext_log->max_xac_cyc = DRV_Reg32(ip_info_base + AHBMON_IP0_MAX_CYC_STS1);

   if (tg_mon_mode == BUSMON_TG_MON_MODE_SNAP) {
      /* Info 0 */
      val = DRV_Reg32(ip_info_base + AHBMON_IP0_SNAP_INFO0);
      ext_log->snap_req = EXTRACT_REG_FIELD_VAL(val, AHBMON_SNAP_INFO0_REQ);
      ext_log->snap_trans = EXTRACT_REG_FIELD_VAL(val, AHBMON_SNAP_INFO0_TRANS);
      ext_log->snap_write = EXTRACT_REG_FIELD_VAL(val, AHBMON_SNAP_INFO0_WRITE);
      ext_log->snap_burst = EXTRACT_REG_FIELD_VAL(val, AHBMON_SNAP_INFO0_BURST);
      ext_log->snap_size = EXTRACT_REG_FIELD_VAL(val, AHBMON_SNAP_INFO0_SIZE);
      ext_log->snap_gnt = EXTRACT_REG_FIELD_VAL(val, AHBMON_SNAP_INFO0_GNT);

      /* Info 1 */
      ext_log->snap_cnt = DRV_Reg32(ip_info_base + AHBMON_IP0_SNAP_INFO1);

      /* Info 2 */
      ext_log->snap_addr = DRV_Reg32(ip_info_base + AHBMON_IP0_SNAP_INFO2);

      /* Info 3 */
      ext_log->snap_data0 = DRV_Reg32(ip_info_base + AHBMON_IP0_SNAP_INFO3);

      /* Info 4 */
      ext_log->snap_data1 = DRV_Reg32(ip_info_base + AHBMON_IP0_SNAP_INFO4);
   }

   drv_ahbmon_dump_extlog(ext_log);
}

