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
package zImageProcess;
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
my $compressTool = "tools\\7lzma.exe";
my $zImageBinaryName = "ZIMAGE_ER";
my $zImageBinaryBackupName = "ZIMAGE_ER.bin";
my %zImageInfo = ("name" => "ZIMAGE",
                  "binary_name" => $zImageBinaryName,
                  "struct_name" => "zimage",
                  "entry_function" => \&ZImageProcess);
my %defaultPartitionInfo = ("MT6250" => [{"ratio" => 0.75, "type" => 2},
                                         {"ratio" => 0.25, "type" => 1}]);
my $minSplitableSize = 8 * 1024;

#****************************************************************************
# subroutine:  Process
# description: Perform the ZIMAGE post build process.
# input:       Binary folder, available start address,
#              original start address ref, original size ref
# output:      Actual start address, new binary size
#****************************************************************************
sub ZImageProcess
{
   my $binaryFolder = shift;
   my $availableStartAddress = shift;
   my $startAddressRef = shift;
   my $sizeRef = shift;

   my $binary = "$binaryFolder\\$zImageBinaryName";
   my $binaryBackup = "$binaryFolder\\$zImageBinaryBackupName";

   my $zimageEnabled = &vivaHelper::GetMakefileOption("ZIMAGE_SUPPORT");
   unless (defined $zimageEnabled and
           $zimageEnabled eq "TRUE" and
           -e $binary)
   {
      return 0;
   }

   # Using default partition setting
   CompressByPartition($binary, $binaryBackup, $$startAddressRef);

   # Update start address and binary size
   # Need 4 byte align
   $$startAddressRef = &vivaHelper::RoundUpToAlignment($availableStartAddress, 4);
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
sub GetZImageInfo
{
   return \%zImageInfo;
}

#****************************************************************************
# Constants
#****************************************************************************
my $bootZImageBinaryName = "BOOT_ZIMAGE_ER";
my $bootZImageBinaryBackupName = "BOOT_ZIMAGE_ER.bin";
my %bootZImageInfo = ("name" => "BOOT_ZIMAGE",
                      "binary_name" => $bootZImageBinaryName,
                      "struct_name" => "boot_zimage",
                      "entry_function" => \&BootZImageProcess);

#****************************************************************************
# subroutine:  Process
# description: Perform the ZIMAGE post build process.
# input:       Binary folder, available start address,
#              original start address ref, original size ref
# output:      Actual start address, new binary size
#****************************************************************************
sub BootZImageProcess
{
   my $binaryFolder = shift;
   my $availableStartAddress = shift;
   my $startAddressRef = shift;
   my $sizeRef = shift;

   my $binary = "$binaryFolder\\$bootZImageBinaryName";
   my $binaryBackup = "$binaryFolder\\$bootZImageBinaryBackupName";

   my %zImage2partitionInfo = ("MT6250" => [{"ratio" => 1, "type" => 2}]);

   my $zimage2Enabled = &vivaHelper::GetMakefileOption("BOOT_ZIMAGE_SUPPORT");
   unless (defined $zimage2Enabled and
           $zimage2Enabled eq "TRUE" and
           -e $binary)
   {
      return 0;
   }

   CompressByPartition($binary, $binaryBackup, $$startAddressRef, $zImage2partitionInfo{&vivaHelper::GetMakefileOption("PLATFORM")});

   # Update start address and binary size
   # Need 4 byte align
   $$startAddressRef = &vivaHelper::RoundUpToAlignment($availableStartAddress, 4);
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
sub GetBootZImageInfo
{
   return \%bootZImageInfo;
}



sub CompressByPartition
{
   my $binary = shift;
   my $binaryBackup = shift;
   my $decompressStartAddress = shift;
   my $partitions = shift;

   # The parition decompress start address should be cache line aligned
   my $alignment = 32;
   my $alignShift = $alignment - $decompressStartAddress % $alignment;

   # Use default setting if the argument is omitted
   $partitions = $defaultPartitionInfo{&vivaHelper::GetMakefileOption("PLATFORM")} unless defined $partitions;

   # Backup the original binary
   printLog("Backup binary...");
   copy($binary, $binaryBackup) or
      &vivaHelper::ErrorHandler("Cannot backup binary $binary: $!", __FILE__, __LINE__);

   # Compress the binary
   {
      my $binarySize = -s $binary or
            &vivaHelper::ErrorHandler("Cannot get file size $binary: $!", __FILE__, __LINE__);

      my $splitPartitionNumber;
      my @partitionSize;
      my @partitionName;
      my @partitionCompressedSize;

      # Use default partition settings if not defined or the size is too small
      if (not defined $partitions)
      {
         $partitions = [{"ratio" => [1], "type" => 1}];
      }

      # Split the binary
      printLog("Splitting binaries...");
      {
         debugLog("Original Size: $binarySize");
         my $temp;
         my $subTotalSize = 0;
         my $i;

         for ($i = 0; $i < @$partitions; ++$i)
         {
            $temp = &vivaHelper::RoundUpToAlignment(int($partitions->[$i]{"ratio"} * $binarySize + 0.99), $alignment) + $alignShift;
            $subTotalSize += $temp;

            push @partitionSize, $temp;
            push @partitionName, "~zimagePartition_$i.tmp";
         }

         # Add or subtract the rest size to the final partition
         $partitionSize[$i - 1] += $binarySize - $subTotalSize;

         for ($i = 0; $i < @partitionSize; ++$i)
         {
            debugLog("$partitionName[$i]\t$partitionSize[$i]");
         }

         # Split
         $splitPartitionNumber = &vivaHelper::SplitBinaryBySize($binary, \@partitionSize, \@partitionName);
      }

      # Compress
      printLog("Compressing binaries...");
      {
         for (my $i = 0; $i < $splitPartitionNumber; ++$i)
         {
            if (0 != system("$compressTool e $partitionName[$i] $partitionName[$i]_comp"))
            {
               &vivaHelper::ErrorHandler("Cannot compress ZIMAGE binary $partitionName[$i]: $!", __FILE__, __LINE__);
            }
            else
            {
               my $temp = -s $partitionName[$i]."_comp";
               push @partitionCompressedSize, $temp or
                  &vivaHelper::ErrorHandler("Cannot get file size $partitionName[$i]_comp: $!", __FILE__, __LINE__);

               # Pad the binary after getting the size
               &vivaHelper::PaddingBinaryToAlignment($partitionName[$i]."_comp", 4);
               debugLog("$partitionName[$i]_comp\t$temp");
            }
         }
      }

      # Making the header
      printLog("Making header...");
      {
         # Write partition number
         my $buffer;
         my $sourceAddress;
         my $destinationAddress;

         open my $output, ">~zimageHeader.tmp" or
            &vivaHelper::ErrorHandler("Cannot open output file ~zimageHeader.tmp: $!", __FILE__, __LINE__);
         binmode $output;

         # Write partition number
         debugLog("Partition number: $splitPartitionNumber");
         $buffer = pack("L", $splitPartitionNumber);
         print $output $buffer;

         # Write partition info
         $sourceAddress = 4 + 20 * ($splitPartitionNumber);
         $destinationAddress = 0;

         for (my $i = 0; $i < $splitPartitionNumber; ++$i)
         {
            my $type = $partitions->[$i]{"type"};
            my $sourceSize = $partitionCompressedSize[$i];
            my $destinationSize = $partitionSize[$i];

            debugLog("Partition[$i]: $type, $sourceAddress, $sourceSize, $destinationAddress, $destinationSize");
            $buffer = pack("LLLLL", $type, $sourceAddress, $sourceSize, $destinationAddress, $destinationSize);
            print $output $buffer;

            $sourceAddress += &vivaHelper::RoundUpToAlignment($sourceSize, 4);
            $destinationAddress += $destinationSize;
         }

         close $output;
      }

      # Concatenate all the compressed binaries and the header
      printLog("Concatenating binaries...");
      {
         my @concatenateList = ("~zimageHeader.tmp");
         for (my $i = 0; $i < $splitPartitionNumber; ++$i)
         {
            push @concatenateList, $partitionName[$i]."_comp";
         }

         open my $output, ">$binary" or
            &vivaHelper::ErrorHandler("Cannot open output file $binary: $!", __FILE__, __LINE__);
         binmode $output;

         &vivaHelper::ConcatenateBinary($output, \@concatenateList);

         close $output;
      }

      # Delete all temp files
      printLog("Deleting temp files...");
      {
         unlink("~zimageHeader.tmp") or &vivaHelper::ErrorHandler("Cannot delete file ~zimageHeader.tmp: $!", __FILE__, __LINE__);
         for (my $i = 0; $i < $splitPartitionNumber; ++$i)
         {
            unlink($partitionName[$i]) or &vivaHelper::ErrorHandler("Cannot delete file $partitionName[$i]: $!", __FILE__, __LINE__);
            unlink($partitionName[$i]."_comp") or &vivaHelper::ErrorHandler("Cannot delete file $partitionName[$i]_comp: $!", __FILE__, __LINE__);
         }
      }
   }
}

sub printLog
{
   print "[ZIMAGE] $_[0]\n";
}

sub debugLog
{
   if ($DEBUG)
   {
      printLog("[DEBUG] $_[0]");
   }
}

1;
