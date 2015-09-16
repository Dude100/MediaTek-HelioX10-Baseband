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
#*   sysGen1.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script copys files from Template folder to Project folder
#*
#* Author:
#* -------
#*   JI Huang  (mtk01077)
#*
#****************************************************************************/

#****************************************************************************
# Included Modules
#****************************************************************************
BEGIN { push @INC, './tools/' }  # add additional library path
use sysGenUtility;                 #pm file name without case sensitivity
use strict;
use tools::pack_dep_gen;
PrintDependModule();


#****************************************************************************
# Constants
#****************************************************************************
my $SYSGEN1_VERNO    = " m0.04";
                       # m0.04 , 2012/09/02 , Support ALPS database for check-in history
                       # m0.03 , 2012/07/02 , Support EWS via tools::pack_dep_gen
                       # m0.02 , 2012/06/28 , Support MOLY database for check-in history
                       # m0.01 , 2012/05/28 , Support path and filename case sensitive on Linux
                       # v1.91 , 2012/04/17 , Support EWS to print file dependency
                       # v1.90 , 2012/01/24 , Support .template copy and refactory sysgen1.pl
                       # v1.89 , 2011/10/18 , Modify the pattern replacement scheme and auto generate the version number
                       # v1.88 , 2011/09/28 , Fix a error_handler bug
                       # v1.87 , 2011/09/02 , Remove fs_config.c template
                       # v1.86 , 2011/09/02 , Add messages for clarifying what files have been copied
                       # v1.84 , 2011/08/29 , Modify sysgen1's flow
                       # v1.83 , 2011/08/04 , Modify custom_config.c template to add CUSTOM_CFG_GLOBAL_MEM_SIZE_IN_BYTES
                       # v1.82 , 2011/07/25 , Stop generating custom_fs.h, and remove including custom_fs.h in fs_config.c
                       # v1.79 , 2011/07/07 , Modify fs_config.c template for moving FS_OPEN_HINT to makefile
                       # v1.78 , 2011/07/06 , Modify custom_config.c template not to contain sys_mem_gen.pl
                       # v1.77 , 2011/07/05 , Modify custom_img_config.c template for bootloader re-orgnization
                       # v1.76 , 2011/07/05 , Modify custom_fs.h template for preparing to remove custom_fs.h
                       # v1.75 , 2011/06/17 , Modify custom_fs.h template for FS slim
                       # v1.74 , 2011/06/09 , Modify custom_config.c template to unify interface for customers amd RDs, remove custom1_create.c and change file owners.
                       # v1.73 , 2011/06/02 , Modify custom_config.c template to remove system memory on MoDIS and merge 8, 16 to 32B ctrl buffer
                       # v1.72 , 2011/06/01 , Modify custom_config.c template to have build time system memory on MoDIS and target
                       # v1.71 , 2011/05/30 , Modify custom_config.c template to add system memory on MoDIS
                       # v1.70 , 2011/05/29 , Modify custom_config.c template because similar codes have existed in ctrl_buff_pool.h
                       # v1.69 , 2011/05/25 , Modify fs_config.c template for insufficient FS_MAX_DRIVE on MT6251
                       # v1.67 , 2011/05/24 , Add file owner and remove 2 useless functions - ctrlbuffpool_gsm_lowcost, ctrlbuffpool_gsm_lowcost_singlebank
                       # v1.66 , 2011/05/24 , Modify custom_config.c template to support build time memory calculation 
                       # v1.65 , 2011/05/23 , Modify custom_jump_tbl.c template for supporting emmc booting 
                       # v1.64 , 2011/05/23 , Modify custom_config.c template for system memory on JADE36V2_DEMO_GPRS(COSMOS_WQVGA_SINGLE) has exhausted 
                       # v1.63 , 2011/05/20 , Modify fs_config.c template to roll-back for no need to enlarge file table for MMS 
                       # v1.62 , 2011/05/18 , Modify custom_jump_tbl.h and custom_jump_tbl.c template for emmc booting
                       # v1.61 , 2011/05/12 , Modify fs_config.c and custom_fota.c template for emmc booting
                       # v1.60 , 2011/05/06 , Modify custom_config.c template to add 54K system memory
                       # v1.59 , 2011/04/22 , Modify custom_config.c template to enlarge system memory
                       # v1.57 , 2011/04/15 , Modify custom_config.c template to increase the demand page pool size for audio and video concurrency
                       # v1.56 , 2011/04/15 , Modify fs_config.c template to increase the amount of fs handles
                       # v1.55 , 2011/04/12 , Modify custom_config.c, custom_config.h template to remove vs task from custom file to kal config file
                       # v1.54 , 2011/04/12 , Modify custom_config.c template to enlarge system memory size(GLOBAL_MEM_SIZE, GLOBAL_DEBUG_MEM_SIZE) on WCDMA
                       # v1.53 , 2011/04/11 , Modify custom_config.c and fs_config.c to fine-tune system memory and FS configurations for MT6252 16+32 segment
                       # v1.52 , 2011/03/30,  Move sub config_query_arm9, config_query_arm11, dependency_check to sysGenUtility.pm
                       # v1.51 , 2011/03/24 , Modify custom_config.c template to remove SLIMMING_WITH_DEMAND_PAGING compile option
                       # v1.50 , 2011/03/24 , Modify custom_sds_dp.c template to refine error handling flow
                       # v1.49 , 2011/03/20 , Modify custom_config.c template to remove JATAAYU_SUPPORT option because Jataayu WAP-MMS solution is already phased-out
                       # v1.48 , 2011/03/17 , Modify custom_config.c template to define DEMP_PAGE_POOL_SIZE based on __SLIMMING_WITH_DEMAND_PAGING_LEVEL1__
                       # v1.47 , 2011/03/17 , Modify custom1_create.c template to include custom_config.h to fix basic load build error
                       # v1.46 , 2011/03/16 , Modify custom_fota.h template to change FUE_CACHE_ENTRIES from 8 to 4 for 4KB NAND page size memory reduction
                       # v1.45 , 2011/03/10 , Modify fs.c template to increase FS_MAX_FILES by 1 on MT6251 to fix FMR recursive call concurrent with NVRAM issue
                       # v1.44 , 2011/03/10 , Modify custom_config.c template to enlarge HSPA system memory by 32KB because 2 16KB control buffer has been added for IOT
                       # v1.43 , 2011/03/07 , Modify custom_config.c template to enlarge EDGE segment system memory by 10KB to fix insufficient system memory issue
                       # v1.42 , 2011/03/07 , Modify custom_config.c template to add WT600K and RM compile options to determine DEMP_PAGE_POOL_SIZE
                       # v1.29 , 2011/03/04 , Modify fs_config.c template to support Card DL
                       # v1.41 , 2011/03/04 , Modify custom_config.c template to simplify MoDIS debug memory configuration and add more for difference with target.
                       # v1.40 , 2011/02/25 , Fine-tune System/Debug memory to remove long-occupants, remove out-of-date options, and to shrink debug memory by statistics
                       # v1.39 , 2011/02/25 , Enlarge DEMP_POOL_SIZE for video on MT6276
                       # v1.37 , 2011/02/23 , Remove custom_sap.h and modify custom_config.c template to remove custom module out-of-range check
                       # v1.36 , 2011/02/20 , Modify custom_config.c template to enlarge DEMP_PAGE_POOL_SIZE from 800 to 1200 for audio codec on MT6276
                       # v1.35 , 2011/02/18 , Modify fs_config.c template to enlarge FS_MAX_THREAD by 1 for LC(COMMON) projects
                       # v1.34 , 2011/02/17 , Shrink system/debug memory for control buffer refinement (remove long-time occupants)
                       # v1.33 , 2011/02/15 , Enlarge GPRS lowest segment system memory by 50KB to fix CLAM53 insufficient system memory power-on failure
                       # v1.32 , 2011/02/12 , Modify fs_config.c template to add FS TLS and remove TaskTrace structure
                       # v1.31 , 2011/01/31 , Fine-tune system/debug memory and control buffer configurations for Gemini+, GSM, and Low-Cost projects
                       # v1.30 , 2011/01/28 , To support eMMC Booting
                       # v1.28 , 2011/01/21 , Change FS_MAX_THREAD from 7 to 8 when LOW_COST_SUPPORT != NONE
                       # v1.27 , 2011/01/21 , Generate custom_sds_type.h, custom_sds_dp.c, and custom_sds_dp.h to support SDS
                       # v1.26 , 2011/01/17 , Enlarge MT6251 16-byte control buffer from 25 to 32 and enlarge system memory by 1KB
                       # v1.25 , 2011/01/12 , Enlarge MT6251 system memory by 3KB to support MT6251E2 (USB task)
                       # v1.24 , 2010/12/30 , Change template of WCDMA system/debug memory configuration. Call globalmem_wcdma and ctrlbuffpool_wcdma to generate umts configuration when L1_WCDMA == TRUE or UMTS_MODE_SUPPORT != NONE.
                       # v1.23 , 2010/12/29 , Modify template of fs_config.c to encapsulate declaration of FS_MAX_OPEN_HINT_PATH and FS_MAX_OPEN_HINT_LOCATION_PER_HINT in #ifdef __FS_OPEN_HINT__ and #endif segment.
                       #                      Modify redundant semicolon in MAX_THREAD in ULC 6251 case in template of fs_config.c.
                       # v1.22 , 2010/12/29 , Search additioinal check in pattern "MANUAL-CHECKIN" in each target file and not to remove a target file when this pattern is found.
                       # v1.21 , 2010/12/24 , Remove MT6255 option from ARM11 table.
                       # v1.20 , 2010/12/23 , Modify fs_config.c to add MoDIS support: (1) Encapsulate file body of fs_config.c with "#if defined(__MTK_TARGET__) || defined(__FS_MODIS_FDM__)" and "#endif".
                       #                                                               (2) Use directive of size of array instead of const variable.
                       # v1.19 , 2010/12/17 , Support RHR (Merge MAUIW1043OF_RHR to MAUI)
                       # v1.18 , 2010/12/15 , Merge RHR modifications of fs_config.c to MAUI.
                       # v1.17 , 2010/12/14 , Modify template of custom_fs.h, fs_config.c for 6251. Re-organize functions for 6251 low-cost.
                       #                      Refine modification of v1.15.
                       # v1.16 , 2010/12/09 , Modify template of custom_config.c, custom_config.h and custom_sap.h to __MAUI_SDK_TEST__ to turn on/off MAUI SDK AVK.
                       # v1.15 , 2010/12/08 , Modify custom_config.c template to add settings for 6251 with low cost feature
                       # v1.14 , 2010/12/01 , Modify dependency_check to remove redundant check-in message check. Add generate_autogen_file subroutine and modify code segment generating output files to generate output files collectively.
                       # v1.13 , 2010/11/18 , Modify custom_config.c template to shrink system/debug memory for SLIM_DEBUG_KAL or RELEASE_KAL
                       # v1.12 , 2010/11/18 , Modify custom_fs.h to remove smart file seeker compile option for MP
                       # v1.11 , 2010/11/17 , Enlarge GPRS+__WIFI_SUPPORT__ system memory by 30KB to fix MAUI_02837414
                       # v1.10 , 2010/11/10 , Modify fs_config.c template to adjust FS cache to be 32-byte-aligned for performance concern
                       # v1.09 , 2010/11/08 , Modify custom_config.c template to shrink system/debug memory by 1028-1040 statistics and for data buffer
                       # v1.08 , 2010/10/18 , Support RHR Add and add header files include on custom_util.c, custom_util.h, custom1_create.c, custom_config.c, custom_config.h, fs_config.c, custom_jump_tbl.c, custom_fota.h, and custom_img_config.c
                       # v1.07 , 2010/10/11 , Modify fs_config.c template to support Dual T-Card
                       # v1.06 , 2010/09/06 , Add MT6573 to ARM11 table
                       # v1.05 , 2010/08/27 , To support MT6276 and ARM11
                       # v1.04 , 2010/08/06 , Modify fs_config.c template to change __ARMx_MMU__ to __DYNAMIC_SWITCH_CACHEABILITY__ to support MT6253E/L write-back cache
                       # v1.03 , 2010/08/04 , Modify custom_fs.h to enable FS Smart File Seeker by compile option for QC
                       # v1.02 , 2010/07/29 , Modify fs_config.c template to add disk protection on WISE CUST disk
                       # v1.01 , 2010/07/29 , Modify fs_config.c template to force FS buffers to be 4-byte aligned to prevent data abort
                       # v1.00 , 2010/07/09 , Add a customer-configurable heap for malloc
                       # v0.99 , 2010/06/23 , Add 1 thread to FS_MAX_THREAD for GADGET for GPRS projects
                       # v0.98 , 2010/06/21 , Support Smart Phone projects with fixed FS drive number 3
                       # v0.97 , 2010/06/03 , Modify custom_fs.h template to support disk size limitation
                       # v0.96 , 2010/06/01 , Remove SINGLE_BANK_NOR_FLASH_SUPPORT makefile option
                       # v0.95 , 2010/05/26 , Modify fs_config.c template to put FS memory card performance enhancement dedicated buffer in Noncached region
                       # v0.94 , 2010/05/17 , Modify custom_fs.h and fs_config.c template to support FS memory card performance enhancement by dedicated buffer
                       # v0.93 , 2010/05/13 , Modify custom_util.c template to support enabling MAUI init debugging trace by keypad
                       # v0.92 , 2010/04/13 , Enlarge System Memory size when __GADGET_SUPPORT__ is defined
                       # v0.91 , 2010/04/13 , Enlarge System Memory size when OPERA_V10_BROWSER is defined 
                       # v0.90 , 2010/02/25 , Modify custom_fs.h and fs_config.c template to enable FS Open Hint
                       # v0.89 , 2010/01/25 , Modify custom_util.c template to support printing log at init
                       # v0.88 , 2010/01/23 , Modify fs_config.c template to increase file handle for __MMI_VECTOR_FONT_SUPPORT__
                       # v0.87 , 2010/01/05 , Support ARM11 Phase-in
                       # v0.86 , 2009/12/20 , Add MT6253D
                       # v0.85 , 2009/12/18 , Rename fs_config.h as custom_fs.h and temporarily disable FS_OPEN_HINT
                       # v0.84 , 2009/12/08 , Enlarge Edge System Memory pool size by 30KB
                       # v0.83 , 2009/11/24 , Modify fs_config.c template and add fs_config.h for FS internal hint
                       # v0.82 , 2009/11/10 , __OP01__ __OP11__ __OP12__ option for gprs GLOBAL_MEM_SIZE determine
                       #                      Remove unused option
                       # v0.81 , 2009/10/28 , Merge WISE_Dev to MAUI
                       # v0.80 , 2009/10/23 , gprs RAM configure template case switch correction
                       # v0.79 , 2009/09/16 , __WCDMA_RAT__ to __UMTS_RAT__
                       # v0.78 , 2009/09/02 , Enlarge System Memory pool 10KB for all edge projects
                       # v0.77 , 2009/07/31 , Modify fs_config.h template to update max thread number
                       # v0.76 , 2009/05/27 , Modify custom_jump_tbl.h template to support External MMI for WISE
                       # v0.75 , 2009/05/19 , Modify custom_MemoryDevice.h, custom_flash.c, custom_flash_norfdm5.c, flash_opt.h, custom_fota.c to re-organize flash-related configurations
                       # v0.74 , 2009/05/15 , Enlarge System Memory pool for new tasks for CMMB (__CMMB_CAS_SMD_SUPPORT__)
                       # v0.73 , 2009/04/09 , Enlarge system memory and debug memory pools for MT6268 (3G projects)
                       # v0.72 , 2009/04/03 , Enlarge system memory and debug memory pools for MT6268 (3G projects)
                       # v0.71 , 2009/03/12 , Modify custom_config.c control buffer and system memory template for MT6268 (3G projects)
                       # v0.70 , 2009/03/03 , Modify custom_fota.c template to meet NOR FOTA requirement
                       # v0.69 , 2009/02/18 , Modify custom_fota.c template for NFB+FOTA case for new boot-loader
                       # v0.68 , 2009/02/12 , Enlarge EDGE debug memory on MoDIS
                       # v0.67 , 2009/02/06 , Add the support of MT6268
                       # v0.66 , 2009/01/05 , Modify custom_fota.h template for FOTA and Secure RO co-existence
                       # v0.65 , 2008/12/31 , Remove MT6205B related codes
                       # v0.64 , 2008/12/31 , Enlarge system memory pool size by 40KB for GSM segment
                       # v0.63 , 2008/12/25 , Remove FOTA_PROPRIETARY
                       # v0.62 , 2008/11/26 , Modify custom_fota.c, custom_fota.h, and custom_img_config.c templates for FOTA+NFB
                       # v0.61 , 2008/11/07 , Modify fs_config.c template for ULC to reduce the number of file handles
                       # v0.60 , 2008/10/31 , Modify fs_config.c template for USB OTG device number
                       # v0.59 , 2008/10/15 , Support FOTA+NFB Auto-Gen
                       # v0.58 , 2008/10/08 , Increase ULC FS_MAX_THREAD by 1.
                       # v0.57 , 2008/10/08 , Modify custom_img_config.c and custom_fota.c templates to make FUE space larger than backup area.
                       # v0.56 , 2008/10/03 , Add custom task VS to support AVK (API Verify Kit)
                       # v0.55 , 2008/09/12 , Add file name and fline number information and unify all auto-gen error messages
                       # v0.54 , 2008/09/03 , To support Dcache Phase3
                       # v0.53 , 2008/09/03 , NAND_FLASH_BOOTING makefile option is changed
                       # v0.52 , 2008/08/28 , Modify custom_fota.c template to support FOTA on ARM9
                       # v0.51 , 2008/08/21 , Unify Auto-Gen error messages
                       # v0.50 , 2008/08/14 , Support FOTA Auto-Gen
                       # v0.49 , 2008/08/11 , Enable MT6238 stack@cacheable region
                       # v0.48 , 2008/08/08 , Modify fs_config.c template for Ultra Low Cost support
                       # v0.47 , 2008/08/04 , Increase system memory pool size by 5KB when GSM+LOW_COST_SUPPORT
                       # v0.46 , 2008/07/23 , Modify GLOBAL_CACHED_MEM_SIZE definition
                       # v0.45 , 2008/07/17 , Modify custom_img_config.c template for FOTA
                       # v0.44 , 2008/07/15 , Modify custom_img_config.c template for FOTA bug fix on boot-loader
                       # v0.43 , 2008/07/13 , Modify templates for FOTA
                       # v0.42 , 2008/07/09 , Modify fs_config.c template for FS Sorting Enhancement
                       # v0.41 , 2008/07/04 , Modify remap_mod_task_g for OBIGO_Q03C_MMS_V02
                       # v0.40 , 2008/07/02 , Modify custom_configmem API separation criteria for MoDIS
                       # v0.39 , 2008/07/01 , Move Cached_System_Mem_Pool out from cached region on MT6238
                       # v0.38 , 2008/06/21 , Modify custom_jump_tbl.c template for BASIC Load
                       # v0.35 , 2008/06/16 , Modify custom_config.c template for MT6235/MT6238 dynamic cacheable region
                       # v0.34 , 2008/06/13 , custom_img_config.c template imported and modify for FOTA and NFB MBA
                       # v0.33 , 2008/06/04 , Modify EDGE and GPRS custom_config.c templates to enlarge system memory and debug memory when AGPS_SUPPORT is turned on
                       # v0.32 , 2008/06/02 , Change makefile option LOW_COST_SUPPORT from FALSE/TRUE to NONE/COMMON/ULC
                       # v0.31 , 2008/04/09 , Modify custom_jump_tbl.c template for __MULTIPLE_BINARY_FILES__
                       # v0.30 , 2008/04/03 , Enlarge system memory pool for GEMINI
                       # v0.29 , 2008/03/27 , custom_config.c add custom_config_demp_page() for demand page in
                       # v0.28 , 2008/03/27 , fs_config.c revise for MT6235/MT6238
                       # v0.27 , 2008/03/27 , GLOBAL_MEM_SIZE 290K -> 320K on GPRS Generic globalmem_gprs for GEMINI projects
                       # v0.26 , 2008/03/05 , move custom_nor_large_disk.c generation to EMI Gen
                       # v0.25 , 2007/12/17 , GLOBAL_MEM_SIZE 330K -> 350K on Edge Generic globalmem_edge
                       # v0.24 , 2007/10/05 , fs_config.c revise for Dual MSDC setting
                       # v0.22 , 2007/08/20 , fs_config.c revise for MT6223P platform setting
                       # v0.21 , 2007/08/20 , custom_config.c system RAM default value alignment on GSM projects
                       # v0.20 , 2007/08/10 , custom_config.c system RAM and MMI stack adjustment if OBIGO_Q05A
                       # v0.19 , 2007/05/14 , custom_config.c control buffer slots adjustment
                       # v0.18 , 2007/05/14 , custom_config.c fs_config.c resource enlarge for DM , DRMT tasks
                       # v0.17 , 2007/04/23 , dependency_check enable
                       # v0.16 , 2007/04/23 , custom_config.c OBIGO_Q05A compile option 
                       # v0.15 , 2007/04/17 , GLOBAL_DEBUG_MEM_SIZE 150K -> 160K on globalmem_gsm
                       # v0.14 , 2007/03/12 , custom_config.c new function custom_config_task_stack_location()
                       # v0.13 , 2007/02/26 , fs_config.c revise for MSDC device configure update
                       # v0.12 , 2007/01/21 , make event schedule pool size customizable
                       # v0.11 , 2007/01/02 , custom_nor_large_disk.c template imported
                       #                    , add error checking on file close
                       # v0.10 ,            , minor revise on custom_fota.h template
                       # v0.09 , 2006/12/25 , fs_config.c support SIM_PLUS, custom_fota.c custom_fota.h template
                       # v0.08 , 2006/12/18 , new mechanism for custom task present on usb / factory boot mode

#****************************************************************************
# File Names
#****************************************************************************
# to align error message file name format
$ARGV[0] =~ s/^.\/|^\///;
my $ProjectDirPath   = $ARGV[0];
my $TemplateDirPath  = 'custom/system/Template';

#****************************************************************************
# system auto generator string
#****************************************************************************
my $strSysGenString = "system auto generator";

#****************************************************************************
# 2 >>>  Grep copiable files
#****************************************************************************
opendir( my $DIR, $TemplateDirPath) || &sysUtil::sysgen_die("Can't open $TemplateDirPath!", __FILE__, __LINE__);
my @Templates = grep { /\.c$|\.h$|\.c\.template$|\.h\.template$/ && -f "$TemplateDirPath/$_" } readdir( $DIR );
closedir $DIR;
#map {print $_, "\n";} @Templates;
#****************************************************************************
# 3 >>>  Report errors if there is any repeated file
#        e.g. A.c and A.c.template exist at the same time.
#****************************************************************************
&ReportRepeatedFiles(\@Templates);

#****************************************************************************
# 4 >>>  Copy files from Template folder if it's not it Project Folder with check-in history
#****************************************************************************

foreach my $file (@Templates)
{
    my $FilePathInProject  = $ProjectDirPath .'/'. $file;
    my $FilePathInTemplate = $TemplateDirPath .'/'. $file;
    $FilePathInProject =~ s/\.template//g;

    if(-f $FilePathInProject)
    {
        &sysUtil::del_noCheckinHistory_file($FilePathInProject);
    }
    if(not -f $FilePathInProject)
    {
        &CopyFileWithReplacement($FilePathInTemplate, $FilePathInProject, ["\\[MAUI_\\d{8}\\]", "MANUAL-CHECKIN", "\\[MOLY\\d{8}\\]", "\\[ALPS\\d{8}\\]"]);
        print "SYSGEN1: Copy $file from $TemplateDirPath to $ProjectDirPath\n";
    }
}

#****************************************************************************
# oo >>>  Finished
#****************************************************************************
exit;

#****************************************************************************
# subroutine:  CopyFileWithReplacement
# input:       $SrcPath - source file path
#              $DestPath - destination path
#              $Array_ref : An array of strings to be replaced to empty string
# output:     N/A
# Description: 1. if the file name doesn't contain .template, replace sysgen1 verno on it
#              2. replace the string in $Array_ref to empty string
#****************************************************************************
sub CopyFileWithReplacement
{
    my ($SrcPath, $DestPath, $Array_ref) = @_;
    my $content;
    open FILE, "<$SrcPath" or &sysUtil::sysgen_die("$SrcPath: open file error!", __FILE__, __LINE__);
    {
        local $/;
        $content = <FILE>;
    }
    close FILE;

    if($SrcPath !~ /\.template$/)
    {
        #Add sysgen1.pl's verno to the file
        $content =~ s/system\s*auto\s*generator(.*)//;    
        $content =~ s/Author\s*:\s+(.*)\s+(.*)/Author:\n $1\n $2    $strSysGenString $SYSGEN1_VERNO /;
    }

    #replace the string in $Array_ref to empty string
    map {$content =~ s/$_//ig} @$Array_ref;
        
    open FILE, ">$DestPath" or &sysUtil::sysgen_die("$DestPath: open file error!", __FILE__, __LINE__);
    print FILE $content;
    close FILE;
}

#****************************************************************************
# subroutine:  ReportRepeatedFiles
# input:       $FileNames_ref
# output:      N/A
# Description: if $FileNames_ref exists A and A.template at the same time,
#              this function reports error.
#****************************************************************************
sub ReportRepeatedFiles
{
    my ($FileNames_ref) = @_;
    my @temp_array = grep { /\.template/ } @$FileNames_ref;
    foreach my $item (@temp_array)
    {
        $item =~ s/\.template//;
        foreach my $filename (@$FileNames_ref)
        {
            if($filename eq $item)
            {
                &sysUtil::sysgen_die("$item and $item.template can't exist at the same time!", __FILE__, __LINE__);
                last;
            }
        }
    }
}
