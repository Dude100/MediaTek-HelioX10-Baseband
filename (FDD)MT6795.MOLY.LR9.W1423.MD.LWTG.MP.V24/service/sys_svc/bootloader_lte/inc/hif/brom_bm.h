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
 *   brom_bm.c
 *
 * Project:
 * --------
 *   BOOTROM
 *
 * Description:
 * ------------
 *	This is the USB3.0/SDIO buffer management driver header file
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 ****************************************************************************/

#ifndef __BROM_BM_H__
#define __BROM_BM_H__

#include "brom_u3mac_reg.h"
#include "string.h"

#define DEFAULT_QMU_CS_12	12

#define BROM_USB_RX_GPD_BUF_SZ	1024
#define BROM_SDIO_RX_GPD_BUF_SZ	2048

#define BROM_GPD_SIGNATURE	0x7208


typedef struct _qbm_gpd
{
    kal_uint8   flags;
    kal_uint8   chksum;
    kal_uint16  reserved1;
    void    	*p_next;
    void       	*p_data_tbd;
    kal_uint16  data_len;
    kal_uint8   ext_len;
    kal_uint8   reserved2;
} qbm_gpd;

//#define USE_USB_LOCAL_BUF
typedef struct _brom_tgpd {
	kal_uint16 sig; 
	kal_uint8 reserve;//reserve for GPD header 4byte align
	kal_bool in_use;
	qbm_gpd bps_tail_gpd;
	qbm_gpd data_gpd;
#ifdef USE_USB_LOCAL_BUF	
	kal_uint8 buf[BROM_TX_GPD_BUF_SZ];
#endif
} brom_tgpd_t;

typedef struct _brom_rgpd {
	kal_uint16 sig; 
	kal_uint8 reserve;//reserve for GPD header 4byte align
	kal_bool in_use;
	qbm_gpd bps_tail_gpd;
	qbm_gpd data_gpd;
#ifdef USE_USB_LOCAL_BUF	
	kal_uint8 buf[BROM_RX_GPD_BUF_SZ];
#endif
} brom_rgpd_t;

/*************************************************************************
 * Exported Macros
 *************************************************************************/
#define DES_FLAG_BIT_HWO  0x01
#define DES_FLAG_BIT_EOL  0x01
#define DES_FLAG_BIT_BDP  0x02
#define DES_FLAG_BIT_BPS  0x04
#define DES_FLAG_BIT_IOC  0x80

#define QBM_GET_GPD_PTR(_p) ((qbm_gpd*)(_p))

#define QBM_DES_SET_HWO(_p) \
          (QBM_GET_GPD_PTR(_p)->flags |= DES_FLAG_BIT_HWO)

#define QBM_DES_CLR_HWO(_p) \
          (QBM_GET_GPD_PTR(_p)->flags &= ~DES_FLAG_BIT_HWO)

#define QBM_DES_GET_HWO(_p) \
          (QBM_GET_GPD_PTR(_p)->flags & DES_FLAG_BIT_HWO)

#define QBM_DES_SET_BDP(_p)             \
          (QBM_GET_GPD_PTR(_p)->flags |= DES_FLAG_BIT_BDP)

#define QBM_DES_CLR_BDP(_p)             \
          (QBM_GET_GPD_PTR(_p)->flags &= ~DES_FLAG_BIT_BDP)

#define QBM_DES_GET_BDP(_p) \
          (QBM_GET_GPD_PTR(_p)->flags & DES_FLAG_BIT_BDP)

#define QBM_DES_SET_BPS(_p) \
          (QBM_GET_GPD_PTR(_p)->flags |= DES_FLAG_BIT_BPS)

#define QBM_DES_CLR_BPS(_p) \
          (QBM_GET_GPD_PTR(_p)->flags &= ~DES_FLAG_BIT_BPS)

#define QBM_DES_GET_BPS(_p) \
          (QBM_GET_GPD_PTR(_p)->flags & DES_FLAG_BIT_BPS)

#define QBM_DES_SET_IOC(_p) \
          (QBM_GET_GPD_PTR(_p)->flags |= DES_FLAG_BIT_IOC)

#define QBM_DES_CLR_IOC(_p) \
          (QBM_GET_GPD_PTR(_p)->flags &= ~DES_FLAG_BIT_IOC)

#define QBM_DES_GET_IOC(_p) \
          (QBM_GET_GPD_PTR(_p)->flags & DES_FLAG_BIT_IOC)

#define QBM_DES_SET_EOL(_p) \
          (QBM_GET_GPD_PTR(_p)->flags |= DES_FLAG_BIT_EOL)

#define QBM_DES_CLR_EOL(_p) \
          (QBM_GET_GPD_PTR(_p)->flags &= ~DES_FLAG_BIT_EOL)

#define QBM_DES_GET_EOL(_p) \
          (QBM_GET_GPD_PTR(_p)->flags & DES_FLAG_BIT_EOL)

#define QBM_DES_SET_CHKSUM(_p, _chk) \
          (QBM_GET_GPD_PTR(_p)->chksum = (_chk))

#define QBM_DES_GET_CHKSUM(_p) \
          QBM_GET_GPD_PTR(_p)->chksum

#define QBM_DES_SET_ALLOW_LEN(_p, _len) \
          (QBM_GET_GPD_PTR(_p)->reserved1 = (_len))

#define QBM_DES_GET_ALLOW_LEN(_p) \
          (QBM_GET_GPD_PTR(_p)->reserved1)

#define QBM_DES_SET_NEXT(_p, _nxt)           \
          QBM_GET_GPD_PTR(_p)->p_next = (qbm_gpd*)(_nxt)

#define QBM_DES_GET_NEXT(_p) \
          (QBM_GET_GPD_PTR(_p)->p_next)

#define QBM_DES_SET_DATAPTR(_p, _dp)     \
          (QBM_GET_GPD_PTR(_p)->p_data_tbd = (kal_uint8*)(_dp))

#define QBM_DES_GET_DATAPTR(_p) \
          (QBM_GET_GPD_PTR(_p)->p_data_tbd)

#define QBM_DES_GET_DATALEN(_p) \
          QBM_GET_GPD_PTR(_p)->data_len

#define QBM_DES_SET_DATALEN(_p, _l) \
          QBM_GET_GPD_PTR(_p)->data_len = (_l)

#define QBM_DES_GET_EXTLEN(_p) \
          QBM_GET_GPD_PTR(_p)->ext_len

#define QBM_DES_SET_EXTLEN(_p, _l) \
          QBM_GET_GPD_PTR(_p)->ext_len = (_l)

#define QBM_DES_GET_EXT(_p) \
          ((kal_uint8*)(_p) + sizeof(qbm_gpd)) 



extern volatile brom_tgpd_t brom_tgpd;
extern volatile brom_rgpd_t brom_rgpd;


/*export API*/
void brom_reset_rgpd(kal_uint32 chunk_sz, kal_bool is_sdio);
void brom_reset_tgpd(void);
void brom_bm_init(kal_uint32 rx_chunk_sz, kal_bool is_sdio);
kal_uint32 cal_checksum_by_len(kal_uint8 *data, kal_uint32 check_len);
#endif
