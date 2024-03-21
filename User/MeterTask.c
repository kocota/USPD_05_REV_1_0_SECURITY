#include "cmsis_os.h"
#include "MeterTask.h"
#include "ce303.h"
#include "modbus.h"
#include "fm25v02.h"

extern osMutexId Fm25v02MutexHandle;
extern osSemaphoreId RS485TransmissionStateHandle;
extern control_register_struct control_registers;

extern uint8_t start_buf[6];

uint8_t meter_temp;

uint8_t meter_id;


void ThreadMeterTask(void const * argument)
{


	osSemaphoreWait(RS485TransmissionStateHandle, osWaitForever); // обнуляем семафор, при создании семафора его значение равно 1

	osMutexWait(Fm25v02MutexHandle, osWaitForever); // тестово обнуляем регистр ошибки опроса счетчика
	fm25v02_write(2*CE_303_ERROR_REG, 0x00);
	fm25v02_write(2*CE_303_ERROR_REG+1, 0x01);
	osMutexRelease(Fm25v02MutexHandle);


	for(;;)
	{
		if(control_registers.meter_polling_reg == 1)
		{
			osMutexWait(Fm25v02MutexHandle, osWaitForever);
			fm25v02_read(2*METER_ID_LOW_REG+1, &meter_temp); // вычитываем значение регистра номера счетчика и записываем его в переменную буфера.

			osMutexRelease(Fm25v02MutexHandle);

			if(meter_temp != meter_id)
			{
				meter_id = meter_temp;

				osMutexWait(Fm25v02MutexHandle, osWaitForever);
				fm25v02_write(2*CE_303_ERROR_REG, 0x00);
				fm25v02_write(2*CE_303_ERROR_REG+1, 0x01);
				osMutexRelease(Fm25v02MutexHandle);

			}

			ce303_voltage(meter_temp); // читаем напряжение
			ce303_current(meter_temp); // читаем ток
			ce303_power(meter_temp); // читаем мощность
			ce303_tarif(meter_temp); // читаем тарифы

			osMutexWait(Fm25v02MutexHandle, osWaitForever);
			fm25v02_read(2*METER_ID_LOW_REG+1, &meter_temp);
			osMutexRelease(Fm25v02MutexHandle);

			if(meter_temp == meter_id)
			{
				osMutexWait(Fm25v02MutexHandle, osWaitForever);
				fm25v02_write(2*CE_303_ERROR_REG, 0x00);
				fm25v02_write(2*CE_303_ERROR_REG+1, 0x00);
				osMutexRelease(Fm25v02MutexHandle);
			}
			else
			{
				osMutexWait(Fm25v02MutexHandle, osWaitForever);
				fm25v02_write(2*CE_303_ERROR_REG, 0x00);
				fm25v02_write(2*CE_303_ERROR_REG+1, 0x01);
				osMutexRelease(Fm25v02MutexHandle);
			}

		}


		osDelay(2000);
	}
}
