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

#ifndef __I2C_DUAL_SW_H__
#define __I2C_DUAL_SW_H__


// MoDIS parser skip start
// The following are private APIs
// I2C DUAL driver is only used by PMIC6326 for now, NOT exported for other owners

// #define MEASURE_I2C_DUAL_PERIOD
//#define I2C_DUAL_AP_MD_TEST

#define I2C_DUAL_CHANNEL1       1
#define I2C_DUAL_CHANNEL2       2
#define I2C_DUAL_READ           0
#define I2C_DUAL_WRITE          1

#define I2C_CLK_RATE                        16250//13000   

#define MAX_ST_MODE_SPEED                   100     /* khz */
#define MAX_FS_MODE_SPEED                   1000     /* khz */
#define MAX_HS_MODE_SPEED                   3400    /* khz */

#define MAX_SAMPLE_CNT_DIV                  8
#define MAX_STEP_CNT_DIV                    64
#define MAX_HS_STEP_CNT_DIV                 8

typedef enum {
    ST_MODE,
    FS_MODE,
    HS_MODE,
} I2C_SPD_MODE;

#if defined(MT6326)
kal_bool pmic6326_reg_write(kal_uint8 reg, kal_uint8 val);
kal_bool pmic6326_reg_read(kal_uint8 reg, kal_uint8 *pval);

kal_bool pmic6326_reg_write_intr(kal_uint8 reg, kal_uint8 val);
kal_bool pmic6326_reg_read_intr(kal_uint8 reg, kal_uint8 *pval);

kal_bool pmic6326_reg_write_polling(kal_uint8 reg, kal_uint8 val);
kal_bool pmic6326_reg_read_polling(kal_uint8 reg, kal_uint8 *pval);

kal_bool pmic6326_reg_write_fast(kal_uint8 reg, kal_uint8 val);
kal_bool pmic6326_reg_read_fast(kal_uint8 reg, kal_uint8 *pval);

kal_bool pmic6326_ch2_reg_write(kal_uint8 reg, kal_uint8 val);
kal_bool pmic6326_ch2_reg_read(kal_uint8 reg, kal_uint8 *pval);

kal_bool pmic6326_ch2_reg_write_intr(kal_uint8 reg, kal_uint8 val);
kal_bool pmic6326_ch2_reg_read_intr(kal_uint8 reg, kal_uint8 *pval);

kal_bool pmic6326_ch2_reg_write_polling(kal_uint8 reg, kal_uint8 val);
kal_bool pmic6326_ch2_reg_read_polling(kal_uint8 reg, kal_uint8 *pval);

kal_bool pmic6326_ch2_reg_write_fast(kal_uint8 reg, kal_uint8 val);
kal_bool pmic6326_ch2_reg_read_fast(kal_uint8 reg, kal_uint8 *pval);

#elif (defined(MT6329) || defined(MT6327))
#define PMIC_BANK0              0
#define PMIC_BANK1              1

#if defined(MEASURE_I2C_DUAL_PERIOD)
extern kal_uint32 i2c_dual_time1;
extern kal_uint32 i2c_dual_time2;
extern kal_uint32 i2c_dual_time3;
#endif

kal_bool pmic6329_reg_write(kal_uint8 reg, kal_uint8 val, kal_uint32 bank);
kal_bool pmic6329_reg_read(kal_uint8 reg, kal_uint8 *pval, kal_uint32 bank);

kal_bool pmic6329_reg_write_intr(kal_uint8 reg, kal_uint8 val, kal_uint32 bank);
kal_bool pmic6329_reg_read_intr(kal_uint8 reg, kal_uint8 *pval, kal_uint32 bank);

kal_bool pmic6329_reg_write_polling(kal_uint8 reg, kal_uint8 val, kal_uint32 bank);
kal_bool pmic6329_reg_read_polling(kal_uint8 reg, kal_uint8 *pval, kal_uint32 bank);

kal_bool pmic6329_reg_write_fast(kal_uint8 reg, kal_uint8 val, kal_uint32 bank);
kal_bool pmic6329_reg_read_fast(kal_uint8 reg, kal_uint8 *pval, kal_uint32 bank);

kal_bool pmic6329_ch2_reg_write(kal_uint8 reg, kal_uint8 val, kal_uint32 bank);
kal_bool pmic6329_ch2_reg_read(kal_uint8 reg, kal_uint8 *pval, kal_uint32 bank);

kal_bool pmic6329_ch2_reg_write_intr(kal_uint8 reg, kal_uint8 val, kal_uint32 bank);
kal_bool pmic6329_ch2_reg_read_intr(kal_uint8 reg, kal_uint8 *pval, kal_uint32 bank);

kal_bool pmic6329_ch2_reg_write_polling(kal_uint8 reg, kal_uint8 val, kal_uint32 bank);
kal_bool pmic6329_ch2_reg_read_polling(kal_uint8 reg, kal_uint8 *pval, kal_uint32 bank);

kal_bool pmic6329_ch2_reg_write_fast(kal_uint8 reg, kal_uint8 val, kal_uint32 bank);
kal_bool pmic6329_ch2_reg_read_fast(kal_uint8 reg, kal_uint8 *pval, kal_uint32 bank);


//==============================================================================
// I2C Exported Function
//==============================================================================
extern void i2c_v1_set_speed (unsigned long clock, I2C_SPD_MODE mode, unsigned long khz);
extern void i2c_dual_ap_md_test(void);
extern kal_bool i2c_dual_polling_trans_comp(kal_uint32 channel);
#endif // End of #if defined(MT6326)
// MoDIS parser skip end

#endif // #ifndef __I2C_DUAL_SW_H__

