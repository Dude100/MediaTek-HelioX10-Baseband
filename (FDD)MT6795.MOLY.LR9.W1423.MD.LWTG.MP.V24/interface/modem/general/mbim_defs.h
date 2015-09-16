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

/*******************************************************************************
 * Filename:
 * ---------
 *   mbim_defs.h
 *
 * Project:
 * --------
 *   MT6280
 *
 * Description:
 * ------------
 *   This file is intends for MBCI implementation.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/


#ifndef _MBIM_DEFS_H
#define _MBIM_DEFS_H

#define MBIM_MAX_SUPPORT_TRANSACTION    40

#define MBIM_MAX_SESSION    (GPRS_MAX_PDP_SUPPORT >> 1)

#define MBIM_MESSAGE_INDEX_NONE     0

#define MBIM_CONTEXT_ID_APPEND  0xFFFFFFFF

#define MBIM_RSSI_DEFAULT   0

#define MBIM_ERROR_RATE_DEFAULT   0

#define MBIM_SIGNAL_STRENGTH_INTERVAL_DEFAULT 0

#define MBIM_RSSI_DISABLE   0xFFFFFFFF

typedef enum {
    MBIM_UUID_BASIC_CONNECT = 0,
    MBIM_UUID_SMS,
    MBIM_UUID_USSD,
    MBIM_UUID_PHONEBOOK,
    MBIM_UUID_STK,
    MBIM_UUID_AUTH,
    MBIM_UUID_DSS,
    MBIM_UUID_MS_HOSTSHUTDOWN,
    MBIM_UUID_MTK_VENDOR_CMD,
    // Add new UUID in here    
    MBIM_UUID_MAX,
    MBIM_UUID_UNKNOW = 0xFF
} mbim_uuid_enum;

//extern const kal_uint8 *mbim_uuid_tbl[MBIM_UUID_MAX];
extern const kal_uint8 mbim_uuid_tbl[MBIM_UUID_MAX][16];

typedef enum {
    MBIM_CONTEXT_TYPE_NONE = 0,
    MBIM_CONTEXT_TYPE_INTERNET,
    MBIM_CONTEXT_TYPE_VPN,
    MBIM_CONTEXT_TYPE_VOICE,
    MBIM_CONTEXT_TYPE_VIDEO_SHARE,
    MBIM_CONTEXT_TYPE_PURCHASE,
    MBIM_CONTEXT_TYPE_IMS,
    MBIM_CONTEXT_TYPE_MMS,
    MBIM_CONTEXT_TYPE_LOCAL,
    MBIM_CONTEXT_TYPE_MAX,
    MBIM_CONTEXT_TYPE_UNKNOW = 0xFF
} mbim_context_type_enum;

extern const kal_uint8 mbim_context_type_tbl[MBIM_CONTEXT_TYPE_MAX][16];

/*------------------MBIM CID BEGIN--------------------------*/
#define MBIM_CID_RESERVE_0                      0

// BASIC_CONNECT
typedef enum {
    MBIM_CID_DEVICE_CAPS                    = 1,
    MBIM_CID_SUBSCRIBER_READY_STATUS        = 2,
    MBIM_CID_RADIO_STATE                    = 3,
    MBIM_CID_PIN                            = 4,
    MBIM_CID_PIN_LIST                       = 5,
    MBIM_CID_HOME_PROVIDER                  = 6,
    MBIM_CID_PREFERRED_PROVIDER             = 7,
    MBIM_CID_VISIBLE_PROVIDER               = 8,
    MBIM_CID_REGISTER_STATE                 = 9,
    MBIM_CID_PACKET_SERVICE                 = 10,
    MBIM_CID_SIGNAL_STATE                   = 11,
    MBIM_CID_CONNECT                        = 12,
    MBIM_CID_PROVISIONED_CONTEXTS           = 13,
    MBIM_CID_SEVICE_ACTIVATION              = 14,
    MBIM_CID_IP_CONFIGURATION               = 15,
    MBIM_CID_DEVICE_SERVICE                 = 16,
    MBIM_CID_RESERVE_17                     = 17,
    MBIM_CID_RESERVE_18                     = 18,
    MBIM_CID_DEVICE_SERVICE_SUBSCRIBE_LIST  = 19,
    MBIM_CID_PACKET_STATISTIC               = 20,
    MBIM_CID_NETWORK_IDLE_HINT              = 21,
    MBIM_CID_EMERGENCY_MODE                 = 22,
    MBIM_CID_IP_PACKET_FILTERS              = 23,
    MBIM_CID_MULTICARRIER_PROVIDERS         = 24,
    MBIM_CID_BASIC_CONNECT_MAX
} mbim_cid_basic_connect_enum;

// SMS
typedef enum {
    MBIM_CID_SMS_CONFIGURATION          = 1,
    MBIM_CID_SMS_READ                   = 2,
    MBIM_CID_SMS_SEND                   = 3,
    MBIM_CID_SMS_DELETE                 = 4,
    MBIM_CID_SMS_MESSAGE_STORE_STATUS   = 5,
    MBIM_CID_SMS_MAX
} mbim_cid_sms_enum;

// USSD
typedef enum {
    MBIM_CID_USSD   = 1,
    MBIM_CID_USSD_MAX
} mbim_cid_ussd_enum;

// PHONEBOOK
typedef enum {
    MBIM_CID_PHONEBOOK_CONFIGURATION    = 1,
    MBIM_CID_PHONEBOOK_READ             = 2,
    MBIM_CID_PHONEBOOK_DELETE           = 3,
    MBIM_CID_PHONEBOOK_WRITE            = 4,
    MBIM_CID_PHONEBOOK_MAX
} mbim_cid_phonebook_enum;

// STK
typedef enum {
    MBIM_CID_STK_PAC                    = 1,
    MBIM_CID_STK_TERMINAL_RESPONSE      = 2,
    MBIM_CID_STK_ENVELOPE               = 3,
    MBIM_CID_STK_MAX
} mbim_cid_stk_enum;

// AUTH
typedef enum {
    MBIM_CID_AKA_AUTH       = 1,
    MBIM_CID_AKAP_AUTH      = 2,
    MBIM_CID_SIM_AUTH       = 3,
    MBIM_CID_AUTH_MAX
} mbim_cid_auth_enum;

// DSS
typedef enum {
    MBIM_CID_DSS_CONNECT    = 1,
    MBIM_CID_DSS_MAX
} mbim_cid_dss_enum;

// MS_HOSTSHUTDOWN
typedef enum {
    MBIM_CID_MS_HOSTSHUTDOWN   = 1,
    MBIM_CID_MS_HOSTSHUTDOWN_MAX
} mbim_cid_ms_hostshutdown_enum;

// MTK_VENDOR_CMD
typedef enum {
    MBIM_CID_MTK_VENDOR_CMD   = 1,
    MBIM_CID_MTK_VENDOR_CMD_MAX
} mbim_cid_mtk_vendor_cmd_enum;

/*------------------MBIM CID END--------------------------*/

/*------------------MBIM CID STRUCT ENUM BEGIN------------------------*/
typedef enum {
    MBIMCellularClassGsm = 1,
    MBIMCellularClassCdma = 2    
} mbim_cellular_class_enum;

typedef enum {
    MBIMSubscriberReadyStateNotInitialized,
    MBIMSubscriberReadyStateInitialized,
    MBIMSubscriberReadyStateSimNotInserted,
    MBIMSubscriberReadyStateBadSim,
    MBIMSubscriberReadyStateFailure,
    MBIMSubscriberReadyStateNotActivated,
    MBIMSubscriberReadyStateDeviceLocked
} mbim_subscriber_ready_state_enum;

typedef enum {
    MBIMRadioOff,
    MBIMRadioOn
} mbim_radio_switch_state_enum;

typedef enum {
    MBIMPinTypeNone,
    MBIMPinTypeCustom,
    MBIMPinTypePin1,
    MBIMPinTypePin2,
    MBIMPinTypeDeviceSimPin,
    MBIMPinTypeDeviceFirstSimPin,
    MBIMPinTypeNetworkPin,
    MBIMPinTypeNetworkSubsetPin,
    MBIMPinTypeServiceProviderPin,
    MBIMPinTypeCorporatePin,
    MBIMPinTypeSubsidyLock,
    MBIMPinTypePuk1,
    MBIMPinTypePuk2,
    MBIMPinTypeDeviceFirstSimPuk,
    MBIMPinTypeNetworkPuk,
    MBIMPinTypeNetworkSubsetPuk,
    MBIMPinTypeServiceProviderPuk,
    MBIMPinTypeCorporatePuk
} mbim_pin_type_enum;

typedef enum {
    MBIMPinOperationEnter,
    MBIMPinOperationEnable,
    MBIMPinOperationDisable,
    MBIMPinOperationChange
} mbim_pin_operation_enum;

typedef enum {
    MBIMPinModeNotSupported,
    MBIMPinModeEnable,
    MBIMPinModeDisable
} mbim_pin_mode_enum;

typedef enum {
    MBIMPinFormatUnknown,
    MBIMPinFormatNumeric,
    MBIMPinFormatAlphaNumeric
} mbim_pin_format_enum;

typedef enum {
    MBIM_PROVIDER_STATE_UNKNOWN = 0x00,
    MBIM_PROVIDER_STATE_HOME = 0x01, 
    MBIM_PROVIDER_STATE_FORBIDDEN = 0x02,
    MBIM_PROVIDER_STATE_PREFERRED = 0x04,
    MBIM_PROVIDER_STATE_VISIBLE = 0x08,
    MBIM_PROVIDER_STATE_REGISTERED = 0x10,
    MBIM_PROVIDER_STATE_PREFERRED_MULTICARRIER = 0x20
} mbim_provider_state_enum;

typedef enum {
    MBIMRegisterStateUnknown,
    MBIMRegisterStateDeregistered,
    MBIMRegisterStateSearching,
    MBIMRegisterStateHome,
    MBIMRegisterStateRoaming,
    MBIMRegisterStatePartner,
    MBIMRegisterStateDenied
} mbim_register_state_enum;

typedef enum {
    MBIMPacketServiceStateUnknown,
    MBIMPacketServiceStateAttaching,
    MBIMPacketServiceStateAttached,
    MBIMPacketServiceStateDetaching,
    MBIMPacketServiceStateDetached
} mbim_packet_service_state_enum;

typedef enum {
    MBIMPacketServiceActionAttach,
    MBIMPacketServiceActionDetach
} mbim_packet_service_action_enum;

typedef enum {
    MBIMRegisterActionAutomatic,
    MBIMRegisterActionManual
} mbim_register_action_enum;

typedef enum {
    MBIMRegisterModeUnknown,
    MBIMRegisterModeAutomatic,
    MBIMRegisterModeManual
} mbim_register_mode_enum;

typedef enum {
    MBIM_REGISTRATION_NONE = 0x00,
    MBIM_REGISTRATION_MANUAL_SELECTION_NOT_AVALIABLE = 0x01,
    MBIM_REGISTRATION_PACKET_SERVICE_AUTOMATIC_ATTACH = 0x02,
} mbim_registration_flags_enum;

typedef enum {
    MBIMDataClassNone = 0x00,
    MBIMDataClassGPRS = 0x01,
    MBIMDataClassEDGE = 0x02,
    MBIMDataClassUMTS = 0x04,
    MBIMDataClassHSDPA = 0x08,
    MBIMDataClassHSUPA = 0x10,
    MBIMDataClassLTE = 0x20
//    MBIMDataClassCustom = 0x80000000
} mbim_data_class_enum;

typedef enum {
    MBIMActivationCommandDeactivate,
    MBIMActivationCommandActivate
} mbim_activation_command_enum;

typedef enum {
    MBIMCompressionNone,
    MBIMCompressionEnable
} mbim_compression_enum;

typedef enum {
    MBIMAuthProtocolNone,
    MBIMAuthProtocolPap,
    MBIMAuthProtocolChap,
    MBIMAuthProtocolMsChapV2
} mbim_auth_protocol_type_enum;

typedef enum {
    MBIMContextIPTypeDefault,
    MBIMContextIPTypeIPv4,
    MBIMContextIPTypeIPv6,
    MBIMContextIPTypeIPv4v6,
    MBIMContextIPTypeIPIPv4AndIPv6
} mbim_context_ip_type_enum;

typedef enum {
    MBIMActivationStateUnknown,
    MBIMActivationStateActivated,
    MBIMActivationStateActivating,
    MBIMActivationStateDeactivated,
    MBIMActivationStateDeactivating
} mbim_activation_state_enum;

typedef enum {
    MBIMVoiceCallStateNone,
    MBIMVoiceCallStateInProgress,
    MBIMVoiceCallStateHangup
} mbim_voice_call_state_enum;

typedef enum {
    MBIMNetworkIdleHintDisabled,
    MBIMNetworkIdleHintEnable
} mbim_network_idle_hint_states_enum;

typedef enum {
    MBIMEmergencyModeOff,
    MBIMEmergencyModeOn
} mbim_mergency_mode_state_enum;

typedef enum {
    MBIMSmsStorageNotInitialized,
    MBIMSmsStorageInitialized
} mbim_sms_storage_state_enum;

typedef enum {
    MBIMSmsFormatPdu,
    MBIMSmsFormatCdma
} mbim_sms_format_enum;

typedef enum {
    MBIMSmsFlagAll,
    MBIMSmsFlagIndex,
    MBIMSmsFlagNew,
    MBIMSmsFlagOld,
    MBIMSmsFlagSent,
    MBIMSmsFlagDraft
} mbim_sms_flag_enum;

typedef enum {
    MBIMSmsStatusNew,
    MBIMSmsStatusOld,
    MBIMSmsStatusDraft,
    MBIMSmsStatusSent
} mbim_sms_message_status_enum;

typedef enum {
    MBIM_SMS_FLAG_NONE,
    MBIM_SMS_FLAG_MESSAGE_STORE_FULL,
    MBIM_SMS_FLAG_NEW_MESSAGE
} mbim_sms_status_flags_enum;

typedef enum {
    MBIMUSSDInitiate,
    MBIMUSSDContinue,
    MBIMUSSDCancel
} mbim_ussd_action_enum;

typedef enum {
    MBIMUSSDNoActionRequired,
    MBIMUSSDActionRequired,
    MBIMUSSDTerminatedByNW,
    MBIMUSSDOtherLocalClient,
    MBIMUSSDOperationNotSupported,
    MBIMUSSDNetworkTimeOut
} mbim_ussd_response_enum;

typedef enum {
    MBIMUSSDNewSession,
    MBIMUSSDExistingSession
} mbim_ussd_session_state_enum;

typedef enum {
    MBIM_MTK_VENDOR_CMD_TYPE_NONE   // add cmd type by Vendor
} mbim_mtk_vendor_cmd_type_enum;

/*------------------MBIM CID STRUCT ENUM END------------------------*/

/*------------------MBIM CID STRUCT BEGIN------------------------*/
typedef struct {
    kal_uint32  offset;
    kal_uint32  size;
} MBIM_OL_PAIR_LIST;

typedef struct {
    kal_uint32  DeviceType;
    kal_uint32  CellularClass;
    kal_uint32  VoiceClass;
    kal_uint32  SimClass;
    kal_uint32  DataClass;
    kal_uint32  SmsCaps;
    kal_uint32  ControlCaps;
    kal_uint32  MaxSessions;
    kal_uint32  CustomDataClassOffset;
    kal_uint32  CustomDataClassSize;
    kal_uint32  DeviceIdOffset;
    kal_uint32  DeviceIdSize;
    kal_uint32  FirmwareInfoOffset;
    kal_uint32  FirmwareInfoSize;
    kal_uint32  HardwareInfoOffset;
    kal_uint32  HardwareInfoSize;
} mbim_device_caps_info_struct;

typedef struct {
    kal_uint32  ReadyState;
    kal_uint32  SubscriberIdOffset;
    kal_uint32  SubscriberIdSize;
    kal_uint32  SimIccIdOffset;
    kal_uint32  SimIccIdSize;
    kal_uint32  ReadyInfo;
    kal_uint32  ElementCount;
    MBIM_OL_PAIR_LIST   TelephoneNumbersRefList[2];
} mbim_subscriber_ready_info_struct;

typedef struct {
    kal_uint8   DataBuffer[32+40+64];   // SubscriberId, SimIccid, TelephoneNumber
} mbim_subscriber_ready_info_databuffer_struct;


typedef struct {
    kal_uint32  RadioState;
} mbim_set_radio_state_struct;

typedef struct {
    kal_uint32  HwRadioState;
    kal_uint32  SwRadioState;
} mbim_radio_state_info_struct;

typedef struct {
    kal_uint32  PinType;
    kal_uint32  PinOperation;
    kal_uint32  PinOffset;
    kal_uint32  PinSize;
    kal_uint32  NewPinOffset;
    kal_uint32  NewPinSize;
} mbim_set_pin_struct;

typedef struct {
    kal_uint32 PinType;
    kal_uint32  PinState;
    kal_uint32  RemainAttempts;
} mbim_pin_info_struct;

typedef struct {
    kal_uint32 PinMode;
    kal_uint32  PinFormat;
    kal_uint32  PinLengthMin;
    kal_uint32  PinLengthMax;
} mbim_pin_desc_struct;

typedef struct {
    mbim_pin_desc_struct  PinDescPin1;
    mbim_pin_desc_struct  PinDescPin2;
    mbim_pin_desc_struct  PinDescDeviceSimPin;
    mbim_pin_desc_struct  PinDescDeviceFirstSimPin;
    mbim_pin_desc_struct  PinDescNetworkPin;
    mbim_pin_desc_struct  PinDescNetworkSubsetPin;
    mbim_pin_desc_struct  PinDescServiceProviderPin;
    mbim_pin_desc_struct  PinDescCorporatePin;
    mbim_pin_desc_struct  PinDescSubsidyLock;
    mbim_pin_desc_struct  PinDescCustom;
} mbim_pin_list_info_struct;

typedef struct {
    kal_uint32  ProviderIdOffset;
    kal_uint32  ProviderIdSize;
    kal_uint32  ProviderState;
    kal_uint32  ProviderNameOffset;
    kal_uint32  ProviderNameSize;
    kal_uint32  CellularClass;
    kal_uint32  Rssi;
    kal_uint32  ErrorRate;
} mbim_provider_struct;

typedef struct {
    kal_uint32  Action;
} mbim_visible_providers_req_struct;

typedef struct {
    kal_uint32  ProviderIdOffset;
    kal_uint32  ProviderIdSize;
    kal_uint32  RegisterAction;
    kal_uint32  DataClass;
} mbim_set_registration_state_struct;

typedef struct {
    kal_uint32  NwError;
    kal_uint32  RegisterState;
    kal_uint32  RegisterMode;
    kal_uint32  AvaliableDataClasses;
    kal_uint32  CurrentCellulrClass;      
    kal_uint32  ProviderIdOffset;
    kal_uint32  ProviderIdSize;
    kal_uint32  ProviderNameOffset;
    kal_uint32  ProviderNameSize;
    kal_uint32  RoamingTextOffset;
    kal_uint32  RoamingTextSize;
    kal_uint32  RegistrationFlag;
} mbim_registration_state_info_struct;

typedef struct {
    kal_uint32  PacketServiceAction;
} mbim_set_packet_service_struct;

typedef struct {
    kal_uint32  NwError;
    kal_uint32  PacketServiceState;
    kal_uint32  HighestAvaliableDataClasses;
    kal_uint64  UplinkSpeed;
    kal_uint64  DownlinkSpeed;
} mbim_packet_service_info_struct;

typedef struct {
    kal_uint32  SignalStrengthInterval;
    kal_uint32  RssiThreshold;
    kal_uint32  ErrorRateThreshold;
} mbim_set_signal_state_struct;

typedef struct {
    kal_uint32  Rssi;
    kal_uint32  ErrorRate;
    kal_uint32  SignalStrengthInterval;
    kal_uint32  RssiThreshold;
    kal_uint32  ErrorRateThreshold;
} mbim_signal_state_info_struct;

typedef struct {
    kal_uint32  SessionId;
    kal_uint32  ActivationCommand;
    kal_uint32  AccessStringOffset;
    kal_uint32  AccessStringSize;
    kal_uint32  UserNameOffset;
    kal_uint32  UserNameSize;
    kal_uint32  PasswordOffset;
    kal_uint32  PasswordSize;
    kal_uint32  Compression;
    kal_uint32  AuthProtocol;
    kal_uint32  IPType;
    kal_uint8  ContextType[16];
} mbim_set_connect_struct;

typedef struct {
    kal_uint32  SessionId;
    kal_uint32  ActivationState;
    kal_uint32  VoiceCallState;
    kal_uint32  IPType;
    kal_uint8  ContextType[16];
    kal_uint32  NwError;
} mbim_connect_info_struct;

typedef struct {
    kal_uint32  ContextId;
    kal_uint8  ContextType[16];
    kal_uint32  AccssStringOffset;
    kal_uint32  AccssStringSize;
    kal_uint32  UserNmeOffset;
    kal_uint32  UserNameSize;
    kal_uint32  PasswordOffset;
    kal_uint32  PasswordSize;
    kal_uint32  Compression;
    kal_uint32  AuthProtocol;
    kal_uint8   DataBuffer[200+64+64];  // APN + Username + Password
} mbim_context_struct;

typedef struct {
    kal_uint32  ElementCount;
    MBIM_OL_PAIR_LIST   ProvisionedContextRefList[10];
} mbim_provisioned_contexts_info_struct;

typedef struct {
    kal_uint32  ContextId;
    kal_uint8  ContextType[16];
    kal_uint32  AccssStringOffset;
    kal_uint32  AccssStringSize;
    kal_uint32  UserNmeOffset;
    kal_uint32  UserNameSize;
    kal_uint32  PasswordOffset;
    kal_uint32  PasswordSize;
    kal_uint32  Compression;
    kal_uint32  AuthProtocol;
    kal_uint32  ProviderIdOffset;
    kal_uint32  ProviderIdSize;
} mbim_set_provisioned_context_struct;

typedef struct {
    kal_uint8   IPv4Address[4];
} mbim_ipv4_address_struct;

typedef struct {
    kal_uint32  OnLinkPrefixLength;
    mbim_ipv4_address_struct    IPv4Address;
} mbim_ipv4_element_struct;

typedef struct {
    kal_uint8   IPv6Address[16];
} mbim_ipv6_address_struct;

typedef struct {
    kal_uint32  OnLinkPrefixLength;
    mbim_ipv6_address_struct    IPv6Address;
} mbim_ipv6_element_struct;

typedef struct {
    kal_uint32  SessionId;
    kal_uint32  IPv4ConfigurationAvaliable;
    kal_uint32  IPv6ConfigurationAvaliable;
    kal_uint32  IPv4AddressCount;
    kal_uint32  IPv4AddressOffset;
    kal_uint32  IPv6AddressCount;
    kal_uint32  IPv6AddressOffset;
    kal_uint32  IPv4GatewayOffset;
    kal_uint32  IPv6GatewayOffset;
    kal_uint32  IPv4DnsServerCount;
    kal_uint32  IPv4DnsServerOffset;
    kal_uint32  IPv6DnsServerCount;
    kal_uint32  IPv6DnsServerOffset;        
    kal_uint32  IPv4Mtu;
    kal_uint32  IPv6Mtu;
    kal_uint8   DataBuffer[88];
} mbim_ip_configuration_struct;

typedef struct {
    kal_uint8   DeviceServiceId[16];
    kal_uint32  DssPayload;
    kal_uint32  MaxDssInstances;
    kal_uint32  CidCount;
    kal_uint32  Cid[MBIM_CID_BASIC_CONNECT_MAX];  // IMPORTTANT: Assume basic connect always has the most CIDs
} mbim_device_service_element_struct;

typedef struct {
    kal_uint32  DeviceServiceCount;
    kal_uint32  MaxDssSessions;
    MBIM_OL_PAIR_LIST   DeviceServiceRefList[MBIM_UUID_MAX];
//    MBIM_OL_PAIR_LIST   DeviceServiceRefList[2];
    mbim_device_service_element_struct DeviceService[MBIM_UUID_MAX];
//    mbim_device_service_element_struct DeviceService[2];
} mbim_device_service_info_struct;

typedef struct {
    kal_uint32  NetworkIdleHintState;
} mbim_network_idle_hint_struct;

typedef struct {
    kal_uint32  EmergencyMode;
} mbim_emergency_mode_info_struct;

typedef struct {
    kal_uint32  ElementCount;
} mbim_device_service_subscribe_list_struct;

typedef struct {
    kal_uint8  DeviceServiceId[16];
    kal_uint32 CidCount;
} mbim_event_entry_struct;

typedef struct {
    kal_uint32  Format;
    kal_uint32  ScAddressOffset;
    kal_uint32  ScAddressSize;
} mbim_set_sms_configuration_struct;

typedef struct {
    kal_uint32  SmsStorageState;
    kal_uint32  Format;
    kal_uint32  MaxMessages;
    kal_uint32  CdmaShortMessageSize;
    kal_uint32  ScAddressOffset;
    kal_uint32  ScAddressSize;
    kal_uint8   DataBuffer[40];
} mbim_sms_configuration_info_struct;

typedef struct {
    kal_uint32  SmsFormat;
    kal_uint32  Flag;
    kal_uint32  MessageIndex;
} mbim_sms_read_req_struct;

typedef struct {
    kal_uint32  Format;
    kal_uint32  ElementCount;
} mbim_sms_read_info_struct;

typedef struct {
    kal_uint32  MessageIndex;    
    kal_uint32  MessageStatus;
    kal_uint32  PduDataOffset;
    kal_uint32  PduDataSize;
    kal_uint8   DataBuffer[184]; // Spec: 183, align to 184
} mbim_sms_pdu_record_struct;

typedef struct {
    kal_uint32  PduDataOffset;
    kal_uint32  PduDataSize;
} mbim_sms_send_pdu_struct;

typedef struct {
    kal_uint32  SmsFormat;
} mbim_sms_send_struct;

typedef struct {
    kal_uint32  MessageReference;
} mbim_sms_send_info_struct;

typedef struct {
    kal_uint32  Flag;
    kal_uint32  MessageIndex;
} mbim_set_sms_delete_struct;

typedef struct {
    kal_uint32  Flag;
    kal_uint32  MessageIndex;
} mbim_sms_status_info_struct;

typedef struct {
    kal_uint32  USSDAction;
    kal_uint32  USSDDataCodingScheme;
    kal_uint32  USSDPayloadOffset;
    kal_uint32  USSDPayloadLength;
} mbim_set_ussd_struct;

typedef struct {
    kal_uint32  USSDResponse;
    kal_uint32  USSDSessionState;
    kal_uint32  USSDDataCodingScheme;
    kal_uint32  USSDPayloadOffset;
    kal_uint32  USSDPayloadLength;
    kal_uint8   DataBuffer[160];
} mbim_ussd_info_struct;

typedef struct {
    kal_uint32  VendorCmdType;  // mbim_mtk_vendor_cmd_type_enum
    kal_uint32  VendorCmdOffset;
    kal_uint32  VendorCmdSize;
} mbim_mtk_vendor_cmd_info_struct;

/*------------------MBIM CID STRUCT END--------------------------*/

typedef enum {
    MBIM_STATUS_SUCCESS = 0,
    MBIM_STATUS_BUSY = 1,
    MBIM_STATUS_FAILURE = 2,
    MBIM_STATUS_SIM_NOT_INSERTED = 3,
    MBIM_STATUS_BAD_SIM = 4,
    MBIM_STATUS_PIN_REQUIRED = 5, 
    MBIM_STATUS_PIN_DISABLED = 6,
    MBIM_STATUS_NOT_REGISTERED = 7,
    MBIM_STATUS_PROVIDERS_NOT_FOUND = 8,
    MBIM_STATUS_NO_DEVICE_SUPPORT = 9,
    MBIM_STATUS_PROVIDER_NOT_VISIBLE = 10,
    MBIM_STATUS_DATA_CLASS_NOT_AVAILABLE = 11,
    MBIM_STATUS_PACKET_SERVICE_DETACHED = 12,
    MBIM_STATUS_MAX_ACTIVATED_CONTEXTS = 13,
    MBIM_STATUS_NOT_INITIALIZED = 14,
    MBIM_STATUS_VOICE_CALL_IN_PROGRESS = 15,
    MBIM_STATUS_CONTEXT_NOT_ACTIVATED = 16,
    MBIM_STATUS_SERVICE_NOT_ACTIVATED = 17,
    MBIM_STATUS_INVALID_ACCESS_STRING = 18,
    MBIM_STATUS_INVALID_USER_NAME_PWD = 19,
    MBIM_STATUS_RADIO_POWER_OFF = 20,
    MBIM_STATUS_INVALID_PARAMETERS = 21,
    MBIM_STATUS_READ_FAILURE = 22,
    MBIM_STATUS_WRITE_FAILURE = 23,
//    MBIM_STATUS_ Reserved = 24,
    MBIM_STATUS_NO_PHONEBOOK = 25,
    MBIM_STATUS_PARAMETER_TOO_LONG = 26,
    MBIM_STATUS_STK_BUSY = 27,
    MBIM_STATUS_OPERATION_NOT_ALLOWED = 28,
    MBIM_STATUS_MEMORY_FAILURE = 29,
    MBIM_STATUS_INVALID_MEMORY_INDEX = 30,
    MBIM_STATUS_MEMORY_FULL = 31,
    MBIM_STATUS_FILTER_NOT_SUPPORTED = 32,
    MBIM_STATUS_DSS_INSTANCE_LIMIT = 33,
    MBIM_STATUS_INVALID_DEVICE_SERVICE_OPERATION = 34,
    MBIM_STATUS_AUTH_INCORRECT_AUTN = 35,
    MBIM_STATUS_AUTH_SYNC_FAILURE = 36,
    MBIM_STATUS_AUTH_AMF_NOT_SET = 37,

    MBIM_STATUS_SMS_UNKNOWN_SMSC_ADDRESS = 100,
    MBIM_STATUS_SMS_NETWORK_TIMEOUT = 101,
    MBIM_STATUS_SMS_LANG_NOT_SUPPORTED = 102,
    MBIM_STATUS_SMS_ENCODING_NOT_SUPPORTED = 103,
    MBIM_STATUS_SMS_FORMAT_NOT_SUPPORTED = 104,

    MBIM_STATUS_END = 0xFF
} mbim_status_code_enum;

typedef enum {
    MBIM_OP_CLOSE = 0,
    MBIM_OP_OPEN = 1,
    MBIM_OP_COMMAND = 2,
    MBIM_OP_ERROR_CANCEL = 3,
    MBIM_OP_REOPEN = 4,
} mbim_op_enum;

typedef enum {
    MBIM_COMMAND_QUERY,
    MBIM_COMMAND_SET
} mbim_command_type_enum;

#endif /* _MBIM_DEFS_H */

