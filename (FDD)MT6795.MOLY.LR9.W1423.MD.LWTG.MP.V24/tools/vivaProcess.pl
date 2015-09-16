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
#*   vivaProcess.pl
#*
#* Project:
#* --------
#*   Maui_Software
#*
#* Description:
#* ------------
#*   This file implemented the VIVA post build process to gen the VI binaries.
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
use vivaHelper;
use zImageProcess;
use File::Copy;

#****************************************************************************
# History
#****************************************************************************
my $VIVA_PROCESS_VERNO = " v1.02";
   # v1.02: Phase out ALICE and BOOT_ZIMAGE on MOLY
   # v1.01: Phase in BOOT_ZIMAGE
   # v1.00: Phase in VIVA

#****************************************************************************
# Constants
#****************************************************************************
my $DEBUG = 1;
my $vivaBinaryName = "VIVA";
my $vivaBinaryBackupName = "VIVA.bin";
# Note the sequence of this list is the same as VI processing sequence.
# Thus it should be consistent to the position in scatter file.
my @viList = (&zImageProcess::GetZImageInfo());
my $separateLine = "=============================================================";

#****************************************************************************
# Arguments
#****************************************************************************
&vivaHelper::ErrorHandler("Insufficient arguments!", __LINE__, __FILE__)
   unless scalar(@ARGV) == 2;

my ($binaryFolder, $makefilePath) = @ARGV;
$binaryFolder =~ s/^.\\|^\\//;
$makefilePath =~ s/^.\\|^\\//;

#****************************************************************************
# Variables
#****************************************************************************
my $vivaBinary = "$binaryFolder\\$vivaBinaryName";
my $vivaBinaryBackup = "$binaryFolder\\$vivaBinaryBackupName";
my %vivaInfo;
my $viAvailableStartAddress;
my $viStartAddressRef;
my $viSize;

#****************************************************************************
# Process
#****************************************************************************
printLog("Start VIVA processing...");

&vivaHelper::Initialize(&vivaHelper::PROCESS_TYPE, $makefilePath);

&vivaHelper::ErrorHandler("Insufficient arguments!", __LINE__, __FILE__)
   unless defined $binaryFolder and defined $makefilePath;

debugLog("Binary Folder: $binaryFolder");
debugLog("Makefile: $makefilePath");

# Backup VIVA binary
copy($vivaBinary, $vivaBinaryBackup) or
   &vivaHelper::ErrorHandler("Cannot backup VIVA header binary $vivaBinary: $!", __FILE__, __LINE__);

# Open VIVA binary
open my $inout, "+<$vivaBinary" or
   &vivaHelper::ErrorHandler("Cannot open VIVA header binary $vivaBinary: $!", __FILE__, __LINE__);
binmode $inout;

# Read VIVA binary
printLog("Read VIVA info...");
&vivaHelper::ReadVIVAInfo($inout, \%vivaInfo);
while (my ($key, $value) = each (%vivaInfo))
{
   debugLog("$key: ".&vivaHelper::DecToHex($value));
}

# Get the first VI available start address
$viSize = -s $vivaBinaryBackup;
$viAvailableStartAddress = $vivaInfo{"viva_base"} + $viSize;
printLog("VI Start Address: ".&vivaHelper::DecToHex($viAvailableStartAddress));

# For each VI
foreach my $vi (@viList)
{
   printLog($separateLine);
   printLog("Start processing ".$vi->{"name"}."...");

   $viStartAddressRef = \$vivaInfo{$vi->{"struct_name"}."_base"};

   # Invoke VI post process
   if ($vi->{"entry_function"}($binaryFolder, $viAvailableStartAddress, $viStartAddressRef, \$viSize))
   {
      # Add padding for new start address
      {
         my $writeCount = $$viStartAddressRef - $viAvailableStartAddress;
         my $buffer = pack("C[$writeCount]", 0);
         print $inout $buffer;
      }

      # Append proccessed binary
      &vivaHelper::ConcatenateBinary($inout, [$binaryFolder."\\".$vi->{"binary_name"}]);

      printLog("Processing OK");

      $viAvailableStartAddress = $$viStartAddressRef + $viSize;

      debugLog("Start Address: ".&vivaHelper::DecToHex($$viStartAddressRef));
      debugLog("Image Size: ".&vivaHelper::DecToHex($viSize));
      debugLog("Next Available Start Address: ".&vivaHelper::DecToHex($viAvailableStartAddress));
   }
   else
   {
      printLog("Processing SKIPPED");
   }
   printLog("End processing ".$vi->{"name"});
}

printLog($separateLine);

# Write VIVA binary
printLog("Update VIVA info...");
seek $inout, 0, 0;
&vivaHelper::WriteVIVAInfo($inout, \%vivaInfo);
while (my ($key, $value) = each (%vivaInfo))
{
   debugLog("$key: ".&vivaHelper::DecToHex($value));
}

close $inout;

# Padding the total size to 4 bytes align
&vivaHelper::PaddingBinaryToAlignment($vivaBinary, 4);

printLog("End VIVA processing");
exit 0;



sub printLog
{
   print "[VIVA] $_[0]\n";
}

sub debugLog
{
   if ($DEBUG)
   {
      printLog("[DEBUG] $_[0]");
   }
}
