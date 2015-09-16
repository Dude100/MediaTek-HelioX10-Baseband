#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "GFH_defs.h"
#include "br_GFH_error.h"
#include "br_GFH.h"
#include "br_GFH_file_info.h"
#include "boot_cert_pattern.h"
#include "custom_secure_config.h"



#if defined(__BOOT_CERT__)


extern kal_uint32 BOOT_CERT_DATA$$Base;
extern kal_uint32 BOOT_CERT_DATA$$Length;


#if defined (_NAND_FLASH_BOOTING_)
#define DEVICE_TYPE           F_NAND_FDM50
#elif defined (__EMMC_BOOTING__)
#define DEVICE_TYPE           F_EMMC_DATA_REGION
#elif defined(__X_BOOTING__)
#define DEVICE_TYPE           F_XBOOT
#else

#if defined(__SERIAL_FLASH_EN__)
#define DEVICE_TYPE           F_SF
#else
#define DEVICE_TYPE           F_NOR
#endif

#endif

/* ------------------------------------- */
/* V1 structure */
/* ------------------------------------- */
#if defined(__BOOT_CERT_V1__)
const MTK_SRDInfo_v01_ST g_SRD_INFO = 
{
    "MTK_SRDINFO_V01",
    0x1,
    (kal_uint32)(&BOOT_CERT_DATA$$Base),
    {BOOT_CERT_CTRL_PATTERN }

};


#elif defined(__BOOT_CERT_V2__)
/* ------------------------------------- */
/* V2 structure */
/* ------------------------------------- */
const MTK_SRDInfo_v02_ST g_SRD_INFO = 
{
    "MTK_SRDINFO_V02",
    0x2,
    (kal_uint32)(&BOOT_CERT_DATA$$Base),
    {BOOT_CERT_CTRL_PATTERN },
    {0}

};


#else

#error "no boot cert structure match this"

#endif /* */


/* ------------------------------------- */
/* global information */
/* ------------------------------------- */
#ifdef __MTK_TARGET__
__attribute__ ((section("BOOT_CERT_SIG")))
#endif /* __MTK_TARGET__ */
const kal_uint32 g_boot_cert_sig[SIG_SINGLE_AND_PHASH_LEN>>2] = {SIG_HASH_VER};


#ifdef __MTK_TARGET__
__attribute__ ((section("BOOT_CERT_DATA")))
#endif /* __MTK_TARGET__ */
const DL_CTRL_FORMAT_ST DL_CTRL_BIN = 
{
    
    //GFH_FILE_INFO_v1
    {  
       GFH_HEADER(GFH_FILE_INFO, 1),
       GFH_FILE_INFO_ID,
       1,
       BOOT_CERT_CTRL,
       DEVICE_TYPE,
       SIG_SINGLE_AND_PHASH,
       (kal_uint32)(&BOOT_CERT_DATA$$Base),
       sizeof(DL_CTRL_FORMAT_ST)+ sizeof(g_boot_cert_sig),          //File Length, filled out by post-build
       32*1024,
       (kal_uint32)(&BOOT_CERT_DATA$$Length),
       SIG_SINGLE_AND_PHASH_LEN,
       0,
       0
    },

    //GFH_BOOT_CERT_CTRL_CONTENT
    {
        GFH_HEADER(GFH_BOOT_CERT_CTRL_CONTENT, 1)
        ,{ BOOT_CERT_CTRL_PATTERN }
        ,{ 0 }
        ,{ 0 }
        ,{ 0 }
     }
};

#endif /* __BOOT_CERT__ */

