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
#*   ckScatter.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script parse scatter file and embedded checking rules for it
#*       1. Load View      --- NOR Flash
#*       2. Execution View --- RAM Device
#*       3. DSP execution region 
#*
#* Author:
#* -------
#*   JI Huang  (mtk01077)
#*
#****************************************************************************/

#****************************************************************************
# Included Modules
#****************************************************************************
use strict;
BEGIN { push @INC, './tools/' }  # add additional library path
use sysGenUtility;                 #pm file name without case sensitivity
use FileInfoParser;
#****************************************************************************
# Constants
#****************************************************************************
my $CKSCATTER_VERNO     =  "m0.02";
                         #  m0.02 , Support path and filename case sensitive on Linux
                         #  m0.01 , skip nfb=SINGLE because it equals to smart phone
                         #  v0.48 , skip ckscatter2 check when ALICE_SUPPORT is turned on
                         #  v0.47 , No need to check the DSP size sould be 2^N and the alignment restriction of DSP base and DSP length
                         #  v0.45 , skip smartphone by using sysgenUtility.pm
                         #  v0.44 , skip smartphone if secure turns on
                         #  v0.43 , Fix parsing makefile 
                         #  v0.42 , Remove $$ to support Perl v5.12.*
                         #  v0.41 , Support 6255
                         #  v0.40 , skip smartphone DSP checking in ckscatter phase 1
                         #  v0.39 , Change custom_flash.c to custom_flash.h and skip smartphone in ckscatter phase 2
                         #  v0.38 , Refine EMI_EXTSRAM_SIZE pattern-matching to adapt to flexible () and spaces
                         #  v0.37 , Skip ckscatter2 check when dcm_compression is turned on because ckscatter cannot see compressed image and will misjudge 
                         #  v0.36 , Get EXTSRAM_SIZE from custom_EMI_release.h
                         #  v0.35 , Support eMMC Booting
                         #  v0.34 , Skip SECURE_RO_ME and SECURE_RO_S from load region boundary check because they will be downloaded to CBR region
                         #  v0.33 , Skip DSP alignment check for MT6276 shrinking
                         #  v0.32 , Skip ckscatter2 check when DUMMY_SCATTER_ENABLE is turned on because invalid memory range will be used in Scatter Gen
                         #  v0.31 , To support eMMC Booting
                         #  v0.30 , Skip ckscatter2 check when ZIMAGE_SUPPORT is turned on because ckscatter cannot see compressed image and will misjudge
                         #  v0.29 , Remove MT6253D
                         #  v0.28 , Rename MT6253E/MT6253L as MT6252H/MT6252
                         #  v0.27 , Check whether RAM consumption has exceeded DUMMY_END
                         #  v0.26 , Move EMI_EXTSRAM_SIZE to custom_EMI_release.h
                         #  v0.25 , Resume RAM boundary checking for MT6253E/L
                         #  v0.24 , To support MT6253E/L, move EXTSRAM_SIZE to custom_EMI_release.h
                         #  v0.23 , To support MT6253DV
                         #  v0.22 , To support MT6253E/L, remove RAM boundary check because EXTSRAM_SIZE was moved from custom_EMI.h to custom_EMI_release.h
                         #  v0.21 , To support MT6251
                         #  v0.20 , Fix sort hex issue
                         #  v0.19 , Adapt to NOR_FLASH_DENSITY unit change (Mbit to byte)
                         #  v0.18 , Adopt different FAT configuration in custom_MemoryDevice.h
                         #  v0.17 , Fix block alignment check errors
                         #  v0.16 , Add MT6268 and remove BT/MT check
                         #  v0.15 , Add file name and fline number information and unify all auto-gen error messages
                         #  v0.14 , NAND_FLASH_BOOTING makefile option is changed
                         #  v0.13 , Modify RAM boundary calculation and bypass 6516 boundary check
                         #  v0.12 , Modify ~flash_cfg_tmp.c parsing rules for flash_opt.h template change for FOTA
                         #  v0.11 , Parse ~flash_cfg_tmp.c only in Phase2 and fix load region calculation issue
                         #  v0.10 , Split ckscatter into two phases and arrange checks into each phase
                         #  v0.09 , add 2nd phase ckscatter at post-build stage
                         #  v0.08 , temporarily remove FAT and load region check due to lack of FAT information and add CODE_PATCH_CODE/DSP_TX/DSP_RX start address alignment check
                         #  v0.07 , add FAT and load region overlap check
                         #  v0.06 , add SECONDARY_EXTSRAM_DSP_TX 
                         #  v0.05 , update scatter parser
                         #  v0.04 , initial version 

#****************************************************************************
# Input Parameters and Global Variables
#****************************************************************************
my $phase            = $ARGV[0];
my $stop_build       = $ARGV[1];
my $SCATTERFILE      = $ARGV[2];
my $LIS_TEMP         = $ARGV[3];
my $FLASH_CFG_TMP    = $ARGV[4];
my $themf            = $ARGV[5];
my $BB_FOLDER        = $ARGV[6];
my $CUSTOM_EMI_H     = $ARGV[6] . '/' . "custom_EMI.h";
my $CUSTOM_EMI_RELEASE_H = $ARGV[6] . '/' . "custom_EMI_release.h";
my $CUSTOM_FLASH_H   = $ARGV[6] . '/' . "custom_flash.h";
my $DUMMY_SCATTER_ALLOW = $ARGV[7];

my %Scat_Content;
my %MAKEFILE_OPTIONS;
my %EMI_H_Value;
my %FLASH_C_Value;
my @FLASH_H_Value_BLK_LIST;
my %FLASH_INFO;
my %NORFLASH_INFO_BLOCKS_TABLE;

# load/exec regions obtained from scatter file
my %LoadView;
my %ExecView;

# load/exec regions obtained from temp lis file
my %LoadRegion;
my %ExecRegion;


#****************************************************************************
# 0 >>>  parse input parameters and decide ckscatter phase
#****************************************************************************
print "phase=$phase, stop_build=$stop_build\n";

    # 0.1 >>> parse Project Make File
    my $keyname;

    if (!-e $themf)
    {
        &error_handler($stop_build, "$themf: NOT exist!", __FILE__, __FILE__, __LINE__) if (!-e $themf);
    }
    
    if ($themf =~ /make\/\w+(BT)_\w+.mak/i or $themf =~ /make\/\w+(MT)_\w+.mak/i) {
        $MAKEFILE_OPTIONS{'type'} = uc($1);
    }

    open (FILE_HANDLE, "<$themf") or &error_handler($stop_build, "$themf: file error!", __FILE__, __LINE__);
    while (<FILE_HANDLE>) {
        if ((/^([^\#]*)\#?.*/) && ($1 =~ /^(\w+)\s*=\s*(.*\S)\s*$/)) {
            $keyname = lc($1);
            #defined($MAKEFILE_OPTIONS{$keyname}) && warn "$1 redefined in $themf!\n";
            $MAKEFILE_OPTIONS{$keyname} = uc($2);
        }
    }
    close (FILE_HANDLE);

    # 0.2 >>> parse key definition in CUSTOM_FLASH_H
    open (FLASHC_HANDLE, "<$CUSTOM_FLASH_H") or &error_handler($stop_build, "$CUSTOM_FLASH_H: file error!", __FILE__, __LINE__);
    while (<FLASHC_HANDLE>)
    {
        if (/NOR_FLASH_DENSITY:\s*(\w*)/)
        {
            $FLASH_INFO{'NOR_FLASH_DENSITY'} = $1;
        }
        elsif (/^FLASH_REGIONINFO_VAR_MODIFIER\s+FlashBlockTBL\s+\S+/)
        {
            $FLASH_C_Value{'BlockTBLFlag'} ++;
        }
        elsif (defined $FLASH_C_Value{'BlockTBLFlag'})
        {
            $FLASH_C_Value{'BlockTBLTxt'} .= $_;
            # debug purpose
            # print $_;
            if (/\{\s*(\S+)\s*,\s*(\S+)\s*\}/)
            {
                push @FLASH_H_Value_BLK_LIST, $_;
            }
            delete $FLASH_C_Value{'BlockTBLFlag'} if (/^\s+EndBlockInfo\s+/);
        }
    }
    close (FLASHC_HANDLE);
    #&dump_custom_flash_h_values();
    
    # 0.3 >>> parse key definition in CUSTOM_EMI_RELEASE_H
    open (EMIRELEASEH_HANDLE, "<$CUSTOM_EMI_RELEASE_H") or &error_handler("$CUSTOM_EMI_RELEASE_H: file error!", __FILE__, __LINE__);
    while (<EMIRELEASEH_HANDLE>) {
        if (/^#define EMI_EXTSRAM_SIZE\s+\(\s*\(*\s*\(*\s*(\S+)\)*\s*<<\s*20\s*\)*\s*>>\s*3\s*\)/)
        {
            $EMI_H_Value{'EXTSRAM_SIZE'} = $1;
        }
    }
    close (EMIRELEASEH_HANDLE);
    #&dump_custom_emi_h_values();

    # 0.4 >>> do check in each phase
    if ($phase == 1)
    {
        &ckscatter_phase1();
    }
    elsif ($phase == 2)
    {
        &ckscatter_phase2();
    }
    else
    {
        &error_handler($stop_build, "make/build.mak: Unsupported ckscatter command!", __FILE__, __LINE__);
    }
    
    exit;

#****************************************************************************
# 1 >>>  Phase 1
#****************************************************************************
sub ckscatter_phase1
{
    print "Phase1!\n";

    # 1.1 >>>  open and read scatter file, keep the important content in memory
    open (SCAT_HANDLE, "<$SCATTERFILE") or &error_handler($stop_build, "$SCATTERFILE: file error!", __FILE__, __LINE__);
    while (<SCAT_HANDLE>) {
       if (/\(.+\)/) {next;}
       if (/;/) {s/;.*//;}
       if (/{/ or /}/ or /\S+/) { $Scat_Content{$.} = $_; }
    }
    close (SCAT_HANDLE);
    #&dump_scatter_file_structure();

    # 1.2 >>> Build the LOAD View List and Execution View List
    &parse_scatter_file_structure();
    #&dump_load_view();
    #&dump_exec_view();

    # 1.3 >>> Check the DSP_TX and DSP_RX execution region
    if (($MAKEFILE_OPTIONS{'platform'} ne 'MT6276') and ($MAKEFILE_OPTIONS{'platform'} ne 'MT6575') and ($MAKEFILE_OPTIONS{'platform'} ne 'MT6573'))  # MT6276 is skipped because these regions no longer obey the alignment rule for shrinking purpose
    {
        my $rule = 0;
    
        foreach my $e ( grep { /EXTSRAM_DSP_[TR]X/ } keys %ExecView )
        {
            printf "DSP Checking: $e \n";
    
            # 1 : No Overlay
            if ( defined $ExecView{$e}->{'attr'} and $ExecView{$e}->{'attr'} eq "OVERLAY")
            {
                printf "$e violate rule , No OVERLAY\n";
                $rule++;
            }
            
            # 2 : Size >= 4KB
            if ( exists $ExecView{$e}->{'length'} and hex( $ExecView{$e}->{'length'} ) < 4 * 1024 )
            {
                my $length = $ExecView{$e}->{'length'};
                printf "$e violate rule , the Length($length) too small\n";
                $rule++;
            }
            elsif ( not exists $ExecView{$e}->{'length'} )
            {
                printf "$e violate rule , please define Length\n";
                $rule++;
                next;
            }
            # Size must be 4K align
            my $sz = hex( $ExecView{$e}->{'length'} );
            if ($sz % (4 * 1024))
            {
                printf "$e violate rule , size must be 4K align \n";
                $rule++;
                next;
            }
    
            # 3 : address need to be assigned
            if ( defined $ExecView{$e}->{'begin'} and $ExecView{$e} =~ /\+/ )
            {
                printf "$e address needs to be assigned\n";
                $rule++;
            }
            elsif ( not defined $ExecView{$e}->{'begin'} )
            {
                printf "$e address not calculated, script error , please contact MTK\n";
                $rule++;
            }
        }
        if ($rule > 0)
        {
            &error_handler($stop_build, "$SCATTERFILE: Scatter File DSP check rule fail! Please contact with Scatter File owner!", __FILE__, __LINE__);
        }
    }

    # 1.4 >>> CODE_PATCH_CODE, DSP_TX, and DSP_RX start addresses need to be 4KB-aligned
    {
        if (exists $MAKEFILE_OPTIONS{'platform'} and (&config_query_arm9($MAKEFILE_OPTIONS{'platform'}) == 1))
        {
            foreach my $e ( keys %ExecView )
            {
                if (($e =~ /EXTSRAM_DSP_[TR]X/) || ($e eq 'CODE_PATCH_CODE'))
                {
                    #printf("$e start address = %08X\n", $ExecView{$e}->{'addr'});
                    if (!defined $ExecView{$e}->{'begin'})
                    {
                        &error_handler($stop_build, "$SCATTERFILE: $e lack of start address! Please contact with Scatter File owner!", __FILE__, __LINE__);
                    }
                    if (hex($ExecView{$e}->{'addr'}) % (4*1024) != 0)
                    {
                        &error_handler($stop_build, "$SCATTERFILE: $e start address needs to be 4KB-aligned! Please contact with Scatter File owner!", __FILE__, __LINE__);
                    }
                }
            }
        }
    }
    
    # 1.5 >>> BOOTLOADER, __HIDDEN_SECURE_RO, __HIDDEN_FLASHTOOL_CFG, __HIDDEN_CUST_PARA start addresses need to be block-aligned
    my $SINGLE = ((exists $MAKEFILE_OPTIONS{'nand_flash_booting'} and $MAKEFILE_OPTIONS{'nand_flash_booting'} eq 'SINGLE') or 
                  (exists $MAKEFILE_OPTIONS{'emmc_booting'} and $MAKEFILE_OPTIONS{'emmc_booting'} eq 'SINGLE'));
    if (1 != &FileInfo::is_SmartPhone(\%MAKEFILE_OPTIONS) and 1 != $SINGLE )
    {
        &get_block_table();
        my @offset = sort {$b <=> $a} keys %NORFLASH_INFO_BLOCKS_TABLE;

        foreach ( keys %LoadView )
        {
            if (/BOODLOADER|__HIDDEN_SECURE_RO|__HIDDEN_FLASHTOOL_CFG|__HIDDEN_CUST_PARA/)
            {
                foreach my $i (@offset)
                {
                    if (hex($LoadView{$_}->{'begin'}) >= $i)
                    {
                        if (hex($LoadView{$_}->{'begin'}) == $i)
                        {
                            last;
                        }
                        my $tmp = hex($LoadView{$_}->{'begin'}) - $i;
                        while ($tmp > 0)
                        {
                            $tmp -= $NORFLASH_INFO_BLOCKS_TABLE{$i};
                        }
                        if ($tmp != 0)
                        {
                            &error_handler($stop_build, "$SCATTERFILE: $_ start address needs to be block-aligned! Please contact with Scatter File owner!", __FILE__, __LINE__);
                        }
                        else
                        {
                            last;
                        }
                    }
                }
            }
        }
    }
}

#****************************************************************************
# 2 >>>  Phase 2
#****************************************************************************
sub ckscatter_phase2
{
    print "Phase2!\n";

    # 2.10 >>>  6516 series do not have FAT information and thus is bypassed in ckscatter_phase2
    if (exists $MAKEFILE_OPTIONS{'platform'} and ($MAKEFILE_OPTIONS{'platform'} =~ /6516/ or $MAKEFILE_OPTIONS{'platform'} =~ /6573/ or $MAKEFILE_OPTIONS{'platform'} =~ /6575/))
    {
        print "bypass check on Smart Phone!\n";
        return;        
    }

    # 2.11 >>>  BT/MT projects do not contain EXTSRAM and thus is bypassed in ckscatter_phase2
    if (exists $MAKEFILE_OPTIONS{'type'} and ($MAKEFILE_OPTIONS{'type'} =~ /BT/ or $MAKEFILE_OPTIONS{'type'} =~ /MT/))
    {
        print "bypass check on BT/MT!\n";
         return;        
    }

    # 2.12 >>>  When ZIMAGE_SUPPORT or DCM Compression is turned on, ckscatter will misjudge because it cannot recognize compressed case. Besides, another tool will be used to check ZIMAGE_SUPPORT/DCM Compression memory expiration
    if (exists $MAKEFILE_OPTIONS{'zimage_support'} and ($MAKEFILE_OPTIONS{'zimage_support'} eq 'TRUE'))
    {
        print "bypass check when ZIMAGE_SUPPORT = TRUE!\n";
        return;        
    }
    if (exists $MAKEFILE_OPTIONS{'dcm_compression_support'} and ($MAKEFILE_OPTIONS{'dcm_compression_support'} eq 'TRUE'))
    {
        print "bypass check when dcm_compression_support = TRUE!\n";
        return;        
    }
    if (exists $MAKEFILE_OPTIONS{'alice_support'} and ($MAKEFILE_OPTIONS{'alice_support'} eq 'TRUE'))
    {
        print "bypass check when alice_support = TRUE!\n";
        return;        
    }    

    # 2.13 >>>  When DUMMY_SCATTER_ENABLE is turned on (only available on NOR booting), ckscatter should bypass
    if ((exists $MAKEFILE_OPTIONS{'nand_flash_booting'} and $MAKEFILE_OPTIONS{'nand_flash_booting'} eq 'NONE') and (!exists $MAKEFILE_OPTIONS{'emmc_booting'} or $MAKEFILE_OPTIONS{'emmc_booting'} eq 'NONE'))
    {
        if (exists $MAKEFILE_OPTIONS{'dummy_scatter_enable'} and ($MAKEFILE_OPTIONS{'dummy_scatter_enable'} eq 'TRUE'))
        {
            if ($DUMMY_SCATTER_ALLOW == 1)
            {
                print "bypass check when DUMMY_SCATTER_ENABLE = TRUE!\n";
                return;
            }
        }
    }

    # 2.2 >>>  open and read temp lis file, keep the important content in memory
    open (LIS_HANDLE, "<$LIS_TEMP") or &error_handler($stop_build, "$LIS_TEMP: file error!", __FILE__, __LINE__);
    my $LoadRegion_seq = 0;
    my $ExecRegion_seq = 0;
    while (<LIS_HANDLE>) {
       if (/Load\s+Region\s+(\S+)\s+\(Base:\s+(\w+),\s+Size:\s+(\w+),\s+Max:\s+(\w+)/)
       {
#           print $_ ,  "\n";
           $LoadRegion{$1}->{'Base'} = $2;
           $LoadRegion{$1}->{'Size'} = $3;
           $LoadRegion{$1}->{'Max'} = $4;
           $LoadRegion{$1}->{'Seq'} = $LoadRegion_seq;
           $LoadRegion_seq++;
       }
       elsif (/Execution\s+Region\s+(\S+)\s+\(Base:\s+(\w+),\s+Size:\s+(\w+),\s+Max:\s+(\w+)/)
       {
#           print $_ ,  "\n";
           $ExecRegion{$1}->{'Base'} = $2;
           $ExecRegion{$1}->{'Size'} = $3;
           $ExecRegion{$1}->{'Max'} = $4;
           $ExecRegion{$1}->{'Seq'} = $ExecRegion_seq;
           $ExecRegion_seq++;
       }
    }
    close (LIS_HANDLE);
    &dump_temp_lis_structure();
    &error_handler($stop_build, "$LIS_TEMP: LIS file empty! Please resolve link errors first!", __FILE__, __LINE__) if (($LoadRegion_seq == 0) && ($ExecRegion_seq == 0));

    # 2.3 >>> parse key definition in ~flash_cfg_tmp.c
    open (FLASH_TMP_HANDLE, "<$FLASH_CFG_TMP") or &error_handler($stop_build, "$FLASH_CFG_TMP: file error!", __FILE__, __LINE__);
    while (<FLASH_TMP_HANDLE>) {
       if (/int\s+flash_base_address\s*=\s*(.+);/s)
              {
           my $flash_base_address = `perl -e "printf ($1)" 2>&1`;
                                       $FLASH_INFO{'FLASH_BASE_ADDRESS'} = sprintf("%X", $flash_base_address);
       }
       elsif (/int\s+allocated_fat_space\s*=\s*(.+);/s)
       {
           my $allocated_fat_space = `perl -e "printf ($1)" 2>&1`;
                                      $FLASH_INFO{'ALLOCATED_FAT_SPACE'} = sprintf("%X", $allocated_fat_space);
       }
    }
    close (FLASH_TMP_HANDLE);
    #&dump_flash_cfg_tmp_values();

    # 2.4 >>> check size limit validation
    my $flash_size  = &comp_flash_size();
    my $load_length = &comp_load_length();
    my ($ram_size, $ram_boundary, $ram_size_dummy_end, $ram_boundary_before_dummy_end);
    if ($MAKEFILE_OPTIONS{'platform'} ne 'MT6251')
    {
        $ram_size                      = &comp_ram_size();
        $ram_boundary                  = &comp_ram_boundary();
        $ram_size_dummy_end            = &comp_ram_size_dummy_end();
        $ram_boundary_before_dummy_end = &comp_ram_boundary_before_dummy_end($ram_size_dummy_end);
    }
    
    #printf "%x, %x, %x, %x\n", $flash_size, $ram_size, $load_length, $ram_boundary;
    
    if ((exists $MAKEFILE_OPTIONS{'nand_flash_booting'} and $MAKEFILE_OPTIONS{'nand_flash_booting'} ne 'NONE') or (exists $MAKEFILE_OPTIONS{'emmc_booting'} and $MAKEFILE_OPTIONS{'emmc_booting'} ne 'NONE'))
    {
        printf "LOAD VIEW , bypass check on NAND FLASH BOOTING\n";
        printf "EXEC VIEW , Physical Device Density 0x%x , Scatter File Configuration 0x%x , Scatter File DUMMY_END 0x%x , Scatter File Usage 0x%x\n",
                         $ram_size , $ram_boundary, $ram_size_dummy_end, $ram_boundary_before_dummy_end;
        if ($ram_size < $ram_boundary)
        {
            &error_handler($stop_build, "$SCATTERFILE: RAM consumption has exceeded its upper bound! Please turn off some features or change to a larger MCP!", __FILE__, __LINE__);
        }
        if ($ram_size_dummy_end < $ram_boundary_before_dummy_end)
        {
            &error_handler($stop_build, "$SCATTERFILE: RAM consumption has exceeded its upper bound! Please turn off some features or change to a larger MCP!", __FILE__, __LINE__);
        }
        if ($ram_size > $ram_boundary and ($ram_size - $ram_boundary) >= 1024 * 1024)
        {
            print "Warnning : RAM / Exec View configure waste at least 1MB\n";
        }
    }
    else
    {
        printf "LOAD VIEW , Physical Device Density 0x%x , Scatter File Configuration 0x%x\t%s\n",
                         $flash_size, $load_length, ($flash_size >= $load_length)? "PASS" : "ERROR";
        if ($flash_size < $load_length)
        {
            &error_handler($stop_build, "$SCATTERFILE: ROM consumption has exceeded its upper bound! Please turn off some features or change to a larger MCP!", __FILE__, __LINE__);
        }
        if (($MAKEFILE_OPTIONS{'platform'} ne 'MT6251'))
        {
            printf "EXEC VIEW , Physical Device Density 0x%x , Scatter File Configuration 0x%x , Scatter File DUMMY_END 0x%x , Scatter File Usage 0x%x\n",
                   $ram_size , $ram_boundary, $ram_size_dummy_end, $ram_boundary_before_dummy_end;
            if ($ram_size < $ram_boundary)
            {
                &error_handler($stop_build, "$SCATTERFILE: RAM consumption has exceeded its upper bound! Please turn off some features or change to a larger MCP!", __FILE__, __LINE__);
            }
            if ($ram_size_dummy_end < $ram_boundary_before_dummy_end)
            {
                &error_handler($stop_build, "$SCATTERFILE: RAM consumption has exceeded its upper bound! Please turn off some features or change to a larger MCP!", __FILE__, __LINE__);
            }
        }
        if ($flash_size > $load_length and ($flash_size - $load_length) >= 1024 * 1024)
        {
            print "Warnning : NOR flash / Load View configure waste at least 1MB\n";
        }
        if ($MAKEFILE_OPTIONS{'platform'} ne 'MT6251')
        {
            if ($ram_size > $ram_boundary and ($ram_size - $ram_boundary) >= 1024 * 1024)
            {
                print "Warnning : RAM / Exec View configure waste at least 1MB\n";
            }
        }
    }
}

#****************************************************************************
# subroutine:  SCHEME Configure Routines :: Query :: ARM9 Family
# input:       BB chip
# Output:      whether this chip belongs to ARM9 Family
#****************************************************************************
sub config_query_arm9
{
    my ($bb) = @_;
    my %BBtbl_ARM9_Family =
    (        
            'MT6235'  => 1,
            'MT6235B' => 1,
            'MT6238'  => 1,
            'MT6239'  => 1,
            'MT6268'  => 1,
    );
    return $BBtbl_ARM9_Family{$bb};
}

#****************************************************************************
# subroutine:  comp_flash_size
# return:      EMI value
#****************************************************************************
sub comp_flash_size
{
    my $flash_limit;
    if ((exists $MAKEFILE_OPTIONS{'nand_flash_booting'} and $MAKEFILE_OPTIONS{'nand_flash_booting'} ne 'NONE') or (exists $MAKEFILE_OPTIONS{'emmc_booting'} and $MAKEFILE_OPTIONS{'emmc_booting'} ne 'NONE'))
    {
        $flash_limit = 0;
    }
    elsif (exists $MAKEFILE_OPTIONS{'system_drive_on_nand'} and $MAKEFILE_OPTIONS{'system_drive_on_nand'} eq "TRUE")
    {
        $flash_limit = hex($FLASH_INFO{'NOR_FLASH_DENSITY'});
    }
    else
    {
        $flash_limit = hex($FLASH_INFO{'FLASH_BASE_ADDRESS'});
    }
    return $flash_limit;
}

#****************************************************************************
# subroutine:  comp_ram_size
# return:      EMI value
#****************************************************************************
sub comp_ram_size
{
    $EMI_H_Value{'EXTSRAM_SIZE'} =~ s/\(//;
    $EMI_H_Value{'EXTSRAM_SIZE'} =~ s/\)//;

    return $EMI_H_Value{'EXTSRAM_SIZE'} * 1024 * 1024 / 8;
}

#****************************************************************************
# subroutine:  comp_ram_size_dummy_end
# return:      RAM size before DUMMY_END or DSP_TXRX
#****************************************************************************
sub comp_ram_size_dummy_end
{
    my $extsram_ram_size_before_dummy_end;
    if    (exists $ExecRegion{'CODE_PATCH_CODE'})
    {
        $extsram_ram_size_before_dummy_end = hex($ExecRegion{'CODE_PATCH_CODE'}->{'Base'});
    }
    elsif (exists $ExecRegion{'CACHED_CODE_PATCH_CODE'})
    {
        $extsram_ram_size_before_dummy_end = hex($ExecRegion{'CACHED_CODE_PATCH_CODE'}->{'Base'});
    }
    elsif (exists $ExecRegion{'DUMMY_END'})
    {
        $extsram_ram_size_before_dummy_end = hex($ExecRegion{'DUMMY_END'}->{'Base'});
    }
    elsif (exists $ExecRegion{'CACHED_DUMMY_END'})
    {
        $extsram_ram_size_before_dummy_end = hex($ExecRegion{'CACHED_DUMMY_END'}->{'Base'});
    }
    elsif (exists $ExecRegion{'EXTSRAM_DSP_TX'})
    {
        $extsram_ram_size_before_dummy_end = hex($ExecRegion{'EXTSRAM_DSP_TX'}->{'Base'});
    }
    elsif (exists $ExecRegion{'SECONDARY_EXTSRAM_DSP_TX'})
    {
        $extsram_ram_size_before_dummy_end = hex($ExecRegion{'SECONDARY_EXTSRAM_DSP_TX'}->{'Base'});
    }
    else
    {
        die "Unknown Scatter File Structure";
    }
    
    printf "RAM DUMMY END , %x\n" , $extsram_ram_size_before_dummy_end;
    
    return $extsram_ram_size_before_dummy_end;
}

#****************************************************************************
# subroutine:  comp_load_length
# return:      LoadView
#****************************************************************************
sub comp_load_length
{
    my @region_list = sort { hex($LoadRegion{$b}->{'Base'}) <=> hex($LoadRegion{$a}->{'Base'}) } keys %LoadRegion;
    my $last_load_region;
    for (0..$#region_list)
    {
        if (($region_list[$_] ne 'SECURE_RO_ME') and ($region_list[$_] ne 'SECURE_RO_S'))
        {
            $last_load_region = $region_list[$_];
            last;
        }
    }
    return ((hex($LoadRegion{$last_load_region}->{'Base'})+hex($LoadRegion{$last_load_region}->{'Size'})) & (~0xF8000000));
}

#****************************************************************************
# subroutine:  get_regions_reside_EXTSRAM
#****************************************************************************
sub get_regions_reside_EXTSRAM
{
    my @regions = (sort { hex($ExecRegion{$a}->{'Base'}) <=> hex($ExecRegion{$b}->{'Base'}) } keys %ExecRegion);
    my $EXTSRAM_Addr;

    for (my $i=0; $i <= $#regions; $i++)
    {
        if ($regions[$i] =~ /EXTSRAM/) # find the start of EXTSRAM
        {
            $EXTSRAM_Addr = $ExecRegion{$regions[$i]}->{'Base'};
        }
    }
    @regions = grep { (hex($ExecRegion{$_}->{'Base'}) & 0xF8000000) == (hex($EXTSRAM_Addr) & 0xF8000000) } keys %ExecRegion;

    return @regions;
}

#****************************************************************************
# subroutine:  comp_ram_boundary
# return:      LoadView
#****************************************************************************
sub comp_ram_boundary
{
    my @regions1  = sort { hex($ExecRegion{$a}->{'Base'}) <=> hex($ExecRegion{$b}->{'Base'}) } &get_regions_reside_EXTSRAM();

    my $extsram_baseaddr = hex($ExecRegion{ $regions1[0] }->{ 'Base' });
    #
    my $extsram_limitaddr;
    if    (exists $ExecRegion{'DUMMY_END'})
    {
        $extsram_limitaddr = hex($ExecRegion{'DUMMY_END'}->{'Base'});
    }
    elsif (exists $ExecRegion{'EXTSRAM_DSP_RX'})
    {
        $extsram_limitaddr = hex($ExecRegion{'EXTSRAM_DSP_RX'}->{'Base'}) + hex($ExecRegion{'EXTSRAM_DSP_RX'}->{'Size'});
    }
    elsif (exists $ExecRegion{'SECONDARY_EXTSRAM_DSP_RX'})
    {
        $extsram_limitaddr = hex($ExecRegion{'SECONDARY_EXTSRAM_DSP_RX'}->{'Base'}) + hex($ExecRegion{'SECONDARY_EXTSRAM_DSP_RX'}->{'Size'});
    }
    elsif (exists $ExecRegion{'CODE_PATCH_CODE'})
    {
        $extsram_limitaddr = hex($ExecRegion{'CODE_PATCH_CODE'}->{'Base'}) + hex($ExecRegion{'CODE_PATCH_CODE'}->{'Size'});
    }
    elsif (exists $ExecRegion{'CACHED_DUMMY_END'})
    {
        $extsram_limitaddr = hex($ExecRegion{'CACHED_DUMMY_END'}->{'Base'}) & (~0xf0000000);
    }
    elsif (exists $ExecRegion{'EXTSRAM'} and exists $ExecRegion{'EXTSRAM'}->{'Size'})
    {
        $extsram_limitaddr = hex($ExecRegion{'EXTSRAM'}->{'Base'}) + hex($ExecRegion{'EXTSRAM'}->{'Size'});
    }
    elsif (exists $ExecRegion{'SECONDARY_EXTSRAM'} and exists $ExecRegion{'SECONDARY_EXTSRAM'}->{'Size'})
    {
        $extsram_limitaddr = hex($ExecRegion{'SECONDARY_EXTSRAM'}->{'Base'}) + hex($ExecRegion{'SECONDARY_EXTSRAM'}->{'Size'});
    }
    else
    {
        die "Unknown Scatter File Structure";
    }
    
    #printf "RAM %x , %x\n" , $extsram_baseaddr , $extsram_limitaddr;
    
    return ($extsram_limitaddr & (~0xf8000000));
}

#****************************************************************************
# subroutine:  comp_ram_boundary_before_dummy_end
# return:      RAM boundary before DUMMY_END
#****************************************************************************
sub comp_ram_boundary_before_dummy_end
{
	   my ($ram_dummy_end) = @_;
    my @regions1  = sort { hex($ExecRegion{$b}->{'Seq'}) <=> hex($ExecRegion{$a}->{'Seq'}) } &get_regions_reside_EXTSRAM();

    #
    my $extsram_limitaddr;
    my $dummy_end_reached = 0;
    foreach my $region (@regions1)
    {
    	   if ($dummy_end_reached == 1)
    	   {
    	   	   $extsram_limitaddr = hex($ExecRegion{$region}->{'Base'}) + hex($ExecRegion{$region}->{'Size'});
    	   	   last;
    	   }
    	   if (hex($ExecRegion{$region}->{'Base'}) == $ram_dummy_end)
    	   {
    	   	   $dummy_end_reached = 1;
    	   }
    }

    printf "RAM Limit before DUMMY_END , %x\n" , $extsram_limitaddr;
 
    return $extsram_limitaddr;
}

#****************************************************************************
# subroutine:  get_block_table
# return:      block table hash
#****************************************************************************
sub get_block_table
{
    if ($#FLASH_H_Value_BLK_LIST >= 0)
    {
        my %blk_href;

        foreach(@FLASH_H_Value_BLK_LIST)
        {
            if (/\{(0x\w+),\s*(0x\w+)\}/)
            {
                $NORFLASH_INFO_BLOCKS_TABLE{hex($1)} = hex($2);
            }
        }
    }
}

#****************************************************************************
# subroutine:  dump_exec_view
# return:      all %LoadView ; key = RegionName , value = hash ref , begin , attr , length
#****************************************************************************
sub dump_exec_view
{
    print "=== EXEC VIEW ===\n";
    foreach my $region_name (sort { $ExecView{$a}->{'seq'} <=> $ExecView{$b}->{'seq'} } keys %ExecView)
    {
        print $region_name, "\t", $ExecView{$region_name}->{'begin'}, "\n";
    }
}

#****************************************************************************
# subroutine:  dump_load_view
# return:      all %LoadView ; key = RegionName , value = hash ref , begin , attr , length
#****************************************************************************
sub dump_load_view
{
    print "=== LOAD VIEW ===\n";
    foreach my $region_name (sort { $LoadView{$a}->{'seq'} <=> $LoadView{$b}->{'seq'} } keys %LoadView)
    {
        print $region_name, "\t", $LoadView{$region_name}->{'begin'}, "\n";
    }
}

#****************************************************************************
# subroutine:  parse_region_string
# input:       reference to %LoadView or %ExecView ; Region Name start address string
# return:      %LoadView ; key = RegionName , value = hash ref , begin , attr , length
#****************************************************************************
my $sequence = 0;
sub parse_region_string
{
    my ($hash_ref, $string) = @_;
    my %tmp;

    if    ($string =~ m/(\S+)\s+(\S+)\s+OVERLAY\s+(\S+)/)
    {
        #print 'PATTERN1', "\t", $1, "\t", $2, "\t", 'OVERLAY', "\t", $3 , "\n";
        $tmp{'seq'}     = ++$sequence;
        $tmp{'attr'}    = "OVERLAY";
        $tmp{'begin'}   = $2;
        $tmp{'length'}  = $3;
        $hash_ref->{$1} = \%tmp;
    }
    elsif    ($string =~ m/(\S+)\s+(\S+)\s+ABSOLUTE\s+(\S+)/)
    {
        #print 'PATTERN1', "\t", $1, "\t", $2, "\t", 'ABSOLUTE', "\t", $3 , "\n";
        $tmp{'seq'}     = ++$sequence;
        $tmp{'attr'}    = "ABSOLUTE";
        $tmp{'begin'}   = $2;
        $tmp{'length'}  = $3;
        $hash_ref->{$1} = \%tmp;
    }
    elsif ($string =~ m/(\S+)\s+(\S+)\s+FIXED\s+(\S+)/)
    {
        #print 'PATTERN1', "\t", $1, "\t", $2, "\t", 'FIXED', "\t", $3, "\n";
        $tmp{'seq'}     = ++$sequence;
        $tmp{'attr'}    = "FIXED";
        $tmp{'begin'}   = $2;
        $tmp{'length'}  = $3;
        $hash_ref->{$1} = \%tmp;
    }
    elsif ($string =~ m/(\S+)\s+(\S+)\s+(\S+)/)
    {
        #print 'PATTERN3', "\t", $1, "\t", $2, "\t", $3, "\n";
        $tmp{'seq'}     = ++$sequence;
        $tmp{'begin'}   = $2;
        $tmp{'length'}  = $3;
        $hash_ref->{$1} = \%tmp;
    }
    elsif ($string =~ m/(\S+)\s+(\S+)/)
    {
        #print 'PATTERN4', "\t", $1, "\t", $2, "\n";
        $tmp{'seq'}     = ++$sequence;
        $tmp{'begin'}   = $2;
        $hash_ref->{$1} = \%tmp;
    }
    else
    {
        warn "UNKNOWN PATTERN : $string";
    }
}

#****************************************************************************
# subroutine:  parse_scatter_file_structure
# return:      %LoadView , %ExecView
#****************************************************************************
sub parse_scatter_file_structure
{
    my $last_line_no;
    my $text_line;
    my $view=0;  #counter , 1 = load view , 2 = exec view
    foreach my $file_line_no (sort {$a <=> $b} keys %Scat_Content)
    {
        $text_line = $Scat_Content{$file_line_no};
        if    ($text_line =~ m/{/)
        {
            if ($view > 1)
            {
                &error_handler($stop_build, "$SCATTERFILE: Unrecognizable view at $file_line_no! Please contact with Scatter File owner!", __FILE__, __LINE__);
            }
            $view++;
            if (not defined $last_line_no)
            {
                &error_handler($stop_build, "$SCATTERFILE: No region name detected before $file_line_no!Please contact with Scatter File owner!", __FILE__, __LINE__);
            }
            &parse_region_string( ($view == 1) ? \%LoadView : \%ExecView , $Scat_Content{$last_line_no} );
        }
        elsif ($text_line =~ m/}/)
        { 
            $view--;
            if ($view < 0)
            {
                &error_handler($stop_build, "$SCATTERFILE: Unrecognizable view at $file_line_no!Please contact with Scatter File owner!", __FILE__, __LINE__);
            }
        }
        $last_line_no = $file_line_no;
    }
}

#****************************************************************************
# subroutine:  error_handler
# return:      none
#****************************************************************************
sub error_handler
{
    my ($todie, $error_msg, $file, $line_no) = @_;
 
#    print $todie, "\n";

    my $final_error_msg = "CKSCATTER ERROR: $error_msg at $file line $line_no\n";
    print $final_error_msg;
    die $final_error_msg if ($todie eq 'TRUE');
}

#****************************************************************************
# subroutine:  dump_scatter_file_structure
# return:      none
#****************************************************************************
sub dump_scatter_file_structure
{
    foreach my $file_line_no (sort {$a <=> $b} keys %Scat_Content)
    {
        print $file_line_no, "\t", $Scat_Content{$file_line_no};
    }
}

#****************************************************************************
# subroutine:  dump_temp_lis_structure
# return:      none
#****************************************************************************
sub dump_temp_lis_structure
{
    print "Dumping temp lis structure: \n";
    foreach my $lv (sort {hex($LoadRegion{$a}->{'Base'}) <=> hex($LoadRegion{$a}->{'Base'})} keys %LoadRegion)
    {
        print $lv, "\t", $LoadRegion{$lv}->{'Base'}, "\t", $LoadRegion{$lv}->{'Size'}, "\t", $LoadRegion{$lv}->{'Max'}, "\t", $LoadRegion{$lv}->{'Seq'}, "\n";
    }
    foreach my $ev (sort {hex($ExecRegion{$a}->{'Base'}) <=> hex($ExecRegion{$a}->{'Base'})} keys %ExecRegion)
    {
        print $ev, "\t", $ExecRegion{$ev}->{'Base'}, "\t", $ExecRegion{$ev}->{'Size'}, "\t", $ExecRegion{$ev}->{'Max'}, "\t", $ExecRegion{$ev}->{'Seq'}, "\n";
    }
}

#****************************************************************************
# subroutine:  dump_custom_emi_h_values
# return:      none
#****************************************************************************
sub dump_custom_emi_h_values
{
    foreach my $key (sort keys %EMI_H_Value)
    {
        print $key, "\t", $EMI_H_Value{$key} , "\n";
    }
}

#****************************************************************************
# subroutine:  dump_custom_flash_h_values
# return:      none
#****************************************************************************
sub dump_custom_flash_h_values
{
    foreach (@FLASH_H_Value_BLK_LIST)
    {
        print "$_\n";
    }
}

#****************************************************************************
# subroutine:  dump_flash_cfg_tmp_values
# return:      none
#****************************************************************************
sub dump_flash_cfg_tmp_values
{
    foreach my $key (sort keys %FLASH_INFO)
    {
        print $key, "\t", $FLASH_INFO{$key} , "\n";
    }
}

