#ifndef __IMS_SDP_CODEC_DEF_H__
#define __IMS_SDP_CODEC_DEF_H__


typedef enum 
{
    VOIP_CODEC_NONE     = 0,
    VOIP_CODEC_AMR,
    VOIP_CODEC_AMR_WB,
    VOIP_CODEC_H264,
    VOIP_TELEPHONE_EVENT,
    VOIP_CODEC_G729,
    VOIP_CODEC_PCMA,
    VOIP_CODEC_PCMU,
    VOIP_CODEC_G7231,
    VOIP_CODEC_G726_16,
    VOIP_CODEC_G726_24,
    VOIP_CODEC_G726_32,
    VOIP_CODEC_G726_40,
    VOIP_CODEC_CN,
#if 0 // not support iLBC    
/* under construction !*/
#endif // not support iLBC
} voip_codec_enum;



typedef enum e_vcodec_pt_type
{
    PT_CODEC_PCMU = 0,
    PT_CODEC_PCMA = 8,
    PT_CODEC_CN = 13,
    PT_CODEC_G729 = 18,
    PT_CODEC_G7231 = 4,
    PT_TELEPHONE_EVENT = 101,
#if 0 // not support iLBC    
/* under construction !*/
#endif // not support iLBC    
    PT_CODEC_G726_16 = 105, /* R1 definition this is 96*/
    PT_CODEC_G726_24 = 106,
    PT_CODEC_G726_32 = 107,
    PT_CODEC_G726_40 = 108,

} voip_codec_pt_type;


/**
 * @brief Define the type in SC_ACCT_MEDIA_G723_RATE
 */
typedef enum voip_conf_g723_1_rate{
    codec_g723_1_5_3k=0,
    codec_g723_1_6_3k,
}e_voip_conf_g723_1_rate;


/**
 * @brief Define the type in SC_ACCT_MEDIA_ILBC_RATE
 */
typedef enum voip_conf_ilbc_rate{
    codec_ilbc_20ms=0,
    codec_ilbc_30ms,
}e_voip_conf_ilbc_rate;


/**
 * @brief Define the type in SC_ACCT_ADV_DTMF_TYPE
 */
typedef enum voip_conf_dtmf{
    dtmf_rfc2833=0,
    dtmf_inband=1,
}e_voip_conf_dtmf;

                
#endif /* __IMS_SDP_CODEC_DEF_H__ */
