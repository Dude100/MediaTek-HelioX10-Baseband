#ifndef __HIF_HAL_H__
/* !ignore me! */
#define __HIF_HAL_H__

#include "kal_general_types.h"
#include "drv_features.h"

#ifdef DRV_HIF_SUPPORT

/* <GROUP CallBackFunctions>
   FUNCTION
   HIF_CALLBACK
   DESCRIPTION
   HIF callback function
   HIF callback function is called when HIF interrupt has arrived. It indicates HIF has finished the last data transfer.
   HIF callback function is called in the context of HISR.
*/
typedef void (*HIF_CALLBACK)(void);

/* HIF Handle.
   HIF handle can be retrieved from hif_open(). It is used for most HIF APIs.
*/
typedef kal_uint32 HIF_HANDLE;

/* HIF transfer type. 
   Defines the transfer type of HIF interface.
*/
typedef enum
{
    /* HIF transfer with A0=1. Use CPU to move data. */
    HIF_TYPE_A0H_CPU,
    /* HIF transfer with A0=1. Use DMA to transfer data. */
    HIF_TYPE_A0H_DMA,
    /* HIF transfer with A0=0. Use CPU to move data. */
    HIF_TYPE_A0L_CPU,
    /* HIF transfer with A0=0. Use DMA to transfer data. */
    HIF_TYPE_A0L_DMA,
} HIF_TYPE;

/* HIF result enum.
*/
typedef enum
{
    /* Indicates no error occurs in the last operation. */
    HIF_RESULT_OK,
    /* Indicates some errors have occured in the last operation. */
    HIF_RESULT_ERROR,
    /* Indicates the function is not supported on the current platform. */
    HIF_RESULT_NOT_SUPPORTED,
    /* Indicates the HIF handle is not valid. */
    HIF_RESULT_INVALID_HANDLE,
    /* Indicates the input argument is not valid. */
    HIF_RESULT_INVALID_ARGUMENT,
    /* Indicates that the HIF power was not turned on when making HIF transactions. */
    HIF_RESULT_HIF_NOT_POWER_ON,
    /* Indicates that the HIF power was not turned on when making HIF transactions. */
    HIF_RESULT_DMA_IS_BUSY
} HIF_RESULT;

/*************************************************************************************************************************************
  * HIF IOCTL code definition.
  * For detail description and usage of HIF control codes, please refer to <xref target="HIF HAL IOCTL Code" text="HIF IOCTL Code" />.
  *************************************************************************************************************************************/
typedef enum
{
    /****************************************************************************************************************
      * Get the current HIF configuration parameters.
      * For detail description and usage of this control code, please refer to <xref target="HIF_IOCTL_GET_PARAM" />.
      ****************************************************************************************************************/
    HIF_IOCTL_GET_PARAM,
    /****************************************************************************************************************
      * Set ultra high control for HIF.
      * For detail description and usage of this control code, please refer to <xref target="HIF_IOCTL_ULTRA_HIGH_CTRL" />.
      ****************************************************************************************************************/
    HIF_IOCTL_ULTRA_HIGH_CTRL,
    /****************************************************************************************************************
      * Query HIF timing support.
      * For detail description and usage of this control code, please refer to <xref target="HIF_IOCTL_QUERY_TIMING_SUPPORT" />.
      ****************************************************************************************************************/
    HIF_IOCTL_QUERY_TIMING_SUPPORT,
    /****************************************************************************************************************
      * Query HIF capabilities.
      * For detail description and usage of this control code, please refer to <xref target="HIF_IOCTL_QUERY_CAPABILITY" />.
      ****************************************************************************************************************/
    HIF_IOCTL_QUERY_CAPABILITY,
    /****************************************************************************************************************
      * Query HIF clock support.
      * For detail description and usage of this control code, please refer to <xref target="HIF_IOCTL_QUERY_CLOCK_SUPPORT" />.
      ****************************************************************************************************************/
    HIF_IOCTL_QUERY_CLOCK_SUPPORT,
    /****************************************************************************************************************
      * Query HIF power state.
      * For detail description and usage of this control code, please refer to <xref target="HIF_IOCTL_QUERY_POWER_STATE" />.
      ****************************************************************************************************************/
    HIF_IOCTL_QUERY_POWER_STATE,
    /****************************************************************************************************************
      * TD realtime support.
      * For detail description and usage of this control code, please refer to <xref target="HIF_IOCTL_REALTIME_REQUEST" />.
      ****************************************************************************************************************/
    HIF_IOCTL_REALTIME_CALLBACK
} HIF_IOCTL_CODE;

/**********************************
  * HIF configuration parameters.
  * 
  * Remarks
  * <img name="hif_write_timing" />
  * 
  * <img name="hif_read_timing" /> 
  **********************************/
typedef struct
{
    /* Chip Select (LPCE#) to Write Strobe (LWR#) setup time. */
    kal_uint32 hif_time_c2ws;
    /* Chip Select (LPCE#) to Write Strobe (LWR#) hold time. */
    kal_uint32 hif_time_c2wh;
    /* Write wait state time. */
    kal_uint32 hif_time_wst;
    /* Chip Select (LPCE#) to Read Strobe (LRD#) setup time. */
    kal_uint32 hif_time_c2rs;
    /* Chip Select (LPCE#) to Read Strobe (LRD#) hold time. */
    kal_uint32 hif_time_c2rh;
    /* Read latency time. */
    kal_uint32 hif_time_rlt;
    /* Chip Select high width. */
    kal_uint32 hif_time_chw;
    /* HIF base clock. Unit in MHz. */
    kal_uint32 hif_base_clk;
    /* HIF bus width. */
    kal_uint32 hif_bus_width;
} HIF_CONFIG_T;

/* This structure is used as the parameter of HIF_IOCTL_QUERY_TIMING_SUPPORT.
*/
typedef struct
{
    /* Indicates whether C2WS is supported. */
    kal_bool c2ws_support;
    /* Indicates whether C2WH is supported. */
    kal_bool c2wh_support;
    /* Indicates whether WST is supported. */
    kal_bool wst_support;
    /* Indicates whether C2RS is supported. */
    kal_bool c2rs_support;
    /* Indicates whether C2RH is supported. */
    kal_bool c2rh_support;
    /* Indicates whether CHW is supported. */
    kal_bool chw_support;
    /* Indicates whether RLT is supported. */
    kal_bool rlt_support;
} HIF_QUERY_TIMING_SUPPORT_T;

/* This structure is used as the parameter of HIF_IOCTL_QUERY_CLOCK_SUPPORT.
*/
typedef struct
{
    /* This array contains the supported clock frequencies. Unit in MHz. Value 0 indicates invalid clock frequency.*/
    kal_uint32 clock[4];
} HIF_QUERY_CLOCK_SUPPORT_T;

/* This structure is used as the parameter of HIF_IOCTL_QUERY_CAPABILITY.
*/
typedef struct
{
    /* Minimum value for HIF transfer length. */
    kal_uint32 transfer_length_min;
    /* Maximum value for HIF transfer length. */
    kal_uint32 transfer_length_max;
} HIF_CAPABILITY_T;

/* This structure is used as the parameter of HIF_IOCTL_ULTRA_HIGH_CTRL.
*/
typedef struct
{
    /* Enable ultra high signal during HIF transaction. */
    kal_bool ultra_high_en;
} HIF_ULTRA_HIGH_CTRL_T;


/* This structure is used as the parameter of HIF_IOCTL_QUERY_POWER_STATE.
*/
typedef struct
{
    /* HIF power state. */
    kal_bool hif_power_on;
} HIF_POWER_STATE_T;

/* This structure is used as the parameter of HIF_IOCTL_REALTIME_CALLBACK.
*/
typedef struct
{
    /* Enable realtime request,Call HIF callback function(hif_hisr) at LISR level. */
    kal_bool realtime_callback_en;
} HIF_REALTIME_CALLBACK_T;

/**************************************************************************************************************************************
  * Function
  * hif_init
  * Description
  * Initialize HIF hardware and structures.
  * Returns
  * None.
  * Remarks
  * <color Red>This function is called in system initialization. HIF user does not need to call this function.</color>
  **************************************************************************************************************************************/
void hif_init(void);

/**************************************************************************************************************************************
  * Function
  * hif_open
  * Description
  * Open and get HIF handle.
  * Parameters
  * port :  [IN] HIF port. Zero based port index.
  * Returns
  * Return a HIF handle.
  * Example
  * <code>
  * HIF_HANDLE handle;
  * handle = hif_open(0);
  * </code>                                                                                                                            
  **************************************************************************************************************************************/
HIF_HANDLE hif_open(kal_uint32 port);

/********************************************************
  * Function
  * hif_close
  * Description
  * Release a HIF handle.
  * Parameters
  * handle :  [IN] HIF handle. Retrieved from hif_open().
  * Returns
  * Return a HIF result code.
  * Example
  * <code>
  * HIF_HANDLE handle;
  * handle = hif_open(0);
  * // HIF operations.
  * hif_close(handle);
  * </code>                                              
  ********************************************************/
HIF_RESULT hif_close(HIF_HANDLE handle);

/***********************************************************************
  * Function
  * hif_config
  * Description
  * Configure HIF timing parameters.
  * HIF parameters must be set before any HIF transmissions.
  * Parameters
  * handle :        [IN] HIF handle. Retrieved from hif_open().
  * pConfigParam :  [IN] HIF parameters. Refer to HIF_CONFIG_T for details.
  * Returns
  * Return a HIF result code.
  * Example
  * <code>
  * HIF_HANDLE handle;
  * HIF_CONFIG_T hif_config_param;
  * handle = hif_open(0);
  * hif_config_param.hif_time_c2ws = 3;
  * hif_config_param.hif_time_c2wh = 2;
  * hif_config_param.hif_time_wst = 15; 
  * hif_config_param.hif_time_c2rs = 4;
  * hif_config_param.hif_time_c2rh = 0;
  * hif_config_param.hif_time_rlt = 0x1f; 
  * hif_config_param.hif_base_clk = 122; 
  * hif_config_param.hif_bus_width = 16;
  * hif_config(handle, &hif_config_param);     
  * // ...
  * hif_close(handle);
  * </code>                                                             
  ***********************************************************************/
HIF_RESULT hif_config(HIF_HANDLE handle, HIF_CONFIG_T* pConfigParam);

/*******************************************************************************
  * Function
  * hif_write
  * Description
  * Fire a HIF transmission for output.
  * Parameters
  * handle :   [IN] HIF handle. Retrieved from hif_open().
  * type :     [IN] HIF transfer type. Refer to HIF_TYPE for details.
  * addr :     [IN] Data buffer address for output.
  * size :     [IN] Data length for HIF transfer. Unit in bytes.
  * fCB :      [IN] Specifies the callback function when the transmission completes.
  * If fCB is specified, HIF driver uses interrupt mode. This API is asynchronous.
  * If fCB is NULL, HIF drvier uses polling mode. This API becomes synchronous.
  * Returns
  * Return a HIF result code.
  * Remarks
  * If type is set to HIF_TYPE_A0H_CPU or HIF_TYPE_A0L_CPU, fCB is ignored. HIF driver works synchronous in CPU mode.
  * Example
  * <code>
  * HIF_HANDLE handle;
  * handle = hif_open(0);
  * // ...
  * 
  * // Synchronous call.
  * hif_write(handle, HIF_TYPE_A0H_CPU, hif_test_buffer, 1024, NULL);
  * 
  * // Asynchronous call.
  * hif_write(handle, HIF_TYPE_A0H_DMA, hif_test_buffer, 1024, hif_test_cb);
  * // Wait for a event which is set in callback function.
  * // ...
  * hif_close(handle);
  * </code>                                                                     
  *******************************************************************************/
HIF_RESULT hif_write(HIF_HANDLE handle, HIF_TYPE type, kal_uint32 addr, kal_uint32 size, HIF_CALLBACK fCB);

/*******************************************************************************
  * Function
  * hif_read
  * Description
  * Fire a HIF transmission for input.
  * Parameters
  * handle :   [IN] HIF handle. Retrieved from hif_open().
  * type :     [IN] HIF transfer type. Refer to HIF_TYPE for details.
  * addr :     [IN] Data buffer address for input.
  * size :     [IN] Data length for HIF transfer. Unit in bytes.
  * fCB :      [IN] Specifies the callback function when the transmission completes.
  * If fCB is specified, HIF driver uses interrupt mode. This API is asynchronous.
  * If fCB is NULL, HIF drvier uses polling mode. This API becomes synchronous.
  * Returns
  * Return a HIF result code.
  * Remarks
  * If type is set to HIF_TYPE_A0H_CPU or HIF_TYPE_A0L_CPU, fCB is ignored. HIF driver works synchronous in CPU mode.
  * Example
  * <code>
  * HIF_HANDLE handle;
  * handle = hif_open(0);
  * // ...
  * 
  * // Synchronous call.
  * hif_read(handle, HIF_TYPE_A0H_CPU, hif_test_buffer, 1024, NULL);
  * 
  * // Asynchronous call.
  * hif_read(handle, HIF_TYPE_A0H_DMA, hif_test_buffer, 1024, hif_test_cb);
  * // Wait for a event which is set in callback function.
  * // ...
  * hif_close(handle);
  * </code>                                                                     
  *******************************************************************************/
HIF_RESULT hif_read(HIF_HANDLE handle, HIF_TYPE type, kal_uint32 addr, kal_uint32 size, HIF_CALLBACK fCB);

/*****************************************************************************
  * Function
  * hif_power_ctrl
  * Description
  * Enable or disable HIF hardware power.
  * Parameters
  * handle :    [IN] HIF handle. Retrieved from hif_open().
  * bPowerOn :  [IN] Set KAL_TRUE to power on HIF hardware. Set KAL_FALSE to power off HIF hardware.
  * Returns
  * Return a HIF result code.
  * Example
  * <code>
  * HIF_HANDLE handle;
  * handle = hif_open(0);
  * hif_power_ctrl(handle, KAL_TRUE);
  * // HIF operations.
  * hif_power_ctrl(handle, KAL_FALSE);
  * hif_close(handle);
  * </code>                                                                   
  *****************************************************************************/
HIF_RESULT hif_power_ctrl(HIF_HANDLE handle, kal_bool bPowerOn);

/*****************************************************************************
  * Function
  * hif_ioctl
  * Description
  * IO Control for HIF driver.
  * A series of HIF control code is defined for extension usage. Refer to HIF_IOCTL_CODE.
  * Parameters
  * handle :  [IN] HIF handle. Retrieved from hif_open().
  * code :    [IN] HIF control code. Refer to HIF_IOCTL_CODE.
  * pParam :  [IN/OUT] Parameter for HIF IO Control. The definition depends on the specified control code. Refer to HIF_IOCTL_CODE.
  * Returns
  * Return a HIF result code.
  * The return value is HIF_RESULT_NOT_SUPPORTED if the current platform does not support the sepcific control code.
  * Example
  * <code>
  * HIF_HANDLE handle;
  * HIF_CONFIG_T config;
  * handle = hif_open(0);
  * hif_ioctl(handle, HIF_IOCTL_GET_PARAM, &amp;config);
  * hif_close(handle);
  * </code>                                                                   
  *****************************************************************************/
HIF_RESULT hif_ioctl(HIF_HANDLE handle, HIF_IOCTL_CODE code, void* pParam);

#endif

#endif
