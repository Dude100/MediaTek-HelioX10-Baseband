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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   md_pccif_int.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   This Module defines PCCIF internal definition.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __MD_PCCIF_INT_H__
#define __MD_PCCIF_INT_H__

#include "cc_irq_public.h"
#include "md_pccif_hw.h"

#if defined(__CC_IRQ_UT__)
#undef  CC_IRQ_MD1MD2_NUMBER
#define CC_IRQ_MD1MD2_NUMBER    PCCIF_IRQ_NUMBER
#undef  CC_IRQ_MD2MD1_NUMBER
#define CC_IRQ_MD2MD1_NUMBER    PCCIF_IRQ_NUMBER
#endif

/* pick larger region as common region number */
#if CC_IRQ_MD1MD2_NUMBER >= CC_IRQ_MD2MD1_NUMBER
#define PCCIF_BUFF_NUMBER    CC_IRQ_MD1MD2_NUMBER
#else
#define PCCIF_BUFF_NUMBER    CC_IRQ_MD2MD1_NUMBER
#endif

/* avoid region number not power of 2 for ease of region allocation */
#if (PCCIF_BUFF_NUMBER == 3)
#error "Region number is not power of 2. Adujst it as power of 2"
#endif

#if (PCCIF_BUFF_NUMBER > PCCIF_IRQ_NUMBER)
#error "PCCIF IRQ number is less than application requirement!!"
#endif

#define PCCIF_VERSION        0x20140723
#define PCCIF_BUFFER_SIZE    (PCCIF_SRAM_SIZE / PCCIF_BUFF_NUMBER)

//- size of PCCIF control sram for user. also used for UT.
#define PCCIF_CTRL_SRAM_USER_SIZE      256
#define PCCIF_CTRL_SRAM_USER_START     256

#define MD_PCCIF_HDR_LEN               4
#define MD_PCCIF_HDR_MAGIC_NUMBER_1    0xA
#define MD_PCCIF_HDR_MAGIC_NUMBER_2    0x5
#define MD_PCCIF_HDR_LENGTH_PARA       16

typedef enum md_pccif_pkt_type_e {
    MD_PCCIF_HDR_TYPE_PARA = 0,
    MD_PCCIF_HDR_TYPE_BUFF,
    MD_PCCIF_HDR_TYPE_MAX
} md_pccif_pkt_type_t;



typedef struct md_pccif_chl_ctrl_s {
    kal_uint32 read_ptr;
    kal_uint32 write_ptr;
} md_pccif_buff_ctrl_t;

typedef struct md_pccif_ctrl_s {
    kal_uint32 md1_version;
    kal_uint32 md2_version;
    kal_uint32 pccif_md1md2_buff_number;
    kal_uint32 pccif_md2md1_buff_number;
    kal_uint32 ex_turn;
    kal_uint32 ex_md1_hold;
    kal_uint32 ex_md2_hold;
} md_pccif_ctrl_t;

typedef struct md_pccif_pkt_hdr_s {
    kal_uint32 magic_number_2:4;
    kal_uint32 index:12;
    kal_uint32 length:8;
    kal_uint32 type:4;
    kal_uint32 magic_number_1:4;
} md_pccif_pkt_hdr_t;

extern void md_pccif_hw_init();
extern kal_uint32 md_pccif_free_buffer(kal_uint32 index);
extern kal_uint32 md_pccif_channel_is_full(kal_uint32 index);
extern kal_uint32 md_pccif_is_tx_res_avail(kal_uint32 index, kal_uint32 length);
extern void md_pccif_enqueue_para(kal_uint32 index, kal_uint32 para0, kal_uint32 para1, kal_uint32 para2);
extern void md_pccif_trigger_irq(kal_uint32 index);
extern void md_pccif_enqueue_buff(kal_uint32 index, void *addr, kal_uint32 length);
extern kal_uint32 md_pccif_get_pended_irq(kal_uint32 index);
extern kal_uint32 md_pccif_get_pkt_type(kal_uint32 index);
extern void md_pccif_ack(kal_uint32 index);
extern void md_pccif_get_buff(kal_uint32 index, kal_uint32 *buff, kal_uint32 *length);

extern kal_uint32 md_pccif_get_user_ram_base();

extern void md_pccif_hw_reset();
extern void md_pccif_get_cc_mutex();
extern void md_pccif_release_cc_mutex();
extern void md_pccif_init_reset();
extern void md_pccif_set_enable();
extern void md_pccif_set_disable();
extern kal_uint32 md_pccif_is_enabled();

#endif
