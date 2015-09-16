#ifndef __HMU_DRV_FUNC_H__
#define __HMU_DRV_FUNC_H__
#include "kal_general_types.h"
#include "dcl.h"

/*************************************************************************
 * HMU Parameters Definition
 *************************************************************************/
 /*Maximum number of emulation devices managed by HMU in normal booting*/
#define HMU_MAX_EMUDEVNUM 				10
 /*Maximum number of emulation devices managed by HMU in Host Detection booting*/
#define HMU_MAX_HD_EMUDEVNUM			3
/*Maximum length of the HIF core's extended information */
#define HMU_MAX_HIF_EXTINFO_SIZE		512
/*Maximum length of each emulation device's extended information */
#define HMU_MAX_EMUDEV_EXTINFO_SIZE		64

#define HMU_PREFIX		"HMU"
#define HMU_FAIL_PREFIX	"HMU-FAIL"


/* Port number for DHL debugging channel. */
#define HMU_EXCEPT_COM_PORT uart_port_usb2

/*************************************************************************
 * Type Definitions
 *************************************************************************/
/*The definitions abouthe HIF event group */
/* Name */
#define HIF_DRV_EG_NAME "HIF_DRV_EG"

/* Event */
#define HIF_DRV_EG_HIF_TICK_EVENT       0x80000000  /* HIF tick to trigger USBCORE to check GPD. */
#define HIF_DRV_EG_HIF_TICK_EVENT_SDIO  0x08000000  /* HIF tick to trigger SDIOCORE to check GPD. */
#define HIF_DRV_EG_HIF_TICK_EVENT_UART  0x00800000  /* HIF tick to trigger UARTCORE to check GPD. */
#define HIF_DRV_EG_HIF_TICK_EVENT_CLDMA 0x00080000  /* HIF tick to trigger CLDMACORE to check GPD. */
#define HIF_DRV_EG_USBC_IND_EVENT       0x40000000  /* To allow USBCORE to indicate device events or setup packet up to USBCLASS in task context. */
#define HIF_DRV_EG_UART_IND_EVENT       0x00400000  /* To allow UARTCORE to indicate port open in task context. */
#define HIF_DRV_EG_ALL_EVENT            0xFFFFFFFF  /* All events associated with the event group managed by HMU. */

/* HIF tick to trigger HIFCORE to check GPD. Add HIF tick event must modify this mask*/
#define HIF_DRV_EG_HIF_TICK_EVENT_GROUP ( HIF_DRV_EG_HIF_TICK_EVENT \
                                        | HIF_DRV_EG_HIF_TICK_EVENT_SDIO \
                                        | HIF_DRV_EG_HIF_TICK_EVENT_UART \
                                        | HIF_DRV_EG_HIF_TICK_EVENT_CLDMA \
                                        )

/** 
 * @brief enumeration for HMU Emulation Device types
 */
typedef enum
{
	HMU_USB_DEV_MIN					= 0,	
	HMU_USB_DEV_ACM, hmu_usb_dev_cdcacm = HMU_USB_DEV_ACM,
	HMU_USB_DEV_ECM, hmu_usb_dev_ecm = HMU_USB_DEV_ECM,
	HMU_USB_DEV_MBIM, hmu_usb_dev_mbim = HMU_USB_DEV_MBIM,
	HMU_USB_DEV_CDROM, hmu_usb_dev_cdrom = HMU_USB_DEV_CDROM,
	HMU_USB_DEV_DISK, hmu_usb_dev_disk = HMU_USB_DEV_DISK,	
	HMU_USB_DEV_RNDIS, hmu_usb_dev_rndis = HMU_USB_DEV_RNDIS,
#ifdef __USB_MSD_SUPPORT__
	HMU_USB_DEV_MSD,hmu_usb_dev_msd = HMU_USB_DEV_MSD,
#endif
	HMU_USB_DEV_MAX,	

	HMU_MOBILE_DEV_MIN				= 20,
	HMU_MOBILE_DEV_COM 	,
	HMU_MOBILE_DEV_ETH ,
	HMU_MOBILE_DEV_IP ,
	HMU_MOBILE_DEV_IPC,
	HMU_MOBILE_DEV_MB ,	
	HMU_MOBILE_DEV_MAX ,		

	HMU_EXT_DEV_MIN					= 40 ,		
	HMU_EXT_DEV_UART 	,		
	HMU_EXT_DEV_MAX 	,		

	HMU_DEV_NONE					= 0x7fffffff,	
}hmuEmuDeviceType_enum;

/** 
 * @brief enumeration for HMU HIFCORE Init function types. Here we define both of init functions and post init functions 
 */
typedef enum
{	
//  The declaration part for the type of init/deinit functions
	HMU_HIFCORE_MIN			= 0,	
	HMU_HIFCORE_USB ,
	HMU_HIFCORE_SDIO ,	
	HMU_HIFCORE_CCIF ,
    HMU_HIFCORE_CAIF ,	
    HMU_HIFCORE_CLDMA ,
    HMU_HIFCORE_CCCI ,
	HMU_HIFCORE_MAX , 
	
	HMU_HIFCORE_TYPE_NONE			= 0x7fffffff,	
}hmuHifCoreType_enum;

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
#endif

/*************************************************************************
 * Struct Definitions
 *************************************************************************/
/** 
 * @name: HMU_EMUDEV_INFO_STRUCT
 * @brief the hmu structure for emulation device 
 */
typedef struct HMU_EMUDEV_INFO_STRUCT
{	
	/* the emulation device type supported in LTE HIF */
	hmuEmuDeviceType_enum    dev_type;
	/* the mapping between the emulation device and it's upper layer tunnel */
	kal_uint32 			dev_mapping;		
	/* reserve in NVRAM space. next pointer point to the next emulation device in device list. Null means no next device  */
	union {
		void 								*reserve ;
		struct HMU_EMUDEV_INFO_STRUCT		*next ;  // Not use in NVRAM 
	} u ;	
	/* the length of extra device-specific information */
	kal_uint32			ext_devinfo_len;
	/* the pointer to extra device-specific information */
	kal_char			ext_devinfo[HMU_MAX_EMUDEV_EXTINFO_SIZE];
}hmu_emudev_info;

/** 
 * @name: HMU_CONF_STRUCT_STRUCT
 * @brief the hmu structure for HMU main structure in normal booting, and the configuration is loaded from NVRAM_EF_HMU_CONFIG_LID.
 */
typedef struct HMU_CONF_STRUCT_STRUCT
{	
	/* total device number defined configuration files */
	kal_uint32    		dev_num;	
	/* the length of extra hif specific information*/
	kal_uint32			ext_hifinfo_len;
	/* the pointer to extra hif specific information*/
	kal_char			ext_hifinfo[HMU_MAX_HIF_EXTINFO_SIZE];
	/* number of device info list to introduce the device information of the configured devices*/
	hmu_emudev_info 	dev_info[HMU_MAX_EMUDEVNUM];
}hmu_conf_struct;

/** 
 * @name: HMU_HD_CONF_STRUCT_STRUCT
 * @brief the hmu structure for HMU main structure in Host Detection booting, and the configuration is loaded from NVRAM_EF_HMU_HD_CONFIG_LID.
 */
typedef struct HMU_HD_CONF_STRUCT_STRUCT
{	
	kal_uint32    		dev_num;	
	kal_uint32			ext_hifinfo_len;
	kal_char			ext_hifinfo[HMU_MAX_HIF_EXTINFO_SIZE];
	hmu_emudev_info 	dev_info[HMU_MAX_HD_EMUDEVNUM];
}hmu_hd_conf_struct;

/*
 * @brief: upper layer device module exception mode initialization function 
 *         it is used for the case that an exception happens before hmu_init() completed
 *
 * @return KAL_TRUE if caller is allowed to proceed the exception flow
 *         KAL_FALSE otherwise
 */
typedef kal_bool (*uldrv_except_init)(kal_uint32 dev_mapping, kal_uint32 ext_devinfo_len, kal_char *ext_devinfo);

/** 
 * @name: _HMU_ULDRV_EXCEPT_INITFUNC_STRUCT
 *
 * @brief the structure is for upper layer device module to register its 
 *        exception mode initialization callback function
 */
typedef struct _HMU_ULDRV_EXCEPT_INITFUNC_STRUCT {
	kal_uint32                      port_id;
	uldrv_except_init               except_init_func;
} hmu_uldrv_except_initfunc ;

typedef kal_int32 (*ul_drv_init)(kal_uint32 dev_mapping, kal_uint32 ext_devinfo_len, kal_char * ext_devinfo) ;

/** 
 * @name: _HMU_HIFCORE_INITFUNC_STRUCT
 * @brief the structure for Init function and hif emu device types registration table
 */
typedef struct _HMU_ULDRV_INITFUNC_STRUCT {
	hmuEmuDeviceType_enum			dev_type;
	ul_drv_init				init_func;
} hmu_uldrv_initfunc ;

typedef kal_int32 (*hif_core_init)(kal_uint32 dev_num, hmu_emudev_info *emudev_info, kal_uint32 ext_hifinfo_len, kal_char * ext_hifinfo) ;

/** 
 * @name: _HMU_HIFCORE_INITFUNC_STRUCT
 * @brief the structure for Init function and hif core types registration table
 */
typedef struct _HMU_HIFCORE_INITFUNC_STRUCT {
	hmuHifCoreType_enum			hifcore_type;
	hif_core_init				init_func;
} hmu_hifcore_initfunc ;

/** 
 * @name: _HMU_TICK_INTERVAL_STRUCT
 * @brief the structure for set hif event trigger interval
 */
typedef struct _HMU_TICK_INTERVAL_STRUCT
{
    kal_uint32 hif_event;
    kal_uint32 hif_event_tick_count;
    kal_uint32 hif_current_tick;
} hmu_tick_interval;


/** 
 * @name: DECLARE_HMU_ULDRV_EXCEPT_INIT_FUNC
 * @brief This macro is used to declare the upper layer device module exception initialization functions which will be linked in HMU registration table
 */
#define DECLARE_HMU_ULDRV_EXCEPT_INIT_FUNC(_funcName) \
	extern kal_bool _funcName(kal_uint32 dev_mapping, kal_uint32 ext_devinfo_len, kal_char *ext_devinfo) ;

#endif /*__HMU_DRV_FUNC_H__*/
