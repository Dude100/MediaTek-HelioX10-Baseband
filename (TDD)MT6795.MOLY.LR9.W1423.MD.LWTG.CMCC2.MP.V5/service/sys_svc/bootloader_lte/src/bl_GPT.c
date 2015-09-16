#include "kal_general_types.h"
#include "reg_base.h"
#include "gpt_reg.h"
#include "irqid.h"
#include "drv_features_gpt.h"
#include "intrCtrl.h"
#include "sync_data.h"
#include "bl_drv_common.h"
#include "drvpdn.h"

static kal_bool gpt_bus_clock_en = KAL_FALSE;
#define BL_GPTM_BUS_CLOCK_ON()                      \
	do{                                             \
		if(KAL_FALSE == gpt_bus_clock_en)           \
		{                                           \
			PDN_CLR(PDN_MDGPTM);                    \
			gpt_bus_clock_en = KAL_TRUE;            \
		}                                           \
	}while(0);

void bl_drvgpt_init(void)
{
	kal_uint32 i;

	BL_GPTM_BUS_CLOCK_ON();
	for(i = 1; i <= DRV_GPT_TOTAL_COUNTER; i++)
	{
		DRV_WriteReg32(MDGPT_CTRL_REG(i), 0);
		DRV_WriteReg32(MDGPT_CNT_REG(i), 0xFFFFF);
		DRV_WriteReg32(MDGPT_PSR_REG(i), 0);
//		IRQSensitivity(MDGPT_INTR_ID(i), EDGE_SENSITIVE);
//		IRQClearInt(MDGPT_INTR_ID(i));
//		IRQMask(MDGPT_INTR_ID(i));
	}
}

void bl_drvgpt_stop_timer(kal_uint32 num)
{
	unsigned int timer_status;

	ASSERT( (num >= 1) && (DRV_GPT_TOTAL_COUNTER >= num) );

	BL_GPTM_BUS_CLOCK_ON();
	timer_status = DRV_Reg32(MDGPT_CTRL_REG(num));

	DRV_WriteReg32_NPW(MDGPT_CTRL_REG(num), timer_status & (~MDGPT_CTRL_MODE_ENABLE));
	Data_Sync_Barrier();
}

void bl_drvgpt_start_timer(kal_uint32 num)
{
	unsigned int timer_status;

	ASSERT( (num >= 1) && (DRV_GPT_TOTAL_COUNTER >= num) );

	BL_GPTM_BUS_CLOCK_ON();
	timer_status = DRV_Reg32(MDGPT_CTRL_REG(num));

	if( timer_status & MDGPT_CTRL_MODE_ENABLE ){
		//ASSERT(0);
		return;
	}

	DRV_WriteReg32_NPW(MDGPT_CTRL_REG(num), timer_status | MDGPT_CTRL_MODE_ENABLE);
	Data_Sync_Barrier();
}

void bl_drvgpt_set_timer(kal_uint32 num, kal_uint32 time, kal_uint32 mode, kal_uint32 prescaler)
{
	ASSERT( (1 <= num) && (num <= DRV_GPT_TOTAL_COUNTER) && (time <= 0xFFFFFUL) );

	BL_GPTM_BUS_CLOCK_ON();
	DRV_WriteReg32(MDGPT_CNT_REG(num), time);
	DRV_WriteReg32(MDGPT_PSR_REG(num), prescaler);

	mode &= MDGPT_CTRL_MODE_REPEAT | MDGPT_CTRL_MODE_ONESHOT;

	DRV_WriteReg32_NPW(MDGPT_CTRL_REG(num), mode);//1<<1 enable timer
}

void bl_drvgpt_udelay(kal_uint32 num, kal_uint32 udelay)
{
	ASSERT( (num > 0) && (num <= DRV_GPT_TOTAL_COUNTER));

	BL_GPTM_BUS_CLOCK_ON();
	/* set timer */
	bl_drvgpt_stop_timer(num);
	bl_drvgpt_set_timer(num, udelay, MDGPT_CTRL_MODE_ONESHOT, 0);
//	IRQMask(MDGPT_INTR_ID(num));
	bl_drvgpt_start_timer(num);

	/* wait time-out */
	while (DRV_Reg32(MDGPT_CTRL_REG(num)) & MDGPT_CTRL_MODE_ENABLE);

	/* Check time-out value */
	ASSERT(DRV_Reg32(MDGPT_DATA_REG(num)) == udelay);
//	IRQClearInt(MDGPT_INTR_ID(num));
//	IRQUnmask(MDGPT_INTR_ID(num));
}

void bl_drvgpt_start_timeout_ms(kal_uint32 num, kal_uint32 mdelay)
{
    //Each unit is 8us, tick = ms *1000/8;
    kal_uint32 tick_uint = mdelay*125; 

    ASSERT( (num > 0) && (num <= DRV_GPT_TOTAL_COUNTER));

    BL_GPTM_BUS_CLOCK_ON();

    /* set timer */
    bl_drvgpt_stop_timer(num);
    bl_drvgpt_set_timer(num, tick_uint, MDGPT_CTRL_MODE_ONESHOT, 3);
    bl_drvgpt_start_timer(num);
}

void bl_drvgpt_start_timeout_s(kal_uint32 num, kal_uint32 sdelay)
{
    //Each unit is 64us, tick = s*1000000/64;
    kal_uint32 tick_uint = sdelay*15625; 

    ASSERT( (num > 0) && (num <= DRV_GPT_TOTAL_COUNTER));

    BL_GPTM_BUS_CLOCK_ON();

    /* set timer */
    bl_drvgpt_stop_timer(num);
    bl_drvgpt_set_timer(num, tick_uint, MDGPT_CTRL_MODE_ONESHOT, 6);
    bl_drvgpt_start_timer(num);
}

kal_bool bl_drvgpt_get_timeout_status(kal_uint32 num)
{
    if(DRV_Reg32(MDGPT_CTRL_REG(num)) & MDGPT_CTRL_MODE_ENABLE){
        return KAL_FALSE;
    }

    return KAL_TRUE;
}
