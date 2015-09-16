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
#*   sysInit.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script will copy files from mcu\custom\system to build folder 
#* 
#*
#* Author:
#* -------
#*   Amber Su  (mtk03389)
#*
#*============================================================================
#*             HISTORY
#* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*------------------------------------------------------------------------------
#* $Revision$
#* $Modtime$
#* $Log$
#*
#* 04 21 2014 ray.lin-wang
#* [MOLY00035595] [Build Environment] enhance the build flow
#* .
#*
#* 10 20 2013 qmei.yang
#* [MOLY00037376] [SystemService][Auto-Gen][Request For Design Change] Support Secure_RO on MOLY
#* .
#*
#* 09 16 2013 qmei.yang
#* [MOLY00037954] [SystemService][Auto-Gen][KAL][Request For Design Change] Support cross core ctrl buff, shared buffer, autogen, dump md32
#* .
#*
#* 09 11 2013 ray.lin-wang
#* [MOLY00034122] [Build Environment] phase in MD32/CR4 flow
#* integrate from reorg CBr.
#*
#* 01 24 2013 amber.su
#* [MOLY00009227] [SystemService][AAPMC][Internal Refinement] Support AAPMC to auto-adjust Modem Image Layout
#* .
#*
#* 01 09 2013 amber.su
#* .
#* 
#* 08 03 2012 ray.lin-wang
#* [MOLY00000043] [GCC on Linux] build flow related porting
#* modify chmod solution.
#* sysgen_init.pl => only chmod on windows
#* build.mak => remove files before copying
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
use auto_adjust_mem; #pm file name without case sensitivity
use File::Path;
use File::Copy;
#****************************************************************************
# Input and Parameters initialization
#****************************************************************************
my ($input_folder, $output_folder) = @ARGV;
my $extension = AAPMC_COPYER::THEONE;
my $Debug = 1;

print "Original System Folder Path: $input_folder\n" if($Debug);
print "Output System Folder Path: $output_folder\n" if($Debug);

#****************************************************************************
# Main Flow
#****************************************************************************
&delete_process if(-d $output_folder);	
mkpath($output_folder) or &error_handler("create $output_folder folder failed!", __FILE__, __LINE__) if(!-d $output_folder);

opendir (DIR, $input_folder) or &error_handler("cannot open $input_folder!", __FILE__, __LINE__);
my @files =  grep { /\.conf$/ } readdir (DIR);
close DIR;

print "===== Copy process =====\n";
foreach (@files) {
  $replaced_filename = $_;
  if($_ =~ /(.+)\.conf$/i) {
    $replaced_filename = $1;
  }
  print "[$replaced_filename] ";
  if(-e "$output_folder/$replaced_filename")
  {
    print "Skip\n";
  }
  else
  {
    print "Need to Copy\n";
    print "Copy from $input_folder/$_ to $output_folder/$replaced_filename\n" if($Debug);
    copy("$input_folder/$_", "$output_folder/$replaced_filename") or &error_handler("copy $_ file failed!", __FILE__, __LINE__);

    # chmod for read-only codebase
    chmod(0640, "$output_folder/$replaced_filename") if($^O eq "MSWin32");
  }
}

exit 0;

#*************************************************************************************************
# Delete build\xxx\yyy\custom\system before copy operation
#*************************************************************************************************
sub delete_process
{
  print "===== Delete process =====\n";
  opendir (DIR, $output_folder) or &error_handler("cannot open $output_folder!", __FILE__, __LINE__);
  my @out_files = grep { !/^\.{1,2}$/ } readdir (DIR);
  close DIR;
  
  foreach my $file(@out_files)
  {
    if(-d "$output_folder/$file")
    {
        rmtree("$output_folder/$file");
        print "delete folder: $output_folder/$file\n";
        next;
    }
    if($file =~ /\d$/)
    {
        print "skip $file\n";
        next;
    }
    if($file =~ /$extension$/)
    {
        my $org_file =~ s/$extension$//;
        if(!-e "$output_folder/$org_file")
        {
            unlink "$output_folder/$file";
            print "delete $output_folder/$file\n";
        }
        else
        {
            print "skip $file\n";    
        }
        next;
    }
    if(&AAPMC_COPYER::IsNeededToCopy($output_folder,$input_folder,$file))
    {
      unlink "$output_folder/$file";
      print "delete $file\n";
    }
    else
    {
      print "skip $file\n";
    }
  }
}
#*************************************************************************************************
# Error Handling Message
#*************************************************************************************************
sub error_handler
{
   my ($error_msg, $file, $line_no) = @_;
   my $final_error_msg = "Error: $error_msg at $file line $line_no\n";
   print "$final_error_msg";
   exit 3;
}
