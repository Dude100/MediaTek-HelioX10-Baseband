/*!
 *  @file usbcore_mode.h
 *  @author Roger Huang <chaomin.haung@mediatek.com>
 *  @version 1.0
 *  @section LICENSE
 *
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
 *  @section DESCRIPTION
 *  This file provides mode related definitions of usbcore
 */

#ifndef _USBCORE_MODE_H
#define _USBCORE_MODE_H


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


/*!
 *  @brief USBC_DEF_BCDDEV defines default bcd device
 */
#define USBC_DEF_BCDDEV                     0x0001


/*!
 *  @brief USBC_DEF_STR_IDX_LANGUAGE defines default language string index
 */
#define USBC_DEF_STR_IDX_LANGUAGE           0x00


/*!
 *  @brief USBC_DEF_IDX_MANUFACTURER defines default manufacturer string index
 */
#define USBC_DEF_STR_IDX_MANUFACTURER       0x01


/*!
 *  @brief USBC_DEF_IDX_PRODUCT defines default product string index
 */
#define USBC_DEF_STR_IDX_PRODUCT            0x02


/*!
 *  @brief USBC_DEF_IDX_SERIALNUM defines default serial number string index
 */
#define USBC_DEF_STR_IDX_SERIALNUM          0x03


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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


/*!
 *  @brief USBC_USB11_MAX_PACKET_SIZE define maximum packet size in USB SPEED 1.1
 */
#define USBC_USB11_MAX_PACKET_SIZE          64


/*!
 *  @brief USBC_USB20_MAX_PACKET_SIZE define maximum packet size in USB SPEED 2.0
 */
#define USBC_USB20_MAX_PACKET_SIZE          512


/*!
 *  @brief USBC_USB30_MAX_PACKET_SIZE define maximum packet size in USB SPEED 3.0
 */
#define USBC_USB30_MAX_PACKET_SIZE          1024


/*!
 *  @brief usbc_core_mode_e enumerate all possible modes of USBCORE module
 *  @param USBC_CORE_MODE_MIN                       pseudo mode
 *  @param USBC_CORE_MODE_ACM                       1 CDC-ACM COM
 *  @param USBC_CORE_MODE_ECM                       1 CDC-ECM
 *  @param USBC_CORE_MODE_RNDIS                     1 RNDIS
 *  @param USBC_CORE_MODE_CDROM                     1 Mass Storage CDROM
 *  @param USBC_CORE_MODE_DISK                      1 Mass Storage Disk
 *  @param USBC_CORE_MODE_MBIM                      1 MBIM
 *  @param USBC_CORE_MODE_1RNDIS_1ACM               1 RNDIS 1 CDC-ACM
 *  @param USBC_CORE_MODE_1RNDIS_2ACM               1 RNDIS 2 CDC-ACM
 *  @param USBC_CORE_MODE_1ECM_1ACM                 1 CDC-ECM 1 CDC-ACM
 *  @param USBC_CORE_MODE_2ACM                      2 CDC-ACM
 *  @param USBC_CORE_MODE_3ACM                      3 CDC-ACM
 *  @param USBC_CORE_MODE_1RNDIS_1ACM_1CDROM        1 RNDIS 1 CDC-ACM 1 CDROM
 *  @param USBC_CORE_MODE_1ECM_1ACM_1CDROM          1 CDC-ECM 1 CDC-ACM 1 CDROM
 *  @param USBC_CORE_MODE_MAX                       pseudo mode
 */
typedef enum _usbc_core_mode {
    USBC_CORE_MODE_MIN                          = 0,
    USBC_CORE_MODE_ACM                          = 1,
    USBC_CORE_MODE_ECM                          = 2,
    USBC_CORE_MODE_RNDIS                        = 3,
    USBC_CORE_MODE_CDROM                        = 4,
    USBC_CORE_MODE_DISK                         = 5,
    USBC_CORE_MODE_MBIM                         = 6,
    USBC_CORE_MODE_1RNDIS_1ACM                  = 7,
    USBC_CORE_MODE_1RNDIS_2ACM                  = 8,
    USBC_CORE_MODE_1ECM_1ACM                    = 9,
    USBC_CORE_MODE_2ACM                         = 10,
    USBC_CORE_MODE_3ACM                         = 11,
    USBC_CORE_MODE_1RNDIS_1ACM_1CDROM           = 12,
    USBC_CORE_MODE_1ECM_1ACM_1CDROM             = 13,
#ifdef __USB_MSD_SUPPORT__
	USBC_CORE_MODE_MSD							=14,
	USBC_CORE_MODE_1ACM_1MSD					=15,
#endif
    USBC_CORE_MODE_1MBIM_1ACM                   = 16,
    USBC_CORE_MODE_MAX                          = 99,
} usbc_core_mode_e;


/*!
 *  @brief set the mode usbcore will run at
 */
void usbc_core_set_mode(usbc_core_mode_e mode);


/*!
 *  @brief  SetUp all things for MODE CDC_ACM
 */
void usbc_core_set_mode_acm(void);


/*!
 *  @brief  SetUp all things for MODE RNDIS
 */
void usbc_core_set_mode_rndis(void);


/*!
 *  @brief  SetUp all things for MODE 1MBIM_1ACM
 */
void usbc_core_set_mode_1mbim_1acm(void);


/*!
 *  @brief  SetUp all things for MODE 1RNDIS_1ACM
 */
void usbc_core_set_mode_1rndis_1acm(void);


/*!
 *  @brief  SetUp all things for MODE 1RNDIS_2ACM
 */
void usbc_core_set_mode_1rndis_2acm(void);

/*!
 *  @brief  SetUp all things for MODE 1RNDIS_3ACM
 */
void usbc_core_set_mode_3acm(void);

/*!
 *  @brief  Set up an USB device with one MBIM function.
 */
void usbc_core_set_mode_mbim(void);
/*!
 *  @brief  Set up an USB device with one MSD function.
 */
void usbc_core_set_mode_msd(void);

void usbc_core_set_mode_1acm_1msd();

#endif  // _USBCORE_MODE_H

