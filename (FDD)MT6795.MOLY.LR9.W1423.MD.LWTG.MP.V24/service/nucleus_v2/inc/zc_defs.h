/***********************************************************************
*
*            Copyright 1993 Mentor Graphics Corporation
*                         All Rights Reserved.
*
* THIS WORK CONTAINS TRADE SECRET AND PROPRIETARY INFORMATION WHICH IS
* THE PROPERTY OF MENTOR GRAPHICS CORPORATION OR ITS LICENSORS AND IS
* SUBJECT TO LICENSE TERMS.
*
************************************************************************

************************************************************************
*
*   FILE NAME
*
*       zc_defs.h
*
*   COMPONENT
*
*       ZC - Zero Copy
*
*   DESCRIPTION
*
*       This file provides the internal interfaces to the
*       Nucleus Zero Copy components
*
*   DATA STRUCTURES
*
*       ZC_OBJ_DEBUG
*       ZC_GLOBAL_OBJ_DEBUG
*       ZC_GLOBAL_DATA
*       ZC_AVAILABLE
*       ZC_DATA
*       ZC_SEGMENT
*       ZC_BUFFER
*       ZC_OBJECT
*
*   DEPENDENCIES
*
*       zc_extr.h
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
***********************************************************************/

#ifndef     ZC_DEFS_H
#define     ZC_DEFS_H

#ifdef          __cplusplus

/* C declarations in C++     */
extern          "C" {

#endif

/* Include required header files */
#include    "zc_extr.h"

/*******************************
* TESTING DEFINITIONS
*******************************/

/* Setting NU_ZC_TEST_ENABLE to NU_TRUE makes all file "static" variables and
   functions contained in the Zero Copy Software to become global variables and
   functions.  Additionally, all internally referenced functions are mapped to
   external functions that must be defined by the test software.  This allows unit
   testing through external drivers and stub functions.  The default setting of
   NU_FALSE makes all internal functions "static" to limit their scope to
   the file level.*/
#define         NU_ZC_TEST_ENABLE                   NU_FALSE

/*******************************
* STRUCTURE DEFINITIONS
*******************************/

/* Define object elements used when debugging is enabled.  These
   object elements will be added to each object to facilitate debugging
   zero copy objects in memory. */
typedef struct
{
    NU_UINT32              obj_id;         /* Object ID for the given object                   */
    union _ZC_OBJECT *  next_obj;       /* Pointer to the next object in memory             */

} ZC_OBJ_DEBUG;

/* Define some debug elements specific to the global object */
typedef struct
{
    NU_UINT32              avail_objects;  /* Number of objects available                      */
    NU_UINT32              data_objects;   /* Number of objects being used as data objects     */
    NU_UINT32              seg_objects;    /* Number of objects being used as segment objects  */
    NU_UINT32              buf_objects;    /* Number of objects being used as buffer objects   */

} ZC_GLOBAL_OBJ_DEBUG;

/*********************
* GLOBAL DATA struct
*********************/

typedef struct
{
#if (NU_DEBUG_ENABLE == NU_TRUE)

    ZC_OBJ_DEBUG    obj_debug;      /* Debug specific data common to all zero copy objects      */
    ZC_GLOBAL_OBJ_DEBUG
                    global_debug;   /* Debugging elements specific to the global object - see
                                       zc_debug_defs.h                                          */

#endif  /* NU_DEBUG_ENABLE == NU_TRUE */

    NU_UINT32          avail_head_id;  /* Object ID of first available object                      */
    NU_UINT32          avail_tail_id;  /* Object ID of last available object                       */
    NU_UINT32          count_bits;     /* Number of bits used as count bits for the unique
                                       32-bit ID for buffers                                    */
    NU_UINT32          count_bit_mask; /* Value used to mask out all but count bits within a
                                       32-bit ID for a buffer                                   */
    NU_UINT32          total_objects;  /* Total number of objects in the system                    */

} ZC_GLOBAL_DATA;

/*********************
* AVAILABLE OBJ struct
*********************/

typedef struct
{
#if (NU_DEBUG_ENABLE == NU_TRUE)

    ZC_OBJ_DEBUG    obj_debug;      /* Debug specific data common to all zero copy objects      */

#endif  /* NU_DEBUG_ENABLE == NU_TRUE */

    NU_UINT32          type;           /* Set to ZC_Available_Type                                 */
    NU_UINT32          unused;         /* Not used for ZC Available object                         */
    NU_UINT32          next_obj_id;    /* ID of next available object                              */

} ZC_AVAILABLE;

/*********************
* DATA OBJ struct
*********************/

typedef struct
{
#if (NU_DEBUG_ENABLE == NU_TRUE)

    ZC_OBJ_DEBUG    obj_debug;      /* Debug specific data common to all zero copy objects      */

#endif  /* NU_DEBUG_ENABLE == NU_TRUE */

    NU_UINT32          type;           /* ZC_DATA_TYPE                                             */
    NU_UINT32          unused;         /* Not used for ZC Data object                              */
    NU_UINT32          data_refs;      /* Number of ZC Segments that reference this data           */
    NU_UINT32          mem_ptr;        /* Pointer to the data buffer that this object references   */
    NU_UINT32          length;         /* Length of the memory referenced by this object           */
    NU_UINT32          cb_func_ptr;    /* Pointer to the application supplied call-back function   */
    NU_UINT32          cb_param;       /* Application supplied parameter for the call-back function*/

} ZC_DATA;

/*********************
* SEGMENT OBJ struct
*********************/

typedef struct
{
#if (NU_DEBUG_ENABLE == NU_TRUE)

    ZC_OBJ_DEBUG    obj_debug;      /* Debug specific data common to all zero copy objects      */

#endif  /* NU_DEBUG_ENABLE == NU_TRUE */

    NU_UINT32          type;           /* ZC_SEGMENT_TYPE                                          */
    NU_UINT32          unused;         /* Not used for ZC Segment object                           */
    NU_UINT32          parent_id;      /* ID of the ZC Buffer that the Segment is part of          */
    NU_UINT32          prev_seg_id;    /* ID of Previous Segment in the ZC Buffer (may be NULL)    */
    NU_UINT32          next_seg_id;    /* ID of Next Segment in the ZC Buffer (may be NULL)        */
    NU_UINT32          data_obj_id;    /* ID to the ONE ZC DATA object referenced by this Segment  */
    NU_UINT32          mem_offset;     /* Positive offset from the start of the memory buffer
                                       pointed to by this segment to the memory referenced.     */
    NU_UINT32          length;         /* Length of the memory (from the mem_offset) referenced by
                                       this Segment.                                            */

} ZC_SEGMENT;

/*********************
* BUFFER OBJ struct
*********************/

typedef struct
{
#if (NU_DEBUG_ENABLE == NU_TRUE)

    ZC_OBJ_DEBUG    obj_debug;      /* Debug specific data common to all zero copy objects      */

#endif  /* NU_DEBUG_ENABLE == NU_TRUE */

    NU_UINT32          type;           /* ZC_BUFFER_TYPE                                           */
    NU_UINT32          id;             /* Holds ZC_Object_Id & ZC_Object_Count_Bits                */
    NU_UINT32          head_seg_id;    /* ID of First Segment in the ZC Buffer (may be NULL)       */
    NU_UINT32          tail_seg_id;    /* ID of Last Segment in the ZC Buffer (may be NULL)        */
    NU_UINT32          length;         /* Total number of data bytes contained the ZC Buffer       */

} ZC_BUFFER;


/*********************
* OBJECT union
*********************/

/* Define Zero Copy OBJECT type.  A Zero Copy OBJECT is an object that
   encapsulates the properties of a global object, a data object, a
   segment object, a buffer object, and an available object.  An object
   can be used for any of these purposes. */
typedef union _ZC_OBJECT
{
    ZC_GLOBAL_DATA  global;
    ZC_DATA         data;
    ZC_SEGMENT      seg;
    ZC_BUFFER       buf;
    ZC_AVAILABLE    avail;

} ZC_OBJECT;

/*******************************
* TYPE DEFINITIONS
*******************************/

/* Typedef for object id and type */
typedef             NU_UINT32                      ZC_OBJ_ID;
typedef             NU_UINT32                      ZC_OBJ_TYPE;

/* Define for "static" variables / data used to allow testing
   of internal functions using external drivers / stub functions */
#if (NU_ZC_TEST_ENABLE == NU_TRUE)

/* Define STATIC as nothing to make internal functions / variables
   globally visible */
#define             STATIC

#else

/* Define STATIC as static to make internal functions / variables
   have file level scope */
#define             STATIC                      static

#endif  /* NU_ZC_TEST_ENABLE == NU_TRUE */

/*******************************
* CONSTANTS
*******************************/

/* Define the Initialization Status constant.   */
#define             ZC_INIT_NOT_COMPLETE       -1

/* Define zero copy object size */
#define             ZC_OBJECT_SIZE              sizeof(ZC_OBJECT)

/* Define values for the zero copy object types */
#define             ZC_AVAILABLE_TYPE           0
#define             ZC_DATA_TYPE                1
#define             ZC_SEGMENT_TYPE             2
#define             ZC_BUFFER_TYPE              3

/* Define object ID of first object available
   for use (as data, segment, or buffer) */
#define             ZC_FIRST_AVAIL_OBJ_ID       1

/* Define the number of bits (multiply number of bytes x 8) used for a buffer ID */
#define             ZC_BUF_ID_NUM_BITS          (sizeof(ZC_BUF_ID) * 8)

/*******************************
* EXTERNAL DATA REFERENCES
*******************************/

/* Starting memory address for ALL ZC objects (set during initialization). */
extern              ZC_OBJECT *                 ZC_Objects_Base_Addr;

/*******************************
* MACROS
*******************************/

/*  The ZC Macros are available to improve the readability of the code and provide
    any commonly used functionality in the form of a macro.*/

/* Define a macro to get a pointer to the global data structure */
#define ZC_GLOBAL_DATA_GET()                                                            \
            (ZC_GLOBAL_DATA *)ZC_Objects_Base_Addr

/* Define macro to get object pointer (obj_ptr) from object ID (obj_id) number:
   MULTIPLY the object ID and the object size then ADD the base for the
   objects (ZC_Objects_Base_Addr) */
#define ZC_OBJ_PTR_GET(obj_id)                                                          \
            (ZC_OBJECT *)(((ZC_OBJ_ID)(obj_id) * ZC_OBJECT_SIZE) +                      \
                          (NU_UINT32)ZC_Objects_Base_Addr)

/* Define macro to create a unique ZC Buffer ID (buf_id) using the ZC Object Pointer:
   INCREMENT the buffer ID (increment the count bits / low order bits of buffer ID) */
#define ZC_BUF_ID_CREATE(obj_ptr)                                                       \
            ++((obj_ptr) -> buf.id)

/* Define macro to get the Object Number (obj_id) using the ZC Buffer ID (buf_id):
   SHIFT RIGHT the buffer ID by the ZC_Object_Count_Bits value (extracts the object ID) */
#define ZC_OBJ_ID_FROM_BUF_ID_GET(buf_id)                                               \
            ((buf_id) >> (ZC_Objects_Base_Addr -> global.count_bits))

/* Define macro to get the Object Pointer (obj_ptr) using the ZC Buffer ID:
   GET the object ID from the buffer ID (see ZC_OBJ_ID_FROM_BUF_ID_GET macro above)
   then GET the object pointer using the object ID (see ZC_OBJ_ADDR_GET macro above) */
#define ZC_OBJ_PTR_FROM_BUF_ID_GET(buf_id)                                              \
            ZC_OBJ_PTR_GET(ZC_OBJ_ID_FROM_BUF_ID_GET(buf_id))

/* Define macro to set the Object Type (obj_type) using the obj_id:
   GET the object pointer from the object ID (see ZC_OBJ_PTR_GET macro above) then
   set the type to obj_type */
#define ZC_OBJ_TYPE_SET(obj_type, obj_id)                                               \
            (ZC_OBJ_PTR_GET(obj_id)) -> buf.type = (ZC_OBJ_TYPE)(obj_type)

/* Define macro to ensure that the address used within the Zero Copy function is the
   optimal address (offset is within the designated segment).
   Test offset is GREATER THAN or EQUAL to 0 (not negative) AND that the segment
   ID is NOT NULL AND that the offset is LESS THAN the length of the segment.  Returns
   the original segment ID if all cases above are TRUE; otherwise, calls ZC_SEG_OPTIMAL_GET
   function and returns the value returned by this function */
#define ZC_SEG_OPTIMAL_ENSURE(buf_id, seg_id, offset_ptr)                                   \
            (((*(offset_ptr) >= 0) && ((seg_id) != NU_NULL) &&                              \
              (*(offset_ptr) < (NU_INT)((ZC_OBJ_PTR_GET(seg_id)) -> seg.length))) ? (seg_id) : \
              ZC_SEG_OPTIMAL_GET(buf_id, seg_id, offset_ptr))

/* Define macro to ensure that the segment ID, if NULL, is converted into the appropriate
   non-NULL value.  A NULL value for the segment ID is the same as the head segment for
   the segment.  This macro will return the segment ID if non-NULL and returns the
   buffer's head segment ID if the segment ID is NULL.
   Test if segment ID does NOT EQUAL NULL.  Return the segment ID if TRUE; return the
   head segment ID for the buffer if FALSE */
#define ZC_SEG_NONNULL_ENSURE(buf_id, seg_id)                                           \
            ((seg_id) != NU_NULL ? (seg_id) :                                           \
             (ZC_SEG_ID)((ZC_OBJ_PTR_FROM_BUF_ID_GET(buf_id)) -> buf.head_seg_id))

/* Define macro to increment the number of references for a given data object.
   Convert the object ID to an object pointer than increment the data reference count */
#define ZC_DATA_REF_ADD(obj_id)                                                         \
            ((ZC_OBJ_PTR_GET(obj_id)) -> data.data_refs)++

/* Define a macro to check if a Zero Copy buffer is empty:
   Test if the buffer head segment ID is EQUAL to NULL */
#define ZC_BUF_EMPTY_CHECK(buf_object)                                                  \
            ((buf_object) -> buf.head_seg_id == NU_NULL)

/* Define a macro to check if a given segment / offset address is the beginning of
   the Zero Copy buffer:
   Test if the buffer head segment ID is EQUAL to the segment ID AND if the
   offset within the segment is EQUAL to 0 */
#define ZC_BUF_BEGIN_CHECK(buf_obj, seg_id, offset)                                     \
            ((((buf_obj) -> buf.head_seg_id) == (seg_id)) && ((offset) == 0))

/* Define a macro to check if a given segment / offset address is the end of the
   Zero Copy buffer:
   Test if the buffer tail segment ID is EQUAL to the segment ID AND if the
   offset within the segment is EQUAL to the length of the segment */
#define ZC_BUF_END_CHECK(buf_obj, seg_id, offset)                                       \
            ((((buf_obj) -> buf.tail_seg_id) == (seg_id)) &&                            \
             ((offset) == (NU_INT)((ZC_OBJ_PTR_GET(seg_id)) -> seg.length)))

/* Define a macro to check if a given segment is the only segment within the
   Zero Copy buffer:
   Test if the buffer head segment ID is EQUAL to the buffer tail segment ID */
#define ZC_ONE_SEG_CHECK(buf_obj_ptr)                                                   \
            ((buf_obj_ptr) -> buf.tail_seg_id == (buf_obj_ptr) -> buf.head_seg_id)

/* Define macro to check if address is 4-byte aligned.
   CAST the memory address as an unsigned 32-bit value, BITWISE AND the address
   with 3 and check if EQUAL to 0 (TRUE returned if 4-byte aligned) */
#define ZC_4BYTE_ALIGN_CHECK(mem_addr)                                                  \
            (((NU_UINT32)(mem_addr) & 3UL) == 0)

/* Define macro to align memory address on 4-byte boundary:
   ADD the size of a NU_UINT32 to the memory address then AND the result to clear the
   lower 2 bits */
#define ZC_4BYTE_ALIGN_GET(mem_addr)                                                    \
            (NU_VOID *)(((NU_UINT32)(mem_addr) + sizeof(NU_UINT32)) & 0xFFFFFFFCUL)


/*******************************
* DEFINITIONS / TERMINOLOGY
*******************************/

/* This section is simply an overview of definitions and terminology used
   in the Zero Copy software */

/*  OBJECT Pointer (obj_ptr)
    =========================

        Physical address of the ZC Object structure

            EXAMPLE 1
            ---------

                                        PHYSICAL ADDR

               object pointer --------->0xC0000000 +---------+
                                                   |ZC_OBJECT|
                                                   |         |
                                                   |         |
                                        0xC0000020 +---------+
                                                   |ZC_OBJECT|
                                                   |         |
                                                   |         |
                                        0xC0000040 +---------+


    BUFFER ID (buf_id)
    ==================

        Unique 32-bit ID for each ZC Buffer where:
            - Upper portion contains the Object ID (see below)
            - Lower portion is used as a counter to create a unique ID for each ZC Buffer.

            NOTE:  The count bits are incremented each time the object is allocated for
                   use as a ZC Buffer.

        EXAMPLE 2
        ---------

                                      BUFFER ID (32-bits)

            |       obj_id          |                    count bits                  |
            |-----------------------|------------------------------------------------|
            |                       |<--------------object ID count bits------------>|

          bit 31                  bit n                                            bit 0

                                where n = object ID count bits


    OBJECT ID (obj_id)
    ==================

        The relative number of each object within the entire group of objects.

        The numbers are sequential and represent the relative location of
        each ZC Object structure within the total group of ZC Object structures.

            EXAMPLE 3
            ---------

                    PHYSICAL ADDR

                    0xC0000000 +---------+<-------------- START OF ZC OBJECTS = ZC_Objects_Base_Addr
                               |ZC_OBJECT|
                               |         |<-------------- object ID = 0
                               |         |
                    0xC0000020 +---------+
                               |ZC_OBJECT|
                               |         |<-------------- object ID = 1
                               |         |
                    0xC0000040 +---------+
                               |ZC_OBJECT|
                               |         |<-------------- object ID = 2
                               |         |
                    0xC0000060 +---------+


    OBJECT TYPE (obj_type)
    ======================

        This value represents how the data object is currently being utilized within the ZC software.
        A ZC Object can be one of the following 4 types at any given time:

            ZC_AVAILABLE_TYPE   -   ZC Object is available for use (not used as a data, segment, or buffer)
            ZC_DATA_TYPE        -   ZC Object is being used as a data object
            ZC_SEGMENT_TYPE     -   ZC Object is being used as a segment object
            ZC_BUFFER_TYPE      -   ZC Object is being used as a buffer object

    SEGMENT ID (seg_id)
    ===================

        Object ID of a ZC Object being used as a segment (when OBJECT TYPE = ZC_SEGMENT_TYPE)

    ZC_Objects_Base_Addr
    ====================

        Starting address (base) of the contiguous group of ZC objects.

        See EXAMPLE 3 above.

    ZC_OBJECT_SIZE
    ==============

        Size of the ZC Object data structure.  This size is the maximum sized data structure contained
        within the ZC Object union.

        The following 5 data structures are contained within the ZC Object union:

                    ZC_GLOBAL_DATA
                    ZC_DATA
                    ZC_SEGMENT
                    ZC_BUFFER
                    ZC_AVAILABLE
*/

/*******************************
* INTERNAL FUNCTION MAPPINGS
*******************************/

#if (NU_ZC_TEST_ENABLE == NU_FALSE)

/* The following defines are used to map all internal called functions (upper-case) to
   the actual function names (mixed case).  If testing, all internal called functions
   must be implemented within the test code.  This allows the use of test code drivers
   and stubs when performing unit testing */

/* Active Functions */
#define ZC_INITIALIZE           ZC_Initialize
#define ZC_BUF_CREATE           ZC_Buf_Create
#define ZC_BUF_DELETE           ZC_Buf_Delete
#define ZC_BUF_INSERT           ZC_Buf_Insert
#define ZC_BUF_SPLIT            ZC_Buf_Split
#define ZC_BUF_DUPLICATE        ZC_Buf_Duplicate
#define ZC_DATA_INSERT          ZC_Data_Insert
#define ZC_DATA_COPY_INSERT     ZC_Data_Copy_Insert
#define ZC_DATA_REMOVE          ZC_Data_Remove
#define ZC_SEG_CREATE           ZC_Seg_Create
#define ZC_SEG_CHAIN_INSERT     ZC_Seg_Chain_Insert
#define ZC_SEG_SPLIT            ZC_Seg_Split
#define ZC_SEG_DATA_REMOVE      ZC_Seg_Data_Remove
#define ZC_SEG_DELETE           ZC_Seg_Delete
#define ZC_DATA_CREATE          ZC_Data_Create
#define ZC_DATA_REF_REMOVE      ZC_Data_Ref_Remove
#define ZC_OBJ_ALLOCATE         ZC_Obj_Allocate
#define ZC_OBJ_DEALLOCATE       ZC_Obj_Deallocate
#define ZC_MEM_ALLOCATE         ZC_Mem_Allocate
#define ZC_MEM_FREE             ZC_Mem_Free

/* Passive Functions */
#define ZC_BUF_LEN_GET          ZC_Buf_Len_Get
#define ZC_DATA_COPY_GET        ZC_Data_Copy_Get
#define ZC_SEG_OPTIMAL_GET      ZC_Seg_Optimal_Get
#define ZC_SEG_NEXT_GET         ZC_Seg_Next_Get
#define ZC_SEG_PREV_GET         ZC_Seg_Prev_Get
#define ZC_SEG_DATA_GET         ZC_Seg_Data_Get
#define ZC_SEG_LEN_GET          ZC_Seg_Len_Get

/* Passive Error Checking Functions */
#define ZCE_BUF_SEG_ERROR_CHECK ZCE_Buf_Seg_Error_Check

#endif  /* NU_ZC_TEST_ENABLE == NU_FALSE */

/*******************************
* GLOBAL FUNCTION PROTOTYPES
*******************************/

/* This section provides the prototypes for all the global functions using
   their internal names (ZC_*).  This allows any of these functions to
   be called from other Zero Copy functions. */

/* Define function prototypes for Zero Copy ACTIVE functions */
NU_STATE      ZC_INITIALIZE(NU_MEMORY_POOL *, NU_INT);
ZC_BUF_ID   ZC_BUF_CREATE(NU_VOID);
NU_STATE      ZC_BUF_DELETE(ZC_BUF_ID);
ZC_SEG_ID   ZC_BUF_INSERT(ZC_BUF_ID, ZC_SEG_ID, NU_INT, ZC_BUF_ID);
ZC_BUF_ID   ZC_BUF_SPLIT(ZC_BUF_ID, ZC_SEG_ID, NU_INT);
ZC_BUF_ID   ZC_BUF_DUPLICATE(ZC_BUF_ID, ZC_SEG_ID, NU_INT, NU_INT);
ZC_SEG_ID   ZC_DATA_INSERT(ZC_BUF_ID, ZC_SEG_ID, NU_INT, NU_CHAR *, NU_INT, NU_VOID (*)(NU_CHAR *, NU_INT), NU_INT);
ZC_SEG_ID   ZC_DATA_COPY_INSERT(ZC_BUF_ID, ZC_SEG_ID, NU_INT, NU_CHAR *, NU_INT);
ZC_SEG_ID   ZC_DATA_REMOVE(ZC_BUF_ID, ZC_SEG_ID, NU_INT, NU_INT);

/* Define function prototypes for Zero Copy PASSIVE functions */
NU_INT         ZC_BUF_LEN_GET(ZC_BUF_ID);
NU_INT         ZC_DATA_COPY_GET(ZC_BUF_ID, ZC_SEG_ID, NU_INT, NU_CHAR *, NU_INT);
ZC_SEG_ID   ZC_SEG_OPTIMAL_GET(ZC_BUF_ID, ZC_SEG_ID, NU_INT *);
ZC_SEG_ID   ZC_SEG_NEXT_GET(ZC_BUF_ID, ZC_SEG_ID);
ZC_SEG_ID   ZC_SEG_PREV_GET(ZC_BUF_ID, ZC_SEG_ID);
NU_CHAR *      ZC_SEG_DATA_GET(ZC_BUF_ID, ZC_SEG_ID);
NU_INT         ZC_SEG_LEN_GET(ZC_BUF_ID, ZC_SEG_ID);
NU_INT         ZCE_BUF_SEG_ERROR_CHECK(ZC_BUF_ID, ZC_SEG_ID);

#ifdef          __cplusplus

/* End of C declarations */
}

#endif  /* __cplusplus */

#endif      /* ZC_INTERN_APIS_H */
