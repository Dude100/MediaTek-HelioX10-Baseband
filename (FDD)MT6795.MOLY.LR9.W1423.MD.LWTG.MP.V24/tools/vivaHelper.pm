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
#*   vivaHelper.pm
#*
#* Project:
#* --------
#*   Maui_Software
#*
#* Description:
#* ------------
#*   This file implemented the VIVA help library.
#*
#*
#* Author:
#* -------
#*   Ke-Ting Chen (mtk03141)
#*
#*****************************************************************************
package vivaHelper;
#****************************************************************************
# Included Modules
#****************************************************************************
use strict;
use warnings;
BEGIN { push @INC, '.\\tools\\' }  # add additional library path
use FileInfoParser;
use sysGenUtility;
use LISInfo;
use objListHelper;

#****************************************************************************
# History
#****************************************************************************
my $VIVA_HELPER_VERNO = " v1.00";
   # v1.00: Phase in VIVA

#****************************************************************************
# Constants
#****************************************************************************
use constant PROCESS_TYPE => 1;
use constant CONFIG_TYPE  => 2;

my $vivaGFHHeaderSize = 56;
my $vivaHeaderSize = 20;

#****************************************************************************
# Variables
#****************************************************************************
my $executionType;
my %makefileOptions;
my $chip;
my $lisFilePath;

#****************************************************************************
# subroutine:  Initialize
# description: Initialize the module for further using.
# input:       Exeuction type, makefile path, LIS file
# output:      None
# need init:   N/A
#****************************************************************************
sub Initialize
{
   my $executionType = shift;
   my $makefilePath = shift;
   $lisFilePath = shift;

   # Parse makefile
   if (defined $makefilePath)
   {
      if (0 == &FileInfo::Parse_MAKEFILE($makefilePath, \%makefileOptions))
      {
         &ErrorHandler("Fail to parse makefile $makefilePath $!", __FILE__, __LINE__) ;
      }

      $chip = &GetMakefileOption("PLATFORM");
   }

   # Parse LIS file
   if (defined $lisFilePath)
   {
      &LISInfo::ParseLIS($lisFilePath);
   }
}

#****************************************************************************
# subroutine:  GetMakefileOption
# description: Get the makefile feature option value.
# input:       Option name
# output:      Option value
# need init:   Yes
#****************************************************************************
sub GetMakefileOption
{
   my $option = shift;
   return $makefileOptions{$option};
}

#****************************************************************************
# subroutine:  IsSV5
# description: To see if current processing chip is SV5 support or not
# input:       None
# output:      1: SV5; 0: otherwise
# need init:   Yes
#****************************************************************************
sub IsSV5
{
   return &sysUtil::is_sv5($chip);
}

#****************************************************************************
# subroutine:  GetVIVAHeaderSize
# description: Get the size of VIVA header
# input:       None
# output:      The VIVA header size with GFH if existed
# need init:   Yes
#****************************************************************************
sub GetVIVAHeaderSize
{
   my $result = $vivaHeaderSize;
   $result += $vivaGFHHeaderSize if (&IsSV5());
   return $result;
}

#****************************************************************************
# subroutine:  GetVIVAHeaderSize_NI
# description: Get the size of VIVA header
# input:       isSV5
# output:      The VIVA header size with GFH if existed
# need init:   No
#****************************************************************************
sub GetVIVAHeaderSize_NI
{
   my $isSV5 = shift;

   my $result = $vivaHeaderSize;
   $result += $vivaGFHHeaderSize if ($isSV5);
   return $result;
}

#****************************************************************************
# subroutine:  IsVIEnabled
# description: Check if any VI is enabled
# input:       None
# output:      1: at least one VI is enabled; 0: otherwise
# need init:   Yes
#****************************************************************************
sub IsVIEnabled
{
   my $zImageOption = &GetMakefileOption("ZIMAGE_SUPPORT");
   my $dcmcmpOption = &GetMakefileOption("DCM_COMPRESSION_SUPPORT");
   my $aliceOption = &GetMakefileOption("ALICE_SUPPORT");

   if (defined $zImageOption and $zImageOption eq "TRUE")
   {
      return 1;
   }
   elsif (defined $dcmcmpOption and $dcmcmpOption eq "TRUE")
   {
      return 1;
   }
   elsif (defined $aliceOption and $aliceOption eq "TRUE")
   {
      return 1;
   }
   else
   {
      return 0;
   }
}

#****************************************************************************
# subroutine:  IsVIEnabled_NI
# description: Check if any VI is enabled
# input:       Makefile path
# output:      1: at least one VI is enabled; 0: otherwise
# need init:   No
#****************************************************************************
sub IsVIEnabled_NI
{
   my $makefilePath = shift;
   my %options;
   if (0 == &FileInfo::Parse_MAKEFILE($makefilePath, \%options))
   {
      &ErrorHandler("Fail to parse makefile $makefilePath $!", __FILE__, __LINE__) ;
   }

   my $zImageOption = $options{"ZIMAGE_SUPPORT"};
   my $dcmcmpOption = $options{"DCM_COMPRESSION_SUPPORT"};
   my $aliceOption = $options{"ALICE_SUPPORT"};

   if (defined $zImageOption and $zImageOption eq "TRUE")
   {
      return 1;
   }
   elsif (defined $dcmcmpOption and $dcmcmpOption eq "TRUE")
   {
      return 1;
   }
   elsif (defined $aliceOption and $aliceOption eq "TRUE")
   {
      return 1;
   }
   else
   {
      return 0;
   }
}

#****************************************************************************
# subroutine:  ReadGFHHeader
# description: Read the GFH header.
# input:       Binary file handle reference, GFH header reference
# output:      GFH header. Note the the magic number is stripped
# need init:   No
#****************************************************************************
sub ReadGFHHeader
{
   # struct GFH_Header
   #   U32 m_magic_ver: 'M', 'M', 'M', version
   #   U16 m_size
   #   U16 m_type

   my $input = shift;
   my $headerRef = shift;
   my $buffer;
   my @result;

   read $input, $buffer, 8;
   @result = unpack("C[3]CSS", $buffer);

   &ErrorHandler ("Error GFH header magic number!", __FILE__, __LINE__)
      if (77 != $result[0] or 77 != $result[1] or 77 != $result[2]);

   $headerRef->{"m_ver"} = $result[3];
   $headerRef->{"m_size"} = $result[4];
   $headerRef->{"m_type"} = $result[5];
}

#****************************************************************************
# subroutine:  ReadGFHFileInfo
# description: Read the GFH file informatino.
# input:       Binary file handle reference, GFH file info reference
# output:      GFH file information
# need init:   No
#****************************************************************************
sub ReadGFHFileInfo
{
   # struct GFH_FILE_INFO_v1
   #   GFH_Header      m_gfh_hdr;
   #   char            m_identifier[12];
   #   U32             m_file_ver;
   #   U16             m_file_type;
   #   U8              m_flash_dev;
   #   U8              m_sig_type;
   #   U32             m_load_addr;
   #   U32             m_file_len;
   #   U32             m_max_size;
   #   U32             m_content_offset;
   #   U32             m_sig_len;
   #   U32             m_jump_offset;
   #   U32             m_attr;

   my $input = shift;
   my $fileInfoRef = shift;
   my $buffer;
   my @result;
   my %header;

   # Read GFH header
   &ReadGFHHeader($input, \%header);
   &ErrorHandler("Invalid GFH file info header!", __FILE__, __LINE__)
      if (1 != $header{"m_ver"} or 56 != $header{"m_size"} or 0 != $header{"m_type"});

   # Read file info
   read $input, $buffer, 48; # The first 8 bytes were consumed by ReadGFHHeader
   @result = unpack("Z[12]LSCCLLLLLLL", $buffer);

   &ErrorHandler ("Error GFH header magic number!", __FILE__, __LINE__)
      if ("FILE_INFO" ne $result[0]);

   $fileInfoRef->{"m_gfh_hdr"} = \%header;
   $fileInfoRef->{"m_identifier"} = $result[0];
   $fileInfoRef->{"m_file_ver"} = $result[1];
   $fileInfoRef->{"m_file_type"} = $result[2];
   $fileInfoRef->{"m_flash_dev"} = $result[3];
   $fileInfoRef->{"m_sig_type"} = $result[4];
   $fileInfoRef->{"m_load_addr"} = $result[5];
   $fileInfoRef->{"m_file_len"} = $result[6];
   $fileInfoRef->{"m_max_size"} = $result[7];
   $fileInfoRef->{"m_content_offset"} = $result[8];
   $fileInfoRef->{"m_sig_len"} = $result[9];
   $fileInfoRef->{"m_jump_offset"} = $result[10];
   $fileInfoRef->{"m_attr"} = $result[11];
}

#****************************************************************************
# subroutine:  WriteGFHHeader
# description: Write the GFH header.
# input:       Binary file handle reference, GFH header reference
# output:      None
# need init:   No
#****************************************************************************
sub WriteGFHHeader
{
   # struct GFH_Header
   #   U32 m_magic_ver: 'M', 'M', 'M', version
   #   U16 m_size
   #   U16 m_type

   my $output = shift;
   my $headerRef = shift;
   my $buffer;
   my @result;

   $result[0] = 77;
   $result[1] = 77;
   $result[2] = 77;
   $result[3] = $headerRef->{"m_ver"};
   $result[4] = $headerRef->{"m_size"};
   $result[5] = $headerRef->{"m_type"};

   $buffer = pack("C[3]CSS", @result);

   print $output $buffer;
}

#****************************************************************************
# subroutine:  WriteGFHFileInfo
# description: Write the GFH file informatino.
# input:       Binary file handle reference, GFH file info reference
# output:      None
# need init:   No
#****************************************************************************
sub WriteGFHFileInfo
{
   # struct GFH_FILE_INFO_v1
   #   GFH_Header      m_gfh_hdr;
   #   char            m_identifier[12];
   #   U32             m_file_ver;
   #   U16             m_file_type;
   #   U8              m_flash_dev;
   #   U8              m_sig_type;
   #   U32             m_load_addr;
   #   U32             m_file_len;
   #   U32             m_max_size;
   #   U32             m_content_offset;
   #   U32             m_sig_len;
   #   U32             m_jump_offset;
   #   U32             m_attr;

   my $output = shift;
   my $fileInfoRef = shift;
   my $buffer;
   my @result;

   # Write GFH header
   &WriteGFHHeader($output, $fileInfoRef->{"m_gfh_hdr"});

   # Write file info
   $result[0] = $fileInfoRef->{"m_identifier"};
   $result[1] = $fileInfoRef->{"m_file_ver"};
   $result[2] = $fileInfoRef->{"m_file_type"};
   $result[3] = $fileInfoRef->{"m_flash_dev"};
   $result[4] = $fileInfoRef->{"m_sig_type"};
   $result[5] = $fileInfoRef->{"m_load_addr"};
   $result[6] = $fileInfoRef->{"m_file_len"};
   $result[7] = $fileInfoRef->{"m_max_size"};
   $result[8] = $fileInfoRef->{"m_content_offset"};
   $result[9] = $fileInfoRef->{"m_sig_len"};
   $result[10] = $fileInfoRef->{"m_jump_offset"};
   $result[11] = $fileInfoRef->{"m_attr"};
   $result[12] = 4095;

   $buffer = pack("Z[12]LSCCLLLLLLL", @result);
   print $output $buffer;
}

#****************************************************************************
# subroutine:  UpdateGFHFileInfo
# description: Update the GFH file info in the binary.
# input:       Binary path, hash ref includes the new values
# output:      None
# need init:   No
#****************************************************************************
sub UpdateGFHFileInfo
{
   my $binary = shift;
   my $diffInfoRef = shift;
   my %fileInfo;

   # Read the original GFH file info
   open my $inout, "+<$binary" or &ErrorHandler("Cannot open binary $binary: $!", __FILE__, __LINE__);
   binmode $inout;
   &ReadGFHFileInfo($inout, \%fileInfo);

   # Update the entry
   while (my ($key, $value) = each (%$diffInfoRef))
   {
      &ErrorHandler("Unrecognizable GFH file info entry $key!", __FILE__, __LINE__)
         unless exists $fileInfo{$key};

      $fileInfo{$key} = $value;
   }

   # Write to modified GFH file info
   seek $inout, 0, 0;
   &WriteGFHFileInfo($inout, \%fileInfo);

   close $inout;
}

#****************************************************************************
# subroutine:  ReadVIVAInfo
# description: Read the VIVA information from the binary.
# input:       Binary name, VIVA info reference
# output:      VIVA info
# need init:   Yes
#****************************************************************************
sub ReadVIVAInfo
{
   my $input = shift;
   my $infoRef = shift;

   &ReadVIVAInfo_NI($input, $infoRef, &IsSV5());
}

#****************************************************************************
# subroutine:  ReadVIVAInfo_NI
# description: Read the VIVA information from the binary.
# input:       Binary name, VIVA info reference
# output:      VIVA info
# need init:   No
#****************************************************************************
sub ReadVIVAInfo_NI
{
   # struct VIVA_HEADER
   #   U32 viva_base
   #   U32 zimage_base
   #   U32 boot_zimage_base
   #   U32 dcmcmp_base
   #   U32 alice_base

   my $input = shift;
   my $infoRef = shift;
   my $isSV5 = shift;

   my $buffer;
   my @result;

   if ($isSV5)
   {
      # Read and save the GFH for further use
      my %GFHFileInfo;
      &ReadGFHFileInfo($input, \%GFHFileInfo);
      $infoRef->{"GFH_FILE_INFO"} = \%GFHFileInfo;
   }

   # Read the VIVA info
   read $input, $buffer, 32;
   @result = unpack("LLLLL", $buffer);

   $infoRef->{"viva_base"} = $result[0];
   $infoRef->{"zimage_base"} = $result[1];
   $infoRef->{"boot_zimage_base"} = $result[2];
   $infoRef->{"dcmcmp_base"} = $result[3];
   $infoRef->{"alice_base"} = $result[4];
}

#****************************************************************************
# subroutine:  ReadVIVAInfoFromBinary_NI
# description: Read the VIVA information from the binary.
# input:       Binary name, VIVA info reference
# output:      VIVA info
# need init:   No
#****************************************************************************
sub ReadVIVAInfoFromBinary_NI
{
   my $binary = shift;
   my $infoRef = shift;
   my $isSV5 = shift;

   open my $input, "<$binary" or
      &ErrorHandler("Cannot open binary $binary: $!", __FILE__, __LINE__);
   binmode $input;

   ReadVIVAInfo_NI($input, $infoRef, $isSV5);

   close $input;
}

#****************************************************************************
# subroutine:  WriteVIVAInfo
# description: Write the VIVA information to the binary.
# input:       Binary name, VIVA info reference
# output:      None
# need init:   Yes
#****************************************************************************
sub WriteVIVAInfo
{
   # struct VIVA_HEADER
   #   U32 viva_base
   #   U32 zimage_base
   #   U32 boot_zimage_base
   #   U32 dcmcmp_base
   #   U32 alice_base

   my $output = shift;
   my $infoRef = shift;

   my $buffer;
   my @result;

   if (&IsSV5())
   {
      &WriteGFHFileInfo($output, $infoRef->{"GFH_FILE_INFO"});
   }

   # Write the VIVA info
   $result[0] = $infoRef->{"viva_base"};
   $result[1] = $infoRef->{"zimage_base"};
   $result[2] = $infoRef->{"boot_zimage_base"};
   $result[3] = $infoRef->{"dcmcmp_base"};
   $result[4] = $infoRef->{"alice_base"};

   $buffer = pack("LLLLL", @result);
   print $output $buffer;
}

#****************************************************************************
# subroutine:  SplitBinaryBySize
# description: Split the binary to several part by the input size.
# input:       Binary path, size array ref, filename array ref
# output:      The result binary number
# need init:   No
#****************************************************************************
sub SplitBinaryBySize
{
   my $binary = shift;
   my $sizeArrayRef = shift;
   my $filenameArrayRef = shift;
   my $buffer;
   my $readCount;
   my $imageCount = 0;

   #&ErrorHandler("The size number is different to filename number!", __FILE__, __LINE__)
   #   if (scalar(@$sizeArrayRef) != scalar(@$filenameArrayRef));

   open my $input, "<$binary" or &ErrorHandler("Cannot open binary $binary: $!", __FILE__, __LINE__);
   binmode $input;

   for (my $i = 0; $i < scalar(@$sizeArrayRef); ++$i)
   {
      if (not defined $filenameArrayRef->[$i] or $filenameArrayRef->[$i] eq "")
      {
         &ErrorHandler("Invalid filename while split file!", __FILE__, __LINE__)
      }

      open my $output, ">$filenameArrayRef->[$i]"
         or &ErrorHandler("Cannot open binary $filenameArrayRef->[$i]: $!", __FILE__, __LINE__);
      binmode $output;

      $readCount = read $input, $buffer, $sizeArrayRef->[$i];
      print $output $buffer;

      close $output;

      ++$imageCount;
      last if $readCount < $sizeArrayRef->[$i];
   }

   close $input;

   return $imageCount;
}

#****************************************************************************
# subroutine:  SplitBinaryByGFH
# description: Split the binary to three part: GFH, body, signature according
#              to the information in GFH.
# input:       Binary path, GFH filename, body filename, signature filename
# output:      The result binary number
# need init:   No
#****************************************************************************
sub SplitBinaryByGFH
{
   my $binary = shift;
   my @filenameArray = (shift, shift, shift);
   #my $GFHFilename = shift;
   #my $bodyFilename = shift;
   #my $signatureFilename = shift;
   my @sizeArray;
   my %fileInfo;
   my $binarySize = -s $binary;

   open my $input, "<$binary" or &ErrorHandler("Cannot open binary $binary: $!", __FILE__, __LINE__);
   binmode $input;

   &ReadGFHFileInfo($input, \%fileInfo);
   close $input;

   @sizeArray = ($fileInfo{"m_content_offset"},
                 $binarySize - $fileInfo{"m_content_offset"} - $fileInfo{"m_sig_len"},
                 $fileInfo{"m_sig_len"});

   return &SplitBinaryBySize($binary, \@sizeArray, \@filenameArray);
}

#****************************************************************************
# subroutine:  ConcatenateBinary
# description: Concatenate binaries.
# input:       Destination file handle ref, source filename array ref
# output:      None
# need init:   No
#****************************************************************************
sub ConcatenateBinary
{
   my $output = shift;
   my $sourceArrayRef = shift;
   my $pool;
   my $readSize;

   foreach my $source (@$sourceArrayRef)
   {
      open my $input, "<$source" or &ErrorHandler("Cannot open binary $source: $!", __FILE__, __LINE__);
      binmode $input;

      do
      {
         $readSize = read $input, $pool, 1048576;
         print $output $pool;
      } while ($readSize == 1048576);

      close $input;
   }
}

#****************************************************************************
# subroutine:  RoundUpToAlignment
# description: Increase the input number to the required alignment.
# input:       Number, alignment
# output:      Aligned number
# need init:   No
#****************************************************************************
sub RoundUpToAlignment
{
   my $number = shift;
   my $alignment = shift;

   my $remainder = $number % $alignment;

   if ($remainder)
   {
      return $number + $alignment - $remainder;
   }
   else
   {
      return $number;
   }
}

#****************************************************************************
# subroutine:  RoundDownToAlignment
# description: Decrease the input number to the required alignment.
# input:       Number, alignment
# output:      Aligned number
# need init:   No
#****************************************************************************
sub RoundDownToAlignment
{
   my $number = shift;
   my $alignment = shift;

   my $remainder = $number % $alignment;

   if ($remainder)
   {
      return $number - $remainder;
   }
   else
   {
      return $number;
   }
}

#****************************************************************************
# subroutine:  PaddingBinaryToAlignment
# description: Add padding after a binary to target alignment requirement.
# input:       Binary path, alignment
# output:      Byte added
# need init:   No
#****************************************************************************
sub PaddingBinaryToAlignment
{
   my $binary = shift;
   my $alignment = shift;
   my $binarySize = -s $binary;

   open my $output, ">>$binary" or &ErrorHandler("Cannot open binary $binary: $!", __FILE__, __LINE__);
   binmode $output;

   my $alignedSize = RoundUpToAlignment($binarySize, $alignment);
   my $writeCount = $alignedSize - $binarySize;

   my $buffer = pack("C[$writeCount]", 0);
   print $output $buffer;

   close $output;

   return $writeCount;
}

#****************************************************************************
# subroutine:  GetLISLoadRegionInfo
# description: Get the LIS load region information
# input:       Load region name, info hash ref
# output:      Info hash
# need init:   Yes
#****************************************************************************
sub GetLISLoadRegionInfo
{
   my $regionName = shift;
   my $infoRef = shift;
   my @result = &LISInfo::GetLoadRegionInfo($regionName, 0);

   $infoRef->{"base_address"} = $result[0];
   $infoRef->{"actual_size"} = $result[1];
   $infoRef->{"max_size"} = $result[2];
   $infoRef->{"attribute"} = $result[3];
}

#****************************************************************************
# subroutine:  GetLISExecutionRegionInfo
# description: Get the LIS execution region information
# input:       Execution region name, info hash ref
# output:      Info hash
# need init:   Yes
#****************************************************************************
sub GetLISExecutionRegionInfo
{
   my $regionName = shift;
   my $infoRef = shift;
   my @result = &LISInfo::GetExeRegionInfo($regionName, 0);

   $infoRef->{"base_address"} = $result[0];
   $infoRef->{"actual_size"} = $result[1];
   $infoRef->{"max_size"} = $result[2];
   $infoRef->{"attribute"} = $result[3];
}

#****************************************************************************
# subroutine:  GetLISExecutionRegionObjectInfo
# description: Get the LIS execution region object list with size
# input:       Execution region name, list array ref
# output:      Padding size in the region, list array
# need init:   Yes
#****************************************************************************
sub GetLISExecutionRegionObjectList
{
   my $regionName = shift;
   my $listRef = shift;
   my $attribute = shift;
   my $category = shift;
   my $result = &LISInfo::GetObjTotalSizesByExeRegion($regionName);
   my %resultHash;

   my @infoList;

   my $totalSize = 0;

   #foreach my $key (keys %$result)
   #{
   #   if ($key =~ /(.+)::(.*)/)
   #   {
   #      if (exists $resultHash{$1})
   #      {
   #         $resultHash{$1} += $result->{$key};
   #      }
   #      else
   #      {
   #         $resultHash{$1} = $result->{$key};
   #      }
   #      $totalSize += $result->{$key};
   #   }
   #}

   foreach my $key (keys %$result)
   {
      if ($key =~ /(.+)::(.*)/)
      {
         push @infoList, {"name" => $1, "library" => $2, "size" => $result->{$key}};
      }
   }

   &objListHelper::InputObjectListFromLISInfo(\@infoList, $listRef, $attribute, $category);

   if (exists $result->{"PAD"})
   {
      return $result->{"PAD"};
   }
   else
   {
      return 0;
   }
}

#****************************************************************************
# subroutine:  GetLISTotalSize
# description: Get the total size information in LIS
# input:       Info hash ref
# output:      Info hash
# need init:   Yes
#****************************************************************************
sub GetLISTotalSize
{
   my $infoRef = shift;

   $infoRef->{"RO"} = &LISInfo::GetTotalROSize(0);
   $infoRef->{"RW"} = &LISInfo::GetTotalRWZISize(0);
   $infoRef->{"ROM"} = &LISInfo::GetTotalROMSize(0);
}

#****************************************************************************
# subroutine:  GetScatterReservedSize
# description: Get the estimated total ROM size with provided VIVA size
# input:       VIVA size
# output:      Estimated total size
# need init:   Yes
#****************************************************************************
sub GetScatterReservedSize
{
   my $fsBase = shift;
   return &LISInfo::GetScatterReservedSize(\%makefileOptions, $fsBase);
}

#****************************************************************************
# subroutine:  InputObjectListFromFile
# description: Get a new object list from the specified file.
# input:       Input filename, object list ref
# output:      Object list
# need init:   No
#****************************************************************************
sub InputObjectListFromFile
{
   my $filename = shift;
   my $objectListRef = shift;

   &objListHelper::InputObjectListFromObjListFile($filename, $objectListRef);
}

#****************************************************************************
# subroutine:  OutputObjectListToFile
# description: Put the object list to the specified file.
# input:       Output filename, object list ref
# output:      Output to file
# need init:   No
#****************************************************************************
sub OutputObjectListToFile
{
   my $filename = shift;
   my $objectListRef = shift;

   &objListHelper::OutputObjectListToObjListFile($filename, $objectListRef, "        ");
}

#****************************************************************************
# subroutine:  CompareObjectList
# description: Compare two object list.
# input:       First object list, second object list
# output:      0 for equal; 1 for larger; -1 for smaller
# need init:   No
#****************************************************************************
sub CompareObjectList
{
   my $firstList = shift;
   my $secondList = shift;

   return &objListHelper::CompareObjectList($firstList, $secondList);
}

#****************************************************************************
# subroutine:  SortObjectListByCategory
# description: Sort the object list by the category.
# input:       Object list ref.
# output:      Sorted object list
# need init:   No
#****************************************************************************
sub SortObjectList
{
   my $listRef = shift;
   &objListHelper::SortObjectListByCategory($listRef);
}

#****************************************************************************
# subroutine:  SplitObjectListBySize
# description: Split the object list into two part with specified size.
# input:       Source list ref, target size,
#              split list ref with target size, another split list ref
# output:      The split lists
# need init:   No
#****************************************************************************
sub SplitObjectListBySize
{
   my $sourceListRef = shift;
   my $targetSize = shift;
   my $firstListRef = shift;
   my $secondListRef = shift;

   my @sortedSourceList = sort {$b->{"size"} <=> $a->{"size"}} @$sourceListRef;
   my $remainingSize = $targetSize;

   foreach my $object (@sortedSourceList)
   {
      if ($remainingSize >= $object->{"size"})
      {
         $remainingSize -= $object->{"size"};
         push @$firstListRef, $object;
      }
      else
      {
         push @$secondListRef, $object;
      }
   }

   return ($targetSize - $remainingSize);
}

#****************************************************************************
# subroutine:  SplitObjectListByName
# description: Split the object list by a name list
# input:       Source list ref, name list,
#              split list ref with target names, another split list ref
# output:      The list with size
# need init:   No
#****************************************************************************
sub SplitObjectListByName
{
   my $sourceListRef = shift;
   my $targetNameList = shift;
   my $firstListRef = shift;
   my $secondListRef = shift;

   my %nameHash = map { $_ => 1 } @$targetNameList;

   foreach my $object (@$sourceListRef)
   {
      if (exists $nameHash{$object->{"name"}})
      {
         push @$firstListRef, $object;
      }
      else
      {
         push @$secondListRef, $object;
      }
   }
}

#****************************************************************************
# subroutine:  ChangeObjectListAttributeListByObjectList
# description: Chagne the attribute list of each object in the list by
#              the specified object list.
# input:       Target object ref, source object ref
# output:      Target object ref
# need init:   No
#****************************************************************************
sub ChangeObjectListAttributeListByObjectList
{
   my $targetObjectListRef = shift;
   my $sourceObjectListRef = shift;

   &objListHelper::ChangeObjectListAttributeListByObjectList($targetObjectListRef, $sourceObjectListRef);
}

#****************************************************************************
# subroutine:  DecToHex
# description: Transform decimal number to hex.
# input:       Decimal number
# output:      Hex number in 0xXXXXXXXX format
# need init:   No
#****************************************************************************
sub DecToHex
{
   return sprintf("0x%08X", $_[0]);
}

#****************************************************************************
# subroutine:  ErrorHandler
# description: Handle the post process error and output the error message.
#              Note calling this function will lead program terminated.
# input:       Message, source filename, line number
# output:      None
# need init:   Yes/No
#****************************************************************************
sub ErrorHandler
{
   my ($message, $file, $line) = @_;

   my $errorMessage = "VIVA ERROR: $message at $file line $line\n";
   print $errorMessage;

   if (defined $executionType and $executionType eq CONFIG_TYPE)
   {
      die $errorMessage;
   }
   else
   {
      exit 1;
   }
}

1;
