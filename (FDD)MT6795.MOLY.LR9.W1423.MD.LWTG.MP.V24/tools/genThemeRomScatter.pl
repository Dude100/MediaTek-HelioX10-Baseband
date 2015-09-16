#!/usr/bin/perl
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2008
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
# To process CustImgNamesExt and put image information to ExtractObj.ini.
#******************************************************************************
# Subroutine: Usage
#******************************************************************************
sub usage {
  print "perl genThemeRomScatter.pl LIS_FILE ThemeRom_scatter.txt ~Theme_ROM.tmp\n";
  exit 1;
}

$lisfile = $ARGV[0];
shift(@ARGV);
$Scatter = $ARGV[0];
shift(@ARGV);
$LinkConfig = $ARGV[0];
shift(@ARGV);
$custPackDir = $ARGV[0];
shift(@ARGV);
$theme_rom_folder = $ARGV[0];
shift(@ARGV);
$custthemeres = $ARGV[0];
shift(@ARGV);
$empty_res = $ARGV[0];
shift(@ARGV);
@linkerOption = @ARGV;
$CustPackResPreambleExist = 0;
$addressNum = 0;

# Process lisfile to get mtk_theme_header address
# mtk_theme_header is from plutommi\customer\custResource\themres.c

open (LIS,"<$lisfile") || die "Cannot open LIS file $lisfile:$!\n";
while ($read_line = <LIS>) {
  if ($read_line =~ /\s*custpack2ndJumpTbl\s+(0x\S+)\s*Data\s*(\d+)/){
    $CustPackResPreamble = hex($1);
    $CustPackResPreambleLen = $2;
    $CustPackResPreambleExist = 1;
    $startaddress = $CustPackResPreamble + $CustPackResPreambleLen;#4 Byte
    last;
  }
}
($CustPackResPreambleExist == 1) or die "CustPackResPreamble address does NOT exist!";
close(LIS);

#THEME_ROM 0x01aab108
#{    
#    THEME_ROM 0x01aab108 FIXED //fixed address from 1st build LIS file
#    {
#         themeRes.obj (RESOURCE_1ST_CONTENT, +First)
#         themeRes.obj (+RO)
#    }
#}

#THEME_OTHERS +0x0
#{
#        THEME_OTHERS    +0x0
#        {
#             *.obj  (+RO)
#             *.obj  (+RW, +ZI)
#        }
#}


open (FILE,">$Scatter") || die "Cannot open output scatter file:$!\n";
print FILE "THEME_ROM ".sprintf("0x%08X", $startaddress)."\n";
print FILE "{\n";
print FILE "    THEME_ROM ".sprintf("0x%08X", $startaddress)." FIXED\n";
print FILE "    {\n";
print FILE "         themeRes\.obj \(RESOURCE_1ST_CONTENT, +First\)\n";
print FILE "         themeRes.obj (+RO)\n";
print FILE "    }\n";
print FILE "}\n\n";
print FILE "THEME_OTHERS +0x0\n";
print FILE "{\n";
print FILE "    THEME_OTHERS    +0x0\n";
print FILE "    \{\n";
print FILE "         \*.obj  \(+RO\)\n";
print FILE "         \*.obj  \(+RW\, +ZI\)\n";
print FILE "    \}\n";
print FILE "\}\n";
close(FILE);
   
# Generate link config file
open (FILE,">$LinkConfig") || die "Cannot open the linker config file:$!\n";
print FILE "@linkerOption -scatter $Scatter -output $custPackDir\\THEME_ROM.elf -symdefs $custPackDir\\THEME_ROM.sym -list $custPackDir\\THEME_ROM.lis\n";
close(FILE);

