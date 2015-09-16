#ifndef _I2C_PMIC_H_
#define _I2C_PMIC_H_
 #include "reg_base.h"
 #include "drv_comm.h"

 #if defined(MT6290)
 
#define REG_I2C_BASE                      (BASE_ADDR_I2C)
#define REG_I2C_DATA_PORT                 (REG_I2C_BASE+0x00)
#define REG_I2C_SLAVE_ADDR                (REG_I2C_BASE+0x04)
#define REG_I2C_INT_MASK                  (REG_I2C_BASE+0x08)
#define REG_I2C_INT_STA                   (REG_I2C_BASE+0x0C)
#define REG_I2C_CONTROL                   (REG_I2C_BASE+0x10)
#define REG_I2C_TRANSFER_LEN              (REG_I2C_BASE+0x14)
#define REG_I2C_TRANSAC_LEN               (REG_I2C_BASE+0x18)
#define REG_I2C_DELAY_LEN                 (REG_I2C_BASE+0x1C)
#define REG_I2C_TIMING                    (REG_I2C_BASE+0x20)
#define REG_I2C_START                     (REG_I2C_BASE+0x24)
#define REG_I2C_FIFO_STAT                 (REG_I2C_BASE+0x30)
#define REG_I2C_FIFO_THRESH               (REG_I2C_BASE+0x34)
#define REG_I2C_FIFO_ADDR_CLR             (REG_I2C_BASE+0x38)
#define REG_I2C_IO_CONFIG                 (REG_I2C_BASE+0x40)
#define REG_I2C_MULTI_MASTER              (REG_I2C_BASE+0x44)
#define REG_I2C_HS_MODE                   (REG_I2C_BASE+0x48)
#define REG_I2C_SOFTRESET                 (REG_I2C_BASE+0x50)
#define REG_I2C_SPARE                     (REG_I2C_BASE+0x60)
#define REG_I2C_DEBUG_STA                 (REG_I2C_BASE+0x64)
#define REG_I2C_DEBUG_CTRL                (REG_I2C_BASE+0x68)
#define REG_I2C_TRANSFER_LEN_AUX          (REG_I2C_BASE+0x6C)
#define REG_I2C_ADVANCE_READ_DATA_TIMING  (REG_I2C_BASE+0x70)
#define REG_I2C_TIMEOUT_TIMING            (REG_I2C_BASE+0x74)
#define REG_I2C_HW_VERSION_CODE           (REG_I2C_BASE+0x78)



#define DRV_I2C_ClearBits16(addr, data)             DRV_WriteReg(addr,((~data)&DRV_Reg(addr)))
#define DRV_I2C_SetBits16(addr, data)               DRV_WriteReg(addr,((data)|DRV_Reg(addr)))
#define DRV_I2C_WriteReg16(addr, data)              DRV_WriteReg(addr, data)
#define DRV_I2C_ReadReg16(addr)                     DRV_Reg(addr)
#define DRV_I2C_SetData16(addr, bitmask, value)     DRV_WriteReg(addr, ((~bitmask)&DRV_Reg(addr))|value)
/*
#if (0 == CHIP_VER)//FPGA
#if defined(DRV_I2C_CLOCK_RATE_15_360_MHZ)
#define I2C_CLOCK_RATE	15360 //15.36MHz
#elif defined(DRV_I2C_CLOCK_RATE_3_000_MHZ)
#define I2C_CLOCK_RATE	3000 //3.0MHz
#elif defined(DRV_I2C_CLOCK_RATE_10_130_MHZ)
#define I2C_CLOCK_RATE	5005//20.02MHz/4  //10130  //13MHz
#else // #if defined(DRV_I2C_CLOCK_RATE_15_360_MHZ)
#define I2C_CLOCK_RATE	13000 //13MHz
#endif // #if defined(DRV_I2C_CLOCK_RATE_15_360_MHZ)
#elif (0 != CHIP_VER) //E1 or E2
#define I2C_CLOCK_RATE  15000 // AP_BUS1x_clk/4     i2c clk is apb_bus1x_clk/4
#endif
*/

/*
typedef enum
{
	I2C_TRANSACTION_COMPLETE,
	I2C_TRANSACTION_FAIL,
	I2C_TRANSACTION_IS_BUSY,
	I2C_TRANSACTION_ACKERR,
	I2C_TRANSACTION_HS_NACKERR,
	I2C_TRANSACTION_SUCCESS,
	I2C_TRANSACTION_TIMEOUT
}I2C_TRANSACTION_RESULT;


typedef enum
{
    I2C_IDLE_STATE = 0,
	I2C_READY_STATE,
	I2C_BUSY_STATE
}I2C_STATE;
*/
/* Transaction mode for new SCCB APIs */
typedef enum
{
	I2C_TRANSACTION_FAST_MODE,
	I2C_TRANSACTION_HIGH_SPEED_MODE
}I2C_TRANSACTION_MODE;

/* Transaction type for batch transaction */
/*
typedef enum
{
	I2C_TRANSACTION_WRITE,
	I2C_TRANSACTION_READ,
	I2C_TRANSACTION_CONT_WRITE,
	I2C_TRANSACTION_CONT_READ,
	I2C_TRANSACTION_WRITE_AND_READ,
	I2C_TRANSACTION_WRITE_NB,
}I2C_TRANSACTION_TYPE;

typedef struct
{
   kal_uint8 *data;
   kal_uint32 data_len;
}i2c_single_write_struct, i2c_single_read_struct;

*/
/* For I2C_CMD_CONT_WRITE, I2C_CMD_CONT_READ command. */
/*
typedef struct
{
   kal_uint8 *data;
   kal_uint32 data_len;
   kal_uint32 transfer_num;
}i2c_cont_write_struct, i2c_cont_read_struct;
*/
/* For I2C_CMD_WRITE_AND_READ command. */
/*
typedef struct
{
   kal_uint8 *indata;
   kal_uint32 indata_len;
   kal_uint8 *outdata;
   kal_uint32 outdata_len;
}i2c_write_and_read_struct;
*/
/* */

/*
typedef union
{
	i2c_single_write_struct single_write;
  i2c_single_read_struct single_read;
  i2c_cont_write_struct cont_write;
  i2c_cont_write_struct cont_read;
  i2c_write_and_read_struct write_and_read;
}i2c_transaction_data_struct;
*/
/* For I2C_CMD_SINGLE_BATCH command. */
/*///typedef struct
{
   I2C_TRANSACTION_TYPE transaction_type;
   i2c_transaction_data_struct transaction_data;
}i2c_batch_data_struct;
*////


/*
typedef enum
{
	DCL_I2C_0_OWNER,
	DCL_I2C_1_OWNER
}DCL_I2C_OWNER;
#define DCL_I2C_NUM_OF_OWNER 2

typedef enum
{
	DCL_I2C_CONFIG_NONE,
	DCL_I2C_GET_TRANSACTION_MODE,
	DCL_I2C_SET_TRANSACTION_MODE,
	DCL_I2C_SET_TRANSACTION_FS_SPEED,
	DCL_I2C_SET_TRANSACTION_HS_SPEED,
	DCL_I2C_SINGLE_WRITE,
	DCL_I2C_SINGLE_READ,
	DCL_I2C_CONT_WRITE,
	DCL_I2C_CONT_READ,
	DCL_I2C_WRITE_AND_READ,
////	DCL_I2C_BATCH_TRANSACTION,
////	DCL_I2C_GET_BATCH_TRANSACTION_RESULT,
////	DCL_I2C_GET_DMA_PROPERTY,
////	DCL_I2C_ENABLE_DMA,
	DCL_I2C_SET_SLAVE_ADDRESS,
	DCL_I2C_SET_DELAY_LEN,
}DCL_I2C_CONFIG_TYPE;
*/
/*
typedef struct
{
	//kal_uint8 sccb_mode; // Transaction mode for existing SCCB APIs

	kal_bool get_handle_wait; //When get handle wait until the I2C is avaliable

	kal_uint8 slave_address;	//the address of the slave device

	kal_uint8 delay_len;	//number of half pulse between transfers in a trasaction

	I2C_TRANSACTION_MODE transaction_mode;	//I2C_TRANSACTION_FAST_MODE or I2C_TRANSACTION_HIGH_SPEED_MODE

	kal_uint16 Fast_Mode_Speed;	//The speed of I2C fast mode(Kb)

	kal_uint16 HS_Mode_Speed;	//The speed of I2C high speed mode(Kb)
	#if (defined(DRV_I2C_DMA_ENABLED))
	kal_bool	is_DMA_enabled;	//Transaction via DMA instead of 8-byte FIFO
	#endif
}i2c_config_struct;
*/
/*
typedef struct
{
	i2c_config_struct  i2c_config;

	kal_uint8 fs_sample_cnt_div;     //these two parameters are used to specify I2C clock rate
	kal_uint8 fs_step_cnt_div;       //half pulse width=step_cnt_div*sample_cnt_div*(1/13Mhz)

	kal_uint8 hs_sample_cnt_div;     //these two parameters are used to specify I2C clock rate
	kal_uint8 hs_step_cnt_div;       //half pulse width=step_cnt_div*sample_cnt_div*(1/13Mhz)

	I2C_TRANSACTION_RESULT transaction_result; //The result of the end of transaction  (I2C_TRANSACTION_COMPLETE|I2C_TRANSACTION_FAIL) 
}i2c_handle_struct;
*/

/*
typedef struct
{
	volatile I2C_STATE  state;
	DCL_I2C_OWNER	    owner;

	kal_uint32	number_of_read;
	kal_uint8*	read_buffer;
	#if (defined(DRV_I2C_DMA_ENABLED))
	kal_bool	is_DMA_enabled;
	#endif
}i2c_status_struct;


*/



/* Register masks */
#define I2C_1_BIT_MASK                0x01
#define I2C_3_BIT_MASK                0x07
#define I2C_4_BIT_MASK                0x0f
#define I2C_5_BIT_MASK				  0x1f
#define I2C_6_BIT_MASK                0x3f
#define I2C_8_BIT_MASK                0xff
#define I2C_16_BIT_MASK               0xffff

#define I2C_RX_FIFO_THRESH_MASK       0x0007
#define I2C_RX_FIFO_THRESH_SHIFT      0
#define I2C_TX_FIFO_THRESH_MASK       0x0700
#define I2C_TX_FIFO_THRESH_SHIFT      8

#define I2C_AUX_LEN_MASK              0x1f00
#define I2C_AUX_LEN_SHIFT             8

#define I2C_SAMPLE_CNT_DIV_MASK       0x0700
#define I2C_SAMPLE_CNT_DIV_SHIFT      8
#define I2C_DATA_READ_TIME_MASK       0x7000
#define I2C_DATA_READ_TIME_SHIFT      12

#define I2C_MASTER_READ               0x01
#define I2C_MASTER_WRITE              0x00

//#define I2C_CTL_MODE_BIT            0x01
#define I2C_CTL_RS_STOP_BIT           0x02
#define I2C_CTL_DMA_EN_BIT            0x04
#define I2C_CTL_CLK_EXT_EN_BIT        0x08
#define I2C_CTL_DIR_CHANGE_BIT        0x10
#define I2C_CTL_ACK_ERR_DET_BIT       0x20
#define I2C_CTL_TRANSFER_LEN_CHG_BIT  0x40
#define I2C_CTL_RST_BUS_BUSY_BIT  0x80
#define I2C_CTL_TIMEOUT_BIT  0x100


#define I2C_DATA_READ_ADJ_BIT         0x8000

#define I2C_SCL_MODE_BIT              0x01
#define I2C_SDA_MODE_BIT              0x02
#define I2C_BUS_DETECT_EN_BIT         0x04

#define I2C_ARBITRATION_BIT           0x01
#define I2C_CLOCK_SYNC_BIT            0x02
#define I2C_BUS_BUSY_DET_BIT          0x04

#define I2C_HS_EN_BIT                 0x01
#define I2C_HS_NACK_ERR_DET_EN_BIT    0x02
#define I2C_HS_MASTER_CODE_MASK       0x0070
#define I2C_HS_MASTER_CODE_SHIFT      4
#define I2C_HS_STEP_CNT_DIV_MASK      0x0700
#define I2C_HS_STEP_CNT_DIV_SHIFT     8
#define I2C_HS_SAMPLE_CNT_DIV_MASK    0x7000
#define I2C_HS_SAMPLE_CNT_DIV_SHIFT   12

/* I2C Status */
#define I2C_FIFO_FULL_STATUS          0x01
#define I2C_FIFO_EMPTY_STATUS         0x02
#define DRV_I2C_FIFO_DEPTH				8

/* Register Settings */
#define SET_I2C_SLAVE_ADDRESS(n,rw)       do{DRV_I2C_SetData16(REG_I2C_SLAVE_ADDR, I2C_8_BIT_MASK, (((n>>1)<<1) + rw));} while(0);

#define DISABLE_I2C_INT                   do{DRV_I2C_WriteReg16(REG_I2C_INT_MASK, 0);} while(0);
#define ENABLE_I2C_INT                    do{DRV_I2C_WriteReg16(REG_I2C_INT_MASK,I2C_1_BIT_MASK);} while(0);

#define CLEAR_I2C_STA                     do{DRV_I2C_WriteReg16(REG_I2C_INT_STA, I2C_5_BIT_MASK);} while(0);

//#define SET_I2C_FAST_SPEED_MODE	REG_I2C_CONTROL &= ~I2C_CTL_MODE_BIT;
//#define SET_I2C_HIGH_SPEED_MODE	REG_I2C_CONTROL |= I2C_CTL_MODE_BIT;

#define SET_I2C_ST_BETWEEN_TRANSFER       do{DRV_I2C_ClearBits16(REG_I2C_CONTROL, I2C_CTL_RS_STOP_BIT);} while(0);
#define SET_I2C_RS_BETWEEN_TRANSFER       do{DRV_I2C_SetBits16(REG_I2C_CONTROL, I2C_CTL_RS_STOP_BIT);} while(0);
#define ENABLE_I2C_DMA_TRANSFER           do{DRV_I2C_SetBits16(REG_I2C_CONTROL, I2C_CTL_DMA_EN_BIT);} while(0);
#define ENABLE_I2C_CLOCK_EXTENSION        do{DRV_I2C_SetBits16(REG_I2C_CONTROL, I2C_CTL_CLK_EXT_EN_BIT);} while(0);
#define ENABLE_I2C_DIR_CHANGE             do{DRV_I2C_SetBits16(REG_I2C_CONTROL, I2C_CTL_DIR_CHANGE_BIT);} while(0);
#define ENABLE_I2C_ACK_ERR_DET            do{DRV_I2C_SetBits16(REG_I2C_CONTROL, I2C_CTL_ACK_ERR_DET_BIT);} while(0);
#define ENABLE_I2C_TRANSFER_LEN_CHG       do{DRV_I2C_SetBits16(REG_I2C_CONTROL, I2C_CTL_TRANSFER_LEN_CHG_BIT);} while(0);
#define ENABLE_I2C_BUS_BUSY_RESET         do{DRV_I2C_SetBits16(REG_I2C_CONTROL, I2C_CTL_RST_BUS_BUSY_BIT);} while(0);
#define ENABLE_I2C_TIMEOUT                do{DRV_I2C_SetBits16(REG_I2C_CONTROL, I2C_CTL_TIMEOUT_BIT);} while(0); 

#define DISABLE_I2C_DMA_TRANSFER          do{DRV_I2C_ClearBits16(REG_I2C_CONTROL, I2C_CTL_DMA_EN_BIT);} while(0);
#define DISABLE_I2C_CLOCK_EXTENSION       do{DRV_I2C_ClearBits16(REG_I2C_CONTROL, I2C_CTL_CLK_EXT_EN_BIT);} while(0);
#define DISABLE_I2C_DIR_CHANGE            do{DRV_I2C_ClearBits16(REG_I2C_CONTROL, I2C_CTL_DIR_CHANGE_BIT);} while(0);
#define DISABLE_I2C_ACK_ERR_DET           do{DRV_I2C_ClearBits16(REG_I2C_CONTROL, I2C_CTL_ACK_ERR_DET_BIT);} while(0);
#define DISABLE_I2C_TRANSFER_LEN_CHG      do{DRV_I2C_ClearBits16(REG_I2C_CONTROL, I2C_CTL_TRANSFER_LEN_CHG_BIT);} while(0);
#define DISABLE_I2C_BUS_BUSY_RESET        do{DRV_I2C_ClearBits16(REG_I2C_CONTROL, I2C_CTL_RST_BUS_BUSY_BIT);} while(0);
#define DISABLE_I2C_TIMEOUT               do{DRV_I2C_ClearBits16(REG_I2C_CONTROL, I2C_CTL_TIMEOUT_BIT);} while(0); 

#if 1//#ifdef DRV_I2C_MAX_65535_TRANSFER_LENGTH
#define SET_I2C_TRANSFER_LENGTH(n)        do{DRV_I2C_SetData16(REG_I2C_TRANSFER_LEN, I2C_16_BIT_MASK, (n));} while(0);
#define SET_I2C_AUX_TRANSFER_LENGTH(n)    do{DRV_I2C_SetData16(REG_I2C_TRANSFER_LEN_AUX, I2C_16_BIT_MASK, (n));} while(0);
#else
/* under construction !*/
/* under construction !*/
#endif

#define SET_I2C_TRANSACTION_LENGTH(n)     do{DRV_I2C_SetData16(REG_I2C_TRANSAC_LEN, I2C_8_BIT_MASK, (n));} while(0);
#define SET_I2C_DELAY_LENGTH(n)           do{DRV_I2C_SetData16(REG_I2C_DELAY_LEN, I2C_8_BIT_MASK, (n));} while(0);

#define SET_I2C_STEP_CNT_DIV(n)           do{DRV_I2C_SetData16(REG_I2C_TIMING, I2C_6_BIT_MASK, (n));} while(0);
#define SET_I2C_SAMPLE_CNT_DIV(n)         do{DRV_I2C_SetData16(REG_I2C_TIMING, I2C_SAMPLE_CNT_DIV_MASK, ((n)<<I2C_SAMPLE_CNT_DIV_SHIFT));} while(0);
#define SET_I2C_DATA_READ_TIME(n)         do{DRV_I2C_SetData16(REG_I2C_TIMING, I2C_DATA_READ_TIME_MASK, ((n)<<I2C_DATA_READ_TIME_SHIFT));} while(0);
#define ENABLE_I2C_DATA_READ_ADJ          do{DRV_I2C_SetBits16(REG_I2C_TIMING, I2C_DATA_READ_ADJ_BIT);} while(0);
#define DISABLE_I2C_DATA_READ_ADJ         do{DRV_I2C_ClearBits16(REG_I2C_TIMING, I2C_DATA_READ_ADJ_BIT);} while(0);

#define START_I2C_TRANSACTION             do{DRV_I2C_WriteReg16(REG_I2C_START, 0x01);} while(0);
#define STOP_I2C_TRANSACTION              do{DRV_I2C_WriteReg16(REG_I2C_START, 0x00);} while(0);


// #define I2C_FIFO_FULL                     ((REG_I2C_FIFO_STAT>>1)&0x01)
// #define I2C_FIFO_EMPTY                    (REG_I2C_FIFO_STAT & 0x01)

#define SET_I2C_RX_FIFO_THRESH(n)         do{DRV_I2C_SetData16(REG_I2C_FIFO_THRESH, I2C_RX_FIFO_THRESH_MASK, ((n)<< I2C_RX_FIFO_THRESH_SHIFT));} while(0);
#define SET_I2C_TX_FIFO_THRESH(n)         do{DRV_I2C_SetData16(REG_I2C_FIFO_THRESH, I2C_TX_FIFO_THRESH_MASK, ((n)<< I2C_TX_FIFO_THRESH_SHIFT));} while(0);

#define CLEAR_I2C_FIFO                    do{DRV_I2C_WriteReg16(REG_I2C_FIFO_ADDR_CLR, 0x01);} while(0);

#define SET_I2C_SCL_NORMAL_MODE           do{DRV_I2C_ClearBits16(REG_I2C_IO_CONFIG, I2C_SCL_MODE_BIT);} while(0);
#define SET_I2C_SCL_WIRED_AND_MODE        do{DRV_I2C_SetBits16(REG_I2C_IO_CONFIG, I2C_SCL_MODE_BIT);} while(0);
#define SET_I2C_SDA_NORMAL_MODE           do{DRV_I2C_ClearBits16(REG_I2C_IO_CONFIG, I2C_SDA_MODE_BIT);} while(0);
#define SET_I2C_SDA_WIRED_AND_MODE        do{DRV_I2C_SetBits16(REG_I2C_IO_CONFIG, I2C_SDA_MODE_BIT);} while(0);
#define ENABLE_I2C_BUS_DETECT             do{DRV_I2C_SetBits16(REG_I2C_IO_CONFIG, I2C_BUS_DETECT_EN_BIT);} while(0);
#define DISABLE_I2C_BUS_DETECT            do{DRV_I2C_ClearBits16(REG_I2C_IO_CONFIG, I2C_BUS_DETECT_EN_BIT);} while(0);

#define ENABLE_I2C_CLOCK_SYNC             do{DRV_I2C_SetBits16(REG_I2C_MULTI_MASTER, I2C_ARBITRATION_BIT);} while(0);
#define ENABLE_DATA_ARBITION              do{DRV_I2C_SetBits16(REG_I2C_MULTI_MASTER, I2C_CLOCK_SYNC_BIT);} while(0);
#define ENABLE_I2C_BUS_BUSY_DET           do{DRV_I2C_SetBits16(REG_I2C_MULTI_MASTER, I2C_BUS_BUSY_DET_BIT);} while(0);
#define DISABLE_I2C_CLOCK_SYNC            do{DRV_I2C_ClearBits16(REG_I2C_MULTI_MASTER, I2C_ARBITRATION_BIT);} while(0);
#define DISABLE_DATA_ARBITION             do{DRV_I2C_ClearBits16(REG_I2C_MULTI_MASTER, I2C_CLOCK_SYNC_BIT);} while(0);
#define DISABLE_I2C_BUS_BUSY_DET          do{DRV_I2C_ClearBits16(REG_I2C_MULTI_MASTER, I2C_BUS_BUSY_DET_BIT);} while(0);

//#define SET_I2C_HIGH_SPEED_MODE_800KB     do{DRV_I2C_WriteReg16(REG_I2C_HS_MODE, 0x0703);} while(0);
//#define SET_I2C_HIGH_SPEED_MODE_1000KB    do{DRV_I2C_WriteReg16(REG_I2C_HS_MODE, 0x0503);} while(0);

#define SET_I2C_FAST_MODE                 do{DRV_I2C_ClearBits16(REG_I2C_HS_MODE, I2C_HS_EN_BIT);} while(0);
#define SET_I2C_HS_MODE                   do{DRV_I2C_SetBits16(REG_I2C_HS_MODE, I2C_HS_EN_BIT);} while(0);
#define ENABLE_I2C_NAKERR_DET             do{DRV_I2C_SetBits16(REG_I2C_HS_MODE, I2C_HS_NACK_ERR_DET_EN_BIT);} while(0);
#define DISABLE_I2C_NAKERR_DET            do{DRV_I2C_ClearBits16(REG_I2C_HS_MODE, I2C_HS_NACK_ERR_DET_EN_BIT);} while(0);
#define SET_I2C_HS_MASTER_CODE(n)         do{DRV_I2C_SetData16(REG_I2C_HS_MODE, I2C_HS_MASTER_CODE_MASK, ((n)<<I2C_HS_MASTER_CODE_SHIFT));} while(0);

#define SET_I2C_HS_STEP_CNT_DIV(n)        do{DRV_I2C_SetData16(REG_I2C_HS_MODE, I2C_HS_STEP_CNT_DIV_MASK, ((n)<<I2C_HS_STEP_CNT_DIV_SHIFT));} while(0);
#define SET_I2C_HS_SAMPLE_CNT_DIV(n)      do{DRV_I2C_SetData16(REG_I2C_HS_MODE, I2C_HS_SAMPLE_CNT_DIV_MASK, ((n)<<I2C_HS_SAMPLE_CNT_DIV_SHIFT));} while(0);

#define RESET_I2C                         do{DRV_I2C_WriteReg16(REG_I2C_SOFTRESET, 0x01);} while(0);




typedef enum 
{
	I2C_PASS = 0,
	I2C_ACKERR =1,
	I2C_NACKERR = 2,
	I2C_FAIL,
}I2C_STATUS;

#define I2C_CLOCK_RATE  15000 // AP_BUS1x_clk/4     i2c clk is apb_bus1x_clk/4
#define FS_300K 300
#define HS_500K 500
/*
#define FS_300K_SAMPLE_CNT_DIV 0
#define FS_300K_STEP_CNT_DIV 24
#define HS_500K_SAMPLE_CNT_DIV  1
#define FS_500K_STEP_CNT_DIV 7
*/

typedef struct I2C_CFG_T
{
	I2C_TRANSACTION_MODE mode;
	kal_uint16 speed;
	kal_uint16 step_cnt_div;
	kal_uint16 sample_cnt_div;
}I2C_CFG;


/****** SW definitions******/
#define I2C_READ_BIT            0x01
#define I2C_WRITE_BIT           0x00

#define I2C_TRANSAC_COMPLETE    0x01
#define I2C_TRANSAC_ACK_ERR     0x02
#define I2C_HS_NACK_ERR         0x04
#define I2C_ARBLOST			0x08
#define I2C_TIMEOUT         	0x10


typedef struct EXTBUCK_INFO_T
{
	kal_uint8 slave_addr;
	kal_uint8 pid_reg_addr;
	kal_uint8* pPidArray;     // point to a array which store the PID need to check 
	kal_uint8 pidCount;        // the count of PID in Pid array point by pPidArray
}EXTBUCK_INFO;

//extern kal_bool dcl_i2c_init_done_flag;
//extern i2c_handle_struct i2c_handle[DCL_I2C_NUM_OF_OWNER];
/*

void dcl_i2c_init(void);
kal_bool dcl_i2c_ctl(DCL_I2C_OWNER owner,DCL_I2C_CONFIG_TYPE type,void * data);
void dcl_i2c_hw_cfg (DCL_I2C_OWNER owner, I2C_TRANSACTION_TYPE type, kal_uint8* write_buffer, kal_uint32 write_len, kal_uint8* read_buffer, kal_uint32 read_len, kal_uint32 transfer_num);
void dcl_i2c_set_transaction_speed(DCL_I2C_OWNER owner,I2C_TRANSACTION_MODE mode,kal_uint16* Fast_Mode_Speed,kal_uint16* HS_Mode_Speed);
kal_uint32 dcl_i2c_wait_transaction_complete_and_lock(DCL_I2C_OWNER owner);
void dcl_i2c_wait_transaction_complete(kal_uint32 savedMask);*/

#define I2C_PMIC_DRV_TEST 0 
#define I2C_WAIT_TIMEOUT 300000
#define EN_I2C_PRINTF 0
#if EN_I2C_PRINTF
extern void dbg_print(char *fmt,...);

#define I2C_PRINT(fmt, var ...)	do {dbg_print(fmt"\n\r", ##var);} while (0)
#define I2C_PRINTN(fmt, var ...)	do {dbg_print(fmt, ##var);} while (0)
#define I2C_ERR(fmt, var ...)		do {I2C_PRINT("ERROR [%s:%d]"fmt, __FUNCTION__, __LINE__, ##var);} while (0)
#define I2C_WARN(fmt, var ...)	do {I2C_PRINT("WARNING [%s:%d]"fmt, __FUNCTION__, __LINE__, ##var);} while (0)
#else 
#define I2C_PRINT(fmt, var ...)	
#define I2C_PRINTN(fmt, var ...)	
#define I2C_ERR(fmt, var ...)		
#define I2C_WARN(fmt, var ...)	
#endif

I2C_STATUS i2c_pmic_reg_write(kal_uint8 slave_addr ,kal_uint8 reg , kal_uint8 val);
I2C_STATUS i2c_pmic_reg_read(kal_uint8 slave_addr , kal_uint8 reg , kal_uint8 * pval);
kal_uint8 extbuck_53555_exist(void);
kal_uint8 extbuck_6335_exist(void);
kal_uint8 exbuck_other_exist(EXTBUCK_INFO extbuck_info);

#if I2C_PMIC_DRV_TEST
typedef enum{
    I2C_REPORT_FAIL = -1,
    I2C_REPORT_PASS = 0,
    I2C_REPORT_NA
}I2C_REPORT_STATUS;
I2C_REPORT_STATUS ut_i2c_pmic_unexist_slave_addr_test(kal_uint32 flags, void *param);
 I2C_REPORT_STATUS ut_i2c_pmic_readonly_reg_test (kal_uint32 flags, void *param);
 I2C_REPORT_STATUS ut_i2c_pmic_loopback_test(kal_uint32 flags, void *param);
 I2C_REPORT_STATUS ut_i2c_pmic_wait_comp_count_test(kal_uint32 flags, void *param);
 I2C_REPORT_STATUS ut_i2c_pmic6335_reg_access_test(kal_uint32 flags, void *param);
 I2C_REPORT_STATUS ut_i2c_pmic_all_speed_unsexist_slave_test(kal_uint32 flags, void *param);
 I2C_REPORT_STATUS ut_i2c_pmic_all_speed_loopback_test(kal_uint32 flags, void *param);
 I2C_REPORT_STATUS ut_i2c_pmic_exist_fun_test(kal_uint32 flags, void *param); 
 #endif
 #else
 typedef enum 
 {
	 I2C_PASS = 0,
	 I2C_ACKERR =1,
	 I2C_NACKERR = 2,
	 I2C_FAIL,
 }I2C_STATUS;

 typedef struct EXTBUCK_INFO_T
{
	kal_uint8 slave_addr;
	kal_uint8 pid_reg_addr;
	kal_uint8* pPidArray;     // point to a array which store the PID need to check 
	kal_uint8 pidCount;        // the count of PID in Pid array point by pPidArray
}EXTBUCK_INFO;

 I2C_STATUS i2c_pmic_reg_write(kal_uint8 slave_addr ,kal_uint8 reg , kal_uint8 val);
I2C_STATUS i2c_pmic_reg_read(kal_uint8 slave_addr , kal_uint8 reg , kal_uint8 * pval);
kal_uint8 extbuck_53555_exist(void);
kal_uint8 extbuck_6335_exist(void);
kal_uint8 exbuck_other_exist(EXTBUCK_INFO extbuck_info);

 
 #endif
#endif



