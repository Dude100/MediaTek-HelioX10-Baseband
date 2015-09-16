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
#*   scatGenLib.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script designed as module to be include by top level perl script
#*
#* Author:
#* -------
#*   JI Huang  (mtk01077)
#*
#****************************************************************************/
#use strict;
BEGIN { push @INC, './tools/' }  # add additional library path
use sysGenUtility;                 #pm file name without case sensitivity
use POSIX qw(floor ceil);
use scatFrame;
use CommonUtility;
use File::Basename;
use tools::pack_dep_gen;
PrintDependModule();
my  $g_nFlashSize = 0;
my  $feature_query_function_ptr;
my  $norflash_info_blk_href;
my  $nor_device_exist;
my  $fota_cfg_href;
my  $bb_folder;
my  $themf;
my  $bl_exist;
my  $Is_Flashtool_Layout = 0; #$Is_Flashtool_Layout : 0=normal layout, 1=flashtool required layout
my  $dummy_scatter;
my  $mf_option_ref;
my  $g_nfb_or_emb;

my  $feature_config_href;
my  $g_region_before_cached_dummy_end = undef;
my  $mf_option_ref = undef;

1;
#***************************************************************************
# global variables
#***************************************************************************
my $g_config_cs_swap = 0;
my $g_config_rom_offset = 0;
#***************************************************************************


#****************************************************************************
# MAIN INTERFACE
# input: 
#          arg1 : a function pointer to query feature 
#          arg2 : base band chip
#          arg3 : a hash reference to query flash geometry
#          arg4 : ram size
#****************************************************************************
sub scatGen_main
{
    my ($func, $bb, $g_nFlashSize, $flash_blk_href, $rs, $nor_device, $fota_cfg, 
        $bb_path, $makefile, $need_build_bootloader, $mem_dev_h_cfg, 
        $IsFlashtoolLayoutInput, $use_dummy_scatter, $feature_config, $nFactoryBinSize) = @_;
    $feature_query_function_ptr = $func;
    $norflash_info_href         = $flash_href;
    $nor_device_exist           = $nor_device;
    $fota_cfg_href              = $fota_cfg;
    $bb_folder                  = $bb_path;
    $themf                      = $makefile;
    $bl_exist                   = $need_build_bootloader;
    $Is_Flashtool_Layout        = $IsFlashtoolLayoutInput; #$Is_Flashtool_Layout : 0=normal layout, 1=flashtool required layout
    $dummy_scatter              = $use_dummy_scatter;
    $g_config_rom_offset        = 0;
    $g_config_cs_swap           = 0;
    $feature_config_href        = $feature_config;
    $mf_option_ref              = &FileInfo::GetMakeFileRef($makefile);
    

    if (defined &$func('nand_flash_booting') and &$func('nand_flash_booting') ne 'NONE')
    {
    	  $g_nfb_or_emb = &$func('nand_flash_booting');
    }
    elsif (defined &$func('emmc_booting') and &$func('emmc_booting') ne 'NONE')
    {
    	  $g_nfb_or_emb = &$func('emmc_booting');
    }
    else
    {
          $g_nfb_or_emb = 'NONE';
    }
    my $multibin = &$func('multiple_binary_files');
    my $security = &$func('secure_support');
    my $fota     = &$func('fota_enable');
    my $usbdl    = &$func('usb_download_in_bl');
    my $zimage   = &$func('zimage_support');
    my $boot_cert = &$func('boot_cert_support');
    my $dcm_compression_support = &$func('dcm_compression_support');
    my $fast_boot = &$func('split_binary_support');
    
    my $compiler = &$func('compiler');
    if($compiler ne "RVCT")
    {
        &sysUtil::sysgen_die("tools/scatGenLib.pl: Unsupported Compiler: $compiler !", __FILE__, __LINE__);
    }

    # Layout configuration
    &config_setup($bb);
    my $flash_size   = $flash_href->{'AVAILABLE_SIZE'};

    # SW Feature dispatch decision tree
    my $output_result;

    if (&FileInfo::is_SmartPhone($mf_option_ref) == 1 
      or $g_nfb_or_emb eq "SINGLE")
    {        
        $output_result .= &layout9($bb, $rs);
        return $output_result;
    }

    ### for SV5, only SECURE_RO_ENABLE needs to be parsed
    if (&sysUtil::is_sv5($bb) == 1)
    {
        $security = "FALSE";
    }

    #if ($nfb_or_emb ne 'NONE')
    if(&isNAND($func))
    {
        if ($bb eq 'MT6253')
        {
            &sysUtil::sysgen_die("tools/scatGenLib.pl: Unsupported Feature Combination NFB on platform $bb!", __FILE__, __LINE__);
        }
          
        if (defined $zimage and $zimage eq 'TRUE')
        {
            &sysUtil::sysgen_die("tools/scatGenLib.pl: Unsupported Feature Combination : ZIMAGE + NFB!", __FILE__, __LINE__);
        }

        # NAND FLASH BOOTING (Phase 1)
        if (&sysUtil::is_arm11($bb) == 1)
        {
            $output_result .= &layout10($bb);
        }
        
        # NAND FLASH BOOTING (Phase 2)
        if (defined $fota and $fota eq 'FOTA_DM')
        {
            $output_result .= &layout6($bb);
        }
        # Add FACTORY_COMBINE layout
        if(defined $fast_boot and $fast_boot eq 'FACTORY_COMBINE')
        {
            $output_result .= &layout16($bb, $g_nfb_or_emb, 0, $nFactoryBinSize, $rs);
        }

        $output_result .= &layout1($bb, undef, $rs, $multibin, $security, $fota, $boot_cert, $fast_boot);

        my $secure_ro_enable = &$func('secure_ro_enable');
        if ((&sysUtil::is_sv5($bb) == 1) and (defined $secure_ro_enable and $secure_ro_enable eq 'TRUE'))
        {
            $output_result .= &layout11($bb);
        }
    }
    else
    {
        if (($bb eq 'MT6276') or  ($bb eq 'MT6268'))
        {
            &sysUtil::sysgen_die("tools/scatGenLib.pl: Unsupported Feature Combination NOR booting on platform $bb!", __FILE__, __LINE__);
        }

        # NOR TRADITIONAL BOOTING (Phase 1)
        if (defined $zimage and $zimage eq 'TRUE')
        {
            if ((defined $multibin and $multibin eq 'TRUE') or (defined $fota and $fota eq 'TRUE'))
            {
                &sysUtil::sysgen_die("tools/scatGenLib.pl: Unsupported Feature Combination : ZIMAGE + MBA or FOTA!", __FILE__, __LINE__);
            }
        }
        if ($fota eq 'FOTA_DM')
        {
            if (defined $alice and $alice eq 'TRUE')
            {
                &sysUtil::sysgen_die("tools/scatGenLib.pl: Unsupported Feature Combination : FOTA + ALICE!", __FILE__, __LINE__);
            }        	
        }        
        
        if (&sysUtil::is_sv5($bb) == 1)
        {
            $output_result .= &layout13($bb);
        }
        elsif ($bl_exist eq 'TRUE')
        {
            $output_result .= &layout4($bb);
        }
        # Add NOR Combinaion Bin Layout except FOTA case
        if (defined $fast_boot and $fast_boot eq 'FACTORY_COMBINE' and (!defined $fota or $fota ne 'FOTA_DM'))
        {
            $output_result .= &layout16($bb, $g_nfb_or_emb, &lv_rom_fbase(), $nFactoryBinSize, $rs);
        }

        # NOR TRADITIONAL BOOTING (Phase 2)
        if ($fota eq 'FOTA_DM')
        {   # FOTA only or FOTA+SECURE or FOTA+MBA or FOTA+MBA+SECURE
        	$output_result .=  &layout7($bb, $flash_size, $rs, $boot_cert, $fast_boot, $nFactoryBinSize);
        }
        elsif(&sysUtil::is_XIP_Shadowing($bb))
        {
            $output_result .= &layout9($bb, $rs);
        }
        elsif (($multibin eq 'TRUE') && ($security eq 'TRUE'))
        {   # MBA+SECURE or MBA+SECURE+DCMP
            $output_result .= &layout5($bb, $flash_size, $rs, $boot_cert);
        }
        elsif ($multibin eq 'TRUE')
        {   # MBA + non SECURE or MBA+nonSECURE+DCMP
            $output_result .= &layout2($bb, $flash_size, $rs, $boot_cert);
        }
        elsif ((defined $zimage) and ($zimage eq 'TRUE'))
        {   # ZIMAGE only or ZIMAGE+SECURE or ZIMAGE+DCMP or ZIMAGE+DCMP+SECURE
            &sysUtil::sysgen_die("$bb_folder/custom_FeatureConfig.h: CONFIG_ZIMAGE_MAX_COMPRESSED_SIZE need to be defined when ZIMAGE_SUPPORT is turned on!", __FILE__, __LINE__)
                if (!defined($feature_config_href->{'CONFIG_ZIMAGE_MAX_COMPRESSED_SIZE'}));
            $output_result .=  &layout12($bb, $flash_size, $rs, $feature_config_href->{'CONFIG_ZIMAGE_MAX_COMPRESSED_SIZE'}, $boot_cert);
        }
        elsif(defined $dcm_compression_support and $dcm_compression_support eq 'TRUE')
        {   #DCMP or DCMP+SECURE 
        	$output_result .= &layout15($bb, $flash_size, $rs, $boot_cert);
        }
        elsif ($security eq 'TRUE')
        {
            $output_result .=  &layout3($bb, $flash_size, $rs, $boot_cert);
        }
        else
        {
            $output_result .=  &layout0($bb, $flash_size, $rs, $boot_cert);
        }

        my $secure_ro_enable = &$func('secure_ro_enable');
        if ((&sysUtil::is_sv5($bb) == 1) and (defined $secure_ro_enable and $secure_ro_enable eq 'TRUE'))
        {
            $output_result .= &layout11($bb);
        }
    }

    # Finally , return output
    return $output_result;
}

sub scatGen_verno
{
    return "m0.32" . " + scatFrame". scatFrame::scatFrame_verno() ;
    # m0.32 by mei, 20120919, Support BOOT_CERT in NFB=SINGLE
	# m0.31 by mei, 20120815, Modify obj name in SHOULDBE_EMPTYSECTION
    # m0.30 by mei, 20120807, Refactory scatGen.pl
    # m0.29 by mei, 20120726, Add * (RELEASE_VERNO_RW), * (RELEASE_BRANCH_RW), * (BUILD_TIME_RW) near by libverno.a
    # m0.28 by mei, 20120720, Modify lib name for architecture change
    # m0.27 by mei, 20120717, Move INTSRAM_PREINIT_ZI to CACHED_EXTSRAM_PREINIT_ZI
    # m0.26 by mei, 20120713, Change lib name from *xx.lib to *xx.a
    # m0.25 by mei, 20120702, Remove PrintDependency() via using tools::pack_dep_gen; PrintDependModule();
    # m0.24 by mei, 20120701, Generate EXTSRAM_FS if FS_RAMDISK=TRUE
    # m0.23 by mei, 20120628, [scatGenBL.pl]change Region name to add _NOINIT
    # m0.22 by mei, 20120614, [scatGen.pl]Not to parse custom_flash.h during nor flash booting
    # v6.32 by Carina, 20120605, [scatGen.pl]modify the base address of SDS to grow from the bottom of flash
    # v6.30 by mei, 20120604, Make CBR block aligned
    # v6.29 by mei, 20120531, Fix config_query_next_block_aligned_addr()'s bug
    # v6.28 by Carina, 20120530, GetBottomLayout() & layout1() refinement
    # v6.27 by mei, 20120530, Fix reserving too much sizes in BL layout
    # m0.21 by mei, 20120528, Support path and filename case sensitive on Linux
    # m0.20 by mei, 20120522, Set RAM base +0x0 and ALIGN 1MB on MT6280
    # m0.19 by mei, 20120522, Shrink RamDisk from 3MB to 256KB for all chips
    # v6.22 by Carina, 20120521, Modify GetBottomLayout() to fix the error of CACHED_DUMMY_END base address of layout5
    # v6.21 by Carina, 20120521, [scatGen.pl] sync the reserved size for BL in scatGen.pl and scatGenLib.pl
    # v6.20 by mei, 20120521, [scatGenBL] support READ_ONLY to set max size
    # v6.19 by mei, 20120520, Read BL/EXT_BL reserved size from custom_featureconfig.h
    #                         Remove useless ROMlength_calc()
    # v6.18 by mei, 20120519, Support read Input section first from BB folder
    # v6.16 by Carina, 20120516, Modify ZIMAGE execution name to ZIMAGE_ER to support ScatterAssert function
    # v6.15 by Carina, 20120515, Rename #define ALIGN to SetAddress
    # v6.13 by Carina, 20120513, Isolate ZImage input section
    # v6.12 by mei, 20120512, Always generate INTSRAM_DATA_PREINIT after INTSRAM_DATA 
    # v6.11 by Carina, 20120511, Modify BOTTOM_NOR_LV_Layout() to fix the error of v6.05
    # m0.18 by mei, 20120507, Add _nvram_callback_tbl into EXTSRAM_NVRAM_LTABLE
    # m0.17 by mei, 20120312, [scatGenBL.pl] change bl_bootarm.obj to bl_bootarm_rvct.obj
    # m0.16 by mei, 20120312, to support bootarm.s into bootarm_rvct.obj and ex_hdlr.obj into ex_hdlr_rvct.obj
    # m0.15 by mei, 20120416, Put 3 objects into ITCM
    # m0.14 by mei, 20120320, Support XIP Shadowing on NOR
    # m0.13 by mei, 20120212, Support different memory segments in layout9()
    # m0.12 by mei, 20120210, Support NOR and XBOOTING in layout0_rom_ev() at the same time
    # m0.11 by mei, 20120206, Pass MAKEFILE Option from scatGen to scatGenBL for is_SmartPhone()
    # m0.10 by mei, 20120203, Pass MAKEFILE Option from scatGen to scatGenLib for is_SmartPhone()
    # m0.09 by mei, 20120131, Fix scatGen.pl for SINGLE in custom_img_config_h_file_body()
    # m0.08 by mei, 20120120, Support MT6280 on NOR Layout
    # m0.07 by mei, 20120120, Support SmartPhone by query SMART_PHONE_CORE!=NONE
    # m0.06 by mei, 20120116, Support BLscatGen and set ITCM base if there is no mmsysram base  
    #                                    modify custom_img_config.h and custom_blconfig.c
    # m0.05 by mei, 20120113, Support nfb=SINGLE in scatGenLib.pl and scatGen.pl
    # m0.04 by mei, 20120108, Support MT6280    
    # m0.03 by mei, 20120508, Shrink RamDisk from 3MB to 256KB on MT6280
    # m0.02 by mei, 20120507, Move DSPTXRX_query_length to sysgenUtility.pm
    # m0.01 by mei, 20120507, [scatGenBL.pl] Rename input section name for GCC migration
    # v6.10 by Carina, 20120507, Fix the error of BOOT_CERT attribute
    # v6.09 by Carina, 20120503, Modify attribute of c libs to prevent from ambiguous link error
    # v6.08 by Carina, 20120502, MT6250D slim approaches
    # v6.07 by mei, 20120501, [scatGen.pl] Isolate all processes to be reuseable functions
    # v6.06 by Carina, 20120427, Modify the input section in DYNAMIC_COMP_MP4DEC_BODY region
    # v6.05 by Carina, 20120426, BOTTOM_NOR_LV_Layout() refinement
    # v6.04 by mei, 20120425, Get list file from specific folder
    # v6.03 by Carina, 20120425, Modify the input section in DYNAMIC_COMP_MP4ENC_BODY region
    # v6.02 by mei, 20120418, [scatGenBL] add 4 objs to EXT_READ_ONLY_INT if SERIAL_FLASH_STT_SUPPORT = TRUE
    # v6.01 by Carina, 20120417, Add OVERLAY attribute to ALICE region to avoid ROM access ALICE region before it is initialized
    # v6.00 by Carina, 20120417, Add pragma in INTSRAM_DATA_PREINIT in order to put init data transferred from bootloader
    # v5.99 by Carina, 20120417, To generate ROM_SIGNATURE_SECTION region in MT6250(sv5)
    # v5.98 by Carina, 20120413, Modify the regions of DCM with compression
    # v5.97 by Carina, 20120412, Modify the size of INTSRAM to enhance 6250 FTE performance
    # v5.96 by Carina, 20120411, Fix the error of BOTTOM_NOR_LV_Layout() in scatGenLib.pl
    # v5.95 by Carina, 20120406, Modify custom_img_config.h in scatGen.pl: do not reserve space for MBA+NOR 
    # v5.94 by Carina, 20120405, Modify the size of JUMP_TABLE to support MBA in sv5 project
    # v5.93 by Carina, 20120403, Add two regions(DYNAMIC_COMP_DAF, DYNAMIC_COMP_WAVETABLE) and delete one regions(DYNAMIC_COMP_RESAMPLE) of DCM with compression
    # v5.92 by Carina, 20120403, Phase in ALICE
    # v5.91 by Carina, 20120323, Modify scatGenBL.pl to fix the READ_WRITE_base of MT6921 NAND booting
    # v5.90 by Carina, 20120322, Support VIVA
    # v5.89 by Carina, 20120321, Support MT6250 (without VIVA)
    # v5.88 by Carina, 20120417, Support EWS to print file dependency
    # v5.87 by Carina, 20120320, Modify the template of custom_img_config.h: do not reserve space for P-MAUI/S-MAUI/ODP when MBA is on
    # v5.86 by Carina, 20120319, Add SecInfo section to Ext Bootloader scatter file in non-SV5 projects
    # v5.85 by mei, 20120319, Make sv5 ext_bootloader max size to support Card Download
    # v5.83 by mei, 20120313, Fix ram disk turn-on's bug on smart phone
    # v5.81 by Carina, 20120312, Modify the layout of DYNAMIC_CACHEDABLE regions due to MED_IN_ASM default on under all mmi version
    # v5.79 by Carina, 20120312, Modified the input section of SINGLE_BANK_CODE due to the code of SNORCODE region in bootarm.s has been moved to ex_hdlr.s
    # v5.78 by Carina, 20120309, Modify DSP_RX size of MT6250 in gsm mode to avoid DSP MPU violation occurs
    # v5.77 by Carina, 20120309, Modify scatGenBL.pl to support NAND booting of MT6921
    # v5.76 by Carina, 20120222, Support MBA new feature option  MBA_DEFAULT_BINARY
    # v5.75 by Carina, 20120222, Add to codec input sections to support MP4 ASP on ARM9 platform
    # v5.74 by Carina, 20120222, Modify the READ_ONLY_INT's address for MT6250 bring up
    # v5.73 by Carina, 20120222, Enlarge SINGEL_BANK_CODE size to 16K in BASIC load
    # v5.72.1 by Carina, 20120221, Modify DSP_TX DSP_RX size for MT6250 to reduce memory usage
    # v5.72.0 by Carina, 20120216, Add feature option to determine bn_lib.obj attribute for PM_DEMO
    # v5.71 by Carina, 20120217, Modify DSP_TX DSP_RX size for MT6250 due to the base addr need to be align with length of these to regions
    # v5.70 by Carina, 20120216, MT6250_DVT branch merge back to 11BW1132SP branch
    # v5.69 by Carina, 20120212, To change to another description for removing MT6306.lib from demand_paging region
    # v5.68 by Carina, 20120210, Remove some input sections from DEMADN_PAGING_ROM0 for VICTOR56_DEMO_BB PM_DEMO
    # v5.67 by Carina, 20120214, To exclude urlc_lisr_trace.obj from demand paging region for Luffy76 V22 sanity fail
    # v5.65 by Carina, 20120208, Remove MBA_NOR_LV_Layout and ceate BOTTOM_NOR_LV_Layout and GetBottomRegion to generate Bottom-to-top regions 
    # v5.64 by mei, 20120130, Support MT6922
    # v5.63 by mei, 20120117, Add 2 regions in DCMP if VIDEO_PLAYER_RECORDER_W_DCM=ENABLE
    # v5.62 by Carina, 20120115, To remove the threadx-releated code and templates due to the threadx is phase-out
    # v5.61 by Carina, 20120115, Add "ROM load region is block-aligned" comment in NOR case and add $bisBL parameter in query_cs1_addr()
    # v5.60 by mei, 20120112, [scatGen.pl]Not to use Project Limit if not INTER_MTK
    # v5.59 by mei, 20120111, Move some objs out of demand paging for MMI performance (response time)
    # v5.58 by mei, 20120109, [FOTAscatGen] To remove *che.lib (+RO) from INT_RO/RW region
    # v5.57 by mei, 20120108, Support TK6280 and CR4
    # v5.56 by mei, 20120108, Isolate INTSRAM CODE and DATA template
    # v5.55 by mei, 20120108, Remove cache.obj (INTERNCODE)
    # v5.54 by mei, 20120103, 1.Remove max size in DemandPaging's execution region to avoid L6407W, L6406W
    #                         2.Add ABSOLUTE in the region next to DEMAND_PAGING_ROM0_ROCODE
    # v5.53 by mei, 20120103, To put combo_flash_nor.obj, combo_flash_init.obj, custom_sfi.obj into 1st MAUI.
    # v5.52 by mei, 20120102, [FOTA scatGen]Not to generate SECURE_MAC if secure_support is not TRUE 
    # v5.51 by mei, 20120102, Revise v5.49 and v5.45
    # v5.50 by mei, 20120102, Support boot_cert_v2
    # v5.49 by mei, 20111225, Remove CodePatchCode and create a GetDummyEnd ProtoType
    # v5.48 by mei, 20111225, (L6478E)Rollback v5.46 because it's useless, and solved by --max_veneer_passes=30
    # v5.47 by mei, 20111223, Remove 55 DCM since there is no DCM in 6255
    # v5.46 by mei, 20111222, Fix v5.44(L6478E) by separating DP ROCODE regions into 20 parts and remove OVERLAY
    # v5.45 by mei, 20111216, Fix v5.41 to warn if MBA+Demand Paging's region exceeds 0xffffffff
    # v5.44 by mei, 20111215, Fix v5.43(L6478E) by combining DP ROCODE region.
    # v5.43 by mei, 20111214, Fix L6478E link error by put L6478E.obj in the end of DP ROCODE and separate DP ROCODE regions 
    # v5.42 by mei, 20111212, Fix v5.37 to put DCM regions in the end of DEMAND_PAGING_ROM0
    # v5.41 by mei, 20111212, Modify scatGen.pl to warn if MBA+DP's max size exceeds 0x7F00000
    # v5.40 by mei, 20111211, Make DemandPaging MaxSize's input from custom_FeatureConfig.h and custom_img_config.h
    # v5.39 by mei, 20111211, Support SECURE_RO in Smartphone layout 
    # v5.38 by mei, 20111211, Fix base address of LIS/BAISC load's 2nd ZI by shifting 0x800000
    # v5.37 by mei, 20111209, Put RO-DATA in the end of DEMAND_PAGING_ROM0 to prevent L6286E and seperate regions to prevent Out of Memory
    # v5.36 by mei, 20111206, Fix v5.35 and v5.32
    # v5.35 by mei, 20111205, Subtract DCMP compressed size from ROM in ZIMAGE+DCMP(+SECURE) layout
    # v5.34 by mei, 20111205, Make up input section pattern
    # v5.33 by mei, 20111130, Remove DYNAMIC_CODE15 and DYNAMIC_CODE17 for 6255
    # v5.32 by mei, 20111129, Support MBA+FOTA on nor and nand, and
    #                         support ZIMAGE+SECURE(+DCMP), DCMP+SECURE, DCMP+MBA+SECURE
    # v5.31 by mei, 20111117, Support 6255 BL security
    # v5.30 by mei, 20111116, Remove OVERLAY on EXTSRAM_TMP_PAGE_TABLE
    # v5.29 by mei, 20111115, Support all VideoCodec on arm9/11
    # v5.28 by mei, 20111115, Generate ZIMAGE_DUMMY region
    # v5.27 by Claudia, 20111110, [DPV2] Move extra obj to ROM2 to solve MMI and Audio performance issue
    # v5.26 by mei, 20111110, Set BL's READ_WRITE base address to 0x50000000
    # v5.25 by mei, 20111109, Fix v4.93 error handle
    # v5.24 by mei, 20111109, Fix v5.10 merge defect
    # v5.23 by mei, 20111109, Set BL's READ_ONLY base address to 0x0 in SV3+NOR
    # v5.22 by mei, 20111108, [DPV2]Move mre_custom.lib into demand paging
    # v5.21 by mei, 20111108, Fix a 6255NFB missing parameter bug
    # v5.20 by mei, 20111104, Add ROM_Video to enhance Video Performance
    # v5.19 by mei, 20111104, Add objs into ROM2 for DPv2 MMI performance issue
    # v5.18 by mei, 20111104, Add libs into ROM2 for DPv2 on TDD128
    # v5.17 by mei, 20111104, Add video codec libs into ROM2 for DPv2
    # v5.16 by mei, 20111103, Fix 6255 sysram size in scatGenBL.pl 
    # v5.15 by mei, 20111102, Enlarge SINGEL_BANK_CODE size to 16K in BASIC load 
    # v5.14 by mei, 20111101, Add CustVenusThemeData.obj into CUSTPACK_ROM_CONTENT
    # v5.13 by mei, 20111031, Revise v4.64 to support 6921 on scatGenBL.pl
    # v5.12 by mei, 20111031, Modify default input sections in ZIMAGE
    # v5.11 by mei, 20111031, Fix scatGen.pl for 6256 custom_img_config.h
    # v5.10 by mei, 20111028, Support 6255 NFB/NOR
    # v5.09 by mei, 20111028, Modfiy scatGen.pl to widen dummy scatter file's ram/flash size
    # v5.08 by mei, 20111027, Add load region's max_size for NFB's MBA and FOTA layout
    # v5.07 by mei, 20111026, Add *gl1.lib to support HAL
    # v5.06 by mei, 20111026, Revise v4.92
    # v5.05 by mei, 20111021, Rename resource_lang_pack_jtbl.obj to resource_lang_pack_preamble.obj
    # v5.04 by mei, 20111021, Shrink TxRx Size for 6921 and revise CACHEDDUMMYEND_query_offset()
    # v5.03 by mei, 20111020, Support usb boot trace(move some objs to 1st MAUI)
    # v5.02 by mei, 20111019, Add 2 input sections into *NVRAM_LTABLE
    # v5.01 by mei, 20111019, Revise v4.87, add some comments for v4.93, and fix bugs
    # v5.00 by mei, 20111019, Revise v4.85
    # v4.99 by mei, 20111013, Add some objs in DPv1
    # v4.98 by mei, 20111012, Revise v4.64
    # v4.97 by mei, 20111011, Shrink ram size for UMTS_TDD128
    # v4.96 by mei, 20111011, Shrink DSP share mem and remove reserved space for smartphone
    # v4.95 by mei, 20111010, Fix NFB to support BASIC
    # v4.94 by mei, 20111010, Remove phased-out chips and  ADS option
    # v4.93 by mei, 20111007, Isolate med and asm pool in scatter file for DSP shared memory
    #                         Shrink NFB scatter file spaces between regions with different attributes
    # v4.92 by mei, 20111006, Add custom_emi_*.obj into 1st MAUI and remove custom_emi_mt6256.obj out of 2nd MAUI
    # v4.91 by mei, 20111004, Enhance 6252 FTE performance
    # v4.90 by mei, 20110929, Modify scatGen.pl's template of custom_secure_config.h
    # v4.89 by mei, 20110928, Modify dcmgr.h's location for HAL
    # v4.88 by mei, 20110927, Modify zimage's input sections for VRT rendering performance
    # v4.87 by mei, 20110925, Modify scatGen.pl for 1. Phase in FileInfoParser.pm for parsing makefile
    #                         2. notifying users that gendummylis can't work with manual checked-in scatter file
    # v4.86 by mei, 20110923, Add 3 objs to DPV2's exception list
    # v4.85 by mei, 20110920, Support FastBoot
    # v4.84 by mei, 20110919, Modify scatGen.pl for custom_img_config.h's FOTA_UE_FLASH_BASE_ADDRESS
    # v4.83 by mei, 20110918, Add 3 objs to DPV2's exception list
    # v4.82 by mei, 20110917, Add NVRAM_LTABLE for 51 in DTCM
    # v4.81 by mei, 20110916, Move common functions to sysGenUtility.pm
    # v4.80 by mei, 20110907, Add DPV2 candidates
    # v4.79 by mei, 20110907, Always provide Audio lock regions in Demand Paging no matter which are in DPV1 or DPV2
    # v4.78 by mei, 20110907, rename SINGLE_BANK_CODE to INTSRAM_SINGLE_BANK_CODE in INTSRAM_type3() for 6251
    # v4.77 by mei, 20110907, Add INTSRAM_DUMMY_END in template_6253EL of INTSRAM_type1()
    # v4.76 by Claudia, Support MBA_ON_DEMAND and THIRD_ROM removal
    # v4.75 by mei, 20110906, Modify scatGen.pl for adding sds default values if its sds_support!=TRUE
    # v4.74 by Claudia, Correct RAM disk generation rule
    # v4.73 by mei, 20110905, Add NVRAM_LTABLE in all scatter files
    # v4.72 by Claudia, Refine DPv2 ROM2 candidates
    # v4.71 by Claudia, Add MP4ENC to DCM Compression
    # v4.70 by Claudia, To support custom_FeatureConfig.h
    # v4.69 by Claudia, Add audio lock region for VORBIS
    # v4.68 by Claudia, Correct Audio/Video lock regions;
    #                   Separate Video regions from ROM2 on some BB to enhance performance on DPv2; 
    #                   Refine ROM2 input sections for DPv2 (rolled-back to prevent veneer put in ROM2 issue)
    #                   Change MBA input regions to +RO-CODE, +RO-DATA to prevent ambiguous link error when combined with DPv2
    # v4.67 by Claudia, Modify Audio lock region input sections due to library rename
    # v4.66 by mei, 20110831, Modify scatGen.pl for EMIGen restructure
    # v4.65 by mei, 20110830, Add * (INTSRAM_MULTIMEDIA_RW, INTSRAM_MULTIMEDIA_ZI) in MT6276(med_template_G)
    # v4.64 by mei, 20110830, To support MT6921 Auto-Gen for NFB
    # v4.63 by Claudia, Add & in front of function call Dec2Hex() in DCMP_code_layout()
    # v4.62 by Claudia, Remove unused INTSRAM_MULTIMEDIA user wrxbrp.obj on MT6276/MT6573/MT6575 because this SW work-around is only required on MT6268
    # v4.61 by Claudia, Put FLMM_PASPACE region in default cacheable region to sync with ASM behavior
    # v4.60 by Claudia, Correct MT6575 L2TCM_DATA size to sync with MT6276E2
    # v4.59 by Claudia, Correct MT6252 BL scatter STACK_AREA base address
    # v4.58 by Claudia, Modify FOTA Scatter to make FOTA internal regions independent of MAUI (for TCM only platform)
    # v4.57 by Claudia, Add DUMMY_END when DCM_Compression+non-MMU platforms to ensure link error will occur when memory expiration because DCMP regions are OVERLAY
    # v4.56 by Claudia, Refine EMI_EXTSRAM_SIZE pattern-matching to adapt to flexible () and spaces
    # v4.55 by mei, 20110812, Modify DCM Compression Pool Size and number
    # v4.54 by Claudia, Ensure MAUI ROM to be block-aligned even when EXT_BL_UPDATE_SUPPORT is turned off
    # v4.53 by mei, 20110811, Support MBA+DCMP in layout2
    # v4.51 by mei, 20110810, Add intergrafx_sw.lib and intergrafx_hw.lib into demand page to solve ROM2_RODATA extremely big which caused L6286E
    # v4.50 by Claudia, Support DPv2
    # v4.49 by mei, 20110808, Refine DCM Compression Layout for using meaningful execution name
    #                         Add DCM Compression Only Layout
    # v4.48 by Claudia, Fix FOTA Scatter Gen false alarm for NOR project without Sys RAM
    # v4.47 by Claudia, Modify gendummylis behavior to support ZIMAGE_AUTO_CONFIG
    # v4.46 by mei, 20110802, Isolate * (FLMM_PASPACE) to DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI_FLMM_PASPACE 
    # v4.45 by mei, 20110802, Add penpower.lib into demand paging   
    # v4.44 by mei, 20110801, Always generate EXTSRAM_GADGET    
    # v4.43 by mei, 20110801, Support DCM compression         
    # v4.42 by mei, 20110727, Support 6256 DSP DPV2 image layout     
    # v4.40 by Claudia, Report error when CONFIG_ZIMAGE_MAX_COMPRESSED_SIZE is larger than available ROM size
    # v4.39 by mei, 20110725, in Layout7(), modify __HIDDEN_SECURE_MAC's base address to be 2 blocks aligned and 
    #                         make boot_cert's base to be block aligned
    # v4.38 by mei, 20110725, Change BL/DSP_BL BaseAddress, API name(DSP_MT6256_2ndROM_EV->DSP_MT6256_EV), Support 56 in BBtbl_EXTSRAM_Shrinking_By_DP
    # v4.37 by mei, 20110724, Refine __KEEP_ROM related modification and modify FOTA __HIDDEN_SECURE_MAC's base address
    # v4.36 by Claudia, 20110724, Refine FOTA Scatter Gen and sync NOR/NFB FOTA scatter gen flow;
    #                             Correct custom_img_config.h UE_EXECUTION_BASE to be the same as FOTA load region base;
    #                             Remove FOTA custom pool size check
    # v4.35 by mei, 20110722, [BL scatGen]Add * (INTERNDATA) in BL's READ_WRITE_INT and EXT_BL's EXT_READ_WRITE_INT
    #                         [scatGen] Remove __KEEP_ROM in MAUI scatter file, and add __HIDDEN_SECURE_MAC's base address in layout7
    # v4.34 by mei, 20110721, Change Video Locked Lib Name for demand paging on 6276 and 6256
    # v4.33 by mei, 20110717, Support Basic Layout for 6256, Support PrefixRegionName in DSP_MT6256_2ndROM_EV
    #                         Change Query_DSP_MT6256_Info()'s interface, Change EXT_BL's base address
    # v4.32 by mei, 20110714, Remove L1Trc.obj from INTSRAM_DATA on MT6256
    # v4.31 by mei, 20110713, Support video locked sregion in 6256 and add demand_paging_rom_vidoe_h264enc for 6276 asnd 6256  in scatGen 
    # v4.30 by mei, 20110712, Support 6256 in scatGen 
    # v4.29 by Claudia, Fix Redbend FOTA issue that backup storage base contains no dataa for NOR; Add mmiresource.lib to ZIMAGE
    # v4.28 by mei, 20110711, Support 6256 in BL and EXT_BL 
    # v4.27 by Claudia, Enlarge EXT_BL size to 224KB when Card Download is enabled
    # v4.26 by Claudia, Modify ROM input sections when ZIMAGE is turned on for optimization
    # v4.22 by Claudia, Add .ANY to ROM section when ZIMAGE+NEPTUNE_MMI to support 32+32 GPRS segment
    # v4.25 by Claudia, To get EXTSRAM_SIZE from custom_EMI_release.h for all platforms
    # v4.24 by Claudia, To support EXT_BL_UPDATE_SUPPORT feature
    # v4.23 by Claudia, Put kmxime_latin.o (+RO) in ZIMAGE region for optimization
    # v4.21 by Claudia, Correct file owner of custom_img_config.h
    # v4.20 by Claudia, Enlarge Demand Paging load region upper bound by 12MB
    # v4.19 by Claudia, Add *l1_ext.lib in Primary MAUI
    # v4.18 by Claudia, Modify ZIMAGE input section for logo display optimization
    # v4.17 by Claudia, Support MT6575 Scatter Gen
    # v4.16 by Claudia, Put extra IG obj in demand paging region
    # v4.15 by Claudia, Add syscomp_config.obj(SHOULD_NOT_USED_RODATA) to SHOULDBE_EMPTYSECTION to prevent const being linked
    # v4.14 by Claudia, Add MMI resource obj as wild-card formats to split image resources to solve compiler limit error
    # v4.13 by Claudia, Fine-tune ZIMAGE related input sections for compression optimization
    # v4.12 by Claudia, Remove adaptation.lib and stacklib.lib because they were already merged to KAL
    # v4.11 by Claudia, Add mc.lib to Primary MAUI and to fine-tune BL scatter file to support eMMC Booting
    # v4.05 by Claudia, To support MT6921 Auto-Gen
    # v4.08 by Claudia, Support gendummylis command to generate dummy scatter file for memory expiration issues
    # v4.07 by Claudia, Modify MBA input sections
    # v4.04 by Claudia, Add EMMC_BOOTING options to support eMMC Booting
    # v4.03 by Claudia, Put more mmi framework code into Demand Paging
    # v4.02 by Claudia, Support MT6573 GPRS Scatter Gen
    # v3.56 by Claudia, Support MT6252 feature combination: Generate RVCT-style scatter file for MT6252+SECURE+USBDL
    # v3.55 by Claudia, Support MT6252 feature combination: Add MT6252 BL Scatter Gen support; Remove MT6252 blocking feature combinations; Add INTSRAM_DATA_PREINIT for BL-backup data
    # v3.39 by Claudia, Support Combo Memory by removing part number retrieval and adding EMIINITRW in EMIINIT_CODE region
    # v4.01 by Claudia, Add ss_btmt_dma.obj (INTERNRW1, INTERNZI1) in MT6276(M) INTSRAM_MULTIMEDIA to support SLT
    # v4.00 by Claudia, Support MMv2 FLMM region/API creation
    # v3.99 by Claudia, Put *IG_*.lib in Demand Paging region to support Intergrafx
    # v3.98 by Claudia, Put Video IP release version libraries in Demand Paging region for customers
    # v3.97 by Claudia, Support ARM9/11+Fcore NOR template and Scatter Gen for MT6573
    # v3.96 by Claudia, Fine-tune ZIMAGE input sections when MMI_VERSION is NEPTUNE_MMI
    # v3.95 by Claudia, Modify Bootloader's and MAUI's scatter file for MT6251 16+3 package
    # v3.94 by Claudia, Correct MT6276 L2TCM size from 96KB(E1) to 84KB(E2)
    # v3.93 by Claudia, Correct Demand Paging obigo03cstkadp.lib, mre_engine.lib, mre_custom.lib library names and enlarge Demand Paging size by 4MB
    # v3.91 by Claudia, Separate L1S DSPTX/RX region size from normal size because L1S load will build extra test code and cannot fit-in the shrunk DSPTX/RX size of MT6276
    # v3.90 by Claudia, Add * in front of IGV3.a in order to allow linker to recognize it
    # v3.89 by Claudia, Put Plutommi app libraries in Demand Paging region
    # v3.88 by Claudia, Create MP4COM and UVTDEC demand paging regions to separate VT decoder from MPEG4 decoder
    # v3.87 by Claudia, Add ROM2_RODATA to use 2-MAUI RO-DATA to push 2-MAUI RO-CODE away from 1-MAUI RO-CODE to prevent L6478E
    # v3.85 by Claudia, Put IG lib/obj in Demand Paging region when INTERGRAFX_SUPPORT is turned on
    # v3.84 by Claudia, Remove SLIMMING_WITH_DEMAND_PAGING option and put extra lib/obj in Demand Paging region by-default
    # v3.83 by Claudia, Modify custom_secure_config.h template change SDS configurations into length-based instead of block-based and to modify relavant error-checking mechanisms
    # v3.82 by Claudia, Place EXT_BOOTLOADER at the last 4MB~5.5MB of the RAM and place FOTA at the last 4MB to prevent EXT_BOOTLOADER from overlapping with FOTA
    # v3.81 by Claudia, Remove jataayu.lib and jataayuapp.lib because Jataayu WAP-MMS solution is already phased-out
    # v3.80 by Claudia, Put h264dec_mphp_arm11.a in DEMAND_PAGING_ROM_VIDEO_H264DEC
    # v3.79 by Claudia, Put extra lib/obj in Demand Paging region for SLIMMING_WITH_DEMAND_PAGING
    # v3.78 by Claudia, Generate MBA regions in custom_img_config.h for NOR projects; Generate GFH in LANG_PACK_ROM, CUST_PACK_ROM, JUMP_TABLE, and THIRD_ROM for SV5; Generate INTSRAM_PROTECTED_RES on MT6251; Refine SV5 BL scatter input sections
    # v3.77 by Claudia, Add SECONDARY_ROCODE and SECONDARY_RODATA pragmas for 2-MAUI
    # v3.47 by Claudia, Work-around to prevent L6478E error
    # v3.76 by Claudia, To refine MT6251 image layout and to add ROOT_CERT region
    # v3.75 by Claudia, To rename makefile option USB_DOWNLOAD into USB_DOWNLOAD_IN_BL
    # v3.74 by Claudia, Put usb_driver.lib in Primary MAUI because USB part has been split from drv.lib
    # v3.73 by Claudia, Shrink MT6251 SINGLE_BANK_CODE from 0x1E00 to 0x1600
    # v3.72 by Claudia, Shrink MT6276 MCU_DSP_SHAREMEM, DSP_TX, and DSP_RX region, and set alignment to 256KB instead of 1MB for shrinking
    # v3.71 by Claudia, Adopt LPDDR and LPDDR2 for MT6276
    # v3.43 by Claudia, Modify BL layout and custom_img_config.h template to support Card DL
    # v3.70 by Claudia, Remove RVCT work-around that 2-MAUI needs to be moved backwards to prevent L6286E on projects with DRAM no larger than 512Mb
    # v3.69 by Claudia, Modify custom_secure_config.h template to fix typo of BOOT_CERT_CTRL_PATTERN from 03 to 0x3
    # v3.68 by Claudia, Put video codec and wavetable in Demand Paging for MT6276
    # v3.67 by Claudia, Enlarge DEMAND_PAGING_ROM0 load region to fix memory expiration issue
    # v3.66 by Claudia, Add j2me_nemo.lib and j2me_nemo_cldc.lib to demand paging region on MT6236/MT6276, and rename ijet_adp.lib as nemo_adp.lib
    # v3.64 by Claudia, Rename ROMImage.obj as romclass.obj, and add 3g324m.lib in Demand Paging on MT6276
    # v3.63 by Claudia, To support MT6251 feature regression (Secure USBDL on MT6251)
    # v3.62 by Claudia, To support Redbend FOTA solution and FOTA on MT6276
    # v3.61 by Claudia, Put audio codec in Demand Paging region on MT6276 for shrinking
    # v3.60 by Claudia, Separate DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE into RW and ZI regions because ZI region (ASM pool) needs to be put at the front when COSMOS_MMI for camera HW limitation
    # v3.59 by Claudia, Fix ZIMAGE overlap with CACHED_DUMMY_END issue
    # v3.58 by Claudia, Enable check_user_setting for DUMMY_SCATTER_ENABLE to fix flash size = 0 issue when EXPECTED_CODE_LIMIT is not set
    # v3.57 by Claudia, Support DUMMY_SCATTER_ENABLE for trace-on projects; Fix ZIMAGE overlap with softwareLA issue; Add EMIINIT_RW in BL EMIINIT_CODE region
    # v3.54 by Claudia, Reduce FCORE execution view from 5MB to 1.5MB
    # v3.53 by Claudia, Put Font obj in DEMAND_PAGING_ROM3 for ONDEMAND+COSMOS_MMI to reduce memory consumption
    # v3.52 by Claudia, 
    # v3.51 by Claudia, Put ZIMAGE decompressed contents in cacheable region to fix performance degradation issue
    # v3.50 by Claudia, Change MCU-DSP share region to DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE region when COSMOS_MMI because MED pool was merged to ASM pool when COSMOS_MMI
    # v3.49 by Claudia, Fix DSP alignment issue when ZIMAGE configuration is not aligned with DSP region size
    # v3.48 by Claudia, To support eMMC Booting
    # v3.46 by Claudia, Put sst_sec.lib in Primary MAUI because it has been split out from sst.lib
    # v3.45 by Claudia, Fine-tune MT6276 BL scatter file to fit-in BL image
    # v3.44 by Claudia, Adopt MANUAL-CHECKIN pattern for manual check-in files to bypass Auto-Gen
    # v3.42 by Claudia, Add BOOT_CERT region and modify custom_secure_config.h template for Boot Cert feature
    # v3.41 by Claudia, Generate custom_secure_config.h to support SDS
    # v3.40 by Claudia, Fix custom_img_config.h template issue that FOTA_MAUI_SPACE cannot be recognized due to an extra space after applying SV5
    # v3.38 by Claudia, Put stack_ltlcom.obj in L1TCM on MT6276 to optimize PS MIPs
    # v3.37 by Claudia, Bound execution region ROM1 with load region limitation and add usb.lib to Primary MAUI to support ZIMAGE_SUPPORT
    # v3.36 by Claudia, Put more obj in Demand Paging region for MBA to save memory consumption
    # v3.35 by Claudia, Move l1sm.obj and l1csm.obj out from L1TCM on MT6276
    # v3.34 by Claudia, Restore L2TCM_DATA and remove FLEXL2 on MT6276 E2
    # v3.33 by Claudia, To support MT6251 and NOR SV5
    # v3.32 by Claudia, Put * (INTERNCODE_TP) & * (INTERNRW_TP, INTERNZI_TP) in internal RAM when tct.obj is in internal RAM to support KAL thread protect
    # v3.31 by Claudia, Change MT6276 BL READ_ONLY_SHARED base address to fit-in PMU increase after applying HAL
    # v3.30 by Claudia, Put mm_comm.lib in Primary MAUI because MM power control was moved from drv.lib to mm_comm.lib
    # v3.29 by Claudia, Fine-tune ZIMAGE_SUPPORT input sections in ROM and internal RAM to prevent power-on failure
    # v3.28 by Claudia, Remove MT6255
    # v3.27 by Claudia, Modify DSP_SOLUTION comparison rule from DSP_SOLUTION=DSP_FCORE4 to DSP_SOLUTION=DUALMACDSP for makefile option rename
    # v3.26 by Claudia, Move MT6276 L1S load 2-MAUI RW backwards by 4MB to prevent it overwrite 2-MAUI load view
    # v3.25 by Claudia, Support RHR (Merge MAUIW1043OF_RHR to MAUI)
    # v3.24 by Claudia, Put extra lib/obj in MT6276 DEMAND_PAGING region (as MT6236) for MT6276 slimming
    # v3.23 by Claudia, Support PROJECT_EXPECTED_RAM_LIMIT_NFB for NAND+DRAM projects to set RAM boundary
    # v3.22 by Claudia, Remove MT6253D
    # v3.20 by Claudia, Put cipher.lib in Primary MAUI because gcu.c has been moved from drv_graphics.lib to cipher.lib for HAL
    # v3.19 by Claudia, Support ZIMAGE_SUPPORT feature
    # v3.14 by Claudia, Rename or add libraries to support HAL
    # v3.18 by Claudia, Fix the issue that the sequence of MBA and FOTA binaries in custom_img_config.h is incorrect
    # v3.17 by Claudia, Put btmt_mem.obj in Sys RAM for MT6276 SLT
    # v3.16 by Claudia, Rename MT6253E/L as MT6252H/MT6252
    # v3.15 by Claudia, Add INTSRAM pragmas for users to split INTSRAM sections for RVCT
    # v3.13 by Claudia, Shrink MT6516 MD memory usage from 6MB to 4MB
    # v3.12 by Claudia, Fix SV5 side effect that Scatter Gen error when FOTA is turned on
    # v3.11 by Claudia, Add ABSOLUTE attribute on the region after 2-MAUI OVERLAY ROM to prevent following regions from heriting OVERLAY attribute
    # v3.10 by Claudia, Enlarge DP load region size from 16MB to 18MB
    # v3.09 by Claudia, Support MT6253E/L + GSM
    # v3.08 by Claudia, Support RHR Add and add header files include on custom_img_config.h
    # v3.07 by Claudia, Add input sections for TC01 partition and NAND totalBBM
    # v3.06 by Claudia, Remove SV5_DEV option and enable SV5 on all MT6276/MT6251/MT6255/MT6256 platforms
    # v3.05 by Claudia, Wrap sections with /* with double quotes "" to prevent pre-processor error
    # v3.04 by Claudia, Move SECONDARY_ROM base address backwards to prevent L6286E link error
    # v3.03 by Claudia, Generate CACHED_CODE_PATCH_CODE for MT6253E/L
    # v3.02 by Claudia, Fix incorrect EXTSRAM base address issue for MT6253E/L
    # v3.01 by Claudia, Move EMI_EXTSRAM_SIZE to custom_EMI_release.h
    # v3.00 by Claudia, Remove SHOULDBE_EMPTYSECTION for WISE MMI
    # v2.99 by Claudia, Remove part number sync check between custom_EMI.h/custom_flash.c and custom_MemoryDevice.h
    # v2.98 by Claudia, To support MT6253E/L
    # v2.97 by Claudia, To support COSMOS_MMI by adding gdi_2.lib to Primary MAUI, and by putting PLUTO_MMI objs in Demand Paging region
    # v2.96 by Claudia, Modify jblend_ram generation rule by checking whether J2ME_SUPPORT contains JBLENDIA or not
    # v2.95 by Claudia, Add MT6573 to ARM11 table
    # v2.94 by Claudia, Modify RMVB and H.264 DCM regions on MT6236 and MT6253
    # v2.93 by Claudia, To support SV5
    # v2.92 by Claudia, To support MT6276
    # v2.91 by Claudia, Generate SECOND_PART only when MT6253+EMI 104MHz
    # v2.90 by Claudia, To change GADGET_SUPPORT option from TRUE/FALSE to NONE/STANDARD/SHARED_MEMORY
    # v2.89 by Claudia, To support MT6253E/L, move EXTSRAM_SIZE to custom_EMI_release.h
    # v2.88 by Claudia, To support MT6253DV
    # v2.87 by Claudia, Remove CODE_PATCH_CODE region when the compiler is RVCT to fix RVCT bug (CODE_PATCH_ENGINE will not be defined on RVCT)
    # v2.86 by Claudia, Refine MT6236 Demand Paging input sections to put additional Java objs and to remove Opera due to performance degrade
    # v2.85 by Claudia, Modify Primary MAUI input section to ensure only C library will be put in Primary MAUI
    # v2.84 by Claudia, Add comments in INTSRAM to prevent objs being removed from INTSRAM
    # v2.83 by Claudia, Replace mmi_framework.lib and *.o with gdi.lib and *.l for Primary MAUI shrinking
    # v2.82 by Claudia, Add region EXTSRAM_PROTECTED_RES to put protected resources for customers, and modify BL scatter file to split READ_ONLY region into READ_ONLY and READ_ONLY_HEAD
    # v2.81 by Claudia, Add region SHOULDBE_EMPTYSECTION with size 0 to trigger link error when using forbidden C library APIs
    # v2.80 by Claudia, Remove j2me_hi_rvct.lib and ROMImage.obj from Demand Paging because it will be called in HISR
    # v2.79 by Claudia, Disable configuration checking for MT6251
    # v2.78 by Claudia, Put extra RO in Demand Paging reigon for (MT6236) RAM shrinking
    # v2.77 by Claudia, Add the support for Smart Phone (MT6516 only) and remove phased-out chips (MT6226, MT6226M, MT6227, MT6228, MT6230)
    # v2.75 by Claudia, Remove SINGLE_BANK_NOR_FLASH_SUPPORT makefile option
    # v2.74 by Claudia, Remove ROM6 and aggregate obigo03c libraries to fix ADS L6286E
    # v2.73 by Claudia, Rename ul1dsm.obj as ul1sm.obj
    # v2.72 by Claudia, Rename l1dsm.obj as l1sm.obj
    # v2.70 by Claudia, To fix issues found in MT6236 feature regression test.
    # v2.69 by Claudia, Add INTSRAM_MULTIMEDIA_RW, INTSRAM_MULTIMEDIA_ZI for put MM HW line buffer to MT6236(B) INTSRAM_MULTIMEDIA region
    # v2.68 by Claudia, Put pmic_drv.obj in Primary MAUI to support custom tool generated custom PMIC control APIs
    # v2.67 by Claudia, Add an extra region EXTSRAM_GADGET and pragma to support Web Gadget
    # v2.66 by Claudia, Add extra regions to support Opera browser
    # v2.65 by Claudia, Add MT6236(B) templates for RVCT
    # v2.64 by Claudia, Put ext_drv_assert_hdlr_if.obj in Primary MAUI to support External Driver Assert Handler for TC01
    # v2.63 by Claudia, Enable SS features for RVCT
    # v2.62 by Claudia, Add RVCT C++ initialization
    # v2.61 by Claudia, Put sss.lib and sss_rvct.lib Data in Primary MAUI
    # v2.60 by Claudia, Remove previous work-around and add OVERLAY in Secondary MAUI to prevent RVCT veneer placement issue
    # v2.59 by Claudia, Put image_codec_public16.lib in Primary MAUI
    # v2.58 by Claudia, Temporarily add a 4MB offset for SECONDARY_ROM to force the veneer to be placed in Primary MAUI for RVCT
    # v2.57 by Claudia, Add DYNAMIC_CODE21 for * (RVDEC_DYNAMIC_ZI, RVDEC_DYNAMIC_RO) for MT6236 and change MT6236 DCM candidates
    # v2.56 by Claudia, Modify BL scatter file to add input sections to EXT_READ_ONLY and EXT_READ_WRITE for X-Download
    # v2.55 by Claudia, Work around to tune FAT size for Toshiba MCP bad small blocks issue 
    # v2.54 by Claudia, Add OVERLAY in NFB ROM1 for RVCT veneer placment workaround
    # v2.53 by Claudia, Add pragmas PRIMARY_ROCODE, PRIMARY_RODATA, PRIMARY_RW, PRIMARY_ZI for Primary MAUI
    # v2.52 by Claudia, Append _rvct at j2me_11.lib and j2me_hi.lib for RVCT migration
    # v2.51 by Claudia, Modify BL Scatter Gen for MT6236 bug fix and address tuning
    # v2.50 by Claudia, Put custom_util.obj in Primary MAUI to support printing log at init
    # v2.49 by Claudia, Allow SECOND_PART always exist to support MEM_Info
    # v2.48 by Claudia, Support MT6236 Auto-Gen
    # v2.47 by Claudia, Add DYNAMIC_CODE20 for H.264 on MT6253
    # v2.46 by Claudia, Support RVCT migration
    # v2.45 by Claudia, Re-calculate NOR flash size and FAT base address for Toshiba MCP bad small blocks issue
    # v2.44 by Claudia, Modify BL Scatter File to add nand_fdm50_l.obj to Ext Bootloader in NFB
    # v2.43 by Claudia, Correct BL scatter file pragma naming from EX_BOOTLOADER to EXT_BOOTLOADER
    # v2.42 by Claudia, Support Nucleus Plus 2.1
    # v2.41 by Claudia, Generate OVERLAY EMIINIT_CODE on all platforms
    # v2.40 by Claudia, Add cs_fac_det*.obj to Primary MAUI for Customer Specific Factory detection mechanism
    # v2.39 by Claudia, Add MT6253D
    # v2.38 by Claudia, Add Ext_Charger_*.obj and Ext_Cable_*.obj for External Cable detection
    # v2.37 by Claudia, Align all NFB=BASIC binary size as 0x800000+0x1A00000 in custom_img_config.h
    # v2.36 by JI, vector font resource support in LANG_PACK
    # v2.35 by JI, remove idle_task.obj 
    # v2.34 by Claudia, Support BASIC NFB option
    # v2.33 by JI, NFB ARM7 Primary MAUI adjust balance libraries
    # v2.32 by JI, ARM9 NFB MBA Reserved Region Adjust to 0x4C0000
    # v2.31 by JI, MT6253 DCM Region Add MP4ENC3 region
    # v2.29 by JI, NFB ARM7 Primary MAUI adjust balance libraries
    # v2.28 by JI(deputy), MT6268 UMTS NFB layout adjust to isolate large ul1.lib and uas.lib as independent Execution Region
    # v2.27 by JI(deputy), MT6235, MT6235B put uart_def.obj in SysRAM
    # v2.26 by Claudia, Modify Demand Paging input section to support Engineer Mode source code re-org
    # v2.25 by Claudia, Put btmt_mem.obj in MED_MAIN_REGION for MT6253_MT
    # v2.24 by Claudia, Enlarge UA_NONCACHED size by 64KB in FOTA scatter file for ARM9 NFB projects
    # v2.23 by Claudia, Remove m11191.c and m11194.c from Internal RAM
    # v2.22 by Claudia, Support FOTA Update Package on NAND
    # v2.21 by Claudia, Modify scatGen.pl to modify custom_MemoryDevice.h information retrieval for new FAT naming in custom_MemoryDevice.h
    # v2.20 by Claudia, Add custpack_java_certs.obj in CUSTPACK_ROM_CONTENT to support Java certificate custpack feature
    # v2.19 by Claudia, Create one DCM region from the med_main buffer on MT6253 to share with MP4 decoder
    # v2.18 by Claudia, Import new pragma INTSRAM_ROCODE, INTSRAM_RODATA, INTSRAM_RW, INTSRAM_ZI to INTSRAM and remove init.obj, ex_item.obj, and tst_trace.obj 
    # v2.17 by Claudia, Put uscounter.obj in MT6268 INTSRAM_CODE and INTSRAM_DATA
    # v2.16 by Claudia, Move nvram.lib and nvram_sec.lib from Primary ROM to SECONDARY_ROM
    # v2.15 by Claudia, Put intrCtrl.obj (INTERNRW, INTERNZI) in MT6227 series INTSRAM_DATA
    # v2.14 by Claudia, Put tct.obj (INTERNCODE) instead of the entire obj in Internal RAM to shrink Internal RAM usage
    # v2.13 by Claudia, Add mtkdebug.lib to SECONDARY_ROM for NFB projects
    # v2.12 by Claudia, Roll back temp solution to turn on FOTA for CMCC projects
    # v2.11 by Claudia, Turn on FOTA when OPTR_SPEC is set to CMCC_0202_SEGA(_TECH) or CMCC_0202_SEGC(_TECH)
    # v2.10 by Claudia, Remove FAT validity check for NAND FOTA for FAT tuning is done automatically
    # v2.09 by Claudia, Support BL Scatter Gen for MT6268H
    # v2.08 by Claudia, Modify FOTA scatter file to remove duplicated input section
    # v2.07 by Claudia, Modify INTSRAM_TMP_PAGE_TABLE and INTSRAM_FOTA_TEMP on MT6268 size for FOTA
    # v2.06 by Claudia, Modify BL scatter file input section and add comments
    # v2.05 by Claudia, Add the support of MT6268
    # v2.04 by Claudia, Remove unnecessary libraries from MAUI scatter files since they are replaced after applying MONZA2G
    # v2.03 by Claudia, Modify MT6253 INTSRAM_MULTIMEDIA Sys RAM input section
    # v2.02 by Claudia, Put Regioninit_ads.obj at the beginning so that it can be cached to improve boot-up speed
    # v2.01 by Claudia, Modify MT6253 TCM to place HW line buffer on different banks of TCM from MCU
    # v2.00 by Claudia, Enlarge UA_ROM size to 0x38000 in FOTA scatter files for NFB projects on ARM7
    # v1.99 by Claudia, Put WAP-related libraries, interface.lib, and interface_classb.lib in SECONDARY_ROM to avoid ADS L6286E link error
    # v1.98 by Claudia, Remove MT621X series and add the support of MT6253
    # v1.97 by Claudia, Modify NAND FOTA image header size for ext bootloader
    # v1.96 by Claudia, Support Auto Gen for BL scatter files and generate BOOTLOADER with size at least 128K when NEED_BUILD_BOOTLOADER is TRUE
    # v1.95 by Claudia, Put uart_def.obj in SysRAM
    # v1.94 by Claudia, Remove mpal objects from INTSRAM to support MT6253 memory requirement
    # v1.93 by Claudia, Support Auto Gen for FOTA scatter files and set FOTA load region size as CONFIG_FOTA_UE_FLASH_SPACE
    # v1.92 by Claudia, Group L1 timing related objects in Internal RAM and add comments to prevent customers from removing them
    # v1.91 by Claudia, Remove media_app.lib from ROM because its size has exceeded 4MB boundary
    # v1.90 by Claudia, SW workaround for MONZA2G sleep mode + MT6235 by tuning INTSRAM
    # v1.89 by Claudia, Remove llc.lib from Primary MAUI to reduce ROM size
    # v1.88 by Claudia, Remove MT6205B-only scatter file templates
    # v1.87 by Claudia, Define FOTA mapping table size for MAUI in custom_MemoryDevice.h
    # v1.86 by Claudia, Remove ijet_adp.lib from Demand Paging when J2ME_VM is KVM or KVM_SOURCE
    # v1.85 by Claudia, Modify custom_img_config.h template and FAT base address for FOTA on NFB
    # v1.84 by Claudia, Increase FOTA_MAUI_MAPPING_TABLE_SIZE on ARM7 platforms for FOTA on NFB
    # v1.83 by Claudia, Modify FOTA_PACKAGE_STORAGE_BASE calculation for FOTA+ENFB.
    # v1.82 by Claudia, Add libraries because of library rename for MONZA2G
    # v1.81 by Claudia, Put WAP related input sections in ROM3 instead of SECONDARY_ROM
    # v1.80 by Claudia, Replace WAP input section custom_wap_cust_pack.obj with custpack_certs.obj in CUSTOM_PACK
    # v1.79 by Claudia, Modify custom_img_config.h template for FOTA+NFB
    # v1.78 by Claudia, Aggregate WAP Third Party libraries into SECONDARY_ROM for NFB projects
    # v1.77 by Claudia, Correct scatter file layout for SECURE+FOTA+NOR on MT6238 platforms
    # v1.76 by Claudia, Add NFB FAT configuration check and modify Primary ROM size limit when FOTA_DM is enabled
    # v1.75 by Claudia, Set DEMP region's size to a proper value
    # v1.74 by Claudia, Remove email.lib from ROM and ROM1 because ROM will exceed its size limitation
    # v1.73 by Claudia, Add l1_classb_g2.lib and l1_g2.lib as well as l1_classb.lib and l1.lib for MONZA2G
    # v1.72 by Claudia, Remove cc.lib from Primary MAUI
    # v1.71 by Claudia, Add an extra ROM region for RO-CODE for NFB
    # v1.70 by Claudia, Add general boot-loader for MT6238+SECURE
    # v1.69 by Claudia, Modify the size of INTSRAM_TMP_PAGE_TABLE for INTSRAM_FOTA_TEMP
    # v1.68 by Claudia, Support NFB=MIXED+SECURE scatter file layouts
    # v1.67 by Claudia, Fix NOR RDM5.0 FAT and small block judgement error
    # v1.66 by Claudia, Enlarge the size limit of load region DEMAND_PAGING_ROM0 from 14MB to 16MB on MT6238
    # v1.65 by Claudia, Enlarge the size limit of load region DEMAND_PAGING_ROM0 from 13MB to 14MB
    # v1.64 by Claudia, Revise FOTA+NFB scatter files and custom_img_config.h
    # v1.63 by Claudia, Modify MT6238 NFB scatter file template to align with MT6235
    # v1.62 by Claudia, Remove MMI Resource from Demand Paging when THIRD_ROM exists
    # v1.61 by Claudia, Support FOTA+NFB Auto-Gen
    # v1.60 by Claudia, Put gdi_arm.lib in Primary MAUI
    # v1.59 by Claudia, Put CODE_PATCH_CODE to Cacheable region
    # v1.58 by Claudia, Add l1.lib and l1_classb_umts.lib for GSM and UMTS projects.
    # v1.57 by Claudia, Modify custom_img_config.h template to generate FOTA backup UE space size.
    # v1.56 by Claudia, Put SINGLE_BANK_CODE to cacheable region CACHED_EXTSRAM_CODE on ARM9 platforms and align NFB and non-NFB CACHED_EXTSRAM
    # v1.55 by Claudia, Unify ESBNOR input sections with pragmas
    # v1.54 by Claudia, Check FOTA update package validity
    # v1.53 by Claudia, To support NORXIP+SECURE+MBA scatter file
    # v1.52 by Claudia, Move EXTSRAM base address from 0x140 to 0x200 when remapping
    # v1.51 by Claudia, Add file name and fline number information and unify all auto-gen error messages
    # v1.50 by Claudia, Modify NFB makefile option judgement for MT6225 TCM
    # v1.49 by Claudia, Fix MBA incorrect addressing issue
    # v1.48 by Claudia, Fix ARM9 MBA scatter file address calculation error
    # v1.47 by Claudia, Restore MT6225 NFB Nucleus small configuration to fix ambiguous section problem
    # v1.46 by Claudia, To support MBA on ARM9
    # v1.45 by Claudia, NAND_FLASH_BOOTING makefile option is changed
    # v1.44 by Claudia, Put kal_nucleus_initialize.obj(SNORCODE) in SINGLE_BANK_CODE for ESB bug fix
    # v1.43 by Claudia, Put tct.obj(+RW, +ZI) in DTCM
    # v1.42 by Claudia, To support FOTA on ARM9
    # v1.41 by Claudia, Aggregate NFB scatter file template to aggregate Secondary MAUI RO-DATA into one region with no limit
    # v1.40 by Claudia, Unify Auto-Gen error messages and add error-checking for unsupported scatter file layouts
    # v1.39 by Claudia, Enlarge Demand Paging load region size to 13MB
    # v1.38 by Claudia, Add offset to DYNAMIC_CACHEABLE regions
    # v1.37 by Claudia, Support FOTA Auto-Gen
    # v1.36 by Claudia, Fix LIBRA35 SECURE NFB scatter file template issue
    # v1.35 by Claudia, Split init.c into init.c and emi.c; split cache.c into cache.c and mmu.c
    # v1.34 by Claudia, Enable MT6238 dynamic cacheable region
    # v1.33 by Claudia, Put Regioninit_ads.obj to the front to enhance power-up performance
    # v1.32 by Claudia, Support SW Video on MT6225 and MT6235
    # v1.31 by Claudia, Add DSP_TX/DSP_RX input sections on 07B to fix DSP error
    # v1.30 by Claudia, Re-organize MT6235/MT6238 TCM and Cached Region input sections
    # v1.29 by Claudia, Shrink MT6238 ITCM usage
    # v1.28 by Claudia, Put custom_scatstruct.obj back in MT6238 DTCM
    # v1.27 by Claudia, Support MT6238/MT6239 NFB scatter files
    # v1.26 by Claudia, Modify Demand Paging load view start address to align with execution view
    # v1.25 by Claudia, Modify MT6238 TCM input sections to fix 60qbit problem
    # v1.24 by Claudia, Fix ambiguous input sections issue on MT6235
    # v1.23 by Claudia, Modify Sys RAM size for MT6238 E3
    # v1.22 by Claudia, Fix ambiguous input sections issue on MT6238
    # v1.21 by JI(deputy), Add divrt_real.o and f_t_p.l , fix position and reduce L6286E possibilities
    # v1.20 by JI(deputy), Add ObigoQ03C Libs in third party ROM section of NORXIP templates
    # v1.19 by JI(deputy), MT6223P INTSRAM input section revise
    # v1.18 by JI(deputy), NFB layout Primary + custom_jump_tbl.obj
    # v1.17 by Claudia, Modify scatter file for MT6235/MT6238 dynamic cacheable region
    # v1.16 by Claudia, Support NFB MBA layout
    # v1.15 by Claudia, Put image_codec16.lib in Primary MAUI
    # v1.14 by Claudia, Modify Scatter Gen for MT6238/MT6239 NFB scatter files
    # v1.13 by Claudia, Put gpt.obj in MT6235 ITCM to avoid 60-qbit violation
    # v1.12 by Claudia, Add EBOOK and EXTRA to Demand Paging
    # v1.11 by Claudia, Support USB-Download + NFB scatter file (checked in as v1.09)
    # v1.10 by Claudia, Modify MBA input section from custthemeRes.obj to ThemeRes.obj
    # v1.09 by Claudia, Support SECURE NFB scatter file
    # v1.08 by Claudia, Change med_main.obj to drv_gfx_stack_switch_manager.obj in MT6225 DTCM
    # v1.07 by Claudia, Add input section gui_effect_oem.obj to MT6225/6228/6229/6230/6235/6235B/6238/6239 LARGEPOOL
    # v1.06 by Claudia, replace control buffer related code with GPT related code in ITCM for MT6238
    # v1.05 by Claudia, Modify DEMAND_PAGING_ROM0 start addresses
    # v1.04 by Claudia, support MT6235/MT6238 scatter Gen
    # v1.03 by Claudia, add execution regions for USB Download for End Uesr scatter file layouts
    # v0.102 by Claudia, add SECURE+MBA layout and add input sections to CUST_PACK_ROM and CUST_PACK_ROM_CONTENT for MBA
    # v0.101 by Claudia, add input section for EMI Info
    # v0.100 by Claudia, put VR_Engine to DCM on MT6225, MT6226/MT6227 series, MT6228, MT6229, MT6230
    # v0.99 by Claudia, remove custom_switchclock.c and add custom_flash.c for EMI/flash split
    # v0.98 by Claudia, put JPEG encoder/decoder to INTSRAM DCM on MT6223 series.
    # v0.97 by Claudia, modify MT6225 INTSRAM input section to fix link error
    # v0.96 by Claudia, support NORMAL/SECURE/NONE USB_DOWNLOAD option
    # v0.95 by Claudia, force med_main.obj to be the first in LARGEPOOL execution region on MT6227D/MT6226D
    # v0.94 by Claudia, DYNAMIC_CODE add RESAMPLE/REVERB on MT6223/MT6227/MT6227D/MT6226/MT6226M/MT6226D
    # v0.93 by JI, code location bug fix when ESBNOR + DCM_SUPPORT + MT6227 series
    # v0.92 by JI, Scatter address calc correct on multi-bin , secure layout
    # v0.91 by JI, new library sss.lib
    # v0.90 by JI, MT6223 ESBNOR move l1dsm.obj from External to Internal
    # v0.89 by JI, NFB Secondary DSP TX RX address calc bug-fix
    # v0.88 by JI, Scatter adjustable with NOR Flash Block Size.
    #              And USB_DOWNLOAD feature supported
    # v0.87 by JI, NFB Primary add BLINUSED execution region
    # v0.86 by JI, NFB Primary ROM replace sw_png_codec as image_codec.lib
    # v0.85 by JI, drv lib split into drv ,  drv_display , drv_graphics , drv_idp
    # v0.84 by JI, NFB Primary ROM add MiscUtils.obj for C++ const data init
    # v0.83 by JI, NFB Primary RAM length limit calc correction
    # v0.82 by JI, SINGLE_BANK_CODE revise and doc organize on all platform
    # v0.81 by JI, SINGLE_BANK_CODE revise on MT6223/23P platform
    # -------------- 07B active branch 
    # v0.80 by JI, Re Plan NFB scatter template due to plutommi , mtkapp library split into 5 libs 
    # v0.77 by JI, Aggrate more C++ section in Primary ROM on NFB project
    # v0.76 by JI, enhanced single bank nor flash support on MT6229/MT6230 platform
    # v0.75 by JI, SINGLE_BANK_CODE revise on MT6223/23P platform
    # v0.74 by JI, Aggrate C++ section to fix L6216E error
    # v0.73 by JI, DYNAMIC_CODE cancel WAV, REVERB, RESAMPLE, use SBC instead
    # v0.72 by JI, SINGLE_BANK_CODE remove +First when BASIC load to fix link error
    # v0.70 by JI, NFB Layout adaptive for memory density , 32MB/64MB supported
    # v0.68 by JI, MT6223 add DYNAMIC_CODE for CTM / WAV sharing
    # v0.67 by JI, MT6225 add gpt.obj (INTERNCODE)
    # v0.66 by JI, Shift NFB Large Pool to fit LCD HW 32MB limit
    # v0.65 by JI, One more RO-CODE execution region to fill code of new feature set
    # v0.64 by JI, ROM size should bounded on 24MB on MT6228/29 series platform
    # v0.63 by JI, DSP TX RX size are adjustable for chip MT6223/MT6229 and mode GSM/GPRS
    # v0.62 by JI, MT6223 series supported for SINGLE_BANK_CODE
    # v0.61 by JI, MT6223P support and its INTSRAM configuration
    # v0.60 by JI, aes_engine.obj replace drm_util.obj
    # v0.59 by JI, speed up pmic6318 on MT6227D platform
    # v0.58 by JI, add MCU_Platform MT6227 MT6226M for Secure Support (Since S02)
    # v0.57 by JI, take gpt.obj lpwr.obj data out from 6227 platform
    # v0.56 by JI, NFB layout adaptive for memory density
    # v0.55 by JI, MT6227D add 2 drv object to speed up
    # v0.54 by JI, modified to SST_intrCtrl.obj (INTERNCODE,INTERNCONST)
    # v0.52 by JI, MT6223 INTSRAM configure -- replace L1 objects , bootarm.obj , SST_intrCtrl.obj
    # v0.51 by JI, MT6223 INTSRAM configure -- replace L1 objects
    # v0.50 by JI, MT6225 intersram remove gdi_bytestream.obj (by JF Huang)
    # v0.49 by JI, MT6227, MT6217 series INTSRAM add gdi_image_alpha_bmp.obj for GDI enhancement
    # v0.48 by JI, add MCU_Platform MT6226D as MT6227D clone 
    # v0.47 by JI, cut dependency MMI_VERSION Makefile compile option
    # v0.46 by JI, MT6223 INTSRAM adjust for l1audio wav and drv gpt
    # v0.44 by JI, Split out WAP,J2ME libraries from defualt ROM
    # v0.43 by JI, idle_task.obj & custom_switchclock.obj in INTSRAM on platform with DCM facility
    # v0.42 by JI, intrCtrl.obj replace to SST_intrCtrl.obj on all platform
    # v0.41 by JI, gpt.obj , lpwr.obj add into INTSRAM on 6217, 6218, 6219, 6227 series platform
    # v0.40 by JI, MT6223 , MT6227D supported
    # v0.39 by JI, MT6205B SINGLE_BANK_CODE support , distinguish lowcost SB and enhanced SB
    # v0.35 by JI, NFB Primary ROM and EXTSRAM revise for 6225 platform
    # v0.34 by JI, MT6225 TCM code / data re-partition , 7800h : 5800h => 7600h : 5A00h
    # v0.33 by JI, fix link error when SECURE SUPPORT TRUE and JATAAUY TRUE
    # v0.32 by JI, 6205B missed , TCM content adjust for intrCtrl.obj and single bank required
    # v0.31 by JI, NFB Secondary LargePool default start address 0x1600000 -> 0x1700000
    # v0.30 by JI, ThreadX related revision on NFB Primary ROM and TCM
    # v0.29 by JI, NFB Primary ROM members re-organized. drv_init() splited
    # v0.28 by JI, MT6228 TCM content add jvm_runtime.obj for MCU cache system bug-fix
    # v0.27 by JI, TCM content adjust for intrCtrl.obj and single bank required
    # v0.26 by JI, secure layout does not force user use RAM > 8MB
    # v0.25 by JI, basic/l1s load string compare as capital letter bug fix
    # v0.24 by JI, MT6225 TCM reconfigure ; audio in, L1 out
    # v0.23 by JI, SINGLE_BANK_CODE support
    # v0.22 by JI, NFB Primary ROM new members : object files under misc_drv\BB_folder\codegen\*
    # v0.21 by JI, NFB Primary ROM new member motion_sensor_custom.obj
    # v0.20 by JI, 6227D platform support
    # v0.19 by JI, 6217 INTSRAMCODE add new member drm_util.c
    # v0.18 by JI, Split custom.lib into specific objects in Primary ROM content (NFB)
    # v0.17 by JI, 6225 TCM Data add new member med_main.obj (INTERNRW2)
    # v0.16 by JI, 6225 NFB layout supported
    # v0.15 by JI, Move INTSRAM_MEDIA to Secondary ROM
    #              INTSRAM content align between non-NFB and NFB layouts
    # v0.14 by JI, NFB layout enlarge Paimary MAUI size , temporal for C++ problem
    # v0.13 by JI, dynamic code regions (code cache on external RAM) on MT6225 
    # v0.12 by JI, modify idle_task.obj to follow custom_switchclock.obj
}

#****************************************************************************
# subroutine:  NOR_Get_BASE_and_MaxSize
#              this function is meant to help calculate 
#              each SECURE or MBA region's base address and max size by input combination settings 
# input:       $strKey:         Region Name
#              $RegionInfo_ref: 
# RegionName    => [ LoadRegionOption(+0/ block aligned/ assigned sizes), 
#                    Value           (x / block/ bytes),  
#                    MaxSize         (defined by input /-1=empty/undef=blocksize or assigned size)]
# --------------------example-------------------------
# BOOT_CERT     => [ $LVoption, $nValue, $nMaxSize ]
# SECURE_MAC    => [ $LVoption, $nValue, $nMaxSize ]
# SECURE_RO     => [ $LVoption, $nValue, $nMaxSize ]
# FLASHTOOL_CFG => [ $LVoption, $nValue, $nMaxSize ]
# CUST_PARA     => [ $LVoption, $nValue, $nMaxSize ]
# ----------------------------------------------------
# $nLVoption: DONT_CARE    =don't care: apply +0,  $nValue=don't care
#             BLOCK_ALIGNED=block aligned,         $nValue=how many block
#             OCCUPIED_SIZE=occupied size,         $nValue = size
# $nMaxSize: defined outside
# $nMaxSize=-1: empty string
# $nMaxSize=undef: defined by calculation 
#         
#              $nBottomAddress: this function will use this bottom address 
#                               to minus the total region info occupied sizes.
# ----------------------------------------------------
# output:      $nBottomAddress: $nBottomAddress-= actual occupied size
#              $RegionInfo_ref->{$strKey}[2]: $nValue
#              $nOccupiedSize: acutal occupied size
#****************************************************************************
use constant DONT_CARE            => 0;
use constant BLOCK_ALIGNED        => 1; 
use constant OCCUPIED_SIZE        => 2;
sub NOR_Get_BASE_and_MaxSize
{
    my ($strKey, $RegionInfo_ref, $nBottomAddress) = @_;
    #print "SECURE_Get_BASE_and_MaxSize, bottom base=$nBottomAddress, BLOCK aligned=".BLOCK_ALIGNED." key[0]=".$RegionInfo_ref->{$strKey}[0]."\n";
    my $nOccupiedSize = 0;
    if($RegionInfo_ref->{$strKey}[0] == BLOCK_ALIGNED)
    {
        my $nblock_size = 0;
        my $nBlockCount = $RegionInfo_ref->{$strKey}[1];
        foreach (1..$nBlockCount)
        {
            $nblock_size = &config_query_flash_block_sz($nBottomAddress - 1);
            $nOccupiedSize += $nblock_size;
            $nBottomAddress -= $nblock_size;
        }
    }
    elsif ($RegionInfo_ref->{$strKey}[0] == OCCUPIED_SIZE)
    {
        $nOccupiedSize = $RegionInfo_ref->{$strKey}[1];
        $nBottomAddress -= $nOccupiedSize;
    }
    return ($nBottomAddress, $RegionInfo_ref->{$strKey}[2], $nOccupiedSize);
}
#****************************************************************************
# subroutine:  BOTTOM_NOR_LV_Layout
#              this function is meant to support generating any Bottom-to-top region layout on NOR
# input:       $bb, $fs:flash size <because secure regions are always put in the end of layout>,
#              $is_OVERLAY: 0=don't add OVERLAY on load region, 1=add OVERLAY on load region
#              $RegionSetting_ref: please refer to sub NOR_Get_BASE_and_MaxSize()
# output:      $nBOTTOM_TOTAL_SIZE: secure region total occupied size
#              $strSECURE_LAYOUT:   output layout
#              $nDCMP_evTotalSize:  if dcm_compression_support
#****************************************************************************
sub BOTTOM_NOR_LV_Layout
{
    my ($bb, $fs, $rs, $is_OVERLAY, $RegionSetting_ref) = @_;      
    my @BottomToTopRegion;
    my $nBOTTOM_TOTAL_SIZE = 0;
    my ($nMax, $nOccupiedSize) = (0, 0);
    my $str_LAYOUT;
    my $nDCMP_evTotalSize = 0;
    # --- --- ---
    &GetBottomRegion(\@BottomToTopRegion, $bb);
    
    my %RegionInfo; #{KeyName => [strBase, strMax]}
    my $nBottomAddress = $fs;
    foreach my $Region (@BottomToTopRegion)
    {
        ($nBottomAddress, $nMax, $nOccupiedSize) = &NOR_Get_BASE_and_MaxSize($Region,$RegionSetting_ref, $nBottomAddress);
        $nBOTTOM_TOTAL_SIZE += $nOccupiedSize;
        my $strMaxSize = &CommonUtil::Dec2Hex((!defined $nMax) ? $nOccupiedSize : $nMax);
        $strMaxSize = '' if ($nMax == -1);
        $RegionInfo{$Region}  = [&CommonUtil::Dec2Hex( &config_query_flash_base_address($bb) + $nBottomAddress), $strMaxSize];
    }
    my $RegionInfo_ref = \%RegionInfo;
    ($str_LAYOUT ,$nDCMP_evTotalSize) = &GetBottomLayout($bb, $rs, $RegionInfo_ref, $is_OVERLAY);

    return ($nBOTTOM_TOTAL_SIZE, $str_LAYOUT, $nDCMP_evTotalSize);
}
#****************************************************************************
# subroutine:  GetBottomRegion
#              this function is to determine the regions at the Bottom of the Flash
# input:       $BottomToTopRegion_ref: please refer to sub BOTTOM_NOR_LV_Layout()
# output:      N/A
#****************************************************************************
sub GetBottomRegion
{
	  my ($BottomRegions, $bb) = @_;	 
	  
	  # get feature option
    my $fota   = &$feature_query_function_ptr('fota_enable');
    my $secure = &$feature_query_function_ptr('secure_support') if (&sysUtil::is_sv5($bb) != 1);
    my $mba = &$feature_query_function_ptr('multiple_binary_files');
    my $alice = &$feature_query_function_ptr('alice_support') if ($mba eq 'TRUE');
    my $dcmp = &$feature_query_function_ptr('dcm_compression_support') if ($mba eq 'TRUE');
    my $boot_cert = &$feature_query_function_ptr('boot_cert_support');
    my $mba_bin = &$feature_query_function_ptr('mba_default_binary');
    
    #get bottom to top regions
    my @secure_regions_1 = ('CUST_PARA', 'FLASHTOOL_CFG', 'SECURE_RO');
    my @secure_regions_2 = ('SECURE_MAC');
    my @boot_cert_region = ('BOOT_CERT');
    my @mba_regions = ('JUMP_TABLE', 'CUSTPACK_ROM' , 'LANG_PACK_ROM');
    my @dcmp = ('DYNAMIC_COMP_CODE');
    my @alice_region = ('ALICE');    
    my @viva_region = ('VIVA');

        
    if(defined $secure and $secure eq 'TRUE')
    {
        push @$BottomRegions, @secure_regions_1; 	       
    }
    if(defined $boot_cert and $boot_cert ne 'FALSE' and $boot_cert ne 'NONE')
    {
        push @$BottomRegions, @boot_cert_region;
    }
    if(defined $secure and $secure eq 'TRUE')
    {
        push @$BottomRegions, @secure_regions_2;
    }
    if(defined $alice and $alice eq 'TRUE') # alice grows bottom to top if MBA support 
    {    	 
        push @$BottomRegions, @alice_region;
    }        
    if(defined $dcmp and $dcmp eq 'TRUE')
    {
        push @$BottomRegions, @dcmp;
    }
    if(((defined $alice and $alice eq 'TRUE') or (defined $dcmp and $dcmp eq 'TRUE')) and $mba eq 'TRUE')
    {
        push @$BottomRegions, @viva_region;
    }    
    if((defined $mba and $mba eq 'TRUE') and (defined $fota and $fota eq 'FOTA_DM'))
    {
    	  if(!defined $mba_bin or (defined $mba_bin and $mba_bin eq 'CUST_AND_LANG'))
    	  {
            push @$BottomRegions, @mba_regions;	
        }
        elsif(defined $mba_bin and $mba_bin eq 'CUST_ONLY')
        {
            push @$BottomRegions, ($mba_regions[0], $mba_regions[1]);	
        }
        elsif(defined $mba_bin and $mba_bin eq 'LANG_ONLY')
        {   
            push @$BottomRegions, ($mba_regions[0], $mba_regions[2]);	
        }
    }
}

#****************************************************************************
# subroutine:  GetBottomLayout
#              this function is to generate the layout at the Bottom of the Flash
# input:       $bb
# output:      1. BottomToTop Layout 2. nDCMP_evTotalSize
#****************************************************************************
sub GetBottomLayout
{
    my ($bb, $rs, $RegionInfo_ref, $is_OVERLAY) = @_;
    my $strLVAttribute = (($is_OVERLAY == 1) and ($Is_Flashtool_Layout == 0)) ? 'OVERLAY' : '';
    # feature option
    my $fota   = &$feature_query_function_ptr('fota_enable');
    my $secure = &$feature_query_function_ptr('secure_support');
    my $boot_cert = &$feature_query_function_ptr('boot_cert_support');
    my $mba = &$feature_query_function_ptr('multiple_binary_files');
    my $alice = &$feature_query_function_ptr('alice_support') if ($mba eq 'TRUE'); 
    my $dcmp = &$feature_query_function_ptr('dcm_compression_support') if ($mba eq 'TRUE');
    # --- --- ---   
    # Boot Cert region
    my $boot_cert_rom = &layout14($bb, $RegionInfo_ref->{'BOOT_CERT'}->[0], $RegionInfo_ref->{'BOOT_CERT'}->[1], $strLVAttribute) if ($boot_cert ne 'FALSE' and $boot_cert ne 'NONE');
    chomp $boot_cert_rom;
    # --- --- ---
    # viva region
    my $viva_Layout;
    if((defined $alice and $alice eq 'TRUE') or (defined $dcmp and $dcmp eq 'TRUE'))
    {
        $viva_Layout = &layoutVIVA($RegionInfo_ref->{'VIVA'}->[0], $RegionInfo_ref->{'VIVA'}->[1], $bb);
    }
    ### Calculate DCMP End address
    my $lv_dcmp_basic, $lv_dcmp_code;
    my $nDCMP_evTotalSize = 0;
    my ($nCachedDummyEnd_BaseAddr);   
    my $mode = &$feature_query_function_ptr('MODE');
    my ($nTxSize, $nRxSize) = &sysUtil::DSPTXRX_query_length($bb, $mode);
    $nCachedDummyEnd_BaseAddr = $rs - $nTxSize - $nRxSize;
    
    my $j2me_support = &$feature_query_function_ptr('j2me_support');
    if (defined $j2me_support and $j2me_support =~ /JBLENDIA/)
    {
        $nCachedDummyEnd_BaseAddr -= (128*1024); # jblend_ram
    }
    # --- --- ---
    # DCM Compression region
    if(defined $dcmp and $dcmp eq 'TRUE')
    {
        $lv_dcmp_basic = &DCMP_basic_template($RegionInfo_ref->{'DYNAMIC_COMP_CODE'}->[0], $bb) if ($Is_Flashtool_Layout != 1); #DCMP lv base address
        ($nDCMP_evTotalSize, $lv_dcmp_code) = &DCMP_code_layout($bb, $nCachedDummyEnd_BaseAddr);
    }
    # --- --- ---
    # ALICE region
    my $alice_Layout = &layoutALICE("+0x0") if(defined $alice and $alice eq 'TRUE');
    # --- --- ---
    # MBA region
    my $ev_lang_pack;
    my $ev_custpack_rom;
    my $ev_jump_table;
    my $strMBA_Layout;
    if(defined $mba and $mba eq 'TRUE')
    {
        $ev_lang_pack         = &layout2_lang_ev($RegionInfo_ref->{LANG_PACK_ROM}->[0], $bb);
        $ev_custpack_rom      = &layout2_cust_ev($bb);
        $ev_jump_table        = &layout2_jump_ev($bb);    # ev start address remains +0x0, which means to start from lv start address
        my $mba_bin = &$feature_query_function_ptr('mba_default_binary');
        my $lv_lang_pack;
        my $lv_cust_pack;
        my $lv_mba;

        $lv_lang_pack = <<"__LANGPACK";
LANG_PACK_ROM $RegionInfo_ref->{LANG_PACK_ROM}->[0] $RegionInfo_ref->{LANG_PACK_ROM}->[1]
{
$ev_lang_pack
}
__LANGPACK
        $lv_cust_pack = <<"__CUSTPACK";
CUSTPACK_ROM $RegionInfo_ref->{CUSTPACK_ROM}->[0] $RegionInfo_ref->{CUSTPACK_ROM}->[1]
{
$ev_custpack_rom
}    	
__CUSTPACK

        if(!defined $mba_bin or (defined $mba_bin and $mba_bin eq 'CUST_AND_LANG'))
        {
            $lv_mba = $lv_lang_pack.$lv_cust_pack;
        }
        elsif(defined $mba_bin and $mba_bin eq 'LANG_ONLY')
        {
            $lv_mba = $lv_lang_pack;	
        }       
        elsif(defined $mba_bin and $mba_bin eq 'CUST_ONLY')
        {
            $lv_mba = $lv_cust_pack;
        }
    
        $strMBA_Layout = << "__TEMPLATE";
$lv_mba
JUMP_TABLE $RegionInfo_ref->{JUMP_TABLE}->[0] $RegionInfo_ref->{JUMP_TABLE}->[1]
{
$ev_jump_table
}
__TEMPLATE

    }
    # --- --- ---
    #SECURE region
    my $ev_hidden_secure_mac;
    my $ev_hidden_secure_ro;
    my $ev_hidden_toolcfg;
    my $ev_hidden_custpara;
    my $strSECURE_LAYOUT;
    if(defined $secure and $secure eq 'TRUE')
    {
        $ev_hidden_secure_mac = ($fota eq "FOTA_DM") ? &layout3_fota_secure_mac_ev() : &layout3_secure_mac_ev();
        $ev_hidden_secure_ro  = &layout3_secure_ro_ev($RegionInfo_ref->{'SECURE_RO'}->[0]);
        $ev_hidden_toolcfg    = &layout3_toolcfg_ev($RegionInfo_ref->{'FLASHTOOL_CFG'}->[0]);
        $ev_hidden_custpara   = &layout3_custpara_ev($RegionInfo_ref->{'CUST_PARA'}->[0]);      
        $strSECURE_LAYOUT = <<"__LAYOUT";
;=========================================================================
; This load region must be behind all the protected load region
;=========================================================================
; 1. DO NOT modify load region naming and pragma naming!
;=========================================================================

__HIDDEN_SECURE_MAC $RegionInfo_ref->{'SECURE_MAC'}->[0] $strLVAttribute $RegionInfo_ref->{'SECURE_MAC'}->[1]
{
$ev_hidden_secure_mac
}
$boot_cert_rom
;=========================================================================
; The following load regions must be the end of all the load regions
;=========================================================================
; 1. Only address is configurable.
; 2. Region address must be fixed address.
; 3. Using flash-sector-aligned address in region address for higher security.
; 4. DO NOT modify load region order, load region naming and pragma naming!
;=========================================================================
__HIDDEN_SECURE_RO $RegionInfo_ref->{'SECURE_RO'}->[0] $strLVAttribute $RegionInfo_ref->{'SECURE_RO'}->[1]
{
$ev_hidden_secure_ro
}
__HIDDEN_FLASHTOOL_CFG $RegionInfo_ref->{'FLASHTOOL_CFG'}->[0] $strLVAttribute $RegionInfo_ref->{'FLASHTOOL_CFG'}->[1]
{
$ev_hidden_toolcfg
}
__HIDDEN_CUST_PARA $RegionInfo_ref->{'CUST_PARA'}->[0] $strLVAttribute $RegionInfo_ref->{'CUST_PARA'}->[1]
{
$ev_hidden_custpara
}
__LAYOUT
    }
# --- --- ---
# Total layout
    my $str_LAYOUT;
    $str_LAYOUT  = $strMBA_Layout if((defined $mba and $mba eq 'TRUE') and (defined $fota and $fota eq 'FOTA_DM'));
    $str_LAYOUT .= $viva_Layout if(((defined $dcmp and $dcmp eq 'TRUE') or (defined $alice and $alice eq 'TRUE')) and ($mba eq 'TRUE'));	
    $str_LAYOUT .= $lv_dcmp_basic."\n".$lv_dcmp_code if(defined $dcmp and $dcmp eq 'TRUE');
    $str_LAYOUT .= $alice_Layout if(defined $alice and $alice eq 'TRUE');
    $str_LAYOUT .= (defined $secure and $secure eq 'TRUE' and &sysUtil::is_sv5($bb) != 1)? $strSECURE_LAYOUT : $boot_cert_rom;
      
    return ($str_LAYOUT, $nDCMP_evTotalSize)
}
#****************************************************************************
# subroutine:  CombinationBin Layout
# input:       $bb: BaseBandChip Name (no use now)
#              $nfb_or_emb : NONE == NOR, other = NAND
#              $current start address
#              $bin_size
#              $rs: EXTSRAM size
# output:      the body strings
#****************************************************************************
sub layout16
{
    my ($bb, $nfb_or_emb, $nCurrentStartAddr, $nBinSize, $rs) = @_;
    my $strLayout;
    my $strBase = &CommonUtil::Dec2Hex($nCurrentStartAddr);

    # --- --- ---
    # Configure Primary ROM and SECONDARY_ROM base address, including DSP_ROM, based on DSP existence
    my ($rom_start_address, $second_rom_start_address) = &config_query_nfb_rom_secrom_base_address($rs);

    my $strNANDTemplate = <<"__LAYOUT";
FACTORY_ROM $rom_start_address
{
}

FACTORY_SECONDARY_ROM $second_rom_start_address
{
}

__LAYOUT

    my $strNORTemplate = <<"__LAYOUT";
FACTORY_ROM $strBase
{
}

__LAYOUT

    #if($nfb_or_emb eq 'NONE')
    if(0 == &isNAND($feature_query_function_ptr))
    {
        $strLayout = $strNORTemplate;   
        # Set Next Region(ROM) offset is block aligned
        &config_add_rom_offset( $nBinSize );
    }
    else
    {
        $strLayout = $strNANDTemplate;
    }
    return $strLayout;
}
#****************************************************************************
# subroutine:  NOR Layout: DCM Compression ONLY Layout
# input:       $bb: BaseBandChip Name
#              $flash_size: flash size(may be filesystem's start address?)
#              $rs: actual ram size
# output:      the body strings
#****************************************************************************
sub layout15 #DCMP_ONLY
{
    my ($bb, $flash_size, $rs, $boot_cert) = @_;
    my $viva_header_size = &sysUtil::query_viva_size($bb);
    &sysUtil::sysgen_die("$bb_folder/custom_FeatureConfig.h: CONFIG_DCMP_MAX_COMPRESSED_SIZE need to be defined when DCM_COMPRESION_SUPPORT is turned on!", __FILE__, __LINE__)
       if (!defined($feature_config_href->{'CONFIG_DCMP_MAX_COMPRESSED_SIZE'}));    
    my $nDCMCompressedSize = hex($feature_config_href->{'CONFIG_DCMP_MAX_COMPRESSED_SIZE'});
    # --- --- ---
    if (($flash_size - &config_query_rom_offset() - 0x400 - $viva_header_size) < $nDCMCompressedSize) #VIVA +0x400
    {
        &sysUtil::sysgen_die("FlashSize isn't big enough to put in DCM Compression", __FILE__, __LINE__);
    }
    my $fbase   = sprintf("0x%08x", &lv_rom_fbase($bb));
    my $available_rom = $flash_size - &config_query_rom_offset() - 0x400 - $viva_header_size - $nDCMCompressedSize;
    # if secure support
    my $secure = &$feature_query_function_ptr('secure_support');
    my $bottom_region_size = 0;
    my $lv_bottom;
    my $useless;
    if(defined $secure and $secure eq 'TRUE' || ($boot_cert ne 'FALSE' and $boot_cert ne 'NONE'))
    {
        my $fast_boot = &$feature_query_function_ptr('split_binary_support');
        my $SECURE_MAC_BLOCKSIZE = (defined $fast_boot and $fast_boot ne 'NONE') ? 2 : 1;
        my %RegionSetting = ('BOOT_CERT'     => [ OCCUPIED_SIZE, 4 * 1024, undef ],
                             'SECURE_MAC'    => [ BLOCK_ALIGNED, $SECURE_MAC_BLOCKSIZE, undef ],
                             'SECURE_RO'     => [ BLOCK_ALIGNED, 1, undef ],
                             'FLASHTOOL_CFG' => [ BLOCK_ALIGNED, 1, undef ],
                             'CUST_PARA'     => [ BLOCK_ALIGNED, 1, undef ]);
        ($bottom_region_size, $lv_bottom, $useless) = &BOTTOM_NOR_LV_Layout($bb, $flash_size, undef, 1, \%RegionSetting); #OVERLAY
        &WarnMinus(($available_rom - $bottom_region_size), __FILE__, __LINE__, "FlashSize(fs-offset-DCMCompressedSize): "
        .&CommonUtil::Dec2Hex($available_rom).") isn't big enough to put in BOTTOM regions(".&CommonUtil::Dec2Hex($bottom_region_size).")");
        $available_rom -= $bottom_region_size;
    }
    # --- --- ---
    #VIVA Layout
    my $lv_viva = &layoutVIVA("+0x400", &CommonUtil::Dec2Hex($viva_header_size), $bb);    
    
    ### Calculate DCMP End address
    my ($nCachedDummyEnd_BaseAddr);
    
    my $mode = &$feature_query_function_ptr('MODE');
    my ($nTxSize, $nRxSize) = &sysUtil::DSPTXRX_query_length($bb, $mode);
    $nCachedDummyEnd_BaseAddr = $rs - $nTxSize - $nRxSize;
    
    my $j2me_support = &$feature_query_function_ptr('j2me_support');
    if (defined $j2me_support and $j2me_support =~ /JBLENDIA/)
    {
        $nCachedDummyEnd_BaseAddr -= (128*1024); # jblend_ram
    }
    # --- --- ---
    #DCM Compression Layout
    my $lv_dcmp_basic = &DCMP_basic_template('+0x0', $bb) if ($Is_Flashtool_Layout != 1); 
    my ($DCMP_TotalSize, $lv_dcmp_code) = &DCMP_code_layout($bb, $nCachedDummyEnd_BaseAddr);
    # --- --- ---
    #ALICE Layout
    my $alice = &$feature_query_function_ptr('alice_support');
    my $lv_alice;
    if(defined $alice and $alice eq 'TRUE')
    {
        &sysUtil::sysgen_die("$bb_folder/custom_FeatureConfig.h: CONFIG_ALICE_MAX_COMPRESSED_SIZE need to be defined when ALICE_SUPPORT is turned on!", __FILE__, __LINE__)
           if (!defined($feature_config_href->{'CONFIG_ALICE_MAX_COMPRESSED_SIZE'}));
        my $comp_alice = $feature_config_href->{'CONFIG_ALICE_MAX_COMPRESSED_SIZE'};        
        if ($available_rom < hex($comp_alice))
        {
            &sysUtil::sysgen_die("$bb_folder/custom_FeatureConfig.h: CONFIG_ALICE_MAX_COMPRESSED_SIZE cannot be configured larger than available ROM size! Please configure CONFIG_ALICE_MAX_COMPRESSED_SIZE within ".&CommonUtil::Dec2Hex($available_rom)."!", __FILE__, __LINE__);
        }      	  
        $lv_alice = &layoutALICE("+0x0");	
        $available_rom -= hex($comp_alice);
    }
    # --- --- ---
    my $flength = &CommonUtil::Dec2Hex($available_rom);    
    my $ev_rom_default = &layout0_rom_ev($bb, $fbase, $rs, $flength, &CommonUtil::Dec2Hex($DCMP_TotalSize));
    chomp $ev_rom_default;

    my $template = <<"__LAYOUT";
; ROM Load region is block-aligned
ROM $fbase
{
$ev_rom_default
}

$lv_viva
$lv_dcmp_basic
$lv_dcmp_code
$lv_alice
$lv_bottom
__LAYOUT
    return $template;
}
#****************************************************************************
# subroutine:  BOOT_CERT Layout <Class>
# return:      the body strings
#****************************************************************************
sub layout14
{
    my ($bb, $base_addr, $size, $strLVAttribute) = @_;
    my $alice = &$feature_query_function_ptr('alice_support');
    my $boot_cert_ev_base;    
    $boot_cert_ev_base = (defined $alice and $alice eq 'TRUE')?
    sprintf("0x%08x", hex($base_addr) ^ (config_query_flash_base_address($bb)) ^ 0x90000000) : "+0x0";       
    my $template = <<"__TEMPLATE";
BOOT_CERT $base_addr $strLVAttribute $size
{
    BOOT_CERT $boot_cert_ev_base
    {
         *.obj (BOOT_CERT_DATA)
    }
    BOOT_CERT_SIG +0x0
    {
         *.obj (BOOT_CERT_SIG)
    }
}
__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  BOOT_ZIMAGE Layout <Class>
# return:      the body strings
#****************************************************************************
sub layoutBOOT_ZIMAGE
{
    my ($ev_base) = @_;
    my $boot_zimage_list = ($dummy_scatter ne 'TRUE') ? &Get_ObjListGen_List('objectBOOT_ZIMAGE.list') : &Get_ObjListGen_List('objectBOOT_ZIMAGE_dummy.list');
    if($Is_Flashtool_Layout == 1) #If not flash tool, still need the following layout.
    {
        return (undef);
    }
    my $template = <<"__TEMPLATE";
BOOT_ZIMAGE +0x0
{
    BOOT_ZIMAGE_ER $ev_base
    {
$boot_zimage_list
    }
}
__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  ALICE Layout <Class>
# return:      the body strings
#****************************************************************************
sub layoutALICE
{
    my ($base_addr) = @_;
    my $zimage = &$feature_query_function_ptr('zimage_support');
    my $boot_zimage = &$feature_query_function_ptr('boot_zimage_support');    
    my $aliceList = ($dummy_scatter ne 'TRUE') ? &Get_ObjListGen_List('objectALICE.list') : &Get_ObjListGen_List('objectALICE_dummy.list');
    my $ro_code;
    
    if($Is_Flashtool_Layout == 1) #If not flash tool, still need the following layout.
    {
    	return (undef);
    }
    
    if ((!defined $zimage or (defined $zimage and $zimage ne 'TRUE')) and (!defined $boot_zimage or (defined $boot_zimage and $boot_zimage ne 'TRUE')))
    {
        $ro_code = "        *                             (+RO-CODE)";
    }
    my $template = <<"__TEMPLATE";
ALICE $base_addr ALIGN 128
{
    ALICE +0x0 OVERLAY $size
    {
        *                             (ALICE_FIRST, +First)
$ro_code
$aliceList
    }
}
__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  VIVA Layout <Class>
# return:      the body strings
#****************************************************************************
sub layoutVIVA
{
    my ($base_addr, $size, $bb) = @_;
    my $viva_gfh;
    if(&sysUtil::is_sv5($bb) == 1)
    {
        $viva_gfh = <<"__VIVAGFH";
    VIVA_GFH +0x0 ; Only exist on SV5 platform
    {
        *                             (VIVA_GFH)
    }
__VIVAGFH
    }
  
    my $template = <<"__TEMPLATE";
VIVA $base_addr $size
{
$viva_gfh
    VIVA +0x0
    {
        *                             (VIVA)
    }
}
__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  BOOTLOADER Layout for SV5 <Class>
# return:      the body strings
#****************************************************************************
sub layout13
{
    my ($bb) = @_;
    # --- --- ---
    my $package_seg = &$feature_query_function_ptr('package_seg');
    my $ext_bl_update_support = &$feature_query_function_ptr('ext_bl_update_support');
    my $card_dl = &$feature_query_function_ptr('card_download');
    my ($HEADER_BLOCK_MIN_SIZE, $BL_MIN_SIZE, $ROOT_CERT_MIN_SIZE, $EXT_BL_MIN_SIZE, $EXT_BL_BAK_MIN_SIZE);
    if ($package_seg eq '16_3_SEG')
    {
        $HEADER_BLOCK_MIN_SIZE = 2 * 1024;
        $BL_MIN_SIZE = 6 * 1024;
        $ROOT_CERT_MIN_SIZE = 0;
        $EXT_BL_MIN_SIZE = 4 * 1024;
        $EXT_BL_BAK_MIN_SIZE = 0;
    }    
    elsif (($bb eq 'MT6250') and ($package_seg eq '32_32_SEG'))
    {
        $HEADER_BLOCK_MIN_SIZE = 2 * 1024;
        $BL_MIN_SIZE = 10 * 1024;
        $ROOT_CERT_MIN_SIZE = 0;
        $EXT_BL_MIN_SIZE = 8 * 1024;
        $EXT_BL_BAK_MIN_SIZE = 0;
    }
    elsif ((!defined $ext_bl_update_support) or (defined $ext_bl_update_support and $ext_bl_update_support eq 'FALSE'))
    {#if not support ext_bl_update_support
        $HEADER_BLOCK_MIN_SIZE = 4 * 1024;
        $BL_MIN_SIZE = 24 * 1024;
        $ROOT_CERT_MIN_SIZE = 4 * 1024;
        $EXT_BL_MIN_SIZE = 96 * 1024;
        $EXT_BL_BAK_MIN_SIZE = 0;
        $EXT_BL_MIN_SIZE = 224 * 1024 if (defined $card_dl and $card_dl ne 'NONE');
    }
    else
    {
        $HEADER_BLOCK_MIN_SIZE = 4 * 1024;
        $BL_MIN_SIZE = 24 * 1024;
        $ROOT_CERT_MIN_SIZE = 4 * 1024;
        $EXT_BL_MIN_SIZE = hex($fota_cfg_href->{'BL_IMG_MAX_SIZE'});
        $EXT_BL_BAK_MIN_SIZE = hex($fota_cfg_href->{'BL_IMG_MAX_SIZE'});
    }
    
    $BL_MIN_SIZE = (exists $feature_config_href->{MAX_BL_SIZE}) ? 
                                hex($feature_config_href->{MAX_BL_SIZE}) : $BL_MIN_SIZE;
    $EXT_BL_MIN_SIZE = (exists $feature_config_href->{MAX_EXT_BL_SIZE}) ? 
                                hex($feature_config_href->{MAX_EXT_BL_SIZE}) : $EXT_BL_MIN_SIZE;
    $EXT_BL_BAK_MIN_SIZE = (exists $feature_config_href->{MAX_EXT_BL_SIZE}) ? 
                                hex($feature_config_href->{MAX_EXT_BL_SIZE}) : $EXT_BL_BAK_MIN_SIZE;
    ### Header Block starts at 0
    my $header_block_base = 0;  # Header Block base without remap
    my $header_block_base_str = sprintf("0x%08x", $header_block_base + &config_query_flash_base_address($bb));
    my $header_block_size = $HEADER_BLOCK_MIN_SIZE;
    my $header_block_size_str = sprintf("0x%08x", $header_block_size);
    
    ### BL is behind Header Block
    my $bl_base = $header_block_base + $header_block_size;  # BL base without remap
    my $bl_base_str = sprintf("0x%08x", $bl_base + &config_query_flash_base_address($bb));
    my $bl_size = $BL_MIN_SIZE;
    my $bl_size_str = sprintf("0x%08x", $bl_size);
    
    ### ROOT_CERT is behind BL
    my $root_cert_base = $bl_base + $bl_size;  # ROOT_CERT base without remap
    my $root_cert_base_str = sprintf("0x%08x", $root_cert_base + &config_query_flash_base_address($bb));
    my $root_cert_size = $ROOT_CERT_MIN_SIZE;
    my $root_cert_size_str = sprintf("0x%08x", $root_cert_size);
    
    ### EXT_BOOTLOADER is behind ROOT_CERT and should be block-aligned if EXT_BL_UPDATE_SUPPORT is turned on
    my $ext_bl_base = (defined $ext_bl_update_support and $ext_bl_update_support eq 'TRUE') ? (&config_query_next_block_aligned_addr($root_cert_base, $root_cert_size)) : ($root_cert_base + $root_cert_size);  # EXT_BL base without remap
    my $ext_bl_base_str = sprintf("0x%08x", $ext_bl_base + &config_query_flash_base_address($bb));
    my $ext_bl_size = (defined $ext_bl_update_support and $ext_bl_update_support eq 'TRUE') ? (&config_query_next_block_aligned_addr($ext_bl_base, $EXT_BL_MIN_SIZE) - $ext_bl_base) : ($EXT_BL_MIN_SIZE);
    my $ext_bl_size_str = sprintf("0x%08x", $ext_bl_size);
    
    ### EXT_BOOTLOADER_BAK is behind EXT_BOOTLOADER and should be block-aligned
    my ($ext_bl_bak_base, $ext_bl_bak_size) = (($ext_bl_base + $ext_bl_size), 0); 
    if(&FileInfo::is("ext_bl_update_support", "TRUE"))
    {
        $ext_bl_bak_base = (&config_query_next_block_aligned_addr($ext_bl_base, $ext_bl_size));  # EXT_BL base without remap
        $ext_bl_bak_size = &config_query_next_block_aligned_addr($ext_bl_bak_base, $EXT_BL_BAK_MIN_SIZE) - $ext_bl_bak_base;
    }
    my $ext_bl_bak_base_str = sprintf("0x%08x", $ext_bl_bak_base + &config_query_flash_base_address($bb)); 
    my $ext_bl_bak_size_str = sprintf("0x%08x", $ext_bl_bak_size);
    
    ### CBR is behind EXT_BOOTLOADER
    my $cbr_region;
    my $cbr_blk = $fota_cfg_href->{'CBR_REGION_NORMAL_BLOCK_NUM'}*2+$fota_cfg_href->{'CBR_REGION_SPARE_BLOCK_NUM'};
    my $cbr_base = $ext_bl_bak_size==0 ? &config_query_next_block_aligned_addr($ext_bl_base, $ext_bl_size)
                                       : &config_query_next_block_aligned_addr($ext_bl_bak_base, $ext_bl_bak_size);  # CBR base without remap
    my $cbr_base_str = sprintf("0x%08x", $cbr_base + &config_query_flash_base_address($bb));
    my $cbr_size = $cbr_blk * (64*1024);  # CBR block is treated as 64KB
    my $cbr_size_str = sprintf("0x%08x", $cbr_size);

    ### Set MAUI ROM start offset
    &config_add_rom_offset($cbr_base+$cbr_size);

    ### EXT_BOOTLOADER_BAK only exists when EXT_BL_UPDATE_SUPPORT is turned on
    my $ext_bootloader_bak_lv;
    if (&FileInfo::is("ext_bl_update_support", "TRUE"))
    {
    	$ext_bootloader_bak_lv = <<"__TEMPLATE";
EXT_BOOTLOADER_BAK $ext_bl_bak_base_str $ext_bl_bak_size_str
{
}
__TEMPLATE
    }
    chomp $ext_bootloader_bak_lv;
    
    # --- --- --- 
    my $layout_default = <<"__LAYOUT";
BOOTLOADER $bl_base_str $bl_size_str
{
}

ROOT_CERT $root_cert_base_str $root_cert_size_str
{
    ; reserved region for secure chip project
}

EXT_BOOTLOADER $ext_bl_base_str $ext_bl_size_str
{
}

$ext_bootloader_bak_lv

CBR $cbr_base_str $cbr_size_str
{
    ; reserved for bootup and features
}

__LAYOUT

    # --- --- --- 
    my $layout_small_seg = <<"__LAYOUT";
BOOTLOADER $bl_base_str $bl_size_str
{
}

EXT_BOOTLOADER $ext_bl_base_str $ext_bl_size_str
{
}

__LAYOUT

    # --- --- ---
    if ((($bb eq 'MT6251') and ($package_seg eq '16_3_SEG')) 
    or (($bb eq 'MT6250') and ($package_seg eq '32_32_SEG')))
    {
    	return $layout_small_seg;
    }
    else
    {
    	return $layout_default;
    }
}
#****************************************************************************
# subroutine:  GetDummyEnd
# return:      1. Base address
#              2. Offset
#              3. regioninfo
#****************************************************************************
sub GetDummyEnd
{
    my ($bb, $rs) = @_;
    my ($nBase, $nOffset) = ($rs, 0);
    my %RegionInfo; # [KeyName, nSize, nOffset]
    
    if($bb eq "MT6256")
    {
        my ($strTx1Size, $strTx2Size, $strDSPOnlySize, $strRxSize, $strDSP_RomSize)= &Query_DSP_MT6256_Info(1, $rs);
        $nOffset = hex($strTx1Size) + hex($strTx2Size) + hex($strDSPOnlySize) + hex($strRxSize) + hex($strDSP_RomSize);
    }
    else
    {
        #TX, RX
        my $mode = &$feature_query_function_ptr('MODE');
        my ($region_size_tx, $region_size_rx) = &sysUtil::DSPTXRX_query_length($bb, $mode);
        $nOffset = $region_size_tx + $region_size_rx;
        
        # Sharemem
        my ($dsp_sharemem_size, $mcu_c_dsp_c_len, $mcu_c_dsp_nc_len, $mcu_nc_dsp_c_len, $mcu_nc_dsp_nc_len) = &DSP_SHAREMEM_query_length($bb);
        $nOffset += $dsp_sharemem_size; 
        $RegionInfo{"SHAREMEM"} = [ $dsp_sharemem_size, $nOffset ];
    }
    #Extsram Temp page table = aligned 16K
    if(defined &Query_EXTSRAM_PAGETABLE_SupportBB($bb))
    {
        $nOffset += &Query_EXTSRAM_PAGETABLE_SupportBB($bb);
        $nRemainder = ($rs - $nOffset) % (16*1024);
        $nOffset += $nRemainder; 
        $RegionInfo{"EXTSRAM_TMPPAGETABLE"} = [ &Query_EXTSRAM_PAGETABLE_SupportBB($bb), $nOffset ];
    }
    # jblend region = 128K
    my $j2me_support = &$feature_query_function_ptr('j2me_support');
    if (defined $j2me_support and $j2me_support =~ /JBLENDIA/)
    {
        $nOffset += (128*1024);
        $RegionInfo{"JBLEND"} = [ 128*1024, $nOffset ];
    }
     
    
    my $isNAND = &isNAND($feature_query_function_ptr);
    #NOR: if dcmp only, nOffset should add dcmp size.

    
    #NAND: if secure's on, it should add secure's region
    if($isNAND or &is_SINGLE($feature_query_function_ptr))
    {
        if(&$feature_query_function_ptr('secure_support') eq "TRUE" and (!&sysUtil::is_sv5($bb)))
        {
            my $flash_custpara_size       = 8 * 1024;
            my $flash_toolcfg_size        = 4 * 1024;
            my $flash_secure_ro_size      = 4 * 1024;
            my $flash_secure_mac_size     = 4 * 1024;
            $nOffset += $flash_custpara_size;
            $RegionInfo{"CUST_PARA"} = [ $flash_custpara_size, $nOffset ];
            $nOffset += $flash_toolcfg_size;
            $RegionInfo{"FLASH_TOOLCFG"} = [ $flash_toolcfg_size, $nOffset ];
            $nOffset += $flash_secure_ro_size;
            $RegionInfo{"SECURE_RO"} = [ $flash_secure_ro_size, $nOffset ];
            $nOffset += $flash_secure_mac_size;
            $RegionInfo{"SECURE_MAC"} = [ $flash_secure_mac_size, $nOffset ];
        }
        my $boot_cert = &$feature_query_function_ptr('boot_cert_support');
        if($boot_cert ne 'FALSE' and $boot_cert ne 'NONE')
        {
            my $flash_boot_cert_size      = 4 * 1024;
            $nOffset += $flash_boot_cert_size;
            $RegionInfo{"BOOT_CERT"} = [ $flash_boot_cert_size, $nOffset ];
        }
    }
    
    return ($rs-$nOffset, $nOffset, \%RegionInfo);
}

#****************************************************************************
# subroutine:  ZIMAGE Layout <Class>
# return:      the body strings
#****************************************************************************
sub layout12
{
    my ($bb, $fs, $rs, $comp_zlength, $boot_cert) = @_;
    my $viva_header_size = &sysUtil::query_viva_size($bb);
    # --- --- ---
    my $fbase   = sprintf("0x%08x", &lv_rom_fbase($bb));
    my $available_rom = $fs - &config_query_rom_offset() - 0x400 - $viva_header_size; #VIVA +0x400
    &WarnMinus(($available_rom - hex($comp_zlength)), __FILE__, __LINE__, "$bb_folder/custom_FeatureConfig.h: CONFIG_ZIMAGE_MAX_COMPRESSED_SIZE cannot be configured larger than available ROM size! Please configure CONFIG_ZIMAGE_MAX_COMPRESSED_SIZE within ".&CommonUtil::Dec2Hex($available_rom)."!");
    $available_rom -= hex($comp_zlength);
    # if secure support
    my $secure = &$feature_query_function_ptr('secure_support');
    ### Get bottom regions
    my $bottom_region_size = 0;
    my $lv_bottom;
    my $useless;
    if(defined $secure and $secure eq 'TRUE' || ($boot_cert ne 'FALSE' and $boot_cert ne 'NONE'))
    {  
        my $fast_boot = &$feature_query_function_ptr('split_binary_support');
        my $SECURE_MAC_BLOCKSIZE = (defined $fast_boot and $fast_boot ne 'NONE') ? 2 : 1;
        my %RegionSetting = ('BOOT_CERT'     => [ OCCUPIED_SIZE, 4 * 1024, undef ],
                             'SECURE_MAC'    => [ BLOCK_ALIGNED, $SECURE_MAC_BLOCKSIZE, undef ],
                             'SECURE_RO'     => [ BLOCK_ALIGNED, 1, undef ],
                             'FLASHTOOL_CFG' => [ BLOCK_ALIGNED, 1, undef ],
                             'CUST_PARA'     => [ BLOCK_ALIGNED, 1, undef ]);
        ($bottom_region_size, $lv_bottom, $useless) = &BOTTOM_NOR_LV_Layout($bb, $fs, undef, 1, \%RegionSetting); #OVERLAY
        &WarnMinus(($available_rom - $bottom_region_size), __FILE__, __LINE__, "FlashSize(fs-0x400-comp_size: ".&CommonUtil::Dec2Hex($available_rom).") isn't big enough to put in BOTTOM regions(".&CommonUtil::Dec2Hex($secure_size).")");
        $available_rom -= $bottom_region_size;
    }
    ### Get VIVA-related region size
    my $dcm_compression_support = &$feature_query_function_ptr('dcm_compression_support');
    my $alice = &$feature_query_function_ptr('alice_support');
    my $boot_zimage = &$feature_query_function_ptr('boot_zimage_support');
    my $nDCMCompressedSize = 0;
    my $comp_alice = 0;
    my $comp_boot_zimage = 0;
    if(defined $dcm_compression_support and $dcm_compression_support eq 'TRUE')
    {
        &sysUtil::sysgen_die("$bb_folder/custom_FeatureConfig.h: CONFIG_DCMP_MAX_COMPRESSED_SIZE need to be defined when DCM_COMPRESION_SUPPORT is turned on!", __FILE__, __LINE__)
          if (!defined($feature_config_href->{'CONFIG_DCMP_MAX_COMPRESSED_SIZE'}));    
        $nDCMCompressedSize = hex($feature_config_href->{'CONFIG_DCMP_MAX_COMPRESSED_SIZE'});
    }
    if(defined $alice and $alice eq 'TRUE')
    {
        &sysUtil::sysgen_die("$bb_folder/custom_FeatureConfig.h: CONFIG_ALICE_MAX_COMPRESSED_SIZE need to be defined when ALICE_SUPPORT is turned on!", __FILE__, __LINE__)
          if (!defined($feature_config_href->{'CONFIG_ALICE_MAX_COMPRESSED_SIZE'}));
        $comp_alice = hex($feature_config_href->{'CONFIG_ALICE_MAX_COMPRESSED_SIZE'});
    }
    if(defined $boot_zimage and $boot_zimage eq 'TRUE')
    {
        &sysUtil::sysgen_die("$bb_folder/custom_FeatureConfig.h: CONFIG_BOOT_ZIMAGE_MAX_COMPRESSED_SIZE need to be defined when BOOT_ZIAMGE_SUPPORT is turned on!", __FILE__, __LINE__)
          if (!defined($feature_config_href->{'CONFIG_BOOT_ZIMAGE_MAX_COMPRESSED_SIZE'}));
        $comp_boot_zimage = hex($feature_config_href->{'CONFIG_BOOT_ZIMAGE_MAX_COMPRESSED_SIZE'});
    }
    my $total_viva_regions = $comp_boot_zimage + $nDCMCompressedSize + $comp_alice;
    &WarnMinus($available_rom - $total_viva_regions
    , "flash can't put in VIVA regions:\n
    DCM compressed region($nDCMCompressedSize)/ALICE region($comp_alice)/BOOT_ZIMAGE regions($comp_boot_zimage)",  __FILE__, __LINE__);
    $available_rom -= $total_viva_regions;
    my $flength = &CommonUtil::Dec2Hex($available_rom);

    ### VIVA layout
    my $lv_viva = &layoutVIVA("+0x400", &CommonUtil::Dec2Hex($viva_header_size), $bb);
    ### DCM with Compression layout
    my ($cached_dummy_end_start_address_val, $nOffset, $temp_ref) = &GetDummyEnd($bb, $rs); # Calculate DCMP start addresses
    my ($lv_dcmp_basic, $lv_dcmp_code);
    my $DCMP_TotalSize = 0;
    if(defined $dcm_compression_support and $dcm_compression_support eq 'TRUE')
    {
        $lv_dcmp_basic = &DCMP_basic_template('+0x0', $bb) if($Is_Flashtool_Layout != 1);
        #DSP_TX, and DSP_RX start addresses will be 4KB-aligned
        ($DCMP_TotalSize, $lv_dcmp_code) = &DCMP_code_layout($bb, $cached_dummy_end_start_address_val);
        $cached_dummy_end_start_address_val -= $DCMP_TotalSize;
    }
    my $dcmp_ram_size = &CommonUtil::Dec2Hex($DCMP_TotalSize);
    # Let cached_dummy_end get original start address(which depends on $DCMP_TotalSize)
    my $ev_rom_default = &layout0_rom_ev($bb, $fbase, $rs, $flength, $dcmp_ram_size);
    chomp $ev_rom_default;
    # --- --- --- 
    ### ALICE layout
    my $lv_alice;
    if(defined $alice and $alice eq 'TRUE')
    {
        $lv_alice = &layoutALICE("+0x0");
    }
    ### BOOT_ZIMAGE layout
    # Get the EXTSRAM layout before getting last region of it    
    my $previous_region = &GetRegion_before_cached_dummy_end();
    my $comp_boot_zimage;
    my $lv_boot_zimage;
    if(defined $boot_zimage and $boot_zimage eq 'TRUE')
    {
        my $boot_zimage_ev_base = "ImageLimit($previous_region)";
        $lv_boot_zimage = &layoutBOOT_ZIMAGE($boot_zimage_ev_base);
    }
    
    ### Get ZIMAGE-related infomations
    my $zimage_ram_base = (defined $boot_zimage and $boot_zimage eq 'TRUE')? "ImageLimit(BOOT_ZIMAGE_ER)" : "ImageLimit($previous_region)";
    my $zimage_attribute = (defined $boot_zimage and $boot_zimage eq 'TRUE') ? "OVERLAY" : "";
    my $ev_rom_zimage = &GetInputSections("ZIMAGE");
    my $zimageList = ($dummy_scatter ne 'TRUE')? &Get_ObjListGen_List('objectZIMAGE.list') : &Get_ObjListGen_List('objectZIMAGE_dummy.list');
    $ev_rom_zimage .= $zimageList;
    chomp $ev_rom_zimage;

    
    my $ZIMAGE_DUMMY;
    if ($dummy_scatter eq 'TRUE')
    {
        $ZIMAGE_DUMMY = <<"__ANY_RO";
    ZIMAGE_DUMMY_CODE +0x0
    {
         *                             (+RO-CODE)
    }
    ZIMAGE_DUMMY_DATA +0x0
    {
         *                             (+RO-DATA)
    }
__ANY_RO
         chomp $ZIMAGE_DUMMY;
    } 
    my $layout_zimage;
    if($Is_Flashtool_Layout != 1)
    {
        $layout_zimage = <<"__ZIMAGE_LAYOUT";
ZIMAGE +0x0
{
    ZIMAGE_ER $zimage_ram_base $zimage_attribute
    {
$ev_rom_zimage
    }
$ZIMAGE_DUMMY
ScatterAssert(ImageLimit(ZIMAGE_ER) < ImageBase(CACHED_DUMMY_END))
}
__ZIMAGE_LAYOUT
    }
    
    my $layout_default = <<"__LAYOUT";
; ROM Load region is block-aligned
ROM $fbase
{
$ev_rom_default
}
$lv_viva
$lv_boot_zimage
$layout_zimage
$lv_dcmp_basic
$lv_dcmp_code
$lv_alice
$lv_bottom
__LAYOUT
    return $layout_default;
}

#****************************************************************************
# subroutine:  SECURE_RO Layout <Class>
# return:      the body strings
#****************************************************************************
sub layout11
{
    my $template = <<"__TEMPLATE";
SECURE_RO_ME +0x0
{
    SECURE_RO_ME_GFH +0x0 
    {
         *                             (SECURE_RO_ME_GFH, +First)
         *                             (SECURE_RO_ME_GFH_EXT)
    }
    SECURE_RO_ME +0x0
    {
         *.obj (SECURE_RO)
    }
    SECURE_RO_ME_SIGNATURE_SECTION +0x0
    {
         *                             (SECURE_RO_ME_SIGNATURE_SECTION)
    }    
}

SECURE_RO_S +0x0
{
    SECURE_RO_S_GFH +0x0 
    {
         *                             (SECURE_RO_S_GFH, +First)
         *                             (SECURE_RO_S_GFH_EXT)
    }
    SECURE_RO_S +0x0
    {
         *.obj (SECURE_RO_S)
    }
    SECURE_RO_S_SIGNATURE_SECTION +0x0
    {
         *                             (SECURE_RO_S_SIGNATURE_SECTION)
    }    
}
__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  NFB ARM11 BL Layout <Class>
# return:      the body strings
#****************************************************************************
sub layout10
{
    my ($bb) = @_;

    # --- --- --- 
    # Alignment configuration
    my $alignment_config;
    my $dsp_solution = &$feature_query_function_ptr('dsp_solution');
    if (defined $dsp_solution and $dsp_solution eq 'DUALMACDSP')
    {
        $alignment_config .= <<"__TEMPLATE";
#define ALIGNMENT_1MB 0x100000
#define ALIGNMENT_256KB 0x40000
#define SetAddress(address, alignment) ((address+(alignment-1)) AND ~(alignment-1))
__TEMPLATE
    }
    chomp $alignment_config;

    # --- --- --- 
    # Configure DSP BL
    my $dsp_bl;
    if (defined $dsp_solution and $dsp_solution eq 'DUALMACDSP' and $bb ne 'MT6256')
    {
        $dsp_bl .= <<"__TEMPLATE";
DSP_BL 0x0
{
}
__TEMPLATE
    }
    chomp $dsp_bl;

    # --- --- ---
    my $layout_default = <<"__LAYOUT";
$alignment_config

BOOTLOADER 0x0
{
}

EXT_BOOTLOADER 0x0
{
}

$dsp_bl

__LAYOUT

    return $layout_default;
}

#****************************************************************************
# subroutine:  NOR Smart Phone Modem Layout <Class>
# return:      the body strings
#****************************************************************************
sub layout9
{
    my ($bb, $nPhysical_rs) = @_;
    my $mode = &$feature_query_function_ptr('MODE');
    my $umts_mode_support = &$feature_query_function_ptr('umts_mode_support');
    # --- --- --- 
    # address setting
    my ($fbase, $flength, $rambase, $rs);
    if ($bb eq 'MT6516')
    {
        $fbase                = "0x00000000";
        $flength              = "0x280000";
        $rambase              = $flength; 
        $rs                   = "0x400000";
    }
    elsif (($bb eq 'MT6573') or ($bb eq 'MT6575'))
    {
        if ($mode eq 'GPRS')
        {
            $fbase                = "0x00000000";
            $flength              = "0x400000";
            $rs                   = "0x300000";  # 0x700000-0x400000
        }
        else
        {
            $fbase                = "0x00000000";
            $flength              = "0x600000";
            $rs                   = "0xD00000";  # 0x1300000-0x600000
            if($bb eq 'MT6573' and (defined $umts_mode_support and $umts_mode_support eq 'UMTS_TDD128_MODE_SUPPORT'))
            {
            	$rs = "0x900000";
            }
        }
        $rambase              = $flength;
    }
    elsif ($bb eq 'TK6280')
    {   # 128MB SRAM = 0x8000000
        $fbase                = "0x00000000";
        $flength              = "0x4000000";
        $rs                   = "0x4000000";
        $rambase              = $flength;
    }
    elsif ($bb eq 'MT6280')
    {
        $fbase                = "0x00000000";
        $flength              = &CommonUtil::Dec2Hex($nPhysical_rs);
        $rambase              = "+0x0 ALIGN 0x100000";
        $rs                   = &CommonUtil::Dec2Hex($nPhysical_rs);
    }

    # --- --- ---
    my $secure_ro;
    my $nflash_secure_ro_addr = 0;
    my $secure_ro_support = &$feature_query_function_ptr('secure_ro_enable');
    if(defined $secure_ro_support and $secure_ro_support eq 'TRUE')
    {
        my $nSECURE_RO_SIZE = 32*1024;
        #load region base = execution region base
        $nflash_secure_ro_addr = hex($fbase) + hex($flength) - $nSECURE_RO_SIZE;
        my $flash_secure_ro_addr = &CommonUtil::Dec2Hex($nflash_secure_ro_addr);
        my $ev_hidden_secure_ro  = &layout3_secure_ro_ev($flash_secure_ro_addr);
        $secure_ro = <<"__TEMPLATE";
;=========================================================================
; The following secure related load regions must be the end of all the load regions
;=========================================================================
; 1. Only address is configurable.
; 2. Region address must be fixed address.
; 3. Using flash-sector-aligned address in region address for higher security.
; 4. DO NOT modify load region order, load region naming and pragma naming!
;=========================================================================
__HIDDEN_SECURE_RO $flash_secure_ro_addr
{
$ev_hidden_secure_ro
}
__TEMPLATE
    }
    # --- --- ---
    my $BOOT_CERT_LV;
    my $boot_cert = &$feature_query_function_ptr('boot_cert_support');
    if($boot_cert ne "FALSE" and  $boot_cert ne "NONE")
    {
        my $nRamEnd = ($nflash_secure_ro_addr ==0) ? (hex($fbase) + hex($flength)) : $nflash_secure_ro_addr;
        my ($nDummyEnd_Base, $nOffset, $temp_ref) = &GetDummyEnd($bb, $nRamEnd);
        $BOOT_CERT_LV = &layout14($bb, &CommonUtil::Dec2Hex($nDummyEnd_Base), &CommonUtil::Dec2Hex(4*1024), "");
    }
    # --- --- --- 
    # Alignment configuration and DSP_ROM for Fcore
    my ($alignment_config, $dsp_rom);
    my $dsp_solution = &$feature_query_function_ptr('dsp_solution');
    my $dsp_rom_base_str;
    if (defined $dsp_solution and $dsp_solution eq 'DUALMACDSP')
    {
        if ($mode ne 'GPRS')
        {
            ### Set alignment config template
            $alignment_config .= <<"__TEMPLATE";
#define ALIGNMENT_1MB 0x100000
#define SetAddress(address, alignment) ((address+(alignment-1)) AND ~(alignment-1))
__TEMPLATE
        }

        ### Set DSP_ROM template
        if (($bb eq 'MT6573') or ($bb eq 'MT6575'))
        {
            if ($mode eq 'GPRS')
            {
                $dsp_rom_base_str = sprintf("0x%08x", hex($flength)+hex($rs));
                my $ram_end_str = sprintf("0x%08x", hex($flength)+hex($rs));
            }
            else
            {
                $dsp_rom_base_str = sprintf("0x%08x", hex($flength)+hex($rs));
                my $ram_end_str = sprintf("0x%08x", hex($flength)+hex($rs));
                #$dsp_rom .= "; 1MB margin from $ram_end_str to $dsp_rom_base_str\n";
            }
        }
        else
        {
            $dsp_rom_base_str = $rs;
        }
        $dsp_rom .= <<"__TEMPLATE";
DSP_ROM $dsp_rom_base_str
{
    DSP_ROM $dsp_rom_base_str
    {
        *.obj (DSP_DATA)
    }
}
__TEMPLATE
    }
    chomp $alignment_config;
    chomp $dsp_rom;

    # --- --- --- 
    # execution view reterieving
    my $ev_rom_default        = &layout0_rom_ev($bb, $fbase, hex($rs), $rambase, "0x0");
    chomp $ev_rom_default;
    
    # --- --- --- 
    my $layout_default = <<"__LAYOUT";
$alignment_config
ROM $fbase $flength
{
$ev_rom_default
}
$secure_ro
$BOOT_CERT_LV
$dsp_rom
__LAYOUT

    return $layout_default;
}

#****************************************************************************
# subroutine:  NFB + FOTA Layout <Class>
# return:      the body strings
#****************************************************************************
sub layout8
{
    my ($bb, $security) = @_;
    
    if ($security eq 'TRUE')
    {
          return;
    }
    
    # --- --- --- 
    my $layout_default = <<"__LAYOUT";
__HIDDEN_SECURE_MAC +0x0
{
    __HIDDEN_SECURE_MAC_CONTENT +0x0
    {
         *.obj (SECURE_MAC_CONTENT)
    }
    __HIDDEN_SECURE_MAC +0x0
    {
         *.obj (SECURE_MAC_SIZE)
    }
}

__LAYOUT
    return $layout_default;
}

#****************************************************************************
# subroutine:  FOTA Layout <Class>
# return:      the body strings
#****************************************************************************
sub layout7
{
    my ($bb, $fs, $rs, $boot_cert, $fast_boot, $nFactoryBinSize) = @_;
    # --- --- --- 
    # address setting
    # --- --- ---
    my $lv_strFactoryCombine;
    my $nFOTASize = hex($fota_cfg_href->{'FOTA_UE_RESIDENT_FLASH_SPACE_SIZE'})+hex($fota_cfg_href->{'FOTA_UE_BACKUP_FLASH_SPACE_SIZE'});
    &config_reset_rom_offset(hex($fota_cfg_href->{'FOTA_UE_FLASH_BASE_ADDRESS'}));
    &config_add_rom_offset($nFOTASize);
	
    if(defined $fast_boot and $fast_boot eq 'FACTORY_COMBINE')
    {
        $lv_strFactoryCombine = &layout16($bb, 'NONE', &lv_rom_fbase(), $nFactoryBinSize, $rs);
        &WarnMinus(($fs - (&config_query_rom_offset() + hex($fota_cfg_href->{'MAX_LENGTH_ROM'}))), __FILE__, __LINE__, "FlashSize isn't big enough to put in FactoryBin");
    }
    # --- --- ---
    my $fbase = &CommonUtil::Dec2Hex(&lv_rom_fbase());
    my $flength = $fota_cfg_href->{'MAX_LENGTH_ROM'};
      
    # --- --- --- 
    my $secure = &$feature_query_function_ptr('secure_support');
    my $mba = &$feature_query_function_ptr('multiple_binary_files');
    
    # --- --- ---
    my $fota_ue_flash_base_address = sprintf("0x%08x", hex($fota_cfg_href->{'FOTA_UE_FLASH_BASE_ADDRESS'}) + &config_query_flash_base_address($bb));
    my $fota_ue_flash_space_size = $fota_cfg_href->{'CONFIG_FOTA_UE_FLASH_SPACE'};

    # --- --- ---
    # FOTA update package validity check
    my $fota_package_storage_base;
    if (&$feature_query_function_ptr('system_drive_on_nand') eq 'TRUE' or &$feature_query_function_ptr('fota_update_package_on_nand') eq 'TRUE')
    {
          $fota_package_storage_base = hex($fota_cfg_href->{'FOTA_PACKAGE_STORAGE_BASE'});
    }
    else
    {
          $fota_package_storage_base = hex($fota_cfg_href->{'FOTA_PACKAGE_STORAGE_BASE'}) - &config_query_flash_base_address($bb);
    }
    my $fota_package_storage_size = hex($fota_cfg_href->{'FOTA_PACKAGE_STORAGE_SIZE'});
    my $block_sz_update_package = &config_query_flash_block_size($fota_package_storage_base);
    my $tmp_addr = $fota_package_storage_base;
    my $tmp_block_sz = $block_sz_update_package;
    while ($tmp_addr < ($fota_package_storage_base + $fota_package_storage_size))
    {
          $tmp_block_sz = &config_query_flash_block_size($tmp_addr);
          &sysUtil::sysgen_die("$bb_folder/custom_img_config.h: All blocks in FOTA update package should have the same size! Please check FOTA_PACKAGE_STORAGE_BASE and FOTA_PACKAGE_STORAGE_SIZE settings in custom_img_config.h!", __FILE__, __LINE__) if ($tmp_block_sz != $block_sz_update_package);
          $tmp_addr += $tmp_block_sz;
    }

    my $available_rom = $fs;
    my $bottom_region_size = 0;
    my $lv_bottom;
    my $useless;
    if((defined $secure and $secure eq 'TRUE') || ($boot_cert ne 'FALSE' and $boot_cert ne 'NONE') || (defined $mba and $mba eq 'TRUE'))
    {
        my $fast_boot = &$feature_query_function_ptr('split_binary_support');
        my $SECURE_MAC_BLOCKSIZE = (defined $fast_boot and $fast_boot ne 'NONE') ? 2 : 1;
        my %RegionSetting = ('LANG_PACK_ROM' => [ BLOCK_ALIGNED, 8, undef ],
                             'CUSTPACK_ROM'  => [ BLOCK_ALIGNED, 2, undef ],
                             'JUMP_TABLE'    => [ BLOCK_ALIGNED, 1, undef ],
                             'BOOT_CERT'     => [ BLOCK_ALIGNED, 1, undef ],
                             'SECURE_MAC'    => [ BLOCK_ALIGNED, $SECURE_MAC_BLOCKSIZE, undef ],
                             'SECURE_RO'     => [ BLOCK_ALIGNED, 1, undef ],
                             'FLASHTOOL_CFG' => [ BLOCK_ALIGNED, 1, undef ],
                             'CUST_PARA'     => [ BLOCK_ALIGNED, 1, undef ]);
                             
        ($bottom_region_size, $lv_bottom, $useless) = &BOTTOM_NOR_LV_Layout($bb, $fs, undef, 0, \%RegionSetting); #not OVERLAY
        $available_rom -= $bottom_region_size;
    }
    
    &WarnMinus(($available_rom - (&config_query_rom_offset() + hex($fota_cfg_href->{'MAX_LENGTH_ROM'}))), __FILE__, __LINE__, "FlashSize isn't big enough to put in SecureRegion or BOOT_CERT");
    # --- --- ---
    my $ev_rom_default       = &layout0_rom_ev($bb, $fbase, $rs, $flength, "0x0");
    my $ev_rom_secure        = &layout3_secusb_rom_ev($bb, hex($fbase), $rs, "0x0");
    chomp $ev_rom_default;
    chomp $ev_rom_secure;
    my $ev_rom = (defined $secure and $secure eq 'TRUE')? $ev_rom_secure : $ev_rom_default;
    
    # --- --- --- 
    my $layout_fota = <<"__LAYOUT";
FOTA $fota_ue_flash_base_address $fota_ue_flash_space_size
{
}
$lv_strFactoryCombine
; ROM Load region is block-aligned
ROM $fbase $flength
{
$ev_rom
}
$lv_bottom

__LAYOUT
    # --- --- --- 


    if(&sysUtil::is_XIP_Shadowing($bb))
    {
        return $FOTA_LV."\n".$lv_strFactoryCombine."\n".&layout9($bb, $rs);
    }
    else
    {
            return $layout_fota;
    }
}

#****************************************************************************
# subroutine:  NFB + FOTA Layout <Class>
# return:      the body strings
#****************************************************************************
sub layout6
{
    my ($bb) = @_;

    # --- --- --- 
    my $layout_default = <<"__LAYOUT";
FOTA 0x00
{
}

__LAYOUT
    return $layout_default;
}

#****************************************************************************
# subroutine:  SECURE MBA Layout <Class>
# return:      the body strings
#****************************************************************************
sub layout5
{
    my ($bb, $fs, $rs, $boot_cert) = @_;
    # address setting
    my $fbase    = sprintf("0x%08x", &lv_rom_fbase($bb));
    my $available_rom = $fs;
    
    # --- --- --- 
    # viva
    my $viva_header_size = &sysUtil::query_viva_size($bb);    
    # dcmp
    my $dcm_compression_support = &$feature_query_function_ptr('dcm_compression_support');
    my $is_DCMP = (defined $dcm_compression_support and $dcm_compression_support eq 'TRUE');    
    my $nDCMCompressedSize = 0;
    my $nDCMP_evTotalSize = 0;
    if($is_DCMP)
    {
        # DCM Compressed Size Calculation - Influence avaiable flash size.
        # DCM Compressed Size Calculation - Influence avaiable flash size.
        &sysUtil::sysgen_die("$bb_folder/custom_FeatureConfig.h: CONFIG_DCMP_MAX_COMPRESSED_SIZE need to be defined when DCM_COMPRESION_SUPPORT is turned on!", __FILE__, __LINE__)
           if (!defined($feature_config_href->{'CONFIG_DCMP_MAX_COMPRESSED_SIZE'}));
        $nDCMCompressedSize = hex($feature_config_href->{'CONFIG_DCMP_MAX_COMPRESSED_SIZE'});
    }
    # alice 
    my $alice = &$feature_query_function_ptr('alice_support');
    my $comp_alice;
    if(defined $alice and $alice eq 'TRUE')
    {
        &sysUtil::sysgen_die("$bb_folder/custom_FeatureConfig.h: and CONFIG_ALICE_MAX_COMPRESSED_SIZE need to be defined when ALICE_SUPPORT is turned on!", __FILE__, __LINE__)
           if (!defined($feature_config_href->{'CONFIG_ALICE_MAX_COMPRESSED_SIZE'}));
        $comp_alice = hex($feature_config_href->{'CONFIG_ALICE_MAX_COMPRESSED_SIZE'});
    }    
    # --- --- ---
    my $secure = &$feature_query_function_ptr('secure_support');
    my $bottom_region_size = 0;
    my $lv_bottom;
    my $isOVERLAY;
    $isOVERLAY = (($alice eq 'TRUE') or $is_DCMP);    
    if((defined $secure and $secure eq 'TRUE') || ($boot_cert ne 'FALSE' and $boot_cert ne 'NONE') 
    || $is_DCMP || (defined $alice and $alice eq 'TRUE'))
    {
        my $fast_boot = &$feature_query_function_ptr('split_binary_support');
        my $SECURE_MAC_TYPE = (defined $fast_boot and $fast_boot ne 'NONE') ? BLOCK_ALIGNED :OCCUPIED_SIZE;
        my $SECURE_MAC_SIZE = (defined $fast_boot and $fast_boot ne 'NONE') ? 2 : 0x1000;
        my %RegionSetting = ('BOOT_CERT'          => [ OCCUPIED_SIZE, 4 * 1024, undef ],
                             'SECURE_MAC'         => [ $SECURE_MAC_TYPE, $SECURE_MAC_SIZE,  undef ],
                             'SECURE_RO'          => [ BLOCK_ALIGNED, 1, undef ],
                             'FLASHTOOL_CFG'      => [ BLOCK_ALIGNED, 1, undef ],
                             'CUST_PARA'          => [ BLOCK_ALIGNED, 1, undef ],
                             'VIVA'               => [ OCCUPIED_SIZE, $viva_header_size, undef ],
                             'ALICE'              => [ OCCUPIED_SIZE, $comp_alice, undef ],                             
                             'DYNAMIC_COMP_CODE'  => [ OCCUPIED_SIZE, $nDCMCompressedSize, undef ]);                             
        ($bottom_region_size, $lv_bottom, $nDCMP_evTotalSize) = &BOTTOM_NOR_LV_Layout($bb, $available_rom, $rs, $isOVERLAY, \%RegionSetting); #OVERLAY if dcm_compression_support or ALICE support
        &WarnMinus(($available_rom - $bottom_region_size), __FILE__, __LINE__, "FlashSize: ".&CommonUtil::Dec2Hex($fs).") isn't big enough to put in BOTTOM regions(".&CommonUtil::Dec2Hex($bottom_region_size).")");
        $available_rom -= $bottom_region_size;
    }

    # --- --- --- 
    # Jump Table  address setup
    my $jump_table_size = 0x200;
    my $jbase   = sprintf("0x%08x", &config_query_flash_base_address($bb) + $available_rom- $jump_table_size);

    # --- --- --- 
    # Lang Pack   address setup
    my $flash_lang_pack_addr = sprintf("+0x%x", &config_query_max_flash_block_sz($fs));

    &WarnMinus( $available_rom - &config_query_rom_offset(), __FILE__, __LINE__, "Layout5(NOR::MBA+Secure)-ROM MaxSize is not correct");
    my $flength  = sprintf("0x%08x", $available_rom - &config_query_rom_offset());

    my $usbdl  = &$feature_query_function_ptr('usb_download_in_bl');
    # --- --- --- 
    # execution view reterieving
    my $ev_rom_secure;
    if ($usbdl eq 'SECURE' && $nor_device_exist eq 'TRUE')
    {
        $ev_rom_secure       = &layout3_secusb_rom_ev($bb, &lv_rom_fbase($bb), $rs, &CommonUtil::Dec2Hex($nDCMP_evTotalSize));
    }
    else
    {
        $ev_rom_secure       = &layout3_rom_ev($bb, &lv_rom_fbase($bb), $rs, &CommonUtil::Dec2Hex($nDCMP_evTotalSize));
    }
    my $ev_lang_pack         = &layout2_lang_ev("+0x00", $bb);
    my $ev_custpack_rom      = &layout2_cust_ev($bb);
    my $ev_jump_table        = &layout2_jump_ev($bb);        # ev start address remains +0x0, which means to start from lv start address
    # --- --- --- 
    chomp $ev_rom_secure;
    chomp $ev_lang_pack;
    chomp $ev_custpack_rom;
    chomp $ev_jump_table;
    # --- --- --- 
    # mba default binary
        my $mba_bin = &$feature_query_function_ptr('MBA_DEFAULT_BINARY');
    my $lv_lang_pack;
    my $lv_cust_pack;
    my $lv_mba;
    
    $lv_lang_pack = <<"__LANGPACK";
LANG_PACK_ROM +0x00
{
$ev_lang_pack
}

__LANGPACK

     $lv_cust_pack = <<"__CUSTPACK";
CUSTPACK_ROM +0x00
{
$ev_custpack_rom
}
    	
__CUSTPACK

    if(!defined $mba_bin or (defined $mba_bin and $mba_bin eq 'CUST_AND_LANG'))
    {
        $lv_mba = $lv_lang_pack.$lv_cust_pack;
    }    
    elsif(defined $mba_bin and $mba_bin eq 'LANG_ONLY')
    {
        $lv_mba = $lv_lang_pack;	
    }        
    elsif(defined $mba_bin and $mba_bin eq 'CUST_ONLY')
    {
    	  $lv_mba = $lv_cust_pack;
    }
    
    my $layout_mbin = <<"__LAYOUT";
; ROM Load region is block-aligned
ROM $fbase $flength
{
$ev_rom_secure
}

$lv_mba

JUMP_TABLE $jbase 0x200
{
$ev_jump_table
}
$lv_bottom

__LAYOUT

    return $layout_mbin;
}

#****************************************************************************
# subroutine:  BOOTLOADER Layout <Class>
# return:      the body strings
#****************************************************************************
sub layout4
{
    my ($bb) = @_;

    # --- --- --- 
    my $ext_bl_update_support = &$feature_query_function_ptr('ext_bl_update_support');
    my $card_dl = &$feature_query_function_ptr('card_download');
    my ($BL_MIN_SIZE, $EXT_BL_MIN_SIZE, $EXT_BL_BAK_MIN_SIZE);
    if ((!defined $ext_bl_update_support) or (defined $ext_bl_update_support and $ext_bl_update_support eq 'FALSE'))
    {
    	$BL_MIN_SIZE = 32 * 1024;
    	if (defined $card_dl and $card_dl ne 'NONE')
    	{
            $EXT_BL_MIN_SIZE = 224 * 1024;
    	}
    	else
    	{
            $EXT_BL_MIN_SIZE = 96 * 1024;
    	}
    	$EXT_BL_BAK_MIN_SIZE = 0;
    }
    else
    {
    	$BL_MIN_SIZE = 32 * 1024;
    	$EXT_BL_MIN_SIZE = hex($fota_cfg_href->{'BL_IMG_MAX_SIZE'});
    	$EXT_BL_BAK_MIN_SIZE = hex($fota_cfg_href->{'BL_IMG_MAX_SIZE'});
    }
    
    $BL_MIN_SIZE = (exists $feature_config_href->{MAX_BL_SIZE}) ? 
                             hex($feature_config_href->{MAX_BL_SIZE}) : $BL_MIN_SIZE;
    $EXT_BL_MIN_SIZE = (exists $feature_config_href->{MAX_EXT_BL_SIZE}) ? 
                             hex($feature_config_href->{MAX_EXT_BL_SIZE}) : $EXT_BL_MIN_SIZE;
    $EXT_BL_BAK_MIN_SIZE = (exists $feature_config_href->{MAX_EXT_BL_SIZE}) ? 
                             hex($feature_config_href->{MAX_EXT_BL_SIZE}) : $EXT_BL_BAK_MIN_SIZE;
    ### BL starts at 0
    my $bl_base = 0;  # BL base without remap
    my $bl_base_str = sprintf("0x%08x", $bl_base + &config_query_flash_base_address($bb));
    my $bl_size = $BL_MIN_SIZE;
    my $bl_size_str = sprintf("0x%08x", $bl_size);
    
    ### EXT_BOOTLOADER is behind BL and should be block-aligned if EXT_BL_UPDATE_SUPPORT is turned on
    my $ext_bl_base = (defined $ext_bl_update_support and $ext_bl_update_support eq 'TRUE') ? (&config_query_next_block_aligned_addr($bl_base, $bl_size)) : ($bl_base + $bl_size);  # EXT_BL base without remap
    my $ext_bl_base_str = sprintf("0x%08x", $ext_bl_base + &config_query_flash_base_address($bb));
    my $ext_bl_size = (defined $ext_bl_update_support and $ext_bl_update_support eq 'TRUE') ? (&config_query_next_block_aligned_addr($ext_bl_base, $EXT_BL_MIN_SIZE) - $ext_bl_base) : ($EXT_BL_MIN_SIZE);
    my $ext_bl_size_str = sprintf("0x%08x", $ext_bl_size);

    ### EXT_BOOTLOADER_BAK is behind EXT_BOOTLOADER and should be block-aligned
    my ($ext_bl_bak_base, $ext_bl_bak_size) = (($ext_bl_base + $ext_bl_size), 0); 
    if(&FileInfo::is("ext_bl_update_support", "TRUE"))
    {
        $ext_bl_bak_base = (&config_query_next_block_aligned_addr($ext_bl_base, $ext_bl_size));  # EXT_BL base without remap
        $ext_bl_bak_size = &config_query_next_block_aligned_addr($ext_bl_bak_base, $EXT_BL_BAK_MIN_SIZE) - $ext_bl_bak_base;
    }
    my $ext_bl_bak_base_str = sprintf("0x%08x", $ext_bl_bak_base + &config_query_flash_base_address($bb)); 
    my $ext_bl_bak_size_str = sprintf("0x%08x", $ext_bl_bak_size);

	### Set MAUI ROM start offset
    &config_add_rom_offset($ext_bl_bak_base+$ext_bl_bak_size);

    ### EXT_BOOTLOADER_BAK only exists when EXT_BL_UPDATE_SUPPORT is turned on
    my $ext_bootloader_bak_lv;
    if (defined $ext_bl_update_support and $ext_bl_update_support eq 'TRUE')
    {
    	$ext_bootloader_bak_lv = <<"__TEMPLATE";
EXT_BOOTLOADER_BAK $ext_bl_bak_base_str $ext_bl_bak_size_str
{
}
__TEMPLATE
    }
    chomp $ext_bootloader_bak_lv;

    # --- --- --- 
    my $layout_default = <<"__LAYOUT";
BOOTLOADER $bl_base_str $bl_size_str
{
}

EXT_BOOTLOADER $ext_bl_base_str $ext_bl_size_str
{
}

$ext_bootloader_bak_lv

__LAYOUT
    return $layout_default;
}

#****************************************************************************
# subroutine:  SECURE Layout <Class>
# return:      the body strings
#****************************************************************************
sub layout3
{
    my ($bb, $fs, $rs, $boot_cert) = @_;
    # --- --- --- 
    # address setting
    my $fbase    = sprintf("0x%08x", &lv_rom_fbase($bb));

    my $query_address        ;
    my $last_block_size      ;
    # --- --- --- 
    # custom parameter address setup
    $query_address           = $fs - 1;
    $last_block_size         = &config_query_flash_block_sz($query_address);
    $query_address           = $fs - $last_block_size;
    my $flash_custpara_addr  = sprintf("0x%08x", &config_query_flash_base_address($bb) + $query_address);

    # --- --- --- 
    # tool config address setup
    $query_address           --;
    $last_block_size         = &config_query_flash_block_sz($query_address);
    $query_address           = $query_address - $last_block_size + 1;
    my $flash_toolcfg_addr   = sprintf("0x%08x", &config_query_flash_base_address($bb) + $query_address);

    # --- --- --- 
    # Secure RO   address setup
    $query_address           --;
    $last_block_size         = &config_query_flash_block_sz($query_address);
    $query_address           = $query_address - $last_block_size + 1;
    my $flash_secure_ro_addr = sprintf("0x%08x", &config_query_flash_base_address($bb) + $query_address);

    # --- --- ---
    # Boot Cert region
    my $flash_boot_cert_size = 4 * 1024;
    my $flash_boot_cert_size_str = sprintf("0x%08x", $flash_boot_cert_size);
    my $flash_boot_cert_base_str;
    my $boot_cert_rom;
    if ($boot_cert ne 'FALSE' and $boot_cert ne 'NONE')
    {
        $query_address -= $flash_boot_cert_size;
        $flash_boot_cert_base_str = sprintf("0x%08x", &config_query_flash_base_address($bb) + $query_address);
        $boot_cert_rom = &layout14($bb, $flash_boot_cert_base_str, $flash_boot_cert_size_str, "");
    }
    chomp $boot_cert_rom;
    # --- --- ---
    # Secure MAC  address setup
    my $fast_boot = &$feature_query_function_ptr('split_binary_support');
    my $flash_secure_mac_addr = '+0x0';
    if(defined $fast_boot and $fast_boot ne 'NONE')
    {
        # SECURE_MAC should be 2 blocks aligned if any factory support turns on(even maui)
        $query_address           --;
        $last_block_size         = &config_query_flash_block_sz($query_address);
        $query_address           = $query_address - $last_block_size;
        $last_block_size         = &config_query_flash_block_sz($query_address);
        $query_address           = $query_address - $last_block_size + 1;
        $flash_secure_mac_addr = sprintf("0x%08x", &config_query_flash_base_address($bb) + $query_address);
    }
    # --- --- ---
    &WarnMinus( $query_address - &config_query_rom_offset(), __FILE__, __LINE__, "Layout3(NOR::Secure)-ROM MaxSize is not correct");
    my $flength  = sprintf("0x%08x", $query_address - &config_query_rom_offset());

    my $usbdl  = &$feature_query_function_ptr('usb_download_in_bl');
    # --- --- --- 
    # execution view reterieving
    my $ev_rom_secure;
    if ($usbdl eq 'SECURE' && $nor_device_exist eq 'TRUE')
    {
        $ev_rom_secure       = &layout3_secusb_rom_ev($bb, &lv_rom_fbase($bb), $rs, "0x0");
    }
    else
    {
        $ev_rom_secure       = &layout3_rom_ev($bb, &lv_rom_fbase($bb), $rs, "0x0");
    }
    my $ev_hidden_secure_mac = &layout3_secure_mac_ev();
    my $ev_hidden_secure_ro  = &layout3_secure_ro_ev($flash_secure_ro_addr);
    my $ev_hidden_toolcfg    = &layout3_toolcfg_ev($flash_toolcfg_addr);
    my $ev_hidden_custpara   = &layout3_custpara_ev($flash_custpara_addr);
    chomp $ev_rom_secure;
    chomp $ev_hidden_secure_mac;
    chomp $ev_hidden_secure_ro;
    chomp $ev_hidden_toolcfg;
    chomp $ev_hidden_custpara;
    
    # --- --- --- 
    my $layout_secure = <<"__LAYOUT";
; ROM Load region is block-aligned
ROM $fbase $flength
{
$ev_rom_secure
}

;=========================================================================
; This load region must be behind all the protected load region
;=========================================================================
; 1. DO NOT modify load region naming and pragma naming!
;=========================================================================

__HIDDEN_SECURE_MAC $flash_secure_mac_addr
{
$ev_hidden_secure_mac
}

$boot_cert_rom

;=========================================================================
; The following load regions must be the end of all the load regions
;=========================================================================
; 1. Only address is configurable.
; 2. Region address must be fixed address.
; 3. Using flash-sector-aligned address in region address for higher security.
; 4. DO NOT modify load region order, load region naming and pragma naming!
;=========================================================================

__HIDDEN_SECURE_RO $flash_secure_ro_addr
{
$ev_hidden_secure_ro
}

__HIDDEN_FLASHTOOL_CFG $flash_toolcfg_addr
{
$ev_hidden_toolcfg
}

__HIDDEN_CUST_PARA $flash_custpara_addr
{
$ev_hidden_custpara
}

__LAYOUT

    return $layout_secure;
}

#****************************************************************************
# subroutine:  MULTIBIN Layout <Class>
# return:      the body strings
#****************************************************************************
sub layout2
{
    my ($bb, $fs, $rs, $boot_cert) = @_;
    # --- --- --- 
    # alice
    my $viva_header_size = &sysUtil::query_viva_size($bb);    
    my $alice = &$feature_query_function_ptr('alice_support'); 
    my $comp_alice;
    if(defined $alice and $alice eq 'TRUE')
    {
        &sysUtil::sysgen_die("$bb_folder/custom_FeatureConfig.h: and CONFIG_ALICE_MAX_COMPRESSED_SIZE need to be defined when ALICE_SUPPORT is turned on!", __FILE__, __LINE__)
           if (!defined($feature_config_href->{'CONFIG_ALICE_MAX_COMPRESSED_SIZE'}));
        $comp_alice = $feature_config_href->{'CONFIG_ALICE_MAX_COMPRESSED_SIZE'};
    }


    # --- --- --- 
    # address setting    
    my $fbase   = sprintf("0x%08x", &lv_rom_fbase($bb));
    # --- --- ---
    

    my $available_rom = $fs;
    my $dcm_compression_support = &$feature_query_function_ptr('dcm_compression_support');
    my $is_DCMP = (defined $dcm_compression_support and $dcm_compression_support eq 'TRUE');    

    # --- --- --- 
    # dcmp
    my $nDCMCompressedSize = 0;
    my $nDCMP_evTotalSize = 0;
    if($is_DCMP)
    {
        # DCM Compressed Size Calculation - Influence avaiable flash size.
        &sysUtil::sysgen_die("$bb_folder/custom_FeatureConfig.h: CONFIG_DCMP_MAX_COMPRESSED_SIZE need to be defined when DCM_COMPRESION_SUPPORT is turned on!", __FILE__, __LINE__)
           if (!defined($feature_config_href->{'CONFIG_DCMP_MAX_COMPRESSED_SIZE'}));    
        $nDCMCompressedSize = hex($feature_config_href->{'CONFIG_DCMP_MAX_COMPRESSED_SIZE'});
        
    }    
    
    # --- --- --- 
    my $secure = &$feature_query_function_ptr('secure_support');
    my $bottom_region_size = 0;
    my $lv_bottom;
    my $isOVERLAY;
    $isOVERLAY = (($alice eq 'TRUE') or $is_DCMP);
    if(($boot_cert ne 'FALSE' and $boot_cert ne 'NONE') || $is_DCMP || (defined $alice and $alice eq 'TRUE'))
    {
        my %RegionSetting = ('BOOT_CERT'          => [ OCCUPIED_SIZE, 4 * 1024, undef ],                                                                                                                   
                             'VIVA'               => [ OCCUPIED_SIZE, $viva_header_size, undef ],
                             'ALICE'              => [ OCCUPIED_SIZE, hex($comp_alice), undef ],                             
                             'DYNAMIC_COMP_CODE'  => [ OCCUPIED_SIZE, $nDCMCompressedSize, undef ]);
        ($bottom_region_size, $lv_bottom, $nDCMP_evTotalSize) = &BOTTOM_NOR_LV_Layout($bb, $available_rom, $rs, $isOVERLAY, \%RegionSetting); #OVERLAY if dcm_compression_support or ALICE support
        &WarnMinus(($available_rom - $bottom_region_size), __FILE__, __LINE__, "FlashSize: ".&CommonUtil::Dec2Hex($fs).") isn't big enough to put in BOTTOM regions(".&CommonUtil::Dec2Hex($bottom_region_size).")");
        $available_rom -= $bottom_region_size;
    }
    # --- --- ---

    #&WarnMinus( $fs - &config_query_rom_offset(), __FILE__, __LINE__, "Layout2(NOR::MBA)-ROM MaxSize is not correct");
    my $jump_table_size = &sysUtil::is_sv5($bb) ? 0x280 : 0x200;
    my $jsize   = &CommonUtil::Dec2Hex($jump_table_size);
    my $jbase   = sprintf("0x%08x", &config_query_flash_base_address($bb) + $available_rom- $jump_table_size);
    my $flength = sprintf("0x%08x", $available_rom - &config_query_rom_offset() );
    
    my $ev_rom_default  = &layout0_rom_ev($bb, $fbase, $rs, $flength, &CommonUtil::Dec2Hex($nDCMP_evTotalSize));
    my $ev_lang_pack    = &layout2_lang_ev("+0x00", $bb);
    my $ev_custpack_rom = &layout2_cust_ev($bb);
    my $ev_jump_table   = &layout2_jump_ev($bb);
    # --- --- --- 
    chomp $ev_rom_default;
    chomp $ev_lang_pack;
    chomp $ev_custpack_rom;
    chomp $ev_jump_table;
    # --- --- --- 
    # mba default binary
    my $mba_bin = &$feature_query_function_ptr('MBA_DEFAULT_BINARY');
    my $lv_lang_pack;
    my $lv_cust_pack;
    my $lv_mba;
    
    
    $lv_lang_pack = <<"__LANGPACK";
LANG_PACK_ROM +0x00
{
$ev_lang_pack
}

__LANGPACK

     $lv_cust_pack = <<"__CUSTPACK";
CUSTPACK_ROM +0x00
{
$ev_custpack_rom
}
    	
__CUSTPACK

    if(!defined $mba_bin or (defined $mba_bin and $mba_bin eq 'CUST_AND_LANG'))
    {
        $lv_mba = $lv_lang_pack.$lv_cust_pack;
    }    
    elsif(defined $mba_bin and $mba_bin eq 'LANG_ONLY')
    {
        $lv_mba = $lv_lang_pack;	
    }        
    elsif(defined $mba_bin and $mba_bin eq 'CUST_ONLY')
    {
    	  $lv_mba = $lv_cust_pack;
    }
    
    my $layout_mbin = <<"__LAYOUT";
; ROM Load region is block-aligned
ROM $fbase $flength
{
$ev_rom_default
}

$lv_mba

JUMP_TABLE $jbase $jsize
{
$ev_jump_table
}
$lv_bottom

__LAYOUT

    return $layout_mbin;
}

#****************************************************************************
# subroutine:  NFB Layout <Class>
# return:      the body strings
#****************************************************************************
sub layout1
{
    my ($bb, $fs, $rs, $multibin, $security, $fota, $boot_cert, $fast_boot) = @_;
    
    # --- --- --- 
    my %BBtbl_EXTSRAM_Shrinking_By_DP =
       (        
                'MT6236'  => 1,
                'MT6236B' => 1,
                'MT6276'  => 1,
                'MT6256'  => 1,
                'MT6921'  => 1,
                'MT6255'  => 1,
                'MT6922'  => 1,
       );

    # --- --- --- 
    my $nfb_mbin_size_limit = 0x4C0000;
    #--- Note XXX ---------------------
    # NFB MBA 
	# Reserve 0x260000 for CUST_PACK and LANG_PACK on NAND Flash Layout
	# Reserve total 0x4C0000 for (CSUT_PACK+LANG_PACK) on RAM Layout
    #----------------------------------
    
    # --- --- --- 
    if ((&sysUtil::is_arm9($bb) != 1) and (&sysUtil::is_arm11($bb) != 1))
    {
        &sysUtil::sysgen_die("$bb_folder/custom_MemoryDevice.h: NFB RAM size $rs cannot < 32MB on ARM7 platforms!", __FILE__, __LINE__)
            if $rs < (32 * 1024 * 1024);
    }

    # --- --- --- 
    my $seperate_primary_and_secondary;
    my $seperate_secondary_rom_and_ram;
    if ($rs == 32 * 1024 * 1024 )
    {
        $seperate_primary_and_secondary = 0x0800000;
        $seperate_secondary_rom_and_ram = 0x1800000;
    }
    elsif ($rs >= 64 * 1024 * 1024 )
    {
        #--- Note XXX ---------------------
        # MT621X , MT622X LCD DMA cannot access memory cross 32 MB boundary
        #----------------------------------
        $seperate_primary_and_secondary = 0x0C00000;
        $seperate_secondary_rom_and_ram = 0x2000000;
    }

    # --- --- --- 
    my $nfb_or_emb;
    if (defined &$feature_query_function_ptr('nand_flash_booting') and &$feature_query_function_ptr('nand_flash_booting') ne 'NONE')
    {
    	  $nfb_or_emb = &$feature_query_function_ptr('nand_flash_booting');
    }
    elsif (defined &$feature_query_function_ptr('emmc_booting') and &$feature_query_function_ptr('emmc_booting') ne 'NONE')
    {
    	  $nfb_or_emb = &$feature_query_function_ptr('emmc_booting');
    }
    else
    {
    	  $nfb_or_emb = 'NONE';
    }
    # --- --- --- 
    if ((&sysUtil::is_arm9($bb) != 1) and (&sysUtil::is_arm11($bb) != 1))
    {
        &sysUtil::sysgen_die("$bb_folder/custom_MemoryDevice.h: Unsupported RAM density $rs and NFB layout on ARM7 platforms!", __FILE__, __LINE__) unless defined $seperate_secondary_rom_and_ram;
    }

    # --- --- ---
    # Configure Primary ROM and SECONDARY_ROM base address, including DSP_ROM, based on DSP existence
    my ($rom_start_address, $second_rom_start_address) = &config_query_nfb_rom_secrom_base_address($rs);
    # --- --- ---
    # Configure DSP_ROM
    my $dsp_rom;
    my $dsp_solution = &$feature_query_function_ptr('dsp_solution');
    if (defined $dsp_solution and $dsp_solution eq 'DUALMACDSP')
    {
        $dsp_rom = <<"__LAYOUT";
DSP_ROM +0x4000
{
    DSP_ROM +0x0
    {
        *.obj (DSP_DATA)
    }
}

__LAYOUT
    }
    chomp $dsp_rom;

    # --- --- ---
    # set secure load region addresses
    my ($query_address, $nOffset, $temp_ref) = &GetDummyEnd($bb, $rs);
    my ($flash_custpara_addr, $flash_toolcfg_addr, $flash_secure_ro_addr, $flash_secure_mac_addr);
    my ($flash_custpara_size_str, $flash_toolcfg_size_str, $flash_secure_ro_size_str, $flash_secure_mac_size_str);
    if ($security eq 'TRUE')
    {
        $flash_custpara_size_str = &CommonUtil::Dec2Hex( $temp_ref->{"CUST_PARA"}[0]);
        $flash_custpara_addr = &CommonUtil::Dec2Hex( $rs - $temp_ref->{"CUST_PARA"}[1]);
        
        $flash_toolcfg_size_str = &CommonUtil::Dec2Hex( $temp_ref->{"FLASH_TOOLCFG"}[0]);
        $flash_toolcfg_addr = &CommonUtil::Dec2Hex( $rs - $temp_ref->{"FLASH_TOOLCFG"}[1]);
        
        $flash_secure_ro_size_str = &CommonUtil::Dec2Hex( $temp_ref->{"SECURE_RO"}[0]);
        $flash_secure_ro_addr = &CommonUtil::Dec2Hex( $rs - $temp_ref->{"SECURE_RO"}[1]);
        
        $flash_secure_mac_size_str = &CommonUtil::Dec2Hex( $temp_ref->{"SECURE_MAC"}[0]);
        $flash_secure_mac_addr = &CommonUtil::Dec2Hex( $rs - $temp_ref->{"SECURE_MAC"}[1]);
    }
    my ($flash_boot_cert_size_str, $flash_boot_cert_addr);
    if ($boot_cert ne 'FALSE' and $boot_cert ne 'NONE')
    {  # Boot Cert address setup
       $flash_boot_cert_size_str = &CommonUtil::Dec2Hex( $temp_ref->{"BOOT_CERT"}[0]);
       $flash_boot_cert_addr = &CommonUtil::Dec2Hex( $rs - $temp_ref->{"BOOT_CERT"}[1]);
    }
    my $cached_dummy_end_addr = $query_address | 0xF0000000;
    
    # --- --- ---
    my $ev_primary;
    if ($nfb_or_emb eq 'BASIC')
    {
        $ev_primary = &layout1_primaryrom_basic_ev($bb, $seperate_primary_and_secondary, $multibin, $security);
    }
    else
    {
        $ev_primary = &layout1_primaryrom_ev($bb, $seperate_primary_and_secondary, $multibin, $security);
    }
    my $ev_secondary = &layout1_secondaryrom_ev($bb,
                                                $rs,
                                                $seperate_primary_and_secondary,
                                                $seperate_secondary_rom_and_ram,
                                                $cached_dummy_end_addr,
                                                $multibin,
                                                $security,
                                                $nfb_or_emb);
   

    ### Determine Demand Paging pool size
    my $dp_lv_start_string    = sprintf("0x%08x", ($rs|0xf0000000));
    my $dp_lv_size_string = (exists $feature_config_href->{'MAX_DEMAND_PAGING_ROM0_SIZE'}) ? $feature_config_href->{'MAX_DEMAND_PAGING_ROM0_SIZE'} : $fota_cfg_href->{'MAX_LENGTH_DEMAND_PAGING_ROM0'};
    my $ev_demand_paging;
    if ((&sysUtil::is_arm9($bb) == 1) or (&sysUtil::is_arm11($bb) == 1))
    {
        $ev_demand_paging = &layout1_demandpaging_ev($bb, $rs, $BBtbl_EXTSRAM_Shrinking_By_DP{$bb}, $nfb_or_emb, $dp_lv_size_string);
    }

    ### MBA region
    my $lv_mba;
    if(defined $multibin and $multibin eq 'TRUE')
    {
        my $lv_lang_pack;
        my $lv_cust_pack;
        my $mba_bin = &$feature_query_function_ptr('MBA_DEFAULT_BINARY');
        my ($lang_pack_start_string, $lang_pack_size_string, $custpack_start_string, $custpack_size_string);
        ### Determine MBA resource bin size    
        my $lang_pack_rom_bin_size = (exists $feature_config_href->{'MAX_LANG_PACK_ROM_SIZE'}) ? hex($feature_config_href->{'MAX_LANG_PACK_ROM_SIZE'}) : hex($fota_cfg_href->{'MAX_LENGTH_LANG_PACK_ROM'});
        my $custpack_rom_bin_size = (exists $feature_config_href->{'MAX_CUSTPACK_ROM_SIZE'}) ? hex($feature_config_href->{'MAX_CUSTPACK_ROM_SIZE'}) : hex($fota_cfg_href->{'MAX_LENGTH_CUSTPACK_ROM'});
        $lang_pack_start_string = sprintf("0x%08x", hex($dp_lv_start_string)+hex($dp_lv_size_string));
        $lang_pack_size_string = sprintf("0x%08x", $lang_pack_rom_bin_size);
        $custpack_start_string = (defined $mba_bin and $mba_bin eq 'CUST_ONLY')? sprintf("0x%08x", hex($dp_lv_start_string)+hex($dp_lv_size_string)) : sprintf("0x%08x", hex($lang_pack_start_string)+hex($lang_pack_size_string));
        $custpack_size_string = sprintf("0x%08x", $custpack_rom_bin_size);
        my $ev_lang_pack          = &layout2_lang_ev($lang_pack_start_string, $bb);
        my $ev_custpack_rom       = &layout2_cust_ev($bb);
        my $sep_string            = sprintf("0x%08x", $seperate_primary_and_secondary);
        $lv_lang_pack = <<"__LANGPACK";
LANG_PACK_ROM $lang_pack_start_string $lang_pack_size_string 
{
$ev_lang_pack
}

__LANGPACK
    
        $lv_cust_pack = <<"__CUSTPACK";
CUSTPACK_ROM $custpack_start_string $custpack_size_string
{
$ev_custpack_rom
}    

__CUSTPACK

        if(!defined $mba_bin or (defined $mba_bin and $mba_bin eq 'CUST_AND_LANG'))
        {
            $lv_mba = $lv_lang_pack.$lv_cust_pack;
        }
        elsif(defined $mba_bin and $mba_bin eq 'LANG_ONLY')
        {
            $lv_mba = $lv_lang_pack;	
        }
        elsif(defined $mba_bin and $mba_bin eq 'CUST_ONLY')
        {
            $lv_mba = $lv_cust_pack;
        }
    }
    # DP and MBA's region can't exceed 0xffffffff
    my $nLimit =0;
    if(&isNAND($feature_query_function_ptr) and $nfb_or_emb ne 'BASIC')
    {
        $nLimit = hex($dp_lv_start_string) + hex($dp_lv_size_string);
        &WarnMinus( (0xffffffff - $nLimit), __FILE__, __LINE__, "Demand Paging Region(BASE:$dp_lv_start_string + MAXSIZE:$dp_lv_size_string) can't exceed 0xFFFFFFFF");
    }
    if(defined &$feature_query_function_ptr('multiple_binary_files') && &$feature_query_function_ptr('multiple_binary_files') eq "TRUE")
    {
        $nLimit += hex($lang_pack_size_string) + hex($custpack_size_string);
        &WarnMinus( (0xffffffff - $nLimit), __FILE__, __LINE__, "DP(BASE:$dp_lv_start_string + MAXSIZE:$dp_lv_size_string)+MBA(LANG_PACK MAX=$lang_pack_size_string , CUST_PACK MAX=$custpack_size_string) Region can't exceed 0xFFFFFFFF");
    }
    
    ### Determine ROM/SECONDARY_ROM size : to sync with feature_config.h and custom_img_config.h
    my $nROM_MaxSize = (exists $feature_config_href->{'MAX_ROM_SIZE'}) ? hex($feature_config_href->{'MAX_ROM_SIZE'}) : hex($fota_cfg_href->{'MAX_LENGTH_ROM'});
    my $n2ndROM_MaxSize = (exists $feature_config_href->{'MAX_SECONDARY_ROM_SIZE'}) ? hex($feature_config_href->{'MAX_SECONDARY_ROM_SIZE'}) : hex($fota_cfg_href->{'MAX_LENGTH_SECONDARY_ROM'});
    my $strROM_MaxSize =(($fota eq 'FOTA_DM') or $multibin eq 'TRUE')? &CommonUtil::Dec2Hex($nROM_MaxSize) : "";
    my $str2ndROM_MaxSize = (($fota eq 'FOTA_DM') or $multibin eq 'TRUE')? &CommonUtil::Dec2Hex($n2ndROM_MaxSize) : "";
    ###
    my $ev_hidden_secure_mac;
    if ($fota eq 'FOTA_DM')
    {
        $ev_hidden_secure_mac = layout3_fota_secure_mac_ev();
    }
    else
    {
        $ev_hidden_secure_mac = &layout3_secure_mac_ev();
    }
    
    my $ev_hidden_secure_ro   = &layout3_secure_ro_ev("+0x0");
    my $ev_hidden_toolcfg     = &layout3_toolcfg_ev("+0x0");
    my $ev_hidden_custpara    = &layout3_custpara_ev("+0x0");
	# --- --- ---
	# MT6256 DSP_ROM
	my $MT6256_DSP_ROM = &DSP_MT6256_DSPROM($bb, $dsp_solution, $rs);
    
    # --- --- ---
    # Boot Cert region
    my $boot_cert_rom;
    if ($boot_cert ne 'FALSE' and $boot_cert ne 'NONE')
    {
        $boot_cert_rom = &layout14($bb, $flash_boot_cert_addr, $flash_boot_cert_size_str, "");
    }
    chomp $boot_cert_rom;
    
    # --- --- --- 
    chomp $ev_primary;
    chomp $ev_secondary;
    chomp $ev_demand_paging;
    chomp $ev_lang_pack;
    chomp $ev_custpack_rom;
    chomp $ev_hidden_secure_mac;
    chomp $ev_hidden_secure_ro;
    chomp $ev_hidden_toolcfg;
    chomp $ev_hidden_custpara;

    # --- --- --- 
    my $layout_basic_arm7 = <<"__LAYOUT";
ROM $rom_start_address
{
$ev_primary
}

SECONDARY_ROM $sep_string 0x1400000
{
$ev_secondary
}

__LAYOUT
    # --- --- --- 
    my $layout_basic_arm9_above = <<"__LAYOUT";
ROM $rom_start_address $strROM_MaxSize
{
$ev_primary
}

$dsp_rom
SECONDARY_ROM $second_rom_start_address $str2ndROM_MaxSize
{
$ev_secondary
}

$boot_cert_rom

$MT6256_DSP_ROM

__LAYOUT
    # --- --- --- 
    my $layout_secure_basic_nfb = <<"__LAYOUT";
ROM $rom_start_address $strROM_MaxSize
{
$ev_primary
}

$dsp_rom
SECONDARY_ROM $second_rom_start_address $str2ndROM_MaxSize
{
$ev_secondary
}

$boot_cert_rom

$MT6256_DSP_ROM

;=========================================================================
; This load region must be behind all the protected load region
;=========================================================================
; 1. Only address is configurable.
; 2. Region address must be fixed address.
; 4. DO NOT modify load region order, load region naming and pragma naming!
;=========================================================================
__HIDDEN_SECURE_MAC $flash_secure_mac_addr $flash_secure_mac_size_str
{
$ev_hidden_secure_mac
}

__HIDDEN_SECURE_RO $flash_secure_ro_addr $flash_secure_ro_size_str
{
$ev_hidden_secure_ro
}

__HIDDEN_FLASHTOOL_CFG $flash_toolcfg_addr $flash_toolcfg_size_str
{
$ev_hidden_toolcfg
}

__HIDDEN_CUST_PARA $flash_custpara_addr $flash_custpara_size_str
{
$ev_hidden_custpara
}

__LAYOUT
     # --- --- --- 
    my $layout_dp_nfb = <<"__LAYOUT";
ROM $rom_start_address $strROM_MaxSize
{
$ev_primary
}

$dsp_rom

SECONDARY_ROM $second_rom_start_address $str2ndROM_MaxSize
{
$ev_secondary
}

$boot_cert_rom

$MT6256_DSP_ROM

DEMAND_PAGING_ROM0 $dp_lv_start_string $dp_lv_size_string
{
$ev_demand_paging
}

__LAYOUT
    # --- --- --- 
    my $layout_mbin_ondemand_dp_nfb = <<"__LAYOUT";
ROM $rom_start_address $strROM_MaxSize
{
$ev_primary
}

$dsp_rom

SECONDARY_ROM $second_rom_start_address $str2ndROM_MaxSize
{
$ev_secondary
}

$boot_cert_rom

$MT6256_DSP_ROM

DEMAND_PAGING_ROM0 $dp_lv_start_string $dp_lv_size_string
{
$ev_demand_paging
}

$lv_mba

__LAYOUT
    # --- --- --- 
    my $layout_secure_dp_nfb = <<"__LAYOUT";
ROM $rom_start_address $strROM_MaxSize
{
$ev_primary
}

$dsp_rom

SECONDARY_ROM $second_rom_start_address $str2ndROM_MaxSize
{
$ev_secondary
}

$boot_cert_rom

$MT6256_DSP_ROM

DEMAND_PAGING_ROM0 $dp_lv_start_string $dp_lv_size_string
{
$ev_demand_paging
}

;=========================================================================
; This load region must be behind all the protected load region
;=========================================================================
; 1. Only address is configurable.
; 2. Region address must be fixed address.
; 4. DO NOT modify load region order, load region naming and pragma naming!
;=========================================================================
__HIDDEN_SECURE_MAC $flash_secure_mac_addr $flash_secure_mac_size_str
{
$ev_hidden_secure_mac
}

__HIDDEN_SECURE_RO $flash_secure_ro_addr $flash_secure_ro_size_str
{
$ev_hidden_secure_ro
}

__HIDDEN_FLASHTOOL_CFG $flash_toolcfg_addr $flash_toolcfg_size_str
{
$ev_hidden_toolcfg
}

__HIDDEN_CUST_PARA $flash_custpara_addr $flash_custpara_size_str
{
$ev_hidden_custpara
}

__LAYOUT
    # --- --- --- 
    my $layout_secure_mbin_ondemand_dp_nfb = <<"__LAYOUT";
ROM $rom_start_address $strROM_MaxSize
{
$ev_primary
}

$dsp_rom

SECONDARY_ROM $second_rom_start_address $str2ndROM_MaxSize
{
$ev_secondary
}

$boot_cert_rom

$MT6256_DSP_ROM

DEMAND_PAGING_ROM0 $dp_lv_start_string $dp_lv_size_string
{
$ev_demand_paging
}

$lv_mba

;=========================================================================
; This load region must be behind all the protected load region
;=========================================================================
; 1. Only address is configurable.
; 2. Region address must be fixed address.
; 4. DO NOT modify load region order, load region naming and pragma naming!
;=========================================================================
__HIDDEN_SECURE_MAC $flash_secure_mac_addr $flash_secure_mac_size_str
{
$ev_hidden_secure_mac
}

__HIDDEN_SECURE_RO $flash_secure_ro_addr $flash_secure_ro_size_str
{
$ev_hidden_secure_ro
}

__HIDDEN_FLASHTOOL_CFG $flash_toolcfg_addr $flash_toolcfg_size_str
{
$ev_hidden_toolcfg
}

__HIDDEN_CUST_PARA $flash_custpara_addr $flash_custpara_size_str
{
$ev_hidden_custpara
}

__LAYOUT

    # --- --- --- 
    if ($nfb_or_emb eq 'ONDEMAND')
    {
        if ($multibin eq 'TRUE' and $security eq 'TRUE')
        {
            return $layout_secure_mbin_ondemand_dp_nfb;
        }
        elsif ($multibin eq 'TRUE')
        {
            return $layout_mbin_ondemand_dp_nfb;
        }
        elsif ($security eq 'TRUE')
        {
            return $layout_secure_dp_nfb;
        }
        else
        {
            return $layout_dp_nfb;
        }
    }
    elsif ($nfb_or_emb eq 'BASIC')
    {
        if ($multibin eq 'TRUE')
        {
            &sysUtil::sysgen_die("$themf: Unsupported Combination BASIC NFB + MULTIPLE_BINARY_FILES!", __FILE__, __LINE__);
        }
        elsif ($fota eq 'FOTA_DM' and $fast_boot eq 'FACTORY_ONLY')
        {
            &sysUtil::sysgen_die("$themf: Unsupported Combination BASIC NFB + FOTA for factory bin!", __FILE__, __LINE__);
        }
        elsif ($security eq 'TRUE')
        {
            if ((&sysUtil::is_arm9($bb) == 1) or (&sysUtil::is_arm11($bb) == 1))
            {
                return $layout_secure_basic_nfb;
            }
            else
            {
                &sysUtil::sysgen_die("$themf: Unsupported Combination BASIC NFB + SECURE_SUPPORT on ARM7 platforms!", __FILE__, __LINE__);
            }
        }
        else
        {
            if ((&sysUtil::is_arm9($bb) == 1) or (&sysUtil::is_arm11($bb) == 1))
            {
                return $layout_basic_arm9_above;
            }
            else
            {
                return $layout_basic_arm7;
            }
        }
    }
    else
    {
        &sysUtil::sysgen_die("$themf: Unsupported NAND_FLASH_BOOTING setting $nfb_or_emb in project makefile!", __FILE__, __LINE__);
    }
}

#****************************************************************************
# subroutine:  Default Layout <Class>
# return:      the body strings
#****************************************************************************
sub layout0
{
    my ($bb, $fs, $rs, $boot_cert) = @_;
    my $fbase   = sprintf("0x%08x", &lv_rom_fbase($bb));
    my $alice = &$feature_query_function_ptr('alice_support');
    
    # --- --- ---
    # Boot Cert region    
    my $flash_boot_cert_size = 4 * 1024;
    my $flash_boot_cert_size_str = sprintf("0x%08x", $flash_boot_cert_size);
    my $flash_boot_cert_base_str;
    my $boot_cert_rom;
    my $boot_cert_Attribute;   
    $boot_cert_Attribute = (($alice eq 'TRUE') and $Is_Flashtool_Layout != 1)? "OVERLAY" : "";
        
    if ($boot_cert ne 'FALSE' and $boot_cert ne 'NONE')
    {
        $fs -= $flash_boot_cert_size;
        $flash_boot_cert_base_str = sprintf("0x%08x", &config_query_flash_base_address($bb) + $fs);
        $boot_cert_rom = &layout14($bb, $flash_boot_cert_base_str, $flash_boot_cert_size_str, $boot_cert_Attribute);
    }
    chomp $boot_cert_rom;
    
    # --- --- ---
    # ALICE region
    my ($VIVA_rom, $ALICE_rom);
    my $comp_alice;
    if(defined $alice and $alice eq 'TRUE')
    {   
        &sysUtil::sysgen_die("$bb_folder/custom_FeatureConfig.h: CONFIG_ALICE_MAX_COMPRESSED_SIZE need to be defined when ALICE_SUPPORT is turned on!", __FILE__, __LINE__)
           if (!defined($feature_config_href->{'CONFIG_ALICE_MAX_COMPRESSED_SIZE'}));
        $comp_alice = $feature_config_href->{'CONFIG_ALICE_MAX_COMPRESSED_SIZE'};
        my $viva_header_size = &sysUtil::query_viva_size($bb);    
        $VIVA_rom = &layoutVIVA("+0x400", &CommonUtil::Dec2Hex($viva_header_size), $bb);
        $ALICE_rom = &layoutALICE("+0x0");                
        $fs -=  (hex($comp_alice) + 0x400 + $viva_header_size);      
    }
    
    
    &WarnMinus($fs - &config_query_rom_offset(), __FILE__, __LINE__, "Layout0: ROM Size is not correct or flash can't put in VIVA regions:\nALICE region($comp_alice)");
    my $flength = sprintf("0x%08x", $fs - &config_query_rom_offset() );
    my $ev_rom_default = &layout0_rom_ev($bb, $fbase, $rs, $flength, "0x0");
        
    # --- --- --- 
    chomp $ev_rom_default;
    # --- --- --- 
    my $layout_default = <<"__LAYOUT";
; ROM Load region is block-aligned
ROM $fbase
{
$ev_rom_default
}
$VIVA_rom
$ALICE_rom
$boot_cert_rom
__LAYOUT
    return $layout_default;
}

{ # global variables and query functions

#****************************************************************************
# subroutine:  SCHEME Configure Routines :: Query Flash Block Size
# input:       Flash Offset Address
# Output:      Flash block size
#****************************************************************************
sub config_query_flash_block_sz
{
    my ($offset) = @_;
    my $flash_size   = $g_nFlashSize;
   
    &sysUtil::sysgen_die("tools/scatGenLib.pl: Query Block Size at $offset larger than available size!", __FILE__, __LINE__) if ($offset > $flash_size);

    my $href   = $norflash_info_blk_href;
    &sysUtil::sysgen_die("tools/scatGenLib.pl: Block Size Information Unavailable, Please check EMI DataBase and custom_flash.c!", __FILE__, __LINE__) unless defined $href;

    my @offset = sort {$b <=> $a} keys %$href;

    foreach my $i (@offset)
    {
        return $href->{$i} if ($offset >= $i);
    }
    &sysUtil::sysgen_die("tools/scatGenLib.pl: Unreachable!", __FILE__, __LINE__);
}

#****************************************************************************
# subroutine:  SCHEME Configure Routines :: Query Max Flash Block Size before offset
# input:       Flash Offset Address
# Output:      Flash block size
#****************************************************************************
sub config_query_max_flash_block_sz
{
    my ($offset) = @_;
    my $flash_size   = $g_nFlashSize;
    my $max_block_sz = 0;

    &sysUtil::sysgen_die("tools/scatGenLib.pl: Query Block Size at $offset larger than available size!", __FILE__, __LINE__) if ($offset > $flash_size);

    my $href   = $norflash_info_blk_href;
    &sysUtil::sysgen_die("tools/scatGenLib.pl: Block Size Information Unavailable, Please check EMI DataBase and custom_flash.c!", __FILE__, __LINE__) unless defined $href;

    my @offset = sort {$b <=> $a} keys %$href;

    foreach my $i (@offset)
    {
         if ($offset > $i)
         {
              if (hex($max_block_sz) < hex($href->{$i}))
              {
                   $max_block_sz = $href->{$i};
              }
         }
    }
    return $max_block_sz;
}

#****************************************************************************
# subroutine:  SCHEME Configure Routines :: Query Next Block-aligned Addr from input Addr
# input:       Address, Offset to the next destination
# Output:      Next block-aligned addr
#****************************************************************************
sub config_query_next_block_aligned_addr
{
    my ($addr, $offset) = @_;
    my $flash_size   = $g_nFlashSize;

    &sysUtil::sysgen_die("tools/scatGenLib.pl: Query Block-aligned addr at ($addr + $offset) larger than available size!", __FILE__, __LINE__) if (($addr+$offset) > $flash_size);

    my $tmp_addr = $addr;
    while ($tmp_addr < ($addr+$offset))
    {
        my $nblock_size = &config_query_flash_block_size($tmp_addr);
        $tmp_addr = ($tmp_addr % $nblock_size ==0) ? $tmp_addr+$nblock_size : (int($tmp_addr /$nblock_size)+1)*$nblock_size;
    }
    &sysUtil::sysgen_die("tools/scatGenLib.pl: Query Block-aligned addr at $tmp_addr larger than available size!", __FILE__, __LINE__) if ($tmp_addr > $flash_size);
    return $tmp_addr;
}

#****************************************************************************
# subroutine:  SCHEME Configure Routines :: Setup
# input:       BB chip
# Output:      NOR Flash / External RAM Chip Select swap determine
#              ROM begin address offset determine
#****************************************************************************
sub config_setup
{
    my ($bb) = @_;

    my $esb    = &$feature_query_function_ptr('enhanced_single_bank_nor_flash_support');
    my $fota   = &$feature_query_function_ptr('fota_enable');
    my $usbdl  = &$feature_query_function_ptr('usb_download_in_bl');
    #if (defined $nfb_or_emb and $nfb_or_emb ne 'NONE')
    if(&isNAND($feature_query_function_ptr))
    {
         return;
    }
    if (&sysUtil::is_mpu_capable($bb) or defined &sysUtil::is_arm9($bb)
       or &sysUtil::is_arm11($bb) or &sysUtil::is_CR4($bb))
    {
        # determine $g_config_cs_swap
        if ($bl_exist eq 'TRUE')
        {
            $g_config_cs_swap = 1;
        }
        if (defined $esb and $esb eq 'TRUE')
        {
            $g_config_cs_swap = 1;  
        }
        if (defined $usbdl and $usbdl ne 'NONE')
        {
            $g_config_cs_swap = 1;  
        }
        if (defined $fota and $fota eq 'FOTA_DM')
        {
            $g_config_cs_swap = 1;  
        }
    }
}

#****************************************************************************
# subroutine:  SCHEME Configure Routines :: Query :: Flash Base
# input:       BB chip
# Output:      Configure Flash Base Address
#****************************************************************************
sub config_query_flash_base_address
{
   my ($bb) = @_;
   my $addr = 0;
   return $addr if ($g_config_cs_swap == 0);
   return &sysUtil::query_cs1_addr($bb, $addr, 0);
}

#****************************************************************************
# subroutine:  SCHEME Configure Routines :: Query :: ROM BEGIN OFFSET
# input:       None
# Output:      Begin offset
#****************************************************************************
sub config_query_rom_offset
{
   return $g_config_rom_offset;
}
#****************************************************************************
# subroutine:  SCHEME Configure Routines :: Set :: ROM BEGIN OFFSET
# input:       (nRomBaseAddress) or (nRomBaseAddress + Additional Offset)
# Output:      N/A
#****************************************************************************
sub config_reset_rom_offset
{
    my ($nNewOffset) = @_;
    $g_config_rom_offset = $nNewOffset;
}
#****************************************************************************
# subroutine:  SCHEME Configure Routines :: Set :: ROM BEGIN OFFSET
# input:       None
# Output:      Begin offset
#****************************************************************************
sub config_add_rom_offset
{
    my ($new_offset) = @_;

    my $nBlockSize = 0;
    # to see how many blocks it needs.
    while ($nBlockSize < $new_offset)
    {
    	$nBlockSize += &config_query_flash_block_sz($g_config_rom_offset+$nBlockSize);
    }
    $g_config_rom_offset += $nBlockSize;
}

#****************************************************************************
# subroutine:  SCHEME Configure Routines :: Query Remapping
# Output:      Remapping: 1
#****************************************************************************
sub config_query_remapping
{
    return $g_config_cs_swap;
}

#****************************************************************************
# subroutine:  SCHEME Configure Routines :: Query :: External SRAM Base
# input:       BB chip
# Output:      Configured External SRAM Base Address
#****************************************************************************
sub config_query_extsram_base_address
{
   my ($bb) = @_;

   my $addr = 0;
   return $addr if ($g_config_cs_swap == 1);
   return &sysUtil::query_cs1_addr($bb, $addr, 0);
}
}# global variables and query functions
#****************************************************************************
# subroutine:  SCHEME Configure Routines :: Query :: ROM/SECONDARY_ROM Base
# input:       EXTSRAM size
# Output:      Configured ROM/SECONDARY_ROM Base Address
#****************************************************************************
sub config_query_nfb_rom_secrom_base_address
{
	my ($rs) = @_;
    # Configure Primary ROM and SECONDARY_ROM base address
    my ($rom_start_address, $second_rom_start_address);
    my $dsp_solution = &$feature_query_function_ptr('dsp_solution');
    my $fota         = &$feature_query_function_ptr('fota_enable');
    
    # Determine ROM base address
    if (defined $dsp_solution and $dsp_solution eq 'DUALMACDSP')
    {
    	$rom_start_address = "0x180000";  # Reserve 0~1.5MB for DSP execution view
    }
    else
    {
    	if ($fota eq 'FOTA_DM')
    	{
    		$rom_start_address = "+0x00";
    	}
    	else
    	{
    		$rom_start_address = "0x00";
    	}
    }

    # Determine SECONDARY_ROM base address
    if (defined $dsp_solution and $dsp_solution eq 'DUALMACDSP')
    {
        if ($rs > (512/8*1024*1024))
        {
            # Ensure there are at least 4MB between symbols in ROM and SECONDARY_ROM to prevent L6286E
            $second_rom_start_address = "0x880000";
        }
        else
        {
            # Save more space for slimming projects
            $second_rom_start_address = "+0x4000";
        }
    }
    else
    {
        $second_rom_start_address = "+0x4000";
    }
    
    return ($rom_start_address, $second_rom_start_address);
}

#****************************************************************************
# subroutine:  Default Layout :: Load View :: ROM base address
# input:       BB chip
#****************************************************************************
sub lv_rom_fbase
{
    my ($bb) = @_;
    return &config_query_flash_base_address($bb) + &config_query_rom_offset();
}

#****************************************************************************
# subroutine:  Default Layout :: Exec View :: EXTSRAM base address
# input:       BB chip
#****************************************************************************
sub ev_extsram_base
{
    my ($bb) = @_;
    return &config_query_extsram_base_address($bb);
}

#****************************************************************************
# subroutine:  SECURE Layout :: ROM :: Exec View
# input:       BB chip, flash base address[value], ram size [value]
#****************************************************************************
sub layout3_rom_ev
{
    my ($bb, $fbAddr, $ram_size_value, $decomp_zlength_str) = @_;
    my $fbAddr_string = sprintf("0x%08x", $fbAddr);
    my %BBtbl_RVCT =
       (     'MT6235'  => sub { &ROM_type_0_RVCT($bb, $fbAddr_string, "TRUE") .
                                &EXTSRAM_type_7($bb, &ev_extsram_base($bb), $ram_size_value, $decomp_zlength_str) .
                                &INTSRAM_type1($bb) .
                                &INTSRAM_DCM_EV($bb) .
                                &INTSRAM_PAGETABLE_EV($bb, "0x40004000", "0x0000B000") .
                                &INTSRAM_MED_EV($bb, "0x40000000", 1, "0x00010000") .
                                &FLMM_EV($bb); },
             'MT6235B' => sub { &ROM_type_0_RVCT($bb, $fbAddr_string, "TRUE") .
                                &EXTSRAM_type_7($bb, &ev_extsram_base($bb), $ram_size_value, $decomp_zlength_str) .
                                &INTSRAM_type1($bb) .
                                &INTSRAM_DCM_EV($bb) .
                                &INTSRAM_PAGETABLE_EV($bb, "0x40004000", "0x0000B000") .
                                &INTSRAM_MED_EV($bb, "0x40000000", 1, "0x00010000") .
                                &FLMM_EV($bb); },
             'MT6236'  => sub { &ROM_type_0_RVCT($bb, $fbAddr_string, "TRUE") .
                                &EXTSRAM_type_7($bb, &ev_extsram_base($bb), $ram_size_value, $decomp_zlength_str) .
                                &INTSRAM_type1($bb) .
                                &INTSRAM_DCM_EV($bb) .
                                &INTSRAM_PAGETABLE_EV($bb, "0x40004000", "0x00015000") .
                                &INTSRAM_MED_EV($bb, "0x40000000", 1, "0x0001A000") .
                                &FLMM_EV($bb); },
             'MT6236B' => sub { &ROM_type_0_RVCT($bb, $fbAddr_string, "TRUE") .
                                &EXTSRAM_type_7($bb, &ev_extsram_base($bb), $ram_size_value, $decomp_zlength_str) .
                                &INTSRAM_type1($bb) .
                                &INTSRAM_DCM_EV($bb) .
                                &INTSRAM_PAGETABLE_EV($bb, "0x40004000", "0x00015000") .
                                &INTSRAM_MED_EV($bb, "0x40000000", 1, "0x0001A000") .
                                &FLMM_EV($bb); },
             'MT6921'  => sub { &ROM_type_0_RVCT($bb, $fbAddr_string, "TRUE") .
                                &EXTSRAM_type_7($bb, &ev_extsram_base($bb), $ram_size_value, $decomp_zlength_str) .
                                &INTSRAM_type1($bb) .
                                &INTSRAM_DCM_EV($bb) .
                                &INTSRAM_PAGETABLE_EV($bb, "0x40004000", "0x00015000") .
                                &INTSRAM_MED_EV($bb, "0x40000000", 1, "0x0001A000") .
                                &FLMM_EV($bb); },
             'MT6253'  => sub { &ROM_type_0_RVCT($bb, $fbAddr_string, "TRUE") .
                                &EXTSRAM_type_2($bb, $ram_size_value, "0x0") .
                                &INTSRAM_type1($bb) .
                                &INTSRAM_DCM_EV($bb) .
                                &INTSRAM_MED_EV($bb, "0x4001C000", 0, "0x4000"); },
             'MT6251'  => sub { &ROM_type_0_RVCT($bb, $fbAddr_string, "TRUE") . 
                                &shouldbe_emptysection() . 
                                &INTSRAM_type3($bb) . 
                                &ROM_SIGNATURE_SECTION_EV($bb, "ROM", "MAUI");},
             'MT6253E' => sub { &ROM_type_0_RVCT($bb, $fbAddr_string, "TRUE") . 
                                &EXTSRAM_type_7($bb, &ev_extsram_base($bb), $ram_size_value, $decomp_zlength_str) .
                                &INTSRAM_type1($bb) .
                                &INTSRAM_DCM_EV($bb) .
                                &INTSRAM_MED_EV($bb, "0x40000000", 0, "0x1A000"); },
             'MT6253L' => sub { &ROM_type_0_RVCT($bb, $fbAddr_string, "TRUE") . 
                                &EXTSRAM_type_7($bb, &ev_extsram_base($bb), $ram_size_value, $decomp_zlength_str) .
                                &INTSRAM_type1($bb) .
                                &INTSRAM_DCM_EV($bb) .
                                &INTSRAM_MED_EV($bb, "0x40000000", 0, "0x1A000"); },
             'MT6252H' => sub { &ROM_type_0_RVCT($bb, $fbAddr_string, "TRUE") . 
                                &EXTSRAM_type_7($bb, &ev_extsram_base($bb), $ram_size_value, $decomp_zlength_str) .
                                &INTSRAM_type1($bb) .
                                &INTSRAM_DCM_EV($bb) .
                                &INTSRAM_MED_EV($bb, "0x40000000", 0, "0x1A000"); },
             'MT6252'  => sub { &ROM_type_0_RVCT($bb, $fbAddr_string, "TRUE") . 
                                &EXTSRAM_type_7($bb, &ev_extsram_base($bb), $ram_size_value, $decomp_zlength_str) .
                                &INTSRAM_type1($bb) .
                                &INTSRAM_DCM_EV($bb) .
                                &INTSRAM_MED_EV($bb, "0x40000000", 0, "0x1A000"); },
             'MT6280'  => sub { &ROM_type_0_RVCT($bb, $fbAddr_string, "TRUE") . 
                                &EXTSRAM_type_7($bb, &ev_extsram_base($bb), $ram_size_value, $decomp_zlength_str) .
                                &INTSRAM_type1($bb) .
                                &INTSRAM_DCM_EV($bb) .
                                &INTSRAM_MED_EV($bb, "0x40000000", 0, "0x1A000"); },
             'MT6255' => sub { &ROM_type_0_RVCT($bb, $fbAddr_string, "TRUE") .
                                &EXTSRAM_type_7($bb, &ev_extsram_base($bb), $ram_size_value, $decomp_zlength_str) .
                                &INTSRAM_type1($bb) .
                                &INTSRAM_DCM_EV($bb) .
                                &INTSRAM_MED_EV($bb, "0x40000000", 1, "0x00007000") .
                                &FLMM_EV($bb); },
             'MT6922' => sub { &ROM_type_0_RVCT($bb, $fbAddr_string, "TRUE") .
                                &EXTSRAM_type_7($bb, &ev_extsram_base($bb), $ram_size_value, $decomp_zlength_str) .
                                &INTSRAM_type1($bb) .
                                &INTSRAM_DCM_EV($bb) .
                                &INTSRAM_MED_EV($bb, "0x40000000", 1, "0x00007000") .
                                &FLMM_EV($bb); },
             'MT6250'  => sub { &ROM_type_0_RVCT($bb, $fbAddr_string, "TRUE") . 
                                &EXTSRAM_type_7($bb, &ev_extsram_base($bb), $ram_size_value, "0x0") .
                                &INTSRAM_type1($bb) .
                                &INTSRAM_DCM_EV($bb) .
                                &INTSRAM_MED_EV($bb, "0x40000000", 0, "0x1A000"); },               
       );
    my $func;
    my $compiler = &$feature_query_function_ptr('compiler');
    if ($compiler eq 'RVCT')
    {
    	   $func = $BBtbl_RVCT{$bb};
    }
    return &$func;
}

#****************************************************************************
# subroutine:  SECURE+USB-DL Layout :: ROM :: Exec View
# input:       BB chip, flash base address[value], ram size [value]
#****************************************************************************
sub layout3_secusb_rom_ev
{
    my ($bb, $fbAddr, $ram_size_value, $decomp_zlength_str) = @_;
    my %BBtbl_RVCT =
       (
             'MT6235'  => sub { &ROM_type_4_RVCT($bb, $fbAddr) .
                                &EXTSRAM_type_7($bb, &ev_extsram_base($bb), $ram_size_value, $decomp_zlength_str) .
                                &INTSRAM_type1($bb) .
                                &INTSRAM_DCM_EV($bb) .
                                &INTSRAM_PAGETABLE_EV($bb, "0x40004000", "0x0000B000") .
                                &INTSRAM_MED_EV($bb, "0x40000000", 1, "0x00010000") .
                                &FLMM_EV($bb); },
             'MT6235B' => sub { &ROM_type_4_RVCT($bb, $fbAddr) .
                                &EXTSRAM_type_7($bb, &ev_extsram_base($bb), $ram_size_value, $decomp_zlength_str) .
                                &INTSRAM_type1($bb) .
                                &INTSRAM_DCM_EV($bb) .
                                &INTSRAM_PAGETABLE_EV($bb, "0x40004000", "0x0000B000") .
                                &INTSRAM_MED_EV($bb, "0x40000000", 1, "0x00010000") .
                                &FLMM_EV($bb); },
             'MT6236'  => sub { &ROM_type_4_RVCT($bb, $fbAddr) .
                                &EXTSRAM_type_7($bb, &ev_extsram_base($bb), $ram_size_value, $decomp_zlength_str) .
                                &INTSRAM_type1($bb) .
                                &INTSRAM_DCM_EV($bb) .
                                &INTSRAM_PAGETABLE_EV($bb, "0x40004000", "0x00015000") .
                                &INTSRAM_MED_EV($bb, "0x40000000", 1, "0x0001A000") .
                                &FLMM_EV($bb); },
             'MT6236B' => sub { &ROM_type_4_RVCT($bb, $fbAddr) .
                                &EXTSRAM_type_7($bb, &ev_extsram_base($bb), $ram_size_value, $decomp_zlength_str) .
                                &INTSRAM_type1($bb) .
                                &INTSRAM_DCM_EV($bb) .
                                &INTSRAM_PAGETABLE_EV($bb, "0x40004000", "0x00015000") .
                                &INTSRAM_MED_EV($bb, "0x40000000", 1, "0x0001A000") .
                                &FLMM_EV($bb); },
             'MT6921'  => sub { &ROM_type_4_RVCT($bb, $fbAddr) .
                                &EXTSRAM_type_7($bb, &ev_extsram_base($bb), $ram_size_value, $decomp_zlength_str) .
                                &INTSRAM_type1($bb) .
                                &INTSRAM_DCM_EV($bb) .
                                &INTSRAM_PAGETABLE_EV($bb, "0x40004000", "0x00015000") .
                                &INTSRAM_MED_EV($bb, "0x40000000", 1, "0x0001A000") .
                                &FLMM_EV($bb); },
             'MT6253'  => sub { &ROM_type_4_RVCT($bb, $fbAddr) .
                                &EXTSRAM_type_2($bb, $ram_size_value, "0x0") .
                                &INTSRAM_type1($bb) .
                                &INTSRAM_DCM_EV($bb) .
                                &INTSRAM_MED_EV($bb, "0x4001C000", 0, "0x4000"); },
             'MT6253E' => sub { &ROM_type_4_RVCT($bb, $fbAddr) .
                                &EXTSRAM_type_7($bb, &ev_extsram_base($bb), $ram_size_value, $decomp_zlength_str) .
                                &INTSRAM_type1($bb) .
                                &INTSRAM_DCM_EV($bb) .
                                &INTSRAM_MED_EV($bb, "0x40000000", 0, "0x1A000"); },
             'MT6253L' => sub { &ROM_type_4_RVCT($bb, $fbAddr) .
                                &EXTSRAM_type_7($bb, &ev_extsram_base($bb), $ram_size_value, $decomp_zlength_str) .
                                &INTSRAM_type1($bb) .
                                &INTSRAM_DCM_EV($bb) .
                                &INTSRAM_MED_EV($bb, "0x40000000", 0, "0x1A000"); },
             'MT6252H' => sub { &ROM_type_4_RVCT($bb, $fbAddr) .
                                &EXTSRAM_type_7($bb, &ev_extsram_base($bb), $ram_size_value, $decomp_zlength_str) .
                                &INTSRAM_type1($bb) .
                                &INTSRAM_DCM_EV($bb) .
                                &INTSRAM_MED_EV($bb, "0x40000000", 0, "0x1A000"); },
             'MT6252'  => sub { &ROM_type_4_RVCT($bb, $fbAddr) .
                                &EXTSRAM_type_7($bb, &ev_extsram_base($bb), $ram_size_value, $decomp_zlength_str) .
                                &INTSRAM_type1($bb) .
                                &INTSRAM_DCM_EV($bb) .
                                &INTSRAM_MED_EV($bb, "0x40000000", 0, "0x1A000"); },
             'MT6280' => sub { &ROM_type_4_RVCT($bb, $fbAddr) .
                                &EXTSRAM_type_7($bb, &ev_extsram_base($bb), $ram_size_value, $decomp_zlength_str) .
                                &INTSRAM_type1($bb) .
                                &INTSRAM_DCM_EV($bb) .
                                &INTSRAM_MED_EV($bb, "0x40000000", 0, "0x1A000"); },
             'MT6255' => sub { &ROM_type_4_RVCT($bb, $fbAddr) .
                                &EXTSRAM_type_7($bb, &ev_extsram_base($bb), $ram_size_value, $decomp_zlength_str) .
                                &INTSRAM_type1($bb) .
                                &INTSRAM_DCM_EV($bb) .
                                &INTSRAM_MED_EV($bb, "0x40000000", 1, "0x00007000") .
                                &FLMM_EV($bb); },
             'MT6922' => sub { &ROM_type_4_RVCT($bb, $fbAddr) .
                                &EXTSRAM_type_7($bb, &ev_extsram_base($bb), $ram_size_value, $decomp_zlength_str) .
                                &INTSRAM_type1($bb) .
                                &INTSRAM_DCM_EV($bb) .
                                &INTSRAM_MED_EV($bb, "0x40000000", 1, "0x00007000") .
                                &FLMM_EV($bb); },
             'MT6250'  => sub { &ROM_type_4_RVCT($bb, $fbAddr) .
                                &EXTSRAM_type_7($bb, &ev_extsram_base($bb), $ram_size_value, "0x0") .
                                &INTSRAM_type1($bb) .
                                &INTSRAM_DCM_EV($bb) .
                                &INTSRAM_MED_EV($bb, "0x40000000", 0, "0x1A000"); },                                   
       );
       #map {print $_, "\n";} keys %BBtbl;
    &sysUtil::sysgen_die("tools/scatGenLib.pl: Unsupported Feature Combination SECURE+USB-Download or SECURE+FOTA on $bb!", __FILE__, __LINE__) if not exists $BBtbl_RVCT{$bb}; 
    my $func;
    my $compiler = &$feature_query_function_ptr('compiler');
    if ($compiler eq 'RVCT')
    {
    	   $func = $BBtbl_RVCT{$bb};
    }
    return &$func;
}

#****************************************************************************
# subroutine:  NFB Layout :: PRIMARY ROM :: Exec View
# input:       BB chip, flash size[value], ram size [value]
#****************************************************************************
sub layout1_primaryrom_ev
{
    my ($bb, $ram_size_value, $multibin, $security) = @_;
    my %BBtbl =
       (
             'MT6235'  => sub { &ROM_type_1($bb, $multibin, $security) .
                                &EXTSRAM_type_8($bb) .
                                &INTSRAM_type1($bb);}, 
             'MT6235B' => sub { &ROM_type_1($bb, $multibin, $security) .
                                &EXTSRAM_type_8($bb) .
                                &INTSRAM_type1($bb);}, 
             'MT6236'  => sub { &ROM_type_1($bb, $multibin, $security) .
                                &EXTSRAM_type_8($bb) .
                                &INTSRAM_type1($bb);}, 
             'MT6236B' => sub { &ROM_type_1($bb, $multibin, $security) .
                                &EXTSRAM_type_8($bb) .
                                &INTSRAM_type1($bb);}, 
             'MT6921'  => sub { &ROM_type_1($bb, $multibin, $security) .
                                &EXTSRAM_type_8($bb) .
                                &INTSRAM_type1($bb);},
             'MT6268'  => sub { &ROM_type_1($bb, $multibin, $security) .
                                &EXTSRAM_type_8($bb) .
                                &INTSRAM_type1($bb);},                   
             'MT6276'  => sub { &ROM_type_1($bb, $multibin, $security) .
                                &EXTSRAM_type_8($bb) .
                                &INTSRAM_type1($bb) . 
                                &ROM_SIGNATURE_SECTION_EV($bb, "ROM", "MAUI");},
             'MT6256'  => sub { &ROM_type_1($bb, $multibin, $security) .
                                &EXTSRAM_type_8($bb) .
                                &INTSRAM_type1($bb) . 
                                &ROM_SIGNATURE_SECTION_EV($bb, "ROM", "MAUI");},
             'MT6255'  => sub { &ROM_type_1($bb, $multibin, $security) .
                                &EXTSRAM_type_8($bb) .
                                &INTSRAM_type1($bb) . 
                                &ROM_SIGNATURE_SECTION_EV($bb, "ROM", "MAUI");},
             'MT6922'  => sub { &ROM_type_1($bb, $multibin, $security) .
                                &EXTSRAM_type_8($bb) .
                                &INTSRAM_type1($bb) . 
                                &ROM_SIGNATURE_SECTION_EV($bb, "ROM", "MAUI");},
       );
       #map {print $_, "\n";} keys %BBtbl;
    &sysUtil::sysgen_die("tools/scatGenLib.pl: Unsupported Feature Combination NFB on $bb!", __FILE__, __LINE__) if not exists $BBtbl{$bb}; 
    if ((&sysUtil::is_arm9($bb) != 1) and (&sysUtil::is_arm11($bb) != 1))
    {
        &sysUtil::sysgen_die("tools/scatGenLib.pl: NFB PRIMARY MAUI size $ram_size_value cannot < 8MB on ARM7 platforms!", __FILE__, __LINE__) if $ram_size_value < (8 * 1024 * 1024);
    }
    my $func = $BBtbl{$bb};
    return &$func;
}

#****************************************************************************
# subroutine:  NFB Layout :: PRIMARY ROM :: Exec View (NFB = BASIC)
# input:       BB chip, flash size[value], ram size [value]
#****************************************************************************
sub layout1_primaryrom_basic_ev
{
    my ($bb, $ram_size_value, $multibin, $security) = @_;
    my %BBtbl =
       (
             'MT6235'  => sub { &ROM_type_1($bb, $multibin, $security) .
                                &EXTSRAM_type_8($bb) .
                                &INTSRAM_type1($bb) .
                                &INTSRAM_DCM_EV($bb);}, 
             'MT6235B' => sub { &ROM_type_1($bb, $multibin, $security) .
                                &EXTSRAM_type_8($bb) .
                                &INTSRAM_type1($bb) .
                                &INTSRAM_DCM_EV($bb);}, 
             'MT6236'  => sub { &ROM_type_1($bb, $multibin, $security) .
                                &EXTSRAM_type_8($bb) .
                                &INTSRAM_type1($bb) .
                                &INTSRAM_DCM_EV($bb);}, 
             'MT6236B' => sub { &ROM_type_1($bb, $multibin, $security) .
                                &EXTSRAM_type_8($bb) .
                                &INTSRAM_type1($bb) .
                                &INTSRAM_DCM_EV($bb);}, 
             'MT6921' => sub { &ROM_type_1($bb, $multibin, $security) .
                                &EXTSRAM_type_8($bb) .
                                &INTSRAM_type1($bb) .
                                &INTSRAM_DCM_EV($bb);}, 
             'MT6268'  => sub { &ROM_type_1($bb, $multibin, $security) .
                                &EXTSRAM_type_8($bb) .
                                &INTSRAM_type1($bb) .
                                &INTSRAM_DCM_EV($bb);},                   
             'MT6276'  => sub { &ROM_type_1($bb, $multibin, $security) .
                                &EXTSRAM_type_8($bb) .
                                &INTSRAM_type1($bb) . 
                                &INTSRAM_DCM_EV($bb) . 
                                &ROM_SIGNATURE_SECTION_EV($bb, "ROM", "MAUI");},
             'MT6256'  => sub { &ROM_type_1($bb, $multibin, $security) .
                                &EXTSRAM_type_8($bb) .
                                &INTSRAM_type1($bb) . 
                                &INTSRAM_DCM_EV($bb) . 
                                &ROM_SIGNATURE_SECTION_EV($bb, "ROM", "MAUI");},
             'MT6255' => sub { &ROM_type_1($bb, $multibin, $security) .
                                &EXTSRAM_type_8($bb) .
                                &INTSRAM_type1($bb) . 
                                &ROM_SIGNATURE_SECTION_EV($bb, "ROM", "MAUI");},
             'MT6922' => sub { &ROM_type_1($bb, $multibin, $security) .
                                &EXTSRAM_type_8($bb) .
                                &INTSRAM_type1($bb) . 
                                &ROM_SIGNATURE_SECTION_EV($bb, "ROM", "MAUI");},
       );
       #map {print $_, "\n";} keys %BBtbl;
    &sysUtil::sysgen_die("tools/scatGenLib.pl: Unsupported Feature Combination NFB on $bb!", __FILE__, __LINE__) if not exists $BBtbl{$bb}; 
    my $func = $BBtbl{$bb};
    return &$func;
}

#****************************************************************************
# subroutine:  NFB Layout :: SECONDARY ROM :: Exec View
# input:       BB chip, flash size[value], ram size [value]
#****************************************************************************
sub layout1_secondaryrom_ev
{
    my ($bb, $ram_size_value, $secondary_rompool, $secondary_rampool, $cached_dummy_end_addr, $multibin, $security, $nfb_or_emb) = @_;

    my $ram_base_above_arm9 = "+0x1000";
    
    my %BBtbl =
       (
             'MT6235'  => sub { &ROM_type_2($bb, "+0x0", $security, $nfb_or_emb) .
                                &EXTSRAM_type_9($bb, $ram_base_above_arm9, $ram_size_value, $cached_dummy_end_addr, $multibin, $security) .
                                &INTSRAM_BLINUSED_EV($bb, "0x40000000", "0x00004000") .
                                &INTSRAM_PAGETABLE_EV($bb, "0x40004000", "0x0000B000") .
                                &INTSRAM_FOTATEMP_EV($bb, "0x4000F000") .
                                &INTSRAM_MED_EV($bb, "0x40000000", 1, "0x00010000") .
                                &FLMM_EV($bb); },
             'MT6235B' => sub { &ROM_type_2($bb, "+0x0", $security, $nfb_or_emb) .
                                &EXTSRAM_type_9($bb, $ram_base_above_arm9, $ram_size_value, $cached_dummy_end_addr, $multibin, $security) .
                                &INTSRAM_BLINUSED_EV($bb, "0x40000000", "0x00004000") .
                                &INTSRAM_PAGETABLE_EV($bb, "0x40004000", "0x0000B000") .
                                &INTSRAM_FOTATEMP_EV($bb, "0x4000F000") .
                                &INTSRAM_MED_EV($bb, "0x40000000", 1, "0x00010000") .
                                &FLMM_EV($bb); },
             'MT6236'  => sub { &ROM_type_2($bb, "+0x0", $security, $nfb_or_emb) .
                                &EXTSRAM_type_9($bb, $ram_base_above_arm9, $ram_size_value, $cached_dummy_end_addr, $multibin, $security) .
                                &INTSRAM_BLINUSED_EV($bb, "0x40000000", "0x00004000") .
                                &INTSRAM_PAGETABLE_EV($bb, "0x40004000", "0x0000B000") .
                                &INTSRAM_FOTATEMP_EV($bb, "0x40017000") .
                                &INTSRAM_MED_EV($bb, "0x40000000", 1, "0x00018000") .
                                &FLMM_EV($bb); },
             'MT6236B' => sub { &ROM_type_2($bb, "+0x0", $security, $nfb_or_emb) .
                                &EXTSRAM_type_9($bb, $ram_base_above_arm9, $ram_size_value, $cached_dummy_end_addr, $multibin, $security) .
                                &INTSRAM_BLINUSED_EV($bb, "0x40000000", "0x00004000") .
                                &INTSRAM_PAGETABLE_EV($bb, "0x40004000", "0x0000B000") .
                                &INTSRAM_FOTATEMP_EV($bb, "0x40017000") .
                                &INTSRAM_MED_EV($bb, "0x40000000", 1, "0x00018000") .
                                &FLMM_EV($bb); },
             'MT6921'  => sub { &ROM_type_2($bb, "+0x0", $security, $nfb_or_emb) .
                                &EXTSRAM_type_9($bb, $ram_base_above_arm9, $ram_size_value, $cached_dummy_end_addr, $multibin, $security) .
                                &INTSRAM_BLINUSED_EV($bb, "0x40000000", "0x00004000") .
                                &INTSRAM_PAGETABLE_EV($bb, "0x40004000", "0x0000B000") .
                                &INTSRAM_FOTATEMP_EV($bb, "0x40017000") .
                                &INTSRAM_MED_EV($bb, "0x40000000", 1, "0x00018000") .
                                &FLMM_EV($bb); },
             'MT6268'  => sub { &ROM_type_5($bb, "+0x0", $security, $nfb_or_emb) .
                                &EXTSRAM_type_9($bb, $ram_base_above_arm9, $ram_size_value, $cached_dummy_end_addr, $multibin, $security) .
                                &INTSRAM_BLINUSED_EV($bb, "0x92000000", "0x00004000") .
                                &INTSRAM_PAGETABLE_EV($bb, "0x92004000", "0x0001B000") .
                                &INTSRAM_FOTATEMP_EV($bb, "0x9201F000") .
                                &INTSRAM_MED_EV($bb, "0x92000000", 1, "0x00020000") .
                                &FLMM_EV($bb); },
             'MT6276'  => sub { &ROM_type_5($bb, "+0x0", $security, $nfb_or_emb) .
                                &EXTSRAM_type_9($bb, $ram_base_above_arm9, $ram_size_value, $cached_dummy_end_addr, $multibin, $security) .
                                &INTSRAM_BLINUSED_EV($bb, "0xC8000000", "0x00004000") .
                                &INTSRAM_PAGETABLE_EV($bb, "0xC8004000", "0x0000F000") .
                                &INTSRAM_FOTATEMP_EV($bb, "0xC8013000") .
                                &INTSRAM_MED_EV($bb, "0xC8000000", 1, "0x00014000") .
                                &FLMM_EV($bb) .
                                &ROM_SIGNATURE_SECTION_EV($bb, "SECONDARY_ROM", "S_MAUI") ;},
             'MT6256'  => sub { &ROM_type_5($bb, "+0x0", $security, $nfb_or_emb) .
                                &EXTSRAM_type_9($bb, $ram_base_above_arm9, $ram_size_value, $cached_dummy_end_addr, $multibin, $security) .
                                &INTSRAM_BLINUSED_EV($bb, "0x91000000", "0x00004000") .
                                &INTSRAM_PAGETABLE_EV($bb, "0x91004000", "0x0000B000") .
                                &INTSRAM_FOTATEMP_EV($bb, "0x9100F000") .
                                &INTSRAM_MED_EV($bb, "0x91000000", 1, "0x00010000") .
                                &FLMM_EV($bb) .
                                &ROM_SIGNATURE_SECTION_EV($bb, "SECONDARY_ROM", "S_MAUI") ;},
             'MT6255'  => sub { &ROM_type_5($bb, "+0x0", $security, $nfb_or_emb) .
                                &EXTSRAM_type_9($bb, $ram_base_above_arm9, $ram_size_value, $cached_dummy_end_addr, $multibin, $security) .
                                &INTSRAM_BLINUSED_EV($bb, "0x40000000", "0x00004000") .
                                &INTSRAM_FOTATEMP_EV($bb, "0x40006000") .
                                &INTSRAM_MED_EV($bb, "0x40000000", 1, "0x00007000") .
                                &FLMM_EV($bb) .
                                &ROM_SIGNATURE_SECTION_EV($bb, "SECONDARY_ROM", "S_MAUI") ;},
             'MT6922'  => sub { &ROM_type_5($bb, "+0x0", $security, $nfb_or_emb) .
                                &EXTSRAM_type_9($bb, $ram_base_above_arm9, $ram_size_value, $cached_dummy_end_addr, $multibin, $security) .
                                &INTSRAM_BLINUSED_EV($bb, "0x40000000", "0x00004000") .
                                &INTSRAM_FOTATEMP_EV($bb, "0x40006000") .
                                &INTSRAM_MED_EV($bb, "0x40000000", 1, "0x00007000") .
                                &FLMM_EV($bb) .
                                &ROM_SIGNATURE_SECTION_EV($bb, "SECONDARY_ROM", "S_MAUI") ;},   
       );
       #map {print $_, "\n";} keys %BBtbl;
    &sysUtil::sysgen_die("tools/scatGenLib.pl: Unsupported Feature Combination NFB on $bb!", __FILE__, __LINE__) if not exists $BBtbl{$bb}; 
    my $func = $BBtbl{$bb};
    return &$func;
}

#****************************************************************************
# subroutine:  NFB Layout :: DEMAND_PAGING_ROM0 :: Exec View
# input:       BB chip, ram size [value]
#****************************************************************************
sub layout1_demandpaging_ev
{
    my ($bb, $ram_size_value, $extsram_shrinking_by_dp, $nfb_or_emb, $dp_lv_size_string) = @_;
    return undef if($nfb_or_emb ne 'ONDEMAND');
    
    my $mba = &$feature_query_function_ptr('multiple_binary_files');
    
    ###
    my $ft_temp = <<"__TEMPLATE";
; FT
         *ft.a (+RO-CODE)
         *ft.a (+RO-DATA)
__TEMPLATE

    my $fmgr_temp = <<"__TEMPLATE";
; FMGR
         filemanagersrc.obj (+RO-CODE, +RO-DATA)
         filemgr.obj (+RO-CODE, +RO-DATA)
         filemgrcore.obj (+RO-CODE, +RO-DATA)
         filemgrui.obj (+RO-CODE, +RO-DATA)
__TEMPLATE

    my $eng_mode_temp = <<"__TEMPLATE";
; Engineering mode
         engineermodedevice.obj (+RO-CODE, +RO-DATA)
         engineermodebt.obj (+RO-CODE, +RO-DATA)
         engineermodeminigps.obj (+RO-CODE, +RO-DATA)
         engineermodeprofiling.obj (+RO-CODE, +RO-DATA)
         engineermodesocketapp.obj (+RO-CODE, +RO-DATA)
         engineermodesocketdemoapp.obj (+RO-CODE, +RO-DATA)
         engineermodeiperf.obj (+RO-CODE, +RO-DATA)
         engineermodemain.obj (+RO-CODE, +RO-DATA)
         engineermodedm.obj (+RO-CODE, +RO-DATA)
         engineermodestorage.obj (+RO-CODE, +RO-DATA)
         engineermodedebuginfo.obj (+RO-CODE, +RO-DATA)
         engineermodemultimedia.obj (+RO-CODE, +RO-DATA)
         engineermoderftest.obj (+RO-CODE, +RO-DATA)
         engineermodevoip.obj (+RO-CODE, +RO-DATA)
         engineermodegprs.obj (+RO-CODE, +RO-DATA)
         engineermodeaudio.obj (+RO-CODE, +RO-DATA)
         engineermodemmiframework.obj (+RO-CODE, +RO-DATA)
         engineermodemisc.obj (+RO-CODE, +RO-DATA)
         engineermodepmic.obj (+RO-CODE, +RO-DATA)
         engineermodepcsnetwork.obj (+RO-CODE, +RO-DATA)
__TEMPLATE

    my $mmi_game_temp = <<"__TEMPLATE";
; MMI game
         F1Race.obj (+RO-CODE, +RO-DATA)
         TOH.obj (+RO-CODE, +RO-DATA)
         Riches.obj (+RO-CODE, +RO-DATA)
         ColorBalls.obj (+RO-CODE, +RO-DATA)
         Snake.obj (+RO-CODE, +RO-DATA)
         Smash.obj (+RO-CODE, +RO-DATA)
         Doll.obj (+RO-CODE, +RO-DATA)
         Majung.obj (+RO-CODE, +RO-DATA)
         Puzzle.obj (+RO-CODE, +RO-DATA)
         Ufo.obj (+RO-CODE, +RO-DATA)
         Magicsushi.obj (+RO-CODE, +RO-DATA)
         Vsmj.obj (+RO-CODE, +RO-DATA)
__TEMPLATE

    my $extra_temp = <<"__TEMPLATE";
; EXTRA
         bmi.obj (+RO-CODE, +RO-DATA)
         Calculator.obj (+RO-CODE, +RO-DATA)
         Calorie.obj (+RO-CODE, +RO-DATA)
         currencyconvertor.obj (+RO-CODE, +RO-DATA)
         CurrencyConvertorE.obj (+RO-CODE, +RO-DATA)
         Extra.obj (+RO-CODE, +RO-DATA)
         healthmenstural.obj (+RO-CODE, +RO-DATA)
         Shortcuts.obj (+RO-CODE, +RO-DATA)
         StopwatchMultiPurpose.obj (+RO-CODE, +RO-DATA)
         StopwatchTypical.obj (+RO-CODE, +RO-DATA)
         unitconvertor.obj (+RO-CODE, +RO-DATA)
__TEMPLATE

    my $ebook_temp = <<"__TEMPLATE";
; EBOOK
         EbookFramework.obj (+RO-CODE, +RO-DATA)
         EbookSrc.obj (+RO-CODE, +RO-DATA)
__TEMPLATE

    my $service_temp = <<"__TEMPLATE";
; SERVICE
         PlstSrvsql.obj (+RO-CODE, +RO-DATA)  ;mmi_service.lib
         PlstSrvpls.obj (+RO-CODE, +RO-DATA)  ;mmi_service.lib
__TEMPLATE

    my $mplayer_temp = <<"__TEMPLATE";
; MEDIA PLAYER
         MediaPlayerPlaylistUI.obj (+RO-CODE, +RO-DATA)  ;media_app.lib
         MediaPlayerFTEMainScreen.obj (+RO-CODE, +RO-DATA)  ;media_app.lib
__TEMPLATE

    my $vt_temp = <<"__TEMPLATE";
; VT MEMORY
         *3g324m.a (+RO-CODE, +RO-DATA)
__TEMPLATE

    my $mmi_temp = <<"__TEMPLATE";
; MMI
         *cosmos_app.a (+RO-CODE, +RO-DATA)
         *cosmos_media_app.a (+RO-CODE, +RO-DATA)
         *cosmos_conn_app.a (+RO-CODE, +RO-DATA)
         *cosmos_inet_app.a (+RO-CODE, +RO-DATA)
         *mmi_service.a (+RO-CODE, +RO-DATA)
         *mmi_core.a (+RO-CODE, +RO-DATA)
         *syncml.a (+RO-CODE, +RO-DATA)
         *email.a (+RO-CODE, +RO-DATA)
         *emlst.a (+RO-CODE, +RO-DATA)
         *ems.a (+RO-CODE, +RO-DATA)
         *applib_inet.a (+RO-CODE, +RO-DATA)
         *vcard.a (+RO-CODE, +RO-DATA)
         custom_config_account.obj (+RO-CODE, +RO-DATA)
         custom_events_notify.obj (+RO-CODE, +RO-DATA)
         custom_em.obj (+RO-CODE, +RO-DATA)
         custom_rec_config.obj (+RO-CODE, +RO-DATA)
         custom_ecc.obj (+RO-CODE, +RO-DATA)
; Pluto MMI
         *mmi_app.a (+RO-CODE, +RO-DATA)
         *media_app.a (+RO-CODE, +RO-DATA)
         *inet_app.a (+RO-CODE, +RO-DATA)
         *conn_app.a (+RO-CODE, +RO-DATA)
; Venus MMI
         *venusmmi.a (+RO-CODE, +RO-DATA)
; IG
		 *intergrafx_sw.a       (+RO-CODE, +RO-DATA)
		 *intergrafx_hw.a       (+RO-CODE, +RO-DATA)	
         *IGV3.a                  (+RO-CODE, +RO-DATA)
         *IG_*.a                (+RO-CODE, +RO-DATA)
         IG_DA_*.obj              (+RO-CODE, +RO-DATA)
         IG_FT_*.obj              (+RO-CODE, +RO-DATA)
__TEMPLATE

    my $obigo03c_temp = <<"__TEMPLATE";
         *obigo03cadp.a (+RO-CODE, +RO-DATA)
         *obigo03capp.a (+RO-CODE, +RO-DATA)
         *obigo03clib.a (+RO-CODE, +RO-DATA)
__TEMPLATE

    my $browser_other_temp = <<"__TEMPLATE";
    	 *obigo03cstkadp.a (+RO-CODE, +RO-DATA)
    	 *obigo03cstklib.a (+RO-CODE, +RO-DATA)
    	 *obigo03cfwadp.a (+RO-CODE, +RO-DATA)
    	 *obigo03cfwlib.a (+RO-CODE, +RO-DATA)
    	 *obigo03cmmsadp.a (+RO-CODE, +RO-DATA)
    	 *obigo03cmmslib.a (+RO-CODE, +RO-DATA)
    	 *obigo03cpushadp.a (+RO-CODE, +RO-DATA)
    	 *obigo03cpushlib.a (+RO-CODE, +RO-DATA)
    	 *opera_rvct.a (+RO-CODE, +RO-DATA)
    	 *opera10opdev.a (+RO-CODE, +RO-DATA)
    	 *opera10adp.a (+RO-CODE, +RO-DATA)
     	 *sb51_rvct.a (+RO-CODE, +RO-DATA)
     	 *sslplus5_rvct.a (+RO-CODE, +RO-DATA)
     	 *insignia_dm.a (+RO-CODE, +RO-DATA)
     	 *insignia_dmsdk.a (+RO-CODE, +RO-DATA)
__TEMPLATE

    my $mmi_image_temp = <<"__TEMPLATE";
; mmiresource - Image
         CustImgMap.obj (+RO-DATA)
         CustImgMapExt.obj (+RO-DATA)

; must use software image decoder
         CustImgRes.obj (+RO-DATA)
         CustImgDataRes_*.obj (+RO-DATA)
         CustImgResExt.obj (+RO-DATA)
__TEMPLATE

    my $mmi_image_temp_mba = <<"__TEMPLATE";
; mmiresource - Image
         CustImgMap.obj (+RO-DATA)
         CustImgMapExt.obj (+RO-DATA)

; must use software image decoder
         CustImgRes.obj (+RO-DATA)
         CustImgDataRes_*.obj (+RO-DATA)
__TEMPLATE

    my $mmi_audio_temp = <<"__TEMPLATE";
; mmiresource - Audio
         CustAdoMap.obj (+RO-DATA)
         CustAdoMapExt.obj (+RO-DATA)
         CustAdoRes.obj (+RO-DATA)
         CustAdoDataRes_*.obj (+RO-DATA)
         CustAdoResExt.obj (+RO-DATA)
__TEMPLATE

    my $mmi_audio_temp_mba = <<"__TEMPLATE";
; mmiresource - Audio
         CustAdoMap.obj (+RO-DATA)
         CustAdoMapExt.obj (+RO-DATA)
         CustAdoRes.obj (+RO-DATA)
         CustAdoDataRes_*.obj (+RO-DATA)
__TEMPLATE

    my $mmi_string_temp = <<"__TEMPLATE";
; mmiresource - String
         CustStrMap.obj (+RO-DATA)
         CustStrRes.obj (+RO-DATA)
         CustStrDataRes_*.obj (+RO-DATA)
__TEMPLATE

    my $mmi_menu_temp = <<"__TEMPLATE";
; mmiresource - Menu
         CustMenuRes.obj (+RO-DATA)
         CustMenuDataRes_*.obj (+RO-DATA)
__TEMPLATE

    my $mmi_font_temp = <<"__TEMPLATE";
; mmiresource - Font
; must use software font engine
         FontRes.obj (+RO-DATA)
	     vf_*.obj (+RO-CODE, +RO-DATA)
__TEMPLATE

    my $mmi_font_slim_temp = <<"__TEMPLATE";
; mmiresource - Font
; must use software font engine
         FontRes.obj (+RO-DATA)
         vf_56.obj (+RO-CODE, +RO-DATA)
         vf_57.obj (+RO-CODE, +RO-DATA)
         vf_58.obj (+RO-CODE, +RO-DATA)
         vf_59.obj (+RO-CODE, +RO-DATA)
         vf_60.obj (+RO-CODE, +RO-DATA)
         *vectorfont_freetype.a (+RO-CODE, +RO-DATA)
__TEMPLATE

    my $mmi_font_slim_temp_mba = <<"__TEMPLATE";
; mmiresource - Font
; must use software font engine
         *vectorfont_freetype.a (+RO-CODE, +RO-DATA)
__TEMPLATE

    my $mmi_theme_temp = <<"__TEMPLATE";
; mmiresource - Theme
         ThemeRes.obj (+RO-DATA)
__TEMPLATE

    my $mmi_theme_slim_temp = <<"__TEMPLATE";
; mmiresource - Theme
         ThemeRes.obj (+RO-DATA)
         ReadThemeRes.obj (+RO-CODE, +RO-DATA)
__TEMPLATE

    my $mmi_theme_slim_temp_mba = <<"__TEMPLATE";
; mmiresource - Theme
         ReadThemeRes.obj (+RO-CODE, +RO-DATA)
__TEMPLATE

    my $mmi_misc_temp = <<"__TEMPLATE";
; mmiresource - Misc.
         IMERes.obj (+RO-CODE, +RO-DATA)  ;mmiresource.lib
__TEMPLATE

    my $mmi_misc_slim_temp = <<"__TEMPLATE";
; mmiresource - Misc.
         IMERes.obj (+RO-CODE, +RO-DATA)  ;mmiresource.lib
         resource_world_clock-city.obj (+RO-CODE, +RO-DATA)
         mmi_rp_callback_mgr_table.obj (+RO-CODE, +RO-DATA)
         mmi_rp_file_type_table.obj (+RO-CODE, +RO-DATA)
         resource_camcorder_skins.obj (+RO-CODE, +RO-DATA)
         CustCoordinates.obj (+RO-CODE, +RO-DATA)
         readres.obj (+RO-CODE, +RO-DATA)
         CustBinaryRes.obj (+RO-CODE, +RO-DATA)
         CustBinaryDataRes_*.obj (+RO-CODE, +RO-DATA)
__TEMPLATE

    my $mmi_misc_slim_temp_mba = <<"__TEMPLATE";
; mmiresource - Misc.
         resource_world_clock-city.obj (+RO-CODE, +RO-DATA)
         mmi_rp_callback_mgr_table.obj (+RO-CODE, +RO-DATA)
         mmi_rp_file_type_table.obj (+RO-CODE, +RO-DATA)
         resource_camcorder_skins.obj (+RO-CODE, +RO-DATA)
         CustCoordinates.obj (+RO-CODE, +RO-DATA)
         readres.obj (+RO-CODE, +RO-DATA)
         CustBinaryRes.obj (+RO-CODE, +RO-DATA)
         CustBinaryDataRes_*.obj (+RO-CODE, +RO-DATA)
__TEMPLATE

    my $mmi_t9_temp = <<"__TEMPLATE";
; T9
         t9relChinese_rvct.o (+RO-CODE, +RO-DATA)  ;t9.lib
__TEMPLATE

    my $mmi_hangwang_temp = <<"__TEMPLATE";
; HangWang
         *hanwang.a (+RO-CODE, +RO-DATA)
; PenPower
         *penpower.a (+RO-CODE, +RO-DATA)
__TEMPLATE

    my $mmi_cstar_temp = <<"__TEMPLATE";
; CStar
         *cstar.a (+RO-CODE, +RO-DATA)
         *libkmxime_arm9_rvct.a (+RO-CODE, +RO-DATA)
         *kmxime_arm9_rvct_demo.a (+RO-CODE, +RO-DATA)
__TEMPLATE

    my $mmi_charsettbl_temp = <<"__TEMPLATE";
; Charset Table
         charsettable.obj (+RO-CODE, +RO-DATA)
__TEMPLATE

    my $j2me_temp = <<"__TEMPLATE";
; J2ME
         *jal.a (+RO-CODE)
         *jal.a (+RO-DATA)
         *nemo_adp.a (+RO-CODE)
         *nemo_adp.a (+RO-DATA)
__TEMPLATE

    my $j2me_kvm_temp = <<"__TEMPLATE";
; J2ME
         *jal.a (+RO-CODE)
         *jal.a (+RO-DATA)
;         *nemo_adp.a (+RO-CODE)
         *nemo_adp.a (+RO-DATA)
__TEMPLATE

    my $j2me_extsram_shrinking_temp = <<"__TEMPLATE";
         romclass.obj (+RO-CODE)
         romclass.obj (+RO-DATA)
         j2me_custom_mids.obj (+RO-CODE)
         j2me_custom_mids.obj (+RO-DATA)
         *j2me_nemo.a (+RO-CODE)
         *j2me_nemo.a (+RO-DATA)
         *j2me_nemo_cldc.a (+RO-CODE)
         *j2me_nemo_cldc.a (+RO-DATA)
__TEMPLATE

    my $j2me_slim_temp = <<"__TEMPLATE";
         *nemo_adp.a (+RO-CODE, +RO-DATA)
         *j2me_nemo_fdlibm.a (+RO-CODE, +RO-DATA)
__TEMPLATE

    my $gadget_temp = <<"__TEMPLATE";
; GADGET
         *gadget_lib.a (+RO-CODE, +RO-DATA)
         *gadget_adp.a (+RO-CODE, +RO-DATA)
         custom_gadget_config.obj (+RO-CODE, +RO-DATA)
__TEMPLATE

    my $vre_temp = <<"__TEMPLATE";
; mre
         *mre_engine.a (+RO-CODE, +RO-DATA)
         *mre_custom.a (+RO-CODE, +RO-DATA)
__TEMPLATE

    my $mmi_framework_temp = <<"__TEMPLATE";
; MMI_FRAMEWORK
         gui.obj                         (+RO-CODE, +RO-DATA)   
         gui_asyncdynamic_menus.obj      (+RO-CODE, +RO-DATA)   
         gui_buttons.obj                 (+RO-CODE, +RO-DATA)   
         gui_bytestream.obj              (+RO-CODE, +RO-DATA)   
         gui_calendar.obj                (+RO-CODE, +RO-DATA)   
         gui_clock.obj                   (+RO-CODE, +RO-DATA)   
         gui_color_slider.obj            (+RO-CODE, +RO-DATA)   
         gui_custom_menus.obj            (+RO-CODE, +RO-DATA)   
         gui_dynamic_menus.obj           (+RO-CODE, +RO-DATA)   
         gui_ems.obj                     (+RO-CODE, +RO-DATA)   
         gui_effect_oem.obj              (+RO-CODE, +RO-DATA)
         gui_fixed_menuitems.obj         (+RO-CODE, +RO-DATA)   
         gui_fixed_menus.obj             (+RO-CODE, +RO-DATA)   
         gui_font_size.obj               (+RO-CODE, +RO-DATA)   
         gui_font_oem.obj                (+RO-CODE, +RO-DATA)   
         gui_hardware_dependent.obj      (+RO-CODE, +RO-DATA)   
         gui_image.obj                   (+RO-CODE, +RO-DATA)
         gui_inputs.obj                  (+RO-CODE, +RO-DATA)   
         gui_inputs_cache.obj            (+RO-CODE, +RO-DATA)   
         gui_wcss_inputs.obj             (+RO-CODE, +RO-DATA)   
         gui_multi_line_inputs.obj       (+RO-CODE, +RO-DATA)   
         gui_single_line_inputs.obj      (+RO-CODE, +RO-DATA)   
         gui_ems_inputs.obj              (+RO-CODE, +RO-DATA)   
         gui_menu_shortcut.obj           (+RO-CODE, +RO-DATA)   
         gui_panel.obj                   (+RO-CODE, +RO-DATA)   
         gui_scrollbars.obj              (+RO-CODE, +RO-DATA)   
         gui_status_icon_bar_oem.obj     (+RO-CODE, +RO-DATA)
         gui_scrollbars_oem.obj          (+RO-CODE, +RO-DATA)   
         gui_spectrum.obj                (+RO-CODE, +RO-DATA)   
         gui_tab_bars.obj                (+RO-CODE, +RO-DATA)   
         gui_tab_bars_oem.obj            (+RO-CODE, +RO-DATA)   
         gui_text_label.obj              (+RO-CODE, +RO-DATA)   
         gui_themes.obj                  (+RO-CODE, +RO-DATA)   
         gui_title.obj                   (+RO-CODE, +RO-DATA)   
         gui_title_oem.obj               (+RO-CODE, +RO-DATA)   
         gui_virtual_keyboard.obj        (+RO-CODE, +RO-DATA)   
         gui_icon_bar.obj                (+RO-CODE, +RO-DATA)   
         gui_windows.obj                 (+RO-CODE, +RO-DATA)   
         gui_video.obj                   (+RO-CODE, +RO-DATA)   
         gui_menu_oem.obj                (+RO-CODE, +RO-DATA)   
         gui_main_menu_oem.obj           (+RO-CODE, +RO-DATA)   
         wgui_tree.obj                   (+RO-CODE, +RO-DATA)   
         wgui_asyncdynamic_menuitems.obj (+RO-CODE, +RO-DATA)   
         wgui_asyncdynamic_menus.obj     (+RO-CODE, +RO-DATA)   
         wgui_calendar.obj               (+RO-CODE, +RO-DATA)   
         wgui_categories.obj             (+RO-CODE, +RO-DATA)   
         wgui_categories_cm.obj          (+RO-CODE, +RO-DATA)   
         wgui_categories_fmgr.obj        (+RO-CODE, +RO-DATA)   
         wgui_categories_idlescreen.obj  (+RO-CODE, +RO-DATA)   
         wgui_categories_idlescreen_op.obj      (+RO-CODE, +RO-DATA)  
         wgui_categories_inputs.obj      (+RO-CODE, +RO-DATA)   
         wgui_categories_list.obj        (+RO-CODE, +RO-DATA)   
         wgui_categories_mms_viewer.obj  (+RO-CODE, +RO-DATA)   
         wgui_categories_multimedia.obj  (+RO-CODE, +RO-DATA)   
         wgui_categories_notification.obj      (+RO-CODE, +RO-DATA) 
         wgui_categories_popup.obj       (+RO-CODE, +RO-DATA)   
         wgui_categories_stopwatch.obj   (+RO-CODE, +RO-DATA)   
         wgui_categories_search.obj      (+RO-CODE, +RO-DATA)   
         wgui_categories_sublcd.obj      (+RO-CODE, +RO-DATA)   
         wgui_categories_text_viewer.obj      (+RO-CODE, +RO-DATA) 
         wgui_categories_util.obj        (+RO-CODE, +RO-DATA)   
         wgui_hint_oem.obj               (+RO-CODE, +RO-DATA)   
         wgui_clock.obj                  (+RO-CODE, +RO-DATA)   
         wgui_datetime.obj               (+RO-CODE, +RO-DATA)   
         wgui_draw_manager.obj           (+RO-CODE, +RO-DATA)   
         wgui_dynamic_menuitems.obj      (+RO-CODE, +RO-DATA)   
         wgui_dynamic_menus.obj          (+RO-CODE, +RO-DATA)   
         wgui_ems.obj                    (+RO-CODE, +RO-DATA)   
         wgui_fixed_menuitems.obj        (+RO-CODE, +RO-DATA)   
         wgui_fixed_menus.obj            (+RO-CODE, +RO-DATA)   
         wgui_inline_edit.obj            (+RO-CODE, +RO-DATA)   
         wgui_progress_bar.obj           (+RO-CODE, +RO-DATA)   
         gui_progress_bar.obj            (+RO-CODE, +RO-DATA)   
         wgui_inputs.obj                 (+RO-CODE, +RO-DATA)   
         wgui_inputs_multiline.obj       (+RO-CODE, +RO-DATA)   
         wgui_inputs_singleline.obj      (+RO-CODE, +RO-DATA)   
         wgui_inputs_dialer.obj          (+RO-CODE, +RO-DATA)   
         wgui_panel.obj                  (+RO-CODE, +RO-DATA)   
         wgui_softkeys.obj               (+RO-CODE, +RO-DATA)   
         wgui_softkey_oem.obj            (+RO-CODE, +RO-DATA)   
         gui_slide_bar.obj               (+RO-CODE, +RO-DATA)   
         wgui_slide_bar.obj              (+RO-CODE, +RO-DATA)   
         wgui_status_icon_bar.obj        (+RO-CODE, +RO-DATA)
         wgui_tab_bars.obj               (+RO-CODE, +RO-DATA)   
         wgui_text_label.obj             (+RO-CODE, +RO-DATA)   
         wgui_title.obj                  (+RO-CODE, +RO-DATA)   
         wgui_touch_screen.obj           (+RO-CODE, +RO-DATA)   
         wgui_virtual_keyboard.obj       (+RO-CODE, +RO-DATA)   
         wgui_icon_bar.obj               (+RO-CODE, +RO-DATA)   
         wingui.obj                      (+RO-CODE, +RO-DATA)   
         wgui_video.obj                  (+RO-CODE, +RO-DATA)   
         gui_horizontal_selector.obj     (+RO-CODE, +RO-DATA)   
         gui_touch_feedback.obj          (+RO-CODE, +RO-DATA)   
         gui_touch_feedback_oem.obj      (+RO-CODE, +RO-DATA) 

         commonscreens.obj               (+RO-CODE, +RO-DATA)
         InlineCui.obj                   (+RO-CODE, +RO-DATA)
         Imc.obj                         (+RO-CODE, +RO-DATA)
         Imc_key.obj                     (+RO-CODE, +RO-DATA)
         Imc_pen.obj                     (+RO-CODE, +RO-DATA)
         Imm.obj                         (+RO-CODE, +RO-DATA)
         Imui.obj                        (+RO-CODE, +RO-DATA)
         mmiapi_main.obj                 (+RO-CODE, +RO-DATA)   
         mmiapi_sms.obj                  (+RO-CODE, +RO-DATA)   
         mmiapi_sms_msg.obj              (+RO-CODE, +RO-DATA)   
         mmiapi_wap.obj                  (+RO-CODE, +RO-DATA)   
         ctk.obj                         (+RO-CODE, +RO-DATA)   
         wap_stub.obj                    (+RO-CODE, +RO-DATA)   
         mtkmultitap.obj                 (+RO-CODE, +RO-DATA)   
         SoftwareTracerSettingMode.obj   (+RO-CODE, +RO-DATA)   
         SoftwareTracerAnalyzingMode.obj (+RO-CODE, +RO-DATA)   
         SoftwareTracerMoDIS.obj         (+RO-CODE, +RO-DATA)   
         SoftwareTracerCommonFunc.obj    (+RO-CODE, +RO-DATA)   
         SoftwareTracer.obj              (+RO-CODE, +RO-DATA)   
         FSEditorCui.obj                 (+RO-CODE, +RO-DATA)   
         MenuCui.obj                     (+RO-CODE, +RO-DATA)   
         shutdownapp.obj                 (+RO-CODE, +RO-DATA)   
         simdetection.obj                (+RO-CODE, +RO-DATA)   
         smlmenu.obj                     (+RO-CODE, +RO-DATA)   
         Gsm7BitNationalLang.obj         (+RO-CODE, +RO-DATA)   
         Procedure.obj                   (+RO-CODE, +RO-DATA)   
         mte.obj                         (+RO-CODE, +RO-DATA)   
         mslt.obj                        (+RO-CODE, +RO-DATA)   
         bengali.obj                     (+RO-CODE, +RO-DATA)   
         assamese.obj                    (+RO-CODE, +RO-DATA)   
         hindi.obj                       (+RO-CODE, +RO-DATA)   
         malayalam.obj                   (+RO-CODE, +RO-DATA)   
         oriya.obj                       (+RO-CODE, +RO-DATA)   
         kannada.obj                     (+RO-CODE, +RO-DATA)   
         gujarati.obj                    (+RO-CODE, +RO-DATA)   
         indicruleengine.obj             (+RO-CODE, +RO-DATA)   
         indicruleenginecommon.obj       (+RO-CODE, +RO-DATA)   
         marathi.obj                     (+RO-CODE, +RO-DATA)   
         punjabi.obj                     (+RO-CODE, +RO-DATA)   
         tamil.obj                       (+RO-CODE, +RO-DATA)   
         telugu.obj                      (+RO-CODE, +RO-DATA)   
         ascii.obj                       (+RO-CODE, +RO-DATA)   
         bootupapp.obj                   (+RO-CODE, +RO-DATA)   
         bootupmenuctrl.obj              (+RO-CODE, +RO-DATA)   
         checkdisk.obj                   (+RO-CODE, +RO-DATA)   
         AlertScreen.obj                 (+RO-CODE, +RO-DATA)   
         bidi.obj                        (+RO-CODE, +RO-DATA)   
         bidi_l_rules.obj                (+RO-CODE, +RO-DATA)   
         bidicharmap.obj                 (+RO-CODE, +RO-DATA)   
         bidipararules.obj               (+RO-CODE, +RO-DATA)   
         bidiprocessdatatypes.obj        (+RO-CODE, +RO-DATA)   
         debuginit.obj                   (+RO-CODE, +RO-DATA)   
         mmi_frm_utility.obj             (+RO-CODE, +RO-DATA)   
         mmi_frm_gestures.obj            (+RO-CODE, +RO-DATA)   
         mmi_frm_gestures_cfg.obj        (+RO-CODE, +RO-DATA)   
         AT_utility.obj                  (+RO-CODE, +RO-DATA)   
         themeconverterui.obj            (+RO-CODE, +RO-DATA)   
         themeconverterxml.obj           (+RO-CODE, +RO-DATA)   
         thememanager.obj                (+RO-CODE, +RO-DATA)   
         gsm7bitdefaultalphabet.obj      (+RO-CODE, +RO-DATA)   
         mempoolcontainer.obj            (+RO-CODE, +RO-DATA)   
         networkfunctions.obj            (+RO-CODE, +RO-DATA)  

         nvram_common_config.obj (+RO-CODE, +RO-DATA)
         *applib_sqlite3.a (+RO-CODE, +RO-DATA)
__TEMPLATE

    my $dpv2_ROCODE = ".ANY (+RO-CODE)";
    my $dpv2_RODATA = ".ANY (+RO-DATA)";

    my $dpv2_temp = <<"__TEMPLATE";
         romclass.obj (+RO-CODE, +RO-DATA)
         custom_gadget_config.obj (+RO-CODE, +RO-DATA)
         nvram_common_config.obj (+RO-CODE, +RO-DATA)
         j2me_custom_mids.obj (+RO-CODE, +RO-DATA)
         *mre_custom.a (+RO-CODE, +RO-DATA)
__TEMPLATE

    # --- --- --- 
    my $demand_paging_rom0_temp = $ft_temp . $mmi_temp;
    if ($bb eq 'MT6276')
    {
        $demand_paging_rom0_temp .= $vt_temp;
    }
    my @demand_paging_rom0_libs = split("\n", $demand_paging_rom0_temp);
    map { s/^\s+//; } @demand_paging_rom0_libs;
    
    # --- --- ---
    my $demand_paging_rom1_temp = $obigo03c_temp . $browser_other_temp;
    my @demand_paging_rom1_libs = split("\n", $demand_paging_rom1_temp);
    map { s/^\s+//; } @demand_paging_rom1_libs;

    # --- --- ---
    my @mmi_image_libs = split("\n", $mmi_image_temp);
    map { s/^\s+//; } @mmi_image_libs;
    my @mmi_image_libs_mba = split("\n", $mmi_image_temp_mba);
    map { s/^\s+//; } @mmi_image_libs_mba;
    
    # --- --- ---
    my $demand_paging_rom3_temp;
    if ($mba eq 'TRUE')
    {
    	$demand_paging_rom3_temp = $mmi_audio_temp_mba . $mmi_font_slim_temp_mba . $mmi_theme_slim_temp_mba . $mmi_misc_slim_temp_mba . $mmi_t9_temp . $mmi_hangwang_temp . $mmi_cstar_temp . $mmi_charsettbl_temp;
    }
    else
    {
    	$demand_paging_rom3_temp = $mmi_audio_temp . $mmi_string_temp . $mmi_menu_temp . $mmi_font_slim_temp . $mmi_theme_slim_temp . $mmi_misc_slim_temp . $mmi_t9_temp . $mmi_hangwang_temp . $mmi_cstar_temp . $mmi_charsettbl_temp;
    }
    my @demand_paging_rom3_libs = split("\n", $demand_paging_rom3_temp);
    map { s/^\s+//; } @demand_paging_rom3_libs;
    
    # --- --- ---
    my $j2me_libs_temp;
    if ((&$feature_query_function_ptr('j2me_vm') eq 'KVM') or (&$feature_query_function_ptr('j2me_vm') eq 'KVM_SOURCE'))
    {
    	$j2me_libs_temp = $j2me_kvm_temp;
    }
    else
    {
    	$j2me_libs_temp = $j2me_temp;
    }
    $j2me_libs_temp .= $j2me_extsram_shrinking_temp . $j2me_slim_temp;
    my @j2me_libs = split("\n", $j2me_libs_temp);;
    map { s/^\s+//; } @j2me_libs;

    # --- --- ---
    my @gadget_libs = split("\n", $gadget_temp);
    map { s/^\s+//; } @gadget_libs;

    # --- --- ---
    my @vre_libs = split("\n", $vre_temp);
    map { s/^\s+//; } @vre_libs;
    
    # --- --- ---
    my @mmi_framework_libs = split("\n", $mmi_framework_temp);
    map { s/^\s+//; } @mmi_framework_libs;
    
    # --- --- ---
    my @dpv2_libs = split("\n", $dpv2_temp);
    map { s/^\s+//; } @dpv2_libs;
    
    ### Calculate jblend_ram start addresses
    my $extsram_base_value = 0;
    my $j2me_support = &$feature_query_function_ptr('j2me_support');
    my $mode = &$feature_query_function_ptr('MODE');
    my ($region_size_tx, $region_size_rx) = &sysUtil::DSPTXRX_query_length($bb, $mode);
    my $jblend_ram_start_address = sprintf("0x%08x", $extsram_base_value + $ram_size_value - $region_size_tx - $region_size_rx - (128*1024));

    # --- --- --- 
    my $dp_ev_start_string = sprintf("0x%08x", ($ram_size_value|0xf0000000));

    # --- --- --- 
    my $ev_string;

    ### for SV5
    if (&sysUtil::is_sv5($bb) == 1)
    {
        $ev_string  = &format_execution_view( "DEMAND_PAGING_ROM0_GFH",
                                              $dp_ev_start_string,
                                              undef,
                                              ["*                             (ODP_GFH, +First)",
                                              ]
                                            );
        $dp_ev_start_string = "+0x0";
    }

    # --- --- ---
    # Determine DPv2
    my $demand_paging_version = &$feature_query_function_ptr('demand_paging_version');
    if (defined $demand_paging_version and $demand_paging_version eq 'DPV2')
    {
        $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM0",
                                              $dp_ev_start_string,
                                              undef,
                                              \@dpv2_libs);

        my $nLoop = 1;
        foreach my $i (1..$nLoop)
        {
           my $strOverlay = ($i%2==0 or $nLoop ==1) ? " OVERLAY" : ""; 
           my $L6478E_obj = ($i==$nLoop) ? "L6478E.obj (L6478E_high)" : "";
           $i = "" if ($nLoop == 1);
           $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM0_ROCODE$i",
                                                 "+0x0$strOverlay",
                                                 ($nLoop == 1) ? "" :$dp_lv_size_string,
                                                 [$dpv2_ROCODE ,
                                                  $L6478E_obj]);                                    
        }
    }
    elsif ((&$feature_query_function_ptr('mmi_version') ne 'PLUTO_MMI') and (&$feature_query_function_ptr('mmi_version') ne 'COSMOS_MMI'))
    {
    	$ev_string .= &format_execution_view( "DEMAND_PAGING_ROM0",
    	                                      $dp_ev_start_string,
                                              undef,
                                              undef);
    }
    else
    {
        $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM0",
                                              $dp_ev_start_string,
                                              undef,
                                              \@demand_paging_rom0_libs);
        $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM1",
                                              "+0x00",
                                              undef,
                                              \@demand_paging_rom1_libs);
        if ($mba eq 'TRUE')
        {
            $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM2",
                                                  "+0x00",
                                                  undef,
                                                  \@mmi_image_libs_mba);
        }
        else
        {
            $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM2",
                                                  "+0x00",
                                                  undef,
                                                  \@mmi_image_libs);
        }
        $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM3",
                                              "+0x00",
                                              undef,
                                              \@demand_paging_rom3_libs);
        $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM4",
                                              "+0x00",
                                              undef,
                                              \@j2me_libs);
        $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM5",
                                              "+0x00",
                                              undef,
                                              \@gadget_libs);
        $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM6",
                                              "+0x00",
                                              undef,
                                              \@vre_libs);
        $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM7",
                                              "+0x00",
                                              undef,
                                              \@mmi_framework_libs);
    }
        
    ### Audio/Video lock Demand Paging regions
    #Audio Part: if DEMAND PAGING exists, then Audio Part should appear.
    if (defined &$feature_query_function_ptr('mmi_version') and &$feature_query_function_ptr('mmi_version') ne 'EMPTY_MMI')
    {
        $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM_AUDIO_WAVETABLE",
                                              "+0x00 ABSOLUTE",
                                              undef,
                                              ["*melody_par.a (+RO-CODE, +RO-DATA)",
                                               "*melody_syn.a (+RO-CODE, +RO-DATA)",
                                               "Wavetable_SW.obj (+RO-CODE, +RO-DATA)",
                                              ]
                                            );
        $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM_AUDIO_WAV",
                                              "+0x00",
                                              undef,
                                              ["*wav_codec.a (+RO-CODE, +RO-DATA)",
                                              ]
                                            );
        $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM_AUDIO_MP3",
                                              "+0x00",
                                              undef,
                                              ["*mp3_dec.a (+RO-CODE, +RO-DATA)",
                                              ]
                                            );
        $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM_AUDIO_AAC",
                                              "+0x00",
                                              undef,
                                              ["*aac_dec.a (+RO-CODE, +RO-DATA)",
                                              ]
                                            );
        $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM_AUDIO_AACV1",
                                              "+0x00",
                                              undef,
                                              ["*heaacv1_dec.a (+RO-CODE, +RO-DATA)",
                                              ]
                                            );
        $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM_AUDIO_AACV2",
                                              "+0x00",
                                              undef,
                                              ["*heaacv2_dec.a (+RO-CODE, +RO-DATA)",
                                              ]
                                            );
        $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM_AUDIO_AMR",
                                              "+0x00",
                                              undef,
                                              ["*amr_codec.a (+RO-CODE, +RO-DATA)",
                                              ]
                                            );
        $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM_AUDIO_AWB",
                                              "+0x00",
                                              undef,
                                              ["*awb_codec.a (+RO-CODE, +RO-DATA)",
                                              ]
                                            );
        $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM_AUDIO_COOK",
                                              "+0x00",
                                              undef,
                                              ["*cook_dec.a (+RO-CODE, +RO-DATA)",
                                              ]
                                            );
        $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM_AUDIO_APE",
                                              "+0x00",
                                              undef,
                                              ["*ape_dec.a (+RO-CODE, +RO-DATA)",
                                              ]
                                            );
        $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM_AUDIO_DRA",
                                              "+0x00",
                                              undef,
                                              ["*ArmDraDecLib_rvct.a (+RO-CODE, +RO-DATA)",
                                               "*ArmDraDecLib_rvct_Trial.a (+RO-CODE, +RO-DATA)",
                                              ]
                                            );
        $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM_AUDIO_WMA_16OB",
                                              "+0x00",
                                              undef,
                                              ["dll_PM_6236_WMA_16OB.obj (+RO-CODE, +RO-DATA)",
                                               "dll_PM_6268_WMA_16OB.obj (+RO-CODE, +RO-DATA)",
                                              ]
                                            );
        $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM_AUDIO_WMA_44OB",
                                              "+0x00",
                                              undef,
                                              ["dll_PM_6236_WMA_44OB.obj (+RO-CODE, +RO-DATA)",
                                               "dll_PM_6268_WMA_44OB.obj (+RO-CODE, +RO-DATA)",
                                              ]
                                            );
        $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM_AUDIO_WMA_44QB",
                                              "+0x00",
                                              undef,
                                              ["dll_PM_6236_WMA_44QB.obj (+RO-CODE, +RO-DATA)",
                                               "dll_PM_6268_WMA_44QB.obj (+RO-CODE, +RO-DATA)",
                                              ]
                                            );
        $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM_AUDIO_BES_BASS",
                                              "+0x00",
                                              undef,
                                              ["*BesBass.a (+RO-CODE, +RO-DATA)",
                                              ]
                                            );
        $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM_AUDIO_BES_CF",
                                              "+0x00",
                                              undef,
                                              ["*BesCF.a (+RO-CODE, +RO-DATA)",
                                              ]
                                            );
        $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM_AUDIO_BES_EQ",
                                              "+0x00",
                                              undef,
                                              ["*BesEQ.a (+RO-CODE, +RO-DATA)",
                                              ]
                                            );
        $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM_AUDIO_BES_HEADPHONE",
                                              "+0x00",
                                              undef,
                                              ["*BesHeadphone.a (+RO-CODE, +RO-DATA)",
                                              ]
                                            );
        $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM_AUDIO_BES_LIVE",
                                              "+0x00",
                                              undef,
                                              ["*BesLive.a (+RO-CODE, +RO-DATA)",
                                              ]
                                         );
        $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM_AUDIO_BES_LOUDNESS",
                                              "+0x00",
                                              undef,
                                              ["*BesLoudness.a (+RO-CODE, +RO-DATA)",
                                              ]
                                            );
        $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM_AUDIO_BES_SURROUND",
                                              "+0x00",
                                              undef,
                                              ["*BesSurround.a (+RO-CODE, +RO-DATA)",
                                              ]
                                            );
        $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM_AUDIO_BES_TS",
                                              "+0x00",
                                              undef,
                                              ["*BesTS.a (+RO-CODE, +RO-DATA)",
                                              ]
                                            );
        $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM_AUDIO_BLISRC",
                                              "+0x00",
                                              undef,
                                              ["*BLISRC.a (+RO-CODE, +RO-DATA)",
                                              ]
                                            );
        $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM_AUDIO_VORBIS",
                                              "+0x00",
                                              undef,
                                              ["*vorbis_codec.a (+RO-CODE, +RO-DATA)",
                                              ]
                                            );
    }
    if ((&sysUtil::is_arm11($bb) == 1) and (defined &$feature_query_function_ptr('mmi_version') and &$feature_query_function_ptr('mmi_version') ne 'EMPTY_MMI'))
    {
        $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM_VIDEO_H264DEC",
                                              "+0x00 ABSOLUTE",
                                              undef,
                                              ["*h264dec.arm11*.a (+RO-CODE, +RO-DATA)",
                                               "*h264dec_mphp.arm11*.a (+RO-CODE, +RO-DATA)",
                                              ]
                                            );
        $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM_VIDEO_H264ENC",
                                              "+0x00",
                                              undef,
                                              ["*h264enc.arm11*.a (+RO-CODE, +RO-DATA)",
                                              ]
                                            );                                                
        $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM_VIDEO_MP4DEC",
                                              "+0x00",
                                              undef,
                                              ["*mp4dec.arm11*.a (+RO-CODE, +RO-DATA)",
                                              ]
                                            );
        $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM_VIDEO_MP4COM",
                                              "+0x00",
                                              undef,
                                              ["*mp4com.arm11*.a (+RO-CODE, +RO-DATA)",
                                              ]
                                            );
        $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM_VIDEO_MP4ENC",
                                              "+0x00",
                                              undef,
                                              ["*mp4enc*.arm11*.a (+RO-CODE, +RO-DATA)",
                                              ]
                                            );
        $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM_VIDEO_UVTENC",
                                              "+0x00",
                                              undef,
                                              ["*uvtenc.arm11*.a (+RO-CODE, +RO-DATA)",
                                              ]
                                            );
        $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM_VIDEO_UVTDEC",
                                              "+0x00",
                                              undef,
                                              ["*uvtdec.arm11*.a (+RO-CODE, +RO-DATA)",
                                              ]
                                            );
        $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM_VIDEO_RMDEC",
                                              "+0x00",
                                              undef,
                                              ["*rmdec.arm11*.a (+RO-CODE, +RO-DATA)",
                                              ]
                                            );
    }
    # To prevent L6286E, so move RODATA in the end of DEMAND_PAGING_ROM0
    if (defined $demand_paging_version and $demand_paging_version eq 'DPV2')
    {  

        my $nLoop = 1;
        foreach my $i (1..$nLoop)
        {
           $i = "" if($nLoop == 1);
           $ev_string .= &format_execution_view( "DEMAND_PAGING_ROM0_RODATA$i",
                                                 "+0x0 ABSOLUTE",
                                                 ($nLoop == 1) ? "" :$dp_lv_size_string,
                                                 [$dpv2_RODATA]);                                     
        }
    }
    $ev_string .= &app_feature_jblend( $jblend_ram_start_address );
    $ev_string .= &INTSRAM_DCM_EV($bb);
    ### for SV5
    #$ev_string .= &ROM_SIGNATURE_SECTION_EV($bb, "DEMAND_PAGING_ROM0", "ODP");

    return $ev_string;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View Lists
# input:       BB chip, begin address [string], ram size [value]
#****************************************************************************
sub layout0_rom_ev
{
    my ($bb, $bAdr, $rSZ, $fSZ_str, $decomp_zlength_str) = @_;
    my %BBtbl_RVCT =
       (
       'MT6235'  => sub { &ROM_type_0_RVCT($bb, $bAdr, "FALSE"). &EXTSRAM_type_7($bb, &ev_extsram_base($bb), $rSZ, $decomp_zlength_str). &INTSRAM_type1($bb). &INTSRAM_DCM_EV($bb). &INTSRAM_PAGETABLE_EV($bb, "0x40004000", "0x0000B000") . &INTSRAM_MED_EV($bb, "0x40000000", 1, "0x00010000"). &FLMM_EV($bb);},
       'MT6235B' => sub { &ROM_type_0_RVCT($bb, $bAdr, "FALSE"). &EXTSRAM_type_7($bb, &ev_extsram_base($bb), $rSZ, $decomp_zlength_str). &INTSRAM_type1($bb). &INTSRAM_DCM_EV($bb). &INTSRAM_PAGETABLE_EV($bb, "0x40004000", "0x0000B000") . &INTSRAM_MED_EV($bb, "0x40000000", 1, "0x00010000"). &FLMM_EV($bb);},
       'MT6236'  => sub { &ROM_type_0_RVCT($bb, $bAdr, "FALSE"). &EXTSRAM_type_7($bb, &ev_extsram_base($bb), $rSZ, $decomp_zlength_str). &INTSRAM_type1($bb). &INTSRAM_DCM_EV($bb). &INTSRAM_PAGETABLE_EV($bb, "0x40004000", "0x00015000") . &INTSRAM_MED_EV($bb, "0x40000000", 1, "0x0001A000"). &FLMM_EV($bb);},
       'MT6236B' => sub { &ROM_type_0_RVCT($bb, $bAdr, "FALSE"). &EXTSRAM_type_7($bb, &ev_extsram_base($bb), $rSZ, $decomp_zlength_str). &INTSRAM_type1($bb). &INTSRAM_DCM_EV($bb). &INTSRAM_PAGETABLE_EV($bb, "0x40004000", "0x00015000") . &INTSRAM_MED_EV($bb, "0x40000000", 1, "0x0001A000"). &FLMM_EV($bb);},
       'MT6921'  => sub { &ROM_type_0_RVCT($bb, $bAdr, "FALSE"). &EXTSRAM_type_7($bb, &ev_extsram_base($bb), $rSZ, $decomp_zlength_str). &INTSRAM_type1($bb). &INTSRAM_DCM_EV($bb). &INTSRAM_PAGETABLE_EV($bb, "0x40004000", "0x00015000") . &INTSRAM_MED_EV($bb, "0x40000000", 1, "0x0001A000"). &FLMM_EV($bb);},
       'MT6253'  => sub { &ROM_type_0_RVCT($bb, $bAdr, "FALSE", $decomp_zlength_str). &EXTSRAM_type_2($bb, $rSZ, $decomp_zlength_str). &INTSRAM_type1($bb). &INTSRAM_DCM_EV($bb). &INTSRAM_MED_EV($bb, "0x4001C000", 0, "0x4000");},
       'MT6516'  => sub { &ROM_type_0_RVCT($bb, $bAdr, "FALSE"). &EXTSRAM_type_6($bb, $rSZ). &INTSRAM_type1($bb). &INTSRAM_DCM_EV($bb); },
       'MT6253E' => sub { &ROM_type_0_RVCT($bb, $bAdr, "FALSE"). &EXTSRAM_type_7($bb, &ev_extsram_base($bb), $rSZ, $decomp_zlength_str). &INTSRAM_type1($bb). &INTSRAM_DCM_EV($bb). &INTSRAM_MED_EV($bb, "0x40000000", 1, "0x0001A000");},
       'MT6253L' => sub { &ROM_type_0_RVCT($bb, $bAdr, "FALSE"). &EXTSRAM_type_7($bb, &ev_extsram_base($bb), $rSZ, $decomp_zlength_str). &INTSRAM_type1($bb). &INTSRAM_DCM_EV($bb). &INTSRAM_MED_EV($bb, "0x40000000", 1, "0x0001A000");},
       'MT6252H' => sub { &ROM_type_0_RVCT($bb, $bAdr, "FALSE"). &EXTSRAM_type_7($bb, &ev_extsram_base($bb), $rSZ, $decomp_zlength_str). &INTSRAM_type1($bb). &INTSRAM_DCM_EV($bb). &INTSRAM_MED_EV($bb, "0x40000000", 1, "0x0001A000");},
       'MT6252'  => sub { &ROM_type_0_RVCT($bb, $bAdr, "FALSE"). &EXTSRAM_type_7($bb, &ev_extsram_base($bb), $rSZ, $decomp_zlength_str). &INTSRAM_type1($bb). &INTSRAM_DCM_EV($bb). &INTSRAM_MED_EV($bb, "0x40000000", 1, "0x0001A000");},
       'MT6251'  => sub { &ROM_type_0_RVCT($bb, $bAdr, "FALSE"). &shouldbe_emptysection(). &INTSRAM_type3($bb). &ROM_SIGNATURE_SECTION_EV($bb, "ROM", "MAUI");},
       'MT6573'  => sub { &ROM_type_0_RVCT($bb, $bAdr, "FALSE"). &EXTSRAM_type_7($bb, hex($fSZ_str), $rSZ, $decomp_zlength_str). &INTSRAM_type1($bb). &INTSRAM_DCM_EV($bb). &INTSRAM_PAGETABLE_EV($bb, "0x90000000", "0x0001B000") . &INTSRAM_MED_EV($bb, "0x40000000", 1, "0x00043000"). &FLMM_EV($bb);},
       'MT6575'  => sub { &ROM_type_0_RVCT($bb, $bAdr, "FALSE"). &EXTSRAM_type_7($bb, hex($fSZ_str), $rSZ, $decomp_zlength_str). &INTSRAM_type1($bb). &INTSRAM_DCM_EV($bb). &INTSRAM_MED_EV($bb, "0x40000000", 1, "0x00043000"). &FLMM_EV($bb);},
       'MT6255'  => sub { &ROM_type_0_RVCT($bb, $bAdr, "FALSE"). &EXTSRAM_type_7($bb, &ev_extsram_base($bb), $rSZ, $decomp_zlength_str). &INTSRAM_type1($bb). &INTSRAM_DCM_EV($bb). &INTSRAM_MED_EV($bb, "0x40000000", 1, "0x00007000"). &FLMM_EV($bb);},
       'MT6922'  => sub { &ROM_type_0_RVCT($bb, $bAdr, "FALSE"). &EXTSRAM_type_7($bb, &ev_extsram_base($bb), $rSZ, $decomp_zlength_str). &INTSRAM_type1($bb). &INTSRAM_DCM_EV($bb). &INTSRAM_MED_EV($bb, "0x40000000", 1, "0x00007000"). &FLMM_EV($bb);},
       'TK6280'  => sub { &ROM_type_0_RVCT($bb, $bAdr, "FALSE"). &EXTSRAM_type_7($bb, hex($fSZ_str), $rSZ, $decomp_zlength_str). &INTSRAM_type1($bb). &INTSRAM_DCM_EV($bb). &INTSRAM_MED_EV($bb, "0x40000000", 1, "0x00043000"). &FLMM_EV($bb);},
       'MT6280'  => sub { &ROM_type_0_RVCT($bb, $bAdr, "FALSE"). &EXTSRAM_type_7($bb, $fSZ_str, $rSZ, $decomp_zlength_str). &INTSRAM_type1($bb). &INTSRAM_DCM_EV($bb). &INTSRAM_MED_EV($bb, "0x40000000", 1, "0x00043000");},
       'MT6250'  => sub { &ROM_type_0_RVCT($bb, $bAdr, "FALSE"). &EXTSRAM_type_7($bb, &ev_extsram_base($bb), $rSZ, $decomp_zlength_str). &INTSRAM_type1($bb). &INTSRAM_DCM_EV($bb). &INTSRAM_MED_EV($bb, "0x40000000", 1, "0x0001A000"). &ROM_SIGNATURE_SECTION_EV($bb, "ROM", "MAUI");},
       );
       #map {print $_, "\n";} keys %BBtbl;
    &sysUtil::sysgen_die("tools/scatGenLib.pl: Unsupported Feature Combination Default on $bb!", __FILE__, __LINE__) if not exists $BBtbl_RVCT{$bb}; 
    my $func;
    my $compiler = &$feature_query_function_ptr('compiler');
    if ($compiler eq 'RVCT')
    {
       $func = $BBtbl_RVCT{$bb};
    }
    return &$func;
}

#****************************************************************************
# subroutine:  SECURE Layout :: SECURE MAC :: Exec View
# input:       BB chip, begin address [string], ram size [value] "None"
#****************************************************************************
sub layout3_secure_mac_ev
{
   my $template = <<"__TEMPLATE";
    __HIDDEN_SECURE_MAC +0x0
    {
         *.obj (SECURE_MAC_SIZE)
    }
    __HIDDEN_SECURE_MAC_CONTENT +0x0
    {
         *.obj (SECURE_MAC_CONTENT)
    }
__TEMPLATE
   return $template;
}

#****************************************************************************
# subroutine:  SECURE Layout :: SECURE MAC :: Exec View
# input:       BB chip, begin address [string], ram size [value] "None"
#****************************************************************************
sub layout3_fota_secure_mac_ev
{
   my $template = <<"__TEMPLATE";
    __HIDDEN_SECURE_MAC_CONTENT +0x0
    {
         *.obj (SECURE_MAC_CONTENT)
    }
    __HIDDEN_SECURE_MAC +0x0
    {
         *.obj (SECURE_MAC_SIZE)
    }
__TEMPLATE
   return $template;
}

#****************************************************************************
# subroutine:  SECURE Layout :: SECURE RO :: Exec View
# input:       BB chip, begin address [string], ram size [value] "None"
#****************************************************************************
sub layout3_secure_ro_ev
{
    my ($addr) = @_;
    return &format_execution_view( "SECURE_RO", $addr, undef, ["*.obj (SECURE_RO)"] );
}

#****************************************************************************
# subroutine:  SECURE Layout :: FLASHTOOL CFG:: Exec View
# input:       BB chip, begin address [string], ram size [value] "None"
#****************************************************************************
sub layout3_toolcfg_ev
{
    my ($addr) = @_;
    return &format_execution_view( "__HIDDEN_FLASHTOOL_CFG", $addr, undef, ["*.obj (FLASHTOOL_CFG)"] );
}

#****************************************************************************
# subroutine:  SECURE Layout :: CUST PARA:: Exec View
# input:       BB chip, begin address [string], ram size [value] "None"
#****************************************************************************
sub layout3_custpara_ev
{
    my ($addr) = @_;
    my $template = &format_execution_view( "__HIDDEN_CUST_PARA", $addr, undef, ["*.obj (CUST_PARA)"] );
    $template .= &format_execution_view( "__HIDDEN_CUST_PARA_TAIL", "+0x0", undef, ["*.obj (CUST_PARA_TAIL)"] );
    return $template;
}

#****************************************************************************
# subroutine:  MultiBIN Layout :: LANG PACK ROM :: Exec View
# input:       BB chip, begin address [string], ram size [value] "None"
#****************************************************************************
sub layout2_lang_ev
{
    my ($lang_pack_rom_base, $bb) = @_;

    ### Add GFH for SV5
    my $sv5_lang_gfh;
    if (&sysUtil::is_sv5($bb) == 1)
    {
    	$sv5_lang_gfh = <<"__TEMPLATE";
    LANG_PACK_ROM_GFH +0x0
    {
    	 *                             (LANG_PACK_GFH, +First)
    }
__TEMPLATE

        $lang_pack_rom_base = "+0x0";
    }
    chomp $sv5_lang_gfh;
      
    my $template = <<"__TEMPLATE";
$sv5_lang_gfh
    LANG_PACK_ROM $lang_pack_rom_base
    {
         resource_lang_pack_preamble.obj (RESOURCE_JUMP_TBL, +First)
         resource_lang_pack_jtbl.obj (+RW)
    }
    LANG_PACK_ROM_CONTENT +0x00
    {
         *  (LANGPACK_RODATA, LANGPACK_ROCODE)
         CustStrRes.obj (+RO-CODE, +RO-DATA)
         CustStrDataRes_*.obj (+RO-CODE, +RO-DATA)
         CustStrMap.obj (+RO-CODE, +RO-DATA)
         FontRes.obj (+RO-CODE, +RO-DATA)
         IMERes.obj (+RO-CODE, +RO-DATA)
         CustMenuRes.obj (+RO-CODE, +RO-DATA)
         CustMenuDataRes_*.obj (+RO-CODE, +RO-DATA)
         CustFontMapExt.obj (+RO-CODE, +RO-DATA)
         CustFontResExt.obj (+RO-CODE, +RO-DATA)
         vf_*.obj (+RO-CODE, +RO-DATA)
    }
__TEMPLATE
    return $template;
}

#****************************************************************************
# subroutine:  MultiBIN Layout :: CUST PACK ROM :: Exec View
# input:       BB chip, begin address [string], ram size [value] "None"
#****************************************************************************
sub layout2_cust_ev
{
    my ($bb) = @_;

    ### Add GFH for SV5
    my $sv5_cust_gfh;
    if (&sysUtil::is_sv5($bb) == 1)
    {
    	$sv5_cust_gfh = <<"__TEMPLATE";
    CUSTPACK_ROM_GFH +0x0
    {
         *                             (CUSTPACK_GFH, +First)
    }
__TEMPLATE
    }
    chomp $sv5_cust_gfh;
    
    my $mmi_version = &$feature_query_function_ptr('mmi_version');
    my $Cust_Theme;
    if($mmi_version eq 'PLUTO_MMI' or $mmi_version eq 'COSMOS_MMI')
    {
        $Cust_Theme = <<"__TEMPLATE";
         CustVenusThemeData.obj (+RO-CODE, +RO-DATA)
__TEMPLATE
        chomp $Cust_Theme;
    }
    my $template = <<"__TEMPLATE";
$sv5_cust_gfh
    CUSTPACK_ROM +0x00
    {
         resource_custpack_preamble.obj (RESOURCE_JUMP_TBL, +First)
         resource_custpack_jtbl.obj (+RW)
    }
    CUSTPACK_ROM_CONTENT +0x00
    {
         *  (CUSTPACK_RODATA, CUSTPACK_ROCODE)¡@
         ThemeRes.obj (RESOURCE_1ST_CONTENT)
         ThemeRes.obj (+RO-CODE, +RO-DATA)
         nvram_cust_pack.obj (+RO-CODE, +RO-DATA)
         CustImgResExt.obj (+RO-CODE, +RO-DATA)
         CustAdoResExt.obj (+RO-CODE, +RO-DATA)
         custpack_certs.obj (+RO-CODE, +RO-DATA)
         custpack_java_certs.obj (+RO-CODE, +RO-DATA)
$Cust_Theme
    }
__TEMPLATE
    return $template;
}

#****************************************************************************
# subroutine:  MultiBIN Layout :: JUMP TABL ROM :: Exec View
# input:       BB chip, begin address [string], ram size [value] "None"
#****************************************************************************
sub layout2_jump_ev
{
    my ($bb) = @_;

    ### Add GFH for SV5
    my $sv5_jump_gfh;
    if (&sysUtil::is_sv5($bb) == 1)
    {
    	$sv5_jump_gfh = <<"__TEMPLATE";
    JUMP_TABLE_GFH +0x0
    {
         *                             (JUMP_TABLE_GFH, +First)
    }
__TEMPLATE
    }
    chomp $sv5_jump_gfh;
      
    my $template = <<"__TEMPLATE";
$sv5_jump_gfh
    JUMP_TABLE +0x00
    {
         custom_jump_tbl.obj (+RO-CODE, +RO-DATA, +RW, +ZI)
    }
__TEMPLATE
    return $template;
}

#****************************************************************************
# subroutine:  Execution View Generator
# input:       Region name [string], Begin [string], Length [string], Content [Array Reference]
# output:      execution view body string
#****************************************************************************
sub format_execution_view
{
    my ($name, $begin, $length, $ar) = @_;
    my $formated_string = ' ' x 4 . $name . " $begin $length\n";
    $formated_string .= ' ' x 4 . "{\n";
    foreach (@$ar)
    {
           if (/\A;/) {$formated_string .= $_ . "\n";}
           else       {$formated_string .= ' ' x 9 . $_ . "\n";}
    }
    $formated_string .= ' ' x 4 . "}\n";
    return $formated_string;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: ROM Type 0 (RVCT)
# input:       Begin [string]
#****************************************************************************
sub ROM_type_0_RVCT
{
    my ($bb, $begin_string, $secure) = @_;

    my $rom_baseaddr      = $begin_string;
    my $rom_size_string   = sprintf("0x%08x", 0x800);
    my $rom0_begin_string = sprintf("0x%08x FIXED", hex($begin_string) + hex($rom_size_string));
    my $rom1_template;
    my $zimage = &$feature_query_function_ptr('zimage_support');
    my $mmi_version = &$feature_query_function_ptr('mmi_version');
    my $alice = &$feature_query_function_ptr('alice_support');
    my $dcm_compression_support = &$feature_query_function_ptr('dcm_compression_support');
    my $mba = &$feature_query_function_ptr('multiple_binary_files');
    my $optional_obj_nep_zimage;
    my $ALICEforbiden_dummy;
    my @aliceForbiden_libs;
    my $semicolon;
    if((!defined $mba or $mba ne 'TRUE') or &sysUtil::is_sv5($bb) == 1)
    {
        $semicolon = ';';
    }
    
    my $dcmp_input_section;
    if (defined $dcm_compression_support and $dcm_compression_support eq 'TRUE')
    {
        $dcmp_input_section = <<"__TEMPLATE_DCMP";
         *                             (i.__rt_udiv_3)
         *                             (i.__rt_sdiv_3)
         *                             (i.__rt_udiv_5)
         *                             (i.__rt_sdiv_5)
         *                             (i.__rt_udiv_9)
         *                             (i.__rt_sdiv_9)
         *                             (i.__rt_udiv_21)
         *                             (i.__rt_sdiv_21)
         *                             (i.__rt_udiv_31)
         *                             (i.__rt_sdiv_31)
         *                             (i.__rt_udiv_60)
         *                             (i.__rt_sdiv_60)
         *                             (i.__rt_udiv_100)
         *                             (i.__rt_sdiv_100)
         *                             (i.__rt_udiv_1000)
         *                             (i.__rt_sdiv_1000)
         *                             (i.__rt_udiv_3600)
         *                             (i.__rt_sdiv_3600)
         *                             (i.__rt_udiv_10000)
         *                             (i.__rt_sdiv_10000)

__TEMPLATE_DCMP
    }
    $rom1_template = $dcmp_input_section;

    if((defined $alice and $alice eq 'TRUE') or (defined $zimage and $zimage eq 'TRUE'))
    {
        $rom1_template .= &GetROM1_inputsection();
        if(($dummy_scatter eq 'TRUE') and ($alice eq 'TRUE') and ($zimage eq 'TRUE'))
        {
            $ALICEforbiden_dummy   = &Get_ObjListGen_List('objectALICE_FORBID_dummy.list');
            @aliceForbiden_libs  = split("\n", $ALICEforbiden_dummy);
            map { s/^\s+//; } @aliceForbiden_libs;
        }
    }
    else
    {    
        $rom1_template .= "         *                             (+RO)";
    }

    chomp $rom1_template;

    my @rom1_libs = split("\n", $rom1_template);
    map { s/^\s+//; } @rom1_libs;

    # --- --- --- 
    my $ev_string;
    ### for SV5
    if (&sysUtil::is_sv5($bb) == 1)
    {
        $ev_string  = &format_execution_view( "ROM_GFH",
                                              $rom_baseaddr,
                                              undef,
                                              ["*                             (MAUI_GFH, +First)",
                                               "*                             (MAUI_GFH_EXT)",
                                              ]
                                            );
        $rom_baseaddr = "+0x0";
        $rom0_begin_string = "+0x0";
    }

    $ev_string .= &format_execution_view( "ROM",
                                          $rom_baseaddr,
                                          $rom_size_string,
                                          ["bootarm_rvct.obj (C\$\$code,+First)",
                                           "$semicolon*obj (MBA_INFO)",
                                           "*.obj (LEADING_PART)",
                                          ]
                                        );
    $ev_string .= &format_execution_view( "ROM0",
                                          $rom0_begin_string,
                                          undef,
                                          ["*.obj (SECINFO)",
                                          ]
                                        );
    $ev_string .= &format_execution_view( "ROMHEAD",
                                          "+0x0",
                                          undef,
                                          ["*.obj (SECOND_PART)",
                                           "*.obj (MAUI_FOTA_HEAD_INFO)",
                                          ]
                                        );
    if((!defined $dcm_compression_support or $dcm_compression_support ne 'TRUE')
        and (&sysUtil::is_arm7($bb) and $bb ne 'MT6253'))
    {
        $ev_string .= &format_execution_view( "ROM_VIDEO",
                                              "+0x0",
                                              undef,
                                              ["* (MP4ENC1_DYNAMIC_CODE, MP4ENC1_DYNAMIC_RO)",
                                               "* (MP4ENC_DYNAMIC_CODE, MP4ENC_DYNAMIC_RO)",
                                               "* (MP4ENC2_DYNAMIC_RO)",
                                              ]
                                            );
    }
    $ev_string .= &format_execution_view( "ROM1",
                                          "+0x0",
                                          undef,
                                          \@rom1_libs
                                        );
    if (($dummy_scatter eq 'TRUE') and ($alice eq 'TRUE') and ($zimage eq 'TRUE'))
    {
        $ev_string .= &format_execution_view( "ALICE_FORBID",
                                          "+0x0",
                                          undef,
                                          \@aliceForbiden_libs
                                        );   	        
    }                                        
    if ($secure eq 'TRUE')
    {
        $ev_string .= &format_execution_view( "ROM_TAIL",
                                              "+0x0",
                                              undef,
                                              ["*.obj (SECINFO_TAIL)",
                                              ]
                                            );
    }
    return $ev_string;
}

#****************************************************************************
# subroutine:  NFB Layout :: PRIMARY ROM :: Exec View :: ROM Type 1
# input:       Begin [string]
#****************************************************************************
sub ROM_type_1
{
    my ($bb, $multibin, $security) = @_;
    my $secinfo_offset_value = 4 * 1024;
    my $compiler = &$feature_query_function_ptr('compiler');

    # --- --- ---
    my $mba = &$feature_query_function_ptr('multiple_binary_files');
    my $semicolon;
    if((!defined $mba or $mba ne 'TRUE') or &sysUtil::is_sv5($bb) == 1)
    {
        $semicolon = ';';
    }
    # --- --- ---
    my $fixed;
    if ((&sysUtil::is_arm9($bb) != 1) and (&sysUtil::is_arm11($bb) != 1))
    {
         $fixed = "FIXED";
         chomp $fixed;
    }
    # --- --- ---
    my $size;
    if ((&sysUtil::is_arm9($bb) != 1) and (&sysUtil::is_arm11($bb) != 1))
    {
         $size = "0x3E8000";
         chomp $size;
    }

    my $rom_temp = &app_feature_pmaui_rom($bb);
    my @mtklibs = split("\n", $rom_temp);
    map { s/^\s+//; } @mtklibs;

    my $rom1_1_temp = &app_feature_clib_rom();
    my @rom1_1_libs = split("\n", $rom1_1_temp);
    map { s/^\s+//; } @rom1_1_libs;

    my $ev_string;
    my ($rom_baseaddr, $romhead_baseaddr);
    my $dsp_solution = &$feature_query_function_ptr('dsp_solution');
    if (defined $dsp_solution and $dsp_solution eq 'DUALMACDSP')
    {
        $rom_baseaddr     = "0x180000";
    }
    else
    {
        $rom_baseaddr = "0x00";
    }
    $romhead_baseaddr = sprintf("0x%x FIXED", hex($rom_baseaddr)+0x800);

    ### for SV5
    if (&sysUtil::is_sv5($bb) == 1)
    {
        $ev_string  = &format_execution_view( "ROM_GFH",
                                              $rom_baseaddr,
                                              undef,
                                              ["*                             (MAUI_GFH, +First)",
                                               "*                             (MAUI_GFH_EXT)",
                                              ]
                                            );
        $rom_baseaddr = "+0x0";
        $romhead_baseaddr = "+0x0";
    }

    $ev_string .= &format_execution_view( "ROM",
                                          $rom_baseaddr,
                                          undef,
                                          ["bootarm_rvct.obj                   (C\$\$code,+First)",
                                           "*.obj                         (LEADING_PART)",
                                           "$semicolon*obj                          (MBA_INFO)",
                                           "L6478E.obj                    (L6478E_low)",
                                          ]
                                        );
    $ev_string .= &format_execution_view( "ROMHEAD",
                                          $romhead_baseaddr,
                                          undef,
                                          ["*.obj                         (SECINFO)",
                                           "*.obj                         (SECOND_PART)",
                                           "*.obj                         (MAUI_FOTA_HEAD_INFO)",
                                          ]
                                        );
    if ($compiler eq 'RVCT')
    {
        $ev_string .= &format_execution_view( "ROM1_1",
                                              "+0x0",
                                              undef,
                                             \@rom1_1_libs);
    }
    $ev_string .= &format_execution_view( "ROM1",
                                          "+0x0",
                                          $size,
                                          \@mtklibs);
    return $ev_string;
}

#****************************************************************************
# subroutine:  NFB Layout :: SECONDARY ROM :: Exec View :: ROM Type 2
# input:       Begin [value]
#****************************************************************************
sub ROM_type_2
{
    my ($bb, $ev_baseaddr, $security, $nfb_or_emb) = @_;
    my $ev_string;

    my @rom2libs = split("\n", &app_feature_rom2($bb, $nfb_or_emb));
    map { s/^\s+//; } @rom2libs;

    # --- --- ---
    # Determine DPv2
    my $demand_paging_version = &$feature_query_function_ptr('demand_paging_version');

    my $compiler = &$feature_query_function_ptr('compiler');
    if ($compiler eq 'RVCT')
    {
        $ev_string .= &format_execution_view( "SECONDARY_ROM",
                                              $ev_baseaddr,
                                              undef,
                                              ["bootarm_rvct.obj (DUMMY_ROM_HEAD)"]
                                            );
        if (($nfb_or_emb ne 'ONDEMAND') or (!defined $demand_paging_version) or (defined $demand_paging_version and $demand_paging_version ne 'DPV2'))
        {
            $ev_string .= "    ; Add ROM2_RODATA to use 2-MAUI RO-DATA to push 2-MAUI RO-CODE away from 1-MAUI RO-CODE to prevent L6478E\n";
            $ev_string .= &format_execution_view( "ROM2_RODATA",
                                                  "+0x0 ABSOLUTE",
                                                  undef,
                                                  [".ANY (+RO-DATA)",
                                                  ]
                                                );
        }
        $ev_string .= &format_execution_view( "ROM2",
                                              "+0x0 OVERLAY ; Add OVERLAY to prevent RVCT veneer placement issue",
                                              undef,
                                              \@rom2libs
                                            );
        $ev_string .= "    ; Add ABSOLUTE to prevent being inherited OVERLAY attribute\n";
    }

    if ($security eq 'TRUE')
    {
        $ev_string .= &format_execution_view( "ROM_TAIL", "+0x0 ABSOLUTE", undef, ["*.obj (SECINFO_TAIL)"]);
    }
    return $ev_string;
}

#****************************************************************************
# subroutine:  Secure+USB-DL Layout :: ROM :: Exec View :: ROM Type 4 (RVCT)
# input:       Flash Begin [value]
#****************************************************************************
sub ROM_type_4_RVCT
{
    my ($bb, $baseaddr_value) = @_;

    my $rom_size_string   = sprintf("0x%08x", 0x800);
    my $rom0_begin_string = sprintf("0x%08x", hex($begin_string) + hex($rom_size_string));
    # --- --- --- 
    my $ev_baseaddr       = sprintf("0x%08x", $baseaddr_value);
    my $rom0_begin_string = sprintf("0x%08x", $baseaddr_value + hex($rom_size_string));
    # --- --- --- 
    my $mba = &$feature_query_function_ptr('multiple_binary_files');
    my $semicolon;
    if((!defined $mba or $mba ne 'TRUE') or &sysUtil::is_sv5($bb) == 1)
    {
        $semicolon = ';';
    }
    # --- --- --- 
    my $ev_string;
    $ev_string  = &format_execution_view( "ROM",
                                          $ev_baseaddr,
                                          $rom_size_string,
                                          ["bootarm_rvct.obj (C\$\$code,+First)",
                                           "$semicolon*obj (MBA_INFO)",
                                           "*.obj (LEADING_PART)",
                                          ]
                                        );
    $ev_string .= &format_execution_view( "ROM0",
                                          $rom0_begin_string,
                                          "FIXED",
                                          ["*.obj (SECINFO)",
                                          ]
                                        );
    $ev_string .= &format_execution_view( "ROMHEAD",
                                          "+0x0",
                                          undef,
                                          ["*.obj (SECOND_PART)",
                                           "*.obj (MAUI_FOTA_HEAD_INFO)",
                                          ]
                                        );
    my $dcm_compression_support = &$feature_query_function_ptr('dcm_compression_support');
    if((!defined $dcm_compression_support or $dcm_compression_support ne 'TRUE')
        and (&sysUtil::is_arm7($bb) and $bb ne 'MT6253'))
    {
        $ev_string .= &format_execution_view( "ROM_VIDEO",
                                              "+0x0",
                                              undef,
                                              ["* (MP4ENC1_DYNAMIC_CODE, MP4ENC1_DYNAMIC_RO)",
                                               "* (MP4ENC_DYNAMIC_CODE, MP4ENC_DYNAMIC_RO)",
                                               "* (MP4ENC2_DYNAMIC_RO)",
                                              ]
                                            );
    }
    $ev_string .= &format_execution_view( "ROM1",
                                          "+0x0",
                                          undef,
                                          [".ANY (+RO-CODE)",
                                           ".ANY (+RO-DATA)",
                                          ]
                                        );
    $ev_string .= &format_execution_view( "ROM_TAIL",
                                          "+0x0",
                                          undef,
                                          ["*.obj (SECINFO_TAIL)",
                                          ]
                                        );
    return $ev_string;
}

#****************************************************************************
# subroutine:  NFB Layout :: SECONDARY ROM :: Exec View :: ROM Type 5
# input:       Begin [value]
#****************************************************************************
sub ROM_type_5
{
    my ($bb, $ev_baseaddr, $security, $nfb_or_emb) = @_;
    my $ev_string;

    my @rom2libs = split("\n", &app_feature_rom2($bb, $nfb_or_emb));
    map { s/^\s+//; } @rom2libs;

    # --- --- ---
    # Determine DPv2
    my $demand_paging_version = &$feature_query_function_ptr('demand_paging_version');

    ### for SV5
    if (&sysUtil::is_sv5($bb) == 1)
    {
        $ev_string  = &format_execution_view( "SECONDARY_ROM_GFH",
                                              $ev_baseaddr,
                                              undef,
                                              ["*                             (S_MAUI_GFH, +First)",
                                               "*                             (S_MAUI_GFH_EXT)",
                                              ]
                                            );
        $ev_baseaddr = "+0x0";
    }

    my $compiler = &$feature_query_function_ptr('compiler');
    if ($compiler eq 'RVCT')
    {
        $ev_string .= &format_execution_view( "SECONDARY_ROM",
                                              $ev_baseaddr,
                                              undef,
                                              ["bootarm_rvct.obj (DUMMY_ROM_HEAD)"]
                                            );
        if (($nfb_or_emb ne 'ONDEMAND') or (!defined $demand_paging_version) or (defined $demand_paging_version and $demand_paging_version ne 'DPV2'))
        {
            $ev_string .= "    ; Add ROM2_RODATA to use 2-MAUI RO-DATA to push 2-MAUI RO-CODE away from 1-MAUI RO-CODE to prevent L6478E\n";
            $ev_string .= &format_execution_view( "ROM2_RODATA",
                                                  "+0x0 ABSOLUTE",
                                                  undef,
                                                  [".ANY (+RO-DATA)",
                                                  ]
                                                );
        }
        $ev_string .= &format_execution_view( "ROM2",
                                              "+0x0 OVERLAY ; Add OVERLAY to prevent RVCT veneer placement issue",
                                              undef,
                                              \@rom2libs
                                            );
        $ev_string .= "    ; Add ABSOLUTE to prevent being inherited OVERLAY attribute\n";
    }

    if ($security eq 'TRUE')
    {
        $ev_string .= &format_execution_view( "ROM_TAIL", "+0x0 ABSOLUTE", undef, ["*.obj (SECINFO_TAIL)"]);
    }
    return $ev_string;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: EXTSRAM Type 2
# input:       BB , RAM size [value]
# remark:      include SINGLE_BANK_CODE, LARGEPOOL , EXTSRAM , APP Features , DSP TX, DSP RX
#****************************************************************************
sub EXTSRAM_type_2
{
    my ($bb, $ram_size, $decomp_size_str) = @_;
    my $ev_string;
    my $extsram_base_value = &ev_extsram_base($bb);
    my $ev_baseaddr = sprintf("0x%08x", ($extsram_base_value == 0x0) ? 0x200 : $extsram_base_value);

    $ev_string  = &SINGLE_BANK_CODE($bb, "SINGLE_BANK_CODE", $ev_baseaddr);
    if (defined $ev_string)
    {
       $ev_baseaddr = sprintf("0x%08x", 0x2000);
       my $mode = &$feature_query_function_ptr('MODE');
       $ev_baseaddr = sprintf("0x%08x", 0x4000) if($mode eq "BASIC"); # because basic load has too many debug information
    }

    $ev_string .= &LARGEPOOL($bb, "EXTSRAM_LARGEPOOL_NORMAL", $ev_baseaddr, undef);
    $ev_string .= &app_feature_jblend("+0x00");
    $ev_string .= &format_execution_view( "EXTSRAM",
                                          "+0x00",
                                          undef,
                                          ["* (EXTSRAM_RW, EXTSRAM_ZI)",
                                           "* (+RW, +ZI)",
                                          ]
                                         );
    $ev_string .= &format_execution_view( "EXTSRAM_NVRAM_LTABLE",
                                          "+0x00",
                                          undef,
                                          ["* (_nvram_ltable)",
                                           "* (_indirect_init)",
                                           "* (_fs_filetable)",
                                           "* (_nvram_callback_tbl)",]
                                         );
    $ev_string .= &app_feature_res_prot($bb);
    $ev_string .= &app_feature_gadget("+0x00");

    my $mode = &$feature_query_function_ptr('MODE');
    my ($region_size_tx, $region_size_rx) = &sysUtil::DSPTXRX_query_length($bb, $mode);

    ### Add DUMMY_END for DCMP because DCMP regions are OVERLAY and will not report error when expiration
    if (hex($decomp_size_str) != 0)
    {
    	# Minus DSP_TX/RX
    	my $dcmp_end = &ev_extsram_base($bb) + $ram_size - $region_size_tx - $region_size_rx;
        $ev_string .= &format_execution_view( "DUMMY_END",
                                              sprintf("0x%08x", $dcmp_end - hex($decomp_size_str) - 4),
                                              "ABSOLUTE 0x04",
                                              ["bootarm_rvct.obj (DUMMY_POOL)"]
                                            );
    }
    $ev_string .= &DSPTXRX( $bb, "EXTSRAM", $extsram_base_value, $ram_size, $region_size_tx, $region_size_rx );
    $ev_string .= &shouldbe_emptysection();
    return $ev_string;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: EXTSRAM Type 6 (Smart Phone)
# input:       BB , RAM size [value]
# remark:      include LARGEPOOL , EXTSRAM , APP Features , DSP TX, DSP RX
#****************************************************************************
sub EXTSRAM_type_6
{
    my ($bb, $ram_size) = @_;
    my $ev_string;

    ###
    my %BBtbl =
       (        
                'MT6516'  => '0x280000',
       );
    my $ev_baseaddr = $BBtbl{$bb};
    $ev_string .= &LARGEPOOL($bb, "EXTSRAM_LARGEPOOL_NORMAL", $ev_baseaddr, "0x20000");
    $ev_string .= &app_feature_jblend("+0x00");
    $ev_string .= &format_execution_view( "EXTSRAM",
                                          "+0x00",
                                          undef,
                                          ["* (EXTSRAM_RW, EXTSRAM_ZI)",
                                           "* (+RW, +ZI)",
                                          ]
                                         );
    $ev_string .= &format_execution_view( "EXTSRAM_NVRAM_LTABLE",
                                          "+0x00",
                                          undef,
                                          ["* (_nvram_ltable)",
                                           "* (_indirect_init)",
                                           "* (_fs_filetable)",
                                           "* (_nvram_callback_tbl)",]
                                         );
    my $mode = &$feature_query_function_ptr('MODE');
    my ($region_size_tx, $region_size_rx) = &sysUtil::DSPTXRX_query_length($bb, $mode);
    $ev_string .= &DSPTXRX( $bb, "EXTSRAM", $extsram_base_value, $ram_size, $region_size_tx, $region_size_rx );
    $ev_string .= &shouldbe_emptysection();
    return $ev_string;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: EXTSRAM Type 7 (ARM9 Only)
# input:       BB , RAM size [value]
# remark:      include SINGLE_BANK_CODE, LARGEPOOL , EXTSRAM , APP Features , PAGE_TABLE, CACHED_EXTSRAM , DSP TX, DSP RX
#****************************************************************************
sub EXTSRAM_type_7
{
    my ($bb, $ram_base, $ram_size, $decomp_size_str) = @_;
    my $ev_string;
    my $ev_baseaddr = sprintf("0x%08x", ($ram_base == 0x0) ? 0x200 : $ram_base);
    $ev_baseaddr = $ram_base if($ram_base =~/\+/);
    ### ALICE support
    my $alice = &$feature_query_function_ptr('alice_support');    

    my $dsp_solution = &$feature_query_function_ptr('dsp_solution');
    my $is_DUALMACDSP = (defined $dsp_solution and $dsp_solution eq 'DUALMACDSP') ? 1 : 0;
    &sysUtil::sysgen_die("Unsupported combination: feature phone with DSP=DUALMACDSP in NOR\n", __FILE__, __LINE__) if((!&FileInfo::is_SmartPhone($mf_option_ref)) and $is_DUALMACDSP); # FCORE has aligned requirement in feature phone.
    
    $ev_string = &SINGLE_BANK_CODE($bb, "SINGLE_BANK_CODE", $ev_baseaddr);
    if (defined $ev_string)
    {
        $ev_baseaddr = sprintf("0x%08x", 0x2000);
        my $mode = &$feature_query_function_ptr('MODE');
        $ev_baseaddr = sprintf("0x%08x", 0x4000) if($mode eq "BASIC"); # because basic load has too many debug information
    }
    if($alice eq 'TRUE')
    {
        $ev_string .= &format_execution_view( "EXTSRAM_ALICE", 
                                          $ev_baseaddr, 
                                          "0x6000", 
                                          ["* (ALICE_RAM)"]
                                        );	
    	  $ev_baseaddr = sprintf("0x%08x", hex($ev_baseaddr) + 0x6000);
    }               
    $ev_string .= &format_execution_view( "EXTSRAM", 
                                          $ev_baseaddr, 
                                          undef, 
                                          ["* (NONCACHEDRW, NONCACHEDZI)",
                                           "*deniro.a (+RW, +ZI)",
                                           "*fs_fig.a (+RW, +ZI)",
                                          ]
                                        );
    #--- --- --- --- --- --- --- --- --- --- --- --- ---       
    #DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI_MMIPOOL  +0x1000
    #DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI          +0x0
    # --- --- --- --- --- --- --- --- --- --- --- --- ---
    $ev_string .= &format_execution_view( "DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI_MMIPOOL",
                                              "+0x1000", undef,
                                              ["med_main.obj (LARGEPOOL_ZI)",
                                               "* (DYNAMICCACHEABLEZI_NC_MMIPOOL)", ] );
    $ev_string .= &format_execution_view( "DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI",
                                              "+0x0", undef, ["* (DYNAMICCACHEABLEZI_NC)"]);
    # --- --- --- --- --- --- --- --- --- --- --- --- ---                                      
    $ev_string .= &format_execution_view( "DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_RW",
                                          "+0x0",
                                          undef,
                                          ["* (DYNAMICCACHEABLERW_NC)",
                                          ]
                                        );
    if ((&sysUtil::is_arm9($bb) == 1) or (&sysUtil::is_arm11($bb) == 1))
    {
        $ev_string .= &format_execution_view( "PAGE_TABLE",
                                              (&config_query_remapping() or &FileInfo::is_SmartPhone($mf_option_ref)) ? "+0xF0001000" : "+0xE0001000",
                                              undef,
                                              ["* (PAGETABLE)"]
                                            );
        $ev_string .= &CACHED_EXTSRAM_EV("+0x0");
    }
    else
    {
        $ev_string .= &CACHED_EXTSRAM_EV("+0xF0001000");
    }
    $ev_string .= &format_execution_view( "CACHED_EXTSRAM_NVRAM_LTABLE",
                                          "+0x00",
                                          undef,
                                          ["* (_nvram_ltable)",
                                           "* (_indirect_init)",
                                           "* (_fs_filetable)",
                                           "* (_nvram_callback_tbl)",]
                                         );
    $ev_string .= &app_feature_res_prot($bb);
    $ev_string .= &app_feature_gadget("+0x00");
    $ev_string .= &format_execution_view( "DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_RW",
                                          "+0x1000",
                                          undef,
                                          ["* (DYNAMICCACHEABLERW_C)"]
                                        );
    # --- --- --- --- --- --- --- --- --- --- --- --- ---
    #DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_MMIPOOL       +0x0
    #DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_FLMM_PASPACE  +0x0
    #DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI               +0x0
    # --- --- --- --- --- --- --- --- --- --- --- --- ---
    $ev_string .= &format_execution_view( "DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_MMIPOOL",
                                          '+0x0', undef, ["* (DYNAMICCACHEABLEZI_C_MMIPOOL)", "* (VIDEOPOOL_C)"]); 
                                          # we don't support video_standalone in NOR so put VIDEOPOOL_C in asm pool just in case it's be turned on
    if ((&sysUtil::is_arm9($bb) == 1) or (&sysUtil::is_arm11($bb) == 1))
    {
        $ev_string .= &format_execution_view( "DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_FLMM_PASPACE", 
                                          '+0x0', undef, ["* (FLMM_PASPACE)"] );
    }
    $ev_string .= &format_execution_view( "DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI", 
                                          '+0x0', undef,["* (DYNAMICCACHEABLEZI_C)"]);
    $g_region_before_cached_dummy_end = "DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI";
    # --- --- --- --- --- --- --- --- --- --- --- --- ---
    ### Smart Phone MD/AP-only load requires RAM disk
    my $nand_support = (defined &$feature_query_function_ptr('nand_support')) ? &$feature_query_function_ptr('nand_support') : 'FALSE';
    my $system_drive_on_nand = (defined &$feature_query_function_ptr('system_drive_on_nand')) ? &$feature_query_function_ptr('system_drive_on_nand') : 'FALSE';
    
    my $ram_disk_size = 0;
    if (&FileInfo::is("FS_RAMDISK", "TRUE"))
    {
        $ram_disk_size = 0x40000; #256KB
    }
    ### Calculate start addresses
    my ($cached_dummy_end_start_address, $jblend_ram_start_address, $cached_dummy_end_start_address_val);
    my $j2me_support = &$feature_query_function_ptr('j2me_support');
    my $mode = &$feature_query_function_ptr('MODE');
    my ($region_size_tx, $region_size_rx) = &sysUtil::DSPTXRX_query_length($bb, $mode);
    my ($dsp_sharemem_size, $mcu_c_dsp_c_len, $mcu_c_dsp_nc_len, $mcu_nc_dsp_c_len, $mcu_nc_dsp_nc_len) = &DSP_SHAREMEM_query_length($bb);
    $ram_base = 0x0 if($ram_base =~/\+/); # assume $ram_size;
    $cached_dummy_end_start_address_val = $ram_base + $ram_size - $region_size_tx - $region_size_rx - $dsp_sharemem_size;
    my $dsp_sharemem_offset = $cached_dummy_end_start_address_val;
    if(defined &Query_EXTSRAM_PAGETABLE_SupportBB($bb))
    {
        $cached_dummy_end_start_address_val -=&Query_EXTSRAM_PAGETABLE_SupportBB($bb);
    }
    my $extsram_Tmp_Page_Table_Base = $cached_dummy_end_start_address_val;
    
    if (defined $j2me_support and $j2me_support =~ /JBLENDIA/)
    {
         $cached_dummy_end_start_address_val -= (128*1024);
         $jblend_ram_start_address = &CommonUtil::Dec2Hex($cached_dummy_end_start_address_val | 0xF0000000);
    }
    $cached_dummy_end_start_address_val -= $ram_disk_size;
         
    my $boot_cert = &$feature_query_function_ptr('boot_cert_support');
    my $nBOOT_CERT_Size = 0;
    if(&is_SINGLE($feature_query_function_ptr) and ($boot_cert ne 'FALSE' and $boot_cert ne 'NONE'))
    {
        $nBOOT_CERT_Size = 4*1024;
    }
    my $cached_dummy_end_skip_for_zimage = (hex($decomp_size_str)==0) ? (0) : (hex($decomp_size_str)+4);
    $cached_dummy_end_start_address = sprintf("0x%08x", (($cached_dummy_end_start_address_val - $cached_dummy_end_skip_for_zimage -  $nBOOT_CERT_Size) | 0xF0000000));
    
    
    $ev_string .= &format_execution_view( "CACHED_DUMMY_END",
                                          $cached_dummy_end_start_address,
                                          undef,
                                          ["bootarm_rvct.obj (DUMMY_POOL)"]
                                        );
    
    ### Smart Phone MD/AP-only load requires RAM disk
    if ($ram_disk_size != 0)
    {
        my $ram_end = $cached_dummy_end_start_address_val;
        
    	my $extsram_fs_begin_addr = sprintf("0x%08x", $ram_end & (~0xF0000000));  # RAM disk can use AP address for Modem-only loads
    	my $extsram_fs_size = sprintf("0x%x", $ram_disk_size);
        $ev_string .= &format_execution_view( "EXTSRAM_FS",
                                          $extsram_fs_begin_addr,
                                          $extsram_fs_size,
                                          ["flash_mtd.ramdisk.obj (STATICRW , STATICCONST, STATICZI)"]
                                        );
    }
    $ev_string .= &app_feature_jblend( $jblend_ram_start_address );
    $ev_string .= &EXTSRAM_PAGETABLE_EV($bb, $extsram_Tmp_Page_Table_Base);
    $ev_string .= &DSP_SHAREMEM_EV( $bb, "EXTSRAM", $dsp_sharemem_offset, $mcu_c_dsp_c_len, $mcu_c_dsp_nc_len, $mcu_nc_dsp_c_len, $mcu_nc_dsp_nc_len );
    $ev_string .= &DSPTXRX( $bb, "EXTSRAM", $ram_base, $ram_size , $region_size_tx, $region_size_rx );
    $ev_string .= &shouldbe_emptysection();
    return $ev_string;
}

#****************************************************************************
# subroutine:  NFB Layout :: PRIMARY ROM :: Exec View :: EXTSRAM Type 8 (ARM9 Only)
# input:       BB, RAM base, RAM size [val]
# remark:      include PRIMARY_EXTSRAM , PRIMARY_CACHED_EXTSRAM
#****************************************************************************
sub EXTSRAM_type_8
{
    my ($bb, $ev_baseaddr, $ram_size_value) = @_;

    # --- --- --- 
    my $ev_primary_cached = <<"__TEMPLATE";
         *config.a                   (+RW)
         *dsp_ram.a                  (+RW)
         *fs.a                       (+RW)
         *kal.a                      (+RW)
         *nucleus.a                  (+RW)
         *nucleus_int.a              (+RW)
         *nucleus_v2.a               (+RW)
         *nucleus_v2_int.a           (+RW)
         *sst.a                      (+RW)
         *sst_sec.a                  (+RW)
         *sss.a                      (+RW)
         *sss_rvct*.a                (+RW)
         *.l                           (+RW)

         *drv.a                      (+RW)
         *mc.a                       (+RW)
         *usb_driver.a               (+RW)
         *mm_comm.a                  (+RW)
         *mtd.a                      (+RW)
         *peripheral.a               (+RW)
         *drv_display.a              (+RW)
         *gfx_drv.a                  (+RW)
         *cipher.a                   (+RW)
         *drv_idp.a                  (+RW)
         *fdm.a                      (+RW)
         *tst.a                      (+RW)
          
; libs must be in primary ROM
         *gdi.a                      (+RW)
         *gdi_2.a                    (+RW)
         *media.a                    (+RW)
         *media_sec.a                (+RW)
         *verno.a                    (+RW)
         * (RELEASE_VERNO_RW, RELEASE_BRANCH_RW, BUILD_TIME_RW)
         *j2me_hi.a                  (+RW)
         *j2me_hi_rvct.a             (+RW)
         *gdi_arm.a                  (+RW)
         *ssf.a                      (+RW)
         
; init
         *init.a                     (+RW)
         *sys_drv.a                  (+RW)
         *sys_svc.a                  (+RW)
         
; hardware driver
         *bmt.a                      (+RW)

; Crypto, Image, and Graphics
         *gfx_core16.a               (+RW)
         *gfx_core32.a               (+RW)
         
; specific objects in custom.lib
; directory mcu/custom/system
         custom_config.obj             (+RW)
         custom_emi*.obj               (+RW)
         custom_flash.obj              (+RW)
         custom_jump_tbl.obj           (+RW)
         custom_util.obj               (+RW)
         custom_scatstruct.obj         (+RW)
         custom_fota.obj               (+RW)
         custom_img_config.obj         (+RW)
; directory mcu/custom/common/hal
         combo_flash_nor.obj           (+RW)
         combo_flash_init.obj          (+RW)
         custom_sfi.obj                (+RW)
; directory mcu/custom/drv/common
         gpio_setting.obj              (+RW)
; directory mcu/custom/drv/misc_drv
         adc_channel.obj               (+RW)
         alerter_tone.obj              (+RW)
         alerterdrv.obj                (+RW)
         auxmain.obj                   (+RW)
         chr_parameter.obj             (+RW)
         custom_drv_init.obj           (+RW)
         custom_equipment.obj          (+RW)
         custom_hw_default.obj         (+RW)
         eint_def.obj                  (+RW)
         exif_custom.obj               (+RW)
         gpio_drv.obj                  (+RW)
         irda_custom.obj               (+RW)
         kbdmain_joystick.obj          (+RW)
         keypad_def.obj                (+RW)
         msdc_custom.obj               (+RW)
         pmic_custom.obj               (+RW)
         pwmdrv.obj                    (+RW)
         touch_panel_custom.obj        (+RW)
         touch_panel_spi.obj           (+RW)
         touchpad.obj                  (+RW)
         touchpad_keydef.obj           (+RW)
         tv_custom.obj                 (+RW)
         uart_def.obj                  (+RW)
         uem_gpio.obj                  (+RW)
         usb_custom.obj                (+RW)
         usb_host_ms_custom.obj        (+RW)
; directory mcu/custom/drv/misc_drv/BB_folder/codegen
         adc_var.obj                   (+RW)
         eint_var.obj                  (+RW)
         gpio_var.obj                  (+RW)
         uem_drv.obj                   (+RW)
         pmic_drv.obj                  (+RW)
; directory mcu/custom/drv/LCD
         lcd.obj                       (+RW)
; directory mcu/custom/drv/Ext_Charger
         Ext_Charger_*.obj             (+RW)
; directory mcu/custom/drv/Ext_Cable_Detection
         Ext_Cable_*.obj               (+RW)
; directory mcu/custom/drv/sp_fac_det
         cs_fac_det*.obj               (+RW)
         
; specific objects in mmiresource.lib
         custNFBProgressImg.obj        (+RW)
         gui_wrapper.obj               (+RW)
         
; specific objects in media_app.lib
         mdi_tv.obj                    (+RW)

         bl_SC624.obj                  (+RW)
         mmi_create.obj                (+RW)
         mmi_main.obj                  (+RW)
         ws_fs_api.obj                 (+RW)
         ext_drv_assert_hdlr_if.obj    (+RW)

         *                             (PRIMARY_RW)

; specific objects in che.lib
         md5_engine.obj                (+RW)
__TEMPLATE
    # --- --- --- 
    my @objects_primary_cached  = split("\n", $ev_primary_cached);
    map { s/^\s+//; } @objects_primary_cached;
    # --- --- --- 
    my $ev_string;
    $ev_string .= &format_execution_view( "PRIMARY_CACHED_EXTSRAM", "+0xF0001000", undef, \@objects_primary_cached);
    $ev_string .= &app_feature_res_prot($bb);
    return $ev_string;
}

#****************************************************************************
# subroutine:  NFB Layout :: SECONDARY ROM :: Exec View :: EXTSRAM Type 9 (ARM9 Only)
# input:       BB, RAM base, RAM size [val]
# remark:      include SECODARY_EXTSRAM, PAGE_TABLE, ...
#****************************************************************************
sub EXTSRAM_type_9
{
    my ($bb, $ev_baseaddr, $ram_size, $cached_dummy_end_start_address_val, $multibin, $security) = @_;
    my $ev_string;
    
    # --- --- --- --- ---
    ### For COSMOS_MMI, MED pool in DYNAMIC_CACHEABLE_DEFAULT_NONCACHEABLE_ZI region will be merged to ASM pool in DYNAMIC_CACHEABLE_DEFAULT_CACHEABLE_ZI region
    ### So DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI* becomes MCU/DSP share region
    my $dsp_solution = &$feature_query_function_ptr('dsp_solution');
    my $mmi_version = &$feature_query_function_ptr('mmi_version');
    my $video_standalone = &$feature_query_function_ptr('VIDEO_STANDALONE_MEMORY');
    my $is_DUALMACDSP = (defined $dsp_solution and $dsp_solution eq 'DUALMACDSP') ? 1 : 0;
    my $strDSP_SizeLimit = '0xC800000 ; DSP SizeLimit=200MB';
    my $is_FLMM = (&sysUtil::is_arm9($bb)==1 or &sysUtil::is_arm11($bb)==1) ? 1 : 0;
    my $is_video_standalone = defined $video_standalone and $video_standalone eq 'TRUE' ? 1 : 0;
    &sysUtil::sysgen_die("Unsupported combination: nonCOSMOS+VIDEO_STANDALONE_MEMORY=TRUE\n", __FILE__, __LINE__) if ($mmi_version ne 'COSMOS_MMI' and $is_video_standalone);
    my $strHeadRegion = $security eq 'TRUE' ? 'ROM_TAIL' : 'ROM2';
    if ($is_DUALMACDSP)
    {
        # --- --- --- --- --- --- --- --- --- --- --- --- ---          VIDEO_STANDALONE  |  Others
        # DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_VIDEOPOOL     256K aligned 200MB|  256K aligned
        # DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_MMIPOOL       256K aligned      |                200MB
        # DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_FLMM_PASPACE                    |                200MB
        # DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI                                 |  256K aligned
        # --- --- --- --- --- --- --- --- --- --- --- --- ---
        $ev_string .= &format_execution_view( "DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_VIDEOPOOL",
                                              "SetAddress(ImageLimit($strHeadRegion)+0xF0000000, ALIGNMENT_256KB) ABSOLUTE",
                                              $is_video_standalone ? $strDSP_SizeLimit : undef,
                                              ["* (VIDEOPOOL_C)"]
                                                );
        $strHeadRegion = 'DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_VIDEOPOOL';
        
        $ev_string .= ";if MMIPOOL or FLMM_PASPACE's size exceeds 200MB, please turn on feature option: VIDEO_STANDALONE_MEMORY=TRUE\n" if($is_video_standalone==0);
        $ev_string .= &format_execution_view( "DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_MMIPOOL",
                                          !$is_video_standalone ? '+0x0' : "SetAddress(ImageLimit($strHeadRegion), ALIGNMENT_256KB) ABSOLUTE",
                                          (!$is_video_standalone && !$is_FLMM) ? $strDSP_SizeLimit : undef,
                                          ["* (DYNAMICCACHEABLEZI_C_MMIPOOL)"]
                                        );
        $strHeadRegion = 'DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_MMIPOOL';
        if($is_FLMM)
        {
            $ev_string .= &format_execution_view( "DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_FLMM_PASPACE", 
                                              "+0x0", 
                                              !$is_video_standalone ? $strDSP_SizeLimit : undef, 
                                              ["* (FLMM_PASPACE)"] );
            $strHeadRegion = 'DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_FLMM_PASPACE';
        }
        $ev_string .= &format_execution_view( "DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI",
                                              $is_video_standalone ? '+0x0' : "SetAddress(ImageLimit($strHeadRegion), ALIGNMENT_256KB) ABSOLUTE",
                                              undef,
                                              ["* (DYNAMICCACHEABLEZI_C)"]
                                            );
    }
    else
    {
        &sysUtil::sysgen_die("DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_VIDEOPOOL is unsupported under non-DUALMACDSP platform", __FILE__, __LINE__) if($is_video_standalone);
        # --- --- --- --- --- --- --- --- --- --- --- --- ---
        #DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_MMIPOOL       +0x1000 | 0xF0000000
        #DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_FLMM_PASPACE  +0x0
        #DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI               +0x0
        # --- --- --- --- --- --- --- --- --- --- --- --- ---
        $ev_string .= &format_execution_view( "DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_MMIPOOL",
                                          '+0xF0001000 ABSOLUTE', undef, ["* (DYNAMICCACHEABLEZI_C_MMIPOOL)"] );
        if($is_FLMM)
        {
            $ev_string .= &format_execution_view( "DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_FLMM_PASPACE", 
                                              "+0x0", undef, ["* (FLMM_PASPACE)"] );
        }
        $ev_string .= &format_execution_view( "DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI",
                                              '+0x0', undef, ["* (DYNAMICCACHEABLEZI_C)"]);
    }
    # --- --- --- --- DYNAMIC CACHEABLE DEFAULT NON-CACHEABLE --- --- --- ---
      
        # --- --- --- --- --- --- --- --- --- --- --- --- ---
       #DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI_MMIPOOL  +0x1000 ^ 0xF0000000
       #DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI          +0x0
       # --- --- --- --- --- --- --- --- --- --- --- --- ---
       $ev_string .= &format_execution_view( "DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI_MMIPOOL",
                                              "+0x10001000" . " ABSOLUTE", undef,
                                              ["med_main.obj (LARGEPOOL_ZI)",
                                               "* (DYNAMICCACHEABLEZI_NC_MMIPOOL)", ] );
       $ev_string .= &format_execution_view( "DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI",
                                              "+0x0", undef, ["* (DYNAMICCACHEABLEZI_NC)"]);
    
    
    # --- --- --- --- ---
    # Because DYNAMIC_CACHEABLE_DEFAULT_NONCACHEABLE_ZI does not exist in BASIC load and L1S load,
    # add 1MB/8MB offset to ensure 2-MAUI load view will not overlap with execution view
    my $secondary_extsram_zi_offset = "+0x1000";
    my $mode = &$feature_query_function_ptr('MODE');
    if (($mode eq "BASIC") or ($mode eq "L1S"))
    {
        $secondary_extsram_zi_offset = "+0x800000";
    }
    $ev_string .= &format_execution_view( "SECONDARY_EXTSRAM_ZI",
                                          $secondary_extsram_zi_offset, undef,
                                          ["*deniro.a (+ZI)",
                                           "*fs_fig.a (+ZI)",
                                           "*verno.a  (+ZI)",
                                           "; Others that voluntarily NOT cached",
                                           "* (NONCACHEDZI)",
                                          ]
                                        );
    # --- --- --- --- ---
    $ev_string .= &format_execution_view( "SECONDARY_EXTSRAM_RW",
                                          "+0x0", undef,
                                          ["*deniro.a (+RW)",
                                           "*fs_fig.a (+RW)",
                                           "; Others that voluntarily NOT cached",
                                           "* (NONCACHEDRW)",
                                          ]
                                        );
    $ev_string .= &format_execution_view( "DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_RW",
                                          "+0x1000", undef,
                                          ["* (DYNAMICCACHEABLERW_NC)"]
                                        );
    # SECONDARY_EXTSRAM must be the last region before PAGE_TABLE
    $ev_string .= &format_execution_view( "PAGE_TABLE",
                                          "+0xF0001000", undef,
                                          ["cache.obj (PAGETABLE)",
                                           "* (PAGETABLE)",
                                          ]
                                        );
    $ev_string .= &CACHED_EXTSRAM_EV("+0x0");
    $ev_string .= &format_execution_view( "CACHED_EXTSRAM_NVRAM_LTABLE",
                                          "+0x00", undef,
                                          ["* (_nvram_ltable)",
                                           "* (_indirect_init)",
                                           "* (_fs_filetable)",
                                           "* (_nvram_callback_tbl)",]
                                         );
    $ev_string .= &app_feature_gadget("+0x00");
    $ev_string .= &format_execution_view( "DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_RW",
                                          "+0x1000", undef,
                                          ["* (DYNAMICCACHEABLERW_C)"]
                                        );

    # --- --- --- --- ---
	my $extsram_base_value = 0;
	my($nDummyEndBase, $nOffset, $regioninfo_ref) = &GetDummyEnd($bb, $ram_size);
    
    my $demand_paging_version = &$feature_query_function_ptr('demand_paging_version');
    my $L6478E = (!defined $demand_paging_version or $demand_paging_version ne 'DPV2') ? "L6478E.obj (L6478E_high)" :"";
    $ev_string .= &format_execution_view( "CACHED_DUMMY_END",
                                          &CommonUtil::Dec2Hex($nDummyEndBase | 0xF0000000),
                                          undef,
                                          ["bootarm_rvct.obj (DUMMY_POOL)",
                                          $L6478E,]
                                        );
    $ev_string .= &app_feature_jblend( &CommonUtil::Dec2Hex(0xF0000000 |($ram_size - $regioninfo_ref->{"JBLEND"}[1])) );
    $ev_string .= &EXTSRAM_PAGETABLE_EV($bb, $ram_size - $regioninfo_ref->{"EXTSRAM_TMPPAGETABLE"}[1]);
    my ($dsp_sharemem_size, $mcu_c_dsp_c_len, $mcu_c_dsp_nc_len, $mcu_nc_dsp_c_len, $mcu_nc_dsp_nc_len) = &DSP_SHAREMEM_query_length($bb);
    $ev_string .= &DSP_SHAREMEM_EV( $bb, "SECONDARY_EXTSRAM", $ram_size-$regioninfo_ref->{"SHAREMEM"}[1], $mcu_c_dsp_c_len, $mcu_c_dsp_nc_len, $mcu_nc_dsp_c_len, $mcu_nc_dsp_nc_len );
    my ($region_size_tx, $region_size_rx) = &sysUtil::DSPTXRX_query_length($bb, $mode);
    $ev_string .= &DSPTXRX( $bb, "SECONDARY_EXTSRAM", $extsram_base_value, $ram_size , $region_size_tx, $region_size_rx );
    $ev_string .= &DSP_MT6256_EV( $bb, "SECONDARY_EXTSRAM", $dsp_solution, $ram_size );
    $ev_string .= &shouldbe_emptysection();
    return $ev_string;
}

#****************************************************************************
# subroutine:  NFB Layout :: ROM :: Exec View :: EXTSRAM :: LARGEPOOL
# input:       BB , LargePool Base Address [string]
#****************************************************************************
sub LARGEPOOL_NFB
{
    my ($bb, $ev_regionname, $ev_baseaddr) = @_;
    my $largepool_tempC = <<"__LARGEPOOLTEMPLATE";
    $ev_regionname $ev_baseaddr
    {
; For MT6235, MT6235B, MT6236, MT6236B projects, app-based ASM always at first due to Java FBBR, med_main.obj is put in Cacheable region
         app_mem.obj (LARGEPOOL_FIRST_ZI)
         ScrMemMgr.obj (LARGEPOOL_ZI)
         j2me_custom_resource.obj (LARGEPOOL_ZI)
;         med_main.obj (LARGEPOOL_ZI)
         ResMemMgr.obj (LARGEPOOL_ZI)
         gui_effect_oem.obj (LARGEPOOL_ZI)
    }
__LARGEPOOLTEMPLATE
    my %BBtbl =
       (        
                'MT6235'  => $largepool_tempC,
                'MT6235B' => $largepool_tempC,
                'MT6236'  => $largepool_tempC,
                'MT6236B' => $largepool_tempC,
                'MT6921'  => $largepool_tempC,
                'MT6268'  => $largepool_tempC,
                'MT6276'  => $largepool_tempC,
                'MT6255'  => $largepool_tempC,
                'MT6922'  => $largepool_tempC,
       );
       #map {print $_, "\n";} keys %BBtbl;
    &sysUtil::sysgen_die("tools/scatGenLib.pl: unsupported $bb!", __FILE__, __LINE__) if not exists $BBtbl{$bb}; 
    # --- --- --- 
    return $BBtbl{$bb};
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: EXTSRAM :: SINGLE_BANK_CODE
# input:       BB , SINGLE_BANK_CODE Base Address [string]
#****************************************************************************
sub SINGLE_BANK_CODE
{
    my ($bb, $ev_regionname, $ev_baseaddr, $ev_size) = @_;
    # SINGLE_BANK_CODE execution view is optional 
    my $esb = &$feature_query_function_ptr('enhanced_single_bank_nor_flash_support');
    return undef unless(defined $esb and (1 != &sysUtil::is_XIP_Shadowing($bb)));
    return undef unless($esb eq 'TRUE');
    # --- --- --- 
    my $sbcode_tempA = <<"__SBNORFLASHTEMPLATE";
    $ev_regionname $ev_baseaddr $ev_size
    {
;for single bank support , certain following code need to be called by sleep manager
         ex_hdlr_rvct.obj (SNORCODE,+First)
         * (SNORCODE)
         * (SNORCONST)
    }
__SBNORFLASHTEMPLATE
    my $sbcode_tempD = <<"__SBNORFLASHTEMPLATE";
    $ev_regionname $ev_baseaddr $ev_size
    {
;for single bank support , certain following code need to be called by sleep manager
         * (SNORCODE)
         * (SNORCONST)
         uread4.o (+RO-CODE, +RO-DATA)
         uwrite4.o (+RO-CODE, +RO-DATA)
    }
__SBNORFLASHTEMPLATE
    # --- --- --- 
    my %BBtbl =
       (        'MT6235'  => $sbcode_tempD,
                'MT6235B' => $sbcode_tempD,
                'MT6236'  => $sbcode_tempD,
                'MT6236B' => $sbcode_tempD,
                'MT6921'  => $sbcode_tempD,
                'MT6253'  => $sbcode_tempA,
                'MT6253E' => $sbcode_tempA,
                'MT6253L' => $sbcode_tempA,
                'MT6252H' => $sbcode_tempA,
                'MT6252'  => $sbcode_tempA,
                'MT6251'  => $sbcode_tempA,
                'MT6255'  => $sbcode_tempD,
                'MT6280'  => $sbcode_tempA,
                'MT6922'  => $sbcode_tempD,
                'MT6250'  => $sbcode_tempA,                
       );
       #map {print $_, "\n";} keys %BBtbl;
    &sysUtil::sysgen_die("tools/scatGenLib.pl: Unsupported Feature Combination ESB on $bb!", __FILE__, __LINE__) if not exists $BBtbl{$bb}; 
    # --- --- --- 
    # +First but not present will make basic and l1s load build failure
    my $mode = &$feature_query_function_ptr('MODE');
    if (defined $mode)
    {
        if ($mode eq "BASIC" or $mode eq "L1S")
        {
           $BBtbl{$bb} =~ s/,\+First\)/\)/g;
        }
    }
    # --- --- --- 
    return $BBtbl{$bb};
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: EXTSRAM :: LARGEPOOL
# input:       BB , LargePool Base Address [string]
#****************************************************************************
sub LARGEPOOL
{
    my ($bb, $ev_regionname, $ev_baseaddr, $ev_size) = @_;

    my $largepool_tempB = <<"__LARGEPOOLTEMPLATE";
    $ev_regionname $ev_baseaddr $ev_size
    {
; app-based ASM always at first due to Java FBBR
         app_mem.obj (LARGEPOOL_FIRST_ZI)
         ScrMemMgr.obj (LARGEPOOL_ZI)
         j2me_custom_resource.obj (LARGEPOOL_ZI)
         med_main.obj (LARGEPOOL_ZI)
    }
__LARGEPOOLTEMPLATE
    my $largepool_tempD = <<"__LARGEPOOLTEMPLATE";
    $ev_regionname $ev_baseaddr $ev_size
    {
; For MT6235, MT6235B, MT6236, MT6236B projects, app-based ASM always at first due to Java FBBR
         app_mem.obj (LARGEPOOL_FIRST_ZI)
         j2me_custom_resource.obj (LARGEPOOL_ZI)
;         med_main.obj (LARGEPOOL_ZI)
         ScrMemMgr.obj (LARGEPOOL_ZI)
         gui_effect_oem.obj (LARGEPOOL_ZI)
    }
__LARGEPOOLTEMPLATE

    my %BBtbl =
       (        'MT6235'  => $largepool_tempD,
                'MT6235B' => $largepool_tempD,
                'MT6236'  => $largepool_tempD,
                'MT6236B' => $largepool_tempD,
                'MT6921'  => $largepool_tempD,
                'MT6253'  => $largepool_tempB,                
                'MT6516'  => $largepool_tempB,
       );
       #map {print $_, "\n";} keys %BBtbl;
    &sysUtil::sysgen_die("tools/scatGenLib.pl: unsupported $bb!", __FILE__, __LINE__) if not exists $BBtbl{$bb}; 
    # --- --- --- 
    # +First but not present will make basic and l1s load build failure
    my $mode = &$feature_query_function_ptr('MODE');
    if (defined $mode)
    {
        if ($mode eq "BASIC" or $mode eq "L1S")
        {
           $BBtbl{$bb} =~ s/,\+First\)/\)/g;
        }
    }
    # --- --- --- 
    return $BBtbl{$bb};
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: EXTSRAM :: jblend
# input:       None
#****************************************************************************
sub app_feature_jblend
{
    my ($start_address) = @_;
    my $j2me_support = &$feature_query_function_ptr('j2me_support');
    if (defined $j2me_support and $j2me_support =~ /JBLENDIA/)
    {
        return &format_execution_view( "jblend_ram", $start_address, "0x20000", ["*jblend_*.o (+RW, +ZI)"]);
    }
    return '';
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: EXTSRAM :: EXTSRAM_GADGET
# input:       None
#****************************************************************************
sub app_feature_gadget
{
    my ($start_address) = @_;
    return &format_execution_view( "EXTSRAM_GADGET",
                                       $start_address,
                                       undef,
                                       ["*gadget_adp.a (+RW, +ZI)",
                                        "*gadget_lib.a (+RW, +ZI)",
                                        "*               (EXTSRAM_GADGET_RW, EXTSRAM_GADGET_ZI)",
                                       ]
                                     );
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: EXTSRAM :: EXTSRAM_PROTECTED_RES
# input:       RamAddress
# output:      
#****************************************************************************
sub app_feature_res_prot
{
	my ($bb) = @_;
    my $res_prot = &$feature_query_function_ptr('res_prot');
    my $nfb_or_emb;
    if (defined &$feature_query_function_ptr('nand_flash_booting') and &$feature_query_function_ptr('nand_flash_booting') ne 'NONE')
    {
    	  $nfb_or_emb = &$feature_query_function_ptr('nand_flash_booting');
    }
    elsif (defined &$feature_query_function_ptr('emmc_booting') and &$feature_query_function_ptr('emmc_booting') ne 'NONE')
    {
    	  $nfb_or_emb = &$feature_query_function_ptr('emmc_booting');
    }
    else
    {
    	  $nfb_or_emb = 'NONE';
    }
    my $name_str;
    if ($bb eq 'MT6251')
    {
    	  $name_str = "INTSRAM_PROTECTED_RES";
    }
    elsif ((&sysUtil::is_arm9($bb) == 1) or (&sysUtil::is_arm11($bb) == 1))
    {
    	  if (defined $nfb_or_emb and $nfb_or_emb ne 'NONE')
    	  {
            $name_str = "PRIMARY_CACHED_EXTSRAM_PROTECTED_RES";
        }
        else
        {
            $name_str = "CACHED_EXTSRAM_PROTECTED_RES";
        }
    }
    else
    {
    	  $name_str = "EXTSRAM_PROTECTED_RES";
    }
    if (defined $res_prot and $res_prot eq 'TRUE')
    {
        return &format_execution_view( $name_str,
                                       "+0x00",
                                       undef,
                                       ["* (PROTECTED_RES_HEAD, +First)",
                                        "* (PROTECTED_RES)",
                                        "* (PROTECTED_RES_TAIL, +Last)",
                                       ]
                                     );
    }
    return '';
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: EXTSRAM :: SHOULDBE_EMPTYSECTION
# input:       RamAddress
# output:      
#****************************************************************************
sub shouldbe_emptysection
{
    ### WISE MMI will use thread-unsafe APIs such as strtok, and it cannot be put in SHOULDBE_EMPTYSECTION
    if (&$feature_query_function_ptr('mmi_version') eq 'WISDOM_MMI')
    {
    	   return;
    }
	   my $template = <<"__TEMPLATE";
    ; define an empty section to detect unsafe APIs in link time
    SHOULDBE_EMPTYSECTION +0 0x0
    {
        armlibc_rvct.obj (SHOULD_NOT_USED_FUNCTION)
        armlibc_rvct_heap.obj (SHOULD_NOT_USED_FUNCTION)
        armlibc_rvct_io.obj (SHOULD_NOT_USED_FUNCTION)
        syscomp_config.obj (SHOULD_NOT_USED_RODATA)
    }
__TEMPLATE
    return $template;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: ROM :: Primary MAUI
# input:       BB
# output:      
#****************************************************************************
sub app_feature_clib_rom
{
    my $standard_c_or_all .=<<"__TEMPLATE";
         \"*armlib/*.l\"                 (+RO)
         \"*cpplib/*.l\"                 (+RO)
         *armlib/*.l                   (+RO)
         *cpplib/*.l                   (+RO)
         *armlib*                       (+RO-CODE, +RO-DATA)
         *cpplib*                       (+RO-CODE, +RO-DATA)
__TEMPLATE
        chomp $standard_c_or_all;

    my $rom_temp = <<"__TEMPLATE__";
; C++ related input sections
         cpp_initialise.o              (+RO-CODE, +RO-DATA)
         cpp_finalise.o                (+RO-CODE, +RO-DATA)
         *                             (C\$\$pi_ctorvec)
         *                             (C\$\$pi_dtorvec)
         *                             (C\$\$ddtorvec)
         *                             (C\$\$ctor)
         *                             (C\$\$dtor)
; for RVCT C++ initialize
         init_aeabi.o                  (+RO-CODE, +RO-DATA)
         *                             (.init_array)
         *                             (.ARM.exidx)
         
$standard_c_or_all
__TEMPLATE__

    return $rom_temp;
}
 
#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: ROM :: Primary MAUI
# input:       BB
# output:      
#****************************************************************************
sub app_feature_pmaui_rom
{
    my ($bb) = @_;

    # --- --- --- 
    my $template_A = << "__RTOSLIBS_A";
         *nucleus.a                  (+RO)
         *nucleus_int.a              (+RO)
         *nucleus_debug.a            (+RO)

; moved from ITCM
         tct.obj                       (+RO)
__RTOSLIBS_A
    # --- --- --- 
    my $template_C = << "__RTOSLIBS_C";
         *nucleus.a                  (+RO)
         *nucleus_int.a              (+RO)
         *nucleus_debug.a            (+RO)
         *nucleus_v2.a               (+RO)
         *nucleus_v2_int.a           (+RO)
         *nucleus_v2_debug.a         (+RO)
         *nucleus_v2_ctrl_code.a     (+RO)

;nucleus_ctrl_code.lib
         csc.obj                       (+RO)
         tcc.obj                       (+RO)
         tms.obj                       (+RO)
         evc.obj                       (+RO)
         quc.obj                       (+RO)
         pmc.obj                       (+RO)
         smc.obj                       (+RO)

; moved from ITCM
         tmt.obj                       (+RO)
         tct.obj                       (+RO)
         stack_timer.obj               (+RO)
         data_buff_pool.obj            (+RO)
         kal_nucleus_timer.obj         (+RO)
__RTOSLIBS_C
    # --- --- --- 
    my $template_D = << "__RTOSLIBS_D";
         *nucleus.a                  (+RO)
         *nucleus_int.a              (+RO)
         *nucleus_debug.a            (+RO)
         *nucleus_v2.a               (+RO)
         *nucleus_v2_int.a           (+RO)
         *nucleus_v2_debug.a         (+RO)
         *nucleus_v2_ctrl_code.a     (+RO)

;nucleus_ctrl_code.lib
         csc.obj                       (+RO)
         tcc.obj                       (+RO)
         tms.obj                       (+RO)
         evc.obj                       (+RO)
         quc.obj                       (+RO)
         pmc.obj                       (+RO)
         smc.obj                       (+RO)

; moved from ITCM
         tct.obj                       (+RO)
         stack_timer.obj               (+RO)
         data_buff_pool.obj            (+RO)
         kal_nucleus_timer.obj         (+RO)
__RTOSLIBS_D
    # --- --- --- 
    my %BBtbl =
       (        'MT6235'  => $template_C,
                'MT6235B' => $template_C,
                'MT6236'  => $template_C,
                'MT6236B' => $template_C,
                'MT6921'  => $template_C,
                'MT6253'  => $template_D,
                'MT6516'  => $template_A,
                'MT6253E' => $template_D,
                'MT6253L' => $template_D,
                'MT6252'  => $template_D,
                'MT6280'  => $template_D,
                'MT6252H' => $template_D,
                'MT6268'  => $template_C,
                'MT6276'  => $template_C,
                'MT6251'  => $template_D,
                'MT6256'  => $template_C,
                'MT6255'  => $template_C,
                'MT6922'  => $template_C,
                'MT6250'  => $template_D,                
       );
       #map {print $_, "\n";} keys %BBtbl;
    #&sysUtil::sysgen_die("tools/scatGenLib.pl: unsupported $bb!", __FILE__, __LINE__) if not exists $BBtbl{$bb}; 
    my $rtos_libs = $BBtbl{$bb};
    chomp $rtos_libs;

    # --- --- --- 
    # Determine ZIMAGE
    my $zimage = &$feature_query_function_ptr('zimage_support');
    my $mmi_version = &$feature_query_function_ptr('mmi_version');
    my ($l1_temp, $img_med_fs_temp, $gui_wrapper_temp);
    my $board_ver = &$feature_query_function_ptr('BOARD_VER');
    my $flavor = &$feature_query_function_ptr('FLAVOR');
    my $MT6276_vs_PMdemo;

    if((defined $board_ver and $board_ver eq "VICTOR56_DEMO_BB") and 
    (defined $flavor and $flavor eq "PM_DEMO" or $flavor eq "PM_DEMO_MC3230"))
    {    
        $MT6276_vs_PMdemo = "bn_lib.obj                    (+RO-CODE, +RO-DATA)";
    }
    else
    {
        $MT6276_vs_PMdemo = "bn_lib.obj                    (+RO)";
    }
    if (($zimage eq 'TRUE') and ($mmi_version eq 'NEPTUNE_MMI'))
    {
    	$l1_temp .= <<"__TEMPLATE";
         l1d_data.obj                  (+RO) 
         m11007.obj                    (+RO)
         m12100.obj                    (+RO)
         l1sm.obj                      (+RO) 
         l1csm.obj                     (+RO)
         m12171.obj                    (+RO)
__TEMPLATE

        $img_med_fs_temp .= <<"__TEMPLATE";
         camera_process_v2.obj         (+RO)
         visualhisr.obj                (+RO)
         visual_comm.obj               (+RO)
__TEMPLATE
    }
    elsif ($zimage eq 'TRUE')
    {
        my $finger_touch_support = &$feature_query_function_ptr('finger_touch_support');
        my $semicolon;
        if($bb eq 'MT6252' || $bb eq 'MT6250' and $finger_touch_support eq 'FTE')
        {
            $semicolon = ';';
        }
    	$l1_temp .= <<"__TEMPLATE";
         l1d_data.obj                  (+RO) 
         m11007.obj                    (+RO)
         $semicolon m12100.obj                    (+RO)
         $semicolon l1sm.obj                      (+RO) 
         $semicolon l1csm.obj                     (+RO)
         m12171.obj                    (+RO)
__TEMPLATE

        $img_med_fs_temp .= <<"__TEMPLATE";
         *gdi_2.a                    (+RO)
         *fs.a                       (+RO)
__TEMPLATE

        $gui_wrapper_temp .= <<"__TEMPLATE";
         gui_wrapper.obj               (+RO)
__TEMPLATE
    }
    else
    {
    	$l1_temp .= <<"__TEMPLATE";
         ; combine to gl1.lib + 
         *l1_classb_g2.a             (+RO)
         *l1_g2.a                    (+RO)
         *l1_classb_umts.a           (+RO)
         ; combine to gl1.lib -
         *gl1.a                      (+RO)
__TEMPLATE

        $img_med_fs_temp .= <<"__TEMPLATE";
         *gdi_2.a                    (+RO)
         *gfx_core16.a               (+RO)
         *gfx_core32.a               (+RO)
         *media.a                    (+RO)
         *media_sec.a                (+RO)
         *fs.a                       (+RO)
__TEMPLATE

        $gui_wrapper_temp .= <<"__TEMPLATE";
         gui_wrapper.obj               (+RO)
__TEMPLATE
    }
    chomp $l1_temp;
    chomp $img_med_fs_temp;
    chomp $gui_wrapper_temp;

    #--- --- ---
    my $template = <<"__TEMPLATE";
         Regioninit_ads.obj            (+RO-CODE)

         *bmt.a                      (+RO)
         *config.a                   (+RO)
         *drv.a                      (+RO)
         *mc.a                       (+RO)
         *usb_driver.a               (+RO)
         *mm_comm.a                  (+RO)
         *mtd.a                      (+RO)
         *peripheral.a               (+RO)
         *drv_display.a              (+RO)
         *gfx_drv.a                  (+RO)
         *cipher.a                   (+RO)
         *drv_idp.a                  (+RO)
         *fdm.a                      (+RO)
         *init.a                     (+RO)
         *sys_drv.a                  (+RO)
         *sys_svc.a                  (+RO)
         *kal.a                      (+RO)
$l1_temp
         *l1_ext.a                   (+RO)
         *sst.a                      (+RO)
         *sst_sec.a                  (+RO)
         *sss.a                      (+RO)
         *sss_rvct*.a                (+RO)
         *tst.a                      (+RO)
$rtos_libs

; libs must be in primary ROM
         *gdi.a                      (+RO)
$img_med_fs_temp
         *verno.a                    (+RO)
         *j2me_hi.a                  (+RO)
         *j2me_hi_rvct.a             (+RO)
         *gdi_arm.a                  (+RO)
         *dsp_ram.a                  (+RO)
         *ssf.a                      (+RO)

; specific objects in custom.lib
; because custom.lib (+RO) might be in 2-MAUI, specify (+RO-CODE, +RO-DATA) here to prevent link error
; directory mcu/custom/system
         custom_emi*.obj               (+RO-CODE, +RO-DATA)
         custom_config.obj             (+RO-CODE, +RO-DATA)
         custom_flash.obj              (+RO-CODE, +RO-DATA)
         custom_scatstruct.obj         (+RO-CODE, +RO-DATA)
         custom_jump_tbl.obj           (+RO-CODE, +RO-DATA)
         custom_util.obj               (+RO-CODE, +RO-DATA)
         custom_fota.obj               (+RO-CODE, +RO-DATA)
         custom_img_config.obj         (+RO-CODE, +RO-DATA)
; directory mcu/custom/common/hal
         combo_flash_nor.obj           (+RO-CODE, +RO-DATA)
         combo_flash_init.obj          (+RO-CODE, +RO-DATA)
         custom_sfi.obj                (+RO-CODE, +RO-DATA)
; directory mcu/custom/drv/common
         gpio_setting.obj              (+RO-CODE, +RO-DATA)
; directory mcu/custom/drv/misc_drv
         adc_channel.obj               (+RO-CODE, +RO-DATA)
         alerter_tone.obj              (+RO-CODE, +RO-DATA)
         alerterdrv.obj                (+RO-CODE, +RO-DATA)
         auxmain.obj                   (+RO-CODE, +RO-DATA)
         chr_parameter.obj             (+RO-CODE, +RO-DATA)
         custom_drv_init.obj           (+RO-CODE, +RO-DATA)
         custom_equipment.obj          (+RO-CODE, +RO-DATA)
         custom_hw_default.obj         (+RO-CODE, +RO-DATA)
         eint_def.obj                  (+RO-CODE, +RO-DATA)
         exif_custom.obj               (+RO-CODE, +RO-DATA)
         gpio_drv.obj                  (+RO-CODE, +RO-DATA)
         irda_custom.obj               (+RO-CODE, +RO-DATA)
         kbdmain_joystick.obj          (+RO-CODE, +RO-DATA)
         keypad_def.obj                (+RO-CODE, +RO-DATA)
         msdc_custom.obj               (+RO-CODE, +RO-DATA)
         pmic_custom.obj               (+RO-CODE, +RO-DATA)
         pwmdrv.obj                    (+RO-CODE, +RO-DATA)
         touch_panel_custom.obj        (+RO-CODE, +RO-DATA)
         touch_panel_spi.obj           (+RO-CODE, +RO-DATA)
         touchpad.obj                  (+RO-CODE, +RO-DATA)
         touchpad_keydef.obj           (+RO-CODE, +RO-DATA)
         tv_custom.obj                 (+RO-CODE, +RO-DATA)
         uart_def.obj                  (+RO-CODE, +RO-DATA)
         uem_gpio.obj                  (+RO-CODE, +RO-DATA)
         usb_custom.obj                (+RO-CODE, +RO-DATA)
         usb_host_ms_custom.obj        (+RO-CODE, +RO-DATA)
         pmu_custom.obj                (+RO-CODE, +RO-DATA)
; directory mcu/custom/drv/misc_drv/BB_folder/codegen
         adc_var.obj                   (+RO-CODE, +RO-DATA)
         eint_var.obj                  (+RO-CODE, +RO-DATA)
         gpio_var.obj                  (+RO-CODE, +RO-DATA)
         uem_drv.obj                   (+RO-CODE, +RO-DATA)
         pmic_drv.obj                  (+RO-CODE, +RO-DATA)
; directory mcu/custom/drv/LCD
         lcd.obj                       (+RO-CODE, +RO-DATA)
; directory mcu/custom/drv/Ext_Drv_Assert_Hdlr
         ext_drv_assert_hdlr_if.obj    (+RO-CODE, +RO-DATA)
; directory mcu/custom/drv/Ext_Charger
         Ext_Charger_*.obj             (+RO-CODE, +RO-DATA)
; directory mcu/custom/drv/Ext_Cable_Detection
         Ext_Cable_*.obj               (+RO-CODE, +RO-DATA)
; directory mcu/custom/drv/sp_fac_det
         cs_fac_det*.obj               (+RO-CODE, +RO-DATA)

; specific objects in mmiresource.lib
         custNFBProgressImg.obj        (+RO)
$gui_wrapper_temp

; specific objects in media_app.lib
         mdi_tv.obj                    (+RO)

; specific objects in bcsi.lib ; C++ const data init
         MiscUtils.obj                 (+RO)

         ul1sm.obj                     (+RO)

         bl_SC624.obj                  (+RO)
         mmi_create.obj                (+RO)
         mmi_main.obj                  (+RO)
         ws_fs_api.obj                 (+RO)
         rc4_engine.obj                (+RO)

; for MT6276
$MT6276_vs_PMdemo
         X509.obj                      (+RO)
         *drv_sec.a                  (+RO)
         ostd.obj                      (+RO)
         wdata.obj                     (+RO)

; for USB Boot Trace
        otg.obj                  (+RO-CODE, +RO-DATA)
        usb.obj                  (+RO-CODE, +RO-DATA)
        usbacm_adap.obj          (+RO-CODE, +RO-DATA)
        usbacm_drv.obj           (+RO-CODE, +RO-DATA)
        usbd.obj                 (+RO-CODE, +RO-DATA)
        usbms_adap.obj           (+RO-CODE, +RO-DATA)
        usbms_drv.obj            (+RO-CODE, +RO-DATA)
        usbms_state.obj          (+RO-CODE, +RO-DATA)
        usb_adap.obj             (+RO-CODE, +RO-DATA)
        usb_debug_tool.obj       (+RO-CODE, +RO-DATA)
        usb_host_acm_drv.obj     (+RO-CODE, +RO-DATA)
        usb_host_default_drv.obj (+RO-CODE, +RO-DATA)
        usb_host_ms_adap.obj     (+RO-CODE, +RO-DATA)
        usb_host_ms_drv.obj      (+RO-CODE, +RO-DATA)
        usb_host_ms_state.obj    (+RO-CODE, +RO-DATA)
        usb_mode.obj             (+RO-CODE, +RO-DATA)
        usb_resource.obj         (+RO-CODE, +RO-DATA)
        usb_task.obj             (+RO-CODE, +RO-DATA)
; for hwlzma
        *sys_sec.a                  (+RO)
        *sleep_drv.a                (+RO)

        *                       (PRIMARY_ROCODE, PRIMARY_RODATA)

; specific objects in che.lib
         md5_engine.obj                (+RO)
__TEMPLATE
    return $template;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM2 :: Exec View :: ROM :: Secondary MAUI
# input:       BB
# output:      
#****************************************************************************
sub app_feature_rom2
{
	my ($bb, $nfb_or_emb) = @_;
	
    # --- --- ---
    # Determine DPv2
    my $demand_paging_version = &$feature_query_function_ptr('demand_paging_version');
    my $rom2_temp;
    if (($nfb_or_emb eq 'ONDEMAND') and (defined $demand_paging_version) and ($demand_paging_version eq 'DPV2'))
    {#exception list
        my $VideoCodec = app_feature_rom2_video($bb);
        my $TDD128 = &$feature_query_function_ptr('L1_TDD128');
        my $board_ver = &$feature_query_function_ptr('BOARD_VER');
        my $flavor = &$feature_query_function_ptr('FLAVOR');
        if(defined $TDD128 and $TDD128 eq "TRUE")
        {
            my $TDD_string = <<"__TEMPLATE";
;L1_TDD128
         *uas.a (+RO)
         *ast_l1_ast2001.a (+RO)
         *ast_l1_ast3001.a (+RO)
         *fta.a (+RO)
__TEMPLATE
            $rom2_temp .= $TDD_string;
        }
        if(defined $board_ver and $board_ver eq "VICTOR56_DEMO_BB")
        {
        	 if(defined $flavor and $flavor eq "PM_DEMO" or $flavor eq "PM_DEMO_MC3230")
        	 {
        	  my $Victor56_demo_string = <<"__TEMPLATE";
;for VICTOR56_PM_DEMO
         *gadget_lib.a (+RO)
         *obigo03cstklib.a (+RO)
         *obigo03clib.a (+RO)
         *gadget_adp.a (+RO)
         *ossl_crypto.a (+RO)   
         *sdk_test.a (+RO)  
         *mre_engine.a (+RO)  
         *jal.a (+RO)
         *mre_custom.a (+RO)  
         *audio.a (+RO)        	
__TEMPLATE
           $rom2_temp .= $Victor56_demo_string;
           }
             
        }
        
        $rom2_temp .= <<"__TEMPLATE";
$VideoCodec
;misc
         hif.obj (+RO)
         tl1_m_l.obj (+RO)
         dcl_sim.obj (+RO)
         icc_sim_common_mtk.obj (+RO)
         icc_switchControl2.obj (+RO)
         MT6302_SPI.obj (+RO)
         ast_l1_trace_isr_level_1.obj (+RO)
         ast_l1_trace_isr_level_2.obj (+RO)
         ast_l1_trace_isr_level_3.obj (+RO)
         ast_l1_trace_task_level_1.obj (+RO)
         ast_l1_trace_task_level_3.obj (+RO)
         ll1_tl1_timing_sync_handler.obj (+RO)
         l4c_em.obj (+RO)
         ul2_em.obj (+RO)
         tl1_ll1.obj (+RO)
         tl1_m_t.obj (+RO)
         tl1_m_t_dms.obj (+RO)
         tl1_d_tl.obj (+RO)
         tl1_m_l_dms.obj (+RO)
         icc_switchControl_mtk_1.obj (+RO)
         vt_csr_if.obj (+RO)
         VT_CSR_Q.obj (+RO)
         VT_send_ilm.obj (+RO)
         data_module_mains.obj (+RO)
         rlp_l1ra_msg_hdlrs.obj (+RO)
         data_reset.obj (+RO)
         rlp_frame_hdlrs.obj (+RO)
         rlp_common_xid_proc.obj (+RO)
         rlp_timer_common.obj (+RO)
         rlp_common_proc.obj (+RO)
         rlp_frame_funcs.obj (+RO)
         l2_testloop_one.obj (+RO)
         pdcp.obj (+RO)
         cpdcp.obj (+RO)
         bigend.obj (+RO)
         rfc2507_lib.obj (+RO)
         rfc2507_lib_tcp.obj (+RO)
         rfc2507_lib_non_tcp.obj (+RO)
         ul2d_sigin.obj (+RO)
         icc_switchControl1.obj (+RO)
         icc_switchControl0.obj (+RO)
         icc_switchControl_mtk_0.obj (+RO)
         ll1_tl1_common.obj (+RO)
         ll1_tl1_hspa_gap_handler.obj (+RO)
         ll1_tl1_fach_gap_handler.obj (+RO)
         ll1_tl1_dch_gap_handler.obj (+RO)
         tl1_d_lh.obj (+RO)
         event_info_utility.obj (+RO)
         f8.obj (+RO)
         kasumi_opti.obj (+RO)
         uea2.obj (+RO)
         SNOW_3G_opti.obj (+RO)
         ll1_tl1_pch_gap_handler.obj (+RO)
         tl1_m_h.obj (+RO)
         tl1_d_hl.obj (+RO)
         tl1_main.obj (+RO)
         custom_sim_driver.obj (+RO)
         mt6302_custom.obj (+RO)
         usbvideo_drv.obj (+RO)
         usbvideo_state.obj (+RO)
         sensor_frame_rate_lut.obj (+RO)
         camera_tuning_oper.obj (+RO)
         usbacm_ft.obj (+RO)
         custom_nvram_sec.obj (+RO)
         custom_nvram_config.obj (+RO)
         usbacm_logging.obj (+RO)
         custom_vrender.obj (+RO)
         meta_customize.obj (+RO)
         afe.obj (+RO)
         capacitive_tp_cypress_cy8ctma340.obj (+RO)
         capacitive_tp_i2c.obj (+RO)
         camera_sccb.obj (+RO)
         custom_idp.obj (+RO)
         matv_hostdrv.obj (+RO)
         matv_cust.obj (+RO)
         
         aud_i2s_config.obj (+RO)
         usbimage_drv.obj (+RO)
         motion_sensor_custom.obj (+RO)
         motion_sensor_i2c.obj (+RO)
         image_sensor_ov3640.obj (+RO)
         asd_main.obj (+RO)
         decider_core.obj (+RO)
         asd_core.obj (+RO)
         autocap_main.obj (+RO)
         autocap_core.obj (+RO)
         gps_sm.obj (+RO)
         MTK_GPS_Misc.obj (+RO)
         uem_proc_cmd.obj (+RO)
         
         camera_memory_in_process.obj (+RO)
         factoryModeSrc.obj (+RO)
         ft_fnc_util.obj (+RO)
         ft_main.obj (+RO)
         ft_fnc.obj (+RO)
         JavaAgencyEMPerformance.obj (+RO)
         bitshift_accelerator.obj (+RO)
         f8_opti.obj (+RO)
         tl1_trx_calibration.obj (+RO)

         rsa_lib.obj (+RO)
         icc_switchcontrol1_aw6314_dummy.obj (+RO)
         kal_public_api.obj (+RO)
         video_scheduler_component_v2.obj (+RO)
         video_clock_component_v2.obj (+RO)
         mp4_recorder.obj (+RO)
         wav_drv_thumb.obj (+RO)
         EncRateControl_Visual.obj (+RO)
         p8_pkey.obj (+RO)
         video_recorder_clock_component_v2.obj (+RO)
         EncProfile.obj (+RO)
         nic.obj (+RO)
         EncRotate.obj (+RO)
         nvram_ul1def.obj (+RO)
         rrc_asn_decode.obj (+RO)
         sp_3g.obj (+RO)
         t9engine.obj (+RO)
         sm_event.obj (+RO)
         ul1_kal.obj (+RO)
         termCall.obj (+RO)
         dspsyn.obj (+RO)
         sm_instance.obj (+RO)
         ll1_timing_sync_handler.obj (+RO)
         ll1_common.obj (+RO)
         ll1_fach_gap_handler.obj (+RO)
         ll1_dch_gap_handler.obj (+RO)
         aac_drv.obj (+RO)
         wav_drv.obj (+RO)
         wma_drv.obj (+RO)
         ll1_pch_gap_handler.obj (+RO)
         opera_adp_hw_binding.obj (+RO)
         EncPutBits.obj (+RO)
         gps_main.obj (+RO)
         ctm_drv.obj (+RO)
         Settings.obj (+RO)
         rfc2507_lib_common.obj (+RO)
         tst_sysser_base.obj (+RO)
         ctm_receiver.obj (+RO)
         as_access_sem_funcs.obj (+RO)
         tst_profile.obj (+RO)
         gps_uart_hdlr.obj (+RO)
         invtst.obj (+RO)
         rrlp_r5_asn_decode.obj (+RO)
         lapdm_app_mesg_funcs.obj (+RO)
         vcodec_OAL_v2.obj (+RO)
         l2cap_utl.obj (+RO)
         obheader.obj (+RO)
         meif.obj (+RO)
         avi_provider.obj (+RO)
         rfc_ctl.obj (+RO)
         sdp_msg_api.obj (+RO)
         scalado_adp_hw_binding_asm.obj (+RO)
         EncVisualObjectSequence.obj (+RO)
         EncInit.obj (+RO)
         snd_effect.obj (+RO)
         vrt_base_type_info.obj (+RO)
         
         mac_cfg_*.obj (+RO)
         camera_sensor_para_*.obj (+RO)
         camera_para*.obj (+RO)
         camera_af_para_*.obj (+RO)
;applib.lib
         app_str.obj (+RO)
         app_addr.obj (+RO)
         app_asyncfile.obj (+RO)
         app_base64.obj (+RO)
         app_datetime.obj (+RO)
         app_mem.obj (+RO)
         app_mime.obj (+RO)
         app_ua.obj (+RO)
         app_usedetails.obj (+RO)
         applib_asn_common.obj (+RO)
         dict.obj (+RO)
;audio.lib
         aac_comp_drv.obj (+RO)
         afe2.obj (+RO)
         am.obj (+RO)
         amr.obj (+RO)
         amr_drv.obj (+RO)
         amr_dedi.obj (+RO)
         amr_table.obj (+RO)
         apm_comp.obj (+RO)
         audio_idma.obj (+RO)
         audio_service.obj (+RO)
         audioCF.obj (+RO)
         audioPP.obj (+RO)
         audlp2_drv.obj (+RO)
         AudioDrain.obj (+RO)
         AVB.obj (+RO)
         daf_drv.obj (+RO)
         daf_rtpss.obj (+RO)
         dpmgr.obj (+RO)
         i2s_drv.obj (+RO)
         l1audio_trace.obj (+RO)
         media.obj (+RO)
         pcm4way.obj (+RO)
         pcm.obj (+RO)
         pcm_strm_drv.obj (+RO)
         poc_amr.obj (+RO)
         sbc_drv.obj (+RO)
         sbc_seq.obj (+RO)
         sp_drv.obj (+RO)
         sp_enhance.obj (+RO)
         spt_analyzer.obj (+RO)
         tone2.obj (+RO)
         vm.obj (+RO)
         vm_drv.obj (+RO)
         wav.obj (+RO)
         wav_codec.obj (+RO)
         wav_thumb.obj (+RO)
         Wavetable_DSPv2.obj (+RO)
         pcmRouteService.obj (+RO)
;audio_comp.lib
         AacDspDecoder.obj (+RO)
         AmrDspDecoder.obj (+RO)
         apm.obj (+RO)
         ast.obj (+RO)
         AudComUtil.obj (+RO)
         AudioMixer.obj (+RO)
         aumxr_eng.obj (+RO)
         DafParser.obj (+RO)
         jimy_comp.obj (+RO)
         jsmf_comp.obj (+RO)
         jwav_comp.obj (+RO)
         kt_Detect.obj (+RO)
         MedAdapt.obj (+RO)
         media_avsync.obj (+RO)
         melody_common.obj (+RO)
         MelodyParser.obj (+RO)
         MelodySynthesizer.obj (+RO)
         PcmSink.obj (+RO)
         jwav.obj (+RO)
         jimy.obj (+RO)
         jsmf.obj (+RO)
;btadp.lib
         bt_avrcp_util.obj (+RO)
         bt_adp_a2dp.obj (+RO)
         bt_adp_spp_vp.obj (+RO)
         bt_adp_obex.obj (+RO)
         bt_adp_system.obj (+RO)
         bt_maui_system.obj (+RO)
         bt_uart.obj (+RO)
         bt_osapi.obj (+RO)
;btprofile.lib
         at_hs.obj (+RO)
         obparse.obj (+RO)
         avrcpsdp.obj (+RO)
         atp.obj (+RO)
         avrcp.obj (+RO)
;btstack.lib
         sdpserv.obj (+RO)
         ring.obj (+RO)
         rfcomm.obj (+RO)
         sdp.obj (+RO)
;camera.lib
         aaa_ae.obj (+RO)
         aaa_ae_cct_if.obj (+RO)
         aaa_af.obj (+RO)
         aaa_af_comm.obj (+RO)
         aaa_awb.obj (+RO)
         aaa_awb_cct_if.obj (+RO)
         aaa_flash_ae.obj (+RO)
         aaa_process.obj (+RO)
         cal_camera_nvram.obj (+RO)
         cal_cb.obj (+RO)
         cal_cct_feature_ctrl.obj (+RO)
         cal_feature_ctrl.obj (+RO)
         cal_main.obj (+RO)
         cal_profiling.obj (+RO)
         cal_scenario_ctrl.obj (+RO)
         cal_task_main.obj (+RO)
         cal_webcam.obj (+RO)
         idp_cam_if.obj (+RO)
         isp_cct_feature.obj (+RO)
         isp_cct_if.obj (+RO)
         isp_comm_if.obj (+RO)
         isp_control.obj (+RO)
         isp_device.obj (+RO)
         isp_driver_if.obj (+RO)
         isp_feature.obj (+RO)
         isp_flashlight_if.obj (+RO)
         isp_image_effect.obj (+RO)
         isp_isr.obj (+RO)
         isp_nvram.obj (+RO)
         isp_pca.obj (+RO)
         isp_tunning_oper.obj (+RO)
         isp_webcam.obj (+RO)
;camera_sec.lib
         aaa_ae_core.obj (+RO)
         aaa_af_core.obj (+RO)
         aaa_awb_core.obj (+RO)
         isp_lsc_core.obj (+RO)
         isp_pca_core.obj (+RO)
;cc.lib
         cc_facility_proc.obj (+RO)
         cc_ie_form.obj (+RO)
         cc_msg_form.obj (+RO)
         cc_mpty_proc.obj (+RO)
;certman.lib
         certman_util.obj (+RO)
         certman_retrieve.obj (+RO)
         certman_storage.obj (+RO)
         certman_db.obj (+RO)
;che.lib
         aes_engine.obj (+RO)
         bignum.obj (+RO)
         che_api.obj (+RO)
         che_sw_driver.obj (+RO)
         des_engine.obj (+RO)
         md4_engine.obj (+RO)
;data
         rlp_i_transfer.obj (+RO)
;dhcp.lib
         dhcp_unpack.obj (+RO)
;dhcpd.lib         
         dhcpd_util.obj (+RO)
         dhcpd_log.obj (+RO)
         dhcpd_msg.obj (+RO)
;dp_engine.lib
         APM_Util.obj (+RO)
         resample.obj (+RO)
         sbc_enc.obj (+RO)
         sbc_common.obj (+RO)
         sbc_anal.obj (+RO)
         APM_Util.obj (+RO)
;drm.lib
         drm_interface.obj (+RO)
         drm_main.obj (+RO)
         drm_memory.obj (+RO)
         drm_util.obj (+RO)
;drmadp_mtk
         drm_core_cmd.obj (+RO)
         drm_core_parser.obj (+RO)
         drm_core_proc.obj (+RO)
;flc2.lib
         flc2_debug_functions.obj (+RO)
         flc2_ent_functions.obj (+RO)
         flc2_mem_mngr_config.obj (+RO)
         flc2_mem_mngr_fix_size.obj (+RO)
         flc2_mem_mngr_ctrl_buff_adp.obj (+RO)
         flc2_mem_mngr_adm_adp.obj (+RO)
;gadget_ports
         gadget_adp_audio.obj (+RO)
;gadget_adp.lib
         common.obj (+RO)
;hostap.lib
         wpa.obj (+RO)
         aes_wrap.obj (+RO)
;l4_classb.lib         
         smsal_modi_peer_rest.obj (+RO)
         csmcc_msg_hdlr.obj (+RO)
         csmcc_bc_func.obj (+RO)
         csmcc_facility_proc.obj (+RO)
         l4c_sms_cmd.obj (+RO)
         l4c_phb_cmd.obj (+RO)
         l4c_sendmsg.obj (+RO)
         l4c_utility.obj (+RO)
         rmmi_utility.obj (+RO)
         rmmi_rsp.obj (+RO)
         rmmi_sio.obj (+RO)
         smsal_utils.obj (+RO)
;l4misc.lib
         phb_utils.obj (+RO)
         phb_name_num_index.obj (+RO)
         uem_utility.obj (+RO)
         uem_gpio_ctrl.obj (+RO)
;llc.lib
         llc_flowctrl.obj (+RO)
;nvram.lib
         nvram_interface.obj (+RO)
         nvram_io.obj (+RO)
         nvram_util.obj (+RO)
         nvram_drval_fat.obj (+RO)
         nvram_l1def.obj (+RO)
         nvram_multi_folder.obj (+RO)
         nvram_sec.obj (+RO)
         nvram_ltable.obj (+RO)
;matv.lib
         mATVwcx_env.obj (+RO)
;matv_sec.lib         
         matd_demod.obj (+RO)
         mATVdrv_chscan.obj (+RO)
;mcd.lib
         mcd_mem.obj (+RO)
         mcd_bits.obj (+RO)
;mcsv.lib
         mcsv.obj (+RO)
;mm_classb_umts.lib
         mm_ps_detach.obj (+RO)
         mm_ctrl_plmn_search.obj (+RO)
         mm_common_funcs.obj (+RO)
         mm_ps_attach.obj (+RO)
         mm_cs_loc_update.obj (+RO)
         mm_sim_access.obj (+RO)
;mmi_framework.lib
         CommonLang.obj (+RO)
         gui_status_icon_bar.obj (+RO)
         gui_status_icon.obj (+RO)
         history.obj (+RO)
         keybrd.obj (+RO)
         mmi_frm_remutex.obj (+RO)
         mmitimer.obj (+RO)
         Notification.obj (+RO)
         pixcomfontengine.obj (+RO)
         queue.obj (+RO)
         Scenario.obj (+RO)
         screenrotation.obj (+RO)
         scrmemmgr.obj (+RO)
         sublcdhistory.obj (+RO)
         touchscreen.obj (+RO)
         ucs2.obj (+RO)
         wingui.obj (+RO)
;mpl.lib
         media_player.obj (+RO)
         media_session.obj (+RO)
         mpl_utility.obj (+RO)
         mpl_vt.obj (+RO)
         mpl_session.obj (+RO)
;mtv
         atv_sp.obj (+RO)
;mt6306        
         *MT6306.a (+RO)
;opengles.lib     
         base_common_mem.obj (+RO)
         base_common_ds.obj (+RO)
         bs_symbol.obj (+RO)
         egl_handle.obj (+RO)
         essl_node.obj (+RO)
         essl_list.obj (+RO)
         gfxsys_power_ctrl_6256_series.obj (+RO)
         gles_gb_plbu.obj (+RO)
         gles_state.obj (+RO)
         gpu_drv_task.obj (+RO)
         gpu_memory_if.obj (+RO)
         make_basic_blocks.obj (+RO)
         mali200_preschedule.obj (+RO)
         mali200_instruction.obj (+RO)
         mali_dbg_print_log.obj (+RO)
         mali_gp_job.obj (+RO)
         mali_kernel_core.obj (+RO)
         mali_kernel_l2_cache.obj (+RO)
         mali_kernel_rendercore.obj (+RO)
         mali_kernel_mem_mmu.obj (+RO)
         mali_kernel_GP2.obj (+RO)
         mali_kernel_MALI200.obj (+RO)
         mali_osk_memory.obj (+RO)
         mali_osk_time.obj (+RO)
         mali_osk_low_level_mem.obj (+RO)
         mali_osk_locks.obj (+RO)
         mali_syncobj_handler.obj (+RO)
         mali_osk_irq.obj (+RO)
         mali_osk_timers.obj (+RO)
         mali_osk_notification.obj (+RO)
         mali_memory.obj (+RO)
         mali_mutex.obj (+RO)
         mali_osk_misc.obj (+RO)
         mali_osk_list.obj (+RO)
         mali_osu_atomics.obj (+RO)
         mali_runtime.obj (+RO)
         mali_osu_misc.obj (+RO)
         mali_kernel_nucleus.obj (+RO)
         base_arch_atomic.obj (+RO)
         mali_kernel_nucleus.obj (+RO)
         base_arch_atomic.obj (+RO)
         mali_osu_atomics.obj (+RO)
         mali_osk_mali.obj (+RO)
         base_common_tools_circular_linked_list.obj (+RO)
         base_arch_pp.obj (+RO)
         mali_rsw_cache.obj (+RO)
         base_common_sync_handle.obj (+RO)
         mali_linked_list.obj (+RO)
         gles_object.obj (+RO)
         base_arch_threads.obj (+RO)
         base_arch_main.obj (+RO)
         mali_runtime.obj (+RO)
         gles_m200_shaders.obj (+RO)
         mali_osu_locks.obj (+RO)
         egl_thread.obj (+RO)
         mali_convert.obj (+RO)
         gles_m200_rsw_setup.obj (+RO)
         egl_misc.obj (+RO)
         egl_gles.obj (+RO)
         gles_clear.obj (+RO)
         egl_main.obj (+RO)
         gles_draw.obj (+RO)
         essl_mem.obj (+RO)
         gles_gb_draw.obj (+RO)
         gles2_error.obj (+RO)
         mali_mem_ref.obj (+RO)
         gles2_pixel.obj (+RO)
         bs_loader.obj (+RO)         
         gles_flush.obj (+RO)  
         mali_dependency_system.obj (+RO)
         mali_kernel_descriptor_mapping.obj (+RO)       
         mali_osk_math.obj (+RO)
         mali_runtime.obj (+RO)
         base_common_context.obj (+RO)         
         mali_shared_mem_ref.obj (+RO)
         mali_rsw_cache.obj (+RO)   
         gles2_vertex_array.obj (+RO)
         mali_surface_specifier.obj (+RO)
;postproc.lib         
         fd_main.obj (+RO)
         pp_feature_ctrl.obj (+RO)
         pp_main.obj (+RO)
         pp_scenario_ctrl.obj (+RO)
         sd_main.obj (+RO)
         utility_feature_ctrl.obj (+RO)
;postproc_sec.lib
         fd_core.obj (+RO)
         sd_core.obj (+RO)
         utility_core.obj (+RO)
;ppp
         ppp_ipcp.obj (+RO)
;provider.lib
         mp4_parser_stbl.obj (+RO)
         mp4_parser.obj (+RO)
         mp4_sample_data_audio.obj (+RO)
         mp4_parser_audio.obj (+RO)
         source_provider_component.obj (+RO)
;ratcm.lib
         ratcm_ctrl_csd.obj (+RO)
;rr_classb2
         acs_common_ctrl_hdlr.obj (+RO)
         csn_common.obj (+RO)
         csrr_recv_lapdm_mesgs.obj (+RO)
         csrr_send_int_msg.obj (+RO)
         gprs_rlcmac_common_rest.obj (+RO)
         gprs_rlcmac_dl_rest.obj (+RO)
         lapdm_frame_funcs.obj (+RO)
         lapdm_recv_mpal_msgs.obj (+RO)
         lapdm_recv_rr_msgs.obj (+RO)
         mac_common_ctrl_hdlr.obj (+RO)
         mac_data_blk_hdlr.obj (+RO)
         mac_dl_ctrl_hdlr.obj (+RO)
         mac_main.obj (+RO)
         mac_sendmsgs.obj (+RO)
         mac_utils.obj (+RO)
         meas_funcs.obj (+RO)
         mpal_gprs_common_func.obj (+RO)
         mpal_gprs_dl_func.obj (+RO)
         mpal_gprs_dl_msg_hdlr.obj (+RO)
         mpal_gsm_common_func.obj (+RO)
         mpal_gsm_dl_func.obj (+RO)
         mpal_gsm_dl_msg_hdlr.obj (+RO)
         mpal_gsm_ul_msg_hdlr.obj (+RO)
         mpal_main.obj (+RO)
         nstd_mobile_alloc_peer_pun.obj (+RO)
         psi.obj (+RO)
         rlc_dl_ctrl_msg_hdlr.obj (+RO)
         rlc_util.obj (+RO)
         rmc_gprs_timer_hdlr.obj (+RO)
         rmc_gprs_meas_funcs.obj (+RO)
         rmc_peer_dl_rest.obj (+RO)
         rmp_timerhdlr.obj (+RO)
         rmp_pktacc.obj (+RO)
         rr_create.obj (+RO)
         rr_data_ind.obj (+RO)
         rr_dual_sim_process.obj (+RO)
         rr_gprs_meas_decode.obj (+RO)
         rr_gprs_utils.obj (+RO)
         rr_spare_bit.obj (+RO)
         rr_utils.obj (+RO)
         rrm_main.obj (+RO)
         rrm_send_msgs.obj (+RO)
         si_msg_decode.obj (+RO)
         si_update_funcs.obj (+RO)
;rtsp.lib
         rtsp_util.obj (+RO)
;sbpki2adp
         pki.obj (+RO)
         pki_pkcs8.obj (+RO)
         pki_pkcs7.obj (+RO)
         pki_validate.obj (+RO)
         pki_x509.obj (+RO)
;scsi.lib
         csi_asn_encode.obj (+RO)
         csi_asn_decode.obj (+RO)
         scsi.obj (+RO)
;sim2.lib
         sim_driver_interfaces.obj (+RO)
         sim_handler.obj (+RO)
         sim_toolkit.obj (+RO)
         usim_handler.obj (+RO)
;smslib.lib
         smslib_decode.obj (+RO)
         smslib_others.obj (+RO)
;soc.lib
         soc_api.obj (+RO)
         soc_common.obj (+RO)
;tls.lib
         tls_api.obj (+RO)
         tls_fs.obj (+RO)
;uas.lib
         am_receive.obj (+RO)
         am_specific_operations.obj (+RO)
         am_transmit.obj (+RO)
         config_l2_test_entity.obj (+RO)
         crlc_fsm.obj (+RO)
         csr_fsm.obj (+RO)
         f8f9_drv.obj (+RO)
         l2_testloop_mode2.obj (+RO)
         mac_api.obj (+RO)
         mac_cfg_ciphering.obj (+RO)
         mac_cfg_edch_cctrch.obj (+RO)
         mac_cfg_hsdsch_cctrch.obj (+RO)
         mac_cfg_queue.obj (+RO)
         mac_cfg_rach_params.obj (+RO)
         mac_cfg_rx_cctrch.obj (+RO)
         mac_cfg_tfc_subset.obj (+RO)
         mac_cfg_tvm.obj (+RO)
         mac_cfg_tx_cctrch.obj (+RO)
         mac_cfg_tx_logch.obj (+RO)
         mac_cfg_tx_trch.obj (+RO)
         mac_config.obj (+RO)
         mac_edch_data.obj (+RO)
         mac_global_data.obj (+RO)
         mac_header.obj (+RO)
         mac_hsdsch_data.obj (+RO)
         mac_phy.obj (+RO)
         mac_rach.obj (+RO)
         mac_timers.obj (+RO)
         mac_tx.obj (+RO)
         rab.obj (+RO)
         reset.obj (+RO)
         retransmission_buffer.obj (+RO)
         rlc_am_rx_fsm.obj (+RO)
         rlc_drv_common.obj (+RO)
         rlc_drv_rx.obj (+RO)
         rlc_drv_rx_command.obj (+RO)
         rlc_drv_tx.obj (+RO)
         rlc_drv_tx_command.obj (+RO)
         rlc_entity.obj (+RO)
         rrc_asn_isValid.obj (+RO)
         rrc_db_decode.obj (+RO)
         rrc_db_encode.obj (+RO)
         rrc_utils.obj (+RO)
         rrcc_fsm.obj (+RO)
         rrci_fsm.obj (+RO)
         sdu_queue.obj (+RO)
         seq_fsm.obj (+RO)
         seq_mac.obj (+RO)
         seq_rlc.obj (+RO)
         tm_transmit.obj (+RO)
         transmission_buffer_queue.obj (+RO)
         ul2_mem_mgmt.obj (+RO)
         ul2_sigout.obj (+RO)
         ul2_timers.obj (+RO)
         ul2d_handlers.obj (+RO)
         um_receive.obj (+RO)
         um_transmit.obj (+RO)
         usime_utils.obj (+RO)
         urr_unpack.obj (+RO)
         db_schema.obj (+RO)
;ul1_hs.lib
         ccm.obj (+RO)
         cm_dch.obj (+RO)
         cm_fach.obj (+RO)
         cm_idle.obj (+RO)
         cm_null.obj (+RO)
         cm_standby.obj (+RO)
         cmcs_gap.obj (+RO)
         cmm.obj (+RO)
         cs.obj (+RO)
         ctch.obj (+RO)
         dldch.obj (+RO)
         dm.obj (+RO)
         e_dch.obj (+RO)
         edch.obj (+RO)
         error_check.obj (+RO)
         erxbrp.obj (+RO)
         erxcrp.obj (+RO)
         erxsrp.obj (+RO)
         etxcrp.obj (+RO)
         fach.obj (+RO)
         frame_tick.obj (+RO)
         fs.obj (+RO)
         hcqi.obj (+RO)
         hrxbrp.obj (+RO)
         hrxcrp.obj (+RO)
         hrxsrp.obj (+RO)
         hs_dsch.obj (+RO)
         hsce.obj (+RO)
         hsdsch.obj (+RO)
         htxcrp.obj (+RO)
         param_db.obj (+RO)
         pch.obj (+RO)
         rach.obj (+RO)
         report.obj (+RO)
         resource.obj (+RO)
         rxtx.obj (+RO)
         scs.obj (+RO)
         sfn.obj (+RO)
         sfn_meas.obj (+RO)
         sib.obj (+RO)
         tgps.obj (+RO)
         time.obj (+RO)
         timer.obj (+RO)
         u11100.obj (+RO)
         u11120.obj (+RO)
         u11130.obj (+RO)
         u11131.obj (+RO)
         u11132.obj (+RO)
         u11134.obj (+RO)
         u11135.obj (+RO)
         u11142.obj (+RO)
         u11143.obj (+RO)
         u11190.obj (+RO)
         ul1_tool.obj (+RO)
         ul1a_trc.obj (+RO)
         ul1c_trace1.obj (+RO)
         ul1c_trace2.obj (+RO)
         ul1c_trace3.obj (+RO)
         ul1c_trace4.obj (+RO)
         UL1D_HSPA_Trace1.obj (+RO)
         UL1D_HSPA_Trace2.obj (+RO)
         UL1D_HSPA_Trace.obj (+RO)
         UL1D_MLT_Trace1.obj (+RO)
         UL1D_MLT_Trace2.obj (+RO)
         UL1D_Trace1.obj (+RO)
         UL1D_Trace2.obj (+RO)
         UL1D_Trace3.obj (+RO)
         UL1D_Trace4.obj (+RO)
         UL1D_Trace5.obj (+RO)
         UL1D_Trace6.obj (+RO)
         UL1D_Trace.obj (+RO)
         ul1data_main.obj (+RO)
         UL1SM_Trace1.obj (+RO)
         ul1tst_cfg.obj (+RO)
         ul1tst_cs.obj (+RO)
         ul1tst_nsft.obj (+RO)
         ul1tst_rach.obj (+RO)
         ul1tst_report.obj (+RO)
         ul1tst_rssi.obj (+RO)
         UL1TST_Trace1.obj (+RO)
         ul1tst_uldch.obj (+RO)
         uldch.obj (+RO)
         wafc.obj (+RO)
         wagps.obj (+RO)
         wbch.obj (+RO)
         wcellinfo.obj (+RO)
         wcore.obj (+RO)
         wcs.obj (+RO)
         wdatabase.obj (+RO)
         wdldch.obj (+RO)
         wdlpc.obj (+RO)
         wdm.obj (+RO)
         wfach.obj (+RO)
         winternaldata.obj (+RO)
         wlog3g.obj (+RO)
         wmeas.obj (+RO)
         wnwscan.obj (+RO)
         wpch.obj (+RO)
         wps.obj (+RO)
         wrach.obj (+RO)
         wrcontrol.obj (+RO)
         wrevent.obj (+RO)
         wrfm.obj (+RO)
         wrgain.obj (+RO)
         wrgeneral.obj (+RO)
         wrinit.obj (+RO)
         wrsynthesizer.obj (+RO)
         wrxbrp.obj (+RO)
         wrxcrp.obj (+RO)
         wrxsrp.obj (+RO)
         wsfn.obj (+RO)
         wspeedest.obj (+RO)
         wtfcstate.obj (+RO)
         wtimer.obj (+RO)
         wtxbrp.obj (+RO)
         wtxcrp.obj (+RO)
         wuldch.obj (+RO)
         wulpc.obj (+RO)
         wutil.obj (+RO)
         ul1tst_edch.obj (+RO)
         ul1tst_hsdsch.obj (+RO)
         wdbg.obj (+RO)
;venusmmi.lib
         vcp_clock.obj (+RO)
         vadp_p2v_mem_info.obj (+RO)
         vadp_v2p_input_server.obj (+RO)
         vfx_weak_ptr.obj (+RO)
         vfx_frame_filter.obj (+RO)
         vfx_date_time.obj (+RO)
         vfx_signal.obj (+RO)
         vfx_frame_aligner.obj (+RO)
         vfx_draw_context.obj (+RO)
         vfx_basic_type.obj (+RO)
         vfx_frame.obj (+RO)
         vfx_app_launcher.obj (+RO)
;video_sec.lib
         h264_hw_decoder_component_v2.obj (+RO)
         mjpeg_decoder_component_v2.obj (+RO)
         mjpeg_encoder_component_v2.obj (+RO)
         mp4_decore_v2.obj (+RO)
         mp4_rc_v2.obj (+RO)
         mpeg4_hw_decoder_component_v2.obj (+RO)
         mpeg4_hw_encoder_component_v2.obj (+RO)
         mpeg4_hw_encore_v2.obj (+RO)
         mply_sec.obj (+RO)
         mses_sec.obj (+RO)
         sw_video_resizer.obj (+RO)
         video_OAL_v2.obj (+RO)
         video_codec_buffer_mgr_v2.obj (+RO)
         video_codec_log.obj (+RO)
         video_decoder_common_adapter_v2.obj (+RO)
         video_decoder_component_v2.obj (+RO)
         video_decoder_isolation_v2.obj (+RO)
         video_decscheduler_component_v2.obj (+RO)
         video_encoder_auxiliary_v2.obj (+RO)
         video_encoder_common_adapter_v2.obj (+RO)
         video_encoder_component_v2.obj (+RO)
         video_recorder_source_component_v2.obj (+RO)
         video_codec_schedule_control.obj (+RO)
         yuv_encoder_component_v2.obj (+RO)
         open_api_h264_decode.obj (+RO)
         open_api_h264_driver.obj (+RO)
         open_api_h264_mem_if.obj (+RO)
         open_api_h264_memory_management.obj (+RO)
         open_api_h264_sw_driver.obj (+RO)
         open_api_h264_yuv_management.obj (+RO)
;video.lib
         VideoCall_IL_Client.obj (+RO)
         custom_video_enc.obj (+RO)
         custom_video_enc_h264.obj (+RO)
         custom_video_enc_matv.obj (+RO)
         custom_video_enc_mjpeg.obj (+RO)
         custom_video_enc_mpeg4.obj (+RO)
         custom_video_enc_utility.obj (+RO)
         custom_video_enc_vt.obj (+RO)
         hal_custom_video.obj (+RO)
         val.obj (+RO)
         val_recorder.obj (+RO)
         video_buffer_management_v2.obj (+RO)
         video_codec_custom_adapter_v2.obj (+RO)
         video_codec_utility_v2.obj (+RO)
         video_comm_component_v2.obj (+RO)
         video_comm_v2.obj (+RO)
         video_dbg_v2.obj (+RO)
         video_recorder_clock_utility_v2.obj (+RO)
         video_recorder_if_v2.obj (+RO)
         video_vt_api_v2.obj (+RO)
         va2_comp_video_renderer.obj (+RO)
         va2_display_api_adapter.obj (+RO)
         va2_util_buffer_header_queue.obj (+RO)
         va2_util_misc.obj (+RO)
         mp4_filewriter_component_v2.obj (+RO)
         mp4_filewriter_meta_creation_v2.obj (+RO)
                  
         *va2_video_renderer_*.obj (+RO) ; for va2_video_renderer_vp_mt6xxx for va2_video_renderer_vt_mt6xxx
         
         va2_video_renderer_vt_mt6276.obj (+RO)
         va2_video_renderer_vt_mt6268.obj (+RO)
         va2_video_renderer_vt_mt6256_e2.obj (+RO)
         va2_video_renderer_vt_mt6236.obj (+RO)
         va2_video_renderer_vt.obj (+RO)
         va2_video_renderer_vp_mt6276.obj (+RO)
         va2_video_renderer_vp_mt6268.obj (+RO)
         va2_video_renderer_vp_mt6236.obj (+RO)
         va2_video_renderer_vp_mt6235.obj (+RO)
         va2_video_renderer_vp.obj (+RO)
         
;video_codec_sec.lib
         mpeg4_encoder_component_v2.obj (+RO)
         H264SwDecApi.obj (+RO)
         MP4SwDecApi.obj (+RO)
         MP4SwEncDriver_Fcore.obj (+RO)
         MP4SwEncDriver_Hybrid.obj (+RO)
         mpeg4_encoder_component_v2.obj (+RO)
         mpeg4_vt_encoder_component_v2.obj (+RO)
         UVTSwEncApi.obj (+RO)
         vcodec_OAL.obj (+RO)
         video_msg.obj (+RO)
         
;vrt.lib 
         vrt_cache_alloc.obj (+RO)
         vrt_datatype.obj (+RO)
         vrt_gles_render_device.obj (+RO)
         vrt_render_device.obj (+RO)
         vrt_render.obj (+RO)
         vrt_task.obj (+RO)
;vrt16.lib         
         vrt_base_map.obj (+RO)
         vrt_canvas.obj (+RO)
         vrt_base_string.obj (+RO)
;vrt_adp.lib         
         vrt_system.obj (+RO)
;wifi.lib         
         gl_hpi.obj (+RO)
         wlan_lib.obj (+RO)
         wndrv_misc.obj (+RO)
;xmlp.lib
         xml_main.obj (+RO)
         wbxmlp_main.obj (+RO)
;Performance Concern OBJ List         
;uas.lib Because of performance concern, move out of Demand Paging (for 3G layer 3 MEME/ADR/DBME) 
         asn_memory.obj (+RO)
         asn_common.obj (+RO)
         rrc_asn_encode.obj (+RO)
         urr_pack.obj (+RO)
         rrc_meme_phys_layer.obj (+RO)
         rrc_meme_event.obj (+RO)
         rrc_meme_intra_frequency.obj (+RO)
         rrc_meme_measurement_report.obj (+RO)
         meme_comm_send.obj (+RO)
         meme_fsm.obj (+RO)
         rrc_meme_cell_info_list.obj (+RO)
         rrc_meme_gsm_layer.obj (+RO)
         rrc_meme_inter_frequency.obj (+RO)
         rrc_meme_inter_rat.obj (+RO)
         rrc_meme_mac_layer.obj (+RO)
         rrc_meme_measurement_control.obj (+RO)
         rrc_meme_population.obj (+RO)
         rrc_meme_quality_measurement.obj (+RO)
         rrc_meme_rrc_states.obj (+RO)
         rrc_meme_sib.obj (+RO)
         rrc_meme_tables.obj (+RO)
         rrc_meme_timing.obj (+RO)
         rrc_meme_traffic_volume.obj (+RO)
         rrc_meme_ue_internal.obj (+RO)
         rrc_meme_utilities.obj (+RO)
         db_wrappers.obj (+RO)
         db_access.obj (+RO)
         dbme.obj (+RO)
; becuase of mmi performance concern, so move out of demand paging (HS to mainmenu, mainmenu to HS)
         vfx_object.obj (+RO)
         AppMemMgrCore.obj (+RO)
         vcp_page_menu_util.obj (+RO)
         vfx_text_frame.obj (+RO)
         vfx_screen.obj (+RO)
         ttinterp.obj (+RO)
         wgui_status_icon_bar.obj (+RO)
         event_handler.obj (+RO)
         vfx_timer.obj (+RO)
         mmi_cb_mgr.obj (+RO)
         vfx_animatable.obj (+RO)
         vapp_widget_archive.obj (+RO)
         vapp_mainmenu.obj (+RO)
         vcp_pluto_control.obj (+RO)
         vfx_sys_memory.obj (+RO)
         vfx_app.obj (+RO)
         wgui_softkeys.obj (+RO)
         vapp_mainmenu_page_menu.obj (+RO)
         vfx_top_level.obj (+RO)
         ftobjs.obj (+RO)
         vfx_pen.obj (+RO)
         vrt_canvas_frame.obj (+RO)
         ftgrays.obj (+RO)
         vfx_cpp_base.obj (+RO)
         vfx_renderer.obj (+RO)
         gui_effect_oem.obj (+RO)
         nvraminterface.obj (+RO)
         vapp_widget_primitive.obj (+RO)
         vfx_control.obj (+RO)
         readres.obj (+RO)
         ftcalc.obj (+RO)
         vfx_object_list.obj (+RO)
         vapp_mainmenu_builder.obj (+RO)
         gui_clock.obj (+RO)
         vfx_logger.obj (+RO)
         vrt_draw_cmd_queue.obj (+RO)
         vfx_keypad.obj (+RO)
         gpioBacklightSrv.obj (+RO)
         freetype_adaptation.obj (+RO)
         vfx_system.obj (+RO)
         vfx_image_src.obj (+RO)
         vfx_archive.obj (+RO)
         vfx_mmi.obj (+RO)
         gui_sse_oem.obj (+RO)
         rmpc_nbr_cell.obj (+RO)
         vapp_widget_gallery_viewer.obj (+RO)
         wgui_draw_manager.obj (+RO)
         bidipararules.obj (+RO)
         vfx_async_signal.obj (+RO)
         l4_create.obj (+RO)
         LangModule.obj (+RO)
         vapp_wallpaper_wildworld.obj (+RO)
         JavaAppFactorySrv.obj (+RO)
         vapp_gallery_data.obj (+RO)
         vfx_main_scr.obj (+RO)
         rmc_serv_nbr_meas.obj (+RO)
         rrm_utils.obj (+RO)
         vfx_page.obj (+RO)
         vapp_home.obj (+RO)
         vfx_animation.obj (+RO)
         vfx_app_scr.obj (+RO)
         vapp_home_director.obj (+RO)
         vapp_widget_gallery_control_bar.obj (+RO)
         bidi.obj (+RO)
         wgui_categories_util.obj (+RO)
         rmc_common_access.obj (+RO)
         vapp_screen_lock_main.obj (+RO)
         rmc_cell_resel.obj (+RO)
         vfx_primitive_frame.obj (+RO)
         vrt_image.obj (+RO)
         rmc_meas.obj (+RO)
         vfx_adp_device.obj (+RO)
         rmc_update_rla_meas.obj (+RO)
         ftgloadr.obj (+RO)
         vapp_dual_sim_setting.obj (+RO)
         gui_buttons.obj (+RO)
         vapp_platform_context.obj (+RO)
         AppMgrSrv.obj (+RO)
         vrt_object.obj (+RO)
         vrt_gdi_render_device.obj (+RO)
         vcp_base_menu.obj (+RO)
         gles_entrypoints.obj (+RO)
         imc.obj (+RO)
         vrt_3d.obj (+RO)
         vcp_text_layout.obj (+RO)
         imm.obj (+RO)
         gles2_entrypoints.obj (+RO)
         vcp_list_menu.obj (+RO)
         vrt_base_list.obj (+RO)
         vapp_dialer_cp.obj (+RO)
         vcp_text_editor.obj (+RO)
         vrt_pointer.obj (+RO)
         vrt_vector.obj (+RO)
         vapp_dialer_main.obj (+RO)
         vfx_asset_loader.obj (+RO)
         vcp_page_panel.obj (+RO)
         vcp_tabctrl_page.obj (+RO)
         vapp_phb_launch.obj (+RO)
         imc_pen.obj (+RO)
         vcp_marquee.obj (+RO)
         vcp_text_view.obj (+RO)
         vfx_mesh.obj (+RO)
         vrt_matrix.obj (+RO)

         vcp_scrollable.obj (+RO)
         vfx_page_transition.obj (+RO)
         vcp_navi_title_bar.obj (+RO)
         vfx_string.obj (+RO)
         vfx_page_bar.obj (+RO)
         vapp_widget_shortcut.obj (+RO)
         vapp_home_shortcut_selector.obj (+RO)
         vapp_widget.obj (+RO)
         vapp_widget_kit.obj (+RO)
         vapp_widget_clock.obj (+RO)
         vapp_worldclock_srv.obj (+RO)
         vapp_home_primitive.obj (+RO)
         vapp_home_desktop.obj (+RO)
         vapp_home_bar.obj (+RO)
         vdat_systime.obj (+RO)
         vcp_button.obj (+RO)
         vfx_auto_animate.obj (+RO)
         mac_timer_hdlr.obj (+RO)
         vapp_wallpaper.obj (+RO)
         CharBatSrv.obj (+RO)
;for improve audio boot-up discontinuous sound
         rlc_main.obj (+RO)
         mpal_gprs_ul_msg_hdlr.obj (+RO)
         mpal_gsm_ul_func.obj (+RO)
         rcs_cell.obj (+RO)
         rlc_msg_hdlr.obj (+RO)
         si_class_b.obj (+RO)
         rmc_timer.obj (+RO)
         rcs_plmn.obj (+RO)
         rmc_gprs_sendmsgs.obj (+RO)
         rmpc_common_func.obj (+RO)
         mac_timer_hdlr.obj (+RO)
         rmc_gmm_procs.obj (+RO)
         rlc_ctrl_msg_hdlr.obj (+RO)
         csrr_ded_access.obj (+RO)
         psi_si_utils.obj (+RO)
         mm_ctrl_cell_proc.obj (+RO)
         mm_cs_other.obj (+RO)
         mm_ps_other.obj (+RO)
;Library Base
         *usb.a (+RO)
         *sim_driver.a (+RO)
         *custom.a (+RO)
__TEMPLATE
    }
    else
    {
    	$rom2_temp .= <<"__TEMPLATE";
         .ANY (+RO-CODE)
__TEMPLATE
    }

    # --- --- ---
    # Common contents
    $rom2_temp .= <<"__TEMPLATE";
         * (SECONDARY_ROCODE, SECONDARY_RODATA)
         L6478E.obj (L6478E_fix_1, +Last)
__TEMPLATE

    return $rom2_temp;
}

#****************************************************************************
# subroutine:  NFB Layout 
# input:       bb chip
# output:      template of ROM2_VIDEO regions for work-around for DPv2
#****************************************************************************
sub app_feature_rom2_video
{
    my ($bb) = @_;

    my $ret_string;
    if (&sysUtil::is_arm9($bb)==1)
    {
        $ret_string = <<"__TEMPLATE";
;VideoCodec
         *h264dec.arm9*.a (+RO)
         *h264dec_mphp.arm9*.a (+RO)
         *mp4com.arm9*.a (+RO)
         *mp4dec.arm9*.a (+RO)
         *mp4dec_asp.arm9*.a (+RO)
         *mp4com_asp.arm9*.a (+RO)
         *mp4enc.arm9.arm9tcm*.a (+RO)
         *uvtdec.arm9*.a (+RO)
         *uvtenc.arm9*.a (+RO)
         *rmdec.arm9*.a (+RO)
__TEMPLATE
}
    chomp $ret_string;
    return $ret_string;
}

#****************************************************************************
# subroutine:  NFB Layout 
# input:       bb chip, dsp solution, ramsize
# output:      template of DSP_ROM 6256 load region+execution region
#****************************************************************************
sub DSP_MT6256_DSPROM
{
	my ($bb, $dsp_solution, $RamSize) = @_;
	if ($bb eq "MT6256" and defined $dsp_solution and $dsp_solution eq "DUALMACDSP")
	{
		&sysUtil::sysgen_die("tools/scatGenLib.pl: DSP_MT6256 can't exist with original DSP regions", __FILE__, __LINE__); 
	}
	my $template;
	if( $bb eq "MT6256")
	{
		my ($Tx1Base, $Tx2Base, $DSPOnlyBase, $RxBase, $DSP_RomBase)= &Query_DSP_MT6256_Info(2, $RamSize);
		my ($Tx1Size, $Tx2Size, $DSPOnlySize, $RxSize, $DSP_RomSize)= &Query_DSP_MT6256_Info(1, $RamSize);
		$template = <<"__TEMPLATE";
DSP_ROM $DSP_RomBase $DSP_RomSize
{
    DSP_ROM $DSP_RomBase $DSP_RomSize
    {
    }
}
__TEMPLATE
		chomp $template;
	}
	return $template;
}

#****************************************************************************
# subroutine:  NFB Layout 
# input:       bb chip, dsp solution, ramsize
# output:      NAND:template of 2ndRom DSP 6256 execution regions
#****************************************************************************
sub DSP_MT6256_EV
{
    my ($bb, $PrefixRegion, $dsp_solution, $RamSize) = @_;
	if ($bb eq "MT6256" and defined $dsp_solution and $dsp_solution eq "DUALMACDSP")
	{
		&sysUtil::sysgen_die("tools/scatGenLib.pl: DSP_MT6256 can't exist with original DSP regions", __FILE__, __LINE__); 
	}
	my $template;
	if( $bb eq "MT6256")
	{
		my ($Tx1Base, $Tx2Base, $DSPOnlyBase, $RxBase, $DSP_RomBase)= &Query_DSP_MT6256_Info(2, $RamSize);
		my ($Tx1Size, $Tx2Size, $DSPOnlySize, $RxSize, $DSP_RomSize)= &Query_DSP_MT6256_Info(1, $RamSize);
		$template = "\; DSP execution regions cannot be modified\n";
        $template .= &format_execution_view( $PrefixRegion."_DSP_RW_MCU_RW_TX1",
                                          $Tx1Base,
                                          $Tx1Size,
                                          ["*.obj (EXTRAM_TXDATA_0)"]
                                        );
        $template .= &format_execution_view( $PrefixRegion."_DSP_RW_MCU_RW_DMA_RW_TX2_AND_RX",
                                          $Tx2Base,
                                          $Tx2Size,
                                          ["*.obj (EXTRAM_TXDATA)",
         								   "*.obj (EXTRAM_RXDATA)"]
                                        );
        $template .= &format_execution_view( $PrefixRegion."_DSP_RW_DSPONLY",
                                          $DSPOnlyBase,
                                          $DSPOnlySize,
                                          [""]
                                        );
        $template .= &format_execution_view( $PrefixRegion."_DSP_DMA_RX",
                                          $RxBase,
                                          $RxSize,
                                          ["m12161.obj (EXTRAM_RXDATA)"]
                                        );
	}
	return $template;
}


#****************************************************************************
# subroutine:  NFB Layout 
# input:       Choice=1: return Region MaxSize,
#                     2: return Base Address, default: 1  
#              RamSize or no input
# output:      return Base address if input=2 or 
#              return Size if input=1 of 5 related regions 
#****************************************************************************
sub Query_DSP_MT6256_Info
{
    my ($Choice, $RamSize) = @_;
    my ($Tx1, $Tx2, $DSPOnly, $Rx, $DSP_Rom);
    $Choice =1 if(!defined $Choice or (($Choice ne "1") and ($Choice ne "2")));
    
    #default value= Region MaxSize
    $DSP_Rom = 0x5f000; #DSP_ROM
    $Tx1     = 0x6000;  #SECONDARY_EXTSRAM_DSP_RW_MCU_RW_TX1
    $Tx2     = 0x2000;  #SECONDARY_EXTSRAM_DSP_RW_MCU_RW_DMA_RW_TX2_AND_RX
    $DSPOnly = 0x18000; #SECONDARY_EXTSRAM_DSP_RW_DSPONLY
    $Rx      = 0x10000; #SECONDARY_EXTSRAM_DSP_DMA_RX

    if(defined $RamSize && $Choice eq "2")
    {   #Base Address
        $Rx      = $RamSize - $Rx ;
        $DSPOnly = $Rx      - $DSPOnly ;
        $Tx2     = $DSPOnly - $Tx2 ;
        $Tx1     = $Tx2     - $Tx1 ;
        $DSP_Rom = $Tx1     - $DSP_Rom ;
    }
    return (&CommonUtil::Dec2Hex($Tx1), &CommonUtil::Dec2Hex($Tx2), &CommonUtil::Dec2Hex($DSPOnly), &CommonUtil::Dec2Hex($Rx), &CommonUtil::Dec2Hex($DSP_Rom));
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: EXTSRAM :: DSP
# input:       ram start address <value> , ram size <value>
#****************************************************************************
sub DSPTXRX
{
    my ($bb, $prefix_name, $baseaddr, $ram_size, $region_size_tx, $region_size_rx) = @_;
    my $tx_addr = sprintf("0x%08x", $baseaddr + $ram_size - $region_size_tx - $region_size_rx);
    my $rx_addr = sprintf("0x%08x", $baseaddr + $ram_size - $region_size_rx);
    my $ev_len_tx  = sprintf("0x%x", $region_size_tx);
    my $ev_len_rx  = sprintf("0x%x", $region_size_rx);
    my $ev_dsp  = <<"__DSPTEMPLATE";
; DSP execution regions cannot be OVERLAY; its size should be specified as 2^N, larger than 4KB, and should be 32K aligned with its start and END address
    ${prefix_name}_DSP_TX $tx_addr ABSOLUTE $ev_len_tx
    {
         *.obj (EXTRAM_TXDATA)
    }
    ${prefix_name}_DSP_RX $rx_addr $ev_len_rx
    {
         *.obj (EXTRAM_RXDATA)
    }
__DSPTEMPLATE

    # --- --- --- 
    my %BBtbl_DSPTXRX =
       (        'MT6235'  => 1,
                'MT6235B' => 1,
                'MT6236'  => 1,
                'MT6236B' => 1,
                'MT6921'  => 1,
                'MT6268'  => 1,
                'MT6253'  => 1,
                'MT6516'  => 1,
                'MT6276'  => 1,
                'MT6253E' => 1,
                'MT6253L' => 1,
                'MT6252H' => 1,
                'MT6252'  => 1,
                'MT6573'  => 1,
                'MT6575'  => 1,
                'MT6255'  => 1,
                'MT6922'  => 1,
                'MT6250'  => 1,                
                'MT6280'  => 1,
       );
       #map {print $_, "\n";} keys %BBtbl;

    if (defined $BBtbl_DSPTXRX{$bb} and $BBtbl_DSPTXRX{$bb})
    {
        return $ev_dsp;
    }
}

#****************************************************************************
# Global Table  ,  MCU/DSP Share Memory table
#****************************************************************************
    my %MCU_DSP_ShareTbl_InKB =
       (
             'AUDIO' => ['64', 'MCU_NC_DSP_NC'],
             'VIDEO' => ['64', 'MCU_NC_DSP_NC'],
             'DSSYS' => ['4', 'MCU_NC_DSP_NC'],
             'UART'  => ['16', 'MCU_NC_DSP_NC'],
       );

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: EXTSRAM :: DSP :: Size of DSP_SHAREMEM query
# input:       ram start address <value> , ram size <value>
#****************************************************************************
sub DSP_SHAREMEM_query_length
{
    my ($bb) = @_;
    my ($len_mcu_c_dsp_c, $len_mcu_c_dsp_nc, $len_mcu_nc_dsp_c, $len_mcu_nc_dsp_nc) = (0, 0, 0, 0);
    my $dsp_sharemem_len = 0;

    # --- --- --- 
    my %BBtbl_ShareMem =
       (
           'MT6276'  => ['AUDIO', 'VIDEO', 'DSSYS', 'UART'],
           'MT6573'  => ['AUDIO', 'VIDEO', 'DSSYS', 'UART'],
           'MT6575'  => ['AUDIO', 'VIDEO', 'DSSYS', 'UART'],
       );

    if (defined $BBtbl_ShareMem{$bb})
    {
        my $sharemem_list = $BBtbl_ShareMem{$bb};
        my $idx = 0;
        while (defined $sharemem_list->[$idx])
        {
            my $sharemem_key = $sharemem_list->[$idx];
            if ($MCU_DSP_ShareTbl_InKB{$sharemem_key}->[1] eq 'MCU_C_DSP_C')
            {
                $len_mcu_c_dsp_c += $MCU_DSP_ShareTbl_InKB{$sharemem_key}->[0];
            }
            elsif ($MCU_DSP_ShareTbl_InKB{$sharemem_key}->[1] eq 'MCU_C_DSP_NC')
            {
                $len_mcu_c_dsp_nc += $MCU_DSP_ShareTbl_InKB{$sharemem_key}->[0];
            }
            elsif ($MCU_DSP_ShareTbl_InKB{$sharemem_key}->[1] eq 'MCU_NC_DSP_C')
            {
                $len_mcu_nc_dsp_c += $MCU_DSP_ShareTbl_InKB{$sharemem_key}->[0];
            }
            elsif ($MCU_DSP_ShareTbl_InKB{$sharemem_key}->[1] eq 'MCU_NC_DSP_NC')
            {
                $len_mcu_nc_dsp_nc += $MCU_DSP_ShareTbl_InKB{$sharemem_key}->[0];
            }
            $idx++;
        }
    }
    if ($bb eq 'MT6276')
    {
    	$len_mcu_nc_dsp_nc = 96;
    }
    elsif($bb eq 'MT6573' or $bb eq 'MT6575')
    {
    	$len_mcu_nc_dsp_nc = 64;
    }
    $len_mcu_c_dsp_c = ceil($len_mcu_c_dsp_c/32) * 32 * 1024;
    $len_mcu_c_dsp_nc = ceil($len_mcu_c_dsp_nc/32) * 32 * 1024;
    $len_mcu_nc_dsp_c = ceil($len_mcu_nc_dsp_c/32) * 32 * 1024;
    $len_mcu_nc_dsp_nc = ceil($len_mcu_nc_dsp_nc/32) * 32 * 1024;
    $dsp_sharemem_len = $len_mcu_c_dsp_c + $len_mcu_c_dsp_nc + $len_mcu_nc_dsp_c + $len_mcu_nc_dsp_nc;

    return ($dsp_sharemem_len, $len_mcu_c_dsp_c, $len_mcu_c_dsp_nc, $len_mcu_nc_dsp_c, $len_mcu_nc_dsp_nc);
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: EXTSRAM :: DSP
# input:       ram start address <value> , ram size <value>
#****************************************************************************
sub DSP_SHAREMEM_EV
{
    my ($bb, $prefix_name, $dsp_sharemem_base, $len_mcu_c_dsp_c, $len_mcu_c_dsp_nc, $len_mcu_nc_dsp_c, $len_mcu_nc_dsp_nc) = @_;
    my ($region_base, $region_base_str, $region_len_str);
    my $ev_dsp;

    $region_base = $dsp_sharemem_base;
    if ($len_mcu_c_dsp_c != 0)
    {
        $region_base_str = sprintf("0x%08x", $region_base | 0xf0000000);
        $region_len_str = sprintf("0x%08x", $len_mcu_c_dsp_c);
        $ev_dsp .= <<"__DSPTEMPLATE";
; MCU and DSP shared memory pool, should be 32KB-aligned
    ${prefix_name}_MCU_C_DSP_C_SHAREMEM $region_base_str $region_len_str
    {
         *.obj (DMDSP_SHARE_MCU_C_DSP_C_RODATA, DMDSP_SHARE_MCU_C_DSP_C_RW, DMDSP_SHARE_MCU_C_DSP_C_ZI)
    }
__DSPTEMPLATE
    }
    if ($len_mcu_c_dsp_nc != 0)
    {
        $region_base_str = sprintf("0x%08x", $region_base | 0xf0000000);
        $region_len_str = sprintf("0x%08x", $len_mcu_c_dsp_nc);
        $ev_dsp .= <<"__DSPTEMPLATE";
; MCU and DSP shared memory pool, should be 32KB-aligned
    ${prefix_name}_MCU_C_DSP_NC_SHAREMEM $region_base_str $region_len_str
    {
         *.obj (DMDSP_SHARE_MCU_C_DSP_NC_RODATA, DMDSP_SHARE_MCU_C_DSP_NC_RW, DMDSP_SHARE_MCU_C_DSP_NC_ZI)
    }
__DSPTEMPLATE
    }
    if ($len_mcu_nc_dsp_c != 0)
    {
        $region_base_str = sprintf("0x%08x", $region_base);
        $region_len_str = sprintf("0x%08x", $len_mcu_nc_dsp_c);
        $ev_dsp .= <<"__DSPTEMPLATE";
; MCU and DSP shared memory pool, should be 32KB-aligned
    ${prefix_name}_MCU_NC_DSP_C_SHAREMEM $region_base_str $region_len_str
    {
         *.obj (DMDSP_SHARE_MCU_NC_DSP_C_RODATA, DMDSP_SHARE_MCU_NC_DSP_C_RW, DMDSP_SHARE_MCU_NC_DSP_C_ZI)
    }
__DSPTEMPLATE
    }
    if ($len_mcu_nc_dsp_nc != 0)
    {
        $region_base_str = sprintf("0x%08x", $region_base);
        $region_len_str = sprintf("0x%08x", $len_mcu_nc_dsp_nc);
        $ev_dsp .= <<"__DSPTEMPLATE";
; MCU and DSP shared memory pool, should be 32KB-aligned
    ${prefix_name}_MCU_NC_DSP_NC_SHAREMEM $region_base_str $region_len_str
    {
         *.obj (DMDSP_SHARE_MCU_NC_DSP_NC_RODATA, DMDSP_SHARE_MCU_NC_DSP_NC_RW, DMDSP_SHARE_MCU_NC_DSP_NC_ZI)
         *.obj (DMDSP_SHARE_DSSYS_RODATA, DMDSP_SHARE_DSSYS_RW, DMDSP_SHARE_DSSYS_ZI)
         *.obj (DMDSP_SHARE_UART_RODATA, DMDSP_SHARE_UART_RW, DMDSP_SHARE_UART_ZI)
         *.obj (DMDSP_SHARE_VIDEO_RODATA, DMDSP_SHARE_VIDEO_RW, DMDSP_SHARE_VIDEO_ZI)
         *.obj (DMDSP_SHARE_AUDIO_RODATA, DMDSP_SHARE_AUDIO_RW, DMDSP_SHARE_AUDIO_ZI)
    }
__DSPTEMPLATE
    }

    my $dsp_solution = &$feature_query_function_ptr('dsp_solution');
    if (defined $dsp_solution and $dsp_solution eq 'DUALMACDSP')
    {
        return $ev_dsp;
    }
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: EXTSRAM :: CACHED_EXTSRAM
#****************************************************************************
sub CACHED_EXTSRAM_EV
{
    my ($base_addr) = @_;
    my $strVernoInputSection = "         * (RELEASE_VERNO_RW, RELEASE_BRANCH_RW, BUILD_TIME_RW)";
    $strVernoInputSection = "" if(!&FileInfo::is_NOR() and $g_nfb_or_emb ne "BASIC" and $g_nfb_or_emb ne "SINGLE");
    my $template = <<"__TEMPLATE";
    CACHED_EXTSRAM $base_addr
    {
; All RW/ZI are put in CACHED region by default
         * (+RW, +ZI)
         * (CACHED_EXTSRAM_RW, CACHED_EXTSRAM_ZI)
$strVernoInputSection
    }
    CACHED_EXTSRAM_PREINIT_ZI +0x0
    {         
; data passed from bootloader to maui
        * (CACHED_EXTSRAM_PREINIT_ZI)
    }
__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: EXTSRAM :: ROM_SIGNATURE_SECTION
#****************************************************************************
sub ROM_SIGNATURE_SECTION_EV
{
    my ($bb, $region_prefix, $pragma_prefix) = @_;
    my $template;
    if (&sysUtil::is_sv5($bb) == 1)
    {
        $template = <<"__TEMPLATE";
    ${region_prefix}_SIGNATURE_SECTION +0x0
    {
         *                             (${pragma_prefix}_SIGNATURE_SECTION)
    }
__TEMPLATE
    }
    chomp $template;

    return $template;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: INTSRAM type 3 :: 6251
# input:       BB
# remark:      INTSRAM only
#****************************************************************************
sub INTSRAM_type3
{
    my ($bb) = @_;

    my $intsram_base = 0x40000200;  # 0x200 is for vector table
    my $intsram_base_str = sprintf("0x%08x", $intsram_base);
    my $single_bank_code = &SINGLE_BANK_CODE($bb, "INTSRAM_SINGLE_BANK_CODE", $intsram_base_str, "0x1600");
    if (defined $single_bank_code)
    {
        $intsram_base_str = "0x40001800";
    }
    chomp $single_bank_code;
    
    ### RES_PROT region
    my $res_prot = &app_feature_res_prot($bb);
    my $res_prot_region_calc = ($res_prot eq '') ? "" : " + ImageLength(INTSRAM_PROTECTED_RES)";
    
    my $intsram_6251 = <<"__6251";
$single_bank_code
    EMIINIT_CODE $intsram_base_str OVERLAY
    {
         * (EMIINITCODE, EMIINITCONST, EMIINITZI, EMIINITRW)
    }
    INTSRAM_CODE $intsram_base_str OVERLAY 0xC00
    {
; Please do NOT remove any content below!
         * (INTSRAM_ROCODE)
         * (INTSRAM_ROCODE_*)
         switch8.o (+RO-CODE)
         uread4.o (+RO-CODE, +RO-DATA)
         uwrite4.o (+RO-CODE, +RO-DATA)
         * (SNORCODE_INT)
         * (SNORCONST_INT)
; Please do NOT remove any content above!
    }
    INTSRAM_DATA 0x40002400 0x5D800
    {
; Please do NOT remove any content below!
         * (INTSRAM_RODATA, INTSRAM_RW, INTSRAM_ZI)
         * (INTSRAM_RODATA_*, INTSRAM_RW_*, INTSRAM_ZI_*)
         * (+RW, +ZI)
         * (RELEASE_VERNO_RW, RELEASE_BRANCH_RW, BUILD_TIME_RW)         
; Please do NOT remove any content above!
    }   
    INTSRAM_DATA_PREINIT +0x0 0x5D800
    {
; Please do NOT remove any content below!
         * (PREINIT_INTSRAM_RODATA, PREINIT_INTSRAM_RW, PREINIT_INTSRAM_ZI)
         uart.obj (INTSRAM_RODATA, INTSRAM_RW, INTSRAM_ZI)
         *sys_drv.a (INTSRAM_RODATA, INTSRAM_RW, INTSRAM_ZI)
         *sys_svc.a (INTSRAM_RODATA, INTSRAM_RW, INTSRAM_ZI)
         *init.a (INTSRAM_RODATA, INTSRAM_RW, INTSRAM_ZI)
; system-realted data
         bootarm_rvct.obj (STACK_POOL_INTSRAM)
; Please do NOT remove any content above!
    }
    INTSRAM_DATA_NVRAM_LTABLE +0x0 0x5D800
    {
         * (_nvram_ltable)
         * (_indirect_init)
         * (_fs_filetable)
         * (_nvram_callback_tbl)
    }
$res_prot
    INTSRAM_DSP_TX_RX 0x4005FC00 0x400
    {
         *.obj (EXTRAM_TXDATA)
         *.obj (EXTRAM_RXDATA)
    }
    ScatterAssert((ImageLength(INTSRAM_DATA) + ImageLength(INTSRAM_DATA_PREINIT) + ImageLength(INTSRAM_DATA_NVRAM_LTABLE)$res_prot_region_calc) < 0x5D800)
__6251

    return $intsram_6251;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: INTSRAM type 1
# input:       BB
# remark:      INTSRAM_CODE INTSRAM_DATA
#****************************************************************************
sub INTSRAM_type1
{
    my ($bb) = @_;
    my $comm_intsram_code  = &INTSRAM_CODE_OBJ_system($bb);
    my $comm_intsram_data  = &INTSRAM_DATA_OBJ_system($bb);
    my $other_intsram_code = &INTSRAM_CODE_OBJ_others($bb);
    my $other_intsram_data = &INTSRAM_DATA_OBJ_others($bb);
    # --- --- --- 
    chomp $comm_intsram_code;
    chomp $comm_intsram_data;
    chomp $other_intsram_code;
    chomp $other_intsram_data;
    my $template_6236 = <<"__TEMPLATE_6236";
    INTSRAM_MM_DATA 0x50112800 0x00018800
    {
         * (INTSRAM_MM_RODATA, INTSRAM_MM_RW, INTSRAM_MM_ZI)
    }
__TEMPLATE_6236
    # --- --- --- 
    my $template_6253 = <<"__TEMPLATE_6253";
; Because MT6253 Internal RAM is tight, and med_main.obj and MP4DEC2 will not be used at simultaneously,
; on MT6253 platforms, the buffer in med_main.obj will be shared between JPEG and MP4DEC2.
; (Originally MP4DEC2 uses the DCM region shared with audio.)
; The sharing is used to make concurrency for audio and MP4DEC2
    MED_MAIN_REGION 0x4000CC70 OVERLAY 0x9600
    {
         mm_intmem_mt6253.obj (INTERNRW1, INTERNZI1)
         btmt_mem.obj (INTSRAM_RW, INTSRAM_ZI)
    }
__TEMPLATE_6253
    # --- --- --- 
    my ($l2tcm_data_76, $l2tcm_region, $flexl2_region);
    if ((&$feature_query_function_ptr('chip_ver') eq 'S00' and $bb eq "MT6276") or $bb eq "MT6573")
    {
    	  $l2tcm_data_76 = <<"__TEMPLATE_L2TCM_DATA";
; moved from L2TCM, work-around for L2TCM issue
         * (L2TCM_RW, L2TCM_ZI)
__TEMPLATE_L2TCM_DATA

        $flexl2_region = <<"__TEMPLATE_FLEXL2_REGION";
    FLEXL2_DATA 0x90000000 0x10000
    {
        * (FLEXL2_RW, FLEXL2_ZI)
    }
__TEMPLATE_FLEXL2_REGION
    }
    else
    {
    	  $l2tcm_region = <<"__TEMPLATE_L2TCM_REGION";
    L2TCM_DATA 0x58012000 0x3000
    {
        * (L2TCM_RW, L2TCM_ZI)
    }
__TEMPLATE_L2TCM_REGION
    }
    chomp $l2tcm_data;
    chomp $l2tcm_region;
    chomp $flexl2_region;

    my $template_6276 = <<"__TEMPLATE_6276";
    L2TCM_CODE 0x58000000 0x12000
    {
        * (L2TCM_RODATA, L2TCM_ROCODE)
    }
$l2tcm_region
$flexl2_region
__TEMPLATE_6276
    # --- --- --- 
    my $template_6573 = <<"__TEMPLATE_6573";
    L2TCM_CODE 0x58000000 0x12000
    {
        * (L2TCM_RODATA, L2TCM_ROCODE)
    }
    FLEXL2_DATA 0x90000000 0x10000
    {
        * (FLEXL2_RW, FLEXL2_ZI)
    }
__TEMPLATE_6573
    # --- --- --- 
    my $template_6575 = <<"__TEMPLATE_6575";
    L2TCM_CODE 0x58000000 0x12000
    {
        * (L2TCM_RODATA, L2TCM_ROCODE)
    }
    L2TCM_DATA 0x58012000 0x3000
    {
        * (L2TCM_RW, L2TCM_ZI)
    }
__TEMPLATE_6575
    # --- --- --- --- --- --- --- --- --- --- --- 
    my ($strCODE_Base, $strCODE_Size, $strDATA_Base, $strDATA_Size) = sysUtil::GetIntsramInfo($bb);
    &sysUtil::sysgen_die("tools/scatGenLib.pl: unsupported $bb!", __FILE__, __LINE__) if(!defined $strCODE_Base or !defined $strCODE_Size or !defined $strDATA_Base or !defined $strDATA_Size ); 
    my $template_INTERSARM_HW_BOUNDARY = undef;
    if(&sysUtil::is_CR4($bb) == 1)
    {
        my ($strHW_Base, $strHW_Size) = sysUtil::GetIntsramHWBoundary($bb, sysUtil::INTSRAM_HW_BOUNDARY);
        &sysUtil::sysgen_die("tools/scatGenLib.pl: unsupported $bb - intsram HW boundary!", __FILE__, __LINE__) if(!defined $strHW_Base or !defined $strHW_Size); 
        $template_INTERSARM_HW_BOUNDARY = <<"_TEMPLATE_INTSRAM_HW";
    ;Defined ATCM or BTCM HW boundary
    INTSRAM_PHYSICAL_BOUNDARY $strHW_Base OVERLAY $strHW_Size
    {
         ;Only for getting linker symbol
    }
    ScatterAssert((ImageBase(INTSRAM_CODE) + ImageLength(INTSRAM_CODE) + ImageLength(INTSRAM_DATA)) < ($strHW_Base+$strHW_Size))
_TEMPLATE_INTSRAM_HW
    }
    else
    {
        my $strDummyEndBase = &CommonUtil::Dec2Hex(hex($strDATA_Base) + hex($strDATA_Size));
        $template_INTERSARM_HW_BOUNDARY = <<"_TEMPLATE_INTSRAM_HW";
    INTSRAM_DUMMY_END $strDummyEndBase
    {
         bootarm.obj (INTSRAM_END)
    }
_TEMPLATE_INTSRAM_HW
    }
    my $template_PAST_INTERSARM = <<"_TEMPLATE_INTSRAM";
    EMIINIT_CODE $strCODE_Base OVERLAY
    {
         * (EMIINITCODE, EMIINITCONST, EMIINITZI, EMIINITRW)
    }
    INTSRAM_CODE $strCODE_Base OVERLAY $strCODE_Size
    {
; Please do NOT remove any content below!
         * (INTSRAM_ROCODE)
         * (INTSRAM_ROCODE_*)
         switch8.o (+RO-CODE)
$comm_intsram_code
$other_intsram_code
; Please do NOT remove any content above!
    }
    INTSRAM_DATA $strDATA_Base ABSOLUTE $strDATA_Size
    {
; Please do NOT remove any content below!
         * (INTSRAM_RODATA, INTSRAM_RW, INTSRAM_ZI)
         * (INTSRAM_RODATA_*, INTSRAM_RW_*, INTSRAM_ZI_*)
$comm_intsram_data
$other_intsram_data
$l2tcm_data_76
; Please do NOT remove any content above!
    }
_TEMPLATE_INTSRAM
    my $template_INTSRAM_DATA_PREINIT_Others = <<"_TEMPLATE_INTSRAM_DATA_PREINIT_Others";
; Please do NOT remove any content below!
         uart.obj (INTSRAM_RODATA, INTSRAM_RW, INTSRAM_ZI)
         *sys_drv.a (INTSRAM_RODATA, INTSRAM_RW, INTSRAM_ZI)
         *sys_svc.a (INTSRAM_RODATA, INTSRAM_RW, INTSRAM_ZI)
         *init.a (INTSRAM_RODATA, INTSRAM_RW, INTSRAM_ZI)
; system-realted data
         bootarm.obj (STACK_POOL_INTSRAM)
; Please do NOT remove any content above!
_TEMPLATE_INTSRAM_DATA_PREINIT_Others
    $template_INTSRAM_DATA_PREINIT_Others = "" unless ($bb =~/6253|6252|6250/);

    my $template_INTERSARM = <<"_TEMPLATE_INTSRAM";
$template_PAST_INTERSARM
    INTSRAM_DATA_PREINIT +0x0 $strDATA_Size
    {
; data passed from bootloader to maui
         * (PREINIT_INTSRAM_RODATA, PREINIT_INTSRAM_RW, PREINIT_INTSRAM_ZI)
$template_INTSRAM_DATA_PREINIT_Others
    }
$template_INTERSARM_HW_BOUNDARY
_TEMPLATE_INTSRAM
    # --- --- --- --- --- --- --- --- --- --- --- 
    my %BBtbl =
       (        'MT6516'  => sub { $template_PAST_INTERSARM ;},
                'MT6235'  => sub { $template_PAST_INTERSARM ;},
                'MT6235B' => sub { $template_PAST_INTERSARM ;},
                'MT6236'  => sub { $template_PAST_INTERSARM. $template_6236 ;},
                'MT6236B' => sub { $template_PAST_INTERSARM. $template_6236 ;},
                'MT6921'  => sub { $template_PAST_INTERSARM. $template_6236 ;},
                'MT6268'  => sub { $template_PAST_INTERSARM ;},
                'MT6253'  => sub { $template_PAST_INTERSARM. $template_6253 ;},
                'MT6276'  => sub { $template_PAST_INTERSARM. $template_6276 ;},
                'MT6253E' => sub { $template_INTERSARM ;},
                'MT6253L' => sub { $template_INTERSARM ;},
                'MT6252H' => sub { $template_INTERSARM ;},
                'MT6252'  => sub { $template_INTERSARM ;},
                'MT6250'  => sub { $template_INTERSARM ;},                
                'MT6573'  => sub { $template_PAST_INTERSARM. $template_6573 ;},
                'MT6575'  => sub { $template_PAST_INTERSARM. $template_6575 ;},
                'MT6256'  => sub { $template_PAST_INTERSARM ;},
                'MT6255'  => sub { $template_PAST_INTERSARM ;},
                'MT6922'  => sub { $template_PAST_INTERSARM ;},
                'TK6280'  => sub { $template_PAST_INTERSARM. $template_INTERSARM_HW_BOUNDARY ;},
                'MT6280'  => sub { $template_PAST_INTERSARM. $template_INTERSARM_HW_BOUNDARY ;},
       );
    #map {my $func = $BBtbl{$_}; print &$func . "\n";} keys %BBtbl;
    &sysUtil::sysgen_die("tools/scatGenLib.pl: unsupported $bb!", __FILE__, __LINE__) if not exists $BBtbl{$bb}; 
    my $func = $BBtbl{$bb};
    return &$func;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: INTSRAM type :: INTSRAM CODE content :: system
# input:       BB
# remark:      But regard it 
#****************************************************************************
sub INTSRAM_CODE_OBJ_system
{
    my ($bb) = @_;
    my $template_sys = << "__TEMPLATE";
; system-realted CODE , STANDARD set
         bootarm_rvct.obj (INTERNCODE)
         data_buff_pool.obj (INTERNCODE)
         ctrl_buff_pool.obj (INTERNCODE)
         stack_buff_pool.obj (INTERNCODE)
         stack_ltlcom.obj (INTERNCODE)
         stack_timer.obj (INTERNCODE)
         lcd_dll.obj (INTERNCODE)
         event_shed.obj (INTERNCODE)
         SST_intrCtrl.obj (INTERNCODE, INTERNCONST)
__TEMPLATE
    my $template_small_sys = << "__TEMPLATE";
; system-realted CODE , SMALL set
         bootarm_rvct.obj (INTERNCODE)
         data_buff_pool.obj (INTERNCODE)
         ctrl_buff_pool.obj (INTERNCODE)
         stack_buff_pool.obj (INTERNCODE)
         stack_ltlcom.obj (INTERNCODE)
         stack_timer.obj (INTERNCODE)
         SST_intrCtrl.obj (INTERNCODE, INTERNCONST)
__TEMPLATE
    my $template_extra_small_sys = << "__TEMPLATE";
; system-realted CODE , Extra SMALL set
         bootarm_rvct.obj (INTERNCODE)
         SST_intrCtrl.obj (INTERNCODE, INTERNCONST)
__TEMPLATE
    my $template_arm9_above_sys = << "__TEMPLATE";
; system-realted CODE , ARM9/ARM11/CR4 Family STANDARD set
         bootarm_rvct.obj (INTERNCODE)
         stack_timer.obj (INTERNCODE)
         data_buff_pool.obj (INTERNCODE)
__TEMPLATE
    my $template_arm9_above_small_sys = << "__TEMPLATE";
; system-realted CODE , ARM9/ARM11/CR4 Family SMALL set
         bootarm_rvct.obj (INTERNCODE)
__TEMPLATE
    my $template_cr4_clib = << "__TEMPLATE";
         dflt.o (+RO-CODE)
         uread4.o (+RO-CODE)
         lludiv5.o (+RO-CODE)
__TEMPLATE
    # --- --- --- 
    my $template_lib = << "__TEMPLATE";
; common used C library
         memset.o (+RO-CODE, +RO-DATA)
         rt_memclr.o (+RO-CODE, +RO-DATA)
         callvia.o (+RO-CODE, +RO-DATA)
         _sprintf.o (+RO-CODE, +RO-DATA)
         rt_memcpy.o (+RO-CODE, +RO-DATA)
         lludiv10.o (+RO-CODE, +RO-DATA)
         rt_udiv.o (+RO-CODE, +RO-DATA)
         uread4.o (+RO-CODE, +RO-DATA)
         uwrite4.o (+RO-CODE, +RO-DATA)
__TEMPLATE
    # --- --- --- 
    my $template_nucleus = << "__TEMPLATE";
; Nucleus-related CODE , STANDARD set
         tct.obj (INTERNCODE)
; INTERNCODE_TP needs to be put in INTSRAM along with tct.obj (INTERNCODE)
         * (INTERNCODE_TP)
         tcc.obj (INTERNCODE)
         csc.obj (INTERNCODE)
         tmt.obj (+RO)
         tms.obj (+RO)
         smc.obj (+RO)
         evc.obj (+RO)
         pmc.obj (+RO)
         quc.obj (+RO)
         kal_nucleus_buff_mgr.obj (INTERNCODE)
         kal_nucleus_evshed_buff_mgr.obj (INTERNCODE)
         kal_nucleus_itc.obj (INTERNCODE)
         kal_nucleus_timer.obj (INTERNCODE)
__TEMPLATE
    my $template_small_nucleus = << "__TEMPLATE";
; Nucleus-related CODE , SMALL set
         tct.obj (INTERNCODE)
; INTERNCODE_TP needs to be put in INTSRAM along with tct.obj (INTERNCODE)
         * (INTERNCODE_TP)
         tcc.obj (INTERNCODE)
         csc.obj (INTERNCODE)
         tmt.obj (+RO)
         smc.obj (INTERNCODE)
         evc.obj (INTERNCODE)
         pmc.obj (INTERNCODE)
         quc.obj (INTERNCODE)
         kal_nucleus_buff_mgr.obj (INTERNCODE)
         kal_nucleus_evshed_buff_mgr.obj (INTERNCODE)
         kal_nucleus_itc.obj (INTERNCODE)
         kal_nucleus_timer.obj (INTERNCODE)
__TEMPLATE
    my $template_extra_small_nucleus = << "__TEMPLATE";
; Nucleus-related CODE , Extra SMALL set
         tct.obj (INTERNCODE)
; INTERNCODE_TP needs to be put in INTSRAM along with tct.obj (INTERNCODE)
         * (INTERNCODE_TP)
         tmt.obj (+RO)
         kal_nucleus_timer.obj (INTERNCODE)
__TEMPLATE
    my $template_nfb_nucleus = << "__TEMPLATE";
; Nucleus-related CODE , NFB set
         tct.obj (INTERNCODE)
; INTERNCODE_TP needs to be put in INTSRAM along with tct.obj (INTERNCODE)
         * (INTERNCODE_TP)
         tcc.obj (+RO)
         csc.obj (+RO)
         tmt.obj (+RO)
         tms.obj (+RO)
         smc.obj (+RO)
         evc.obj (+RO)
         pmc.obj (+RO)
         quc.obj (+RO)
         kal_nucleus_buff_mgr.obj (INTERNCODE)
         kal_nucleus_evshed_buff_mgr.obj (INTERNCODE)
         kal_nucleus_itc.obj (INTERNCODE)
         kal_nucleus_timer.obj (INTERNCODE)
__TEMPLATE
    my $template_nfb_small_nucleus = << "__TEMPLATE";
; Nucleus-related CODE , NFB set (Small Configure)
         tct.obj (INTERNCODE)
; INTERNCODE_TP needs to be put in INTSRAM along with tct.obj (INTERNCODE)
         * (INTERNCODE_TP)
         tcc.obj (INTERNCODE)
         csc.obj (INTERNCODE)
         tmt.obj (INTERNCODE)
         tms.obj (INTERNCODE)
         smc.obj (INTERNCODE)
         evc.obj (INTERNCODE)
         pmc.obj (INTERNCODE)
         quc.obj (INTERNCODE)
         kal_nucleus_buff_mgr.obj (INTERNCODE)
         kal_nucleus_evshed_buff_mgr.obj (INTERNCODE)
         kal_nucleus_itc.obj (INTERNCODE)
         kal_nucleus_timer.obj (INTERNCODE)
__TEMPLATE
    my $template_arm9_above_nucleus = << "__TEMPLATE";
; Nucleus-related CODE , ARM9/ARM11/CR4 Family STANDARD set
         csc.obj (INTERNCODE)
         pmc.obj (INTERNCODE)
         tcc.obj (INTERNCODE)
         tct.obj (INTERNCODE)
; INTERNCODE_TP needs to be put in INTSRAM along with tct.obj (INTERNCODE)
         * (INTERNCODE_TP)
         tmt.obj (+RO)
         kal_nucleus_timer.obj (INTERNCODE)
__TEMPLATE
    my $template_arm9_above_small_nucleus = << "__TEMPLATE";
; Nucleus-related CODE , ARM9/ARM11/CR4 Family SMALL set
         tct.obj (INTERNCODE)
; INTERNCODE_TP needs to be put in INTSRAM along with tct.obj (INTERNCODE)
         * (INTERNCODE_TP)
__TEMPLATE
	my $template_MT6256_small_nucleus = << "__TEMPLATE";
         tcct_common.obj (INTERNCODE)
         esal_ar_int_a.obj (INTERNCODE)
         esal_ar_stk_a.obj (INTERNCODE)
         esal_ts_stk_a.obj (INTERNCODE)
         esal_ts_rte_a.obj (INTERNCODE)
         esal_ts_stk.obj (INTERNCODE, INTERNCONST)
__TEMPLATE
    # --- --- --- 
    my $template_arm9_above_utility = << "__TEMPLATE";
; utilities-related CODE , ARM9/ARM11/CR4 Family STANDARD set
         SST_intrCtrl.obj (INTERNCODE, INTERNCONST)
         emi.obj (INTERNCODE)
         custom_scatstruct.obj (INTERNCODE)
__TEMPLATE
    # --- --- --- 
    my $template_arm9_above_small_utility = << "__TEMPLATE";
; utilities-related CODE , ARM9/ARM11/CR4 Family SMALL set
         SST_intrCtrl.obj (INTERNCODE, INTERNCONST)
         emi.obj (INTERNCODE)
__TEMPLATE

    # --- --- --- 
    my $template;
    my $zimage   = &$feature_query_function_ptr('zimage_support');
    my $nfb_or_emb;
    if (defined &$feature_query_function_ptr('nand_flash_booting') and &$feature_query_function_ptr('nand_flash_booting') ne 'NONE')
    {
    	  $nfb_or_emb = &$feature_query_function_ptr('nand_flash_booting');
    }
    elsif (defined &$feature_query_function_ptr('emmc_booting') and &$feature_query_function_ptr('emmc_booting') ne 'NONE')
    {
    	  $nfb_or_emb = &$feature_query_function_ptr('emmc_booting');
    }
    else
    {
    	  $nfb_or_emb = 'NONE';
    }
    # --- --- --- 
    my %BBtbl_cfg = # Place the MCU list for small configure
       (        'MT6253'  => 1,
       );      
    # --- --- --- 
    my %BBtbl_extra_smallcfg = # Place the MCU list for extra small configure
       (        'MT6253E' => 1,
                'MT6253L' => 1,
                'MT6252H' => 1,
                'MT6252'  => 1,
                'MT6250'  => 1,                
       );      
    # --- --- --- 
    my %BBtbl_arm9_above_small_cfg = # Place the MCU list for small configure of ARM9 Family
       (        'MT6268'  => 1,
                'MT6276'  => 1,
                'MT6573'  => 1,
                'MT6575'  => 1,
                'TK6280'  => 1,
                'MT6280'  => 1,
       );      
    # --- --- --- 
    if (defined $BBtbl_extra_smallcfg{$bb} and $BBtbl_extra_smallcfg{$bb})
    {
       #if (defined $nfb_or_emb and $nfb_or_emb ne 'NONE')
       if(&isNAND($feature_query_function_ptr))
       {
           $template = $template_small_sys . $template .
                       $template_nfb_small_nucleus;
       }
       elsif ($bb eq 'MT6250')
       {
       	   $template = $template_extra_small_sys . $template . $template_lib;    	
       }       
       else
       {
           $template = $template_extra_small_sys . $template .
                       $template_extra_small_nucleus . $template_lib;
       }
    }
    elsif (defined $BBtbl_cfg{$bb} and $BBtbl_cfg{$bb})
    {
       #if (defined $nfb_or_emb and $nfb_or_emb ne 'NONE')
       if(&isNAND($feature_query_function_ptr))
       {
           $template = $template_small_sys . $template .
                       $template_nfb_small_nucleus;
       }
       else
       {
           $template = $template_small_sys . $template .
                       $template_small_nucleus . $template_lib;
       }
    }
    else # small configure ?
    {
       if ( $bb eq "MT6256" or $bb eq 'MT6255' or $bb eq 'MT6922')
       {
			$template_arm9_above_small_nucleus .= $template_MT6256_small_nucleus;
       }
       if(&sysUtil::is_CR4($bb) == 1)
       {
            $template_arm9_above_small_sys .= $template_cr4_clib;
       }
       if ((&sysUtil::is_arm9($bb) == 1) || (&sysUtil::is_arm11($bb) == 1) || (&sysUtil::is_CR4($bb) == 1))
       {
           if (defined $BBtbl_arm9_above_small_cfg{$bb} and $BBtbl_arm9_above_small_cfg{$bb})
           {
                  $template = $template_arm9_above_small_sys . $template .
                  $template_arm9_above_small_nucleus . $template_arm9_above_small_utility;
           }
           else
           {
                  $template = $template_arm9_above_small_sys . $template .
                  $template_arm9_above_small_nucleus . $template_arm9_above_utility;
           }
       }
       elsif (defined $nfb_or_emb and $nfb_or_emb ne 'NONE')
       {
           $template = $template_sys . $template .
                       $template_nfb_nucleus;
       }
       else
       {
           $template = $template_sys . $template .
                       $template_nucleus . $template_lib;
       }
    }
    # --- --- --- 
    return $template;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: INTSRAM type :: INTSRAM DATA content :: system
# input:       BB
# remark:      But regard it 
#****************************************************************************
sub INTSRAM_DATA_OBJ_system
{
    my ($bb) = @_;
    my $template_sys = << "__TEMPLATE";
; system-realted data
         bootarm_rvct.obj (STACK_POOL_INTSRAM)
         stack_init.obj (INTERNCONST, INTERNRW, INTERNZI)
         ctrl_buff_pool.obj (INTERNCONST, INTERNRW, INTERNZI)
         stack_ltlcom.obj (INTERNCONST, INTERNRW, INTERNZI)
__TEMPLATE
    my $template_6252_sys = << "__TEMPLATE";
; system-realted data
         stack_init.obj (INTERNCONST, INTERNRW, INTERNZI)
         ctrl_buff_pool.obj (INTERNCONST, INTERNRW, INTERNZI)
         stack_ltlcom.obj (INTERNCONST, INTERNRW, INTERNZI)
__TEMPLATE
    my $template_6250_sys = << "__TEMPLATE";
; system-realted data
         stack_init.obj (INTERNCONST, INTERNRW, INTERNZI)
__TEMPLATE
    my $template_arm9_above_sys = << "__TEMPLATE";
; system-realted data
         bootarm_rvct.obj (STACK_POOL_INTSRAM)
         ctrl_buff_pool.obj (INTERNCONST, INTERNRW, INTERNZI)
         stack_ltlcom.obj (INTERNCONST, INTERNRW, INTERNZI)
__TEMPLATE
    # --- --- --- 
    my $template_nucleus = << "__TEMPLATE";
; Nucleus-related data ; Standard set
         tst*.obj (INTERNCONST, INTERNRW, INTERNZI)
         tct.obj (+RW, +ZI)
; INTERNRW_TP and INTERNZI_TP need to be put in INTSRAM along with tct.obj
         * (INTERNRW_TP, INTERNZI_TP)
         tcd.obj (INTERNCONST, INTERNRW, INTERNZI)
         tmd.obj (+RW, +ZI)
         evd.obj (+RW, +ZI)
         pmd.obj (+RW, +ZI)
         qud.obj (+RW, +ZI)
         smd.obj (+RW, +ZI)
__TEMPLATE
    # --- --- --- 
    my $template_small_nucleus = << "__TEMPLATE";
; Nucleus-related data ; Small set
         tct.obj (+RW, +ZI)
; INTERNRW_TP and INTERNZI_TP need to be put in INTSRAM along with tct.obj
         * (INTERNRW_TP, INTERNZI_TP)
         tcd.obj (INTERNCONST, INTERNRW, INTERNZI)
         tmd.obj (+RW, +ZI)
         evd.obj (+RW, +ZI)
         pmd.obj (+RW, +ZI)
         qud.obj (+RW, +ZI)
         smd.obj (+RW, +ZI)
__TEMPLATE
    # --- --- --- 
    my $template_nucleus_nfb = << "__TEMPLATE";
; Nucleus-related data ; Standard set on NFB
         *nucleus_critical_data.a (+RW, +ZI)
         *nucleus_ctrl_code.a (+RW, +ZI)
; INTERNRW_TP and INTERNZI_TP need to be put in INTSRAM along with tct.obj
         * (INTERNRW_TP, INTERNZI_TP)
__TEMPLATE
    # --- --- --- 
    # --- --- --- 
    my $template_nucleus_nfb_small = << "__TEMPLATE";
; Nucleus-related data ; Small set on NFB
         *nucleus_critical_data.a (INTERNCONST, INTERNRW, INTERNZI)
         *nucleus_ctrl_code.a (INTERNDATA)
; INTERNRW_TP and INTERNZI_TP need to be put in INTSRAM along with tct.obj
         * (INTERNRW_TP, INTERNZI_TP)
__TEMPLATE
    # --- --- --- 
     my $template_nucleus_arm9_above = << "__TEMPLATE";
; Nucleus-related data ; ARM9/ARM11/CR4 Family STANDARD set
         *nucleus_critical_data.a (+RW, +ZI)
         *nucleus_ctrl_code.a (+RW, +ZI)
; INTERNRW_TP and INTERNZI_TP need to be put in INTSRAM along with tct.obj
         * (INTERNRW_TP, INTERNZI_TP)
         *nucleus_v2_critical_data.a (+RW, +ZI)
         *nucleus_v2_ctrl_code.a (+RW, +ZI)
__TEMPLATE
    # --- --- --- 
    my $template_arm9_above_utility = << "__TEMPLATE";
; utilities-related data , ARM9/ARM11/CR4 Family STANDARD set
         emi.obj (INTERNCONST, INTERNRW, INTERNZI)
         custom_scatstruct.obj (INTERNCONST, INTERNRW, INTERNZI)
__TEMPLATE
    # --- --- --- 
    my $template_arm9_above_small_utility = << "__TEMPLATE";
; utilities-related data , ARM9/ARM11/CR4 Family SMALL set
         emi.obj (INTERNCONST, INTERNRW, INTERNZI)
         custom_scatstruct.obj (INTERNCONST, INTERNRW, INTERNZI)
__TEMPLATE
   # --- --- --- 
    my $template;
    my $nfb_or_emb;
    if (defined &$feature_query_function_ptr('nand_flash_booting') and &$feature_query_function_ptr('nand_flash_booting') ne 'NONE')
    {
    	  $nfb_or_emb = &$feature_query_function_ptr('nand_flash_booting');
    }
    elsif (defined &$feature_query_function_ptr('emmc_booting') and &$feature_query_function_ptr('emmc_booting') ne 'NONE')
    {
    	  $nfb_or_emb = &$feature_query_function_ptr('emmc_booting');
    }
    else
    {
    	  $nfb_or_emb = 'NONE';
    }
    # --- --- --- 
    my %BBtbl_cfg = # Place the MCU list for small configure
       (        'MT6253'  => 1,
       );      
    # --- --- --- 
    my %BBtbl_extra_smallcfg = # Place the MCU list for small configure
       (        'MT6253E' => 1,
                'MT6253L' => 1,
                'MT6252H' => 1,
                'MT6252'  => 1,
                'MT6250'  => 1,                
       );      
    # --- --- --- 
    my %BBtbl_arm9_above_small_cfg = # Place the MCU list for small configure of ARM9 Family
       (        'MT6268'  => 1,
                'MT6276'  => 1,
                'MT6573'  => 1,
                'MT6575'  => 1,
                'TK6280'  => 1,
                'MT6280'  => 1,
       );      
    if (defined $BBtbl_extra_smallcfg{$bb} and $BBtbl_extra_smallcfg{$bb})
    {
       #if (defined $nfb_or_emb and $nfb_or_emb ne 'NONE')
       if(&isNAND($feature_query_function_ptr))
       {
           $template = $template_sys . $template . $template_nucleus_nfb_small;
       }
       elsif ($bb eq 'MT6252' or $bb eq 'MT6252H')
       {
           $template = $template_6252_sys . $template . $template_small_nucleus;
       }
       elsif ($bb eq 'MT6250')
       {
           $template = $template_6250_sys . $template;
       }       
       else
       {
           $template = $template_sys . $template . $template_small_nucleus;
       }
    }
    elsif (defined $BBtbl_cfg{$bb} and $BBtbl_cfg{$bb})
    {
       #if (defined $nfb_or_emb and $nfb_or_emb ne 'NONE')
       if(&isNAND($feature_query_function_ptr))
       {
           $template = $template_sys . $template . $template_nucleus_nfb_small;
       }
       else
       {
           $template = $template_sys . $template . $template_nucleus;
       }
    }
    else
    {
        if ((&sysUtil::is_arm9($bb) == 1) || (&sysUtil::is_arm11($bb) == 1)|| (&sysUtil::is_CR4($bb) == 1))
        {
            if (defined $BBtbl_arm9_above_small_cfg{$bb} and $BBtbl_arm9_above_small_cfg{$bb})
            {
                $template = $template_arm9_above_sys . $template . $template_nucleus_arm9_above . $template_arm9_above_small_utility;
            }
            else
            {
                $template = $template_arm9_above_sys . $template . $template_nucleus_arm9_above . $template_arm9_above_utility;
            }
        }
        else
        {
            #if (defined $nfb_or_emb and $nfb_or_emb ne 'NONE')
            if(&isNAND($feature_query_function_ptr))
            {
                $template = $template_sys . $template . $template_nucleus_nfb;
            }
            else
            {
                $template = $template_sys . $template . $template_nucleus;
            }
        }
    }
    return $template;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: INTSRAM type :: INTSRAM CODE content :: others
# input:       BB
#****************************************************************************
sub INTSRAM_CODE_OBJ_others
{
    my ($bb) = @_;
    my %BBtbl =
       (        'MT6235'  => &INTSRAM_CODE_OBJ_others_6235(),
                'MT6235B' => &INTSRAM_CODE_OBJ_others_6235(),
                'MT6236'  => &INTSRAM_CODE_OBJ_others_6235(),
                'MT6236B' => &INTSRAM_CODE_OBJ_others_6235(),
                'MT6921'  => &INTSRAM_CODE_OBJ_others_6235(),
                'MT6253'  => &INTSRAM_CODE_OBJ_others_6253(),
                'MT6268'  => &INTSRAM_CODE_OBJ_others_6268(),
                'MT6516'  => &INTSRAM_CODE_OBJ_others_6516(),
                'MT6276'  => &INTSRAM_CODE_OBJ_others_6276(),
                'MT6573'  => &INTSRAM_CODE_OBJ_others_6573(),
                'MT6575'  => &INTSRAM_CODE_OBJ_others_6573(),
                'MT6256'  => &INTSRAM_CODE_OBJ_others_6235(),
                'MT6255'  => &INTSRAM_CODE_OBJ_others_6235(),
                'MT6922'  => &INTSRAM_CODE_OBJ_others_6235(),
                'TK6280'  => &INTSRAM_CODE_OBJ_others_6573(),
                'MT6280'  => &INTSRAM_CODE_OBJ_others_6573(),
       );
       #map {print $_, "\n";} keys %BBtbl;
#    &sysUtil::sysgen_die("tools/scatGenLib.pl: unsupported $bb!", __FILE__, __LINE__) if not exists $BBtbl{$bb}; 
    # --- --- --- 
    my %BBtbl_cfg = # Place the MCU list for small configure
       (       'MT6253'  => 1,
       );      
    my $template = $BBtbl{$bb};
    my $nfb_or_emb;
    if (defined &$feature_query_function_ptr('nand_flash_booting') and &$feature_query_function_ptr('nand_flash_booting') ne 'NONE')
    {
    	  $nfb_or_emb = &$feature_query_function_ptr('nand_flash_booting');
    }
    elsif (defined &$feature_query_function_ptr('emmc_booting') and &$feature_query_function_ptr('emmc_booting') ne 'NONE')
    {
    	  $nfb_or_emb = &$feature_query_function_ptr('emmc_booting');
    }
    else
    {
    	  $nfb_or_emb = 'NONE';
    }
    
    #if (defined $nfb_or_emb and $nfb_or_emb ne 'NONE')
    if(&isNAND($feature_query_function_ptr))
    {
        if (defined $BBtbl_cfg{$bb} and $BBtbl_cfg{$bb})
        {
            $template =~ s/cam_module\.obj/;cam_module\.obj/;
        }
    }
    return $template;
}
#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: INTSRAM type :: INTSRAM CODE content :: others :: 6235
# input:       BB
#****************************************************************************
sub INTSRAM_CODE_OBJ_others_6235
{
    my $template = << "__TEMPLATE";
; INTSRAM_CODE_OBJ_others_6235
         m12168.obj (INTERNCODE)
         m11303.obj (INTERNCODE)
         m11305.obj (INTERNCODE)
         m12194.obj (INTERNCODE)
         L1Trc.obj (INTERNCODE)
         l1d_data.obj (INTERNCODE)
         divider.obj (INTERNCODE)
         gpt.obj (INTERNCODE)
         lpwr.obj (INTERNCODE)
         l1sm.obj (INTERNCODE)
         * (SNORCODE_INT)
         * (SNORCONST_INT)
         cp15.obj (INTERNCODE)
         m11301.obj (INTERNCODE)

; Please Do Not Remove
         l1d_internal_data.obj (INTERNCODE)
         m12100.obj (INTERNCODE)         
         m12110.obj (INTERNCODE)
         m12120.obj (INTERNCODE)
         m12160.obj (INTERNCODE)
         m12167.obj (INTERNCODE)
         m12170.obj (INTERNCODE)
         m12180.obj (INTERNCODE)
__TEMPLATE
    return $template;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: INTSRAM type :: INTSRAM CODE content :: others :: 6253
# input:       BB
#****************************************************************************
sub INTSRAM_CODE_OBJ_others_6253
{
    my $template = << "__TEMPLATE";
; INTSRAM_CODE_OBJ_others_6253
         m11303.obj (INTERNCODE)
         cam_module.obj (INTERNCODE)
         uart.obj (INTERNCODE)
         gdi_image_direct_gif.obj (INTERNCODE)
         gdi_mutex.obj (INTERNCODE)
         gpt.obj (INTERNCODE)
         * (SNORCODE_INT)
         * (SNORCONST_INT)

; Please Do Not Remove
         m12100.obj (INTERNCODE)
         m12110.obj (INTERNCODE)
         m12120.obj (INTERNCODE)
         m12160.obj (INTERNCODE)
         m12170.obj (INTERNCODE)
         m12171.obj (INTERNCODE)
         m12180.obj (INTERNCODE)
__TEMPLATE
    return $template;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: INTSRAM type :: INTSRAM CODE content :: others :: 6268
# input:       BB
#****************************************************************************
sub INTSRAM_CODE_OBJ_others_6268
{
    my $template = << "__TEMPLATE";
; INTSRAM_CODE_OBJ_others_6268
         l1d_data.obj (INTERNCODE)
         divider.obj (INTERNCODE)
         gpt.obj (INTERNCODE)
         lpwr.obj (INTERNCODE)
         l1sm.obj (INTERNCODE)

         visualhisr.obj (INTERNCODE)
         video_comm.obj (INTERNCODE)
         pdn.obj(INTERNCODE)         
         wmeas.obj (INTERNCODE)
         wcellinfo.obj (INTERNCODE)     
         wcore.obj (INTERNCODE)
         wtxbrp.obj (INTERNCODE)
         wrxbrp.obj (INTERNCODE)
         wrfm.obj (INTERNCODE)
         wcs.obj (INTERNCODE)
         ul1sm.obj (INTERNCODE)
         l1csm.obj (INTERNCODE) 
         m12168.obj (INTERNCODE)
         m11303.obj (INTERNCODE)
         m11305.obj (INTERNCODE)
         m12194.obj (INTERNCODE)
         L1Trc.obj (INTERNCODE)

         ccm.obj (INTERNCODE)
         dm.obj(INTERNCODE)
         cs.obj(INTERNCODE)
         cmm.obj(INTERNCODE)
         rach.obj(INTERNCODE)
         timer.obj(INTERNCODE)
         frame_tick.obj(INTERNCODE)
         time.obj(INTERNCODE)             
         ul1d_ps.obj (INTERNCODE)             
         ul1d_rf_control.obj (INTERNCODE)     
         ul1d_pch.obj (INTERNCODE)
         uscounter.obj (INTERNCODE)

; Please Do Not Remove
         l1d_internal_data.obj (INTERNCODE)
         m12100.obj (INTERNCODE)         
         m12110.obj (INTERNCODE)
         m12120.obj (INTERNCODE)
         m12160.obj (INTERNCODE)
         m12170.obj (INTERNCODE)
         m12167.obj (INTERNCODE)
         m12180.obj (INTERNCODE)
__TEMPLATE
    return $template;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: INTSRAM type :: INTSRAM CODE content :: others :: 6276
# input:       BB
#****************************************************************************
sub INTSRAM_CODE_OBJ_others_6276
{
    my $template = << "__TEMPLATE";
; INTSRAM_CODE_OBJ_others_6276
         l1d_data.obj (INTERNCODE)
         divider.obj (INTERNCODE)
         gpt.obj (INTERNCODE)
         lpwr.obj (INTERNCODE)

         visualhisr.obj (INTERNCODE)
         video_comm.obj (INTERNCODE)
         pdn.obj(INTERNCODE)         
         wmeas.obj (INTERNCODE)
         wcellinfo.obj (INTERNCODE)     
         wcore.obj (INTERNCODE)
         wtxbrp.obj (INTERNCODE)
         wrxbrp.obj (INTERNCODE)
         wrfm.obj (INTERNCODE)
         wcs.obj (INTERNCODE)
         ul1sm.obj (INTERNCODE)
         m12168.obj (INTERNCODE)
         m11303.obj (INTERNCODE)
         m11305.obj (INTERNCODE)
         m12194.obj (INTERNCODE)
         L1Trc.obj (INTERNCODE)

         ccm.obj (INTERNCODE)
         dm.obj(INTERNCODE)
         cs.obj(INTERNCODE)
         cmm.obj(INTERNCODE)
         rach.obj(INTERNCODE)
         timer.obj(INTERNCODE)
         frame_tick.obj(INTERNCODE)
         time.obj(INTERNCODE)             
         ul1d_ps.obj (INTERNCODE)             
         ul1d_rf_control.obj (INTERNCODE)     
         ul1d_pch.obj (INTERNCODE)
         uscounter.obj (INTERNCODE)

; Please Do Not Remove
         l1d_internal_data.obj (INTERNCODE)
         m12100.obj (INTERNCODE)         
         m12110.obj (INTERNCODE)
         m12120.obj (INTERNCODE)
         m12160.obj (INTERNCODE)
         m12170.obj (INTERNCODE)
         m12167.obj (INTERNCODE)
         m12180.obj (INTERNCODE)

; Put stack_ltlcom.obj in INTSRAM on MT6276 to improve idle MIPS
         stack_ltlcom.obj (INTERNCODE)
__TEMPLATE
    return $template;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: INTSRAM type :: INTSRAM CODE content :: others :: 6573
# input:       BB
#****************************************************************************
sub INTSRAM_CODE_OBJ_others_6573
{
    my $template = << "__TEMPLATE";
; INTSRAM_CODE_OBJ_others_6573
         l1d_data.obj (INTERNCODE)
         divider.obj (INTERNCODE)
         gpt.obj (INTERNCODE)
         lpwr.obj (INTERNCODE)
         l1sm.obj (INTERNCODE)

         visualhisr.obj (INTERNCODE)
         video_comm.obj (INTERNCODE)
         pdn.obj(INTERNCODE)         
         wmeas.obj (INTERNCODE)
         wcellinfo.obj (INTERNCODE)     
         wcore.obj (INTERNCODE)
         wtxbrp.obj (INTERNCODE)
         wrxbrp.obj (INTERNCODE)
         wrfm.obj (INTERNCODE)
         wcs.obj (INTERNCODE)
         ul1sm.obj (INTERNCODE)
         l1csm.obj (INTERNCODE) 
         m12168.obj (INTERNCODE)
         m11303.obj (INTERNCODE)
         m11305.obj (INTERNCODE)
         m12194.obj (INTERNCODE)
         L1Trc.obj (INTERNCODE)

         ccm.obj (INTERNCODE)
         dm.obj(INTERNCODE)
         cs.obj(INTERNCODE)
         cmm.obj(INTERNCODE)
         rach.obj(INTERNCODE)
         timer.obj(INTERNCODE)
         frame_tick.obj(INTERNCODE)
         time.obj(INTERNCODE)             
         ul1d_ps.obj (INTERNCODE)             
         ul1d_rf_control.obj (INTERNCODE)     
         ul1d_pch.obj (INTERNCODE)
         uscounter.obj (INTERNCODE)

; Please Do Not Remove
         l1d_internal_data.obj (INTERNCODE)
         m12100.obj (INTERNCODE)         
         m12110.obj (INTERNCODE)
         m12120.obj (INTERNCODE)
         m12160.obj (INTERNCODE)
         m12170.obj (INTERNCODE)
         m12167.obj (INTERNCODE)
         m12180.obj (INTERNCODE)
__TEMPLATE
    return $template;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: INTSRAM type :: INTSRAM CODE content :: others :: 6516
# input:       BB
#****************************************************************************
sub INTSRAM_CODE_OBJ_others_6516
{
    my $template = << "__TEMPLATE";
; INTSRAM_CODE_OBJ_others_6516
         l1d_data.obj (INTERNCODE)
         m12168.obj (INTERNCODE)
         m11303.obj (INTERNCODE)
         m11305.obj (INTERNCODE)
         m12194.obj (INTERNCODE)
         cam_module.obj (INTERNCODE)
         divider.obj (INTERNCODE)
         L1Trc.obj (INTERNCODE)
         uart.obj (INTERNCODE)
         gdi_image_direct_gif.obj (INTERNCODE)
         gdi_mutex.obj (INTERNCODE)
         file62.o (INTERNCODE)
         file12.o (INTERNCODE)
         file71.o (INTERNCODE) 

; Please Do Not Remove
         l1d_internal_data.obj (INTERNCODE)
         m12100.obj (INTERNCODE)         
         m12110.obj (INTERNCODE)
         m12120.obj (INTERNCODE)
         m12160.obj (INTERNCODE)
         m12167.obj (INTERNCODE)
         m12170.obj (INTERNCODE)
         m12180.obj (INTERNCODE)
__TEMPLATE
    return $template;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: INTSRAM type :: INTSRAM DATA content :: others
# input:       BB
#****************************************************************************
sub INTSRAM_DATA_OBJ_others
{
    my ($bb) = @_;
    my %BBtbl =
       (        'MT6235'  => &INTSRAM_DATA_OBJ_others_6235(),
                'MT6235B' => &INTSRAM_DATA_OBJ_others_6235(),
                'MT6236'  => &INTSRAM_DATA_OBJ_others_6235(),
                'MT6236B' => &INTSRAM_DATA_OBJ_others_6235(),
                'MT6921'  => &INTSRAM_DATA_OBJ_others_6235(),
                'MT6253'  => &INTSRAM_DATA_OBJ_others_6253(),
                'MT6268'  => &INTSRAM_DATA_OBJ_others_6268(),
                'MT6516'  => &INTSRAM_DATA_OBJ_others_6516(),
                'MT6256'  => &INTSRAM_DATA_OBJ_others_6256(),
                'MT6255'  => &INTSRAM_DATA_OBJ_others_6256(),
                'MT6922'  => &INTSRAM_DATA_OBJ_others_6256(),
       );
    return $BBtbl{$bb};
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: INTSRAM type :: INTSRAM DATA content :: others :: 6235
# input:       BB
#****************************************************************************
sub INTSRAM_DATA_OBJ_others_6235
{
    my $template = << "__TEMPLATE";
; INTSRAM_DATA_OBJ_others_6235
         l1d_data.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12168.obj (INTERNCONST, INTERNRW, INTERNZI)
         m11303.obj (INTERNCONST, INTERNRW, INTERNZI)
         m11305.obj (INTERNCONST, INTERNRW, INTERNZI)         
         m12194.obj (INTERNCONST, INTERNRW, INTERNZI)                  
         L1Trc.obj (INTERNCONST, INTERNRW, INTERNZI)
         gdi_image.obj (INTERNCONST, INTERNRW, INTERNZI)
         gif_parse.obj (INTERNCONST, INTERNRW, INTERNZI)
         gdi.obj (INTERNZI)         
         interpret.obj (INTERNZI)
         file71.o (INTERNCONST, INTERNRW, INTERNZI)
         l1sm.obj (INTERNCONST, INTERNRW, INTERNZI)
         drv_gfx_stack_switch_manager.obj (INTERNRW, INTERNZI)

; Please Do Not Remove
         l1d_internal_data.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12100.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12110.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12120.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12160.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12167.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12170.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12180.obj (INTERNCONST, INTERNRW, INTERNZI)                  
__TEMPLATE
    return $template;
}
#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: INTSRAM type :: INTSRAM DATA content :: others :: 6253
# input:       BB
#****************************************************************************
sub INTSRAM_DATA_OBJ_others_6253
{
    my $template = << "__TEMPLATE";
; INTSRAM_DATA_OBJ_others_6253
         gdi_image.obj (INTERNCONST, INTERNRW, INTERNZI)
         gdi.obj (INTERNZI)
         interpret.obj (INTERNZI)
         drv_gfx_stack_switch_manager.obj (INTERNRW2, INTERNZI2)

; Please Do Not Remove
         m12100.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12160.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12170.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12171.obj (INTERNCONST, INTERNRW, INTERNZI)
__TEMPLATE
    return $template;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: INTSRAM type :: INTSRAM DATA content :: others :: 6268
# input:       BB
#****************************************************************************
sub INTSRAM_DATA_OBJ_others_6268
{
    my $template = << "__TEMPLATE";
; INTSRAM_DATA_OBJ_others_6268
         l1sm.obj (INTERNCONST, INTERNRW, INTERNZI)
         l1d_data.obj (INTERNCONST, INTERNRW, INTERNZI)
         gdi_image.obj (INTERNCONST, INTERNRW, INTERNZI)
         gif_parse.obj (INTERNCONST, INTERNRW, INTERNZI)
         file71.o (INTERNCONST, INTERNRW, INTERNZI)
         gdi.obj (INTERNZI)         
         interpret.obj (INTERNZI)

         gpt.obj (INTERNCONST, INTERNRW, INTERNZI)
         lpwr.obj (INTERNCONST, INTERNRW, INTERNZI)
         l1sm.obj (INTERNCONST, INTERNRW, INTERNZI)
         visualhisr.obj (INTERNCONST, INTERNRW, INTERNZI)
         pdn.obj(INTERNCONST, INTERNRW, INTERNZI)                  
         ul1sm.obj (INTERNCONST, INTERNRW, INTERNZI)
         l1csm.obj (INTERNCONST, INTERNRW, INTERNZI) 
         m12168.obj (INTERNCONST, INTERNRW, INTERNZI)
         m11303.obj (INTERNCONST, INTERNRW, INTERNZI)
         m11305.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12194.obj (INTERNCONST, INTERNRW, INTERNZI)
         L1Trc.obj (INTERNCONST, INTERNRW, INTERNZI)
         wcellinfo.obj (INTERNRW, INTERNZI)     
         wcore.obj (INTERNRW, INTERNZI)
         wtxbrp.obj (INTERNRW, INTERNZI)
         wrxbrp.obj (INTERNCONST, INTERNRW, INTERNZI)
         param_db.obj (INTERNZI)

         u11126.obj(INTERNCONST, INTERNRW, INTERNZI)         

         cmm.obj(INTERNCONST, INTERNRW, INTERNZI)
         dm.obj(INTERNCONST, INTERNRW, INTERNZI)
         frame_tick.obj(INTERNCONST, INTERNRW, INTERNZI)                 
         timer.obj(INTERNCONST, INTERNRW, INTERNZI)
         cs.obj(INTERNCONST, INTERNRW, INTERNZI) 
         rach.obj(INTERNCONST, INTERNRW, INTERNZI)  
         wmeas.obj (INTERNCONST)
         wcellinfo.obj (INTERNCONST)     
         wcore.obj (INTERNCONST)
         wtxbrp.obj (INTERNCONST)
         wrfm.obj (INTERNCONST)
         wcs.obj (INTERNCONST)
         timer.obj(INTERNCONST)
         time.obj(INTERNCONST)  
         ul1d_ps.obj (INTERNCONST, INTERNRW, INTERNZI)
         ul1d_afc.obj  (INTERNCONST, INTERNRW, INTERNZI)
         uscounter.obj (INTERNRW, INTERNZI)

; Please Do Not Remove
         l1d_internal_data.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12100.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12110.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12120.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12160.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12170.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12167.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12180.obj (INTERNCONST, INTERNRW, INTERNZI)
__TEMPLATE
    return $template;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: INTSRAM type :: INTSRAM DATA content :: others :: 6516
# input:       BB
#****************************************************************************
sub INTSRAM_DATA_OBJ_others_6516
{
    my $template = << "__TEMPLATE";
; INTSRAM_DATA_OBJ_others_6516
         inc.obj (+RW,+ZI)
         l1d_data.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12168.obj (INTERNCONST, INTERNRW, INTERNZI)
         m11303.obj (INTERNCONST, INTERNRW, INTERNZI)
         m11305.obj (INTERNCONST, INTERNRW, INTERNZI)         
         m12194.obj (INTERNCONST, INTERNRW, INTERNZI)                  
         L1Trc.obj (INTERNCONST, INTERNRW, INTERNZI)
         gdi_image.obj (INTERNCONST, INTERNRW, INTERNZI)
         gdi.obj (INTERNZI)         
         interpret.obj (INTERNZI)
         file71.o (INTERNCONST, INTERNRW, INTERNZI)

; Please Do Not Remove
         l1d_internal_data.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12100.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12110.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12120.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12160.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12167.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12170.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12180.obj (INTERNCONST, INTERNRW, INTERNZI)                  
__TEMPLATE
    return $template;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: INTSRAM type :: INTSRAM DATA content :: others :: 6256
# input:       BB
#****************************************************************************
sub INTSRAM_DATA_OBJ_others_6256
{
    my $template = << "__TEMPLATE";
; INTSRAM_DATA_OBJ_others_6256
         l1d_data.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12168.obj (INTERNCONST, INTERNRW, INTERNZI)
         m11303.obj (INTERNCONST, INTERNRW, INTERNZI)
         m11305.obj (INTERNCONST, INTERNRW, INTERNZI)         
         m12194.obj (INTERNCONST, INTERNRW, INTERNZI)                  
         gdi_image.obj (INTERNCONST, INTERNRW, INTERNZI)
         gif_parse.obj (INTERNCONST, INTERNRW, INTERNZI)
         gdi.obj (INTERNZI)         
         interpret.obj (INTERNZI)
         file71.o (INTERNCONST, INTERNRW, INTERNZI)
         l1sm.obj (INTERNCONST, INTERNRW, INTERNZI)
         drv_gfx_stack_switch_manager.obj (INTERNRW, INTERNZI)

; Please Do Not Remove
         l1d_internal_data.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12100.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12110.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12120.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12160.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12167.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12170.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12180.obj (INTERNCONST, INTERNRW, INTERNZI)                  
__TEMPLATE
    return $template;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: INTSRAM type :: INTSRAM MED content(mm sysram)
# input:       BB  ,  OVERLAY indication
#****************************************************************************
sub INTSRAM_MED_EV
{
    my ($bb, $base_addr, $overlay, $size) = @_;
    if ((defined $overlay) && ($overlay == 1))
    {
        $overlay = "OVERLAY";
    }
    else
    {
        undef $overlay;
    }
    # --- --- --- 
    my $med_template_C = << "__MULTIMEDIA_C";
    INTSRAM_MULTIMEDIA $base_addr $overlay $size
    {
         med_main.obj (INTERNRW1, INTERNZI1)
         uart_def.obj (INTERNRW1, INTERNZI1)
    }
__MULTIMEDIA_C
    # --- --- --- 
    my $med_template_D = << "__MULTIMEDIA_D";
    INTSRAM_MULTIMEDIA $base_addr $overlay $size
    {
         mm_intmem_mt6253.obj  (INTERNRW3, INTERNZI3)
    }
__MULTIMEDIA_D
    # --- --- --- 
    my $med_template_E = << "__MULTIMEDIA_E";
    INTSRAM_MULTIMEDIA $base_addr $overlay $size
    {
         mm_intmem_mt6268.obj (INTERNRW1, INTERNZI1)
         wrxbrp.obj (INTERNRW1, INTERNZI1) 
    }
__MULTIMEDIA_E
    # --- --- --- 
    my $med_template_F = << "__MULTIMEDIA_F";
    INTSRAM_MULTIMEDIA $base_addr $overlay $size
    {
         * (INTSRAM_MULTIMEDIA_RW, INTSRAM_MULTIMEDIA_ZI)
         med_main.obj (INTERNRW1, INTERNZI1)
         uart_def.obj (INTERNRW1, INTERNZI1)
    }
__MULTIMEDIA_F
    # --- --- --- 
    my $med_template_G = << "__MULTIMEDIA_G";
    INTSRAM_MULTIMEDIA $base_addr $overlay $size
    {
         * (INTSRAM_MULTIMEDIA_RW, INTSRAM_MULTIMEDIA_ZI)
         med_main.obj (INTERNRW1, INTERNZI1)
         btmt_mem.obj (INTERNRW1, INTERNZI1)
         ss_btmt_dma.obj (INTERNRW1, INTERNZI1)
    }
__MULTIMEDIA_G
    # --- --- --- 
    my $med_template_H = << "__MULTIMEDIA_H";
    INTSRAM_MULTIMEDIA $base_addr $overlay $size
    {
;         med_main.obj (INTERNRW1, INTERNZI1)
    }
__MULTIMEDIA_H
    # --- --- --- 
    my %BBtbl =
       (        'MT6235'  => $med_template_C,
                'MT6235B' => $med_template_C,
                'MT6236'  => $med_template_F,
                'MT6236B' => $med_template_F,
                'MT6921'  => $med_template_F,
                'MT6253'  => $med_template_D,
                'MT6268'  => $med_template_E,
                'MT6276'  => $med_template_G,
                'MT6573'  => $med_template_H,
                'MT6575'  => $med_template_H,
                'MT6256'  => $med_template_F,
                'MT6255'  => $med_template_F,
                'MT6922'  => $med_template_F,
       );
       #map {print $_, "\n";} keys %BBtbl;
#    &sysUtil::sysgen_die("tools/scatGenLib.pl: unsupported $bb!", __FILE__, __LINE__) if not exists $BBtbl{$bb}; 
    # --- --- --- 
    return $BBtbl{$bb};
}

#****************************************************************************
# subroutine:  NFB Layout :: ROM :: Exec View :: INTSRAM type :: SYS-RAM BOOTLOADER USED INDICATION
# input:       BB
#****************************************************************************
sub INTSRAM_BLINUSED_EV
{
    my ($bb, $base_addr, $size) = @_;
    # --- --- --- 
    my $ev_string = << "__TEMPLATE";
    INTSRAM_BLINUSED $base_addr OVERLAY $size
    {
    ; Execution Region Reserved for Bootloader
    }
__TEMPLATE
    return $ev_string;
}
#****************************************************************************
# subroutine:  NFB Layout :: ROM :: Exec View :: EXTSRAM type :: TMP_PAGE_TABLE
# input:       BB
#****************************************************************************
sub Query_EXTSRAM_PAGETABLE_SupportBB
{
    my ($bb) = @_;
    my %supportBB = 
    (       'MT6255' => 0x4000,
            'MT6922' => 0x4000,
            'MT6575' => 0x4000,
    );
    return $supportBB{$bb};
}
sub EXTSRAM_PAGETABLE_EV
{
    my ($bb, $nDummyEndBaseAddress) = @_;
    my $nTMP_PAGE_TABLE_size = &Query_EXTSRAM_PAGETABLE_SupportBB($bb);
    if(!defined $nTMP_PAGE_TABLE_size )
    {
        return;
    }
    # --- --- --- 
    my $bisMMU = &sysUtil::is_mmu($bb);
    my $strSize = &CommonUtil::Dec2Hex( $nTMP_PAGE_TABLE_size );
    my $base_addr = &CommonUtil::Dec2Hex($nDummyEndBaseAddress);
    my $ev_string = << "__TEMPLATE";
    ;temp page table should be 16K aligned
    EXTSRAM_TMP_PAGE_TABLE $base_addr $strSize
    {
         * (TMPPAGETABLE)
    }
__TEMPLATE
    return $ev_string;
}
#****************************************************************************
# subroutine:  NFB Layout :: ROM :: Exec View :: INTSRAM type :: TMP_PAGE_TABLE
# input:       BB
#****************************************************************************
sub INTSRAM_PAGETABLE_EV
{
    my ($bb, $base_addr, $size) = @_;
    # --- --- --- 
    my $ev_string = << "__TEMPLATE";
     ;temp page table should be 16K aligned
    INTSRAM_TMP_PAGE_TABLE $base_addr OVERLAY $size
    {
         * (TMPPAGETABLE)
    }
__TEMPLATE
    return $ev_string;
}

#****************************************************************************
# subroutine:  NFB+FOTA Layout :: ROM :: Exec View :: INTSRAM type :: FOTA_TEMP
# input:       BB
#****************************************************************************
sub INTSRAM_FOTATEMP_EV
{
    my ($bb, $base_addr) = @_;
    
    my $fota = &$feature_query_function_ptr('fota_enable');
    if ($fota ne 'FOTA_DM')
    {
       return;
    }
    
    # --- --- --- 
    my $ev_string = << "__TEMPLATE";
    INTSRAM_FOTA_TEMP $base_addr OVERLAY 0x00001000
    {
         *.obj (DUMMY_SECTION)
    }
__TEMPLATE
    return $ev_string;
}

#****************************************************************************
# Global Table  ,  DCM id table
#****************************************************************************
    my %DCMidtbl =
       (       'DYNAMIC_CODE1' => 'AMR515',
               'DYNAMIC_CODE2' => 'G3D',
               'DYNAMIC_CODE3' => 'CTM',
               'DYNAMIC_CODE4' => 'G729',
               'DYNAMIC_CODE5' => 'SBC',
               'DYNAMIC_CODE6' => 'BCODE',
               'DYNAMIC_CODE7' => 'REVERB',
               'DYNAMIC_CODE8' => 'RESAMPLE',
               'DYNAMIC_CODE9' => 'JPEG_ENC_DYNAMIC_CODE',
               'DYNAMIC_CODE10'=> 'JPEG_DEC_DYNAMIC_CODE',
               'DYNAMIC_CODE11'=> 'VRENGINE',
               'DYNAMIC_CODE12'=> 'MP4DEC2',
               'DYNAMIC_CODE13'=> 'MP4ENC2',
               'DYNAMIC_CODE14'=> '264DEC2',
               'DYNAMIC_CODE15'=> 'MP4DEC1',
               'DYNAMIC_CODE16'=> 'MP4ENC1',
               'DYNAMIC_CODE17'=> '264DEC1',
               'DYNAMIC_CODE18'=> 'MP4DEC',
               'DYNAMIC_CODE19'=> 'MP4ENC',
               'DYNAMIC_CODE20'=> '264DEC3',
               'DYNAMIC_CODE21'=> 'RVDEC2',
               'DYNAMIC_CODE22'=> 'RVDEC1',
               'DYNAMIC_CODE23'=> 'RVDEC3',
       );
#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: INTSRAM type :: INTSRAM DCM content
# input:       BB
#****************************************************************************
sub INTSRAM_DCM_EV
{
    my ($bb) = @_;
    my %DCMcfg_D =
       (       'DYNAMIC_CODE1' => [ 0x5010F000, 0x5000 ],
               'DYNAMIC_CODE2' => [ 0x5010C800, 0x2800 ],
               'DYNAMIC_CODE3' => [ 0x5010F000, 0x5000 ],
               'DYNAMIC_CODE4' => [ 0x5010F000, 0x5000 ],
               'DYNAMIC_CODE5' => [ 0x5010F000, 0x5000 ],
               'DYNAMIC_CODE11'=> [ 0x5010F000, 0x5000 ],
               'DYNAMIC_CODE12'=> [ 0x50108C00, 0x3C00 ],
               'DYNAMIC_CODE13'=> [ 0x50108C00, 0x3C00 ],
               'DYNAMIC_CODE14'=> [ 0x50108C00, 0x3C00 ],
               'DYNAMIC_CODE15'=> [ 0x5010C800, 0x2800 ],
               'DYNAMIC_CODE16'=> [ 0x5010C800, 0x2800 ],
               'DYNAMIC_CODE17'=> [ 0x5010C800, 0x2800 ],
       );
    my %DCMcfg_F =
       (       'DYNAMIC_CODE1' => [ 0x40017000, 0x5000 ],
               'DYNAMIC_CODE3' => [ 0x40017000, 0x5000 ],
               'DYNAMIC_CODE4' => [ 0x40017000, 0x5000 ],
               'DYNAMIC_CODE5' => [ 0x40017000, 0x5000 ],
               'DYNAMIC_CODE11'=> [ 0x40017000, 0x5000 ],
               'DYNAMIC_CODE12'=> [ 0x4000CC70, 0x9600 ],
               'DYNAMIC_CODE13'=> [ 0x40017000, 0x5000 ],
               'DYNAMIC_CODE16'=> [ 0x4000CC70, 0x9600 ],
               'DYNAMIC_CODE17'=> [ 0x40016270, 0xD90 ],
               'DYNAMIC_CODE18'=> [ 0x40016270, 0xD90 ],
               'DYNAMIC_CODE19'=> [ 0x40016270, 0xD90 ], 
               'DYNAMIC_CODE20'=> [ 0x4000CC70, 0x9600 ],
               'DYNAMIC_CODE22'=> [ 0x40016270, 0xD90 ],
               'DYNAMIC_CODE23'=> [ 0x4000CC70, 0x9600 ],
       );
    my %DCMcfg_G =
       (       'DYNAMIC_CODE1' => [ 0x50116000, 0x5000 ],
               'DYNAMIC_CODE2' => [ 0x50113800, 0x2800 ],
               'DYNAMIC_CODE3' => [ 0x50116000, 0x5000 ],
               'DYNAMIC_CODE4' => [ 0x50116000, 0x5000 ],
               'DYNAMIC_CODE5' => [ 0x50116000, 0x5000 ],
               'DYNAMIC_CODE11'=> [ 0x50116000, 0x5000 ],
       );
    my %DCMcfg_H =
       (       'DYNAMIC_CODE1' => [ 0x5010B000, 0x5000 ],
               'DYNAMIC_CODE2' => [ 0x50110000, 0x2800 ],
               'DYNAMIC_CODE3' => [ 0x5010B000, 0x5000 ],
               'DYNAMIC_CODE4' => [ 0x5010B000, 0x5000 ],
               'DYNAMIC_CODE5' => [ 0x5010B000, 0x5000 ],
               'DYNAMIC_CODE11'=> [ 0x5010B000, 0x5000 ],
               'DYNAMIC_CODE15'=> [ 0x50110000, 0x2800 ],
               'DYNAMIC_CODE17'=> [ 0x50110000, 0x2800 ],
               'DYNAMIC_CODE22'=> [ 0x50110000, 0x2800 ],
       );
    my %DCMcfg_I =
       (       'DYNAMIC_CODE1' => [ 0x50015940, 0x4B00 ],
               'DYNAMIC_CODE2' => [ 0x50015940, 0x4B00 ],
               'DYNAMIC_CODE3' => [ 0x50015940, 0x4B00 ],
               'DYNAMIC_CODE4' => [ 0x50015940, 0x4B00 ],
               'DYNAMIC_CODE5' => [ 0x50015940, 0x4B00 ],
               'DYNAMIC_CODE7' => [ 0x50015940, 0x4B00 ],
               'DYNAMIC_CODE8' => [ 0x50015940, 0x4B00 ],
       );
    # --- --- --- 
    my %BBtbl =
       (        'MT6235'  => \%DCMcfg_D,
                'MT6235B' => \%DCMcfg_D,
                'MT6236'  => \%DCMcfg_H,
                'MT6236B' => \%DCMcfg_H,
                'MT6921'  => \%DCMcfg_H,
                'MT6253'  => \%DCMcfg_F,
                'MT6268'  => \%DCMcfg_G,
                'MT6516'  => \%DCMcfg_I,
                'MT6276'  => \%DCMcfg_G,
                'MT6573'  => \%DCMcfg_G,
                'MT6575'  => \%DCMcfg_G,
       );
       #map {print $_, "\n";} keys %BBtbl;
#    &sysUtil::sysgen_die("tools/scatGenLib.pl: unsupported $bb!", __FILE__, __LINE__) if not exists $BBtbl{$bb}; 
    # --- --- --- 
    return "" if(!exists $BBtbl{$bb});
    my $href = $BBtbl{$bb};
    my @list = sort { $href->{$a}->[0] <=> $href->{$b}->[0] or $a cmp $b } keys %$href;
       #map {print $_, "\n";} @list;
    my $result;
    foreach my $region (@list)
    {
        my $section;
        if ((($region eq 'DYNAMIC_CODE16') || ($region eq 'DYNAMIC_CODE14') || ($region eq 'DYNAMIC_CODE17') || ($region eq 'DYNAMIC_CODE20') || $region eq 'DYNAMIC_CODE21' || $region eq 'DYNAMIC_CODE22' || $region eq 'DYNAMIC_CODE23') and ($BBtbl{$bb} == \%DCMcfg_F))
        {
            $section = $DCMidtbl{$region} . "_DYNAMIC_CODE";
            $section.= ", " . $DCMidtbl{$region} . "_DYNAMIC_RO";
            $section.= ", " . $DCMidtbl{$region} . "_DYNAMIC_ZI";
        }
        elsif ($region eq 'DYNAMIC_CODE18' || $region eq 'DYNAMIC_CODE19')
        {
            $section = $DCMidtbl{$region} . "_DYNAMIC_CODE";
            $section.= ", " . $DCMidtbl{$region} . "_DYNAMIC_RO";
        }
        elsif ($region eq 'DYNAMIC_CODE12' || $region eq 'DYNAMIC_CODE13' || $region eq 'DYNAMIC_CODE14' || $region eq 'DYNAMIC_CODE15' || $region eq 'DYNAMIC_CODE16' || $region eq 'DYNAMIC_CODE17' || $region eq 'DYNAMIC_CODE22')
        {
            $section = $DCMidtbl{$region} . "_DYNAMIC_ZI";
            $section.= ", " . $DCMidtbl{$region} . "_DYNAMIC_RO";
        }
        elsif ((&sysUtil::is_arm9($bb) == 1) or (&sysUtil::is_arm11($bb) == 1))
        {
            $section = $DCMidtbl{$region} . "_DYNAMIC_ZI";
        }
        else
        {
            $section = $DCMidtbl{$region} . "_DYNAMIC_CODE";
            $section.= ", " . $DCMidtbl{$region} . "_DYNAMIC_ZI";
        }
        $result .= &format_execution_view( $region, 
                                           sprintf("0x%08x", $href->{$region}->[0]),
                                           sprintf("OVERLAY 0x%04x", $href->{$region}->[1]),
                                           ["* ($section)"]
                                         );
    }

    if (((&sysUtil::is_arm9($bb) == 1) or (&sysUtil::is_arm11($bb) == 1)) && (&$feature_query_function_ptr('nand_flash_booting') eq 'BASIC'))
    {
        $result .= &format_execution_view( "DYMANIC_CODE_DUMMY_END", 
                                           "+0x0 ABSOLUTE",
                                           undef,
                                           ["bootarm_rvct.obj (DUMMY_DYNAMIC_CODE)"]
                                         );
    }
    return $result;
}

#****************************************************************************
# subroutine:  NFB/NOR Layout :: ROM :: Exec View :: MMv2 type :: FLMM
# input:       BB
#****************************************************************************
sub FLMM_EV
{
    my ($bb) = @_;
    return undef if(&sysUtil::is_arm9($bb) != 1 and &sysUtil::is_arm11($bb) != 1);
    # --- --- --- 
    my $ev_string = << "__TEMPLATE";
    FLMM_VASPACE 0xE0000000 ABSOLUTE 0x0FC00000
    {
        ; 124M for FLMM DATA    
        * (FLMM_VASPACE)
    }
    FLMM_STACKSPACE 0xEFC00000 EMPTY 0x00400000
    {
        ; 4M empty region for STACK SPACE
    }
__TEMPLATE
    return $ev_string;
}
#****************************************************************************
# subroutine:  NOR Layout :: DYNAMIC_COMP_CODE :: Load View+Execution View
#                   for dcm compression
# input:  $strBaseAddr: base address
# output: DYNAMIC_COMP_CODE layout
#****************************************************************************
sub DCMP_basic_template
{
    my ($strBaseAddr, $bb) = @_;
    $strBaseAddr = '+0x0' if(!defined $strBaseAddr);
    &sysUtil::sysgen_die("$bb_folder/custom_FeatureConfig.h: CONFIG_DCMP_MAX_COMPRESSED_SIZE need to be defined when DCM_COMPRESION_SUPPORT is turned on!", __FILE__, __LINE__)
       if (!defined($feature_config_href->{'CONFIG_DCMP_MAX_COMPRESSED_SIZE'}));
    my $strMaxSize = $feature_config_href->{'CONFIG_DCMP_MAX_COMPRESSED_SIZE'};

    my $template = <<"__TEMPLATE";
; DYNAMIC_COMP_CODE MaxSize is queried from custom_FeatureConfig.h
DYNAMIC_COMP_CODE $strBaseAddr $strMaxSize
{
    DYNAMIC_COMP_CODE +0x0
    {
         * (DYNAMIC_DUMMY_CODE_HEAD)
    }
}
__TEMPLATE
	chomp($template);
	return $template;
}
#****************************************************************************
# subroutine:  Get DCM Compression's combination
# input: x
# output: Combination total Size and Layout
#****************************************************************************
sub DCMP_GetCombination
{
    my ($bb) = @_;
    my @combination;
    # ('SBC', 'BESLOUDNESS', 'MP4DEC', 'H264DEC', 'MP4ENC', 'MP4ASPDEC', 'VP8DEC', 'VEENC', 'VEDEC', 'DAF', 'WAVETABLE');
    if(defined &$feature_query_function_ptr('bt_a2dp_profile') and &$feature_query_function_ptr('bt_a2dp_profile') eq 'TRUE')
    {
        push(@combination, 'SBC');
    }
    if(defined &$feature_query_function_ptr('bes_loudness_support') and &$feature_query_function_ptr('bes_loudness_support') eq 'TRUE')
    {
        push(@combination, 'BESLOUDNESS');
    }
    if(defined &$feature_query_function_ptr('mp4_decode_profile') and &$feature_query_function_ptr('mp4_decode_profile') eq 'SP')
    {
        push(@combination, 'MP4DEC');
    }
    if(defined &$feature_query_function_ptr('h264_decode') and &$feature_query_function_ptr('h264_decode') eq 'TRUE')
    {
        push(@combination, 'H264DEC');
    }
    if(defined &$feature_query_function_ptr('mp4_encode') and &$feature_query_function_ptr('mp4_encode') eq 'TRUE')
    {
        push(@combination, 'MP4ENC');
    }
    if(defined &$feature_query_function_ptr('mp4_decode_profile') and &$feature_query_function_ptr('mp4_decode_profile') eq 'ASP')
    {
        push(@combination, 'MP4ASPDEC');
    }
    if(defined &$feature_query_function_ptr('vp8_decode') and &$feature_query_function_ptr('vp8_decode') eq 'TRUE')
    {
        push(@combination, 'VP8DEC');
    }
    if(defined &$feature_query_function_ptr('VIDEO_PLAYER_RECORDER_W_DCM') and &$feature_query_function_ptr('VIDEO_PLAYER_RECORDER_W_DCM') eq 'ENABLE')
    {
        push(@combination, 'VEENC');
        push(@combination, 'VEDEC');
    }
    if((defined &$feature_query_function_ptr('daf_decode') and &$feature_query_function_ptr('daf_decode') eq 'TRUE')
    and ($bb eq 'MT6250'))
    {
        push(@combination, 'DAF');
    }
    if((defined &$feature_query_function_ptr('melody_ver') and &$feature_query_function_ptr('melody_ver') eq 'DSP_WT_SYN')
    and ($bb eq 'MT6250'))
    {
        push(@combination, 'WAVETABLE');
    }
    $nSize = @combination;
    if($nSize==0)
    {
		    &sysUtil::sysgen_die("tools/scatGenLib.pl: DCM Compression combination=0, please check feature option or turn off DCM Compression.", __FILE__, __LINE__);
    }
    return \@combination;
}

#****************************************************************************
# subroutine:  NOR Layout :: all DYNAMIC_COMP_$strPostfix :: Load View+Execution View
#              for dcm compression
# input: $bb: chip name for checking if it has mmu
#        $nRamBottomAddress(should be PA) : physical RamSize - TxRx Region - ...
#        global variable: $Is_Flashtool_Layout : 0 or 1 : 
#        if it's flashtool's layout, no need to generate DCMP_code_layout.
#        !!!!!!!!!!!Total combination is set here.!!!!!!!!!!!!!!!!
# output: Combination total Size and Layout
#****************************************************************************
sub DCMP_code_layout
{
    my ($bb, $nRamBottomAddress) = @_;
    if($Is_Flashtool_Layout == 1) #If not flash tool, still need the following layout.
    {
    	return (0, undef);		
    }
    #Check $RamBottomAddress is 32B aligned (0x20)
    if($nRamBottomAddress % 0x20 != 0)
    {
        &sysUtil::sysgen_die("tools/scatGenLib.pl: DCM Compression should be 32B aligned!", __FILE__, __LINE__);
    }
    $strRamAddress = &CommonUtil::Dec2Hex($nRamBottomAddress);
    my $nMMUPrefix = &sysUtil::is_mmu($bb) ? 0xf0000000 : 0;
    $nRamBottomAddress |= $nMMUPrefix;
    # --- --- --- --- combination --- --- --- --- 
    #my @TotalCombination = ('SBC', 'RESAMPLE', 'BESLOUDNESS', 'MP4DEC', 'H264DEC');
    #my @NonExistCombination = map {$_} @TotalCombination;
    my $ExistCombination = &DCMP_GetCombination($bb);
    #foreach my $element (@TotalCombination)
    #{
    #	map { splice(@NonExistCombination, $element, 1) if( $element eq $_ ) } @$ExistCombination;
    #}
	##map {print "NonExistCombination:".$_."\n" } @NonExistCombination;
    # --- --- ---
    my %DCM_COMP_CODE_table;
    my $nTotalDecompressedSize =&DCMP_GetQueryInfo($nRamBottomAddress, $ExistCombination,\%DCM_COMP_CODE_table);
    ##map {print "DCMP_code_layout:$_", "\n";} keys %DCM_COMP_CODE_table;
    my $layout;
    foreach my $strPostfix (@$ExistCombination)
    {
    	$layout .= &DCMP_code_template($strPostfix, $DCM_COMP_CODE_table{$strPostfix}->[0], 
                                    $DCM_COMP_CODE_table{$strPostfix}->[1], &DCMP_InputSection_template($strPostfix));
    }
    
    #$nRamBottomAddress -= $nTotalDecompressedSize;
    #my $nHeaderSize = 0x40;
    #foreach my $strPostfix (@NonExistCombination)
   	#{
   	#	if( 0 == &DCMP_ExistTheSamePool($strPostfix, $ExistCombination) )
   	#	{
    #		$nRamBottomAddress -= $nHeaderSize;
    #		$nTotalDecompressedSize += $nHeaderSize;
   	#	}
   	#	$layout .= &DCMP_code_template($strPostfix, $nRamBottomAddress, $nHeaderSize, 
   	#									&DCMP_InputSection_template($strPostfix));
   	#}
    return ($nTotalDecompressedSize, $layout);
}
#****************************************************************************
# subroutine:  DCMP_ExistTheSamePool: if the input's Pool has existed in ExistCombination's Pool
# input:   $strPostfix: Input Postfix for query
#          $ExistCombination: an array to be queried ExistCombination's Pool
# output: $nExist: if the same pool has existed, yes=1, no=0  
#****************************************************************************
sub DCMP_ExistTheSamePool
{
	my ($strPostfix, $ExistCombination) = @_;
	my ($strQueryPoolNum, $dontcare) = &DCMP_query_SharePoolInfo($strPostfix);
	my $nExist = 0; # 0= not exist, 1=exist
	my @ExistPoolInfo = map { ($strSharePoolNum) = &DCMP_query_SharePoolInfo($_) } @$ExistCombination;
	#map {print "$_,"} @ExistPoolInfo; 
	if( grep {$_ eq $strQueryPoolNum} @ExistPoolInfo )
	{
		$nExist = 1;
	}
	return $nExist;
}

#****************************************************************************
# subroutine:  NOR Layout :: single DYNAMIC_COMP_$strPostfix :: Load View+Execution View
#              for dcm compression
# input:   $strPostfix: Postfix
#          $nBaseAddr: base address in execution region
#          $nMaxSize:  SharePool MaxSize
#          $InputSection: region inputsection
# output: Single DYNAMIC_COMP_$strPostfix :: Load View+Execution View
#****************************************************************************
sub DCMP_code_template
{
    my ($strPostfix, $nBaseAddr, $nMaxSize, $InputSection) = @_;
    my $strHeadSize = '0x40';
    my $strBody_MaxSize = &CommonUtil::Dec2Hex($nMaxSize-hex($strHeadSize));
    my $strMaxSize = &CommonUtil::Dec2Hex($nMaxSize);
    my $strBaseAddr = &CommonUtil::Dec2Hex($nBaseAddr);
    my $template = <<"__TEMPLATE";
DYNAMIC_COMP_$strPostfix +0x0 $strMaxSize
{
; 32byte aligned to support dynamically switchable cachability 
    DYNAMIC_COMP_$strPostfix $strBaseAddr OVERLAY $strHeadSize
    {
         * (DYNAMIC_COMP_$strPostfix\_HEAD)
    }
    DYNAMIC_COMP_$strPostfix\_BODY +0x0 OVERLAY $strBody_MaxSize
    {
$InputSection
    }
}

__TEMPLATE
    chomp($template);
    return $template;
}
#****************************************************************************
# subroutine:  NOR Layout :: single DYNAMIC_COMP_$strPostfix :: InputSection
#              for dcm compression
# input: $strPostfix: Postfix in DYNAMIC_COMP_$strPostfix
# output: InputSection's content
#****************************************************************************
sub DCMP_InputSection_template
{
    my ($strPostfix) = @_;
    my $templateSBC=<<"__TEMPLATE";
       sbc_anal.obj (+RO-CODE, +RO-DATA)
       sbc_common.obj (+RO-CODE, +RO-DATA)
       sbc_enc.obj (+RO-CODE, +RO-DATA)
__TEMPLATE
    my $templateBESLOUDNESS=<<"__TEMPLATE";
       *BesLoudness.a (+RO-CODE, +RO-DATA)
__TEMPLATE
    my $templateMP4DEC=<<"__TEMPLATE";
       *mp4dec*.arm7*.a (+RO-CODE, +RO-DATA)
       *mp4com*.arm7*.a (+RO-CODE, +RO-DATA)
__TEMPLATE
    my $templateH264DEC=<<"__TEMPLATE";
       *h264dec.arm7*.a (+RO-CODE, +RO-DATA)
__TEMPLATE
    my $templateMP4ENC=<<"__TEMPLATE";
       * (MP4ENC1_DYNAMIC_CODE, MP4ENC1_DYNAMIC_RO)
       * (MP4ENC_DYNAMIC_CODE, MP4ENC_DYNAMIC_RO)
       * (MP4ENC2_DYNAMIC_RO)
       *mp4enc*.arm7*.a (+RO-CODE, +RO-DATA)
__TEMPLATE
    my $templateMP4ASPDEC=<<"__TEMPLATE";
       *mp4dec_asp.arm7*.a (+RO-CODE, +RO-DATA)
       *mp4com_asp.arm7*.a (+RO-CODE, +RO-DATA)
__TEMPLATE
    my $templateVP8DEC=<<"__TEMPLATE";
       *vp8dec.arm7*.a (+RO-CODE, +RO-DATA)
__TEMPLATE
    my $templateVEENC=<<"__TEMPLATE";
       * (DYNAMIC_CODE_VEENC_ROCODE, DYNAMIC_CODE_VEENC_RODATA)
__TEMPLATE
    my $templateVEDEC=<<"__TEMPLATE";
       * (DYNAMIC_CODE_VEDEC_ROCODE, DYNAMIC_CODE_VEDEC_RODATA)
__TEMPLATE
    my $templateDAF=<<"__TEMPLATE";
       *mp3_dec.a (+RO-CODE, +RO-DATA)
__TEMPLATE
    my $templateWAVETABLE=<<"__TEMPLATE";
       *melody_par.a (+RO-CODE, +RO-DATA)
       *melody_syn.a (+RO-CODE, +RO-DATA)
__TEMPLATE

    my %DCM_COMP_CODE_INPUTSECTION_table =
    (   'SBC'           => $templateSBC,
        'BESLOUDNESS'   => $templateBESLOUDNESS,
        'MP4DEC'        => $templateMP4DEC,
        'H264DEC'       => $templateH264DEC,
        'MP4ENC'        => $templateMP4ENC,
        'MP4ASPDEC'     => $templateMP4ASPDEC,
        'VP8DEC'        => $templateVP8DEC,
        'VEENC'         => $templateVEENC,
        'VEDEC'         => $templateVEDEC,
        'DAF'           => $templateDAF,
        'WAVETABLE'     => $templateWAVETABLE,                        

    );
    my $template = $DCM_COMP_CODE_INPUTSECTION_table{$strPostfix};
    chomp($template);
    return $template;
}
#****************************************************************************
# subroutine:  Query DCM Compression SharePool Information on ram
#                   for dcm compression
# input: $strPostfix: Postfix in DYNAMIC_COMP_$strPostfix
# output: SharePoolnum, SharePool's max size
#****************************************************************************
sub DCMP_query_SharePoolInfo
{
    my ($strPostfix) = @_;
    #key=$strPostfix, Value={SharePoolNum, MaxSize}
    #Note: MaxSize Should be 0x20(32bytes) aligned!!
    my $is_MP4DEC    = (defined &$feature_query_function_ptr('mp4_decode_profile') and &$feature_query_function_ptr('mp4_decode_profile') eq 'SP') ? 1 : 0;
    my $is_H264DEC   = (defined &$feature_query_function_ptr('h264_decode') and &$feature_query_function_ptr('h264_decode') eq 'TRUE') ? 1 : 0;
    my $is_MP4ENC    = (defined &$feature_query_function_ptr('mp4_encode') and &$feature_query_function_ptr('mp4_encode') eq 'TRUE') ? 1 : 0;
    my $is_MP4ASPDEC = (defined &$feature_query_function_ptr('mp4_decode_profile') and &$feature_query_function_ptr('mp4_decode_profile') eq 'ASP') ? 1 : 0;
    my $is_VP8DEC    = (defined &$feature_query_function_ptr('vp8_decode') and &$feature_query_function_ptr('vp8_decode') eq 'TRUE') ? 1 : 0;
    
    my $pool_size =  ($is_MP4DEC && !($is_H264DEC || $is_MP4ENC || $is_MP4ASPDEC || $is_VP8DEC))? 0x10000 : 0x1B800; 
    my %DCM_COMP_CODE_table = 
    (   'SBC'           => [ 'SharePool1', 0x2000],
        'BESLOUDNESS'   => [ 'SharePool2', 0x3400],
        'MP4DEC'        => [ 'SharePool3', $pool_size],
        'H264DEC'       => [ 'SharePool3', $pool_size],
        'MP4ENC'        => [ 'SharePool3', $pool_size],
        'MP4ASPDEC'     => [ 'SharePool3', $pool_size],
        'VP8DEC'        => [ 'SharePool3', $pool_size],
        'VEENC'         => [ 'SharePool4', 0xE000],
        'VEDEC'         => [ 'SharePool4', 0xE000],
        'DAF'           => [ 'SharePool5', 0x9000],
        'WAVETABLE'     => [ 'SharePool5', 0x9000],                        
    );
    my $strSharePoolNum = $DCM_COMP_CODE_table{$strPostfix}->[0];
    my $MaxSize = $DCM_COMP_CODE_table{$strPostfix}->[1];
    
    return ($strSharePoolNum, $MaxSize);
}
#****************************************************************************
# subroutine:  Process DCM Compression related information
#                   for dcm compression
# input: $RamBottomAddress: maybe RamSize - TxRx Region : from sub DCMP_code_layout
#        $combination: DYNAMIC_COMP_$strPostfix 's Postfix combination
#        $Output_table: %DCM_COMP_CODE_table{strPostfix: BaseAddress, MaxSize}: Combination's each information
# output: $TotalSize: Combination's SharePool total size
#****************************************************************************
sub DCMP_GetQueryInfo
{
    #$Output_table: %DCM_COMP_CODE_table{strPostfix: BaseAddress, MaxSize}
    my ($RamBottomAddress, $combination, $Output_table) = @_;
    my $TotalSize =0; #output: TotalRequiredSize
    
    my %TotalPool;
    foreach my $strPostfix (@$combination)
    {   
        my ($SharePoolNum, $MaxSize) = &DCMP_query_SharePoolInfo($strPostfix);
        if(!defined $TotalPool{$SharePoolNum})
        {
            $RamBottomAddress -= $MaxSize;
            $TotalPool{$SharePoolNum}= [$MaxSize, $RamBottomAddress];
        }
        $Output_table->{$strPostfix} = [$TotalPool{$SharePoolNum}->[1], $MaxSize];
        #print "(strPostfix, base, size)=($strPostfix, $Output_table->{$strPostfix}->[0], $Output_table->{$strPostfix}->[1])\n";
    }
    foreach my $size (values %TotalPool)
    {
        $TotalSize += $size->[0];
    }
    #print "TotalSize=$TotalSize\n";
    return ($TotalSize);
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: DSP TX RX :: Size Of TX RX query
# input:       BB , Mode (BASIC, L1S, GSM, GPRS, UMTS)
#****************************************************************************

#****************************************************************************
# subroutine:  Get_ObjListGen_List
# purpose:     get ALICE-related list from \mcu\custom\system\[project]\scat_config\FeatureBased\ObjListGen\
# input: list name
#        objectROM1.list              :Must be put in ROM1 if ALICE or ZIMAGE support
#        objectALICE.list             :Must be put in ALICE if ALICE support
#        objectZIMAGE.list            :Must be put in ZIMAGE if ZIMAGE support
#        objectBOOT_ZIMAGE.list       :Must be put in BOOT_ZIMAGE if BOOT_ZIMAGE support
#        objectALICE_FORBID_dummy.list:ALICE forbid (dummy scatter)
#        objectROM1_dummy.list        :Must be put in ROM1 if ALICE or ZIMAGE support (dummy scatter)
#        objectALICE_dummy.list       :Must be put in ALICE if ALICE support (dummy scatter)
#        objectZIMAGE_dummy.list      :Must be put in ZIMAGE if ZIMAGE support (dummy scatter)
#        objectBOOT_ZIMAGE_dummy.list :Must be put in BOOT_ZIMAGE if BOOT_ZIMAGE support (dummy scatter)
# output: the content of all obj list of the spacific list
#****************************************************************************

sub Get_ObjListGen_List
{
    my ($list_name) = @_; 
    my $content;
    my $OBJ_LIST = "$bb_folder/scat_config/FeatureBased/ObjListGen/$list_name";
    if($list_name =~ /\.list/)
    {
        $content = &GetList($OBJ_LIST);
    }
    else
    {
        &sysUtil::sysgen_die("$OBJ_LIST: list not exist!", __FILE__, __LINE__);
    }
    return $content;
}

sub GetList
{
    my ($strListPath) = @_; 
    my $strListName = basename($strListPath);
    my $content .= "; ====== $strListName ====== \n";
    open (FILE, "<$strListPath") or &sysUtil::sysgen_die("$strListPath: open list error!", __FILE__, __LINE__);
    {
        local $/;
        $content .= <FILE>;
    }
    $content .= "; ============================= \n";
    close (FILE);
    return $content;
}


#****************************************************************************
# subroutine:  GetROM1_inputsection
#              get ROM1 input sections if ALICE or ZIMAGE support
# output: the obj lists in ROM1
#****************************************************************************
sub GetROM1_inputsection
{
    my $pmaui_standard_c_lib_temp = &app_feature_clib_rom();
    my $zimage = &$feature_query_function_ptr('zimage_support');
    my $alice = &$feature_query_function_ptr('alice_support');
    my $obj_list;

    $obj_list  = $pmaui_standard_c_lib_temp;
    $obj_list .= ($dummy_scatter ne 'TRUE') ? &Get_ObjListGen_List('objectROM1.list') : &Get_ObjListGen_List('objectROM1_dummy.list');
    
    if(defined $zimage and $zimage eq 'TRUE')
    {
        $obj_list .= "*                             (+RO)\n" if ($dummy_scatter ne 'TRUE');
        $obj_list .= "*                             (PRIMARY_ROCODE, PRIMARY_RODATA)";
    }
    else
    {
        $obj_list .= "\n*                             (+RO-DATA)";
    }

    return $obj_list;

}

#****************************************************************************
# subroutine:  GetInputSections
# input:       $strRegionName: which region InputSection belongs to 
# output:      $strContent: InputSections in string
#****************************************************************************
sub GetInputSections
{
    my ($RegionName) = @_;
    my $strCSVPath = &scatFrame::GetConfigInput($RegionName, "$RegionName.csv", scatFrame::InputSections, $bb_folder);
    my ($BasicInputSectionList_aref, $Index_href) = &CommonUtil::ParseCSV($strCSVPath, undef);
    my @InputSectionList;
    foreach my $item (@$BasicInputSectionList_aref)
    {
        my $strCondition = $item->[$Index_href->{FeatureOption}];
        my $strDummyScatter = $item->[$Index_href->{DummyScatter}];
        $strCondition =~ s/\s//g;
        $strDummyScatter =~ s/\s//g;
        next if($strCondition ne "" and (0 == &FileInfo::EvaluateFeatureOptionCondition($strCondition, $mf_option_ref)));
        next if($strDummyScatter ne "" and $strDummyScatter ne $dummy_scatter);
        push @InputSectionList, $item;
    }
    my $strContent = ";$strCSVPath\n";
    $strContent .= &scatFrame::GenInputSections(\@InputSectionList, $Index_href);
    return $strContent;
}

#****************************************************************************
# subroutine:  GetRegion_before_cached_dummy_end
#              get the region before cached_dummy_end
#
# output: the region name
#****************************************************************************
sub GetRegion_before_cached_dummy_end
{
    &sysUtil::sysgen_die("tools/scatGenLib.pl: the layout of extsram has not been generated", __FILE__, __LINE__) 
     if(!defined $g_region_before_cached_dummy_end);
    return $g_region_before_cached_dummy_end;
}
#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: CACHED_DUMMY_END :: start address
# input:       BB , Mode (BASIC, L1S, GSM, GPRS, UMTS)
#****************************************************************************
sub CACHEDDUMMYEND_query_offset
{
    my ($bb, $ram_size) = @_;

    ### Calculate start addresses
    my $cached_dummy_end_start_address_val;
    my $extsram_base_value = 0;
    my $j2me_support = &$feature_query_function_ptr('j2me_support');
    my $mode = &$feature_query_function_ptr('MODE');
    my ($region_size_tx, $region_size_rx) = &sysUtil::DSPTXRX_query_length($bb, $mode);
    my ($dsp_sharemem_size, $mcu_c_dsp_c_len, $mcu_c_dsp_nc_len, $mcu_nc_dsp_c_len, $mcu_nc_dsp_nc_len) = &DSP_SHAREMEM_query_length($bb);
    
    if( $bb ne "MT6256")
    {
        if (defined $j2me_support and $j2me_support =~ /JBLENDIA/)
        {
            $cached_dummy_end_start_address_val = $extsram_base_value + $ram_size - $region_size_tx - $region_size_rx - $dsp_sharemem_size - (128*1024);
        }
        else
        {
            $cached_dummy_end_start_address_val = $extsram_base_value + $ram_size - $region_size_tx - $region_size_rx - $dsp_sharemem_size;
        }
    }
    else
    {
        my ($Tx1Base, $Tx2Base, $DSPOnlyBase, $RxBase, $DSP_RomBase)= &Query_DSP_MT6256_Info(2, $ram_size);
        $cached_dummy_end_start_address_val = hex($DSP_RomBase);
    }
    
    return $cached_dummy_end_start_address_val;
}

#****************************************************************************
# subroutine:  WarnMinus
# input:       $nNumber: to check if it's a minus
#****************************************************************************
sub WarnMinus
{
    my ($nNumber,$file, $line_no, $error_msg) = @_;
    &sysUtil::sysgen_die("tools/scatGenLib.pl: The Size($nNumber) is not correct. $error_msg", $file, $line_no) if($nNumber < 0);
}

#****************************************************************************
# subroutine:  isNAND
# return:      0=nor or SINGLE, 1=nand
#****************************************************************************
sub isNAND
{
    my ($func) = @_;
    my $nfb_or_emb;
    my $nRet = 0;
    if (defined &$func('nand_flash_booting') and &$func('nand_flash_booting') ne 'NONE')
    {
    	  $nfb_or_emb = &$func('nand_flash_booting');
    }
    elsif (defined &$func('emmc_booting') and &$func('emmc_booting') ne 'NONE')
    {
    	  $nfb_or_emb = &$func('emmc_booting');
    }
    else
    {
          $nfb_or_emb = 'NONE';
    }
    $nRet = ($nfb_or_emb eq "NONE" or $nfb_or_emb eq "SINGLE") ? 0 : 1;
    return $nRet; 
}

sub is_SINGLE
{
    my ($func) = @_;
    my $nfb_or_emb;
    my $nRet = 0;
    if (defined &$func('nand_flash_booting') and &$func('nand_flash_booting') ne 'NONE')
    {
    	  $nfb_or_emb = &$func('nand_flash_booting');
    }
    elsif (defined &$func('emmc_booting') and &$func('emmc_booting') ne 'NONE')
    {
    	  $nfb_or_emb = &$func('emmc_booting');
    }
    else
    {
          $nfb_or_emb = 'NONE';
    }
    $nRet = ($nfb_or_emb eq "SINGLE") ? 1 : 0;
    return $nRet; 
}
