#!/usr/bin/perl
use Net::SMTP;
	
#********************************************************************
# Global Vars for mail notification
#********************************************************************
my $Sender = uc(getlogin());;
my $ToList = "MBJ06037".","."MBJ06026";
my $CcList = "";
my $smtp_server = "mtksmtp2.mtk.com.tw"; #172.21.100.20(192.168.160.24)
my $ts_name = $ENV{"COMPUTERNAME"};
my $user_domain = $ENV{"USERDOMAIN"};
my $load_path = `cd`;
chomp($load_path);
my $log = "build\\$ARGV[3]\\log\\chk_env.log";
my $log_flag = 0;
my $Flag = $ARGV[2];        
print "*******************************************\n";
print " Start checking MTK build environment......\n";
print "*******************************************\n";
#********************************************************************
# checking OS version
#********************************************************************
if($ENV{OS} eq "Windows_NT")
{
	print "OS is Windows 2000 or XP. => [OK]\n";
	
	if($Flag =~ /-customer/i){
	  $reading ="OS is Windows 2000 or XP. => [OK]\n";
	  if(-e "build\\$ARGV[3]\\log"){
            open (LOG, "> $log") or warn "cannot open $log\n";
            print LOG $reading;
            $log_flag =1;
          }
          else{
            warn "warning: There is no \\build folder.\n";
          }
        }
}
else
{
	if ($user_domain =~ /MBJ/i)
	{
		my $subject = "[$ts_name: Compile Enviroment error]";
		my $content = "Your OS should be Windows2000 or above!\n";
		#&SendEmailNotify($ToList, $CcList, $subject, $content);
	}
	print "Your OS should be Windows2000 or above!\n";
	exit(1);
}

#********************************************************************
# checking ARM installation path
#********************************************************************
	
#&USAGE() if ($#ARGV != 1);
my $makefile = "$ARGV[1]";
#my $Flag = $ARGV[2];

open(MAK,"<$makefile") or die "$!";
while(<MAK>)
{
	chomp;
	if(/^COMPILER\s*=\s*(\w+)+?/i)
	{
		#print $1;
		$compilerName = $1;
		if($compilerName =~ /RVCT/i)
		{
			print "Compiler in makefile is RVCT!\n";
			if(($Flag =~ /-customer/i) && ($log_flag == 1)){
			  $reading ="Compiler in makefile is RVCT!\n";
              print LOG $reading;
            }
			$rvctflag = 1;	##
			&ChkRVCTenv($makefile,$Flag);
		}
    elsif($compilerName =~ /GCC/i){
      print "Compiler check skip GCC!!\n";
      last;
    }
		else 
		{
			if ($Flag =~ /-customer/i)		# ADS check only for customers
			{
				&ChkADSenv($makfile,-customer);
			}
			elsif($Flag =~ /-internal/i)
			{
				print "Compiler in makefile is Not RVCT!!\n";
				last;
			}
		}
	}
}


#********************************************************************
# checking ARM compiler version & build number
#********************************************************************
sub ChkADSenv
{
	my $optiondir = "$ARGV[0]\\option.mak";
	open(OPTION,"<$optiondir");
	if (defined($ENV{ARMHOME}) && ($ENV{ARMHOME} =~ /program\sFiles/i))
	{
		$ENV{ARMHOME} =~ s/m\sFiles/~1/i;	
	}
	
	while(<OPTION>)
	{
		chomp;
		if(/DIR_ARM(\s*)=(\s*)(.*?ADSV1_2)+?/i)
		{
			my $arm_path = $3;
			if ( defined($ENV{ARMHOME}) &&  (lc($ENV{ARMHOME}) eq lc($arm_path)) )
			{
				print "ARM ADS installation path is correct. => [OK]\n";
				if($log_flag == 1){
				  $reading ="ARM ADS installation path is correct. => [OK]\n";
                  print LOG $reading;
                }
				last;
			}
			else
			{
				if ($user_domain =~ /MBJ/i)
				{
					my $subject = "[$ts_name: Compile Enviroment error]";
					my $content = "ARM installation path is inconsistent with the path defined in makefile[option.mak].\n" . 
									"Current ARM installation path: $ENV{ARMHOME}.\n" . 
									"In \"$optiondir\", ARM path is: $arm_path.\n" . 
									"\nThe different path will cause a compiling error!\n" . 
									"You should make them consistent\n";
					#&SendEmailNotify($ToList, $CcList, $subject, $content);
				} 
				print "ARM ADS installation path is inconsistent with the path defined in makefile[option.mak].\n";
				print "Current ARM installation path: $ENV{ARMHOME}.\n";
				print "In \"$optiondir\", ARM path is: $arm_path.\n";
				print "\nThe different path will cause a compiling error!\n";
				print "You should make them consistent\n";
				exit(1);
			}
		}
	}
	close(OPTION);	

	chdir ("$arm_path");
#**************************************************original
my $arm_compiler = 0;
foreach (split(/[\r\n]+/, `armcc -h 2>&1`))
{
	chomp;
	if(/\bADS1.2/i)
	{
		print "ARM version is correct. => [OK]\n";
		if(($Flag =~ /-customer/i) && ($log_flag == 1)){
		  $reading ="ARM version is correct. => [OK]\n";
          print LOG $reading;
        }
		if(/\bBuild(\s)*(\d+)/)
		{
			if($2 >= 848)
			{
				print "The build number of ARM ADS is correct. => [OK]\n";
				if(($Flag =~ /-customer/i) && ($log_flag == 1)){
				  $reading ="The build number of ARM ADS is correct. => [OK]\n";
                  print LOG $reading;
                }
				$arm_compiler = 1;
				last;
			}
			else
			{
				if ($user_domain =~ /MBJ/i)
				{
					my $subject = "[$ts_name: Compile Enviroment error]";
					my $content = "The build number of ARM should be at least 848!\n";
					#&SendEmailNotify($ToList, $CcList, $subject, $content);
				}
				print "The build number of ARM should be at least 848!\n";
				exit(1);
			}
		}		
	}
	else
	{
		next;
	}
}

if($arm_compiler == 0)
{
	if ($user_domain =~ /MBJ/i)
	{
		my $subject = "[$ts_name: Compile Enviroment error]";
		my $content = "ARM should be ARM1.2 [Build 848](above) or RVCT!\n";
		#&SendEmailNotify($ToList, $CcList, $subject, $content);
	} 
	print "ARM ADS should be ARM1.2 [Build 848](above) or RVCT!\n";
	exit(1);
}
}
#********************************************************************
# checking ARM license
#********************************************************************
unless ($ARGV[2] =~ /-customer/)
{
if ($ENV{"USERDOMAIN"} =~ /MBJ/i)
{
	my $arm_license = 0;
	my $arm_var_name = "ARMLMD_LICENSE_FILE";
	my @env_key = keys(%ENV);

	my $count = 0;
	foreach $_(@env_key)
	{
		if($_ =~ /$arm_var_name/i)
		{
			my @arm_var_value = split(";",$ENV{$_});
			for (my $i = 0; $i < @arm_var_value; $i++)
			{
				if ($ts_name =~ /^BJSTS\d\d$/i)
				{
					if (($arm_var_value[$i] =~ /^\s*C:\\Program Files\\ARM\\ADSv1_2\\licenses\\license\.dat$/i) ||
						($arm_var_value[$i] =~ /^\s*C:\\Progra~1\\ARM\\ADSv1_2\\licenses\\license\.dat$/i))
					{
						for (my $j = $i + 1; $j < @arm_var_value; $j++)
						{
							if ($arm_var_value[$j] =~ /^\s*8224\@bjslic01$/i)
							{
								print "ARM license setting is correct. => [OK]\n";
								$arm_license = 1;
								last;
							}
						}
					}
					if ($arm_license == 1)
					{
						last;
					}
					
				}
				else
				{
					if ($arm_var_value[$i] =~ /^\s*8224\@bjslic01$/i)
					{
						print "ARM license setting is correct. => [OK]\n";
						$arm_license = 1;
						last;
					}
				}
			}
	
			if ($arm_license == 0)
			{
				my $subject = "[$ts_name: Compile Enviroment error]";
				my $content = "Please checking your ARM license setting!\n";
				#&SendEmailNotify($ToList, $CcList, $subject, $content);
				print "Please checking your ARM license setting!\n";
				#exit(1);
				last;
			}
			else
			{
				last;
			}
	  	}
	  
		$count++;
		if($count == ($#env_key+1))
		{
			my $subject = "[$ts_name: Compile Enviroment error]";
			my $content = "Please checking your ARM license setting!\n";
			#&SendEmailNotify($ToList, $CcList, $subject, $content);
			print "Please checking your ARM license setting!\n";
			exit(1);
		}
	}
}
}
elsif ($ARGV[2] =~ /-customer/)
{
	my $arm_var_name = "ARMLMD_LICENSE_FILE";
	my @env_key = keys(%ENV);

	foreach $_(@env_key)
	{
		if($_ =~ /$arm_var_name/i)
		{          
			my $arm_para = $ENV{$_};
			if (($arm_para =~ /^\s*C:\\Program Files\\ARM\\ADSv1_2\\licenses\\license\.dat/i) ||
			($arm_para =~ /^\s*C:\\Progra~1\\ARM\\ADSv1_2\\licenses\\license\.dat/i))
			{         
				if (-e "C:\\Program Files\\ARM\\ADSv1_2\\licenses\\license\.dat")
				{
					print "License is existed!\n";
					if(($Flag =~ /-customer/i) && ($log_flag == 1)){
					  $reading ="License is existed!\n";
                      print LOG $reading;
                    }				
		 		}
		 		else
	   		{
      		print "License is not existed!\n";
      		if(($Flag =~ /-customer/i) && ($log_flag == 1)){
      		  $reading ="License is existed!\n";
              print LOG $reading;
            }
		 		}
		 	}
		 	else
		 	{
		 		print "C:\\Program Files\\ARM\\ADSv1_2\\licenses\\license\.dat is not existed!\n";
		 		if(($Flag =~ /-customer/i) && ($log_flag == 1)){
		 		  $reading ="C:\\Program Files\\ARM\\ADSv1_2\\licenses\\license\.dat is not existed!\n";
                  print LOG $reading;
                }
		 	}
		}
	}
}
#********************************************************************
# checking Active perl version
#********************************************************************
if($] >= 5.008006)
{
	print "Perl version is $] . => [OK]\n";
	if(($Flag =~ /-customer/i) && ($log_flag == 1)){
	  $reading ="Perl version is $] . => [OK]\n";
      print LOG $reading;
    }
}
else
{
	if ($user_domain =~ /MBJ/i)
		{
		my $subject = "[$ts_name: Compile Enviroment error]";
		my $content = "Perl version is too low.\n";
		#&SendEmailNotify($ToList, $CcList, $subject, $content);
	} 
	print "Perl version is not correct , please update to 5.8.6 \n";
	exit(1);
}

#********************************************************************
# checking shell(modification)
#********************************************************************
my @path = split(";",$ENV{"PATH"});

foreach my $path (@path)
{
	if(-d $path)
	{
		$path = "\"$path\""; 
		open(TEMPHANDLE,"<dir /B $path |");
		while(<TEMPHANDLE>)
		{
			chomp;			
			if($_ =~ /^sh\.exe\b/i)
			{
			    if ($user_domain =~ /MBJ/i)
                {
                    my $subject = "[$ts_name: Compile Enviroment error]";
	                my $content = "sh.exe founded in: $path\nplease remove it\n";
	                #&SendEmailNotify($ToList, $CcList, $subject, $content);
	            } 
				print "sh.exe founded in: $path\nplease remove it\n";
				if(($Flag =~ /-customer/i) && ($log_flag == 1)){
				  $reading ="sh.exe founded in: $path\nplease remove it\n";
                  print LOG $reading;
                }
				exit(1);
			}
		}
		close(TEMPHANDLE);
	}
}
print "Shell is cmd.exe. => [OK]\n";
if(($Flag =~ /-customer/i) && ($log_flag == 1)){
  $reading ="Shell is cmd.exe. => [OK]\n";
  print LOG $reading;
}

#********************************************************************
# checking Excel version
#********************************************************************
if ($ENV{"INLSF"} eq "")
{
	use Win32::OLE;
	my $excel = Win32::OLE->new('excel.Application');
	if($excel->version >= 9)
	{
		print "Excel version is 2000 or above. => [OK]\n";
		if(($Flag =~ /-customer/i) && ($log_flag == 1)){
		  $reading ="Excel version is 2000 or above. => [OK]\n";
          print LOG $reading;
        }
	}
	else
	{
		if ($user_domain =~ /MBJ/i)
		{
			my $subject = "[$ts_name: Compile Enviroment error]";
			my $content = "Your Excel should be 2000+!\n";
			#&SendEmailNotify($ToList, $CcList, $subject, $content);
		}
		print "Your Excel should be 2000+!\n";
		exit(1);
	}
}

#********************************************************************
# checking make.exe version
#********************************************************************
if ($ARGV[2] =~ /-customer/){
	open(tfile, "tools\\make.exe -v |") || die "Cannot open make.exe";
  while(<tfile>){
	  if($_ =~ /^\s*GNU\s*Make\s*(.*)/i){
		  $reading = $1;
		  if($reading == "3.81"){
		  	print LOG "make.exe version is ".$reading." [OK]\n";
		  }
		  else{
		  	print "ERROR : make.exe version $reading is wrong,please update to 3.81 !!\n";
		  	print LOG "ERROR : make.exe version(".$reading.") is wrong, please update it to 3.81 !!\n";
		  	exit(1);
		  }
	  }
	
  }
  close(tfile);
	
}

#********************************************************************
# checking MSYS version
#********************************************************************
if ($ARGV[2] =~ /-customer/){
	open(tfile, "tools\\MSYS\\bin\\make.exe -v |") || die "Cannot open make.exe";
  while(<tfile>){
	  if($_ =~ /^GNU\sMake\sversion\s(.*),/i){
		  $reading = $1;
		  if($reading == "3.79.1"){
		  	print LOG "tools\\MSYS\\bin\\make.exe version is ".$reading." [OK]\n";
		  }
		  else{
		  	print "ERROR : tools\\MSYS\\bin\\make.exe version $reading is wrong,please update to 3.79.1 !!\n";
		  	print LOG "ERROR : tools\\MSYS\\bin\\make.exe version(".$reading.") is wrong, please update it to 3.79.1 !!\n";
		  	exit(1);
		  }
	  }
	
  }
  close(tfile);
	
}

print "*******************************************\n";
print "      MTK build environment is ready!\n";
print "*******************************************\n";
close LOG;
sub SendEmailNotify
{
	my ($to_list, $cc_list, $mail_subject, $mail_content) = @_;
	my $msg = <<__EOFNOTIFY
To: $to_list
Cc: $cc_list
Subject: $mail_subject
From: $Sender

Dear All,

$mail_content

Best Regards,

__EOFNOTIFY
;
    my $smtp = Net::SMTP->new($smtp_server);
	$smtp->mail($Sender);
	map { $smtp->to($_); } split(/,/, $to_list);
	map { $smtp->cc($_); } split(/,/, $cc_list);
	$smtp->data($msg);
	$smtp->quit;
}


sub USAGE
{
  print <<"__EOFUSAGE";

USAGE: chk_env Option_MF_Path Project.mak <-build>
__EOFUSAGE
  exit 1;
}
#********************************************************************
# Subroutine
#********************************************************************
sub ChkRVCTenv
{
	my ($makefile,$flag) = @_;
	my $rvctversion = 0;
	my $path_569 = "C:\\Program Files\\ARM\\RVCT\\Programs\\3.1\\569_init\\win_32-pentium";
	open(MAK,"<$makefile") or die "$!";
	while(<MAK>)
	{
		chomp;
		if(/^RVCT_VERSION\s*=\s*(\w+)+?/i)
		{
			if($1 =~ /V31/i)
			{
					print "RVCT VERSION in makefile is correct!\n";
					if(($flag =~ /-customer/i) && ($log_flag == 1)){
					  $reading ="RVCT VERSION in makefile is correct!\n";
                      print LOG $reading;
                    }
					$rvctversion = 1;
			}
			else
			{
					print "RVCT VERSION in makefile is wrong!\n";
					if(($Flag =~ /-customer/i) && ($log_flag == 1)){
					  $reading ="RVCT VERSION in makefile is wrong!\n";
                      print LOG $reading;
                    }
					last;
			}
		}
	}
	close MAK;
	if ($rvctversion == 1)
	{
		if ($flag =~ /-internal/i)
		{
		if((exists $ENV{"RVCT31INC"})&&(exists $ENV{"RVCT31BIN"})&&(exists $ENV{"RVCT31LIB"}))
		{
#			system("pause");
			my $toolpath = $ENV{"RVCT31BIN"};
			#print $toolpath;
			my $chkarmccres = &ChkCompiler($toolpath,ARMCC,$flag);
			my $chktccres = &ChkCompiler($toolpath,TCC,$flag);
			my $chkarmlinkres = &Chkarmlink($toolpath,,$flag);
			  my $chkarmfromelf = ChkFromelf($toolpath,,$flag);
			  my $chkarmar = ChkArmar($toolpath,,$flag);
			if(-e $path_569){
			  print "Start to check ARM B569 :\n";
			  $reading ="Start to check ARM B569 :\n";
              print LOG $reading;
			  my $chkarmccres_569 = &ChkCompiler($path_569,ARMCC,$flag);
			  my $chktccres_569 = &ChkCompiler($path_569,TCC,$flag);
			  my $chkarmlinkres_569 = &Chkarmlink($path_569,,$flag);
              my $chkarmfromelf_569 = ChkFromelf($toolpath,,$flag);			  
              my $chkarmarres_569 = &ChkArmar($path_569,$flag);
			}
				if (($chkarmccres == 1)&&($chkarmlinkres == 1)&&($chktccres == 1)&&($chkarmfromelf==1)&&($chkarmar == 1)&&($chkarmccres_569 == 1)&&($chkarmlinkres_569 == 1)&&($chktccres_569 == 1)&&($chkarmarres_569 == 1)&&($chkarmfromelf_569==1))
				{
					print "ARM RVCT31 environment is correct!\n";	
				}
			}
		}
		elsif ($flag =~ /-customer/i)
		{
			my $toolpath = `cd`;
			my $chkarmccres = &ChkCompiler($toolpath,ARMCC,$flag);
			my $chktccres = &ChkCompiler($toolpath,TCC,$flag);
			my $chkarmlinkres = &Chkarmlink($toolpath,,$flag);
			my $chkarmfromelf = ChkFromelf($toolpath,,$flag);
			my $chkarmar = ChkArmar($toolpath,,$flag);
			
			if (($chkarmccres == 1)&&($chkarmlinkres == 1)&&(chktccres == 1)&&($chkarmfromelf==1)&&($chkarmar == 1))
			{
				print "ARM RVCT31 environment is correct!\n";	
				if($log_flag == 1){
				  $reading ="ARM RVCT3.1 environment is correct!\n";
                  print LOG $reading;
                }
			}
		}
		else
		{
			print "The Environment configuration is unmatched!\n";	
			if(($Flag =~ /-customer/i) && ($log_flag == 1)){
			  $reading ="The Environment configuration is unmatched!\n";
              print LOG $reading;
            }
		}
	}
}


sub ChkCompiler
{
	my ($path,$compiler,$flag_compiler) = @_; 
	my $arm_compiler = 0;
	chdir($path);
	
	if ($flag_compiler =~ /-customer/i)
	{
		foreach (split(/[\r\n]+/, `$compiler -h 2>&1`))
	  {
			chomp;
			#print $compiler;
			if(/\bRVCT3.1/i)
			{
			  print $compiler." version is RVCT3.1 [OK] , ";
		 		if(/\bBuild(\s)*(\d+)/)
 				{	
					if($2 >= 569)
					{
						print "Build number is $2 [OK] .\n";
						if($log_flag == 1){
						  $reading ="Build number is $2 [OK] .\n";
                          print LOG $reading;
                        }
						$arm_compiler = 1;
						&SetFlagFile(569,$load_path);
						last;
					}
				}	
			}			
			elsif(/\bRVCT4.0/i)
			{
				print $compiler." version is RVCT4.0 [OK] , ";
				if($log_flag == 1){
				  $reading =$compiler." version is RVCT4.0 [OK] ,\n";
                  print LOG $reading;
                }
			}
			else
			{
				print "ARMCC version is not RVCT3.1 or RVCT4.0\n";
				if($log_flag == 1){
				  $reading ="ARMCC version is not RVCT3.1 or RVCT4.0\n";
                  print LOG $reading;
                }
				last;	
			}
		}
	}
	elsif ($flag_compiler =~ /-internal/i)
	{
 		foreach (split(/[\r\n]+/, `$compiler -h 2>&1`))
 		{
 			chomp;
 			#print $_;
 			if(/\bRVCT3.1/i)
 			{
 				print $compiler." version is RVCT3.1 [OK] , ";
 				
 				if(/\bBuild(\s)*(\d+)/)
 				{
          if($2 == 569)
					{
						print "Build number is $2 [OK] .\n";
						$arm_compiler = 1;
						last;
					}
 					elsif($2 >= 1021)####
 					{
 						print "Build number is $2 [OK] .\n";
 						
 						$arm_compiler = 1;
 						last;
 					}
 					else
 					{
 						if ($user_domain =~ /MBJ/i)
 						{
 							my $subject = "[$ts_name: Compile Enviroment error]";
 							my $content = "The build number of ".$compiler." should be at least 1021!\n";
 							#&SendEmailNotify($ToList, $CcList, $subject, $content);
 						}
 						print "The build number of".$compiler." should be at least 1021!\n";
 						
 						exit(1);
 					}
 				}		
 			}
 			else
 			{
 				print "ARMCC version is not RVCT3.1\n";
 				
 				last;	
 			}
 		}
 	}
	return $arm_compiler;
}

sub ChkArmar
{
	my $armar = 0;
	my ($path,$flag_armar) = @_; 
	chdir($path);
		foreach (split(/[\r\n]+/, `armar -h 2>&1`))
		{	
			chomp;
			#print $_;
			if(/\bRVCT3.1/i)
			{
			print "ARMAR version is RVCT3.1 [OK] , ";
			if(($Flag =~ /-customer/i) && ($log_flag == 1)){
			  $reading ="ARMAR version is RVCT3.1 [OK] , ";
              print LOG $reading;
            }
			if(/\bBuild(\s)*(\d+)/)
			{
				if($2 >= 1021)####
				{
					print "Build number is $2 [OK] .\n";
					if(($Flag =~ /-customer/i) && ($log_flag == 1)) {
					  $reading ="Build number is $2 [OK] .\n";
                      print LOG $reading;
                    }
					$armar = 1;
					last;
				}
				else
				{
					print "The build number of ARMAR should be at least 1021! => [ERROR]\n";
					if(($Flag =~ /-customer/i) && ($log_flag == 1)) {
					  $reading ="The build number of ARMAR should be at least 1021! => [ERROR]\n";
                      print LOG $reading;
                    }
					#exit(1);
					last;
				}
			}		
			}
			else
			{
				print "ARMAR version is not RVCT3.1\n";
				if(($Flag =~ /-customer/i) && ($log_flag == 1)) {
				  $reading ="ARMAR version is not RVCT3.1\n";
                  print LOG $reading;
                }
				last;	
			}
		}
	return $armar;	
}

sub ChkFromelf
{
	my $arm_elf = 0;
	my ($path,$flag_elf) = @_; 
	chdir($path);
	if ($flag_elf =~ /-customer/i)		#customers
	{
		foreach (split(/[\r\n]+/, `fromelf -h 2>&1`))
		{	
			chomp;
			#print $_;
			if(/\bRVCT3.1/i)
			{
				print "FROMELF version is RVCT3.1 [OK] , ";
				if($log_flag == 1){
				  $reading ="FROMELF version is RVCT3.1 [OK] , \n";
                  print LOG $reading;
                }
				if(/\bBuild(\s)*(\d+)/)
				{
					if($2 >= 569)####
					{
						print "Build number is $2 [OK] .\n";
						if($log_flag == 1){
						  $reading ="Build number is $2 [OK] .\n";
                          print LOG $reading;
                        }
						$arm_elf = 1;
						last;
					}
				}
			}
		}
	}
	elsif ($flag_elf =~ /-internal/i)
	{
		foreach (split(/[\r\n]+/, `fromelf -h 2>&1`))
		{	
			chomp;
			#print $_;
			if(/\bRVCT3.1/i)
			{
			print "FROMELF version is RVCT3.1 [OK] , ";
			
			if(/\bBuild(\s)*(\d+)/)
			{
			    if($2 == 569)####
				{
					print "Build number is $2 [OK] .\n";
					$arm_link = 1;
					last;
				}
				elsif($2 >= 1021)####
				{
					print "Build number is $2 [OK] .\n";
					$arm_elf = 1;
					last;
				}
				else
				{
					if ($user_domain =~ /MBJ/i)
					{
						my $subject = "[$ts_name: Compile Enviroment error]";
						my $content = "The build number of FROMELF should be at least 1021!\n";
						#&SendEmailNotify($ToList, $CcList, $subject, $content);
					}
					print "The build number of FROMELF should be at least 1021!\n";
					exit(1);
				}
			}		
			}
			else
			{
				print "FROMELF version is not RVCT3.1\n";
				last;	
			}
		}
	}	
	return $arm_elf;
}

sub Chkarmlink
{
	my $arm_link = 0;
	my ($path,$flag_linker) = @_; 
	chdir($path);
	if ($flag_linker =~ /-customer/i)		#customers
	{
		foreach (split(/[\r\n]+/, `armlink -h 2>&1`))
		{	
			chomp;
			#print $_;
			if(/\bRVCT3.1/i)
			{
				print "ARMLINK version is RVCT3.1 [OK] , ";
				if(($Flag =~ /-customer/i) && ($log_flag == 1)){
				  $reading ="ARMLINK version is RVCT3.1 [OK] , ";
                  print LOG $reading;
                }
				if(/\bBuild(\s)*(\d+)/)
				{
					if($2 >= 569)####
					{
						print "Build number is $2 [OK] .\n";
						if(($Flag =~ /-customer/i) && ($log_flag == 1)){
						  $reading ="Build number is $2 [OK] .\n";
                          print LOG $reading;
                        }
						$arm_link = 1;
						last;
					}
				}
			}
		}
	}
	elsif ($flag_linker =~ /-internal/i)
	{
		foreach (split(/[\r\n]+/, `armlink -h 2>&1`))
		{	
			chomp;
			#print $_;
			if(/\bRVCT3.1/i)
			{
			print "ARMLINK version is RVCT3.1 [OK] , ";			
			if(/\bBuild(\s)*(\d+)/)
			{
                if($2 == 569)####
				{
						print "Build number is $2 [OK] .\n";
						
						$arm_link = 1;
						last;
					}

				elsif($2 >= 1021)####
				{
					print "Build number is $2 [OK] .\n";
					
					$arm_link = 1;
					last;
				}
				else
				{
					if ($user_domain =~ /MBJ/i)
					{
						my $subject = "[$ts_name: Compile Enviroment error]";
						my $content = "The build number of ARMLINK should be at least 1021!\n";
						#&SendEmailNotify($ToList, $CcList, $subject, $content);
					}
					print "The build number of ARMLINK should be at least 1021!\n";
					
					exit(1);
				}
			}		
			}
			else
			{
				print "ARMLINK version is not RVCT3.1\n";
				last;	
			}
		}
	}	
	return $arm_link;
}

sub SetFlagFile
{
	my($buildNo,$path) = @_;
#	print "buildno= $buildNo";
	my $file = "$path\\tools\\RVCTBuildNo.tmp";
#	print "file =$file\n";
	open (FH,">$file") or die "$!";
	print FH "RVCT_CUS_BUILD_NO = ".$buildNo;
	close FH;
}
