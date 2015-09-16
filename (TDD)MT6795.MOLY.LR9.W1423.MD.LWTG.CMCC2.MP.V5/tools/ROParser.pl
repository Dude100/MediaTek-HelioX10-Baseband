#*--------------------------------------------------------------------------*
#* Global variables
#*--------------------------------------------------------------------------*
my $LISFILE      = $ARGV[0];
my $rootdir = @ARGV[1];
my $mcudir = @ARGV[2];
my $branch = @ARGV[3];
my @filearray;
my @disarray;
my @unusedroarray;
my @resultarray;
my @symbolarray;
my $printmode = "dec";
my $outputfilename;
my $unusedfilename;
#*--------------------------------------------------------------------------*
#* Code Body
#*--------------------------------------------------------------------------*

$initialtime = time();

warn "
==============================================================================
 [Program]    ROParser.pl
 [Version]    V3.0
 [Date]       2008-04-09
 [Author]     yikuan.huang\@mediatek.com
 [Copyright]  Copyright (C) 2008 MediaTek Incorporation. All Rights Reserved.
==============================================================================
";

unless(defined($branch)){
	usage();
}
startview($branch);
determinefilename();
print "start to parse LIS file......\n";
parselisfile();
print "finish parsing LIS file......\n";

print "start to disassemble...\n";
traversefile($rootdir);
disassemble();
print "finish disassembling!\n";

print "start to get unusedRO...\n";
getunusedRO();
print "finish getting unusedRO...\n";

print "start to parse dis file...\n";
parsedisfile();
print "finish parsing dis file...\n";

print "start to dump resule to files...\n";
dump_resulte_to_file();
print "finish dumping resule to files!\n";

$finishtime = time(); 
$exectime = $finishtime - $initialtime;
print "Total execution time: ".$exectime." seconds\n";



#****************************************************************************
# FUNCTION
#  determinefilename
# DESCRIPTION
#  This function determine the name of output file
#****************************************************************************
sub determinefilename{
    @filepart = split /\\/,$LISFILE;
	$outputfilename = $filepart[-1];
	$unusedfilename  = $filepart[-1];
	if($filepart[-1] =~ /(\S+)lis/){
		$outputfilename = $1;
	}
	$unusedfilename = $outputfilename;
	$outputfilename = $outputfilename."txt";
	$unusedfilename =~ s/\.//;
	$unusedfilename = $unusedfilename."unusedRO.txt";
}
#****************************************************************************
# FUNCTION
#  parselisfile
# DESCRIPTION
#  This function parse LIS file
#****************************************************************************
sub parselisfile{
#****************************************************************************
# Parse LIS file content
#****************************************************************************
my (@ref_obj, @ref_func, @dec_obj, @dec_region, @content , @symbol);	# referencing obj, referencing function, declaration obj, declaraion region, referenced content
my ($i, $ref_count ,$j, $switch);

die "$LISFILE does not exist!\n" if (!-e $LISFILE);


open (FILE_HANDLE, "<$LISFILE") or die "Fail to open $LISFILE\n";
$i = 0;
$j = 0;
$switch = 0;
while (<FILE_HANDLE>) {
	if (/(\S+)\((\S+)\)\srefers\sto\s(\S+)\((\S+)\)\sfor\s(\S+)\s*/) {	# AAA.obj(i.func/pragma) refers to BBB.obj(i.func/pragma/region) for content
		$ref_obj[$i] = $1;		# AAA
		$ref_func[$i] = $2;		# i.func/pragma
		$dec_obj[$i] = $3;		# BBB
		$dec_region[$i] = $4;	# i.func/pragma/region
		$content[$i] = $5;		# content
		$i++;									# should be indexed with the same $i
	}
	if (/Local Symbols/){
		$switch = 1;
	}
	if (/================================================================================/){
		$switch = 0;
	}
	if ($switch == 1){
		$_ = trim($_);
		if(/(\S+)(\s*)(\S+)(\s*)(\S+)(\s*)(\S+)(\s*)(\S+)/){
			$symbol[$j] = $1;
			$j++;
		}
	}
}
$ref_count = $i;
close FILE_HANDLE or die "Fail to close $LISFILE\n";

@symbol = reverse sort @symbol;

#****************************************************************************
# Further parse the reference table to find constdata
#****************************************************************************
my $ref_data;
my %constdata;
$i = 0;
foreach $ref_data (@content) {
	if ($ref_data eq ".constdata\$1") {	# AAA.obj(i.func/pragma) refers to BBB.obj(i.func/pragma/region) for .constdata$1
		$constdata{$i} = $ref_data;				# constdata{$i} = .constdata$1, $i is the index of constdata references
	}
	$i++;
}


#****************************************************************************
# Find unused RO data
#****************************************************************************
my (%unused_RO_func, %unused_RO_pragma);

$i = 0;
while ($i < $ref_count) {
	if (defined $constdata{$i}) {
		my $is_In_Symbol_Table = 0;
		my $funcname = $ref_func[$i];
		foreach (@symbol){
			my $tablefuncname = $_;
			if($funcname eq $tablefuncname){
				$is_In_Symbol_Table = 1;
				last;
			}
			if($funcname gt $tablefuncname){
				$is_In_Symbol_Table = 0;
				last;
			}
		}
		if ($is_In_Symbol_Table == 0) {
			if ($ref_func[$i] =~ /i.(\S+)/) {	# function case
				$unused_RO_func{$ref_func[$i]} = $ref_obj[$i];
			}
			else{
				$unused_RO_pragma{$ref_func[$i]} = $ref_obj[$i];
			}
			#print $ref_func[$i]."...".$ref_obj[$i]."\n";
		}
	}
	$i++;
}

#****************************************************************************
# Output unreferenced functions that contain unused RO data
#****************************************************************************
open (FILE_HANDLE, ">$unusedfilename") or die "Fail to open $unusedfilename\n";
my $ref_data;
print FILE_HANDLE "Unreferenced functions that contain unused RO data: \n";
foreach $ref_data (sort {$unused_RO_func{$a} cmp $unused_RO_func{$b}} keys %unused_RO_func) {
	print FILE_HANDLE "$ref_data ($unused_RO_func{$ref_data})\n";
}

print FILE_HANDLE "\nOther pragmas that contains unreferenced functions with RO data: \n";
foreach $ref_data (sort {$unused_RO_pragma{$a} cmp $unused_RO_pragma{$b}} keys %unused_RO_pragma) {
	print FILE_HANDLE "$ref_data ($unused_RO_pragma{$ref_data})\n";
}

close FILE_HANDLE or die "Fail to close output.txt\n";


}



#****************************************************************************
# FUNCTION
#  dump_resulte_to_file
# DESCRIPTION
#  This function dumps the result of RO parser to file(result.txt)
#****************************************************************************
sub dump_resulte_to_file{
	#*--------------------------------------------------------------------------*
	#* Local variables
	#*--------------------------------------------------------------------------*
	$resultfuncname;
	$resultobjname;
    $resultconstantstring;
	$resultstringsize;
	$resultconstantdata;
	$resultdatasize;
	$resultfilepath;
	$resultowner;
	#*--------------------------------------------------------------------------*
	#* Code Body
	#*--------------------------------------------------------------------------*
	%ownerhash;
	open(RESULT,">$outputfilename") || die "File open error!\n";
	# Set the data format
format RESULT =
  @<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< @<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  @<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< @<<<<<<<<<< @<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< @<<<<<<<<<< @<<<<<<<<<<
  $resultfuncname,$resultobjname,$resultconstantstring,$resultstringsize,$resultconstantdata,$resultdatasize,$resultowner
.
	foreach (@resultarray){
		my $resulthash = $_;
		$resultfuncname = $resulthash->{"funcname"};
		$resultobjname = $resulthash->{"objname"};
		$resultconstantstring = $resulthash->{"constantstring"};
		$resultstringsize = $resulthash->{"stringsize"};
		$resultconstantdata = $resulthash->{"constantdata"};
		$resultdatasize = $resulthash->{"datasize"};
		$resultfilepath = get_objpath_by_objname($resultobjname);
		if(defined $ownerhash{$resultfilepath}){
			
		}
		else{
			$ownerhash{$resultfilepath} = getOwner($resultfilepath);
		}
		$resultowner = $ownerhash{$resultfilepath};
		if($printmode eq "dec"){
			if($resultstringsize =~ /0x(\w+)/){
				$resultstringsize = hex($1);
			}
			if($resultdatasize =~ /0x(\w+)/){
				$resultdatasize = hex($1);
			}
		}
		#print $resultfuncname." ".$resultobjname." ".$resultconstantstring." ".$resultstringsize." ".$resultconstantdata." ".$resultdatasize."\n";
		write(RESULT);
	}	
	close(RESULT);
	
	#delete unusedRO file
	#unlink($unusedfilename);
}

#****************************************************************************
# FUNCTION
#  check_global_table
# DESCRIPTION
#  This function check whether the offset is in the global symbol table
#****************************************************************************
sub check_global_table(){
	$_ = $_[0];
	s/0x//;
	my $offset = hex($_);
	my $objname = $_[1];
	my $result = "0";
	#print $offset." ... ".$objname."\n";
	foreach (@symbolarray){
		my $symbolhash = $_;
		$symbolojbname = $symbolhash->{"objname"};
		$symbolname = $symbolhash->{"symbolname"};
		$symbolvalue = $symbolhash->{"symbolvalue"};
		$symbolsize = $symbolhash->{"symbolsize"};
		$symbolstart = $symbolhash->{"symbolstart"};
		$symbolend = $symbolhash->{"symbolend"};
		if($symbolojbname eq $objname){
			if(($offset>=$symbolstart) && ( $offset<$symbolend)){
				$result = $symbolname.":".$symbolsize;
				last;
			}
		}
	}
	return $result;
}


#****************************************************************************
# FUNCTION
#  parsedisfile
# DESCRIPTION 
#  This function parse the dis file which appears in @unusedroarray , and create the result
#****************************************************************************
sub parsedisfile(){
	#*--------------------------------------------------------------------------*
	#* Code Body
	#*--------------------------------------------------------------------------*
	foreach	(@unusedroarray){		
		my $gethash = $_;
		my $getobjname = $gethash->{"objname"};
		my $getfuncname = $gethash->{"funcname"};
		my $getdisfilepath = $gethash->{"disfilepath"};
		my $firstaddress;
		my $offset;
		my $constdatasecnum;
		if(defined($getdisfilepath)){
			@symbolarray = ();
			open(FILE,"<$getdisfilepath") || die "File open error - $getdisfilepath!\n";
			@data = <FILE>;
		  	my $funcswitch = 0;
		  	my $getoffset = 0;
		  	my $findconstdatasec = 0;
		  	my $constdataswitch = 0;
		  	my $hasvalue = 0;

		  	
		  	my $thisoffset;
		  	my $targetoffset;
		  	
		  	my $hasequal = 0;

		  	my @blockarray;
		  	my @indexarray;
		  	my @firstaddressarray;
		  	my $index = 0;
		  	my $targetindex = 0;
		  	my $maxlength = 16;
		  	
		  	my $hasglobal = 0;
			
			#&parse_for_global_symbol_table(@data);
			my $currentsecnum;		#store section number temporarily
			my @secnum; 			#store section number in one dis file
		#****************************************************************************
		# 1 >>> First round : scan the dis file, and get all the section number which has .constdata
		# For example,  ** Section #10
		#
    	#			Name        : .constdata
		# We find the ".constdata", and get it's previous section number - 10
		# Store all the section number into @secnum
		#****************************************************************************
		foreach(@data){
	  		# Find each section number, and record it in the $currentsecnum
	  		if($_ =~ /\*\* Section #(\d+)/){
	  			$currentsecnum = $1;
	  		}
	  		# Find the .constdata, record the previous section number into @secnum 
	  		if(index($_,"Name        : .constdata")>=0){
	  			push @secnum, $currentsecnum;
	  		}	
	  	}
	  	
	  	#****************************************************************************
		# 2 >>> Second round : scan the dis file, get the data row from the symbol table
		# For example,
		# Symbol table .symtab (121 symbols, 112 local)
      	#  Symbol Name                Value      Bind  Sec  Type  Size
    	# ========================================================================
      	# 1  $t                         0x00000000   Lc    5  Code
      	# ................................
      	# ========================================================================
      	# 
      	# We find "Symbol table" first, and record the data between two "=======" lines
      	#****************************************************************************
	  	$isSym = 0;	
	   	$switch = 0;
	   	
	  	foreach(@data){
	  		# Find the symbol table 
	  		if(index($_,"Symbol table .symtab")>=0){
	  				$isSym = 1;
	  				next;
	  		}
	  		if((index($_,"=================")>=0)&&($isSym eq 1)){
	  				$switch = 1;
	  				$isSym = 0;
	  				next;
	  		}
	  		if((index($_,"==================")>=0)&&($isSym eq 0)){
	  			$switch = 0;
	  			next;
	  		}
	  		if($switch eq 1){
	  			my %symbolhash;
	  			#if it has 7 values
	  			if(/\s+(\S+)\s+(\S+)\s+(\S+)\s+(\S+)\s+(\S+)\s+(\S+)\s+(\S+)/){
	  				#print $1."\n".$2."\n".$3."\n".$4."\n".$5."\n".$6."\n".$7."\n";
	  				#print "\n";
	  				if(matchsecnum($5,@secnum) eq 1){
		  				%symbolhash ={};
						$symbolhash{"objname"}= $getobjname;
						$symbolhash{"symbolname"}= $2;
						$symbolhash{"symbolvalue"}= $3;
						$symbolhash{"symbolsize"}= $7;
						if(index($symbolhash{"symbolsize"},"0x")>=0){
								$_ = $symbolhash{"symbolvalue"};
								s/0x//;
								$symbolhash{"symbolstart"} = hex($_);
								$_ = $symbolhash{"symbolsize"};
								s/0x//;
								$symbolhash{"symbolend"} = $symbolhash{"symbolstart"} + hex($_);
							push @symbolarray, \%symbolhash;
						}
	  				}
	  				next;
	  			}
	  			#if it has 6 values
	  			elsif(/\s+(\S+)\s+(\S+)\s+(\S+)\s+(\S+)\s+(\S+)\s+(\S+)/){
	  				#print $1."\n".$2."\n".$3."\n".$4."\n".$5."\n".$6."\n";
	  				#print "\n";
	  				if(matchsecnum($5,@secnum) eq 1){
		  				%symbolhash ={};
						$symbolhash{"objname"}= $getobjname;
						$symbolhash{"symbolname"}= $2;
						$symbolhash{"symbolvalue"}= $3;
	  				}
	  				next;
	  			}
	  			
	  			# across two line!!
	  			else{
	  				# second line: 5 values
	  				if(/\s+(\S+)\s+(\S+)\s+(\S+)\s+(\S+)\s+(\S+)/){
	  					#print $1."\n".$2."\n".$3."\n".$4."\n".$5."\n";
						if(matchsecnum($3,@secnum) eq 1){
							$symbolhash{"objname"}= $getobjname;
							$symbolhash{"symbolvalue"}= $1;
							$symbolhash{"symbolsize"}= $5;
							if(index($symbolhash{"symbolsize"},"0x")>=0){
								$_ = $symbolhash{"symbolvalue"};
								s/0x//;
								$symbolhash{"symbolstart"} = hex($_);
								$_ = $symbolhash{"symbolsize"};
								s/0x//;
								$symbolhash{"symbolend"} = $symbolhash{"symbolstart"} + hex($_);
								push @symbolarray, \%symbolhash;
							}
							%symbolhash ={};
						}
	  					next;
	  				}
	  				# second line: 4 values
	  				if(/\s+(\S+)\s+(\S+)\s+(\S+)\s+(\S+)/){
	  					#print $1."\n".$2."\n".$3."\n".$4."\n";
	  					if(matchsecnum($3,@secnum) eq 1){
		  					$symbolhash{"objname"}= $getobjname;
							$symbolhash{"symbolvalue"}= $1;	
							if(index($symbolhash{"symbolsize"},"0x")>=0){
			  					$_ = $symbolhash{"symbolvalue"};
								s/0x//;
								$symbolhash{"symbolstart"} = hex($_);
								$_ = $symbolhash{"symbolsize"};
								s/0x//;
								$symbolhash{"symbolend"} = $symbolhash{"symbolstart"} + hex($_);
		  						push @symbolarray, \%symbolhash;
							}
		  					%symbolhash ={};
	  					}
	  					next;
	  				}
	  				# first line: 2 values
	  				if(/\s+(\S+)\s+(\S+)/){
	  					#print $1."\n".$2."\n";
	  					$symbolhash{"symbolname"}= $2;
	  					next
	  				}
	  			}
	  		}

	  	}
				

						
		  	foreach(@data){
		  		# open the section
		  		if($_ =~ /Name        : i.$getfuncname\n/){
		  			$funcswitch = 1;
		  			$findconstdatasec = 1;
		  			next;
		  		}
		  		if($_ =~ /Name        : $getfuncname\n/){
		  			$funcswitch = 1;
		  			$findconstdatasec = 1;
		  			next;
		  		}
		  		
		  		if(($funcswitch == 1)&&($_ =~ /.constdata$1/)){
		  				# if the address has 4 digits
		  				$isExist = "false";
		  				if($_ =~ /= 0x(\w\w\w\w)]/){
		  					$firstaddress = $1;
		  					foreach $address(@firstaddressarray){
		  						if($address eq $firstaddress){
		  							$isExist = "true";
		  						}
		  					}
		  					if($isExist eq "false"){
		  						push @firstaddressarray, $firstaddress;
		  					}
		  					next;
		  				}
		  				# if the address has 3 digits
		  				if($_ =~ /= 0x(\w\w\w)]/){
		  					$firstaddress = $1;
		  					foreach $address(@firstaddressarray){
		  						if($address eq $firstaddress){
		  							$isExist = "true";
		  						}
		  					}
		  					if($isExist eq "false"){
		  						push @firstaddressarray, $firstaddress;
		  					}
		  					next;
		  				}
		  				# if the address has 2 digits
		  				if($_ =~ /= 0x(\w\w)]/){
		  					$firstaddress = $1;
		  					foreach $address(@firstaddressarray){
		  						if($address eq $firstaddress){
		  							$isExist = "true";
		  						}
		  					}
		  					if($isExist eq "false"){
		  						push @firstaddressarray, $firstaddress;
		  					}
		  					next;
		  				}
		  				# if the address has 1 digits
		  				if($_ =~ /= 0x(\w)]/){
		  					$firstaddress = $1;
		  					foreach $address(@firstaddressarray){
		  						if($address eq $firstaddress){
		  							$isExist = "true";
		  						}
		  					}
		  					if($isExist eq "false"){
		  						push @firstaddressarray, $firstaddress;
		  					}
		  					next;
		  				}
		  		}
		  		# close the section
		  		if(($funcswitch == 1)&&index($_,"====================================") >= 0){
		  			$funcswitch = 0;
		  		}
		  	}


#print $getdisfilepath."\n";
#print @firstaddressarray."\n";
foreach(@firstaddressarray){
	$firstaddress = $_;
	$stringlength = 0;
	$stringresult = "";
		  	foreach(@data){
		  		# open the section
		  		if($_ =~ /Name        : i.$getfuncname\n/){
		  			$funcswitch = 1;
		  			$findconstdatasec = 1;
		  			next;
		  		}
		  		if($_ =~ /Name        : $getfuncname\n/){
		  			$funcswitch = 1;
		  			$findconstdatasec = 1;
		  			next;
		  		} 		
		  		if(($funcswitch == 1)&&($firstaddress ne "")&&($_ =~ /0x0+$firstaddress:/)){
					my @linearray = split;
					if($linearray[1] =~ /00(\S+)/){
						$offset = "0x".$1;
						$getoffset = 1;
						# check whether the offset is in the global symbol table
							$returndata = &check_global_table($offset,$getobjname);
	
							unless($returndata eq "0"){
								my %resulthash ={};
			    				$resulthash{"funcname"}= $getfuncname;
							    $resulthash{"objname"}= $getobjname;
							    if($returndata =~ /(\S+):(\S+)/){
							    	$resulthash{"constantdata"} = $1;
							    	$resulthash{"datasize"}= $2;
							    }
							    push @resultarray, \%resulthash;
							    $hasglobal = 1;
								last;
							}
						next;
					}
				}
				# close the section
		  		if(($funcswitch == 1)&&index($_,"====================================") >= 0){
		  			$funcswitch = 0;
		  		}
		  		
		  		# find the section number of .constdata
		  		if(($findconstdatasec == 1)&&(index($_,".constdata$1")>=0)){
		  			if(/#(\d+) '.constdata'/){
		  				$constdatasecnum = $1;
		  				$findconstdatasec = 0;
		  				next;
		  			}
		  			
		  		}
		  	    # find .constdata block
		  		if(($getoffset==1)&&($_ =~ /\*\* Section #${constdatasecnum}$/)){
		  			$constdataswitch = 1;
		  			#$getoffset == 0;
		  			next;
		  		}


		  
		  		# find the string in the .constdata block
		  		if(($constdataswitch == 1)&&($_ =~ /0x(\S+):/)){
					# if match the offset
					if(index($_,$offset.":")>=0){	
						$hasequal = 1; 
						$targetindex = $index;
					}
					
					push @indexarray,$index;
					push @blockarray,trim($_);
					$index++;
	   			}	
					  
		  		if(($constdataswitch == 1)&&(index($_,"====================================") >= 0)){
	  				$constdataswitch = 0;
		  		}
		  	}
		 
		 	if($hasglobal == 1){
		 		next;
		 	}
		 	if($getoffset == 0){
		 		$resulthash{"funcname"}= $getfuncname;
				$resulthash{"objname"}= "(".$getobjname.")";
				push @resultarray, \%resulthash;
		 		next;
		 	}
		 
		  	# start to parse the block data
		 	  		
		  	# if find the offset match the target offset
		  	if($hasequal == 1){  		
		  		$line = trim($blockarray[$targetindex]);
		  		$moreswitch = 1;
		  		#$stringlength = 0;
		  		while($moreswitch == 1){ 
			  		@stringarray = split /\s+/,$line;
				  	# remove the first and last item
				  	shift(@stringarray);
				  	pop(@stringarray);
				  	$thislength = 0;
				  	if(scalar(@stringarray) == 0){
				  		$moreswitch = 0;
				  	}
				  	foreach $hexvalue(@stringarray){ 	
				  		if(is_ascii($hexvalue)){
				  			$thislength++;
				  			if($thislength <= $maxlength){
				  				$stringresult = $stringresult.hex_to_ascii($hexvalue);
				  			}
				  			# need to consider next line
				  			if($thislength == $maxlength){
				  				$targetindex = $targetindex + 1;
				  				if($targetindex < scalar(@blockarray)){
				  					$line = trim($blockarray[$targetindex]);
				  					$stringlength += $thislength;
				  				}
				  			}
				  			
				  		}
				  		else{
				  			if(($hexvalue eq "00")&&($stringlength != 0)){
				  					$stringlength += 1;
				  			}
				  			$stringlength += $thislength;
				  			$moreswitch = 0;
				  			last;
				  		}
				   }
		  	   }
			   # save the result
				my %resulthash ={};
				if($stringlength > 0){
					$resulthash{"funcname"}= $getfuncname;
					$resulthash{"objname"}= $getobjname;
					$resulthash{"constantstring"} = $stringresult;
					$resulthash{"stringsize"}= "0x".dec2hex($stringlength);
				}
				else{
					$resulthash{"funcname"}= "(".$getfuncname.")";
					$resulthash{"objname"}= $getobjname;
				}
				push @resultarray, \%resulthash;
		  	}
		  	
		  	# if no offset match the target offset
		  	else{
		   		my $findbetween = 0;
		  		for($i=0;$i<@blockarray;$i++){
		  			$line = trim($blockarray[$i]);
		  			$nextarget = $i;
			  		@stringarray = split /\s+/,$line;
					# get the offset value of this line
					$_ = shift(@stringarray);
					s/0x//;
					$thisoffset = hex($_);
					# get the offset value of next line
					$nextoffset = 0;
					if($i != (@blockarray-1)){
			  			@temparray = split /\s+/,trim($blockarray[$i+1]);
			  			$_ = shift(@temparray);
			  			s/0x//;
						$nextoffset = hex($_);
					}
					# get the target offset
					$_ = $offset;
					s/0x//;
					$targetoffset = hex($_);
					
					$difference = $targetoffset - $thisoffset;
					
					if(($targetoffset > $thisoffset)&&($targetoffset < $nextoffset)){

						$findbetween = 1;
						$moreswitch = 0;
		  				#$stringlength = 0;
					  	@stringarray = split /\s+/,$line;
						# remove the first and last item
						shift(@stringarray);
						pop(@stringarray);
						# remove the first different items
					  	for($j=0;$j<$difference;$j++){
					  		shift(@stringarray);
					  	}
						$thislength = 0;
						$moreswitch = 0;
						foreach $hexvalue(@stringarray){ 
						  	if(is_ascii($hexvalue)){
						  		$thislength++;
						  		if($thislength <= ($maxlength-$difference)){
						  			$stringresult = $stringresult.hex_to_ascii($hexvalue);
						  		}
						  		# need to consider next line
						  		if($thislength == ($maxlength-$difference)){
						  			$nextarget = $nextarget + 1;
						  			if($nextarget < scalar(@blockarray)){
						  				$line = trim($blockarray[$nextarget]);
						  				$moreswitch = 1;
						  				$stringlength += $thislength;
						  			}
						  		}
						  		
						  	}
						  	else{
						  		if(($hexvalue eq "00")&&($stringlength != 0)){
				  					$stringlength += 1;
				  				}
						  		$stringlength += $thislength;
						  		$moreswitch = 0;
						  		last;
						  	}
						}
				  	    while($moreswitch == 1){
						  	@stringarray = split /\s+/,$line;
						  	# remove the first and last item
						  	shift(@stringarray);
						  	pop(@stringarray);
						  	$thislength = 0;
						  	if(scalar(@stringarray) == 0){
						  		$moreswitch = 0;
						  	}
						  	foreach $hexvalue(@stringarray){ 	
						  		if(is_ascii($hexvalue)){
						  			$thislength++;
						  			if($thislength <= $maxlength){
						  				$stringresult = $stringresult.hex_to_ascii($hexvalue);
						  			}
						  			# need to consider next line
						  			if($thislength == $maxlength){
						  				$nextarget = $nextarget + 1;
						  				if($nextarget < @blockarray){
						  					$line = trim($blockarray[$nextarget]);
						  					$stringlength += $thislength;
						  				}
						  			}
						  			
						  		}
						  		else{
						  			if(($hexvalue eq "00")&&($stringlength != 0)){
				  					$stringlength += 1;
				  					}
						  			$stringlength += $thislength;
						  			$moreswitch = 0;
						  			last;
						  		}
						   }
				  	    }
						# save the result
						my %resulthash ={};
						if($stringlength > 0){
							$resulthash{"funcname"}= $getfuncname;
							$resulthash{"objname"}= $getobjname;
							$resulthash{"constantstring"} = $stringresult;
							$resulthash{"stringsize"}= "0x".dec2hex($stringlength);
						}
						else{
							$resulthash{"funcname"}= "(".$getfuncname.")";
							$resulthash{"objname"}= $getobjname;
						}
						push @resultarray, \%resulthash;
						last;
					}
		  		}
		  		# if no offset is between two offsets
				if($findbetween == 0){
					if($#blockarray != -1){
						$line = trim($blockarray[$#blockarray]);
						@stringarray = split /\s+/,$line;
						# get the offset value of this line
						$_ = shift(@stringarray);
						s/0x//;
						$thisoffset = hex($_);
						# get the target offset
						$_ = $offset;
						s/0x//;
						$targetoffset = hex($_);
						# calculate the difference
						$difference = $targetoffset - $thisoffset;
						# remove the first and last item
						shift(@stringarray);
						pop(@stringarray);
						# remove the first different items
					  	for($j=0;$j<$difference;$j++){
					  		shift(@stringarray);
					  	}
						foreach $hexvalue(@stringarray){ 
						  	if(is_ascii($hexvalue)){
						  		$stringlength++;
						  		if($stringlength <= ($maxlength-$difference)){
						  			$stringresult = $stringresult.hex_to_ascii($hexvalue);
						  		}
						  	}
						}
						# save the result
						my %resulthash ={};
						if($stringlength > 0){
							$resulthash{"funcname"}= $getfuncname;
							$resulthash{"objname"}= $getobjname;
							$resulthash{"constantstring"} = $stringresult;
							$resulthash{"stringsize"}= "0x".dec2hex($stringlength);
						}
						else{
							$resulthash{"funcname"}= "(".$getfuncname.")";
							$resulthash{"objname"}= $getobjname;
						}
						push @resultarray, \%resulthash;
					}
				}
				
		  	}
		  	
		  	
			
}	#close for firstaddressarray 
		  	close(FILE);
		}
	}
}
#****************************************************************************
# FUNCTION
#  getunusedRO
# DESCRIPTION
#  Parse unusedRO.txt, and get the function name and obj filename
#****************************************************************************
sub getunusedRO{
	#*--------------------------------------------------------------------------*
	#* Code Body
	#*--------------------------------------------------------------------------*
	open(FILE,"<$unusedfilename") || die "File open error!\n";

	@data = <FILE>;
	foreach(@data){
		    #skip the line that contains :
	  		if(index($_,":") >= 0){
	  			next;
	  		}
	  		# Find each section number, and record it in the $currentsecnum
	  		if($_ =~ /(\S+)\s\((\S+)\)/){ 			
	  			#print $1." ".$2."\n";
	  			my %unusedrohash ={};
			    $unusedrohash{"funcname"}= $1;
			    $unusedrohash{"objname"}= $2;
			    $unusedrohash{"disfilepath"} = get_dispath_by_objname($2);
			    push @unusedroarray, \%unusedrohash;
	  		}
	}
	close(FILE);
	
}

#****************************************************************************
# FUNCTION
#  get_dispath_by_objname
# DESCRIPTION
#  Find the corresponding disfile by obj name
#****************************************************************************
sub get_dispath_by_objname(){
	#*--------------------------------------------------------------------------*
	#* Local variables
	#*--------------------------------------------------------------------------*
	my $objname = $_[0];	
	#*--------------------------------------------------------------------------*
	#* Code Body
	#*--------------------------------------------------------------------------*
	foreach	(@disarray){		
		my $gethash = $_;
		my $getobjname = $gethash->{"objname"};
		my $getdisfilepath = $gethash->{"disfilepath"};
		#if($objname =~ /(\S+).o$/){
		#	$objname = $1.".obj";		
		#}
		
		if($getobjname eq $objname){
			return $getdisfilepath;
		}
	}
	return undef;
}

#****************************************************************************
# FUNCTION
#  get_objpath_by_objname
# DESCRIPTION
#  Find the corresponding objfile by obj name
#****************************************************************************
sub get_objpath_by_objname(){
	#*--------------------------------------------------------------------------*
	#* Local variables
	#*--------------------------------------------------------------------------*
	my $objname = $_[0];	
	#*--------------------------------------------------------------------------*
	#* Code Body
	#*--------------------------------------------------------------------------*
	foreach	(@disarray){		
		my $gethash = $_;
		my $getobjname = $gethash->{"objname"};
		my $getobjfilepath = $gethash->{"objfilepath"};
		#if($objname =~ /(\S+).o$/){
		#	$objname = $1.".obj";		
		#}
		
		if($getobjname eq $objname){
			return $getobjfilepath;
		}
	}
	return undef;
}
#****************************************************************************
# FUNCTION
#  dimp_symboltable_to_file
# DESCRIPTION
#  This function dumps the the data of symbolarray to file(symboltable.txt)
#****************************************************************************
sub dump_symboltable_to_file{
	#*--------------------------------------------------------------------------*
	#* Local variables
	#*--------------------------------------------------------------------------*
	my $disfilename;
	my $symbolname;
	my $symbolvalue;
	my $symbolsize;
	
	#*--------------------------------------------------------------------------*
	#* Code Body
	#*--------------------------------------------------------------------------*
	open(FILE,">symboltable.txt") || die "File open error!\n";
	
	# Set the data format
format FILE =
  @<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< @<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  @<<<<<<<<<<<< @<<<<<<<<<<
  $disfilename,$symbolname, $symbolvalue,$symbolsize
.
	foreach (@symbolarray){
		my $symbolhash = $_;
		$disfilename = $symbolhash->{"objname"};
		$symbolname = $symbolhash->{"symbolname"};
		$symbolvalue = $symbolhash->{"symbolvalue"};
		$symbolsize = $symbolhash->{"symbolsize"};
		# Remove the empty line
		unless($symbolname eq ""){
			write(FILE);
		}
	}	
	close(FILE);
}

#****************************************************************************
# FUNCTION
#  matchsecnum
# DESCRIPTION
#  This function determine whether the section number is in the secnum array
# PARAMETERS
#  $secnum			section number
#  @secnumarray		section number array
# RETURNS
#  result			return 1 for success; return 0 for fail
#****************************************************************************
sub matchsecnum{
	#*--------------------------------------------------------------------------*
	#* Local variables
	#*--------------------------------------------------------------------------*
	my $result = 0;
	my $secnum = $_[0];
	my @secnumarray = $_[1];
	#*--------------------------------------------------------------------------*
	#* Code Body
	#*--------------------------------------------------------------------------*
	foreach (@secnumarray){
		if($secnum == $_){
			$result = 1;
			return $result;
		}
	}
	return $result;
}
sub trim($)
{
	my $string = shift;
	$string =~ s/^\s+//;
	$string =~ s/\s+$//;
	return $string;
}
#****************************************************************************
# FUNCTION
#  disassemble
# DESCRIPTION
#  This function disassemble all the obj files in the root directory
#****************************************************************************
sub disassemble{
	  foreach (@filearray){
		#*--------------------------------------------------------------------------*
		#* Local variables
		#*--------------------------------------------------------------------------*
		my $myhash = $_;
		my $filename = $myhash->{"filename"};
		my $filepath = $myhash->{"filepath"};
		#*--------------------------------------------------------------------------*
		#* Code Body
		#*--------------------------------------------------------------------------*
		$_ = $filename;
		s/.obj/.dis/;        
		my $newfilename = $_;
		$_ = $filepath;
		s/$filename/$newfilename/;
		
		#Start to Disassemble (obj=>dis)
		
		#If the dis file doesn't exist, disassemble the obj file
		unless(-e $_){
			#system("start C:\\Progra~1\\ARM\\ADSv1_2\\Bin\\fromelf -cdrstvz ".$myhash->{"filepath"}.">".$_);
			system("C:\\Progra~1\\ARM\\ADSv1_2\\Bin\\fromelf -cdrstvz ".$myhash->{"filepath"}.">".$_); 
			print "C:\\Progra~1\\ARM\\ADSv1_2\\Bin\\fromelf -cdrstvz ".$myhash->{"filepath"}.">".$_."\n";
                        #sleep(1);
		}
		
	    my %filehash ={};
		$filehash{"objname"}= $filename;
		$filehash{"objfilepath"}= $filepath;
		$filehash{"disfilepath"}= $_;
		push @disarray, \%filehash;

}

	
}


#****************************************************************************
# FUNCTION
#  traversefile
# DESCRIPTION
#  This function scan the root directory , find all the obj files
# PARAMETERS
#  #sub_DIR root directory
#****************************************************************************
  sub traversefile{
	#*--------------------------------------------------------------------------*
	#* Local variables
	#*--------------------------------------------------------------------------*	
	my $sub_DIR_id ;
	my $sub_DIR ;
	my $sub_SRC_FILE;
	my @dirarray;
	my $i;
	my $count=0;
	my $newdir;
 	
 	$sub_DIR = $_[0];  # root directory
	#*--------------------------------------------------------------------------*
	#* Code Body
	#*--------------------------------------------------------------------------*	
	
  	#if $sub_DIR is a directory
  	if(-d ($sub_DIR)){
  			opendir(sub_DIR_id, $sub_DIR) or die " cannot open directory :($sub_DIR)\n";
			 while ( defined ($sub_SRC_FILE = readdir(sub_DIR_id)) )
			  {		 
				#exclude . and ..
			    if (($sub_SRC_FILE ne "\.") && ($sub_SRC_FILE ne "\.\."))
			    { 	
			    	my $path = $sub_DIR."\\".$sub_SRC_FILE;
			    	unless(-d ($path)){
			    		$_ = $path;
			    		#Only count obj file
			    		if(/.obj$/i){
			    			my %filehash ={};
			    			$filehash{"filename"}= $sub_SRC_FILE;
			    			$filehash{"filepath"}= $path;
			    			push @filearray, \%filehash;
			    		}
			    	}
					@dirarray[$count]=$sub_DIR."\\".$sub_SRC_FILE;
					$count++;
			   	} 
			 }	 
			 for($i=0;$i<$count;$i++){
			 	 $newdir = @dirarray[$i];
			 	 traversefile($newdir);
			 }
 }
#****************************************************************************
# FUNCTION
#  hex_to_ascii
# DESCRIPTION
#  This function convert each two-digit hex number back to an ASCII character
#****************************************************************************
sub hex_to_ascii ($){
    (my $str = shift) =~ s/([a-fA-F0-9]{2})/chr(hex $1)/eg;
    return $str;
}
#****************************************************************************
# FUNCTION
#  is_ascii
# DESCRIPTION
#  This function check whether the param is a ascii code
#****************************************************************************
sub is_ascii($){
	$param = hex_to_ascii($_[0]);
	$asciinum = ord($param);
	if((($asciinum>=32)&&($asciinum<=126))||($asciinum==10)){
		return 1;
	}
	else{
		return 0;
	}
}

    sub dec2hex {
    # parameter passed to
    # the subfunction
    my $decnum = $_[0];
    # the final hex number
    my $hexnum;
    my $tempval;
    while ($decnum != 0) {
    # get the remainder (modulus function)
    # by dividing by 16
    $tempval = $decnum % 16;
    # convert to the appropriate letter
    # if the value is greater than 9
    if ($tempval > 9) {
    $tempval = chr($tempval + 55);
    }
    # 'concatenate' the number to 
    # what we have so far in what will
    # be the final variable
    $hexnum = $tempval . $hexnum ;
    # new actually divide by 16, and 
    # keep the integer value of the 
    # answer
    $decnum = int($decnum / 16); 
    # if we cant divide by 16, this is the
    # last step
    if ($decnum < 16) {
    # convert to letters again..
    if ($decnum > 9) {
    $decnum = chr($decnum + 55);
    }
    
    # add this onto the final answer.. 
    # reset decnum variable to zero so loop
    # will exit
    $hexnum = $decnum . $hexnum; 
    $decnum = 0 
    }
    }
    return $hexnum;
    } # end sub
 


}

sub getOwner(){
	$cc_mcu_path = "M:\\".$branch."_int\\MAUI_SW\\mcu";
	$fullfilepath = shift @_;
	@part = split /\\/,$fullfilepath;
	$obj_parse = $part[-1];
	$lib_parse = $part[-2].".lib";
	$owner = "";
	$filepath = getfilepath($lib_parse,$obj_parse,$mcudir);
	
	if($mcudir eq ".\\"){
		$_ = $filepath;
		s/.\\/\\/;
		$cc_mcu_path = $cc_mcu_path.$_;
	}
	else{
		if($filepath =~ /(\S+)mcu(\S+)/){
			$cc_mcu_path = $cc_mcu_path.$2;
		}
	}

  if (!-e ){
  	$new_cc_mcu_path = $cc_mcu_path."pp";
  	if (-e $new_cc_mcu_path){
  		$cc_mcu_path = $new_cc_mcu_path;
  	}
  }
	$owner = get_owner_from_CC_server($cc_mcu_path);
	return $owner;
}
sub getfilepath
{
    my ($mcu_path, $lis_path);
	 $lib_file = shift @_;
	 $obj_file = shift @_;
	 $mcu_path = shift @_;
	my ($lib_tmp, $obj_tmp);

	### get lis file path
	$lib_file =~ /(.*).lib/;
	$lib_tmp = $1;

	# search source file path for object file
	# query from lis file


	if ((lc($lib_file) eq "conn_app.lib")||(lc($lib_file) eq "inet_app.lib")||(lc($lib_file) eq "mmi_app.lib")||(lc($lib_file) eq "mmi_framework.lib")||(lc($lib_file) eq "media_app.lib"))    ## find file path in the official release code base
	{
			$lis_path = $mcu_path . "make\\plutommi\\$lib_tmp\\$lib_tmp.lis";
	}
	else
	{
		 $lis_path = $mcu_path . "make\\$lib_tmp\\$lib_tmp.lis";
	}

	### get c file path
	$obj_file =~ /(.*).obj/;
	$obj_tmp = $1;
	
	my $c_file = "$obj_tmp" . ".c";

	my $success = open (LIS_FILE, "<$lis_path") or warn "cannot open $lis_path\n";

	if($success)
	{
		# read whole file
		my $backup = $/;
		undef $/;
		my $reading = <LIS_FILE>;
		$/ = $backup;

		if ($reading =~ /(.*\\)$c_file/i)
		{
			#print "HIT2: $1\n";
			$c_file = $mcu_path. $1 . $c_file;
			#print "C_FILE: $c_file\n";
		}
		else
		{
			print "Assert: $c_file is NOT MATCHED in $lis_path !\n";
		}
	}

	return $c_file;
}


#****************************************************************************
# Get owner of the source of a label from CC server
# Support when file is merged from subsidiary branch
#****************************************************************************
sub get_owner_from_CC_server
{
   my ($src) = @_;
   my $result;
   my $CQ_owner;
   my $cmd1;
   my $tmp3;
   my $tmp4;
   my $tmp5;
   my $cmd2=();
   
   if($src=~/(.+)\\(.+)/g )
   {
       $tmp3=$1;
       $tmp4=$2;
       my $file_name;

       $tmp5="M: & cd ".$tmp3." & ";

       $tmp4=~s/\./\\\./;
       if(!(-d $tmp3))
       { 
       	  $CQ_owner="ccadmin"; 
       	  return $CQ_owner;
       }     
                     
       #opendir (TMP3_DIR, $tmp3) or die "can't open directory $tmp3: $!";
       opendir (TMP3_DIR, $tmp3);
       while ( defined ($file_name = readdir(TMP3_DIR)) )
       {
	   if ($file_name=~/^$tmp4$/i)
	   { 
	      $tmp4=$file_name;
	      last;
	   }  
       }
       closedir TMP3_DIR;     
       $cmd2=();
       
       $cmd2=$tmp5.'cleartool describe -fmt "Onwer: %Lu\nActivity: %[activity]p\n"'." ".$tmp4;

       $result=`$cmd2`;
    }

   if($result=~/Onwer: (.+)\.Domain Users/i)
   {  
       $CQ_owner=$1;
       if($CQ_owner=~/ccadmin/i)
       {
       	  $cmd2=();
          $cmd2=$tmp5."cleartool describe ".$tmp4."\|find \"Merge\"";

       	  $result=`$cmd2`;
       	  if($result=~/Merge <- ([^\s]+)/i)
       	  {
       	  	$tmp4=$1;

       	  	$cmd2='cleartool describe -fmt "Onwer: %Lu\nActivity: %[activity]p\n"'." ".$tmp4;
       	  	$result=`$cmd2`;
       	  	if($result=~/Onwer: (.+)\.Domain Users/i)
                {
                	$CQ_owner=$1;
                	#print "Merge file owner:$CQ_owner \n";
                } 
       	  }
       }      
   }
   return $CQ_owner;  
} # sub get_owner_from_CC_server


sub usage
{
    print "perl ROParser.pl <LIS filepath> <obj root path> <mcu path> <branch>\n";
    exit(0);
}

sub startview(){
  $view = $branch."_int";
	$result = `cleartool startview $view 2>&1`;
	print $result;
	if($result =~ /cleartool: Error:/){
		exit(0);
	}
}