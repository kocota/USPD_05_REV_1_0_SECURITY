#include "MainTask.h"
#include "modbus.h"
#include "cmsis_os.h"
#include "gpio.h"
#include "fm25v02.h"
#include "m95.h"

extern osThreadId M95TaskHandle;
extern osThreadId MainTaskHandle;
extern osThreadId EventWriteTaskHandle;
extern RTC_HandleTypeDef hrtc;
extern osMutexId Fm25v02MutexHandle;
extern status_register_struct status_registers;
extern control_register_struct control_registers;
extern bootloader_register_struct bootloader_registers;

volatile uint8_t modem_reset_state;

RTC_TimeTypeDef current_time;
RTC_DateTypeDef current_date;
RTC_TimeTypeDef set_time;
RTC_DateTypeDef set_date;

volatile uint8_t security_control_temp = 0;





void ThreadMainTask(void const * argument)
{


	osThreadSuspend(MainTaskHandle); // ждем пока не будут вычитаны регистры и не получен статус фаз А1,А2,В1,В2,С1,С2

	//osMutexWait(Fm25v02MutexHandle, osWaitForever);
	//fm25v02_write(2*READY_DOWNLOAD_REG, 0x00);
	//fm25v02_write(2*READY_DOWNLOAD_REG+1, 0x00);
	//bootloader_registers.ready_download_reg = 0x0000;
	//osMutexRelease(Fm25v02MutexHandle);


	for(;;)
	{

		if( HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_0) == GPIO_PIN_SET ) // проверяем если есть наличие единицы на пине PFO микросхемы TPS3306-15
		{
			if(status_registers.power_on_reg != 1)
			//if(status_registers.power_on_reg == 0) // если основного питания до этого не было, записываем в регистр наличия питания 1
			{
				osMutexWait(Fm25v02MutexHandle, osWaitForever);
				fm25v02_write(2*POWER_ON_REG, 0x00);
				fm25v02_write(2*POWER_ON_REG+1, 1);
				status_registers.power_on_reg = 1;
				osMutexRelease(Fm25v02MutexHandle);

				osMutexWait(Fm25v02MutexHandle, osWaitForever);
				fm25v02_write(2*GPRS_CALL_REG, 0x00);
				fm25v02_write(2*GPRS_CALL_REG+1, CALL_ON);
				osMutexRelease(Fm25v02MutexHandle);

				osMutexWait(Fm25v02MutexHandle, osWaitForever);
				fm25v02_write(2*SYSTEM_STATUS_REG, 0x00);
				fm25v02_write(2*SYSTEM_STATUS_REG+1, POWER_ON);
				status_registers.system_status_reg = POWER_ON;
				osMutexRelease(Fm25v02MutexHandle);

				osThreadResume(EventWriteTaskHandle);
			}
		}
		else // если на пине PFO микросхемы TPS3306-15 нет наличия единицы
		{
			if(status_registers.power_on_reg == 1)
			//if(status_registers.power_on_reg != 0)
			{
				osMutexWait(Fm25v02MutexHandle, osWaitForever);
				fm25v02_write(2*POWER_ON_REG, 0x00);
				fm25v02_write(2*POWER_ON_REG+1, 0x00);
				status_registers.power_on_reg = 0;
				osMutexRelease(Fm25v02MutexHandle);

				//osMutexWait(Fm25v02MutexHandle, osWaitForever);
				//fm25v02_write(2*GPRS_CALL_REG, 0x00);
				//fm25v02_write(2*GPRS_CALL_REG+1, CALL_ON);
				//osMutexRelease(Fm25v02MutexHandle);

				osMutexWait(Fm25v02MutexHandle, osWaitForever);
				fm25v02_write(2*SYSTEM_STATUS_REG, 0x00);
				fm25v02_write(2*SYSTEM_STATUS_REG+1, POWER_OFF);
				status_registers.system_status_reg = POWER_OFF;
				osMutexRelease(Fm25v02MutexHandle);

				//---- тест -------------------------------------------------
				if(status_registers.security_status_reg == DOOR_OPEN_ALARM)
				{
					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_write(2*SECURITY_STATUS_REG, 0x00);
					fm25v02_write(2*SECURITY_STATUS_REG+1, 0x08);
					status_registers.security_status_reg = 0x08;
					osMutexRelease(Fm25v02MutexHandle);
				}
				//-----------------------------------------------------------

				osMutexWait(Fm25v02MutexHandle, osWaitForever);
				fm25v02_write(2*GPRS_CALL_REG, 0x00);
				fm25v02_write(2*GPRS_CALL_REG+1, CALL_ON);
				osMutexRelease(Fm25v02MutexHandle);

				osThreadResume(EventWriteTaskHandle);
			}
		}

		switch(control_registers.security_control_reg) // проверяем значение переменной включения охранной сигнализации
		{

			case(DISABLE_FROM_SERVER):

				BUZ_OFF();

				osMutexWait(Fm25v02MutexHandle, osWaitForever);
				fm25v02_write(2*SECURITY_CONTROL_REG, 0x00);
				fm25v02_write(2*SECURITY_CONTROL_REG+1, SECURITY_CONTROL_DEFAULT);
				control_registers.security_control_reg = SECURITY_CONTROL_DEFAULT; // обновляем переменную
				fm25v02_write(2*SECURITY_STATUS_REG, 0x00);
				fm25v02_write(2*SECURITY_STATUS_REG+1, DISABLED_BY_SERVER);
				osMutexRelease(Fm25v02MutexHandle);

				//osMutexWait(Fm25v02MutexHandle, osWaitForever);
				//fm25v02_write(2*GPRS_CALL_REG, 0x00);
				//fm25v02_write(2*GPRS_CALL_REG+1, CALL_ON);
				//osMutexRelease(Fm25v02MutexHandle);

				osMutexWait(Fm25v02MutexHandle, osWaitForever);
				fm25v02_write(2*SYSTEM_STATUS_REG, 0x00);
				fm25v02_write(2*SYSTEM_STATUS_REG+1, TURN_OFF_STATE_ALARM);
				status_registers.system_status_reg = TURN_OFF_STATE_ALARM;
				osMutexRelease(Fm25v02MutexHandle);

				osMutexWait(Fm25v02MutexHandle, osWaitForever);
				fm25v02_write(2*GPRS_CALL_REG, 0x00);
				fm25v02_write(2*GPRS_CALL_REG+1, CALL_ON);
				osMutexRelease(Fm25v02MutexHandle);

				osThreadResume(EventWriteTaskHandle);

			break;

			case(ENABLE_FROM_SERVER): // если в регистр поступила команда включить из сервера

				BUZ_OFF();

				security_control_temp = ENABLED_BY_SERVER;

				osMutexWait(Fm25v02MutexHandle, osWaitForever);
				fm25v02_write(2*SECURITY_CONTROL_REG, 0x00);
				fm25v02_write(2*SECURITY_CONTROL_REG+1, SECURITY_CONTROL_DEFAULT);
				control_registers.security_control_reg = SECURITY_CONTROL_DEFAULT; // обновляем переменную
				fm25v02_write(2*SECURITY_STATUS_REG, 0x00);
				fm25v02_write(2*SECURITY_STATUS_REG+1, ARMING_PROCESS);
				osMutexRelease(Fm25v02MutexHandle);

			break;

			case(DISABLE_FROM_IBUTTON): // если поступила команда выключить из сервера или с таблетки

				osMutexWait(Fm25v02MutexHandle, osWaitForever);
				fm25v02_write(2*SECURITY_CONTROL_REG, 0x00);
				fm25v02_write(2*SECURITY_CONTROL_REG+1, SECURITY_CONTROL_DEFAULT);
				control_registers.security_control_reg = SECURITY_CONTROL_DEFAULT; // обновляем переменную
				fm25v02_write(2*SECURITY_STATUS_REG, 0x00);
				fm25v02_write(2*SECURITY_STATUS_REG+1, DISABLED_BY_IBUTTON);
				osMutexRelease(Fm25v02MutexHandle);

				//osMutexWait(Fm25v02MutexHandle, osWaitForever);
				//fm25v02_write(2*GPRS_CALL_REG, 0x00);
				//fm25v02_write(2*GPRS_CALL_REG+1, CALL_ON);
				//osMutexRelease(Fm25v02MutexHandle);

				osMutexWait(Fm25v02MutexHandle, osWaitForever);
				fm25v02_write(2*SYSTEM_STATUS_REG, 0x00);
				fm25v02_write(2*SYSTEM_STATUS_REG+1, TURN_OFF_STATE_ALARM);
				status_registers.system_status_reg = TURN_OFF_STATE_ALARM;
				osMutexRelease(Fm25v02MutexHandle);

				osMutexWait(Fm25v02MutexHandle, osWaitForever);
				fm25v02_write(2*GPRS_CALL_REG, 0x00);
				fm25v02_write(2*GPRS_CALL_REG+1, CALL_ON);
				osMutexRelease(Fm25v02MutexHandle);

				osThreadResume(EventWriteTaskHandle);

			break;

			case(ENABLE_FROM_IBUTTON): // если поступила команда включить с таблетки

				security_control_temp = ENABLED_BY_IBUTTON;

				osMutexWait(Fm25v02MutexHandle, osWaitForever);
				fm25v02_write(2*SECURITY_CONTROL_REG, 0x00);
				fm25v02_write(2*SECURITY_CONTROL_REG+1, SECURITY_CONTROL_DEFAULT);
				control_registers.security_control_reg = SECURITY_CONTROL_DEFAULT; // обновляем переменную
				fm25v02_write(2*SECURITY_STATUS_REG, 0x00);
				fm25v02_write(2*SECURITY_STATUS_REG+1, ARMING_PROCESS);
				osMutexRelease(Fm25v02MutexHandle);

			break;
		}

		switch(control_registers.time_update_reg) // проверяем значение переменной обновления времени
		{
			case(SET_TIME): // Если в регистр записана команда установить время

				osMutexWait(Fm25v02MutexHandle, osWaitForever);
				fm25v02_write(2*TIME_UPDATE_REG, 0x00);
				fm25v02_write(2*TIME_UPDATE_REG+1, SET_TIME_DEFAULT);
				osMutexRelease(Fm25v02MutexHandle);

				set_time.Hours = control_registers.time_hour_reg; // записываем в переменные структуры времени значения регистров управления временем
				set_time.Minutes = control_registers.time_minute_reg;
				set_time.Seconds = control_registers.time_seconds_reg;
				set_date.Date = control_registers.time_day_reg;
				set_date.Month = control_registers.time_month_reg;
				set_date.Year = control_registers.time_year_reg;
				set_date.WeekDay = control_registers.time_weekday_reg;

				set_time.Hours = RTC_ByteToBcd2(set_time.Hours); // переводим обычный формат времени в BCD
				set_time.Minutes = RTC_ByteToBcd2(set_time.Minutes);
				set_time.Seconds = RTC_ByteToBcd2(set_time.Seconds);
				set_date.Date = RTC_ByteToBcd2(set_date.Date);
				set_date.Month = RTC_ByteToBcd2(set_date.Month);
				set_date.Year = RTC_ByteToBcd2(set_date.Year);
				set_date.WeekDay = RTC_ByteToBcd2(set_date.WeekDay);

				HAL_RTC_SetTime(&hrtc, &set_time, RTC_FORMAT_BCD); // устанавливаем дату и время
				HAL_RTC_SetDate(&hrtc, &set_date, RTC_FORMAT_BCD);


			break;

			case(SET_TIME_DEFAULT): // Если в регистр не поступала команда установки времени

				HAL_RTC_GetTime(&hrtc, &current_time , RTC_FORMAT_BCD); // получаем значение даты и времени
				HAL_RTC_GetDate(&hrtc, &current_date , RTC_FORMAT_BCD);

				current_time.Hours = RTC_Bcd2ToByte(current_time.Hours); // переводим из BCD формата в обычный
				current_time.Minutes = RTC_Bcd2ToByte(current_time.Minutes);
				current_time.Seconds = RTC_Bcd2ToByte(current_time.Seconds);
				current_date.Date = RTC_Bcd2ToByte(current_date.Date);
				current_date.Month = RTC_Bcd2ToByte(current_date.Month);
				current_date.Year = RTC_Bcd2ToByte(current_date.Year);
				current_date.WeekDay = RTC_Bcd2ToByte(current_date.WeekDay);

				osMutexWait(Fm25v02MutexHandle, osWaitForever);

				fm25v02_write(2*TIME_CURRENT_HOUR_REG, 0x00); // записываем в регистры значения даты и времени
				fm25v02_write(2*TIME_CURRENT_HOUR_REG+1, current_time.Hours);
				fm25v02_write(2*TIME_CURRENT_MINUTE_REG, 0x00);
				fm25v02_write(2*TIME_CURRENT_MINUTE_REG+1, current_time.Minutes);
				fm25v02_write(2*TIME_CURRENT_SECOND_REG, 0x00);
				fm25v02_write(2*TIME_CURRENT_SECOND_REG+1, current_time.Seconds);
				fm25v02_write(2*TIME_CURRENT_DAY_REG, 0x00);
				fm25v02_write(2*TIME_CURRENT_DAY_REG+1, current_date.Date);
				fm25v02_write(2*TIME_CURRENT_MONTH_REG, 0x00);
				fm25v02_write(2*TIME_CURRENT_MONTH_REG+1, current_date.Month);
				fm25v02_write(2*TIME_CURRENT_YEAR_REG, 0x00);
				fm25v02_write(2*TIME_CURRENT_YEAR_REG+1, current_date.Year);
				fm25v02_write(2*TIME_CURRENT_WEEKDAY_REG, 0x00);
				fm25v02_write(2*TIME_CURRENT_WEEKDAY_REG+1, current_date.WeekDay);

				osMutexRelease(Fm25v02MutexHandle);

				status_registers.time_current_hour_reg = current_time.Hours;
				status_registers.time_current_minute_reg = current_time.Minutes;
				status_registers.time_current_second_reg = current_time.Seconds;
				status_registers.time_current_day_reg = current_date.Date;
				status_registers.time_current_month_reg = current_date.Month;
				status_registers.time_current_year_reg = current_date.Year;
				status_registers.time_current_weekday_reg = current_date.WeekDay;


			break;

		}

		switch(control_registers.reset_control_reg) // удаленная перезагрузка контроллера
		{
			case(1):
				osMutexWait(Fm25v02MutexHandle, osWaitForever);
				fm25v02_write(2*RESET_CONTROL_REG, 0);
				fm25v02_write(2*RESET_CONTROL_REG+1, 0);
				osMutexRelease(Fm25v02MutexHandle);
				NVIC_SystemReset();
			break;

		}

		switch(control_registers.alarm_loop_clear_reg) // сбросить сработавшие шлейфы
		{
			case(1):
				osMutexWait(Fm25v02MutexHandle, osWaitForever);
				fm25v02_write(2*ALARM_LOOP_CLEAR_REG, 0);
				fm25v02_write(2*ALARM_LOOP_CLEAR_REG+1, 0);
				fm25v02_write(2*ALARM_LOOP_REG, 0);
				fm25v02_write(2*ALARM_LOOP_REG+1, 0);
				osMutexRelease(Fm25v02MutexHandle);

				osMutexWait(Fm25v02MutexHandle, osWaitForever);
				fm25v02_write(2*GPRS_CALL_REG, 0x00);
				fm25v02_write(2*GPRS_CALL_REG+1, CALL_ON);
				osMutexRelease(Fm25v02MutexHandle);

				osThreadResume(EventWriteTaskHandle);

			break;

		}

		switch(control_registers.false_loop_clear_reg) // сбросить неисправные шлейфы
		{
			case(1):
				osMutexWait(Fm25v02MutexHandle, osWaitForever);
				fm25v02_write(2*FALSE_LOOP_CLEAR_REG, 0);
				fm25v02_write(2*FALSE_LOOP_CLEAR_REG+1, 0);
				fm25v02_write(2*ERROR_LOOP_REG, 0);
				fm25v02_write(2*ERROR_LOOP_REG+1, 0);
				osMutexRelease(Fm25v02MutexHandle);

				osMutexWait(Fm25v02MutexHandle, osWaitForever);
				fm25v02_write(2*GPRS_CALL_REG, 0x00);
				fm25v02_write(2*GPRS_CALL_REG+1, CALL_ON);
				osMutexRelease(Fm25v02MutexHandle);

				osThreadResume(EventWriteTaskHandle);


			break;

		}


		switch(control_registers.event_read_reg)
		{
			case(1):

				osMutexWait(Fm25v02MutexHandle, osWaitForever);
				fm25v02_write(2*EVENT_READ_REG, 0);
				fm25v02_write(2*EVENT_READ_REG+1, 0);
				fm25v02_write(2*ADDRESS_LAST_EVENT_H_REG, 0x00);
				fm25v02_write(2*ADDRESS_LAST_EVENT_H_REG+1, 0x20);
				fm25v02_write(2*ADDRESS_LAST_EVENT_L_REG, 0x00);
				fm25v02_write(2*ADDRESS_LAST_EVENT_L_REG+1, 0x00);
				osMutexRelease(Fm25v02MutexHandle);

			break;
		}

		switch(bootloader_registers.working_mode_reg)
		{
			case(1):

				NVIC_SystemReset();

			break;
		}

		if( modem_reset_state == 1)
		{
			osMutexWait(Fm25v02MutexHandle, osWaitForever); // ждем освобождение мьютекса записи в память
			osThreadSuspend(M95TaskHandle);
			modem_reset_state = 0;
			//AT_QPOWD(0);
			m95_power_off();
			HAL_Delay(5000);
			NVIC_SystemReset();
		}


		osDelay(500);
	}
}
