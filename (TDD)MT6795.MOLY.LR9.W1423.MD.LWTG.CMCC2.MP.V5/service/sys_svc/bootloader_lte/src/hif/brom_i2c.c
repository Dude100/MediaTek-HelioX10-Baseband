#include <brom_i2c.h>
#include "reg_base.h"

#ifdef GPIO_FPGA_20120814_LATER
/////////////////////////////////////////////////////////////////
/*define the GPIO base address here before the GPIO driver ready*/
#define GPIO_BASE_ADDR	BASE_MADDR_MDGPIOMUX

#define GPIO_DIR1 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x100))
#define GPIO_DIR2 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x110))
#define GPIO_PULLEN1 	((volatile unsigned int*)(GPIO_BASE_ADDR + 0x180))
#define GPIO_PULLEN2 	((volatile unsigned int*)(GPIO_BASE_ADDR + 0x190))
#define GPIO_PULLSEL1 	((volatile unsigned int*)(GPIO_BASE_ADDR + 0x200))
#define GPIO_PULLSEL2 	((volatile unsigned int*)(GPIO_BASE_ADDR + 0x210))
#define GPIO_DINV1 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x280))
#define GPIO_DINV2 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x290))
#define GPIO_DOUT1 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x300))
#define GPIO_DOUT2 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x310))
#define GPIO_DIN1 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x380))
#define GPIO_DIN2 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x390))

/* Following registers only could be tested in ASIC */
/* ================================================================= */
#define GPIO_DRIVE1 	((volatile unsigned int*)(GPIO_BASE_ADDR + 0x400))
#define GPIO_DRIVE2 	((volatile unsigned int*)(GPIO_BASE_ADDR + 0x410))
#define GPIO_DRIVE3 	((volatile unsigned int*)(GPIO_BASE_ADDR + 0x420))
#define GPIO_DRIVE4 	((volatile unsigned int*)(GPIO_BASE_ADDR + 0x430))

/* Set and Clear Registers*/
/* ================================================================= */
#define GPIO_DIR1_SET 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x100 + 0x4))
#define GPIO_DIR2_SET 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x110 + 0x4))
#define GPIO_PULLEN1_SET 	((volatile unsigned int*)(GPIO_BASE_ADDR + 0x180 + 0x4))
#define GPIO_PULLEN2_SET 	((volatile unsigned int*)(GPIO_BASE_ADDR + 0x190 + 0x4))
#define GPIO_PULLSEL1_SET 	((volatile unsigned int*)(GPIO_BASE_ADDR + 0x200 + 0x4))
#define GPIO_PULLSEL2_SET 	((volatile unsigned int*)(GPIO_BASE_ADDR + 0x210 + 0x4))
#define GPIO_DINV1_SET 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x280 + 0x4))
#define GPIO_DINV2_SET 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x290 + 0x4))
#define GPIO_DOUT1_SET 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x300 + 0x4))
#define GPIO_DOUT2_SET 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x310 + 0x4))
#define GPIO_DIN1_SET 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x380 + 0x4))
#define GPIO_DIN2_SET 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x390 + 0x4))

#define GPIO_DIR1_CLR 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x100 + 0x8))
#define GPIO_DIR2_CLR 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x110 + 0x8))
#define GPIO_PULLEN1_CLR 	((volatile unsigned int*)(GPIO_BASE_ADDR + 0x180 + 0x8))
#define GPIO_PULLEN2_CLR 	((volatile unsigned int*)(GPIO_BASE_ADDR + 0x190 + 0x8))
#define GPIO_PULLSEL1_CLR 	((volatile unsigned int*)(GPIO_BASE_ADDR + 0x200 + 0x8))
#define GPIO_PULLSEL2_CLR 	((volatile unsigned int*)(GPIO_BASE_ADDR + 0x210 + 0x8))
#define GPIO_DINV1_CLR 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x280 + 0x8))
#define GPIO_DINV2_CLR 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x290 + 0x8))
#define GPIO_DOUT1_CLR 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x300 + 0x8))
#define GPIO_DOUT2_CLR 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x310 + 0x8))
#define GPIO_DIN1_CLR 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x380 + 0x8))
#define GPIO_DIN2_CLR 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x390 + 0x8))


#else /*GPIO_FPGA_20120731_LATER*/
/////////////////////////////////////////////////////////////////
/*define the GPIO base address here before the GPIO driver ready*/
#define GPIO_BASE_ADDR	BASE_MADDR_MDGPIO

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
#define GPIO_DIN1_SET 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x290 + 0x4))
#define GPIO_DIN2_SET 		((volatile unsigned int*)(GPIO_BASE_ADDR + 0x2A0 + 0x4))

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




#define GPIO_DRIVE1_SET 	((volatile unsigned int*)(GPIO_BASE_ADDR + 0x310 + 0x4))
#define GPIO_DRIVE2_SET 	((volatile unsigned int*)(GPIO_BASE_ADDR + 0x320 + 0x4))
#define GPIO_DRIVE3_SET 	((volatile unsigned int*)(GPIO_BASE_ADDR + 0x330 + 0x4))
#define GPIO_DRIVE4_SET 	((volatile unsigned int*)(GPIO_BASE_ADDR + 0x340 + 0x4))

#define GPIO_DRIVE1_CLR 	((volatile unsigned int*)(GPIO_BASE_ADDR + 0x310 + 0x8))
#define GPIO_DRIVE2_CLR 	((volatile unsigned int*)(GPIO_BASE_ADDR + 0x320 + 0x8))
#define GPIO_DRIVE3_CLR 	((volatile unsigned int*)(GPIO_BASE_ADDR + 0x330 + 0x8))
#define GPIO_DRIVE4_CLR 	((volatile unsigned int*)(GPIO_BASE_ADDR + 0x340 + 0x8))
#endif /*GPIO_FPGA_20120731_LATER*/

/////////////////////////////////////////////////////////////////

#define     GPIO_MODE_SET(_no)  (GPIO_MODE1_SET+(0x10*(_no)))
#define     GPIO_DIR_SET(_no)   (GPIO_DIR1_SET+(0x10*(_no)))  
#define     GPIO_DOUT_SET(_no)  (GPIO_DOUT1_SET+(0x10*(_no)))  
#define     GPIO_PULLEN_SET(_no)  (GPIO_PULLEN1_SET+(0x10*(_no)))  
#define     GPIO_PULLSEL_SET(_no)  (GPIO_PULLSEL1_SET+(0x10*(_no)))  
//#define     GPIO_MODE_CLR(_no)  (GPIO_MODE1_CLR+(0x10*(_no)))
#define     GPIO_DIR_CLR(_no)   (GPIO_DIR1_CLR+(0x10*(_no)))
#define     GPIO_DOUT_CLR(_no)  (GPIO_DOUT1_CLR+(0x10*(_no)))
#define     GPIO_PULLEN_CLR(_no) (GPIO_PULLEN1_CLR+(0x10*(_no)))  
#define     GPIO_PULLSEL_SCLR(_no)  (GPIO_PULLSEL1_CLR+(0x10*(_no))) 
   
//#define     GPIO_MODE(_no)      (GPIO_MODE1+(0x10*(_no))) 
#define     GPIO_DOUT(_no)      (GPIO_DOUT1+(0x10*(_no)))
#define     GPIO_DIR(_no)       (GPIO_DIR1+(0x10*(_no)))
#define     GPIO_DIN(_no)       (GPIO_DIN1+(0x10*(_no)))

/////////////////////////////////////////////////////////////////

#define     OUTPUT   1
#define     INPUT    0 

#define SDA    5        /// GPIO #5: I2C data pin on U3 EVB
#define SCL    4        /// GPIO #4: I2C clock pin on U3 EVB

/////////////////////////////////////////////////////////////////

unsigned int  i2c_dummy_cnt;

#define I2C_DELAY 1
#define I2C_DUMMY_DELAY(_delay) for (i2c_dummy_cnt = ((_delay)) ; i2c_dummy_cnt!=0; i2c_dummy_cnt--)

void GPIO_ModeSetup(unsigned int pin, int mode)
{    
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}

void GPIO_InitIO(unsigned int dir, unsigned int pin)
{  
    unsigned int no,remainder;
    no = pin >>4;
    remainder = pin & 0xf;

    if (dir == OUTPUT)
    {   
        DRV_WriteReg16(GPIO_PULLEN_SET(no),(1 << remainder));
        DRV_WriteReg16(GPIO_DIR_SET(no),(1 << remainder));
    }
    else
    {   
        DRV_WriteReg16(GPIO_PULLEN_CLR(no),(1 << remainder));
        DRV_WriteReg16(GPIO_DIR_CLR(no),(1 << remainder));
    }
    I2C_DUMMY_DELAY(100);
}

void GPIO_WriteIO(unsigned int data, unsigned int pin)
{
    unsigned int no;
    unsigned int remainder;
    no = pin >>4;
    remainder = pin & 0xf ;
    if (data == 1)
        DRV_WriteReg16(GPIO_DOUT_SET(no),(1 << remainder));
    else
        DRV_WriteReg16(GPIO_DOUT_CLR(no),(1 << remainder));
}

unsigned int GPIO_ReadIO( unsigned int pin)
{
    unsigned int no;
    unsigned int remainder;
    unsigned short data;
    no = pin >>4;
    remainder = pin & 0xf ;

    data=DRV_Reg16(GPIO_DIN(no));   
    data=data &(1 << remainder);
    data=(data >> remainder);
    return (unsigned int)data;
}

/////////////////////////////////////////////////////////////////

void SerialCommInit(void)
{
    GPIO_ModeSetup(SCL,0);
    GPIO_ModeSetup(SDA,0);
    GPIO_InitIO(OUTPUT,SCL);
}

void SerialCommRelease(void)
{
    GPIO_WriteIO(1,SCL);
    GPIO_WriteIO(1,SDA);
}

/* Start sequence of I2C

   SDA ¢w¢w¢{
           ¢|¢w¢w
   SCL ¢w¢w¢w¢{
             ¢|¢w¢w
*/
void SerialCommStart(void) /* Prepare the SDA and SCL for sending/receiving */
{
    GPIO_InitIO(OUTPUT,SDA);
    GPIO_WriteIO(1,SDA);
    I2C_DUMMY_DELAY(I2C_DELAY);
    GPIO_WriteIO(1,SCL);
    I2C_DUMMY_DELAY(I2C_DELAY);
    GPIO_WriteIO(0,SDA);
    I2C_DUMMY_DELAY(I2C_DELAY);
    GPIO_WriteIO(0,SCL);
    I2C_DUMMY_DELAY(I2C_DELAY);
}

/* Stop sequence of I2C

   SDA       ¢z¢w¢w
       ¢w¢w¢w¢}
   SCL     ¢z¢w¢w¢w
       ¢w¢w¢}
*/
void SerialCommStop(void)
{
    GPIO_InitIO(OUTPUT,SDA);
    GPIO_WriteIO(0,SCL);
    I2C_DUMMY_DELAY(I2C_DELAY);
    GPIO_WriteIO(0,SDA);
    I2C_DUMMY_DELAY(I2C_DELAY);
    GPIO_WriteIO(1,SCL);
    I2C_DUMMY_DELAY(I2C_DELAY);
    GPIO_WriteIO(1,SDA);
    I2C_DUMMY_DELAY(I2C_DELAY);
}

unsigned int SerialCommTxByte(unsigned char data) /* return 0 --> ack */
{
    int i, ack;
    
    GPIO_InitIO(OUTPUT,SDA);

    for(i=8; --i>0;){
        GPIO_WriteIO((data>>i)&0x01, SDA);
        I2C_DUMMY_DELAY(I2C_DELAY);
        GPIO_WriteIO( 1, SCL); /* high */
        I2C_DUMMY_DELAY(I2C_DELAY);
        GPIO_WriteIO( 0, SCL); /* low */
        I2C_DUMMY_DELAY(I2C_DELAY);
    }
    GPIO_WriteIO((data>>i)&0x01, SDA);
    I2C_DUMMY_DELAY(I2C_DELAY);
    GPIO_WriteIO( 1, SCL); /* high */
    I2C_DUMMY_DELAY(I2C_DELAY);
    GPIO_WriteIO( 0, SCL); /* low */
    I2C_DUMMY_DELAY(I2C_DELAY);
    
    GPIO_WriteIO(0, SDA);
    I2C_DUMMY_DELAY(I2C_DELAY);
    GPIO_InitIO(INPUT,SDA);
    I2C_DUMMY_DELAY(I2C_DELAY);
    GPIO_WriteIO(1, SCL);
    I2C_DUMMY_DELAY(I2C_DELAY);
    ack = GPIO_ReadIO(SDA); /// ack 1: error , 0:ok
    GPIO_WriteIO(0, SCL);
    I2C_DUMMY_DELAY(I2C_DELAY);
    
    if(ack==1)
        return 0;
    else
        return 1;  
}

void SerialCommRxByte(unsigned  char *data, unsigned char ack)
{
   int i;
   unsigned int dataCache;
   dataCache = 0;
   GPIO_InitIO(INPUT,SDA);
   for(i=8; --i>=0;){
      dataCache <<= 1;
      I2C_DUMMY_DELAY(I2C_DELAY);
      GPIO_WriteIO(1, SCL);
      I2C_DUMMY_DELAY(I2C_DELAY);
      dataCache |= GPIO_ReadIO(SDA);
      GPIO_WriteIO(0, SCL);
      I2C_DUMMY_DELAY(I2C_DELAY);
   }
   GPIO_InitIO(OUTPUT,SDA);
   GPIO_WriteIO(ack, SDA);
   I2C_DUMMY_DELAY(I2C_DELAY);
   GPIO_WriteIO(1, SCL);
   I2C_DUMMY_DELAY(I2C_DELAY);
   GPIO_WriteIO(0, SCL);
   I2C_DUMMY_DELAY(I2C_DELAY);
   *data = (unsigned char)dataCache;
}

int I2cWriteReg(unsigned char dev_id, unsigned char Addr, unsigned char Data)
{
    int acknowledge=0;

    SerialCommStart();
    acknowledge=SerialCommTxByte((dev_id<<1) & 0xff);
    if(acknowledge)
        acknowledge=SerialCommTxByte(Addr);
    else
        return 0;
    acknowledge=SerialCommTxByte(Data);
    if(acknowledge)
    {
        SerialCommStop();
        return 1;
    }
    else
    {    
        return 0;
    }        
}

int I2cReadReg(unsigned char dev_id, unsigned char Addr, unsigned char *Data)
{
    int acknowledge=0;    
    SerialCommStart();    
    acknowledge=SerialCommTxByte((dev_id<<1) & 0xff);
    if(acknowledge)
        acknowledge=SerialCommTxByte(Addr);
    else
        return 0;    
    SerialCommStart();
    acknowledge=SerialCommTxByte(((dev_id<<1) & 0xff) | 0x01);
    if(acknowledge)
        SerialCommRxByte(Data, 1);  // ack 0: ok , 1 error
    else
        return 0;    
    SerialCommStop();
    return acknowledge;
} 
