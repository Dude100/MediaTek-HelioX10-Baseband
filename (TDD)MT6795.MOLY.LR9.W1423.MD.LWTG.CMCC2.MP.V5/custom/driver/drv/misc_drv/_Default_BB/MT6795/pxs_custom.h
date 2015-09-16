/*******************************************************************************
 *
 * Filename:
 * ---------
 * pxs_custom.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 *   PXS driver custom header file
 *
 * Author:
 * -------
 * -------
 *
 *******************************************************************************/
#if defined(__PXS_CM3623__)
#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "drv_comm.h"
#include "dcl.h"

// Use GPIO to simulate I2C communication interface
#define USE_SW_I2C

// Use HW I2C
//#define USE_HW_I2C


#if defined(USE_SW_I2C)
extern const char gpio_pxs_i2c_scl_pin;
extern const char gpio_pxs_i2c_sda_pin;

//#define CM3623_SCL   gpio_pxs_scl_pin
//#define CM3623_SDA   gpio_pxs_sda_pin

#define CM3623_SCL   gpio_pxs_i2c_scl_pin
#define CM3623_SDA   gpio_pxs_i2c_sda_pin

#define SCL_GPIO_MODE()   DclGPIO_Control(pxs_scl_gpio_dcl_handle,GPIO_CMD_SET_MODE_0,0); //GPIO_ModeSetup(CM3623_SCL, 0)
#define SCL_HIGH()        DclGPIO_Control(pxs_scl_gpio_dcl_handle,GPIO_CMD_WRITE_HIGH,0); //GPIO_WriteIO(1, CM3623_SCL)
#define SCL_LOW()         DclGPIO_Control(pxs_scl_gpio_dcl_handle,GPIO_CMD_WRITE_LOW,0); //GPIO_WriteIO(0, CM3623_SCL)
#define SCL_OUTPUT()      DclGPIO_Control(pxs_scl_gpio_dcl_handle,GPIO_CMD_SET_DIR_OUT,0); //GPIO_InitIO(GPIO_DIR_OUTPUT, CM3623_SCL)
#define SDA_GPIO_MODE()   DclGPIO_Control(pxs_sda_gpio_dcl_handle,GPIO_CMD_SET_MODE_0,0); //GPIO_ModeSetup(CM3623_SDA, 0)
#define SDA_HIGH()        DclGPIO_Control(pxs_sda_gpio_dcl_handle,GPIO_CMD_WRITE_HIGH,0); //GPIO_WriteIO(1, CM3623_SDA)
#define SDA_LOW()         DclGPIO_Control(pxs_sda_gpio_dcl_handle,GPIO_CMD_WRITE_LOW,0); //GPIO_WriteIO(0, CM3623_SDA)
#define SDA_OUTPUT()      DclGPIO_Control(pxs_sda_gpio_dcl_handle,GPIO_CMD_SET_DIR_OUT,0); //GPIO_InitIO(GPIO_DIR_OUTPUT, CM3623_SDA)
#define SDA_INPUT()       DclGPIO_Control(pxs_sda_gpio_dcl_handle,GPIO_CMD_SET_DIR_IN,0); //GPIO_InitIO(GPIO_DIR_INPUT, CM3623_SDA)
#define SDA_VAL()         pxs_GPIO_ReadIO(pxs_sda_gpio_dcl_handle) //GPIO_ReadIO(CM3623_SDA)

#endif // #if defined(USE_SW_I2C)

// PXS EINT
extern const unsigned char PXS_EINT_NO;
#define CM3623_EINT  PXS_EINT_NO


//extern kal_bool cm3623_power_enable(kal_bool enable);
//extern kal_uint16 cm3623_get_pxs_threshold(void);
//extern kal_uint16 cm3623_get_pxs_sensitivity_level_num(void);
//extern kal_uint16 *cm3623_get_pxs_sensitivity_level_table(void);

extern kal_bool pxs_custom_hw_cmd_handler(PXS_HW_CMD_ENUM cmd, void *pData);



#endif // #if defined(__PXS_CM3623__)

