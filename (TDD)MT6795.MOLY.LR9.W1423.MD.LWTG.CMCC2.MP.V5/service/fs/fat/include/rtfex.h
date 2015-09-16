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
 *   rtfex.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *    about exception handling
 *
 * Author:
 * -------
 *
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
/**************************************************************************/
/*                                                                        */
/*  File: RTFEX.H                                Copyright (c) 1998,2002  */
/*  Version: 4.0                                 On Time Informatik GmbH  */
/*                                                                        */
/*                                                                        */
/*                                      On Time        /////////////----- */
/*                                    Informatik GmbH /////////////       */
/* --------------------------------------------------/////////////        */
/*                                  Real-Time and System Software         */
/*                                                                        */
/**************************************************************************/

/* RTFiles internal exception handling

   Every try block contains a code block, exception handlers, and a finally
   block. The code block is executed first, followed by exception handlers
   (if an exception is raised) and the finally block. Exception handlers and
   finally blocks are executed only once. If an exception is raised within
   an exception handler, the finally block is executed and the exception is
   propagated. If an exception is raised with a finally handler, it is
   propagated. When an exception handler runs to its end, the exception is
   NOT considered to be handled.
*/

#ifndef _RTFEX_H
#define _RTFEX_H

#include "rtfiles.h"

#define RTFX_SETJMP


#ifndef RTTDLL
   #ifdef RTT32DLL // assume all public symbols are in a separate EXE/DLL
      #if defined(_MSC_VER)
         #define RTTDLL __declspec(dllimport)
         #define RTTDDL __declspec(dllimport)
         #define RTTDDL2
      #elif defined(__BORLANDC__)
         #define RTTDLL
         #define RTTDDL extern
         #define RTTDDL2 __import
      #else // importing needs no special declaration or is not supported
         #define RTTDLL
         #define RTTDDL extern
         #define RTTDDL2
      #endif
   #else            // assume all public symbols are in this EXE/DLL
      #define RTTDLL
      #define RTTDDL extern
      #define RTTDDL2
   #endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef RTFX_SETJMP      // always TRUE in MTK target
   #include <setjmp.h>

   #if defined(__MTK_TARGET__) && defined(__RVCT__)
   /*
    * inc\clib.h has optimized setjmp buffer for RVCT3.1 (only 48 bytes are enough) - W10.29
    */
   #include "clib.h"
   #define XCONTEXT              mtk_jmpbuf  // defined in inc\clib.h
   #else    // !__MTK_TARGET__ || !__RVCT__
   /*
    * 1. In ADS projects, use optimized 44 bytes jmpbuf instead of official 128 bytes jmpbuf.
    * 2. use an unique name different from mtk_jmpbuf because mtk_jmpbuf will be included by kal_release.h in the future.
    */
   typedef int mtkfs_jmpbuf[11];
   #define XCONTEXT              mtkfs_jmpbuf
   #endif   // __MTK_TARGET__ && __RVCT__

   #define XSAVECONTEXT(C)       setjmp(*(C))
   #define XRESTORECONTEXT(C, V) longjmp(*(C), V)
#elif defined(_WIN32) || defined (WIN32) || defined (__FLAT__)
   #include <rtfex32.h>
#else
   #include <rtfex16.h>
#endif


#ifdef _MSC_VER
   #define XAPI _fastcall
#elif defined __BORLANDC__
   #define XAPI __fastcall
#else
   #define XAPI
#endif

struct _XDataTag;

/*
 * The data structure compiled with RVCT 3.1 may be larger than compiled with ADS 1.2 because
 * 8-bytes data elements required 8-bytes alignment. Move XCONTEXT to the 1st member to resolve
 * this issue. (W10.18)
 */
typedef struct _XDataTag {
   XCONTEXT Context;
   struct _XDataTag * Next;
   int XValue;
   int State;
   int IsHandled;
} _XData;

typedef enum { XReturn, XBreak } XAction;

#define XNOEX 0
#define XCODE XNOEX
#define XFINALLY -1

RTTDLL void    XAPI _XRaiseException(int XValue);
RTTDLL void    XAPI _XReExecute(void);
RTTDLL void    XAPI _XHandled(_XData * XD);
RTTDLL void    XAPI _XInitBlock(_XData * XD);
RTTDLL XAction XAPI _XCloseBlock(_XData * XD);
RTTDLL XAction XAPI _XCloseBlockCanReturn(_XData * XD);
RTTDLL XAction XAPI _XCloseBlockNoPropagate(_XData * XD);
RTTDLL _XData * XAPI _XHandler(void);

#define XHANDLER    _XHandler()
#define XRAISE(X)   _XRaiseException(X)
#define XREEXECUTE  _XReExecute()

#if defined(__FS_XDATA_MEMORY_NOT_IN_STACK__)

#define XHANDLED    _XHandled(_XDataBlock)

#define XTRY  while (1) { _XData * _XDataBlock = (_XData*)fs_mem_alloc(FS_MEM_TYPE_XDATA, sizeof(_XData), NULL); _XInitBlock(_XDataBlock); switch (XSAVECONTEXT(&(_XDataBlock->Context))) {
// add an exception handler record to the exception stack

#define XENDX    } if (_XCloseBlock(_XDataBlock) == XBreak) break; }
#define XEND     } { int x = _XDataBlock->XValue; if (_XCloseBlockCanReturn  (_XDataBlock) == XReturn) return x; else if (x >= 0) break; } }
#define XEND_API } { int x = _XDataBlock->XValue; if (_XCloseBlockNoPropagate(_XDataBlock) == XReturn) return x; else if (x >= 0) break; } }

#define XVALUE  _XDataBlock->XValue

#else   // !__FS_XDATA_MEMORY_NOT_IN_STACK__

#define XHANDLED    _XHandled(&_XDataBlock)

#define XTRY  while (1) { _XData _XDataBlock; _XInitBlock(&_XDataBlock); switch (XSAVECONTEXT(&_XDataBlock.Context)) {
// add an exception handler record to the exception stack

#define XENDX    } if (_XCloseBlock(&_XDataBlock) == XBreak) break; }
#define XEND     } { int x = _XDataBlock.XValue; if (_XCloseBlockCanReturn  (&_XDataBlock) == XReturn) return x; else if (x >= 0) break; } }
#define XEND_API } { int x = _XDataBlock.XValue; if (_XCloseBlockNoPropagate(&_XDataBlock) == XReturn) return x; else if (x >= 0) break; } }

#define XVALUE  _XDataBlock.XValue

#endif  // __FS_XDATA_MEMORY_NOT_IN_STACK__


typedef enum
{
    RTFRetry,
    RTFFail
} RTFErrorAction;

typedef RTFErrorAction (RTFAPI * RTFCriticalErrorHandler)(WCHAR Drive, DWORD SerialNumber, int ErrorCode);

RTTDLL void RTFAPI MTErrHdlr_RemovableDeviceRWError(RTFDevice *Dev);
RTTDLL RTFErrorAction RTFAPI HandleCriticalError(RTFDevice * Dev, int ErrorCode);

#ifdef  __cplusplus
}
#endif

#endif


