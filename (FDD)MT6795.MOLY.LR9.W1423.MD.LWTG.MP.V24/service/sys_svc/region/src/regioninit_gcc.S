@/*****************************************************************************
@*  Copyright Statement:
@*  --------------------
@*  This software is protected by Copyright and the information contained
@*  herein is confidential. The software may not be copied and the information
@*  contained herein may not be used or disclosed except with the written
@*  permission of MediaTek Inc. (C) 2005
@*
@*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
@*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
@*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
@*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
@*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
@*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
@*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
@*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
@*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
@*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
@*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
@*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
@*
@*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
@*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
@*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
@*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
@*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
@*
@*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
@*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
@*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
@*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
@*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
@* testyg
@*****************************************************************************/
@
@/*****************************************************************************
@ *
@ * Filename:
@ * ---------
@ *   regioninit.s
@ *
@ * Project:
@ * --------
@ *   Maui_Software
@ *
@ * Description:
@ * ------------
@ *   This Module defines the initialization of RW/ZI/RO data for each area..
@ *
@ * Author:
@ * -------
@ *   Rex   Luo    (mtk00389)
@ *   Anthony Chin (mtk00276)
@ *   Shalyn Chua  (mtk00576)
@ *
@ *============================================================================
@ *             HISTORY
@ * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
@ *------------------------------------------------------------------------------
@ * $Log$
@ *
@ * 08 07 2014 carl.kao
@ * [MOLY00074828] [Need Patch] [Sanity Fail] sim卡搜网时连续发生KernelAPI和EE，sim卡无法找到网络
@ * .
@ *
@ * 08 05 2014 carl.kao
@ * [MOLY00074244] [K2][MOLY][DSPMOLY] DSP image loading enhancement - use shared buffer mechanism
@ * SoC DSP Image Loading Enhance
@ *
@ * 06 03 2014 carl.kao
@ * [MOLY00067558] [SystemService][Auto-Gen][Request For Design Change] add TCM only lds file and region init code for TCM only load for MT6752
@ * Merging //MOLY/TRUNK/MOLY/mcu/ to //MOLY/BRANCHES_LR9/LR9.W1421.MD.LWTG.MP/mcu/
@ *
@ * 05 20 2014 carl.kao
@ * [MOLY00066129] [SYSTEM SERVICE] [Region Init] Assembly Code Add Size Info for MPPT
@ * .
@ *
@ * 03 28 2013 qmei.yang
@ * [MOLY00013019] [SystemService][region init][Internal Refinement] To make sure the 1st symbol be 4 bytes aligned
@ * .
@ *
@ * 03 28 2013 qmei.yang
@ * [MOLY00012756] [SystemService] To remove useless input section by requests
@ * .
@ * 
@ * 11 05 2012 chin-chieh.hung
@ * [MOLY00005322] TATAKA merge to MOLY
@ * Integration change(SS part, exclude kal/sst/config)
@ * 
@ * 11 05 2012 chin-chieh.hung
@ * [MOLY00005322] TATAKA merge to MOLY
@ * Integration change(SS part, exclude kal/sst/config)
@ * 
@ * 11 05 2012 chin-chieh.hung
@ * [MOLY00005322] TATAKA merge to MOLY
@ * Integration change(SS part, exclude kal/sst/config)
@ * 
@ * 11 05 2012 chin-chieh.hung
@ * [MOLY00005322] TATAKA merge to MOLY
@ * Integration change(SS part, exclude kal/sst/config)
@ * 
@ * 11 05 2012 chin-chieh.hung
@ * [MOLY00005322] TATAKA merge to MOLY
@ * Integration change(SS part, exclude kal/sst/config)
@ * 
@ * 08 27 2012 qmei.yang
@ * [MOLY00001774] [SystemService][Region_Init][Internal Refinement] Support MT6577 region init and remove useless regions and compile option
@ * .
@ * 
@ *
@ * 02 09 2012 ken.lin
@ * [MAUI_03127715] [INIT][FixBug] remove redundant region init - SINGLE_BANK_CODE
@ * .
@ *
@ * 02 03 2012 ken.lin
@ * [MAUI_03112654] [System Service][MT6280] Check-in SS related modification for MT6280 E1 DVT
@ * .
@ *
@ * 01 16 2012 ken.lin
@ * [MAUI_03112654] [System Service][MT6280] Check-in SS related modification for MT6280 E1 DVT
@ * .
@ *
@ * 12 20 2011 ken.lin
@ * [MAUI_03101840] [System Service][TK6280] Merge SS modification for TK6280
@ * .
@ *
@ * 10 28 2011 ken.lin
@ * [MAUI_03063098] [System Service][BB Chip] Merge SS modification for MT6255
@ * .
@ *
@ * 10 07 2011 qmei.yang
@ * [MAUI_03045135] [SystemService][Auto-Gen][Sys Gen][scatGen][Request For Design Change] Isolate med and asm pool in scatter file for DSP shared memory
@ * Isolate med and asm pool in scatter file for DSP shared memory
@ *
@ * 09 15 2011 ken.lin
@ * [MAUI_03016796] [NVRAM] NVRAM LID Split
@ * .
@ *
@ * 09 05 2011 ken.lin
@ * [MAUI_03016796] [NVRAM] NVRAM LID Split
@ * .
@ *
@ * 06 03 2011 ken.lin
@ * [MAUI_02908670] [NewFeature][SystemService] add MT6575 support
@ * .
@ *
@ * 05 24 2011 ken.lin
@ * [MAUI_02931343] [Serial Flash] Leakage checking and recovery at boot time.
@ * .
@ *
@ * 04 08 2011 ken.lin
@ * [MAUI_02908700] [SystemService][FixBug] init DSP share memory and dump ccci share memory in MT6573
@ * .
@ *
@ * 03 16 2011 ken.lin
@ * [MAUI_02897468] [init][ChangeFeature] Resource Protect on 6251
@ * .
@ *
@ * 03 06 2011 ken.lin
@ * [MAUI_02869092] [Bootloader][Change feature] Add bootloader support on MT6252
@ * .
@ *
@ * 02 21 2011 ken.lin
@ * [MAUI_02869092] [Bootloader][Change feature] Add bootloader support on MT6252
@ * .
@ *
@ * 02 20 2011 ken.lin
@ * [MAUI_02873111] [init][ChangeFeature] modify region init for scatter file change
@ * .
@ *
@ * 02 12 2011 ken.lin
@ * [MAUI_02869092] [Bootloader][Change feature] Add bootloader support on MT6252
@ * .
@ *
@ * 01 27 2011 ken.lin
@ * [MAUI_02866548] [SystemService][NewFeature] EMB support
@ * .
@ *
@ * 01 03 2011 ken.lin
@ * [MAUI_02857100] [SystemService][ChangeFeature] remove MT6255 chip option
@ * .
@ *
@ * 11 25 2010 ken.lin
@ * [MAUI_02841889] [System Service][HAL] This CR is used for SSx to check in HAL activity
@ * .
@ *
@ * 11 18 2010 ken.lin
@ * [MAUI_02829741] [NewFeature][SystemService] add MT6258/MT6258H support
@ * .
@ *
@ * 11 17 2010 ken.lin
@ * [MAUI_02839016] [SystemService][SST] remove chip option - MT6253D
@ * .
@ *
@ * 11 10 2010 ken.lin
@ * [MAUI_02829741] [NewFeature][SystemService] add MT6258/MT6258H support
@ * .
@ *
@ * 09 19 2010 ken.lin
@ * [MAUI_02610051] [SystemService][NewFeature] add MT6573 support
@ * .
@ *
@ * 08 25 2010 ken.lin
@ * [MAUI_02610051] [SystemService][NewFeature] add MT6573 support
@ * add MT6573 support
@ *
@ * 08 05 2010 ken.lin
@ * [MAUI_02603197] [SystemService][NewFeature] add MT6253 E/L support
@ * add MT6253E/L support
@ *
@ * Jul 8 2010 mtk02554
@ * [MAUI_02581074] [SystemService][NewFeature] customer resource protection
@ * new region for protected resource
@ *
@ * Jun 30 2010 mtk02554
@ * [MAUI_02574496] [SystemService][NewFeature] add MT6251 support
@ * add MT6251 support
@ *
@ * Jun 18 2010 mtk02554
@ * [MAUI_02564887] [NewFeature][SystemService] add MT6276 support
@ * add MT6276 support
@ *
@ * Jun 16 2010 mtk02554
@ * [MAUI_02545018] [NewFeature][SystemService] add MT6255 support
@ * add MT6256 support
@ *
@ * Jun 4 2010 mtk02554
@ * [MAUI_02545018] [NewFeature][SystemService] add MT6255 support
@ * add MT6255 support
@ *
@ * Apr 15 2010 mtk02554
@ * [MAUI_02373549] [Gadget] code check in
@ * add EXTSRAM_GADGET
@ *
@ * Dec 16 2009 mtk02554
@ * [MAUI_02016794] [init][AddFeature] add support for MT6253D & MT6253 E8
@ * add support for MT6253AL (MT6253D+MT6253)
@ *
@ * Nov 22 2009 mtk02554
@ * [MAUI_01995103] [system service] [AddFeature] Merge MT6270A_DVT to MAUI
@ * add support for MT6270A
@ *
@ * Aug 27 2009 mtk00702
@ * [MAUI_01645273] [system service][AddFeature] add MT6268H support
@ * add MT6268H otpion
@ *
@ * Aug 23 2009 mtk02554
@ * [MAUI_01943549] [init][AddFeature] add MT6236 support
@ * add MT6236 and MT6236B support
@ *
@ * Feb 24 2009 mtk00702
@ * [MAUI_01635463] [init][AddFeature] add MT6253 supporting
@ * add MT6253 option
@ *
@ * Feb 9 2009 mtk01710
@ * [MAUI_01317678] [system service][add feature]support MT6268 chip
@ * Add MT6268 compile option
@ *
@ * Dec 2 2008 mtk01866
@ * [MAUI_01289041] [SystemService][NewFeature] Merge MT6516 Back to MainTrunk
@ * Merge MT6516 Back to MainTrunk
@ *
@ * Nov 12 2008 mtk01866
@ * [MAUI_01274087] [INIT][NewFeature] merge MT6253T back to MainTrunk
@ * merge MT6253T back to MainTrunk
@ *
@ * Oct 24 2008 mtk01866
@ * [MAUI_01257539] [INIT][ChangeFeature] modify the default name of CODE_PATCH_CODE to CACHED_CODE_PATC
@ * modify for NFB project
@ *
@ * Oct 17 2008 mtk01866
@ * [MAUI_01257539] [INIT][ChangeFeature] modify the default name of CODE_PATCH_CODE to CACHED_CODE_PATC
@ * add CACHED_CODE_PATCH_CODE to regioninit
@ *
@ * Oct 3 2008 mtk01866
@ * [MAUI_01248908] [NOR FDM/MTD][New Feature] Make SINGLE_BANK_CODE section cacheable on ARM9 platform.
@ * Rmove dummy code in bootarm.s and add ENSB new region support for ESNB
@ *
@ * Sep 6 2008 mtk01866
@ * [MAUI_01231807] [SystemService][NFB]  modify compile option for NFB
@ * store the need register when do SYS_InitRegions
@ *
@ * Sep 3 2008 mtk01866
@ * [MAUI_01230636] [CS5] [DCACHE PHASE3] [MAUI/08A] [W08.37] [FEATURE] Phase-in MT623X_DCACHE_DEV into
@ * phase in for DCache phase3
@ *
@ * Jun 19 2008 mtk01866
@ * [MAUI_00790254] [System Service] Merge MT6268A to maintrunk
@ * Merge 6268A back to MainTrunk
@ *
@ * Apr 24 2008 mtk01077
@ * [MAUI_00740317] [SystemService][Auto-Gen][Scatter Gen][Sys Gen][Request For Design Change] Scatter G
@ * 
@ *
@ * Apr 22 2008 mtk01866
@ * [MAUI_00749050] [SystemService][AddFeature] Merge TK6516 DVT to main trunk
@ * Add compile option for TK6516
@ *
@ * Apr 20 2008 mtk01077
@ * [MAUI_00740317] [SystemService][Auto-Gen][Scatter Gen][Sys Gen][Request For Design Change] Scatter G
@ * 
@ *
@ * Apr 3 2008 mtk01866
@ * [MAUI_00749050] [SystemService][AddFeature] Merge TK6516 DVT to main trunk
@ * Merge 6516 Back to MainTrunk
@ *
@ * Apr 2 2008 mtk01866
@ * [MAUI_00747577] [BugFix][INIT] Fix RegionInit problem.
@ * Revise backward copy problem
@ *
@ * Apr 1 2008 mtk01866
@ * [MAUI_00747577] [BugFix][INIT] Fix RegionInit problem.
@ * Fix regioninit with backward copy problem
@ *
@ * Mar 31 2008 mtk01866
@ * [MAUI_00740317] [SystemService][Auto-Gen][Scatter Gen][Sys Gen][Request For Design Change] Scatter G
@ * add backward copy for MT6235/38
@ *
@ * Mar 15 2008 mtk01866
@ * [MAUI_00732430] [INIT][AddFeature] add MT6239 and MT6235B compiltion option
@ * add compilation for MT6239/6235B
@ *
@ * Feb 14 2008 mtk01866
@ * [MAUI_00611737] [SystemService][AddFeature] 6235 scatter file refinement.
@ * modify to support refined scatter file for 35/38
@ *
@ * Jan 23 2008 MTK01866
@ * [MAUI_00610146] [INIT][AddFeature]  Merge Monza and 6268 Back to MainTrunk
@ * Merge Monza and 6268T related code
@ *
@ * Dec 13 2007 MTK01866
@ * [MAUI_00591116] [BufFix] Sync MT6223 and 6223P
@ * add MT6223P compilation
@ *
@ * Dec 3 2007 MTK01892
@ * [MAUI_00586601] [SystemService][Add Feature] move cacheable region to primary MAUI
@ * fix bootup slowly issue - move cachable region from secondary MAUI to primary MAUI.
@ *
@ * Nov 7 2007 mtk01866
@ * [MAUI_00573142] [SystemService][Add Feature]  migrate from MT6235 DVT to MainTrunke
@ * Merge MT6235 DVT to MainTrunk. 
@ *
@ * Oct 3 2007 mtk00702
@ * [MAUI_00410341] [init][AddFeature] ARM9 MMU porting
@ * 1. add INT_InitEMIInitCode() and INT_InitMMRegions()
@ * 2. refine INT_InitRegions()
@ *
@ * Sep 6 2007 mtk01568
@ * [MAUI_00541308] [System Service] [MT6238] Check-in MT6238 Compile Option into Maintrunk.
@ * 
@ *
@ * Sep 2 2007 mtk01568
@ * [MAUI_00541308] [System Service] [MT6238] Check-in MT6238 Compile Option into Maintrunk.
@ * 
@ *
@ * Sep 2 2007 mtk01568
@ * [MAUI_00541308] [System Service] [MT6238] Check-in MT6238 Compile Option into Maintrunk.
@ * 
@ *
@ * Jul 15 2007 mtk01568
@ * [MAUI_00416979] [System Service] [6223P] Check-in 6223P compile option into MAUI/07A.
@ * 
@ *
@ * Jul 5 2007 mtk01568
@ * [MAUI_00413251] [System Service] [6226D] Check-in 6226D compile option into MAUI/07A/06B.
@ * 
@ *
@ * May 1 2007 MTK01568
@ * [MAUI_00384134] [System Service] [6223] Check-in 6223 related files into main trunk.
@ * 
@ *
@ * Apr 9 2007 mtk01077
@ * [MAUI_00377311] [INIT] region_init platform condition syntax correction
@ * 
@ *
@ * Mar 29 2007 mtk01077
@ * [MAUI_00377311] [INIT] region_init platform condition syntax correction
@ * 
@ *
@ * Mar 25 2007 MTK01568
@ * [MAUI_00375788] [System Service] [6227D] Check-in 6227D related files into main trunk.
@ * 
@ *
@ * Mar 23 2007 mtk00576
@ * [MAUI_00359377] [System Service][New Feature] Porting MAUI to support MT6223
@ * Bug fix, boot-up failure for MT6223.
@ *
@ * Feb 8 2007 mtk01337
@ * [MAUI_00361983] [NOR][FDM]Enhanced Single Bank NOR Flash Support
@ * modify SINGLE_BANK_SUPPORT define
@ *
@ * Feb 6 2007 mtk01337
@ * [MAUI_00361983] [NOR][FDM]Enhanced Single Bank NOR Flash Support
@ * add initialization code for single bank RAM code
@ *
@ * Jan 18 2007 mtk00576
@ * [MAUI_00359377] [System Service][New Feature] Porting MAUI to support MT6223
@ * Porting for MT6223.
@ *
@ * Dec 4 2006 mtk01077
@ * [MAUI_00348452] Custom\System\BB\* auto generator stage 3 phase-in , scatter file
@ * 
@ *
@ * Nov 20 2006 mtk01077
@ * [MAUI_00344919] [INIT] speed up ZI procedure in region init
@ * 
@ *
@ * Nov 10 2006 mtk00576
@ * [MAUI_00342298] [Bootloader, Init, Custom][Add Feature] MT6225 supports NFB
@ * Switch the order of INSTRAM_Multimedia.
@ *
@ * Oct 5 2006 mtk00702
@ * [MAUI_00323865] [system service][AddFeature] add MT6225 support in MAUI
@ * add compilation flag
@ *
@ * Aug 29 2006 mtk01077
@ * [MAUI_00325483] [INIT][Custom] Enable MPU on all RO-code and RO-data, Rearrange scattar file layout
@ * 
@ *
@ * Jul 17 2006 mtk00702
@ * [MAUI_00211187] [System service][AddFeature] Add compilation flag to support MT6230
@ * add compilation flag MT6230
@ 
@    Rev 1.14   Aug 15 2005 11:47:48   mtk00576
@ Copy and zero-initialize the INTSRAM_MULTIMEDIA region.
@ Resolution for 12335: [CUSTOM][Enhancement] Improve performance of multi-media
@ 
@    Rev 1.13   Aug 02 2005 11:40:46   mtk00576
@ Remove redundant functions.
@ Resolution for 12098: [Init, Inc, drv, custom][Add Feature] Porting system to MT6226, MT6227 and MT6229
@ 
@    Rev 1.12   Jul 28 2005 17:55:58   mtk00576
@ Porting to MT6226, MT6227 and MT6229.
@ Resolution for 12098: [Init, Inc, drv, custom][Add Feature] Porting system to MT6226, MT6227 and MT6229
@ 
@    Rev 1.11   Jun 13 2005 09:27:22   BM
@ add copyright and disclaimer
@ 
@    Rev 1.10   May 29 2005 12:43:44   mtk00576
@ Porting to MT6228
@ Resolution for 11274: [System][Enhancement] Support MT6228
@ 
@    Rev 1.9   Feb 01 2005 17:06:58   mtk00702
@ 1. move the compile option- _SIMULATION
@ 2. replace "MOVE PC, R7" with "BX R7" such that InitRegions can be invoked by C code
@ Resolution for 9731: [INIT, SST][AddFeature] Add Chip UID feature
@ 
@    Rev 1.8   Nov 08 2004 18:13:24   mtk00702
@ disable initialization of ZI region for co-sim
@ Resolution for 8658: [INIT, SST, DRV]Use compile option for co-sim load
@ 
@    Rev 1.7   Oct 06 2004 10:16:26   mtk00576
@ Making MT6217 available.
@ Resolution for 8084: [System Service][Enhancement] Porting MAUI to MT6217
@ 
@    Rev 1.6   Jun 06 2004 18:29:02   mtk00576
@ At MT6219, configure 256KB internal SRAM for Multi-media.
@ 
@    Rev 1.5   Apr 30 2004 22:19:38   mtk00576
@ Activate internal SRAM in MT6219.
@ 
@    Rev 1.4   Nov 20 2003 16:20:22   mtk00576
@ Modify InitRegions to meet both MT6218 and MT6218B.
@ Resolution for 3225: [Init][Add Feature]Porting to support MT6218B.
@ 
@    Rev 1.3   Oct 29 2003 16:12:56   mtk00576
@ Porting to MT6218B.
@ Resolution for 3225: [Init][Add Feature]Porting to support MT6218B.
@ 
@    Rev 1.2   Jun 06 2003 13:20:14   mtk00389
@ Modify to split INTSRAM_CODE and INTSRAM_DATA
@ Resolution for 93: Integration with MT6218
@ 
@    Rev 1.1   Jun 03 2003 10:43:18   mtk00389
@ Modify for MT6218, add region init
@ Resolution for 93: Integration with MT6218
@ 
@    Rev 1.0   Nov 30 2002 19:49:56   admin
@ Initial revision.
@ *------------------------------------------------------------------------------
@ * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
@ *============================================================================
@ ****************************************************************************/

@**************************************************************
@*     File: regioninit.s                                     *
@*  Purpose: Application Startup Code                         *
@**************************************************************
@
@ This file contains the macro and supporting subroutines to
@ copy RO code and RW data from ROM to RAM and zero-initialize
@ the ZI data areas in RAM.


@ All of this should be set as an assembler argument using the -pd option.
@ For example to set support for Angel it would be -pd "MT6218 SETL {TRUE}"
@ see also make\comp.mak

        #include "asm_def.h"

  /* Added by Anthony Chin 10/28/2001. */
        CPU_ISA()
        ISA_UNIFIED_SETTING()
        .global INT_InitRegions
        .global INT_InitEMIInitCode
        .global INT_InitPreInitData
        .global INT_InitMMRegions
        .global SYS_InitRegions

        .type INT_InitRegions, STT_FUNC
        .type INT_InitEMIInitCode, STT_FUNC
        .type INT_InitPreInitData, STT_FUNC
        .type INT_InitMMRegions, STT_FUNC
        .type SYS_InitRegions, STT_FUNC

/* 
Labels with positive integers represent local labels,
'b' after number represent backward reference;
'f' after number represent forward reference.
ex. label "1:" is referenced by "1b" or "1f".
*/


/* This macro:
@ a) copies RO code and/or RW data from ROM at Load$$area$$Base
@ to RAM at Image$$area$$Base, of length Image$$area$$Length bytes.
@ b) fills with zero the ZI data in RAM at Image$$area$$ZI$$Base, 
@ of length Image$$area$$ZI$$Length bytes.*/


        .macro   macro_RegionInit areaname

#if defined(_SIMULATION) /* _SIMULATION == 0 */
        @ For co-sim load,
        @ memory is initialized by hardware...

#else   /* _SIMULATION */

@ The following symbols are generated by the linker.  They are .externed 
@ WEAKly because they may not all have defined values. Those which are
@ undefined will take the value zero.

   .equ  copyloadsym, Load$$\areaname\($$Base)
   .weak Load$$\areaname\($$Base)
   .equ  copybasesym, Image$$\areaname\($$Base)
   .weak Image$$\areaname\($$Base)
   .equ  copylensym, Image$$\areaname\($$Length)
   .weak Image$$\areaname\($$Length)
   .equ  zibasesym, Image$$\areaname\($$ZI$$Base)
   .weak Image$$\areaname\($$ZI$$Base)
   .equ  zilensym, Image$$\areaname\($$ZI$$Length)
   .weak Image$$\areaname\($$ZI$$Length)

        LDR     r0, =copyloadsym       @ copyloadsym: load address of region
        LDR     r1, =copybasesym       @ copybasesym: execution address of region
        MOV     r2, r1                 @ copy execution address into r2
        LDR     r4, =copylensym        @ copylensym
        ADD     r2, r2, r4             @ add region length to execution address to...
                                       @ ...calculate address of word beyond end...
                                       @ ... of execution region
        BL      copy

        LDR     r2, =zilensym          @ zilensym: get length of ZI region
        LDR     r0, =zibasesym         @ zibasesym: load base address of ZI region
        MOV     r1, r0                 @ copy base address of ZI region into r1
        ADD     r1, r1, r2             @ add region length to base address to...
                                       @ ...calculate address of word beyond end...
                                       @ ... of ZI region
        BL      zi_init_32
#endif  /* _SIMULATION */

        .endm

@ This macro:
@ a) fills with zero the ZI data in RAM at Image$$area$$ZI$$Base, 
@ of length Image$$area$$ZI$$Length bytes.

        .macro        macro_ZeroInit areaname
        
#if defined(_SIMULATION) /* _SIMULATION == 0 */
        @ For co-sim load,
        @ memory is initialized by hardware...

#else   /* _SIMULATION */

@ The following symbols are generated by the linker.  They are .externed 
@ WEAKly because they may not all have defined values. Those which are
@ undefined will take the value zero.

   .equ  copyloadsym, Load$$\areaname\($$Base)
   .weak Load$$\areaname\($$Base)
   .equ  copybasesym, Image$$\areaname\($$Base)
   .weak Image$$\areaname\($$Base)
   .equ  copylensym, Image$$\areaname\($$Length)
   .weak Image$$\areaname\($$Length)
   .equ  zibasesym, Image$$\areaname\($$ZI$$Base)
   .weak Image$$\areaname\($$ZI$$Base)
   .equ  zilensym, Image$$\areaname\($$ZI$$Length)
   .weak Image$$\areaname\($$ZI$$Length)

        LDR     r2, =zilensym          @ zilensym: get length of ZI region
        LDR     r0, =zibasesym         @ zibasesym: load base address of ZI region
        MOV     r1, r0                 @ copy base address of ZI region into r1
        ADD     r1, r1, r2             @ add region length to base address to...
                                       @ ...calculate address of word beyond end...
                                       @ ... of ZI region
        BL      zi_init_32

#endif  /* _SIMULATION */

        .endm

@ This macro:
@ a) copies RO code and/or RW data from ROM at Load$$area$$Base
@ to RAM at Image$$area$$Base, of length Image$$area$$Length bytes.

        .macro        macro_CopyRW areaname

#if defined(_SIMULATION) /* _SIMULATION == 0 */
        @ For co-sim load,
        @ memory is initialized by hardware...

#else   /* _SIMULATION */

@ The following symbols are generated by the linker.  They are .externed 
@ WEAKly because they may not all have defined values. Those which are
@ undefined will take the value zero.

   .equ  copyloadsym, Load$$\areaname\($$Base)
   .weak Load$$\areaname\($$Base)
   .equ  copybasesym, Image$$\areaname\($$Base)
   .weak Image$$\areaname\($$Base)
   .equ  copylensym, Image$$\areaname\($$Length)
   .weak Image$$\areaname\($$Length)
   .equ  zibasesym, Image$$\areaname\($$ZI$$Base)
   .weak Image$$\areaname\($$ZI$$Base)
   .equ  zilensym, Image$$\areaname\($$ZI$$Length)
   .weak Image$$\areaname\($$ZI$$Length)

        LDR     r0, =copyloadsym        @ copyloadsym: load address of region
        LDR     r1, =copybasesym        @ copybasesym: execution address of region
        MOV     r2, r1                  @ copy execution address into r2
        LDR     r4, =copylensym
        ADD     r2, r2, r4              @ add region length to execution address to...
                                        @ ...calculate address of word beyond end...
                                        @ ... of execution region
        BL      copy

#endif  /* _SIMULATION */

        .endm

        
        .macro        macro_BackwardCopyRW areaname

#if defined(_SIMULATION) /* _SIMULATION == 0 */
        @ For co-sim load,
        @ memory is initialized by hardware...

#else   /* _SIMULATION */

@ The following symbols are generated by the linker.  They are .externed 
@ WEAKly because they may not all have defined values. Those which are
@ undefined will take the value zero.

   .equ  copyloadsym, Load$$\areaname\($$Base)
   .weak Load$$\areaname\($$Base)
   .equ  copybasesym, Image$$\areaname\($$Base)
   .weak Image$$\areaname\($$Base)
   .equ  copylensym, Image$$\areaname\($$Length)
   .weak Image$$\areaname\($$Length)
   .equ  zibasesym, Image$$\areaname\($$ZI$$Base)
   .weak Image$$\areaname\($$ZI$$Base)
   .equ  zilensym, Image$$\areaname\($$ZI$$Length)
   .weak Image$$\areaname\($$ZI$$Length)

        LDR     r0, =copyloadsym       @ copyloadsym: load address of region
        LDR     r1, =copybasesym       @ copybasesym: execution address of region
        MOV     r2, r1                 @ copy execution address into r2
        LDR     r4, =copylensym        @ copylensym
        SUB     r4, r4, #4
        ADD     r0, r0, r4
        ADD     r1, r1, r4
        
        BL      backward_copy

#endif  /* _SIMULATION */
        
        .endm         

@
@ NoteXXX: INT_InitXXXRegions is called from boot.s to initialize the specified execution regions.
@          The register r12 will be used in the bootarm.s. We should be careful not to
@          overwrite r12.
@

@
@/*************************************************************************/
@/*                                                                       */
@/* FUNCTION                                                              */
@/*   INT_InitEMIInitCode                                                 */
@/*                                                                       */
@/* DESCRIPTION                                                           */
@/*   Initialize EMI INIT code                                            */
@/*                                                                       */
@/* INPUTS                                                                */
@/*   None                                                                */
@/*                                                                       */
@/* OUTPUTS                                                               */
@/*   None                                                                */
@/*************************************************************************/
@ VOID INT_InitEMIInitCode(VOID)
@ {
@
    FUNC_ATTR(INT_InitEMIInitCode)
.align 2
INT_InitEMIInitCode:

   MOV   r7,lr
   
   macro_RegionInit EMIINIT_CODE
   macro_RegionInit SINGLE_BANK_CODE
   
   BX    r7 
.size INT_InitEMIInitCode, .-INT_InitEMIInitCode
@ }
@
/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*   INT_InitPreInitData                                                 */
/*                                                                       */
/* DESCRIPTION                                                           */
/*   Initialize CACHED_PREINIT_ZI region                                        */
/*                                                                       */
/* INPUTS                                                                */
/*   None                                                                */
/*                                                                       */
/* OUTPUTS                                                               */
/*   None                                                                */
/*************************************************************************/
@ VOID INT_InitPreInitData(VOID)
@ {
@
    FUNC_ATTR(INT_InitPreInitData)
INT_InitPreInitData:

   MOV   r7,lr
   
   macro_ZeroInit CACHED_EXTSRAM_PREINIT_ZI
   
   BX    r7 
.size INT_InitPreInitData, .-INT_InitPreInitData
@ }
@

@
@/*************************************************************************/
@/*                                                                       */
@/* FUNCTION                                                              */
@/*   INT_InitMMRegions                                                   */
@/*                                                                       */
@/* DESCRIPTION                                                           */
@/*   Initialize the multimedia region                                    */
@/*                                                                       */
@/* INPUTS                                                                */
@/*   None                                                                */
@/*                                                                       */
@/* OUTPUTS                                                               */
@/*   None                                                                */
@/*************************************************************************/
@ VOID INT_InitMMRegions(VOID)
@ {
@
INT_InitMMRegions:

   BX    lr                                 @ Return to caller
.size INT_InitMMRegions, .-INT_InitMMRegions
@ }
@


@
@/*************************************************************************/
@/*                                                                       */
@/* FUNCTION                                                              */
@/*   INT_InitEXTSRAM_ZIwihoutInitDSP                                     */
@/*                                                                       */
@/* DESCRIPTION                                                           */
@/*   Initialize CACHED_EXTSRAM without PHY_EXTSRAM_ZI_HEAD_AND_NOINIT    */
@/*                                                                       */
@/* INPUTS                                                                */
@/*   None                                                                */
@/*                                                                       */
@/* OUTPUTS                                                               */
@/*   None                                                                */
@/*************************************************************************/
@ VOID INT_InitEXTSRAM_ZIwihoutInitDSP(VOID)
@ {
@
    FUNC_ATTR(INT_InitEXTSRAM_ZIwihoutInitDSP)
INT_InitEXTSRAM_ZIwihoutInitDSP:

#if defined(__DSP_IMG_ON_EMI__)

        STMDB   sp!, {lr}                               @ save lr
        
        LDR     r0, =Load$$EXTSRAM$$Base       	      	@ copyloadsym: load address of region
        LDR     r1, =Image$$EXTSRAM$$Base      	      	@ copybasesym: execution address of region
        MOV     r2, r1                                	@ copy execution address into r2
        LDR     r4, =Image$$EXTSRAM$$Length    	      	@ copylensym
        ADD     r2, r2, r4                            	@ add region length to execution address to...
                                                      	@ ...calculate address of word beyond end...
                                                      	@ ... of execution region
        BL      copy

        LDR     r2, =Image$$EXTSRAM_ZI$$ZI$$Length       @ zilensym: get length of ZI region
        LDR     r1, =PHY_EXTSRAM_ZI_HEAD_NO_INIT$$Length @ we dont init dsp array
        SUB     r2, r2, r1        
        LDR     r0, =Image$$EXTSRAM_ZI$$ZI$$Base         @ zibasesym: load base address of ZI region
        ADD     r0, r0, r1
        MOV     r1, r0                                   
        ADD     r1, r1, r2                               
                                                         
                                                         
        BL      zi_init_32
        
        LDMIA   sp!, {lr}                               @ restore lr
#endif

        BX    lr                                        @ Return to caller

.size INT_InitEXTSRAM_ZIwihoutInitDSP, .-INT_InitEXTSRAM_ZIwihoutInitDSP
@ }
@


@
@/*************************************************************************/
@/*                                                                       */
@/* FUNCTION                                                              */
@/*   INT_InitRegions                                                     */
@/*                                                                       */
@/* DESCRIPTION                                                           */
@/*   Initialize the RW/ZI regions                                        */
@/*   Initialize the ZI regions for TCM only load                         */
@/*                                                                       */
@/* INPUTS                                                                */
@/*   None                                                                */
@/*                                                                       */
@/* OUTPUTS                                                               */
@/*   None                                                                */
@/*************************************************************************/
@ VOID INT_InitRegions(VOID)
@ {
@
    FUNC_ATTR(INT_InitRegions)
INT_InitRegions:

   MOV   r7,lr

#if defined(__TCM_ONLY_LOAD__)

     macro_ZeroInit INTSRAM_DATA
     macro_ZeroInit INTSRAM_DATA_B1
     macro_ZeroInit CACHED_EXTSRAM
     macro_ZeroInit EXTSRAM
     macro_ZeroInit DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI     
     macro_ZeroInit DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI

#else /*!defined(__TCM_ONLY_LOAD__)*/

      macro_RegionInit INTSRAM_CODE
      macro_RegionInit INTSRAM_DATA
      macro_RegionInit INTSRAM_DATA_B1

      macro_RegionInit CACHED_EXTSRAM
      macro_RegionInit CACHED_EXTSRAM_NVRAM_LTABLE
      macro_RegionInit DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_RW
      macro_RegionInit DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_RW
      macro_ZeroInit   DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI
      macro_ZeroInit   DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI

#if !defined(__DSP_IMG_ON_EMI__)
      macro_RegionInit EXTSRAM
#else
      STMDB   sp!, {r7}                    @ save lr
      BL INT_InitEXTSRAM_ZIwihoutInitDSP
      LDMIA   sp!, {r7}                    @ restore lr
#endif

      macro_RegionInit EXTSRAM_DSP_TX
      macro_RegionInit EXTSRAM_DSP_RX

#endif /* end of defined(__TCM_ONLY_LOAD__)*/

   BX    r7                                 @ Return to caller
.size INT_InitRegions, .-INT_InitRegions
@ }
@

@
@/*************************************************************************/
@/*                                                                       */
@/* FUNCTION                                                              */
@/*   SYS_InitRegions                                                     */
@/*                                                                       */
@/* DESCRIPTION                                                           */
@/*   Initialize the 2nd MAUI RW/ZI regions                               */
@/*                                                                       */
@/* INPUTS                                                                */
@/*   None                                                                */
@/*                                                                       */
@/* OUTPUTS                                                               */
@/*   None                                                                */
@/*************************************************************************/
@ VOID SYS_InitRegions(VOID)
@ {
@
    FUNC_ATTR(SYS_InitRegions)
SYS_InitRegions:

   @/* save working regsters since this function may be called by a C-code caller */
   BX    lr                                 @ Return to caller
.size SYS_InitRegions, .-SYS_InitRegions
@ }
@


@ --- copy and zi_init subroutines

@ copy is a subroutine which copies a region, from an address given by 
@ r0 to an address given by r1. The address of the word beyond the end
@ of this region is held in r2. r3 is used to hold the word being copied. 
.global copy
@copy:
@   .word _copy

    FUNC_ATTR(copy)
copy:
        CMP     r0, r1
        BEQ     copy_exit
copy_loop:
        CMP     r1, r2                 @ loop whilst r1 < r2
        LDRLO   r3, [r0], #4
        STRLO   r3, [r1], #4
        BLO     copy_loop
copy_exit:
        MOV     pc, lr                 @ return from subroutine copy
.size copy, .-copy
        
@ backward_copy is a subroutine which copies a region, from an address given by 
@ r0 to an address given by r1. The address of the word beyond the end
@ of this region is held in r2. r3 is used to hold the word being copied. 
.global backward_copy
@backward_copy:
@   .word _backward_copy

    FUNC_ATTR(backward_copy)
backward_copy:
        CMP     r0, r1
        BEQ     backward_copy_exit
backward_copy_loop:
        CMP     r1, r2                 @ loop whilst r1 < r2
        LDRGE   r3, [r0], #-4
        STRGE   r3, [r1], #-4
        BGE     backward_copy_loop
backward_copy_exit:
        MOV     pc, lr                 @ return from subroutine copy
.size backward_copy, .-backward_copy

@ zi_init is a subroutine which zero-initialises a region,
@ starting at the address in r0. The address of the word
@ beyond the end of this region is held in r1.
.global zi_init
@zi_init:
@   .word _zi_init
    FUNC_ATTR(zi_init)
zi_init:
        MOV     r2, #0
        CMP     r0, r1                 @ loop whilst r0 < r1
        STRLO   r2, [r0], #4
        BLO     zi_init 
        MOV     pc, lr                 @ return from subroutine zi_init
.size zi_init, .-zi_init

@ zi_init_32 is a subroutine which zero-initialises a region,
@ starting at the address in r0. The length is held in r2.
@ the address of the 4-byte beyound the end of this region is 
@ held in r1. set 32 bytes zero per loop.
.global zi_init_32
@zi_init_32:
@   .word _zi_init_32

    FUNC_ATTR(zi_init_32)
zi_init_32:
        STMDB   sp!, {r8-r10}          @ save extra working register
        MOV     r3, #0
        MOV     r8, #0
        MOV     r9, #0
        MOV     r10, #0
        SUBS    r2, r2, #0x20          @ loop while r2 > 32

.global zi_init_32_loop
@zi_init_32_loop:
   @.word _zi_init_32_loop

    FUNC_ATTR(zi_init_32_loop)
zi_init_32_loop:
        STMCSIA r0!, {r3,r8-r10}
        STMCSIA r0!, {r3,r8-r10}
        SUBCSS  r2, r2, #0x20          @ loop while r2 > 32
        BCS     zi_init_32_loop
        LDMIA   sp!, {r8-r10}          @ restore extra working register
        B       zi_init
        MOV     pc, lr                 @ return from subroutine zi_init
.size zi_init_32_loop, .-zi_init_32_loop
   .end
