#include "stm32f4xx_hal.h"
#include "cmsis_os.h"
#include "modbus.h"
#include "fm25v02.h"
#include "m95.h"
#include "gpio.h"

extern osThreadId M95TaskHandle;
extern UART_HandleTypeDef huart3;
extern osSemaphoreId TransmissionStateHandle;
extern osSemaphoreId ReceiveStateHandle;
extern osMutexId UartMutexHandle;
extern osMutexId Fm25v02MutexHandle;
extern osTimerId Ring_Center_TimerHandle;
extern osThreadId CallRingCenterTaskHandle;

extern uint8_t modem_rx_data[256];

uint8_t level;

volatile uint8_t ip1 = 0; // стартовое значение ip адреса сервера
volatile uint8_t ip2 = 0; // стартовое значение ip адреса сервера
volatile uint8_t ip3 = 0; // стартовое значение ip адреса сервера
volatile uint8_t ip4 = 0;  // стартовое значение ip адреса сервера
volatile uint8_t port_high_reg = 0; // старший байт номера порта сервера
volatile uint8_t port_low_reg = 0;  // младший байт номера порта сервера
volatile uint16_t port = 0;   // номер порта сервера

uint8_t state;
uint8_t Version_H = 0;  // версия прошивки, старший байт
uint8_t Version_L = 14; // версия прошивки, младший байт
uint8_t id2[10]; // номер CCID симкарты
uint64_t id1[20];

uint8_t idh = 1;
uint8_t idl = 15;

volatile uint8_t request_state = 0;

volatile uint8_t connect_ok_state = 0;




void ThreadM95Task(void const * argument)
{
	osThreadSuspend(M95TaskHandle);
	osSemaphoreWait(TransmissionStateHandle, osWaitForever); // обнуляем семафор, при создании семафора его значение равно 1
	osSemaphoreWait(ReceiveStateHandle, osWaitForever); // обнуляем семафор, при создании семафора его значение равно 1

	osTimerStart(Ring_Center_TimerHandle, 60000); // запускаем таймер для перезагрузки по его окончанию


	osMutexWait(Fm25v02MutexHandle, osWaitForever);
	fm25v02_write(2*VERSION_REG, 0x02);
	fm25v02_write(2*VERSION_REG+1, 0x0E);
	osMutexRelease(Fm25v02MutexHandle);



	for(;;)
	{

		osMutexWait(Fm25v02MutexHandle, osWaitForever);

		fm25v02_read(2*IP_1_REG+1, &ip1); // читаем значение IP адреса сервера из памяти
		fm25v02_read(2*IP_2_REG+1, &ip2);
		fm25v02_read(2*IP_3_REG+1, &ip3);
		fm25v02_read(2*IP_4_REG+1, &ip4);
		fm25v02_read(2*PORT_HIGH_REG+1, &port_high_reg); // читаем значение старшего байта порта сервера
		fm25v02_read(2*PORT_LOW_REG+1, &port_low_reg); // читаем занчение младшего байта порта сервера

		osMutexRelease(Fm25v02MutexHandle);

		port = (((uint16_t)port_high_reg)<<8)|((uint16_t)port_low_reg); // вычисляем общее значение регистра порта

		if ( (ip1==0)&&(ip2==0)&&(ip3==0)&&(ip4==0)&&(port==0) ) // Если значения ip адреса сервера и его номера порта при инициализации нулевые, то выставляем их значения по умолчанию
		{
			// сервер сигнализации
			ip1 = 195;    // значение по умолчанию
			ip2 = 208;    // значение по умолчанию
			ip3 = 163;    // значение по умолчанию
			ip4 = 67;     // значение по умолчанию
			port = 35050; // значение по умолчанию

			// сервер освещения
			//ip1 = 195;    // значение по умолчанию
			//ip2 = 208;    // значение по умолчанию
			//ip3 = 163;    // значение по умолчанию
			//ip4 = 67;     // значение по умолчанию
			//port = 35070; // значение по умолчанию
		}

		/*
		osMutexWait(UartMutexHandle, osWaitForever);

		if( ATE0() == AT_OK )
		{

		}
		else
		{
			m95_power_on();
		}
		*/

		osMutexWait(UartMutexHandle, osWaitForever);

		if(AT()==AT_ERROR) // два раза проверяем, есть ли ответ на команду АТ, если нет, включаем питание
		{
			if(AT()==AT_ERROR)
			{
				m95_power_on();
			}
		}

		if( ATE0() == AT_OK )
		{

		}

		osMutexRelease(UartMutexHandle);

		osMutexWait(UartMutexHandle, osWaitForever);

		switch( AT_CIPSTATUS() )
		{

			case IP_INITIAL:

				LED1_OFF();

				AT_CSTT("internet.mts.ru","mts","mts");

			break;

			case IP_START:

				LED1_OFF();

				AT_CIICR();

			break;

			case IP_GPRSACT:

				LED1_OFF();

				AT_CIFSR();

			break;

			case IP_STATUS:

				LED1_OFF();

				AT_CIPSTART("TCP", ip1, ip2, ip3, ip4, port);

			break;

			case CONNECT_OK:

				osThreadResume(CallRingCenterTaskHandle); // пробуждаем процесс запроса к серверу

				LED1_ON();

				if( AT_CSQ(&level) == AT_OK )
				{
					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_write(2*SIGNAL_LEVEL_REG, 0x00);
					fm25v02_write(2*SIGNAL_LEVEL_REG+1, level);
					osMutexRelease(Fm25v02MutexHandle);
				}

				if(	AT_CCID(&id2[0], &id1[0]) == AT_OK ) // читаем CCID сим-карты
				{
					osMutexWait(Fm25v02MutexHandle, osWaitForever);

					fm25v02_write(2*ICCID_NUMBER_REG1, 0x00); // записываем в регистры CCID сим-карты
					fm25v02_write(2*ICCID_NUMBER_REG1+1, id2[0]);
					fm25v02_write(2*ICCID_NUMBER_REG2, 0x00);
					fm25v02_write(2*ICCID_NUMBER_REG2+1, id2[1]);
					fm25v02_write(2*ICCID_NUMBER_REG3, 0x00);
					fm25v02_write(2*ICCID_NUMBER_REG3+1, id2[2]);
					fm25v02_write(2*ICCID_NUMBER_REG4, 0x00);
					fm25v02_write(2*ICCID_NUMBER_REG4+1, id2[3]);
					fm25v02_write(2*ICCID_NUMBER_REG5, 0x00);
					fm25v02_write(2*ICCID_NUMBER_REG5+1, id2[4]);
					fm25v02_write(2*ICCID_NUMBER_REG6, 0x00);
					fm25v02_write(2*ICCID_NUMBER_REG6+1, id2[5]);
					fm25v02_write(2*ICCID_NUMBER_REG7, 0x00);
					fm25v02_write(2*ICCID_NUMBER_REG7+1, id2[6]);
					fm25v02_write(2*ICCID_NUMBER_REG8, 0x00);
					fm25v02_write(2*ICCID_NUMBER_REG8+1, id2[7]);

					osMutexRelease(Fm25v02MutexHandle);
				}

				if( request_state == 0)
				{
					request_state = 1;
					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_write(2*GPRS_CALL_REG, 0x00);
					fm25v02_write(2*GPRS_CALL_REG+1, CALL_ON);
					osMutexRelease(Fm25v02MutexHandle);
				}

			break;

			case TCP_CLOSED:

				osThreadSuspend(CallRingCenterTaskHandle);

				LED1_OFF();

				AT_CIPSTART("TCP", ip1, ip2, ip3, ip4, port);

			break;

			case PDP_DEACT:

				LED1_OFF();

				AT_CIPSHUT();

			break;

			case TCP_CONNECTING:

				LED1_OFF();

			break;

		}

		osMutexRelease(UartMutexHandle);

		osDelay(1000);

	}
}
