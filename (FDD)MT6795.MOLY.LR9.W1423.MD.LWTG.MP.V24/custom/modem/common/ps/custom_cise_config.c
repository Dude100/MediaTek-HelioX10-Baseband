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
/*
**   Includes
*/
#include "kal_general_types.h"

#include "custom_cise_config.h"

#ifdef __AS_SPECIFIC_CHANNEL_SRCH__
kal_bool uas_custom_specific_channel_srch = KAL_FALSE;
#endif

/**
 * The specific channels
 * How to use:
 * Max number is define in NUM_OF_SPECIFIC_CHANNELS.
 * If user only want to config UARFCNs less than NUM_OF_SPECIFIC_CHANNELS in some band, just fill invalid UARFCN.
 * For example, if band 1 only need 3 UARFCNs, just fill {10562,10563,10564,0xffff}
 */
kal_uint16 specific_uarfcn[NUM_OF_UMTS_BANDS][NUM_OF_SPECIFIC_CHANNELS]     = 
{
    {10562,10563,10564,10838}, /* band  1 */
    { 9662, 9663, 9664, 9938}, /* band  2 */
    { 1162, 1163, 1164, 1513}, /* band  3 */
    { 1537, 1538, 1539, 1738}, /* band  4 */
    { 4357, 4358, 4359, 4458}, /* band  5 */
    { 4387, 4388, 4389, 4413}, /* band  6 */
    { 2237, 2238, 2239, 2563}, /* band  7 */
    { 2937, 2938, 2939, 3088}, /* band  8 */
    { 9237, 9238, 9239, 9387}, /* band  9 */
    { 3112, 3113, 3114, 3388}, /* band 10 */
    { 3712, 3713, 3714, 3787}, /* band 11 */
    { 3842, 3843, 3844, 3903}, /* band 12 */
    { 4017, 4018, 4019, 4043}, /* band 13 */
    { 4117, 4118, 4119, 4143}, /* band 14 */
    {65535,65535,65535,65535}, /* band 15 *//* !! Reserved !! */
    {65535,65535,65535,65535}, /* band 16 *//* !! Reserved !! */
    {65535,65535,65535,65535}, /* band 17 *//* !! Reserved !! */
    {65535,65535,65535,65535}, /* band 18 *//* !! Reserved !! */
    {  712,  713,  714,  763}, /* band 19 */
    { 4512, 4513, 4514, 4512}, /* band 20 */
    {  862,  867,  868,  912}, /* band 21 */
    { 4662, 4663, 4664, 5038}  /* band 22 */
};


/* For customer to determine support Standard Fast Return or not */

/*****************************************************************************
* FUNCTION
*  CSCE_IsSupportStdFR
*
* DESCRIPTION
*
*  this function allow customer to determine support Standard Fast Return or not
*
* PARAMETERS
*
* RETURNS
*  kal_bool
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_bool CSCE_IsSupportStdFR (void)
{
    /********************************************* 
     KAL_TRUE: support Standard Fast Return 
     KAL_FALSE: not support Standard Fast Return 
    *********************************************/
   return KAL_TRUE;
   //return KAL_FALSE;
}

/*****************************************************************************
* FUNCTION
*  uas_custom_is_specific_channel_srch
* DESCRIPTION
*   The function returns whether UE is in specific channel search mode.
*
* PARAMETERS
*  Void
* RETURNS
*  kal_bool
*  TRUE: specific channel search mode, FALSE: normal search mode
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_bool uas_custom_is_specific_channel_srch(void)
{
#ifdef __AS_SPECIFIC_CHANNEL_SRCH__
    return uas_custom_specific_channel_srch;
#else
    return KAL_FALSE;
#endif 
}

#ifdef __AS_SPECIFIC_CHANNEL_SRCH__
/*****************************************************************************
* FUNCTION
*  uas_custom_set_specific_channel_srch
* DESCRIPTION
*   The function set specific search mode.
*
* PARAMETERS
*   kal_bool
*   TRUE: set specific search mode, FALSE: disable specific search mode.
* RETURNS
*   Void
* GLOBALS AFFECTED
*   None
*****************************************************************************/
void uas_custom_set_specific_channel_srch( kal_bool set_value )
{
    uas_custom_specific_channel_srch = set_value;
}
#endif /* __AS_SPECIFIC_CHANNEL_SRCH__ */

/*****************************************************************************
* FUNCTION
*  uas_custom_get_specific_channel
* DESCRIPTION
*   UAS use this function to get specific channel
*
* PARAMETERS
*   band            : which band to get
*   specificChannel : point to return UARFCN
* RETURNS
*  kal_bool         : Success return TRUE
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_bool uas_custom_get_specific_channel( kal_uint8 band, kal_uint16 *specificChannel)
{
    kal_bool ret = KAL_TRUE;
    kal_uint8 i;

    if ((band >= 0) && (band < NUM_OF_UMTS_BANDS))
    {
        for (i=0;i<NUM_OF_SPECIFIC_CHANNELS;i++)
        {
            *(specificChannel + i) = specific_uarfcn[band][i];
        }
    }
    else
    {
        ret = KAL_FALSE;
    }

    return ret;
}

/*****************************************************************************
* FUNCTION
*  uas_custom_set_specific_channel
* DESCRIPTION
*   use this function to set specific channel
*
* PARAMETERS
*   band            : which band to set
*   specificChannel : UARFCN to set
* RETURNS
*  kal_bool         : Success return TRUE
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_bool uas_custom_set_specific_channel( kal_uint8 band, kal_uint16 *specificChannel)
{
    kal_bool ret = KAL_TRUE;
    kal_uint8 i;

    /**
     * We'll not check input UARFCN here.
     * When UAS use specific channel, UAS will check:
     *  1> UARFCN is valid or not
     *  2> UARFCN is in UE support band or not
     */
    if ((band >= 0) && (band < NUM_OF_UMTS_BANDS))
    {
        for (i=0;i<NUM_OF_SPECIFIC_CHANNELS;i++)
        {
            specific_uarfcn[band][i] = *(specificChannel + i);
        }
    }
    else
    {
        ret = KAL_FALSE;
    }

    return ret;
}

