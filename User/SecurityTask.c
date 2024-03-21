#include "SecurityTask.h"
#include "cmsis_os.h"
#include "fm25v02.h"
#include "gpio.h"
#include "modbus.h"


extern osMutexId Fm25v02MutexHandle;
extern osThreadId EventWriteTaskHandle;

extern status_register_struct status_registers;
extern control_register_struct control_registers;

uint8_t button_state1=0;
uint8_t button_state2=0;
uint8_t button_state3=0;
uint8_t button_state4=0;
uint8_t button_state5=0;
uint8_t button_state6=0;
uint8_t button_state7=0;
uint8_t button_state8=0;

uint8_t loop_state1_on=0;
uint8_t loop_state1_off=0;
uint8_t loop_state2_on=0;
uint8_t loop_state2_off=0;
uint8_t loop_state3_on=0;
uint8_t loop_state3_off=0;
uint8_t loop_state4_on=0;
uint8_t loop_state4_off=0;
uint8_t loop_state5_on=0;
uint8_t loop_state5_off=0;
uint8_t loop_state6_on=0;
uint8_t loop_state6_off=0;
uint8_t loop_state7_on=0;
uint8_t loop_state7_off=0;
uint8_t loop_state8_on=0;
uint8_t loop_state8_off=0;


void ThreadSecurityTask(void const * argument)
{
	uint8_t alarm_loop_reg_temp;
	uint8_t status_loop_reg_temp;


	osMutexWait(Fm25v02MutexHandle, osWaitForever); // обнуляем регистр статуса освещения и переменную регитра статуса освещения
	fm25v02_write(2*LIGHTING_STATUS_REG, 0x00);
	fm25v02_write(2*LIGHTING_STATUS_REG+1, 0x00);
	status_registers.lighting_status_reg = 0x0000;
	osMutexRelease(Fm25v02MutexHandle);

	osDelay(5000);


	for(;;)
	{

		//----Контроль статуса шлейфа №1--------------------------------------------------------------------------------------------------------------------------------
		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4) == GPIO_PIN_RESET)
		{
			loop_state1_off = 0;

			if(loop_state1_on<10)
			{
				loop_state1_on++;
				if(loop_state1_on==10)
				{

					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_read(2*STATUS_LOOP_REG+1, &status_loop_reg_temp);
					osMutexRelease(Fm25v02MutexHandle);

					if( (status_loop_reg_temp&0x01) == 0x00 )
					{

						status_loop_reg_temp = status_loop_reg_temp|0x01;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*STATUS_LOOP_REG, 0x00);
						fm25v02_write(2*STATUS_LOOP_REG+1, status_loop_reg_temp);
						osMutexRelease(Fm25v02MutexHandle);

						status_registers.status_loop_reg = status_registers.status_loop_reg|0x01;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*GPRS_CALL_REG, 0x00);
						fm25v02_write(2*GPRS_CALL_REG+1, CALL_ON);
						osMutexRelease(Fm25v02MutexHandle);

					}

				}
			}

		}
		else if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4) == GPIO_PIN_SET)
		{
			loop_state1_on = 0;

			if(loop_state1_off<10)
			{
				loop_state1_off++;
				if(loop_state1_off==10)
				{
					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_read(2*STATUS_LOOP_REG+1, &status_loop_reg_temp);
					osMutexRelease(Fm25v02MutexHandle);

					if( (status_loop_reg_temp&0x01) == 0x01 )
					{

						status_loop_reg_temp = status_loop_reg_temp&0xFE;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*STATUS_LOOP_REG, 0x00);
						fm25v02_write(2*STATUS_LOOP_REG+1, status_loop_reg_temp);
						osMutexRelease(Fm25v02MutexHandle);

						status_registers.status_loop_reg = status_registers.status_loop_reg&0xFE;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*GPRS_CALL_REG, 0x00);
						fm25v02_write(2*GPRS_CALL_REG+1, CALL_ON);
						osMutexRelease(Fm25v02MutexHandle);

					}
				}

			}

		}
		//--------------------------------------------------------------------------------------------------------------------------------------------------

		//----Контроль статуса шлейфа №2--------------------------------------------------------------------------------------------------------------------------------
		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5) == GPIO_PIN_RESET)
		{
			loop_state2_off = 0;

			if(loop_state2_on<10)
			{
				loop_state2_on++;
				if(loop_state2_on==10)
				{

					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_read(2*STATUS_LOOP_REG+1, &status_loop_reg_temp);
					osMutexRelease(Fm25v02MutexHandle);

					if( (status_loop_reg_temp&0x02) == 0x00 )
					{

						status_loop_reg_temp = status_loop_reg_temp|0x02;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*STATUS_LOOP_REG, 0x00);
						fm25v02_write(2*STATUS_LOOP_REG+1, status_loop_reg_temp);
						osMutexRelease(Fm25v02MutexHandle);

						status_registers.status_loop_reg = status_registers.status_loop_reg|0x02;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*GPRS_CALL_REG, 0x00);
						fm25v02_write(2*GPRS_CALL_REG+1, CALL_ON);
						osMutexRelease(Fm25v02MutexHandle);

					}

				}
			}

		}
		else if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5) == GPIO_PIN_SET)
		{
			loop_state2_on = 0;

			if(loop_state2_off<10)
			{
				loop_state2_off++;
				if(loop_state2_off==10)
				{
					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_read(2*STATUS_LOOP_REG+1, &status_loop_reg_temp);
					osMutexRelease(Fm25v02MutexHandle);

					if( (status_loop_reg_temp&0x02) == 0x02 )
					{

						status_loop_reg_temp = status_loop_reg_temp&0xFD;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*STATUS_LOOP_REG, 0x00);
						fm25v02_write(2*STATUS_LOOP_REG+1, status_loop_reg_temp);
						osMutexRelease(Fm25v02MutexHandle);

						status_registers.status_loop_reg = status_registers.status_loop_reg&0xFD;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*GPRS_CALL_REG, 0x00);
						fm25v02_write(2*GPRS_CALL_REG+1, CALL_ON);
						osMutexRelease(Fm25v02MutexHandle);

					}
				}

			}

		}
		//--------------------------------------------------------------------------------------------------------------------------------------------------

		//----Контроль статуса шлейфа №3--------------------------------------------------------------------------------------------------------------------------------
		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6) == GPIO_PIN_RESET)
		{
			loop_state3_off = 0;

			if(loop_state3_on<10)
			{
				loop_state3_on++;
				if(loop_state3_on==10)
				{

					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_read(2*STATUS_LOOP_REG+1, &status_loop_reg_temp);
					osMutexRelease(Fm25v02MutexHandle);

					if( (status_loop_reg_temp&0x04) == 0x00 )
					{

						status_loop_reg_temp = status_loop_reg_temp|0x04;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*STATUS_LOOP_REG, 0x00);
						fm25v02_write(2*STATUS_LOOP_REG+1, status_loop_reg_temp);
						osMutexRelease(Fm25v02MutexHandle);

						status_registers.status_loop_reg = status_registers.status_loop_reg|0x04;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*GPRS_CALL_REG, 0x00);
						fm25v02_write(2*GPRS_CALL_REG+1, CALL_ON);
						osMutexRelease(Fm25v02MutexHandle);

					}

				}
			}

		}
		else if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6) == GPIO_PIN_SET)
		{
			loop_state3_on = 0;

			if(loop_state3_off<10)
			{
				loop_state3_off++;
				if(loop_state3_off==10)
				{
					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_read(2*STATUS_LOOP_REG+1, &status_loop_reg_temp);
					osMutexRelease(Fm25v02MutexHandle);

					if( (status_loop_reg_temp&0x04) == 0x04 )
					{

						status_loop_reg_temp = status_loop_reg_temp&0xFB;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*STATUS_LOOP_REG, 0x00);
						fm25v02_write(2*STATUS_LOOP_REG+1, status_loop_reg_temp);
						osMutexRelease(Fm25v02MutexHandle);

						status_registers.status_loop_reg = status_registers.status_loop_reg&0xFB;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*GPRS_CALL_REG, 0x00);
						fm25v02_write(2*GPRS_CALL_REG+1, CALL_ON);
						osMutexRelease(Fm25v02MutexHandle);

					}
				}

			}

		}
		//--------------------------------------------------------------------------------------------------------------------------------------------------

		//----Контроль статуса шлейфа №4--------------------------------------------------------------------------------------------------------------------------------
		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7) == GPIO_PIN_RESET)
		{
			loop_state4_off = 0;

			if(loop_state4_on<10)
			{
				loop_state4_on++;
				if(loop_state4_on==10)
				{

					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_read(2*STATUS_LOOP_REG+1, &status_loop_reg_temp);
					osMutexRelease(Fm25v02MutexHandle);

					if( (status_loop_reg_temp&0x08) == 0x00 )
					{

						status_loop_reg_temp = status_loop_reg_temp|0x08;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*STATUS_LOOP_REG, 0x00);
						fm25v02_write(2*STATUS_LOOP_REG+1, status_loop_reg_temp);
						osMutexRelease(Fm25v02MutexHandle);

						status_registers.status_loop_reg = status_registers.status_loop_reg|0x08;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*GPRS_CALL_REG, 0x00);
						fm25v02_write(2*GPRS_CALL_REG+1, CALL_ON);
						osMutexRelease(Fm25v02MutexHandle);

					}

				}
			}

		}
		else if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7) == GPIO_PIN_SET)
		{
			loop_state4_on = 0;

			if(loop_state4_off<10)
			{
				loop_state4_off++;
				if(loop_state4_off==10)
				{
					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_read(2*STATUS_LOOP_REG+1, &status_loop_reg_temp);
					osMutexRelease(Fm25v02MutexHandle);

					if( (status_loop_reg_temp&0x08) == 0x08 )
					{

						status_loop_reg_temp = status_loop_reg_temp&0xF7;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*STATUS_LOOP_REG, 0x00);
						fm25v02_write(2*STATUS_LOOP_REG+1, status_loop_reg_temp);
						osMutexRelease(Fm25v02MutexHandle);

						status_registers.status_loop_reg = status_registers.status_loop_reg&0xF7;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*GPRS_CALL_REG, 0x00);
						fm25v02_write(2*GPRS_CALL_REG+1, CALL_ON);
						osMutexRelease(Fm25v02MutexHandle);

					}
				}

			}

		}
		//--------------------------------------------------------------------------------------------------------------------------------------------------

		//----Контроль статуса шлейфа №5--------------------------------------------------------------------------------------------------------------------------------
		if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4) == GPIO_PIN_RESET)
		{
			loop_state5_off = 0;

			if(loop_state5_on<10)
			{
				loop_state5_on++;
				if(loop_state5_on==10)
				{

					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_read(2*STATUS_LOOP_REG+1, &status_loop_reg_temp);
					osMutexRelease(Fm25v02MutexHandle);

					if( (status_loop_reg_temp&0x10) == 0x00 )
					{

						status_loop_reg_temp = status_loop_reg_temp|0x10;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*STATUS_LOOP_REG, 0x00);
						fm25v02_write(2*STATUS_LOOP_REG+1, status_loop_reg_temp);
						osMutexRelease(Fm25v02MutexHandle);

						status_registers.status_loop_reg = status_registers.status_loop_reg|0x10;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*GPRS_CALL_REG, 0x00);
						fm25v02_write(2*GPRS_CALL_REG+1, CALL_ON);
						osMutexRelease(Fm25v02MutexHandle);

					}

				}
			}

		}
		else if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4) == GPIO_PIN_SET)
		{
			loop_state5_on = 0;

			if(loop_state5_off<10)
			{
				loop_state5_off++;
				if(loop_state5_off==10)
				{
					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_read(2*STATUS_LOOP_REG+1, &status_loop_reg_temp);
					osMutexRelease(Fm25v02MutexHandle);

					if( (status_loop_reg_temp&0x10) == 0x10 )
					{

						status_loop_reg_temp = status_loop_reg_temp&0xEF;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*STATUS_LOOP_REG, 0x00);
						fm25v02_write(2*STATUS_LOOP_REG+1, status_loop_reg_temp);
						osMutexRelease(Fm25v02MutexHandle);

						status_registers.status_loop_reg = status_registers.status_loop_reg&0xEF;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*GPRS_CALL_REG, 0x00);
						fm25v02_write(2*GPRS_CALL_REG+1, CALL_ON);
						osMutexRelease(Fm25v02MutexHandle);

					}
				}

			}

		}
		//--------------------------------------------------------------------------------------------------------------------------------------------------

		//----Контроль статуса шлейфа №6--------------------------------------------------------------------------------------------------------------------------------
		if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5) == GPIO_PIN_RESET)
		{
			loop_state6_off = 0;

			if(loop_state6_on<10)
			{
				loop_state6_on++;
				if(loop_state6_on==10)
				{

					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_read(2*STATUS_LOOP_REG+1, &status_loop_reg_temp);
					osMutexRelease(Fm25v02MutexHandle);

					if( (status_loop_reg_temp&0x20) == 0x00 )
					{

						status_loop_reg_temp = status_loop_reg_temp|0x20;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*STATUS_LOOP_REG, 0x00);
						fm25v02_write(2*STATUS_LOOP_REG+1, status_loop_reg_temp);
						osMutexRelease(Fm25v02MutexHandle);

						status_registers.status_loop_reg = status_registers.status_loop_reg|0x20;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*GPRS_CALL_REG, 0x00);
						fm25v02_write(2*GPRS_CALL_REG+1, CALL_ON);
						osMutexRelease(Fm25v02MutexHandle);

					}

				}
			}

		}
		else if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5) == GPIO_PIN_SET)
		{
			loop_state6_on = 0;

			if(loop_state6_off<10)
			{
				loop_state6_off++;
				if(loop_state6_off==10)
				{
					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_read(2*STATUS_LOOP_REG+1, &status_loop_reg_temp);
					osMutexRelease(Fm25v02MutexHandle);

					if( (status_loop_reg_temp&0x20) == 0x20 )
					{

						status_loop_reg_temp = status_loop_reg_temp&0xDF;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*STATUS_LOOP_REG, 0x00);
						fm25v02_write(2*STATUS_LOOP_REG+1, status_loop_reg_temp);
						osMutexRelease(Fm25v02MutexHandle);

						status_registers.status_loop_reg = status_registers.status_loop_reg&0xDF;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*GPRS_CALL_REG, 0x00);
						fm25v02_write(2*GPRS_CALL_REG+1, CALL_ON);
						osMutexRelease(Fm25v02MutexHandle);

					}
				}

			}

		}
		//--------------------------------------------------------------------------------------------------------------------------------------------------

		//----Контроль статуса шлейфа №7--------------------------------------------------------------------------------------------------------------------------------
		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == GPIO_PIN_RESET)
		{
			loop_state7_off = 0;

			if(loop_state7_on<10)
			{
				loop_state7_on++;
				if(loop_state7_on==10)
				{

					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_read(2*STATUS_LOOP_REG+1, &status_loop_reg_temp);
					osMutexRelease(Fm25v02MutexHandle);

					if( (status_loop_reg_temp&0x40) == 0x00 )
					{

						status_loop_reg_temp = status_loop_reg_temp|0x40;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*STATUS_LOOP_REG, 0x00);
						fm25v02_write(2*STATUS_LOOP_REG+1, status_loop_reg_temp);
						osMutexRelease(Fm25v02MutexHandle);

						status_registers.status_loop_reg = status_registers.status_loop_reg|0x40;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*GPRS_CALL_REG, 0x00);
						fm25v02_write(2*GPRS_CALL_REG+1, CALL_ON);
						osMutexRelease(Fm25v02MutexHandle);

					}

				}
			}

		}
		else if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == GPIO_PIN_SET)
		{
			loop_state7_on = 0;

			if(loop_state7_off<10)
			{
				loop_state7_off++;
				if(loop_state7_off==10)
				{
					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_read(2*STATUS_LOOP_REG+1, &status_loop_reg_temp);
					osMutexRelease(Fm25v02MutexHandle);

					if( (status_loop_reg_temp&0x40) == 0x40 )
					{

						status_loop_reg_temp = status_loop_reg_temp&0xBF;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*STATUS_LOOP_REG, 0x00);
						fm25v02_write(2*STATUS_LOOP_REG+1, status_loop_reg_temp);
						osMutexRelease(Fm25v02MutexHandle);

						status_registers.status_loop_reg = status_registers.status_loop_reg&0xBF;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*GPRS_CALL_REG, 0x00);
						fm25v02_write(2*GPRS_CALL_REG+1, CALL_ON);
						osMutexRelease(Fm25v02MutexHandle);

					}
				}

			}

		}
		//--------------------------------------------------------------------------------------------------------------------------------------------------

		//----Контроль статуса шлейфа №8--------------------------------------------------------------------------------------------------------------------------------
		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1) == GPIO_PIN_RESET)
		{
			loop_state8_off = 0;

			if(loop_state8_on<10)
			{
				loop_state8_on++;
				if(loop_state8_on==10)
				{

					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_read(2*STATUS_LOOP_REG+1, &status_loop_reg_temp);
					osMutexRelease(Fm25v02MutexHandle);

					if( (status_loop_reg_temp&0x80) == 0x00 )
					{

						status_loop_reg_temp = status_loop_reg_temp|0x80;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*STATUS_LOOP_REG, 0x00);
						fm25v02_write(2*STATUS_LOOP_REG+1, status_loop_reg_temp);
						osMutexRelease(Fm25v02MutexHandle);

						status_registers.status_loop_reg = status_registers.status_loop_reg|0x80;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*GPRS_CALL_REG, 0x00);
						fm25v02_write(2*GPRS_CALL_REG+1, CALL_ON);
						osMutexRelease(Fm25v02MutexHandle);

					}

				}
			}

		}
		else if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1) == GPIO_PIN_SET)
		{
			loop_state8_on = 0;

			if(loop_state8_off<10)
			{
				loop_state8_off++;
				if(loop_state8_off==10)
				{
					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_read(2*STATUS_LOOP_REG+1, &status_loop_reg_temp);
					osMutexRelease(Fm25v02MutexHandle);

					if( (status_loop_reg_temp&0x80) == 0x80 )
					{

						status_loop_reg_temp = status_loop_reg_temp&0x7F;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*STATUS_LOOP_REG, 0x00);
						fm25v02_write(2*STATUS_LOOP_REG+1, status_loop_reg_temp);
						osMutexRelease(Fm25v02MutexHandle);

						status_registers.status_loop_reg = status_registers.status_loop_reg&0x7F;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*GPRS_CALL_REG, 0x00);
						fm25v02_write(2*GPRS_CALL_REG+1, CALL_ON);
						osMutexRelease(Fm25v02MutexHandle);

					}
				}

			}

		}
		//--------------------------------------------------------------------------------------------------------------------------------------------------



		if( (status_registers.security_status_reg == ENABLED_BY_IBUTTON) || (status_registers.security_status_reg == ENABLED_BY_SERVER) && (status_registers.power_on_reg == 1) ) // если основное питание есть и режим охраны включен таблеткой или из центра
		{

			//----Контроль шлейфа №1--------------------------------------------------------------------------------------------------------------------------------
			if( (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4) == GPIO_PIN_RESET) && ( (control_registers.control_loop_reg&0x01) != 0x00 ) )
			{
				if(button_state1<10)
				{
					button_state1++;
					if(button_state1==10)
					{
						if(control_registers.mute_reg == MUTE_OFF)
						{
							BUZ_ON();
						}

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_read(2*ALARM_LOOP_REG+1, &alarm_loop_reg_temp);
						osMutexRelease(Fm25v02MutexHandle);

						alarm_loop_reg_temp = alarm_loop_reg_temp|0x01;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*ALARM_LOOP_REG, 0x00);
						fm25v02_write(2*ALARM_LOOP_REG+1, alarm_loop_reg_temp);
						osMutexRelease(Fm25v02MutexHandle);

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*SECURITY_STATUS_REG, 0x00);
						fm25v02_write(2*SECURITY_STATUS_REG+1, DOOR_OPEN_ALARM);
						osMutexRelease(Fm25v02MutexHandle);

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*SYSTEM_STATUS_REG, 0x00);
						fm25v02_write(2*SYSTEM_STATUS_REG+1, ALARM_STATE);
						status_registers.system_status_reg = ALARM_STATE;
						osMutexRelease(Fm25v02MutexHandle);

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*GPRS_CALL_REG, 0x00);
						fm25v02_write(2*GPRS_CALL_REG+1, CALL_ON);
						osMutexRelease(Fm25v02MutexHandle);

						osThreadResume(EventWriteTaskHandle);

					}
				}

			}
			else if ( (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4) == GPIO_PIN_SET) && ( (control_registers.control_loop_reg&0x01) != 0x00 ) )
			{
				if(button_state1>0)
				{
					button_state1 = 0;
					//LED5_OFF();

				}

			}
			//--------------------------------------------------------------------------------------------------------------------------------------------------

			//----Контроль шлейфа №2--------------------------------------------------------------------------------------------------------------------------------
			if( (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5) == GPIO_PIN_RESET) && ( (control_registers.control_loop_reg&0x02) != 0x00 ) )
			{
				if(button_state2<10)
				{
					button_state2++;
					if(button_state2==10)
					{
						if(control_registers.mute_reg == MUTE_OFF)
						{
							BUZ_ON();
						}

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_read(2*ALARM_LOOP_REG+1, &alarm_loop_reg_temp);
						osMutexRelease(Fm25v02MutexHandle);

						alarm_loop_reg_temp = alarm_loop_reg_temp|0x02;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*ALARM_LOOP_REG, 0x00);
						fm25v02_write(2*ALARM_LOOP_REG+1, alarm_loop_reg_temp);
						osMutexRelease(Fm25v02MutexHandle);

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*SECURITY_STATUS_REG, 0x00);
						fm25v02_write(2*SECURITY_STATUS_REG+1, DOOR_OPEN_ALARM);
						osMutexRelease(Fm25v02MutexHandle);

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*SYSTEM_STATUS_REG, 0x00);
						fm25v02_write(2*SYSTEM_STATUS_REG+1, ALARM_STATE);
						status_registers.system_status_reg = ALARM_STATE;
						osMutexRelease(Fm25v02MutexHandle);

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*GPRS_CALL_REG, 0x00);
						fm25v02_write(2*GPRS_CALL_REG+1, CALL_ON);
						osMutexRelease(Fm25v02MutexHandle);

						osThreadResume(EventWriteTaskHandle);

					}
				}

			}
			else if ( (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5) == GPIO_PIN_SET) && ( (control_registers.control_loop_reg&0x02) != 0x00 ) )
			{
				if(button_state2>0)
				{
					button_state2 = 0;
					//LED5_OFF();

				}

			}
			//--------------------------------------------------------------------------------------------------------------------------------------------------

			//----Контроль шлейфа №3--------------------------------------------------------------------------------------------------------------------------------
			if( (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6) == GPIO_PIN_RESET) && ( (control_registers.control_loop_reg&0x04) != 0x00 ) )
			{
				if(button_state3<10)
				{
					button_state3++;
					if(button_state3==10)
					{
						if(control_registers.mute_reg == MUTE_OFF)
						{
							BUZ_ON();
						}

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_read(2*ALARM_LOOP_REG+1, &alarm_loop_reg_temp);
						osMutexRelease(Fm25v02MutexHandle);

						alarm_loop_reg_temp = alarm_loop_reg_temp|0x04;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*ALARM_LOOP_REG, 0x00);
						fm25v02_write(2*ALARM_LOOP_REG+1, alarm_loop_reg_temp);
						osMutexRelease(Fm25v02MutexHandle);

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*SECURITY_STATUS_REG, 0x00);
						fm25v02_write(2*SECURITY_STATUS_REG+1, DOOR_OPEN_ALARM);
						osMutexRelease(Fm25v02MutexHandle);

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*SYSTEM_STATUS_REG, 0x00);
						fm25v02_write(2*SYSTEM_STATUS_REG+1, ALARM_STATE);
						status_registers.system_status_reg = ALARM_STATE;
						osMutexRelease(Fm25v02MutexHandle);

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*GPRS_CALL_REG, 0x00);
						fm25v02_write(2*GPRS_CALL_REG+1, CALL_ON);
						osMutexRelease(Fm25v02MutexHandle);

						osThreadResume(EventWriteTaskHandle);

					}
				}

			}
			else if ( (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6) == GPIO_PIN_SET) && ( (control_registers.control_loop_reg&0x04) != 0x00 ) )
			{
				if(button_state3>0)
				{
					button_state3 = 0;
					//LED5_OFF();

				}

			}
			//--------------------------------------------------------------------------------------------------------------------------------------------------

			//----Контроль шлейфа №4--------------------------------------------------------------------------------------------------------------------------------
			if( (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7) == GPIO_PIN_RESET) && ( (control_registers.control_loop_reg&0x08) != 0x00 ) )
			{
				if(button_state4<10)
				{
					button_state4++;
					if(button_state4==10)
					{
						if(control_registers.mute_reg == MUTE_OFF)
						{
							BUZ_ON();
						}

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_read(2*ALARM_LOOP_REG+1, &alarm_loop_reg_temp);
						osMutexRelease(Fm25v02MutexHandle);

						alarm_loop_reg_temp = alarm_loop_reg_temp|0x08;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*ALARM_LOOP_REG, 0x00);
						fm25v02_write(2*ALARM_LOOP_REG+1, alarm_loop_reg_temp);
						osMutexRelease(Fm25v02MutexHandle);

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*SECURITY_STATUS_REG, 0x00);
						fm25v02_write(2*SECURITY_STATUS_REG+1, DOOR_OPEN_ALARM);
						osMutexRelease(Fm25v02MutexHandle);

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*SYSTEM_STATUS_REG, 0x00);
						fm25v02_write(2*SYSTEM_STATUS_REG+1, ALARM_STATE);
						status_registers.system_status_reg = ALARM_STATE;
						osMutexRelease(Fm25v02MutexHandle);

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*GPRS_CALL_REG, 0x00);
						fm25v02_write(2*GPRS_CALL_REG+1, CALL_ON);
						osMutexRelease(Fm25v02MutexHandle);

						osThreadResume(EventWriteTaskHandle);

					}
				}

			}
			else if ( (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7) == GPIO_PIN_SET) && ( (control_registers.control_loop_reg&0x08) != 0x00 ) )
			{
				if(button_state4>0)
				{
					button_state4 = 0;
					//LED5_OFF();

				}

			}
			//--------------------------------------------------------------------------------------------------------------------------------------------------

			//----Контроль шлейфа №5--------------------------------------------------------------------------------------------------------------------------------
			if( (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4) == GPIO_PIN_RESET) && ( (control_registers.control_loop_reg&0x10) != 0x00 ) )
			{
				if(button_state5<10)
				{
					button_state5++;
					if(button_state5==10)
					{
						if(control_registers.mute_reg == MUTE_OFF)
						{
							BUZ_ON();
						}

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_read(2*ALARM_LOOP_REG+1, &alarm_loop_reg_temp);
						osMutexRelease(Fm25v02MutexHandle);

						alarm_loop_reg_temp = alarm_loop_reg_temp|0x10;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*ALARM_LOOP_REG, 0x00);
						fm25v02_write(2*ALARM_LOOP_REG+1, alarm_loop_reg_temp);
						osMutexRelease(Fm25v02MutexHandle);

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*SECURITY_STATUS_REG, 0x00);
						fm25v02_write(2*SECURITY_STATUS_REG+1, DOOR_OPEN_ALARM);
						osMutexRelease(Fm25v02MutexHandle);

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*SYSTEM_STATUS_REG, 0x00);
						fm25v02_write(2*SYSTEM_STATUS_REG+1, ALARM_STATE);
						status_registers.system_status_reg = ALARM_STATE;
						osMutexRelease(Fm25v02MutexHandle);

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*GPRS_CALL_REG, 0x00);
						fm25v02_write(2*GPRS_CALL_REG+1, CALL_ON);
						osMutexRelease(Fm25v02MutexHandle);

						osThreadResume(EventWriteTaskHandle);

					}
				}

			}
			else if ( (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4) == GPIO_PIN_SET) && ( (control_registers.control_loop_reg&0x10) != 0x00 ) )
			{
				if(button_state5>0)
				{
					button_state5 = 0;
					//LED5_OFF();

				}

			}
			//--------------------------------------------------------------------------------------------------------------------------------------------------

			//----Контроль шлейфа №6--------------------------------------------------------------------------------------------------------------------------------
			if( (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5) == GPIO_PIN_RESET) && ( (control_registers.control_loop_reg&0x20) != 0x00 ) )
			{
				if(button_state6<10)
				{
					button_state6++;
					if(button_state6==10)
					{
						if(control_registers.mute_reg == MUTE_OFF)
						{
							BUZ_ON();
						}

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_read(2*ALARM_LOOP_REG+1, &alarm_loop_reg_temp);
						osMutexRelease(Fm25v02MutexHandle);

						alarm_loop_reg_temp = alarm_loop_reg_temp|0x20;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*ALARM_LOOP_REG, 0x00);
						fm25v02_write(2*ALARM_LOOP_REG+1, alarm_loop_reg_temp);
						osMutexRelease(Fm25v02MutexHandle);

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*SECURITY_STATUS_REG, 0x00);
						fm25v02_write(2*SECURITY_STATUS_REG+1, DOOR_OPEN_ALARM);
						osMutexRelease(Fm25v02MutexHandle);

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*SYSTEM_STATUS_REG, 0x00);
						fm25v02_write(2*SYSTEM_STATUS_REG+1, ALARM_STATE);
						status_registers.system_status_reg = ALARM_STATE;
						osMutexRelease(Fm25v02MutexHandle);

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*GPRS_CALL_REG, 0x00);
						fm25v02_write(2*GPRS_CALL_REG+1, CALL_ON);
						osMutexRelease(Fm25v02MutexHandle);

						osThreadResume(EventWriteTaskHandle);

					}
				}

			}
			else if ( (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5) == GPIO_PIN_SET) && ( (control_registers.control_loop_reg&0x20) != 0x00 ) )
			{
				if(button_state6>0)
				{
					button_state6 == 0;
					//LED5_OFF();

				}

			}
			//--------------------------------------------------------------------------------------------------------------------------------------------------

			//----Контроль шлейфа №7--------------------------------------------------------------------------------------------------------------------------------
			if( (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == GPIO_PIN_RESET) && ( (control_registers.control_loop_reg&0x40) != 0x00 ) )
			{
				if(button_state7<10)
				{
					button_state7++;
					if(button_state7==10)
					{
						if(control_registers.mute_reg == MUTE_OFF)
						{
							BUZ_ON();
						}

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_read(2*ALARM_LOOP_REG+1, &alarm_loop_reg_temp);
						osMutexRelease(Fm25v02MutexHandle);

						alarm_loop_reg_temp = alarm_loop_reg_temp|0x40;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*ALARM_LOOP_REG, 0x00);
						fm25v02_write(2*ALARM_LOOP_REG+1, alarm_loop_reg_temp);
						osMutexRelease(Fm25v02MutexHandle);

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*SECURITY_STATUS_REG, 0x00);
						fm25v02_write(2*SECURITY_STATUS_REG+1, DOOR_OPEN_ALARM);
						osMutexRelease(Fm25v02MutexHandle);

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*SYSTEM_STATUS_REG, 0x00);
						fm25v02_write(2*SYSTEM_STATUS_REG+1, ALARM_STATE);
						status_registers.system_status_reg = ALARM_STATE;
						osMutexRelease(Fm25v02MutexHandle);

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*GPRS_CALL_REG, 0x00);
						fm25v02_write(2*GPRS_CALL_REG+1, CALL_ON);
						osMutexRelease(Fm25v02MutexHandle);

						osThreadResume(EventWriteTaskHandle);

					}
				}

			}
			else if ( (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == GPIO_PIN_SET) && ( (control_registers.control_loop_reg&0x40) != 0x00 ) )
			{
				if(button_state7>0)
				{
					button_state7 = 0;
					//LED5_OFF();

				}

			}
			//--------------------------------------------------------------------------------------------------------------------------------------------------

			//----Контроль шлейфа №8--------------------------------------------------------------------------------------------------------------------------------
			if( (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1) == GPIO_PIN_RESET) && ( (control_registers.control_loop_reg&0x80) != 0x00 ) )
			{
				if(button_state8<10)
				{
					button_state8++;
					if(button_state8==10)
					{
						if(control_registers.mute_reg == MUTE_OFF)
						{
							BUZ_ON();
						}

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_read(2*ALARM_LOOP_REG+1, &alarm_loop_reg_temp);
						osMutexRelease(Fm25v02MutexHandle);

						alarm_loop_reg_temp = alarm_loop_reg_temp|0x80;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*ALARM_LOOP_REG, 0x00);
						fm25v02_write(2*ALARM_LOOP_REG+1, alarm_loop_reg_temp);
						osMutexRelease(Fm25v02MutexHandle);

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*SECURITY_STATUS_REG, 0x00);
						fm25v02_write(2*SECURITY_STATUS_REG+1, DOOR_OPEN_ALARM);
						osMutexRelease(Fm25v02MutexHandle);

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*SYSTEM_STATUS_REG, 0x00);
						fm25v02_write(2*SYSTEM_STATUS_REG+1, ALARM_STATE);
						status_registers.system_status_reg = ALARM_STATE;
						osMutexRelease(Fm25v02MutexHandle);

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write(2*GPRS_CALL_REG, 0x00);
						fm25v02_write(2*GPRS_CALL_REG+1, CALL_ON);
						osMutexRelease(Fm25v02MutexHandle);

						osThreadResume(EventWriteTaskHandle);

					}
				}

			}
			else if ( (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1) == GPIO_PIN_SET) && ( (control_registers.control_loop_reg&0x80) != 0x00 ) )
			{
				if(button_state8>0)
				{
					button_state8 = 0;
					//LED5_OFF();

				}

			}
			//--------------------------------------------------------------------------------------------------------------------------------------------------



		}

		osDelay(10);

	}
}
