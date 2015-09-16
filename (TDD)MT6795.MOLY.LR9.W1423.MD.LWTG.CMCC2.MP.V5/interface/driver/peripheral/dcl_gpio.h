/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   dcl_gpio.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file of DCL (Driver Common Layer) for GPIO.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef DCL_DEFINITION_STRUCT
#ifndef __DCL_GPIO_H_STRUCT__
#define __DCL_GPIO_H_STRUCT__
//#include "gpio_sw_.h"
#include "drv_features_gpio.h"
#define INPUT			      0		/* IO in input */
#define ALL_INPUT		      0x0000 
#define OUTPUT			      1		/* IO in output */
#define ALL_OUTPUT		   0xffff 

#define GPIO_DIR_INPUT   0
#define GPIO_DIR_OUTPUT  1
#define GPIO_DIR_BOTH    2

#define GPIO_MAGIC_NUM		0x80
#define GPO_MAGIC_NUM		  0x70


#define GPIO_INPUT			      0		/* IO in input */
#define GPIO_ALL_INPUT		      0x0000 
#define GPIO_OUTPUT			      1		/* IO in output */
#define GPIO_ALL_OUTPUT		   0xffff 

#define GPIO_MAGIC_NUM_INTERNAL		0x80
#define GPO_MAGIC_NUM_INTERNAL		  0x70


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(DRV_GPIO_REG_AS_6223) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6253E) || defined(DRV_GPIO_REG_AS_6253E_1)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #if defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6253E) || defined(DRV_GPIO_REG_AS_6253E_1)
/* under construction !*/
/* under construction !*/
   #if defined(DRV_GPIO_REG_AS_6253E_1)
/* under construction !*/
/* under construction !*/
   #endif   /*DRV_GPIO_REG_AS_6253E*/
   #endif   /*DRV_GPIO_REG_AS_6253T*/
#elif defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(DRV_GPIO_REG_AS_6235)
/* under construction !*/
/* under construction !*/
#endif
#elif defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6270A)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #if !defined(DRV_GPIO_REG_AS_6270A)
/* under construction !*/
/* under construction !*/
   #endif//!defined(DRV_GPIO_REG_AS_6270A)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(DRV_GPIO_REG_AS_6236)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(DRV_GPIO_REG_AS_6255)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(DRV_GPIO_REG_AS_6276)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(DRV_GPIO_REG_AS_6251)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

typedef enum {
   mode_default = 0,
   mode_f32k_ck = 0x82,
   mode_max_num 
 } gpio_clk_mode;  
//remove this to see if there are build error .this should be delete. 12-22.
#if 0   
/* under construction !*/
/* under construction !*/
#if defined(DRV_GPIO_REG_AS_6255)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(DRV_GPIO_REG_AS_6276)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //defined(DRV_GPIO_REG_AS_6255)
/* under construction !*/
/* under construction !*/
#endif 



typedef enum {
   div_max_num=16
} gpio_clk_div;	
typedef struct
{
   kal_uint8      pin_num;  /*1,activated ,0:de-activated*/
   kal_uint8      dir; // GPIO_DIR_OUTPUT or GPIO_DIR_INPUT or GPIO_DIR_BOTH
} GPIOCheckStruct;  

/*******************************************************************************
 * DCL_OPTIONS for GPIO
 *******************************************************************************/
#define GPIO_OPTIONS

/*******************************************************************************
 * DCL_CONFIGURE_T
 *******************************************************************************/

/*******************************************************************************
 * DCL_EVENT for GPIO
 *******************************************************************************/
#define GPIO_EVENTS

/*******************************************************************************
 * DCL_CTRL_CMD for GPIO
 *******************************************************************************/
#ifdef __BUILD_DOM__
/*The GPIO Command values in DCL_CTRL_CMD_T Enum of dcl.h*/
/*DCL_CTRL_DATA_T  Define the Control data structure for each module's command*/
typedef enum
{
	 GPIO_CMD_READ, 			 		 /*read data from GPIO Pin*/
   GPIO_CMD_WRITE_LOW,   		 /*write low to GPIO pin*/
   GPIO_CMD_WRITE_HIGH,			 /*write high to GPIO Pin*/
   GPIO_CMD_SET_MODE_0, 		 /*set GPIO mode as mode 0*/
   GPIO_CMD_SET_MODE_1,			 /*set GPIO mode as mode 1*/
   GPIO_CMD_SET_MODE_2,			 /*set GPIO mode as mode 2*/
   GPIO_CMD_SET_MODE_3,			 /*set GPIO mode as mode 3*/
   GPIO_CMD_SET_MODE_4,			 /*set GPIO mode as mode 4 ,only for chip support 4-bit mode*/
   GPIO_CMD_SET_MODE_5,			 /*set GPIO mode as mode 5*,only for chip support 4-bit mode*/
   GPIO_CMD_SET_MODE_6,			 /*set GPIO mode as mode 6*,only for chip support 4-bit mode*/
   GPIO_CMD_SET_MODE_7,			 /*set GPIO mode as mode 7*,only for chip support 4-bit mode*/
   GPIO_CMD_SET_MODE_8,			 /*set GPIO mode as mode 8*,only for chip support 4-bit mode*/
   GPIO_CMD_SET_DIR_OUT, 		 /*set GPIO direction as output*/
   GPIO_CMD_SET_DIR_IN,	 		 /*set GPIO direction as input*/
   GPIO_CMD_RETURN_MODE, 		 /*get current GPIO mode*/
   GPIO_CMD_RETURN_DIR,  		 /*get current GPIO direction*/
   GPIO_CMD_RETURN_OUT,  		 /*get current GPIO output level*/
   GPIO_CMD_ENABLE_PULL, 		 /*enable GPIO pull-up/pull-down seting */
   GPIO_CMD_DISABLE_PULL,		 /*disable GPIO pull-up/pull-down seting*/
   GPIO_CMD_SET_PULL_HIGH,               /*set GPIO as pull-up*/
   GPIO_CMD_SET_PULL_LOW,                /*set GPIO as pull-down*/
   GPIO_CMD_SET_DINV,  			 /*enable or disable GPIO data inversion*/
   GPIO_CMD_SET_DEBUG,  	         /*configure the GPIO sets to auxiliary function mode or to debug mode*/
   GPIO_CMD_SET_CLK_OUT,                 /*select the clock output source of GPIO*/
   GPIO_CMD_SET_CLK_DIV,
   GPIO_CMD_SET_OWNERSHIP_TO_MD, /* to set ownership of a GPIO port to Modem side.*/
   GPIO_CMD_SET_OWNERSHIP_TO_AP, /* to set ownership of a GPIO port to AP side.*/
   GPIO_CMD_SET_DRIVE, /* to set the drive of a GPIO port.*/
   GPIO_CMD_RETURN_DRIVE, /* to return the drive of the GPIO port.*/
   GPIO_CMD_RETURN_OWNERSHIP, /* to return the ownership of the GPIO port. */ 
   GPO_CMD_RETURN_MODE,	  	         /*get current GPO mode*/
   GPO_CMD_RETURN_OUT,    	         /*get current GPO output level*/
   GPO_CMD_WRITE_HIGH,  		 /*write high to GPO Pin*/
   GPO_CMD_WRITE_LOW,  			 /*write low to GPO Pin*/
   GPO_CMD_MODE_SET_0, 			 /*set GPIO mode as mode 0*/
   GPO_CMD_MODE_SET_1,                   /*set GPIO mode as mode 1*/
   GPO_CMD_MODE_SET_2, 			 /*set GPIO mode as mode 2*/
   GPO_CMD_MODE_SET_3,                   /*set GPIO mode as mode 3*/
   GPIO_CMD_SET_DIR_OUT_NO_IRQ_MASK,     /*set GPIO direction as output without  mask IRQ portect*/
   GPIO_CMD_SET_DIR_IN_NO_IRQ_MASK,      /*set GPIO direction as input without  mask IRQ portect*/
   GPIO_CMD_WRITE_HIGH_NO_IRQ_MASK,      /*write high to GPIO Pin without mask IRQ protect*/
   GPIO_CMD_WRITE_LOW_NO_IRQ_MASK,       /*write low to GPIO Pin without mask IRQ protect*/
   GPIO_CMD_READ_NO_IRQ_MASK, 		 /*read data from GPIO Pin without IRQ mask*/
   GPIO_CMD_WRITE_FOR_SPI,		 /*this function is to write data to one GPIO port, that for faster access without debug checking.*/
   GPIO_CMD_GET_AP_PIN,
}DCL_CTRL_CMD_T;
#else
#define GPIO_CMDS    \
   GPIO_CMD_READ,  \
   GPIO_CMD_WRITE_LOW,  \
   GPIO_CMD_WRITE_HIGH,	\
   GPIO_CMD_SET_MODE_0, \
   GPIO_CMD_SET_MODE_1,	\
   GPIO_CMD_SET_MODE_2,	\
   GPIO_CMD_SET_MODE_3,	\
   GPIO_CMD_SET_MODE_4,	\
   GPIO_CMD_SET_MODE_5,	\
   GPIO_CMD_SET_MODE_6,	\
   GPIO_CMD_SET_MODE_7,	\
   GPIO_CMD_SET_MODE_8,	\
   GPIO_CMD_SET_DIR_OUT,\
   GPIO_CMD_SET_DIR_IN,	\
   GPIO_CMD_RETURN_MODE, \
   GPIO_CMD_RETURN_DIR,  \
   GPIO_CMD_RETURN_OUT,  \
   GPIO_CMD_ENABLE_PULL, \
   GPIO_CMD_DISABLE_PULL,\
   GPIO_CMD_SET_PULL_HIGH, \
   GPIO_CMD_SET_PULL_LOW,  \
   GPIO_CMD_SET_DINV,  \
   GPIO_CMD_SET_DEBUG,  \
   GPIO_CMD_SET_CLK_OUT, \
   GPIO_CMD_SET_CLK_DIV, \
   GPIO_CMD_SET_OWNERSHIP_TO_MD, \
   GPIO_CMD_SET_OWNERSHIP_TO_AP, \
   GPIO_CMD_SET_DRIVE, \
   GPIO_CMD_RETURN_DRIVE, \
   GPIO_CMD_RETURN_OWNERSHIP, \
   GPO_CMD_RETURN_MODE,	\
   GPO_CMD_RETURN_OUT, \
   GPO_CMD_WRITE_HIGH, \
   GPO_CMD_WRITE_LOW, \
   GPO_CMD_MODE_SET_0, \
   GPO_CMD_MODE_SET_1, \
   GPO_CMD_MODE_SET_2, \
   GPO_CMD_MODE_SET_3,\
   GPIO_CMD_SET_DIR_OUT_NO_IRQ_MASK, \
   GPIO_CMD_SET_DIR_IN_NO_IRQ_MASK, \
   GPIO_CMD_WRITE_HIGH_NO_IRQ_MASK, \
   GPIO_CMD_WRITE_LOW_NO_IRQ_MASK, \
   GPIO_CMD_READ_NO_IRQ_MASK, \
   GPIO_CMD_WRITE_FOR_SPI,\
   GPIO_CMD_GET_AP_PIN,
#endif /*__BUILD_DOM__*/
#define GPIO_PULL_ENABLE 		1
#define GPIO_PULL_DISABLE		0
#define GPIO_PULL_HIGH			1
#define GPIO_PULL_LOW			0

/* FOR GPIO_CMD_READ control command. */
typedef struct
{
#define GPIO_IO_HIGH    1
#define GPIO_IO_LOW     0
   DCL_UINT8   u1IOData; // GPIO_IO_HIGH or GPIO_IO_LOW
} GPIO_CTRL_READ_T;

/* FOR GPIO_CMD_RETURN_MODE control command. */
typedef struct
{
#define GPIO_MODE_0    0
#define GPIO_MODE_1    1
#define GPIO_MODE_2    2
#define GPIO_MODE_3    3
#define GPIO_MODE_4    4
#define GPIO_MODE_5    5
#define GPIO_MODE_6    6
#define GPIO_MODE_7    7
#define GPIO_MODE_8    8 
   DCL_UINT8   u1RetMode;//Output: to return GPIO_MODE0, GPIO_MODE1, GPIO_MODE2, or GPIO_MODE3
} GPIO_CTRL_RETURN_MODE_T;

/* FOR GPO_CMD_RETURN_MODE control command. */
typedef struct
{
#define GPO_MODE_0    0
#define GPO_MODE_1    1
#define GPO_MODE_2    2
#define GPO_MODE_3    3
   DCL_UINT8   u1RetMode;//Output: to return GPO_MODE0, GPO_MODE1, GPO_MODE2, or GPO_MODE3
} GPO_CTRL_RETURN_MODE_T;

/* FOR GPIO_CMD_RETURN_DIR control command. */
typedef struct
{
#define GPIO_DIR_IN  0
#define GPIO_DIR_OUT 1 
   DCL_UINT8   u1RetDirData;//Output: to return GPIO_DIR_INPUT, or GPIO_DIR_OUTPUT
} GPIO_CTRL_RETURN_DIR_T;

/* FOR GPIO_CMD_RETURN_OUT control command. */
typedef struct
{
   DCL_UINT8   u1RetOutData;//Output: to return  GPIO_IO_HIGH or GPIO_IO_LOW
} GPIO_CTRL_RETURN_OUT_T;

/* FOR GPIO_CMD_RETURN_AP control command. */
typedef struct
{
   DCL_UINT8   u1RetApData;//
} GPIO_CTRL_RETURN_AP_T;

/* FOR GPO_CMD_RETURN_OUT control command. */
typedef struct
{
#define GPO_IO_HIGH 1
#define GPO_IO_LOW	0
   DCL_UINT8   u1RetOutData;//Output: to return  GPO_IO_HIGH or GPO_IO_LOW
} GPO_CTRL_RETURN_OUT_T;

/* FOR GPIO_CMD_SET_DINV control command. */
typedef struct
{
   DCL_BOOL    fgSetDinv; //get more detail in spec.
} GPIO_CTRL_SET_DINV_T;

/* FOR GPIO_CMD_SET_DEBUG control command. */
typedef struct
{
   DCL_BOOL    fgSetDebug;
} GPIO_CTRL_SET_DEBUG_T;

/* FOR GPIO_CMD_SET_CLK_OUT control command. */
typedef struct
{
   DCL_UINT16  u2ClkNum; //clock number in spec.
   gpio_clk_mode u2Mode;
  // DCL_UINT16  u2Mode;	 //the CLKOUT value in spec.(by chip)
} GPIO_CTRL_SET_CLK_OUT_T;


/* FOR GPIO_CMD_SET_CLK_DIV control command. */
typedef struct
{
    DCL_UINT16  u2ClkNum; //clock number in spec.
    gpio_clk_div   u2Div;
    //DCL_UINT16  u2Div;	 //the CLKOUT value in spec.(by chip)
}GPIO_CTRL_SET_CLK_DIV_T;

/* FOR GPIO_CTRL_WRITE_FOR_SPI_T control command. */
typedef struct
{
   DCL_UINT8   data;
   DCL_UINT16  no;
   DCL_UINT16  remainder_shift;
} GPIO_CTRL_WRITE_FOR_SPI_T;

/* FOR GPIO_CMD_SET_DRIVE and GPIO_CMD_RETURN_DRIVE control command. */
typedef struct
{
	#define GPIO_DRIVE_MODE_0 0   // 4mA
	#define GPIO_DRIVE_MODE_1 1   // 8mA
	#define GPIO_DRIVE_MODE_2 2   // 12mA
	#define GPIO_DRIVE_MODE_3 3   // 16mA
	DCL_UINT8 u1DriveMode;  //GPIO drive mode value in spec
}GPIO_CTRL_RETURN_DRIVE_T,GPIO_CTRL_SET_DRIVE_T;


/* FOR GPIO_CMD_RETURN_OWNERSHIP control command. */
typedef struct
{
	#define GPIO_MD_OWNERSHIP 0   
	#define GPIO_AP_OWNERSHIP 1   
	DCL_UINT8 u1OwnerShip;  //GPIO ownership value in spec
}GPIO_CTRL_RETURN_OWNERSHIP_T;


#ifdef __BUILD_DOM__
/*The GPIO command prarmeter data structure for each command. that's enum in in DCL_CTRL_DATA_T*/
typedef struct
{
	 GPIO_CTRL_READ_T              rRead;       /*data structure for GPIO_CMD_READ control command */
   GPIO_CTRL_RETURN_MODE_T       rReturnMode; /*data structure for GPIO_CMD_RETURN_MODE control command*/
   GPIO_CTRL_RETURN_DIR_T        rReturnDir;  /*data structure for GPIO_CMD_RETURN_DIR control command */
   GPIO_CTRL_RETURN_OUT_T        rReturnOut;  /*data structure for GPIO_CMD_RETURN_OUT  control command */
   GPIO_CTRL_RETURN_AP_T         rReturnAp;
   GPIO_CTRL_SET_DINV_T          rSetDinv;    /*data structure for GPIO_CMD_SET_DINV control command */
   GPIO_CTRL_SET_DEBUG_T         rSetDebug; 	/*data structure for GPIO_CMD_SET_DEBUG control command */
   GPIO_CTRL_SET_CLK_OUT_T       rSetClkOut; 	/*data structure for GPIO_CMD_SET_CLK_OUT control command */
   GPIO_CTRL_SET_CLK_DIV_T		 rSetClkDiv;
   GPIO_CTRL_WRITE_FOR_SPI_T     rWriteSpi;	 	/*data structure for GPIO_CTRL_WRITE_FOR_SPI control command */
   GPIO_CTRL_SET_DRIVE_T         rSetDrive;     /*data structure for GPIO_CMD_SET_DRIVE control command */
   GPIO_CTRL_RETURN_DRIVE_T      rReturnDrive;  /*data structure for GPIO_CMD_RETURN_DRIVE control command */
   GPIO_CTRL_RETURN_OWNERSHIP_T  rReturnOwnership; /*data structure for GPIO_CMD_RETURN_OWNERSHIP control command */
   GPO_CTRL_RETURN_MODE_T		     oReturnMode; /*data structure for GPO_CMD_RETURN_OUT control command */
   GPO_CTRL_RETURN_OUT_T		     oReturnOut;	/*data structure for GPO_CMD_RETURN_MODE control command */
}DCL_CTRL_DATA_T;
#else
#define GPIO_CTRLS \
   GPIO_CTRL_READ_T              rRead; \
   GPIO_CTRL_RETURN_MODE_T       rReturnMode; \
   GPIO_CTRL_RETURN_DIR_T        rReturnDir; \
   GPIO_CTRL_RETURN_OUT_T        rReturnOut; \
   GPIO_CTRL_RETURN_AP_T         rReturnAp; \
   GPIO_CTRL_SET_DINV_T          rSetDinv; \
   GPIO_CTRL_SET_DEBUG_T         rSetDebug; \
   GPIO_CTRL_SET_CLK_OUT_T       rSetClkOut; \
   GPIO_CTRL_SET_CLK_DIV_T		 rSetClkDiv; \
   GPIO_CTRL_WRITE_FOR_SPI_T     rWriteSpi;	 \
   GPIO_CTRL_SET_DRIVE_T         rSetDrive;  \
   GPIO_CTRL_RETURN_DRIVE_T      rReturnDrive;  \
   GPIO_CTRL_RETURN_OWNERSHIP_T  rReturnOwnership; \
   GPO_CTRL_RETURN_MODE_T		 		 oReturnMode; \
   GPO_CTRL_RETURN_OUT_T		     oReturnOut;
#endif //__BUILD_DOM__
#endif // #ifndef __DCL_GPIO_H_STRUCT__
#endif // #ifdef DCL_DEFINITION_STRUCT   

#if defined(DCL_DEFINITION_PROTOTYPE)
#ifndef __DCL_GPIO_H_PROTOTYPE__
#define __DCL_GPIO_H_PROTOTYPE__

// MoDIS parser skip start

/*************************************************************************
* FUNCTION
*  DclGPIO_Initialize
*
* DESCRIPTION
*  This function is to initialize GPIO module. Note that all the GPIO pin
* will be set to a predefined state.
*
* PARAMETERS
*	none
*
* RETURN VALUES
*  none
*
*************************************************************************/
extern DCL_STATUS DclGPIO_Initialize(void);

/*************************************************************************
* FUNCTION
*  DclGPIO_Open
* DESCRIPTION
*  This function is to open the GPIO module and get a handle. Note that multiple opens are allowed.
*
* PARAMETERS
*	eDev: - only valid for DCL_GPIO,DCL_GPO,DCL_GPIO_CLK.
*	flags: - no sepcial flags is needed. Please use FLAGS_NONE
*
* RETURN VALUES
*	DCL_HANDLE_INVALID: - Open failed.
* other value: - a valid handle
*
*************************************************************************/
extern DCL_HANDLE DclGPIO_Open(DCL_DEV dev, DCL_FLAGS flags);

/*************************************************************************
* FUNCTION
*  DclGPIO_ReadData
*
* DESCRIPTION
*  This function is not supported for the GPIO module now.
*
* PARAMETERS
*	N/A
*
* RETURN VALUES
*	STATUS_UNSUPPORTED: 
*
*************************************************************************/
extern DCL_STATUS DclGPIO_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options);

/*************************************************************************
* FUNCTION
*  DclGPIO_WriteData
*
* DESCRIPTION
*  This function is not supported for the GPIO module now.
*
* PARAMETERS
*	N/A
*
* RETURN VALUES
*	STATUS_UNSUPPORTED: 
*
*************************************************************************/
extern DCL_STATUS DclGPIO_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options);

/*************************************************************************
* FUNCTION
*  DclGPIO_Configure
*
* DESCRIPTION
*  This function is not supported for the GPIO module now.
*
* PARAMETERS
*	N/A
*
* RETURN VALUES 
*	STATUS_UNSUPPORTED:
*
*************************************************************************/
extern DCL_STATUS DclGPIO_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure);

/*************************************************************************
* FUNCTION
*  DclGPIO_RegisterCallback
*
* DESCRIPTION
*  This function is not supported for the GPIO module now.
*
* PARAMETERS
*	N/A
*
* RETURN VALUES
*	STATUS_UNSUPPORTED: 
*
*************************************************************************/
extern DCL_STATUS DclGPIO_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback);

/*************************************************************************
* FUNCTION
*  DclGPIO_Control
*
* DESCRIPTION
*  This function is to send command to control the GPIO module.
*
* PARAMETERS
* handle: - a valid handle return by DclGPIO_Open()
* cmd: 	  - a control command for GPIO module
*          1. GPIO_CMD_READ: to read the input value from the GPIO port contain in handle.
*          2. GPIO_CMD_WRITE_LOW: to write low to the output of GPIO port contain in handle.
*          3. GPIO_CMD_WRITE_HIGH: to write high to the output of  GPIO port contain in handle.
*          4. GPIO_CMD_SET_MODE_0: to set the mode of the GPIO port contain in handle as mode 0.
*          5. GPIO_CMD_SET_MODE_1: to set the mode of the GPIO port contain in handle as mode 1.
*          6. GPIO_CMD_SET_MODE_2: to set the mode of the GPIO port contain in handle as mode 2.
*          7. GPIO_CMD_SET_MODE_3: to set the mode of the GPIO port contain in handle as mode 3.
*          8. GPIO_CMD_SET_DIR_OUT: to set the direction of the GPIO port as output.
*          9. GPIO_CMD_SET_DIR_IN: to set the direction of the GPIO port as input.
*         10. GPIO_CMD_RETURN_MODE: to get the mode of the GPIO port
*         11. GPIO_CMD_RETURN_DIR: to get the direction of the GPIO port
*         12. GPIO_CMD_RETURN_OUT: to return the output value of the GPIO port
*         13. GPIO_CMD_ENABLE_PULL: to enable the pull resister for a GPIO port
*         14. GPIO_CMD_DISABLE_PULL: to disenable the pull resister for a GPIO port
*         15. GPIO_CMD_SET_PULL_HIGH: to select the pull up for a GPIO port
*         16. GPIO_CMD_SET_PULL_LOW: to select the pull down for a GPIO port
*         17. GPIO_CMD_SET_DINV: to set the inversion of a GPIO port
*         18. GPIO_CMD_SET_DEBUG: to enable or disable debug mode
*         19. GPIO_CMD_SET_CLK_OUT: to set the clock frequency for a clock output
*         20. GPIO_CMD_SET_OWNERSHIP_TO_MD: to set ownership of a GPIO port to Modem side.
*         21. GPIO_CMD_SET_OWNERSHIP_TO_AP: to set ownership of a GPIO port to AP side.
*         22. GPIO_CMD_SET_DRIVE: to set the drive of a GPIO port.
*         23. GPIO_CMD_RETURN_DRIVE: to return the drive of the GPIO port.
*         24. GPIO_CMD_RETURN_OWNERSHIP: to return the ownership of the GPIO port.
*         25. GPO_CMD_RETURN_MODE: to get the mode of the GPO port
*         26. GPO_CMD_RETURN_OUT: to return the output value of the GPO port
*         27. GPO_CMD_WRITE_HIGH: to write high to the output of  GPO port contain in handle.
*         28. GPO_CMD_WRITE_LOW: to write low to the output of GPO port contain in handle.
*         29. GPO_CMD_MODE_SET_0: to set the mode of the GPIO port contain in handle as mode 0.
*         30. GPO_CMD_MODE_SET_1: to set the mode of the GPI1 port contain in handle as mode 1.
*         31. GPO_CMD_MODE_SET_2: to set the mode of the GPI2 port contain in handle as mode 2.
*         32. GPO_CMD_MODE_SET_3: to set the mode of the GPI3 port contain in handle as mode 3.

*         33. GPIO_CMD_SET_DIR_OUT_NO_IRQ_MASK: to set the direction of the GPIO port as output without IRQ protect.
*         34. GPIO_CMD_SET_DIR_IN_NO_IRQ_MASK:  to set the direction of the GPIO port as input without IRQ protect
*         35. GPIO_CMD_WRITE_HIGH_NO_IRQ_MASK:  to write high to the output of  GPIO port contain in handle without IRQ protect.
*         36. GPIO_CMD_WRITE_LOW_NO_IRQ_MASK:	  to write low to the output of GPIO port contain in handle without IRQ protect.
*         37. GPIO_CMD_READ_NO_IRQ_MASK:		  to read the input value from the GPIO port contain in handle without IRQ protect..

*         38. GPIO_CMD_WRITE_FOR_SPI_T: 
* data: - data for GPIO control command.
*          1. GPIO_CMD_READ: pointer to a GPIO_CTRLS structure
*          2. GPIO_CMD_WRITE_LOW:		NULL.
*          3. GPIO_CMD_WRITE_HIGH:		NULL.
*          4. GPIO_CMD_SET_MODE_0:		NULL.
*          5. GPIO_CMD_SET_MODE_1:		NULL.
*          6. GPIO_CMD_SET_MODE_2:		NULL.
*          7. GPIO_CMD_SET_MODE_3:		NULL.
*          8. GPIO_CMD_SET_DIR_OUT:		NULL.
*          9. GPIO_CMD_SET_DIR_IN:		NULL.
*         10. GPIO_CMD_RETURN_MODE: pointer to a GPIO_CTRL_RETURN_MODE_T structure
*         11. GPIO_CMD_RETURN_DIR:  pointer to a GPIO_CTRL_SET_DIR_T structure
*         12. GPIO_CMD_RETURN_OUT:  pointer to a GPIO_CTRL_RETURN_OUT_T structure
*         13. GPIO_CMD_ENABLE_PULL:		NULL.
*         14. GPIO_CMD_DISABLE_PULL:	NULL.
*         15. GPIO_CMD_SET_PULL_HIGH:	NULL.	
*         16. GPIO_CMD_SET_PULL_LOW:	NULL.
*         17. GPIO_CMD_SET_DINV:  pointer to a GPIO_CTRL_SET_DINV_T structure
*         18. GPIO_CMD_SET_DEBUG: pointer to a GPIO_CTRL_SET_DEBUG_T structure
*         19. GPIO_CMD_SET_CLK_OUT: pointer to a GPIO_CTRL_SET_CLK_OUT_T structure
*		  20. GPIO_CMD_SET_OWNERSHIP_TO_MD: NULL.
*         21. GPIO_CMD_SET_OWNERSHIP_TO_AP: NULL.
*         22. GPIO_CMD_SET_DRIVE: pointer to a GPIO_CTRL_SET_DRIVE_T structure
*         23. GPIO_CMD_RETURN_DRIVE: pointer to a GPIO_CTRL_RETURN_DRIVE_T structure
*         24. GPIO_CMD_RETURN_OWNERSHIP: pointer to a GPIO_CTRL_RETURN_OWNERSHIP_T structure
*
*         25. GPO_CMD_RETURN_MODE: pointer to a GPO_CTRL_RETURN_MODE_T structure
*         26. GPO_CMD_RETURN_OUT:  pointer to a GPO_CTRL_RETURN_OUT_T structure
*         27. GPO_CMD_WRITE_HIGH: NULL.
*         28. GPO_CMD_WRITE_LOW:  NULL.
*         29. GPO_CMD_MODE_SET_0: NULL..
*         30. GPO_CMD_MODE_SET_1: NULL..
*         31. GPO_CMD_MODE_SET_2: NULL.
*         32. GPO_CMD_MODE_SET_3: NULL.

*         33. GPIO_CMD_SET_DIR_OUT_NO_IRQ_MASK: NULL.
*         34. GPIO_CMD_SET_DIR_IN_NO_IRQ_MASK:  NULL.
*         35. GPIO_CMD_WRITE_HIGH_NO_IRQ_MASK:  NULL.
*         36. GPIO_CMD_WRITE_LOW_NO_IRQ_MASK:	  NULL.
*         37. GPIO_CMD_READ_NO_IRQ_MASK:		  pointer to a GPIO_CTRLS structure

*         38. GPIO_CMD_WRITE_FOR_SPI_T: pointer to GPIO_CTRL_WRITE_FOR_SPI_T
* RETURN VALUES
*	STATUS_OK: - command is executed successfully.
*	STATUS_FAIL: - command is failed.
* STATUS_INVALID_CMD: - The command is invalid.
* STATUS_INVALID_DCL_HANDLE: - The handle is invalid.
* STATUS_INVALID_CTRL_DATA: - The ctrl data is not valid.
*************************************************************************/
extern DCL_STATUS DclGPIO_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);

/*************************************************************************
* FUNCTION
*  DclGPIO_Close
*
* DESCRIPTION
*  This function is not supported for the GPIO module now.
*
* PARAMETERS
*	handle: the handle that return by DclGPIO_Open.
*
* RETURN VALUES:
*	STATUS_UNSUPPORTED:
*
*************************************************************************/
extern DCL_STATUS DclGPIO_Close(DCL_HANDLE handle);

// MoDIS parser skip end

#endif // #ifndef __DCL_GPIO_H_PROTOTYPE__
#endif // #ifdef DCL_DEFINITION_PROTOTYPE


