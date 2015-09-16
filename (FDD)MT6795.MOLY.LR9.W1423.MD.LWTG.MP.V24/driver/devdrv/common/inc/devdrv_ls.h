/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *   devdrv_ls.h
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *   Macros for different link section
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * MT6290E1_FristCall Branch sync back to MOLY Trunk
 *
 * removed!
 * removed!
 * add INTERNBLOCK2 back
 *
 * removed!
 * removed!
 * Remove input section
 ****************************************************************************/


#ifndef __DEVDRV_LS_H__
#define __DEVDRV_LS_H__

#if defined(__ARMCC_VERSION)
    #define LINK_SECTION(x)             __attribute__ ((section (x)))
#elif defined(__GNUC__) /* end of __ARMCC_VERSION */
    #define LINK_SECTION(x)             __attribute__ ((section (x)))
#elif defined(_MSC_VER) && (_MSC_VER >= 1500)
    #define LINK_SECTION(x)
#else  /* end of __GNUC__ */
    #error "Unsupported Compiler"
#endif

/* Link Sections */
#if 1 /* To Be Removed */
    #define DEVDRV_LS_INTERNCODE               LINK_SECTION("INTSRAM_ROCODE")
    #define DEVDRV_LS_INTERNZI                 LINK_SECTION("INTSRAM_ZI")
    #define DEVDRV_LS_INTERNZI_TP              LINK_SECTION("INTSRAM_ZI")
    #define DEVDRV_LS_INTERNRW                 LINK_SECTION("INTSRAM_RW")
    #define DEVDRV_LS_INTERNCONST              LINK_SECTION("INTSRAM_RODATA")
#endif

#if defined(MT6290) && defined(__ARM7EJ_S__)
    #define DEVDRV_LS_COPRO_INTSRAM_ROCODE     LINK_SECTION("COPRO_INTSRAM_ROCODE")
    #define DEVDRV_LS_COPRO_INTSRAM_RODATA     LINK_SECTION("COPRO_INTSRAM_RODATA")
    #define DEVDRV_LS_COPRO_INTSRAM_RW         LINK_SECTION("COPRO_INTSRAM_RW")
    #define DEVDRV_LS_COPRO_INTSRAM_ZI         LINK_SECTION("COPRO_INTSRAM_ZI")
#endif

#define DEVDRV_LS_INTSRAM_ROCODE           LINK_SECTION("INTSRAM_ROCODE")
#define DEVDRV_LS_INTSRAM_RODATA           LINK_SECTION("INTSRAM_RODATA")
#define DEVDRV_LS_INTSRAM_RW               LINK_SECTION("INTSRAM_RW")
#define DEVDRV_LS_INTSRAM_ZI               LINK_SECTION("INTSRAM_ZI")
#define DEVDRV_LS_INTSRAM_EX_ROCODE        LINK_SECTION("INTSRAM_EX_ROCODE")
#define DEVDRV_LS_DRAM_EX_ROCODE           LINK_SECTION("DRAM_EX_ROCODE")
#define DEVDRV_LS_EMIINITZI                LINK_SECTION("EMIINITZI")
#define DEVDRV_LS_EMIINITCODE              LINK_SECTION("EMIINITCODE")
#define DEVDRV_LS_SECOND_PART              LINK_SECTION("SECOND_PART")
#define DEVDRV_LS_SNORCODE                 LINK_SECTION("SNORCODE")
//#define DEVDRV_LS_INTERNBLOCK0_ZI          LINK_SECTION("INTERNBLOCK0_ZI")
//#define DEVDRV_LS_INTERNBLOCK1_RW          LINK_SECTION("INTERNBLOCK1_RW")
#define DEVDRV_LS_INTERNBLOCK2_RW          LINK_SECTION("INTERNBLOCK2_RW")
//#define DEVDRV_LS_INTERNBLOCK1_ZI          LINK_SECTION("INTERNBLOCK1_ZI")
#define DEVDRV_LS_INTERNBLOCK2_ZI          LINK_SECTION("INTERNBLOCK2_ZI")
//#define DEVDRV_LS_INTERNBLOCK1_CO          LINK_SECTION("INTERNBLOCK1_CO")
#define DEVDRV_LS_INTERNBLOCK2_CO          LINK_SECTION("INTERNBLOCK2_CO")
#define DEVDRV_LS_SHOULD_NOT_USED_RODATA   LINK_SECTION("SHOULD_NOT_USED_RODATA")
#define DEVDRV_LS_DYNAMICCACHEABLERW_NC    LINK_SECTION("DYNAMICCACHEABLERW_NC")
#define DEVDRV_LS_DYNAMICCACHEABLEZI_NC    LINK_SECTION("DYNAMICCACHEABLEZI_NC")
#define DEVDRV_LS_DYNAMICCACHEABLERW_C     LINK_SECTION("DYNAMICCACHEABLERW_C")
#define DEVDRV_LS_DYNAMICCACHEABLEZI_C     LINK_SECTION("DYNAMICCACHEABLEZI_C")
#define DEVDRV_LS_PHY_EXTSRAM              LINK_SECTION("PHY_EXTSRAM")

#define DEVDRV_LS_NONCACHEDRW    LINK_SECTION("NONCACHEDRW")
#define DEVDRV_LS_NONCACHEDZI    LINK_SECTION("NONCACHEDZI")


/* if __REDUCE_TCM_SUPPORT__ is defined,
 * LS_INTXXXCODE_REDUCE_TCM_SUPPORT is placed in normal text section
 */
#if defined(__REDUCE_TCM_SUPPORT__)
    #define LS_INTERNCODE_REDUCE_TCM_SUPPORT
    #define LS_INTSRAM_ROCODE_REDUCE_TCM_SUPPORT
#else
    #define LS_INTERNCODE_REDUCE_TCM_SUPPORT LS_INTSRAM_ROCODE
    #define LS_INTSRAM_ROCODE_REDUCE_TCM_SUPPORT LS_INTSRAM_ROCODE
#endif


/* Predefined Macro: http://www.cppblog.com/byc/archive/2010/11/15/133663.html
   

C++:
    __cplusplus

GCC:
    __GNUC__ 
    __GNUC_MINOR__ 
    __GNUC_PATCHLEVEL__
    __GNUG__    equivalent to testing (__GNUC__ && __cplusplus).

MinGW:
    __MINGW32__
    __STDC__
    __GNUC__
    _WIN32, __WINNT__, __MINGW32__, _X86_, i386, __GNUC__

VC:
    _WIN32
    _MSC_VER
    _ATL_VER
    _DEBUG    Defined when compiling with /LDd, /MDd, /MLd, and /MTd. 
    _M_IX86
    _MT    Defined when /MD or /MDd (Multithreaded DLL) or /MT or /MTd (Multithreaded) is specified.  
    _UNICODE

CYGWIN:
    __CYGWIN32__

    Intel Compiler:
    __INTEL_COMPILER

Borland:
    __WIN32__
    __BORLANDC_
*/

#endif /* end of __DEVDRV_LS_H__ */


