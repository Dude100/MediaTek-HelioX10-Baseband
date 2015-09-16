#if !defined(__IDC_TRACE_H__)
#define __IDC_TRACE_H__

#if !defined(GEN_FOR_PC)
#include "kal_public_defs.h"
#endif

#include "dhl_trace.h"

#if !defined(GEN_FOR_PC)
#if defined (__DHL_MODULE__) || defined(__CUSTOM_RELEASE__)
	#include "idc_trace_gen.h"
#endif
#endif

BEGIN_TRACE_MAP(MOD_IDC)
	TRC_MSG(IDC_START_COUNT_MSG, 	"[DRV_IDC] Start counting CONNSYS TX/RX")
	TRC_MSG(IDC_END_COUNT_MSG, 	"[DRV_IDC] End counting CONNSYS TX/RX (%d/%d)")
	TRC_MSG(IDC_TDM_HI_MSG, 	"[DRV_IDC] TDM_REQ_HI_Entry")
	TRC_MSG(IDC_TDM_LO_MSG, 	"[DRV_IDC] TDM_REQ_LO_Entry")
	TRC_MSG(IDC_TDM_INIT_MSG, 	"[DRV_IDC] TDM_REQ Init")
	TRC_MSG(IDC_UART_INIT_MSG, 	"[DRV_IDC] IDC UART Init")
	TRC_MSG(IDC_SCHEDULE_0_MSG, 	"[DRV_IDC] Schedule Event, schedule_num %d, num_event %d")
	TRC_MSG(IDC_SCHEDULE_1_MSG, 	"[DRV_IDC] Schedule Offset = %d")
	TRC_MSG(IDC_SCHEDULE_START_MSG,	"[DRV_IDC] Start Schedule %d 0x%x")
	TRC_MSG(IDC_SCHEDULE_STATUS_MSG,"[DRV_IDC] Get Schedule Status 0x%x 0x%x")
	TRC_MSG(IDC_INTERNAL_PIN_MSG, 	"[DRV_IDC] Switch to internal pins")
	TRC_MSG(IDC_EXTERNAL_PIN_MSG, 	"[DRV_IDC] Switch to external pins")
	TRC_MSG(IDC_RX_HISR_MSG, 	"[DRV_IDC] HISR without Read Data, IIR = %x, LSR = %x, RXTRIG = %x, (%d, %d, %d)")
	TRC_MSG(IDC_RX_EXCEPTION_MSG, 	"[DRV_IDC] Exception occur, IIR = %x, LSR = %x, RXTRIG = %x, (%d, %d, %d)")
	TRC_MSG(IDC_RX_HISTORY_MSG, 	"[DRV_IDC] Receive %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x")
	TRC_MSG(IDC_RX_80211_RX_MSG,	"[DRV_IDC] Receive 802_11_RX %x %x")
	TRC_MSG(IDC_RX_80211_TX_MSG,	"[DRV_IDC] Receive 802_11_TX %x %x")
	TRC_MSG(IDC_RX_SEND_ILM_MSG,	"[DRV_IDC] MSG Send to EL1: %x, type:%x, msg:%x")
END_TRACE_MAP(MOD_IDC)

#endif  /* !__IDC_TRACE_H__ */
