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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   ccci_misc_data_info.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   CCCI MISC info config id 
 *
 * Author:
 * -------
 * -------
 *
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * [CCCI IPC] Support Clibtime feature
 *
 * removed!
 * removed!
 * [CCCI] CCCI new debug mechanism
 *
 * removed!
 * removed!
 * [CCCI MISCINFO] Change SBP id name
 *
 * removed!
 * removed!
 * [CCCI MISC Info] Change NT code to SBP ID
 *
 * removed!
 * removed!
 * [CCCI MISC INFO] Add ccci misc id for SBP NT code
 *
 ****************************************************************************/

X_CCCI_MISCINFO_CONF(CCMSG_ID_MISCINFO_HIF_DMA_REMAP)   //- add for DMA to query HIF-DMA remap address
X_CCCI_MISCINFO_CONF(CCMSG_ID_MISCINFO_RTC_32K_LESS)	//- add for L1 to query 32K-less information in AP
X_CCCI_MISCINFO_CONF(CCMSG_ID_MISCINFO_RANDOM_SEED_NUM) //- add for sram repair function to get random seed number from AP (Owner: SE7/SD3/Cindy)
X_CCCI_MISCINFO_CONF(CCMSG_ID_MISCINFO_GPS_COCLOCK)     //- add for L1D to query GPS co-clock information from AP
X_CCCI_MISCINFO_CONF(CCMSG_ID_MISCINFO_SBP_ID)     	    //- add for SBP to query SBP related profile (Owner: SE3/PS8/Hong)
X_CCCI_MISCINFO_CONF(CCMSG_ID_MISCINFO_CCCI)            //- add for CCCI related feature (Owner: SE7/SD8/CS)
X_CCCI_MISCINFO_CONF(CCMSG_ID_MISCINFO_CLIB_TIME)       //- add for KAL to get andriod time (Owner: SE7/SS/Carl)

