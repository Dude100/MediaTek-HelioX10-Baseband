#ifdef __SIM_DRV_MULTI_DRV_ARCH__
#include "kal_public_api.h"
#include "drv_comm.h"
#include "dma_sw.h"
#include 	"intrCtrl.h"
#include "sim_hw.h"
#include "sim_al.h"
#include "sim_sw_comm.h"

#include "sim_ca_icc_nagra.h"
#include "multi_icc_custom.h"

extern sim_ctrlDriver sim_ctrlDriver_MT6302, sim_ctrlDriver_MTK;
extern kal_uint32	hwCbArray[SIM_DRV_MTK_INTERFACE_NUM];
extern sim_ctrlDriver *sim_driverTable[];

extern sim_HW_cb	simHWCbArray[];

TIccStatus DalIccInit();

sim_test_function_sim3()
{
	TIccStatus IccStatus;


		IccStatus = DalIccInit();
		test_icc();

}

sim_test_function_sim1()
{
	sim_power_enum resultVoltage;
	sim_HW_cb	*hw_cb;
	usim_status_enum status;
	kal_uint32 simInterface;

	simInterface = 0;
	hw_cb = &simHWCbArray[simInterface];
	status = sim_ctrlDriver_MT6302.reset(UNKNOWN_POWER_CLASS, &resultVoltage, KAL_FALSE, hw_cb);
	sim_ctrlDriver_MT6302.EOC(hw_cb);
}

sim_test_function_sim2()
{
	sim_power_enum resultVoltage;
	sim_HW_cb	*hw_cb;
	usim_status_enum status;
	kal_uint32 simInterface;




	simInterface = 2;
	hw_cb = &simHWCbArray[simInterface];
	status = sim_ctrlDriver_MT6302.reset(UNKNOWN_POWER_CLASS, &resultVoltage, KAL_FALSE, hw_cb);
	sim_ctrlDriver_MT6302.EOC(hw_cb);

}

sim_test_reset_phone(SIM_ICC_APPLICATION application)
{
	sim_power_enum resultVoltage;
	usim_status_enum status;
	status = L1sim_Reset_All(UNKNOWN_POWER_CLASS, &resultVoltage, KAL_FALSE, application);
}

sim_test_phone_selectGSM(SIM_ICC_APPLICATION application)
{
	SIM_test_selectGSMFile_multiple(application);
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
#ifdef GEMINI_UT_MORE_RESET_POWEROFF
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#ifdef GEMINI_UT_MORE_RESET_POWEROFF
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#ifdef GEMINI_UT_MORE_RESET_POWEROFF
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
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
#endif

init_all_cb2()
{
	sim_init_hwCb();
	DRV_ICC_interface_init(SIM_ICC_APPLICATION_CMMB_SMD);
	DRV_ICC_interface_init(SIM_ICC_APPLICATION_PHONE1);
	DRV_ICC_interface_init(SIM_ICC_APPLICATION_PHONE2);
}

init_all_cb()
{
	sim_power_enum resultVoltage;
	sim_HW_cb	*hw_cb;
	usim_status_enum status;
	kal_uint32 simInterface;
	TIccStatus IccStatus;

#if (2 == SIM_DRV_MTK_INTERFACE_NUM)
	{
		simInterface = 1;
		hw_cb = &simHWCbArray[simInterface];
		hwCbArray[simInterface] = (kal_uint32)hw_cb;
		sim_driverTable[simInterface] = &sim_ctrlDriver_MTK;

		hw_cb->mtk_baseAddr = SIM2_base;
		hw_cb->mtk_pdnAddr = DRVPDN_CON0;
		hw_cb->mtk_pdnBit = DRVPDN_CON0_SIM2;
		hw_cb->mtk_pdnDevice = PDN_SIM2;
		hw_cb->mtk_dmaMaster = DMA_SIM2;
		hw_cb->mtk_lisrCode = IRQ_SIM2_CODE;
		hw_cb->simInterface = simInterface;
		hw_cb->MT6302InterfaceNo = 0xFF;
		hw_cb->MT6302PeerInterfaceCb = 0x0;
	}
#endif
	{
		simInterface = 0;
		hw_cb = &simHWCbArray[simInterface];
		hwCbArray[simInterface] = (kal_uint32)hw_cb;
		hw_cb->mtk_baseAddr = SIM_base;
		hw_cb->mtk_pdnAddr = DRVPDN_CON1;
		hw_cb->mtk_pdnBit = DRVPDN_CON1_SIM;
		hw_cb->mtk_pdnDevice = PDN_SIM;
		hw_cb->mtk_dmaMaster = DMA_SIM;
		hw_cb->mtk_lisrCode = IRQ_SIM_CODE;
		hw_cb->simInterface = simInterface;
		hw_cb->MT6302InterfaceNo = 0;
		hw_cb->MT6302PeerInterfaceCb = &simHWCbArray[2];
	}

	{
		simInterface = 2;
		hw_cb = &simHWCbArray[simInterface];
		hwCbArray[simInterface] = (kal_uint32)hw_cb;
		hw_cb->mtk_baseAddr = SIM_base;
		hw_cb->mtk_pdnAddr = DRVPDN_CON1;
		hw_cb->mtk_pdnBit = DRVPDN_CON1_SIM;
		hw_cb->mtk_pdnDevice = PDN_SIM;
		hw_cb->mtk_dmaMaster = DMA_SIM;
		hw_cb->mtk_lisrCode = IRQ_SIM_CODE;
		hw_cb->simInterface = simInterface;
		hw_cb->MT6302InterfaceNo = 1;
		hw_cb->MT6302PeerInterfaceCb = &simHWCbArray[0];
	}


}

#define SIM_TEST_FUNCTION_NUMBER_MAX 5

void multiple_sim_test()
{
	kal_uint32 testIndex = 0;

	sim_MT6302_init();
	init_all_cb2();

	while(1){
		switch( (testIndex % SIM_TEST_FUNCTION_NUMBER_MAX)){
			case 0:
				sim_test_function_sim3();
				break;
			case 1:
				sim_test_reset_phone(SIM_ICC_APPLICATION_PHONE1);
				break;
			case 2:
				sim_test_reset_phone(SIM_ICC_APPLICATION_PHONE2);
				break;
			case 3:
				sim_test_phone_selectGSM(SIM_ICC_APPLICATION_PHONE1);
				break;
			case 4:
				sim_test_phone_selectGSM(SIM_ICC_APPLICATION_PHONE1);
				break;
			default:
				ASSERT(0);
		}
		testIndex ++;
		kal_sleep_task(20);
	}
}
#endif /*__SIM_DRV_MULTI_DRV_ARCH__*/
