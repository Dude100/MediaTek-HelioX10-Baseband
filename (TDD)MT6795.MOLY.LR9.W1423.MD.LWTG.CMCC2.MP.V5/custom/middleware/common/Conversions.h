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

/*******************************************************************************
 * Filename:
 * ---------
 * Conversions.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines constant, enum value, and structures for converting 
 *    realted utilities.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_CONVERSIONS_H
#define _MMI_CONVERSIONS_H
#include "kal_public_api.h" //MSBB change #include "kal_release.h"

#if !defined(NEPTUNE_MMI)
#include "kal_general_types.h"
#endif

#ifndef FALSE
  #define FALSE           0
#endif
#define TRUE            1
#define UNKOWN_UCS2_CHAR   0xFFEB

typedef enum
{
    BIG_5_ENCODING_TYPE,
    GB2312_ENCODING_TYPE,
    HKSCS_ENCODING_TYPE,
    NO_OF_TEXT_ENCODING
} TextEncodingEnum;

typedef struct
{
    short start;
    short end;
} key_index_t;

/*-- function prototypes --*/

extern kal_uint16 mmi_chset_wchar_to_ucs2(kal_uint16 encode_char, TextEncodingEnum encoding);
extern kal_uint16 mmi_chset_ucs2_to_wchar(kal_uint16 ucs2_char, TextEncodingEnum encoding);

extern kal_uint16 mmi_chset_text_to_ucs2_str(
                    kal_uint8 *dest,
                    kal_int32 dest_size,
                    kal_uint8 *src,
                    TextEncodingEnum encoding);
extern kal_uint16 mmi_chset_text_to_ucs2_str_ex(
                    kal_uint8 *dest,
                    kal_int32 dest_size,
                    kal_uint8 *src,
                    TextEncodingEnum encoding,
                    kal_uint32 *src_end_pos);

extern kal_uint16 mmi_chset_ucs2_to_text_str(
                    kal_uint8 *dest,
                    kal_int32 dest_size,
                    kal_uint8 *src,
                    TextEncodingEnum encoding);
extern kal_uint16 mmi_chset_ucs2_to_text_str_ex(
                    kal_uint8 *dest,
                    kal_int32 dest_size,
                    kal_uint8 *src,
                    TextEncodingEnum encoding,
                    kal_uint32 *src_end_pos);

extern kal_uint8 mmi_chset_is_text_in_str(kal_uint8 *src);

/*-- exposed global data --*/

extern const kal_uint8 *g_ucs2_to_encode_key_MSB[NO_OF_TEXT_ENCODING];
extern const kal_uint8 *g_encode_to_ucs2_key_MSB[NO_OF_TEXT_ENCODING];
extern const kal_uint16 *g_ucs2_to_encode_table[NO_OF_TEXT_ENCODING];
extern const kal_uint16 *g_encode_to_ucs2_table[NO_OF_TEXT_ENCODING];
extern const kal_uint16 g_unknown_encode_char[NO_OF_TEXT_ENCODING];
extern const kal_uint16 *g_text_encoding_name[NO_OF_TEXT_ENCODING];

#define CHSET_MAX_COUNT             25
#define CHSET_BIT_WORD_16           16
#define CHSET_BIT_WORD_8            8
#define CHSET_TMP_BUFF_SIZE         2048        /* the size of the temp buffer in mmi_chset_convert() */

/* Supported Guess Charsets */
#define CHSET_GUESS_ALL				0x00000000
#define CHSET_GUESS_UTF8			0x00000001
#define CHSET_GUESS_UTF16LE			0x00000002
#define CHSET_GUESS_UTF16BE			0x00000004
#define CHSET_GUESS_UCS2			0x00000008
#define CHSET_GUESS_GB2312			0x00000010
#define CHSET_GUESS_BIG5			0x00000020
#define CHSET_GUESS_WESTERN_ISO		0x00000040
#define CHSET_GUESS_HKSCS                0x00000080

#define CHSET_LANG_MAP_SIZE   5

/* Enum of all supported charsets*/
typedef enum
{
    CHSET_BASE,
    MMI_CHSET_BASE = CHSET_BASE,
    CHSET_ASCII,
    MMI_CHSET_ASCII = CHSET_ASCII, // ASCII
    CHSET_ARABIC_ISO, 
    MMI_CHSET_ARABIC_ISO = CHSET_ARABIC_ISO, // ISO 8859-6 (Arabic)
    CHSET_ARABIC_WIN,
    MMI_CHSET_ARABIC_WIN = CHSET_ARABIC_WIN, // Windows-1256 (Arabic)
    CHSET_PERSIAN_CP1097,
    MMI_CHSET_PERSIAN_CP1097 = CHSET_PERSIAN_CP1097, // CP1097  (Persian) 
    CHSET_PERSIAN_CP1098,
    MMI_CHSET_PERSIAN_CP1098 = CHSET_PERSIAN_CP1098, // CP1098  (Persian)
    CHSET_BALTIC_ISO,
    MMI_CHSET_BALTIC_ISO = CHSET_BALTIC_ISO, // ISO-8859-4 (Baltic language group)
    CHSET_BALTIC_WIN,
    MMI_CHSET_BALTIC_WIN = CHSET_BALTIC_WIN, // Windows-1257 (Baltic language group)
    CHSET_CEURO_ISO,
    MMI_CHSET_CEURO_ISO = CHSET_CEURO_ISO, // ISO-8859-2 (Central european language group)
    CHSET_CEURO_WIN,
    MMI_CHSET_CEURO_WIN = CHSET_CEURO_WIN, // Windows-1250 (Central european language group)
    CHSET_CYRILLIC_ISO,
    MMI_CHSET_CYRILLIC_ISO = CHSET_CYRILLIC_ISO, // ISO-8859-5 (Cyrillic script based languages)
    CHSET_CYRILLIC_WIN,
    MMI_CHSET_CYRILLIC_WIN = CHSET_CYRILLIC_WIN, // Windows-1251 (Cyrillic script)
    CHSET_GREEK_ISO,
    MMI_CHSET_GREEK_ISO = CHSET_GREEK_ISO, // ISO-8859-7 (Greek)
    CHSET_GREEK_WIN,
    MMI_CHSET_GREEK_WIN = CHSET_GREEK_WIN, // Windows-1253 (Greek)
    CHSET_HEBREW_ISO,
    MMI_CHSET_HEBREW_ISO = CHSET_HEBREW_ISO, // ISO-8859-8 (Hebrew)
    CHSET_HEBREW_WIN,
    MMI_CHSET_HEBREW_WIN = CHSET_HEBREW_WIN, // Windows-1255 (Hebrew)
    CHSET_LATIN_ISO,
    MMI_CHSET_LATIN_ISO = CHSET_LATIN_ISO, // ISO-8859-4 (North european language group)
    CHSET_NORDIC_ISO,
    MMI_CHSET_NORDIC_ISO = CHSET_NORDIC_ISO, // ISO-8859-10 (Nordic language group)
    CHSET_SEURO_ISO,
    MMI_CHSET_SEURO_ISO = CHSET_SEURO_ISO,  // ISO-8859-3 (South european language group)
    CHSET_TURKISH_ISO,
    MMI_CHSET_TURKISH_ISO = CHSET_TURKISH_ISO, // ISO-8859-9 (Turkish)
    CHSET_TURKISH_WIN,
    MMI_CHSET_TURKISH_WIN = CHSET_TURKISH_WIN, // Windows-1254 (Turkish)
    CHSET_WESTERN_ISO,
    MMI_CHSET_WESTERN_ISO = CHSET_WESTERN_ISO, // ISO-8859-1 (Latin script based languages)
    CHSET_ARMENIAN_ISO,
    MMI_CHSET_ARMENIAN_ISO  = CHSET_ARMENIAN_ISO, // ISO-10585 ARMSCII (Armenian)
	CHSET_THAI_WIN,
    MMI_CHSET_THAI_WIN = CHSET_THAI_WIN, // Windows-874 (Thai)
    CHSET_VIETNAMESE_WIN,
    MMI_CHSET_VIETNAMESE_WIN = CHSET_VIETNAMESE_WIN,  // Windows-1258 (Vietnamese)
    CHSET_KOI8_R,
    MMI_CHSET_KOI8_R = CHSET_KOI8_R,  // KOI8-russian 
    CHSET_TIS_620,
    MMI_CHSET_TIS_620 = CHSET_TIS_620,  // Thai Industrial Standard 620
    CHSET_WESTERN_WIN,
    MMI_CHSET_WESTERN_WIN = CHSET_WESTERN_WIN, // Windows-1252 (Latin script based languages)
    
    /* Add new (8-bit) encodings above this line */
    
    CHSET_BIG5,
    MMI_CHSET_BIG5 = CHSET_BIG5,  // Big5 (Traditional chinese)
    CHSET_GB2312,
    MMI_CHSET_GB2312 = CHSET_GB2312, // GB2312 (Simplified chinese)
    CHSET_HKSCS,
    MMI_CHSET_HKSCS = CHSET_HKSCS,  // HKSCS 2004 (Hong Kong chinese)
    CHSET_SJIS,
    MMI_CHSET_SJIS = CHSET_SJIS,  // SJIS (Japanese)
    CHSET_GB18030,
    MMI_CHSET_GB18030 = CHSET_GB18030, // GB18030 (Simplified chinese-extended)
    CHSET_UTF7,
    MMI_CHSET_UTF7 = CHSET_UTF7,  // UTF-7 
    CHSET_EUCKR,
    MMI_CHSET_EUCKR = CHSET_EUCKR, // Extended Unix Code - korean

    /* Place all CJK encodings above this one */

    CHSET_UTF16LE,
    MMI_CHSET_UTF16LE = CHSET_UTF16LE, // UTF-16LE
    CHSET_UTF16BE,
    MMI_CHSET_UTF16BE = CHSET_UTF16BE, // UTF-16BE
    CHSET_UTF8,
    MMI_CHSET_UTF8 = CHSET_UTF8,  // UTF-8
    CHSET_UCS2,
    MMI_CHSET_UCS2 = CHSET_UCS2,  // UCS2
    CHSET_TOTAL,
    MMI_CHSET_TOTAL = CHSET_TOTAL 
} mmi_chset_enum, chset_enum;

/* do not change the order */

/* Enum of all supporte charset pairs */

typedef enum _ENCODING_SCHEMES_ENUM
{
    BASE_ENCODING_SCHEME,

    ASCII_TO_UCS2,
    UCS2_TO_ASCII,   

    ARABIC_ISO_TO_UCS2,
    UCS2_TO_ARABIC_ISO,

    ARABIC_WINDOWS_TO_UCS2,
    UCS2_TO_ARABIC_WINDOWS,
    
    PERSIAN_CP1097_TO_UCS2,
    UCS2_TO_PERSIAN_CP1097,

    PERSIAN_CP1098_TO_UCS2,
    UCS2_TO_PERSIAN_CP1098,
    
    BALTIC_ISO_TO_UCS2,
    UCS2_TO_BALTIC_ISO,

    BALTIC_WINDOWS_TO_UCS2,
    UCS2_TO_BALTIC_WINDOWS,

    CENTRAL_EUROPEAN_ISO_TO_UCS2,
    UCS2_TO_CENTRAL_EUROPEAN_ISO,

    CENTRAL_EUROPEAN_WINDOWS_TO_UCS2,
    UCS2_TO_CENTRAL_EUROPEAN_WINDOWS,

    CYRILLIC_ISO_TO_UCS2,
    UCS2_TO_CYRILLIC_ISO,

    CYRILLIC_WINDOWS_TO_UCS2,
    UCS2_TO_CYRILLIC_WINDOWS,
    
    GREEK_ISO_TO_UCS2,
    UCS2_TO_GREEK_ISO,

    GREEK_WINDOWS_TO_UCS2,
    UCS2_TO_GREEK_WINDOWS,

    HEBREW_ISO_TO_UCS2,
    UCS2_TO_HEBREW_ISO,

    HEBREW_WINDOWS_TO_UCS2,
    UCS2_TO_HEBREW_WINDOWS,

    LATIN_ISO_TO_UCS2,
    UCS2_TO_LATIN_ISO,

    NORDIC_ISO_TO_UCS2,
    UCS2_TO_NORDIC_ISO,

    SOUTH_EUROPEAN_ISO_TO_UCS2,
    UCS2_TO_SOUTH_EUROPEAN_ISO,

    TURKISH_ISO_TO_UCS2,
    UCS2_TO_TURKISH_ISO,

    TURKISH_WINDOWS_TO_UCS2,
    UCS2_TO_TURKISH_WINDOWS,

    WESTERN_ISO_TO_UCS2,
    UCS2_TO_WESTERN_ISO,

    ARMENIAN_ISO_TO_UCS2,
    UCS2_TO_ARMENIAN_ISO,
    
    THAI_WINDOWS_TO_UCS2,
    UCS2_TO_THAI_WINDOWS,

    VIETNAMESE_WINDOWS_TO_UCS2,
    UCS2_TO_VIETNAMESE_WINDOWS,

    KOI8_R_TO_UCS2,
    UCS2_TO_KOI8_R,

    TIS_620_TO_UCS2,
    UCS2_TO_TIS_620,
    
    WESTERN_WINDOWS_TO_UCS2,
    UCS2_TO_WESTERN_WINDOWS,

    /* Add new (8-bit) encodings above this line */
    BIG5_TO_UCS2,
    UCS2_TO_BIG5,

    GB2312_TO_UCS2,
    UCS2_TO_GB2312,

    HKSCS_TO_UCS2,
    UCS2_TO_HKSCS,

    SJIS_TO_UCS2,
    UCS2_TO_SJIS,

    GB18030_TO_UCS2,
    UCS2_TO_GB18030,

    UTF7_TO_UCS2,
    UCS2_TO_UTF7,

    EUCKR_WINDOWS_TO_UCS2,
    UCS2_TO_EUCKR_WINDOWS,

    /* Place all CJK encodings above this one */
    UTF16LE_TO_UCS2,
    UCS2_TO_UTF16LE,
    
    UTF16BE_TO_UCS2,
    UCS2_TO_UTF16BE,
    
    UTF8_TO_UCS2,
    UCS2_TO_UTF8,

    CHSET_PAIR_TOTAL
} mmi_chset_pair_enum;

/* Global variable to hold curent default encoding in phone 
   This value will be updated by MMI phone setup module */
extern mmi_chset_enum g_chset_text_encoding;    

extern kal_uint16 EncodingDecoding(
                    mmi_chset_pair_enum Scheme,
                    char *pOutBuffer,
                    char *pInBuffer,
                    kal_int32 dest_size,
                    kal_uint32 *src_end_pos);

/*****************************************************************************
 * FUNCTION
 *  mmi_chset_init
 * DESCRIPTION
 *  Routine for initializing the related data structures of the various encoding types
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_chset_init(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_chset_convert
 * DESCRIPTION
 *  Convert string between 2 character sets. (will add the terminate character)
 * PARAMETERS
 *  src_type        :   [IN]        Charset type of source
 *  dest_type       :   [IN]        Charset type of destination
 *  src_buff        :   [IN]        Buffer stores source string
 *  dest_buff       :   [OUT]       Buffer stores destination string
 *  dest_size       :   [IN]        Size of destination buffer (bytes)
 * RETURNS
 *  Length of destination string, including null terminator. (bytes)
 *****************************************************************************/
extern kal_int32 mmi_chset_convert(
                    mmi_chset_enum src_type,
                    mmi_chset_enum dest_type,
                    char *src_buff,
                    char *dest_buff,
                    kal_int32 dest_size);

extern kal_int32 mmi_chset_convert_ex(
                    mmi_chset_enum src_type,
                    mmi_chset_enum dest_type,
                    char *src_buff,
                    char *dest_buff,
                    kal_int32 dest_size,
                    kal_uint32 *src_end_pos);

extern kal_int32 chset_convert(
                    chset_enum src_type,
                    chset_enum dest_type,
                    char *src_buff,
                    char *dest_buff,
                    kal_int32 dest_size);

extern kal_int32 chset_convert_ex(
                    chset_enum src_type,
                    chset_enum dest_type,
                    char *src_buff,
                    char *dest_buff,
                    kal_int32 dest_size,
                    kal_uint32 *src_end_pos);

/*****************************************************************************
 * FUNCTION
 *  mmi_chset_use_space_for_unknown_character
 * DESCRIPTION
 *  It's a property of charset conversion module. Setting it up would cause invalid character values behave as 'space' character.
 *  It is applicable only with ideographic charsets.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_chset_use_space_for_unknown_character(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_chset_use_space_for_unknown_character
 * DESCRIPTION
 *  It's a property of charset conversion module. Setting it up would cause invalid character values behave as 0xFFFF.
 *  It is applicable only with ideographic charsets.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_chset_do_not_use_space_for_unknown_character(void);

extern kal_int32 mmi_chset_convert_with_src_length(
        mmi_chset_enum src_type,
        mmi_chset_enum dest_type,
        char *src_buff,
        kal_int32 src_size,
        char *dest_buff,
        kal_int32 dest_size);
extern kal_uint16 UCS2_TO_WCHAR(kal_uint16 src_char);

extern void mmi_chset_mixed_text_to_ucs2_str(
                kal_uint8 *dest,
                kal_int16 dest_size,
                kal_uint8 *src,
                mmi_chset_enum encoding);
extern void mmi_chset_mixed_text_to_ucs2_str_ex(
                kal_uint8 *dest,
                kal_int16 dest_size,
                kal_uint8 *src,
                mmi_chset_enum encoding,
                kal_uint32 *src_end_pos);

extern kal_int32 mmi_chset_text_to_ucs2(kal_uint8 *dest, kal_int32 dest_size, kal_uint8 *src);
extern kal_int32 mmi_chset_text_to_ucs2_ex(
                    kal_uint8 *dest,
                    kal_int32 dest_size,
                    kal_uint8 *src,
                    kal_uint32 *src_end_pos);

/*****************************************************************************
 * FUNCTION
 *  mmi_chset_get_char_size_of_charset
 * DESCRIPTION
 *  Get maximum number of bytes, that the given charset can take for a single character
 * PARAMETERS
 *  mmi_chset_enum         :  [IN]        Charset
 * RETURNS
 *  Maximum number of bytes, that chset can take for a single character
 *****************************************************************************/
extern kal_int32 mmi_chset_get_char_size_of_charset(mmi_chset_enum chset);

extern kal_int32 mmi_chset_get_char_size_of_default_charset(void);

/* UTF8 related */

/*****************************************************************************
 * FUNCTION
 *  mmi_chset_utf8_to_ucs2
 * DESCRIPTION
 *  Convert single UTF8 character to UCS2
 * PARAMETERS
 *  ucs2	:  [OUT] Output buffer (Needs at least 2 bytes)
 *  utf8 :  [IN]  Input buffer (Can have 1 to 4 bytes, depending ont he character)
 * RETURNS
 *  Number of input bytes used
 *****************************************************************************/
extern kal_int32 mmi_chset_utf8_to_ucs2(kal_uint8 *ucs2, kal_uint8 *utf8);

/*****************************************************************************
 * FUNCTION
 *  mmi_chset_ucs2_to_utf8
 * DESCRIPTION
 *  Convert single UCS2 character to UTF8
 * PARAMETERS
 *  utf8  :  [OUT]Output buffer (Needs 1 to 4 bytes, depending ont he character)
 *  ucs2  :  [IN] Input
 * RETURNS
 *  Number of bytes taken in utf8
 *****************************************************************************/
extern kal_int32 mmi_chset_ucs2_to_utf8(kal_uint8 *utf8, kal_uint16 ucs2);

extern kal_int32 mmi_chset_utf8_to_ucs2_string(kal_uint8 *dest, kal_int32 dest_size, kal_uint8 *src);
extern kal_int32 mmi_chset_utf8_to_ucs2_string_ex(
                    kal_uint8 *dest,
                    kal_int32 dest_size,
                    kal_uint8 *src,
                    kal_uint32 *src_end_pos);
extern kal_int32 mmi_chset_ucs2_to_utf8_string(kal_uint8 *dest, kal_int32 dest_size, kal_uint8 *src);
extern kal_int32 mmi_chset_ucs2_to_utf8_string_ex(
                    kal_uint8 *dest,
                    kal_int32 dest_size,
                    kal_uint8 *src,
                    kal_uint32 *src_end_pos);

/*****************************************************************************
 * FUNCTION
 *  mmi_chset_utf8_strlen
 * DESCRIPTION
 *  Get string length of a UTF8 encoded buffer
 * PARAMETERS
 *  s   :  [IN] Input buffer
 * RETURNS
 *  Number of valid characters
 *****************************************************************************/
extern kal_int32 mmi_chset_utf8_strlen(const kal_uint8 *s);

/*****************************************************************************
 * FUNCTION
 *  mmi_chset_get_charset_id
 * DESCRIPTION
 *  This function is used for get the charset id for the given charset name string. It's a name resolver for charsets.
 * PARAMETERS
 *  chset_name     :   [IN]        Charset name
 *  chset_id_p      :   [OUT]       Charset ID
 * RETURNS
 *  retrun KAL_TRUE if succeed, otherwise return KAL_FALSE
 *****************************************************************************/
extern kal_bool mmi_chset_get_charset_id(const kal_int8 *chset_name, mmi_chset_enum *chset_id_p);

extern kal_bool chset_get_charset_id(const kal_int8 *chset_name, chset_enum *chset_id_p);

/*****************************************************************************
 * FUNCTION
 *  chset_get_preferred_mime_name
 * DESCRIPTION
 *  This function is used for get the preferred MIME name of character set via
 *  the character set id.
 * PARAMETERS
 *  chset_id       :   [IN]        Character set id.
 * RETURNS
 *  If successful, retrun the const pointer to the character set name,
 *  otherwise return NULL
 *****************************************************************************/
extern const kal_int8 *chset_get_preferred_mime_name(chset_enum chset_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_chset_get_utf_byte_order
 * DESCRIPTION
 *  The function is used for get the byte order via the byte order mark .
 * PARAMETERS
 *  str_bom     :  [IN]        The byte order mark.
 * RETURNS
 *  returns MMI_CHSET_UTF16LE if the stream is little-endian
 *  returns MMI_CHSET_UTF16BE if the stream is big-endian
 *  returns MMI_CHSET_UTF8 if the input BOM is a UTF-8's BOM
 *  Otherwise returns -1
 *****************************************************************************/
extern kal_int8 mmi_chset_get_utf_byte_order(const kal_int8 *str_bom);

/*****************************************************************************
 * FUNCTION
 *  mmi_chset_utf16_strlen
 * DESCRIPTION
 *  The function is used for get the number of characters of the given UTF16
 *  encoded string, not including the beginning BOM and the final null
 *  character.
 *  Here we only accept FFFE/FEFF marks as endianness indicators in the
 *  beginning of the stream(See RFC 2781 section 3.2 specifies).
 *  If there is no BOM, the text default is interpreted as big-endian.
 *  The function does not count the surrogate pair. Because of it can't translate
 *  to UCS2.
 * PARAMETERS
 *  str_utf16    :    [IN]        UTF-16 encoded string which length is to be computed.
 *  utf16_type   :    [IN]        The type of input UTF-16 encoded string. MMI_CHSET_UTF16LE or MMI_CHSET_UTF16BE
 * RETURNS
 *  The number of characters of the input UTF16 encoded string.
 *****************************************************************************/
extern kal_int32 mmi_chset_utf16_strlen(const kal_int8 *str_utf16, mmi_chset_enum utf16_type);

extern kal_int32 mmi_chset_ucs2_to_utf16_bom_str(
                    kal_uint8 *dest_utf16,
                    kal_int32 dest_size,
                    mmi_chset_enum utf16_type,
                    kal_uint8 *src_ucs2,
                    kal_uint32 *src_end_pos);

/*****************************************************************************
 * FUNCTION
 *  mmi_chset_guess
 * DESCRIPTION
 *  Try to guess the charset of string buffer with given guess size.
 *  It will try only the suspect list if suspect_chset_mask is not CHSET_GUESS_ALL.
 *  Otherwise it will guess all the supported chsets.
 *	This function will return the preferred charset if more than one charsets
 *	have the same possibility.
 *  Currently we support:   UTF8, UTF16, UCS2, GB2312, BIG5, ISO8859-1
 * PARAMETERS
 *  buff                   :  [IN]        String buffer need to guess the charset
 *  guess_size             :  [IN]        String buffer size in byte used to guess
 *  preferred_chset        :  [IN]        Preferred charset name, pass 0 to use system prefer charset
 *  suspect_chset_mask     :  [IN]        Suspect charsets, use "|" to add more suspect charsets. 
 *                                     Use CHSET_GUESS_ALL to guess in all supported charsets.
 * RETURNS
 *  Charset Guess result
 *****************************************************************************/                    
extern mmi_chset_enum mmi_chset_guess(
                          const char *buff,
                          kal_int32 guess_size,
                          mmi_chset_enum preferred_chset,
                          kal_uint32 suspect_chset_mask);

/*****************************************************************************
 * FUNCTION
 *  mmi_chset_set_default_encoding_type
 * DESCRIPTION
 *  This function is used for set default encoding type (g_chset_text_encoding)
 * PARAMETERS
 *  chset_name      :  [IN]        Charset name
 * RETURNS
 *  Default encoding type setting success or fail
 *****************************************************************************/
extern kal_bool mmi_chset_set_default_encoding_type(const kal_int8 *chset_name);

/*****************************************************************************
 * FUNCTION
 *  mmi_chset_set_default_encoding_type
 * DESCRIPTION
 *  This function is used for set default encoding type (g_chset_text_encoding)
 * PARAMETERS
 *  chset_id        :  [IN]        Charset ID
 * RETURNS
 *  Default encoding type setting success or fail
 *****************************************************************************/
extern kal_bool mmi_chset_set_default_encoding_type_by_id(mmi_chset_enum chset_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_chset_get_default_encoding_type
 * DESCRIPTION
 *  This function is used to get default encoding type (g_chset_text_encoding)
 * PARAMETERS
 *  NONE
 * RETURNS
 *  Default encoding id
 *****************************************************************************/
extern mmi_chset_enum mmi_chset_get_default_encoding_type(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_chset_get_chset_list_by_language
 * DESCRIPTION
 *  Get charset list according to current language
 * PARAMETERS
 *  chset_list      :  [OUT]        Charset list.
 *  default         :  [OUT]        Default charset.
 * RETURNS
 *  chset number in the list
 *****************************************************************************/
extern kal_int32 mmi_chset_get_chset_list_by_language(mmi_chset_enum *chset_list, mmi_chset_enum *default_chset);

/*****************************************************************************
 * FUNCTION
 *  mmi_chset_get_enabled_chset_list
 * DESCRIPTION
 *  Get charset list 
 * PARAMETERS
 *  chset_list      :  [OUT]        Array of charset ids.
 * RETURNS
 *  Total number of enabled charsets
 *****************************************************************************/
extern kal_int32 mmi_chset_get_enabled_chset_list(mmi_chset_enum *chset_list);

/*****************************************************************************
 * FUNCTION
 *  mmi_chset_get_english_default_chset
 * DESCRIPTION
 *  Get default charset of English. Dependent of available languages in phone
 * PARAMETERS
 *  void
 * RETURNS
 *  default charset
 *****************************************************************************/
extern mmi_chset_enum mmi_chset_get_english_default_chset(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_chset_get_chset_string
 * DESCRIPTION
 *  Get charset string id (shown in menus) by chset enum
 * PARAMETERS
 *  chset      :  [IN]        Charset id (enum value)
 * RETURNS
 *  chset string id
 *****************************************************************************/
extern kal_uint16 mmi_chset_get_chset_string(mmi_chset_enum chset);

#ifdef __MMI_CHSET_SJIS__
extern kal_uint32 mmi_chset_sjis_to_ucs2(
            kal_uint8 *dest,
            kal_int32 dest_size,
            kal_uint8 *src,
            kal_uint32 *src_end_pos);
extern kal_uint32 mmi_chset_ucs2_to_sjis(
            kal_uint8 *dest,
            kal_int32 dest_size,
            kal_uint8 *src,
            kal_uint32 *src_end_pos);
#endif /* __MMI_CHSET_SJIS__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_chset_is_enabled
 * DESCRIPTION
 *  Checks whether chset is enabled or not.
 * PARAMETERS
 *  chset            :  [IN]       Input charset id
 * RETURNS
 *  TRUE if enabled
 *****************************************************************************/
 extern kal_bool mmi_chset_is_enabled(mmi_chset_enum chset);

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  mmi_charset_ucs2_to_utf8_length_in_bytes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  raw     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
extern int mmi_charset_ucs2_to_utf8_length_in_bytes(const kal_uint8 *raw);

/* DOM-NOT_FOR_SDK-END */

#endif /* _MMI_CONVERSIONS_H */ 

