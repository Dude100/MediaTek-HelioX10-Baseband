
#ifndef __AGPS_MD_INTERFACE_H__
#define __AGPS_MD_INTERFACE_H__

#include "nbr_public_struct.h"

//version history
// 6  add PositionTect bitmap parameter in MOLR_BEGIN_REQ, add session_id in MTLR_BEGIN_IND and MTLR_BEGIN_RSP
// 7  change version's type from short to int to avoid unaligned access
// 8  add 4 Session IND messages
// 9  extend requestor_id and client_name from 128 bytes to 160 bytes
// 10 define LPP UP SWIP <-> LPP CP message ID (no struct definition, uses raw data)
// 11 add AGPS_MD_TYPE_MTLR_BEGIN_2_IND and agps_md_mtlr_begin_2_ind struct
// 12 add supporting eutran band list in sim_info_rsp
// 13 add session_id in agps_md_auto_mtlr_response_ind struct
// 13.2 add AGPS_MD_TYPE_SIM_INFO_IND for MD to report SIM_INFO when it is boot up complete, AP CCCI driver should keep the data sent from MD when AP/AGPS does not open CCCI yet
// 13.3 add AGPS_MD_TYPE_LPP_PEER_OTDOA_RESET_UE_STORED_POS_REQ for SUPL LPP session to delete OTDOA data in MD side when A-GPS session is finished

#define AGPS_MD_INTERFACE_VERSION 13
#define MAX_AGPS_MD_BUFFER_SIZE 4096

typedef int agps_md_reset_data;
#define AGPS_MD_RESET_EPHEMERIS        0x0001
#define AGPS_MD_RESET_ALMANAC          0x0002
#define AGPS_MD_RESET_POSITION         0x0004
#define AGPS_MD_RESET_TIME             0x0008
#define AGPS_MD_RESET_IONO             0x0010
#define AGPS_MD_RESET_UTC              0x0020
#define AGPS_MD_RESET_HEALTH           0x0040
#define AGPS_MD_RESET_SVDIR            0x0080
#define AGPS_MD_RESET_SVSTEER          0x0100
#define AGPS_MD_RESET_SADATA           0x0200
#define AGPS_MD_RESET_RTI              0x0400
#define AGPS_MD_RESET_CELLDB_INFO      0x8000
#define AGPS_MD_RESET_ALL              0xFFFF

typedef struct {
    double          latitude;           //Represents latitude in degrees
    double          longitude;          //Represents longitude in degrees
    char            altitude_used;      //0=disabled 1=enabled
    double          altitude;           //Represents altitude in meters above the WGS 84 reference
    char            speed_used;         //0=disabled 1=enabled
    float           speed;              //Represents speed in meters per second
    char            bearing_used;       //0=disabled 1=enabled
    float           bearing;            //Represents heading in degrees
    char            accuracy_used;      //0=disabled 1=enabled
    float           accuracy;           //Represents expected accuracy in meters
    char            timestamp_used;     //0=disabled 1=enabled
    long long       timestamp;          //Milliseconds since January 1, 1970
} agps_md_gps_location;

typedef enum {
    //PMTK
    AGPS_MD_TYPE_PMTK = 0,
    //GPS control
    AGPS_MD_TYPE_GPS_RESET_IND  = 100,
    AGPS_MD_TYPE_GPS_RESET_RSP,
    AGPS_MD_TYPE_GPS_OPEN_IND,
    AGPS_MD_TYPE_GPS_OPEN_RSP,
    AGPS_MD_TYPE_GPS_CLOSE_IND,
    AGPS_MD_TYPE_GPS_CLOSE_RSP,
    AGPS_MD_TYPE_SESSION_ABORT_REQ,
    AGPS_MD_TYPE_SESSION_ABORT_RSP,
    //MOLR
    AGPS_MD_TYPE_MOLR_BEGIN_REQ = 200,
    AGPS_MD_TYPE_MOLR_BEGIN_RSP,
    //MTLR
    AGPS_MD_TYPE_MTLR_BEGIN_IND = 300,
    AGPS_MD_TYPE_MTLR_BEGIN_RSP,
    AGPS_MD_TYPE_MTLR_BEGIN_2_IND,
    //NBR
    AGPS_MD_TYPE_NBR_CELL_INFO_REG_REQ  = 400,
    AGPS_MD_TYPE_NBR_CELL_INFO_REG_CNF,
    AGPS_MD_TYPE_NBR_CELL_INFO_DEREG_REQ,
    AGPS_MD_TYPE_NBR_CELL_INFO_DEREG_CNF,
    AGPS_MD_TYPE_NBR_CELL_INFO_IND,
    //Automation
    AGPS_MD_TYPE_AUTO_TEST_IND  = 500,
    AGPS_MD_TYPE_AUTO_CP_UP_STATUS_IND,
    AGPS_MD_TYPE_AUTO_MOLR_START_IND,
    AGPS_MD_TYPE_AUTO_MOLR_STOP_IND,
    AGPS_MD_TYPE_AUTO_MTLR_RESPONSE_IND,    //not support by MTK AOSP AGPS
    //SIM info query
    AGPS_MD_TYPE_EMERGENCY_CALL_IND = 600,
    AGPS_MD_TYPE_SIM_INFO_REQ,
    AGPS_MD_TYPE_SIM_INFO_RSP,
    AGPS_MD_TYPE_SERVICE_STATE_REQ,
    AGPS_MD_TYPE_SERVICE_STATE_RSP,
    AGPS_MD_TYPE_ROAMING_STATE_REQ,
    AGPS_MD_TYPE_ROAMING_STATE_RSP,
    AGPS_MD_TYPE_DATA_CONNECTION_STATE_REQ,
    AGPS_MD_TYPE_DATA_CONNECTION_STATE_RSP,
    AGPS_MD_TYPE_SIM_INFO_IND,
    //Session IND
    AGPS_MD_TYPE_SESSION_START_IND = 700,
    AGPS_MD_TYPE_SESSION_END_IND,
    AGPS_MD_TYPE_LTE_OTDOA_IND,
    AGPS_MD_TYPE_LTE_ECID_IND,
    //LPP UP SWIP to LPP CP (raw data)
    AGPS_MD_TYPE_LPP_PEER_OTDOA_MEAS_REQ = 800,
    AGPS_MD_TYPE_LPP_PEER_OTDOA_ASSIST_DATA_REQ,
    AGPS_MD_TYPE_LPP_PEER_OTDOA_MEAS_ABORT_REQ,
    AGPS_MD_TYPE_LPP_PEER_ECID_MEAS_REQ,
    AGPS_MD_TYPE_LPP_PEER_ECID_MEAS_ABORT_REQ,
    AGPS_MD_TYPE_LPP_PEER_EUTRAN_BAND_UPDATE_REQ,
    AGPS_MD_TYPE_LPP_PEER_OTDOA_RESET_UE_STORED_POS_REQ,
    //LPP CP to LPP UP SWIP (raw data)
    AGPS_MD_TYPE_LPP_PEER_OTDOA_MEAS_CNF = 900,
    AGPS_MD_TYPE_LPP_PEER_OTDOA_ASSIST_DATA_CNF,
    AGPS_MD_TYPE_LPP_PEER_OTDOA_ADDITIONAL_ASSIST_DATA_REQ,
    AGPS_MD_TYPE_LPP_PEER_ECID_MEAS_CNF,
    AGPS_MD_TYPE_LPP_PEER_EUTRAN_BAND_UPDATE_CNF
} agps_md_type;

typedef struct {
    int  version; //use AGPS_MD_INTERFACE_VERSION
    short  type;    //refer to agps_md_type
    short  len;     //data length, not include header's size
} agps_md_header;

typedef struct {
    char  pmtk[256];
} agps_md_pmtk;

typedef struct {
    agps_md_reset_data  flags;  //just hardcode 0x3f
} agps_md_gps_reset_ind;
/*
typedef struct {
    //nothing
} agps_md_gps_reset_rsp;
*/
typedef struct {
    #define AGPS_MD_GPS_OPEN_IND_TYPE_NILR 0
    #define AGPS_MD_GPS_OPEN_IND_TYPE_MTLR 1
    #define AGPS_MD_GPS_OPEN_IND_TYPE_MOLR 2
    char  type;   //refer to AGPS_MD_GPS_OPEN_IND_TYPE_
} agps_md_gps_open_ind;

typedef struct {
    #define AGPS_MD_GPS_OPEN_RSP_RESULT_DENY 0
    #define AGPS_MD_GPS_OPEN_RSP_RESULT_ACCEPT 1
    char  result;        //refer to AGPS_MD_GPS_OPEN_RSP_RESULT_

    #define AGPS_MD_GPS_OPEN_RSP_RESULT_CP_AUTO_RESET_DISABLED 0
    #define AGPS_MD_GPS_OPEN_RSP_RESULT_CP_AUTO_RESET_ENABLED 1
    char  cp_auto_reset; //refer to AGPS_MD_GPS_OPEN_RSP_RESULT_CP_AUTO_RESET_
} agps_md_gps_open_rsp;

/*
typedef struct {
    //nothing
} agps_md_gps_close_ind;

typedef struct {
    //nothing
} agps_md_gps_close_rsp;

typedef struct {
    //nothing
} agps_md_session_abort_req;

typedef struct {
    //nothing
} agps_md_session_abort_rsp;
*/
typedef struct {
   short  length;
   char  pdu[300];
} position_protocol_pdu;

typedef struct {
    #define AGPS_MD_MOLR_BEGIN_POS_TECH_AGNSS   (1 << 0)
    #define AGPS_MD_MOLR_BEGIN_POS_TECH_ECID    (1 << 1)
    #define AGPS_MD_MOLR_BEGIN_POS_TECH_OTDOA   (1 << 2)
    int  pos_tech_bitmap;   //refer to AGPS_MD_MOLR_BEGIN_POS_TECH_
    #define AGPS_MD_MOLR_BEGIN_REQ_MOLR_TYPE_LOC_ESTIMATE 0
    #define AGPS_MD_MOLR_BEGIN_REQ_MOLR_TYPE_ASSIST_DATA 1
    char  molr_type;                //refer to AGPS_MD_MOLR_BEGIN_REQ_MOLR_TYPE_
    char gps_assist_data_used;    //0=disabled 1=enabled
    int  gps_assist_data;           //0x6f hardcode
    char  external_addr_used;     //0=disabled 1=enabled
    char  external_addr[20];
    char  mlc_number_used;        //0=disabled 1=enabled
    char  mlc_number[20];
    int  pos_protocol_pdu_num;
    position_protocol_pdu pos_protocol_pdu[3];
} agps_md_molr_begin_req;

typedef struct {
    #define AGPS_MD_MOLR_BEGIN_RSP_RESULT_FAIL 0
    #define AGPS_MD_MOLR_BEGIN_RSP_RESULT_SUCCESS 1
    char  result;    ///refer to AGPS_MD_MOLR_BEGIN_RSP_RESULT_
    char  location_used;  //0=disabled 1=enabled
    agps_md_gps_location location;
} agps_md_molr_begin_rsp;

typedef struct {
    #define AGPS_MD_MTLR_BEGIN_IND_NOTIFY_TYPE_NOTIFY_LOCATION_ALLOWED 0
    #define AGPS_MD_MTLR_BEGIN_IND_NOTIFY_TYPE_NOTIFY_VERIFY_ALLOW_IF_NO_RSP 1
    #define AGPS_MD_MTLR_BEGIN_IND_NOTIFY_TYPE_NOTIFY_VERIFY_DENY_IF_NO_RSP 2
    #define AGPS_MD_MTLR_BEGIN_IND_NOTIFY_TYPE_NOTIFY_TO_MS_USER_LOCATION_NOT_ALLOWED 3
    int session_id;
    char  notify_type;   //refer to AGPS_MD_MTLR_BEGIN_IND_NOTIFY_TYPE_
    char  requestor_id[160];    //ASCII string
    char  client_name[160];     //ASCII string
} agps_md_mtlr_begin_ind;

typedef struct {
    #define AGPS_MD_MTLR_BEGIN_2_IND_NOTIFY_TYPE_NOTIFY_LOCATION_ALLOWED 0
    #define AGPS_MD_MTLR_BEGIN_2_IND_NOTIFY_TYPE_NOTIFY_VERIFY_ALLOW_IF_NO_RSP 1
    #define AGPS_MD_MTLR_BEGIN_2_IND_NOTIFY_TYPE_NOTIFY_VERIFY_DENY_IF_NO_RSP 2
    #define AGPS_MD_MTLR_BEGIN_2_IND_NOTIFY_TYPE_NOTIFY_TO_MS_USER_LOCATION_NOT_ALLOWED 3
    int  session_id;
    char  notify_type;   //refer to AGPS_MD_MTLR_BEGIN_IND_NOTIFY_TYPE_
    char  requestor_id[160];
    int  requestor_id_len;
    char  client_name[160];
    int  client_name_len;
    #define AGPS_MD_MTLR_BEGIN_2_IND_ENCODING_TYPE_GSM7 1
    #define AGPS_MD_MTLR_BEGIN_2_IND_ENCODING_TYPE_UTF8 2
    #define AGPS_MD_MTLR_BEGIN_2_IND_ENCODING_TYPE_UCS2 3
    char  requestor_id_encoding_type;   //refer to AGPS_MD_MTLR_BEGIN_2_IND_ENCODING_TYPE_
    char  client_name_encoding_type;    //refer to AGPS_MD_MTLR_BEGIN_2_IND_ENCODING_TYPE_
} agps_md_mtlr_begin_2_ind;

typedef struct {
    #define AGPS_MD_MTLR_BEGIN_RSP_USER_RESPOND_DENY 0
    #define AGPS_MD_MTLR_BEGIN_RSP_USER_RESPOND_ACCEPT 1
    #define AGPS_MD_MTLR_BEGIN_RSP_USER_RESPOND_NO_RESPOND 2
    int session_id;
    char user_respond;  //refer to AGPS_MD_MTLR_BEGIN_RSP_USER_RESPOND
} agps_md_mtlr_begin_rsp;
/*
typedef struct {
    //nothing
} agps_md_nbr_cell_info_reg_req;
*/
typedef struct {
    #define AGPS_MD_NBR_CELL_INFO_RAT_MODE_GSM 1
    #define AGPS_MD_NBR_CELL_INFO_RAT_MODE_UMTS 2
    #define AGPS_MD_NBR_CELL_INFO_RAT_MODE_LTE 4
    char  rat_mode;
    char  is_nbr_info_valid;
    ps_nbr_cell_info_union_type  ps_nbr_cell_info_union;
} agps_md_nbr_cell_info_reg_cnf;
/*
typedef struct {
    //nothing
} agps_md_nbr_cell_info_dereg_req;

typedef struct {
    //nothing
} agps_md_nbr_cell_info_dereg_cnf;
*/
typedef struct {
    #define AGPS_MD_NBR_CELL_INFO_RAT_MODE_GSM 1
    #define AGPS_MD_NBR_CELL_INFO_RAT_MODE_UMTS 2
    #define AGPS_MD_NBR_CELL_INFO_RAT_MODE_LTE 4
    char  rat_mode;
    char  is_nbr_info_valid;
    ps_nbr_cell_info_union_type  ps_nbr_cell_info_union;
} agps_md_nbr_cell_info_ind;

typedef struct {
    char mode;  // 0=off 1=on
} agps_md_auto_test_ind;

typedef struct {
    #define AGPS_MD_AUTO_CP_UP_STATUS_MODE_SET_TO_CP 0
    #define AGPS_MD_AUTO_CP_UP_STATUS_MODE_SET_TO_UP 1
    #define AGPS_MD_AUTO_CP_UP_STATUS_MODE_CP_SET_TO_LOC_EST 2
    #define AGPS_MD_AUTO_CP_UP_STATUS_MODE_CP_SET_TO_ASSIT_DATA 3
    #define AGPS_MD_AUTO_CP_UP_STATUS_MODE_UP_SET_TO_MA 4
    #define AGPS_MD_AUTO_CP_UP_STATUS_MODE_UP_SET_TO_MB 5
    char  mode; //refer to AGPS_MD_CP_UP_STATUS_MODE_
} agps_md_auto_cp_up_status_ind;
/*
typedef struct {
    //nothing
} agps_md_auto_molr_start_ind;

typedef struct {
    //nothing
} agps_md_auto_molr_stop_ind;
*/
typedef struct {
    #define AGPS_MD_AUTO_MTLR_RESPONSE_IND_RESPONSE_REJECT 0
    #define AGPS_MD_AUTO_MTLR_RESPONSE_IND_RESPONSE_ACCEPT 1
    char  response; //refer to AGPS_MD_MTLR_RESPONSE_IND_RESPONSE_
    int session_id;
} agps_md_auto_mtlr_response_ind;

typedef struct {
    #define AGPS_MD_EMERGENCY_CALL_IND_SIM_ID_SIM_1 1
    #define AGPS_MD_EMERGENCY_CALL_IND_SIM_ID_SIM_2 2
    #define AGPS_MD_EMERGENCY_CALL_IND_SIM_ID_SIM_3 3
    #define AGPS_MD_EMERGENCY_CALL_IND_SIM_ID_SIM_4 4
    char  sim_id;   //refer to AGPS_MD_EMERGENCY_CALL_IND_SIM_ID_

    #define AGPS_MD_EMERGENCY_CALL_IND_STATE_DIALED 0
    #define AGPS_MD_EMERGENCY_CALL_IND_STATE_ENDED 1
    char  state; //refer to AGPS_MD_EMERGENCY_CALL_IND_STATE_
} agps_md_emergency_call_ind;
/*
typedef struct {
    //nothing
} agps_md_sim_info_req;
*/
typedef struct {
    #define AGPS_MD_SIM_INFO_RSP_SIM_NUMBER_SINGLE 1
    #define AGPS_MD_SIM_INFO_RSP_SIM_NUMBER_GEMINI 2
    #define AGPS_MD_SIM_INFO_RSP_SIM_NUMBER_GEMINI_3 3
    #define AGPS_MD_SIM_INFO_RSP_SIM_NUMBER_GEMINI_4 4
    char sim_number; //refer to AGPS_MD_SIM_INFO_RSP_SIM_NUMBER_
    #define AGPS_MD_SIM_INFO_RSP_MD_TYPE_FDD 0
    #define AGPS_MD_SIM_INFO_RSP_MD_TYPE_TDD 1
    char md_type;
    #define AGPS_MD_SIM_INFO_RSP_SUPPORT_EUTRAN_BAND_MAX 50
    char support_lpp_ecid;
    char support_lpp_otdoa;
    char support_eutran_band_num;
    short support_eutran_band_list[AGPS_MD_SIM_INFO_RSP_SUPPORT_EUTRAN_BAND_MAX];
} agps_md_sim_info_rsp, agps_md_sim_info_ind;
/*
typedef struct {
    //nothing
} agps_md_service_state_req;
*/
typedef struct {
    int state_bitmap;   //0=out of service  1=in service
} agps_md_service_state_rsp;
/*
typedef struct {
    //nothing
} agps_md_roaming_state_req;
*/
typedef struct {
    int state_bitmap;   //0=local or unknown  1=roaming
} agps_md_roaming_state_rsp;
/*
typedef struct {
    //nothing
} agps_md_data_connection_state_req;
*/
typedef struct {
    int state_bitmap;   //0=disconnected or unknown  1=connected
} agps_md_data_connection_state_rsp;

#endif

