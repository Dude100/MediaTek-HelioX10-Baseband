/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 *   mml1_custom_mipi.h
 *
 * Project:
 * --------
 *   MT6290 EVB
 *
 * Description:
 * ------------
 *   MT6290 EVB Multi-Mode Multi-RAT L1 constance definition
 *
 * Author:
 * -------
 *
 *
 *==============================================================================
 *******************************************************************************/
#ifndef  _MML1_CUSTOM_MIPI_H_
#define  _MML1_CUSTOM_MIPI_H_

#define USID_NULL      0x0000
#define USID_REG_W     0x0001
#define USID_REG_W_EXT 0x0002

#define MML1_REG_0_W              0x0001
#define MML1_REG_W                0x0002
#define MML1_REG_W_EXT_1ST        0x0003
#define MML1_REG_W_EXT_BYTE       0x0004
#define MML1_REG_W_EXT_END        0x0005
#define MML1_IMM_BSI_WAIT         0x0006

//port slectiong
#define MML1_MIPI_PORT0          0x0000
#define MML1_MIPI_PORT1          0x0001

typedef kal_uint8  USID_T;//4 bits valid
typedef kal_uint8  PRODUCT_ID_T;//8 bits valid
typedef kal_uint16 MANUFACTORY_ID_T;//10 bits valid
typedef kal_uint8  MIPI_PORT_T;

#define MIPI_USID_INIT0           0x0000
#define MIPI_USID_ASM0            0x000B
#define MIPI_USID_ASM1            0x000A
#define MIPI_USID_PA0             0x000F
#define MIPI_USID_PA1             0x000E
#define MIPI_USID_ANT0            0x0006
#define MIPI_USID_ET              0x000C

typedef struct
{
   kal_uint16       usid_procedure;
   MIPI_PORT_T      mipi_port_sel;
   USID_T           current_usid;
   PRODUCT_ID_T     product_id;
   MANUFACTORY_ID_T manufactory_id;
   USID_T           new_usid;
}MML1_MIPI_USID_CHANGE_T;

#endif


