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
 *    i2c_dual_sw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intended for I2C DUAL driver.
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
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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

#ifndef __I2C_PMIC_SW_H__
#define __I2C_PMIC_SW_H__

#define I2C_PMIC_DBG_LOG_ENABLE
#define I2C_PMIC_DBG_PATTERN_ENABLE
//#define I2C_PMIC_DISABLE_DCM

#if defined(I2C_PMIC_DBG_LOG_ENABLE)
#define I2C_PMIC_LOG i2c_pmic_log
#else
#define I2C_PMIC_LOG(...)
#endif

typedef enum
{
    	I2C_PMIC_READY_STATE = 0,
	I2C_PMIC_READ_STATE,
	I2C_PMIC_WRITE_STATE
}I2C_PMIC_STATE;

typedef enum
{
    	I2C_PMIC_QUERY = 0,
	I2C_PMIC_READ,
	I2C_PMIC_WRITE
}I2C_PMIC_POLLING_TYPE;


/* GCC porting related */
#if defined(__UBL__) || defined(__FUE__)
#ifdef __MTK_TARGET__

#define __i2csection(S) __attribute__ ((section (#S)))
/* Tag variables with this */
#define __emiinitrw __i2csection(EMIINITRW)
#define __emiinitzi __i2csection(EMIINITZI)
/* Tag constants with this */
#define __emiinitconst __i2csection(EMIINITCONST)
/* Tag function with this */
#define __emiinitcode __i2csection(EMIINITCODE)

#endif /* __MTK_TARGET__ */
#else //#if defined(__UBL__) || defined(__FUE__)

#define __emiinitrw
#define __emiinitzi
#define __emiinitconst
#define __emiinitcode

#endif //#if defined(__UBL__) || defined(__FUE__)

typedef enum 
{
	I2C_byte_return,
	I2C_byte_write,
	I2C_field_write,		
	I2C_read_sw_end,
	I2C_write_sw_end,
	I2C_polling_finish_reading,
	I2C_polling_finish_writing,
	I2C_polling_finish_reading_error,
	I2C_polling_finish_writing_error,
	I2C_polling_other_reading,
	I2C_polling_other_writing,
	I2C_polling_finish_other_reading,
	I2C_polling_finish_other_writing,
	I2C_polling_finish_other_reading_error,
	I2C_polling_finish_other_writing_error,
	I2C_polling_rdy_query,
	I2C_polling_rdy_read,
	I2C_polling_rdy_write,
	I2C_polling_other_finish_mine
}I2C_PMIC_DBG_INFO;

typedef struct
{
   I2C_PMIC_DBG_INFO type;
   kal_uint32 qbit;
   kal_uint32 time;
   kal_uint32 irqmask;
   kal_uint32 token;
   kal_uint32 hwowner;
   kal_uint32 PDNStatus;
}I2C_PMIC_DBG_LOG;

extern void i2c_pmic_log(I2C_PMIC_DBG_INFO type,kal_uint32 var);


#endif // #ifndef __I2C_PMIC_SW_H__

