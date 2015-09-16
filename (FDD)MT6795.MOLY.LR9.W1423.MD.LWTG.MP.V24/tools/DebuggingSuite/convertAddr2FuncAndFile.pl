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
#*   xxx  (mtkxxxxx)
#*
#*============================================================================
#*             HISTORY
#* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*------------------------------------------------------------------------------
#* $Revision$
#* $Modtime$
#* $Log$
#*
#* 04 28 2014 woody.kuo
#* [MOLY00054950] [System Service][MOLY Kernel Internal Request] To prevent nested exception during KAL_ERROR_BUFFMNGR_ISVALID_FAILED
#* change file to binmode due to 0xa 0xd
#*
#*------------------------------------------------------------------------------
#* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*============================================================================
#****************************************************************************/

#****************************************************************************
# Included Modules
#****************************************************************************


#****************************************************************************
# Constants
#****************************************************************************
my $MY_VERNO     = " v0.02";
                  #  v0.01 , initial draft


#****************************************************************************
# File Names
#****************************************************************************
my $DBGINFO = $ARGV[0];
my $ADDRESS = $ARGV[1];
my $AddressInDecimal;

my $DebugPrint    = 0; # 1 for debug; 0 for non-debug

printf STDERR "version: $MY_VERNO\n"  if($DebugPrint == 1);
#****************************************************************************
# 0 >>>  Print out input parameters for checking
#****************************************************************************
if ($DebugPrint == 1) {
    printf  "DBGINFO: $DBGINFO\n";
    printf  "ADDRESS: $ADDRESS\n";
    printf  "\n";
}

#****************************************************************************
# 1 >>> Check Input ADDRESS
#****************************************************************************
printf  "Starting stage1... (Check input ADDRESS)\n" if($DebugPrint == 1);
if ($ADDRESS =~ m/0x[a-fA-F0-9]+/) {
  $AddressInDecimal = hex($ADDRESS);
  printf  "input ADDRESS = 0x%x\n", $AddressInDecimal  if($DebugPrint == 1);
}
else {
    &error_handler("Illegal ADDRESS: $ADDRESS! please input address beginning with format \"0x?\"", __FILE__, __LINE__);
}
print "\n"  if($DebugPrint == 1);

my $func = convert2FuncName($AddressInDecimal);
my $file = convert2FileName($AddressInDecimal);

if ($func eq "\0"){
    printf "error: input address $ADDRESS is not a function address!!!";
} else {
    printf "file: $file, func: $func \n";
}

#****************************************************************************
# oo >>>  Finished
#****************************************************************************
exit 0;

#-------------------------------------------------------------------------------------------------------------
#| DbgInfo output file format                                                                                |
#|-----------------------------------------------------------------------------------------------------------|
#| Item                                                 | Content                                 | Size     |
#|------------------------------------------------------|-----------------------------------------|----------|
#| DEBUGINFO_DB_FILE_PREFIX                             | CATI                                    | 4        |
#|------------------------------------------------------|-----------------------------------------|----------|
#| DEBUGINFO_DB_VER_MAIN                                | 1                                       | 4        |
#|------------------------------------------------------|-----------------------------------------|----------|
#| DEBUGINFO_DB_VER_SUB                                 | 0                                       | 4        |
#|------------------------------------------------------|-----------------------------------------|----------|
#| Project Name                                         | (string)argv[3]                         | length+1 | 
#|------------------------------------------------------|-----------------------------------------|----------|
#| HW Version                                           | (string)argv[4]                         | length+1 | 
#|------------------------------------------------------|-----------------------------------------|----------|
#| SW Version                                           | (string)argv[5]                         | length+1 |
#|------------------------------------------------------|-----------------------------------------|----------|
#| Build Time                                           | (string)argv[6]                         | length+1 |
#|------------------------------------------------------|-----------------------------------------|----------|
#| Sym Table Offset                                     | nSymTableOffset                         | 4        |
#|------------------------------------------------------|-----------------------------------------|----------|
#| File Table Offset                                    | nFileTableOffset                        | 4        |
#|------------------------------------------------------|-----------------------------------------|----------|
#| Symbol Table | Function name                         | m_mFunctions.m_Name                     | length+1 |
#|              |---------------------------------------|-----------------------------------------|----------|
#|              | Start Address                         | m_mFunctions.m_Addr                     | 4        |
#|              |---------------------------------------|-----------------------------------------|----------|
#|              | End Address                           | m_mFunctions.m_Addr+m_mFunctions.m_Size | 4        |
#|              |--------------------------------------------------------------------------------------------|
#|              | Repeat above 3 items�K                                                                      |
#|              |--------------------------------------------------------------------------------------------|
#|              | NULL Function Name                    | ""                                      | 1        |
#|--------------|---------------------------------------|-----------------------------------------|----------|
#| File Table   | m_mRangesByFile       | File Path     | key                                     | length+1 |
#|              |-----------------------|---------------|-----------------------------------------|----------|
#|              | m_mRangesByFile       | Count         | value.size                              | 4        |
#|              |-----------------------|---------------|-----------------------------------------|----------|
#|              | m_mRangesByFile.value | Start Address | m_mRangesByFile.value.key               | 4        |
#|              |                       |---------------|-----------------------------------------|----------|
#|              |                       | End Address   | m_mRangesByFile.value.value             | 4        |
#|              |                       |--------------------------------------------------------------------|
#|              |                       | Repeat above 2 items�K                                              |
#|              |--------------------------------------------------------------------------------------------|
#|              | Repeat above 3 items�K                                                                      |
#|              |--------------------------------------------------------------------------------------------|
#|              | NULL Function Name                    | ""                                      | 1        |
#-------------------------------------------------------------------------------------------------------------

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
        printf  "function name = \"%40s\"", $str  if($DebugPrint == 1);
        
        # read start address
        for ($i = 0; $i < 4; $i++) {
            read FILE_HANDLE, $byte[$i], 1;
        }
        $start_addr = get_int32(ord($byte[0]), ord($byte[1]), ord($byte[2]), ord($byte[3]));
        printf  ", start_addr = 0x%08x", $start_addr  if($DebugPrint == 1);
        
        # read end address
        for ($i = 0; $i < 4; $i++) {
            read FILE_HANDLE, $byte[$i], 1;
        }
        $end_addr = get_int32(ord($byte[0]), ord($byte[1]), ord($byte[2]), ord($byte[3]));
        printf  ", end_addr = 0x%08x\n", $end_addr  if($DebugPrint == 1);
        
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
# subroutine:  error_handler
# input:       $error_msg:     error message
#              $file:          filename
#              $line_no:       line number
#****************************************************************************
sub error_handler
{
    my ($error_msg, $file, $line_no) = @_;

    my $final_error_msg = "PARSER ERROR: $error_msg at $file line $line_no\n";
    die $final_error_msg;
}
