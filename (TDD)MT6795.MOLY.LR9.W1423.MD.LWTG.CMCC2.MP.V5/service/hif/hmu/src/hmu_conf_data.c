#include "hmu_conf_data.h"

/* For HIF to set tick event interval, if necessary */
hmu_tick_interval hmu_tick_interval_table[]=
{
 /* {event,  event tick interval + 1 } */
//	    {HIF_DRV_EG_HIF_TICK_EVENT_UART, 10},
#if defined(__MODEM_CARD__) && !defined(__TRADITIONAL_MODEM_CARD__)
    {HIF_DRV_EG_HIF_TICK_EVENT_CLDMA, 100},
#endif
    {0,0} // add before this line
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#if __USB_ACM_SUPPORT__
DECLARE_HMU_ULDRV_EXCEPT_INIT_FUNC(cdcacm_hmu_except_init) ;
#endif
#if __HIF_UART_SUPPORT__
DECLARE_HMU_ULDRV_EXCEPT_INIT_FUNC(uart_hmu_except_init) ;
#endif
#if __HIF_CCCI_SUPPORT__
DECLARE_HMU_ULDRV_EXCEPT_INIT_FUNC(ccci_except_init_hmu) ;
#endif

hmu_uldrv_except_initfunc uldrv_except_init_func_table[] = {
#if __USB_ACM_SUPPORT__
    {uart_port_usb2, 		    cdcacm_hmu_except_init},
#endif
#if __HIF_UART_SUPPORT__
    {uart_port1     ,           uart_hmu_except_init},
#endif
#if __HIF_CCCI_SUPPORT__ && !defined(__MODEM_CARD__)
    {uart_port_dhl_sp_expt,     ccci_except_init_hmu},
#endif
} ;
unsigned int uldrv_except_init_func_table_num = sizeof(uldrv_except_init_func_table)/sizeof(hmu_uldrv_except_initfunc) ;

