#include "eint_sw.h"
#include "kal_general_types.h"

#if defined(MT6290) || defined(MT6595) || (defined (MT6752) && defined (__MD1__))

/**
*  @brief  set the polarity parameter of the eint
*  @param  eint        :  the eint index to be set
*  @param  pol :	the polarity value to set, it should be 0~1
*				  0: set pol to negative polarity
*				  1: set pol to positive polarity
*  @return EINT_OK :   set successful,  EINT_FAIL : set failed
*/
kal_int32 eint_set_pol(eint_e eint, kal_uint32 pol)
{
	if(eint >= EINT_NUM)
	{
		EINT_PRINT("\tset eint pol failed,eint is:[%d]",eint);
		return EINT_FAIL;
	}
	if(EINT_POSITIVE_POLARITY == pol)
	{
		REG32_WRITE(GPIOMUX_EINT_POL_SET,(1 << eint));
	}
	else
	{
		REG32_WRITE(GPIOMUX_EINT_POL_CLR,(1 << eint));
	}
	
	return EINT_OK;
}

/**
 *  @brief     get  eint polarity value of eint
 *  @param  eint :  The eint to be read.
 *  @return   return the eint polarity parameter's value of eint
 *                 0: current is negative polarity
 *                 1: current is positive polarity
 *                 EINT_FAIL: eint is out of range
 */
kal_int32 gpio_get_eint_pol(eint_e eint)
{
	kal_uint32 pol;
	if(eint >= EINT_NUM)
	{
		EINT_PRINT("\t gpio set eint pol failed,eint is:[%d]",eint);
		return EINT_FAIL;
	}
	if(REG32(GPIOMUX_EINT_POL)&(1<<eint))
	{
		pol = EINT_POSITIVE_POLARITY;
	}
	else
	{
		pol = EINT_NEGATIVE_POLARITY;
	}
	return pol;
}



/**
*  @brief  set the debounce enable parameter of the eint
*  @param  eint        :  the eint index to be set
*  @param  debounce_en :	the debounce enable value to set, it should be 0~1
*				  		0: enable debounce function
*				  		1: disable debounce function
*  @return EINT_OK :   set successful,  EINT_FAIL : set failed
*/
kal_int32 eint_set_debounce_enable(eint_e eint, kal_uint32 debounce_en)
{
	if(eint >= EINT_NUM)
	{
		EINT_PRINT("\tset eint debounce failed,eint is:[%d]",eint);
		return EINT_FAIL;
	}
#if defined(MT6290)
	if(REG32(GPIOMUX_EINT_OWN) & (1<<eint))
	{
		EINT_PRINT("\t gpio set eint debounce failed,eint[%d] is AP",eint);
		return EINT_FAIL;
	}
#endif	
	if(EINT_ENABLE == debounce_en)
	{
		REG32_WRITE(GPIOMUX_EINT_DB_EN_SET,(1 << eint));
		while(!(REG32(GPIOMUX_EINT_DBNCSTS) & (1<<eint)));
	}
	else
	{
		REG32_WRITE(GPIOMUX_EINT_DB_EN_CLR,(1 << eint));
		while((REG32(GPIOMUX_EINT_DBNCSTS) & (1<<eint)));					
	}
	
	
	return EINT_OK;
}

/**
*  @brief  set the debounce duration parameter of the eint
*  @param  eint        :  the eint index to be set
*  @param  duration :	the debounce duration value to set, it should be 0~0x3fff
*  @return EINT_OK :   set successful,  EINT_FAIL : set failed
*/
kal_int32 eint_set_debounce_duration(eint_e eint, kal_uint32 duration)
{
	volatile unsigned int *reg_addr;
	if(eint >= EINT_NUM)
	{
		EINT_PRINT("\tset eint debounce failed,eint is:[%d]",eint);
		return EINT_FAIL;
	}

	if(duration > EINT_DB_DUR_MAX)
	{
		EINT_PRINT("\tset eint debounce failed,debounce duration:[%x] is out of range",duration);
		return EINT_FAIL;
	}
	else
	{
		reg_addr = (volatile unsigned int *)((unsigned int)GPIOMUX_EINT_DUR0 + 4*eint);
		REG32_WRITE(reg_addr,duration);
	}
	
	return EINT_OK;
}

/**
*  @brief  set the irqen parameter of the eint
*  @param  eint        :  the eint index to be set
*  @param  enable :	the irq enable register value to set, it should be 0~1
*				  		0: disable eint irq send to cirq/gic module
*				  		1: enable eint irq send to cirq/gic module
*  @return EINT_OK :   set successful,  EINT_FAIL : set failed
*/
kal_int32 eint_set_irqen(eint_e eint,kal_uint32 enable)
{
	if(eint >= EINT_NUM)
	{
		EINT_PRINT("\tset eint irqen failed,eint is:[%d]",eint);
		return EINT_FAIL;
	}
	if(EINT_ENABLE == enable)
	{
		REG32_WRITE(GPIOMUX_EINT_IRQEN_SET,(1<<eint));
	}
	else if(EINT_DISABLE == enable)
	{
		REG32_WRITE(GPIOMUX_EINT_IRQEN_CLR,(1<<eint));
	}
	else
	{
		EINT_ERR("\tThe irq enable value should be 0 or 1 !!!!");
		return EINT_FAIL;
	}

	return EINT_OK;
}

void eint_set_mask_all(kal_uint32 mask_bits)
{
	REG32_WRITE(GPIOMUX_EINT_IRQEN_CLR,mask_bits);
}

void eint_set_unmask_all(kal_uint32 unmask_bits)
{
	REG32_WRITE(GPIOMUX_EINT_IRQEN_SET,unmask_bits);
}


/**
 *  @brief     get  eint debounce enable value of eint
 *  @param  eint :  The eint to be read.
 *  @return   return the eint debounce parameter's value of eint
 *                 0:  current debounce is disable
 *                 1:  current debounce is enable
 *                 EINT_FAIL: eint is out of range
 */
kal_int32 eint_get_debounce_enable(eint_e eint)
{
	kal_uint32 debounce;
	if(eint >= EINT_NUM)
	{
		EINT_PRINT("\tset eint debounce failed,eint is:[%d]",eint);
		return EINT_FAIL;
	}
	if(REG32(GPIOMUX_EINT_DB_EN)&(1<<eint))
	{
		debounce = EINT_ENABLE;
	}
	else
	{
		debounce = EINT_DISABLE;
	}
	return debounce;
}

/**
 *  @brief     get  eint IRQEN value of eint
 *  @return   return the eint debounce parameter's value of eint
 *                 0:  current eint is unmask
 *                 1:  current eint is mask
 *                 EINT_FAIL: eint is out of range
 */
kal_int32 eint_get_irqen(void)
{
	kal_uint32 irqen;

	irqen = REG32(GPIOMUX_EINT_IRQEN);
	irqen &= ((1<<EINT_TOTAL_CHANNEL) - 1); 
	return irqen;
}


/**
*  @brief  set the sensitivity parameter of the eint
*  @param  eint        :  the eint index to be set
*  @param  type :	the sensitivity value to set, it should be 0~1
*				  0: set sensitivity to edge(pulse)
*				  1: set sensitivity to level
*  @return EINT_OK :   set successful,  EINT_FAIL : set failed
*/
kal_int32 eint_set_type(eint_e eint, kal_uint32 type)
{
	if(eint >= EINT_NUM)
	{
		EINT_PRINT("\tset eint pol failed,eint is:[%d]",eint);
		return EINT_FAIL;
	}
	if(EINT_LEVEL_SENSITIVITY == type)
	{
		REG32_WRITE(GPIOMUX_EINT_TYPE_SET,(1 << eint));
	}
	else
	{
		REG32_WRITE(GPIOMUX_EINT_TYPE_CLR,(1 << eint));
	}
	
	return EINT_OK;
}

/**
 *  @brief     get  eint type parameter's value of eint
 *  @param  eint :  The eint to be read.
 *  @return   return the eint type parameter's value of eint
 *                 0: current is edge(pulse) sensitivity
 *                 1: current is level sensitivity
 *                 EINT_FAIL: eint is out of range
 */
kal_int32 gpio_get_eint_type(eint_e eint)
{
	if(eint >= EINT_NUM)
	{
		EINT_PRINT("\t gpio set eint pol failed,eint is:[%d]",eint);
		return EINT_FAIL;
	}
	if(REG32(GPIOMUX_EINT_TYPE)&(1<<eint))
	{
		return EINT_LEVEL_SENSITIVITY;
	}
	else
	{
		return EINT_EDGE_SENSITIVITY;
	}
	
}


/**
*  @brief  set eint ownership register
*  @param  eint  : the eint index to set ownerhsip
*  @param  ownership : the ownership register bit value to set ,it should be 0~1
*                                    0: set ownership to MD
*                                    1: set ownership to AP
*  @return GPIO_OK :	set successful,  EINT_FAIL : set failed
*/
kal_int32 eint_set_ownership(kal_uint32 eint,kal_uint32 ownership)
{
	kal_uint32 reg_val;

	if((eint >= EINT_NUM)||(ownership > EINT_OWNERSHIP_AP))
	{
		EINT_PRINT("\teint_set_ownership failed! eint[%d] or ownership[%d] is over range",eint,ownership);
		return EINT_FAIL;
	}
	
	if(ownership == EINT_OWNERSHIP_AP)
	{
		reg_val = REG32(GPIOMUX_EINT_OWN);
		reg_val = reg_val|(1<<eint);
		REG32_WRITE(GPIOMUX_EINT_OWN,reg_val);
	}
	else
	{

		reg_val = REG32(GPIOMUX_EINT_OWN);
		reg_val = reg_val&(~(1<<eint));
		REG32_WRITE(GPIOMUX_EINT_OWN,reg_val);

	}

	return EINT_OK;
}

/**
*  @brief  set the source gpio index parameter of the eint
*  @param  eint        :  the eint index to be set
*  @param  gpio_pin :	The pin which is to set as source gpio of eint. it should be 0~63
*  @return GPIO_OK :   set successful,  EINT_FAIL : set failed
*/
kal_int32 gpio_set_eint_src(eint_e eint, kal_uint8 gpio_pin)
{
	volatile unsigned int* eint_src_reg;
	kal_uint32 eint_src,eint_src_reg_shift;
	if((eint >= EINT_NUM)||(gpio_pin >= GPIO_PIN_MAX))
	{
		EINT_PRINT("\t gpio seteint src failed! eint:[%d] or gpio_pin:[%d] is out of range",eint,gpio_pin);
		return EINT_FAIL;
	}

	eint_src_reg = (volatile unsigned int*)((unsigned int)GPIOMUX_EINT_SRC1 + EINT_SRC_OFFSET*(eint/EINT_SRC_NUM_PER_REG));
	eint_src_reg_shift = (eint%EINT_SRC_NUM_PER_REG)*EINT_SRC_SHIFT_BIT;
	eint_src = REG32(eint_src_reg);
	REG32_WRITE(eint_src_reg,(eint_src&(~(0xff << eint_src_reg_shift))));
	eint_src = REG32(eint_src_reg);
	REG32_WRITE(eint_src_reg,(eint_src|(gpio_pin << eint_src_reg_shift)));
	
	return EINT_OK;
}

/**
 *  @brief     get  eint source gpio id of eint
 *  @param  eint :  The eint to be read.
 *  @return   return the eint source parameter's value of eint
 *                 gpio_pin: 0~64 the gpio index of eint source
 *                 EINT_FAIL: eint is out of range
 */
kal_int32 gpio_get_eint_src(eint_e eint)
{
	volatile unsigned int* eint_src_reg;
	kal_uint32 eint_src,eint_src_reg_shift,gpio_pin;
	if(eint >= EINT_NUM)
	{
		EINT_PRINT("\t gpio get eint src failed! eint:[%d]  is out of range",eint);
		return EINT_FAIL;
	}
	eint_src_reg = (volatile unsigned int*)((unsigned int)GPIOMUX_EINT_SRC1 + EINT_SRC_OFFSET*(eint/EINT_SRC_NUM_PER_REG));
	eint_src_reg_shift = (eint%EINT_SRC_NUM_PER_REG)*EINT_SRC_SHIFT_BIT;
	eint_src = REG32(eint_src_reg);
	gpio_pin = (eint_src>>eint_src_reg_shift)&0xff;
	return gpio_pin;
}


/**
 *  @brief     set dedicated eint source l2 eint index value of deint
 *  @param  deint :  The dedicated eint to be set.
 *  @param  eint_num: the l2 eint index to set as source eint of deint,it should be 0~15
 *  @return GPIO_OK :	set successful,  EINT_FAIL : set failed
 */
kal_int32 eint_set_l1_eint_source(dedicated_eint_e deint,eint_e eint_num)
{
	volatile unsigned int *reg_addr;
	kal_uint32 reg_val;

	if((eint_num >= EINT_NUM)||(deint >= DEDICATED_EINT_TOTAL_CHANNEL))
	{
		EINT_PRINT("\teint set l1 eint source failed,eint_num is:[%d] , deint is [%d]",eint_num,deint);
		return EINT_FAIL;
	}
	reg_addr = (volatile unsigned int *)((unsigned int)GPIOMUX_EINT_DIRQ0 + deint*4);
	reg_val = REG32(reg_addr);
	REG32_WRITE(reg_addr,(reg_val&(~0xf)));
	reg_val = REG32(reg_addr);
	REG32_WRITE(reg_addr,(reg_val | eint_num));
	return EINT_OK;
}

/**
 *  @brief     set dedicated eint enable value of deint
 *  @param  deint :  The dedicated eint to be set.
 *  @param  enable: the enable register value to set,it should be 0~1
 *				   0: enable dedicated eint 
 *				   1: disable dedicated eint 
 *  @return GPIO_OK :	set successful,  EINT_FAIL : set failed
 */
kal_int32 eint_set_l1_eint_enable(dedicated_eint_e deint , kal_uint32 enable)
{
	volatile unsigned int *reg_addr;
	kal_uint32 bit_shift,reg_val;

	bit_shift = 31;

	if((deint >= DEDICATED_EINT_TOTAL_CHANNEL)||(enable > EINT_ENABLE))
	{
		EINT_PRINT("\teint set l1 eint enable failed,eint is:[%d],enable is:[%d]",deint,enable);
		return EINT_FAIL;
	}
	reg_addr = (volatile unsigned int *)((unsigned int)GPIOMUX_EINT_DIRQ0 + deint*4);
	reg_val = REG32(reg_addr);
	REG32_WRITE(reg_addr,(reg_val&(~(1 << bit_shift))));
	reg_val = REG32(reg_addr);
	REG32_WRITE(reg_addr,(reg_val | (enable << bit_shift)));
	return EINT_OK;
}

/**
 *  @brief     set dedicated eint enable value of deint
 *  @param  deint :  The dedicated eint to be set.
 *  @param  enable: the enable register value to set,it should be 0~1
 *				   0: enable dedicated eint 
 *				   1: disable dedicated eint 
 *  @return GPIO_OK :	set successful,  EINT_FAIL : set failed
 */
kal_int32 eint_get_l1_irqen(dedicated_eint_e deint)
{
	volatile unsigned int *reg_addr;
	kal_uint32 bit_shift,reg_val;

	bit_shift = 31;

	if((deint >= DEDICATED_EINT_TOTAL_CHANNEL))
	{
		EINT_PRINT("\teint set l1 eint enable failed,eint is:[%d],enable is:[%d]",deint);
		return EINT_FAIL;
	}
	reg_addr = (volatile unsigned int *)((unsigned int)GPIOMUX_EINT_DIRQ0 + deint*4);
	reg_val = REG32(reg_addr);

	return ((reg_val & (1 << bit_shift)) != 0);
}


/**
 *  @brief     set dedicated eint enable value of deint
 *  @param  deint :  The dedicated eint to be set.
 *  @param  eint: the l2 eint index to set as source eint of deint,it should be 0~15
 *  @param  enable: the enable register value to set,it should be 0~1
 *				   0: enable dedicated eint 
 *				   1: disable dedicated eint 
 *  @return GPIO_OK :	set successful,  EINT_FAIL : set failed
 */
kal_int32 gpio_set_l1_eint(dedicated_eint_e deint,eint_e eint,kal_uint32 enable)
{
	if((deint >= DEDICATED_EINT_TOTAL_CHANNEL)||(eint >= EINT_NUM)||(enable> EINT_ENABLE))
	{
		EINT_PRINT("\teint set l1 eint failed! deint = [%d],eint = [%d], enable = [%d]",deint,eint,enable);
		return EINT_FAIL;
	}
	eint_set_irqen(eint,EINT_DISABLE);
	eint_set_l1_eint_source(deint,eint);
	eint_set_l1_eint_enable(deint,enable);

	return EINT_OK;
}


/**
 *  @brief     get  dedicated eint source l2 eint index value of l1_deint
 *  @param  l1_deint :  The dedicated eint to be read.
 *  @return   return the dedicated eint  source l2 eint index value of l1_deint
 *                 src_eint:  0~0xf , l2 eint index
 *                 EINT_FAIL: l1_deint is out of range
 */
kal_int32 gpio_get_l1_eint_src(kal_uint32 l1_deint)
{
	kal_uint32 src_eint;
	volatile unsigned int *reg_addr;

	if(l1_deint >= DEDICATED_EINT_TOTAL_CHANNEL)
	{
		EINT_PRINT("\t eint get l1 deint srouce failed,l1_eint is:[%d]",l1_deint);
		return EINT_FAIL;
	}

	reg_addr = (volatile unsigned int *)((unsigned int)GPIOMUX_EINT_DIRQ0 + 4*l1_deint);
	src_eint = REG32(reg_addr)&0xf;

	return src_eint;
}

#else

kal_int32 eint_set_pol(eint_e eint, kal_uint32 pol)
{
	
	return 0;
}


kal_int32 gpio_get_eint_pol(eint_e eint)
{
	
	return 0;
}




kal_int32 eint_set_debounce_enable(eint_e eint, kal_uint32 debounce_en)
{
	
	
	return 0;
}


kal_int32 eint_set_debounce_duration(eint_e eint, kal_uint32 duration)
{
	
	return 0;
}

kal_int32 eint_set_irqen(eint_e eint,kal_uint32 enable)
{
	

	return 0;
}

void eint_set_mask_all(kal_uint32 mask_bits)
{
	
}

void eint_set_unmask_all(kal_uint32 unmask_bits)
{
	
}



kal_int32 eint_get_debounce_enable(eint_e eint)
{
	
	return 0;
}


kal_int32 eint_get_irqen(void)
{
	
	return 0;
}



kal_int32 eint_set_type(eint_e eint, kal_uint32 type)
{
	
	return 0;
}


kal_int32 gpio_get_eint_type(eint_e eint)
{
	return 0;
	
}



kal_int32 eint_set_ownership(kal_uint32 eint,kal_uint32 ownership)
{
	

	return 0;
}


kal_int32 gpio_set_eint_src(eint_e eint, kal_uint8 gpio_pin)
{
	
	return 0;
}


kal_int32 gpio_get_eint_src(eint_e eint)
{
	
	return 0;
}



kal_int32 eint_set_l1_eint_source(dedicated_eint_e deint,eint_e eint_num)
{
	
	return 0;
}


kal_int32 eint_set_l1_eint_enable(dedicated_eint_e deint , kal_uint32 enable)
{
	
	return 0;
}


kal_int32 eint_get_l1_irqen(dedicated_eint_e deint)
{
	
	return 0;
}



kal_int32 gpio_set_l1_eint(dedicated_eint_e deint,eint_e eint,kal_uint32 enable)
{
	

	return 0;
}



kal_int32 gpio_get_l1_eint_src(kal_uint32 l1_deint)
{
	

	return 0;
}

#endif

