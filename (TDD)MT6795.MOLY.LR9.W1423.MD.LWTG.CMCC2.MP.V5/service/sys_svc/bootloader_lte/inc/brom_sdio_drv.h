#ifndef __BROM_SDIO_DRV_H__
#define __BROM_SDIO_DRV_H__ 

#define BROM_SDIO_UL_QUE    0
#define BROM_SDIO_DL_QUE    0

/*
typedef enum _brom_sdio_link_st{
	BROM_SDIO_LINK_OFF = 0,
	BROM_SDIO_LINK_ON,
} brom_sdio_link_st_e;
*/

typedef enum _brom_sdio_sync_rslt{
	BROM_SDIO_SYNC_FALSE = 0,
	BROM_SDIO_SYNC_XBOOT,
	BROM_SDIO_SYNC_GDB,
} brom_sdio_sync_rslt_e;


#define SDIOMB_BOOT_REQ_MAGIC 0x53444254 // "SDBT"
#define SDIOMB_BOOT_ACK_MAGIC 0x53425400 // "SBTx"
#define SDIOMB_DOWNLOAD_REQ_MAGIC 0x5344444C // "SDDL"
#define SDIOMB_DOWNLOAD_ACK_MAGIC 0x53444C00 // "SDLx"
#define SDIOMB_REQ_REFUSE_MAGIC 0x52454655 // "REFU"
#define SDIOMB_ACK_TIMEOUT_MASK 0x000000FF
#define SDIOMB_TIMEOUT_UNIT_MS (10)


#define SDIOMB_GDB_REQ_MAGIC 0x47444200 // "GDBx"
#define SDIOMB_GDB_ACK_MAGIC 0x59474442 // "YGDB"
#define SDIOMB_GDB_CLEAN_MAGIC 0x00000000 

#define BROM_SDIO_D2HMB0_INT               (1 << 16)
#define BROM_SDIO_H2DMB0_INT               (1 << 17)

#define BROM_SDIO_PLL_START               (1 << 22)
#define BROM_SDIO_PLL_END                 (1 << 23)

void brom_sdio_init(void);
void brom_sdio_sync_reset(void);
brom_sdio_sync_rslt_e brom_sdio_sync(void);
void brom_sdio_isr_handle(void);

kal_bool brom_sdio_get_rx_gdb(kal_uint8 *recv_buf, kal_uint32 *p_len);
kal_bool brom_sdio_send_tx_gdb(kal_uint8 *send_buf, kal_uint32 len);

kal_bool brom_sdio_get_rx_xboot(kal_uint8 *recv_buf, kal_uint32 *p_len, kal_uint32 timeout);
kal_bool brom_sdio_send_tx_xboot(kal_uint8 *send_buf, kal_uint32 len, kal_uint32 timeout);

kal_uint32 brom_sdio_get_timeout(void);

kal_bool brom_sdio_xboot_mb_sddl(void);

void brom_sdio_sync_before_PLL_init(void);
void brom_sdio_sync_after_PLL_init(void);

void brom_sdio_write_mb1(kal_uint32 data);

#endif

