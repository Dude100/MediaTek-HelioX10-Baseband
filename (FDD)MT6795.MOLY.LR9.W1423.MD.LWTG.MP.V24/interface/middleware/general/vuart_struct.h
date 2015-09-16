typedef struct 
{
LOCAL_PARA_HDR
 UART_PORT port;
 module_type owner;
}uart_putbytes_req_struct;

typedef struct 
{
    LOCAL_PARA_HDR
    UART_PORT port;
    kal_bool  sendReadyToRead;
}uart_getbytes_ind_struct;

typedef struct 
{
    LOCAL_PARA_HDR
     UART_PORT port;
     module_type owner;
     kal_bool      is_WriteSuspend;
     kal_uint16   maxWriteLength;
}uart_set_config_ind_struct;

