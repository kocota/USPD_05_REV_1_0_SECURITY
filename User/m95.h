#ifndef M95
#define M95

//---- Состояние проверки принятого пакета от модема-----------

#define ACTIVE     1 // активно
#define NOT_ACTIVE 0 // не активно

//-------------------------------------------------------------

//---- Тип возвращаемого значения при выполнении АТ команды----

#define AT_OK    0  // АТ команда выполнена без ошибок
#define AT_ERROR 1  // АТ команда не выполнена

//-------------------------------------------------------------

//---- Тип протокола-------------------------------------------

#define TCP 0
#define UDP 1

//-------------------------------------------------------------

//---- Состояние модема ---------------------------------------

#define IP_INITIAL     2
#define IP_START       3
#define IP_CONFIG      4
#define IP_IND         5
#define IP_GPRSACT     6
#define IP_STATUS      7
#define TCP_CONNECTING 8
#define UDP_CONNECTING 9
#define IP_CLOSE       10
#define CONNECT_OK     11
#define PDP_DEACT      12
#define TCP_CLOSED     13

//-------------------------------------------------------------

//----прототипы функций общения с модемом SIM800C----------
void m95_power_on(void);
void m95_power_off(void);
void modem_rx_buffer_clear (void);

uint8_t request_to_server();
uint8_t find_str(uint8_t* buf_in, uint16_t buf_in_len, uint8_t* buf_search, uint16_t buf_search_len);
uint8_t ATE0 (void);
uint8_t AT (void);
uint8_t AT_CSQ (uint8_t* signal_level);
uint8_t AT_CIPIN (void);
uint8_t AT_CIPSTATUS (void);
uint8_t AT_QIREGAPP  (char* apn, char* user, char* password);
uint8_t AT_CSTT  (char* apn, char* user, char* password);
uint8_t AT_CIICR  (void);
uint8_t AT_CIFSR  (void);
uint8_t AT_CIPSTART (char* type , uint8_t ip1, uint8_t ip2, uint8_t ip3, uint8_t ip4, uint16_t port);
uint8_t AT_CIPSEND (uint8_t* buf, uint16_t length);
uint8_t AT_CIPSHUT  (void);
uint8_t AT_CCID ( uint8_t* id, uint64_t* temp_id);
uint8_t AT_CPOWD (uint8_t mode);
uint8_t AT_CIPTKA  (void);
//------------------------------------------------------------


void ThreadM95Task(void const * argument);



#endif
