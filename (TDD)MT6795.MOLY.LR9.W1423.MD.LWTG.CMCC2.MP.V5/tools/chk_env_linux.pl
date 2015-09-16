use strict;
use warnings;

my $chk_flag = $ARGV[0];
my $compiler = $ARGV[1];
my $wrong_ver_flag = 0;

print <<"__EOFUSAGE";
*******************************************
recommended Build Environment
*******************************************
* [OS]                : Linux
* [PERL]              : v5.10.1 or v5.14.2
* [MAKE]              : GNU Make v3.81
* [SHELL]             : GNU bash v4.1.5
* [GCC-ARM-NONE-EABI] : v4.6.2 or above
* [NATIVE GCC(UBUNTU)]: v4.5 or above

__EOFUSAGE

print "*******************************************\n";
print " Start checking current Build Environment  \n";
print "*******************************************\n";

#********************************************************************
# checking memory size
#********************************************************************
# $mem_size = `free -k | grep "Mem:" 2>&1`;
# if($mem_size =~ /.*?(\d+)\s+/i) {
# my $standard_mem = 2*1024*1024;
# if($1 >= $standard_mem) {
# print "* [MEMORY]    : $1  [OK] !!!\n";
# }else {
# print "* [MEMORY]    : $1  [LOWER THAN RECOMMENDED] !!!\n";
# $wrong_ver_flag = 1;
# }
# }


#********************************************************************
# checking perl version
#********************************************************************

my $perl_version = `perl --version | grep "This is perl" 2>&1`;
if($perl_version =~ /\bv5.14.2/i)
{
	print "* [PERL]              : v5.14.2            [OK] !!!\n";
}
elsif($perl_version =~ /\bv5.10.1/i)
{
	print "* [PERL]              : v5.10.1            [OK] !!!\n";
}
else
{
	if($perl_version =~ /.*?(v[\d\.]+)\s*/i)
	{
		print "* [PERL]              : $1            [NOT RECOMMENDED] !!!\n";
		$wrong_ver_flag = 1;
	}
	else 
	{
		print "* [PERL]              :                    [UNKNOWN VERSION] !!!\n";
		$wrong_ver_flag = 1;
	}
}


#********************************************************************
# checking GNU make version
#********************************************************************

my $make_version = `make --version | grep "GNU Make" 2>&1`;
if($make_version =~ /\b3.81/i)
{
	print "* [MAKE]              : GNU Make v3.81     [OK] !!!\n";
}
else
{
	if($make_version =~ /GNU\s*Make\s*([\d\.]+)\s*/i)
	{
		print "* [MAKE]              : GUN Make v$1     [NOT RECOMMENDED] !!!\n";
		$wrong_ver_flag = 1;
	}
	else
	{
		print "* [MAKE]              :                    [UNKNOWN VERSION] !!!\n";
		$wrong_ver_flag = 1;
	}

}

#********************************************************************
# checking shell version
#********************************************************************

my $shell_version = `bash --version | grep "GNU bash" 2>&1`;
my $shell_is_gnu = "false";
my $shell_number = "UNKNOWN";
my $recommend_number = "4.1.5";

if ($shell_version =~ /\bGNU bash/i) {
	$shell_is_gnu = "true";
} 
			
if ($shell_version =~ /\b$recommend_number/i) {
	$shell_number = $recommend_number;
} 
else 
{
	if ($shell_version =~ /.*?([\d\.]+)\s*/i) {
		$shell_number = $1;
	}
}

if ($shell_is_gnu eq "true" and $shell_number eq "$recommend_number"){
	print "* [SHELL]             : GNU bash v4.1.5    [OK] !!!\n";
}
else
{
	if ($shell_is_gnu eq "true") {
		if ($shell_number eq "UNKNOWN") {
			print "* [SHELL]             : GNU bash v[UNKNOWN VERSION NUMBER] !!!\n";			
		}
		my @tmp_bash_ver = split /\./,$shell_number;
		if (($tmp_bash_ver[0]<4) || ($tmp_bash_ver[0] == 4 && $tmp_bash_ver[1] < 1) || ($tmp_bash_ver[0] == 4 && $tmp_bash_ver[1] == 1 && $tmp_bash_ver[2] < 5)) 
		{
			print "* [SHELL]             : GNU bash v$shell_number    [LOWER THAN RECOMMENDED] !!!\n";
			$wrong_ver_flag = 1;
		}
		else 
		{
			print "* [SHELL]             : GNU bash v$shell_number    [HIGHER THAN RECOMMENDED] !!!\n";
	    }
	}
	else
	{
		print "* [SHELL]             :                   [UNKNOWN VERSION] !!!\n";
		$wrong_ver_flag = 1;
	
	}
}


#********************************************************************
# checking compiler version
#********************************************************************
# tools/GCC/4.6.2/linux/bin/arm-none-eabi-gcc  -mthumb --version
my @tmp = split (' ',$compiler);
my $compiler_location = $tmp[0];
my $compiler_is_existing = "true";

if (!-e $compiler_location) {
	print "* [GCC-ARM-NONE-EABI] : $compiler_location     [CANNOT FOUND] !!!\n";
	$wrong_ver_flag = 1;
	$compiler_is_existing = "false";
}
else
{
	my $compiler_version = `$compiler --version | grep "arm-none-eabi-gcc" 2>&1`;

	if ($compiler_version =~ /\b4.6.2/i)
	{
		print "* [GCC-ARM-NONE-EABI] : v4.6.2             [OK] !!!\n";
	}
	else {
		if($compiler_version =~ /.*?([\d\.]+)\s*/i) {
			my @tmp_ver = split /\./,$1;
			if (($tmp_ver[0]<4) || ($tmp_ver[0] == 4 && $tmp_ver[1] < 6) || ($tmp_ver[0] == 4 && $tmp_ver[1] == 6 && $tmp_ver[2] < 2)) {
				print "* [GCC-ARM-NONE-EABI] : v$1             [LOWER THAN RECOMMENDED] !!!\n";
				$wrong_ver_flag = 1;
			}else {
				print "* [GCC-ARM-NONE-EABI] : v$1             [HIGHER THAN RECOMMENDED] !!!\n";
			}
		}
		else
		{
			print "* [GCC-ARM-NONE-EABI] : [UNKNOWN VERSION] !!!\n";
			$wrong_ver_flag = 1;
		}
	}
}

#********************************************************************
# checking Ubuntu gcc version
#********************************************************************

my $gcc_version = `gcc --version | grep "gcc" 2>&1`;
chomp($gcc_version);
if($gcc_version =~ /4\.4\.3/i)
{
	print "* [NATIVE GCC(UBUNTU)]: $gcc_version  [OK] !!!\n";
}
else
{
	if($gcc_version =~ /4\.4/i)
	{
		print "* [NATIVE GCC(UBUNTU)]: $gcc_version  [NOT RECOMMENDED] !!!\n";
		$wrong_ver_flag = 1;
	}
	else 
	{
		print "* [NATIVE GCC(UBUNTU)]: $gcc_version  [OK] !!!\n";
	}
}

#********************************************************************
# un-expected version handle
#********************************************************************
if ($chk_flag eq "-chkenv" and $compiler_is_existing eq "false") {
		print "\nPlease install the GCC Cross-Compiler on correct path:\n";
		print "$compiler_location\n\n";
		exit(1);
}
if ($wrong_ver_flag == 1){
	print "\ncurrent Build Env. is not recommendation \nTo avoid unexpected errors , please install the recommended Tool Chain.\n";
	print "*******************************************\n";
	print "  Build Environment is NOT RECOMMENDED!\n";
	print "*******************************************\n\n";

}
else
{
	print "*******************************************\n";
	print "      Build Environment is ready!\n";
	print "*******************************************\n\n";
}
