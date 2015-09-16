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
 *   cccitty_it.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Impelements the CCCITTY IT for SP integration test
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
 * 	Add cccitty sequence support(Merging from MP5 CL:641385 to MP6)
 *
 * removed!
 * removed!
 * 	add cccitty sequence support and status update support
 *
 * removed!
 * removed!
 * [CCCI] Add ICUSB feature.
 *
 * 11 26 2013 box.wu
 * removed!
 * add exception, tty, ICUSB.
 *
 * 06 20 2013 ap.wang
 * removed!
 * [CCCI_TTY_IT] Remove ATCI channel IT
 *
 * 04 12 2013 ap.wang
 * removed!
 * [CCCITTY_IT] Invalid GPD data before free GPD in UL mode
 *
 * 04 07 2013 ap.wang
 * removed!
 * [CCCITTY_IT] Modify NexTX allocate GPD fail handle
 *
 * 03 28 2013 ap.wang
 * removed!
 * [CCCI_IT_CTRL] Modify ILM queue threshold size
 *
 * 03 27 2013 ap.wang
 * removed!
 *
 * 03 21 2013 ap.wang
 * removed!
 *
 * removed!
 * removed!
 * checkin cccitty IT code
 *
 ****************************************************************************/
#include "ccci_if.h"
#if defined (__CCCI_TTY_IT__) /* in hif_main.mak */
#include "kal_public_api.h" //for INLINE
#include "syscomp_config.h"

#include "cccidev_qbm.h"
#include "qmu_bm.h"
#include "qmu_bm_util.h"
#include "dcl_uart.h"
#include "dcl.h"
#include "drv_msgid.h"

#include "dhl_trace.h"
#define cccitty_it_print(...) dhl_print(TRACE_INFO, DHL_USER_FLAG_NONE, MOD_CCCITTY, ##__VA_ARGS__)
//#define cccitty_it_print(...)

//#define _DUMP_COM_CONTENT_  //Dump the Tx/Rx content of COM PORT

//#define DEV_CONV_TX_CONV_RX   1
//#define DEV_NEW_TX_CONV_RX    2

#define CCCITTY_IT_DEV_NUM        4
#define CCCITTY_IT_LB_BUF_SIZE    (QBM_CCCI_COMM_DATA_LEN*10)

//TODO: add additional mode for performance statistics
typedef enum {
	DEV_CONV_TX_CONV_RX = 1,
	DEV_NEW_TX_CONV_RX,
	DEV_NEW_TX_ONLY,                     //generate traffic at MD
	DEV_CONV_TX_ONLY,                    //generate traffic at MD
	DEV_CONV_RX_ONLY,                    //drop packet
} CCCITTY_IT_MODE_t;

typedef struct {

    kal_uint8  pDataBuffer[CCCITTY_IT_LB_BUF_SIZE];
	kal_uint8*  pRead;
	kal_uint8*  pWrite;
    kal_uint32  u4BufferSize;

} RingBufferT;


typedef enum _ccci_tty_it_mode {
    CCCI_TTY_IT_DISABLE = 0,
    CCCI_TTY_IT_LB,         /* Default Mode */
    CCCI_TTY_IT_DL,
    CCCI_TTY_IT_UL,
    CCCI_TTY_IT_MAX                      
} CCCI_TTY_IT_MODE_T;

typedef struct _cccitty_it_instance_t {
    DCL_HANDLE              handle;
    DCL_UINT32              owner;
    DCL_UINT32              mode;
    //RingBufferT             tx_data;
    kal_uint8               buff[QBM_CCCI_COMM_DATA_LEN]; 
    DCL_UINT16              length;
    CCCI_TTY_IT_MODE_T      it_mode;
    ccci_io_request_t       *ior;
    kal_uint8               *p_data;
} cccitty_it_instance_t;
static cccitty_it_instance_t cccitty_it_inst_g[CCCITTY_IT_DEV_NUM];


/*************************************************************/
//CCCIDEV_TASK1
/*
#define CCCITTY_IT_TASK1_PORT   uart_port_dhl_ccci
#define CCCITTY_IT_TASK1_MOD    MOD_CCCIITDEV1
#define CCCITTY_IT_TASK1_MODE   DEV_NEW_TX_CONV_RX
#define CCCITTY_IT_TASK1_FLAG   (TTY_FLAG_NEW_TX)
*/
// For ICUSB feature development
#define CCCITTY_IT_TASK1_PORT   uart_port_sim_ccci
#define CCCITTY_IT_TASK1_MOD    MOD_CCCIITDEV1
#define CCCITTY_IT_TASK1_MODE   DEV_CONV_TX_CONV_RX
#define CCCITTY_IT_TASK1_FLAG   (0)

//CCCIDEV_TASK2
#define CCCITTY_IT_TASK2_PORT   uart_port_tst_ccci
#define CCCITTY_IT_TASK2_MOD    MOD_CCCIITDEV2
#define CCCITTY_IT_TASK2_MODE   DEV_CONV_TX_CONV_RX
#define CCCITTY_IT_TASK2_FLAG   (0)

//CCCIDEV_TASK3
#define CCCITTY_IT_TASK3_PORT   uart_port_at_ccci
#define CCCITTY_IT_TASK3_MOD    MOD_CCCIITDEV3
#define CCCITTY_IT_TASK3_MODE   DEV_CONV_TX_CONV_RX
#define CCCITTY_IT_TASK3_FLAG   (0)

//CCCIDEV_TASK4
#define CCCITTY_IT_TASK4_PORT   uart_port_gps_ccci
#define CCCITTY_IT_TASK4_MOD    MOD_CCCIITDEV4
#define CCCITTY_IT_TASK4_MODE   DEV_CONV_TX_CONV_RX
#define CCCITTY_IT_TASK4_FLAG   (0)
/*************************************************************/


// ==========================================================
// Private Function
// ==========================================================
static kal_bool cccitty_it_create_instance(DCL_HANDLE handle, DCL_UINT32 owner, DCL_UINT32 mode)
{
    kal_uint8 i;
    
    for (i=0; i<CCCITTY_IT_DEV_NUM; i++) {
        if (cccitty_it_inst_g[i].handle == (DCL_HANDLE) 0x0) {
            cccitty_it_inst_g[i].handle = handle;
            cccitty_it_inst_g[i].owner = owner;
            cccitty_it_inst_g[i].mode = mode;
            cccitty_it_inst_g[i].it_mode = CCCI_TTY_IT_LB;
            cccitty_it_inst_g[i].length = 0;
            cccitty_it_inst_g[i].p_data = NULL;
            return KAL_TRUE;
        }
    }

	// Can't create TTY_UT instance, ASSERT.
	ASSERT(0);
    return KAL_FALSE;
}

static cccitty_it_instance_t* cccitty_it_get_instance(DCL_HANDLE handle)
{
    kal_uint8 i;

    for (i=0; i<CCCITTY_IT_DEV_NUM; i++) {
        if (cccitty_it_inst_g[i].handle == handle) {
            return &cccitty_it_inst_g[i];
        }
    } 
    return NULL;
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

kal_uint32 kaka;
static void _cccitty_it_conv_tx_conv_rx_hdr(DCL_HANDLE handle, kal_uint32 owner)
{
    /* reference _tty_ut_conv_tx_conv_rx_rd_handler */
    UART_CTRL_GET_BYTES_T ur_ctrl_getbytes;
    UART_CTRL_PUT_BYTES_T ur_ctrl_putbytes;
    DCL_STATUS          ret = STATUS_FAIL;
    DCL_UINT8           *data_buf;
#ifdef _DUMP_COM_CONTENT_
    kal_uint32          i;
#endif
    cccitty_it_instance_t* p_cccitty_it_inst = cccitty_it_get_instance(handle);
    ASSERT(p_cccitty_it_inst);

    data_buf = p_cccitty_it_inst->buff;

    /* RX */
    ur_ctrl_getbytes.u4OwenrId = owner;
	ur_ctrl_getbytes.puBuffaddr = data_buf;
	ur_ctrl_getbytes.u2Length = QBM_CCCI_COMM_DATA_LEN;

#ifdef __CCCI_TTY_CONV_RX_UL_PERF__
    CCCI_PERF_GET_CYCLE(ul_prof[ul_prof_id].tty_conv_rx_CMD_GB_s);    
    ret = DclSerialPort_Control(handle, SIO_CMD_GET_BYTES, (DCL_CTRL_DATA_T*) &ur_ctrl_getbytes);
    CCCI_PERF_GET_CYCLE(ul_prof[ul_prof_id].tty_conv_rx_CMD_GB_e); 
    ul_prof[ul_prof_id].tty_conv_rx_CMD_GB_t = CCCI_PERF_GET_DURATION(ul_prof[ul_prof_id].tty_conv_rx_CMD_GB_s,ul_prof[ul_prof_id].tty_conv_rx_CMD_GB_e);
    ul_prof_id++;
    if(ul_prof_id >= CCCI_PERF_REC_CNT_1) ul_prof_id = 0;
#else
    ret = DclSerialPort_Control(handle, SIO_CMD_GET_BYTES, (DCL_CTRL_DATA_T*) &ur_ctrl_getbytes);
#endif
    cccitty_it_print("[CCCITTYIT][Conv Rx] SIO_CMD_GET_BYTES return :%d, %d\r\n", ret, ur_ctrl_getbytes.u2RetSize);
    ASSERT(STATUS_OK == ret);
    if(ur_ctrl_getbytes.u2RetSize > 0){
        cccitty_it_print("[CCCITTYIT][Conv Rx] pkt_len:%d\r\n", ur_ctrl_getbytes.u2RetSize);
#ifdef _DUMP_COM_CONTENT_             
        cccitty_it_print("[CCCITTYIT][Conv Rx] Content:\r\n");
        for(i = 0; i<ur_ctrl_getbytes.u2RetSize; i++){
	        cccitty_it_print("%x ", data_buf[i]);
        }  
        cccitty_it_print("\r\n");
#endif 
    }

    
    if(p_cccitty_it_inst->it_mode == CCCI_TTY_IT_LB || p_cccitty_it_inst->it_mode == CCCI_TTY_IT_DL){
        /* TX */
        ur_ctrl_putbytes.u4OwenrId = owner;
        ur_ctrl_putbytes.puBuffaddr = data_buf;
        ur_ctrl_putbytes.u2Length = ur_ctrl_getbytes.u2RetSize;
        if(p_cccitty_it_inst->it_mode == CCCI_TTY_IT_DL && p_cccitty_it_inst->p_data != NULL){
                ur_ctrl_putbytes.puBuffaddr = p_cccitty_it_inst->p_data;
                ur_ctrl_putbytes.u2Length = p_cccitty_it_inst->length;
                p_cccitty_it_inst->p_data = NULL;
                p_cccitty_it_inst->length = 0;
        }
        
        if(ur_ctrl_putbytes.u2Length == 0){
            cccitty_it_print("[CCCITTYIT][Conv TX] Length = 0, WARNING!!\r\n");
            return;
        }

        do{
#ifdef __CCCI_TTY_CONV_TX_DL_PERF__
            CCCI_PERF_GET_CYCLE(dl_prof[dl_prof_id].tty_conv_tx_s);
            ret = DclSerialPort_Control(handle, SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*) &ur_ctrl_putbytes);
            CCCI_PERF_GET_CYCLE(dl_prof[dl_prof_id].tty_conv_tx_e);

            dl_prof[dl_prof_id].tty_conv_tx_t = CCCI_PERF_GET_DURATION(dl_prof[dl_prof_id].tty_conv_tx_s, dl_prof[dl_prof_id].tty_conv_tx_e);
            dl_prof[dl_prof_id].tty_conv_tx_cccih_t = CCCI_PERF_GET_DURATION(dl_prof[dl_prof_id].tty_conv_tx_cccih_s,dl_prof[dl_prof_id].tty_conv_tx_cccih_e);
            dl_prof[dl_prof_id].tty_conv_tx_sdioc_submit_ior_t = CCCI_PERF_GET_DURATION(dl_prof[dl_prof_id].sdioc_submit_ior_s,dl_prof[dl_prof_id].sdioc_submit_ior_e);
            dl_prof_id++;
            if(dl_prof_id >= CCCI_PERF_REC_CNT_1){dl_prof_id = 0;}
#else
            ret = DclSerialPort_Control(handle, SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*) &ur_ctrl_putbytes);
#endif

            cccitty_it_print("[CCCITTYIT][Conv Tx] SIO_CMD_PUT_BYTES return :%d, %d\r\n", ret, ur_ctrl_putbytes.u2RetSize);
            ASSERT(STATUS_OK == ret);
            if(ur_ctrl_putbytes.u2RetSize == 0)
            {
                cccitty_it_print("[CCCITTYIT][Conv Tx write failed!!] [owner: %d] [seq: %x]\r\n", owner, data_buf[8]);
                kal_sleep_task(1);
            }
        }while(ur_ctrl_putbytes.u2RetSize == 0);
        
        if(ur_ctrl_putbytes.u2RetSize > 0){
            cccitty_it_print("[CCCITTYIT][Conv Tx] pkt_len:%d\r\n", ur_ctrl_putbytes.u2RetSize);
#ifdef _DUMP_COM_CONTENT_             
            cccitty_it_print("[CCCITTYIT][Conv Tx] Content:\r\n");
            for(i = 0; i<ur_ctrl_putbytes.u2RetSize; i++){
                cccitty_it_print("%x ", data_buf[i]);
            }
            cccitty_it_print("\r\n");
#endif        
        }
    }
}

static void _cccitty_it_conv_tx_hdr(DCL_HANDLE handle, kal_uint32 owner)
{
    /* reference _tty_ut_conv_tx_conv_rx_rd_handler */
    UART_CTRL_PUT_BYTES_T ur_ctrl_putbytes;
    DCL_STATUS          ret = STATUS_FAIL;
#ifdef _DUMP_COM_CONTENT_
    kal_uint32          i;
#endif
    cccitty_it_instance_t* p_cccitty_it_inst = cccitty_it_get_instance(handle);
    ASSERT(p_cccitty_it_inst);
 
    if(p_cccitty_it_inst->it_mode == CCCI_TTY_IT_DL){
        /* TX */
        ur_ctrl_putbytes.u4OwenrId = owner;
        ur_ctrl_putbytes.puBuffaddr = p_cccitty_it_inst->p_data;
        ur_ctrl_putbytes.u2Length = p_cccitty_it_inst->length;
        p_cccitty_it_inst->p_data = NULL;
        p_cccitty_it_inst->length = 0;
    
        if(ur_ctrl_putbytes.u2Length == 0){
            cccitty_it_print("[CCCITTYIT][Conv TX] Length = 0, WARNING!!\r\n");
            return;
        }

        do{
#ifdef __CCCI_TTY_CONV_TX_DL_PERF__
            CCCI_PERF_GET_CYCLE(dl_prof[dl_prof_id].tty_conv_tx_s);
            ret = DclSerialPort_Control(handle, SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*) &ur_ctrl_putbytes);
            CCCI_PERF_GET_CYCLE(dl_prof[dl_prof_id].tty_conv_tx_e);

            dl_prof[dl_prof_id].tty_conv_tx_t = CCCI_PERF_GET_DURATION(dl_prof[dl_prof_id].tty_conv_tx_s, dl_prof[dl_prof_id].tty_conv_tx_e);
            dl_prof[dl_prof_id].tty_conv_tx_cccih_t = CCCI_PERF_GET_DURATION(dl_prof[dl_prof_id].tty_conv_tx_cccih_s,dl_prof[dl_prof_id].tty_conv_tx_cccih_e);
            dl_prof[dl_prof_id].tty_conv_tx_sdioc_submit_ior_t = CCCI_PERF_GET_DURATION(dl_prof[dl_prof_id].sdioc_submit_ior_s,dl_prof[dl_prof_id].sdioc_submit_ior_e);
            dl_prof_id++;
            if(dl_prof_id >= CCCI_PERF_REC_CNT_1){dl_prof_id = 0;}
#else
            ret = DclSerialPort_Control(handle, SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*) &ur_ctrl_putbytes);
#endif
            cccitty_it_print("[CCCITTYIT][Conv Tx] SIO_CMD_PUT_BYTES return :%d, %d\r\n", ret, ur_ctrl_putbytes.u2RetSize);
            ASSERT(STATUS_OK == ret);
            if(ur_ctrl_putbytes.u2RetSize == 0)
            {
                cccitty_it_print("[CCCITTYIT][Conv Tx write failed!!] [owner: %d] [seq: %x]\r\n", owner, (kal_uint32)ur_ctrl_putbytes.puBuffaddr[0]);
                kal_sleep_task(1);
            }
        }while(ur_ctrl_putbytes.u2RetSize == 0);
        
        if(ur_ctrl_putbytes.u2RetSize > 0){
            cccitty_it_print("[CCCITTYIT][Conv Tx] pkt_len:%d\r\n", ur_ctrl_putbytes.u2RetSize);
#ifdef _DUMP_COM_CONTENT_             
            cccitty_it_print("[CCCITTYIT][Conv Tx] Content:\r\n");
            for(i = 0; i<ur_ctrl_putbytes.u2RetSize; i++){
                cccitty_it_print("%x ", data_buf[i]);
            }
            cccitty_it_print("\r\n");
#endif        
        }
    }
}


static void _cccitty_it_new_tx_conv_rx_hdr(DCL_HANDLE handle, kal_uint32 owner, kal_bool new_tx_light)
{
    /* reference _tty_ut_conv_tx_conv_rx_rd_handler */
    UART_CTRL_GET_BYTES_T ur_ctrl_getbytes;
    DCL_STATUS          ret = STATUS_FAIL;
    qbm_gpd      *tgpd = NULL; 
    DCL_UINT8           *data_buf;
    tty_io_request_t    tx_ior;
#ifdef _DUMP_COM_CONTENT_
    kal_uint32          i;
#endif
    kal_uint32          test;
    cccitty_it_instance_t* p_cccitty_it_inst = cccitty_it_get_instance(handle);
    
    
    while ((tgpd = QBM_ALLOC_ONE(QBM_TYPE_CCCI_COMM)) == NULL){
        kal_sleep_task(1);
    }
    
    if (tgpd != NULL){
        
        ASSERT(tgpd);        
        
        data_buf = (DCL_UINT8*)CCCIDEV_GET_QBM_DATAPTR(tgpd);
      	ur_ctrl_getbytes.u4OwenrId = owner;
    	ur_ctrl_getbytes.puBuffaddr = data_buf;
    	ur_ctrl_getbytes.u2Length = QBM_CCCI_COMM_DATA_LEN;
        
        ret = DclSerialPort_Control(handle, SIO_CMD_GET_BYTES, (DCL_CTRL_DATA_T*) &ur_ctrl_getbytes);
        cccitty_it_print("[CCCITTYIT][Conv Rx] SIO_CMD_GET_BYTES return :%d, %d\r\n", ret, ur_ctrl_getbytes.u2RetSize);
        ASSERT(STATUS_OK == ret);
        if(ur_ctrl_getbytes.u2RetSize > 0){
            cccitty_it_print("[CCCITTYIT][Conv Rx] pkt_len:%d\r\n", ur_ctrl_getbytes.u2RetSize);
#ifdef _DUMP_COM_CONTENT_ 
            cccitty_it_print("[CCCITTYIT][Conv Rx] Content:\r\n");
            for(i = 0; i<ur_ctrl_getbytes.u2RetSize; i++){
                cccitty_it_print("%x ", data_buf[i]);
            }
            cccitty_it_print("\r\n");
#endif            
        }

        if (p_cccitty_it_inst->it_mode == CCCI_TTY_IT_UL || p_cccitty_it_inst->it_mode == CCCI_TTY_IT_DL){
            if (tgpd != NULL){
                QBM_CACHE_INVALID(data_buf, ur_ctrl_getbytes.u2RetSize);
                QBM_FREE_ONE(tgpd);
                tgpd = NULL;
            }
        }
    }else{
        cccitty_it_print("[CCCITTYIT][Conv Rx] TGPD Alloc Fail!!!! \r\n");
    }

    if(p_cccitty_it_inst->it_mode== CCCI_TTY_IT_LB || p_cccitty_it_inst->it_mode == CCCI_TTY_IT_DL){
        if (tgpd != NULL){ /*Loopback Mode*/
            tx_ior.next_request = NULL;
        	tx_ior.first_gpd = tgpd;
        	tx_ior.last_gpd = tgpd;

            CCCICOMM_SET_QBM_DATALEN(tgpd, ur_ctrl_getbytes.u2RetSize); 
            //QBM_DES_SET_HWO(tgpd);
            qbm_cal_set_checksum((void *)tgpd);
            //ASSERT(ur_ctrl_getbytes.u2RetSize > 0);

            //kal_mem_cpy(CCCIDEV_GET_QBM_DATAPTR(tgpd), (void *)data_buf,ur_ctrl_getbytes.u2RetSize);
            //QBM_CACHE_FLUSH(CCCIDEV_GET_QBM_DATAPTR(tgpd), ur_ctrl_getbytes.u2RetSize);

            test = CCCIDEV_GET_QBM_DATALEN(tgpd);
            if(KAL_TRUE == new_tx_light){
                qbmt_cache_flush_q(tgpd, tgpd, 1);
            }
            cccitty_it_print("[CCCITTYIT][New Tx] data len %d\r\n",test);
        }else if (p_cccitty_it_inst->it_mode == CCCI_TTY_IT_DL){
            tx_ior.next_request = NULL;
            if (p_cccitty_it_inst->ior != NULL){
            	tx_ior.first_gpd = p_cccitty_it_inst->ior->first_gpd;
            	tx_ior.last_gpd = p_cccitty_it_inst->ior->last_gpd;
                p_cccitty_it_inst->ior = NULL;
            }
            else {
                cccitty_it_print("[CCCITTYIT][New Tx] DL ior->first_gpd is NULL!!!!!!\r\n");
                return;   
            }
        }else{
            cccitty_it_print("[CCCITTYIT][New Tx] NOT DL MODE and tgpd = NULL, ERROR!!!!!!\r\n");    
            return;
        }
        


        if(KAL_TRUE == new_tx_light){
            /* The hif_set_gpd won't call qbmt_cache_flush_q for recalculating check sum and flush GPD*/
            DclSerialPort_UpModuleTransmitLight(handle, &tx_ior);
        }else{
            DclSerialPort_UpModuleTransmit(handle, &tx_ior);
        }
        
#ifdef _DUMP_COM_CONTENT_ 
        cccitty_it_print("[CCCITTYIT][New Tx] Content:\r\n");
        for(i = 0; i<ur_ctrl_getbytes.u2RetSize; i++){
           cccitty_it_print("%x ", CCCIDEV_GET_QBM_DATAPTR(tgpd));
        }
        cccitty_it_print("\r\n");
#endif            
    }

}


static void _cccitty_it_new_tx_hdr(DCL_HANDLE handle, kal_uint32 owner, kal_bool new_tx_light)
{
    /* reference _tty_ut_conv_tx_conv_rx_rd_handler */
    tty_io_request_t    tx_ior;
    cccitty_it_instance_t* p_cccitty_it_inst = cccitty_it_get_instance(handle);
    
    if(p_cccitty_it_inst->it_mode == CCCI_TTY_IT_DL){

        tx_ior.next_request = NULL;
        if (p_cccitty_it_inst->ior != NULL){
        	tx_ior.first_gpd = p_cccitty_it_inst->ior->first_gpd;
        	tx_ior.last_gpd = p_cccitty_it_inst->ior->last_gpd;
            p_cccitty_it_inst->ior = NULL;
        }
        else {
            cccitty_it_print("[CCCITTYIT][New Tx] DL ior->first_gpd is NULL!!!!!!\r\n");
            return;   
        }
        if(KAL_TRUE == new_tx_light){
            /* The hif_set_gpd won't call qbmt_cache_flush_q for recalculating check sum and flush GPD*/
            DclSerialPort_UpModuleTransmitLight(handle, &tx_ior);
        }else{
            DclSerialPort_UpModuleTransmit(handle, &tx_ior);
        }
              
    }

}



static void cccittyit_test(module_type module_id, kal_uint8 uart_port, kal_uint8 dev_mod, DCL_HANDLE handle)
{
    //ttyut_test
    ilm_struct          current_ilm;
    kal_bool            no_flush_tx = KAL_TRUE;

    kal_mem_set(&current_ilm, 0, sizeof(ilm_struct));
    kaka = 0;
    switch (dev_mod) {
        case DEV_CONV_TX_CONV_RX:
        {
            while (1){
                    kal_sleep_task(10);
                    if(kaka == 1){
                        cccitty_it_print("[CCCITTYIT][ILM_MSG] uart_port:%d waiting msg\r\n", uart_port);
                    }                        
                    while (msg_get_extq_messages() > 0)
                    {
                        if ( msg_receive_extq(&current_ilm) != KAL_TRUE )
                        {
                            break;
                        }
                        switch (current_ilm.msg_id)
                        {
                            case MSG_ID_UART_READY_TO_READ_IND:
                            {
                                cccitty_it_print("[CCCITTYIT][ILM_MSG] MSG_ID_UART_READY_TO_READ_IND uart_port:%d msg_id:%x\r\n", uart_port, current_ilm.msg_id);
                                _cccitty_it_conv_tx_conv_rx_hdr(handle, module_id);
                                break;
                            }
                            case MSG_ID_UART_READY_TO_WRITE_IND:
                            {
                                cccitty_it_print("[CCCITTYIT][ILM_MSG] MSG_ID_UART_READY_TO_WRITE_IND uart_port:%d msg_id:%x\r\n", uart_port, current_ilm.msg_id);
                                break;
                            }
                            default:
                                cccitty_it_print("[CCCITTYIT][ILM_MSG] unsupport msg uart_port:%d msg_id:%x\r\n", uart_port, current_ilm.msg_id);
                                break;
                        }
                        if(kaka == 1){
                            cccitty_it_print("[CCCITTYIT][ILM_MSG] uart_port:%d destroy_ilm\r\n", uart_port);
                        }                        
                        destroy_ilm(&current_ilm);
                        if(kaka == 1){
                            cccitty_it_print("[CCCITTYIT][ILM_MSG] uart_port:%d msg_get_extq_messages\r\n", uart_port);
                        }                        
                    }
            }
            break;
        } //DEV_CONV_TX_CONV_RX
           
       case DEV_NEW_TX_CONV_RX:
       {
            while (1){
                    kal_sleep_task(10);
                    if(kaka == 1){
                        cccitty_it_print("[CCCITTYIT][ILM_MSG] uart_port:%d waiting msg\r\n", uart_port);
                    }                        
                    while (msg_get_extq_messages() > 0)
                    {
                        if ( msg_receive_extq(&current_ilm) != KAL_TRUE )
                        {
                            break;
                        }
                        switch (current_ilm.msg_id)
                        {
                            case MSG_ID_UART_READY_TO_READ_IND:
                            {
                                cccitty_it_print("[CCCITTYIT][ILM_MSG] MSG_ID_UART_READY_TO_READ_IND uart_port:%d msg_id:%x\r\n", uart_port, current_ilm.msg_id);
                                _cccitty_it_new_tx_conv_rx_hdr(handle, module_id, no_flush_tx);
                                if(no_flush_tx == KAL_TRUE){
                                        no_flush_tx = KAL_FALSE;
                                }else{
                                        no_flush_tx = KAL_TRUE;
                                }
                                break;
                            }
                            default:
                                cccitty_it_print("[CCCITTYIT][ILM_MSG] unsupport msg uart_port:%d msg_id:%x\r\n", uart_port, current_ilm.msg_id);
                                break;
                        }
                        if(kaka == 1){
                            cccitty_it_print("[CCCITTYIT][ILM_MSG] uart_port:%d destroy_ilm\r\n", uart_port);
                        }                        
                        destroy_ilm(&current_ilm);
                        if(kaka == 1){
                            cccitty_it_print("[CCCITTYIT][ILM_MSG] uart_port:%d msg_get_extq_messages\r\n", uart_port);
                        }                        
                    }
            }
            break;
        } //DEV_NEW_TX_CONV_RX
        default:
            ASSERT(0);
            break;
    }
}
DCL_STATUS _cccittyit_drv_state_cb(DCL_HANDLE handle, tty_drv_state_e state)
{
	return STATUS_OK;
}


/**************CCCITTY task********************/
kal_bool cccittyit_task_init(void)
{
    return KAL_TRUE;
}

kal_bool ccci_tty_it_create();
static void ccciitdev1_task_main(task_entry_struct *task_entry_ptr)
{
//#if 0
    DCL_HANDLE          handle;
    DCL_STATUS          status;    

    #ifdef __CCCI_IT_CTRL__
        ccci_tty_it_create();
    #endif
    kal_set_active_module_id(CCCITTY_IT_TASK1_MOD);
    handle = DclSerialPort_Open(CCCITTY_IT_TASK1_PORT, 0);
    status = DclSerialPort_UpModuleInit(handle, CCCITTY_IT_TASK1_MOD, CCCITTY_IT_TASK1_FLAG);

    //new user shall register callback function, even though we dont need txdone callback
    //DclSerialPort_UpModuleRegisterCb(handle, NULL, NULL, _cccittyit_drv_state_cb);                     
    ASSERT(status == STATUS_OK);
    cccitty_it_print("=========> open port uart_port_dhl_ccci \r\n");
    cccitty_it_create_instance(handle, CCCITTY_IT_TASK1_MOD, CCCITTY_IT_TASK1_MODE);
    cccittyit_test(CCCITTY_IT_TASK1_MOD, CCCITTY_IT_TASK1_PORT, CCCITTY_IT_TASK1_MODE, handle);
//#endif
}

static void ccciitdev2_task_main(task_entry_struct *task_entry_ptr)
{
    DCL_HANDLE          handle;
    DCL_STATUS          status;    

    kal_set_active_module_id(CCCITTY_IT_TASK2_MOD);
    handle = DclSerialPort_Open(CCCITTY_IT_TASK2_PORT, 0);
    status = DclSerialPort_UpModuleInit(handle, CCCITTY_IT_TASK2_MOD, CCCITTY_IT_TASK2_FLAG);
    ASSERT(status == STATUS_OK);
    cccitty_it_print("=========> open port uart_port_tst_ccci \r\n");
    cccitty_it_create_instance(handle, CCCITTY_IT_TASK2_MOD, CCCITTY_IT_TASK2_MODE);
    cccittyit_test(CCCITTY_IT_TASK2_MOD, CCCITTY_IT_TASK2_PORT, CCCITTY_IT_TASK2_MODE, handle);
}

static void ccciitdev3_task_main(task_entry_struct *task_entry_ptr)
{
//	    DCL_HANDLE          handle;
//	    DCL_STATUS          status;    
//	
//	    kal_set_active_module_id(CCCITTY_IT_TASK3_MOD);
//	    handle = DclSerialPort_Open(CCCITTY_IT_TASK3_PORT, 0);
//	    status = DclSerialPort_UpModuleInit(handle, CCCITTY_IT_TASK3_MOD, CCCITTY_IT_TASK3_FLAG);
//	    ASSERT(status == STATUS_OK);
//	    cccitty_it_print("=========> open port uart_port_at_ccci \r\n");
//	    cccitty_it_create_instance(handle, CCCITTY_IT_TASK3_MOD, CCCITTY_IT_TASK3_MODE);
//	    cccittyit_test(CCCITTY_IT_TASK3_MOD, CCCITTY_IT_TASK3_PORT, CCCITTY_IT_TASK3_MODE, handle);

}

static void ccciitdev4_task_main(task_entry_struct *task_entry_ptr)
{
    DCL_HANDLE          handle;
    DCL_STATUS          status;    

    kal_set_active_module_id(CCCITTY_IT_TASK4_MOD);
    handle = DclSerialPort_Open(CCCITTY_IT_TASK4_PORT, 0);
    status = DclSerialPort_UpModuleInit(handle, CCCITTY_IT_TASK4_MOD, CCCITTY_IT_TASK4_FLAG);
    ASSERT(status == STATUS_OK);
    cccitty_it_print("=========> open port uart_port_gps_ccci \r\n");
    cccitty_it_create_instance(handle, CCCITTY_IT_TASK4_MOD, CCCITTY_IT_TASK4_MODE);
    cccittyit_test(CCCITTY_IT_TASK4_MOD, CCCITTY_IT_TASK4_PORT, CCCITTY_IT_TASK4_MODE, handle);
}


/*********************************************************************************************/

kal_bool ccciitdev1_task_create(comptask_handler_struct **handle)
{
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
}

kal_bool ccciitdev2_task_create(comptask_handler_struct **handle)
{
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
}

kal_bool ccciitdev3_task_create(comptask_handler_struct **handle)
{
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
}

kal_bool ccciitdev4_task_create(comptask_handler_struct **handle)
{
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
}


#ifdef __CCCI_IT_CTRL__
#include "ccci_it_ctrl_if.h"
kal_bool ccci_tty_it_normal(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
    
    cccitty_it_inst_g[(kal_uint32)p_param-1].it_mode = CCCI_TTY_IT_LB;

    return KAL_TRUE;
}

kal_bool ccci_tty_it_loopback(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
    
    cccitty_it_inst_g[(kal_uint32)p_param-1].it_mode = CCCI_TTY_IT_LB;

    return KAL_TRUE;
}

kal_bool ccci_tty_it_downlink_handle(ccci_io_request_t *ior, kal_uint32 dev_num){
    cccitty_it_instance_t *p_dev = &cccitty_it_inst_g[dev_num];
    qbm_gpd* current_gpd;
    
    p_dev->it_mode = CCCI_TTY_IT_DL;
       
    switch (p_dev->mode) {
        case DEV_CONV_TX_CONV_RX:
            current_gpd = ior->first_gpd;
            while(1){
                p_dev->p_data = (DCL_UINT8*)CCCIDEV_GET_QBM_DATAPTR(current_gpd);
                p_dev->length = (DCL_UINT16)CCCIDEV_GET_QBM_DATALEN(current_gpd);
                if ((msg_get_task_extq_capacity(p_dev->owner) - msg_get_task_extq_messages(p_dev->owner))<5){
                    cccitty_it_print("[ccci_tty_it_downlink_handle] Message size (%d) capacity(%d) \r\n", 
                        msg_get_task_extq_messages(p_dev->owner), msg_get_task_extq_capacity(p_dev->owner));
                    kal_sleep_task(1);
                }
                _cccitty_it_conv_tx_hdr(p_dev->handle, p_dev->owner);
                if (current_gpd == ior->last_gpd){
                    break;
                }
                current_gpd = current_gpd->p_next;
            }
            qbmt_dest_q(ior->first_gpd, ior->last_gpd);
            break;

        case DEV_NEW_TX_CONV_RX:
            p_dev->ior = ior;
            _cccitty_it_new_tx_hdr(p_dev->handle, p_dev->owner, KAL_TRUE);
            break;
            
        default:
            ASSERT(0);
            break;
    }
    return KAL_TRUE;    
}


kal_bool ccci_tty_it_downlink(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
    ccci_io_request_t ior = {0};
    ior = ccci_it_gen_packet(QBM_TYPE_CCCI_COMM);
    if (ior.first_gpd != NULL){
        ccci_tty_it_downlink_handle(&ior, (kal_uint32)p_param-1);
    }
    return KAL_TRUE;
}

kal_bool ccci_tty_it_uplink(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
    
    cccitty_it_inst_g[(kal_uint32)p_param-1].it_mode = CCCI_TTY_IT_UL;
    return KAL_TRUE;
}

IT_MODE_T ccci_tty_it_mode_table1[] = {
    {"CCCITTTY[1] ccci_tty_it_normal",      ccci_tty_it_normal,         (void*)1},
    {"CCCITTTY[1] ccci_tty_it_loopback",    ccci_tty_it_loopback,       (void*)1},
    {"CCCITTTY[1] ccci_tty_it_downlink",    ccci_tty_it_downlink,       (void*)1,   1},   
    {"CCCITTTY[1] ccci_tty_it_uplink",      ccci_tty_it_uplink,         (void*)1}, 
};

IT_MODE_T ccci_tty_it_mode_table2[] = {
    {"CCCITTTY[2] ccci_tty_it_normal",      ccci_tty_it_normal,         (void*)2},
    {"CCCITTTY[2] ccci_tty_it_loopback",    ccci_tty_it_loopback,       (void*)2},
    {"CCCITTTY[2] ccci_tty_it_downlink",    ccci_tty_it_downlink,       (void*)2,   1},   
    {"CCCITTTY[2] ccci_tty_it_uplink",      ccci_tty_it_uplink,         (void*)2}, 
};

IT_MODE_T ccci_tty_it_mode_table3[] = {
    {"CCCITTTY[3] ccci_tty_it_normal",      ccci_tty_it_normal,         (void*)3},
    {"CCCITTTY[3] ccci_tty_it_loopback",    ccci_tty_it_loopback,       (void*)3},
    {"CCCITTTY[3] ccci_tty_it_downlink",    ccci_tty_it_downlink,       (void*)3,   1},   
    {"CCCITTTY[3] ccci_tty_it_uplink",      ccci_tty_it_uplink,         (void*)3}, 
};

IT_MODE_T ccci_tty_it_mode_table4[] = {
    {"CCCITTTY[4] ccci_tty_it_normal",      ccci_tty_it_normal,         (void*)4},
    {"CCCITTTY[4] ccci_tty_it_loopback",    ccci_tty_it_loopback,       (void*)4},
    {"CCCITTTY[4] ccci_tty_it_downlink",    ccci_tty_it_downlink,       (void*)4,   1},   
    {"CCCITTTY[4] ccci_tty_it_uplink",      ccci_tty_it_uplink,         (void*)4}, 
};

kal_bool ccci_tty_it_create(){
    ccci_it_mode_control_table_reg("CCCI_TTY1", 
                         ccci_tty_it_mode_table1, 
                         sizeof(ccci_tty_it_mode_table1) / sizeof(IT_MODE_T) 
                        );
    ccci_it_mode_control_table_reg("CCCI_TTY2", 
                         ccci_tty_it_mode_table2, 
                         sizeof(ccci_tty_it_mode_table2) / sizeof(IT_MODE_T) 
                        );
    ccci_it_mode_control_table_reg("CCCI_TTY3", 
                         ccci_tty_it_mode_table3, 
                         sizeof(ccci_tty_it_mode_table3) / sizeof(IT_MODE_T) 
                        );
    ccci_it_mode_control_table_reg("CCCI_TTY4", 
                         ccci_tty_it_mode_table4, 
                         sizeof(ccci_tty_it_mode_table4) / sizeof(IT_MODE_T) 
                        );
    return KAL_TRUE;
}

#endif



#endif  
