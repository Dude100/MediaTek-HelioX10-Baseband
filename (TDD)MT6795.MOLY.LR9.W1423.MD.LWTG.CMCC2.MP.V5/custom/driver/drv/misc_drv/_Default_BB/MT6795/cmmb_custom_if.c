#if defined(__CMMB_SUPPORT__)
#include "kal_public_api.h" //MSBB change #include "kal_release.h"      // Basic data type 

#include "cmmb_custom_if.h"
#include "gpio_sw.h"

/**
 * Power on Demodulator
 *
 * @param None.
 *
 * @return None.
 */
void cmmb_power_on_custom(void)
{
	DCL_HANDLE cmmb_reset_handle;
	DCL_HANDLE cmmb_power_on_handle;

	cmmb_reset_handle = DclGPIO_Open(DCL_GPIO, CMMB_GPIO_RESET_PIN);
	cmmb_power_on_handle = DclGPIO_Open(DCL_GPIO, CMMB_GPIO_POWER_ON_PIN);

	DclGPIO_Control(cmmb_reset_handle, GPIO_CMD_SET_DIR_OUT, NULL);
	DclGPIO_Control(cmmb_reset_handle, GPIO_CMD_WRITE_LOW, NULL);

	//need wait about 50ms
	kal_sleep_task(15);
	
	DclGPIO_Control(cmmb_reset_handle, GPIO_CMD_WRITE_HIGH, NULL);

	//need wait about 50ms
	kal_sleep_task(15);

	//enable all LDO
	DclGPIO_Control(cmmb_power_on_handle, GPIO_CMD_SET_DIR_OUT, NULL);
	DclGPIO_Control(cmmb_power_on_handle, GPIO_CMD_WRITE_HIGH, NULL);

	DclGPIO_Close(cmmb_reset_handle);
	DclGPIO_Close(cmmb_power_on_handle);
}

void cmmb_power_off_custom(void)
{
	DCL_HANDLE cmmb_reset_handle;
	DCL_HANDLE cmmb_power_on_handle;

	cmmb_reset_handle = DclGPIO_Open(DCL_GPIO, CMMB_GPIO_RESET_PIN);
	cmmb_power_on_handle = DclGPIO_Open(DCL_GPIO, CMMB_GPIO_POWER_ON_PIN);

	DclGPIO_Control(cmmb_reset_handle, GPIO_CMD_SET_DIR_OUT, NULL);
	DclGPIO_Control(cmmb_power_on_handle, GPIO_CMD_SET_DIR_OUT, NULL);

	//pull low reset pin and disable all LDO
	DclGPIO_Control(cmmb_reset_handle, GPIO_CMD_WRITE_LOW, NULL);
	DclGPIO_Control(cmmb_power_on_handle, GPIO_CMD_WRITE_LOW, NULL);

	DclGPIO_Close(cmmb_reset_handle);
	DclGPIO_Close(cmmb_power_on_handle);
}

#endif
