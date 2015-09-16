
#ifndef __DRV_BUSERR_H__
#define __DRV_BUSERR_H__

#include "reg_base.h"
#include "kal_general_types.h"

extern void bus_err_LISR(void);
extern kal_int32 bus_err_status_init(void);

#define MD_DEC_ERR_CTL (BASE_ADDR_MDINFRAMISC+ 0x10)
#define MD_DEC_ERR_CTL_INI_VAL (0x10005)
#define MD_DEC_ERR_ADDR (BASE_ADDR_MDINFRAMISC+ 0x14)
#define MD_DEC_ERR_TYPE (BASE_ADDR_MDINFRAMISC+ 0x18)
#define MD_DEC_ERR_TYPE_RESET (0x1F)

#define AP_DEC_ERR_CTL (BASE_ADDR_APMISC+ 0x10)
#define AP_DEC_ERR_CTL_INI_VAL (0xFE0)
#define AP_DEC_ERR_ADDR (BASE_ADDR_APMISC+ 0x2C)

#define AP_AHB_OWN (BASE_ADDR_MDCFGCTL + 0x30)

#endif /* end of __DRV_BUSERR_H__ */

