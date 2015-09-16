
#ifndef __SPI_DRV_HAL_H__
/* !ignore me! */
#define __SPI_DRV_HAL_H__

#include "spi.h"
#include "drv_features.h"
#include "kal_general_types.h"

/* !ignore me! */
#if defined(DRV_SPI_SUPPORT) && defined(DRV_SPI_HAL)

/* SPI ports number. */
#define SPI_MAX_PORT_NUM 2

/* SPI Handle.
   SPI handle can be retrieved from spi_open(). It is used for most SPI APIs.
*/
typedef kal_uint32 SPI_HANDLE;

/* <GROUP CallBackFunctions>
   FUNCTION
   SPI_CALLBACK
   DESCRIPTION
   SPI callback function
   SPI callback function is called when SPI interrupt has arrived. It indicates SPI has finished the last data transfer.
   SPI callback function is called in the context of HISR.
*/
typedef void (*SPI_CALLBACK)(void);

/* SPI result enum.
*/
typedef enum
{
    /* Indicates no error occurs in the last operation. */
    SPI_RESULT_OK,
    
    /* Indicates some errors have occured in the last operation. */
    SPI_RESULT_ERROR,

    /* Indicates some errors have occured in the last operation. */
    SPI_RESULT_INVALID_ARGUMENT,  
    
    /* Indicates the function is not supported on the current platform. */
    SPI_RESULT_NOT_SUPPORTED
} SPI_RESULT;

/*************************************************************************************************************************************
  * SPI IOCTL code definition.
  * For detail description and usage of SPI control codes, please refer to <xref target="SPI HAL IOCTL Code" text="SPI IOCTL Code" />.
  *************************************************************************************************************************************/
typedef enum
{
    /****************************************************************************************************************
      * Get the current SPI configuration parameters.
      * For detail description and usage of this control code, please refer to <xref target="SPI_IOCTL_GET_PARAM" />.
      ****************************************************************************************************************/
    SPI_IOCTL_GET_PARAM,
    /****************************************************************************************************************
      * Get the capability of current SPI hardware.
      * For detail description and usage of this control code, please refer to <xref target="SPI_IOCTL_QUERY_CAPABILITY" />.
      ****************************************************************************************************************/
    SPI_IOCTL_QUERY_CAPABILITY,
    /*************************************************************************************************************************
      * Query supported SPI modes.
      * For detail description and usage of this control code, please refer to <xref target="SPI_IOCTL_QUERY_MODE_SUPPORT" />.
      *************************************************************************************************************************/
    SPI_IOCTL_QUERY_MODE_SUPPORT,
    /******************************************************************************************************************
      * Query SPI base clock.
      * For detail description and usage of this control code, please refer to <xref target="SPI_IOCTL_QUERY_CLOCK" />.
      ******************************************************************************************************************/
    SPI_IOCTL_QUERY_CLOCK,
    /***************************************************************************************************************
      * Set and configure SPI mode.
      * For detail description and usage of this control code, please refer to <xref target="SPI_IOCTL_SET_MODE" />.
      ***************************************************************************************************************/
    SPI_IOCTL_SET_MODE,
    /***************************************************************************************************************
      * Get SPI mode settings.
      * For detail description and usage of this control code, please refer to <xref target="SPI_IOCTL_GET_MODE" />.
      ***************************************************************************************************************/
    SPI_IOCTL_GET_MODE,
    /***************************************************************************************************************
      * Get SPI driving current.
      * For detail description and usage of this control code, please refer to <xref target="SPI_IOCTL_GET_DRIVING_CURRENT" />.
      ***************************************************************************************************************/
    SPI_IOCTL_GET_DRIVING_CURRENT,
    /***************************************************************************************************************
      * Set SPI driving current.
      * For detail description and usage of this control code, please refer to <xref target="SPI_IOCTL_SET_DRIVING_CURRENT" />.
      ***************************************************************************************************************/
    SPI_IOCTL_SET_DRIVING_CURRENT
} SPI_IOCTL_CODE;

/* SPI mode. Including special modes provided by SPI controller.
*/
typedef enum
{
    /* Deassert mode. SPI CS pin will be pulled low and high for each byte during transmission. */
    SPI_MODE_DEASSERT,
    /* Pause mode. SPI CS pin is pulled low and keeps until specific amount of transfers have been finished. */
    SPI_MODE_PAUSE,
    /* Ultra high mode. Raise DMA priority during DMA transmission. */
    SPI_MODE_ULTRA_HIGH,
    /* Slow down mode. Slow down SPI DMA speed during DMA transmission. */
    SPI_MODE_SLOW_DOWN,
    /* Get tick delay mode. This mode is used to tuning SPI timing. */
    SPI_MODE_GET_TICK
} SPI_HAL_MODE;

/*********************************
  * SPI get tick delay mode enums.
  *********************************/
typedef enum
{
    /* Delay SCK for one clock. */
    SPI_GET_TICK_DELAY1 = 1,
    /* Delay SCK for two clocks. */
    SPI_GET_TICK_DELAY2 = 2
} SPI_GET_TICK_E;

/* SPI transimssion bit order definition. */
typedef enum
{
    /* Transfer LSB first. */
    SPI_MSBF_LSB = 0,
    /* Transfer MSB first. */
    SPI_MSBF_MSB = 1
} SPI_MSBF_E;

/* SPI clock polarity definition. */
typedef enum
{
    /* CPOL = 0. */
    SPI_CPOL_B0 = 0,
    /* CPOL = 1. */
    SPI_CPOL_B1 = 1
} SPI_CPOL_E;

/* SPI clock format definition. */
typedef enum
{
    /* CPHA = 0. */
    SPI_CPHA_B0 = 0,
    /* CPHA = 1. */
    SPI_CPHA_B1 = 1
} SPI_CPHA_E;

/* SPI data transfer byte order definition. */
typedef enum
{
    /* Use little endian. */
    SPI_ENDIAN_LITTLE = 0,
    /* Use big endian. */
    SPI_ENDIAN_BIG = 1
} SPI_ENDIAN_E;

/************************************
  * SPI configuration parameters.
  * 
  * Remarks
  * <img name="spi_timing_diagram" />
  ************************************/
typedef struct
{
    /* CS setup time. Unit in count of SPI base clock. Range(0-255).
       The chip select setup time = (cs_setup_time+1)*CLK_PERIOD, where CLK_PERIOD is the cycle time of the clock the SPI engine adopts. */
    kal_uint32 cs_setup_time;
    /* CS hold time. Unit in count of SPI base clock. Range(0-255).
       The chip select hold time = (cs_hold_time+1)*CLK_PERIOD. */
    kal_uint32 cs_hold_time;
    /* CS idle time. Unit in count of SPI base clock. Range(0-255).
       The chip select idle time between consecutive transaction = (cs_idle_time+1)*CLK_PERIOD. */
    kal_uint32 cs_idle_time;
    /* SCK clock low time. Unit in count of SPI base clock. Range(0-255).
       The SCK clock low time = (clk_low_time+1)*CLK_PERIOD. */
    kal_uint32 clk_low_time;
    /* SCK clock high time. Unit in count of SPI base clock. Range(0-255).
       The SCK clock high time = (clk_high_time+1)*CLK_PERIOD. */
    kal_uint32 clk_high_time;
    /* Bit order setting for SPI output. */
    SPI_MSBF_E tx_msbf;
    /* Bit order setting for SPI input. */
    SPI_MSBF_E rx_msbf;
    /* Byte order setting for SPI output. */
    SPI_ENDIAN_E tx_endian;
    /* Byte order setting for SPI input. */
    SPI_ENDIAN_E rx_endian;
    /* SPI clock polarity. */
    SPI_CPOL_E clk_polarity;
    /* SPI clock format. */
    SPI_CPHA_E clk_fmt;
} SPI_CONFIG_PARAM_T;

/* This structure is used as the parameter of SPI_IOCTL_QUERY_CAPABILITY.
*/
typedef struct
{
    /* Minimum value for cs setup time. */
    kal_uint32 cs_setup_time_min;
    /* Maximum value for cs setup time. */
    kal_uint32 cs_setup_time_max;
    /* Minimum value for cs hold time. */
    kal_uint32 cs_hold_time_min;
    /* Maximum value for cs hold time. */
    kal_uint32 cs_hold_time_max;
    /* Minimum value for cs idle time. */
    kal_uint32 cs_idle_time_min;
    /* Maximum value for cs idle time. */
    kal_uint32 cs_idle_time_max;
    /* Minimum value for clock low time. */
    kal_uint32 clk_low_time_min;
    /* Maximum value for clock low time. */
    kal_uint32 clk_low_time_max;
    /* Minimum value for clock high time. */
    kal_uint32 clk_high_time_min;
    /* Maximum value for clock high time. */
    kal_uint32 clk_high_time_max;
    /* Minimum value for transfer length. */
    kal_uint32 transfer_length_min;
    /* Maximum value for transfer length. */
    kal_uint32 transfer_length_max;
    /* Minimum value for transfer count. */
    kal_uint32 transfer_count_min;
    /* Maximum value for transfer count. */
    kal_uint32 transfer_count_max;
    /* Minimum value for slow down threshold. */
    kal_uint32 slow_down_thresh_min;
    /* Maximum value for slow down threshold. */
    kal_uint32 slow_down_thresh_max;
    /* Minimum value for ultra high threshold. */
    kal_uint32 ultra_high_thresh_min;
    /* Maximum value for ultra high threshold. */
    kal_uint32 ultra_high_thresh_max;
    /* Minimum value for driving current. */
    kal_uint32 driving_current_min;
    /* Maximum value for driving current. */
    kal_uint32 driving_current_max;
} SPI_CAPABILITY_T;

/* This structure is used as the parameter of SPI_IOCTL_QUERY_MODE_SUPPORT.
*/
typedef struct
{
    /* [IN] Specify a SPI mode. */
    SPI_HAL_MODE mode;
    /* [OUT] Return whether the specific mode is supported. */
    kal_bool bSupport;
} SPI_QUERY_MODE_T;

/* This structure is used as the parameter of SPI_IOCTL_QUERY_CLOCK.
   It contains the clock frequency which is used to calculate SPI timing parameters.
*/
typedef struct
{
    /* [OUT] SPI base clock. Unit in MHz. */
    kal_uint32 clock;
} SPI_QUERY_CLOCK_T;

/********************************************************************
  * This structure is used as the parameter of SPI_IOCTL_SET_MODE and SPI_IOCTL_GET_MODE.
  ********************************************************************/
typedef struct
{
    /* [IN] Specify a SPI mode. */
    SPI_HAL_MODE mode;
    /* [IN/OUT] Specify whether the mode is enabled.
       For SPI_IOCTL_SET_MODE, it is an input parameter.
       For SPI_IOCTL_GET_MODE, it is an output parameter.
    */
    kal_bool bEnable;
    /* [IN/OUT] The parameter for the specific mode.
       The meaning of this parameter depends on the mode to be set/get.
    */
    kal_uint32 Param;
} SPI_MODE_T;

/* This structure is used as the parameter of SPI_MODE_T for SPI_MODE_SLOW_DOWN.
   If user uses SPI_IOCTL_SET_MODE or SPI_IOCTL_GET_MODE to set/get SPI DMA slow down mode, the Param in SPI_MODE_T is a pointer to this structure. 
*/
typedef struct
{
    /* This parameter decides whether to enable splitting burst one 4-beat read/write access into four single read/write accesses.*/
    kal_bool split_burst_enable;
    /* This parameter is a counter to configure how many time units to send one request to GMC.*/
    kal_uint32 slow_down_thresh;
} SPI_SLOWDOWN_PARAM_T;

/* This structure is used as the parameter of SPI_IOCTL_GET_DRIVING_CURRENT and SPI_IOCTL_SET_DRIVING_CURRENT.
*/
typedef struct
{
    /* Indicates whether slew rate control is enabled. */
    kal_bool bEnableSlewRate;
    /* Driving current value.
       <b> <color Red>Note: This variable just indicates the value that is set in the hardware configuration register. It does not stands fot the actual driving current.
       Refer to related hardware spec for detail information.</b></color>
    */
    kal_uint32 driving_current;
} SPI_DRIVING_CURRENT_T;

/**************************************************************************************************************************************
  * Function
  * spi_open
  * Description
  * Open and get SPI handle.
  * Parameters
  * port :  [IN] SPI port. Zero based port index.
  * For <color Blue>MT6238</color>/<color Blue>MT6268</color>/<color Blue>MT6236</color>, only one port is supported. 
  * Returns
  * Return a SPI handle.
  * Example
  * <code>
  * SPI_HANDLE handle;
  * handle = spi_open(0);
  * </code>                                                                                                                            
  **************************************************************************************************************************************/
SPI_HANDLE spi_open(kal_uint32 port);

/********************************************************
  * Function
  * spi_close
  * Description
  * Release a SPI handle.
  * Parameters
  * handle :  [IN] SPI handle. Retrieved from spi_open().
  * Returns
  * Return a SPI result code.
  * Example
  * <code>
  * SPI_HANDLE handle;
  * handle = spi_open(0);
  * // SPI operations.
  * spi_close(handle);
  * </code>                                              
  ********************************************************/
SPI_RESULT spi_close(SPI_HANDLE handle);

/***********************************************************************
  * Function
  * spi_configure
  * Description
  * Configure SPI parameters including timing parameters and waveform parameters.
  * SPI parameters must be set before any SPI transmissions.
  * Parameters
  * handle :        [IN] SPI handle. Retrieved from spi_open().
  * pConfigParam :  [IN] SPI parameters. Refer to SPI_CONFIG_PARAM_T for details.
  * Returns
  * Return a SPI result code.
  * Example
  * <code>
  * SPI_HANDLE handle;
  * SPI_CONFIG_PARAM_T param;
  * handle = spi_open(0);
  * param.cs_setup_time = 5;
  * param.cs_hold_time = 5;
  * param.cs_idle_time = 5;
  * param.clk_low_time = 5;
  * param.clk_high_time = 5;
  * param.tx_mlsb = SPI_LSB;
  * param.rx_mlsb = SPI_LSB;
  * param.clk_polarity = SPI_CPOL_0;
  * param.clk_fmt = SPI_CPHA_0;
  * spi_configure(handle, &amp;param);
  * // ...
  * spi_close(handle);
  * </code>                                                             
  ***********************************************************************/
SPI_RESULT spi_configure(SPI_HANDLE handle, SPI_CONFIG_PARAM_T* pConfigParam);

/*******************************************************************************
  * Function
  * spi_write
  * Description
  * Fire a SPI transmission for output.
  * Parameters
  * handle :   [IN] SPI handle. Retrieved from spi_open().
  * pBuffer :  [IN] Data buffer for output.
  * length :   [IN] Data length for one package. Unit in bytes. <color Red><b>If count &gt; 1, length must be 4X.</b></color>
  * count :    [IN] Package count.<b> <color Red>If count &gt; 1, length must be 4X.</b></color>
  * fCB :      [IN] Specifies the callback function when the transmission completes.
  * If fCB is specified, SPI driver uses interrupt mode. This API is asynchronous.
  * If fCB is NULL, SPI drvier uses polling mode. This API becomes synchronous.
  * Returns
  * Return a SPI result code.
  * Example
  * <code>
  * SPI_HANDLE handle;
  * SPI_CONFIG_PARAM_T param;
  * handle = spi_open(0);
  * // ...
  * spi_configure(handle, &amp;param);
  * 
  * // Synchronous call.
  * spi_write(handle, spi_test_buffer1, 1024, 1, NULL);
  * 
  * // Asynchronous call.
  * spi_write(handle, spi_test_buffer1, 1024, 1, spi_test_cb);
  * // Wait for a event which is set in callback function.
  * // ...
  * spi_close(handle);
  * </code>                                                                     
  *******************************************************************************/
SPI_RESULT spi_write(SPI_HANDLE handle, void* pBuffer, kal_uint32 length, kal_uint32 count, SPI_CALLBACK fCB);

/*******************************************************************************
  * Function
  * spi_read
  * Description
  * Fire a SPI transmission for input.
  * Parameters
  * handle :   [IN] SPI handle. Retrieved from spi_open().
  * pBuffer :  [OUT] Data buffer for input.
  * length :   [IN] Data length for one package. Unit in bytes. <color Red><b>If count &gt; 1, length must be 4X.</b></color>
  * count :    [IN] Package count. <color Red><b>If count &gt; 1, length must be 4X.</b></color>
  * fCB :      [IN] Specifies the callback function when the transmission completes.
  * If fCB is specified, SPI driver uses interrupt mode. This API is asynchronous.
  * If fCB is NULL, SPI drvier uses polling mode. This API becomes synchronous.
  * Returns
  * Return a SPI result code.
  * Example
  * <code>
  * SPI_HANDLE handle;
  * SPI_CONFIG_PARAM_T param;
  * handle = spi_open(0);
  * // ...
  * spi_configure(handle, &amp;param);
  * 
  * // Synchronous call.
  * spi_read(handle, spi_test_buffer2, 1024, 1, NULL);
  * 
  * // Asynchronous call.
  * spi_read(handle, spi_test_buffer2, 1024, 1, spi_test_cb);
  * // Wait for a event which is set in callback function.
  * // ...
  * spi_close(handle);
  * </code>                                                                     
  *******************************************************************************/
SPI_RESULT spi_read(SPI_HANDLE handle, void* pBuffer, kal_uint32 length, kal_uint32 count, SPI_CALLBACK fCB);

/***********************************************************************************
  * Function
  * spi_readwrite
  * Description
  * Fire a SPI transmission for input and output. This transaction uses
  * duplex mode of SPI.
  * Parameters
  * handle :      [IN] SPI handle. Retrieved from spi_open().
  * pOutBuffer :  [IN] Data buffer for output.
  * pInBuffer :   [OUT] Data buffer for input.
  * length :      [IN] Data length for one package. Unit in bytes. <color Red><b>If count &gt; 1, length must be 4X.</b></color>
  * count :       [IN] Package count. <color Red><b>If count &gt; 1, length must be 4X.</b></color>
  * fCB :         [IN] Specifies the callback function when the transmission completes.
  * If fCB is specified, SPI driver uses interrupt mode. This API is asynchronous.
  * If fCB is NULL, SPI drvier uses polling mode. This API becomes synchronous.
  * Returns
  * Return a SPI result code.
  * Example
  * <code>
  * SPI_HANDLE handle;
  * SPI_CONFIG_PARAM_T param;
  * handle = spi_open(0);
  * // ...
  * spi_configure(handle, &amp;param);
  * 
  * // Synchronous call.
  * spi_readwrite(handle, spi_test_buffer1, spi_test_buffer2, 1024, 1, NULL);
  * 
  * // Asynchronous call.
  * spi_readwrite(handle, spi_test_buffer1, spi_test_buffer2, 1024, 1, spi_test_cb);
  * // Wait for a event which is set in callback function.
  * // ...
  * spi_close(handle);
  * </code>
  ***********************************************************************************/
SPI_RESULT spi_readwrite(SPI_HANDLE handle, void* pOutBuffer, void* pInBuffer, kal_uint32 length, kal_uint32 count, SPI_CALLBACK fCB);

/*****************************************************************************
  * Function
  * spi_power_ctrl
  * Description
  * Enable or disable SPI Controller power.
  * <textattr color="Red">This API is currently not implemented. SPI power will be turned on when calling spi_open() and turned off when calling</textattr> spi_close().
  * Parameters
  * handle :    [IN] SPI handle. Retrieved from spi_open().
  * bPowerOn :  [IN] Set KAL_TRUE to power on SPI Controller. Set KAL_FALSE to power off SPI Controller.
  * Returns
  * Return a SPI result code.
  * Example
  * <code>
  * SPI_HANDLE handle;
  * handle = spi_open(0);
  * spi_power_ctrl(handle, KAL_TRUE);
  * // SPI operations.
  * spi_power_ctrl(handle, KAL_FALSE);
  * spi_close(handle);
  * </code>                                                                   
  *****************************************************************************/
SPI_RESULT spi_power_ctrl(SPI_HANDLE handle, kal_bool bPowerOn);

/*****************************************************************************
  * Function
  * spi_ioctl
  * Description
  * IO Control for SPI driver.
  * A series of SPI control code is defined for extension usage. Refer to SPI_IOCTL_CODE.
  * Parameters
  * handle :  [IN] SPI handle. Retrieved from spi_open().
  * code :    [IN] SPI control code. Refer to SPI_IOCTL_CODE.
  * pParam :  [IN/OUT] Parameter for SPI IO Control. The definition depends on the specified control code. Refer to SPI_IOCTL_CODE.
  * Returns
  * Return a SPI result code.
  * The return value is SPI_RESULT_NOT_SUPPORTED if the current platform does not support the sepcific control code.
  * Example
  * <code>
  * SPI_HANDLE handle;
  * SPI_MODE_T SetMode;
  * handle = spi_open(0);
  * // Test for deassert mode.
  * SetMode.mode = SPI_MODE_DEASSERT;
  * SetMode.bEnable = KAL_TRUE;
  * spi_ioctl(handle, SPI_IOCTL_SET_MODE, &amp;SetMode);
  * spi_readwrite(handle, spi_test_buffer1, spi_test_buffer2, 1024, 1, NULL);
  * SetMode.bEnable = KAL_FALSE;
  * spi_ioctl(handle, SPI_IOCTL_SET_MODE, &amp;SetMode);
  * spi_close(handle);
  * </code>                                                                   
  *****************************************************************************/
SPI_RESULT spi_ioctl(SPI_HANDLE handle, SPI_IOCTL_CODE code, void* pParam);

#endif
#endif
