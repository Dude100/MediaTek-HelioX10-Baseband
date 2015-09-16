/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   dmdmsp_init.c
 *
 * Project:
 * --------
 *   
 *
 * Description:
 * ------------
 *   dmdsp init related function.
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
 ****************************************************************************/
#include "reg_base.h"
#include "kal_general_types.h"
#include "cp15.h"

#if defined(__DSP_FCORE4__)
#include "dmdsp_init.h"
#endif /* __DSP_FCORE4__ */

#if defined(__SV5_ENABLED__)
#include "br_GFH_file_info.h"
#endif

#if defined(__DSP_FCORE4__) && !defined(__UBL__)

/* Make sure there is a linker symbol we could use. */
#pragma arm section rwdata="DSP_DATA"
kal_int8 dsp_argv_string[] = "-abc -xyz";
#pragma arm section

kal_bool sync_status = KAL_FALSE;

/**********************************************************
Function declaration
***********************************************************/
int ConvertHexToBin(kal_int8 *pStart);


/**********************************************************
Extern variables
***********************************************************/
extern kal_uint32 Load$$DSP_ROM$$Base;
#define DSP_START_ADDR &Load$$DSP_ROM$$Base


#endif /* __DSP_FCORE4__ && !defined(__UBL__) */
   
         
#if defined(__DSP_BOOT_ORG__) /* __DSP_BOOT_ORG__ */


#if !defined(__UBL__)

/*************************************************************************
* FUNCTION
*  INT_Version_Check
*
* DESCRIPTION
*   This function implements HW ID check with software load version
*
* CALLS
*  U_PutUARTByte
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_int32 dmdsp_init(void)
{

	kal_int32 result =0;
	
	result = dsp_argv_string[0];
	
#if defined(DMDSP_INIT_DEBUG)
	//dbg_print("DMDSP INIT start\n\r");
#endif
    /* */
    
    /* Set the start addr of DMDSP */
    *(volatile unsigned short *)DMDSP_RESETADDR_L = RESETADDR_L;
    *(volatile unsigned short *)DMDSP_RESETADDR_H = RESETADDR_H;

#if defined(TK6270) || defined(MT6270A) || defined(MT6276) || defined(MT6573) || defined(MT6575) || defined(MT6577)
    /* CLR the resetout signal*/
    *(volatile unsigned short *)DMDSP_RESETOUT_CLR = 0x1048;
    *(volatile unsigned short *)DMDSP_RESETOUT_CLR = 0x0048;
#elif defined(MT6268T) /* TK6270 || MT6270A */
    *(volatile unsigned short *)DMDSP_RESETOUT_CLR = 0x0;
    *(volatile unsigned short *)DMDSP_RESETOUT_CLR = 0x1;
#else /* TK6270 || MT6270A */
    #error "please define how to boot-up DSP"
#endif /* TK6270 || MT6270A */


#if defined(DMDSP_INIT_DEBUG)
	//dbg_print("DMDSP translate from intel hex to bin start\n\r");
#endif	

#if !defined(L1D_TEST_COSIM)
    /* Memory copy bin data from intel hex */
    #if defined(MT6276) || defined(MT6573) || defined(MT6575) || defined(MT6577)
    result = ConvertHexToBin((kal_int8 *)MAP2CREGVA(DSP_START_ADDR));
    #else
    result = ConvertHexToBin((kal_int8 *)DSP_START_ADDR);
    #endif
#endif /* !L1D_TEST_COSIM */

    if (result !=0) return -1;

	
#if defined(DMDSP_INIT_DEBUG)
    //dbg_print("DMDSP translate from intel hex to bin finish\n\r");
#endif


    /* Parse the loader file done, we could enable DSP now.*/
    *(volatile unsigned short *)DMDSP_SRAMINIT_CLR = 0x0000;
       
    return 0;
}


#if defined(INTEL_HEX_TO_BIN)



/**********************************************************
Global variables
***********************************************************/
hexstruct *g_pointer;
kal_uint8 g_Byte[2*20];


/**********************************************************
Function declaration
***********************************************************/
void CharToByte(kal_int8* pChar,kal_uint8* pByte, int nByte);
void Hex4addr(kal_int8* PLChar, kal_int8* PHChar,kal_uint8 *addr);
void Hex2addr(kal_int8* PLChar, kal_uint8 *addr);



/*************************************************************************
* FUNCTION
*  INT_Version_Check
*
* DESCRIPTION
*   This function implements HW ID check with software load version
*
* CALLS
*  U_PutUARTByte
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void CharToByte(kal_int8* pChar,kal_uint8* pByte, int nbyte)
{
    kal_int8 h,l;
    
    while (nbyte > 0)
    {
    	h=pChar[0];//high addr
    	l=pChar[1];//low addr
    	if(l>='0'&&l<='9')
       	l=l-'0';
    	else if(l>='a' && l<='f')
       	l=l-'a'+0xa;
    	else if(l>='A' && l<='F')
       	l=l-'A'+0xa;
    	if(h>='0'&&h<='9')
       	h=h-'0';
    	else if(h>='a' && h<='f')
       	h=h-'a'+0xa;
    	else if(h>='A' &&h <='F')
       	h=h-'A'+0xa;

    	*pByte=(kal_uint8)h*16+l;

#if defined(DMDSP_INIT_DEBUG)
			dbg_print(" addr = %x , value = %x \n\r",pByte, *pByte);
#endif

		
    	pChar += 2;
    	pByte += 1;
    	nbyte--;

       
		
    }
}

/*************************************************************************
* FUNCTION
*  INT_Version_Check
*
* DESCRIPTION
*   This function implements HW ID check with software load version
*
* CALLS
*  U_PutUARTByte
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void Hex4addr(kal_int8* PLChar, kal_int8* PHChar, kal_uint8 *addr)
{
	CharToByte(PLChar, 	(kal_uint8 *)addr+1, 1);
	CharToByte(PLChar+2,(kal_uint8 *)addr  , 1);
	CharToByte(PHChar, 	(kal_uint8 *)addr+3, 1);
	CharToByte(PHChar+2,(kal_uint8 *)addr+2, 1);
}

/*************************************************************************
* FUNCTION
*  INT_Version_Check
*
* DESCRIPTION
*   This function implements HW ID check with software load version
*
* CALLS
*  U_PutUARTByte
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void Hex2addr(kal_int8* PLChar, kal_uint8 *addr)
{
	CharToByte(PLChar, 	(kal_uint8 *)addr+1,   1);
	CharToByte(PLChar+2,(kal_uint8 *)addr, 	1);
}

/*************************************************************************
* FUNCTION
*  INT_Version_Check
*
* DESCRIPTION
*   This function implements HW ID check with software load version
*
* CALLS
*  U_PutUARTByte
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
int ConvertHexToBin(kal_int8 *pStart)
{
    kal_uint32 base_addr = 0;
    kal_uint16 shift_addr = 0;
    kal_uint8 pBC[1];
    kal_uint8 g_finish = 0;
    
#if defined(DMDSP_INIT_DEBUG)	
    kal_uint32 count = 0;	

#endif


    while (g_finish == 0)
    {
    	
    	
#if defined(DMDSP_INIT_DEBUG)	
		count++;	

#endif
    g_pointer = (hexstruct *)pStart;
		CharToByte(g_pointer->record_type, g_Byte,1);
		CharToByte(g_pointer->ByteCount, (kal_uint8 *)pBC, 1);

#if defined(DMDSP_INIT_DEBUG)
		dbg_print("  \n\r New line start \n\r");
		dbg_print("  start symbol = %x ",g_pointer->colm);
		dbg_print("  ByteCount = %x ",pBC[0]);
		dbg_print("  Record type = %x \n\r",g_Byte);
#endif
						
	
		switch (*(kal_uint8 *)g_Byte)
		{
			
			case 0x01:
				g_finish = 1;
				break;
			
			case 0x04:
				Hex4addr(g_pointer->addr, g_pointer->data, (kal_uint8 *)&base_addr);	
				base_addr >= 4;
				base_addr <= 4;
				
				#if defined(DMDSP_INIT_DEBUG)
					dbg_print("New region base address = %x \n\r",base_addr);
				#endif
				
				break;
			
			case 0x00:
				Hex2addr(g_pointer->addr , (kal_uint8 *)&shift_addr);

				#if defined(DMDSP_INIT_DEBUG)
					dbg_print("Start copy data to address = %x \n\r",base_addr+shift_addr);
				#endif

				CharToByte(g_pointer->data,(kal_uint8 *)(base_addr + shift_addr), *(kal_uint8 *)pBC);
				break;
			
			default:
				g_finish = 1;
				break;
		}
		
		pStart = ((g_pointer->data + *(kal_uint8 *)pBC * 2) + 4);
		
		
	}

	return 0;
}

#else /* INTELL_HEX_TO_BIN */


/*************************************************************************
* FUNCTION
*  INT_Version_Check
*
* DESCRIPTION
*   This function implements HW ID check with software load version
*
* CALLS
*  U_PutUARTByte
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
long circindex(long index, long incr, unsigned long nitems)
{
	index += incr;

	if (index < 0) 
		 index += nitems;
	else if (index >= nitems) 
		index -= nitems;
    
    return index;
}

/*************************************************************************
* FUNCTION
*  INT_Version_Check
*
* DESCRIPTION
*   This function implements HW ID check with software load version
*
* CALLS
*  U_PutUARTByte
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_int32  ConvertHexToBin(kal_int8 *pStart)
{

    mi_block_header *block;
    mi_table_header *meminit = (mi_table_header *)(pStart+MEMINIT_STREAM_IGNORE_BITS);
    kal_int8 *src, *dest;
    void (*fnptr)(void);
    kal_int32 i, j, cnt;
    kal_uint32 type;
    kal_uint32 addr;
    kal_uint32 bn = 0, num_blocks;
    
    if (meminit == 0)
    {
		 return 0;	/* MemInit wasn't used to build a table */
    }

    if (meminit->magic.magic != MI_MAGIC|| meminit->magic.version != 0)
    {
	 
#if defined(DMDSP_INIT_DEBUG)
		dbg_print("  \n\r Error in magic (0xFFFF) = %x or version (0x0) = %x  \n\r", meminit->magic.magic, meminit->magic.version);
#endif
        return -1;	/* not an init table we recognise */
    }
        
    num_blocks = meminit->num_blocks;

    if (num_blocks == 0)
        return 0;	/* no blocks to initialise */

	  /* Process each block in turn. */
    block = meminit->blocks;
    
    while (bn++ < num_blocks) {
        type = block->flags;


		
#if defined(DMDSP_INIT_DEBUG)
	dbg_print("  \n\r New block is found  \n\r");
	dbg_print("  \n\r Block  addr = %x \n\r", block->addr);
	dbg_print("  \n\r Block  bytecount = %x  \n\r",block->byte_count);
	dbg_print("  \n\r Block  flags = %x  \n\r", block->flags);
	dbg_print("  \n\r Block  pattern bytes = %x  \n\r", block->pattern_bytes);
#endif

		
        /* validation */
        if (((type & MI_WS_BITS)>>MI_WS_POS) != MI_WS_8BITS)
            return -1;
        if (((type & MI_MEM_BITS)>>MI_MEM_POS) != MI_MEM_US)
            return -1;
        
        type &= MI_BT_BITS;
        type >>= MI_BT_POS;

        switch (type) {
            case MI_BT_RAW:
				
#if defined(DMDSP_INIT_DEBUG)
		dbg_print("  \n\r CASE MI_BT_RAW  \n\r");
#endif
            /* copy the data directly */
                src = (kal_int8 *)(block+1);
                dest = block->addr;
                cnt = block->byte_count;

#if defined(DSPINIT_ON_DSP)                
                if (in_l1_instr((unsigned long)dest)) 
                {
                    if (_memcpy_l1(dest, src, cnt) != dest)
                    {
                        return -1;
                    } 
                    else 
                    {
                        src += cnt;
                    }
                } 
                else 
#endif /* DSPINIT_ON_DSP */
		  {
                    for (i = 0; i < cnt; i++)
                    {
			   
#if defined(DMDSP_INIT_DEBUG)
	dbg_print("  \n\r src = %x , value = %x   dest = %x , value = %x \n\r", src, *src, dest, *dest);
#endif
                        *dest++ = *src++;
                    }
                }

                /* round up to start of next word */
                addr = (unsigned long)src;
                if (addr & 0x3)
                    addr += 4;
                
                addr &= ~0x3;
                src = (kal_int8 *)addr;
                break;
            
            case MI_BT_ZERO:
				
#if defined(DMDSP_INIT_DEBUG)
	dbg_print("  \n\r MI_BT_ZERO \n\r");
#endif
            /* Zero-fill the target section */
                dest = block->addr;
                cnt = block->byte_count;
                /* don't add code here */
                for (i = 0; i < cnt; i++)
                {
                    *dest++ = 0;
			
#if defined(DMDSP_INIT_DEBUG)
	dbg_print("  \n\r  dest = %x , value = %x \n\r",  dest, 0);
#endif		
                }
                    
                src = (kal_int8 *)(block+1);
                break;
                
            case MI_BT_CALL:
		
#if defined(DMDSP_INIT_DEBUG)
	dbg_print("  \n\r MI_BT_CALL \n\r");
#endif		
                /* Call the block as an initialization function */
                fnptr = (void (*)(void))block->addr;
                (*fnptr)();
                src = (kal_int8 *)(block+1);
                break;
                
            case MI_BT_REP:
				
#if defined(DMDSP_INIT_DEBUG)
	dbg_print("  \n\r MI_BT_REP \n\r");
#endif
                /* keep repeating the pattern until we've filled
                the section to the requested number of bytes.
                No guarantee that byte_count % pattern_bytes == 0. */
                j = 0;
                src = (kal_int8 *)(block+1);
                dest = block->addr;
                cnt = block->byte_count;
                /* don't add code here */
                for (i = 0; i < cnt; i++) 
                {
                    dest[i] = src[j];
                    j = circindex(j, 1, block->pattern_bytes);
                }
			
                /* round up the pattern length to 32-bit multiple. */
                addr = block->pattern_bytes;
                
                if (addr & 0x3)
                    addr += 4;
                    
                addr &= ~0x3;
                /* advance pointer by that much */
                src += addr;
                break;
            default:
			
#if defined(DMDSP_INIT_DEBUG)
	dbg_print("  \n\r Default...... there is something errror \n\r");
#endif	
                return -1;
        }
        /* src now points to the beginning of the next block */
        block = (mi_block_header *)src;
    }
    return 0;
}


#endif /* INTEL_HEX_TO_BIN */


#endif /* __UBL__ */


#elif defined(__DSP_BOOT_SEC__)


/*************************************************************************
* FUNCTION
*  dmdsp_ungate_dsp
*
* DESCRIPTION
*   This function implement the un-gate function
*
* CALLS
*  U_PutUARTByte -> UART driver is not initialized when it is called in bootarm.s
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void dmdsp_ungate_dsp(void)
{
#if !defined(__NO_ARM_BL__) 
    *(volatile unsigned long *)BL_SYNC_ADDR = BL_SYNC_NOT_START;   
    *(volatile unsigned short *)DMDSP_SRAMINIT_CLR = 0x0000;
#endif /* */    
}
/*************************************************************************
* FUNCTION
*  INT_Version_Check
*
* DESCRIPTION
*   This function implements HW ID check with software load version
*
* CALLS
*  U_PutUARTByte -> UART driver is not initialized when it is called in bootarm.s
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
#if !defined(__UBL__)
#if !defined(_NAND_FLASH_BOOTING_) && !defined(__EMMC_BOOTING__)
kal_int32 dmdsp_init(void)
#else
kal_int32 dmdsp_init(kal_uint32 cnt_base_addr)
#endif /* */
{

	kal_int32 result =0;
	
#if defined(__SV5_ENABLED__)	
    GFH_FILE_INFO_v1 *pFileInfo;
#endif    
    
	result = dsp_argv_string[0];

#if defined(__NO_ARM_BL__)
    
    if ( BL_FRST_MAGIC != *(volatile unsigned long *)BL_SYNC_ADDR)   
    {
        *(volatile unsigned long *)BL_SYNC_ADDR = BL_SYNC_NOT_START;   
    }
       
    *(volatile unsigned short *)DMDSP_SRAMINIT_CLR = 0x0000;
#endif /* */

    
    /* Set up the load , backup , and jump address */
    /* Non-NFB the load address is fixed so we do not need to process content address */
#if !defined(_NAND_FLASH_BOOTING_) && !defined(__EMMC_BOOTING__)
    *(volatile unsigned long *)BL_LOAD_ADDR = (kal_uint32)DSP_START_ADDR+DSP_BL_CONTENT_OFFSET;
    *(volatile unsigned long *)BL_BACK_ADDR = (DSP_EXEC_START_ADDR + DSP_EXEC_LEN);
    *(volatile unsigned long *)BL_JUMP_ADDR = (DSP_EXEC_JUMP_ADDR);
#else
    pFileInfo = (GFH_FILE_INFO_v1*)cnt_base_addr;    
    *(volatile unsigned long *)BL_LOAD_ADDR = (kal_uint32)(cnt_base_addr + pFileInfo->m_content_offset) ;
    *(volatile unsigned long *)BL_BACK_ADDR = (DSP_EXEC_START_ADDR + DSP_EXEC_LEN);
    *(volatile unsigned long *)BL_JUMP_ADDR = (DSP_EXEC_JUMP_ADDR);
#endif /* !_NAND_FLASH_BOOTING_ */

    
    cp15_clean_dcache();
    
    *(volatile unsigned long *)BL_SYNC_ADDR = BL_SYNC_MAGIC;
  
       
    return 0;
}

/*************************************************************************
* FUNCTION
*  dmdsp_sync_done
*
* DESCRIPTION
*   This function implements HW ID check with software load version
*
* CALLS
*  U_PutUARTByte -> UART driver is not initialized when it is called in bootarm.s
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool dmdsp_sync_done(void)
{
    kal_uint32 count = 0xFFFFFF;
    
    while (count-- > 0 && (*(volatile unsigned long *)BL_SYNC_ADDR == BL_SYNC_MAGIC));
    
    if (count == 0 ) 
    {
        return KAL_FALSE;
    }
    else
    {
        return KAL_TRUE;
    }
}

#endif /* !__UBL__ */

#endif /* __DSP_FCORE4_ORG__ */
