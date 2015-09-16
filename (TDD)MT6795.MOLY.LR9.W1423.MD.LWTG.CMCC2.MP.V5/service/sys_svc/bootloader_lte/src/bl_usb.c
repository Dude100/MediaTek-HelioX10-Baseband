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
 *   bl_usb.c
 *
 * Project:
 * --------
 *   Bootloader
 *
 * Description:
 * ------------
 *   Wrapper for USB driver
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_general_types.h"   
#include "kal_public_api.h" 
#include "bl_share_param.h" 
#include "bl_cfgctl.h" 
#include "bl_efuse.h" 
#include "bl_wdt.h" 
#include "bl_usb.h" 
#include "bl_GPT.h" 
#include "brom_usb_drv.h" 

#define BUFMAX			2048

typedef struct {
    kal_uint32 len;
    kal_uint8  buf[BUFMAX];
} tx_buffer_t;

typedef struct {
    kal_uint32 len;
    kal_uint32 pos;
    kal_uint8  buf[BUFMAX];
} rx_buffer_t;

tx_buffer_t tbuf;
rx_buffer_t rbuf;

static kal_uint32 g_usb_own_state;

static void USB_GetPidVid(kal_uint16 *pid, kal_uint16* vid)
{
    if(g_mini_ext_bl_param.usb_pid != 0 || g_mini_ext_bl_param.usb_vid != 0)
    {
        //Use GFH setting if it exists
        *pid = g_mini_ext_bl_param.usb_pid;
        *vid = g_mini_ext_bl_param.usb_vid;
    }
    else
    {
        //Otherwise use efuse setting
        bl_efuse_get_usb_pidvid(pid, vid);
    }
}

kal_bool  USBDL_UART_Init(void)
{
    kal_uint16 usb_pid, usb_vid;

    //Setup the ownership of USB
    g_usb_own_state = bl_cfgctl_save_and_set_usbown(USB30_MAC_MD|USB30_PHY_MD);

    //Get PID/VID setting
    USB_GetPidVid(&usb_pid, &usb_vid);

    //Set up PID/VID
    brom_usb_patch_pid_vid(usb_pid, usb_vid);

    //Init USB driver
    brom_usb_init();

    //Init rx & tx buffer
    tbuf.len = 0;
    rbuf.len = 0;
    rbuf.pos = 0;

    bl_wdt_restart();

    return KAL_TRUE;
}

void USBDL_Release(void)
{
    brom_usb_deinit();

    //Restore the ownership of USB
    bl_cfgctl_restore_usbown(g_usb_own_state);
}

kal_bool USBDL_Is_USB_Download_Mode(void)
{
    bl_wdt_restart();

    //Polling USB link status until timeout
    BL_GPT_START_TIMEOUT_S(BL_USB_TIMEOUT_S);
    while(brom_usb_get_link_st() != BROM_USB_LINK_ON){
        if(BL_GPT_GET_TIMEOUT_STATUS() == KAL_TRUE){
            return KAL_FALSE;
        }
    };

    bl_wdt_restart();

    return KAL_TRUE;
}

void USBDL_PutUARTByte_Ext(kal_uint8 data,kal_bool blocking_api)
{
	// put the character into tbuf 
	tbuf.buf[tbuf.len] = data;
	tbuf.len++;

	if (tbuf.len == BUFMAX)
		USBDL_PutUARTByte_Complete();
}

void USBDL_PutUARTByte(kal_uint8 data)
{
	USBDL_PutUARTByte_Ext(data, KAL_TRUE);
}


/*
	It is called by bootloader to flush the tx buffer into USB FIFO
*/
void USBDL_PutUARTByte_Complete_Ext(kal_bool blocking_api)
{
	kal_uint32 i=0;

	//Send USB one byte at a time to avoid USB ZLP issue
	while(tbuf.len){
		brom_usb_send_tx_data(&tbuf.buf[i], 1);
		i++;
		tbuf.len--;
	}
}

void USBDL_PutUARTByte_Complete(void)
{
	USBDL_PutUARTByte_Complete_Ext(KAL_TRUE);
}

kal_bool USB_GetcNonblock(kal_uint8 *ch)
{
    *ch = 0;

    if(rbuf.len)
    {

        //Get character from rbuf
        *ch = rbuf.buf[rbuf.pos];

        rbuf.pos++;
        rbuf.len--;

        return KAL_TRUE;		
    }
    else{
        //Get data from usb device
        rbuf.len = 0;
        rbuf.pos = 0;

        if(brom_usb_get_rx_data(rbuf.buf, &rbuf.len))
        {

            *ch = rbuf.buf[rbuf.pos];

            rbuf.pos++;
            rbuf.len--;

            return KAL_TRUE;
        }
        else
        {
            return KAL_FALSE;
        }
    }
}

kal_uint8 USBDL_GetUARTByte_Ext(kal_bool blocking_api)
{
    kal_uint8 ch;

    if(blocking_api == KAL_TRUE)
    {
        while(!USB_GetcNonblock(&ch));
        return ch;
    }
    else
    {
        USB_GetcNonblock(&ch);
        return ch;
    }
}


kal_uint8 USBDL_GetUARTByte(void)
{
	return USBDL_GetUARTByte_Ext(KAL_TRUE);
}

// this can be omited for USB COM
void USBDL_CheckUARTSendEnd(void)
{
}
