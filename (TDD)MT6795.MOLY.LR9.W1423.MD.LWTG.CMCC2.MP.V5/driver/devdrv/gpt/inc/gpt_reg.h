#ifndef __GPT_REG_H__
#define __GPT_REG_H__

#include <reg_base.h>
#include <irqid.h>

/* Register Address Definition */
#define MDGPT_BASE          (BASE_ADDR_MDGPTM)
#define GPT_CODA_VERSION    (MDGPT_BASE)

/* n = 1~6 */
#define MDGPT_CNT_REG(n)    (MDGPT_BASE + ((n))*0x10U + 0x0U)
#define MDGPT_PSR_REG(n)    (MDGPT_BASE + ((n))*0x10U + 0x4U)
#define MDGPT_CTRL_REG(n)   (MDGPT_BASE + ((n))*0x10U + 0x8U)
#define MDGPT_DATA_REG(n)   (MDGPT_BASE + ((n))*0x10U + 0xCU)

#define MDGPT_CTRL_MODE_ENABLE   (1U<<1)
#define MDGPT_CTRL_MODE_ONESHOT  (0U<<0)
#define MDGPT_CTRL_MODE_REPEAT   (1U<<0)

#if defined(MT6290) && defined(__ARM7EJ_S__)
#define MDGPT_INTR_ID(n)          (n + ARM7_IRQID_MDGPTM3 - 3)     // In ARM7, n = 3 ~ 6, no 0 and 1 GPT interrupt
#define MDGPT_INTR_ID2TIMER(n)    (n + 3 - ARM7_IRQID_MDGPTM3)
#else /* end of "defined(MT6290) && defined(__ARM7EJ_S__)" */
#define MDGPT_INTR_ID(n)          (n + MD_IRQID_MDGPTM_EVENT1 - 1)
#define MDGPT_INTR_ID2TIMER(n)    (n + 1 - MD_IRQID_MDGPTM_EVENT1)
#endif /* end of else of "defined(MT6290) && defined(__ARM7EJ_S__)" */


#endif /* end of __GPT_REG_H__ */
