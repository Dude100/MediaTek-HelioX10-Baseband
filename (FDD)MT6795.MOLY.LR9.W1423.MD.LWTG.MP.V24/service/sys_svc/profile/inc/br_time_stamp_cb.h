/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2009
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
 *   br_time_stamp_cb.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Prototype definition of time stamp measurement callback function
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#ifndef __BR_TIME_STAMP_CB_H__
#define __BR_TIME_STAMP_CB_H__

#include "br_sw_types.h"

#ifdef __cplusplus
extern "C" {
#endif

//==============================================================================
// TimeStamp callback function prototype 
//==============================================================================

typedef enum {
     TS_BEGIN = 0
    ,TS_END
} TS_TIME_ANCHOR;

typedef void (*CB_TS_RECORD)(U32 id, TS_TIME_ANCHOR anchor);
typedef void (*CB_TS_INFO)(U32 id, U32 data1, U32 data2, U32 data3);
typedef void (*CB_TS_ID_STR_RECORD)(const char *id_str, U32 id, TS_TIME_ANCHOR anchor);
typedef void (*CB_TS_ID_STR_INFO)(const char *id_str, U32 id, U32 data1, U32 data2, U32 data3);

//==============================================================================
// TimeStamp macro definition
//==============================================================================

#if defined(__TIME_STAMP__)

    #if defined(__RTLSIM__)

        #define CALLBACK_TS_BEGIN(id,func)\
                    do{\
                        if( NULL != (func) ) {\
                            ((CB_TS_ID_STR_RECORD)(func))(QUOTE(id##[BEGIN]), id, TS_BEGIN);\
                        }\
                    }while(0)
    
        #define CALLBACK_TS_END(id,func)\
                    do{\
                        if( NULL != (func) ) {\
                            ((CB_TS_ID_STR_RECORD)(func))(QUOTE(id##[END]), id, TS_END);\
                        }\
                    }while(0)
    
        #define CALLBACK_TS_INFO(id,d1,d2,d3,func)\
                    do{\
                        if( NULL != (func) ) {\
                            ((CB_TS_ID_STR_INFO)(func))(QUOTE(id##[INFO]), id, d1, d2, d3);\
                        }\
                    }while(0)
    
    #else
    
        #define CALLBACK_TS_BEGIN(id,func)\
                    do{\
                        if( NULL != (func) ) {\
                            ((CB_TS_RECORD)(func))(id, TS_BEGIN);\
                        }\
                    }while(0)
    
        #define CALLBACK_TS_END(id,func)\
                    do{\
                        if( NULL != (func) ) {\
                            ((CB_TS_RECORD)(func))(id, TS_END);\
                        }\
                    }while(0)
    
        #define CALLBACK_TS_INFO(id,d1,d2,d3,func)\
                    do{\
                        if( NULL != (func) ) {\
                            ((CB_TS_INFO)(func))(id, d1, d2, d3);\
                        }\
                    }while(0)
    
    #endif

#else

    #define CALLBACK_TS_BEGIN(id,func)
    #define CALLBACK_TS_END(id,func)
    #define CALLBACK_TS_INFO(id,d1,d2,d3,func)

#endif

#ifdef __cplusplus
}
#endif

#endif

