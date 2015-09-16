use strict;
use warnings;
#*--------------------------------------------------------------------------*
#* Global variables
#*--------------------------------------------------------------------------*
my $LISFILE      = $ARGV[0];
my $DBGFILE      = $ARGV[1];
my %lang_pack_set;
my %cust_pack_set;
my %jump_table_set;
my %lib_set;
my %symbol_set;
my %symbol_startaddr_set;
my %symbol_endaddr_set;
my %filesrange_set;
my (@ref_sec, @dec_sec, @dec_region, @content, @total);	# referencing obj, referencing function, declaration obj, declaraion region, referenced content
my ($initialtime, $finishtime, $exectime);
my $output = "";

#*--------------------------------------------------------------------------*
#* Code Body
#*--------------------------------------------------------------------------*
warn "
==============================================================================
 [Program]    MBA_Check.pl
 [Version]    V2.0
 [Date]       2011-12-01
 [Author]     yikuan.huang\@mediatek.com Timon.Lu\@mediatek.com
 [Copyright]  Copyright (C) 2011 MediaTek Incorporation. All Rights Reserved.
==============================================================================
";
$initialtime = time();
# parse the dbg file
parsedbgfile();
# parse the lis file
parselisfile();
# check the reference chain
getFalseReference();
# output result to file
writeOutput();
$finishtime = time(); 
$exectime = $finishtime - $initialtime;
print "Total execution time: ".$exectime." seconds\n";


#****************************************************************************
# FUNCTION
#  parsedbgfile
# DESCRIPTION
#  This function parse DBG info file
#  if you need to know detail, please refer to DBG file format
#****************************************************************************

sub parsedbgfile{

my $dbgfilesize = -s $ARGV[1];
my ($mainversion, $subversion, $projectname, $hwversion, $swversion, $buildtime, $symtableoffset, $filetableoffset);
my $symtablelength;
my ($buf, $data, $n);
my @contents;	

#-------------------------------------------------------------
die "$DBGFILE does not exist!\n" if (!-e $DBGFILE);
open (DBG_FILE_HANDLE, "<$DBGFILE") or die "Fail to open $DBGFILE\n";
binmode DBG_FILE_HANDLE;
#-------------------------------------------------------------
$n = sysread (DBG_FILE_HANDLE, $data, $dbgfilesize);
#------------------------parse header --------------------------
if($data =~ /CATI(.{4})(.{4})([\w\s\x2E\x3A\x2F\x5F]+)\x00([\w\s\x2E\x3A\x2F\x5F]+)\x00([\w\s\x2E\x3A\x2F\x5F]+)\x00([\w\s\x2E\x3A\x2F\x5F]+)\x00(.{4})(.{4})([\s\S]*)/){
	  #mainversion of debug info 
    $mainversion = unpack('V', $1); 
    #subversion of debug info
    $subversion = unpack('V', $2);
    #project name of debug info
    $projectname = $3;
    #HW version of debug info
    $hwversion = $4;
    #SW version of debug info
    $swversion = $5;
    #build time of debug info which will be generated after building binary
    $buildtime = $6;
    #symtable offset of debug info which is append after debug info header (mainversion...etc)
    $symtableoffset = unpack('V', $7);
    #filetable offset of debug info which is append after symtable.
    $filetableoffset = unpack('V', $8);
    
    #debug info version match
    if(($mainversion != 1) || ($subversion != 0)){
        die "debug info file version is incorrect! VER_MAIN: ".$mainversion.", VER_SUB: ".$subversion."\n";
    }
    #get symbol table length
    $symtablelength = $filetableoffset - $symtableoffset;
    #truncate symbol table
    $data = substr($9, 0, $symtablelength);        

    my $count = 3;	
    my $symbol;
    #split symbol table by its format. name->null string->4 bytes for start addr->4 bytes for end addr ...repeat
    my @symbols = split(/([\w:()]+).(.{4})(.{4})/, $data);
    foreach my $val (@symbols) {
        if(($count % 4 ) == 0){
            #print length($val)." ".$val."\n";
            $symbol = $val;
            $symbol_set{$symbol} = $symbol;
        }
        elsif(($count % 4 ) == 1){
            #print length($val)." ".unpack('V', $val)."\n";
            $symbol_startaddr_set{$symbol} = unpack('V', $val);
        }
        elsif(($count % 4 ) == 2){
            #print length($val)." ".unpack('V', $val)."\n";
            $symbol_endaddr_set{$symbol} = unpack('V', $val);
        }
        $count++;        
    }
    #truncate file table    
    $data = substr($9, $symtablelength+1);
    $count = 1;
    my $file_name="";
    #split file table by its format. name->null string->4 bytes for number of addr range pair-> 4 bytes for
    #pair one start addr->4 bytes for pair one end addr->......pair loop
    #my @files = split(/([\w\x2F]+\x2F[\w]+).[c|cpp]\x00/, $data);
    my @files = split(/\w+\x2F([\w]+).[c|cpp]\x00/, $data);
    foreach my $val (@files) {
        if($count % 2 == 0){
        	  $file_name = $val;
        	  #print $file_name."\n";
        }
        elsif($count % 2 == 1){
            @contents = unpack("V*", $val);
            $filesrange_set{$file_name} = [@contents];
        }
        $count++;            
    }
}
else{

}

close(DBG_FILE_HANDLE);

}

#****************************************************************************
# FUNCTION
#  parselisfile
# DESCRIPTION
#  This function parse LIS file
#****************************************************************************
sub parselisfile{
my ($i, $ref_count);
my $loadregionswitch = 0;
my $langpackswitch = 0;
my $custpackswitch = 0;
my $jumptableswitch = 0;
$i = 0; 
die "$LISFILE does not exist!\n" if (!-e $LISFILE);
open (FILE_HANDLE, "<$LISFILE") or die "Fail to open $LISFILE\n";
while (<FILE_HANDLE>) {
	if (/(\S+)\..*\((\S+)\)\srefers\sto\s(\S+)\..*\((\S+)\)\sfor\s(\S+)\s*/) {	# AAA.obj(i.func/pragma) refers to BBB.obj(i.func/pragma/region) for content
		$ref_sec[$i] = $2.$1;		# AAA		
		$dec_sec[$i] = $4.$3;		# BBB
		$total[$i] = $_;
		$i++;					# should be indexed with the same $i		    
	}
	
	if (/Memory Map of the image/){
	  $loadregionswitch = 1;	
	}
  if (/Image component sizes/){
    $loadregionswitch = 0;	  	
  }
	# turn on the switch if meet Load Region LANG_PACK_ROM
	if (/Execution Region LANG_PACK_ROM_CONTENT/){
		$langpackswitch = 1;
	}
	else{
		# turn off the switch if meet another Load Region
		if (/Execution Region/){
			$langpackswitch = 0;
		}
	}
	
	# turn on the switch if meet Load Region CUSTPACK_ROM
	if (/Execution Region CUSTPACK_ROM_CONTENT/){
		$custpackswitch = 1;
	}
	else{
		# turn off the switch if meet another Load Region
		if (/Execution Region/){
			$custpackswitch = 0;
		}
	}
	
	# turn on the switch if meet Load Region JUMP_TABLE
	if (/Load Region JUMP_TABLE/){
		$jumptableswitch = 1;
	}
	else{
		# turn off the switch if meet another Load Region
		if (/Execution Region/){
			$jumptableswitch = 0;
		}
	}
	
	# parse the lang pack section
	if ($langpackswitch == 1){
		if(/\s*0x\S*\s*\S*\s*\S*\s*\S*\s*\S*\s*(\S*)\s*(\w*)/){
			unless(trim($1.$2) eq ""){
				#print $2.$1."\n";
				$lang_pack_set{$1.$2}=$1.$2;
			}				
		}		
	}
	# parse the cust pack section
	if ($custpackswitch == 1){
		if(/\s*0x\S*\s*\S*\s*\S*\s*\S*\s*\S*\s*(\S*)\s*(\w*)/){
			unless(trim($1.$2) eq ""){
				$cust_pack_set{$1.$2}=$1.$2;
			}				
		}
	}
	# parse the jump table section
	if ($jumptableswitch == 1){
		if(/\s*0x\S*\s*\S*\s*\S*\s*\S*\s*\S*\s*(\S*)\s*(\w*)/){
			unless(trim($1.$2) eq ""){
				#print $2.$1."\n";
				$jump_table_set{$1.$2}=$1.$2;
			}	
		}
	}
	if ($loadregionswitch == 1){		
		#parse function 
	  if(/\s*0x\S*\s*\S*\s*\S*\s*\S*\s*\S*\s*(\S*)\s*(\S*)/){
	  	my $section = $1;
	  	my $objandLib = $2;
	  	if($objandLib =~ /(\S*)\.o.*\((\S*)\)/){		#$2 = library name    
		    $lib_set{$section.$1} = $2;
		    #print "$section -> $1 -> $2 \n";
		  }
	  }
  }	
}
close FILE_HANDLE or die "Fail to close $LISFILE\n";

}
#****************************************************************************
# FUNCTION
#  replaceFileName
# DESCRIPTION
#  this function use the result of parsedbgfile to get real file name!
#  
#****************************************************************************
sub replaceFileName{    
    my $filename = "";
    my $libname = "";
    my ($fromfunctionaddr, $tofunctionaddr, $fromfilename, $tofilename); 

    if($_[0] =~ /(\S+)\..*[\(\.]+(\w+)\)\srefers\sto\s(\S+)\..*[\(\.]+(\w+)\)\sfor\s(\S+)\s*/){
		    $fromfunctionaddr = $symbol_startaddr_set{$2}; # $2 = from function address
		    $tofunctionaddr = $symbol_startaddr_set{$4};	 # $4 = to function address	  
		    # those two line are used to prevent warning msg.  
		    $fromfunctionaddr = defined $fromfunctionaddr ? $fromfunctionaddr : 0;
		    $tofunctionaddr = defined $tofunctionaddr ? $tofunctionaddr : 0;
		    # look for file name by function address		    
		    for $filename (keys %filesrange_set){
		        if(length($filename) != 0){
		            for(my $i = 1; $i < ($filesrange_set{$filename}[0]*2+1); $i+=2){
		                if($fromfunctionaddr != 0 && $fromfunctionaddr >= $filesrange_set{$filename}[$i] && $fromfunctionaddr <= $filesrange_set{$filename}[$i+1]){
		                  $fromfilename = $filename;
		                  $_[0] =~ s/$1/$fromfilename/g;
		                }
		                if($tofunctionaddr != 0 && $tofunctionaddr >= $filesrange_set{$filename}[$i] && $tofunctionaddr <= $filesrange_set{$filename}[$i+1]){
		                  $tofilename = $filename;			                  
		                  $_[0] =~ s/$3/$tofilename/g;		                  
		                }
		            }
		        }
		    }
    }    
    # those two line are used to prevent warning msg.
    $fromfilename = defined $fromfilename ? $fromfilename : "";
		$tofilename = defined $tofilename ? $tofilename : "";		
		$libname = 	$lib_set{$_[1]};
		$libname = defined $libname ? $libname : "";
    if(length($fromfilename) != 0){
        $_[0] = "Warnning :  $fromfilename.obj ($libname) \n    ".$_[0];
    }
	  else{
    	  $_[0] = "Warnning :  $1.obj ($libname) \n    ".$_[0];
		}
}
#****************************************************************************
# FUNCTION
#  getFalseReference
# DESCRIPTION
#  Check the function reference
#****************************************************************************
sub getFalseReference{
	
for (my $i = 0;$i<@ref_sec;$i++) {
	my $from_sec = $ref_sec[$i];
	my $to_sec = $dec_sec[$i];
	my $line = $total[$i];
	
	
	# hard code to skip function InitializeResourceVariables and StandaloneResValidation
	if(($from_sec =~ /resource_custpack_jtbl.*/) || ($from_sec =~ /resource_lang_pack_jtbl.*/)){			
		next;	
	}
	# check if lang not refer to lang
	if(isLangPack($from_sec) eq "true"){
		unless(isLangPack($to_sec) eq "true"){
			replaceFileName($line, $from_sec);		
			$output = $output.$line."Recommend Correction ---> Cannot Cross Reference Out of Lang Pack Content, Please Move RO-CODE out of RESB or Revise Data Structure\n\n";
		}
	}
	# check if cust not refer to cust
	if(isCustPack($from_sec) eq "true"){
		unless(isCustPack($to_sec) eq "true"){
			replaceFileName($line, $from_sec);
			$output = $output.$line."Recommend Correction ---> Cannot Cross Reference Out of Cust Pack Content, Please Move RO-CODE out of RESB or Revise Data Structure\n\n";
		}
	}
	# check if jtb not refer to lang or cust
	if(isJumpTable($from_sec) eq "true"){
		unless((isLangPack($to_sec) eq "true")||(isCustPack($to_sec) eq "true")){
			replaceFileName($line, $from_sec);
			$output = $output.$line."Recommend Correction ---> Critial Probelm, Please Reach System Service To Help You\n\n";
		}
	}
	# check if not lang or jtb refer to lang
	if(isLangPack($to_sec) eq "true"){
		unless((isLangPack($from_sec) eq "true")||(isJumpTable($from_sec) eq "true")){			
			replaceFileName($line, $from_sec);
			$output = $output.$line."Recommend Correction ---> Cannot Directly Reference To Lang Pack Content, Lookup JumpTable First\n\n";			
		}
	}
	# check if not cust or jtb refer to cust
	if(isCustPack($to_sec) eq "true"){
		unless((isCustPack($from_sec) eq "true")||(isJumpTable($from_sec) eq "true")){
			replaceFileName($line, $from_sec);
			$output = $output.$line."Recommend Correction ---> Cannot Directly Reference To Cust Pack Content, Lookup JumpTable First\n\n";
		}
	}
	# check if lang or cust refer to jtb
	if(isJumpTable($to_sec) eq "true"){
		if((isLangPack($from_sec) eq "true")||(isCustPack($from_sec) eq "true")){
			replaceFileName($line, $from_sec);
			$output = $output.$line."Recommend Correction ---> Cannot Reverse Reference From RESB to Jump Table, Please Revise Data Structure\n\n";
		}
	}
}

}

#****************************************************************************
# FUNCTION
#  isLangPack
# DESCRIPTION
#  Check the obj if exist in Lang Pack region
#****************************************************************************
sub isLangPack(){
	my $result = "false";
	my $obj = $_[0];
	while ( my ($key, $value) = each(%lang_pack_set) ) {
		my $target = $key;
        if($obj eq $target){
        	$result = "true";
        }
    }
    return $result;
}
#****************************************************************************
# FUNCTION
#  isCustPack
# DESCRIPTION
#  Check the obj if exist in Cust Pack region
#****************************************************************************
sub isCustPack(){
	my $result = "false";
	my $obj = $_[0];
	while ( my ($key, $value) = each(%cust_pack_set) ) {
        my $target = $key;
        if($obj eq $target){
        	$result = "true";
        }
    }
    return $result;	
}
#****************************************************************************
# FUNCTION
#  isJumpTable
# DESCRIPTION
#  Check the obj if exist in Jump Table region
#****************************************************************************
sub isJumpTable(){
	my $result = "false";
	my $obj = $_[0];
	while ( my ($key, $value) = each(%jump_table_set) ) {
        my $target = $key;
        if($obj eq $target){
        	$result = "true";
        }
    }
    return $result;	
}
#****************************************************************************
# FUNCTION
#  writeOutput
# DESCRIPTION
#  Output the result to file
#****************************************************************************
sub writeOutput{
	# set the name of output file
	my @part = split /\\/, $LISFILE;
	my $outputFile = $part[-1];
	$outputFile =~ s/lis/txt/;
	
	#write result to file	
	open(RESULT,">$outputFile") || die "File open error!\n";
	print RESULT $output;
	close(RESULT)
}

#****************************************************************************
# FUNCTION
#  trim
# DESCRIPTION
#  Trim the space in front and back of string
#****************************************************************************
sub trim($)
{
	my $string = shift;
	$string =~ s/^\s+//;
	$string =~ s/\s+$//;
	return $string;
}
