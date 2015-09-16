/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
 *  custom_ups_config.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is used to define the UPS configuration.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/******************************************************************************/
/*========================================================================
 *  CAUTION !! CAUTION !! CAUTION !! CAUTION !! CAUTION !! CAUTION !!
 *
 *  Please DO NOT modify code below.
 *
 *  CAUTION !! CAUTION !! CAUTION !! CAUTION !! CAUTION !! CAUTION !!
 *======================================================================= */

/******************************************************************************/

#include "kal_general_types.h"
#include "kal_public_api.h"

#include "custom_ups_config.h"

/******************************************************************************/
#ifdef __MBIM_SUPPORT__

kal_uint8* mbim_custom_getMacAddress(void)
{
    static const kal_uint8 mac_addr[] =
        {VENDOR_MAC_ADDRESS_PREFIX, 0xAA, 0xAA, 0xAA};

    ASSERT((sizeof(mac_addr)/sizeof(kal_uint8)) == 6);
    return (kal_uint8*)mac_addr;
}

#endif

#ifdef __USB_TETHERING__

kal_uint8* rndis_custom_getGWMacAddress()
{  
    static const kal_uint8 GWMacAddr[] = { VENDOR_MAC_ADDRESS_PREFIX,0xFF,0xFF,0xFF};
    ASSERT((sizeof(GWMacAddr)/sizeof(kal_uint8))==6) ;
    return (kal_uint8*)GWMacAddr;
}

kal_uint8* rndis_custom_getMPMacAddress()
{
    static const kal_uint8 MPMacAddr[] = { VENDOR_MAC_ADDRESS_PREFIX,0xAA,0xAA,0xAA};
    ASSERT((sizeof(MPMacAddr)/sizeof(kal_uint8))==6) ;
    return (kal_uint8*)MPMacAddr;
}

kal_uint16 rndis_custom_getMPVendorId()
{
    return (kal_uint16) VENDOR_ID;
}

static const kal_uint8 MPVendorDesc[] = VENDOR_DESCRIPTION;
kal_uint8* rndis_custom_getMPVendorDesc()
{
    return (kal_uint8*)MPVendorDesc;
}

kal_uint16 rndis_custom_getMPVendorDescLen()
{
    ASSERT(((sizeof(MPVendorDesc)/sizeof(kal_uint8))-1) <= 64);
    return (kal_uint16) ((sizeof(MPVendorDesc)/sizeof(kal_uint8))-1);
}
 
kal_uint32 rndis_custom_getMPLinkSpeed()
{
    return (kal_uint32) VENDOR_DEVICE_LINKSPEED;
}

#endif
/******************************************************************************/
