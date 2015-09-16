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
 *	This is the USB3.0/SDIO buffer management driver
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 ****************************************************************************/

#include "brom_bm.h"

volatile brom_tgpd_t brom_tgpd;
volatile brom_rgpd_t brom_rgpd;


kal_uint32 calc_checksum_by_len(kal_uint32 checksum, kal_uint8* data, kal_int32 len) 
{
    kal_int32 i;

    /* 
     * The len must be divied by 4.
     * So we can optm it by this weird way.
     * The optm jsut for ARM
     */
    i = len - 8;
    do {
        checksum  += data[i + 4];
        checksum  += data[i + 5];
        checksum  += data[i + 6];
        checksum  += data[i + 7];
        i -= 4;
    }while (i >= 0);

    /* 
     * Don't need this mask, because we setup check sum by strb (BM_DES_SET_CHK).
     * The instruction only retrieve first byte, so don't need to mask chksum with 0xFF.
     * The first byte are the same even if checksum value > 0xFF.
     * (0xFF - 0x123)&0xFF == (0xFF - 0x23)
     */
    //checksum &= 0xFF;

    return (0xFF - checksum);
}


kal_uint32 cal_checksum_by_len(kal_uint8 *data, kal_uint32 check_len)
{
    kal_uint32 checksum;


     /*
      * byte 2 is checksum, we don't need to add it
      */
    checksum  = *data;
    checksum += data[2];
    checksum += data[3];

    checksum = calc_checksum_by_len(checksum, data, check_len);

	return checksum;
}


void brom_reset_tgpd(void)
{
	kal_uint32 checksum = 0;

	memset((void *)(&brom_tgpd), 0 , sizeof(brom_tgpd_t));
	brom_tgpd.in_use = KAL_FALSE;

	brom_tgpd.sig = BROM_GPD_SIGNATURE;

	/*set tail gpd as BSP GPD with HWO=0*/
	QBM_DES_SET_BPS(&brom_tgpd.bps_tail_gpd);
	checksum = cal_checksum_by_len((kal_uint8 *)(&brom_tgpd.bps_tail_gpd), DEFAULT_QMU_CS_12);
	QBM_DES_SET_CHKSUM(&brom_tgpd.bps_tail_gpd, checksum);

	/*set data tgpd no ext part, no bd, with 1024 allow length, HWO=1*/
	QBM_DES_SET_HWO(&brom_tgpd.data_gpd);
	QBM_DES_SET_NEXT(&brom_tgpd.data_gpd, &brom_tgpd.bps_tail_gpd);
#ifdef USE_USB_LOCAL_BUF
	QBM_DES_SET_DATAPTR(&brom_tgpd.data_gpd, &brom_tgpd.buf);
#endif
	checksum = cal_checksum_by_len((kal_uint8 *)(&brom_tgpd.data_gpd), DEFAULT_QMU_CS_12);
	QBM_DES_SET_CHKSUM(&brom_tgpd.data_gpd, checksum);
	/*clear HWO to abort current in used GPD*/
	QBM_DES_CLR_HWO(&brom_tgpd.data_gpd);
}

void brom_reset_rgpd(kal_uint32 chunk_sz, kal_bool is_sdio)
{
	kal_uint32 checksum = 0, chunk_sz_limit = 0;

	memset((void*)(&brom_rgpd), 0 , sizeof(brom_rgpd_t));
	brom_rgpd.in_use = KAL_FALSE;

	brom_rgpd.sig = BROM_GPD_SIGNATURE;

	/*set tail gpd as BSP GPD with HWO=0*/
	QBM_DES_SET_BPS(&brom_rgpd.bps_tail_gpd);
	checksum = cal_checksum_by_len((kal_uint8 *)(&brom_rgpd.bps_tail_gpd), DEFAULT_QMU_CS_12);
	QBM_DES_SET_CHKSUM(&brom_rgpd.bps_tail_gpd, checksum);

	if (is_sdio) {
		chunk_sz_limit = BROM_SDIO_RX_GPD_BUF_SZ;
	} else {
		chunk_sz_limit = BROM_USB_RX_GPD_BUF_SZ;
	}

	/*set data rgpd no ext part, no bd, with 1024 allow length, HWO=1*/
	QBM_DES_SET_HWO(&brom_rgpd.data_gpd);
	if (chunk_sz <= chunk_sz_limit) {
		QBM_DES_SET_ALLOW_LEN(&brom_rgpd.data_gpd, chunk_sz);
	} else { 
		/*ERROR*/
		QBM_DES_SET_ALLOW_LEN(&brom_rgpd.data_gpd, chunk_sz_limit);	
	}
	QBM_DES_SET_NEXT(&brom_rgpd.data_gpd, &brom_rgpd.bps_tail_gpd);
#ifdef USE_USB_LOCAL_BUF
	QBM_DES_SET_DATAPTR(&brom_rgpd.data_gpd, &brom_rgpd.buf);
#endif
	checksum = cal_checksum_by_len((kal_uint8 *)(&brom_rgpd.data_gpd), DEFAULT_QMU_CS_12);
	QBM_DES_SET_CHKSUM(&brom_rgpd.data_gpd, checksum);
	/*clear HWO to abort current in used GPD*/
	QBM_DES_CLR_HWO(&brom_rgpd.data_gpd);
}

/*!
 *	@brief	initial the bootrom tx/rx gpd
 *			When USB speed is confirmed, we should set the receive chunk size 
 *			as MPS x N for ACM usage.
 *	@param	chunk_sz :the RGPD allow length would be set by chunk size
 *	@param	is_sdio : TRUE: Chunk size doesn't limited by USB chunk size rule
*/
void brom_bm_init(kal_uint32 rx_chunk_sz, kal_bool is_sdio)
{
	/*initial tgpd*/
	brom_reset_tgpd();

	/*initial rgpd*/
	brom_reset_rgpd(rx_chunk_sz, is_sdio);

}





