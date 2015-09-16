##############################################################
# Define bootloader folder path
##############################################################
ifneq ($(filter __SV5X_ENABLED__, $(strip $(MODULE_DEFS))),)
BL_PATH = bootloader_lte
else
BL_PATH = bootloader
endif

# Define source file lists to SRC_LIST
           
ifneq ($(filter __SV5_ENABLED__ __SV5X_ENABLED__,$(strip $(MODULE_DEFS))),)
SRC_LIST = service/sss/components/src/SSS_secure_shared_common.c \
           service/sss/components/src/RSA.c \
           service/sss/components/src/sha1_sw.c \
           service/sss/components/src/SSS_secure_shared_v5.c \
           service/sss/components/src/SSS_Secure_v5.c \
           service/sss/components/crypto/src/br_crypto_common.c \
           service/sss/components/crypto/src/br_crypto_drv.c \
           service/sss/components/crypto/src/br_crypto_drv_AES_HW.c \
           service/sss/components/crypto/src/br_crypto_drv_AES_SW.c \
           service/sss/components/crypto/src/br_crypto_drv_M1_RSA.c \
           service/sss/components/crypto/src/br_crypto_drv_SOE_AES_HW.c \
           service/sss/components/crypto/src/br_crypto_drv_SEJ_AES_HW.c \
           service/sss/components/crypto/src/br_crypto_drv_SEJ_AES_SW.c \
           service/sss/components/crypto/src/br_crypto_drv_SEJ_3DES_HW.c \
           service/sss/components/crypto/src/br_crypto_drv_SEJ_3DES_SW.c \
           service/sss/components/crypto/src/br_crypto_drv_3DES_HW.c \
           service/sss/components/crypto/src/br_crypto_drv_3DES_SW.c \
           service/sss/components/crypto/src/br_crypto_drv_3DES_util.c \
           service/sss/components/crypto/src/br_crypto_drv_SHA256_HW.c \
           service/sss/components/crypto/src/br_crypto_drv_SHA256_SW.c \
           service/sss/components/crypto/src/br_crypto_drv_SHA1_HW.c \
           service/sss/components/crypto/src/br_crypto_drv_SHA1_SW.c \
           service/sss/components/crypto/src/br_crypto_lib.c \
           service/sss/components/crypto/src/br_crypto_scheme.c \
           service/sss/components/crypto/src/br_sd_crypto.c \
           service/sss/components/crypto/src/br_M1_RSA.c \
           service/sss/components/crypto/src/br_sha256_hw.c \
           service/sss/components/crypto/src/br_sha256_sw.c \
           service/sss/components/crypto/src/br_sha1_hw.c \
           service/sss/components/crypto/src/br_sha1_sw.c \
           service/sss/components/crypto/src/br_aes_sw.c \
           service/sss/components/crypto/src/br_3des_sw.c \
           service/sss/components/src/bl_Secure_common.c \
           service/sss/components/src/bl_Secure_v5.c \
           service/sss/components/src/bl_FactoryConn.c

ifeq ($(strip $(COMPILER)),GCC)
SRC_LIST    += service/sss/components/crypto/src/br_crypto_asm_gcc.S
else
SRC_LIST    += service/sss/components/crypto/src/br_crypto_asm.S
endif

else
SRC_LIST = service/sss/components/src/SSS_secure_dummy.c

endif
 
# Define include path lists to INC_DIR
INC_DIR = service/sst/include \
          service/sst/include_sec \
          service/sss/components/inc \
          service/sss/interface/inc \
          driver/drv/include \
          service/sys_svc/$(BL_PATH)/inc \
          driver/dp_engine/che/include \
          service/sss/interface/crypto/export/public \
          service/sss/components/crypto/export/private \
          service/sss/components/crypto/inc \
          service/sss/components/GFH/private \
          service/sys_svc/gfh/public \
          service/sys_svc/cbr/inc \
          service/sys_svc/profile/inc \
          service/security/sds
 
# Define the specified compile options to COMP_DEFS
COMP_DEFS = APCS_INTWORK \
            __MTK_SECURE_PLATFORM__ \
            __CP_DEFINED_ALL_CONTEXT__ \
            __CP_DEFINED_WORKING_BUF__ \
            __CRYPTO_ENCRYPT__  \
            __CRYPTO_SCHEME__ \
            __CRYPTO_LIB__ \
            __CS_SIG_SINGLE__ \
            __CS_MTK_CIPHER__ \
            __CS_CIPHER__ \
            __CS_HASH__ \
            __CL_GFH_SIG__ \
            __CL_MTK_CIPHER__ \
            __CL_SIG_SINGLE_AND_PHASH_V1__ \
            __CL_SIG_MULTI_V1__ \
            __RSA_SW__ \
            __SHA256_SW__ \
            __SHA256_HW__ \
            __SHA1_SW__ \
            __SHA1_HW__ \
            __SOE_AES_HW__ \
            __SEJ_AES_HW__ \
            __SEJ_3DES_HW__ \
            __AES_SW__ \
            __AES_HW__ \
            __3DES_SW__  \
            __3DES_HW__ \
            __TIME_STAMP__

# Turn-on asembly support. To sync with BootROM
COMP_DEFS +=__SHA1_HW_ASM__ \
            __SEJ_AES_HW_ASM__

# Define the source file search paths to SRC_PATH
SRC_PATH = service/sss/components/src \
           service/sss/components/crypto/src
 
