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
 *		dcl_pmic6320_hw.h
 *
 * Project:
 * --------
 *   	Maui_Software
 *
 * Description:
 * ------------
 *		This file is for PMIC 6320
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef __DCL_PMIC6320_HW_H_STRUCT__
#define __DCL_PMIC6320_HW_H_STRUCT__


#include "dcl_pmic_features.h"

#if defined(PMIC_6320_REG_API)

#define PMIC_BASE (0x0000)
#define DEW_BASE  (0xBC00)
#define MT6320_E1_CID               0x1020

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
#define CID             0x0100
#define TOP_CKPDN       0x0102
#define TOP_CKPDN2      0x0108
#define TOP_GPIO_CKPDN  0x010E
#define TOP_RST_CON     0x0114
#define WRP_CKPDN       0x011A
#define WRP_RST_CON     0x0120
#define TOP_RST_MISC    0x0126
#define TOP_CKCON1      0x0128
#define TOP_CKCON2      0x012A
#define TOP_CKTST1      0x012C
#define TOP_CKTST2      0x012E
#define OC_DEG_EN       0x0130
#define OC_CTL0         0x0132
#define OC_CTL1         0x0134
#define OC_CTL2         0x0136
#define INT_RSV         0x0138
#define TEST_CON0       0x013A
#define TEST_CON1       0x013C
#define STATUS0         0x013E
#define STATUS1         0x0140
#define PGSTATUS        0x0142
#define CHRSTATUS       0x0144
#define OCSTATUS0       0x0146
#define OCSTATUS1       0x0148
#define OCSTATUS2       0x014A
#define SIMLS_CON       0x014C
#define TEST_OUT_L      0x014E
#define TEST_OUT_H      0x0150
#define TDSEL_CON       0x0152
#define RDSEL_CON       0x0154
#define GPIO_SMT_CON0   0x0156
#define GPIO_SMT_CON1   0x0158
#define GPIO_SMT_CON2   0x015A
#define GPIO_SMT_CON3   0x015C
#define DRV_CON0        0x015E
#define DRV_CON1        0x0160
#define DRV_CON2        0x0162
#define DRV_CON3        0x0164
#define DRV_CON4        0x0166
#define DRV_CON5        0x0168
#define DRV_CON6        0x016A
#define DRV_CON7        0x016C
#define DRV_CON8        0x016E
#define DRV_CON9        0x0170
#define DRV_CON10       0x0172
#define DRV_CON11       0x0174
#define DRV_CON12       0x0176
#define INT_CON0        0x0178
#define INT_CON1        0x017E
#define INT_STATUS0     0x0184
#define INT_STATUS1     0x0186
#define FQMTR_CON0      0x0188
#define FQMTR_CON1      0x018A
#define FQMTR_CON2      0x018C
#define EFUSE_CON0      0x018E
#define EFUSE_CON1      0x0190
#define EFUSE_CON2      0x0192
#define EFUSE_CON3      0x0194
#define EFUSE_CON4      0x0196
#define EFUSE_CON5      0x0198
#define EFUSE_CON6      0x019A
#define EFUSE_VAL_0_15  0x019C
#define EFUSE_VAL_16_31 0x019E
#define EFUSE_VAL_32_47 0x01A0
#define EFUSE_VAL_48_63 0x01A2
#define EFUSE_VAL_64_79 0x01A4
#define EFUSE_VAL_80_95 0x01A6
#define EFUSE_VAL_96_111 0x01A8
#define EFUSE_VAL_112_127 0x01AA
#define EFUSE_VAL_128_143 0x01AC
#define EFUSE_VAL_144_159 0x01AE
#define EFUSE_VAL_160_175 0x01B0
#define EFUSE_VAL_176_191 0x01B2
#define EFUSE_DOUT_0_15 0x01B4
#define EFUSE_DOUT_16_31 0x01B6
#define EFUSE_DOUT_32_47 0x01B8
#define EFUSE_DOUT_48_63 0x01BA
#define EFUSE_DOUT_64_79 0x01BC
#define EFUSE_DOUT_80_95 0x01BE
#define EFUSE_DOUT_96_111 0x01C0
#define EFUSE_DOUT_112_127 0x01C2
#define EFUSE_DOUT_128_143 0x01C4
#define EFUSE_DOUT_144_159 0x01C6
#define EFUSE_DOUT_160_175 0x01C8
#define EFUSE_DOUT_176_191 0x01CA
#define SPI_CON         0x01CC
#define BUCK_CON0       0x0200
#define BUCK_CON1       0x0202
#define BUCK_CON2       0x0204
#define VPROC_CON0      0x0206
#define VPROC_CON1      0x0208
#define VPROC_CON2      0x020A
#define VPROC_CON3      0x020C
#define VPROC_CON4      0x020E
#define VPROC_CON5      0x0210
#define VPROC_CON6      0x0212
#define VPROC_CON7      0x0214
#define VPROC_CON8      0x0216
#define VPROC_CON9      0x0218
#define VPROC_CON10     0x021A
#define VPROC_CON11     0x021C
#define VPROC_CON12     0x021E
#define VPROC_CON13     0x0220
#define VPROC_CON14     0x0222
#define VPROC_CON15     0x0224
#define VPROC_CON16     0x0226
#define VPROC_CON17     0x0228
#define VPROC_CON18     0x022A
#define VSRAM_CON0      0x022C
#define VSRAM_CON1      0x022E
#define VSRAM_CON2      0x0230
#define VSRAM_CON3      0x0232
#define VSRAM_CON4      0x0234
#define VSRAM_CON5      0x0236
#define VSRAM_CON6      0x0238
#define VSRAM_CON7      0x023A
#define VSRAM_CON8      0x023C
#define VSRAM_CON9      0x023E
#define VSRAM_CON10     0x0240
#define VSRAM_CON11     0x0242
#define VSRAM_CON12     0x0244
#define VSRAM_CON13     0x0246
#define VSRAM_CON14     0x0248
#define VSRAM_CON15     0x024A
#define VSRAM_CON16     0x024C
#define VSRAM_CON17     0x024E
#define VSRAM_CON18     0x0250
#define VSRAM_CON19     0x0252
#define VSRAM_CON20     0x0254
#define VSRAM_CON21     0x0256
#define VCORE_CON0      0x0258
#define VCORE_CON1      0x025A
#define VCORE_CON2      0x025C
#define VCORE_CON3      0x025E
#define VCORE_CON4      0x0260
#define VCORE_CON5      0x0262
#define VCORE_CON6      0x0264
#define VCORE_CON7      0x0266
#define VCORE_CON8      0x0268
#define VCORE_CON9      0x026A
#define VCORE_CON10     0x026C
#define VCORE_CON11     0x026E
#define VCORE_CON12     0x0270
#define VCORE_CON13     0x0272
#define VCORE_CON14     0x0274
#define VCORE_CON15     0x0276
#define VCORE_CON16     0x0278
#define VCORE_CON17     0x027A
#define VCORE_CON18     0x027C
#define VM_CON0         0x027E
#define VM_CON1         0x0280
#define VM_CON2         0x0282
#define VM_CON3         0x0284
#define VM_CON4         0x0286
#define VM_CON5         0x0288
#define VM_CON6         0x028A
#define VM_CON7         0x028C
#define VM_CON8         0x028E
#define VM_CON9         0x0290
#define VM_CON10        0x0292
#define VM_CON11        0x0294
#define VM_CON12        0x0296
#define VM_CON13        0x0298
#define VM_CON14        0x029A
#define VM_CON15        0x029C
#define VM_CON16        0x029E
#define VM_CON17        0x02A0
#define VM_CON18        0x02A2
#define VIO18_CON0      0x0300
#define VIO18_CON1      0x0302
#define VIO18_CON2      0x0304
#define VIO18_CON3      0x0306
#define VIO18_CON4      0x0308
#define VIO18_CON5      0x030A
#define VIO18_CON6      0x030C
#define VIO18_CON7      0x030E
#define VIO18_CON8      0x0310
#define VIO18_CON9      0x0312
#define VIO18_CON10     0x0314
#define VIO18_CON11     0x0316
#define VIO18_CON12     0x0318
#define VIO18_CON13     0x031A
#define VIO18_CON14     0x031C
#define VIO18_CON15     0x031E
#define VIO18_CON16     0x0320
#define VIO18_CON17     0x0322
#define VIO18_CON18     0x0324
#define VPA_CON0        0x0326
#define VPA_CON1        0x0328
#define VPA_CON2        0x032A
#define VPA_CON3        0x032C
#define VPA_CON4        0x032E
#define VPA_CON5        0x0330
#define VPA_CON6        0x0332
#define VPA_CON7        0x0334
#define VPA_CON8        0x0336
#define VPA_CON9        0x0338
#define VPA_CON10       0x033A
#define VPA_CON11       0x033C
#define VPA_CON12       0x033E
#define VPA_CON13       0x0340
#define VPA_CON14       0x0342
#define VPA_CON15       0x0344
#define VPA_CON16       0x0346
#define VPA_CON17       0x0348
#define VPA_CON18       0x034A
#define VPA_CON19       0x034C
#define VPA_CON20       0x034E
#define VRF18_CON0      0x0350
#define VRF18_CON1      0x0352
#define VRF18_CON2      0x0354
#define VRF18_CON3      0x0356
#define VRF18_CON4      0x0358
#define VRF18_CON5      0x035A
#define VRF18_CON6      0x035C
#define VRF18_CON7      0x035E
#define VRF18_CON8      0x0360
#define VRF18_CON9      0x0362
#define VRF18_CON10     0x0364
#define VRF18_CON11     0x0366
#define VRF18_CON12     0x0368
#define VRF18_CON13     0x036A
#define VRF18_CON14     0x036C
#define VRF18_CON15     0x036E
#define VRF18_CON16     0x0370
#define VRF18_CON17     0x0372
#define VRF18_CON18     0x0374
#define VRF18_CON19     0x0376
#define VRF18_CON20     0x0378
#define VRF18_2_CON0    0x037A
#define VRF18_2_CON1    0x037C
#define VRF18_2_CON2    0x037E
#define VRF18_2_CON3    0x0380
#define VRF18_2_CON4    0x0382
#define VRF18_2_CON5    0x0384
#define VRF18_2_CON6    0x0386
#define VRF18_2_CON7    0x0388
#define VRF18_2_CON8    0x038A
#define VRF18_2_CON9    0x038C
#define VRF18_2_CON10   0x038E
#define VRF18_2_CON11   0x0390
#define VRF18_2_CON12   0x0392
#define VRF18_2_CON13   0x0394
#define VRF18_2_CON14   0x0396
#define VRF18_2_CON15   0x0398
#define VRF18_2_CON16   0x039A
#define VRF18_2_CON17   0x039C
#define VRF18_2_CON18   0x039E
#define BUCK_K_CON0     0x03A0
#define BUCK_K_CON1     0x03A2
#define ANALDO_CON0     0x0400
#define ANALDO_CON1     0x0402
#define ANALDO_CON2     0x0404
#define ANALDO_CON3     0x0406
#define ANALDO_CON4     0x0408
#define ANALDO_CON5     0x040A
#define ANALDO_CON6     0x040C
#define ANALDO_CON7     0x040E
#define ANALDO_CON8     0x0410
#define ANALDO_CON9     0x0412
#define ANALDO_CON10    0x0414
#define ANALDO_CON11    0x0416
#define ANALDO_CON12    0x0418
#define ANALDO_CON13    0x041A
#define ANALDO_CON14    0x041C
#define ANALDO_CON15    0x041E
#define DIGLDO_CON0     0x0420
#define DIGLDO_CON2     0x0422
#define DIGLDO_CON3     0x0424
#define DIGLDO_CON5     0x0426
#define DIGLDO_CON6     0x0428
#define DIGLDO_CON7     0x042A
#define DIGLDO_CON8     0x042C
#define DIGLDO_CON9     0x042E
#define DIGLDO_CON10    0x0430
#define DIGLDO_CON11    0x0432
#define DIGLDO_CON12    0x0434
#define DIGLDO_CON13    0x0436
#define DIGLDO_CON14    0x0438
#define DIGLDO_CON15    0x043A
#define DIGLDO_CON16    0x043C
#define DIGLDO_CON17    0x043E
#define DIGLDO_CON18    0x0440
#define DIGLDO_CON19    0x0442
#define DIGLDO_CON20    0x0444
#define DIGLDO_CON21    0x0446
#define DIGLDO_CON23    0x0448
#define DIGLDO_CON24    0x044A
#define DIGLDO_CON26    0x044C
#define DIGLDO_CON27    0x044E
#define DIGLDO_CON28    0x0450
#define DIGLDO_CON29    0x0452
#define DIGLDO_CON30    0x0454
#define DIGLDO_CON31    0x0456
#define DIGLDO_CON32    0x0458
#define DIGLDO_CON33    0x045A
#define DIGLDO_CON34    0x045C
#define DIGLDO_CON35    0x045E
#define DIGLDO_CON36    0x0460
#define DIGLDO_CON37    0x0462
#define DIGLDO_CON38    0x0464
#define DIGLDO_CON39    0x0466
#define DIGLDO_CON40    0x0468
#define DIGLDO_CON41    0x046A
#define DIGLDO_CON42    0x046C
#define DIGLDO_CON43    0x046E
#define DIGLDO_CON44    0x0470
#define STRUP_CON0      0x0500
#define STRUP_CON2      0x0502
#define STRUP_CON3      0x0504
#define STRUP_CON4      0x0506
#define STRUP_CON5      0x0508
#define STRUP_CON6      0x050A
#define STRUP_CON7      0x050C
#define STRUP_CON8      0x050E
#define STRUP_CON9      0x0510
#define AUXADC_ADC0     0x0512
#define AUXADC_ADC1     0x0514
#define AUXADC_ADC2     0x0516
#define AUXADC_ADC3     0x0518
#define AUXADC_ADC4     0x051A
#define AUXADC_ADC5     0x051C
#define AUXADC_ADC6     0x051E
#define AUXADC_ADC7     0x0520
#define AUXADC_ADC8     0x0522
#define AUXADC_ADC9     0x0524
#define AUXADC_ADC10    0x0526
#define AUXADC_ADC11    0x0528
#define AUXADC_ADC12    0x052A
#define AUXADC_ADC13    0x052C
#define AUXADC_ADC14    0x052E
#define AUXADC_ADC15    0x0530
#define AUXADC_ADC16    0x0532
#define AUXADC_ADC17    0x0534
#define AUXADC_ADC18    0x0536
#define AUXADC_ADC19    0x0538
#define AUXADC_ADC20    0x053A
#define AUXADC_ADC21    0x053C
#define AUXADC_ADC22    0x053E
#define AUXADC_CON0     0x0540
#define AUXADC_CON1     0x0542
#define AUXADC_CON2     0x0544
#define AUXADC_CON3     0x0546
#define AUXADC_CON4     0x0548
#define AUXADC_CON5     0x054A
#define AUXADC_CON6     0x054C
#define AUXADC_CON7     0x054E
#define AUXADC_CON8     0x0550
#define AUXADC_CON9     0x0552
#define AUXADC_CON10    0x0554
#define AUXADC_CON11    0x0556
#define AUXADC_CON12    0x0558
#define AUXADC_CON13    0x055A
#define AUXADC_CON14    0x055C
#define FLASH_CON0      0x055E
#define FLASH_CON1      0x0560
#define FLASH_CON2      0x0562
#define KPLED_CON0      0x0564
#define KPLED_CON1      0x0566
#define KPLED_CON2      0x0568
#define ISINKS_CON0     0x056A
#define ISINKS_CON1     0x056C
#define ISINKS_CON2     0x056E
#define ISINKS_CON3     0x0570
#define ISINKS_CON4     0x0572
#define ISINKS_CON5     0x0574
#define ISINKS_CON6     0x0576
#define ISINKS_CON7     0x0578
#define ISINKS_CON8     0x057A
#define ISINKS_CON9     0x057C
#define ISINKS_CON10    0x057E
#define ISINKS_CON11    0x0580
#define ACCDET_CON0     0x0582
#define ACCDET_CON1     0x0584
#define ACCDET_CON2     0x0586
#define ACCDET_CON3     0x0588
#define ACCDET_CON4     0x058A
#define ACCDET_CON5     0x058C
#define ACCDET_CON6     0x058E
#define ACCDET_CON7     0x0590
#define ACCDET_CON8     0x0592
#define ACCDET_CON9     0x0594
#define ACCDET_CON10    0x0596
#define ACCDET_CON11    0x0598
#define ACCDET_CON12    0x059A
#define ACCDET_CON13    0x059C
#define ACCDET_CON14    0x059E
#define ACCDET_CON15    0x05A0
#define ACCDET_CON16    0x05A2
#define SPK_CON0        0x0600
#define SPK_CON1        0x0602
#define SPK_CON2        0x0604
#define SPK_CON3        0x0606
#define SPK_CON4        0x0608
#define SPK_CON5        0x060A
#define SPK_CON6        0x060C
#define SPK_CON7        0x060E
#define SPK_CON8        0x0610
#define SPK_CON9        0x0612
#define SPK_CON10       0x0614
#define SPK_CON11       0x0616
#define FGADC_CON0      0x0618
#define FGADC_CON1      0x061A
#define FGADC_CON2      0x061C
#define FGADC_CON3      0x061E
#define FGADC_CON4      0x0620
#define FGADC_CON5      0x0622
#define FGADC_CON6      0x0624
#define FGADC_CON7      0x0626
#define FGADC_CON8      0x0628
#define FGADC_CON9      0x062A
#define FGADC_CON10     0x062C
#define FGADC_CON11     0x062E
#define FGADC_CON12     0x0630
#define FGADC_CON13     0x0632
#define FGADC_CON14     0x0634
#define FGADC_CON15     0x0636
#define FGADC_CON16     0x0638
#define FGADC_CON17     0x063A
#define FGADC_CON18     0x063C
#define FGADC_CON19     0x063E
#define RTC_MIX_CON0    0x0640
#define RTC_MIX_CON1    0x0642
#define AUDDAC_CON0     0x0700
#define AUDBUF_CFG0     0x0702
#define AUDBUF_CFG1     0x0704
#define AUDBUF_CFG2     0x0706
#define AUDBUF_CFG3     0x0708
#define AUDBUF_CFG4     0x070A
#define IBIASDIST_CFG0  0x070C
#define AUDACCDEPOP_CFG0 0x070E
#define AUD_IV_CFG0     0x0710
#define AUDCLKGEN_CFG0  0x0712
#define AUDLDO_CFG0     0x0714
#define AUDLDO_CFG1     0x0716
#define AUDNVREGGLB_CFG0 0x0718
#define AUD_NCP0        0x071A
#define AUDPREAMP_CON0  0x071C
#define AUDADC_CON0     0x071E
#define AUDADC_CON1     0x0720
#define AUDADC_CON2     0x0722
#define AUDADC_CON3     0x0724
#define AUDADC_CON4     0x0726
#define AUDADC_CON5     0x0728
#define AUDADC_CON6     0x072A
#define AUDDIGMI_CON0   0x072C
#define AUDLSBUF_CON0   0x072E
#define AUDLSBUF_CON1   0x0730
#define AUDENCSPARE_CON0 0x0732
#define AUDENCCLKSQ_CON0 0x0734
#define AUDPREAMPGAIN_CON0 0x0736
#define ZCD_CON0        0x0738
#define ZCD_CON1        0x073A
#define ZCD_CON2        0x073C
#define ZCD_CON3        0x073E
#define ZCD_CON4        0x0740
#define ZCD_CON5        0x0742
#define NCP_CLKDIV_CON0 0x0744
#define NCP_CLKDIV_CON1 0x0746

//mask is HEX
//shift is Integer
#define STATUS_VSIM1_EN_MASK 0x1
#define STATUS_VSIM1_EN_SHIFT 12
#define STATUS_VSIM2_EN_MASK 0x1
#define STATUS_VSIM2_EN_SHIFT 11
#define OC_STATUS_VSIM1_MASK 0x1
#define OC_STATUS_VSIM1_SHIFT 12
#define OC_STATUS_VSIM2_MASK 0x1
#define OC_STATUS_VSIM2_SHIFT 11
#define RG_SIMLS2_SRST_CONF_MASK 0xF
#define RG_SIMLS2_SRST_CONF_SHIFT 12
#define RG_SIMLS2_SCLK_CONF_MASK 0xF
#define RG_SIMLS2_SCLK_CONF_SHIFT 8
#define RG_SIMLS1_SRST_CONF_MASK 0xF
#define RG_SIMLS1_SRST_CONF_SHIFT 4
#define RG_SIMLS1_SCLK_CONF_MASK 0xF
#define RG_SIMLS1_SCLK_CONF_SHIFT 0
#define RG_SIMLS_TDSEL_MASK 0x3
#define RG_SIMLS_TDSEL_SHIFT 7
#define RG_SIMAP_TDSEL_MASK 0x1
#define RG_SIMAP_TDSEL_SHIFT 0
#define RG_SIMLS_RDSEL_MASK 0x3
#define RG_SIMLS_RDSEL_SHIFT 7
#define RG_SIMAP_RDSEL_MASK 0x1
#define RG_SIMAP_RDSEL_SHIFT 0
#define RG_OCTL_SIM1_AP_SRST_MASK 0xF
#define RG_OCTL_SIM1_AP_SRST_SHIFT 12
#define RG_OCTL_SIM1_AP_SCLK_MASK 0xF
#define RG_OCTL_SIM1_AP_SCLK_SHIFT 8
#define RG_OCTL_SIMLS1_SRST_MASK 0xF
#define RG_OCTL_SIMLS1_SRST_SHIFT 12
#define RG_OCTL_SIMLS1_SCLK_MASK 0xF
#define RG_OCTL_SIMLS1_SCLK_SHIFT 8
#define RG_OCTL_SIM2_AP_SRST_MASK 0xF
#define RG_OCTL_SIM2_AP_SRST_SHIFT 4
#define RG_OCTL_SIM2_AP_SCLK_MASK 0xF
#define RG_OCTL_SIM2_AP_SCLK_SHIFT 0
#define RG_OCTL_SIMLS2_SRST_MASK 0xF
#define RG_OCTL_SIMLS2_SRST_SHIFT 4
#define RG_OCTL_SIMLS2_SCLK_MASK 0xF
#define RG_OCTL_SIMLS2_SCLK_SHIFT 0
#define RG_VIO18_MODESET_MASK 0x1
#define RG_VIO18_MODESET_SHIFT 8
#define RG_VPA_MODESET_MASK 0x1
#define RG_VPA_MODESET_SHIFT 8
#define VPA_EN_MASK 0x1
#define VPA_EN_SHIFT 0
#define RG_VRF18_MODESET_MASK 0x1
#define RG_VRF18_MODESET_SHIFT 8
#define RG_VRF18_BK_LDO_MASK 0x1
#define RG_VRF18_BK_LDO_SHIFT 1
#define VRF18_EN_CTRL_MASK 0x1
#define VRF18_EN_CTRL_SHIFT 0
#define VRF18_EN_MASK 0x1
#define VRF18_EN_SHIFT 0
#define RG_VRF18_2_MODESET_MASK 0x1
#define RG_VRF18_2_MODESET_SHIFT 8
#define RG_VRF18_2_BK_LDO_MASK 0x1
#define RG_VRF18_2_BK_LDO_SHIFT 1
#define VRF18_2_EN_CTRL_MASK 0x1
#define VRF18_2_EN_CTRL_SHIFT 0
#define VRF18_2_EN_SEL_MASK 0x7
#define VRF18_2_EN_SEL_SHIFT 0
#define VRF18_2_EN_MASK 0x1
#define VRF18_2_EN_SHIFT 0
#define VRF28_ON_CTRL_MASK 0x1
#define VRF28_ON_CTRL_SHIFT 14
#define RG_VRF28_EN_MASK 0x1
#define RG_VRF28_EN_SHIFT 12
#define VRF28_SRCLK_EN_SEL_MASK 0x7
#define VRF28_SRCLK_EN_SEL_SHIFT 4
#define VRF28_ON_2_CTRL_MASK 0x1
#define VRF28_ON_2_CTRL_SHIFT 14
#define RG_VRF28_2_EN_MASK 0x1
#define RG_VRF28_2_EN_SHIFT 12
#define VRF28_2_SRCLK_EN_SEL_MASK 0x7
#define VRF28_2_SRCLK_EN_SEL_SHIFT 4
#define RG_VSIM1_EN_MASK 0x1
#define RG_VSIM1_EN_SHIFT 15
#define RG_VSIM1_STBTD_MASK 0x3
#define RG_VSIM1_STBTD_SHIFT 12
#define QI_VSIM1_MODE_MASK 0x1
#define QI_VSIM1_MODE_SHIFT 7
#define VSIM1_SRCLK_MODE_SEL_MASK 0x7
#define VSIM1_SRCLK_MODE_SEL_SHIFT 4
#define VSIM1_LP_MODE_SET_MASK 0x1
#define VSIM1_LP_MODE_SET_SHIFT 1
#define VSIM1_LP_SEL_MASK 0x1
#define VSIM1_LP_SEL_SHIFT 0
#define RG_VSIM2_EN_MASK 0x1
#define RG_VSIM2_EN_SHIFT 15
#define RG_VSIM2_STBTD_MASK 0x3
#define RG_VSIM2_STBTD_SHIFT 12
#define QI_VSIM2_MODE_MASK 0x1
#define QI_VSIM2_MODE_SHIFT 7
#define VSIM2_SRCLK_MODE_SEL_MASK 0x7
#define VSIM2_SRCLK_MODE_SEL_SHIFT 4
#define VSIM2_THER_SHDN_EN_MASK 0x1
#define VSIM2_THER_SHDN_EN_SHIFT 2
#define VSIM2_LP_MODE_SET_MASK 0x1
#define VSIM2_LP_MODE_SET_SHIFT 1
#define VSIM2_LP_SEL_MASK 0x1
#define VSIM2_LP_SEL_SHIFT 0
#define QI_VSIM1_OC_STATUS_MASK 0x1
#define QI_VSIM1_OC_STATUS_SHIFT 3
#define QI_VSIM2_OC_STATUS_MASK 0x1
#define QI_VSIM2_OC_STATUS_SHIFT 2
#define RG_VSIM1_CAL_MASK 0xF
#define RG_VSIM1_CAL_SHIFT 8
#define RG_VSIM1_VOSEL_MASK 0x7
#define RG_VSIM1_VOSEL_SHIFT 5
#define RG_VSIM1_STB_SEL_MASK 0x1
#define RG_VSIM1_STB_SEL_SHIFT 4
#define RG_VSIM1_OCFB_MASK 0x1
#define RG_VSIM1_OCFB_SHIFT 2
#define RG_VSIM1_NDIS_EN_MASK 0x1
#define RG_VSIM1_NDIS_EN_SHIFT 0
#define RG_VSIM2_CAL_MASK 0xF
#define RG_VSIM2_CAL_SHIFT 8
#define RG_VSIM2_VOSEL_MASK 0x7
#define RG_VSIM2_VOSEL_SHIFT 5
#define RG_VSIM2_STB_SEL_MASK 0x1
#define RG_VSIM2_STB_SEL_SHIFT 4
#define RG_VSIM2_OCFB_MASK 0x1
#define RG_VSIM2_OCFB_SHIFT 2
#define RG_VSIM2_NDIS_EN_MASK 0x1
#define RG_VSIM2_NDIS_EN_SHIFT 0
#define VSIM1_ON_CTRL_MASK 0x1
#define VSIM1_ON_CTRL_SHIFT 9
#define VSIM2_ON_CTRL_MASK 0x1
#define VSIM2_ON_CTRL_SHIFT 8

/* =================================================================*/

#define DEW_EVENT_OUT_EN  	      (DEW_BASE+0x0)
#define DEW_DIO_EN        	      (DEW_BASE+0x2)
#define DEW_EVENT_SRC_EN  	      (DEW_BASE+0x4)
#define DEW_EVENT_SRC     	      (DEW_BASE+0x6)
#define DEW_EVENT_FLAG    	      (DEW_BASE+0x8)
#define DEW_READ_TEST     	      (DEW_BASE+0xA)
#define DEW_WRITE_TEST    	      (DEW_BASE+0xC)
#define DEW_CRC_EN        	      (DEW_BASE+0xE)
#define DEW_CRC_VAL       	      (DEW_BASE+0x10)
#define DEW_MON_GRP_SEL   	      (DEW_BASE+0x12)
#define DEW_MON_FLAG_SEL  	      (DEW_BASE+0x14)
#define DEW_EVENT_TEST    	      (DEW_BASE+0x16)
#define DEW_CIPHER_KEY_SEL	      (DEW_BASE+0x18)
#define DEW_CIPHER_IV_SEL 	      (DEW_BASE+0x1A)
#define DEW_CIPHER_LOAD   	      (DEW_BASE+0x1C)
#define DEW_CIPHER_START  	      (DEW_BASE+0x1E)
#define DEW_CIPHER_RDY    	      (DEW_BASE+0x20)
#define DEW_CIPHER_MODE   	      (DEW_BASE+0x22)
#define DEW_CIPHER_SWRST  	      (DEW_BASE+0x24)
#define DEW_CIPHER_IV0    	      (DEW_BASE+0x26)
#define DEW_CIPHER_IV1    	      (DEW_BASE+0x28)
#define DEW_CIPHER_IV2    	      (DEW_BASE+0x2A)
#define DEW_CIPHER_IV3    	      (DEW_BASE+0x2C)
#define DEW_CIPHER_IV4    	      (DEW_BASE+0x2E)
#define DEW_CIPHER_IV5    	      (DEW_BASE+0x30)

#endif // #ifdef PMIC_6320_REG_API
#endif // #ifndef __DCL_PMIC6320_HW_H_STRUCT__

