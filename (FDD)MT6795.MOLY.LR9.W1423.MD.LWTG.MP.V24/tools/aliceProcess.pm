#!/usr/bin/perl
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2005
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
#*   zImageProcess.pl
#*
#* Project:
#* --------
#*   Maui_Software
#*
#* Description:
#* ------------
#*   This file implemented the ZIMAGE post build process.
#*
#*
#* Author:
#* -------
#*   Ke-Ting Chen (mtk03141)
#*
#*****************************************************************************
package aliceProcess;
#****************************************************************************
# Included Modules
#****************************************************************************
use strict;
use warnings;
BEGIN { push @INC, '.\\tools\\' }  # add additional library path
use vivaHelper;
use File::Copy;

#****************************************************************************
# Constants
#****************************************************************************
my $DEBUG = 1;
my $aliceBinaryName = "ALICE";
my $aliceBinaryBackupName = "ALICE.bin";
my $compressTool = "tools\\ALICE.exe";
my %info = ("name" => "ALICE",
            "binary_name" => $aliceBinaryName,
            "struct_name" => "alice",
            "entry_function" => \&Process);

#****************************************************************************
# subroutine:  Process
# description: Perform the ZIMAGE post build process.
# input:       Binary folder, available start address,
#              original start address ref, original size ref
# output:      Actual start address, new binary size
#****************************************************************************
sub Process
{
   my $binaryFolder = shift;
   my $availableStartAddress = shift;
   my $startAddressRef = shift;
   my $sizeRef = shift;

   my $binary = "$binaryFolder\\$aliceBinaryName";
   my $binaryBackup = "$binaryFolder\\$aliceBinaryBackupName";

   my $compressedStartAddress = &vivaHelper::RoundUpToAlignment($availableStartAddress, 4);
   my $decompressedStartAddress = $$startAddressRef;

   my $aliceEnabled = &vivaHelper::GetMakefileOption("ALICE_SUPPORT");
   unless (defined $aliceEnabled and
           $aliceEnabled eq "TRUE" and
           -e $binary)
   {
      return 0;
   }

   # Backup the original binary
   printLog("Backup binary...");
   move($binary, $binaryBackup) or
      &vivaHelper::ErrorHandler("Cannot backup ALICE binary $binary: $!", __FILE__, __LINE__);

   # Update start address
   # Need 4 byte align
   $$startAddressRef = &vivaHelper::RoundUpToAlignment($availableStartAddress, 4);

   # Compress the binary directly
   {
      my $chip = &vivaHelper::GetMakefileOption("PLATFORM");
      printLog("Compressing binary...");
      if (0 != system("$compressTool -chip $chip -iBin $binaryBackup -oBin $binary -cBase $compressedStartAddress -dBase $decompressedStartAddress"))
      {
         &vivaHelper::ErrorHandler("Cannot compress ALICE binary $binary", __FILE__, __LINE__);
      }
   }

   # Update binary size
   $$startAddressRef = $compressedStartAddress;
   $$sizeRef = -s $binary;

   #debugLog("Base Address: $$startAddressRef");
   #debugLog("Length: $$sizeRef");

   return 1;
}

#****************************************************************************
# subroutine:  GetInfo
# description: Get the basic information of processing
# input:       None
# output:      Info ref
#****************************************************************************
sub GetInfo
{
   return \%info;
}

#****************************************************************************
# subroutine:  GetRawDataStartAddress
# description: Get the start address of ALICE raw data on the target
# input:       VIVA binary path, Is SV5
# output:      Base address
#****************************************************************************
sub GetRawDataStartAddress
{
   my $binaryPath = shift;
   my $isSV5 = shift;
   my %vivaInfo;
   my $aliceBaseAddress;
   &vivaHelper::ReadVIVAInfoFromBinary_NI($binaryPath, \%vivaInfo, $isSV5);

   $aliceBaseAddress = $vivaInfo{"alice_base"};

   # TODO: read the alice header to check the remapping bank
   $aliceBaseAddress = ($aliceBaseAddress & 0x0FFFFFFF) | 0x90000000;

   return $aliceBaseAddress;
}

sub printLog
{
   print "[ALICE] $_[0]\n";
}

sub debugLog
{
   if ($DEBUG)
   {
      printLog("[ALICE] $_[0]");
   }
}

1;

# tools\ALICE.exe -chip MT6250 -iBin .\build\MT6250_EVB\MT6250_EVB_PCB01_gprs_MT6250_S00.MAUI_11BW1132SP_W12_08.bin\ALICE.bin -oBin .\build\MT6250_EVB\MT6250_EVB_PCB01_gprs_MT6250_S00.MAUI_11BW1132SP_W12_08.bin\ALICE -base 273860240 -statistics statistics.txt -debugLevel 3
