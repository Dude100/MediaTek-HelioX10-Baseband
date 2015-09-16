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
#*   cfgGen_flash.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script generates flash part in the CFG file for flash tool for SV5
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
#*
#*------------------------------------------------------------------------------
#* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*============================================================================
#****************************************************************************/

#****************************************************************************
# Included Modules
#****************************************************************************
use strict;

1;

#****************************************************************************
# Constants
#****************************************************************************
my $CFGGEN_FLASH_VERNO = " V0.00";
                        #  v0.00 , initial version 

#****************************************************************************
# Input Parameters and Global Variables
#****************************************************************************

#****************************************************************************
# subroutine:  get_mem_dev_h_value
# input:       $str_BB_path:  BB folder path
# input:       $href_mem_dev: reference of hash of custom_MemoryDevice.h configurations
#****************************************************************************
sub get_mem_dev_h_value
{
    my ($str_BB_path, $href_mem_dev) = @_;
    
    my $CUSTOM_MEM_DEV_H = $str_BB_path . "\\custom_MemoryDevice.h";

    open (MEMDEVH_HANDLE, "<$CUSTOM_MEM_DEV_H") or &error_handler("$CUSTOM_MEM_DEV_H: file error!", __FILE__, __LINE__);
    while (<MEMDEVH_HANDLE>) {
        if (/^#define\s+(\w+)\s+\((\w*)\)/ || /^#define\s+(\w+)\s+(\w*)/)
        {
            my $option = $1;
            my $value  = $2;
            
            &error_handler("$CUSTOM_MEM_DEV_H: $option redefined in custom_MemoryDevice.h!", __FILE__, __LINE__) if defined($href_mem_dev->{$option});
            if ((!defined $value) or ($value eq ''))
            {
                $href_mem_dev->{$option} = 'TRUE';
            }
            else
            {
                if ($option =~ /CS(\d+)_PART_NUMBER/)
                {
                    if (($href_mem_dev->{MEMORY_DEVICE_TYPE} eq 'LPSDRAM') or ($href_mem_dev->{MEMORY_DEVICE_TYPE} eq 'LPDDR') or ($href_mem_dev->{MEMORY_DEVICE_TYPE} eq 'LPDDR2'))
                    {
                        if ($value =~ /(\w+)_([A-Za-z0-9]+EVB)/ or $value =~ /(\w+)_(Sapphire28)/i)
                        {
                            $href_mem_dev->{$option} = $1;
                        }
                        else
                        {
                            $href_mem_dev->{$option} = $value;
                        }
                    }
                    elsif ($href_mem_dev->{MEMORY_DEVICE_TYPE} eq 'NOR_LPSDRAM_MCP')
                    {
                        if ($value =~ /(\w+)_([A-Za-z0-9]+EVB)/ or $value =~ /(\w+)_(Sapphire28)/i)
                        {
                            $href_mem_dev->{$option} = $1;
                        }
                        else
                        {
                            $href_mem_dev->{$option} = $value;
                        }
                    }
                    else
                    {
                        $href_mem_dev->{$option} = $value;
                    }
                }
                else
                {
                    $href_mem_dev->{$option} = $value;
                }
            }
        }
    }
    close (MEMDEVH_HANDLE);
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
# subroutine:  gen_flash_info
# return:      Flash information
#****************************************************************************
sub gen_flash_info
{
    my ($str_BB_path, $str_board_ver, $bb) = @_;
    
    my %MEM_DEV_H_Value;
    &get_mem_dev_h_value($str_BB_path, \%MEM_DEV_H_Value);
    
    ### DRAM
    my $is_dram = (($MEM_DEV_H_Value{MEMORY_DEVICE_TYPE} eq 'LPSDRAM') or ($MEM_DEV_H_Value{MEMORY_DEVICE_TYPE} eq 'LPDDR') or ($MEM_DEV_H_Value{MEMORY_DEVICE_TYPE} eq 'LPDDR2')) ? 'TRUE' : 'FALSE';
    
    ### Flash type
    my $flash_type;
    if ($is_dram eq 'TRUE')
    {
        $flash_type = "[NAND Flash]";
    }
    elsif ($MEM_DEV_H_Value{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH')
    {
        $flash_type = "[Serial Flash]";
    }
    else
    {
        $flash_type = "[NOR Flash]";
    }

    ### Read custom_flash.h for flash ID and NOR flash size
    my ($flash_id_str, @flash_id, $flash_id_template);
    my ($nor_flash_size_mb, $nor_flash_size_template);
    my $CUSTOM_FLASH_H   = $str_BB_path . "\\custom_flash.h";
    open (CUSTOM_FLASH_H, "<$CUSTOM_FLASH_H") or &error_handler("$CUSTOM_FLASH_H: file error!", __FILE__, __LINE__);
    while (<CUSTOM_FLASH_H>)
    {
        if (/const\s+kal_char\s+FLASH_ID\[\]\s+=\s+\"(.+)\";/)
        {
            $flash_id_str = $1;
        }
        elsif (/NOR_FLASH_SIZE\(Mb\):\s+(\d+)/)
        {
            $nor_flash_size_mb = $1;
        }
    }
    close CUSTOM_FLASH_H;
    if ($MEM_DEV_H_Value{CS0_PART_NUMBER} eq 'EHD013111MA_60_MTKINTERN')  # work-around for QC
    {
        $flash_id_str = "0x0020,0x00BA,0x0010,0x0055";
    }
    print "FLASH_ID = $flash_id_str\n";
    $flash_id_str =~ s/\{//;
    $flash_id_str =~ s/\}//;
    $flash_id_str =~ s/\s+//g;
    @flash_id = split /\,/, $flash_id_str;
    for (0..7)  # there are totally 8 flash ID
    {
        my $idx = $_ + 1;
        my $cur_flash_id = (($is_dram eq 'TRUE') or ($MEM_DEV_H_Value{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH')) ? "0xFF" : "0xFFFF";
        if (defined $flash_id[$_])
        {
            if (($is_dram eq 'TRUE') or ($MEM_DEV_H_Value{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH'))
            {
                $cur_flash_id = sprintf("0x%02X", hex($flash_id[$_]));
            }
            else
            {
                $cur_flash_id = sprintf("0x%04X", hex($flash_id[$_]));
            }
        }
        $flash_id_template .= "ID$idx=$cur_flash_id\n";
    }
    chomp $flash_id_template;
    
    if ($is_dram eq 'FALSE')
    {
        $nor_flash_size_template = sprintf("Flash_Size=0x%x", $nor_flash_size_mb/8*1024*1024);
    }
    
    my $template = <<"__TEMPLATE";
$flash_type
$flash_id_template
$nor_flash_size_template

__TEMPLATE
}
