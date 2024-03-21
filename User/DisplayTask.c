#include "stm32f4xx_hal.h"
#include "DisplayTask.h"
#include "da04_11gwa.h"
#include "modbus.h"
#include "cmsis_os.h"
#include "fm25v02.h"

extern TIM_HandleTypeDef htim2;
extern SPI_HandleTypeDef hspi3;

extern status_register_struct status_registers;
extern control_register_struct control_registers;
extern ibutton_register_struct ibutton_registers;

extern osMutexId Fm25v02MutexHandle;

volatile uint16_t register_menu_state = 0;
volatile uint16_t register_content_menu_state = 0;

volatile uint8_t control_register_increment_state = 0;
volatile uint8_t control_register_decrement_state = 0;
volatile uint8_t control_register_save_state = 0;
volatile uint8_t control_register_temp_number = 0;


volatile uint16_t ibutton_temp_register;

uint16_t a=0;

uint32_t addr_test;

struct Struct1
{
	uint8_t a;
	uint8_t b;
	uint16_t c;


};

uint8_t spi_buf[4];

void ThreadDisplayTask(void const * argument)
{


	uint8_t ibutton_temp_reg_h;
	uint8_t ibutton_temp_reg_l;

	HAL_TIM_Base_Start_IT(&htim2);

	addr_test = IBUTTON1_BYTE_0_REG + ((B1-A1)/8)*16 + (B1-A1)%8 ;

	spi_buf[0] = 0xFF;
	spi_buf[1] = 0xFF;
	spi_buf[2] = 0xFF;
	spi_buf[3] = 0xFF;


	for(;;)
	{

		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_11, GPIO_PIN_RESET);
		HAL_Delay(100);
		while( HAL_SPI_Transmit(&hspi3, &spi_buf[0], 4, 100) != HAL_OK ){}
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_11, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_11, GPIO_PIN_RESET);


		a = (status_registers.security_status_reg)%10;

		if( register_content_menu_state == 0 )
		{

			if( register_menu_state == TIME )
			{
				hour_display((uint8_t)status_registers.time_current_hour_reg);
				minute_display((uint8_t)status_registers.time_current_minute_reg);
			}

			else
			{
				if( (register_menu_state <= MAX_P_NUMBER) && (register_menu_state > 0) )
				{
					status_register_display(register_menu_state);
				}
				else if( (register_menu_state > MAX_P_NUMBER) && (register_menu_state <= MAX_Y_NUMBER) )
				{
					control_register_display( (register_menu_state- MAX_P_NUMBER) );
				}
				else if( (register_menu_state > MAX_Y_NUMBER) && (register_menu_state <= MAX_A_NUMBER) )
				{
					ibutton_a_register_display( (register_menu_state- MAX_Y_NUMBER) );
				}
				else if( (register_menu_state > MAX_A_NUMBER) && (register_menu_state <= MAX_B_NUMBER) )
				{
					ibutton_b_register_display( (register_menu_state- MAX_A_NUMBER) );
				}
			}

		}
		else if( register_content_menu_state == 1)
		{
			if(register_menu_state == TIME)
			{
				register_content_menu_state = 0;
			}

			/*
			if(register_menu_state == P1)
			{
				number_display( status_registers.version_reg );
			}

			if(register_menu_state == P2)
			{
				number_display( (status_registers.version_reg>>8) );
			}

			if(register_menu_state == P3)
			{
				number_display( status_registers.security_status_reg );
			}

			if(register_menu_state == P4)
			{
				number_display( status_registers.status_loop_reg );
			}

			if(register_menu_state == P5)
			{
				number_display( status_registers.error_loop_reg );
			}

			if(register_menu_state == P6)
			{
				number_display( status_registers.alarm_loop_reg );
			}

			if(register_menu_state == P7)
			{
				number_display( status_registers.time_current_year_reg );
			}

			if(register_menu_state == P8)
			{
				number_display( status_registers.time_current_month_reg );
			}

			if(register_menu_state == P9)
			{
				number_display( status_registers.time_current_day_reg );
			}

			if(register_menu_state == P10)
			{
				number_display( status_registers.time_current_hour_reg );
			}

			if(register_menu_state == P11)
			{
				number_display( status_registers.time_current_minute_reg );
			}

			if(register_menu_state == P12)
			{
				number_display( status_registers.time_current_second_reg );
			}

			if(register_menu_state == P13)
			{
				number_display( status_registers.time_current_weekday_reg );
			}

			if(register_menu_state == P14)
			{
				number_display( status_registers.address_processed_event_h_reg );
			}

			if(register_menu_state == P15)
			{
				number_display( status_registers.address_processed_event_l_reg );
			}

			if(register_menu_state == P16)
			{
				number_display( status_registers.address_last_event_h_reg );
			}

			if(register_menu_state == P17)
			{
				number_display( status_registers.address_last_event_l_reg );
			}

			if(register_menu_state == P18)
			{
				number_display( status_registers.system_status_reg );
			}

			if(register_menu_state == P19)
			{
				number_display( status_registers.power_on_reg );
			}

			if(register_menu_state == P20)
			{
				number_display( status_registers.error_rtc_reg );
			}

			if(register_menu_state == P21)
			{
				number_display( status_registers.ibutton_complite_0_reg );
			}

			if(register_menu_state == P22)
			{
				number_display( status_registers.ibutton_complite_1_reg );
			}

			if(register_menu_state == P23)
			{
				number_display( status_registers.ibutton_complite_2_reg );
			}

			if(register_menu_state == P24)
			{
				number_display( status_registers.ibutton_complite_3_reg );
			}

			if(register_menu_state == P25)
			{
				number_display( status_registers.ibutton_complite_4_reg );
			}

			if(register_menu_state == P26)
			{
				number_display( status_registers.ibutton_complite_5_reg );
			}

			if(register_menu_state == P27)
			{
				number_display( status_registers.ibutton_complite_6_reg );
			}

			if(register_menu_state == P28)
			{
				number_display( status_registers.ibutton_complite_7_reg );
			}

			if(register_menu_state == P29)
			{
				number_display( status_registers.ce303_error_reg );
			}

			if(register_menu_state == P30)
			{
				number_display( status_registers.ce303_current_a_reg );
			}

			if(register_menu_state == P31)
			{
				number_display( status_registers.ce303_current_b_reg );
			}

			if(register_menu_state == P32)
			{
				number_display( status_registers.ce303_current_c_reg );
			}

			if(register_menu_state == P33)
			{
				number_display( status_registers.ce303_current_mil_a_reg );
			}

			if(register_menu_state == P34)
			{
				number_display( status_registers.ce303_current_mil_b_reg );
			}

			if(register_menu_state == P35)
			{
				number_display( status_registers.ce303_current_mil_c_reg );
			}

			if(register_menu_state == P36)
			{
				number_display( status_registers.ce303_volt_a_reg );
			}

			if(register_menu_state == P37)
			{
				number_display( status_registers.ce303_volt_b_reg );
			}

			if(register_menu_state == P38)
			{
				number_display( status_registers.ce303_volt_c_reg );
			}

			if(register_menu_state == P39)
			{
				number_display( status_registers.ce303_volt_mil_a_reg );
			}

			if(register_menu_state == P40)
			{
				number_display( status_registers.ce303_volt_mil_b_reg );
			}

			if(register_menu_state == P41)
			{
				number_display( status_registers.ce303_volt_mil_c_reg );
			}

			if(register_menu_state == P42)
			{
				number_display( status_registers.ce303_power_a_reg );
			}

			if(register_menu_state == P43)
			{
				number_display( status_registers.ce303_power_b_reg );
			}

			if(register_menu_state == P44)
			{
				number_display( status_registers.ce303_power_c_reg );
			}

			if(register_menu_state == P45)
			{
				number_display( status_registers.ce303_power_mil_a_reg );
			}

			if(register_menu_state == P46)
			{
				number_display( status_registers.ce303_power_mil_b_reg );
			}

			if(register_menu_state == P47)
			{
				number_display( status_registers.ce303_power_mil_c_reg );
			}

			if(register_menu_state == P48)
			{
				number_display( status_registers.ce303_total_power_h_reg );
			}

			if(register_menu_state == P49)
			{
				number_display( status_registers.ce303_total_power_l_reg );
			}

			if(register_menu_state == P50)
			{
				number_display( status_registers.ce303_total_power_m_reg );
			}

			if(register_menu_state == P51)
			{
				number_display( status_registers.ce303_tarif1_power_h_reg );
			}

			if(register_menu_state == P52)
			{
				number_display( status_registers.ce303_tarif1_power_l_reg );
			}

			if(register_menu_state == P53)
			{
				number_display( status_registers.ce303_tarif1_power_mil_reg );
			}

			if(register_menu_state == P54)
			{
				number_display( status_registers.ce303_tarif2_power_h_reg );
			}

			if(register_menu_state == P55)
			{
				number_display( status_registers.ce303_tarif2_power_l_reg );
			}

			if(register_menu_state == P56)
			{
				number_display( status_registers.ce303_tarif2_power_mil_reg );
			}

			if(register_menu_state == P57)
			{
				number_display( status_registers.ce303_tarif3_power_h_reg );
			}

			if(register_menu_state == P58)
			{
				number_display( status_registers.ce303_tarif3_power_l_reg );
			}

			if(register_menu_state == P59)
			{
				number_display( status_registers.ce303_tarif3_power_mil_reg );
			}

			if(register_menu_state == P60)
			{
				number_display( status_registers.signal_level_reg );
			}

			if(register_menu_state == P61)
			{
				number_display( status_registers.iccid_number_reg1 );
			}

			if(register_menu_state == P62)
			{
				number_display( status_registers.iccid_number_reg2 );
			}

			if(register_menu_state == P63)
			{
				number_display( status_registers.iccid_number_reg3 );
			}

			if(register_menu_state == P64)
			{
				number_display( status_registers.iccid_number_reg4 );
			}

			if(register_menu_state == P65)
			{
				number_display( status_registers.iccid_number_reg5 );
			}

			if(register_menu_state == P66)
			{
				number_display( status_registers.iccid_number_reg6 );
			}

			if(register_menu_state == P67)
			{
				number_display( status_registers.iccid_number_reg7 );
			}

			if(register_menu_state == P68)
			{
				number_display( status_registers.iccid_number_reg8 );
			}
			*/

			/*
			if(register_menu_state == Y1)
			{
				number_display( control_registers.security_control_reg );
				control_register_temp_number = control_registers.security_control_reg;
			}

			if(register_menu_state == Y2)
			{
				number_display( control_registers.control_loop_reg );
				control_register_temp_number = control_registers.control_loop_reg;
			}

			if(register_menu_state == Y3)
			{
				number_display( control_registers.alarm_loop_clear_reg );
				control_register_temp_number = control_registers.alarm_loop_clear_reg;
			}

			if(register_menu_state == Y4)
			{
				number_display( control_registers.false_loop_clear_reg );
				control_register_temp_number = control_registers.false_loop_clear_reg;
			}

			if(register_menu_state == Y5)
			{
				number_display( control_registers.time_update_reg );
				control_register_temp_number = control_registers.time_update_reg;
			}

			if(register_menu_state == Y6)
			{
				number_display( control_registers.time_year_reg );
				control_register_temp_number = control_registers.time_year_reg;
			}

			if(register_menu_state == Y7)
			{
				number_display( control_registers.time_month_reg );
				control_register_temp_number = control_registers.time_month_reg;
			}

			if(register_menu_state == Y8)
			{
				number_display( control_registers.time_day_reg );
				control_register_temp_number = control_registers.time_day_reg;
			}

			if(register_menu_state == Y9)
			{
				number_display( control_registers.time_hour_reg );
				control_register_temp_number = control_registers.time_hour_reg;
			}

			if(register_menu_state == Y10)
			{
				number_display( control_registers.time_minute_reg );
				control_register_temp_number = control_registers.time_minute_reg;
			}

			if(register_menu_state == Y11)
			{
				number_display( control_registers.time_seconds_reg );
				control_register_temp_number = control_registers.time_seconds_reg;
			}

			if(register_menu_state == Y12)
			{
				number_display( control_registers.time_weekday_reg );
				control_register_temp_number = control_registers.time_weekday_reg;
			}

			if(register_menu_state == Y13)
			{
				number_display( control_registers.event_read_reg );
				control_register_temp_number = control_registers.event_read_reg;
			}

			if(register_menu_state == Y14)
			{
				number_display( control_registers.event_address_high_reg );
				control_register_temp_number = control_registers.event_address_high_reg;
			}

			if(register_menu_state == Y15)
			{
				number_display( control_registers.event_address_low_reg );
				control_register_temp_number = control_registers.event_address_low_reg;
			}

			if(register_menu_state == Y16)
			{
				number_display( control_registers.id_high_reg );
				control_register_temp_number = control_registers.id_high_reg;
			}

			if(register_menu_state == Y17)
			{
				number_display( control_registers.id_low_reg );
				control_register_temp_number = control_registers.id_low_reg;
			}

			if(register_menu_state == Y18)
			{
				number_display( control_registers.reset_control_reg );
				control_register_temp_number = control_registers.reset_control_reg;
			}

			if(register_menu_state == Y19)
			{
				number_display( control_registers.meter_polling_reg );
				control_register_temp_number = control_registers.meter_polling_reg;
			}

			if(register_menu_state == Y20)
			{
				number_display( control_registers.ip1_reg );
				control_register_temp_number = control_registers.ip1_reg;
			}

			if(register_menu_state == Y21)
			{
				number_display( control_registers.ip2_reg );
				control_register_temp_number = control_registers.ip2_reg;
			}

			if(register_menu_state == Y22)
			{
				number_display( control_registers.ip3_reg );
				control_register_temp_number = control_registers.ip3_reg;
			}

			if(register_menu_state == Y23)
			{
				number_display( control_registers.ip4_reg );
				control_register_temp_number = control_registers.ip4_reg;
			}

			if(register_menu_state == Y24)
			{
				number_display( control_registers.port_high_reg );
				control_register_temp_number = control_registers.port_high_reg;
			}

			if(register_menu_state == Y25)
			{
				number_display( control_registers.port_low_reg );
				control_register_temp_number = control_registers.port_low_reg;
			}

			if(register_menu_state == Y26)
			{
				number_display( control_registers.meter_id_high_reg );
				control_register_temp_number = control_registers.meter_id_high_reg;
			}

			if(register_menu_state == Y27)
			{
				number_display( control_registers.meter_id_low_reg );
				control_register_temp_number = control_registers.meter_id_low_reg;
			}

			if(register_menu_state == Y28)
			{
				number_display( control_registers.gprs_call_reg );
				control_register_temp_number = control_registers.gprs_call_reg;
			}

			if(register_menu_state == Y29)
			{
				number_display( control_registers.mute_reg );
				control_register_temp_number = control_registers.mute_reg;
			}

			if(register_menu_state == Y30)
			{
				number_display( control_registers.arming_timeleft_reg );
				control_register_temp_number = control_registers.arming_timeleft_reg;
			}
			*/

			/*
			if(register_menu_state == A1)
			{
				number_display( ibutton_registers.ibutton1_byte_0_reg );
				control_register_temp_number = ibutton_registers.ibutton1_byte_0_reg;
			}

			if(register_menu_state == A2)
			{
				number_display( ibutton_registers.ibutton1_byte_1_reg );
				control_register_temp_number = ibutton_registers.ibutton1_byte_1_reg;
			}

			if(register_menu_state == A3)
			{
				number_display( ibutton_registers.ibutton1_byte_2_reg );
				control_register_temp_number = ibutton_registers.ibutton1_byte_2_reg;
			}

			if(register_menu_state == A4)
			{
				number_display( ibutton_registers.ibutton1_byte_3_reg );
				control_register_temp_number = ibutton_registers.ibutton1_byte_3_reg;
			}

			if(register_menu_state == A5)
			{
				number_display( ibutton_registers.ibutton1_byte_4_reg );
				control_register_temp_number = ibutton_registers.ibutton1_byte_4_reg;
			}

			if(register_menu_state == A6)
			{
				number_display( ibutton_registers.ibutton1_byte_5_reg );
				control_register_temp_number = ibutton_registers.ibutton1_byte_5_reg;
			}

			if(register_menu_state == A7)
			{
				number_display( ibutton_registers.ibutton1_byte_6_reg );
				control_register_temp_number = ibutton_registers.ibutton1_byte_6_reg;
			}

			if(register_menu_state == A8)
			{
				number_display( ibutton_registers.ibutton1_byte_7_reg );
				control_register_temp_number = ibutton_registers.ibutton1_byte_7_reg;
			}

			if(register_menu_state == A9)
			{
				number_display( ibutton_registers.ibutton2_byte_0_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_0_reg;
			}

			if(register_menu_state == A10)
			{
				number_display( ibutton_registers.ibutton2_byte_1_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_1_reg;
			}

			if(register_menu_state == A11)
			{
				number_display( ibutton_registers.ibutton2_byte_2_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_2_reg;
			}

			if(register_menu_state == A12)
			{
				number_display( ibutton_registers.ibutton2_byte_3_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_3_reg;
			}

			if(register_menu_state == A13)
			{
				number_display( ibutton_registers.ibutton2_byte_4_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_4_reg;
			}

			if(register_menu_state == A14)
			{
				number_display( ibutton_registers.ibutton2_byte_5_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_5_reg;
			}

			if(register_menu_state == A15)
			{
				number_display( ibutton_registers.ibutton2_byte_6_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_6_reg;
			}

			if(register_menu_state == A16)
			{
				number_display( ibutton_registers.ibutton2_byte_7_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_7_reg;
			}

			if(register_menu_state == A17)
			{
				number_display( ibutton_registers.ibutton3_byte_0_reg );
				control_register_temp_number = ibutton_registers.ibutton3_byte_0_reg;
			}

			if(register_menu_state == A18)
			{
				number_display( ibutton_registers.ibutton3_byte_1_reg );
				control_register_temp_number = ibutton_registers.ibutton3_byte_1_reg;
			}

			if(register_menu_state == A19)
			{
				number_display( ibutton_registers.ibutton3_byte_2_reg );
				control_register_temp_number = ibutton_registers.ibutton3_byte_2_reg;
			}

			if(register_menu_state == A20)
			{
				number_display( ibutton_registers.ibutton3_byte_3_reg );
				control_register_temp_number = ibutton_registers.ibutton3_byte_3_reg;
			}

			if(register_menu_state == A21)
			{
				number_display( ibutton_registers.ibutton3_byte_4_reg );
				control_register_temp_number = ibutton_registers.ibutton3_byte_4_reg;
			}

			if(register_menu_state == A22)
			{
				number_display( ibutton_registers.ibutton3_byte_5_reg );
				control_register_temp_number = ibutton_registers.ibutton3_byte_5_reg;
			}

			if(register_menu_state == A23)
			{
				number_display( ibutton_registers.ibutton3_byte_6_reg );
				control_register_temp_number = ibutton_registers.ibutton3_byte_6_reg;
			}

			if(register_menu_state == A24)
			{
				number_display( ibutton_registers.ibutton3_byte_7_reg );
				control_register_temp_number = ibutton_registers.ibutton3_byte_7_reg;
			}

			if(register_menu_state == A25)
			{
				number_display( ibutton_registers.ibutton4_byte_0_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_0_reg;
			}

			if(register_menu_state == A26)
			{
				number_display( ibutton_registers.ibutton4_byte_1_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_1_reg;
			}

			if(register_menu_state == A27)
			{
				number_display( ibutton_registers.ibutton4_byte_2_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_2_reg;
			}

			if(register_menu_state == A28)
			{
				number_display( ibutton_registers.ibutton4_byte_3_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_3_reg;
			}

			if(register_menu_state == A29)
			{
				number_display( ibutton_registers.ibutton4_byte_4_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_4_reg;
			}

			if(register_menu_state == A30)
			{
				number_display( ibutton_registers.ibutton4_byte_5_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_5_reg;
			}

			if(register_menu_state == A31)
			{
				number_display( ibutton_registers.ibutton4_byte_6_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_6_reg;
			}

			if(register_menu_state == A32)
			{
				number_display( ibutton_registers.ibutton4_byte_7_reg );
				control_register_temp_number = ibutton_registers.ibutton4_byte_7_reg;
			}

			if(register_menu_state == A33)
			{
				number_display( ibutton_registers.ibutton5_byte_0_reg );
				control_register_temp_number = ibutton_registers.ibutton5_byte_0_reg;
			}

			if(register_menu_state == A34)
			{
				number_display( ibutton_registers.ibutton5_byte_1_reg );
				control_register_temp_number = ibutton_registers.ibutton5_byte_1_reg;
			}

			if(register_menu_state == A35)
			{
				number_display( ibutton_registers.ibutton5_byte_2_reg );
				control_register_temp_number = ibutton_registers.ibutton5_byte_2_reg;
			}

			if(register_menu_state == A36)
			{
				number_display( ibutton_registers.ibutton5_byte_3_reg );
				control_register_temp_number = ibutton_registers.ibutton5_byte_3_reg;
			}

			if(register_menu_state == A37)
			{
				number_display( ibutton_registers.ibutton5_byte_4_reg );
				control_register_temp_number = ibutton_registers.ibutton5_byte_4_reg;
			}

			if(register_menu_state == A38)
			{
				number_display( ibutton_registers.ibutton2_byte_5_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_5_reg;
			}

			if(register_menu_state == A39)
			{
				number_display( ibutton_registers.ibutton2_byte_6_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_6_reg;
			}

			if(register_menu_state == A40)
			{
				number_display( ibutton_registers.ibutton2_byte_7_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_7_reg;
			}

			if(register_menu_state == A41)
			{
				number_display( ibutton_registers.ibutton2_byte_0_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_0_reg;
			}

			if(register_menu_state == A42)
			{
				number_display( ibutton_registers.ibutton2_byte_1_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_1_reg;
			}

			if(register_menu_state == A43)
			{
				number_display( ibutton_registers.ibutton2_byte_2_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_2_reg;
			}

			if(register_menu_state == A44)
			{
				number_display( ibutton_registers.ibutton2_byte_3_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_3_reg;
			}

			if(register_menu_state == A45)
			{
				number_display( ibutton_registers.ibutton2_byte_4_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_4_reg;
			}

			if(register_menu_state == A46)
			{
				number_display( ibutton_registers.ibutton2_byte_5_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_5_reg;
			}

			if(register_menu_state == A47)
			{
				number_display( ibutton_registers.ibutton2_byte_6_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_6_reg;
			}

			if(register_menu_state == A48)
			{
				number_display( ibutton_registers.ibutton2_byte_7_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_7_reg;
			}

			if(register_menu_state == A49)
			{
				number_display( ibutton_registers.ibutton2_byte_0_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_0_reg;
			}

			if(register_menu_state == A50)
			{
				number_display( ibutton_registers.ibutton2_byte_1_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_1_reg;
			}

			if(register_menu_state == A51)
			{
				number_display( ibutton_registers.ibutton2_byte_2_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_2_reg;
			}

			if(register_menu_state == A52)
			{
				number_display( ibutton_registers.ibutton2_byte_3_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_3_reg;
			}

			if(register_menu_state == A53)
			{
				number_display( ibutton_registers.ibutton2_byte_4_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_4_reg;
			}

			if(register_menu_state == A54)
			{
				number_display( ibutton_registers.ibutton2_byte_5_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_5_reg;
			}

			if(register_menu_state == A55)
			{
				number_display( ibutton_registers.ibutton2_byte_6_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_6_reg;
			}

			if(register_menu_state == A56)
			{
				number_display( ibutton_registers.ibutton2_byte_7_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_7_reg;
			}

			if(register_menu_state == A57)
			{
				number_display( ibutton_registers.ibutton2_byte_0_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_0_reg;
			}

			if(register_menu_state == A58)
			{
				number_display( ibutton_registers.ibutton2_byte_1_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_1_reg;
			}

			if(register_menu_state == A59)
			{
				number_display( ibutton_registers.ibutton2_byte_2_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_2_reg;
			}

			if(register_menu_state == A60)
			{
				number_display( ibutton_registers.ibutton2_byte_3_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_3_reg;
			}

			if(register_menu_state == A61)
			{
				number_display( ibutton_registers.ibutton2_byte_4_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_4_reg;
			}

			if(register_menu_state == A62)
			{
				number_display( ibutton_registers.ibutton2_byte_5_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_5_reg;
			}

			if(register_menu_state == A63)
			{
				number_display( ibutton_registers.ibutton2_byte_6_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_6_reg;
			}

			if(register_menu_state == A64)
			{
				number_display( ibutton_registers.ibutton2_byte_7_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_7_reg;
			}

			if(register_menu_state == A65)
			{
				number_display( ibutton_registers.ibutton2_byte_0_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_0_reg;
			}

			if(register_menu_state == A66)
			{
				number_display( ibutton_registers.ibutton2_byte_1_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_1_reg;
			}

			if(register_menu_state == A67)
			{
				number_display( ibutton_registers.ibutton2_byte_2_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_2_reg;
			}

			if(register_menu_state == A68)
			{
				number_display( ibutton_registers.ibutton2_byte_3_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_3_reg;
			}

			if(register_menu_state == A69)
			{
				number_display( ibutton_registers.ibutton2_byte_4_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_4_reg;
			}

			if(register_menu_state == A70)
			{
				number_display( ibutton_registers.ibutton2_byte_5_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_5_reg;
			}

			if(register_menu_state == A71)
			{
				number_display( ibutton_registers.ibutton2_byte_6_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_6_reg;
			}

			if(register_menu_state == A72)
			{
				number_display( ibutton_registers.ibutton2_byte_7_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_7_reg;
			}

			if(register_menu_state == A73)
			{
				number_display( ibutton_registers.ibutton2_byte_0_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_0_reg;
			}

			if(register_menu_state == A74)
			{
				number_display( ibutton_registers.ibutton2_byte_1_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_1_reg;
			}

			if(register_menu_state == A75)
			{
				number_display( ibutton_registers.ibutton2_byte_2_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_2_reg;
			}

			if(register_menu_state == A76)
			{
				number_display( ibutton_registers.ibutton2_byte_3_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_3_reg;
			}

			if(register_menu_state == A77)
			{
				number_display( ibutton_registers.ibutton2_byte_4_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_4_reg;
			}

			if(register_menu_state == A78)
			{
				number_display( ibutton_registers.ibutton2_byte_5_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_5_reg;
			}

			if(register_menu_state == A79)
			{
				number_display( ibutton_registers.ibutton2_byte_6_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_6_reg;
			}

			if(register_menu_state == A80)
			{
				number_display( ibutton_registers.ibutton2_byte_7_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_7_reg;
			}

			if(register_menu_state == A81)
			{
				number_display( ibutton_registers.ibutton2_byte_0_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_0_reg;
			}

			if(register_menu_state == A82)
			{
				number_display( ibutton_registers.ibutton2_byte_1_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_1_reg;
			}

			if(register_menu_state == A83)
			{
				number_display( ibutton_registers.ibutton2_byte_2_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_2_reg;
			}

			if(register_menu_state == A84)
			{
				number_display( ibutton_registers.ibutton2_byte_3_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_3_reg;
			}

			if(register_menu_state == A85)
			{
				number_display( ibutton_registers.ibutton2_byte_4_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_4_reg;
			}

			if(register_menu_state == A86)
			{
				number_display( ibutton_registers.ibutton2_byte_5_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_5_reg;
			}

			if(register_menu_state == A87)
			{
				number_display( ibutton_registers.ibutton2_byte_6_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_6_reg;
			}

			if(register_menu_state == A88)
			{
				number_display( ibutton_registers.ibutton2_byte_7_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_7_reg;
			}

			if(register_menu_state == A89)
			{
				number_display( ibutton_registers.ibutton2_byte_0_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_0_reg;
			}

			if(register_menu_state == A90)
			{
				number_display( ibutton_registers.ibutton2_byte_1_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_1_reg;
			}

			if(register_menu_state == A91)
			{
				number_display( ibutton_registers.ibutton2_byte_2_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_2_reg;
			}

			if(register_menu_state == A92)
			{
				number_display( ibutton_registers.ibutton2_byte_3_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_3_reg;
			}

			if(register_menu_state == A93)
			{
				number_display( ibutton_registers.ibutton2_byte_4_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_4_reg;
			}

			if(register_menu_state == A94)
			{
				number_display( ibutton_registers.ibutton2_byte_5_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_5_reg;
			}

			if(register_menu_state == A95)
			{
				number_display( ibutton_registers.ibutton2_byte_6_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_6_reg;
			}

			if(register_menu_state == A96)
			{
				number_display( ibutton_registers.ibutton2_byte_7_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_7_reg;
			}

			if(register_menu_state == A97)
			{
				number_display( ibutton_registers.ibutton2_byte_0_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_0_reg;
			}

			if(register_menu_state == A98)
			{
				number_display( ibutton_registers.ibutton2_byte_1_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_1_reg;
			}

			if(register_menu_state == A99)
			{
				number_display( ibutton_registers.ibutton2_byte_2_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_2_reg;
			}

			if(register_menu_state == A100)
			{
				number_display( ibutton_registers.ibutton2_byte_3_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_3_reg;
			}

			if(register_menu_state == A101)
			{
				number_display( ibutton_registers.ibutton2_byte_4_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_4_reg;
			}

			if(register_menu_state == A101)
			{
				number_display( ibutton_registers.ibutton2_byte_5_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_5_reg;
			}

			if(register_menu_state == A103)
			{
				number_display( ibutton_registers.ibutton2_byte_6_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_6_reg;
			}

			if(register_menu_state == A104)
			{
				number_display( ibutton_registers.ibutton2_byte_7_reg );
				control_register_temp_number = ibutton_registers.ibutton2_byte_7_reg;
			}
			*/

			if( (register_menu_state >= P1) && (register_menu_state <= P68) )
			{

				if(register_menu_state == P1)
				{
					osMutexWait(Fm25v02MutexHandle, osWaitForever);

					fm25v02_read(2*(VERSION_REG + (register_menu_state - P1) ), &ibutton_temp_reg_h);
					//fm25v02_read(2*(ICCID_NUMBER_REG1 + (register_menu_state - P61) )+1, &ibutton_temp_reg_l);
					ibutton_temp_register = ibutton_temp_reg_h;

					osMutexRelease(Fm25v02MutexHandle);

					number_display( ibutton_temp_register );
				}

				if(register_menu_state == P2)
				{
					osMutexWait(Fm25v02MutexHandle, osWaitForever);

					//fm25v02_read(2*(VERSION_REG + (register_menu_state - P2) ), &ibutton_temp_reg_h);
					fm25v02_read(2*(VERSION_REG + (register_menu_state - P2) )+1, &ibutton_temp_reg_l);
					ibutton_temp_register = ibutton_temp_reg_l;

					osMutexRelease(Fm25v02MutexHandle);

					number_display( ibutton_temp_register );
				}

				if( (register_menu_state >= P3) && (register_menu_state <= P20) )
				{
					osMutexWait(Fm25v02MutexHandle, osWaitForever);

					fm25v02_read(2*(SECURITY_STATUS_REG + (register_menu_state - P3) ), &ibutton_temp_reg_h);
					fm25v02_read(2*(SECURITY_STATUS_REG + (register_menu_state - P3) )+1, &ibutton_temp_reg_l);
					ibutton_temp_register = (((uint16_t)ibutton_temp_reg_h)<<8)|ibutton_temp_reg_l;

					osMutexRelease(Fm25v02MutexHandle);

					number_display( ibutton_temp_register );

				}

				if( (register_menu_state >= P21) && (register_menu_state <= P28) )
				{
					osMutexWait(Fm25v02MutexHandle, osWaitForever);

					fm25v02_read(2*(IBUTTON_COMPLETE_0_REG + (register_menu_state - P21) ), &ibutton_temp_reg_h);
					fm25v02_read(2*(IBUTTON_COMPLETE_0_REG + (register_menu_state - P21) )+1, &ibutton_temp_reg_l);
					ibutton_temp_register = (((uint16_t)ibutton_temp_reg_h)<<8)|ibutton_temp_reg_l;

					osMutexRelease(Fm25v02MutexHandle);

					number_display( ibutton_temp_register );

				}

				if( (register_menu_state >= P29) && (register_menu_state <= P47) )
				{
					osMutexWait(Fm25v02MutexHandle, osWaitForever);

					fm25v02_read(2*(CE_303_ERROR_REG + (register_menu_state - P29) ), &ibutton_temp_reg_h);
					fm25v02_read(2*(CE_303_ERROR_REG + (register_menu_state - P29) )+1, &ibutton_temp_reg_l);
					ibutton_temp_register = (((uint16_t)ibutton_temp_reg_h)<<8)|ibutton_temp_reg_l;

					osMutexRelease(Fm25v02MutexHandle);

					number_display( ibutton_temp_register );

				}

				if( (register_menu_state >= P48) && (register_menu_state <= P59) )
				{
					osMutexWait(Fm25v02MutexHandle, osWaitForever);

					fm25v02_read(2*(CE_303_TOTAL_POWER_H_REG + (register_menu_state - P48) ), &ibutton_temp_reg_h);
					fm25v02_read(2*(CE_303_TOTAL_POWER_H_REG + (register_menu_state - P48) )+1, &ibutton_temp_reg_l);
					ibutton_temp_register = (((uint16_t)ibutton_temp_reg_h)<<8)|ibutton_temp_reg_l;

					osMutexRelease(Fm25v02MutexHandle);

					number_display( ibutton_temp_register );

				}

				if(register_menu_state == P60)
				{
					osMutexWait(Fm25v02MutexHandle, osWaitForever);

					fm25v02_read(2*(SIGNAL_LEVEL_REG + (register_menu_state - P60) ), &ibutton_temp_reg_h);
					fm25v02_read(2*(SIGNAL_LEVEL_REG + (register_menu_state - P60) )+1, &ibutton_temp_reg_l);
					ibutton_temp_register = (((uint16_t)ibutton_temp_reg_h)<<8)|ibutton_temp_reg_l;

					osMutexRelease(Fm25v02MutexHandle);

					number_display( ibutton_temp_register );
				}

				if( (register_menu_state >= P61) && (register_menu_state <= P68) )
				{
					osMutexWait(Fm25v02MutexHandle, osWaitForever);

					fm25v02_read(2*(ICCID_NUMBER_REG1 + (register_menu_state - P61) ), &ibutton_temp_reg_h);
					fm25v02_read(2*(ICCID_NUMBER_REG1 + (register_menu_state - P61) )+1, &ibutton_temp_reg_l);
					ibutton_temp_register = (((uint16_t)ibutton_temp_reg_h)<<8)|ibutton_temp_reg_l;

					osMutexRelease(Fm25v02MutexHandle);

					number_display( ibutton_temp_register );

				}

			}


			if( (register_menu_state >= Y1) && (register_menu_state <= Y31) )
			{

				if( (register_menu_state >= Y1) && (register_menu_state <= Y2) )
				{

					osMutexWait(Fm25v02MutexHandle, osWaitForever);

					fm25v02_read(2*(SECURITY_CONTROL_REG + (register_menu_state - Y1) ), &ibutton_temp_reg_h);
					fm25v02_read(2*(SECURITY_CONTROL_REG + (register_menu_state - Y1) )+1, &ibutton_temp_reg_l);
					ibutton_temp_register = (((uint16_t)ibutton_temp_reg_h)<<8)|ibutton_temp_reg_l;

					osMutexRelease(Fm25v02MutexHandle);

					number_display( ibutton_temp_register );

					control_register_temp_number = ibutton_temp_register;

				}

				if( (register_menu_state >= Y3) && (register_menu_state <= Y4) )
				{

					osMutexWait(Fm25v02MutexHandle, osWaitForever);

					fm25v02_read(2*(ALARM_LOOP_CLEAR_REG + (register_menu_state - Y3) ), &ibutton_temp_reg_h);
					fm25v02_read(2*(ALARM_LOOP_CLEAR_REG + (register_menu_state - Y3) )+1, &ibutton_temp_reg_l);
					ibutton_temp_register = (((uint16_t)ibutton_temp_reg_h)<<8)|ibutton_temp_reg_l;

					osMutexRelease(Fm25v02MutexHandle);

					number_display( ibutton_temp_register );

					control_register_temp_number = ibutton_temp_register;

				}

				if( (register_menu_state >= Y5) && (register_menu_state <= Y12) )
				{

					osMutexWait(Fm25v02MutexHandle, osWaitForever);

					fm25v02_read(2*(TIME_UPDATE_REG + (register_menu_state - Y5) ), &ibutton_temp_reg_h);
					fm25v02_read(2*(TIME_UPDATE_REG + (register_menu_state - Y5) )+1, &ibutton_temp_reg_l);
					ibutton_temp_register = (((uint16_t)ibutton_temp_reg_h)<<8)|ibutton_temp_reg_l;

					osMutexRelease(Fm25v02MutexHandle);

					number_display( ibutton_temp_register );

					control_register_temp_number = ibutton_temp_register;

				}

				if( (register_menu_state >= Y13) && (register_menu_state <= Y15) )
				{

					osMutexWait(Fm25v02MutexHandle, osWaitForever);

					fm25v02_read(2*(EVENT_READ_REG + (register_menu_state - Y13) ), &ibutton_temp_reg_h);
					fm25v02_read(2*(EVENT_READ_REG + (register_menu_state - Y13) )+1, &ibutton_temp_reg_l);
					ibutton_temp_register = (((uint16_t)ibutton_temp_reg_h)<<8)|ibutton_temp_reg_l;

					osMutexRelease(Fm25v02MutexHandle);

					number_display( ibutton_temp_register );

					control_register_temp_number = ibutton_temp_register;

				}

				if( (register_menu_state >= Y16) && (register_menu_state <= Y28) )
				{

					osMutexWait(Fm25v02MutexHandle, osWaitForever);

					fm25v02_read(2*(ID_HIGH_REG + (register_menu_state - Y16) ), &ibutton_temp_reg_h);
					fm25v02_read(2*(ID_HIGH_REG + (register_menu_state - Y16) )+1, &ibutton_temp_reg_l);
					ibutton_temp_register = (((uint16_t)ibutton_temp_reg_h)<<8)|ibutton_temp_reg_l;

					osMutexRelease(Fm25v02MutexHandle);

					number_display( ibutton_temp_register );

					control_register_temp_number = ibutton_temp_register;

				}

				if( register_menu_state == Y29 )
				{

					osMutexWait(Fm25v02MutexHandle, osWaitForever);

					fm25v02_read(2*(MUTE_REG + (register_menu_state - Y29) ), &ibutton_temp_reg_h);
					fm25v02_read(2*(MUTE_REG + (register_menu_state - Y29) )+1, &ibutton_temp_reg_l);
					ibutton_temp_register = (((uint16_t)ibutton_temp_reg_h)<<8)|ibutton_temp_reg_l;

					osMutexRelease(Fm25v02MutexHandle);

					number_display( ibutton_temp_register );

					control_register_temp_number = ibutton_temp_register;

				}

				if( register_menu_state == Y30 )
				{

					osMutexWait(Fm25v02MutexHandle, osWaitForever);

					fm25v02_read(2*(ARMING_TIMELEFT + (register_menu_state - Y30) ), &ibutton_temp_reg_h);
					//fm25v02_read(2*(ARMING_TIMELEFT + (register_menu_state - Y30) )+1, &ibutton_temp_reg_l);
					//ibutton_temp_register = (((uint16_t)ibutton_temp_reg_h)<<8)|ibutton_temp_reg_l;
					ibutton_temp_register = ibutton_temp_reg_h;

					osMutexRelease(Fm25v02MutexHandle);

					number_display( ibutton_temp_register );

					control_register_temp_number = ibutton_temp_register;

				}

				if( register_menu_state == Y31 )
				{

					osMutexWait(Fm25v02MutexHandle, osWaitForever);

					//fm25v02_read(2*(ARMING_TIMELEFT + (register_menu_state - Y30) ), &ibutton_temp_reg_h);
					fm25v02_read(2*(ARMING_TIMELEFT + (register_menu_state - Y31) )+1, &ibutton_temp_reg_l);
					//ibutton_temp_register = (((uint16_t)ibutton_temp_reg_h)<<8)|ibutton_temp_reg_l;
					ibutton_temp_register = ibutton_temp_reg_l;

					osMutexRelease(Fm25v02MutexHandle);

					number_display( ibutton_temp_register );

					control_register_temp_number = ibutton_temp_register;

				}


			}


			if( (register_menu_state >= A1) && (register_menu_state <= A999) )
			{
				osMutexWait(Fm25v02MutexHandle, osWaitForever);

				fm25v02_read(2*(IBUTTON1_BYTE_0_REG + (((register_menu_state - A1)/8)*16) + ((register_menu_state - A1)%8) ), &ibutton_temp_reg_h);
				fm25v02_read(2*(IBUTTON1_BYTE_0_REG + (((register_menu_state - A1)/8)*16) + ((register_menu_state - A1)%8) )+1, &ibutton_temp_reg_l);
				ibutton_temp_register = (((uint16_t)ibutton_temp_reg_h)<<8)|ibutton_temp_reg_l;

				osMutexRelease(Fm25v02MutexHandle);

				number_display( ibutton_temp_register );

				control_register_temp_number = ibutton_temp_register;

			}


			if( (register_menu_state >= B1) && (register_menu_state <= B593) )
			{
				osMutexWait(Fm25v02MutexHandle, osWaitForever);

				fm25v02_read(2*(IBUTTON1_BYTE_0_REG + (((register_menu_state - A1)/8)*16) + ((register_menu_state - A1)%8) ), &ibutton_temp_reg_h);
				fm25v02_read(2*(IBUTTON1_BYTE_0_REG + (((register_menu_state - A1)/8)*16) + ((register_menu_state - A1)%8) )+1, &ibutton_temp_reg_l);
				ibutton_temp_register = (((uint16_t)ibutton_temp_reg_h)<<8)|ibutton_temp_reg_l;

				osMutexRelease(Fm25v02MutexHandle);

				number_display( ibutton_temp_register );

				control_register_temp_number = ibutton_temp_register;

			}



		}

		else if( register_content_menu_state == 2)
		{

			/*

			if(register_menu_state == Y1)
			{

				if( (control_register_increment_state == 1) && (control_register_decrement_state == 0) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number < 255)
					{
						control_register_temp_number++;
					}

				}
				else if( (control_register_increment_state == 0) && (control_register_decrement_state == 1) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number > 0)
					{
						control_register_temp_number--;
					}

				}
				else if(control_register_save_state == 1)
				{
					control_register_save_state = 0;
					register_content_menu_state = 1;

					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_write(2*SECURITY_CONTROL_REG, 0x00);
					fm25v02_write(2*SECURITY_CONTROL_REG+1, control_register_temp_number );
					osMutexRelease(Fm25v02MutexHandle);

					control_registers.security_control_reg = control_register_temp_number;

				}

				number_change_display( control_register_temp_number );

			}

			if(register_menu_state == Y2)
			{

				if( (control_register_increment_state == 1) && (control_register_decrement_state == 0) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number < 255)
					{
						control_register_temp_number++;
					}

				}
				else if( (control_register_increment_state == 0) && (control_register_decrement_state == 1) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number > 0)
					{
						control_register_temp_number--;
					}

				}
				else if(control_register_save_state == 1)
				{
					control_register_save_state = 0;
					register_content_menu_state = 1;

					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_write(2*CONTROL_LOOP_REG, 0x00);
					fm25v02_write(2*CONTROL_LOOP_REG+1, control_register_temp_number );
					osMutexRelease(Fm25v02MutexHandle);

					control_registers.control_loop_reg = control_register_temp_number;

				}

				number_change_display( control_register_temp_number );

			}

			if(register_menu_state == Y3)
			{

				if( (control_register_increment_state == 1) && (control_register_decrement_state == 0) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number < 255)
					{
						control_register_temp_number++;
					}

				}
				else if( (control_register_increment_state == 0) && (control_register_decrement_state == 1) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number > 0)
					{
						control_register_temp_number--;
					}

				}
				else if(control_register_save_state == 1)
				{
					control_register_save_state = 0;
					register_content_menu_state = 1;

					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_write(2*ALARM_LOOP_CLEAR_REG, 0x00);
					fm25v02_write(2*ALARM_LOOP_CLEAR_REG+1, control_register_temp_number );
					osMutexRelease(Fm25v02MutexHandle);

					control_registers.alarm_loop_clear_reg = control_register_temp_number;

				}

				number_change_display( control_register_temp_number );

			}

			if(register_menu_state == Y4)
			{

				if( (control_register_increment_state == 1) && (control_register_decrement_state == 0) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number < 255)
					{
						control_register_temp_number++;
					}

				}
				else if( (control_register_increment_state == 0) && (control_register_decrement_state == 1) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number > 0)
					{
						control_register_temp_number--;
					}

				}
				else if(control_register_save_state == 1)
				{
					control_register_save_state = 0;
					register_content_menu_state = 1;

					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_write(2*FALSE_LOOP_CLEAR_REG, 0x00);
					fm25v02_write(2*FALSE_LOOP_CLEAR_REG+1, control_register_temp_number );
					osMutexRelease(Fm25v02MutexHandle);

					control_registers.false_loop_clear_reg = control_register_temp_number;

				}

				number_change_display( control_register_temp_number );

			}

			if(register_menu_state == Y5)
			{

				if( (control_register_increment_state == 1) && (control_register_decrement_state == 0) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number < 255)
					{
						control_register_temp_number++;
					}

				}
				else if( (control_register_increment_state == 0) && (control_register_decrement_state == 1) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number > 0)
					{
						control_register_temp_number--;
					}

				}
				else if(control_register_save_state == 1)
				{
					control_register_save_state = 0;
					register_content_menu_state = 1;

					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_write(2*TIME_UPDATE_REG, 0x00);
					fm25v02_write(2*TIME_UPDATE_REG+1, control_register_temp_number );
					osMutexRelease(Fm25v02MutexHandle);

					control_registers.time_update_reg = control_register_temp_number;

				}

				number_change_display( control_register_temp_number );

			}

			if(register_menu_state == Y6)
			{

				if( (control_register_increment_state == 1) && (control_register_decrement_state == 0) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number < 255)
					{
						control_register_temp_number++;
					}

				}
				else if( (control_register_increment_state == 0) && (control_register_decrement_state == 1) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number > 0)
					{
						control_register_temp_number--;
					}

				}
				else if(control_register_save_state == 1)
				{
					control_register_save_state = 0;
					register_content_menu_state = 1;

					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_write(2*TIME_YEAR_REG, 0x00);
					fm25v02_write(2*TIME_YEAR_REG+1, control_register_temp_number );
					osMutexRelease(Fm25v02MutexHandle);

					control_registers.time_year_reg = control_register_temp_number;

				}

				number_change_display( control_register_temp_number );

			}

			if(register_menu_state == Y7)
			{

				if( (control_register_increment_state == 1) && (control_register_decrement_state == 0) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number < 255)
					{
						control_register_temp_number++;
					}

				}
				else if( (control_register_increment_state == 0) && (control_register_decrement_state == 1) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number > 0)
					{
						control_register_temp_number--;
					}

				}
				else if(control_register_save_state == 1)
				{
					control_register_save_state = 0;
					register_content_menu_state = 1;

					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_write(2*TIME_MONTH_REG, 0x00);
					fm25v02_write(2*TIME_MONTH_REG+1, control_register_temp_number );
					osMutexRelease(Fm25v02MutexHandle);

					control_registers.time_month_reg = control_register_temp_number;

				}

				number_change_display( control_register_temp_number );

			}

			if(register_menu_state == Y8)
			{

				if( (control_register_increment_state == 1) && (control_register_decrement_state == 0) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number < 255)
					{
						control_register_temp_number++;
					}

				}
				else if( (control_register_increment_state == 0) && (control_register_decrement_state == 1) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number > 0)
					{
						control_register_temp_number--;
					}

				}
				else if(control_register_save_state == 1)
				{
					control_register_save_state = 0;
					register_content_menu_state = 1;

					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_write(2*TIME_DAY_REG, 0x00);
					fm25v02_write(2*TIME_DAY_REG+1, control_register_temp_number );
					osMutexRelease(Fm25v02MutexHandle);

					control_registers.time_day_reg = control_register_temp_number;

				}

				number_change_display( control_register_temp_number );

			}

			if(register_menu_state == Y9)
			{

				if( (control_register_increment_state == 1) && (control_register_decrement_state == 0) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number < 255)
					{
						control_register_temp_number++;
					}

				}
				else if( (control_register_increment_state == 0) && (control_register_decrement_state == 1) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number > 0)
					{
						control_register_temp_number--;
					}

				}
				else if(control_register_save_state == 1)
				{
					control_register_save_state = 0;
					register_content_menu_state = 1;

					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_write(2*TIME_HOUR_REG, 0x00);
					fm25v02_write(2*TIME_HOUR_REG+1, control_register_temp_number );
					osMutexRelease(Fm25v02MutexHandle);

					control_registers.time_hour_reg = control_register_temp_number;

				}

				number_change_display( control_register_temp_number );

			}

			if(register_menu_state == Y10)
			{

				if( (control_register_increment_state == 1) && (control_register_decrement_state == 0) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number < 255)
					{
						control_register_temp_number++;
					}

				}
				else if( (control_register_increment_state == 0) && (control_register_decrement_state == 1) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number > 0)
					{
						control_register_temp_number--;
					}

				}
				else if(control_register_save_state == 1)
				{
					control_register_save_state = 0;
					register_content_menu_state = 1;

					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_write(2*TIME_MINUTE_REG, 0x00);
					fm25v02_write(2*TIME_MINUTE_REG+1, control_register_temp_number );
					osMutexRelease(Fm25v02MutexHandle);

					control_registers.time_minute_reg = control_register_temp_number;

				}

				number_change_display( control_register_temp_number );

			}

			if(register_menu_state == Y11)
			{

				if( (control_register_increment_state == 1) && (control_register_decrement_state == 0) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number < 255)
					{
						control_register_temp_number++;
					}

				}
				else if( (control_register_increment_state == 0) && (control_register_decrement_state == 1) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number > 0)
					{
						control_register_temp_number--;
					}

				}
				else if(control_register_save_state == 1)
				{
					control_register_save_state = 0;
					register_content_menu_state = 1;

					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_write(2*TIME_SECONDS_REG, 0x00);
					fm25v02_write(2*TIME_SECONDS_REG+1, control_register_temp_number );
					osMutexRelease(Fm25v02MutexHandle);

					control_registers.time_seconds_reg = control_register_temp_number;

				}

				number_change_display( control_register_temp_number );

			}

			if(register_menu_state == Y12)
			{

				if( (control_register_increment_state == 1) && (control_register_decrement_state == 0) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number < 255)
					{
						control_register_temp_number++;
					}

				}
				else if( (control_register_increment_state == 0) && (control_register_decrement_state == 1) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number > 0)
					{
						control_register_temp_number--;
					}

				}
				else if(control_register_save_state == 1)
				{
					control_register_save_state = 0;
					register_content_menu_state = 1;

					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_write(2*TIME_WEEKDAY_REG, 0x00);
					fm25v02_write(2*TIME_WEEKDAY_REG+1, control_register_temp_number );
					osMutexRelease(Fm25v02MutexHandle);

					control_registers.time_weekday_reg = control_register_temp_number;

				}

				number_change_display( control_register_temp_number );

			}

			if(register_menu_state == Y13)
			{

				if( (control_register_increment_state == 1) && (control_register_decrement_state == 0) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number < 255)
					{
						control_register_temp_number++;
					}

				}
				else if( (control_register_increment_state == 0) && (control_register_decrement_state == 1) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number > 0)
					{
						control_register_temp_number--;
					}

				}
				else if(control_register_save_state == 1)
				{
					control_register_save_state = 0;
					register_content_menu_state = 1;

					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_write(2*EVENT_READ_REG, 0x00);
					fm25v02_write(2*EVENT_READ_REG+1, control_register_temp_number );
					osMutexRelease(Fm25v02MutexHandle);

					control_registers.event_read_reg = control_register_temp_number;

				}

				number_change_display( control_register_temp_number );

			}

			if(register_menu_state == Y14)
			{

				if( (control_register_increment_state == 1) && (control_register_decrement_state == 0) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number < 255)
					{
						control_register_temp_number++;
					}

				}
				else if( (control_register_increment_state == 0) && (control_register_decrement_state == 1) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number > 0)
					{
						control_register_temp_number--;
					}

				}
				else if(control_register_save_state == 1)
				{
					control_register_save_state = 0;
					register_content_menu_state = 1;

					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_write(2*EVENT_ADDRESS_HIGH_REG, 0x00);
					fm25v02_write(2*EVENT_ADDRESS_HIGH_REG+1, control_register_temp_number );
					osMutexRelease(Fm25v02MutexHandle);

					control_registers.event_address_high_reg = control_register_temp_number;

				}

				number_change_display( control_register_temp_number );

			}

			if(register_menu_state == Y15)
			{

				if( (control_register_increment_state == 1) && (control_register_decrement_state == 0) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number < 255)
					{
						control_register_temp_number++;
					}

				}
				else if( (control_register_increment_state == 0) && (control_register_decrement_state == 1) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number > 0)
					{
						control_register_temp_number--;
					}

				}
				else if(control_register_save_state == 1)
				{
					control_register_save_state = 0;
					register_content_menu_state = 1;

					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_write(2*EVENT_ADDRESS_LOW_REG, 0x00);
					fm25v02_write(2*EVENT_ADDRESS_LOW_REG+1, control_register_temp_number );
					osMutexRelease(Fm25v02MutexHandle);

					control_registers.event_address_low_reg = control_register_temp_number;

				}

				number_change_display( control_register_temp_number );

			}

			if(register_menu_state == Y16)
			{

				if( (control_register_increment_state == 1) && (control_register_decrement_state == 0) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number < 255)
					{
						control_register_temp_number++;
					}

				}
				else if( (control_register_increment_state == 0) && (control_register_decrement_state == 1) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number > 0)
					{
						control_register_temp_number--;
					}

				}
				else if(control_register_save_state == 1)
				{
					control_register_save_state = 0;
					register_content_menu_state = 1;

					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_write(2*ID_HIGH_REG, 0x00);
					fm25v02_write(2*ID_HIGH_REG+1, control_register_temp_number );
					osMutexRelease(Fm25v02MutexHandle);

					control_registers.id_high_reg = control_register_temp_number;

				}

				number_change_display( control_register_temp_number );

			}

			if(register_menu_state == Y17)
			{

				if( (control_register_increment_state == 1) && (control_register_decrement_state == 0) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number < 255)
					{
						control_register_temp_number++;
					}

				}
				else if( (control_register_increment_state == 0) && (control_register_decrement_state == 1) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number > 0)
					{
						control_register_temp_number--;
					}

				}
				else if(control_register_save_state == 1)
				{
					control_register_save_state = 0;
					register_content_menu_state = 1;

					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_write(2*ID_LOW_REG, 0x00);
					fm25v02_write(2*ID_LOW_REG+1, control_register_temp_number );
					osMutexRelease(Fm25v02MutexHandle);

					control_registers.id_low_reg = control_register_temp_number;

				}

				number_change_display( control_register_temp_number );

			}

			if(register_menu_state == Y18)
			{

				if( (control_register_increment_state == 1) && (control_register_decrement_state == 0) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number < 255)
					{
						control_register_temp_number++;
					}

				}
				else if( (control_register_increment_state == 0) && (control_register_decrement_state == 1) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number > 0)
					{
						control_register_temp_number--;
					}

				}
				else if(control_register_save_state == 1)
				{
					control_register_save_state = 0;
					register_content_menu_state = 1;

					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_write(2*RESET_CONTROL_REG, 0x00);
					fm25v02_write(2*RESET_CONTROL_REG+1, control_register_temp_number );
					osMutexRelease(Fm25v02MutexHandle);

					control_registers.reset_control_reg = control_register_temp_number;

				}

				number_change_display( control_register_temp_number );

			}

			if(register_menu_state == Y19)
			{

				if( (control_register_increment_state == 1) && (control_register_decrement_state == 0) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number < 255)
					{
						control_register_temp_number++;
					}

				}
				else if( (control_register_increment_state == 0) && (control_register_decrement_state == 1) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number > 0)
					{
						control_register_temp_number--;
					}

				}
				else if(control_register_save_state == 1)
				{
					control_register_save_state = 0;
					register_content_menu_state = 1;

					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_write(2*METER_POLLING_REG, 0x00);
					fm25v02_write(2*METER_POLLING_REG+1, control_register_temp_number );
					osMutexRelease(Fm25v02MutexHandle);

					control_registers.meter_polling_reg = control_register_temp_number;

				}

				number_change_display( control_register_temp_number );

			}

			if(register_menu_state == Y20)
			{

				if( (control_register_increment_state == 1) && (control_register_decrement_state == 0) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number < 255)
					{
						control_register_temp_number++;
					}

				}
				else if( (control_register_increment_state == 0) && (control_register_decrement_state == 1) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number > 0)
					{
						control_register_temp_number--;
					}

				}
				else if(control_register_save_state == 1)
				{
					control_register_save_state = 0;
					register_content_menu_state = 1;

					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_write(2*IP_1_REG, 0x00);
					fm25v02_write(2*IP_1_REG+1, control_register_temp_number );
					osMutexRelease(Fm25v02MutexHandle);

					control_registers.ip1_reg = control_register_temp_number;

				}

				number_change_display( control_register_temp_number );

			}

			if(register_menu_state == Y21)
			{

				if( (control_register_increment_state == 1) && (control_register_decrement_state == 0) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number < 255)
					{
						control_register_temp_number++;
					}

				}
				else if( (control_register_increment_state == 0) && (control_register_decrement_state == 1) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number > 0)
					{
						control_register_temp_number--;
					}

				}
				else if(control_register_save_state == 1)
				{
					control_register_save_state = 0;
					register_content_menu_state = 1;

					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_write(2*IP_2_REG, 0x00);
					fm25v02_write(2*IP_2_REG+1, control_register_temp_number );
					osMutexRelease(Fm25v02MutexHandle);

					control_registers.ip2_reg = control_register_temp_number;

				}

				number_change_display( control_register_temp_number );

			}

			if(register_menu_state == Y22)
			{

				if( (control_register_increment_state == 1) && (control_register_decrement_state == 0) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number < 255)
					{
						control_register_temp_number++;
					}

				}
				else if( (control_register_increment_state == 0) && (control_register_decrement_state == 1) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number > 0)
					{
						control_register_temp_number--;
					}

				}
				else if(control_register_save_state == 1)
				{
					control_register_save_state = 0;
					register_content_menu_state = 1;

					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_write(2*IP_3_REG, 0x00);
					fm25v02_write(2*IP_3_REG+1, control_register_temp_number );
					osMutexRelease(Fm25v02MutexHandle);

					control_registers.ip3_reg = control_register_temp_number;

				}

				number_change_display( control_register_temp_number );

			}

			if(register_menu_state == Y23)
			{

				if( (control_register_increment_state == 1) && (control_register_decrement_state == 0) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number < 255)
					{
						control_register_temp_number++;
					}

				}
				else if( (control_register_increment_state == 0) && (control_register_decrement_state == 1) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number > 0)
					{
						control_register_temp_number--;
					}

				}
				else if(control_register_save_state == 1)
				{
					control_register_save_state = 0;
					register_content_menu_state = 1;

					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_write(2*IP_4_REG, 0x00);
					fm25v02_write(2*IP_4_REG+1, control_register_temp_number );
					osMutexRelease(Fm25v02MutexHandle);

					control_registers.ip4_reg = control_register_temp_number;

				}

				number_change_display( control_register_temp_number );

			}

			if(register_menu_state == Y24)
			{

				if( (control_register_increment_state == 1) && (control_register_decrement_state == 0) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number < 255)
					{
						control_register_temp_number++;
					}

				}
				else if( (control_register_increment_state == 0) && (control_register_decrement_state == 1) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number > 0)
					{
						control_register_temp_number--;
					}

				}
				else if(control_register_save_state == 1)
				{
					control_register_save_state = 0;
					register_content_menu_state = 1;

					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_write(2*PORT_HIGH_REG, 0x00);
					fm25v02_write(2*PORT_HIGH_REG+1, control_register_temp_number );
					osMutexRelease(Fm25v02MutexHandle);

					control_registers.port_high_reg = control_register_temp_number;

				}

				number_change_display( control_register_temp_number );

			}

			if(register_menu_state == Y25)
			{

				if( (control_register_increment_state == 1) && (control_register_decrement_state == 0) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number < 255)
					{
						control_register_temp_number++;
					}

				}
				else if( (control_register_increment_state == 0) && (control_register_decrement_state == 1) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number > 0)
					{
						control_register_temp_number--;
					}

				}
				else if(control_register_save_state == 1)
				{
					control_register_save_state = 0;
					register_content_menu_state = 1;

					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_write(2*PORT_LOW_REG, 0x00);
					fm25v02_write(2*PORT_LOW_REG+1, control_register_temp_number );
					osMutexRelease(Fm25v02MutexHandle);

					control_registers.port_low_reg = control_register_temp_number;

				}

				number_change_display( control_register_temp_number );

			}

			if(register_menu_state == Y26)
			{

				if( (control_register_increment_state == 1) && (control_register_decrement_state == 0) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number < 255)
					{
						control_register_temp_number++;
					}

				}
				else if( (control_register_increment_state == 0) && (control_register_decrement_state == 1) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number > 0)
					{
						control_register_temp_number--;
					}

				}
				else if(control_register_save_state == 1)
				{
					control_register_save_state = 0;
					register_content_menu_state = 1;

					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_write(2*METER_ID_HIGH_REG, 0x00);
					fm25v02_write(2*METER_ID_HIGH_REG+1, control_register_temp_number );
					osMutexRelease(Fm25v02MutexHandle);

					control_registers.meter_id_high_reg = control_register_temp_number;

				}

				number_change_display( control_register_temp_number );

			}

			if(register_menu_state == Y27)
			{

				if( (control_register_increment_state == 1) && (control_register_decrement_state == 0) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number < 255)
					{
						control_register_temp_number++;
					}

				}
				else if( (control_register_increment_state == 0) && (control_register_decrement_state == 1) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number > 0)
					{
						control_register_temp_number--;
					}

				}
				else if(control_register_save_state == 1)
				{
					control_register_save_state = 0;
					register_content_menu_state = 1;

					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_write(2*METER_ID_LOW_REG, 0x00);
					fm25v02_write(2*METER_ID_LOW_REG+1, control_register_temp_number );
					osMutexRelease(Fm25v02MutexHandle);

					control_registers.meter_id_low_reg = control_register_temp_number;

				}

				number_change_display( control_register_temp_number );

			}

			if(register_menu_state == Y28)
			{

				if( (control_register_increment_state == 1) && (control_register_decrement_state == 0) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number < 255)
					{
						control_register_temp_number++;
					}

				}
				else if( (control_register_increment_state == 0) && (control_register_decrement_state == 1) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number > 0)
					{
						control_register_temp_number--;
					}

				}
				else if(control_register_save_state == 1)
				{
					control_register_save_state = 0;
					register_content_menu_state = 1;

					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_write(2*GPRS_CALL_REG, 0x00);
					fm25v02_write(2*GPRS_CALL_REG+1, control_register_temp_number );
					osMutexRelease(Fm25v02MutexHandle);

					control_registers.gprs_call_reg = control_register_temp_number;

				}

				number_change_display( control_register_temp_number );

			}

			if(register_menu_state == Y29)
			{

				if( (control_register_increment_state == 1) && (control_register_decrement_state == 0) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number < 255)
					{
						control_register_temp_number++;
					}

				}
				else if( (control_register_increment_state == 0) && (control_register_decrement_state == 1) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number > 0)
					{
						control_register_temp_number--;
					}

				}
				else if(control_register_save_state == 1)
				{
					control_register_save_state = 0;
					register_content_menu_state = 1;

					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_write(2*MUTE_REG, 0x00);
					fm25v02_write(2*MUTE_REG+1, control_register_temp_number );
					osMutexRelease(Fm25v02MutexHandle);

					control_registers.mute_reg = control_register_temp_number;

				}

				number_change_display( control_register_temp_number );

			}

			if(register_menu_state == Y30)
			{

				if( (control_register_increment_state == 1) && (control_register_decrement_state == 0) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number < 255)
					{
						control_register_temp_number++;
					}

				}
				else if( (control_register_increment_state == 0) && (control_register_decrement_state == 1) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number > 0)
					{
						control_register_temp_number--;
					}

				}
				else if(control_register_save_state == 1)
				{
					control_register_save_state = 0;
					register_content_menu_state = 1;

					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_write(2*ARMING_TIMELEFT, 0x00);
					fm25v02_write(2*ARMING_TIMELEFT+1, control_register_temp_number );
					osMutexRelease(Fm25v02MutexHandle);

					control_registers.arming_timeleft_reg = control_register_temp_number;

				}

				number_change_display( control_register_temp_number );

			}
			//---------------------------------------------------------------------------

			*/

			if( (register_menu_state >= Y1) && (register_menu_state <= Y31) )
			{


				if( (register_menu_state >= Y1) && (register_menu_state <= Y2) )
				{

					if( (control_register_increment_state == 1) && (control_register_decrement_state == 0) )
					{
						control_register_increment_state = 0;
						control_register_decrement_state = 0;

						if(control_register_temp_number < 255)
						{
							control_register_temp_number++;
						}

					}
					else if( (control_register_increment_state == 0) && (control_register_decrement_state == 1) )
					{
						control_register_increment_state = 0;
						control_register_decrement_state = 0;

						if(control_register_temp_number > 0)
						{
							control_register_temp_number--;
						}

					}
					else if(control_register_save_state == 1)
					{
						control_register_save_state = 0;
						register_content_menu_state = 1;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write( 2*(SECURITY_CONTROL_REG + (register_menu_state - Y1) ), 0x00);
						fm25v02_write( 2*(SECURITY_CONTROL_REG + (register_menu_state - Y1) )+1, control_register_temp_number );
						osMutexRelease(Fm25v02MutexHandle);

						//control_registers.arming_timeleft_reg = control_register_temp_number;


					}

					number_change_display( control_register_temp_number );

				}


				if( (register_menu_state >= Y3) && (register_menu_state <= Y4) )
				{

					if( (control_register_increment_state == 1) && (control_register_decrement_state == 0) )
					{
						control_register_increment_state = 0;
						control_register_decrement_state = 0;

						if(control_register_temp_number < 255)
						{
							control_register_temp_number++;
						}

					}
					else if( (control_register_increment_state == 0) && (control_register_decrement_state == 1) )
					{
						control_register_increment_state = 0;
						control_register_decrement_state = 0;

						if(control_register_temp_number > 0)
						{
							control_register_temp_number--;
						}

					}
					else if(control_register_save_state == 1)
					{
						control_register_save_state = 0;
						register_content_menu_state = 1;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write( 2*(ALARM_LOOP_CLEAR_REG + (register_menu_state - Y3) ), 0x00);
						fm25v02_write( 2*(ALARM_LOOP_CLEAR_REG + (register_menu_state - Y3) )+1, control_register_temp_number );
						osMutexRelease(Fm25v02MutexHandle);

						//control_registers.arming_timeleft_reg = control_register_temp_number;


					}

					number_change_display( control_register_temp_number );

				}


				if( (register_menu_state >= Y5) && (register_menu_state <= Y12) )
				{

					if( (control_register_increment_state == 1) && (control_register_decrement_state == 0) )
					{
						control_register_increment_state = 0;
						control_register_decrement_state = 0;

						if(control_register_temp_number < 255)
						{
							control_register_temp_number++;
						}

					}
					else if( (control_register_increment_state == 0) && (control_register_decrement_state == 1) )
					{
						control_register_increment_state = 0;
						control_register_decrement_state = 0;

						if(control_register_temp_number > 0)
						{
							control_register_temp_number--;
						}

					}
					else if(control_register_save_state == 1)
					{
						control_register_save_state = 0;
						register_content_menu_state = 1;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write( 2*(TIME_UPDATE_REG + (register_menu_state - Y5) ), 0x00);
						fm25v02_write( 2*(TIME_UPDATE_REG + (register_menu_state - Y5) )+1, control_register_temp_number );
						osMutexRelease(Fm25v02MutexHandle);

						//control_registers.arming_timeleft_reg = control_register_temp_number;


					}

					number_change_display( control_register_temp_number );

				}


				if( (register_menu_state >= Y13) && (register_menu_state <= Y15) )
				{

					if( (control_register_increment_state == 1) && (control_register_decrement_state == 0) )
					{
						control_register_increment_state = 0;
						control_register_decrement_state = 0;

						if(control_register_temp_number < 255)
						{
							control_register_temp_number++;
						}

					}
					else if( (control_register_increment_state == 0) && (control_register_decrement_state == 1) )
					{
						control_register_increment_state = 0;
						control_register_decrement_state = 0;

						if(control_register_temp_number > 0)
						{
							control_register_temp_number--;
						}

					}
					else if(control_register_save_state == 1)
					{
						control_register_save_state = 0;
						register_content_menu_state = 1;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write( 2*(EVENT_READ_REG + (register_menu_state - Y13) ), 0x00);
						fm25v02_write( 2*(EVENT_READ_REG + (register_menu_state - Y13) )+1, control_register_temp_number );
						osMutexRelease(Fm25v02MutexHandle);

						//control_registers.arming_timeleft_reg = control_register_temp_number;


					}

					number_change_display( control_register_temp_number );

				}


				if( (register_menu_state >= Y16) && (register_menu_state <= Y28) )
				{

					if( (control_register_increment_state == 1) && (control_register_decrement_state == 0) )
					{
						control_register_increment_state = 0;
						control_register_decrement_state = 0;

						if(control_register_temp_number < 255)
						{
							control_register_temp_number++;
						}

					}
					else if( (control_register_increment_state == 0) && (control_register_decrement_state == 1) )
					{
						control_register_increment_state = 0;
						control_register_decrement_state = 0;

						if(control_register_temp_number > 0)
						{
							control_register_temp_number--;
						}

					}
					else if(control_register_save_state == 1)
					{
						control_register_save_state = 0;
						register_content_menu_state = 1;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write( 2*(ID_HIGH_REG + (register_menu_state - Y16) ), 0x00);
						fm25v02_write( 2*(ID_HIGH_REG + (register_menu_state - Y16) )+1, control_register_temp_number );
						osMutexRelease(Fm25v02MutexHandle);

						//control_registers.arming_timeleft_reg = control_register_temp_number;


					}

					number_change_display( control_register_temp_number );

				}


				if( register_menu_state == Y29 )
				{

					if( (control_register_increment_state == 1) && (control_register_decrement_state == 0) )
					{
						control_register_increment_state = 0;
						control_register_decrement_state = 0;

						if(control_register_temp_number < 255)
						{
							control_register_temp_number++;
						}

					}
					else if( (control_register_increment_state == 0) && (control_register_decrement_state == 1) )
					{
						control_register_increment_state = 0;
						control_register_decrement_state = 0;

						if(control_register_temp_number > 0)
						{
							control_register_temp_number--;
						}

					}
					else if(control_register_save_state == 1)
					{
						control_register_save_state = 0;
						register_content_menu_state = 1;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write( 2*(MUTE_REG + (register_menu_state - Y29) ), 0x00);
						fm25v02_write( 2*(MUTE_REG + (register_menu_state - Y29) )+1, control_register_temp_number );
						osMutexRelease(Fm25v02MutexHandle);

						//control_registers.arming_timeleft_reg = control_register_temp_number;


					}

					number_change_display( control_register_temp_number );

				}


				if( register_menu_state == Y30 )
				{

					if( (control_register_increment_state == 1) && (control_register_decrement_state == 0) )
					{
						control_register_increment_state = 0;
						control_register_decrement_state = 0;

						if(control_register_temp_number < 255)
						{
							control_register_temp_number++;
						}

					}
					else if( (control_register_increment_state == 0) && (control_register_decrement_state == 1) )
					{
						control_register_increment_state = 0;
						control_register_decrement_state = 0;

						if(control_register_temp_number > 0)
						{
							control_register_temp_number--;
						}

					}
					else if(control_register_save_state == 1)
					{
						control_register_save_state = 0;
						register_content_menu_state = 1;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						fm25v02_write( 2*(ARMING_TIMELEFT + (register_menu_state - Y30) ), control_register_temp_number );
						//fm25v02_write( 2*(ARMING_TIMELEFT + (register_menu_state - Y30) )+1, control_register_temp_number );
						osMutexRelease(Fm25v02MutexHandle);

						//control_registers.arming_timeleft_reg = control_register_temp_number;


					}

					number_change_display( control_register_temp_number );

				}


				if( register_menu_state == Y31 )
				{

					if( (control_register_increment_state == 1) && (control_register_decrement_state == 0) )
					{
						control_register_increment_state = 0;
						control_register_decrement_state = 0;

						if(control_register_temp_number < 255)
						{
							control_register_temp_number++;
						}

					}
					else if( (control_register_increment_state == 0) && (control_register_decrement_state == 1) )
					{
						control_register_increment_state = 0;
						control_register_decrement_state = 0;

						if(control_register_temp_number > 0)
						{
							control_register_temp_number--;
						}

					}
					else if(control_register_save_state == 1)
					{
						control_register_save_state = 0;
						register_content_menu_state = 1;

						osMutexWait(Fm25v02MutexHandle, osWaitForever);
						//fm25v02_write( 2*(ARMING_TIMELEFT + (register_menu_state - Y30) ), 0x00);
						fm25v02_write( 2*(ARMING_TIMELEFT + (register_menu_state - Y31) )+1, control_register_temp_number );
						osMutexRelease(Fm25v02MutexHandle);

						//control_registers.arming_timeleft_reg = control_register_temp_number;


					}

					number_change_display( control_register_temp_number );

				}

			}


			if( (register_menu_state >= A1) && (register_menu_state <= A999) )
			{

				if( (control_register_increment_state == 1) && (control_register_decrement_state == 0) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number < 255)
					{
						control_register_temp_number++;
					}

				}
				else if( (control_register_increment_state == 0) && (control_register_decrement_state == 1) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number > 0)
					{
						control_register_temp_number--;
					}

				}
				else if(control_register_save_state == 1)
				{
					control_register_save_state = 0;
					register_content_menu_state = 1;

					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_write( 2*(IBUTTON1_BYTE_0_REG + (((register_menu_state - A1)/8)*16) + ((register_menu_state - A1)%8) ), 0x00);
					fm25v02_write( 2*(IBUTTON1_BYTE_0_REG + (((register_menu_state - A1)/8)*16) + ((register_menu_state - A1)%8) )+1, control_register_temp_number );
					osMutexRelease(Fm25v02MutexHandle);

					//control_registers.arming_timeleft_reg = control_register_temp_number;


				}

				number_change_display( control_register_temp_number );

			}

			if( (register_menu_state >= B1) && (register_menu_state <= B593) )
			{

				if( (control_register_increment_state == 1) && (control_register_decrement_state == 0) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number < 255)
					{
						control_register_temp_number++;
					}

				}
				else if( (control_register_increment_state == 0) && (control_register_decrement_state == 1) )
				{
					control_register_increment_state = 0;
					control_register_decrement_state = 0;

					if(control_register_temp_number > 0)
					{
						control_register_temp_number--;
					}

				}
				else if(control_register_save_state == 1)
				{
					control_register_save_state = 0;
					register_content_menu_state = 1;

					osMutexWait(Fm25v02MutexHandle, osWaitForever);
					fm25v02_write( 2*(IBUTTON1_BYTE_0_REG + (((register_menu_state - A1)/8)*16) + ((register_menu_state - A1)%8) ), 0x00);
					fm25v02_write( 2*(IBUTTON1_BYTE_0_REG + (((register_menu_state - A1)/8)*16) + ((register_menu_state - A1)%8) )+1, control_register_temp_number );
					osMutexRelease(Fm25v02MutexHandle);

					//control_registers.arming_timeleft_reg = control_register_temp_number;


				}

				number_change_display( control_register_temp_number );

			}

			//-----------------------------------------------------------------------------------------




		}




		osDelay(100); // ждем 100 милисекунд
	}
}

