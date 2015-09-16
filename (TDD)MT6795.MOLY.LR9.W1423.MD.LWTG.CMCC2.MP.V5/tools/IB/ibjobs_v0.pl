!#/usr/local/bin/perl
my @tl;

my $tl2;
my $count=0;

@tl= `qprocess xgconsole.exe`;

foreach $tl2 (@tl) 
{
	if ( $tl2 =~ /xgconsole/i )
	{
		if ($count==0)
		{
			 print"USERNAME              SESSIONNAME         ID    PID  IMAGE\n";
		}
		print "$tl2 \n";
		$count++;
		
	}	
}


@tl= `qprocess buildconsole.exe`;

$tl2="";


foreach $tl2 (@tl) 
{
	if ( $tl2 =~ /buildconsole/i )
	{
		if ($count==0)
		{
			 print"USERNAME              SESSIONNAME         ID    PID  IMAGE\n";			
		}
	  print "$tl2 \n";
		$count++;
		
	}
}




if ( $count==0)
{
  print "\nIncredibuild running process NOT found.\n";
} elsif ( $count==1)
{
  print "\n $count Incredibuild running process found.\n";	
} elsif ( $count>1)
{
  print "\n $count Incredibuild running processes found.\n";	
}
