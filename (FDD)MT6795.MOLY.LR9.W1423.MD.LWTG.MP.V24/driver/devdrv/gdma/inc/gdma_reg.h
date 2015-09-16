#ifndef __GDMA_REG_H__
#define __GDMA_REG_H__

#include <reg_base.h>
#include <irqid.h>

/* Register Address Definition */
#define MDGDMA_BASE          (BASE_ADDR_MDGDMA)
#define APGDMA_BASE			 (BASE_ADDR_APGDMA)

#define GDMA_CODA_VERSION    (MDGDMA_BASE)

/* n = 1~4 */
#define GDMA_FDCSR(n)				(MDGDMA_BASE + 0x10U + (4*(n/2)))
#define APGDMA_FDCSR(n)				(APGDMA_BASE + 0x10U + (4*(n/2)))
	#define FDMA_STAT(n)			(0x1 << ((n % 2) * 16))
	#define FDMA_CS_EN(n)			(0x1 << (8 + (n % 2) * 16))
	#define FDMA_MODE_LINKLIST(n)	(0x0 << (9 + (n % 2) * 16))
	#define FDMA_MODE_BASIC(n)		(0x1 << (9 + (n % 2) * 16))
	#define FDMA_MODE_DESCRPT(n)	(0x2 << (9 + (n % 2) * 16))
	#define FDMA_CS16B_EN			(0x1 << 31)

#define GDMA_CH_REG_OFFSET			0x20	
#define GDMA_FDCR(n)				(MDGDMA_BASE + 0x20U + (n*GDMA_CH_REG_OFFSET))
#define APGDMA_FDCR(n)				(APGDMA_BASE + 0x20U + (n*GDMA_CH_REG_OFFSET))
	#define FDMA_START				(0x1 << 0)
	#define FDMA_RESUME				(0x1 << 1)
	#define FDMA_STOP				(0x1 << 2)
#define GDMA_FDSAR(n)				(MDGDMA_BASE + 0x24U + (n*GDMA_CH_REG_OFFSET))
#define APGDMA_FDSAR(n)				(APGDMA_BASE + 0x24U + (n*GDMA_CH_REG_OFFSET))
#define GDMA_FDDAR(n)				(MDGDMA_BASE + 0x28U + (n*GDMA_CH_REG_OFFSET))
#define APGDMA_FDDAR(n)				(APGDMA_BASE + 0x28U + (n*GDMA_CH_REG_OFFSET))
#define GDMA_FDSCPR(n)				(MDGDMA_BASE + 0x30U + (n*GDMA_CH_REG_OFFSET))
#define APGDMA_FDSCPR(n)			(APGDMA_BASE + 0x30U + (n*GDMA_CH_REG_OFFSET))
#define GDMA_FDDCPR(n)				(MDGDMA_BASE + 0x34U + (n*GDMA_CH_REG_OFFSET))
#define APGDMA_FDDCPR(n)			(APGDMA_BASE + 0x34U + (n*GDMA_CH_REG_OFFSET))


#define GDMA_GISAR0					(MDGDMA_BASE + 0x600U)
	#define	FDMA_DST_DONE(n)		(0x1 << (n + 4))
	#define FDMA_QE_DST_INT(n)		(0x1 << (n + 12))
#define APGDMA_GISAR0				(APGDMA_BASE + 0x600U)
#define GDMA_GIMRK0					(MDGDMA_BASE + 0x620U)
#define APGDMA_GIMRK0				(APGDMA_BASE + 0x620U)


#define GDMA_INTR_ID        IRQ_MDGDMA0_CODE

#endif /* end of __GPT_REG_H__ */
