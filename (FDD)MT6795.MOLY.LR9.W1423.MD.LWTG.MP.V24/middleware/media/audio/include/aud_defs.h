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
 * aud_defs.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary definitions of audio manager task.
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _AUD_DEFS_H
#define _AUD_DEFS_H

/*-----------------------------------------------------------------------------
                    macros, defines
-----------------------------------------------------------------------------*/

/* Legacy volume settings */
#define AUD_MAX_VOLUME_LEVEL                        (7)
 
/*-----------------------------------------------------------------------------
                    typedefs, enums
-----------------------------------------------------------------------------*/

/* audio type */
typedef enum
{
    AUD_TYPE_NONE = 0,                      /* 0: none */
    AUD_TYPE_SPEECH,                        /* 1: speech */
    AUD_TYPE_TONE,                          /* 2: tone */
    AUD_TYPE_KEYTONE,                       /* 3: keytone */
    AUD_TYPE_MIC = 8                        /* 8: Microphone */
} aud_type_enum;

/* volume type */
typedef enum
{
    AUD_VOLUME_CTN = 0,                     /* 0: tone */
    AUD_VOLUME_KEY,                         /* 1: keytone */
    AUD_VOLUME_MIC,                         /* 2: microphone */
    AUD_VOLUME_FMR,                         /* 3: FM Radio */
    AUD_VOLUME_SPH,                         /* 4: Speech */
    AUD_VOLUME_SID,                         /* 5: Side-tone */
    AUD_VOLUME_MEDIA,                       /* 6: Multi-Media */
    
    AUD_MAX_VOLUME_TYPE
} aud_volume_enum;

/* Audio path */
typedef enum
{
    AUD_PATH_UNKNOWN  = 0x00,               /* Unknown */
    AUD_PATH_RECEIVER = 0x01,               /* Speaker */
    AUD_PATH_HEADSET  = 0x02,               /* Headset */
    AUD_PATH_SPEAKER  = 0x04,               /* Loud-speaker */
    AUD_PATH_DUAL     = 0x08,               /* Both headset and loud-speaker */
    AUD_PATH_BT       = 0x10                /* BT */
} aud_path_enum;


#endif /* _AUD_DEFS_H */
