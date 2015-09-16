my @argv = @ARGV;
#print "argv:@argv";
($#argv < 0) && &Usage;

while(<@argv>)
{
	if (/(\w+?)]/i)
	{
		if($1 >= 794)
		{
			$para1=$1;
			print "GEQ794";
#			return $para1;
		}
		else
		{
			$para1=$1;
			print "LSS794";
#			return $para1;
		}
	}
}


sub Usage
{
	print "\nUsage:\n perl Armversion.pl <armlinkinfo> \n";
	print "\nDescription:\n";
	print "   <file> = armlink_info in option.mak n";
	print "Example:\n";
	print " perl Armversion.pl armlink_info\n";
	exit 1;
}