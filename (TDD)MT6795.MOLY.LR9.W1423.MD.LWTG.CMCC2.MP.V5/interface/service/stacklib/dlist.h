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
 *	dlist.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 * Header file for double linked list facility
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __DLIST_H__
#define __DLIST_H__
 
//#include "kal_release.h"
/*RHR*/
#include "kal_general_types.h"
/*RHR*/
/* TYPES DEFINITIONS ********************************************************/
/*
 * DLIST_LINK: The structure used for a link in a doubly linked list.
 * The pThis field is a generic pointer that points to the item being listed.
 * The pNext field is a pointer to the next link in the list, and is NULL for
 * the last link in the list.
 */
typedef struct DLIST_LINK_TAG
{
    void                    *pThis; /*
                                     * Pointer to the item in the list
                                     */
    struct DLIST_LINK_TAG   *pPrev; /*
                                     * Pointer to the previous link in the list
                                     */
    struct DLIST_LINK_TAG   *pNext; /*
                                     * Pointer to the next link in the list
                                     */
} DLIST_LINK;

/*
 * DLIST_HEAD: The structure used for the head of a doubly linked list.
 * The ulCount field contains the number of links in the doubly linked list,
 * and will be zero when the doubly linked list is empty.
 * The pFirst field is a pointer to the first link in the doubly linked list,
 * and will be NULL for an empty list.
 */
typedef struct DLIST_HEAD_TAG
{
    kal_uint32                     ulCount;    /*
                                         * A count of the number of links in
                                         * the list
                                         */
    struct DLIST_LINK_TAG   *pFirst;    /*
                                         * A pointer to the first link in the
                                         * list
                                         */
    struct DLIST_LINK_TAG   *pLast;     /*
                                         * A pointer to the last link in the
                                         * list
                                         */
} DLIST_HEAD;

/*
 * DLIST_HANDLE: Pointer to DLIST_HEAD structure to be used as a handle for the
 * doubly linked list.
 */
typedef DLIST_HEAD *DLIST_HANDLE;

/*
 * DLIST_LINK_HANDLE: Pointer to DLIST_LINK structure to be used as a handle for
 * a link in a doubly linked list.
 */
typedef DLIST_LINK *DLIST_LINK_HANDLE;


/* GLOBAL VARIABLE DECLARATIONS *********************************************/
/* The Omitted Storage Class Model is assumed. The storage class
 * "extern" must be explicitly included on all referencing
 * declarations, and the storage class must omitted from the single
 * defining declaration for each external variable. The defining
 * declaration can include an initializer, but it is not required to
 * do so. It is invalid to have both an initiliazer and the storage
 * class extern in a declaration (ref:[4.8.2; A Reference Manual]).
 *
 * Use global variables for performance improvement and always provide
 * MACROS to manipulate them. E.g. SET(v) and GET.  */

/* PUBLIC FUNCTION PROTOTYPES ***********************************************/



/**
 * Description: Intialises a DLIST_HEAD
 * structure before first use
 *
 * Notes:       Sets ulCount to zero and pFirst to
 * NULL.
 */
extern void DlistInit(DLIST_HANDLE hList);

/**
 * Description: Destroy the link list.
 *
 * Notes:       Frees all links in the list, but not
 *              their items.
 *
 * @param hList
 * @return kal_bool: TRUE if successful, FALSE is not
 */
extern kal_bool DlistDeleteAll(DLIST_HANDLE hList);

/****************************************************************************
 * Function:    DlistInsertAtStart
 * Description: Adds a new link to the start of the doubly linked list
 * Parameters:  hList: Pointer to a DLIST_HEAD structure
 *              pThis: The item to be added to the doubly linked list
 * Returns:     kal_bool: TRUE if successful, FALSE is not
 * Notes:       Allocates memory for a new DLIST_LINK.
 *              Returns TRUE if the memory was allocated, else FALSE.
 ****************************************************************************/

extern kal_bool DlistInsertAtStart(DLIST_HANDLE hList, void *pThis);
extern kal_bool DlistInsertAtFront(DLIST_HANDLE hList, void *pThis, DLIST_LINK_HANDLE hLink);

/****************************************************************************
 * Function:    DlistInsertAtEnd
 * Description: Adds a new link to the end of the doubly linked list
 * Parameters:  hList: Pointer to a DLIST_HEAD structure
 *              pThis: The item to be added to the doubly linked list
 * Returns:     kal_bool: TRUE if successful, FALSE is not
 * Notes:       Allocates memory for a new DLIST_LINK.
 *              Returns TRUE if the memory was allocated, else FALSE.
 ****************************************************************************/

extern kal_bool DlistInsertAtEnd(DLIST_HANDLE hList, void *pThis);

/****************************************************************************
 * Function:    DlistInsertAfter
 * Description: Adds a new link after the given link of the doubly linked list
 * Parameters:  hList: Pointer to a DLIST_HEAD structure
 *              phLink: Pointer to a pointer to the link to insert after
 *              pThis: The item to be added to the doubly linked list
 * Returns:     kal_bool: TRUE if successful, FALSE is not
 * Notes:       Need to use DlistFirst, DlistNext or DlistFind to set phLink
 *              before calling this function.
 *              Allocates memory for a new DLIST_LINK.
 *              Returns TRUE if the memory was allocated, else FALSE.
 ****************************************************************************/

extern kal_bool DlistInsertAfter(DLIST_HANDLE hList,
                       DLIST_LINK_HANDLE *phLink,
                       void *pThis);

/****************************************************************************
 * Function:    DlistInsertBefore
 * Description: Adds a new link before the given link of the doubly linked list
 * Parameters:  hList: Pointer to a DLIST_HEAD structure
 *              phLink: Pointer to a pointer to the link to insert before
 *              pThis: The item to be added to the doubly linked list
 * Returns:     kal_bool: TRUE if successful, FALSE is not
 * Notes:       Need to use DlistFirst, DlistNext or DlistFind to set phLink
 *              before calling this function.
 *              Allocates memory for a new DLIST_LINK.
 *              Returns TRUE if the memory was allocated, else FALSE.
 ****************************************************************************/

extern kal_bool DlistInsertBefore(DLIST_HANDLE hList,
                        DLIST_LINK_HANDLE *phLink,
                        void *pThis);

/****************************************************************************
 * Function:    DlistSort
 * Description: Sorts a doubly linked list into item order
 * Parameters:  hList: Pointer to a DLIST_HEAD structure
 *              Compare: Pointer to a function that compares two items,
 *              pThis and pNext, returning an int which is:
 *                  zero if pThis == pNext
 *                  negative if pThis < pNext
 *                  positive if pThis > pNext
 * Returns:     kal_bool: TRUE if successful, FALSE is not
 * Notes:       DlistSort swaps items on Compare returning a positive result.
 *              To sort into the reverse order, use a different Compare
 *              function that inverts the positive and negative results.
 ****************************************************************************/

extern void DlistSort(DLIST_HANDLE hList, int (*Compare)(void *pThis, void *pNext));

/****************************************************************************
 * Function:    DlistFirst
 * Description: Gets the first item in the doubly linked list and sets the
 *              pointer at phLink for use by DlistNext, DlistInsertAfter or
 *              DlistDelete.
 * Parameters:  hList: Pointer to a DLIST_HEAD structure
 *              phLink: Pointer to a pointer to be set to the first link
 * Returns:     void *: Pointer to pThis of first link, or NULL if empty list.
 * Notes:       Might return NULL if pThis of first link is NULL pointer, or
 *              if the doubly linked list is empty. The pointer at phLink
 *              will be set to NULL if the doubly linked list is empty.
 ****************************************************************************/

extern void *DlistFirst(DLIST_HANDLE hList, DLIST_LINK_HANDLE *phLink);

/****************************************************************************
 * Function:    DlistLast
 * Description: Gets the last item in the doubly linked list and sets the
 *              pointer at phLink for use by DlistPrev, DlistInsertAfter or
 *              DlistDelete.
 * Parameters:  hList: Pointer to a DLIST_HEAD structure
 *              phLink: Pointer to a pointer to be set to the last link
 * Returns:     void *: Pointer to pThis of last link, or NULL if empty list.
 * Notes:       Might return NULL if pThis of last link is NULL pointer, or
 *              if the doubly linked list is empty. The pointer at phLink
 *              will be set to NULL if the doubly linked list is empty.
 ****************************************************************************/

extern void *DlistLast(DLIST_HANDLE hList, DLIST_LINK_HANDLE *phLink);

/****************************************************************************
 * Function:    DlistNext
 * Description: Gets the next item in the doubly linked list and sets the
 *              pointer at phLink for use by DlistInsertAfter or DlistDelete.
 * Parameters:  hList: Pointer to a DLIST_HEAD structure
 *              phLink: Pointer to a pointer to be set to the next link
 * Returns:     void *: Pointer to pThis of next link, or NULL if end of list.
 * Notes:       Might return NULL if pThis of first link is NULL pointer, or
 *              if the end of the doubly linked list has been reached. The
 *              pointer at phLink will be set to NULL if the end of the doubly
 *              linked list has been reached.
 ****************************************************************************/

extern void *DlistNext(DLIST_HANDLE hList, DLIST_LINK_HANDLE *phLink);

/****************************************************************************
 * Function:    DlistThis
 * Description: Gets the current item in the doubly linked. Useful after a call
 *               to DlistDelete, where DlistNext will skip an item
 * Parameters:  hList: Pointer to a DLIST_HEAD structure
 *              phLink: Pointer to a pointer to be set to the next link
 * Returns:     void *: Pointer to pThis of this link.
 * Notes:       Might return NULL if pThis of this link is NULL pointer.
 ****************************************************************************/

extern void *DlistThis(DLIST_HANDLE hList, DLIST_LINK_HANDLE *phLink);

/****************************************************************************
 * Function:    DlistPrev
 * Description: Gets the previous item in the doubly linked list and sets the
 *              pointer at phLink for use by DlistInsertAfter or DlistDelete.
 * Parameters:  hList: Pointer to a DLIST_HEAD structure
 *              phLink: Pointer to a pointer to be set to the previous link
 * Returns:     void *: Pointer to pThis of previous link, or NULL if end of
 *              list.
 * Notes:       Might return NULL if pThis of first link is NULL pointer, or
 *              if the end of the doubly linked list has been reached. The
 *              pointer at phLink will be set to NULL if the end of the doubly
 *              linked list has been reached.
 ****************************************************************************/

extern void *DlistPrev(DLIST_HANDLE hList, DLIST_LINK_HANDLE *phLink);

/****************************************************************************
 * Function:    DlistFind
 * Description: Finds a particular item in a doubly linked list
 * Parameters:  hList: Pointer to a DLIST_HEAD structure
 *              phLink: Pointer to a pointer to be set to the found link
 *              pTarget: Pointer to the "value" being sought
 *              Compare: Pointer to a function that compares an item, pThis,
 *              with the "value" being sought, pTarget, returning an int which
 *              is zero if pThis == pTarget, else non-zero.
 * Returns:     void *: Pointer to pThis of link found, or NULL if not found.
 * Notes:       Sets the pointer at phLink to the link found, for use in
 *              subsequent DlistInsertAfter, DlistDelete or DlistNext calls.
 ****************************************************************************/

extern void *DlistFind(DLIST_HANDLE hList, DLIST_LINK_HANDLE *phLink, void *pTarget,
                int (*Compare)(void *pThis, void *pTarget));

/****************************************************************************
 * Function:    DlistDelete
 * Description: Deletes a particular item in a doubly linked list
 * Parameters:  hList: Pointer to a DLIST_HEAD structure
 *              phLink: Pointer to a pointer the link to be deleted
 * Returns:     kal_bool: TRUE if the pointer at phLink was not NULL, else FALSE
 * Notes:       Sets the pointer at phLink to the next link, for use in
 *              subsequent DlistInsertAfter, DlistDelete or DlistNext calls.
 ****************************************************************************/

extern kal_bool DlistDelete(DLIST_HANDLE hList, DLIST_LINK_HANDLE *phLink);

/****************************************************************************
 * Function:    DlistCount
 * Description: Obtains the number of links in the doubly linked list
 * Parameters:  hList: Pointer to a DLIST_HEAD structure
 * Returns:     kal_uint32: the value of the DLIST_HEAD structure's ulCount field
 * Notes:       Enables functions using Dlist to treat DLIST_HEAD as a handle
 ****************************************************************************/

extern kal_uint32 DlistCount(DLIST_HANDLE hList);

//#define KAREN_TRACE

#ifndef GEN_FOR_PC
//#include <stdio.h>
#endif

#endif /* __DLIST_H__ */
