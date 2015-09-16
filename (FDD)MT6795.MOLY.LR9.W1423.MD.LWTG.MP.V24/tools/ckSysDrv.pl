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
#
#*****************************************************************************
#*
#* Filename:
#* ---------
#*   ckSysDrv.pl
#*
#* Project:
#* --------
#*   Maui_Software
#*
#* Description:
#* ------------
#*   This script parse prepocessed fs_quota.c and nvram_user_config.c to
#*       1. check if system drive space is enough
#*       2. display current flash usage
#*
#* Author:
#* -------
#*   Sherman Wang  (mtk00590)
#*
#*============================================================================
#*             HISTORY
#* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*------------------------------------------------------------------------------
#* $Revision:  $
#* $Modtime: $
#* $Log: $
#*
#*
#*------------------------------------------------------------------------------
#* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*============================================================================
#****************************************************************************/

#****************************************************************************
# Included Modules
#****************************************************************************
BEGIN { push @INC, './tools/' }  # add additional library path             
use strict;
use Getopt::Std;
use POSIX;
use auto_adjust_mem;               # pm file name without case sensitivity
use constant OWNER        => "mtk02704";

#****************************************************************************
# Constants
#****************************************************************************
my $DebugPrint = 0;
# 0001(1)
# 0010(2)
# 0100(4): NVRAM/Quota handling details
# 1000(8): NVRAM/Quota 

#****************************************************************************
# Usage
#****************************************************************************
sub usage
{
    print "perl ckSysDrv.pl <Preprocessed fs_quota.c> <Preprocessed nvram_user_config.c>\n";
    exit(0);
}

#****************************************************************************
# parsing command arguments
#****************************************************************************
my %option = ();
if (!getopts('hdc:', \%option) or $option{'h'})
{
    &usage;
    exit(0);
}
$DebugPrint = 1 if $option{'d'};

my $FLASH_CFG            = $ARGV[0]; 
my $FS_STAT              = $ARGV[1];
my $NVRAM_STAT           = $ARGV[2];
my $FEATURE_OVERLOAD     = $ARGV[3];
my $SYSTEM_DRIVE_ON_NAND = $ARGV[4];
my $NVRAM_PSEUDO_MERGE   = $ARGV[5];
my $BOARD_FOLDER         = $ARGV[6];
my $LINK_INFO            = $ARGV[7];
my $PROJECT              = $ARGV[8];
my $AAPMCLOG             = $ARGV[9];
 
my %cluster_multiple = ();

print "[CkSysDrv] Starting...\n" if ($DebugPrint & 1);
print "[CkSysDrv] ARGV# = $#ARGV\n" if($DebugPrint & 1);
my $j = 0;
my %arguments = (
    0 => "\$FLASH_CFG",
    1 => "\$FS_STAT",
    2 => "\$NVRAM_STAT",
    3 => "\$FEATURE_OVERLOAD",
    4 => "\$SYSTEM_DRIVE_ON_NAND",
    5 => "\$NVRAM_PSEUDO_MERGE",
    6 => "\$BOARD_FOLDER",
    7 => "\$LINK_INFO",
    8 => "\$PROJECT",
    9 => "\$AAPMCLOG",
);
for (; $j < $#ARGV + 1 ; $j++) 
{
    printf("\t\t\$ARGV[$j]: $arguments{$j} = %s\n", $ARGV[$j]) if($DebugPrint & 1);
}

#****************************************************************************
# Parse preprocessed custom_MemoryDevice.h and custom_EMI.h
#****************************************************************************
open(FLASH_CFG, "<$FLASH_CFG") or cksysdrv_die(ERR::ERR_UNEXPECTED,  "cannot open FLASH_CFG: $FLASH_CFG\n", __FILE__, __LINE__);

my $backup = $/;
undef $/;
my $reading = <FLASH_CFG>;
close FLASH_CFG;

# common variables
my $fs_auto_config_support;
my $allocated_fat_space;    # in Byte
my $first_partition_sectors;   # in Sector
my $first_partition_size;   # in Byte
my $system_drive_sectors;      # in Sector
my $system_drive_size;      # in Byte
my $flash_base_address;
my $system_drive_location;
    my $ON_NAND = 1;
    my $ON_NOR  = 2;
    my $ON_EMMC = 3;
my $app_storage_in_sys_drv;

my $original_base_address;
my $original_fat_space;
my $original_first_partition_sectors;
    
my $free_space = -1;
my $cksysdrv_enabled;
my $DEV_PREFIX; # prefix of macros in custom_MemoryDevice.h
my $DEV_TYPE;   # memory type of debug info

# NOR flash specific variables
my $fs_low_cost_support;
my $nvram_custom_cfg_max_record_sector_num;
my $nor_regions;
my $nor_reserved_blocks;
my $nor_single_bank_support = 0;
my $nor_sector_size;
my $nor_max_blk_size                   = 0;    # in Byte
my $nor_drive_overhead                 = 0;    # in Byte
my $blockheader_overhead			   = 0;
my $blockheader_overhead_total         = 0;
my $nor_min_reserved_blocks            = 2;
my $nor_extra_reserved_space           = 0;
my $nor_extra_reserved_space_for_power_loss           = 0;
my $nor_protection_mode_reserved_space = 0;

# NAND flash specific variables
my $nand_block_size;                           # KB
my $fat_nand_block_num;
my $nand_log_block_num;
my $fat_nand_region_num;
my $nand_fdm_version;

#
my $code_boundary_addr=0;       #in Byte
    my $release_all_free = -1;  #flag
my $alignment;                  #in Byte
my $code_shortage_size;
my $short_block;
my $short_block_size;
my $diff;
my $cluster_size;  # in Byte

# log
my @log_buf = ();
my %error_code = (
    ERR::NO_MODIFY            => "ERR::NO_MODIFY",
    ERR::MODIFY_SUCCESS       => "ERR::MODIFY_SUCCESS",
    ERR::CANNOT_ADJUST        => "ERR::CANNOT_ADJUST",
    ERR::AAPMCLOG_SUCCESS     => "ERR::AAPMCLOG_SUCCESS",
    ERR::ERR_MODIFYFAIL       => "ERR::ERR_MODIFYFAIL",
    ERR::ERR_UNEXPECTED       => "ERR::ERR_UNEXPECTED",
    ERR::ERR_MODIFYDUPLICATED => "ERR::ERR_MODIFYDUPLICATED",
);

print "[CkSysDrv] Read common configurations...\n" if ($DebugPrint &1);

#---------------------------------------------------
# Read common variables
#---------------------------------------------------

# macth   int cksysdrv_enabled = 0 ;
if ($reading =~ /int\s+cksysdrv_enabled\s*=\s*(.*);/)
{
    $cksysdrv_enabled = `perl -e "print ($1)" 2>&1`;

    if ($cksysdrv_enabled == 0)
    {
        print "[ckSysDrv] ckSysDrv is disabled!";

        exit(0);
    }
}

# macth   int fs_auto_config_support = 0 ;
if ($reading =~ /int\s+fs_auto_config_support\s*=\s*(.*);/)
{
    $fs_auto_config_support = `perl -e "print ($1)" 2>&1`;

    if ($fs_auto_config_support == 0)
    {
        print "[ckSysDrv] Auto adjust is disabled!\n";
    }
    
    if ($#ARGV < 6)
    {
        $fs_auto_config_support = 0;
    }
        print "[ckSysDrv] \$fs_auto_config_support = $fs_auto_config_support\n"; 
}



# macth   int system_drive_location = 0 ;
if ($reading =~ /int\s+system_drive_location\s*=\s*(.*);/)
{
    $system_drive_location = `perl -e "print ($1)" 2>&1`;
    if ($system_drive_location == $ON_NOR)
    {
        print("[Input] System Drive Type                      = NOR\n")if ($DebugPrint &1);
        $DEV_PREFIX = "NOR_BOOTING_NOR_";
        $DEV_TYPE = "NOR";
    }
    elsif ($system_drive_location == $ON_NAND)
    {
        print("[Input] System Drive Type = NAND\n")if ($DebugPrint &1);
        $DEV_PREFIX = "NAND_BOOTING_NAND_";
        $DEV_TYPE = "NAND";
    }
    elsif ($system_drive_location == $ON_EMMC)
    {
        print("[Input] System Drive Type = EMMC\n")if ($DebugPrint &1);
        $DEV_PREFIX = "EMMC_BOOTING_UP_";
        $DEV_TYPE = "EMMC";
    }
    else
    {
        cksysdrv_die(ERR::ERR_UNEXPECTED, "System drive location is unrecoginzed!", __FILE__, __LINE__);
    }


}
else
{
    cksysdrv_die(ERR::ERR_UNEXPECTED, "System drive location is unrecoginzed!", __FILE__, __LINE__);
}

#match APP_STORAGE_IN_SYS_DRV
if ($reading =~ /int\s+app_storage_in_sys_drv\s*=\s*(.*);/)
{
    $app_storage_in_sys_drv = `perl -e "print ($1)" 2>&1`;
    printf("\t[Input] APP_STORAGE_IN_SYS_DRV: $app_storage_in_sys_drv\n") if ($DebugPrint &1);
}

if ($system_drive_location == $ON_NOR || $system_drive_location == $ON_NAND) 
{
    # macth   int flash_base_address =  0x00E00000 ;
    if ($reading =~ /int\s+flash_base_address\s*=\s*(.*);/)
    {
        $flash_base_address = `perl -e "print ($1)" 2>&1`;
        $original_base_address = $flash_base_address;
        printf("[Input] %sFS_BASE_ADDRESS        = 0x%08X\n", $DEV_PREFIX, $flash_base_address)if ($DebugPrint &1);
    }
    else
    {
        cksysdrv_die(ERR::ERR_UNEXPECTED, "FS base address is NOT found!", __FILE__, __LINE__);
    }

    # macth   int allocated_fat_space =  0x00200000 ;
    if ($reading =~ /int\s+allocated_fat_space\s*=\s*(.*);/)
    {
        $allocated_fat_space = `perl -e "print ($1)" 2>&1`;
        $original_fat_space = $allocated_fat_space;
        printf("[Input] %sFS_SIZE                = 0x%08X\n", $DEV_PREFIX, $allocated_fat_space)if ($DebugPrint &1);
    }
    else
    {
        cksysdrv_die(ERR::ERR_UNEXPECTED,  "FS total size is NOT found!", __FILE__, __LINE__);
    }

    # macth   int partition_sectors =  0 ;
    if ($reading =~ /int\s+partition_sectors\s*=\s*(.*);/)
    {
        $first_partition_sectors = `perl -e "print ($1)" 2>&1`;
        $original_first_partition_sectors = $first_partition_sectors;
        $first_partition_size = $first_partition_sectors * 512;
        printf("[Input] %sFS_FIRST_DRIVE_SECTORS = %d sectors(0x%08X bytes)\n", $DEV_PREFIX, $first_partition_sectors, $first_partition_size)if ($DebugPrint &1);
    }
    else
    {
        
        cksysdrv_die(ERR::ERR_UNEXPECTED,  "The first drive size is NOT found!", __FILE__, __LINE__);
    }
}
elsif ($system_drive_location == $ON_EMMC)    # EMMC booting
{
    # macth   int system_drive_size =  0 ;
    if ($reading =~ /int\s+system_drive_size\s*=\s*(.*);/)
    {
        $system_drive_sectors = `perl -e "print ($1)" 2>&1`;
        $system_drive_size = $system_drive_sectors * 512;
        printf("[Input] %sFS_SIZE = %d sectors(0x%08X bytes)\n", $DEV_PREFIX, $system_drive_sectors, $allocated_fat_space)if ($DebugPrint &1);
    }
    else
    {
        cksysdrv_die(ERR::ERR_UNEXPECTED,  "[EMMC Booting] System drive size is NOT found!", __FILE__, __LINE__);
    }
}
else
{
    cksysdrv_die(ERR::ERR_UNEXPECTED,  "Unrecognizable device type", __FILE__, __LINE__);
}

print "\n[$DEV_TYPE] Read device specific configurations \n" if ($DebugPrint &1);
if ($system_drive_location == $ON_NAND)    # System drive on NAND flash
{

    #---------------------------------------------------
    # NAND flash
    #---------------------------------------------------

    #print "(NAND)...\n" if ($DebugPrint &1);

    # macth   int nand_fdm_version = 0;
    if ($reading =~ /int\s+nand_fdm_version\s*=\s*(.*);/)
    {
        $nand_fdm_version = `perl -e "print ($1)" 2>&1`;    # 4 or 5
        printf("\tFDM version: %d\n", $nand_fdm_version) if ($DebugPrint &1);
    }
    else
    {
        cksysdrv_die(ERR::ERR_UNEXPECTED,  "NAND FDM version is NOT found!", __FILE__, __LINE__);
    }

    if ($nand_fdm_version != 4 && $nand_fdm_version != 5)
    {
        cksysdrv_die(ERR::ERR_UNEXPECTED,  "Unsupported NAND FDM version!", __FILE__, __LINE__);
    }

    # macth   int nand_block_size = 0;
    if ($reading =~ /int\s+nand_block_size\s*=\s*(.*);/)
    {
        $nand_block_size = `perl -e "print ($1)" 2>&1`;    # (KB)
        printf("[CkSysDrv:NAND] Block size: %d (KB)\n", $nand_block_size) if ($DebugPrint &1);
    }
    else
    {
        cksysdrv_die(ERR::ERR_UNEXPECTED,  "NAND block size is NOT found!", __FILE__, __LINE__);
    }
}
elsif ($system_drive_location == $ON_NOR)    # System drive on NOR flash
{

    #------------------------------------------------------------
    # NOR flash
    #------------------------------------------------------------

    #print "(NOR)...\n";

    # macth   int fs_low_cost_support =  0 ;
    if ($reading =~ /int\s+fs_low_cost_support\s*=\s*(.*);/)
    {
        $fs_low_cost_support = `perl -e "print ($1)" 2>&1`;
        printf("\tUltra-low-cost support: %d\n", $fs_low_cost_support) if ($DebugPrint &1);
    }
    else
    {
        warn "[CkSysDrv:NOR] Ultra-low-cost indication is NOT found!";
        undef $fs_low_cost_support;
    }

    # macth   int nvram_custom_cfg_max_record_size = 4 ;
    if ($reading =~ /int\s+nvram_custom_cfg_max_record_sector_num\s*=\s*(.*);/)
    {
        $nvram_custom_cfg_max_record_sector_num = `perl -e "print ($1)" 2>&1`;
        printf("\tNVRAM maximum record size: %d\n", $nvram_custom_cfg_max_record_sector_num) if ($DebugPrint &1);
    }
    else
    {
        
        cksysdrv_die(ERR::ERR_UNEXPECTED,  
            "NVRAM_CUSTOM_CFG_MAX_RECORD_SECTOR_NUM is NOT defined! It should be defined in custom\\common\\custom_nvram_config.h", __FILE__, __LINE__);
    }

    # match   {float,int} nor_reserved_blocks = {1.5,5} ;
    if ($reading =~ /int\s+nor_reserved_blocks\s*=\s*(.*);/)
    {
        $nor_reserved_blocks = `perl -e "print ($1)" 2>&1`;
        printf("\tNOR FDM reserved blocks: %d\n", $nor_reserved_blocks) if ($DebugPrint &1);
    }
    elsif ($reading =~ /float\s+nor_reserved_blocks\s*=\s*(.*);/)
    {
        $nor_reserved_blocks = `perl -e "print ($1)" 2>&1`;
        printf("\tNOR FDM reserved blocks: %.2f\n", $nor_reserved_blocks) if ($DebugPrint &1);
    }
    else
    {
        cksysdrv_die(ERR::ERR_UNEXPECTED,  "RESERVED BLOCKS is NOT found!", __FILE__, __LINE__);
    }

    # match   int nor_single_bank_support = {1,0} ;
    if ($reading =~ /int\s+nor_single_bank_support\s*=\s*(.*);/)
    {
        $nor_single_bank_support = `perl -e "print ($1)" 2>&1`;
    }
    
    # match   int nor_sector_size = 512 ;
    if ($reading =~ /int\s+nor_sector_size\s*=\s*(.*);/)
    {
        $nor_sector_size = `perl -e "print ($1)" 2>&1`;
        printf("\tSector size: %d (Bytes)\n", $nor_sector_size) if ($DebugPrint &1);
    }
    else
    {
        cksysdrv_die(ERR::ERR_UNEXPECTED, "SECTOR SIZE is NOT found!\n", __FILE__, __LINE__);
    }

    # macth  FlashRegionInfo RegionInfo[] =
    #        {
    #           {0x20000, 16},
    #           EndRegionInfo
    #        };
    if ($reading =~ /\s+RegionInfo\s*?\[\s*?\]\s*?=\s*?\{([\w\W]+?)\s*?\{0, 0\}\s*?\}\s*?;/)
    {
        $nor_regions = $1;
    }
    else
    {
        cksysdrv_die(ERR::ERR_UNEXPECTED,  "RegionInfo is NOT found!\n", __FILE__, __LINE__);
    }

    # match {0x20000, 16},
    while ($nor_regions =~ /\{\s*(0x[\dA-Fa-f]+)\s*,\s*(\d+)\s*\}\s*,/)
    {
        my $sectors_per_block;

        $nor_regions = $';

        if ($nor_sector_size == 512)
        {
            $blockheader_overhead = 512;
            $sectors_per_block    = (hex($1) - $blockheader_overhead) / 512;
            while ((($sectors_per_block + 1) * 4) > $blockheader_overhead)
            {
                $blockheader_overhead += 512;
                $sectors_per_block--;
            }
            printf("\t\t[i]sectors_per_block                       = $sectors_per_block\n")if ($DebugPrint & 2);
        }
        elsif ($nor_sector_size == 1024)
        {
            $blockheader_overhead = 2048;
            printf("\t\t[i]sectors_per_block                       = $sectors_per_block\n")if ($DebugPrint & 2);
        }

        $alignment = hex($1);
        printf("\t\t[i]alignment                               = $alignment\n")if ($DebugPrint & 2);

        $nor_max_blk_size = hex($1) - $blockheader_overhead if ($nor_max_blk_size < hex($1) - $blockheader_overhead);
        printf("\t\t[i]nor_max_blk_size                        = $nor_max_blk_size\n")if ($DebugPrint & 2);

        $blockheader_overhead_total = $blockheader_overhead * $2;
        printf("\t\t[i]blockheader_overhead                    = $blockheader_overhead\n")if ($DebugPrint & 2);

    }

}


if ($fs_auto_config_support == 1)
{
    # match code_boundary_addr
    printf ("Parsing $LINK_INFO\n") if ($DebugPrint &1);
    open(LINK_INFO, "<$LINK_INFO") or warn "cannot open LINK_INFO: $LINK_INFO\n";
    while (<LINK_INFO>)
    {
        printf("\t\t[i]%s\n", $_) if ($DebugPrint &1);

        if ($system_drive_location == $ON_NOR)
        {

            #multi-bank, we can't adjust because FS addr. must align bank.
            if ($nor_single_bank_support == 0)
            {
                cksysdrv_die(ERR::CANNOT_ADJUST,  "Can't adjust FS base address because of multibank! Please consider turning on ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT\n", __FILE__, __LINE__);
            }
            
            #this is temp solution, because don't know how big is code region when multi-bin
                # release all freespace once the link error doesn't include key word: EXTSRAM, INTSRAM, CACHED and PAGE_TABLE
                
            if (/L6220E:\s*Load\s*region\s*(.*)\s*size/)
            {
                printf("Link error: Load region = $1\n")if ($DebugPrint &1);
                if ($1 =~ /(EXTSRAM|INTSRAM|CACHED|PAGE_TABLE)/)
                {
                    printf("\tFalse alarm\n")if ($DebugPrint &1);    
                }
                else
                {
                    $code_boundary_addr = $release_all_free; #free all free space to code region
                    printf("\tRelease all free space\n")if ($DebugPrint &1);
                }
            }

            # correct soultion is to calc all shortage, 
            # e.g. Error: L6220E: Load region ROM size (54932988 bytes) exceeds limit (1048576 bytes).
            # if(/L6220E:\s*Load\s*region\s*ROM\s*size\s*\((.*)\s*bytes\)\s+exceeds\s+limit/)
            # {
            #    $code_boundary_addr = $1;
            # }


        }
        elsif ($system_drive_location == $ON_NAND || $system_drive_location == $ON_EMMC)
        {

            #match Error: BIN (413.52 blocks) and FAT (400 blocks) on NAND Flash overlap risk were detected.
            if(/Error:\s*BIN\s*\((.*)\s*blocks\)\s*and\s*FAT\s*\((.*)\s*blocks\)/)
            {
                $code_boundary_addr = ($1 + 1) * $nand_block_size * 1024;
                printf("Link error: Load region = $1 blocks\n")if ($DebugPrint &1);
            }

            if (/BIN\s*size\s*=\((.*)\s*blocks\)\s*on\s*NAND\s*Flash/)
            {
                $code_boundary_addr = $1;
                printf("Load region = $1 blocks\n")if ($DebugPrint &1);
            }
           
        }
    }

    close LINK_INFO;

    my $i = 0;
    for (; $i < 10 ; $i++) 
    {
        my $err_level_1 = calc_func();
        print "\n\n[ckSysdrv result] $error_code{$err_level_1}($err_level_1)\n";
        if ($err_level_1 == ERR::NO_MODIFY)
        {
            my $err_level_2 = adjust_func();
            
            print "\n\n[AAPMC result] $error_code{$err_level_2}($err_level_2)\n";
            exit $err_level_2;
        }
        elsif ($err_level_1 == ERR::MODIFY_SUCCESS)
        {
            print "\n\n[Retrying...]\n";
        }
        else
        {
            exit $err_level_1;
        }
            
    }
    if ($i == 10)
    {
        if ($code_shortage_size > 0)
        {
            printf("Error: Shortage of code region (bytes, sectors) = (0x%08X, %d)\n", $code_shortage_size, $code_shortage_size/512);
        }
        elsif ($diff >= 0)
        {
            printf("Error: Shortage of FAT region: %d clusters (%d Sectors = %.1f KB = %.2f MB)\n", $diff, $diff * ($cluster_size / 512), $diff * $cluster_size / 1024, $diff * $cluster_size / (1024 * 1024));
        }
        cksysdrv_die(ERR::CANNOT_ADJUST,  "Can't find an available setting. Check ckSysDrv.log for detail!\n", __FILE__, __LINE__);
    }
}
else
{
    calc_func();

    if ($code_shortage_size > 0)
    {
        printf("Error: Shortage of code region (bytes, sectors) = (0x%08X, %d)\n", $code_shortage_size, $code_shortage_size/512);
        exit ERR::ERR_UNEXPECTED;
    }
    elsif ($diff < 0)
    {
        printf("Error: Shortage of FAT region: %d clusters (%d Sectors = %.1f KB = %.2f MB)\n", -1*$diff, -1*$diff * ($cluster_size / 512), 1*$diff * $cluster_size / 1024, 1*$diff * $cluster_size / (1024 * 1024));
        exit ERR::ERR_UNEXPECTED;
    }

    cksysdrv_die(ERR::NO_MODIFY,  "Auto config is OFF this time!\n", __FILE__, __LINE__);
}

#---------------------------------------------------------
# Read device specific variables and calculate free space
#---------------------------------------------------------
sub calc_func
{
    if ($system_drive_location == $ON_NAND)    # System drive on NAND flash
    {

        print "[CkSysDrv:NAND] Calculate free space...\n" if ($DebugPrint &1);

        if ($nand_block_size != 0)
        {
            if ($nand_fdm_version == 4)
            {

                #----------------------------------------------------------
                # 12 : Reserved blocks in each region.
                # 5 : Max possible bad blocks number in each region. (2%)
                # Log_Block_Number : Number of log blocks. In 2KB NAND, the value is 3. In 528B page size NAND, the value is 6.
                # Block_Size : 128KB or 16KB.
                #----------------------------------------------------------
                printf("allocated_fat_space = %d, nand_block_size = %d\n", $allocated_fat_space, $nand_block_size) if ($DebugPrint & 1);
                
                $fat_nand_block_num  = $allocated_fat_space / ($nand_block_size * 1024);
                $fat_nand_region_num = ceil($fat_nand_block_num / 256);

                if ($nand_block_size == 128)
                {
                    $nand_log_block_num = 3;
                }
                elsif ($nand_block_size == 16)
                {
                    $nand_log_block_num = 6;
                }
                else
                {
                    cksysdrv_die(ERR::ERR_UNEXPECTED, "Unsupported NAND block size!\n", __FILE__, __LINE__);
                }

                $free_space = ($fat_nand_block_num - (($fat_nand_region_num) * (12 + 5)) - ($nand_log_block_num)) * ($nand_block_size * 1024);
            }
            else    # NAND FDM5
            {

                #----------------------------------------------------------
                # Block_Size : 128KB or 16KB.
                # 40 : Reserved blocks in each region (1024 blocks).
                #----------------------------------------------------------
                printf("\t\t[i]allocated_fat_space = %d, nand_block_size = %d\n", $allocated_fat_space, $nand_block_size) if ($DebugPrint & 1);

                $fat_nand_block_num  = $allocated_fat_space / ($nand_block_size * 1024);
                $fat_nand_region_num = ceil($fat_nand_block_num / 1024);

                printf("\t\t[i]nand_block_num = %d, nand_region_num = %d, nand_block_size = %d\n", $fat_nand_block_num, $fat_nand_region_num, $nand_block_size) if ($DebugPrint & 1);
                $free_space      = ($fat_nand_block_num - (($fat_nand_region_num) * 40)) * ($nand_block_size * 1024);

                printf("\t\t[i]first_partition_size = $first_partition_size, first_partition_sectors = $first_partition_sectors\n") if ($DebugPrint & 1);
                
                printf("\tBlock Number: %d\n",  $fat_nand_block_num)  if ($DebugPrint &1);
                printf("\tRegion Number: %d\n", $fat_nand_region_num) if ($DebugPrint &1);
                printf("\tFree Space: %d B = %d KB = %d MB\n", $free_space, $free_space / 1024, $free_space / (1024 * 1024)) if ($DebugPrint &1);
                
            }
        }
        else    # we have no NAND flash geometry information (before 09A), use 2KB page size to do more strict checking.
        {
            if ($nand_fdm_version == 4)
            {

                #----------------------------------------------------------
                # 12 : Reserved blocks in each region.
                # 5  : Max possible bad blocks number in each region. (2%)
                # 3  : Number of log blocks. In 2KB NAND, 3 log blocks.
                #----------------------------------------------------------

                $fat_nand_block_num  = $allocated_fat_space / (128 * 1024);
                $fat_nand_region_num = ceil($fat_nand_block_num / 256);
                $free_space      = ($fat_nand_block_num - (($fat_nand_region_num) * (12 + 5)) - 3) * (128 * 1024);
            }
            else    # NAND FDM5
            {

                #----------------------------------------------------------
                # 40 : Reserved blocks in each region.
                #----------------------------------------------------------

                $fat_nand_block_num  = $allocated_fat_space / (128 * 1024);
                $fat_nand_region_num = ceil($fat_nand_block_num / 1024);
                $free_space      = ($fat_nand_block_num - (($fat_nand_region_num) * 40)) * (128 * 1024);
            }
        }

        # Calculate system drive free space
        $free_space = $free_space - $first_partition_size;
        $alignment = ($nand_block_size * 1024);
        
        printf("first_partition_size = $first_partition_size, first_partition_sectors = $first_partition_sectors\n") if ($DebugPrint & 1);

        printf("[CkSysDrv:NAND] Block Number: %d\n",  $fat_nand_block_num)  if ($DebugPrint &1);
        printf("[CkSysDrv:NAND] Region Number: %d\n", $fat_nand_region_num) if ($DebugPrint &1);
        printf("[CkSysDrv:NAND] Free Space: %d B = %d KB = %d MB)\n", $free_space, $free_space / 1024, $free_space / (1024 * 1024)) if ($DebugPrint &1);

    }
    elsif ($system_drive_location == $ON_NOR)    # System drive on NOR flash
    {

        print "[$DEV_TYPE] Calculate free space...\n" if ($DebugPrint &1);

        printf("\t\t[i]nor_sector_size                         = $nor_sector_size\n")if ($DebugPrint & 2);
        printf("\t\t[i]nvram_custom_cfg_max_record_sector_num  = $nvram_custom_cfg_max_record_sector_num\n")if ($DebugPrint & 2);

        $nor_protection_mode_reserved_space = ($nvram_custom_cfg_max_record_sector_num * 2 + 1) * $nor_sector_size;
        printf("\t\t[i]nor_protection_mode_reserved_space      = $nor_protection_mode_reserved_space\n")if ($DebugPrint & 2);


		$nor_extra_reserved_space = 4 * $nor_sector_size if ($nor_reserved_blocks == $nor_min_reserved_blocks);
        printf("\t\t[i]nor_min_reserved_blocks                 = $nor_min_reserved_blocks\n")if ($DebugPrint & 2);
        printf("\t\t[i]nor_reserved_blocks                     = $nor_reserved_blocks\n")if ($DebugPrint & 2);
        printf("\t\t[i]nor_extra_reserved_space                = $nor_extra_reserved_space\n")if ($DebugPrint & 2);
  
	  	$nor_extra_reserved_space_for_power_loss = 6 * $nor_sector_size if ($nor_sector_size == 512);
        printf("\t\t[i]nor_extra_reserved_space_for_power_loss = $nor_extra_reserved_space_for_power_loss\n")if ($DebugPrint & 2);


		$blockheader_overhead_total = ceil($allocated_fat_space/($nor_max_blk_size + $blockheader_overhead)) * $blockheader_overhead;
		printf("\t\t[i]blockheader_overhead_total      = $blockheader_overhead_total\n")if ($DebugPrint & 2);
		printf("\t\t[i]blocks                          = %d\n", ceil($allocated_fat_space/$nor_max_blk_size))if ($DebugPrint & 2);

        $nor_drive_overhead = $blockheader_overhead_total + ($nor_reserved_blocks * $nor_max_blk_size + $nor_protection_mode_reserved_space + $nor_extra_reserved_space + $nor_extra_reserved_space_for_power_loss);
        printf("\t\t[i]nor_drive_overhead              = $nor_drive_overhead\n")if ($DebugPrint & 2);

        $free_space = $allocated_fat_space - $first_partition_size - $nor_drive_overhead;    # in Byte
        printf("\t\t[i]free_space                      = $free_space\n")if ($DebugPrint & 2);


    }
    elsif ($system_drive_location == $ON_EMMC)    # System drive on EMMC
    {
        $allocated_fat_space = $free_space = $system_drive_size;
        $alignment = 1;

    }
    else
    {
        cksysdrv_die(ERR::ERR_UNEXPECTED,  "Unsupported system drive location!\n", __FILE__, __LINE__);
        
    }

    print "[CkSysDrv] Calculate FAT type and cluster size...\n" if ($DebugPrint &1);

    $cluster_size = -1;  # in Byte
    my $fat_type     = 12;

    if ($free_space == -1)
    {

        # free space is not available
        $cluster_size = -2;
        warn "[CkSysDrv] Free space is not available!";
    }
    elsif ($free_space < 1024 * 1024)
    {
        $cluster_size = 512;
    }
    elsif ($free_space < 4096 * 1024)
    {
        $cluster_size = 1024;
    }
    elsif ($free_space < 8192 * 1024)
    {
        $cluster_size = 2048;
    }
    elsif ($free_space < 16384 * 1024)
    {
        $cluster_size = 4096;
    }
    elsif ($free_space < 32 * 1024 * 1024)
    {
        $cluster_size = 1024;
        $fat_type     = 16;
    }
    elsif ($free_space < 128 * 1024 * 1024)
    {
        $cluster_size = 2048;
        $fat_type     = 16;
    }
    elsif ($free_space < 256 * 1024 * 1024)
    {
        $cluster_size = 4096;
        $fat_type     = 16;
    }
    elsif ($free_space < 512 * 1024 * 1024)
    {
        $cluster_size = 8192;
        $fat_type     = 16;
    }
    else
    {

        # when free space >= 512MB, no need to determine system drive free space;
        # $cluster_size will be set as -1
        warn "[CkSysDrv] System Drive >= 512MB , such configuration not supported by FileSystem in default";
    }

    printf("[CkSysDrv] FAT type: FAT%d\n",          $fat_type)     if ($DebugPrint &1);
    printf("[CkSysDrv] Cluster size: %d (Bytes)\n", $cluster_size) if ($DebugPrint &1);

    print "[CkSysDrv] Parse FS quota configurations...\n" if ($DebugPrint &1);

#****************************************************************************
# Parse ~fs_quota_usage.log to determine folder size
#****************************************************************************
# my $folder =
# {
#    FOLDER    => $folder_name,
#    COUNT     => $count,
#    UNIT      => $unit_byte,
#    SIZE      => $size_in_byte
# }
    my @folder_size = ();

    open(FS_STAT, "<$FS_STAT") or cksysdrv_die(ERR::ERR_UNEXPECTED,  "cannot open FS_STAT: $FS_STAT\n\n", __FILE__, __LINE__);
    $/ = $backup;

    while (<FS_STAT>)
    {

        # match {Z:\@USER\, 0, 83968,  0xf1f2f3f4 ,  0x1 },
        if (/\{\s*(Z.+\\)\s*,[^,]+,\s*(\d+)\s*,[^,]+,\s*(0x[\dA-Fa-f]+)\s*\}\s*,/i)
        {
            my %this_folder = ();
            $this_folder{FOLDER} = $1;
            $this_folder{COUNT}  = $2;
            $this_folder{UNIT}   = $3;
            $this_folder{SIZE}   = ($this_folder{UNIT} eq '0x1') ? ($this_folder{COUNT}) : ($this_folder{COUNT} * $cluster_size);

            push @folder_size, \%this_folder;

        }
    }

    close FS_STAT;

    foreach my $folder (@folder_size)
    {
        printf("%-20s %10s\n", $folder->{FOLDER}, $folder->{SIZE}) if ($DebugPrint &4);
    }

    print "[CkSysDrv] Parse NVRAM configurations...\n" if ($DebugPrint &1);

#****************************************************************************
# Parse ~nvram_lid_size.log to get application's nvram reserved size info.
#****************************************************************************
    my @app_rev_size = ();

# my $app =
# {
#    APPLICATION  => $app_name,
#    SIZE         => $size_in_byte # unit_size * record_num
# }

# For NVRAM-PSEUDO-MERGE usage.
    my %this_app = ();
    $this_app{APPLICATION} = "Package file size";
    $this_app{SIZE}        = "unknown";
    push @app_rev_size, \%this_app;

    my %this_app = ();
    $this_app{APPLICATION} = "Info file A";
    $this_app{SIZE}        = "unknown";
    push @app_rev_size, \%this_app;

    my %this_app = ();
    $this_app{APPLICATION} = "Info file B";
    $this_app{SIZE}        = "unknown";
    push @app_rev_size, \%this_app;

    my %this_app = ();
    $this_app{APPLICATION} = "Extra size";
    $this_app{SIZE}        = "unknown";
    push @app_rev_size, \%this_app;

    foreach my $app (@app_rev_size)
    {
        printf("%-40s %10s\n", $app->{APPLICATION}, $app->{SIZE}) if ($DebugPrint & 1);
        $cluster_multiple{$app->{APPLICATION}} = 1;
    }
    print("Start parse NVRAM LID\n") if ($DebugPrint &1);
    open(NVRAM_STAT, "<$NVRAM_STAT") or cksysdrv_die(ERR::ERR_UNEXPECTED,  "Cannot open NVRAM_STAT: $NVRAM_STAT\n\n", __FILE__, __LINE__);

    my %app_size = ();
    $/ = $backup;

    while (<NVRAM_STAT>)
    {
        $_ =~ s/\bCUSTPACK\b//;
        if (/(\d+)\s*(\d+)\s*(\w.+\w)/)
        {
            if (!defined($cluster_multiple{$3}))
            {
                my %this_app = ();
                $this_app{APPLICATION} = $3;
                $this_app{SIZE}        = $2;
                $cluster_multiple{$3}  = 1;
                print "push: " if ($DebugPrint &4); 
                push @app_rev_size, \%this_app;
            }
            if (defined $app_size{$3})
            {
                cksysdrv_die(ERR::ERR_UNEXPECTED,  "$3 has different sizes $app_size{$3} vs. $2!\n", __FILE__, __LINE__) unless ($app_size{$3} == $2);
                $app_size{$3}         += $app_size{$3};
                $cluster_multiple{$3} += 1;
            }
            else
            {
                $app_size{$3} = $2;
                print "$app_size{$3} $3\n" if ($DebugPrint &4);
            }
        }
    }

    close NVRAM_STAT;

    while ((my $key, my $value) = each %app_size)
    {

#   print "$key $value\n" if ($DebugPrint &1);
    }

    foreach my $app (@app_rev_size)
    {
        if (   ($NVRAM_PSEUDO_MERGE =~ /^ON|TRUE$/)
            && (!exists $app_size{$app->{APPLICATION}}))
        {
            $app_size{$app->{APPLICATION}} = 0;
        }

        if ($app->{SIZE} ne 'unknown')
        {
            if ($cluster_multiple{$app->{APPLICATION}} eq "1")
            {
                if ($app_size{$app->{APPLICATION}})
                {
                    warn "$app->{APPLICATION} has different sizes $app->{SIZE} vs. $app_size{$app->{APPLICATION}}!" unless ($app->{SIZE} == $app_size{$app->{APPLICATION}});
                }
            }
            $app->{SIZE} = $app_size{$app->{APPLICATION}};
        }
        else
        {
            $app->{SIZE} = $app_size{$app->{APPLICATION}};
        }

        printf("%-40s %10s\n", $app->{APPLICATION}, $app->{SIZE}) if ($DebugPrint &4);
    }

    print "[CkSysDrv] Parse file system management overhead...\n" if ($DebugPrint &1);

#****************************************************************************
# Determine FAT overhead
#****************************************************************************
# Calculate the freespace by removing MBR & PBR & FAT & Root DIR space.
    my $fat_overhead_cluster;
    my $tmp_free_space = $free_space;

# MBR
    $tmp_free_space -= 512;

# PBR
    $tmp_free_space -= 512;

# FAT
    if ($fat_type == 12)
    {

        # FAT-12
        # DIR
        if ($fs_low_cost_support == 1)
        {
            $tmp_free_space -= (16 * 32);    # 1
        }
        else
        {
            $tmp_free_space -= (128 * 32);    # 8
        }

        # FAT Table
        my $fat_size = 0;

        if ($cluster_size > 0)
        {
            while (($fat_size * 2 / 3) * $cluster_size < $tmp_free_space)
            {
                $fat_size += 512;
                $tmp_free_space -= 512;
            }
        }
    }
    else
    {

        # FAT-16
        # DIR
        if ($fs_low_cost_support == 1)
        {
            $tmp_free_space -= (16 * 32);    # 1
        }
        else
        {
            $tmp_free_space -= (512 * 32);    # 32
        }

        # FAT Table
        my $fat_size = 0;

        if ($cluster_size > 0)
        {
            while (($fat_size / 2) * $cluster_size < $tmp_free_space)
            {
                $fat_size += 512;
                $tmp_free_space -= 512;
            }
        }
    }

# Example:
#Z:\@WAP\
#Z:\@DRM\
#Z:\NVRAM\NVD_DATA\NVRAM_EF_PHB_LID
#                 \NVRAM_EF_SMS_LID
# dir entry of level-1 (in cluster unit) = 2 (@WAP, @DRM)
# dir entry of level-2 (in direntry cnt) = 2 + 1 ("." , ".." , NVD_DATA) at Z:\NVRAM
# dir entry of level-3 (in direntry cnt) = 2 + 2 ("." , ".." , NVRAM_EF_PHB_LID, NVRAM_EF_SMS_LID) at Z:\NVRAM\NVD_DATA

    my $fat_overhead_cluster;
    if ($cluster_size > 0)
    {

        # level-1 directory entries + level-2 directory entries + level-3 directory entries
        $fat_overhead_cluster = ($#folder_size + 1) + ceil((2 + 1) * 32 / $cluster_size) + ceil((2 + ($#app_rev_size + 1)) * 32 / $cluster_size);
    }

    print "[CkSysDrv] Print result...\n" if ($DebugPrint &1);
    print("===========================================================\n");

#****************************************************************************
# Print out the result
#****************************************************************************
#1.
#  die "Free space is greater than 16MB!";
#print "SYSTEM_DRIVE_ON_NAND = $SYSTEM_DRIVE_ON_NAND\n";
#print "FAT_BASE_ADDRESS = $flash_base_address (".hex($flash_base_address).")\n";
    print("                                               Byte Cluster\n");
    print("===========================================================\n");
    
    if ($system_drive_location == $ON_NOR || $system_drive_location == $ON_NAND)
    {
        printf("FS Total Size  %36s %7s\n",                            $allocated_fat_space, $allocated_fat_space/$cluster_size);
        printf("FS Public(First) Drive Size %23s %7s\n",               $first_partition_size, $first_partition_size/$cluster_size);
        printf("FS Overhead for (MBR + PBR + Root Dir) %12s %7s\n",     $free_space - $tmp_free_space, ($free_space - $tmp_free_space)/$cluster_size);
        if ($system_drive_location == $ON_NOR)
        {
            printf("FDM Overhead (NOR) %32s %7s\n",                 $nor_drive_overhead, $nor_drive_overhead/$cluster_size);
        }
        elsif ($system_drive_location == $ON_NAND)
        {
            printf("FDM Overhead (NAND) %31s %7s\n",                ($fat_nand_region_num * 40) * ($nand_block_size * 1024), ($fat_nand_region_num * 40) * ($nand_block_size * 1024)/$cluster_size);
        }

    }
    else #EMMC
    {
        printf("FS System Drive Size  %29s \n",               $free_space);
    }

    $free_space = $tmp_free_space;

    

    my $free_space_cluster    = floor($free_space / $cluster_size);
    my $app_rev_total         = 0;
    my $app_rev_total_cluster = 0;
    my $folder_total          = 0;
    my $folder_total_cluster  = 0;
    my $nv_overhead           = 0;
    my $nv_overhead_cluster   = 0;
    my $mini_public_drv_sectors = 0;

    #CYLEN: need to calc real overhead of NVRAM
    if ($NVRAM_PSEUDO_MERGE =~ /^ON|TRUE$/)
    {
    	$nv_overhead = 10;
    }
    else
    {
    	$nv_overhead = 15;
    }

    printf("NVRAM reserved folder overhead %20s %7s\n", $nv_overhead * $cluster_size, $nv_overhead);

    if ($free_space_cluster >= $nv_overhead)
    {
        $free_space_cluster -= $nv_overhead; 
    }
    else
    {
        $free_space_cluster = 0;
    }

	$nv_overhead = 0;
	

    print("===========================================================\n");


    if ($cluster_size > 0)
    {
        printf("Free Space for NVRAM and App's Folders %12s %7s\n\n", $free_space, $free_space_cluster);
        print("-----------------------------------------------------------\n");
        printf("FAT Type     %38s        \n", $fat_type);
        printf("Cluster Size %38s       1\n", $cluster_size);
        print("-----------------------------------------------------------\n");
        printf("FAT Overhead for Sub Dir %26s %7s\n", $fat_overhead_cluster * $cluster_size, $fat_overhead_cluster);
        print("-----------------------------------------------------------\n");
        foreach my $app (@app_rev_size)
        {

            if ($app->{SIZE} ne "unknown")
            {
                printf("%-40s %10s %7s\n", $app->{APPLICATION}, $app->{SIZE}, ceil($app->{SIZE} / $cluster_multiple{$app->{APPLICATION}} / $cluster_size) * $cluster_multiple{$app->{APPLICATION}}) if ($DebugPrint == 0 || ($DebugPrint & 8) == 1);
                $app_rev_total         += $app->{SIZE};
                $app_rev_total_cluster += ceil($app->{SIZE} / $cluster_multiple{$app->{APPLICATION}} / $cluster_size) * $cluster_multiple{$app->{APPLICATION}};
            }
            else
            {
                printf("%-40s %10s %7s\n", $app->{APPLICATION}, $app->{SIZE}, $app->{SIZE}) if ($DebugPrint == 0 ||  ($DebugPrint & 8) == 1);
            }
        }

        for(keys %cluster_multiple)
        {
            delete $cluster_multiple{$_};
        }
        
        if (defined $app_size{'SW CHANGE LID LIST'})
        {
            printf("%-40s %10s %7s\n", "NVRAM_EXTRA_REPORT_FILES", $app_size{'SW CHANGE LID LIST'}, ceil($app_size{'SW CHANGE LID LIST'} / $cluster_size)) if ($DebugPrint == 0 || ($DebugPrint & 8) == 1);
            $nv_overhead         += $app_size{'SW CHANGE LID LIST'};
            $nv_overhead_cluster += ceil($app_size{'SW CHANGE LID LIST'} / $cluster_size);
        }
        if (defined $app_size{'SW CHANGE LID DESCRIPTION'})
        {
            printf("%-40s %10s %7s\n", "NVRAM_EXTRA_REPORT_FILES", $app_size{'SW CHANGE LID DESCRIPTION'}, ceil($app_size{'SW CHANGE LID DESCRIPTION'} / $cluster_size)) if ($DebugPrint == 0 || ($DebugPrint & 8) == 1);
            $nv_overhead         += $app_size{'SW CHANGE LID DESCRIPTION'};
            $nv_overhead_cluster += ceil($app_size{'SW CHANGE LID DESCRIPTION'} / $cluster_size);
        }

        printf("\nTOTAL %45s %7s\n", $app_rev_total + $nv_overhead, $app_rev_total_cluster + $nv_overhead_cluster);
        print("-----------------------------------------------------------\n");

        foreach my $folder (@folder_size)
        {
            if ($folder->{SIZE} ne "unknown")
            {
                printf("%-40s %10s %7s\n", $folder->{FOLDER}, $folder->{SIZE}, ceil($folder->{SIZE} / $cluster_size)) if ($DebugPrint == 0 || ($DebugPrint & 8) == 1);
                $folder_total         += $folder->{SIZE};
                $folder_total_cluster += ceil($folder->{SIZE} / $cluster_size);
            }
            else
            {
                printf("%-40s %10s %7s\n", $folder->{FOLDER}, $folder->{SIZE}, $folder->{SIZE}) if ($DebugPrint == 0 || ($DebugPrint & 8) == 1);
            }
        }
        printf("\nTOTAL %45s %7s\n", $folder_total, $folder_total_cluster);
        print("===========================================================\n");

        my $folder_and_app_clusters = $fat_overhead_cluster + $app_rev_total_cluster + $nv_overhead_cluster + $folder_total_cluster;
        $diff                       = $free_space_cluster - $folder_and_app_clusters;

        print("\nREPORT\n");
        print("===========================================================\n");
        printf("Cluster Size (Bytes) %38s\n",                            $cluster_size);
        printf("Free Space (Clusters) %37s\n",                           $free_space_cluster);
        printf("Folders and Applications Requirement (Clusters) %11s\n", $folder_and_app_clusters);

        print("\n");

        if ($system_drive_location == $ON_NAND)
        {
            $mini_public_drv_sectors = 400;
        }
        elsif ($system_drive_location == $ON_NOR)
        {
            $mini_public_drv_sectors = 25;
        }
        

        
        if ($diff >= 0)
        {
            my $diff_size = $diff * $cluster_size;
            
            print("RESULT: PASS!\n");
            printf("%d clusters are left (%.1f KB = %.2f MB)\n", $diff, $diff_size / 1024, $diff_size / (1024 * 1024));

            if ($fs_auto_config_support == 0)
            {
                return ERR::NO_MODIFY;
            }
            
            #this is temp solution, because don't know how big is code region when multi-bin
            if ($code_boundary_addr == $release_all_free)
            {
                
                $code_boundary_addr = $flash_base_address + $diff_size + $first_partition_size;

                $code_shortage_size = $first_partition_size + $diff_size;
                $short_block = floor($code_shortage_size/$alignment);
                $short_block_size = $short_block * $alignment;

            }
            elsif ($code_boundary_addr > 0)
            {
                $code_shortage_size = $code_boundary_addr - $flash_base_address;
                $short_block = floor($code_shortage_size/$alignment);
                $short_block_size = $short_block * $alignment;
            }

            if ($code_shortage_size > 0)
            {
                printf("But Code & FAT overlap!\n");
                printf("Code region still need 0x%08X bytes (%d sectors, %d blocks)\n", $code_shortage_size, $code_shortage_size/512, $short_block);

                printf("\t\t[i]code_boundary_addr   = 0x%08X(%d)\n", $code_boundary_addr, $code_boundary_addr) if ($DebugPrint & 2);
                printf("\t\t[i]flash_base_address   = 0x%08X(%d)\n", $flash_base_address, $flash_base_address) if ($DebugPrint & 2);
                printf("\t\t[i]short_block_size     = 0x%08X(%d)\n", $short_block_size, $short_block_size) if ($DebugPrint & 2);
                printf("\t\t[i]first_partition_size = 0x%08X(%d)\n", $first_partition_size, $first_partition_size) if ($DebugPrint & 2);
                printf("\t\t[i]diff                 = 0x%08X(%d)\n", $diff_size, $diff_size) if ($DebugPrint & 2);

                if ($diff_size + $first_partition_size < $alignment) # free space less than one block --> fail
                {
                    printf("FAT region has no block-aligned space to free!\n");
                    return ERR::CANNOT_ADJUST;
                }
                

                #this is temp solution, because don't know how big is code region when multi-bin
                $flash_base_address += $short_block_size;
                $allocated_fat_space -= $short_block_size;
                printf("\t[Adjust] $DEV_PREFIX\FS_BASE_ADDRESS  (bytes, sectors) = (0x%08X, %d)\n", $flash_base_address, $allocated_fat_space/512) if ($DebugPrint & 2);
                printf("\t[Adjust] $DEV_PREFIX\FS_SIZE          (bytes, sectors) = (0x%08X, %d)\n", $allocated_fat_space, $allocated_fat_space/512) if ($DebugPrint & 2);

                if ($first_partition_size > 0)
                {
                    
                    if ($first_partition_size < $short_block_size )
                    {
                        if ($app_storage_in_sys_drv == 1)
                        {
                            $first_partition_size = 0;
                        }
                        else
                        {
                            if ($first_partition_size > $mini_public_drv_sectors * 1024)
                            {
                                $first_partition_size = $mini_public_drv_sectors * 1024;
                            }
                            else
                            {
                                ;
                            }
                        }
                    }
                    else
                    {
                        if ($app_storage_in_sys_drv == 1)
                        {
                            $first_partition_size -= $short_block_size;

                            if ($first_partition_size < $mini_public_drv_sectors * 1024)
                            {
                                $first_partition_size = 0;
                            }
                        }
                        else
                        {
                            if ($first_partition_size - $short_block_size > $mini_public_drv_sectors * 1024)
                            {
                                $first_partition_size -= $short_block_size;
                                $short_block_size = 0;
                            }
                            else
                            {
                                $short_block_size -= ($first_partition_size - $mini_public_drv_sectors * 1024);
                                $first_partition_size = $mini_public_drv_sectors * 1024;
                            }
                        }
                        
                        
                    }
                    printf("\t[Adjust] $DEV_PREFIX\FIRST_DRIVE_SIZE (bytes, sectors) = (0x%08X, %d)\n", $first_partition_size, $first_partition_size/512) if ($DebugPrint & 2);
                }
                
                #this is temp solution, because don't know how big is code region when multi-bin
                $code_boundary_addr = $flash_base_address;
                $code_shortage_size = 0;
                
                return ERR::MODIFY_SUCCESS;
            }
            
            return ERR::NO_MODIFY;

        }
        else
        {
            my $diff_size = $diff * $cluster_size * (-1);
            my $free_flash_block_space = ceil(($first_partition_size + $free_space)/$alignment);       #in Byte
            my $diff_block = ceil($diff_size/$alignment);
            my $diff_block_size = $diff_block * $alignment;


            print("RESULT: FAIL!\n");
            printf("FAT region still need 0x%08X bytes (%d sectors)\n", $diff_block_size, $diff_block_size/512);
            warn "Free clusters are NOT enough. ";

            #print("\nINSTRUCTION\n");
            #print("===========================================================\n");
            #print("Please help try following action items to solve this error. Suggested order is \n");
            #print("\n");
            #printf("1) Shrink FS First Drive Size to enlarge system drive size (Shrink at least %d sectors).\n", $diff * ($cluster_size / 512));
            #print("2) Enlarge FS Region Size.\n");
            #print("3) Disable some features to shrink quota requirement.\n");
            #print("4) Replace flash device with another bigger one (Custom release projects only).\n");
            print("\n");


            if ($FEATURE_OVERLOAD ne "TRUE")
            {
     
                
                printf("Diff = %dbytes = %dclusters = %dblocks(%d bytes)\n", $diff_size, -1 * $diff, $diff_block, $alignment)       if ($DebugPrint & 2);
                printf("SYSDRV_OFFSET (bytes, sectors) = %d, %d\n", $first_partition_size, $first_partition_size/512)               if ($DebugPrint & 2);
                printf("Free space (free_flash_block_space): $free_flash_block_space blocks\n")                                            if ($DebugPrint & 2);

                
                if ($fs_auto_config_support == 1)
                {

                    if ($system_drive_location == $ON_EMMC)
                    {
                        $allocated_fat_space = $system_drive_size = $allocated_fat_space + $diff_size;
                        printf("\t[Adjust] $DEV_PREFIX\FS_SIZE          (bytes, sectors) = (0x%08X, %d)\n", $allocated_fat_space, $allocated_fat_space/512) if ($DebugPrint & 2);
                    }
                    else
                    {
                        if ($first_partition_size > 0) #inside FS, already block-aligned, don't need to calc with alignment
                        {
                            if ($first_partition_size < $diff_size )
                            {
                                if ($app_storage_in_sys_drv == 1)
                                {
                                    $diff_size -= $first_partition_size;
                                    $first_partition_size = 0;
                                }
                                else
                                {
                                    if ($first_partition_size > $mini_public_drv_sectors * 1024)
                                    {
                                        $diff_size -= ($first_partition_size - $mini_public_drv_sectors * 1024);
                                        $first_partition_size = $mini_public_drv_sectors * 1024;
                                    }
                                    else
                                    {
                                        ;
                                    }
                                
                                }
                                
                            }
                            else
                            {
                                if ($app_storage_in_sys_drv == 1)
                                {
                                    $first_partition_size -= $diff_size;
                                    if ($first_partition_size < $mini_public_drv_sectors * 1024)
                                    {
                                        $first_partition_size = 0;
                                    }
                                    $diff_size = 0;
                                }
                                else
                                {
                                    if ($first_partition_size - $diff_size > $mini_public_drv_sectors * 1024)
                                    {
                                        $first_partition_size -= $diff_size;
                                        $diff_size = 0;
                                    }
                                    else
                                    {
                                        $diff_size -= ($first_partition_size - $mini_public_drv_sectors * 1024);
                                        $first_partition_size = $mini_public_drv_sectors * 1024;
                                    }
                                    
                                }


                            }
                        }
                        printf("%04d Adjust SYSDRV_OFFSET (bytes, sectors) = (0x%08X, %d)\n", __LINE__, $first_partition_size, $first_partition_size/512)         if ($DebugPrint & 2);
                   
                        #out of FS, must consider alignment
                        
                        $diff_block = ceil($diff_size/$alignment);
                        $diff_block_size = $diff_block * $alignment;

#                        if ($diff_block_size > ($free_flash_block_space * $alignment)) # free space less than one block --> fail
#                        {
#                            printf("FAT region has no block-aligned space to free!\n");
#                            return ERR::CANNOT_ADJUST;
#                        }
#                        else
                        {
                            $flash_base_address -= $diff_block_size;
                            $allocated_fat_space += $diff_block_size;
                            printf("%04d Adjust flash_base_address (bytes, sectors) = (0x%08X, %d)\n", __LINE__, $flash_base_address, $allocated_fat_space/512)   if ($DebugPrint & 2);
                            printf("%04d Adjust allocated_fat_space (bytes, sectors) = (0x%08X, %d)\n", __LINE__, $allocated_fat_space, $allocated_fat_space/512) if ($DebugPrint & 2);
                        }
                    }
                    
                    return ERR::MODIFY_SUCCESS;

                 }
             
            }

            return ERR::NO_MODIFY;

        }
    }
    else
    {
        printf("Free Space for NVRAM and App's Folders %11s\n\n", $free_space);
        print("-----------------------------------------------------------\n");
        print("Cluster Size  No need to be determined if Free space >= 512MB\n");
        print("-----------------------------------------------------------\n");
        print("FAT Overhead  No need to be determined if Free space >= 512MB\n");
        print("-----------------------------------------------------------\n");
        foreach my $app (@app_rev_size)
        {
            printf("%-40s %10s\n", $app->{APPLICATION}, $app->{SIZE});
            $app_rev_total += $app->{SIZE} if ($app->{SIZE} ne "unknown");
        }
        printf("\nTOTAL %45s\n", $app_rev_total);
        print("-----------------------------------------------------------\n");
        foreach my $folder (@folder_size)
        {
            printf("%-40s %10s\n", $folder->{FOLDER}, $folder->{SIZE});
            $folder_total += $folder->{SIZE} if ($folder->{SIZE} ne "unknown");
        }
        printf("\nTOTAL %45s\n", $folder_total);

        print("===========================================================\n");
        print "\n\nFree space >= 512MB are enough for Folders and Applications.\n";
        return ERR::NO_MODIFY;
    }
}
sub adjust_func
{
    my (%ChangeList, %OriginalList);
    my $fat_space = sprintf("0x%08X", $allocated_fat_space);
    my $base_addr = sprintf("0x%08X", $flash_base_address);
    my $sysdrv_offset = sprintf("%d",  $first_partition_size/512);

    if ($DebugPrint & 4)
    {
        my $tmp_h_path = "$BOARD_FOLDER\\fs_layout.h";
        
        open(tmp_h_path, "> $tmp_h_path") || cksysdrv_die(ERR::ERR_UNEXPECTED,  "cannot open fs_layout.h: $tmp_h_path\n\n", __FILE__, __LINE__);

        print tmp_h_path "/* Always  generated by ckSysDrv automatically */\n";
        print tmp_h_path "\n";
        print tmp_h_path "#ifdef __CKSYSDRV_AUTO_ADJ__\n";
        print tmp_h_path "\n";
        printf(tmp_h_path "#ifdef %sFS_BASE_ADDRESS \n", $DEV_PREFIX);
        printf(tmp_h_path "#undef %sFS_BASE_ADDRESS \n", $DEV_PREFIX);
        printf(tmp_h_path "#define %sFS_BASE_ADDRESS      $base_addr\n", $DEV_PREFIX);
        print tmp_h_path "#endif\n";
        print tmp_h_path "\n";
        printf(tmp_h_path "#ifdef %sFS_SIZE\n", $DEV_PREFIX);
        printf(tmp_h_path "#undef %sFS_SIZE\n", $DEV_PREFIX);
        printf(tmp_h_path "#define %sFS_SIZE              $fat_space\n", $DEV_PREFIX);
        print tmp_h_path "#endif\n";
        print tmp_h_path "\n";
        printf(tmp_h_path "#ifdef %sFS_FIRST_DRIVE_SECTORS\n", $DEV_PREFIX);
        printf(tmp_h_path "#undef %sFS_FIRST_DRIVE_SECTORS\n", $DEV_PREFIX);
        printf(tmp_h_path "#define %sFS_FIRST_DRIVE_SECTORS %d\n", $DEV_PREFIX, $sysdrv_offset);
        print tmp_h_path "#endif\n";
        print tmp_h_path "\n";
        print tmp_h_path "#endif /* __CKSYSDRV_AUTO_ADJ__ */\n";
        close tmp_h_path;
    }

    if ($original_base_address != $flash_base_address)
    {
        $ChangeList{"$DEV_PREFIX\FS_BASE_ADDRESS"} = $base_addr;
        $OriginalList{"$DEV_PREFIX\FS_BASE_ADDRESS"} = sprintf("0x%08X", $original_base_address);
    }
    
    if ($original_fat_space != $allocated_fat_space)
    {
        $ChangeList{"$DEV_PREFIX\FS_SIZE"} = $fat_space;
        $OriginalList{"$DEV_PREFIX\FS_SIZE"} = sprintf("0x%08X", $original_fat_space);
        
    }
    
    if ($original_first_partition_sectors != $first_partition_size/512)
    {
        $ChangeList{"$DEV_PREFIX\FS_FIRST_DRIVE_SECTORS"} = $sysdrv_offset;
        $OriginalList{"$DEV_PREFIX\FS_FIRST_DRIVE_SECTORS"} = sprintf("%d", $original_first_partition_sectors);
        
    }

    if (%ChangeList)
    {
        my $err;
        open(LINK_INFO, "> $LINK_INFO") or warn "cannot open $LINK_INFO\n";

        system("echo content of AAPMC.log:") if ($DebugPrint & 1);
        system("if exist $AAPMCLOG (type $AAPMCLOG) else echo File not exist") if ($DebugPrint & 2);
        
        if( ERR::AAPMCLOG_SUCCESS == &AAPMCLogParser::Open($AAPMCLOG))
        {
            my $report = "[Before Adjustment]\n";
            while(my ($key, $value) = each(%OriginalList))
            {
                my $string = sprintf("    $key: $value\n");
                
                $report = $report.$string;
            }

            
            $report .= "[AfterAdjustment]\n";

            while(my ($key, $value) = each(%ChangeList))
            {
                my $string = sprintf("    $key: $value\n");
                
                $report = $report.$string;
            }

            my $P4Info_ref =  &AUTO_ADJUST::CreateP4InfoTemplate("",#OWNER, 
                                                                 "",#$PROJECT, 
                                                                 "Auto adjust FAT setting", 
                                                                 $report);


            $err = &AAPMCLogParser::AddOneChangeRecord("$BOARD_FOLDER\\custom_MemoryDevice.h", 
                                                           \%ChangeList, \%$P4Info_ref);
            print "[AAPMC] return code: $error_code{$err}($err)\n";
            if($err == ERR::ERR_MODIFYDUPLICATED)
            {
                printf(LINK_INFO "[AAPMC] can't modified more than twice\n");

            }
            elsif ($err == ERR::AAPMCLOG_SUCCESS)
            {
                printf(LINK_INFO "[AAPMC] add successfully!\n".$report);

            }
            else
            {
                printf(LINK_INFO "[AAPMC] unexcept error: $err\n");
            }
            &AAPMCLogParser::Close($AAPMCLOG);
        }
        else
        {
            printf(LINK_INFO "[AAPMC] load AAPMCLog failed\n");
        }

        close LINK_INFO;
        system("echo content of CheckBinaryBlockUsage.log:") if ($DebugPrint & 1);
        system("if exist .\\build\\$PROJECT\\log\\CheckBinaryBlockUsage.log (type .\\build\\$PROJECT\\log\\CheckBinaryBlockUsage.log) else echo File not exist") if ($DebugPrint & 2);
        system("echo content of $LINK_INFO") if ($DebugPrint & 2);
        system("type $LINK_INFO") if ($DebugPrint & 2);

        return $err;
    }
    else
    {
        system("echo content of CheckBinaryBlockUsage.log") if ($DebugPrint & 1);
        system("if exist .\\build\\$PROJECT\\log\\CheckBinaryBlockUsage.log (type .\\build\\$PROJECT\\log\\CheckBinaryBlockUsage.log) else echo File not exist") if ($DebugPrint & 2);
        return ERR::NO_MODIFY
    }

    
}

sub cksysdrv_die
{
    my ($err, $error_msg, $file, $line_no) = @_;
    my $final_error_msg = "[ckSysDrv]: $error_msg at $file line $line_no : ($error_code{$err})!\n";

    print($final_error_msg);

    if ($#ARGV > 5)
    {
        open(LINK_INFO, "> $LINK_INFO") or die "cannot open LINK_INFO: $LINK_INFO\n";
        printf(LINK_INFO $final_error_msg);
        close LINK_INFO;
    }
    exit $err;
}

