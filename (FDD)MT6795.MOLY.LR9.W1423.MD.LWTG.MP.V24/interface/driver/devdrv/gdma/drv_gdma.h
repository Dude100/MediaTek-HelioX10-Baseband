#ifndef __DRV_GDMA_H__
#define __DRV_GDMA_H__


typedef enum {
	GDMA_CH_LOGGING,	          /**<  */
	GDMA_CH_INTRAT,           /**<  */	
	GDMA_CH_RESERVED1,
	GDMA_CH_RESERVED2,
	GDMA_CH_MAX,
} gdma_channel_type_e;


typedef struct gdma_gpd_addr_s {
	kal_uint32 gdma_src_Gpd;				/***/
	kal_uint32 gdma_dst_Gpd;				/***/
} gdma_gpd_addr_t;

typedef enum {
	GDMA_MOD_LINKLIST,				/***/
	GDMA_MOD_BASIC,				/***/
	GDMA_MOD_DESCRPT,				/***/	
} gdma_mod_e;


typedef struct gdma_cfg_s {
	gdma_channel_type_e gdma_sel_channel;		/***/
	gdma_mod_e gdma_mod;
	gdma_gpd_addr_t	gdma_gpd_addr;
	kal_uint16 gdma_mod_basic_tx_size;
	kal_uint16 gdma_other_para;
} gdma_cfg_t;


typedef enum {
	GDMA_START,	          /**<  */
	GDMA_RESUME,           /**<  */	
} gdma_start_cmd_type_e;

typedef enum {
	GDMA_STARTED,	          /**<  */
	GDMA_STOP,           /**<  */	
} gdma_status_type_e;

typedef enum {
	GDMA_SRC_DONE=0,
	GDMA_DST_DONE=4,
	GDMA_SRC_QUE_EMPTY=8,	          
	GDMA_DST_QUE_EMPTY=12,           
	GDMA_LEN_ERR=16,
	GDMA_ALO_LEN_ERR=20,
	GDMA_BD_CS_ERR=24,
	GDMA_GPD_CS_ERR=28,	
} gdma_int_type_e;

typedef struct gdma_cbType_s {
	gdma_channel_type_e 	gdma_channel;
	gdma_int_type_e 		gdma_int_type;
} gdma_cbType_t;

typedef struct gdma_cbParameter_s {
	gdma_int_type_e 	gdma_int_type;
	gdma_gpd_addr_t 	gpd_info;
} gdma_cbParameter_t;


typedef void (*gdma_pcb_f)(gdma_cbParameter_t *gpd_info);

typedef enum {
	GDMA_CB_SRC_GPD_DONE,
	GDMA_CB_DST_GPD_DONE,
	GDMA_CB_SRC_QUE_EMPTY,
	GDMA_CB_DST_QUE_EMPTY,
	GDMA_CB_ERROR,	
} gdma_cbType_e;


/*****************************************************************************
 *						 function declaration                                *
 *****************************************************************************/
kal_bool drv_gdma_set_config(gdma_cfg_t *gdmaCfg_p);
kal_uint8 drv_gdma_start_cmd(gdma_channel_type_e chId, gdma_start_cmd_type_e cmd);
void drv_gdma_stop_cmd(gdma_channel_type_e chId);
void drv_gdma_get_curGPD(gdma_channel_type_e chId, gdma_gpd_addr_t *cur_gpd_addr);
gdma_status_type_e drv_gdma_get_status(gdma_channel_type_e chId);
kal_uint8 drv_gdma_register_callback(gdma_cbType_t *cbType, gdma_pcb_f callback);
void HDMA_PDN_SET(kal_uint32 channel);
void HDMA_PDN_CLR(kal_uint32 channel);
kal_uint32 HDMA_PDN_STS(kal_uint32 channel);
void FDMA_PDN_SET(kal_uint32 channel);
void FDMA_PDN_CLR(kal_uint32 channel);
kal_uint32 FDMA_PDN_STS(kal_uint32 channel);

#endif /* end of __DRV_GPT_H__ */
