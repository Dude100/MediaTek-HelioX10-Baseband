#include "drv_comm.h"
#include "brom_bm.h"
#include "brom_sdio_reg.h"
#include "brom_sdioq_op.h"
#include "brom_sdio_drv.h"
#include "bl_common.h"
#include "bl_GPT.h"

static uint32 first_time = 1;
static uint32 timeout_ms = 0;
kal_uint32 ul_expect_pkt_cnt = 0;

static void hifsdio_set_func_ready()
{
    *ORG_SDIO_CAPABILITY_READY = 0x1;
    *ORG_SDIO_CIS_READY = 0x1;
    *SDIO_CTRL_FCR |= SDIO_W_FUNC_RDY;
    return ;
}


static void hifsdio_give_fw_own()
{
    if( *SDIO_IRQ_FICR & SDIO_FW_OWN){
        *SDIO_IRQ_FICR |= SDIO_FW_OWN_BACK_SET;
    }
}

static void hifsdioq_set_ulq_count(kal_bool reset, kal_uint8 ulq_index, kal_uint8 inc_ulq_count)
{
    kal_uint32  write_val;
    if( KAL_TRUE == reset ){
        write_val = 0x1 << 16;
        *SDIO_QMU_UL_PCCR = write_val;
    }
    else{
        write_val = (0x0F & ulq_index)<<12;
        write_val = write_val | (kal_uint32)inc_ulq_count;
        *SDIO_QMU_UL_PCCR = write_val;
    }
}


static void hifsdioq_set_dlq_new_gpd(kal_uint8 dlq_index, kal_uint16 dl_gpd_len)
{
    switch (dlq_index) {
        case 0:
            *SDIO_QMU_DLQ_CR_n(0) = (SDIO_QMU_DLQ_RESUME | (kal_uint32)dl_gpd_len);
            break;
            
        case 1:
            *SDIO_QMU_DLQ_CR_n(1) = (SDIO_QMU_DLQ_RESUME | (kal_uint32)dl_gpd_len);
            break;
            
        case 2:
            *SDIO_QMU_DLQ_CR_n(2) = (SDIO_QMU_DLQ_RESUME | (kal_uint32)dl_gpd_len);
            break;
            
        case 3:
            *SDIO_QMU_DLQ_CR_n(3) = (SDIO_QMU_DLQ_RESUME | (kal_uint32)dl_gpd_len);
            break;
            
        default:
            break;
    }

}



static kal_bool hifsdio_get_ul_data(kal_uint8 *recv_buf, kal_uint32 *p_len)
{
	kal_bool ret = KAL_FALSE;
	qbm_gpd *p_gpd = NULL;
	kal_uint8 q_num = 0;
	kal_uint32 checksum = 0;

	q_num = BROM_SDIO_UL_QUE;
	p_gpd = (qbm_gpd *)&brom_rgpd.data_gpd;
	*p_len = 0;

	if (brom_rgpd.in_use == KAL_FALSE) {
		brom_rgpd.in_use = KAL_TRUE;

		/*stop queue*/
		SDIO_QMU_STOP(KAL_FALSE, q_num);
		SDIO_QMU_CHK_STOP_COMPLETE(KAL_FALSE, q_num);
        
        hifsdioq_set_ulq_count(KAL_TRUE, q_num, 1);

		/*fill GPD format*/
		QBM_DES_SET_HWO(p_gpd);
		QBM_DES_SET_DATAPTR(p_gpd, recv_buf);
		checksum = cal_checksum_by_len((kal_uint8*)p_gpd, DEFAULT_QMU_CS_12);
		QBM_DES_SET_CHKSUM(p_gpd, checksum);

		/*start queue*/
		SDIO_QMU_SET_START_ADDR(KAL_FALSE, q_num, p_gpd);
		SDIO_QMU_START(KAL_FALSE, q_num);

        hifsdioq_set_ulq_count(KAL_FALSE, q_num, 1);
        
	} else {
		if (QBM_DES_GET_HWO(p_gpd) == 0) {
			/*return receive data and data length*/
			*p_len = QBM_DES_GET_DATALEN(p_gpd);

			if (brom_rgpd.sig != BROM_GPD_SIGNATURE) {
				/* ERROR : GPD signature is set by others	*/	
				brom_reset_rgpd(BROM_SDIO_RX_GPD_BUF_SZ, KAL_TRUE);
                		BL_PRINT(LOG_ERROR, "SDIO:UL GPD SIG Error\n");
			}
			/*bootrom service recycle the buffer and HIF set buffer not in-use to wait new buffer submitted*/
			brom_rgpd.in_use = KAL_FALSE;

			ret = KAL_TRUE;
		}
	}
	
	return ret;
}

static kal_bool hifsdio_multi_get_ul_data(kal_uint8 *recv_buf, kal_uint32 *p_len)
{
	kal_bool ret = KAL_FALSE;
	qbm_gpd *p_gpd = NULL;
	kal_uint8 q_num = 0;
	kal_uint32 checksum = 0;
	kal_uint32 idx = 0;
	kal_uint32 total_len = 0;
	kal_uint8 *buf_addr = 0;


	q_num = BROM_SDIO_UL_QUE;

	if (brom_multi_rgpd[0].in_use == KAL_FALSE) { //use 1st gpd as the whole pool usage state

		ul_expect_pkt_cnt = *p_len / BROM_SDIO_RX_GPD_BUF_SZ;
		if ((*p_len % BROM_SDIO_RX_GPD_BUF_SZ) != 0) {
			ul_expect_pkt_cnt ++;
		}		
		if (ul_expect_pkt_cnt > BROM_MAX_MULTI_UL_PKT_CNT) {
			ul_expect_pkt_cnt = BROM_MAX_MULTI_UL_PKT_CNT;
		}

		/*stop queue*/
		SDIO_QMU_STOP(KAL_FALSE, q_num);
		SDIO_QMU_CHK_STOP_COMPLETE(KAL_FALSE, q_num);

		brom_multi_rgpd[0].in_use = KAL_TRUE;
		buf_addr = recv_buf;
		/*fill gpd list*/
		for (idx = 0 ; idx < ul_expect_pkt_cnt ; idx ++) {			
			/*fill GPD format*/
			QBM_DES_SET_HWO(&brom_multi_rgpd[idx].data_gpd);
			QBM_DES_SET_DATAPTR(&brom_multi_rgpd[idx].data_gpd, buf_addr);
			buf_addr += BROM_SDIO_RX_GPD_BUF_SZ;
			if (idx >= (ul_expect_pkt_cnt - 1)) {
				/*set latest null gpd*/
				QBM_DES_SET_NEXT(&brom_multi_rgpd[idx].data_gpd, &brom_multi_rgpd[idx].bps_tail_gpd);
			} else {
				/*set gpd link*/
				QBM_DES_SET_NEXT(&brom_multi_rgpd[idx].data_gpd, &brom_multi_rgpd[idx+1].data_gpd);
			}
			checksum = cal_checksum_by_len((kal_uint8*)&brom_multi_rgpd[idx].data_gpd, DEFAULT_QMU_CS_12);
			QBM_DES_SET_CHKSUM(&brom_multi_rgpd[idx].data_gpd, checksum);
		}        
		/*start with gpd list header*/
		p_gpd = (qbm_gpd *)&brom_multi_rgpd[0].data_gpd;
		/*start queue*/
		SDIO_QMU_SET_START_ADDR(KAL_FALSE, q_num, p_gpd);
		SDIO_QMU_START(KAL_FALSE, q_num);

        hifsdioq_set_ulq_count(KAL_FALSE, q_num, ul_expect_pkt_cnt);
        
	} else {
		for (idx = 0 ; idx < ul_expect_pkt_cnt ; idx ++) {
			p_gpd = &brom_multi_rgpd[idx].data_gpd;
			if (QBM_DES_GET_HWO(p_gpd) == 0) {
				total_len += QBM_DES_GET_DATALEN(p_gpd);
			} else {
				break;
			}
		}
		if (idx == ul_expect_pkt_cnt) { //means expect ul pkt received
			brom_multi_rgpd[0].in_use = KAL_FALSE;
			ul_expect_pkt_cnt = 0;
			*p_len = total_len;
			ret = KAL_TRUE;
		}
	}
	
	return ret;
}


static kal_bool hifsdio_send_dl_data(kal_uint8 *send_buf, kal_uint32 len)
{
	kal_bool ret = KAL_FALSE;
	qbm_gpd *p_gpd = NULL;
	kal_uint8 q_num = 0;
	kal_uint32 checksum = 0;
    kal_uint32  timeout_us = 1000*1000*10; // 10 sec

	q_num = BROM_SDIO_DL_QUE;
	p_gpd = (qbm_gpd *)&brom_tgpd.data_gpd;

	if (brom_tgpd.in_use == KAL_FALSE) {
		brom_tgpd.in_use = KAL_TRUE;
		
		/*stop queue*/
		SDIO_QMU_STOP(KAL_TRUE, q_num);
		SDIO_QMU_CHK_STOP_COMPLETE(KAL_TRUE, q_num);
		/*fill GPD format*/
		QBM_DES_SET_HWO(p_gpd);
		QBM_DES_SET_DATAPTR(p_gpd, send_buf);
		QBM_DES_SET_DATALEN(p_gpd, len);
		checksum = cal_checksum_by_len((kal_uint8*)p_gpd, DEFAULT_QMU_CS_12);
		QBM_DES_SET_CHKSUM(p_gpd, checksum);
		/*start queue*/
		SDIO_QMU_SET_START_ADDR(KAL_TRUE, q_num, p_gpd);
		SDIO_QMU_START(KAL_TRUE, q_num);

        hifsdioq_set_dlq_new_gpd(q_num, len);
	}
	/*block here until tx packet sent*/
	while(1) {
		if (QBM_DES_GET_HWO(p_gpd) == 0 && (*SDIO_IRQ_DL_FTE0SR & SDIO_DLQ_DONE(BROM_SDIO_DL_QUE)) ) {

            *SDIO_IRQ_DL_FTE0SR |= SDIO_DLQ_DONE(BROM_SDIO_DL_QUE);
            
			if (brom_tgpd.sig != BROM_GPD_SIGNATURE) {
				/* ERROR : GPD signature is set by others	*/
				brom_reset_tgpd();
				brom_tgpd.in_use = KAL_TRUE;
				BL_PRINT(LOG_ERROR, "SDIO:DL GPD SIG Error\n");
			}
			brom_tgpd.in_use = KAL_FALSE;
			ret = KAL_TRUE;
			break;
		}

        bl_drvgpt_udelay(BL_GPT_UDELAY_INSTANCE, 1);
        timeout_us--;
        if(0 == timeout_us){
            //Although this is a blocking function without timeout, still print error message after 10 sec.
            BL_PRINT(LOG_ERROR, "SDIO:Send packer blocked\n");
            timeout_us = 1000*1000*10;
        }
	}
	return ret;
}


static kal_bool hifsdio_send_dl_data_with_timeout(kal_uint8 *send_buf, kal_uint32 len, kal_uint32 timeout)
{
	kal_bool ret = KAL_FALSE;
	qbm_gpd *p_gpd = NULL;
	kal_uint8 q_num = 0;
	kal_uint32 checksum = 0;
    uint32 timeout_us = timeout * 1000;
    uint32 time_count = 0;
    
	q_num = BROM_SDIO_DL_QUE;
	p_gpd = (qbm_gpd *)&brom_tgpd.data_gpd;

	if (brom_tgpd.in_use == KAL_FALSE) {
		brom_tgpd.in_use = KAL_TRUE;
		
		/*stop queue*/
		SDIO_QMU_STOP(KAL_TRUE, q_num);
		SDIO_QMU_CHK_STOP_COMPLETE(KAL_TRUE, q_num);
		/*fill GPD format*/
		QBM_DES_SET_HWO(p_gpd);
		QBM_DES_SET_DATAPTR(p_gpd, send_buf);
		QBM_DES_SET_DATALEN(p_gpd, len);
		checksum = cal_checksum_by_len((kal_uint8*)p_gpd, DEFAULT_QMU_CS_12);
		QBM_DES_SET_CHKSUM(p_gpd, checksum);
		/*start queue*/
		SDIO_QMU_SET_START_ADDR(KAL_TRUE, q_num, p_gpd);
		SDIO_QMU_START(KAL_TRUE, q_num);

        hifsdioq_set_dlq_new_gpd(q_num, len);

        //BL_PRINT(LOG_ERROR, "[Debug log] SDIO: DL packet send - len = %d \n\r", len);
	}
	/*block here until tx packet sent*/
	while(1) {
		if (QBM_DES_GET_HWO(p_gpd) == 0 && (*SDIO_IRQ_DL_FTE0SR & SDIO_DLQ_DONE(BROM_SDIO_DL_QUE)) ) {

            *SDIO_IRQ_DL_FTE0SR |= SDIO_DLQ_DONE(BROM_SDIO_DL_QUE);
            
			if (brom_tgpd.sig != BROM_GPD_SIGNATURE) {
				/* ERROR : GPD signature is set by others	*/
				brom_reset_tgpd();
				brom_tgpd.in_use = KAL_TRUE;
                		BL_PRINT(LOG_ERROR, "SDIO:DL GPD SIG Error \n\r");
			}
			brom_tgpd.in_use = KAL_FALSE;
			ret = KAL_TRUE;

            //BL_PRINT(LOG_ERROR, "[Debug log] SDIO: DL packet send Sccess~ \n\r");
			break;
		}

        time_count++;
        if(time_count > timeout_us){
            //ERROR : send pkt timeout
		    brom_reset_tgpd();
			brom_tgpd.in_use = KAL_FALSE;
            BL_PRINT(LOG_ERROR, "SDIO:Send packet timeout \n\r");
            //while(1){} /* only for debug use */
            ret = KAL_FALSE;
            break;
        }
        
        bl_drvgpt_udelay(BL_GPT_UDELAY_INSTANCE, 1);
	}
	return ret;
}

/*!
 *	@brief	Handle the SDIO related interrupt by polling.
 *	@return	No return value.
*/
void brom_sdio_isr_handle(void)
{
    if( (*SDIO_IRQ_FISR & SDIO_DRV_CLR_FW_OWN) ){
        *SDIO_IRQ_FISR |= SDIO_DRV_CLR_FW_OWN;
        hifsdio_give_fw_own();
    }

    if( (*SDIO_IRQ_FISR & BROM_SDIO_D2HMB0_INT) ){
        *SDIO_IRQ_FISR |= BROM_SDIO_D2HMB0_INT;
    }

    // change mailbox interrupt ack code to brom_sdio_sync
    //if( (*SDIO_IRQ_FISR & BROM_SDIO_H2DMB0_INT) ){
    //    *SDIO_IRQ_FISR |= BROM_SDIO_H2DMB0_INT;
    //}
    
}


kal_bool brom_sdio_xboot_send_d2hmb0_int(void)
{
    DRV_WriteReg32(SDIO_IRQ_FICR, BROM_SDIO_D2HMB0_INT);
    return KAL_TRUE;
}

/*!
 *	@brief	reset first_time parameter for mailbox sync again.
 */
void brom_sdio_sync_reset(void)
{
     first_time = 1;
}

/*!
 *	@brief	Handle the SDIO related interrupt by polling.
 *	@return	BROM_SDIO_SYNC_FALSE   : No success sync this time
 *                 BROM_SDIO_SYNC_XBOOT  : Sync success with xBoot protocol
 *                 BROM_SDIO_SYNC_GDB      : Sync success with GDB protocol
 */
brom_sdio_sync_rslt_e brom_sdio_sync(void)
{
        uint32 lsr;
        uint32 timeout = 0;
        uint32 swint_val;

        if(1 == first_time){
            hifsdio_set_func_ready();
            *SDIO_IRQ_FISR |= BROM_SDIO_H2DMB0_INT;
            
            DRV_WriteReg32(SDIO_MB_D2HSM0R, SDIOMB_BOOT_REQ_MAGIC);
            brom_sdio_xboot_send_d2hmb0_int();
            
            first_time = 0;
        }

        brom_sdio_isr_handle();

        lsr = DRV_Reg32(SDIO_MB_H2DRM0R);   
        swint_val = *SDIO_IRQ_FISR;   

        if ((lsr & 0xFFFFFF00) == SDIOMB_BOOT_ACK_MAGIC && (swint_val & BROM_SDIO_H2DMB0_INT))
        {
            *SDIO_IRQ_FISR |= BROM_SDIO_H2DMB0_INT;
            //BL_PRINT(LOG_ERROR, "[Debug log] SDIO: H2D Mailbox received... \n\r");
            
            timeout = (lsr & SDIOMB_ACK_TIMEOUT_MASK);
            timeout_ms = timeout * 10;
            if( 0 == timeout_ms){
                timeout_ms = 10;
            }
            return BROM_SDIO_SYNC_XBOOT;
            
        }        

        return BROM_SDIO_SYNC_FALSE;
        
}


/*!
 *	@brief	Get SDIO UpLink data by this API
 *	@param	recv_buf : buffer to store received data
 *	@param	p_len: return received data length 
 *	@return	KAL_TRUE: received data, KAL_FLASE: no received data
*/
kal_bool brom_sdio_get_rx_gdb(kal_uint8 *recv_buf, kal_uint32 *p_len)
{
	/*handle sdio isr when bootrom call this function*/
	brom_sdio_isr_handle();

	return hifsdio_get_ul_data(recv_buf, p_len);
}

/*!
 *	@brief	Send SDIO DownLink data by this API, will blocked until sent, no timeout
 *	@param	send_buf : buffer to send
 *	@param	len : the data length to send
 *	@return	KAL_TRUE: data send success, KAL_FALSE: data send fail
*/
kal_bool brom_sdio_send_tx_gdb(kal_uint8 *send_buf, kal_uint32 len)
{
	/*handle sdio isr when bootrom call this function*/
	brom_sdio_isr_handle();

	return hifsdio_send_dl_data(send_buf, len);
}


/*!
 *	@brief	Get SDIO UpLink data by this API in xBoot protocol
 *	@param	recv_buf : buffer to store received data
 *	@param	p_len: return received data length 
 *	@param	timeout: timeout value, unit is ms
 *	@return	KAL_TRUE: received data, KAL_FLASE: no received data until timeout
*/
kal_bool brom_sdio_get_rx_xboot(kal_uint8 *recv_buf, kal_uint32 *p_len, kal_uint32 timeout)
{
    uint32 timeout_us = timeout * 1000;
    uint32 time_count = 0;
    kal_bool ret = KAL_FALSE;

    while (KAL_FALSE == ret)
    {
	    /*handle sdio isr when bootrom call this function*/
	    brom_sdio_isr_handle();

#ifdef __UBL__
		ret = hifsdio_multi_get_ul_data(recv_buf, p_len);
#else
        ret = hifsdio_get_ul_data(recv_buf, p_len);
#endif
        time_count++;
        if(time_count > timeout_us){
            BL_PRINT(LOG_ERROR, "SDIO:Get packet timeout\n");
            break;
        }
        
        bl_drvgpt_udelay(BL_GPT_UDELAY_INSTANCE, 1);
    }

    return ret;
}


/*!
 *	@brief	Send SDIO DownLink data by this API, will blocked until sent, no timeout
 *	@param	send_buf : buffer to send
 *	@param	len : the data length to send
 *	@return	KAL_TRUE: data send success, KAL_FALSE: data send fail
*/
kal_bool brom_sdio_send_tx_xboot(kal_uint8 *send_buf, kal_uint32 len, kal_uint32 timeout)

{
	/*handle sdio isr when bootrom call this function*/
	brom_sdio_isr_handle();

	return hifsdio_send_dl_data_with_timeout(send_buf, len, timeout);
}


/*!
 *	@brief	return the timeout value which get form host by xboot or GDB sync.
 *	@return	timeout value,  unit is ms. 
 */
kal_uint32 brom_sdio_get_timeout(void)
{
    return timeout_ms;
}


/*!
 *	@brief	Send SDDL magic number and wait host to response REFU, it is a block function
 *	@return	KAL_TRUE until host return REFU.
 */
kal_bool brom_sdio_xboot_mb_sddl(void)
{
    uint32  h2dmb0_value;
    uint32  timeout_us = 1000*1000*10; // 10 sec
    
    DRV_WriteReg32(SDIO_MB_D2HSM0R, SDIOMB_DOWNLOAD_REQ_MAGIC);
    DRV_WriteReg32(SDIO_IRQ_FICR, BROM_SDIO_D2HMB0_INT);

    while(1){
        bl_drvgpt_udelay(BL_GPT_UDELAY_INSTANCE, 1);
        h2dmb0_value = DRV_Reg32(SDIO_MB_H2DRM0R);

        if(SDIOMB_REQ_REFUSE_MAGIC == h2dmb0_value){
            break;
        }

        timeout_us--;
        if(0 == timeout_us){
            //host not reply the mailbox after 10 sec, print error message but still wait.
            BL_PRINT(LOG_ERROR, "SDIO:Mailbox SDDL blocked\n");
            timeout_us = 1000*1000*10;
        }
    }
    
    return KAL_TRUE;
}


/*!
 *	@brief	Sync with host before PLL init, because AHB bus will stop and change during PLL_init
 */
void brom_sdio_sync_before_PLL_init(void)
{
    uint32 sdio_int_status = 0;
    uint32  timeout_us = 1000*1000*10; // 10 sec
    
    *SDIO_IRQ_FICR = BROM_SDIO_PLL_START;
    sdio_int_status = *SDIO_IRQ_FISR; 
    
    while( !(sdio_int_status & SDIO_DRV_SET_FW_OWN) ){
        bl_drvgpt_udelay(1, 1);
        timeout_us--;
        
        sdio_int_status = *SDIO_IRQ_FISR;
        
        if(0 == timeout_us){
            BL_PRINT(LOG_ERROR, "SDIO:Sync with Host before PLL init - timeout!! \n");
            timeout_us = 1000*1000*10; ;
        }
    }
    
    *SDIO_IRQ_FISR |= SDIO_DRV_CLR_FW_OWN;
}


/*!
 *	@brief	Sync with host after PLL init, because AHB bus will stop and change during PLL_init
 */
void brom_sdio_sync_after_PLL_init(void)
{
    //*SDIO_IRQ_FICR = BROM_SDIO_PLL_END;
    bl_drvgpt_udelay(1, 1);
    
    if( *SDIO_IRQ_FICR & SDIO_FW_OWN){
        *SDIO_IRQ_FICR |= SDIO_FW_OWN_BACK_SET;
    }
}


/*!
 *	@brief	Write Mailbox 1
 */
void brom_sdio_write_mb1(kal_uint32 data)
{
    DRV_WriteReg32(SDIO_MB_D2HSM1R, data);
}

