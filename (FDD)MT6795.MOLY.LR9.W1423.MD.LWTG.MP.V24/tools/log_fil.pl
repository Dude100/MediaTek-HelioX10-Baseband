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
#!/usr/bin/perl
# filter out the lines having PVCS Log
use File::Copy;

# Log Area Turn on Criteria:
# 1. match $log_turnon in one line and match "^ \*-{75}" in the next line, log area begin from the next line
$log_turnon     = " \* Below this line, this part is controlled by PVCS VM\. DO NOT MODIFY!!";
$log_turnon_slim = "\* Below this line, this part is controlled by PVCS VM\. DO NOT MODIFY!!";
# 2. match " * $Revision: ... $", " * $Modtime: ... $" or " * $Log: ... $", log area begin from this line

# Log Area Turn on Criteria:
# 1. match $log_turnoff and log area is before this line
$log_turnoff     = " \* Upper this line, this part is controlled by PVCS VM\. DO NOT MODIFY!!";
$log_turnoff_slim = "\* Upper this line, this part is controlled by PVCS VM\. DO NOT MODIFY!!";
# 2. match "^ \*-{75}" and $log_turnon is not in previous line
# 3. match "^ \*{15}\*+\/" and $log_turnon is not in previous line

$author_turnon      = " \* Author:";
$author_turnon_slim  = "\* Author:";

$revision_turnon     = "\; \* Revision History";
$revision_turnon_slim = "\;\* Revision History";

$revision_turnoff     = "\; \******************************";
$revision_turnoff_slim = "\;\******************************";

#
# parsing command arguments
#

my $reading;
my $line_no;
my $debug_print = 0; # 1 for debug; 0 for non-debug

if (!($ARGV[0] =~ /\.(h|c|hpp|cpp|s|java|txt|inc)$/i))
{
   &usage;
}

if ($#ARGV < 1)
{
	$TMP_FILE = "~log_fil($$).tmp";
}
else
{
	$TMP_FILE = $ARGV[1];
}

#
# open source file & result file
#
my $SRC_FILE = $ARGV[0];
my $is_exist = 0;
$is_exist = 1 if -e $SRC_FILE;
if ($is_exist == 1)
{
	open SRC_FILE_R , "+<$SRC_FILE" or die "cannot open $SRC_FILE\n";
}
else
{
	die "cannot find $SRC_FILE\n";
}

#
# search the PVCS $Log & remove them
#
$is_log_area = -1;      # -1: not in a log area
                        #  0: possibly the beginning of the area
                        #  1: in a log area

$is_author_area = -1;   # -1: not in a author area
                        #  0: possibly the beginning of the area
                        #  1: in a author area

$is_revision_area = -1;# -1: not in a author area
                        #  0: possibly the beginning of the area
                        #  1: in a author area
$line_no = 1;
my $SRC_FILE_RW;
foreach (<SRC_FILE_R>)
{
    my $read_line = $_;

    print "$line_no\t" if ($debug_print == 1);
    if (((index($read_line, $log_turnon) >=0) || (index($read_line, $log_turnon_slim) >=0)) && ($is_log_area == -1))
    {
        $SRC_FILE_RW .= $read_line;
        $is_log_area = 0;
        $turnon_line_no = $line_no;
        print "Log Area $is_log_area\n"  if ($debug_print == 1);
    }
    elsif (/^\;? ?\*-{75}/)
    {
        $SRC_FILE_RW .= $read_line;
        $is_log_area = (($is_log_area == 0) && ($line_no == $turnon_line_no+1)) ? 1 : -1;
        print "Log Area $is_log_area\n"  if ($debug_print == 1);
    }
    elsif (/^\;? ?\*{15}\*+\//)
    {
        $SRC_FILE_RW .= $read_line;
        $is_log_area = (($is_log_area == 0) && ($line_no == $turnon_line_no+1)) ? 1 : -1;
        print "Log Area $is_log_area\n"  if ($debug_print == 1);
    }
    elsif (((index($read_line, $log_turnoff) >=0) || (index($read_line, $log_turnoff_slim) >=0)) && ($is_log_area == 1))
    {
        $SRC_FILE_RW .= $read_line;
        $is_log_area = -1;
        print "Log Area $is_log_area\n"  if ($debug_print == 1);
    }
    elsif (/^(\;?) ?\* \$Revision:.*\$$/) # match " * $Revision: ... $"
    {
        ($1 eq '')? ($read_line =~ s/^ ?\* .*/ \* removed!/) : ($read_line =~ s/^\; \* .*/\; \* removed!/);
        $SRC_FILE_RW .= $read_line;
        $is_log_area = 1;
        print "Log Area $is_log_area\n"  if ($debug_print == 1);
    }
    elsif (/^(\;?) ?\* \$Modtime:.*\$$/) # match " * $Modtime: ... $"
    {
        ($1 eq '')? ($read_line =~ s/^ ?\* .*/ \* removed!/) : ($read_line =~ s/^\; \* .*/\; \* removed!/);
        $SRC_FILE_RW .= $read_line;
        $is_log_area = 1;
        print "Log Area $is_log_area\n"  if ($debug_print == 1);
    }
    elsif (/^(\;?) ?\* \$Log:.*\$$/) # match " * $Log: ... $"
    {
        ($1 eq '')? ($read_line =~ s/^ ?\* .*/ \* removed!/) : ($read_line =~ s/^\; \* .*/\; \* removed!/);
        $SRC_FILE_RW .= $read_line;
        $is_log_area = 1;
        print "Log Area $is_log_area\n"  if ($debug_print == 1);
    }
    elsif (((index($read_line, $author_turnon) >=0) || (index($read_line, $author_turnon_slim) >=0)) && ($is_author_area == -1))
    {
        $SRC_FILE_RW .= $read_line;
        $is_author_area = 0;
        print "Author on\n" if ($debug_print == 1);
    }
    elsif (((index($read_line, $revision_turnon) >= 0) || (index($read_line, $revision_turnon_slim) >= 0)) && ($is_revision_area == -1))
    {
        $SRC_FILE_RW .= $read_line;
        $is_revision_area = 0;
        print "Revision on\n" if ($debug_print == 1);
    }
    elsif (((index($read_line, $revision_turnoff) >= 0) || (index($read_line, $revision_turnoff_slim) >= 0)) && ($is_revision_area == 1))
    {
        $SRC_FILE_RW .= $read_line;
        $is_revision_area = -1;
        print "Revision Area $is_revision_area\n"  if ($debug_print == 1);
    }
    elsif (/^\;? ?\* -{6}/)
    {
        $SRC_FILE_RW .= $read_line;
        $is_author_area = ($is_author_area == 0) ? 1 : -1;
        print "Log Area $is_log_area\n"  if ($debug_print == 1);
    }
# Not remove author information from the scatter file.
#    elsif ((/^\; \* -{6}/) && ($is_author_area == 0))
#    {
#        $SRC_FILE_RW .= $read_line;
#        $is_author_area = 1;
#        print "Log Area $is_author_area\n"  if ($debug_print == 1);
#    }
    elsif ((/^\; \* -{6}/) && ($is_revision_area == 0))
    {
        $SRC_FILE_RW .= $read_line;
 #       $is_revision_area = ($is_revision_area == 0) ? 1 : -1;
        $is_revision_area = 1;
        print "Revision Area $is_revision_area\n"  if ($debug_print == 1);
    }
    else
    {
        if ($is_log_area == 1)
        {
            if ($read_line =~ /^ ?\* .*/)
            {
                $read_line =~ s/^ ?\* .*/ \* removed!/; # For C source file log removal
            }
            elsif ($read_line =~ /^\;.*/)
            {
                $read_line =~ s/^\;.*/\; \* removed!/; # For assembly language source file log removal
            }
            $SRC_FILE_RW .= $read_line;
            print "log removed\n" if ($debug_print == 1);
        }
        elsif ($is_author_area == 1)
        {
            if ($read_line =~ /^ ?\*\s+\S+/)
            {
                $read_line =~ s/^ ?\*.*/ \* -------/; 
            } 
            elsif ($read_line =~ /^\; \*?\s+\S+/)
            {
                if ($SRC_FILE =~ /scat\w+\.txt/i)
                {
                    $read_line =~ s/^\; \*.*/\; \* -------/; # For scatter file author removal
                    $is_author_area = -1;
                }
                else
                {
                    $read_line =~ s/^\; \*.*/\; \* -------/; # For assembly language source file author removal
                }
            }
            else
            {
                $is_author_area = -1;
            }
            $SRC_FILE_RW .= $read_line;
            print "author removed\n" if ($debug_print == 1);
        }
        elsif ($is_revision_area == 1)
        {
            $read_line =~ s/^\; \* .*/\; \* removed!/; # For scatter file revision history removal
            $SRC_FILE_RW .= $read_line;
            $is_revision_area = 1;
            print "Revision removed\n" if ($debug_print == 1);
        }
        else
        {
            if (($read_line =~ /^ ?\* \S{3} \d{1,2} \d{4} \S{8}/) || ($read_line =~ /^ ?\* \d{1,2} \d{1,2} \d{4} \S{8}/) ||($read_line =~ /^ ?\* \[MAUI_\d{8}\]/) || ($read_line =~ /^ ?\* \[MOLY_\d{8}\]/)|| ($read_line =~ /^ ?\* \[MOLY0\d{7}\]/)) {
                $read_line =~ s/^ ?\* .*/ \* removed!/; # For C source file revision history removal
            }
            elsif (($read_line =~ /^\; \* \S{3} \d{1,2} \d{4} \S{8}/) || ($read_line =~ /^\; \* \d{1,2} \d{1,2} \d{4} \S{8}/) || ($read_line =~ /^\; \* \[MAUI_\d{8}\]/) || ($read_line =~ /^ ?\* \[MOLY_\d{8}\]/)|| ($read_line =~ /^ ?\* \[MOLY0\d{7}\]/)) {
                $read_line =~ s/^\; \* .*/\; \* removed!/; # For assembly language source file revision history removal
            }
            $SRC_FILE_RW .= $read_line;

            print "remained\n" if ($debug_print == 1);
        }
    }
    $line_no ++;
    if ( ( ($is_log_area != -1)||($is_author_area != -1) ) && ($line_no > 150) )
    {
        #system "echo Possible ERROR in line $SRC_FILE $line_no [$is_log_area,$is_author_area]!! >> fil.log";
        #exit(0);
    }
} # foreach (<SRC_FILE_R>) of parsing directives: #if, #ifdef, #ifndef, #endif, #else, #elif

if ($TMP_FILE eq $SRC_FILE)
{
	# clear all file content
	truncate(SRC_FILE_R, 0);
	seek(SRC_FILE_R, 0, 0);
	print SRC_FILE_R $SRC_FILE_RW;
	close SRC_FILE_R;
}
else
{
	close SRC_FILE_R;
	open SRC_FILE_RW, ">$TMP_FILE" or die "cannot write $TMP_FILE\n";
	print SRC_FILE_RW $SRC_FILE_RW;
	close SRC_FILE_RW;
	move("$TMP_FILE","$SRC_FILE") or move("$TMP_FILE","$SRC_FILE") or die "Error: log_fil can not move cover file, please check it is read only or not $SRC_FILE\n";
}
exit 0;


# show usage
sub usage
{
	print "USAGE: perl log_fil.pl <source file> <tmpfile>\n";
	exit(1);
}
