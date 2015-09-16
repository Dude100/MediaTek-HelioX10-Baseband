
#ifndef	GPIO_DRV_07_13_11
#define GPIO_DRV_07_13_11

#include "drv_comm.h"
#include "dcl.h"
#include "kal_debug.h"

#if !defined(GPIO_DUMMY_FUN)

#if defined(DRV_GPIO_REG_AS_6290) || defined(DRV_GPIO_REG_AS_6595)	|| defined(DRV_GPIO_REG_AS_6752)

#define BU_G_FLD(_i,_ms,_ls)	    (((_i)<<(31-(_ms))) >> (31- (_ms) + (_ls)))
#define BU_G_BIT(_i,_n)				BU_G_FLD(_i, _n, _n)

#ifdef __DRV_GPIO_REG_DBG__

#define DRV_GPIO_WriteReg(addr,data)    DRV_DBG_WriteReg32(addr,data)
#define DRV_GPIO_Reg(addr)              DRV_DBG_Reg32(addr)
#define DRV_GPIO_WriteReg32(addr,data)  DRV_DBG_WriteReg32(addr,data)
#define DRV_GPIO_Reg32(addr)            DRV_DBG_Reg32(addr)
#define DRV_GPIO_WriteReg8(addr,data)   DRV_DBG_WriteReg8(addr,data)
#define DRV_GPIO_Reg8(addr)             DRV_DBG_Reg8(addr)


#define DRV_GPIO_ClearBits(addr,data)   DRV_DBG_ClearBits(addr,data)
#define DRV_GPIO_SetBits(addr,data)     DRV_DBG_SetBits(addr,data)
#define DRV_GPIO_ClearBits32(addr,data) DRV_DBG_ClearBits32(addr,data)
#define DRV_GPIO_SetBits32(addr,data)   DRV_DBG_SetBits32(addr,data)
#define DRV_GPIO_ClearBits8(addr,data)  DRV_DBG_ClearBits8(addr,data)
#define DRV_GPIO_SetBits8(addr,data)    DRV_DBG_SetBits8(addr,data)

#define DRV_GPIO_SetData(addr, bitmask, value)     DRV_DBG_SetData(addr, bitmask, value)
#define DRV_GPIO_SetData32(addr, bitmask, value)   DRV_DBG_SetData32(addr, bitmask, value)
#define DRV_GPIO_SetData8(addr, bitmask, value)    DRV_DBG_SetData8(addr, bitmask, value)

#else //__DRV_GPIO_REG_DBG__

#define DRV_GPIO_WriteReg(addr,data)    DRV_WriteReg32(addr,data)
#define DRV_GPIO_Reg(addr)              DRV_Reg32(addr)
#define DRV_GPIO_WriteReg32(addr,data)  DRV_WriteReg32(addr,data)
#define DRV_GPIO_Reg32(addr)            DRV_Reg32(addr)
#define DRV_GPIO_WriteReg8(addr,data)   DRV_WriteReg8(addr,data)
#define DRV_GPIO_Reg8(addr)             DRV_Reg8(addr)


#define DRV_GPIO_ClearBits(addr,data)   DRV_ClearBits32(addr,data)
#define DRV_GPIO_SetBits(addr,data)     DRV_DBGD_SetBits32(addr,data)
#define DRV_GPIO_ClearBits32(addr,data) DRV_ClearBits32(addr,data)
#define DRV_GPIO_SetBits32(addr,data)   DRV_DBGD_SetBits32(addr,data)
#define DRV_GPIO_ClearBits8(addr,data)  DRV_ClearBits8(addr,data)
#define DRV_GPIO_SetBits8(addr,data)    DRV_SetBits8(addr,data)

#define DRV_GPIO_SetData(addr, bitmask, value)     DRV_SetData32(addr, bitmask, value)
#define DRV_GPIO_SetData32(addr, bitmask, value)   DRV_SetData32(addr, bitmask, value)
#define DRV_GPIO_SetData8(addr, bitmask, value)    DRV_SetData8(addr, bitmask, value)

#endif //__DRV_GPIO_REG_DBG__

#ifdef __MTK_TARGET__
#define EN_GPIO_PRINTF 1

#if EN_GPIO_PRINTF
extern void dbg_print(char *fmt,...);

#define GPIO_PRINT(fmt, var ...)	do {dbg_print(fmt"\n\r", ##var);} while (0)
#define GPIO_PRINTN(fmt, var ...)	do {dbg_print(fmt, ##var);} while (0)
#define GPIO_ERR(fmt, var ...)		do {GPIO_PRINT("ERROR [%s:%d]"fmt, __FUNCTION__, __LINE__, ##var);} while (0)
#define GPIO_WARN(fmt, var ...)	do {GPIO_PRINT("WARNING [%s:%d]"fmt, __FUNCTION__, __LINE__, ##var);} while (0)
#else 
#define GPIO_PRINT(fmt, var ...)	
#define GPIO_PRINTN(fmt, var ...)	
#define GPIO_ERR(fmt, var ...)		
#define GPIO_WARN(fmt, var ...)	
#endif
#endif
#define REG32(addr)					(*((volatile unsigned int*)(addr)))
#define REG32_WRITE(addr, value)		do {(*((volatile unsigned int*)(addr))) = (unsigned int)(value);}while (0)

#define GPIO_OK    (0)
#define GPIO_FAIL  (-1)
#if defined(MT6290)
#define GPIO_PIN_MAX		64
#elif defined(MT6595)
#define GPIO_PIN_MAX		214
#elif defined(MT6752) && defined(__MD1__)
#define GPIO_PIN_MAX		186
#endif
#define GPIO_AS_INPUT					0
#define GPIO_AS_OUTPUT					1
#define GPIO_DISABLE					0
#define GPIO_ENABLE						1
#define GPIO_PULL_DOWN					0
#define GPIO_PULL_UP					1
#define GPIO_OUTPUT_LOW					0
#define GPIO_OUTPUT_HIGH				1
#define GPIO_OWNERSHIP_AP				1
#define GPIO_OWNERSHIP_MD 				0
#define GPIO_DRIVE_NUM_PER_REG 16
#define GPIO_DRIVE_BIT_NUM 2

#if defined(MT6290)
//#define GPIO_BASE_ADDR					BASE_ADDR_MDGPIO
//#define GPIOMUX_BASE_ADDR				BASE_ADDR_GPIOMUX
#define GPIO_ADDR_OFFSET					0xF0
#define GPIO_BASE_ADDR					BASE_ADDR_MDGPIOMUX + GPIO_ADDR_OFFSET
#define GPIOMUX_BASE_ADDR				BASE_ADDR_MDGPIOMUX

#define GPIO_DIR1 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x10))
#define GPIO_DIR2 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x20))
#define GPIO_PULLEN1 	((volatile unsigned int*)(GPIO_BASE_ADDR + 0x90))
#define GPIO_PULLEN2 	((volatile unsigned int*)(GPIO_BASE_ADDR + 0xA0))
#define GPIO_PULLSEL1 	((volatile unsigned int*)(GPIO_BASE_ADDR + 0x110))
#define GPIO_PULLSEL2 	((volatile unsigned int*)(GPIO_BASE_ADDR + 0x120))
#define GPIO_DINV1 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x190))
#define GPIO_DINV2 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x1A0))
#define GPIO_DOUT1 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x210))
#define GPIO_DOUT2 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x220))
#define GPIO_DIN1 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x290))
#define GPIO_DIN2 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x2A0))

/* Following registers only could be tested in ASIC */
/* ================================================================= */
#define GPIO_DRIVE1 	((volatile unsigned int*)(GPIO_BASE_ADDR + 0x310))
#define GPIO_DRIVE2 	((volatile unsigned int*)(GPIO_BASE_ADDR + 0x320))
#define GPIO_DRIVE3 	((volatile unsigned int*)(GPIO_BASE_ADDR + 0x330))
#define GPIO_DRIVE4 	((volatile unsigned int*)(GPIO_BASE_ADDR + 0x340))

/* Set and Clear Registers*/
/* ================================================================= */
#define GPIO_DIR1_SET 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x10 + 0x4))
#define GPIO_DIR2_SET 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x20 + 0x4))
#define GPIO_PULLEN1_SET 	((volatile unsigned int*)(GPIO_BASE_ADDR + 0x90 + 0x4))
#define GPIO_PULLEN2_SET 	((volatile unsigned int*)(GPIO_BASE_ADDR + 0xA0 + 0x4))
#define GPIO_PULLSEL1_SET 	((volatile unsigned int*)(GPIO_BASE_ADDR + 0x110 + 0x4))
#define GPIO_PULLSEL2_SET 	((volatile unsigned int*)(GPIO_BASE_ADDR + 0x120 + 0x4))
#define GPIO_DINV1_SET 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x190 + 0x4))
#define GPIO_DINV2_SET 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x1A0 + 0x4))
#define GPIO_DOUT1_SET 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x210 + 0x4))
#define GPIO_DOUT2_SET 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x220 + 0x4))
//#define GPIO_DIN1_SET 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x290 + 0x4))
//#define GPIO_DIN2_SET 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x2A0 + 0x4))

#define GPIO_DIR1_CLR 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x10 + 0x8))
#define GPIO_DIR2_CLR 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x20 + 0x8))
#define GPIO_PULLEN1_CLR 	((volatile unsigned int*)(GPIO_BASE_ADDR + 0x90 + 0x8))
#define GPIO_PULLEN2_CLR 	((volatile unsigned int*)(GPIO_BASE_ADDR + 0xA0 + 0x8))
#define GPIO_PULLSEL1_CLR 	((volatile unsigned int*)(GPIO_BASE_ADDR + 0x110 + 0x8))
#define GPIO_PULLSEL2_CLR 	((volatile unsigned int*)(GPIO_BASE_ADDR + 0x120 + 0x8))
#define GPIO_DINV1_CLR 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x190 + 0x8))
#define GPIO_DINV2_CLR 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x1A0 + 0x8))
#define GPIO_DOUT1_CLR 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x210 + 0x8))
#define GPIO_DOUT2_CLR 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x220 + 0x8))
#define GPIO_DIN1_CLR 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x290 + 0x8))
#define GPIO_DIN2_CLR 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x2A0 + 0x8))



/* Following registers are read back value ,read only */
/* ================================================================= */
#define GPIO_SEL_DOUT1		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x410))
#define GPIO_SEL_DOUT2		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x420))
#define GPIO_SEL_DIR1		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x490))
#define GPIO_SEL_DIR2		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x4A0))
#define GPIO_SEL_PLUP1		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x510))
#define GPIO_SEL_PLUP2		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x520))
#define GPIO_SEL_PLDN1		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x590))
#define GPIO_SEL_PLDN2		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x5A0))
#define GPIO_SEL_DRIVE1		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x610))
#define GPIO_SEL_DRIVE2		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x620))
#define GPIO_SEL_DRIVE3		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x630))
#define GPIO_SEL_DRIVE4		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x640))


/* Following registers are GPIO MUX PART */
/* ================================================================= */
#define GPIOMUX_GPIO_OWN1		((volatile unsigned int*)(GPIOMUX_BASE_ADDR + 0x10 ))//- GPIO_ADDR_OFFSET))
#define GPIOMUX_GPIO_OWN2		((volatile unsigned int*)(GPIOMUX_BASE_ADDR + 0x20 ))//- GPIO_ADDR_OFFSET))

/**
 * @brief	GPIO drive value
 */
typedef enum {	/* GPIO DRIVE items */
	GPIO_DRIVE_4MA,
	GPIO_DRIVE_8MA,
	GPIO_DRIVE_12MA,
	GPIO_DRIVE_16MA,
} gpio_drive_e;

/**
 * @brief	GPIO Pin Enumeration
 */
typedef enum {	
	GPIO_PIN0=0,
	GPIO_PIN1,
	GPIO_PIN2,
	GPIO_PIN3,
	GPIO_PIN4,
	GPIO_PIN5,
	GPIO_PIN6,
	GPIO_PIN7,
	GPIO_PIN8,
	GPIO_PIN9,
	GPIO_PIN10,
	GPIO_PIN11,
	GPIO_PIN12,
	GPIO_PIN13,
	GPIO_PIN14,
	GPIO_PIN15,
	GPIO_PIN16,
	GPIO_PIN17,
	GPIO_PIN18,
	GPIO_PIN19,
	GPIO_PIN20,
	GPIO_PIN21,
	GPIO_PIN22,
	GPIO_PIN23,
	GPIO_PIN24,
	GPIO_PIN25,
	GPIO_PIN26,
	GPIO_PIN27,
	GPIO_PIN28,
	GPIO_PIN29,
	GPIO_PIN30,
	GPIO_PIN31,
	GPIO_PIN32,
	GPIO_PIN33,
	GPIO_PIN34,
	GPIO_PIN35,
	GPIO_PIN36,
	GPIO_PIN37,
	GPIO_PIN38,
	GPIO_PIN39,
	GPIO_PIN40,
	GPIO_PIN41,
	GPIO_PIN42,
	GPIO_PIN43,
	GPIO_PIN44,
	GPIO_PIN45,
	GPIO_PIN46,
	GPIO_PIN47,
	GPIO_PIN48,
	GPIO_PIN49,
	GPIO_PIN50,
	GPIO_PIN51,
	GPIO_PIN52,
	GPIO_PIN53,
	GPIO_PIN54,
	GPIO_PIN55,
	GPIO_PIN56,
	GPIO_PIN57,
	GPIO_PIN58,
	GPIO_PIN59,
	GPIO_PIN60,
	GPIO_PIN61,
	GPIO_PIN62,
	GPIO_PIN63,
} gpio_pin_e;

#elif defined(MT6595)

typedef enum {	
	GPIO_PIN0=0,
	GPIO_PIN1,
	GPIO_PIN2,
	GPIO_PIN3,
	GPIO_PIN4,
	GPIO_PIN5,
	GPIO_PIN6,
	GPIO_PIN7,
	GPIO_PIN8,
	GPIO_PIN9,
	GPIO_PIN10,
	GPIO_PIN11,
	GPIO_PIN12,
	GPIO_PIN13,
	GPIO_PIN14,
	GPIO_PIN15,
	GPIO_PIN16,
	GPIO_PIN17,
	GPIO_PIN18,
	GPIO_PIN19,
	GPIO_PIN20,
	GPIO_PIN21,
	GPIO_PIN22,
	GPIO_PIN23,
	GPIO_PIN24,
	GPIO_PIN25,
	GPIO_PIN26,
	GPIO_PIN27,
	GPIO_PIN28,
	GPIO_PIN29,
	GPIO_PIN30,
	GPIO_PIN31,
	GPIO_PIN32,
	GPIO_PIN33,
	GPIO_PIN34,
	GPIO_PIN35,
	GPIO_PIN36,
	GPIO_PIN37,
	GPIO_PIN38,
	GPIO_PIN39,
	GPIO_PIN40,
	GPIO_PIN41,
	GPIO_PIN42,
	GPIO_PIN43,
	GPIO_PIN44,
	GPIO_PIN45,
	GPIO_PIN46,
	GPIO_PIN47,
	GPIO_PIN48,
	GPIO_PIN49,
	GPIO_PIN50,
	GPIO_PIN51,
	GPIO_PIN52,
	GPIO_PIN53,
	GPIO_PIN54,
	GPIO_PIN55,
	GPIO_PIN56,
	GPIO_PIN57,
	GPIO_PIN58,
	GPIO_PIN59,
	GPIO_PIN60,
	GPIO_PIN61,
	GPIO_PIN62,
	GPIO_PIN63,
	GPIO_PIN64,
	GPIO_PIN65,
	GPIO_PIN66,
	GPIO_PIN67,
	GPIO_PIN68,
	GPIO_PIN69,
	GPIO_PIN70,
	GPIO_PIN71,
	GPIO_PIN72,
	GPIO_PIN73,
	GPIO_PIN74,
	GPIO_PIN75,
	GPIO_PIN76,
	GPIO_PIN77,
	GPIO_PIN78,
	GPIO_PIN79,
	GPIO_PIN80,
	GPIO_PIN81,
	GPIO_PIN82,
	GPIO_PIN83,
	GPIO_PIN84,
	GPIO_PIN85,
	GPIO_PIN86,
	GPIO_PIN87,
	GPIO_PIN88,
	GPIO_PIN89,
	GPIO_PIN90,
	GPIO_PIN91,
	GPIO_PIN92,
	GPIO_PIN93,
	GPIO_PIN94,
	GPIO_PIN95,
	GPIO_PIN96,
	GPIO_PIN97,
	GPIO_PIN98,
	GPIO_PIN99,
	GPIO_PIN100,
	GPIO_PIN101,
	GPIO_PIN102,
	GPIO_PIN103,
	GPIO_PIN104,	
} gpio_pin_e;

   #define 	GPIO_DIR1       	(GPIO_base+0x0000)
   #define 	GPIO_PULLEN1    	(GPIO_base+0x0100)
   #define 	GPIO_PULLSEL1    	(GPIO_base+0x0200)
   #define 	GPIO_DOUT1      	(GPIO_base+0x0400)
   #define 	GPIO_DIN1       	(GPIO_base+0x0500)
   #define 	GPIO_MODE1       	(GPIO_base+0x0600)

   
   #define 	GPIO_DIR1_SET       (GPIO_DIR1+0x04)
   #define 	GPIO_PULLEN1_SET    (GPIO_PULLEN1+0x04) 
   #define 	GPIO_PULLSEL1_SET   (GPIO_PULLSEL1+0x04) 
   #define 	GPIO_DOUT1_SET      (GPIO_DOUT1+0x04)
   #define 	GPIO_MODE1_SET       	(GPIO_MODE1+0x04)
   #define  GPIO_MODE_SET(_no)  (GPIO_MODE1_SET+(0x10*(_no)))
   #define  GPIO_DIR_SET(_no)   (GPIO_DIR1_SET+(0x10*(_no)))
   #define  GPIO_DOUT_SET(_no)  (GPIO_DOUT1_SET+(0x10*(_no)))
   
   #define 	GPIO_DIR1_CLR       (GPIO_DIR1+0x08)
   #define 	GPIO_PULLEN1_CLR    (GPIO_PULLEN1+0x08)
   #define 	GPIO_DOUT1_CLR      (GPIO_DOUT1+0x08)
   #define 	GPIO_MODE1_CLR      (GPIO_MODE1+0x08)
 
   #define  GPIO_MODE_CLR(_no)  (GPIO_MODE1_CLR+(0x10*(_no)))
   #define  GPIO_DIR_CLR(_no)   (GPIO_DIR1_CLR+(0x10*(_no)))
   #define  GPIO_DOUT_CLR(_no)  (GPIO_DOUT1_CLR+(0x10*(_no)))
   
   #define  GPIO_MODE(_no)      (GPIO_MODE1+(0x10*(_no))) 
   #define  GPIO_DOUT(_no)      (GPIO_DOUT1+(0x10*(_no)))
   #define  GPIO_DIR(_no)       (GPIO_DIR1+(0x10*(_no))) 
   #define  GPIO_DIN(_no)       (GPIO_DIN1+(0x10*(_no))) 
#elif defined(MT6752) && defined(__MD1__)
typedef enum {	
	GPIO_PIN0=0,
	GPIO_PIN1,
	GPIO_PIN2,
	GPIO_PIN3,
	GPIO_PIN4,
	GPIO_PIN5,
	GPIO_PIN6,
	GPIO_PIN7,
	GPIO_PIN8,
	GPIO_PIN9,
	GPIO_PIN10,
	GPIO_PIN11,
	GPIO_PIN12,
	GPIO_PIN13,
	GPIO_PIN14,
	GPIO_PIN15,
	GPIO_PIN16,
	GPIO_PIN17,
	GPIO_PIN18,
	GPIO_PIN19,
	GPIO_PIN20,
	GPIO_PIN21,
	GPIO_PIN22,
	GPIO_PIN23,
	GPIO_PIN24,
	GPIO_PIN25,
	GPIO_PIN26,
	GPIO_PIN27,
	GPIO_PIN28,
	GPIO_PIN29,
	GPIO_PIN30,
	GPIO_PIN31,
	GPIO_PIN32,
	GPIO_PIN33,
	GPIO_PIN34,
	GPIO_PIN35,
	GPIO_PIN36,
	GPIO_PIN37,
	GPIO_PIN38,
	GPIO_PIN39,
	GPIO_PIN40,
	GPIO_PIN41,
	GPIO_PIN42,
	GPIO_PIN43,
	GPIO_PIN44,
	GPIO_PIN45,
	GPIO_PIN46,
	GPIO_PIN47,
	GPIO_PIN48,
	GPIO_PIN49,
	GPIO_PIN50,
	GPIO_PIN51,
	GPIO_PIN52,
	GPIO_PIN53,
	GPIO_PIN54,
	GPIO_PIN55,
	GPIO_PIN56,
	GPIO_PIN57,
	GPIO_PIN58,
	GPIO_PIN59,
	GPIO_PIN60,
	GPIO_PIN61,
	GPIO_PIN62,
	GPIO_PIN63,
	GPIO_PIN64,
	GPIO_PIN65,
	GPIO_PIN66,
	GPIO_PIN67,
	GPIO_PIN68,
	GPIO_PIN69,
	GPIO_PIN70,
	GPIO_PIN71,
	GPIO_PIN72,
	GPIO_PIN73,
	GPIO_PIN74,
	GPIO_PIN75,
	GPIO_PIN76,
	GPIO_PIN77,
	GPIO_PIN78,
	GPIO_PIN79,
	GPIO_PIN80,
	GPIO_PIN81,
	GPIO_PIN82,
	GPIO_PIN83,
	GPIO_PIN84,
	GPIO_PIN85,
	GPIO_PIN86,
	GPIO_PIN87,
	GPIO_PIN88,
	GPIO_PIN89,
	GPIO_PIN90,
	GPIO_PIN91,
	GPIO_PIN92,
	GPIO_PIN93,
	GPIO_PIN94,
	GPIO_PIN95,
	GPIO_PIN96,
	GPIO_PIN97,
	GPIO_PIN98,
	GPIO_PIN99,
	GPIO_PIN100,
	GPIO_PIN101,
	GPIO_PIN102,
	GPIO_PIN103,
	GPIO_PIN104,	
} gpio_pin_e;

   #define 	GPIO_DIR1       	(GPIO_base+0x0000)
   #define 	GPIO_DOUT1      	(GPIO_base+0x0100)
   #define 	GPIO_DIN1       	(GPIO_base+0x0200)
   #define 	GPIO_MODE1       	(GPIO_base+0x0300)

   
   #define 	GPIO_DIR1_SET       (GPIO_DIR1+0x04)
   #define 	GPIO_DOUT1_SET      (GPIO_DOUT1+0x04)
   #define 	GPIO_MODE1_SET       	(GPIO_MODE1+0x04)
   #define  GPIO_MODE_SET(_no)  (GPIO_MODE1_SET+(0x10*(_no)))
   #define  GPIO_DIR_SET(_no)   (GPIO_DIR1_SET+(0x10*(_no)))
   #define  GPIO_DOUT_SET(_no)  (GPIO_DOUT1_SET+(0x10*(_no)))
   
   #define 	GPIO_DIR1_CLR       (GPIO_DIR1+0x08)
   #define 	GPIO_DOUT1_CLR      (GPIO_DOUT1+0x08)
   #define 	GPIO_MODE1_CLR      (GPIO_MODE1+0x08)
 
   #define  GPIO_MODE_CLR(_no)  (GPIO_MODE1_CLR+(0x10*(_no)))
   #define  GPIO_DIR_CLR(_no)   (GPIO_DIR1_CLR+(0x10*(_no)))
   #define  GPIO_DOUT_CLR(_no)  (GPIO_DOUT1_CLR+(0x10*(_no)))
   
   #define  GPIO_MODE(_no)      (GPIO_MODE1+(0x10*(_no))) 
   #define  GPIO_DOUT(_no)      (GPIO_DOUT1+(0x10*(_no)))
   #define  GPIO_DIR(_no)       (GPIO_DIR1+(0x10*(_no))) 
   #define  GPIO_DIN(_no)       (GPIO_DIN1+(0x10*(_no))) 
#endif

extern void gpio_init(void);
extern void GPIO_InitIO(char direction, char port);
extern char GPIO_ReadIO(char port);
extern void GPIO_WriteIO(char data, char port);
extern char GPIO_ReturnMode(char port);
extern char GPO_ReturnMode(char port);
extern char GPIO_ReturnDir(char port);
extern char GPIO_ReturnDout(char port);
extern char GPO_ReturnDout(char port);
extern void GPO_WriteIO(char data,char port);
extern void GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada);
extern void GPO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada);
extern void initGPIO(void);
extern void GPIO_PullenSetup(kal_uint16 pin, kal_bool enable);
extern void GPIO_DinvSetup(kal_uint16 pin, kal_bool enable);
extern void GPIO_SetDebugMode(kal_bool enable); 
extern void GPIO_PullSelSetup(kal_uint16 pin, kal_bool pull_up);
#ifdef __CUST_NEW__
extern void GPIO_InitIO_FAST(char direction, char port);
extern char GPIO_ReadIO_FAST(char port);
extern void GPIO_WriteIO_FAST(char data, char port);
#endif/* __CUST_NEW__ */
extern void GPIO_WriteIO_FAST2(char data, kal_uint16 no, kal_uint16 remainder_shift);
extern kal_int32 gpio_set_drive(gpio_pin_e gpio_pin,kal_uint32 drive);
extern kal_int32 gpio_set_ownership(kal_uint32 pin_num,kal_uint32 ownership);
extern kal_int32 gpio_get_drive_value(gpio_pin_e gpio_pin);
extern kal_int32 gpio_get_ownership(kal_uint32 pin_num);
#define METAMODE_GPIO 49
#endif

#else
/*************************/
/*use to fix build error for unsupport project*/
/*************************/

#define BU_G_FLD(_i,_ms,_ls)	   0
#define BU_G_BIT(_i,_n)			0



#define DRV_GPIO_WriteReg(addr,data)   0
#define DRV_GPIO_Reg(addr)              0
#define DRV_GPIO_WriteReg32(addr,data)  0
#define DRV_GPIO_Reg32(addr)            0
#define DRV_GPIO_WriteReg8(addr,data)   0
#define DRV_GPIO_Reg8(addr)             0


#define DRV_GPIO_ClearBits(addr,data)   0
#define DRV_GPIO_SetBits(addr,data)     0
#define DRV_GPIO_ClearBits32(addr,data) 0
#define DRV_GPIO_SetBits32(addr,data)   0
#define DRV_GPIO_ClearBits8(addr,data) 0
#define DRV_GPIO_SetBits8(addr,data)   0

#define DRV_GPIO_SetData(addr, bitmask, value)     0
#define DRV_GPIO_SetData32(addr, bitmask, value)   0
#define DRV_GPIO_SetData8(addr, bitmask, value)    0


#define GPIO_PRINT(fmt, var ...)	
#define GPIO_PRINTN(fmt, var ...)	
#define GPIO_ERR(fmt, var ...)		
#define GPIO_WARN(fmt, var ...)	
#define REG32(addr)					(*((volatile unsigned int*)(addr)))
#define REG32_WRITE(addr, value)		do {(*((volatile unsigned int*)(addr))) = (unsigned int)(value);}while (0)

#define GPIO_OK    (0)
#define GPIO_FAIL  (-1)

#define GPIO_PIN_MAX		64

#define GPIO_AS_INPUT					0
#define GPIO_AS_OUTPUT					1
#define GPIO_DISABLE					0
#define GPIO_ENABLE						1
#define GPIO_PULL_DOWN					0
#define GPIO_PULL_UP					1
#define GPIO_OUTPUT_LOW					0
#define GPIO_OUTPUT_HIGH				1
#define GPIO_OWNERSHIP_AP				1
#define GPIO_OWNERSHIP_MD 				0
#define GPIO_DRIVE_NUM_PER_REG 16
#define GPIO_DRIVE_BIT_NUM 2
typedef enum {	
	GPIO_PIN0=0,
	GPIO_PIN1,
	GPIO_PIN2,
	GPIO_PIN3,
	GPIO_PIN4,
	GPIO_PIN5,
	GPIO_PIN6,
	GPIO_PIN7,
	GPIO_PIN8,
	GPIO_PIN9,
	GPIO_PIN10,
	GPIO_PIN11,
	GPIO_PIN12,
	GPIO_PIN13,
	GPIO_PIN14,
	GPIO_PIN15,
	GPIO_PIN16,
	GPIO_PIN17,
	GPIO_PIN18,
	GPIO_PIN19,
	GPIO_PIN20,
	GPIO_PIN21,
	GPIO_PIN22,
	GPIO_PIN23,
	GPIO_PIN24,
	GPIO_PIN25,
	GPIO_PIN26,
	GPIO_PIN27,
	GPIO_PIN28,
	GPIO_PIN29,
	GPIO_PIN30,
	GPIO_PIN31,
	GPIO_PIN32,
	GPIO_PIN33,
	GPIO_PIN34,
	GPIO_PIN35,
	GPIO_PIN36,
	GPIO_PIN37,
	GPIO_PIN38,
	GPIO_PIN39,
	GPIO_PIN40,
	GPIO_PIN41,
	GPIO_PIN42,
	GPIO_PIN43,
	GPIO_PIN44,
	GPIO_PIN45,
	GPIO_PIN46,
	GPIO_PIN47,
	GPIO_PIN48,
	GPIO_PIN49,
	GPIO_PIN50,
	GPIO_PIN51,
	GPIO_PIN52,
	GPIO_PIN53,
	GPIO_PIN54,
	GPIO_PIN55,
	GPIO_PIN56,
	GPIO_PIN57,
	GPIO_PIN58,
	GPIO_PIN59,
	GPIO_PIN60,
	GPIO_PIN61,
	GPIO_PIN62,
	GPIO_PIN63,
	GPIO_PIN64,
	GPIO_PIN65,
	GPIO_PIN66,
	GPIO_PIN67,
	GPIO_PIN68,
	GPIO_PIN69,
	GPIO_PIN70,
	GPIO_PIN71,
	GPIO_PIN72,
	GPIO_PIN73,
	GPIO_PIN74,
	GPIO_PIN75,
	GPIO_PIN76,
	GPIO_PIN77,
	GPIO_PIN78,
	GPIO_PIN79,
	GPIO_PIN80,
	GPIO_PIN81,
	GPIO_PIN82,
	GPIO_PIN83,
	GPIO_PIN84,
	GPIO_PIN85,
	GPIO_PIN86,
	GPIO_PIN87,
	GPIO_PIN88,
	GPIO_PIN89,
	GPIO_PIN90,
	GPIO_PIN91,
	GPIO_PIN92,
	GPIO_PIN93,
	GPIO_PIN94,
	GPIO_PIN95,
	GPIO_PIN96,
	GPIO_PIN97,
	GPIO_PIN98,
	GPIO_PIN99,
	GPIO_PIN100,
	GPIO_PIN101,
	GPIO_PIN102,
	GPIO_PIN103,
	GPIO_PIN104,	
} gpio_pin_e;

#define GPIO_ADDR_OFFSET	0				
#define GPIO_BASE_ADDR		0			
#define GPIOMUX_BASE_ADDR	0			

#define GPIO_DIR1 	0	
#define GPIO_DIR2 	0	
#define GPIO_PULLEN1 	0
#define GPIO_PULLEN2 	0
#define GPIO_PULLSEL1 	0
#define GPIO_PULLSEL2 	0
#define GPIO_DINV1 		0
#define GPIO_DINV2 		0
#define GPIO_DOUT1 		0
#define GPIO_DOUT2 		0
#define GPIO_DIN1 		0
#define GPIO_DIN2 		0

/* Following registers only could be tested in ASIC */
/* ================================================================= */
#define GPIO_DRIVE1 0
#define GPIO_DRIVE2 	0
#define GPIO_DRIVE3 	0
#define GPIO_DRIVE4 	0

/* Set and Clear Registers*/
/* ================================================================= */
#define GPIO_DIR1_SET 	0	
#define GPIO_DIR2_SET 	0	
#define GPIO_PULLEN1_SET 	0
#define GPIO_PULLEN2_SET 	0
#define GPIO_PULLSEL1_SET 	0
#define GPIO_PULLSEL2_SET 	0
#define GPIO_DINV1_SET 		0
#define GPIO_DINV2_SET 		0
#define GPIO_DOUT1_SET 		0
#define GPIO_DOUT2_SET 		0
//#define GPIO_DIN1_SET 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x290 + 0x4))
//#define GPIO_DIN2_SET 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x2A0 + 0x4))

#define GPIO_DIR1_CLR 		0
#define GPIO_DIR2_CLR 		0
#define GPIO_PULLEN1_CLR 	0
#define GPIO_PULLEN2_CLR 	0
#define GPIO_PULLSEL1_CLR 	0
#define GPIO_PULLSEL2_CLR 	0
#define GPIO_DINV1_CLR 		0
#define GPIO_DINV2_CLR 		0
#define GPIO_DOUT1_CLR 		0
#define GPIO_DOUT2_CLR 		0
#define GPIO_DIN1_CLR 		0
#define GPIO_DIN2_CLR 		0



/* Following registers are read back value ,read only */
/* ================================================================= */
#define GPIO_SEL_DOUT1		0
#define GPIO_SEL_DOUT2		0
#define GPIO_SEL_DIR1		0
#define GPIO_SEL_DIR2		0
#define GPIO_SEL_PLUP1		0
#define GPIO_SEL_PLUP2		0
#define GPIO_SEL_PLDN1		0
#define GPIO_SEL_PLDN2		0
#define GPIO_SEL_DRIVE1		0
#define GPIO_SEL_DRIVE2		0
#define GPIO_SEL_DRIVE3		0
#define GPIO_SEL_DRIVE4		0


/* Following registers are GPIO MUX PART */
/* ================================================================= */
#define GPIOMUX_GPIO_OWN1	0	
#define GPIOMUX_GPIO_OWN2	0	

/**
 * @brief	GPIO drive value
 */
typedef enum {	/* GPIO DRIVE items */
	GPIO_DRIVE_4MA,
	GPIO_DRIVE_8MA,
	GPIO_DRIVE_12MA,
	GPIO_DRIVE_16MA,
} gpio_drive_e;
extern void gpio_init(void);
extern void GPIO_InitIO(char direction, char port);
extern char GPIO_ReadIO(char port);
extern void GPIO_WriteIO(char data, char port);
extern char GPIO_ReturnMode(char port);
extern char GPO_ReturnMode(char port);
extern char GPIO_ReturnDir(char port);
extern char GPIO_ReturnDout(char port);
extern char GPO_ReturnDout(char port);
extern void GPO_WriteIO(char data,char port);
extern void GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada);
extern void GPO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada);
extern void initGPIO(void);
extern void GPIO_PullenSetup(kal_uint16 pin, kal_bool enable);
extern void GPIO_DinvSetup(kal_uint16 pin, kal_bool enable);
extern void GPIO_SetDebugMode(kal_bool enable); 
extern void GPIO_PullSelSetup(kal_uint16 pin, kal_bool pull_up);
#ifdef __CUST_NEW__
extern void GPIO_InitIO_FAST(char direction, char port);
extern char GPIO_ReadIO_FAST(char port);
extern void GPIO_WriteIO_FAST(char data, char port);
#endif/* __CUST_NEW__ */
extern void GPIO_WriteIO_FAST2(char data, kal_uint16 no, kal_uint16 remainder_shift);
extern kal_int32 gpio_set_drive(gpio_pin_e gpio_pin,kal_uint32 drive);
extern kal_int32 gpio_set_ownership(kal_uint32 pin_num,kal_uint32 ownership);
extern kal_int32 gpio_get_drive_value(gpio_pin_e gpio_pin);
extern kal_int32 gpio_get_ownership(kal_uint32 pin_num);
#define METAMODE_GPIO 49
#endif
#endif