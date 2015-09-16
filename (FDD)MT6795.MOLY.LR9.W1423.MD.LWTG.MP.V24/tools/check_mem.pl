my ($lis_exist,$platform,$check_g)=&ParseCmdlineInput(@ARGV);
my $DEBUG = 0;
my ($M_flag,$M_start_add,$M_size,$G_flag,$G_start_add,$G_size) = &ParseInputFile($lis_exist,$check_g);
my $Result_m='';
my $Result_g='';

print "$lis_exist !!\n" if ($DEBUG);
print $M_flag,"\n" if ($DEBUG);
print $G_flag,"\n" if ($DEBUG);


if ($M_flag)
{
	$Result_m = CheckBound($M_start_add,$M_size,$platform);
	
	print "result_m=$Result_m\n" if ($DEBUG);
	
	if ($Result_m)
	{
		print "med_ext-mem exceeds the boundary!\n";
		die;
	}
}
else
{
	print "Skip med_ext_mem memory boundary check!\n";	
}

if ($G_flag)
{
	$Result_g = CheckBound($G_start_add,$G_size,$platform);	
	
	print "result_g=$Result_g\n" if ($DEBUG);
	
	if ($Result_g)
	{
		print "g_applib_mem_ap_pool exceeds the boundary!\n";
		die;
	}
}
else
{
	print "Skip g_applib_mem_ap_pool memory boundary check\n";	
}


sub ParseCmdlineInput
{
	my $partfile = '';
	my $Platform = '';
	my $Check_flag = '';
	my @argv = @_;
	($#argv < 0) && &Usage;
	while($#argv!=-1)
	{
		print $argv[0],"\n" if ($DEBUG);
		if(-e $argv[0])	
		{
			$partfile = $argv[0];
		}
		else
		{
			print "The lis file is not existed!";
			die;
		}
		$Platform = $argv[1];
		$Check_flag = $argv[2];
		last;
	}
	return ($partfile,$Platform,$Check_flag);
}

sub ParseInputFile
{
	my ($input_file,$chk_g) =@_;
	my $m_start_add='';
	my $m_size='';
	my $g_start_add='';
	my $g_size='';
	my $m_flag = '';
	my $g_flag = '';
	
	print "Start to check memory boundary from input file: \n$input_file\n";
	open INPUT, "<$input_file" or die "cannot open $input_file";
	while(<INPUT>)
	{
		if (/(med_ext_mem)\s+(0\w+)\s+(\b.*?)\s+([0-9]+)\s+([^\s]+)/)
		{
			$m_start_add = $2;
			$m_size = $4;
			$m_flag = 1;
			print "m_start_add=$m_start_add\n" if ($DEBUG);	
			print "size =$m_size\n" if ($DEBUG);
			next;
		}
		elsif (/(g_applib_mem_ap_pool)\s+(0\w+)\s+(\b.*?)\s+([0-9]+)\s+([^\s]+)/)
		{
			$g_start_add = $2;
			$g_size = $4;
			$g_flag = 1;
			print "g_start_add=$g_start_add\n" if ($DEBUG);	
			print "size =$g_size\n" if ($DEBUG);
			last;
		}	
	}
# &Check_bound();
	close INPUT;
	
	if (($chk_g)&&($g_flag))
	{
		$g_flag = 1;
		$m_flag = 0;
	}
	elsif ((!$chk_g)&&($m_flag))
	{
		$g_flag = 0;
		$m_flag = 1;
	}
	return ($m_flag, $m_start_add,$m_size,$g_flag,$g_start_add,$g_size);
}

sub CheckBound
{
	my ($start_add,$size,$plat)=@_;	
	print "start_add=$start_add\n" if($DEBUG);
	print "plat=$plat\n" if($DEBUG);
	my $result1 = '';
	my $result2 = '';
	my $add = '';
	my $basic ='';
	my $test ='';
	$start_add=hex($start_add);
	if ($plat =~ /(622\w+)|(6235)/i) #
	{
		$basic = 0x01000000;	
	}
	elsif ($plat =~ /(6238)|(6268)|(6516)|(6236)/i)
	{
		$basic = 0x04000000;  #"67108864";	
	}
	else
	{
		print "The platform not exist in ";	
	}
	
	#$basic=hex($basic);
	print "basic=$basic\n" if($DEBUG);
	$result1 = int($start_add / $basic);
	$add = $start_add + $size;
	$result2 = int($add / $basic);
	$basic1 = $basic;
	
	print "start_add=$start_add\n" if($DEBUG);
	print "basic1=$basic1\n" if($DEBUG);
	print "Result1=$result1\n" if($DEBUG);
	print "add=$add\n" if($DEBUG);
	print "Result2=$result2\n" if($DEBUG);
	print "size=$size\n\n" if($DEBUG);
	#chomp($result1);
	#chomp($result2);
	if ($result1 eq $result2)
	{
		return 0;	
	}
	else
	{
		return 1;
	}
}