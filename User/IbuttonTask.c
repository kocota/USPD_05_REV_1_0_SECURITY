#include "stm32f4xx_hal.h"
#include "IbuttonTask.h"
#include "SecurityTask.h"
#include "cmsis_os.h"
#include "gpio.h"
#include "ibutton.h"
#include "modbus.h"
#include "fm25v02.h"


extern volatile uint8_t security_state;
extern osTimerId Ring_Center_TimerHandle;
extern osThreadId IbuttonTaskHandle;
extern osMutexId Fm25v02MutexHandle;
extern status_register_struct status_registers;
extern control_register_struct control_registers;
extern volatile uint8_t security_state_temp;

uint8_t t_data[50];

IbuttonROM_Struct IbuttonROM;
uint32_t t;


//Поток обработки ibutton и постановки на сигнализацию-------------------------
void ThreadIbuttonTask(void const * argument)
{
	uint8_t ibutton_temp[8]; //временная переменная для записи номера таблетки
	uint8_t temp;
	osThreadSuspend(IbuttonTaskHandle); // переводим поток ThreadIbuttonTask в спящий режим

	osMutexWait(Fm25v02MutexHandle, osWaitForever);
	fm25v02_write(2*SECURITY_STATUS_REG, 0x00); // обнуляем старший байт статуса режима охраны
	fm25v02_read(2*SECURITY_STATUS_REG+1, &temp); // читаем младший байт статуса режима охраны
	osMutexRelease(Fm25v02MutexHandle);

	if( (temp<0)||(temp>8) ) // если младший байт статуса режима охраны не входит в диапазон режимов статуса охраны, то обнуляем младший байт статуса режима охраны
	{
		osMutexWait(Fm25v02MutexHandle, osWaitForever);
		fm25v02_write(2*SECURITY_STATUS_REG, 0x00);
		fm25v02_write(2*SECURITY_STATUS_REG+1, 0x00); // обнуляем младший байт статуса режима охраны
		osMutexRelease(Fm25v02MutexHandle);
	}

	for(;;)
	{
		if( ibutton_reset() == HAL_OK )// Инициализируем ibutton таблетку, проверяем отвечает ли она на сброс, если отвечает, то выполняем чтение ROM
		{

			if( ibutton_read_rom(&IbuttonROM) == HAL_OK ) // Считываем ROM-код таблетки
			{
				if( (ibutton_search_rom(&IbuttonROM) == HAL_OK) && (IbuttonROM.IbuttonROM_High != 0) && (IbuttonROM.IbuttonROM_Low != 0) )
				{

		  			BUZ_ON();
		  			HAL_Delay(20);
		  			BUZ_OFF();

					ibutton_temp[0] = (uint8_t)(IbuttonROM.IbuttonROM_Low); // записываем во временные переменные номер найденной таблетки
					ibutton_temp[1] = (uint8_t)(IbuttonROM.IbuttonROM_Low>>8);
					ibutton_temp[2] = (uint8_t)(IbuttonROM.IbuttonROM_Low>>16);
					ibutton_temp[3] = (uint8_t)(IbuttonROM.IbuttonROM_Low>>24);
					ibutton_temp[4] = (uint8_t)(IbuttonROM.IbuttonROM_High);
					ibutton_temp[5] = (uint8_t)(IbuttonROM.IbuttonROM_High>>8);
					ibutton_temp[6] = (uint8_t)(IbuttonROM.IbuttonROM_High>>16);
					ibutton_temp[7] = (uint8_t)(IbuttonROM.IbuttonROM_High>>24);

					if( (status_registers.security_status_reg == DISABLED_BY_IBUTTON) || (status_registers.security_status_reg == DISABLED_BY_SERVER) || (status_registers.security_status_reg == RESERVED_0) ) // Если сигнализация выключена, ставим на охрану
			  		{

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*IBUTTON_COMPLETE_0_REG, 0x00);
						fm25v02_write(2*IBUTTON_COMPLETE_0_REG+1, ibutton_temp[0]);
						fm25v02_write(2*IBUTTON_COMPLETE_1_REG, 0x00);
						fm25v02_write(2*IBUTTON_COMPLETE_1_REG+1, ibutton_temp[1]);
						fm25v02_write(2*IBUTTON_COMPLETE_2_REG, 0x00);
						fm25v02_write(2*IBUTTON_COMPLETE_2_REG+1, ibutton_temp[2]);
						fm25v02_write(2*IBUTTON_COMPLETE_3_REG, 0x00);
						fm25v02_write(2*IBUTTON_COMPLETE_3_REG+1, ibutton_temp[3]);
						fm25v02_write(2*IBUTTON_COMPLETE_4_REG, 0x00);
						fm25v02_write(2*IBUTTON_COMPLETE_4_REG+1, ibutton_temp[4]);
						fm25v02_write(2*IBUTTON_COMPLETE_5_REG, 0x00);
						fm25v02_write(2*IBUTTON_COMPLETE_5_REG+1, ibutton_temp[5]);
						fm25v02_write(2*IBUTTON_COMPLETE_6_REG, 0x00);
						fm25v02_write(2*IBUTTON_COMPLETE_6_REG+1, ibutton_temp[6]);
						fm25v02_write(2*IBUTTON_COMPLETE_7_REG, 0x00);
						fm25v02_write(2*IBUTTON_COMPLETE_7_REG+1, ibutton_temp[7]);
						osMutexRelease(Fm25v02MutexHandle);

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*SECURITY_CONTROL_REG, 0x00); // запускаем процесс постановки на охрану
						fm25v02_write(2*SECURITY_CONTROL_REG+1, ENABLE_FROM_IBUTTON);
						osMutexRelease(Fm25v02MutexHandle);

						control_registers.security_control_reg = ENABLE_FROM_IBUTTON;

						HAL_Delay(10000); // делаем паузу

			  		}

					else if( (status_registers.security_status_reg == ENABLED_BY_IBUTTON) || (status_registers.security_status_reg == ENABLED_BY_SERVER) || ( status_registers.security_status_reg == DOOR_OPEN_ALARM ) || ( status_registers.security_status_reg == ARMING_ERROR ) || ( status_registers.security_status_reg == DOOR_OPEN_POWER_OFF) ) // если сигнализация включена, снимаем с охраны
			  		{

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*IBUTTON_COMPLETE_0_REG, 0x00);
						fm25v02_write(2*IBUTTON_COMPLETE_0_REG+1, ibutton_temp[0]);
						fm25v02_write(2*IBUTTON_COMPLETE_1_REG, 0x00);
						fm25v02_write(2*IBUTTON_COMPLETE_1_REG+1, ibutton_temp[1]);
						fm25v02_write(2*IBUTTON_COMPLETE_2_REG, 0x00);
						fm25v02_write(2*IBUTTON_COMPLETE_2_REG+1, ibutton_temp[2]);
						fm25v02_write(2*IBUTTON_COMPLETE_3_REG, 0x00);
						fm25v02_write(2*IBUTTON_COMPLETE_3_REG+1, ibutton_temp[3]);
						fm25v02_write(2*IBUTTON_COMPLETE_4_REG, 0x00);
						fm25v02_write(2*IBUTTON_COMPLETE_4_REG+1, ibutton_temp[4]);
						fm25v02_write(2*IBUTTON_COMPLETE_5_REG, 0x00);
						fm25v02_write(2*IBUTTON_COMPLETE_5_REG+1, ibutton_temp[5]);
						fm25v02_write(2*IBUTTON_COMPLETE_6_REG, 0x00);
						fm25v02_write(2*IBUTTON_COMPLETE_6_REG+1, ibutton_temp[6]);
						fm25v02_write(2*IBUTTON_COMPLETE_7_REG, 0x00);
						fm25v02_write(2*IBUTTON_COMPLETE_7_REG+1, ibutton_temp[7]);
						osMutexRelease(Fm25v02MutexHandle);

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*SECURITY_CONTROL_REG, 0x00); // запускаем процесс постановки на охрану
						fm25v02_write(2*SECURITY_CONTROL_REG+1, DISABLE_FROM_IBUTTON);
						osMutexRelease(Fm25v02MutexHandle);

						control_registers.security_control_reg = DISABLE_FROM_IBUTTON;

						HAL_Delay(10000);

			  		}

				}
			}


		}

		osDelay(10);
	}
}
//------------------------------------------------------------


