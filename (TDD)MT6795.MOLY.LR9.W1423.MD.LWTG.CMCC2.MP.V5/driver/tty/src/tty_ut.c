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
 *   tty_ut.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   TTY Core unit test file - it needs Host Test Program to run test.
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
 * checkin supporting buffer port features
 *
 * removed!
 * removed!
 * 
 * MOLY Migration from TATAKA
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "kal_debug.h"
//#include "kal_release.h"
#include "syscomp_config.h"
#include "kal_debug.h"
#include "dcl.h"
#include "qmu_bm.h"
#include "qmu_bm_util.h"

#include "devdrv_ls.h"
#include "drv_msgid.h"
#include "md_drv_sap.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"

/*for dhl trace*/
#include "dhl_trace.h"

#define TTY_UT_MISC_TEST  (1)    /* Set 1 to enable owner test and init/deinit test*/

#define USB_TEST
//#undef USB_TEST

#if defined USB_TEST    /* USB COM */
#define TTY_UT_COM_NUM  2
#define TTY_UT_COM1     uart_port_usb
#define TTY_UT_COM2     uart_port_usb2     
#define TTY_UT_COM3     uart_port_usb3     

#else   /* UART COM */
#define TTY_UT_COM_NUM  1
#define TTY_UT_COM1     uart_port2
#define TTY_UT_COM2     uart_port2
#define TTY_UT_COM3     uart_port2
#endif

#if (TTY_UT_COM_NUM > 2)
#error "COM number more than three does not support."
#endif


#define IO_REQUEST_PUSH(_ori, _new) \
{ \
    tty_io_request_t *tmp_ior = _ori; \
    while (tmp_ior->next_request != NULL) { \
        tmp_ior = tmp_ior->next_request; \
    } \
    tmp_ior->next_request = _new; \
}

#define BUSY_WAIT(_loopCnt) do{unsigned int i,j;for(i=0;i<_loopCnt;i++){j=i;j++;}}while(0)

typedef enum _tty_ut_mode {
    TTY_UT_CONV_TX_ONLY = 0,
    TTY_UT_NEW_TX_ONLY,
    TTY_UT_CONV_RX_ONLY,
    TTY_UT_NEW_RX_ONLY,
    TTY_UT_CONV_TX_CONV_RX,
    TTY_UT_CONV_TX_NEW_RX,
    TTY_UT_NEW_TX_CONV_RX,
    TTY_UT_NEW_TX_NEW_RX,
    TTY_UT_NEW_INIT_CONV_TX_CONV_RX,
    TTY_UT_BYPASS,                                          //This is used to disable test procedure
} tty_ut_mode_e;

static tty_ut_mode_e tty_ut_mode_1 = TTY_UT_NEW_TX_NEW_RX; //TTY_UT_NEW_TX_NEW_RX;
static tty_ut_mode_e tty_ut_mode_2 = TTY_UT_NEW_TX_NEW_RX; //TTY_UT_CONV_TX_CONV_RX;
static tty_ut_mode_e tty_ut_mode_3 = TTY_UT_NEW_TX_CONV_RX;

// for conventional path
#define TTY_UT_NEW_BUF_SIZE     QBM_TTY_XXX_DATA_LEN
#define TTY_UT_CONV_BUF_SIZE    QBM_TTY_XXX_DATA_LEN*2

#define TTY_UT_LB_CON_TX_TX_BUF_SIZE    QBM_TTY_XXX_DATA_LEN*10

#define TTY_UT_CHUNK_SIZE_DEFAULT (QBM_TTY_XXX_DATA_LEN)

typedef struct _ttyut_instance_t {
    DCL_HANDLE              handle;
    DCL_UINT32              owner;
    tty_io_request_t        *ttyut_rx_ior;
    kal_mutexid             ttyut_mutex;

    kal_uint8 ttyut_rx_buf[TTY_UT_CONV_BUF_SIZE];
    kal_uint8 ttyut_tx_buf[TTY_UT_CONV_BUF_SIZE];
    kal_uint32 ttyut_tx_offset;
    kal_uint32 ttyut_tx_len;

    kal_uint8 conv_tx_rx_buf[TTY_UT_LB_CON_TX_TX_BUF_SIZE];
    kal_uint32 conv_tx_rx_rd_idx;
    kal_uint32 conv_tx_rx_wt_idx;
    kal_uint32 conv_tx_rx_wrap;
} ttyut_instance_t;
static ttyut_instance_t ttyut_inst_g[TTY_UT_COM_NUM];

#if defined(__MTK_TARGET__)
extern void dbg_print(char *fmt,...);
#define ttyut_print dbg_print
#else
#define ttyut_print(...) dhl_print(TRACE_INFO, DHL_USER_FLAG_NONE, MOD_TTY, ##__VA_ARGS__)
#endif

// ==========================================================
// Private Function
// ==========================================================
static kal_bool ttyut_create_instance(DCL_HANDLE handle, DCL_UINT32 owner)
{
    kal_uint8 i;
    char mutex_name_str[64];
    
    for (i=0; i<TTY_UT_COM_NUM; i++) {
        if (ttyut_inst_g[i].handle == (DCL_HANDLE) 0x0) {

            sprintf(mutex_name_str, "TTY_UT_%d", (int)handle);
            ttyut_inst_g[i].handle = handle;
            ttyut_inst_g[i].owner = owner;
            ttyut_inst_g[i].ttyut_rx_ior = NULL;
            ttyut_inst_g[i].ttyut_mutex = kal_create_mutex(mutex_name_str);
            return KAL_TRUE;
        }
    }

    // Can't create TTY_UT instance, ASSERT.
    ASSERT(0);
    return KAL_FALSE;
}

static ttyut_instance_t* ttyut_get_instance(DCL_HANDLE handle)
{
    kal_uint8 i;

    for (i=0; i<TTY_UT_COM_NUM; i++) {
        if (ttyut_inst_g[i].handle == handle) {
            return &ttyut_inst_g[i];
        }
    } 

    return NULL;
}


// ==========================================================
// Private Function
// ==========================================================
DCL_STATUS _ttyut_rx_cb(DCL_HANDLE handle, module_type source_id, tty_io_request_t *rx_ior)
{
    ttyut_instance_t *ttyut_inst_p;

    ttyut_inst_p = ttyut_get_instance(handle);
    if (ttyut_inst_p->ttyut_rx_ior) {
        IO_REQUEST_PUSH(ttyut_inst_p->ttyut_rx_ior, rx_ior);
    } else {
        ttyut_inst_p->ttyut_rx_ior = rx_ior;
    }

    ttyut_print("=========>_ttyut_rx_cb\r\n");
    return STATUS_OK;
}

DCL_STATUS _ttyut_tx_done_cb(DCL_HANDLE handle, module_type source_id, tty_io_request_t *tx_ior)
{
    if (tx_ior) {
        /* free all GPDs of all IOR */
        do {
            qbmt_dest_q(tx_ior->first_gpd, tx_ior->last_gpd);
        } while ((tx_ior = tx_ior->next_request) != NULL);
    } else {
        ttyut_print("[TTY UT] [ERROR] =========>_ttyut_tx_done_cb : tx_ior is NULL!!!!!\r\n");
    }

    ttyut_print("=========>_ttyut_tx_done_cb\r\n");
    return STATUS_OK;
}

DCL_STATUS _ttyut_drv_state_cb(DCL_HANDLE handle, tty_drv_state_e state)
{
    ttyut_print("=========>_ttyut_drv_state_cb: state - %s\r\n", (state==DRV_ST_ATTACHED)?"attached":"detached");
    return STATUS_OK;
}

DCL_STATUS _ttyut_hdr_main(DCL_DEV dev, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
    return STATUS_OK;
}

static kal_bool _ttyut_upmod_init_deinit_test(kal_uint8 uart_port)
{
    #define TEST_ROUND  100
    #define UART_INVALID_PORT 0xFFFF
    DCL_STATUS status;
    DCL_HANDLE handle;
    int idx;
    UART_CTRL_OPEN_T ur_ctrl_open;
    UART_CTRL_CLOSE_T ur_ctrl_close;
    Seriport_HANDLER_T tty_ut_uart_handler = {DCL_UART_USB_TYPE, _ttyut_hdr_main};

    /*Test 1*/
    /* Init non-existed port -> should init failed */
    /* test invalid port 0xFFFF*/
    handle = DclSerialPort_Open(UART_INVALID_PORT, 0);
    if(handle != STATUS_INVALID_DEVICE)
    {
        ttyut_print("[ERROR][TTY UT] DCL upper module open non-existed port successfully");
        return KAL_FALSE;
    }
    /* test non-exist port by invalid handle with NEW API*/
    handle = 0xFFFF;
    status = DclSerialPort_UpModuleInit(handle, MOD_TTY_UT, TTY_FLAG_NEW_TX | TTY_FLAG_NEW_RX);
    if (status == STATUS_OK) {
        ttyut_print("[ERROR][TTY UT] DCL upper module init non-existed port with NEW API successfully");
        return KAL_FALSE;
    }
    /* test non-exist port by invalid handle with Conventional API*/
    handle = 0xFFFF;
    status = DclSerialPort_Control(handle, SIO_CMD_OPEN, (DCL_CTRL_DATA_T*) &ur_ctrl_open);
    if (status == STATUS_OK) {
        ttyut_print("[ERROR][TTY UT] DCL upper module init non-existed port with Conv API successfully");
        return KAL_FALSE;
    }

    /*Test 2 : Driver reg/de-reg API test*/
    /* First register callback -> should not return failed */
    handle = DclSerialPort_Open(uart_max_port, 0);
    for (idx = 0; idx < TEST_ROUND; idx ++)
    {
        status = DclSerialPort_DrvRegisterCb(handle, &tty_ut_uart_handler);
        if (status != STATUS_OK) {
            ttyut_print("[ERROR][TTY UT] Driver first register callback function failed");
            return KAL_FALSE;
        }
        /* Duplicated register -> should return failed */
        status = DclSerialPort_DrvRegisterCb(handle, &tty_ut_uart_handler);
        if (status == STATUS_OK) {
            ttyut_print("[ERROR][TTY UT] Driver first register callback function twice successfully");
            return KAL_FALSE;
        }
        /* First De-register callback -> should not return failed */
        status = DclSerialPort_DrvDeRegisterCb(handle);
        if (status != STATUS_OK) {
            ttyut_print("[ERROR][TTY UT] Driver first De-register callback function failed");
            return KAL_FALSE;
        }
        /* Duplicated register -> should return failed */
        status = DclSerialPort_DrvDeRegisterCb(handle);
        if (status == STATUS_OK) {
            ttyut_print("[ERROR][TTY UT] Driver De-register callback function twice successfully");
            return KAL_FALSE;
        }
    }

    /*Test 3 : open non-registered port with NEW API*/
    /* Init non-register port -> should not return failed */
    handle = DclSerialPort_Open(uart_max_port, 0);
    for (idx = 0; idx < TEST_ROUND; idx ++)
    {
        status = DclSerialPort_UpModuleInit(handle, MOD_TTY_UT, TTY_FLAG_NEW_TX | TTY_FLAG_NEW_RX);
        if (status != STATUS_OK) {
            ttyut_print("[ERROR][TTY UT] DCL upper module first init non-registered port failed");
            return KAL_FALSE;
        }
        /* Duplicated init -> should init failed */
        status = DclSerialPort_UpModuleInit(handle, MOD_TTY_UT, TTY_FLAG_NEW_TX | TTY_FLAG_NEW_RX);
        if (status == STATUS_OK) {
            ttyut_print("[ERROR][TTY UT] DCL upper module init twice (non-registered port)successfully!!");
            return KAL_FALSE;
        }
        /* First deinit -> should deinit successfully */
        status = DclSerialPort_UpModuleDeinit(handle);
        if (status != STATUS_OK) {
            ttyut_print("[ERROR][TTY UT] DCL upper module first deinit non-registered port failed");
            return KAL_FALSE;
        }
        /* Duplicated deinit -> should deinit failed */
        status = DclSerialPort_UpModuleDeinit(handle);
        if (status == STATUS_OK) {
            ttyut_print("[ERROR][TTY UT] DCL upper module deinit twice (non-registered port)successfully!!");
            return KAL_FALSE;
        }
    }

    /*Test 4 : open non-registered port with Conv API*/
    /* Init non-register port -> should not return failed */
    handle = DclSerialPort_Open(uart_max_port, 0);
    ur_ctrl_open.u4OwenrId = MOD_TTY_UT;
    ur_ctrl_close.u4OwenrId = MOD_TTY_UT;
    for (idx = 0; idx < TEST_ROUND; idx ++)
    {
        status = DclSerialPort_Control(handle, SIO_CMD_OPEN, (DCL_CTRL_DATA_T*) &ur_ctrl_open);
        if (status != STATUS_OK) {
            ttyut_print("[ERROR][TTY UT] DCL upper module first init non-registered port failed");
            return KAL_FALSE;
        }
        /* Duplicated init -> should init failed */
        status = DclSerialPort_Control(handle, SIO_CMD_OPEN, (DCL_CTRL_DATA_T*) &ur_ctrl_open);
        if (status == STATUS_OK) {
            ttyut_print("[ERROR][TTY UT] DCL upper module init twice (non-registered port)successfully!!");
            return KAL_FALSE;
        }
        /* First deinit -> should deinit successfully */
        status = DclSerialPort_Control(handle, SIO_CMD_CLOSE, (DCL_CTRL_DATA_T*) &ur_ctrl_close);
        if (status != STATUS_OK) {
            ttyut_print("[ERROR][TTY UT] DCL upper module first deinit non-registered port failed");
            return KAL_FALSE;
        }
        /* Duplicated deinit -> should deinit failed */
        status = DclSerialPort_Control(handle, SIO_CMD_CLOSE, (DCL_CTRL_DATA_T*) &ur_ctrl_close);
        if (status == STATUS_OK) {
            ttyut_print("[ERROR][TTY UT] DCL upper module deinit twice (non-registered port)successfully!!");
            return KAL_FALSE;
        }
    }

    /*Test 5 : open registered port test*/
    handle = DclSerialPort_Open(uart_port, 0);
    for (idx = 0; idx < TEST_ROUND; idx ++)
    {
        /* First init -> should init successfully */
        status = DclSerialPort_UpModuleInit(handle, MOD_TTY_UT, TTY_FLAG_NEW_TX | TTY_FLAG_NEW_RX);
        if (status != STATUS_OK) {
            ttyut_print("[ERROR][TTY UT] DCL upper module init failed");
            return KAL_FALSE;
        }
        DclSerialPort_UpModuleRegisterCb(handle, _ttyut_rx_cb, NULL, _ttyut_drv_state_cb);

        /* Duplicated init -> should init failed */
        status = DclSerialPort_UpModuleInit(handle, MOD_TTY_UT, TTY_FLAG_NEW_TX | TTY_FLAG_NEW_RX);
        if (status == STATUS_OK) {
            ttyut_print("[ERROR][TTY UT] DCL upper module init twice successfully!!");
            return KAL_FALSE;
        }

        /* First deinit -> should deinit successfully */
        status = DclSerialPort_UpModuleDeinit(handle);
        if (status != STATUS_OK) {
            ttyut_print("[ERROR][TTY UT] DCL upper module init failed");
            return KAL_FALSE;
        }

        /* Duplicated deinit -> should deinit failed */
        status = DclSerialPort_UpModuleDeinit(handle);
        if (status == STATUS_OK) {
            ttyut_print("[ERROR][TTY UT] DCL upper module init failed");
            return KAL_FALSE;
        }
    }

    return KAL_TRUE;
}

static kal_bool _ttyut_upmod_change_owner_test()
{
    DCL_STATUS status;
    DCL_HANDLE handle;  
    UART_CTRL_OPEN_T ur_ctrl_open;
    UART_CTRL_CLOSE_T ur_ctrl_close;
    UART_CTRL_OWNER_T ur_ctrl_owner;
    UART_CTRL_GET_DRV_STATE_T getDrvState;
    UART_CTRL_GET_CHUNK_SIZE_T getChunkSize;
    
    handle = DclSerialPort_Open(TTY_UT_COM1, 0);

    kal_sleep_task(3000);


    /* Conventional owner change to conventional owner */
    {
        UART_CTRL_PUT_BYTES_T ur_ctrl_putbytes;
        char *test_string1 = "[Change owner test] Conventional Owner A change to ";
        char *test_string2 = "Conventional owner B\r\n";
        
        ur_ctrl_open.u4OwenrId = MOD_TTY_UT;
        DclSerialPort_Control(handle, SIO_CMD_OPEN, (DCL_CTRL_DATA_T*) &ur_ctrl_open);

        /* Send string */
        ur_ctrl_putbytes.u4OwenrId = MOD_TTY_UT;
        ur_ctrl_putbytes.puBuffaddr = (DCL_UINT8*)test_string1;
        ur_ctrl_putbytes.u2Length = strlen(test_string1);
        DclSerialPort_Control(handle, SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*) &ur_ctrl_putbytes);
        kal_sleep_task(1);

        /* Change owner to MOD_TTY_UT99 */
        ur_ctrl_owner.u4OwenrId = MOD_TTY_UT99;
        DclSerialPort_Control(handle, SIO_CMD_SET_OWNER, (DCL_CTRL_DATA_T*) &ur_ctrl_owner);

        kal_set_active_module_id(MOD_TTY_UT99);
        
        /* Send string */
        ur_ctrl_putbytes.u4OwenrId = MOD_TTY_UT99;
        ur_ctrl_putbytes.puBuffaddr = (DCL_UINT8*)test_string2;
        ur_ctrl_putbytes.u2Length = strlen(test_string2);
        DclSerialPort_Control(handle, SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*) &ur_ctrl_putbytes);
        kal_sleep_task(1);

        /* Close com port */
        ur_ctrl_close.u4OwenrId = MOD_TTY_UT99;
        DclSerialPort_Control(handle, SIO_CMD_CLOSE, (DCL_CTRL_DATA_T*) &ur_ctrl_close);

        kal_set_active_module_id(MOD_TTY_UT);
    }

    BUSY_WAIT(1000);
    
    /* Conventional owner change to new owner */
    {
        UART_CTRL_PUT_BYTES_T ur_ctrl_putbytes;
        char *test_string1 = "[Change owner test] Conventional Owner A change to ";
        char *test_string2 = "New owner B\r\n";
        void *tx_gpd;
        tty_io_request_t *tx_ior;
        unsigned char *tx_buf_ptr;

        ur_ctrl_open.u4OwenrId = MOD_TTY_UT;
        DclSerialPort_Control(handle, SIO_CMD_OPEN, (DCL_CTRL_DATA_T*) &ur_ctrl_open);

        /* Send string */
        ur_ctrl_putbytes.u4OwenrId = MOD_TTY_UT;
        ur_ctrl_putbytes.puBuffaddr = (DCL_UINT8*)test_string1;
        ur_ctrl_putbytes.u2Length = strlen(test_string1);
        DclSerialPort_Control(handle, SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*) &ur_ctrl_putbytes);
        kal_sleep_task(1);

        /* Change owner to MOD_TTY_UT99 */
        ur_ctrl_owner.u4OwenrId = MOD_TTY_UT99;
        DclSerialPort_Control(handle, SIO_CMD_SET_OWNER, (DCL_CTRL_DATA_T*) &ur_ctrl_owner);
        kal_set_active_module_id(MOD_TTY_UT99);
        DclSerialPort_UpModuleReinit(handle, MOD_TTY_UT99, TTY_FLAG_NEW_TX | TTY_FLAG_NEW_RX);
        DclSerialPort_UpModuleRegisterCb(handle, _ttyut_rx_cb, NULL, _ttyut_drv_state_cb);

        // Wait for device ready
        getDrvState.u4OwnerId = MOD_TTY_UT;
        do {
            kal_sleep_task(100);
            status = DclSerialPort_Control(handle, TTY_CMD_GET_DRV_STATE, (DCL_CTRL_DATA_T*) &getDrvState);
        } while (getDrvState.drv_state != DRV_ST_ATTACHED);

        // Get chunk size
        do {
            kal_sleep_task(100);
            status = DclSerialPort_Control(handle, TTY_CMD_GET_CHUNK_SIZE, (DCL_CTRL_DATA_T*) &getChunkSize);
        } while (status != STATUS_OK);

        /* Send string */
        tx_gpd = QBM_ALLOC_ONE(QBM_TYPE_TTY_TYPE1);
        if (tx_gpd) {
            tx_ior = (tty_io_request_t*)QBM_DES_GET_SW_CTRL_FIELD(tx_gpd);
            tx_ior->next_request = NULL;
            tx_ior->first_gpd = tx_gpd;
            tx_ior->last_gpd = tx_gpd;
            
            tx_buf_ptr = QBM_DES_GET_DATAPTR(tx_gpd);
            kal_mem_cpy((void*)tx_buf_ptr, test_string2, strlen(test_string2));
            QBM_DES_SET_DATALEN(tx_gpd, strlen(test_string2)); // Set data length

            QBM_DES_SET_HWO(tx_gpd);
            qbm_cal_set_checksum(tx_gpd);
            //QBM_CACHE_FLUSH(tx_gpd, sizeof(qbm_gpd));

            DclSerialPort_UpModuleTransmit(handle, tx_ior);
        } else {
            ttyut_print("[ERROR] [TTY UT] GPD allocate failed in QBM_TYPE_TTY_TYPE1 type\r\n");
            return KAL_FALSE;
        }
        kal_sleep_task(1);

        /* Close com port */
        DclSerialPort_UpModuleDeinit(handle);

        kal_set_active_module_id(MOD_TTY_UT);
    }

    BUSY_WAIT(1000);

    /* New owner change to new owner */
    {
        char *test_string1 = "[Change owner test] New Owner A change to ";
        char *test_string2 = "New owner B\r\n";
        void *tx_gpd;
        tty_io_request_t *tx_ior;
        unsigned char *tx_buf_ptr;      
        UART_CTRL_CLR_BUFFER_T ur_ctrl_clr_buf;

        /* Bind COM port - initialization */
        status = DclSerialPort_UpModuleInit(handle, MOD_TTY_UT, TTY_FLAG_NEW_TX | TTY_FLAG_NEW_RX);
        if (status != STATUS_OK) {
            ttyut_print("[TTY UT] DCL upper module init failed");
            return KAL_FALSE;
        } else {
            DclSerialPort_UpModuleRegisterCb(handle, _ttyut_rx_cb, NULL, _ttyut_drv_state_cb);
            // Wait for device ready
            getDrvState.u4OwnerId = MOD_TTY_UT;
            do {
                kal_sleep_task(100);
                status = DclSerialPort_Control(handle, TTY_CMD_GET_DRV_STATE, (DCL_CTRL_DATA_T*) &getDrvState);
            } while (getDrvState.drv_state != DRV_ST_ATTACHED);

            // Get chunk size
            do {
                kal_sleep_task(100);
                status = DclSerialPort_Control(handle, TTY_CMD_GET_CHUNK_SIZE, (DCL_CTRL_DATA_T*) &getChunkSize);
            } while (status != STATUS_OK);  
        }
        
        /* Send string */
        tx_gpd = QBM_ALLOC_ONE(QBM_TYPE_TTY_TYPE1);
        if (tx_gpd) {
            tx_ior = (tty_io_request_t*)QBM_DES_GET_SW_CTRL_FIELD(tx_gpd);
            tx_ior->next_request = NULL;
            tx_ior->first_gpd = tx_gpd;
            tx_ior->last_gpd = tx_gpd;
            
            tx_buf_ptr = QBM_DES_GET_DATAPTR(tx_gpd);
            kal_mem_cpy((void*)tx_buf_ptr, test_string1, strlen(test_string1));
            QBM_DES_SET_DATALEN(tx_gpd, strlen(test_string1)); // Set data length

            QBM_DES_SET_HWO(tx_gpd);
            qbm_cal_set_checksum(tx_gpd);
            QBM_CACHE_FLUSH(tx_gpd, sizeof(qbm_gpd));

            DclSerialPort_UpModuleTransmit(handle, tx_ior);
        } else {
            ttyut_print("[ERROR] [TTY UT] GPD allocate failed in QBM_TYPE_TTY_TYPE1 type\r\n");
            return KAL_FALSE;
        }
        kal_sleep_task(1);

        /* Send Clear Tx/Rx buffer commands */
        ur_ctrl_clr_buf.u4OwenrId = MOD_TTY_UT; 
        DclSerialPort_Control(handle, SIO_CMD_CLR_TX_BUF, (DCL_CTRL_DATA_T*) &ur_ctrl_clr_buf);
        DclSerialPort_Control(handle, SIO_CMD_CLR_RX_BUF, (DCL_CTRL_DATA_T*) &ur_ctrl_clr_buf);

        /* Change owner to MOD_TTY_UT99 */
        ur_ctrl_owner.u4OwenrId = MOD_TTY_UT99;
        DclSerialPort_Control(handle, SIO_CMD_SET_OWNER, (DCL_CTRL_DATA_T*) &ur_ctrl_owner);
        kal_set_active_module_id(MOD_TTY_UT99);
        DclSerialPort_UpModuleReinit(handle, MOD_TTY_UT99, TTY_FLAG_NEW_TX | TTY_FLAG_NEW_RX);
        DclSerialPort_UpModuleRegisterCb(handle, _ttyut_rx_cb, NULL, _ttyut_drv_state_cb);

        // Wait for device ready
        getDrvState.u4OwnerId = MOD_TTY_UT;
        do {
            kal_sleep_task(100);
            status = DclSerialPort_Control(handle, TTY_CMD_GET_DRV_STATE, (DCL_CTRL_DATA_T*) &getDrvState);
        } while (getDrvState.drv_state != DRV_ST_ATTACHED);

        // Get chunk size
        do {
            kal_sleep_task(100);
            status = DclSerialPort_Control(handle, TTY_CMD_GET_CHUNK_SIZE, (DCL_CTRL_DATA_T*) &getChunkSize);
        } while (status != STATUS_OK);

        /* Send string */
        tx_gpd = QBM_ALLOC_ONE(QBM_TYPE_TTY_TYPE1);
        if (tx_gpd) {
            tx_ior = (tty_io_request_t*)QBM_DES_GET_SW_CTRL_FIELD(tx_gpd);
            tx_ior->next_request = NULL;
            tx_ior->first_gpd = tx_gpd;
            tx_ior->last_gpd = tx_gpd;
            
            tx_buf_ptr = QBM_DES_GET_DATAPTR(tx_gpd);
            kal_mem_cpy((void*)tx_buf_ptr, test_string2, strlen(test_string2));
            QBM_DES_SET_DATALEN(tx_gpd, strlen(test_string2)); // Set data length

            QBM_DES_SET_HWO(tx_gpd);
            qbm_cal_set_checksum(tx_gpd);
            //QBM_CACHE_FLUSH(tx_gpd, sizeof(qbm_gpd));

            DclSerialPort_UpModuleTransmit(handle, tx_ior);
        } else {
            ttyut_print("[ERROR] [TTY UT] GPD allocate failed in QBM_TYPE_TTY_TYPE1 type\r\n");
            return KAL_FALSE;
        }
        kal_sleep_task(1);

        /* Close com port */
        DclSerialPort_UpModuleDeinit(handle);

        kal_set_active_module_id(MOD_TTY_UT);
    }

    BUSY_WAIT(1000);

    /* New owner change to conventional owner */
    {
        UART_CTRL_PUT_BYTES_T ur_ctrl_putbytes;
        char *test_string1 = "[Change owner test] New Owner A change to ";
        char *test_string2 = "Conventional owner B\r\nPASS\r\n";
        void *tx_gpd;
        tty_io_request_t *tx_ior;
        unsigned char *tx_buf_ptr;
        UART_CTRL_CLR_BUFFER_T ur_ctrl_clr_buf;
            
        /* Bind COM port - initialization */
        status = DclSerialPort_UpModuleInit(handle, MOD_TTY_UT, TTY_FLAG_NEW_TX | TTY_FLAG_NEW_RX);
        if (status != STATUS_OK) {
            ttyut_print("[TTY UT] DCL upper module init failed");
            return KAL_FALSE;
        } else {
            DclSerialPort_UpModuleRegisterCb(handle, _ttyut_rx_cb, NULL, _ttyut_drv_state_cb);

            // Wait for device ready
            getDrvState.u4OwnerId = MOD_TTY_UT;

            do {
                kal_sleep_task(100);
                status = DclSerialPort_Control(handle, TTY_CMD_GET_DRV_STATE, (DCL_CTRL_DATA_T*) &getDrvState);
            } while (getDrvState.drv_state != DRV_ST_ATTACHED);

            // Get chunk size
            do {
                kal_sleep_task(100);
                status = DclSerialPort_Control(handle, TTY_CMD_GET_CHUNK_SIZE, (DCL_CTRL_DATA_T*) &getChunkSize);
            } while (status != STATUS_OK);
        }
        
        /* Send string */
        tx_gpd = QBM_ALLOC_ONE(QBM_TYPE_TTY_TYPE1);
        if (tx_gpd) {
            tx_ior = (tty_io_request_t*)QBM_DES_GET_SW_CTRL_FIELD(tx_gpd);
            tx_ior->next_request = NULL;
            tx_ior->first_gpd = tx_gpd;
            tx_ior->last_gpd = tx_gpd;
            
            tx_buf_ptr = QBM_DES_GET_DATAPTR(tx_gpd);
            kal_mem_cpy((void*)tx_buf_ptr, test_string1, strlen(test_string1));
            QBM_DES_SET_DATALEN(tx_gpd, strlen(test_string1)); // Set data length

            QBM_DES_SET_HWO(tx_gpd);
            qbm_cal_set_checksum(tx_gpd);
            //QBM_CACHE_FLUSH(tx_gpd, sizeof(qbm_gpd));

            DclSerialPort_UpModuleTransmit(handle, tx_ior);
        } else {
            ttyut_print("[ERROR] [TTY UT] GPD allocate failed in QBM_TYPE_TTY_TYPE1 type\r\n");
            return KAL_FALSE;
        }
        kal_sleep_task(1);

        /* Send Clear Tx/Rx buffer commands */
        ur_ctrl_clr_buf.u4OwenrId = MOD_TTY_UT;
        DclSerialPort_Control(handle, SIO_CMD_CLR_TX_BUF, (DCL_CTRL_DATA_T*) &ur_ctrl_clr_buf);
        DclSerialPort_Control(handle, SIO_CMD_CLR_RX_BUF, (DCL_CTRL_DATA_T*) &ur_ctrl_clr_buf);

        /* Change owner to MOD_TTY_UT99 */
        ur_ctrl_owner.u4OwenrId = MOD_TTY_UT99;
        DclSerialPort_Control(handle, SIO_CMD_SET_OWNER, (DCL_CTRL_DATA_T*) &ur_ctrl_owner);

        kal_set_active_module_id(MOD_TTY_UT99);

        /* Send string */
        ur_ctrl_putbytes.u4OwenrId = MOD_TTY_UT99;
        ur_ctrl_putbytes.puBuffaddr = (DCL_UINT8*)test_string2;
        ur_ctrl_putbytes.u2Length = strlen(test_string2);
        DclSerialPort_Control(handle, SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*) &ur_ctrl_putbytes);
        kal_sleep_task(1);

        /* Close com port */
        ur_ctrl_close.u4OwenrId = MOD_TTY_UT99;
        DclSerialPort_Control(handle, SIO_CMD_CLOSE, (DCL_CTRL_DATA_T*) &ur_ctrl_close);

        kal_set_active_module_id(MOD_TTY_UT);
    }

    BUSY_WAIT(1000);

    return KAL_TRUE;
}

static kal_bool ttyut_test_preproc(tty_ut_mode_e test_mode, kal_uint8 uart_port)
{
    DCL_STATUS status;
    DCL_HANDLE handle;
    DCL_UINT32 owner = MOD_NIL;

    handle = DclSerialPort_Open(uart_port, 0);

    if (TTY_UT_COM1 == uart_port) {
        owner = MOD_TTY_UT;
    } else if (TTY_UT_COM2 == uart_port) {
        owner = MOD_TTY_UT2;
    } else if (TTY_UT_COM3 == uart_port) {
        owner = MOD_TTY_UT3;
    } else {
        // Unsupported mode, ASSERT.
        ASSERT(0);
    }
    ttyut_create_instance(handle, owner);

    switch (test_mode)
    {
        case TTY_UT_BYPASS:
            {
                //Do nothing;
                break;
            }
        case TTY_UT_CONV_TX_CONV_RX:
        case TTY_UT_CONV_TX_ONLY:
        case TTY_UT_CONV_RX_ONLY:
            {
                UART_CTRL_OPEN_T data;
                data.u4OwenrId = owner;
                DclSerialPort_Control(handle, SIO_CMD_OPEN, (DCL_CTRL_DATA_T*) &data);
            }
            break;

        case TTY_UT_NEW_INIT_CONV_TX_CONV_RX:
            {
                status = DclSerialPort_UpModuleInit(handle, owner, 0);
                if (status != STATUS_OK) {
                    ttyut_print("[TTY UT] DCL upper module init failed");
                }
            }
            break;
        case TTY_UT_NEW_TX_NEW_RX:  
        case TTY_UT_NEW_TX_ONLY:
        case TTY_UT_NEW_RX_ONLY:
            {
                void *rx_gpd_first, *rx_gpd_last;
                tty_io_request_t *rx_ior;
                void *rx_gpd_tmp;
                int i;
                UART_CTRL_GET_DRV_STATE_T getDrvState;
                UART_CTRL_GET_CHUNK_SIZE_T getChunkSize;
                
                /* Bind COM port - initialization */
                status = DclSerialPort_UpModuleInit(handle, owner, TTY_FLAG_NEW_TX | TTY_FLAG_NEW_RX);
                if (status != STATUS_OK) {
                    ttyut_print("[TTY UT] DCL upper module init failed");
                } else {
                    DclSerialPort_UpModuleRegisterCb(handle, _ttyut_rx_cb, _ttyut_tx_done_cb, _ttyut_drv_state_cb);

                    // Wait for device ready
                    getDrvState.u4OwnerId = owner;
                    do {
                        kal_sleep_task(100);
                        status = DclSerialPort_Control(handle, TTY_CMD_GET_DRV_STATE, (DCL_CTRL_DATA_T*) &getDrvState);
                    } while ((getDrvState.drv_state != DRV_ST_ATTACHED) || (status != STATUS_OK));

                    // Get chunk size
                    do {
                        kal_sleep_task(100);
                        status = DclSerialPort_Control(handle, TTY_CMD_GET_CHUNK_SIZE, (DCL_CTRL_DATA_T*) &getChunkSize);
                    } while (status != STATUS_OK);

                    qbmt_alloc_q_no_tail(QBM_TYPE_TTY_TYPE1, 2, &rx_gpd_first, &rx_gpd_last);
                    rx_gpd_tmp = rx_gpd_first;

                    if (!rx_gpd_first || !rx_gpd_last) {
                        ttyut_print("[TTY UT] DCL upper module init failed");
                        return KAL_FALSE;
                    }
                                        
                    // Set allow length
                    for (i=0; i<2; i++) {
                        if(getChunkSize.chunkSize == 1)  //Some HIF doesn't have chunksize restrictions(ex: uart)
                        {
                            QBM_DES_SET_ALLOW_LEN(rx_gpd_tmp, TTY_UT_CHUNK_SIZE_DEFAULT);
                        }
                        else
                        {
                            QBM_DES_SET_ALLOW_LEN(rx_gpd_tmp, (kal_uint16)getChunkSize.chunkSize);
                        }
                        qbm_cal_set_checksum((kal_uint8*)rx_gpd_tmp);
                        QBM_CACHE_FLUSH(rx_gpd_tmp, sizeof(qbm_gpd));
                        rx_gpd_tmp = QBM_DES_GET_NEXT(rx_gpd_tmp);
                    }
                    
                    rx_ior = (tty_io_request_t*)QBM_DES_GET_SW_CTRL_FIELD(rx_gpd_first);
                    rx_ior->next_request = NULL;
                    rx_ior->first_gpd = rx_gpd_first;
                    rx_ior->last_gpd = rx_gpd_last;
                    
                    DclSerialPort_UpModuleAssignRxIor(handle, rx_ior);
                }
            }
            break;

        case TTY_UT_CONV_TX_NEW_RX:
            {
                void *rx_gpd_first, *rx_gpd_last;
                tty_io_request_t *rx_ior;
                void *rx_gpd_tmp;
                int i;
                UART_CTRL_GET_DRV_STATE_T getDrvState;
                UART_CTRL_GET_CHUNK_SIZE_T getChunkSize;
                
                /* Bind COM port - initialization */
                status = DclSerialPort_UpModuleInit(handle, owner, TTY_FLAG_NEW_RX);
                if (status != STATUS_OK) {
                    ttyut_print("[TTY UT] DCL upper module init failed");
                } else {
                    DclSerialPort_UpModuleRegisterCb(handle, _ttyut_rx_cb, NULL, _ttyut_drv_state_cb);

                    // Wait for device ready
                    getDrvState.u4OwnerId = owner;
                    do {
                        kal_sleep_task(100);
                        status = DclSerialPort_Control(handle, TTY_CMD_GET_DRV_STATE, (DCL_CTRL_DATA_T*) &getDrvState);
                    } while ((getDrvState.drv_state != DRV_ST_ATTACHED) || (status != STATUS_OK));

                    // Get chunk size
                    do {
                        kal_sleep_task(100);
                        status = DclSerialPort_Control(handle, TTY_CMD_GET_CHUNK_SIZE, (DCL_CTRL_DATA_T*) &getChunkSize);
                    } while (status != STATUS_OK);

                    qbmt_alloc_q_no_tail(QBM_TYPE_TTY_TYPE1, 2, &rx_gpd_first, &rx_gpd_last);
                    rx_gpd_tmp = rx_gpd_first;

                    if (!rx_gpd_first || !rx_gpd_last) {
                        ttyut_print("[TTY UT] DCL upper module init failed");
                        return KAL_FALSE;
                    }

                    // Set allow length
                    for (i=0; i<2; i++) {
                        QBM_DES_SET_ALLOW_LEN(rx_gpd_tmp, (kal_uint16)getChunkSize.chunkSize);
                        qbm_cal_set_checksum((kal_uint8*)rx_gpd_tmp);
                        QBM_CACHE_FLUSH(rx_gpd_tmp, sizeof(qbm_gpd));
                        rx_gpd_tmp = QBM_DES_GET_NEXT(rx_gpd_tmp);
                    }

                    rx_ior = (tty_io_request_t*)QBM_DES_GET_SW_CTRL_FIELD(rx_gpd_first);
                    rx_ior->next_request = NULL;
                    rx_ior->first_gpd = rx_gpd_first;
                    rx_ior->last_gpd = rx_gpd_last;

                    DclSerialPort_UpModuleAssignRxIor(handle, rx_ior);
                }
            }
            break;

        case TTY_UT_NEW_TX_CONV_RX:
            {
                UART_CTRL_GET_DRV_STATE_T getDrvState;

                /* Bind COM port - initialization */
                status = DclSerialPort_UpModuleInit(handle, owner, TTY_FLAG_NEW_TX);
                if (status != STATUS_OK) {
                    ttyut_print("[TTY UT] DCL upper module init failed");
                } else {
                    DclSerialPort_UpModuleRegisterCb(handle, NULL, NULL, _ttyut_drv_state_cb);

                    // Wait for device ready
                    getDrvState.u4OwnerId = owner;
                    do {
                        kal_sleep_task(100);
                        status = DclSerialPort_Control(handle, TTY_CMD_GET_DRV_STATE, (DCL_CTRL_DATA_T*) &getDrvState);
                    } while ((getDrvState.drv_state != DRV_ST_ATTACHED) || (status != STATUS_OK));
                }
            }
            break;
            
        default:
            break;
    }

    return KAL_TRUE;
}

static void _tty_ut_conv_tx_conv_rx_rd_handler(DCL_HANDLE handle)
{
    UART_CTRL_GET_BYTES_T ur_ctrl_getbytes;
    UART_CTRL_PUT_BYTES_T ur_ctrl_putbytes;
    ttyut_instance_t *ttyut_inst_p;

    ttyut_inst_p = ttyut_get_instance(handle);
    ur_ctrl_getbytes.u4OwenrId = ttyut_inst_p->owner;
    ur_ctrl_getbytes.puBuffaddr = ttyut_inst_p->conv_tx_rx_buf + ttyut_inst_p->conv_tx_rx_rd_idx;
    ur_ctrl_getbytes.u2Length = ttyut_inst_p->conv_tx_rx_wrap
                                ? (ttyut_inst_p->conv_tx_rx_wt_idx - ttyut_inst_p->conv_tx_rx_rd_idx)
                                : (TTY_UT_LB_CON_TX_TX_BUF_SIZE - ttyut_inst_p->conv_tx_rx_rd_idx);
    if (ur_ctrl_getbytes.u2Length == 0) {
        return;
    }
    
    if (STATUS_OK == DclSerialPort_Control(handle, SIO_CMD_GET_BYTES, (DCL_CTRL_DATA_T*) &ur_ctrl_getbytes)
        && ur_ctrl_getbytes.u2RetSize > 0)
    {
        ttyut_inst_p->conv_tx_rx_rd_idx += ur_ctrl_getbytes.u2RetSize;
        
        if (ttyut_inst_p->conv_tx_rx_rd_idx == TTY_UT_LB_CON_TX_TX_BUF_SIZE ) {
            /* reach the end of buffer, wrap to head */
            ASSERT(ttyut_inst_p->conv_tx_rx_wrap == 0);
            ttyut_inst_p->conv_tx_rx_rd_idx = 0;
            ttyut_inst_p->conv_tx_rx_wrap = 1;
        }

        ur_ctrl_putbytes.u4OwenrId = ttyut_inst_p->owner;
        ur_ctrl_putbytes.puBuffaddr = ttyut_inst_p->conv_tx_rx_buf + ttyut_inst_p->conv_tx_rx_wt_idx;
        ur_ctrl_putbytes.u2Length = ttyut_inst_p->conv_tx_rx_wrap
                                    ? (TTY_UT_LB_CON_TX_TX_BUF_SIZE - ttyut_inst_p->conv_tx_rx_wt_idx)
                                    : (ttyut_inst_p->conv_tx_rx_rd_idx - ttyut_inst_p->conv_tx_rx_wt_idx);
        ASSERT(ur_ctrl_putbytes.u2Length > 0);
    
        if (STATUS_OK == DclSerialPort_Control(handle, SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*) &ur_ctrl_putbytes)
            && ur_ctrl_putbytes.u2RetSize > 0)
        {
            ttyut_inst_p->conv_tx_rx_wt_idx += ur_ctrl_putbytes.u2RetSize;
            
            if (ttyut_inst_p->conv_tx_rx_wt_idx == TTY_UT_LB_CON_TX_TX_BUF_SIZE ) {
                /* reach the end of buffer, de-wrap to head */
                ASSERT(ttyut_inst_p->conv_tx_rx_wrap == 1);
                ttyut_inst_p->conv_tx_rx_wt_idx = 0;
                ttyut_inst_p->conv_tx_rx_wrap = 0;

                if (ttyut_inst_p->conv_tx_rx_rd_idx > 0) {
                    ur_ctrl_putbytes.u4OwenrId = ttyut_inst_p->owner;
                    ur_ctrl_putbytes.puBuffaddr = ttyut_inst_p->conv_tx_rx_buf;
                    ur_ctrl_putbytes.u2Length = ttyut_inst_p->conv_tx_rx_rd_idx - ttyut_inst_p->conv_tx_rx_wt_idx;
                    if (STATUS_OK == DclSerialPort_Control(handle, SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*) &ur_ctrl_putbytes)
                        && ur_ctrl_putbytes.u2RetSize > 0)
                    {
                        ttyut_inst_p->conv_tx_rx_wt_idx += ur_ctrl_putbytes.u2RetSize;
                    }
                }
            }
        }
    }
}

static void _ttyut_process_ilm(DCL_HANDLE handle, ilm_struct *ilm_ptr, tty_ut_mode_e test_mode)
{
    ttyut_instance_t *ttyut_inst_p;

    ASSERT(ilm_ptr != NULL);

    ttyut_inst_p = ttyut_get_instance(handle);

    if (ilm_ptr != NULL)
    {
        switch (ilm_ptr->msg_id)
        {
            case MSG_ID_UART_READY_TO_WRITE_IND:
                {
                    UART_CTRL_PUT_BYTES_T ur_ctrl_putbytes;
                    
                    if (test_mode == TTY_UT_CONV_TX_CONV_RX || test_mode == TTY_UT_NEW_INIT_CONV_TX_CONV_RX)
                    {
                        ur_ctrl_putbytes.u4OwenrId = ttyut_inst_p->owner;
                        ur_ctrl_putbytes.puBuffaddr = ttyut_inst_p->conv_tx_rx_buf + ttyut_inst_p->conv_tx_rx_wt_idx;
                        ur_ctrl_putbytes.u2Length = ttyut_inst_p->conv_tx_rx_wrap
                                                    ? (TTY_UT_LB_CON_TX_TX_BUF_SIZE - ttyut_inst_p->conv_tx_rx_wt_idx)
                                                    : (ttyut_inst_p->conv_tx_rx_rd_idx - ttyut_inst_p->conv_tx_rx_wt_idx);

                        if (ur_ctrl_putbytes.u2Length > 0
                            && STATUS_OK == DclSerialPort_Control(handle, SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*) &ur_ctrl_putbytes)
                            && ur_ctrl_putbytes.u2RetSize > 0)
                        {
                            ttyut_inst_p->conv_tx_rx_wt_idx += ur_ctrl_putbytes.u2RetSize;
                            
                            if (ttyut_inst_p->conv_tx_rx_wt_idx == TTY_UT_LB_CON_TX_TX_BUF_SIZE ) {
                                /* reach the end of buffer, de-wrap to head */
                                ASSERT(ttyut_inst_p->conv_tx_rx_wrap == 1);
                                ttyut_inst_p->conv_tx_rx_wt_idx = 0;
                                ttyut_inst_p->conv_tx_rx_wrap = 0;
                                
                                if (ttyut_inst_p->conv_tx_rx_rd_idx > 0) {
                                    ur_ctrl_putbytes.u4OwenrId = ttyut_inst_p->owner;
                                    ur_ctrl_putbytes.puBuffaddr = ttyut_inst_p->conv_tx_rx_buf;
                                    ur_ctrl_putbytes.u2Length = ttyut_inst_p->conv_tx_rx_rd_idx - ttyut_inst_p->conv_tx_rx_wt_idx;
                                    if (STATUS_OK == DclSerialPort_Control(handle, SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*) &ur_ctrl_putbytes)
                                        && ur_ctrl_putbytes.u2RetSize > 0)
                                    {
                                        ttyut_inst_p->conv_tx_rx_wt_idx += ur_ctrl_putbytes.u2RetSize;
                                    }
                                }
                            }
                        }
                    } else if (test_mode == TTY_UT_CONV_TX_ONLY || test_mode == TTY_UT_CONV_TX_NEW_RX) {
                        if (ttyut_inst_p->ttyut_tx_len > 0)
                        {                       
                            ur_ctrl_putbytes.u4OwenrId = ttyut_inst_p->owner;
                            ur_ctrl_putbytes.puBuffaddr = ttyut_inst_p->ttyut_tx_buf + ttyut_inst_p->ttyut_tx_offset;
                            ur_ctrl_putbytes.u2Length = ttyut_inst_p->ttyut_tx_len;
                            if (STATUS_OK == DclSerialPort_Control(handle, SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*) &ur_ctrl_putbytes))
                            {                           
                                ttyut_print("[TTY UT] send %d bytes data\r\n", ur_ctrl_putbytes.u2RetSize);
                                ttyut_inst_p->ttyut_tx_len -= ur_ctrl_putbytes.u2RetSize;
                                ttyut_inst_p->ttyut_tx_offset += ur_ctrl_putbytes.u2RetSize;
                            }
                        }
                    }
                }
                break;
            case MSG_ID_UART_READY_TO_READ_IND:
                {
                    UART_CTRL_GET_BYTES_T ur_ctrl_getbytes; 
                    int idx;

                    switch (test_mode)
                    {
                        case TTY_UT_CONV_TX_CONV_RX:
                        case TTY_UT_NEW_INIT_CONV_TX_CONV_RX:
                            {
                                _tty_ut_conv_tx_conv_rx_rd_handler(handle);
                            }
                            break;
                        case TTY_UT_NEW_TX_CONV_RX:
                            {
                                ur_ctrl_getbytes.u4OwenrId = ttyut_inst_p->owner;
                                ur_ctrl_getbytes.puBuffaddr = ttyut_inst_p->ttyut_rx_buf;
                                ur_ctrl_getbytes.u2Length = QBM_TTY_XXX_DATA_LEN;

                                if (STATUS_OK == DclSerialPort_Control(handle, SIO_CMD_GET_BYTES, (DCL_CTRL_DATA_T*) &ur_ctrl_getbytes)
                                        && ur_ctrl_getbytes.u2RetSize > 0)
                                {
                                    void *tx_gpd;
                                    tty_io_request_t *tx_ior;
                                    unsigned char *tx_buf_ptr;

                                    tx_gpd = QBM_ALLOC_ONE(QBM_TYPE_TTY_TYPE1);
                                    if (tx_gpd) {
                                        tx_ior = (tty_io_request_t*)QBM_DES_GET_SW_CTRL_FIELD(tx_gpd);
                                        tx_ior->next_request = NULL;
                                        tx_ior->first_gpd = tx_gpd;
                                        tx_ior->last_gpd = tx_gpd;
                                        
                                        tx_buf_ptr = QBM_DES_GET_DATAPTR(tx_gpd);
                                        kal_mem_cpy((void*)tx_buf_ptr, ur_ctrl_getbytes.puBuffaddr, ur_ctrl_getbytes.u2RetSize);
                                        QBM_DES_SET_DATALEN(tx_gpd, ur_ctrl_getbytes.u2RetSize); // Set data length
                                        QBM_DES_SET_HWO(tx_gpd);
                                        qbm_cal_set_checksum(tx_gpd);
                                        //QBM_CACHE_FLUSH(tx_gpd, sizeof(qbm_gpd));

                                        ttyut_print("[TTY UT] Receive data and re-send to Host, len=%d\r\n", ur_ctrl_getbytes.u2RetSize);
                                        DclSerialPort_UpModuleTransmit(handle, tx_ior);
                                    } else {
                                        ttyut_print("[ERROR] [TTY UT] GPD allocate failed in QBM_TYPE_TTY_TYPE1 type\r\n");
                                        ASSERT(tx_gpd);
                                    }
                                }
                            }
                            break;
                        case TTY_UT_CONV_RX_ONLY:
                            {
                                ur_ctrl_getbytes.u4OwenrId = ttyut_inst_p->owner;
                                ur_ctrl_getbytes.puBuffaddr = ttyut_inst_p->ttyut_rx_buf;
                                ur_ctrl_getbytes.u2Length = TTY_UT_CONV_BUF_SIZE;
                                
                                if (STATUS_OK == DclSerialPort_Control(handle, SIO_CMD_GET_BYTES, (DCL_CTRL_DATA_T*) &ur_ctrl_getbytes)
                                        && ur_ctrl_getbytes.u2RetSize > 0)
                                {                               
                                    ttyut_print("[TTY UT] Rx Only Test, len=%d, data: ", ur_ctrl_getbytes.u2RetSize);
                                    for (idx = 0; idx < ur_ctrl_getbytes.u2RetSize; idx ++) {
                                        ttyut_print("%c", ur_ctrl_getbytes.puBuffaddr[idx]);
                                    }
                                    ttyut_print("\r\n");
                                }                               
                            }
                            break;
                        default:
                            break;
                    }
                }
                break;
            default:
                break;
        }
    }
}

static void ttyut_test(tty_ut_mode_e test_mode, kal_uint8 uart_port)
{
    ilm_struct current_ilm = {0};
    DCL_HANDLE handle;
    ttyut_instance_t *ttyut_inst_p;
    UART_CTRL_GET_DRV_STATE_T getDrvState;
    DCL_UINT32 owner = MOD_NIL;
    DCL_STATUS status;

    handle = DclSerialPort_Open(uart_port, 0);
    ttyut_inst_p = ttyut_get_instance(handle);
    ASSERT(ttyut_inst_p);

    // Wait for device ready
    if (TTY_UT_COM1 == uart_port) {
        owner = MOD_TTY_UT;
    } else if (TTY_UT_COM2 == uart_port) {
        owner = MOD_TTY_UT2;
    } else if (TTY_UT_COM3 == uart_port) {
        owner = MOD_TTY_UT3;
    } else {
        // Unsupported mode, ASSERT.
        ASSERT(0);
    }
    getDrvState.u4OwnerId = owner;
    do {
        kal_sleep_task(100);
        status = DclSerialPort_Control(handle, TTY_CMD_GET_DRV_STATE, (DCL_CTRL_DATA_T*) &getDrvState);
    } while ((getDrvState.drv_state != DRV_ST_ATTACHED) || (status != STATUS_OK));


    switch (test_mode)
    {
        case TTY_UT_BYPASS:
            {
                while(1)
                {
                    //do nothing;
                    kal_sleep_task(1000);
                }
            }
        case TTY_UT_CONV_TX_CONV_RX:
            ttyut_print("[TTY UT] loopback Test of conventional Tx and conventional Rx - in Old init procedure\r\n");
            {
                while (1)
                {
                    while (msg_get_extq_messages() > 0)
                    {
                        if (msg_receive_extq(&current_ilm) == KAL_TRUE)
                        {
                            _ttyut_process_ilm(handle, &current_ilm, test_mode);
                            destroy_ilm(&current_ilm);
                        }
                    }

                    /* Polling Read */
                    kal_sleep_task(1);
                    _tty_ut_conv_tx_conv_rx_rd_handler(handle);
                }
            }
            break;

        case TTY_UT_NEW_INIT_CONV_TX_CONV_RX:
            ttyut_print("[TTY UT] loopback Test of conventional Tx and conventional Rx - in New init procedure\r\n");
            {
                while (1)
                {
                    while (msg_get_extq_messages() > 0)
                    {
                        if (msg_receive_extq(&current_ilm) == KAL_TRUE)
                        {
                            _ttyut_process_ilm(handle, &current_ilm, test_mode);
                            destroy_ilm(&current_ilm);
                        }
                    }

                    /* Polling Read */
                    kal_sleep_task(1);
                    _tty_ut_conv_tx_conv_rx_rd_handler(handle);
                }
            }
            break;

        case TTY_UT_NEW_TX_CONV_RX:
            ttyut_print("[TTY UT] loopback Test of new Tx and conventional Rx\r\n");
            {
                while (1)
                {
                    if (msg_receive_extq(&current_ilm) == KAL_TRUE)
                    {
                        _ttyut_process_ilm(handle, &current_ilm, test_mode);
                        destroy_ilm(&current_ilm);
                    }
                }
            }
            break;

        case TTY_UT_CONV_RX_ONLY:
            ttyut_print("[TTY UT] conventional Rx Only Test\r\n");
            {
                while (1)
                {
                    if (msg_receive_extq(&current_ilm) == KAL_TRUE)
                    {
                        _ttyut_process_ilm(handle, &current_ilm, test_mode);
                        destroy_ilm(&current_ilm);
                    }
                }
            }
            break;

        case TTY_UT_NEW_RX_ONLY:
            ttyut_print("[TTY UT] new Rx Only Test\r\n");
            {
                while (1)
                {
                    tty_io_request_t *rx_ior;
                    unsigned char *rx_buf_ptr;
                    int rx_buf_len;
                    int idx;

                    kal_take_mutex(ttyut_inst_p->ttyut_mutex);
                    
                    if (ttyut_inst_p->ttyut_rx_ior) {
                        rx_ior = ttyut_inst_p->ttyut_rx_ior;
                        ttyut_inst_p->ttyut_rx_ior = ttyut_inst_p->ttyut_rx_ior->next_request;
                        kal_give_mutex(ttyut_inst_p->ttyut_mutex);
                        rx_ior->next_request = NULL;

                        /* Assert if first gpd is not equal to last gpd, unless Clear Rx/Set owner/Close command is requested */
                        ASSERT(rx_ior->first_gpd == rx_ior->last_gpd);
                        
                        rx_buf_ptr = QBM_DES_GET_DATAPTR(rx_ior->first_gpd);
                        rx_buf_len = QBM_DES_GET_DATALEN(rx_ior->first_gpd);
                        QBM_CACHE_INVALID(rx_buf_ptr, rx_buf_len);
                        
                        ttyut_print("[TTY UT] Rx Only Test, len=%d, data: ", rx_buf_len);
                        for (idx = 0; idx < rx_buf_len; idx ++) {
                            ttyut_print("%c", rx_buf_ptr[idx]);
                        }
                        ttyut_print("\r\n");
                        
                        QBM_DES_SET_HWO(rx_ior->first_gpd);
                        qbm_cal_set_checksum(rx_ior->first_gpd);
                        QBM_CACHE_FLUSH(rx_ior->first_gpd, sizeof(qbm_gpd));    
                        
                        /* Re-assign this rx ior to driver for the following receiving */
                        DclSerialPort_UpModuleAssignRxIor(handle, rx_ior);
                    } else {
                        kal_give_mutex(ttyut_inst_p->ttyut_mutex);
                    }
                    
                    /* TODO: check scheduling/priority issue */
                    kal_sleep_task(10);
                    
                    /* msg_receive_extq will block, therefore we poll if any message first */
                    while (msg_get_extq_messages() > 0)
                    {
                        if (msg_receive_extq(&current_ilm) != KAL_TRUE)
                        {
                            break;
                        }
                        destroy_ilm(&current_ilm);
                    }
                }
            }
            break;
        case TTY_UT_CONV_TX_ONLY:
            kal_sleep_task(3000);
            ttyut_print("[TTY UT] conventional Tx Only Test\r\n");
            {
                int idx, len;
                DCL_STATUS ret_st;
                
                for (idx = 0; idx < TTY_UT_CONV_BUF_SIZE; idx ++) {
                    ttyut_inst_p->ttyut_tx_buf[idx] = 'a' + idx % ('z'-'a'+1);
                }
                /* 1st round - 1~2048 bytes in order */
                for (len = 1; len <= 2048; len ++) {
                    UART_CTRL_PUT_BYTES_T ur_ctrl_putbytes;

                    ttyut_print("[TTY UT] expect send %d bytes data\r\n", len);

                    ttyut_inst_p->ttyut_tx_offset = 0;
                    ttyut_inst_p->ttyut_tx_len = len;
                    ur_ctrl_putbytes.u4OwenrId = ttyut_inst_p->owner;
                    ur_ctrl_putbytes.puBuffaddr = ttyut_inst_p->ttyut_tx_buf;
                    ur_ctrl_putbytes.u2Length = len;
                    ret_st = DclSerialPort_Control(handle, SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*) &ur_ctrl_putbytes);

                    if (STATUS_OK == ret_st && ur_ctrl_putbytes.u2RetSize > 0) {

                        ttyut_print("[TTY UT] send %d bytes data\r\n", ur_ctrl_putbytes.u2RetSize);
                        
                        ttyut_inst_p->ttyut_tx_offset = ur_ctrl_putbytes.u2RetSize;
                        ttyut_inst_p->ttyut_tx_len -= ur_ctrl_putbytes.u2RetSize;
                    }

                    kal_sleep_task(10);

                    /* Polling ttyut_tx_len until all tx buffer are sent */
                    while (ttyut_inst_p->ttyut_tx_len != 0)
                    {
                        kal_sleep_task(1);
                        
                        while (msg_get_extq_messages() > 0)
                        {
                            if (msg_receive_extq(&current_ilm) != KAL_TRUE) {
                                break;
                            } else {
                                _ttyut_process_ilm(handle, &current_ilm, test_mode);
                            }
                            destroy_ilm(&current_ilm);
                        }
                    }

                }

                /* 2nd round - 1~2048 bytes in random size */
                while (1)
                {
                    UART_CTRL_PUT_BYTES_T ur_ctrl_putbytes;
                    
                    len = rand()%TTY_UT_CONV_BUF_SIZE + 1;
                    ur_ctrl_putbytes.u4OwenrId = ttyut_inst_p->owner;
                    ur_ctrl_putbytes.puBuffaddr = ttyut_inst_p->ttyut_tx_buf;
                    ur_ctrl_putbytes.u2Length = len;                    
                    ttyut_inst_p->ttyut_tx_offset = 0;
                    ttyut_inst_p->ttyut_tx_len = len;
                    ret_st = DclSerialPort_Control(handle, SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*) &ur_ctrl_putbytes);

                    if (STATUS_OK == ret_st && ur_ctrl_putbytes.u2RetSize > 0)
                    {
                        ttyut_print("[TTY UT] send %d bytes data\r\n", ur_ctrl_putbytes.u2RetSize);
                        
                        ttyut_inst_p->ttyut_tx_offset = ur_ctrl_putbytes.u2RetSize;
                        ttyut_inst_p->ttyut_tx_len -= ur_ctrl_putbytes.u2RetSize;
                    }

                    /* Polling ttyut_tx_len until all tx buffer are sent */
                    while (ttyut_inst_p->ttyut_tx_len != 0)
                    {
                        kal_sleep_task(10);
                        
                        while (msg_get_extq_messages() > 0)
                        {
                            if (msg_receive_extq(&current_ilm) != KAL_TRUE) {
                                break;
                            } else {
                                _ttyut_process_ilm(handle, &current_ilm, test_mode);
                            }
                            destroy_ilm(&current_ilm);
                        }
                    }
                } /* while */
            }

            break;
        case TTY_UT_NEW_TX_ONLY:
            kal_sleep_task(3000);
            ttyut_print("[TTY UT] new Tx Only Test\r\n");
            {
                int idx;
                for (idx = 0; idx < TTY_UT_NEW_BUF_SIZE; idx ++) {
                    ttyut_inst_p->ttyut_tx_buf[idx] = 'a' + idx % ('z'-'a'+1);
                }
                while (1)
                {
                    void *tx_gpd;
                    tty_io_request_t *tx_ior;
                    unsigned char *tx_buf_ptr;

                    tx_gpd = QBM_ALLOC_ONE(QBM_TYPE_TTY_TYPE1);
                    if (tx_gpd) {
                        tx_ior = (tty_io_request_t*)QBM_DES_GET_SW_CTRL_FIELD(tx_gpd);
                        tx_ior->next_request = NULL;
                        tx_ior->first_gpd = tx_gpd;
                        tx_ior->last_gpd = tx_gpd;
                        ttyut_inst_p->ttyut_tx_len = rand()%TTY_UT_NEW_BUF_SIZE + 1;
                        
                        tx_buf_ptr = QBM_DES_GET_DATAPTR(tx_gpd);
                        kal_mem_cpy((void*)tx_buf_ptr, ttyut_inst_p->ttyut_tx_buf, ttyut_inst_p->ttyut_tx_len);
                        QBM_DES_SET_DATALEN(tx_gpd, ttyut_inst_p->ttyut_tx_len); // Set data length
                        QBM_DES_SET_HWO(tx_gpd);
                        qbm_cal_set_checksum(tx_gpd);
                        //QBM_CACHE_FLUSH(tx_gpd, sizeof(qbm_gpd));

                        ttyut_print("[TTY UT] send %d bytes data\r\n", ttyut_inst_p->ttyut_tx_len);
                        DclSerialPort_UpModuleTransmit(handle, tx_ior);
                    } else {
                        ttyut_print("[ERROR] [TTY UT] GPD allocate failed in QBM_TYPE_TTY_TYPE1 type\r\n");
                    }
                    
                    /* TODO: check scheduling/priority issue */
                    kal_sleep_task(10);
                    
                    /* msg_receive_extq will block, therefore we poll if any message first */
                    while (msg_get_extq_messages() > 0)
                    {
                        if (msg_receive_extq(&current_ilm) != KAL_TRUE)
                        {
                            break;
                        }
                        destroy_ilm(&current_ilm);
                    }
                }
            }
            break;
        case TTY_UT_NEW_TX_NEW_RX:
            ttyut_print("[TTY UT] loopback Test of new Tx and new Rx\r\n");
            {
                while (1)
                {
                    void *tx_gpd;
                    tty_io_request_t *tx_ior;
                    tty_io_request_t *rx_ior;
                    unsigned char *tx_buf_ptr;
                    unsigned char *rx_buf_ptr;
                    kal_uint16 rx_len;

                    kal_take_mutex(ttyut_inst_p->ttyut_mutex);
                    
                    if (ttyut_inst_p->ttyut_rx_ior)
                    {
                        rx_ior = ttyut_inst_p->ttyut_rx_ior;
                        ttyut_inst_p->ttyut_rx_ior = ttyut_inst_p->ttyut_rx_ior->next_request;
                        kal_give_mutex(ttyut_inst_p->ttyut_mutex);
                        rx_ior->next_request = NULL;

                        /* Assert if first gpd is not equal to last gpd, unless Clear Rx/Set owner/Close command is requested */
                        ASSERT(rx_ior->first_gpd == rx_ior->last_gpd);
                        
                        tx_gpd = QBM_ALLOC_ONE(QBM_TYPE_TTY_TYPE1);
                        if (tx_gpd) {
                            tx_ior = (tty_io_request_t*)QBM_DES_GET_SW_CTRL_FIELD(tx_gpd);
                            tx_ior->next_request = NULL;
                            tx_ior->first_gpd = tx_gpd;
                            tx_ior->last_gpd = tx_gpd;
                            
                            tx_buf_ptr = QBM_DES_GET_DATAPTR(tx_gpd);
                            rx_buf_ptr = QBM_DES_GET_DATAPTR(rx_ior->first_gpd);
                            rx_len = QBM_DES_GET_DATALEN(rx_ior->first_gpd);

                            QBM_CACHE_INVALID(rx_buf_ptr, rx_len);
                            kal_mem_cpy((void*)tx_buf_ptr, (void*)rx_buf_ptr, rx_len);
                            QBM_CACHE_FLUSH(tx_buf_ptr, rx_len); // flush tx data
                            
                            QBM_DES_SET_DATALEN(tx_gpd, rx_len); // Set data length
                            QBM_DES_SET_HWO(tx_gpd);
                            qbm_cal_set_checksum(tx_gpd);
                            QBM_CACHE_FLUSH(tx_gpd, sizeof(qbm_gpd));

                            ttyut_print("[TTY UT] Receive data and re-send to Host, len=%d\r\n", rx_len);
                            DclSerialPort_UpModuleTransmitLight(handle, tx_ior);
                        } else {
                            ttyut_print("[ERROR] [TTY UT] GPD allocate failed in QBM_TYPE_TTY_TYPE1 type\r\n");
                        }
                        
                        QBM_DES_SET_HWO(rx_ior->first_gpd);
                        qbm_cal_set_checksum(rx_ior->first_gpd);
                        QBM_CACHE_FLUSH(rx_ior->first_gpd, sizeof(qbm_gpd));    

                        /* Re-assign this rx ior to driver for the following receiving */
                        DclSerialPort_UpModuleAssignRxIor(handle, rx_ior);
                    } else {
                        kal_give_mutex(ttyut_inst_p->ttyut_mutex);
                    }
                    
                    /* TODO: check scheduling/priority issue */
                    kal_sleep_task(10);
                    
                    /* msg_receive_extq will block, therefore we poll if any message first */
                    while (msg_get_extq_messages() > 0)
                    {
                        if (msg_receive_extq(&current_ilm) != KAL_TRUE)
                        {
                            break;
                        }
                        destroy_ilm(&current_ilm);
                    }
                }
            }
            break;
        case TTY_UT_CONV_TX_NEW_RX:
            ttyut_print("[TTY UT] loopback Test of conventional Tx and new Rx\r\n");
            {
                while (1)
                {
                    UART_CTRL_PUT_BYTES_T ur_ctrl_putbytes;
                    tty_io_request_t *rx_ior;
                    void *rx_data;
                    kal_uint16 rx_len;

                    kal_take_mutex(ttyut_inst_p->ttyut_mutex);
                    
                    if (ttyut_inst_p->ttyut_rx_ior)
                    {
                        rx_ior = ttyut_inst_p->ttyut_rx_ior;
                        ttyut_inst_p->ttyut_rx_ior = ttyut_inst_p->ttyut_rx_ior->next_request;
                        kal_give_mutex(ttyut_inst_p->ttyut_mutex);
                        rx_ior->next_request = NULL;

                        /* Assert if first gpd is not equal to last gpd, unless Clear Rx/Set owner/Close command is requested */
                        ASSERT(rx_ior->first_gpd == rx_ior->last_gpd);

                        rx_data = QBM_DES_GET_DATAPTR(rx_ior->first_gpd);
                        rx_len = QBM_DES_GET_DATALEN(rx_ior->first_gpd);

                        if (rx_len > 0)
                        {   /* in the test case, only one gpd is used in one ior since we only send 2 gpds to driver and one is for tailing */
                            QBM_CACHE_INVALID(rx_data, rx_len);
                            ASSERT(rx_len <= QBM_TTY_XXX_DATA_LEN);
                            kal_mem_cpy(ttyut_inst_p->ttyut_tx_buf, rx_data, rx_len);
                            ttyut_inst_p->ttyut_tx_len = rx_len;
                            
                            ur_ctrl_putbytes.u4OwenrId = ttyut_inst_p->owner;
                            ur_ctrl_putbytes.puBuffaddr = ttyut_inst_p->ttyut_tx_buf;
                            ur_ctrl_putbytes.u2Length = ttyut_inst_p->ttyut_tx_len;

                            if (STATUS_OK == DclSerialPort_Control(handle, SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*) &ur_ctrl_putbytes)
                                && ur_ctrl_putbytes.u2RetSize < ttyut_inst_p->ttyut_tx_len)
                            {
                                ttyut_inst_p->ttyut_tx_offset = ur_ctrl_putbytes.u2RetSize;
                                ttyut_inst_p->ttyut_tx_len -= ur_ctrl_putbytes.u2RetSize;
                            }
                        }

                        QBM_DES_SET_HWO(rx_ior->first_gpd);
                        qbm_cal_set_checksum(rx_ior->first_gpd);
                        QBM_CACHE_FLUSH(rx_ior->first_gpd, sizeof(qbm_gpd));    

                        /* Re-assign this rx ior to driver for the following receiving */
                        DclSerialPort_UpModuleAssignRxIor(handle, rx_ior);
                    } else {
                        kal_give_mutex(ttyut_inst_p->ttyut_mutex);
                    }
                    
                    /* TODO: check scheduling/priority issue */
                    kal_sleep_task(10);
                    
                    /* msg_receive_extq will block, therefore we poll if any message first */
                    while (msg_get_extq_messages() > 0)
                    {
                        if (msg_receive_extq(&current_ilm) != KAL_TRUE) {
                            break;
                        } else {
                            _ttyut_process_ilm(handle, &current_ilm, test_mode);
                        }
                        destroy_ilm(&current_ilm);
                    }
                }
            }
            break;
        default:
            break;
    }
}


// ==========================================================
// TTY_UT Task Function
// ==========================================================
kal_bool ttyut_task_init(void)
{
    // Init ttyut instance struct.
    kal_mem_set(&ttyut_inst_g, 0, sizeof(ttyut_inst_g));

    return KAL_TRUE;
}

static void ttyut_task_main(task_entry_struct *task_entry_ptr)
{
    kal_uint32 tsk_pri;
    kal_bool ret = KAL_TRUE;

    DCL_HANDLE handle;
    UART_CTRL_GET_DRV_STATE_T getDrvState;
    DCL_STATUS status;

    tsk_pri = kal_get_current_task_priority();

#if TTY_UT_MISC_TEST
    /*Init test and change owner test*/
    if (TASK_PRIORITY_TTY_UT == tsk_pri) {
        // Init_deinit test
        kal_set_active_module_id(MOD_TTY_UT);

        /*Make sure driver is already attached*/
        handle = DclSerialPort_Open(TTY_UT_COM1, 0);
        getDrvState.u4OwnerId = MOD_TTY_UT;
        do {
            kal_sleep_task(100);
            status = DclSerialPort_Control(handle, TTY_CMD_GET_DRV_STATE, (DCL_CTRL_DATA_T*) &getDrvState);
        } while ((getDrvState.drv_state != DRV_ST_ATTACHED) || (status != STATUS_OK)); 

        if (_ttyut_upmod_init_deinit_test(TTY_UT_COM1)) {
            ttyut_print("[TTY UT] init-deinit test OK\r\n");
        } else {
            ttyut_print("[TTY UT] init-deinit test failed\r\n");
            //return;
            ASSERT(0);
        }

        // Change_owner test
        if (_ttyut_upmod_change_owner_test()) {
            ttyut_print("[TTY UT] change owner test OK\r\n");
        } else {
            ttyut_print("[TTY UT] change owner test failed\r\n");
            //return;
            ASSERT(0);
        }
    }
#endif

    /*
     * S1.TTYUT_PREPROC.
     */
    switch (tsk_pri)
    {
        case TASK_PRIORITY_TTY_UT:
            kal_set_active_module_id(MOD_TTY_UT);
            ret = ttyut_test_preproc(tty_ut_mode_1, TTY_UT_COM1);
            break;

        case TASK_PRIORITY_TTY_UT2:
            if (TTY_UT_COM_NUM > 1) {
                kal_set_active_module_id(MOD_TTY_UT2);
                ret = ttyut_test_preproc(tty_ut_mode_2, TTY_UT_COM2);
            }
            break;

        case TASK_PRIORITY_TTY_UT3:
            if (TTY_UT_COM_NUM > 2) {
                kal_set_active_module_id(MOD_TTY_UT3);
                ret = ttyut_test_preproc(tty_ut_mode_3, TTY_UT_COM3);
            }
            break;

        default:
            // Unsupported mode, ASSERT.
            ASSERT(0);
            break;
    }

    if (KAL_TRUE == ret) {

    } else {
        // Failed to ttyut_test_preproc(), ASSERT.
        ASSERT(0);
    }

    /*
     * S2. TTYUT_MAIN.
     */
    switch (tsk_pri)
    {
        case TASK_PRIORITY_TTY_UT:

            ttyut_test(tty_ut_mode_1, TTY_UT_COM1);
            break;

        case TASK_PRIORITY_TTY_UT2:
            if (TTY_UT_COM_NUM > 1) {
                ttyut_test(tty_ut_mode_2, TTY_UT_COM2);
            }
            break;

        case TASK_PRIORITY_TTY_UT3:
            if (TTY_UT_COM_NUM > 2) {
                ttyut_test(tty_ut_mode_3, TTY_UT_COM3);
            }
            break;

        default:
            // Unsupport mode, ASSERT.
            ASSERT(0);
            break;
    }

    while (1) {
        kal_sleep_task(KAL_TICKS_30_SEC);
    }
}

kal_bool ttyut_create(comptask_handler_struct **handle)
{
    static const comptask_handler_struct ttyut_handler_info =
    {
        ttyut_task_main,        /* task entry function */
        ttyut_task_init,        /* task initialization function */
        NULL                    /* task reset handler */
    };

    ttyut_print("=========>ttyut_create\r\n");

    *handle = (comptask_handler_struct *)&ttyut_handler_info;
    return KAL_TRUE;
}

