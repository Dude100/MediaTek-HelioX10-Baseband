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
 *   ccci_sdio.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   This file handles the CCCI functions that are SDIO specified (ex. share memory initialization and boot up handshake)
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * [CCCI IPC] Support Clibtime feature
 *
 * removed!
 * removed!
 * [CCCI] CCCI new debug mechanism
 *
 * removed!
 * removed!
 * [CCCI] Add exception share memory size check.
 *
 * removed!
 * removed!
 * [CCCI] Add exception share memory size check.
 *
 * removed!
 * removed!
 * [CCCI] For SS debug info
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * [K2 MD2] Add CCCI/CCIF new feature for K2 MD2
 *
 * removed!
 * removed!
 * [CCCI] Fix CCCI direct SM size
 *
 * removed!
 * removed!
 * [CCCI] Provide CCCI direct write SM API
 *
 * removed!
 * removed!
 * [CCCI & RPC & FS] ASSERT enhancement
 *
 * removed!
 * removed!
 * 	Clear memory dump flag if mtklogger is disabled
 *
 * removed!
 * removed!
 * Rollback //MOLY/TRUNK/MOLY/mcu/service/hif/ccci/src/ccci_sdio.c to revision 17
 *
 * removed!
 * removed!
 * [CCCI] Add exception debug info & boot trace.
 *
 * removed!
 * removed!
 * [CCCI] Add exception debug info & boot trace.
 *
 * removed!
 * removed!
 * 	[CCCI] CCCI MISC Info.
 *
 * 12 09 2013 box.wu
 * removed!
 * Rollback to ECCCI merge
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * [increase polling to of hs phase 2]
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * CCCI META boot flow integration
 *
 * 06 04 2013 ap.wang
 * removed!
 * Modify header file to include new CCCI header file for compatibility.
 * Add fake API
 *
 * removed!
 * removed!
 * a. Check-in cccifs new features (support 16KB I/O)
 * b. add __CCCIFS_SUPPORT__ option to related files
 *
 * removed!
 * removed!
 * [CCCI] CCCI/CLDMA INT
 *
 * removed!
 * removed!
 * MT6290 Rename CCCI Services
 *
 * removed!
 * removed!
 * [ROUTER] fix link error when SDIO_SUPPORT  is not enabled
 *
 * removed!
 * removed!
 * sync latest version of new features
 *
 * removed!
 * removed!
 * [MOLY][CCCI_SDIO] 1st version of MT6290 CCCI feature
 ****************************************************************************/
#include "ccci_common.h"
#include "ccci_if.h"
#include "kal_trace.h"
#include "ccci_sdio.h"
#include "ccci_except.h"
#include "ex_public.h"

#if defined(__MTK_TARGET__)
#include "init_public.h" //for meta mode
#include "hif_sdio_except.h"
//#define __CCCI_BYPASS_HANDSHAKE__  //for test only
    #if defined(ATEST_SYS_ENABLE) || !defined(__HIF_SDIO_SUPPORT__)
    #define __CCCI_BYPASS_HANDSHAKE__
    #endif  
#else 
/* MODIS */
#define __CCCI_BYPASS_HANDSHAKE__
#endif

#define CCCI_HS_POLLING_TIMEOUT   10*1000 //10 sec

#ifdef ATEST_SYS_CCCI
void EINT_Set_Polarity_UT(kal_uint8 eintno, kal_bool ACT_Polarity);
#define CCCI_EINT_Set_Polarity EINT_Set_Polarity_UT
#else
extern void EINT_Set_Polarity(kal_uint8 eintno, kal_bool ACT_Polarity);
#define CCCI_EINT_Set_Polarity EINT_Set_Polarity
#endif

#if 0 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
//static kal_timerid ccci_system_timer;

#ifndef __CCCI_BYPASS_HANDSHAKE__

#ifdef ATEST_SYS_CCCI
void EINT_Set_Polarity_UT(kal_uint8 eintno, kal_bool ACT_Polarity){
    //MT6280 has this function but it should be controlled by HIF SDIO in MT6290
    ccci_trace(CCCI_ERR, CCCI_MOD_SDIO, CCCI_TR_SET_POLA);
    return;
}
#endif

#define CCCI_POLLING_MODE_BUF_SZ  512+CPU_CACHE_LINE_SIZE //256: sizeof(MODEM_RUNTIME_DATA+buff),  + cache size for cache aligned
#define CCCI_POLLING_MSG_BUF_SZ   32+CPU_CACHE_LINE_SIZE  //16: sizeof(CCCI_BUFF_T),  + cache size for cache aligned
static kal_uint8 ccci_hs_buff[CCCI_POLLING_MODE_BUF_SZ]; 

/*!
 *  @brief     ccci_sdio_hs1: notify AP that MD need the run time data for information check.
 *  @return   void
 */
void ccci_sdio_hs1(void) 
{
    CCCI_BUFF_T         *ccci_buff;
#ifdef ATEST_SYS_CCCI
    kal_char            ccci_fake_ap_ack[256];
    kal_char            *pbuff;
    MODEM_RUNTIME_DATA  *pdata;
    CCCI_BUFF_T         *p_header;
#endif
//    kal_uint8           ccci_hs_buff[CCCI_POLLING_MODE_BUF_SZ]; 
    qbm_gpd             *p_gpd = NULL;
    kal_uint8           *p_data = NULL;
    void                *p_cache_aligned;
    kal_bool            hif_ret;
    kal_uint32          rcv_size = 0;
#if __DUMP_AP_ACK_INFO
    kal_uint32          i;
#endif
    MODEM_RUNTIME_DATA *ap_md_share_data = ccci_get_share_data();
    kal_uint32          get_shm_ret, set_shm_ret;

	ccci_trace(CCCI_TRACE, CCCI_MOD_SDIO,CCCI_TR_HSHK1_IN);
    /* 
     * ASSERT the case that buffser size is too small
     * if the size is too small, output of CCCI_HS_GET_ALIGN might cause mem corruption
     */ 
    ASSERT(CCCI_POLLING_MODE_BUF_SZ >= 2*CPU_CACHE_LINE_SIZE);
    /*make p_gpd aligned to CPU_CACHE_LINE_SIZE_MASK*/
    p_cache_aligned = ccci_hs_buff;
    if((kal_uint32)p_cache_aligned&CPU_CACHE_LINE_SIZE_MASK) { 
        p_cache_aligned = (void *)((kal_uint32)(ccci_hs_buff)&~CPU_CACHE_LINE_SIZE_MASK);
        p_cache_aligned += CPU_CACHE_LINE_SIZE;
    }
    p_gpd = (qbm_gpd *)p_cache_aligned;
    
	set_ccci_boot_state(CCCI_INIT); 
    
	/*Register for prevent other user mis-use*/ 
    ccci_init(CCCI_CONTROL_CHANNEL,ccci_boot_ack);
    ccci_init(CCCI_CONTROL_CHANNEL_ACK,ccci_boot_ack);//ccci_handshake1_ack);

    //kal_mem_set(ccci_hs_buff, 0, CCCI_POLLING_MODE_BUF_SZ);
    /* CCCI polling mode, QMU_BM is not ready yet*/ 
    /* format ccci_hs_buff as GPD->BUFF format */
    CCCI_INIT_RESET_DATALEN_EXTLEN((kal_uint32 *)p_gpd);
    CCCI_INIT_RESET_COMMON_DATA((kal_uint32 *)p_gpd);
    ccci_buff = QBM_DES_GET_DATAPTR(p_gpd);
    CCCI_INIT_MAILBOX(ccci_buff, CCMSG_ID_START_BOOT);
    ccci_buff->channel = CCCI_CONTROL_CHANNEL;
    ccci_buff->reserved = BOOT_CHECK_ID;
    ccci_debug_add_seq(ccci_buff, CCCI_DEBUG_NOT_ASSERT_BIT); // add ccci seq
    QBM_DES_SET_DATALEN(p_gpd, sizeof(CCCI_BUFF_T));
    QBM_CACHE_FLUSH(ccci_buff, sizeof(CCCI_BUFF_T));
    
	set_ccci_boot_state(CCCI_HANDSHAKE1); 
    
    hif_ret = hifsdio_simple_send_gpd(0, p_gpd, CCCI_HS_POLLING_TIMEOUT);
    if(!hif_ret){
        ccci_trace(CCCI_ERR, CCCI_MOD_SDIO, CCCI_TR_HSHK1_WNG, hif_ret);
        /* 20121213 ASSERT after timeout per HIF SDIO polling API limitation */
        EXT_ASSERT(KAL_FALSE, hif_ret, 0, 0);
    }

    /*Waiting for the HIF SDIO RXQ[0] to receive a mailbox "BOOT_CHECK_ID"*/
    /*This action doesn't require AP to set the CCCI channel...orz*/
    /*Need to discuss with AP side: send to CCCI_CONTROL_CHANNEL_ACK*/

#ifdef ATEST_SYS_CCCI
    //ccci_buff.reserved = BOOT_CHECK_ID;
    pbuff = ccci_fake_ap_ack;
    pbuff += sizeof(CCCI_BUFF_T);
    pdata = (MODEM_RUNTIME_DATA *)pbuff;
    pdata->DriverVersion = CCCI_CURRENT_VERSION;
    pdata->BootChannel = CCCI_CONTROL_CHANNEL;
    
    p_header = (CCCI_BUFF_T *)ccci_fake_ap_ack;
    ccci_handshake1_ack(p_header, sizeof(p_header));

    p_header->reserved =  BOOT_CHECK_ID;
    ccci_handshake1_ack(p_header, sizeof(p_header));
#endif

    ccci_trace(CCCI_TRACE, CCCI_MOD_SDIO,CCCI_TR_HSHK1_WAIT_ACK);
    QBM_DES_SET_ALLOW_LEN(p_gpd, sizeof(MODEM_RUNTIME_DATA)+sizeof(CCCI_BUFF_T));
        
    while(CCCI_HANDSHAKE1_AP_ACK != get_ccci_boot_state()){
        hif_ret = hifsdio_simple_receive_gpd(0, p_gpd, CCCI_HS_POLLING_TIMEOUT);
        if(KAL_TRUE == hif_ret){
            rcv_size = QBM_DES_GET_DATALEN(p_gpd);
            p_data = QBM_DES_GET_DATAPTR(p_gpd);
            QBM_CACHE_INVALID(p_data, rcv_size);
            ccci_debug_check_seq((CCCI_BUFF_T *)p_data); // check ccci seq
            ccci_handshake1_ack((CCCI_BUFF_T *)p_data, rcv_size - sizeof(CCCI_BUFF_T));

        }else{        
            /* 20121213 ASSERT after timeout per HIF SDIO polling API limitation */
            EXT_ASSERT(KAL_FALSE, hif_ret, 0, 0);
        }
    }
    ccci_trace(CCCI_TRACE, CCCI_MOD_SDIO,CCCI_TR_HSHK1_AP_ACK, rcv_size);
#if __DUMP_AP_ACK_INFO
    for(i = 0; i<rcv_size ; i++){
        ccci_dhl_print(CCCI_TRACE, CCCI_MOD_SDIO,"%x ", (kal_uint32) *p_data++);
    }
    ccci_dhl_print(CCCI_TRACE, CCCI_MOD_SDIO,"****************!!\n", rcv_size);
#endif

	//Modem exception memory
	ap_md_share_data->ExceShareMemBase = (kal_uint32) &MDExceShareMemBase;
	ap_md_share_data->ExceShareMemSize = mExceShareMemSize;

	//FS
	ap_md_share_data->FileShareMemBase = (kal_uint32) &MDFileShareMemBase;
	ap_md_share_data->FileShareMemSize = mFileShareMemSize;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    EXT_ASSERT(ap_md_share_data->ExceShareMemSize >= ccci_excep_shm_get_total_size(), 
               ccci_excep_shm_get_total_size(), ap_md_share_data->ExceShareMemSize, ap_md_share_data->ExceShareMemBase);

    if((kal_uint32 *)ap_md_share_data->ExceShareMemBase != NULL){
        set_shm_ret=  ccci_excep_init_shm(CCCI_EXCEP_MEMORY_TYPE_STATIC_BUFFER);
        ASSERT(set_shm_ret == CCCI_SUCCESS);
        get_shm_ret = ccci_excep_query_shm(CCCI_EXCEP_MEMORY_REGION_CCCI, &ccci_excep_dbg_log_base_hs2, &ccci_excep_dbg_log_size_hs2, &ccci_excep_dbg_log_type_hs2);
        ASSERT(get_shm_ret == CCCI_SUCCESS);
    }

    // set ccci debug feature;
    ccci_debug_set_feature();

	/* in ccci on sdio the memory attribute could be non-cacheable, bufferable memory  */
	/* 20130524 EEMCS META mode integration*/

	/* in ccci on sdio the memory attribute could be non-cacheable, bufferable memory  */
	/* 20130524 EEMCS META mode integration*/

#if defined(__MTK_TARGET__)
	if ( META_BOOT_ID == (ap_md_share_data->BootingStartID  & 0x000000FF) )
	{
		/*setting the meta mode */
		INT_SetMetaMode();
	}
    if( (ap_md_share_data->BootingStartID & 0x0000FF00) != 0 )
    {
        ex_set_memorydump_flag();
    }
    else
    {
        ex_clear_memorydump_flag();
    }
#endif
	ccci_deinit(CCCI_CONTROL_CHANNEL);
	ccci_deinit(CCCI_CONTROL_CHANNEL_ACK);
}

/*!
 *  @brief     ccci_sdio_hs2: AP_MD handshake part II
 *                ack the BootReadyID to BootChannel
 *  @return   void
 */
void ccci_sdio_hs2(kal_uint16 _boot_mode) 
{
    CCCI_BUFF_T         *ccci_buff;
//    kal_uint8           ccci_hs_buff[CCCI_POLLING_MSG_BUF_SZ]; 
    qbm_gpd             *p_gpd;
    void                *p_cache_aligned;
    kal_bool            hif_ret;
	MODEM_RUNTIME_DATA *ap_md_share_data = ccci_get_share_data();

    //ASSERT(ccci_sdio_state_g == CCCI_SDIO_HANDSHAKE1_AP_ACK);
    ccci_trace(CCCI_TRACE, CCCI_MOD_SDIO,CCCI_TR_HSHK2_IN);
    /* 
     * ASSERT the case that buffser size is too small
     * if the size is too small, output of CCCI_HS_GET_ALIGN might cause mem corruption
     */ 
    ASSERT(CCCI_POLLING_MSG_BUF_SZ >= 2*CPU_CACHE_LINE_SIZE);
    /*make p_gpd aligned to CPU_CACHE_LINE_SIZE_MASK*/
    p_cache_aligned = ccci_hs_buff;
    if((kal_uint32)p_cache_aligned&CPU_CACHE_LINE_SIZE_MASK) { 
        p_cache_aligned = (void *)((kal_uint32)(ccci_hs_buff)&~CPU_CACHE_LINE_SIZE_MASK);
        p_cache_aligned += CPU_CACHE_LINE_SIZE;
    }
    p_gpd = (qbm_gpd *)p_cache_aligned;

	set_ccci_boot_state(CCCI_HANDSHAKE2);

    /* Note that BootChannel is get from the handshake_phase1*/    	   
    ccci_init(ap_md_share_data->BootChannel,ccci_boot_ack);
    ccci_init(ap_md_share_data->BootChannel+1,ccci_boot_ack);

    //kal_mem_set(ccci_hs_buff, 0, CCCI_POLLING_MSG_BUF_SZ);
    /* CCCI polling mode, QMU_BM is not ready yet*/ 
    /* format ccci_hs_buff as GPD->BUFF format */
    CCCI_INIT_RESET_DATALEN_EXTLEN((kal_uint32 *)p_gpd);
    CCCI_INIT_RESET_COMMON_DATA((kal_uint32 *)p_gpd);
    ccci_buff = QBM_DES_GET_DATAPTR(p_gpd);

    ccci_buff->channel = ap_md_share_data->BootChannel;
    ccci_debug_add_seq(ccci_buff, CCCI_DEBUG_ASSERT_BIT); // add ccci seq
    if (ap_md_share_data->DriverVersion == CCCI_CURRENT_VERSION)
    {
        CCCI_INIT_MAILBOX(ccci_buff, ap_md_share_data->BootReadyID);
        ccci_trace(CCCI_TRACE, CCCI_MOD_SDIO, CCCI_TR_HSHK2_DRV_VER, ap_md_share_data->DriverVersion);        
    }
    else
    {
        CCCI_INIT_MAILBOX(ccci_buff, CCMSG_ID_DRV_VERSION_ERR);
        ccci_trace(CCCI_ERR, CCCI_MOD_SDIO, CCCI_TR_HSHK2_DRV_VERERR, ap_md_share_data->DriverVersion);
    }
    QBM_DES_SET_DATALEN(p_gpd, sizeof(CCCI_BUFF_T));
    QBM_CACHE_FLUSH(ccci_buff, sizeof(CCCI_BUFF_T));
        
    hif_ret = hifsdio_simple_send_gpd(0, p_gpd, CCCI_HS_POLLING_TIMEOUT);
    if(!hif_ret){
        ccci_trace(CCCI_ERR, CCCI_MOD_SDIO, CCCI_TR_HSHK2_WNG, hif_ret);
        /* 20121213 ASSERT after timeout per HIF SDIO polling API limitation */
        EXT_ASSERT(KAL_FALSE, hif_ret,0 ,0);
    }
/*    
    ccci_sdio_state_g = CCCI_SDIO_HANDSHAKE1;
    ret = ccci_write(ap_md_share_data.BootChannel, &ccci_buff);
    if(CCCI_SUCCESS != ret){
        ccci_dhl_print(CCCI_ERR, CCCI_MOD_SDIO, "[CCCI_ERR] ====>BootChannel ccci_write return %x \r\n", ret);
    }
*/
#ifdef ATEST_SYS_CCCI
    /* LB the request */
    ccci_boot_ack(&ccci_buff);
    ccci_get_share_data();
#endif

    ccci_deinit(ap_md_share_data->BootChannel);
    ccci_deinit(ap_md_share_data->BootChannel+1);

	set_ccci_boot_state(CCCI_BOOT_DONE); 
}

#else //__CCCI_BYPASS_HANDSHAKE__

void ccci_sdio_hs1(void) 
{
    return;
}

void ccci_sdio_hs2(kal_uint16 _boot_mode) 
{
	//MODEM_RUNTIME_DATA *ap_md_share_data = ccci_get_share_data();

	//FS: Initialized for feature development
	//ap_md_share_data->FileShareMemBase = (kal_uint32)&MDFileShareMemBase;
	//ap_md_share_data->FileShareMemSize = mFileShareMemSize;

    return;
}
#endif //__CCCI_BYPASS_HANDSHAKE__
