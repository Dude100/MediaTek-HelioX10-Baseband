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
 *   ccci_except.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Implements the CCCI exception mode
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
 * [CCCI IPC] Support Clibtime feature
 *
 * removed!
 * removed!
 * [CCCI] Fix Klocwork warnings
 *
 * removed!
 * removed!
 * [CCCI FS] Support CCCI FS exception mode.
 *
 * removed!
 * removed!
 * [CCCI] Remove CCCI unused including path.
 *
 * removed!
 * removed!
 * [CCCI] Remove CCCI unused including path.
 *
 * removed!
 * removed!
 * [CCCI FS] Support CCCI FS exception mode.
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
 * [CCCI] For SS debug info
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * [CCCI] Change CCIF MPU protection
 *
 * removed!
 * removed!
 * [K2 MD2] Add CCCI/CCIF new feature for K2 MD2
 *
 * removed!
 * removed!
 * [CCCI] Add ROME chip version by API instead compile option
 *
 * removed!
 * removed!
 * [CCCI] Fix CCCI direct SM size
 *
 * removed!
 * removed!
 * [CCCI] Add & Maintain UT code
 *
 * removed!
 * removed!
 * [CCCI] Provide CCCI direct write SM API
 *
 * removed!
 * removed!
 * [CCCI EXPT] To avoid K2 MD2 build error, remove the compile error of boot up trace register
 *
 * removed!
 * removed!
 * [CCCI EXPT] To avoid K2 MD2 build error, remove the compile error of boot up trace register
 *
 * removed!
 * removed!
 * [CCCI exception]  Add to send msg in ccci_exception_info_passed for printing 2k shm data
 *
 * removed!
 * removed!
 * 	Add Step info in exception mode
 *
 * removed!
 * removed!
 * [CCCI EXPT] Add boot up trace API for 82lte
 *
 * removed!
 * removed!
 * [CCCI EXPT] Add cache invalidate after received exception RX gpd due to CCCI is first user.
 *
 * removed!
 * removed!
 * [CCCI] Change exception flow.
 *
 * removed!
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * [CCCI] Provide CCCI writes ex_log_ptr to share memory API
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * [CCCI] Solve polling gpd caused memory corruption in MT6595.
 * Solutiin: For MT6595_S00, increase static buffer size (add QBM_HEAD_SIZE) and polling
 *  gpd offeset to the size.
 *
 * removed!
 * removed!
 * [CCCI] Solve boottrc API MODIS build error.
 *
 * removed!
 * removed!
 * 	Shrink CCCI UL/DL buffer to 3.5KB
 *
 * removed!
 * removed!
 * 	workaround for MMDS_DC
 *
 * removed!
 * removed!
 * [CCCI] Modify CCIF SRAM address for bootup trace.
 *
 * removed!
 * removed!
 * 1. Provide CCCI debug info & boot trace capability.
 * 2. Provide CCCI MISC info capability (for MD need to get random seed from AP).
 *
 * removed!
 * removed!
 * [CCCI] Add exception debug info & boot trace.
 *
 * 12 10 2013 box.wu
 * removed!
 * [ECCCI] exception done
 *
 * 11 26 2013 box.wu
 * removed!
 * add exception, tty, ICUSB.
 *
 * removed!
 * removed!
 * 	add compile option to prevent redundant exception state check
 *
 * removed!
 * removed!
 * 	1. revise ccci exception handshake I/O
 * 	2. add global variable state for debugging
 *
 * removed!
 * removed!
 * 	.
 *
 * 09 10 2013 ap.wang
 * removed!
 * 	Add compile option for hosted dongle
 *
 * 07 15 2013 ap.wang
 * removed!
 * [CCCI_EXCEPTION] Fix MoDIS build error
 *
 * 07 15 2013 ap.wang
 * removed!
 * [CCCI_EXCEPTION] Roll back
 *
 * 07 15 2013 ap.wang
 * removed!
 * [CCCI EXCEPTION] Include cache_sw.h
 *
 * 07 12 2013 ap.wang
 * removed!
 * [CCCI EXCEPTION] exception integration
 *
 * removed!
 * removed!
 * [MOLY][CCCI_SDIO] 1st version of MT6290 CCCI feature
 ****************************************************************************/

#if 0 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
#include "ccci_if.h"
#include "ccci_except.h"
#include "cccidev_qbm.h"
#include "ex_item.h"
#include "cache_sw.h"        //for CPU_CACHE_LINE_SIZE

#if defined(__HIF_SDIO_SUPPORT__)
#include "hif_sdio_except.h" // include polling API
#endif
#if defined(__HIF_CLDMA_SUPPORT__)
#include "hif_cldma_except.h"
#include "hif_cldma.h"
#endif
#if defined(__CCIFCORE_SUPPORT__)
#include "ccifcore_if.h"
#endif


static ccci_except_ch_inst_t ccci_expt_inst[CCCI_EXPT_USR_MAX];

#define CCCI_EXCEPT_POLLING_MODE_BUF_SZ (3584)// defined by AP SKB restriction
#define CCCI_HS_POLLING_TIMEOUT   10*1000 //10 sec

// The reason + QBM_HEAD_SIZE is for ROME E1, cldma needs to record this buff whether is cacheable or non-cacheable
static kal_uint8 g_ccci_expect_polling_buf_tx[CCCI_EXCEPT_POLLING_MODE_BUF_SZ + QBM_HEAD_SIZE];    //for tx
static kal_uint8 g_ccci_expect_polling_buf_rx[CCCI_EXCEPT_POLLING_MODE_BUF_SZ + QBM_HEAD_SIZE];    //for rx head
static kal_uint8 g_ccci_expect_polling_buf_rx2[CCCI_EXCEPT_POLLING_MODE_BUF_SZ + QBM_HEAD_SIZE];   //for rx tail

static qbm_gpd* ccci_except_polling_gpd_tx = NULL;
static qbm_gpd* ccci_except_polling_gpd_rx= NULL;
static qbm_gpd* ccci_except_polling_gpd_rx2 = NULL;
volatile kal_int32 ccci_exception_check_write_result = CCCI_FAIL;
volatile kal_int32 ccci_exception_info_write_result = CCCI_FAIL;
volatile kal_int32 ccci_exception_handshake_done = CCCI_FAIL;

volatile CCCI_EXPT_STATE_E ccci_exception_state = CCCI_EXPT_INVALID_ST;

#ifdef __SP_BOOTTRC_ENABLE__
#define CCCI_BOOTTRC_GPD_SZ  QBM_HEAD_SIZE + 16 + CPU_CACHE_LINE_SIZE 
static kal_uint8 ccci_boottrc_gpd[CCCI_BOOTTRC_GPD_SZ]; 
#if defined(__MTK_TARGET__)
#define __boottrc_performance_measurement__ // For bootup trace performance measurement
#endif
#ifdef __boottrc_performance_measurement__
kal_uint32 ccci_boottrc_max_transmit_time =0;
kal_uint32 ccci_boottrc_min_transmit_time =0xFFFFFFFF;
kal_uint32 ccci_boottrc_avg_transmit_time =0;
kal_uint32 ccci_boottrc_total_transmit_time =0;
kal_uint32 ccci_boottrc_transmit_count = 0;
#endif // __boottrc_performance_measurement__

#endif // __SP_BOOTTRC_ENABLE__

//- Addr/Size for EXCEP Log
kal_uint32 ccci_excep_dbg_log_base_hs2;
kal_uint32 ccci_excep_dbg_log_size_hs2;
CCCI_EXCEP_MEMORY_TYPE ccci_excep_dbg_log_type_hs2;

CCCI_EXCEP_MEMORY_TYPE ccci_excep_memory_type = CCCI_EXCEP_MEMORY_TYPE_MAX;

#undef   X_CCCI_EXCEP_MEMORY_CONF
#define  X_CCCI_EXCEP_MEMORY_CONF(region, length)  length,
static kal_uint32 ccci_excep_memory_region_len[] = 
{ 
    #include "ccci_excep_memory_region.h"
}; 
#undef   X_CCCI_EXCEP_MEMORY_CONF

//#define TEMP_SOLUTION_FOR_INTEGRATION        //This is flag is workaround for triggering clear channel operation manually
#define SWITCH_TO_EXCEPTION_IO               //define this flag to use exception I/O rather than INIT POLLING I/O
#define CCCI_EXCETION_PRE_TEST
//#define WDT_ISR_TEST
/*~~~~~~~~~~FOT WDT TEST~~~~~~~~~~~~~~~*/
#ifdef WDT_ISR_TEST
#include "drv_rstctl.h"

void wdt_test(void){
    rstctl_ext_cfg_t ext_cfg;

        // set watchdog timeout interrupt
        ext_cfg.EXT_RST_EA=1;    //enable EXT_RST
        ext_cfg.MD_POL = 0;            //polarity setting
        ext_cfg.PAD_OUT_EA=1; //output enable. If not enable will be input mode

        drv_rstctl_extrst_setCfg(ext_cfg);

        //reset after 5 sec
        drv_rstctl_wd_reset(WDT_IRQ_ONLY, RST_MDALL, 0x27100);
}
#endif
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/*Fix modis link error*/
#if !defined(__MTK_TARGET__)
#define ex_init_step_logging
#define ex_set_step_logging
#define ex_fire_extern_step_logging
#endif


/*************************************************************************
* FUNCTION
*  void ccci_except_ack
*
* DESCRIPTION
*  This function use to as a ack funtion when exception happen
*
* PARAMETERS
*  channel    -    			logical channel
*  *
* RETURNS
*  NA
*
*************************************************************************/
void ccci_except_ack(CCCI_BUFF_T *bufp)
{
    return;
}

/*************************************************************************
* FUNCTION
*  void ccci_exception_info_passed
*
* DESCRIPTION
*  This function .
*
* PARAMETERS
*  channel    -    			logical channel
*  *
* RETURNS
*  The address of the share memory of the input logical channel
*
*************************************************************************/
extern EX_LOG_T *ex_log_ptr;
extern kal_bool INT_QueryExceptionStatus(void);
#if defined (__CCCI_FS_IT__)
    extern void cccifs_it_case();
#endif
void ccci_exception_info_passed(void)
{
#if defined(__MODEM_CCCI_EXIST__)&& !defined(__MODEM_CARD__)  
    CCCI_BUFF_T *buff;
    qbm_gpd *p_first_gpd, *p_last_gpd;
    kal_uint32 gpd_num;

    // ensure in the exception state
    if(INT_QueryExceptionStatus() == KAL_FALSE) return;


    //- Already init in ccci_exception_handshake
    //- ccci_init(CCCI_CONTROL_CHANNEL, ccci_except_ack);
    //- ccci_init(CCCI_CONTROL_CHANNEL_ACK, ccci_except_ack);

    buff = CCCIDEV_GET_QBM_DATAPTR(ccci_except_polling_gpd_tx);
    CCCI_INIT_MAILBOX(buff, CCMSG_ID_EXCEPTION_PASS);
	ccci_debug_add_seq(buff, CCCI_DEBUG_ASSERT_BIT); // add ccci seq
    QBM_DES_SET_DATALEN(ccci_except_polling_gpd_tx, sizeof(CCCI_BUFF_T));
    QBM_DES_SET_DATALEN(ccci_except_polling_gpd_tx->p_data_tbd,  sizeof(CCCI_BUFF_T));
    qbm_cal_set_checksum((kal_uint8 *)ccci_except_polling_gpd_tx);
    qbm_cal_set_checksum((kal_uint8 *)ccci_except_polling_gpd_tx->p_data_tbd);
    QBM_CACHE_FLUSH(ccci_except_polling_gpd_tx, sizeof(qbm_gpd));
    QBM_CACHE_FLUSH(ccci_except_polling_gpd_tx->p_data_tbd, sizeof(qbm_gpd));
    QBM_CACHE_FLUSH(buff, sizeof(CCCI_BUFF_T));

    // TODO:Need to revise the API, shall use exception API (after channle reset flow is done)
#ifdef SWITCH_TO_EXCEPTION_IO
    p_first_gpd = p_last_gpd = ccci_except_polling_gpd_tx;
    ccci_except_set_gpd(CCCI_CONTROL_CHANNEL, p_first_gpd, p_last_gpd);
    gpd_num = 0;
    do{
        ccci_except_hif_st(CCCI_CONTROL_CHANNEL);
        ccci_except_poll_gpd(CCCI_CONTROL_CHANNEL, (void **)&p_first_gpd, (void **)&p_last_gpd, &gpd_num);
    }while(0 == gpd_num);
    ex_set_step_logging(EX_AUTO_STEP); //0x46
    CCCIDEV_RST_CCCI_COMM_GPD_LIST(p_first_gpd, p_last_gpd);
#else
    ccci_exception_info_write_result = ccci_polling_io(CCCI_CONTROL_CHANNEL, ccci_except_polling_gpd_tx, KAL_TRUE);
    CCCIDEV_RST_CCCI_COMM_GPD_LIST(ccci_except_polling_gpd_tx, ccci_except_polling_gpd_tx);
#endif

    ccci_exception_state = CCCI_EXPT_INFO_PASS_ST;
#endif    

#if defined (__CCCI_FS_IT__)
    cccifs_it_case();
#endif
}
void ccci_exception_info_passed_pre(void)  
{
#if defined(__MODEM_CCCI_EXIST__)&& !defined(__MODEM_CARD__)  

    CCCI_BUFF_T *buff;
    qbm_gpd *p_first_gpd, *p_last_gpd;
    kal_uint32 gpd_num;

    // ensure in the exception state
    if(INT_QueryExceptionStatus() == KAL_FALSE) return;


    //- Already init in ccci_exception_handshake
    //- ccci_init(CCCI_CONTROL_CHANNEL, ccci_except_ack);
    //- ccci_init(CCCI_CONTROL_CHANNEL_ACK, ccci_except_ack);

    buff = CCCIDEV_GET_QBM_DATAPTR(ccci_except_polling_gpd_tx);
    buff->data[0] = MD_EX_MAGIC;
    buff->data[1] = CCMSG_ID_EXCEPTION_REC_OK;
    buff->channel = CCCI_CONTROL_CHANNEL;
    buff->reserved = MD_EX_REC_OK_CHK_ID;
    ccci_debug_add_seq(buff, CCCI_DEBUG_ASSERT_BIT); // add ccci seq
    kal_mem_cpy((void*)(buff+1), ex_log_ptr, sizeof(EX_LOG_T));
    QBM_DES_SET_DATALEN(ccci_except_polling_gpd_tx, sizeof(CCCI_BUFF_T) + sizeof(EX_LOG_T));
    QBM_DES_SET_DATALEN(ccci_except_polling_gpd_tx->p_data_tbd,  sizeof(CCCI_BUFF_T) + sizeof(EX_LOG_T));
    qbm_cal_set_checksum((kal_uint8 *)ccci_except_polling_gpd_tx);
    qbm_cal_set_checksum((kal_uint8 *)ccci_except_polling_gpd_tx->p_data_tbd);
    QBM_CACHE_FLUSH(ccci_except_polling_gpd_tx, sizeof(qbm_gpd));
    QBM_CACHE_FLUSH(ccci_except_polling_gpd_tx->p_data_tbd, sizeof(qbm_gpd));
    QBM_CACHE_FLUSH(buff, sizeof(CCCI_BUFF_T) + sizeof(EX_LOG_T));

    // TODO:Need to revise the API, shall use exception API (after channle reset flow is done)
#ifdef SWITCH_TO_EXCEPTION_IO
    p_first_gpd = p_last_gpd = ccci_except_polling_gpd_tx;
    ccci_except_set_gpd(CCCI_CONTROL_CHANNEL, p_first_gpd, p_last_gpd);
    gpd_num = 0;
    do{
        ccci_except_hif_st(CCCI_CONTROL_CHANNEL);
        ccci_except_poll_gpd(CCCI_CONTROL_CHANNEL, (void **)&p_first_gpd, (void **)&p_last_gpd, &gpd_num);
    }while(0 == gpd_num);
    ex_set_step_logging(EX_AUTO_STEP); //0x45
    CCCIDEV_RST_CCCI_COMM_GPD_LIST(p_first_gpd, p_last_gpd);
#else
    ccci_exception_info_write_result = ccci_polling_io(CCCI_CONTROL_CHANNEL, ccci_except_polling_gpd_tx, KAL_TRUE);
    CCCIDEV_RST_CCCI_COMM_GPD_LIST(ccci_except_polling_gpd_tx, ccci_except_polling_gpd_tx);
#endif

    ccci_exception_state = CCCI_EXPT_INFO_PASS_PRE_ST;
    #ifdef WDT_ISR_TEST
    wdt_test();
    #endif
#endif    
}

/*************************************************************************
* FUNCTION
*  void ccci_exception_handshake
*
* DESCRIPTION
*  This function .
*
* PARAMETERS
*  channel    -    			logical channel
*  *
* RETURNS
*  The address of the share memory of the input logical channel
*
*************************************************************************/
void ccci_exception_handshake(void){
#if defined(__MODEM_CCCI_EXIST__)&& !defined(__MODEM_CARD__) 
    CCCI_BUFF_T  *buff;
    kal_uint32   p_cache_aligned;
    kal_uint32 gpd_num;
    qbm_gpd *p_first_gpd, *p_last_gpd;
    //kal_uint32   rcv_size = 0; 
    // ensure in the exception state
    if(INT_QueryExceptionStatus() == KAL_FALSE) 
        return;

    //we block here for debuging
    //if(ccci_exception_state != CCCI_EXPT_CLEAR_CH_ST) while(1);
    //- Avoid to use kal_mem_cpy
    //- HW bug

    ccci_init(CCCI_CONTROL_CHANNEL, ccci_except_ack);
    ccci_init(CCCI_CONTROL_CHANNEL_ACK, ccci_except_ack);

    // exception only have single thread, need to do polling mode
    /* initialize polling mode GPD */
    ASSERT(CCCI_EXCEPT_POLLING_MODE_BUF_SZ >= 2*CPU_CACHE_LINE_SIZE);
    /*make p_gpd aligned to CPU_CACHE_LINE_SIZE_MASK*/

    p_cache_aligned = (kal_uint32)g_ccci_expect_polling_buf_tx;
    if(p_cache_aligned&CPU_CACHE_LINE_SIZE_MASK) { 
        p_cache_aligned = ((kal_uint32)(g_ccci_expect_polling_buf_tx)&~CPU_CACHE_LINE_SIZE_MASK);
        p_cache_aligned += CPU_CACHE_LINE_SIZE;
    }
    
    // The reason + QBM_HEAD_SIZE is for ROME E1, cldma needs to record this buff whether is cacheable or non-cacheable
	ccci_except_polling_gpd_tx = (qbm_gpd *)(p_cache_aligned + QBM_HEAD_SIZE);

    CCCIDEV_RST_CCCI_COMM_GPD_LIST(ccci_except_polling_gpd_tx, ccci_except_polling_gpd_tx);

    //format Rx GPD
    p_cache_aligned = (kal_uint32)g_ccci_expect_polling_buf_rx;
    if(p_cache_aligned&CPU_CACHE_LINE_SIZE_MASK) { 
        p_cache_aligned = ((kal_uint32)(g_ccci_expect_polling_buf_rx)&~CPU_CACHE_LINE_SIZE_MASK);
        p_cache_aligned += CPU_CACHE_LINE_SIZE;
    }
    
    // The reason + QBM_HEAD_SIZE is for ROME E1, cldma needs to record this buff whether is cacheable or non-cacheable
	ccci_except_polling_gpd_rx = (qbm_gpd *)(p_cache_aligned + QBM_HEAD_SIZE);

    CCCIDEV_RST_CCCI_COMM_GPD_LIST(ccci_except_polling_gpd_rx, ccci_except_polling_gpd_rx);

    //format Rx 2nd GPD
    p_cache_aligned = (kal_uint32)g_ccci_expect_polling_buf_rx2;
    if(p_cache_aligned&CPU_CACHE_LINE_SIZE_MASK) { 
        p_cache_aligned = ((kal_uint32)(g_ccci_expect_polling_buf_rx2)&~CPU_CACHE_LINE_SIZE_MASK);
        p_cache_aligned += CPU_CACHE_LINE_SIZE;
    }
    
    // The reason + QBM_HEAD_SIZE is for ROME E1, cldma needs to record this buff whether is cacheable or non-cacheable
	ccci_except_polling_gpd_rx2 = (qbm_gpd *)(p_cache_aligned + QBM_HEAD_SIZE);

    CCCIDEV_RST_CCCI_COMM_GPD_LIST(ccci_except_polling_gpd_rx2, ccci_except_polling_gpd_rx2);

    //step 0. config rx gpd next pointer
    QBM_DES_SET_NEXT(ccci_except_polling_gpd_rx, ccci_except_polling_gpd_rx2);

    //step 1. send TX handshake pkt
    buff = CCCIDEV_GET_QBM_DATAPTR(ccci_except_polling_gpd_tx);
    
    buff->data[0] = MD_EX_MAGIC;
    buff->data[1] = CCMSG_ID_EXCEPTION_CHECK;
    buff->channel = CCCI_CONTROL_CHANNEL;
    buff->reserved = MD_EX_CHK_ID;
    ccci_debug_add_seq(buff, CCCI_DEBUG_ASSERT_BIT); // add ccci seq
    QBM_DES_SET_DATALEN(ccci_except_polling_gpd_tx, sizeof(CCCI_BUFF_T));
    QBM_DES_SET_DATALEN(ccci_except_polling_gpd_tx->p_data_tbd,  sizeof(CCCI_BUFF_T));
    qbm_cal_set_checksum((kal_uint8 *)ccci_except_polling_gpd_tx);
    qbm_cal_set_checksum((kal_uint8 *)ccci_except_polling_gpd_tx->p_data_tbd);
    QBM_CACHE_FLUSH(ccci_except_polling_gpd_tx, sizeof(qbm_gpd));
    QBM_CACHE_FLUSH(ccci_except_polling_gpd_tx->p_data_tbd, sizeof(qbm_gpd));
    QBM_CACHE_FLUSH(buff, sizeof(CCCI_BUFF_T));

    ex_set_step_logging(EX_AUTO_STEP); //0x41

    //step 2. polling echoed rx handshake pkt (need two GPD, one for tail)
    // TODO:Need to revise the API, shall use exception API (after channle reset flow is done)
#ifdef SWITCH_TO_EXCEPTION_IO
    p_first_gpd = p_last_gpd = ccci_except_polling_gpd_tx;
    ccci_except_set_gpd(CCCI_CONTROL_CHANNEL, p_first_gpd, p_last_gpd);
    gpd_num = 0;
    do{
        ccci_except_hif_st(CCCI_CONTROL_CHANNEL);
        ccci_except_poll_gpd(CCCI_CONTROL_CHANNEL, (void **)&p_first_gpd, (void **)&p_last_gpd, &gpd_num);
    }while(0 == gpd_num);
    CCCIDEV_RST_CCCI_COMM_GPD_LIST(p_first_gpd, p_last_gpd);

    ex_set_step_logging(EX_AUTO_STEP); //0x42
    
    p_first_gpd = ccci_except_polling_gpd_rx;
    p_last_gpd = ccci_except_polling_gpd_rx2;
    do{
        ccci_except_set_gpd(CCCI_CONTROL_CHANNEL_ACK, p_first_gpd, p_last_gpd);
        gpd_num = 0;
        do{
            ccci_except_hif_st(CCCI_CONTROL_CHANNEL_ACK);
            ccci_except_poll_gpd(CCCI_CONTROL_CHANNEL_ACK, (void **)&p_first_gpd, (void **)&p_last_gpd, &gpd_num);
        }while(0 == gpd_num);
        buff = CCCIDEV_GET_QBM_DATAPTR(ccci_except_polling_gpd_rx);
        //rcv_size = CCCIDEV_GET_QBM_DATALEN(ccci_except_polling_gpd_rx); // FIXME
        QBM_CACHE_INVALID(buff, sizeof(CCCI_BUFF_T));
        ccci_debug_check_seq(buff); // check ccci seq
        if (buff->reserved == MD_EX_CHK_ID){
            ex_set_step_logging(EX_AUTO_STEP);  //0x43
            ccci_exception_handshake_done = KAL_TRUE;
            CCCIDEV_RST_CCCI_COMM_GPD_LIST(p_first_gpd, p_last_gpd);
            ccci_except_set_gpd(CCCI_CONTROL_CHANNEL_ACK, p_first_gpd, p_last_gpd);  //reload to CCCI_CONTROL_CHANNEL_ACK
            break;
        }
        else
        {
            //dump date
            ex_fire_extern_step_logging(0xFFFFFFFF);
            ex_fire_extern_step_logging(buff->data[0]);
            ex_fire_extern_step_logging(buff->data[1]);
            ex_fire_extern_step_logging(buff->channel);
            ex_fire_extern_step_logging(buff->reserved);
            ex_fire_extern_step_logging(0xFFFFFFFF);
        }
        CCCIDEV_RST_CCCI_COMM_GPD_LIST(p_first_gpd, p_last_gpd);
    }while(1);
    
#else     
    ccci_exception_check_write_result = ccci_polling_io(CCCI_CONTROL_CHANNEL, ccci_except_polling_gpd_tx, KAL_TRUE);
    CCCIDEV_RST_CCCI_COMM_GPD_LIST(ccci_except_polling_gpd_tx, ccci_except_polling_gpd_tx);

    while(CCCI_SUCCESS == (ccci_exception_handshake_done = ccci_polling_io(CCCI_CONTROL_CHANNEL_ACK, ccci_except_polling_gpd_tx, KAL_FALSE))){
        buff = CCCIDEV_GET_QBM_DATAPTR(ccci_except_polling_gpd_tx);
        QBM_CACHE_INVALID(buff, sizeof(CCCI_BUFF_T));
        ccci_debug_check_seq(buff); // check ccci seq
        if (buff->reserved == MD_EX_CHK_ID){
            CCCIDEV_RST_CCCI_COMM_GPD_LIST(ccci_except_polling_gpd_tx, ccci_except_polling_gpd_tx);
            break;
        }
        CCCIDEV_RST_CCCI_COMM_GPD_LIST(ccci_except_polling_gpd_tx, ccci_except_polling_gpd_tx);
    }
#endif    
    ex_set_step_logging(EX_AUTO_STEP);  //0x44
    ccci_exception_state = CCCI_EXPT_HANDSHAKE_ST;
#ifdef CCCI_EXCETION_PRE_TEST
    ccci_exception_info_passed_pre();
#endif    

#endif
}


ccci_except_ch_inst_t *get_ch_expt_inst(kal_uint32 ccci_ch)
{
    switch(ccci_ch){
        case CCCI_FS_CHANNEL:
        {
            return &ccci_expt_inst[CCCI_EXPT_FS_DL];
        }
        break;
        case CCCI_FS_ACK_CHANNEL:
        {
            return &ccci_expt_inst[CCCI_EXPT_FS_UL];
        }
        break;
        case CCCI_TST_CHANNEL:
        {
            return &ccci_expt_inst[CCCI_EXPT_DHL_CTRL_DL];
        }
        break;
        case CCCI_TR_CHANNEL:    
        {
            return &ccci_expt_inst[CCCI_EXPT_DHL_CTRL_UL];
        }
        break;
        case CCCI_MD_LOG_RX:
        {
            return &ccci_expt_inst[CCCI_EXPT_DHL_DL];
        }
        break;
        case CCCI_MD_LOG_TX:
        {
            return &ccci_expt_inst[CCCI_EXPT_DHL_UL];
        }
        break;
        case CCCI_CONTROL_CHANNEL:
        {
            return &ccci_expt_inst[CCCI_EXPT_CTRL_DL];
        }
        break;
        case CCCI_CONTROL_CHANNEL_ACK:
        {
            return &ccci_expt_inst[CCCI_EXPT_CTRL_UL];
        }
        break;
        default:
            return NULL;
    }
}
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
#endif
/*!
 *  @brief ccci_except_init: Exception Mode Initialization Function, 
 *         called by CCCITTY when receiving TTY_CMD_EXCEPTION_HIF_INIT
 *
 *  @param ch_dhl_dl  [IN] DHL CCCI donwlink channel 
 *  @param ch_dhl_ul  [IN] DHL CCCI uplink channel 
 *
 *  @return CCCI error code, CCCI_RETURNVAL_T. 
 *          Always return CCCI_SUCCESS
 */
kal_int32 ccci_except_init(kal_uint32 ch_dhl_dl, kal_uint32 ch_dhl_ul)
{
    ccci_ch_handle *dhl_dl_ch_handle, *dhl_ctrl_dl_ch_handle, *fs_dl_ch_handle;
    ccci_hw_apis  *tmp_hif_apis;
    ccci_hif_expt_apis *dhl_hif_apis, *dhl_ctrl_hif_apis, *fs_hif_apis;
    kal_uint32     dhl_dl_q_bmap = 0;
    kal_uint32     expt_q_bmap   = 0;
    kal_uint32     tmp_dl_bmap   = 0;
    kal_uint32     tmp_ul_bmap   = 0;

    //4 1. Init. the hif_expt_apis
    dhl_dl_ch_handle      = ccci_get_ch_info(ch_dhl_dl);
    dhl_ctrl_dl_ch_handle = ccci_get_ch_info(CCCI_TST_CHANNEL);
    fs_dl_ch_handle       = ccci_get_ch_info(CCCI_FS_CHANNEL); 

    tmp_hif_apis      = ccci_get_hw_handle_api(dhl_dl_ch_handle->hw_type_predifined);
    dhl_hif_apis      = tmp_hif_apis->hif_expt_apis;
    tmp_hif_apis      = ccci_get_hw_handle_api(dhl_ctrl_dl_ch_handle->hw_type_predifined);
    dhl_ctrl_hif_apis = tmp_hif_apis->hif_expt_apis;
    tmp_hif_apis      = ccci_get_hw_handle_api(fs_dl_ch_handle->hw_type_predifined);
    fs_hif_apis       = tmp_hif_apis->hif_expt_apis;

    ccci_expt_inst[CCCI_EXPT_DHL_DL].ccci_ch            = ch_dhl_dl;
    ccci_expt_inst[CCCI_EXPT_DHL_DL].qno                = CCCI_EXPT_DHL_TXRX_HIF_QNO;
    ccci_expt_inst[CCCI_EXPT_DHL_DL].hwq_type           = CCCI_TYPE_TX;
    ccci_expt_inst[CCCI_EXPT_DHL_DL].hw_type            = dhl_dl_ch_handle->hw_type_predifined;
    ccci_expt_inst[CCCI_EXPT_DHL_DL].hif_expt_apis      = dhl_hif_apis;

    ccci_expt_inst[CCCI_EXPT_DHL_UL].ccci_ch            = ch_dhl_ul;
    ccci_expt_inst[CCCI_EXPT_DHL_UL].qno                = CCCI_EXPT_DHL_TXRX_HIF_QNO;
    ccci_expt_inst[CCCI_EXPT_DHL_UL].hwq_type           = CCCI_TYPE_RX;
    ccci_expt_inst[CCCI_EXPT_DHL_UL].hw_type            = dhl_dl_ch_handle->hw_type_predifined;
    ccci_expt_inst[CCCI_EXPT_DHL_UL].hif_expt_apis      = dhl_hif_apis;

    ccci_expt_inst[CCCI_EXPT_DHL_CTRL_DL].ccci_ch       = CCCI_TST_CHANNEL;
    ccci_expt_inst[CCCI_EXPT_DHL_CTRL_DL].qno           = CCCI_EXPT_DHL_CTRL_TXRX_HIF_QNO;
    ccci_expt_inst[CCCI_EXPT_DHL_CTRL_DL].hwq_type      = CCCI_TYPE_TX;
    ccci_expt_inst[CCCI_EXPT_DHL_CTRL_DL].hw_type       = dhl_dl_ch_handle->hw_type_predifined;
    ccci_expt_inst[CCCI_EXPT_DHL_CTRL_DL].hif_expt_apis = dhl_ctrl_hif_apis;

    ccci_expt_inst[CCCI_EXPT_DHL_CTRL_UL].ccci_ch       = CCCI_TR_CHANNEL;
    ccci_expt_inst[CCCI_EXPT_DHL_CTRL_UL].qno           = CCCI_EXPT_DHL_CTRL_TXRX_HIF_QNO;
    ccci_expt_inst[CCCI_EXPT_DHL_CTRL_UL].hwq_type      = CCCI_TYPE_RX;
    ccci_expt_inst[CCCI_EXPT_DHL_CTRL_UL].hw_type       = dhl_dl_ch_handle->hw_type_predifined;
    ccci_expt_inst[CCCI_EXPT_DHL_CTRL_UL].hif_expt_apis = dhl_ctrl_hif_apis;

    ccci_expt_inst[CCCI_EXPT_FS_DL].ccci_ch             = CCCI_FS_CHANNEL;
    ccci_expt_inst[CCCI_EXPT_FS_DL].qno                 = CCCI_EXPT_FS_TXRX_HIF_QNO;
    ccci_expt_inst[CCCI_EXPT_FS_DL].hwq_type            = CCCI_TYPE_TX;
    ccci_expt_inst[CCCI_EXPT_FS_DL].hw_type             = fs_dl_ch_handle->hw_type_predifined;
    ccci_expt_inst[CCCI_EXPT_FS_DL].hif_expt_apis       = fs_hif_apis;

    ccci_expt_inst[CCCI_EXPT_FS_UL].ccci_ch             = CCCI_FS_ACK_CHANNEL;
    ccci_expt_inst[CCCI_EXPT_FS_UL].qno                 = CCCI_EXPT_FS_TXRX_HIF_QNO;
    ccci_expt_inst[CCCI_EXPT_FS_UL].hwq_type            = CCCI_TYPE_RX;
    ccci_expt_inst[CCCI_EXPT_FS_UL].hw_type             = fs_dl_ch_handle->hw_type_predifined;
    ccci_expt_inst[CCCI_EXPT_FS_UL].hif_expt_apis       = fs_hif_apis;

    /* assume control use the same HW as FS */
    ccci_expt_inst[CCCI_EXPT_CTRL_DL].ccci_ch             = CCCI_CONTROL_CHANNEL;
    ccci_expt_inst[CCCI_EXPT_CTRL_DL].qno                 = CCCI_EXPT_CTRL_TXRX_HIF_QNO;
    ccci_expt_inst[CCCI_EXPT_CTRL_DL].hwq_type            = CCCI_TYPE_TX;
    ccci_expt_inst[CCCI_EXPT_CTRL_DL].hw_type             = fs_dl_ch_handle->hw_type_predifined;
    ccci_expt_inst[CCCI_EXPT_CTRL_DL].hif_expt_apis       = fs_hif_apis;

    ccci_expt_inst[CCCI_EXPT_CTRL_UL].ccci_ch             = CCCI_CONTROL_CHANNEL_ACK;
    ccci_expt_inst[CCCI_EXPT_CTRL_UL].qno                 = CCCI_EXPT_CTRL_TXRX_HIF_QNO;
    ccci_expt_inst[CCCI_EXPT_CTRL_UL].hwq_type            = CCCI_TYPE_RX;
    ccci_expt_inst[CCCI_EXPT_CTRL_UL].hw_type             = fs_dl_ch_handle->hw_type_predifined;
    ccci_expt_inst[CCCI_EXPT_CTRL_UL].hif_expt_apis       = fs_hif_apis;

    //4 2. hif_except_que_setting inform HIF driver about the exception que id
    if(ccci_expt_inst[CCCI_EXPT_DHL_DL].hw_type == ccci_expt_inst[CCCI_EXPT_FS_DL].hw_type){
        /* DHL and NVRAM using the same HIF driver */
        /* ccci_ctrl_pool might not initialize when assert happen, use predefined value ccci_ch_info*/
        dhl_dl_q_bmap = (1 << ccci_expt_inst[CCCI_EXPT_DHL_DL].qno);

        /* Exception DL queue bitmap */
        tmp_dl_bmap   = (1 << ccci_expt_inst[CCCI_EXPT_FS_DL].qno);
        tmp_dl_bmap  |= (1 << ccci_expt_inst[CCCI_EXPT_DHL_DL].qno);
        tmp_dl_bmap  |= (1 << ccci_expt_inst[CCCI_EXPT_DHL_CTRL_DL].qno);
        tmp_dl_bmap  |= (1 << ccci_expt_inst[CCCI_EXPT_CTRL_DL].qno);

        /* DHL queue number */
        tmp_ul_bmap   = (1 << ccci_expt_inst[CCCI_EXPT_DHL_UL].qno);
        tmp_ul_bmap  |= (1 << ccci_expt_inst[CCCI_EXPT_FS_UL].qno);
        tmp_ul_bmap  |= (1 << ccci_expt_inst[CCCI_EXPT_DHL_CTRL_UL].qno);
        tmp_ul_bmap  |= (1 << ccci_expt_inst[CCCI_EXPT_CTRL_UL].qno);

        expt_q_bmap   = (tmp_dl_bmap | (tmp_ul_bmap << 16));
        
        dhl_hif_apis->hif_expt_init(dhl_dl_q_bmap, expt_q_bmap);
    }else{
        /* DHL and NVRAM using different HIF driver */

        //4 2.1.1 DHL HIF queue intialization
        dhl_dl_q_bmap = (1 << ccci_expt_inst[CCCI_EXPT_DHL_DL].qno);
        tmp_dl_bmap   = dhl_dl_q_bmap;
        tmp_dl_bmap  |= (1 << ccci_expt_inst[CCCI_EXPT_DHL_CTRL_DL].qno);
        tmp_ul_bmap   = (1 << ccci_expt_inst[CCCI_EXPT_DHL_UL].qno);
        tmp_ul_bmap  |= (1 << ccci_expt_inst[CCCI_EXPT_DHL_CTRL_DL].qno);
        expt_q_bmap   = (tmp_dl_bmap | (tmp_ul_bmap << 16));        
        
        dhl_hif_apis->hif_expt_init(dhl_dl_q_bmap, expt_q_bmap);

        //4 2.1.2 NVRAM HIF queue intialization
        tmp_dl_bmap   = (1 << ccci_expt_inst[CCCI_EXPT_FS_DL].qno);
        tmp_dl_bmap  |= (1 << ccci_expt_inst[CCCI_EXPT_CTRL_DL].qno);
        tmp_ul_bmap   = (1 << ccci_expt_inst[CCCI_EXPT_FS_UL].qno);
        tmp_ul_bmap  |= (1 << ccci_expt_inst[CCCI_EXPT_CTRL_UL].qno);        
        expt_q_bmap   = (tmp_dl_bmap | (tmp_ul_bmap << 16));        
        
        fs_hif_apis->hif_expt_init(0, expt_q_bmap);
    }

    // Reset all ccci seq record
    ccci_debug_reset_seq_data();    
    return CCCI_SUCCESS;
}

/*!
 *  @brief ccci_except_init_hmu: Warpper function of ccci_except_init
 *         called by hmu_except_init
 *
 *  @return CCCI error code, CCCI_RETURNVAL_T. 
 *          Always return CCCI_SUCCESS
 */
kal_int32 ccci_except_init_hmu(kal_uint32 dev_mapping, kal_uint32 ext_devinfo_len, kal_char * ext_devinfo){

    //If CCCI has done exception init, just return
    //Currently, exception handshake is done before exception init. 
#ifdef SWITCH_TO_EXCEPTION_IO
    if(ccci_exception_state != CCCI_EXPT_INVALID_ST) return CCCI_SUCCESS;
#endif

#if !(defined(ATEST_SYS_CCCI) || defined(ATEST_SYS_SDIOC))
    cccitty_dev_expt_init();
    ccci_exception_state = CCCI_EXPT_INIT_CCCITTY_DEV_ST;
    // TODO: Temprorarily disable fs feature
    //ccci_fs_svc_expt_init();
#endif
    ex_fire_extern_step_logging(CCCI_DBG_EXPT_INIT);
    ccci_except_init(CCCI_MD_LOG_RX, CCCI_MD_LOG_TX);
    ccci_exception_state = CCCI_EXPT_INIT_ST;

#ifdef TEMP_SOLUTION_FOR_INTEGRATION  //this action shall be triggered by DHL clear q cmd
    cccitty_ttyc_hdr_expt_clear_ch(uart_port_dhl_ccci);
#endif

    return CCCI_SUCCESS;
}

/*!
 *  @brief ccci_except_clear_ch: Exception Mode Clear channel function
 *                           called by CCCITTY when receiving TTY_CMD_EXCEPTION_CLEAR_CHANNEL
 *
 *  @param ccci_ch    [IN] DHL CCCI donwlink/uplink channel 
 *
 *  @return CCCI error code, CCCI_RETURNVAL_T. 
 *          Always return CCCI_SUCCESS, since TTYcore ignore it
 */
kal_int32 ccci_except_clear_ch(kal_uint32 ccci_ch)
{
    ccci_except_ch_inst_t *expt_inst;
    kal_bool ret = KAL_FALSE;
    
    ex_fire_extern_step_logging((CCCI_DBG_EXPT_CLR_CH | (ccci_ch << 8)));
    expt_inst = get_ch_expt_inst(ccci_ch);
	if(expt_inst != NULL)
        ret = expt_inst->hif_expt_apis->hif_expt_clear_q(expt_inst->hwq_type, expt_inst->qno);

    return ((KAL_TRUE == ret) ? CCCI_SUCCESS:CCCI_FAIL);
}

/*!
 *  @brief ccci_except_set_gpd: Exception Mode DL/UL reload Function,
 *                           called by CCCITTY when receiving TTY_CMD_EXCEPTION_TX_GPD/TTY_CMD_EXCEPTION_ASSIGN_RX_GPD
 *                           Note: For DL the CCCI header in TGPD should be prepared by the caller!!!
 *
 *  @param expt_ch    [IN] exception mode ccci channel
 *  @param p_first_gpd[IN] pointer of first dl gpd
 *  @param p_last_gpd [IN] pointer of last dl gpd
 *
 *  @return CCCI error code, CCCI_RETURNVAL_T. 
 *          Always return CCCI_SUCCESS, since TTYcore ignore it
 */
kal_int32 ccci_except_set_gpd(kal_uint32 expt_ch, void *p_first_gpd, void *p_last_gpd)
{
    ccci_except_ch_inst_t *expt_inst;
    kal_bool ret = KAL_FALSE;

    expt_inst = get_ch_expt_inst(expt_ch);
	if(expt_inst != NULL)
        ret = expt_inst->hif_expt_apis->hif_expt_set_gpd(expt_inst->hwq_type, expt_inst->qno, p_first_gpd, p_last_gpd);
    //send uart debug log if NG case 
    if(ret != KAL_TRUE)
    {
        ex_fire_extern_step_logging((CCCI_DBG_EXPT_SET_GPD | (0xFF<<8)));
    }

    return ((KAL_TRUE == ret) ? CCCI_SUCCESS:CCCI_FAIL);
}

/*!
 *  @brief ccci_except_poll_gpd: Exception Mode Reclaim DL Done/UL GPDs
 *                           called by CCCITTY when receiving TTY_CMD_EXCEPTION_TX_DONE_INFO/TTY_CMD_EXCEPTION_GET_RX_GPD

 *
 *  @param expt_ch      [IN]  exception mode ccci channel
 *  @param pp_first_gpd [OUT] pointer of first_gpd_pointer
 *  @param pp_last_gpd  [OUT] pointer of last_gpd_pointer
 *  @param gpd_num      [OUT] pointer of number of gpd returned by hif
 *
 *  @return CCCI error code, CCCI_RETURNVAL_T. 
 *          Always return CCCI_SUCCESS, since TTYcore ignore it
 */
kal_int32 ccci_except_poll_gpd(kal_uint32 expt_ch, void **pp_first_gpd, void **pp_last_gpd, kal_uint32 *gpd_num)
{
    kal_int32           hif_expt_ret = KAL_FALSE;
    ccci_except_ch_inst_t *expt_inst;

    expt_inst = get_ch_expt_inst(expt_ch);
	if(expt_inst != NULL)
        hif_expt_ret = expt_inst->hif_expt_apis->hif_expt_poll_gpd(expt_inst->hwq_type, expt_inst->qno, pp_first_gpd, pp_last_gpd);
    if(hif_expt_ret < 0){
        *gpd_num = 0;
    }else{
        *gpd_num = hif_expt_ret;
    }
    return CCCI_SUCCESS; 
}

/*!
 *  @brief ccci_except_hif_st: Exception Mode Query HIF Driver State
 *                           called by CCCITTY when receiving TTY_CMD_EXCEPTION_HIF_STATE
 *                           to query if HIF driver allow the dl TGPDs in exception mode
 *
 *  @param expt_dl_ch   [IN]  exception mode dl ccci channel
 *
 *  @return CCCI error code, CCCI_RETURNVAL_T.
 *                           CCCI_SUCCESS: HIF allows the dl traffic
 *                           CCCI_FAIL:    HIF declines the dl traffic
 */
kal_int32 ccci_except_hif_st(kal_uint32 expt_dl_ch)
{
    ccci_except_ch_inst_t *expt_inst;
    kal_bool ret = KAL_FALSE;

    expt_inst = get_ch_expt_inst(expt_dl_ch);
	if(expt_inst != NULL)
        ret = expt_inst->hif_expt_apis->hif_expt_link_st(expt_inst->hwq_type, expt_inst->qno);

    if(ret != KAL_TRUE)
    {
        ex_fire_extern_step_logging((CCCI_DBG_EXPT_HIF_ST | (0xFF<<8)));
    }
 
    return ((KAL_TRUE == ret) ? CCCI_SUCCESS:CCCI_FAIL);
}

/*!
 *  @brief ccci_except_hif_st: Trigger HIF Driver to handle the ISR during the exception mode
 *                           called by CCCITTY when receiving TTY_CMD_EXCEPTION_HIF_POLL
 *
 *  @return CCCI error code, CCCI_RETURNVAL_T. 
 *          Always return CCCI_SUCCESS, since TTYcore ignore it
 */
kal_int32 ccci_except_hif_isr(kal_uint32 expt_dl_ch)
{
    ccci_except_ch_inst_t *expt_inst;
    kal_bool ret = KAL_FALSE;

    expt_inst = get_ch_expt_inst(expt_dl_ch);
	if(expt_inst != NULL)
        ret = expt_inst->hif_expt_apis->hif_expt_hif_isr();
    if(KAL_TRUE != ret)
    {
        ex_fire_extern_step_logging((CCCI_DBG_EXPT_HIF_ISR | (0xFF<<8)));
    }

    return ((KAL_TRUE == ret) ? CCCI_SUCCESS:CCCI_FAIL);
}

/*************************************************************************
* FUNCTION
*  kal_int32 ccci_excep_dbg_logging_InHS2
*
* DESCRIPTION
*  This function is used to write log to CCCI Exception Memory
*  The function only supports 4bytes align debug info currently
*
* PARAMETERS
*  log_type    - Log type
*  state_info  - Idle task state information
*  *
* RETURNS
*  The address of the share memory of the input logical channel
*
*************************************************************************/
kal_int32 ccci_excep_dbg_logging_InHS2(kal_uint32 index, void* addr)
{

    static kal_uint32       magic_number_valid_hs = 0;
    kal_uint32              dst_addr;
    ccci_excep_dbg_hdr_t    *hdr_ptr;

    if (addr == NULL || ((kal_uint32)addr % 4 !=0) || index >= CCCI_EXCEP_DBG_HS_LOG_MAX || (kal_uint32 *)ccci_excep_dbg_log_base_hs2 == NULL)
        return CCCI_FAIL;
    
    hdr_ptr = (ccci_excep_dbg_hdr_t*)ccci_excep_dbg_log_base_hs2;
    
    //- if magic number is not written, set magic number at first two words
    if (magic_number_valid_hs == 0)
    {
        magic_number_valid_hs = 1;
        hdr_ptr->magic_number_l = CCCI_EXCEP_DBG_INDICATOR_L;
        hdr_ptr->magic_number_h = CCCI_EXCEP_DBG_INDICATOR_H;
    }

    //- yy: Current excep dbg only support 4 bytes, so the address of log will be ccci_excep_dbg_log_base + 0x10 + index * 4
    //-     Each index use one word.
    dst_addr = ccci_excep_dbg_log_base_hs2 + sizeof(ccci_excep_dbg_hdr_t) + index * 4;
    
    if (dst_addr > ccci_excep_dbg_log_base_hs2 + ccci_excep_dbg_log_size_hs2)
        return CCCI_FAIL;
    
    *((volatile kal_uint32 *)dst_addr) = *((kal_uint32 *)addr);
    
    //- write last index
    hdr_ptr->last_write_index = (0x70000000 | index);
    
    //- read to device type memory to ensure data is drained to EMI.
    dst_addr = *((volatile kal_uint32 *)(ccci_excep_dbg_log_base_hs2));

    return CCCI_SUCCESS;
}

#ifdef __SP_BOOTTRC_ENABLE__
/*************************************************************************
* FUNCTION
*  void ccci_boottrc_send_log
*
* DESCRIPTION
*  This function is exported API to write bootup trace log in shared buffer.
*
* PARAMETERS
*  index - bootup trace log key.
*  value - bootup trace log value.
*
* RETURNS
*  NA
*
*************************************************************************/
void ccci_boottrc_send_log(kal_uint32 index, kal_uint32 value)
{
#if defined(__MTK_TARGET__)
#ifdef __boottrc_performance_measurement__
	kal_uint32 ccci_boottrc_start_time =0;
	kal_uint32 ccci_boottrc_end_time =0;
	kal_uint32 ccci_boottrc_dur_time =0;
	ccci_boottrc_start_time = ccci_get_current_time();
#endif

	qbm_gpd    	*p_gpd;
    void       	*p_cache_aligned;
	CCCI_BUFF_T	*ccci_buff;
	kal_bool    hif_ret;

	p_cache_aligned = ccci_boottrc_gpd;
	if((kal_uint32)p_cache_aligned&CPU_CACHE_LINE_SIZE_MASK) { 
		p_cache_aligned = (void *)((kal_uint32)(ccci_boottrc_gpd)&~CPU_CACHE_LINE_SIZE_MASK);
		p_cache_aligned += CPU_CACHE_LINE_SIZE;
	}
	p_gpd = (qbm_gpd *)p_cache_aligned;
	
	//kal_mem_set(ccci_hs_buff, 0, CCCI_POLLING_MODE_BUF_SZ);
	/* CCCI polling mode, QMU_BM is not ready yet*/ 
	/* format ccci_hs_buff as GPD->BUFF format */
	CCCI_INIT_RESET_DATALEN_EXTLEN((kal_uint32 *)p_gpd);
	CCCI_INIT_RESET_COMMON_DATA((kal_uint32 *)p_gpd);
	ccci_buff = QBM_DES_GET_DATAPTR(p_gpd);
	ccci_buff->data[0] = 0x43525442; // pattern : "BTRC"
	ccci_buff->data[1] = index;
	ccci_buff->channel = CCCI_CONTROL_CHANNEL;
	ccci_buff->reserved = value;
    ccci_debug_add_seq(ccci_buff, CCCI_DEBUG_ASSERT_BIT); // add ccci seq
	QBM_DES_SET_DATALEN(p_gpd, sizeof(CCCI_BUFF_T));
	QBM_CACHE_FLUSH(ccci_buff, sizeof(CCCI_BUFF_T));
    
#if defined(__HIF_SDIO_SUPPORT__)
    hif_ret = hifsdio_simple_send_gpd(0, p_gpd, CCCI_HS_POLLING_TIMEOUT);
#elif defined(__HIF_CLDMA_SUPPORT__)
    hif_ret = hifcldma_simple_send_gpd(0, p_gpd, CCCI_HS_POLLING_TIMEOUT);
#elif defined(__CCIFCORE_SUPPORT__)
    hif_ret = ccifc_simple_send_gpd(0, p_gpd, CCCI_HS_POLLING_TIMEOUT);
#endif

	if(!hif_ret){
		EXT_ASSERT(KAL_FALSE, hif_ret,0,0);
	}

#ifdef __boottrc_performance_measurement__
	ccci_boottrc_end_time = ccci_get_current_time();
	ccci_boottrc_dur_time = ccci_get_duration(ccci_boottrc_start_time,ccci_boottrc_end_time);
	ccci_boottrc_max_transmit_time = (ccci_boottrc_dur_time > ccci_boottrc_max_transmit_time)? ccci_boottrc_dur_time : ccci_boottrc_max_transmit_time;
	ccci_boottrc_min_transmit_time = (ccci_boottrc_dur_time < ccci_boottrc_min_transmit_time)? ccci_boottrc_dur_time : ccci_boottrc_min_transmit_time;
	ccci_boottrc_total_transmit_time += ccci_boottrc_dur_time;
	ccci_boottrc_transmit_count++;
	ccci_boottrc_avg_transmit_time = ccci_boottrc_total_transmit_time / ccci_boottrc_transmit_count; 
	// write to share memory
	ccci_excep_dbg_logging_InHS2(CCCI_EXCEP_DBG_HS_BOOTTRC_WAIT_TIME, (void *)&ccci_boottrc_total_transmit_time);
#endif
#endif
}
#endif    /* __SP_BOOTTRC_ENABLE__ */

/*************************************************************************
* FUNCTION
*  kal_int32 ccci_excep_init_shm
*
* DESCRIPTION
*  Initialize ccci exception share memory
*
* PARAMETERS
*  NA
*
* RETURNS
*  CCCI_SUCCESS or CCCI_FAIL
*
*************************************************************************/
kal_int32 ccci_excep_init_shm(CCCI_EXCEP_MEMORY_TYPE mem_type)
{
    if(mem_type >= CCCI_EXCEP_MEMORY_TYPE_MAX)
        return CCCI_FAIL;

    ccci_excep_memory_type = mem_type;
    return CCCI_SUCCESS;
}

/*************************************************************************
* FUNCTION
*  kal_int32 ccci_excep_query_shm
*
* DESCRIPTION
* Query the address, size & type of share memory 
*
* PARAMETERS
* region V the region of exception share memory (defined in ccci_excep_shm_region.h)
* address - pointer to address to hold the address of region.
* size V pointer to address to hold the size of region.
* Mem_type V share memory or static buffer (defined in ccci_excep_shm_type.h)
*
* RETURNS
* CCCI_SUCCESS or CCCI_FAIL
*
*************************************************************************/
kal_int32 ccci_excep_query_shm(CCCI_EXCEP_MEMORY_REGION region, kal_uint32 *address, kal_uint32 *size, CCCI_EXCEP_MEMORY_TYPE *mem_type)
{
    MODEM_RUNTIME_DATA *ap_md_share_data = ccci_get_share_data();
    kal_uint8 *ptr;
    kal_uint32 i = 0, region_len = 0;

    // Check condition
    if(region >= CCCI_EXCEP_MEMORY_REGION_MAX)
        return CCCI_FAIL;
    if(address == NULL || size == NULL || mem_type == NULL)
        return CCCI_FAIL;
    if((kal_uint32 *)ap_md_share_data->ExceShareMemBase == NULL || ap_md_share_data->ExceShareMemSize ==0)
        return CCCI_FAIL;

    // Get address
    ptr = (kal_uint8 *)ap_md_share_data->ExceShareMemBase;
    for(i=0; i < CCCI_EXCEP_MEMORY_REGION_MAX;i++)
    {
        if(i == (kal_uint32)region)
            break;
        region_len = ccci_excep_memory_region_len[i];
        ptr += region_len; 
    }

    // Set address
    *address = (kal_uint32) ptr;
    if(*address >= (ap_md_share_data->ExceShareMemBase+ap_md_share_data->ExceShareMemSize))    
        return CCCI_FAIL;

    // Set size
    *size = ccci_excep_memory_region_len[region];

    if( (*address + *size) > (ap_md_share_data->ExceShareMemBase+ap_md_share_data->ExceShareMemSize))
        return CCCI_FAIL;

    // Set memory type
    if(ccci_excep_memory_type == CCCI_EXCEP_MEMORY_TYPE_MAX)
        return CCCI_FAIL;
    *mem_type = ccci_excep_memory_type;
    return CCCI_SUCCESS;
}

/*************************************************************************
* FUNCTION
*  kal_int32 ccci_excep_shm_get_total_size
*
* DESCRIPTION
* Query exception share memory size
*
* PARAMETERS
* NA
*
* RETURNS
* exception share memory size
*
*************************************************************************/
kal_uint32 ccci_excep_shm_get_total_size()
{
    kal_uint32 region_len =0, i=0;
   
    for(i=0; i < CCCI_EXCEP_MEMORY_REGION_MAX;i++)
    {
        region_len += ccci_excep_memory_region_len[i];
    }
    
    return region_len;
}

// TODO: Important!!!!!!!!!
/* 20130820
    temporarily disable these function, because it is implement by AP AEE handshake flow
    But AEE handshake flow shall not use normal flow polling I/O 
    =>need to refine
*/
#if 0
#if !defined(ATEST_SYS_CCCI)
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
/* under construction !*/
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
#endif   	
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
#endif //#if !defined(ATEST_SYS_CCCI)
#endif 
#endif
