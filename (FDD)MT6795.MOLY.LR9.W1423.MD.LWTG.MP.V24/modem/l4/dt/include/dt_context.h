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
/*******************************************************************************
 * Filename:
 * ---------
 *	dt_context.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for DT global context.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/

#ifndef _DT_CONTEXT_H
#define _DT_CONTEXT_H
#ifdef __MTK_TARGET__
    #define DT_UART_SetOwner DT_HAL_UART_SetOwner
    #define DT_UART_GetBytes DT_HAL_UART_GetBytes
    #define DT_UART_PutBytes DT_HAL_UART_PutBytes
    #define DT_UART_ClrTxBuffer DT_HAL_UART_ClrTxBuffer
    #define DT_UART_ClrRxBuffer DT_HAL_UART_ClrRxBuffer
    #define DT_UART_GetOwnerID DT_HAL_UART_GetOwnerID
#else
    #define DT_UART_SetOwner temp_DT_UART_SetOwner
    #define DT_UART_GetBytes temp_DT_UART_GetBytes
    #define DT_UART_PutBytes temp_DT_UART_PutBytes
    #define DT_UART_ClrTxBuffer temp_DT_UART_ClrTxBuffer
    #define DT_UART_ClrRxBuffer temp_DT_UART_ClrRxBuffer
    #define DT_UART_GetOwnerID temp_DT_UART_GetOwnerID
#endif

//#include "fat_fs.h"
#include "dcl.h"

//#include "kal_non_specific_general_types.h"
#include "dt_common_enum.h"
#include "fs_type.h"
//#include "event_shed.h"
//#include "stack_timer.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
    
#define dt_skip_spaces(source_string_ptr)                               \
      while( source_string_ptr->string_ptr[ source_string_ptr->index ]    \
                                 == DT_SPACE )                          \
      {                                                                   \
        source_string_ptr->index++;                                          \
      }

#define dt_skip_none_a(source_string_ptr, length)                               \
      while( (source_string_ptr->index < length) && !((source_string_ptr->string_ptr[ source_string_ptr->index ] == DT_CHAR_A) ||\
             (source_string_ptr->string_ptr[ source_string_ptr->index ] == dt_char_a)) ) \
      {                                                                   \
        source_string_ptr->index++;                                          \
      }

#define DT_IS_LOWER( alpha_char )   \
  ( ( (alpha_char >= dt_char_a) && (alpha_char <= dt_char_z) ) ?  1 : 0 )

#define DT_IS_UPPER( alpha_char )   \
   ( ( (alpha_char >= DT_CHAR_A) && (alpha_char <= DT_CHAR_Z) ) ? 1 : 0 )      
#define DT_IS_NUMBER( alpha_char )   \
   ( ( (alpha_char >= DT_CHAR_0) && (alpha_char <= DT_CHAR_9) ) ? 1 : 0 )

#define DT_IS_ALPHA( alpha_char )   \
   ( ( DT_IS_UPPER(alpha_char) || DT_IS_LOWER(alpha_char) ) ? 1 : 0 )

#define DT_IS_SYMBOL( alpha_char )   \
   ( ( (alpha_char == DT_CHAR_PLUS) || (alpha_char == DT_CHAR_STAR) || \
       (alpha_char == DT_CHAR_POUND) || (alpha_char == DT_COMMA) || \
       (alpha_char == DT_CHAR_DOT) || (alpha_char == DT_FORWARD_SLASH) || \
       (alpha_char == DT_COLON) || (alpha_char == DT_HAT) || \
       (alpha_char == DT_CHAR_MINUS) || \
       (alpha_char == DT_L_SQ_BRACKET) || \
       (alpha_char == DT_R_SQ_BRACKET) || \
       (alpha_char == DT_L_ANGLE_BRACKET) || \
        (alpha_char == DT_CHAR_ULINE) || \
         (alpha_char == DT_SPACE) || \
           (alpha_char == DT_SEMICOLON) || \
       (alpha_char == DT_R_ANGLE_BRACKET) \
     ) ? 1 : 0 )      


typedef struct 
{
   kal_uint16  head;
   kal_uint16  length;
   kal_uint8   data[DT_MAX_DATA_INPUT_QUEUE_LENGTH];

} dt_uart_input_queue_struct;

typedef struct 
{
   kal_uint16  head;
   kal_uint16  length;
   kal_uint8   data[DT_MAX_DATA_OUTPUT_QUEUE_LENGTH];

} dt_uart_output_queue_struct;

typedef struct dt_transfer_struct
{
    module_type dest_mod; 
} dt_transfer_struct;

typedef struct
{
/***********************************************************************/
/* Below context are placed in the front of DT context                 */
/* to increase immediate offset access , to reduce ROM size            */
/* Please KEEP the position for the following frequent used variables  */
/***********************************************************************/
   FS_HANDLE   fd[2];
   kal_uint8      data_folder;
   kal_bool       printingDownloadData_flag ;  /* use to indicate unfinished task of printing download data, rtw_ind will check this */
   kal_uint16    printingData_loopCount; /* used in copy/move file action and read file action */
   kal_wchar * OpenFilename;
   kal_wchar*  downloadFullpath;
   kal_wchar*  data_rename_path[4];/* [0][1] used to record file rename/move path *
                                    * [2][3] used to record copy file path        */
	
   eventid                       event_id[2]; /*0: for file list pause timer 
                                                1: for file read/write guard timer */
   event_scheduler              *event_scheduler_ptr;                                                       
   kal_uint16		 	       cmee_err; // error value 
   void*                       	       arg_list[DT_MAX_ARG_NUM];
   kal_bool                   	       uart_stop_send_flag;
    UART_PORT                   port; 
    dt_transfer_struct           transfer; 
   kal_uint16                        write_data_size;
   dt_transfer_state_enum     transfer_state;
   kal_wchar 	                    *download_filename; 											
   kal_bool 				abort_action;										
   kal_bool 				download_complete;	  
   kal_uint8 				state; 
/***********************************************************************/
/* Above context are placed in the front of DT context                 */
/* to increase immediate offset access , to reduce ROM size            */
/* Please try to KEEP the position for these frequent used variables   */
/***********************************************************************/

   dt_uart_input_queue_struct     		uart_input_queue;
   dt_uart_output_queue_struct     	uart_output_queue;

   #ifndef __MTK_TARGET__
   kal_uint8 temp_output_string[20];
   dt_uart_input_queue_struct temp_uart_input_buffer;
   dt_uart_output_queue_struct temp_uart_output_buffer;
   module_type uart_owner;
   kal_uint16 uart_port; 
   kal_uint8 test_uart_stop_send;
   kal_bool test_abort_flag;
   #endif
}dt_context_struct;

typedef struct dt_string_struct
{
   kal_uint16   index;
   kal_uint8   *string_ptr;
   kal_uint8	cmd_mode;
} dt_string_struct;

extern dt_context_struct  dt_context_g;
#define DT_PTR   (&dt_context_g)


#endif /* _DT_CONTEXT_H */

