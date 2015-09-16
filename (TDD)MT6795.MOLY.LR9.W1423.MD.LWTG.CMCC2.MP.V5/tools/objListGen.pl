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
#*   objListGen.pl
#*
#* Project:
#* --------
#*   Maui_Software
#*
#* Description:
#* ------------
#*   This file generate the object list for scatter file including.
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
BEGIN { push @INC, './tools/' }  # add additional library path
use File::Copy;
use File::Basename;
use File::Path;
use Storable qw/lock_retrieve lock_nstore/;
use objListHelper;
use FileInfoParser;
use tools::pack_dep_gen;

PrintDependModule();

#****************************************************************************
# History
#****************************************************************************
my $OBJ_LIST_GEN_VERNO = " v1.01";
   # v1.02: Phase in PrintDependency
   # v1.01: Phase in BOOT_ZIMAGE
   # v1.00: Phase in object list generate mechanism

#****************************************************************************
# Constants
#****************************************************************************
my $DEBUG = 1;
my $templateFolderPath  = "custom/system/Template";
my $objectListGenFolderPath = "scat_config/FeatureBased/ObjListGen";

# Feature option
my $featureOptionBackupFileName = "object.list.backup";

# Source
my $aliceForbidListFileName = "AliceForbidList.csv";
my $bootZImageForbidListFileName = "BootZImageForbidList.csv";
my $zImageForbidListFileName = "ZImageForbidList.csv";

# Source backup
my $aliceForbidListBackupFileName = "AliceForbidList.csv.backup";
my $bootZImageForbidListBackupFileName = "BootZImageForbidList.csv.backup";
my $zImageForbidListBackupFileName = "ZImageForbidList.csv.backup";

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

my $separateLine = "=============================================================";

#****************************************************************************
# Arguments
#****************************************************************************
&objListHelper::ErrorHandler("Insufficient arguments! ".scalar(@ARGV), __LINE__, __FILE__)
   unless scalar(@ARGV) >= 2;

my $customFolder = $ARGV[0];
my $makefilePath = $ARGV[1];
my $forceDummyScatter = $ARGV[2];
$forceDummyScatter = "FALSE" unless defined $forceDummyScatter;

# To align error message file name format
$customFolder =~ s/^.\/|^\///;
$makefilePath =~ s/^.\/|^\///;

# Print out the arguments
printLog($separateLine);
printLog("Arguments:");
printLog("Custom Folder: $customFolder");
printLog("Makefile: $makefilePath");
printLog("Force Dummy Scatter: $forceDummyScatter");
printLog("");

#****************************************************************************
# Variables
#****************************************************************************
# Files
my $sourceCSVFolder = "$templateFolderPath/$objectListGenFolderPath";
my $destinationListFolder = "$customFolder/$objectListGenFolderPath";

# Source files
my $aliceForbidListFile = "$sourceCSVFolder/$aliceForbidListFileName";
my $bootZImageForbidListFile = "$sourceCSVFolder/$bootZImageForbidListFileName";
my $zImageForbidListFile = "$sourceCSVFolder/$zImageForbidListFileName";

# Source backup files
my $featureOptionBackupFile = "$sourceCSVFolder/$featureOptionBackupFileName";
my $aliceForbidListBackupFile = "$sourceCSVFolder/$aliceForbidListBackupFileName";
my $bootZImageForbidListBackupFile = "$sourceCSVFolder/$bootZImageForbidListBackupFileName";
my $zImageForbidListBackupFile = "$sourceCSVFolder/$zImageForbidListBackupFileName";

# Normal scatter
my $objectROM1ListFile = "$destinationListFolder/$objectROM1ListFileName";
my $objectBootZImageListFile = "$destinationListFolder/$objectBootZImageListFileName";
my $objectZImageListFile = "$destinationListFolder/$objectZImageListFileName";
my $objectAliceListFile = "$destinationListFolder/$objectAliceListFileName";

# Dummy scatter
my $objectROM1DummyListFile = "$destinationListFolder/$objectROM1DummyListFileName";
my $objectBootZImageDummyListFile = "$destinationListFolder/$objectBootZImageDummyListFileName";
my $objectZImageDummyListFile = "$destinationListFolder/$objectZImageDummyListFileName";
my $objectAliceDummyListFile = "$destinationListFolder/$objectAliceDummyListFileName";
my $objectAliceForbidDummyListFile = "$destinationListFolder/$objectAliceForbidDummyListFileName";

# Feature switches
my $aliceEnabled = 0;
my $bootZImageEnabled = 0;
my $zImageEnabled = 0;

my $isDummyScatter = 0;

# Source file changed
my $aliceForbidListFileChanged = 0;
my $bootZImageForbidListFileChanged = 0;
my $zImageForbidListFileChanged = 0;

# Source object lists
my @aliceForbidList;
my @bootZImageForbidList;
my @zImageForbidList;

# Output object lists
my %outputObjectLists =
(
   "ROM1"               => {"list" => [], "generate" => 0, "list_file" => $objectROM1ListFile},
   "BOOT_ZIMAGE"        => {"list" => [], "generate" => 0, "list_file" => $objectBootZImageListFile},
   "ZIMAGE"             => {"list" => [], "generate" => 0, "list_file" => $objectZImageListFile},
   "ALICE"              => {"list" => [], "generate" => 0, "list_file" => $objectAliceListFile},
   "ROM1_DUMMY"         => {"list" => [], "generate" => 0, "list_file" => $objectROM1DummyListFile},
   "BOOT_ZIMAGE_DUMMY"  => {"list" => [], "generate" => 0, "list_file" => $objectBootZImageDummyListFile},
   "ZIMAGE_DUMMY"       => {"list" => [], "generate" => 0, "list_file" => $objectZImageDummyListFile},
   "ALICE_DUMMY"        => {"list" => [], "generate" => 0, "list_file" => $objectAliceDummyListFile},
   "ALICE_FORBID_DUMMY" => {"list" => [], "generate" => 0, "list_file" => $objectAliceForbidDummyListFile}
);

exit 0;

#****************************************************************************
# Initialize
#****************************************************************************
printLog($separateLine);
printLog("[Start initializing stage]");

# Initialize the environment
&initialize();

printLog("[End initializing stage]\n");

#****************************************************************************
# Process ALICE Forbid List
#****************************************************************************
printLog($separateLine);
printLog("[Start processing ALICE forbid list stage]");

if (&processAliceForbidList())
{
   printLog("Process completed");
}
else
{
   printLog("Process skipped");
}

printLog("[End processing ALICE forbid list stage]\n");

#****************************************************************************
# Process ZIMAGE Forbid List
#****************************************************************************
printLog($separateLine);
printLog("[Start prcoessing ZIMAGE forbid list stage]");

if (&processZImageForbidList())
{
   printLog("Process completed");
}
else
{
   printLog("Process skipped");
}

printLog("[End prcoessing ZIMAGE fobid list stage]\n");

#****************************************************************************
# Process BOOT_ZIMAGE Forbid List
#****************************************************************************
printLog($separateLine);
printLog("[Start processing BOOT_ZIMAGE forbid list stage]");

if (&processBootZImageForbidList())
{
   printLog("Process completed");
}
else
{
   printLog("Process skipped");
}

printLog("[End processing BOOT_ZIMAGE forbid list stage]\n");

#****************************************************************************
# Output to files
#****************************************************************************
printLog($separateLine);
printLog("[Start outputing stage]");
{
   foreach my $objectList (values %outputObjectLists)
   {
      if ($objectList->{"generate"})
      {
         my @filename = fileparse($objectList->{"list_file"});
         printLog("Generate $filename[0]");
         &objListHelper::SortObjectListByCategory($objectList->{"list"});
         &objListHelper::OutputObjectListToObjListFile($objectList->{"list_file"}, $objectList->{"list"}, "        ");
      }
      #elsif (-e $objectList->{"list_file"} and not $objectList->{"manual_modified"})
      #{
      #   unlink $objectList->{"list_file"} or
      #      &objListHelper::ErrorHandler("Fail to delete file $objectList->{list_file} $!", __FILE__, __LINE__);
      #}
   }
}
printLog("[End outputing stage]\n");


sub initialize
{
   my %makefileOptions;

   # Check the feature set
   {
      printLog("Checking feature set...");

      # Parse makefile
      if (0 == &FileInfo::Parse_MAKEFILE($makefilePath, \%makefileOptions))
      {
         &objListHelper::ErrorHandler("Fail to parse makefile $makefilePath $!", __FILE__, __LINE__);
      }

      $aliceEnabled = &_checkFeatureOption("ALICE", "ALICE_SUPPORT", "TRUE", \%makefileOptions);
      $bootZImageEnabled = &_checkFeatureOption("BOOT_ZIMAGE", "BOOT_ZIMAGE_SUPPORT", "TRUE", \%makefileOptions);
      $zImageEnabled = &_checkFeatureOption("ZIMAGE", "ZIMAGE_SUPPORT", "TRUE", \%makefileOptions);

      # Check dummy scatter
      {
         my $option = $makefileOptions{"DUMMY_SCATTER_ENABLE"};
         if ((defined $option and $option eq "TRUE") or ($forceDummyScatter eq "TRUE"))
         {
            debugLog("DUMMY_SCATTER is enabled");
            $isDummyScatter = 1;
         }
      }

      # Check if the feature options are changed
      {
         my $featureOptionChanged = 0;

         if (-e $featureOptionBackupFile)
         {
            $featureOptionChanged = 1 if not &_isFileContentMatch($makefilePath, $featureOptionBackupFile);
         }
         else
         {
            $featureOptionChanged = 1;
         }

         if ($featureOptionChanged)
         {
            copy($makefilePath, $featureOptionBackupFile) or
               &objListHelper::ErrorHandler("Fail to backup file $makefilePath $!", __FILE__, __LINE__);
            _removeObjectLists();
         }
      }
   }

   # Parse source object lists
   {
      printLog("Parsing source object lists...");

      if ($aliceEnabled)
      {
         $aliceForbidListFileChanged =
            &_getSourceObjectList("ALICE Forbidden List", $aliceForbidListFile, \@aliceForbidList,
                                  \%makefileOptions, $aliceForbidListBackupFile);
      }

      if ($bootZImageEnabled)
      {
         $bootZImageForbidListFileChanged =
            &_getSourceObjectList("BOOT_ZIMAGE Forbidden List", $bootZImageForbidListFile, \@bootZImageForbidList,
                                  \%makefileOptions, $bootZImageForbidListBackupFile);
      }

      if ($zImageEnabled)
      {
         $zImageForbidListFileChanged =
            &_getSourceObjectList("ZIMAGE Forbidden List", $zImageForbidListFile, \@zImageForbidList,
                                  \%makefileOptions, $zImageForbidListBackupFile);
      }
   }

   # Check manual checking of output object lists
   #{
   #   printLog("Check manual modification of output object lists...");
   #
   #   foreach my $objectList (values %outputObjectLists)
   #   {
   #      if (&objListHelper::IsManualModified($objectList->{"list_file"}))
   #      {
   #         my @filename = fileparse($objectList->{"list_file"});
   #         debugLog("$filename[0] was manual modified");
   #
   #         $objectList->{"manual_modified"} = 1;
   #      }
   #   }
   #}

   # Generate ObjListGenPath: scat_config\FeatureBased\ObjListGen
   unless (-d $destinationListFolder)
   {
       mkpath($destinationListFolder)
         or &objListHelper::ErrorHandler("Fail to create folder $destinationListFolder $!", __FILE__, __LINE__);
   }
}

sub _checkFeatureOption
{
   my $featureName = shift;
   my $featureOption = shift;
   my $featureEnableValue = shift;
   my $makefileOptions = shift;

   my $result = 0;

   my $option = $makefileOptions->{$featureOption};
   if (defined $option and $option eq $featureEnableValue)
   {
      debugLog("$featureName is enabled");
      $result = 1;
   }

   return $result;
}

sub _isFileContentMatch
{
   my $firstFile = shift;
   my $secondFile = shift;

   if (&__getFileContent($firstFile) eq &__getFileContent($secondFile))
   {
      return 1;
   }
   else
   {
      return 0;
   }
}

sub __getFileContent
{
    my $sourceFile = shift;
    my $content;
    open FILE, "<$sourceFile" or
      &objListHelper::ErrorHandler("Fail to open file $sourceFile $!", __FILE__, __LINE__);
    {
        local $/;
        $content = <FILE>;
    }
    close FILE;
    chomp($content);
    return $content;
}

sub _getSourceObjectList
{
   my $listName = shift;
   my $sourceFile = shift;
   my $listRef = shift;
   my $makefileOptions = shift;
   my $backupFile = shift;
   my $sourceFileChanged = 0;

   debugLog("Get $listName");
   &objListHelper::InputObjectListFromCSVFile($sourceFile, $listRef, $makefileOptions);
   PrintDependency($sourceFile);

   if (-e $backupFile)
   {
      #my @backupList;
      #&objListHelper::InputObjectListFromCSVFile($backupFile, \@backupList, $makefileOptions);

      #if (0 != &objListHelper::CompareObjectList($listRef, \@backupList))
      unless (&_isFileContentMatch($sourceFile, $backupFile))
      {
         $sourceFileChanged = 1;

         copy($sourceFile, $backupFile) or
            &objListHelper::ErrorHandler("Fail to backup file $sourceFile $!", __FILE__, __LINE__);
      }
   }
   else
   {
      copy($sourceFile, $backupFile) or
         &objListHelper::ErrorHandler("Fail to backup file $sourceFile $!", __FILE__, __LINE__);

      $sourceFileChanged = 1;
   }

   if ($sourceFileChanged)
   {
      debugLog("$listName changed");
      _removeObjectLists();
   }
   else
   {
      debugLog("$listName not changed");
   }

   return $sourceFileChanged;
}

sub _removeObjectLists
{
   debugLog("Delete object lists");
   unlink $_->{"list_file"} foreach (values %outputObjectLists);
}

sub processAliceForbidList
{
   if ($aliceEnabled)
   {
      if ($zImageEnabled)
      {
         my @afList;
         my @afOverlapList;
         my @afzfList;

         &objListHelper::SplitObjectListByCheckList(\@aliceForbidList, \@zImageForbidList, \@afzfList, \@afOverlapList, \@afList);

         &objListHelper::ChangeObjectListAttributeList(\@afList, "+RO");
         &objListHelper::ChangeObjectListAttributeList(\@afOverlapList, "+RO-CODE");
         &objListHelper::ChangeObjectListAttributeList(\@afzfList, "+RO-CODE, +RO-DATA");

         my $isSourceChanged = $aliceForbidListFileChanged || $zImageForbidListFileChanged;

         if ($isDummyScatter)
         {
            &_pushToOutputObjectList("ALICE_FORBID_DUMMY", \@afList, $isSourceChanged);
            &_pushToOutputObjectList("ROM1_DUMMY", \@afOverlapList, $isSourceChanged);
            &_pushToOutputObjectList("ROM1_DUMMY", \@afzfList, $isSourceChanged);
            &_pushToOutputObjectList("ALICE_DUMMY", [], $isSourceChanged);
         }
         else
         {
            &_pushToOutputObjectList("ZIMAGE", \@afList, $isSourceChanged);
            &_pushToOutputObjectList("ROM1", \@afOverlapList, $isSourceChanged);
            &_pushToOutputObjectList("ROM1", \@afzfList, $isSourceChanged);
            &_pushToOutputObjectList("ALICE", [], $isSourceChanged);
         }
      }
      else
      {
         my $isSourceChanged = $aliceForbidListFileChanged;

         if ($isDummyScatter)
         {
            &_pushToOutputObjectList("ROM1_DUMMY", \@aliceForbidList, $isSourceChanged);
            &_pushToOutputObjectList("ALICE_DUMMY", [], $isSourceChanged);
         }
         else
         {
            &_pushToOutputObjectList("ROM1", \@aliceForbidList, $isSourceChanged);
            &_pushToOutputObjectList("ALICE", [], $isSourceChanged);
         }
      }

      return 1;
   }
   else
   {
      return 0;
   }
}

sub processZImageForbidList
{
   if ($zImageEnabled)
   {
      if ($aliceEnabled)
      {
         my @zfUnmatchedList = grep((not $_->{"matched"}), @zImageForbidList);

         my @zf_RList;
         my @zf_AList;
         my @zfafList;
         my @zfOverlapList;
         my @zfOnlyList;

         &objListHelper::SplitObjectListByCheckList(\@zfUnmatchedList, \@aliceForbidList, \@zfafList, \@zfOverlapList, \@zfOnlyList);

         # ZFAF list should have been empty if there were no wildcard symbol
         # Append this list to ZF only list since the priority is lower for wildcard
         push @zfOnlyList, @zfafList;
         &objListHelper::SortObjectListByCategory(\@zfOnlyList);

         # Specify the ZF overlap list to ROM1 with +RO-CODE, +RO-DATA since the libraries include them are in AF list
         foreach my $object (@zfOverlapList)
         {
            if ($object->{"attributes"}[0] eq "+RO")
            {
               $object->{"attributes"}[0] = "+RO-CODE";
               $object->{"attributes"}[1] = "+RO-DATA";
               push @zf_RList, $object;
            }
            else
            {
               push @zf_RList, $object;
            }
         }

         # The data part is in ROM1 and code part is in ALICE for ZF only list
         foreach my $object (@zfOnlyList)
         {
            if ($object->{"attributes"}[0] eq "+RO")
            {
               my %newObject = %$object;
               $object->{"attributes"}[0] = "+RO-DATA";
               push @zf_RList, $object;

               $newObject{"attributes"} = ["+RO"];
               push @zf_AList, \%newObject;
            }
            elsif ($object->{"attributes"}[0] eq "+RO-CODE")
            {
               push @zf_AList, $object;

               if (defined $object->{"attributes"}[1] and $object->{"attributes"}[1] eq "+RO-DATA")
               {
                  my %newObject = %$object;
                  $newObject{"attributes"} = ["+RO-DATA"];
                  push @zf_RList, \%newObject;
                  splice @{$object->{"attributes"}}, -1;
               }
            }
            else
            {
               push @zf_RList, $object;
            }
         }

         my $isSourceChanged = $zImageForbidListFileChanged || $aliceForbidListFileChanged;

         if ($isDummyScatter)
         {
            &_pushToOutputObjectList("ROM1_DUMMY", \@zf_RList, $isSourceChanged);
            &_pushToOutputObjectList("ALICE_DUMMY", \@zf_AList, $isSourceChanged);

            &_pushToOutputObjectList("ZIMAGE_DUMMY", [], $isSourceChanged);
         }
         else
         {
            &_pushToOutputObjectList("ROM1", \@zf_RList, $isSourceChanged);
            &_pushToOutputObjectList("ALICE", \@zf_AList, $isSourceChanged);

            &_pushToOutputObjectList("ZIMAGE", [], $isSourceChanged);
         }
      }
      else
      {
         my $isSourceChanged = $zImageForbidListFileChanged;

         if ($isDummyScatter)
         {
            &_pushToOutputObjectList("ROM1_DUMMY", \@zImageForbidList, $isSourceChanged);
            &_pushToOutputObjectList("ZIMAGE_DUMMY", [], $isSourceChanged);
         }
         else
         {
            &_pushToOutputObjectList("ROM1", \@zImageForbidList, $isSourceChanged);
            &_pushToOutputObjectList("ZIMAGE", [], $isSourceChanged);
         }
      }

      return 1;
   }
   else
   {
      return 0;
   }
}

sub processBootZImageForbidList
{
   if ($bootZImageEnabled)
   {
      my @bzList;
      my @afzfbzfList;
      my @afzfbzfOverlapList;

      my $isSourceChanged = $bootZImageForbidListFileChanged;

      # BOOT_ZIMAGE library problem workaround
      my @bootZImageNormalForbidList;
      my @bootZImageWorkaroundForbidList;

      foreach my $object (@bootZImageForbidList)
      {
         if ($object->{"category"} eq "Workaround")
         {
            push @bootZImageWorkaroundForbidList, $object;
         }
         else
         {
            push @bootZImageNormalForbidList, $object;
         }
      }

      if ($isDummyScatter)
      {
        #&objListHelper::SplitObjectListByCheckList(\@{$outputObjectLists{"ROM1_DUMMY"}{"list"}}, \@bootZImageForbidList, \@afzfbzfList, \@afzfbzfOverlapList, \@bzList);
         &objListHelper::SplitObjectListByCheckList(\@{$outputObjectLists{"ROM1_DUMMY"}{"list"}}, \@bootZImageNormalForbidList, \@afzfbzfList, \@afzfbzfOverlapList, \@bzList);
      }
      else
      {
        #&objListHelper::SplitObjectListByCheckList(\@{$outputObjectLists{"ROM1"}{"list"}}, \@bootZImageForbidList, \@afzfbzfList, \@afzfbzfOverlapList, \@bzList);
         &objListHelper::SplitObjectListByCheckList(\@{$outputObjectLists{"ROM1"}{"list"}}, \@bootZImageNormalForbidList, \@afzfbzfList, \@afzfbzfOverlapList, \@bzList);
      }

      # BOOT_ZIMAGE library problem workaround
      {
         # Force the workaround libraries to ROM1
         my %bootZImageWorkaourndForbidHash = map { $_->{"name"} => 1 } @bootZImageWorkaroundForbidList;;
         my @tempBZList = @bzList;
         @bzList = ();

         foreach my $object (@tempBZList)
         {
            if (exists $bootZImageWorkaourndForbidHash{$object->{"name"}})
            {
               push @afzfbzfList, $object;
            }
            else
            {
               push @bzList, $object;
            }
         }
      }

      if ($isDummyScatter)
      {
         &_pushToOutputObjectList("BOOT_ZIMAGE_DUMMY", \@bzList, $isSourceChanged);

         @{$outputObjectLists{"ROM1_DUMMY"}{"list"}} = ();
         &_pushToOutputObjectList("ROM1_DUMMY", \@afzfbzfList, $isSourceChanged);
         &_pushToOutputObjectList("ROM1_DUMMY", \@afzfbzfOverlapList, $isSourceChanged);
      }
      else
      {

         &_pushToOutputObjectList("BOOT_ZIMAGE", \@bzList, $isSourceChanged);

         @{$outputObjectLists{"ROM1"}{"list"}} = ();
         &_pushToOutputObjectList("ROM1", \@afzfbzfList, $isSourceChanged);
         &_pushToOutputObjectList("ROM1", \@afzfbzfOverlapList, $isSourceChanged);
      }

      return 1;
   }
   else
   {
      return 0;
   }
}

sub _pushToOutputObjectList
{
   my $objectListName = shift;
   my $objectListRef = shift;
   my $isSourceChanged = shift;

   push @{$outputObjectLists{$objectListName}{"list"}}, @$objectListRef;

   if (-e $outputObjectLists{$objectListName}{"list_file"})
   {
      #if ($isSourceChanged)
      #{
      #   $outputObjectLists{$objectListName}{"generate"} = 1;
      #}
   }
   else
   {
      $outputObjectLists{$objectListName}{"generate"} = 1;
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
