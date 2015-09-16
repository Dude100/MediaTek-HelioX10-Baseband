/* *****************************************************************
 * sha.h
 * ? Copyright 1994 John Halleck
 * All rights reserved
 *
 * --ABSTRACT-- sha.h
 * This implements the "Secure Hash Algorithm" as per the original
 * NIST specs, with the latest NIST version as an option.
 *
 * --KEYWORDS-- sha.h
 *
 * --CONTENTS-- sha.h
 * Date, Department, Author
 *    20may1994, John Halleck
 * Revision history
 *    For each revision: Date, change summary, authorizing document,
 *    change department, section, author
 *    20may1994, Initial Creation, John Halleck
 *     1aug1994, Changes per NIST
 *    19nov1994, portablility changes, output string code.
 *   20apr1995, change to default context option, John Halleck.
 * Unit purpose
 *    (What does this do?)
 *    Secure hash function with the NIST modifications, and renamed
 *    routines.
 * External Units accessed
 *    Name, purpose, access summary
 *    [None]
 * Exceptions propagated by this unit
 *    [None]
 * Machine-dependencies
 *    Access type, purpose, and justification
 *    Assumes there is a 32 bit word availiable on the machine.
 * Compiler-dependencies
 *    [None]
 ********************************************************************
 */

/* Random note: This standard was originally proposed to provide a hash function
 * for the Digital Signature Standard that was proposed in August 1991 
 */


/*****************************************************************************
 *
 * Filename:
 * ---------
 *    sha1.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   SHA1 Engine
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * code review. remove unused definitions.
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __SHA1_H__
#define __SHA1_H__

#define BITS8  unsigned char
#define BITS16 unsigned short
#define BITS32 unsigned long
#define ARGCARGV
#define PROTOTYPES



/* Defines common to everything */

#define SHF_DIGESTSIZE 20
/* Put out a digest of this size in bytes */
#define SHF_DIGESTWORDSIZE 5
/* and words */

#define SHF_BLOCKSIZE  64
#define SHF_BLOCKWORDSIZE 16
/* Process messages in this block size */

/* Structure for storing SHF info */

typedef BITS32 shadigest[SHF_DIGESTWORDSIZE];
typedef BITS8  sha1_digest[SHF_DIGESTSIZE];

typedef struct {
  BITS32    data [SHF_BLOCKWORDSIZE];     /* SHS data buffer */
  BITS32    countLo;       /* Count (64 bits in              */
  BITS32    countHi;       /* 2 32 bit words)                */
  shadigest digest;        /* Message digest                 */
  int       kind;          /* Which type of SHA?             */
  int       thisword;      /* Which word are we processing?  */
  int       thisbyte;      /* Which byte in that word?       */
  int		length; //Julie1213
} sha1_context, *sha1_context_ptr;

/* These routines all take a context, so that multiple streams can be
 * handled.  If you pass NULL, then a single package wide canned context
 * will be used.
 */

/* Initialize a stream */
void CHE_sha1_Init       (sha1_context_ptr context);
/* Version 0 - Original NIST version (Obsolete) */
/*             (30 January 1995) */
/* Version 1 - lastest NIST modifications    */

/* Add a buffer's worth of characters to the current hash. */
void CHE_sha1_append     (sha1_context_ptr context, BITS8 *buffer, int count);

/* Add a string's worth of characters to the current hash. */
void CHE_shaStrUpdate  (sha1_context_ptr context, char *input);

/* Done, report the final hash. */
void CHE_sha1_finish      (sha1_context_ptr context, sha1_digest adigest);

/* And for all you bit twiddlers out there, the machine independent
 * Digest to digest string routines.
 */
 
/* digest from context */
void CHE_shaBytes (sha1_context_ptr context, sha1_digest adigest);
/* string from digest */
void CHE_shaString (sha1_digest adigest, char *outputstring);

/* hash of a buffer */
/* This returns directly the SHA digest of the characters in a buffer. */
void CHE_shaHash (int version, BITS8 *buffer, int count, sha1_digest adigest);

void CHE_sha1_hmac( unsigned char *key, int keylen,
                unsigned char *input, int ilen,
                unsigned char output[20] );


#endif /* __SHA1_H__ */

