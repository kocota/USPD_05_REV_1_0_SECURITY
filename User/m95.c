#include "stm32f4xx_hal.h"
#include "m95.h"
#include "cmsis_os.h"
#include "string.h"
#include "stdio.h"



extern UART_HandleTypeDef huart3;
extern osTimerId AT_TimerHandle;
extern osSemaphoreId TransmissionStateHandle;

extern char modem_rx_buffer[256];
extern uint8_t modem_rx_data[256];
extern uint8_t modem_rx_number;
extern uint8_t read_rx_state;

char find_buffer[256];

//uint8_t send_ok[] = "SEND OK\r\n";
uint8_t send_ok[] = "SEND OK";

uint8_t find_str(uint8_t* buf_in, uint16_t buf_in_len, uint8_t* buf_search, uint16_t buf_search_len)
{
	uint8_t j=0;

	for(uint8_t i=0; i<buf_in_len; i++)
	{
		if( *( buf_in+i ) == *(buf_search+j) )
		{
			j++;
			if(j>=buf_search_len)
			{
				return 1;
			}
		}
		else
		{
			j=0;
		}
	}

	return 0;
}

void m95_power_on(void) // функция включения питания
{
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_15, GPIO_PIN_RESET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_15, GPIO_PIN_SET);
	HAL_Delay(1100);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_15, GPIO_PIN_RESET);
}

void m95_power_off(void)
{
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_15, GPIO_PIN_RESET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_15, GPIO_PIN_SET);
	HAL_Delay(1100);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_15, GPIO_PIN_RESET);
}



void modem_rx_buffer_clear (void)
{
	for(uint16_t i=0; i<256; i++)
	{
		modem_rx_buffer[i] = 0;
	}
}

uint8_t ATE0 (void)
{
	char str_out[6];
	sprintf(str_out, "ATE0\r\n");

	read_rx_state = ACTIVE;
	modem_rx_number = 0;
	modem_rx_buffer_clear();
	HAL_UART_Receive_DMA(&huart3, &modem_rx_data[0], 1);
	HAL_UART_Transmit_DMA(&huart3, str_out, 6);
	//HAL_UART_Transmit_DMA(&huart3, at, 3);

	osSemaphoreWait(TransmissionStateHandle, osWaitForever);

	osTimerStart(AT_TimerHandle, 300);
	while(read_rx_state == ACTIVE)
	{
		if(strstr(modem_rx_buffer, "OK\r\n") != NULL )
		{
			osTimerStop(AT_TimerHandle);
			read_rx_state = NOT_ACTIVE;
			return AT_OK;
		}
	}
	return AT_ERROR;
}


uint8_t AT (void)
{
	char str_out[4];
	sprintf(str_out, "AT\r\n");

	read_rx_state = ACTIVE;
	modem_rx_number = 0;
	modem_rx_buffer_clear();
	HAL_UART_Receive_DMA(&huart3, &modem_rx_data[0], 1);
	HAL_UART_Transmit_DMA(&huart3, str_out, 4);
	//HAL_UART_Transmit_DMA(&huart3, at, 3);

	osSemaphoreWait(TransmissionStateHandle, osWaitForever);

	osTimerStart(AT_TimerHandle, 300);
	while(read_rx_state == ACTIVE)
	{
		if(strstr(modem_rx_buffer, "OK\r\n") != NULL )
		{
			osTimerStop(AT_TimerHandle);
			read_rx_state = NOT_ACTIVE;
			return AT_OK;
		}
	}
	return AT_ERROR;
}


uint8_t request_to_server() // функция запроса к серверу, чтобы тот прочитал регистры из устройства
{
	uint8_t send_out[5] = {0x01, 0x02, 0x03, 0x04, 0x05};

	if( AT_CIPSEND(&send_out[0], 5) == AT_OK )
	{
		return AT_OK;
	}

	return AT_ERROR;
}

//---- SIM800C commands ------------------------------------------

uint8_t AT_CIPIN (void)
{
	uint8_t str_out[10];
	sprintf(str_out, "AT+CPIN?\r\n");
	read_rx_state = ACTIVE;
	modem_rx_number = 0;
	modem_rx_buffer_clear();

	HAL_UART_Receive_DMA(&huart3, &modem_rx_data[0], 1);
	HAL_UART_Transmit_DMA(&huart3, str_out, 10);

	osSemaphoreWait(TransmissionStateHandle, osWaitForever);

	osTimerStart(AT_TimerHandle, 5000);
	while(read_rx_state == ACTIVE)
	{

		if(strstr(modem_rx_buffer, "OK\r\n") != NULL )
		{
			osTimerStop(AT_TimerHandle);
			read_rx_state = NOT_ACTIVE;
			return AT_OK;
		}

	}
	return AT_ERROR;
}

uint8_t AT_CSQ (uint8_t* signal_level)
{
	char str_out[8];
	sprintf(str_out, "AT+CSQ\r\n");

	read_rx_state = ACTIVE;
	modem_rx_number = 0;
	modem_rx_buffer_clear();
	HAL_UART_Receive_DMA(&huart3, &modem_rx_data[0], 1);
	HAL_UART_Transmit_DMA(&huart3, str_out, 8);
	//HAL_UART_Transmit_DMA(&huart3, at_csq, 7);

	osSemaphoreWait(TransmissionStateHandle, osWaitForever);

	osTimerStart(AT_TimerHandle, 300);
	while(read_rx_state == ACTIVE)
	{
		//osThreadSuspend(M95TaskHandle);
		if(strstr(modem_rx_buffer, "+CSQ:") != NULL )
		{
			if(modem_rx_buffer[9]==',') // в случае, если ATE0 (эхо выключено)
			{
				*signal_level = modem_rx_buffer[8]-0x30;
			}
			else
			{
				*signal_level = (modem_rx_buffer[8]-0x30)*10 + (modem_rx_buffer[9]-0x30);
			}
			// если ATE1 (эхо включено)

			//if(modem_rx_buffer[15]==',')
			//{
				//*signal_level = modem_rx_buffer[14]-0x30;
			//}
			//else
			//{
				//*signal_level = (modem_rx_buffer[14]-0x30)*10 + (modem_rx_buffer[15]-0x30);
			//}

		}
		if(strstr(modem_rx_buffer, "OK") != NULL )
		{
			osTimerStop(AT_TimerHandle);
			read_rx_state = NOT_ACTIVE;
			return AT_OK;
		}
	}
	return AT_ERROR;
}

uint8_t AT_CIPSTATUS (void)
{
	uint8_t str_out[14];
	sprintf(str_out, "AT+CIPSTATUS\r\n");
	read_rx_state = ACTIVE;
	modem_rx_number = 0;
	modem_rx_buffer_clear();

	HAL_UART_Receive_DMA(&huart3, &modem_rx_data[0], 1);
	HAL_UART_Transmit_DMA(&huart3, str_out, 14);

	osSemaphoreWait(TransmissionStateHandle, osWaitForever);

	osTimerStart(AT_TimerHandle, 300);
	while(read_rx_state == ACTIVE)
	{
		//osThreadSuspend(M95TaskHandle);
		if(strstr(modem_rx_buffer, "IP INITIAL\r\n") != NULL )
		{
			osTimerStop(AT_TimerHandle);
			read_rx_state = NOT_ACTIVE;
			return IP_INITIAL;
		}
		if(strstr(modem_rx_buffer, "IP START\r\n") != NULL )
		{
			osTimerStop(AT_TimerHandle);
			read_rx_state = NOT_ACTIVE;
			return IP_START;
		}
		if(strstr(modem_rx_buffer, "IP CONFIG\r\n") != NULL )
		{
			osTimerStop(AT_TimerHandle);
			read_rx_state = NOT_ACTIVE;
			return IP_CONFIG;
		}
		if(strstr(modem_rx_buffer, "IP IND\r\n") != NULL )
		{
			osTimerStop(AT_TimerHandle);
			read_rx_state = NOT_ACTIVE;
			return IP_IND;
		}
		if(strstr(modem_rx_buffer, "IP GPRSACT\r\n") != NULL )
		{
			osTimerStop(AT_TimerHandle);
			read_rx_state = NOT_ACTIVE;
			return IP_GPRSACT;
		}
		if(strstr(modem_rx_buffer, "IP STATUS\r\n") != NULL )
		{
			osTimerStop(AT_TimerHandle);
			read_rx_state = NOT_ACTIVE;
			return IP_STATUS;
		}
		if(strstr(modem_rx_buffer, "TCP CONNECTING\r\n") != NULL )
		{
			osTimerStop(AT_TimerHandle);
			read_rx_state = NOT_ACTIVE;
			return TCP_CONNECTING;
		}
		if(strstr(modem_rx_buffer, "UDP CONNECTING\r\n") != NULL )
		{
			osTimerStop(AT_TimerHandle);
			read_rx_state = NOT_ACTIVE;
			return UDP_CONNECTING;
		}
		if(strstr(modem_rx_buffer, "IP CLOSE\r\n") != NULL )
		{
			osTimerStop(AT_TimerHandle);
			read_rx_state = NOT_ACTIVE;
			return IP_CLOSE;
		}
		if(strstr(modem_rx_buffer, "CONNECT OK\r\n") != NULL )
		{
			osTimerStop(AT_TimerHandle);
			read_rx_state = NOT_ACTIVE;
			return CONNECT_OK;
		}
		if(strstr(modem_rx_buffer, "PDP DEACT\r\n") != NULL )
		{
			osTimerStop(AT_TimerHandle);
			read_rx_state = NOT_ACTIVE;
			return PDP_DEACT;
		}
		if(strstr(modem_rx_buffer, "ERROR\r\n") != NULL )
		{
			osTimerStop(AT_TimerHandle);
			read_rx_state = NOT_ACTIVE;
			return AT_ERROR;
		}
		if(strstr(modem_rx_buffer, "TCP CLOSED\r\n") != NULL )
		{
			osTimerStop(AT_TimerHandle);
			read_rx_state = NOT_ACTIVE;
			return TCP_CLOSED;
		}

	}
	return AT_ERROR;
}

uint8_t AT_CSTT  (char* apn, char* user, char* password)
{
	uint8_t n;
	char str_out[101];
	sprintf(str_out, "AT+CSTT=\"%s\",\"%s\",\"%s\"\r\n", apn, user, password);
	n = strlen(str_out);

	read_rx_state = ACTIVE;
	modem_rx_number = 0;
	modem_rx_buffer_clear();

	HAL_UART_Receive_DMA(&huart3, &modem_rx_data[0], 1);
	HAL_UART_Transmit_DMA(&huart3, str_out, n);

	osSemaphoreWait(TransmissionStateHandle, osWaitForever);

	osTimerStart(AT_TimerHandle, 300);
	while(read_rx_state == ACTIVE)
	{
		//osThreadSuspend(M95TaskHandle);
		if(strstr(modem_rx_buffer, "OK\r\n") != NULL )
		{
			osTimerStop(AT_TimerHandle);
			read_rx_state = NOT_ACTIVE;
			return AT_OK;
		}
		if(strstr(modem_rx_buffer, "ERROR\r\n") != NULL )
		{
			osTimerStop(AT_TimerHandle);
			read_rx_state = NOT_ACTIVE;
			return AT_ERROR;
		}

	}
	return AT_ERROR;

}

uint8_t AT_CIICR  (void)
{
	uint8_t str_out[10];
	sprintf(str_out, "AT+CIICR\r\n");

	read_rx_state = ACTIVE;
	modem_rx_number = 0;
	modem_rx_buffer_clear();

	HAL_UART_Receive_DMA(&huart3, &modem_rx_data[0], 1);
	HAL_UART_Transmit_DMA(&huart3, str_out, 10);

	osSemaphoreWait(TransmissionStateHandle, osWaitForever);

	osTimerStart(AT_TimerHandle, 5000);
	while(read_rx_state == ACTIVE)
	{
		//osThreadSuspend(M95TaskHandle);
		if(strstr(modem_rx_buffer, "OK\r\n") != NULL )
		{
			osTimerStop(AT_TimerHandle);
			read_rx_state = NOT_ACTIVE;
			return AT_OK;
		}
		if(strstr(modem_rx_buffer, "ERROR\r\n") != NULL )
		{
			osTimerStop(AT_TimerHandle);
			read_rx_state = NOT_ACTIVE;
			return AT_ERROR;
		}

	}
	return AT_ERROR;

}

uint8_t AT_CIFSR  (void)
{
	uint8_t str_out[10];
	sprintf(str_out, "AT+CIFSR\r\n");

	read_rx_state = ACTIVE;
	modem_rx_number = 0;
	modem_rx_buffer_clear();

	HAL_UART_Receive_DMA(&huart3, &modem_rx_data[0], 1);
	HAL_UART_Transmit_DMA(&huart3, str_out, 10);

	osSemaphoreWait(TransmissionStateHandle, osWaitForever);

	osTimerStart(AT_TimerHandle, 5000);
	while(read_rx_state == ACTIVE)
	{
		//osThreadSuspend(M95TaskHandle);
		if(strstr(modem_rx_buffer, "OK\r\n") != NULL )
		{
			osTimerStop(AT_TimerHandle);
			read_rx_state = NOT_ACTIVE;
			return AT_OK;
		}
		if(strstr(modem_rx_buffer, "ERROR\r\n") != NULL )
		{
			osTimerStop(AT_TimerHandle);
			read_rx_state = NOT_ACTIVE;
			return AT_ERROR;
		}

	}
	return AT_ERROR;

}

uint8_t AT_CIPSTART (char* type , uint8_t ip1, uint8_t ip2, uint8_t ip3, uint8_t ip4, uint16_t port)
{
	char str1[3];
	char str2[3];
	char str3[3];
	char str4[3];
	char str5[3];
	char str6[5];
	char str7[42];
	uint8_t n;

	sprintf(str1, "%s", type);
	sprintf(str2, "%u", ip1);
	sprintf(str3, "%u", ip2);
	sprintf(str4, "%u", ip3);
	sprintf(str5, "%u", ip4);
	sprintf(str6, "%u", port);

	n = sprintf(str7, "AT+CIPSTART=\"%s\",\"%s.%s.%s.%s\",%s\r\n", str1, str2, str3, str4, str5, str6);

 	read_rx_state = ACTIVE;
	modem_rx_number = 0;
	modem_rx_buffer_clear();

	HAL_UART_Receive_DMA(&huart3, &modem_rx_data[0], 1);
	HAL_UART_Transmit_DMA(&huart3, str7, n);

	osSemaphoreWait(TransmissionStateHandle, osWaitForever);

	osTimerStart(AT_TimerHandle, 3000);
	while(read_rx_state == ACTIVE)
	{
		//osThreadSuspend(M95TaskHandle);
		if( (strstr(modem_rx_buffer, "CONNECT OK\r\n") != NULL) )
		{
			osTimerStop(AT_TimerHandle);
			read_rx_state = NOT_ACTIVE;
			return AT_OK;
		}
		else if( (strstr(modem_rx_buffer, "ALREADY CONNECT\r\n") != NULL) )
		{
			osTimerStop(AT_TimerHandle);
			read_rx_state = NOT_ACTIVE;
			return AT_OK;
		}
		else if( (strstr(modem_rx_buffer, "CONNECT FAIL\r\n") != NULL) )
		{
			osTimerStop(AT_TimerHandle);
			read_rx_state = NOT_ACTIVE;
			return AT_ERROR;
		}

	}
	return AT_ERROR;

}

uint8_t AT_CIPSEND (uint8_t* buf, uint16_t length) // maximum length = 1460
{
	uint8_t n1;
	char str_out[17];

	n1 = sprintf(str_out, "AT+CIPSEND=%u\r\n", length);

 	read_rx_state = ACTIVE;
	modem_rx_number = 0;
	modem_rx_buffer_clear();

	HAL_UART_Receive_DMA(&huart3, &modem_rx_data[0], 1);
	HAL_UART_Transmit_DMA(&huart3, str_out, n1);

	osSemaphoreWait(TransmissionStateHandle, osWaitForever);

	osTimerStart(AT_TimerHandle, 300);
	while(read_rx_state == ACTIVE)
	{
		//osThreadSuspend(osThreadGetId());
		//osSemaphoreWait(ReceiveStateHandle, osWaitForever);
		if( strstr(modem_rx_buffer, "> ") != NULL )
		{
			osTimerStop(AT_TimerHandle);
			modem_rx_number = 0;
			modem_rx_buffer_clear();

			HAL_UART_Receive_DMA(&huart3, &modem_rx_data[0], 1);
			HAL_UART_Transmit_DMA(&huart3, buf, length);

			osSemaphoreWait(TransmissionStateHandle, osWaitForever);

			osTimerStart(AT_TimerHandle, 3000); // маленькое время!!!!!
			while(read_rx_state == ACTIVE)
			{
				//osThreadSuspend(osThreadGetId());
				//osSemaphoreWait(ReceiveStateHandle, osWaitForever);

				if( find_str(modem_rx_buffer, 255, send_ok, 7) == 1 )
				{
					osTimerStop(AT_TimerHandle);
					read_rx_state = NOT_ACTIVE;
					return AT_OK;
				}

				/*
				if( strstr(modem_rx_buffer, "SEND OK\r\n") != NULL )
				{
					osTimerStop(AT_TimerHandle);
					read_rx_state = NOT_ACTIVE;
					return AT_OK;
				}
				*/
				//HAL_Delay(1);
				/*
				else if( strstr(modem_rx_buffer, "ERROR\r\n") != NULL )
				{
					osTimerStop(AT_TimerHandle);
					read_rx_state = NOT_ACTIVE;
					return AT_ERROR;
				}
				*/
			}
			return AT_ERROR;
		}
		/*
		else if( strstr(modem_rx_buffer, "ERROR\r\n") != NULL )
		{
			osTimerStop(AT_TimerHandle);
			read_rx_state = NOT_ACTIVE;
			return AT_ERROR;
		}*/

	}
	return AT_ERROR;

}

uint8_t AT_CIPSHUT  (void)
{
	uint8_t str_out[12];
	sprintf(str_out, "AT+CIPSHUT\r\n");

	read_rx_state = ACTIVE;
	modem_rx_number = 0;
	modem_rx_buffer_clear();

	HAL_UART_Receive_DMA(&huart3, &modem_rx_data[0], 1);
	HAL_UART_Transmit_DMA(&huart3, str_out, 12);

	osSemaphoreWait(TransmissionStateHandle, osWaitForever);

	osTimerStart(AT_TimerHandle, 10000);
	while(read_rx_state == ACTIVE)
	{
		//osThreadSuspend(M95TaskHandle);
		if(strstr(modem_rx_buffer, "OK\r\n") != NULL )
		{
			osTimerStop(AT_TimerHandle);
			read_rx_state = NOT_ACTIVE;
			return AT_OK;
		}
		if(strstr(modem_rx_buffer, "ERROR\r\n") != NULL )
		{
			osTimerStop(AT_TimerHandle);
			read_rx_state = NOT_ACTIVE;
			return AT_ERROR;
		}

	}
	return AT_ERROR;

}

uint8_t AT_CCID ( uint8_t* id, uint64_t* temp_id) // Команда для для чтения CCID сим карты. id - указатель к массиву в которую будет сохраняться CCID симкарты (должен быть 8 байт), temp_id - указатель к временному массиву для расчета (должен быть 20 байт)
{
	//uint64_t id1[20];
	char str_out[9];
	sprintf(str_out, "AT+CCID\r\n");
	read_rx_state = ACTIVE;
	modem_rx_number = 0;
	modem_rx_buffer_clear();
	HAL_UART_Receive_DMA(&huart3, &modem_rx_data[0], 1);
	HAL_UART_Transmit_DMA(&huart3, str_out, 9);

	osSemaphoreWait(TransmissionStateHandle, osWaitForever);

	osTimerStart(AT_TimerHandle, 300);
	while(read_rx_state == ACTIVE)
	{
		//osThreadSuspend(M95TaskHandle);
		if(strstr(modem_rx_buffer, "OK\r\n") != NULL )
		{
			osTimerStop(AT_TimerHandle);
			read_rx_state = NOT_ACTIVE;

			// В случае, когда ATE0, эхо выключено
			for(uint8_t i=0; i<19; i++)
			{
				*(temp_id+i) = (uint8_t)modem_rx_buffer[4+i] - 48;
				//temp_id[i] = (uint8_t)modem_rx_buffer[10+i] - 48;
			}
			// В случае, когда ATE1, эхо включено
			/*
			for(uint8_t i=0; i<19; i++)
			{
				*(temp_id+i) = (uint8_t)modem_rx_buffer[10+i] - 48;
				//temp_id[i] = (uint8_t)modem_rx_buffer[10+i] - 48;
			}
			*/

			*(temp_id+19) = *temp_id*1000000000000000000 + *(temp_id+1)*100000000000000000 + *(temp_id+2)*10000000000000000 + *(temp_id+3)*1000000000000000 + *(temp_id+4)*100000000000000 + *(temp_id+5)*10000000000000 + *(temp_id+6)*1000000000000 + *(temp_id+7)*100000000000 + *(temp_id+8)*10000000000 + *(temp_id+9)*1000000000 + *(temp_id+10)*100000000 + *(temp_id+11)*10000000 + *(temp_id+12)*1000000 + *(temp_id+13)*100000 + *(temp_id+14)*10000 + *(temp_id+15)*1000 + *(temp_id+16)*100 + *(temp_id+17)*10 + *(temp_id+18);
			//temp_id[19] = temp_id[0]*1000000000000000000 + temp_id[1]*100000000000000000 + temp_id[2]*10000000000000000 + temp_id[3]*1000000000000000 + temp_id[4]*100000000000000 + temp_id[5]*10000000000000 + temp_id[6]*1000000000000 + temp_id[7]*100000000000 + temp_id[8]*10000000000 + temp_id[9]*1000000000 + temp_id[10]*100000000 + temp_id[11]*10000000 + temp_id[12]*1000000 + temp_id[13]*100000 + temp_id[14]*10000 + temp_id[15]*1000 + temp_id[16]*100 + temp_id[17]*10 + temp_id[18];

			*id = (uint8_t)(*(temp_id+19)>>56);
			*(id+1) = (uint8_t)(*(temp_id+19)>>48);
			*(id+2) = (uint8_t)(*(temp_id+19)>>40);
			*(id+3) = (uint8_t)(*(temp_id+19)>>32);
			*(id+4) = (uint8_t)(*(temp_id+19)>>24);
			*(id+5) = (uint8_t)(*(temp_id+19)>>16);
			*(id+6) = (uint8_t)(*(temp_id+19)>>8);
			*(id+7) = (uint8_t)*(temp_id+19);

			return AT_OK;
		}

	}
	return AT_ERROR;
}

uint8_t AT_CPOWD (uint8_t mode) // функция отключения питания. mode: 1 - сообщение NORMAL POWER DOWN включено, 0 - сообщение NORMAL POWER DOWN выключено
{
	uint8_t str_out[12];
	sprintf(str_out, "AT+CPOWD=%u\r\n", mode);
	read_rx_state = ACTIVE;
	modem_rx_number = 0;
	modem_rx_buffer_clear();

	HAL_UART_Receive_DMA(&huart3, &modem_rx_data[0], 1);
	HAL_UART_Transmit_DMA(&huart3, str_out, 12);

	osSemaphoreWait(TransmissionStateHandle, osWaitForever);

	osTimerStart(AT_TimerHandle, 300);
	while(read_rx_state == ACTIVE)
	{
		//osThreadSuspend(M95TaskHandle);
		if(mode==0)
		{
			if(strstr(modem_rx_buffer, "OK") != NULL )
			{
				osTimerStop(AT_TimerHandle);
				read_rx_state = NOT_ACTIVE;
				return AT_OK;
			}
		}
		else if(mode==1)
		{
			if(strstr(modem_rx_buffer, "NORMAL POWER DOWN") != NULL )
			{
				osTimerStop(AT_TimerHandle);
				read_rx_state = NOT_ACTIVE;
				return AT_OK;
			}
		}


	}
	return AT_ERROR;
}

uint8_t AT_CIPTKA  (void)
{
	uint8_t str_out[12];
	sprintf(str_out, "AT+CIPTKA?\r\n");

	read_rx_state = ACTIVE;
	modem_rx_number = 0;
	modem_rx_buffer_clear();

	HAL_UART_Receive_DMA(&huart3, &modem_rx_data[0], 1);
	HAL_UART_Transmit_DMA(&huart3, str_out, 12);

	osSemaphoreWait(TransmissionStateHandle, osWaitForever);

	osTimerStart(AT_TimerHandle, 10000);
	while(read_rx_state == ACTIVE)
	{
		//osThreadSuspend(M95TaskHandle);
		if(strstr(modem_rx_buffer, "OK\r\n") != NULL )
		{
			osTimerStop(AT_TimerHandle);
			read_rx_state = NOT_ACTIVE;
			return AT_OK;
		}
		if(strstr(modem_rx_buffer, "ERROR\r\n") != NULL )
		{
			osTimerStop(AT_TimerHandle);
			read_rx_state = NOT_ACTIVE;
			return AT_ERROR;
		}

	}
	return AT_ERROR;

}


