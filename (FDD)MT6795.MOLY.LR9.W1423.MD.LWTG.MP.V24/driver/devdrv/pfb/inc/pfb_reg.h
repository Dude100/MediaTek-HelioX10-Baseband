
#ifndef __PFB_REG_H__
#define __PFB_REG_H__

#include <reg_base.h>

#ifdef MT6290

    #define REG_PFB_CTRL         (BASE_ADDR_MDMCUMISC + 0x0C)
    #define REG_PFB_TOTAL_CNT    (BASE_ADDR_MDMCUMISC + 0x18)

#elif (defined(MT6595) || defined(MT6752))

    #define MD_MCU2EMI_CON0      (BASE_ADDR_MDCONFIG + 0x0200)
    #define MD_MCU2EMI_STATUS0   (BASE_ADDR_MDCONFIG + 0x0204)
    #define MD_PFBUFFER_STATUS2  (BASE_ADDR_MDCONFIG + 0x0218)

#endif

#endif /* __PFB_REG_H__ */
