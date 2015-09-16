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

use strict;
use warnings;
use tools::mbis;

#*****************************************************************************
#              Global Variable Declaration and Initialization
#*****************************************************************************
our $argv_count;
our $command;
our $info;
our $argv;
our $folder;

# get -s|-t|-i|-o|-e|-c
$argv = shift(@ARGV);

# get the arguments number
$argv_count = @ARGV;


if ($argv =~ /^-s$/i && $argv_count >= 1){
    &mbisLogCommand(1,@ARGV);
}
elsif ($argv =~ /^-t$/i && $argv_count == 1){
    $info = shift(@ARGV);
    &mbisLogTimeStamp(1,$info);
}
elsif ($argv =~ /^-i$/i && $argv_count == 1){
    $info = shift(@ARGV);
    &mbisLogInfo(1,$info);
}
elsif ($argv =~ /^-o$/i && $argv_count == 1){
    $folder = shift(@ARGV);
    &mergeLogFile(1,$folder);
}
elsif ($argv =~ /^-e$/i && $argv_count == 0){
    &mbisPostProcess(1);
}
elsif ($argv =~ /^-c$/i && $argv_count == 0){
    &writeTimeLogFromTempfile(1);
}
else{
    &usage;
}



sub usage{
    warn << "__END_OF_USAGE";

Usage:
    mbis.pl [-s|-i|-t|-o|-e|-c] \@argvs

Description:
    -s \@argv :
        log the original command and arguments into mbis info MBIS_BUILD_INFO_LOG.
    -i $info           :
        log the info message into MBIS_BUILD_INFO_LOG.
    -t $info           :
        log the info message and timestamp into MBIS_BUILD_TIME_TMP.
    -o $folder         :
        merge the content of all the *.mbis files $folder into MBIS_BUILD_TIME_TMP.
    -e                 :
        rewrite MBIS_BUILD_INFO_LOG and MBIS_BUILD_TIME_LOG and add mbis process time info.
    -c                 :
        calculate the time duration in MBIS_BUILD_TIME_TMP and rewrite into MBIS_BUILD_TIME_LOG file.

__END_OF_USAGE

  exit 1;
}