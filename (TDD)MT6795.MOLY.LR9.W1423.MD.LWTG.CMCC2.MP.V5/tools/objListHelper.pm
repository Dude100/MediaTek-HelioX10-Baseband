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
#*   objListGen.pm
#*
#* Project:
#* --------
#*   Maui_Software
#*
#* Description:
#* ------------
#*   This file help to handle the object list common operations.
#*
#*
#* Author:
#* -------
#*   Ke-Ting Chen (mtk03141)
#*
#*****************************************************************************
package objListHelper;
#****************************************************************************
# Included Modules
#****************************************************************************
use strict;
use warnings;
BEGIN { push @INC, './tools/' }  # add additional library path
use sysGenUtility;
use FileInfoParser;
use tools::pack_dep_gen;

#****************************************************************************
# History
#****************************************************************************
my $OBJ_LIST_HELPER_VERNO = " v1.03";
   # v1.03: Move feature option evaluation functions to FileInfoParser.pm
   # v1.02: Add checking check-in pattern function
   # v1.01: Correct the compare object name algorithm
   # v1.00: Phase in object list generate mechanism

#****************************************************************************
# Constants
#****************************************************************************

#****************************************************************************
# Variables
#****************************************************************************

#****************************************************************************
# subroutine:  InputObjectListFromObjListFile
# description: Get the object list from the specified object list file.
# input:       Input filename, object list ref
# output:      Object list
# need init:   No
#****************************************************************************
sub InputObjectListFromObjListFile
{
   my $filename = shift;
   my $objectListRef = shift;
   my $category = $filename;

   &ErrorHandler("Undefined object list reference!", __FILE__, __LINE__) unless (defined $objectListRef);

   open my $input, "<$filename" or
      &ErrorHandler("Cannot open file $filename $!", __FILE__, __LINE__);

   while (<$input>)
   {
      chomp;

      if (/^\s*; =+ (.+) =+/)
      {
         $category = $1;
      }
      elsif (/^\s*;/)
      {
         # Skip the comment line
      }
      elsif (/^\s*(\S+)\s+\((.*)\)/)
      {
         my $objectName = $1;
         my @attributeArray = ($2 =~ /([\w|\+|\-]+)/g);
         my %object = ("name" => $objectName, "attributes" => \@attributeArray, "category" => $category);

         push @$objectListRef, \%object;
      }
   }

   close $input;
}

#****************************************************************************
# subroutine:  OutputObjectListToObjListFile
# description: Put the object list to the specified object list file.
# input:       Output filename, object list ref, leading string, attribute string
# output:      None
# need init:   No
#****************************************************************************
sub OutputObjectListToObjListFile
{
   my $filename = shift;
   my $objectListRef = shift;
   my $leadingString = shift;
   my $attributeString = shift;
   my $category = "";

   $leadingString = "" unless defined $leadingString;

   if (&IsManualModified($filename))
   {
      return 0;
   }

   &ErrorHandler("Undefined object list reference!", __FILE__, __LINE__) unless (defined $objectListRef);

   open my $output, ">$filename" or
      &ErrorHandler("Cannot open file $filename $!", __FILE__, __LINE__);

   if (defined $objectListRef->[0] and exists $objectListRef->[0]{"category"})
   {
      $category = $objectListRef->[0]{"category"};
      print $output "$leadingString; ====== $category ======\n";
   }

   foreach my $objectRef (@$objectListRef)
   {
      if ($objectRef->{"category"} ne $category)
      {
         $category = $objectRef->{"category"};
         print $output "\n$leadingString; ====== $category ======\n";
      }

      print $output $leadingString."$objectRef->{name} (";
      if (defined $attributeString)
      {
         print $output $attributeString;
      }
      else
      {
         print $output join(', ', @{$objectRef->{"attributes"}});
      }
      print $output ")\n";
   }

   close $output;

   return 1;
}

#****************************************************************************
# subroutine:  InputObjectListFromCSVFile
# description: Get the new object list from the specified csv file.
# input:       Input filename, object list ref, makefile options hash ref
# output:      Object list
# need init:   No
#****************************************************************************
sub InputObjectListFromCSVFile
{
   my $filename = shift;
   my $objectListRef = shift;
   my $makefileOptionsHashRef = shift;

   &ErrorHandler("Undefined object list reference!", __FILE__, __LINE__) unless (defined $objectListRef);

   open my $input, "<$filename" or
      &ErrorHandler("Cannot open file $filename $!", __FILE__, __LINE__);

   # Skip the first line which contains only the column header
   <$input>;

   while (<$input>)
   {
      chomp;

      # Object Name,Attributes,Library Name,Category,Feature Option
      {
         my @entry = split(/,/);
         unless (3 <= scalar(@entry) and
                 "" ne $entry[0] and
                 "" ne $entry[1] and
                 "" ne $entry[2])
         {
            &ErrorHandler("Incorrect CSV file format \"$_!\"", __FILE__, __LINE__);
         }

         $entry[3] = "" unless defined $entry[3];
         $entry[4] = "" unless defined $entry[4];

         # Check the feature option
         if (($entry[4] ne "") and defined $makefileOptionsHashRef)
         {
            next unless (&FileInfo::EvaluateFeatureOptionCondition($entry[4], $makefileOptionsHashRef));
         }

         my @attributeArray = ($entry[1] =~ /([\w|\+|\-]+)/g);
         my %object = ("name" => $entry[0],
                       "attributes" => \@attributeArray,
                       "library" => $entry[2],
                       "category" => $entry[3],
                       "feature_option" => $entry[4]);
         push @$objectListRef, \%object;
      }
   }

   close $input;
}

#****************************************************************************
# subroutine:  InputObjectListFromLISInfo
# description: Get the new object list from the LIS info list.
# input:       LIS info list ref, object list ref, attribute string, category
# output:      Object list
# need init:   No
#****************************************************************************
sub InputObjectListFromLISInfo
{
   my $infoListRef = shift;
   my $objectListRef = shift;
   my $attributeString = shift;
   my $category = shift;

   $category = "" unless defined $category;


   foreach my $info (@$infoListRef)
   {
      my @attributeArray = ($attributeString =~ /[\w|\+|\-]+/g);
      my %object = ("name" => $info->{"name"},
                    "attributes" => \@attributeArray,
                    "library" => $info->{"library"},
                    "category" => $category,
                    "size" => $info->{"size"});
      push @$objectListRef, \%object;
   }
}

#****************************************************************************
# subroutine:  OutputObjectListToCSVFile
# description: Put the object list to the specified object list file.
# input:       Output filename, object list ref
# output:      None
# need init:   No
#****************************************************************************
sub OutputObjectListToCSVFile
{
   my $filename = shift;
   my $objectListRef = shift;

   &ErrorHandler("Undefined object list reference!", __FILE__, __LINE__) unless (defined $objectListRef);

   open my $output, ">$filename" or
      &ErrorHandler("Cannot open file $filename $!", __FILE__, __LINE__);

   # Print the column header
   print $output "Object Name,Attributes,Library Name,Category,Feature Option\n";

   foreach my $objectRef (@$objectListRef)
   {
      print $output "$objectRef->{name},(";
      print $output join(' ', @{$objectRef->{"attributes"}});
      print $output "),$objectRef->{library},$objectRef->{category},$objectRef->{feature_option}\n";
   }

   close $output;
}

#****************************************************************************
# subroutine:  IsManualModified
# description: Check whether the file is manual modified.
# input:       File path
# output:      1: the file is manual modified; 0: otherwise
# need init:   No
#****************************************************************************
sub IsManualModified
{
   my $filename = shift;
   my $result = &sysUtil::HasCheckinHistory($filename);

   if (defined $result and 1 == $result)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}

#****************************************************************************
# subroutine:  SortObjectListByCategory
# description: Sort the object list by the category.
# input:       Object list ref.
# output:      Sorted object list
# need init:   No
#****************************************************************************
sub SortObjectListByCategory
{
   my $listRef = shift;
   my %categoryListHash;
   my @categorySequence;

   foreach my $object (@$listRef)
   {
      my $category = $object->{"category"};
      if (exists $categoryListHash{$category})
      {
         push @{$categoryListHash{$category}}, $object;
      }
      else
      {
         $categoryListHash{$category} = [$object];
         push @categorySequence, $category;
      }
   }

   @$listRef = ();

   foreach my $category (@categorySequence)
   {
      push @$listRef, @{$categoryListHash{$category}};
   }
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

   # Compare list entry number
   if ((scalar(@$firstList) <=> scalar(@$secondList)) != 0)
   {
      return scalar(@$firstList) <=> scalar(@$secondList);
   }

   # Compare list entry name
   my @sortedFirstList = sort {$a->{"name"} cmp $b->{"name"}} @$firstList;
   my @sortedSecondList = sort {$a->{"name"} cmp $b->{"name"}} @$secondList;

   for (my $i = 0; $i < scalar(@$firstList); ++$i)
   {
      if (($sortedFirstList[$i]{"name"} cmp $sortedSecondList[$i]{"name"}) != 0)
      {
         return ($sortedFirstList[$i]{"name"} cmp $sortedSecondList[$i]{"name"});
      }
      elsif (compareAttributeList($sortedFirstList[$i]{"attributes"}, $sortedSecondList[$i]{"attributes"}) != 0)
      {
         return compareAttributeList($sortedFirstList[$i]{"attributes"}, $sortedSecondList[$i]{"attributes"});
      }
   }

   return 0;
}

#****************************************************************************
# subroutine:  MergeAttributeList
# description: Merge the attribute list to the first attribute list.
# input:       First list ref, second list ref
# output:      Merged list in first list ref
# need init:   No
#****************************************************************************
sub MergeAttributeList
{
   my $firstRef;
   my $secondRef;

   my %resultHash;

   foreach my $attribute (@$firstRef, @$secondRef)
   {
      $resultHash{$attribute} = 1;
   }

   if ($resultHash{"+RO"})
   {
      delete $resultHash{"+RO-CODE"} if (exists $resultHash{"+RO-CODE"});
      delete $resultHash{"+RO-DATA"} if (exists $resultHash{"+RO-DATA"});
   }

   @$firstRef = sort compareAttribute keys %resultHash;
}

sub compareAttribute
{
   my $first = shift;
   my $second = shift;

   my %attributeToNumber = ("+RO" => 0, "+RO-CODE" => 1, "+RO-DATA" => 2);

   return $attributeToNumber{$first} <=> $attributeToNumber{$second};
}

sub compareAttributeList
{
   my $firstList = shift;
   my $secondList = shift;

   # Compare list entry number
   if ((scalar(@$firstList) <=> scalar(@$secondList)) != 0)
   {
      return scalar(@$firstList) <=> scalar(@$secondList);
   }

   for (my $i = 0; $i < scalar(@$firstList); ++$i)
   {
      if (compareAttribute($firstList->[$i], $secondList->[$i]) != 0)
      {
         return compareAttribute($firstList->[$i], $secondList->[$i]);
      }
   }

   return 0;
}

#****************************************************************************
# subroutine:  ChangeAttributeList
# description: Chagne the attribute list to the specified string.
# input:       Object ref, attribute string
# output:      Object ref
# need init:   No
#****************************************************************************
sub ChangeAttributeList
{
   my $objectRef = shift;
   my $attributeString = shift;

   my @attributeArray = ($attributeString =~ /([\w|\+|\-]+)/g);

   $objectRef->{"attributes"} = \@attributeArray;
}

#****************************************************************************
# subroutine:  ChangeObjectListAttributeList
# description: Chagne the attribute list of each object in the list to
#              the specified string.
# input:       Object ref, attribute string
# output:      Object ref
# need init:   No
#****************************************************************************
sub ChangeObjectListAttributeList
{
   my $objectListRef = shift;
   my $attributeString = shift;

   foreach my $object (@$objectListRef)
   {
      &ChangeAttributeList($object, $attributeString);
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

   my @matchList;
   my @noMatchList;

   &SplitObjectListByCheckList($targetObjectListRef, $sourceObjectListRef, \@matchList, \@matchList, \@noMatchList);

   foreach my $object (@matchList)
   {
      if (exists $object->{"matchedObject"})
      {
         $object->{"attributes"} = \@{$object->{"matchedObject"}{"attributes"}};
      }
   }
}

#****************************************************************************
# subroutine:  SplitObjectListByCheckList
# description: Split the source object list by check object list
# input:       Source object list ref, check object list ref,
#              match object list ref, match library list ref, match none list ref
# output: Match object list: the entry exactly match with the one in hash
#         Match library list: the entry fall into the library in hash entry
#         Match non list: match nothing
# note: This function will append a field "matched" to the objects in check list
#****************************************************************************
sub SplitObjectListByCheckList
{
   my $sourceListRef = shift;
   my $checkListRef = shift;

   my $matchObjectListRef = shift;
   my $matchLibraryListRef = shift;
   my $matchNoneListRef = shift;

   map { $_->{"matched"} = 0 } @$checkListRef;

   foreach my $sourceObject (@$sourceListRef)
   {
      my $splitted = 0;

      # Cannot use hash for fast search since there are evil wildcards...
      foreach my $checkObject (@$checkListRef)
      {
         my $compareResult = compareObjectName($checkObject->{"name"}, $sourceObject->{"name"});
         if (0 == $compareResult)
         {
            # Exactly match
            push @$matchObjectListRef, $sourceObject;
            $sourceObject->{"matchedObject"} = $checkObject;
            $checkObject->{"matched"} = 1;
            $splitted = 1;
            last;
         }
         elsif (0 < $compareResult)
         {
            # Source object name is contained in the check object name
            push @$matchObjectListRef, $sourceObject;
            $sourceObject->{"matchedObject"} = $checkObject;
            # Do not set the matched flag since they are not exactly the same
            $splitted = 1;
            last;
         }
         else
         {
            # Source object name is not contained in the check object name
            # Check the library
            if (isLibraryName($sourceObject->{"name"}))
            {
               # Source object is a library, and it can only be put in matchObjectList
               next;
            }
            elsif ($sourceObject->{"library"} eq "Unknown")
            {
               # The library of the source object is unknown, push to match library list for safety
               push @$matchLibraryListRef, $sourceObject;
               $splitted = 1;
               last;
            }
            else
            {
               # Source object is a true object
               if (isLibraryName($checkObject->{"name"}))
               {
                  # Check object is a library, check if source is belong to it
                  $compareResult = compareObjectName($checkObject->{"name"}, $sourceObject->{"library"});
                  if (0 <= $compareResult)
                  {
                     # Match to the library
                     push @$matchLibraryListRef, $sourceObject;
                     $sourceObject->{"matchedObject"} = $checkObject;
                     $splitted = 1;
                     last
                  }
               }
            }
         } # if (0 == $compareResult)
      } # foreach my $checkObject (@$checkListRef)

      if (not $splitted)
      {
         # Matches nothing
         push @$matchNoneListRef, $sourceObject;
      }
   } # foreach my $sourceObject (@$sourceListRef)
}

# Return 1 if the name is belong to a library
sub isLibraryName
{
   my $name = shift;
   $name = lc $name;

   if ((substr($name, -4) eq ".lib") or (substr($name, -2) eq ".a"))
   {
      return 1;
   }
   else
   {
      return 0;
   }
}

# Compare two object name with wildcard
sub compareObjectName
{
   my $first = shift;
   my $second = shift;

   $first = lc $first;
   $second = lc $second;

   if ($first eq $second)
   {
      # Exactly match
      return 0;
   }
   elsif ($first =~ m/\*/)
   {
      $first =~ s/\./\\./g;  # Change . to \.
      $first =~ s/\*/.\*/g;  # Change to regular expression form
      $second =~ s/\*//g;    # Remove wildcard symbol

      if ($second =~ m/$first/)
      {
         # Second is contained in first
         return 1;
      }
      else
      {
         return -1;
      }
   }
   else
   {
      return -1;
   }
}

#****************************************************************************
# subroutine:  ErrorHandler
# description: Handle the post process error and output the error message.
#              Note calling this function will lead program terminated.
# input:       Message, source filename, line number
# output:      None
# need init:   No
#****************************************************************************
sub ErrorHandler
{
   my ($message, $file, $line) = @_;

   my $errorMessage = "OBJ LIST ERROR: $message at $file line $line\n";
   print $errorMessage;

   die $errorMessage;
}

1;

#============================================================================
# Not used but for backing-up
#============================================================================

#****************************************************************************
# subroutine:  ChangeObjectListToHash
# description: Chagne the object list to hash form.
# input:       Object list ref, output hash ref, start serial number
# output:      Object list hash
# need init:   No
#****************************************************************************
sub ChangeObjectListToHash
{
   my $listRef = shift;
   my $hashRef = shift;
   my $serialNumber = shift;

   $serialNumber = 0 unless defined $serialNumber;

   foreach my $object (@$listRef)
   {
      my $key = GetObjectKey($object);
      if (exists $hashRef->{$key})
      {
         mergeAttributeList($hashRef->{$key}->{"attributes"}, $object->{"attributes"});
      }
      else
      {
         $hashRef->{$key} = $object;
         $object->{"matched"} = 0;
         $object->{"serial"} = $serialNumber++;
      }
   }

   return $serialNumber;
}

#****************************************************************************
# subroutine:  GetObjectKey
# description: Get the object key used in object hash.
# input:       Object ref
# output:      Key of the object
# need init:   No
#****************************************************************************
sub GetObjectKey
{
   my $object = shift;

   return "$object->{name}::$object->{library}";
}

#****************************************************************************
# subroutine:  ChangeObjectHashToList
# description: Chagne the object hash to list form.
# input:       Object hash ref, output list ref
# output:      Object list
# need init:   No
#****************************************************************************
sub ChangeObjectHashToList
{
   my $hashRef = shift;
   my $listRef = shift;

   @$listRef = (sort {$a->{"serial"} <=> $b->{"serial"}} values %$hashRef);
}
