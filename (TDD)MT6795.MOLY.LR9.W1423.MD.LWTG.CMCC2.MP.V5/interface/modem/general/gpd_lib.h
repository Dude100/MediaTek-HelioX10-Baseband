/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *   gpd_lib.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *     HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 ******************************************************************************/

#ifndef GPD_LIB_H
#define GPD_LIB_H
/******************************************************************************/

/******************************************************************************
* SAMPLE CODE                                                                                                              
*******************************************************************************/

// Basic
/******************************************************************************
// An example of combining two gpd linked lists and poll the first 3 nodes
{
    gpd_node*   gpd_nodes_a; //gpd linked list A with 5 items
    gpd_node*   gpd_nodes_b; //gpd linked list B with 5 items

    gpd_nodes_a = gpd_lib_add( gpd_nodes_a, gpd_nodes_b);
    gpd_nodes_a = gpd_lib_poll( gpd_nodes_a, 3, &gpd_node_b);

    gpd_lib_size( gpd_nodes_a); // 7
    gpd_lib_size( gpd_nodes_b); // 3
}
*******************************************************************************/

// List
/******************************************************************************
// An example of adding nodes to gpd_list and poll all items out
{
    gpd_list   node_list; //a gpd_list
    gpd_node*   gpd_nodes; //gpd linked list with 5 items   

    gpd_lib_list_create ( &node_list ); // Initialize gpd_list struct
    gpd_lib_list_add( &node_list, gpd_nodes); // add nodes into gpd_list

    gpd_lib_list_size( &node_list ); // 5

    gpd_nodes = gpd_lib_list_pollAll( &node_list ); // Poll all gpd nodes out

    gpd_lib_size(gpd_nodes); // 5
    gpd_lib_list_size( &node_list ); // 0        
}
*******************************************************************************/

// Iterator
/******************************************************************************
// An example of traversing a gpd linked list and remove nodes
{
    gpd_node*   gpd_nodes; //The gpd linked list which is going to be traversed

    gpd_itr     itr;
    gpd_node*   node;
    gpd_lib_iterator_create( &itr, &gpd_nodes ); // Create an iterator
    while( (node = gpd_lib_iterator_next(&itr))!= NULL )
    {
        if ( gpd_lib_data_size(node) > 1500 )
        {
            node = gpd_lib_iterator_remove(&itr); // Remove gpd with 1500+ data length
        }
    }
}
*******************************************************************************/

// Umts GPD Header and Tail
/******************************************************************************
// An example of adding and removing a header and a tail to an umts gpd node
{
    gpd_node*   umts_dl_gpd; //A umts dl gpd node

    kal_uint8   head[] = {0xAA,0xAA,0xAA};
    kal_uint8   tail[] = {0xBB,0xBB,0xBB};

    // Add header and tail
    gpd_lib_umts_addHeader( umts_dl_gpd, head, 3 );
    gpd_lib_umts_addTail( umts_dl_gpd, tail, 3 );

    // Delete header and tail
    gpd_lib_umts_delHeader( umts_dl_gpd, head, 3 );
    gpd_lib_umts_delTail( umts_dl_gpd, tail, 3 );
}
*******************************************************************************/

// Create Umts Single GPD and BD
/******************************************************************************
// An example of creating a single GPD with a single BD
{
    gpd_node*   umts_dl_gpd;

    kal_uint8 mem[1024];
    kal_uint8 data[] = { 1, 2, 3, 4 };

    if( gpd_lib_umts_sizeSingleGpdBd() > 1024 ) ASSERT(0);

    umts_dl_gpd = gpd_lib_umts_createSingleGpdBd( mem, data, 4 );

    //You get a gpd_node umts_dl_gpd
}
*******************************************************************************/

/******************************************************************************/

#include "kal_general_types.h"

/******************************************************************************/

//#define __GPD_LIB_DUBUG__

/******************************************************************************/

#if defined(__SMART_PHONE_MODEM__) && defined(__SDIO_DEVICE_CONNECTIVITY__)
#include "sdio_fw_api_public.h"
//#include "ccci.h"

#define GPD_LIB_GPD_RX_HEADER_SIZE  (GPD_LIB_SDIO_TX_DATA_HEADER + GPD_LIB_CCCI_DATA_HEADER)
#define GPD_LIB_GPD_RX_FOOTER_SIZE  (0)
#define GPD_LIB_SDIO_TX_DATA_HEADER (sizeof(SDIO_TX_DATA_HEADER))
#define GPD_LIB_CCCI_DATA_HEADER    (16)
#else
#define GPD_LIB_GPD_RX_HEADER_SIZE  (0)
#define GPD_LIB_GPD_RX_FOOTER_SIZE  (8)
#endif

/******************************************************************************/

typedef struct _gpd_node
{
    struct
    {
        kal_uint32  hwo:1;
        kal_uint32  bdp:1;
        kal_uint32  reserved:6;
        kal_uint32  checksum:8;
        kal_uint32  allow_buff_size:16;
    } w0;
    union
    {
        kal_uint32*         next_gpd_addr;
        struct _gpd_node*   next_gpd_node;
    } w1;
    union
    {
        kal_uint8*  buff_addr;
        kal_uint32* first_bd_addr;
    } w2;
    struct
    {
        kal_uint32  data_buff_size:16;
        kal_uint32  reserved:16;
    } w3;
} gpd_node;

/******************************************************************************/

typedef struct _gpd_list
{
    gpd_node*   first;
    gpd_node*   last;
    
} gpd_list;

/******************************************************************************/

typedef struct _gpd_itr
{
    gpd_node*   ptr;
    gpd_node*   pre;
    gpd_node**  root;
    
} gpd_itr;

/******************************************************************************/

extern gpd_node* gpd_lib_add( gpd_node* root, gpd_node* nodes );
extern gpd_node* gpd_lib_poll( gpd_node* root, kal_uint16 num, gpd_node** nodes );
extern kal_uint16 gpd_lib_size( gpd_node* root );
extern kal_bool gpd_lib_scan( gpd_node* root, kal_uint16* size, gpd_node** last );

/******************************************************************************/

extern gpd_list* gpd_lib_list_create( void* mem_ptr );
extern void gpd_lib_list_add( gpd_list* list, gpd_node* nodes );
extern gpd_node* gpd_lib_list_poll( gpd_list* list, kal_uint16 num );
extern void gpd_lib_list_add_ex( gpd_list* list, gpd_node* first, gpd_node* last );
extern gpd_node* gpd_lib_list_poll_ex( gpd_list* list, gpd_node** last );
extern kal_uint16 gpd_lib_list_size( gpd_list* list );

/******************************************************************************/

extern gpd_itr* gpd_lib_iterator_create( void* mem_ptr, gpd_node** nodes );
extern gpd_node* gpd_lib_iterator_next( gpd_itr* itr );
extern kal_bool gpd_lib_iterator_hasNext( gpd_itr* itr );
extern gpd_node* gpd_lib_iterator_remove( gpd_itr* itr );
extern gpd_node* gpd_lib_iterator_cut( gpd_itr* itr );

/******************************************************************************/

#define gpd_lib_data_size(np)           ((kal_uint16)((np)->w3.data_buff_size))
#define gpd_lib_data_getAddr(np)        ((kal_uint8*)((np)->w2.buff_addr))
#define gpd_lib_data_setSize(np,size)   ((np)->w3.data_buff_size = (kal_uint16)(size))
extern kal_uint16 gpd_lib_data_totalsize( gpd_node* nodes );

/******************************************************************************/

extern void gpd_lib_umts_addHeader( gpd_node* node, kal_uint8* buff_ptr, 
    kal_uint16 buff_len );
extern void gpd_lib_umts_delHeader( gpd_node* node, kal_uint8** buff_ptr );
extern kal_uint8* gpd_lib_umts_peekHeader( gpd_node* node );
extern void gpd_lib_umts_addTail( gpd_node* node, kal_uint8* buff_ptr, 
    kal_uint16 buff_len );
extern void gpd_lib_umts_delTail( gpd_node* node, kal_uint8** buff_ptr );

extern kal_uint8* gpd_lib_umts_getFirstBDDataPtr( gpd_node* node );
extern kal_uint32* gpd_lib_umts_getFirstBDPeerBuffPtr( gpd_node* node );
extern void gpd_lib_umts_clearFirstBDPeerBuffPtr( gpd_node* node );
extern kal_uint8 gpd_lib_umts_getType( gpd_node* node );
extern void gpd_lib_umts_setOutputAddr( gpd_node* node, kal_uint8* addr );

/******************************************************************************/

extern void gpd_lib_sdio_tx_initGpd(gpd_node * node);
extern gpd_node* gpd_lib_sdio_tx_createGpd( void* mem_ptr, kal_uint8* buff_addr, 
    kal_uint16 buff_len  );
extern kal_uint8* gpd_lib_sdio_tx_getCCCIHeader( gpd_node* node );
extern kal_uint8* gpd_lib_sdio_tx_getPayloadAddr(gpd_node * node);
extern kal_uint16 gpd_lib_sdio_tx_getPayloadLen( gpd_node* node );
extern kal_uint16 gpd_lib_sdio_tx_sizeGpd( void );

/******************************************************************************/

#if defined(__3G_NEW_DATA_PLANE_ARCH__) && defined(__GPD_LIB_TEST__)
#include "uas_data_common.h"

#define UMTSGPD_HEADER_BUFFER_SIZE 60  // used by module UPS
#define UMTSGPD_FOOTER_BUFFER_SIZE 4   // used by module UPS

typedef struct _umts_dl_gpd_flc
{
    umts_dl_gpd gpd;
    
    kal_uint32  header_buffer[(UMTSGPD_HEADER_BUFFER_SIZE+3)/4];
    kal_uint32  footer_buffer[(UMTSGPD_FOOTER_BUFFER_SIZE+3)/4];
   
} umts_dl_gpd_flc;

extern void gpd_lib_umts_initBd(umts_dl_bd * bd);
extern void gpd_lib_umts_initGpd ( umts_dl_gpd* gpd );
extern void gpd_lib_umts_initGpdFlc ( umts_dl_gpd_flc* gpd );
extern void gpd_lib_umts_addBdtoGpd( umts_dl_gpd* gpd, umts_dl_bd* bd );
extern gpd_node* gpd_lib_umts_createSingleGpdBd( void* mem_ptr, 
    kal_uint8* buff_addr, kal_uint16 buff_len  );
extern kal_uint16 gpd_lib_umts_sizeSingleGpdBd( void );
#endif

/******************************************************************************/
#endif /* GPD_LIB_H */

