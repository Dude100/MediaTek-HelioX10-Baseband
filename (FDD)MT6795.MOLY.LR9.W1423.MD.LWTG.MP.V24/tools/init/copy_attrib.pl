use strict;
use Time::HiRes qw(stat);

my $input = $ARGV[0];
my $output = $ARGV[1];

if (! -e $input)
{
	die "Fail to find input: $input";
}
elsif(! -e $output)
{
	die "Fail to find output: $output";
}

my @st_in = stat($input);
if (@st_in)
{
	my $permit = $st_in[2] & 07777;
	my $atime = int($st_in[8]);
	if ($st_in[8] > $atime)
	{
		$atime += 1;
	}
	my $mtime = int($st_in[9]);
	if ($st_in[9] > $mtime)
	{
		$mtime += 1;
	}
	chmod($permit, $output);
	utime($atime, $mtime, $output);
}

