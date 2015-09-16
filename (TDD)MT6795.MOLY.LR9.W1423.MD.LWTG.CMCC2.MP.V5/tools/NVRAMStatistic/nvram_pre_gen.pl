use strict;
use warnings;
use Cwd;
use File::Find;
use File::Copy;


	my ($ERR_OK, $ERR_OPEN_FILE, $ERR_HISR_INDEX) = 0..2;
	my $outputpath = $ARGV[0]; 

	my $debug = 0;
	my $platform = 0;
	my $streamstr =(["0", "1"]);
	my $starttime = time();
	my $usetime = 0;
	 
	my @resultlist;
	my $arrayC = 0;
	my $arrayL = 0;
	my $index = 0;
  	my $mycur = cwd;

	my $tooldir = "../tools/NVRAMStatistic";
	my $curdir;
	my $searchdir = "../../custom";

	print "Platform is: $^O\n";
	
	if ($^O eq "MSWin32")
	{
		$platform = 0;
	}
	else
	{
		$platform = 1;
	}

	if ($platform == 1)
	{
	  chdir("./tools/NVRAMStatistic");
	}	
	
	chdir($searchdir);
	find(\&CheckLidFileName, cwd);

	if($platform == 0)
	{		
		my $srchdir = "../nvram/src";
		chdir($srchdir);		
		find(\&CheckLidFileName, cwd);
		chdir("../../custom");
	}
	else
	{
		my $srchdir = "../service/nvram/src";
		chdir($srchdir);
		
		find(\&CheckLidFileName, cwd);
		chdir("../../../custom");
	}
	
	my $indexarray = $#resultlist+1;  
  
	$streamstr .= sprintf("Total LID Num: %d \n", $indexarray);

	$streamstr .= "\n sort LID file name \n";		
	$streamstr .= "\n    Nvram LID                                      File name \n";
		
	my $temp;
	my $tempName;
	my $temp1;
	my $tempName1;
	my $repeat = 0;
	my $j;
	my @list = sort{$a->[1] cmp $b->[1]}@resultlist;     #sort array 
	
	$tempName = $list[1][0];
	$temp = $list[1][1];

	for(my $i = 1; $i < $#list+1; $i++)
	{
		for($j = 0; $j <2; $j++)
		{
			if($j==0)
  		  {
	  		$tempName1 = $list[$i][$j];
		  }
		  else
		  {
			  $temp1 = $list[$i][$j];
					  
			  if (($tempName eq $tempName1) && ($temp eq $temp1) && $i > 1)
			  {			  	
			  	$repeat = 1;
			  }
			  else
			  {			  	
			  	$repeat = 0;
			  }			
		  }
		}
		
		if( $repeat == 0 )
		{
			$streamstr .= sprintf("%-64s", $tempName1);
			$streamstr .= sprintf("%-64s", $temp1);
			$streamstr .= "\n";			
		}		
		$tempName = $tempName1;
		$temp = $temp1;			
	}
			
	chdir($tooldir);
	
	my @gen_array;
	my $genindex= 0;
	my @tar_array;
	my $tarindex= 0;
    
	# get code from nvram_gen_assign_entry() 
	my $searchfiledir = "src/";  
	my $searchfilefile = "nvram_gen_util.c"; 
	chdir($searchfiledir);
	find(\&CheckLIDAssginTableEntry, $searchfilefile);
	$curdir ="../";
	chdir($curdir);
   
  # get code from nvram_assign_table_entry() 
	my $searchtardir; 
	if($platform == 0)
	{
		$searchtardir = "../../nvram/src/"; 
	}
	else
	{
		$searchtardir = "../../service/nvram/src/";
	}
	
	my $searchtarfile = "nvram_ltable.c";
	chdir($searchtardir);
	find(\&CheckLIDAssginTableEntry, $searchtarfile); 

    if($platform == 0)
    {
		$curdir ="../../tools/NVRAMStatistic";
	}
	else
	{
		$curdir ="../../../tools/NVRAMStatistic";
	}
	
	chdir($curdir);
	my $dif = 0;
	
	print "genindex = $genindex   tarindex = $tarindex \n";
	if( $genindex == $tarindex )
	{
		for(my $i = 0; $i<$#gen_array; $i++)
		{
			if($gen_array[$i] ne $tar_array[$i])
			{
			    $dif++;
			}	
		}
	}
	else
	{
		print" \n warning: genindex != tarindex !!!!\n";
	}
	
	if($dif > 0)
	{
		print" dif = $dif \n";
		$streamstr .= "Warning: nvram_assign_table_entry is different with nvram_gen_assign_entry!!!!!\n";
		$streamstr .= sprintf("dif = %d \n", $dif);
	}	
	
	$usetime = time() - $starttime;	
	print "Buid spend time:  $usetime S\n";		
	$streamstr .= sprintf("Nvram_pre_gen Check spend time: %d \n", $usetime);
	WriteFile("../../$outputpath/nvramfilenameinfo.log",$streamstr); 
	WriteFile("/nvramfilenameinfo.log", $streamstr);
	exit $ERR_OK;
  
sub CheckLidFileName
{
	my $file = $File::Find::name; 	

	if($platform == 0)
	{
		$file =~ s,/,\\,g;
	}
	return unless $file =~ /.*nvram_.*\.c$/gi;  #file pattern
	search_context($file);
}

sub search_context
{	 
	my ($strFilePath) = @_;

	open FILEHANDLE, "<$strFilePath" or die "couldn't open $strFilePath\n" && return $ERR_OPEN_FILE;
	
	my $bLtable = 0;     # found ltable_entry_struct logi
	my $startparse = 0;  # first {
	my $bfindLid = 0;    # need to find a lid  ,if no lid ,how to do
	my $bfindFname = 0;
	my $finishFlag = 0;
	my $count = 0;
    
	while (<FILEHANDLE>) 
	{		
    my $line = $_;      
    chomp($line);
      
    if($line =~ /\s*ltable_entry_struct.+logical_data_item_table_.*=.*/g)
    {
    	$streamstr .= sprintf("\n %d %s \n", $index, $line);
    	
    	$bLtable = 1;
    	$startparse = 0;   # first {
    	$bfindLid = 1;
    	$bfindFname = 0;
    	$finishFlag = 0;
    	$index++;
    	next;
    } 
    
    if($finishFlag == 0 && $startparse ==0 && $bLtable == 1 )
    {
    	my $tmpline = $line;
    	
    	$tmpline =~ s/\s*//;
    	
    	if( $tmpline =~ /{.*/g)
    	{
    		$finishFlag ++;
    		#avoid blank line or line with "; ,"
    		$startparse = 1;
    		next;
    	}	
    	 
      if( $tmpline =~ /}.*/g)
    	{
    		$finishFlag --;
    		next;
    	}	 
    }
    
    if($finishFlag == 0 && $finishFlag == 1 )
    {
    	#ltable finished    	
    	$bLtable = 0;
    	$startparse = 0;
    	$bfindLid = 0;
    	$bfindFname = 0;
    	next;
    }       
    
    if( $startparse ==1 && $bLtable == 1 && $bfindLid == 1 )
    {
    	#find the lid name NVRAM_EF_***_LID
    	my $lidstr = $line;
    	$lidstr =~ s/\s*//;
    	chomp($lidstr);

    	if($lidstr =~ /^NVRAM_EF_.+_LID.*,/g) 
		{
			my $lidstr = $line;
			$lidstr =~ s/\s*//; 

			do{;}until(chop($lidstr) eq ",");

			$resultlist[$arrayC][$arrayL] = $lidstr;
			$streamstr .= sprintf("%-54s", $resultlist[$arrayC][$arrayL]);
			$arrayL++;	
			$bfindFname = 1;   #should get the file name
			next;			    		
		}
    	
    	if ( $startparse ==1 && $bLtable == 1 && $bfindFname == 1)
	    {
	    	# fine file name  "MT010001"
	    	if($line =~ /".+"/g) 
	    	{
	    		my $lidstr = $line;
	    		$lidstr =~ s/\s*//; 
	    		
	    		do{;}until(chop($lidstr) eq ",");
	    		
	    		$resultlist[$arrayC][$arrayL] = $lidstr; 
	    		$streamstr .= sprintf("%s\n", $resultlist[$arrayC][$arrayL]);
	    		$arrayC++;
	    		$arrayL = 0; 
	    		$bfindFname = 0;	
	    	}
	    	next;
	    }     	
    }    
  }   
  return;   
}


sub CheckLIDAssginTableEntry
{
	my $file = $File::Find::name; 	

	if($platform == 0)
	{
		$file =~ s,/,\\,g;         # with path and file name
	}
	
	if($file =~ /\s*nvram_ltable.c$/gi)
	{  
		copyCode($file,0);
	}	
	if($file =~ /\s*nvram_gen_util.c$/gi)
	{
		copyCode($file,1);
	}
}
	
sub copyCode
{
	my ($file, $index) = @_;
	my $startflag = 0;

	open FILEHANDLE, "<$file" or die "couldn't open $file\n" && return $ERR_OPEN_FILE;
	
	while (<FILEHANDLE>) 
	{		
	    my $line = $_;
	        
	    chomp($line);
   
    if($line =~ /\s*.*Tool check begin: nvram_pre_gen.pl.*/g)
    {
    	$startflag = 1;
    	next;
    }
    
    if($startflag == 1)
    {
    	if($line =~ /\s*.*Tool check end: nvram_pre_gen.pl/g)
    	{
    		$startflag = 0;
    		last;
    	}
    	else
    	{
    		if($line !~ /\s*nvram_gen_backup.*/g )
    		{
	    		if($index ==1)
		    	{
			    	$gen_array[$genindex] = $line;
			    	$genindex++;
		    	}
		    	else
		    	{
		    		$tar_array[$tarindex] = $line;
			    	$tarindex++;
		    	}	    		  
    		}  
    		next;		
    	}   	
    }
  }
}  

sub WriteFile
{
    my ($strFilePath, $strContent) = @_;
    open FILE_HANDLE, ">$strFilePath" or  print "couldn't open $strFilePath\n" && return $ERR_OPEN_FILE;
    print FILE_HANDLE $strContent;
    close FILE_HANDLE;
}