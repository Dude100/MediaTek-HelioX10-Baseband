/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *   bl_xboot.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *  X-booting command
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
 *
 * removed!
 * removed!
 * .add SDIO UL multiple GPD solution to anhance xboot time
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * .
 ****************************************************************************/
#include "br_xboot_cmd.h"
#include "brom_errno.h"
#include "brom_sdio_drv.h"

//#define XBOOT_TEST
static kal_uint32 xboot_cmd_timeout;

void Xboot_SetTimeout(kal_uint32 timeout)
{
    xboot_cmd_timeout = timeout;
}

uint32 XbootCmd_GetBin(uint32 offset, uint32 length, uint32 dest)
{
#ifdef XBOOT_TEST

#define TEST_IMG_BASE 0x3000000

	memcpy((uint8 *)dest, (uint8 *)(TEST_IMG_BASE+offset), length);

	return ERR_OK;
#else
	uint32 status = ERR_OK;
	Xboot_CMD_U cmd;
	uint32 left = length, size;

	//prepare command
	memset(&cmd,0,sizeof(Xboot_CMD_GetBin));
	cmd.m_cmd_GetBin.m_magic = MD_CMD_MAGIC;
	cmd.m_cmd_GetBin.m_msg_id = GET_BIN;
	cmd.m_cmd_GetBin.m_offset = offset;
	cmd.m_cmd_GetBin.m_len = length;

	//Send Command
	if(!brom_sdio_send_tx_xboot((uint8 *)&cmd, sizeof(Xboot_CMD_U), xboot_cmd_timeout)){
		status = E_XBOOT_CMD_SEND_DATA_FAIL;
		goto __end;
	}

	//receive ack command
	//Important Note for xboot command implementation:
	//Ffor SDIO, receiving must be after sending is done, and the buffer used by sending is also released.
	memset(&cmd,0,sizeof(Xboot_CMD_status));

	//Get Ack
	size = sizeof(Xboot_CMD_U);
	if(!brom_sdio_get_rx_xboot((uint8 *)&cmd, (kal_uint32 *)&size, xboot_cmd_timeout)){
		status = E_XBOOT_CMD_GET_DATA_FAIL;
		goto __end;
	}

	if(size != sizeof(Xboot_CMD_U)){
		status = E_XBOOT_CMD_GET_DATA_SIZE_FAIL;
		goto __end;
	}

	if(cmd.m_cmd_Status.m_magic != ACK_MD_MAGIC)
	{
		status = E_XBOOT_CMD_GETBIN_ACK_MAGIC_MISMATCH;
		goto __end;
	}

	if(cmd.m_cmd_Status.m_msg_id != ACK_GET_BIN)
	{
		status = E_XBOOT_CMD_GETBIN_ACK_ID_NOT_MATCH;
		goto __end;
	}

	if(cmd.m_cmd_Status.m_status >= XBOOT_ERROR)
	{
		status = E_XBOOT_CMD_GETBIN_ACK_NOT_OK;
		goto __end;
	}

	//Receive binary
	//Note that in SDIO,  the buffer for command and for receiving bin might be the same buffer
	//Make sure the command usage is finished before receiving binary (it is guaranteed by XbootCmd_GetBin itself) 

	//Get binary
	while(left){
		size = left;
		if(!brom_sdio_get_rx_xboot((uint8 *)dest, (kal_uint32 *)&size, xboot_cmd_timeout)){
			status = E_XBOOT_CMD_GET_DATA_FAIL;
			goto __end;
		}

		dest += size;
		left -= size;
	}
	

__end:
	
	return status;
#endif
}

uint32 XbootCmd_Status(XBOOT_CMD_ID msg_id, XBOOT_STAUS xboot_status)
{
#ifdef XBOOT_TEST

	return ERR_OK;
#else
	uint32 status = ERR_OK;
	uint32 size;
	Xboot_CMD_U cmd;

	//This API is only for BIN_LOAD_START, BIN_LOAD_END and MD_BOOT_END command
	if((BIN_LOAD_START != msg_id) && (BIN_LOAD_END != msg_id) && (MD_MSG_FLUSH != msg_id) && (MD_BOOT_END != msg_id))
	{
		status = E_XBOOT_CMD_STATUS_MSG_ID_INVALID;
		goto __end;
	}

	//prepare command
	memset(&cmd, 0, sizeof(Xboot_CMD_status));
	cmd.m_cmd_Status.m_magic = MD_CMD_MAGIC;
	cmd.m_cmd_Status.m_msg_id = msg_id;
	cmd.m_cmd_Status.m_status= xboot_status;

	//Send Command
	if(!brom_sdio_send_tx_xboot((uint8 *)&cmd, sizeof(Xboot_CMD_U), xboot_cmd_timeout)){
		status = E_XBOOT_CMD_SEND_DATA_FAIL;
		goto __end;
	}

	//receive ack command
	//Important Note for xboot command implementation:
	//For SDIO, receiving must be after sending is done, and the buffer used by sending is also released.
	memset(&cmd, 0, sizeof(Xboot_CMD_status));

	//Get Ack
	size = sizeof(Xboot_CMD_U);
	if(!brom_sdio_get_rx_xboot((uint8 *)&cmd, (kal_uint32 *)&size, xboot_cmd_timeout)){
		status = E_XBOOT_CMD_GET_DATA_FAIL;
		goto __end;
	}

	if(size != sizeof(Xboot_CMD_U)){
		status = E_XBOOT_CMD_GET_DATA_SIZE_FAIL;
		goto __end;
	}
	
	if(cmd.m_cmd_Status.m_magic != ACK_MD_MAGIC)
	{
		status = E_XBOOT_CMD_STATUS_ACK_MAGIC_MISMATCH;
		goto __end;
	}

	if(cmd.m_cmd_Status.m_msg_id != (msg_id+1))
	{
		status = E_XBOOT_CMD_STATUS_ACK_ID_NOT_MATCH;
		goto __end;
	}

	if(cmd.m_cmd_Status.m_status >= XBOOT_ERROR)
	{
		status = E_XBOOT_CMD_STATUS_ACK_NOT_OK;
		goto __end;
	}

__end:
	
	return status;
#endif
}

uint32 XbootCmd_DbgPrint(const char *str, uint32 len)
{
	uint32 status;
	uint32 remaining_len = len;
	uint32 i;
	uint32 size;
	Xboot_CMD_U cmd;

#ifdef XBOOT_TEST

    status = ERR_OK;

#else

	while(remaining_len > 0)
	{
		//prepare command
		memset(&cmd,0,sizeof(Xboot_CMD_DBGprint));
		cmd.m_cmd_DBGprint.m_magic = MD_CMD_MAGIC;
		cmd.m_cmd_DBGprint.m_msg_id = MD_MSG_OUTPUT;
		
		if(remaining_len >= XBOOT_STR_LEN)
		{
			cmd.m_cmd_DBGprint.m_str_len = XBOOT_STR_LEN;
			remaining_len -= XBOOT_STR_LEN;
		}
		else
		{
			cmd.m_cmd_DBGprint.m_str_len = remaining_len;
			remaining_len = 0;
		}
		
		for(i = 0; i < cmd.m_cmd_DBGprint.m_str_len; i++)
		{
			cmd.m_cmd_DBGprint.m_str[i] = str[len-remaining_len-cmd.m_cmd_DBGprint.m_str_len+i];
		}

		//Send Command
		if(!brom_sdio_send_tx_xboot((uint8 *)&cmd, sizeof(Xboot_CMD_U), xboot_cmd_timeout)){
			status = E_XBOOT_CMD_SEND_DATA_FAIL;
			goto __end;
		}

		//receive ack command
		//Note that for SDIO, receiving must be after sending is done, and the buffer used by sending is also released.
		memset(&cmd,0,sizeof(Xboot_CMD_status));
		
		//Get Ack
		size = sizeof(Xboot_CMD_U);
		if(!brom_sdio_get_rx_xboot((uint8 *)&cmd, (kal_uint32 *)&size, xboot_cmd_timeout)){
			status = E_XBOOT_CMD_GET_DATA_FAIL;
			goto __end;
		}

		if(size != sizeof(Xboot_CMD_U)){
			status = E_XBOOT_CMD_GET_DATA_SIZE_FAIL;
			goto __end;
		}

		if(cmd.m_cmd_Status.m_magic != ACK_MD_MAGIC)
		{
			status = E_XBOOT_CMD_DBGPRINT_ACK_MAGIC_MISMATCH;
			goto __end;
		}

		if(cmd.m_cmd_Status.m_msg_id != ACK_MD_MSG_OUTPUT)
		{
			status = E_XBOOT_CMD_DBGPRINT_ACK_ID_NOT_MATCH;
			goto __end;
		}

		if(cmd.m_cmd_Status.m_status >= XBOOT_ERROR)
		{
			status = E_XBOOT_CMD_DBGPRINT_ACK_NOT_OK;
			goto __end;
		}
	}

	//Notify Host to flush the message
	status = XbootCmd_Status(MD_MSG_FLUSH, XBOOT_OK);

__end:

#endif

	return status;
}

uint32 XbootCmd_BufSizeChange(uint32 bufSize)
{
#ifdef XBOOT_TEST

	return ERR_OK;
#else
	uint32 status = ERR_OK;
	uint32 size;
	Xboot_CMD_U cmd;

	//prepare command
	memset(&cmd, 0, sizeof(Xboot_CMD_BufSize));
	cmd.m_cmd_BufSize.m_magic = MD_CMD_MAGIC;
	cmd.m_cmd_BufSize.m_msg_id = MD_BUF_SIZE_CHANGE;
	cmd.m_cmd_BufSize.m_buf_size = bufSize;

	//Send Command
	if(!brom_sdio_send_tx_xboot((uint8 *)&cmd, sizeof(Xboot_CMD_U), xboot_cmd_timeout)){
		status = E_XBOOT_CMD_SEND_DATA_FAIL;
		goto __end;
	}

	//receive ack command
	//Important Note for xboot command implementation:
	//For SDIO, receiving must be after sending is done, and the buffer used by sending is also released.
	memset(&cmd, 0, sizeof(Xboot_CMD_status));

	//Get Ack
	size = sizeof(Xboot_CMD_U);
	if(!brom_sdio_get_rx_xboot((uint8 *)&cmd, (kal_uint32 *)&size, xboot_cmd_timeout)){
		status = E_XBOOT_CMD_GET_DATA_FAIL;
		goto __end;
	}

	if(size != sizeof(Xboot_CMD_U)){
		status = E_XBOOT_CMD_GET_DATA_SIZE_FAIL;
		goto __end;
	}

	if(cmd.m_cmd_Status.m_magic != ACK_MD_MAGIC)
	{
		status = E_XBOOT_CMD_STATUS_ACK_MAGIC_MISMATCH;
		goto __end;
	}

	if(cmd.m_cmd_Status.m_msg_id != (MD_BUF_SIZE_CHANGE+1))
	{
		status = E_XBOOT_CMD_STATUS_ACK_ID_NOT_MATCH;
		goto __end;
	}

	if(cmd.m_cmd_Status.m_status >= XBOOT_ERROR)
	{
		status = E_XBOOT_CMD_STATUS_ACK_NOT_OK;
		goto __end;
	}

__end:

	return status;
#endif
}

void Xboot_BootTrace(kal_uint32 data)
{
    brom_sdio_write_mb1(data);
}
