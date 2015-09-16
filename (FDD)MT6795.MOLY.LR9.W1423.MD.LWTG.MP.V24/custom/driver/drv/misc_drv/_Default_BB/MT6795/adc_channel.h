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
 *    adc_channel.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for GPT driver.
 *
 * Author:
 * -------
 * -------
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _ADC_CHANNEL_H
#define _ADC_CHANNEL_H

/*voltage to temperature*/
#define ADC_TEMP_T1  0*1000000   /*0C*/
#define ADC_TEMP_T2  25*1000000  /*25C*/
#define ADC_TEMP_T3  50*1000000  /*50C*/

#define ADC_TEMP_NTCR1 26490.0   /*resistor at 0C*/
#define ADC_TEMP_NTCR2 10000.0   /*resistor at 25C*/
#define ADC_TEMP_NTCR3 4171.0    /*resistor at 50C*/

#define ADC_TEMP_PUR 24000.0      /*orginal registor*/
#define ADC_TEMP_AVDD 2800000.0
#define ADC_TEMP_SCALE 10.0

#define ADC_TEMP_V1 (ADC_TEMP_AVDD*(ADC_TEMP_NTCR1/(ADC_TEMP_NTCR1+ADC_TEMP_PUR))) /*voltage at 0C*/
#define ADC_TEMP_V2 (ADC_TEMP_AVDD*(ADC_TEMP_NTCR2/(ADC_TEMP_NTCR2+ADC_TEMP_PUR))) /*voltage at 25C*/
#define ADC_TEMP_V3 (ADC_TEMP_AVDD*(ADC_TEMP_NTCR3/(ADC_TEMP_NTCR3+ADC_TEMP_PUR))) /*voltage at 50C*/

#define ADC_TEMP_M12 (((ADC_TEMP_T1-ADC_TEMP_T2)*ADC_TEMP_SCALE)/(ADC_TEMP_V1-ADC_TEMP_V2))  /*T1T2's slope */
#define ADC_TEMP_M23 (((ADC_TEMP_T2-ADC_TEMP_T3)*ADC_TEMP_SCALE)/(ADC_TEMP_V2-ADC_TEMP_V3))  /*T2T3's slppe*/

#define ADC_TEMPV2_FACTOR    ADC_TEMP_V2
#define ADC_TEMPA12_FACTOR   (ADC_TEMP_T1-ADC_TEMP_M12/ADC_TEMP_SCALE*ADC_TEMP_V1)
#define ADC_TEMPA23_FACTOR   (ADC_TEMP_T2-ADC_TEMP_M23/ADC_TEMP_SCALE*ADC_TEMP_V2)
#define ADC_TEMPM12_FACTOR   ADC_TEMP_M12
#define ADC_TEMPM23_FACTOR   ADC_TEMP_M23
#define ADC_TEMPSCALE_FACTOR ADC_TEMP_SCALE


#define ADC_ISENSE_FACTOR 2.5 //BMT ISENSE RESISTENCE FACTOR 5 = 1/0.2 --> resister use 0.2 Ohm

//only use channels < ADC_MAX_CHANNEL define in mcu\hal\drv_def\drv_features_adc.h
#define ADC_CALIBRATION_SLOPE_CH0  1232
#define ADC_CALIBRATION_SLOPE_CH1  1232
#define ADC_CALIBRATION_SLOPE_CH2  1232
#define ADC_CALIBRATION_SLOPE_CH3  1232
#define ADC_CALIBRATION_SLOPE_CH4  1232
#define ADC_CALIBRATION_SLOPE_CH5  1232
#define ADC_CALIBRATION_SLOPE_CH6  1232
#define ADC_CALIBRATION_SLOPE_CH7  1232
#define ADC_CALIBRATION_SLOPE_CH8  1232
#define ADC_CALIBRATION_SLOPE_CH9  1232
#define ADC_CALIBRATION_SLOPE_CH10 1232
#define ADC_CALIBRATION_SLOPE_CH11 1232
#define ADC_CALIBRATION_SLOPE_CH12 1232
#define ADC_CALIBRATION_SLOPE_CH13 1232
#define ADC_CALIBRATION_SLOPE_CH14 1232
#define ADC_CALIBRATION_SLOPE_CH15 1232
#define ADC_CALIBRATION_SLOPE_CH16 1232
#define ADC_CALIBRATION_SLOPE_CH17 1232
#define ADC_CALIBRATION_SLOPE_CH18 1232
#define ADC_CALIBRATION_SLOPE_CH19 1232

#define ADC_CALIBRATION_OFFSET_CH0  28673
#define ADC_CALIBRATION_OFFSET_CH1  28673
#define ADC_CALIBRATION_OFFSET_CH2  28673
#define ADC_CALIBRATION_OFFSET_CH3  28673
#define ADC_CALIBRATION_OFFSET_CH4  28673
#define ADC_CALIBRATION_OFFSET_CH5  28673
#define ADC_CALIBRATION_OFFSET_CH6  28673
#define ADC_CALIBRATION_OFFSET_CH7  28673
#define ADC_CALIBRATION_OFFSET_CH8  28673
#define ADC_CALIBRATION_OFFSET_CH9  28673
#define ADC_CALIBRATION_OFFSET_CH10 28673
#define ADC_CALIBRATION_OFFSET_CH11 28673
#define ADC_CALIBRATION_OFFSET_CH12 28673
#define ADC_CALIBRATION_OFFSET_CH13 28673
#define ADC_CALIBRATION_OFFSET_CH14 28673
#define ADC_CALIBRATION_OFFSET_CH15 28673
#define ADC_CALIBRATION_OFFSET_CH16 28673
#define ADC_CALIBRATION_OFFSET_CH17 28673
#define ADC_CALIBRATION_OFFSET_CH18 28673
#define ADC_CALIBRATION_OFFSET_CH19 28673

#define ADC_VOLT_FACTOR_CH0  100
#define ADC_VOLT_FACTOR_CH1  100
#define ADC_VOLT_FACTOR_CH2  100
#define ADC_VOLT_FACTOR_CH3  250
#define ADC_VOLT_FACTOR_CH4  100
#define ADC_VOLT_FACTOR_CH5  100
#define ADC_VOLT_FACTOR_CH6  100
#define ADC_VOLT_FACTOR_CH7  100
#define ADC_VOLT_FACTOR_CH8  100
#define ADC_VOLT_FACTOR_CH9  100
#define ADC_VOLT_FACTOR_CH10 100
#define ADC_VOLT_FACTOR_CH11 100
#define ADC_VOLT_FACTOR_CH12 100
#define ADC_VOLT_FACTOR_CH13 100
#define ADC_VOLT_FACTOR_CH14 100
#define ADC_VOLT_FACTOR_CH15 100
#define ADC_VOLT_FACTOR_CH16 100
#define ADC_VOLT_FACTOR_CH17 100
#define ADC_VOLT_FACTOR_CH18 100
#define ADC_VOLT_FACTOR_CH19 100

#endif   /*_ADC_H*/

