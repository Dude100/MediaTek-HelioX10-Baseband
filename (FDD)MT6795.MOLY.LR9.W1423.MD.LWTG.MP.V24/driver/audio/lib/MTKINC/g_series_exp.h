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
 * g_series_exp.h
 *
 * Project:
 * --------
 * SWIP
 *
 * Description:
 * ------------
 * G series codec common header file.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __G_SERIES_EXP_H__
#define __G_SERIES_EXP_H__
#ifndef NULL
#define NULL    0
#endif

typedef struct G_Series_Struct G_Series_Handle;

struct G_Series_Struct{
    /*
        Get required buffer size for G series codec engine
        internal_buffer_size  : output, the required internal buffer size (unit: byte)
        temp_buffer_size      : output, the required temp buffer size (unit: byte)
        pcm_buffer_size       : output, the required PCM buffer size (unit: byte)
        bitstream_buffer_size : output, the required bitstream buffer size (unit: byte)
    */
    void (*GetBufferSize)(  unsigned int *internal_buffer_size ,
                            unsigned int *temp_buffer_size     ,
                            unsigned int *pcm_buffer_size      ,
                            unsigned int *bitstream_buffer_size);

    /*
        Initialize and enable G series codec engine
        p_handle          : input, handle of current G series codec engine
        p_internal_buffer : input, buffer allocated by application for G series 
                            codec engine internal use
        p_temp_buffer     : input, buffer allocated by application for G series 
                            codec engine temporarily use
        p_init_param      : input, pointer to the data that contains parameters 
                            for initialization of G series codec enigne
    */
    int (*Init)(    G_Series_Handle *p_handle,
                    void *p_internal_buffer, 
                    void *p_temp_buffer,
                    const void *p_init_param);
    
    /*
        Process data from input buffer to output buffer
        pHandle               : input, handle of current G series codec engine
        p_temp_buffer         : input, buffer allocated by application for G series 
                                codec engine temporarily use
        p_pcm_buffer          : input, pointer to PCM data buffer
        pcm_buffer_size       : input, size of the PCM buffer (unit: byte)
                                output, size of the consumed / produced PCM buffer (unit: byte)
        p_bitstream_buffer    : input, pointer to bitstream buffer
        bitstream_buffer_size : input, size of the bitstream buffer (unit: byte)
                                output, size of the consumed / produced bitstream buffer (unit: byte)
        p_runtime_param       : input, pointer to the data that contains parameters 
                                for runtime usage of G series codec enigne
    */
    int (*Process)( G_Series_Handle *p_handle,
                    void *p_temp_buffer,
                    short *p_pcm_buffer,
                    int   *pcm_buffer_size,
                    unsigned char *p_bitstream_buffer,
                    int   *bitstream_buffer_size,
                    const void *p_runtime_param);

    /*
        Get the version of the G series codec engine
    */
    int (*GetVersion)(void);

    void *p_internal_handle;
};

#endif // __G_SERIES_EXP_H__

