#ifndef __UART_GPD_H__
#define __UART_GPD_H__

#define HDMA_MAX_GPD_EXT_LEN		0xFF
#define HDMA_MAX_BD_EXT_LEN		0xFF

typedef enum{
	HDMA_BUF0,
	HDMA_BUF1,
	HDMA_BUF_BOTH,
} hdma_buf_mode_t;

typedef enum{
	HDMA_TST_TX,
	HDMA_TST_RX,
} hdma_tst_mode_t;

typedef struct hdma_tgpd_s {
	kal_uint8 hwo:1;
	kal_uint8 bdp:1;
	kal_uint8 bps:1;
	kal_uint8 resv1:4;
	kal_uint8 ioc:1;
	kal_uint8 cksum;
	kal_uint16 resv2;
	kal_uint32 nextPtr;
	kal_uint32 bufPtr;
	kal_uint16 bufLen;
	kal_uint8 extLen;
	kal_uint8 resv3;
	kal_uint8 extBuf[HDMA_MAX_GPD_EXT_LEN + 1];	// Extension field
} hdma_tgpd_t;

typedef struct hdma_rgpd_s {
	kal_uint8 hwo:1;
	kal_uint8 bdp:1;
	kal_uint8 bps:1;
	kal_uint8 resv1:4;
	kal_uint8 ioc:1;
	kal_uint8 cksum;
	kal_uint16 allowBufLen;
	kal_uint32 nextPtr;
	kal_uint32 bufPtr;
	kal_uint16 bufLen;
	kal_uint16 resv2;
} hdma_rgpd_t;

typedef struct hdma_tbd_s {
	kal_uint8 eol:1;
	kal_uint8 resv1:7;
	kal_uint8 cksum;
	kal_uint16 resv2;
	kal_uint32 nextPtr;
	kal_uint32 bufPtr;
	kal_uint16 bufLen;
	kal_uint8 extLen;
	kal_uint8 resv3;
	kal_uint8 extBuf[HDMA_MAX_BD_EXT_LEN + 1];	// Extension field
} hdma_tbd_t;

typedef struct hdma_rbd_s {
	kal_uint8 eol:1;
	kal_uint8 resv1:7;
	kal_uint8 cksum;
	kal_uint16 allowBufLen;
	kal_uint32 nextPtr;
	kal_uint32 bufPtr;
	kal_uint16 bufLen;
	kal_uint16 resv2;
} hdma_rbd_t;

typedef struct hdma_tx_queue_s {
	hdma_tgpd_t *gpdHeadPtr;
	hdma_tgpd_t *lastLoadedGpdPtr;
	kal_uint32 count;
} hdma_tx_queue_t;

typedef struct hdma_rx_queue_s {
	hdma_rgpd_t *gpdHeadPtr;
	hdma_rgpd_t *lastLoadedGpdPtr;
	kal_uint32 count;
} hdma_rx_queue_t;

typedef struct hdma_tgpd_pool_s{
	kal_uint32 gpdUsed;
	kal_uint32 gpdMax;
	hdma_tgpd_t *gpd;
} hdma_tgpd_pool_t;

typedef struct hdma_rgpd_pool_s{
	kal_uint32 gpdUsed;
	kal_uint32 gpdMax;
	hdma_rgpd_t *gpd;
} hdma_rgpd_pool_t;

typedef struct hdma_tbd_pool_s{
	kal_uint32 bdUsed;
	kal_uint32 bdMax;
	hdma_tbd_t *bd;
} hdma_tbd_pool_t;

typedef struct hdma_rbd_pool_s{
	kal_uint32 bdUsed;
	kal_uint32 bdMax;
	hdma_rbd_t *bd;
} hdma_rbd_pool_t;

typedef struct hdma_gpd_bd_param_s{
	kal_uint32 gpdLenLimit;
	kal_uint32 gpdExtLen;
	kal_uint32 bdLenLimit;
	kal_uint32 bdExtLen;
	kal_uint32 bdNumLimit;
} hdma_gpd_bd_param_t;

typedef struct hdma_gpd_config_s{
	kal_uint8 bps:1;
	kal_uint8 ioc:1;
	kal_uint8 resv:6;
} hdma_gpd_config_t;

#endif
