/*********************************************************************
  * LEGAL DISCLAIMER
  *
  * (Header of MediaTek Software/Firmware Release or Documentation)
  *
  * BY OPENING OR USING THIS FILE, BUYER HEREBY UNEQUIVOCALLY
  * ACKNOWLEDGES AND AGREES THAT THE SOFTWARE/FIRMWARE AND ITS
  * DOCUMENTATIONS ("MEDIATEK SOFTWARE") RECEIVED FROM MEDIATEK AND/OR
  * ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON AN "AS-IS" BASIS ONLY.
  * MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES, EXPRESS OR
  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR
  * NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY
  * WHATSOEVER WITH RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH
  * MAY BE USED BY, INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK
  * SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH THIRD PARTY FOR ANY
  * WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO NOT BE
  * RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
  * SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
  *
  * BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
  * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED
  * HEREUNDER WILL BE, AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE
  * MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE FEES OR
  * SERVICE CHARGE PAID BY BUYER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE
  * AT ISSUE.
  *
  * THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN
  * ACCORDANCE WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING
  * ITS CONFLICT OF LAWS PRINCIPLES.
  **********************************************************************
  */


/*******************************************************************************

 * Include files

******************************************************************************/

#include "drv_iomux.h"
#include "kal_public_api.h"
#include "iomux_drv.h"
/*******************************************************************************

 * LOCAL CONST DEFINATION

******************************************************************************/


/*******************************************************************************

 * LOCAL TYPE DEFINATION

******************************************************************************/


/*******************************************************************************

 * EXTERN DECLARATION

******************************************************************************/
extern func_group_t iomux_func_table[];

/*******************************************************************************

 * GLOBAL VARIABLE DEFINATIONS

*******************************************************************************/
static kal_uint32 mod_conf_mem[IOMUX_MEM_SIZE] __attribute__ ((aligned (32)));
module_conf_t* iomux_MemPtr = (module_conf_t*)mod_conf_mem;



	/*
	 *	@brief	   Check the function num is valid or not for IOPAD group . 
	 *	@param 
	 *		funciton_num:  function mode selection	valid value 0~5;
	 *		module_num:  IOPAD group selection, valied value please see enum module_sel;
	 *	@return  
	 *			 0:  is valid setting;
	 *		1: invaild funtion setting;
	 */ 

kal_uint32 IOMUX_funcValid_check(kal_uint32 function_num, mod_sel_t mod_num){

	kal_uint32 function_value = 0;
	
	if(mod_num >= sel_count || function_num >5){
	//	IOMUX_ERR("Invalid function setting! IOPAD group (%d), function mode (%d)\r\n", mod_num, function_num);
		return IOMUX_FAIL;
	}

	switch(function_num){
		case 0: function_value = iomux_func_table[mod_num].mode0; break;
		case 1: function_value = iomux_func_table[mod_num].mode1; break;
		case 2: function_value = iomux_func_table[mod_num].mode2; break;
		case 3: function_value = iomux_func_table[mod_num].mode3; break;
		case 4: function_value = iomux_func_table[mod_num].mode4; break;
		case 5: function_value = iomux_func_table[mod_num].mode5; break;
		default: break;
		
	}
	if(function_value==0){
	//IOMUX_ERR("IOPAD group (%d), func num (%d) is invalid\r\n", mod_num, function_num);
		return IOMUX_FAIL;
	}

	return IOMUX_OK;
	
}

	
	/*
	 *	@brief	   set IOPAD group to special funciton mode
	 *	@param 
	 *		funciton_num:  function mode selection	valid value 0~5;
	 *		mod_num:  IOPAD group selection, valied value please see enum module_sel;
	 *		sip_flag:		choose the chip is SIP or Non-SIP. 
	 *					0: non-sip ; 1: sip
	 *	@return  
	 */
	 
void IOMUX_set_module_func(kal_uint32 function_num, mod_sel_t mod_num){

	kal_uint32 group_offset = 0;
	kal_uint32 mod_offset = 0;
/*	
	if(mod_num > 37 ){
		IOMUX_ERR("Invalid pin group setting! IOPAD group (%d)\r\n", mod_num);
		return;
	}
*/
	if(mod_num < 5){
		group_offset = 0;
		mod_offset = mod_num * 3;
	}else if(mod_num < 15){
		group_offset = 1;
		if(mod_num < 10){
			mod_offset = (mod_num -5)*3 ;
		}else{
			mod_offset = (mod_num -5)*3 + 1 ;
		}
	}else if(mod_num < 25){
		group_offset = 2;
		if(mod_num < 20){
			mod_offset = (mod_num -15)*3 ;
		}else{
			mod_offset = (mod_num -15)*3 + 1 ;
		}
	}else if(mod_num < 34){
		group_offset = 3;
		if(mod_num < 30){
			mod_offset = (mod_num -25)*3 ;
		}else{
			mod_offset = (mod_num -25)*3 + 1 ;
		}
	}else if(mod_num<37){
		group_offset = 0x35;
		mod_offset = (mod_num-34) * 3;
	}else if(mod_num ==37){
		group_offset = 0x35;
		mod_offset = (mod_num-34) * 3;
		DRV_WriteReg32(((kal_uint32)IOMUX_MODE_SEL + group_offset*0x04), ((DRV_Reg32(((kal_uint32)IOMUX_MODE_SEL + group_offset*0x04)) & ~(0x1<<mod_offset))|(function_num << mod_offset)));
		return;
	}
	
	DRV_SetReg3(((kal_uint32)IOMUX_MODE_SEL + group_offset*0x04), mod_offset, function_num);

}
	
	/*
	 *	@brief	   Get the special funciton mode of the IOPAD group.
	 *	@param 
	 *		mod_num:  IOPAD group selection, valied value please see enum module_sel;
	 *	@return 
			return the	function mode, valid value 0~5;
	 */
kal_uint32 IOMUX_get_module_func(mod_sel_t mod_num){

	kal_uint32 group_offset, mod_offset;
	kal_uint32 func_value;
		
	if(mod_num > 37 ){
		IOMUX_ERR("Invalid  pin group setting! IOPAD group (%d)\r\n", mod_num);
		return IOMUX_FAIL;
	}
		
	if(mod_num < 5){
		group_offset = 0;
		mod_offset = mod_num * 3;
	}else if(mod_num < 15){
		group_offset = 1;
		if(mod_num < 10){
			mod_offset = (mod_num -5)*3 ;
		}else{
			mod_offset = (mod_num -5)*3 + 1 ;
		}
	}else if(mod_num < 25){
		group_offset = 2;
		if(mod_num < 20){
			mod_offset = (mod_num -15)*3 ;
		}else{
			mod_offset = (mod_num -15)*3 + 1 ;
		}
	}else if(mod_num < 34){
		group_offset = 3;
		if(mod_num < 30){
			mod_offset = (mod_num -25)*3 ;
		}else{
			mod_offset = (mod_num -25)*3 + 1 ;
		}
	}else if(mod_num<37){
		group_offset = 0x35;
		mod_offset = (mod_num-34) * 3;
	}else if(mod_num ==37){
		group_offset = 0x35;
		mod_offset = (mod_num-34) * 3;
		func_value = (DRV_Reg32(((kal_uint32)IOMUX_MODE_SEL + group_offset*0x04)) & (0x01<<mod_offset)) >> mod_offset;		
		return func_value;
	}
	func_value = (DRV_Reg32(((kal_uint32)IOMUX_MODE_SEL + group_offset*0x04)) & (0x07<<mod_offset)) >> mod_offset;

	return func_value;

}
	

void IOMUX_set_moduleconfig(module_conf_t* iomux_cfg){

	if(iomux_cfg->type == normal){
		IOMUX_set_module_drive(iomux_cfg->cfg_sel, iomux_cfg->drive);
		IOMUX_set_module_rdsel(iomux_cfg->cfg_sel, iomux_cfg->rdsel);
		IOMUX_set_module_tdsel(iomux_cfg->cfg_sel, iomux_cfg->tdsel);
	}
	else if(iomux_cfg->type == msdc0p){
		IOMUX_set_msdc_drive(iomux_cfg->cfg_sel, iomux_cfg->drive);
		IOMUX_set_msdc_rdsel(iomux_cfg->cfg_sel, iomux_cfg->rdsel);
		IOMUX_set_msdc_tdsel(iomux_cfg->cfg_sel, iomux_cfg->tdsel);
		IOMUX_set_msdc0_smt(iomux_cfg->cfg_sel, iomux_cfg->smt);
		IOMUX_set_msdc0_sr(iomux_cfg->cfg_sel, iomux_cfg->sr);

	}
	else if(iomux_cfg->type == msdc1 || iomux_cfg->type == sdio){
		IOMUX_set_msdc_drive(iomux_cfg->cfg_sel, iomux_cfg->drive);
		IOMUX_set_msdc_rdsel(iomux_cfg->cfg_sel, iomux_cfg->rdsel);
		IOMUX_set_msdc_tdsel(iomux_cfg->cfg_sel, iomux_cfg->tdsel);
		IOMUX_set_sdio_r0(iomux_cfg->cfg_sel, iomux_cfg->r0);
		IOMUX_set_sdio_r1(iomux_cfg->cfg_sel, iomux_cfg->r1);
		IOMUX_set_sdio_sr(iomux_cfg->cfg_sel, iomux_cfg->sr);
		IOMUX_set_sdio_smt(iomux_cfg->cfg_sel, iomux_cfg->smt);

	}
	else{
		IOMUX_ERR("Invalid configuration type! type(%d)\r\n", iomux_cfg->type);
	}
	

}
module_conf_t* IOMUX_get_moduleconfig(config_sel_t cfg_sel, module_type_t type){
  	module_conf_t *iomux_cfg = iomux_MemPtr;
	  kal_mem_set(iomux_cfg, 0, sizeof(module_conf_t));

	iomux_cfg->cfg_sel = cfg_sel;
	iomux_cfg->type = type;
	
	if(iomux_cfg->type == normal){
		iomux_cfg->drive = IOMUX_get_module_drive(iomux_cfg->cfg_sel);
		iomux_cfg->rdsel = IOMUX_get_module_rdsel(iomux_cfg->cfg_sel);
		iomux_cfg->tdsel = IOMUX_get_module_tdsel(iomux_cfg->cfg_sel);
	}
	else if(iomux_cfg->type == msdc0p){
		iomux_cfg->drive =IOMUX_get_msdc_drive(iomux_cfg->cfg_sel);
		iomux_cfg->rdsel =IOMUX_get_msdc_rdsel(iomux_cfg->cfg_sel);
		iomux_cfg->tdsel =IOMUX_get_msdc_tdsel(iomux_cfg->cfg_sel);
		iomux_cfg->smt =IOMUX_get_msdc0_smt(iomux_cfg->cfg_sel);
		iomux_cfg->sr =IOMUX_get_msdc0_sr(iomux_cfg->cfg_sel);

	}
	else if(iomux_cfg->type == msdc1 || iomux_cfg->type == sdio){
		iomux_cfg->drive =IOMUX_get_msdc_drive(iomux_cfg->cfg_sel);
		iomux_cfg->rdsel =IOMUX_get_msdc_rdsel(iomux_cfg->cfg_sel);
		iomux_cfg->tdsel =IOMUX_get_msdc_tdsel(iomux_cfg->cfg_sel);
		iomux_cfg->r0 =IOMUX_get_sdio_r0(iomux_cfg->cfg_sel);
		iomux_cfg->r1 =IOMUX_get_sdio_r1(iomux_cfg->cfg_sel);
		iomux_cfg->sr =IOMUX_get_sdio_sr(iomux_cfg->cfg_sel);
		iomux_cfg->smt =IOMUX_get_sdio_smt(iomux_cfg->cfg_sel);

	}

	return iomux_cfg;

};

void IOMUX_init(){
	//kal_uint32 func_num = 0; 
	//IOMUX_PRINT("IOMUX init");
#if defined(MT6290)
#if __FPGA__
//do nothing
#else
	IOMUX_set_module_func(SEL_NFI_0_D, sel_nfi_0);
	IOMUX_set_module_func(SEL_NFI_1_D, sel_nfi_1);
	IOMUX_set_module_func(SEL_NFI_2_D, sel_nfi_2);
	IOMUX_set_module_func(SEL_NFI_3_D, sel_nfi_3);
	IOMUX_set_module_func(SEL_NFI_4_D, sel_nfi_4);
	IOMUX_set_module_func(SEL_JTAG_D, sel_jtag);
	IOMUX_set_module_func(SEL_SPI0_D, sel_spi_0);
	IOMUX_set_module_func(SEL_SPI1_D, sel_spi_1);
	IOMUX_set_module_func(SEL_SUART0_D, sel_suart0);
	IOMUX_set_module_func(SEL_SDIO_D, sel_sdio);
	IOMUX_set_module_func(SEL_MSDC0P_0_D, sel_msdc0p_0);
	IOMUX_set_module_func(SEL_MSDC0P_1_D, sel_msdc0p_1);
	IOMUX_set_module_func(SEL_MSDC0P_2_D, sel_msdc0p_2);
	IOMUX_set_module_func(SEL_MSDC1P_D, sel_msdc1p);
	IOMUX_set_module_func(SEL_PMIC_BSI_D, sel_pmic_bsi);
	IOMUX_set_module_func(SEL_RFIC1_BSI_D, sel_rfic1_bsi);
	IOMUX_set_module_func(SEL_MISC_BSI_0_D, sel_misc_bsi_0);
	IOMUX_set_module_func(SEL_MISC_BSI_1_D, sel_misc_bsi_1);
	IOMUX_set_module_func(SEL_I2C_D, sel_i2c);
	IOMUX_set_module_func(SEL_BPI_0_D, sel_bpi_0);
	IOMUX_set_module_func(SEL_BPI_1_D, sel_bpi_1);
	IOMUX_set_module_func(SEL_BPI_2_D, sel_bpi_2);
	IOMUX_set_module_func(SEL_BPI_3_D, sel_bpi_3);
	IOMUX_set_module_func(SEL_BPI_4_D, sel_bpi_4);
	IOMUX_set_module_func(SEL_BPI_5_D, sel_bpi_5);
	IOMUX_set_module_func(SEL_USIM1_D, sel_usim1);
	IOMUX_set_module_func(SEL_USIM2_D, sel_usim2);
	IOMUX_set_module_func(SEL_GPIO_0_0_D, sel_gpio_0_0);
	IOMUX_set_module_func(SEL_GPIO_1_D, sel_gpio_1);
	IOMUX_set_module_func(SEL_GPIO_2_0_D, sel_gpio_2_0);
	IOMUX_set_module_func(SEL_GPIO_3_D, sel_gpio_3);
	IOMUX_set_module_func(SEL_GPIO_4_D, sel_gpio_4);
	IOMUX_set_module_func(SEL_SDIO_INT_D, sel_sdio_int);
	IOMUX_set_module_func(SEL_DMCMDPHY_D, sel_dmcmdphy);
	IOMUX_set_module_func(SEL_GPIO_0_1_D, sel_gpio_0_1);
	IOMUX_set_module_func(SEL_GPIO_2_1_D, sel_gpio_2_1);

	if(SEL_GPIO_4_D == 0){
		IOMUX_set_module_func(2, sel_idc_rxd);
	}
#if defined(__ANDROID_MODEM__)&& !defined(__X_BOOTING__)
    *(volatile unsigned *)0xBF8A01AC = 0x400;
    *(volatile unsigned *)0xBF8A01B0 = 0x400;
    *(volatile unsigned *)0xBF8A01B4 = 0x400;
    *(volatile unsigned *)0xBF8A01B8 = 0x400;
    *(volatile unsigned *)0xBF8A01BC = 0x400;
#endif
#endif	
#if defined(__SIP_RAM_SIZE__)
	//SET_DMCMDPHY => DBG mode
	//SET GPO46 to debug pin
	DRV_WriteReg32(((kal_uint32)IOMUX_DBG_FLAG_SEL_1), ((DRV_Reg32(((kal_uint32)IOMUX_DBG_FLAG_SEL_1))|(0x01 << 27))));
	DRV_WriteReg32(((kal_uint32)IOMUX_DBG_MODSEL_1), ((DRV_Reg32(((kal_uint32)IOMUX_DBG_MODSEL_1))|(0x07<< 24))));
#else
	//SET_GPIO_0_1 => DBG mode
	//set GPIO3 to debug pin
	DRV_WriteReg32(((kal_uint32)IOMUX_DBG_FLAG_SEL_0), ((DRV_Reg32(((kal_uint32)IOMUX_DBG_FLAG_SEL_0))|(0x08))));
	DRV_WriteReg32(((kal_uint32)IOMUX_DBG_MODSEL_0), ((DRV_Reg32(((kal_uint32)IOMUX_DBG_MODSEL_0))|(0x07))));
#endif
#else
	#error "The chip type is non-supported"
#endif


	
}



