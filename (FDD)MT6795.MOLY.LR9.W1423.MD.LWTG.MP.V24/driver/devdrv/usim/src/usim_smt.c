#include "kal_public_api.h"
#include "drv_comm.h"
#include "reg_base.h"

#include "sim_hw_mtk.h"
#include "sim_drv_HW_def_MTK.h"
#include "sim_al.h"
#include "sim_drv_SW_struct.h"
#include "sim_drv_SW_API.h"

#include "drv_rstctl.h"
#include "drvpdn.h"
#include "drv_gdma.h"

#define	USIM_ATRSTA_OFF	0x0001

#define USIM_3_3V KAL_TRUE
#ifdef USIM_3_3V
#define	USIM_VOL_CFG	0x1
#else
#define	USIM_VOL_CFG	0x0
#endif

#define	USIM_SMT_NO_ERROR	0x0
#define	USIM_SMT_NO_TS		0x1
#define	USIM_SMT_NO_TOUT	0x2
#define	USIM_SMT_NO_T0END	0x3
#define	USIM_SMT_NO_ATRSTA_OFF	0x4
#define	USIM_SMT_SW_ERROR	0x5
#define	USIM_SMT_COUNT_ERROR	0x6
#define	USIM_SMT_HDMA_ERROR	0x7
#define USIM_SMT_IFCLR_ERROR	0x8
#define USIM_SMT_PPS_ERROR	0x9

// macro
#if defined(MT6595)
#define	USIM_SMT_UPDATE_USIM_IF_FLAG(_if) {					\
	if((_if) == 0)								\
	{									\
		usim_base = SIM_base;						\
		PDN_CLR(PDN_USIM1);						\
		HDMA_PDN_CLR(0);						\
		DRV_WriteReg32(REG_SIM1_PU_PD_SEL, (((SIMx_PD_SEL | SIMx_PU_PD_50K) << SIMx_RST) | (((!SIMx_PD_SEL) | SIMx_PU_PD_50K) << SIMx_DAT) | ((SIMx_PD_SEL | SIMx_PU_PD_50K) << SIMx_CLK))); \
	} else if((_if) == 1)							\
	{									\
		usim_base = SIM2_base;						\
		PDN_CLR(PDN_USIM2);						\
		HDMA_PDN_CLR(1);						\
		DRV_WriteReg32(REG_SIM2_PU_PD_SEL, (((SIMx_PD_SEL | SIMx_PU_PD_50K) << SIMx_RST) | (((!SIMx_PD_SEL) | SIMx_PU_PD_50K) << SIMx_DAT) | ((SIMx_PD_SEL | SIMx_PU_PD_50K) << SIMx_CLK))); \
	} else ASSERT(0);							\
	usim_iftest_sw_reset_usim((_if));					\
} while(0);
#else
#define	USIM_SMT_UPDATE_USIM_IF_FLAG(_if) {					\
	if((_if) == 0)								\
	{									\
		usim_base = SIM_base;						\
		PDN_CLR(PDN_USIM1);						\
		HDMA_PDN_CLR(0);						\
	} else if((_if) == 1)							\
	{									\
		usim_base = SIM2_base;						\
		PDN_CLR(PDN_USIM2);						\
		HDMA_PDN_CLR(1);						\
	} else ASSERT(0);							\
	usim_iftest_sw_reset_usim((_if));					\
} while(0);
#endif

#ifdef __FPGA__
#define	USIM_SMT_DEACTIVATION(_if)	{		\
	DRV_Reg32(usim_base + SIM_CTRL_MTK) = (DRV_Reg32(usim_base + SIM_CTRL_MTK) & (~SIM_CTRL_SIMON)); \
} while(0);
#else
#define	USIM_SMT_DEACTIVATION(_if)	{		\
	DRV_WriteReg32((usim_base + SIM_IRQEN_MTK), SIM_IRQEN_ALLOFF); \
	DRV_WriteReg32((usim_base + SIM_CTRL_MTK), DRV_Reg32(usim_base + SIM_CTRL_MTK) | SIM_CTRL_IFCLR); \
	DRV_Reg32(usim_base + SIM_CTRL_MTK) = (DRV_Reg32(usim_base + SIM_CTRL_MTK) & (~SIM_CTRL_SIMON)); \
	DRV_ICC_PMU_switch((_if), KAL_FALSE);	\
} while(0);
#endif

extern kal_uint32    sim_uncachedTxBuffer0[], sim_uncachedRxBuffer0[], sim_uncachedTxBuffer1[], sim_uncachedRxBuffer1[];

int usim_iftest_for_smt(kal_uint32 hwInterfaceNo);
void usim_iftest_sw_reset_usim(kal_uint32 hwInterfaceNo);

extern kal_char sim_dbg_str[];

int usim_iftest_for_smt(kal_uint32 hwInterfaceNo)
{
	kal_uint32 usim_base = 0;
	kal_uint8 atr_bytes[50];
	kal_uint8 ins[7] = {0xA0, 0xA4, 0x00, 0x00, 0x02, 0x2F, 0xE2};
	kal_uint8 *atr_ptr = atr_bytes + 1;
	kal_uint32 sw1, sw2;
	kal_uint32 i = 0, j = 0;
	kal_uint32 length = 0;

	kal_uint32 PPS_buf[5], cksum = 0xFF, need_PPS = 0, Fi = 0, Di = 0;

	kal_uint32 status, data;

	// 0. Update USIM interface flag
	USIM_SMT_UPDATE_USIM_IF_FLAG(hwInterfaceNo);

	// 1. get ATR STR
#ifdef __FPGA__
#else
	// 1.0 Deactivate SIM
	DRV_ICC_PMU_switch(hwInterfaceNo, KAL_FALSE);
#endif
	DRV_Reg32(usim_base + SIM_BRR_MTK) = (DRV_Reg32(usim_base + SIM_BRR_MTK) & 0x3) | (372 << 2);
	DRV_Reg32(usim_base + SIM_CONF_MTK) = DRV_Reg32(usim_base + SIM_CONF_MTK) & ~(SIM_CONF_TOUTEN);
	DRV_Reg32(usim_base + SIM_CTRL_MTK) = DRV_Reg32(usim_base + SIM_CTRL_MTK) & ~(SIM_CTRL_SIMON);

	// 1.1 Set RXTIDE of SIM_TIDE to 0 and TXTIDE to 1
	DRV_Reg32(usim_base + SIM_TIDE_MTK) = (DRV_Reg32(usim_base + SIM_TIDE_MTK) & (~SIM_TIDE_RXMASK) & (~SIM_TIDE_TXMASK)) | 0x0100;

	// 1.2 Clear Interrupt
	DRV_Reg32(usim_base + SIM_STS_MTK) = DRV_Reg32(usim_base + SIM_STS_MTK);

	// 1.3 If TOUT = 1, T0EN/T1EN = 0
	DRV_Reg32(usim_base + SIM_CONF_MTK) = (DRV_Reg32(usim_base + SIM_CONF_MTK) & ~(SIM_CONF_T0EN | SIM_CONF_T1EN | SIM_CONF_TOUTEN | USIM_VOL_CFG)) | (SIM_CONF_TOUTEN | USIM_VOL_CFG);
#ifdef __FPGA__
#else
   #ifdef USIM_3_3V
	DRV_ICC_PMU_setVolt(hwInterfaceNo, CLASS_B_30V);
   #else
	DRV_ICC_PMU_setVolt(hwInterfaceNo, CLASS_C_18V);
   #endif
	DRV_ICC_PMU_switch(hwInterfaceNo, KAL_TRUE);
#endif

	// 1.4 Set SIMON, Activate SIM
	DRV_Reg32(usim_base + SIM_CTRL_MTK) = (DRV_Reg32(usim_base + SIM_CTRL_MTK) & (~SIM_CTRL_SIMON)) | SIM_CTRL_SIMON;

	// 1.5 Wait first bytes of ATR
	j = 0;
	while(!DRV_Reg32(usim_base + SIM_COUNT_MTK))
	{
		if(j > 0xFFFFFF)
		{
			kal_sprintf(sim_dbg_str,"[SIM_SMT]: NO TS, %x, %d\n\r", usim_base, hwInterfaceNo);
			DRV_ICC_print_str(sim_dbg_str);
			USIM_SMT_DEACTIVATION(hwInterfaceNo);
			return USIM_SMT_NO_TS;
		}
		j++;
	}


	// 0.6 Read FIFO Count
	j = 0;
	while (1)
	{
		status = DRV_Reg32(usim_base + SIM_COUNT_MTK);
		// FIFO Non-Empty
		if(status != 0x0)
		{
			for(i = 0; i < status; i++)
			{
				data = DRV_Reg32(usim_base + SIM_DATA_MTK);
				atr_ptr[0] = data;
				atr_ptr++;
			}
		}

		// TOUT Status = 1
		if(DRV_Reg32(usim_base + SIM_STS_MTK) & SIM_STS_TOUT)
		{
			// Clear Interrupt
			DRV_Reg32(usim_base + SIM_STS_MTK) = DRV_Reg32(usim_base + SIM_STS_MTK);
			// Clear IP's Internal TOUT enable bit
			DRV_Reg32(usim_base + SIM_CONF_MTK) = DRV_Reg32(usim_base + SIM_CONF_MTK) & ~(SIM_CONF_TOUTEN);
			// End of ATR, # of ATR
			atr_bytes[0] = atr_ptr - atr_bytes - 1;
			break;
		}

		if(j > 0xFFFFFF)
		{
			USIM_SMT_DEACTIVATION(hwInterfaceNo);
			kal_sprintf(sim_dbg_str,"[SIM_SMT]: NO TOUT\n\r");
			DRV_ICC_print_str(sim_dbg_str);
			return USIM_SMT_NO_TOUT;
		}
		j++;
	}


	if(atr_bytes[3] == ATR_TA1_64)
	{
		Fi = 512;
		Di = 8;
	}
	else if(atr_bytes[3] == ATR_TA1_32)
	{
		Fi = 512;
		Di = 16;
	}
	else if(atr_bytes[3] == ATR_TA1_16)
	{
		Fi = 512;
		Di = 32;
	}
	else if(atr_bytes[3] == ATR_TA1_8)
	{
		Fi = 512;
		Di = 64;
	}

	if(atr_bytes[2] & 0x80) // Is TD1 existed ?
	{
		j = 0;
		if(atr_bytes[2] & 0x10) j++;
		if(atr_bytes[2] & 0x20) j++;
		if(atr_bytes[2] & 0x40) j++;
		if(atr_bytes[2] & 0x80) j++;

		if(atr_bytes[2+j] & 0x01) // is TA2 existed
		{
			if(!(atr_bytes[2+j+1] & 0x10) && !(atr_bytes[2+j+1] & 0x80)) need_PPS = 1;
		}
	}

	if(need_PPS || (atr_bytes[3] != 0x01 && atr_bytes[3] != 0x11 && atr_bytes[2] & 0x10))
	{


		// Set TOUT = 1
		DRV_Reg32(usim_base + SIM_CONF_MTK) = (DRV_Reg32(usim_base + SIM_CONF_MTK) & ~(SIM_CONF_TOUTEN | USIM_VOL_CFG)) | (SIM_CONF_TOUTEN | USIM_VOL_CFG);
		// Clear
		DRV_Reg32(usim_base + SIM_COMDCTRL_MTK) = DRV_Reg32(usim_base + SIM_COMDCTRL_MTK) | SIM_CTRL_IFCLR;
		j = 0;
		while(DRV_Reg32(usim_base + SIM_CONFSTA_MTK) & SIM_CONFSTA_IFCLR_ON);
		{
			if(j > 0xFFFFFF)
			{
				USIM_SMT_DEACTIVATION(hwInterfaceNo);
				kal_sprintf(sim_dbg_str,"[SIM_SMT]: IFCLR ERROR\n\r");
				DRV_ICC_print_str(sim_dbg_str);
				return USIM_SMT_IFCLR_ERROR;
			}
			j++;
		}

		// Set RXTIDE of SIM_TIDE to 0 and TXTIDE to 1
		DRV_Reg32(usim_base + SIM_TIDE_MTK) = (DRV_Reg32(usim_base + SIM_TIDE_MTK) & (~SIM_TIDE_RXMASK) & (~SIM_TIDE_TXMASK)) | 0x0100;

		j = 0;
		// Send PPSS
		DRV_Reg32(usim_base + SIM_DATA_MTK) = 0xFF;
		PPS_buf[j++] = 0xFF;

		// Send PPS0
		DRV_Reg32(usim_base + SIM_DATA_MTK) = 0x10;
		cksum ^= 0x10;
		PPS_buf[j++] = 0x10;

		// Send PPS1
		// Propose new Fi, Di
		DRV_Reg32(usim_base + SIM_DATA_MTK) = atr_bytes[3];
		cksum ^= atr_bytes[3];
		PPS_buf[j++] = atr_bytes[3];

        
		// Send PCK
		DRV_Reg32(usim_base + SIM_DATA_MTK) = cksum;
		PPS_buf[j++] = cksum;

		// Wait Until TX FIFO Empty
		j = 0;
		while(DRV_Reg32(usim_base + SIM_COUNT_MTK) != 0)
		{
			if(j > 0xFFFFFF)
			{
				USIM_SMT_DEACTIVATION(hwInterfaceNo);
				kal_sprintf(sim_dbg_str,"[SIM_SMT]: COUNT ERROR\n\r");
				DRV_ICC_print_str(sim_dbg_str);
				return USIM_SMT_COUNT_ERROR;
			}
			j++;
		}

		// PPS Exchange RX
		j = 0; data = 0;
		while(1)
		{
			status = DRV_Reg32(usim_base + SIM_COUNT_MTK);

			// FIFO Non-Empty
			if(status != 0x0)
			{
				for(i = 0; i < status; i++)
				{
					data = DRV_Reg32(usim_base + SIM_DATA_MTK);
					if(PPS_buf[j++] != data)
					{
						kal_sprintf(sim_dbg_str, "[SIM_SMT]: not consistent:%x %x\n\r", data, PPS_buf[j-1]);
						DRV_ICC_print_str(sim_dbg_str);
						USIM_SMT_DEACTIVATION(hwInterfaceNo);
						return USIM_SMT_PPS_ERROR;
					}
				}
			}	
        
			// TOUT Status = 1
			if(DRV_Reg32(usim_base + SIM_STS_MTK) & SIM_STS_TOUT)
			{
				if(data == 0)
				{
					if(DRV_Reg32(usim_base + SIM_COUNT_MTK) == 0x0)
					{
						kal_sprintf(sim_dbg_str, "[SIM_SMT]: USIM does not reply on time\n\r");
						DRV_ICC_print_str(sim_dbg_str);
						USIM_SMT_DEACTIVATION(hwInterfaceNo);
						return USIM_SMT_PPS_ERROR;
					}
                		}

				// Clear Interrupt
				DRV_Reg32(usim_base + SIM_STS_MTK) = DRV_Reg32(usim_base + SIM_STS_MTK);
				// Clear IP's Internal TOUT enable bit
				DRV_Reg32(usim_base + SIM_CONF_MTK) = (DRV_Reg32(usim_base + SIM_CONF_MTK) & ~(SIM_CONF_TOUTEN | USIM_VOL_CFG)) | (USIM_VOL_CFG);
				break;
			}
		}
		DRV_Reg32(usim_base + SIM_BRR_MTK) = (DRV_Reg32(usim_base + SIM_BRR_MTK) & 0x3) | ((Fi / Di) << 2);
		kal_sleep_task(10);
	}


#define	EF_ICCID	0x2FE2
	// Clear
	DRV_Reg32(usim_base + SIM_CTRL_MTK) = DRV_Reg32(usim_base + SIM_CTRL_MTK) | SIM_CTRL_IFCLR;
	j = 0;
	while(DRV_Reg32(usim_base + SIM_CONFSTA_MTK) & SIM_CONFSTA_IFCLR_ON);
	{
		if(j > 0xFFFFFF)
		{
			USIM_SMT_DEACTIVATION(hwInterfaceNo);
			kal_sprintf(sim_dbg_str,"[SIM_SMT]: IFCLR ERROR\n\r");
			DRV_ICC_print_str(sim_dbg_str);
			return USIM_SMT_IFCLR_ERROR;
		}
		j++;
	}
	// 2.0 Select File of ICCID
	// 2.0 set file id
	ins[5] = (EF_ICCID >> 8) & 0xFF;
	ins[6] = EF_ICCID & 0xFF;

	// 2.1 Set RXTIDE of SIM_TIDE to 0 and TXTIDE to 1 (Note: TXTIDE cannot be 0 for DMA)
	DRV_Reg32(usim_base + SIM_TIDE_MTK) = (DRV_Reg32(usim_base + SIM_TIDE_MTK) & (~SIM_TIDE_RXMASK) & (~SIM_TIDE_TXMASK)) | 0x0100;

	// 2.2 Enable T0
	DRV_Reg32(usim_base + SIM_CONF_MTK) = DRV_Reg32(usim_base + SIM_CONF_MTK) | SIM_CONF_T0EN; 

	// 2.3 Directly Write File ID to USIM FIFO
	DRV_Reg32(usim_base + SIM_DATA_MTK) = ins[0];
	DRV_Reg32(usim_base + SIM_DATA_MTK) = ins[1];
	DRV_Reg32(usim_base + SIM_DATA_MTK) = ins[2];
	DRV_Reg32(usim_base + SIM_DATA_MTK) = ins[3];
	DRV_Reg32(usim_base + SIM_DATA_MTK) = ins[4];

	if(hwInterfaceNo)
	{
		// HDMA TX (Memory to Device), USIM's Bus Width is Fixed to 8 bits
		DRV_Reg8(sim_uncachedTxBuffer1 + 0x00) = ins[5];
		DRV_Reg8(sim_uncachedTxBuffer1 + 0x01) = ins[6];
		DRV_Reg32(REG_HDMA_HDCTRR1) = HDCTRR_RX_SEL0(0) | HDCTRR_BST_SIZE(HDCTRR_BST_SIZE_16) | HDCTRR_DEV_BUS_WIDTH(HDCTRR_BUS_WIDTH_8) | HDCTRR_MEM_BUS_WIDTH(HDCTRR_BUS_WIDTH_32);
		DRV_Reg32(REG_HDMA_HPRGA0R1) = (kal_uint32) sim_uncachedTxBuffer1;
		DRV_Reg32(REG_HDMA_HDC0R1) = HDCR_XFER_SIZE0(2) | HDCR_START0;
	} else
	{
		// HDMA TX (Memory to Device), USIM's Bus Width is Fixed to 8 bits
		DRV_Reg8(sim_uncachedTxBuffer0 + 0x00) = ins[5];
		DRV_Reg8(sim_uncachedTxBuffer0 + 0x01) = ins[6];
		DRV_Reg32(REG_HDMA_HDCTRR0) = HDCTRR_RX_SEL0(0) | HDCTRR_BST_SIZE(HDCTRR_BST_SIZE_16) | HDCTRR_DEV_BUS_WIDTH(HDCTRR_BUS_WIDTH_8) | HDCTRR_MEM_BUS_WIDTH(HDCTRR_BUS_WIDTH_32);
		DRV_Reg32(REG_HDMA_HPRGA0R0) = (kal_uint32) sim_uncachedTxBuffer0;
		DRV_Reg32(REG_HDMA_HDC0R0) = HDCR_XFER_SIZE0(2) | HDCR_START0;
	}

	DRV_Reg32(usim_base + SIM_COMDLEN_MTK) = ins[4];
	DRV_Reg32(usim_base + SIM_COMDCTRL_MTK) = SIM_INS_START | SIM_INS_INSD | ins[1]; // Expect to Send

	// 2.4 Wait for Operation Done (Including Response)
	j = 0;
	while(!(DRV_Reg32(usim_base + SIM_STS_MTK) & SIM_STS_T0END))
	{
		if(j > 0xFFFFFF)
		{
			USIM_SMT_DEACTIVATION(hwInterfaceNo);
			kal_sprintf(sim_dbg_str,"[SIM_SMT:%d]: NO T0END\n\r", __LINE__);
			DRV_ICC_print_str(sim_dbg_str);
			return USIM_SMT_NO_T0END;
		}
		j++;
	}

	// 2.5 Clear Interrupt
	DRV_Reg32(usim_base + SIM_STS_MTK) = DRV_Reg32(usim_base + SIM_STS_MTK);

	// 2.6 Check Returned Status Bytes
	sw1 = DRV_Reg32(usim_base + SIM_SW1_MTK);
	sw2 = DRV_Reg32(usim_base + SIM_SW2_MTK); sw2 = sw2;

	if((sw1 & 0xF0) != 0x90 && sw1 != 0x69)
	{
		kal_sprintf(sim_dbg_str,"[SIM_SMT]: SW ERROR %x %x\n\r", sw1, sw2);
		DRV_ICC_print_str(sim_dbg_str);
		return USIM_SMT_SW_ERROR;
	}

	if(sw1 == 0x94)
	{
		kal_sprintf(sim_dbg_str,"[SIM_SMT]: SW:%x %x, use non-HDMA mode to test again\n\r", sw1, sw2);
		DRV_ICC_print_str(sim_dbg_str);
		// 2.1 Set RXTIDE of SIM_TIDE to 0 and TXTIDE to 1 (Note: TXTIDE cannot be 0 for DMA)
		DRV_Reg32(usim_base + SIM_TIDE_MTK) = (DRV_Reg32(usim_base + SIM_TIDE_MTK) & (~SIM_TIDE_RXMASK) & (~SIM_TIDE_TXMASK)) | 0x0100;

		// 2.2 Enable T0
		DRV_Reg32(usim_base + SIM_CONF_MTK) = DRV_Reg32(usim_base + SIM_CONF_MTK) | SIM_CONF_T0EN; 

		// 2.3 Directly Write File ID to USIM FIFO
		DRV_Reg32(usim_base + SIM_DATA_MTK) = ins[0];
		DRV_Reg32(usim_base + SIM_DATA_MTK) = ins[1];
		DRV_Reg32(usim_base + SIM_DATA_MTK) = ins[2];
		DRV_Reg32(usim_base + SIM_DATA_MTK) = ins[3];
		DRV_Reg32(usim_base + SIM_DATA_MTK) = ins[4];
		DRV_Reg32(usim_base + SIM_DATA_MTK) = ins[5];
		DRV_Reg32(usim_base + SIM_DATA_MTK) = ins[6];

		DRV_Reg32(usim_base + SIM_COMDLEN_MTK) = ins[4];
		DRV_Reg32(usim_base + SIM_COMDCTRL_MTK) = SIM_INS_START | SIM_INS_INSD | ins[1]; // Expect to Send

		// 2.4 Wait for Operation Done (Including Response)
		j = 0;
		while(!(DRV_Reg32(usim_base + SIM_STS_MTK) & SIM_STS_T0END))
		{
			if(j > 0xFFFFFF)
			{
				USIM_SMT_DEACTIVATION(hwInterfaceNo);
				kal_sprintf(sim_dbg_str,"[SIM_SMT]: NO T0END\n\r");
				DRV_ICC_print_str(sim_dbg_str);
				return USIM_SMT_NO_T0END;
			}
			j++;
		}

		// 2.5 Clear Interrupt
		DRV_Reg32(usim_base + SIM_STS_MTK) = DRV_Reg32(usim_base + SIM_STS_MTK);

		// 2.6 Check Returned Status Bytes
		sw1 = DRV_Reg32(usim_base + SIM_SW1_MTK);
		sw2 = DRV_Reg32(usim_base + SIM_SW2_MTK); sw2 = sw2;

		if(((sw1 & 0xF0) != 0x90 && sw1 != 0x69) || sw1 == 0x94)
		{
			kal_sprintf(sim_dbg_str,"[SIM_SMT]: SW ERROR %x %x\n\r", sw1, sw2);
			DRV_ICC_print_str(sim_dbg_str);
			return USIM_SMT_SW_ERROR;
		}
	}

// --

	// 3.0 Get Response
	DRV_Reg32(usim_base + SIM_CONF_MTK) = DRV_Reg32(usim_base + SIM_CONF_MTK) | SIM_CONF_T0EN;

	length = sw2;

	ins[0] = 0xA0;
	ins[1] = 0xC0;
	ins[2] = 0x00;
	ins[3] = 0x00;
	ins[4] = length;
	DRV_Reg32(usim_base + SIM_DATA_MTK) = ins[0];
	DRV_Reg32(usim_base + SIM_DATA_MTK) = ins[1];
	DRV_Reg32(usim_base + SIM_DATA_MTK) = ins[2];
	DRV_Reg32(usim_base + SIM_DATA_MTK) = ins[3];
	DRV_Reg32(usim_base + SIM_DATA_MTK) = ins[4];

	if(hwInterfaceNo)
	{
		// HDMA RX (Memory to Device), USIM's Bus Width is Fixed to 8 bits
		DRV_Reg32(REG_HDMA_HDCTRR1) = HDCTRR_RX_SEL0(1) | HDCTRR_BST_SIZE(HDCTRR_BST_SIZE_16) | HDCTRR_DEV_BUS_WIDTH(HDCTRR_BUS_WIDTH_8) | HDCTRR_MEM_BUS_WIDTH(HDCTRR_BUS_WIDTH_32);
		DRV_Reg32(REG_HDMA_HPRGA0R1) = (kal_uint32) sim_uncachedRxBuffer1;
		DRV_Reg32(REG_HDMA_HDC0R1) = HDCR_XFER_SIZE0(length) | HDCR_START0;
	} else
	{
		// HDMA RX (Memory to Device), USIM's Bus Width is Fixed to 8 bits
		DRV_Reg32(REG_HDMA_HDCTRR0) = HDCTRR_RX_SEL0(1) | HDCTRR_BST_SIZE(HDCTRR_BST_SIZE_16) | HDCTRR_DEV_BUS_WIDTH(HDCTRR_BUS_WIDTH_8) | HDCTRR_MEM_BUS_WIDTH(HDCTRR_BUS_WIDTH_32);
		DRV_Reg32(REG_HDMA_HPRGA0R0) = (kal_uint32) sim_uncachedRxBuffer0;
		DRV_Reg32(REG_HDMA_HDC0R0) = HDCR_XFER_SIZE0(length) | HDCR_START0;
	}

	DRV_Reg32(usim_base + SIM_COMDLEN_MTK) = ins[4];
	DRV_Reg32(usim_base + SIM_COMDCTRL_MTK) = SIM_INS_START | ins[1]; // Expect to Receive

	// Wait Until TX FIFO Empty
	j = 0;
	while (DRV_Reg32(usim_base + SIM_COUNT_MTK) != 0)
	{
		if(j > 0xFFFFFF)
		{
			USIM_SMT_DEACTIVATION(hwInterfaceNo);
			kal_sprintf(sim_dbg_str,"[SIM_SMT]: COUNT ERROR\n\r");
			DRV_ICC_print_str(sim_dbg_str);
			return USIM_SMT_COUNT_ERROR;
		}
		j++;
	}

	// 2.4 Wait for Operation Done (Including Response)
	j = 0;
	while(!(DRV_Reg32(usim_base + SIM_STS_MTK) & SIM_STS_T0END))
	{
		if(j > 0xFFFFFF)
		{
			USIM_SMT_DEACTIVATION(hwInterfaceNo);
			kal_sprintf(sim_dbg_str,"[SIM_SMT]: NO T0END\n\r");
			DRV_ICC_print_str(sim_dbg_str);
			return USIM_SMT_NO_T0END;
		}
		j++;
	}

	j = 0;
	if(hwInterfaceNo)
	{
		while((DRV_Reg32(REG_HDMA_HDSR) & HDMA_STAT0_1))
		{
			if(j > 0xFFFFFF)
			{
				USIM_SMT_DEACTIVATION(hwInterfaceNo);
				kal_sprintf(sim_dbg_str,"[SIM_SMT]: HDMA ERROR\n\r");
				DRV_ICC_print_str(sim_dbg_str);
				return USIM_SMT_HDMA_ERROR;
			}
			j++;
		}
		kal_sprintf(sim_dbg_str, "[SIM_SMT]: Get %x %x %x %x %x  %x %x %x %x %x  %x %x %x %x %x\n\r",
			sim_uncachedRxBuffer1[0], sim_uncachedRxBuffer1[1], sim_uncachedRxBuffer1[2], sim_uncachedRxBuffer1[3], sim_uncachedRxBuffer1[4],
			sim_uncachedRxBuffer1[5], sim_uncachedRxBuffer1[6], sim_uncachedRxBuffer1[7], sim_uncachedRxBuffer1[8], sim_uncachedRxBuffer1[9],
			sim_uncachedRxBuffer1[10], sim_uncachedRxBuffer1[11], sim_uncachedRxBuffer1[12], sim_uncachedRxBuffer1[13], sim_uncachedRxBuffer1[14]);
	} else
	{
		while((DRV_Reg32(REG_HDMA_HDSR) & HDMA_STAT0_0))
		{
			if(j > 0xFFFFFF)
			{
				USIM_SMT_DEACTIVATION(hwInterfaceNo);
				kal_sprintf(sim_dbg_str,"[SIM_SMT]: HDMA ERROR\n\r");
				DRV_ICC_print_str(sim_dbg_str);
				return USIM_SMT_HDMA_ERROR;
			}
			j++;
		}
		kal_sprintf(sim_dbg_str, "[SIM_SMT]: Get %x %x %x %x %x  %x %x %x %x %x  %x %x %x %x %x\n\r",
			sim_uncachedRxBuffer0[0], sim_uncachedRxBuffer0[1], sim_uncachedRxBuffer0[2], sim_uncachedRxBuffer0[3], sim_uncachedRxBuffer0[4],
			sim_uncachedRxBuffer0[5], sim_uncachedRxBuffer0[6], sim_uncachedRxBuffer0[7], sim_uncachedRxBuffer0[8], sim_uncachedRxBuffer0[9],
			sim_uncachedRxBuffer0[10], sim_uncachedRxBuffer0[11], sim_uncachedRxBuffer0[12], sim_uncachedRxBuffer0[13], sim_uncachedRxBuffer0[14]);
	}
	DRV_ICC_print_str(sim_dbg_str);

	// 2.5 Clear Interrupt
	DRV_Reg32(usim_base + SIM_STS_MTK) = DRV_Reg32(usim_base + SIM_STS_MTK);

	// 2.6 Check Returned Status Bytes
	sw1 = DRV_Reg32(usim_base + SIM_SW1_MTK);
	sw2 = DRV_Reg32(usim_base + SIM_SW2_MTK); sw2 = sw2;

	if(sw1 != 0x90)
	{
		kal_sprintf(sim_dbg_str,"[SIM_SMT]: SW ERROR, expt:0x90, real:%x\n\r", sw1);
		DRV_ICC_print_str(sim_dbg_str);
		return USIM_SMT_SW_ERROR;
	}
// --

	// 3. Deactivation
	// 3.0 If SIM Aleady Activated, Deactivate it
	DRV_Reg32(usim_base + SIM_CTRL_MTK) = DRV_Reg32(usim_base + SIM_CTRL_MTK) & (~SIM_CTRL_SIMON);
	j = 0;
	while(!(DRV_Reg32(usim_base + SIM_ATRSTA_MTK) & USIM_ATRSTA_OFF))
	{
		if(j > 0xFFFFFF)
		{
			USIM_SMT_DEACTIVATION(hwInterfaceNo);
			kal_sprintf(sim_dbg_str,"[SIM_SMT]: NO ATRSTA OFF\n\r");
			DRV_ICC_print_str(sim_dbg_str);
			return USIM_SMT_NO_ATRSTA_OFF;
		}
		j++;

	}
#ifdef __FPGA__
#else
	DRV_ICC_PMU_switch(hwInterfaceNo, KAL_FALSE);
#endif

	return USIM_SMT_NO_ERROR;
}

void usim_iftest_sw_reset_usim(kal_uint32 hwInterfaceNo)
{
#if defined(MT6290)
	if(hwInterfaceNo == 0) drv_rstctl_sw_reset(RST_USIM0);
	else drv_rstctl_sw_reset(RST_USIM1);
#elif defined(MT6595)
#elif defined(MT6752)
#endif
	return;
}
