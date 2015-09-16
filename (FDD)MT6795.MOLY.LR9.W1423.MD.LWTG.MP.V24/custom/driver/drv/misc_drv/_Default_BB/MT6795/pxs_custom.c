/*******************************************************************************
 *
 * Filename:
 * ---------
 * pxs_custom.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 *   PXS driver custom file
 *
 * Author:
 * -------
 * -------
 *
 *******************************************************************************/

#if defined(__PXS_CM3623__)
#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "pxs_cm3623.h"
#include "pxs_custom.h"
#include "drv_comm.h"



static kal_uint16 cm3623_thrshold_array[]=
{
	10,
	4
	
};

kal_bool cm3623_sensitivity_level_num(kal_uint16 *pData)
{
	*pData = sizeof(cm3623_thrshold_array)/sizeof(kal_uint16);
	return KAL_TRUE;
}

kal_bool cm3623_get_sensitivity_table(kal_uint16 **pData)
{
	*pData = &cm3623_thrshold_array[0];
	return KAL_TRUE;
}


kal_bool cm3623_power_enable(kal_bool enable)
{
	
//#if defined(LUFFY76V2_DEMO_BB)
	{
		// Only for Luffy76 V2
		// Luffy76 V2 PXS SDA use GPIO101
		// GPIO101 GPIO mode pull HIGH is controlled by MSDC2 (From 1 to 3)
		// So we need to configure MSDC1 controller to enable pull HIGH (I2C open gain)
		kal_uint32 val32;
		
		// Clear MSDC1 clock gating
		DRV_WriteReg(0x610D0320, 0x200);
		// Configure MSDC1 controller to enable PULL HIGH functionality
		val32 = DRV_Reg32(0x60120018);
		val32 &= ~(0x00000700);
		val32 |= (0x00000200);
		DRV_WriteReg32(0x60120018, val32);
	}
//#endif // #if defined(LUFFY76V2_DEMO_BB)
	return KAL_TRUE;
}

//kal_uint16 cm3623_get_pxs_threshold(void)
//{
//	return CM3623_PXS_THRESHOLD;
//}


kal_bool pxs_custom_hw_cmd_handler(PXS_HW_CMD_ENUM cmd, void *pData)
{
	switch (cmd)
	{
		case PXS_HW_CMD_POWER_ENABLE:
			return cm3623_power_enable(*((kal_bool *)pData));
		break;
		case PXS_HW_CMD_GET_SENSITIVITY_LEVEL_NUM:
			return cm3623_sensitivity_level_num((kal_uint16 *)pData);
		break;
		case PXS_HW_CMD_GET_SENSITIVITY_TABLE:
			return cm3623_get_sensitivity_table((kal_uint16 **)pData);
		break;
		default:
			return KAL_FALSE;
		//break;
	}
}


extern kal_uint16 cm3623_get_pxs_sensitivity_level_num(void);
extern kal_uint16 *cm3623_get_pxs_sensitivity_level_table(void);



#endif // #if defined(__PXS_CM3623__)
