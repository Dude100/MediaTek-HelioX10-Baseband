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
 *   bl_NFI.c
 *
 * Project:
 * --------
 *   Bootloader
 *
 * Description:
 * ------------
 *   NANDFlash driver.
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

#if defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__)

#if !defined(__NFI_VERSION3__) && !defined(__NFI_VERSION3_1__)

#include "flash_opt.h"

#if ( defined(__NAND_FDM_50__) && defined(__NFI_VERSION2__) )
//RHR remove    #include "kal_release.h" 
	#include "NAND_MTD_FDM50_internal.h"
	#include "NAND_DAL.h"
	#include "NAND_DAL_internal.h"
//RHR remove	#include "fat_fs.h"
//RHR remove	#include <bl_FOTA.h>
	#include <bl_loader.h>
	#include <bl_INIT.h>
	// Add for RHR 
//RHR remove  #include "kal_non_specific_general_types.h"
  #include "reg_base.h"
  #include "fs_errcode.h"	
  #include "kal_general_types.h"
  #include "kal_internal_api.h"  
  // Add for RHR 
#else //  ( defined(__NAND_FDM_50__) && defined(__NFI_VERSION2__) )
	#include <bl_types.h>
	#include <bl_MTK_BB_REG.h>
	#include <bl_FOTA.h>
	#include <bl_loader.h>
	#include <bl_INIT.h>
	#include <bl_NFI.h>
#endif  // ( defined(__NAND_FDM_50__) && defined(__NFI_VERSION2__) )

  
#define NFI_Wait_Ready(timeout)   while ( (*NFI_PSTA & STATUS_BUSY) && (--timeout) )

 
static const kal_uint8 FF_match_Table[256] = {
  0 ,1 ,1 ,2 ,1 ,2 ,2 ,3 ,1 ,2 ,2 ,3 ,2 ,3 ,3 ,4
 ,1 ,2 ,2 ,3 ,2 ,3 ,3 ,4 ,2 ,3 ,3 ,4 ,3 ,4 ,4 ,5
 ,1 ,2 ,2 ,3 ,2 ,3 ,3 ,4 ,2 ,3 ,3 ,4 ,3 ,4 ,4 ,5
 ,2 ,3 ,3 ,4 ,3 ,4 ,4 ,5 ,3 ,4 ,4 ,5 ,4 ,5 ,5 ,6
 ,1 ,2 ,2 ,3 ,2 ,3 ,3 ,4 ,2 ,3 ,3 ,4 ,3 ,4 ,4 ,5
 ,2 ,3 ,3 ,4 ,3 ,4 ,4 ,5 ,3 ,4 ,4 ,5 ,4 ,5 ,5 ,6
 ,2 ,3 ,3 ,4 ,3 ,4 ,4 ,5 ,3 ,4 ,4 ,5 ,4 ,5 ,5 ,6
 ,3 ,4 ,4 ,5 ,4 ,5 ,5 ,6 ,4 ,5 ,5 ,6 ,5 ,6 ,6 ,7
 ,1 ,2 ,2 ,3 ,2 ,3 ,3 ,4 ,2 ,3 ,3 ,4 ,3 ,4 ,4 ,5
 ,2 ,3 ,3 ,4 ,3 ,4 ,4 ,5 ,3 ,4 ,4 ,5 ,4 ,5 ,5 ,6
 ,2 ,3 ,3 ,4 ,3 ,4 ,4 ,5 ,3 ,4 ,4 ,5 ,4 ,5 ,5 ,6
 ,3 ,4 ,4 ,5 ,4 ,5 ,5 ,6 ,4 ,5 ,5 ,6 ,5 ,6 ,6 ,7
 ,2 ,3 ,3 ,4 ,3 ,4 ,4 ,5 ,3 ,4 ,4 ,5 ,4 ,5 ,5 ,6
 ,3 ,4 ,4 ,5 ,4 ,5 ,5 ,6 ,4 ,5 ,5 ,6 ,5 ,6 ,6 ,7
 ,3 ,4 ,4 ,5 ,4 ,5 ,5 ,6 ,4 ,5 ,5 ,6 ,5 ,6 ,6 ,7
 ,4 ,5 ,5 ,6 ,5 ,6 ,6 ,7 ,5 ,6 ,6 ,7 ,6 ,7 ,7 ,8
};
	


      //------------------------------------------------------- 
      // 512 page size spare area definition                    
      //------------------------------------------------------- 
      //                                                        
      // |... PAGE DATA ...|...SPARE...|E0|NG|CHK|              
      //                                                        
      //  We store the ECC parity, next good block address and  
      //  spare checksum in the last 2 DWORDs of spare data.    
      //                                                        
      //  E0 -> 4 bytes block-0 ECC parity. (PARITY 6~7)        
      //  NG -> 2 bytes row addr point to next good block.      
      //  CHK -> 2 bytes (16bits) checksum.                     
      //                             
      //------------------------------------------------------- 
      // 2048 page size spare area definition                   
      //------------------------------------------------------- 
      //                                                        
      // |... PAGE DATA ...|...SPARE...|E0|E1|E2|E3|NG|CHK|     
      //                                                        
      //  We store the ECC parity, next good block address and  
      //  spare checksum in the last 5 DWORDs of spare data.    
      //                                                        
      //  E0 -> 4 bytes block-0 ECC parity. (PARITY 0~1)        
      //  E1 -> 4 bytes block-1 ECC parity. (PARITY 2~3)        
      //  E2 -> 4 bytes block-2 ECC parity. (PARITY 4~5)        
      //  E3 -> 4 bytes block-3 ECC parity. (PARITY 6~7)        
      //  NG -> 2 bytes row addr point to next good block.      
      //  CHK -> 2 bytes 16bits checksum.                       
      //                                                                  

typedef union 
{
   kal_uint8    d8[4];
   kal_uint16  d16[2];
   kal_uint32  d32;
} UnionData_U;

/**********************************************************
Description : NFI_CheckGoodBlock
Input       : NFI_MENU, baseaddr must be page alignment
Output      : U32 return data
              512B/page, 8-bits interface, 0x????FF??
              otherwise, 0x????FFFF or 0x??????FF
              for good page
              2: Read error
***********************************************************/ 
static kal_uint32 NFI_CheckGoodBlock(NFI_MENU *input, kal_uint32 addr1, kal_uint16 addr2)
{
   kal_uint32 rb_data[4];
   kal_int32  timeout=0xffff, size;
   
   rb_data[0]= 0;
   rb_data[1]= 0;
   rb_data[2]= 0;
   rb_data[3]= 0;
   
#if defined (__NFI_VERSION2__)
    *NFI_CON=0x0;
    *NFI_OPCON = OPCON_RESET;
    while (*NFI_PSTA != 0);
#else
   *NFI_OPCON = 0x00;
   *NFI_CON = 0x00;        
   *NFI_FIFOCON = FIFO_FLUSH | RESET;                  // Flushing FIFO
#endif
   if ( input->pageSize<1024 )
   {
      *NFI_CON = SW_PROGSPARE_EN;        // program/read spare area enable
      *NFI_CMD = RD_SPARE_CMD;           // reading spare command      
      while (*NFI_PSTA & STATUS_CMD);     
      *NFI_ADDRL = (addr1&0xffffff00);    
      *NFI_ADDRM = 0;
      *NFI_ADDNOB = input->addressCycle; // number of bytes for address
      while (*NFI_PSTA & STATUS_ADDR);    
   }
   else
   {
      *NFI_CON = SW_PROGSPARE_EN;        // program spare area enable
      *NFI_CMD = RD_1ST_CMD;             // read spare command
      while (*NFI_PSTA & STATUS_CMD);     
      if ( input->IOInterface == IO_8BITS )
         *NFI_ADDRL = addr1 + 2048;
      else
         *NFI_ADDRL = addr1 + 1024;
      if ( input->addressCycle>4 )
         *NFI_ADDRM = addr2;
      *NFI_ADDNOB = input->addressCycle; // number of bytes for address
      while (*NFI_PSTA & STATUS_ADDR);      
      *NFI_CMD = RD_2ND_CYCLE_CMD;            
      while (*NFI_PSTA & STATUS_CMD);      
   }      

   *NFI_OPCON = BURST_RD;  // set burst read   
   
   while( *NFI_PSTA & STATUS_DATAR );
   
   NFI_Wait_Ready(timeout);
   
   if ( timeout==0 )
   {
      *NFI_OPCON = 0x0;
      return 2;
   }
   
   size = 0;
   timeout=0xffff;
   
   while ( (size<4) && timeout>0 )
    {
       #if defined (__NFI_VERSION2__)
	   if ( !(*NFI_FIFOSTA&RD_EMPTY_MASK) )
       #else       
      if ( !(*NFI_FIFOCON&RD_EMPTY_MASK) )
       #endif
      {
         rb_data[size] = *NFI_DATAR;
         size ++;
      }
      else 
         timeout--;
   }
   
   // Caution: This line must not be omitted!
   *NFI_OPCON = 0x0;

   if ( timeout<=0 )
      return 3;
      
   if ( input->pageSize<1024 )
   {
      if ( input->IOInterface == IO_8BITS )
         return ( (kal_uint32)((rb_data[1]&0xff00)>>8) );
      else
         return ( ((kal_uint32)(rb_data[0]&0xff) | (rb_data[1]&0xff00)) );
   }
   else
   {
      if ( input->IOInterface == IO_8BITS )
         return ( (kal_uint32)(rb_data[0]&0xff) );
      else
         return ( (kal_uint32)(rb_data[0]&0xffff) );
   }
}

#ifdef __EXT_BOOTLOADER__


#if defined(__FOTA_DM__) &&  defined(_NAND_FLASH_BOOTING_)

extern kal_uint32 nfi_spare_buffer[];
/**********************************************************
 Imported functions
 **********************************************************/
extern kal_uint32 INT_GetCurrentTime(void);

/**********************************************************
Description : NFI_Read_Status
Input       : .......
Output      : _RET_CODE
***********************************************************/            
kal_uint8 NFI_Read_Status(void)
{
	kal_uint8 cmd_status;

	*NFI_CMD = RD_STATUS_CMD;
	while (*NFI_PSTA & STATUS_CMD);
	*NFI_OPCON = (NOB_BYTE | SINGLE_RD);
	while (*NFI_PSTA & STATUS_DATAR);
	cmd_status = (kal_uint8)(*NFI_DATAR);
		
	return cmd_status;
} /*  End of read_status */
#endif /* __FOTA_DM__ */

extern BOOTL_HEADER  BLHeader;   


/**********************************************************
Description : NFI_PageRead
Input       : .......
Output      : _RET_CODE
Remark      : Must be page alignment
***********************************************************/
_RET_CODE NFI_PageRead(kal_uint32 *destination, kal_uint32 *parity, kal_uint32 length, \
                       kal_uint16 addr_no, kal_uint32 addr1, kal_uint16 addr2, kal_uint16 pageSize, \
                       kal_bool ECC, kal_bool continous)
{
#if ( defined(__NAND_FDM_50__) && defined(__NFI_VERSION2__) )
    //static kal_uint32 tmp_PageBuff[2112/4];
    kal_uint32 block;
    kal_uint32 page;
    kal_int32 retVal;
    if ( BLHeader.NFIinfo.addressCycle > 4)
    {
        block = ((addr2<<16)|(addr1>>(BLHeader.NFIinfo.pageShift)))/BLHeader.pagesPerBlock;
        page = ((addr2<<16)|(addr1>>(BLHeader.NFIinfo.pageShift)))%BLHeader.pagesPerBlock;
    }        
    else
    {
        block = (addr1>>(BLHeader.NFIinfo.pageShift))/BLHeader.pagesPerBlock;
        page = (addr1>>(BLHeader.NFIinfo.pageShift))%BLHeader.pagesPerBlock;
    }

    if (length == pageSize)
    {
        retVal = NFB_ReadPhysicalPage(block,page, destination);
    }
    else
    {
        dbg_print("[Error] NFI_PageRead with length != pageSize\n\r");
        retVal = -1;
    }
//    if (retVal != -1)
    if (retVal >= 0)
        return NFI_SUCCESS;
    else
        return NFI_GENERAL_ERR;
#else	// ( defined(__NAND_FDM_50__) && defined(__NFI_VERSION2__) )
   kal_int32   timeout=0xffff;
   kal_uint32  *parity_ptr = parity;
   _RET_CODE   retStatus =  NFI_SUCCESS;
   
#if defined (__NFI_VERSION2__)
    *NFI_CON=0x0;
    *NFI_OPCON = OPCON_RESET;
    while (*NFI_PSTA != 0);
#else
   *NFI_OPCON = 0x00;   
   *NFI_CON = 0x00;        
   *NFI_FIFOCON = FIFO_FLUSH | RESET;                  // Flushing FIFO
#endif
   if ( pageSize<1024 )
   {
      *NFI_CMD = RD_1ST_CMD;             // read command 
      while (*NFI_PSTA & STATUS_CMD);      
      *NFI_ADDRL = addr1;
      if ( addr_no>4 )
         *NFI_ADDRM = addr2;
      *NFI_ADDNOB = addr_no;              // number of bytes for address      
      while (*NFI_PSTA & STATUS_ADDR);      
   }
   else
   {
      *NFI_CMD = RD_1ST_CMD;              // Issue data input command
      while (*NFI_PSTA & STATUS_CMD);      
      *NFI_ADDRL = addr1;
      if ( addr_no>4 )
         *NFI_ADDRM = addr2;
      *NFI_ADDNOB = addr_no;              // no. of bytes for address   
      while (*NFI_PSTA & STATUS_ADDR);      
      *NFI_CMD = RD_2ND_CYCLE_CMD;
      while (*NFI_PSTA & STATUS_CMD);      
   }
   while( *NFI_PSTA & STATUS_DATAR );
   
   NFI_Wait_Ready(timeout);
   
   if ( timeout==0 )
      return NFI_READ_DATA_TIMEOUT;

   // Activating DMA transfer
   if ( ECC )
   {
       #if defined (__NFI_VERSION2__)
       *NFI_CON = (DMA_RD_EN |SW_PROGSPARE_EN| MAIN_ECC_EN|SPARE_ECC_EN|AUTO_ECC_DEC);
       #else        
      *NFI_CON = (DMA_RD_EN | AUTOECC_DEC_EN);
       #endif
   }
   else
      *NFI_CON = DMA_RD_EN;
   
   *NFI_OPCON = BURST_RD;    // set burst read


    #if defined (__NFI_VERSION2__)
	    *(volatile kal_uint32 *)(DMA_base+0x0118)   = 0x0000;                       //(DMA1_START)  
	    *(volatile kal_uint32 *)(DMA_base+0x0100)   = (kal_uint32)NFI_DATAR;        //(DMA1_SRC)    
	    *(volatile kal_uint32 *)(DMA_base+0x0104)   = (kal_uint32)destination;      //(DMA1_DST)    
	    *(volatile kal_uint32 *)(DMA_base+0x0110)   = length>>2;                    //(DMA1_COUNT)  
	    *(volatile kal_uint32 *)(DMA_base+0x0114)   = 0x00f4001a;                   //(DMA1_CONTRL) 
	    *(volatile kal_uint32 *)(DMA_base+0x0128)   = 0;                            //(DMA1_LIMITER)
	    *(volatile kal_uint32 *)(DMA_base+0x0118)   = 0x8000;                       //(DMA1_START)  
	   
 	   timeout = 0xffff;
	    while ( ((*(volatile kal_uint32 *)(DMA_base+0x0000)&0x03)==0x01) && (--timeout) );//(DMA_GLBSTS) 
    #else                                                                                       
	*(volatile kal_uint32 *)(DMA_base+0x0118) = 0x0000;                              //(DMA1_START)  
	*(volatile kal_uint32 *)(DMA_base+0x0100) = (kal_uint32)NFI_DATAR;               //(DMA1_SRC)    
	*(volatile kal_uint32 *)(DMA_base+0x0104) = (kal_uint32)destination;             //(DMA1_DST)    
	*(volatile kal_uint32 *)(DMA_base+0x0110) = length>>2;                           //(DMA1_COUNT)  
	*(volatile kal_uint32 *)(DMA_base+0x0114) = 0x00f4001a;                          //(DMA1_CONTRL) 
	*(volatile kal_uint32 *)(DMA_base+0x0128) = 0;                                   //(DMA1_LIMITER)
	*(volatile kal_uint32 *)(DMA_base+0x0118) = 0x8000;                              //(DMA1_START)  
   
    timeout = 0xffff;
    while ( ((*(volatile kal_uint32 *)(DMA_base+0x0000)&0x03)==0x01) && (--timeout) );//(DMA_GLBSTS) 
    #endif
   
   if ( timeout==0 )
      return DMA_TRANSFER_DATA_TIMEOUT;
         
//   while (!(*NFI_FIFOCON & RD_EMPTY_MASK) || (*NFI_PSTA & STATUS_DATAR));
   while (*NFI_PSTA & STATUS_BUSY);   

#if defined (__NFI_VERSION2__) /*ECC correction processes at __NFI_VERSION2__ case*/
   if ( ECC )
   {
       kal_uint32 spare[1];
       kal_uint32 Error;
       kal_uint16 i;

//       if ((*NFI_PAGEFMT & 0x70) != ECC_BLKSIZE_256) /*Should be ECC_BLKSIZE_256*/
       if ((*NFI_PAGEFMT & 0x70) != 0x10) /*Should be ECC_BLKSIZE_256*/
           return NFI_ZERO_POINTER;

       if ( pageSize == 2048)
       {
           /*read the remain content and get ECC value*/
           for ( i = (length>>2) ; i < ((2048+64)>>2); i ++)
           {
               while(FIFO_RD_REMAIN (*NFI_FIFOSTA ) < 4);
               spare[0] = *NFI_DATAR; /*Hardware ECC decode and don't care content*/
           }
           Error = *NFI_ERRDET;
           if ( Error !=0)
           {
               if ( (Error & (ERRDET_PEBLK0|ERRDET_PEBLK1|ERRDET_PEBLK2|ERRDET_PEBLK3|
                              ERRDET_PEBLK4|ERRDET_PEBLK5|ERRDET_PEBLK6|ERRDET_PEBLK7)) != 0)
               {   /*main area has recoverable error*/
                   kal_uint32 Syndrome;
                   kal_uint16 UpdateAddr;
                   kal_uint8  UpdateData;
                   for(i=0;i<8;i++) /*8 ECC blocks*/
                   {
                      if((Error>>(i+16))&1) /*recoverable range*/
                      {
                         UpdateAddr = (*(volatile kal_uint16*)((kal_uint32)NFI_SYM0_ADDR + (4*i)) ); /*NFI_SYM0_ADDR~NFI_SYM7_ADDR*/
                         Syndrome = (*(volatile kal_uint32*)((kal_uint32)NFI_SYM0_DAT + (4*i)) );    /*NFI_SYM0_DAT~NFI_SYM7_DAT*/
                         UpdateData = ((Syndrome >> ((UpdateAddr & 0x03) << 3)) & 0xFF);
                         ((kal_uint8*)destination)[UpdateAddr] ^= UpdateData; 
                         #ifdef BL_DEBUG
                         dbg_print("1 bit err at Block:%d page:%d offset:%d, bit:%d, fixed value:%x\n\r", 
                                   ((addr1>>16)|(addr2<<16))/64,(addr1>>16)|(addr2<<16)%64,UpdateAddr,UpdateData,((kal_uint8*)destination)[UpdateAddr] );				
                         #endif
                      }
                   }
                   retStatus = NFI_ECC_1BIT_CORRECT;
               }

               if ( (Error & (ERRDET_EBLK0|ERRDET_EBLK1|ERRDET_EBLK2|ERRDET_EBLK3|
                              ERRDET_EBLK4|ERRDET_EBLK5|ERRDET_EBLK6|ERRDET_EBLK7)) != 0)
               {   /*main area has unrecoverable error or ECC damaged*/
                   #ifdef BL_DEBUG
                   dbg_print("uncoverable err at Block:%d page:%d \n\r", 
                             ((addr1>>16)|(addr2<<16))/64,(addr1>>8)|(addr2<<24) );
                   #endif
                   retStatus = NFI_ECC_2BITS_ERR;
               }
           }
       }
       else /* pageSize == 512 */
       {
           /*read the remain content and get ECC value*/    
           for ( i = (length>>2) ; i < ((512+16)>>2); i ++)
           {
               while(FIFO_RD_REMAIN (*NFI_FIFOSTA ) < 4);
               spare[0] = *NFI_DATAR; /*Hardware ECC decode and don't care content*/
           }
           Error = *NFI_ERRDET;
           if ( Error !=0)
           {
               if ( (Error & (ERRDET_PEBLK0|ERRDET_PEBLK1)) != 0)
               {    /*main area has recoverable error*/
                   kal_uint32 Syndrome;
                   kal_uint16 UpdateAddr;
                   kal_uint8  UpdateData;
                   for(i=0;i<2;i++) /*2 ECC blocks*/
                   {
                      if((Error>>(i+16))&1) /*recoverable range*/
                      {
                         UpdateAddr = (*(volatile kal_uint16*)((kal_uint32)NFI_SYM0_ADDR + (4*i)) ); /*NFI_SYM0_ADDR~NFI_SYM1_ADDR*/
                         Syndrome = (*(volatile kal_uint32*)((kal_uint32)NFI_SYM0_DAT + (4*i)) );    /*NFI_SYM0_DAT~NFI_SYM1_DAT*/
                         UpdateData = ((Syndrome >> ((UpdateAddr & 0x03) << 3)) & 0xFF);
                         ((kal_uint8*)destination)[UpdateAddr] ^= UpdateData; 
                         #ifdef BL_DEBUG
                         dbg_print("1 bit err at Block:%d page:%d offset:%d, bit:%d, fixed value:%x\n\r", 
                                   ((addr1>>8)|(addr2<<24))/32,(addr1>>8)|(addr2<<24)%32,UpdateAddr,UpdateData,((kal_uint8*)destination)[UpdateAddr] );				
                         #endif
                      }
                   }
                   retStatus = NFI_ECC_1BIT_CORRECT;
               }
               if( (Error & (ERRDET_EBLK0|ERRDET_EBLK1)) != 0)
               {   /*main area has uncoverable error*/
                   #ifdef BL_DEBUG
                   dbg_print("uncoverable err at Block:%d page:%d \n\r", 
                             ((addr1>>8)|(addr2<<24))/32,(addr1>>8)|(addr2<<24) );
                   #endif
                   retStatus = NFI_ECC_2BITS_ERR;
               }
           }
       }
   }
#else /*only ECC detection do at !(__NFI_VERSION2__) case*/
   if ( ECC )
   {
      if ( parity==NULL )
         return NFI_ZERO_POINTER;
       
      if ( pageSize<1024 )
      {
         while (*NFI_PAGECNTR !=1);
         //parity_ptr[0] = *NFI_PAR6;
         //parity_ptr[0] |= (*NFI_PAR7) << 16;         
         parity_ptr[0] = *NFI_PAR0;
         parity_ptr[0] |= (*NFI_PAR1) << 16;            
      }
      else
      {
         parity_ptr[0] = *NFI_PAR0;
         parity_ptr[0] |= (*NFI_PAR1) << 16;
         parity_ptr[1] = *NFI_PAR2;
         parity_ptr[1] |= (*NFI_PAR3) << 16;
         parity_ptr[2] = *NFI_PAR4;
         parity_ptr[2] |= (*NFI_PAR5) << 16;
         parity_ptr[3] = *NFI_PAR6;
         parity_ptr[3] |= (*NFI_PAR7) << 16;
      }         
   }
#endif
   
   // Caution: This line must not omitted!
#if defined (__NFI_VERSION2__)
   *NFI_OPCON = OPCON_RESET;
   while (*NFI_PSTA != 0);
#else
   *NFI_OPCON = 0x0;
#endif
   
   if ( timeout > 0)
	   return retStatus;
   else 
      return NFI_READ_DATA_TIMEOUT;
      
#endif /*( defined(__NAND_FDM_50__) && defined(__NFI_VERSION2__) )*/
}

#if defined(__FOTA_DM__) &&  defined(_NAND_FLASH_BOOTING_) && !defined(__NFI_VERSION2__)
/**********************************************************
Description : NFI_PageWrite
Input       : .......
Output      : _RET_CODE
Remark      : Must be page alignment
***********************************************************/
_RET_CODE NFI_PageWrite(kal_uint32 *source, kal_uint32 length, kal_uint16 addr_no, \
                        kal_uint32 addr1, kal_uint16 addr2, kal_uint16 pageSize, kal_bool ECC)
{
   kal_int32   timeout=0xfff;
   kal_uint32  *parity_ptr = NULL;
   kal_uint16  chksum = 0;
   kal_uint16  *chksum_ptr = 0;
   kal_uint16  i;
   kal_uint32  current_time = 0, start_time = 0;

   if( (kal_uint32)source & 0x03)
      return NFI_BUFFER_NOT_ALIGNED;
   
   *NFI_OPCON = 0x00;   
   *NFI_CON = 0x00;        
   *NFI_FIFOCON = FIFO_FLUSH | RESET;                  // Flushing FIFO

   if ( pageSize<1024 )
   {
       /* reset pointer */
	   *NFI_CMD = RD_1ST_CMD;				// read command
	   while (*NFI_PSTA & STATUS_CMD);
	   *NFI_OPCON = 0;
	   *NFI_FIFOCON = FIFO_FLUSH | RESET;  // Flushing FIFO
	
	   *NFI_CON = SW_PROGSPARE_EN;
	   *NFI_CMD = INPUT_DATA_CMD;          // Issue data input command
	   while (*NFI_PSTA & STATUS_CMD);	   
	   *NFI_ADDRL = addr1;
	   if ( addr_no>4 )
	      *NFI_ADDRM = addr2;
	   *NFI_ADDNOB = addr_no;	           // number of bytes for address	   
	   while (*NFI_PSTA & STATUS_ADDR);	   
	}
	else
	{
	   *NFI_CON = SW_PROGSPARE_EN;
	   *NFI_CMD = INPUT_DATA_CMD;          // Issue data input command
	   while (*NFI_PSTA & STATUS_CMD);	   
	   *NFI_ADDRL = addr1;
	   if ( addr_no>4 )
	      *NFI_ADDRM = addr2;
	   *NFI_ADDNOB = addr_no;	           // no. of bytes for address	
	   while (*NFI_PSTA & STATUS_ADDR);	   
	}

   *NFI_OPCON = BURST_WR;    // set burst write
   
   // Activating DMA transfer
   *NFI_CON |= DMA_WR_EN;
   
   *(volatile kal_uint32 *)(DMA_base+0x0118) = 0x0000;
   *(volatile kal_uint32 *)(DMA_base+0x0100) = (kal_uint32)source;
   *(volatile kal_uint32 *)(DMA_base+0x0104) = (kal_uint32)NFI_DATAW;
   *(volatile kal_uint32 *)(DMA_base+0x0110) = length>>2;
   *(volatile kal_uint32 *)(DMA_base+0x0114) = 0x00f00016;
   *(volatile kal_uint32 *)(DMA_base+0x0128) = 0;
   *(volatile kal_uint32 *)(DMA_base+0x0118) = 0x8000;
   
   timeout = 0xfff;
   while ( ((*(volatile kal_uint32 *)(DMA_base+0x0000)&0x03)==0x01) && (--timeout) ); 
   if ( timeout==0 )
   {
       *NFI_OPCON = 0x0;
	   return DMA_TRANSFER_DATA_TIMEOUT;
   }

   timeout = 0xfff;
   while( (*NFI_ADDRCNTR < length) && (--timeout) );
   if ( timeout==0 )
   {
       *NFI_OPCON = 0x0;
	   return NFI_TRANSFER_DATA_TIMEOUT;
   }

   for(i = 0 ; i < 16 ; i++)
      nfi_spare_buffer[i] = 0xFFFFFFFF;

   if ( ECC )
   {
      chksum = 0;
      if ( pageSize<1024 )
      {
         parity_ptr = &nfi_spare_buffer[2];
         *parity_ptr = (*(volatile kal_uint16 *)(NFI_base+0x0098)) | ((*(volatile kal_uint16 *)(NFI_base+0x009C)) << 16);
         chksum_ptr = (kal_uint16 *)(&nfi_spare_buffer[0]);
         for(i = 0 ; i < 7 ; i++)
            chksum += chksum_ptr[i];
         chksum_ptr[i] = chksum;
         /* transfer spare content to flash */
         for(i = 0 ; i < 4 ; i++)
         {
            timeout = 0xfff;
            while ( (!(*NFI_FIFOCON & WR_EMPTY_MASK)) && (--timeout));
            if ( timeout==0 )
            {
               return NFI_TRANSFER_DATA_TIMEOUT;
            }
            *NFI_DATAW = nfi_spare_buffer[i];
         }
      }
      else
      {
         parity_ptr = &nfi_spare_buffer[11];
         for (i=0; i<4; i++)
            *parity_ptr++ = (*(volatile kal_uint16 *)(NFI_base+0x0080+(i<<3))) | ((*(volatile kal_uint16 *)(NFI_base+0x0080+(i<<3)+4)) << 16);
         chksum_ptr = (kal_uint16 *)(&nfi_spare_buffer[0]);
         for(i = 0 ; i < 31 ; i++)
            chksum += chksum_ptr[i];
         chksum_ptr[i] = chksum;
         /* transfer spare sare content to flash */
         for(i = 0 ; i < 16 ; i++)
         {
            timeout = 0xfff;
            while ( (!(*NFI_FIFOCON & WR_EMPTY_MASK)) && (--timeout));
            if ( timeout==0 )
            {
               return NFI_TRANSFER_DATA_TIMEOUT;
            }
            *NFI_DATAW = nfi_spare_buffer[i];
         }
      }
   }
   timeout = 0xfff;
   while ( (!(*NFI_FIFOCON & WR_EMPTY_MASK)) && (--timeout));
   if ( timeout==0 )
   {
	   return NFI_TRANSFER_DATA_TIMEOUT;
   }

   timeout = 0xfff;
   while ((*NFI_PSTA & STATUS_DATAW) && (--timeout));
   // Caution: This line must not be omitted!
   *NFI_OPCON = 0x0;
   if ( timeout==0 )
	   return NFI_TRANSFER_DATA_TIMEOUT;

	*NFI_INTR_EN = BUSY_RETURN_EN;
	*NFI_CMD = PROG_DATA_CMD;		// Issue program command
	while (*NFI_PSTA & STATUS_CMD);

	/* wait for program busy period (200us) */
	start_time = INT_GetCurrentTime();
	do
	{
	   current_time = INT_GetCurrentTime();
	   if(current_time > start_time)
	   {
	      if( (current_time - start_time) > 7)
	         break;
	   }
	   else
	   {
	      if( (0xFFFFFFFF - start_time + current_time + 1) > 7)
	         break;
	   }
	}while(1);

   /* wait for program complete */
   timeout = 0xfff;
   while ( (!(*NFI_INTR & BUSY_RETURN)) && (--timeout));
	*NFI_INTR_EN = 0;

   if ( timeout == 0)
      return NFI_WRITE_DATA_TIMEOUT;

	/* check whether operation is successful */
	if(NFI_Read_Status() & 0x01)
	   return NFI_PROGRAM_FAILED;

	return NFI_SUCCESS;
}
#endif /* __FOTA_DM__ */

/**********************************************************
Description : GoodBlockChecking
Input       : NFI_MENU, NFIReadPtr must be page alignment
Output      : TRUE, good block, FALSE, bad block
***********************************************************/
kal_bool GoodBlockChecking(NFI_MENU *input, kal_uint32 addr1, kal_uint16 addr2)
{
#if ( defined(__NAND_FDM_50__) && defined(__NFI_VERSION2__) )
{
    kal_uint32 Block;
    if ( input->addressCycle > 4)
        Block = ((addr2<<16)|(addr1>>(input->pageShift)))/BLHeader.pagesPerBlock;
    else
        Block = (addr1>>(input->pageShift))/BLHeader.pagesPerBlock;

    return (NFB_CheckGoodBlock(Block) == 0) ? KAL_TRUE:KAL_FALSE;
}
#else
{	
   kal_uint32 marking, i;
      
   for (i=0; i<2; i++)
   {
      // Read the bad block marking from the first page
      marking = NFI_CheckGoodBlock(input, addr1, addr2);
      if ( input->pageSize < 1024 ) {
		if ( FF_match_Table[marking & 0xff] < 7 ) {
			return KAL_FALSE;
		}
      } else {
		if ( FF_match_Table[marking & 0xff] < 7) {
			return KAL_FALSE;
		}
		if (input->IOInterface == IO_16BITS) {
			if ( (FF_match_Table[(marking>>8) & 0xff]) < 7 ) {	
				return KAL_FALSE;
			}
		}
      }
      //if ( (marking!=0xff) && (marking!=0xffff) )
      //   return KAL_FALSE;
      addr1 = addr1 + (1<<input->pageShift);
   }
         
   return KAL_TRUE;
}
#endif
}

#if defined(__FOTA_DM__) &&  defined(_NAND_FLASH_BOOTING_)
/**********************************************************
Description : NFI_EraseBlock
Input       : addr1, addr2 must be block aligned
Output      : 
***********************************************************/
_RET_CODE NFI_EraseBlock(kal_uint16 addr_no, kal_uint32 addr1, kal_uint16 addr2, kal_uint16 pageSize)
{
   kal_int32 timeout = 0xfff;
   kal_uint32 addr_cycle = 0;
   kal_uint32 current_time = 0, start_time = 0;
   
	*NFI_CON = 0x0;
	*NFI_OPCON = 0x0;

	*NFI_INTR_EN = ERASE_COMPLETE_EN;

	*NFI_CMD = BLOCK_ERASE1_CMD;		// erase command phase 1
	while (*NFI_PSTA & STATUS_CMD);

	if(pageSize < 1024)
	{
		*NFI_ADDRL = addr1;				// erase block address
		addr_cycle = addr_no - 1;		// no. of block address
		if(addr_cycle > 4)
		   *NFI_ADDRM = addr2;
	}
	else
	{
		*NFI_ADDRL = addr1;				// erase block address
		addr_cycle = addr_no - 2;		// no. of block address
		if(addr_cycle > 4)
		   *NFI_ADDRM = addr2;
	}
	*NFI_ADDNOB = addr_cycle; // number of bytes for address
	while (*NFI_PSTA & STATUS_ADDR);

	*NFI_CMD = BLOCK_ERASE2_CMD;		// erase command phase 2
	while (*NFI_PSTA & STATUS_CMD);
	*NFI_OPCON = 0x0;

	/* wait for erase busy period (2ms) */
	start_time = INT_GetCurrentTime();
	do
	{
	   current_time = INT_GetCurrentTime();
	   if(current_time > start_time)
	   {
	      if( (current_time - start_time) > 67)
	         break;
	   }
	   else
	   {
	      if( (0xFFFFFFFF - start_time + current_time + 1) > 67)
	         break;
	   }
	}while(1);
	/* wait for erase complete */
	while ( (!(*NFI_INTR & ERASE_COMPLETE)) && (--timeout));
	if(timeout == 0)
	{
	   return NFI_ERASE_TIMEOUT;
	}
	/* check whether operation is successful */
	if(NFI_Read_Status() & 0x01)
	   return NFI_ERASE_FAILED;

	return NFI_SUCCESS;
}

#if !defined(__NFI_VERSION2__)
/**********************************************************
Description : NFI_SpareWrite
Input       : .......
Output      : _RET_CODE
Remark      : Must be spare area aligned
***********************************************************/
_RET_CODE NFI_SpareWrite(kal_uint32 *spare, kal_uint16 addr_no, kal_uint32 addr1, \
                        kal_uint16 addr2, kal_uint16 pageSize, kal_uint16 IO)
{
   kal_int32 timeout=0xfff, size;
   kal_uint32 i = 0;
   kal_uint32 current_time = 0, start_time = 0;

   if( (kal_uint32)spare & 0x03)
      return NFI_BUFFER_NOT_ALIGNED;

   *NFI_OPCON = 0x00;
   *NFI_CON = 0x00;        
   *NFI_FIFOCON = FIFO_FLUSH | RESET;    // Flushing FIFO
   *NFI_CON = SW_PROGSPARE_EN;        // program/read spare area enable

   while (!(*NFI_FIFOCON & WR_EMPTY_MASK));

   if ( pageSize<1024 )
   {
	   size = 16;

	   *NFI_CMD = RD_SPARE_CMD;			  // pointer opration to spare area
	   while (*NFI_PSTA & STATUS_CMD);	

	   *NFI_CMD = INPUT_DATA_CMD;			 // reading spare command	   
	   while (*NFI_PSTA & STATUS_CMD);	

	   *NFI_ADDRL = (addr1&0xffffff00);	
	   if ( addr_no>4 )
	      *NFI_ADDRM = addr2;
	   *NFI_ADDNOB = addr_no;            // number of bytes for address
	   while (*NFI_PSTA & STATUS_ADDR);	 
	}
	else
	{
	   size = 64;

	   *NFI_CMD = INPUT_DATA_CMD;			 // reading spare command	   
	   while (*NFI_PSTA & STATUS_CMD);	

	   if ( IO==IO_16BITS )
	      addr1 += 1024;
	   else
	      addr1 += 2048;
	   *NFI_ADDRL = addr1;
	   if ( addr_no>4 )
	      *NFI_ADDRM = addr2;
	   *NFI_ADDNOB = addr_no;             // number of bytes for address
	   while (*NFI_PSTA & STATUS_ADDR);	   
	}

	*NFI_OPCON = BURST_WR;     // set burst write

	for( i = 0 ; i < size ; i++ )
	{
       timeout = 0xfff;
	   while((*NFI_FIFOCON & WR_FULL_MASK) && (--timeout));
	   if(timeout == 0)
	   {
	      *NFI_OPCON = 0x0;
	      return NFI_TRANSFER_SPARE_TIMEOUT;
	   }
	   *NFI_DATAW = nfi_spare_buffer[i];
	}

    timeout = 0xfff;
	while( (!(*NFI_FIFOCON & WR_EMPTY_MASK)) && (--timeout));
	if(timeout == 0)
	{
	   *NFI_OPCON = 0x0;
	   return NFI_TRANSFER_SPARE_TIMEOUT;
	}

	*NFI_INTR_EN = BUSY_RETURN_EN;
	*NFI_CMD = PROG_DATA_CMD;		// Issue program command
	while (*NFI_PSTA & STATUS_CMD);

	/* wait for program busy period (200us) */
	start_time = INT_GetCurrentTime();
	do
	{
	   current_time = INT_GetCurrentTime();
	   if(current_time > start_time)
	   {
	      if( (current_time - start_time) > 7)
	         break;
	   }
	   else
	   {
	      if( (0xFFFFFFFF - start_time + current_time + 1) > 7)
	         break;
	   }
	}while(1);

   /* wait for program complete */
   timeout = 0xfff;
   while ( (!(*NFI_INTR & BUSY_RETURN)) && (--timeout));
	*NFI_INTR_EN = 0;

   // Caution: This line must not omitted!
   *NFI_OPCON = 0x0;
   if ( timeout == 0 )
	   return NFI_WRITE_SPARE_TIMEOUT;

	/* check whether operation is successful */
	if(NFI_Read_Status() & 0x01)
	   return NFI_PROGRAM_FAILED;

	return NFI_SUCCESS;
}

#endif // !defined(__NFI_VERSION2__)

#if defined(NFI_BASIC_TEST)
extern kal_uint32 nfi_page_buffer[];
extern Nand_ImageList_S ImageHeader; 
extern BOOTL_HEADER  BLHeader;
#define TEST_BLOCK (7)
void test_nfi(void)
{
   kal_uint32 addr1 = 0, addr2 = 0;
   kal_uint32 idx = 0;
   kal_uint8 *byte_ptr = (kal_uint8 *)&nfi_page_buffer[0];
   /* erase block */
   addr1 = TEST_BLOCK <<(BLHeader.blockShift-BLHeader.NFIinfo.pageShift);
   addr2 = TEST_BLOCK >> (32 - (BLHeader.blockShift-BLHeader.NFIinfo.pageShift));
   if( NFI_SUCCESS != NFI_EraseBlock(BLHeader.NFIinfo.addressCycle, addr1, 0, BLHeader.NFIinfo.pageSize) )
      while(1);
   addr1 = addr1 << BLHeader.NFIinfo.pageShift;
   if(BLHeader.NFIinfo.addressCycle > 4)
   {
      addr2 = TEST_BLOCK >> (32 - BLHeader.blockShift);
   }
   else addr2 = 0;
   /* write certain pattern to page area */
   for(idx = 0 ; idx < BLHeader.NFIinfo.pageSize ; idx++)
   {
      byte_ptr[idx] = idx&0xFF;
   }
   if(NFI_SUCCESS != NFI_PageWrite(nfi_page_buffer, BLHeader.NFIinfo.pageSize, BLHeader.NFIinfo.addressCycle, 
                                  addr1, addr2, BLHeader.NFIinfo.pageSize, KAL_TRUE))
      while(1);
   /* read back to verify */
   for(idx = 0 ; idx < (BLHeader.NFIinfo.pageSize>>2) ; idx++)
   {
      nfi_page_buffer[idx] = 0xFFFFFFFF;
   }
   for(idx = 0 ; idx < 16 ; idx++)
   {
      nfi_spare_buffer[idx] = 0xFFFFFFFF;
   }
   if(NFI_SUCCESS != NFI_PageRead(nfi_page_buffer, nfi_spare_buffer, BLHeader.NFIinfo.pageSize, BLHeader.NFIinfo.addressCycle, 
                                  addr1, addr2, BLHeader.NFIinfo.pageSize, KAL_TRUE, KAL_FALSE))
      while(1);

   for(idx = 0 ; idx < BLHeader.NFIinfo.pageSize ; idx++)
   {
      if(byte_ptr[idx] != (idx&0xFF))
         while(1);
   }

   /* write certain pattern to spare area of next page */
   addr1 += (1 << BLHeader.NFIinfo.pageShift);
   byte_ptr = (kal_uint8 *)&nfi_spare_buffer[0];
   for(idx = 0 ; idx < 64 ; idx++)
   {
      byte_ptr[idx] = idx&0xFF;
   }
   if(BLHeader.NFIinfo.pageSize < 1024)
   {
      byte_ptr[5]=0xFF; /* bad block indication */
   }
   else
   {
      byte_ptr[0]=0xFF; /* bad block indication */
      byte_ptr[1]=0xFF; /* bad block indication */
   }
   if(NFI_SUCCESS != NFI_SpareWrite(nfi_spare_buffer, BLHeader.NFIinfo.addressCycle, addr1, addr2, BLHeader.NFIinfo.pageSize, IO_8BITS))
      while(1);
   /* read back to verify */
   for(idx = 0 ; idx < (BLHeader.NFIinfo.pageSize>>2) ; idx++)
   {
      nfi_page_buffer[idx] = 0xFFFFFFFF;
   }
   for(idx = 0 ; idx < 64 ; idx++)
   {
      nfi_spare_buffer[idx] = 0xFFFFFFFF;
   }
   if(NFI_SUCCESS != NFI_SpareRead(nfi_spare_buffer, BLHeader.NFIinfo.addressCycle, addr1, addr2, BLHeader.NFIinfo.pageSize, IO_8BITS))
      while(1);

   for(idx = 0 ; idx < BLHeader.NFIinfo.pageSize ; idx++)
   {
      if(BLHeader.NFIinfo.pageSize < 1024)
      {
         if(idx == 16)
            break;
         if(idx == 5) /* by pass bad block indication */
            continue;
      }
      else
      {
         if( (idx == 0) || (idx == 1) ) /* by pass bad block indication */
            continue;
      }
      if(byte_ptr[idx] != (idx&0xFF))
         while(1);
   }
   
   while(1);
}
#endif

#endif /* __FOTA_DM__ */

//#define X_DOWNLOAD_NAND_TEST
#define TESTBLOCK	0x100

#if defined(X_DOWNLOAD_NAND_TEST)
kal_uint32 TBuffer[2112/4];
#endif // defined(X_DOWNLOAD_NAND_TEST)

/**********************************************************
Description : NFIReconfigure
Input       : NO
Output      : NO
***********************************************************/
void NFIReconfigure2(void)
{
#if ( defined(__NAND_FDM_50__) && defined(__NFI_VERSION2__) )
    kal_int32 NFBStatus = -1;
    NFBStatus = DAL_init();
    if ( NFBStatus != FS_NO_ERROR )
    {
        dbg_print("[NFIReconfigure] DAL_init fail\n");
        while (1);
    }
    


    #if defined(X_DOWNLOAD_NAND_TEST)
	/*
	NFB_ErasePhysicalBlock(TESTBLOCK+1);
	NFB_MarkBadBlock(TESTBLOCK+1);
	NFB_ProgramPhysicalPage(TESTBLOCK, 0, 0);
	NFB_ProgramPhysicalPageWithSpare(TESTBLOCK, 0, 0, 0);
	NFB_ReadPhysicalPageWithSpare(TESTBLOCK, 0, 0);
	NFB_ReadPhysicalPage(TESTBLOCK, 0, 0);
	*/
	{
    	kal_uint32 PageOffset, Count;
		kal_uint8 *TestBuffer = (kal_uint8 *)TBuffer;
		kal_uint32 TestCount = 0;
    FLASH_INFO F_info;
		DAL_FDM_Flash_Info_Init (&F_info, 0);    
		while (TestCount<2) {
			if (NFB_ErasePhysicalBlock(TESTBLOCK+1, KAL_TRUE)!=ERROR_NFB_BAD_BLOCK) {
				if (NFB_MarkBadBlock(TESTBLOCK+1, KAL_TRUE)!=ERROR_NFB_SUCCESS) {
					while(1);
				}
				if (NFB_ErasePhysicalBlock(TESTBLOCK+1, KAL_TRUE)!=ERROR_NFB_BAD_BLOCK) {
					while(1);
				}    	
			}    	
			
			if ( (NFB_ErasePhysicalBlock(TESTBLOCK, KAL_TRUE)!=ERROR_NFB_SUCCESS) ||
				 (NFB_ErasePhysicalBlock(TESTBLOCK, KAL_FALSE)!=ERROR_NFB_SUCCESS) ){
				while(1);
			}
			for (PageOffset=0; PageOffset<F_info.PageNumPerSection; PageOffset++) {
				for (Count=0; Count<(F_info.SectorNumPerPage*528); Count++) {
					if ((Count>=(F_info.SectorNumPerPage*512)) && (((Count&0x0f)<2) || ((Count&0x0f)>4))) {
						TestBuffer[Count+PageOffset] = (kal_uint8)0xff;
					} else {
						TestBuffer[Count] = (kal_uint8)(Count+PageOffset);
					}
				}
				
		  		if(NFB_ProgramPhysicalPageWithSpare(TESTBLOCK, PageOffset, TestBuffer, &(TestBuffer[F_info.SectorNumPerPage*512]), TestCount ? KAL_TRUE : KAL_FALSE)<0) {
					while(1);
		  		}
				for (Count=0; Count<(F_info.SectorNumPerPage*528); Count++) {
					TestBuffer[Count] = (kal_uint8)(0);
				}	
				if(NFB_ReadPhysicalPageWithSpare(TESTBLOCK, PageOffset, TestBuffer)<0) {
					while(1);
				}			
				for (Count=0; Count<(F_info.SectorNumPerPage*528); Count++) {
					if ((Count>=(F_info.SectorNumPerPage*512)) && ((Count&0x0f)>=8)) {
						continue;
					}
					if ((Count>=(F_info.SectorNumPerPage*512)) && (((Count&0x0f)<2) || ((Count&0x0f)>4))) {
						continue;
					}				
					if (TestBuffer[Count] != (kal_uint8)(Count+PageOffset)) {
						while(1);
					}		
				}
				
			}

			for (PageOffset=0; PageOffset<F_info.PageNumPerSection; PageOffset++) {
				if(NFB_ReadPhysicalPageWithSpare(TESTBLOCK, PageOffset, TestBuffer)<0) {
					while(1);
				}
				for (Count=0; Count<(F_info.SectorNumPerPage*528); Count++) {
					if ((Count>=(F_info.SectorNumPerPage*512)) && ((Count&0x0f)>=8)) {
						continue;
					}
					if ((Count>=(F_info.SectorNumPerPage*512)) && (((Count&0x0f)<2) || ((Count&0x0f)>4))) {
						continue;
					}					
					if (TestBuffer[Count] != (kal_uint8)(Count+PageOffset)) {
						while(1);
					}		
				}
			}

	  		for (PageOffset=0; PageOffset<F_info.PageNumPerSection; PageOffset++) {
				if(NFB_ReadPhysicalPage(TESTBLOCK, PageOffset, TestBuffer)<0) {
					while(1);
				}
				for (Count=0; Count<(F_info.SectorNumPerPage*512/4); Count++) {
					if (TestBuffer[Count] != (kal_uint8)(Count+PageOffset)) {
						while(1);
					}		
				}
			} 

			for (PageOffset=0; PageOffset<F_info.PageNumPerSection; PageOffset++) {
				if(NFB_ReadPhysicalPageWithSpare_NoTT(TESTBLOCK, PageOffset, TestBuffer, TestBuffer+(F_info.SectorNumPerPage*512))<0) {
					while(1);
				}
				for (Count=0; Count<(F_info.SectorNumPerPage*528); Count++) {
					if ((Count>=(F_info.SectorNumPerPage*512)) && ((Count&0x0f)>=8)) {
						continue;
					}
					if ((Count>=(F_info.SectorNumPerPage*512)) && (((Count&0x0f)<2) || ((Count&0x0f)>4))) {
						continue;
					}					
					if (TestBuffer[Count] != (kal_uint8)(Count+PageOffset)) {
						while(1);
					}		
				}
			}
			TestCount++;
		}
  		
    }
    #endif // defined(X_DOWNLOAD_NAND_TEST)
#endif    
}



#endif /* __EXT_BOOTLOADER__ */

#ifdef BIT_ERROR_TEST


void EmulateBitError(kal_uint32 *destination, kal_uint32 *parity, kal_uint16 addr_no, kal_uint32 addr1, kal_uint16 addr2, kal_uint16 pageSize)
{
   kal_uint8 BitNo, status, Sector, Mask;
   kal_uint32 Offset, MagicNum;
   kal_bool EmulatedBitError;
   kal_uint8 *Ptr = (kal_uint8 *)destination;


	status = NFI_PageRead(destination, parity, pageSize, addr_no, addr1, addr2, pageSize, KAL_TRUE, KAL_FALSE);
    #if !defined (__NFI_VERSION2__) /*In case of __NFI_VERSION2__, ECC correction is done at NFI_PageRead*/
   status = NFI_ParityCheck(destination, parity, addr_no, addr1, addr2, \
                        pageSize, BLHeader.NFIinfo.IOInterface, \
                        BLHeader.NFIinfo.pageSize*BLHeader.pagesPerBlock);                          
    #endif
   if (status != NFI_SUCCESS) {
      dbg_print(" Original data has error. No need to emulate bit error. status=%x \n\r", status);
      return;
   }

   for(Sector=0; Sector<(pageSize/0x200); Sector++) {
      EmulatedBitError = KAL_FALSE;
      if(pageSize < 1024) {
         MagicNum = (addr1>>16) ^ (addr1>>8);
      } else {
         MagicNum = (addr1>>16) ^ (addr1>>24);
      }
      for(Offset=(MagicNum & 0x1ff); Offset<0x200; Offset++) {
         Mask = 0x01;
         for(BitNo=0; BitNo<8; BitNo++) {
            if(Ptr[Sector*0x200+Offset] & Mask) {
               dbg_print("***[Emulate] Offset = %x, Original data = %x", addr1+(Sector*0x200)+Offset, Ptr[Sector*0x200+Offset]);
               Ptr[Sector*0x200+Offset] = Ptr[Sector*0x200+Offset] & (~Mask);
               dbg_print(" New data  = %x \n\r", Ptr[Sector*0x200+Offset]);
               EmulatedBitError = KAL_TRUE;
               break;
            }
            Mask = Mask << 1;
         }
         if(EmulatedBitError==KAL_TRUE) {
            break;
         }
      }
   }

    #if defined (__NFI_VERSION2__)
    *NFI_CON=0x0;
    *NFI_OPCON = OPCON_RESET;
    while (*NFI_PSTA != 0);
    #else
    *NFI_OPCON = 0x00;   
    *NFI_CON = 0x00;        
    *NFI_FIFOCON = 0x30;                  // Flushing FIFO
    #endif
    if (pageSize<1024)
    {
        *NFI_CMD = RD_1ST_CMD;             // Set poiner to 0.
        while (*NFI_PSTA & STATUS_CMD);
        #if defined (__NFI_VERSION2__)
        *NFI_CON=0x0;
        *NFI_OPCON = OPCON_RESET;
        while (*NFI_PSTA != 0);
        #else
        *NFI_OPCON = 0;   
        *NFI_FIFOCON = RESET;
        #endif
    }
   *NFI_CMD = INPUT_DATA_CMD;                  // Issue data input command
   while (*NFI_PSTA & STATUS_CMD);
   *NFI_ADDRL = addr1;
   if (addr_no == 5)
       *NFI_ADDRM = addr2;
   *NFI_ADDNOB = addr_no;  // no. of bytes for address
   while (*NFI_PSTA & STATUS_ADDR);

   *NFI_OPCON = BURST_WR;                      // set burst write

   *NFI_CON = DMA_WR_EN;

    #if defined (__NFI_VERSION2__)
    *(volatile kal_uint32 *)(DMA_base+0x0118)   = 0x0000;                       //(DMA1_START)   
    *(volatile kal_uint32 *)(DMA_base+0x0100)   = (kal_uint32)destination;      //(DMA1_SRC)     
    *(volatile kal_uint32 *)(DMA_base+0x0104)   = (kal_uint32)NFI_DATAW;        //(DMA1_DST)     
    *(volatile kal_uint32 *)(DMA_base+0x0110)   = pageSize>>2;                  //(DMA1_COUNT)   
    *(volatile kal_uint32 *)(DMA_base+0x0114)   = 0x01000016;                   //(DMA1_CONTRL)  
    *(volatile kal_uint32 *)(DMA_base+0x0128)   = 0;                            //(DMA1_LIMITER) 
    *(volatile kal_uint32 *)(DMA_base+0x0118)   = 0x8000;                       //(DMA1_START)   

    while ( ((*(volatile kal_uint32 *)(DMA_base+0x0000)&0x03)==0x01) );         //(DMA_GLBSTS) 
    #else
	*(volatile kal_uint32 *)(DMA_base+0x0118) = 0x0000;                              //(DMA1_START)    
	*(volatile kal_uint32 *)(DMA_base+0x0100) = (kal_uint32)destination;             //(DMA1_SRC)      
	*(volatile kal_uint32 *)(DMA_base+0x0104) = (kal_uint32)NFI_DATAW;               //(DMA1_DST)      
	*(volatile kal_uint32 *)(DMA_base+0x0110) = pageSize>>2;                         //(DMA1_COUNT)    
	*(volatile kal_uint32 *)(DMA_base+0x0114) = 0x01000016;                          //(DMA1_CONTRL)   
	*(volatile kal_uint32 *)(DMA_base+0x0128) = 0;                                   //(DMA1_LIMITER)  
	*(volatile kal_uint32 *)(DMA_base+0x0118) = 0x8000;                              //(DMA1_START)  

    while ( ((*(volatile kal_uint32 *)(DMA_base+0x0000)&0x03)==0x01) );              //(DMA_GLBSTS) 
    #endif

   *NFI_CMD = PROG_DATA_CMD;       // Issue program command
   while (*NFI_PSTA & STATUS_CMD);

   while (*NFI_PSTA & STATUS_BUSY);

    #if defined (__NFI_VERSION2__)
    *NFI_OPCON = OPCON_RESET;
    while (*NFI_PSTA != 0);
    #else
   *NFI_OPCON = 0;
    #endif

   return;
} 

#endif


/**********************************************************
Description : NFI_SpareRead
Input       : .......
Output      : _RET_CODE
Remark      : Must be spare area aligned
***********************************************************/
#if ( defined(__FOTA_DM__) && defined(__NFI_VERSION2__) )&& !defined(__MINI_BOOTLOADER__)
#if defined(__NAND_FDM_50__)
// Notice : Here the PageBuffer is the buffer for main area +  spare area. 
_RET_CODE NFI_SpareRead(kal_uint32 *PageBuffer, kal_uint16 addr_no, kal_uint32 addr1, \
                        kal_uint16 addr2, kal_uint16 pageSize, kal_uint16 IO)
{
    kal_uint32 block;
    kal_uint32 page;
    kal_int32 retVal;
    if ( BLHeader.NFIinfo.addressCycle > 4)
    {
        block = ((addr2<<16)|(addr1>>(BLHeader.NFIinfo.pageShift)))/BLHeader.pagesPerBlock;
        page = ((addr2<<16)|(addr1>>(BLHeader.NFIinfo.pageShift)))%BLHeader.pagesPerBlock;
    }        
    else
    {
        block = (addr1>>(BLHeader.NFIinfo.pageShift))/BLHeader.pagesPerBlock;
        page = (addr1>>(BLHeader.NFIinfo.pageShift))%BLHeader.pagesPerBlock;
    }

	retVal = NFB_ReadPhysicalPageWithSpare(block, page, (kal_uint8 *)PageBuffer);

    if (retVal >= 0)
        return NFI_SUCCESS;
    else
        return NFI_GENERAL_ERR;
}

#else // defined(__NAND_FDM_50__)

/**********************************************************
Description : NFI_SpareRead
Input       : .......
Output      : _RET_CODE
Remark      : Must be spare area aligned
***********************************************************/
_RET_CODE NFI_SpareRead(kal_uint32 *spare, kal_uint16 addr_no, kal_uint32 addr1, \
                        kal_uint16 addr2, kal_uint16 pageSize, kal_uint16 IO)
{
   kal_int32 timeout=0xffff, size, i;
     
    *NFI_CON=0x0;
    *NFI_OPCON = OPCON_RESET;
    while (*NFI_PSTA != 0);

   if ( pageSize<1024 )
   {
      size = 16;
      *NFI_CON = SW_PROGSPARE_EN;        // program/read spare area enable
      *NFI_CMD = RD_SPARE_CMD;           // reading spare command      
      while (*NFI_PSTA & STATUS_CMD);     
      *NFI_ADDRL = (addr1&0xffffff00);    
      if ( addr_no>4 )
         *NFI_ADDRM = addr2;
      *NFI_ADDNOB = addr_no;             // number of bytes for address
      while (*NFI_PSTA & STATUS_ADDR);    
   }
   else
   {
      size = 64;
      *NFI_CON = SW_PROGSPARE_EN;        // program spare area enable
      *NFI_CMD = RD_1ST_CMD;             // read spare command
      while (*NFI_PSTA & STATUS_CMD);     
      if ( IO==IO_16BITS )
      {
         addr1 = addr1 + (2048>>1);
      }
      else 
      {
         addr1 = addr1 + 2048;
      }
      *NFI_ADDRL = addr1;
      if ( addr_no>4 )
         *NFI_ADDRM = addr2;
      *NFI_ADDNOB = addr_no;             // number of bytes for address
      while (*NFI_PSTA & STATUS_ADDR);      
      *NFI_CMD = RD_2ND_CYCLE_CMD;            
      while (*NFI_PSTA & STATUS_CMD);      
   }      

   *NFI_OPCON = BURST_RD | NOB_DWORD;     // set burst read   

   while( *NFI_PSTA & STATUS_DATAR );

   NFI_Wait_Ready(timeout);

   if ( timeout==0 )
     return NFI_READ_SPARE_TIMEOUT;

   for (i=0; i<(size/4); i++)
   {
      timeout = 0xffff;
      while ((*NFI_FIFOSTA & RD_EMPTY_MASK) && (--timeout));
      if(timeout==0)
      {
         break;
      }
      spare[i] = *NFI_DATAR;
   }   

    *NFI_OPCON = OPCON_RESET;
    while (*NFI_PSTA != 0);

   if ( timeout > 0)
      return NFI_SUCCESS;
   else 
      return DMA_TRANSFER_SPARE_TIMEOUT;
}
#endif //  defined(__NAND_FDM_50__)
#endif // ( defined(__FOTA_DM__) && defined(__NFI_VERSION2__) )

#if !defined (__NFI_VERSION2__) /* NFI_ParityCheck is for ECC decode and correct in !(__NFI_VERSION2__) case*/

_RET_CODE NFI_SpareRead(kal_uint32 *spare, kal_uint16 addr_no, kal_uint32 addr1, \
                        kal_uint16 addr2, kal_uint16 pageSize, kal_uint16 IO)
{
   kal_int32 timeout=0xffff, size, i;
     
   *NFI_OPCON = 0x00;
   *NFI_CON = 0x00;        
   *NFI_FIFOCON = FIFO_FLUSH | RESET;                  // Flushing FIFO

   if ( pageSize<1024 )
   {
      size = 16;
      *NFI_CON = SW_PROGSPARE_EN;        // program/read spare area enable
      *NFI_CMD = RD_SPARE_CMD;           // reading spare command      
      while (*NFI_PSTA & STATUS_CMD);     
      *NFI_ADDRL = (addr1&0xffffff00);    
       if ( addr_no>4 )
	  *NFI_ADDRM = addr2;
      *NFI_ADDNOB = addr_no;             // number of bytes for address
      while (*NFI_PSTA & STATUS_ADDR);    
   }
   else
   {
      size = 64;
      *NFI_CON = SW_PROGSPARE_EN;        // program spare area enable
      *NFI_CMD = RD_1ST_CMD;             // read spare command
      while (*NFI_PSTA & STATUS_CMD);     
      if ( IO==IO_16BITS )
      {
         addr1 = addr1 + (2048>>1);
      }
      else 
      {
         addr1 = addr1 + 2048;
      }
      *NFI_ADDRL = addr1;
      if ( addr_no>4 )
         *NFI_ADDRM = addr2;
      *NFI_ADDNOB = addr_no;             // number of bytes for address
      while (*NFI_PSTA & STATUS_ADDR);      
      *NFI_CMD = RD_2ND_CYCLE_CMD;            
      while (*NFI_PSTA & STATUS_CMD);      
   }      

   //   *NFI_OPCON = BURST_RD | NOB_WORD;     // set burst read   
   *NFI_OPCON = BURST_RD | NOB_DWORD;     // set burst read   

   while( *NFI_PSTA & STATUS_DATAR );

   NFI_Wait_Ready(timeout);

   if ( timeout==0 )
     return NFI_READ_SPARE_TIMEOUT;

   for (i=0; i<(size/4); i++)
   {
      while ((*NFI_FIFOCON & RD_EMPTY_MASK));
      spare[i] = *NFI_DATAR;
   }   

/*   dbg_print("Spare area = ");
   for(i=0; i<(size/4); i++) {
        dbg_print("%x ", spare[i]);
   }
   dbg_print("\n\r");*/


   //   while (*NFI_PSTA & STATUS_DATAR);
   // Caution: This line must not omitted!
   *NFI_OPCON = 0x0;
   while (*NFI_PSTA & STATUS_BUSY);   

   if ( timeout > 0)
      return NFI_SUCCESS;
   else 
      return DMA_TRANSFER_SPARE_TIMEOUT;
   
}

/**********************************************************
Description : NUTL_ECC_Correction
Input       : .......
Output      : _RET_CODE
***********************************************************/            
_RET_CODE  NUTL_ECC_Correction(kal_uint32 *dataPtr, kal_uint32 *parityPtr, kal_uint32 *sparePtr, \
                               kal_uint16 pageSize, kal_uint32 blockSize)   
{
   kal_uint8   update_data;
   kal_uint32  i;
   kal_uint32  error_bit_address;
   kal_uint32  error_bit_offset;
   kal_uint8   *p_data8 = (kal_uint8 *)dataPtr;      
   kal_uint32  ecc_parity_from_spare[5] = {0,0,0,0,0};   
   kal_uint32  *ecc_parity_from_reg = parityPtr;
   UnionData_U   xor_ecc_parity[4];
   _RET_CODE   status = NFI_SUCCESS; /*MAUI_00741480*/
   

   if ( pageSize==512 )
   {
      ecc_parity_from_spare[0] = *(sparePtr + 2);
   }
   else
   {
      ecc_parity_from_spare[0] = *(sparePtr + 11);
      ecc_parity_from_spare[1] = *(sparePtr + 12);
      ecc_parity_from_spare[2] = *(sparePtr + 13);
      ecc_parity_from_spare[3] = *(sparePtr + 14);
   }
   
   // XOR two ECC parity bit strings 
   // ecc_parity_from_reg[4]: current ECC parity generated by reading whole page 
   // ecc_parity_from_spare[4]: original ECC parity stored in spare area 
   xor_ecc_parity[0].d32 = (ecc_parity_from_reg[0]^ecc_parity_from_spare[0])&0x0FFF0FFF;
   xor_ecc_parity[1].d32 = (ecc_parity_from_reg[1]^ecc_parity_from_spare[1])&0x0FFF0FFF;
   xor_ecc_parity[2].d32 = (ecc_parity_from_reg[2]^ecc_parity_from_spare[2])&0x0FFF0FFF;
   xor_ecc_parity[3].d32 = (ecc_parity_from_reg[3]^ecc_parity_from_spare[3])&0x0FFF0FFF;

   // compare ECC parity between reg and spare 
   for(i=0; i<(pageSize/0x200); i++) 
   {
      if( 0 != xor_ecc_parity[i].d32 ) 
      {
         if( 0x0FFF == ((xor_ecc_parity[i].d16[0]^xor_ecc_parity[i].d16[1])&0x0FFF) ) 
         {
            // one-bit correctable error 
            error_bit_address = xor_ecc_parity[i].d16[1]&(~xor_ecc_parity[i].d16[0]);
            error_bit_offset = 0x200*i + (error_bit_address>>3);
            update_data = p_data8[error_bit_offset];
            update_data = update_data^(1<<(kal_uint8)(error_bit_address&0x0007));
#ifdef BIT_ERROR_TEST
            dbg_print(" ECC error address=%x error bit=%x Original=%x corrected data=%x \n\r", 
               error_bit_offset, error_bit_address & 0x07, p_data8[error_bit_offset], update_data);            
#endif
            p_data8[error_bit_offset] = update_data;

            if(status==NFI_SUCCESS) {
               status = NFI_ECC_1BIT_CORRECT;
            }
         } 
         else 
         {
            kal_uint32 iIndex=0,iEccsum=0;

            for(iIndex = 0; iIndex < 12; iIndex++)
            {
               iEccsum += ((xor_ecc_parity[i].d16[0] >> iIndex) & 0x01);
               iEccsum += ((xor_ecc_parity[i].d16[1] >> iIndex) & 0x01);
            }
            if(iEccsum ==1)
            {
               // ECC code error.
               dbg_print(" ECC code error... \n\r");
               continue;
            }

/*            dbg_print(" ECC error ... \n\r");
            dbg_print(" Register %x \n\r", ecc_parity_from_reg[i]);
            dbg_print(" Spare %x \n\r", ecc_parity_from_spare[i]);*/
            if(status!=NFI_ECC_2BITS_ERR) {
               status = NFI_ECC_2BITS_ERR;
            }
         }
      }
   }

   return status;
}

/**********************************************************
Description : NFI_ParityCheck
Input       : .......
Output      : _RET_CODE
Remark      : Must be page alignment.
***********************************************************/
_RET_CODE NFI_ParityCheck(kal_uint32 *destination, kal_uint32 *parity, kal_uint16 addr_no, \
                          kal_uint32 addr1, kal_uint16 addr2, kal_uint16 pageSize, kal_uint16 IO, \
                          kal_uint32 blockSize)
{
   _RET_CODE  status;
   kal_uint32 spare[64>>2];
   
   status = NFI_SpareRead(&spare[0], addr_no, addr1, addr2, pageSize, IO);
   
   if ( status!=NFI_SUCCESS )
      return status;
  
   if ( pageSize<1024 )
      status = NUTL_ECC_Correction(destination, parity, &spare[0], 512, blockSize);
   else
      status = NUTL_ECC_Correction(destination, parity, &spare[0], 2048, blockSize);
   
   return status;
}
#endif /*!defined (__NFI_VERSION2__)*/

void NAND_Reset()
{
#if defined(NAND_SUPPORT)
	kal_uint32 Delay;

    *NFI_CMD = RESET_CMD;
    while (*NFI_PSTA & STATUS_CMD);
    // 200ns delay maximum.
    for (Delay=0; Delay<COUNTER_200nS; Delay++){
			#if defined(__MTK_TARGET__)
				#if defined(__ARMCC_VERSION)
					__asm{nop};
				#elif defined(__GNUC__) 
					__asm__("nop");
				#endif /* __RVCT__ , __GNUC__ */ 
			#endif /* __MTK_TARGET__ */
    }

    while (*NFI_PSTA & STATUS_BUSY);
#endif    
}
void NFI_ReadID(kal_uint32 id_num, kal_uint8* id_data)
{
    kal_uint32 ID[2];
    kal_uint32 Backup_NFI_PAGEFMT;
#if (defined(MT6236) || defined(MT6236B))&& defined(__MINI_BOOTLOADER__)
   NFIDriverInit();
#endif        
    Backup_NFI_PAGEFMT = *NFI_PAGEFMT; 
    *NFI_PAGEFMT = PAGEFMT_512_8BIT;      
#if defined(__NFI_VERSION2__)
      *NFI_CON=0x0;
      *NFI_OPCON = OPCON_RESET;
      while( (*NFI_PSTA& (~0x0300) ) ); /*Except device busy status*/
#else
      *NFI_FIFOCON = RESET;
      *NFI_OPCON = 0;
      *NFI_CON = 0;
#endif /*__NFI_VERSION2__*/
      NAND_Reset();
#if defined(__NFI_VERSION2__)
      *NFI_CON=0x0;
      *NFI_OPCON = OPCON_RESET;
      while( (*NFI_PSTA& (~0x0300) ) ); /*Except device busy status*/
#else
      *NFI_FIFOCON = RESET;
      *NFI_OPCON = 0;
      *NFI_CON = 0;
#endif /*__NFI_VERSION2__*/


   *NFI_CMD = RD_ID_CMD;
   while (*NFI_PSTA & STATUS_CMD);
   *NFI_ADDRL = 0;
   *NFI_ADDNOB = 1;
   while (*NFI_PSTA & STATUS_ADDR);

   *NFI_OPCON = (NOB_DWORD | SINGLE_RD);
   while (*NFI_PSTA & STATUS_DATAR);
#if defined(__NFI_VERSION2__)
   while (FIFO_RD_REMAIN (*NFI_FIFOSTA ) < 4);
#endif

   ID[0] = *NFI_DATAR; /*First 4 bytes*/

#if defined(__NFI_VERSION2__)
      *NFI_CON=0x0;
      *NFI_OPCON = OPCON_RESET;
      while( (*NFI_PSTA& (~0x0300) ) ); /*Except device busy status*/
#else
      *NFI_FIFOCON = RESET;
      *NFI_OPCON = 0;
      *NFI_CON = 0;
#endif /*__NFI_VERSION2__*/

   *NFI_OPCON = (NOB_DWORD | SINGLE_RD);
   while (*NFI_PSTA & STATUS_DATAR);
#if defined(__NFI_VERSION2__)
   while (FIFO_RD_REMAIN (*NFI_FIFOSTA ) < 4);
#endif
   ID[1] = *NFI_DATAR; /*Second 4 bytes*/
   id_data[0] = (kal_uint8)ID[0];
   id_data[1] = (kal_uint8)(ID[0]>>8);
   id_data[2] = (kal_uint8)(ID[0]>>16);
   id_data[3] = (kal_uint8)(ID[0]>>24);
   id_data[4] = (kal_uint8)ID[1];
   id_data[5] = (kal_uint8)(ID[1]>>8);
   id_data[6] = (kal_uint8)(ID[1]>>16);
   id_data[7] = (kal_uint8)(ID[1]>>24);
   *NFI_PAGEFMT = Backup_NFI_PAGEFMT;		     
   
}

void NFIReconfigure(void)
{
#if defined (__NFI_VERSION2__)
    *NFI_CON=0x0;
    *NFI_OPCON = OPCON_RESET;
    while (*NFI_PSTA != 0);
	// Force 256Bytes ECC block size for both 2KB and 512B NAND-flash
    //*NFI_PAGEFMT &= ~(0x70);
	*NFI_PAGEFMT |= 0x10;
	*NFI_ACCCON = 0x20023333;//0x7007ffff;
	NAND_Reset();
    *NFI_CON=0x0;
    *NFI_OPCON = OPCON_RESET;
    while (*NFI_PSTA != 0);	
#else
   *NFI_FIFOCON = 0x30;                  // Flushing FIFO
   *NFI_OPCON = 0x00;
   *NFI_CON = 0x00;     
   // Force 512Bytes ECC block size for both 2KB and 512B NAND-flash
   *NFI_PAGEFMT |= 0x20;
   *NFI_ACCCON = 0x7FF;
	NAND_Reset();
   *NFI_FIFOCON = 0x30;                  // Flushing FIFO
   *NFI_OPCON = 0x00;
   *NFI_CON = 0x00;   
#endif
}

/**********************************************************
  Name : NFI_PhyPageRead
  Description :
	Addr1 and Addr2 in this function are real physical page. 
	The address had no need to pass to DAL to translate.
***********************************************************/
_RET_CODE NFI_PhyPageRead(kal_uint32 *destination, kal_uint32 *parity, kal_uint32 length, \
                       kal_uint16 addr_no, kal_uint32 addr1, kal_uint16 addr2, kal_uint16 pageSize, \
                       kal_bool ECC, kal_bool continous)
{
   kal_int32   timeout=0xffff;
   kal_uint32  *parity_ptr = parity;
   _RET_CODE   retStatus =  NFI_SUCCESS;
   
#if defined (__NFI_VERSION2__)
    *NFI_CON=0x0;
    *NFI_OPCON = OPCON_RESET;
    while (*NFI_PSTA != 0);
#else
   *NFI_OPCON = 0x00;   
   *NFI_CON = 0x00;        
   *NFI_FIFOCON = FIFO_FLUSH | RESET;                  // Flushing FIFO
#endif
   if ( pageSize<1024 )
   {
      *NFI_CMD = RD_1ST_CMD;             // read command 
      while (*NFI_PSTA & STATUS_CMD);      
      *NFI_ADDRL = addr1;
      if ( addr_no>4 )
         *NFI_ADDRM = addr2;
      *NFI_ADDNOB = addr_no;              // number of bytes for address      
      while (*NFI_PSTA & STATUS_ADDR);      
   }
   else
   {
      *NFI_CMD = RD_1ST_CMD;              // Issue data input command
      while (*NFI_PSTA & STATUS_CMD);      
      *NFI_ADDRL = addr1;
      if ( addr_no>4 )
         *NFI_ADDRM = addr2;
      *NFI_ADDNOB = addr_no;              // no. of bytes for address   
      while (*NFI_PSTA & STATUS_ADDR);      
      *NFI_CMD = RD_2ND_CYCLE_CMD;
      while (*NFI_PSTA & STATUS_CMD);      
   }
   while( *NFI_PSTA & STATUS_DATAR );
   
   NFI_Wait_Ready(timeout);
   
   if ( timeout==0 )
      return NFI_READ_DATA_TIMEOUT;

   // Activating DMA transfer
   if ( ECC )
   {
       #if defined (__NFI_VERSION2__)
       *NFI_CON = (DMA_RD_EN |SW_PROGSPARE_EN| MAIN_ECC_EN|SPARE_ECC_EN|AUTO_ECC_DEC);
       #else        
      *NFI_CON = (DMA_RD_EN | AUTOECC_DEC_EN);
       #endif
   }
   else
      *NFI_CON = DMA_RD_EN;
   
   *NFI_OPCON = BURST_RD;    // set burst read


    #if defined (__NFI_VERSION2__)
    *(volatile kal_uint32 *)(DMA_base+0x0118)   = 0x0000;                       //(DMA1_START)  
    *(volatile kal_uint32 *)(DMA_base+0x0100)   = (kal_uint32)NFI_DATAR;        //(DMA1_SRC)    
    *(volatile kal_uint32 *)(DMA_base+0x0104)   = (kal_uint32)destination;      //(DMA1_DST)    
    *(volatile kal_uint32 *)(DMA_base+0x0110)   = length>>2;                    //(DMA1_COUNT)  
    *(volatile kal_uint32 *)(DMA_base+0x0114)   = 0x00f4001a;                   //(DMA1_CONTRL) 
    *(volatile kal_uint32 *)(DMA_base+0x0128)   = 0;                            //(DMA1_LIMITER)
    *(volatile kal_uint32 *)(DMA_base+0x0118)   = 0x8000;                       //(DMA1_START)  
   
   timeout = 0xffff;
    while ( ((*(volatile kal_uint32 *)(DMA_base+0x0000)&0x03)==0x01) && (--timeout) );//(DMA_GLBSTS) 
    #else                                                                                       
	*(volatile kal_uint32 *)(DMA_base+0x0118) = 0x0000;                              //(DMA1_START)  
	*(volatile kal_uint32 *)(DMA_base+0x0100) = (kal_uint32)NFI_DATAR;               //(DMA1_SRC)    
	*(volatile kal_uint32 *)(DMA_base+0x0104) = (kal_uint32)destination;             //(DMA1_DST)    
	*(volatile kal_uint32 *)(DMA_base+0x0110) = length>>2;                           //(DMA1_COUNT)  
	*(volatile kal_uint32 *)(DMA_base+0x0114) = 0x00f4001a;                          //(DMA1_CONTRL) 
	*(volatile kal_uint32 *)(DMA_base+0x0128) = 0;                                   //(DMA1_LIMITER)
	*(volatile kal_uint32 *)(DMA_base+0x0118) = 0x8000;                              //(DMA1_START)  
   
    timeout = 0xffff;
    while ( ((*(volatile kal_uint32 *)(DMA_base+0x0000)&0x03)==0x01) && (--timeout) );//(DMA_GLBSTS) 
    #endif
   
   if ( timeout==0 )
      return DMA_TRANSFER_DATA_TIMEOUT;
         
//   while (!(*NFI_FIFOCON & RD_EMPTY_MASK) || (*NFI_PSTA & STATUS_DATAR));
   while (*NFI_PSTA & STATUS_BUSY);   

#if defined (__NFI_VERSION2__) /*ECC correction processes at __NFI_VERSION2__ case*/
   if ( ECC )
   {
       kal_uint32 spare[1];
       kal_uint32 Error;
       kal_uint16 i;

       if ((*NFI_PAGEFMT & 0x70) != 0x10) /*Should be ECC_BLKSIZE_256*/
           return NFI_ZERO_POINTER;

       if ( pageSize == 2048)
       {
           /*read the remain content and get ECC value*/
           for ( i = (length>>2) ; i < ((2048+64)>>2); i ++)
           {
               while(FIFO_RD_REMAIN (*NFI_FIFOSTA ) < 4);
               if (i<(2048>>2)) {
                 spare[0] = *NFI_DATAR; /*Hardware ECC decode and don't care content*/
               } else {
	             parity_ptr[i-(2048>>2)] = *NFI_DATAR;
               }
           }
           Error = *NFI_ERRDET;
           if ( Error !=0)
           {
               if ( (Error & (ERRDET_PEBLK0|ERRDET_PEBLK1|ERRDET_PEBLK2|ERRDET_PEBLK3|
                              ERRDET_PEBLK4|ERRDET_PEBLK5|ERRDET_PEBLK6|ERRDET_PEBLK7)) != 0)
               {   /*main area has recoverable error*/
                   kal_uint32 Syndrome;
                   kal_uint16 UpdateAddr;
                   kal_uint8  UpdateData;
                   for(i=0;i<8;i++) /*8 ECC blocks*/
                   {
                      if((Error>>(i+16))&1) /*recoverable range*/
                      {
                         UpdateAddr = (*(volatile kal_uint16*)((kal_uint32)NFI_SYM0_ADDR + (4*i)) ); /*NFI_SYM0_ADDR~NFI_SYM7_ADDR*/
                         Syndrome = (*(volatile kal_uint32*)((kal_uint32)NFI_SYM0_DAT + (4*i)) );    /*NFI_SYM0_DAT~NFI_SYM7_DAT*/
                         UpdateData = ((Syndrome >> ((UpdateAddr & 0x03) << 3)) & 0xFF);
                         ((kal_uint8*)destination)[UpdateAddr] ^= UpdateData; 
                         #ifdef BL_DEBUG
                         dbg_print("1 bit err at Block:%d page:%d offset:%d, bit:%d, fixed value:%x\n\r", 
                                   ((addr1>>16)|(addr2<<16))/64,(addr1>>16)|(addr2<<16)%64,UpdateAddr,UpdateData,((kal_uint8*)destination)[UpdateAddr] );				
                         #endif
                      }
                   }
                   retStatus = NFI_ECC_1BIT_CORRECT;
               }

               if ( (Error & (ERRDET_EBLK0|ERRDET_EBLK1|ERRDET_EBLK2|ERRDET_EBLK3|
                              ERRDET_EBLK4|ERRDET_EBLK5|ERRDET_EBLK6|ERRDET_EBLK7)) != 0)
               {   /*main area has unrecoverable error or ECC damaged*/
                   #ifdef BL_DEBUG
                   dbg_print("uncoverable err at Block:%d page:%d \n\r", 
                             ((addr1>>16)|(addr2<<16))/64,(addr1>>8)|(addr2<<24) );
                   #endif
                   retStatus = NFI_ECC_2BITS_ERR;
               }
           }
       }
       else /* pageSize == 512 */
       {
           /*read the remain content and get ECC value*/    
           for ( i = (length>>2) ; i < ((512+16)>>2); i ++)
           {
               while(FIFO_RD_REMAIN (*NFI_FIFOSTA ) < 4);
               if (i<(512>>2)) {
                       spare[0] = *NFI_DATAR; /*Hardware ECC decode and don't care content*/
               } else {
                   parity_ptr[i-(512>>2)] = *NFI_DATAR;
               }
           }
           Error = *NFI_ERRDET;
           if ( Error !=0)
           {
               if ( (Error & (ERRDET_PEBLK0|ERRDET_PEBLK1)) != 0)
               {    /*main area has recoverable error*/
                   kal_uint32 Syndrome;
                   kal_uint16 UpdateAddr;
                   kal_uint8  UpdateData;
                   for(i=0;i<2;i++) /*2 ECC blocks*/
                   {
                      if((Error>>(i+16))&1) /*recoverable range*/
                      {
                         UpdateAddr = (*(volatile kal_uint16*)((kal_uint32)NFI_SYM0_ADDR + (4*i)) ); /*NFI_SYM0_ADDR~NFI_SYM1_ADDR*/
                         Syndrome = (*(volatile kal_uint32*)((kal_uint32)NFI_SYM0_DAT + (4*i)) );    /*NFI_SYM0_DAT~NFI_SYM1_DAT*/
                         UpdateData = ((Syndrome >> ((UpdateAddr & 0x03) << 3)) & 0xFF);
                         ((kal_uint8*)destination)[UpdateAddr] ^= UpdateData; 
                         #ifdef BL_DEBUG
                         dbg_print("1 bit err at Block:%d page:%d offset:%d, bit:%d, fixed value:%x\n\r", 
                                   ((addr1>>8)|(addr2<<24))/32,(addr1>>8)|(addr2<<24)%32,UpdateAddr,UpdateData,((kal_uint8*)destination)[UpdateAddr] );				
                         #endif
                      }
                   }
                   retStatus = NFI_ECC_1BIT_CORRECT;
               }
               if( (Error & (ERRDET_EBLK0|ERRDET_EBLK1)) != 0)
               {   /*main area has uncoverable error*/
                   #ifdef BL_DEBUG
                   dbg_print("uncoverable err at Block:%d page:%d \n\r", 
                             ((addr1>>8)|(addr2<<24))/32,(addr1>>8)|(addr2<<24) );
                   #endif
                   retStatus = NFI_ECC_2BITS_ERR;
               }
           }
       }
   }
#else /*only ECC detection do at !(__NFI_VERSION2__) case*/
   if ( ECC )
   {
      if ( parity==NULL )
         return NFI_ZERO_POINTER;
       
      if ( pageSize<1024 )
      {
         while (*NFI_PAGECNTR !=1);
         //parity_ptr[0] = *NFI_PAR6;
         //parity_ptr[0] |= (*NFI_PAR7) << 16;         
         parity_ptr[0] = *NFI_PAR0;
         parity_ptr[0] |= (*NFI_PAR1) << 16;         
      }
      else
      {
         parity_ptr[0] = *NFI_PAR0;
         parity_ptr[0] |= (*NFI_PAR1) << 16;
         parity_ptr[1] = *NFI_PAR2;
         parity_ptr[1] |= (*NFI_PAR3) << 16;
         parity_ptr[2] = *NFI_PAR4;
         parity_ptr[2] |= (*NFI_PAR5) << 16;
         parity_ptr[3] = *NFI_PAR6;
         parity_ptr[3] |= (*NFI_PAR7) << 16;
      }         
   }
#endif
   
   // Caution: This line must not omitted!
#if defined (__NFI_VERSION2__)
   *NFI_OPCON = OPCON_RESET;
   while (*NFI_PSTA != 0);
#else
   *NFI_OPCON = 0x0;
#endif
   
   if ( timeout > 0)
	   return retStatus;
   else 
      return NFI_READ_DATA_TIMEOUT;
      
}

kal_int32 NFB_ReadPhysicalPageWithSpare_NoTT(kal_uint32 PhyBlock, kal_uint32 PhyPage, kal_uint32 *Data, kal_uint32 *Spare)
{
   	kal_uint32 addr1, addr2;

	PhyPage += (PhyBlock << (BLHeader.blockShift - PAGE_SHIFT));
	addr1 = (kal_uint32)(PhyPage << PAGE_SHIFT);
	addr2 = 0;
	if (BLHeader.NFIinfo.addressCycle>4) {
		// Seems only in 2KB page size case.
		addr2 = (kal_uint32)(PhyPage >> PAGE_SHIFT);
   	}	
   		
	return NFI_PhyPageRead(Data, Spare, BLHeader.NFIinfo.pageSize, BLHeader.NFIinfo.addressCycle, addr1, addr2, 
			BLHeader.NFIinfo.pageSize, KAL_TRUE, KAL_FALSE);
}

// Return value :
//	 0 - Good block.
//	-1 - Bad block
kal_int32 NFB_CheckGoodBlock_NoTT(NFI_MENU *input, kal_uint32 Block)
{
   	kal_uint32 addr1, addr2, PhyPage=0;
	kal_uint32 marking, i;

	PhyPage += (Block << (BLHeader.blockShift - PAGE_SHIFT));
	addr1 = (kal_uint32)(PhyPage << PAGE_SHIFT);
	addr2 = 0;
	if (BLHeader.NFIinfo.addressCycle>4) {
		// Seems only in 2KB page size case.
		addr2 = (kal_uint32)(PhyPage >> PAGE_SHIFT);
   	}	

	for (i=0; i<2; i++)
	{
	  // Read the bad block marking from the first page
	  marking = NFI_CheckGoodBlock(input, addr1, addr2);
	  if ( input->pageSize < 1024 ) {
		if ( FF_match_Table[marking & 0xff] < 7 ) {
			return -1;
		}
	  } else {
		if ( FF_match_Table[marking & 0xff] < 7) {
			return -1;
		}
		if (input->IOInterface == IO_16BITS) {
			if ( (FF_match_Table[(marking>>8) & 0xff]) < 7 ) {	
				return -1;
			}
		}
	  }
	  //if ( (marking!=0xff) && (marking!=0xffff) )
	  //   return KAL_FALSE;
	  addr1 = addr1 + (1<<input->pageShift);
	}
	return 0;
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#endif // !defined(__NFI_VERSION3__) && !defined(__NFI_VERSION3_1__)
#endif /* _NAND_FLASH_BOOTING_ || __NOR_FLASH_BOOTING__ */
