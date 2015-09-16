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
 *   mdif.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file of MDIF.
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
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __MDIF_H__
#define __MDIF_H__

/*******************************************************************************
 * Include header files
 *******************************************************************************/
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "reg_base.h"
#include "intrCtrl.h"


/*************************************************************************
 * Define data structure
 *************************************************************************/

#if defined(__DSP_FCORE4__)



/*******************************************************************************
 * Define data structure.
 *******************************************************************************/

/* MDIF API return value */
typedef enum
{
    MDCI_SUCCESS = 0,
    MDCI_FAIL = -1,
    MDCI_IN_USE = -2,
    MDCI_NOT_OWNER = -3,
    MDCI_INVALID_PARAM = -4,
    MDCI_NO_PHY_CHANNEL = -5,
    MDCI_IN_LISR = -6,
    MDCI_NOT_RECEIVE = -7,
    MDCI_API_INVALID = -8
}MDCI_RETURNVAL_T;


/* MDIF logical channel */
/*      NOTICE: Negotiations With AP Owner Before Modification */
typedef enum
{
    MDCI_CONTROL_CHANNEL_M2D = 0,
    MDCI_CONTROL_CHANNEL_D2M =1,
    MDCI_SYSTEM_CHANNEL_M2D = 2,
    MDCI_SYSTEM_CHANNEL_D2M = 3,
    MDCI_VIDEO_CHANNEL_M2D = 4,
    MDCI_VIDEO_CHANNEL_D2M = 5,
    MDCI_AUDIO_CHANNEL_M2D = 6,
    MDCI_AUDIO_CHANNEL_D2M = 7,
    MDCI_SPEECH_CHANNEL_M2D = 8,
    MDCI_SPEECH_CHANNEL_D2M = 9,
    MDCI_USBLOG_CHANNEL_M2D = 10,
    MDCI_USBLOG_CHANNEL_D2M = 11,
    MDIF_EXCPT_CHANNEL_M2D = 12,
    MDIF_EXCPT_CHANNEL_D2M = 13,
    MDCI_SYSSTA_CHANNEL_M2D = 14,
    MDCI_SYSSTA_CHANNEL_D2M = 15,
    MDCI_TST_CHANNEL_M2D = 16,
    MDCI_TST_CHANNEL_D2M = 17,
    MDCI_SLT_INFO_CHANNEL_M2D = 18,
    MDCI_SLT_INFO_CHANNEL_D2M = 19,
    MDCI_MAX_CHANNEL = 20,
    MDCI_FORCE_RESET_MODEM_CHANNEL = 20090215
} MDCI_CHANNEL_T;

/* MDIF mailbox channel structure */
typedef struct
{
    kal_uint32 magic;   /* 0xFFFFFFFF */
    kal_uint32 id;
} MDCI_MAILBOX_T;

/* MDIF stream channel structure */
typedef struct
{
    kal_uint32 addr;
    kal_uint32 len;
} MDCI_STREAM_T;

/* MDIF channel buffer structure */
typedef struct
{
    kal_uint32 data[2];
    kal_uint32 channel;
    kal_uint32 reserved;
} MDCI_BUFF_T;

/* MDIF callback function prototype */
typedef void (*MDCI_CALLBACK)(MDCI_BUFF_T *buff);

/* MDIF status */
typedef enum
{
    MDCI_IDLE = 0x00,
    MDCI_ACTIVE_READ = 0x01,
    MDCI_ACTIVE_WRITE = 0x02,
    MDCI_ACTIVE_ISR = 0x04
} MDCI_STATE_T;


/* MDIF control structure */
typedef struct
{
    MDCI_STATE_T state;
    kal_uint32 owner;
    MDCI_BUFF_T buff;
    MDCI_CALLBACK funp;
    kal_eventgrpid event;

} MDCI_CTRL_T;

/* MDIF Message ID Passing Through CONTROL_CHANNEL */
/*      NOTICE: Negotiations With AP Owner Before Modification */
typedef enum
{
    MDCIMSG_ID_START_BOOT        = 0x00000000,
    MDCIMSG_ID_NORMAL_BOOT_READY = 0x00000001,
    MDCIMSG_ID_META_BOOT_READY   = 0x00000002,
    MDCIMSG_ID_RESET             = 0x00000003,
    MDCIMSG_ID_EXCEPTION_CHECK   = 0x00000004,
    MDCIMSG_ID_DRV_VERSION_ERR   = 0x00000005,
    MDCIMSG_ID_EXCEPTION_REC_OK  = 0x00000006
}MDCI_CONTROL_CHANNEL_MSG;


/*******************************************************************************
 * Define marco.
 *******************************************************************************/

/* initialize a MDIF mailbox buffer */
#define MDCI_INIT_MAILBOX(buff, mailbox_id) \
        do {    \
            ((MDCI_MAILBOX_T *)(buff))->magic = 0xFFFFFFFF; \
            ((MDCI_MAILBOX_T *)(buff))->id = (mailbox_id);  \
            (buff)->channel = MDCI_MAX_CHANNEL;  \
            (buff)->reserved = 0;    \
        } while (0)

/* initialize a MDIF stream buffer */
#define MDCI_INIT_STREAM(buff, stream_addr, stream_len) \
        do {    \
            ((MDCI_STREAM_T *)(buff))->addr = (stream_addr); \
            ((MDCI_STREAM_T *)(buff))->len = (stream_len);  \
            (buff)->channel = MDCI_MAX_CHANNEL;  \
            (buff)->reserved = 0;    \
        } while (0)

/* check the MDIF buffer type */
#define MDCI_IS_MAILBOX(buff)   ((((MDCI_MAILBOX_T *)(buff))->magic == 0xFFFFFFFF)? 1: 0)

/* get the id of the MDIF mailbox buffer */
#define MDCI_MAILBOX_ID(buff)   (((MDCI_MAILBOX_T *)(buff))->id)

/* get the addr of the MDIF stream buffer */
#define MDCI_STREAM_ADDR(buff)   (((MDCI_STREAM_T *)(buff))->addr)

/* get the len of the MDIF stream buffer */
#define MDCI_STREAM_LEN(buff)   (((MDCI_STREAM_T *)(buff))->len)




/*******************************************************************************
 * Declare function prototype.
 * User APIs
 *******************************************************************************/

extern kal_int32    mdci_init(MDCI_CHANNEL_T channel, MDCI_CALLBACK funp);
extern kal_int32    mdci_deinit(MDCI_CHANNEL_T channel);
extern kal_int32    mdci_stream_write(MDCI_CHANNEL_T channel, kal_uint32 addr, kal_uint32 len);
extern kal_int32    mdci_stream_read(MDCI_CHANNEL_T channel, kal_uint32 *addr, kal_uint32 *len);
extern kal_int32    mdci_stream_read_with_reserved(MDCI_CHANNEL_T channel, kal_uint32 *addr, kal_uint32 *len, kal_uint32 *reserved);
extern kal_int32    mdci_stream_write_with_reserved(MDCI_CHANNEL_T channel, kal_uint32 addr, kal_uint32 len,kal_uint32 reserved);
extern kal_int32    mdci_mailbox_write(MDCI_CHANNEL_T channel, kal_uint32 id);
extern kal_int32    mdci_mailbox_read(MDCI_CHANNEL_T channel);
extern kal_int32    mdci_mailbox_write_with_reserved(MDCI_CHANNEL_T channel, kal_uint32 id,kal_uint32 reserved);
extern kal_int32    mdci_mailbox_read_with_reserved(MDCI_CHANNEL_T channel,kal_uint32 *reserved);
extern kal_int32    mdci_mailbox_write_and_wait(MDCI_CHANNEL_T channel, kal_uint32 id, kal_uint32 ticks);
extern kal_int32    mdci_stream_write_and_wait(MDCI_CHANNEL_T channel, kal_uint32 addr, kal_uint32 len,kal_uint32 ticks);
extern kal_int32    mdci_mailbox_read_and_wait(MDCI_CHANNEL_T channel, kal_uint32 ticks);
extern kal_int32    mdci_stream_read_and_wait(MDCI_CHANNEL_T channel, kal_uint32 *addr, kal_uint32 *len,kal_uint32 ticks);




/*******************************************************************************
 * Declare function prototype.
 * Kernel/System Use APIs
 *******************************************************************************/

extern kal_int32    mdci_read(MDCI_CHANNEL_T channel, MDCI_BUFF_T *buff);
extern kal_uint32   mdci_read_and_wait(MDCI_CHANNEL_T channel, MDCI_BUFF_T *buff, kal_uint32 ticks);

extern kal_int32    mdci_write_internal(MDCI_CHANNEL_T channel, MDCI_BUFF_T *buff,kal_bool check_lisr);
#define mdci_write(a,b) mdci_write_internal(a,b,1)
extern kal_int32    mdci_owner_init(MDCI_CHANNEL_T channel, kal_taskid task, MDCI_CALLBACK funp);
extern kal_uint32   mdci_query_sharemem_addr(MDCI_CHANNEL_T channel,kal_uint32 *size);
extern void         mdci_change_owner_only(MDCI_CHANNEL_T channel,kal_uint8 owner);
extern void         mdci_hw_init(kal_uint32 arb, kal_uint32 md_offset);
extern kal_bool     mdci_Check_If_Log_In_Phy(kal_uint32 query_log, kal_bool Is_Ack_All_if_found);
extern void         mdci_init_handshake_phase1(void);
extern void         mdci_init_handshake_phase2(kal_uint16 _boot_mode);


#endif /* #if defined(__DSP_FCORE4__) */

#endif  /* !__MDIF_H__ */


