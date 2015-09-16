#ifndef __EINT_HW_H__
#define __EINT_HW_H__
#include "drv_comm.h"


#define GPIOMUX_BASE_ADDR				BASE_ADDR_MDGPIOMUX

#define GPIOMUX_EINT_SRC1		((volatile unsigned int*)(GPIOMUX_BASE_ADDR + 0x1000))
#define GPIOMUX_EINT_SRC2		((volatile unsigned int*)(GPIOMUX_BASE_ADDR + 0x1004))
#define GPIOMUX_EINT_SRC3		((volatile unsigned int*)(GPIOMUX_BASE_ADDR + 0x1008))
#define GPIOMUX_EINT_SRC4		((volatile unsigned int*)(GPIOMUX_BASE_ADDR + 0x100C))
#define GPIOMUX_EINT_DB_EN		((volatile unsigned int*)(GPIOMUX_BASE_ADDR + 0x1100))
#define GPIOMUX_EINT_POL		((volatile unsigned int*)(GPIOMUX_BASE_ADDR + 0x1180))
#define GPIOMUX_EINT_TYPE		((volatile unsigned int*)(GPIOMUX_BASE_ADDR + 0x1200))
#define GPIOMUX_EINT_IRQEN		((volatile unsigned int*)(GPIOMUX_BASE_ADDR + 0x1280))
#define GPIOMUX_EINT_IRQSTS		((volatile unsigned int*)(GPIOMUX_BASE_ADDR + 0x1300))
#define GPIOMUX_EINT_DBNCSTS   ((volatile unsigned int*)(GPIOMUX_BASE_ADDR + 0x1380))
#define GPIOMUX_EINT_DUR0		((volatile unsigned int*)(GPIOMUX_BASE_ADDR + 0x1400))
#define GPIOMUX_EINT_DUR1		((volatile unsigned int*)(GPIOMUX_BASE_ADDR + 0x1404))
#define GPIOMUX_EINT_DUR2		((volatile unsigned int*)(GPIOMUX_BASE_ADDR + 0x1408))
#define GPIOMUX_EINT_DUR3		((volatile unsigned int*)(GPIOMUX_BASE_ADDR + 0x140C))
#define GPIOMUX_EINT_DUR4		((volatile unsigned int*)(GPIOMUX_BASE_ADDR + 0x1410))
#define GPIOMUX_EINT_DUR5		((volatile unsigned int*)(GPIOMUX_BASE_ADDR + 0x1414))
#define GPIOMUX_EINT_DUR6		((volatile unsigned int*)(GPIOMUX_BASE_ADDR + 0x1418))
#define GPIOMUX_EINT_DUR7		((volatile unsigned int*)(GPIOMUX_BASE_ADDR + 0x141C))
#define GPIOMUX_EINT_DUR8		((volatile unsigned int*)(GPIOMUX_BASE_ADDR + 0x1420))
#define GPIOMUX_EINT_DUR9		((volatile unsigned int*)(GPIOMUX_BASE_ADDR + 0x1424))
#define GPIOMUX_EINT_DUR10		((volatile unsigned int*)(GPIOMUX_BASE_ADDR + 0x1428))
#define GPIOMUX_EINT_DUR11		((volatile unsigned int*)(GPIOMUX_BASE_ADDR + 0x142C))
#define GPIOMUX_EINT_DUR12		((volatile unsigned int*)(GPIOMUX_BASE_ADDR + 0x1430))
#define GPIOMUX_EINT_DUR13		((volatile unsigned int*)(GPIOMUX_BASE_ADDR + 0x1434))
#define GPIOMUX_EINT_DUR14		((volatile unsigned int*)(GPIOMUX_BASE_ADDR + 0x1438))
#define GPIOMUX_EINT_DUR15		((volatile unsigned int*)(GPIOMUX_BASE_ADDR + 0x143C))
#define GPIOMUX_EINT_DIRQ0		((volatile unsigned int*)(GPIOMUX_BASE_ADDR + 0x1800))
#define GPIOMUX_EINT_DIRQ1		((volatile unsigned int*)(GPIOMUX_BASE_ADDR + 0x1804))
#define GPIOMUX_EINT_DIRQ2		((volatile unsigned int*)(GPIOMUX_BASE_ADDR + 0x1808))
#define GPIOMUX_EINT_DIRQ3		((volatile unsigned int*)(GPIOMUX_BASE_ADDR + 0x180C))
#define GPIOMUX_EINT_OWN		((volatile unsigned int*)(GPIOMUX_BASE_ADDR + 0x2000))


/* GPIO_MUX part Set and Clear Registers*/
/* ================================================================= */
#define GPIOMUX_EINT_DB_EN_SET		((volatile unsigned int*)(GPIOMUX_BASE_ADDR + 0x1100 + 0x4))
#define GPIOMUX_EINT_POL_SET		((volatile unsigned int*)(GPIOMUX_BASE_ADDR + 0x1180 + 0x4))
#define GPIOMUX_EINT_TYPE_SET		((volatile unsigned int*)(GPIOMUX_BASE_ADDR + 0x1200 + 0x4))
#define GPIOMUX_EINT_IRQEN_SET		((volatile unsigned int*)(GPIOMUX_BASE_ADDR + 0x1280 + 0x4))


#define GPIOMUX_EINT_DB_EN_CLR		((volatile unsigned int*)(GPIOMUX_BASE_ADDR + 0x1100 + 0x8))
#define GPIOMUX_EINT_POL_CLR		((volatile unsigned int*)(GPIOMUX_BASE_ADDR + 0x1180 + 0x8))
#define GPIOMUX_EINT_TYPE_CLR		((volatile unsigned int*)(GPIOMUX_BASE_ADDR + 0x1200 + 0x8))
#define GPIOMUX_EINT_IRQEN_CLR		((volatile unsigned int*)(GPIOMUX_BASE_ADDR + 0x1280 + 0x8))

#endif
