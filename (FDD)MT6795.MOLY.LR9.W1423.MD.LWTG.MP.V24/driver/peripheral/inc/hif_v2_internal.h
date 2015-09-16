#ifndef __HIF_V2_INTERNAL_H__
#define __HIF_V2_INTERNAL_H__

//#include "drv_features.h"
//#include "kal_release.h"
#include "reg_base.h"
#include "drvpdn.h"
#if defined(DRV_HIF_SUPPORT) && defined(DRV_HIF_V2)


#if defined(MT6256) || defined(MT6276)|| defined(MT6255)
#define DMA_BASE_FOR_HIF   DMA_base
#define base_add_increase          0x10000
#define HIF0_CHANNEL_SUPPORT
#define HIF1_CHANNEL_SUPPORT    //support 2 HIF: for TD and WIFI
#elif defined(MT6575)||defined(MT6577)
//6575 hif0:0xc1001180,hif1:0xc1001200
#define DMA_BASE_FOR_HIF   (AP_DMA_base+0x180)
#define HIF0_base          AP_HIF_base
#define base_add_increase          0x1000
#define HIF1_CHANNEL_SUPPORT    //HIF only for TD
#elif defined(MT6280)
#define HIF0_CHANNEL_SUPPORT    //HIF only for WIFI
#define HIF0_base          HIF_base
#define base_add_increase          0x0
#elif defined(MT6752)
#define HIF1_CHANNEL_SUPPORT
#define NFI_HIF_SHAREPIN_SUPPORT
#define NALE_LPA0_SHAREPIN_SUPPORT
#define HIF0_base          AP_APHIF_base  //(MD HIF: higher address; AP HIF: Lower address)
#define base_add_increase          0x1000
#define __MD_HIF_AST8BIT_OPT__
#else
#error:current MTK chip is not support!
#endif

//define ECO solution for MT6256E4,MT6575E2 or MTK later chips
//#if (defined(MT6256_S03) || defined(MT6575_S01) || defined(MT6577)) && defined(__AST_TL1_TDD__)
//#if (defined(MT6256_S03)) && defined(__AST_TL1_TDD__)
//#define HIF_ECO_SOLUTION_SUPPORT
//#endif
/****************************************************************************
** Define HIF registers and Macro
*****************************************************************************/
#define HIF_MAX_PORT_NUM 4
#define HIF_ENGINE_COUNT 2

#define HIF_PORT_MCU_A0_LOW_ADDR(n)         (HIF0_base+0x0300+n*base_add_increase)
#define HIF_PORT_MCU_A0_HIGH_ADDR(n)        (HIF0_base+0x0310+n*base_add_increase)
#define HIF_PORT_PDMA_ADDR(n)                (HIF0_base+0x0200+n*base_add_increase)

#define HIF_TIMING_CONFIG_WRITE_WAIT_STATE_MASK         0x3F
#define HIF_TIMING_CONFIG_WRITE_SETUP_TIME_MASK         0xF00
#define HIF_TIMING_CONFIG_WRITE_HOLD_TIME_MASK          0xF000
#define HIF_TIMING_CONFIG_READ_LATENCY_TIME_MASK        0x3F0000
#define HIF_TIMING_CONFIG_READ_SETUP_TIME_MASK          0xF000000
#define HIF_TIMING_CONFIG_READ_HOLD_TIME_MASK           0xF0000000
#define HIF_TIMING_CONFIG_CHW_MASK                      0xF
#define HIF_TIMING_CONFIG_WRITE_WAIT_STATE_OFFSET       0
#define HIF_TIMING_CONFIG_WRITE_SETUP_TIME_OFFSET       8
#define HIF_TIMING_CONFIG_WRITE_HOLD_TIME_OFFSET        12
#define HIF_TIMING_CONFIG_READ_LATENCY_TIME_OFFSET      16
#define HIF_TIMING_CONFIG_READ_SETUP_TIME_OFFSET        24
#define HIF_TIMING_CONFIG_READ_HOLD_TIME_OFFSET         28
#define HIF_TIMING_CONFIG_CHW_OFFSET                    0


#define HIF_STA_REG(n)          (HIF0_base+n*base_add_increase+0x0)
#define HIF_INTEN_REG(n)        (HIF0_base+n*base_add_increase+0x4)
#define HIF_INTSTA_REG(n)       (HIF0_base+n*base_add_increase+0x8)
#define HIF_START_REG(n)        (HIF0_base+n*base_add_increase+0xC)
#define HIF_SWRST_REG(n)        (HIF0_base+n*base_add_increase+0x10)
#define HIF_TIME0_REG(n)        (HIF0_base+n*base_add_increase+0x14)
#define HIF_TIME1_REG(n)        (HIF0_base+n*base_add_increase+0x18)
#define HIF_CON_REG(n)          (HIF0_base+n*base_add_increase+0x20)
#define HIF_DAMOUNT_REG(n)      (HIF0_base+n*base_add_increase+0x24)
//#if defined (HIF_ECO_SOLUTION_SUPPORT)
#if defined (MT6752)
#define HIF_ACS_ARB_REG(n)		(HIF0_base+n*base_add_increase+0x320)
#define PIF_BUSY_MASK			0x10
#else
#define HIF_ACS_ARB_REG(n)		(HIF0_base+n*base_add_increase+0x30)
#define PIF_BUSY_MASK			0x2
#endif
#define MCU_ACS_REQ_OFFSET		0
#define MCU_ACS_STR_OFFSET		2

#define HIF_BUSY_MASK           0x00000001
#define HIF_CPL_MASK            0x00000001
#define HIF_START_MASK          0x00000001
#define HIF_RST_MASK            0x00000001
#define HIF_HIFW_MASK           0x00000003
#define HIF_WRITE_MASK          0x00000004
#define HIF_A0_MASK             0x00000008
#define HIF_ULTRA_MASK          0x00000010

#define HIF_HIFW_OFFSET         0
#define HIF_WRITE_OFFSET        2
#define HIF_A0_OFFSET           3
#define HIF_ULTRA_OFFSET        4

#define SET_HIF_CE2WR_SETUP_TIME(n, val)        (*(volatile kal_uint32*)HIF_TIME0_REG(n)) &= ~HIF_TIMING_CONFIG_WRITE_SETUP_TIME_MASK;\
                                                (*(volatile kal_uint32*)HIF_TIME0_REG(n)) |= (val)<<HIF_TIMING_CONFIG_WRITE_SETUP_TIME_OFFSET;
#define SET_HIF_CE2WR_HOLD_TIME(n, val)         (*(volatile kal_uint32*)HIF_TIME0_REG(n)) &= ~HIF_TIMING_CONFIG_WRITE_HOLD_TIME_MASK;\
                                                (*(volatile kal_uint32*)HIF_TIME0_REG(n)) |= (val)<<HIF_TIMING_CONFIG_WRITE_HOLD_TIME_OFFSET;
#define SET_HIF_CE2RD_SETUP_TIME(n, val)        (*(volatile kal_uint32*)HIF_TIME0_REG(n)) &= ~HIF_TIMING_CONFIG_READ_SETUP_TIME_MASK;\
                                                (*(volatile kal_uint32*)HIF_TIME0_REG(n)) |= (val)<<HIF_TIMING_CONFIG_READ_SETUP_TIME_OFFSET;
#define SET_HIF_CE2RD_HOLD_TIME(n, val)         (*(volatile kal_uint32*)HIF_TIME0_REG(n)) &= ~HIF_TIMING_CONFIG_READ_HOLD_TIME_MASK;\
                                                (*(volatile kal_uint32*)HIF_TIME0_REG(n)) |= (val)<<HIF_TIMING_CONFIG_READ_HOLD_TIME_OFFSET;
#define SET_HIF_WRITE_WAIT_STATE(n, val)        (*(volatile kal_uint32*)HIF_TIME0_REG(n)) &= ~HIF_TIMING_CONFIG_WRITE_WAIT_STATE_MASK;\
                                                (*(volatile kal_uint32*)HIF_TIME0_REG(n)) |= (val)<<HIF_TIMING_CONFIG_WRITE_WAIT_STATE_OFFSET;
#define SET_HIF_READ_LATENCY_TIME(n, val)       (*(volatile kal_uint32*)HIF_TIME0_REG(n)) &= ~HIF_TIMING_CONFIG_READ_LATENCY_TIME_MASK;\
                                                (*(volatile kal_uint32*)HIF_TIME0_REG(n)) |= (val)<<HIF_TIMING_CONFIG_READ_LATENCY_TIME_OFFSET;
#define SET_HIF_CS_HIGH_WIDTH_TIME(n, val)      (*(volatile kal_uint32*)HIF_TIME1_REG(n)) &= ~HIF_TIMING_CONFIG_CHW_MASK;\
                                                (*(volatile kal_uint32*)HIF_TIME1_REG(n)) |= (val)<<HIF_TIMING_CONFIG_CHW_OFFSET;
#define SET_HIF_BUS_WIDTH(n, val)               (*(volatile kal_uint32*)HIF_CON_REG(n)) &= ~HIF_HIFW_MASK;\
                                                (*(volatile kal_uint32*)HIF_CON_REG(n)) |= (val/8-1)<<HIF_HIFW_OFFSET;
#define SET_HIF_WRITE(n)                        (*(volatile kal_uint32*)HIF_CON_REG(n)) &= ~HIF_WRITE_MASK;\
                                                (*(volatile kal_uint32*)HIF_CON_REG(n)) |= 1<<HIF_WRITE_OFFSET;
#define SET_HIF_READ(n)                         (*(volatile kal_uint32*)HIF_CON_REG(n)) &= ~HIF_WRITE_MASK;\
                                                (*(volatile kal_uint32*)HIF_CON_REG(n)) |= 0<<HIF_WRITE_OFFSET;
#define SET_HIF_A0_HIGH(n)                      (*(volatile kal_uint32*)HIF_CON_REG(n)) &= ~HIF_A0_MASK;\
                                                (*(volatile kal_uint32*)HIF_CON_REG(n)) |= 1<<HIF_A0_OFFSET;
#define SET_HIF_A0_LOW(n)                       (*(volatile kal_uint32*)HIF_CON_REG(n)) &= ~HIF_A0_MASK;\
                                                (*(volatile kal_uint32*)HIF_CON_REG(n)) |= 0<<HIF_A0_OFFSET;
#define SET_HIF_ULTRA(n, val)                   (*(volatile kal_uint32*)HIF_CON_REG(n)) &= ~HIF_ULTRA_MASK;\
                                                (*(volatile kal_uint32*)HIF_CON_REG(n)) |= (val)<<HIF_ULTRA_OFFSET;
#define GET_HIF_ULTRA(n)                        (((*(volatile kal_uint32*)HIF_CON_REG(n))>> HIF_ULTRA_OFFSET) & 0x1);	
#define SET_HIF_DAMOUNT(n, val)                 (*(volatile kal_uint32*)HIF_DAMOUNT_REG(n)) = (val) - 1;

#define ENABLE_HIF_INTR(n)                      (*(volatile kal_uint32*)HIF_INTEN_REG(n)) = 1;
#define DISABLE_HIF_INTR(n)                     (*(volatile kal_uint32*)HIF_INTEN_REG(n)) = 0;

#define START_HIF(n)                            (*(volatile kal_uint32*)HIF_START_REG(n)) = 0;\
                                                (*(volatile kal_uint32*)HIF_START_REG(n)) = 1;
#define HIF_BUSY(n)                             ((*(volatile kal_uint32*)HIF_STA_REG(n)) & HIF_BUSY_MASK)
#define HIF_INT_CLEAR(n)                        (*(volatile kal_uint32*)HIF_INTSTA_REG(n)) = 0;
//#if defined (HIF_ECO_SOLUTION_SUPPORT)
#define SET_HIF_MCU_ACS_REQ(n)                  (*(volatile kal_uint32*)HIF_ACS_ARB_REG(n)) |= 1<<MCU_ACS_REQ_OFFSET
#define SET_HIF_MCU_ACS_STA(n)                  (*(volatile kal_uint32*)HIF_ACS_ARB_REG(n)) |= 1<<MCU_ACS_STR_OFFSET
#define CLEAR_HIF_MCU_ACS_REQ_STA(n)            (*(volatile kal_uint32*)HIF_ACS_ARB_REG(n)) = 0
#define PIF_BUSY(n)                             ((*(volatile kal_uint32*)HIF_ACS_ARB_REG(n)) & PIF_BUSY_MASK)

//#endif

// power gating definitions
#if defined(MT6276)
//on MT6256,REG_MCU_CG_CLR3,clock gating
#define REG_HIF_POWER_CLR         *((volatile unsigned int *)(CONFIG_base + 0x032c))//REG_HIF_POWER_CLR
#define REG_HIF_POWER_SET         *((volatile unsigned int *)(CONFIG_base + 0x031c))
#define HIF0_POWER_BIT    0x200
#define HIF1_POWER_BIT    0x400
#define NLIARB_POWER_BIT  0x800

#define NLI_ARB_POWER_ON        REG_HIF_POWER_CLR = (NLIARB_POWER_BIT);
#define HIF_POWER_ON(n)         REG_HIF_POWER_CLR = (HIF0_POWER_BIT << (n));
#define HIF_POWER_OFF(n)        REG_HIF_POWER_SET = (HIF0_POWER_BIT << (n));

#elif defined(MT6256)|| defined(MT6255)
//on MT6256,REG_MCU_CG_CLR2,clock gating
#define REG_HIF_POWER_CLR         *((volatile unsigned int *)(CONFIG_base + 0x0728))
#define REG_HIF_POWER_SET         *((volatile unsigned int *)(CONFIG_base + 0x0718))
#define HIF0_POWER_BIT    0x100
#define HIF1_POWER_BIT    0x200
#define NLIARB_POWER_BIT  0x800
//on MT6256,need not to enable NLI clock,it enable when enable HIF clock ,or enable LCD clock
#define NLI_ARB_POWER_ON        //REG_HIF_POWER_CLR = (NLIARB_POWER_BIT);
#define HIF_POWER_ON(n)         REG_HIF_POWER_CLR = (HIF0_POWER_BIT << (n));
#define HIF_POWER_OFF(n)        REG_HIF_POWER_SET = (HIF0_POWER_BIT << (n));

#elif defined(MT6280)
#define REG_HIF_POWER_CLR         *((volatile unsigned int *)(AP_CONFIG_base + 0x8))
#define REG_HIF_POWER_SET         *((volatile unsigned int *)(AP_CONFIG_base + 0x4))
#define HIF0_POWER_BIT    0x40
//on MT6280,need not to enable NLI clock,it enable when enable HIF clock ,or enable LCD clock
#define NLI_ARB_POWER_ON        //REG_HIF_POWER_CLR = (NLIARB_POWER_BIT);
#define HIF_POWER_ON(n)         REG_HIF_POWER_CLR = (HIF0_POWER_BIT << (n));
#define HIF_POWER_OFF(n)        REG_HIF_POWER_SET = (HIF0_POWER_BIT << (n));

#elif defined(MT6575)||defined(MT6577)
//on MT6256,PERI_GLOBALCON_PDN2,power gating
#define PERI_GLOBALCON_PDN2     *((volatile unsigned int *)(PERISYS_CONFG_base + 0x018))
#define PERI_GLOBALCON_PDN2_AP_HIF_BIT    0x80000//bit[19]
//#define PERI_GLOBALCON_PDN2_MD_HIF_BIT    0x100000//bit[20]
#define PERI_GLOBALCON_PDN2_NLI_BIT       0x200000//bit[19]
#define NLI_ARB_POWER_ON                        PERI_GLOBALCON_PDN2 &= (~PERI_GLOBALCON_PDN2_NLI_BIT);
#define HIF_POWER_ON(n)                         PERI_GLOBALCON_PDN2 &= (~(PERI_GLOBALCON_PDN2_AP_HIF_BIT << (n)));//set bit[19]=0
#define HIF_POWER_OFF(n)                        PERI_GLOBALCON_PDN2 |= (PERI_GLOBALCON_PDN2_AP_HIF_BIT << (n));

#elif defined(MT6752) //MD1: off, MD2: on
/*
#define REG_PERI_GLOBALCON_PDN0_SET         *((volatile unsigned int *)(AP_PERICFG_base+0x08))
#define REG_PERI_GLOBALCON_PDN0_CLR         *((volatile unsigned int *)(AP_PERICFG_base+0x10))
#define REG_PERI_GLOBALCON_PDN_MD1_SET      *((volatile unsigned int *)(AP_PERICFG_base+0x20))
#define REG_PERI_GLOBALCON_PDN_MD2_SET      *((volatile unsigned int *)(AP_PERICFG_base+0x24))
#define REG_PERI_GLOBALCON_PDN_MD1_CLR      *((volatile unsigned int *)(AP_PERICFG_base+0x28))
#define REG_PERI_GLOBALCON_PDN_MD2_CLR      *((volatile unsigned int *)(AP_PERICFG_base+0x2C))
#define REG_PERI_GLOBALCON_PDN_MD_MASK      *((volatile unsigned int *)(AP_PERICFG_base+0x38))
#define HIF0_POWER_BIT    0xC1000   //AP HIF& MD HIF& AP DMA power on/off at the same time

//#define HIF_POWER_CONTROL_INIT              REG_PERI_GLOBALCON_PDN_MD1_SET = (HIF0_POWER_BIT << 1); //MD1 always power down
#define HIF_POWER_ON(n)                     REG_PERI_GLOBALCON_PDN_MD2_CLR = (HIF0_POWER_BIT << (0));
#define HIF_POWER_OFF(n)                    REG_PERI_GLOBALCON_PDN_MD2_SET = (HIF0_POWER_BIT << (0));
*/
#define REG_PERI_GLOBALCON_PDN_MD2_STA      *((volatile unsigned int *)(AP_PERICFG_base+0x34))
#define CHECK_HIF_POWER_DOWN                (((REG_PERI_GLOBALCON_PDN_MD2_STA)>>19)&0x1)

#define HIF_POWER_ON(n)                     PDN_CLR(PDN_HIF_COMBIN)
#define HIF_POWER_OFF(n)                    PDN_SET(PDN_HIF_COMBIN)
#else
#error:current MTK chip is not support!
#endif
// End of power gating definitions
/****************************************************************************
** NLI arbiter definitions
*****************************************************************************/
#define REG_NLI_ARB_CS           *((volatile unsigned int *)   (NLI_ARB_base + 0x0014))
#define REG_NLI_ARB_CONT_GRANT   *((volatile unsigned int *)   (NLI_ARB_base + 0x0018))
#define REG_NLI_ARB_HANDOVER     *((volatile unsigned int *)   (NLI_ARB_base + 0x001C))

#if defined(NFI_HIF_SHAREPIN_SUPPORT) //share pin
#define REG_NLI_ARB_SHAREPIN_CON    *((volatile unsigned int *)(NLI_ARB_base + 0x0020))
#define NREB_LRDB_SHR_EN_OFFSET     3
#define NWEB_LWRB_SHR_EN_OFFSET     2
#define NCLE_LPA0_SHR_EN_OFFSET     1
#define NALE_LPA0_SHR_EN_OFFSET     0

#if defined(NALE_LPA0_SHAREPIN_SUPPORT)
#define NFI_HIF_SHR_PIN_CFG   REG_NLI_ARB_SHAREPIN_CON = 0xD
#else
#define NFI_HIF_SHR_PIN_CFG   REG_NLI_ARB_SHAREPIN_CON = 0xE
#endif

#endif

#if defined(MT6752)
#define NLI_ARB_CEB_SEL_OFS(n)   ((3*n)+4)
#define NLI_ARB_CEB_SEL_MASK(n)  (0x3 << (NLI_ARB_CEB_SEL_OFS(n)))
#else
#define NLI_ARB_CE0B_SEL_OFS    0
#define NLI_ARB_CE1B_SEL_OFS    4
#define NLI_ARB_CE2B_SEL_OFS    8
#define NLI_ARB_CE3B_SEL_OFS    12
#define NLI_ARB_CEB_SEL_OFS(n)  (4 * n)

#define NLI_ARB_CE0B_SEL_MASK    0x7
#define NLI_ARB_CE1B_SEL_MASK    0x70
#define NLI_ARB_CE2B_SEL_MASK    0x700
#define NLI_ARB_CE3B_SEL_MASK    0x7000
#define NLI_ARB_CEB_SEL_MASK(n)  (0x7 << (NLI_ARB_CEB_SEL_OFS(n)))
#endif //end if defined(MT6752) 

#if defined (MT6575)||defined (MT6577)
#define NLI_ARB_SET_LPCE_SEL(lpce_num, hif_id) \
{ \
    volatile unsigned int temp_REG_NLI_ARB_CS; \
    temp_REG_NLI_ARB_CS = REG_NLI_ARB_CS; \
    temp_REG_NLI_ARB_CS &= (~(NLI_ARB_CEB_SEL_MASK(lpce_num))); \
    temp_REG_NLI_ARB_CS |= ((4-hif_id) << (NLI_ARB_CEB_SEL_OFS(lpce_num))); \
    REG_NLI_ARB_CS = temp_REG_NLI_ARB_CS; \
}
#elif defined(MT6752)
#define NLI_ARB_SET_LPCE_SEL(lpce_num, hif_id) \
{ \
    volatile unsigned int temp_REG_NLI_ARB_CS; \
    temp_REG_NLI_ARB_CS = REG_NLI_ARB_CS; \
    temp_REG_NLI_ARB_CS &= (~(NLI_ARB_CEB_SEL_MASK(lpce_num))); \
    temp_REG_NLI_ARB_CS |= ((3-hif_id) << (NLI_ARB_CEB_SEL_OFS(lpce_num))); \
    REG_NLI_ARB_CS = temp_REG_NLI_ARB_CS; \
}
#else
#define NLI_ARB_SET_LPCE_SEL(lpce_num, hif_id) \
{ \
    volatile unsigned int temp_REG_NLI_ARB_CS; \
    temp_REG_NLI_ARB_CS = REG_NLI_ARB_CS; \
    temp_REG_NLI_ARB_CS &= (~(NLI_ARB_CEB_SEL_MASK(lpce_num))); \
    temp_REG_NLI_ARB_CS |= ((hif_id+3) << (NLI_ARB_CEB_SEL_OFS(lpce_num))); \
    REG_NLI_ARB_CS = temp_REG_NLI_ARB_CS; \
}
#endif
/****************************************************************************
** PDMA definitions
*****************************************************************************/
#define PDMA_OFS                 0x80
// PDMA definitions
#if defined(MT6276)||defined(MT6256)|| defined(MT6255)
//#define PDMA_BASE 0x80020000 //on MT6276
//#define PDMA_BASE 0x80030000 //on MT6256
#define REG_PDMA_HIF0_MEM_ADDR          *((volatile unsigned int *)(DMA_BASE_FOR_HIF + 0x031c))
#define REG_PDMA_HIF0_LEN               *((volatile unsigned int *)(DMA_BASE_FOR_HIF + 0x0324))
#define REG_PDMA_HIF0_CON               *((volatile unsigned int *)(DMA_BASE_FOR_HIF + 0x0318))
#define REG_PDMA_HIF0_EN                *((volatile unsigned int *)(DMA_BASE_FOR_HIF + 0x0308))

#define REG_PDMA_HIF1_MEM_ADDR          *((volatile unsigned int *)(DMA_BASE_FOR_HIF + 0x039c))
#define REG_PDMA_HIF1_LEN               *((volatile unsigned int *)(DMA_BASE_FOR_HIF + 0x03a4))
#define REG_PDMA_HIF1_CON               *((volatile unsigned int *)(DMA_BASE_FOR_HIF + 0x0398))
#define REG_PDMA_HIF1_EN                *((volatile unsigned int *)(DMA_BASE_FOR_HIF + 0x0388))
#define REG_PDMA_HIF_MEM_ADDR(if_num)   *((volatile unsigned int *)(DMA_BASE_FOR_HIF + 0x031c + (PDMA_OFS * if_num)))
#define REG_PDMA_HIF_LEN(if_num)        *((volatile unsigned int *)(DMA_BASE_FOR_HIF + 0x0324 + (PDMA_OFS * if_num)))
#define REG_PDMA_HIF_CON(if_num)        *((volatile unsigned int *)(DMA_BASE_FOR_HIF + 0x0318 + (PDMA_OFS * if_num)))
#define REG_PDMA_HIF_RST(if_num)        *((volatile unsigned int *)(DMA_BASE_FOR_HIF + 0x030C + (PDMA_OFS * if_num)))
#define REG_PDMA_HIF_EN(if_num)         *((volatile unsigned int *)(DMA_BASE_FOR_HIF + 0x0308 + (PDMA_OFS * if_num)))

#elif defined(MT6575)||defined (MT6577)

#define REG_PDMA_HIF0_MEM_ADDR          *((volatile unsigned int *)(DMA_BASE_FOR_HIF + 0x01c))
#define REG_PDMA_HIF0_LEN               *((volatile unsigned int *)(DMA_BASE_FOR_HIF + 0x024))
#define REG_PDMA_HIF0_CON               *((volatile unsigned int *)(DMA_BASE_FOR_HIF + 0x018))
#define REG_PDMA_HIF0_EN                *((volatile unsigned int *)(DMA_BASE_FOR_HIF + 0x008))

#define REG_PDMA_HIF1_MEM_ADDR          *((volatile unsigned int *)(DMA_BASE_FOR_HIF +PDMA_OFS+0x01c))
#define REG_PDMA_HIF1_LEN               *((volatile unsigned int *)(DMA_BASE_FOR_HIF +PDMA_OFS+0x024))
#define REG_PDMA_HIF1_CON               *((volatile unsigned int *)(DMA_BASE_FOR_HIF +PDMA_OFS+0x018))
#define REG_PDMA_HIF1_EN                *((volatile unsigned int *)(DMA_BASE_FOR_HIF +PDMA_OFS+0x008))
#define REG_PDMA_HIF_MEM_ADDR(if_num)   *((volatile unsigned int *)(DMA_BASE_FOR_HIF + 0x01c + (PDMA_OFS * if_num)))
#define REG_PDMA_HIF_LEN(if_num)        *((volatile unsigned int *)(DMA_BASE_FOR_HIF + 0x024 + (PDMA_OFS * if_num)))
#define REG_PDMA_HIF_CON(if_num)        *((volatile unsigned int *)(DMA_BASE_FOR_HIF + 0x018 + (PDMA_OFS * if_num)))
#define REG_PDMA_HIF_RST(if_num)        *((volatile unsigned int *)(DMA_BASE_FOR_HIF + 0x00C + (PDMA_OFS * if_num)))
#define REG_PDMA_HIF_EN(if_num)         *((volatile unsigned int *)(DMA_BASE_FOR_HIF + 0x008 + (PDMA_OFS * if_num)))
//#else
//#error
#endif


/****************************************************************************
** PDMA Control Register Macros
*****************************************************************************/

#define PDMA_SET_BUF_ADDR(if_num, val)    REG_PDMA_HIF_MEM_ADDR(if_num) = val;
#define PDMA_RD_BIT 0x1
#define PDMA_SET_RW_DIRECTION(if_num, R)  REG_PDMA_HIF_CON(if_num) &= (~(PDMA_RD_BIT));\
                                         REG_PDMA_HIF_CON(if_num) |= (R & 0x1);
#define PDMA_BURST_LEN_MASK 0x70000
#define PDMA_BURST_LEN_OFS 16
#define PDMA_SET_BURST_LEN(if_num, len)   REG_PDMA_HIF_CON(if_num) &= (~(PDMA_BURST_LEN_MASK));\
                                         REG_PDMA_HIF_CON(if_num) |= ((len & 0x7) << PDMA_BURST_LEN_OFS);
#define PDMA_SET_BUF_LEN(if_num, len)     REG_PDMA_HIF_LEN(if_num) = len
#define PDMA_START(if_num)                REG_PDMA_HIF_EN(if_num) = 1;
#define PDMA_SW_RST(if_num)               REG_PDMA_HIF_RST(if_num) = 1;

// End of PDMA definitions

typedef struct
{
    kal_bool realtime_callback;
    kal_bool ultra_high_en;
    kal_uint32 port;
    kal_uint32 engine_id;
    kal_uint32 user;
    HIF_CONFIG_T config;
    kal_bool A0H_CPU_BUSY;
    kal_bool A0L_CPU_BUSY;
    kal_bool DMA_BUSY;
} HIF_INTERNAL_HANDLE_T;

// HIF internal functions
void hif0_lisr(void);
void hif0_hisr(void);
void hif1_lisr(void);
void hif1_hisr(void);
void hif_wait_for_idle(kal_uint32 engine_id);

#endif
#endif
