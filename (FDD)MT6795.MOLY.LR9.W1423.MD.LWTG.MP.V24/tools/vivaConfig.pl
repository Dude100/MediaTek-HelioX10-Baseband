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
#*   vivaConfig.pl
#*
#* Project:
#* --------
#*   Maui_Software
#*
#* Description:
#* ------------
#*   This file implemented the VIVA auto configure process
#*
#*
#* Author:
#* -------
#*   Ke-Ting Chen (mtk03141)
#*
#*****************************************************************************

#****************************************************************************
# Included Modules
#****************************************************************************
use strict;
use warnings;
BEGIN { push @INC, '.\\tools\\' }  # add additional library path
use auto_adjust_mem; #pm file name without case sensitivity
use File::Copy;
use File::Basename;
use vivaHelper;

#****************************************************************************
# History
#****************************************************************************
my $VIVA_CONFIG_VERNO = " v1.03";
   # v1.03: Phase in ZIMAGE_FAVOR_ROM
   # v1.02: Phase in BOOT_ZIMAGE
   # v1.01: Add AUTOCONFIG_SELF_MODIFY_SUCCESS error code support
   # v1.00: Phase in VIVA

#****************************************************************************
# Constants
#****************************************************************************
my $DEBUG = 1;

# Path
my $templateFolderPath  = "custom\\system\\Template";
my $objectListGenFolderPath = "scat_config\\FeatureBased\\ObjListGen";

# Binary
my $bootZImageBinaryName = "BOOT_ZIMAGE_ER";
my $zImageBinaryName = "ZIMAGE_ER";
my $dcmcmpBinaryName = "DYNAMIC_COMP_CODE";
my $aliceBinaryName = "ALICE";

# Normal scatter
my $objectROM1ListFileName = "objectROM1.list";
my $objectBootZImageListFileName = "objectBOOT_ZIMAGE.list";
my $objectZImageListFileName = "objectZIMAGE.list";
my $objectAliceListFileName = "objectALICE.list";

# Dummy scatter
my $objectROM1DummyListFileName = "objectROM1_dummy.list";
my $objectBootZImageDummyListFileName = "objectBOOT_ZIMAGE_dummy.list";
my $objectZImageDummyListFileName = "objectZIMAGE_dummy.list";
my $objectAliceDummyListFileName = "objectALICE_dummy.list";
my $objectAliceForbidDummyListFileName = "objectALICE_FORBID_dummy.list";

# Alignment
my $bootZImageSizeAlignment = 256;
my $zImageSizeAlignment = 256;
my $dcmcmpSizeAlignment = 256;
my $aliceSizeAlignment = 256;

my $veneerReserveRatio = 0.05;
my $smallestSplitableRAMSize = 10240;

my $separateLine = "=============================================================";

use constant CONFIG_FAIL_INSUFFICIENT_RAM => 0;
use constant CONFIG_FAIL_ZIMAGE_OVERFLOW  => 1;
use constant CONFIG_FAIL_FEATURE_NOT_ENABLED => 2;
use constant CONFIG_FAIL_NO_CONFIG_CHANGED => 3;
use constant CONFIG_FAIL_INSUFFICIENT_FLASH_SIZE => 4;
use constant CONFIG_FAIL_INSUFFICIENT_RAM_FOR_BOOT_ZIMAGE => 5;

#****************************************************************************
# Arguments
#****************************************************************************
&vivaHelper::ErrorHandler("Insufficient arguments!", __LINE__, __FILE__)
   unless scalar(@ARGV) == 7;

my $lisFilePath = $ARGV[0];
my $dummyBinaryFolder = $ARGV[1];
my $customFolder = $ARGV[2];
my $makefilePath = $ARGV[3];
my $flashConfigFilePath = $ARGV[4];
my $intermediateFilePath = $ARGV[5];
my $aapmcLogFilePath = $ARGV[6];

# To align error message file name format
$lisFilePath =~ s/^.\\|^\\//;
$dummyBinaryFolder =~ s/^.\\|^\\//;
$customFolder   =~ s/^.\\|^\\//;
$makefilePath =~ s/^.\\|^\\//;
$flashConfigFilePath =~ s/^.\\|^\\//;
$intermediateFilePath =~ s/^.\\|^\\//;
$aapmcLogFilePath =~ s/^.\\|^\\//;

# Print out the arguments
printLog($separateLine);
printLog("Arguments:");
printLog("LIS File: $lisFilePath");
printLog("Dummy Binary Folder: $dummyBinaryFolder");
printLog("Custom Folder: $customFolder");
printLog("Makefile: $makefilePath");
printLog("Flash Config File: $flashConfigFilePath");
printLog("Intermediate File: $intermediateFilePath");
printLog("");

#****************************************************************************
# Variables
#****************************************************************************
my $objectListFolder = "$customFolder\\$objectListGenFolderPath";

my $featureConfigFilePath = "$customFolder\\custom_FeatureConfig.h";

# Binary
my $bootZImageBinary = "$dummyBinaryFolder\\$bootZImageBinaryName";
my $zImageBinary = "$dummyBinaryFolder\\$zImageBinaryName";
my $dcmcmpBinary = "$dummyBinaryFolder\\$dcmcmpBinaryName";
my $aliceBinary = "$dummyBinaryFolder\\$aliceBinaryName";

# Normal scatter
my $objectROM1ListFile = "$objectListFolder\\$objectROM1ListFileName";
my $objectBootZImageListFile = "$objectListFolder\\$objectBootZImageListFileName";
my $objectZImageListFile = "$objectListFolder\\$objectZImageListFileName";
my $objectAliceListFile = "$objectListFolder\\$objectAliceListFileName";

# Dummy scatter
my $objectROM1DummyListFile = "$objectListFolder\\$objectROM1DummyListFileName";
my $objectBootZImageDummyListFile = "$objectListFolder\\$objectBootZImageDummyListFileName";
my $objectZImageDummyListFile = "$objectListFolder\\$objectZImageDummyListFileName";
my $objectAliceDummyListFile = "$objectListFolder\\$objectAliceDummyListFileName";
my $objectAliceForbidDummyListFile = "$objectListFolder\\$objectAliceForbidDummyListFileName";

#my $totalLISROMSize;
my %featureConfig;

# Feature switchs
my $bootZImageEnabled = 0;
my $zImageEnabled = 0;
my $dcmcmpEnabled = 0;
my $aliceEnabled = 0;
my $mbaEnabled = 0;

my $zImageFavorROM = 0;

# Output configurations
my $bootZImageMaxCompressedSize = 0;

my $zImageMaxCompressedSize = 0;

my $dcmcmpMaxCompressedSize = 0;
my $dcmcmpUsedROM = 0;
my $dcmcmpUsedRAM = 0;

my $aliceMaxCompressedSize = 0;

# Output object lists
my @rom1List;
my @bootZImageList;
my @zImageList;
my @aliceList;

# Configure changed
my $configChanged = 0;
my $objectListChanged = 0;

#****************************************************************************
# Initialize
#****************************************************************************
printLog($separateLine);
printLog("[Start initializing stage]");

# Initialize VIVA helper for makefile parsing and LIS parsing
&vivaHelper::Initialize(vivaHelper::CONFIG_TYPE, $makefilePath, $lisFilePath);

# Check the feature set
{
   printLog("Checking feature set...");

   my $bootZImageOption = &vivaHelper::GetMakefileOption("BOOT_ZIMAGE_SUPPORT");
   my $zImageOption = &vivaHelper::GetMakefileOption("ZIMAGE_SUPPORT");
   my $dcmcmpOption = &vivaHelper::GetMakefileOption("DCM_COMPRESSION_SUPPORT");
   my $aliceOption = &vivaHelper::GetMakefileOption("ALICE_SUPPORT");
   my $mbaOption = &vivaHelper::GetMakefileOption("MULTIPLE_BINARY_FILES");

   my $zImageFavorROMOption = &vivaHelper::GetMakefileOption("ZIMAGE_FAVOR_ROM");

   if (defined $bootZImageOption and $bootZImageOption eq "TRUE")
   {
      $bootZImageEnabled = 1;
      debugLog("BOOT_ZIMAGE is enabled");
   }

   if (defined $zImageOption and $zImageOption eq "TRUE")
   {
      $zImageEnabled = 1;
      debugLog("ZIMAGE is enabled");
   }

   if (defined $dcmcmpOption and $dcmcmpOption eq "TRUE")
   {
      $dcmcmpEnabled = 1;
      debugLog("DCM with Compression is enabled");
   }

   if (defined $aliceOption and $aliceOption eq "TRUE")
   {
      $aliceEnabled = 1;
      debugLog("ALICE is enabled");
   }

   if (defined $zImageFavorROMOption and $zImageFavorROMOption eq "TRUE")
   {
      $zImageFavorROM = 1;
      debugLog("ZIMAGE_FAVOR_ROM is enabled");
   }

   if (defined $mbaOption and $mbaOption eq "TRUE")
   {
      $mbaEnabled = 1;
      debugLog("MBA is enabled");
   }

   &configFail(CONFIG_FAIL_FEATURE_NOT_ENABLED)
      unless $zImageEnabled or $bootZImageEnabled or $aliceEnabled or $dcmcmpEnabled;
}

# Parse feature config file
printLog("Parsing feature configuration file");
&parseFeatureConfigFile(\%featureConfig);

printLog("[End initializing stage]\n");

#****************************************************************************
# Configure
#****************************************************************************
printLog($separateLine);
printLog("[Start configuration stage]");

# Note DCMCMP should be configured before BOOT_ZIMAGE, ZIMAGE, and ALICE
if($dcmcmpEnabled)
{
   $configChanged = &configDcmcmp() || $configChanged;
}

printLog("");

if ($bootZImageEnabled and $zImageEnabled and $aliceEnabled)
{
   my ($configChangedTemp, $objectListChangedTemp);
   if ($zImageFavorROM)
   {
      ($configChangedTemp, $objectListChangedTemp) = configBootZImage_ZImage_Alice_FavorROM();
   }
   else
   {
      ($configChangedTemp, $objectListChangedTemp) = configBootZImage_ZImage_Alice();
   }
   $configChanged = $configChangedTemp || $configChanged;
   $objectListChanged = $objectListChangedTemp || $objectListChanged;
}
elsif ($zImageEnabled and $aliceEnabled)
{
   my ($configChangedTemp, $objectListChangedTemp);

   if ($zImageFavorROM)
   {
      ($configChangedTemp, $objectListChangedTemp) = configZImage_Alice_FavorROM();
   }
   else
   {
      ($configChangedTemp, $objectListChangedTemp) = configZImage_Alice();
   }
   $configChanged = $configChangedTemp || $configChanged;
   $objectListChanged = $objectListChangedTemp || $objectListChanged;
}
elsif ($zImageEnabled)
{
   my ($configChangedTemp, $objectListChangedTemp);

   if ($zImageFavorROM)
   {
      ($configChangedTemp, $objectListChangedTemp) = configZImage_FavorROM();
   }
   else
   {
      ($configChangedTemp, $objectListChangedTemp) = configZImage();
   }
   $configChanged = $configChangedTemp || $configChanged;
   $objectListChanged = $objectListChangedTemp || $objectListChanged;
}
elsif ($aliceEnabled)
{
   $configChanged = &configAlice() || $configChanged;
}
else
{
   #&configFail(CONFIG_FAIL_FEATURE_NOT_ENABLED);
}

printLog("[End configuration stage]\n");

#****************************************************************************
# Output
#****************************************************************************
printLog($separateLine);
printLog("[Start output stage]");

my $outputMessage;
my %changeList;
my $result;

# Get original settings
{
   $outputMessage = "[Before auto adjustment]\n";

   if ($zImageEnabled)
   {
      my $zImageMaxCompressedSizeOriginal = &vivaHelper::DecToHex($featureConfig{"CONFIG_ZIMAGE_MAX_COMPRESSED_SIZE"});
      $outputMessage .= "CONFIG_ZIMAGE_MAX_COMPRESSED_SIZE=$zImageMaxCompressedSizeOriginal\n";
   }

   if ($bootZImageEnabled)
   {
      my $bootZImageMaxCompressedSizeOriginal = &vivaHelper::DecToHex($featureConfig{"CONFIG_BOOT_ZIMAGE_MAX_COMPRESSED_SIZE"});
      $outputMessage .= "CONFIG_BOOT_ZIMAGE_MAX_COMPRESSED_SIZE=$bootZImageMaxCompressedSizeOriginal\n";
   }

   if ($dcmcmpEnabled)
   {
      my $dcmcmpMaxCompressedSizeOriginal = &vivaHelper::DecToHex($featureConfig{"CONFIG_DCMP_MAX_COMPRESSED_SIZE"});
      $outputMessage .= "CONFIG_DCMP_MAX_COMPRESSED_SIZE=$dcmcmpMaxCompressedSizeOriginal\n";
   }

   if ($aliceEnabled)
   {
      my $aliceMaxCompressedSizeOriginal = &vivaHelper::DecToHex($featureConfig{"CONFIG_ALICE_MAX_COMPRESSED_SIZE"});
      $outputMessage .= "CONFIG_ALICE_MAX_COMPRESSED_SIZE=$aliceMaxCompressedSizeOriginal\n";
   }
}

# Get new settings and change list
{
   $outputMessage .= "[After auto adjustment]\n";

   if ($zImageEnabled)
   {
      my $zImageMaxCompressedSizeHex = &vivaHelper::DecToHex($zImageMaxCompressedSize);
      $outputMessage .= "CONFIG_ZIMAGE_MAX_COMPRESSED_SIZE=$zImageMaxCompressedSizeHex\n";
      $changeList{"CONFIG_ZIMAGE_MAX_COMPRESSED_SIZE"} = $zImageMaxCompressedSizeHex;
   }

   if ($bootZImageEnabled)
   {
      my $bootZImageMaxCompressedSizeHex = &vivaHelper::DecToHex($bootZImageMaxCompressedSize);
      $outputMessage .= "CONFIG_BOOT_ZIMAGE_MAX_COMPRESSED_SIZE=$bootZImageMaxCompressedSizeHex\n";
      $changeList{"CONFIG_BOOT_ZIMAGE_MAX_COMPRESSED_SIZE"} = $bootZImageMaxCompressedSizeHex;
   }

   if ($dcmcmpEnabled)
   {
      my $dcmcmpMaxCompressedSizeHex = &vivaHelper::DecToHex($dcmcmpMaxCompressedSize);
      $outputMessage .= "CONFIG_DCMP_MAX_COMPRESSED_SIZE=$dcmcmpMaxCompressedSizeHex\n";
      $changeList{"CONFIG_DCMP_MAX_COMPRESSED_SIZE"} = $dcmcmpMaxCompressedSizeHex;
   }

   if ($aliceEnabled)
   {
      my $aliceMaxCompressedSizeHex = &vivaHelper::DecToHex($aliceMaxCompressedSize);
      $outputMessage .= "CONFIG_ALICE_MAX_COMPRESSED_SIZE=$aliceMaxCompressedSizeHex\n";
      $changeList{"CONFIG_ALICE_MAX_COMPRESSED_SIZE"} = $aliceMaxCompressedSizeHex;
   }
}

printLog("Configuration results:");
printLog($outputMessage);

if (&isAutoConfigEnable())
{
   printLog("Auto adjusting...");

   if ($configChanged)
   {
      $result = &AAPMCLogParser::Open($aapmcLogFilePath);

      if (ERR::AAPMCLOG_SUCCESS != $result)
      {
         printLog("Cannot open AAPMC log parser!");
         return $result;
      }
      else
      {
         my $p4InfoRef = &AUTO_ADJUST::CreateP4InfoTemplate("mtk03141", "", "VIVA auto config", $outputMessage);
         my $aapmcResult;

         $result = &AAPMCLogParser::AddOneChangeRecord($featureConfigFilePath, \%changeList, \%$p4InfoRef);

         if (ERR::AAPMCLOG_SUCCESS == $result)
         {
            printLog("Modification succeeded!");
            &printIntermediateFile($outputMessage);
         }
         elsif (ERR::ERR_MODIFYDUPLICATED == $result)
         {
            printLog("Modification duplicated!");
         }
         else
         {
            printLog("Modification failed!");
         }

         $aapmcResult = &AAPMCLogParser::Close($aapmcLogFilePath);

         if (ERR::AAPMCLOG_SUCCESS != $aapmcResult)
         {
            printLog("Cannot close AAPMC log parser!");
            return $aapmcResult;
         }
      }
   }
   else
   {
      # Only object lists are changed
      $result = ERR::AUTOCONFIG_SELF_MODIFY_SUCCESS;
      &printIntermediateFile($outputMessage);
   }

   if ($objectListChanged)
   {
      printLog("Adjusting object list");

      debugLog("Adjust ROM1 object list");
      &backupFile($objectROM1ListFile);
      &vivaHelper::SortObjectList(\@rom1List);
      &vivaHelper::OutputObjectListToFile($objectROM1ListFile, \@rom1List);

      if ($bootZImageEnabled)
      {
         debugLog("Adjust BOOT_ZIMAGE object list");
         &backupFile($objectBootZImageListFile);
         &vivaHelper::SortObjectList(\@bootZImageList);
         &vivaHelper::OutputObjectListToFile($objectBootZImageListFile, \@bootZImageList);
      }

      if ($zImageEnabled)
      {
         debugLog("Adjust ZIMAGE object list");
         &backupFile($objectZImageListFile);
         &vivaHelper::SortObjectList(\@zImageList);
         &vivaHelper::OutputObjectListToFile($objectZImageListFile, \@zImageList);
      }

      if ($aliceEnabled)
      {
         debugLog("Adjust ALICE object list");
         &backupFile($objectAliceListFile);
         &vivaHelper::SortObjectList(\@aliceList);
         &vivaHelper::OutputObjectListToFile($objectAliceListFile, \@aliceList);
      }

      printLog("Adjusting object list done");
   }
}
else
{
   &printIntermediateFile($outputMessage);
   $result = ERR::NO_MODIFY;
}

printLog("Result: $result");
printLog("[End output stage]");
exit $result;

#****************************************************************************
# subroutine:  configDcmcmp
# description: Perform the DCMCMP configuration
# input:       None
# output:      DCMCMP max compressed size, changed,
#              DCMCMP used ROM size, DCMCMP used RAM size
#****************************************************************************
sub configDcmcmp
{
   printLog("Configuring DCMCMP...");

   # Assumption: same category should be put together
   my @dcmcmpRegionInfo = (
   # feature name                   category            load region                 on value
   #['BT_AUDIO_VIA_SCO',             'SharePool1',       'DYNAMIC_COMP_RESAMPLE',    'TRUE'],
   ['BT_A2DP_PROFILE',              'SharePool1',       'DYNAMIC_COMP_SBC',         'TRUE'],
   ['BES_LOUDNESS_SUPPORT',         'SharePool2',       'DYNAMIC_COMP_BESLOUDNESS', 'TRUE'],
   ['MP4_DECODE',                   'SharePool3',       'DYNAMIC_COMP_MP4DEC',      'SP'],
   ['H264_DECODE',                  'SharePool3',       'DYNAMIC_COMP_H264DEC',     'TRUE'],
   ['MP4_ENCODE',                   'SharePool3',       'DYNAMIC_COMP_MP4ENC',      'TRUE'],
   ['MP4_DECODE_PROFILE',           'SharePool3',       'DYNAMIC_COMP_MP4ASPDEC',   'ASP'],
   ['VP8_DECODE',                   'SharePool3',       'DYNAMIC_COMP_VP8DEC',      'TRUE'],
   ['VIDEO_PLAYER_RECORDER_W_DCM',  'SharePool4',       'DYNAMIC_COMP_VEENC',       'TRUE'],
   ['VIDEO_PLAYER_RECORDER_W_DCM',  'SharePool4',       'DYNAMIC_COMP_VEDEC',       'TRUE'],
   ['DAF_DECODE',                   'SharePool5',       'DYNAMIC_COMP_DAF',         'TRUE'],
   ['MELODY_VER',                   'SharePool5',       'DYNAMIC_COMP_WAVETABLE',   'DSP_WT_SYN'],
   );
   use constant FEATURE_NAME => 0;
   use constant CATEGORY => 1;
   use constant LOAD_REGION => 2;
   use constant ON_VALUE => 3;

   my %regionInfo;
   my $currentCategory = $dcmcmpRegionInfo[0][CATEGORY];
   my $categoryMaxRAM = 0;

   # Get the actual size
   foreach my $region (@dcmcmpRegionInfo)
   {
      my $option = &vivaHelper::GetMakefileOption($region->[FEATURE_NAME]);
      if (defined $option and $option eq $region->[ON_VALUE])
      {
         my %regionSize;

         &vivaHelper::GetLISLoadRegionInfo($region->[LOAD_REGION], \%regionInfo);

         $dcmcmpUsedROM += $regionInfo{"max_size"};

         debugLog("$region->[FEATURE_NAME], $region->[CATEGORY], $region->[LOAD_REGION], $region->[ON_VALUE], $regionInfo{max_size}");

         if ($currentCategory ne $region->[CATEGORY])
         {
            $dcmcmpUsedRAM += $categoryMaxRAM;
            $categoryMaxRAM = $regionInfo{"max_size"};
            $currentCategory = $region->[CATEGORY];
         }
         elsif ($categoryMaxRAM < $regionInfo{"max_size"})
         {
            $categoryMaxRAM = $regionInfo{"max_size"};
         }
      }
   }

   # Last category used RAM
   $dcmcmpUsedRAM += $categoryMaxRAM;

   # Get the compressed size
   $dcmcmpMaxCompressedSize = -s $dcmcmpBinary or
         &vivaHelper::ErrorHandler("Cannot get file size $dcmcmpBinary: $!", __FILE__, __LINE__);

   $dcmcmpMaxCompressedSize =
      &vivaHelper::RoundUpToAlignment($dcmcmpMaxCompressedSize, $dcmcmpSizeAlignment);

   debugLog("Used ROM: $dcmcmpUsedROM");
   debugLog("Used RAM: $dcmcmpUsedRAM");
   printLog("DCMCMP Max Compressed Size: ".vivaHelper::DecToHex($dcmcmpMaxCompressedSize));

   # Check whether the cofiguration is changed
   if ($featureConfig{"CONFIG_DCMP_MAX_COMPRESSED_SIZE"} == $dcmcmpMaxCompressedSize)
   {
      debugLog("DCMCMP config not changed");
      return 0;
   }
   else
   {
      debugLog("DCMCMP config changed");
      return 1;
   }
}

sub configBootZImage_ZImage_Alice
{
   printLog("Configuring BOOT_ZIMAGE, ZIMAGE, and ALICE...");

   my $rom1RegionSize;
   my $bootZImageRegionSize;
   my $zImageRegionSize;
   my $aliceRegionSize;

   my @bootZImageDummyList;
   my @aliceForbidDummyList;
   my @anyCodeDummyList;
   my @anyDataDummyList;

   my $bootZImageDummyRegionPadding;
   my $aliceForbidDummyRegionPadding;
   my $anyCodeDummyRegionPadding;
   my $anyDataDummyRegionPadding;

   my $rom1DummyRegionSize;
   my $bootZImageDummyRegionSize;
   my $zImageDummyRegionSize;
   my $aliceDummyRegionSize;
   my $aliceForbidDummyRegionSize;
   my $anyCodeDummyRegionSize;
   my $anyDataDummyRegionSize;

   my $freeRAMSize;

   my $availableRAM;

   my %variables =
      (
       '$dcmcmpUsedRAM' => ["DCMCMP Used RAM", \$dcmcmpUsedRAM],
       '$veneerReserveRatio' => ["Veneer Reserve Ratio", \$veneerReserveRatio],
       '$rom1RegionSize' => ["ROM1 Region Size", \$rom1RegionSize],
       '$bootZImageRegionSize' => ["BOOT_ZIMAGE Region Size", \$bootZImageRegionSize],
       '$zImageRegionSize' => ["ZIMAGE Region Size", \$zImageRegionSize],
       '$aliceRegionSize' => ["ALICE Region Size", \$aliceRegionSize],
       '$bootZImageDummyRegionPadding' => ["BOOT_ZIMAGE Dummy Region Padding", \$bootZImageDummyRegionPadding],
       '$aliceForbidDummyRegionPadding' => ["ALICE_FORBID Dummy Region Padding", \$aliceForbidDummyRegionPadding],
       '$anyCodeDummyRegionPadding' => ["ANY_CODE Dummy Region Padding", \$anyCodeDummyRegionPadding],
       '$anyDataDummyRegionPadding' => ["ANY_DATA Dummy Region Padding", \$anyDataDummyRegionPadding],
       '$rom1DummyRegionSize' => ["ROM1 Dummy Region Size", \$rom1DummyRegionSize],
       '$bootZImageDummyRegionSize' => ["BOOT_ZIMAGE Dummy Region Size", \$bootZImageDummyRegionSize],
       '$zImageDummyRegionSize' => ["ZIMAGE Dummy Region Size", \$zImageDummyRegionSize],
       '$aliceDummyRegionSize' => ["ALICE Dummy Region Size", \$aliceDummyRegionSize],
       '$aliceForbidDummyRegionSize' => ["ALICE_FORBID Dummy Region Size", \$aliceForbidDummyRegionSize],
       '$anyCodeDummyRegionSize' => ["ANY_CODE Dummy Region Size", \$anyCodeDummyRegionSize],
       '$anyDataDummyRegionSize' => ["ANY_DATA Dummy Region Size", \$anyDataDummyRegionSize],
       '$freeRAMSize' => ["Free RAM Size", \$freeRAMSize],
       '$availableRAM' => ["Available RAM", \$availableRAM],
      );

   my %objectLists =
      (
       '@rom1List' => ["ROM1 List", \@rom1List, '$rom1RegionSize',],
       '@bootZImageList' => ["BOOT_ZIMAGE List", \@bootZImageList, '$bootZImageRegionSize',],
       '@zImageList' => ["ZIMAGE List", \@zImageList, '$zImageRegionSize',],
       '@aliceList' => ["ALICE List", \@aliceList, '$aliceRegionSize',],
       '@bootZImageDummyList' => ["BOOT_ZIMAGE Dummy List", \@bootZImageDummyList, '$bootZImageDummyRegionSize', '$bootZImageDummyRegionPadding'],
       '@aliceForbidDummyList' => ["ALICE_FORBID Dummy List", \@aliceForbidDummyList, '$aliceForbidDummyRegionSize', '$aliceForbidDummyRegionPadding'],
       '@anyCodeDummyList' => ["ANY_CODE Dummy List", \@anyCodeDummyList, '$anyCodeDummyRegionSize', '$anyCodeDummyRegionPadding'],
       '@anyDataDummyList' => ["ANY_DATA Dummy List", \@anyDataDummyList, '$anyDataDummyRegionSize', '$anyDataDummyRegionPadding']
      );

   printLog("Get dummy scatter object lists");
   {
      # Basic
      &_inputObjectListFromFile($objectROM1DummyListFile, \@rom1List, "ROM1");
      &_inputObjectListFromFile($objectBootZImageDummyListFile, \@bootZImageList, "BOOT_ZIMAGE");
      &_inputObjectListFromFile($objectZImageDummyListFile, \@zImageList, "ZIMAGE");
      &_inputObjectListFromFile($objectAliceDummyListFile, \@aliceList, "ALICE");

      # To be added
      $bootZImageDummyRegionPadding = &_inputObjectListFromExecutionRegion("BOOT_ZIMAGE_ER", \@bootZImageDummyList, "+RO", "BOOT_ZIMAGE list");
      $aliceForbidDummyRegionPadding = &_inputObjectListFromExecutionRegion("ALICE_FORBID", \@aliceForbidDummyList, "+RO", "ALICE_FORBID list");
      $anyCodeDummyRegionPadding = &_inputObjectListFromExecutionRegion("ZIMAGE_DUMMY_CODE", \@anyCodeDummyList, "+RO-CODE", "ANY_CODE list");
      $anyDataDummyRegionPadding = &_inputObjectListFromExecutionRegion("ZIMAGE_DUMMY_DATA", \@anyDataDummyList, "+RO-DATA", "ANY_DATA list");
   }

   printLog("Get size information");
   {
      $rom1DummyRegionSize = &_getExecutionRegionInfo("ROM1", "actual_size");
      $bootZImageDummyRegionSize = &_getExecutionRegionInfo("BOOT_ZIMAGE_ER", "actual_size");
      $zImageDummyRegionSize = &_getExecutionRegionInfo("ZIMAGE_ER", "actual_size");
      $aliceDummyRegionSize = &_getExecutionRegionInfo("ALICE", "actual_size");
      $aliceForbidDummyRegionSize = &_getExecutionRegionInfo("ALICE_FORBID", "actual_size");
      $anyCodeDummyRegionSize = &_getExecutionRegionInfo("ZIMAGE_DUMMY_CODE", "actual_size");
      $anyDataDummyRegionSize = &_getExecutionRegionInfo("ZIMAGE_DUMMY_DATA", "actual_size");

      $rom1RegionSize = $rom1DummyRegionSize;
      $bootZImageRegionSize = $bootZImageDummyRegionSize;
      $zImageRegionSize = $zImageDummyRegionSize;
      $aliceRegionSize = $aliceDummyRegionSize;

      $freeRAMSize = &getFreeRAMSize();
   }

   # Configure
   {
      printLog("Compute Available RAM");

      &_evaluateAssignment('$availableRAM = ($freeRAMSize - $dcmcmpUsedRAM - $zImageDummyRegionSize) * (1 - $veneerReserveRatio)', \%variables);
      $availableRAM = int($availableRAM);

      if ($availableRAM < 0)
      {
         &configFail(CONFIG_FAIL_INSUFFICIENT_RAM, -1 * $availableRAM);
      }
      elsif ($availableRAM < $anyDataDummyRegionSize + $aliceForbidDummyRegionSize)
      {
         &configFail(CONFIG_FAIL_INSUFFICIENT_RAM_FOR_BOOT_ZIMAGE, $anyDataDummyRegionSize + $aliceForbidDummyRegionSize - $availableRAM);
      }

      # When BOOT_ZIMAGE enabled, all ALICE_FORBID and ANY_DATA list should be in ZIMAGE
      printLog("Push ALICE_FORBID List and ANY_DATA List to ZIMAGE");
      {
         &_pushToObjectList('@zImageList', '@aliceForbidDummyList', \%variables, \%objectLists);
         &_pushToObjectList('@zImageList', '@anyDataDummyList', \%variables, \%objectLists);

         &_evaluateAssignment('$availableRAM = $availableRAM - ($aliceForbidDummyRegionSize + $anyDataDummyRegionSize)', \%variables);
      }

      # The rest RAM size is then used by BOOT_ZIMAGE
      printLog("Push BOOT_ZIMAGE");
      if ($availableRAM >= $bootZImageDummyRegionSize)
      {
         debugLog("Available RAM >= BOOT_ZIMAGE_ER size");

         # All BOOT_ZIMAGE region can be put in RAM
         # No change of BOOT_ZIMAGE object list
         debugLog("BOOT_ZIMAGE list = BOOT_ZIMAGE dummy list");
         debugLog("BOOT_ZIMAGE region size = BOOT_ZIMAGE dummy size = $bootZImageDummyRegionSize");

         &_evaluateAssignment('$availableRAM = $availableRAM - $bootZImageDummyRegionSize', \%variables);
      }
      else
      {
         debugLog("Available RAM < BOOT_ZIMAGE_ER size");

         # Should split BOOT_ZIMAGE dummy list
         &vivaHelper::ChangeObjectListAttributeListByObjectList(\@bootZImageDummyList, \@bootZImageList);
         @bootZImageList = ();
         $bootZImageRegionSize = 0;

         &_splitObjectListAndPush('@bootZImageDummyList', '@bootZImageList', '@rom1List',
                                  '$availableRAM', \%variables, \%objectLists);

         if (0 == scalar(@bootZImageList))
         {
            &configFail(CONFIG_FAIL_INSUFFICIENT_RAM_FOR_BOOT_ZIMAGE, $bootZImageDummyList[-1]->{"size"});
         }

         $availableRAM = 0;
         debugLog("Available RAM = 0");
      }

      # Finally, the rest RAM is used by ZIMAGE for ANY_CODE
      printLog("Push ANY_CODE to ZIMAGE and ALICE");
      {
         &_splitObjectListAndPushByAvailableRAM('@anyCodeDummyList', '@zImageList', '@aliceList',
                                                \%variables, \%objectLists);
      }

      printLog("Compute the Max Compressed Size");
      {
         $bootZImageMaxCompressedSize = &_getRegionMaxCompressedSize("BOOT_ZIMAGE", $bootZImageRegionSize, $bootZImageDummyRegionSize, $bootZImageBinary);
         $zImageMaxCompressedSize = &_getRegionMaxCompressedSize("ZIMAGE", $zImageRegionSize, $zImageDummyRegionSize + $anyCodeDummyRegionSize + $anyDataDummyRegionSize, $zImageBinary);
         $aliceMaxCompressedSize = &_getRegionMaxCompressedSize("ALICE", $aliceRegionSize, $aliceDummyRegionSize, $aliceBinary);
      }

      $bootZImageMaxCompressedSize =
         &vivaHelper::RoundUpToAlignment($bootZImageMaxCompressedSize, $bootZImageSizeAlignment);
      $zImageMaxCompressedSize =
         &vivaHelper::RoundDownToAlignment($zImageMaxCompressedSize, $zImageSizeAlignment);
      $aliceMaxCompressedSize =
         &vivaHelper::RoundUpToAlignment($aliceMaxCompressedSize, $aliceSizeAlignment);

      printLog("BOOT_ZIMAGE Max Compressed Size: ".vivaHelper::DecToHex($bootZImageMaxCompressedSize));
      printLog("ZIMAGE Max Compressed Size: ".vivaHelper::DecToHex($zImageMaxCompressedSize));
      printLog("ALICE Max Compressed Size: ".vivaHelper::DecToHex($aliceMaxCompressedSize));
   }

   # Check whether the configurations are changed
   {
      if ($featureConfig{"CONFIG_BOOT_ZIMAGE_MAX_COMPRESSED_SIZE"} == $bootZImageMaxCompressedSize and
          $featureConfig{"CONFIG_ZIMAGE_MAX_COMPRESSED_SIZE"} == $zImageMaxCompressedSize and
          $featureConfig{"CONFIG_ALICE_MAX_COMPRESSED_SIZE"} == $aliceMaxCompressedSize)
      {
         debugLog("Config not changed");
         $configChanged = 0;
      }
      else
      {
         debugLog("Config changed");
         $configChanged = 1;
      }

      if (&_isObjectListChanged($objectROM1ListFile, \@rom1List) or
          &_isObjectListChanged($objectBootZImageListFile, \@bootZImageList) or
          &_isObjectListChanged($objectZImageListFile, \@zImageList) or
          &_isObjectListChanged($objectAliceListFile, \@aliceList))
      {
         debugLog("Object list changed");
         $objectListChanged = 1;
      }
      else
      {
         debugLog("Object list not changed");
         $objectListChanged = 0;
      }
   }

   return ($configChanged, $objectListChanged);
}

sub configZImage_Alice
{
   printLog("Configuring ZIMAGE and ALICE...");

   my $rom1RegionSize;
   my $zImageRegionSize;
   my $aliceRegionSize;

   my @aliceForbidDummyList;
   my @anyCodeDummyList;
   my @anyDataDummyList;

   my $aliceForbidDummyRegionPadding;
   my $anyCodeDummyRegionPadding;
   my $anyDataDummyRegionPadding;

   my $rom1DummyRegionSize;
   my $zImageDummyRegionSize;
   my $aliceDummyRegionSize;
   my $aliceForbidDummyRegionSize;
   my $anyCodeDummyRegionSize;
   my $anyDataDummyRegionSize;

   my $freeRAMSize;

   my $availableRAM;

   my %variables =
      (
       '$dcmcmpUsedRAM' => ["DCMCMP Used RAM", \$dcmcmpUsedRAM],
       '$veneerReserveRatio' => ["Veneer Reserve Ratio", \$veneerReserveRatio],
       '$rom1RegionSize' => ["ROM1 Region Size", \$rom1RegionSize],
       '$zImageRegionSize' => ["ZIMAGE Region Size", \$zImageRegionSize],
       '$aliceRegionSize' => ["ALICE Region Size", \$aliceRegionSize],
       '$aliceForbidDummyRegionPadding' => ["ALICE_FORBID Dummy Region Padding", \$aliceForbidDummyRegionPadding],
       '$anyCodeDummyRegionPadding' => ["ANY_CODE Dummy Region Padding", \$anyCodeDummyRegionPadding],
       '$anyDataDummyRegionPadding' => ["ANY_DATA Dummy Region Padding", \$anyDataDummyRegionPadding],
       '$rom1DummyRegionSize' => ["ROM1 Dummy Region Size", \$rom1DummyRegionSize],
       '$zImageDummyRegionSize' => ["ZIMAGE Dummy Region Size", \$zImageDummyRegionSize],
       '$aliceDummyRegionSize' => ["ALICE Dummy Region Size", \$aliceDummyRegionSize],
       '$aliceForbidDummyRegionSize' => ["ALICE_FORBID Dummy Region Size", \$aliceForbidDummyRegionSize],
       '$anyCodeDummyRegionSize' => ["ANY_CODE Dummy Region Size", \$anyCodeDummyRegionSize],
       '$anyDataDummyRegionSize' => ["ANY_DATA Dummy Region Size", \$anyDataDummyRegionSize],
       '$freeRAMSize' => ["Free RAM Size", \$freeRAMSize],
       '$availableRAM' => ["Available RAM", \$availableRAM],
      );

   my %objectLists =
      (
       '@rom1List' => ["ROM1 List", \@rom1List, '$rom1RegionSize',],
       '@zImageList' => ["ZIMAGE List", \@zImageList, '$zImageRegionSize',],
       '@aliceList' => ["ALICE List", \@aliceList, '$aliceRegionSize',],
       '@aliceForbidDummyList' => ["ALICE_FORBID Dummy List", \@aliceForbidDummyList, '$aliceForbidDummyRegionSize', '$aliceForbidDummyRegionPadding'],
       '@anyCodeDummyList' => ["ANY_CODE Dummy List", \@anyCodeDummyList, '$anyCodeDummyRegionSize', '$anyCodeDummyRegionPadding'],
       '@anyDataDummyList' => ["ANY_DATA Dummy List", \@anyDataDummyList, '$anyDataDummyRegionSize', '$anyDataDummyRegionPadding']
      );

   printLog("Get dummy scatter object lists");
   {
      # Basic
      &_inputObjectListFromFile($objectROM1DummyListFile, \@rom1List, "ROM1");
      &_inputObjectListFromFile($objectZImageDummyListFile, \@zImageList, "ZIMAGE");
      &_inputObjectListFromFile($objectAliceDummyListFile, \@aliceList, "ALICE");

      # To be added
      $aliceForbidDummyRegionPadding = &_inputObjectListFromExecutionRegion("ALICE_FORBID", \@aliceForbidDummyList, "+RO", "ALICE_FORBID list");
      $anyCodeDummyRegionPadding = &_inputObjectListFromExecutionRegion("ZIMAGE_DUMMY_CODE", \@anyCodeDummyList, "+RO-CODE", "ANY_CODE list");
      $anyDataDummyRegionPadding = &_inputObjectListFromExecutionRegion("ZIMAGE_DUMMY_DATA", \@anyDataDummyList, "+RO-DATA", "ANY_DATA list");
   }

   printLog("Get size information");
   {
      $rom1DummyRegionSize = &_getExecutionRegionInfo("ROM1", "actual_size");
      $zImageDummyRegionSize = &_getExecutionRegionInfo("ZIMAGE_ER", "actual_size");
      $aliceDummyRegionSize = &_getExecutionRegionInfo("ALICE", "actual_size");
      $aliceForbidDummyRegionSize = &_getExecutionRegionInfo("ALICE_FORBID", "actual_size");
      $anyCodeDummyRegionSize = &_getExecutionRegionInfo("ZIMAGE_DUMMY_CODE", "actual_size");
      $anyDataDummyRegionSize = &_getExecutionRegionInfo("ZIMAGE_DUMMY_DATA", "actual_size");

      $rom1RegionSize = $rom1DummyRegionSize;
      $zImageRegionSize = $zImageDummyRegionSize;
      $aliceRegionSize = $aliceDummyRegionSize;

      $freeRAMSize = &getFreeRAMSize();
   }

   # Configure
   {
      printLog("Compute Available RAM");

      &_evaluateAssignment('$availableRAM = ($freeRAMSize - $dcmcmpUsedRAM - $zImageDummyRegionSize) * (1 - $veneerReserveRatio)', \%variables);
      $availableRAM = int($availableRAM);

      if ($availableRAM < 0)
      {
         &configFail(CONFIG_FAIL_INSUFFICIENT_RAM, -1 * $availableRAM);
      }

      # The available RAM is first used to compress ALICE_FORBID list
      printLog("Push ALICE_FORBID List to ZIMAGE and ROM1");
      {
         &_splitObjectListAndPushByAvailableRAM('@aliceForbidDummyList', '@zImageList', '@rom1List',
                                                \%variables, \%objectLists);
      }

      # The rest RAM size is then used by ANY_DATA
      printLog("Push ANY_DATA to ZIMAGE and ROM1");
      {
         &_splitObjectListAndPushByAvailableRAM('@anyDataDummyList', '@zImageList', '@rom1List',
                                                \%variables, \%objectLists);
      }

      # Finally, the rest RAM is used by ZIMAGE for ANY_CODE
      printLog("Push ANY_CODE to ZIMAGE or ALICE");
      {
         &_splitObjectListAndPushByAvailableRAM('@anyCodeDummyList', '@zImageList', '@aliceList',
                                                \%variables, \%objectLists);
      }

      printLog("Compute the Max Compressed Size");
      {
         $zImageMaxCompressedSize = &_getRegionMaxCompressedSize("ZIMAGE", $zImageRegionSize, $zImageDummyRegionSize + $anyCodeDummyRegionSize + $anyDataDummyRegionSize, $zImageBinary);
         $aliceMaxCompressedSize = &_getRegionMaxCompressedSize("ALICE", $aliceRegionSize, $aliceDummyRegionSize, $aliceBinary);
      }

      $zImageMaxCompressedSize =
         &vivaHelper::RoundDownToAlignment($zImageMaxCompressedSize, $zImageSizeAlignment);
      $aliceMaxCompressedSize =
         &vivaHelper::RoundUpToAlignment($aliceMaxCompressedSize, $aliceSizeAlignment);

      printLog("ZIMAGE Max Compressed Size: ".vivaHelper::DecToHex($zImageMaxCompressedSize));
      printLog("ALICE Max Compressed Size: ".vivaHelper::DecToHex($aliceMaxCompressedSize));
   }

   # Check whether the configurations are changed
   {
      if ($featureConfig{"CONFIG_ZIMAGE_MAX_COMPRESSED_SIZE"} == $zImageMaxCompressedSize and
          $featureConfig{"CONFIG_ALICE_MAX_COMPRESSED_SIZE"} == $aliceMaxCompressedSize)
      {
         debugLog("Config not changed");
         $configChanged = 0;
      }
      else
      {
         debugLog("Config changed");
         $configChanged = 1;
      }

      if (&_isObjectListChanged($objectROM1ListFile, \@rom1List) or
          &_isObjectListChanged($objectZImageListFile, \@zImageList) or
          &_isObjectListChanged($objectAliceListFile, \@aliceList))
      {
         debugLog("Object list changed");
         $objectListChanged = 1;
      }
      else
      {
         debugLog("Object list not changed");
         $objectListChanged = 0;
      }
   }

   return ($configChanged, $objectListChanged);
}

sub configZImage
{
   printLog("Configuring ZIMAGE");

   my $rom1RegionSize;
   my $zImageRegionSize;

   my @anyCodeDummyList;
   my @anyDataDummyList;

   my $anyCodeDummyRegionPadding;
   my $anyDataDummyRegionPadding;

   my $rom1DummyRegionSize;
   my $zImageDummyRegionSize;
   my $anyCodeDummyRegionSize;
   my $anyDataDummyRegionSize;

   my $freeRAMSize;

   my $availableRAM;

   my %variables =
      (
       '$dcmcmpUsedRAM' => ["DCMCMP Used RAM", \$dcmcmpUsedRAM],
       '$veneerReserveRatio' => ["Veneer Reserve Ratio", \$veneerReserveRatio],
       '$rom1RegionSize' => ["ROM1 Region Size", \$rom1RegionSize],
       '$zImageRegionSize' => ["ZIMAGE Region Size", \$zImageRegionSize],
       '$anyCodeDummyRegionPadding' => ["ANY_CODE Dummy Region Padding", \$anyCodeDummyRegionPadding],
       '$anyDataDummyRegionPadding' => ["ANY_DATA Dummy Region Padding", \$anyDataDummyRegionPadding],
       '$rom1DummyRegionSize' => ["ROM1 Dummy Region Size", \$rom1DummyRegionSize],
       '$zImageDummyRegionSize' => ["ZIMAGE Dummy Region Size", \$zImageDummyRegionSize],
       '$anyCodeDummyRegionSize' => ["ANY_CODE Dummy Region Size", \$anyCodeDummyRegionSize],
       '$anyDataDummyRegionSize' => ["ANY_DATA Dummy Region Size", \$anyDataDummyRegionSize],
       '$freeRAMSize' => ["Free RAM Size", \$freeRAMSize],
       '$availableRAM' => ["Available RAM", \$availableRAM],
      );

   my %objectLists =
      (
       '@rom1List' => ["ROM1 List", \@rom1List, '$rom1RegionSize',],
       '@zImageList' => ["ZIMAGE List", \@zImageList, '$zImageRegionSize',],
       '@anyCodeDummyList' => ["ANY_CODE Dummy List", \@anyCodeDummyList, '$anyCodeDummyRegionSize', '$anyCodeDummyRegionPadding'],
       '@anyDataDummyList' => ["ANY_DATA Dummy List", \@anyDataDummyList, '$anyDataDummyRegionSize', '$anyDataDummyRegionPadding']
      );

   printLog("Get dummy scatter object lists");
   {
      # Basic
      &_inputObjectListFromFile($objectROM1DummyListFile, \@rom1List, "ROM1");
      &_inputObjectListFromFile($objectZImageDummyListFile, \@zImageList, "ZIMAGE");

      # To be added
      $anyCodeDummyRegionPadding = &_inputObjectListFromExecutionRegion("ZIMAGE_DUMMY_CODE", \@anyCodeDummyList, "+RO-CODE", "ANY_CODE list");
      $anyDataDummyRegionPadding = &_inputObjectListFromExecutionRegion("ZIMAGE_DUMMY_DATA", \@anyDataDummyList, "+RO-DATA", "ANY_DATA list");
   }

   printLog("Get size information");
   {
      $rom1DummyRegionSize = &_getExecutionRegionInfo("ROM1", "actual_size");
      $zImageDummyRegionSize = &_getExecutionRegionInfo("ZIMAGE_ER", "actual_size");
      $anyCodeDummyRegionSize = &_getExecutionRegionInfo("ZIMAGE_DUMMY_CODE", "actual_size");
      $anyDataDummyRegionSize = &_getExecutionRegionInfo("ZIMAGE_DUMMY_DATA", "actual_size");

      $rom1RegionSize = $rom1DummyRegionSize;
      $zImageRegionSize = $zImageDummyRegionSize;

      $freeRAMSize = &getFreeRAMSize();
   }

   # Configure
   {
      printLog("Compute Available RAM");
      &_evaluateAssignment('$availableRAM = int(($freeRAMSize - $dcmcmpUsedRAM - $zImageDummyRegionSize) * (1 - $veneerReserveRatio))', \%variables);

      if ($availableRAM < 0)
      {
         &configFail(CONFIG_FAIL_INSUFFICIENT_RAM, -1 * $availableRAM);
      }

      # The rest RAM size is first used by ANY_DATA
      printLog("Push ANY_DATA to ZIMAGE and ROM1");
      {
         &_splitObjectListAndPushByAvailableRAM('@anyDataDummyList', '@zImageList', '@rom1List',
                                                \%variables, \%objectLists);
      }

      # Finally, the rest RAM is used by ZIMAGE for ANY_CODE
      printLog("Push ANY_CODE to ZIMAGE or ROM1");
      {
         &_splitObjectListAndPushByAvailableRAM('@anyCodeDummyList', '@zImageList', '@rom1List',
                                                \%variables, \%objectLists);
      }

      printLog("Compute the Max Compressed Size");
      {
         $zImageMaxCompressedSize = &_getRegionMaxCompressedSize("ZIMAGE", $zImageRegionSize, $zImageDummyRegionSize + $anyCodeDummyRegionSize + $anyDataDummyRegionSize, $zImageBinary);
      }

      $zImageMaxCompressedSize =
         &vivaHelper::RoundDownToAlignment($zImageMaxCompressedSize, $zImageSizeAlignment);

      printLog("ZIMAGE Max Compressed Size: ".vivaHelper::DecToHex($zImageMaxCompressedSize));
   }

   # Check whether the configurations are changed
   {
      if ($featureConfig{"CONFIG_ZIMAGE_MAX_COMPRESSED_SIZE"} == $zImageMaxCompressedSize)
      {
         debugLog("Config not changed");
         $configChanged = 0;
      }
      else
      {
         debugLog("Config changed");
         $configChanged = 1;
      }

      if (&_isObjectListChanged($objectROM1ListFile, \@rom1List) or
          &_isObjectListChanged($objectZImageListFile, \@zImageList))
      {
         debugLog("Object list changed");
         $objectListChanged = 1;
      }
      else
      {
         debugLog("Object list not changed");
         $objectListChanged = 0;
      }
   }

   return ($configChanged, $objectListChanged);
}

sub configAlice
{
   printLog("Configuring ZIMAGE");

   my $aliceDummyRegionSize = &_getExecutionRegionInfo("ALICE", "actual_size");
   $aliceMaxCompressedSize = &_getRegionMaxCompressedSize("ALICE", $aliceDummyRegionSize, $aliceDummyRegionSize, $aliceBinary);

   if ($mbaEnabled)
   {
      $aliceMaxCompressedSize = $aliceMaxCompressedSize * (1 + 0.02);
      debugLog("MBA is enabled");
      debugLog("Alice Max Compressed Size = Alice Max Compressed Size * (1 + Veneer Reserved Ratio)");
      debugLog("   = $aliceMaxCompressedSize");
   }

   $aliceMaxCompressedSize =
      &vivaHelper::RoundUpToAlignment($aliceMaxCompressedSize, $aliceSizeAlignment);

   printLog("ALICE Max Compressed Size: ".vivaHelper::DecToHex($aliceMaxCompressedSize));
   if ($featureConfig{"CONFIG_ALICE_MAX_COMPRESSED_SIZE"} == $aliceMaxCompressedSize)
   {
      debugLog("Config not changed");
      $configChanged = 0;
   }
   else
   {
      debugLog("Config changed");
      $configChanged = 1;
   }

   return $configChanged;
}

sub _inputObjectListFromFile
{
   my $filename = shift;
   my $listRef = shift;
   my $listName = shift;
   my @filePath = fileparse($filename);

   &vivaHelper::InputObjectListFromFile($filename, $listRef);
   debugLog("Input $listName list from $filePath[0]");
}

sub _inputObjectListFromExecutionRegion
{
   my $regionName = shift;
   my $listRef = shift;
   my $defaultAttribute = shift;
   my $defaultCategory = shift;
   my $padding = 0;

   $padding = &vivaHelper::GetLISExecutionRegionObjectList($regionName, $listRef, $defaultAttribute, $defaultCategory);
   debugLog("Get $regionName list from LIS execution region, padding = $padding");
   return $padding;
}

sub _getExecutionRegionInfo
{
   my $regionName = shift;
   my $infoName = shift;
   my %regionInfo;
   my $result;

   &vivaHelper::GetLISExecutionRegionInfo($regionName, \%regionInfo);
   $result = $regionInfo{$infoName};
   debugLog("$regionName execution region $infoName = $result");

   return $result;
}

sub _getRegionMaxCompressedSize
{
   my $regionName = shift;
   my $regionSize = shift;
   my $dummyRegionSize = shift;
   my $dummyCompressedBinary = shift;

   my $dummyCompressedSize = -s $dummyCompressedBinary or
      &vivaHelper::ErrorHandler("Cannot get file size $dummyCompressedBinary: $!", __FILE__, __LINE__);
   #debugLog("$regionName Dummy Region Size = $dummyRegionSize");
   #debugLog("$regionName Dummy Compressed Binary Size = $dummyCompressedSize");

   my $compressionRatio = $dummyCompressedSize / $dummyRegionSize;
   #debugLog("$regionName Compression Ratio = $regionName Dummy Compressed Binary Size / $regionName Dummy Region Size");
   #debugLog("   = $dummyCompressedSize / $dummyRegionSize");
   #debugLog("   = $compressionRatio");

   my $maxCompressedSize = int($regionSize * $compressionRatio + 0.99);
   debugLog("$regionName max compressed size = $regionName Region Size * $regionName Compression Ratio");
   debugLog("   = $regionSize * $compressionRatio");
   debugLog("   = $maxCompressedSize");

   return $maxCompressedSize;
}

sub _pushToObjectList
{
   my $targetList = shift;
   my $sourceList = shift;

   my $variables = shift;
   my $objectLists = shift;

   push @{$objectLists->{$targetList}[1]}, @{$objectLists->{$sourceList}[1]};
   debugLog("$objectLists->{$targetList}[0] += $objectLists->{$sourceList}[0]");
   _evaluateAssignment("$objectLists->{$targetList}[2] = $objectLists->{$targetList}[2] + $objectLists->{$sourceList}[2]", $variables);
}

sub _splitObjectListAndPush
{
   my $sourceList = shift;
   my $firstList = shift;
   my $secondList = shift;

   my $splitSize = shift;

   my $variables = shift;
   my $objectLists = shift;

   my $splitSizeWithVeneer;
   my $actualSplitSize;

   my @list1;
   my @list2;

   $variables->{'$splitSizeWithVeneer'} = ["Splitted Size with Veneer", \$splitSizeWithVeneer];
   $variables->{'$actualSplitSize'} = ["Actual Splitted Size", \$actualSplitSize];

   #$objectLists->{'@list1'} = ["Splitted List", \@list1, '$actualSplitSize * (1 + $veneerReserveRatio)'];
   $objectLists->{'@list1'} = ["Splitted List", \@list1, '$actualSplitSize + '."$objectLists->{$sourceList}[3]"];
   $objectLists->{'@list2'} = ["Rest List", \@list2, "$objectLists->{$sourceList}[2]".' - $actualSplitSize'];

   debugLog("Split $objectLists->{$sourceList}[0]");

   #&_evaluateAssignment('$splitSizeWithVeneer = '."$splitSize".' * (1 + $veneerReserveRatio)', $variables);
   &_evaluateAssignment('$splitSizeWithVeneer = '."$splitSize", $variables);
   $splitSizeWithVeneer = int($splitSizeWithVeneer);

   $actualSplitSize = &vivaHelper::SplitObjectListBySize($objectLists->{$sourceList}[1], $splitSizeWithVeneer,
                                                         \@list1, \@list2);
   debugLog("Actual Splitted Size = $actualSplitSize");

   &_pushToObjectList($firstList, '@list1', $variables, $objectLists);
   &_pushToObjectList($secondList, '@list2', $variables, $objectLists);

   delete $variables->{'$splitSizeWithVeneer'};
   delete $variables->{'$actualSplitSize'};

   delete $objectLists->{'@list1'};
   delete $objectLists->{'@list2'};

   return $actualSplitSize;
}

sub _splitObjectListAndPushByAvailableRAM
{
   my $sourceList = shift;
   my $firstList = shift;
   my $secondList = shift;

   my $variables = shift;
   my $objectLists = shift;

   if (${$variables->{'$availableRAM'}[1]} < $smallestSplitableRAMSize and ${$variables->{'$availableRAM'}[1]} != 0)
   {
      debugLog("Available RAM < Smallest Splitable RAM");
      debugLog("   = $smallestSplitableRAMSize");
      ${$variables->{'$availableRAM'}[1]} = 0;
      debugLog("Available RAM = 0");
   }

   &_splitObjectListAndPush($sourceList, $firstList, $secondList,
                            '$availableRAM', $variables, $objectLists);

   if (${$variables->{'$availableRAM'}[1]} >= ${$variables->{$objectLists->{$sourceList}[2]}[1]})
   {
      &_evaluateAssignment('$availableRAM = $availableRAM - '."$objectLists->{$sourceList}[2]", $variables);
   }
   else
   {
      ${$variables->{'$availableRAM'}[1]} = 0;
      debugLog("Available RAM = 0");
   }
}

sub _evaluateAssignment
{
   my $assignmentString = shift;
   my $variables = shift;
   my @assignment = split(/=/, $assignmentString);

   my $symbolString = $assignmentString;

   $assignment[0] =~ s/(?:^ +)||(?: +$)//g;
   $assignment[1] =~ s/(?:^ +)||(?: +$)//g;

   my $evaluationString = $assignment[1];

   while (my ($key, $value)= each %$variables)
   {
      my $matchSymbol = "\\$key";
      $symbolString =~ s/$matchSymbol/$value->[0]/g;
      $evaluationString =~ s/$matchSymbol/${$value->[1]}/g;
   }

   my $intermediate = eval{$evaluationString};
   my $assigneeRef = $variables->{$assignment[0]}[1];

   $$assigneeRef = eval ($evaluationString);

   debugLog($symbolString);
   debugLog("   = $intermediate");
   debugLog("   = $$assigneeRef");
}

sub _isObjectListChanged
{
   my $objectListFile = shift;
   my $objectListRef = shift;

   my @objectListOriginal;

   &vivaHelper::InputObjectListFromFile($objectListFile, \@objectListOriginal);

   if (&vivaHelper::CompareObjectList(\@objectListOriginal, $objectListRef) == 0)
   {
      return 0;
   }
   else
   {
      return 1;
   }
}

sub configBootZImage_ZImage_Alice_FavorROM
{
   printLog("Configuring BOOT_ZIMAGE, ZIMAGE, and ALICE favoring ROM...");

   my $rom1RegionSize;
   my $bootZImageRegionSize;
   my $zImageRegionSize;
   my $aliceRegionSize;

   my @bootZImageDummyList;
   my @aliceForbidDummyList;
   my @anyCodeDummyList;
   my @anyDataDummyList;

   my $bootZImageDummyRegionPadding;
   my $aliceForbidDummyRegionPadding;
   my $anyCodeDummyRegionPadding;
   my $anyDataDummyRegionPadding;

   my $rom1DummyRegionSize;
   my $bootZImageDummyRegionSize;
   my $zImageDummyRegionSize;
   my $aliceDummyRegionSize;
   my $aliceForbidDummyRegionSize;
   my $anyCodeDummyRegionSize;
   my $anyDataDummyRegionSize;

   my $bootZImageDummyCompressionRatio;
   my $zImageDummyCompressionRatio;
   my $aliceDummyCompressionRatio;

   my $freeRAMSize;

   my $availableRAM;

   my $exceedROMSize;

   my $targetSplitSize;

   my %variables =
      (
       '$dcmcmpUsedRAM' => ["DCMCMP Used RAM", \$dcmcmpUsedRAM],
       '$veneerReserveRatio' => ["Veneer Reserve Ratio", \$veneerReserveRatio],
       '$rom1RegionSize' => ["ROM1 Region Size", \$rom1RegionSize],
       '$bootZImageRegionSize' => ["BOOT_ZIMAGE Region Size", \$bootZImageRegionSize],
       '$zImageRegionSize' => ["ZIMAGE Region Size", \$zImageRegionSize],
       '$aliceRegionSize' => ["ALICE Region Size", \$aliceRegionSize],
       '$bootZImageDummyRegionPadding' => ["BOOT_ZIMAGE Dummy Region Padding", \$bootZImageDummyRegionPadding],
       '$aliceForbidDummyRegionPadding' => ["ALICE_FORBID Dummy Region Padding", \$aliceForbidDummyRegionPadding],
       '$anyCodeDummyRegionPadding' => ["ANY_CODE Dummy Region Padding", \$anyCodeDummyRegionPadding],
       '$anyDataDummyRegionPadding' => ["ANY_DATA Dummy Region Padding", \$anyDataDummyRegionPadding],
       '$rom1DummyRegionSize' => ["ROM1 Dummy Region Size", \$rom1DummyRegionSize],
       '$bootZImageDummyRegionSize' => ["BOOT_ZIMAGE Dummy Region Size", \$bootZImageDummyRegionSize],
       '$zImageDummyRegionSize' => ["ZIMAGE Dummy Region Size", \$zImageDummyRegionSize],
       '$aliceDummyRegionSize' => ["ALICE Dummy Region Size", \$aliceDummyRegionSize],
       '$aliceForbidDummyRegionSize' => ["ALICE_FORBID Dummy Region Size", \$aliceForbidDummyRegionSize],
       '$anyCodeDummyRegionSize' => ["ANY_CODE Dummy Region Size", \$anyCodeDummyRegionSize],
       '$anyDataDummyRegionSize' => ["ANY_DATA Dummy Region Size", \$anyDataDummyRegionSize],
       '$bootZImageDummyCompressionRatio' => ["BOOT_ZIMAGE Dummy Compression Ratio", \$bootZImageDummyCompressionRatio],
       '$zImageDummyCompressionRatio' => ["ZIMAGE Dummy Compression Ratio", \$zImageDummyCompressionRatio],
       '$aliceDummyCompressionRatio' => ["ALICE Dummy Compression Ratio", \$aliceDummyCompressionRatio],
       '$freeRAMSize' => ["Free RAM Size", \$freeRAMSize],
       '$availableRAM' => ["Available RAM", \$availableRAM],
       '$exceedROMSize' => ["Exceed ROM Size", \$exceedROMSize],
       '$targetSplitSize' => ["Target Split Size", \$targetSplitSize],
      );

   my %objectLists =
      (
       '@rom1List' => ["ROM1 List", \@rom1List, '$rom1RegionSize',],
       '@bootZImageList' => ["BOOT_ZIMAGE List", \@bootZImageList, '$bootZImageRegionSize',],
       '@zImageList' => ["ZIMAGE List", \@zImageList, '$zImageRegionSize',],
       '@aliceList' => ["ALICE List", \@aliceList, '$aliceRegionSize',],
       '@bootZImageDummyList' => ["BOOT_ZIMAGE Dummy List", \@bootZImageDummyList, '$bootZImageDummyRegionSize', '$bootZImageDummyRegionPadding'],
       '@aliceForbidDummyList' => ["ALICE_FORBID Dummy List", \@aliceForbidDummyList, '$aliceForbidDummyRegionSize', '$aliceForbidDummyRegionPadding'],
       '@anyCodeDummyList' => ["ANY_CODE Dummy List", \@anyCodeDummyList, '$anyCodeDummyRegionSize', '$anyCodeDummyRegionPadding'],
       '@anyDataDummyList' => ["ANY_DATA Dummy List", \@anyDataDummyList, '$anyDataDummyRegionSize', '$anyDataDummyRegionPadding']
      );

   printLog("Get dummy scatter object lists");
   {
      # Basic
      &_inputObjectListFromFile($objectROM1DummyListFile, \@rom1List, "ROM1");
      &_inputObjectListFromFile($objectBootZImageDummyListFile, \@bootZImageList, "BOOT_ZIMAGE");
      &_inputObjectListFromFile($objectZImageDummyListFile, \@zImageList, "ZIMAGE");
      &_inputObjectListFromFile($objectAliceDummyListFile, \@aliceList, "ALICE");

      # To be added
      $bootZImageDummyRegionPadding = &_inputObjectListFromExecutionRegion("BOOT_ZIMAGE_ER", \@bootZImageDummyList, "+RO", "BOOT_ZIMAGE list");
      $aliceForbidDummyRegionPadding = &_inputObjectListFromExecutionRegion("ALICE_FORBID", \@aliceForbidDummyList, "+RO", "ALICE_FORBID list");
      $anyCodeDummyRegionPadding = &_inputObjectListFromExecutionRegion("ZIMAGE_DUMMY_CODE", \@anyCodeDummyList, "+RO-CODE", "ANY_CODE list");
      $anyDataDummyRegionPadding = &_inputObjectListFromExecutionRegion("ZIMAGE_DUMMY_DATA", \@anyDataDummyList, "+RO-DATA", "ANY_DATA list");
   }

   printLog("Get size information");
   {
      $rom1DummyRegionSize = &_getExecutionRegionInfo("ROM1", "actual_size");
      $bootZImageDummyRegionSize = &_getExecutionRegionInfo("BOOT_ZIMAGE_ER", "actual_size");
      $zImageDummyRegionSize = &_getExecutionRegionInfo("ZIMAGE_ER", "actual_size");
      $aliceDummyRegionSize = &_getExecutionRegionInfo("ALICE", "actual_size");
      $aliceForbidDummyRegionSize = &_getExecutionRegionInfo("ALICE_FORBID", "actual_size");
      $anyCodeDummyRegionSize = &_getExecutionRegionInfo("ZIMAGE_DUMMY_CODE", "actual_size");
      $anyDataDummyRegionSize = &_getExecutionRegionInfo("ZIMAGE_DUMMY_DATA", "actual_size");

      $rom1RegionSize = $rom1DummyRegionSize;
      $bootZImageRegionSize = $bootZImageDummyRegionSize;
      $zImageRegionSize = $zImageDummyRegionSize;
      $aliceRegionSize = $aliceDummyRegionSize;

      $freeRAMSize = &getFreeRAMSize();

      $exceedROMSize = &getExceedROMSize();
   }

   # Configure
   {
      printLog("Compute Available RAM");

      &_evaluateAssignment('$availableRAM = ($freeRAMSize - $dcmcmpUsedRAM - $zImageDummyRegionSize) * (1 - $veneerReserveRatio)', \%variables);
      $availableRAM = int($availableRAM);

      if ($availableRAM < 0)
      {
         &configFail(CONFIG_FAIL_INSUFFICIENT_RAM, -1 * $availableRAM);
      }

      # Compute the compression ratios
      printLog("Compute the compression ratios");
      {
         $bootZImageDummyCompressionRatio = &_getCompressionRatio("BOOT_ZIMAGE", $bootZImageDummyRegionSize, $bootZImageBinary);
         $zImageDummyCompressionRatio = &_getCompressionRatio("ZIMAGE", $zImageDummyRegionSize + $anyCodeDummyRegionSize + $anyDataDummyRegionSize, $zImageBinary);
         $aliceDummyCompressionRatio = &_getCompressionRatio("ALICE", $aliceDummyRegionSize, $aliceBinary);
      }

      # Assume ANY_CODE in ALICE
      printLog("Assume ANY_CODE are all in ALICE");
      {
         &_evaluateAssignment('$exceedROMSize = int($exceedROMSize - $anyCodeDummyRegionSize * (1 - $aliceDummyCompressionRatio))', \%variables);

         if ($exceedROMSize > $availableRAM * (1 - $zImageDummyCompressionRatio))
         {
            debugLog("Exceed ROM Size > Available RAM * (1 - ZIMAGE Dummy Compression Ratio)");
            debugLog("   = $availableRAM * (1 - $zImageDummyCompressionRatio)");
            debugLog("   = ".($availableRAM * (1 - $zImageDummyCompressionRatio)));
            &configFail(CONFIG_FAIL_INSUFFICIENT_RAM, $exceedROMSize / (1 - $zImageDummyCompressionRatio) - $availableRAM);
         }
      }

      # Push ALICE_FORBID to ZIMAGE or ROM1
      &_splitObjectListAndPushByExceedROM('@aliceForbidDummyList', '@zImageList', '@rom1List',
                                          '$zImageDummyCompressionRatio', \%variables, \%objectLists);

      # Push ANY_DATA to ZIMAGE or ROM1
      &_splitObjectListAndPushByExceedROM('@anyDataDummyList', '@zImageList', '@rom1List',
                                          '$zImageDummyCompressionRatio', \%variables, \%objectLists);

      # Push BOOT_ZIMAGE Dummy to BOOT_ZIMAGE or ROM1
      &vivaHelper::ChangeObjectListAttributeListByObjectList(\@bootZImageDummyList, \@bootZImageList);
      @bootZImageList = pop @bootZImageDummyList; # Push at least one entry to BOOT_ZIMAGE to prevent empty
      $bootZImageRegionSize = 0;
      &_splitObjectListAndPushByExceedROM('@bootZImageDummyList', '@bootZImageList', '@rom1List',
                                          '$bootZImageDummyCompressionRatio', \%variables, \%objectLists);

      # Push ANY_CODE to ZIMAGE or ALICE
      &_splitObjectListAndPushByExceedROM('@anyCodeDummyList', '@zImageList', '@aliceList',
                                          '$aliceDummyCompressionRatio - $zImageDummyCompressionRatio', \%variables, \%objectLists);

      #if ($exceedROMSize > 0)
      #{
      #   &configFail(CONFIG_FAIL_INSUFFICIENT_FLASH_SIZE, $exceedROMSize);
      #}

      printLog("Compute the Max Compressed Size");
      {
         $bootZImageMaxCompressedSize = &_getRegionMaxCompressedSize("BOOT_ZIMAGE", $bootZImageRegionSize, $bootZImageDummyRegionSize, $bootZImageBinary);
         $zImageMaxCompressedSize = &_getRegionMaxCompressedSize("ZIMAGE", $zImageRegionSize, $zImageDummyRegionSize + $anyCodeDummyRegionSize + $anyDataDummyRegionSize, $zImageBinary);
         $aliceMaxCompressedSize = &_getRegionMaxCompressedSize("ALICE", $aliceRegionSize, $aliceDummyRegionSize, $aliceBinary);
      }

      $bootZImageMaxCompressedSize =
         &vivaHelper::RoundUpToAlignment($bootZImageMaxCompressedSize, $bootZImageSizeAlignment);
      $zImageMaxCompressedSize =
         &vivaHelper::RoundDownToAlignment($zImageMaxCompressedSize, $zImageSizeAlignment);
      $aliceMaxCompressedSize =
         &vivaHelper::RoundUpToAlignment($aliceMaxCompressedSize, $aliceSizeAlignment);

      printLog("BOOT_ZIMAGE Max Compressed Size: ".vivaHelper::DecToHex($bootZImageMaxCompressedSize));
      printLog("ZIMAGE Max Compressed Size: ".vivaHelper::DecToHex($zImageMaxCompressedSize));
      printLog("ALICE Max Compressed Size: ".vivaHelper::DecToHex($aliceMaxCompressedSize));
   }

   # Check whether the configurations are changed
   {
      if ($featureConfig{"CONFIG_BOOT_ZIMAGE_MAX_COMPRESSED_SIZE"} == $bootZImageMaxCompressedSize and
          $featureConfig{"CONFIG_ZIMAGE_MAX_COMPRESSED_SIZE"} == $zImageMaxCompressedSize and
          $featureConfig{"CONFIG_ALICE_MAX_COMPRESSED_SIZE"} == $aliceMaxCompressedSize)
      {
         debugLog("Config not changed");
         $configChanged = 0;
      }
      else
      {
         debugLog("Config changed");
         $configChanged = 1;
      }

      if (&_isObjectListChanged($objectROM1ListFile, \@rom1List) or
          &_isObjectListChanged($objectBootZImageListFile, \@bootZImageList) or
          &_isObjectListChanged($objectZImageListFile, \@zImageList) or
          &_isObjectListChanged($objectAliceListFile, \@aliceList))
      {
         debugLog("Object list changed");
         $objectListChanged = 1;
      }
      else
      {
         debugLog("Object list not changed");
         $objectListChanged = 0;
      }
   }

   return ($configChanged, $objectListChanged);
}

sub configZImage_Alice_FavorROM
{
   printLog("Configuring ZIMAGE and ALICE favoring ROM...");

   my $rom1RegionSize;
   my $zImageRegionSize;
   my $aliceRegionSize;

   my @aliceForbidDummyList;
   my @anyCodeDummyList;
   my @anyDataDummyList;

   my $aliceForbidDummyRegionPadding;
   my $anyCodeDummyRegionPadding;
   my $anyDataDummyRegionPadding;

   my $rom1DummyRegionSize;
   my $zImageDummyRegionSize;
   my $aliceDummyRegionSize;
   my $aliceForbidDummyRegionSize;
   my $anyCodeDummyRegionSize;
   my $anyDataDummyRegionSize;

   my $zImageDummyCompressionRatio;
   my $aliceDummyCompressionRatio;

   my $freeRAMSize;

   my $availableRAM;

   my $exceedROMSize;

   my $targetSplitSize;

   my %variables =
      (
       '$dcmcmpUsedRAM' => ["DCMCMP Used RAM", \$dcmcmpUsedRAM],
       '$veneerReserveRatio' => ["Veneer Reserve Ratio", \$veneerReserveRatio],
       '$rom1RegionSize' => ["ROM1 Region Size", \$rom1RegionSize],
       '$zImageRegionSize' => ["ZIMAGE Region Size", \$zImageRegionSize],
       '$aliceRegionSize' => ["ALICE Region Size", \$aliceRegionSize],
       '$aliceForbidDummyRegionPadding' => ["ALICE_FORBID Dummy Region Padding", \$aliceForbidDummyRegionPadding],
       '$anyCodeDummyRegionPadding' => ["ANY_CODE Dummy Region Padding", \$anyCodeDummyRegionPadding],
       '$anyDataDummyRegionPadding' => ["ANY_DATA Dummy Region Padding", \$anyDataDummyRegionPadding],
       '$rom1DummyRegionSize' => ["ROM1 Dummy Region Size", \$rom1DummyRegionSize],
       '$zImageDummyRegionSize' => ["ZIMAGE Dummy Region Size", \$zImageDummyRegionSize],
       '$aliceDummyRegionSize' => ["ALICE Dummy Region Size", \$aliceDummyRegionSize],
       '$aliceForbidDummyRegionSize' => ["ALICE_FORBID Dummy Region Size", \$aliceForbidDummyRegionSize],
       '$anyCodeDummyRegionSize' => ["ANY_CODE Dummy Region Size", \$anyCodeDummyRegionSize],
       '$anyDataDummyRegionSize' => ["ANY_DATA Dummy Region Size", \$anyDataDummyRegionSize],
       '$zImageDummyCompressionRatio' => ["ZIMAGE Dummy Compression Ratio", \$zImageDummyCompressionRatio],
       '$aliceDummyCompressionRatio' => ["ALICE Dummy Compression Ratio", \$aliceDummyCompressionRatio],
       '$freeRAMSize' => ["Free RAM Size", \$freeRAMSize],
       '$availableRAM' => ["Available RAM", \$availableRAM],
       '$exceedROMSize' => ["Exceed ROM Size", \$exceedROMSize],
       '$targetSplitSize' => ["Target Split Size", \$targetSplitSize],
      );

   my %objectLists =
      (
       '@rom1List' => ["ROM1 List", \@rom1List, '$rom1RegionSize',],
       '@zImageList' => ["ZIMAGE List", \@zImageList, '$zImageRegionSize',],
       '@aliceList' => ["ALICE List", \@aliceList, '$aliceRegionSize',],
       '@aliceForbidDummyList' => ["ALICE_FORBID Dummy List", \@aliceForbidDummyList, '$aliceForbidDummyRegionSize', '$aliceForbidDummyRegionPadding'],
       '@anyCodeDummyList' => ["ANY_CODE Dummy List", \@anyCodeDummyList, '$anyCodeDummyRegionSize', '$anyCodeDummyRegionPadding'],
       '@anyDataDummyList' => ["ANY_DATA Dummy List", \@anyDataDummyList, '$anyDataDummyRegionSize', '$anyDataDummyRegionPadding']
      );

   printLog("Get dummy scatter object lists");
   {
      # Basic
      &_inputObjectListFromFile($objectROM1DummyListFile, \@rom1List, "ROM1");
      &_inputObjectListFromFile($objectZImageDummyListFile, \@zImageList, "ZIMAGE");
      &_inputObjectListFromFile($objectAliceDummyListFile, \@aliceList, "ALICE");

      # To be added
      $aliceForbidDummyRegionPadding = &_inputObjectListFromExecutionRegion("ALICE_FORBID", \@aliceForbidDummyList, "+RO", "ALICE_FORBID list");
      $anyCodeDummyRegionPadding = &_inputObjectListFromExecutionRegion("ZIMAGE_DUMMY_CODE", \@anyCodeDummyList, "+RO-CODE", "ANY_CODE list");
      $anyDataDummyRegionPadding = &_inputObjectListFromExecutionRegion("ZIMAGE_DUMMY_DATA", \@anyDataDummyList, "+RO-DATA", "ANY_DATA list");
   }

   printLog("Get size information");
   {
      $rom1DummyRegionSize = &_getExecutionRegionInfo("ROM1", "actual_size");
      $zImageDummyRegionSize = &_getExecutionRegionInfo("ZIMAGE_ER", "actual_size");
      $aliceDummyRegionSize = &_getExecutionRegionInfo("ALICE", "actual_size");
      $aliceForbidDummyRegionSize = &_getExecutionRegionInfo("ALICE_FORBID", "actual_size");
      $anyCodeDummyRegionSize = &_getExecutionRegionInfo("ZIMAGE_DUMMY_CODE", "actual_size");
      $anyDataDummyRegionSize = &_getExecutionRegionInfo("ZIMAGE_DUMMY_DATA", "actual_size");

      $rom1RegionSize = $rom1DummyRegionSize;
      $zImageRegionSize = $zImageDummyRegionSize;
      $aliceRegionSize = $aliceDummyRegionSize;

      $freeRAMSize = &getFreeRAMSize();

      $exceedROMSize = &getExceedROMSize();
   }

   # Configure
   {
      printLog("Compute Available RAM");
      &_evaluateAssignment('$availableRAM = int(($freeRAMSize - $dcmcmpUsedRAM - $zImageDummyRegionSize) * (1 - $veneerReserveRatio))', \%variables);

      if ($availableRAM < 0)
      {
         &configFail(CONFIG_FAIL_INSUFFICIENT_RAM, -1 * $availableRAM);
      }

      # Compute the compression ratios
      printLog("Compute the compression ratios");
      {
         $zImageDummyCompressionRatio = &_getCompressionRatio("ZIMAGE", $zImageDummyRegionSize + $anyCodeDummyRegionSize + $anyDataDummyRegionSize, $zImageBinary);
         $aliceDummyCompressionRatio = &_getCompressionRatio("ALICE", $aliceDummyRegionSize, $aliceBinary);
      }

      # Assume ANY_CODE in ALICE
      printLog("Assume ANY_CODE are all in ALICE");
      {
         &_evaluateAssignment('$exceedROMSize = int($exceedROMSize - $anyCodeDummyRegionSize * (1 - $aliceDummyCompressionRatio))', \%variables);

         if ($exceedROMSize > $availableRAM * (1 - $zImageDummyCompressionRatio))
         {
            debugLog("Exceed ROM Size > Available RAM * (1 - ZIMAGE Dummy Compression Ratio)");
            debugLog("   = $availableRAM * (1 - $zImageDummyCompressionRatio)");
            debugLog("   = ".($availableRAM * (1 - $zImageDummyCompressionRatio)));
            &configFail(CONFIG_FAIL_INSUFFICIENT_RAM, $exceedROMSize / (1 - $zImageDummyCompressionRatio) - $availableRAM);
         }
      }

      # Push ALICE_FORBID to ZIMAGE or ROM1
      &_splitObjectListAndPushByExceedROM('@aliceForbidDummyList', '@zImageList', '@rom1List',
                                          '$zImageDummyCompressionRatio', \%variables, \%objectLists);

      # Push ANY_DATA to ZIMAGE or ROM1
      &_splitObjectListAndPushByExceedROM('@anyDataDummyList', '@zImageList', '@rom1List',
                                          '$zImageDummyCompressionRatio', \%variables, \%objectLists);

      # Push ANY_CODE to ZIMAGE or ALICE
      &_splitObjectListAndPushByExceedROM('@anyCodeDummyList', '@zImageList', '@aliceList',
                                          '$aliceDummyCompressionRatio - $zImageDummyCompressionRatio', \%variables, \%objectLists);

      #if ($exceedROMSize > 0)
      #{
      #   &configFail(CONFIG_FAIL_INSUFFICIENT_FLASH_SIZE, $exceedROMSize);
      #}

      printLog("Compute the Max Compressed Size");
      {
         $zImageMaxCompressedSize = &_getRegionMaxCompressedSize("ZIMAGE", $zImageRegionSize, $zImageDummyRegionSize + $anyCodeDummyRegionSize + $anyDataDummyRegionSize, $zImageBinary);
         $aliceMaxCompressedSize = &_getRegionMaxCompressedSize("ALICE", $aliceRegionSize, $aliceDummyRegionSize, $aliceBinary);
      }

      $zImageMaxCompressedSize =
         &vivaHelper::RoundDownToAlignment($zImageMaxCompressedSize, $zImageSizeAlignment);
      $aliceMaxCompressedSize =
         &vivaHelper::RoundUpToAlignment($aliceMaxCompressedSize, $aliceSizeAlignment);

      printLog("ZIMAGE Max Compressed Size: ".vivaHelper::DecToHex($zImageMaxCompressedSize));
      printLog("ALICE Max Compressed Size: ".vivaHelper::DecToHex($aliceMaxCompressedSize));
   }

   # Check whether the configurations are changed
   {
      if ($featureConfig{"CONFIG_ZIMAGE_MAX_COMPRESSED_SIZE"} == $zImageMaxCompressedSize and
          $featureConfig{"CONFIG_ALICE_MAX_COMPRESSED_SIZE"} == $aliceMaxCompressedSize)
      {
         debugLog("Config not changed");
         $configChanged = 0;
      }
      else
      {
         debugLog("Config changed");
         $configChanged = 1;
      }

      if (&_isObjectListChanged($objectROM1ListFile, \@rom1List) or
          &_isObjectListChanged($objectZImageListFile, \@zImageList) or
          &_isObjectListChanged($objectAliceListFile, \@aliceList))
      {
         debugLog("Object list changed");
         $objectListChanged = 1;
      }
      else
      {
         debugLog("Object list not changed");
         $objectListChanged = 0;
      }
   }

   return ($configChanged, $objectListChanged);
}

sub configZImage_FavorROM
{
   printLog("Configuring ZIMAGE favoring ROM...");

   my $rom1RegionSize;
   my $zImageRegionSize;

   my @anyCodeDummyList;
   my @anyDataDummyList;

   my $anyCodeDummyRegionPadding;
   my $anyDataDummyRegionPadding;

   my $rom1DummyRegionSize;
   my $zImageDummyRegionSize;
   my $anyCodeDummyRegionSize;
   my $anyDataDummyRegionSize;

   my $zImageDummyCompressionRatio;

   my $freeRAMSize;

   my $availableRAM;

   my $exceedROMSize;

   my $targetSplitSize;

   my %variables =
      (
       '$dcmcmpUsedRAM' => ["DCMCMP Used RAM", \$dcmcmpUsedRAM],
       '$veneerReserveRatio' => ["Veneer Reserve Ratio", \$veneerReserveRatio],
       '$rom1RegionSize' => ["ROM1 Region Size", \$rom1RegionSize],
       '$zImageRegionSize' => ["ZIMAGE Region Size", \$zImageRegionSize],
       '$anyCodeDummyRegionPadding' => ["ANY_CODE Dummy Region Padding", \$anyCodeDummyRegionPadding],
       '$anyDataDummyRegionPadding' => ["ANY_DATA Dummy Region Padding", \$anyDataDummyRegionPadding],
       '$rom1DummyRegionSize' => ["ROM1 Dummy Region Size", \$rom1DummyRegionSize],
       '$zImageDummyRegionSize' => ["ZIMAGE Dummy Region Size", \$zImageDummyRegionSize],
       '$anyCodeDummyRegionSize' => ["ANY_CODE Dummy Region Size", \$anyCodeDummyRegionSize],
       '$anyDataDummyRegionSize' => ["ANY_DATA Dummy Region Size", \$anyDataDummyRegionSize],
       '$zImageDummyCompressionRatio' => ["ZIMAGE Dummy Compression Ratio", \$zImageDummyCompressionRatio],
       '$freeRAMSize' => ["Free RAM Size", \$freeRAMSize],
       '$availableRAM' => ["Available RAM", \$availableRAM],
       '$exceedROMSize' => ["Exceed ROM Size", \$exceedROMSize],
       '$targetSplitSize' => ["Target Split Size", \$targetSplitSize],
      );

   my %objectLists =
      (
       '@rom1List' => ["ROM1 List", \@rom1List, '$rom1RegionSize',],
       '@zImageList' => ["ZIMAGE List", \@zImageList, '$zImageRegionSize',],
       '@anyCodeDummyList' => ["ANY_CODE Dummy List", \@anyCodeDummyList, '$anyCodeDummyRegionSize', '$anyCodeDummyRegionPadding'],
       '@anyDataDummyList' => ["ANY_DATA Dummy List", \@anyDataDummyList, '$anyDataDummyRegionSize', '$anyDataDummyRegionPadding']
      );

   printLog("Get dummy scatter object lists");
   {
      # Basic
      &_inputObjectListFromFile($objectROM1DummyListFile, \@rom1List, "ROM1");
      &_inputObjectListFromFile($objectZImageDummyListFile, \@zImageList, "ZIMAGE");

      # To be added
      $anyCodeDummyRegionPadding = &_inputObjectListFromExecutionRegion("ZIMAGE_DUMMY_CODE", \@anyCodeDummyList, "+RO-CODE", "ANY_CODE list");
      $anyDataDummyRegionPadding = &_inputObjectListFromExecutionRegion("ZIMAGE_DUMMY_DATA", \@anyDataDummyList, "+RO-DATA", "ANY_DATA list");
   }

   printLog("Get size information");
   {
      $rom1DummyRegionSize = &_getExecutionRegionInfo("ROM1", "actual_size");
      $zImageDummyRegionSize = &_getExecutionRegionInfo("ZIMAGE_ER", "actual_size");
      $anyCodeDummyRegionSize = &_getExecutionRegionInfo("ZIMAGE_DUMMY_CODE", "actual_size");
      $anyDataDummyRegionSize = &_getExecutionRegionInfo("ZIMAGE_DUMMY_DATA", "actual_size");

      $rom1RegionSize = $rom1DummyRegionSize;
      $zImageRegionSize = $zImageDummyRegionSize;

      $freeRAMSize = &getFreeRAMSize();

      $exceedROMSize = &getExceedROMSize();
   }

   # Configure
   {
      printLog("Compute Available RAM");
      &_evaluateAssignment('$availableRAM = int(($freeRAMSize - $dcmcmpUsedRAM - $zImageDummyRegionSize) * (1 - $veneerReserveRatio))', \%variables);

      if ($availableRAM < 0)
      {
         &configFail(CONFIG_FAIL_INSUFFICIENT_RAM, -1 * $availableRAM);
      }

      # Compute the compression ratios
      printLog("Compute the compression ratios");
      {
         $zImageDummyCompressionRatio = &_getCompressionRatio("ZIMAGE", $zImageDummyRegionSize + $anyCodeDummyRegionSize + $anyDataDummyRegionSize, $zImageBinary);
      }

      # Push ANY_DATA to ZIMAGE
      &_splitObjectListAndPushByExceedROM('@anyDataDummyList', '@zImageList', '@rom1List',
                                          '$zImageDummyCompressionRatio', \%variables, \%objectLists);

      # Push ANY_CODE to ZIMAGE
      &_splitObjectListAndPushByExceedROM('@anyCodeDummyList', '@zImageList', '@rom1List',
                                          '$zImageDummyCompressionRatio', \%variables, \%objectLists);

      #if ($exceedROMSize > 0)
      #{
      #   &configFail(CONFIG_FAIL_INSUFFICIENT_FLASH_SIZE, $exceedROMSize);
      #}

      printLog("Compute the Max Compressed Size");
      {
         $zImageMaxCompressedSize = &_getRegionMaxCompressedSize("ZIMAGE", $zImageRegionSize, $zImageDummyRegionSize + $anyCodeDummyRegionSize + $anyDataDummyRegionSize, $zImageBinary);
      }

      $zImageMaxCompressedSize =
         &vivaHelper::RoundDownToAlignment($zImageMaxCompressedSize, $zImageSizeAlignment);

      printLog("ZIMAGE Max Compressed Size: ".vivaHelper::DecToHex($zImageMaxCompressedSize));
   }

   # Check whether the configurations are changed
   {
      if ($featureConfig{"CONFIG_ZIMAGE_MAX_COMPRESSED_SIZE"} == $zImageMaxCompressedSize)
      {
         debugLog("Config not changed");
         $configChanged = 0;
      }
      else
      {
         debugLog("Config changed");
         $configChanged = 1;
      }

      if (&_isObjectListChanged($objectROM1ListFile, \@rom1List) or
          &_isObjectListChanged($objectZImageListFile, \@zImageList))
      {
         debugLog("Object list changed");
         $objectListChanged = 1;
      }
      else
      {
         debugLog("Object list not changed");
         $objectListChanged = 0;
      }
   }

   return ($configChanged, $objectListChanged);
}

sub _getCompressionRatio
{
   my $regionName = shift;
   my $dummyRegionSize = shift;
   my $dummyCompressedBinary = shift;

   my $dummyCompressedSize = -s $dummyCompressedBinary or
      &vivaHelper::ErrorHandler("Cannot get file size $dummyCompressedBinary: $!", __FILE__, __LINE__);
   #debugLog("$regionName Dummy Region Size = $dummyRegionSize");
   #debugLog("$regionName Dummy Compressed Binary Size = $dummyCompressedSize");

   my $compressionRatio = $dummyCompressedSize / $dummyRegionSize;
   debugLog("$regionName Compression Ratio = $regionName Dummy Compressed Binary Size / $regionName Dummy Region Size");
   debugLog("   = $dummyCompressedSize / $dummyRegionSize");
   debugLog("   = $compressionRatio");

   return $compressionRatio;
}

sub _splitObjectListAndPushByExceedROM
{
   my $sourceList = shift;
   my $firstList = shift;
   my $secondList = shift;

   my $compressionRatio = shift;

   my $variables = shift;
   my $objectLists = shift;

   if (${$variables->{'$exceedROMSize'}[1]} > 0)
   {
      printLog("Split $objectLists->{$sourceList}[0] to $objectLists->{$firstList}[0] and $objectLists->{$secondList}[0]");

      &_evaluateAssignment('$targetSplitSize = min($availableRAM, '."$objectLists->{$sourceList}[2]".')', $variables);
      &_evaluateAssignment('$targetSplitSize = min($targetSplitSize, int($exceedROMSize / (1 - '."$compressionRatio".')))', $variables);

      ${$variables->{'$targetSplitSize'}[1]} = &_splitObjectListAndPush("$sourceList", "$firstList", "$secondList",
                                                                        '$targetSplitSize', $variables, $objectLists);

      &_evaluateAssignment('$availableRAM = $availableRAM - $targetSplitSize - '."$objectLists->{$sourceList}[3]", $variables);
      &_evaluateAssignment('$exceedROMSize = int($exceedROMSize - $targetSplitSize * (1 - '."$compressionRatio".'))', $variables);
   }
   else
   {
      printLog("Push $objectLists->{$sourceList}[0] to $objectLists->{$secondList}[0]");
      &_pushToObjectList($secondList, $sourceList, $variables, $objectLists);
   }
}

#****************************************************************************
# subroutine:  parseFeatureConfigFile
# description: Get the settings in the feature config file
# input:       The setting hash ref
# output:      The settings
#****************************************************************************
sub parseFeatureConfigFile
{
   my $featureConfigRef = shift;
   my $filename = $featureConfigFilePath;

   open my $input, "<$filename" or
      &vivaHelper::ErrorHandler("Cannot open file $filename: $!", __FILE__, __LINE__);

   while (<$input>)
   {
      chomp;
      if (/^\s*\#define\s+(\S+)\s+(\S+)/)
      {
         $featureConfigRef->{$1} = hex($2);
      }
   }

   close $input;
}

#****************************************************************************
# subroutine:  getFreeRAMSize
# description: Get the free RAM size.
# input:       None
# output:      Free RAM size
#****************************************************************************
sub getFreeRAMSize
{
   # TODO: Move this to LISInfo.pm
   my $externalRAMSize = &getExternalRAMSize();
   my $usedRAM;
   my $cacheDummyEndSize = 4;
   my $result;

   my %regionInfo;
   &vivaHelper::GetLISExecutionRegionInfo("DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI", \%regionInfo);
   $usedRAM = ($regionInfo{"base_address"} & hex("0x07FFFFFF")) + $regionInfo{"actual_size"};
   debugLog("End of cacheable ZI = $usedRAM");

   &vivaHelper::GetLISExecutionRegionInfo("EXTSRAM_DSP_TX", \%regionInfo);
   $usedRAM += $regionInfo{"max_size"};
   debugLog("DSP TX RAM = ".$regionInfo{"max_size"});

   &vivaHelper::GetLISExecutionRegionInfo("EXTSRAM_DSP_RX", \%regionInfo);
   $usedRAM += $regionInfo{"max_size"};
   debugLog("DSP RX RAM = ".$regionInfo{"max_size"});

   debugLog("Cache dummy end size = $cacheDummyEndSize");

   $result = $externalRAMSize - $usedRAM - $cacheDummyEndSize;

   debugLog("Free RAM size = External Total RAM Size - (End of cacheable ZI + DSP TX RAM + DSP RX RAM) - Cache Dummy End Size");
   debugLog("   = $result");

   return $result;
}

#****************************************************************************
# subroutine:  getTotalLISROMSize
# description: Get total ROM size in LIS file.
# input:       None
# output:      Total ROM size in LIS file
#****************************************************************************
sub getTotalLISROMSize
{
   my %totalSizeInfo;
   &vivaHelper::GetLISTotalSize(\%totalSizeInfo);

   my $totalLISROMSize = $totalSizeInfo{"ROM"};

   debugLog("Total LIS ROM size = $totalLISROMSize");

   return $totalLISROMSize;
}

#****************************************************************************
# subroutine:  getFileSystemBaseAddress
# description: Get the file system base address.
# input:       None
# output:      File system base address
#****************************************************************************
sub getFileSystemBaseAddress
{
   my $result;

   open my $input, "<$flashConfigFilePath" or
      &vivaHelper::ErrorHandler("Cannot open file $flashConfigFilePath: $!", __FILE__, __LINE__);

   while (<$input>)
   {
     if (/int flash_base_address\s+=\s+((\S|\s)+);/)
     {
       $result = eval($1);
       last;
     }
   }
   close ($input);

   debugLog("File System Base Address = $result");

   return $result;
}

#****************************************************************************
# subroutine:  getExceedROMSize
# description: Get the bytes exceed maximum ROM size.
# input:       None
# output:      Byte exceeded
#****************************************************************************
sub getExceedROMSize
{
   my $fsBaseAddress = &getFileSystemBaseAddress();
   my $totalLISROMSize = &getTotalLISROMSize();
   my $scatterReservedSize = &vivaHelper::GetScatterReservedSize($fsBaseAddress);
   debugLog("Scatter Reserved Size = $scatterReservedSize");

   my $exceedROMSize = $totalLISROMSize + $scatterReservedSize - $fsBaseAddress;

   debugLog("Exceed ROM Size = Total LIS ROM size + Scatter Reserved Size - File System Base Address");
   debugLog("   = $totalLISROMSize + $scatterReservedSize - $fsBaseAddress");
   debugLog("   = $exceedROMSize");

   return $exceedROMSize;
}

#****************************************************************************
# subroutine:  getExternalRAMSize
# description: Get the external RAM size.
# input:       None
# output:      External RAM size
#****************************************************************************
sub getExternalRAMSize
{
   my $filename = "$customFolder\\custom_EMI_release.h";
   my $result;

   open my $input, "<$filename" or
      &vivaHelper::ErrorHandler("Cannot open file $flashConfigFilePath: $!", __FILE__, __LINE__);

   while (<$input>)
   {
     if (/\#define EMI_EXTSRAM_SIZE ((\S|\s)+)/)
     {
       $result = eval($1);
       last;
     }
   }
   close ($input);

   debugLog("External Total RAM Size =  $result");

   return $result;
}

#****************************************************************************
# subroutine:  isAutoConfigEnable
# description: See if the auto configuration mechanism is enabled or not.
# input:       None
# output:      1: enabled; 0: not enabled
#****************************************************************************
sub isAutoConfigEnable
{
   my $autoConfig = &vivaHelper::GetMakefileOption("ZIMAGE_AUTO_CONFIG");

   if (not defined $autoConfig or $autoConfig eq "TRUE")
   {
      return 1;
   }
   else
   {
      return 0;
   }
}

#****************************************************************************
# subroutine:  printIntermediateFile
# description: Print to intermediate file.
# input:       Message
# output:      None
#****************************************************************************
sub printIntermediateFile
{
   my $message = shift;

   open my $output, ">$intermediateFilePath" or
      &vivaHelper::ErrorHandler("Cannot open file $intermediateFilePath: $!", __FILE__, __LINE__);

   print $output $message;

   close $output;
}

#****************************************************************************
# subroutine:  configFailLog
# description: Output the config fail information.
# input:       Fail reason message, recommendation message
# output:      None
#****************************************************************************
sub configFailLog
{
   my ($failReason, $recommend) = @_;

   my $message = "Error: $failReason\nRecommend: $recommend\n";
   printLog("\n$message");

   open (FILE_HANDLE, ">$intermediateFilePath") or
      &vivaHelper::ErrorHandler("Cannot open file $intermediateFilePath: $!", __FILE__, __LINE__);
   print FILE_HANDLE $message;
   close FILE_HANDLE;

   exit ERR::CANNOT_ADJUST;
}

#****************************************************************************
# subroutine:  configFail
# description: Indicate the configuration is failed.
# input:       Fail code (constant with CONFIG_FAIL_XXXX)
# output:      None
#****************************************************************************
sub configFail
{
   my $failCode = shift;
   my $failReason;
   my $recommend;

   if ($failCode == CONFIG_FAIL_INSUFFICIENT_RAM)
   {
      my $exceeded = shift;
      $failReason = "Insufficient RAM space. ($exceeded bytes exceeded)";
      $recommend = "Please turn off some features. (e.g. DCM_COMPRESSION_SUPPORT)";
   }
   elsif ($failCode == CONFIG_FAIL_ZIMAGE_OVERFLOW)
   {
      my $exceeded = shift;
      $failReason = "ZIMAGE overflow. ($exceeded bytes exceeded)";
      $recommend = "Please either\n           (1) remove xxx.lib/xxx.obj from ZIMAGE, or\n           (2) turn off some features"
   }
   elsif ($failCode == CONFIG_FAIL_FEATURE_NOT_ENABLED)
   {
      $failReason = "No configurable feature is enabled.";
      $recommend = "Please turn off some features and refer to build\\[BB]\\VIVA_DEBUG\\[BB].error for more information.";
   }
   elsif ($failCode == CONFIG_FAIL_NO_CONFIG_CHANGED)
   {
      $failReason = "The configuration is not changed.";
      $recommend = "Please turn off some features."
   }
   elsif ($failCode == CONFIG_FAIL_INSUFFICIENT_FLASH_SIZE)
   {
      my $exceeded = shift;
      $failReason = "Insufficient flash space. ($exceeded bytes exceeded)";
      $recommend = "Please turn off some features."
   }
   elsif ($failCode == CONFIG_FAIL_INSUFFICIENT_RAM_FOR_BOOT_ZIMAGE)
   {
      my $exceeded = shift;
      $failReason = "Insufficient RAM space for BOOT_ZIMAGE. ($exceeded bytes exceeded)";
      $recommend = "Please turn off some features. (e.g. DCM_COMPRESSION_SUPPORT)";
   }
   else
   {
      $failReason = "Unknown.";
      $recommend = "Please call for help";
   }

   &configFailLog($failReason, $recommend);
}

#****************************************************************************
# subroutine:  min
# description: Get the minimum one in the two input.
# input:       Number 1, number 2
# output:      Minimum number
#****************************************************************************
sub min
{
    my ($m, $n) = @_;

    if ($m < $n) {
        $m
    }
    else {
        $n
    }
}

#****************************************************************************
# subroutine:  getTimeStamp
# description: Get a time stamp.
# input:       None
# output:      The time stamp
#****************************************************************************
sub getTimeStamp
{
   return time().".".int(rand(1000));
}


#****************************************************************************
# subroutine:  backupFile
# description: Backup file with a timestamp appended.
# input:       Filename
# output:      None
#****************************************************************************
sub backupFile
{
   my $filename = shift;
   my $backupFilename = $filename.".beforeAutoAdj".getTimeStamp();

   copy($filename, $backupFilename) or
      &vivaHelper::ErrorHandler("Cannot backup file $filename: $!", __FILE__, __LINE__);
}


sub printLog
{
   print "$_[0]\n";
}

sub debugLog
{
   if ($DEBUG)
   {
      printLog("\t$_[0]");
   }
}

# DEBUG command
# tools\vivaConfig.pl .\build\KHAN50D_V11_DEMO\VIVA_DEBUG\KHAN50D_V11_DEMO_PCB01_gprs_MT6250_S00.lis.dummy .\build\KHAN50D_V11_DEMO\VIVA_DEBUG\KHAN50D_V11_DEMO_PCB01_gprs_MT6250_S00.MAUI_11BW1132SP_W12_15.bin_dummy .\custom\system\KHAN50D_V11_DEMO_BB .\make\KHAN50D_V11_DEMO_GPRS.mak ~flash_cfg_tmp.c intermediate.log aapmc.log > build\KHAN50D_V11_DEMO\log\vivaConfig.log
