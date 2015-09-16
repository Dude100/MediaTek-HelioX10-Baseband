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
 *   excp_tty_ut.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   TTY Core unit test file in exception mode - it needs Host Test Program to run test.
 *   It works with enabling compile flag __EXCEPT_TTY_UT__.
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
 * 	CCCI Exception IT
 *
 * removed!
 * removed!
 * 1. add new TTY_CMD_MTU_SIZE support
 * 2. add plug-in/plug-out indication
 * 3. fix issue of flushing rx internal gpd
 *
 * removed!
 * removed!
 * Replace with New USB Core.
 * We sync with the following codes from HaoRen MOLY CBr w1322:
 * 1. USB Core
 * 2. USB Class - acm/rndis/mbim
 * 3. ipcore
 * 4. ttycore
 * 5. ethercore
 *
 * removed!
 * removed!
 * * Shorten the busy loop time from about 5 ms to 10 us in order to avoid host test program SetCommState timeout.
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "dcl.h"
#include "hmu.h"
#include "kal_debug.h"
#include "qmu_bm.h"
#include "qmu_bm_util.h"
#include "syscomp_config.h"

#include "devdrv_ls.h"
#include "drv_msgid.h"
#include "md_drv_sap.h"
#include "kal_public_defs.h"


//#define __EXPT_CCCI_TTY_IT__

#ifdef __EXPT_CCCI_TTY_IT__
#define EXCEPTION_TEST_PORT     uart_port_dhl_sp_expt 
//#define EXCEPTION_TEST_PORT     uart_port_dhl_ctrl_sp_expt
#else
#define EXCEPTION_TEST_PORT     uart_port_usb2
#endif
#define TX_BUF_NUM              500
#define RX_BUF_NUM              499+1/*for tailed gpd*/
#define TEST_LB_PKT_NUM         200
#define EXCPT_TTY_UT_CHUNK_SIZE_DEFAULT  (QBM_TTY_XXX_DATA_LEN)

#ifdef __EXPT_CCCI_TTY_IT__
#define EXPT_TTY_TX_GPD_TYPE    QBM_TYPE_CCCI_COMM
#define EXPT_TTY_RX_GPD_TYPE    QBM_TYPE_CCCI_COMM
#else
#define EXPT_TTY_TX_GPD_TYPE    QBM_TYPE_TTY_INT
#define EXPT_TTY_RX_GPD_TYPE    QBM_TYPE_TTY_INT
#endif

#define EXCP_HALT()             while(1)

#ifdef __EXPT_CCCI_TTY_IT__
static DCL_UINT8 bm_buf_excp_tx[QBM_QUEUE_GET_MEM_SIZE(QBM_TYPE_CCCI_COMM, TX_BUF_NUM)];
static DCL_UINT8 bm_buf_excp_rx[QBM_QUEUE_GET_MEM_SIZE(QBM_TYPE_CCCI_COMM, RX_BUF_NUM)];
#else
static DCL_UINT8 bm_buf_excp_tx[QBM_QUEUE_GET_MEM_SIZE(QBM_SIZE_TTY_INT, TX_BUF_NUM)];
static DCL_UINT8 bm_buf_excp_rx[QBM_QUEUE_GET_MEM_SIZE(QBM_SIZE_TTY_INT, RX_BUF_NUM)];
#endif

static void *excp_tgpd_head = NULL;
static void *excp_tgpd_tail = NULL;
static void *excp_rgpd_head = NULL;
static void *excp_rgpd_tail = NULL;

static void *excp_tgpd_free_head = NULL;
static void *excp_tgpd_free_tail = NULL;
static void *excp_rgpd_free_head = NULL;
static void *excp_rgpd_free_tail = NULL;

typedef enum {
    GPD_TYPE_TX,
    GPD_TYPE_RX,
} GPD_TYPE;


#define BUSY_LOOP(_n) do{volatile int i; volatile int j=0; for (i=0; i<_n; i++) {j+=i*2;}}while(0)

extern void dbg_print(char *fmt,...);

#define TTYUT_DBG_PRINT(...)


/*for debug only (CCCI)*/
static volatile kal_uint32 DBG_LOCK = 1; 

#define BUSY_STOP()                          \
    do{                                      \
        while(1){                            \
            if(DBG_LOCK == 0) break;         \
        }                                    \
    }while(0)                                \

void _excp_qbm_init(void)
{
    bm_queue_config conf;
    kal_uint32 size;
    kal_uint8 *pool;
    
    qbm_init();

    /* Tx GPD queue init */
    qbm_init_q_config(&conf);
    size = QBM_QUEUE_GET_MEM_SIZE(EXPT_TTY_TX_GPD_TYPE, TX_BUF_NUM);
    pool = &bm_buf_excp_tx[0];
    conf.buff_num = TX_BUF_NUM;
    conf.p_mem_pool_str = pool;
    conf.p_mem_pool_end = pool + size;
    qbm_init_queue_non_free(EXPT_TTY_TX_GPD_TYPE, &conf, &excp_tgpd_head, &excp_tgpd_tail);
    
    excp_tgpd_free_head = excp_tgpd_head;
    excp_tgpd_free_tail = excp_tgpd_tail;

    /* Rx GPD queue init */
    qbm_init_q_config(&conf);
    size = QBM_QUEUE_GET_MEM_SIZE(EXPT_TTY_RX_GPD_TYPE, RX_BUF_NUM);
    pool = &bm_buf_excp_rx[0];
    conf.buff_num = RX_BUF_NUM;
    conf.p_mem_pool_str = pool;
    conf.p_mem_pool_end = pool + size;
    qbm_init_queue_non_free(EXPT_TTY_RX_GPD_TYPE, &conf, &excp_rgpd_head, &excp_rgpd_tail);

    excp_rgpd_free_head = excp_rgpd_head;
    excp_rgpd_free_tail = excp_rgpd_tail;

}

/**
 *  @ return    gpd number allocated successfully
 */
static DCL_UINT16 _excp_alloc_gpd(
        GPD_TYPE type,
        kal_uint32 buff_num,
        void **pp_head, 
        void **pp_tail
        )
{
    kal_uint16 alloc_num = 0;
    void *free_head;
    void *free_tail;
    void *cur;
    void *pre = NULL;

    free_head = (type == GPD_TYPE_TX) ? excp_tgpd_free_head : excp_rgpd_free_head;
    free_tail = (type == GPD_TYPE_TX) ? excp_tgpd_free_tail : excp_rgpd_free_tail;

    cur = free_head;
    
    while (cur != NULL && buff_num > 0)
    {
        alloc_num ++;
        buff_num --;
        pre = cur;
        cur = QBM_DES_GET_NEXT(cur);
    }

    *pp_head = free_head;
    *pp_tail = pre;

    if (type == GPD_TYPE_TX) {
        excp_tgpd_free_head = cur;
    } else {
        excp_rgpd_free_head = cur;
    }

    return alloc_num;
}

static void _excp_free_gpd(
        GPD_TYPE type,
        void *p_head, 
        void *p_tail
        )
{
    void *free_head;
    void *free_tail;

    free_head = (type == GPD_TYPE_TX) ? excp_tgpd_free_head : excp_rgpd_free_head;
    free_tail = (type == GPD_TYPE_TX) ? excp_tgpd_free_tail : excp_rgpd_free_tail;

    if (free_head == NULL) {
        free_head = p_head;
    } else {
        QBM_DES_SET_NEXT(free_tail, p_head);
    }
    free_tail = p_tail;

    if (type == GPD_TYPE_TX) {
        excp_tgpd_free_head = free_head;
        excp_tgpd_free_tail = free_tail;
    } else {
        excp_rgpd_free_head = free_head;
        excp_rgpd_free_tail = free_tail;
    }
}


static kal_uint32 _excp_rst_gpd_list(kal_uint32 type,qbm_gpd* first_gpd, qbm_gpd* last_gpd)
{
    qbm_gpd*            current_gpd = NULL;
    qbm_gpd*            next_gpd = NULL;
    kal_uint32          num_gpd = 0;
    
    ASSERT(first_gpd && last_gpd);
    current_gpd = first_gpd;

    do {
        next_gpd = QBM_DES_GET_NEXT(current_gpd);
        qbm_reset_pd(type, (void*)current_gpd);
        qbm_cal_set_checksum((kal_uint8 *)current_gpd);
        QBM_CACHE_FLUSH(current_gpd, sizeof(qbm_gpd));
        num_gpd ++;
        if ( current_gpd == last_gpd )
        {
            break;
        }        
        current_gpd = next_gpd;
    } while ( current_gpd != NULL );

    return num_gpd;
}

static void* _excp_get_qbm_dataptr(void* gpd)
{
    void* bd = NULL;
    void* data_ptr = NULL;
    
    ASSERT(NULL!=gpd);
    if(0 != QBM_DES_GET_BDP(gpd)){
        //4 <case 1> GPD->BD->BUFF
        bd = QBM_DES_GET_DATAPTR(gpd);
        ASSERT(NULL!=bd);
        data_ptr = QBM_DES_GET_DATAPTR(bd);
    }else{
        //4 <case 2> GPD->BUFF        
        data_ptr = QBM_DES_GET_DATAPTR(gpd);
    }

    ASSERT(NULL!=data_ptr);
    return data_ptr;
}

static void _excp_set_qbm_datalen(void* gpd, kal_uint32 data_len)
{
    void* bd = NULL;

    ASSERT(NULL != gpd);
    /*QBM_TYPE_CCCI_COMM specific function*/
    ASSERT(QBM_TYPE_CCCI_COMM == QBM_GET_TYPE(gpd));
    /*Must have BD*/
    ASSERT(0 != QBM_DES_GET_BDP(gpd));

    bd = QBM_DES_GET_DATAPTR(gpd);
    ASSERT(NULL!=bd);
    QBM_DES_SET_DATALEN(bd, data_len);
    qbm_cal_set_checksum((kal_uint8 *)bd);
    
    QBM_DES_SET_DATALEN(gpd, data_len);
    qbm_cal_set_checksum((kal_uint8 *)gpd);
}

static void excp_loopback_test(DCL_HANDLE handle, kal_bool is_before_reset, kal_uint32 num)
{
    unsigned char *tx_buf_ptr;
    unsigned char *rx_buf_ptr;
    kal_char trigger_string[50] = {0};
    kal_uint32 i;
    kal_uint32 total_rx_num;
    TTY_CTRL_EXCP_ASSIGN_RX_GPD_T ttyCtlAsnRxGpd;       
    TTY_CTRL_EXCP_GET_RX_GPD_T ttyCtlGetRxGpd;
    TTY_CTRL_EXCP_TX_GPD_T ttyCtlTxGpd;
    TTY_CTRL_EXCP_TX_DONE_INFO_T ttyCtlTxDoneInfo;
    TTY_CTRL_EXCP_HIF_STATE_T ttyCtlHifSt;
    UART_CTRL_GET_CHUNK_SIZE_T ur_ctrl_get_chunk_size;

    /*
        Wait a period of time to let Host have enought time to open com port
    */
    for (i = 0; i < 500000; i ++)
    {
        if (!is_before_reset) {DclSerialPort_Control(handle, TTY_CMD_EXCEPTION_HIF_POLL, NULL); }
        BUSY_LOOP(100);
    }

    /* 
        Send a packet to trigger Host start loopback test
        #format: "exception num" (ex. "exception 50")
    */
    _excp_alloc_gpd(GPD_TYPE_TX, 1, &ttyCtlTxGpd.first_gpd, &ttyCtlTxGpd.last_gpd);
    tx_buf_ptr = QBM_DES_GET_DATAPTR(ttyCtlTxGpd.first_gpd);
    kal_mem_set(trigger_string, 0, sizeof(trigger_string));
    sprintf(trigger_string, "exception %d", num);
    kal_mem_cpy(tx_buf_ptr, trigger_string, strlen(trigger_string)+1);

    // Set Tx GPD
    QBM_CACHE_FLUSH(tx_buf_ptr, strlen(trigger_string)+1);
    QBM_DES_SET_DATALEN(ttyCtlTxGpd.first_gpd, strlen(trigger_string)+1);
    QBM_DES_SET_HWO(ttyCtlTxGpd.first_gpd);
    qbm_cal_set_checksum(ttyCtlTxGpd.first_gpd);
    QBM_CACHE_FLUSH(ttyCtlTxGpd.first_gpd, sizeof(qbm_gpd));
    DclSerialPort_Control(handle, TTY_CMD_EXCEPTION_TX_GPD, (DCL_CTRL_DATA_T*) &ttyCtlTxGpd);
    // Polling Tx Done Info until all Tx GPD are sent and retrieved
    do {
        if (!is_before_reset) {DclSerialPort_Control(handle, TTY_CMD_EXCEPTION_HIF_POLL, NULL); }
        
        DclSerialPort_Control(handle, TTY_CMD_EXCEPTION_TX_DONE_INFO, (DCL_CTRL_DATA_T*) &ttyCtlTxDoneInfo);
    
        if (ttyCtlTxDoneInfo.num > 0) {
            _excp_free_gpd(GPD_TYPE_TX, ttyCtlTxDoneInfo.first_gpd, ttyCtlTxDoneInfo.last_gpd);
            break;
        }
    } while (1);

    
    /* Assign Rx GPD to driver */   
    _excp_alloc_gpd(GPD_TYPE_RX, 2/*1 for tailed GPD*/, &ttyCtlAsnRxGpd.first_gpd, &ttyCtlAsnRxGpd.last_gpd);
    DclSerialPort_Control(handle, TTY_CMD_GET_CHUNK_SIZE, (DCL_CTRL_DATA_T*)&ur_ctrl_get_chunk_size);
    // first gpd
    if(ur_ctrl_get_chunk_size.chunkSize == 1)
    {
        QBM_DES_SET_ALLOW_LEN(ttyCtlAsnRxGpd.first_gpd, EXCPT_TTY_UT_CHUNK_SIZE_DEFAULT);
    }
    else
    {
        QBM_DES_SET_ALLOW_LEN(ttyCtlAsnRxGpd.first_gpd, ur_ctrl_get_chunk_size.chunkSize);
    }
    QBM_DES_SET_HWO(ttyCtlAsnRxGpd.first_gpd);
    qbm_cal_set_checksum(ttyCtlAsnRxGpd.first_gpd);
    QBM_CACHE_FLUSH(ttyCtlAsnRxGpd.first_gpd, sizeof(qbm_gpd));
    // last gpd
    if(ur_ctrl_get_chunk_size.chunkSize == 1)
    {
        QBM_DES_SET_ALLOW_LEN(ttyCtlAsnRxGpd.first_gpd, EXCPT_TTY_UT_CHUNK_SIZE_DEFAULT);
    }
    else
    {
        QBM_DES_SET_ALLOW_LEN(ttyCtlAsnRxGpd.last_gpd, ur_ctrl_get_chunk_size.chunkSize);
    }
    QBM_DES_SET_HWO(ttyCtlAsnRxGpd.last_gpd);
    qbm_cal_set_checksum(ttyCtlAsnRxGpd.last_gpd);
    QBM_CACHE_FLUSH(ttyCtlAsnRxGpd.last_gpd, sizeof(qbm_gpd));
    
    DclSerialPort_Control(handle, TTY_CMD_EXCEPTION_ASSIGN_RX_GPD, (DCL_CTRL_DATA_T*) &ttyCtlAsnRxGpd);
    
    total_rx_num = 0;
    while (total_rx_num < num) // Polling Received Rx GPD and transmit the data to Host
    {       
        void *cur_tx;
        void *cur_rx;
        kal_uint16 rx_len;
        kal_uint16 gpd_num;
        
        /* Get Rx GPD */
        do {
            if (!is_before_reset) {DclSerialPort_Control(handle, TTY_CMD_EXCEPTION_HIF_POLL, NULL);}
            DclSerialPort_Control(handle, TTY_CMD_EXCEPTION_GET_RX_GPD, (DCL_CTRL_DATA_T*) &ttyCtlGetRxGpd);
        } while (ttyCtlGetRxGpd.num == 0);
        total_rx_num += ttyCtlGetRxGpd.num;
        TTYUT_DBG_PRINT("[EXCEPT TTYUT] receive %d gpds, has received total %d gpds\r\n", ttyCtlGetRxGpd.num, total_rx_num);
    
        /* Allocate Tx GPD and re-transmit the rx data to Host */
        gpd_num = ttyCtlGetRxGpd.num;
        _excp_alloc_gpd(GPD_TYPE_TX, gpd_num, &ttyCtlTxGpd.first_gpd, &ttyCtlTxGpd.last_gpd);
    
        cur_rx = ttyCtlGetRxGpd.first_gpd;
        cur_tx = ttyCtlTxGpd.first_gpd;
        
        for (i = 0; i < ttyCtlGetRxGpd.num; i ++)
        {
            rx_buf_ptr = QBM_DES_GET_DATAPTR(cur_rx);
            rx_len = QBM_DES_GET_DATALEN(cur_rx);
            tx_buf_ptr = QBM_DES_GET_DATAPTR(cur_tx);
    
            QBM_CACHE_INVALID(rx_buf_ptr, rx_len);
            kal_mem_cpy(tx_buf_ptr, rx_buf_ptr, rx_len);
            QBM_CACHE_FLUSH(tx_buf_ptr, rx_len);
    
            /* Set Tx GPD */
            QBM_DES_SET_DATALEN(cur_tx, rx_len);
            QBM_DES_SET_HWO(cur_tx);
            qbm_cal_set_checksum(cur_tx);
            QBM_CACHE_FLUSH(cur_tx, sizeof(qbm_gpd));
    
            /* Reset Rx GPD */
            QBM_DES_SET_ALLOW_LEN(cur_rx, ur_ctrl_get_chunk_size.chunkSize);
            QBM_DES_SET_HWO(cur_rx);
            qbm_cal_set_checksum(cur_rx);
            QBM_CACHE_FLUSH(cur_rx, sizeof(qbm_gpd));               
    
            cur_tx = QBM_DES_GET_NEXT(cur_tx);
            cur_rx = QBM_DES_GET_NEXT(cur_rx);
        }
        DclSerialPort_Control(handle, TTY_CMD_EXCEPTION_TX_GPD, (DCL_CTRL_DATA_T*) &ttyCtlTxGpd);

        if (!is_before_reset) {DclSerialPort_Control(handle, TTY_CMD_EXCEPTION_HIF_POLL, NULL); }
        
        /* Re-assign Rx GPD to driver */
        ttyCtlAsnRxGpd.first_gpd = ttyCtlGetRxGpd.first_gpd;
        ttyCtlAsnRxGpd.last_gpd = ttyCtlGetRxGpd.last_gpd;
        DclSerialPort_Control(handle, TTY_CMD_EXCEPTION_ASSIGN_RX_GPD, (DCL_CTRL_DATA_T*) &ttyCtlAsnRxGpd);
    
        /* Polling Tx Done Info until all Tx GPD are sent and retrieved */
        do {
            if (!is_before_reset) {DclSerialPort_Control(handle, TTY_CMD_EXCEPTION_HIF_POLL, NULL);}
            DclSerialPort_Control(handle, TTY_CMD_EXCEPTION_TX_DONE_INFO, (DCL_CTRL_DATA_T*) &ttyCtlTxDoneInfo);
    
            if (ttyCtlTxDoneInfo.num > 0) {
                _excp_free_gpd(GPD_TYPE_TX, ttyCtlTxDoneInfo.first_gpd, ttyCtlTxDoneInfo.last_gpd);
                gpd_num -= ttyCtlTxDoneInfo.num;
                TTYUT_DBG_PRINT("[EXCEPT TTYUT] has sent %d gpds\r\n", ttyCtlTxDoneInfo.num);
            }
        } while (gpd_num > 0);
    
        /* Check HIF state */
        DclSerialPort_Control(handle, TTY_CMD_EXCEPTION_HIF_STATE, (DCL_CTRL_DATA_T*) &ttyCtlHifSt);
        if (ttyCtlHifSt.hif_state != HIF_STATE_NORMAL) {
            EXCP_HALT();
        }

        if (!is_before_reset) {DclSerialPort_Control(handle, TTY_CMD_EXCEPTION_HIF_POLL, NULL); }
    }   

}

static void excp_ccci_loopback_test(DCL_HANDLE handle, kal_uint32 num)
{
    unsigned char *tx_buf_ptr;
    unsigned char *rx_buf_ptr;
    kal_char trigger_string[50] = {0};
    kal_uint32 i;
    kal_uint32 total_rx_num;
    TTY_CTRL_EXCP_ASSIGN_RX_GPD_T ttyCtlAsnRxGpd;       
    TTY_CTRL_EXCP_GET_RX_GPD_T ttyCtlGetRxGpd;
    TTY_CTRL_EXCP_TX_GPD_T ttyCtlTxGpd;
    TTY_CTRL_EXCP_TX_DONE_INFO_T ttyCtlTxDoneInfo;
    TTY_CTRL_EXCP_HIF_STATE_T ttyCtlHifSt;
    UART_CTRL_GET_MTU_SIZE_T ur_ctrl_get_mtu_size;
    kal_uint32 tmp_num;

    /*For debug test only*/
    //BUSY_STOP();
    
    /* Assign Rx GPD to driver */
    // TODO:Need to revise APIs. Because in exception mode(espicailly in HISR), some QBM APIs shall not be used. (ex:enhance mutex)
    //tmp_num = _excp_alloc_gpd(GPD_TYPE_RX, 2/*1 for tailed GPD*/, &ttyCtlAsnRxGpd.first_gpd, &ttyCtlAsnRxGpd.last_gpd);
    tmp_num = qbmt_alloc_q_no_tail(EXPT_TTY_RX_GPD_TYPE, 2, &ttyCtlAsnRxGpd.first_gpd, &ttyCtlAsnRxGpd.last_gpd);
    if(tmp_num!= 2) while(1);
    DclSerialPort_Control(handle, TTY_CMD_GET_MTU_SIZE, (DCL_CTRL_DATA_T*)&ur_ctrl_get_mtu_size);
    QBM_DES_SET_ALLOW_LEN(ttyCtlAsnRxGpd.first_gpd, ur_ctrl_get_mtu_size.ulmtu_sz);
    QBM_DES_SET_HWO(ttyCtlAsnRxGpd.first_gpd);
    qbm_cal_set_checksum(ttyCtlAsnRxGpd.first_gpd);
    QBM_CACHE_FLUSH(ttyCtlAsnRxGpd.first_gpd, sizeof(qbm_gpd));
    // last gpd
    QBM_DES_SET_ALLOW_LEN(ttyCtlAsnRxGpd.last_gpd, ur_ctrl_get_mtu_size.ulmtu_sz);
    QBM_DES_SET_HWO(ttyCtlAsnRxGpd.last_gpd);
    qbm_cal_set_checksum(ttyCtlAsnRxGpd.last_gpd);
    QBM_CACHE_FLUSH(ttyCtlAsnRxGpd.last_gpd, sizeof(qbm_gpd));
    
    DclSerialPort_Control(handle, TTY_CMD_EXCEPTION_ASSIGN_RX_GPD, (DCL_CTRL_DATA_T*) &ttyCtlAsnRxGpd);
    
    total_rx_num = 0;
    //while (total_rx_num < num) // Polling Received Rx GPD and transmit the data to Host
    while(1)
    {       
        void *cur_tx;
        void *cur_rx;
        kal_uint16 rx_len;
        kal_uint16 gpd_num;
        
        /* Get Rx GPD */
        do {
            DclSerialPort_Control(handle, TTY_CMD_EXCEPTION_HIF_POLL, NULL);
            DclSerialPort_Control(handle, TTY_CMD_EXCEPTION_GET_RX_GPD, (DCL_CTRL_DATA_T*) &ttyCtlGetRxGpd);
        } while (ttyCtlGetRxGpd.num == 0);
        total_rx_num += ttyCtlGetRxGpd.num;
        TTYUT_DBG_PRINT("[EXCEPT TTYUT] receive %d gpds, has received total %d gpds\r\n", ttyCtlGetRxGpd.num, total_rx_num);
    
        /* Allocate Tx GPD and re-transmit the rx data to Host */
        gpd_num = ttyCtlGetRxGpd.num;
        //_excp_alloc_gpd(GPD_TYPE_TX, gpd_num, &ttyCtlTxGpd.first_gpd, &ttyCtlTxGpd.last_gpd);
        tmp_num = qbmt_alloc_q_no_tail(EXPT_TTY_TX_GPD_TYPE, gpd_num, &ttyCtlTxGpd.first_gpd, &ttyCtlTxGpd.last_gpd);
        if(tmp_num!= gpd_num) while(1);

        cur_rx = ttyCtlGetRxGpd.first_gpd;
        cur_tx = ttyCtlTxGpd.first_gpd;
        
        for (i = 0; i < ttyCtlGetRxGpd.num; i ++)
        {
            rx_buf_ptr = _excp_get_qbm_dataptr(cur_rx);
            rx_len = QBM_DES_GET_DATALEN(cur_rx);
            tx_buf_ptr = _excp_get_qbm_dataptr(cur_tx);
    
            QBM_CACHE_INVALID(rx_buf_ptr, rx_len);
            kal_mem_cpy(tx_buf_ptr, rx_buf_ptr, rx_len);
            QBM_CACHE_FLUSH(tx_buf_ptr, rx_len);
    
            /* Set Tx GPD */
            _excp_set_qbm_datalen(cur_tx, rx_len);
            QBM_DES_SET_HWO(cur_tx);
            qbm_cal_set_checksum(cur_tx);
            QBM_CACHE_FLUSH(cur_tx, sizeof(qbm_gpd));
            
            /* Reset Rx GPD */
            _excp_rst_gpd_list(EXPT_TTY_RX_GPD_TYPE,cur_rx,cur_rx);
            QBM_DES_SET_ALLOW_LEN(cur_rx, ur_ctrl_get_mtu_size.ulmtu_sz);
            //QBM_DES_SET_HWO(cur_rx);
            qbm_cal_set_checksum(cur_rx);
            QBM_CACHE_FLUSH(cur_rx, sizeof(qbm_gpd));               
    
            cur_tx = QBM_DES_GET_NEXT(cur_tx);
            cur_rx = QBM_DES_GET_NEXT(cur_rx);
        }
        DclSerialPort_Control(handle, TTY_CMD_EXCEPTION_TX_GPD, (DCL_CTRL_DATA_T*) &ttyCtlTxGpd);

        DclSerialPort_Control(handle, TTY_CMD_EXCEPTION_HIF_POLL, NULL);
        
        /*Re-assign Rx GPD to driver */
        ttyCtlAsnRxGpd.first_gpd = ttyCtlGetRxGpd.first_gpd;
        ttyCtlAsnRxGpd.last_gpd = ttyCtlGetRxGpd.last_gpd;
        DclSerialPort_Control(handle, TTY_CMD_EXCEPTION_ASSIGN_RX_GPD, (DCL_CTRL_DATA_T*) &ttyCtlAsnRxGpd);
    
        /* Polling Tx Done Info until all Tx GPD are sent and retrieved */
        do {
            DclSerialPort_Control(handle, TTY_CMD_EXCEPTION_HIF_POLL, NULL);

            /*Debug only to check sdio interrupt status*/
            //if((*SDIO_IRQ_DL_FTE0SR) & SDIO_INT_MASK) while(1);
            
            DclSerialPort_Control(handle, TTY_CMD_EXCEPTION_TX_DONE_INFO, (DCL_CTRL_DATA_T*) &ttyCtlTxDoneInfo);
    
            if (ttyCtlTxDoneInfo.num > 0) {
                //_excp_free_gpd(GPD_TYPE_TX, ttyCtlTxDoneInfo.first_gpd, ttyCtlTxDoneInfo.last_gpd);
                qbmt_dest_q(ttyCtlTxDoneInfo.first_gpd, ttyCtlTxDoneInfo.last_gpd);
                gpd_num -= ttyCtlTxDoneInfo.num;
                TTYUT_DBG_PRINT("[EXCEPT TTYUT] has sent %d gpds\r\n", ttyCtlTxDoneInfo.num);
            }
        } while (gpd_num > 0);
    
        /* Check HIF state */
        DclSerialPort_Control(handle, TTY_CMD_EXCEPTION_HIF_STATE, (DCL_CTRL_DATA_T*) &ttyCtlHifSt);
        if (ttyCtlHifSt.hif_state != HIF_STATE_NORMAL) {
            EXCP_HALT();
        }

        DclSerialPort_Control(handle, TTY_CMD_EXCEPTION_HIF_POLL, NULL);
    }   

}

DCL_STATUS excp_ttyut(void)
{
    DCL_HANDLE handle;

    //for debug only
    //BUSY_STOP();
    
    hmu_except_init();

    TTYUT_DBG_PRINT("[EXCEPT TTYUT] excp_ttyut start\r\n");

    handle = DclSerialPort_Open(EXCEPTION_TEST_PORT, 0);

    /* Init QBM for exception */
    _excp_qbm_init();

    /* Test Case 1: Loopback before RESET */
        /* HIF init and Clear channel */
    DclSerialPort_Control(handle, TTY_CMD_EXCEPTION_HIF_INIT, NULL);
    DclSerialPort_Control(handle, TTY_CMD_EXCEPTION_CLEAR_CHANNEL, NULL);

#ifdef __EXPT_CCCI_TTY_IT__
    excp_ccci_loopback_test(handle, TEST_LB_PKT_NUM);
#else
    //BUSY_LOOP(60000000);
    TTYUT_DBG_PRINT("[EXCEPT TTYUT] excp_ttyut case 1\r\n");
    {
        excp_loopback_test(handle, KAL_TRUE, TEST_LB_PKT_NUM);
    }

    /* Test Case 2: RESET */
    TTYUT_DBG_PRINT("[EXCEPT TTYUT] excp_ttyut case 2\r\n");
    {
        DclSerialPort_Control(handle, TTY_CMD_EXCEPTION_RESET, NULL);
    }

    /* Test Case 3: Loopback after RESET */
        /* HIF init */
    DclSerialPort_Control(handle, TTY_CMD_EXCEPTION_HIF_INIT, NULL);
    //BUSY_LOOP(60000000);
    TTYUT_DBG_PRINT("[EXCEPT TTYUT] excp_ttyut case 3\r\n");
    {
        excp_loopback_test(handle, KAL_FALSE, TEST_LB_PKT_NUM);
    }

    /* Test Case 4: HIF_STATE return TXERROR */
    TTYUT_DBG_PRINT("[EXCEPT TTYUT] excp_ttyut case 4\r\n");
    {
        TTY_CTRL_EXCP_TX_GPD_T ttyCtlTxGpd;
        TTY_CTRL_EXCP_TX_DONE_INFO_T ttyCtlTxDoneInfo;
        TTY_CTRL_EXCP_HIF_STATE_T ttyCtlHifSt;
        kal_uint16 gpd_num;
        kal_uint16 count;

        BUSY_LOOP(50000);
        while (1)
        {
            gpd_num = _excp_alloc_gpd(GPD_TYPE_TX, 1, &ttyCtlTxGpd.first_gpd, &ttyCtlTxGpd.last_gpd);
            TTYUT_DBG_PRINT("[EXCEPT TTYUT] allocate %d gpd\r\n", gpd_num);
            if (gpd_num == 0) {
                break;
            }
            QBM_DES_SET_DATALEN(ttyCtlTxGpd.first_gpd, 100);
            QBM_DES_SET_HWO(ttyCtlTxGpd.first_gpd);
            qbm_cal_set_checksum(ttyCtlTxGpd.first_gpd);
            QBM_CACHE_FLUSH(ttyCtlTxGpd.first_gpd, sizeof(qbm_gpd));

            BUSY_LOOP(300000);
            DclSerialPort_Control(handle, TTY_CMD_EXCEPTION_TX_GPD, (DCL_CTRL_DATA_T*) &ttyCtlTxGpd);
            DclSerialPort_Control(handle, TTY_CMD_EXCEPTION_HIF_POLL, NULL);
        }

        count = 10000;
        while (count-- > 0)
        {
            BUSY_LOOP(30000);
            DclSerialPort_Control(handle, TTY_CMD_EXCEPTION_TX_DONE_INFO, (DCL_CTRL_DATA_T*) &ttyCtlTxDoneInfo);
        }
        
        DclSerialPort_Control(handle, TTY_CMD_EXCEPTION_HIF_STATE, (DCL_CTRL_DATA_T*) &ttyCtlHifSt);
        if (ttyCtlHifSt.hif_state != HIF_STATE_TXERROR) {
            TTYUT_DBG_PRINT("[EXCEPT TTYUT] ERROR!! HIF_STATE return NORMAL\r\n");
            EXCP_HALT();
        } else {
            TTYUT_DBG_PRINT("[EXCEPT TTYUT] HIF_STATE return HIF_STATE_TXERROR\r\n");
        }
    }

    TTYUT_DBG_PRINT("[EXCEPT TTYUT] excp_ttyut end\r\n");
#endif
    return STATUS_OK;
}

static kal_bool excp_ttyut_task_init(void)
{
    return KAL_TRUE;
}

static void excp_ttyut_task_main(task_entry_struct *task_entry_ptr)
{
    DCL_HANDLE handle;
    UART_CTRL_PUT_BYTES_T ur_ctrl_putbytes;
    char *dummy_string = "DUMMYdummyDummY";
    DCL_STATUS status;
    UART_CTRL_GET_DRV_STATE_T getDrvState;

    handle = DclSerialPort_Open(EXCEPTION_TEST_PORT, 0);

    DclSerialPort_UpModuleInit(handle, MOD_EXCP_TTYUT, 0); // conventional init

    /*If taking CCCI exception IT test, task will be blocked here. Because, driver is attached when exception init*/
    getDrvState.u4OwnerId = MOD_EXCP_TTYUT;
    do {
        kal_sleep_task(100);
        status = DclSerialPort_Control(handle, TTY_CMD_GET_DRV_STATE, (DCL_CTRL_DATA_T*) &getDrvState);
    } while ((getDrvState.drv_state != DRV_ST_ATTACHED) || (status != STATUS_OK)); 

    kal_sleep_task(KAL_TICKS_5_SEC);

    /* Transmit a dummy packet */
    ur_ctrl_putbytes.u4OwenrId = MOD_EXCP_TTYUT;
    ur_ctrl_putbytes.puBuffaddr = (DCL_UINT8*)dummy_string;
    ur_ctrl_putbytes.u2Length = strlen(dummy_string);
    DclSerialPort_Control(handle, SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*) &ur_ctrl_putbytes);

    kal_sleep_task(KAL_TICKS_5_SEC);

    /* Trigger an assert to enter exception mode */
    ASSERT(0);
}

kal_bool excp_ttyut_create(comptask_handler_struct **handle)
{
    static const comptask_handler_struct excp_ttyut_handler_info =
    {
        excp_ttyut_task_main,        /* task entry function */
        excp_ttyut_task_init,        /* task initialization function */
        NULL        /* task reset handler */
    };

    TTYUT_DBG_PRINT("=========>excp_ttyut_create\r\n");

    *handle = (comptask_handler_struct *)&excp_ttyut_handler_info;
    return KAL_TRUE;
}

