#!/usr/local/bin/perl
#use strict;

my $filename;
my $argc = @ARGV;
if($argc < 1 || $argc > 4)
{
    print "Error: Please give correct arguments...\nMarginCal.pl LIS_FILE_PATH ROM_SIZE RAM_DEDUCTION (output_tag)\n";
    exit 1;
}
my $filename = @ARGV[0];
my $ROM_size = @ARGV[1];
my $RAM_deduction = @ARGV[2];
my $output_tag = @ARGV[3];
#print "argc=$argc\n";
if ($argc ==1)
{
	$ROM_size = 0;
	$RAM_deduction = 0;
}
elsif ($argc == 2)
{
	$RAM_deduction = 0;
}
elsif ($argc == 4)
{
	print "\<$output_tag\>\n";
}

my ($dev, $ino, $mode, $nlink, $uid, $gid, $rdev, $size, $atime, $mtime, $ctime, $blksize, $blocks) = stat($filename);
open FILE, "<$filename" or die "$!";
seek FILE, $size-30*1024*1024, 0;
my $previous_base;
my $previous_size;
my $current_base;
my $current_size;
my $ram_margin_calculated = 0;
$real_filename = substr($filename, rindex($filename, '\\')+1);
print "In $real_filename:\n";
while (<FILE>)
{
    my $data = $_;
    if($ram_margin_calculated == 0 && $data =~ m/.*Execution Region (.*) .*Base: (\w+).*Size: (\w+)/)
    {
        $previous_base = $current_base;
        $previous_size = $current_size;
        $current_base = $2;
        $current_size = $3;
        
        if($1 =~ /CACHED_DUMMY_END/)
        {
            #print "previous_base: $previous_base\n";
            #print "previous_size: $previous_size\n";
            #print "current_base: $current_base\n";
            #print "current_size: $current_size\n";
            my $ret = (hex $current_base) - (hex $previous_base) - (hex $previous_size);
            $margin = $ret - ($RAM_deduction*1024*1024);
            my $margin_inK = sprintf("%0.2f", $margin/1024);
            my $margin_inM = sprintf("%0.2f", $margin/1024/1024);
            print "RAM Margin: $margin($margin_inK KB/ $margin_inM MB)\n";
            $ram_margin_calculated = 1;
        }
    }
    elsif($ram_margin_calculated == 1 && $data =~ m/.*Total ROM Size \(Code \+ RO Data \+ RW Data\) *(\d+)/)
    {
        my $ret = $1;
        $ret = ($ROM_size*1024*1024) - $ret; 
        my $ret_inK = sprintf("%0.2f", $ret/1024);
        my $ret_inM = sprintf("%0.2f", $ret/1024/1024);
		my $rom_usage = $1;
		my $rom_usage_inK = sprintf("%0.2f", $rom_usage/1024);
        my $rom_usage_inM = sprintf("%0.2f", $rom_usage/1024/1024);
        print "ROM Usage: $rom_usage($rom_usage_inK KB/ $rom_usage_inM MB)\n";
        if($ROM_size >0)
        {
        	print "ROM Margin: $ret($ret_inK KB/ $ret_inM MB)\n";
        }
        Last;
    }
}
close FILE;
print "Done!\n";