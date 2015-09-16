/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *		dcl_pmic6323_hw.h
 *
 * Project:
 * --------
 *   	Maui_Software
 *
 * Description:
 * ------------
 *		This file is for PMIC 6323
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef __DCL_PMIC6323_HW_H_STRUCT__
#define __DCL_PMIC6323_HW_H_STRUCT__


#include "dcl_pmic_features.h"

#if defined(PMIC_6323_REG_API)

#define PMIC_BASE (0x0000)
#define GPIO_BASE (0xC000)
#define MT6323_E1_CID               0x1023

//register number
#define CHR_CON0        0x0000
#define CHR_CON1        0x0002
#define CHR_CON2        0x0004
#define CHR_CON3        0x0006
#define CHR_CON4        0x0008
#define CHR_CON5        0x000A
#define CHR_CON6        0x000C
#define CHR_CON7        0x000E
#define CHR_CON8        0x0010
#define CHR_CON9        0x0012
#define CHR_CON10       0x0014
#define CHR_CON11       0x0016
#define CHR_CON12       0x0018
#define CHR_CON13       0x001A
#define CHR_CON14       0x001C
#define CHR_CON15       0x001E
#define CHR_CON16       0x0020
#define CHR_CON17       0x0022
#define CHR_CON18       0x0024
#define CHR_CON19       0x0026
#define CHR_CON20       0x0028
#define CHR_CON21       0x002A
#define CHR_CON22       0x002C
#define CHR_CON23       0x002E
#define CHR_CON24       0x0030
#define CHR_CON25       0x0032
#define CHR_CON26       0x0034
#define CHR_CON27       0x0036
#define CHR_CON28       0x0038
#define CHR_CON29       0x003A
#define STRUP_CON0      0x003C
#define STRUP_CON2      0x003E
#define STRUP_CON3      0x0040
#define STRUP_CON4      0x0042
#define STRUP_CON5      0x0044
#define STRUP_CON6      0x0046
#define STRUP_CON7      0x0048
#define STRUP_CON8      0x004A
#define STRUP_CON9      0x004C
#define STRUP_CON10     0x004E
#define STRUP_CON11     0x0050
#define SPK_CON0        0x0052
#define SPK_CON1        0x0054
#define SPK_CON2        0x0056
#define SPK_CON6        0x005E
#define SPK_CON7        0x0060
#define SPK_CON8        0x0062
#define SPK_CON9        0x0064
#define SPK_CON10       0x0066
#define SPK_CON11       0x0068
#define SPK_CON12       0x006A
#define CID             0x0100
#define TOP_CKPDN0      0x0102
#define TOP_CKPDN1      0x0108
#define TOP_CKPDN1_SET	0x010A
#define TOP_CKPDN1_CLR	0x010C
#define TOP_CKPDN2      0x010E
#define TOP_RST_CON     0x0114
#define TOP_RST_MISC    0x011A
#define TOP_CKCON0      0x0120
#define TOP_CKCON1      0x0126
#define TOP_CKCON1_CLR  0x012A
#define TOP_CKTST0      0x012C
#define TOP_CKTST1      0x012E
#define TOP_CKTST2      0x0130
#define TEST_OUT        0x0132
#define TEST_CON0       0x0134
#define TEST_CON1       0x0136
#define EN_STATUS0      0x0138
#define EN_STATUS1      0x013A
#define OCSTATUS0       0x013C
#define OCSTATUS1       0x013E
#define PGSTATUS        0x0140
#define CHRSTATUS       0x0142
#define TDSEL_CON       0x0144
#define RDSEL_CON       0x0146
#define SMT_CON0        0x0148
#define SMT_CON1        0x014A
#define SMT_CON2        0x014C
#define SMT_CON3        0x014E
#define SMT_CON4        0x0150
#define DRV_CON0        0x0152
#define DRV_CON1        0x0154
#define DRV_CON2        0x0156
#define DRV_CON3        0x0158
#define DRV_CON4        0x015A
#define SIMLS1_CON      0x015C
#define SIMLS2_CON      0x015E
#define INT_CON0        0x0160
#define INT_CON1        0x0166
#define INT_MISC_CON    0x016C
#define INT_STATUS0     0x0172
#define INT_STATUS1     0x0174
#define OC_GEAR_0       0x0176
#define OC_GEAR_1       0x0178
#define OC_GEAR_2       0x017A
#define OC_CTL_VPROC    0x017C
#define OC_CTL_VSYS     0x017E
#define OC_CTL_VPA      0x0180
#define FQMTR_CON0      0x0182
#define FQMTR_CON1      0x0184
#define FQMTR_CON2      0x0186
#define RG_SPI_CON      0x0188
#define DEW_DIO_EN      0x018A
#define DEW_READ_TEST   0x018C
#define DEW_WRITE_TEST  0x018E
#define DEW_CRC_SWRST   0x0190
#define DEW_CRC_EN      0x0192
#define DEW_CRC_VAL     0x0194
#define DEW_DBG_MON_SEL 0x0196
#define DEW_CIPHER_KEY_SEL 0x0198
#define DEW_CIPHER_IV_SEL 0x019A
#define DEW_CIPHER_EN   0x019C
#define DEW_CIPHER_RDY  0x019E
#define DEW_CIPHER_MODE 0x01A0
#define DEW_CIPHER_SWRST 0x01A2
#define DEW_RDDMY_NO    0x01A4
#define DEW_RDATA_DLY_SEL 0x01A6
#define BUCK_CON0       0x0200
#define BUCK_CON1       0x0202
#define BUCK_CON2       0x0204
#define BUCK_CON3       0x0206
#define BUCK_CON4       0x0208
#define BUCK_CON5       0x020A
#define VPROC_CON0      0x020C
#define VPROC_CON1      0x020E
#define VPROC_CON2      0x0210
#define VPROC_CON3      0x0212
#define VPROC_CON4      0x0214
#define VPROC_CON5      0x0216
#define VPROC_CON7      0x021A
#define VPROC_CON8      0x021C
#define VPROC_CON9      0x021E
#define VPROC_CON10     0x0220
#define VPROC_CON11     0x0222
#define VPROC_CON12     0x0224
#define VPROC_CON13     0x0226
#define VPROC_CON14     0x0228
#define VPROC_CON15     0x022A
#define VPROC_CON18     0x0230
#define VSYS_CON0       0x0232
#define VSYS_CON1       0x0234
#define VSYS_CON2       0x0236
#define VSYS_CON3       0x0238
#define VSYS_CON4       0x023A
#define VSYS_CON5       0x023C
#define VSYS_CON7       0x0240
#define VSYS_CON8       0x0242
#define VSYS_CON9       0x0244
#define VSYS_CON10      0x0246
#define VSYS_CON11      0x0248
#define VSYS_CON12      0x024A
#define VSYS_CON13      0x024C
#define VSYS_CON14      0x024E
#define VSYS_CON15      0x0250
#define VSYS_CON18      0x0256
#define VPA_CON0        0x0300
#define VPA_CON1        0x0302
#define VPA_CON2        0x0304
#define VPA_CON3        0x0306
#define VPA_CON4        0x0308
#define VPA_CON5        0x030A
#define VPA_CON7        0x030E
#define VPA_CON8        0x0310
#define VPA_CON9        0x0312
#define VPA_CON10       0x0314
#define VPA_CON11       0x0316
#define VPA_CON12       0x0318
#define VPA_CON14       0x031C
#define VPA_CON16       0x0320
#define VPA_CON17       0x0322
#define VPA_CON18       0x0324
#define VPA_CON19       0x0326
#define VPA_CON20       0x0328
#define BUCK_K_CON0     0x032A
#define BUCK_K_CON1     0x032C
#define BUCK_K_CON2     0x032E
#define ISINK0_CON0     0x0330
#define ISINK0_CON1     0x0332
#define ISINK0_CON2     0x0334
#define ISINK0_CON3     0x0336
#define ISINK1_CON0     0x0338
#define ISINK1_CON1     0x033A
#define ISINK1_CON2     0x033C
#define ISINK1_CON3     0x033E
#define ISINK2_CON0     0x0340
#define ISINK2_CON1     0x0342
#define ISINK2_CON2     0x0344
#define ISINK2_CON3     0x0346
#define ISINK3_CON0     0x0348
#define ISINK3_CON1     0x034A
#define ISINK3_CON2     0x034C
#define ISINK3_CON3     0x034E
#define ISINK_ANA0      0x0350
#define ISINK_ANA1      0x0352
#define ISINK_PHASE_DLY 0x0354
#define ISINK_EN_CTRL   0x0356
#define ANALDO_CON0     0x0400
#define ANALDO_CON1     0x0402
#define ANALDO_CON2     0x0404
#define ANALDO_CON3     0x0406
#define ANALDO_CON4     0x0408
#define ANALDO_CON5     0x040A
#define ANALDO_CON6     0x040C
#define ANALDO_CON7     0x040E
#define ANALDO_CON8     0x0410
#define ANALDO_CON10    0x0412
#define ANALDO_CON15    0x0414
#define ANALDO_CON16    0x0416
#define ANALDO_CON17    0x0418
#define ANALDO_CON18    0x041A
#define ANALDO_CON19    0x041C
#define ANALDO_CON20    0x041E
#define ANALDO_CON21    0x0420
#define DIGLDO_CON0     0x0500
#define DIGLDO_CON2     0x0502
#define DIGLDO_CON3     0x0504
#define DIGLDO_CON5     0x0506
#define DIGLDO_CON6     0x0508
#define DIGLDO_CON7     0x050A
#define DIGLDO_CON8     0x050C
#define DIGLDO_CON9     0x050E
#define DIGLDO_CON10    0x0510
#define DIGLDO_CON11    0x0512
#define DIGLDO_CON12    0x0514
#define DIGLDO_CON13    0x0516
#define DIGLDO_CON14    0x0518
#define DIGLDO_CON15    0x051A
#define DIGLDO_CON16    0x051C
#define DIGLDO_CON17    0x051E
#define DIGLDO_CON18    0x0520
#define DIGLDO_CON19    0x0522
#define DIGLDO_CON20    0x0524
#define DIGLDO_CON21    0x0526
#define DIGLDO_CON23    0x0528
#define DIGLDO_CON24    0x052A
#define DIGLDO_CON26    0x052C
#define DIGLDO_CON27    0x052E
#define DIGLDO_CON28    0x0530
#define DIGLDO_CON29    0x0532
#define DIGLDO_CON30    0x0534
#define DIGLDO_CON31    0x0536
#define DIGLDO_CON32    0x0538
#define DIGLDO_CON33    0x053A
#define DIGLDO_CON34    0x053C
#define DIGLDO_CON35    0x053E
#define DIGLDO_CON36    0x0540
#define DIGLDO_CON39    0x0542
#define DIGLDO_CON40    0x0544
#define DIGLDO_CON41    0x0546
#define DIGLDO_CON42    0x0548
#define DIGLDO_CON43    0x054A
#define DIGLDO_CON44    0x054C
#define DIGLDO_CON45    0x054E
#define DIGLDO_CON46    0x0550
#define DIGLDO_CON47    0x0552
#define DIGLDO_CON48    0x0554
#define DIGLDO_CON49    0x0556
#define DIGLDO_CON50    0x0558
#define DIGLDO_CON51    0x055A
#define DIGLDO_CON52    0x055C
#define DIGLDO_CON53    0x055E
#define DIGLDO_CON54    0x0560
#define EFUSE_CON0      0x0600
#define EFUSE_CON1      0x0602
#define EFUSE_CON2      0x0604
#define EFUSE_CON3      0x0606
#define EFUSE_CON4      0x0608
#define EFUSE_CON5      0x060A
#define EFUSE_CON6      0x060C
#define EFUSE_VAL_0_15  0x060E
#define EFUSE_VAL_16_31 0x0610
#define EFUSE_VAL_32_47 0x0612
#define EFUSE_VAL_48_63 0x0614
#define EFUSE_VAL_64_79 0x0616
#define EFUSE_VAL_80_95 0x0618
#define EFUSE_VAL_96_111 0x061A
#define EFUSE_VAL_112_127 0x061C
#define EFUSE_VAL_128_143 0x061E
#define EFUSE_VAL_144_159 0x0620
#define EFUSE_VAL_160_175 0x0622
#define EFUSE_VAL_176_191 0x0624
#define EFUSE_DOUT_0_15 0x0626
#define EFUSE_DOUT_16_31 0x0628
#define EFUSE_DOUT_32_47 0x062A
#define EFUSE_DOUT_48_63 0x062C
#define EFUSE_DOUT_64_79 0x062E
#define EFUSE_DOUT_80_95 0x0630
#define EFUSE_DOUT_96_111 0x0632
#define EFUSE_DOUT_112_127 0x0634
#define EFUSE_DOUT_128_143 0x0636
#define EFUSE_DOUT_144_159 0x0638
#define EFUSE_DOUT_160_175 0x063A
#define EFUSE_DOUT_176_191 0x063C
#define EFUSE_CON7      0x063E
#define EFUSE_CON8      0x0640
#define EFUSE_CON9      0x0642
#define RTC_MIX_CON0    0x0644
#define RTC_MIX_CON1    0x0646
#define AUDTOP_CON0     0x0700
#define AUDTOP_CON1     0x0702
#define AUDTOP_CON2     0x0704
#define AUDTOP_CON3     0x0706
#define AUDTOP_CON4     0x0708
#define AUDTOP_CON5     0x070A
#define AUDTOP_CON6     0x070C
#define AUDTOP_CON7     0x070E
#define AUDTOP_CON8     0x0710
#define AUDTOP_CON9     0x0712
#define AUXADC_ADC0     0x0714
#define AUXADC_ADC1     0x0716
#define AUXADC_ADC2     0x0718
#define AUXADC_ADC3     0x071A
#define AUXADC_ADC4     0x071C
#define AUXADC_ADC5     0x071E
#define AUXADC_ADC6     0x0720
#define AUXADC_ADC7     0x0722
#define AUXADC_ADC8     0x0724
#define AUXADC_ADC9     0x0726
#define AUXADC_ADC10    0x0728
#define AUXADC_ADC11    0x072A
#define AUXADC_ADC12    0x072C
#define AUXADC_ADC13    0x072E
#define AUXADC_ADC14    0x0730
#define AUXADC_ADC15    0x0732
#define AUXADC_ADC16    0x0734
#define AUXADC_ADC17    0x0736
#define AUXADC_ADC18    0x0738
#define AUXADC_ADC19    0x073A
#define AUXADC_ADC20    0x073C
#define AUXADC_RSV1     0x073E
#define AUXADC_RSV2     0x0740
#define AUXADC_CON0     0x0742
#define AUXADC_CON1     0x0744
#define AUXADC_CON2     0x0746
#define AUXADC_CON3     0x0748
#define AUXADC_CON4     0x074A
#define AUXADC_CON5     0x074C
#define AUXADC_CON6     0x074E
#define AUXADC_CON7     0x0750
#define AUXADC_CON8     0x0752
#define AUXADC_CON9     0x0754
#define AUXADC_CON10    0x0756
#define AUXADC_CON11    0x0758
#define AUXADC_CON12    0x075A
#define AUXADC_CON13    0x075C
#define AUXADC_CON14    0x075E
#define AUXADC_CON15    0x0760
#define AUXADC_CON16    0x0762
#define AUXADC_CON17    0x0764
#define AUXADC_CON18    0x0766
#define AUXADC_CON19    0x0768
#define AUXADC_CON20    0x076A
#define AUXADC_CON21    0x076C
#define AUXADC_CON22    0x076E
#define AUXADC_CON23    0x0770
#define AUXADC_CON24    0x0772
#define AUXADC_CON25    0x0774
#define AUXADC_CON26    0x0776
#define AUXADC_CON27    0x0778
#define ACCDET_CON0     0x077A
#define ACCDET_CON1     0x077C
#define ACCDET_CON2     0x077E
#define ACCDET_CON3     0x0780
#define ACCDET_CON4     0x0782
#define ACCDET_CON5     0x0784
#define ACCDET_CON6     0x0786
#define ACCDET_CON7     0x0788
#define ACCDET_CON8     0x078A
#define ACCDET_CON9     0x078C
#define ACCDET_CON10    0x078E
#define ACCDET_CON11    0x0790
#define ACCDET_CON12    0x0792
#define ACCDET_CON13    0x0794
#define ACCDET_CON14    0x0796
#define ACCDET_CON15    0x0798
#define ACCDET_CON16    0x079A

//mask is HEX
//shift is Integer
#define RG_CLKSQ_EN_AUX_MD_MASK	0x1
#define RG_CLKSQ_EN_AUX_MD_SHIFT 14
#define RG_VPA_MODESET_MASK 0x1
#define RG_VPA_MODESET_SHIFT 8
#define VPA_EN_MASK 0x1
#define VPA_EN_SHIFT 0
#define RG_STB_SIM1_SIO_MASK 0x1
#define RG_STB_SIM1_SIO_SHIFT 0
#define RG_VSIM1_EN_MASK 0x1
#define RG_VSIM1_EN_SHIFT 15
#define VSIM1_LP_MODE_SET_MASK 0x1
#define VSIM1_LP_MODE_SET_SHIFT 1
#define VSIM1_LP_SEL_MASK 0x1
#define VSIM1_LP_SEL_SHIFT 0
#define RG_VSIM2_EN_MASK 0x1
#define RG_VSIM2_EN_SHIFT 15
#define VSIM2_LP_MODE_SET_MASK 0x1
#define VSIM2_LP_MODE_SET_SHIFT 1
#define VSIM2_LP_SEL_MASK 0x1
#define VSIM2_LP_SEL_SHIFT 0
#define RG_STB_SIM2_SIO_MASK 0x1
#define RG_STB_SIM2_SIO_SHIFT 0
#define RG_VSIM1_VOSEL_MASK 0x1
#define RG_VSIM1_VOSEL_SHIFT 5
#define RG_VSIM2_VOSEL_MASK 0x1
#define RG_VSIM2_VOSEL_SHIFT 5
#define RG_VRF18_EN_MASK 0x1
#define RG_VRF18_EN_SHIFT 15
#define VRF18_LP_MODE_SET_MASK 0x1
#define VRF18_LP_MODE_SET_SHIFT 1
#define VRF18_LP_SEL_MASK 0x1
#define VRF18_LP_SEL_SHIFT 0
#define VRF18_ON_CTRL_MASK 0x1
#define VRF18_ON_CTRL_SHIFT 1
#define RG_ADC_OUT_MD_MASK 0xFFFF
#define RG_ADC_OUT_MD_SHIFT 0
#define RG_ADC_RDY_MD_MASK 0x1
#define RG_ADC_RDY_MD_SHIFT 15
#define RG_MD_RQST_MASK 0x1
#define RG_MD_RQST_SHIFT 15

// ====================================================================== //
#define GPIO_DOUT1_SET      0x0082
#define GPIO_DOUT1_CLR      0x0084
#define GPIO_DOUT2_SET      0x008A
#define GPIO_DOUT2_CLR      0x008C

#define GPIO15_DOUT_SET_MASK 0x1
#define GPIO15_DOUT_SET_SHIFT 15
#define GPIO15_DOUT_CLR_MASK 0x1
#define GPIO15_DOUT_CLR_SHIFT 15
#define GPIO17_DOUT_SET_MASK 0x1
#define GPIO17_DOUT_SET_SHIFT 1
#define GPIO17_DOUT_CLR_MASK 0x1
#define GPIO17_DOUT_CLR_SHIFT 1

#endif // #ifdef PMIC_6323_REG_API
#endif // #ifndef __DCL_PMIC6323_HW_H_STRUCT__

