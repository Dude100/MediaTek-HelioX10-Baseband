use strict;

my $backup = $/;
undef $/;
my $input = <>;
$/ = $backup;

my @text = split(/[\n\r]+/, $input);
my $flag_7z = 0;
foreach my $line (@text)
{
	next if ($line eq "");
	if (($line =~ /^\s*7-Zip/i) || ($line =~ /^\s*Listing archive/i))
	{
		$flag_7z = 1;
		next;
	}
	if ($flag_7z)
	{
		if ($line =~ /^\s*(\S+)\s+(\S+)\s+(\S+)\s+(\d+)\s+(\d+)\s+(.+)\s*$/)
		{
			$line = $6;
		}
		else
		{
			next;
		}
	}
	$line =~ s/\\/\//g;
	next if ($line =~ /\/$/);
	next if (-d $line);
	$line =~ s/ /\\?/g;
	$line =~ s/\#/\\\\\\#/g;
	print $line . "\n";
}
