#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"

#include "drv_features.h"
#include "drv_comm.h"

#include "drv_msgid.h"
#include "stack_msgs.h"
#include "stack_ltlcom.h"

#include "drv_hisr.h"
#include "intrCtrl.h"

#include "idc_internal.h"
#include "dcl_idc.h"
#include "drv_idc.h"

#include "idc_reg.h"
#include "svc_sap.h"

#ifdef ATEST_DRV_ENABLE
#define dhl_trace(...) 
#define DT_IDC_PRINTF(x...) \
do{                         \
	dbg_print(x);           \
	dbg_flush();            \
}while(0)
#else /*ATEST_DRV_ENABLE*/
#include "dhl_trace.h"
#include "idc_trace.h"
#endif

#include "pll.h"
#define BUS_CLOCK	(BUS_CLOCK_MHZ*1000000)
#define PHY_CLOCK_MHZ	(52)

idc_struct_t idc_port = {0, IDC_CLOSED, KAL_FALSE, {IDC_PLAN, IDC_PLAN}, {0, 0}, 0, {0, 0}, 0, {0, len_8, sb_1, pa_none}, IDC_INTERNAL_PIN};
kal_char idc_dbg_str[100];
kal_bool idc_read_RBR = KAL_FALSE;
kal_uint8 idc_rx_count = 0;
kal_uint8 idc_rx_history[20] = {0};
kal_uint32 idc_rx_history_time[20] = {0};
kal_uint8 idc_hisr_count = 0;
kal_uint32 idc_hisr_time[20] = {0};

kal_bool idc_count_start = KAL_FALSE;
kal_uint32 idc_80211_tx_count = 0;
kal_uint32 idc_80211_rx_count = 0;

void drv_idc_conn_txrx_count(kal_bool is_start)
{
	if (KAL_TRUE == is_start)
	{
		dhl_trace(TRACE_INFO, 0, IDC_START_COUNT_MSG);
		idc_count_start = KAL_TRUE;
		idc_80211_tx_count = 0;
		idc_80211_rx_count = 0;
	}
	else
	{
		idc_count_start = KAL_FALSE;
		dhl_trace(TRACE_INFO, 0, IDC_END_COUNT_MSG, idc_80211_tx_count, idc_80211_rx_count);
	}
}

#if defined(MT6290)
#include "eint.h"
extern const unsigned char TDM_REQ_LO_EINT_NO;
extern const unsigned char TDM_REQ_HI_EINT_NO;
extern void EINT_Set_HW_Debounce_Enable(kal_uint8 eintno, kal_uint32 debounce_en);

void TDM_REQ_HI_Entry(void)
{
	IDC_ILM_MSG_T tmp;
	tmp.type = 3;
	tmp.msg = 100;

	// send msg to EL2 that LTE_TX is not Allowed
#if !defined(ATEST_DRV_ENABLE)
	dhl_trace(TRACE_INFO, 0, IDC_TDM_HI_MSG);
#else
	kal_sprintf(idc_dbg_str, "TDM_REQ_HI_Entry\n\r");
	DT_IDC_PRINTF(idc_dbg_str);
#endif
	msg_send_inline6(DRV_IDC_HISR_ID, idc_port.owner_id, DRIVER_PS_SAP | INLINE_ILM_FLAG_SAP, MSG_ID_IDC_RX_DATA, (void *) &tmp, sizeof(IDC_ILM_MSG_T));
	EINT_UnMask(TDM_REQ_LO_EINT_NO);
}

void TDM_REQ_LO_Entry(void)
{
	IDC_ILM_MSG_T tmp;
	tmp.type = 3;
	tmp.msg = 0;

#if !defined(ATEST_DRV_ENABLE)
	dhl_trace(TRACE_INFO, 0, IDC_TDM_LO_MSG);
#else
	kal_sprintf(idc_dbg_str, "TDM_REQ_LO_Entry\n\r");
	DT_IDC_PRINTF(idc_dbg_str);
#endif

	// send msg to EL2 that LTE_TX is Allowed
	msg_send_inline6(DRV_IDC_HISR_ID, idc_port.owner_id, DRIVER_PS_SAP | INLINE_ILM_FLAG_SAP, MSG_ID_IDC_RX_DATA, (void *) &tmp, sizeof(IDC_ILM_MSG_T));
	EINT_UnMask(TDM_REQ_HI_EINT_NO); 
}

void drv_idc_init_gpio(void)
{
	EINT_Mask(TDM_REQ_HI_EINT_NO); // disable TDM_REQ_HI interrupt
	EINT_Mask(TDM_REQ_LO_EINT_NO); // disable TDM_REQ_LO interrupt

	// Level trigger
	EINT_Set_Sensitivity(TDM_REQ_HI_EINT_NO, KAL_FALSE);
	EINT_Set_Sensitivity(TDM_REQ_LO_EINT_NO, KAL_FALSE);

	EINT_Set_HW_Debounce(TDM_REQ_HI_EINT_NO, 0);
	EINT_Set_HW_Debounce(TDM_REQ_LO_EINT_NO, 0);

#if !defined(ATEST_DRV_ENABLE)
	dhl_trace(TRACE_INFO, 0, IDC_TDM_INIT_MSG);
#else
	kal_sprintf(idc_dbg_str, "drv_idc: TDM_REQ Init\n\r");
	DT_IDC_PRINTF(idc_dbg_str);
#endif

	EINT_Registration_and_mask(TDM_REQ_HI_EINT_NO, KAL_TRUE, 1, TDM_REQ_HI_Entry, KAL_FALSE);
	EINT_Registration_and_mask(TDM_REQ_LO_EINT_NO, KAL_TRUE, 0, TDM_REQ_LO_Entry, KAL_FALSE);

	EINT_UnMask(TDM_REQ_HI_EINT_NO); // enable TDM_REQ_HI interrupt
	EINT_UnMask(TDM_REQ_LO_EINT_NO); // enable TDM_REQ_LO interrupt
	
	return;
}
#endif

void drv_idc_init_uart(void)
{
#if defined(MT6290)
	DRV_WriteReg32(BASE_ADDR_MDINFRAMISC + 0x114, DRV_Reg32(BASE_ADDR_MDINFRAMISC + 0x114) | 0x6);
	DRV_WriteReg32(BASE_ADDR_MDPERIMISC + 0x114, DRV_Reg32(BASE_ADDR_MDPERIMISC + 0x114) | 0x4);
#if __FPGA__
#else
	// set GPIO as default output
	DRV_WriteReg32_NPW(BASE_ADDR_TOPMISC + 0x1D4, DRV_Reg32(BASE_ADDR_TOPMISC + 0x1D4) | 0x200);
#endif
#endif

#if defined(MT6595)
	// Enable GPIO 29, 30 pull-up/pull-down
	DRV_WriteReg32(GPIO_base + 0x110, DRV_Reg32(GPIO_base + 0x110) | 0x6000);
	// Select GPIO 29, 30 pull-up
	DRV_WriteReg32(GPIO_base + 0x210, DRV_Reg32(GPIO_base + 0x210) | 0x6000);
#endif

#if !defined(ATEST_DRV_ENABLE)
	dhl_trace(TRACE_INFO, 0, IDC_UART_INIT_MSG);
#else
	kal_sprintf(idc_dbg_str, "drv_idc: IDC UART Init\n\r");
	DT_IDC_PRINTF(idc_dbg_str);
#endif

	// register isr, enable RX data receive interrupt
	IRQMask(MD_IRQID_IDC2ARM);

	// Initialize IDC UART FIFO threshold
	drv_idc_set_fifo_trigger(1);
	DRV_WriteReg32(IDC_UART_FCR, IDC_UART_FCR_RXTRIG | IDC_UART_FCR_FIFOINI);

	DRV_WriteReg32(IDC_UART_IER, IDC_UART_IER_ERBFI);
	IRQ_Register_LISR(MD_IRQID_IDC2ARM, idc_uart_lisr, "IDC_UART");
	DRV_Register_HISR(DRV_IDC_HISR_ID, idc_uart_hisr);
	IRQSensitivity(MD_IRQID_IDC2ARM, KAL_FALSE);
	IRQClearInt(MD_IRQID_IDC2ARM);

	IRQUnmask(MD_IRQID_IDC2ARM);
	idc_port.intr_en = KAL_TRUE;

	idc_port.schedule_state[0] = IDC_PLAN;
	idc_port.schedule_state[1] = IDC_PLAN;
	idc_port.event_cnt[0] = 0;
	idc_port.event_cnt[1] = 0;
	idc_port.sram_w_ptr = 3;	// 2'b11
	idc_port.sram_usage_bit_map[0] = 0;
	idc_port.sram_usage_bit_map[1] = 0;
	idc_port.rx_buf = 0;


	// Initialize baud rate
	drv_idc_set_baudrate(4000000);

	// initial flags/config of IDC driver
	idc_port.main_state = IDC_IN_USE;

	return;
}

void drv_idc_init(void)
{
#if defined(__4G_IDC__)

#if defined(MT6290)
	if (TDM_REQ_LO_EINT_NO == EINT_CHANNEL_NOT_EXIST) // EINT variables are not defined in codegen.dws
		drv_idc_init_uart();
	else	// For 82LTE, 92LTE 
		drv_idc_init_gpio();
#else	// For non MT6290 chips which use IDC (e.g., ROME, K2, ...).
	drv_idc_init_uart();
#endif

#else	// #if !defined(__4G_IDC__)
	//IDC should not be initialized if __4G_IDC__ was not defined
	ASSERT(0);
#endif

	return;
}

void drv_idc_get_support(IDC_SUPPORT_T *support)
{
#if defined(__4G_IDC__)
	support->idc = KAL_TRUE;

#if defined(MT6290)
	if (TDM_REQ_LO_EINT_NO == EINT_CHANNEL_NOT_EXIST) // EINT variables are not defined in codegen.dws
	{
		support->gpio = KAL_FALSE;
		support->uart = KAL_TRUE;
	}
	else	// For 82LTE, 92LTE 
	{
		support->gpio = KAL_TRUE;
		support->uart = KAL_FALSE;
	}
#else
	support->gpio = KAL_FALSE;
	support->uart = KAL_TRUE;
#endif

#else // !defined(__4G_IDC__)
	support->idc = KAL_FALSE;
	support->gpio = KAL_FALSE;
	support->uart = KAL_FALSE;
#endif

	return;
}

void drv_idc_open(kal_uint32 mod_id)
{
	idc_port.owner_id = mod_id;
	idc_port.main_state = IDC_OPEN;

	return;
}

void drv_idc_close()
{

	// stop all events before closing IDC
	DRV_WriteReg32(IDC_BSI_SCH_STOP_3100, 0xFFFFFFFF);
	DRV_WriteReg32(IDC_BSI_SCH_STOP_6332, 0xFFFFFFFF & ~0xFC000000);

	// disable interrupt
	IRQMask(MD_IRQID_IDC2ARM);
	DRV_WriteReg8(IDC_UART_IER, IDC_UART_IER_ALLOFF);
	IRQUnmask(MD_IRQID_IDC2ARM);

	idc_port.intr_en = KAL_FALSE;
	idc_port.rx_buf = 0;

	// clear start/finish priority register
	// clear start/finish priority bit enable register
	// clear start/finish pattern register
	// clear start/finish pattern bit enable register
	DRV_WriteReg32(IDC_UART_START_PRI, 0);
	DRV_WriteReg32(IDC_UART_START_PRI_BITEN, 0);
	DRV_WriteReg32(IDC_UART_START_PAT, 0);
	DRV_WriteReg32(IDC_UART_START_PAT_BITEN, 0);
	DRV_WriteReg32(IDC_UART_FINISH_PRI, 0);
	DRV_WriteReg32(IDC_UART_FINISH_PRI_BITEN, 0);
	DRV_WriteReg32(IDC_UART_FINISH_PAT, 0);
	DRV_WriteReg32(IDC_UART_FINISH_PAT_BITEN, 0);

	idc_port.schedule_state[0] = IDC_PLAN;
	idc_port.schedule_state[1] = IDC_PLAN;
	idc_port.event_cnt[0] = 0;
	idc_port.event_cnt[1] = 0;
	idc_port.sram_usage_bit_map[0] = 0;
	idc_port.sram_usage_bit_map[1] = 0;
	idc_port.rx_buf = 0;

	idc_port.owner_id = 0;
	idc_port.main_state = IDC_CLOSED;

	return;
}

void drv_idc_set_dcb_config(IDC_CTRL_DCB_CONFIG_T idc_config)
{
	kal_uint8 tmp_lcr, tmp_ier;

	IRQMask(MD_IRQID_IDC2ARM);
	tmp_ier = DRV_Reg8(IDC_UART_IER);
	DRV_WriteReg8(IDC_UART_IER, IDC_UART_IER_ALLOFF);
	IRQUnmask(MD_IRQID_IDC2ARM);

	// set baud rate
	drv_idc_set_baudrate(idc_config.u4Baud);

	tmp_lcr = DRV_Reg32(IDC_UART_LCR);
	tmp_lcr &= ~0x3F;
	// set number of bits per character
	switch(idc_config.u1DataBits)
	{
		case len_5:
			tmp_lcr |= IDC_UART_WLS_5;
			break;
		case len_6:
			tmp_lcr |= IDC_UART_WLS_6;
			break;
		case len_7:
			tmp_lcr |= IDC_UART_WLS_7;
			break;
		case len_8:
			tmp_lcr |= IDC_UART_WLS_8;
			break;
		default:
			break;
	}

	switch(idc_config.u1StopBits)
	{
		case sb_1:
			tmp_lcr |= IDC_UART_1_STOP;
			break;
		case sb_2:
			tmp_lcr |= IDC_UART_2_STOP;
			break;
		case sb_1_5:
			tmp_lcr |= IDC_UART_1_5_STOP;
			break;
		default:
			break;
	}

	switch(idc_config.u1Parity)
	{
		case pa_none:
			tmp_lcr |= IDC_UART_NONE_PARITY;
			break;
		case pa_odd:
			tmp_lcr |= IDC_UART_ODD_PARITY;
			break;
		case pa_even:
			tmp_lcr |= IDC_UART_EVEN_PARITY;
			break;
		default:
			break;
	}

	DRV_WriteReg32(IDC_UART_LCR, tmp_lcr);

	kal_mem_cpy((void *) &idc_port.DCB, (void *) &idc_config, sizeof(IDC_CTRL_DCB_CONFIG_T));
   
	IRQMask(MD_IRQID_IDC2ARM);
	DRV_WriteReg8(IDC_UART_IER, tmp_ier);
	IRQUnmask(MD_IRQID_IDC2ARM);
}


void drv_idc_get_dcb_config(IDC_CTRL_DCB_CONFIG_T *DCB)
{
	kal_mem_cpy((void *) DCB, (void *) &idc_port.DCB, sizeof(IDC_CTRL_DCB_CONFIG_T));

	return;
}

void drv_idc_set_baudrate(kal_uint32 baudrate)
{
	kal_uint8 tmp_lcr = 0;
	kal_uint32 freq_div = 1;
	kal_uint32 sample_count = 0;

	idc_port.DCB.u4Baud = baudrate;

	if(baudrate)
	{
		do {
			sample_count = (BUS_CLOCK + (freq_div * baudrate / 2)) / (freq_div * baudrate);
			if(sample_count > 0xff) freq_div++;
		} while(sample_count > 0xff);
	}

	// configure register
	// based on sample_count * baud_pulse, baud_rate = system clock frequency / (SAMPLE_COUNT + 1) / {DLM, DLL}
	DRV_WriteReg32(IDC_UART_RATE_STEP, ID_UART_RATE_STEP_COUNT);

	tmp_lcr = DRV_Reg32(IDC_UART_LCR);
	DRV_WriteReg32(IDC_UART_LCR, tmp_lcr | IDC_UART_LCR_DLAB);
	// -- DLAB start --

	DRV_WriteReg32(IDC_UART_DLL, freq_div & 0xFF);
	DRV_WriteReg32(IDC_UART_DLM, (freq_div >> 8) & 0xFF);

	DRV_WriteReg32(IDC_UART_STEP_COUNT, sample_count - 1);
	DRV_WriteReg32(IDC_UART_SAMPLE_COUNT, sample_count >> 1);

	DRV_WriteReg32(IDC_UART_LCR, tmp_lcr);
	// -- DLAB end --
}


void drv_idc_set_fifo_trigger(kal_uint8 rx_threshold)
{
	DRV_WriteReg32(IDC_UART_RXTRIG, rx_threshold);
	return;
}

void drv_idc_set_pm_config(kal_bool start, kal_uint8 priority, kal_uint8 priority_bit_en, kal_uint8 pattern, kal_uint8 pattern_bit_en)
{
	switch(start)
	{
		case KAL_FALSE:
			DRV_WriteReg32(IDC_UART_FINISH_PRI, priority);
			DRV_WriteReg32(IDC_UART_FINISH_PRI_BITEN, priority_bit_en);
			DRV_WriteReg32(IDC_UART_FINISH_PAT, pattern);
			DRV_WriteReg32(IDC_UART_FINISH_PAT_BITEN, pattern_bit_en);
			break;
		case KAL_TRUE:
			DRV_WriteReg32(IDC_UART_START_PRI, priority);
			DRV_WriteReg32(IDC_UART_START_PRI_BITEN, priority_bit_en);
			DRV_WriteReg32(IDC_UART_START_PAT, pattern);
			DRV_WriteReg32(IDC_UART_START_PAT_BITEN, pattern_bit_en);
			break;
		default:
			ASSERT(0);
			break;
	}
	
	return;
}

void drv_idc_get_pm_config(kal_bool start, kal_uint8 *priority, kal_uint8 *priority_bit_en, kal_uint8 *pattern, kal_uint8 *pattern_bit_en)
{
	switch(start)
	{
		case KAL_FALSE:
			*priority = DRV_Reg8(IDC_UART_FINISH_PRI);
			*priority_bit_en = DRV_Reg8(IDC_UART_FINISH_PRI_BITEN);
			*pattern = DRV_Reg8(IDC_UART_FINISH_PAT);
			*pattern_bit_en = DRV_Reg8(IDC_UART_FINISH_PAT_BITEN);
			break;
		case KAL_TRUE:
			*priority = DRV_Reg8(IDC_UART_START_PRI);
			*priority_bit_en = DRV_Reg8(IDC_UART_START_PRI_BITEN);
			*pattern = DRV_Reg8(IDC_UART_START_PAT);
			*pattern_bit_en = DRV_Reg8(IDC_UART_START_PAT_BITEN);
			break;
		default:
			ASSERT(0);
			break;
	}

	return;
}

void drv_idc_schedule_event(kal_uint8 schedule_num, kal_uint8 num_event, IDC_EVENT_T *event)
{
	kal_uint32 i = 0;
	kal_uint32 sram_usage_status = 0;
	kal_uint32 sram_address = 0;

	if(schedule_num > 1) ASSERT(0);

	dhl_trace(TRACE_INFO, 0, IDC_SCHEDULE_0_MSG, schedule_num, num_event);
	drv_idc_check_event_send_out();

	for(i = 0; i < 2; i++)
	{
		if(idc_port.schedule_state[i] == IDC_RUN)
		{
			if(i == schedule_num)
			{
				// stop all events of specific schedudler, clear event cnt, sram usage bit map
				drv_idc_stop_event(i, 0xFFFFFFFF);
				idc_port.event_cnt[i] = 0;
				idc_port.sram_usage_bit_map[i] = 0;

				// set sceduler state as PLAN
				idc_port.schedule_state[i] = IDC_PLAN;
			} else
			{
				// stop all events of specific schedudler, clear event cnt, sram usage bit map
				if(DRV_Reg32(IDC_BSI_SCH_STATUS(i)) == 0)
				{
					idc_port.event_cnt[i] = 0;
					idc_port.sram_usage_bit_map[i] = 0;

					// set sceduler state as PLAN
					idc_port.schedule_state[i] = IDC_PLAN;
				}
			}
		}
	}

	for(i = 0; i < num_event; i++)
	{
		sram_usage_status = idc_port.sram_usage_bit_map[0] | idc_port.sram_usage_bit_map[1];
		if(sram_usage_status == 0xFFFFFFFF)
		{
			//DT_IDC_PRINTF("[%s:%d] sram is full\n\r", __FUNCTION__, __LINE__);
			ASSERT(0);
		}

		// find the room of sram for storing data
		while(1)
		{
			if(idc_port.sram_w_ptr & sram_usage_status)
			{
				idc_port.sram_w_ptr = idc_port.sram_w_ptr << 2;
				if(idc_port.sram_w_ptr == 0) idc_port.sram_w_ptr = 3;
			} else
			{
				break;
			}
		}

		// config event
		// idc_set_time_stamps_para_data_info_ind_buf
		DRV_WriteReg32(IDC_BSI_IND_ADDR, IDC_BSI_SCH_EVT_CON((schedule_num << 5) + idc_port.event_cnt[schedule_num]));

		sram_address = drv_idc_convert_w_bitmap_ptr_2_address(idc_port.sram_w_ptr);
		DRV_WriteReg32(IDC_BSI_IND_DATA, IDC_BSI_SCH_EVT_CON_STP_STA_ADDR(sram_address + 1, sram_address));
		DRV_WriteReg32(IDC_BSI_IND_DATA, IDC_BSI_SCH_EVT_CON2_SCHE(schedule_num));
		DRV_WriteReg32(IDC_BSI_IND_DATA, event[i].offset * PHY_CLOCK_MHZ * 2 / BUS_CLOCK_MHZ);

		//dhl_trace(TRACE_INFO, 0, IDC_SCHEDULE_0_MSG, event[i].offset);

		// idc_set_data_into_ind_buf_sram
		DRV_WriteReg32(IDC_BSI_IND_ADDR, IDC_BSI_SCH_DATA_L(sram_address));

		DRV_WriteReg32(IDC_BSI_IND_DATA, event[i].data[0]);
		DRV_WriteReg32(IDC_BSI_IND_DATA, 0);
		DRV_WriteReg32(IDC_BSI_IND_DATA, 0);
		DRV_WriteReg32(IDC_BSI_IND_DATA, 1);

		DRV_WriteReg32(IDC_BSI_IND_DATA, event[i].data[1]);
		DRV_WriteReg32(IDC_BSI_IND_DATA, 0);
		DRV_WriteReg32(IDC_BSI_IND_DATA, 0);
		DRV_WriteReg32(IDC_BSI_IND_DATA, 1);

		idc_port.event_cnt[schedule_num]++;
		idc_port.sram_usage_bit_map[schedule_num] |= idc_port.sram_w_ptr;
		idc_port.sram_w_ptr = idc_port.sram_w_ptr << 2;
		if(idc_port.sram_w_ptr == 0) idc_port.sram_w_ptr = 3;
	}

	return;
}

kal_uint8 drv_idc_convert_w_bitmap_ptr_2_address(kal_uint32 bitmap)
{
	kal_uint8 return_value = 0;
	kal_uint32 bit_num = 32;

	while(1)
	{
		bit_num = bit_num >> 1;
		if(bit_num == 1) break;

		if(bitmap < (1 << bit_num)) 
		{
			return_value = (return_value << 1);
		} else
		{
			bitmap = bitmap >> bit_num;
			return_value = (return_value << 1) | 1;
		}
	}

	return return_value << 1;
}

void drv_idc_schedule_start(kal_uint8 schedule_num, kal_uint32 time_base)
{
	if(schedule_num > 1) ASSERT(0);

	if (idc_port.event_cnt[schedule_num] != 0)
	{
		dhl_trace(TRACE_INFO, 0, IDC_SCHEDULE_START_MSG, schedule_num, time_base);
	}

	if(idc_port.schedule_state[schedule_num] == IDC_RUN)
	{
		// stop all events of specific schedudler, clear event cnt, sram usage bit map
		drv_idc_stop_event(schedule_num, 0xFFFFFFFF);
	}

	// set TX global offset with PHY timer value that TX offset timer will start to togle
	DRV_WriteReg32(IDC_BSI_TX_GLO_OS(schedule_num), time_base);

	// turn on required events
	DRV_WriteReg32(IDC_BSI_SCH_START(schedule_num), 0xFFFFFFFF >> (32 - idc_port.event_cnt[schedule_num]));

	idc_port.schedule_state[schedule_num] = IDC_RUN;
	idc_port.event_cnt[schedule_num] = 0;

	return;
}

void drv_idc_stop_event(kal_uint8 schedule_num, kal_uint32 bitmap)
{
	switch(schedule_num)
	{
		case 0:
			DRV_WriteReg32(IDC_BSI_SCH_STOP_3100, bitmap);
			break;
		case 1:
			DRV_WriteReg32(IDC_BSI_SCH_STOP_6332, bitmap & ~0xFC000000); // 59 ~ 63 is reserved for POR
			break;
		default:
			ASSERT(0);
			break;
	}

	return;
}

void drv_idc_purge(UART_buffer dir)
{
	if(dir == TX_BUF)
		DRV_WriteReg32(IDC_UART_FCR, IDC_UART_FCR_RXTRIG | IDC_UART_FCR_CLRT | IDC_UART_FCR_FIFOEN);
	else
		DRV_WriteReg32(IDC_UART_FCR, IDC_UART_FCR_RXTRIG | IDC_UART_FCR_CLRR | IDC_UART_FCR_FIFOEN);
}

void drv_idc_get_schedule_status(kal_uint32 *schedule_status)
{
	schedule_status[0] = DRV_Reg32(IDC_BSI_SCH_STATUS_3100);
	schedule_status[1] = DRV_Reg32(IDC_BSI_SCH_STATUS_6332) & ~0xFC000000; // 58 ~ 63 is reserved for other utility

	dhl_trace(TRACE_INFO, 0, IDC_SCHEDULE_STATUS_MSG, schedule_status[0], schedule_status[1]);

	return;
}

kal_bool drv_idc_check_event_send_out(void)
{
	kal_uint32 schedule_status[2];

	// check that schedule is busy or not
	drv_idc_get_schedule_status(schedule_status);
	if(schedule_status[0] | schedule_status[1]) return KAL_FALSE;

	// check that IDC FIFO has data or not
	if(DRV_Reg32(IDC_UART_LSR) & IDC_UART_LSR_TEMT) return KAL_TRUE;

	return KAL_FALSE;
}

DCL_STATUS drv_idc_set_pin_config(IDC_PIN_MODE_T pin_mode)
{
	DCL_STATUS return_value = STATUS_FAIL;

#if defined(MT6752)
	// IRQMask to prevent unexpected interrupt
	IRQMask(MD_IRQID_IDC2ARM);

	if (pin_mode == IDC_INTERNAL_PIN)
	{
		#if !defined(ATEST_DRV_ENABLE)
		dhl_trace(TRACE_INFO, 0, IDC_INTERNAL_PIN_MSG);
		#else
		kal_sprintf(idc_dbg_str, "drv_idc: Switch to internal pins\n\r");
		DT_IDC_PRINTF(idc_dbg_str);
		#endif
		
		idc_port.pin_mode = IDC_INTERNAL_PIN;

		// Switch to internal pins
		DRV_WriteReg32(GPIO_base + 0x500, DRV_Reg32(GPIO_base+ 0x500) & ~(0x10));

		return_value = STATUS_OK;
	}
	else if (pin_mode == IDC_EXTERNAL_PIN)
	{
		#if !defined(ATEST_DRV_ENABLE)
		dhl_trace(TRACE_INFO, 0, IDC_EXTERNAL_PIN_MSG);
		#else
		kal_sprintf(idc_dbg_str, "drv_idc: Switch to external pins\n\r");
		DT_IDC_PRINTF(idc_dbg_str);
		#endif

		idc_port.pin_mode = IDC_EXTERNAL_PIN;

		// Switch to external pins
		DRV_WriteReg32(GPIO_base + 0x500, DRV_Reg32(GPIO_base+ 0x500) | 0x10);

		// Enable GPIO37 (PTA_TX) pull-up/pull-down
		DRV_WriteReg32(IOCFG_L_BASE+0xA0, DRV_Reg32(IOCFG_L_BASE+0xA0) | 0x20);
		// Select GPIO37 (PTA_TX) pull-up
		DRV_WriteReg32(IOCFG_L_BASE+0xD0, DRV_Reg32(IOCFG_L_BASE+0xD0) | 0x20);

		// Enable GPIO130 (PTA_RX) pull-up/pull-down
		DRV_WriteReg32(IOCFG_L_BASE+0x90, DRV_Reg32(IOCFG_L_BASE+0x90) | 0x40000);
		// Select GPIO130 (PTA_RX) pull-up
		DRV_WriteReg32(IOCFG_L_BASE+0xC0, DRV_Reg32(IOCFG_L_BASE+0xC0) | 0x40000);

		return_value = STATUS_OK;
	}

	// Clear TX/RX FIFO
	DRV_WriteReg32(IDC_UART_FCR, IDC_UART_FCR_RXTRIG | IDC_UART_FCR_FIFOINI);

	IRQClearInt(MD_IRQID_IDC2ARM);
	IRQUnmask(MD_IRQID_IDC2ARM);
#endif

	return return_value;
}

DCL_STATUS drv_idc_get_pin_config(IDC_PIN_MODE_T *pin_mode)
{
	DCL_STATUS return_value = STATUS_FAIL;

#if defined(MT6752)
	*pin_mode = idc_port.pin_mode;
	return_value = STATUS_OK;
#endif

	return return_value;
}

void idc_uart_lisr(kal_uint32 vector)
{
	IRQMask(MD_IRQID_IDC2ARM);

	drv_active_hisr((kal_uint8) DRV_IDC_HISR_ID);

	return;
}

void idc_uart_hisr(void)
{
	kal_uint16 IIR, LSR, RXTRIG;

	IIR = DRV_Reg(IDC_UART_IIR);
	LSR = DRV_Reg(IDC_UART_LSR);
	RXTRIG = DRV_Reg(IDC_UART_RXTRIG);

	if (IIR & IDC_UART_IIR_INT_INVALID)
	{
		IRQClearInt(MD_IRQID_IDC2ARM);
		#if !defined(__UNIFIED_ISR_LEVEL__)
		IRQUnmask(MD_IRQID_IDC2ARM);
		#endif

		return;
	}

	idc_hisr_time[idc_hisr_count] = DRV_Reg32(FRC_VAL_R);
	idc_hisr_count++;
	if (idc_hisr_count == 20)
	{
		idc_hisr_count = 0;
	}

	idc_send_rx_data_by_ilm();
	
	if (KAL_FALSE == idc_read_RBR)
	{
		#if !defined(ATEST_DRV_ENABLE)
		dhl_trace(TRACE_ERROR, 0, IDC_RX_HISR_MSG, IIR, LSR, RXTRIG, idc_port.main_state, idc_port.owner_id, idc_port.intr_en);
		#else
		kal_sprintf(idc_dbg_str, "drv_idc: HISR without Read Data, IIR = %x, LSR = %x, RXTRIG = %x, (%d, %d, %d)\n\r", 
			IIR, LSR, RXTRIG, idc_port.main_state, idc_port.owner_id, idc_port.intr_en);
		DT_IDC_PRINTF(idc_dbg_str);
		#endif

		ASSERT(0);
	}
	else if (((LSR & 0x9F) != 0x1) || (IIR != 0xc4))
	{
		#if !defined(ATEST_DRV_ENABLE)
		dhl_trace(TRACE_ERROR, 0, IDC_RX_EXCEPTION_MSG, IIR, LSR, RXTRIG, idc_port.main_state, idc_port.owner_id, idc_port.intr_en);
		#else
		kal_sprintf(idc_dbg_str, "drv_idc: Exception occur, IIR = %x, LSR = %x, RXTRIG = %x, (%d, %d, %d)\n\r",
			IIR, LSR, RXTRIG, idc_port.main_state, idc_port.owner_id, idc_port.intr_en);
		DT_IDC_PRINTF(idc_dbg_str);
		#endif
	}
	else if (RXTRIG == 0);
	
	idc_read_RBR = KAL_FALSE;

	IRQClearInt(MD_IRQID_IDC2ARM);
	#if !defined(__UNIFIED_ISR_LEVEL__)
	IRQUnmask(MD_IRQID_IDC2ARM);
	#endif
	return;
}

void idc_send_rx_data_by_ilm(void)
{
	while(DRV_Reg(IDC_UART_LSR) & IDC_UART_LSR_DR)
	{
		// read bytes from IDC UART FIFO to SW buffer
		idc_port.rx_buf = (idc_port.rx_buf << 16) | (1 << 8) | DRV_Reg8(IDC_UART_RBR);
		idc_read_RBR = KAL_TRUE;

		idc_rx_history[idc_rx_count] = (kal_uint8)(idc_port.rx_buf & 0xFF);
		idc_rx_history_time[idc_rx_count] = DRV_Reg32(FRC_VAL_R);
		
		idc_rx_count++;
		if (idc_rx_count == 20)
		{
			idc_rx_count = 0;
			#if !defined(ATEST_DRV_ENABLE)
			dhl_trace(TRACE_INFO, 0, IDC_RX_HISTORY_MSG,
				idc_rx_history[0], idc_rx_history[1], idc_rx_history[2], idc_rx_history[3], idc_rx_history[4],
				idc_rx_history[5], idc_rx_history[6], idc_rx_history[7], idc_rx_history[8], idc_rx_history[9],
				idc_rx_history[10], idc_rx_history[11], idc_rx_history[12], idc_rx_history[13], idc_rx_history[14],
				idc_rx_history[15], idc_rx_history[16], idc_rx_history[17], idc_rx_history[18], idc_rx_history[19]
				);
			#else
			kal_sprintf(idc_dbg_str, "drv_idc: Receive %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x\n\r", 
				idc_rx_history[0], idc_rx_history[1], idc_rx_history[2], idc_rx_history[3], idc_rx_history[4],
				idc_rx_history[5], idc_rx_history[6], idc_rx_history[7], idc_rx_history[8], idc_rx_history[9],
				idc_rx_history[10], idc_rx_history[11], idc_rx_history[12], idc_rx_history[13], idc_rx_history[14],
				idc_rx_history[15], idc_rx_history[16], idc_rx_history[17], idc_rx_history[18], idc_rx_history[19]
				);
			DT_IDC_PRINTF(idc_dbg_str);
			#endif
		}

		// if there are two-byte data in fifo and data is valid, send them by ilm
		if((idc_port.rx_buf & 0x01010101) == 0x01000101)
		{
			IDC_ILM_MSG_T tmp;
			tmp.type  = (idc_port.rx_buf & 0x001E0000) >> 17;
			tmp.msg = ((idc_port.rx_buf & 0x00E00000) >> 21) | ((idc_port.rx_buf & 0x000000FE) << 2);
			//DT_IDC_PRINTF("%x %x\n\r", tmp.type, tmp.msg);
			if (tmp.type == 0)
                        {
                                if (KAL_TRUE == idc_count_start)
				{
                                        idc_80211_rx_count++;
					dhl_trace(TRACE_INFO, 0, IDC_RX_80211_RX_MSG, tmp.type, tmp.msg);
				}
                        }
                        else if (tmp.type == 1)
                        {
                                if (KAL_TRUE == idc_count_start)
                                {
					idc_80211_tx_count++;
					dhl_trace(TRACE_INFO, 0, IDC_RX_80211_TX_MSG, tmp.type, tmp.msg);
				}
                        }
			else
			{
			#if !defined(ATEST_DRV_ENABLE)
				dhl_trace(TRACE_INFO, 0, IDC_RX_SEND_ILM_MSG, idc_port.rx_buf, tmp.type, tmp.msg);
			#else
				kal_sprintf(idc_dbg_str, "drv_idc: MSG Send to EL1: %x, type:%x, msg:%x\n\r", idc_port.rx_buf, tmp.type, tmp.msg);
				DT_IDC_PRINTF(idc_dbg_str);
			#endif
				msg_send_inline6(MOD_DRV_HISR, idc_port.owner_id, DRIVER_PS_SAP | INLINE_ILM_FLAG_SAP, MSG_ID_IDC_RX_DATA, (void *) &tmp, sizeof(IDC_ILM_MSG_T));
			}

			idc_port.rx_buf = 0;
		}
	}

	return;
}
