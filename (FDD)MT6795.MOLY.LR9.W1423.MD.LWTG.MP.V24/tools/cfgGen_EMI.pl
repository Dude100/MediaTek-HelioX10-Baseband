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
#*   cfgGen_EMI.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script generates EMI part in the CFG file for flash tool for SV5
#*
#* Author:
#* -------
#*   Marvin Lin  (mtk03483)
#*
#*============================================================================
#*             HISTORY
#* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*------------------------------------------------------------------------------
#* $Revision$
#* $Modtime$
#* $Log$
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
#* 04 16 2013 guo-huei.chang
#* [MOLY00013409] [MT6290 Bring-up] DRAMC/EMI related Code Update
#* 1. update emigen to auto-gen all header files
#* 2. update init mempll
#* 3. update cfggen
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
#* 03 08 2013 guo-huei.chang
#* [MOLY00011607] update custom_EMI function and cfggen EMI part
#* update custom_EMI function into custom_EMI_MT6290.c and remove it in devdrv_fakeapi.c
#* update cfgGen_EMI.pl for MT6290
#* 
#* 08 16 2012 marvin.lin
#* [MOLY00002193] [MemoryStorage][Auto-Gen][EMI Gen/CFG Gen][Request For Design Change] support MT6280 combo memory
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
# auto flush print function
local $| = 1;

#****************************************************************************
# Constants
#****************************************************************************
my $CFGGEN_EMI_VERNO = " V0.03";
                      #  v0.03 , Fix compile error when $PLATFORM is not found
                      #  v0.02 , Support MT6255 SF+DDR or DISCRETE_NAND case
                      #  v0.01 , Fix unable to pre-compie custom_EMI_MT6256.c when make new issue
                      #  v0.00 , initial version 

#****************************************************************************
# Input Parameters and Global Variables
#****************************************************************************
my $DebugPrint = 0;

#****************************************************************************
# subroutine:  get_mem_dev_h_value
# input:       $str_BB_path:  BB folder path
# input:       $href_mem_dev: reference of hash of custom_MemoryDevice.h configurations
#****************************************************************************
sub get_mem_dev_h_value
{
    my ($str_BB_path, $href_makefile_options) = @_;
    my %mem_dev_options;
    my $CUSTOM_MEM_DEV_H = $str_BB_path . "\/custom_MemoryDevice.h";

    open (MEMDEVH_HANDLE, "<$CUSTOM_MEM_DEV_H") or &error_handler("$CUSTOM_MEM_DEV_H: file error!", __FILE__, __LINE__);
    while (<MEMDEVH_HANDLE>) {
        if (/^#define\s+(\w+)\s+\((\w*)\)/ || /^#define\s+(\w+)\s+(\w*)/)
        {
            my $option = $1;
            my $value  = $2;
            
            &error_handler("$CUSTOM_MEM_DEV_H: $option redefined in custom_MemoryDevice.h!", __FILE__, __LINE__) if defined($mem_dev_options{$option});
            if ((!defined $value) or ($value eq ''))
            {
                $mem_dev_options{$option} = 'TRUE';
            }
            else
            {
                $mem_dev_options{$option} = $value;
            }
        }
    }
    if ((!defined $href_makefile_options->{'combo_memory_support'}) or ($href_makefile_options->{'combo_memory_support'} eq 'FALSE'))
    {
        $mem_dev_options{COMBO_MEM_ENTRY_COUNT} = 1;
    }

    close (MEMDEVH_HANDLE);
    
    return %mem_dev_options;
}

#****************************************************************************
# subroutine:  error_handler
# input:       $error_msg:     error message
#****************************************************************************
sub error_handler
{
    my ($error_msg, $file, $line_no) = @_;
    
    my $final_error_msg = "CFGGEN ERROR: $error_msg at $file line $line_no\n";
    print $final_error_msg;
    die $final_error_msg;
}

#****************************************************************************
# subroutine:  get_emi_settings
# return:      EMI settings
#****************************************************************************
sub get_emi_settings
{
    my ($str_BB_path, $bb, $cc_cmd, $via_cmd, $option_tmp_file, $custom_emi_temp_local, $href_MAKEFILE_OPTIONS, $href_mem_dev_options) = @_;
    my @emi_settings;

    ### Pre-compile custom_EMI.c
    my ($custom_EMI_c_file);
    my $custom_emi_command;
    $custom_EMI_c_file = ".\/custom\/driver\/common\/custom_EMI_" . $bb . ".c";

    print "custom_EMI.c = $custom_EMI_c_file\n";
    $custom_emi_command = "$cc_cmd $via_cmd$option_tmp_file -E $custom_EMI_c_file > " . $custom_emi_temp_local . "\/" . "~custom_EMI_c.tmp";
    print "$custom_emi_command\n";
    
    my $status = system($custom_emi_command);
    &error_handler("\/tools\/cfgGen_EMI.pl: pre-compile $custom_EMI_c_file erro!", __FILE__, __LINE__) if ($status != 0);

    ### Get Memory Type
    my ($emi_clk, $emi_dev_type, $memory_type);
    my $CUSTOM_EMI_RELEASE_H;
    $CUSTOM_EMI_RELEASE_H = $str_BB_path . "\/custom_EMI_release.h";
    
    open (CUSTOM_EMI_RELEASE_H, "<$CUSTOM_EMI_RELEASE_H") or &error_handler("$CUSTOM_EMI_RELEASE_H: file error!", __FILE__, __LINE__);
    while (<CUSTOM_EMI_RELEASE_H>)
    {
        if (/#define __EMI_CLK_(\d+)MHZ__/)
        {
            $emi_clk = $1;
        }
        elsif (/#define __EMI_DEVICE_(\w+)__/)
        {
            $emi_dev_type = $1;
        }
    }
    close CUSTOM_EMI_RELEASE_H;
    if($href_MAKEFILE_OPTIONS->{'sip_ram_size'} ne "NONE")
    {
        $memory_type = "SIP_";
    }
    $memory_type .= $emi_dev_type . "_" . $emi_clk . "MHZ";

    ### Read EMI settings from ~custom_EMI_c.tmp
    my $file_content;
    my $custom_emi_path;
    $custom_emi_path = "<" . $custom_emi_temp_local . "\/~custom_EMI_c.tmp";
    
    print "path:$custom_emi_path\n";
    open (CUSTOM_EMI_C_TMP, $custom_emi_path) or &error_handler("~custom_EMI_c.tmp: file error!", __FILE__, __LINE__);
    {
        local $/;
        $file_content = <CUSTOM_EMI_C_TMP>;
    }
    close CUSTOM_EMI_C_TMP;

    ### Get EMI_INFO type declaration    
    my $EMI_INFO_decl_str;
    my %EMI_INFO_decl_hash;  # key: EMI register; value: index
    my $EMI_INFO_decl_count = 0;
    if ($file_content =~ /typedef\s*struct\s*\{([\S|\s]+?)\}\s*MTK_EMI_Info/)
    {
        $EMI_INFO_decl_str = $1;
    }
    while ($EMI_INFO_decl_str =~ /\{/)  # Skip all other contents between the beginning { and the real EMI info
    {
        $EMI_INFO_decl_str = $';
    }
    while ($EMI_INFO_decl_str =~ /unsigned int (\w+)\;/)
    {
        $EMI_INFO_decl_hash{$1} = $EMI_INFO_decl_count;
        $EMI_INFO_decl_count++;
        $EMI_INFO_decl_str = $';
    }
    print "EMI_INFO_decl_hash:\n" if ($DebugPrint == 1);
    foreach my $idx (keys %EMI_INFO_decl_hash)
    {
        print "$idx\n" if ($DebugPrint == 1);
    }

    ### Trim EMI Info contents string
    my $EMI_INFO_value_str;
    if ($file_content =~ /MTK_EMI_Info\s*EMI_INFO\[\]\s*\=\s*\{([\s|\S]+?)\}\;/)
    {
        $EMI_INFO_value_str = $1;
    }
    $EMI_INFO_value_str =~ s/\s//g;  # EMI_INFO_value_str becomes {EMI_INFO set 1},{EMI_INFO set 2},......,{EMI_INFO set n}

    my @EMI_INFO_value_array;
    @EMI_INFO_value_array = split(/},{/,$EMI_INFO_value_str);
    
    for my $idx (0..$#EMI_INFO_value_array)
    {
        $EMI_INFO_value_array[$idx] =~ s/^,//;  # Remove the beginning ,
        $EMI_INFO_value_array[$idx] =~ s/^{//;  # Remove the beginning {
        $EMI_INFO_value_array[$idx] =~ s/,$//;  # Remove the last ,
        $EMI_INFO_value_array[$idx] =~ s/,}$//;  # Remove the last ,}
        print "\$EMI_INFO_value_array[$idx]:\n$EMI_INFO_value_array[$idx]\n" if ($DebugPrint == 1);
    }

    for my $combo_idx (1..$href_mem_dev_options->{COMBO_MEM_ENTRY_COUNT})
    {
        ### Get EMI Info contents
        my %cur_emi_info_value_list;
        foreach (split(/,/, $EMI_INFO_value_array[$combo_idx-1]))
        {
            if ((/\.(\w+)=\((0x[\w]{1,8})\)/) or (/\.(\w+)=(0x[\w]{1,8})/))
            {
                $cur_emi_info_value_list{$1} = $2;
            }
        }
        $emi_settings[$combo_idx] = <<"__TEMPLATE";
        memory_type: $memory_type
        EMI_Setting:
__TEMPLATE
        foreach my $key (sort keys %cur_emi_info_value_list)
        {
            if ($key =~ /(\w+)_val/)
            {
                $emi_settings[$combo_idx] .= "            " . uc($1) . ": " . $cur_emi_info_value_list{$key} . "\n";
            }
            else
            {
                $emi_settings[$combo_idx] .= "            " . uc($key) . ": " . $cur_emi_info_value_list{$key} . "\n";
            }
        }
        print "combo_mem_idx:$combo_idx\n" if ($DebugPrint == 1);
        print "$emi_settings[$combo_idx]\n" if ($DebugPrint == 1);
    }
    
    return @emi_settings;
}

#****************************************************************************
# subroutine:  get_flash_settings
# return:      Flash settings
#****************************************************************************
sub get_flash_settings
{
    my ($str_BB_path, $bb, $cc_cmd, $via_cmd, $option_tmp_file, $custom_emi_temp_local, $href_MAKEFILE_OPTIONS, $href_mem_dev_options) = @_;
    my @flash_settings;

    ### Read flash ID from combo_flash_id.h
    my (@flash_id_str_list, @flash_id, @valid_id_length_list);
    my $flash_id_template;
    my $decide_flash_type = "NAND";
    my $mcp_count = 0;
    my $COMBO_FLASH_ID_H;
    $COMBO_FLASH_ID_H = $str_BB_path . "\/combo_flash_id.h";
    
    open (COMBO_FLASH_ID_H, "<$COMBO_FLASH_ID_H") or &error_handler("$COMBO_FLASH_ID_H: file error!", __FILE__, __LINE__);
    while (<COMBO_FLASH_ID_H>)
    {
        if (/\s+(\d+),\s*\/\/\s*Valid\s+ID\s+length/)
        {
            $valid_id_length_list[$mcp_count] = $1;
        }
        elsif (/\s+\{(.+)\}\s*\/\/\s*Flash\s+ID/)
        {
            $flash_id_str_list[$mcp_count] = $1;
            ##$mcp_count++;
            if($href_MAKEFILE_OPTIONS->{'serial_flash_support'} eq 'TRUE')##SF align with NAND, restruct 16bit type ID string
            {
                    $flash_id_template = undef;
            		$decide_flash_type = "SF";
            		$flash_id_str_list[$mcp_count] =~ s/\{//;
            		$flash_id_str_list[$mcp_count] =~ s/\}//;
            		$flash_id_str_list[$mcp_count] =~ s/\s+//g;
            		print "Before restruct id string is : $flash_id_str_list[$mcp_count]\n";
            		@flash_id = split /\,/, $flash_id_str_list[$mcp_count];
            		my $cur_flash_id = "0xFFFF";
            		for (0..7)  # there are totally 8 flash ID
            		{
            			$cur_flash_id = sprintf("0x%04X", hex($flash_id[$_]));
            			print "cur_flash_id is : $cur_flash_id\n";
            			if(7 == $_)
            			{
            				$flash_id_template .= "$cur_flash_id\n";
            				###$block_info_lines .=  "   \{$tmp_start, $tmp_size\},\n";
            			}
            			else
            			{
            				$flash_id_template .= "$cur_flash_id, \n";
            			}
            			print "After restruct template id string is : $flash_id_template\n";
            			chomp($flash_id_template);
            		}
            		$flash_id_str_list[$mcp_count] = $flash_id_template;
            		print "After restruct id string is : $flash_id_template\n";
            }
            $mcp_count++;
        }
    }
    close COMBO_FLASH_ID_H;


    #Parse combo_nfi_config.h to gen NAND Parameters for Flashtool Download
    my @combo_nfi_info_struct;
    if($href_MAKEFILE_OPTIONS->{'nand_support'} eq 'TRUE')
    {
        my $COMBO_FLASH_CONFIG_H;##NAND Flash Config File
        $COMBO_FLASH_CONFIG_H = $str_BB_path . "\/combo_nfi_config.h";
        
        my $combo_flash_idx = -1;
        print "$COMBO_FLASH_CONFIG_H\n";
        open (COMBO_FLASH_CONFIG_H, "<$COMBO_FLASH_CONFIG_H") or &error_handler("$COMBO_FLASH_CONFIG_H: file error!", __FILE__, __LINE__);
        while (<COMBO_FLASH_CONFIG_H>)
        {
            if (/\s*0x(\w+),\s*\/\/\s*NFI_(\w+)_(\w+)/)
            {
                #print "1-[$combo_flash_idx]: $1, $2, $3\n";
                $combo_nfi_info_struct[$combo_flash_idx] .= "\n            " ."NFI_" ."$2_" . "$3" .": " ."0x$1";
            }
            elsif (/\s*(\w+),\s*\/\/\s*NFI_(\w+)_(\w+)/)
            {
                #print "2-[$combo_flash_idx]: $1, $2, $3\n";
                $combo_nfi_info_struct[$combo_flash_idx] .= "\n            " ."NFI_" ."$2_" . "$3" .": " ."$1";
            }
            elsif (/\s*\{(.+)\},\s*\/\/\s*NFI_(\w+)_(\w+)/)
            {
                #print "3-[$combo_flash_idx]: $1, $2, $3\n";
                if($2 eq 'BB')
                {
                    $combo_nfi_info_struct[$combo_flash_idx] .= "\n            " ."NFI_" ."$2_" . "$3" .": " ."[$1]";
                }
                else
                {
                    $combo_flash_idx++;#to calculate combo idx
                    $combo_nfi_info_struct[$combo_flash_idx] .= "\n            " ."NFI_" ."$2_" . "$3" .": " ."$1";#NFI_DeviceName is the first parse line of combo flash
                }
            }
        }
    }

    for (0..($mcp_count-1))
    {
        my $combo_idx = $_ + 1;
        
        
        $flash_settings[$combo_idx] .= <<"__TEMPLATE";
      - flash_info:
            flash_type: $decide_flash_type
            id_length: $valid_id_length_list[$_]
__TEMPLATE
        if (defined $combo_nfi_info_struct[$_])
        {
            $flash_settings[$combo_idx] .= <<"__TEMPLATE";
            flash_id: [$flash_id_str_list[$_]]$combo_nfi_info_struct[$_]
__TEMPLATE
        }
        else
        {
            $flash_settings[$combo_idx] .= <<"__TEMPLATE";
            flash_id: [$flash_id_str_list[$_]]
__TEMPLATE
        }
    }

    return @flash_settings;
}

#****************************************************************************
# subroutine:  gen_external_memory_setting
# input:       $str_BB_path:  BB folder path
# return:      External Memory Setting
#****************************************************************************
sub gen_external_memory_setting
{
    my ($str_BB_path, $str_board_ver, $bb, $cc_cmd, $via_cmd, $option_tmp_file, $custom_emi_temp_local, $href_MAKEFILE_OPTIONS) = @_;
    my (@emi_settings, @flash_settings);
    my %custom_mem_dev_options;

    %custom_mem_dev_options = &get_mem_dev_h_value($str_BB_path, $href_MAKEFILE_OPTIONS);
    
    ### Generate EMI settings from CFG file for chips which do not support Auto-Gen
    if (($bb ne 'MT6276') and ($bb ne 'MT6256') and ($bb ne 'MT6255') and ($bb ne 'MT6280') and ($bb ne 'MT6290'))
    {
        my $EMI_CFG_FILE;
        $EMI_CFG_FILE = $str_BB_path . "\/" . $str_board_ver . "\.cfg";
        
        open (EMI_CFG_FILE, "<$EMI_CFG_FILE") or &error_handler("$EMI_CFG_FILE: file error!", __FILE__, __LINE__);
        my $saved_sep = $/;
        undef $/;
        my $emi_cfg_file_content = <EMI_CFG_FILE>;
        close EMI_CFG_FILE;
        $/ = $saved_sep;
        my $template = <<"__TEMPLATE";
############################################################################################################
#
#  External Memory Setting
#
############################################################################################################

$emi_cfg_file_content

__TEMPLATE

        return $template;
    }

    @emi_settings = &get_emi_settings($str_BB_path, $bb, $cc_cmd, $via_cmd, $option_tmp_file, $custom_emi_temp_local, $href_MAKEFILE_OPTIONS, \%custom_mem_dev_options);
    @flash_settings = &get_flash_settings($str_BB_path, $bb, $cc_cmd, $via_cmd, $option_tmp_file, $custom_emi_temp_local, $href_MAKEFILE_OPTIONS, \%custom_mem_dev_options);
    
    ###
    my $combo_mem_param;
    for my $combo_idx (1..$custom_mem_dev_options{COMBO_MEM_ENTRY_COUNT})
    {
        $combo_mem_param .= <<"__TEMPLATE";
       # EMI $combo_idx
$flash_settings[$combo_idx]
$emi_settings[$combo_idx]
__TEMPLATE
    }

    my $para_ver;
    if($bb eq 'MT6290')
    {
        $para_ver = "v3.1";
    }
    elsif($bb eq 'MT6280')
    {
        $para_ver = "v2";
    }
    else
    {
        $para_ver = "v1";
    }

    my $template = <<"__TEMPLATE";
############################################################################################################
#
#  External Memory Setting
#
############################################################################################################
    
external_memory:
    parameters_version: $para_ver
    PMIC: $href_MAKEFILE_OPTIONS->{'pmic'}
    parameters:
$combo_mem_param
__TEMPLATE
}

return 1;
