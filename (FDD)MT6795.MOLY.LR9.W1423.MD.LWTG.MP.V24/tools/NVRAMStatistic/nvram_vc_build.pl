#!/usr/bin/perl -w

# Author: Chenxiang Zhao
# function: Create VC Debug enviornment of NvramAutoGen

$customer_folder = "";
$mmi_folder = "";
$vc_build_dir = "vc_build";
$is_vc_build_dir_exist = 1;
$nvram_dsp_name = "nvram_auto_gen";
$fsquota_dsp_name = "fs_quota";
$nvram_dsw_name = $nvram_dsp_name;
$compile_option = "";
$include_path = "";


$custom_option_pathname = "include\\custom_option.txt";
$custom_include_pathname = "include\\custom_include.txt";

#use this two func to init $customer_folder $mmi_folder
#and parse the custom_option.txt and custom_include.txt,convert the
#the defination of macro or inc to the format which VC knows.
#after call, both $compile_option and $include_path are initialized. 
parse_custom_option($custom_option_pathname);
parse_custom_include($custom_include_pathname);

$nvram_compile_option = $compile_option;
$nvram_include_path = $include_path;

$fsquota_compile_option = $compile_option;
$fsquota_include_path = $include_path;

$nvram_compile_option = $nvram_compile_option."/D \"NVRAM_AUTO_GEN\"\n";
$nvram_include_path = $nvram_include_path."/I \"..\\include\"\n";

$fsquota_compile_option = $fsquota_compile_option."/D \"BUILD_TIME_CHECK_GEN\"\n";
$fsquota_include_path = $fsquota_include_path."/I \"..\\..\\..\\custom\\common\\\"\n";

@compile_option_array = ($nvram_compile_option, $nvram_compile_option, $fsquota_compile_option);
@include_path_array = ($nvram_include_path, $nvram_include_path, $fsquota_include_path);

$nvram_src_list = "..\\src\\nvram_auto_gen.c\n";
$nvram_src_list = $nvram_src_list."..\\src\\nvram_gen_util.c\n";
$nvram_src_list = $nvram_src_list."..\\src\\operator_mmi_cache_wrapper.c\n";
$nvram_src_list = $nvram_src_list."..\\..\\..\\custom\\common\\$mmi_folder\\common_mmi_cache_config.c\n";
$nvram_src_list = $nvram_src_list."..\\..\\..\\custom\\app\\$customer_folder\\custom_mmi_cache_config.c\n";
$nvram_src_list = $nvram_src_list."..\\..\\..\\custom\\common\\$mmi_folder\\nvram_common_config.c\n";
$nvram_src_list = $nvram_src_list."..\\..\\..\\custom\\app\\$customer_folder\\nvram_user_config.c\n";
$nvram_src_list = $nvram_src_list."..\\..\\..\\custom\\app\\$customer_folder\\nvram_cust_pack.c\n";
$nvram_src_list = $nvram_src_list."..\\..\\..\\nvram\\src\\nvram_data_items.c\n";


$fsquota_src_list = "..\\src\\fs_quota_entry_dump.c\n";

#if add one new project, you need add two new var: xxx_dsp_name  xxx_src_list
#and you should add them to the following two array respectively.
@project_name_array = ($nvram_dsp_name, $fsquota_dsp_name);
@project_src_array = ($nvram_src_list, $fsquota_src_list);

#create vc build environment root dir
if (!-e $vc_build_dir) {
	$is_vc_build_dir_exist = 0;
}
else {
	if (!-d $vc_build_dir) {
		unlink $vc_build_dir || die "cannot delete file $vc_build_dir : $!";
		$is_vc_build_dir_exist = 0;
	}
}

if (!$is_vc_build_dir_exist) {
	mkdir $vc_build_dir || die "cannot create dir $vc_build_dir : $!";
}
else {
	chdir $vc_build_dir;
	unlink <*.*>;
	chdir "..\\";
}

#enter vc build dir
chdir $vc_build_dir;
create_vc_dsw($nvram_dsw_name, @project_name_array);


for ($i = 0; $i <= $#project_name_array; $i++)
{
#uncomment this to support one project in individual folder
=pod
	if (!$is_vc_build_dir_exist) {
		mkdir $project_name_array[$i] || die "cannot create dir $project_name_array[$i]";
	}
	else {
		if (!-e $project_name_array[$i] || (-e $project_name_array[$i] && !-d $project_name_array[$i])) {
			if (-e $project_name_array[$i]) {
				unlink $project_name_array[$i] || die "cannot delete file $project_name_array[$i] : $!";
			}
			mkdir $project_name_array[$i] || die "cannot create dir $project_name_array[$i] : $!";
		}
	}
	#enter each project folder
	chdir $project_name_array[$i];
=cut
	create_vc_dsp($project_name_array[$i],
		$compile_option_array[$i],
		$include_path_array[$i],
		$project_src_array[$i]);
	#leave this project folder
#	chdir "..\\";
}

#leave vc build dir
chdir "..\\";

exit(0);


#create_vc_dsp($name, $compile_option, $include_path, $src_list) $src_list consists of xx.c\nxxx.c\nxx.c\n 
sub create_vc_dsp {
	open(dspFile, ">$_[0].dsp") || die "cannot open $_[0].dsp : $!";
	print dspFile qq(# Microsoft Developer Studio Project File - Name="$_[0]" - Package Owner=<4>\n);
	print dspFile qq(# Microsoft Developer Studio Generated Build File, Format Version 6.00\n);
	print dspFile qq(# ** DO NOT EDIT **\n\n);
	
	print dspFile qq(# TARGTYPE "Win32 (x86) Console Application" 0x0103\n\n);
	
	print dspFile qq(CFG=$_[0] - Win32 Debug\n);
	print dspFile qq(!MESSAGE This is not a valid makefile. To build this project using NMAKE,\n);
	print dspFile qq(!MESSAGE use the Export Makefile command and run\n);
	print dspFile qq(!MESSAGE\n);
	print dspFile qq(!MESSAGE NMAKE /f "$_[0].mak".\n);
	print dspFile qq(!MESSAGE\n);	
	print dspFile qq(!MESSAGE You can specify a configuration when running NMAKE\n);
	print dspFile qq(!MESSAGE by defining the macro CFG on the command line. For example:\n);
	print dspFile qq(!MESSAGE\n);
	print dspFile qq(!MESSAGE NMAKE /f "$_[0].mak" CFG="$_[0] - Win32 Debug"\n);
	print dspFile qq(!MESSAGE\n);
	print dspFile qq(!MESSAGE Possible choices for configuration are:\n);
	print dspFile qq(!MESSAGE\n);
	print dspFile qq,!MESSAGE "$_[0] - Win32 Release" (based on "Win32 (x86) Console Application")\n,;
	print dspFile qq,!MESSAGE "$_[0] - Win32 Debug" (based on "Win32 (x86) Console Application")\n,;
	print dspFile qq(!MESSAGE\n\n);
	print dspFile qq(# Begin Project\n);
	print dspFile qq(# PROP AllowPerConfigDependencies 0\n);
	print dspFile qq(# PROP Scc_ProjName ""\n);
	print dspFile qq(# PROP Scc_LocalPath ""\n);
	print dspFile qq(CPP=cl.exe\n);
	print dspFile qq(RSC=rc.exe\n\n);
	
	print dspFile qq(!IF  "\$(CFG)" == "$_[0] - Win32 Release"\n\n);
	
	print dspFile qq(# PROP BASE Use_MFC 0\n);
	print dspFile qq(# PROP BASE Use_Debug_Libraries 0\n);
	print dspFile qq(# PROP BASE Output_Dir "..\\Release"\n);
	print dspFile qq(# PROP BASE Intermediate_Dir "..\\Release"\n);
	print dspFile qq(# PROP BASE Target_Dir ""\n);
	print dspFile qq(# PROP Use_MFC 0\n);
	print dspFile qq(# PROP Use_Debug_Libraries 0\n);
	print dspFile qq(# PROP Output_Dir "..\\Release"\n);
	print dspFile qq(# PROP Intermediate_Dir "Release"\n);
	print dspFile qq(# PROP Target_Dir ""\n);
	print dspFile qq(# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c\n);
	print dspFile qq(# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c\n);
	print dspFile qq(# ADD CPP @"$_[0].ini"\n);
	print dspFile qq(# ADD BASE RSC /l 0x804 /d "NDEBUG"\n);
	print dspFile qq(# ADD RSC /l 0x804 /d "NDEBUG"\n);
	print dspFile qq(BSC32=bscmake.exe\n);
	print dspFile qq(# ADD BASE BSC32 /nologo\n);
	print dspFile qq(# ADD BSC32 /nologo\n);
	print dspFile qq(LINK32=link.exe\n);
	print dspFile qq(# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386\n);
	print dspFile qq(# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386\n\n);
	print dspFile qq(!ELSEIF  "\$(CFG)" == "$_[0] - Win32 Debug" \n\n);	
	
	print dspFile qq(# PROP BASE Use_MFC 0\n);
	print dspFile qq(# PROP BASE Use_Debug_Libraries 1\n);
	print dspFile qq(# PROP BASE Output_Dir "..\\debug"\n);
	print dspFile qq(# PROP BASE Intermediate_Dir "..\\debug"\n);
	print dspFile qq(# PROP BASE Target_Dir ""\n);
	print dspFile qq(# PROP Use_MFC 0\n);
	print dspFile qq(# PROP Use_Debug_Libraries 1\n);
	print dspFile qq(# PROP Output_Dir "..\\debug"\n);
	print dspFile qq(# PROP Intermediate_Dir "..\\debug"\n);
	print dspFile qq(# PROP Target_Dir ""\n);
	print dspFile qq(# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c\n);
	print dspFile qq(# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c\n);
	print dspFile qq(# ADD CPP @"$_[0].ini"\n);
	print dspFile qq(# ADD BASE RSC /l 0x804 /d "_DEBUG"\n);
	print dspFile qq(# ADD RSC /l 0x804 /d "_DEBUG"\n);
	print dspFile qq(# ADD BSC32 /nologo\n);
	print dspFile qq(LINK32=link.exe\n);
	print dspFile qq(# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept\n);
	print dspFile qq(# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept\n\n);
	
	print dspFile qq(!ENDIF\n\n);

	print dspFile qq(# Begin Target\n\n);
	
	print dspFile qq(# Name "$_[0] - Win32 Release"\n);
	print dspFile qq(# Name "$_[0] - Win32 Debug"\n);
	my @src_array = split(/\n\s*/, $_[3]);
	foreach $one_src(@src_array) {
		print dspFile qq(# Begin Source File\n\n);
		
		print dspFile qq(SOURCE=$one_src\n);
		print dspFile qq(# End Source File\n);	
	}

	print dspFile qq(# End Target\n);
	print dspFile qq(# End Project\n);
	#make project ini file
	open(f_ini, ">$_[0].ini") || die "cannot create $_[0].ini or write it: $!";
	print f_ini $_[1];
	print f_ini $_[2];
	close(f_ini);
	close(dspFile);	
}

#create_vc_dsw($name, @project_name_array)
sub create_vc_dsw {
	my $dsw_file;

	(my $name, my @dsp_array) = @_;
	open($dsw_file, ">$name.dsw") || die "cannot open $name.dsw: $!";
	print $dsw_file qq(Microsoft Developer Studio Workspace File, Format Version 6.00\n);
	print $dsw_file qq(# WARNING: DO NOT EDIT OR DELETE THIS WORKSPACE FILE!\n\n);
	
	print $dsw_file qq(###############################################################################\n\n);

	for ($i = 0; $i <= $#dsp_array; $i++) {
		print $dsw_file qq(Project: "$dsp_array[$i]"=.\\$dsp_array[$i].dsp - Package Owner=<4>\n\n);
		print $dsw_file qq(Package=<5>\n);
		print $dsw_file qq({{{\n);
		print $dsw_file qq(}}}\n\n);
		
		print $dsw_file qq(Package=<4>\n);
		print $dsw_file qq({{{\n);
		print $dsw_file qq(}}}\n\n);
		
		print $dsw_file qq(###############################################################################\n\n);
		
	}
	print $dsw_file qq(Global:\n\n);
	print $dsw_file qq(Package=<5>\n);
	print $dsw_file qq({{{\n);
	print $dsw_file qq(}}}\n\n);
	
	print $dsw_file qq(Package=<3>\n);
	print $dsw_file qq({{{\n);
	print $dsw_file qq(}}}\n\n);
	
	print $dsw_file qq(###############################################################################\n\n\n);
	close($dsw_file);
}

#parse_custom_option($filename)
sub parse_custom_option {
	open(f_custom_option, "<$_[0]") || die "cannot open $_[0]: $!";
	my $first_line = <f_custom_option>;
	chomp $first_line;
	my @customer_folder_pair = split(/\s*=\s*/, $first_line);
	$customer_folder = $customer_folder_pair[1];
	my $second_line = <f_custom_option>;
	chomp $second_line;
	my @mmi_folder_pair = split(/\s*=\s*/, $second_line);
	$mmi_folder = $mmi_folder_pair[1];
	my $custom_option_line = "";
	while (<f_custom_option>) {
		$_ =~ s/\\/ /;
		$_ =~ s/\n/ /;
		$custom_option_line = $custom_option_line.$_;
		
	}
	my @vc_custom_option;
	@vc_custom_option = split(/\s*CUSTOM_OPTION\s*=\s*/, $custom_option_line);
	$compile_option = $vc_custom_option[1];
	$compile_option =~ s/\"\s+-D/\"\n-D/g;
	$compile_option =~ s/-D /\/D /g;
	$compile_option = $compile_option."\n";
	$compile_option =~ s/\/D\s*\"__MTK_TARGET__\"\s*\n//;
	close(f_custom_option);
}

#parse_custom_include($filename);
sub parse_custom_include {
	open(f_custom_include, "<$_[0]") || die "cannot open $_[0]: $!";
	my $custom_include_line = "";
	while (<f_custom_include>) {
		$_ =~ s/\n/ /;
		$custom_include_line = $custom_include_line.$_;
	}
	my @vc_custom_include;
	@vc_custom_include = split(/\s*CUSTOM_INC\s*=\s*/, $custom_include_line);
	$include_path = $vc_custom_include[1];
	$include_path =~ s/\"\s+-I/\"\n-I/g;
	$include_path =~ s/-I\s*/\/I /g;
	$include_path = $include_path."\n";
	close(f_custom_include);
}
