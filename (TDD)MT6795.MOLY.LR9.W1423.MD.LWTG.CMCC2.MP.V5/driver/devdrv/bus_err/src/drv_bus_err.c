#include "drv_bus_err.h"
#include "drv_comm.h"
#include "intrCtrl.h"
#include "drv_hisr.h"
#include "kal_general_types.h"
#include "devdrv_ls.h"

void bus_err_LISR(void)
{
	//MD BUS ERR information
	dhl_print(TRACE_ERROR, 0, MOD_LISR2HISR_BUS_ERR, "MD:BUS_ERR,[DEC_ERR_CTRL: %08x]", DRV_Reg32(MD_DEC_ERR_CTL));
	dhl_print(TRACE_ERROR, 0, MOD_LISR2HISR_BUS_ERR, "MD:BUS_ERR,[DEC_ERR_TYPE: %08x]", DRV_Reg32(MD_DEC_ERR_TYPE));
	dhl_print(TRACE_ERROR, 0, MOD_LISR2HISR_BUS_ERR, "MD:BUS_ERR,ADDR:%08x",DRV_Reg32(MD_DEC_ERR_ADDR));

#if  defined(__SMART_PHONE_MODEM__) &&  !defined(__HIF_CCIF_SUPPORT__) 
	EXT_ASSERT(0,DRV_Reg32(MD_DEC_ERR_CTL),DRV_Reg32(MD_DEC_ERR_TYPE),DRV_Reg32(MD_DEC_ERR_ADDR));
#else
	//AP BUS ERR information
	dhl_print(TRACE_ERROR, 0, MOD_LISR2HISR_BUS_ERR, "AP:BUS_ERR,%08x",DRV_Reg32(AP_DEC_ERR_CTL));
	dhl_print(TRACE_ERROR, 0, MOD_LISR2HISR_BUS_ERR, "AP:BUS_ERR,ADDR:%08x",DRV_Reg32(AP_DEC_ERR_ADDR));
		
	kal_uint32 bus_int_info; //MD interrupt status + MD configuration + MD error type + AP info
	bus_int_info = ((DRV_Reg32(MD_DEC_ERR_CTL)&0xFF0000)<<8) + ((DRV_Reg32(MD_DEC_ERR_CTL)&0xFF)<<16) + ((DRV_Reg32(MD_DEC_ERR_TYPE)&0xFF)<<8)+((DRV_Reg32(AP_DEC_ERR_CTL)&0xFF0)>>4);
			
	// Assert with MD&AP information: bus_int_info + MD_DEC_ERR_ADDR + AP_DEC_ERR_ADDR
	EXT_ASSERT(0,bus_int_info,DRV_Reg32(MD_DEC_ERR_ADDR),DRV_Reg32(AP_DEC_ERR_ADDR));
#endif

	/*
	//Clean MD BUS ERR information
	DRV_WriteReg32(MD_DEC_ERR_CTL, 0x0001000D);
	DRV_WriteReg32(MD_DEC_ERR_TYPE, 0x0000001F);
	dhl_print(TRACE_ERROR, 0, MOD_LISR2HISR_BUS_ERR, "MD:BUS_ERR,[After reset: %08x]", DRV_Reg32(MD_DEC_ERR_CTL));

	//Clean AP BUS ERR information
	DRV_WriteReg32(0xBE460010, 0x00000FE0);
	dhl_print(TRACE_ERROR, 0, MOD_LISR2HISR_BUS_ERR, "AP:BUS_ERR,[After reset: %08x]", DRV_Reg32(AP_DEC_ERR_CTL));
	*/
	
}

kal_int32 bus_err_status_init(void)
{
#if defined(MT6290)
    #if  defined(__SMART_PHONE_MODEM__) &&  !defined(__HIF_CCIF_SUPPORT__)
    #else
	// Enable AP region R/W access
    	DRV_WriteReg32(AP_AHB_OWN, (DRV_Reg32(AP_AHB_OWN)|0x00100000));
    #endif
	//register bus err lisr
	IRQ_Register_LISR(IRQ_BUS_ERR_CODE, bus_err_LISR, "BUSERR");
	
	IRQSensitivity(MD_IRQID_BUS_ERR, KAL_TRUE);
    	IRQClearInt(MD_IRQID_BUS_ERR);
    	IRQUnmask(MD_IRQID_BUS_ERR);

	//set MD bus_err option & clear interrupt status
	DRV_WriteReg32(MD_DEC_ERR_CTL, MD_DEC_ERR_CTL_INI_VAL); //decode error + repetitively interrupt
	DRV_WriteReg32(MD_DEC_ERR_TYPE, MD_DEC_ERR_TYPE_RESET);
    #if  defined(__SMART_PHONE_MODEM__) &&  !defined(__HIF_CCIF_SUPPORT__)
    #else
	//set AP bus_err option & clear interrupt status
    	DRV_WriteReg32(AP_DEC_ERR_CTL, AP_DEC_ERR_CTL_INI_VAL); //decode error + repetitively interrupt	
    #endif
#endif

	return 0;
}


#if defined(__MTK_TARGET__)
DEVDRV_LS_INTSRAM_ROCODE void clear_bus_err_int(void)
#else 
void clear_bus_err_int(void)
#endif
{
	MDCIRQ_WrClrRegBit_Vector(MDCIRQ_ISAR_BASE, MD_IRQID_BUS_ERR);
}
