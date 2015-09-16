/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *    dcl_sim_gpio.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file defines structures and functions for SIM GPIO DCL interface.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef DCL_DEFINITION_STRUCT

#ifndef __DCL_SIM_GPIO_H_STRUCT__
#define __DCL_SIM_GPIO_H_STRUCT__

/*RHR*/
//#include "kal_non_specific_general_types.h"
#include "dcl.h"
/*RHR*/

typedef enum{
   MT6306_SIM_GPIO1 = 0,
   MT6306_SIM_GPIO2,
   MT6306_SIM_GPIO3,
   MT6306_SIM_GPIO4,
   MT6306_SIM_GPIO5,
   MT6306_SIM_GPIO6,
   MT6306_SIM_GPIO7,
   MT6306_SIM_GPIO8,
   MT6306_SIM_GPIO9,
   MT6306_SIM_GPIO10,
   MT6306_SIM_GPIO11,
   MT6306_SIM_GPIO12,
   MT6306_SIM_GPI13,
   MT6306_SIM_GPI14,
   MT6306_SIM_GPI15,
   MT6306_SIM_GPI16,
   MT6306_SIM_GPI17,
   MT6306_SIM_GPI18,
}DCL_SIMGPIO_PIN_DEF;

#define SIMGPIO_PULL_HIGH			1
#define SIMGPIO_PULL_LOW			0
#define SIMGPIO_DIR_IN           0
#define SIMGPIO_DIR_OUT          1 
#define SIMGPIO_VOLT_18V         0
#define SIMGPIO_VOLT_28V         1
#define SIMGPIO_VOLT_30V         2


/*******************************************************************************
 * DCL_OPTIONS for SIMGPIO
 *******************************************************************************/
#define SIMGPIO_OPTIONS

/*******************************************************************************
 * DCL_CONFIGURE_T
 *******************************************************************************/

/*******************************************************************************
 * DCL_EVENT for GPIO
 *******************************************************************************/
#define SIMGPIO_EVENTS

/*******************************************************************************
 * DCL_CTRL_CMD for GPIO
 *******************************************************************************/
#define SIMGPIO_CMDS    \
   SIMGPIO_CMD_READ,  \
   SIMGPIO_CMD_WRITE,  \
   SIMGPIO_CMD_SET_DIR,  \
   SIMGPIO_CMD_TRUN_ON_VCC,  \
   SIMGPI_CMD_READ,

/*******************************************************************************
 * DCL_CTRL_DATA_T: Define the Control data structure for each module's command
 *******************************************************************************/
/* FOR GPIO_CMD_READ control command. */
typedef struct
{
   DCL_UINT8   u1IOData; // GPIO_IO_HIGH or GPIO_IO_LOW
} SIMGPIO_CTRL_READ_T;

/* FOR SIMGPIO_CMD_WRITE control command. */
typedef struct
{
   DCL_UINT8   u1IOData;// GPIO_IO_HIGH or GPIO_IO_LOW
} SIMGPIO_CTRL_WRITE_T;

/* FOR SIMGPIO_CMD_SET_DIR control command. */
typedef struct
{
   DCL_UINT16  u2Dir;
} SIMGPIO_CTRL_SET_DIR_T;

/* FOR SIMGPIO_CMD_TRUN_ON_VCC control command. */
typedef struct
{
   kal_bool on;
   kal_uint8 volt;
} SIMGPIO_CTRL_TRUN_ON_POWER;

#define SIMGPIO_CTRLS \
   SIMGPIO_CTRL_READ_T               rSGRead; \
   SIMGPIO_CTRL_WRITE_T              rSGWrite; \
   SIMGPIO_CTRL_SET_DIR_T            rSGSetDir; \
   SIMGPIO_CTRL_TRUN_ON_POWER        rSGTurnOnPower; \
   SIMGPIO_CTRL_READ_T               rSGIRead;

#endif /*__DCL_SIM_GPIO_H_STRUCT__*/

#endif /*DCL_DEFINITION_STRUCT*/

#ifdef DCL_DEFINITION_PROTOTYPE
#ifndef __DCL_SIM_GPIO_H_PROTOTYPE__
#define __DCL_SIM_GPIO_H_PROTOTYPE__
DCL_STATUS DclSIMGPIO_Initialize(void);
DCL_HANDLE DclSIMGPIO_Open(DCL_DEV dev, DCL_FLAGS flags);
DCL_STATUS DclSIMGPIO_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);
DCL_STATUS DclSIMGPIO_Close(DCL_HANDLE handle);
#endif /*__DCL_SIM_GPIO_H_PROTOTYPE__*/
#endif //DCL_DEFINITION_PROTOTYPE


