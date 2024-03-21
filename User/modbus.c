#include "cmsis_os.h"
#include "modbus.h"
#include "fm25v02.h"
//#include "stm32f4xx_hal.h"


extern osMutexId Fm25v02MutexHandle;

status_register_struct status_registers;
control_register_struct control_registers;
bootloader_register_struct bootloader_registers;
ibutton_register_struct ibutton_registers;

//----функция чтения из памяти регистров статуса--------------------------
void read_status_registers(void)
{
	uint8_t status_reg_temp_h;
	uint8_t status_reg_temp_l;

	osMutexWait(Fm25v02MutexHandle, osWaitForever);

	fm25v02_read(2*VERSION_REG, &status_reg_temp_h);
	fm25v02_read(2*VERSION_REG+1, &status_reg_temp_l);
	status_registers.version_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*SECURITY_STATUS_REG, &status_reg_temp_h);
	fm25v02_read(2*SECURITY_STATUS_REG+1, &status_reg_temp_l);
	status_registers.security_status_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*STATUS_LOOP_REG, &status_reg_temp_h);
	fm25v02_read(2*STATUS_LOOP_REG+1, &status_reg_temp_l);
	status_registers.status_loop_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*ERROR_LOOP_REG, &status_reg_temp_h);
	fm25v02_read(2*ERROR_LOOP_REG+1, &status_reg_temp_l);
	status_registers.error_loop_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*ALARM_LOOP_REG, &status_reg_temp_h);
	fm25v02_read(2*ALARM_LOOP_REG+1, &status_reg_temp_l);
	status_registers.alarm_loop_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*TIME_CURRENT_YEAR_REG, &status_reg_temp_h);
	fm25v02_read(2*TIME_CURRENT_YEAR_REG+1, &status_reg_temp_l);
	status_registers.time_current_year_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*TIME_CURRENT_MONTH_REG, &status_reg_temp_h);
	fm25v02_read(2*TIME_CURRENT_MONTH_REG+1, &status_reg_temp_l);
	status_registers.time_current_month_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*TIME_CURRENT_DAY_REG, &status_reg_temp_h);
	fm25v02_read(2*TIME_CURRENT_DAY_REG+1, &status_reg_temp_l);
	status_registers.time_current_day_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*TIME_CURRENT_HOUR_REG, &status_reg_temp_h);
	fm25v02_read(2*TIME_CURRENT_HOUR_REG+1, &status_reg_temp_l);
	status_registers.time_current_hour_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*TIME_CURRENT_MINUTE_REG, &status_reg_temp_h);
	fm25v02_read(2*TIME_CURRENT_MINUTE_REG+1, &status_reg_temp_l);
	status_registers.time_current_minute_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*TIME_CURRENT_SECOND_REG, &status_reg_temp_h);
	fm25v02_read(2*TIME_CURRENT_SECOND_REG+1, &status_reg_temp_l);
	status_registers.time_current_second_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*TIME_CURRENT_WEEKDAY_REG, &status_reg_temp_h);
	fm25v02_read(2*TIME_CURRENT_WEEKDAY_REG+1, &status_reg_temp_l);
	status_registers.time_current_weekday_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*ADDRESS_PROCESSED_EVENT_H_REG, &status_reg_temp_h);
	fm25v02_read(2*ADDRESS_PROCESSED_EVENT_H_REG+1, &status_reg_temp_l);
	status_registers.address_processed_event_h_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*ADDRESS_PROCESSED_EVENT_L_REG, &status_reg_temp_h);
	fm25v02_read(2*ADDRESS_PROCESSED_EVENT_L_REG+1, &status_reg_temp_l);
	status_registers.address_processed_event_l_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*ADDRESS_LAST_EVENT_H_REG, &status_reg_temp_h);
	fm25v02_read(2*ADDRESS_LAST_EVENT_H_REG+1, &status_reg_temp_l);
	status_registers.address_last_event_h_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*ADDRESS_LAST_EVENT_L_REG, &status_reg_temp_h);
	fm25v02_read(2*ADDRESS_LAST_EVENT_L_REG+1, &status_reg_temp_l);
	status_registers.address_last_event_l_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*SYSTEM_STATUS_REG, &status_reg_temp_h);
	fm25v02_read(2*SYSTEM_STATUS_REG+1, &status_reg_temp_l);
	status_registers.system_status_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*POWER_ON_REG, &status_reg_temp_h);
	fm25v02_read(2*POWER_ON_REG+1, &status_reg_temp_l);
	status_registers.power_on_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*ERROR_RTC_REG, &status_reg_temp_h);
	fm25v02_read(2*ERROR_RTC_REG+1, &status_reg_temp_l);
	status_registers.error_rtc_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*POWER_ON_LIGHTING_REG, &status_reg_temp_h);
	//fm25v02_read(2*POWER_ON_LIGHTING_REG+1, &status_reg_temp_l);
	//status_registers.power_on_lighting_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON_COMPLETE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON_COMPLETE_0_REG+1, &status_reg_temp_l);
	status_registers.ibutton_complite_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON_COMPLETE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON_COMPLETE_1_REG+1, &status_reg_temp_l);
	status_registers.ibutton_complite_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON_COMPLETE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON_COMPLETE_2_REG+1, &status_reg_temp_l);
	status_registers.ibutton_complite_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON_COMPLETE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON_COMPLETE_3_REG+1, &status_reg_temp_l);
	status_registers.ibutton_complite_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON_COMPLETE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON_COMPLETE_4_REG+1, &status_reg_temp_l);
	status_registers.ibutton_complite_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON_COMPLETE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON_COMPLETE_5_REG+1, &status_reg_temp_l);
	status_registers.ibutton_complite_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON_COMPLETE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON_COMPLETE_6_REG+1, &status_reg_temp_l);
	status_registers.ibutton_complite_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON_COMPLETE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON_COMPLETE_7_REG+1, &status_reg_temp_l);
	status_registers.ibutton_complite_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*CE_303_ERROR_REG, &status_reg_temp_h);
	fm25v02_read(2*CE_303_ERROR_REG+1, &status_reg_temp_l);
	status_registers.ce303_error_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*CE_303_CURRENT_A_REG, &status_reg_temp_h);
	fm25v02_read(2*CE_303_CURRENT_A_REG+1, &status_reg_temp_l);
	status_registers.ce303_current_a_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*CE_303_CURRENT_B_REG, &status_reg_temp_h);
	fm25v02_read(2*CE_303_CURRENT_B_REG+1, &status_reg_temp_l);
	status_registers.ce303_current_b_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*CE_303_CURRENT_C_REG, &status_reg_temp_h);
	fm25v02_read(2*CE_303_CURRENT_C_REG+1, &status_reg_temp_l);
	status_registers.ce303_current_c_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*CE_303_CURRENT_MIL_A_REG, &status_reg_temp_h);
	fm25v02_read(2*CE_303_CURRENT_MIL_A_REG+1, &status_reg_temp_l);
	status_registers.ce303_current_mil_a_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*CE_303_CURRENT_MIL_B_REG, &status_reg_temp_h);
	fm25v02_read(2*CE_303_CURRENT_MIL_B_REG+1, &status_reg_temp_l);
	status_registers.ce303_current_mil_b_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*CE_303_CURRENT_MIL_C_REG, &status_reg_temp_h);
	fm25v02_read(2*CE_303_CURRENT_MIL_C_REG+1, &status_reg_temp_l);
	status_registers.ce303_current_mil_c_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*CE_303_VOLT_A_REG, &status_reg_temp_h);
	fm25v02_read(2*CE_303_VOLT_A_REG+1, &status_reg_temp_l);
	status_registers.ce303_volt_a_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*CE_303_VOLT_B_REG, &status_reg_temp_h);
	fm25v02_read(2*CE_303_VOLT_B_REG+1, &status_reg_temp_l);
	status_registers.ce303_volt_b_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*CE_303_VOLT_C_REG, &status_reg_temp_h);
	fm25v02_read(2*CE_303_VOLT_C_REG+1, &status_reg_temp_l);
	status_registers.ce303_volt_c_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*CE_303_VOLT_MIL_A_REG, &status_reg_temp_h);
	fm25v02_read(2*CE_303_VOLT_MIL_A_REG+1, &status_reg_temp_l);
	status_registers.ce303_volt_mil_a_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*CE_303_VOLT_MIL_B_REG, &status_reg_temp_h);
	fm25v02_read(2*CE_303_VOLT_MIL_B_REG+1, &status_reg_temp_l);
	status_registers.ce303_volt_mil_b_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*CE_303_VOLT_MIL_C_REG, &status_reg_temp_h);
	fm25v02_read(2*CE_303_VOLT_MIL_C_REG+1, &status_reg_temp_l);
	status_registers.ce303_volt_mil_c_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*CE_303_POWER_A_REG, &status_reg_temp_h);
	fm25v02_read(2*CE_303_POWER_A_REG+1, &status_reg_temp_l);
	status_registers.ce303_power_a_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*CE_303_POWER_B_REG, &status_reg_temp_h);
	fm25v02_read(2*CE_303_POWER_B_REG+1, &status_reg_temp_l);
	status_registers.ce303_power_b_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*CE_303_POWER_C_REG, &status_reg_temp_h);
	fm25v02_read(2*CE_303_POWER_C_REG+1, &status_reg_temp_l);
	status_registers.ce303_power_c_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*CE_303_POWER_MIL_A_REG, &status_reg_temp_h);
	fm25v02_read(2*CE_303_POWER_MIL_A_REG+1, &status_reg_temp_l);
	status_registers.ce303_power_mil_a_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*CE_303_POWER_MIL_B_REG, &status_reg_temp_h);
	fm25v02_read(2*CE_303_POWER_MIL_B_REG+1, &status_reg_temp_l);
	status_registers.ce303_power_mil_b_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*CE_303_POWER_MIL_C_REG, &status_reg_temp_h);
	fm25v02_read(2*CE_303_POWER_MIL_C_REG+1, &status_reg_temp_l);
	status_registers.ce303_power_mil_c_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*LIGHTING_STATUS_REG, &status_reg_temp_h);
	//fm25v02_read(2*LIGHTING_STATUS_REG+1, &status_reg_temp_l);
	//status_registers.lighting_status_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*LIGHTING_ALARM_REG, &status_reg_temp_h);
	//fm25v02_read(2*LIGHTING_ALARM_REG+1, &status_reg_temp_l);
	//status_registers.lighting_alarm_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*MONTH_LIGHTING_OFF_REG, &status_reg_temp_h);
	//fm25v02_read(2*MONTH_LIGHTING_OFF_REG+1, &status_reg_temp_l);
	//status_registers.month_lighting_off_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*DAY_LIGHTING_OFF_REG, &status_reg_temp_h);
	//fm25v02_read(2*DAY_LIGHTING_OFF_REG+1, &status_reg_temp_l);
	//status_registers.day_lighting_off_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*HOUR_LIGHTING_OFF_REG, &status_reg_temp_h);
	//fm25v02_read(2*HOUR_LIGHTING_OFF_REG+1, &status_reg_temp_l);
	//status_registers.hour_lighting_off_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*MINUTE_LIGHTING_OFF_REG, &status_reg_temp_h);
	//fm25v02_read(2*MINUTE_LIGHTING_OFF_REG+1, &status_reg_temp_l);
	//status_registers.minute_lighting_off_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*MONTH_LIGHTING_ON_REG, &status_reg_temp_h);
	//fm25v02_read(2*MONTH_LIGHTING_ON_REG+1, &status_reg_temp_l);
	//status_registers.month_lighting_on_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*DAY_LIGHTING_ON_REG, &status_reg_temp_h);
	//fm25v02_read(2*DAY_LIGHTING_ON_REG+1, &status_reg_temp_l);
	//status_registers.day_lighting_on_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*HOUR_LIGHTING_ON_REG, &status_reg_temp_h);
	//fm25v02_read(2*HOUR_LIGHTING_ON_REG+1, &status_reg_temp_l);
	//status_registers.hour_lighting_on_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*MINUTE_LIGHTING_ON_REG, &status_reg_temp_h);
	//fm25v02_read(2*MINUTE_LIGHTING_ON_REG+1, &status_reg_temp_l);
	//status_registers.minute_lighting_on_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*CURRENT_PHASE_A_REG, &status_reg_temp_h);
	//fm25v02_read(2*CURRENT_PHASE_A_REG+1, &status_reg_temp_l);
	//status_registers.current_phase_a_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*CURRENT_PHASE_B_REG, &status_reg_temp_h);
	//fm25v02_read(2*CURRENT_PHASE_B_REG+1, &status_reg_temp_l);
	//status_registers.current_phase_b_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*CURRENT_PHASE_C_REG, &status_reg_temp_h);
	//fm25v02_read(2*CURRENT_PHASE_C_REG+1, &status_reg_temp_l);
	//status_registers.current_phase_c_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*CURRENT_VOLTAGE_A_REG, &status_reg_temp_h);
	//fm25v02_read(2*CURRENT_VOLTAGE_A_REG+1, &status_reg_temp_l);
	//status_registers.current_voltage_a_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*CURRENT_VOLTAGE_B_REG, &status_reg_temp_h);
	//fm25v02_read(2*CURRENT_VOLTAGE_B_REG+1, &status_reg_temp_l);
	//status_registers.current_voltage_b_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*CURRENT_VOLTAGE_C_REG, &status_reg_temp_h);
	//fm25v02_read(2*CURRENT_VOLTAGE_C_REG+1, &status_reg_temp_l);
	//status_registers.current_voltage_c_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*CE_303_TOTAL_POWER_H_REG, &status_reg_temp_h);
	fm25v02_read(2*CE_303_TOTAL_POWER_H_REG+1, &status_reg_temp_l);
	status_registers.ce303_total_power_h_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*CE_303_TOTAL_POWER_L_REG, &status_reg_temp_h);
	fm25v02_read(2*CE_303_TOTAL_POWER_L_REG+1, &status_reg_temp_l);
	status_registers.ce303_total_power_l_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*CE_303_TOTAL_POWER_M_REG, &status_reg_temp_h);
	fm25v02_read(2*CE_303_TOTAL_POWER_M_REG+1, &status_reg_temp_l);
	status_registers.ce303_total_power_m_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*CE_303_TARIF1_POWER_H_REG, &status_reg_temp_h);
	fm25v02_read(2*CE_303_TARIF1_POWER_H_REG+1, &status_reg_temp_l);
	status_registers.ce303_tarif1_power_h_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*CE_303_TARIF1_POWER_L_REG, &status_reg_temp_h);
	fm25v02_read(2*CE_303_TARIF1_POWER_L_REG+1, &status_reg_temp_l);
	status_registers.ce303_tarif1_power_l_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*CE_303_TARIF1_POWER_MIL_REG, &status_reg_temp_h);
	fm25v02_read(2*CE_303_TARIF1_POWER_MIL_REG+1, &status_reg_temp_l);
	status_registers.ce303_tarif1_power_mil_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*CE_303_TARIF2_POWER_H_REG, &status_reg_temp_h);
	fm25v02_read(2*CE_303_TARIF2_POWER_H_REG+1, &status_reg_temp_l);
	status_registers.ce303_tarif2_power_h_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*CE_303_TARIF2_POWER_L_REG, &status_reg_temp_h);
	fm25v02_read(2*CE_303_TARIF2_POWER_L_REG+1, &status_reg_temp_l);
	status_registers.ce303_tarif2_power_l_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*CE_303_TARIF2_POWER_MIL_REG, &status_reg_temp_h);
	fm25v02_read(2*CE_303_TARIF2_POWER_MIL_REG+1, &status_reg_temp_l);
	status_registers.ce303_tarif2_power_mil_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*CE_303_TARIF3_POWER_H_REG, &status_reg_temp_h);
	fm25v02_read(2*CE_303_TARIF3_POWER_H_REG+1, &status_reg_temp_l);
	status_registers.ce303_tarif3_power_h_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*CE_303_TARIF3_POWER_L_REG, &status_reg_temp_h);
	fm25v02_read(2*CE_303_TARIF3_POWER_L_REG+1, &status_reg_temp_l);
	status_registers.ce303_tarif3_power_l_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*CE_303_TARIF3_POWER_MIL_REG, &status_reg_temp_h);
	fm25v02_read(2*CE_303_TARIF3_POWER_MIL_REG+1, &status_reg_temp_l);
	status_registers.ce303_tarif3_power_mil_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*CE_303_TARIF4_POWER_H_REG, &status_reg_temp_h);
	//fm25v02_read(2*CE_303_TARIF4_POWER_H_REG+1, &status_reg_temp_l);
	//status_registers.ce303_tarif4_power_h_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*CE_303_TARIF4_POWER_L_REG, &status_reg_temp_h);
	//fm25v02_read(2*CE_303_TARIF4_POWER_L_REG+1, &status_reg_temp_l);
	//status_registers.ce303_tarif4_power_l_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*CE_303_TARIF4_POWER_MIL_REG, &status_reg_temp_h);
	//fm25v02_read(2*CE_303_TARIF4_POWER_MIL_REG+1, &status_reg_temp_l);
	//status_registers.ce303_tarif4_power_mil_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*CE_303_TARIF5_POWER_H_REG, &status_reg_temp_h);
	//fm25v02_read(2*CE_303_TARIF5_POWER_H_REG+1, &status_reg_temp_l);
	//status_registers.ce303_tarif5_power_h_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*CE_303_TARIF5_POWER_L_REG, &status_reg_temp_h);
	//fm25v02_read(2*CE_303_TARIF5_POWER_L_REG+1, &status_reg_temp_l);
	//status_registers.ce303_tarif5_power_l_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*CE_303_TARIF5_POWER_MIL_REG, &status_reg_temp_h);
	//fm25v02_read(2*CE_303_TARIF5_POWER_MIL_REG+1, &status_reg_temp_l);
	//status_registers.ce303_tarif5_power_mil_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*SIGNAL_LEVEL_REG, &status_reg_temp_h);
	fm25v02_read(2*SIGNAL_LEVEL_REG+1, &status_reg_temp_l);
	status_registers.signal_level_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*ADVANCED_LOOP_REG, &status_reg_temp_h);
	//fm25v02_read(2*ADVANCED_LOOP_REG+1, &status_reg_temp_l);
	//status_registers.advanced_loop_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*ADDITIONAL_INPUT_REG1, &status_reg_temp_h);
	//fm25v02_read(2*ADDITIONAL_INPUT_REG1+1, &status_reg_temp_l);
	//status_registers.additional_input_reg1 = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*ADDITIONAL_INPUT_REG2, &status_reg_temp_h);
	//fm25v02_read(2*ADDITIONAL_INPUT_REG2+1, &status_reg_temp_l);
	//status_registers.additional_input_reg2 = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*ICCID_NUMBER_REG1, &status_reg_temp_h);
	fm25v02_read(2*ICCID_NUMBER_REG1+1, &status_reg_temp_l);
	status_registers.iccid_number_reg1 = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*ICCID_NUMBER_REG2, &status_reg_temp_h);
	fm25v02_read(2*ICCID_NUMBER_REG2+1, &status_reg_temp_l);
	status_registers.iccid_number_reg2 = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*ICCID_NUMBER_REG3, &status_reg_temp_h);
	fm25v02_read(2*ICCID_NUMBER_REG3+1, &status_reg_temp_l);
	status_registers.iccid_number_reg3 = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*ICCID_NUMBER_REG4, &status_reg_temp_h);
	fm25v02_read(2*ICCID_NUMBER_REG4+1, &status_reg_temp_l);
	status_registers.iccid_number_reg4 = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*ICCID_NUMBER_REG5, &status_reg_temp_h);
	fm25v02_read(2*ICCID_NUMBER_REG5+1, &status_reg_temp_l);
	status_registers.iccid_number_reg5 = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*ICCID_NUMBER_REG6, &status_reg_temp_h);
	fm25v02_read(2*ICCID_NUMBER_REG6+1, &status_reg_temp_l);
	status_registers.iccid_number_reg6 = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*ICCID_NUMBER_REG7, &status_reg_temp_h);
	fm25v02_read(2*ICCID_NUMBER_REG7+1, &status_reg_temp_l);
	status_registers.iccid_number_reg7 = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*ICCID_NUMBER_REG8, &status_reg_temp_h);
	fm25v02_read(2*ICCID_NUMBER_REG8+1, &status_reg_temp_l);
	status_registers.iccid_number_reg8 = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	osMutexRelease(Fm25v02MutexHandle);
}
//----------------------------------------------------------------

//----Функция чтения из памяти управляющих регистров--------------
void read_control_registers(void)
{
	uint8_t status_reg_temp_h;
	uint8_t status_reg_temp_l;

	osMutexWait(Fm25v02MutexHandle, osWaitForever);

	fm25v02_read(2*SECURITY_CONTROL_REG, &status_reg_temp_h);
	fm25v02_read(2*SECURITY_CONTROL_REG+1, &status_reg_temp_l);
	control_registers.security_control_reg = ((((uint16_t)status_reg_temp_h)&0x00FF)<<8)|(((uint16_t)status_reg_temp_l)&0x00FF);

	fm25v02_read(2*CONTROL_LOOP_REG, &status_reg_temp_h);
	fm25v02_read(2*CONTROL_LOOP_REG+1, &status_reg_temp_l);
	control_registers.control_loop_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*FILTER_TIME_LOOP_REG, &status_reg_temp_h);
	//fm25v02_read(2*FILTER_TIME_LOOP_REG+1, &status_reg_temp_l);
	//control_registers.filter_time_loop_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*QUANTITY_FALSE_LOOP_REG, &status_reg_temp_h);
	//fm25v02_read(2*QUANTITY_FALSE_LOOP_REG+1, &status_reg_temp_l);
	//control_registers.quantity_false_loop_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*TIME_FALSE_LOOP_REG, &status_reg_temp_h);
	//fm25v02_read(2*TIME_FALSE_LOOP_REG+1, &status_reg_temp_l);
	//control_registers.time_false_loop_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*ALARM_LOOP_CLEAR_REG, &status_reg_temp_h);
	fm25v02_read(2*ALARM_LOOP_CLEAR_REG+1, &status_reg_temp_l);
	control_registers.alarm_loop_clear_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*FALSE_LOOP_CLEAR_REG, &status_reg_temp_h);
	fm25v02_read(2*FALSE_LOOP_CLEAR_REG+1, &status_reg_temp_l);
	control_registers.false_loop_clear_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*SECURITY_TIME_MAX_REG, &status_reg_temp_h);
	//fm25v02_read(2*SECURITY_TIME_MAX_REG+1, &status_reg_temp_l);
	//control_registers.security_time_max_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*TIME_UPDATE_REG, &status_reg_temp_h);
	fm25v02_read(2*TIME_UPDATE_REG+1, &status_reg_temp_l);
	control_registers.time_update_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*TIME_YEAR_REG, &status_reg_temp_h);
	fm25v02_read(2*TIME_YEAR_REG+1, &status_reg_temp_l);
	control_registers.time_year_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*TIME_MONTH_REG, &status_reg_temp_h);
	fm25v02_read(2*TIME_MONTH_REG+1, &status_reg_temp_l);
	control_registers.time_month_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*TIME_DAY_REG, &status_reg_temp_h);
	fm25v02_read(2*TIME_DAY_REG+1, &status_reg_temp_l);
	control_registers.time_day_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*TIME_HOUR_REG, &status_reg_temp_h);
	fm25v02_read(2*TIME_HOUR_REG+1, &status_reg_temp_l);
	control_registers.time_hour_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*TIME_MINUTE_REG, &status_reg_temp_h);
	fm25v02_read(2*TIME_MINUTE_REG+1, &status_reg_temp_l);
	control_registers.time_minute_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*TIME_SECONDS_REG, &status_reg_temp_h);
	fm25v02_read(2*TIME_SECONDS_REG+1, &status_reg_temp_l);
	control_registers.time_seconds_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*TIME_WEEKDAY_REG, &status_reg_temp_h);
	fm25v02_read(2*TIME_WEEKDAY_REG+1, &status_reg_temp_l);
	control_registers.time_weekday_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*MODBUS_IDLE_TIME_MAX_REG, &status_reg_temp_h);
	//fm25v02_read(2*MODBUS_IDLE_TIME_MAX_REG+1, &status_reg_temp_l);
	//control_registers.modbus_idle_time_max_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*TIME_CONNECTION_TEST_REG, &status_reg_temp_h);
	//fm25v02_read(2*TIME_CONNECTION_TEST_REG+1, &status_reg_temp_l);
	//control_registers.time_connection_test_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*EVENT_READ_REG, &status_reg_temp_h);
	fm25v02_read(2*EVENT_READ_REG+1, &status_reg_temp_l);
	control_registers.event_read_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*EVENT_ADDRESS_HIGH_REG, &status_reg_temp_h);
	fm25v02_read(2*EVENT_ADDRESS_HIGH_REG+1, &status_reg_temp_l);
	control_registers.event_address_high_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*EVENT_ADDRESS_LOW_REG, &status_reg_temp_h);
	fm25v02_read(2*EVENT_ADDRESS_LOW_REG+1, &status_reg_temp_l);
	control_registers.event_address_low_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*MODEM_RING_TRY_LOAD_REG, &status_reg_temp_h);
	//fm25v02_read(2*MODEM_RING_TRY_LOAD_REG+1, &status_reg_temp_l);
	//control_registers.modem_ring_try_load_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*MODEM_RING_PAUSE_LOAD_REG, &status_reg_temp_h);
	//fm25v02_read(2*MODEM_RING_PAUSE_LOAD_REG+1, &status_reg_temp_l);
	//control_registers.modem_ring_pause_load_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*MODEM_RING_PAUSE2_LOAD_REG, &status_reg_temp_h);
	//fm25v02_read(2*MODEM_RING_PAUSE2_LOAD_REG+1, &status_reg_temp_l);
	//control_registers.modem_ring_pause2_load_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*RING_MINUTE_TIME_REG, &status_reg_temp_h);
	//fm25v02_read(2*RING_MINUTE_TIME_REG+1, &status_reg_temp_l);
	//control_registers.ring_minute_time_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*RING_HOUR_TIME_REG, &status_reg_temp_h);
	//fm25v02_read(2*RING_HOUR_TIME_REG+1, &status_reg_temp_l);
	//control_registers.ring_hour_time_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*ID_HIGH_REG, &status_reg_temp_h);
	fm25v02_read(2*ID_HIGH_REG+1, &status_reg_temp_l);
	control_registers.id_high_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*ID_LOW_REG, &status_reg_temp_h);
	fm25v02_read(2*ID_LOW_REG+1, &status_reg_temp_l);
	control_registers.id_low_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*RESET_CONTROL_REG, &status_reg_temp_h);
	fm25v02_read(2*RESET_CONTROL_REG+1, &status_reg_temp_l);
	control_registers.reset_control_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*METER_POLLING_REG, &status_reg_temp_h);
	fm25v02_read(2*METER_POLLING_REG+1, &status_reg_temp_l);
	control_registers.meter_polling_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IP_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IP_1_REG+1, &status_reg_temp_l);
	control_registers.ip1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IP_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IP_2_REG+1, &status_reg_temp_l);
	control_registers.ip2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IP_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IP_3_REG+1, &status_reg_temp_l);
	control_registers.ip3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IP_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IP_4_REG+1, &status_reg_temp_l);
	control_registers.ip4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*PORT_HIGH_REG, &status_reg_temp_h);
	fm25v02_read(2*PORT_HIGH_REG+1, &status_reg_temp_l);
	control_registers.port_high_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*PORT_LOW_REG, &status_reg_temp_h);
	fm25v02_read(2*PORT_LOW_REG+1, &status_reg_temp_l);
	control_registers.port_low_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*METER_ID_HIGH_REG, &status_reg_temp_h);
	fm25v02_read(2*METER_ID_HIGH_REG+1, &status_reg_temp_l);
	control_registers.meter_id_high_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*METER_ID_LOW_REG, &status_reg_temp_h);
	fm25v02_read(2*METER_ID_LOW_REG+1, &status_reg_temp_l);
	control_registers.meter_id_low_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*GPRS_CALL_REG, &status_reg_temp_h);
	fm25v02_read(2*GPRS_CALL_REG+1, &status_reg_temp_l);
	control_registers.gprs_call_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*MUTE_REG, &status_reg_temp_h);
	fm25v02_read(2*MUTE_REG+1, &status_reg_temp_l);
	control_registers.mute_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*LIGHT_CONTROL_REG, &status_reg_temp_h);
	//fm25v02_read(2*LIGHT_CONTROL_REG+1, &status_reg_temp_l);
	//control_registers.light_control_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*LIGHTING_ALARM_RESET_REG, &status_reg_temp_h);
	//fm25v02_read(2*LIGHTING_ALARM_RESET_REG+1, &status_reg_temp_l);
	//control_registers.lighting_alarm_reset_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*CURRENT_MEASUREMENT_ACCURACY_REG, &status_reg_temp_h);
	//fm25v02_read(2*CURRENT_MEASUREMENT_ACCURACY_REG+1, &status_reg_temp_l);
	//control_registers.current_measurement_accuracy_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*MAX_CURRENT_PHASE_A, &status_reg_temp_h);
	//fm25v02_read(2*MAX_CURRENT_PHASE_A+1, &status_reg_temp_l);
	//control_registers.max_current_phase_a = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*MAX_CURRENT_PHASE_B, &status_reg_temp_h);
	//fm25v02_read(2*MAX_CURRENT_PHASE_B+1, &status_reg_temp_l);
	//control_registers.max_current_phase_b = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*MAX_CURRENT_PHASE_C, &status_reg_temp_h);
	//fm25v02_read(2*MAX_CURRENT_PHASE_C+1, &status_reg_temp_l);
	//control_registers.max_current_phase_c = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*LIGHTING_SWITCHING_REG, &status_reg_temp_h);
	//fm25v02_read(2*LIGHTING_SWITCHING_REG+1, &status_reg_temp_l);
	//control_registers.lighting_switching_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	//fm25v02_read(2*ALARM_SWITCHING_REG, &status_reg_temp_h);
	//fm25v02_read(2*ALARM_SWITCHING_REG+1, &status_reg_temp_l);
	//control_registers.alarm_switching_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*ARMING_TIMELEFT, &status_reg_temp_h);
	fm25v02_read(2*ARMING_TIMELEFT+1, &status_reg_temp_l);
	control_registers.arming_timeleft_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	osMutexRelease(Fm25v02MutexHandle);

}
//----------------------------------------------------------------

//----Функция чтения из памяти регистров бутлоадера---------------

void read_bootloader_registers(void)
{
	uint8_t status_reg_temp_h;
	uint8_t status_reg_temp_l;

	osMutexWait(Fm25v02MutexHandle, osWaitForever);

	//fm25v02_read(2*BOOTLOADER_VERSION_REG, &status_reg_temp_h);
	//fm25v02_read(2*BOOTLOADER_VERSION_REG+1, &status_reg_temp_l);
	//bootloader_registers.bootloader_version_reg = ((((uint16_t)status_reg_temp_h)&0x00FF)<<8)|(((uint16_t)status_reg_temp_l)&0x00FF);

	//fm25v02_read(2*START_ADDRESS_FIRMWARE_HIGH_REG, &status_reg_temp_h);
	//fm25v02_read(2*START_ADDRESS_FIRMWARE_HIGH_REG+1, &status_reg_temp_l);
	//bootloader_registers.start_address_firmware_high_reg = ((((uint16_t)status_reg_temp_h)&0x00FF)<<8)|(((uint16_t)status_reg_temp_l)&0x00FF);

	//fm25v02_read(2*START_ADDRESS_FIRMWARE_2_REG, &status_reg_temp_h);
	//fm25v02_read(2*START_ADDRESS_FIRMWARE_2_REG+1, &status_reg_temp_l);
	//bootloader_registers.start_address_firmware_2_reg = ((((uint16_t)status_reg_temp_h)&0x00FF)<<8)|(((uint16_t)status_reg_temp_l)&0x00FF);

	//fm25v02_read(2*START_ADDRESS_FIRMWARE_3_REG, &status_reg_temp_h);
	//fm25v02_read(2*START_ADDRESS_FIRMWARE_3_REG+1, &status_reg_temp_l);
	//bootloader_registers.start_address_firmware_3_reg = ((((uint16_t)status_reg_temp_h)&0x00FF)<<8)|(((uint16_t)status_reg_temp_l)&0x00FF);

	//fm25v02_read(2*START_ADDRESS_FIRMWARE_LOW_REG, &status_reg_temp_h);
	//fm25v02_read(2*START_ADDRESS_FIRMWARE_LOW_REG+1, &status_reg_temp_l);
	//bootloader_registers.start_address_firmware_low_reg = ((((uint16_t)status_reg_temp_h)&0x00FF)<<8)|(((uint16_t)status_reg_temp_l)&0x00FF);

	//fm25v02_read(2*END_ADDRESS_FIRMWARE_HIGH_REG, &status_reg_temp_h);
	//fm25v02_read(2*END_ADDRESS_FIRMWARE_HIGH_REG+1, &status_reg_temp_l);
	//bootloader_registers.end_address_firmware_high_reg = ((((uint16_t)status_reg_temp_h)&0x00FF)<<8)|(((uint16_t)status_reg_temp_l)&0x00FF);

	//fm25v02_read(2*END_ADDRESS_FIRMWARE_LOW_REG, &status_reg_temp_h);
	//fm25v02_read(2*END_ADDRESS_FIRMWARE_LOW_REG+1, &status_reg_temp_l);
	//bootloader_registers.end_address_firmware_low_reg = ((((uint16_t)status_reg_temp_h)&0x00FF)<<8)|(((uint16_t)status_reg_temp_l)&0x00FF);

	//fm25v02_read(2*CRC_FIRMWARE_HIGH_REG, &status_reg_temp_h);
	//fm25v02_read(2*CRC_FIRMWARE_HIGH_REG+1, &status_reg_temp_l);
	//bootloader_registers.crc_firmware_high_reg = ((((uint16_t)status_reg_temp_h)&0x00FF)<<8)|(((uint16_t)status_reg_temp_l)&0x00FF);

	//fm25v02_read(2*CRC_FIRMWARE_LOW_REG, &status_reg_temp_h);
	//fm25v02_read(2*CRC_FIRMWARE_LOW_REG+1, &status_reg_temp_l);
	//bootloader_registers.crc_firmware_low_reg = ((((uint16_t)status_reg_temp_h)&0x00FF)<<8)|(((uint16_t)status_reg_temp_l)&0x00FF);

	//fm25v02_read(2*JUMP_VECTOR_HIGH_REG, &status_reg_temp_h);
	//fm25v02_read(2*JUMP_VECTOR_HIGH_REG+1, &status_reg_temp_l);
	//bootloader_registers.jump_vector_high_reg = ((((uint16_t)status_reg_temp_h)&0x00FF)<<8)|(((uint16_t)status_reg_temp_l)&0x00FF);

	//fm25v02_read(2*JUMP_VECTOR_2_REG, &status_reg_temp_h);
	//fm25v02_read(2*JUMP_VECTOR_2_REG+1, &status_reg_temp_l);
	//bootloader_registers.jump_vector_2_reg = ((((uint16_t)status_reg_temp_h)&0x00FF)<<8)|(((uint16_t)status_reg_temp_l)&0x00FF);

	//fm25v02_read(2*JUMP_VECTOR_3_REG, &status_reg_temp_h);
	//fm25v02_read(2*JUMP_VECTOR_3_REG+1, &status_reg_temp_l);
	//bootloader_registers.jump_vector_3_reg = ((((uint16_t)status_reg_temp_h)&0x00FF)<<8)|(((uint16_t)status_reg_temp_l)&0x00FF);

	//fm25v02_read(2*JUMP_VECTOR_LOW_REG, &status_reg_temp_h);
	//fm25v02_read(2*JUMP_VECTOR_LOW_REG+1, &status_reg_temp_l);
	//bootloader_registers.jump_vector_low_reg = ((((uint16_t)status_reg_temp_h)&0x00FF)<<8)|(((uint16_t)status_reg_temp_l)&0x00FF);

	//fm25v02_read(2*FIRMWARE_CORRECTNESS_REG, &status_reg_temp_h);
	//fm25v02_read(2*FIRMWARE_CORRECTNESS_REG+1, &status_reg_temp_l);
	//bootloader_registers.firmware_correctness_reg = ((((uint16_t)status_reg_temp_h)&0x00FF)<<8)|(((uint16_t)status_reg_temp_l)&0x00FF);

	fm25v02_read(2*WORKING_MODE_REG, &status_reg_temp_h);
	fm25v02_read(2*WORKING_MODE_REG+1, &status_reg_temp_l);
	bootloader_registers.working_mode_reg = ((((uint16_t)status_reg_temp_h)&0x00FF)<<8)|(((uint16_t)status_reg_temp_l)&0x00FF);

	//fm25v02_read(2*READY_DOWNLOAD_REG, &status_reg_temp_h);
	//fm25v02_read(2*READY_DOWNLOAD_REG+1, &status_reg_temp_l);
	//bootloader_registers.ready_download_reg = ((((uint16_t)status_reg_temp_h)&0x00FF)<<8)|(((uint16_t)status_reg_temp_l)&0x00FF);

	//fm25v02_read(2*DOWNLOAD_TIMEOUT_REG, &status_reg_temp_h);
	//fm25v02_read(2*DOWNLOAD_TIMEOUT_REG+1, &status_reg_temp_l);
	//bootloader_registers.download_timeout_reg = ((((uint16_t)status_reg_temp_h)&0x00FF)<<8)|(((uint16_t)status_reg_temp_l)&0x00FF);

	//fm25v02_read(2*JUMP_ATTEMPT_REG, &status_reg_temp_h);
	//fm25v02_read(2*JUMP_ATTEMPT_REG+1, &status_reg_temp_l);
	//bootloader_registers.jump_attempt_reg = ((((uint16_t)status_reg_temp_h)&0x00FF)<<8)|(((uint16_t)status_reg_temp_l)&0x00FF);

	//fm25v02_read(2*MAX_JUMP_ATTEMPT_REG, &status_reg_temp_h);
	//fm25v02_read(2*MAX_JUMP_ATTEMPT_REG+1, &status_reg_temp_l);
	//bootloader_registers.max_jump_attempt_reg = ((((uint16_t)status_reg_temp_h)&0x00FF)<<8)|(((uint16_t)status_reg_temp_l)&0x00FF);

	//fm25v02_read(2*END_ADDRESS_FIRMWARE_2_REG, &status_reg_temp_h);
	//fm25v02_read(2*END_ADDRESS_FIRMWARE_2_REG+1, &status_reg_temp_l);
	//bootloader_registers.end_address_firmware_2_reg = ((((uint16_t)status_reg_temp_h)&0x00FF)<<8)|(((uint16_t)status_reg_temp_l)&0x00FF);

	//fm25v02_read(2*END_ADDRESS_FIRMWARE_3_REG, &status_reg_temp_h);
	//fm25v02_read(2*END_ADDRESS_FIRMWARE_3_REG+1, &status_reg_temp_l);
	//bootloader_registers.end_address_firmware_3_reg = ((((uint16_t)status_reg_temp_h)&0x00FF)<<8)|(((uint16_t)status_reg_temp_l)&0x00FF);

	//fm25v02_read(2*ADDRESS_TO_WRITE_2_REG, &status_reg_temp_h);
	//fm25v02_read(2*ADDRESS_TO_WRITE_2_REG+1, &status_reg_temp_l);
	//bootloader_registers.address_to_write_2_reg = ((((uint16_t)status_reg_temp_h)&0x00FF)<<8)|(((uint16_t)status_reg_temp_l)&0x00FF);

	//fm25v02_read(2*ADDRESS_TO_WRITE_3_REG, &status_reg_temp_h);
	//fm25v02_read(2*ADDRESS_TO_WRITE_3_REG+1, &status_reg_temp_l);
	//bootloader_registers.address_to_write_3_reg = ((((uint16_t)status_reg_temp_h)&0x00FF)<<8)|(((uint16_t)status_reg_temp_l)&0x00FF);

	//fm25v02_read(2*CLEAR_PAGE_NUMBER_REG, &status_reg_temp_h);
	//fm25v02_read(2*CLEAR_PAGE_NUMBER_REG+1, &status_reg_temp_l);
	//bootloader_registers.clear_page_number_reg = ((((uint16_t)status_reg_temp_h)&0x00FF)<<8)|(((uint16_t)status_reg_temp_l)&0x00FF);

	//fm25v02_read(2*CLEAR_PAGE_ON_REG, &status_reg_temp_h);
	//fm25v02_read(2*CLEAR_PAGE_ON_REG+1, &status_reg_temp_l);
	//bootloader_registers.clear_page_on_reg = ((((uint16_t)status_reg_temp_h)&0x00FF)<<8)|(((uint16_t)status_reg_temp_l)&0x00FF);

	//fm25v02_read(2*WRITE_ARRAY_REG, &status_reg_temp_h);
	//fm25v02_read(2*WRITE_ARRAY_REG+1, &status_reg_temp_l);
	//bootloader_registers.write_array_reg = ((((uint16_t)status_reg_temp_h)&0x00FF)<<8)|(((uint16_t)status_reg_temp_l)&0x00FF);

	//fm25v02_read(2*READ_ARRAY_REG, &status_reg_temp_h);
	//fm25v02_read(2*READ_ARRAY_REG+1, &status_reg_temp_l);
	//bootloader_registers.read_array_reg = ((((uint16_t)status_reg_temp_h)&0x00FF)<<8)|(((uint16_t)status_reg_temp_l)&0x00FF);

	//fm25v02_read(2*ADDRESS_TO_WRITE_HIGH_REG, &status_reg_temp_h);
	//fm25v02_read(2*ADDRESS_TO_WRITE_HIGH_REG+1, &status_reg_temp_l);
	//bootloader_registers.address_to_write_high_reg = ((((uint16_t)status_reg_temp_h)&0x00FF)<<8)|(((uint16_t)status_reg_temp_l)&0x00FF);

	//fm25v02_read(2*ADDRESS_TO_WRITE_LOW_REG, &status_reg_temp_h);
	//fm25v02_read(2*ADDRESS_TO_WRITE_LOW_REG+1, &status_reg_temp_l);
	//bootloader_registers.address_to_write_low_reg = ((((uint16_t)status_reg_temp_h)&0x00FF)<<8)|(((uint16_t)status_reg_temp_l)&0x00FF);

	//fm25v02_read(2*BYTE_QUANTITY_REG, &status_reg_temp_h);
	//fm25v02_read(2*BYTE_QUANTITY_REG+1, &status_reg_temp_l);
	//bootloader_registers.byte_quantity_reg = ((((uint16_t)status_reg_temp_h)&0x00FF)<<8)|(((uint16_t)status_reg_temp_l)&0x00FF);

	//fm25v02_read(2*PACKET_CRC_HIGH_REG, &status_reg_temp_h);
	//fm25v02_read(2*PACKET_CRC_HIGH_REG+1, &status_reg_temp_l);
	//bootloader_registers.packet_crc_high_reg = ((((uint16_t)status_reg_temp_h)&0x00FF)<<8)|(((uint16_t)status_reg_temp_l)&0x00FF);

	//fm25v02_read(2*PACKET_CRC_LOW_REG, &status_reg_temp_h);
	//fm25v02_read(2*PACKET_CRC_LOW_REG+1, &status_reg_temp_l);
	//bootloader_registers.packet_crc_low_reg = ((((uint16_t)status_reg_temp_h)&0x00FF)<<8)|(((uint16_t)status_reg_temp_l)&0x00FF);

	//fm25v02_read(2*PACKET_DATA_0_REG, &status_reg_temp_h);
	//fm25v02_read(2*PACKET_DATA_0_REG+1, &status_reg_temp_l);
	//bootloader_registers.packet_data_0_reg = ((((uint16_t)status_reg_temp_h)&0x00FF)<<8)|(((uint16_t)status_reg_temp_l)&0x00FF);

	//fm25v02_read(2*PACKET_DATA_1_REG, &status_reg_temp_h);
	//fm25v02_read(2*PACKET_DATA_1_REG+1, &status_reg_temp_l);
	//bootloader_registers.packet_data_1_reg = ((((uint16_t)status_reg_temp_h)&0x00FF)<<8)|(((uint16_t)status_reg_temp_l)&0x00FF);

	//fm25v02_read(2*PACKET_DATA_2_REG, &status_reg_temp_h);
	//fm25v02_read(2*PACKET_DATA_2_REG+1, &status_reg_temp_l);
	//bootloader_registers.packet_data_2_reg = ((((uint16_t)status_reg_temp_h)&0x00FF)<<8)|(((uint16_t)status_reg_temp_l)&0x00FF);

	//fm25v02_read(2*PACKET_DATA_3_REG, &status_reg_temp_h);
	//fm25v02_read(2*PACKET_DATA_3_REG+1, &status_reg_temp_l);
	//bootloader_registers.packet_data_3_reg = ((((uint16_t)status_reg_temp_h)&0x00FF)<<8)|(((uint16_t)status_reg_temp_l)&0x00FF);

	//fm25v02_read(2*PACKET_DATA_4_REG, &status_reg_temp_h);
	//fm25v02_read(2*PACKET_DATA_4_REG+1, &status_reg_temp_l);
	//bootloader_registers.packet_data_4_reg = ((((uint16_t)status_reg_temp_h)&0x00FF)<<8)|(((uint16_t)status_reg_temp_l)&0x00FF);

	osMutexRelease(Fm25v02MutexHandle);

}
//----------------------------------------------------------------



//----Функция чтения из памяти регистров учетных записей I-button---------------

void read_ibutton_registers(void)
{
	uint8_t status_reg_temp_h;
	uint8_t status_reg_temp_l;

	osMutexWait(Fm25v02MutexHandle, osWaitForever);

	fm25v02_read(2*IBUTTON1_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON1_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton1_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON1_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON1_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton1_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON1_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON1_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton1_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON1_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON1_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton1_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON1_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON1_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton1_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON1_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON1_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton1_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON1_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON1_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton1_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON1_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON1_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton1_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON2_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON2_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton2_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON2_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON2_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton2_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON2_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON2_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton2_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON2_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON2_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton2_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON2_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON2_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton2_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON2_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON2_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton2_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON2_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON2_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton2_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON2_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON2_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton2_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON3_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON3_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton3_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON3_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON3_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton3_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON3_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON3_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton3_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON3_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON3_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton3_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON3_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON3_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton3_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON3_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON3_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton3_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON3_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON3_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton3_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON3_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON3_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton3_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON4_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON4_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton4_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON4_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON4_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton4_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON4_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON4_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton4_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON4_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON4_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton4_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON4_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON4_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton4_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON4_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON4_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton4_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON4_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON4_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton4_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON4_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON4_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton4_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON5_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON5_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton5_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON5_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON5_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton5_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON5_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON5_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton5_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON5_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON5_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton5_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON5_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON5_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton5_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON5_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON5_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton5_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON5_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON5_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton5_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON5_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON5_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton5_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON6_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON6_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton6_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON6_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON6_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton6_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON6_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON6_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton6_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON6_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON6_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton6_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON6_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON6_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton6_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON6_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON6_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton6_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON6_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON6_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton6_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON6_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON6_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton6_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON7_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON7_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton7_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON7_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON7_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton7_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON7_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON7_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton7_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON7_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON7_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton7_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON7_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON7_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton7_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON7_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON7_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton7_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON7_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON7_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton7_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON7_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON7_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton7_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON8_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON8_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton8_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON8_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON8_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton8_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON8_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON8_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton8_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON8_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON8_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton8_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON8_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON8_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton8_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON8_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON8_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton8_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON8_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON8_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton8_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON8_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON8_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton8_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON9_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON9_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton9_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON9_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON9_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton9_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON9_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON9_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton9_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON9_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON9_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton9_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON9_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON9_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton9_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON9_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON9_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton9_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON9_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON9_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton9_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON9_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON9_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton9_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON10_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON10_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton10_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON10_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON10_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton10_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON10_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON10_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton10_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON10_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON10_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton10_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON10_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON10_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton10_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON10_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON10_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton10_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON10_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON10_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton10_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON10_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON10_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton10_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON11_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON11_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton11_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON11_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON11_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton11_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON11_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON11_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton11_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON11_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON11_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton11_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON11_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON11_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton11_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON11_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON11_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton11_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON11_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON11_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton11_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON11_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON11_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton11_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON12_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON12_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton12_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON12_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON12_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton12_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON12_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON12_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton12_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON12_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON12_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton12_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON12_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON12_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton12_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON12_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON12_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton12_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON12_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON12_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton12_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON12_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON12_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton12_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON13_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON13_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton13_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON13_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON13_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton13_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON13_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON13_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton13_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON13_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON13_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton13_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON13_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON13_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton13_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON13_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON13_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton13_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON13_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON13_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton13_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON13_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON13_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton13_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON14_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON14_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton14_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON14_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON14_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton14_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON14_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON14_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton14_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON14_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON14_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton14_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON14_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON14_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton14_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON14_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON14_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton14_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON14_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON14_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton14_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON14_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON14_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton14_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON15_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON15_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton15_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON15_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON15_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton15_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON15_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON15_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton15_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON15_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON15_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton15_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON15_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON15_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton15_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON15_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON15_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton15_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON15_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON15_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton15_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON15_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON15_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton15_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON16_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON16_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton16_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON16_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON16_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton16_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON16_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON16_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton16_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON16_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON16_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton16_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON16_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON16_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton16_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON16_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON16_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton16_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON16_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON16_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton16_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON16_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON16_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton16_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON17_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON17_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton17_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON17_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON17_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton17_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON17_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON17_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton17_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON17_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON17_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton17_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON17_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON17_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton17_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON17_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON17_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton17_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON17_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON17_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton17_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON17_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON17_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton17_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON18_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON18_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton18_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON18_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON18_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton18_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON18_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON18_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton18_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON18_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON18_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton18_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON18_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON18_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton18_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON18_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON18_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton18_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON18_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON18_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton18_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON18_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON18_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton18_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON19_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON19_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton19_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON19_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON19_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton19_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON19_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON19_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton19_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON19_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON19_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton19_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON19_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON19_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton19_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON19_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON19_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton19_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON19_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON19_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton19_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON19_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON19_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton19_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON20_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON20_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton20_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON20_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON20_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton20_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON20_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON20_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton20_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON20_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON20_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton20_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON20_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON20_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton20_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON20_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON20_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton20_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON20_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON20_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton20_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON20_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON20_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton20_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON21_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON21_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton21_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON21_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON21_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton21_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON21_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON21_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton21_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON21_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON21_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton21_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON21_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON21_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton21_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON21_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON21_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton21_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON21_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON21_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton21_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON21_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON21_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton21_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON22_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON22_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton22_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON22_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON22_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton22_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON22_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON22_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton22_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON22_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON22_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton22_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON22_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON22_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton22_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON22_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON22_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton22_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON22_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON22_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton22_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON22_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON22_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton22_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON23_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON23_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton23_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON23_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON23_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton23_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON23_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON23_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton23_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON23_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON23_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton23_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON23_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON23_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton23_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON23_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON23_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton23_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON23_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON23_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton23_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON23_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON23_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton23_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON24_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON24_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton24_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON24_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON24_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton24_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON24_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON24_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton24_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON24_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON24_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton24_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON24_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON24_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton24_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON24_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON24_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton24_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON24_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON24_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton24_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON24_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON24_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton24_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON25_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON25_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton25_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON25_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON25_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton25_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON25_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON25_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton25_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON25_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON25_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton25_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON25_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON25_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton25_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON25_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON25_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton25_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON25_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON25_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton25_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON25_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON25_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton25_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON26_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON26_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton26_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON26_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON26_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton26_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON26_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON26_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton26_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON26_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON26_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton26_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON26_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON26_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton26_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON26_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON26_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton26_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON26_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON26_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton26_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON26_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON26_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton26_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON27_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON27_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton27_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON27_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON27_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton27_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON27_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON27_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton27_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON27_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON27_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton27_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON27_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON27_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton27_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON27_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON27_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton27_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON27_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON27_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton27_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON27_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON27_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton27_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON28_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON28_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton28_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON28_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON28_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton28_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON28_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON28_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton28_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON28_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON28_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton28_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON28_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON28_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton28_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON28_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON28_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton28_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON28_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON28_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton28_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON28_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON28_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton28_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON29_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON29_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton29_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON29_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON29_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton29_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON29_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON29_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton29_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON29_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON29_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton29_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON29_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON29_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton29_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON29_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON29_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton29_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON29_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON29_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton29_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON29_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON29_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton29_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON30_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON30_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton30_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON30_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON30_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton30_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON30_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON30_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton30_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON30_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON30_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton30_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON30_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON30_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton30_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON30_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON30_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton30_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON30_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON30_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton30_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON30_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON30_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton30_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON31_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON31_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton31_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON31_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON31_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton31_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON31_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON31_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton31_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON31_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON31_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton31_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON31_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON31_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton31_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON31_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON31_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton31_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON31_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON31_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton31_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON31_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON31_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton31_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON32_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON32_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton32_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON32_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON32_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton32_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON32_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON32_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton32_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON32_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON32_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton32_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON32_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON32_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton32_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON32_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON32_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton32_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON32_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON32_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton32_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON32_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON32_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton32_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON33_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON33_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton33_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON33_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON33_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton33_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON33_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON33_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton33_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON33_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON33_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton33_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON33_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON33_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton33_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON33_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON33_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton33_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON33_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON33_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton33_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON33_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON33_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton33_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON34_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON34_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton34_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON34_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON34_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton34_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON34_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON34_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton34_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON34_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON34_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton34_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON34_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON34_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton34_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON34_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON34_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton34_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON34_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON34_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton34_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON34_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON34_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton34_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON35_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON35_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton35_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON35_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON35_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton35_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON35_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON35_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton35_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON35_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON35_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton35_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON35_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON35_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton35_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON35_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON35_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton35_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON35_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON35_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton35_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON35_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON35_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton35_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON36_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON36_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton36_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON36_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON36_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton36_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON36_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON36_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton36_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON36_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON36_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton36_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON36_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON36_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton36_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON36_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON36_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton36_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON36_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON36_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton36_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON36_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON36_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton36_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON37_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON37_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton37_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON37_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON37_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton37_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON37_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON37_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton37_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON37_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON37_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton37_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON37_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON37_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton37_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON37_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON37_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton37_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON37_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON37_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton37_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON37_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON37_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton37_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON38_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON38_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton38_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON38_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON38_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton38_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON38_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON38_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton38_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON38_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON38_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton38_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON38_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON38_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton38_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON38_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON38_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton38_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON38_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON38_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton38_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON38_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON38_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton38_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON39_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON39_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton39_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON39_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON39_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton39_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON39_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON39_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton39_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON39_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON39_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton39_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON39_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON39_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton39_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON39_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON39_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton39_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON39_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON39_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton39_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON39_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON39_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton39_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON40_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON40_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton40_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON40_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON40_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton40_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON40_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON40_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton40_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON40_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON40_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton40_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON40_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON40_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton40_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON40_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON40_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton40_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON40_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON40_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton40_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON40_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON40_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton40_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON41_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON41_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton41_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON41_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON41_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton41_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON41_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON41_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton41_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON41_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON41_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton41_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON41_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON41_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton41_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON41_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON41_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton41_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON41_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON41_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton41_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON41_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON41_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton41_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON42_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON42_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton42_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON42_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON42_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton42_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON42_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON42_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton42_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON42_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON42_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton42_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON42_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON42_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton42_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON42_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON42_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton42_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON42_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON42_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton42_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON42_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON42_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton42_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON43_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON43_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton43_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON43_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON43_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton43_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON43_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON43_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton43_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON43_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON43_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton43_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON43_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON43_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton43_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON43_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON43_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton43_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON43_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON43_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton43_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON43_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON43_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton43_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON44_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON44_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton44_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON44_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON44_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton44_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON44_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON44_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton44_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON44_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON44_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton44_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON44_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON44_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton44_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON44_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON44_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton44_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON44_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON44_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton44_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON44_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON44_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton44_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON45_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON45_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton45_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON45_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON45_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton45_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON45_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON45_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton45_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON45_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON45_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton45_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON45_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON45_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton45_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON45_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON45_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton45_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON45_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON45_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton45_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON45_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON45_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton45_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON46_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON46_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton46_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON46_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON46_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton46_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON46_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON46_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton46_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON46_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON46_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton46_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON46_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON46_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton46_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON46_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON46_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton46_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON46_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON46_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton46_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON46_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON46_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton46_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON47_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON47_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton47_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON47_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON47_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton47_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON47_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON47_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton47_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON47_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON47_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton47_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON47_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON47_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton47_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON47_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON47_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton47_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON47_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON47_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton47_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON47_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON47_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton47_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON48_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON48_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton48_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON48_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON48_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton48_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON48_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON48_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton48_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON48_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON48_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton48_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON48_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON48_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton48_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON48_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON48_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton48_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON48_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON48_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton48_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON48_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON48_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton48_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON49_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON49_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton49_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON49_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON49_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton49_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON49_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON49_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton49_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON49_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON49_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton49_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON49_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON49_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton49_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON49_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON49_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton49_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON49_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON49_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton49_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON49_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON49_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton49_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON50_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON50_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton50_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON50_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON50_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton50_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON50_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON50_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton50_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON50_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON50_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton50_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON50_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON50_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton50_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON50_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON50_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton50_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON50_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON50_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton50_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON50_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON50_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton50_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON51_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON51_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton51_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON51_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON51_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton51_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON51_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON51_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton51_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON51_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON51_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton51_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON51_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON51_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton51_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON51_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON51_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton51_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON51_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON51_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton51_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON51_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON51_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton51_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON52_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON52_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton52_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON52_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON52_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton52_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON52_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON52_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton52_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON52_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON52_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton52_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON52_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON52_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton52_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON52_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON52_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton52_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON52_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON52_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton52_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON52_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON52_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton52_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON53_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON53_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton53_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON53_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON53_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton53_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON53_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON53_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton53_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON53_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON53_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton53_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON53_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON53_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton53_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON53_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON53_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton53_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON53_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON53_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton53_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON53_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON53_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton53_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON54_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON54_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton54_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON54_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON54_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton54_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON54_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON54_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton54_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON54_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON54_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton54_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON54_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON54_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton54_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON54_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON54_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton54_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON54_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON54_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton54_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON54_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON54_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton54_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON55_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON55_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton55_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON55_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON55_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton55_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON55_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON55_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton55_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON55_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON55_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton55_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON55_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON55_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton55_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON55_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON55_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton55_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON55_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON55_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton55_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON55_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON55_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton55_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON56_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON56_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton56_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON56_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON56_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton56_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON56_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON56_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton56_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON56_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON56_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton56_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON56_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON56_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton56_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON56_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON56_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton50_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON56_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON56_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton56_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON56_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON56_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton56_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON57_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON57_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton57_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON57_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON57_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton57_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON57_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON57_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton57_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON57_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON57_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton57_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON57_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON57_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton57_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON57_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON57_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton57_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON57_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON57_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton57_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON57_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON57_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton57_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON58_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON58_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton58_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON58_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON58_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton58_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON58_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON58_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton58_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON58_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON58_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton58_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON58_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON58_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton58_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON58_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON58_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton58_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON58_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON58_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton58_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON58_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON58_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton58_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON59_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON59_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton59_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON59_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON59_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton59_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON59_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON59_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton59_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON59_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON59_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton59_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON59_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON59_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton59_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON59_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON59_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton59_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON59_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON59_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton59_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON59_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON59_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton59_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON60_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON60_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton60_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON60_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON60_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton60_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON60_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON60_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton60_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON60_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON60_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton60_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON60_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON60_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton60_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON60_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON60_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton60_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON60_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON60_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton60_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON60_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON60_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton60_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON61_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON61_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton61_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON61_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON61_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton61_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON61_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON61_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton61_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON61_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON61_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton61_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON61_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON61_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton61_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON61_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON61_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton61_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON61_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON61_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton61_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON61_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON61_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton61_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON62_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON62_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton62_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON62_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON62_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton62_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON62_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON62_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton62_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON62_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON62_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton62_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON62_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON62_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton62_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON62_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON62_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton62_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON62_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON62_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton62_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON62_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON62_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton62_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON63_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON63_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton63_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON63_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON63_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton63_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON63_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON63_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton63_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON63_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON63_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton63_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON63_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON63_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton63_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON63_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON63_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton63_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON63_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON63_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton63_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON63_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON63_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton63_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON64_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON64_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton64_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON64_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON64_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton64_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON64_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON64_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton64_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON64_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON64_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton64_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON64_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON64_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton64_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON64_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON64_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton64_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON64_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON64_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton64_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON64_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON64_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton64_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON65_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON65_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton65_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON65_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON65_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton65_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON65_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON65_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton65_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON65_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON65_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton65_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON65_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON65_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton65_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON65_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON65_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton65_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON65_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON65_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton65_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON65_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON65_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton65_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON66_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON66_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton66_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON66_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON66_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton66_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON66_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON66_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton66_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON66_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON66_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton66_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON66_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON66_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton66_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON66_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON66_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton66_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON66_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON66_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton66_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON66_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON66_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton66_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON67_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON67_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton67_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON67_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON67_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton67_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON67_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON67_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton67_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON67_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON67_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton67_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON67_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON67_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton67_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON67_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON67_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton67_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON67_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON67_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton67_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON67_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON67_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton67_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON68_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON68_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton68_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON68_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON68_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton68_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON68_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON68_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton68_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON68_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON68_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton68_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON68_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON68_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton68_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON68_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON68_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton68_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON68_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON68_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton68_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON68_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON68_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton68_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON69_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON69_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton69_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON69_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON69_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton69_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON69_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON69_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton69_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON69_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON69_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton69_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON69_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON69_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton69_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON69_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON69_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton69_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON69_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON69_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton69_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON69_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON69_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton69_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON70_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON70_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton70_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON70_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON70_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton70_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON70_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON70_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton70_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON70_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON70_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton70_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON70_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON70_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton70_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON70_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON70_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton70_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON70_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON70_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton70_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON70_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON70_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton70_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON71_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON71_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton71_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON71_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON71_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton71_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON71_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON71_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton71_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON71_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON71_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton71_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON71_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON71_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton71_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON71_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON71_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton71_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON71_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON71_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton71_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON71_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON71_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton71_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON72_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON72_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton72_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON72_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON72_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton72_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON72_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON72_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton72_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON72_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON72_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton72_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON72_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON72_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton72_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON72_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON72_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton72_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON72_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON72_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton72_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON72_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON72_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton72_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON73_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON73_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton73_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON73_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON73_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton73_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON73_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON73_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton73_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON73_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON73_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton73_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON73_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON73_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton73_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON73_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON73_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton73_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON73_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON73_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton73_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON73_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON73_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton73_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON74_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON74_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton74_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON74_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON74_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton74_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON74_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON74_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton74_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON74_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON74_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton74_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON74_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON74_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton74_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON74_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON74_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton74_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON74_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON74_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton74_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON74_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON74_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton74_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON75_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON75_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton75_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON75_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON75_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton75_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON75_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON75_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton75_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON75_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON75_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton75_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON75_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON75_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton75_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON75_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON75_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton75_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON75_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON75_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton75_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON75_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON75_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton75_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON76_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON76_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton76_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON76_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON76_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton76_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON76_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON76_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton76_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON76_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON76_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton76_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON76_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON76_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton76_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON76_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON76_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton76_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON76_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON76_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton76_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON76_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON76_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton76_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON77_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON77_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton77_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON77_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON77_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton77_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON77_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON77_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton77_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON77_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON77_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton77_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON77_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON77_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton77_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON77_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON77_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton77_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON77_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON77_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton77_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON77_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON77_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton77_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON78_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON78_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton78_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON78_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON78_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton78_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON78_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON78_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton78_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON78_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON78_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton78_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON78_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON78_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton78_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON78_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON78_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton78_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON78_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON78_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton78_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON78_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON78_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton78_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON79_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON79_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton79_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON79_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON79_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton79_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON79_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON79_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton79_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON79_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON79_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton79_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON79_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON79_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton79_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON79_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON79_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton79_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON79_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON79_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton79_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON79_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON79_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton79_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON80_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON80_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton80_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON80_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON80_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton80_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON80_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON80_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton80_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON80_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON80_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton80_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON80_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON80_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton80_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON80_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON80_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton80_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON80_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON80_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton80_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON80_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON80_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton80_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON81_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON81_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton81_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON81_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON81_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton81_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON81_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON81_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton81_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON81_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON81_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton81_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON81_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON81_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton81_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON81_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON81_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton81_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON81_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON81_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton81_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON81_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON81_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton81_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON82_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON82_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton82_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON82_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON82_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton82_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON82_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON82_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton82_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON82_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON82_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton82_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON82_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON82_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton82_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON82_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON82_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton82_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON82_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON82_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton82_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON82_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON82_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton82_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON83_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON83_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton83_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON83_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON83_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton83_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON83_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON83_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton83_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON83_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON83_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton83_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON83_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON83_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton83_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON83_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON83_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton83_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON83_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON83_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton83_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON83_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON83_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton83_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON84_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON84_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton84_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON84_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON84_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton84_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON84_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON84_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton84_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON84_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON84_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton84_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON84_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON84_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton84_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON84_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON84_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton84_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON84_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON84_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton84_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON84_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON84_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton84_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON85_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON85_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton85_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON85_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON85_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton85_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON85_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON85_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton85_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON85_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON85_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton85_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON85_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON85_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton85_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON85_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON85_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton85_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON85_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON85_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton85_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON85_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON85_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton85_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON86_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON86_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton86_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON86_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON86_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton86_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON86_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON86_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton86_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON86_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON86_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton86_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON86_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON86_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton86_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON86_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON86_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton86_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON86_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON86_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton86_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON86_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON86_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton86_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON87_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON87_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton87_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON87_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON87_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton87_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON87_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON87_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton87_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON87_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON87_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton87_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON87_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON87_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton87_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON87_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON87_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton87_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON87_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON87_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton87_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON87_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON87_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton87_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON88_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON88_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton88_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON88_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON88_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton88_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON88_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON88_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton88_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON88_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON88_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton88_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON88_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON88_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton88_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON88_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON88_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton88_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON88_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON88_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton88_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON88_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON88_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton88_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON89_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON89_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton89_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON89_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON89_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton89_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON89_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON89_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton89_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON89_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON89_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton89_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON89_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON89_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton89_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON89_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON89_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton89_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON89_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON89_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton89_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON89_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON89_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton89_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON90_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON90_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton90_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON90_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON90_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton90_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON90_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON90_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton90_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON90_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON90_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton90_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON90_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON90_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton90_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON90_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON90_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton90_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON90_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON90_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton90_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON90_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON90_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton90_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON91_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON91_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton91_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON91_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON91_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton91_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON91_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON91_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton91_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON91_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON91_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton91_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON91_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON91_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton91_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON91_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON91_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton91_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON91_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON91_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton91_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON91_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON91_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton91_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON92_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON92_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton92_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON92_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON92_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton92_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON92_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON92_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton92_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON92_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON92_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton92_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON92_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON92_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton92_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON92_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON92_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton92_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON92_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON92_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton92_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON92_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON92_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton92_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON93_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON93_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton93_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON93_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON93_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton93_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON93_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON93_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton93_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON93_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON93_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton93_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON93_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON93_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton93_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON93_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON93_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton93_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON93_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON93_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton93_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON93_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON93_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton93_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON94_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON94_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton94_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON94_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON94_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton94_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON94_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON94_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton94_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON94_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON94_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton94_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON94_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON94_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton94_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON94_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON94_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton94_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON94_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON94_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton94_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON94_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON94_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton94_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON95_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON95_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton95_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON95_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON95_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton95_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON95_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON95_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton95_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON95_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON95_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton95_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON95_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON95_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton95_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON95_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON95_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton95_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON95_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON95_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton95_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON95_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON95_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton95_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON96_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON96_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton96_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON96_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON96_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton96_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON96_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON96_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton96_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON96_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON96_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton96_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON96_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON96_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton96_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON96_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON96_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton96_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON96_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON96_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton96_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON96_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON96_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton96_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON97_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON97_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton97_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON97_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON97_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton97_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON97_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON97_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton97_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON97_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON97_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton97_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON97_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON97_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton97_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON97_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON97_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton97_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON97_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON97_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton97_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON97_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON97_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton97_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON98_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON98_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton98_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON98_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON98_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton98_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON98_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON98_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton98_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON98_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON98_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton98_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON98_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON98_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton98_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON98_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON98_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton98_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON98_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON98_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton98_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON98_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON98_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton98_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON99_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON99_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton99_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON99_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON99_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton99_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON99_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON99_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton99_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON99_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON99_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton99_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON99_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON99_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton99_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON99_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON99_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton99_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON99_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON99_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton99_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON99_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON99_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton99_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON100_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON100_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton100_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON100_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON100_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton100_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON100_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON100_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton100_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON100_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON100_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton100_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON100_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON100_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton100_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON100_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON100_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton100_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON100_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON100_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton100_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON100_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON100_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton100_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON101_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON101_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton101_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON101_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON101_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton101_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON101_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON101_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton101_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON101_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON101_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton101_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON101_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON101_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton101_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON101_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON101_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton101_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON101_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON101_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton101_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON101_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON101_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton101_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON102_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON102_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton102_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON102_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON102_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton102_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON102_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON102_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton102_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON102_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON102_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton102_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON102_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON102_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton102_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON102_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON102_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton102_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON102_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON102_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton102_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON102_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON102_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton102_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON103_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON103_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton103_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON103_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON103_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton103_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON103_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON103_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton103_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON103_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON103_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton103_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON103_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON103_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton103_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON103_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON103_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton103_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON103_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON103_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton103_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON103_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON103_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton103_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON104_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON104_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton104_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON104_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON104_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton104_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON104_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON104_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton104_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON104_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON104_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton104_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON104_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON104_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton104_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON104_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON104_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton104_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON104_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON104_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton104_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON104_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON104_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton104_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON105_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON105_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton105_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON105_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON105_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton105_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON105_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON105_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton105_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON105_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON105_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton105_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON105_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON105_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton105_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON105_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON105_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton105_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON105_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON105_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton105_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON105_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON105_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton105_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON106_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON106_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton106_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON106_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON106_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton106_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON106_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON106_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton106_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON106_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON106_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton106_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON106_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON106_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton106_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON106_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON106_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton106_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON106_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON106_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton106_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON106_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON106_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton106_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON107_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON107_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton107_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON107_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON107_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton107_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON107_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON107_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton107_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON107_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON107_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton107_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON107_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON107_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton107_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON107_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON107_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton107_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON107_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON107_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton107_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON107_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON107_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton107_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON108_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON108_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton108_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON108_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON108_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton108_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON108_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON108_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton108_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON108_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON108_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton108_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON108_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON108_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton108_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON108_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON108_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton108_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON108_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON108_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton108_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON108_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON108_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton108_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON109_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON109_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton109_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON109_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON109_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton109_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON109_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON109_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton109_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON109_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON109_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton109_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON109_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON109_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton109_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON109_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON109_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton109_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON109_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON109_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton109_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON109_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON109_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton109_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON110_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON110_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton110_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON110_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON110_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton110_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON110_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON110_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton110_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON110_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON110_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton110_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON110_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON110_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton110_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON110_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON110_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton110_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON110_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON110_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton110_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON110_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON110_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton110_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON111_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON111_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton111_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON111_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON111_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton110_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON111_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON111_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton111_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON111_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON111_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton111_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON111_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON111_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton111_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON111_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON111_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton111_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON111_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON111_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton111_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON111_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON111_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton111_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON112_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON112_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton112_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON112_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON112_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton112_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON112_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON112_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton112_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON112_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON112_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton112_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON112_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON112_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton112_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON112_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON112_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton112_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON112_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON112_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton112_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON112_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON112_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton112_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON113_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON113_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton113_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON113_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON113_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton113_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON113_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON113_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton113_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON113_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON113_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton113_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON113_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON113_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton113_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON113_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON113_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton113_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON113_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON113_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton113_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON113_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON113_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton113_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON114_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON114_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton114_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON114_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON114_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton114_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON114_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON114_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton114_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON114_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON114_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton114_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON114_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON114_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton114_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON114_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON114_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton114_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON114_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON114_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton114_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON114_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON114_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton114_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON115_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON115_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton115_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON115_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON115_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton115_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON115_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON115_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton115_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON115_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON115_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton115_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON115_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON115_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton115_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON115_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON115_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton115_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON115_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON115_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton115_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON115_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON115_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton115_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON116_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON116_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton116_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON116_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON116_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton116_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON116_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON116_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton116_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON116_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON116_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton116_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON116_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON116_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton116_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON116_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON116_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton116_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON116_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON116_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton116_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON116_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON116_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton116_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON117_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON117_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton117_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON117_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON117_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton117_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON117_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON117_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton117_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON117_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON117_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton117_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON117_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON117_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton117_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON117_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON117_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton117_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON117_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON117_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton117_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON117_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON117_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton117_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON118_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON118_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton118_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON118_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON118_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton118_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON118_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON118_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton118_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON118_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON118_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton118_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON118_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON118_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton118_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON118_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON118_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton118_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON118_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON118_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton118_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON118_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON118_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton118_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON119_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON119_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton119_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON119_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON119_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton119_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON119_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON119_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton119_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON119_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON119_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton119_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON119_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON119_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton119_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON119_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON119_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton119_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON119_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON119_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton119_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON119_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON119_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton119_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON120_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON120_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton120_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON120_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON120_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton120_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON120_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON120_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton120_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON120_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON120_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton120_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON120_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON120_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton120_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON120_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON120_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton120_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON120_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON120_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton120_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON120_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON120_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton120_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON121_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON121_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton121_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON121_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON121_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton121_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON121_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON121_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton121_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON121_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON121_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton121_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON121_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON121_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton121_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON121_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON121_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton121_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON121_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON121_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton121_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON121_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON121_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton121_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON122_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON122_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton122_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON122_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON122_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton122_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON122_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON122_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton122_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON122_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON122_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton122_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON122_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON122_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton122_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON122_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON122_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton122_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON122_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON122_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton122_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON122_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON122_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton122_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON123_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON123_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton123_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON123_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON123_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton123_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON123_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON123_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton123_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON123_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON123_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton123_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON123_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON123_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton123_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON123_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON123_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton123_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON123_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON123_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton123_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON123_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON123_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton123_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON124_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON124_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton124_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON124_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON124_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton124_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON124_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON124_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton124_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON124_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON124_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton124_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON124_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON124_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton124_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON124_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON124_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton124_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON124_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON124_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton124_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON124_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON124_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton124_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON125_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON125_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton125_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON125_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON125_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton125_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON125_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON125_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton125_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON125_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON125_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton125_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON125_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON125_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton125_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON125_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON125_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton125_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON125_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON125_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton125_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON125_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON125_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton125_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON126_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON126_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton126_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON126_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON126_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton126_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON126_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON126_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton126_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON126_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON126_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton126_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON126_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON126_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton126_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON126_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON126_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton126_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON126_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON126_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton126_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON126_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON126_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton126_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON127_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON127_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton127_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON127_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON127_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton127_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON127_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON127_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton127_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON127_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON127_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton127_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON127_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON127_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton127_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON127_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON127_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton127_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON127_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON127_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton127_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON127_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON127_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton127_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON128_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON128_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton128_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON128_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON128_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton128_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON128_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON128_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton128_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON128_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON128_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton128_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON128_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON128_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton128_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON128_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON128_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton128_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON128_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON128_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton128_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON128_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON128_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton128_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON129_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON129_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton129_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON129_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON129_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton129_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON129_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON129_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton129_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON129_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON129_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton129_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON129_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON129_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton129_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON129_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON129_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton129_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON129_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON129_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton129_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON129_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON129_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton129_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON130_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON130_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton130_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON130_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON130_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton130_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON130_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON130_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton130_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON130_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON130_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton130_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON130_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON130_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton130_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON130_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON130_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton130_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON130_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON130_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton130_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON130_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON130_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton130_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON131_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON131_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton131_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON131_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON131_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton131_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON131_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON131_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton131_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON131_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON131_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton131_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON131_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON131_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton131_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON131_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON131_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton131_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON131_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON131_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton131_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON131_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON131_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton131_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON132_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON132_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton132_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON132_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON132_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton132_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON132_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON132_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton132_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON132_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON132_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton132_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON132_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON132_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton132_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON132_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON132_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton132_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON132_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON132_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton132_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON132_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON132_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton132_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON133_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON133_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton133_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON133_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON133_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton133_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON133_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON133_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton133_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON133_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON133_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton133_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON133_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON133_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton133_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON133_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON133_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton133_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON133_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON133_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton133_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON133_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON133_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton133_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON134_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON134_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton134_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON134_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON134_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton134_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON134_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON134_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton134_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON134_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON134_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton134_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON134_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON134_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton134_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON134_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON134_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton134_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON134_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON134_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton134_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON134_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON134_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton134_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON135_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON135_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton135_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON135_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON135_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton135_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON135_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON135_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton135_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON135_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON135_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton135_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON135_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON135_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton135_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON135_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON135_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton135_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON135_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON135_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton135_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON135_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON135_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton135_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON136_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON136_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton136_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON136_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON136_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton136_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON136_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON136_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton136_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON136_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON136_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton136_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON136_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON136_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton136_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON136_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON136_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton136_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON136_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON136_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton136_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON136_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON136_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton136_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON137_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON137_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton137_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON137_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON137_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton137_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON137_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON137_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton137_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON137_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON137_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton137_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON137_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON137_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton137_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON137_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON137_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton137_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON137_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON137_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton137_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON137_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON137_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton137_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON138_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON138_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton138_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON138_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON138_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton138_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON138_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON138_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton138_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON138_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON138_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton138_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON138_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON138_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton138_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON138_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON138_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton138_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON138_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON138_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton138_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON138_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON138_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton138_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON139_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON139_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton139_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON139_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON139_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton139_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON139_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON139_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton139_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON139_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON139_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton139_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON139_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON139_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton139_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON139_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON139_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton139_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON139_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON139_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton139_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON139_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON139_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton139_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON140_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON140_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton140_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON140_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON140_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton140_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON140_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON140_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton140_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON140_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON140_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton140_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON140_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON140_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton140_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON140_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON140_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton140_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON140_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON140_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton140_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON140_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON140_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton140_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON141_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON141_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton141_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON141_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON141_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton141_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON141_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON141_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton141_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON141_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON141_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton141_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON141_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON141_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton141_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON141_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON141_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton141_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON141_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON141_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton141_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON141_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON141_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton141_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON142_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON142_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton142_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON142_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON142_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton142_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON142_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON142_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton142_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON142_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON142_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton142_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON142_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON142_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton142_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON142_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON142_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton142_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON142_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON142_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton142_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON142_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON142_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton142_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON143_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON143_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton143_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON143_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON143_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton143_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON143_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON143_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton143_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON143_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON143_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton143_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON143_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON143_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton143_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON143_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON143_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton143_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON143_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON143_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton143_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON143_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON143_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton143_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON144_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON144_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton144_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON144_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON144_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton144_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON144_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON144_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton144_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON144_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON144_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton144_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON144_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON144_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton144_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON144_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON144_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton144_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON144_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON144_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton144_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON144_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON144_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton144_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON145_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON145_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton145_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON145_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON145_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton145_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON145_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON145_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton145_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON145_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON145_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton145_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON145_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON145_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton145_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON145_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON145_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton145_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON145_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON145_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton145_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON145_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON145_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton145_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON146_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON146_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton146_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON146_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON146_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton146_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON146_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON146_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton146_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON146_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON146_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton146_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON146_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON146_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton146_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON146_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON146_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton146_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON146_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON146_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton146_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON146_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON146_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton146_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON147_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON147_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton147_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON147_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON147_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton147_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON147_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON147_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton147_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON147_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON147_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton147_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON147_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON147_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton147_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON147_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON147_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton147_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON147_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON147_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton147_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON147_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON147_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton147_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON148_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON148_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton148_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON148_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON148_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton148_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON148_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON148_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton148_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON148_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON148_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton148_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON148_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON148_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton148_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON148_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON148_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton148_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON148_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON148_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton148_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON148_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON148_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton148_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON149_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON149_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton149_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON149_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON149_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton149_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON149_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON149_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton149_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON149_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON149_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton149_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON149_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON149_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton149_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON149_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON149_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton149_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON149_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON149_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton149_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON149_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON149_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton149_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON150_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON150_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton150_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON150_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON150_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton150_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON150_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON150_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton150_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON150_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON150_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton150_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON150_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON150_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton150_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON150_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON150_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton150_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON150_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON150_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton150_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON150_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON150_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton150_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON151_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON151_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton151_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON151_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON151_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton151_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON151_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON151_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton151_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON151_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON151_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton151_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON151_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON151_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton151_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON151_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON151_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton151_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON151_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON151_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton151_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON151_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON151_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton151_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON152_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON152_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton152_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON152_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON152_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton152_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON152_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON152_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton152_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON152_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON152_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton152_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON152_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON152_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton152_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON152_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON152_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton152_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON152_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON152_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton152_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON152_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON152_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton152_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON153_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON153_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton153_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON153_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON153_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton153_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON153_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON153_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton153_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON153_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON153_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton153_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON153_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON153_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton153_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON153_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON153_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton153_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON153_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON153_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton153_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON153_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON153_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton153_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON154_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON154_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton154_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON154_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON154_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton154_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON154_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON154_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton154_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON154_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON154_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton154_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON154_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON154_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton154_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON154_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON154_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton154_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON154_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON154_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton154_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON154_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON154_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton154_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON155_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON155_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton155_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON155_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON155_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton155_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON155_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON155_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton155_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON155_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON155_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton155_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON155_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON155_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton155_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON155_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON155_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton155_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON155_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON155_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton155_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON155_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON155_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton155_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON156_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON156_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton156_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON156_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON156_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton156_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON156_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON156_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton156_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON156_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON156_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton156_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON156_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON156_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton156_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON156_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON156_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton156_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON156_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON156_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton156_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON156_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON156_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton156_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON157_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON157_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton157_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON157_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON157_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton157_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON157_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON157_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton157_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON157_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON157_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton157_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON157_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON157_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton157_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON157_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON157_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton157_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON157_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON157_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton157_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON157_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON157_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton157_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON158_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON158_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton158_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON158_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON158_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton158_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON158_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON158_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton158_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON158_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON158_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton158_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON158_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON158_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton158_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON158_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON158_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton158_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON158_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON158_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton158_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON158_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON158_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton158_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON159_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON159_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton159_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON159_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON159_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton159_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON159_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON159_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton159_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON159_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON159_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton159_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON159_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON159_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton159_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON159_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON159_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton159_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON159_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON159_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton159_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON159_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON159_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton159_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON160_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON160_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton160_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON160_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON160_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton160_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON160_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON160_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton160_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON160_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON160_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton160_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON160_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON160_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton160_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON160_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON160_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton160_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON160_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON160_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton160_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON160_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON160_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton160_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON161_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON161_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton161_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON161_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON161_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton161_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON161_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON161_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton161_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON161_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON161_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton161_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON161_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON161_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton161_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON161_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON161_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton161_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON161_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON161_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton161_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON161_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON161_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton161_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON162_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON162_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton162_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON162_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON162_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton162_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON162_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON162_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton162_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON162_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON162_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton162_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON162_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON162_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton162_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON162_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON162_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton162_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON162_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON162_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton162_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON162_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON162_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton162_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON163_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON163_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton163_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON163_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON163_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton163_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON163_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON163_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton163_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON163_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON163_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton163_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON163_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON163_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton163_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON163_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON163_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton163_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON163_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON163_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton163_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON163_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON163_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton163_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON164_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON164_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton164_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON164_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON164_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton164_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON164_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON164_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton164_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON164_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON164_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton164_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON164_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON164_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton164_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON164_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON164_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton164_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON164_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON164_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton164_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON164_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON164_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton164_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON165_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON165_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton165_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON165_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON165_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton165_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON165_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON165_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton165_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON165_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON165_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton165_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON165_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON165_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton165_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON165_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON165_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton165_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON165_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON165_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton165_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON165_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON165_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton165_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON166_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON166_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton166_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON166_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON166_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton166_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON166_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON166_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton166_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON166_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON166_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton166_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON166_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON166_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton166_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON166_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON166_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton166_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON166_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON166_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton166_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON166_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON166_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton166_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON167_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON167_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton167_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON167_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON167_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton167_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON167_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON167_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton167_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON167_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON167_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton167_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON167_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON167_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton167_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON167_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON167_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton167_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON167_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON167_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton167_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON167_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON167_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton167_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON168_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON168_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton168_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON168_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON168_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton168_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON168_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON168_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton168_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON168_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON168_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton168_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON168_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON168_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton168_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON168_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON168_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton168_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON168_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON168_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton168_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON168_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON168_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton168_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON169_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON169_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton169_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON169_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON169_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton169_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON169_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON169_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton169_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON169_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON169_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton169_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON169_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON169_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton169_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON169_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON169_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton169_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON169_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON169_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton169_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON169_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON169_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton169_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON170_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON170_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton170_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON170_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON170_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton170_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON170_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON170_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton170_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON170_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON170_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton170_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON170_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON170_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton170_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON170_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON170_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton170_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON170_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON170_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton170_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON170_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON170_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton170_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON171_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON171_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton170_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON171_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON171_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton171_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON171_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON171_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton171_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON171_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON171_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton171_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON171_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON171_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton171_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON171_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON171_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton171_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON171_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON171_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton171_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON171_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON171_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton171_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON172_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON172_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton172_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON172_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON172_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton172_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON172_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON172_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton172_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON172_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON172_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton172_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON172_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON172_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton172_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON172_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON172_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton172_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON172_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON172_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton172_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON172_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON172_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton172_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON173_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON173_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton173_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON173_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON173_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton173_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON173_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON173_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton173_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON173_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON173_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton173_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON173_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON173_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton173_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON173_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON173_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton173_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON173_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON173_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton173_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON173_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON173_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton173_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON174_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON174_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton174_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON174_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON174_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton174_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON174_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON174_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton174_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON174_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON174_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton174_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON174_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON174_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton174_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON174_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON174_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton174_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON174_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON174_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton174_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON174_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON174_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton174_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON175_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON175_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton175_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON175_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON175_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton175_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON175_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON175_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton175_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON175_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON175_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton175_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON175_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON175_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton175_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON175_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON175_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton175_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON175_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON175_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton175_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON175_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON175_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton175_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON176_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON176_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton176_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON176_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON176_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton176_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON176_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON176_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton176_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON176_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON176_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton176_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON176_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON176_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton176_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON176_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON176_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton176_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON176_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON176_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton176_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON176_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON176_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton176_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON177_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON177_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton177_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON177_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON177_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton177_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON177_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON177_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton177_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON177_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON177_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton177_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON177_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON177_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton177_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON177_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON177_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton177_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON177_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON177_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton177_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON177_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON177_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton177_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON178_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON178_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton178_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON178_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON178_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton178_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON178_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON178_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton178_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON178_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON178_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton178_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON178_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON178_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton178_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON178_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON178_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton178_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON178_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON178_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton178_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON178_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON178_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton178_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON179_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON179_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton179_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON179_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON179_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton179_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON179_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON179_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton179_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON179_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON179_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton179_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON179_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON179_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton179_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON179_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON179_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton179_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON179_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON179_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton179_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON179_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON179_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton179_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON180_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON180_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton180_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON180_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON180_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton180_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON180_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON180_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton180_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON180_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON180_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton180_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON180_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON180_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton180_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON180_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON180_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton180_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON180_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON180_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton180_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON180_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON180_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton180_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON181_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON181_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton181_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON181_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON181_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton181_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON181_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON181_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton181_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON181_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON181_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton181_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON181_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON181_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton181_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON181_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON181_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton181_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON181_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON181_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton181_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON181_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON181_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton181_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON182_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON182_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton182_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON182_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON182_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton182_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON182_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON182_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton182_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON182_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON182_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton182_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON182_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON182_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton182_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON182_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON182_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton182_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON182_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON182_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton182_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON182_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON182_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton182_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON183_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON183_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton183_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON183_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON183_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton183_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON183_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON183_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton183_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON183_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON183_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton183_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON183_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON183_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton183_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON183_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON183_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton183_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON183_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON183_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton183_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON183_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON183_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton183_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON184_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON184_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton184_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON184_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON184_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton184_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON184_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON184_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton184_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON184_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON184_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton184_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON184_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON184_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton184_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON184_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON184_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton184_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON184_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON184_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton184_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON184_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON184_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton184_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON185_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON185_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton185_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON185_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON185_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton185_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON185_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON185_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton185_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON185_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON185_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton185_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON185_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON185_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton185_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON185_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON185_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton185_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON185_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON185_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton185_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON185_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON185_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton185_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON186_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON186_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton186_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON186_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON186_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton186_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON186_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON186_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton186_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON186_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON186_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton186_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON186_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON186_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton186_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON186_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON186_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton186_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON186_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON186_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton186_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON186_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON186_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton186_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON187_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON187_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton187_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON187_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON187_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton187_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON187_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON187_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton187_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON187_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON187_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton187_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON187_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON187_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton187_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON187_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON187_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton187_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON187_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON187_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton187_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON187_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON187_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton187_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON188_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON188_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton188_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON188_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON188_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton188_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON188_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON188_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton188_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON188_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON188_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton188_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON188_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON188_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton188_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON188_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON188_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton188_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON188_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON188_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton188_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON188_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON188_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton188_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON189_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON189_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton189_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON189_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON189_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton189_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON189_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON189_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton189_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON189_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON189_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton189_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON189_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON189_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton189_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON189_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON189_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton189_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON189_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON189_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton189_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON189_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON189_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton189_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON190_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON190_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton190_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON190_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON190_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton190_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON190_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON190_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton190_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON190_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON190_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton190_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON190_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON190_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton190_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON190_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON190_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton190_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON190_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON190_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton190_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON190_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON190_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton190_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON191_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON191_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton191_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON191_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON191_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton191_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON191_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON191_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton191_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON191_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON191_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton191_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON191_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON191_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton191_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON191_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON191_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton191_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON191_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON191_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton191_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON191_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON191_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton191_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON192_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON192_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton192_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON192_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON192_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton192_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON192_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON192_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton192_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON192_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON192_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton192_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON192_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON192_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton192_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON192_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON192_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton192_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON192_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON192_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton192_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON192_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON192_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton192_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON193_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON193_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton193_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON193_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON193_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton193_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON193_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON193_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton193_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON193_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON193_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton193_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON193_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON193_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton193_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON193_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON193_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton193_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON193_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON193_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton193_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON193_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON193_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton193_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON194_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON194_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton194_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON194_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON194_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton194_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON194_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON194_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton194_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON194_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON194_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton194_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON194_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON194_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton194_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON194_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON194_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton194_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON194_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON194_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton194_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON194_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON194_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton194_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON195_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON195_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton195_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON195_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON195_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton195_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON195_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON195_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton195_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON195_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON195_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton195_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON195_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON195_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton195_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON195_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON195_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton195_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON195_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON195_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton195_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON195_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON195_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton195_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON196_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON196_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton196_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON196_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON196_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton196_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON196_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON196_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton196_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON196_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON196_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton196_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON196_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON196_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton196_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON196_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON196_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton196_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON196_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON196_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton196_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON196_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON196_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton196_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON197_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON197_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton197_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON197_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON197_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton197_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON197_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON197_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton197_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON197_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON197_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton197_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON197_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON197_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton197_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON197_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON197_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton197_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON197_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON197_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton197_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON197_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON197_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton197_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON198_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON198_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton198_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON198_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON198_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton198_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON198_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON198_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton198_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON198_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON198_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton198_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON198_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON198_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton198_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON198_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON198_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton198_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON198_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON198_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton198_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON198_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON198_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton198_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;


	fm25v02_read(2*IBUTTON199_BYTE_0_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON199_BYTE_0_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton199_byte_0_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON199_BYTE_1_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON199_BYTE_1_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton199_byte_1_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON199_BYTE_2_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON199_BYTE_2_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton199_byte_2_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON199_BYTE_3_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON199_BYTE_3_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton199_byte_3_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON199_BYTE_4_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON199_BYTE_4_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton199_byte_4_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON199_BYTE_5_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON199_BYTE_5_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton199_byte_5_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON199_BYTE_6_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON199_BYTE_6_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton199_byte_6_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	fm25v02_read(2*IBUTTON199_BYTE_7_REG, &status_reg_temp_h);
	fm25v02_read(2*IBUTTON199_BYTE_7_REG+1, &status_reg_temp_l);
	ibutton_registers.ibutton199_byte_7_reg = (((uint16_t)status_reg_temp_h)<<8)|status_reg_temp_l;

	osMutexRelease(Fm25v02MutexHandle);

}

//----------------------------------------------------------------


//-----Блок расчета CRC16 для Modbus---------------------------------------------------------------

const unsigned char MB_Slave_aucCRCHi[] =
{
  0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
  0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
  0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
  0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
  0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
  0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
  0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
  0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
  0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
  0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
  0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
  0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
  0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
  0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
  0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
  0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40
};

const unsigned char MB_Slave_aucCRCLo[] =
{
  0x00, 0xC0, 0xC1, 0x01, 0xC3, 0x03, 0x02, 0xC2, 0xC6, 0x06, 0x07, 0xC7, 0x05, 0xC5, 0xC4, 0x04,
  0xCC, 0x0C, 0x0D, 0xCD, 0x0F, 0xCF, 0xCE, 0x0E, 0x0A, 0xCA, 0xCB, 0x0B, 0xC9, 0x09, 0x08, 0xC8,
  0xD8, 0x18, 0x19, 0xD9, 0x1B, 0xDB, 0xDA, 0x1A, 0x1E, 0xDE, 0xDF, 0x1F, 0xDD, 0x1D, 0x1C, 0xDC,
  0x14, 0xD4, 0xD5, 0x15, 0xD7, 0x17, 0x16, 0xD6, 0xD2, 0x12, 0x13, 0xD3, 0x11, 0xD1, 0xD0, 0x10,
  0xF0, 0x30, 0x31, 0xF1, 0x33, 0xF3, 0xF2, 0x32, 0x36, 0xF6, 0xF7, 0x37, 0xF5, 0x35, 0x34, 0xF4,
  0x3C, 0xFC, 0xFD, 0x3D, 0xFF, 0x3F, 0x3E, 0xFE, 0xFA, 0x3A, 0x3B, 0xFB, 0x39, 0xF9, 0xF8, 0x38,
  0x28, 0xE8, 0xE9, 0x29, 0xEB, 0x2B, 0x2A, 0xEA, 0xEE, 0x2E, 0x2F, 0xEF, 0x2D, 0xED, 0xEC, 0x2C,
  0xE4, 0x24, 0x25, 0xE5, 0x27, 0xE7, 0xE6, 0x26, 0x22, 0xE2, 0xE3, 0x23, 0xE1, 0x21, 0x20, 0xE0,
  0xA0, 0x60, 0x61, 0xA1, 0x63, 0xA3, 0xA2, 0x62, 0x66, 0xA6, 0xA7, 0x67, 0xA5, 0x65, 0x64, 0xA4,
  0x6C, 0xAC, 0xAD, 0x6D, 0xAF, 0x6F, 0x6E, 0xAE, 0xAA, 0x6A, 0x6B, 0xAB, 0x69, 0xA9, 0xA8, 0x68,
  0x78, 0xB8, 0xB9, 0x79, 0xBB, 0x7B, 0x7A, 0xBA, 0xBE, 0x7E, 0x7F, 0xBF, 0x7D, 0xBD, 0xBC, 0x7C,
  0xB4, 0x74, 0x75, 0xB5, 0x77, 0xB7, 0xB6, 0x76, 0x72, 0xB2, 0xB3, 0x73, 0xB1, 0x71, 0x70, 0xB0,
  0x50, 0x90, 0x91, 0x51, 0x93, 0x53, 0x52, 0x92, 0x96, 0x56, 0x57, 0x97, 0x55, 0x95, 0x94, 0x54,
  0x9C, 0x5C, 0x5D, 0x9D, 0x5F, 0x9F, 0x9E, 0x5E, 0x5A, 0x9A, 0x9B, 0x5B, 0x99, 0x59, 0x58, 0x98,
  0x88, 0x48, 0x49, 0x89, 0x4B, 0x8B, 0x8A, 0x4A, 0x4E, 0x8E, 0x8F, 0x4F, 0x8D, 0x4D, 0x4C, 0x8C,
  0x44, 0x84, 0x85, 0x45, 0x87, 0x47, 0x46, 0x86, 0x82, 0x42, 0x43, 0x83, 0x41, 0x81, 0x80, 0x40
};

//------------------------------------------------------------------------------------------------------



//--------------------- Процедура расчета CRC16 -------------------------------------

 unsigned int CRC16( unsigned char * pucFrame, unsigned int usLen ){
  unsigned char MB_Slave_ucCRCHi = 0xFF;
  unsigned char MB_Slave_ucCRCLo = 0xFF;
  int iIndex;
  //
  while( usLen-- ){
    iIndex = MB_Slave_ucCRCLo ^ *( pucFrame++ );
    MB_Slave_ucCRCLo = MB_Slave_ucCRCHi ^ MB_Slave_aucCRCHi[iIndex];
    MB_Slave_ucCRCHi = MB_Slave_aucCRCLo[iIndex];
  }
  return MB_Slave_ucCRCHi << 8 | MB_Slave_ucCRCLo;
}

//------------------------------------------------------------------------------------

