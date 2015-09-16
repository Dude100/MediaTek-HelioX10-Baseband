;/*****************************************************************************
;*  Copyright Statement:
;*  --------------------
;*  This software is protected by Copyright and the information contained
;*  herein is confidential. The software may not be copied and the information
;*  contained herein may not be used or disclosed except with the written
;*  permission of MediaTek Inc. (C) 2005
;*
;*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
;*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
;*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
;*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
;*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
;*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
;*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
;*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
;*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
;*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
;*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
;*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
;*
;*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
;*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
;*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
;*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
;*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
;*
;*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
;*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
;*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
;*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
;*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
;*
;*****************************************************************************/
;
;/*****************************************************************************
; *
; * Filename:
; * ---------
; *   regioninit.s
; *
; * Project:
; * --------
; *   Maui_Software
; *
; * Description:
; * ------------
; *   This Module defines the initialization of RW/ZI/RO data for each area..
; *
; * Author:
; * -------
; * -------
; * -------
; * -------
; *
; *============================================================================
; *             HISTORY
; * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
; *------------------------------------------------------------------------------
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; *------------------------------------------------------------------------------
; * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
; *============================================================================
; ****************************************************************************/

;**************************************************************
;*     File: regioninit.s                                     *
;*  Purpose: Application Startup Code                         *
;**************************************************************
;
; This file contains the macro and supporting subroutines to
; copy RO code and RW data from ROM to RAM and zero-initialize
; the ZI data areas in RAM.


; All of this should be set as an assembler argument using the -pd option.
; For example to set support for Angel it would be -pd "MT6218 SETL {TRUE}"
; see also make\comp.mak


;  /* Added by Anthony Chin 10/28/2001. */
 CODE32
 
        AREA RegionInit, CODE, READONLY

        EXPORT INT_InitRegions
        EXPORT INT_InitEMIInitCode
        EXPORT INT_InitPreInitData
        EXPORT INT_InitMMRegions
        EXPORT SYS_InitRegions

; This macro:
; a) copies RO code and/or RW data from ROM at Load$$area$$Base
; to RAM at Image$$area$$Base, of length Image$$area$$Length bytes.
; b) fills with zero the ZI data in RAM at Image$$area$$ZI$$Base, 
; of length Image$$area$$ZI$$Length bytes.
        
        MACRO
        macro_RegionInit $areaname

        LCLS   namecp
        LCLS   copyloadsym
        LCLS   copybasesym
        LCLS   copylensym
        LCLS   zibasesym
        LCLS   zilensym

namecp SETS "$areaname"

copyloadsym SETS  "|Load$$$$":CC:namecp:CC:"$$$$Base|"
copybasesym SETS  "|Image$$$$":CC:namecp:CC:"$$$$Base|"
copylensym  SETS  "|Image$$$$":CC:namecp:CC:"$$$$Length|"
zibasesym   SETS  "|Image$$$$":CC:namecp:CC:"$$$$ZI$$$$Base|"
zilensym    SETS  "|Image$$$$":CC:namecp:CC:"$$$$ZI$$$$Length|"

; The following symbols are generated by the linker.  They are imported 
; WEAKly because they may not all have defined values. Those which are
; undefined will take the value zero.

        IMPORT $copyloadsym [WEAK]
        IMPORT $copybasesym [WEAK]
        IMPORT $copylensym [WEAK]
        IMPORT $zibasesym [WEAK]
        IMPORT $zilensym [WEAK]
        
        IF :DEF: _SIMULATION

                                        ; For co-sim load,
                                        ; memory is initialized by hardware...   

        ELSE  ; _SIMULATION 

        LDR     r0, =$copyloadsym       ; load address of region
        LDR     r1, =$copybasesym       ; execution address of region
        MOV     r2, r1                  ; copy execution address into r2
        LDR     r4, =$copylensym
        ADD     r2, r2, r4              ; add region length to execution address to...
                                        ; ...calculate address of word beyond end...
                                        ; ... of execution region
        BL      copy

        LDR     r2, =$zilensym          ; get length of ZI region
        LDR     r0, =$zibasesym         ; load base address of ZI region
        MOV     r1, r0                  ; copy base address of ZI region into r1
        ADD     r1, r1, r2              ; add region length to base address to...
                                        ; ...calculate address of word beyond end...
                                        ; ... of ZI region
        BL      zi_init_32

        ENDIF ; _SIMULATION 

        MEND
        
; This macro:
; a) fills with zero the ZI data in RAM at Image$$area$$ZI$$Base, 
; of length Image$$area$$ZI$$Length bytes.

        MACRO
        macro_ZeroInit $areaname
        
        LCLS   namecp
        LCLS   copyloadsym
        LCLS   copybasesym
        LCLS   copylensym
        LCLS   zibasesym
        LCLS   zilensym

namecp SETS "$areaname"

copyloadsym SETS  "|Load$$$$":CC:namecp:CC:"$$$$Base|"
copybasesym SETS  "|Image$$$$":CC:namecp:CC:"$$$$Base|"
copylensym  SETS  "|Image$$$$":CC:namecp:CC:"$$$$Length|"
zibasesym   SETS  "|Image$$$$":CC:namecp:CC:"$$$$ZI$$$$Base|"
zilensym    SETS  "|Image$$$$":CC:namecp:CC:"$$$$ZI$$$$Length|"

; The following symbols are generated by the linker.  They are imported 
; WEAKly because they may not all have defined values. Those which are
; undefined will take the value zero.

        IMPORT $copyloadsym [WEAK]
        IMPORT $copybasesym [WEAK]
        IMPORT $copylensym [WEAK]
        IMPORT $zibasesym [WEAK]
        IMPORT $zilensym [WEAK]       
        
        LDR     r2, =$zilensym          ; get length of ZI region
        LDR     r0, =$zibasesym         ; load base address of ZI region
        MOV     r1, r0                  ; copy base address of ZI region into r1
        ADD     r1, r1, r2              ; add region length to base address to...
                                        ; ...calculate address of word beyond end...
                                        ; ... of ZI region
        BL      zi_init_32

        MEND

; This macro:
; a) copies RO code and/or RW data from ROM at Load$$area$$Base
; to RAM at Image$$area$$Base, of length Image$$area$$Length bytes.

        MACRO
        macro_CopyRW $areaname
        
        LCLS   namecp
        LCLS   copyloadsym
        LCLS   copybasesym
        LCLS   copylensym
        LCLS   zibasesym
        LCLS   zilensym

namecp SETS "$areaname"

copyloadsym SETS  "|Load$$$$":CC:namecp:CC:"$$$$Base|"
copybasesym SETS  "|Image$$$$":CC:namecp:CC:"$$$$Base|"
copylensym  SETS  "|Image$$$$":CC:namecp:CC:"$$$$Length|"
zibasesym   SETS  "|Image$$$$":CC:namecp:CC:"$$$$ZI$$$$Base|"
zilensym    SETS  "|Image$$$$":CC:namecp:CC:"$$$$ZI$$$$Length|"

; The following symbols are generated by the linker.  They are imported 
; WEAKly because they may not all have defined values. Those which are
; undefined will take the value zero.

        IMPORT $copyloadsym [WEAK]
        IMPORT $copybasesym [WEAK]
        IMPORT $copylensym [WEAK]
        IMPORT $zibasesym [WEAK]
        IMPORT $zilensym [WEAK]

        LDR     r0, =$copyloadsym       ; load address of region
        LDR     r1, =$copybasesym       ; execution address of region
        MOV     r2, r1                  ; copy execution address into r2
        LDR     r4, =$copylensym
        ADD     r2, r2, r4              ; add region length to execution address to...
                                        ; ...calculate address of word beyond end...
                                        ; ... of execution region
        BL      copy

        MEND         

        MACRO
        macro_BackwardCopyRW $areaname
        
        LCLS   namecp
        LCLS   copyloadsym
        LCLS   copybasesym
        LCLS   copylensym
        LCLS   zibasesym
        LCLS   zilensym

namecp SETS "$areaname"

copyloadsym SETS  "|Load$$$$":CC:namecp:CC:"$$$$Base|"
copybasesym SETS  "|Image$$$$":CC:namecp:CC:"$$$$Base|"
copylensym  SETS  "|Image$$$$":CC:namecp:CC:"$$$$Length|"
zibasesym   SETS  "|Image$$$$":CC:namecp:CC:"$$$$ZI$$$$Base|"
zilensym    SETS  "|Image$$$$":CC:namecp:CC:"$$$$ZI$$$$Length|"

; The following symbols are generated by the linker.  They are imported 
; WEAKly because they may not all have defined values. Those which are
; undefined will take the value zero.

        IMPORT $copyloadsym [WEAK]
        IMPORT $copybasesym [WEAK]
        IMPORT $copylensym [WEAK]
        IMPORT $zibasesym  [WEAK]
        IMPORT $zilensym [WEAK]

        LDR     r0, =$copyloadsym       ; load address of region
        LDR     r1, =$copybasesym       ; execution address of region
        MOV     r2, r1                  ; copy execution address into r2
        LDR     r4, =$copylensym
        SUB     r4, r4, #4
        ADD     r0, r0, r4
        ADD     r1, r1, r4
        
        BL      backward_copy

        MEND         

;
; NoteXXX: INT_InitXXXRegions is called from boot.s to initialize the specified execution regions.
;          The register r12 will be used in the bootarm.s. We should be careful not to
;          overwrite r12.
;

;
;/*************************************************************************/
;/*                                                                       */
;/* FUNCTION                                                              */
;/*   INT_InitEMIInitCode                                                 */
;/*                                                                       */
;/* DESCRIPTION                                                           */
;/*   Initialize EMI INIT code                                            */
;/*                                                                       */
;/* INPUTS                                                                */
;/*   None                                                                */
;/*                                                                       */
;/* OUTPUTS                                                               */
;/*   None                                                                */
;/*************************************************************************/
; VOID INT_InitEMIInitCode(VOID)
; {
;
INT_InitEMIInitCode

   MOV   r7,lr
   macro_RegionInit EMIINIT_CODE
   IF :DEF:MT6251 :LOR: :DEF:MT6252 :LOR: :DEF:MT6252H :LOR: :DEF: MT6280
   macro_RegionInit INTSRAM_DATA_PREINIT
   ENDIF

   macro_RegionInit SINGLE_BANK_CODE
   
   BX    r7 
; }
;


;/*************************************************************************/
;/*                                                                       */
;/* FUNCTION                                                              */
;/*   INT_InitPreInitData                                                 */
;/*                                                                       */
;/* DESCRIPTION                                                           */
;/*   Initialize CACHED_PREINIT_ZI region                                        */
;/*                                                                       */
;/* INPUTS                                                                */
;/*   None                                                                */
;/*                                                                       */
;/* OUTPUTS                                                               */
;/*   None                                                                */
;/*************************************************************************/
; VOID INT_InitPreInitData(VOID)
; {
;

INT_InitPreInitData

   MOV   r7,lr
   
   macro_ZeroInit CACHED_EXTSRAM_PREINIT_ZI
   
   BX    r7 
; }
;
;
;/*************************************************************************/
;/*                                                                       */
;/* FUNCTION                                                              */
;/*   INT_InitMMRegions                                                   */
;/*                                                                       */
;/* DESCRIPTION                                                           */
;/*   Initialize the multimedia region                                    */
;/*                                                                       */
;/* INPUTS                                                                */
;/*   None                                                                */
;/*                                                                       */
;/* OUTPUTS                                                               */
;/*   None                                                                */
;/*************************************************************************/
; VOID INT_InitMMRegions(VOID)
; {
;
INT_InitMMRegions

   MOV   r7,lr

   IF :DEF:_NAND_FLASH_BOOTING_:LOR::DEF:_NOR_FLASH_BOOTING_:LOR::DEF:__EMMC_BOOTING__

   ELSE ; _NAND_FLASH_BOOTING_  || _NOR_FLASH_BOOTING_ || __EMMC_BOOTING__

   IF :DEF:MT6219 :LOR: :DEF:MT6226 :LOR: :DEF:MT6227 :LOR: :DEF:MT6228 :LOR: :DEF:MT6229 :LOR: :DEF:MT6226M :LOR: :DEF:MT6230 :LOR: :DEF:MT6225 :LOR: :DEF:MT6227D :LOR: :DEF:MT6226D :LOR: :DEF:MT6238 :LOR: :DEF:MT6235 :LOR: :DEF:MT6268T :LOR: :DEF: MT6235B :LOR: :DEF: MT6239 :LOR: :DEF: TK6516 :LOR: :DEF: MT6268A :LOR: :DEF: MT6253T :LOR: :DEF: MT6516 :LOR: :DEF: MT6268 :LOR: :DEF: MT6253 :LOR: :DEF: MT6253E :LOR: :DEF: MT6253L :LOR: :DEF: MT6252 :LOR: :DEF: MT6252H :LOR: :DEF: MT6236 :LOR: :DEF: MT6236B :LOR: :DEF: MT6268H :LOR: :DEF: MT6270A :LOR: :DEF: MT6256 :LOR: :DEF: MT6255 :LOR: :DEF: MT6276 :LOR: :DEF: MT6573 :LOR: :DEF: MT6575 :LOR: :DEF: MT6577
   macro_RegionInit INTSRAM_MULTIMEDIA
   ENDIF

   ENDIF ; _NAND_FLASH_BOOTING_ || _NOR_FLASH_BOOTING_ || __EMMC_BOOTING__
   
   BX    r7                                 ; Return to caller
; }
;


;
;/*************************************************************************/
;/*                                                                       */
;/* FUNCTION                                                              */
;/*   INT_InitRegions                                                     */
;/*                                                                       */
;/* DESCRIPTION                                                           */
;/*   Initialize the RW/ZI regions                                        */
;/*                                                                       */
;/* INPUTS                                                                */
;/*   None                                                                */
;/*                                                                       */
;/* OUTPUTS                                                               */
;/*   None                                                                */
;/*************************************************************************/
; VOID INT_InitRegions(VOID)
; {
;
INT_InitRegions

   MOV   r7,lr
   
   IF (:DEF:_NAND_FLASH_BOOTING_ :LAND: :LNOT: :DEF:__NFB_SINGLE_ROM__) :LOR: :DEF:_NOR_FLASH_BOOTING_ :LOR: :DEF:__EMMC_BOOTING__
   
   macro_RegionInit INTSRAM_CODE
   IF :DEF:MT6251 :LOR: :DEF:MT6252 :LOR: :DEF:MT6252H
   ; macro_RegionInit INTSRAM_DATA
   ELSE
   macro_RegionInit INTSRAM_DATA
   ENDIF
   
   macro_RegionInit L2TCM_CODE
   macro_RegionInit L2TCM_DATA
   macro_RegionInit FLEXL2_DATA
   
   macro_BackwardCopyRW PRIMARY_CACHED_EXTSRAM_PROTECTED_RES
   macro_BackwardCopyRW PRIMARY_CACHED_EXTSRAM
   macro_BackwardCopyRW PRIMARY_EXTSRAM
   macro_RegionInit ROM_1
   macro_ZeroInit   PRIMARY_EXTSRAM
   macro_ZeroInit   PRIMARY_CACHED_EXTSRAM
      
   macro_ZeroInit   SECONDARY_EXTSRAM
   macro_ZeroInit   SECONDARY_EXTSRAM_ZI
   macro_ZeroInit   CACHED_EXTSRAM
   
   IF :DEF:__GADGET_SUPPORT__
   macro_ZeroInit   EXTSRAM_GADGET
   ENDIF
   
   ELSE ; (_NAND_FLASH_BOOTING_ && !__NFB_SINGLE_ROM__) || _NOR_FLASH_BOOTING_ || __EMMC_BOOTING__

    macro_RegionInit INTSRAM_CODE
    macro_RegionInit INTSRAM_DATA
   
   IF :DEF: MT6573 :LOR: :DEF: MT6575 :LOR: :DEF: MT6577
      macro_RegionInit L2TCM_CODE
      macro_RegionInit L2TCM_DATA
      macro_RegionInit FLEXL2_DATA
   ENDIF

   IF :DEF:MT6238 :LOR: :DEF:MT6235 :LOR: :DEF: MT6235B :LOR: :DEF: MT6239 :LOR: :DEF: MT6268A :LOR: :DEF: MT6268 :LOR: :DEF: MT6236 :LOR: :DEF: MT6236B :LOR: :DEF: MT6270A :LOR: :DEF: TK6280 :LOR: :DEF: MT6280 :LOR: :DEF: MT6256 :LOR: :DEF: MT6255 :LOR: :DEF: MT6276 :LOR: :DEF: MT6573 :LOR: :DEF: MT6575 :LOR: :DEF: MT6577 :LOR: :DEF: MT6253E :LOR: :DEF: MT6253L :LOR: :DEF: MT6252 :LOR: :DEF: MT6252H
      macro_RegionInit PAGE_TABLE
      macro_RegionInit CACHED_EXTSRAM
      macro_RegionInit CACHED_EXTSRAM_PROTECTED_RES
      macro_RegionInit CACHED_EXTSRAM_NVRAM_LTABLE
      macro_BackwardCopyRW DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_RW
      macro_RegionInit CACHED_EXTSRAM_CODE      
      macro_BackwardCopyRW DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_RW
      macro_ZeroInit   DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI
      macro_ZeroInit   DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI_MMIPOOL
      macro_ZeroInit   DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI
      macro_ZeroInit   DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_MMIPOOL
      macro_ZeroInit   DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_VIDEOPOOL
   ENDIF

   macro_RegionInit EXTSRAM
   macro_RegionInit EXTSRAM_PROTECTED_RES
   macro_RegionInit EXTSRAM_NVRAM_LTABLE 


   IF :DEF:MT6223 :LOR: :DEF: MT6223P :LOR: :DEF:MT6238 :LOR: :DEF:MT6235 :LOR: :DEF:MT6268T :LOR: :DEF: MT6235B :LOR: :DEF: MT6239 :LOR: :DEF: TK6516 :LOR: :DEF: MT6268A :LOR: :DEF: MT6253T :LOR: :DEF: MT6516 :LOR: :DEF: MT6268 :LOR: :DEF: MT6253 :LOR: :DEF: MT6253E :LOR: :DEF: MT6253L :LOR: :DEF: MT6252 :LOR: :DEF: MT6252H :LOR: :DEF: MT6236 :LOR: :DEF: MT6236B :LOR: :DEF: MT6268H :LOR: :DEF: MT6270A :LOR: :DEF: MT6256 :LOR: :DEF: MT6255 :LOR: :DEF: MT6276 :LOR: :DEF: MT6573 :LOR: :DEF: MT6575 :LOR: :DEF: MT6577
      macro_RegionInit EXTSRAM_DSP_TX
      macro_RegionInit EXTSRAM_DSP_RX
   ENDIF

   IF :DEF: MT6573 :LOR: :DEF: MT6575 :LOR: :DEF: MT6577
      macro_RegionInit EXTSRAM_MCU_NC_DSP_NC_SHAREMEM
   ENDIF

   ENDIF ; (_NAND_FLASH_BOOTING_ && !__NFB_SINGLE_ROM__) || _NOR_FLASH_BOOTING_ || __EMMC_BOOTING__

   BX    r7                                 ; Return to caller
; }
;

;
;/*************************************************************************/
;/*                                                                       */
;/* FUNCTION                                                              */
;/*   SYS_InitRegions                                                     */
;/*                                                                       */
;/* DESCRIPTION                                                           */
;/*   Initialize the 2nd MAUI RW/ZI regions                               */
;/*                                                                       */
;/* INPUTS                                                                */
;/*   None                                                                */
;/*                                                                       */
;/* OUTPUTS                                                               */
;/*   None                                                                */
;/*************************************************************************/
; VOID SYS_InitRegions(VOID)
; {
;
SYS_InitRegions

   ;/* save working regsters since this function may be called by a C-code caller */

   STMDB sp!, {r0-r7}
   MOV   r7,lr

   ;

   IF :DEF:_NAND_FLASH_BOOTING_:LOR::DEF:_NOR_FLASH_BOOTING_:LOR::DEF:__EMMC_BOOTING__
   ; The Regions Init by reversed order

   IF :DEF:MT6229 :LOR: :DEF:MT6230 :LOR: :DEF: MT6238 :LOR: :DEF: MT6235 :LOR: :DEF: MT6268T :LOR: :DEF: MT6235B :LOR: :DEF: MT6239 :LOR: :DEF: TK6516 :LOR: :DEF: MT6268A :LOR: :DEF: MT6516 :LOR: :DEF: MT6268 :LOR: :DEF: MT6236 :LOR: :DEF: MT6236B :LOR: :DEF: MT6268H :LOR: :DEF: MT6270A :LOR: :DEF: MT6256 :LOR: :DEF: MT6255 :LOR: :DEF: MT6276 :LOR: :DEF: MT6573 :LOR: :DEF: MT6575 :LOR: :DEF: MT6577
      macro_RegionInit SECONDARY_EXTSRAM_DSP_TX
      macro_RegionInit SECONDARY_EXTSRAM_DSP_RX
   ENDIF 

   IF :DEF: MT6276 :LOR: :DEF: MT6270A :LOR: :DEF: MT6573 :LOR: :DEF: MT6575 :LOR: :DEF: MT6577
      macro_RegionInit SECONDARY_EXTSRAM_MCU_NC_DSP_NC_SHAREMEM
   ENDIF
   
   macro_RegionInit INTSRAM_MULTIMEDIA

   ; optional regions
   macro_RegionInit CODE_PATCH_CODE
   macro_RegionInit CACHED_CODE_PATCH_CODE

   ; init RW
   macro_BackwardCopyRW DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_RW
   IF :DEF:__GADGET_SUPPORT__     
   macro_BackwardCopyRW EXTSRAM_GADGET
   ENDIF
   macro_BackwardCopyRW CACHED_EXTSRAM
   macro_BackwardCopyRW DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_RW      
   macro_BackwardCopyRW CACHED_EXTSRAM_NVRAM_LTABLE
   macro_BackwardCopyRW SECONDARY_EXTSRAM
   macro_BackwardCopyRW SECONDARY_EXTSRAM_RW

   ; ZeroInit 2nd large pool or dynamic cacheable-switching(dnc) must be the last
   macro_ZeroInit   DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI
   macro_ZeroInit   DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI_MMIPOOL
   macro_ZeroInit   DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI
   macro_ZeroInit   DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_MMIPOOL
   macro_ZeroInit   DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_VIDEOPOOL

   ; ZeroInit Secondary LargePool must be the last step
   macro_ZeroInit   SECONDARY_EXTSRAM_LARGEPOOL_NORMAL

   ENDIF ; _NAND_FLASH_BOOTING_ || _NOR_FLASH_BOOTING_ || __EMMC_BOOTING__

   MOV lr, r7
   LDMIA sp!, {r0-r7}

   BX    lr                                 ; Return to caller
; }
;


; --- copy and zi_init subroutines

; copy is a subroutine which copies a region, from an address given by 
; r0 to an address given by r1. The address of the word beyond the end
; of this region is held in r2. r3 is used to hold the word being copied. 
copy
        CMP     r1, r2                 ; loop whilst r1 < r2
        LDRLO   r3, [r0], #4
        STRLO   r3, [r1], #4
        BLO     copy
        BX lr                 ; return from subroutine copy
        
; backward_copy is a subroutine which copies a region, from an address given by 
; r0 to an address given by r1. The address of the word beyond the end
; of this region is held in r2. r3 is used to hold the word being copied. 
backward_copy
        CMP     r1, r2                 ; loop whilst r1 < r2
        LDRGE   r3, [r0], #-4
        STRGE   r3, [r1], #-4
        BGE     backward_copy
        BX lr                 ; return from subroutine copy

; zi_init is a subroutine which zero-initialises a region,
; starting at the address in r0. The address of the word
; beyond the end of this region is held in r1.
zi_init
        MOV     r2, #0
        CMP     r0, r1                 ; loop whilst r0 < r1
        STRLO   r2, [r0], #4
        BLO     zi_init 
        BX lr                 ; return from subroutine zi_init

; zi_init_32 is a subroutine which zero-initialises a region,
; starting at the address in r0. The length is held in r2.
; the address of the 4-byte beyound the end of this region is 
; held in r1. set 32 bytes zero per loop.
zi_init_32
        STMDB   sp!, {r8-r10}          ; save extra working register
        MOV     r3, #0
        MOV     r8, #0
        MOV     r9, #0
        MOV     r10, #0
        SUBS    r2, r2, #0x20          ; loop while r2 > 32

zi_init_32_loop
        STMCSIA r0!, {r3,r8-r10}
        STMCSIA r0!, {r3,r8-r10}
        SUBCSS  r2, r2, #0x20          ; loop while r2 > 32
        BCS     zi_init_32_loop
        LDMIA   sp!, {r8-r10}          ; restore extra working register
        B       zi_init
        BX lr                 ; return from subroutine zi_init
        END

