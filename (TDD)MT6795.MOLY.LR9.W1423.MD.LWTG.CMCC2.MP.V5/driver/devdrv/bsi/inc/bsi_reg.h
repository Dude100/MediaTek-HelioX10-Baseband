#ifndef __BSI_REG_H__
#define __BSI_REG_H__

#include <reg_base.h>
#include <irqid.h>

#define BSI_MAC_BASE                    BASE_ADDR_BSI_MAC_PMIC
#define BSI_MAC_CTRL_REG                (BSI_MAC_BASE + 0x00)
#define BSI_MAC_WDATA_REG               (BSI_MAC_BASE + 0x04)
#define BSI_MAC_RDINT_REG               (BSI_MAC_BASE + 0x08)
#define BSI_MAC_RDATA_3100_REG          (BSI_MAC_BASE + 0x0C)
#define BSI_MAC_RDATA_3532_REG          (BSI_MAC_BASE + 0x10)

#define BSI_APB2CRF_BASE                BASE_ADDR_BSI_APB2CRF_PMIC
#define BSI_APB2CRF_IMM_CTRL_REG        (BSI_APB2CRF_BASE + 0x00)
#define BSI_APB2CRF_IMM_WDATA_REG       (BSI_APB2CRF_BASE + 0x04)
#define BSI_APB2CRF_IMM_RDINT_REG       (BSI_APB2CRF_BASE + 0x08)
#define BSI_APB2CRF_IMM_RDATA_3100_REG  (BSI_APB2CRF_BASE + 0x0C)
#define BSI_APB2CRF_IMM_RDATA_3532_REG  (BSI_APB2CRF_BASE + 0x10)

#define BSISPI_BASE                     BASE_ADDR_BSISPI_PMIC
#define BSISPI_CODA_VERSION_REG         (BSISPI_BASE + 0x00)
#define BSISPI_PORT_PARAM_REG           (BSISPI_BASE + 0x10)
#define BSISPI_SW_MODE_REG              (BSISPI_BASE + 0x14)
#define BSISPI_CLSNINT_REG              (BSISPI_BASE + 0x18)
#define BSISPI_IC0_PARAM1_REG           (BSISPI_BASE + 0x20)
#define BSISPI_IC0_PARAM2_REG           (BSISPI_BASE + 0x24)
#define BSISPI_IC1_PARAM1_REG           (BSISPI_BASE + 0x28)
#define BSISPI_IC1_PARAM2_REG           (BSISPI_BASE + 0x2C)
//#define BSISPI_LOG_WPTR_REG             (BSISPI_BASE + 0x30) // Not existed in PMIC SPICTRL
//#define BSISPI_SRAM_DEL_DEL_REG         (BSISPI_BASE + 0x40) // Not existed in PMIC SPICTRL

#endif  /* end of __BSI_REG_H__ */
