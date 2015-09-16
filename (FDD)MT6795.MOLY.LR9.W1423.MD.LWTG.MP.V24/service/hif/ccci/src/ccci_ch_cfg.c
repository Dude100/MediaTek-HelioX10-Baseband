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
 *   ccci_ch_cfg.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Defines the CCCI channel mapping
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * 08 01 2014 ap.wang
 * removed!
 * .
 *
 * removed!
 * removed!
 * [CCCI] CCCI new debug mechanism
 *
 * removed!
 * removed!
 * [K2 MD2] Add CCCI/CCIF new feature for K2 MD2
 *
 * 05 14 2014 ap.wang
 * removed!
 * CCMNI Fast Ack Patch and linkdown fast reload
 *
 * removed!
 * removed!
 * 	[CCMNI ACK Fast Path]
 * removed!
 * removed!
 * [CCCI & RPC & FS] ASSERT enhancement
 *
 * removed!
 * removed!
 * [CCCI] Add ICUSB feature.
 *
 * 11 26 2013 box.wu
 * removed!
 * add exception, tty, ICUSB.
 *
 * removed!
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * .
 *
 * 06 28 2013 box.wu
 * removed!
 * change to legacy
 *
 * 06 11 2013 ap.wang
 * removed!
 * [CCCI IMS] Add IMSD channel for __HIF_CLDMA_SUPPORT__
 *
 * 06 04 2013 ap.wang
 * removed!
 * Modify header file to include new CCCI header file for compatibility.
 * Add fake API
 *
 * 06 03 2013 box.wu
 * removed!
 * CCIFCore GPD support
 *
 * 05 30 2013 ap.wang
 * removed!
 * [CCCI_IMS] Add IMS_DCTRL channel
 *
 * 01 28 2013 ap.wang
 * removed!
 * [CCCI] CCCI_IMS channel rename
 *
 * removed!
 * removed!
 * [CCCI] CCCI_IMS 1st verison loopback support
 *
 * 01 11 2013 ap.wang
 * removed!
 * [CCCI] Modify CCCI channel config
 ****************************************************************************/
#include "ccci_common.h"
#include "ccci_if.h"
#include "ccci_ch_cfg.h"

#if defined (__HIF_SDIO_SUPPORT__)
#include "sdiocore_if.h"
static ccci_ch_handle ccci_ch_info[CCCI_PEER_ID_MAX][CCCI_MAX_CHANNEL] = {
	// CCCI_PEER_ID_AP_MD
	{
	    /*[Realtime] CCCI Control*/
	    {SDIOC_TXQ_Q0, CCCI_CH_USER_DIRECT, CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_SDIO }, // [00] CCCI_CONTROL_CHANNEL     
	    {SDIOC_RXQ_Q0, CCCI_CH_USER_DIRECT, CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_SDIO }, // [01] CCCI_CONTROL_CHANNEL_ACK 
	    /*[Realtime] CCCI System*/
	    {SDIOC_TXQ_Q0, CCCI_CH_USER_DIRECT, CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_SDIO }, // [02] CCCI_SYSTEM_CHANNEL      
	    {SDIOC_RXQ_Q0, CCCI_CH_USER_DIRECT, CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_SDIO }, // [03] CCCI_SYSTEM_CHANNEL_ACK  
	    /*[Realtime] Audio*/
	    {SDIOC_TXQ_Q0, CCCI_CH_USER_DIRECT, CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_SDIO }, // [04] CCCI_PCM_CHANNEL         
	    {SDIOC_RXQ_Q0, CCCI_CH_USER_DIRECT, CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_SDIO }, // [05] CCCI_PCM_CHANNEL_ACK     
	    /*[TTY Core] Meta --> Through TTY Core*/
	    {SDIOC_TXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, ccci_dlior_cb,  NULL, CCCI_TYPE_SDIO }, // [06] CCCI_TST_CHANNEL         
	    {SDIOC_RXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_SDIO }, // [07] CCCI_TST_ACK_CHANNEL     //No use
	    {SDIOC_RXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_SDIO }, // [08] CCCI_TR_CHANNEL          
	    {SDIOC_TXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, ccci_dlior_cb,  NULL, CCCI_TYPE_SDIO }, // [09] CCCI_TR_ACK_CHANNEL      //No use
	    /*[TTY Core] AT*/
	    {SDIOC_TXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, ccci_dlior_cb,  NULL, CCCI_TYPE_SDIO }, // [10] CCCI_AT_CHANNEL_TX       
	    {SDIOC_RXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_SDIO }, // [11] CCCI_AT_ACK_CHANNEL_TX   //No use
	    {SDIOC_RXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_SDIO }, // [12] CCCI_AT_CHANNEL_RX       
	    {SDIOC_TXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, ccci_dlior_cb,  NULL, CCCI_TYPE_SDIO }, // [13] CCCI_AT_ACK_CHANNEL_RX   //No use
	    /*File System Service*/
	    {SDIOC_TXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, ccci_dlior_cb,  NULL, CCCI_TYPE_SDIO }, // [14] CCCI_FS_CHANNEL          
	    {SDIOC_RXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_SDIO }, // [15] CCCI_FS_ACK_CHANNEL      
	    /*PMIC*/
	    /*6516 PMIC specific re-quirement: set PMIC SIM VCC*/
	    {SDIOC_TXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, ccci_dlior_cb,  NULL, CCCI_TYPE_SDIO }, // [16] CCCI_PMIC_CHANNEL        
	    {SDIOC_RXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_SDIO }, // [17] CCCI_PMIC_ACK_CHANNEL    
	    /*UEM*/
	    /*AP engineering mode to switch on/off MD feature*/
	    {SDIOC_TXQ_Q1, CCCI_CH_USER_LEGACY, CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_SDIO }, // [18] CCCI_UEM_CHANNEL         
	    {SDIOC_RXQ_Q1, CCCI_CH_USER_LEGACY, CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_SDIO }, // [19] CCCI_UEM_ACK_CHANNEL     
	    /*[NET] 6290 PDN 1*/
	    {SDIOC_TXQ_Q3, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_SDIO }, // [20] CCCI_CCMNI1_RX           
	    {SDIOC_RXQ_Q2, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb, NULL, CCCI_TYPE_SDIO }, // [21] CCCI_CCMNI1_RX_ACK       //No use
	    {SDIOC_RXQ_Q2, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb, NULL, CCCI_TYPE_SDIO }, // [22] CCCI_CCMNI1_TX           
	    {SDIOC_TXQ_Q3, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_SDIO }, // [23] CCCI_CCMNI1_TX_ACK       //No use
	    /*[NET] 6290 PDN 2*/
		{SDIOC_TXQ_Q3, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_SDIO }, // [24] CCCI_CCMNI2_RX           
		{SDIOC_RXQ_Q2, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb, NULL, CCCI_TYPE_SDIO }, // [25] CCCI_CCMNI2_RX_ACK     //No use  
		{SDIOC_RXQ_Q2, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb, NULL, CCCI_TYPE_SDIO }, // [26] CCCI_CCMNI2_TX           
		{SDIOC_TXQ_Q3, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_SDIO }, // [27] CCCI_CCMNI2_TX_ACK       //No use
	    /*[NET] 6290 PDN 3*/
	    {SDIOC_TXQ_Q3, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_SDIO }, // [28] CCCI_CCMNI3_RX           
		{SDIOC_RXQ_Q4, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb, NULL, CCCI_TYPE_SDIO }, // [29] CCCI_CCMNI3_RX_ACK     //No use  
		{SDIOC_RXQ_Q4, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb, NULL, CCCI_TYPE_SDIO }, // [30] CCCI_CCMNI3_TX           
		{SDIOC_TXQ_Q3, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_SDIO }, // [31] CCCI_CCMNI3_TX_ACK       //No use
		/*RPC Service*/
		{SDIOC_TXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, ccci_dlior_cb,  NULL, CCCI_TYPE_SDIO }, // [32] CCCI_IPC_RPC_CHANNEL         
	    {SDIOC_RXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_SDIO }, // [33] CCCI_IPC_RPC_ACK_CHANNEL     
	    /*Message/IPC Service*/
	    {SDIOC_TXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, ccci_dlior_cb,  NULL, CCCI_TYPE_SDIO }, // [34] CCCI_MSGSVC_SEND_CHANNEL     
	    {SDIOC_RXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_SDIO }, // [35] CCCI_MSGSVC_SEND_ACK_CHANNEL //No use 
	    {SDIOC_RXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_SDIO }, // [36] CCCI_MSGSVC_RCV_CHANNEL      
	    {SDIOC_TXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, ccci_dlior_cb,  NULL, CCCI_TYPE_SDIO }, // [37] CCCI_MSGSVC_RCV_ACK_CHANNEL   //No use
	    /*[TTY Core] GPS user --> Throught TTY Core*/
		{SDIOC_TXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, ccci_dlior_cb,  NULL, CCCI_TYPE_SDIO }, // [38] CCCI_GPS_CHANNEL_TX          
	    {SDIOC_RXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_SDIO }, // [39] CCCI_GPS_ACK_CHANNEL_TX      //No use
	    {SDIOC_RXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_SDIO }, // [40] CCCI_GPS_CHANNEL_RX          
	    {SDIOC_TXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, ccci_dlior_cb,  NULL, CCCI_TYPE_SDIO }, // [41] CCCI_GPS_ACK_CHANNEL_RX    //No use   
	    /*[TTY Core] MD Log --> Replaced by DHL --> Through TTY Core*/
	    /*MD send log to AP to store in SD card*/
	    {SDIOC_TXQ_Q2, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, ccci_dlior_cb,  NULL, CCCI_TYPE_SDIO }, // [42] CCCI_MD_LOG_RX               
	    {SDIOC_RXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_SDIO }, // [43] CCCI_MD_LOG_TX               
        /*************************ARM7*********************************************/ 
        {0,            CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CAIF_GPD },  // [44] CCCI_ARM7_RESERVED1_TX  
        {1,            CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CAIF_GPD },  // [45] CCCI_ARM7_RESERVED1_RX  
        {2,            CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CAIF_GPD },  // [46] CCCI_ARM7_RESERVED2_RX  
        {3,            CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CAIF_GPD },  // [47] CCCI_ARM7_RESERVED2_TX  
        {0,            CCCI_CH_USER_LEGACY, CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CAIF_BUF },  // [48] CCCI_ARM7_RESERVED3_TX  
        {1,            CCCI_CH_USER_LEGACY, CCCI_TYPE_RX, NULL, ccci_ulbuff_cb, CCCI_TYPE_CAIF_BUF },  // [49] CCCI_ARM7_RESERVED3_RX  
        /*[Realtime] CCCI IT CHANNEL*/
	    {SDIOC_TXQ_Q0, CCCI_CH_USER_DIRECT, CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_SDIO }, // [50] CCCI_IT_CHANNEL_TX     
	    {SDIOC_RXQ_Q0, CCCI_CH_USER_DIRECT, CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_SDIO }, // [51] CCCI_IT_CHANNEL_RX 
	    /*IMS channel */
	    {SDIOC_RXQ_Q0, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_SDIO }, // [52] CCCI_IMSV_UL
	    {SDIOC_TXQ_Q0, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_SDIO }, // [53] CCCI_IMSV_DL         
	    {SDIOC_RXQ_Q0, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_SDIO }, // [54] CCCI_IMSC_UL
	    {SDIOC_TXQ_Q0, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_SDIO }, // [55] CCCI_IMSC_DL 
	    {SDIOC_RXQ_Q0, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_SDIO }, // [56] CCCI_IMSA_UL
	    {SDIOC_TXQ_Q0, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_SDIO }, // [57] CCCI_IMSA_DL 
	    {SDIOC_RXQ_Q0, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_SDIO }, // [58] CCCI_IMSD_UL
	    {SDIOC_TXQ_Q0, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_SDIO }, // [59] CCCI_IMSD_DL
	    /*ICUSB channel*/
	    {SDIOC_TXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, ccci_dlior_cb,  NULL, CCCI_TYPE_SDIO }, // [60] CCCI_SIM_CHANNEL_TX       
	    {SDIOC_RXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_SDIO }, // [61] CCCI_SIM_CHANNEL_RX       
	    /*[Realtime] CCCI IT LB CHANNEL*/
        {SDIOC_TXQ_Q0, CCCI_CH_USER_DIRECT, CCCI_TYPE_TX, NULL, 		  NULL, CCCI_TYPE_SDIO }, // [62] CCCI_LB_IT_CHANNEL_TX	 
	    {SDIOC_RXQ_Q0, CCCI_CH_USER_DIRECT, CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_SDIO }, // [63] CCCI_LB_IT_CHANNEL_RX 
        /*__CCMNI_ACK_FAST_PATH__*/
        {SDIOC_RXQ_Q3, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_SDIO }, // [64] CCCI_CCMNI1_DLACK_RX	 
	    {SDIOC_RXQ_Q3, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_SDIO }, // [65] CCCI_CCMNI2_DLACK_RX 
	    {SDIOC_RXQ_Q4, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_SDIO }, // [66] CCCI_CCMNI3_DLACK_RX 
        /*CCCI DEBUG INFO*/
        {SDIOC_TXQ_Q0, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_SDIO }, // [67] CCCI_DEBUG_STATUS_CHANNEL_TX 
	    {SDIOC_RXQ_Q0, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_SDIO }, // [68] CCCI_DEBUG_STATUS_CHANNEL_RX
	    /*[NET] 6290 PDN 4*/
        {SDIOC_TXQ_Q3, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_SDIO }, // [69] CCCI_CCMNI4_RX           
    	{SDIOC_RXQ_Q4, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_SDIO }, // [70] CCCI_CCMNI4_RX_ACK     //No use  
    	{SDIOC_RXQ_Q4, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_SDIO }, // [71] CCCI_CCMNI4_TX           
    	{SDIOC_TXQ_Q3, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_SDIO }, // [72] CCCI_CCMNI4_TX_ACK       //No use
    	{SDIOC_RXQ_Q4, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_SDIO }, // [73] CCCI_CCMNI4_DLACK_RX 
        /* [NET] 6290 PDN5 */
        {SDIOC_TXQ_Q3, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_SDIO }, // [74] CCCI_CCMNI5_RX           
    	{SDIOC_RXQ_Q4, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_SDIO }, // [75] CCCI_CCMNI5_RX_ACK     //No use  
    	{SDIOC_RXQ_Q4, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_SDIO }, // [76] CCCI_CCMNI5_TX           
    	{SDIOC_TXQ_Q3, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_SDIO }, // [77] CCCI_CCMNI5_TX_ACK       //No use
    	{SDIOC_RXQ_Q4, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_SDIO }, // [78] CCCI_CCMNI5_DLACK_RX 
        /* [NET] 6290 PDN6 */
        {SDIOC_TXQ_Q3, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_SDIO }, // [79] CCCI_CCMNI6_RX           
    	{SDIOC_RXQ_Q4, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_SDIO }, // [80] CCCI_CCMNI6_RX_ACK     //No use  
    	{SDIOC_RXQ_Q4, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_SDIO }, // [81] CCCI_CCMNI6_TX           
    	{SDIOC_TXQ_Q3, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_SDIO }, // [82] CCCI_CCMNI6_TX_ACK       //No use
    	{SDIOC_RXQ_Q4, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_SDIO }, // [83] CCCI_CCMNI6_DLACK_RX 
        /* [NET] 6290 PDN7 */
        {SDIOC_TXQ_Q3, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_SDIO }, // [84] CCCI_CCMNI7_RX           
    	{SDIOC_RXQ_Q4, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_SDIO }, // [85] CCCI_CCMNI7_RX_ACK     //No use  
    	{SDIOC_RXQ_Q4, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_SDIO }, // [86] CCCI_CCMNI7_TX           
    	{SDIOC_TXQ_Q3, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_SDIO }, // [87] CCCI_CCMNI7_TX_ACK       //No use
    	{SDIOC_RXQ_Q4, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_SDIO }, // [88] CCCI_CCMNI7_DLACK_RX 
        /* [NET] 6290 PDN8 */
        {SDIOC_TXQ_Q3, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_SDIO }, // [89] CCCI_CCMNI8_RX           
    	{SDIOC_RXQ_Q4, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_SDIO }, // [90] CCCI_CCMNI8_RX_ACK     //No use  
    	{SDIOC_RXQ_Q4, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_SDIO }, // [91] CCCI_CCMNI8_TX           
    	{SDIOC_TXQ_Q3, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_SDIO }, // [92] CCCI_CCMNI8_TX_ACK       //No use
    	{SDIOC_RXQ_Q4, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_SDIO }, // [93] CCCI_CCMNI8_DLACK_RX 
    }
    /*CCCI_FORCE_RESET_MODEM_CHANNEL  = 20090215*/                                                   
    /*Special condition: AP request MD to assert*/
};
#elif defined (__HIF_CLDMA_SUPPORT__)
#include "cldmacore_if.h"
static ccci_ch_handle ccci_ch_info[CCCI_PEER_ID_MAX][CCCI_MAX_CHANNEL] = {
	// CCCI_PEER_ID_AP_MD
	{
	    /*[Realtime] CCCI Control*/
	    {CLDMAC_TXQ_Q0, CCCI_CH_USER_DIRECT, CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CLDMA }, // [00] CCCI_CONTROL_CHANNEL     
	    {CLDMAC_RXQ_Q0, CCCI_CH_USER_DIRECT, CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [01] CCCI_CONTROL_CHANNEL_ACK 
	    /*[Realtime] CCCI System*/
	    {CLDMAC_TXQ_Q0, CCCI_CH_USER_DIRECT, CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CLDMA }, // [02] CCCI_SYSTEM_CHANNEL      
	    {CLDMAC_RXQ_Q0, CCCI_CH_USER_DIRECT, CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [03] CCCI_SYSTEM_CHANNEL_ACK  
	    /*[Realtime] Audio*/
	    {CLDMAC_TXQ_Q0, CCCI_CH_USER_DIRECT, CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CLDMA }, // [04] CCCI_PCM_CHANNEL         
	    {CLDMAC_RXQ_Q0, CCCI_CH_USER_DIRECT, CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [05] CCCI_PCM_CHANNEL_ACK     
	    /*[TTY Core] Meta --> Through TTY Core*/
	    {CLDMAC_TXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, ccci_dlior_cb,  NULL, CCCI_TYPE_CLDMA }, // [06] CCCI_TST_CHANNEL         
	    {CLDMAC_RXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [07] CCCI_TST_ACK_CHANNEL     //No use
	    {CLDMAC_RXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [08] CCCI_TR_CHANNEL          
	    {CLDMAC_TXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, ccci_dlior_cb,  NULL, CCCI_TYPE_CLDMA }, // [09] CCCI_TR_ACK_CHANNEL      //No use
	    /*[TTY Core] AT*/
	    {CLDMAC_TXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, ccci_dlior_cb,  NULL, CCCI_TYPE_CLDMA }, // [10] CCCI_AT_CHANNEL_TX       
	    {CLDMAC_RXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [11] CCCI_AT_ACK_CHANNEL_TX   //No use
	    {CLDMAC_RXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [12] CCCI_AT_CHANNEL_RX       
	    {CLDMAC_TXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, ccci_dlior_cb,  NULL, CCCI_TYPE_CLDMA }, // [13] CCCI_AT_ACK_CHANNEL_RX   //No use
	    /*File System Service*/
	    {CLDMAC_TXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, ccci_dlior_cb,  NULL, CCCI_TYPE_CLDMA }, // [14] CCCI_FS_CHANNEL          
	    {CLDMAC_RXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [15] CCCI_FS_ACK_CHANNEL      
	    /*PMIC*/
	    /*6516 PMIC specific re-quirement: set PMIC SIM VCC*/
	    {CLDMAC_TXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, ccci_dlior_cb,  NULL, CCCI_TYPE_CLDMA }, // [16] CCCI_PMIC_CHANNEL        
	    {CLDMAC_RXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [17] CCCI_PMIC_ACK_CHANNEL    
	    /*UEM*/
	    /*AP engineering mode to switch on/off MD feature*/
	    {CLDMAC_TXQ_Q1, CCCI_CH_USER_LEGACY, CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CLDMA }, // [18] CCCI_UEM_CHANNEL         
	    {CLDMAC_RXQ_Q1, CCCI_CH_USER_LEGACY, CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [19] CCCI_UEM_ACK_CHANNEL     
	    /*[NET] 6290 PDN 1*/
	    {CLDMAC_TXQ_Q3, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CLDMA }, // [20] CCCI_CCMNI1_RX           
	    {CLDMAC_RXQ_Q3, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb, NULL, CCCI_TYPE_CLDMA }, // [21] CCCI_CCMNI1_RX_ACK       //No use
	    {CLDMAC_RXQ_Q3, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb, NULL, CCCI_TYPE_CLDMA }, // [22] CCCI_CCMNI1_TX           
	    {CLDMAC_TXQ_Q3, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CLDMA }, // [23] CCCI_CCMNI1_TX_ACK       //No use
	    /*[NET] 6290 PDN 2*/
	    {CLDMAC_TXQ_Q4, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CLDMA }, // [24] CCCI_CCMNI2_RX           
	    {CLDMAC_RXQ_Q3, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb, NULL, CCCI_TYPE_CLDMA }, // [25] CCCI_CCMNI2_RX_ACK     //No use  
	    {CLDMAC_RXQ_Q3, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb, NULL, CCCI_TYPE_CLDMA }, // [26] CCCI_CCMNI2_TX           
	    {CLDMAC_TXQ_Q4, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CLDMA }, // [27] CCCI_CCMNI2_TX_ACK       //No use
	    /*[NET] 6290 PDN 3*/
	    {CLDMAC_TXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CLDMA }, // [28] CCCI_CCMNI3_RX           
	    {CLDMAC_RXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [29] CCCI_CCMNI3_RX_ACK     //No use  
	    {CLDMAC_RXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [30] CCCI_CCMNI3_TX           
	    {CLDMAC_TXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CLDMA }, // [31] CCCI_CCMNI3_TX_ACK       //No use
	    /*RPC Service*/
	    {CLDMAC_TXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, ccci_dlior_cb,  NULL, CCCI_TYPE_CLDMA }, // [32] CCCI_IPC_RPC_CHANNEL         
	    {CLDMAC_RXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [33] CCCI_IPC_RPC_ACK_CHANNEL     
	    /*Message/IPC Service*/
	    {CLDMAC_TXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, ccci_dlior_cb,  NULL, CCCI_TYPE_CLDMA }, // [34] CCCI_MSGSVC_SEND_CHANNEL     
	    {CLDMAC_RXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [35] CCCI_MSGSVC_SEND_ACK_CHANNEL //No use 
	    {CLDMAC_RXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [36] CCCI_MSGSVC_RCV_CHANNEL      
	    {CLDMAC_TXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, ccci_dlior_cb,  NULL, CCCI_TYPE_CLDMA }, // [37] CCCI_MSGSVC_RCV_ACK_CHANNEL   //No use
	    /*[TTY Core] GPS user --> Throught TTY Core*/
	    {CLDMAC_TXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, ccci_dlior_cb,  NULL, CCCI_TYPE_CLDMA }, // [38] CCCI_GPS_CHANNEL_TX          
	    {CLDMAC_RXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [39] CCCI_GPS_ACK_CHANNEL_TX      //No use
	    {CLDMAC_RXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [40] CCCI_GPS_CHANNEL_RX          
	    {CLDMAC_TXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, ccci_dlior_cb,  NULL, CCCI_TYPE_CLDMA }, // [41] CCCI_GPS_ACK_CHANNEL_RX    //No use   
	    /*[TTY Core] MD Log --> Replaced by DHL --> Through TTY Core*/
	    /*MD send log to AP to store in SD card*/
	    {CLDMAC_TXQ_Q2, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, ccci_dlior_cb,  NULL, CCCI_TYPE_CLDMA }, // [42] CCCI_MD_LOG_RX               
	    {CLDMAC_RXQ_Q2, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [43] CCCI_MD_LOG_TX               
	/*************************ARM7*********************************************/ 
	    {0,            CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CAIF_GPD },  // [44] CCCI_ARM7_RESERVED1_TX  
	    {1,            CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CAIF_GPD },  // [45] CCCI_ARM7_RESERVED1_RX  
	    {2,            CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CAIF_GPD },  // [46] CCCI_ARM7_RESERVED2_RX  
	    {3,            CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CAIF_GPD },  // [47] CCCI_ARM7_RESERVED2_TX  
	    {0,            CCCI_CH_USER_LEGACY, CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CAIF_BUF },  // [48] CCCI_ARM7_RESERVED3_TX  
	    {1,            CCCI_CH_USER_LEGACY, CCCI_TYPE_RX, NULL, ccci_ulbuff_cb, CCCI_TYPE_CAIF_BUF },  // [49] CCCI_ARM7_RESERVED3_RX  
	    /*[Realtime] CCCI IT CHANNEL*/
	    {CLDMAC_TXQ_Q0, CCCI_CH_USER_DIRECT, CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CLDMA }, // [50] CCCI_IT_CHANNEL_TX     
	    {CLDMAC_RXQ_Q0, CCCI_CH_USER_DIRECT, CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [51] CCCI_IT_CHANNEL_RX 
	    /*IMS channel */
	    {CLDMAC_RXQ_Q6, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [52] CCCI_IMSV_UL
	    {CLDMAC_TXQ_Q6, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CLDMA }, // [53] CCCI_IMSV_DL         
	    {CLDMAC_RXQ_Q6, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [54] CCCI_IMSC_UL
	    {CLDMAC_TXQ_Q6, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CLDMA }, // [55] CCCI_IMSC_DL 
	    {CLDMAC_RXQ_Q6, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [56] CCCI_IMSA_UL
	    {CLDMAC_TXQ_Q6, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CLDMA }, // [57] CCCI_IMSA_DL 
	    {CLDMAC_RXQ_Q6, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [58] CCCI_IMSD_UL
	    {CLDMAC_TXQ_Q6, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CLDMA }, // [59] CCCI_IMSD_DL
	    /*ICUSB channel*/
	    {CLDMAC_TXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, ccci_dlior_cb,  NULL, CCCI_TYPE_CLDMA }, // [60] CCCI_SIM_CHANNEL_TX       
	    {CLDMAC_RXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [61] CCCI_SIM_CHANNEL_RX       
	    /*[Realtime] CCCI IT LB CHANNEL*/
	    {CLDMAC_TXQ_Q0, CCCI_CH_USER_DIRECT, CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CLDMA }, // [62] CCCI_LB_IT_CHANNEL_TX	 
	    {CLDMAC_RXQ_Q0, CCCI_CH_USER_DIRECT, CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [63] CCCI_LB_IT_CHANNEL_RX 
         /*__CCMNI_ACK_FAST_PATH__*/
        {CLDMAC_RXQ_Q4, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [64] CCCI_CCMNI1_DLACK_RX     
        {CLDMAC_RXQ_Q4, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [65] CCCI_CCMNI2_DLACK_RX 
        {CLDMAC_RXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [66] CCCI_CCMNI3_DLACK_RX 
        /*CCCI DEBUG INFO*/
        {CLDMAC_TXQ_Q0, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CLDMA }, // [67] CCCI_DEBUG_STATUS_CHANNEL_TX 
	    {CLDMAC_RXQ_Q0, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [68] CCCI_DEBUG_STATUS_CHANNEL_RX
        /*[NET] 6290 PDN 4*/
        {CLDMAC_TXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CLDMA }, // [69] CCCI_CCMNI4_RX           
        {CLDMAC_RXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [70] CCCI_CCMNI4_RX_ACK     //No use  
        {CLDMAC_RXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [71] CCCI_CCMNI4_TX           
        {CLDMAC_TXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CLDMA }, // [72] CCCI_CCMNI4_TX_ACK       //No use
        {CLDMAC_TXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [73] CCCI_CCMNI4_DLACK_RX 
        /*[NET] 6290 PDN 5*/
        {CLDMAC_TXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CLDMA }, // [74] CCCI_CCMNI5_RX           
        {CLDMAC_RXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [75] CCCI_CCMNI5_RX_ACK     //No use  
        {CLDMAC_RXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [76] CCCI_CCMNI5_TX           
        {CLDMAC_TXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CLDMA }, // [77] CCCI_CCMNI5_TX_ACK       //No use
        {CLDMAC_TXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [78] CCCI_CCMNI5_DLACK_RX 
        /*[NET] 6290 PDN 6*/
        {CLDMAC_TXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CLDMA }, // [79] CCCI_CCMNI6_RX           
        {CLDMAC_RXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [80] CCCI_CCMNI6_RX_ACK     //No use  
        {CLDMAC_RXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [81] CCCI_CCMNI6_TX           
        {CLDMAC_TXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CLDMA }, // [82] CCCI_CCMNI6_TX_ACK       //No use
        {CLDMAC_TXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [83] CCCI_CCMNI6_DLACK_RX 
        /*[NET] 6290 PDN 7*/
        {CLDMAC_TXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CLDMA }, // [84] CCCI_CCMNI7_RX           
        {CLDMAC_RXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [85] CCCI_CCMNI7_RX_ACK     //No use  
        {CLDMAC_RXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [86] CCCI_CCMNI7_TX           
        {CLDMAC_TXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CLDMA }, // [87] CCCI_CCMNI7_TX_ACK       //No use
        {CLDMAC_TXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [88] CCCI_CCMNI7_DLACK_RX 
        /*[NET] 6290 PDN 8*/
        {CLDMAC_TXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CLDMA }, // [89] CCCI_CCMNI8_RX           
        {CLDMAC_RXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [90] CCCI_CCMNI8_RX_ACK     //No use  
        {CLDMAC_RXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [91] CCCI_CCMNI8_TX           
        {CLDMAC_TXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CLDMA }, // [92] CCCI_CCMNI8_TX_ACK       //No use
        {CLDMAC_TXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CLDMA }, // [93] CCCI_CCMNI8_DLACK_RX 
    }
	/*CCCI_FORCE_RESET_MODEM_CHANNEL  = 20090215*/                                                   
    /*Special condition: AP request MD to assert*/
};
#elif __CCIFCORE_SUPPORT__
#include "ccifcore_if.h"
static ccci_ch_handle ccci_ch_info[CCCI_PEER_ID_MAX][CCCI_MAX_CHANNEL] = {
	// CCCI_PEER_ID_AP_MD
	{
	    /*[Realtime] CCCI Control*/
	    {CCIFC_TXQ_Q0, CCCI_CH_USER_DIRECT, CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CCIF_GPD_AP }, // [00] CCCI_CONTROL_CHANNEL     
	    {CCIFC_RXQ_Q0, CCCI_CH_USER_DIRECT, CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [01] CCCI_CONTROL_CHANNEL_ACK 
	    /*[Realtime] CCCI System*/
	    {CCIFC_TXQ_Q0, CCCI_CH_USER_DIRECT, CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CCIF_GPD_AP }, // [02] CCCI_SYSTEM_CHANNEL      
	    {CCIFC_RXQ_Q0, CCCI_CH_USER_DIRECT, CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [03] CCCI_SYSTEM_CHANNEL_ACK  
	    /*[Realtime] Audio*/
	    {CCIFC_TXQ_Q0, CCCI_CH_USER_DIRECT, CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CCIF_GPD_AP }, // [04] CCCI_PCM_CHANNEL         
	    {CCIFC_RXQ_Q0, CCCI_CH_USER_DIRECT, CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [05] CCCI_PCM_CHANNEL_ACK     
	    /*[TTY Core] Meta --> Through TTY Core*/
	    {CCIFC_TXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, ccci_dlior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [06] CCCI_TST_CHANNEL         
	    {CCIFC_RXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [07] CCCI_TST_ACK_CHANNEL     //No use
	    {CCIFC_RXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [08] CCCI_TR_CHANNEL          
	    {CCIFC_TXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, ccci_dlior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [09] CCCI_TR_ACK_CHANNEL      //No use
	    /*[TTY Core] AT*/
	    {CCIFC_TXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, ccci_dlior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [10] CCCI_AT_CHANNEL_TX       
	    {CCIFC_RXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [11] CCCI_AT_ACK_CHANNEL_TX   //No use
	    {CCIFC_RXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [12] CCCI_AT_CHANNEL_RX       
	    {CCIFC_TXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, ccci_dlior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [13] CCCI_AT_ACK_CHANNEL_RX   //No use
	    /*File System Service*/
	    {CCIFC_TXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, ccci_dlior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [14] CCCI_FS_CHANNEL          
	    {CCIFC_RXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [15] CCCI_FS_ACK_CHANNEL      
	    /*PMIC*/
	    /*6516 PMIC specific re-quirement: set PMIC SIM VCC*/
	    {CCIFC_TXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, ccci_dlior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [16] CCCI_PMIC_CHANNEL        
	    {CCIFC_RXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [17] CCCI_PMIC_ACK_CHANNEL    
	    /*UEM*/
	    /*AP engineering mode to switch on/off MD feature*/
	    {CCIFC_TXQ_Q1, CCCI_CH_USER_LEGACY, CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CCIF_GPD_AP }, // [18] CCCI_UEM_CHANNEL         
	    {CCIFC_RXQ_Q1, CCCI_CH_USER_LEGACY, CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [19] CCCI_UEM_ACK_CHANNEL     
	    /*[NET] 6290 PDN 1*/
	    {CCIFC_TXQ_Q3, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CCIF_GPD_AP }, // [20] CCCI_CCMNI1_RX           
	    {CCIFC_RXQ_Q3, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb, NULL, CCCI_TYPE_CCIF_GPD_AP }, // [21] CCCI_CCMNI1_RX_ACK       //No use
	    {CCIFC_RXQ_Q3, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb, NULL, CCCI_TYPE_CCIF_GPD_AP }, // [22] CCCI_CCMNI1_TX           
	    {CCIFC_TXQ_Q3, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CCIF_GPD_AP }, // [23] CCCI_CCMNI1_TX_ACK       //No use
	    /*[NET] 6290 PDN 2*/
	    {CCIFC_TXQ_Q4, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CCIF_GPD_AP }, // [24] CCCI_CCMNI2_RX           
	    {CCIFC_RXQ_Q3, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb, NULL, CCCI_TYPE_CCIF_GPD_AP }, // [25] CCCI_CCMNI2_RX_ACK     //No use  
	    {CCIFC_RXQ_Q3, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb, NULL, CCCI_TYPE_CCIF_GPD_AP }, // [26] CCCI_CCMNI2_TX           
	    {CCIFC_TXQ_Q4, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CCIF_GPD_AP }, // [27] CCCI_CCMNI2_TX_ACK       //No use
	    /*[NET] 6290 PDN 3*/
	    {CCIFC_TXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CCIF_GPD_AP }, // [28] CCCI_CCMNI3_RX           
	    {CCIFC_RXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [29] CCCI_CCMNI3_RX_ACK     //No use  
	    {CCIFC_RXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [30] CCCI_CCMNI3_TX           
	    {CCIFC_TXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CCIF_GPD_AP }, // [31] CCCI_CCMNI3_TX_ACK       //No use
	    /*RPC Service*/
	    {CCIFC_TXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, ccci_dlior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [32] CCCI_IPC_RPC_CHANNEL         
	    {CCIFC_RXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [33] CCCI_IPC_RPC_ACK_CHANNEL     
	    /*Message/IPC Service*/
	    {CCIFC_TXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, ccci_dlior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [34] CCCI_MSGSVC_SEND_CHANNEL     
	    {CCIFC_RXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [35] CCCI_MSGSVC_SEND_ACK_CHANNEL //No use 
	    {CCIFC_RXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [36] CCCI_MSGSVC_RCV_CHANNEL      
	    {CCIFC_TXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, ccci_dlior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [37] CCCI_MSGSVC_RCV_ACK_CHANNEL   //No use
	    /*[TTY Core] GPS user --> Throught TTY Core*/
	    {CCIFC_TXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, ccci_dlior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [38] CCCI_GPS_CHANNEL_TX          
	    {CCIFC_RXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [39] CCCI_GPS_ACK_CHANNEL_TX      //No use
	    {CCIFC_RXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [40] CCCI_GPS_CHANNEL_RX          
	    {CCIFC_TXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, ccci_dlior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [41] CCCI_GPS_ACK_CHANNEL_RX    //No use   
	    /*[TTY Core] MD Log --> Replaced by DHL --> Through TTY Core*/
	    /*MD send log to AP to store in SD card*/
	    {CCIFC_TXQ_Q2, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, ccci_dlior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [42] CCCI_MD_LOG_RX               
	    {CCIFC_RXQ_Q2, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [43] CCCI_MD_LOG_TX               
        /*************************ARM7*********************************************/ 
        {0,            CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CAIF_GPD },  // [44] CCCI_ARM7_RESERVED1_TX  
        {1,            CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CAIF_GPD },  // [45] CCCI_ARM7_RESERVED1_RX  
        {2,            CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CAIF_GPD },  // [46] CCCI_ARM7_RESERVED2_RX  
        {3,            CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CAIF_GPD },  // [47] CCCI_ARM7_RESERVED2_TX  
        {0,            CCCI_CH_USER_LEGACY, CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CAIF_BUF },  // [48] CCCI_ARM7_RESERVED3_TX  
        {1,            CCCI_CH_USER_LEGACY, CCCI_TYPE_RX, NULL, ccci_ulbuff_cb, CCCI_TYPE_CAIF_BUF },  // [49] CCCI_ARM7_RESERVED3_RX  
	    /*[Realtime] CCCI IT CHANNEL*/
	    {CCIFC_TXQ_Q0, CCCI_CH_USER_DIRECT, CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CCIF_GPD_AP }, // [50] CCCI_IT_CHANNEL_TX     
	    {CCIFC_RXQ_Q0, CCCI_CH_USER_DIRECT, CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [51] CCCI_IT_CHANNEL_RX 
	    /*IMS channel */
	    {CCIFC_RXQ_Q6, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [52] CCCI_IMSV_UL
	    {CCIFC_TXQ_Q6, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CCIF_GPD_AP }, // [53] CCCI_IMSV_DL         
	    {CCIFC_RXQ_Q6, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [54] CCCI_IMSC_UL
	    {CCIFC_TXQ_Q6, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CCIF_GPD_AP }, // [55] CCCI_IMSC_DL 
	    {CCIFC_RXQ_Q6, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [56] CCCI_IMSA_UL
	    {CCIFC_TXQ_Q6, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CCIF_GPD_AP }, // [57] CCCI_IMSA_DL 
	    {CCIFC_RXQ_Q6, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [58] CCCI_IMSD_UL
	    {CCIFC_TXQ_Q6, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CCIF_GPD_AP }, // [59] CCCI_IMSD_DL
	    /*ICUSB channel*/
	    {CCIFC_TXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, ccci_dlior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [60] CCCI_SIM_CHANNEL_TX       
	    {CCIFC_RXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [61] CCCI_SIM_CHANNEL_RX       
	    /*[Realtime] CCCI IT LB CHANNEL*/
	    {CCIFC_TXQ_Q0, CCCI_CH_USER_DIRECT, CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CCIF_GPD_AP }, // [62] CCCI_LB_IT_CHANNEL_TX	 
	    {CCIFC_RXQ_Q0, CCCI_CH_USER_DIRECT, CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [63] CCCI_LB_IT_CHANNEL_RX 
        /*__CCMNI_ACK_FAST_PATH__*/
        {CCIFC_RXQ_Q4, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [64] CCCI_CCMNI1_DLACK_RX      
        {CCIFC_RXQ_Q4, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [65] CCCI_CCMNI2_DLACK_RX 
        {CCIFC_RXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [66] CCCI_CCMNI3_DLACK_RX 
        /*CCCI DEBUG INFO*/
        {CCIFC_TXQ_Q0, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CCIF_GPD_AP }, // [67] CCCI_DEBUG_STATUS_CHANNEL_TX 
	    {CCIFC_RXQ_Q0, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [68] CCCI_DEBUG_STATUS_CHANNEL_RX
	    /*[NET] 6290 PDN 4*/
        {CCIFC_TXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CCIF_GPD_AP }, // [69] CCCI_CCMNI4_RX           
        {CCIFC_RXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [70] CCCI_CCMNI4_RX_ACK     //No use  
        {CCIFC_RXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [71] CCCI_CCMNI4_TX           
        {CCIFC_TXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CCIF_GPD_AP }, // [72] CCCI_CCMNI4_TX_ACK       //No use
        {CCIFC_TXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [73] CCCI_CCMNI4_DLACK_RX 
        /*[NET] 6290 PDN 5*/
        {CCIFC_TXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CCIF_GPD_AP }, // [74] CCCI_CCMNI5_RX           
        {CCIFC_RXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [75] CCCI_CCMNI5_RX_ACK     //No use  
        {CCIFC_RXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [76] CCCI_CCMNI5_TX           
        {CCIFC_TXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CCIF_GPD_AP }, // [77] CCCI_CCMNI5_TX_ACK       //No use
        {CCIFC_TXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [78] CCCI_CCMNI5_DLACK_RX 
        /*[NET] 6290 PDN 6*/
        {CCIFC_TXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CCIF_GPD_AP }, // [79] CCCI_CCMNI6_RX           
        {CCIFC_RXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [80] CCCI_CCMNI6_RX_ACK     //No use  
        {CCIFC_RXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [81] CCCI_CCMNI6_TX           
        {CCIFC_TXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CCIF_GPD_AP }, // [82] CCCI_CCMNI6_TX_ACK       //No use
        {CCIFC_TXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [83] CCCI_CCMNI6_DLACK_RX 
        /*[NET] 6290 PDN 7*/
        {CCIFC_TXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CCIF_GPD_AP }, // [84] CCCI_CCMNI7_RX           
        {CCIFC_RXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [85] CCCI_CCMNI7_RX_ACK     //No use  
        {CCIFC_RXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [86] CCCI_CCMNI7_TX           
        {CCIFC_TXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CCIF_GPD_AP }, // [87] CCCI_CCMNI7_TX_ACK       //No use
        {CCIFC_TXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [88] CCCI_CCMNI7_DLACK_RX 
        /*[NET] 6290 PDN 8*/
        {CCIFC_TXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CCIF_GPD_AP }, // [89] CCCI_CCMNI8_RX           
        {CCIFC_RXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [90] CCCI_CCMNI8_RX_ACK     //No use  
        {CCIFC_RXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [91] CCCI_CCMNI8_TX           
        {CCIFC_TXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,           NULL, CCCI_TYPE_CCIF_GPD_AP }, // [92] CCCI_CCMNI8_TX_ACK       //No use
        {CCIFC_TXQ_Q5, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,  NULL, CCCI_TYPE_CCIF_GPD_AP }, // [93] CCCI_CCMNI8_DLACK_RX 
    },
	//CCCI_PEER_ID_MD1_MD2 
	// TODO: Define MD1 & MD2 channel config
	/*CCCI_FORCE_RESET_MODEM_CHANNEL  = 20090215*/                                                   
    /*Special condition: AP request MD to assert*/
};
#else
/* undefined HIF HW */
static ccci_ch_handle ccci_ch_info[CCCI_PEER_ID_MAX][CCCI_MAX_CHANNEL];
    
#endif

/*!
 *  @brief  ccci_get_ch_info returns the pointer of channel information structure
 *  @param  CCCI_CH_NO    CCCI channel number
 *  @return   ccci_ch_handle
 */
ccci_ch_handle* ccci_get_ch_info(CCCI_CHANNEL_T CCCI_CH_NO){
	kal_uint8 peer_id = GET_PEER_ID(CCCI_CH_NO);
	kal_uint32 peer_channel = GET_PEER_CHANNEL(CCCI_CH_NO);
    EXT_ASSERT(peer_channel < CCCI_MAX_CHANNEL, (kal_uint32)CCCI_CH_NO, CCCI_MAX_CHANNEL,0);
	ASSERT(peer_id < CCCI_PEER_ID_MAX);
	ASSERT(peer_id >= CCCI_PEER_ID_MIN);
    return &ccci_ch_info[peer_id][peer_channel];
}



/*MT6575 CCCI channels for reference*/
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
