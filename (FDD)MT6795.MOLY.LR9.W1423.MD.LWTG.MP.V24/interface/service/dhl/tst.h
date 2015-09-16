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
 *   tst.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   TST legacy interface
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * 06 06 2014 ken.liu
 * removed!
 * sync from K2 pre-bringup dev branch.
 *
 * 11 15 2013 ken.liu
 * removed!
 * add filter on/off control for META tool.
 *
 * 07 25 2013 ken.liu
 * removed!
 * check-in dhl mux filter support (disabled by default until next ELT release)
 *
 * 11 07 2012 ken.liu
 * removed!
 * dhl module check-in.
 ****************************************************************************/

#ifndef _TST_H
#define _TST_H

/********************/
/* Constant definition */
/********************/
#if defined(__LTE_RAT__) || defined(__UMTS_RAT__)
#define TST_L1TRC_FILTER_NUM 50
#else
#define TST_L1TRC_FILTER_NUM 40
#endif  //TST_L1TRC_FILTER_NUM definition

//For world phone projects, we need to have common nvram lid size for both td and fd
//So, we define the maximal number for both of them

//Willie: We need to consider about NVRAM checksum size (2 byte)
#define NVRAM_CHECKSUM_SIZE (2)
#define NVRAM_PEER_BUF_HEADER_SIZE (8)
#if defined(__LTE_RAT__) || defined(__UMTS_RAT__) || defined(__GSM_RAT__)
#define NVRAM_EF_TST_FILTER_ALLOCATE_SIZE  (4096-NVRAM_CHECKSUM_SIZE-NVRAM_PEER_BUF_HEADER_SIZE)
#define NVRAM_EF_DHL_FILTER_ALLOCATE_SIZE  (4096-NVRAM_CHECKSUM_SIZE-NVRAM_PEER_BUF_HEADER_SIZE)
#else
#define NVRAM_EF_TST_FILTER_ALLOCATE_SIZE  (2048-NVRAM_CHECKSUM_SIZE)
#define NVRAM_EF_DHL_FILTER_ALLOCATE_SIZE  (2048-NVRAM_CHECKSUM_SIZE)
#endif

extern void tst_init_filters(char *src, unsigned short len);
extern void tst_save_filter_to_nvram(void);

typedef struct
{
  kal_bool spare_logging_enabled;
  kal_bool usb_dma_logging_enable;
  kal_bool malmo_disable;
  kal_bool dnt_enable;    //only effective if __TST_LMU_LOGGING__ is not defined
  kal_uint8 meta_mode_trace_enable; //0: disable, 1: relay, 2: save to file
}
tst_config_struct_t;

#endif /* _TST_H */

