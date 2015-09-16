
#ifndef __DRV_PFB_H__
#define __DRV_PFB_H__

void drv_pfb_cnt_enable(void);
void drv_pfb_cnt_disable(void);
kal_uint32 drv_pfb_get_cnt(void);

void enablePrefetchBuffer(void);
void disablePrefetchBuffer(void);

#endif /* __DRV_PFB_H__ */
