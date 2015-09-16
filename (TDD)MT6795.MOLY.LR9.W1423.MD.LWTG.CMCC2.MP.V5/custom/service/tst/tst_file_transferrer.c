/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * tst_file_transfer.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements the tasks to transfer TST logs to File
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_public_api.h" //MSBB change #include "kal_release.h"      /* Basic data type */

#include "kal_public_defs.h" //MSBB change #include "stack_common.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"

#include "syscomp_config.h"
#include "task_config.h"      /* Task creation */

#include "kal_public_api.h"   /* Buffer management */

#include "GV.h"
#include "tst_def.h"
#include "tst_ext.h"          /* Dump info*/
#include "fat_fs.h"
#include "dcl.h" // For HAL RTC Interface
#include "tst_file_def.h"

//#pragma arm section code= "PRIMARY_ROCODE" rwdata = "PRIMARY_RW" , rodata = "PRIMARY_RODATA" , zidata = "PRIMARY_ZI" 
/*************************************************************************
* Definitions
 *************************************************************************/
#ifdef __TST_WRITE_TO_FILE__
  #if defined(__TST_WRITE_EX_MEM_ONLY__)
    __tstfilezidata kal_uint8   write2file_temp_buf[ASSERT_MEM_DISK_DUMP_BUF_LEN];
    #define ASSERT_MEM_DISK_DUMP_BUF_LEN         (1024)
  #else
    #define write2file_temp_buf (tst_dump_info.buffer)
    #define ASSERT_MEM_DISK_DUMP_BUF_LEN (TST_FSWRITE_BUFFER_SIZE)
  #endif 
#endif  //#ifdef __TST_WRITE_TO_FILE__

#define BIN_FILE_HEADER (0x2454ABCD)
#define BIN_FILE_VERSION (0x00000001)
#define TST_FILE_DISK_CHECK_PERIOD (128)

/*************************************************************************
* Global variable declaration
 *************************************************************************/

#ifdef __TST_WRITE_TO_FILE__    
  __tstfilezidata tst_dump_info_struct tst_dump_info;
  
  #ifdef __SMART_PHONE_MODEM__ 
    __tstfilezidata kal_uint32 tst_check_sd_avail_tick=0;
  #endif  //#ifdef __SMART_PHONE_MODEM__ 
    
  #if defined(__TST_WRITE_EX_MEM_ONLY__)
    __tstfilezidata kal_uint8   write2file_temp_buf[ASSERT_MEM_DISK_DUMP_BUF_LEN];
  #else
    #define write2file_temp_buf (tst_dump_info.buffer)
    #define ASSERT_MEM_DISK_DUMP_BUF_LEN (TST_FSWRITE_BUFFER_SIZE)
  #endif 
#elif defined(__AT_ETSTLP_SUPPORT__) || !defined(__MMI_FMI__)
    #define ASSERT_MEM_DISK_DUMP_BUF_LEN (1024)  // for dual talk logging memory dump
    __tstfilezidata kal_uint8 write2file_temp_buf[ASSERT_MEM_DISK_DUMP_BUF_LEN];
#else
    #define write2file_temp_buf NULL
    #define ASSERT_MEM_DISK_DUMP_BUF_LEN (0)
#endif  //#ifdef __TST_WRITE_TO_FILE__

__tstfilerwdata tst_log_to_file_err_enum tst_err_log_to_file = NO_LOG_ERROR;  //the error code
__tstfilerwdata kal_uint8* tst_file_ex_tmp_buf = write2file_temp_buf;
__tstfilerwdata kal_uint32 tst_file_ex_tmp_buf_size = ASSERT_MEM_DISK_DUMP_BUF_LEN;
__tstfilezidata kal_eventgrpid  tft_event_group;


/*************************************************************************
* Extern variable declaration
 *************************************************************************/
#if defined(__SMART_PHONE_MODEM__) 
  extern kal_bool  tst_ft_mode; 
#endif  //#if defined(__SMART_PHONE_MODEM__) 
extern kal_bool  tst_is_PsTrc_open;
extern kal_bool  tst_ft_mode;
extern kal_uint8   TST_OUTPUT_MODE;
extern char base_release_hw_ver[];
extern char base_release_sw_ver[];
extern unsigned char  tst_module_filter_g[];
extern unsigned char  tst_sap_filter_g[];
extern unsigned char  tst_trace_filter_g[];
extern kal_bool    tst_l1trace_flag;
extern kal_bool    tst_pstrace_flag;
extern kal_bool bLoadMiniLogFilter;

/*************************************************************************
* Function declaration
 *************************************************************************/
kal_bool tst_file_transferrer_create(comptask_handler_struct **handle);
kal_bool tst_file_transferrer_init(void);
void tst_file_transferrer_main( task_entry_struct * task_entry_ptr );
kal_bool tst_file_transferrer_reset(void);
void tst_file_open_file_to_write(void);
void tst_file_dump_create_file(void);
FS_HANDLE tst_file_create_file(void);
void tst_file_dump_file(void);
kal_bool tst_file_write_file(kal_uint8 *buffer, kal_uint32 length);
extern kal_bool tst_check_filter_enabled(void);
extern void trc_setfilter(unsigned char *setting, unsigned int len);
extern kal_bool if_buffer_all_zero(kal_uint8 *ptr, kal_uint16 length);
extern void tst_file_update_predefined_filters(void);
extern kal_uint32 tst_get_ring_buffer_usage(void);
extern void tst_file_write_logacc_logs(void);
extern void tst_nvram_statistic_handler(nvram_actions act);
kal_uint32 tst_file_wait_data_card_for_ready(void);
kal_bool tst_file_get_disk_phy_space(kal_char driveLetter);

/*************************************************************************
* Function body
 *************************************************************************/

#ifdef __TST_WRITE_TO_FILE__  //this function is only avaialable when __TST_WRITE_TO_FILE__ is enabled

__tstfileFunc void tst_file_write_verno_to_file(void)
{
  FS_HANDLE  fHandle;
  WCHAR strFSName[54];//i.e. X:\PSLog\00000.dmp
  kal_uint32 written_bytes;
  
  #if !defined(__SMART_PHONE_MODEM__)
  {
    RTC_CTRL_GET_TIME_T rtc_time;
    DCL_HANDLE rtc_handler;
	  kal_uint32 tick;    
    
    rtc_handler = DclRTC_Open(DCL_RTC,FLAGS_NONE);
    if(STATUS_FAIL == DclRTC_Control(rtc_handler, RTC_CMD_GET_TIME, (DCL_CTRL_DATA_T *)&rtc_time)) // New API with CMD & DATA 
    {
		tick = kal_get_systicks();
		  kal_wsprintf(strFSName, "%c:\\PSLog\\%d_version.txt", tst_dump_info.cDriveLetter,tick);  
    }
	  else
	  {
    	kal_wsprintf(strFSName, "%c:\\PSLog\\%04d_%02d%02d_%02d%02d_%d_version.txt", tst_dump_info.cDriveLetter,
               rtc_time.u1Year + 2000,
               rtc_time.u1Mon,
               rtc_time.u1Day,
               rtc_time.u1Hour,
               rtc_time.u1Min,
               rtc_time.u1Sec
               );
	  }
  }
  #else //#if !define(__SMART_PHONE_MODEM__)   
  {     
    kal_uint32 tick;     
    
    tick = kal_get_systicks();
    //create/open the file
    kal_wsprintf(strFSName, "%c:\\PSLog\\%d_version.txt", tst_dump_info.cDriveLetter,tick);  
  }
  #endif  //#if !define(__SMART_PHONE_MODEM__)

  fHandle = FS_Open(strFSName, FS_CREATE_ALWAYS); //overwrite it if if has existed  
  
  if (fHandle < 0)
    return;
    
  FS_Write(fHandle, "MTK HW Version = ", 17, &written_bytes);
  FS_Write(fHandle, base_release_hw_ver, strlen(base_release_hw_ver), &written_bytes);
  FS_Write(fHandle, "\n", 1, &written_bytes);
  FS_Write(fHandle, "MTK SW Version = ", 17, &written_bytes);
  FS_Write(fHandle, base_release_sw_ver, strlen(base_release_sw_ver), &written_bytes);
  FS_Write(fHandle, "\n", 1, &written_bytes);  
  FS_Close(fHandle);
}

//Load the filter settings from SD:\\PSLog\\catcher_filter.bin
__tstfileFunc int tst_file_load_Catcher_filter_from_files(void)
{
  FS_HANDLE  fHandle;
  WCHAR strFSName[36];//i.e. X:\PSLog\00000.dmp
  kal_uint32 read_data;
  kal_uint32 read_len;
  int res = 0;
  
  kal_wsprintf(strFSName, "%c:\\PSLog\\catcher_filter.bin", tst_dump_info.cDriveLetter);
  fHandle = FS_Open(strFSName, FS_READ_ONLY); //overwrite it if if has existed  
  
  if (fHandle < 0)
  {
    tst_sys_trace("[TST] Can't find catcher_filter.bin from SD.");
    res = -1;
    goto LOAD_FILTER_EXIT;
  }
  
  //bin file content layout
  // header (4 bytes)
  // version (4 bytes)
  // l1 data length(4 bytes) 
  // l1 data ( (l1_n+3)/4*4 bytes )
  // ps module length (4 bytes) 
  // ps module data ( ps_m_n bytes )  
  // ps trace length (4 bytes) 
  // ps trace data ( ps_t_n bytes )
  // ps sap length (4 bytes) 
  // ps sap data ( ps_s_n bytes )
  
  //read header
  res = FS_Read(fHandle, &read_data, 4, &read_len);
  if (read_data != BIN_FILE_HEADER)
  {
    res = -2;
    goto LOAD_FILTER_EXIT;
  }
 
  //read version
  res = FS_Read(fHandle, &read_data, 4, &read_len);
  if (read_data == 0x00000001)
  { 
    kal_uint32 i;
    unsigned char* data_ptr;    
    
    for (i=0;i<4;++i)
    {    
      //read length
      res = FS_Read(fHandle, &read_data, 4, &read_len);
      data_ptr = (unsigned char*)get_ctrl_buffer(read_data);
      
      //read data
      res = FS_Read(fHandle, data_ptr, read_data, &read_len);      
      
      switch (i)
      {
        case 0: //l1        
          if(if_buffer_all_zero( data_ptr, read_data))
          {
            tst_l1trace_flag = KAL_FALSE;
          }
          else
          {
            tst_l1trace_flag = KAL_TRUE;                
          }
          trc_setfilter(data_ptr, read_data);
        break;
        case 1: //tst module
          memcpy(tst_module_filter_g, data_ptr, read_data);
        break;
        case 2: //tst trace
          memcpy(tst_trace_filter_g, data_ptr, read_data);
        break;
        case 3: //tst sap
          memcpy(tst_sap_filter_g, data_ptr, read_data);
        break;
        default:
        break;
      }
      
      free_ctrl_buffer(data_ptr);
    } //for (i=0;i<4;++i)
    
    res = 0;
  }
  else
  {
    FS_Close(fHandle);
    res = -3;
    goto LOAD_FILTER_EXIT;
  }
 
LOAD_FILTER_EXIT: 
  FS_Close(fHandle);
  return res; 
}

__tstfileFunc void tst_file_set_log2SD_option(void)
{
  // decide the tst output mode
  if ( (TST_OUTPUT_MODE == 0) || (tst_ft_mode == KAL_TRUE)) //UART only
  {  
    tst_dump_info.tst_write2_sd_option = TST_Write2File_None;
  }
  else if (TST_OUTPUT_MODE == 1) //FILE only
  {
    tst_dump_info.tst_write2_sd_option = TST_Write2File_Only;
  }
  else   //Both UART and File
  { 
    tst_dump_info.tst_write2_sd_option = TST_Write2File_Both;
  }
  
  #ifdef __USB_MODEM_CARD_SUPPORT__
    tst_file_wait_data_card_for_ready();
  #endif  //__USB_MODEM_CARD_SUPPORT__
  
  if (tst_dump_info.tst_write2_sd_option != TST_Write2File_None)
  {       
    //tst_open_file_to_write();
    tst_file_open_file_to_write();
    tst_is_PsTrc_open = KAL_TRUE;        
    tst_dump_info.bAlreadyAssertDump = KAL_FALSE;        
    
    //check the pre-defined filter files
    if (tst_file_load_Catcher_filter_from_files() != 0)
    {  
      //Use the default filters if no filters are set
      if (bLoadMiniLogFilter == KAL_TRUE || tst_check_filter_enabled() == KAL_FALSE)
      {
        tst_sys_trace("[TST] Use the pre-defined filters for logging");  
        tst_file_update_predefined_filters();
      }
      else
      {
        tst_sys_trace("[TST] Use the pre-defined filters from NVRAM for logging");  
      }
    }
    else
    {
      tst_sys_trace("[TST] Use the pre-defined filters from SD for logging");  
    }
    if (if_buffer_all_zero(tst_module_filter_g, TST_MODULE_FILTER_LEN))
      tst_pstrace_flag = KAL_FALSE;
    else
      tst_pstrace_flag = KAL_TRUE;  	
    
  }
}

__tstfileFunc void tst_file_sp_check_sd_ready(void)
{
#ifdef __SMART_PHONE_MODEM__    
  if (tst_err_log_to_file == NO_CARD)
  {
    kal_uint32 cur_time;
    extern kal_uint32 tst_check_sd_avail_tick;
    
	cur_time = kal_get_systicks();
    
    //check it every two second
    if (kal_ticks_to_secs(cur_time-tst_check_sd_avail_tick) > 2)
    {
      //tst_set_log2SD_option();
      tst_check_sd_avail_tick = cur_time;
    }
  }
#endif  //#ifdef __SMART_PHONE_MODEM__   
}

//Return
//0: nothing happen, 
//1: to start only log to file, 
//2: to stop only log to file
__tstfileFunc kal_uint32 tst_file_check_if_output2uart(void)
{
  kal_uint32 cWriteToFileInd=0;
    
  if (TST_OUTPUT_MODE == 2) //output to both UART and File
  {
    kal_uint32 ratio;
    cWriteToFileInd = 0;
    ratio = tst_get_ring_buffer_usage() * 100 / TST_RING_BUFFER_SIZE;
    
    if (tst_dump_info.tst_write2_sd_option == TST_Write2File_Both)
    {
      if (ratio > 70 ) // > 70%
      {
        tst_dump_info.tst_write2_sd_option = TST_Write2File_Only;

        cWriteToFileInd = 1; //1: to start  logging to file, 

        //reset the counter
        tst_dump_info.nOmitPacketCount = 1; //this will be reset at tst_indicate_write_to_file_status()
      }
    }
    else 
    {
      if (ratio < 10 ) // <10%
      {        
        tst_dump_info.tst_write2_sd_option = TST_Write2File_Both;
        cWriteToFileInd = 2;
      }else
      {
        tst_dump_info.nOmitPacketCount++; //this will be reset at tst_indicate_write_to_file_status()
      }
    }        
  }

  return cWriteToFileInd;
}

/*************************************************************************
* FUNCTION
*  tst_create
*
* DESCRIPTION
*  This function implements tst entity's create handler.
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/
__tstfileFunc kal_bool
tst_file_transferrer_create(comptask_handler_struct **handle)
{
  static const comptask_handler_struct tst_file_transferrer_handler_info =
  {
    tst_file_transferrer_main,      /* task entry function */
    tst_file_transferrer_init,        /* task initialization function */
    tst_file_transferrer_reset    /* task reset handler */
  };

  *handle = (comptask_handler_struct *)&tst_file_transferrer_handler_info;
  return KAL_TRUE;
}


/*************************************************************************
* FUNCTION
*  tst_file_transferrer_init
*
* DESCRIPTION
*  This function calls component task's initialization handler
*
* PARAMETERS
*  task_index  -  task's index
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
__tstfileFunc kal_bool tst_file_transferrer_init(void)
{
  tst_dump_info.cDriveLetter = 0xFF;  // init it as a impossible char
  tft_event_group = kal_create_event_group("TFTEVT");
  return KAL_TRUE;  
}


/*************************************************************************
* FUNCTION
*  tst_file_transferrer_reset
*
* DESCRIPTION
*  This function implements xyz's reset handler
*
* PARAMETERS
*  task_index  -  task's index
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
__tstfileFunc kal_bool
tst_file_transferrer_reset(void)
{
  return KAL_TRUE;
}



/*************************************************************************
* FUNCTION
*  tst_file_transferrer_main
*
* DESCRIPTION
*  This function implements tst task's entry function
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

__tstfileFunc void tst_file_transferrer_main( task_entry_struct * task_entry_ptr )
{
  kal_uint32  event_group;
  kal_uint32 b_write_version = 0;
  
  tst_file_set_log2SD_option();   
  tst_nvram_statistic_handler(NVRAM_READ); //read statistic
  
  while (1){
    //wait for event to indicate if Transferrer needs to take the action
    kal_retrieve_eg_events(  tst_event_group,
                             TST_EVENT_OPEN_FILE | TST_EVENT_WRITE_CREATE_TO_FILE | TST_EVENT_WRITE_TO_FILE | TST_EVENT_LGA_LOG2FILE_REQ,
                             KAL_OR_CONSUME,
                             &event_group,
                             KAL_SUSPEND);
            
    //switch the event cases
    if (TST_EVENT_OPEN_FILE & event_group)
    {  //open file to write
      tst_file_open_file_to_write();
      
       //indicate the file has created and opened
      kal_set_eg_events(tst_event_group, TST_EVENT_OPEN_FILE_OK, KAL_OR);
    }
    else if (TST_EVENT_WRITE_CREATE_TO_FILE & event_group){  
      //write to file and create a new file      
      tst_file_dump_create_file();
      
      //indicate the actions complete
      kal_set_eg_events(tst_event_group, TST_EVENT_WRITE_CREATE_TO_FILE_OK, KAL_OR);      
    }
    else if (TST_EVENT_WRITE_TO_FILE & event_group){
      //write to file
      tst_file_dump_file();
      
      //indicate the action completes
      kal_set_eg_events(tst_event_group, TST_EVENT_WRITE_TO_FILE_OK, KAL_OR);      
    }
    #if defined(__LOGACC_ENABLE__) && !defined(UNIT_TEST) 
    else if (TST_EVENT_LGA_LOG2FILE_REQ & event_group)
    {
      tst_file_write_logacc_logs();
    }
    #endif  //#if defined(__LOGACC_ENABLE__) && !defined(UNIT_TEST) 
    
    //output the version info
    if (!b_write_version)
    {
      tst_file_write_verno_to_file();
      b_write_version = 1;
    }
    
    //Clean Up
		{
		  //Update the disk size
		  {
		    static kal_uint32 tst_file_disk_check_interval = 0;  
		    if (tst_file_disk_check_interval>TST_FILE_DISK_CHECK_PERIOD)
		    {
		      tst_file_get_disk_phy_space(tst_dump_info.cDriveLetter);
		      tst_file_disk_check_interval = 0;
		    }
		    else
		      ++tst_file_disk_check_interval;
		  }  
		}                                      
  }  //end of while(1)
}


/*************************************************************************
* FUNCTION                                                            
*  tst_file_open_file_to_write
*
* DESCRIPTION                                                           
*   open a file and prepare for writing
*
* PARAMETERS
*  None
* 
*
* RETURNS
*  None
*
*
*****************************************************************************/
#ifdef __SMART_PHONE_MODEM__
  __tstfilezidata kal_char error_msg_str[32]; //debug
#endif  //#ifdef __SMART_PHONE_MODEM__
__tstfileFunc void tst_file_open_file_to_write(void)
{
  kal_char driveLetter;  
  FS_HANDLE  fHandle;
 
   if (tst_dump_info.tst_write2_sd_option == TST_Write2File_None)  return;   
 
  tst_dump_info.bHeadOfOnePacket = KAL_FALSE;
  tst_dump_info.bAssertForFull = KAL_FALSE;
  tst_dump_info.nOmitPacketCount = 0;
        
  //if(stack_query_boot_mode() != NORMAL_BOOT) 
#if defined(__SMART_PHONE_MODEM__) 
  if (tst_ft_mode == KAL_TRUE)  
#else //#if defined(__SMART_PHONE_MODEM__) 
  if(kal_query_boot_mode() != NORMAL_BOOT) 
#endif  //#if defined(__SMART_PHONE_MODEM__) 
  {  
    #if defined(__SMART_PHONE_MODEM__)    
      //There is some unknow state while booting
      sprintf(error_msg_str, "Boot mode:%d", (kal_uint32)kal_query_boot_mode());    
      tst_sys_trace(error_msg_str);              
    #endif  //#if defined(__SMART_PHONE_MODEM__) 
      
    return;        
  }    
  
  if (tst_dump_info.buffer == NULL || tst_dump_info.L1Buffer == NULL)
  {  
    tst_err_log_to_file = ERR_ALLOC_MEM;
    goto FAIL_EXIT;
  }

  //1. check if removable dis exits
  driveLetter = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, 0);
  if (driveLetter <67 || driveLetter > 72)
  { 
    #ifdef __SMART_PHONE_MODEM__       
      sprintf(error_msg_str, "Boot mode:%d", (kal_uint32)driveLetter);    
      tst_sys_trace(error_msg_str);   
    #endif  //#ifdef __SMART_PHONE_MODEM__
    return;
  }
  tst_dump_info.cDriveLetter = driveLetter;
  
  {//2. query the vacancy
    kal_bool res = tst_file_get_disk_phy_space(driveLetter);
    if (!res){goto FAIL_EXIT;}
  }//2. end of querying the vacancy
   
  //3. create the file X:\pslog\log??.dmp  
  fHandle = tst_file_create_file();  //create a new file
  
  if (fHandle < 0) {
    goto FAIL_EXIT;
  }//failed to open or create the file
      
  tst_dump_info.nDiskFreeSpace -= TST_MAX_LOG_SIZE_FOR_SINGLE_FILE;
  tst_dump_info.nFileFreeSpace = TST_MAX_LOG_SIZE_FOR_SINGLE_FILE - (1<<12); //4k for buffer
  tst_dump_info.nCommitCountDown = TST_COMMIT_BATCH;  
  tst_err_log_to_file = NO_LOG_ERROR;
  return;
  
FAIL_EXIT:  
  tst_dump_info.tst_write2_sd_option = TST_Write2File_None;
  return;
}


/*************************************************************************
* FUNCTION                                                            
*  tst_file_write_to_file
*
* DESCRIPTION                                                           
*   write data to the log file
*
* PARAMETERS
*  None
* 
*
* RETURNS
*  None
*
*
*****************************************************************************/
__tstfileFunc kal_bool tst_file_write_file(kal_uint8 *buffer, kal_uint32 length)
{
  kal_int32 res;
  kal_uint32 written_bytes;
  //write and commit
  
  if (length == 0) return KAL_TRUE;
  
  #if !defined(__SMART_PHONE_MODEM__)
  res = FS_Extend(tst_dump_info.fHandle, length);  
  
  if (FS_NO_ERROR != res)
  {
    tst_err_log_to_file = ERR_EXTEND;
    goto FAIL_EXIT;
  }
  #endif  //#if !defined(__SMART_PHONE_MODEM__)
    
  res = FS_Write(tst_dump_info.fHandle, tst_dump_info.buffer, length, &written_bytes);

  if (FS_NO_ERROR != res)
  {
    tst_err_log_to_file = ERR_WRITE;
    goto FAIL_EXIT;
  }
  
  tst_dump_info.nCommitCountDown--;
  if (tst_dump_info.nCommitCountDown == 0)
  {
    tst_dump_info.nCommitCountDown = TST_COMMIT_BATCH;

    #if !defined(__SMART_PHONE_MODEM__)
      // flush the FS buffer every nCommitCountDown times
      res = FS_Commit(tst_dump_info.fHandle);
      
      if (FS_NO_ERROR != res)
      {
        tst_err_log_to_file = ERR_COMMIT;
        goto FAIL_EXIT;
      }
    #endif  //#if !defined(__SMART_PHONE_MODEM__)
  }
  
  return KAL_TRUE;
  
FAIL_EXIT:    
  tst_dump_info.tst_write2_sd_option = TST_Write2File_None;
  return KAL_FALSE;
}

/*************************************************************************
* FUNCTION                                                            
*  tst_file_dump_create_file
*
* DESCRIPTION                                                           
*   write logs to the file. After the file is full, create a new file
*
* PARAMETERS
*  None
* 
*
* RETURNS
* 
*
*
*****************************************************************************/

__tstfileFunc void tst_file_dump_create_file(void)
{    
  FS_HANDLE fHandle;
  kal_int32 res;
  kal_bool  bRet;

  //move logs from the buffer to the file
  bRet = tst_file_write_file(tst_dump_info.buffer, tst_dump_info.nBufferPtr);    
  if (!bRet) goto FAIL_EXIT;

  tst_dump_info.nBufferPtr = 0;
  
  res = FS_Close(tst_dump_info.fHandle);
  if (res < 0)
  {
    tst_err_log_to_file = ERR_CLOSE;
    goto FAIL_EXIT;
  }
  
  if (tst_dump_info.nDiskFreeSpace < TST_FILE_MIN_DISK_SIZE ) //128kBytes as minimal size
  {
    tst_err_log_to_file = DISK_FULL;
    goto FAIL_EXIT;
  }
  tst_dump_info.fHandle = 0;
  
  fHandle = tst_file_create_file();  //create a new file
  if (fHandle < 0) //failed to open or create the file
  {
    goto FAIL_EXIT;
  }
     
  return;
  
FAIL_EXIT:

  return;
}

/*************************************************************************
* FUNCTION                                                            
*  tst_file_dump_file
*
* DESCRIPTION                                                           
*   write logs to the file.
*
* PARAMETERS
*  None
* 
*
* RETURNS
* 
*
*
*****************************************************************************/

__tstfileFunc void tst_file_dump_file(void)
{
  kal_bool bRet = tst_file_write_file(tst_dump_info.buffer, TST_FSWRITE_BUFFER_SIZE);
  
  if (!bRet)
  {
    tst_err_log_to_file   = ERR_WRITE;    
  }
  
}

/*************************************************************************
* FUNCTION                                                            
*  tst_file_create_file
*
* DESCRIPTION                                                           
*   create and open the new file according to the current time
*
* PARAMETERS
*  None
* 
*
* RETURNS
*  FS_HANDLE: the file handle of the created file
*
*
*****************************************************************************/

__tstfileFunc FS_HANDLE tst_file_create_file(void)
{
  WCHAR strFSName[36];//i.e. X:\PSLog\00000.dmp
  FS_HANDLE  fHandle;
       
  //create/open the folder "X:\PSLog\"   
  kal_wsprintf(strFSName, "%c:\\PSLog\\", tst_dump_info.cDriveLetter);
  FS_CreateDir(strFSName);
    
  #if !defined(__SMART_PHONE_MODEM__)
  {
    RTC_CTRL_GET_TIME_T rtc_time;
    DCL_HANDLE rtc_handler;
    
    rtc_handler = DclRTC_Open(DCL_RTC,FLAGS_NONE);
    DclRTC_Control(rtc_handler, RTC_CMD_GET_TIME, (DCL_CTRL_DATA_T *)&rtc_time); // New API with CMD & DATA 

    //create/open the file
    kal_wsprintf(strFSName, "%c:\\PSLog\\%04d_%02d%02d_%02d%02d_%d.dmp", tst_dump_info.cDriveLetter,
               rtc_time.u1Year + 2000,
               rtc_time.u1Mon,
               rtc_time.u1Day,
               rtc_time.u1Hour,
               rtc_time.u1Min,
               rtc_time.u1Sec
             );
    kal_wsprintf(tst_dump_info.strAssertFolderName, 
             "%c:\\PSLog\\%04d_%02d%02d_%02d%02d_%d\\", tst_dump_info.cDriveLetter,
               rtc_time.u1Year + 2000,
               rtc_time.u1Mon,
               rtc_time.u1Day,
               rtc_time.u1Hour,
               rtc_time.u1Min,
               rtc_time.u1Sec
             );
  }
  #else //#if !define(__SMART_PHONE_MODEM__)   
  {     
    kal_uint32 tick;     
    
    tick = kal_get_systicks();
    //create/open the file
    kal_wsprintf(strFSName, "%c:\\PSLog\\%d.dmp", tst_dump_info.cDriveLetter,tick);
    kal_wsprintf(tst_dump_info.strAssertFolderName, 
               "%c:\\PSLog\\%d.files\\", tst_dump_info.cDriveLetter,tick);
  }
  #endif  //#if !define(__SMART_PHONE_MODEM__)

  fHandle = FS_Open(strFSName, FS_CREATE_ALWAYS); //overwrite it if if has existed
  
  if (fHandle < 0)
  {  //error openning the file
    goto FAIL_EXIT;
  }
  {
    //write the header 
    kal_uint32 version = 0x02;
    kal_mem_cpy(tst_dump_info.buffer, (kal_uint8*)&version, 4);
    tst_dump_info.nBufferPtr = 4;  
      
    tst_dump_info.fHandle = fHandle;
  }
  return fHandle;
  
FAIL_EXIT:  
  tst_err_log_to_file = ERR_OPEN;  
  tst_dump_info.tst_write2_sd_option = TST_Write2File_None;
  return -1;
}

//0: Not ready, 1:ok
__tstfileFunc kal_uint32 tst_file_wait_data_card_for_ready(void)
{
#ifdef __USB_MODEM_CARD_SUPPORT__  
  if (tst_dump_info.tst_write2_sd_option == TST_Write2File_None)
    return 0;
  else
  {
    kal_uint32 event_group;
    
    kal_retrieve_eg_events(  tft_event_group,
          TFT_EVENT_SD_CARD_READY,
          KAL_OR_CONSUME,
          &event_group,
          KAL_SUSPEND);
  }
#endif  //#ifdef __USB_MODEM_CARD_SUPPORT__  
  
  return 1;
}


__tstfileFunc kal_bool tst_file_get_disk_phy_space(kal_char driveLetter)
{
	FS_DiskInfo diskInfo;
	WCHAR strFSName[8];
	kal_uint32 totalFreeSpace;
	
	kal_wsprintf(strFSName, "%c:\\", driveLetter);
	//FAT document: only the first time calling for a drive is time-consuming.
	if (0 > FS_GetDiskInfo(strFSName, &diskInfo, FS_DI_BASIC_INFO|FS_DI_FREE_SPACE))
	{//Failed for this drive, take it not exist
  	 tst_err_log_to_file = NO_CARD;
  	 return KAL_FALSE;
	}  

  //calculate for the free space
  /*total disk size could be bigger than 2G (kal_int32) or 4G (kal_uint32)*/
  totalFreeSpace =  (diskInfo.BytesPerSector * 
                                diskInfo.SectorsPerCluster / 1024) *
                                diskInfo.FreeClusters; //in unit of KBytes, to prevent it exceed kal_int32

  if (totalFreeSpace > (1<<20))
  {//if the free size > 1GBytes, just bookkeep it as 1G
    	totalFreeSpace = (1<<30);
  }
  else
  {
    	totalFreeSpace *= 1024;
  }
 
  if (totalFreeSpace < TST_MAX_LOG_SIZE_FOR_SINGLE_FILE)
  {
    tst_err_log_to_file = DISK_FULL;
    return KAL_FALSE;
  }
  
  tst_dump_info.nDiskFreeSpace = totalFreeSpace;
  
  return KAL_TRUE;
}


#else //__TST_WRITE_TO_FILE__

//#pragma arm section code= "PRIMARY_ROCODE" rwdata = "PRIMARY_RW" , rodata = "PRIMARY_RODATA" , zidata = "PRIMARY_ZI" 
__tstfileFunc kal_bool tst_file_transferrer_create(comptask_handler_struct **handle)
{
  return KAL_FALSE;  
}

#endif //__TST_WRITE_TO_FILE__

