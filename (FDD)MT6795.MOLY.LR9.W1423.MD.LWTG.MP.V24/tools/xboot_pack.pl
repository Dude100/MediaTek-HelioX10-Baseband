#!/usr/bin/perl
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2013
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
#*   xboot_pack.pl
#*
#* Project:
#* --------
#*   MOLY
#*
#* Description:
#* ------------
#*   Pack xboot image
#*       
#* Author:
#* -------
#*   Cindy Tu (mtk03468)
#*
#****************************************************************************
use strict;

#****************************************************************************
# Constants
#****************************************************************************
my $XBOOT_PACK_VERNO = " m0.01"; # v0.01 by mtk3468, initial version

#Usage:xboot_pack.pl DA_BINFILE_PATH(filename) BL_BINFILE_PATH(filename) EXT_BINFILE_PATH(filename) MOLY_Image(filename) DST_BINFILE_PATH(filename)

#****************************************************************************
# Global Variables
#****************************************************************************
my $IMG_TBL_MAGIC=0x2454E7D3;
my $IMG_TBL_ADDR_MAGIC=0x14;
my $IMG_TBL_BASE_ADDR=0x20;
my $IMG_TBL_SIZE=0x10;
my $IMG_TYPE_DA=0x06;
my $IMG_TYPE_MINI_BL=0x02;
my $IMG_TYPE_EXT_BL=0x03;
my $IMG_TYPE_MOLY=0x04;
my $IMAGE_ALIGN=0x100;
my $DA_MAX_SIZE=0x10000;
my $BL_MAX_SIZE=0x40000;
my $IMAGE_BIN_START=0x100;

my $da_base;
my $mini_bl_base;
my $ext_bl_base;
my $moly_base;

my @img_tbl_buffer;

#****************************************************************************
# Input Parameters
#****************************************************************************
my ($xboot_da_file)    = $ARGV[0];
my ($mini_bl_bin_file) = $ARGV[1];
my ($ext_bl_bin_file)  = $ARGV[2];
my ($moly_bin_file)    = $ARGV[3];
my ($dst_bin_file)     = $ARGV[4];
my ($net_path)         = $ARGV[5];
my ($partial_source)   = $ARGV[6];

print "Input: $xboot_da_file $mini_bl_bin_file $ext_bl_bin_file $moly_bin_file\n";

#****************************************************************************
# Parameter Check
#****************************************************************************
die "xboot DA file $xboot_da_file doesn't exist" if not -e $xboot_da_file;
die "mini BL file $mini_bl_bin_file doesn't exist" if not -e $mini_bl_bin_file;
die "ext BL file $ext_bl_bin_file doesn't exist" if not -e $ext_bl_bin_file;
die "moly binary file $moly_bin_file doesn't exist" if not -e $moly_bin_file;

#****************************************************************************
# Functions
#****************************************************************************

#Write img param
open (FILE_HANDLE, ">$dst_bin_file") or &error_handler("$dst_bin_file: open file error!");
binmode(FILE_HANDLE);
&ImgTblGen();
print FILE_HANDLE @img_tbl_buffer;
close FILE_HANDLE;

#Write Xboot DA
&ConcaFile($xboot_da_file, $dst_bin_file, 1); 
&ConcaFile($mini_bl_bin_file, $dst_bin_file, 1); 
&ConcaFile($ext_bl_bin_file, $dst_bin_file, 1); 
&ConcaFile($moly_bin_file, $dst_bin_file, 0);

print "Partial $partial_source";
if($partial_source eq "TRUE")
{
    system("/proj/wcp1sm/Guardian $net_path/$dst_bin_file");
}

#****************************************************************************
# subroutine:  Construct img param region
# input:       NA
# output:      NA
#****************************************************************************
sub ImgTblGen
{
    my ($loop, $nIndex, $crcIndex) = (0, 0, 0);
    my $da_bin_size = (-s $xboot_da_file);
    my $mini_bl_size = (-s $mini_bl_bin_file);
    my $ext_bl_size = (-s $ext_bl_bin_file);
    my $entries = '';
    
    #check file size
    if( $da_bin_size > $DA_MAX_SIZE )
    {
       die "xboot DA file should not exist $DA_MAX_SIZE";
    }
     
    if( $mini_bl_size > $BL_MAX_SIZE )
    {
       die "mini BL file should not exist $DA_MAX_SIZE";
    }
    
    if( $ext_bl_size > $BL_MAX_SIZE )
    {
       die "ext BL file should not exist $DA_MAX_SIZE";
    }
    
    #calculate binary offset
    $da_base      = $IMAGE_BIN_START;
    $mini_bl_base = ($da_base + $da_bin_size + $IMAGE_ALIGN - 1) & ~($IMAGE_ALIGN - 1);
    $ext_bl_base  = ($mini_bl_base + $mini_bl_size + $IMAGE_ALIGN - 1) & ~($IMAGE_ALIGN - 1);
    $moly_base    = ($ext_bl_base + $ext_bl_size + $IMAGE_ALIGN - 1) & ~($IMAGE_ALIGN - 1);
    
    print "da_base=$da_base, mini_bl_base=$mini_bl_base, ext_bl_base=$ext_bl_base, moly_base=$moly_base\n";

    #padding reserved head
    for ($loop=0; $loop < $IMG_TBL_ADDR_MAGIC ; $loop=$loop+1, $nIndex=$nIndex+1) {
        $img_tbl_buffer[$nIndex] = chr(0xFF);
    }
    #Write img base at magic addr
    $img_tbl_buffer[$nIndex++] = &Dec2ASCIIString($IMG_TBL_BASE_ADDR);

    #padding reserved
    for ($loop = 0; $loop < $IMG_TBL_BASE_ADDR - ($IMG_TBL_ADDR_MAGIC+4) ; $loop=$loop+1, $nIndex=$nIndex+1) {
        $img_tbl_buffer[$nIndex] = chr(0xFF);
    }

    #Write img tbl magic
    $img_tbl_buffer[$nIndex++] = &Dec2ASCIIString($IMG_TBL_MAGIC);
    
    #Write img tbl reserve
    $img_tbl_buffer[$nIndex++] = chr(0xFF);
    $img_tbl_buffer[$nIndex++] = chr(0xFF);
    
    #Write img tbl size
    $img_tbl_buffer[$nIndex++] = chr($IMG_TBL_SIZE);
    $img_tbl_buffer[$nIndex++] = chr(0x0);
    $crcIndex = $nIndex++; 
    
    #Write img tbl entry
    $img_tbl_buffer[$nIndex++] = &Dec2ASCIIString( ($IMG_TYPE_DA << 24) | ($da_base >> 8));
    $entries .= $img_tbl_buffer[$nIndex-1];
    $img_tbl_buffer[$nIndex++] = &Dec2ASCIIString( ($IMG_TYPE_MINI_BL << 24) | ($mini_bl_base >> 8));
    $entries .= $img_tbl_buffer[$nIndex-1];
    $img_tbl_buffer[$nIndex++] = &Dec2ASCIIString( ($IMG_TYPE_EXT_BL << 24) | ($ext_bl_base >> 8));
    $entries .= $img_tbl_buffer[$nIndex-1];
    $img_tbl_buffer[$nIndex++] = &Dec2ASCIIString( ($IMG_TYPE_MOLY << 24) | ($moly_base >> 8));
    $entries .= $img_tbl_buffer[$nIndex-1];

    #Write img tbl crc
    my $crc = &Crc32($entries);
    $img_tbl_buffer[$crcIndex] = &Dec2ASCIIString($crc);
    
    my $tblstr = join('', @img_tbl_buffer);
    #&PrintHex($tblstr);
    
    #padding reserved
    for ($loop = 0; $loop < $IMAGE_BIN_START - length($tblstr) ; $loop=$loop+1, $nIndex=$nIndex+1) {
        $img_tbl_buffer[$nIndex] = chr(0xFF);
    }    
}

#****************************************************************************
# subroutine:  Concatenate src file to dst file 
# input:       Src file, dst file
# output:      NA
#****************************************************************************
sub ConcaFile
{
    my ($src, $dst, $pad) = @_;
    my $b;
    my $src_bin_file_size = (-s $src);
    my $align_size;
    my $loop;
    my @padding;
    
    open (DST_FILE_HANDLE, ">>$dst") or &error_handler("$dst: open file error!");
    binmode(DST_FILE_HANDLE);
    
    open (SRC_FILE_HANDLE, "<$src")  or &error_handler("$src: open file error!");
    binmode(SRC_FILE_HANDLE);
    
    #append src file
    while(read(SRC_FILE_HANDLE, $b, 1))
    {
    	print DST_FILE_HANDLE $b;
    }    
    
    if($pad == 1)
    {
       #padding reserved
       $align_size = ($src_bin_file_size + $IMAGE_ALIGN - 1) & ~($IMAGE_ALIGN - 1);
       for ($loop = 0; $loop < $align_size - $src_bin_file_size ; $loop=$loop+1) {
           $padding[$loop] = chr(0xFF);
       }  
       print DST_FILE_HANDLE @padding;
    }
    
    close SRC_FILE_HANDLE;
    close DST_FILE_HANDLE;
}

#****************************************************************************
# subroutine:  Dec2HexASCII, without "0x" for prefix, big endian
# input:       Integer value
# output:      Hex ASCII without "0x"
#****************************************************************************
sub Dec2ASCIIString
{
    my ($dec) = @_;
    my $str = "";
    if($dec>0x00FF0000)
    {
    	$str .= chr(($dec>> 0)&0xFF);
    	$str .= chr(($dec>> 8)&0xFF);
    	$str .= chr(($dec>>16)&0xFF);
    	$str .= chr(($dec>>24)&0xFF);	
    }
    elsif($dec>0x0000FF00)
    {
    	$str .= chr($dec&0xFF);	
    	$str .= chr(($dec>> 8)&0xFF);
    	$str .= chr(($dec>>16)&0xFF);
        $str .= chr(0x00);
    }
    elsif($dec>0x000000FF)
    {
    	$str .= chr($dec&0xFF);	
    	$str .= chr(($dec>> 8)&0xFF);
        $str .= chr(0x00);
    	$str .= chr(0x00);
    }
    else
    {
    	$str .= chr($dec&0xFF);	
        $str .= chr(0x00);
    	$str .= chr(0x00);
    	$str .= chr(0x00);
    }

}

#****************************************************************************
# subroutine:  Calculate the CRC32
# input:       Input string
# output:      CRC value
#****************************************************************************
sub Crc32 {
    my ($input, $init_value, $polynomial) = @_;
    
    $init_value = 0 unless (defined $init_value);
    $polynomial = 0xedb88320 unless (defined $polynomial);
    
    my @lookup_table;
    
    for (my $i=0; $i<256; $i++) {
        my $x = $i;
        for (my $j=0; $j<8; $j++) {
            if ($x & 1) {
                $x = ($x >> 1) ^ $polynomial;
            } else {
                $x = $x >> 1;
            }
        }
        $lookup_table[$i]=$x;
    }
    
    my $crc = $init_value;
    
    foreach my $x (unpack ('C*', $input)) {
        $crc = $lookup_table[ ($crc ^ $x) & 0xff ] ^ (($crc >> 8) & 0xffffff);
    }
    
    return $crc;
}

#****************************************************************************
# subroutine:  Print string in HEX value
# input:       Input string
# output:      NA
#****************************************************************************
sub PrintHex
{
    ## Initial string
    my ($string) = @_;
    
    ## convert each character from the string into HEX code
    $string =~ s/(.)/sprintf("%02X",ord($1))/eg;
    
    print "$string\n";
}
