#!/usr/bin/perl
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2006
#
#  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
#  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
#  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
#  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
#  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
#  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
#  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
#  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
#  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
#  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
#  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
#  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
#
#  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
#  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
#  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
#  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
#  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
#
#  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
#  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
#  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
#  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
#  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
#
#*****************************************************************************
#*
#* Filename:
#* ---------
#*   emigenMD.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script will
#*       1. parse custom_MemoryDevice.h to get memory device type and part number
#*       2. read a excel file to get appropriate emi setting based on the part number
#*       3. based on the emi settings, generate custom_EMI.h if not exist
#*       4. based on the emi settings, generate custom_EMI_INFO.h if not exist
#*       5. based on the emi settings, generate custom_EMI_release.h if not exist
#*       6. based on the emi settings, generate custom_flash_norfdm5.h if not exist
#*       7. based on the emi settings, generate custom_sfi_defs.h if not exist
#*       8. based on the emi settings, generate custom_flash.h if not exist
#*       9. based on the emi settings, generate combo_flash_config.h if not exist
#*       10. based on the emi settings, generate combo_flash_id.h if not exist
#*       11. based on the emi settings, generate flash_opt_gen.h if not exist
#*
#* Author:
#* -------
#*   Guo-Huei Chang    (mtk04123)
#*   Way Chen      (mtk54483)
#*
#*============================================================================
#*             HISTORY
#* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*------------------------------------------------------------------------------
#* $Revision$
#* $Modtime$
#* $Log$
#*
#* 04 21 2014 guo-huei.chang
#* [MOLY00063203] [EMIGEN] Update EMIGEN for Smart Phone Project
#* 	Update emigen to generate EMI size for none EMI support
#*
#* 01 08 2014 guo-huei.chang
#* [MOLY00052841] [EMIGEN] Update EMIGEN for SmartPhone project
#* 	1. update emigen for smart phone to generate custom emi header
#* 	2. update custom_EMI_SP.c for smart phone
#*
#* 12 09 2013 guo-huei.chang
#* [MOLY00048000] [MT6595] Update custom_EMI for MT6595
#* Merge MT6595_E1_DEV to MOLY TRUNK
#*
#* 11 15 2013 way.chen
#* [MOLY00046608] [ROME][EMIGEN] Optimal EMIGEN Flash Code
#* Optimal EMIGEN Flash Part Code for ROME.
#*
#* 11 06 2013 guo-huei.chang
#* [MOLY00045425] [MT6595][EMIGEN] Update EMIGEN
#* update emigen for MT6595 build pass
#*
#* 10 30 2013 way.chen
#* [MOLY00044297] [MT6290][EMIGEN] Upload New MDL for MP
#* Add New MDL File for MP.
#*
#* 08 23 2013 guo-huei.chang
#* [MOLY00034592] [MT6290][Combo Memory Support] Enable Combo Memory Feature
#* 1. Update Memory Device List for MT6290(m)
#* 2. Update/re-arch cfggen
#* 3. Update/re-arch emigen
#* 4. remove emigen/cfggen legacy
#* 5. Add combo memory supporting
#* 6. auto-generate all header files that emigen related
#*
#* 05 29 2013 way.chen
#* [MOLY00024037] [MakeFile] [Config project makefile] MT6290M_LTE(MULTI_MODE_EXT_SP).mak
#* Fix EMIGEN Can not gen EMI releated files.
#*
#* 05 23 2013 way.chen
#* [MOLY00023060] [MT6290 Bring-up] Update EMIGEN Related Code
#* Modify correct NAND flash size and change emigen not care SMART_PHONE_CORE.
#*
#* 05 22 2013 guo-huei.chang
#* [MOLY00011607] update custom_EMI function and cfggen EMI part
#* change checking smart phone method without emi
#*
#* 05 02 2013 guo-huei.chang
#* [MOLY00013409] [MT6290 Bring-up] DRAMC/EMI related Code Update
#* add emigen to support combo memory
#*
#* 04 16 2013 guo-huei.chang
#* [MOLY00013409] [MT6290 Bring-up] DRAMC/EMI related Code Update
#* 1. update emigen to auto-gen all header files
#* 2. update init mempll
#* 3. update cfggen
#*
#* 03 27 2013 yaohua.liu
#* [MOLY00012498] MT6290 MOLY_NAND Integrate to Trunk
#* Merging //MOLY_CBr/yaohua.liu/MOLY_NAND/mcu/... to TRUNK
#*
#* 03 22 2013 guo-huei.chang
#* [MOLY00012511] Update Auto-k for E1
#* fix MoDIS compile error
#*
#* 03 22 2013 guo-huei.chang
#* [MOLY00012511] update auto-k for MT6290 FPGA, MT6290 EVB, and MT6290M EVB
#* 1. add custom folder for MT6290M
#* 2. update custom_EMI.h and custom_EMI_release.h with emigen
#* 3. update custom_EMI_INFO.h with manual check in
#* 4. update cfggen
#*
#* 03 19 2013 guo-huei.chang
#* [MOLY00011607] update custom_EMI function and cfggen EMI part
#* integrate CBr that update emigen and cfggen
#*
#* 02 05 2013 guo-huei.chang
#* [MOLY00009961] rename emigen from 7208 to 6290
#*
#* 11 01 2012 marvin.lin
#* [MOLY00005622] [MemoryStorage][Auto-Gen][EMI Gen/CFG Gen][Request For Design Change] EMIGEN support MT6290 on MOLY
#* .
#* 
#* 07 24 2012 marvin.lin
#* [MOLY00001098] [MemoryStorage][Auto-Gen][EMI Gen/CFG Gen][Request For Design Change] autogen support nand flash 8-bit ecc on MT6280
#* .
#*
#*
#*------------------------------------------------------------------------------
#* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*============================================================================
#****************************************************************************/
#****************************************************************************
# Included Modules
#****************************************************************************
use strict;
use warnings;
no warnings 'redefine';
use Scalar::Util qw/reftype/;
use Storable 'dclone';
#auto flush 'print' function
local $| = 1;

push @INC, "tools/perl";
require Spreadsheet::ParseExcel;
# use Spreadsheet::ParseExcel;
# die on errors...

my $EMIGEN_VERNO  = " V9.008";
                    # V9.008 , by Guo-Huei at 2014/04/15, Update EMIGEN to generate SmartPhone's DRAM Size by MDL
                    # V9.007 , by Guo-Huei at 2014/01/08, Update EMIGEN for SmartPhone project
                    # V9.006 , by Guo-Huei at 2013/12/09, Update custom_EMI for MT6595
                    # V9.005 , by Way at 2013/11/15, Optimal EMIGEN Flash Part Code for ROME.
                    # V9.004 , by Guo-Huei at 2013/11/06, update emigen for MT6595 build pass
                    # V9.003 , by Way at 2013/10/24, Support MP Level MDL
                    # V9.002 , by Guo-Huei at 2013/08/07, 1. remove lagacy code. 2. auto-generate header file according MDL content 3. Add combo memory support 4. error check for combo memory configuration.
                    # V9.001 , by Guo-Huei at 2013/08/05, 1. remove lagacy code. 2. re-arch emigen flow. 3. remove WIN32 OLE related code. 4. use warnings
                    # V8.276 , by Way at 2013/06/24, 1. remove lagacy code; 2. Re-arch EMIGEN flow; 3. Implement combo flash part auto gen flow; 4. Add combo_nfi_config.h for enhance NAND flash flow of mT6290.
                    # V8.275 , by Way at 2013/06/7, enable auto emigen flash part.
                    # V8.274 , by Way at 2013/05/23, change checking smart phone method without flash.
                    # V8.273 , by Guo-Huei at 2013/05/15, change checking smart phone method without emi.
                    # V8.272 , by Guo-Huei at 2013/05/02, add emigen to support combo memory.
                    # V8.271 , by Guo-Huei at 2013/04/12, update emigen to auto-gen custom_EMI_INFO.h
                    # V8.270 , by Guo-Huei at 2013/03/27, update emigen to support parsing flash.
                    # V8.269 , by Guo-Huei at 2013/03/22, update emigen to auto-generate emi related output files.
                    # V8.268 , by Guo-Huei at 2013/03/19, update custom_EMI function and cfggen EMI part
                    # V8.267 , by Guo-Huei at 2013/02/05, rename emigen from MT7208 to MT6290
                    # V8.266 , by Marvin  at 2012/11/01 , autogen support MT6290
                    # V8.259 , by Marvin  at 2012/07/24 , autogen support nand flash 8-bit ecc
                    # V8.258 , by Marvin  at 2012/07/05 , Autogen support MT6280
                    # V8.254 , by Marvin  at 2012/06/08 , modify open MDL method for autogen on linux
                    # V8.249 , by Marvin  at 2012/04/30 , modify combo memory hw list data structure name
                    # V8.234 , by Marvin  at 2012/01/09 , check in MT6280 DVT
                    # V8.231 , by Marvin  at 2011/12/26 , EMIGEN support MT6255 combo memory
                    # V8.229 , by Marvin  at 2011/12/06 , modify emigen bug in emigensf.pl variable makefile_options define error
                    # V8.228 , by Marvin  at 2011/12/02 , EMIGEN support MT6255 on MAUI, 11B, 11AW1112SP2, 11BW1144SP
                    # V8.226 , by Marvin  at 2011/11/17 , add emi 156Mhz setting to work around for 6256 ORFS 600KHz fail 
                    # V8.227 , by Marvin  at 2011/11/24 , to fix the sanity fail that init_eco_version corrupt the EMI region code for 6921 on 11B
                    # V8.225 , by Marvin  at 2011/11/16 , to fix the emigen error for 6252D sip serialflash 
                    # V8.224 , by Marvin  at 2011/11/10 , supprot MT6276 L1 downgrade for memory device 32 or 16 bit
                    # V8.223 , by Marvin  at 2011/11/04 , remove the card DL + combo memory flash layout
                    # V8.222 , by Marvin  at 2011/11/02 , support new version perl rule
                    # V8.221 , by Marvin  at 2011/11/01 , modify custom_emi.c to fix the build error for 6921 on 11B 
                    # V8.220 , by Marvin  at 2011/10/31 , remove check demo project policy to avoid production release load build error
                    # V8.219 , by Marvin  at 2011/10/24 , modify custom_emi.c and custom_emi.h to support combo memory for 6921 on 11B & maui
                    # V8.218 , by Marvin  at 2011/10/13, modify custom_emi.c to match 11B hal rule
                    # V8.217 , by Marvin  at 2011/10/10 , to fix emigen re-sructure error
                    # V8.216 , by Marvin  at 2011/10/07 , emi sw work-around for 6236 BT issue.
                    # V8.215 , by Marvin  at 2011/10/05 , emigen support 6256 combo memory
                    # V8.214 , by Marvin  at 2011/09/22 , support 6252E sip serial flash size 32Mbit
                    # V8.213 , by Marvin  at 2011/09/20 , modify emi dynamicclockswitch return value
                    # V8.210 , by Marvin  at 2011/09/05 , add the dependency of the custom_featureconfig.h
                    # V8.209 , by Marvin  at 2011/09/02 , support to parse custom_featureconfig.h
                    # V8.208 , by Marvin  at 2011/08/31 , EMI GEN Re-structure and EMI GEN version update 
                    # V7.207 , by Marvin  at 2011/08/29 , to support the feature of psuedo sized block.
                    # V7.206 , by Claudia at 2011/08/15 , Modify SP custom_EMI_release.h EMI_EXTSRAM_SIZE template to sync with feature phones
                    # V7.205 , by Marvin at  2011/08/08 , modify custom_emi.c for supporting WQVGA of 6252
                    # V7.204 , by Marvin at  2011/08/01 , modify the custom_flash.c for FOTA + Card DL + combo memory feature support
                    # V7.203 , by Marvin at  2011/07/15 , modify the custom_flash.c for NOR FDM slim
                    # V7.202 , by Marvin at  2011/07/13 , modify the custom_sfi.c to fix build error for compile option UBL
                    # V7.201 , by Claudia at 2011/07/11 , Fix Combo Memory error for error-detecting EMMC_BOOTING
                    # V7.200 , by Marvin at  2011/07/11 , modify the FS address for FOTA backup storage
                    # V7.199 , by Marvin at  2011/07/11 , Modify custom_EMI.c to fix build error for compile option EMMC_BOOTING
                    # V7.198 , by Claudia at 2011/07/08 , Modify custom_EMI.c to fix build error when _EMI_NOR_CMD_NUM is 0
                    # V7.197 , by Claudia at 2011/07/08 , Remove __NOR_FULL_DRIVER__ option for BL re-structure
                    # V7.196 , by Claudia at 2011/07/07 , Support Combo Memory on all platforms
                    # V7.184 , by Claudia at 2011/05/17 , Support MT6921 Auto-Gen
                    # V7.183 , by Claudia at 2011/05/16 , Correct MT6236 DRAM init flow
                    # V7.150 , by Claudia at 2011/03/04 , To support Card DL
                    # V7.159 , by Claudia at 2011/02/21 , Modify custom_EMI.c template to fix MT6235E5 DCM conflict with sw-workaround issue
                    # V7.149 , by Claudia at 2011/01/21 , To generate the entire NOR flash geometry for SDS (Secure Data Storage) feature
                    # V7.195 , by Marvin  at 2011/07/06 , modify custom_flash.c template for bootloader re-organize
                    # V7.194 , by Marvin  at 2011/06/15 , modify custom_flash.c
                    # V7.193 , by Marvin  at 2011/06/15 , add pid to copy MDL file name, flash_opt.h template
                    # V7.192 , by Marvin  at 2011/06/14 , add output file owner name for BM to find correct file owner quickly
                    # V7.191 , by Marvin  at 2011/06/13 , Modify custom_SFI.c to remove include pwic.h to fix build error
                    # V7.190 , by Claudia at 2011/05/30 , Modify custom_EMI_release.h to include kal_general_types.h to fix build error
                    # V7.189 , by Claudia at 2011/05/30 , Support MT6252D SIP_SERIAL_FLASH_SIZE selection
                    # V7.188 , by Claudia at 2011/05/29 , Modify MT6276 custom_EMI.c for data training result and fix auto-tracking coding error
                    # V7.187 , by Claudia at 2011/05/29 , Remove 64Mb serial flash upper limit for MT6252 and MT6251
                    # V7.186 , by Claudia at 2011/05/26 , Modify custom_EMI.c to fix build error for EMMC_BOOTING
                    # V7.185 , by Claudia at 2011/05/26 , Modify custom_flash.c to fix build warnings
                    # V7.182 , by Claudia at 2011/05/13 , Modify custom_flash.c and flash_opt.h templates and add EMMC_BOOTING options to support eMMC Booting
                    # V7.181 , by Claudia at 2011/05/11 , Modify custom_EMI.c, custom_SFI.c, combo_sfi_config.h, and combo_sfi_defs.h templates to support MT6252 porting IC;  Modify MDL version from 10AW1108MP to 10AW1124MP
                    # V7.180 , by Claudia at 2011/05/10 , Modify MT6252 custom_EMI.c to correct pragma wrapping
                    # V7.179 , by Claudia at 2011/05/05 , Retrieve MTKSIP information from internal MDL as well, and skip internal MDL operation for customer release
                    # V7.178 , by Claudia at 2011/04/22 , Support EMI Gen for MT6573 (and future smart phone projects)
                    # V7.177 , by Claudia at 2011/04/18 , Support MT6276M MDL split with MT6276
                    # V7.176 , by Claudia at 2011/04/16 , Support MT6252 SIP PSRAM selection by makefile option SIP_RAM_SIZE
                    # V7.175 , by Claudia at 2011/04/11 , Auto-select highest EMI clock by available EMI settings in MDL on MT6276 when EMI_CLK is set as DEFAULT
                    # V7.173 , by Claudia at 2011/04/01 , Fix the issue that MDL copy will fail when load path contains '+'
                    # V7.172 , by Claudia at 2011/03/24 , Modify flash_opt.h template to tune FS size for SDS
                    # V7.171 , by Claudia at 2011/03/18 , Modify Lookup_SFI_setting_by_IDX_CLK_BB_REG to retrieve MT6252 SFI setting with old MDL format (with chip information in the field)
                    # V7.170 , by Claudia at 2011/03/18 , Remove dependency check for SFI files on platforms which do not support SFI
                    # V7.169 , by Claudia at 2011/03/15 , Refine MT6251 MDL to remove chip information and to move MT6251 from common internal MDL to a separate internal MDL for MT6251
                    # V7.168 , by Claudia at 2011/03/12 , Modify custom_EMI.c and custom_EMI.h template to fix MT6252 build error
                    # V7.167 , by Claudia at 2011/03/11 , Fix custom_MemoryDevice.h unable to recognize "#define option" format issue
                    # V7.166 , by Claudia at 2011/03/10 , Modify custom_EMI.c template to set EPLL by or operation to prevent DSS configurations set by BL from being overwritten
                    # V7.165 , by Claudia at 2011/03/08 , Modify custom_EMI.c and custom_EMI.h templates to rename MT6270 as MT6276M
                    # V7.164 , by Claudia at 2011/03/07 , Modify custom_SFI.c to support MT6251 Meta, and modify custom_EMI.h to fix MT6251 build error when no COMBO_MEMORY_ENTRY_COUNT is defined
                    # V7.163 , by Claudia at 2011/03/04 , Support EMI Gen for MT6276 (including Combo Memory)
                    # V7.162 , by Claudia at 2011/03/01 , Forbid MT6251 with serial flash larger than 64Mb
                    # V7.161 , by Claudia at 2011/02/25 , Change MDL to 10AW1108 and report error directly when MDL does not exist
                    # V7.160 , by Claudia at 2011/02/21 , Fix custom_SFI.c GFH declaration invalid format error
                    # V7.158 , by Claudia at 2011/02/18 , Fix incorrect EXTSRAM_SIZE issue when RAM size is larger than 128Mb in MDL
                    # V7.157 , by Claudia at 2011/02/18 , Support EMI Gen for MT6251 (including Combo Memory)
                    # V7.156 , by Claudia at 2011/02/17 , Correct MT6252 compile option and fix SFI DCM issue; correct custom_flash.c Card DL template
                    # V7.155 , by Claudia at 2011/02/15 , Change MDL to 10AW1108 version; generate entire flash to support Card DL; generate 0 instead of x to fix SFI build error; remove redundant codes; add extra checking and bug fix to support MT6252 MP
                    # V7.152 , by Claudia at 2011/02/07 , Generate flash ID under all cases to support Card DL ini gen
                    # V7.151 , by Claudia at 2011/01/27 , Allow RegionInfo to be compiled for COMBO_MEMORY_SUPPORT and SERIAL_FLASH to prevent cksydrv error
                    # V7.148 , by Claudia at 2011/01/20 , To support NOR Idle Sweep
                    # V7.147 , by Claudia at 2011/01/20 , Support Combo Memory and refine emiclean and emigen behavior in Gsm2.mak
                    # V6.146 , by Claudia at 2011/01/14 , Put emiclean control in EMI Gen script instead of Gsm2.mak and to support MANUAL-CHECKIN for custom release
                    # V6.145 , by Claudia at 2011/01/04 , Modify custom_EMI.c template to skip Enhanced SW DCM
                    # V6.144 , by Claudia at 2010/12/23 , Modify custom_EMI.c template to remove the include of pwic.h to prevent build error caused by HAL
                    # V6.143 , by Claudia at 2010/12/17 , Modfiy MT6236/MT6268 custom_EMI.c to extend delay after CAL_EN (1/5T DLL Enable)
                    # V6.142 , by Claudia at 2010/12/17 , Support RHR (Merge MAUIW1043OF_RHR to MAUI)
                    # V6.141 , by Claudia at 2010/12/10 , Support PROJECT_EXPECTED_RAM_LIMIT_NFB for NAND+DRAM projects to set RAM boundary
                    # V6.140 , by Claudia at 2010/12/10 , Remove MT6253D, and rename for chip ID
                    # V6.132 , by Claudia at 2010/12/02 , Modify custom_flash.c and flash_opt.h to add new compile options for Spansion VSR
                    # V6.129 , by Claudia at 2010/12/02 , Enhance NOR FDM 4.0 to support Spansion VSR flipping problem.
                    # V6.138 , by Claudia at 2010/11/26 , Modify custom_flash.c template to replace DWORD with kal_uint32 to prevent build error
                    # V6.137 , by Claudia at 2010/11/19 , Modify flash_opt.h template to force build error if the public drive size is not enough
                    # V6.136 , by Claudia at 2010/11/14 , Rename MT6253E/L as MT6252H/MT6252
                    # V6.135 , by Claudia at 2010/11/11 , Support EMI Gen for MT6516
                    # V6.134 , by Claudia at 2010/11/05 , Support EMI clock configurable to enable force MCP at 52MHz
                    # V6.133 , by Claudia at 2010/10/27 , Modify MT6253(D) ASYNC setting retrieval to support 52MHz-only MCP on MT6253(DV)
                    # V6.131 , by Claudia at 2010/10/18 , Modify MT6253E/L custom_EMI.c template to enable DMA soft mode grant count
                    # V6.130 , by Claudia at 2010/10/18 , Support RHR Add and add header files include on custom_EMI.c, custom_EMI.h, and custom_flash.c
                    # V6.128 , by Claudia at 2010/10/01 , Modify custom_flash.c template to add NAND init check to support X-DL for TotalBBM
                    # V6.127 , by Claudia at 2010/09/13 , Support MT6253E/L
                    # V6.126 , by Claudia at 2010/09/05 , Support Spansion VSR flash
                    # V6.125 , by Claudia at 2010/08/16 , Support MT6253DV MCP clock rate selection
                    # V6.124 , by Claudia at 2010/08/06 , Correct compile option ARM9_MMU to __ARM9_MMU__
                    # V6.122 , by Claudia at 2010/07/29 , Support MT6236(ADMUX)
                    # V6.121 , by Claudia at 2010/07/12 , Modify custom_flash.c and flash_opt.h templates to support Intel SIBLEY M18 ESB
                    # V6.120 , by Claudia at 2010/07/11 , Rename the MDL before opening it to prevent WIN32 error due to opening MDL with the same name at the same time
                    # V6.119 , by Claudia at 2010/07/09 , Modify custom_EMI_release.h template to remove #define on platforms other than MT6236(B) to prevent compile error in ADS
                    # V6.118 , by Claudia at 2010/07/07 , Modify custom_EMI.c template to include custom_EMI_release.h to prevent custom release EMI Gen error due to the opening of excel files
                    # V6.117 , by Claudia at 2010/06/18 , Modify custom_EMI.c template to include pll.h instead of init.h for init.h file split
                    # V6.116 , by Claudia at 2010/06/17 , Create dummy custom_flash_norfdm5.c and custom_EMI_release.h when NOR_FDM5 not defined and when platform is not MT6236
                    # V6.115 , by Claudia at 2010/06/17 , Modify flash_opt.h template to add __FS_PHOE_DRIVE_AVAILABLE__ options
                    # V6.114 , by Claudia at 2010/06/11 , Create custom_EMI_release.h to define memory device type compile option
                    # V6.113 , by Claudia at 2010/05/23 , Modify MT6236 DCM flow to improve power-saving
                    # V6.111 , by Claudia at 2010/04/14 , Modify flash_opt.h template to support Spansion NS_P series flash
                    # V6.110 , by Claudia at 2010/04/09 , Search for missing part numbers in the internal MDL for unsupported MCPs
                    # V6.109 , by Claudia at 2010/03/20 , Modify custom_EMI.h template for MT6253(D) RF Desense
                    # V6.108 , by Claudia at 2010/03/19 , Modify custom_flash.c template to support NOR raw disk
                    # V6.107 , by Claudia at 2010/03/17 , Modify custom_flash.c template to support totalBBM
                    # V6.106 , by Claudia at 2010/03/16 , Modify custom_flash.c and flash_opt.h template to support customized reserve block
                    # V6.105 , by Claudia at 2010/03/07 , Modify MEM Info EMI setting retrieval to get the setting by the EMI fast clock of each chip
                    # V6.104 , by Claudia at 2010/03/06 , Modify EMI Gen part number comparison rule to be exactly match as one single line of the Part Number field of MDL
                    # V6.103 , by Claudia at 2010/03/06 , Fix side effect of EMI Init flow change
                    # V6.102 , by Claudia at 2010/03/06 , Modify EMI Init flow to support different MCPs
                    # V6.101 , by Claudia at 2010/02/09 , Work around to tune FAT size for Toshiba MCP bad small blocks issue 
                    # V6.100 , by Claudia at 2010/01/25 , Add MEM_Info for MT6253
                    # V6.99 , by Claudia at 2010/01/23 , Support MT6236 and MT6253D Auto-Gen
                    # V6.98 , by Claudia at 2010/01/21 , Re-calculate NOR flash size and FAT base address for Toshiba MCP bad small blocks issue
                    # V6.97 , by Claudia at 2010/01/19 , Modify custom_flash.c template to allow FDM in BL
                    # V6.96 , by Claudia at 2010/01/05 , Support ARM11 Phase-in
                    # V6.95 , by Claudia at 2009/12/27 , EMI Initialization flow change on platfoms later than MT6253
                    # V6.94 , by Claudia at 2009/12/24 , Support MMAA
                    # V6.93 , by Claudia at 2009/12/20 , Add MT6253D
                    # V6.92 , by Claudia at 2009/12/01 , Modify custom_flash.c template to support NAND FDM5.0 Replace Block Count
                    # V6.91 , by Claudia at 2009/11/23 , Add NFB=BASIC case when calculating FAT offset for FOTA
                    # V6.90 , by Claudia at 2009/11/05 , Modify custom_flash.c template to avoid multi-instance compile error
                    # V6.89 , by JI at 2009/11/04 , MT6268 disable dqs enlarge feature 
                    # V6.88 , by JI at 2009/10/20 , Support MT6253 SYNC_ACCESS Pseudo RAM CRE 
                    # V6.87 , by Claudia at 2009/10/14 , Support NAND multi-instance
                    # V6.86 , by JI at 2009/08/05 , MT6235 BURST MODE Device Definition Missed Bug Fix
                    # V6.85 , by JI at 2009/08/04 , MT6253 add SAMSUNG SERIES SYNC type NOR_RAM_MCP support
                    # V6.84 , by JI at 2009/07/08 , MT6253 and INTEL_SIBLEY custom_EMI.c template
                    # V6.83 , by Claudia at 2009/06/16 , Modify MT6268 custom_EMI.c template
                    # V6.82 , by Claudia at 2009/06/05 , Retrieve MT6229/MT6230 information with platform as "MT6229 MT6230".
                    # V6.81 , by Claudia at 2009/06/05 , Modify flash_opt.h to remove NOR_BOOTING_NAND_BLOCK_SIZE and to set NAND_PARTITION_SECTORS as 0 when FOTA UPDATE_PACKAGE_ON_NAND
                    # V6.80 , by Claudia at 2009/05/27 , Modify custom_setEMI() in custom_EMI.c to forbid ultra-high requests
                    # V6.79 , by Claudia at 2009/05/22 , Modify custom_flash.c and flash_opt.h templates for FOTA Update Package on NAND
                    # V6.78 , by Claudia at 2009/05/20 , Modify DRAM initialization flow on MT6235/MT6238 to set PDN bit according to database
                    # V6.77 , by Claudia at 2009/05/19 , Modify custom_MemoryDevice.h, custom_flash.c, custom_flash_norfdm5.c, flash_opt.h, custom_fota.c to re-organize flash-related configurations
                    # V6.76 , by Claudia at 2009/05/07 , Modify DRAM initialization flow to remove power-down and auto-refresh
                    # V6.75 , by Claudia at 2009/04/08 , Remove FAT tuning for FOTA when FAT is already valid
                    # V6.74 , by Claudia at 2009/04/07 , Roll back temp solution to turn on FOTA for CMCC projects
                    # V6.73 , by Claudia at 2009/04/03 , Remove MCU Data prefetch buffer related codes on MT6268
                    # V6.72 , by Claudia at 2009/04/02 , Turn on FOTA when OPTR_SPEC is set to CMCC_0202_SEGA(_TECH) or CMCC_0202_SEGC(_TECH)
                    # V6.71 , by Claudia at 2009/03/25 , Tune FAT and Partition Sector settings automatically when FOTA is turned on
                    # V6.70 , by Claudia at 2009/03/25 , Modify EMI Gen V5 to support MT6230 for part number change
                    # V6.69 , by Claudia at 2009/03/19 , Use split_addr instead of split_emi for EMI Address and add MT6268 check for MT6268-specific registers
                    # V6.68 , by Claudia at 2009/03/16 , Support MT6223+INTEL_SIBLEY device templates
                    # V6.67 , by Claudia at 2009/03/13 , EMI Gen script Enhancement due to Device Excel data base extended for MT6253/MT6268
                    # V5.66 , by Claudia at 2009/03/06 , Add a new API custom_get_NORFLASH_Size in custom_flash.c for boot-loader
                    # V5.65 , by Claudia at 2009/01/14 , Modify FAT offset calculation when FOTA is turned on
                    # V5.64 , by Claudia at 2008/12/31 , Remove MT6205B
                    # V5.63 , by Claudia at 2008/12/30 , Remove LCSB
                    # V5.62 , by Claudia at 2008/12/25 , Remove FOTA_PROPRIETARY
                    # V5.61 , by Claudia at 2008/12/10 , Refine compile error messages.
                    # V5.60 , by Claudia at 2008/12/10 , Modify flash_opt.h template for new NOR flash devices
                    # V5.59 , by Claudia at 2008/12/02 , Modify flash_opt.h template to fix Spansion tESL and tERS issue
                    # V5.58 , by Claudia at 2008/11/14 , Add a new category in flash_opt.h for Spansion WSP
                    # V5.57 , by Claudia at 2008/10/28 , Fix NOR RDM5.0 FAT and small block judgement error
                    # V5.56 , by Claudia at 2008/10/22 , Revise MEMORY_DEVICE_TYPE and NAND_FLASH_BOOTING consistency check notification
                    # V5.55 , by Claudia at 2008/10/15 , Support FOTA+NFB Auto-Gen
                    # V5.54 , by Claudia at 2008/10/09 , Check MEMORY_DEVICE_TYPE and NAND_FLASH_BOOTING consistency in EMI Gen
                    # V5.53 , by Claudia at 2008/09/12 , Add file name and fline number information and unify all auto-gen error messages
                    # V5.52 , by Claudia at 2008/09/11 , To support ESB on MT6235
                    # V5.51 , by Claudia at 2008/08/28 , Modify custom_flash.c temlate to support FOTA on ARM9
                    # V5.50 , by Claudia at 2008/08/22 , To support FOTA on ARM9
                    # V5.49 , by Claudia at 2008/08/22 , Modify custom_EMI.c template for MT6235 NOR+PSRAM BURST MODE to remove EMI_CONE/EMI_CONF
                    # V5.48 , by Claudia at 2008/08/21 , Unify Auto-Gen error messages and modify EMI Gen part number parsing rules
                    # V5.47 , by Claudia at 2008/08/14 , Support FOTA Auto-Gen
                    # V5.46 , by Claudia at 2008/07/30 , Modify custom_EMI.c template to fix EMI_GENA and EMI_GEND issue on MT6235/MT6238 NFB
                    # V5.45 , by Claudia at 2008/07/24 , Align MT6238 info retrieval behavior with memory device database excel columns
                    # V5.44 , by Claudia at 2008/07/16 , Modify MT6235 DCM flow to fix UART data error issue
                    # V5.43 , by Claudia at 2008/07/16 , Modify custom_flash.c template for FOTA bug fix
                    # V5.42 , by Claudia at 2008/07/16 , Modify custom_flash.c template for FOTA bug fix on boot-loader
                    # V5.41 , by Claudia at 2008/07/15 , Modify custom_flash.c template for FOTA bug fix on boot-loader
                    # V5.40 , by Claudia at 2008/07/11 , Modify custom_flash.c template for FOTA
                    # V5.39 , by Claudia at 2008/07/10 , Modify custom_EMI.c template for EMI_GENA bit-clear issue
                    # V5.38 , by Claudia at 2008/06/13 , Modify custom_flash.c template to support NFB MBA
                    # V5.37 , by Claudia at 2008/06/11 , Set PARTITION_SIZE to 0 when NAND_FLASH_BOOTING and SYSTEM_DRIVE_ON_NAND are not defined
                    # V5.36 , by Claudia at 2008/06/10 , Remove page mode settings when ASYNC_ACCESS is selected
                    # V5.35 , by Claudia at 2008/06/02 , Modify custom_EMI.c template to adjust PMU output voltage by calling pmic_adpt_init() on MT6235/MT6238
                    # V5.34 , by Claudia at 2008/05/29 , Modify EMI Gen to change #if 0 patterns to comments so that they will not be removed from custom release
                    # V5.33 , by Claudia at 2008/05/23 , Modify flash_opt.h template so that when unsupported flash is used for ESB, compile error will occur
                    # V5.32 , by Claudia at 2008/05/22 , Modify DCM templates for MT6235/MT6238
                    # V5.31 , by Claudia at 2008/05/22 , Modify NOR_BLOCK_SIZE to be the largest block size in FAT
                    # V5.30 , by Claudia at 2008/05/22 , Modify MT6235 custom_setEMI template for E4
                    # V5.29 , by Claudia at 2008/05/19 , Modify MT6235/MT6238 DCM templates
                    # V5.28 , by Claudia at 2008/05/14 , Add MT6235B/MT6239 for EMI Info
                    # V5.27 , by Claudia at 2008/05/12 , Modify RegionInfo/BankInfo/BlockInfo patterh to { , } (spaces before and after , allowed)
                    # V5.26 , by Claudia at 2008/05/12 , Modify EMI Gen so that RegionInfo starts from FAT base address.
                    # V5.25 , by Claudia at 2008/04/23 , Generate part number and flash geometry information in custom_EMI.h and flash_opt.h for Scatter Gen
                    # V5.24 , by Claudia at 2008/04/02 , Erase queue size is either 5 (default) or according to user-setting
                    # V5.23 , by Claudia at 2008/03/28 , Add EMI Info for custom_EMI.c and custom_EMI.h
                    # V5.22 , by Claudia at 2008/03/24 , Fix PROJECT_EXPECTED_CODE_LIMIT errors and force erase queue size to be 3 when ALLOCATED_FAT_SPACE is set
                    # V5.21 , by Claudia at 2008/03/19 , Modify custom_flash.c template for ESB RAM shrink
                    # V5.20 , by Claudia at 2008/03/19 , FLASH_BASE_ADDRESS/ALLOCATED_FAT_SIZE should be defined when __FS_SYSDRV_ON_NAND__
                    # V5.19 , by Claudia at 2008/03/18 , region_info should align with FAT size setting by customer
                    # V5.18 , by Claudia at 2008/03/12 , Modify EMI Gen to split EMI/flash
                    # V5.17 , by Claudia at 2008/03/12 , Modify check mechanism when both EXPECTED_CODE_SIZE and EXPECTED_FAT_SIZE are set
                    # V5.16 , by Claudia at 2008/02/22 , Device Excel data base extended for MT6235/MT6238
my $DebugPrint    = 0; # 1 for debug; 0 for non-debug

my $BOOL_EMI_CLEAN            = $ARGV[0];
my $CUSTOM_MEMORY_DEVICE_HDR  = $ARGV[1];
my $THEMF                     = $ARGV[2];
my $BOOL_MD_INFO              = $ARGV[3];
my $INSIDE_MTK                = $ARGV[4];
my $LOAD_TMP_PATH             = $ARGV[5];
my $CUSTOM_FEATURE_CONFIG_HDR = $CUSTOM_MEMORY_DEVICE_HDR;
$CUSTOM_FEATURE_CONFIG_HDR =~ s/custom_MemoryDevice/custom_FeatureConfig/;


# to align error message file name format
$CUSTOM_MEMORY_DEVICE_HDR =~ s/^.\\|^\\//;
$THEMF                    =~ s/^.\\|^\\//;
#print "$BOOL_EMI_CLEAN  $CUSTOM_MEMORY_DEVICE_HDR  $THEMF\n";
# the following parameters come from $CUSTOM_MEMORY_DEVICE_HDR
my %PART_NUMBER;
my $MEMORY_DEVICE_TYPE;
my $EMI_CLK;
my $emi_clk_config;
my $SFI_CLK;
my $sfi_clk_config;
my $NOR_FLASH_BASE_ADDRESS_VAL;
my $NOR_ALLOCATED_FAT_SPACE_VAL;
my $LPSDRAM_CHIP_SELECT = 0xFF;
my $PROJECT_EXPECTED_RAM_LIMIT;
my $PROJECT_EXPECTED_CODE_LIMIT;
my $PROJECT_EXPECTED_RAM_LIMIT_NFB;
my $SNOR_ERASE_QUEUE_SIZE;
my $NOR_SYSTEM_DRIVE_RESERVED_BLOCK;
my $emi_is_existed = 1;
my %MEM_DEV_LIST_INDEX;
my @MCP_LIST;  # list of PART_NUMBER hash references
my @MDL_INFO_LIST;  # list of MEM_DEV_LIST_INFO has references
my %COMM_MDL_INFO;  # common MDL info, obtained from MDL_INFO_LIST.
my @REGION_INFO_LIST;  # extracted list of Region Info of all memory devices
my @BANK_INFO_LIST;  # extracted list of Bank Info of all memory devices
my @BLOCK_INFO_LIST;  # extracted list of Block Info of all memory devices
my %MAKEFILE_OPTIONS; #list of makefile option
my %CUSTOM_MEM_DEV_OPTIONS;  #list of custom_memory_device option
my $MEMORY_DEVICE_LIST_XLS;  #CORRECT MDL FILE 
my $MEMORY_DEVICE_LIST_INT_XLS; #INTERNAL MDL FILE
my $MEMORY_DEVICE_LIST_XLS_E;
my $nor_block_size;
my %CUSTOM_FEATURE_CFG_OPTIONS;
my $OS_ENV = $^O;

# locations of output EMI settings
my $CUSTOM_EMI_H           = $CUSTOM_MEMORY_DEVICE_HDR;
my $CUSTOM_EMI_INFO_H      = $CUSTOM_MEMORY_DEVICE_HDR;
my $CUSTOM_EMI_RELEASE_H   = $CUSTOM_MEMORY_DEVICE_HDR;
my $CUSTOM_EMI_C           = $CUSTOM_MEMORY_DEVICE_HDR;
my $CUSTOM_SFI_H           = $CUSTOM_MEMORY_DEVICE_HDR;
my $CUSTOM_FLASH_H         = $CUSTOM_MEMORY_DEVICE_HDR;
my $FLASH_OPT_GEN_H        = $CUSTOM_MEMORY_DEVICE_HDR;
my $CUSTOM_FLASH_NORFDM5_H = $CUSTOM_MEMORY_DEVICE_HDR;
my $COMBO_FLASH_CONFIG_H   = $CUSTOM_MEMORY_DEVICE_HDR;
my $COMBO_FLASH_ID_H       = $CUSTOM_MEMORY_DEVICE_HDR;
my $COMBO_SFI_CONFIG_H     = $CUSTOM_MEMORY_DEVICE_HDR;
my $COMBO_SFI_DEFS_H       = $CUSTOM_MEMORY_DEVICE_HDR;
my $CUSTOM_SFI_CLOCK_DEFS_H       = $CUSTOM_MEMORY_DEVICE_HDR;
my $COMBO_NFI_CONFIG_H     = $CUSTOM_MEMORY_DEVICE_HDR;

print "os environment : $OS_ENV\n";

$CUSTOM_EMI_H           =~ s/\/custom_MemoryDevice\.h$/\/custom_EMI\.h/i;
$CUSTOM_EMI_INFO_H         =~ s/\/custom_MemoryDevice\.h$/\/custom_EMI_INFO\.h/i;
$CUSTOM_EMI_RELEASE_H   =~ s/\/custom_MemoryDevice\.h$/\/custom_EMI_release\.h/i;
$CUSTOM_EMI_C           =~ s/\/custom_MemoryDevice\.h$/\/custom_EMI\.c/i;
$CUSTOM_SFI_H           =~ s/\/custom_MemoryDevice\.h$/\/custom_SFI\.h/i;
$CUSTOM_FLASH_H         =~ s/\/custom_MemoryDevice\.h$/\/custom_flash\.h/i;
$FLASH_OPT_GEN_H            =~ s/\/custom_MemoryDevice\.h$/\/flash_opt_gen\.h/i;
$CUSTOM_FLASH_NORFDM5_H =~ s/\/custom_MemoryDevice\.h$/\/custom_flash_norfdm5\.h/i;
$COMBO_FLASH_CONFIG_H   =~ s/\/custom_MemoryDevice\.h$/\/combo_flash_config\.h/i;
$COMBO_FLASH_ID_H       =~ s/\/custom_MemoryDevice\.h$/\/combo_flash_id\.h/i;
$COMBO_SFI_CONFIG_H     =~ s/\/custom_MemoryDevice\.h$/\/combo_sfi_config\.h/i;
$COMBO_SFI_DEFS_H       =~ s/\/custom_MemoryDevice\.h$/\/combo_sfi_defs\.h/i;
$CUSTOM_SFI_CLOCK_DEFS_H   =~ s/\/custom_MemoryDevice\.h$/\/custom_sfi_clock\.h/i;
$COMBO_NFI_CONFIG_H =~ s/\/custom_MemoryDevice\.h$/\/combo_nfi_config\.h/i;

print "Load path:$LOAD_TMP_PATH\n";
print "custom memory device:$CUSTOM_MEMORY_DEVICE_HDR\n";
print "makefile: $THEMF\n";
print "inside_mtk : $INSIDE_MTK\n";
print "OutputFile: $CUSTOM_EMI_H, $CUSTOM_EMI_INFO_H, $CUSTOM_EMI_RELEASE_H, $CUSTOM_EMI_C, $CUSTOM_SFI_H, $CUSTOM_FLASH_H, $FLASH_OPT_GEN_H, $CUSTOM_FLASH_NORFDM5_H, $COMBO_FLASH_CONFIG_H, $COMBO_FLASH_ID_H, $COMBO_SFI_CONFIG_H, $COMBO_SFI_DEFS_H, $COMBO_NFI_CONFIG_H\n";

# output file owner
my $CUSTOM_EMI_H_OWNER           = "Guo-Huei Chang(mtk04123)";
my $CUSTOM_EMI_INFO_H_OWNER      = "Guo-Huei Chang(mtk04123)";
my $CUSTOM_EMI_RELEASE_H_OWNER   = "Guo-Huei Chang(mtk04123)";
my $CUSTOM_EMI_C_OWNER           = "Guo-Huei Chang(mtk04123)";
my $CUSTOM_SFI_H_OWNER           = "Way Chen(mtk54483)";
my $CUSTOM_FLASH_H_OWNER         = "Way Chen(mtk54483)";
my $FLASH_OPT_GEN_H_OWNER        = "Way Chen(mtk54483)";
my $CUSTOM_FLASH_NORFDM5_H_OWNER = "Way Chen(mtk54483)";
my $COMBO_FLASH_CONFIG_H_OWNER   = "Way Chen(mtk54483)";
my $COMBO_FLASH_ID_H_OWNER       = "Way Chen(mtk54483)";
my $COMBO_SFI_CONFIG_H_OWNER     = "Way Chen(mtk54483)";
my $COMBO_SFI_DEFS_H_OWNER       = "Way Chen(mtk54483)";
my $COMBO_NFI_CONFIG_H_OWNER       = "Way Chen(mtk54483)";

require "tools/emigenemi.pl";
require "tools/emigenflash.pl";
require "tools/emigenSF.pl";

#****************************************************************************
# parse makefile
#****************************************************************************
&Parse_Makefile();
#****************************************************************************
# find the correct EMI database
#****************************************************************************
&Find_MDL();

#****************************************************************************
# emiclean
#****************************************************************************
if ($BOOL_EMI_CLEAN eq 'TRUE')
{
    &Check_ManualCheckIn($CUSTOM_EMI_H, "TRUE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
    &Check_ManualCheckIn($CUSTOM_EMI_RELEASE_H, "TRUE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
    &Check_ManualCheckIn($CUSTOM_EMI_INFO_H, "TRUE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
    &Check_ManualCheckIn($CUSTOM_SFI_H, "TRUE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigen_flash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
    &Check_ManualCheckIn($CUSTOM_FLASH_H, "TRUE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
    &Check_ManualCheckIn($FLASH_OPT_GEN_H, "TRUE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
    &Check_ManualCheckIn($CUSTOM_FLASH_NORFDM5_H, "TRUE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
    &Check_ManualCheckIn($COMBO_FLASH_CONFIG_H, "TRUE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
    &Check_ManualCheckIn($COMBO_FLASH_ID_H, "TRUE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
    &Check_ManualCheckIn($COMBO_SFI_CONFIG_H, "TRUE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
    &Check_ManualCheckIn($COMBO_SFI_DEFS_H, "TRUE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
    exit;
}

#****************************************************************************
# PLATFORM EMI support matrix
#****************************************************************************
my %BBtbl_SFI_FAST_CLK = 
    (   
        'MT6290'  => 78,
    );
my %BBtbl_SFI_SLOW_CLK = 
    (   
        'MT6290'  => 13,
    );

if($BOOL_MD_INFO  eq 'TRUE')
{
    print "emigen should not enter this routine\n";
    &Parse_Memory_Device();
    &Parse_MDL(\%MAKEFILE_OPTIONS,\%CUSTOM_MEM_DEV_OPTIONS,\@MDL_INFO_LIST,\$MEMORY_DEVICE_LIST_XLS, \$MEMORY_DEVICE_LIST_INT_XLS);
    #****************************************************************************
    # check consistency among FEATURE, MEMORY_DEVICE_TYPE, PLATFORM, MCU_CLOCK and MemoryDeviceList data
    #****************************************************************************
    $sfi_clk_config = $BBtbl_SFI_FAST_CLK{$MAKEFILE_OPTIONS{'platform'}};
    &Decide_MemClockSpeed();

    #****************************************************************************
    # get common MDL information from a list of MDL information for Combo Memory
    #****************************************************************************
    &get_common_MDL_info(\@MDL_INFO_LIST, \%CUSTOM_MEM_DEV_OPTIONS, \%COMM_MDL_INFO,\%MAKEFILE_OPTIONS, $LPSDRAM_CHIP_SELECT, $CUSTOM_MEMORY_DEVICE_HDR, $emi_is_existed);
    &query_MD_INFO(\%MAKEFILE_OPTIONS,\%CUSTOM_MEM_DEV_OPTIONS,\%COMM_MDL_INFO);
    if ($DebugPrint == 1)
    {
        print "COMM_MDL_INFO: Flash Size = $COMM_MDL_INFO{0}->{'Flash Size'}, NAND Block Size(KB) = $COMM_MDL_INFO{0}->{'NAND Block Size(KB)'}, Small Block Start = $COMM_MDL_INFO{0}->{'Small Block Start'}, Default FAT Base = $COMM_MDL_INFO{0}->{'Default FAT Base'}, Default FAT Size = $COMM_MDL_INFO{0}->{'Default FAT Size'}, RAM \"Size (Mb)\" = $COMM_MDL_INFO{1}->{'Size (Mb)'}, \"CS0 ADMUX\" = $COMM_MDL_INFO{0}->{'ADMUX'}, \"CS1 ADMUX\" = $COMM_MDL_INFO{1}->{'ADMUX'}, \"DRAM\" = $COMM_MDL_INFO{1}->{'DRAM'}, \"CS0 Comm. Series\" = $COMM_MDL_INFO{0}->{'Comm. Series'}, \"CS1 Comm. Series\" = $COMM_MDL_INFO{1}->{'Comm. Series'}, \"Bank\" = $COMM_MDL_INFO{0}->{'Bank'}, \"PBP->Y / N\" = $COMM_MDL_INFO{0}->{'PBP'}->{'Y / N'}, \"PBP->Size(W)\" = $COMM_MDL_INFO{0}->{'PBP'}->{'Size(W)'}\n";
    }
    exit;
}

#****************************************************************************
# dependency check
#****************************************************************************
&Check_ManualCheckIn($CUSTOM_EMI_H, "FALSE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
&Check_ManualCheckIn($CUSTOM_EMI_RELEASE_H, "FALSE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
&Check_ManualCheckIn($CUSTOM_EMI_INFO_H, "FALSE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
&Check_ManualCheckIn($CUSTOM_SFI_H, "FALSE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigen_flash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
&Check_ManualCheckIn($CUSTOM_FLASH_H, "FALSE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
&Check_ManualCheckIn($FLASH_OPT_GEN_H, "FALSE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
&Check_ManualCheckIn($CUSTOM_FLASH_NORFDM5_H, "TRUE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
&Check_ManualCheckIn($COMBO_FLASH_CONFIG_H, "FALSE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
&Check_ManualCheckIn($COMBO_FLASH_ID_H, "FALSE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
&Check_ManualCheckIn($COMBO_SFI_CONFIG_H, "FALSE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
&Check_ManualCheckIn($COMBO_SFI_DEFS_H, "FALSE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
&Check_ManualCheckIn($CUSTOM_SFI_CLOCK_DEFS_H, "FALSE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
&Check_ManualCheckIn($COMBO_NFI_CONFIG_H, "FALSE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);

my $is_existed_h                    = (-e $CUSTOM_EMI_H)?           1 : 0;
my $is_existed_release_h            = (-e $CUSTOM_EMI_RELEASE_H)?   1 : 0;
my $is_existed_info_h               = (-e $CUSTOM_EMI_INFO_H)?      1 : 0;
my $is_existed_sfi_h                = (-e $CUSTOM_SFI_H)?           1 : 0;
my $is_existed_flash_h              = (-e $CUSTOM_FLASH_H)?         1 : 0;
my $is_existed_flash_opt_gen        = (-e $FLASH_OPT_GEN_H)?        1 : 0;
my $is_existed_flash_norfdm5        = (-e $CUSTOM_FLASH_NORFDM5_H)? 1 : 0;
my $is_existed_combo_flash_cfg_h    = (-e $COMBO_FLASH_CONFIG_H)?   1 : 0;
my $is_existed_combo_flash_id_h     = (-e $COMBO_FLASH_ID_H)?       1 : 0;
my $is_existed_combo_sfi_cfg_h      = (-e $COMBO_SFI_CONFIG_H)?     1 : 0;
my $is_existed_combo_sfi_defs_h     = (-e $COMBO_SFI_DEFS_H)?       1 : 0;
my $is_existed_combo_nfi_config_h   = (-e $COMBO_NFI_CONFIG_H)?     1 : 0;
#****************************************************************************
# Check for Serial Flash Platform file
#****************************************************************************

if($MAKEFILE_OPTIONS{'platform'} eq 'MT6290')
{
    if($MAKEFILE_OPTIONS{'serial_flash_support'} eq 'TRUE')
    {
        if ( ($is_existed_h == 1) && ($is_existed_release_h == 1) && ($is_existed_info_h == 1) && ($is_existed_sfi_h == 1) && ($is_existed_flash_h == 1) && ($is_existed_flash_opt_gen == 1) && ($is_existed_flash_norfdm5 == 1) && ($is_existed_combo_flash_cfg_h == 1) && ($is_existed_combo_flash_id_h == 1) && ($is_existed_combo_sfi_cfg_h == 1) && ($is_existed_combo_sfi_defs_h == 1) )
        {
            print "\n\nALL flash_opt\.h, custom_EMI\.h, custom_EMI_release\.h, custom_EMI\.c, custom_SFI\.h, custom_SFI\.c, custom_flash\.c, custom_flash_norfdm5\.c, combo_flash_config\.h, combo_flash_id\.h, combo_sfi_config\.h, and combo_sfi_defs\.h are existed!!!\n\n\n";
            exit;
        }
    }
    else
    {
        if ( ($is_existed_h == 1) && ($is_existed_release_h == 1) && ($is_existed_info_h == 1) && ($is_existed_flash_h == 1) && ($is_existed_flash_opt_gen == 1) && ($is_existed_flash_norfdm5 == 1) && ($is_existed_combo_flash_cfg_h == 1) && ($is_existed_combo_flash_id_h == 1) )
        {
            print "\n\nALL flash_opt_gen\.h, custom_EMI\.h, custom_EMI_release\.h, custom_EMI_INFO\.h, custom_flash\.h, combo_flash_config\.h, and combo_flash_id\.h are existed!!!\n\n\n";
            exit;
        }
    }
}

#****************************************************************************
# parse custom_MemoryDevice.h to extract MEMORY_DEVICE_TYPE & PART_NUMBER
#****************************************************************************
&Parse_Memory_Device();

#****************************************************************************
# parse custom_FeatureConfig.h to extract feature-related configurations
#****************************************************************************
&Parse_custom_FeatureConfig(\%CUSTOM_FEATURE_CFG_OPTIONS);

if ($DebugPrint == 1)
{
    print "Device Type : $CUSTOM_MEM_DEV_OPTIONS{MEMORY_DEVICE_TYPE}  , ";
    for (1..$CUSTOM_MEM_DEV_OPTIONS{COMBO_MEM_ENTRY_COUNT})
    {
        print "$_: $MCP_LIST[$_]->{0}, $MCP_LIST[$_]->{1}\n";
    }
    print "Manual Configure ( $CUSTOM_FEATURE_CFG_OPTIONS{PROJECT_EXPECTED_RAM_LIMIT} , $CUSTOM_FEATURE_CFG_OPTIONS{PROJECT_EXPECTED_CODE_LIMIT}, $CUSTOM_FEATURE_CFG_OPTIONS{PROJECT_EXPECTED_RAM_LIMIT_NFB} )\n";
}

#****************************************************************************
# Check EMI exist
#****************************************************************************
if (&config_query_no_EMI() == 1)
{
    require "tools/emiGenSP.pl";
    $emi_is_existed = 0;
}

#****************************************************************************
# parse EMI database to get EMI settings
#****************************************************************************
&Parse_MDL(\%MAKEFILE_OPTIONS,\%CUSTOM_MEM_DEV_OPTIONS,\@MDL_INFO_LIST,\$MEMORY_DEVICE_LIST_XLS, \$MEMORY_DEVICE_LIST_INT_XLS);

#****************************************************************************
# Check Combo Memory configuration validity
#****************************************************************************
my $nor_size_Mb;
&CheckConfigValid(\%MAKEFILE_OPTIONS,\%CUSTOM_MEM_DEV_OPTIONS,\@MDL_INFO_LIST,\$MEMORY_DEVICE_LIST_XLS, \$MEMORY_DEVICE_LIST_INT_XLS);

print "Flash Size is $nor_size_Mb\n" if (defined $nor_size_Mb);
my $blk_info_first;
if ($MAKEFILE_OPTIONS{'serial_flash_support'} eq 'TRUE')
{
    $blk_info_first = $MDL_INFO_LIST[1]->{1}->{'Device Geometry'}->{'Block Info.'};
}
elsif ($MAKEFILE_OPTIONS{'nand_support'} eq 'TRUE')
{
    $blk_info_first = $MDL_INFO_LIST[1]->{1}->{'NAND Block Size(KB)'};
}

if (defined $blk_info_first)
{
    $blk_info_first =~ s/\s+//g;  # remove spaces
    $blk_info_first =~ s/},/}/g;  # remove , after }
}
for (1..$CUSTOM_MEM_DEV_OPTIONS{COMBO_MEM_ENTRY_COUNT})
{
    ### NOR flash size should be the same among all devices when Combo Memory is enabled
    ### NAND flash size is not considered because we don't have to use NAND flash size information, this is not right for MT6290!
    my $cur_nor_size_Mb;
    if ($MAKEFILE_OPTIONS{'serial_flash_support'} eq 'TRUE')
    {
        $cur_nor_size_Mb = $MDL_INFO_LIST[$_]->{1}->{'Size (Mb)'};
        if (!defined $nor_size_Mb)
        {
            $nor_size_Mb = $cur_nor_size_Mb;
        }
        else
        {
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Please select flash with the same size when COMBO_MEMORY_SUPPORT is enabled!", __FILE__, __LINE__) if ($nor_size_Mb != $cur_nor_size_Mb);
        }
    }
    elsif($MAKEFILE_OPTIONS{'nand_support'} eq 'TRUE')
    {
        $cur_nor_size_Mb = $MDL_INFO_LIST[$_]->{1}->{'NAND Size(MB)'};
        if (!defined $nor_size_Mb)
        {
            $nor_size_Mb = $cur_nor_size_Mb;
        }
        else
        {
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Please select flash with the same size when COMBO_MEMORY_SUPPORT is enabled!", __FILE__, __LINE__) if ($nor_size_Mb != $cur_nor_size_Mb);
        }
    }
}
#****************************************************************************
# check consistency among FEATURE, MEMORY_DEVICE_TYPE, PLATFORM, MCU_CLOCK and MemoryDeviceList data
#****************************************************************************
$sfi_clk_config = $BBtbl_SFI_FAST_CLK{$MAKEFILE_OPTIONS{'platform'}};
&Decide_MemClockSpeed();

#****************************************************************************
# get common MDL information from a list of MDL information for Combo Memory
#****************************************************************************
&get_common_MDL_info(\@MDL_INFO_LIST, \%CUSTOM_MEM_DEV_OPTIONS, \%COMM_MDL_INFO,\%MAKEFILE_OPTIONS, $LPSDRAM_CHIP_SELECT, $CUSTOM_MEMORY_DEVICE_HDR, $emi_is_existed);
if ($DebugPrint == 1)
{
    print "COMM_MDL_INFO: Flash Size = $COMM_MDL_INFO{0}->{'Flash Size'}, NAND Block Size(KB) = $COMM_MDL_INFO{0}->{'NAND Block Size(KB)'}, Small Block Start = $COMM_MDL_INFO{0}->{'Small Block Start'}, Default FAT Base = $COMM_MDL_INFO{0}->{'Default FAT Base'}, Default FAT Size = $COMM_MDL_INFO{0}->{'Default FAT Size'}, RAM \"Size (Mb)\" = $COMM_MDL_INFO{1}->{'Size (Mb)'}, \"CS0 ADMUX\" = $COMM_MDL_INFO{0}->{'ADMUX'}, \"CS1 ADMUX\" = $COMM_MDL_INFO{1}->{'ADMUX'}, \"DRAM\" = $COMM_MDL_INFO{1}->{'DRAM'}, \"CS0 Comm. Series\" = $COMM_MDL_INFO{0}->{'Comm. Series'}, \"CS1 Comm. Series\" = $COMM_MDL_INFO{1}->{'Comm. Series'}, \"Bank\" = $COMM_MDL_INFO{0}->{'Bank'}, \"PBP->Y / N\" = $COMM_MDL_INFO{0}->{'PBP'}->{'Y / N'}, \"PBP->Size(W)\" = $COMM_MDL_INFO{0}->{'PBP'}->{'Size(W)'}\n";
}

#****************************************************************************
# PROJECT EXPECTED CONFIGURE
#****************************************************************************
my $physical_ram_density;
my $project_expected_ram_limit_common = (exists $MAKEFILE_OPTIONS{'nand_flash_booting'} and $MAKEFILE_OPTIONS{'nand_flash_booting'} ne 'NONE') ? $CUSTOM_FEATURE_CFG_OPTIONS{PROJECT_EXPECTED_RAM_LIMIT_NFB} : $CUSTOM_FEATURE_CFG_OPTIONS{PROJECT_EXPECTED_RAM_LIMIT};
if (defined $project_expected_ram_limit_common)
{
    #ensure practical
    &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Cannot configure expected RAMSIZE larger than physical RAM size!", __FILE__, __LINE__)
        if ( hex($project_expected_ram_limit_common) > ($COMM_MDL_INFO{1}->{'Size (Mb)'} * 1024 * 1024 / 8) );

    #ensure 2^n
    my $i;
    for( $i = 1 ; $i < hex($project_expected_ram_limit_common) ; $i *= 2 ){1;}
    if ( $i < ($COMM_MDL_INFO{1}->{'Size (Mb)'} * 1024 * 1024 / 8) )
    {
        $physical_ram_density = "// PHYSICAL RAM DENSITY $COMM_MDL_INFO{1}->{'Size (Mb)'} Mb\n";
        $COMM_MDL_INFO{1}->{'Size (Mb)'} = $i * 8 / ( 1024 * 1024);
    }
}
chomp $physical_ram_density if (defined $physical_ram_density);

#****************************************************************************
# get common entire geometry information for Combo Memory
#****************************************************************************
my (@entire_region_info_size_list, @entire_region_info_count_list, @entire_bank_info_size_list, @entire_bank_info_count_list);
my (@entire_block_info_start_list, @entire_block_info_size_list);
if ($MAKEFILE_OPTIONS{'serial_flash_support'} eq 'TRUE')
{
    &get_common_MDL_Geo_info(\@MDL_INFO_LIST, $CUSTOM_MEM_DEV_OPTIONS{COMBO_MEM_ENTRY_COUNT}, $CUSTOM_MEM_DEV_OPTIONS{MEMORY_DEVICE_TYPE}, 0, $COMM_MDL_INFO{0}->{'Flash Size'}, \@entire_region_info_size_list, \@entire_region_info_count_list, \@entire_bank_info_size_list, \@entire_bank_info_count_list);
    &convert_regions_to_blocks(0, \@entire_region_info_size_list, \@entire_region_info_count_list, \@entire_block_info_start_list, \@entire_block_info_size_list);

}
#NAND Flash Also need to check FAT for MT6290, we may use NAND FAT Infomation
&Calculate_FAT_Info(\%MAKEFILE_OPTIONS, \%CUSTOM_MEM_DEV_OPTIONS, \%COMM_MDL_INFO, \@MDL_INFO_LIST, \$NOR_FLASH_BASE_ADDRESS_VAL, \$NOR_ALLOCATED_FAT_SPACE_VAL, $nor_size_Mb, \%CUSTOM_FEATURE_CFG_OPTIONS, \@entire_block_info_start_list, \@entire_block_info_size_list);
#****************************************************************************
# get common FS geometry information for Combo Memory
#****************************************************************************
my (@fs_region_info_size_list, @fs_region_info_count_list, @fs_bank_info_size_list, @fs_bank_info_count_list);
my (@fs_block_info_start_list, @fs_block_info_size_list);
if ($MAKEFILE_OPTIONS{'serial_flash_support'} eq 'TRUE')
{
    &get_common_MDL_Geo_info(\@MDL_INFO_LIST, $CUSTOM_MEM_DEV_OPTIONS{COMBO_MEM_ENTRY_COUNT}, $CUSTOM_MEM_DEV_OPTIONS{MEMORY_DEVICE_TYPE}, $NOR_FLASH_BASE_ADDRESS_VAL, $NOR_FLASH_BASE_ADDRESS_VAL+$NOR_ALLOCATED_FAT_SPACE_VAL, \@fs_region_info_size_list, \@fs_region_info_count_list, \@fs_bank_info_size_list, \@fs_bank_info_count_list);
    &convert_regions_to_blocks($NOR_FLASH_BASE_ADDRESS_VAL, \@fs_region_info_size_list, \@fs_region_info_count_list, \@fs_block_info_start_list, \@fs_block_info_size_list);
    if ($DebugPrint == 1)
    {
        print "Entire RegionInfo: ";
        for (0..$#entire_region_info_size_list)
        {
            print "\{$entire_region_info_size_list[$_], $entire_region_info_count_list[$_]\}, ";
        }
        print "\nEntire BankInfo: ";
        for (0..$#entire_bank_info_size_list)
        {
            print "\{$entire_bank_info_size_list[$_], $entire_bank_info_count_list[$_]\}, ";
        }
        print "\nEntire BlockInfo: ";
        for (0..$#entire_block_info_start_list)
        {
            print "\{$entire_block_info_start_list[$_], $entire_block_info_size_list[$_]\}, ";
        }
        print "\nFS RegionInfo: ";
        for (0..$#fs_region_info_size_list)
        {
            print "\{$fs_region_info_size_list[$_], $fs_region_info_count_list[$_]\}, ";
        }
        print "\nFS BankInfo: ";
        for (0..$#fs_bank_info_size_list)
        {
            print "\{$fs_bank_info_size_list[$_], $fs_bank_info_count_list[$_]\}, ";
        }
        print "\nFS BlockInfo: ";
        for (0..$#fs_block_info_start_list)
        {
            print "\{$fs_block_info_start_list[$_], $fs_block_info_size_list[$_]\}, ";
        }
        print "\n";
    }
}

### Validate FAT and NOR Raw disk overlapping case
&Validate_FAT_NORRAWDISK_OVERLAP(\%CUSTOM_MEM_DEV_OPTIONS, \%COMM_MDL_INFO, \$NOR_FLASH_BASE_ADDRESS_VAL, \$NOR_ALLOCATED_FAT_SPACE_VAL, $CUSTOM_MEMORY_DEVICE_HDR);
### Calculate NOR Raw disk Region Info
&Calculate_NORRAWDISK_Region_Info(\%CUSTOM_MEM_DEV_OPTIONS);

### Check CODE setting validity
my $expected_code_limit;
if (defined $CUSTOM_FEATURE_CFG_OPTIONS{PROJECT_EXPECTED_CODE_LIMIT})
{
    #ensure practical
    &error_handler("$CUSTOM_FEATURE_CONFIG_HDR: Cannot configure expected CODESIZE larger than (physical NOR flash size - FAT space)!", __FILE__, __LINE__)
        if ( hex($CUSTOM_FEATURE_CFG_OPTIONS{PROJECT_EXPECTED_CODE_LIMIT}) > $NOR_FLASH_BASE_ADDRESS_VAL );
}

#****************************************************************************
# generate custom_EMI.h
#****************************************************************************
if ($is_existed_h == 0)
{
    if ($MAKEFILE_OPTIONS{'platform'} eq 'MT6290')
    {
        open (CUSTOM_EMI_H, ">$CUSTOM_EMI_H") or &error_handler("CUSTOM_EMI_H: file error!", __FILE__, __LINE__);

        print CUSTOM_EMI_H &copyright_file_header();
        print CUSTOM_EMI_H &description_file_header("custom_EMI.h",
                                              "This Module defines the EMI (external memory interface) related setting.",
                                              $CUSTOM_EMI_H_OWNER . "EMI auto generator" . $EMIGEN_VERNO);
        if ($emi_is_existed == 0) {
            print CUSTOM_EMI_H &custom_EMI_h_file_body_for_sp($MAKEFILE_OPTIONS{'platform'});
        } else {
            print CUSTOM_EMI_H &custom_EMI_h_90_file_body(\%MAKEFILE_OPTIONS,\%CUSTOM_MEM_DEV_OPTIONS,\@MDL_INFO_LIST, \%COMM_MDL_INFO, \%PART_NUMBER, $CUSTOM_MEMORY_DEVICE_HDR, $LPSDRAM_CHIP_SELECT, $emi_clk_config);
        }
        close CUSTOM_EMI_H or &error_handler("$CUSTOM_EMI_H: file error!", __FILE__, __LINE__);
    }
}

#****************************************************************************
# generate custom_EMI_INFO.h
#****************************************************************************
if ($is_existed_info_h == 0)
{
    if($MAKEFILE_OPTIONS{'platform'} eq 'MT6290')
    {
        open (CUSTOM_EMI_INFO_H, ">$CUSTOM_EMI_INFO_H") or &error_handler("CUSTOM_EMI_INFO_H: file error!", __FILE__, __LINE__);
 
        print CUSTOM_EMI_INFO_H &copyright_file_header();
        print CUSTOM_EMI_INFO_H &description_file_header("custom_EMI_INFO.h",
                                                    "This Module defines the EMI (external memory interface) related setting.",
                                                    $CUSTOM_EMI_INFO_H_OWNER . "EMI auto generator" . $EMIGEN_VERNO);
        if ($emi_is_existed == 0) {
            print CUSTOM_EMI_INFO_H &custom_EMI_info_h_file_body_for_sp($MAKEFILE_OPTIONS{'platform'});
        } else {
            print CUSTOM_EMI_INFO_H &custom_EMI_info_h_90_file_body(\%MAKEFILE_OPTIONS,\%CUSTOM_MEM_DEV_OPTIONS,\@MDL_INFO_LIST, \%COMM_MDL_INFO, \%PART_NUMBER, $CUSTOM_MEMORY_DEVICE_HDR, $LPSDRAM_CHIP_SELECT, $emi_clk_config);
        }
        close CUSTOM_EMI_INFO_H or &error_handler("$CUSTOM_EMI_INFO_H: file error!", __FILE__, __LINE__);
 
        print "\n$CUSTOM_EMI_INFO_H is generated\n";
    }
}
#****************************************************************************
# generate custom_EMI_release.h
#****************************************************************************
if ($is_existed_release_h == 0)
{
    open (CUSTOM_EMI_RELEASE_H, ">$CUSTOM_EMI_RELEASE_H") or &error_handler("CUSTOM_EMI_RELEASE_H: file error!", __FILE__, __LINE__);

    print CUSTOM_EMI_RELEASE_H &copyright_file_header();
    print CUSTOM_EMI_RELEASE_H &description_file_header("custom_EMI_release.h",
                                                "This Module defines the EMI (external memory interface) related setting.",
                                                $CUSTOM_EMI_RELEASE_H_OWNER . "EMI auto generator" . $EMIGEN_VERNO);
    if ($emi_is_existed == 0) {
        print CUSTOM_EMI_RELEASE_H &custom_EMI_release_h_file_body_for_sp(\%MAKEFILE_OPTIONS,\%CUSTOM_MEM_DEV_OPTIONS,\@MDL_INFO_LIST, \%COMM_MDL_INFO, $LPSDRAM_CHIP_SELECT, $emi_clk_config);
    } else {
        print CUSTOM_EMI_RELEASE_H &custom_EMI_release_h_90_file_body(\%MAKEFILE_OPTIONS,\%CUSTOM_MEM_DEV_OPTIONS,\@MDL_INFO_LIST, \%COMM_MDL_INFO, $LPSDRAM_CHIP_SELECT, $emi_clk_config);
    }
    close CUSTOM_EMI_RELEASE_H or &error_handler("$CUSTOM_EMI_RELEASE_H: file error!", __FILE__, __LINE__);

    print "\n$CUSTOM_EMI_RELEASE_H is generated\n";
}

#****************************************************************************
# generate flash_opt_gen.h
#****************************************************************************
if ($is_existed_flash_opt_gen == 0)
{
    open (FLASH_OPT_GEN_H, ">$FLASH_OPT_GEN_H") or &error_handler("$FLASH_OPT_GEN_H: file error!", __FILE__, __LINE__);

    print FLASH_OPT_GEN_H &copyright_file_header();
    print FLASH_OPT_GEN_H &description_file_header("flash_opt_gen.h",
                                               "NOR flash related options",
                                               $FLASH_OPT_GEN_H_OWNER . "EMI auto generator" . $EMIGEN_VERNO);
    print FLASH_OPT_GEN_H &flash_opt_gen_h_file_body(\%MAKEFILE_OPTIONS,\%CUSTOM_MEM_DEV_OPTIONS,\@MDL_INFO_LIST, \%COMM_MDL_INFO, $CUSTOM_MEMORY_DEVICE_HDR, $THEMF, \@entire_bank_info_size_list, \@entire_bank_info_count_list, \@entire_block_info_start_list, \@entire_block_info_size_list, \@entire_region_info_size_list, \@entire_region_info_count_list);
    close FLASH_OPT_GEN_H or &error_handler("$FLASH_OPT_GEN_H: file error!", __FILE__, __LINE__);

    print "\n$FLASH_OPT_GEN_H is generated\n";
}

#****************************************************************************
# generate custom_flash.h
#****************************************************************************
if ($is_existed_flash_h == 0)
{
    open (CUSTOM_FLASH_H, ">$CUSTOM_FLASH_H") or &error_handler("$CUSTOM_FLASH_H: file error!", __FILE__, __LINE__);

    print CUSTOM_FLASH_H &copyright_file_header();
    print "custom_flash.h $CUSTOM_MEMORY_DEVICE_HDR\n";
    print CUSTOM_FLASH_H &description_file_header("custom_flash.h",
                                                  "This Module defines flash related settings.",
                                                  $CUSTOM_FLASH_H_OWNER . "EMI auto generator" . $EMIGEN_VERNO);
    print CUSTOM_FLASH_H &custom_flash_h_file_body(\%MAKEFILE_OPTIONS,\%CUSTOM_MEM_DEV_OPTIONS, \@MDL_INFO_LIST, \%COMM_MDL_INFO, \@MCP_LIST, $NOR_FLASH_BASE_ADDRESS_VAL, $NOR_ALLOCATED_FAT_SPACE_VAL, $LPSDRAM_CHIP_SELECT, $CUSTOM_MEMORY_DEVICE_HDR, $nor_size_Mb, \@entire_bank_info_size_list, \@entire_bank_info_count_list, \@entire_block_info_start_list, \@entire_block_info_size_list,\@fs_region_info_size_list, \@fs_region_info_count_list, \@entire_region_info_size_list, \@entire_region_info_count_list);
    close CUSTOM_FLASH_H or &error_handler("$CUSTOM_FLASH_H: file error!", __FILE__, __LINE__);

    print "\n$CUSTOM_FLASH_H is generated\n";
}

#****************************************************************************
# generate custom_flash_norfdm5.h
#****************************************************************************
if (($is_existed_flash_norfdm5 == 0) and (defined $CUSTOM_MEM_DEV_OPTIONS{__NOR_FDM5__}))##Only __NOR_FDM5__ defined will gen custom_flash_norfdm5.h
{
    open (CUSTOM_FLASH_NORFDM5_H, ">$CUSTOM_FLASH_NORFDM5_H") or &error_handler("$CUSTOM_FLASH_NORFDM5_H: file error!", __FILE__, __LINE__);

    print CUSTOM_FLASH_NORFDM5_H &copyright_file_header();
    print CUSTOM_FLASH_NORFDM5_H &description_file_header("custom_flash_norfdm5.h",
                                                          "defines prototypes and data structure which will be used in NOR FDM 5.0",
                                                          $CUSTOM_FLASH_NORFDM5_H_OWNER . "EMI auto generator" . $EMIGEN_VERNO);
    print CUSTOM_FLASH_NORFDM5_H &custom_flash_norfdm5_h_file_body(\%MAKEFILE_OPTIONS, \%CUSTOM_MEM_DEV_OPTIONS, \@MDL_INFO_LIST, \%COMM_MDL_INFO, $NOR_FLASH_BASE_ADDRESS_VAL, $NOR_ALLOCATED_FAT_SPACE_VAL,\@entire_bank_info_size_list, \@entire_bank_info_count_list);
    close CUSTOM_FLASH_NORFDM5_H or &error_handler("$CUSTOM_FLASH_NORFDM5_H: file error!", __FILE__, __LINE__);

    print "\n$CUSTOM_FLASH_NORFDM5_H is generated\n";
}

#****************************************************************************
# generate combo_flash_config.h
#****************************************************************************
if ($is_existed_combo_flash_cfg_h == 0)
{
    open (COMBO_FLASH_CONFIG_H, ">$COMBO_FLASH_CONFIG_H") or &error_handler("$COMBO_FLASH_CONFIG_H: file error!", __FILE__, __LINE__);

    print COMBO_FLASH_CONFIG_H &copyright_file_header();
    print COMBO_FLASH_CONFIG_H &description_file_header("combo_flash_config.h",
                                                        "This Module defines the Flash configurations for Combo Memory.",
                                                        $COMBO_FLASH_CONFIG_H_OWNER . "EMI auto generator" . $EMIGEN_VERNO);
    print COMBO_FLASH_CONFIG_H &combo_flash_config_h_file_body(\%MAKEFILE_OPTIONS, \%CUSTOM_MEM_DEV_OPTIONS, \@MDL_INFO_LIST, \%COMM_MDL_INFO);
    close COMBO_FLASH_CONFIG_H or &error_handler("$COMBO_FLASH_CONFIG_H: file error!", __FILE__, __LINE__);

    print "\n$COMBO_FLASH_CONFIG_H is generated\n";
}

#****************************************************************************
# generate combo_flash_id.h
#****************************************************************************
if ($is_existed_combo_flash_id_h == 0)
{
    open (COMBO_FLASH_ID_H, ">$COMBO_FLASH_ID_H") or &error_handler("$COMBO_FLASH_ID_H: file error!", __FILE__, __LINE__);

    print COMBO_FLASH_ID_H &copyright_file_header();
    print COMBO_FLASH_ID_H &description_file_header("combo_flash_id.h",
                                                    "This Module defines the Flash ID table for Combo Memory.",
                                                    $COMBO_FLASH_ID_H_OWNER . "EMI auto generator" . $EMIGEN_VERNO);
    print COMBO_FLASH_ID_H &combo_flash_id_h_file_body(\%MAKEFILE_OPTIONS, \%CUSTOM_MEM_DEV_OPTIONS, \@MDL_INFO_LIST, \%COMM_MDL_INFO);
    close COMBO_FLASH_ID_H or &error_handler("$COMBO_FLASH_ID_H: file error!", __FILE__, __LINE__);

    print "\n$COMBO_FLASH_ID_H is generated\n";
}

if($MAKEFILE_OPTIONS{'platform'} eq'MT6290')
{
    if($MAKEFILE_OPTIONS{'nand_support'} eq 'TRUE')
    {
        #****************************************************************************
        # generate combo_nfi_config.h
        #****************************************************************************
        if ($is_existed_combo_nfi_config_h == 0)
        {
            open (COMBO_SFI_DEFS_H, ">$COMBO_NFI_CONFIG_H") or &error_handler("$COMBO_NFI_CONFIG_H: file error!", __FILE__, __LINE__);
         
            print COMBO_SFI_DEFS_H &copyright_file_header();
            print COMBO_SFI_DEFS_H &description_file_header("combo_nfi_config.h",
                                                            "gen NAND Flash Related Configuration and Table",
                                                            $COMBO_NFI_CONFIG_H_OWNER . "EMI auto generator" . $EMIGEN_VERNO);
            print COMBO_SFI_DEFS_H &combo_nfi_config_h_file_body(\%MAKEFILE_OPTIONS, \%CUSTOM_MEM_DEV_OPTIONS, \@MDL_INFO_LIST, \%COMM_MDL_INFO);
            close COMBO_SFI_DEFS_H or &error_handler("$COMBO_NFI_CONFIG_H: file error!", __FILE__, __LINE__);
        
            print "\n$COMBO_NFI_CONFIG_H is generated\n";
        }
    }

    if($MAKEFILE_OPTIONS{'serial_flash_support'} eq 'TRUE')
    {
        #****************************************************************************
        # generate combo_sfi_defs.h
        #****************************************************************************
        if ($is_existed_combo_sfi_defs_h == 0)
        {
            open (COMBO_SFI_DEFS_H, ">$COMBO_SFI_DEFS_H") or &error_handler("$COMBO_SFI_DEFS_H: file error!", __FILE__, __LINE__);
         
            print COMBO_SFI_DEFS_H &copyright_file_header();
            print COMBO_SFI_DEFS_H &description_file_header("combo_sfi_defs.h",
                                                            "defines flash ID table",
                                                            $COMBO_SFI_DEFS_H_OWNER . "EMI auto generator" . $EMIGEN_VERNO);
            print COMBO_SFI_DEFS_H &combo_sfi_defs_h_file_body(\%MAKEFILE_OPTIONS, \%CUSTOM_MEM_DEV_OPTIONS, \@MDL_INFO_LIST, \%COMM_MDL_INFO);
            close COMBO_SFI_DEFS_H or &error_handler("$COMBO_SFI_DEFS_H: file error!", __FILE__, __LINE__);
        
            print "\n$COMBO_SFI_DEFS_H is generated\n";
        }
    }
}

exit;

#****************************************************************************
# find the correct EMI database
#****************************************************************************
sub Find_MDL
{
    my $MDL_DIR = "tools/MemoryDeviceList/";
    my $platform = $MAKEFILE_OPTIONS{'platform'};
    my $ver = 0000;

    $MEMORY_DEVICE_LIST_XLS = "";
    $MEMORY_DEVICE_LIST_INT_XLS = "";

    opendir(DIR, $MDL_DIR) or die $!;

    while (my $mdl = readdir(DIR)) {
        if ($mdl =~ /MemoryDeviceList_$platform\_SinceW(\w+)\.xls/) {
            if ($1 > $ver) {
                $ver = $1;
                $MEMORY_DEVICE_LIST_XLS = $MDL_DIR . $mdl;
            }
        } elsif ($mdl =~ /MemoryDeviceList_$platform\_Internal\.xls/) {
            $MEMORY_DEVICE_LIST_INT_XLS = $MDL_DIR . $mdl;
        }
    }

    close(DIR);

    if ((! -e $MEMORY_DEVICE_LIST_XLS) && (! -e $MEMORY_DEVICE_LIST_INT_XLS)) {
            &error_handler("MDL Excel is not exist for platform '$platform':$MEMORY_DEVICE_LIST_XLS and $MEMORY_DEVICE_LIST_INT_XLS", __FILE__, __LINE__);
    }

    if ($DebugPrint == 1) {
        print "custom memory device header file:$CUSTOM_MEMORY_DEVICE_HDR\n";
        print "MDL Excel:$MEMORY_DEVICE_LIST_XLS, Internal MDL Excel:$MEMORY_DEVICE_LIST_INT_XLS\n";
        print "Makefile:$THEMF\n";
    }
}

#****************************************************************************
# parse Project Makefile
#****************************************************************************
sub Parse_Makefile
{
    my $keyname;
  
    &error_handler("$THEMF: NOT exist!", __FILE__, __LINE__) if (!-e $THEMF);

    if ($THEMF =~ /make\\(\w+)_(\w+).mak/i) {
        $MAKEFILE_OPTIONS{'MODE'} = uc($2);
    }

    open (FILE_HANDLE, "<$THEMF") or &error_handler("$THEMF: file error!", __FILE__, __LINE__);
    while (<FILE_HANDLE>) {
        if (/^(\w+)\s*=\s*(\S+)/) {
            $keyname = lc($1);
            defined($MAKEFILE_OPTIONS{$keyname}) && warn "$1 redefined in $THEMF!\n";
            $MAKEFILE_OPTIONS{$keyname} = uc($2);
            if ($DebugPrint == 1) {
               print "$1:$2\n"; 
            }
        }
    }
    close (FILE_HANDLE);
}

#****************************************************************************
# parse Memory Device
#****************************************************************************
sub Parse_Memory_Device
{
    my $cs;

    open CUSTOM_MEMORY_DEVICE_HDR, "<$CUSTOM_MEMORY_DEVICE_HDR" or &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: file error!", __FILE__, __LINE__);
    while (<CUSTOM_MEMORY_DEVICE_HDR>)
    {
        # error-checking
        if (/^#if|^#ifdef|^#ifndef|^#elif|^#else/)
        {
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Not allowed to set conditional keywords $_ in custom_MemoryDevice.h!", __FILE__, __LINE__)
            unless (/^#ifndef\s+__CUSTOM_MEMORYDEVICE__/);
        }

        if (/^#define\s+(\w+)\s+\(([\w|\-]*)\)/ || /^#define\s+(\w+)\s+([\w|\-]*)/)
        {
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: $1 redefined in custom_MemoryDevice.h!", __FILE__, __LINE__) if defined($CUSTOM_MEM_DEV_OPTIONS{$1});
            if ((!defined $2) or ($2 eq ''))
            {
                $CUSTOM_MEM_DEV_OPTIONS{$1} = 'TRUE';
            }
            else
            {
                $CUSTOM_MEM_DEV_OPTIONS{$1} = $2;
                #print "$1 => $CUSTOM_MEM_DEV_OPTIONS{$1}\n";
            }

            my $option = $1;
            my $content = $2;
            if ($option =~ /COMBO_MEM(\d+)_CS(\d+)_PART_NUMBER/)
            {
                next if ((!defined $MAKEFILE_OPTIONS{'combo_memory_support'}) or ($MAKEFILE_OPTIONS{'combo_memory_support'} eq 'FALSE'));
                &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: COMBO_MEM_ENTRY_COUNT needs to be defined when COMBO_MEMORY_SUPPORT is turned on!", __FILE__, __LINE__) if (!defined $CUSTOM_MEM_DEV_OPTIONS{COMBO_MEM_ENTRY_COUNT});
                my %TMP_PART_NUMBER;
                my $mcp_idx = $1;
                $cs = $2;
                print "LPSDRAM_CHIP_SELECT:$LPSDRAM_CHIP_SELECT, cs:$cs\n";
                $LPSDRAM_CHIP_SELECT = $cs;
                &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Only COMBO_MEM0n_CS0 or COMBO_MEM0n_CS1 is allowed!", __FILE__, __LINE__) if (($LPSDRAM_CHIP_SELECT != 0) && ($LPSDRAM_CHIP_SELECT != 1));
                $TMP_PART_NUMBER{$cs} = $content;

                if (defined $MCP_LIST[$mcp_idx])
                {
                    if (defined $MCP_LIST[$mcp_idx]->{$cs})
                    {
                        &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: COMBO_MEM$mcp_idx\_CS$cs\_PART_NUMBER multiply defined!", __FILE__, __LINE__);
                    }
                    else
                    {
                        $MCP_LIST[$mcp_idx]->{$cs} = $TMP_PART_NUMBER{$cs};
                    }
                }
                else
                {
                    $MCP_LIST[$mcp_idx] = \%TMP_PART_NUMBER;
                }
            }
            elsif ($option =~ /CS(\d+)_PART_NUMBER/)
            {
                next if ($MAKEFILE_OPTIONS{'combo_memory_support'} eq 'TRUE');  # when COMBO_MEMORY_SUPPORT is turned on, CSx_PART_NUMBER is ignored
                my $cs = $1;
                
                print "LPSDRAM_CHIP_SELECT:$LPSDRAM_CHIP_SELECT, cs:$cs\n";
                $LPSDRAM_CHIP_SELECT = $cs;
                &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Only COMBO_MEM0n_CS0 or COMBO_MEM0n_CS1 is allowed!", __FILE__, __LINE__) if (($LPSDRAM_CHIP_SELECT != 0) && ($LPSDRAM_CHIP_SELECT != 1));
                $PART_NUMBER{$cs} = $content;
            }
        }
    }

    $CUSTOM_MEM_DEV_OPTIONS{NOR_FDM4_ESB_PARAMETER_ERASE_QUEUE_SIZE}   = (defined $CUSTOM_MEM_DEV_OPTIONS{NOR_FDM4_ESB_PARAMETER_ERASE_QUEUE_SIZE}) ? $CUSTOM_MEM_DEV_OPTIONS{NOR_FDM4_ESB_PARAMETER_ERASE_QUEUE_SIZE} : 5;
    $CUSTOM_MEM_DEV_OPTIONS{NOR_PARAMETER_SYSTEM_DRIVE_RESERVED_BLOCK} = (defined $CUSTOM_MEM_DEV_OPTIONS{NOR_PARAMETER_SYSTEM_DRIVE_RESERVED_BLOCK}) ? $CUSTOM_MEM_DEV_OPTIONS{NOR_PARAMETER_SYSTEM_DRIVE_RESERVED_BLOCK} : 3;

    # No Combo MCP case
    if ($MAKEFILE_OPTIONS{'combo_memory_support'} ne 'TRUE')
    {
        $MCP_LIST[1] = \%PART_NUMBER;
        $CUSTOM_MEM_DEV_OPTIONS{COMBO_MEM_ENTRY_COUNT} = 1;
    }

    # COMBO_MEM_ENTRY_COUNT and the number of COMBO_MEMxx_CSx_PART_NUMBER does not match
    if ($CUSTOM_MEM_DEV_OPTIONS{COMBO_MEM_ENTRY_COUNT} != $#MCP_LIST)
    {
        &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: COMBO_MEM_ENTRY_COUNT and the number of COMBO_MEMxx_CSx_PART_NUMBER does not match!", __FILE__, __LINE__);
    }

    ###Check MEMORY_DEVICE_TYPE correction
    if (($CUSTOM_MEM_DEV_OPTIONS{MEMORY_DEVICE_TYPE} !~ /$MAKEFILE_OPTIONS{'ram_support_type'}/) || 
        (($MAKEFILE_OPTIONS{'ram_support_type'} =~ /DDR$/) && ($CUSTOM_MEM_DEV_OPTIONS{MEMORY_DEVICE_TYPE} =~ /DDR\d+/))) {
        &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: ram type of MEMORY_DEVICE_TYPE ($CUSTOM_MEM_DEV_OPTIONS{MEMORY_DEVICE_TYPE}) and ram_support_type ($MAKEFILE_OPTIONS{'ram_support_type'}) should be the same", __FILE__, __LINE__);
    }

    close CUSTOM_MEMORY_DEVICE_HDR;
}

#****************************************************************************
# parse EMI database to get EMI settings
#****************************************************************************
sub Parse_MDL
{
    my ($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $MEMORY_DEVICE_LIST_XLS_LOCAL, $MEMORY_DEVICE_LIST_INT_XLS_LOCAL) = @_;
    my ($result, $result0, $result1);
    my %tmp_hash;


    &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Incorrect memory device type!", __FILE__, __LINE__) unless $CUSTOM_MEM_DEV_OPTIONS{MEMORY_DEVICE_TYPE};

    ##Parse DRAM Parameters
    my $dram_info_sheet = $CUSTOM_MEM_DEV_OPTIONS{MEMORY_DEVICE_TYPE};
    if ($MAKEFILE_OPTIONS{'sip_ram_size'} ne 'NONE') {
        $dram_info_sheet = 'SIP_' . $dram_info_sheet;
    }
    if ($emi_is_existed == 1) {
        for (1..$CUSTOM_MEM_DEV_OPTIONS{COMBO_MEM_ENTRY_COUNT})
        {
            $result = &get_info($MEMORY_DEVICE_LIST_XLS, $dram_info_sheet, $MCP_LIST[$_], \%tmp_hash);
            if (($result ne 'TRUE'))
            {
                print "INTERNAL FIND part number:$MCP_LIST[$_]->{0},$MCP_LIST[$_]->{1}\n";
                $result = &get_info($MEMORY_DEVICE_LIST_INT_XLS, $dram_info_sheet, $MCP_LIST[$_], \%tmp_hash);
            }         
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Part Number $MCP_LIST[$_]->{0} not found!", __FILE__, __LINE__) if ($result ne 'TRUE');
            $MDL_INFO_LIST[$_] = dclone \%tmp_hash;
        }
    } else {
        for (1..$CUSTOM_MEM_DEV_OPTIONS{COMBO_MEM_ENTRY_COUNT})
        {
            $result = &get_info($MEMORY_DEVICE_LIST_XLS, 'RAM', $MCP_LIST[$_], \%tmp_hash);
            if (($result ne 'TRUE'))
            {
                print "INTERNAL FIND part number:$MCP_LIST[$_]->{0},$MCP_LIST[$_]->{1}\n";
                $result = &get_info($MEMORY_DEVICE_LIST_INT_XLS, 'RAM', $MCP_LIST[$_], \%tmp_hash);
            }
            &error_handler("Cannot find $MAKEFILE_OPTIONS{'platform'} in MDL!", __FILE__, __LINE__) if ($result ne 'TRUE');
            $MDL_INFO_LIST[$_] = dclone \%tmp_hash;
        }
    }

    undef %tmp_hash;
    ##Parse Flash Parameters
    ###disctete type should parse flash info sheet
    if (($CUSTOM_MEM_DEV_OPTIONS{MEMORY_DEVICE_TYPE} !~ /\w+_\w+_MCP/) && (($MAKEFILE_OPTIONS{'serial_flash_support'} eq 'TRUE') || ($MAKEFILE_OPTIONS{'nand_support'} eq 'TRUE')))
    {
        ###Parse Flash MDL info
        
        my $flash_sheet = '';
        if($MAKEFILE_OPTIONS{'serial_flash_support'} eq 'TRUE')#sheet "SERIAL_FLASH" in MDL
        {
            $flash_sheet = 'SERIAL_FLASH';
        }
        elsif($MAKEFILE_OPTIONS{'nand_support'} eq 'TRUE')
        {
            $flash_sheet = 'NAND_FLASH';
        }

        for (1..$CUSTOM_MEM_DEV_OPTIONS{COMBO_MEM_ENTRY_COUNT})
        {
            print "part number:$MCP_LIST[$_]->{0},$MCP_LIST[$_]->{1}\n";
            $result = &get_info($$MEMORY_DEVICE_LIST_XLS_LOCAL, $flash_sheet, $MCP_LIST[$_], \%tmp_hash);
            if ($result ne 'TRUE')
            {
                print "INTERNAL FIND part number:$MCP_LIST[$_]->{0},$MCP_LIST[$_]->{1}\n";
                $result = &get_info($MEMORY_DEVICE_LIST_INT_XLS, $flash_sheet, $MCP_LIST[$_], \%tmp_hash);
            }
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: $flash_sheet Part Number $MCP_LIST[$_]->{1} not found!", __FILE__, __LINE__) if ($result ne 'TRUE');
            $MDL_INFO_LIST[$_]->{1} = dclone $tmp_hash{1};
        }
    }
    for (1..$CUSTOM_MEM_DEV_OPTIONS{COMBO_MEM_ENTRY_COUNT})
    {
        &dump_mdl_info($MDL_INFO_LIST[$_], "\$MDL_INFO_LIST[$_]->");
    }

}

#****************************************************************************
# check emi clock driving config
#****************************************************************************
sub check_emi_clk_driving_cfg
{
    my ($emi_clk_driving, $bb_chip) = @_;
    if ($bb_chip eq 'MT6290')
    {
        if (($emi_clk_driving->{'DRAMC_ACTIM0_VAL'} !~ /0x[0-9a-fA-F]{8,8}/) || ($emi_clk_driving->{'DRAMC_DRVCTL0_VAL'} !~ /0x[0-9a-fA-F]{8,8}/) || ($emi_clk_driving->{'DRAMC_DRVCTL1_VAL'} !~ /0x[0-9a-fA-F]{8,8}/))
        {
            return 0;
        }
    }
    return 1;
}

#****************************************************************************
# check consistency among FEATURE, MEMORY_DEVICE_TYPE, PLATFORM, MCU_CLOCK and MemoryDeviceList data
#****************************************************************************
sub Decide_MemClockSpeed
{
    my $emi_force_clk  = 0;
    my $sfi_force_clk  = 0;
    if ((defined $CUSTOM_MEM_DEV_OPTIONS{EMI_CLK}) and $CUSTOM_MEM_DEV_OPTIONS{EMI_CLK} ne 'DEFAULT')
    {
        $emi_clk_config = $emi_force_clk = $CUSTOM_MEM_DEV_OPTIONS{EMI_CLK};
    }
    if ((defined $CUSTOM_MEM_DEV_OPTIONS{SFI_CLK}) and $CUSTOM_MEM_DEV_OPTIONS{SFI_CLK}ne 'DEFAULT')
    {
        if ($CUSTOM_MEM_DEV_OPTIONS{SFI_CLK} eq '104M')
        {
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: $MAKEFILE_OPTIONS{'platform'} does not support SFI clock as 104MHz! Please configure SFI_CLK as DEFAULT!", __FILE__, __LINE__) if ($BBtbl_SFI_FAST_CLK{$MAKEFILE_OPTIONS{'platform'}} != 104);
            $sfi_clk_config = $sfi_force_clk = 104;
        }
        elsif ($CUSTOM_MEM_DEV_OPTIONS{SFI_CLK} eq '78M')
        {
            $sfi_clk_config = $sfi_force_clk = 78;
        }
        else
        {
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Please configure SFI_CLK as 104M, 78M, or DEFAULT!", __FILE__, __LINE__);
        }
    }

    if($MAKEFILE_OPTIONS{'serial_flash_support'} eq 'TRUE')
    {
        my $sfi_104_support = 1;  # assume all devices can support 104; set as 0 if found not support
        my $sfi_78_support  = 1;  # assume all devices can support 78; set as 0 if found not support

        #print "test $CUSTOM_MEM_DEV_OPTIONS{MEMORY_DEVICE_TYPE}\n";
        ### Check if all devices can support the required clock
        if ($sfi_force_clk != 0)  # force specific clock
        {
            for (1..$CUSTOM_MEM_DEV_OPTIONS{COMBO_MEM_ENTRY_COUNT})
            {
                if ((!defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, $sfi_clk_config, $MAKEFILE_OPTIONS{'platform'}, 'SF_CTL', \@MDL_INFO_LIST)) or (&Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, $sfi_clk_config, $MAKEFILE_OPTIONS{'platform'}, 'DRIVING', \@MDL_INFO_LIST) eq 'x') or (&Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, $sfi_clk_config, $MAKEFILE_OPTIONS{'platform'}, 'DRIVING', \@MDL_INFO_LIST) eq ' '))  # unable to find the specified clock setting
                {
                    &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Device $_ not support $sfi_clk_config MHz settings!", __FILE__, __LINE__);
                }
            }
        }
        else
        {
            for (1..$CUSTOM_MEM_DEV_OPTIONS{COMBO_MEM_ENTRY_COUNT})
            {
                #if ((!defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS{'platform'}, 'SF_CTL', \@MDL_INFO_LIST)) or (&Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS{'platform'}, 'SFI_MAC_CTL', \@MDL_INFO_LIST) eq 'x') or (&Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS{'platform'}, 'SFI_MAC_CTL', \@MDL_INFO_LIST) eq ' '))  # unable to find 104MHz clock setting
                if (!defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS{'platform'}, 'SF_CTL', \@MDL_INFO_LIST))
                {
                    $sfi_104_support = 0;
                }
                #if ((!defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS{'platform'}, 'SF_CTL', \@MDL_INFO_LIST)) or (&Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS{'platform'}, 'SFI_MAC_CTL', \@MDL_INFO_LIST) eq 'x') or (&Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS{'platform'}, 'SFI_MAC_CTL', \@MDL_INFO_LIST) eq ' '))  # unable to find 104MHz clock setting
                if (!defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS{'platform'}, 'SF_CTL', \@MDL_INFO_LIST))
                {
                    $sfi_78_support = 0;
                }
                if (($sfi_104_support == 0) and ($sfi_78_support == 0))
                {
                    &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Unable to find valid SFI settings!", __FILE__, __LINE__);
                }
                elsif ($sfi_104_support != 0)
                {
                    $sfi_clk_config = 104;
                }
                else  # sfi_104_support == 0 and sfi_78_support != 0
                {
                    $sfi_clk_config = 78;
                }
            }
        }
        print "SFI_CLK configured as $sfi_clk_config\n" if ($DebugPrint == 1);
    }

    if ($emi_is_existed == 1) {
        ### Check if all devices can support the required clock
        if ($emi_force_clk != 0)  # force specific clock
        {
            for (1..$CUSTOM_MEM_DEV_OPTIONS{COMBO_MEM_ENTRY_COUNT})
            {
                my $mhz_emi_driving = $emi_clk_config . 'MHZ EMI Driving';
                my $emi_clk_driving = $MDL_INFO_LIST[$_]->{0}->{$MAKEFILE_OPTIONS{'platform'}}->{$mhz_emi_driving};
                if (&check_emi_clk_driving_cfg($emi_clk_driving, $MAKEFILE_OPTIONS{'platform'}) == 0)
                {
                    &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Device $_ not support $emi_clk_config MHz settings!", __FILE__, __LINE__);
                }
            }
        }
        else
        {
            my %emi_clk;
            for (1..$CUSTOM_MEM_DEV_OPTIONS{COMBO_MEM_ENTRY_COUNT})
            {
                my $mdl_info_platform = $MDL_INFO_LIST[$_]->{0}->{$MAKEFILE_OPTIONS{'platform'}};
                foreach my $mdl_info_content (sort keys %{$mdl_info_platform})
                {
                    if ($mdl_info_content =~ /(\d+)MHZ EMI Driving/)
                    {
                        if (!defined $emi_clk{$1})
                        {
                            $emi_clk{$1} = 'TRUE';
                        }
                        my $emi_clk_driving = $mdl_info_platform->{$mdl_info_content};
                        if (&check_emi_clk_driving_cfg($emi_clk_driving, $MAKEFILE_OPTIONS{'platform'}) == 0)
                        {
                            $emi_clk{$1} = 'FALSE';
                        }
                    }
                }
            }
            undef $emi_clk_config;
            while( (my $clk_speed, my $value) = each %emi_clk)
            {
                if ($value eq 'TRUE')
                {
                    next if ((defined $emi_clk_config) && ($emi_clk_config >= $clk_speed));
 
                    $emi_clk_config = $clk_speed;
                }
                
            }
            if (!defined $emi_clk_config) {
                &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Device $_ not support $emi_clk_config MHz settings!", __FILE__, __LINE__);
            }
        }
        print "EMI_CLK configured as $emi_clk_config\n" if ($DebugPrint == 1);
    }
}

#****************************************************************************
# subroutine:  dump_mdl_info
# return:      none
# input:       $mdl_ref:     MDL hash reference
#              $pre_string:  to print prefix string
#****************************************************************************
sub dump_mdl_info
{
    my ($mdl_ref, $pre_string) = @_;
    my $prefix_string;
    foreach my $key (keys %{$mdl_ref})
    {
        $prefix_string = $pre_string if (defined $pre_string);
        $prefix_string = $prefix_string . "{$key}";
        if (ref $mdl_ref->{$key} eq 'HASH')
        {
            &dump_mdl_info($mdl_ref->{$key}, "$prefix_string->");
        }
        else
        {
            print "$prefix_string = " . $mdl_ref->{$key} . "\n";
        }
    }
}

#****************************************************************************
# subroutine:  fs_read_excel
# return:      hash of matching rows and indexing rows
# input:       $file:        excel file to be read
#              $sheet:       sheet to open
#              $target_href: the target patterns to be searched
#****************************************************************************
sub fs_read_excel
{
    my ($file, $sheet, $target_href, $BACKUP_MDL_PATH) = @_;
    my %mdl_list;
    my $copied_file;
    my $curr_time_str = &get_CurrTime_str();
    my $WorkSheet;
    my $Excel;
    my $Book;
    my $parser;
    my $workbook;
    my ($row_min, $row_max);
    my ($col_min, $col_max);

    if (! -e $file) {
        return %mdl_list;
    }

    ### copy and rename the current excel file to prevent concurrency build problem
    # remove ^.\ or ^\
    $BACKUP_MDL_PATH =~ s/^.\\|^\\//;

    if($BACKUP_MDL_PATH =~ /build/)
    {
        print "BAKCUP_MDL_PATH match with /build/ PREMATCH:$`, MATCH:$&, POSTMATCH:$'\n";
        $BACKUP_MDL_PATH = $& . $';
    }
    print "file is $file\n";
    if($file =~ /^(\w+.*?)\.xls$/)
    {
        if($1 =~ /^(\w*.*?)tools(\w*.*?)MemoryDeviceList_(\w+)$/)
        {
            print "1:$1,2:$2,3:$3\n";
            $copied_file = $1 . $BACKUP_MDL_PATH . "\/". "MemoryDeviceList_" . $3;
        } 
    }
    $copied_file = $copied_file . "_" . $sheet . "_" . $curr_time_str . $$ . ".xls";
    if($^O eq "MSWin32")
    {
        $file =~ s/\//\\/g;
        $copied_file =~ s/\//\\/g;
        print "copy $file $copied_file\n";
        system("copy /y \"$file\" \"$copied_file\"");
    }
    else
    {
        print "cp -f $file $copied_file\n";
        system("cp -f \"$file\" \"$copied_file\"");
    }
    $file = $copied_file;

    $parser   = Spreadsheet::ParseExcel->new();
    $workbook = $parser->parse($file) or die "cannot open MDL $!\n";
    $WorkSheet = $workbook->worksheet($sheet);
    ($row_min, $row_max) = $WorkSheet->row_range();
    ($col_min, $col_max) = $WorkSheet->col_range();

    # get the sheet name
    my $name = $WorkSheet->get_name();
    print "[sheetname]: $name, row:{$row_min, $row_max}, col:{$col_min, $col_max}\n";

    my $xls_content_row_start;
    my $xls_content_num;
    for my $col ($col_min..$col_max)
    {
        my @mdl_each_col_content = undef;
        my $array_content_row_start = undef;
        foreach my $row ($row_min..$row_max)
        {
            if (($col == 0) && (!defined $WorkSheet->get_cell($row, $col)->is_merged()) && (!defined $xls_content_row_start))
            {
                $xls_content_row_start = $row;
                $xls_content_num = $row_max - $xls_content_row_start + 1;
            }
            if (((defined $xls_content_row_start) && ($row >= $xls_content_row_start)) || (!defined $mdl_each_col_content[-1]) || ($mdl_each_col_content[-1] ne &xls_cell_value($WorkSheet, $row, $col)))
            {
                push(@mdl_each_col_content, &xls_cell_value($WorkSheet, $row, $col));
            }
            if ((defined $xls_content_row_start) && ($row == $xls_content_row_start))
            {
                $array_content_row_start = $#mdl_each_col_content;
            }
        }
        my @hash_tail_array;
        my $hash_pointer;
        for (1..$xls_content_num)
        {
            push(@hash_tail_array, \%{$mdl_list{$_}});
        }
        print "MDL_INFO_LIST " if ($DebugPrint == 1);
        foreach my $idx (1..$array_content_row_start-1)
        {
            my $data = $mdl_each_col_content[$idx];
            print "{$data}" if ($DebugPrint == 1);
            for my $content_idx (1..$xls_content_num)
            {
                $hash_pointer = shift(@hash_tail_array);
                if ($idx != $array_content_row_start-1)
                {
                    print "->" if ($content_idx == 1) && ($DebugPrint == 1);
                    if (!defined $hash_pointer->{$data})
                    {
                        $hash_pointer->{$data} = {};
                    }
                    $hash_pointer = $hash_pointer->{$data};
                    #print "[$idx][$content_idx]hash_pointer:$hash_pointer\n";
                }
                push(@hash_tail_array, $hash_pointer);
            }
        }
        print "=" if ($DebugPrint == 1);
        foreach my $idx ($array_content_row_start..$#mdl_each_col_content)
        {
            my $mdl_idx = $idx - $array_content_row_start + 1;
            my $data = $mdl_each_col_content[$idx];
            $hash_pointer = shift(@hash_tail_array);
            $hash_pointer->{$mdl_each_col_content[$array_content_row_start-1]} = $data;
            print "$mdl_idx:$data" if ($DebugPrint == 1);
            if ($idx != $#mdl_each_col_content)
            {
                print ", " if ($DebugPrint == 1);
            }
        }
        print "\n" if ($DebugPrint == 1);
    }

    return %mdl_list;
}

#****************************************************************************
# subroutine:  get_info
# input:       $file:        file path
#              $sheet:       sheet to open
#              $target_href: the target patterns to be searched
#              $href:        output matching hash reference
#****************************************************************************
sub get_info
{
    my ($file, $sheet, $target_href, $href) = @_;
    my %mdl_list;

    %mdl_list = &fs_read_excel($file, $sheet,  $target_href, $LOAD_TMP_PATH);

    if (keys(%mdl_list) == 0)
    {
        print "get_info return FALSE!\n" if ($DebugPrint == 1);
        return "FALSE";
    }

    foreach my $idx (keys %mdl_list)
    {
        if ($sheet =~ /\w+_\w+_MCP/)
        {
            if ($target_href->{0} eq $mdl_list{$idx}->{'Part Number'})
            {
                $href->{0} = $mdl_list{$idx}->{'DRAM Parameters'};
                $href->{1} = $mdl_list{$idx}->{'Flash Parameters'};
                for my $keys (keys %{$mdl_list{$idx}})
                {
                    if (($keys ne 'DRAM Parameters') && ($keys ne 'Flash Parameters'))
                    {
                        for (0..1)
                        {
                            $href->{$_}->{$keys} = $mdl_list{$idx}->{$keys};
                        }
                    }
                }
            }
        }
        else
        {
            my $tgt = 0;
            $tgt = $tgt + 1 if ($sheet =~ /\w+_FLASH/);
            if ($target_href->{$tgt} eq $mdl_list{$idx}->{'Part Number'})
            {
                $href->{$tgt} = $mdl_list{$idx};
            }
        }
    }
    &dump_mdl_info($href, "\$href->");

    if (keys(%{$href}) == 0)
    {
        return "FALSE";
    }

    return "TRUE";
}

#****************************************************************************
# subroutine:  SCHEME Configure Routines :: Query :: no EMI Family
# input:       NONE
# Output:      whether this chip belongs to no EMI Family
#****************************************************************************
sub config_query_no_EMI
{
    if ($CUSTOM_MEM_DEV_OPTIONS{MEMORY_DEVICE_TYPE} eq 'NONE')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


#****************************************************************************
# subroutine:  xls_cell_value
# return:      excel cell value no matter it's in merge area or not
# input:       $sheet:  specified Excel Sheet
#              $row:    specified row number
#              $col:    specified column number
#****************************************************************************
sub xls_cell_value
{
    my ($sheet, $row, $col) = @_;

    my $cell = $sheet->get_cell($row, $col);
    if ($cell)
    {
        if ((defined $cell->is_merged()) && ($cell->is_merged() == 1))
        {
            my $mareas =$sheet->get_merged_areas();
            # get merged areas' value if cell is merged
            for (0..$#$mareas)
            {
                if(($row >= $mareas->[$_]->[0] && $row <= $mareas->[$_]->[2]) && ($col >= $mareas->[$_]->[1] && $col <= $mareas->[$_]->[3]))
                {
                    return $sheet->get_cell($mareas->[$_]->[0], $mareas->[$_]->[1])->value();
                }
            }
        } else {
            # cell is not merged cell => get cell value
            return $cell->value();
        }
    } else {
        my $value;
        return $value;
    }
}

#****************************************************************************
# subroutine:  dependency check
# return:      None
#****************************************************************************
sub Check_ManualCheckIn
{
    my ($target, $force_del_new_file, @depends) = @_;

    return unless (-e $target);

    ## Now check if the $target file check-in or auto-gen
    ## Read whole file ##
    open SRC_FILE_R , "<$target" or &error_handler("$target: file error!", __FILE__, __LINE__);
    my $saved_sep = $/;
    undef $/;
    my $reading = <SRC_FILE_R>; 
    close SRC_FILE_R;
    $/ = $saved_sep;

    ## Look for check-in pattern ##
    if ($reading =~ /MANUAL-CHECKIN/i)
    {
        print "$target: Check-in message is found. No need to update.\n";
        return;
    }

    unlink $target if (-e $target);

    return;
}

#****************************************************************************
# subroutine:  CheckConfigValid
# return:      None
#****************************************************************************
sub CheckConfigValid
{
    my ($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $MEMORY_DEVICE_LIST_XLS_LOCAL, $MEMORY_DEVICE_LIST_INT_XLS_LOCAL) = @_;
    my $dram_size = $MDL_INFO_LIST[1]->{0}->{'Density (Mb)'};

    ###Check DRAM Size
    for (1..$CUSTOM_MEM_DEV_OPTIONS{COMBO_MEM_ENTRY_COUNT})
    {
        if ($emi_is_existed == 1)
        {
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Please select correct dram! dram_size is $dram_size.", __FILE__, __LINE__) if ((!defined $dram_size) || ($dram_size <= 0));
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Please select dram with the same size ($dram_size vs. $MDL_INFO_LIST[$_]->{0}->{'Density (Mb)'}) when COMBO_MEMORY_SUPPORT is enabled!", __FILE__, __LINE__) if ($dram_size ne $MDL_INFO_LIST[$_]->{0}->{'Density (Mb)'});
        }
    }

    ###Check Combo Memory Supporting
    if($MAKEFILE_OPTIONS{'combo_memory_support'} eq 'TRUE')
    {
        my @combo_mem_part_number;
        &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: MEMORY_DEVICE_TYPE supports only XXX_MCP when COMBO_MEMORY_SUPPORT is enabled!", __FILE__, __LINE__) if ((($CUSTOM_MEM_DEV_OPTIONS{MEMORY_DEVICE_TYPE} !~ /\w+_MCP/) && ($CUSTOM_MEM_DEV_OPTIONS{MEMORY_DEVICE_TYPE} ne 'NONE')) && ($MAKEFILE_OPTIONS{'sip_ram_size'} eq "NONE"));
        for (1..$CUSTOM_MEM_DEV_OPTIONS{COMBO_MEM_ENTRY_COUNT})
        {
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: COMBO MEM Part Number ($MCP_LIST[$_]->{0}) of DRAM should be the same that ($MCP_LIST[$_]->{1}) of Flash!", __FILE__, __LINE__) if (($MCP_LIST[$_]->{0} ne $MCP_LIST[$_]->{1}) && ($MAKEFILE_OPTIONS{'sip_ram_size'} eq "NONE"));
            for my $combo_mem_idx (0..$#combo_mem_part_number)
            {
                &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Each COMBO MEM Part Number should be difference ($combo_mem_part_number[$combo_mem_idx]:COMBO_MEM0$combo_mem_idx and COMBO_MEM0$_)!", __FILE__, __LINE__) if ($MCP_LIST[$_]->{1} eq $combo_mem_part_number[$combo_mem_idx]);
            }
            push(@combo_mem_part_number, $MCP_LIST[$_]->{1});
        }
    }

    ###Combo Flash Size Should be same
    if($MAKEFILE_OPTIONS{'combo_memory_support'} eq 'TRUE')
    {
        if($MAKEFILE_OPTIONS{'serial_flash_support'} eq 'TRUE')
        {
            for (1..$CUSTOM_MEM_DEV_OPTIONS{COMBO_MEM_ENTRY_COUNT})
            {
                my $cur_nor_size_Mb;
                $cur_nor_size_Mb = $MDL_INFO_LIST[$_]->{1}->{'Size (Mb)'};
                if (!defined $nor_size_Mb)
                {
                    $nor_size_Mb = $cur_nor_size_Mb;
                }
                else
                {
                    &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Please select flash with the same size when COMBO_MEMORY_SUPPORT is enabled!", __FILE__, __LINE__) if ($nor_size_Mb != $cur_nor_size_Mb);
                }
            }
        }
        elsif($MAKEFILE_OPTIONS{'nand_support'} eq 'TRUE')
        {
            my $nand_size_Mb;
            my $nand_block_size;
            for (1..$CUSTOM_MEM_DEV_OPTIONS{COMBO_MEM_ENTRY_COUNT})
            {
                my $cur_nand_size_Mb;
                my $cur_nand_block_size;
                $cur_nand_size_Mb = $MDL_INFO_LIST[$_]->{1}->{'NAND Size(MB)'};
                $cur_nand_block_size = $MDL_INFO_LIST[$_]->{1}->{'NAND Block Size(KB)'};
                if (!defined $nand_size_Mb)
                {
                    $nand_size_Mb = $cur_nand_size_Mb;
                    $nand_block_size = $cur_nand_block_size;
                }
                else
                {
                    &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Please select flash with the same size when COMBO_MEMORY_SUPPORT is enabled!", __FILE__, __LINE__) if ($nand_size_Mb != $cur_nand_size_Mb);
                    &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Please select flash with the same block size when COMBO_MEMORY_SUPPORT is enabled!", __FILE__, __LINE__) if ($nand_block_size != $cur_nand_block_size);
                }
            }
        }
    }
    ###Serail Flash Support and NAND Support Should Not be TRUE at the same time
    if(($MAKEFILE_OPTIONS{'serial_flash_support'} eq 'TRUE') and ($MAKEFILE_OPTIONS{'nand_support'} eq 'TRUE'))
    {
        &error_handler("Serial Flash and NAND Flash Support at the same time, please check makefile setting!!", __FILE__, __LINE__);
    }

    ###The Flash Name max length is 64
    if($MAKEFILE_OPTIONS{'nand_support'} eq 'TRUE')
    {
        for (1..$CUSTOM_MEM_DEV_OPTIONS{COMBO_MEM_ENTRY_COUNT})
        {
            my $vendor = uc($MDL_INFO_LIST[$_]->{1}->{'Vendor'});
            my $PartNumber = $MDL_INFO_LIST[$_]->{1}->{'Part Number'};
            my $flash_name .= "$vendor " if (defined $vendor);
            $flash_name .= "$PartNumber" if (defined $PartNumber);
            my $name_length = length($flash_name);
            if($name_length > 64)
            {
                &error_handler("Flash Name is too long, DA Support Max Length is 64 byte!!", __FILE__, __LINE__);
            }
        }
    }

    return;
}



#****************************************************************************
# subroutine:  error_handler
# input:       $error_msg:     error message
#****************************************************************************
sub error_handler
{
    my ($error_msg, $file, $line_no) = @_;

    my $final_error_msg = "EMIGEN ERROR: $error_msg at $file line $line_no\n";
    print $final_error_msg;
    die $final_error_msg;
}


#****************************************************************************
# subroutine:  copyright_file_header
# return:      file header -- copyright
#****************************************************************************
sub copyright_file_header
{
    my $template = <<"__TEMPLATE";
/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  description_file_header
# return:      file header -- description 
# input:       $filename:     filename
# input:       $description:  one line description
# input:       $author:       optional
#****************************************************************************
sub description_file_header
{
    my ($filename, $description, $author) = @_;
    my @stat_ar;
    my ($sec, $min, $hour, $day, $month, $year);

    if (-e $MEMORY_DEVICE_LIST_XLS) {
        @stat_ar = stat $MEMORY_DEVICE_LIST_XLS;
        ($sec, $min, $hour, $day, $month, $year) = localtime($stat_ar[9]);
    } elsif (-e "tools/emiGenSP.pl") {
        @stat_ar = stat "tools/emiGenSP.pl";
        ($sec, $min, $hour, $day, $month, $year) = localtime($stat_ar[9]);
    } else {
        ($sec, $min, $hour, $day, $month, $year) = localtime();
    }
    $month++;
    $year+=1900;

    my $template = <<"__TEMPLATE";
/*****************************************************************************
 *
 * Filename:
 * ---------
 *   $filename
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   $description
 *
 * Author:
 * -------
 *  $author
 *
 *   Memory Device database last modified on $year/$month/$day
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * \$Revision\$
 * \$Modtime\$
 * \$Log\$
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

__TEMPLATE

    return $template;
}

#******************************************************************************
# subroutine:  get_CurrTime_str
# return:      string of the current time
# input:       None
#******************************************************************************
sub get_CurrTime_str
{
    my($sec, $min, $hour, $mday, $mon, $year) = localtime(time);
    return (sprintf "%04d_%02d_%02d_%02d_%02d_%02d", $year+1900, $mon+1, $mday, $hour, $min, $sec);
}

#****************************************************************************
# subroutine:  SCHEME Configure Routines :: Query :: MD Information
#****************************************************************************
sub query_MD_INFO
{
    my ($MAKEFILE_OPTIONS_LOCAL,$CUSTOM_MEM_DEV_OPTIONS_LOCAL,$COMM_MDL_INFO_LOCAL) = @_;
    open write_file, ">", "MD_INFO.txt" or die "open file error:$!";
    #if(($CUSTOM_MEM_DEV_OPTIONS{'MEMORY_DEVICE_TYPE'} = 'LPDDR') || ($CUSTOM_MEM_DEV_OPTIONS{'MEMORY_DEVICE_TYPE'} = 'LPDDR2') || ($CUSTOM_MEM_DEV_OPTIONS{'MEMORY_DEVICE_TYPE'} = 'LPSDRAM'))
    #{
        #if(defined $MAKEFILE_OPTIONS{'sip_ram_size'})
        #{
            #print write_file "Memory device type:$CUSTOM_MEM_DEV_OPTIONS{'MEMORY_DEVICE_TYPE'}";
            #print write_file "size:$COMM_MDL_INFO{1}->{'Size (Mb)'}"
        #}
        #else
        #{
            #print write_file "Memory device type:$CUSTOM_MEM_DEV_OPTIONS{'MEMORY_DEVICE_TYPE'}";
            #print write_file "size:$COMM_MDL_INFO{1}->{'Size (Mb)'}"
        #}

    #}
    #else
    #{
        #if(defined $MAKEFILE_OPTIONS{'sip_ram_size'})
        #{
            #print write_file "Memory device type:$CUSTOM_MEM_DEV_OPTIONS{'MEMORY_DEVICE_TYPE'}";
            #print write_file "size:$COMM_MDL_INFO{1}->{'Size (Mb)'}"
        #}
        #else
        #{
            #print write_file "Memory device type:$CUSTOM_MEM_DEV_OPTIONS{'MEMORY_DEVICE_TYPE'}";
            #print write_file "size:$COMM_MDL_INFO{1}->{'Size (Mb)'}"
        #}
    #}

    print write_file "Memory device type:$CUSTOM_MEM_DEV_OPTIONS{'MEMORY_DEVICE_TYPE'}\n";
    print write_file "size:$COMM_MDL_INFO{1}->{'Size (Mb)'}\n";
    close(write_file);
}

#****************************************************************************
# subroutine:  Parse Custom Feature Configuration
#****************************************************************************
sub Parse_custom_FeatureConfig
{
    my ($CUSTOM_FEATURE_CFG_OPTIONS_LOCAL) = @_;
    open CUSTOM_FEATURE_CONFIG_HDR, "<$CUSTOM_FEATURE_CONFIG_HDR" or &error_handler("$CUSTOM_FEATURE_CONFIG_HDR: file error!", __FILE__, __LINE__);

    while (<CUSTOM_FEATURE_CONFIG_HDR>)
    {
        # error-checking
        if (/^#if|^#ifdef|^#ifndef|^#elif|^#else/)
        {
            &error_handler("$CUSTOM_FEATURE_CONFIG_HDR: Not allowed to set conditional keywords $_ in custom_FeatureConfig.h!", __FILE__, __LINE__)
                unless (/^#ifndef\s+__CUSTOM_FEATURECONFIG_H__/);
        }

        if (/^#define\s+(\w+)\s+\(([\w|\-]*)\)/ || /^#define\s+(\w+)\s+([\w|\-]*)/)
        {
            &error_handler("$CUSTOM_FEATURE_CONFIG_HDR: $1 redefined in custom_FeatureConfig.h!", __FILE__, __LINE__) if defined($CUSTOM_FEATURE_CFG_OPTIONS{$1});
            if ((!defined $2) or ($2 eq ''))
            {
                $CUSTOM_FEATURE_CFG_OPTIONS{$1} = 'TRUE';
            }
            else
            {
                $CUSTOM_FEATURE_CFG_OPTIONS{$1} = $2;
            }
        }
    }

    close CUSTOM_FEATURE_CONFIG_HDR;
    my $clean_setting;
    if($INSIDE_MTK eq '0')
    {
        $CUSTOM_FEATURE_CFG_OPTIONS{PROJECT_EXPECTED_RAM_LIMIT} = $clean_setting;
        $CUSTOM_FEATURE_CFG_OPTIONS{PROJECT_EXPECTED_CODE_LIMIT} = $clean_setting;
        $CUSTOM_FEATURE_CFG_OPTIONS{PROJECT_EXPECTED_RAM_LIMIT_NFB} = $clean_setting;
    }
    #$PROJECT_EXPECTED_RAM_LIMIT      = $CUSTOM_FEATURE_CFG_OPTIONS{PROJECT_EXPECTED_RAM_LIMIT};
    #$PROJECT_EXPECTED_CODE_LIMIT     = $CUSTOM_FEATURE_CFG_OPTIONS{PROJECT_EXPECTED_CODE_LIMIT};
    #$PROJECT_EXPECTED_RAM_LIMIT_NFB  = $CUSTOM_FEATURE_CFG_OPTIONS{PROJECT_EXPECTED_RAM_LIMIT_NFB};    
}

return 1;
