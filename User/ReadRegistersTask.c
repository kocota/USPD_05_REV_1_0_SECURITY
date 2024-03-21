#include "ReadRegistersTask.h"
#include "cmsis_os.h"
#include "modbus.h"
#include "fm25v02.h"

extern osThreadId M95TaskHandle;
extern osThreadId GetCurrentTaskHandle;
extern osThreadId MainTaskHandle;
//extern ADC_HandleTypeDef hadc1;
extern osThreadId LedTaskHandle;
extern osMutexId Fm25v02MutexHandle;
extern status_register_struct status_registers;
extern control_register_struct control_registers;


void ThreadReadRegistersTask(void const * argument)
{
	read_status_registers(); // вычитываем регистры
	read_control_registers();
	read_bootloader_registers();
	read_ibutton_registers();

	if(control_registers.arming_timeleft_reg < 100) // если время постановки на охрану больше 100 * 10мс
	{
		osMutexWait(Fm25v02MutexHandle, osWaitForever);
		fm25v02_write(2*ARMING_TIMELEFT, 0x00);
		fm25v02_write(2*ARMING_TIMELEFT+1, 0x64); // выставляем значение времени постановки на охрану равное 100 * 10мс
		osMutexRelease(Fm25v02MutexHandle);
	}

	osDelay(2000); // ждем пока будет получен статус фаз А1,А2,В1,В2,С1,С2
	osThreadResume(LedTaskHandle);  // запускаем процесс светодиодов
	osThreadResume(MainTaskHandle); // запускаем основной процесс
	osThreadResume(M95TaskHandle);  // запускаем процесс модема
	osDelay(1000); //ждем 1 секунду


	for(;;)
	{

		read_status_registers(); // вычитываем регистры
		read_control_registers();
		read_bootloader_registers();
		read_ibutton_registers();

		osDelay(1000); // ждем 1 секунду
	}
}
