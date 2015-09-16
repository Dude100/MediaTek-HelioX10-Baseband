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
 *   hif_sdio.h
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 * driver header of SDIO device IP
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
 * 	Merging
 *  	
 * 	//MOLY_CBr/cs.huang/MOLY_CCCI.Seq.Trace.W1427P1/mcu/...
 *  	
 * 	to //MOLY/BRANCHES_LR9/LR9.W1423.MD.LWTG.MP/mcu/...
 *
 * removed!
 * removed!
 * Add flag to ENABLE_FORMAL_SLEEP_SDIO
 *
 * removed!
 * removed!
 * 	SDIO sleep related code submit
 *
 * removed!
 * removed!
 * Add normal parameter init in extcept init API
 *
 * removed!
 * removed!
 * Change project name to MT6290
 *
 * removed!
 * removed!
 * modify the way of setting int mask to reduce times of DL int
 * Add a API of check UL done to reduce MIPS
 *
 * removed!
 * removed!
 * update hifsdio_init_phase2 & API in except
 ****************************************************************************/


#ifndef __HIF_SDIO_H__
#define __HIF_SDIO_H__

#include "kal_public_api.h"

#define HIFSDIO_MAX_ULQ_NUM 7
#define HIFSDIO_MAX_DLQ_NUM 4

#ifdef MTK_SLEEP_ENABLE
#define ENABLE_FORMAL_SLEEP_SDIO
#endif

#define SDIOReg_Write8(addr,data)	\
	(*((volatile kal_uint8 *)(addr))) = data

#define SDIOReg_Write16(addr,data)	\
	(*((volatile kal_uint16 *)(addr))) = data

#define SDIOReg_Write32(addr,data)	\
	(*((volatile kal_uint32 *)(addr))) = data

#define SDIOReg_Read8(addr)	\
	*(volatile kal_uint8 *)(addr)

#define SDIOReg_Read16(addr)	\
	*(volatile kal_uint16 *)(addr)

#define SDIOReg_Read32(addr)	\
	*(volatile kal_uint32 *)(addr)


/*!
 *  @brief hifsdio_isr_mask is used to record the interrupt enable bitmap mask
 */
typedef struct _hifsdio_isr_en_mask{
	kal_uint32	GLO_INTR_En_Msk;
	kal_uint16	SW_INTR_En_Msk;
    kal_uint16	FW_INTR_En_Msk;
    kal_uint32	UL0_INTR_En_Msk;
    kal_uint32	DL0_INTR_En_Msk;
    kal_uint32	DL1_INTR_En_Msk;
    
} hifsdio_isr_en_mask_t;


typedef struct _hifsdio_isr_status{
	kal_uint32	GLO_INTR_Status;
	kal_uint16	SW_INTR_Status;
    kal_uint16	FW_INTR_Status;
    kal_uint32	UL0_INTR_Status;
    kal_uint32	DL0_INTR_Status;
    kal_uint32	DL1_INTR_Status;
    
} hifsdio_isr_status_t;


typedef enum _hifsdio_isr_mask_code{
    GLO_INTR_Msk = 0,
    SW_INTR_Msk,
    FW_INTR_Msk,
    UL0_INTR_Set_Msk,
	UL0_INTR_Clr_Msk,
    DL0_INTR_Msk,
    DL1_INTR_Msk,
    SET_ALL_Msk = 0xFF,
}hifsdio_isr_mask_e;


typedef struct _hifsdio_queue_config {
    /*!
     *  @brief   the head pointer of the GPD which preserve in FW, not hang on the QMU HW yet. 
     */
    void    *head_ptr_preserve;

   /*!
     *  @brief   the tail pointer of the GPD which preserve in FW, not hang on the QMU HW yet. 
     */
    void    *tail_ptr_preserve;

   /*!
     *  @brief   the total number of GPDs which preserve in FW, not hang on the QMU HW yet. 
     */
    kal_uint32  num_preserve;
    
} hifsdio_queue_config_t;



typedef struct _hifsdio_property {

    /*!
     *  @brief total UL QMU queues requested to configure
     */
    kal_uint8           ulq_num;
    /*!
     *  @brief total DL QMU queues requested to configure
     */
    kal_uint8           dlq_num;
    /*!
     *  @brief reserve for 4 bytes alignment
     */
    kal_uint8           reserve[2];    
    
     /*!
     *  @brief  set the checksum function of QMU is enable or not
     */
    kal_bool            checksum_en;

    /*!
     *  @brief  set the checksum bytes, KAL_FALSE = use 12bytes checksum
     *             Notice : the SDIO IP only has 16bytes checksum now, 12bytes ability will be added in future. 
     */
    kal_bool            checksum_16bytes;
        
    /*!
     *  @brief  set whether IOC function of DL queue is diable or not
     *             (if disable, the interrupt will occurs when each GPD is transfered done no matter the IOC bit of GPD)
     */
    kal_bool            dl_ioc_dis[HIFSDIO_MAX_DLQ_NUM];

    
   /*!
     *  @brief sdio_isr_cb_func is the call back function for ISR
     */
    void    (*sdio_isr_cb_func)(hifsdio_isr_status_t sdio_int_status);

} hifsdio_property_t;


#define H2D_INT_CCCI_force_MD_assert  (5)


/*!
 *  @brief AP_CCCI_ASSERT_CB is used for AP CCCI assert MD through SDIO SW INT
 */
typedef void (*AP_CCCI_ASSERT_CB)(void);  



/*!
 *  @brief  initialize sdio hif driver 
 *  @param
 *  @return KAL_TRUE if initial success , 
 		   KAL_FALSE if initial failure.
 */
kal_bool hifsdio_init();

/*!
 *  @brief  initialize sdio hif driver phase2, which related to qbm & ISR
 *  @param
 *  @return KAL_TRUE if initial success ,
                   KAL_FALSE if initial failure.
 */
kal_bool hifsdio_init_phase2();

/*!
 *  @brief  ask sdio hif driver to set this property
 *  @param  property    the property sdiocore will set
 *  @return KAL_TRUE if the property can be satisfied, otherwise KAL_FALSE
 */
kal_bool hifsdio_set_property(hifsdio_property_t* p_sdio_property);


/*!
 *  @brief  shutdown sdio hif driver, detach LISR/HISR , 
 *			need to re-initial sdio driver after shut down
 */
void hifsdio_shutdown();

/*!
 *  @brief  record and log the sdio ip hardware information.
 *  @param  p_hw_inof , used to record the hw info 
 */
// void hifsdio_get_hw_info(hifsdio_hw_info_t* p_hw_info);

/*!
 *  @brief  set D2H interrupt (SW interrupt to host)
 *  @param  set_fw_own_back , if want to set fw own back int
 *  @param  sw_int_num , the number of the sw interrupt which want to be set
 *                                   (if want to set sw int, the set_fw_own_back param must be KAL_FALSE)
 */
void hifsdio_set_D2H_int(kal_bool set_fw_own_back, kal_uint8 sw_int_num);


/*!
 *  @brief  read H2D mailbox
 *  @param  H2D_mb_num , the mailbox number which want to read
 *  @param  mb_content , the data pointer of read mailbox value
 */
void hifsdio_read_mb(kal_uint8 H2D_mb_num, kal_uint32 *mb_content);


/*!
 *  @brief  read H2D mailbox
 *  @param  D2H_mb_num , the mailbox number which want to write
 *  @param  mb_content , the data pointer of read mailbox value
 */
void hifsdio_write_mb(kal_uint8 D2H_mb_num, kal_uint32 *mb_content);

/*!
 *  @brief   check whether it back to FW site.  
 *  @return  KAL_TRUE if the ownership is back to FW site.
 */
kal_bool hifsdio_check_fw_own(void);

/*!
 *  @brief  give the ownership to host driver 
 */
void hifsdio_give_fw_own(void);


/*!
 *  @brief  enable sleep function when host give own back
 */
void hifsdio_enable_sleep(void);


/*!
 *  @brief  read the FW side interrupt mask value now.
 *  @return  the interrupt mask setting now.
 */
hifsdio_isr_en_mask_t hifsdio_read_int_mask();


/*!
 *  @brief  set the FW side interrupt mask of SDIO
 *  @param  p_isr_mask , the pointer of the mask value we want to set
 *  @param  mask_set ,  select which interrupt mask we want to set
 */
void hifsdio_set_int_mask(hifsdio_isr_en_mask_t *p_isr_mask, hifsdio_isr_mask_e mask_set);


/*!
 *  @brief  to inform host that function is ready, so host can transfer normal data
 *             upper application can call this function after GPDs initial is complete.
 */
void hifsdio_set_func_ready();


/*!
 *  @brief  check whether UL que has new packet received.
 *  @return  the UL que status in bitwise. 0x1 means only que0, 0x3 means que0 & que1 have new packet received. 
 */
kal_uint8 hifsdio_check_UL_newpkt(void);


/*!
 *  @brief  check the initial phase now when exception happens at boot.
 *  @return  0 for SDIO has not init, 1 for phase1 init done, 2 for phase2 init done. 
 */
kal_uint8 hifsdio_except_check_init_stage(void);


/*!
 *  @brief  register the callback functin of CCCI which use to apply assert from AP.
 *  @param  func_cb_ptr, the callback function pointer of CCCI force assert from AP.
 */
void hifsdio_register_AP_force_assert_callback(AP_CCCI_ASSERT_CB func_cb_ptr);



/*!
*  @brief  ask sdio hif driver to set STALL for specified queue
*			stop queue, flush fifo(?) , record current GPD pointer (not supported by HW now)
*  @param  is_tx	KAL_TRUE for tx (D2H), KAL_FALSE for rx(H2D)
*  @param  nQueue		Queue number in request command
*/
// TODO: has not implement, temprarily marked.
//void hifsdio_set_stop(kal_bool is_tx, kal_uint8 nQueue);


/*!
*  @brief  ask sdio hif driver to recover for specified queue
*			restore queue, resume queue,
*  @param  is_tx	KAL_TRUE for tx (D2H), KAL_FALSE for rx(H2D)
*  @param  nQueue       Queue number in request command
*/
// TODO: has not implement, temprarily marked.
//void hifsdio_set_recover(kal_bool is_tx ,kal_uint8 nQueue);

#endif
