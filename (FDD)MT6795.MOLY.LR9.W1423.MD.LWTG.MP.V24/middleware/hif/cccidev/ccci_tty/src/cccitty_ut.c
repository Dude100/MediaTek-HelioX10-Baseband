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
 *   cccitty_ut.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Implements the CCCI TTY UT functions
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
 * 	.
 *
 * removed!
 * removed!
 * Rename project name as MT6290
 *
 * removed!
 * removed!
 * [CCCITTY]  1. fix warnings 2.enable sdiocore sim when CCCITTY UT
 *
 * removed!
 * removed!
 * sync latest version of new features
 *
 * removed!
 * removed!
 * [MOLY][CCCI_SDIO] 1st version of MT6290 CCCI feature
 ****************************************************************************/
#if defined(ATEST_SYS_CCCI_TTY)

#include "cccitty_common.h"
#include "cccitty_qbm.h"
#include "cccitty_sm.h"
#include "cccitty_data.h"
#include "cccitty_if.h"
#include "qmu_bm_util.h"
#include "dcl_uart.h"
#if defined(ATEST_SYS_CCCI_TTY)
#include "sys_test.h"
#endif

//#if defined(__MTK_TARGET__)
//#define cccittyut_print    dbg_print
//#else
#include "dhl_trace.h"
#define cccittyut_print(...) dhl_print(TRACE_INFO, DHL_USER_FLAG_NONE, MOD_CCCITTY, ##__VA_ARGS__)
//#endif

#define MIN(_a, _b) (((_a) <= (_b)) ? (_a) : (_b))
#define BUSY_WAIT(_loopCnt) do{unsigned int i,j;for(i=0;i<_loopCnt;i++){j=i;j++;}}while(0)

#define CCCITTY_UT_INVALID_PORT uart_max_port
#define CCCITTY_DHL_PORT        uart_port_dhl_ccci
#define CCCITTY_META_PORT       uart_port_tst_ccci
#define CCCITTY_AT_PORT         uart_port_at_ccci
#define CCCITTY_IMS_PORT        uart_port_imsctrl_ccci
#define CCCITTY_GPS_PORT        uart_port_gps_ccci

#define TTY_UT_COM1             CCCITTY_AT_PORT
#define TTY_UT_COM2             CCCITTY_META_PORT
#define TTY_UT_COM3             CCCITTY_DHL_PORT

/*simply assign a int to them*/
#define MOD_TTY_UT              2048
#define MOD_TTY_UT1             2148
#define MOD_TTY_UT2             2248
#define MOD_TTY_UT3             2348
#define MOD_TTY_UT99            4096

typedef enum _tty_ut_mode {
	TTY_UT_CONV_TX_ONLY = 0,
	TTY_UT_NEW_TX_ONLY,
	TTY_UT_CONV_RX_ONLY,
	TTY_UT_CONV_TX_CONV_RX,
	TTY_UT_NEW_TX_CONV_RX,
	TTY_UT_NEW_INIT_CONV_TX_CONV_RX
} tty_ut_mode_e;

//static tty_ut_mode_e tty_ut_mode_1 = TTY_UT_CONV_TX_CONV_RX;
//static tty_ut_mode_e tty_ut_mode_2 = TTY_UT_NEW_TX_CONV_RX;
//static tty_ut_mode_e tty_ut_mode_3 = TTY_UT_NEW_INIT_CONV_TX_CONV_RX;

// for conventional path
#define TTY_UT_NEW_BUF_SIZE		QBM_CCCI_COMM_DATA_LEN
#define TTY_UT_CONV_BUF_SIZE	QBM_CCCI_COMM_DATA_LEN*2

#define TTY_UT_LB_CON_TX_TX_BUF_SIZE	QBM_CCCI_COMM_DATA_LEN*10


typedef struct _ttyut_instance_t {
    DCL_HANDLE              handle;
    DCL_UINT32              owner;
//    tty_io_request_t        *ttyut_rx_ior;

	kal_uint8 ttyut_rx_buf[TTY_UT_CONV_BUF_SIZE];
	kal_uint8 ttyut_tx_buf[TTY_UT_CONV_BUF_SIZE];
	kal_uint32 ttyut_tx_offset;
	kal_uint32 ttyut_tx_len;

	kal_uint8 conv_tx_rx_buf[TTY_UT_LB_CON_TX_TX_BUF_SIZE];
	kal_uint32 conv_tx_rx_rd_idx;
	kal_uint32 conv_tx_rx_wt_idx;
	kal_uint32 conv_tx_rx_wrap;
} ttyut_instance_t;
static ttyut_instance_t ttyut_inst_g[CCCI_TTY_DEV_CNT];

// ==========================================================
// Private Function
// ==========================================================
static kal_bool ttyut_task_init()
{
    // Init ttyut instance struct.
    kal_mem_set(&ttyut_inst_g, 0, sizeof(ttyut_inst_g));

    return KAL_TRUE;
}
kal_bool cccittyut_init(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
    ttyut_task_init();
    return KAL_TRUE;
}
static kal_bool ttyut_create_instance(DCL_HANDLE handle, DCL_UINT32 owner)
{
    kal_uint8 i;
    
    for (i=0; i<CCCI_TTY_DEV_CNT; i++) {
        if (ttyut_inst_g[i].handle == (DCL_HANDLE) 0x0) {

            ttyut_inst_g[i].handle = handle;
            ttyut_inst_g[i].owner = owner;
//            ttyut_inst_g[i].ttyut_rx_ior = NULL;
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

    for (i=0; i<CCCI_TTY_DEV_CNT; i++) {
        if (ttyut_inst_g[i].handle == handle) {
            return &ttyut_inst_g[i];
        }
    } 

    return NULL;
}

static void ttyut_del_instance(ttyut_instance_t *pttyut_inst)
{
    if(NULL!= pttyut_inst){
        kal_mem_set(pttyut_inst, 0, sizeof(ttyut_instance_t));
    }
}



DCL_STATUS _cccittyut_drv_state_cb(DCL_HANDLE handle, tty_drv_state_e state)
{
	cccittyut_print("=========>_cccittyut_drv_state_cb: state - %s\r\n", (state==DRV_ST_ATTACHED)?"attached":"detached");
	return STATUS_OK;
}

DCL_STATUS _cccittyut_tx_done_cb(DCL_HANDLE handle, module_type source_id, tty_io_request_t *tx_ior)
{
	if (tx_ior) {
		/* free all GPDs of all IOR */
		do {
			qbmt_dest_q(tx_ior->first_gpd, tx_ior->last_gpd);
		} while ((tx_ior = tx_ior->next_request) != NULL);
	} else {
		cccittyut_print("[TTY UT] [ERROR] =========>_cccittyut_tx_done_cb : tx_ior is NULL!!!!!\r\n");
	}

	cccittyut_print("=========>_cccittyut_tx_done_cb\r\n");
	return STATUS_OK;
}

static kal_bool cccitty_ut_init_deinit(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
	#define             TEST_ROUND	100
	DCL_STATUS          status;
	DCL_HANDLE          handle;
	int                 idx;
    kal_char            error_string[256];
    
	/* Init non-existed port -> should init failed */
	handle = DclSerialPort_Open(CCCITTY_UT_INVALID_PORT, 0);
	status = DclSerialPort_UpModuleInit(handle, MOD_TTY_UT, TTY_FLAG_NEW_TX); //Note that CCCI_TTY doesn't support NEW Rx
	if (status == STATUS_OK) {
        sprintf(error_string, "%s \n",
        "[CCCI_TTY_UT] DCL upper module init non-existed port successfully");
        strncpy(p_ret_err_str, error_string, MIN(strlen(error_string), *p_ret_err_str_sz));
        goto cccitty_ut_init_deinit_err;
	}

	handle = DclSerialPort_Open(CCCITTY_AT_PORT, 0);

	for (idx = 0; idx < TEST_ROUND; idx ++)
	{
		/* First init -> should init successfully */
		status = DclSerialPort_UpModuleInit(handle, MOD_TTY_UT, TTY_FLAG_NEW_TX); //Note that CCCI_TTY doesn't support NEW Rx
		if (status != STATUS_OK) {
            sprintf(error_string, "%s \n",
            "[CCCI_TTY_UT ERROR] DCL upper module init failed");
            strncpy(p_ret_err_str, error_string, MIN(strlen(error_string), *p_ret_err_str_sz));
            goto cccitty_ut_init_deinit_err;
		}

		DclSerialPort_UpModuleRegisterCb(handle, NULL, NULL, _cccittyut_drv_state_cb);

		/* Duplicated init -> should init failed */
		status = DclSerialPort_UpModuleInit(handle, MOD_TTY_UT, TTY_FLAG_NEW_TX);
		if (status == STATUS_OK) {
            sprintf(error_string, "%s \n",
            "[CCCI_TTY_UT ERROR] DCL upper module init twice successfully");
            strncpy(p_ret_err_str, error_string, MIN(strlen(error_string), *p_ret_err_str_sz));
            goto cccitty_ut_init_deinit_err;
		}

		/* First deinit -> should deinit successfully */
		status = DclSerialPort_UpModuleDeinit(handle);
		if (status != STATUS_OK) {
            sprintf(error_string, "%s \n",
            "[CCCI_TTY_UT ERROR] DCL upper module deinit failed");
            strncpy(p_ret_err_str, error_string, MIN(strlen(error_string), *p_ret_err_str_sz));
            goto cccitty_ut_init_deinit_err;
		}

		/* Duplicated deinit -> should deinit failed */
		status = DclSerialPort_UpModuleDeinit(handle);
		if (status == STATUS_OK) {
            sprintf(error_string, "%s \n",
            "[CCCI_TTY_UT ERROR] DCL upper module deinit-twice failed");
            strncpy(p_ret_err_str, error_string, MIN(strlen(error_string), *p_ret_err_str_sz));
            goto cccitty_ut_init_deinit_err;
		}
	}

    cccittyut_print("[CCCI_TTY_UT] ======== cccitty_ut_init_deinit PASS!! ========\r\n");
	return KAL_TRUE;

cccitty_ut_init_deinit_err:
    cccittyut_print("%s \r\n", error_string);
    return KAL_FALSE;    
}


kal_bool _cccitty_ut_conv_tx_fg;
DCL_STATUS
_ccciut_drvtxdone(
    DCL_HANDLE          handle,
    module_type         source_id,
    void                *tx_ior)
{

    _cccitty_ut_conv_tx_fg = KAL_TRUE;
    DclSerialPort_DrvTxDone(handle, source_id, tx_ior);
	return STATUS_OK;
}
static kal_bool cccitty_ut_upmod_change_owner_test(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
    #define             UR_CONF_U4BAUD          38400
    #define             UR_CONF_U1DATABITS      7
    #define             UR_CONF_U1STOPBITS      2
    #define             UR_CONF_U1PARITY        3
    #define             UR_CONF_U1FLOWCONTROL   2
    #define             UR_CONF_UCXONCHAR       0x91
    #define             UR_CONF_UCXOFFCHAR      0x92
    #define             UR_CONF_FGDSRCHECK      KAL_FALSE
    #define             WAIT_LIMIT  100
	DCL_STATUS          status;
	DCL_HANDLE          handle;	
	UART_CTRL_OPEN_T    ur_ctrl_open;
	UART_CTRL_CLOSE_T   ur_ctrl_close;
	UART_CTRL_OWNER_T   ur_ctrl_owner;
	UART_CTRL_GET_DRV_STATE_T getDrvState;
	UART_CTRL_GET_CHUNK_SIZE_T getChunkSize;
    kal_char            error_string[256];
    UART_CTRL_OWNER_T   CtrlOwner;
    UART_CTRL_DCB_T     ur_ctrl_set_dcb, ur_ctrl_read_dcb;
    UART_CTRL_FLOW_CTRL_T ur_ctrl_flow_ctrl;

	handle = DclSerialPort_Open(CCCITTY_AT_PORT, 0);


    
/*		tgpd1 = QBM_ALLOC_ONE(CCCI_TTY_DL_BUF_TYPE);
		tgpd2 = QBM_ALLOC_ONE(QBM_TYPE_HIF_DL);
		tgpd3 = QBM_ALLOC_ONE(QBM_TYPE_HIF_UL_TYPE);
		tgpd4 = QBM_ALLOC_ONE(QBM_TYPE_TTY_TYPE1);*/
        
//ian debug	kal_sleep_task(3000);
	/* Conventional owner change to conventional owner */
	{
		UART_CTRL_PUT_BYTES_T ur_ctrl_putbytes;
		char *test_string1 = "[Change owner test] Conventional Owner A change to ";
		char *test_string2 = "Conventional owner B\r\n";

        cccittyut_print("[CCCI_TTY_UT] %s %s!! \r\n", test_string1, test_string2);
        
		ur_ctrl_open.u4OwenrId = MOD_TTY_UT;
		DclSerialPort_Control(handle, SIO_CMD_OPEN, (DCL_CTRL_DATA_T*) &ur_ctrl_open);

		/* Send string */
		ur_ctrl_putbytes.u4OwenrId = MOD_TTY_UT;
		ur_ctrl_putbytes.puBuffaddr = (DCL_UINT8*)test_string1;
		ur_ctrl_putbytes.u2Length = strlen(test_string1);
		DclSerialPort_Control(handle, SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*) &ur_ctrl_putbytes);
		kal_sleep_task(100);

		/* Change owner to MOD_TTY_UT99 */
		ur_ctrl_owner.u4OwenrId = MOD_TTY_UT99;
		DclSerialPort_Control(handle, SIO_CMD_SET_OWNER, (DCL_CTRL_DATA_T*) &ur_ctrl_owner);

		kal_set_active_module_id(MOD_TTY_UT99);
		
		/* Send string */
		ur_ctrl_putbytes.u4OwenrId = MOD_TTY_UT99;
		ur_ctrl_putbytes.puBuffaddr = (DCL_UINT8*)test_string2;
		ur_ctrl_putbytes.u2Length = strlen(test_string2);
		DclSerialPort_Control(handle, SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*) &ur_ctrl_putbytes);
		kal_sleep_task(100);

		/* Get Owner ID */
		DclSerialPort_Control(handle, SIO_CMD_GET_OWNER_ID, (DCL_CTRL_DATA_T*) &CtrlOwner);

		/* Set DCB config */
        // S1. Set DCB.
        ur_ctrl_set_dcb.u4OwenrId = CtrlOwner.u4OwenrId;
        ur_ctrl_set_dcb.rUARTConfig.u4Baud = UR_CONF_U4BAUD;
        ur_ctrl_set_dcb.rUARTConfig.u1DataBits = UR_CONF_U1DATABITS;
        ur_ctrl_set_dcb.rUARTConfig.u1StopBits = UR_CONF_U1STOPBITS;
        ur_ctrl_set_dcb.rUARTConfig.u1Parity = UR_CONF_U1PARITY;
        ur_ctrl_set_dcb.rUARTConfig.u1FlowControl = UR_CONF_U1FLOWCONTROL;
        ur_ctrl_set_dcb.rUARTConfig.ucXonChar = UR_CONF_UCXONCHAR;
        ur_ctrl_set_dcb.rUARTConfig.ucXoffChar = UR_CONF_UCXOFFCHAR;
        ur_ctrl_set_dcb.rUARTConfig.fgDSRCheck = UR_CONF_FGDSRCHECK;
		DclSerialPort_Control(handle, SIO_CMD_SET_DCB_CONFIG, (DCL_CTRL_DATA_T*) &ur_ctrl_set_dcb);

		/* Read DCB config */
		DclSerialPort_Control(handle, SIO_CMD_READ_DCB_CONFIG, (DCL_CTRL_DATA_T*) &ur_ctrl_read_dcb);

        if (!(
            (ur_ctrl_read_dcb.rUARTConfig.u4Baud == ur_ctrl_set_dcb.rUARTConfig.u4Baud) &&
            (ur_ctrl_read_dcb.rUARTConfig.u1DataBits == ur_ctrl_set_dcb.rUARTConfig.u1DataBits) &&
            (ur_ctrl_read_dcb.rUARTConfig.u1StopBits == ur_ctrl_set_dcb.rUARTConfig.u1StopBits) &&
            (ur_ctrl_read_dcb.rUARTConfig.u1Parity == ur_ctrl_set_dcb.rUARTConfig.u1Parity) &&
            (ur_ctrl_read_dcb.rUARTConfig.u1FlowControl == ur_ctrl_set_dcb.rUARTConfig.u1FlowControl) &&
            (ur_ctrl_read_dcb.rUARTConfig.ucXonChar == ur_ctrl_set_dcb.rUARTConfig.ucXonChar) &&
            (ur_ctrl_read_dcb.rUARTConfig.ucXoffChar == ur_ctrl_set_dcb.rUARTConfig.ucXoffChar) &&
            (ur_ctrl_read_dcb.rUARTConfig.fgDSRCheck == ur_ctrl_set_dcb.rUARTConfig.fgDSRCheck))){

            sprintf(error_string, "%s \n",
            "[CCCI_TTY_UT] cccitty_ut_upmod_change_owner_test SIO_CMD_READ_DCB_CONFIG FAIL");
            strncpy(p_ret_err_str, error_string, MIN(strlen(error_string), *p_ret_err_str_sz));
            goto cccitty_ut_chown_err; 
            
        }
		kal_sleep_task(1);

		/* Set flow control */
        ur_ctrl_flow_ctrl.u4OwenrId = CtrlOwner.u4OwenrId;
        DclSerialPort_Control(handle, SIO_CMD_SET_FLOW_CTRL, (DCL_CTRL_DATA_T*) &ur_ctrl_flow_ctrl);
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

        cccittyut_print("[CCCI_TTY_UT] %s %s!! \r\n", test_string1, test_string2);
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
		DclSerialPort_UpModuleReinit(handle, MOD_TTY_UT99, TTY_FLAG_NEW_TX); //Note that CCCI_TTY doesn't support NEW Rx
		DclSerialPort_UpModuleRegisterCb(handle, NULL, NULL, _cccittyut_drv_state_cb);

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
		tx_gpd = QBM_ALLOC_ONE(CCCI_TTY_DL_BUF_TYPE);
		if (tx_gpd) {
			tx_ior = (tty_io_request_t*)QBM_DES_GET_SW_CTRL_FIELD(tx_gpd);
			tx_ior->next_request = NULL;
			tx_ior->first_gpd = tx_gpd;
			tx_ior->last_gpd = tx_gpd;

#if 0       /*20120724 Ian Modify CCCI_COMM for TTYCore*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
            tx_buf_ptr = CCCITTY_GET_QBM_DATAPTR(tx_gpd);
            kal_mem_cpy((void*)tx_buf_ptr, test_string2, strlen(test_string2));
            CCCICOMM_SET_QBM_DATALEN(tx_gpd, strlen(test_string2)); // Set data length
                
            QBM_DES_SET_HWO(tx_gpd);
#endif
			DclSerialPort_UpModuleTransmit(handle, tx_ior);
		} else {
            sprintf(error_string, "%s \n",
            "[CCCI_TTY_UT] Conv-->New GPD allocate failed in CCCI_TTY_DL_BUF_TYPE type");
            strncpy(p_ret_err_str, error_string, MIN(strlen(error_string), *p_ret_err_str_sz));
            goto cccitty_ut_chown_err;
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

        cccittyut_print("[CCCI_TTY_UT] %s %s!! \r\n", test_string1, test_string2);
		/* Bind COM port - initialization */
		status = DclSerialPort_UpModuleInit(handle, MOD_TTY_UT, TTY_FLAG_NEW_TX);  //Note that CCCI_TTY doesn't support NEW Rx
		if (status != STATUS_OK) {
            sprintf(error_string, "%s \n",
            "[CCCI_TTY_UT] New-->New DCL upper module init failed");
            strncpy(p_ret_err_str, error_string, MIN(strlen(error_string), *p_ret_err_str_sz));
            goto cccitty_ut_chown_err;            
		} else {
			DclSerialPort_UpModuleRegisterCb(handle, NULL, NULL, _cccittyut_drv_state_cb);
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
#if 0
/* under construction !*/
/* under construction !*/
#endif
        tx_gpd = QBM_ALLOC_ONE(CCCI_TTY_DL_BUF_TYPE);
		if (tx_gpd) {
			tx_ior = (tty_io_request_t*)QBM_DES_GET_SW_CTRL_FIELD(tx_gpd);
			tx_ior->next_request = NULL;
			tx_ior->first_gpd = tx_gpd;
			tx_ior->last_gpd = tx_gpd;

#if 0       /*20120724 Ian Modify CCCI_COMM for TTYCore*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
            tx_buf_ptr = CCCITTY_GET_QBM_DATAPTR(tx_gpd);
            kal_mem_cpy((void*)tx_buf_ptr, test_string1, strlen(test_string1));
            CCCICOMM_SET_QBM_DATALEN(tx_gpd, strlen(test_string1)); // Set data length

            QBM_DES_SET_HWO(tx_gpd);
#endif

			DclSerialPort_UpModuleTransmit(handle, tx_ior);
		} else {
            sprintf(error_string, "%s \n",
            "[CCCI_TTY_UT] New-->New GPD allocate failed in CCCI_TTY_DL_BUF_TYPE type");
            strncpy(p_ret_err_str, error_string, MIN(strlen(error_string), *p_ret_err_str_sz));
            goto cccitty_ut_chown_err;   
		}
		kal_sleep_task(1);

		/* Send Clear Tx/Rx buffer commands */
		ur_ctrl_clr_buf.u4OwenrId = MOD_TTY_UT; 
		DclSerialPort_Control(handle, SIO_CMD_CLR_TX_BUF, (DCL_CTRL_DATA_T*) &ur_ctrl_clr_buf);
		DclSerialPort_Control(handle, SIO_CMD_CLR_RX_BUF, (DCL_CTRL_DATA_T*) &ur_ctrl_clr_buf);

        //4 <Note> New TTY user should wait for Tx flush done before change owner or close port
        /* No need wait flush since there's no callback*/
        kal_sleep_task(500);
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
#endif

		/* Change owner to MOD_TTY_UT99 */
		ur_ctrl_owner.u4OwenrId = MOD_TTY_UT99;
		DclSerialPort_Control(handle, SIO_CMD_SET_OWNER, (DCL_CTRL_DATA_T*) &ur_ctrl_owner);
		kal_set_active_module_id(MOD_TTY_UT99);
		DclSerialPort_UpModuleReinit(handle, MOD_TTY_UT99, TTY_FLAG_NEW_TX);  //Note that CCCI_TTY doesn't support NEW Rx
		DclSerialPort_UpModuleRegisterCb(handle, NULL, NULL, _cccittyut_drv_state_cb);

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
		tx_gpd = QBM_ALLOC_ONE(CCCI_TTY_DL_BUF_TYPE);
		if (tx_gpd) {
			tx_ior = (tty_io_request_t*)QBM_DES_GET_SW_CTRL_FIELD(tx_gpd);
			tx_ior->next_request = NULL;
			tx_ior->first_gpd = tx_gpd;
			tx_ior->last_gpd = tx_gpd;

#if 0       /*20120724 Ian Modify CCCI_COMM for TTYCore*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
            tx_buf_ptr = CCCITTY_GET_QBM_DATAPTR(tx_gpd);
            kal_mem_cpy((void*)tx_buf_ptr, test_string2, strlen(test_string2));
            CCCICOMM_SET_QBM_DATALEN(tx_gpd, strlen(test_string2)); // Set data length

            QBM_DES_SET_HWO(tx_gpd);
#endif

			DclSerialPort_UpModuleTransmit(handle, tx_ior);
		} else {
            sprintf(error_string, "%s \n",
            "[CCCI_TTY_UT] New-->New GPD allocate failed in CCCI_TTY_DL_BUF_TYPE type - 2");
            strncpy(p_ret_err_str, error_string, MIN(strlen(error_string), *p_ret_err_str_sz));
            goto cccitty_ut_chown_err; 
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

        cccittyut_print("[CCCI_TTY_UT] %s %s!! \r\n", test_string1, test_string2);
		/* Bind COM port - initialization */
		status = DclSerialPort_UpModuleInit(handle, MOD_TTY_UT, TTY_FLAG_NEW_TX);  //Note that CCCI_TTY doesn't support NEW Rx
		if (status != STATUS_OK) {
            sprintf(error_string, "%s \n",
            "[CCCI_TTY_UT] New-->Conv DCL upper module init failed");
            strncpy(p_ret_err_str, error_string, MIN(strlen(error_string), *p_ret_err_str_sz));
            goto cccitty_ut_chown_err; 
		} else {
			DclSerialPort_UpModuleRegisterCb(handle, NULL, NULL, _cccittyut_drv_state_cb);

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
#if 0
/* under construction !*/
/* under construction !*/
#endif
		tx_gpd = QBM_ALLOC_ONE(CCCI_TTY_DL_BUF_TYPE);
		if (tx_gpd) {
			tx_ior = (tty_io_request_t*)QBM_DES_GET_SW_CTRL_FIELD(tx_gpd);
			tx_ior->next_request = NULL;
			tx_ior->first_gpd = tx_gpd;
			tx_ior->last_gpd = tx_gpd;
			
#if 0       /*20120724 Ian Modify CCCI_COMM for TTYCore*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
            tx_buf_ptr = CCCITTY_GET_QBM_DATAPTR(tx_gpd);
			kal_mem_cpy((void*)tx_buf_ptr, test_string1, strlen(test_string1));
            CCCICOMM_SET_QBM_DATALEN(tx_gpd, strlen(test_string1)); // Set data length

            QBM_DES_SET_HWO(tx_gpd);
#endif

			DclSerialPort_UpModuleTransmit(handle, tx_ior);
		} else {
            sprintf(error_string, "%s \n",
            "[CCCI_TTY_UT] New-->ConvGPD allocate failed in CCCI_TTY_DL_BUF_TYPE type");
            strncpy(p_ret_err_str, error_string, MIN(strlen(error_string), *p_ret_err_str_sz));
            goto cccitty_ut_chown_err; 
		}
		kal_sleep_task(1);

		/* Send Clear Tx/Rx buffer commands */
		ur_ctrl_clr_buf.u4OwenrId = MOD_TTY_UT;
		DclSerialPort_Control(handle, SIO_CMD_CLR_TX_BUF, (DCL_CTRL_DATA_T*) &ur_ctrl_clr_buf);
		DclSerialPort_Control(handle, SIO_CMD_CLR_RX_BUF, (DCL_CTRL_DATA_T*) &ur_ctrl_clr_buf);

        //4 <Note> New TTY user should wait for Tx flush done before change owner or close port
        kal_sleep_task(500);
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
#endif        
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

    cccittyut_print("[CCCI_TTY_UT] cccitty_ut_upmod_change_owner_test PASS!! \r\n");
	return KAL_TRUE;
    
cccitty_ut_chown_err:
    cccittyut_print("%s \r\n", error_string);
    return KAL_FALSE;
}


static kal_bool cccitty_ut_conv_tx(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
	#define             TEST_ROUND	100
    #define             WAIT_LIMIT  100
	DCL_STATUS          status;

    kal_char            error_string[256];
    
	DCL_HANDLE          handle;
    kal_uint32          uart_port = CCCITTY_AT_PORT;
    //tty_ut_mode_e       tty_ut_mode = TTY_UT_CONV_TX_ONLY;
    kal_uint32          owner = MOD_NIL;

	DCL_HANDLE          handle1;
    kal_uint32          uart_port1 = CCCITTY_GPS_PORT;
    //tty_ut_mode_e       tty_ut_mode1 = TTY_UT_CONV_TX_ONLY;
    kal_uint32          owner1 = MOD_NIL;
    cccitty_inst_t      *p_cccitty = cccitty_get_instance();    

    cccittyut_print("[CCCI_TTY_UT] cccitty_ut_conv_tx test\r\n");

    cccittyut_print("=====> cccitty_ut_conv_tx initial \r\n");
    /* init for 1st set CCCITTY_AT_PORT*/
    handle = DclSerialPort_Open(uart_port, 0);
    ttyut_create_instance(handle, owner);
	{
		UART_CTRL_OPEN_T data;
		data.u4OwenrId = owner;
		DclSerialPort_Control(handle, SIO_CMD_OPEN, (DCL_CTRL_DATA_T*) &data);
    }

    /* init for 2nd set CCCITTY_GPS_PORT-1*/
    handle1 = DclSerialPort_Open(uart_port1, 0);
    ttyut_create_instance(handle1, owner1);
	{
		status = DclSerialPort_UpModuleInit(handle1, owner1, 0);
		if (status != STATUS_OK) {
			sprintf(error_string, "%s \n",
            "[CCCI_TTY_UT] cccitty_ut_conv_tx : DCL upper module init failed for uart_port: CCCITTY_GPS_PORT-1");
            strncpy(p_ret_err_str, error_string, MIN(strlen(error_string), *p_ret_err_str_sz));
            goto cccitty_ut_conv_tx_err;
		}
	}
    
    /* De-init for 2nd set CCCITTY_GPS_PORT-1*/
    status = DclSerialPort_UpModuleDeinit(handle1);
    if (status != STATUS_OK) {
        sprintf(error_string, "%s \n",
        "[CCCI_TTY_UT] cccitty_ut_conv_tx : DCL upper module deinit failed for uart_port: CCCITTY_GPS_PORT-1");
        strncpy(p_ret_err_str, error_string, MIN(strlen(error_string), *p_ret_err_str_sz));
        goto cccitty_ut_conv_tx_err;
    }

    /* init for 2nd set CCCITTY_GPS_PORT-2*/
    handle1 = DclSerialPort_Open(uart_port1, 0);
    ttyut_create_instance(handle1, owner1);
	{
		status = DclSerialPort_UpModuleInit(handle1, owner1, 0);
		if (status != STATUS_OK) {
			sprintf(error_string, "%s \n",
            "[CCCI_TTY_UT] cccitty_ut_conv_tx : DCL upper module init failed for uart_port: CCCITTY_GPS_PORT-2");
            strncpy(p_ret_err_str, error_string, MIN(strlen(error_string), *p_ret_err_str_sz));
            goto cccitty_ut_conv_tx_err;
		}
	}

    p_cccitty->dcl_txdone = _ccciut_drvtxdone;
    cccittyut_print("=====> start TTY_UT_CONV_TX_ONLY: CCCITTY_AT_PORT\r\n");
    cccittyut_print("[TTY UT] conventional Tx Only Test\r\n");
    {
        int             idx, len;
        DCL_STATUS      ret_st;
        ttyut_instance_t *ttyut_inst_p;
        kal_uint32      retry_num;

        ttyut_inst_p = ttyut_get_instance(handle);
    	ASSERT(ttyut_inst_p);
				
        for (idx = 0; idx < TTY_UT_CONV_BUF_SIZE; idx ++) {
            ttyut_inst_p->ttyut_tx_buf[idx] = 'a' + idx % ('z'-'a'+1);
        }
        /* 1st round - 1~4096 bytes in order */
        /* 0 will cause assert in dcl_tty */
		for (len = 1; len <= 4096; len +=4) {
			UART_CTRL_PUT_BYTES_T ur_ctrl_putbytes;

			cccittyut_print("[TTY UT] cccitty_ut_conv_tx expect send %d bytes data\r\n", len);
            _cccitty_ut_conv_tx_fg = KAL_FALSE;
			ttyut_inst_p->ttyut_tx_offset = 0;
			ttyut_inst_p->ttyut_tx_len = len;
			ur_ctrl_putbytes.u4OwenrId = ttyut_inst_p->owner;
			ur_ctrl_putbytes.puBuffaddr = ttyut_inst_p->ttyut_tx_buf;
			ur_ctrl_putbytes.u2Length = len;
			ret_st = DclSerialPort_Control(handle, SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*) &ur_ctrl_putbytes);

			if (STATUS_OK == ret_st && ur_ctrl_putbytes.u2RetSize > 0) {

				cccittyut_print("[TTY UT] send %d bytes data\r\n", ur_ctrl_putbytes.u2RetSize);
				
				ttyut_inst_p->ttyut_tx_offset = ur_ctrl_putbytes.u2RetSize;
				ttyut_inst_p->ttyut_tx_len -= ur_ctrl_putbytes.u2RetSize;
			}

            if(STATUS_OK != ret_st || ur_ctrl_putbytes.u2RetSize != len){
                sprintf(error_string, "%s ret_st:%x retsize=%d\n",
                    "[CCCI_UT] cccitty_ut_conv_tx cannot finish the tx",
                    (kal_uint32)ret_st,
                    ur_ctrl_putbytes.u2RetSize);
                strncpy(p_ret_err_str, error_string, MIN(strlen(error_string), *p_ret_err_str_sz));
                goto cccitty_ut_conv_tx_err;
            }

            retry_num = 0;
            while(KAL_TRUE != _cccitty_ut_conv_tx_fg){
                retry_num++;
                if(retry_num>WAIT_LIMIT){
                    sprintf(error_string, "%s:%d %s ttyut_tx_len=%d\n",
                    "[CCCI_UT] cccitty_ut_conv_tx cannot finish the tx in",
                    retry_num*10, //KAL_TICKS_10_MSEC
                    "ms",
                    ttyut_inst_p->ttyut_tx_len);
                    
        			strncpy(p_ret_err_str, error_string, MIN(strlen(error_string), *p_ret_err_str_sz));
                    goto cccitty_ut_conv_tx_err;
                }
                kal_sleep_task(KAL_TICKS_10_MSEC);
            }
            /* Note: that if the sleep time is not enough, the TTYCore will ask source to wait for UART_READY_TO_WRITE
               and that will send the ilm to MOD_NIL, the owenr of CCCITTY_AT_PORT, and cause ASSERT*/
            //kal_sleep_task(KAL_TICKS_10_MSEC*100); /* I have to enforce the Tx has been done, or TTYCore will send ilm */
		}
    }

    cccittyut_print("=====> cccitty_ut_conv_tx de-initial \r\n");
    /* De-init for 1st set CCCITTY_AT_PORT*/
    status = DclSerialPort_UpModuleDeinit(handle);
    if (status != STATUS_OK) {
        sprintf(error_string, "%s \n",
        "[CCCI_TTY_UT] cccitty_ut_conv_tx : DCL upper module deinit failed for uart_port: CCCITTY_AT_PORT");
        strncpy(p_ret_err_str, error_string, MIN(strlen(error_string), *p_ret_err_str_sz));
        goto cccitty_ut_conv_tx_err;
    }
    /* De-init for 2nd set CCCITTY_GPS_PORT-2*/
    status = DclSerialPort_UpModuleDeinit(handle1);
    if (status != STATUS_OK) {
        sprintf(error_string, "%s \n",
        "[CCCI_TTY_UT] cccitty_ut_conv_tx : DCL upper module deinit failed for uart_port: CCCITTY_GPS_PORT-2");
        strncpy(p_ret_err_str, error_string, MIN(strlen(error_string), *p_ret_err_str_sz));
        goto cccitty_ut_conv_tx_err;
    }
    p_cccitty->dcl_txdone = DclSerialPort_DrvTxDone;
    cccittyut_print("[CCCI_TTY_UT] cccitty_ut_conv_tx PASS!! \r\n");
    ttyut_del_instance(ttyut_get_instance(handle));
    ttyut_del_instance(ttyut_get_instance(handle1));
    
	return KAL_TRUE;
cccitty_ut_conv_tx_err:
    ttyut_del_instance(ttyut_get_instance(handle));
    ttyut_del_instance(ttyut_get_instance(handle1));
    p_cccitty->dcl_txdone = DclSerialPort_DrvTxDone;
    cccittyut_print("%s \r\n", error_string);
    return KAL_FALSE;     
}

extern int rand(void);
static kal_bool cccitty_ut_new_tx(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
	#define             TEST_ROUND	100
    #define             WAIT_LIMIT  100
	DCL_STATUS          status;

    kal_char            error_string[256];
    
	DCL_HANDLE          handle;
    kal_uint32          uart_port = CCCITTY_DHL_PORT;
    //tty_ut_mode_e       tty_ut_mode = TTY_UT_NEW_TX_ONLY;
    kal_uint32          owner = MOD_NIL;
    cccitty_inst_t      *p_cccitty = cccitty_get_instance();    
    UART_CTRL_GET_DRV_STATE_T getDrvState;
    UART_CTRL_GET_CHUNK_SIZE_T getChunkSize;
    

    cccittyut_print("[CCCI_TTY_UT] cccitty_ut_new_tx test\r\n");

    cccittyut_print("=====> cccitty_ut_new_tx initial \r\n");
    /* init for 1st set CCCITTY_DHL_PORT*/
	/* Bind COM port - initialization */
    handle = DclSerialPort_Open(uart_port, 0);
    ttyut_create_instance(handle, owner);
	status = DclSerialPort_UpModuleInit(handle, owner, TTY_FLAG_NEW_TX);
	if (status != STATUS_OK) {
    	cccittyut_print("[TTY UT] DCL upper module init failed");
	} else {
	 	DclSerialPort_UpModuleRegisterCb(handle, NULL, _cccittyut_tx_done_cb, _cccittyut_drv_state_cb);

        // Wait for device ready
        getDrvState.u4OwnerId = owner;
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

    p_cccitty->dcl_txdone = _ccciut_drvtxdone;
    cccittyut_print("=====> start TTY_UT_NEW_TX_ONLY: CCCITTY_DHL_PORT\r\n");
    cccittyut_print("[TTY UT] New Tx Only Test\r\n");
    {
        kal_uint32 idx;
        ttyut_instance_t *ttyut_inst_p;

        ttyut_inst_p = ttyut_get_instance(handle);
    	ASSERT(ttyut_inst_p);        
        
        for (idx = 0; idx < TTY_UT_NEW_BUF_SIZE; idx ++) {
            ttyut_inst_p->ttyut_tx_buf[idx] = 'a' + idx % ('z'-'a'+1);
        }
        for (idx = 0; idx < 1024; idx ++)
        {
            void *tx_gpd;
            tty_io_request_t *tx_ior;
            unsigned char *tx_buf_ptr;
            kal_uint32      retry_num;

            cccittyut_print("\n\r [TTY UT] cccitty_ut_NEW_tx send_idx %d \r\n", idx);
            
            tx_gpd = QBM_ALLOC_ONE(CCCI_TTY_DL_BUF_TYPE);
            if (tx_gpd) {
                tx_ior = (tty_io_request_t*)QBM_DES_GET_SW_CTRL_FIELD(tx_gpd);
                tx_ior->next_request = NULL;
                tx_ior->first_gpd = tx_gpd;
                tx_ior->last_gpd = tx_gpd;
                ttyut_inst_p->ttyut_tx_len = rand()%TTY_UT_NEW_BUF_SIZE + 1;
						
                tx_buf_ptr = CCCITTY_GET_QBM_DATAPTR(tx_gpd);
                kal_mem_cpy((void*)tx_buf_ptr, ttyut_inst_p->ttyut_tx_buf, ttyut_inst_p->ttyut_tx_len);
                CCCICOMM_SET_QBM_DATALEN(tx_gpd, ttyut_inst_p->ttyut_tx_len); // Set data length
                QBM_DES_SET_HWO(tx_gpd);
                //QBM_CACHE_FLUSH(tx_gpd, sizeof(qbm_gpd));

                //kal_printf("[TTY UT] send %d bytes data\r\n", ttyut_inst_p->ttyut_tx_len);
                DclSerialPort_UpModuleTransmit(handle, tx_ior);
            } else {
                sprintf(error_string, "%s \r\n",
                "[CCCI_TTY_UT] cccitty_ut_new_tx : GPD allocate failed CCCI_TTY_DL_BUF_TYPE uart_port: CCCITTY_DHL_PORT");
                strncpy(p_ret_err_str, error_string, MIN(strlen(error_string), *p_ret_err_str_sz));
                goto cccitty_ut_new_tx_err;
            }
			/* TODO: check scheduling/priority issue */
			//kal_sleep_task(100);
			retry_num = 0;
			while(KAL_TRUE != _cccitty_ut_conv_tx_fg){
                retry_num++;
                if(retry_num>WAIT_LIMIT){
                    sprintf(error_string, "%s:%d %s ttyut_tx_len=%d\n",
                    "[CCCI_TTY_UT] cccitty_ut_NEW_tx cannot finish the tx in",
                    retry_num*10, //KAL_TICKS_10_MSEC
                    "ms",
                    ttyut_inst_p->ttyut_tx_len);
                    
        			strncpy(p_ret_err_str, error_string, MIN(strlen(error_string), *p_ret_err_str_sz));
                    goto cccitty_ut_new_tx_err;
                }
                kal_sleep_task(KAL_TICKS_10_MSEC);
            }
        }
    }

    cccittyut_print("=====> cccitty_ut_new_tx de-initial \r\n");
    /* De-init for 1st set CCCITTY_DHL_PORT*/
    status = DclSerialPort_UpModuleDeinit(handle);
    if (status != STATUS_OK) {
        sprintf(error_string, "%s \n",
        "[CCCI_TTY_UT] cccitty_ut_new_tx : DCL upper module deinit failed for uart_port: CCCITTY_DHL_PORT");
        strncpy(p_ret_err_str, error_string, MIN(strlen(error_string), *p_ret_err_str_sz));
        goto cccitty_ut_new_tx_err;
    }
    ttyut_del_instance(ttyut_get_instance(handle));
    p_cccitty->dcl_txdone = DclSerialPort_DrvTxDone;
    cccittyut_print("[CCCI_TTY_UT] cccitty_ut_new_tx PASS!! \r\n");
	return KAL_TRUE;

cccitty_ut_new_tx_err:
    ttyut_del_instance(ttyut_get_instance(handle));
    p_cccitty->dcl_txdone = DclSerialPort_DrvTxDone;
    cccittyut_print("%s \r\n", error_string);
    return KAL_FALSE;     
}

extern kal_uint32 cccitty_reset_ccci_comm_gpd_list(qbm_gpd* first_gpd, qbm_gpd* last_gpd);
extern DCL_STATUS cccitty_ttyc_hdr(DCL_DEV dev, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);
DCL_STATUS _cccitty_ut_DrvRx(DCL_HANDLE handle, module_type source_id, ccci_io_request_t* rx_ior)
{
    kal_uint32          rgpd_cnt;
    UART_CTRL_ASSIGN_RX_IOR_T ur_ctrl_assign_rxior;
    kal_uint32          uart_port = CCCITTY_AT_PORT;
    
    /* reset the gpd */
    rgpd_cnt = cccitty_reset_ccci_comm_gpd_list(rx_ior->first_gpd, rx_ior->last_gpd);

    cccittyut_print("========> _cccitty_ut_DrvRx source_id: %x rgpd_cnt (%d)!! \r\n", source_id, rgpd_cnt);     
    /* call reload gpd */

//		result = tty_mgmt_info[device].sp_handler_cb(device, TTY_CMD_ASSIGN_RX_IOR, (DCL_CTRL_DATA_T *)&ur_ctrl_assign_rxior);    
    ur_ctrl_assign_rxior.u4OwnerId = MOD_NIL;
    ur_ctrl_assign_rxior.ior = rx_ior;
    cccitty_ttyc_hdr(uart_port, TTY_CMD_ASSIGN_RX_IOR, (DCL_CTRL_DATA_T *)&ur_ctrl_assign_rxior);

    return STATUS_OK;
}
kal_int32 _cccitty_ut_write_gpd(CCCI_CHANNEL_T channel, ccci_io_request_t *p_ccci_DL_ior, ccci_io_ext_info_t* pinfo){

    cccittyut_print("========> _cccitty_ut_write_gpd channel: %d!! \r\n", channel); 
    qbmt_dest_q(p_ccci_DL_ior->first_gpd, p_ccci_DL_ior->last_gpd);
    return CCCI_SUCCESS;
}
#define CCCITTYUT_MAGIC1 0xf1f2f3f4
#define CCCITTYUT_MAGIC2 0xa1a2a3a4

void _cccitty_format_cccih(CCCI_BUFF_T *pcccih, kal_uint32 ch){
    pcccih->data[0] = CCCITTYUT_MAGIC1;
    pcccih->data[1] = sizeof(CCCI_BUFF_T);
    pcccih->channel = ch;
    pcccih->reserved = CCCITTYUT_MAGIC2;
}

void _cccitty_format_gpd(qbm_gpd *first_gpd,qbm_gpd *last_gpd, kal_uint32 ch){
    qbm_gpd*            current_gpd = NULL;
    CCCI_BUFF_T         *pcccih;
    
    ASSERT(first_gpd && last_gpd);
  
    current_gpd = first_gpd;
    do {
        pcccih = CCCITTY_GET_QBM_DATAPTR(current_gpd);
        _cccitty_format_cccih(pcccih, ch);
        //add dummy data length
        pcccih->data[1] = pcccih->data[1] + 10;
        if ( current_gpd == last_gpd )
        {
            break;
        }
        current_gpd = QBM_DES_GET_NEXT(current_gpd);

    } while ( current_gpd != NULL );    
}
extern void cccitty_ccci_ul_cb(CCCI_CHANNEL_T channel, ccci_io_request_t* io_request);
kal_bool cccitty_ut_conv_rx(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
    cccitty_inst_t      *p_cccitty = cccitty_get_instance();
    kal_char            error_string[256];
    kal_uint32          idx;
    ccci_io_request_t   ior;
    kal_uint32          to_alloc, num_alloc;
    DCL_STATUS          status;
	DCL_HANDLE          handle;
    kal_uint32          uart_port = CCCITTY_AT_PORT;
    kal_uint32          ccci_rx_ch = CCCI_AT_CHANNEL_RX;
    //tty_ut_mode_e       tty_ut_mode = TTY_UT_CONV_TX_ONLY;
    kal_uint32          owner = MOD_NIL;
    CCCI_BUFF_T         *p_cccih;
    //ttyut_instance_t    *ttyut_inst_p;
    UART_CTRL_CLR_BUFFER_T data;

    cccittyut_print("[CCCI_TTY_UT] cccitty_ut_conv_rx test\r\n");

    p_cccitty->dcl_rx = _cccitty_ut_DrvRx;
    p_cccitty->ccci_write_gpd = _cccitty_ut_write_gpd;

    //4 <1> cccitty_ccci_ul_cb
    /* <1-1> invalid CCCI channel */
    cccitty_ccci_ul_cb(0, NULL);
    /* <1-2> invalid IOR */
    cccitty_ccci_ul_cb(CCCI_GPS_CHANNEL_RX, NULL);

    ior.next_request = NULL;

    to_alloc = 5;
    /* <1-3> send ior to close channel expect the gpd will be reloaded to HIF*/
    for(idx = 0; idx < 500; idx++){
        num_alloc = qbmt_alloc_q_no_tail(CCCI_TTY_UL_BUF_TYPE, to_alloc, (void**)&ior.first_gpd, (void**)&ior.last_gpd);
        ASSERT(num_alloc == to_alloc);
        cccitty_ccci_ul_cb(CCCI_GPS_CHANNEL_RX, &ior);
    }
    //4 <2> open AT port
    /* init for 1st set CCCITTY_AT_PORT*/
    handle = DclSerialPort_Open(uart_port, 0);
    ttyut_create_instance(handle, owner);
	{
		UART_CTRL_OPEN_T data;
		data.u4OwenrId = owner;
		DclSerialPort_Control(handle, SIO_CMD_OPEN, (DCL_CTRL_DATA_T*) &data);
    }
    //ttyut_inst_p = ttyut_get_instance(handle);

    //4 <3> Rx 1 invalid RGPD
    cccittyut_print("===> cccitty_ut_conv_rx test <3> Rx 1 invalid RGPD \r\n");     
    to_alloc = 1;

    num_alloc = qbmt_alloc_q_no_tail(CCCI_TTY_UL_BUF_TYPE, to_alloc, (void**)&ior.first_gpd, (void**)&ior.last_gpd);
    ASSERT(num_alloc == to_alloc);
    /* format RGPD*/
    p_cccih = CCCITTY_GET_QBM_DATAPTR(ior.first_gpd);
    /* make the ccci channel error */
    _cccitty_format_cccih(p_cccih, CCCI_GPS_CHANNEL_RX);
    cccitty_ccci_ul_cb(ccci_rx_ch, &ior);

    //4 <4> Rx 1 valid RGPD
    cccittyut_print("===> cccitty_ut_conv_rx test <4> Rx 1 valid RGPD \r\n");     
    to_alloc = 1;

    num_alloc = qbmt_alloc_q_no_tail(CCCI_TTY_UL_BUF_TYPE, to_alloc, (void**)&ior.first_gpd, (void**)&ior.last_gpd);
    ASSERT(num_alloc == to_alloc);
    /* format RGPD*/
    p_cccih = CCCITTY_GET_QBM_DATAPTR(ior.first_gpd);
    _cccitty_format_cccih(p_cccih, ccci_rx_ch);
    //add dummy data length to ccci header
    p_cccih->data[1] = p_cccih->data[1] + 10;
    cccitty_ccci_ul_cb(ccci_rx_ch, &ior);

    //4 <5> Rx (1 invalid RGPD) /(1 valid RGPD)
    cccittyut_print("===> cccitty_ut_conv_rx test <5> Rx (1 invalid RGPD) /(1 valid RGPD) \r\n");     
    to_alloc = 2;

    num_alloc = qbmt_alloc_q_no_tail(CCCI_TTY_UL_BUF_TYPE, to_alloc, (void**)&ior.first_gpd, (void**)&ior.last_gpd);
    ASSERT(num_alloc == to_alloc);
    /* format 1st RGPD*/
    p_cccih = CCCITTY_GET_QBM_DATAPTR(ior.first_gpd);
    /* make the ccci channel error */
    _cccitty_format_cccih(p_cccih, CCCI_GPS_CHANNEL_RX);
    /* format 2nd RGPD*/
    p_cccih = CCCITTY_GET_QBM_DATAPTR(ior.last_gpd);
    _cccitty_format_cccih(p_cccih, ccci_rx_ch);
    //add dummy data length to ccci header
    p_cccih->data[1] = p_cccih->data[1] + 10;
    cccitty_ccci_ul_cb(ccci_rx_ch, &ior);    

    //4 <6> Rx (1 valid RGPD) /(1 invalid RGPD)
    cccittyut_print("===> cccitty_ut_conv_rx test <6> Rx (1 valid RGPD) /(1 invalid RGPD) \r\n");     
    to_alloc = 2;

    num_alloc = qbmt_alloc_q_no_tail(CCCI_TTY_UL_BUF_TYPE, to_alloc, (void**)&ior.first_gpd, (void**)&ior.last_gpd);
    ASSERT(num_alloc == to_alloc);
    /* format 1st RGPD*/
    p_cccih = CCCITTY_GET_QBM_DATAPTR(ior.first_gpd);
    _cccitty_format_cccih(p_cccih, ccci_rx_ch);
    //add dummy data length to ccci header
    p_cccih->data[1] = p_cccih->data[1] + 10;

    /* format 2nd RGPD*/
    p_cccih = CCCITTY_GET_QBM_DATAPTR(ior.last_gpd);
    /* make the ccci channel error */
    _cccitty_format_cccih(p_cccih, CCCI_GPS_CHANNEL_RX);

    cccitty_ccci_ul_cb(ccci_rx_ch, &ior);    
    //4 <7> Rx (1 valid RGPD) /(1 invalid RGPD) /(1 invalid RGPD)
    cccittyut_print("===> cccitty_ut_conv_rx test <7> Rx (1 valid RGPD) /(1 invalid RGPD) /(1 invalid RGPD) \r\n");     
    to_alloc = 3;

    num_alloc = qbmt_alloc_q_no_tail(CCCI_TTY_UL_BUF_TYPE, to_alloc, (void**)&ior.first_gpd, (void**)&ior.last_gpd);
	ASSERT(num_alloc == to_alloc);
    /* format 1st RGPD*/
    p_cccih = CCCITTY_GET_QBM_DATAPTR(ior.first_gpd);
    _cccitty_format_cccih(p_cccih, ccci_rx_ch);
    //add dummy data length to ccci header
    p_cccih->data[1] = p_cccih->data[1] + 10;

    /* format 2nd RGPD*/
    p_cccih = CCCITTY_GET_QBM_DATAPTR(QBM_DES_GET_NEXT(ior.first_gpd));
    /* make the ccci channel error */
    _cccitty_format_cccih(p_cccih, CCCI_GPS_CHANNEL_RX);

    /* format 3rd RGPD*/
    p_cccih = CCCITTY_GET_QBM_DATAPTR(ior.last_gpd);
    /* make the ccci channel error */
    _cccitty_format_cccih(p_cccih, CCCI_GPS_CHANNEL_RX);
    cccitty_ccci_ul_cb(ccci_rx_ch, &ior);        

    //4 <8> test flush while hif_ul_q is not empty

    cccittyut_print("===> cccitty_ut_conv_rx test <8> test flush while hif_ul_q is not empty \r\n");     
    to_alloc = 5;
    for(idx = 0; idx < 100; idx++){
        num_alloc = qbmt_alloc_q_no_tail(CCCI_TTY_UL_BUF_TYPE, to_alloc, (void**)&ior.first_gpd, (void**)&ior.last_gpd);
    	ASSERT(num_alloc == to_alloc);
        _cccitty_format_gpd(ior.first_gpd, ior.last_gpd, ccci_rx_ch);

        cccitty_ccci_ul_cb(ccci_rx_ch, &ior);
    }

  	data.u4OwenrId = MOD_NIL;
   	p_cccitty->dcl_rx = DclSerialPort_DrvRx;
   	DclSerialPort_Control(handle, SIO_CMD_CLR_RX_BUF, (DCL_CTRL_DATA_T*) &data);

    //4 <9> cloase AT port 
    p_cccitty->dcl_rx = DclSerialPort_DrvRx;

    /* De-init for 1st set CCCITTY_AT_PORT*/
    status = DclSerialPort_UpModuleDeinit(handle);
    if (status != STATUS_OK) {
        sprintf(error_string, "%s \n",
        "[CCCI_TTY_UT] cccitty_ut_conv_rx : DCL upper module deinit failed for uart_port: CCCITTY_AT_PORT");
        strncpy(p_ret_err_str, error_string, MIN(strlen(error_string), *p_ret_err_str_sz));
        goto cccitty_ut_conv_rx_err;
    }
    
    ttyut_del_instance(ttyut_get_instance(handle));
    p_cccitty->ccci_write_gpd = ccci_write_gpd;
    cccittyut_print("[CCCI_TTY_UT] cccitty_ut_conv_rx PASS!! \r\n");
    return KAL_TRUE;

cccitty_ut_conv_rx_err:
    
    ttyut_del_instance(ttyut_get_instance(handle));
    p_cccitty->dcl_rx = DclSerialPort_DrvRx;
    p_cccitty->ccci_write_gpd = ccci_write_gpd;
    cccittyut_print("%s \r\n", error_string);
    return KAL_FALSE;
}

#define CCCITTY_EX_MAGIC 123
kal_int32 cccitty_ut_except_clear_ch(kal_uint32 ccci_ch)
{
    return CCCI_SUCCESS;
}
kal_int32 cccitty_ut_except_set_gpd(kal_uint32 expt_ch, void *p_first_gpd, void *p_last_gpd)
{
    qbmt_dest_q(p_first_gpd, p_last_gpd);
    return CCCI_SUCCESS;
}
kal_int32 cccitty_ut_except_poll_gpd(kal_uint32 expt_ch, void **pp_first_gpd, void **pp_last_gpd, kal_uint32 *gpd_num)
{
    *gpd_num = CCCITTY_EX_MAGIC;
    return CCCI_SUCCESS;
}
kal_int32 cccitty_ut_except_hif_st(kal_uint32 expt_dl_ch)
{
    return CCCI_SUCCESS;
}
kal_int32 cccitty_ut_except_hif_isr(kal_uint32 expt_dl_ch)
{
    return CCCI_SUCCESS;
}
kal_bool cccitty_ut_ex(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
	DCL_HANDLE          handle;
    TTY_CTRL_EXCP_HIF_STATE_T ttyCtlHifSt;
    TTY_CTRL_EXCP_TX_GPD_T ttyCtlTxGpd;
    TTY_CTRL_EXCP_TX_DONE_INFO_T ttyCtlTxDoneInfo;
    TTY_CTRL_EXCP_ASSIGN_RX_GPD_T ttyCtlAsnRxGpd;
    TTY_CTRL_EXCP_GET_RX_GPD_T ttyCtlGetRxGpd;
    UART_CTRL_GET_CHUNK_SIZE_T ur_ctrl_get_chunk_size;
    UART_CTRL_GET_MTU_SIZE_T ur_ctrl_get_mtu_size, ur_ctrl_get_mtu_size_tmp;
    kal_char            error_string[256];
    
    //4 <1> initialize the ccci_tty exception port
    cccitty_dev_expt_init();   

    //4 <2> HIF_INIT and CLEAR_CHANNEL
    handle = DclSerialPort_Open(uart_port_dhl_sp_expt, 0);

    DclSerialPort_Control(handle, TTY_CMD_EXCEPTION_HIF_INIT, NULL);
    DclSerialPort_Control(handle, TTY_CMD_EXCEPTION_CLEAR_CHANNEL, NULL);
    DclSerialPort_Control(handle, TTY_CMD_EXCEPTION_RESET, NULL);
    DclSerialPort_Control(handle, TTY_CMD_EXCEPTION_HIF_POLL, NULL);
    DclSerialPort_Control(handle, TTY_CMD_GET_MTU_SIZE, (DCL_CTRL_DATA_T*) &ur_ctrl_get_mtu_size);
    kal_mem_set(&ur_ctrl_get_mtu_size_tmp, 0, sizeof(UART_CTRL_GET_MTU_SIZE_T));
    cccitty_ttyc_hdr_cmd_get_mtu_size(0, &ur_ctrl_get_mtu_size_tmp.dlmtu_sz, &ur_ctrl_get_mtu_size_tmp.ulmtu_sz);
    if(ur_ctrl_get_mtu_size.dlmtu_sz != ur_ctrl_get_mtu_size_tmp.dlmtu_sz ||
       ur_ctrl_get_mtu_size.ulmtu_sz != ur_ctrl_get_mtu_size_tmp.ulmtu_sz){
        cccittyut_print("[CCCI_TTY_UT] cccitty_ut_ex FAIL !! TTY_CMD_GET_MTU_SIZE\r\n");
        sprintf(error_string, "%s \n", "[CCCI_TTY_UT] cccitty_ut_ex FAIL !! TTY_CMD_GET_MTU_SIZE");
        strncpy(p_ret_err_str, error_string, MIN(strlen(error_string), *p_ret_err_str_sz));
        return KAL_FALSE;
    }
    

    //4 <3> HIF_STATE    
    DclSerialPort_Control(handle, TTY_CMD_EXCEPTION_HIF_STATE, (DCL_CTRL_DATA_T*) &ttyCtlHifSt);
    if (ttyCtlHifSt.hif_state != HIF_STATE_NORMAL) {
        cccittyut_print("[CCCI_TTY_UT] cccitty_ut_ex FAIL !! TTY_CMD_EXCEPTION_HIF_STATE\r\n");
        sprintf(error_string, "%s \n", "[CCCI_TTY_UT] cccitty_ut_ex FAIL !! TTY_CMD_EXCEPTION_HIF_STATE");
        strncpy(p_ret_err_str, error_string, MIN(strlen(error_string), *p_ret_err_str_sz));
        return KAL_FALSE;
    }

    //4 <4> TX_GPD
    ttyCtlTxGpd.first_gpd = QBM_ALLOC_ONE(CCCI_TTY_DL_BUF_TYPE); /* the DHL will use non-free type TGPD/RGPD*/
    ttyCtlTxGpd.last_gpd  = ttyCtlTxGpd.first_gpd;
    DclSerialPort_Control(handle, TTY_CMD_EXCEPTION_TX_GPD, (DCL_CTRL_DATA_T*) &ttyCtlTxGpd);
    DclSerialPort_Control(handle, TTY_CMD_EXCEPTION_TX_DONE_INFO, (DCL_CTRL_DATA_T*) &ttyCtlTxDoneInfo);
    if (ttyCtlTxDoneInfo.num != CCCITTY_EX_MAGIC) { /* preset return number, checking if the api is called correctly */
        cccittyut_print("[CCCI_TTY_UT] cccitty_ut_ex FAIL !! TTY_CMD_EXCEPTION_TX_DONE_INFO\r\n");
        sprintf(error_string, "%s \n", "[CCCI_TTY_UT] cccitty_ut_ex FAIL !! TTY_CMD_EXCEPTION_TX_DONE_INFO");
        return KAL_FALSE;
    }
    
    //4 <5> RX_GPD
    ttyCtlAsnRxGpd.first_gpd = QBM_ALLOC_ONE(CCCI_TTY_DL_BUF_TYPE); /* the DHL will use non-free type TGPD/RGPD*/
    ttyCtlAsnRxGpd.last_gpd  = ttyCtlAsnRxGpd.first_gpd;    
    DclSerialPort_Control(handle, TTY_CMD_EXCEPTION_ASSIGN_RX_GPD, (DCL_CTRL_DATA_T*) &ttyCtlAsnRxGpd);
    DclSerialPort_Control(handle, TTY_CMD_EXCEPTION_GET_RX_GPD, (DCL_CTRL_DATA_T*) &ttyCtlGetRxGpd);
    if (ttyCtlGetRxGpd.num != CCCITTY_EX_MAGIC) { /* preset return number, checking if the api is called correctly */
        cccittyut_print("[CCCI_TTY_UT] cccitty_ut_ex FAIL !! TTY_CMD_EXCEPTION_GET_RX_GPD\r\n");
        sprintf(error_string, "%s \n", "[CCCI_TTY_UT] cccitty_ut_ex FAIL !! TTY_CMD_EXCEPTION_GET_RX_GPD");
        return KAL_FALSE;
    }

    DclSerialPort_Control(handle, TTY_CMD_GET_CHUNK_SIZE, (DCL_CTRL_DATA_T*)&ur_ctrl_get_chunk_size);
    cccittyut_print("[CCCI_TTY_UT] cccitty_ut_ex PASS!! \r\n");
    return KAL_TRUE;
}

kal_bool cccitty_ut_hmu(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){

        kal_uint32 idx;

        for(idx = CCCI_TTY_COM_ID_MIN; idx < CCCI_TTY_COM_ID_MAX; idx++){
            cccitty_dev_deinit(idx);
        }

        for(idx = CCCI_TTY_COM_ID_MIN; idx < CCCI_TTY_COM_ID_MAX; idx++){
            cccitty_dev_init(idx);
        }
        
        cccittyut_print("[CCCI_TTY_UT] cccitty_ut_hmu PASS!! \r\n");

        /* The only case that will fail is ASSERTION during state change*/
        return KAL_TRUE;
}

extern void cccitty_ccci_dummy_cb(CCCI_CHANNEL_T channel, ccci_io_request_t* io_request);
kal_bool cccitty_ut_misc(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
     
        /* This function should not be called during the entire process */
        /* The purpose of this function is keep the architecture compatible with MT6280 */
        cccitty_ccci_dummy_cb(0, NULL);

        
        cccittyut_print("[CCCI_TTY_UT] cccitty_ut_misc PASS!! \r\n");
        return KAL_TRUE;
}
kal_bool cccitty_dummy(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
        return KAL_TRUE;
}

extern kal_bool st_reg_test(kal_char *p_mod_name, ST_TCASE_T *p_tcase, kal_uint32 tcase_num);

ST_TCASE_T st_tcase_cccitty_g[] = {
    {"cccitty_dummy",               cccitty_dummy,                NULL},    
    {"cccittyut_init",              cccittyut_init,               NULL},
    {"1.1 cccitty_ut_init_deinit",  cccitty_ut_init_deinit,       NULL}, 
    {"1.2 cccitty_ut_chown",        cccitty_ut_upmod_change_owner_test,      NULL},  
    {"1.3 conventional TX test",    cccitty_ut_conv_tx,           NULL},
    {"1.4 New TX test",             cccitty_ut_new_tx,            NULL},
    {"1.5 Conv RX test",            cccitty_ut_conv_rx,           NULL},
	{"1.6 Exception Mode test",     cccitty_ut_ex,                NULL},
    {"1.7 HMU test",                cccitty_ut_hmu,               NULL},
    {"1.8 MISC",                    cccitty_ut_misc,              NULL},
    {"cccitty_dummy",               cccitty_dummy,                NULL}
};
kal_uint32 st_tcase_count_cccitty_g = sizeof(st_tcase_cccitty_g) / sizeof(ST_TCASE_T);

kal_bool cccitty_ut_st_create()
{
    tst_sys_trace("112234");
    return st_reg_test("CCCI_TTY", st_tcase_cccitty_g, st_tcase_count_cccitty_g);
}
#endif //#if defined(ATEST_SYS_CCCI_TTY)
