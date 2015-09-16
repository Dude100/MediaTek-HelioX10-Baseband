!#/usr/local/bin/perl
my @tl;
@tl= `tasklist`;
my $tl2;
my $count=0;

system "cls";

foreach $tl2 (@tl) 
{
	if ( $tl2 =~ /xgconsole|buildconsole/i )
	{
		if ($count==0)
		{
      print "Image Name                     PID Session Name        Session#    Mem Usage\n";
      print "========================= ======== ================ =========== ============\n";			
		}
		print "$tl2 \n";
		$count++;
	}	
}

if ( $count==0)
{
  print "Incredibuild running process NOT found.\n";
} elsif ( $count==1)
{
  print " $count Incredibuild running process found.\n";	
} elsif ( $count>1)
{
  print " $count Incredibuild running processes found.\n";	
}




