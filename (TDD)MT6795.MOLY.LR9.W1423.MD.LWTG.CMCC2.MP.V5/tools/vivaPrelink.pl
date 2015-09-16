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
#*   vivaPrelink.pl
#*
#* Project:
#* --------
#*   Maui_Software
#*
#* Description:
#* ------------
#*   This file implemented the VIVA prelink process.
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

#****************************************************************************
# History
#****************************************************************************
my $VIVA_PRELINK_VERNO = " v1.00";
   # v1.00: Phase in VIVA

#****************************************************************************
# Constants
#****************************************************************************
my $DEBUG = 1;
my $afOverlapListName = "objectAF_Overlap.list";
my $afOverlapLibraryName = "af_overlap.lib";
my $separateLine = "=============================================================";

#****************************************************************************
# Arguments
#****************************************************************************
&vivaHelper::ErrorHandler("Insufficient arguments!", __LINE__, __FILE__)
   unless scalar(@ARGV) == 5;

my $customFolder = $ARGV[0];
my $libraryFolder = $ARGV[1];
my $objectFolder = $ARGV[2];
my $makefilePath = $ARGV[3];
my $outputFilePath = $ARGV[4];

# To align error message file name format
$customFolder =~ s/^.\\|^\\//;
$libraryFolder =~ s/^.\\|^\\//;
$objectFolder   =~ s/^.\\|^\\//;
$makefilePath   =~ s/^.\\|^\\//;
$outputFilePath   =~ s/^.\\|^\\//;

# Print out the arguments
printLog($separateLine);
printLog("Arguments:");
printLog("Custom Folder: $customFolder");
printLog("Library Folder: $libraryFolder");
printLog("Object Folder: $objectFolder");
printLog("Makefile: $makefilePath");
printLog("Output File: $outputFilePath");
printLog("");

#****************************************************************************
# Variables
#****************************************************************************
my $afOverlapList = "$customFolder\\$afOverlapListName";
my $afOverlapLibrary = "$libraryFolder\\$afOverlapLibraryName";

#****************************************************************************
# Process
#****************************************************************************
exit 0;

printLog("[Start VIVA prelink]");

&vivaHelper::Initialize(&vivaHelper::PROCESS_TYPE, $makefilePath);

# Check feature options
{
   my $zImageOption = &vivaHelper::GetMakefileOption("ZIMAGE_SUPPORT");
   my $aliceOption = &vivaHelper::GetMakefileOption("ALICE_SUPPORT");

   unless ((defined $zImageOption and $zImageOption eq "TRUE") and
           (defined $aliceOption and $aliceOption eq "TRUE"))
   {
      printLog("No need of prelinking");
      goto END_PROCESS;
   }
}

# ALICE Prelink process
{
   my %objectAFOverlapHash;
   my @libraryList;

   # Get AF overlap list hash
   {
      printLog("Getting AF overlap list...");
      # Read AF overlap list
      my @objectAFOverlapList;
      &vivaHelper::InputObjectListFromFile($afOverlapList, \@objectAFOverlapList);

      # Change to AF overlap list to hash form
      foreach my $object (@objectAFOverlapList)
      {
         $objectAFOverlapHash{"$object->{name}"} = 1;
         debugLog("$object->{name}");
      }
   }

   # Delete the original AF overlap library
   unlink($afOverlapLibrary) if -e $afOverlapLibrary;

   # Move the AF overlap objects
   {
      printLog("Getting all object list...");
      my @allObjectList;
      &getFileList($objectFolder, \@allObjectList);

      my %deleteObjectHash;
      my $addObjectString = "";

      printLog("Matching overlap object...");
      foreach my $object (@allObjectList)
      {
         if ($object =~ /\\([\w\.]+)\\([\w\.]+)$/)
         {
            # Check if in the AF overlap list
            if ($objectAFOverlapHash{$2})
            {
               # Mark the file as processed
               $objectAFOverlapHash{$2} = 0;

               if (exists $deleteObjectHash{$1})
               {
                  $deleteObjectHash{$1} .= "$2 ";
               }
               else
               {
                  $deleteObjectHash{$1} = "$2 ";
               }

               $addObjectString .= "$object "
            }
         }
      }

      printLog("Adding objects...");
      debugLog("$_") foreach split(/ /, $addObjectString);
      &addLibraryFile($afOverlapLibrary, $addObjectString);

      printLog("Deleting objects...");
      while (my ($key, $value) = each %deleteObjectHash)
      {
         debugLog("$key: $value");
         &deleteLibraryFile("$libraryFolder\\$key.lib", $value);
      }
   }

   # Output the library name to the output file
   if (-e $afOverlapLibrary)
   {
      open my $output, ">$outputFilePath"  or
         &vivaHelper::ErrorHandler("Cannot open file $outputFilePath: $!", __FILE__, __LINE__);

      print $output $afOverlapLibraryName;

      close $output;
   }

   # Print out the non-processed list
   printLog("\nNon-processed objects");
   while (my ($key, $value) = each %objectAFOverlapHash)
   {
      printLog("\t$key") if ($value);
   }
}


END_PROCESS:

printLog("[End VIVA prelink]");
exit 0;

#****************************************************************************
# subroutine:  getFileList
# description: Get all the file list under the folder.
# input:       Folder path, file list ref
# output:      File list
#****************************************************************************
sub getFileList
{
   my $folderPath = shift;
   my $fileListRef = shift;

   system("dir $folderPath /S /B > ~listTemp.tmp");
   open my $input, "<~listTemp.tmp";
   while (<$input>)
   {
      chomp;
      push @$fileListRef, $_;
   }
   close $input;

   unlink("~listTemp.tmp");
}

#****************************************************************************
# subroutine:  getLibraryFileList
# description: Get the file list in a library.
# input:       Library path, library file list ref
# output:      Library file list
#****************************************************************************
sub getLibraryFileList
{
   my $library = shift;
   my $listRef = shift;

   my $result = `armar -t $library 2>&1`;

   if ($result =~ /Error:/)
   {
      &vivaHelper::ErrorHandler("Fail to get library content files $library $result", __FILE__, __LINE__);
   }
   else
   {
      @$listRef = split(/\n/, $result);
   }
}


#****************************************************************************
# subroutine:  addLibraryFile
# description: Add the files to the library.
# input:       Library, files
# output:      None
#****************************************************************************
sub addLibraryFile
{
   my $library = shift;
   my $files = shift;

   my $result;

   open my $output, ">~tempVIAFile.tmp";
   print $output $files;
   close $output;

   if (-e $library)
   {
      $result = `armar -r $library -via ~tempVIAFile.tmp 2>&1`;
   }
   else
   {
      $result = `armar --create $library -via ~tempVIAFile.tmp 2>&1`;
   }

   unlink("~tempVIAFile.tmp");

   if ($result =~ /Error/)
   {
      &vivaHelper::ErrorHandler("Fail to add library content files $library $result", __FILE__, __LINE__);
   }
}

#****************************************************************************
# subroutine:  deleteLibraryFile
# description: Delete the files from the library.
# input:       Library, files
# output:      None
#****************************************************************************
sub deleteLibraryFile
{
   my $library = shift;
   my $files = shift;

   my $result;

   # Delete files one by one for only remake some module case
   foreach my $file (split(/ /, $files))
   {
      $result = `armar -d $library $file 2>&1`;

      chomp $result;

      if ($result =~ /Error/)
      {
         printLog("Warning: Cannot delete library content file $file from $library. $result");
         #&vivaHelper::ErrorHandler("Fail to delete library content files $library $result", __FILE__, __LINE__);
      }
   }
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

# tools\vivaPrelink.pl .\custom\system\MT6250_EVB .\build\MT6250_EVB\gprs\MT6250o\lib .\build\MT6250_EVB\gprs\MT6250o .\make\MT6250_EVB_GPRS.mak .\output.txt >tempVIVA.txt
