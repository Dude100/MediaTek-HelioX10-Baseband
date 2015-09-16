#!/usr/bin/perl -w

#-------------------------------------------------------------------
#Tool version

$tool_version = 'v2.0';

#-------------------------------------------------------------------
#Parameters Configuration

$imm_file   = $ARGV[0];
$itcm_file  = $ARGV[1];
$dtcm_file  = $ARGV[2];
$log_file   = $ARGV[3];

#-------------------------------------------------------------------
# Replace '\' with '/'

$imm_file  =~ s/\\/\//g;  
$itcm_file =~ s/\\/\//g;
$dtcm_file =~ s/\\/\//g;
$log_file  =~ s/\\/\//g;

#-------------------------------------------------------------------

$debug_mode = 0;  # 0 or 1
$error_prefix   = 'AutoTCM Error:';
$warning_prefix = 'AutoTCM Warning:';
$nolist_keyword = 'NO_LIST';

#-------------------------------------------------------------------
# attribute keyword for TCM placement

$attribute_itcm    = '__attribute__ ((section("INTSRAM_ROCODE")))';
$attribute_dtcm_ro = '__attribute__ ((section("INTSRAM_RODATA")))';
$attribute_dtcm_rw = '__attribute__ ((section("INTSRAM_RW")))';
$attribute_dtcm_zi = '__attribute__ ((section("INTSRAM_ZI")))  __attribute__ ((zero_init))';

#-------------------------------------------------------------------
# Open log file
open (FILE_LOG,  ">>$log_file" ) or die (print "$error_prefix Can't open Auto-TCM-Attribute log file $log_file!\n");
print FILE_LOG "Auto TCM Attribute Tool $tool_version\n";

#-------------------------------------------------------------------
#Construct C file name
$c_file = $imm_file;
$c_file =~ s/.*\///;         # remove path part
print FILE_LOG "Source C   File : $c_file\n";
print FILE_LOG "Immediated File : $imm_file\n";

#-------------------------------------------------------------------
# Intialize some list as empty
%itcm_list  = ();
%dtcm_list  = ();
%added_code = ();

#-------------------------------------------------------------------
#Extract ITCM list

$itcm_list_num = &Extract_ITCM_List($itcm_file, $c_file);
 
if( $itcm_list_num > 0 )
{
   &Find_ITCM_List($imm_file);
}

#-------------------------------------------------------------------
#Extract DTCM list

$dtcm_list_num = &Extract_DTCM_List(($dtcm_file, $c_file));

if( $dtcm_list_num > 0 )
{
   &Find_DTCM_List($imm_file);
}

#-------------------------------------------------------------------
#Add __attribute__ code in source code

if( scalar(keys %added_code) > 0 )
{  
   my $backup = &Add_Attribute_Code( $debug_mode, $imm_file );
   print FILE_LOG "Backup Imm File : $backup\n";
   
}else
{     
   if( $itcm_list_num == 0 && $dtcm_list_num==0 )
   {
      print FILE_LOG "\t$c_file is not in TCM symbol lists.\n";

   }else
   {
      print FILE_LOG "\tNo TCM symbol is detected, but there are $itcm_list_num function and $dtcm_list_num variable in TCM symbol list.\n";
   }

}

#-------------------------------------------------------------------
#Close log file handle

print FILE_LOG "Done!\n";
print FILE_LOG "-----------------------------------------------------------\n";
close FILE_LOG;

#-------------------------------------------------------------------

#Parsing Done. 

exit 0;  #return 0 if it is successful

#-------------------------------------------------------------------

sub Extract_ITCM_List
{  
   my $list = $_[0];
   
   return 0 if( $list eq $nolist_keyword );
   
   my $search_file_1 = $_[1];
   my $search_file_2 = $search_file_1;
   $search_file_2 =~ s/\.c$/\.obj/;
   
   # Open TCM fucntions list file
   open (FILE_ITCM, "<$list" ) or &print_error_info_die("$error_prefix Can't open TCM function list file $list!\n");         

   while (<FILE_ITCM>)
   {  
      my $line_in =  $_;
      
      if( $line_in =~ /^\s*(\S+)\s*,?\s*($search_file_1|$search_file_2)\b/ )
      {      
         $itcm_list{$1} = 0;
      }   
   }

   close FILE_ITCM;

   return scalar(keys %itcm_list);
}

#-------------------------------------------------------------------

sub Extract_DTCM_List
{
   my $list = $_[0];
   
   return 0 if( $list eq $nolist_keyword );
   
   my $search_file_1 = $_[1];
   my $search_file_2 = $search_file_1;
   $search_file_2 =~ s/\.c$/\.obj/;
   
   # Open TCM variables list file
   open (FILE_DTCM, "<$list" ) or &print_error_info_die("$error_prefix Can't open TCM variable list file $list!\n");

   while (<FILE_DTCM>)
   {  
      my $line_in =  $_;
      
      if( $line_in =~ /^\s*(\S+)\s*,?\s*($search_file_1|$search_file_2)\b/ )
      {      
         $dtcm_list{$1} = 0;
      }   
   }
   
   close FILE_DTCM;
   
   return scalar(keys %dtcm_list);
}

#-------------------------------------------------------------------

sub Find_ITCM_List
{
   my $imm = $_[0];  #Input is immediate file
   
   # Open imm file, which is output of pre-processor
   open (FILE_IMM,  "<$imm" ) or &print_error_info_die("$error_prefix Can't open immediated file $imm!\n");

   my $line_in      = '';
   my $line_number  = 0;
   my $brace_l_cnt  = 0;  # left brace conter
   my $brace_r_cnt  = 0;  # right brace conter
   my $hited_target = undef;
   my $hited_lineno = undef;
 
   while( <FILE_IMM> )
   {
      $line_in = $_;
      $line_number++;
      
      next if($line_in =~ /^\#line/);
      next unless ( $line_in =~ /\S/ );
            
      $line_in =~ s/\".*?[^\\]\"/\"!!STRING!!\"/g;  # Replace string with spcial keyword
      
      if($brace_l_cnt == $brace_r_cnt)
      {
         foreach( keys %itcm_list )
         { 
            my $target = $_;
            
            if( $line_in =~ /\S+\s+\**$target\s*\(/ )
            {
               $hited_target = $target;  
               $hited_lineno = $line_number;
               last;      
            }
            
         }    
      }      
      
      if($hited_target && $line_in =~ /([{;])/ )
      {           
         if( $1 eq '{' )  # Function body is detected.
         {
            $itcm_list{ $hited_target }++;    # hit and increase hit counter
            $added_code{ $hited_lineno } = $attribute_itcm;
         }

         #if ';' is found first, it is only a function prototype                  
         
         $hited_target = undef;
                 
      }
        
      $brace_l_cnt += $line_in =~ tr/{//;  #count { number
      $brace_r_cnt += $line_in =~ tr/}//;  #count } number
      
   }

   my $number_hit_once  = 0;
   my $report_hit_once  ='';
   my $report_hit_miss  ='';
   my $report_hit_other ='';
   
   while( ($function, $hit_cnt) = each %itcm_list)
   {
      if( $hit_cnt == 1 )
      {
         $number_hit_once++;
         $report_hit_once  .= "\tTCM Function $function() is found.\n";
      
      }elsif( $hit_cnt == 0 )
      {
         $report_hit_miss  .= "\t$warning_prefix TCM Function $function() is missed.\n";
      
      }else
      {
         $report_hit_other .= "\t$warning_prefix TCM Function $function() is found $hit_cnt times.\n";
      }         
   }
   
   unless( $report_hit_miss  eq '' )
   {
      print          "$report_hit_miss";     
      print FILE_LOG "$report_hit_miss";
   }
   
   unless( $report_hit_other eq '' )
   {
      print          "$report_hit_other";
      print FILE_LOG "$report_hit_other";
   }
   
   if($number_hit_once>0)
   {
      #print FILE_LOG "$report_hit_once";
      print FILE_LOG "\t$number_hit_once TCM functions are found.\n";
   }
   
   if($brace_l_cnt != $brace_r_cnt)
   { 
      print          "\t$warning_prefix Left brace and right brace are not paried! { : }= $brace_l_cnt:$brace_l_cnt\n";
      print FILE_LOG "\t$warning_prefix Left brace and right brace are not paried! { : }= $brace_l_cnt:$brace_l_cnt\n";
   }
   
   close FILE_IMM;

}

#-------------------------------------------------------------------

sub Find_DTCM_List
{
   my $imm = $_[0];  #Input is immediated file
   
   # Open imm file, which is output of pre-processor
   open (FILE_IMM,  "<$imm"  ) or &print_error_info_die("$error_prefix Can't open immediated file $imm!\n");

   my $line_in      = '';
   my $line_number  = 0;
   my $brace_l_sum  = 0;  # left brace { conter 
   my $brace_r_sum  = 0;  # right brace } conter
   my $struct_hit    = 0;
   my $struct_lineno = 0;
   my $parentheses_tick_all = 0;  #number ( - number ) in all file
 
   while( <FILE_IMM> )
   {
      $line_in = $_;
      $line_number++;
      
      next if($line_in =~ /^\#line/);   # speed up parsing
      next unless ( $line_in =~ /\S/ ); # speed up parsing
      
      # Update {} counters
      my $brace_l_cnt = $line_in =~ tr/{//;  #count { number
      my $brace_r_cnt = $line_in =~ tr/}//;  #count } number        
      my $brace_tick_ori = $brace_l_sum - $brace_r_sum;
      my $brace_tick_new = $brace_tick_ori + ($brace_l_cnt - $brace_r_cnt);      
      $brace_l_sum += $brace_l_cnt;
      $brace_r_sum += $brace_r_cnt;
      
      my $parentheses_tick_line = ($line_in =~ tr/(//) - ($line_in =~ tr/)//);
      $parentheses_tick_all += $parentheses_tick_line;
      
      $line_in =~ s/\".*?[^\\]\"/\"!!STRING!!\"/g;  # Replace string with spcial keyword
      $line_in =~ s/{.*?}/{!!!!}/g;                 # Replace content inside {}
      
      if( $brace_tick_ori == 0 && !($line_in =~ /^\s*{/) ) # Only search global variable
      {
         if( $line_in =~ /\bstruct\b/ ) # Match "struct" keyword
         {
            $struct_hit = 1;
            $struct_lineno = $line_number;
               
            next if( $brace_r_cnt == 0); # next line if there is no }

         }elsif( $parentheses_tick_line==0 && $parentheses_tick_all==0 )
         {         
            foreach( keys %dtcm_list )
            { 
               my $target = $_;                              
               
               if(    $line_in =~ /(^|,)[^=]*\b$target\b.*[=;,]/    )   # variable name is matched but assignment is excluded
               {                                                                                      
                  unless(   ( $line_in =~ /\bextern\b/ )                            # extern is excluded.                  
                          ||( $line_in =~ /\S+\s+\**\w+\(.*$target.*\)\s*\;?\s*$/ ) # function parameter is excluded.  Ex: "void abc( int $target );" 
                        )
                  {                     

                     my $section = ($line_in =~ /\bconst\b.*$target/) ? $attribute_dtcm_ro : # It is RO data if include "const" keyword
                                   ($line_in =~ /=/                 ) ? $attribute_dtcm_rw : 
                                                                        $attribute_dtcm_zi ;

                     $dtcm_list{ $target }++;    # hit and increase hit counter
                     $added_code{ $line_number } = $section;
                     #last;
                  }
                                                   
               }#End of if()
               
            }#End of foreach()
         }         
      }      

      if( $struct_hit==1 && $brace_tick_new==0 && $brace_r_cnt>0 )
      {
         $struct_hit = 0;
                    
         foreach( keys %dtcm_list )
         {                         
            my $target = $_;                        
                        
            if ( $line_in =~ /\}.*\b$target\b/ )            
            {              
               #print "Struct \"$target\" is found in\n";
               #print "$line_in\n";

               my $section = ( $line_in =~ /\}.*=/ ) ? $attribute_dtcm_rw:$attribute_dtcm_zi;
               
               $dtcm_list{ $target }++;    # hit and increase hit counter
               $added_code{ $struct_lineno } = $section;
               #last;                              

            }
         }         
      }
      
   }
      
   my $number_hit_once  = 0;
   my $report_hit_once  ='';
   my $report_hit_miss  ='';
   my $report_hit_other ='';
   
   while( ($data, $hit_cnt) = each %dtcm_list )
   {
      if( $hit_cnt == 1 )
      {
         $number_hit_once++;
         $report_hit_once  .= "\tTCM Variable \"$data\" is found.\n";
      
      }elsif( $hit_cnt == 0 )
      {
         $report_hit_miss  .= "\t$warning_prefix TCM Variable \"$data\" is missed.\n";
      
      }else
      {
         $report_hit_other .= "\t$warning_prefix TCM Variable \"$data\" is found $hit_cnt times.\n";
      }         
   }
   
   unless( $report_hit_miss  eq '' )
   {  
      print          "$report_hit_miss";   
      print FILE_LOG "$report_hit_miss";
   }
   
   unless( $report_hit_other eq '' )
   {
      print          "$report_hit_other";
      print FILE_LOG "$report_hit_other";
   }
   
   if($number_hit_once>0)
   {
      #print FILE_LOG "$report_hit_once";
      print FILE_LOG "\t$number_hit_once TCM variables are found.\n";
   }
            
   
#   if($brace_l_sum != $brace_r_sum)
#   { 
#      print          "\t$warning_prefix Left brace and right brace are not paried! { : }= $brace_l_cnt:$brace_l_cnt\n";
#      print FILE_LOG "\t$warning_prefix Left brace and right brace are not paried! { : }= $brace_l_sum:$brace_r_sum\n";
#   }      
   
   close FILE_IMM;

}

#-------------------------------------------------------------------

sub Add_Attribute_Code
{
   my $debug    = $_[0];
   my $file_ori = $_[1];

   my $file_new = $file_ori;
   my $file_bak = $file_ori;
   $file_bak =~ s/\.c$/\.i/;

   rename $file_ori, $file_bak or &print_error_info_die("$error_prefix Can't rename $file_ori to $file_bak\n");
   
   open (FILE_IN,   "<$file_bak"  ) or &print_error_info_die("$error_prefix Can't open immediated file $file_bak!\n");
   open (FILE_OUT,  ">$file_new"  ) or &print_error_info_die("$error_prefix Can't open output file $file_new!\n");

   my $line_number = 0;
   my $line_in = '';
   my $log_on = 0;
   
   while( <FILE_IN> )   
   {
      $line_in = $_;
      $line_number++;
      
      if( exists $added_code{$line_number} )
      {
         my $added = $added_code{$line_number};
         print FILE_OUT "$added  ";
         
         if( $debug == 1 )
         {
            print FILE_LOG "$added  ";
            $log_on = 1;
         }
      }                  
      
      print FILE_OUT $line_in;
      
      if($log_on==1)
      {
         print FILE_LOG $line_in;

         if( $line_in =~ /[={\;]/ )
         {  
            $log_on= 0;
            print FILE_LOG "\n";
         }
      }
   
   }
  
   close FILE_IN;
   close FILE_OUT;
   
   return $file_bak;
}

#-------------------------------------------------------------------

sub print_error_info_die
{
   my $error_info = $_[0];
   print FILE_LOG $error_info;
   print STDERR   $error_info;
   exit(1);
  
}

#-------------------------------------------------------------------