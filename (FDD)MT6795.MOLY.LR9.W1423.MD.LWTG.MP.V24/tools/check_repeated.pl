#!/usr/local/bin/perl


my $count;
my $repeated=0;


my @in_var = @ARGV;

my @new_var;

	foreach $a  (@in_var)
	{
		 $count =0;
		 #print "var_a=$a \n";
		 		 
		 foreach $b  (@in_var)
		 {
		 	 if ( "$a" eq "$b" )
		 	 {
		 	   $count++;	
		 	   
		   }
		 }	
		 
	 	 if ($count==0)
	 	 {

 	 	 } elsif ( $count > 1)
		 {
		 	 print "$a repeated $count times ! \n";

		 	 $repeated++;
		 } 
		 
	}	

exit $repeated;




