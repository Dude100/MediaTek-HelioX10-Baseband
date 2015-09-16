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
#*   initLogParser.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script parses raw data of the boot-up log
#*
#* Author:
#* -------
#*   Dot Li  (mtk02439)
#*
#*============================================================================
#*       HISTORY
#* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*------------------------------------------------------------------------------
#* $Revision$
#* $Modtime$
#* $Log$
#*
#* 04 17 2013 dot.li
#* [MOLY00019590] [SystemService][Init] Smartphone modem boot-up trace phase 2
#* .
#*
#* 03 12 2013 dot.li
#* [MOLY00011540] [SystemService][Init] Smartphone modem boot-up trace
#* .
#* 
#*------------------------------------------------------------------------------
#* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*============================================================================
#****************************************************************************/

BEGIN { push @INC, '..' }  # add additional library path

#****************************************************************************
# Input arguments
#****************************************************************************
my $LOG_STAGE = $ARGV[0];

my $DebugPrint  = 1; # 1 for debug; 0 for non-debug

#****************************************************************************
# >>> Handle boot-up stage
#****************************************************************************
#****************************************************************************
# 1 >>> Abort at stage 1
#****************************************************************************
if ($LOG_STAGE eq "HS1") {
  print "MD init stage 1\n";
  
  #****************************************************************************
  # 1-1 >>> Parsing stage 1 label
  #****************************************************************************
  my $stage1_label_file = "../../driver/sys_drv/init/inc/bootarm.h";
  
  &error_handler("$stage1_label_file: NOT exist!", __FILE__, __LINE__) if (!-e $stage1_label_file);
  open (FILE_HANDLE, "<$stage1_label_file") or &error_handler("$stage1_label_file: file error!", __FILE__, __LINE__);
 
  my ($line, $add_label, @boot_stage_label, @boot_stage_code, $i);
  
  $add_label = 0; # not start enum
  $i = 0;

  # parsing enum info
  while ($line = <FILE_HANDLE>) {
    if ($line =~ m/#define LABEL/) {
      $boot_stage_label[$i] = $1  if ($line =~ m/(LABEL_(\w|\d)+)/ );
      $boot_stage_code[$i] = $1 if ($line =~ m/((0x|0X)[0-9A-Fa-f]+)/ );
      $i++;
    }
  }

  #****************************************************************************
  # 1-2 >>> Matching and output result
  #****************************************************************************

  print "Magic:";
  $hex=$ARGV[1];
  while($hex =~ /(.{2})/sg) {
    print chr(hex($1));
  }
  print " (0x$ARGV[1])\n";
  
  if ($ARGV[1] =~ /30305f49/) {
    $matching = 0;
    
    for($i = 0; $i < $#boot_stage_label; $i++) {
      if(hex($boot_stage_code[$i]) == hex($ARGV[2])) {
        print "last label record: $boot_stage_label[$i]\n";
        $matching = 1;
        last;
      }
    }
    print "No matching stage found!!\n" if ($matching == 0);
  }
}   # boot stage HS1
#****************************************************************************
# 2 >>> Abort at stage 2
# input format: ./initLogParser.pl HS2 [project flavor] [log file]
#****************************************************************************
if ($LOG_STAGE eq "HS2") {

  #****************************************************************************
  # 2-0 >>> Parse CPU speed
  #****************************************************************************

  use FileInfoParser;
  my %MAKEFILE_OPTIONS;
  my $themf = "../../make/" . $ARGV[1];
  if(1!=&FileInfo::Parse_MAKEFILE($themf, \%MAKEFILE_OPTIONS))
  {
    &sysUtil::sysgen_die("[1.1]Parse MakeFile failed");
  }

  my $CPU_MHZ = $MAKEFILE_OPTIONS{'MCU_CLOCK'};

  $CPU_MHZ =~  s/\D//g;
  
  my $LOG_FILE = $ARGV[2];
  
  # to align error message file name format
  $LOG_FILE =~ s/^.\\|^\\//;
  
  #****************************************************************************
  # 2-1 >>>  Print out input parameters for checking
  #****************************************************************************
  if ($DebugPrint == 1) {
    print "LOG_STAGE: $LOG_STAGE\n";
    print "LOG_FILE: $LOG_FILE\n";
    print "\n";  
  }
  
  my (@boot_log_raw, $boot_log, $start_idx, $i);
  
  #****************************************************************************
  # 2-2 >>> Read In Exception Log
  #****************************************************************************
  print "Starting stage1... (Read in boot-up log)\n" if($DebugPrint == 1);
  
  &error_handler("$LOG_FILE: NOT exist!", __FILE__, __LINE__) if (!-e $LOG_FILE);
  open (FILE_HANDLE, "<$LOG_FILE") or &error_handler("$LOG_FILE: file error!", __FILE__, __LINE__);
  #binmode FILE_HANDLE;
  
  # parsing log file
  use constant TASK_MAGIC => 0x4B534154;
  
  my ($line, @data32);
  
  $i = 0;
  while ($line = <FILE_HANDLE>) {
    if ($line =~ /(\w+) (\w+) (\w+) (\w+)/) {
      $data32[0] = $1;
      $data32[1] = $2;
      $data32[2] = $3;
      $data32[3] = $4;
      foreach $_ (@data32) {
        $boot_log_raw[$i++] = hex($_);
      }
    }
  }
  
  close (FILE_HANDLE);
  
  #****************************************************************************
  # 2-3 >>> Parse Header for log address
  #****************************************************************************
  print "Starting stage2... (Parse header for log address)\n" if($DebugPrint == 1);
  
  $start_idx = $boot_log_raw[0]/16;
  #print "$boot_log_raw[0] , $start_idx\n";
  
  #****************************************************************************
  # 2-4 >>> Parse Boot-Up Log
  #****************************************************************************
  print "Starting stage3... (Parse boot-up log)\n" if($DebugPrint == 1);
  
  $boot_log .= "CPU Speed = ".$CPU_MHZ." MHz\n";

  print "MD init stage 2\n";
  my @boot_stage = &hs2_label_parse();
  
  $boot_log .= sprintf("%4s%10s    (%10s)\t\tLog\n","Idx","msec","CPU cycle");
  
  my ($parse_task, $log_size, $ts_msec, $temp_str);
  $i = $start_idx;
  while($i < @boot_log_raw) {
    if($boot_log_raw[$i] != 0) {
      if($boot_log_raw[$i] == TASK_MAGIC) {
        $parse_task = $boot_log_raw[$i+1];
      } else {
        $log_size++;
        $ts_msec = sprintf("%.2f", $boot_log_raw[$i+1] / $CPU_MHZ / 1000);  # milli-second
        if ($parse_task == 1) {
          $boot_log .= sprintf("[%2d]%10.2f ms (%10d)\t\t[Task] Start of task index $boot_log_raw[$i] init \n", $log_size, $ts_msec, $boot_log_raw[$i+1]);
        } else {
          $boot_log .= sprintf("[%2d]%10.2f ms (%10d)\t\Start of $boot_stage[$boot_log_raw[$i]]\n", $log_size, $ts_msec, $boot_log_raw[$i+1]);
        }
      }
    }
    $i += 2;
  }
    
  # print to console
  print $boot_log;
  print "Number of log = $log_size\n" if($DebugPrint == 1);

  #****************************************************************************
  # 2-5 >>> Output to a TXT
  #****************************************************************************
  print "Output to $LOG_FILE.txt\n";
  open (FILE_HANDLE, ">$LOG_FILE.txt") or &error_handler("$LOG_FILE: file error!", __FILE__, __LINE__);
  print FILE_HANDLE $boot_log;
  close (FILE_HANDLE);
  
}   # boot stage HS2

#****************************************************************************
# oo >>>  Finished
#****************************************************************************
exit 0;


#****************************************************************************
# subroutine:  error_handler
# input:     $error_msg:   error message
#        $file:      filename
#        $line_no:     line number
#****************************************************************************
sub error_handler
{
  my ($error_msg, $file, $line_no) = @_;

  my $final_error_msg = "BOOT LOG PARSER ERROR: $error_msg at $file line $line_no\n";
  die $final_error_msg;
}


#****************************************************************************
# subroutine:  hs2_label_parse
#****************************************************************************
sub hs2_label_parse
{
  my $stage2_label_file = "../../driver/sys_drv/init/inc/init_trc_id.h";
  
  &error_handler("$stage2_label_file: NOT exist!", __FILE__, __LINE__) if (!-e $stage2_label_file);
  open (FILE_HANDLE, "<$stage2_label_file") or &error_handler("$stage2_label_file: file error!", __FILE__, __LINE__);
 
  my ($line, $add_label, @label_arr, $i);
  
  $add_label = 0; # not start enum
  $i = 0;

  # parsing enum info
  while ($line = <FILE_HANDLE>) {
    if ($line =~ m/typedef enum {/) {
      $add_label = 1;
    }

    if ($line =~ m/} BOOT;/) {
      $add_label = 2;
    }

    if($add_label == 1) {
      if ($line =~ m/(BOOT_(\w|\d)+)/) {
        $label_arr[$i++]=$1;
      }
    }
  }
 
  
  return @label_arr;
}
