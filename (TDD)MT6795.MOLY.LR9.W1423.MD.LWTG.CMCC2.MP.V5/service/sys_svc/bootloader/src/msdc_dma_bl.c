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
 *    msdc_dma_bl.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the DMA driver. Originated from dma.c
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
 ****************************************************************************/
#if defined(__CARD_DOWNLOAD__) || defined(__EMMC_BOOTING__)

#include "drv_comm.h"
#include "drv_hisr.h"
#include "reg_base.h"
#include "config_hw.h"
#include "intrCtrl.h"
#include "dma_hw.h"
#include "dma_sw.h"
#include "drvpdn.h"
#include "che_hw.h"
#include "lcd_if.h"
#include "uart_sw.h"
#include "cache_sw.h"
#include "init.h"

extern kal_uint32 kal_get_mytask_priority(void);
void DMA_ERROR_LISR(void);

#ifdef MT6218
VOID_FUNC DMA_LISR_FUNC[DMA_MAX_CHANNEL] =
{
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR
};
#elif defined(MT6218B) || defined(MT6217)
VOID_FUNC DMA_LISR_FUNC[DMA_MAX_CHANNEL] =
{
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR
};
#elif defined(MT6223) || defined(MT6223P)
VOID_FUNC DMA_LISR_FUNC[DMA_MAX_CHANNEL+2] =
{
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR
};
#elif defined(TK6516) || defined(MT6516)
VOID_FUNC DMA_LISR_FUNC[DMA_MAX_CHANNEL+2] =
{
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR
};
#elif defined(MT6253T) || defined(MT6253) || defined(MT6253D)
VOID_FUNC DMA_LISR_FUNC[DMA_MAX_CHANNEL] =
{
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR
};
#elif defined(MT6276)
VOID_FUNC DMA_LISR_FUNC[DMA_MAX_CHANNEL] =
{
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR
};
#elif defined(MT6256)
VOID_FUNC DMA_LISR_FUNC[DMA_MAX_CHANNEL] =
{
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR
};
#elif defined(MT6251)
VOID_FUNC DMA_LISR_FUNC[DMA_MAX_CHANNEL] =
{
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR
};
#elif defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H)
VOID_FUNC DMA_LISR_FUNC[DMA_MAX_CHANNEL] =
{
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR
};
#else
VOID_FUNC DMA_LISR_FUNC[DMA_MAX_CHANNEL] =
{
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR
};
#endif

static DMA_GBL_CLASS dma_gbl_class_g;
static const kal_uint8 dma_gbl_class_to_grade[DMA_MAX_GBL_CLASS + 1]
   = { 0 /* CLASS 0 */, 10 /* CLASS 1 */, 50 /* CLASS 2 */, 100 /* CLASS 3 */, 200 /* CLASS 4 */ };
static const DMA_GBL_PRIORITY_BANK dma_gbl_priority_bank[DMA_GBL_TOTAL_PRIORITY_BANK]
   = { {0, 9, 1}, {10, 39, 2}, {40, 89, 3}, {90, 119, 4}, {120, 169, 5}, {170, 199, 6}, {200, 249, 7}, {250, 255, 8} };
kal_uint32 DMA_Channel_Status = 0xffff;
#if defined(MT6223) || defined(MT6223P) || defined(TK6516) || defined(MT6516)
DMA_Master DMA_Owner[DMA_MAX_CHANNEL+2];
#else
DMA_Master DMA_Owner[DMA_MAX_CHANNEL];
#endif
#if defined(__DMA_V3__)
#pragma arm section rwdata = "INTSRAM_RW" , rodata = "INTSRAM_RODATA" , zidata = "INTSRAM_ZI"
static DMA_SAVE_PARAM DMA_Save_Param[DMA_MAX_CHANNEL];
#pragma arm section rwdata , rodata , zidata
#endif

void DMA_Stop(kal_uint8 channel)
{
#if defined(__DMA_V3__)
   kal_uint32 temp;
   /* E1 DMA bug: if stopping or flushing a disabled DMA channel, an unexpected interrupt will be triggered. 
       Disable interrupt control bit before stop DMA*/
   if( !DMA_CheckRunStat(channel) )
   {
       DMA_ACKI(channel);
       return;   
   }
   temp = DRV_Reg32(DMA_INT_EN(channel));
   DRV_WriteReg32(DMA_INT_EN(channel), 0);
      
   //DMA_Flush(channel);
   DMA_Stop_Now(channel);
   DMA_WaitUntilRdy(channel);   // => pending 1 transaction time
   DMA_ACKI(channel);        
   
   /* E1 DMA bug: restore intr. control bit */
   DRV_WriteReg32(DMA_INT_EN(channel), temp);   
   
#else // __DMA_V3_
	DMA_Stop_Now(channel);
	DMA_ACKI(channel);
#endif	// __DMA_V3_
}

void DMA_FreeChannel(kal_uint8 handle)
{
   kal_uint32 savedMask;
   savedMask = SaveAndSetIRQMask();
   DMA_Channel_Status |= (0x01<<handle);
   DMA_Stop(handle);
#if !defined(__DMA_V3__)
   /* Reset the used DMA channel register to default value to prevent from DMA transfer fail in MAUI */
   DRV_WriteReg32(DMA_SRC(handle), 0);
   DRV_WriteReg32(DMA_DST(handle), 0);
   DRV_WriteReg32(DMA_WPPT(handle), 0);
   DRV_WriteReg32(DMA_WPTO(handle), 0);
   DRV_WriteReg32(DMA_COUNT(handle), 0);
   DRV_WriteReg32(DMA_CON(handle), 0);
   DRV_WriteReg32(DMA_START(handle), 0);
   DRV_WriteReg32(DMA_LIMITER(handle), 0);
   DRV_WriteReg32(DMA_PGMADDR(handle), 0);
#endif	// !__DMA_V3_
   
   DMA_Owner[handle-1] = DMA_IDLE;
   RestoreIRQMask(savedMask);
}

kal_uint8 DMA_GetChannel(DMA_Master DMA_CODE)
{
   kal_uint8 index;
   kal_uint8 handle=0xff;
   kal_uint32 savedMask;
#if defined(__DMA_V3__)


   savedMask = SaveAndSetIRQMask();
   if ((DMA_Channel_Status & (0x01<<DMA_CODE)) != 0)
   {
         handle = DMA_CODE;
         DMA_Channel_Status &= ~(0x01<<DMA_CODE);
         DMA_Owner[handle-1] = DMA_CODE;
   }
   RestoreIRQMask(savedMask);
   
   ASSERT(handle!=0xff);

   return handle;


#else // __DMA_V3__
   savedMask = SaveAndSetIRQMask();
#if defined(MT6223) || defined(MT6223P) || defined(TK6516) || defined(MT6516)
   for (index = 4; index <= DMA_MAX_CHANNEL+2; index++)
#elif defined(MT6253T) || defined(MT6253) || defined(MT6253D)
   for (index = 5; index <= DMA_MAX_CHANNEL; index++)
#elif defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H)
   for (index = 2; index <= DMA_MAX_CHANNEL; index++)
#else /*MT6223*/
   for (index = 4; index <= DMA_MAX_CHANNEL; index++)
#endif
   {
      if ((DMA_Channel_Status & (0x01<<index)) != 0)
      {
         handle = index;
         DMA_Channel_Status &= ~(0x01<<index);
         break;
      }
   }
   RestoreIRQMask(savedMask);
   ASSERT(handle!=0xff);

//#ifndef __PRODUCTION_RELEASE__
#if defined(MT6223) || defined(MT6223P) || defined(TK6516) || defined(MT6516)
   for (index = 4; index <= DMA_MAX_CHANNEL+2; index++)
#elif defined(MT6253T) || defined(MT6253) || defined(MT6253D)
   for (index = 5; index <= DMA_MAX_CHANNEL; index++)
#elif defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H)
   for (index = 2; index <= DMA_MAX_CHANNEL; index++)   	
#else
   for (index = 4; index <= DMA_MAX_CHANNEL; index++)
#endif
   {
      if (DMA_Owner[index-1]==DMA_CODE)
         ASSERT(0);
   }
//#endif   /*__PRODUCTION_RELEASE__*/

   DMA_Owner[handle-1] = DMA_CODE;
   return handle;

   
#endif //// __DMA_V3_   
}

void DMA_Config_Internal(kal_uint8 dma_no, DMA_INPUT *dma_menu, kal_bool fullsize, kal_bool b2w, kal_uint8 limit, kal_bool start)
{
   ECO_VERSION eco;
   kal_uint32 dma_con = 0;
   kal_uint32 temp;
   kal_uint32 _savedMask;
   kal_uint32 priority;
   DMA_GBL_CLASS dma_gbl_class;
   kal_uint8 dma_gbl, bank = 0;


   if (DMA_CheckRunStat(dma_no) || DMA_CheckITStat(dma_no))
      ASSERT(0);

   ASSERT(DMA_Owner[dma_no - 1] != DMA_IDLE);

   if (fullsize == KAL_TRUE)
      ASSERT(b2w == KAL_FALSE);

   ASSERT(dma_menu->count <= 0xffff);

   /* DMA bug: DMA will never stop when start DMA with zero length */
   if( start == KAL_TRUE &&  dma_no < DMA_VFIFO_CH_S)
       ASSERT(dma_menu->count != 0);


   DMA_Stop(dma_no);

   /* get chip version */
   eco = INT_ecoVersion();

#if defined(MT6225)
   /* it is not allowed to use "burst" tx in MT6225 E1, E2, E3*/
   if (eco <= ECO_E3) {
      if (((DMA_TMODE *)(dma_menu->menu))->burst_mode == KAL_TRUE) {
         if (dma_menu->type == DMA_HWTX || dma_menu->type == DMA_SWCOPY || dma_menu->type == DMA_HWTX_RINGBUFF) {
            EXT_ASSERT(0, dma_no, dma_menu->type, b2w);
         }
      }
   }
#endif  /* MT6225 */

#if !defined(__MTK_L1CACHEABLE__)
   /* check if the memory address is in cached region for ARM9 platforms */
   if (dma_menu->type == DMA_SWCOPY) {
      if (INT_QueryIsCachedRAM(((DMA_SWCOPYMENU *)dma_menu->menu)->srcaddr, 1)) {
         EXT_ASSERT(0, ((DMA_SWCOPYMENU *)dma_menu->menu)->srcaddr, 0, 0);
      }
      if (INT_QueryIsCachedRAM(((DMA_SWCOPYMENU *)dma_menu->menu)->dstaddr, 1)) {
         EXT_ASSERT(0, ((DMA_SWCOPYMENU *)dma_menu->menu)->dstaddr, 0, 0);
      }
   } else if (fullsize == KAL_TRUE) {
      if (INT_QueryIsCachedRAM(((DMA_SWCOPYMENU *)dma_menu->menu)->srcaddr, 1)) {
         EXT_ASSERT(0, ((DMA_SWCOPYMENU *)dma_menu->menu)->srcaddr, 0, 0);
      }
      if (INT_QueryIsCachedRAM(((DMA_SWCOPYMENU *)dma_menu->menu)->dstaddr, 1)) {
         EXT_ASSERT(0, ((DMA_SWCOPYMENU *)dma_menu->menu)->dstaddr, 0, 0);
      }
   } else {
      if (INT_QueryIsCachedRAM(((DMA_HWMENU *)dma_menu->menu)->addr, 1)) {
         EXT_ASSERT(0, ((DMA_HWMENU *)dma_menu->menu)->addr, 0, 0);
      }
   }
   if (dma_menu->type == DMA_HWRX_RINGBUFF || dma_menu->type == DMA_HWTX_RINGBUFF) {
      if (INT_QueryIsCachedRAM(((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->WPTO, 1)) {
         EXT_ASSERT(0, (kal_uint32)(((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT), 0, 0);
      }
      if (INT_QueryIsCachedRAM(((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->WPTO, 1)) {
         EXT_ASSERT(0, (kal_uint32)(((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT), 0, 0);
      }
   }
#endif /* !__MTK_L1CACHEABLE__ */

   switch(dma_menu->type) {
   case  DMA_HWTX:

#if defined( __DMA_V3__)

      if (fullsize == KAL_TRUE) 
      {         
         ASSERT( dma_no <= DMA_FULL_CH_NUM );
         DRV_WriteReg32(DMA_SRC(dma_no), ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->source);
         DRV_WriteReg32(DMA_DST(dma_no), ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->destination);

         if( ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->fixed_raddr)
         {
            dma_con |= ((((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->rsize)&DMA_CON_SIZE_MASK)<<DMA_CON_RSIZE_OFFSET;
            dma_con |= DMA_CON_SFIX;
         }

         if( ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->fixed_waddr)
         {
            dma_con |= ((((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->wsize)&DMA_CON_SIZE_MASK)<<DMA_CON_WSIZE_OFFSET;
            dma_con |= DMA_CON_DFIX;
         }
      }
      else
      {
         ASSERT( dma_no > DMA_FULL_CH_NUM );
		 dma_con |= DMA_CON_TXCONTRL;
         DRV_WriteReg32(DMA_PGMADDR(dma_no), ((DMA_HWMENU *)dma_menu->menu)->addr);
      }
	  
      if (dma_menu->fixed_pattern)
      {
         dma_con |= DMA_CON_FIXED_PATTERN;
      }

#else //__DMA_V3__
      if (fullsize == KAL_TRUE)
         temp = (kal_uint32)(((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->master);
      else
         temp = (kal_uint32)(((DMA_HWMENU *)dma_menu->menu)->master);

      dma_con |= (kal_uint32)(temp << 20);
      dma_con |= DMA_CON_TXCONTRL;
      dma_con |= DMA_CON_DRQ;

      if (fullsize == KAL_TRUE) {
         if (((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->TMOD.burst_mode) {
#ifdef MT6218
            dma_con |= DMA_CON_TMOD;
            dma_con |= (kal_uint32)(((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->TMOD.cycle) << 9;
#endif	/* MT6218 */
         }
      } else {
         if (((DMA_HWMENU *)dma_menu->menu)->TMOD.burst_mode) {
#ifdef MT6218
            dma_con |= DMA_CON_TMOD;
            dma_con |= (kal_uint32)(((DMA_HWMENU *)dma_menu->menu)->TMOD.cycle) << 9;
#endif	/* MT6218 */
         }
      }

      if (fullsize == KAL_TRUE) {
         DRV_WriteReg32(DMA_SRC(dma_no), ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->source);
         DRV_WriteReg32(DMA_DST(dma_no), ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->destination);
      }
      else {
         DRV_WriteReg32(DMA_PGMADDR(dma_no), ((DMA_HWMENU *)dma_menu->menu)->addr);
#if !defined(MT6218)
         if(b2w == KAL_TRUE)
            dma_con |= DMA_CON_B2W;
#endif
      }

#endif //__DMA_V3__
      break;

   case  DMA_HWRX:
#if defined( __DMA_V3__)

      ASSERT( dma_menu->fixed_pattern == 0 );

      if (fullsize == KAL_TRUE)
      {
         ASSERT( dma_no <= DMA_FULL_CH_NUM );
         DRV_WriteReg32(DMA_SRC(dma_no), ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->source);
         DRV_WriteReg32(DMA_DST(dma_no), ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->destination);

         if( ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->fixed_raddr)
         {
            /* Fixed write access, src address must be 8byte alignment */
            ASSERT( ( ((DMA_SWCOPYMENU *)dma_menu->menu)->srcaddr & 0x7 ) == 0 );         
            dma_con |= ((((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->rsize)&DMA_CON_SIZE_MASK)<<DMA_CON_RSIZE_OFFSET;
            dma_con |= DMA_CON_SFIX;
         }

         if( ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->fixed_waddr)
         {
            /* Fixed write access, dst address must be 8byte alignment */
            ASSERT( ( ((DMA_SWCOPYMENU *)dma_menu->menu)->dstaddr & 0x7 ) == 0 );         
            dma_con |= ((((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->wsize)&DMA_CON_SIZE_MASK)<<DMA_CON_WSIZE_OFFSET;
            dma_con |= DMA_CON_DFIX;
         }
      }
      else
      {
         ASSERT( dma_no > DMA_FULL_CH_NUM );
		 dma_con |= DMA_CON_RXCONTRL;
         DRV_WriteReg32(DMA_PGMADDR(dma_no), ((DMA_HWMENU *)dma_menu->menu)->addr);
      }

#else //__DMA_V3__

      if (fullsize == KAL_TRUE)
         dma_con |= (kal_uint32)(((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->master) << 20;
      else
         dma_con |= (kal_uint32)(((DMA_HWMENU *)dma_menu->menu)->master) << 20;

      dma_con |= DMA_CON_RXCONTRL;
      dma_con |= DMA_CON_DRQ;

      if (fullsize == KAL_TRUE) {
         if (((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->TMOD.burst_mode) {
#ifdef MT6218
            dma_con |= DMA_CON_TMOD;
            dma_con |= (kal_uint32)(((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->TMOD.cycle) << 9;
#endif	/* MT6218 */
         }
      } else {
         if (((DMA_HWMENU *)dma_menu->menu)->TMOD.burst_mode) {
#ifdef MT6218
            dma_con |= DMA_CON_TMOD;
            dma_con |= (kal_uint32)(((DMA_HWMENU *)dma_menu->menu)->TMOD.cycle) << 9;
#endif	/* MT6218 */
         }
      }

      if (fullsize == KAL_TRUE) {
         DRV_WriteReg32(DMA_SRC(dma_no), ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->source);
         DRV_WriteReg32(DMA_DST(dma_no), ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->destination);
      } else {
         DRV_WriteReg32(DMA_PGMADDR(dma_no), ((DMA_HWMENU *)dma_menu->menu)->addr);
#if !defined(MT6218)
         if(b2w == KAL_TRUE)
            dma_con |= DMA_CON_B2W;
#endif
      }
#endif //__DMA_V3__

      break;

   case DMA_SWCOPY:
#if defined( __DMA_V3__)

      DRV_WriteReg32(DMA_SRC(dma_no), ((DMA_SWCOPYMENU *)dma_menu->menu)->srcaddr);
      DRV_WriteReg32(DMA_DST(dma_no), ((DMA_SWCOPYMENU *)dma_menu->menu)->dstaddr);
      if( ((DMA_SWCOPYMENU *)dma_menu->menu)->fixed_raddr)
      {
          /* Fixed read access, src address must be 8byte alignment */
          ASSERT( ( ((DMA_SWCOPYMENU *)dma_menu->menu)->srcaddr & 0x7 ) == 0 );
          dma_con |= ((((DMA_SWCOPYMENU *)dma_menu->menu)->rsize)&DMA_CON_SIZE_MASK)<<DMA_CON_RSIZE_OFFSET;
          dma_con |= DMA_CON_SFIX;
      }

      if( ((DMA_SWCOPYMENU *)dma_menu->menu)->fixed_waddr)
      {
          /* Fixed write access, dst address must be 8byte alignment */
          ASSERT( ( ((DMA_SWCOPYMENU *)dma_menu->menu)->dstaddr & 0x7 ) == 0 );
          dma_con |= ((((DMA_SWCOPYMENU *)dma_menu->menu)->wsize)&DMA_CON_SIZE_MASK)<<DMA_CON_WSIZE_OFFSET;
          dma_con |= DMA_CON_DFIX;
      }

      if (dma_menu->fixed_pattern)
      {
         dma_con |= DMA_CON_FIXED_PATTERN;
      }
#else //__DMA_V3__

      DRV_WriteReg32(DMA_SRC(dma_no), ((DMA_SWCOPYMENU *)dma_menu->menu)->srcaddr);
      DRV_WriteReg32(DMA_DST(dma_no), ((DMA_SWCOPYMENU *)dma_menu->menu)->dstaddr);
      dma_con = DMA_CON_SWCOPY;
	  
#endif //__DMA_V3__

      break;

   case DMA_HWTX_RINGBUFF:
#if defined( __DMA_V3__)

     ASSERT( fullsize == KAL_TRUE && dma_no <= DMA_FULL_CH_NUM );

     /*E1 Bug: Len1 can not be zero */
     ASSERT( ( (DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT != 0 );

     dma_con |= DMA_CON_WPEN|DMA_CON_WPSD; //RAM -> Register

     DRV_WriteReg32(DMA_WPTO(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPTO);
     DRV_WriteReg32(DMA_SRC(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->source);
     DRV_WriteReg32(DMA_DST(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->destination);

     if( ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->fixed_raddr)
     {
          /* Fixed read access, src address must be 8byte alignment */
          ASSERT( ( ((DMA_SWCOPYMENU *)dma_menu->menu)->srcaddr & 0x7 ) == 0 );     
         dma_con |= ((((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->rsize)&DMA_CON_SIZE_MASK)<<DMA_CON_RSIZE_OFFSET;
         dma_con |= DMA_CON_SFIX;
     }
	 
     if( ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->fixed_waddr)
     {
          /* Fixed write access, dst address must be 8byte alignment */
          ASSERT( ( ((DMA_SWCOPYMENU *)dma_menu->menu)->dstaddr & 0x7 ) == 0 );     
         dma_con |= ((((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->wsize)&DMA_CON_SIZE_MASK)<<DMA_CON_WSIZE_OFFSET;
         dma_con |= DMA_CON_DFIX;
     }

     if (dma_menu->fixed_pattern)
     {
        dma_con |= DMA_CON_FIXED_PATTERN;
     }

#else //__DMA_V3__

      if (fullsize == KAL_TRUE)
         dma_con |= ((kal_uint32)((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->master) << 20;
      else
         dma_con |= ((kal_uint32)((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->master) << 20;

      dma_con |= DMA_CON_TXCONTRL;
      dma_con |= DMA_CON_DRQ;

      if (fullsize == KAL_TRUE) {
         if (((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->TMOD.burst_mode) {
#ifdef MT6218
            dma_con |= DMA_CON_TMOD;
            dma_con |= (kal_uint32)(((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->TMOD.cycle) << 9;
#endif	/* MT6218 */
         }
      } else {
         if (((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->TMOD.burst_mode) {
#ifdef MT6218
            dma_con |= DMA_CON_TMOD;
            dma_con |= (kal_uint32)(((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->TMOD.cycle) << 9;
#endif	/* MT6218 */
         }
      }

      dma_con |= DMA_CON_WPEN;   /*RAM->Register*/

      if (fullsize == KAL_TRUE) {
         DRV_WriteReg32(DMA_WPPT(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT);
         DRV_WriteReg32(DMA_WPTO(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPTO);
         DRV_WriteReg32(DMA_SRC(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->source);
         DRV_WriteReg32(DMA_DST(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->destination);
      } else {
         DRV_WriteReg32(DMA_WPPT(dma_no), ((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT);
         DRV_WriteReg32(DMA_WPTO(dma_no), ((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->WPTO);
         DRV_WriteReg32(DMA_PGMADDR(dma_no), ((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->addr);
#if !defined(MT6218)
         if(b2w == KAL_TRUE)
            dma_con |= DMA_CON_B2W;
#endif
      }

#endif //__DMA_V3__

      break;

   case DMA_HWRX_RINGBUFF:

#if defined(__DMA_V3__)

     ASSERT( fullsize == KAL_TRUE && dma_no <= DMA_FULL_CH_NUM );

     /*E1 Bug: Len1 can not be zero */
     ASSERT(( (DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT != 0 ) ;

     ASSERT( dma_menu->fixed_pattern == 0 );
      
     dma_con |= DMA_CON_WPEN;


     DRV_WriteReg32(DMA_WPTO(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPTO);
     DRV_WriteReg32(DMA_SRC(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->source);
     DRV_WriteReg32(DMA_DST(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->destination);

     if( ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->fixed_raddr)
     {
         /* Fixed write access, src address must be 8byte alignment */
        ASSERT( ( ((DMA_SWCOPYMENU *)dma_menu->menu)->srcaddr & 0x7 ) == 0 );     
        dma_con |= ((((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->rsize)&DMA_CON_SIZE_MASK)<<DMA_CON_RSIZE_OFFSET;
        dma_con |= DMA_CON_SFIX;
     }

     if( ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->fixed_waddr)
     {
         /* Fixed write access, dst address must be 8byte alignment */
         ASSERT( ( ((DMA_SWCOPYMENU *)dma_menu->menu)->dstaddr & 0x7 ) == 0 );     
        dma_con |= ((((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->wsize)&DMA_CON_SIZE_MASK)<<DMA_CON_WSIZE_OFFSET;
        dma_con |= DMA_CON_DFIX;
     }

#else //__DMA_V3__

      if (fullsize == KAL_TRUE)
         dma_con |= ((kal_uint32) ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->master) << 20;
      else
         dma_con |= ((kal_uint32) ((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->master) << 20;

      dma_con |= DMA_CON_RXCONTRL;
      dma_con |= DMA_CON_DRQ;

      if (fullsize == KAL_TRUE) {
         if (((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->TMOD.burst_mode) {
#ifdef MT6218
            dma_con |= DMA_CON_TMOD;
            dma_con |= (kal_uint32)(((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->TMOD.cycle) << 9;
#endif	/* MT6218 */
         }
      } else {
         if (((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->TMOD.burst_mode) {
#ifdef MT6218
            dma_con |= DMA_CON_TMOD;
            dma_con |= (kal_uint32)(((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->TMOD.cycle) << 9;
#endif	/* MT6218 */
         }
      }

      dma_con |= DMA_CON_WPSD;      /*Register->RAM*/
      dma_con |= DMA_CON_WPEN;

      if (fullsize == KAL_TRUE) {
         DRV_WriteReg32(DMA_WPPT(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT);
         DRV_WriteReg32(DMA_WPTO(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPTO);
         DRV_WriteReg32(DMA_SRC(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->source);
         DRV_WriteReg32(DMA_DST(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->destination);
      } else {
         DRV_WriteReg32(DMA_WPPT(dma_no), ((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT);
         DRV_WriteReg32(DMA_WPTO(dma_no), ((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->WPTO);
         DRV_WriteReg32(DMA_PGMADDR(dma_no), ((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->addr);
#if !defined(MT6218)
         if(b2w == KAL_TRUE)
            dma_con |= DMA_CON_B2W;
#endif
      }
	  
#endif //__DMA_V3__

      break;

   default:

      ASSERT(0);

      break;
   }

#if defined(__DMA_V3__)

  
   if (((DMA_TMODE *)(dma_menu->menu))->burst_mode==KAL_TRUE 
   	 && ( dma_con & ( DMA_CON_SFIX | DMA_CON_DFIX ) ) == 0 )  /* Fixed access, burst size must be single */
   {
       if(((DMA_TMODE *)(dma_menu->menu))->cycle==0)
       {
           dma_con |= (DMA_CON_BURST_SINGLE<<DMA_CON_BURST_OFFSET);
       }
       else
       {
           dma_con |= ((((DMA_TMODE *)(dma_menu->menu))->cycle-1)&0x07)<<DMA_CON_BURST_OFFSET;
       }
   }
   else
   {
       dma_con |= (DMA_CON_BURST_SINGLE<<DMA_CON_BURST_OFFSET);
   }

   if (dma_menu->callback != NULL)
   {
      DRV_WriteReg32(DMA_INT_EN(dma_no), 1);
      DMA_LISR_FUNC[dma_no-1] = dma_menu->callback;
   }
   else
   {
      DRV_WriteReg32(DMA_INT_EN(dma_no), 0);
   }

   // keep the original bw limit setting
   //dma_con |= (*DMA_CON(dma_no)&DMA_CON_SLOW_MASK);
   //DRV_WriteReg32(DMA_CON(dma_no),dma_con);

   if(dma_menu->type!=DMA_HWTX_RINGBUFF && dma_menu->type!=DMA_HWRX_RINGBUFF)
   {
       DMA_Save_Param[dma_no].len1 = ((kal_uint32)dma_menu->count)<<(dma_menu->size);
	   DMA_Save_Param[dma_no].len2 = 0;
	   DMA_Save_Param[dma_no].size = dma_menu->size;
	   
   }
   else
   {
       DMA_Save_Param[dma_no].len1 = (((kal_uint32)((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT)<<(dma_menu->size));
	   DMA_Save_Param[dma_no].len2 = ((kal_uint32)dma_menu->count-(kal_uint32)(((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT))<<(dma_menu->size);
	   DMA_Save_Param[dma_no].size = dma_menu->size;
   }

   DRV_WriteReg32(DMA_COUNT(dma_no),DMA_Save_Param[dma_no].len1);
   DRV_WriteReg32(DMA_WPPT(dma_no),DMA_Save_Param[dma_no].len2);

   if( limit != 0 )
   {
       dma_con |= (( limit << DMA_CON_SLOW_OFFSET )& DMA_CON_SLOW_MASK);
	   dma_con |= DMA_CON_SLOW_EN;
   }

   DRV_WriteReg32(DMA_CON(dma_no),dma_con);  
   
#else //__DMA_V3__

   switch(dma_menu->size) {
   case DMA_BYTE:

#if !defined(MT6218)
      if (dma_menu->type != DMA_SWCOPY) {

         if ( (((DMA_TMODE *)(dma_menu->menu))->burst_mode==KAL_TRUE) &&
              (((DMA_TMODE *)(dma_menu->menu))->cycle & 0xf0) )

            dma_con |= DMA_CON_BURST_16BEAT;

         else if ( (((DMA_TMODE *)(dma_menu->menu))->burst_mode==KAL_TRUE) &&
                   (((DMA_TMODE *)(dma_menu->menu))->cycle & 0x08) )

            dma_con |= DMA_CON_BURST_8BEAT;

         else if ( (((DMA_TMODE *)(dma_menu->menu))->burst_mode==KAL_TRUE) &&
                   (((DMA_TMODE *)(dma_menu->menu))->cycle & 0x04) )

             dma_con |= DMA_CON_BURST_4BEAT;
      }
#endif  /* ! MT6218 */

      break;

   case DMA_SHORT:

#if !defined(MT6218)
      if (dma_menu->type != DMA_SWCOPY) {

         if ( (((DMA_TMODE *)(dma_menu->menu))->burst_mode==KAL_TRUE) &&
              (((DMA_TMODE *)(dma_menu->menu))->cycle & 0xf8) )

            dma_con |= DMA_CON_BURST_8BEAT;

         else if ( (((DMA_TMODE *)(dma_menu->menu))->burst_mode==KAL_TRUE) &&
                   (((DMA_TMODE *)(dma_menu->menu))->cycle & 0x04) )

            dma_con |= DMA_CON_BURST_4BEAT;
      }
#endif  /* ! MT6218 */

      dma_con |= DMA_CON_SIZE_SHORT;

      break;

   case DMA_LONG:

#if !defined(MT6218)
      if (dma_menu->type != DMA_SWCOPY) {

         if ( (((DMA_TMODE *)(dma_menu->menu))->burst_mode==KAL_TRUE) &&
              (((DMA_TMODE *)(dma_menu->menu))->cycle & 0xfc) )

            dma_con |= DMA_CON_BURST_4BEAT;
      }
#endif  /* !MT6218 */

      dma_con |= DMA_CON_SIZE_LONG;

      break;

   default:

      ASSERT(0);

      break;
   }

   if (dma_menu->callback != NULL)
   {
      dma_con |= DMA_CON_ITEN;
      DMA_LISR_FUNC[dma_no-1] = dma_menu->callback;
   }

   DRV_WriteReg32(DMA_CON(dma_no),dma_con);
   DRV_WriteReg32(DMA_COUNT(dma_no),(kal_uint32)dma_menu->count);

   /* set the bandwidth limiter */

   _savedMask = SaveAndSetIRQMask();

   dma_gbl_class = dma_gbl_class_g;

   RestoreIRQMask(_savedMask);

   if (dma_gbl_class == 0) {

      /* full speed */

      DRV_WriteReg8(DMA_LIMITER(dma_no), 0);
   } else {

      dma_gbl = dma_gbl_class_to_grade[dma_gbl_class];

      priority = kal_get_mytask_priority();

      if (priority <= dma_gbl_priority_bank[0].upper && priority >= dma_gbl_priority_bank[0].lower)
         bank = dma_gbl_priority_bank[0].bank;
      else if (priority <= dma_gbl_priority_bank[1].upper && priority >= dma_gbl_priority_bank[1].lower)
         bank = dma_gbl_priority_bank[1].bank;
      else if (priority <= dma_gbl_priority_bank[2].upper && priority >= dma_gbl_priority_bank[2].lower)
         bank = dma_gbl_priority_bank[2].bank;
      else if (priority <= dma_gbl_priority_bank[3].upper && priority >= dma_gbl_priority_bank[3].lower)
         bank = dma_gbl_priority_bank[3].bank;
      else if (priority <= dma_gbl_priority_bank[4].upper && priority >= dma_gbl_priority_bank[4].lower)
         bank = dma_gbl_priority_bank[4].bank;
      else if (priority <= dma_gbl_priority_bank[5].upper && priority >= dma_gbl_priority_bank[5].lower)
         bank = dma_gbl_priority_bank[5].bank;
      else if (priority <= dma_gbl_priority_bank[6].upper && priority >= dma_gbl_priority_bank[6].lower)
         bank = dma_gbl_priority_bank[6].bank;
      else if (priority <= dma_gbl_priority_bank[7].upper && priority >= dma_gbl_priority_bank[7].lower)
         bank = dma_gbl_priority_bank[7].bank;
      else
         ASSERT(0);

      DRV_WriteReg8(DMA_LIMITER(dma_no), DMA_GBL_PRIORITY_2_BL(bank, dma_gbl));
   }

#if defined(MT6218B) || defined(MT6217)
   lcd_dma_slow_down(dma_gbl_class);
#endif

#endif //__DMA_V3__


   if (start) {

      /* configuration is done and start the DMA */

      DMA_Start(dma_no);
   }
}
kal_bool DMA_Valid_Addr_Chk(const void *src, kal_uint32 length)
{
#if defined(MT6276)
	if(((kal_uint32)(src) < 0x3FFFFFFF) && 
		/*check if across bank boundary*/
		((((kal_uint32)(src)+length) & ((kal_uint32)(src)& 0xF0000000))==((kal_uint32)(src)& 0xF0000000)))
	{
	  return KAL_TRUE;
	}
	else
	{
	  return KAL_FALSE;
	}
#else
	{
	  return KAL_TRUE;
	}
#endif /*MT6276*/
}
#pragma arm section

void DMA_ERROR_LISR(void)
{
   while(1);
}

#endif//__CARD_DOWNLOAD__
