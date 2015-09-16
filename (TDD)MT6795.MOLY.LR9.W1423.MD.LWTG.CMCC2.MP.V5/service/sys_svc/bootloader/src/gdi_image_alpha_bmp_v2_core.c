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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  gdi_image_alpha_bmp_v2_core.c
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  Core algorithm for alpha bitmap v2
 *  Compiled in ARM mode to enhance performance.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "gdi_image_alpha_bmp_v2_internal.h"

#ifdef GDI_IMAGE_AB2_HAS_GDI

#include "kal_public_api.h"
#include "MMI_features.h"
#include "MMIDataType.h"
#include "gdi_primitive.h"

#endif /* GDI_IMAGE_AB2_HAS_GDI */


/***************************************************************************** 
 * Define
 *****************************************************************************/
/* read / write data */
#define GET_DATA_16(ptr)                (*((U16*)(ptr)))
#define GET_DATA_24(ptr)                ((((U8 *)(ptr))[0]) + (((U8 *)(ptr))[1] << 8) + (((U8*)(ptr))[2] << 16))
#define GET_DATA_32(ptr)                (*((U32 *)(ptr)))

#define PUT_DATA_16(ptr, p)             (*((U16*)(ptr)) = p)
#define PUT_DATA_24(ptr, p)     \
    do                          \
    {                           \
        U8 *ptr8 = (U8*)(ptr);  \
        ptr8[0] = p;            \
        ptr8[1] = p >> 8;       \
        ptr8[2] = p >> 16;      \
    } while (0)
#define PUT_DATA_32(ptr, p)             (*((U32*)(ptr)) = p)


/* color table helper macro */
#define GET_TABLE_16(pal, idx)          GET_DATA_16((U8 *)(pal) + 2 * (idx))
#define GET_TABLE_24(pal, idx)          GET_DATA_24((U8 *)(pal) + 3 * (idx))
#define GET_TABLE_32(pal, idx)          GET_DATA_32((U8 *)(pal) + 4 * (idx))

/* ARGB8888 */
#define R_OF_RGB888(c)                  (((c) <<  8) >> 24)
#define G_OF_RGB888(c)                  (((c) << 16) >> 24)
#define B_OF_RGB888(c)                  (((c) << 24) >> 24)
#define A_OF_ARGB8888(c)                ((c) >> 24)

/* ARGB8565 */
#define R_OF_RGB565(c)                  (((c) << 16) >> 27)
#define G_OF_RGB565(c)                  (((c) << 21) >> 26)
#define B_OF_RGB565(c)                  (((c) << 27) >> 27)
#define A_OF_ARGB8565(c)                (((c) <<  8) >> 24)

/* target dependent */
#if MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL == 16

#define GET_IMG_PIXEL(ptr)                  GET_DATA_16(ptr)
#define PUT_IMG_PIXEL(ptr, p)               PUT_DATA_16(ptr, p)

#define GET_NORMAL_TABLE_COLOR(table, idx)  GET_TABLE_16(table, idx)
#define GET_ALPHA_TABLE_COLOR(table, idx)   GET_TABLE_24(table, idx)

#elif MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL == 24

#define GET_IMG_PIXEL(ptr)                  GET_DATA_24(ptr)
#define PUT_IMG_PIXEL(ptr, p)               PUT_DATA_24(ptr, p)

#define GET_NORMAL_TABLE_COLOR(table, idx)  GET_TABLE_24(table, idx)
#define GET_ALPHA_TABLE_COLOR(table, idx)   GET_TABLE_32(table, idx)

#elif MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL == 32

#define GET_IMG_PIXEL(ptr)                  GET_DATA_32(ptr)
#define PUT_IMG_PIXEL(ptr, p)               PUT_DATA_32(ptr, p)

#define GET_NORMAL_TABLE_COLOR(table, idx)  GET_TABLE_24(table, idx)
#define GET_ALPHA_TABLE_COLOR(table, idx)   GET_TABLE_32(table, idx)

#else

#error "Not support this layer pixel size."

#endif


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
/* Bit-Stream data structure */
typedef struct
{
    const U8 *mem_ptr;
    U32 buf;
    U32 buf_bits;
} gdi_image_ab2_bs_struct;


/* RLE Pixel Stream data structure */
typedef struct
{
    gdi_image_ab2_bs_struct bs;
    
    U32 color_idx_bits;
    
    U32 count;
    U32 is_discount;
    U32 repeat_color_idx;
    
} gdi_image_ab2_rle_ps_struct;


/***************************************************************************** 
 * Local Function 
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_bs_init
 * DESCRIPTION
 *  Initialize the given bit-stream data structure.
 *  The first data will start at given memory pointer.
 * PARAMETERS
 *  bs              [OUT]   bit-stream structure to be initialized
 *  mem_ptr         [IN]    start memory to be a bit-stream
 * RETURNS
 *  void
 *****************************************************************************/
static GDI_IMAGE_AB2_INLINE void gdi_image_ab2_bs_init(
    gdi_image_ab2_bs_struct *bs,
    const U8 *mem_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ASSERT(bs != NULL);

    if ((U32)mem_ptr & 0x1 != 0)
    {
        /* if mem_ptr is not 2-bytes alignment, read one byte into buffer */
        bs->mem_ptr     = mem_ptr + 1;
        bs->buf         = *(U8 *) mem_ptr;
        bs->buf_bits    = 8;
    }
    else
    {
        bs->mem_ptr     = mem_ptr;
        bs->buf         = 0;
        bs->buf_bits    = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_bs_read
 * DESCRIPTION
 *  Read given bits data from bit-stream. The data must less or equal 16 bits.
 * PARAMETERS
 *  bs              [IN]    bit-stream
 *  bits            [IN]    number of bits to read
 * RETURNS
 *  Read data
 *****************************************************************************/
static GDI_IMAGE_AB2_INLINE U32 gdi_image_ab2_bs_read(gdi_image_ab2_bs_struct *bs, U32 bits)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //GDI_ASSERT(bs != NULL);
    //GDI_ASSERT(bits <= 16);

    if (bs->buf_bits < bits)
    {
        /* read 16 bits data from memory and fill to buffer */
        bs->buf |= ((*(U16 *)bs->mem_ptr) << bs->buf_bits);
        bs->buf_bits += 16;
        bs->mem_ptr  += sizeof(U16);
    }
    
    data = bs->buf & ~(~0 << bits);
    bs->buf >>= bits;
    bs->buf_bits -= bits;

    return data;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_bs_ignore
 * DESCRIPTION
 *  Ignore given bits data from bit-stream. The bits must less or equal 16.
 * PARAMETERS
 *  bs              [IN]    bit-stream
 *  bits            [IN]    number of bits to ignore
 * RETURNS
 *  void
 *****************************************************************************/
static GDI_IMAGE_AB2_INLINE void gdi_image_ab2_bs_ignore(gdi_image_ab2_bs_struct *bs, U32 bits)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //GDI_ASSERT(bs != NULL);
    //GDI_ASSERT(bits <= 16);

    if (bs->buf_bits < bits)
    {
        /* read 16 bits data from memory and fill to buffer */
        bs->buf |= ((*(U16 *)bs->mem_ptr) << bs->buf_bits);
        bs->buf_bits += 16;
        bs->mem_ptr  += sizeof(U16);
    }
    
    bs->buf >>= bits;
    bs->buf_bits -= bits;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_bs_ignore_large
 * DESCRIPTION
 *  Ignore given bits data from bit-stream, can handle larger than 16 bits.
 * PARAMETERS
 *  bs              [IN]    bit-stream
 *  bits            [IN]    number of bits to ignore
 * RETURNS
 *  void
 *****************************************************************************/
static GDI_IMAGE_AB2_INLINE void gdi_image_ab2_bs_ignore_large(gdi_image_ab2_bs_struct *bs, U32 bits)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //GDI_ASSERT(bs != NULL);

    if (bits >= 16)
    {
        bits -= bs->buf_bits;
        bs->buf         = 0;
        bs->buf_bits    = 0;

        bs->mem_ptr += (bits / 16) * sizeof(U16);
        bits %= 16;
    }
    
    gdi_image_ab2_bs_ignore(bs, bits);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_decode_to_PARGB8888
 * DESCRIPTION
 *  Restoure color to PARGB8888 color format
 * PARAMETERS
 *  src_color       [IN] source color
 * RETURNS
 *  the result of alpha blending
 *****************************************************************************/
static GDI_IMAGE_AB2_INLINE U32 gdi_image_ab2_decode_to_PARGB8888(U32 src_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    U32 a, r, g, b;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL == 16

    // TODO: may be optimized
    a = 255 - A_OF_ARGB8565(src_color);
    r = GDI_IMAGE_AB2_BITS_5_to_8(R_OF_RGB565(src_color));
    g = GDI_IMAGE_AB2_BITS_6_to_8(G_OF_RGB565(src_color));
    b = GDI_IMAGE_AB2_BITS_5_to_8(B_OF_RGB565(src_color));

#else    

    // TODO: may be optimized
    a = 255 - A_OF_ARGB8888(src_color);
    r = R_OF_RGB888(src_color);
    g = G_OF_RGB888(src_color);
    b = B_OF_RGB888(src_color);

#endif

    return (a << 24) | (r << 16) | (g << 8) | b;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_alpha_blending
 * DESCRIPTION
 *  Caculate alpha blending color.
 *  src_color must be pre-multiplied alpha format
 * PARAMETERS
 *  dst_color       [IN] desination color
 *  src_color       [IN] source color
 * RETURNS
 *  the result of alpha blending
 *****************************************************************************/
static GDI_IMAGE_AB2_INLINE U32 gdi_image_ab2_alpha_blending(U32 dst_color, U32 src_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    U32 alpha;
    U32 r, g, b;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
#if MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL == 16

    alpha = A_OF_ARGB8565(src_color);
    
    r = R_OF_RGB565(src_color);
    r += GDI_IMAGE_AB2_DIV_255(R_OF_RGB565(dst_color) * alpha);
    if (r > 31)
    {
        r = 31;
    }

    g = G_OF_RGB565(src_color);
    g += GDI_IMAGE_AB2_DIV_255(G_OF_RGB565(dst_color) * alpha);
    if (g > 63)
    {
        g = 63;
    }

    b = B_OF_RGB565(src_color);
    b += GDI_IMAGE_AB2_DIV_255(B_OF_RGB565(dst_color) * alpha);
    if (b > 31)
    {
        b = 31;
    }

    return (r << 11) | (g << 5) | b;

#else    

    alpha = A_OF_ARGB8888(src_color);
    
    r = R_OF_RGB888(src_color);
    r += GDI_IMAGE_AB2_DIV_255(R_OF_RGB888(dst_color) * alpha);
    if (r > 255)
    {
        r = 255;
    }

    g = G_OF_RGB888(src_color);
    g += GDI_IMAGE_AB2_DIV_255(G_OF_RGB888(dst_color) * alpha);
    if (g > 255)
    {
        g = 255;
    }

    b = B_OF_RGB888(src_color);
    b += GDI_IMAGE_AB2_DIV_255(B_OF_RGB888(dst_color) * alpha);
    if (b > 255)
    {
        b = 255;
    }

    return (r << 16) | (g < 8) | b;

#endif
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_rle_get_normal_color
 * DESCRIPTION
 *  Get the color value in normal color table.
 *  color_idx MUST in the normal color table.
 * PARAMETERS
 *  rle_info        [IN]    RLE header data
 *  color_idx       [IN]    color index to query
 * RETURNS
 *  Color value of the color index
 *****************************************************************************/
static GDI_IMAGE_AB2_INLINE U32 gdi_image_ab2_rle_get_normal_color(
    const gdi_image_ab2_rle_info_struct *rle_info,
    U32 color_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //GDI_ASSERT(color_idx != 0);
    
    return GET_NORMAL_TABLE_COLOR(
        rle_info->normal_color_pal_ptr,
        color_idx - 1);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_rle_get_alpha_color
 * DESCRIPTION
 *  Get the color value in alpha color table.
 *  color_idx MUST in the alpha color table.
 * PARAMETERS
 *  rle_info        [IN]    RLE header data
 *  color_idx       [IN]    color index to query
 * RETURNS
 *  Color value of the color index
 *****************************************************************************/
static GDI_IMAGE_AB2_INLINE U32 gdi_image_ab2_rle_get_alpha_color(
    const gdi_image_ab2_rle_info_struct *rle_info,
    U32 color_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //GDI_ASSERT(color_idx >= rle_info->normal_color_cnt + 1);
    
    return GET_ALPHA_TABLE_COLOR(
        rle_info->alpha_color_pal_ptr,
        color_idx - rle_info->normal_color_cnt - 1);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_rle_get_color_PARGB8888
 * DESCRIPTION
 *  Get the color value in color table.
 * PARAMETERS
 *  rle_info        [IN]    RLE header data
 *  color_idx       [IN]    color index to query
 * RETURNS
 *  Color value of the color index
 *****************************************************************************/
static GDI_IMAGE_AB2_INLINE U32 gdi_image_ab2_rle_get_color_PARGB8888(
    const gdi_image_ab2_rle_info_struct *rle_info,
    U32 color_idx)
{
    if (color_idx == 0)
    {
        return 0;
    }
    else if (color_idx <= rle_info->normal_color_cnt)
    {
        /* normal color */
        return
            gdi_image_ab2_decode_to_PARGB8888(
                gdi_image_ab2_rle_get_normal_color(rle_info, color_idx));
    }
    else
    {
        /* alpha color */
        return
            gdi_image_ab2_decode_to_PARGB8888(
                gdi_image_ab2_rle_get_alpha_color(rle_info, color_idx));
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_rle_ps_init
 * DESCRIPTION
 *  Initialize RLE pixel stream data structure.
 * PARAMETERS
 *  ps              [OUT]   the RLE pixel stream to be initialized
 *  mem_ptr         [IN]    the start memory to be a RLE pixel stream
 *  color_idx_bits  [IN]    the bits per color index
 * RETURNS
 *  void
 *****************************************************************************/
static GDI_IMAGE_AB2_INLINE void gdi_image_ab2_rle_ps_init(
    gdi_image_ab2_rle_ps_struct *ps,
    const U8 *mem_ptr,
    U32 color_idx_bits)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    GDI_ASSERT(ps != NULL);
    GDI_ASSERT(mem_ptr != NULL);

    gdi_image_ab2_bs_init(&ps->bs, mem_ptr);
    
    ps->color_idx_bits      = color_idx_bits;
    
    ps->count               = 0;
    ps->is_discount         = 0;
    ps->repeat_color_idx    = 0;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_rle_ps_fetch_color_index
 * DESCRIPTION
 *  Parse and return a RLE color index from current position. 
 *  According the ABMv2 RLE file format.
 *  *** Helper function for internal use.
 * PARAMETERS
 *  ps              [IN]    the RLE pixel stream
 * RETURNS
 *  the fected color index
 *****************************************************************************/
static GDI_IMAGE_AB2_INLINE U32 gdi_image_ab2_rle_ps_fetch_color_index(gdi_image_ab2_rle_ps_struct *ps)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //GDI_ASSERT(ps != NULL);

    return gdi_image_ab2_bs_read(&ps->bs, ps->color_idx_bits);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_rle_ps_fetch_color_index
 * DESCRIPTION
 *  Parse a new RLE pack encoding.
 *  According the ABMv2 RLE file format.
 *  *** Helper function for internal use.
 * PARAMETERS
 *  ps              [IN]    the RLE pixel stream
 * RETURNS
 *  void
 *****************************************************************************/
static GDI_IMAGE_AB2_INLINE void gdi_image_ab2_rle_ps_fetch_pack(gdi_image_ab2_rle_ps_struct *ps)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 pack_head;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //GDI_ASSERT(ps != NULL);
    //GDI_ASSERT(ps->count == 0);
    
    pack_head       = gdi_image_ab2_bs_read(&ps->bs, 8);

    ps->count       = (pack_head & 0x7f) + 1;
    ps->is_discount = pack_head & 0x80;
    
    if (!ps->is_discount)
    {
        ps->repeat_color_idx = gdi_image_ab2_rle_ps_fetch_color_index(ps);
    }
}


/*
 * optimization for time
 */
#ifdef __MTK_TARGET__
#pragma Otime
#pragma arm section code = "INTERNCODE"
#endif

/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_rle_ps_ignore
 * DESCRIPTION
 *  Ignore pixels by given number
 * PARAMETERS
 *  ps              [IN]    the RLE pixel stream
 *  n               [IN]    number of pixels to be ignored
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_image_ab2_rle_ps_ignore(gdi_image_ab2_rle_ps_struct *ps, U32 n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //GDI_ASSERT(ps != NULL);

    while (n != 0)
    {
        U32 ignore_count;
        
        if (ps->count == 0)
        {
            gdi_image_ab2_rle_ps_fetch_pack(ps);
        }

        ignore_count = GDI_IMAGE_AB2_MIN(ps->count, n);
        ps->count   -= ignore_count;
        n           -= ignore_count;

        if (ps->is_discount)
        {
            gdi_image_ab2_bs_ignore_large(&ps->bs, ps->color_idx_bits * ignore_count);
        }
    } /* while (n > 0) */
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_rle_ps_draw_to_PARGB8888
 * DESCRIPTION
 *  Decode n pixels to dst_ptr, direct output to PARGB8888.
 *  ***This function is the core to be optimized for performance.
 *  Please modify it carefully.
 * PARAMETERS
 *  ps              [IN]    the RLE pixel stream
 *  rle_info        [IN]    the RLE header data
 *  dst_ptr         [OUT]   the target image buffer to output
 *  dst_pixel_bytes [IN]    bytes per pixels of dst_ptr
 *  n               [IN]    number of pixels to output
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_image_ab2_rle_ps_draw_to_PARGB8888(
    gdi_image_ab2_rle_ps_struct *ps, 
    const gdi_image_ab2_rle_info_struct *rle_info,
    U8 *dst_ptr,
    U32 dst_pixel_bytes, 
    U32 n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 color_idx;
    U32 out_color;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (n != 0)
    {
        U32 draw_count;
        
        if (ps->count == 0)
        {
            gdi_image_ab2_rle_ps_fetch_pack(ps);
        }

        draw_count  = GDI_IMAGE_AB2_MIN(ps->count, n);
        ps->count   -= draw_count;
        n           -= draw_count;

        if (ps->is_discount)
        {
            /* discontinue pack */
            do
            {
                color_idx = gdi_image_ab2_rle_ps_fetch_color_index(ps);
                out_color = gdi_image_ab2_rle_get_color_PARGB8888(rle_info, color_idx);
                PUT_DATA_32(dst_ptr, out_color);
                dst_ptr += dst_pixel_bytes;
            } while(--draw_count);
        }
        else
        {
            /* repeat pack */
            color_idx = ps->repeat_color_idx;
            out_color = gdi_image_ab2_rle_get_color_PARGB8888(rle_info, color_idx);
            do 
            {
                PUT_DATA_32(dst_ptr, out_color);
                dst_ptr += dst_pixel_bytes;
            } while(--draw_count);
        } /* if (ps->is_discount) */
    } /* while (n != 0) */
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_rle_ps_draw_na
 * DESCRIPTION
 *  Decode n pixels to dst_ptr, WITOUT alpha blending (source color key mode).
 *  ***This function is the core to be optimized for performance.
 *  Please modify it carefully.
 * PARAMETERS
 *  ps              [IN]    the RLE pixel stream
 *  rle_info        [IN]    the RLE header data
 *  dst_ptr         [OUT]   the target image buffer to output
 *  dst_pixel_bytes [IN]    bytes per pixels of dst_ptr
 *  n               [IN]    number of pixels to output
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_image_ab2_rle_ps_draw_na(
    gdi_image_ab2_rle_ps_struct *ps, 
    const gdi_image_ab2_rle_info_struct *rle_info,
    U8 *dst_ptr,
    U32 dst_pixel_bytes, 
    U32 n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 color_idx;
    U32 out_color;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (n != 0)
    {
        U32 draw_count;
        
        if (ps->count == 0)
        {
            gdi_image_ab2_rle_ps_fetch_pack(ps);
        }

        draw_count  = GDI_IMAGE_AB2_MIN(ps->count, n);
        ps->count   -= draw_count;
        n           -= draw_count;

        if (ps->is_discount)
        {
            /* discontinue pack */
            do
            {
                color_idx = gdi_image_ab2_rle_ps_fetch_color_index(ps);
                if (color_idx == 0)
                {
                    /* transparent color, do nothing */
                }
                else
                {
                    /* normal color, put to destination */
                    out_color = gdi_image_ab2_rle_get_normal_color(rle_info, color_idx);
                    PUT_IMG_PIXEL(dst_ptr, out_color);
                }
                dst_ptr += dst_pixel_bytes;
            } while(--draw_count);
        }
        else
        {
            /* repeat pack */
            color_idx = ps->repeat_color_idx;
            if (color_idx == 0)
            {
                /* transparent color, seek destination pointer to next position to draw */
                dst_ptr += dst_pixel_bytes * draw_count;
            }
            else
            {
                /* normal color, put to destination */
                out_color = gdi_image_ab2_rle_get_normal_color(rle_info, color_idx);
                do 
                {
                    PUT_IMG_PIXEL(dst_ptr, out_color);
                    dst_ptr += dst_pixel_bytes;
                } while(--draw_count);
            }
        } /* if (ps->is_discount) */
    } /* while (n != 0) */
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_rle_ps_draw_alpha
 * DESCRIPTION
 *  Decode n pixels to dst_ptr, with alpha blending.
 *  ***This function is the core to be optimized for performance.
 *  Please modify it carefully.
 * PARAMETERS
 *  ps              [IN]    the RLE pixel stream
 *  rle_info        [IN]    the RLE header data
 *  dst_ptr         [OUT]   the target image buffer to output
 *  src_ptr         [IN]    the alpha blending source image buffer
 *  dst_pixel_bytes [IN]    bytes per pixels of dst_ptr
 *  src_pixel_bytes [IN]    bytes per pixels of src_ptr
 *  n               [IN]    number of pixels to output
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_image_ab2_rle_ps_draw_alpha(
    gdi_image_ab2_rle_ps_struct *ps, 
    const gdi_image_ab2_rle_info_struct *rle_info,
    U8 *dst_ptr,
    const U8 *src_ptr,
    U32 dst_pixel_bytes, 
    U32 src_pixel_bytes, 
    U32 n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 color_idx;
    U32 out_color, src_color, img_color;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (n != 0)
    {
        U32 draw_count;
        
        if (ps->count == 0)
        {
            gdi_image_ab2_rle_ps_fetch_pack(ps);
        }

        draw_count = GDI_IMAGE_AB2_MIN(ps->count, n);
        ps->count   -= draw_count;
        n           -= draw_count;

        if (ps->is_discount)
        {
            /* discontinue pack */
            do
            {
                color_idx = gdi_image_ab2_rle_ps_fetch_color_index(ps);
                if (color_idx == 0)
                {
                    /* transparent color, copy from source  */
                    out_color = GET_IMG_PIXEL(src_ptr);
                }
                else if (color_idx <= rle_info->normal_color_cnt)
                {
                    /* normal color, just put to destination */
                    out_color = gdi_image_ab2_rle_get_normal_color(rle_info, color_idx);
                }
                else
                {
                    /* alpha color, do alpha blending */
                    img_color = gdi_image_ab2_rle_get_alpha_color(rle_info, color_idx);
                    src_color = GET_IMG_PIXEL(src_ptr);
                    out_color = gdi_image_ab2_alpha_blending(src_color, img_color);
                }
                PUT_IMG_PIXEL(dst_ptr, out_color);
                dst_ptr += dst_pixel_bytes;
                src_ptr += src_pixel_bytes;
            } while(--draw_count);
        }
        else
        {
            /* repeat pack */
            color_idx = ps->repeat_color_idx;
            if (color_idx == 0)
            {
                /* transparent color, copy from source  */
                do
                {
                    out_color = GET_IMG_PIXEL(src_ptr);
                    PUT_IMG_PIXEL(dst_ptr, out_color);
                    dst_ptr += dst_pixel_bytes;
                    src_ptr += src_pixel_bytes;
                } while(--draw_count);
            }
            else if (color_idx <= rle_info->normal_color_cnt)
            {
                /* normal color, just put to destination */
                out_color = gdi_image_ab2_rle_get_normal_color(rle_info, color_idx);
                do
                {
                    PUT_IMG_PIXEL(dst_ptr, out_color);
                    dst_ptr += dst_pixel_bytes;
                    src_ptr += src_pixel_bytes;
                } while(--draw_count);
            }
            else
            {
                /* alpha color, do alpha blending */
                img_color = gdi_image_ab2_rle_get_alpha_color(rle_info, color_idx);
                do
                {
                    src_color = GET_IMG_PIXEL(src_ptr);
                    out_color = gdi_image_ab2_alpha_blending(src_color, img_color);
                    PUT_IMG_PIXEL(dst_ptr, out_color);
                    dst_ptr += dst_pixel_bytes;
                    src_ptr += src_pixel_bytes;
                } while(--draw_count);
            }
        } /* if (ps->is_discount) */
    } /* while (n != 0) */
}


/*
 * optimization for space
 */
#ifdef __MTK_TARGET__
#pragma Ospace
#pragma arm section code
#endif


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_rle_decode_to_PARGB8888
 * DESCRIPTION
 *  Decode the RLE data stream to a PARGB8888 buffer.
 * PARAMETERS
 *  dst_buf         [IN]    destination image buffer (the target to draw)
 *  rle_info        [IN]    the RLE header data
 *  draw_width      [IN]    the pixels to draw a line
 *  draw_height     [IN]    the lines to draw
 *  begin_ignore    [IN]    the pixels to ignore before drawing
 *  line_ignore     [IN]    the pixels to ignore after drawing each line
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_image_ab2_rle_decode_to_PARGB8888(
    gdi_image_ab2_img_buf_struct *dst_buf,
    const gdi_image_ab2_rle_info_struct *rle_info,
    U32 draw_width, 
    U32 draw_height,
    U32 begin_ignore,
    U32 line_ignore)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_image_ab2_rle_ps_struct ps;
    U8 *dst_ptr;
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ASSERT(dst_buf != NULL);
    GDI_ASSERT(rle_info != NULL);

    /* create a RLE pixel stream */
    gdi_image_ab2_rle_ps_init(&ps, rle_info->bs_ptr, rle_info->color_idx_bits);

    /* Seek to the start position (ignore top clipping) */
    gdi_image_ab2_rle_ps_ignore(&ps, begin_ignore);
    dst_ptr = dst_buf->ptr;
    
    for (i = draw_height; i != 0; i--)
    {
        gdi_image_ab2_rle_ps_draw_to_PARGB8888(
            &ps,
            rle_info,
            dst_ptr,
            dst_buf->pixel_bytes,
            draw_width);

        /* Seek to the begin of next line */
        gdi_image_ab2_rle_ps_ignore(&ps, line_ignore);
        dst_ptr += dst_buf->pitch_bytes;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_rle_decode_na
 * DESCRIPTION
 *  Decode the RLE data stream WITHOUT alpha.
 * PARAMETERS
 *  dst_buf         [IN]    destination image buffer (the target to draw)
 *  rle_info        [IN]    the RLE header data
 *  draw_width      [IN]    the pixels to draw a line
 *  draw_height     [IN]    the lines to draw
 *  begin_ignore    [IN]    the pixels to ignore before drawing
 *  line_ignore     [IN]    the pixels to ignore after drawing each line
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_image_ab2_rle_decode_na(
    gdi_image_ab2_img_buf_struct *dst_buf,
    const gdi_image_ab2_rle_info_struct *rle_info,
    U32 draw_width, 
    U32 draw_height,
    U32 begin_ignore,
    U32 line_ignore)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_image_ab2_rle_ps_struct ps;
    U8 *dst_ptr;
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ASSERT(dst_buf != NULL);
    GDI_ASSERT(rle_info != NULL);

    /* create a RLE pixel stream */
    gdi_image_ab2_rle_ps_init(&ps, rle_info->bs_ptr, rle_info->color_idx_bits);

    /* Seek to the start position (ignore top clipping) */
    gdi_image_ab2_rle_ps_ignore(&ps, begin_ignore);
    dst_ptr = dst_buf->ptr;
    
    for (i = draw_height; i != 0; i--)
    {
        gdi_image_ab2_rle_ps_draw_na(
            &ps,
            rle_info,
            dst_ptr,
            dst_buf->pixel_bytes,
            draw_width);

        /* Seek to the begin of next line */
        gdi_image_ab2_rle_ps_ignore(&ps, line_ignore);
        dst_ptr += dst_buf->pitch_bytes;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_rle_decode_alpha
 * DESCRIPTION
 *  Decode the RLE data stream with alpha.
 * PARAMETERS
 *  dst_buf         [IN]    destination image buffer (the target to draw)
 *  src_buf         [IN]    alpha blending source image buffer
 *  rle_info        [IN]    RLE header data
 *  draw_width      [IN]    pixels to draw a line
 *  draw_height     [IN]    lines to draw
 *  begin_ignore    [IN]    pixels to ignore before drawing
 *  line_ignore     [IN]    pixels to ignore after drawing each line
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_image_ab2_rle_decode_alpha(
    gdi_image_ab2_img_buf_struct *dst_buf,
    const gdi_image_ab2_img_buf_struct *src_buf,
    const gdi_image_ab2_rle_info_struct *rle_info,
    U32 draw_width, 
    U32 draw_height,
    U32 begin_ignore,
    U32 line_ignore)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_image_ab2_rle_ps_struct ps;
    U8 *dst_ptr, *src_ptr;
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ASSERT(dst_buf != NULL);
    GDI_ASSERT(src_buf != NULL);
    GDI_ASSERT(rle_info != NULL);

    /* create a RLE pixel stream */
    gdi_image_ab2_rle_ps_init(&ps, rle_info->bs_ptr, rle_info->color_idx_bits);

    /* Seek to the start position (ignore top clipping) */
    gdi_image_ab2_rle_ps_ignore(&ps, begin_ignore);
    dst_ptr = dst_buf->ptr;
    src_ptr = src_buf->ptr;
    
    for (i = draw_height; i != 0; i--)
    {
        gdi_image_ab2_rle_ps_draw_alpha(
            &ps,
            rle_info,
            dst_ptr,
            src_ptr,
            dst_buf->pixel_bytes,
            src_buf->pixel_bytes,
            draw_width);
        
        /* Seek to the begin of next line */
        gdi_image_ab2_rle_ps_ignore(&ps, line_ignore);
        dst_ptr += dst_buf->pitch_bytes;
        src_ptr += src_buf->pitch_bytes;
    }
}


