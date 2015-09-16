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
#*   gen_bin_from_elf.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   The script will generate single bin file or multiple bin files from elf file.
#*       
#*
#* Author:
#* -------
#*   Amber Su (mtk03389)
#*
#*============================================================================
#*             HISTORY
#* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*------------------------------------------------------------------------------
#* $Revision$
#* $Modtime$
#* $Log$
#* 
#* 09 21 2012 amber.su
#* [MOLY00003688] [SystemService][Auto-Gen][Internal Refinement] Support BOOT_CERT & multibin on MOLY
#* .
#* 
#* 09 12 2012 amber.su
#* NULL
#* .
#*
#*
#*
#*------------------------------------------------------------------------------
#* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*============================================================================
#****************************************************************************/
#****************************************************************************
# Included Modules
#****************************************************************************
use File::Path;
BEGIN { push @INC, './tools/' }
require 'sysGen2.pl';

#****************************************************************************
# Input and Parameters initialization
#****************************************************************************
my ($bin_create,$linker_script,$elf_file,$bin_file)=@ARGV;
my $err_flag = 0;
print "Input: $bin_create $linker_script $elf_file $bin_file\n";
&error_handler("$linker_script does not exist!", __FILE__, __LINE__) if(!-e $linker_script);
#****************************************************************************
# Main Flow
#****************************************************************************
my $objcopy_input_href = &GetOBJCOPYInput($linker_script);
if(defined $objcopy_input_href)
{
  rmtree($bin_file) or &error_handler("delete $bin_file folder failed!", __FILE__, __LINE__) if(-d $bin_file);	
  mkpath($bin_file) or &error_handler("create $bin_file folder failed!", __FILE__, __LINE__) if(!-d $bin_file);
  foreach my $strBinFileName (keys %$objcopy_input_href)
  {
    $strCommandLine = $objcopy_input_href->{$strBinFileName};
    $cmd = "$bin_create -O binary $strCommandLine $elf_file $bin_file/$strBinFileName";
    print "$cmd\n";
    $result = system("$cmd");
    if($result != 0)
    {
      $err_flag = 1;
      print "Failed!\n";
    }
    else
    {
      print "Done!\n";
    }
  }
}
else
{
  $cmd = "$bin_create -O binary $elf_file $bin_file";
  print "$cmd\n";
  $result = system("$cmd");
  if($result != 0)
  {
    $err_flag = 1;
    print "Failed!\n";
  }
  else
  {
    print "Done!\n";
  }
}
if($err_flag)
{
  &error_handler("The process of generating bin file failed!", __FILE__, __LINE__);
}
else
{
  print "The process of generating bin file is finished!\n";
  exit 0; 
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


