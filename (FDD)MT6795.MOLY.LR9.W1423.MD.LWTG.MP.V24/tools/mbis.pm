#!/usr/bin/perl 
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2005
#
#  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
#  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
#  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
#  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
#  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
#  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
#  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
#  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
#  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
#  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
#  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
#  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
#
#  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
#  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
#  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
#  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
#  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
#
#  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
#  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
#  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
#  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
#  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
#
#
#*****************************************************************************
package tools::mbis;
BEGIN{ push @INC, "tools/perl"};
use MIME::Lite;
use File::Copy;
use Cwd;
use File::Basename;

# for export subroutines
use Exporter;
@ISA = qw(Exporter);
use vars qw(@EXPORT);
@EXPORT  = qw(&mbisLogCommand &mbisLogInfo &mbisLogTimeStamp &mergeLogFile &mbisPostProcess &writeTimeLogFromTempfile);

#*****************************************************************************
#              Global Variable Declaration and Initialization
#*****************************************************************************
my $file_server_folder;
my $mbis_config_ini;

if($^O eq "MSWin32") {
	if (!-d "modem/lte_sec"){
		$file_server_folder = "\\\\glbfs14\\sw_releases\\mbis\\moly\\un_processed\\";
		$mbis_config_ini = "\\\\glbfs14\\sw_releases\\mbis\\scripts\\MBIS_conf.ini";
	}else{ # in LTE domain
		$file_server_folder = "\\\\mtklwafs01\\mbis\\moly\\un_processed\\";
		$mbis_config_ini = "\\\\mtklwafs01\\mbis\\scripts\\MBIS_conf.ini";
	}
}
if($^O eq "linux") {
	$file_server_folder = "/moly/un_processed"; #/glbfs14/sw_releases/mbis/ is root
	$mbis_config_ini = "/mtkeda/wcpsm/mbis/config/mbis_conf.ini";
}

#*****************************************************************************
#   Function: mbisLogCommand
#   Argument:
#       (1) $mbis_enable:   mbis enable flag
#       (2) @argv:          original command (.bat) name + the arguments
#
#   Return: NONE
#   Description: log the original command and arguments into mbis info MBIS_BUILD_INFO_LOG.
#*****************************************************************************
sub mbisLogCommand{
    my ($mbis_enable, @argv) = @_;
    
    if ($mbis_enable){
        logToInfoFile ("COMMAND,make @argv");
    }
}



#*****************************************************************************
#   Function: mbisLogInfo
#   Argument:
#       (1) $mbis_enable:   mbis enable flag
#       (2) $info:          the info string
#
#   Return: NONE
#   Description: log the info message into MBIS_BUILD_INFO_LOG.
#*****************************************************************************
sub mbisLogInfo{
    my ($mbis_enable, $info) = @_;
    if ($mbis_enable){
        logToInfoFile ($info);
    }
}



#*****************************************************************************
#   Function: mbisLogTimeStamp
#   Argument:
#       (1) $mbis_enable:   mbis enable flag
#       (2) $info:          the info string
#
#   Return: NONE
#   Description: log the info message and timestamp into MBIS_BUILD_TIME_TMP.
#*****************************************************************************
sub mbisLogTimeStamp{
    my ($mbis_enable, $info) = @_;
    if ($mbis_enable){
        logToTimeStampTempFile ($info);
    }
}



#*****************************************************************************
#   Function: mergeFileIntoTempfile
#   Argument:
#       (1) $mbis_enable:   mbis enable flag
#       (2) $folder:        the *.mbis folder
#
#   Return: NONE
#   Description: merge the content of all the *.mbis files $dir into MBIS_BUILD_TIME_TMP.
#*****************************************************************************
sub mergeLogFile{
    my ($mbis_enable, $folder) = @_;
    if ($mbis_enable){
        opendir (DIR, $folder) or die "no folder : $folder";
        my @files = grep {/.+\.mbis/}  readdir DIR;
        close DIR;
        foreach my $file (@files){
            logFileIntoTimeStampTempFile("$folder/$file");
        }
    }
}



#*****************************************************************************
#   Function: mbisPostProcess
#   Argument:
#       (1) $mbis_enable:   mbis enable flag
#   Return: NONE
#   Description: rewrite MBIS_BUILD_INFO_LOG and MBIS_BUILD_TIME_LOG and add 
#                mbis process time info.
#*****************************************************************************
sub mbisPostProcess{
    my ($mbis_enable) = @_;
    if ($mbis_enable)
    {
      my $build_time_string = "";
      my $successful_build = 0;
      my $userID = "";
      my @info_list = ();
      my $bm_build = 0;
      my $transfer_file_name = "";
      my $machine = "";
      my $build_start_time = "";
      my $mbis_process_start_time;
      my $mbis_process_end_time;
      my $mbis_duration_time;
      my $total_process_start_time;
      my $total_process_end_time;
      my $total_duration_time;
      my $line;
      my $PID = "";
      my $sec;
      my $min;
      my $hour;
      my $mday;
      my $mon;
      my $year;
      my $path;
       
      $mbis_process_start_time = time;
      logToTimeStampTempFile("T_S,MBIS,M");
       
      # process the time log file
      &writeTimeLogFromTempfile($mbis_enable);
      
      # process the info log file
      open(FILEHANDLE, $ENV{MBIS_BUILD_INFO_LOG}) or die "can't open $ENV{MBIS_BUILD_INFO_LOG}!\n";
    
      foreach $line (<FILEHANDLE>){
          # for time end/start stamp
          $line =~ s/\s+$//;
          @info_list=split /,/, $line;
          if ($info_list[0] eq "SUCCESSFUL_BUILD")
          {
            $successful_build = $info_list[1];
          }
          elsif ($info_list[0] eq "USER") 
          {
            $userID = $info_list[1];
          }
          elsif ($info_list[0] eq "BM_BUILD")
          {
            $bm_build = $info_list[1];
          }
          elsif ($info_list[0] eq "BUILD_MACHINE")
          {
            $machine = lc($info_list[1]); 
          }
          elsif ($info_list[0] eq "BUILD_START_DATATIME")
          {
            $build_start_time = lc($info_list[1]);
          }
          elsif ($info_list[0] eq "PID")
          {
            $PID = sprintf("%8.8d",($info_list[1]));
          }
      }
      close(FILEHANDLE);
      
      $mbis_process_end_time = time;
      logToTimeStampTempFile("T_E,MBIS,M");
      logToTimeStampTempFile("T_E,TOTAL,A");
      
      # write the reformatted time log directly since parse the temp time log file already.
      $mbis_duration_time = $mbis_process_end_time - $mbis_process_start_time;
      logToTimeStampFile("MBIS,M,$mbis_process_start_time,$mbis_process_end_time,$mbis_duration_time");
      
      # get the start stampe for TOTAL to calculate the TOTAL time
      open(FILEHANDLE, $ENV{MBIS_BUILD_TIME_TMP}) or die "can't open  $ENV{MBIS_BUILD_TIME_TMP}!\n"; 
      foreach $line (<FILEHANDLE>){
          if($line =~ /^T_S,TOTAL,A,(.+)/){
              $total_process_start_time = trim($1);
              last;
          }
      }
      close(FILEHANDLE);

      # write the reformatted time log directly again.
      $total_process_end_time = time;	
      $total_duration_time = $total_process_end_time - $total_process_start_time;
      logToTimeStampFile("TOTAL,A,$total_process_start_time,$total_process_end_time,$total_duration_time");

      # Record build end_data_time
      ($sec, $min, $hour, $mday, $mon, $year) = localtime(time);
      $build_time_string = sprintf("%4.4d.%2.2d.%2.2d.%2.2d.%2.2d.%2.2d", $year+1900, $mon+1, $mday, $hour, $min, $sec);
      logToInfoFile("BUILD_END_DATATIME,$build_time_string");
      
      #if(($successful_build == 1) && ($bm_build == 1)){
      $transfer_file_name = $build_start_time  . "_" .  $machine . "_" . $PID;

      $dir_path = dirname($ENV{MBIS_BUILD_INFO_LOG});
      move($ENV{MBIS_BUILD_INFO_LOG}, "$dir_path/$transfer_file_name"."_mbis_info.log");
      move($ENV{MBIS_BUILD_TIME_LOG}, "$dir_path/$transfer_file_name"."_mbis_time.log");
      move($ENV{MBIS_BUILD_TIME_TMP}, "$dir_path/$transfer_file_name"."_mbis_time.tmp");
      $path = $ENV{MBIS_BUILD_INFO_LOG};
      $path =~ m/(.*)[\\\/](.+)/;
      if($^O eq "MSWin32")
      {
            $copy_result = system("robocopy  $1 $file_server_folder $transfer_file_name*.* /NJH /NJS /NDL /NFL /NP /R:3 /W:10");
            if (($copy_result >> 8) > 8){
              system("copy /y $1\\$transfer_file_name\_mbis_time.tmp $1\\$transfer_file_name\_mbis_time.tmp.log > nul");
              &notify_owner("$1\\$transfer_file_name\_mbis_info.log","$1\\$transfer_file_name\_mbis_time.log","$1\\$transfer_file_name\_mbis_time.tmp.log","$1\\mbis_updload.log");
            }
      }
      else
      {
        my $err_cnt = 0;
        my @mbis_logs = glob("$dir_path/*.*");
        if (!-d "modem/lte_sec"){
          $ftp_script = "/mtkeda/moly/bin/mtk-autoftp-mbis.sh";
        }else{ # in LTE domain
          $ftp_script = "/mtkeda/moly/bin/mtk-autoftp-lte-mbis.sh";
        }
        foreach my $log_file (@mbis_logs) {
          $copy_result = system("$ftp_script $log_file $file_server_folder > $dir_path/mbis_updload.log");
          $err_cnt ++ if($copy_result != 0);
        }
        if($err_cnt){
          copy("$1/$transfer_file_name\_mbis_time.tmp", "$1/$transfer_file_name\_mbis_time.tmp.log");
          &notify_owner("$1/$transfer_file_name\_mbis_info.log","$1/$transfer_file_name\_mbis_time.log","$1/$transfer_file_name\_mbis_time.tmp.log","$1/mbis_updload.log");
        }
      }
        #}
    } #if ($mbis_enable)
}

#*****************************************************************************
#   Function: writeTimeLogFromTempfile
#   Argument: NONE
#   Return: NONE
#   Description: calculate the time duration in MBIS_BUILD_TIME_TMP and rewrite 
#                into MBIS_BUILD_TIME_LOG file.
#*****************************************************************************
sub writeTimeLogFromTempfile{
    my ($mbis_enable) = @_;
    if ($mbis_enable){
        my @time_data;
        my $timestamp_type;
        my $item_name;
        my $item_type;
        my $item_timestamp;
        my %mbis_start_timetable;
        my %mbis_end_timetable;
        my @item_seq;
        my $last_item_name;
        my @mbis_end_timetable_key;
        my $item;
        my $item_start_time;
        my $item_end_time;
        my $item_duration_time;
        my $log_str;
        my $line;
    
        open(FILEHANDLE, $ENV{MBIS_BUILD_TIME_TMP}) or die "can't open $ENV{MBIS_BUILD_TIME_TMP}!\n";
        foreach $line (<FILEHANDLE>){
            $line =~ s/\s+$//;
            
            # do NOT process TOTAL and MBIS start timestamp because the end timestamp is not logged yet.
            if($line =~ /(^T_S,TOTAL,A)|(^T_S,MBIS,M)/){
                next;
            }
            
            if($line =~ /^(T_S|T_E),/){
                @time_data  = split (/,/ , $line);
                
                #T_S[0],emigen[1],T[2],1288539647[3]
                $timestamp_type = trim($time_data[0]);
                $item_name      = trim($time_data[1]);
                $item_type      = trim($time_data[2]);
                $item_timestamp = trim($time_data[3]);
                
                if ($timestamp_type eq "T_S"){
                    $mbis_start_timetable{$item_name} = "$item_type,$item_timestamp";
                    
                    # remember the item sequence
                    push(@item_seq, $item_name); 
                    
                    # special handling for $item_type = "O", keep the $item_name for next item comparsion
                    if ($item_type eq "O"){
                        $last_item_name = $item_name;
                    }   
                }
                else{ #$timestamp_type eq "T_E"
                    $mbis_end_timetable{$item_name} = "$item_type,$item_timestamp";
                    
                    # special handling for $item_type = "O", obj timestamp must side by side with T_S and T_E
                    if ($item_type eq "O"){
                        if ($last_item_name ne $item_name){
                            logWarning("[WARNING] Unexpect timestamp for object : $item_name");
                        }
                        $last_item_name = "";
                    }            
                }
            }
            elsif ($line =~ /^Time Stamp/){
        	   #ignore title
       	    }
       	    else{
       	         logWarning("[WARNING] Unexpect mbis log line : $line");
       	    }
        }
        close(FILEHANDLE);
        
        foreach $item_name(@item_seq){
            # $item = "$item_type,$item_name"          
            $item_start_time    = getItemTimeStamp($mbis_start_timetable{$item_name});
            $item_end_time      = getItemTimeStamp($mbis_end_timetable{$item_name});
            if (defined($item_end_time)){
                $item_duration_time = $item_end_time - $item_start_time;
                $item_type = getItemType($mbis_start_timetable{$item_name});
                
                # check if the item_type is match
                # still log the timestamp according to the start timestamp type
                if (getItemType($mbis_end_timetable{$item_name}) ne $item_type){
                     logWarning("[WARNING] Type mismatch for item : $item_name");
                }    
                
                # append to the log string
                #print "$item_name,$item_type,$item_start_time,$item_end_time,$item_duration_time\n";
                $log_str .= "$item_name,$item_type,$item_start_time,$item_end_time,$item_duration_time\n";
    
                # clean the value of $mbis_end_timetable{$item_name} for checking single T_E
                $mbis_end_timetable{$item_name} = undef;
            }
            else{
                # check if just T_S but no T_E
                logWarning("[WARNING] Single T_S of $item_name");
            }
        }
        
        # check if just T_E but no T_S
        @mbis_end_timetable_key = keys %mbis_end_timetable;
        foreach $item_name(@mbis_end_timetable_key){
            if (defined($mbis_end_timetable{$item_name})){
                logWarning("[WARNING] Single T_E of $item_name");
            }
        }
        
        # write the log string to the log file
        if (defined($log_str)){
            open(FILEHANDLE, ">$ENV{MBIS_BUILD_TIME_LOG}") or die "cannot open file for writing: $!";
            print FILEHANDLE "Item Name,Type,Start Time,End Time,Duration Time\n";
            print FILEHANDLE "$log_str";
            close(FILEHANDLE);
        }
    }#if ($mbis_enable)
}


#*****************************************************************************
#              Internal Subroutine Definition
#*****************************************************************************
sub logToInfoFile{
    open FILEHANDLE, ">>$ENV{MBIS_BUILD_INFO_LOG}";
    print FILEHANDLE "$_[0]\n";
    close FILEHANDLE;
}



sub logToTimeStampFile{
    open FILEHANDLE, ">>$ENV{MBIS_BUILD_TIME_LOG}";
    print FILEHANDLE "$_[0]\n";
    close FILEHANDLE;
}



sub logToTimeStampTempFile{
    my $datetime = time;
    open FILEHANDLE, ">>$ENV{MBIS_BUILD_TIME_TMP}";
    print FILEHANDLE "$_[0],$datetime\n";
    close FILEHANDLE;
}



sub logFileIntoTimeStampTempFile{
    my $file_path = $_[0];
    my $line;
    open FILEHANDLE, ">>$ENV{MBIS_BUILD_TIME_TMP}";
    open INPUT, $file_path or die "cannot open source file: $!";
    foreach $line (<INPUT>){
        print FILEHANDLE $line;
    }
    close INPUT;
    close FILEHANDLE;
}



sub logWarning{
    return 0;
#    open FILEHANDLE, ">>mbis_warning.log";
#    print FILEHANDLE "$_[0]\n";
#    close FILEHANDLE;
}



sub trim{
    if (defined($_[0])){
        my $item = $_[0];
        $item =~ s/(^\s+)|(\s+$)//g;
        return $item;
    }
    else{
        return undef;
    }
    
}



sub getItemTimeStamp{
    if (defined($_[0])){
        my $item = $_[0];
        $item =~ /(?:\w+),(\w+)/;
        return $1;
    }
    else{
        return undef;
    }
}



sub getItemType{
    if (defined($_[0])){
        my $item = $_[0];
        $item =~ /(\w+),\w+/;
        return $1;
    }
    else{
         return undef;
    }
}

sub notify_owner{
  if (!-e "$mbis_config_ini") {
  	  warn "Skip mbis log files. Build process is DONE.\n";
  	  exit 0;
  } 
  my %mbis_conf = iniToHash($mbis_config_ini);
  my $smtp = $mbis_conf{'NOTIFY_INFO'}->{'SMTP'};
  my $admin_email = $mbis_conf{'NOTIFY_INFO'}->{'MBIS_ADMIN_MAIL'};
  my $notify_owner_email = $mbis_conf{'NOTIFY_INFO'}->{'MBIS_NOTIFY_MAIL'};
  my $message_body="";
  
  print "Notify MBIS Service Owner...";  
	chomp(my $cwd = cwd());
	my ($infolog,$timelog,$infotmp,$upload_log) = @_;

  if(-e "$upload_log")
  {
    open (LOG_FILE, "<$upload_log") or warn "cannot open $upload_log!\n";
    $backup = $/;
    undef $/;
    $message_body = <LOG_FILE>;
    $/ = $backup;
    close LOG_FILE;
  }
  
  $msg = MIME::Lite->new(
    From    => $admin_email,
    To      => $notify_owner_email,
    Subject => '[MBIS Notify] MBIS log files upload Failed',
    Type    => 'multipart/mixed'
  );
  
  $msg->attach(Type  => 'auto',Path  => $cwd."/".$infolog,);
  $msg->attach(Type  => 'auto',Path  => $cwd."/".$timelog,);
  $msg->attach(Type  => 'auto',Path  => $cwd."/".$infotmp,);
  
  $msg->attach (
     Type => 'TEXT',
     Data => $message_body
  ) or warn "Error adding the text message part: $!\n";
  
  $msg->send('smtp', $smtp, Timeout => 60);
  print "Done\n"; 
}

sub iniToHash {
  open(MYINI, $_[0]);
  my %hash;
  my $hashref;

  while(<MYINI>)
  {
    next if ((/^\s*$/) || (/^\s*#/));
    if (/^\s*\[(.+)\]/)
    {
      $hashref = $hash{$1} ||= {};
    }
    elsif (/^\s*(\S+)\s*=\s*(.+)\s*$/)
    {
      $hashref->{$1} = $2;
    }
    elsif (/^\s*(\S+)\s*\+=\s*(.+)\s*$/)
    {
      $hashref->{$1} = $hashref->{$1} . " $2";
    }
  }

  close MYINI;
  return %hash;
}

1;
