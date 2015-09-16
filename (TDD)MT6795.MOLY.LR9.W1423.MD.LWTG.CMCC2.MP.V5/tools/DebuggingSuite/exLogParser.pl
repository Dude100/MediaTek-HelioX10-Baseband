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
#*   exLogParser.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script parses raw data of the exception log
#*
#* Author:
#* -------
#*   Ken Lin  (mtk02554)
#*
#*============================================================================
#*             HISTORY
#* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*------------------------------------------------------------------------------
#* $Revision$
#* $Modtime$
#* $Log$
#*
#* 06 24 2014 qmei.yang
#* [MOLY00067552] [System Service][MOLY Kernel Internal Request] Change get exception timestamp code
#* .
#*
#* 04 29 2014 qmei.yang
#* [MOLY00064133] [SystemService][DebuggingSuite][Internal Refinement] Fix ex_log_parser.pl convert2FuncName parsing failure
#* .
#*
#* 03 22 2014 qmei.yang
#* [MOLY00060431] [SystemService][DebuggingSuite][Internal Refinement] Enrich exception information for world phone support
#* .
#*
#* 08 06 2013 ken.lin
#* [MOLY00031394] [SST][ChangeFeature] Enhance the stack dump display in exLogParser.pl
#* .
#*
#* 07 29 2013 ken.lin
#* [MOLY00031394] [SST][ChangeFeature] Enhance the stack dump display in exLogParser.pl
#* .
#* 
#* 08 31 2012 ken.lin
#* [MOLY00002912] [SST][NewFeature] exception log parser and add comments as reminder in structure definition
#* .
#*
#*
#*------------------------------------------------------------------------------
#* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*============================================================================
#****************************************************************************/

#****************************************************************************
# Included Modules
#****************************************************************************
use strict;
BEGIN { push @INC, '.\\tools\\' }  # add additional library path 
use File::Copy;

#****************************************************************************
# Constants
#****************************************************************************
my $ZIMAGECONFIG_VERNO     = " v0.03";
                       #  v0.03 , support new timestamp format
                       #  v0.02 , enhance stack dump
                       #  v0.01 , initial draft


#****************************************************************************
# File Names
#****************************************************************************
my $FORMAT = $ARGV[0];
my $EX_LOG = $ARGV[1];
my $DBGINFO = $ARGV[2];

# to align error message file name format
$EX_LOG =~ s/^.\\|^\\//;

my $DebugPrint    = 0; # 1 for debug; 0 for non-debug

#****************************************************************************
# 0 >>>  Print out input parameters for checking
#****************************************************************************
if ($DebugPrint == 1) {
    print "FORMAT: $FORMAT\n";
    print "EX_LOG: $EX_LOG\n";
    print "DBGINFO: $DBGINFO\n";
    print "\n";
}

my (@ex_log_raw, $ex_log, $len, $i, $j);

#****************************************************************************
# 1 >>> Check Input Format
#****************************************************************************
print "Starting stage1... (Check input format)\n" if($DebugPrint == 1);
if ($FORMAT eq 'b' || $FORMAT eq '-b') {
    print "Format: binary\n"  if($DebugPrint == 1);
}
elsif ($FORMAT eq 'a' || $FORMAT eq '-a') {
    print "Format: AP log\n"  if($DebugPrint == 1);
}
else {
    &error_handler("Illegal format!", __FILE__, __LINE__);
}
print "\n";


#****************************************************************************
# 2 >>> Read In Exception Log
#****************************************************************************
print "Starting stage2... (Read in exception log)\n" if($DebugPrint == 1);

&error_handler("$EX_LOG: NOT exist!", __FILE__, __LINE__) if (!-e $EX_LOG);
open (FILE_HANDLE, "<$EX_LOG") or &error_handler("$EX_LOG: file error!", __FILE__, __LINE__);
#binmode FILE_HANDLE;

use constant EX_LOG_SIZE => 512;
my $log_size;

if ($FORMAT eq 'b' || $FORMAT eq '-b') {
    # binary form
    my ($data8, $n);
    
    $i = 0;
    while (($n = read FILE_HANDLE, $data8, 1) != 0) {
        $ex_log_raw[$i++] = ord($data8); # read 1 byte a time and convert ascii to integer
        $log_size += $n;
    }
}
else {
    # ap log form
    my ($line, @data32);
    
    $i = 0;    
    while ($line = <FILE_HANDLE>) {
        #print $line;
        if ($line =~ /(\w+) (\w+) (\w+) (\w+)/) {
            $data32[0] = $1;
            $data32[1] = $2;
            $data32[2] = $3;
            $data32[3] = $4;
            foreach $_ (@data32) {
                $ex_log_raw[$i++] = hex($_) & 0x000000FF;
                $ex_log_raw[$i++] = (hex($_) & 0x0000FF00) >> 8;
                $ex_log_raw[$i++] = (hex($_) & 0x00FF0000) >> 16;
                $ex_log_raw[$i++] = (hex($_) & 0xFF000000) >> 24;
                $log_size += 4;
            }
        }
    }
}
    
close (FILE_HANDLE);
if ($log_size < EX_LOG_SIZE) {
    &error_handler("Incomplete log!", __FILE__, __LINE__);
}
print "\n";


#****************************************************************************
# 3 >>> Parse Exception Log
#****************************************************************************
print "Starting stage3... (Parse exception log)\n" if($DebugPrint == 1);

#****************************************************************************
# 3-1 >>> Parse Header (offset: +0x0, length: 4)
#****************************************************************************
my @exception_type = (
  'INVAID_EXCEPTION',
  'UNDEF_EXCEPTION',
  'SWI_EXCEPTION',
  'PREFETCH_EXCEPTION',
  'DATAABORT_EXCEPTION',
  'ASSERT_FAIL_EXCEPTION',
  'SYS_FATALERR_EXT_TASK_EXCEPTION',
  'SYS_FATALERR_EXT_BUF_EXCEPTION',
  'SYS_LOCKUP',
  'ASSERT_DUMP_EXTENDED_RECORD',
  'ASSERT_FAIL_NATIVE',
  'DSP_ASSERT_FAIL',
  'DSP_FATAL_ERROR',
  'STACKACCESS_EXCEPTION'
);
my ($ex_type, $ex_nvram, $ex_serial_num);

$ex_log .= "header = \n";

# 3-1-1 >>> ex_type (offset: +0x0, length: 1)
$ex_type = $ex_log_raw[0x0];
$ex_log .= " - ex_type = $exception_type[$ex_type]\n";

# 3-1-2 >>> ex_nvram (offset: +0x1, length: 1)
$ex_nvram = $ex_log_raw[0x1];
$ex_log .= " - ex_nvram = $ex_nvram\n";

# 3-1-3 >>> ex_serial_num (offset: +0x2, length: 2)
$ex_serial_num = get_int16($ex_log_raw[0x2], $ex_log_raw[0x3]);
$ex_log .= " - ex_serial_num = $ex_serial_num\n";


#****************************************************************************
# 3-2 >>>  Parse SW Version (offset: +0x4, length: 12)
#****************************************************************************
my $sw_version;

$i = 0;
while($i < 12) {
    last if (!(chr($ex_log_raw[$i + 0x4]) =~ /[\w.]/));
    $sw_version .= chr($ex_log_raw[$i + 0x4]);
    $i++;
}
$ex_log .= "sw_version = $sw_version\n";


#****************************************************************************
# 3-3 >>> Parse Environment Information (offset: +0x10, length: 164)
#****************************************************************************
my ($boot_mode, $USCNT, $FrameNo, $execution_unit, $status, $stack_ptr, @stack_dump, $ext_queue_pending_cnt, 
    @ext_queue_pending, @interrupt_mask, $processing_lisr, $lr, $is_dbginfo_exist);
my @boot_mode_type = (
  'FACTORY_BOOT',
  'NORMAL_BOOT',
  'USBMS_BOOT',
  'FUE_BOOT'
);

$ex_log .= "envinfo = \n";

# 3-3-1 >>> boot_mode (offset: +0x18, length: 1)
$boot_mode = $ex_log_raw[0x18];
$ex_log .= " - ex_type = $boot_mode_type[$boot_mode]\n";

# 3-3-2 >>> ex_timestamp (offset: +0x10, length: 8)
$USCNT = get_int32($ex_log_raw[0x10], $ex_log_raw[0x11], $ex_log_raw[0x12], $ex_log_raw[0x13]);
$FrameNo = get_int32($ex_log_raw[0x14], $ex_log_raw[0x15], $ex_log_raw[0x16], $ex_log_raw[0x17]);
$ex_log .= " - USCNT = $USCNT\n";
$ex_log .= " - FrameNo = $FrameNo\n";


# 3-3-3 >>> execution_unit (offset: +0x19, length: 8)
$i = 0;
while($i < 8) {
    last if (!(chr($ex_log_raw[$i + 0x19]) =~ /[\w]/));
    $execution_unit .= chr($ex_log_raw[$i + 0x19]);
    $i++;
}
$ex_log .= " - execution_unit = $execution_unit\n";

# 3-3-4 >>> status (offset: +0x21, length: 1)
$status = $ex_log_raw[0x21];
$ex_log .= " - status = $status\n";

# 3-3-5 >>> stack_ptr (offset: +0x24, length: 4)
$stack_ptr = get_int32($ex_log_raw[0x24],
                       $ex_log_raw[0x25],
                       $ex_log_raw[0x26],
                       $ex_log_raw[0x27]);
$ex_log .= sprintf(" - stack_ptr = 0x%08X\n", $stack_ptr);

# 3-3-6 >>> stack_dump (offset: +0x28, length: 40)
$is_dbginfo_exist = 0;
if (-e $DBGINFO) {
    $is_dbginfo_exist = 1;
    $ex_log .= " - stack_dump = \n";
}
else {
    $ex_log .= " - stack_dump = [If you have DbgInfo, please feed it to exLogParser.pl for more information.]\n";
}

for($i = 0; $i < 10; $i++) {
    $stack_dump[$i] .= get_int32($ex_log_raw[($i * 4) + 0x28],
                                 $ex_log_raw[($i * 4) + 0x29],
                                 $ex_log_raw[($i * 4) + 0x2A],
                                 $ex_log_raw[($i * 4) + 0x2B]);
    $ex_log .= sprintf("    0x%08X", $stack_dump[$i]);
    if ($stack_dump[$i] != 0 && $stack_dump[$i] != 0xCCCCCCCC && $is_dbginfo_exist == 1) {
        $ex_log .= " -> " . convert2FuncName($stack_dump[$i]) . "( file: " . convert2FileName($stack_dump[$i]) . ")";
    }
    $ex_log .= "\n";
}

# 3-3-7 >>> ext_queue_pending_cnt (offset: +0x50, length: 2)
$ext_queue_pending_cnt = get_int16($ex_log_raw[0x50],
                                   $ex_log_raw[0x51]);
$ex_log .= " - ext_queue_pending_cnt = $ext_queue_pending_cnt\n";

# 3-3-8 >>> ext_queue_pending (offset: +0x54, length: 80)
$ex_log .= " - ext_queue_pending = \n";
$len = 20;
$i = 0;
while($i < $len) {
    $j = 0;
    while($j < 4) {
        $ext_queue_pending[$i] = get_int32($ex_log_raw[($i * 4) + 0x54],
                                           $ex_log_raw[($i * 4) + 0x55],
                                           $ex_log_raw[($i * 4) + 0x56],
                                           $ex_log_raw[($i * 4) + 0x57]);
        if ($i % 4 == 0) {
            $ex_log .= sprintf("    0x%08X,", $ext_queue_pending[$i]);
        }
        elsif ($i % 4 == 3) {
            $ex_log .= sprintf(" 0x%08X\n", $ext_queue_pending[$i]);
        }
        else {
            $ex_log .= sprintf(" 0x%08X,", $ext_queue_pending[$i]);
        }
            
        $j++;
        last if(++$i == $len);
    }
}

# 3-3-9 >>> interrupt_mask (offset: +0xA4, length: 8)
$interrupt_mask[0] = get_int32($ex_log_raw[0xA4],
                               $ex_log_raw[0xA5],
                               $ex_log_raw[0xA6],
                               $ex_log_raw[0xA7]);
$interrupt_mask[1] = get_int32($ex_log_raw[0xA8],
                               $ex_log_raw[0xA9],
                               $ex_log_raw[0xAA],
                               $ex_log_raw[0xAB]);
$ex_log .= sprintf(" - interrupt_mask = 0x%08X, 0x%08X\n", $interrupt_mask[0], $interrupt_mask[1]);

# 3-3-10 >>> processing_lisr (offset: +0xAC, length: 4)
$processing_lisr = get_int32($ex_log_raw[0xAC],
                             $ex_log_raw[0xAD],
                             $ex_log_raw[0xAE],
                             $ex_log_raw[0xAF]);
$ex_log .= sprintf(" - processing_lisr = 0x%08X\n", $processing_lisr);

# 3-3-11 >>> lr (offset: +0xB0, length: 4)
$lr = get_int32($ex_log_raw[0xB0],
                $ex_log_raw[0xB1],
                $ex_log_raw[0xB2],
                $ex_log_raw[0xB3]);
$ex_log .= sprintf(" - lr = 0x%08X\n", $lr);


#****************************************************************************
# 3-4 >>> Parse Diagnosis (offset: +0xB4, length: 36)
#****************************************************************************
my ($diagnosis, $owner, $timing_check);
my @diagnosis_type = (
  'Healthy',
  'InternalSRAMCorrupted',
  'SystemStackCorrupted',
  'TaskStackCorrupted',
  'HISRStackCorrupted',
  'VectorTableCorrupted'
);

$ex_log .= "diaginfo = \n";

# 3-4-1 >>> diagnosis (offset: +0xB4, length: 1)
$diagnosis = $ex_log_raw[0xB4];
$ex_log .= " - diagnosis = $diagnosis_type[$diagnosis]\n";

# 3-4-2 >>> owner (offset: +0xB5, length: 8)
$i = 0;
while($i < 8) {
    last if (!(chr($ex_log_raw[$i + 0xB5]) =~ /[\w]/));
    $owner .= chr($ex_log_raw[$i + 0xB5]);
    $i++;
}
$ex_log .= " - owner = $owner\n";

# 3-4-3 >>> timing_check (useless?)


#****************************************************************************
# 3-5 >>> Parse Content (offset: +0xD8, length: 292)
#****************************************************************************
$ex_log .= "content = \n";

# check exception type
if ($exception_type[$ex_type] eq 'ASSERT_FAIL_EXCEPTION'
    || $exception_type[$ex_type] eq 'ASSERT_DUMP_EXTENDED_RECORD'
    || $exception_type[$ex_type] eq 'ASSERT_FAIL_NATIVE') {
#****************************************************************************
# 3-5-A >>> Assert
#****************************************************************************
my ($filename, $linenumber, @parameters, @dump, $guard);

$ex_log .= " assert = \n";

# 3-5-A-1 >>> filename (offset: +0xD8, length: 24)
$i = 0;
while($i < 24) {
    $filename .= chr($ex_log_raw[($i++) + 0xD8]);
}
$ex_log .= "  - filename = $filename\n";

# 3-5-A-2 >>> linenumber (offset: +0xF0, length: 4)
$linenumber = get_int32($ex_log_raw[0xF0],
                        $ex_log_raw[0xF1],
                        $ex_log_raw[0xF2],
                        $ex_log_raw[0xF3]);
$ex_log .= "  - linenumber = $linenumber\n";

# 3-5-A-3 >>> parameters (offset: +0xF4, length: 12)
$parameters[0] = get_int32($ex_log_raw[0xF4],
                           $ex_log_raw[0xF5],
                           $ex_log_raw[0xF6],
                           $ex_log_raw[0xF7]);
$parameters[1] = get_int32($ex_log_raw[0xF8],
                           $ex_log_raw[0xF9],
                           $ex_log_raw[0xFA],
                           $ex_log_raw[0xFB]);
$parameters[2] = get_int32($ex_log_raw[0xFC],
                           $ex_log_raw[0xFD],
                           $ex_log_raw[0xFE],
                           $ex_log_raw[0xFF]);
$ex_log .= sprintf("  - parameters = 0x%08X, 0x%08X, 0x%08X\n", $parameters[0], $parameters[1], $parameters[2]);

# 3-5-A-4 >>> dump (offset: +0x100, length: 252)
if ($exception_type[$ex_type] eq 'ASSERT_DUMP_EXTENDED_RECORD') {
    $ex_log .= "  - dump = \n";
    $len = 63;
    $i = 0;
    while($i < $len) {
        $j = 0;
        while($j < 4) {
            $dump[$i] = get_int32($ex_log_raw[($i * 4) + 0x100],
                                  $ex_log_raw[($i * 4) + 0x101],
                                  $ex_log_raw[($i * 4) + 0x102],
                                  $ex_log_raw[($i * 4) + 0x103]);
            if ($i % 4 == 0) {
                $ex_log .= sprintf("        0x%08X,", $dump[$i]);
            }
            elsif ($i % 4 == 3) {
                $ex_log .= sprintf(" 0x%08X\n", $dump[$i]);
            }
            else {
                $ex_log .= sprintf(" 0x%08X,", $dump[$i]);
            }
            
            $j++;
            last if(++$i == $len);
        }
    }
}
    
# 3-5-A-5 >>> guard (offset: +0x1FC, length: 4) (useless)

}
else {
#****************************************************************************
# 3-5-B >>> Fatal Error
#****************************************************************************
my ($code1, $code2);

$ex_log .= " fatalerr = \n";

# 3-5-B-1 >>> error_code (offset: +0xD8, length: 8)
$ex_log .= sprintf("  error_code =\n");
$code1 = get_int32($ex_log_raw[0xD8],
                   $ex_log_raw[0xD9],
                   $ex_log_raw[0xDA],
                   $ex_log_raw[0xDB]);
$code2 = get_int32($ex_log_raw[0xDC],
                   $ex_log_raw[0xDD],
                   $ex_log_raw[0xDE],
                   $ex_log_raw[0xDF]);
$ex_log .= sprintf("   - code1 = 0x%08X\n", $code1);
$ex_log .= sprintf("   - code2 = 0x%08X\n", $code2);

# 3-5-B-2 >>> description (offset: +0xE0, length: 20)
# 3-5-B-3 >>> analysis (offset: +0xF4, length: 52)
# 3-5-B-4 >>> guideline (offset: +0x128, length: 20)

# 3-5-B-5 >>> info (offset: +0x13C, length: 160)
$ex_log .= "  info =\n";
if ($exception_type[$ex_type] eq 'SYS_FATALERR_EXT_BUF_EXCEPTION') {
    # 3-5-B-5-X-1 >>> ctrl_buff (offset: +0x13C, length: 136)
    my ($ex_ctrlbuf_size, $ex_ctrlbuf_num);
    
    $ex_log .= "   ctrl_buff =\n";
    
    # 3-5-B-5-X-1-1 >>> ex_ctrlbuf_size (offset: +0x13C, length: 4)
    $ex_ctrlbuf_size = get_int32($ex_log_raw[0x13C],
                                 $ex_log_raw[0x13D],
                                 $ex_log_raw[0x13E],
                                 $ex_log_raw[0x13F]);
    $ex_log .= "    - ex_ctrlbuf_size = $ex_ctrlbuf_size\n";
    
    # 3-5-B-5-X-1-2 >>> ex_ctrlbuf_num (offset: +0x140, length: 4)
    $ex_ctrlbuf_num = get_int32($ex_log_raw[0x140],
                                $ex_log_raw[0x141],
                                $ex_log_raw[0x142],
                                $ex_log_raw[0x143]);
    $ex_log .= "    - ex_ctrlbuf_num = $ex_ctrlbuf_num\n";
    
    # 3-5-B-5-X-1-3 >>> ex_ctrlbuf_top (offset: +0x144, length: 32)
    $ex_log .= "    ex_ctrlbuf_top =\n";    
    parse_CtrlBuffInfo(0x144, $code1);
    
    # 3-5-B-5-X-1-4 >>> ex_ctrlbuf_second (offset: +0x164, length: 32)
    $ex_log .= "    ex_ctrlbuf_second =\n";    
    parse_CtrlBuffInfo(0x164, $code1);
    
    # 3-5-B-5-X-1-5 >>> ex_ctrlbuf_third (offset: +0x184, length: 32)
    $ex_log .= "    ex_ctrlbuf_third =\n";    
    parse_CtrlBuffInfo(0x184, $code1);
    
    # 3-5-B-5-X-1-6 >>> ex_monitor (offset: +0x1A4, length: 48)
    if ($code1 != 0x823) {
        $ex_log .= "    - ex_monitor =\n";
        $i = 0;
        while ($i < 3) {
            parse_Monitor(0x1A4 + $i * 0x10);
            $i++;
        }
    }
    
    # 3-5-B-6 >>> extrainfo (offset: +0x1D4, length: 36)
    parse_fatalerr_extrainfo(0x1D4);
    
}
elsif ($exception_type[$ex_type] eq 'SYS_FATALERR_EXT_TASK_EXCEPTION') {
    # 3-5-B-5-X-2 >>> task_info (offset: +0x13C, length: 160)
  
    $i = 0;
    while ($i < 4) {
        $ex_log .= "   task_info[$i] =\n";    
        parse_TaskInfo(0x13C + $i * 0x28);
        $i++;
    }

    # 3-5-B-6 >>> extrainfo (offset: +0x1DC, length: 36)
    parse_fatalerr_extrainfo(0x1DC);

}
elsif ($exception_type[$ex_type] eq 'UNDEF_EXCEPTION'
       || $exception_type[$ex_type] eq 'SWI_EXCEPTION'
       || $exception_type[$ex_type] eq 'PREFETCH_EXCEPTION'
       || $exception_type[$ex_type] eq 'DATAABORT_EXCEPTION') {
    # 3-5-B-5-X-3 >>> cpu_reg (offset: +0x13C, length: 68)
    my ($cpsr, @reg);
    
    $ex_log .= "   cpu_reg =\n";

    # 3-5-B-5-X-3-1 >>> cpsr (offset: +0x13C, length: 4)
    $cpsr = get_int32($ex_log_raw[0x13C],
                      $ex_log_raw[0x13D],
                      $ex_log_raw[0x13E],
                      $ex_log_raw[0x13F]);
    $ex_log .= sprintf("    - cpsr = 0x%08X\n", $cpsr);    
    
    # 3-5-B-5-X-3-2 >>> reg (offset: +0x140, length: 64)
    $ex_log .= sprintf("    reg =\n", $cpsr);    
    $i = 0;
    while($i <= 15) {
        $reg[$i] .= get_int32($ex_log_raw[($i * 4) + 0x140],
                              $ex_log_raw[($i * 4) + 0x141],
                              $ex_log_raw[($i * 4) + 0x142],
                              $ex_log_raw[($i * 4) + 0x143]);
        $ex_log .= sprintf("     - r%d = 0x%08X\n", $i, $reg[$i]);
        $i++;
    }
    
    # 3-5-B-6 >>> extrainfo (offset: +0x180, length: 36)
    parse_fatalerr_extrainfo(0x180);
}
else {
    # do nothing
}
}

# print to console
print $ex_log;


#****************************************************************************
# 4 >>> Output to a TXT
#****************************************************************************
open (FILE_HANDLE, ">$EX_LOG.txt") or &error_handler("$EX_LOG: file error!", __FILE__, __LINE__);
print FILE_HANDLE $ex_log;
close (FILE_HANDLE);

#****************************************************************************
# oo >>>  Finished
#****************************************************************************
exit 0;

#****************************************************************************
# subroutine:  get_int16
# input:       $byte0
#              $byte1
#****************************************************************************
sub get_int16
{
    my ($byte0, $byte1) = @_;
    return ($byte1 << 8) | $byte0;
}

#****************************************************************************
# subroutine:  get_int32
# input:       $byte0
#              $byte1
#              $byte2
#              $byte3
#****************************************************************************
sub get_int32
{
    my ($byte0, $byte1, $byte2, $byte3) = @_;
    return ($byte3 << 24) | ($byte2 << 16) | ($byte1 << 8) | $byte0;
}

#****************************************************************************
# subroutine:  parse_CtrlBuffInfo
# input:       base_offset
#              code1
#****************************************************************************
sub parse_CtrlBuffInfo
{
    my ($base_offset, $code1) = @_;
    my $i;
    
    # check if KAL_ERROR_BUFFMNGR_GETBUFF_NOT_AVAILABLE
    if ($code1 == 0x823) {
        # history
        $ex_log .= "     history = \n";        
        
        my ($ex_his_owner, $ex_his_source, $ex_his_line, $ex_his_count);
        
        # a >>> ex_his_owner
        $i = 0;
        while($i < 8) {
            last if (!(chr($ex_log_raw[$i + $base_offset]) =~ /[\w]/));
            $ex_his_owner .= chr($ex_log_raw[$i + $base_offset]);
            $i++;
        }
        $ex_log .= "      - ex_his_owner = $ex_his_owner\n";
        
        # b >>> ex_his_source
        $i = 0;
        while($i < 16) {
            last if (!(chr($ex_log_raw[$i + $base_offset + 0x8]) =~ /[\w.]/));
            $ex_his_source .= chr($ex_log_raw[$i + $base_offset + 0x8]);
            $i++;
        }
        $ex_log .= "      - ex_his_source = $ex_his_source\n";   
        
        # c >>> ex_his_line
        $ex_his_line = get_int32($ex_log_raw[$base_offset + 0x18],
                                 $ex_log_raw[$base_offset + 0x19],
                                 $ex_log_raw[$base_offset + 0x1A],
                                 $ex_log_raw[$base_offset + 0x1B]);
        $ex_log .= "      - ex_his_line = $ex_his_line\n";    
        
        # c >>> ex_his_count
        $ex_his_count = get_int32($ex_log_raw[$base_offset + 0x1C],
                                  $ex_log_raw[$base_offset + 0x1D],
                                  $ex_log_raw[$base_offset + 0x1E],
                                  $ex_log_raw[$base_offset + 0x1F]);
        $ex_log .= "      - ex_his_count = $ex_his_count\n";         
    }
    else {
        # common
        $ex_log .= "     common = \n";
        
        my ($ex_buf_RTOS_header1, $ex_buf_RTOS_header2, 
            $ex_buf_KAL_header1, $ex_buf_KAL_header2, $ex_buf_KAL_header3,
            $ex_buf_poolID, $ex_buf_KAL_footer1, $ex_buf_KAL_footer2);
            
        # a >>> ex_buf_RTOS_header1
        $ex_buf_RTOS_header1 = get_int32($ex_log_raw[$base_offset],
                                         $ex_log_raw[$base_offset + 0x1],
                                         $ex_log_raw[$base_offset + 0x2],
                                         $ex_log_raw[$base_offset + 0x3]);
        $ex_log .= sprintf("      - ex_buf_RTOS_header1 = 0x%08X\n", $ex_buf_RTOS_header1);
        
        # b >>> ex_buf_RTOS_header2
        $ex_buf_RTOS_header2 = get_int32($ex_log_raw[$base_offset + 0x4],
                                         $ex_log_raw[$base_offset + 0x5],
                                         $ex_log_raw[$base_offset + 0x6],
                                         $ex_log_raw[$base_offset + 0x7]);
        $ex_log .= sprintf("      - ex_buf_RTOS_header2 = 0x%08X\n", $ex_buf_RTOS_header2);
        
        # c >>> ex_buf_KAL_header1
        $ex_buf_KAL_header1 = get_int32($ex_log_raw[$base_offset + 0x8],
                                        $ex_log_raw[$base_offset + 0x9],
                                        $ex_log_raw[$base_offset + 0xA],
                                        $ex_log_raw[$base_offset + 0xB]);
        $ex_log .= sprintf("      - ex_buf_KAL_header1 = 0x%08X\n", $ex_buf_KAL_header1);
        
        # d >>> ex_buf_KAL_header2
        $ex_buf_KAL_header2 = get_int32($ex_log_raw[$base_offset + 0xC],
                                        $ex_log_raw[$base_offset + 0xD],
                                        $ex_log_raw[$base_offset + 0xE],
                                        $ex_log_raw[$base_offset + 0xF]);
        $ex_log .= sprintf("      - ex_buf_KAL_header2 = 0x%08X\n", $ex_buf_KAL_header2);        
        
        # e >>> ex_buf_KAL_header3
        $ex_buf_KAL_header3 = get_int32($ex_log_raw[$base_offset + 0x10],
                                        $ex_log_raw[$base_offset + 0x11],
                                        $ex_log_raw[$base_offset + 0x12],
                                        $ex_log_raw[$base_offset + 0x13]);
        $ex_log .= sprintf("      - ex_buf_KAL_header3 = 0x%08X\n", $ex_buf_KAL_header3);
        
        # f >>> ex_buf_poolID
        $ex_buf_poolID = get_int32($ex_log_raw[$base_offset + 0x14],
                                   $ex_log_raw[$base_offset + 0x15],
                                   $ex_log_raw[$base_offset + 0x16],
                                   $ex_log_raw[$base_offset + 0x17]);
        $ex_log .= sprintf("      - ex_buf_poolID = 0x%08X\n", $ex_buf_poolID);
        
        # g >>> ex_buf_KAL_footer1
        $ex_buf_KAL_footer1 = get_int32($ex_log_raw[$base_offset + 0x18],
                                        $ex_log_raw[$base_offset + 0x19],
                                        $ex_log_raw[$base_offset + 0x1A],
                                        $ex_log_raw[$base_offset + 0x1B]);
        $ex_log .= sprintf("      - ex_buf_KAL_footer1 = 0x%08X\n", $ex_buf_KAL_footer1);
        
        # h >>> ex_buf_KAL_footer2
        $ex_buf_KAL_footer2 = get_int32($ex_log_raw[$base_offset + 0x1C],
                                        $ex_log_raw[$base_offset + 0x1D],
                                        $ex_log_raw[$base_offset + 0x1E],
                                        $ex_log_raw[$base_offset + 0x1F]);
        $ex_log .= sprintf("      - ex_buf_KAL_footer2 = 0x%08X\n", $ex_buf_KAL_footer2);        
    }
}

#****************************************************************************
# subroutine:  parse_Monitor
# input:       base_offset
#****************************************************************************
sub parse_Monitor
{
    my ($base_offset) = @_;
    my ($ex_buf_source, $ex_buf_line, $i);
    
    # a >>> ex_buf_source
    $i = 0;
    while($i < 12) {
        last if (!(chr($ex_log_raw[$base_offset + $i]) =~ /[\w.]/));
        $ex_buf_source .= chr($ex_log_raw[$base_offset + $i]);
        $i++;
    }
    $ex_log .= "        ex_buf_source = $ex_buf_source, ";
    
    # b >>> ex_buf_line
    $ex_buf_line = get_int32($ex_log_raw[$base_offset + 0xC],
                             $ex_log_raw[$base_offset + 0xD],
                             $ex_log_raw[$base_offset + 0xE],
                             $ex_log_raw[$base_offset + 0xF]);
    $ex_log .= "ex_buf_line = $ex_buf_line\n";    
}

#****************************************************************************
# subroutine:  parse_TaskInfo
# input:       base_offset
#****************************************************************************
sub parse_TaskInfo
{
    my ($base_offset) = @_;
    my ($ex_task_name, $ex_task_stack_gp, $ex_task_cur_status, $i);
    
    # a >>> ex_task_name
    $i = 0;
    while($i < 8) {
        last if (!(chr($ex_log_raw[$base_offset + $i]) =~ /[\w]/));
        $ex_task_name .= chr($ex_log_raw[$base_offset + $i]);
        $i++;
    }
    $ex_log .= "    - ex_task_name = $ex_task_name\n";
    
    # b >>> ex_task_stack_gp    
    $i = 0;
    while($i < 8) {
        last if (!(chr($ex_log_raw[$base_offset + 0x8 + $i]) =~ /[\w]/));
        $ex_task_stack_gp .= chr($ex_log_raw[$base_offset + 0x8 + $i]);
        $i++;
    }
    $ex_log .= "    - ex_task_stack_gp = $ex_task_stack_gp\n";    
    
    # c >>> ex_task_cur_status
    $ex_task_cur_status = get_int32($ex_log_raw[$base_offset + 0x10],
                                    $ex_log_raw[$base_offset + 0x11],
                                    $ex_log_raw[$base_offset + 0x12],
                                    $ex_log_raw[$base_offset + 0x13]);
    $ex_log .= "    - ex_task_cur_status = $ex_task_cur_status\n";
    
    # d >>> ex_task_external_q
    $ex_log .= "    - ex_task_external_q =\n";
    parse_Queue($base_offset + 0x14);
    
    # e >>> ex_task_internal_q
    $ex_log .= "    - ex_task_internal_q =\n";
    parse_Queue($base_offset + 0x1C);    
}

#****************************************************************************
# subroutine:  parse_Queue
# input:       base_offset
#****************************************************************************
sub parse_Queue
{
    my ($base_offset) = @_;
    my ($ex_q_src_mod, $ex_q_count, $ex_q_msg_id, $ex_q_cur_mes_no, $ex_q_config_entry);
    
    # a >>> ex_q_src_mod
    $ex_q_src_mod = $ex_log_raw[$base_offset];
    $ex_log .= sprintf("      - ex_q_src_mod = 0x%02X\n", $ex_q_src_mod);
 
    # b >>> ex_q_count   
    $ex_q_count = $ex_log_raw[$base_offset + 0x1];
    $ex_log .= "      - ex_q_count = $ex_q_count\n"; 
    
    # c >>> ex_q_msg_id   
    $ex_q_msg_id = get_int16($ex_log_raw[$base_offset + 0x2],
                             $ex_log_raw[$base_offset + 0x3]);
    $ex_log .= sprintf("      - ex_q_msg_id = 0x%04X\n", $ex_q_msg_id);
    
    # d >>> ex_q_cur_mes_no   
    $ex_q_cur_mes_no = get_int16($ex_log_raw[$base_offset + 0x4],
                                 $ex_log_raw[$base_offset + 0x5]);
    $ex_log .= "      - ex_q_cur_mes_no = $ex_q_cur_mes_no\n";
    
    # e >>> ex_q_config_entry   
    $ex_q_config_entry = get_int16($ex_log_raw[$base_offset + 0x6],
                                   $ex_log_raw[$base_offset + 0x7]);
    $ex_log .= "      - ex_q_config_entry = $ex_q_config_entry\n";    
}

#****************************************************************************
# subroutine:  parse_fatalerr_extrainfo
# input:       base_offset
#****************************************************************************
sub parse_fatalerr_extrainfo
{
    my ($addr) = @_;
    $ex_log .= "  extrainfo =\n";
    $ex_log .= "    - ";
    my $i=0;
    my @extrainfo;
    while($i < 9) {
        $ex_log .= chr($ex_log_raw[($i * 4) + $addr]);
        $ex_log .= chr($ex_log_raw[($i * 4) + $addr+1]);
        $ex_log .= chr($ex_log_raw[($i * 4) + $addr+2]);
        $ex_log .= chr($ex_log_raw[($i * 4) + $addr+3]);
        $i++;
    }
}

#****************************************************************************
# subroutine:  convert2FuncName
# input:       addr
#****************************************************************************
sub convert2FuncName
{
    my ($addr) = @_;
    my ($data, @byte, $n, $i);
    my ($str, $start_addr, $end_addr);
    
    # open DbgInfo
    &error_handler("$DBGINFO: NOT exist!", __FILE__, __LINE__) if (!-e $DBGINFO);
    open (FILE_HANDLE, "<$DBGINFO") or &error_handler("$DBGINFO: file error!", __FILE__, __LINE__);
    binmode FILE_HANDLE;
    
    # skip three words & four strings
    foreach (1..3) {
        read FILE_HANDLE, $data, 4;
    }
    foreach (1..4) {
        while (($n = read FILE_HANDLE, $data, 1) != 0) {
            last if (ord($data) == 0);
        }
    }
    
    # skip two words (nSymTableOffset & nFileTableOffset)
    foreach (1..2) {
        read FILE_HANDLE, $data, 4;
    }
    
    # find the corresponding function name
    while (1) {
        # read a string
        $str = "";
        while (($n = read FILE_HANDLE, $data, 1) != 0) {
            $str .= $data;
            last if (ord($data) == 0);
        }
        
        # check if NULL string
        last if ($str eq "\0");
        
        # read start address
        for ($i = 0; $i < 4; $i++) {
            read FILE_HANDLE, $byte[$i], 1;
        }
        $start_addr = get_int32(ord($byte[0]), ord($byte[1]), ord($byte[2]), ord($byte[3]));
        
        # read end address
        for ($i = 0; $i < 4; $i++) {
            read FILE_HANDLE, $byte[$i], 1;
        }
        $end_addr = get_int32(ord($byte[0]), ord($byte[1]), ord($byte[2]), ord($byte[3]));
        
        #check if the one we want
        last if ($start_addr <= ($addr + 1) && ($addr + 1) < $end_addr);
    }
    
    # close DbgInfo
    close(FILE_HANDLE);
    
    if ($DebugPrint == 1) {
        print sprintf("start_addr: 0x%08X, end_addr: 0x%08X\n", $start_addr, $end_addr);    
        print sprintf("addr: 0x%08X\n", $addr);
        print "func_name returned: $str\n";
    }
    
    return $str;
}

#****************************************************************************
# subroutine:  convert2FileName
# input:       addr
#****************************************************************************
sub convert2FileName
{
    my ($addr) = @_;
    my ($data, @byte, $offset, $n, $i, $j);
    my ($nFileTableOffset, $str, $count, $start_addr, $end_addr);
    
    # open DbgInfo
    &error_handler("$DBGINFO: NOT exist!", __FILE__, __LINE__) if (!-e $DBGINFO);
    open (FILE_HANDLE, "<$DBGINFO") or &error_handler("$DBGINFO: file error!", __FILE__, __LINE__);
    
    # skip three words & four strings
    foreach (1..3) {
        read FILE_HANDLE, $data, 4;
    }
    $offset = 12;
    foreach (1..4) {
        while (($n = read FILE_HANDLE, $data, 1) != 0) {
            $offset++;            
            last if (ord($data) == 0);
        }
    }
    
    # read nFileTableOffset
    read FILE_HANDLE, $data, 4;
    for ($i = 0; $i < 4; $i++) {
        read FILE_HANDLE, $byte[$i], 1;
    }
    $nFileTableOffset = get_int32(ord($byte[0]), ord($byte[1]), ord($byte[2]), ord($byte[3]));
    $offset += 8;
    
    # go to the offset
    while($offset < $nFileTableOffset) {
        read FILE_HANDLE, $data, 1;
        $offset++;
    }
    
    # find the corresponding file name
    while (1) {
        # read a string
        $str = "";
        while (($n = read FILE_HANDLE, $data, 1) != 0) {
            $str .= $data;
            last if (ord($data) == 0);
        }
        
        # check if NULL string
        last if ($str eq "\0");
        
        #read count
        for ($i = 0; $i < 4; $i++) {
            read FILE_HANDLE, $byte[$i], 1;
        }
        $count = get_int32(ord($byte[0]), ord($byte[1]), ord($byte[2]), ord($byte[3]));
        
        for ($i = 0; $i < $count; $i++) {
            # read start address
            for ($j = 0; $j < 4; $j++) {
                read FILE_HANDLE, $byte[$j], 1;
            }
            $start_addr = get_int32(ord($byte[0]), ord($byte[1]), ord($byte[2]), ord($byte[3]));
            
            # read end address
            for ($j = 0; $j < 4; $j++) {
                read FILE_HANDLE, $byte[$j], 1;
            }
            $end_addr = get_int32(ord($byte[0]), ord($byte[1]), ord($byte[2]), ord($byte[3]));
            
            # check if the one we want
            last if ($start_addr <= ($addr + 1) && ($addr + 1) < $end_addr);
        }
        last if ($i < $count);
    }
    
    # close DbgInfo
    close(FILE_HANDLE);
    
    if ($DebugPrint == 1) {
        print sprintf("start_addr: 0x%08X, end_addr: 0x%08X\n", $start_addr, $end_addr);    
        print sprintf("addr: 0x%08X\n", $addr);
        print "file_name returned: $str\n";
    }
    
    return $str;
}

#****************************************************************************
# subroutine:  error_handler
# input:       $error_msg:     error message
#              $file:          filename
#              $line_no:       line number
#****************************************************************************
sub error_handler
{
    my ($error_msg, $file, $line_no) = @_;

    my $final_error_msg = "EX LOG PARSER ERROR: $error_msg at $file line $line_no\n";
    die $final_error_msg;
}
