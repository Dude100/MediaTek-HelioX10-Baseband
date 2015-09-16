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
 *   bl_dbgprint.c
 *
 * Project:
 * --------
 *   Bootloader
 *
 * Description:
 * ------------
 *   Minimal printf-like function
 *     Acceptable formats are %d, %o, %x, %c, %s, %f(default fraction part is 4 digits)
 *     All special characters in the fmt string is distinguishable (ex: \n, \t, %%, \\t)
 *     no precision, width, or modifier;
 *     The inernal buffer is only MAXCHAR long, there is no check to make sure it fits.
 *     It calls a function putchar(char a) to output each character.
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
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_general_types.h"
#include "bl_custom.h"
#include "bl_UART_SW.H"
#include <stdarg.h>

#if defined(BL_DEBUG)
#define MAXCHARS     512
#define MAXFRACT     10000
#define NumFract     4

kal_char buf[MAXCHARS];

static LOG_LEVEL debug_level = LOG_DEBUG;

/**********************************************************
Description : Convert an integer as string.
Input       : Buffer pointer, value to convert.
Output      : Non
***********************************************************/

static void itoa(kal_char **buf, kal_int32 i, kal_int32 base)
{
   kal_char *s;
#define LEN   20
   kal_int32 rem;
   static kal_char rev[LEN+1];

   rev[LEN] = 0;
   if (i == 0)
   {
      (*buf)[0] = '0';
      ++(*buf);
      return;
   }
   s = &rev[LEN];
   while (i)
   {
      rem = i % base;
      if (rem < 10)
         *--s = rem + '0';
      else if (base == 16)
         *--s = "abcdef"[rem - 10];
      i /= base;
   }
   while (*s)
   {
      (*buf)[0] = *s++;
      ++(*buf);
   }
}


/**********************************************************
Description : Convert floating point to string.
Input       : Buffer pointer, value to convert.
Output      : Non
***********************************************************/

void itof(kal_char **buf, kal_int32 i)
{
   kal_char *s;
#define LEN   20
   kal_int32 rem, j;
   static kal_char rev[LEN+1];

   rev[LEN] = 0;
   s = &rev[LEN];
   for (j= 0 ; j < NumFract ; j++)
   {
      rem = i % 10;
         *--s = rem + '0';
      i /= 10;
   }
   while (*s)
   {
      (*buf)[0] = *s++;
      ++(*buf);
   }
}


/**********************************************************
Description : debug print used internally
Input       : Buffer pointer, value to convert.
Output      : None
***********************************************************/
void bl_print_internal(LOG_LEVEL level, kal_char *fmt, va_list ap)
{
   kal_int64   dval;
   kal_int32    ival;
   kal_char    *p, *sval;
   kal_char    *bp, cval;
   kal_int32    fract;
#ifdef __ADV_DBG_PRINT__
   kal_uint32 uival, uival1, uival2;
   kal_char *bp_old;
   kal_int32 i, j;
#endif /* __ADV_DBG_PRINT__ */

   bp= buf;
   *bp= 0;
   
   if((level) < debug_level)
   {
      return;
   }

   for (p= fmt; *p; p++)
   {
      if (*p != '%')
      {
         *bp++= *p;
         continue;
      }
      switch (*++p) 
      {
         case 'd':
            ival= va_arg(ap, kal_int32);
            if (ival < 0)
            {
               *bp++= '-';
               ival= -ival;
            }
            itoa (&bp, ival, 10);
            break;
         
         case 'o':
            ival= va_arg(ap, kal_int32);
            if (ival < 0)
            {
               *bp++= '-';
              ival= -ival;
            }
            *bp++= '0';
            itoa (&bp, ival, 8);
            break;
         
         case 'x':
            ival= va_arg(ap, kal_int32);
            if (ival < 0)
            {
              *bp++= '-';
              ival= -ival;
            }
            *bp++= '0';
            *bp++= 'x';
            itoa (&bp, ival, 16);
            break;

#ifdef __ADV_DBG_PRINT__
         case 'u':
            uival= va_arg(ap, unsigned int);
            *bp++= '0';
            *bp++= 'x';
            bp_old = bp;
            uival1 = uival >> 16;
            uival2 = uival & 0x0000ffff;
            itoa(&bp, uival1, 16);
            i = (unsigned int)bp - (unsigned int)bp_old;
            if (i < 4) {           
                for (j = 3; j > (3 - i); j--) {
                    bp_old[j] = bp_old[j - (3 - i) - 1];
                }          
                for (j = 0; j <= (3 - i); j++)
                    bp_old[j] = '0';
            }
            bp = bp_old + 4;
            bp_old = bp;
            itoa(&bp, uival2, 16);
            i = (unsigned int)bp - (unsigned int)bp_old;
            if (i < 4) {            
                for (j = 3; j > (3 - i); j--) {
                    bp_old[j] = bp_old[j - (3 - i) - 1];
                }            
                for (j = 0; j <= (3 - i); j++)
                    bp_old[j] = '0';
            }
            bp = bp_old + 4;
            break;
#endif /* __ADV_DBG_PRINT__ */
         
         case 'p':
            ival= va_arg(ap, kal_int32);
            *bp++= '0';
            *bp++= 'x';
            itoa (&bp, ival, 16);
            break;
         
         case 'c':
            cval= va_arg(ap, kal_int32);
            *bp++= cval;
            break;
         
         case 'f':
            dval= va_arg(ap, kal_int64);
            if (dval < 0)
            {
               *bp++= '-';
               dval= -dval;
            }
            if (dval >= 1.0)
               itoa (&bp, (kal_int32)dval, 10);
             else
               *bp++= '0';
            *bp++= '.';
            fract= (kal_int32)((dval- (kal_int64)(kal_int32)dval)*(kal_int64)(MAXFRACT));
            itof(&bp, fract);
            break;
         
         case 's':
            for (sval = va_arg(ap, kal_char *) ; *sval ; sval++ )
               *bp++= *sval;
            break;
      }
   }
   
   *bp= 0;
   
   for (bp= buf; *bp; bp++) 
   {
      PutUARTByte(*bp);
   } 
}

/**********************************************************
Description : Print the debug information via UART1.
Input       : A String to print.
Output      : Non
***********************************************************/

void dbg_print(kal_char *fmt, ...)
{
   va_list     ap;
   va_start (ap, fmt);

   bl_print_internal(LOG_DEBUG, fmt, ap);

   va_end (ap);
}

/**********************************************************
Description : Print the debug information via UART1. (with debug level)
Input       : A String to print.
Output      : Non
***********************************************************/
void bl_print(LOG_LEVEL level, kal_char *fmt, ...)
{
   va_list     ap;
   va_start (ap, fmt);

   bl_print_internal(level, fmt, ap);

   va_end (ap);
}

/**********************************************************
Description : Set current debug level
Input       : Debug level
Output      : Non
***********************************************************/
void set_debug_level(LOG_LEVEL level)
{
   debug_level = level;
}

#else

void dbg_print(kal_char *fmt, ...)
{
}

void bl_print(LOG_LEVEL level, kal_char *fmt, ...)
{
}

void set_debug_level(LOG_LEVEL level)
{
}

#endif

