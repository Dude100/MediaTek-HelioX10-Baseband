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
#*   CMMAutoGen.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script generates the CMM files for debugging
#*
#* Author:
#* -------
#*   Claudia Lo  (mtk01876)
#*
#****************************************************************************/

#****************************************************************************
# Included Modules
#****************************************************************************
use strict;
BEGIN { push @INC, './tools/' }  # add additional library path
use sysGenUtility;                 #pm file name without case sensitivity
use FileInfoParser;
use LISInfo;
use File::Copy;
use File::Basename;
use CommonUtility;
#****************************************************************************
# Constants
#****************************************************************************
my $CMMGEN_VERNO     = " m0.35";
                      #  m0.35, Support MDx OnTargetMemoryDump.cmm
                      #  m0.34, Support MDx chip select and global bbreg
                      #  m0.33, Support MT6752 reg_base.h shared
                      #  m0.32, Support to generate dspbin info.
                      #  m0.31, Support memory dumped by cmm
                      #  m0.30, Support Build Info and MT6290 nocode
                      #  m0.29, Support Debug Assistant
                      #  m0.28, Workaround for MT6290_COPRO to use mt6290_reg_base.h
                      #  m0.27, Add infomake.log input
                      #  m0.26, Support MT6290 nocode.cmm
                      #  m0.25, Support more flexible reg_base parsing
                      #  m0.24, Support CodeIntegrity Check with new template
                      #  m0.22, Set ResBreak Off on MT6280 for connecting to T32
                      #  m0.21, Remove Modem_Only.cmm's rule, add Info.cmm support
                      #  m0.20, Support Modem_Only.cmm
                      #  m0.19, [WR8]
                      #  m0.18, Fix CheckIntegrity based on ROM due to the change of region naming
                      #  m0.17, [WR8]
                      #  m0.16, Support get chip
                      #  m0.15, Move Dec2Hex from sysGenUtility to CommonUtility
                      #  m0.14, Support version check
                      #  m0.13, Support Check Code integrity for MT6280
                      #  m0.12, Support Platform in SwitchToClonedChip()
                      #  m0.11, Modify cmm to make dcm driver force on ARM clock (only for MT6280E1) 
                      #  m0.10, Change relative source path to be in DATA.LOAD.ELF
                      #  m0.09, Add relative source path and modify dbgsuite path for the one folder structure
                      #  v1.43, Remove winclear in BL/EXT_BL cmm and InTargetReset.cmm 
                      #  m0.08, Support precompile in GCC
                      #  m0.07, Support path and filename case sensitive on Linux
                      #  m0.06, Support GCC
                      #  m0.05, Support the one new architecture
                      #  m0.04 , Modify cmm for unstable MT6280 SIP connection
                      #  m0.03 , Skip GCC temporarily
                      #  v1.41 , Reset workaround for MT6250
                      #  v1.40 , support ALICE
                      #  v1.38 , Support Memory dump synced with sysgen2
                      #  m0.02 , Correct command for CR4
                      #  v1.37 , Support MT6922
                      #  m0.01 , Support MT6280
                      #  v1.36 , Parse LIS only when generatinig MAUI cmm files to prevent false alarm of parsing LIS error when generating BL/FOTA cmm files; correct MT6235B/MT6236B/MT6921 reg_base file name
                      #  v1.30 , Modify TK6280 CMM to support CR4 template
                      #  v1.21 , Support TK6280 CMM Gen
                      #  v1.35 , Generate MAUI/BL/EXT_BL/FOTA nocode.cmm and utility cmm from CMMAutoGen.pl
                      #  v1.34 , Skip EXTSRAM_TMP_PAGE_TABLE to sync MTK_Only.cmm with memory dump
                      #  v1.33 , Remove mmv2_offline_restore.cmm because it is merged to BasicAnalysis.cmm
                      #  v1.32 , Modify MT6575 nocode.cmm for Device APC
                      #  v1.31 , Fix MT6252 CMM not sync with dump issue for DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI and CACHED_EXTSRAM_NVRAM_LTABLE
                      #          Restore ZIMAGE dump
                      #          Make OS configurations independent of makefile
                      #  v1.29 , Correct MTK_Only.cmm to follow new continuous regions and rule after adding MMIPOOL and VIDEOPOOL
                      #  v1.28 , Modify MT6255 CMM file to work-around and set PC at boot-rom due to invalid boot code
                      #  v1.27 , Load SINGLE_BANK_CODE region for MT6252 to restore single-bank symbols
                      #  v1.26 , Skip NVRAM_LTABLE because it'll append on other regions
                      #  v1.25 , Clear only 128KB RAM disk and clear RAM disk only when RAM disk exists
                      #  v1.24 , Load FLMM_STACKSPACE to support Stack Isolation
                      #  v1.23 , Remove flash_opt.h input parameter and flash_opt.h part for this file is no longer used in CMM Gen and is removed
                      #  v1.22 , Skip FLMM EXTSRAM region because it is continuous with DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI
                      #  v1.20 , Modify MT6256 MTK_Only.cmm to correct Sys RAM base by retrieving from LIS file, and to add vector table dump
                      #  v1.19 , Correct MMv2_offline_restore.cmm path for MMv2
                      #  v1.18 , Support MMv2
                      #  v1.17 , Change MT6256 CPU to ARM1176JZF
                      #  v1.16 , Get EXTSRAM_FS information from lis file and then embed these information in nocode.cmm to adapt to EXTSRAM_FS location change for memory reduction
                      #  v1.14 , Modify MT6575 nocode.cmm to enable system reset and to add EMI BW limiter
                      #  v1.10 , Support MT6575 CMM Gen
                      #  v1.15 , Transform reg_base_mt6921.h into reg_base_mt6236.h to fix MT6921 RGU base missing issue
                      #  v1.12 , Support MT6921
                      #  v1.13 , Fix CMM file abort off missing issue due to eMMC booting side effect
                      #  v1.11 , Support eMMC Booting
                      #  v1.09 , Add MAUI_BIN input parameter and add this information to MAUI bin and DSP_ROM loading path; Correct MT6573 DPLL settings
                      #  v1.08 , Use NUCLEUS configuration instead of NUCLEUS_V2 to fix CVD unable to display Nucleus task information issue on MT6276
                      #  v1.07 , Remove redefinition check to prevent false alarm warnings
                      #  v1.06 , Copy ZIMAGE from load view to exec view so that the decompressed codes can be seen
                      #  v1.05 , To support makefile option USB_DOWNLOAD renamed as USB_DOWNLOAD_IN_BL
                      #  v1.04 , Generate l1assertbypass button under all platforms
                      #  v1.03 , Dump 0x0 on MT6252 to fix vector table corruption false alarm
                      #  v1.02 , Remove "Go" button on MT6251/MT6252/MT6252H because RTCK bug has been fixed on E2/E3
                      #  v1.01 , Set MT6251/MT6252/MT6252H JtagClock to RTCK because RTCK bug has been fixed on E2/E3
                      #  v1.00 , initial version after SS take over
my $CMMGEN_AUTHOR    = "Qmei Yang";

#****************************************************************************
# Input Parameters and Global Variables
#****************************************************************************
my $ACTION        = $ARGV[0];  # 0: MAUI nocode.cmm; 1: HQ_Only.cmm; 2: BL nocode.cmm; 3: EXT_BL nocode.cmm; 4: FOTA nocode.cmm
my $CMMFILE       = $ARGV[1];
my $ELFFILE       = $ARGV[2];
my $MAKEFILE      = $ARGV[3];
my $MAUI_BIN      = $ARGV[4];
my $LISFILE       = $ARGV[5];
my $CC_CMD        = $ARGV[6];
my $VIA_CMD       = $ARGV[7];
my $OPTION_TMP    = $ARGV[8];
my $TMP_FOLDER    = $ARGV[9];
my $INFOMAKE_PATH = $ARGV[10];
my $TMPFILE_PATH  = $ARGV[11];


my $DebugPrint = 0;
my $CMMDIR  = dirname($CMMFILE);
my $BUILDDIR  = dirname($ELFFILE);
my $g_strCOMPILER = undef;
my $g_strDSPBinName = "";
print "ACTION: $ACTION,\nCMMFILE: $CMMFILE,\nCMMDIR:  $CMMDIR,\n
ELFFILE: $ELFFILE, \nMAKEFILE: $MAKEFILE,\n
MAUI_BIN: $MAUI_BIN, \nLISFILE: $LISFILE, \n
CC_CMD: $CC_CMD, \nVIA_CMD: $VIA_CMD, \nOPTION_TMP: $OPTION_TMP\n
TMP_FOLDER: $TMP_FOLDER\nINFOMAKE_PATH: $INFOMAKE_PATH\n
TMPFILE_PATH: $TMPFILE_PATH\n";

#****************************************************************************
# 1 >>> Parse makefile
#****************************************************************************
my %MAKEFILE_OPTIONS;
my %CmplOption;
my %RelOption;
FileInfo::PreProcess($MAKEFILE, \%MAKEFILE_OPTIONS, $INFOMAKE_PATH, \%CmplOption, \%RelOption, 1);
my $PLATFORM = &FileInfo::GetChip();
$PLATFORM = &sysUtil::SwitchToClonedChip($PLATFORM);
$PLATFORM =~ s/\_COPRO// if($PLATFORM =~ /\_COPRO/); # temporarily workaround
$g_strCOMPILER = &FileInfo::GetCompiler();


#****************************************************************************
# 2 >>> Parse reg_base.h
#****************************************************************************
my $REG_BASE_TMP_AFTER_TRANSFORM = "$TMP_FOLDER/~reg_base_after_transform.h";
my $REG_BASE_TMP_AFTER_PRECOMPILE = "$TMP_FOLDER/~reg_base_after_precompile.h";
my $REG_BASE_H = "./driver/regbase/inc/";
my %REG_BASE_DEFS;

### Determine reg_base.h by platform
my $platform_lc = lc(&DefineRegBaseChipName($PLATFORM));
my $reg_base_h_file = "reg_base_" . $platform_lc . "\.h";
$REG_BASE_H .= $reg_base_h_file;
copy ($REG_BASE_H, "$TMP_FOLDER/$reg_base_h_file");

### Change reg_base definitions to data structure for pre-compile
&reg_base_define_to_struct($TMP_FOLDER, $reg_base_h_file, $REG_BASE_TMP_AFTER_TRANSFORM);

### Pre-compile reg_base.h to get the correct register base addresses
my $status = system("$CC_CMD $VIA_CMD $OPTION_TMP -E $REG_BASE_TMP_AFTER_TRANSFORM > $REG_BASE_TMP_AFTER_PRECOMPILE") if($g_strCOMPILER eq "RVCT");
my $status = system("$CC_CMD $VIA_CMD$OPTION_TMP -E $REG_BASE_TMP_AFTER_TRANSFORM > $REG_BASE_TMP_AFTER_PRECOMPILE") if($g_strCOMPILER eq "GCC");
&error_handler("tools/CMMAutoGen.pl: pre-compile $REG_BASE_TMP_AFTER_TRANSFORM error!", __FILE__, __LINE__) if ($status != 0);

### Parse pre-compiled results and get the correct base address for each address
&parse_reg_base($REG_BASE_TMP_AFTER_PRECOMPILE, \%REG_BASE_DEFS);
if ($DebugPrint == 1)
{
    foreach (keys %REG_BASE_DEFS)
    {
        my $key = $_;
        my $value = $REG_BASE_DEFS{$_};
        print "#define $key $value\n";
    }
}
#****************************************************************************
# 2.5 >>> Parse dsp bin path
#****************************************************************************
if(-f $TMPFILE_PATH)
{
    my %TMP;
    my $strTMPFILE = CommonUtil::GetFileContent($TMPFILE_PATH);
    CommonUtil::HashStringParser($strTMPFILE, \%TMP);
    $g_strDSPBinName = basename($TMP{DSPMOLY_BIN});
}
#****************************************************************************
# 3 >>> Generate MAUI nocode.cmm and utility cmm files
#****************************************************************************
if ($ACTION == 0)
{
    ### Parse LIS file first (do not parse LIS file outside to prevent unnecessary errors when LIS does not exist)
    &LISInfo::Parse($LISFILE);
    
    ### Generate MAUI nocode.cmm
    {
        my $maui_nocode_template;
    
        ### Copyright Statement
        $maui_nocode_template .= &template_copyright_file_header();
        
        ### verno string
        $maui_nocode_template .= &template_verno();
        
        ### CPU-related information and commands (chip-dependent)
        $maui_nocode_template .= &template_cpu_info_command($PLATFORM);
        
        ### disable watchdog (chip-dependent)
        $maui_nocode_template .= &template_disable_watchdog($PLATFORM, \%REG_BASE_DEFS);
        
        ### bypass CTIRQ1 precision check
        $maui_nocode_template .= &template_bypass_ctirq1_check(\%REG_BASE_DEFS);
    
        ### disable DABORT and PABORT breakpoint (chip-dependent)
        $maui_nocode_template .= &template_disable_dabort_pabort_bkpt($PLATFORM, \%MAKEFILE_OPTIONS);
   
        ### specify load elf
        $maui_nocode_template .= &template_specify_load_elf();
    
        ### add utilities for debugging
        $maui_nocode_template .= &template_add_utility_for_debug();
        
        ### add buttons for debugging
        $maui_nocode_template .= &template_add_button_for_debug($PLATFORM, \%MAKEFILE_OPTIONS);
        
        ### set attribute for breakpoints
        $maui_nocode_template .= &template_set_bkpt_attr();
    
        ### clean win and endup
        $maui_nocode_template .= &template_clean_win_and_endup(1);
        
        open (CMM_FILE, ">$CMMFILE") or &error_handler("$CMMFILE: Unable to open $CMMFILE!\n", __FILE__, __LINE__);
        print CMM_FILE $maui_nocode_template;
        close CMM_FILE;
    }
    
    ### Generate InTargetReset.cmm
    {
        my $InTargetReset_cmm_file = "$CMMDIR/InTargetReset.cmm";
        my $InTargetReset_cmm_template;
        
        ### Copyright Statement
        $InTargetReset_cmm_template .= &template_copyright_file_header();
        
        ### verno string
        $InTargetReset_cmm_template .= &template_verno();
        
        ### utility purpose
        $InTargetReset_cmm_template .= &template_utility_description("InTargetReset.cmm", "Perform reset action");

        ### CPU-related information and commands (chip-dependent)
        $InTargetReset_cmm_template .= &template_cpu_info_command($PLATFORM);
        if($PLATFORM eq "MT6290")
        {
            $InTargetReset_cmm_template =~ s/EnReset off/EnReset on/;
            $InTargetReset_cmm_template =~ s/WaitReset off/WaitReset 1.s/;    
        }
        
        ### disable watchdog (chip-dependent)
        $InTargetReset_cmm_template .= &template_disable_watchdog($PLATFORM, \%REG_BASE_DEFS);
           
        ### clean win and endup
        $InTargetReset_cmm_template .= &template_clean_win_and_endup(0);
        
        open (CMM_FILE, ">$InTargetReset_cmm_file") or &error_handler("$InTargetReset_cmm_file: Unable to open $InTargetReset_cmm_file!\n", __FILE__, __LINE__);
        print CMM_FILE $InTargetReset_cmm_template;
        close CMM_FILE;
    }

    ### Generate auto_reset.cmm [MAUI_00796491]
    {
        my $auto_reset_cmm_file = "$CMMDIR/auto_reset.cmm";
        my $auto_reset_cmm_template;
        
        ### Copyright Statement
        $auto_reset_cmm_template .= &template_copyright_file_header();
        
        ### verno string
        $auto_reset_cmm_template .= &template_verno();
        
        ### utility purpose
        $auto_reset_cmm_template .= &template_utility_description("auto_reset.cmm", "Auto Reset target with L1d assert disable");

        ### in-target reset
        $auto_reset_cmm_template .= &template_in_target_reset();

        ### bypass CTIRQ1 precision check
        $auto_reset_cmm_template .= &template_bypass_ctirq1_check(\%REG_BASE_DEFS);
        
        ### GO
        $auto_reset_cmm_template .= &template_go();
        
        open (CMM_FILE, ">$auto_reset_cmm_file") or &error_handler("$auto_reset_cmm_file: Unable to open $auto_reset_cmm_file!\n", __FILE__, __LINE__);
        print CMM_FILE $auto_reset_cmm_template;
        close CMM_FILE;
    }
    ### Generate Info.cmm
    {
        my $BuildFolder = dirname($LISFILE);
        &gen_info_cmm_from_template($PLATFORM, $BuildFolder, $ELFFILE, $MAUI_BIN, $CMMDIR, $g_strDSPBinName);
    }

    ### Generate Debug_Go.cmm (under certain conditions)
    if (($MAKEFILE_OPTIONS{'CUST_CODE'} eq 'TC01') and ($MAKEFILE_OPTIONS{'DEMO_PROJECT'} eq 'TRUE'))
    {
        my $DebugGo_cmm_file = "./Debug_Go.cmm";
        my $DebugGo_cmm_template;
        
        ### Copyright Statement
        $DebugGo_cmm_template .= &template_copyright_file_header();
        
        ### verno string
        $DebugGo_cmm_template .= &template_verno();

        ### utility purpose
        $DebugGo_cmm_template .= &template_utility_description("Debug_Go.cmm", "Break at scheduler, perform some task and then resume");
        
        ### set breakpoint at scheduler
        $DebugGo_cmm_template .= &template_set_bkpt_at_scheduler(\%MAKEFILE_OPTIONS);
        
        open (CMM_FILE, ">$DebugGo_cmm_file") or &error_handler("$DebugGo_cmm_file: Unable to open $DebugGo_cmm_file!\n", __FILE__, __LINE__);
        print CMM_FILE $DebugGo_cmm_template;
        close CMM_FILE;
    }
}

#****************************************************************************
# 4 >>> Generate MAUI HQ_Only.cmm
#****************************************************************************
if ($ACTION == 1)
{
    my $hq_only_template;
    
    ### Parse LIS file first (do not parse LIS file outside to prevent unnecessary errors when LIS does not exist)
    &LISInfo::Parse($LISFILE);
    
    ### Generate BuildInfo.cmm
    {
        my $BuildInfoCMM = "$CMMDIR/BuildInfo.cmm";
        my $TemplateFolder = "./tools/DebuggingSuite/Misc/";
        my $template = &CommonUtil::GetFileContent($TemplateFolder."BuildInfoTemplate.cmm");
        $template = &Gen_Info_CMMContent($PLATFORM, $template, $ELFFILE, $MAUI_BIN, $g_strDSPBinName);
        my $bbreg = &Gen_bb_reg_content(\%REG_BASE_DEFS);
        $template =~ s/\[CMMAUTOGEN_BBREG\]/$bbreg/g;
        open (OUTPUT_FILE, ">$BuildInfoCMM") or &error_handler("Unable to open $BuildInfoCMM!\n", __FILE__, __LINE__);
        print OUTPUT_FILE $template;
        close OUTPUT_FILE;
        print "Generate $BuildInfoCMM from ./tools/DebuggingSuite/Misc/BuildInfoTemplate.cmm\n";        
    }
    
    ### Read Template.cmm
    my $Template_cmm_file = "./tools/DebuggingSuite/Misc/Template.cmm";
    open (TEMPLATE_CMM_FILE, "<$Template_cmm_file") or &error_handler("$Template_cmm_file: Unable to open $Template_cmm_file!\n", __FILE__, __LINE__);
    {
        local $/;
        my $template_cmm_content = <TEMPLATE_CMM_FILE>;
        $hq_only_template .= &gen_hq_only_cmm_from_template_cmm($template_cmm_content);
    }
    close TEMPLATE_CMM_FILE;
    
    ### Write HQ_Only.cmm
    open (CMM_FILE, ">$CMMFILE") or &error_handler("$CMMFILE: Unable to open $CMMFILE!\n", __FILE__, __LINE__);
    print CMM_FILE $hq_only_template;
    close CMM_FILE;
    
    # [note]must be running gen_dump_address_size_template() 
    #       after generating hqonly.cmm for ClassifyRegionType()
    ### Generate OnTargetMemoryDump.cmm
    {
        my $DumpCMM = "$CMMDIR/OnTargetMemoryDump.cmm";
        my $MDxDumpCMM = "$CMMDIR/$PLATFORM\_OnTargetMemoryDump.cmm";
        if(-e $DumpCMM)
        {
            my $template = &CommonUtil::GetFileContent($DumpCMM);
            my $regions = &gen_dump_address_size_template($PLATFORM);
            $template =~ s/\[CMMAUTOGEN_DUMP_REGIONS\]/$regions/g;
            open (OUTPUT_FILE, ">$DumpCMM") or &error_handler("Unable to open $DumpCMM!\n", __FILE__, __LINE__);
            print OUTPUT_FILE $template;
            close OUTPUT_FILE;
            print "Generate $DumpCMM\n";
        }
        elsif(-e $MDxDumpCMM)
        {
            my $template = &CommonUtil::GetFileContent($MDxDumpCMM);
            my $regions = &gen_dump_address_size_template($PLATFORM);
            $template =~ s/\[CMMAUTOGEN_DUMP_REGIONS\]/$regions/g;
            open (OUTPUT_FILE, ">$DumpCMM") or &error_handler("Unable to open $DumpCMM!\n", __FILE__, __LINE__);
            print OUTPUT_FILE $template;
            close OUTPUT_FILE;
            print "Generate $DumpCMM\n";
            my $MDxDumpCMM_aref = &FindBBRelatedFile($CMMDIR, &DefineRegBaseChipName($PLATFORM), "\_OnTargetMemoryDump\.cmm\$");
            foreach my $cmm (@$MDxDumpCMM_aref)
            {
                print "delete $CMMDIR/$cmm\n";
                unlink "$CMMDIR/$cmm";
            }
        }
    }
    
}

#****************************************************************************
# 5 >>> Generate BL/EXT_BL/FOTA nocode.cmm with the same templates and different ELF files
#****************************************************************************
if (($ACTION == 2) or ($ACTION == 3) or ($ACTION == 4))
{
    my $bl_nocode_template;

    ### Copyright Statement
    $bl_nocode_template .= &template_copyright_file_header();
    
    ### verno string
    $bl_nocode_template .= &template_verno();
    
    ### CPU-related information and commands (chip-dependent)
    $bl_nocode_template .= &template_cpu_info_command($PLATFORM);
    
    ### disable watchdog (chip-dependent)
    $bl_nocode_template .= &template_disable_watchdog($PLATFORM, \%REG_BASE_DEFS);
    
    ### specify load elf
    $bl_nocode_template .= &template_specify_load_elf();

    ### set attribute for breakpoints
    $bl_nocode_template .= &template_set_bkpt_attr();

    ### clean win and endup
    $bl_nocode_template .= &template_clean_win_and_endup(0);
    
    open (BLCMM_FILE, ">$CMMFILE") or &error_handler("$CMMFILE: Unable to open $CMMFILE!\n", __FILE__, __LINE__);
    print BLCMM_FILE $bl_nocode_template;
    close BLCMM_FILE;
}

exit;

sub gen_dump_address_size_template
{  
    my ($bb) = @_;
    my $template;
        print "------------On Target Dump Region Info--------------\n";
        my $DumpRegion_aref = LISInfo::GetCMMDumpRegionInfo($bb);
        foreach my $item (@$DumpRegion_aref)
        {
            my $strBase = $item->[1];
            my $strEnd = CommonUtil::Dec2Hex(hex($item->[1])+hex($item->[2])-0x1);
            print $item->[0].":".$item->[1].",".$item->[2].", $strEnd\n";
            $template .= "print \"Dumping [$item->[0]]sys_mem_$strBase.bin\"\n"; 
            $template .= "DATA.SAVE.BINARY \"\&store_folder\\sys_mem_$strBase.bin\" $strBase--$strEnd\n";
        } 
    print "----------------------------------------------\n";
        
    return $template;    
}

#****************************************************************************
# subroutine:  reg_base_define_to_struct
# input:       $strInputFileFolder : folder of input reg_base.h
#              $strInputFile:  reg_base.h
#              $strOutputFilePath: path of output file for definitions of reg_base
#****************************************************************************
sub reg_base_define_to_struct
{
    my ($strInputFileFolder, $strInputFile, $strOutputFilePath) = @_;

    open (INPUT_FILE, "<$strInputFileFolder/$strInputFile") or &error_handler("$strInputFileFolder/$strInputFile: Unable to open $strInputFile!\n", __FILE__, __LINE__);
    open (OUTPUT_FILE, ">$strOutputFilePath") or &error_handler("$strOutputFilePath: Unable to open $strOutputFilePath!\n", __FILE__, __LINE__);

    print OUTPUT_FILE "\#include \"$strInputFile\"\n\n";
    print OUTPUT_FILE "typedef struct dummy_reg\n{\n";
    while (<INPUT_FILE>)
    {
        my ($reg);

        if (/^#define\s+(\w+)\s+\(*\w+\)*/)
        {
            $reg = $1;
            print OUTPUT_FILE "\tint $reg\_decl = $reg;\n";
        }
    }
    print OUTPUT_FILE "}\n";

    close INPUT_FILE;
    close OUTPUT_FILE;
    
    return;
}

#****************************************************************************
# subroutine:  parse_reg_base
# input:       $strInputFilePath: pre-compiled reg_base.h
#              $hrefRegBase:      hash reference to reg_base
#****************************************************************************
sub parse_reg_base
{
    my ($strInputFilePath, $hrefRegBase) = @_;

    open (INPUT_FILE, "<$strInputFilePath") or &error_handler("$strInputFilePath: Unable to open $strInputFilePath!\n", __FILE__, __LINE__);

    while (<INPUT_FILE>)
    {
        if (/\s*int\s+(\w+)\_decl\s+\=\s+\((.*)\);/)
        {
            my $reg = uc($1);
            my $nDecl = eval($2);
            $hrefRegBase->{$reg} = CommonUtil::Dec2Hex($nDecl);
        }
    }

    close INPUT_FILE;
    
    return;
}

#****************************************************************************
# subroutine:  get_cpu_type
# input:       $bb: platform
# output:      CPU type string
#****************************************************************************
sub get_cpu_type
{
    my ($bb) = @_;
    
    ### Determine CPU type
    my $strCPUType;
    if (&sysUtil::is_arm7($bb))
    {
        $strCPUType = "ARM7EJS";
    }
    elsif (&sysUtil::is_arm9($bb))
    {
        $strCPUType = "ARM926EJ";
    }
    elsif (&sysUtil::is_arm11($bb))
    {
        $strCPUType = "ARM1176JZ";
    }
    elsif (&sysUtil::is_CR4($bb))
    {
        $strCPUType = "CortexR4";
    }
    else
    {
        &error_handler("$MAKEFILE: Unsupported platform $bb!\n", __FILE__, __LINE__);
    }
    
    return $strCPUType;
}
#****************************************************************************
# subroutine:  gen_info_cmm_from_template
# input:       
# output:      
#****************************************************************************
sub gen_info_cmm_from_template
{
    my ($org_bb, $strBuildFolder, $strELFPathInCMM, $strBinName, $CMMDIR, $strDSPBinName) = @_;
    my $bb = &DefineRegBaseChipName($org_bb);
    if(&FileInfo::is("SMART_PHONE_CORE", "MODEM_ONLY"))
    {#modem only load, do copy bin
        &CopyBLBin($bb, $strBuildFolder);
    }
    &GenInfoTemplate($org_bb, $CMMDIR, $strELFPathInCMM, $strBinName, $strDSPBinName); # always generate it if needed
}

sub CopyBLBin  #called by gen_info_cmm_from_template
{ # get bin path, copy bin
    my ($bb, $strDestBinFolder) = @_; # $bb= e.g. MT6589, not MT6589_MD2
    $strDestBinFolder .= "/";
    my $strBinFolder = "./service/bootloader_bin/";
    my $Bins_aref = &FindBBRelatedFile($strBinFolder, $bb, "\.elf\$|\.bin\$");
    foreach my $bin (@$Bins_aref)
    {
        print "copy ".$strBinFolder.$bin." -> ". $strDestBinFolder.$bin."\n";
        copy($strBinFolder.$bin, $strDestBinFolder.$bin);
    }
}

sub GenInfoTemplate #called by gen_info_cmm_from_template
{
    my ($org_bb, $CMMDIR, $strELFPathInCMM, $strBinName, $strDSPBinName) = @_; # bb=e.g.MT6589_MD1, not MT6589
    # replace .\tools\DebuggingSuite\Scripts\ChipDependent\xxchip\*Info.cmm
    my $TemplateFolder = "$CMMDIR/";
    my $Files_aref = &FindBBRelatedFile($TemplateFolder, $org_bb, "_Info\.cmm\$");
    _GenInfoTemplate($org_bb, $CMMDIR, $strELFPathInCMM, $strBinName, $strDSPBinName, $Files_aref,$TemplateFolder);
    # replace .\tools\DebuggingSuite\Scripts\Misc\*chip*.cmm
    my $TemplateFolder = "./tools/DebuggingSuite/Misc/";
    my $Files_aref = &FindBBRelatedFile($TemplateFolder, $org_bb, "\.cmm\$");
    _GenInfoTemplate($org_bb, $CMMDIR, $strELFPathInCMM, $strBinName, $strDSPBinName, $Files_aref,$TemplateFolder);
}
sub _GenInfoTemplate #called by GenInfoTemplate
{
    my ($org_bb, $CMMDIR, $strELFPathInCMM, $strBinName, $strDSPBinName, $Files_aref, $TemplateFolder) = @_; # bb=e.g.MT6589_MD1, not MT6589
    foreach my $file(@$Files_aref)
    {
        my $strDestPath = "$CMMDIR/$file";
        my $template = &CommonUtil::GetFileContent($TemplateFolder.$file);
        $template = &Gen_Info_CMMContent($org_bb, $template, $strELFPathInCMM, $strBinName, $strDSPBinName);
        open (OUTPUT_FILE, ">$strDestPath") or &error_handler("Unable to open $strDestPath!\n", __FILE__, __LINE__);
        print OUTPUT_FILE $template;
        close OUTPUT_FILE;
        print "Generate $strDestPath from $TemplateFolder$file\n";
    }
}
sub FindBBRelatedFile 
{
    my ($Folder, $bb, $FileExtension) = @_;
    opendir( my $DIR, $Folder) || &sysUtil::sysgen_die("Can't open $Folder!", __FILE__, __LINE__);
    my @Files = grep { /$bb/i and /$FileExtension/i} readdir( $DIR );
    closedir $DIR; 
    return \@Files;
}

sub Gen_Info_CMMContent #called by gen_info_cmm_from_template
{
    my ($org_bb, $template, $strELFPath, $strBinName, $strDSPBinName) = @_;
    my $strBinPath = dirname($strELFPath)."/".$strBinName;
    if(-d $strBinPath)
    {
        $strBinPath = $strBinPath."/ROM";
        $strDSPBinName = $strBinPath."/".$strDSPBinName if($strDSPBinName ne "");
    }
    else
    {
        $strDSPBinName = dirname($strELFPath)."/".$strDSPBinName if($strDSPBinName ne "");
    }
    my $nChipSelect = 0;
    if($org_bb =~ /_MD(\d)/i)
    {
        $nChipSelect = $1;
    }

    $template =~ s/\[CMMAUTOGEN_ChipSelect\]/$nChipSelect/g;
    $template =~ s/\[CMMAUTOGEN_ELFPath\]/$strELFPath/g;
    $template =~ s/\[CMMAUTOGEN_SrcPath\]/..\/..\/..\/../g;
    $template =~ s/\[CMMAUTOGEN_BINPath\]/$strBinPath/g;
    $template =~ s/\[CMMAUTOGEN_DSPBINPath\]/$strDSPBinName/g;
    my $cmmgen_verno = &template_verno();
    $template =~ s/\[CMMAUTOGEN_VERNO\]/$cmmgen_verno/g;
    
    return $template;
}

sub Gen_bb_reg_content
{
    my ($reg_base_href) = @_;
    my $template;
    foreach my $key (keys %$reg_base_href)
    {
        my $value = $reg_base_href->{$key};
        $template .= "GLOBAL &$key\n&$key=($value)\n";    
    }
    return $template;    
}

#****************************************************************************
# subroutine:  gen_hq_only_cmm_from_template_cmm
# input:       $strInputContent: one line from Template.cmm to be replaced into HQ_Only.cmm
# output:      replaced HQ_Only.cmm line
#****************************************************************************
sub gen_hq_only_cmm_from_template_cmm
{
    my ($strInputContent) = @_;

    my $strReplacedContent = $strInputContent;

    ### Replace [CMMGEN_VERNO] with template_verno
    my $cmmgen_verno = &template_verno();
    $strReplacedContent =~ s/\[CMMGEN_VERNO\]/$cmmgen_verno/g;
    
    ### Replace [ARM] with the correct CPU
    my $strCPUType = &get_cpu_type($PLATFORM);
    $strReplacedContent =~ s/\[ARM\]/$strCPUType/g;

    ### Replace [ELF] with ELF path
    $strReplacedContent =~ s/\[ELF\]/$ELFFILE/g;

    ### Replace [PATH] with .
    $strReplacedContent =~ s/\[PATH\]/..\/..\/..\/../g;

    ### Replace [ELFPARA] with empty 
    $strReplacedContent =~ s/\[ELFPARA\]/\/ZeroSym/g;

    ### Replace [BIN_PATH] with T:
    $strReplacedContent =~ s/\[BIN_PATH\]/T:/g;

    ### Replace [DBGSUITE_PATH] with tools\\DebuggingSuite
    $strReplacedContent =~ s/\[DBGSUITE_PATH\]/..\\..\\..\\..\\tools\\DebuggingSuite/g;

    ### Replace [DBG_BUTTON] with GPRS/UAS buttons
    my $DBG_BUTTON= <<"__TEMPLATE";
menu.reprogram &DBGSUITE_PATH\\Misc\\Assistant
menu.reprogram gprs
menu.reprogram uas
__TEMPLATE
    $strReplacedContent =~ s/\[DBG_BUTTON\]/$DBG_BUTTON/g;
    
    ### before using all dump information, parse lis/sym first:
    &LISInfo::ClassifyRegionType(\%MAKEFILE_OPTIONS);
    
    ### Replace [DATA_COPY_TO_VM] with CODE region list
    my $strDATA_COPY_TO_VM = &gen_DATA_COPY_TO_VM();
    $strReplacedContent =~ s/\[DATA_COPY_TO_VM\]/$strDATA_COPY_TO_VM/g;

    ### Replace [ASSIGN_VERNO_INFO] with verno info assignment
    my $strASSIGN_VERNO_INFO = &get_version_from_elf_template();
    $strReplacedContent =~ s/\[ASSIGN_VERNO_INFO\]/$strASSIGN_VERNO_INFO/g;
    ### Replace [BINARY] with loading memory dump regions
    my $strBinary = &gen_dump_regions_template();
    $strReplacedContent =~ s/\[BINARY\]/$strBinary/g;
    
    ### Replace [CHECK_CODE]
    my $strSAVE_CHECK_CODE_CMD = &gen_SAVE_CHECK_CODE_CMD();
    $strReplacedContent =~ s/\[CHECK_CODE\]/$strSAVE_CHECK_CODE_CMD/g;
    
    print "strReplacedContent=$strReplacedContent" if ($DebugPrint == 1);
    return $strReplacedContent;
}
sub gen_DATA_COPY_TO_VM
{
    my $template;
    my $Region_aref = LISInfo::GetDumpCodeRegions(\%MAKEFILE_OPTIONS);
    foreach my $RegionName (@$Region_aref)
    {
        if($RegionName =~ /0x/)
        {#workaround for VECTOR_TABLE dump region
            $template .= "data.copy $RegionName--($RegionName+0x200) VM:$RegionName\n";
        }
        else
        {
            $template .= "data.copy Load\$\$$RegionName\$\$Base--(Load\$\$$RegionName\$\$Base+Image\$\$$RegionName\$\$Length) VM:Image\$\$$RegionName\$\$Base\n";
        }
    }
    return $template;
}

sub gen_SAVE_CHECK_CODE_CMD
{
    my $template;
    my $Region_aref = LISInfo::GetDumpCodeRegions(\%MAKEFILE_OPTIONS);
    my $i = 0;
    foreach my $RegionName (@$Region_aref)
    {
        $template .= '&command_count=&command_count+1'."\n" if($i!=0);
        my ($strBase, $strLength, $strHintName) = (undef, undef, "ROM_CODE");
        if($RegionName =~ /0x/)
        {#workaround for VECTOR_TABLE dump region
            ($strBase, $strLength) = ($RegionName, "0x200");
        }
        else
        {
            ($strBase, $strLength) = ("Image\$\$$RegionName\$\$Base", "Image\$\$$RegionName\$\$Length");
            $strHintName = "INT_CODE" if($RegionName =~/INTSRAM/i);
        }

        my $strDataSet = <<"__TEMPLATE";
DATA.SET VM:(&pool_addr+&command_size*&command_count) %LONG 0x1 ; op code
DATA.SET VM:(&pool_addr+&command_size*&command_count+0x4) %LONG $strBase ; start address
DATA.SET VM:(&pool_addr+&command_size*&command_count+0x8) %LONG $strLength ; length
DATA.SET VM:(&pool_addr+&command_size*&command_count+0xC) "$strHintName" 0x0 ; name
__TEMPLATE
        $template .= $strDataSet;
        $i++;
    }
    
    if(FileInfo::isnot("SW_BINDING_SUPPORT", "NONE"))
    {
        my $strDataSet = <<"__TEMPLATE";
&command_count=&command_count+1
; bypass INT_IntializeSystemMemory in ROM_CODE
DATA.SET VM:(&pool_addr+&command_size*&command_count) %LONG 0xFFFFFFFF ; op code
DATA.SET VM:(&pool_addr+&command_size*&command_count+0x4) %LONG INT_IntializeSystemMemory ; start address
DATA.SET VM:(&pool_addr+&command_size*&command_count+0x8) %LONG Y.SIZEOF(INT_IntializeSystemMemory) ; length
DATA.SET VM:(&pool_addr+&command_size*&command_count+0xC) "BYPASS" 0x0 ; name
__TEMPLATE
        $template .= $strDataSet;
    }
    
    if(FileInfo::is("BOOT_CERT_SUPPORT", "BOOT_CERT_V2"))
    {
        my $strDataSet = <<"__TEMPLATE";
&command_count=&command_count+1
; bypass g_SRD_INFO in ROM_CODE
DATA.SET VM:(&pool_addr+&command_size*&command_count) %LONG 0xFFFFFFFF ; op code
DATA.SET VM:(&pool_addr+&command_size*&command_count+0x4) %LONG g_SRD_INFO ; start address
DATA.SET VM:(&pool_addr+&command_size*&command_count+0x8) %LONG Y.SIZEOF(g_SRD_INFO) ; length
DATA.SET VM:(&pool_addr+&command_size*&command_count+0xC) "BYPASS" 0x0 ; name
__TEMPLATE
        $template .= $strDataSet;
    }
    return $template;
}

sub get_version_from_elf_template
{
    my $template;
    my $strRegionName = "PRIMARY_CACHED_EXTSRAM";
    if(!&LISInfo::IsRegionExistent($strRegionName) and &LISInfo::IsRegionExistent("CACHED_EXTSRAM"))
    {
        $strRegionName = "CACHED_EXTSRAM";
    }
    elsif(!&LISInfo::IsRegionExistent("CACHED_EXTSRAM") and &LISInfo::IsRegionExistent("EXTSRAM"))
    {
        $strRegionName = "EXTSRAM";
    }
    elsif(!&LISInfo::IsRegionExistent("EXTSRAM") and &LISInfo::IsRegionExistent("INTSRAM_DATA"))
    {
        $strRegionName = "INTSRAM_DATA";
    }
    else
    {
        &error_handler("Can't judge verno in which section", __FILE__, __LINE__);            
    }
    
    $template = <<"__TEMPLATE";
&ELF_VERNO_ADDR=V.VALUE((int)&RELEASE_VERNO_RW\$\$Base - (int)&Image\$\$$strRegionName\$\$Base + (int)&Load\$\$$strRegionName\$\$Base)
&ELF_BRANCH_ADDR=V.VALUE((int)&RELEASE_BRANCH_RW\$\$Base - (int)&Image\$\$$strRegionName\$\$Base + (int)&Load\$\$$strRegionName\$\$Base)
&ELF_BTIME_ADDR=V.VALUE((int)&BUILD_TIME_RW\$\$Base - (int)&Image\$\$$strRegionName\$\$Base + (int)&Load\$\$$strRegionName\$\$Base)
__TEMPLATE
    return $template;
}

sub gen_dump_regions_template
{
    my $template;
    my $DumpRegions_ref = &LISInfo::GetDumpExeRegions(\%MAKEFILE_OPTIONS);
    my $BIN_PATH = $BUILDDIR ."\\". $MAUI_BIN;
    print "-----------------DUMP Regions-----------------\n";
    foreach my $strGroupName (keys %$DumpRegions_ref)
    {
        my $array_ref = $DumpRegions_ref->{$strGroupName};
        foreach my $RegionItem (@$array_ref)
        {
            my $RegionName = $RegionItem->[0];
            my $strBase = &LISInfo::GetDumpRegionBase($strGroupName, $RegionName, $BIN_PATH, $PLATFORM);
            print "[$strGroupName]$RegionName: $strBase\n";
            $template .= "D.LOAD.BINARY &BIN_PATH\\sys_mem_$strBase.bin $strBase /byte /nosymbol\n";
        }
    }
    print "----------------------------------------------\n";
    return $template;
}
#****************************************************************************
# subroutine:  template_copyright_file_header
#              (this template will be used by MAUI nocode.cmm, BL nocode.cmm, EXT_BL nocode.cmm, and FOTA nocode.cmm)
# output:      template of copyright file header
#****************************************************************************
sub template_copyright_file_header
{
    my $template = <<"__TEMPLATE";
; Copyright Statement:
; --------------------
; This software is protected by Copyright and the information contained
; herein is confidential. The software may not be copied and the information
; contained herein may not be used or disclosed except with the written
; permission of MediaTek Inc. (C) 2005
; 
; BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
; THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
; RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
; AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
; EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
; MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
; NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
; SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
; SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
; THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
; NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
; SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
; 
; BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
; LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
; AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
; OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
; MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
; 
; THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
; WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
; LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
; RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
; THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  template_verno
#              (this template will be used by MAUI nocode.cmm, BL nocode.cmm, EXT_BL nocode.cmm, and FOTA nocode.cmm)
# output:      template of verno and author information
#****************************************************************************
sub template_verno
{
    my $template = <<"__TEMPLATE";
; CMMAutoGen$CMMGEN_VERNO by $CMMGEN_AUTHOR

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  template_cpu_info_command
#              (this template will be used by MAUI nocode.cmm, BL nocode.cmm, EXT_BL nocode.cmm, and FOTA nocode.cmm)
# input:       $bb: platform
# output:      template of CPU-related information and commands
#****************************************************************************
sub template_cpu_info_command
{
    my ($bb) = @_;
    
    ### Determine CPU type
    my $strCPUType = &get_cpu_type($bb);
    
    my $template = "; CPU_info_command\n";
    if (&sysUtil::is_arm11($bb))
    {
        $template .= <<"__TEMPLATE_ARM11";
SYStem.RESet
SYStem.CPU $strCPUType
SYStem.JtagClock Rtck
System.Option Cflush on     ;flush the cache to avoid data consistency
System.Option ResBreak off  ;Dont hold the ARM11 core after reset
SYStem.Up
R.S PC 0x00000000

setup.IMASKHLL ON
setup.IMASKASM ON

__TEMPLATE_ARM11
    }
    elsif($bb eq "MT6290")
    {
        $template .= <<"__TEMPLATE_CR4";
SYStem.RESet
SYStem.CPU $strCPUType
System.Option Cflush on                    ; flush the cache to avoid data consistency
SYStem.JtagClock 1MHz                     ; For DAP-lite Jtag connection
System.Multicore SWDP on
SYStem.MultiCore COREBASE APB:0x80210000    ; For CoreSight
SYStem.MultiCore DEBUGACCESSPORT 1         ; Specify which port of DAP is used for access ARM Debug Registers (0~255)
SYStem.MultiCore MEMORYACCESSPORT 0        ; Specify which port of DAP is used for access Memory (0~255)
System.Option ResBreak off                 ; Turn off ResBreak option to avoid connect to target before it is ready
System.Option EnReset off
SYSTEM.OPTION WaitReset off
SYStem.Up

setup.IMASKHLL ON
setup.IMASKASM ON

__TEMPLATE_CR4
    }
    elsif (&sysUtil::is_CR4($bb))
    {
        my %COREBASE_tbl = 
        (
            "MT6290" => "0x80210000",
        );
        my $COREBASE = $COREBASE_tbl{$bb};
        $template .= <<"__TEMPLATE_CR4";
SYStem.RESet
SYStem.CPU $strCPUType
System.Option Cflush on                    ; flush the cache to avoid data consistency
SYStem.JtagClock 10MHz                     ; For DAP-lite Jtag connection
System.Multicore SWDP on
SYStem.MultiCore COREBASE APB:$COREBASE    ; For CoreSight
SYStem.MultiCore DEBUGACCESSPORT 1         ; Specify which port of DAP is used for access ARM Debug Registers (0~255)
SYStem.MultiCore MEMORYACCESSPORT 0        ; Specify which port of DAP is used for access Memory (0~255)
System.Option ResBreak off                 ; Turn off ResBreak option to avoid connect to target before it is ready
System.Option EnReset on
SYStem.Up

setup.IMASKHLL ON
setup.IMASKASM ON

__TEMPLATE_CR4
    }
    else
    {
        $template .= <<"__TEMPLATE_OTHER";
SYStem.RESet
SYStem.CPU $strCPUType
SYStem.JtagClock RTCK.
sys.o cflush on
SYStem.Up
setup.IMASKHLL ON
setup.IMASKASM ON

__TEMPLATE_OTHER
    }

    return $template;
}

#****************************************************************************
# subroutine:  template_disable_watchdog
#              (this template will be used by MAUI nocode.cmm, BL nocode.cmm, EXT_BL nocode.cmm, and FOTA nocode.cmm)
# input:       $bb: platform
#              $hrefRegBase: hash reference of reg_base
# output:      template of disabling watchdog commands
#****************************************************************************
sub template_disable_watchdog
{
    my ($bb, $hrefRegBase) = @_;
    
    ### Get RGU_Base
    my $strRGUBaseAddr = $hrefRegBase->{'RGU_BASE'};
    $strRGUBaseAddr = "0xBF820100" if($bb eq "MT6290");

    my $template = <<"__TEMPLATE";
; disable_watchdog
D.S SD:$strRGUBaseAddr %LE %LONG 0x55000000

__TEMPLATE

    my %AP_WDT_tbl = 
    (
        "TK6280" => "0x61050000",
        "MT6280" => "0xA0030000",
    );
    my $AP_WDT = $AP_WDT_tbl{$bb};
    my $template_AP_WDT = <<"__TEMPLATE_AP_WDT";
; MD WDT
D.S SD:$strRGUBaseAddr %LE %WORD 0x2220

; AP WDT
D.S SD:$AP_WDT %LE %WORD 0x2220

__TEMPLATE_AP_WDT

    if (exists $AP_WDT_tbl{$bb})
    {
        return $template_AP_WDT;
    }
    else
    {
        return $template;
    }
}

#****************************************************************************
# subroutine:  template_bypass_ctirq1_check
#              (this template will be used by MAUI nocode.cmm)
# input:       $hrefRegBase: hash reference of reg_base
# output:      template of bypass CTIRQ1 precision check
#****************************************************************************
sub template_bypass_ctirq1_check
{
    my ($hrefRegBase) = @_;
    
    ### Get BSI_Base
    my $nBSIBaseAddr = hex($hrefRegBase->{'BSI_BASE'});
    my $strBSIBaseAddr1 = sprintf("0x%08X", $nBSIBaseAddr+8);
    my $strBSIBaseAddr2 = sprintf("0x%08X", $nBSIBaseAddr+16);

    my $template = <<"__TEMPLATE";
; bypass_CTIRQ1_precision_check
; Avoiding assert at CTIRQ1/2
D.S SD:$strBSIBaseAddr1 %LE %WORD 0xABCD
D.S SD:$strBSIBaseAddr2 %LE %WORD 0x0003     ; bit0: disable CTIRQ1/2 timing check

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  template_disable_dabort_pabort_bkpt
#              (this template will be used by MAUI nocode.cmm)
# input:       $bb:              platform
#              $hrefMakefileOpt: hash reference of makefile options
# output:      template of disabling DABORT and PABORT breakpoint
#****************************************************************************
sub template_disable_dabort_pabort_bkpt
{
    my ($bb, $hrefMakefileOpt) = @_;
    
    if (!FileInfo::is_NOR($hrefMakefileOpt))
    {
        if ((&sysUtil::is_arm9($bb)==1) or (&sysUtil::is_arm11($bb)==1) or ($bb eq 'MT6270A'))
        {
            my $template = <<"__TEMPLATE";
; disable DABORT and PABORT breakpoint
tronchip.set dabort off
tronchip.set pabort off

__TEMPLATE

            return $template;
        }
    }
    
    return;
}

#****************************************************************************
# subroutine:  template_specify_load_elf
#              (this template will be used by MAUI nocode.cmm, BL nocode.cmm, EXT_BL nocode.cmm, and FOTA nocode.cmm)
# input:       
# output:      template of loading ELF
#****************************************************************************
sub template_specify_load_elf
{
    my $template = <<"__TEMPLATE";
; specify_load_elf
D.LOAD.ELF $ELFFILE \/RELPATH \/PATH "..\/..\/..\/.." \/nocode
__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  template_add_utility_for_debug
#              (this template will be used by MAUI nocode.cmm)
# input:
# output:      template of debugging utilities
#****************************************************************************
sub template_add_utility_for_debug
{
    my $template = <<"__TEMPLATE";
; add_utility_for_debugging
menu.reset
GLOBAL &DBGSUITE_PATH
&DBGSUITE_PATH=\"..\\..\\..\\..\\tools\\DebuggingSuite\"

if version.build()==0x100000 
(
    task.config &DBGSUITE_PATH\\Misc\\NUCLEUS
)
else
(
    if y.exist(TCT_Schedule)
    (
        task.config &DBGSUITE_PATH\\Misc\\NUCLEUS
        menu.reprogram &DBGSUITE_PATH\\Misc\\NUCLEUS
    )
    else
    (
        task.config &DBGSUITE_PATH\\Misc\\NUCLEUS_V2
        menu.reprogram &DBGSUITE_PATH\\Misc\\NUCLEUS_V2
    )
)

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  template_add_button_for_debug
#              (this template will be used by MAUI nocode.cmm)
# input:       $hrefMakefileOpt: hash reference of makefile options
# output:      template of debugging buttons
#****************************************************************************
sub template_add_button_for_debug
{
    my ($bb, $hrefMakefileOpt) = @_;
    
    ### Determine whether to load Debug button
    my $debug_button_template;
    if ($bb eq "MT6290")
    {        
        $debug_button_template = <<"__TEMPLATE_DEBUG_BUTTON";
menu.reprogram DebugGo
__TEMPLATE_DEBUG_BUTTON
    }
    $debug_button_template .= "menu.reprogram Cortex-R_MPU_View\n" if(&sysUtil::is_CR4($bb));
    
    ### Determine whether to load GPRS/UAS buttons
    my $ps_button_template;
    if ($hrefMakefileOpt->{'MODE'} eq 'GPRS')
    {
        $ps_button_template = <<"__TEMPLATE_PS_BUTTON";
menu.reprogram gprs
__TEMPLATE_PS_BUTTON
    }
    elsif ($hrefMakefileOpt->{'MODE'} eq 'UMTS')
    {
        $ps_button_template = <<"__TEMPLATE_PS_BUTTON";
menu.reprogram gprs
menu.reprogram uas
__TEMPLATE_PS_BUTTON
    }
    
    my $template = <<"__TEMPLATE";
menu.reprogram InTargetReset
menu.reprogram l1assertbypass
$debug_button_template
$ps_button_template

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  template_set_bkpt_attr
#              (this template will be used by MAUI nocode.cmm, BL nocode.cmm, EXT_BL nocode.cmm, and FOTA nocode.cmm)
# input:       
# output:      template of setting breakpoints attribute
#****************************************************************************
sub template_set_bkpt_attr
{
    my $template = <<"__TEMPLATE";
; setting attribute of breakpoints
Break.Select Program OnChip
Break.Select Hll OnChip
Break.Select Spot OnChip
Break.Select Read OnChip
Break.Select Write OnChip

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  template_clean_win_and_endup
#              (this template will be used by MAUI nocode.cmm, BL nocode.cmm, EXT_BL nocode.cmm, and FOTA nocode.cmm)
# input:       $bWinClear = 1: gen winclear, 0 or undef: not to generate winclear
# output:      template of clean win and endup
#****************************************************************************
sub template_clean_win_and_endup
{
    my ($bWinClear) = @_;
    my $winclear = undef;
    if($bWinClear == 1){
    $winclear = <<"__TEMPLATE";
; clean_win
winclear
__TEMPLATE
    }
    my $template = <<"__TEMPLATE";
$winclear
; endup
d.l
enddo

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  template_utility_description
#              (this template will be used by auto_reset.cmm and InTargetReset.cmm)
# input:       $strFileName: string of cmm file name
#              $strDesc:     string of descriptions
# output:      template of utility cmm header description string
#****************************************************************************
sub template_utility_description
{
    my ($strFileName, $strDesc) = @_;
    
    my $template = <<"__TEMPLATE";
; $strFileName
; $strDesc

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  template_in_target_reset
#              (this template will be used by auto_reset.cmm)
# input:
# output:      template of in-target reset
#****************************************************************************
sub template_in_target_reset
{
    my $template = <<"__TEMPLATE";
; In Target reset
SYStem.Mode EmulExt
Register.RESet

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  template_go
#              (this template will be used by auto_reset.cmm)
# input:
# output:      template of GO
#****************************************************************************
sub template_go
{
    my $template = <<"__TEMPLATE";
GO

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  template_set_bkpt_at_scheduler
#              (this template will be used by Debug_Go.cmm)
# input:       $hrefMakefileOpt: hash reference of makefile options
# output:      template of setting breakpoint at scheduler and go until break at scheduler
#****************************************************************************
sub template_set_bkpt_at_scheduler
{
    my ($hrefMakefileOpt) = @_;
    
    ### Determine scheduler symbol
    my $strScheduler;
    if ($hrefMakefileOpt->{'RTOS'} eq 'NUCLEUS')
    {
        $strScheduler = "TCT_Schedule";
    }
    elsif ($hrefMakefileOpt->{'RTOS'} eq 'NUCLEUS_V2')
    {
        $strScheduler = "TCCT_Schedule";
    }
    else
    {
        &error_handler("$MAKEFILE: Unsupported RTOS in makefile!\n", __FILE__, __LINE__);
    }
    
    ### Determine actions to be done during break at scheduler
    my $action_template;
    if (($hrefMakefileOpt->{'CUST_CODE'} eq 'TC01') and ($hrefMakefileOpt->{'DEMO_PROJECT'} eq 'TRUE'))
    {
        $action_template = &template_debug_go_disable_dcm_sm_l1_wdt(\%REG_BASE_DEFS);
    }
    
    my $template = <<"__TEMPLATE";
b.s $strScheduler
go

wait !run()

if r(pc)==address.offset($strScheduler)
(
    ; print "stop at $strScheduler"

$action_template

    b.d $strScheduler
    go
    ; d.l
)

enddo

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  template_debug_go_disable_dcm_sm_l1_wdt
#              (this template will be used by Debug_Go.cmm and will be called by template_set_bkpt_at_scheduler)
# input:       $hrefRegBase: hash reference of reg_base
# output:      template of disabling DCM, SM, L1_ASSERT_BYPASS, and WDT
#****************************************************************************
sub template_debug_go_disable_dcm_sm_l1_wdt
{
    my ($hrefRegBase) = @_;
    
    ### Get RGU_Base
    my $strRGUBaseAddr = $hrefRegBase->{'RGU_BASE'};

    my $template = <<"__TEMPLATE";
    ; disable DCM
    if Y.EXIST(dcm)
    (
        d.s address.offset(dcm) %LE %LONG 0x1
    )
    
    ; disable SleepMode
    if Y.EXIST(sm)
    (
        d.s address.offset(sm) %LE %LONG 0x1
    )
    
    ; disable L1 timing check
    DO l1timing_check_disabled
    
    ; disable WatchDog
    d.s SD:$strRGUBaseAddr %LE %WORD 0x2200
__TEMPLATE

    return $template;
}

sub DefineRegBaseChipName
{
    my ($strChipName) = @_;
    if($strChipName =~ /MT6589/i)
    {
        $strChipName = "MT6589";
    }
    elsif($strChipName =~ /MT6752/i)
    {
        $strChipName = "MT6752";
    }
    return $strChipName;
}

#****************************************************************************
# subroutine:  error_handler
# input:       $error_msg:     error message
#****************************************************************************
sub error_handler
{
    my ($strErrorMsg, $strFile, $strLine) = @_;
    
    my $strFinalErrorMsg = "CMMGEN ERROR: $strErrorMsg at $strFile line $strLine\n";
    print $strFinalErrorMsg;
    die $strFinalErrorMsg;
}
