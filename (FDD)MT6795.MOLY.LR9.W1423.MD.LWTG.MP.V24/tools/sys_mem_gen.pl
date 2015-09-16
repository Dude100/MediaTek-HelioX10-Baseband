######
#
#       Filename:  sys_mem_gen.pl
#       Author: jianming fan
#       Data 2011-05-22
#
#       Interface:   
#           (flag sys_mem est_mem debug_mem int_mem, all_logs) = &Build_time_caculate_memory(syscomp_config.o)
#           flag is 1 if ok; flag is 0 if failed.
#           flag is 1 if ok; flag is 0 if failed.
#
#       @Interface change:
#           perl sys_mem_gen.pl  "obj_name under mcu folder"  "BB chip folder path"  "platform"  "log dir path"
#           return 0 if ok; else fail.
#           
#       @example
#           perl sys_mem_gen.pl syscomp_config_modis.o  custom\system\sparrow51\  TRUE  build\xx\log
#           perl sys_mem_gen.pl syscomp_config.o  custom\system\sparrow51\  FALSE build\xxx\log
#            
#       Other behavior:
#       Besides, the script will write all_logs into build\XXX_chip\log\sys_mem_log.log.
#       If write log fail, the script just keeps silen. 
#       The temp file generated for the script are syscomp_config.o symbols.log section.log at mcu root.
#       They will be deleted regardless whether Build_time_caculate_memory returns false or true.
#
#       History: 
#       2011-10-21
#       sys_mem_gen enhancement for stack isolation: 
#       1.remove this code ->(sub task_stack_common_plus overhead for tasks which stack size is larger than 8k);
#       2.remove this code ->(add 10K for nvram temp allocate);
#       2011-10-20
#       sys_mem_gen enhancement for stack isolation: 
#       1.remove workaround code; 
#       2.adjust small objects and big objects;
#       3.sub task_stack_common_plus overhead for tasks which stack size is larger than 8k;
#       4.add 10K for nvram temp allocate;
#       2011-09-16
#       stack isolation modifify sys mem gen
#       2011-08-17
#       Meaningfull fatal code string to users
#       2011-07-06
#       interface change to optimize build flow with po hu, Amber su and Qmei yang
#       enlarge timer quota 2011-06-01
#       2011-06-03
#       1) remove tmp files syscomp_config_modis.log
#       2) sys_mem_gen_modis.log
#       2011-06-16
#       reduce timer quato for ulc project
#       3)
#
#####

#  kal_hisr should be fixed to be one byte
#!/usr/bin/perl
BEGIN { push @INC,  './tools/' }  # add additional library path
use warnings;
use strict;
use FileInfoParser;

################ I: caculate task resource
#
#caculate task/hisr resource
#typedef struct {
#   kal_char             *comp_name_ptr;
#   kal_char             *comp_qname_ptr;
#   kal_uint32           comp_priority;
#   kal_uint32           comp_stack_size;
#   kal_create_func_ptr  comp_create_func;
#   kal_bool             comp_internal_ram_stack;
#   kal_uint8            comp_ext_qsize;
#   kal_uint8            comp_int_qsize;
#   kal_uint8            comp_boot_mode;
#} comptask_info_struct;
#

#define the error code
my ($ERR_OK, $ERR_OPEN_OBJ,$ERR_PARSE_OBJ,$ERR_GET_TASK_SYM,
    $ERR_GET_HISR_SYM , $ERR_GET_BUF_SYM, $ERR_GET_BUF_SYM2, 
    $ERR_GET_BUF_SYM3, $ERR_GET_MODULE, $ERR_WRITE_FILE, 
    $ERR_ARGV, $ERR_READELF_TOOL, $ERR_SYMNOT_EXIST, 
    $ERR_HISR_INDEX, $ERR_DUPLICATE_TASK_PRIORITY, $ERR_DUPLICATE_HISR_INTID) 
    = 0..15;

my @err_code_meaning = ("OK", 
                        "open sys_comp_config.o file fail", 
                        "parse file fail", 
                        "parse task symbol fail",
                        "parse hisr symbol fail", 
                        "parse control buffer symbol fail", 
                        "parse data buffer symbol fail",
                        "parse event buffer symobl fail", 
                        "pass module typde symbol fail", 
                        "write file fail", "argu fail",
                        "tool\\MinGw\\bin\\arm_none_eabi_readelf tool absent",
                        "symbol in symbols not exist",
                        "error hisr index",
                        "error : duplicate task priority",
                        "error : duplicate hisr INTID");
                 
#the following symbols are from config\src\syscomp_config.c
my @symbols=qw/sys_comp_config_tbl 
               hisr_info
               cfg_ctrl_buff
               cfg_data_buff
               cfg_event_buff 
               cfg_module_number
               sys_internal_ram_defined
               debug_buf2
               cfg_low_cost_support
               cfg_3G_FSM
               cfg_task_info_g_size
               cfg_task_cb_size
               cfg_hisr_cb_size
               cfg_ext_queue_head
               cfg_ilm_struct
               cfg_max_custom_tasks
               cfg_kal_queue_stat_type
               cfg_no_create_task
               cfg_ctrl_buff_overhead
               cfg_pool_cb_size
               cfg_pool_stat_size
               cfg_nu_buff_overhead
               cfg_normal_mode
               cfg_buff_stat
               cfg_gemini
               page_size
               stack_isolation
               task_stack_common_plus
               cfg_factory_mode
               cfg_usb_mode
               cfg_int_buff_callstack
               cfg_hisr_priority_max
               hisr_intid_g
               hisr_intid_map_size/;
my @symbols_offset;
my @symbols_size;

####Stack isolation's requirement on sys_mem_gen.
#    Stack will be aligned to page size (4KB on ARM11, 1KB on ARM9)
#    so there will be a lot of space left because of alignment!
#    Then small objects will be dumped into the gaps.
#    
#    Accordingly, all elements are categoried into stack, small obj, and big obj!
#    For now, control block of task/hisr/ext queue, dynamic obj belongs to small obj
#    queue, buffers, module_ilm_g, task_info_g belongs to big obj

#    the formula:
#    the total sysgem memory size for stack isolation is:
#    $big_object_size + $g_aligned_stack_size + 
#    max ( ($g_small_objects_size - ($g_aligned_stack_size - $g_actual_stack_size)), 0 )

my $g_small_objects_size = 0;
my $g_big_objects_size = 0;
my $g_actual_stack_size = 0;
my $g_aligned_stack_size = 0;
my $g_stack_no_aligned = 0;
my $g_bDefinedKtest = 0;
my $g_ATEST_DRV_ENABLE = 0;
my $g_total_no_created_task = 0;
#debug

#HISR shared stack begin
my $g_hisr_shared_iram_stack_size = 0;
#HISR shared stack end

print $^O;

if (@ARGV != 5)
{
    print "Error: $0 error code $ERR_ARGV $err_code_meaning[$ERR_ARGV]\n";
    exit $ERR_ARGV;
}

my $file = $ARGV[0]; 
my $outputpath = $ARGV[1]; 
my $platform = $ARGV[2]; 
my $logpath = $ARGV[3];
my $infomake_path = $ARGV[4];
#debug
print "[Info]: bb chip folder $outputpath\n";

if(-e $infomake_path)
{
    my %CmplOption;
    my %relOption;

    BuildInfo::Parse_InfoMakeLog($infomake_path,\%CmplOption,\%relOption);
    if( BuildInfo::exist(BuildOPT::CMPL, "__KTEST__"))
    {
        $g_bDefinedKtest = 1;
    }
    else
    {
        $g_bDefinedKtest = 0;
    }
    if( BuildInfo::exist(BuildOPT::CMPL, "ATEST_DRV_ENABLE"))
    {
        $g_ATEST_DRV_ENABLE = 1;
    }
    else
    {
        $g_ATEST_DRV_ENABLE = 0;
    }
}
else
{
    print "paremeter is wrong: info.log.\n";
    exit $ERR_ARGV;
}

my ($flag, $sys_mem, $est_mem, $debug_mem, $int_mem, $all_logs) =
&Build_time_caculate_memory($file, $outputpath);

if ($flag == $ERR_OK)
{
    if ($platform eq "TRUE")
    {
        $platform = "modis";
    }
    else
    {
        $platform = "target";
    }

    if (&output_file($sys_mem, $est_mem, $debug_mem, $int_mem, $all_logs, $outputpath, $platform, $logpath) != 0)
    {
        print "Error: $0 error code $ERR_WRITE_FILE $err_code_meaning[$ERR_WRITE_FILE]\n";
        exit $ERR_WRITE_FILE;
    }
    else
    {
       exit $ERR_OK;
    }
}
else
{
    print "Error: $0 error code $flag $err_code_meaning[$flag]\n";
    exit $flag;
}

sub copyright_file_header
{
    my $template = <<"__TEMPLATE";
/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
__TEMPLATE

   return $template;
}

sub file_descriptor 
{
     my $filename = shift;

     my $template = <<"__TEMPLATE";
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  $filename 
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contain definition of custom component module configuration variables, and routines
 *
 * Author:
 * -------
 *   jianming Fan (mtk80457)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * \$Revision\$
 * \$Modtime\$
 * \$Log\$
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
__TEMPLATE

   return $template;
}

sub header_file_head
{
    my $platform = shift;

    if ($platform eq "modis")
    {
        my $template = <<"__TEMPLATE";
#ifndef __SYS_MEM_SIZE_MODIS_H__
#define __SYS_MEM_SIZE_MODIS_H__
__TEMPLATE
        return $template;
    }
    else
    {
        my $template = <<"__TEMPLATE";
#ifndef __SYS_MEM_SIZE_H__
#define __SYS_MEM_SIZE_H__
__TEMPLATE
        return $template;
    }
}

sub output_file
{
    my $accurate_sys_mem = shift;
    my $estimate_sys_mem = shift;
    my $debug_mem_size = shift;
    my $intram_size = shift;
    my $all_logs = shift;
    my $outurl = shift;
    my $platform = shift;
    my $logpath = shift;
    my $filename;
    my $logfilename;
    my $ret;

    if ($platform eq "modis")
    {
        $filename = "sys_mem_size_modis.h";
        $logfilename = "sys_mem_gen_stat_modis.log";
    }else
    {
        $filename = "sys_mem_size.h";
        $logfilename = "sys_mem_gen_stat.log";
    }

    my $copyright = &copyright_file_header();
    my $descript = &file_descriptor($filename);
    my $head = &header_file_head($platform);   
    my $template = <<"__TEMPLATE";
$copyright

$descript

$head
/* GLOBAL_MEM_SIZE = accurate_sys_mem + estimate_sys_mem. 
 * estimate_sys_mem  is for timer, event group, sem created at run time.
 * You may modify the estimate_sys_mem to meet you own need
 */
    #define GLOBAL_MEM_SIZE                     ($accurate_sys_mem + $estimate_sys_mem)
    #define GLOBAL_DEBUG_MEM_SIZE               ($debug_mem_size)
    #define GLOBAL_HISR_SHARED_IRAM_STACK_SIZE  ($g_hisr_shared_iram_stack_size)
    #define GLOBAL_TOTAL_CREATED_TASK_NUMBER    ($g_total_no_created_task)
#endif  
__TEMPLATE
    
    my $tempath;
    if ( $^O eq "MSWin32" )
    {
        $tempath = ">$outurl\\$filename";
    }
    else
    {
        $tempath = ">$outurl\/$filename";
    }
        
    if (open(SYS_MEM_SIZE_H, $tempath))
    {
        print SYS_MEM_SIZE_H $template;
        close SYS_MEM_SIZE_H;
        $ret = 0;
    }
    else
    {
        $ret = -1;
    }
    
    # The log file is for statistics
    $all_logs.="sys_mem:".
    $accurate_sys_mem."\t"."estimate sys mem:".
    $estimate_sys_mem."\t"."debug_mem_size:".
    $debug_mem_size."\t"."int ram size:".$intram_size."\n";

    if ( $^O eq "MSWin32" )
    {
        $tempath = ">$logpath\\$logfilename";
    }
    else
    {
        $tempath = ">$logpath\/$logfilename";
    }
        
    if (open (SYS_MEM_LOG, $tempath))
    {
        print SYS_MEM_LOG  $all_logs;
        close SYS_MEM_LOG;
    }

    return $ret;
}


#input: syscomp_config.o path. 
#return (flag sys_mem est_mem debug_mem int_mem, all_logs)
#other output: log file in build\log\sys_mem_gen.log
sub  Build_time_caculate_memory
{

    my $object_file = shift;
    my $outurl = shift;

    #open the syscomp_config.o file
    if(!open DF, "<", $object_file)
    {
        return ($ERR_OPEN_OBJ, undef, undef, undef, undef, undef);
    }
    binmode DF;
    my $syscomp_fh = *DF;

    my $sys_mem_size = 0;
    my $sys_mem_size_factory = 0;
    my $sys_mem_size_usb = 0;
    my $intram_size = 0;
    my $debug_mem_size = 0;
    my $estimate_sys_mem = 0; 
    my $estimate_sys_mem_factory = 0; 
    my $estimate_sys_mem_usb = 0; 

## hard code here
    my $int_queue_head_size = 20;
## the follwing parameter are from syscomp_config.o
    my $ext_queue_head_size;
    my $ext_queue_entry_size;
    my $int_queue_entry_size;
    my $task_cb_size;
    my $hisr_cb_size;
    my $MAX_CUSTOM_TASKS;
    my $kal_queue_stat_type;
    my $ctrl_buff_overhead;
    my $pool_cb_size;
    my $kal_pool_stat_type;
    my $NU_buff_overhead;
    my $buff_stat_size;
    my $int_ram_defined;
    my $debug_buf2_defined;
    my $low_cost_support;
    my $FSM_defined;
    my $task_info_g;
    my $NORMAL_M;
    my $task_no_create_pattern;
    my $module_number;
    my $Gemini;
    my $page_size;
    my $stack_isolation;
    my $task_stack_common_plus; #/* overhead of DPV2 & FPU */#
    my $kal_int_buffer_callstack;
    my $hisr_priority_max_level;
    my $hisr_intid_g;
    my $hisr_intid_map_size;

    my $hisr_entry_size = 16;
    my $task_entry_size= 6 * 4;
    my $ctr_buff_size = 8;
    my $task_entry_para_ptr_size = 4;

    my $sys_mem;
    my $dbg_mem;
    my $int_mem;
    my $flag = 0;
    my $logs;
    my $total_no_created_task;
    my $all_logs;
    my $FACTORY_M;
    my $USB_M;
    my $factory_created_task;
    my $usb_created_task;

    my $ret = &parse_sys_mem_object($object_file);

    if ($ret != 1)
    {
        return ($ret, undef, undef, undef, undef, undef);
    }

    ### the digits are index to symbols
    ($flag, $int_ram_defined,  $debug_buf2_defined,  
        $low_cost_support, $FSM_defined, $task_info_g,
        $task_cb_size, $hisr_cb_size, $ext_queue_head_size, 
        $int_queue_entry_size, $MAX_CUSTOM_TASKS, $kal_queue_stat_type,
        $task_no_create_pattern, $ctrl_buff_overhead, $pool_cb_size,
        $kal_pool_stat_type,  $NU_buff_overhead, $NORMAL_M,
        $buff_stat_size, $Gemini, $page_size,
        $stack_isolation, $task_stack_common_plus, $FACTORY_M,
        $USB_M, $kal_int_buffer_callstack, $hisr_priority_max_level,
        $hisr_intid_g, $hisr_intid_map_size)
    = &read_word_value_from_obj($syscomp_fh, 6, 7,
                                8, 9, 10,
                                11, 12, 13, 
                                14, 15, 16,
                                17, 18, 19,
                                20, 21, 22,
                                23, 24, 25,
                                26, 27, 28,
                                29, 30, 31,
                                32, 33);
    $ext_queue_entry_size =  $int_queue_entry_size ;

    $all_logs = "internal ram defined:".$int_ram_defined."\n";
    ($flag, $sys_mem, $dbg_mem, $int_mem, $total_no_created_task, 
        $sys_mem_size_factory, $factory_created_task, 
        $sys_mem_size_usb, $usb_created_task, $logs) =
    &Caculate_task_memory(
        $syscomp_fh, 
        $symbols_size[0],
        $symbols_offset[0], 
        $task_entry_size, 
        $int_ram_defined,
        $ext_queue_head_size,
        $task_cb_size,
        $task_entry_para_ptr_size,
        $ext_queue_entry_size,
        $int_queue_head_size,
        $int_queue_entry_size,
        $kal_queue_stat_type,
        $NORMAL_M,
        $task_no_create_pattern,
        $page_size,
        $task_stack_common_plus,
        $FACTORY_M,
        $USB_M
        );

    if ($flag == 0)
    {
        &remove_tmp_files($syscomp_fh, $object_file);
        return ($ERR_GET_TASK_SYM, undef, undef, undef, undef, undef);
    } 
    
    $g_total_no_created_task = $total_no_created_task;
    $all_logs .= sprintf("total created task number = %d \n", $g_total_no_created_task);

    $sys_mem_size += $sys_mem;
    $intram_size  += $int_mem;
    $debug_mem_size += $dbg_mem;
    $all_logs.=$logs;

    #{$symbols_size[32], $symbols_offset[32]} meaning $hisr_intid_g
    ($flag) = &Check_unique_intid($syscomp_fh, $symbols_size[32], $symbols_offset[32], $hisr_intid_map_size);
    if ($flag != 0)
    {
        &remove_tmp_files($syscomp_fh, $object_file);
        return ($ERR_DUPLICATE_HISR_INTID, undef, undef, undef, undef,undef);
    } 

    ($flag, $sys_mem, $dbg_mem, $int_mem, $logs) = 
    &Caculate_hisr_memory($syscomp_fh, $symbols_size[1], $symbols_offset[1], 
        $hisr_entry_size, $int_ram_defined,
        $hisr_cb_size,
        $page_size,
        $hisr_priority_max_level);

    if ($flag == 0)
    {
        &remove_tmp_files($syscomp_fh, $object_file);
        return ($ERR_GET_HISR_SYM, undef, undef, undef, undef,undef);
    } 

    $sys_mem_size += $sys_mem;
    $sys_mem_size_usb += $sys_mem;
    $sys_mem_size_factory += $sys_mem;
    $intram_size  += $int_mem;
    $debug_mem_size += $dbg_mem;
    $all_logs.=$logs;

    ($flag, $sys_mem, $dbg_mem, $int_mem, $logs) = 
    &Caculate_control_buffer($syscomp_fh, $symbols_size[2], $symbols_offset[2], 
        $ctr_buff_size, $ctrl_buff_overhead,
        $pool_cb_size, $kal_pool_stat_type, 
        $buff_stat_size, $kal_int_buffer_callstack);
    if ($flag == 0)
    {
        &remove_tmp_files($syscomp_fh, $object_file);
        return ($ERR_GET_BUF_SYM, undef, undef, undef, undef, undef);
    } 

    $sys_mem_size += $sys_mem;
    $sys_mem_size_usb += $sys_mem;
    $sys_mem_size_factory += $sys_mem;
    $g_big_objects_size += $sys_mem;
    $debug_mem_size += $dbg_mem;
    $all_logs.=$logs;

    ($flag, $sys_mem, $dbg_mem, $int_mem, $logs) = 
    &Caculate_data_buffer($syscomp_fh, $symbols_size[3],
        $symbols_offset[3], 
        $NU_buff_overhead,
        $pool_cb_size);
    if ($flag == 0)
    {
        &remove_tmp_files($syscomp_fh, $object_file);
        return ($ERR_GET_BUF_SYM2, undef, undef, undef, undef, undef);
    } 

    $sys_mem_size += $sys_mem;
    $sys_mem_size_usb += $sys_mem;
    $sys_mem_size_factory += $sys_mem;
    $intram_size  += $int_mem;
    $all_logs.=$logs;
    $g_big_objects_size += $sys_mem;

    ($flag, $sys_mem, $dbg_mem, $int_mem, $logs) = 
    &Caculate_event_buffer($syscomp_fh, $symbols_size[4], 
        $symbols_offset[4], 
        $NU_buff_overhead);
    if ($flag == 0)
    {
        &remove_tmp_files($syscomp_fh, $object_file);
        return ($ERR_GET_BUF_SYM3, undef, undef, undef, undef, undef);
    } 

    $sys_mem_size += $sys_mem;
    $sys_mem_size_usb += $sys_mem;
    $sys_mem_size_factory += $sys_mem;
    $intram_size  += $int_mem;
    $all_logs.=$logs;
    $g_big_objects_size += $sys_mem;

    ($flag, $sys_mem, $dbg_mem, $int_mem, $module_number, $logs) = 
    &Caculate_ilm_module_g($syscomp_fh, $symbols_size[5], 
        $symbols_offset[5]);
    if ($flag == 0)
    {
        &remove_tmp_files($syscomp_fh, $object_file);
        return ($ERR_GET_MODULE, undef, undef, undef, undef, undef);
    } 
    #$g_big_objects_size += $sys_mem;

    # module_ilm_g has been moved from system memory to global array
#    $sys_mem_size += $sys_mem;
#    $intram_size  += $int_mem;
#    $all_logs.=$logs;
#
    ($flag, $sys_mem, $dbg_mem, $int_mem, $logs) = 
    &Caculate_task_info_g($symbols_size[0], 
                          $task_entry_size,
                          $MAX_CUSTOM_TASKS,
                          $task_info_g);
    $sys_mem_size += $sys_mem;
    $sys_mem_size_usb += $sys_mem;
    $sys_mem_size_factory += $sys_mem;
    $intram_size  += $int_mem;
    $all_logs.=$logs;
    $g_big_objects_size += $sys_mem;

############################The following part is estimation
############### V: run time create: mutext, sem, event group, three kinds of timers
    my $sem_number;
    my $event_group_number;
    my $timer_number;

    if (0 == $low_cost_support)
    {
        $sem_number = 8 * $total_no_created_task;
        $event_group_number = 3 * $total_no_created_task;
        $timer_number = 8 * $total_no_created_task;
    }
    elsif (2 == $low_cost_support)
    {   
        $sem_number = 2 * $total_no_created_task;
        $event_group_number = 1 * $total_no_created_task;
        $timer_number =  (0.5 + $Gemini * 0.1) * $module_number;
    }
    else
    {
        $sem_number = 2 * $total_no_created_task;
        $event_group_number = 1 * $total_no_created_task;
        $timer_number =  (1 + $Gemini * 0.1) * $module_number;
    }

    $estimate_sys_mem += ($sem_number * 48 + $event_group_number * 36 + $timer_number * 80);
    $g_small_objects_size += $estimate_sys_mem;
    $estimate_sys_mem_usb += $estimate_sys_mem / $total_no_created_task * $usb_created_task;
    $estimate_sys_mem_factory += $estimate_sys_mem / $total_no_created_task * $factory_created_task;
    #printf "small objects memory %d, task number %d\n", $new,  $total_no_created_task;

#################### VI: fsm
    #
    if ($FSM_defined)
    {
        $estimate_sys_mem += 2700;
        $g_big_objects_size += 2700;
        $estimate_sys_mem_factory += 2700;
        $estimate_sys_mem_usb += 2700;
    }
#print "fsm memory $new\n";


    #stack isolation turn off
    $sys_mem_size = (($sys_mem_size + 3)>>2)<<2;
    $sys_mem_size_usb = (($sys_mem_size_usb + 3)>>2)<<2;
    $sys_mem_size_factory = (($sys_mem_size_factory + 3)>>2)<<2;
    $estimate_sys_mem = (($estimate_sys_mem + 3)>>2)<<2;
    $estimate_sys_mem_usb = (($estimate_sys_mem_usb + 3)>>2)<<2;
    $estimate_sys_mem_factory = (($estimate_sys_mem_factory + 3)>>2)<<2;
    $debug_mem_size = (($debug_mem_size + 3)>>2)<<2;
    $intram_size = (($intram_size + 3)>>2)<<2;

    &remove_tmp_files($syscomp_fh, $object_file);
    my $total_sys_mem_stack_isolation  = 0; 
    
    #$g_big_objects_size += 10240; # temp allocate 10k in nvram_main.c nvram_malloc_disk_table()
    
    $total_sys_mem_stack_isolation += $g_big_objects_size + $g_aligned_stack_size;
    #small ojects more than the aligned gap, should take the system memory
    my $fill_gap = $g_small_objects_size - ($g_aligned_stack_size - $g_actual_stack_size);
    if ($fill_gap > 0)
    {
        $total_sys_mem_stack_isolation += $fill_gap;
    }
    
    #The notion of m_drop m_slip comes from stack isolation algorithm
    my $m_drop = 32 * $g_stack_no_aligned;    
    my $m_slip = ($fill_gap >= 8 * 1024)? 0: 4096;

    $total_sys_mem_stack_isolation += ($m_drop + $m_slip);
    
    # temp patch for 11BW1141OF from shuguang
    # add extra memory for ARM11 projects 56/76
    #if ($page_size == 4096) {
    #    $all_logs .= "add extra 80K now\n";
    #    $total_sys_mem_stack_isolation += 80*1024;
    #}
    
    $all_logs .= "No consider stack isolation sys_mem_size = $sys_mem_size + $estimate_sys_mem in NORMAL mode\n"; 
    $all_logs .= "No consider stack isolation sys_mem_size = $sys_mem_size_usb + $estimate_sys_mem_usb in USB mode\n"; 
    $all_logs .= "No consider stack isolation sys_mem_size = $sys_mem_size_factory + $estimate_sys_mem_factory in FACTORY mode\n"; 
    $all_logs .= "In stack isolation sys_mem_size: $total_sys_mem_stack_isolation"."\n".
    "small obj size: $g_small_objects_size"."\n"."align stack size: $g_aligned_stack_size"."\n".
    "actual stack size: $g_actual_stack_size"."\n"."big object size: $g_big_objects_size"."\n";

    if ($stack_isolation == 0)
    {
        return ($ERR_OK, $sys_mem_size, $estimate_sys_mem, $debug_mem_size, $intram_size, $all_logs); 
    }
    else
    {
        return ($ERR_OK, $total_sys_mem_stack_isolation, 0, $debug_mem_size, $intram_size, $all_logs);
    }
}

sub remove_tmp_files
{
    my $fh = shift @_;
    my $file_name = shift @_;
    close $fh;
    #unlink $file_name; 
}

#step1:  readelf the syscomp_config.o to get the symbols's offset and size.
#return : ok 1; fail 0;
#many globals affected
# XXX don't die
sub parse_sys_mem_object
{

    my $object_file = shift;
    my $readelf_path;
    my $temSymbols;
    my $temSection;
    
    if ( $^O eq "MSWin32" )
    {
        $readelf_path = "tools\\MinGW\\bin\\arm-none-eabi-readelf.exe";
    }
    else
    {
        $readelf_path = "tools/GCC/4.6.2/linux/bin/arm-none-eabi-readelf";
    }
    	  
    if(! -x $readelf_path)
    {
        return $ERR_READELF_TOOL;
    }

#debug
    if ( $^O eq "MSWin32" )
    {
        $temSymbols = "$logpath\\symbols.log";
    }
    else
    {
        $temSymbols = "$logpath\/symbols.log";
    }
    
    if (system "$readelf_path --syms $object_file > $temSymbols")
    {
        return $ERR_PARSE_OBJ;
    }

    if ( $^O eq "MSWin32" )
    {
        $temSection = "$logpath\\section.log";
    }
    else
    {
        $temSection = "$logpath\/section.log";
    }
    
    if (system "$readelf_path -S $object_file > $temSection")
    { 
        return $ERR_PARSE_OBJ;
    }

    my $i = 0;
    my $sym;
    foreach $sym (@symbols)
    {
        ($symbols_offset[$i], $symbols_size[$i]) = &get_sym_offset_size($sym);
        if (!defined($symbols_offset[$i]))
        {
            return $ERR_SYMNOT_EXIST;
        }
        $i++;
    }
    unlink $temSymbols;
    unlink $temSection;

    return 1;
}

sub read_word_value_from_obj
{
    my @values;
    my $fh = shift @_;
    my $flag = 1;
    my $content;

    foreach (@_) {
        my $offset = $symbols_offset[$_];
        if (!seek($fh, $offset, 0))
        {
               $flag = 0;
               last;
        }

        if (read($fh, $content, 4) != 4)
        {
               $flag = 0;
               last;
        }

        my @tmp = unpack("V*", $content);
        push (@values, $tmp[0]);
    }
    
    return ($flag, @values);
}

#input symbol.log, section.log, symbol name. 
#output: OK: (offset, size); fail: (undef, undef) 
sub get_sym_offset_size
{
    my $symbol_name = shift;
    my $file ;    
    if ( $^O eq "MSWin32" )
    {
        $file = "$logpath\\symbols.log";
    }
    else
    {
        $file = "$logpath\/symbols.log";
    }

    my $ok = open SYM_FD, "<", $file;
    
    if(!$ok)
    {
        return (undef, undef);
    }
    
    if ( $^O eq "MSWin32" )
    {
        $file = "$logpath\\section.log";
    }
    else
    {
        $file = "$logpath\/section.log";
    }
    
    $ok =  open SEC_FD, "<", $file; 
    if(!$ok)
    {
        return (undef, undef);
    }
   
    my $get_symbol = 0;
    my $found;
    my $offset;
    my $size;
    my $section;
    my $value;
    
    while(<SYM_FD>)
    {
        if(/$symbol_name\s*/)
        {   
            #debug
            #print $_;
            my @fields = split;
            
            $value = $fields[1];
            #debug
            #print "value: $value\n";

            $size = $fields[2];
            #debug
            #print "size : $size\n";

            $section = $fields[6];
            #debug
            #print "sectioin : $section\n";
            
            $get_symbol = 1;
            last;
            
        }
    }
    
    if ($get_symbol)
    {
        while(<SEC_FD>)
        {
            if (/\[\s?(\d+)\]/)
            {
                if ($1 == $section)
                {
                    /\[\s?\d+\](.*)/; 
                    $_ = $1;
                    my @fields = split;
                    #debug  
		    #print "$fields[3]\n";
		    $offset = hex("0x".$fields[3]) + hex("0x".$value);

                    #printf "0x%x\n", $offset;
                    $found = 1;
                    last;
                }
            }
        }
    }

    close SYM_FD;
    close SEC_FD;
   
    if ($found)
    {
        return ($offset, $size);
    }else
    {
        return (undef, undef);
    }
}

########################################### I : task resource#####################
#input: file handle of syscomp_config.o, symbols_size[0], symbols_offset[0], task_entry_size, int_ram_defined
#return: (flag sys_mem_size  debug_mem_size int_ram_size NU_create_task comments)
sub Caculate_task_memory
{
    my $file_handler = shift;
    my $symbol_size = shift;
    my $symbol_offset = shift;
    my $task_entry_size = shift;
    my $int_ram_defined = shift;
    my $ext_queue_head_size = shift ; 
    my $task_cb_size = shift;
    my $task_entry_para_ptr_size = shift;
    my $ext_queue_entry_size = shift;
    my $int_queue_head_size = shift;
    my $int_queue_entry_size = shift;
    my $kal_queue_stat_type = shift;
    my $NORMAL_M = shift;
    my $task_no_create_pattern = shift;
    my $page_size = shift;
    my $task_stack_common_plus = shift;
    my $FACTORY_M = shift;
    my $USB_M = shift;

    my $i = 0;
    my $task_numbers = $symbol_size / $task_entry_size;  
  
    my $nu_task_create++;
    my $task_sys_mem; 
    my $task_dbg_mem; 
    my $task_int_mem; 
    my $nu_task_create_factory = 0;
    my $task_sys_mem_factory; 
    my $task_dbg_mem_factory; 
    my $task_int_mem_factory; 
    my $nu_task_create_usb=0;
    my $task_sys_mem_usb; 
    my $task_dbg_mem_usb; 
    my $task_int_mem_usb; 
    my $all_logs; 

    while ($i < $task_numbers)
    {
        my $flag;
        my $stack;
        my $ext_q;
        my $int_q;
        my $in_sram;
        my $exist;
        my $priority;
        my $boot_mode;
        my $sys_mem;
        my $dbg_mem;
        my $int_mem;
        my $logs;
        my $j = 0;
        my $priority1 = 0;
        my $priority2 = 0;
        my $priority_j = 0;
        my $priority_j1 = 0;
        my $priority_j2 = 0;
          
        ($flag, $stack, $ext_q, $int_q, $in_sram, $exist, $priority, $boot_mode) = 
        &Get_task_memory_parameter($file_handler, 
                                    $symbol_offset + $i * $task_entry_size, 
                                    $task_entry_size);

        #fail
        if ($flag == 0)
        {
            return (0, undef, undef, undef, undef, undef, undef, undef);
        }
        $priority1 = (($priority & 0xFFFF0000) >> 16);
        $priority2 = $priority & 0x0000FFFF;

        #check task priority from next to the end
        $j = $i+1;
        if($g_ATEST_DRV_ENABLE == 0)
        {
           while ($j < $task_numbers)
           {
               ($flag, $priority_j) = &Get_task_priority($file_handler, 
                                        $symbol_offset + $j * $task_entry_size, 
                                        $task_entry_size);
                                        
               $priority_j1 = (($priority_j & 0xFFFF0000) >> 16);
               $priority_j2 = $priority_j & 0x0000FFFF;
               
               if (($flag != $task_no_create_pattern) && ($priority1 != 256)) #priority 256 means start or tail task. e.g. TASK_ID_SRV_CODE_BEGIN
               {
                   if( ($priority1 == $priority2) || ($priority1 == $priority_j1) || ($priority1 == $priority_j2)
                    || (($priority2 != 256) && (($priority2 == $priority_j1) || ($priority2 == $priority_j2))) )
                   {
                       printf "KAL task config Error: duplicate task index %d priority 0x%08X, index %d priority 0x%08X\n",
                       $i, $priority, $j, $priority_j;
                       
                       if($priority1 == $priority2)
                       {
                           printf "task index %d 1st priority %d == 2nd priority %d \n", $i, $priority1, $priority2;
                       }
                       if($priority1 == $priority_j1)
                       {
                           printf "task index %d 1st priority %d == task index %d 1st priority %d \n", $i, $priority1, $j, $priority_j1;
                       }
                       if($priority1 == $priority_j2)
                       {
                           printf "task index %d 1st priority %d == task index %d 2nd priority %d \n", $i, $priority1, $j, $priority_j2;
                       }
                       if(($priority2 != 256) && ($priority2 == $priority_j1))
                       {
                           printf "task index %d 2nd priority %d == task index %d 1st priority %d \n", $i, $priority2, $j, $priority_j1;
                       }
                       if(($priority2 != 256) && ($priority2 == $priority_j2))
                       {
                           printf "task index %d 2nd priority %d == task index %d 2nd priority %d \n", $i, $priority2, $j, $priority_j2;
                       }
                       print "Please check task config or contact config owner!!!";
                       exit $ERR_DUPLICATE_TASK_PRIORITY;                
                   }
               }
               $j++;
           }
        }        

        ($flag, $sys_mem, $dbg_mem, $int_mem, $logs) 
        = &caculate_task_resource($stack, $ext_q, $int_q, 
                                  $in_sram, $exist, $i,
                                  $boot_mode, $int_ram_defined, $ext_queue_head_size,
                                  $task_cb_size, $task_entry_para_ptr_size, $ext_queue_entry_size,
                                  $int_queue_head_size, $int_queue_entry_size, $kal_queue_stat_type,
                                  $NORMAL_M, $task_no_create_pattern, $page_size,
                                  $task_stack_common_plus, $FACTORY_M, $USB_M, $NORMAL_M);
        #flag 0 : task no create
        if ($flag == 1)
        {
            $nu_task_create++;
            $task_sys_mem += $sys_mem;
            $task_dbg_mem += $dbg_mem;
            $task_int_mem += $int_mem;
            $all_logs .= $logs;
        }
        elsif ($flag == 2)
        {
            $all_logs .= $logs;
        }

        ($flag, $sys_mem, $dbg_mem, $int_mem, $logs) 
        = &caculate_task_resource($stack, $ext_q, $int_q, 
                                  $in_sram, $exist, $i,
                                  $boot_mode, $int_ram_defined, $ext_queue_head_size,
                                  $task_cb_size, $task_entry_para_ptr_size, $ext_queue_entry_size,
                                  $int_queue_head_size, $int_queue_entry_size, $kal_queue_stat_type,
                                  $NORMAL_M, $task_no_create_pattern, $page_size,
                                  $task_stack_common_plus, $FACTORY_M, $USB_M, $FACTORY_M);
        #flag 0 : task no create
        if ($flag == 1)
        {
            $nu_task_create_factory++;
            $task_sys_mem_factory += $sys_mem;
            $task_dbg_mem_factory += $dbg_mem;
            $task_int_mem_factory += $int_mem;
        }

        ($flag, $sys_mem, $dbg_mem, $int_mem, $logs) 
        = &caculate_task_resource($stack, $ext_q, $int_q, 
                                  $in_sram, $exist, $i,
                                  $boot_mode, $int_ram_defined, $ext_queue_head_size,
                                  $task_cb_size, $task_entry_para_ptr_size, $ext_queue_entry_size,
                                  $int_queue_head_size, $int_queue_entry_size, $kal_queue_stat_type,
                                  $NORMAL_M, $task_no_create_pattern, $page_size,
                                  $task_stack_common_plus, $FACTORY_M, $USB_M, $USB_M);
        #flag 0 : task no create
        if ($flag == 1)
        {
            $nu_task_create_usb++;
            $task_sys_mem_usb += $sys_mem;
            $task_dbg_mem_usb += $dbg_mem;
            $task_int_mem_usb += $int_mem;
        }
        
        $i++;
    }

    $all_logs.="No consider stack isolation All task consumes $task_sys_mem in NORMAL mode\n";
    $all_logs.="No consider stack isolation All task consumes $task_sys_mem_usb in USB mode\n";
    $all_logs.="No consider stack isolation All task consumes $task_sys_mem_factory in FACTORY mode\n";
    return (1, $task_sys_mem, $task_dbg_mem, $task_int_mem, $nu_task_create, 
        $task_sys_mem_factory, $nu_task_create_factory, 
        $task_sys_mem_usb, $nu_task_create_usb, $all_logs);
}


#input  stack ext_q, int_q, in_sram, exist, priority
#return ($flag, $sys_mem, $dbg_mem, $int_mem, $logs)
#task_info_g exist
sub caculate_task_resource
{
    my $stack = shift;
    my $ext_q = shift;
    my $int_q = shift;
    my $in_sram = shift;
    my $exist = shift;
    my $index = shift;
    my $boot_mode = shift; 
    my $int_ram_defined = shift;
    my $ext_queue_head_size = shift ; 
    my $task_cb_size = shift;
    my $task_entry_para_ptr_size = shift;
    my $ext_queue_entry_size = shift;
    my $int_queue_head_size = shift;
    my $int_queue_entry_size = shift;
    my $kal_queue_stat_type = shift;
    my $NORMAL_M = shift;
    my $task_no_create_pattern = shift;
    my $page_size = shift;
    my $task_stack_common_plus = shift;
    my $FACTORY_M = shift;
    my $USB_M = shift;
    my $checking_mode = shift;
    my $tmp_aligned_stack = 0;
    
    my $logs;
    my $dbg_mem = 0; 
    my $int_mem = 0;
    my $task_mem_size = 0;
    my $task_extq_size = 0;
    my $task_intq_size = 0;

    #no create, no memory
    if ($exist == $task_no_create_pattern || $stack == 0)
    {
        return (0, undef, undef, undef, undef);
    }

    if( (($boot_mode & $NORMAL_M ) == $NORMAL_M)
     || (($boot_mode & $FACTORY_M ) == $FACTORY_M)
     || (($boot_mode & $USB_M ) == $USB_M) )
    {
        $task_mem_size += $task_entry_para_ptr_size;
        $task_mem_size += $task_cb_size;
        if(($checking_mode == $NORMAL_M)&&($checking_mode == ($boot_mode & $checking_mode )))
        {
            $g_small_objects_size += $task_entry_para_ptr_size;
            $g_small_objects_size += $task_cb_size;
        }

        if ($in_sram == 0 || !$int_ram_defined )
        {
            $task_mem_size += $stack;
            if( (($checking_mode == $NORMAL_M)&&($checking_mode == ($boot_mode & $checking_mode )))
            && ($stack != (int ($stack / $page_size)) * $page_size) )
            {
                $g_stack_no_aligned++;
            }

#	if ($stack >= (8*1024))
#	{
#		$stack -= $task_stack_common_plus;
#	}
            $tmp_aligned_stack = int(( ($stack + ($page_size - 1) ) / $page_size )) * $page_size;
            if(($checking_mode == $NORMAL_M)&&($checking_mode == ($boot_mode & $checking_mode )))
            {
                $g_actual_stack_size += $stack;
                $g_aligned_stack_size += $tmp_aligned_stack;
            }

        }
        else
        {
            $int_mem += $stack;
        }

        if($ext_q)
        {
            $task_extq_size = $ext_q * $ext_queue_entry_size;
            $task_mem_size += $ext_queue_head_size + $task_extq_size;
            if(($checking_mode == $NORMAL_M)&&($checking_mode == ($boot_mode & $checking_mode )))
            {
                $g_small_objects_size +=  $ext_queue_head_size;
                if ($task_extq_size >= 512)
                {
                    $g_big_objects_size += $task_extq_size;
                }
                else
                {
                    $g_small_objects_size += $task_extq_size;
                }
            }
        }

        if($int_q)
        {
            $task_intq_size = $int_q * $int_queue_entry_size;
            $task_mem_size += $int_queue_head_size + $task_intq_size;
            if(($checking_mode == $NORMAL_M)&&($checking_mode == ($boot_mode & $checking_mode )))
            {
                $g_small_objects_size += $int_queue_head_size;
                if ($task_intq_size >= 512)
                {
                    $g_big_objects_size += $task_intq_size;
                }
                else
                {
                    $g_small_objects_size += $task_intq_size;
                }
            }
        }

        $dbg_mem += $kal_queue_stat_type;
        
    }
    else
    {
        return (0, undef, undef, undef, undef);
    }

    if ($checking_mode == $NORMAL_M)
    {
        $logs.= sprintf("Task of index %3d consumes %4d. stack %4d align stack %4d ext_q %3d int_ram? %d",
                    $index, $task_mem_size, $stack, $tmp_aligned_stack, $ext_q, $in_sram);
        
        $logs.=" boot mode:";
        if(($boot_mode & $NORMAL_M ) == $NORMAL_M)
        {
            $logs.="NORMAL ";
        }
        else
        {
            $logs.="       ";
        }
        if(($boot_mode & $USB_M ) == $USB_M)
        {
            $logs.="USB ";
        }
        else
        {
            $logs.="    ";
        }
        if(($boot_mode & $FACTORY_M ) == $FACTORY_M)
        {
            $logs.="FACTORY ";
        }
        else
        {
            $logs.="        ";
        }
        $logs.="mode\n";
    }

    if ($checking_mode == ($boot_mode & $checking_mode ))
    {
        return (1, $task_mem_size, $dbg_mem, $int_mem, $logs);
    }
    elsif (($checking_mode == $NORMAL_M)&&($boot_mode == $FACTORY_M))
    {
        return (2, undef, undef, undef, $logs);
    }
    else
    {
        return (0, undef, undef, undef, undef);
    }
}

#input: offset, size, DF
#output (flag, stack size, ext queue, int queue, in_sram, $exist, $priority, $boot_mode) 
#assumption: sys_comp_config_tbl layout
sub  Get_task_memory_parameter
{
    my $fh = shift;
    my $offset = shift;
    my $size = shift; 
    my $content;
    
    if (!seek($fh, $offset, 0))
    {
        return (0, undef, undef, undef, undef, undef, undef, undef);
    }

    if(read($fh, $content, $size) != $size)
    {
        return (0, undef, undef, undef, undef, undef, undef, undef);
    }
    #little edian order 
    my @tmp = unpack("V*", $content);

    #debug
    #printf "0x%x\n", $tmp[5]; 
    my $exist = $tmp[4];
   
    my $priority = $tmp[2];
   
    my $boot_mode = ($tmp[5] & 0xFF000000) >> 24;
    my $int_q = ($tmp[5] & 0x00FF0000) >> 16;
    #printf "0x%x\n", $int_q>>16;

    my $ext_q = ($tmp[5] & 0x0000FF00) >> 8;
    #printf "%x\n", $ext_q>>8;

    my $in_sram = $tmp[5] & 0x000000FF;
    #print $in_sram."\n";

    my $stack = $tmp[3]; 
    #print $stack."\n";
    #debug

    return (1, $stack, $ext_q, $int_q, $in_sram, $exist, $priority, $boot_mode);
}
#input: offset, size, DF
#output (flag, $priority) 
#assumption: sys_comp_config_tbl layout
sub  Get_task_priority
{
    my $fh = shift;
    my $offset = shift;
    my $size = shift; 
    my $content;
    
    if (!seek($fh, $offset, 0))
    {
        return (0, undef, undef, undef, undef, undef, undef, undef);
    }

    if(read($fh, $content, $size) != $size)
    {
        return (0, undef, undef, undef, undef, undef, undef, undef);
    }
    #little edian order 
    my @tmp = unpack("V*", $content);

    #debug
    #printf "0x%x\n", $tmp[5];    
    my $exist = $tmp[4];
    my $priority = $tmp[2];

    return ($exist, $priority);
}
######################################################## II: caculate hisr resource
#typedef struct hisr_intid_map_t
#{
#	kal_hisr hisr_id;
#	interrupt_type int_id;
#}hisr_intid_map;
sub Get_hisr_intid
{
    my $fh = shift;
    my $offset = shift;
    my $size = shift; 
    my $content;
    
    if (!seek($fh, $offset, 0))
    {
        return (0, undef);
    }

    if(read($fh, $content, $size) != $size)
    {
        return (0, undef);
    }

    #little endian order 
    my @tmp = unpack("V*", $content);
   
    my $intid = (($tmp[0] & 0xFFFF0000)>>16);

    #debug
    return (1, $intid);
}

#return (0) if successful
#make sure each int_id of hisr_intid_g[] is unique
sub Check_unique_intid
{
    my $file_handle = shift;
    my $sys_size = shift;
    my $sys_offset = shift;
    my $hisr_intid_map_size = shift;

    my $hisr_intid_numbers = $sys_size/ $hisr_intid_map_size;
    my $j = 1;
    my $i = 0;
    my $intid_i;
    my $intid_j;
    my $flag;

    while($i < $hisr_intid_numbers)
    {
        ($flag, $intid_i) = &Get_hisr_intid($file_handle, $sys_offset+$hisr_intid_map_size*$i, $hisr_intid_map_size);
        if($flag == 0)
        {
            print "ERROR: fail to Get_hisr_intid intid_i\n";
            return(1);
        }
        while($j < $hisr_intid_numbers)
        {
            ($flag, $intid_j) = &Get_hisr_intid($file_handle, $sys_offset+$hisr_intid_map_size*$j, $hisr_intid_map_size);
            if($flag == 0)
            {
                print "ERROR: fail to Get_hisr_intid intid_j\n";
                return(1);
            }
            if($intid_i == $intid_j)
            {
                print "ERROR: duplicate KAL_INTID_$intid_j in hisr_config_internal.h \n";
                return(2);
            }
            $j++;
        }
        $i++;
        $j = $i+1;
    }
    
    return(0);
}

#return ( flag, sys_mem_size  debug_mem_size int_ram_size  comments)
sub Caculate_hisr_memory
{
    my $file_handle = shift;
    my $sys_size = shift;
    my $sys_offset = shift;
    my $hisr_entry_size = shift;
    my $int_ram_defined = shift;
    my $hisr_cb_size = shift;
    my $page_size = shift;
    my $hisr_priority_max_level = shift;
    my $hisr_sys_mem;
    my $hisr_dbg_mem;
    my $hisr_int_mem = 0;
    my $all_logs; 
    
    my $j = 0;
    my $i = 0; 
    my $hisr_numbers = $sys_size/ $hisr_entry_size; 
    my $stack;
    my $int_ram;
    my $index;
    my $flag;
    my $sys_mem;
    my $dbg_mem;
    my $int_mem;
    my $logs;
    my $current_index;
    my $hisr_priority;
    #hisr_max_shared_iram_size[p] means max shared iram stack size in priority p 
    my @hisr_max_shared_iram_size; 
    my @hisr_max_shared_eram_size; 

    #zero-init array
    while($j < $hisr_priority_max_level)
    {
        $hisr_max_shared_iram_size[$j] = 0;
        $hisr_max_shared_eram_size[$j] = 0;
        $j++;
    }
    
    if ($platform ne "TRUE") # target only
    {             
        #init hisr shared stack info
        $j = 0;  
        while($j < $hisr_numbers)
        {
            ($flag, $stack, $int_ram, $index, $hisr_priority) = 
            &Get_hisr_memory_parameter($file_handle, 
                                        $sys_offset + $j * $hisr_entry_size, 
                                        $hisr_entry_size);

            # eram, condition check must be same as caculate_hisr_resource()
            if ($int_ram == 0 || $int_ram_defined == 0) 
            {
                if($stack > $hisr_max_shared_eram_size[$hisr_priority])
                {
                    $hisr_max_shared_eram_size[$hisr_priority] = $stack;
                }
            }
            else
            {
                if($stack > $hisr_max_shared_iram_size[$hisr_priority])
                {
                    $hisr_max_shared_iram_size[$hisr_priority] = $stack;
                }
            }
            $j++;
        }
        
        $j = 0;
        while($j < $hisr_priority_max_level)
        {
            #sum hisr shared iram stack size
            $g_hisr_shared_iram_stack_size += $hisr_max_shared_iram_size[$j];
            $all_logs .= sprintf("priority %2d hisr max shared size iram %4d eram %4d \n", 
                $j, $hisr_max_shared_iram_size[$j], $hisr_max_shared_eram_size[$j]);
            $hisr_int_mem += $hisr_max_shared_iram_size[$j];
            #count it if IRAM size could not be its stack
            if($hisr_max_shared_eram_size[$j] > $hisr_max_shared_iram_size[$j])
            {
                $hisr_sys_mem += $hisr_max_shared_eram_size[$j];
            }
            $j++;
        }        
        $all_logs .= sprintf("hisr shared stack total iram size %5d \n", $g_hisr_shared_iram_stack_size);
    }

    while ($i < $hisr_numbers)
    {
        ($flag, $stack, $int_ram, $index, $hisr_priority) = 
        &Get_hisr_memory_parameter($file_handle, 
                                    $sys_offset + $i * $hisr_entry_size, 
                                    $hisr_entry_size);
        if ($flag == 0)
        {
            return (0, undef, undef, undef, undef); 
        }

        $i++;

        ($flag, $sys_mem, $dbg_mem, $int_mem, $logs)  = 
                        &caculate_hisr_resource($stack, 
                                                $int_ram, 
                                                $index,
                                                $int_ram_defined,
                                                $hisr_cb_size,
                                                $page_size,
                                                $hisr_priority,
                                                $hisr_max_shared_iram_size[$hisr_priority],
                                                $hisr_max_shared_eram_size[$hisr_priority]);

       if ($flag)
       {
            $hisr_sys_mem += $sys_mem;
            $hisr_dbg_mem += $dbg_mem;
            $hisr_int_mem += $int_mem;
            $all_logs .= $logs;
       }
    }

    #check if duplicate hisr index is inside hisr_info
    while($i)
    {
        $j = $i-1;
        ($flag, $stack, $int_ram, $index, $hisr_priority) = 
        &Get_hisr_memory_parameter($file_handle, 
                                    $sys_offset + $j * $hisr_entry_size, 
                                    $hisr_entry_size);
        $current_index = $index;
        while($j)
        {            
            ($flag, $stack, $int_ram, $index, $hisr_priority) = 
            &Get_hisr_memory_parameter($file_handle, 
                                        $sys_offset + ($j-1) * $hisr_entry_size, 
                                        $hisr_entry_size);
            $j--;
            if($current_index == $index)
            {
                printf "KAL hisr config Error: duplicate hisr index %d\n", $index;
                print "Please check hisr config or contact config owner!!!";
                exit $ERR_HISR_INDEX;
            }
        }
        $i--;
    }

    $all_logs.="No consider stack isolation. All HISRs consume ext mem: $hisr_sys_mem  int mem: $hisr_int_mem\n";
    $g_hisr_shared_iram_stack_size = $hisr_int_mem;

    return (1, $hisr_sys_mem, $hisr_dbg_mem, $hisr_int_mem, $all_logs);
}
#typedef struct
#{
#    kal_hisr            index;
#    kal_uint8           priority;
#    kal_uint8           options;
#    kal_uint32          stack_size;
#    kal_hisr_func_ptr   entry_func;
#    kal_char            *hisr_name;
#}hisr_parameter_s;
sub Get_hisr_memory_parameter
{
    my $fh = shift;
    my $offset = shift;
    my $size = shift; 
    my $content;
    
    if (!seek($fh, $offset, 0))
    {
        return (0, undef, undef, undef);
    }

    if(read($fh, $content, $size) != $size)
    {
        return (0, undef, undef, undef);
    }

    #little edian order 
    my @tmp = unpack("V*", $content);
   
    my $int_ram = (($tmp[0] & 0x00FF0000) >> 16);
    my $hisr_priority = (($tmp[0] & 0x0000FF00) >> 8);
    my $hisr_index = (($tmp[0] & 0x000000FF));
    my $stack = $tmp[1];

    #debug
    return (1, $stack, $int_ram, $hisr_index, $hisr_priority);
}

#return (1, $sys_mem, $dbg_mem, $int_mem, $logs)
sub caculate_hisr_resource
{
    my $stack = shift;
    my $int_ram = shift;
    my $index = shift;
    my $int_ram_defined = shift;
    my $hisr_cb_size = shift;
    my $page_size = shift;
    my $hisr_priority = shift;
    my $max_shared_iram_size = shift;
    my $max_shared_eram_size = shift;
    my $tmp_aligned_stack = 0;
    my $hisr_mem = 0;
    my $int_mem = 0;
    my $logs;

    if ($int_ram == 0 || $int_ram_defined == 0)
    {
        #modis OR max shared eram size 
        if( ($platform eq "TRUE") || (($stack > $max_shared_iram_size) && ($stack > $max_shared_eram_size)) )
        {
            $hisr_mem = $stack;
            $g_actual_stack_size += $stack;
            
            if ($stack != (int ($stack / $page_size)) * $page_size)
            {
                $g_stack_no_aligned++;
            }

            $tmp_aligned_stack = int( ( ($stack + ($page_size - 1) ) / $page_size )) * $page_size;
            $g_aligned_stack_size += $tmp_aligned_stack; 
        }
    }
    else
    {
        #modis OR max shared iram size
        if( ($platform eq "TRUE") || ($stack > $max_shared_iram_size) )
        {
            $int_mem += $stack;
        }
    }

    $hisr_mem+= $hisr_cb_size;
    $g_small_objects_size += $hisr_cb_size;
    
    $logs .= sprintf("HISR of index %3d priority %3d consumes %4d. stack %4d aligned stack %4d int_ram? %d\n",
                    $index, $hisr_priority, $hisr_mem, $stack, $tmp_aligned_stack, $int_ram);
        
    return (1, $hisr_mem, 0, $int_mem, $logs);
}

############################## III: Buffers: control buffer, event buffer, data buffer
#return ( flag, sys_mem_size  debug_mem_size int_ram_size  comments)
sub Caculate_control_buffer
{
    my $fh = shift;
    my $sys_size = shift;
    my $sys_offset = shift;
    my $buff_entry_size =  shift;
    my $ctrl_buff_overhead = shift;
    my $pool_cb_size = shift;
    my $kal_pool_stat_type = shift;
    my $buff_stat_size = shift;
    my $kal_int_buffer_callstack = shift;

    my $i = 0;
    
    my $size;
    my $num;
    my $ctrl_buff_number = $sys_size/ $buff_entry_size;
    my $flag;
    my $sys_mem;
    my $dbg_mem;
    my $int_mem;
    my $logs;
   
    my $all_sys_mem;
    my $all_dbg_mem;
    my $all_int_mem;
    my $all_logs;
   
    while ($i < $ctrl_buff_number)
    { 

        ($flag, $size, $num) = 
        &read_2_word_from_obj($fh, 
                                 $sys_offset+ $i * $buff_entry_size, 
                                 $buff_entry_size);
        $i++;
        
        #fail
        if ($flag == 0)
        {
            return (0, undef, undef, undef, undef); 
        }

       ($flag, $sys_mem, $dbg_mem, $int_mem, $logs) = 
        &caculate_ctrl_buff_resource($size, $num, $ctrl_buff_overhead,
                                     $pool_cb_size, $kal_pool_stat_type,
                                     $buff_stat_size, $kal_int_buffer_callstack);
       if ($flag)
       {
            $all_sys_mem += $sys_mem;
            $all_dbg_mem += $dbg_mem;
            $all_int_mem += $int_mem;
       }
       $all_logs .= sprintf("control buffer size(=%6d) num(=%4d)\n", $size, $num);
    }
    $all_logs.="control buffer consumes sys_mem + dbg_mem = $all_sys_mem + $all_dbg_mem\n";
    
    return (1, $all_sys_mem, $all_dbg_mem, $all_int_mem, $all_logs);
}

sub caculate_ctrl_buff_resource
{
    my $data_size = shift;
    my $num = shift;
    my $ctrl_buff_overhead = shift;
    my $pool_cb_size = shift;
    my $kal_pool_stat_type = shift;
    my $buff_stat_size = shift;
    my $kal_int_buffer_callstack = shift;
    my $sys_mem;
    my $debug_mem;

    $sys_mem = ($ctrl_buff_overhead + $data_size) * $num + $pool_cb_size;
    $debug_mem += ($kal_pool_stat_type + ($buff_stat_size + $kal_int_buffer_callstack) * $num);
    return (1, $sys_mem, $debug_mem, 0, undef);
}

#event pool
#return ( flag, sys_mem_size  debug_mem_size int_ram_size  comments)
sub Caculate_event_buffer
{
    my $fh = shift;
    my $sys_size = shift;
    my $sys_offset = shift;
    my $NU_buff_overhead = shift;

    my $flag;
    my $size;
    my $num;
    my $sys_mem = 0;
    my $dbg_mem = 0;
    my $int_mem = 0;
    my $logs ="";
   
    #&read_2_word_from_obj($symbols_offset[4], $ctr_buff_size);
    ($flag, $size, $num) = 
    &read_2_word_from_obj($fh, $sys_offset, $sys_size);
    #fail
    if ($flag == 0)
    {
        return (0, undef, undef, undef, undef); 
    }

    $sys_mem +=  ($NU_buff_overhead + $size) * $num;
    $logs.="event pool consumes $sys_mem\n";

    return ($flag, $sys_mem, $dbg_mem, $int_mem, $logs); 
}

#data buffer
#return ( flag, sys_mem_size  debug_mem_size int_ram_size  comments)
sub Caculate_data_buffer
{
    my $fh = shift;
    my $sys_size = shift;
    my $sys_offset = shift;
    my $NU_buff_overhead = shift;
    my $pool_cb_size = shift;

    my $flag;
    my $size;
    my $num;
    my $sys_mem = 0;
    my $int_mem = 0;
    my $logs = "";
   
    #&read_2_word_from_obj($symbols_offset[4], $ctr_buff_size);
    ($flag, $size, $num) = 
    &read_2_word_from_obj($fh, $sys_offset, $sys_size);
    #fail
    if ($flag == 0)
    {
        return (0, undef, undef, undef, undef); 
    }

    if ($num > 0)
    {
        $size = (($size + $NU_buff_overhead + 3) >> 2 ) << 2;
        $sys_mem += $size * $num + $pool_cb_size;
        $logs = "data buffer consumes $sys_mem\n";
    }
    

    return (1, $sys_mem, 0, $int_mem, $logs); 
}

sub read_2_word_from_obj
{
    my $fh = shift;
    my $offset = shift;
    my $size = shift; 
    my $content;
    
    if (!seek($fh, $offset, 0))
    {
        return (0, undef, undef);
    }

    if(read($fh, $content, $size) != $size)
    {
        return (0, undef, undef);
    }
  
    #little edian order 
    my @tmp = unpack("V*", $content);
   
    my $data_size = $tmp[0]; 
    my $num = $tmp[1]; 

    return (1, $data_size, $num);
}

#return ( flag, sys_mem_size  debug_mem_size int_ram_size $module_num comments)
sub Caculate_ilm_module_g
{
    my $fh = shift;
    my $sys_size = shift;
    my $sys_offset = shift;
    my $logs;

    my $size;
    my $num;
    my $flag;
    my $sys_mem;

    ($flag, $size, $num) = &read_2_word_from_obj($fh, $sys_offset, $sys_size);
    if ($flag == 0)
    {
        return (0, undef, undef, undef, undef);
    }

    $sys_mem += $size * $num; 
    $logs.=
    sprintf("%d ilm consumes %d\n", $num, $sys_mem);

    return (1, $sys_mem, 0, 0, $num, $logs);
}


#return ( flag, sys_mem_size  debug_mem_size int_ram_size  comments)
sub Caculate_task_info_g
{
    my $task_size = shift;
    my $task_entry_size = shift;
    my $MAX_CUSTOM_TASKS = shift;
    my $task_info_g = shift;

    my $task_number = $task_size / $task_entry_size; 
    my $logs;
    my $sys_mem;

    $sys_mem += ($task_number - $MAX_CUSTOM_TASKS) * $task_info_g;

    $logs .= sprintf("%d task_info_g sys_mem %d\n", 
                    $task_number - $MAX_CUSTOM_TASKS, 
                    $sys_mem);

    return (1, $sys_mem, 0, 0, $logs);
}
