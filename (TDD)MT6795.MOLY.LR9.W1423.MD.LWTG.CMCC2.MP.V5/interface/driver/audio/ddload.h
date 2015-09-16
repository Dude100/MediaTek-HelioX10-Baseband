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
 *
 * Filename:
 * ---------
 * ddload.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Dynamic Download for DSP(MT6218 and later)
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Revision:   1.8  $
 * $Modtime:   Aug 15 2005 18:08:16  $
 * $Log:   //mtkvs01/vmdata/Maui_sw/archives/mcu/dsp_ram/ddload.h-arc  $
 *
 * removed!
 * removed!
 * add DDL MT6752 compile option.
 *
 * removed!
 * removed!
 * MT6595 check in.
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .ADD MT6571
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * MT6582 bringup (MOLY)
 *
 * removed!
 * removed!
 * MT6572 bring up
 * 
 * 10 22 2012 kh.hung
 * removed!
 * .
 * 
 * removed!
 * removed!
 * Merge ram_source_MT6583_MD1.bin and Patch_6583_MD1.bin.
 * 
 * removed!
 * removed!
 * Add MT6583 compile option.
 *
 * 05 11 2012 kh.hung
 * removed!
 * .
 *
 * removed!
 * removed!
 * . modify for Dynamic Download
 *
 * 
 *******************************************************************************/
#ifndef  _DDLOAD_H_
#define  _DDLOAD_H_

typedef struct{
   int        Dsp_Start_Addr;
   const char *Array_Addr;
   int        Array_Len;
}DLL_Func;

typedef struct{
   const DLL_Func *dspFunc;
   const char *Compressed_Array_Addr;
   int        Compressed_Array_Len;
}DLL_FuncCompress;

typedef struct{
   DLL_Func dll;
   unsigned char isAlloc;
}DLL_FuncGen;

/* ------------------------------------------------------------------------- */

#define DPCHIP_DATACARD_DSP         (defined(MT6280) || defined(MT6589) || defined(MT6572) || defined(MT6582) || defined(MT6290) || defined(MT6592) || defined(MT6571) || defined(MT6595) || defined(MT6752))

#define DPCHIP_DDL_HANDSHAKE_IO_NOT_IO7  (DPCHIP_DATACARD_DSP)
#define DPCHIP_DDL_TCH                   (DPCHIP_DATACARD_DSP)
#define DPCHIP_DDL_TCH2                  (DPCHIP_DATACARD_DSP)
#define DPCHIP_SHERIF_INTERNAL_DM_BASE   (DPCHIP_DATACARD_DSP)

#define DPCHIP_NO_DDL_AUDIO (defined(MT6595) || defined(MT6752))
#define SPH_ENH_DDLOAD_TWO_PARTS      (defined(MT6290) || defined(MT6592) || defined(MT6595) || defined(MT6752))
#define SPH_ENH_DDLOAD_THREE_PARTS    (defined(MT6571))

/* ------------------------------------------------------------------------- */

#define CM_PAGE   4

#if (DPCHIP_DATACARD_DSP)
  #define CM_PAGE_TCH_DDL               8
  #define CM_PAGE_TCH2_DDL              8
#endif

/* ------------------------------------------------------------------------- */
#define DDID_NONE                       0
#if (SPH_ENH_DDLOAD_TWO_PARTS) || (SPH_ENH_DDLOAD_THREE_PARTS)
    #define DDID_TCH_COMMON             7
#else
    #define DDID_NOISE_REDUCTION        7
#endif
#define DDID_AudioHeader               24
#define DDID_Internal_TCH2            254
#define DDID_Internal_Header_Kernal   255
#define DDID_SPH_TCH_1               6001     // For SPH ENH seperate into two parts
#define DDID_SPH_TCH_2               6002     // For SPH ENH seperate into two parts
#define DDID_SPH_TCH_3               6003     // For SPH ENH seperate into three parts

/* ------------------------------------------------------------------------- */

void _idma_load_pm_d2(unsigned short int page, unsigned short int addr, unsigned int len, const unsigned char *image);
void FreeFuncPtr(DLL_FuncGen *dllGenPtr);
int GetPmDllFuncPtr(unsigned int fw_id, DLL_FuncGen *dllResult);

void DSP_DynamicDownload_Init( void );
int DSP_DynamicDownload( int dsp_fw_id );

/* ------------------------------------------------------------------------- */

#endif  /*_DDLOAD_H_ */


