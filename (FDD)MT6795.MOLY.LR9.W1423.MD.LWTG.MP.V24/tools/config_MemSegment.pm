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
#*   config_MemSegment.pm
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This module collects the subroutines for common utility. 
#*       
#*
#* Author:
#* -------
#*   Carina Liao (mtk04017)
#*
#****************************************************************************/
package memConfig;
use strict;
#use warnings;
BEGIN { push @INC, './tools/' }  # add additional library path
use sysGenUtility;                 #pm file name without case sensitivity
use FileInfoParser;
use CommonUtility;
use File::Basename;
#****************************************************************************
# Version
#****************************************************************************
my $CONFIGMEMSEGMENT_VERNO   = " m0.06";
                               # m0.06 , 2012/09/18, Change getting flash size rule and add error checking in GetPhysicalFlashEnd()
                               # m0.05 , 2012/08/17, Support Smartphone
                               # m0.04 , 2012/08/10, Support GetBlockSize() in Get_SDS_total_size() directly
                               # m0.03 , 2012/08/07, Add Memory Parsing Rule and Verification
                               # m0.02 , 2012/07/26, Replace is_NOR() by is_NonSPNOR() and add some error handling
                               # m0.01 , 2012/07/12, Move booting type query from sysGenUtility to FileInfoParser
                               # v0.02 , 2012/05/28, Support path and filename case sensitive on Linux
                               # v0.01 , 2012/05/14, Initial revision
#****************************************************************************
# Constants
#****************************************************************************
#Parse File Type
use constant MEMORY_DEVICE                 => "CUSTOM_MEMORY_DEVICE";
use constant FEATURE_CONFIG                => "CUSTOM_FEATURE_CONFIG";
use constant CUSTOM_IMG_CONFIG             => "CUSTOM_IMG_CONFIG";
use constant CUSTOM_EMI                    => "CUSTOM_EMI_RELEASE";
use constant CUSTOM_FLASH                  => "CUSTOM_FLASH";
#****************************************************************************
# Global variable
#****************************************************************************
my %g_MemConfigValues; # $MemConfigValues{Type} = href;
#Keyword needs to be case sensitive:
# ----- RAM -----
# nEMI_EXTSRAM_SIZE    : exported by GetPhysicalExtRAM()
# strEMI_EXTSRAM_SIZE  : exported by GetPhysicalExtRAM()
# nPROCESSED_RAMSIZE   : exported by GetExtRamSize()

# ----- Flash Info -----
# RegionInfoTxt         : exported by GetFlashInfoLog()
# BlkInfoTxt            : exported by GetFlashInfoLog()
# BankInfoTxt           : exported by GetFlashInfoLog()
# REGION_LIST
# BANK_LIST
# BLK_LIST
# BLK_TABLE       : exported by GetBlockTable()

# ----- Flash Size -----
# NOR_FLASH_DENSITY  : exported by GetFlashInfoLog()
# nNOR_FLASH_DENSITY
# NOR_FLASH_SIZE  : exported by GetFlashInfoLog()
# nNOR_FLASH_SIZE : exported by GetPhysicalFlashEnd()
# nCODESize       : exported by GetROMSize()

#****************************************************************************
# oo >>>  Finished
#****************************************************************************
return 1;

sub Parse
{
    my ($strFilePath, $Source, $INSIDE_MTK, $bIsDummy) = @_;
    return if(!defined $Source);
    my %Results;
    $Results{PATH} = $strFilePath;
    $Results{path} = $strFilePath;
    if($Source eq FEATURE_CONFIG)
    {
        &FileInfo::ParseDefinition($strFilePath, \%Results, 0);
        &_PostProcessFeatureConfig(\%Results, $INSIDE_MTK, $bIsDummy);
    }
    elsif($Source eq CUSTOM_IMG_CONFIG)
    {
        &FileInfo::ParseDefinition($strFilePath, \%Results, 1);
        &_PostProcessIMG_CONFIG(\%Results);    
    }
    elsif($Source eq CUSTOM_EMI)
    {
        &FileInfo::ParseDefinition($strFilePath, \%Results, 0);
        &_PostProcessRamSize(\%Results, $bIsDummy);
    }
    elsif($Source eq CUSTOM_FLASH)
    {
            &_ParseFlashInfo($strFilePath, \%Results); 
            &_PostProcessFlashSize(\%Results, $bIsDummy);
    }
    else
    {
        &FileInfo::ParseDefinition($strFilePath, \%Results, 0);
    }
    $g_MemConfigValues{$Source} =  \%Results;
}

sub _PostProcessFeatureConfig
{
    my ($Hash_ref, $INSIDE_MTK, $bIsDummy)=@_;
    if($INSIDE_MTK == 0)
    {
        delete $Hash_ref->{"PROJECT_EXPECTED_CODE_LIMIT"} if (exists $Hash_ref->{"PROJECT_EXPECTED_CODE_LIMIT"});
        delete $Hash_ref->{"PROJECT_EXPECTED_RAM_LIMIT"} if (exists $Hash_ref->{"PROJECT_EXPECTED_RAM_LIMIT"});
        delete $Hash_ref->{"PROJECT_EXPECTED_RAM_LIMIT_NFB"} if (exists $Hash_ref->{"PROJECT_EXPECTED_RAM_LIMIT_NFB"});
    }
    if($bIsDummy)
    {
        $Hash_ref->{'CONFIG_ZIMAGE_DECOMPRESSED_SIZE'} = "0x2000000";
    }
    $Hash_ref->{CONFIG_FOTA_UE_FLASH_SPACE}       = "0x0" if(!defined $Hash_ref->{CONFIG_FOTA_UE_FLASH_SPACE});
    $Hash_ref->{CONFIG_FOTA_PACKAGE_BLOCK_NUMBER} = "4" if(!defined $Hash_ref->{CONFIG_FOTA_PACKAGE_BLOCK_NUMBER});
    $Hash_ref->{CONFIG_FOTA_PACKAGE_AREA_SIZE}    = "0x0" if(!defined $Hash_ref->{CONFIG_FOTA_PACKAGE_AREA_SIZE});
    $Hash_ref->{CONFIG_FOTA_NAND_MAP_TABLE_SIZE}  = "0x800" if(!defined $Hash_ref->{CONFIG_FOTA_NAND_MAP_TABLE_SIZE});
}
sub _PostProcessIMG_CONFIG
{
    my ($Hash_ref) = @_;
    if(defined $g_MemConfigValues{FEATURE_CONFIG})
    {
        $Hash_ref->{CONFIG_FOTA_UE_FLASH_SPACE} = &get("CONFIG_FOTA_UE_FLASH_SPACE", FEATURE_CONFIG);
        $Hash_ref->{CONFIG_FOTA_PACKAGE_BLOCK_NUMBER} = &get("CONFIG_FOTA_PACKAGE_BLOCK_NUMBER", FEATURE_CONFIG);
        $Hash_ref->{CONFIG_FOTA_PACKAGE_AREA_SIZE} = &get("CONFIG_FOTA_PACKAGE_AREA_SIZE", FEATURE_CONFIG);
        $Hash_ref->{CONFIG_FOTA_NAND_MAP_TABLE_SIZE} = &get("CONFIG_FOTA_NAND_MAP_TABLE_SIZE", FEATURE_CONFIG);
    }
}
sub _PostProcessRamSize
{
    my ($Hash_ref, $bIsDummy) = @_;
    $Hash_ref->{nEMI_EXTSRAM_SIZE} = eval($Hash_ref->{EMI_EXTSRAM_SIZE});
    $Hash_ref->{strEMI_EXTSRAM_SIZE} = &CommonUtil::Dec2Hex($Hash_ref->{nEMI_EXTSRAM_SIZE});
    if($bIsDummy)
    {
        $Hash_ref->{nPROCESSED_RAMSIZE} = 0x8000000;
    }
    else
    {
        &DieIfNotParsing(FEATURE_CONFIG, __FILE__, __LINE__);
        if(&FileInfo::is_NonSPNOR() and &exist('PROJECT_EXPECTED_RAM_LIMIT', FEATURE_CONFIG))
        {
            $Hash_ref->{nPROCESSED_RAMSIZE} = hex(&get('PROJECT_EXPECTED_RAM_LIMIT', FEATURE_CONFIG));
        }
        elsif(!&FileInfo::is_NonSPNOR() and &exist('PROJECT_EXPECTED_RAM_LIMIT_NFB', FEATURE_CONFIG))
        {
            $Hash_ref->{nPROCESSED_RAMSIZE} = hex(&get('PROJECT_EXPECTED_RAM_LIMIT_NFB', FEATURE_CONFIG));
        }
        else
        {
            $Hash_ref->{nPROCESSED_RAMSIZE} = $Hash_ref->{"nEMI_EXTSRAM_SIZE"};
        }
    }
}
sub _ParseFlashInfo
{
    my ($strFilePath, $Hash_ref) = @_;
    my (@REGION_LIST, @BANK_LIST, @BLK_LIST, %BLK_TABLE);
    my $content = &CommonUtil::GetFileContent($strFilePath);
    my @lines = split(/\n|\r/, $content);
    &_parse_flash_size(\@lines, $Hash_ref);
    if(&FileInfo::is_NonSPNOR())
    {
        $Hash_ref->{RegionInfoTxt} = &_parse_norflash_list(\@lines, \@REGION_LIST,  
                                          'FLASH_REGIONINFO_VAR_MODIFIER\s+FlashRegionInfo\s+oriRegionInfo\S+',
                                          'EndoriRegionInfo');
        $Hash_ref->{BlkInfoTxt} = &_parse_norflash_list(\@lines, \@BLK_LIST, 
                                          'FLASH_REGIONINFO_VAR_MODIFIER\s+FlashBlockTBL\s+\S+',
                                          'EndBlockInfo');
        $Hash_ref->{BankInfoTxt} = &_parse_norflash_list(\@lines, \@BANK_LIST,
                                          'static\s+NORBankInfo\s+oriBankInfo\S+',
                                          'EndBankInfo');
        if (scalar(@BLK_LIST) > 0)
        {
            foreach my $item (@BLK_LIST)
            {   #{0x0, 0x10000}
                $BLK_TABLE{hex($item->[0])} = hex($item->[1]);
            }
        }
        $Hash_ref->{REGION_LIST} = \@REGION_LIST;
        $Hash_ref->{BANK_LIST} = \@BANK_LIST;
        $Hash_ref->{BLK_LIST} = \@BLK_LIST;
        $Hash_ref->{BLK_TABLE} = \%BLK_TABLE;
    }
}
sub _parse_norflash_list #called by _ProcessFlash
{
    my ($lines_aref, $list_aref, $strSearch, $strEnd) = @_;
    my $strParsedString;
    my $bFound = undef;
    foreach my $line (@$lines_aref)
    {
        if ($line =~ /^$strSearch/)
        {
            $bFound = 1;
        }
        elsif ($bFound)
        {
            if ($line =~ /\{\s*(\S+)\s*,\s*(\S+)\s*\}/)
            {
                $strParsedString .= $line . "\n";
                push @$list_aref, [$1,$2];
            }
            last if ($line =~ /^\s*$strEnd\s*/);
        }
    }
    return $strParsedString;
}
sub _parse_flash_size  # called by _ProcessFlash
{
    my ($lines_aref, $Hash_ref) = @_;
    foreach my $line (@$lines_aref) 
    {   
        # NOR_FLASH_DENSITY = NOR_FLASH_SIZE but in different units
        # NOR_FLASH_DENSITY is only generated in nor project by emiGen
        # #define NOR_FLASH_SIZE is generated in both nand(means nand flash size) and nor project by emiGen
        if($line =~ /^\s*\*\s+NOR_FLASH_DENSITY:\s*(\w*)/) 
        {            #  * NOR_FLASH_DENSITY: 0x02000000 - got from MDL's bank/block calculation
            $Hash_ref->{NOR_FLASH_DENSITY} = $1; # in string
            $Hash_ref->{nNOR_FLASH_DENSITY} = hex($1); # in num
        }
        elsif($line =~ /^\s*\#define\s+NOR_FLASH_SIZE\s+(\w+)/)
        {                 # #define NOR_FLASH_SIZE 0x08000000
            $Hash_ref->{NOR_FLASH_SIZE} = $1;        # in string
            $Hash_ref->{nNOR_FLASH_SIZE} = hex($1);  # in num
        }
    }
}
sub _PostProcessFlashSize
{
    my ($Hash_ref, $bIsDummy) = @_;
    &DieIfNotParsing(FEATURE_CONFIG, __FILE__, __LINE__);
    if(&FileInfo::is_NonSPNOR())
    {
        if($bIsDummy)
        {
            $Hash_ref->{nCODESize} = 0x8000000;
        }
        elsif(&exist('PROJECT_EXPECTED_CODE_LIMIT', FEATURE_CONFIG))
        {
            $Hash_ref->{nCODESize} = hex(&get('PROJECT_EXPECTED_CODE_LIMIT', FEATURE_CONFIG));
        }
        else
        {
            ($Hash_ref->{nCODESize}, my $temp)  = &_GetFSInfo($Hash_ref);
        }
    }
}
sub _GetFSInfo
{
    my ($Hash_ref) = @_;
    &DieIfNotNonSPNOR(__FILE__, __LINE__);
    &DieIfNotParsing(MEMORY_DEVICE, __FILE__, __LINE__);
    my ($nFSBase, $nFSSize) = (undef, undef);
    if(&exist("NOR_BOOTING_NOR_FS_BASE_ADDRESS", MEMORY_DEVICE) and &exist("NOR_BOOTING_NOR_FS_SIZE", MEMORY_DEVICE))
    {
        $nFSBase = hex(&get("NOR_BOOTING_NOR_FS_BASE_ADDRESS", MEMORY_DEVICE));
        $nFSSize = hex(&get("NOR_BOOTING_NOR_FS_SIZE", MEMORY_DEVICE));
    }
    elsif(&exist("NOR_BOOTING_NOR_FS_BASE_ADDRESS", MEMORY_DEVICE) and !&exist("NOR_BOOTING_NOR_FS_SIZE" , MEMORY_DEVICE))
    {
        my ($nFATBase , $nFATSpace, $nSmallBlockStart) = &_GetFATInfo($Hash_ref);
        $nFSBase = hex(&get("NOR_BOOTING_NOR_FS_BASE_ADDRESS", MEMORY_DEVICE));
        $nFSSize = $nSmallBlockStart - $nFSBase;
    }
    elsif(!&exist("NOR_BOOTING_NOR_FS_BASE_ADDRESS", MEMORY_DEVICE) and &exist("NOR_BOOTING_NOR_FS_SIZE", MEMORY_DEVICE))
    {
        ($nFSBase , my $nFATSpace, my $nSmallBlockStart) = &_GetFATInfo($Hash_ref);
        $nFSSize = hex(&get("NOR_BOOTING_NOR_FS_SIZE", MEMORY_DEVICE));
    }
    else
    {
        ($nFSBase , $nFSSize, my $nSmallBlockStart) = &_GetFATInfo($Hash_ref);
    }
    ### work-around for bad small block issue
    #To correct Toshiba(NOR Flash on 36) for some small blocks which can't be used
    if((($nFSBase+$nFSSize) > $Hash_ref->{nNOR_FLASH_DENSITY}) and 
       (($nFSBase+$nFSSize) <= ($Hash_ref->{nNOR_FLASH_SIZE})))
    {
        $nFSSize = $Hash_ref->{nNOR_FLASH_DENSITY} - $nFSBase;
    }
    return ($nFSBase, $nFSSize);
}
sub _GetFATInfo ### Calculate FAT size/start address
{
    my ($Hash_ref) = @_; #parsed hash from custom_flash.h
    &DieIfNotNonSPNOR(__FILE__, __LINE__);
    &DieIfNotParsing(MEMORY_DEVICE, __FILE__, __LINE__);
    my ($Regions_aref, $BLK_aref) = ($Hash_ref->{REGION_LIST}, $Hash_ref->{BLK_LIST});
    my ($nFATBase , $nFATSpace) = (0, 0);
    my $nFlashSize = $Hash_ref->{nNOR_FLASH_DENSITY};
    my $sum_of_regions = 0;
    my $nSmallBlockStart = $nFlashSize;
    for (0..scalar(@{$Regions_aref})-1)
    {
        $sum_of_regions += hex($Regions_aref->[$_][0]) * $Regions_aref->[$_][1];
    }
    if ((scalar(@{$Regions_aref})>0) && &is("__NOR_FDM5__", "TRUE", MEMORY_DEVICE))
    {
        $nSmallBlockStart = hex($BLK_aref->[-1]->[0]);# match {0xFF0000,0x2000}
        $nFATSpace = $sum_of_regions - ($nFlashSize - $nSmallBlockStart); #To avoid Toshiba(NOR Flash) some small blocks can't be used
    }
    else
    {
        $nFATSpace = $sum_of_regions;
    }
    $nFATBase = $nFlashSize - $sum_of_regions;
    return ($nFATBase , $nFATSpace, $nSmallBlockStart);
}
sub VerifyFSInfo
{
    my ($isDummy) = @_;
    return if($isDummy or !&FileInfo::is_NonSPNOR());
    my $Flash_href = &GetSource(CUSTOM_FLASH);
    my ($nFSBase, $nFSSize) = &_GetFSInfo($Flash_href);
    
    # 1. Ensure that FS Base and Size are correct
    my $nPhysicalFlashSize = &GetPhysicalFlashEnd();
    &config_die("FAT space($nFSBase+$nFSSize) cannot exceed physical NOR flash size($nPhysicalFlashSize)!", __FILE__, __LINE__)
        if(($nFSBase < 0) or ($nFSSize < 0) or (($nFSBase+ $nFSSize) > $nPhysicalFlashSize));
    
    # 2. Ensure small block workaround
    if(&exist("__NOR_FDM5__", MEMORY_DEVICE))
    {
        my ($nFATBase , $nFATSpace, $nSmallBlockStart) = &_GetFATInfo($Flash_href);
        &config_die("FAT space($nFSBase+$nFSSize) cannot include small blocks(SmallBlockStart:$nSmallBlockStart) in NOR FDM 5.0!", __FILE__, __LINE__)
            if(($nFSBase+$nFSSize) > $nSmallBlockStart);
    } 
    
    # 3. if FS Base is defined by the customer, help to check bank/block alignment.
    if(&exist("NOR_BOOTING_NOR_FS_BASE_ADDRESS", MEMORY_DEVICE))
    {
        if(&FileInfo::is("enhanced_single_bank_nor_flash_support","TRUE"))
        {   #single-bank FAT start address needs to be block-aligned
            my $bBlockAligned = &isBlockAligned($nFSBase);
            my $BlkInfoTxt = &get("BlkInfoTxt", CUSTOM_FLASH);
            &config_die("FS Base($nFSBase) needs to be block-aligned in single-bank setting!\nBlockInfo:\n$BlkInfoTxt\n",
                        __FILE__, __LINE__)  if(!$bBlockAligned);
        }
        else
        {   #multi-bank FAT start address needs to be bank-aligned
            my ($bBankAligned, $nSum_of_banks) = &isBankAligned($nFSBase);
            &config_die("FS Base($nFSBase) needs to be bank-aligned (SumOfBank=$nSum_of_banks) in multi-bank setting!",
                        __FILE__, __LINE__) if(!$bBankAligned);
        }
    }
    # 4. Check CODE setting validity
    my $strROMLimit = &get("PROJECT_EXPECTED_CODE_LIMIT", FEATURE_CONFIG);
    &config_die("Expected ROM Limit($strROMLimit) in ".&GetMappingPath(FEATURE_CONFIG).
                                 " is larger than FS Base(".&CommonUtil::Dec2Hex($nFSBase).")!\n" , __FILE__, __LINE__)
        if(defined $strROMLimit and hex($strROMLimit) > $nFSBase);
}
sub isBlockAligned
{
    my ($nBase) = @_;
    my $BLK_aref = &get("BLK_LIST", CUSTOM_FLASH);
    my $bBlockAligned = 1;
    foreach my $nIndex (scalar(@{$BLK_aref})-1 .. 0)
    {
        if($nBase >= hex($BLK_aref->[$nIndex]->[0]))
        {
            my $nCurrentBlockSize = hex($BLK_aref->[$nIndex]->[1]);
            if(($nBase-hex($BLK_aref->[$nIndex]->[0])) % $nCurrentBlockSize)
            { # block aligned should be 0 after %
                $bBlockAligned = 0;
            }
        }
    }
    return $bBlockAligned;
}
sub isBankAligned
{
    my ($nBase) = @_;
    my $BANK_aref = &get("BANK_LIST", CUSTOM_FLASH);
    my $bBankAligned = 1;
    my $nSum_of_banks = 0;
    foreach my $nIndex (0 .. scalar(@{$BANK_aref})-1)
    {
        foreach (0 .. $BANK_aref->[$nIndex]->[1])
        {
            $nSum_of_banks += hex($BANK_aref->[$nIndex]->[0]);
            last if($nSum_of_banks >= $nBase);
        }
        last if($nSum_of_banks >= $nBase);
    }
    $bBankAligned = ($nSum_of_banks == $nBase);
    return ($bBankAligned, $nSum_of_banks);
}
sub VerifyRAMInfo
{
    my ($isDummy) = @_;
    return if($isDummy);
    # Check RAM setting validity 
    my $strRamSize = &GetPhysicalExtRAMSize(1);
    my $strRamLimit = (&FileInfo::is_NonSPNOR()) ? &get("PROJECT_EXPECTED_RAM_LIMIT", FEATURE_CONFIG)
                                                 : &get("PROJECT_EXPECTED_RAM_LIMIT_NFB", FEATURE_CONFIG) ;
    &config_die("Expected Ram Limit($strRamLimit) in ".&GetMappingPath(FEATURE_CONFIG).
                                 " is larger than physical Ram size($strRamSize)!\n" , __FILE__, __LINE__)
        if(defined $strRamLimit and hex($strRamLimit) > hex($strRamSize));
}

#****************************************************************************
# subroutine:  Get_SDS_total_size: To get the SDS total size according to the block size
# input:      $block_size : the block size for SDS
#              $feature_config_ref : a hash reference to query defined values in custom_FeatureConfig.h
#              $feature_option_ref : a hash reference to query feature options in projec.mak
# return:      $sds_total_size
#****************************************************************************
sub Get_SDS_total_size
{
    my ($block_size, $feature_config_ref, $feature_option_ref) = @_;
    my $sds_data_size  = 0;
    my $sds_spare_size = 0;
    my $sds_total_size = 0;
    $feature_config_ref = &GetSource(FEATURE_CONFIG) if(!defined $feature_config_ref);
    if(!&FileInfo::is_NonSPNOR($feature_option_ref))
    {
        $sds_data_size  = (defined $feature_config_ref->{'SDS_MAX_SIZE'}) ? hex($feature_config_ref->{'SDS_MAX_SIZE'}) : 256*1024;
        $sds_spare_size = (defined $feature_config_ref->{'SDS_RESERVED_SIZE_FOR_BBM'}) ? hex($feature_config_ref->{'SDS_RESERVED_SIZE_FOR_BBM'}) : 256*1024;
    }
    else
    {
        my $mode = $feature_option_ref->{'MODE'};
        if(!defined $block_size)
        {
            $block_size = &GetBlockSize(&GetPhysicalFlashEnd() -1, __FILE__, __LINE__);
        }
        my $two_blocks_size = 2 * $block_size; #the number of blocks for SDS need to be 2N
        
        if(defined $feature_config_ref->{'SDS_MAX_SIZE'})
        {
            $sds_data_size = hex($feature_config_ref->{'SDS_MAX_SIZE'});
        }
        elsif(($mode eq 'GSM') or ($mode eq 'GPRS'))
        {
            my $sds_temp_size = 0;
            &config_die("Input parameter: Block Size($block_size) can't be less than 1",__FILE__, __LINE__) 
                if(!defined $block_size or $block_size <= 0);
            while($sds_temp_size < 32*1024)
            {
                $sds_temp_size += $two_blocks_size;
            }
            $sds_data_size = ($block_size <=  12*1024) ? $sds_temp_size : $two_blocks_size;
        }
        else
        {
            my $sds_temp_size = 0;
            &config_die("Input parameter: Block Size($block_size) can't be less than 1",__FILE__, __LINE__) 
                if(!defined $block_size or $block_size <= 0);
            while($sds_temp_size < 128*1024)
            {
                $sds_temp_size += $two_blocks_size;
            }
            $sds_data_size = ($block_size <=  64*1024) ? $sds_temp_size : $two_blocks_size;
        }
    }
    $sds_total_size = $sds_data_size + $sds_spare_size;
    return $sds_total_size;
}
sub GetExtRamSize
{
    &DieIfNotParsing(CUSTOM_EMI, __FILE__, __LINE__);
    return &get("nPROCESSED_RAMSIZE", CUSTOM_EMI);
}
sub GetROMSize
{
    &DieIfNotParsing(CUSTOM_FLASH, __FILE__, __LINE__);
    return &get("nCODESize", CUSTOM_FLASH);
}
sub GetPhysicalExtRAMSize
{
    my ($bNeedString) = @_;
    my $ExtRamSize = &get("nEMI_EXTSRAM_SIZE", CUSTOM_EMI) ;
    $ExtRamSize = &get("strEMI_EXTSRAM_SIZE", CUSTOM_EMI) if($bNeedString);
    return $ExtRamSize;
}
sub GetPhysicalFlashEnd
{
    &DieIfNotParsing(CUSTOM_FLASH, __FILE__, __LINE__);
    return &get("nNOR_FLASH_SIZE", CUSTOM_FLASH);
}

sub GetBlockTable
{
    &DieIfNotParsing(CUSTOM_FLASH, __FILE__, __LINE__);    
    return &get("BLK_TABLE", CUSTOM_FLASH);
}

sub GetFlashInfoLog
{
    &DieIfNotParsing(CUSTOM_FLASH, __FILE__, __LINE__);
    my $Blk = &get("BlkInfoTxt", CUSTOM_FLASH);
    my $Region = &get("RegionInfoTxt", CUSTOM_FLASH);
    my $Bank = &get("BankInfoTxt", CUSTOM_FLASH);
    my $NOR_Density = &get("NOR_FLASH_DENSITY", CUSTOM_FLASH);
    my $FlashSize = &get("NOR_FLASH_SIZE", CUSTOM_FLASH);
    return ($Blk, $Region, $Bank, $NOR_Density, $FlashSize);
}

#****************************************************************************
# subroutine:  GetNextBlockAlignedAddr : Query Next Block-aligned Addr from input Addr
# input:       $nAddr : Address to the next destination
#              $bReturnItselfIfAligned : 1=if $nAddr is block aligned, return itself directly.
#                                        0=return next block aligned address against $nAddr
#              $file = __FILE__ , $line_no= __LINE__
# Output:      Next block-aligned addr
#****************************************************************************
sub GetNextBlockAlignedAddr
{
    my ($nAddr, $bReturnItselfIfAligned, $file, $line_no) = @_;
    &DieIfNotNonSPNOR($file, $line_no);
    my $nFlashSize = &GetPhysicalFlashEnd();
    &config_die("Query Block-aligned addr at ($nAddr) larger than FlashSize($nFlashSize)!", $file, $line_no) 
        if ($nAddr > $nFlashSize);

    my $nNextAddr = undef;
    my $BLK_aref = &get("BLK_LIST", CUSTOM_FLASH);
    foreach my $nIndex (scalar(@{$BLK_aref})-1 .. 0)
    {
        if($nAddr >= hex($BLK_aref->[$nIndex]->[0]))
        {
            my $nCurrentBlockSize = hex($BLK_aref->[$nIndex]->[1]);
            my $bBlockAligned = ($nAddr - hex($BLK_aref->[$nIndex]->[0])) % $nCurrentBlockSize;
            if($bBlockAligned)
            {
                $nNextAddr = $nAddr;
                $nNextAddr += $nCurrentBlockSize if(!$bReturnItselfIfAligned);
                last;
            }
            else
            {
                my $nBlocks = int(($nAddr - hex($BLK_aref->[$nIndex]->[0])) / $nCurrentBlockSize);
                $nNextAddr = hex($BLK_aref->[$nIndex]->[0]) + $nBlocks*$nCurrentBlockSize;
                last;
            }
        }
    }
    if(!defined $nNextAddr)
    {
        my $BlkInfoTxt = &get("BlkInfoTxt", CUSTOM_FLASH);
        &config_die("Can't find next Block-aligned addr. Please check block table:\n$BlkInfoTxt\n", $file, $line_no);
    }
    &config_die("Next Block-aligned addr at $nNextAddr is larger than FlashSize($nFlashSize)!", $file, $line_no) 
        if ($nNextAddr > $nFlashSize);
    return $nNextAddr;
}
sub GetBlockSize #by address
{
    my ($nAddr, $file, $line_no) = @_;
    &DieIfNotNonSPNOR($file, $line_no);
    my $nFlashSize = &GetPhysicalFlashEnd();
    &config_die("[GetBlockSize]Current Address($nAddr) can't be larger than FlashSize($nFlashSize)!", $file, $line_no) 
        if ($nAddr > $nFlashSize);
            
    my $href = &GetBlockTable();
    my @offset = sort {$b <=> $a} keys %$href;
    foreach my $i (@offset)
    {
        return $href->{$i} if ($nAddr >= $i);
    }
    my $BlkInfoTxt = &get("BlkInfoTxt", CUSTOM_FLASH);
    &config_die("Block table information:\n$BlkInfoTxt\n is not enough for Current Address($nAddr)!", $file, $line_no);
}


sub get
{
    my ($strKey, $Source) = @_;
    my $strValue = undef;
    if(defined $Source)
    {
        &DieIfNotParsing($Source, __FILE__, __LINE__);
        if(exists $g_MemConfigValues{$Source}->{$strKey})
        {
            $strValue = $g_MemConfigValues{$Source}->{$strKey};
        }
    }
    return $strValue;
}
sub GetSource
{
    my ($Source) = @_;
    &DieIfNotParsing($Source);
    return $g_MemConfigValues{$Source}; # return href
}
sub GetMemDev #MemoryDevice
{
    my ($strKey) = @_;
    return &get($strKey, MEMORY_DEVICE);
}
sub GetFtCfg #FeatureConfig
{
    my ($strKey) = @_;
    return &get($strKey, FEATURE_CONFIG);
}
sub GetPath
{
    my ($Source) = @_;
    return &get("PATH", $Source);    
}
sub GetMappingPath
{
    my ($Source) = @_;
    my $strFileName = basename(&get("PATH", $Source));
    my $strBoard = &FileInfo::get("BOARD_VER");
    my $strFlavor = &FileInfo::get("FLAVOR");
    my $strPath = "custom/system/$strBoard/$strFlavor/$strFileName\.conf";
    return $strPath;
}
sub is
{
    my ($strKey, $strValue, $Source) = @_;
    my $bIsTheSame = 0;
    if(defined $Source)
    {
        &DieIfNotParsing($Source, __FILE__, __LINE__);
        $bIsTheSame = 1 if(exists $g_MemConfigValues{$Source}->{uc($strKey)} and 
                                  $g_MemConfigValues{$Source}->{uc($strKey)} eq $strValue);
    }
    return $bIsTheSame;
}
sub exist
{
    my ($strKey, $Source) = @_;
    my $bExist = 0;
    if(defined $Source)
    {
        &DieIfNotParsing($Source, __FILE__, __LINE__);
        $bExist = 1 if(exists $g_MemConfigValues{$Source}->{uc($strKey)});
    }
    return $bExist;
}

sub config_die
{
    my ($error_msg, $file, $line_no) = @_;
    &sysUtil::error_handler($error_msg, $file, $line_no, '[Memory Config]');
}

sub DieIfNotParsing
{
    my ($Source, $file, $line_no) = @_;
    &config_die("Please parse $Source in advance.", $file, $line_no) if(!exists $g_MemConfigValues{$Source});
}

sub DieIfNotNonSPNOR
{
    my ($file, $line_no) = @_;
    &config_die("This function is unsupported on non NOR platform.", $file, $line_no) if(!&FileInfo::is_NonSPNOR());
}
