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
#*   auto_adjust_mem.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   1. This script will read link error and decide to enter two-phase linking
#*   2. If need, it will calculate recommand memory configuration value.
#*   3. If turn on *_AUTO_CONFIG option, it will triger two-phase linking.
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
#* 06 25 2013 ray.lin-wang
#* [MOLY00027330] [ARM7toMOLY] ARM7 Build/SYSGEN/Functions Update to TRUNK
#* .
#*
#* 06 03 2013 amber.su
#* [MOLY00023890] [SystemService][Auto-Gen][Internal Refinement] Support compiler option judgement
#* .
#*
#* 01 24 2013 amber.su
#* [MOLY00009227] [SystemService][AAPMC][Internal Refinement] Support AAPMC to auto-adjust Modem Image Layout
#* .
#*
#* 01 18 2013 amber.su
#* .
#*
#* 01 14 2013 amber.su
#* .
#*
#* 01 14 2013 amber.su
#* .
#*
#* 01 14 2013 amber.su
#* .
#*
#* 01 14 2013 amber.su
#* .
#*
#* 01 11 2013 amber.su
#* .
#* 
#* 07 30 2012 jerry.chang
#* [MOLY00001397] [MOLY] rename gsm2.mak and make2.pl
#* .
#* 
#* 07 26 2012 amber.su
#* [MOLY00000422] [Guardian] sing file for guardian
#* .
#*  V0, two phase linking process with ZIMAGE_AUTO_CONFIG
#*  V1, two phase linking process with DEMAND_PAGING_AUTO_CONFIG
#*  V2, parse all regions for link error for AAPMC on DP and MBA support
#*  V3, support auto checkin mechanism
#*  V4, two phase linking process with FILE_SYSTEM_AUTO_CONFIG
#*  V5, phase-in ALICE, and combine it with ZIMAGE prcessing
#*  V6, phase-in AAPMC for MOLY, and remove related code for MAUI
#*------------------------------------------------------------------------------
#* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*============================================================================
#****************************************************************************

#use strict;
BEGIN { push @INC, './tools/' }  # add additional library path
use auto_adjust_mem; #pm file name without case sensitivity/for AAPMC
use File::Path;
use File::Copy;
use File::Basename;
#*************************************************************************************************
# Input and Parameters initialization
#*************************************************************************************************
my ($LEVEL,$TEP_LOG) = @ARGV;
my $DEBUG = 1;
my $sperate_line = "====================================================================\n";

#*************************************************************************************************
# Main Flow
# >> LEVEL 1. Check link error pattern to decide whether enter to two-phase linking
# >> LEVEL 2. Calculate correct value to decide whether link error can be resolved with adjusted 
#             memory configuration value
#*************************************************************************************************
if($LEVEL == 1) {

  open (LOGFILE, "<$TEP_LOG") or &error_handler("cannot open $TEP_LOG!", __FILE__, __LINE__);
  while (<LOGFILE>) {
    if (/^(\S+)\s*=\s*(\S+)/) {
      $keyname = $1;
      $${keyname} = $2;
    }
  }
  close LOGFILE;

  #my $AAPMC_LOG = "$AAPMC_TEMP_FOLDER/AAPMC.log";
  
  #&error_handler("File: $AAPMC_MAKEFILE did NOT exist!", __FILE__, __LINE__) if (!-e $AAPMC_MAKEFILE);
  
  print "[Check any error related two-phase linking...]\n" if($DEBUG);
  
  unlink "$AAPMC_TEMP_FOLDER/~ModemReservedSize_AutoConfig.tmp" if(-e "$AAPMC_TEMP_FOLDER/~ModemReservedSize_AutoConfig.tmp");
  
  $LINK_ERR = &ckLinkError;

  #open (FILE_HANDLE, "<$AAPMC_MAKEFILE") or &error_handler("cannot open $AAPMC_MAKEFILE!", __FILE__, __LINE__);
  #while (<FILE_HANDLE>) {
  #  if ((/^([^\#]*)\#?.*/) && ($1 =~ /^(\w+)\s*=\s*(.*\S)\s*$/)) {
  #    $keyname = lc($1);
  #    $${keyname} = uc($2);
  #  }
  #}
  #close FILE_HANDLE; 

  if($LINK_ERR) {
    print "Need to enter two-phase linking process.\n" if($DEBUG);   
    exit 1;
  } else{
    print "Do not need to enter two-phase linking process.\n\n" if($DEBUG);    
    exit 0;
  }
  
}
elsif($LEVEL == 2) {

  open (LOGFILE, "<$TEP_LOG") or &error_handler("cannot open $TEP_LOG!", __FILE__, __LINE__);
  while (<LOGFILE>) {
    if (/^(\S+)\s*=\s*(\S+)/) {
      $keyname = $1;
      $${keyname} = $2;
    }
  }
  close LOGFILE;
  
  my $AAPMC_LOG = "$AAPMC_TEMP_FOLDER/AAPMC.log";
  my $out_str = "";
  my $remd_str = "";
  my $result;
  
  my $Status = 0;
  
  if(-e "$AAPMC_TEMP_FOLDER/~ModemReservedSize_AutoConfig.tmp") {
    #&error_handler("File: $AAPMC_SYM_FILE did NOT exist!", __FILE__, __LINE__) if(!-e $AAPMC_SYM_FILE);
    &error_handler("Folder: $AAPMC_CUSTOM_FOLDER_PATH did NOT exist!", __FILE__, __LINE__) if (!-d $AAPMC_CUSTOM_FOLDER_PATH);
    &error_handler("File: $AAPMC_MAKEFILE did NOT exist!", __FILE__, __LINE__) if (!-e $AAPMC_MAKEFILE);
    &backup_file("$AAPMC_SYM_FILE","$AAPMC_TARGDIR/MODEM_RESV_SIZE_DEBUG") if(-e $AAPMC_SYM_FILE);
    &backup_file("$AAPMC_MAP_FILE","$AAPMC_TARGDIR/MODEM_RESV_SIZE_DEBUG") if(-e $AAPMC_MAP_FILE);
    &backup_file("$AAPMC_LINKER_SCRIPT","$AAPMC_TARGDIR/MODEM_RESV_SIZE_DEBUG") if(-e $AAPMC_LINKER_SCRIPT);
    print "perl tools/ModemReservedSize_AutoConfig.pl $AAPMC_MAP_FILE $AAPMC_SYM_FILE $AAPMC_LINKER_SCRIPT $AAPMC_CUSTOM_FOLDER_PATH \"$AAPMC_MAKEFILE\" $AAPMC_TEMP_FOLDER/~ModemReservedSize_AutoConfig.tmp $AAPMC_LOG $AAPMC_INFOMAKE_LOG $AAPMC_COPRO_INFO_LOG> $AAPMC_LOG_FOLDER/ModemReservedSize_AutoConfig.log 2>&1\n" if($DEBUG);
    $out_str = "Calculating correct Modem Reserved Size value...";
    $result = system("perl tools/ModemReservedSize_AutoConfig.pl $AAPMC_MAP_FILE $AAPMC_SYM_FILE $AAPMC_LINKER_SCRIPT $AAPMC_CUSTOM_FOLDER_PATH \"$AAPMC_MAKEFILE\" $AAPMC_TEMP_FOLDER/~ModemReservedSize_AutoConfig.tmp $AAPMC_LOG $AAPMC_INFOMAKE_LOG $AAPMC_COPRO_INFO_LOG> $AAPMC_LOG_FOLDER/ModemReservedSize_AutoConfig.log 2>&1") ;
    $remd_str = &getRecomdValue("$AAPMC_TEMP_FOLDER/~ModemReservedSize_AutoConfig.tmp");
    $check_scrip = "ModemReservedSize_AutoConfig";
  } elsif (-e "$AAPMC_TEMP_FOLDER/~FS_LinkError.tmp") {
    #re-calculate FS size
    print "perl tools/cksysdrv.pl $FLASH_CFG $FSUSAGE_LOG $NVRAMID_LOG $FEATURE_OVER $SYSDRV $NVRAM_PSEUDO $SYS_PATH $AAPMC_TEMP_FOLDER/~FS_LinkError.tmp $PROJECT_NAME $AAPMC_LOG> $AAPMC_LOG_FOLDER/FileSystemConfig.log 2>&1\n" if($DEBUG);
    $out_str = "Calculating correct File System value...";
    $result = system("perl tools/cksysdrv.pl $FLASH_CFG $FSUSAGE_LOG $NVRAMID_LOG $FEATURE_OVER $SYSDRV $NVRAM_PSEUDO $SYS_PATH $AAPMC_TEMP_FOLDER/~FS_LinkError.tmp $PROJECT_NAME $AAPMC_LOG >> $AAPMC_LOG_FOLDER/FileSystemConfig.log 2>&1") ;
    $remd_str = &getRecomdValue("$AAPMC_TEMP_FOLDER/~FS_LinkError.tmp");
    $check_scrip = "FileSystemConfig";
  } else {
    die "lack of log file to enter two-phase linking process\n";
  }
  # die error code: 2304 >> 9
  $check_log = "$AAPMC_LOG_FOLDER/$check_scrip.log";
  if(($result>>8) == ERR::NO_MODIFY) { # NO_MODIFY: recommand a value but not modify custom_featureConfig.h || scatter file is checkin by human
    $out_str .= "Done.\nPlease adjust memory configuration manually and refer to $check_log\n";
    $out_str .= "$sperate_line$remd_str$sperate_line";
    if($check_scrip eq "ModemReservedSize_AutoConfig"){
      open(TEMPFILE,">$AAPMC_TEMP_FOLDER/~NoAAPMC.tmp") or &error_handler("cannot open $AAPMC_TEMP_FOLDER/~NoAAPMC.tmp!", __FILE__, __LINE__);
      print TEMPFILE ".";
      close TEMPFILE;
    }
  } elsif (($result>>8) == ERR::AAPMCLOG_SUCCESS) { # AAPMCLOG_SUCCESS: recommand a value and write to AAMPC.log
    $out_str .= "Done.\nThe adjustment of memory configuration is done and refer to $check_log\n";
    $out_str .= "$sperate_line$remd_str$sperate_line";
    
    #Skip to modify .h
    #if(ERR::AAPMCLOG_SUCCESS == &AAPMCLogParser::Open($AAPMC_LOG)) {
    #    my $IndexArray_ref = &AAPMCLogParser::GetAllRecordsIndex();
    #    foreach my $i (@$IndexArray_ref) {
    #        my $ChangeRecord_ref = &AAPMCLogParser::GetByIndex($i, AAPMCLogParser::RECORD);
    #        $Status += &AUTO_ADJUST::ModifyByChangeRecord("./", $ChangeRecord_ref, 1);
    #    }
    #    $closevalue = &AAPMCLogParser::Close($AAPMC_LOG);
    #    if($closevalue == ERR::AAPMCLOG_SUCCESS){
    #      if($Status == ERR::ERR_MODIFYFAIL) {
    #        $out_str .= "Failed.\nAll memory configurations are unchange. It cannot apply two-phase linking process. Please check link error\n" 
    #      } else {
    #        # The pattern "The adjustment of memory configuration is done and refer to $check_log" will be parsed by auto-notify
    #        $out_str .= "Done.\nThe adjustment of memory configuration is done and refer to $check_log\n";
    #        $out_str .= "$sperate_line$remd_str$sperate_line";
    #      }
    #    } else {
    #      &error_handler("cannot close $AAPMC_LOG!", __FILE__, __LINE__);
    #    }
    #}else {
    #    &error_handler("cannot open $AAPMC_LOG!", __FILE__, __LINE__);
    #}
  } elsif (($result>>8) == ERR::AUTOCONFIG_SELF_MODIFY_SUCCESS) { # AUTOCONFIG_SELF_MODIFY_SUCCESS: skip AAPMC operation and treat it as AAPMCLOG_SUCCESS
    # The pattern "The adjustment of memory configuration is done and refer to $check_log" will be parsed by auto-notify
    $out_str .= "Done.\nThe adjustment of memory configuration is done and refer to $check_log\n";
    $out_str .= "$sperate_line$remd_str$sperate_line";
  } elsif (($result>>8) == ERR::CANNOT_ADJUST) { # CANT_ADJUST: cannot adjust memory config
    $out_str .= "Failed.\nPlease check link error or check $check_log.\n";
    $out_str .= "$sperate_line$remd_str$sperate_line";
  }elsif (($result>>8) == ERR::ERR_LOADVIEWSIZE_INSUFFICIENT) { # ERR_LOADVIEWSIZE_INSUFFICIENT: cannot adjust memory config
    $out_str .= "Failed.\nPlease refer to $check_log for the recommended modification.\n";
    $out_str .= "$sperate_line$remd_str$sperate_line";
  } elsif (($result>>8) == ERR::NO_NEED_TO_UPDATE) { # NO_NEED_TO_UPDATE: skip AAPMC operation and treat it as AAPMCLOG_SUCCESS
    # The pattern "The adjustment of memory configuration is done and refer to $check_log" will be parsed by auto-notify
    $out_str .= "Done.\nDo not need to adjust memory configuration and refer to $check_log\n";
    if($check_scrip eq "ModemReservedSize_AutoConfig"){
      open(TEMPFILE,">$AAPMC_TEMP_FOLDER/~NoAAPMC.tmp") or &error_handler("cannot open $AAPMC_TEMP_FOLDER/~NoAAPMC.tmp!", __FILE__, __LINE__);
      print TEMPFILE ".";
      close TEMPFILE;
    }
  } elsif (($result>>8) == ERR::ERR_MODIFYDUPLICATED) { # ERR_MODIFYDUPLICATED: cannot modify same memory config more than twice
    $out_str .= "Failed.\nDuplicate memory configuration value are existed. Please check $check_log\n";
  } elsif ((101 <= ($result>>8)) && ( ($result>>8) <= 110)) { # special error code
    $out_str .= "Failed.\nsome errors occured while executing tools/$check_scrip.pl. Please check $check_log\n";
  } else {
    $out_str .= "Failed.\nsome errors occured while executing tools/$check_scrip.pl. Please check $check_log\n";
  }
  
  my $return_code = $result>>8;
  if($Status != 0) {
    $return_code .= "-".$Status;
  }
  
  if((($result>>8) == ERR::AAPMCLOG_SUCCESS && $Status != ERR::ERR_MODIFYFAIL) or
     (($result>>8) == ERR::AUTOCONFIG_SELF_MODIFY_SUCCESS) or
     (($result>>8) == ERR::NO_NEED_TO_UPDATE) or
     (($result>>8) == ERR::NO_MODIFY)){
       print "Result[$return_code]: $out_str\n";
       print STDERR "Result[$return_code]: $out_str\n";
       if(-e "$AAPMC_LOG_FOLDER/auto_adjust_mem.log" && $check_scrip eq "ModemReservedSize_AutoConfig" && (($result>>8) == ERR::NO_MODIFY or ($result>>8) == ERR::NO_NEED_TO_UPDATE)){
         mkpath("$AAPMC_TARGDIR/MODEM_RESV_SIZE_DEBUG") or &error_handler("create $AAPMC_TARGDIR/MODEM_RESV_SIZE_DEBUG folder failed!", __FILE__, __LINE__) if(!-d "$AAPMC_TARGDIR/MODEM_RESV_SIZE_DEBUG");
         print STDERR "copy $AAPMC_LOG_FOLDER/auto_adjust_mem.log $AAPMC_TARGDIR/MODEM_RESV_SIZE_DEBUG/auto_adjust_mem.log\n";
         
         #copy("$AAPMC_LOG_FOLDER/auto_adjust_mem.log","$AAPMC_TARGDIR/MODEM_RESV_SIZE_DEBUG/auto_adjust_mem.log");
         if($^O eq "MSWin32")
         {
           system("copy /y $AAPMC_LOG_FOLDER/auto_adjust_mem.log $AAPMC_TARGDIR/MODEM_RESV_SIZE_DEBUG/auto_adjust_mem.log  > nul");
         }
         elsif($^O eq "linux")
         {
           system("cp $AAPMC_LOG_FOLDER/auto_adjust_mem.log $AAPMC_TARGDIR/MODEM_RESV_SIZE_DEBUG");
         }
       }
    
  } else {
    print "AAPMC Error: Error[$return_code] $out_str\n";
    print STDERR "AAPMC Error: Error[$return_code] $out_str";
    exit 1;
  }
  
}

#*************************************************************************************************
# Check system drive error
# >> For File System
#*************************************************************************************************
sub cksysdrvError{
  my $CK_SYSDRV_ERR = 0;
  my $err_str = "";
  print "enter to check error for system drive...\n";
  if(-e $ckSYSDRV_LOG) { 
    open (FILE_HANDLE, $ckSYSDRV_LOG) or &error_handler("cannot open $ckSYSDRV_LOG!", __FILE__, __LINE__);
    while (<FILE_HANDLE>) {
      if ($_ =~ /Shortage/i) {
        print "[Cksysdrv Error] $_" if($DEBUG);
        $err_str .= $_;
        $CK_SYSDRV_ERR = 1;
      } 
    }
    close FILE_HANDLE; 
    if($CK_SYSDRV_ERR) {
      mkpath("$AAPMC_TARGDIR/FILE_SYSTEM_DEBUG") or &error_handler("create $AAPMC_TARGDIR/FILE_SYSTEM_DEBUG folder failed!", __FILE__, __LINE__) if(!-d "$AAPMC_TARGDIR/FILE_SYSTEM_DEBUG");
      copy("$ckSYSDRV_LOG","$AAPMC_TARGDIR/FILE_SYSTEM_DEBUG/ckSysDrv.log.error");
    }
  }
  if($CK_SYSDRV_ERR) {
    open(TEMPFILE,">$AAPMC_TEMP_FOLDER/~FS_LinkError.tmp") or &error_handler("cannot open $AAPMC_TEMP_FOLDER/~FS_LinkError.tmp!", __FILE__, __LINE__);
    print TEMPFILE "$err_str";
    #parse code size in checkbinaryblockusage.log
    if(-e $ckBBU_LOG) { 
      open (FILE_HANDLE, $ckBBU_LOG) or &error_handler("cannot open $ckBBU_LOG!", __FILE__, __LINE__);
      while (<FILE_HANDLE>) {
        if ($_ =~ /BIN size = .+ on NAND Flash/i) {
          print TEMPFILE "[CheckBinaryBlockUsage Info] $_";
        } 
      }
      close FILE_HANDLE; 
    }
    close TEMPFILE;
  }
  return $CK_SYSDRV_ERR;   
}

#*************************************************************************************************
# Check Binary Block Usage
# >> For bin file will obverlap FAT or not
#*************************************************************************************************
sub ckBinBlockUasgeError{
  my $CK_BBU_ERR = 0;
  my $err_str = "";
  print "enter to check error for binary block usage...\n";
  if(-e $ckBBU_LOG) { 
    open (FILE_HANDLE, $ckBBU_LOG) or &error_handler("cannot open $ckBBU_LOG!", __FILE__, __LINE__);
    while (<FILE_HANDLE>) {
      if ($_ =~ /Error: BIN(.+)overlap/i) {
        print "[CheckBinaryBlockUsage Error] $_" if($DEBUG);
        $err_str .= $_;
        $CK_BBU_ERR = 1;
      }
    }
    close FILE_HANDLE; 
    if($CK_BBU_ERR) {
      mkpath("$AAPMC_TARGDIR/FILE_SYSTEM_DEBUG") or &error_handler("create $AAPMC_TARGDIR/FILE_SYSTEM_DEBUG folder failed!", __FILE__, __LINE__) if(!-d "$AAPMC_TARGDIR/FILE_SYSTEM_DEBUG");
      copy("$ckBBU_LOG","$AAPMC_TARGDIR/FILE_SYSTEM_DEBUG/checkBinaryBlockUsage.log.error");
    }
  }
  if($CK_BBU_ERR) {
    open(TEMPFILE,">>$AAPMC_TEMP_FOLDER/~FS_LinkError.tmp") or &error_handler("cannot open $AAPMC_TEMP_FOLDER/~FS_LinkError.tmp!", __FILE__, __LINE__);
    print TEMPFILE "$err_str";
    close TEMPFILE;
  }
  return $CK_BBU_ERR;   
}

#*************************************************************************************************
# Check system drive error
# >> For File System
#*************************************************************************************************
sub ckLinkError{
  my $CK_LK_ERR = 0;
  my $link_err_str = "";
  print "enter to check link error...\n";
  if(-e $AAPMC_LINKLOG) {
    my $linklogname = basename($AAPMC_LINKLOG);
    open (FILE_HANDLE, $AAPMC_LINKLOG) or &error_handler("cannot open $AAPMC_LINKLOG!", __FILE__, __LINE__);
    while (<FILE_HANDLE>) {
      $_ =~ s/\s+$//;
      if ($_ =~ /is not within region \`(RAM|ROM|VRAM)\'|will not fit in region \`ROM\'$/) {
        print "[Link Error] $_\n" if($DEBUG);
        $link_err_str .= $_."\n";
        $CK_LK_ERR = 1;
      } 
    }
    close FILE_HANDLE; 
    if($CK_LK_ERR) {
      mkpath("$AAPMC_TARGDIR/MODEM_RESV_SIZE_DEBUG") or &error_handler("create $AAPMC_TARGDIR/MODEM_RESV_SIZE_DEBUG folder failed!", __FILE__, __LINE__) if(!-d "$AAPMC_TARGDIR/MODEM_RESV_SIZE_DEBUG");
      copy("$AAPMC_LINKLOG","$AAPMC_TARGDIR/MODEM_RESV_SIZE_DEBUG/$linklogname");
      unlink $AAPMC_LINKLOG;
    }
  }
  else
  {
    $CK_LK_ERR = 1;
  }
  if($CK_LK_ERR) {
    open(TEMPFILE,">$AAPMC_TEMP_FOLDER/~ModemReservedSize_AutoConfig.tmp") or &error_handler("cannot open $AAPMC_TEMP_FOLDER/~ModemReservedSize_AutoConfig.tmp!", __FILE__, __LINE__);
    print TEMPFILE "$link_err_str";
    close TEMPFILE;
  }
  return $CK_LK_ERR;   
}

#*************************************************************************************************
# Get recommand value after script calculation
# >> To show in command line
#*************************************************************************************************
sub getRecomdValue{
  $logfile = $_[0];
  my $backup= $/;
  undef $/;
  open B_FLIE,"<$logfile" or &error_handler("cannot open $logfile!", __FILE__, __LINE__);
  my $reading = <B_FLIE>;
  $/ = $backup;
  close B_FLIE;
 
  return $reading;
}

#*************************************************************************************************
# Error Handling Message
#*************************************************************************************************
sub error_handler
{
     my ($error_msg, $file, $line_no) = @_;
     my $final_error_msg = "ERROR: $error_msg at $file line $line_no\n";
     print $final_error_msg;
     exit 99;
}

#*************************************************************************************************
# Backup files to debug
#*************************************************************************************************
sub backup_file
{
  my ($input_file,$out_folder) = @_;
  my $bk_file = basename($input_file);
  mkpath("$out_folder") or &error_handler("create $out_folder folder failed!", __FILE__, __LINE__) if(!-d "$out_folder");
  copy("$input_file","$out_folder/$bk_file.backup");
}
