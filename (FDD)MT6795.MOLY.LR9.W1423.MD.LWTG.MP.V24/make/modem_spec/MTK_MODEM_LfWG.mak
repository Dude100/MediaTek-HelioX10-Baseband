#
#  Copyright Statement:
#  ---------------------------
#  This software/firmware and related documentation ("MediaTek Software") are
#  protected under relevant copyright laws. The information contained herein 
#  is confidential and proprietary to MediaTek Inc. and/or its licensors.  
#  Without the prior written permission of MediaTek inc. and/or its licensors,
#  any reproduction,modification, use or disclosure of MediaTek Software, and
#  information contained herein, in whole or in part, shall be strictly prohibited.
#   
#  MediaTek Inc.(C)2011.All rights reserved.
#
#  BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND
#  AGREES THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK 
#  SOFTWARE") RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED 
#  TO RECEIVER ON AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL 
#  WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED 
#  WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR 
#  NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER 
#  WITH RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, 
#  INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER 
#  AGREES TO LOOK ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING 
#  THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES THAT IT IS RECEIVER'S SOLE 
#  RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES 
#  CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR 
#  ANY MEDIATEK SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO 
#  CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND 
#  EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE LIABILITY WITH RESPECT 
#  TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,AT MEDIATEK'S OPTION, 
#  TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,OR REFUND ANY SOFTWARE 
#  LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO MEDIATEK FOR SUCH MEDIATEK 
#  SOFTWARE AT ISSUE. 
#
# *************************************************************************

# Generated at 2012-11-29 14:23:02
# ------------------------------ Modem specification
GERAN_MODE_SUPPORT = GERAN_EGPRS_MODE
  # Description:
  #   2G modem capability
  # Option Values:
  #   GERAN_GSM_MODE: Support GSM only
  #   GERAN_GPRS_MODE: Support GPRS
  #   GERAN_EGPRS_MODE: Support EGPRS
  #   NONE: NONE
  # Switch-ability:
  #   Non-switchable

R4_SUPPORT = TRUE
  # Description:
  #   R4 and R5 protocol features,maily NACC and ExtULTBF for cusotmers
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   Non-switchable

R5_SUPPORT = TRUE
  # Description:
  #   R4 and R5 protocol features,maily NACC and ExtULTBF for cusotmers
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   Non-switchable

R99_SUPPORT = TRUE
  # Description:
  #   to enable R99 features to be R99 capable MS.
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   Non-switchable

L1_GPRS = TRUE
  # Description:
  #   Turn on the GPRS support of Layer 1
  #   This is used for internal test
  # Option Values:
  #   TRUE: GPRS enable
  #   FALSE: GPRS disable
  # Switch-ability:
  #   Non-switchable

L1_EGPRS = TRUE
  # Description:
  #   this compile option is only used for L1 Stand alone to turn on/off EDGE function
  # Option Values:
  #   TRUE: EGPRS enable
  #   FALSE: EGPRS disable
  # Switch-ability:
  #   Non-switchable

UTRAN_MODE_SUPPORT = UTRAN_FDD_MODE
  # Description:
  #   3G modem capability
  # Option Values:
  #   UTRAN_FDD_MODE: Support 3G FDD
  #   UTRAN_TDD128_MODE: Support 3G TDD128
  #   NONE: NONE
  # Switch-ability:
  #   Non-switchable

UMTS_MODE_SUPPORT = UMTS_FDD_MODE_SUPPORT
  # Description:
  #   The option is to switch the FDD or TDD mode for 3G modem
  # Option Values:
  #   UMTS_FDD_MODE_SUPPORT: 3G modem in FDD mode
  #   UMTS_TDD128_MODE_SUPPORT: 3G modem in TDD mode
  #   NONE: None of 3G modem mode is supported.
  # Switch-ability:
  #   Non-switchable

UMTS_RELEASE_SUPPORT = UMTS_R9_SUPPORT
  # Description:
  #   The option is to switch different version of release for 3G modem
  # Option Values:
  #   UMTS_R6_SUPPORT: 3G modem supports Rel6
  #   UMTS_R4_SUPPORT: 3G modem supports Rel4
  #   UMTS_R5_SUPPORT: 3G modem supports Rel5
  # Switch-ability:
  #   Non-switchable

HSDPA_SUPPORT = TRUE
  # Description:
  #   Define if UE supports HSDPA feature. (TRUE/FALSE)
  # Option Values:
  #   TRUE: HSDPA is support
  #   FALSE: HSDPA is not support
  # Switch-ability:
  #   Non-switchable

HSUPA_SUPPORT = TRUE
  # Description:
  #   Define if UE supports HSUPA feature. (TRUE/FALSE)
  # Option Values:
  #   TRUE: HSUPA is support
  #   FALSE: HSUPA is not support
  # Switch-ability:
  #   Non-switchable

L1_WCDMA = TRUE
  # Description:
  #   Add an option to enable WCDMA L1 support
  # Option Values:
  #   TRUE: Support UMTS L1
  #   FALSE: Not support UMTS L1
  # Switch-ability:
  #   Non-switchable

L2_HSDPA_COPRO = TRUE
  # Description:
  #   Enable using L2 HSDPA Coprocessor
  # Option Values:
  #   TRUE: Enable L2 HSDPA Copro
  #   FALSE: Disable L2 HSDPA Copro
  # Switch-ability:
  #   Non-switchable

L2_HSUPA_COPRO = TRUE
  # Description:
  #   Enable using L2 HSUPA Coprocessor
  # Option Values:
  #   TRUE: Enable L2 HSUPA Copro
  #   FALSE: Disable L2 HSUPA Copro
  # Switch-ability:
  #   Non-switchable

UL2_HSPA_PLUS_RX_COPRO = TRUE
  # Description:
  #   The option is to enable R7R8 L2 RX copro and bytecopy
  # Option Values:
  #   TRUE: enable R7R8 L2 RX copro and bytecopy
  #   FALSE: disable R7R8 L2 RX copro and bytecopy
  # Switch-ability:
  #   Non-switchable

UL2_HSPA_PLUS_TX_COPRO = TRUE
  # Description:
  #   The option is to enable R7R8 L2 TX copro
  # Option Values:
  #   TRUE: enable R7R8 L2 TX copro
  #   FALSE: disable R7R8 L2 RX copro
  # Switch-ability:
  #   Non-switchable

EUTRAN_MODE_SUPPORT = EUTRAN_MODE
  # Description:
  #   4G modem capability
  # Option Values:
  #   EUTRAN_MODE: Support EUTRAN mode
  #   NONE: NONE
  # Switch-ability:
  #   Non-switchable

LTE_RELEASE_SUPPORT = LTE_R9C0_RELEASE
  # Description:
  #   The option is to switch different asn1 version of release for TS36.331
  # Option Values:
  #   LTE_R9_RELEASE: TS 36.331 9.8.0
  #   LTE_R9C0_RELEASE: TS 36.331 9.c.0
  #   NONE: NONE
  # Switch-ability:
  #   Non-switchable

FDD_LTE_SUPPORT = TRUE
  # Description:
  #   FDD_LTE support capability
  # Option Values:
  #   TRUE: Support FDD-LTE
  #   FALSE: Do NOT support FDD-LTE
  #   NONE: NONE
  # Switch-ability:
  #   Non-switchable

TDD_LTE_SUPPORT = FALSE
  # Description:
  #   TDD_LTE support capability
  # Option Values:
  #   TRUE: Support TDD-LTE
  #   FALSE: Do NOT support TDD-LTE
  #   NONE: NONE
  # Switch-ability:
  #   Non-switchable