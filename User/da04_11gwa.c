#include "stm32f4xx_hal.h"
#include "da04_11gwa.h"

extern uint8_t spi_buf[4];

//---- Первая цифра---------------------------------------
void LED1_A2_ON(void)
{
	//HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
	spi_buf[3] = spi_buf[3] & 0xF7;
}

void LED1_A2_OFF(void)
{
	//HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
	spi_buf[3] = spi_buf[3] | 0x08;
}

void LED1_B2_ON(void)
{
	//HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, GPIO_PIN_SET);
	spi_buf[3] = spi_buf[3] & 0xEF;
}

void LED1_B2_OFF(void)
{
	//HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, GPIO_PIN_RESET);
	spi_buf[3] = spi_buf[3] | 0x10;
}

void LED1_C2_ON(void)
{
	//HAL_GPIO_WritePin(GPIOC, GPIO_PIN_11, GPIO_PIN_SET);
	spi_buf[3] = spi_buf[3] & 0xDF;
}

void LED1_C2_OFF(void)
{
	//HAL_GPIO_WritePin(GPIOC, GPIO_PIN_11, GPIO_PIN_RESET);
	spi_buf[3] = spi_buf[3] | 0x20;
}

void LED1_D2_ON(void)
{
	//HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, GPIO_PIN_SET);
	spi_buf[3] = spi_buf[3] & 0xFE;
}

void LED1_D2_OFF(void)
{
	//HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, GPIO_PIN_RESET);
	spi_buf[3] = spi_buf[3] | 0x01;
}

void LED1_E2_ON(void)
{
	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_SET);
	spi_buf[3] = spi_buf[3] & 0xFD;
}

void LED1_E2_OFF(void)
{
	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_RESET);
	spi_buf[3] = spi_buf[3] | 0x02;
}

void LED1_F2_ON(void)
{
	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, GPIO_PIN_SET);
	spi_buf[3] = spi_buf[3] & 0xFB;
}

void LED1_F2_OFF(void)
{
	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, GPIO_PIN_RESET);
	spi_buf[3] = spi_buf[3] | 0x04;
}

void LED1_G2_ON(void)
{
	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_SET);
	spi_buf[3] = spi_buf[3] & 0xBF;
}

void LED1_G2_OFF(void)
{
	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_RESET);
	spi_buf[3] = spi_buf[3] | 0x40;
}
//---------------------------------------------------------


//---- Вторая цифра---------------------------------------
void LED1_A1_ON(void)
{
	//HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_SET);
	spi_buf[2] = spi_buf[2] & 0xF7;
}

void LED1_A1_OFF(void)
{
	//HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_RESET);
	spi_buf[2] = spi_buf[2] | 0x08;
}

void LED1_B1_ON(void)
{
	//HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_SET);
	spi_buf[2] = spi_buf[2] & 0xEF;
}

void LED1_B1_OFF(void)
{
	//HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_RESET);
	spi_buf[2] = spi_buf[2] | 0x10;
}

void LED1_C1_ON(void)
{
	//HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
	spi_buf[2] = spi_buf[2] & 0xDF;
}

void LED1_C1_OFF(void)
{
	//HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_RESET);
	spi_buf[2] = spi_buf[2] | 0x20;
}

void LED1_D1_ON(void)
{
	//HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_SET);
	spi_buf[2] = spi_buf[2] & 0xFE;
}

void LED1_D1_OFF(void)
{
	//HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_RESET);
	spi_buf[2] = spi_buf[2] | 0x01;
}

void LED1_E1_ON(void)
{
	//HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);
	spi_buf[2] = spi_buf[2] & 0xFD;
}

void LED1_E1_OFF(void)
{
	//HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
	spi_buf[2] = spi_buf[2] | 0x02;
}

void LED1_F1_ON(void)
{
	//HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
	spi_buf[2] = spi_buf[2] & 0xFB;
}

void LED1_F1_OFF(void)
{
	//HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
	spi_buf[2] = spi_buf[2] | 0x04;
}

void LED1_G1_ON(void)
{
	//HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET);
	spi_buf[2] = spi_buf[2] & 0xBF;
}

void LED1_G1_OFF(void)
{
	//HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
	spi_buf[2] = spi_buf[2] | 0x40;
}
//---------------------------------------------------------

//---- третья цифра---------------------------------------
void LED2_A2_ON(void)
{
	//HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET);
	spi_buf[1] = spi_buf[1] & 0xF7;
}

void LED2_A2_OFF(void)
{
	//HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_RESET);
	spi_buf[1] = spi_buf[1] | 0x08;
}

void LED2_B2_ON(void)
{
	//HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_SET);
	spi_buf[1] = spi_buf[1] & 0xEF;
}

void LED2_B2_OFF(void)
{
	//HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_RESET);
	spi_buf[1] = spi_buf[1] | 0x10;
}

void LED2_C2_ON(void)
{
	//HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_SET);
	spi_buf[1] = spi_buf[1] & 0xDF;
}

void LED2_C2_OFF(void)
{
	//HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_RESET);
	spi_buf[1] = spi_buf[1] | 0x20;
}

void LED2_D2_ON(void)
{
	//HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_SET);
	spi_buf[1] = spi_buf[1] & 0xFE;
}

void LED2_D2_OFF(void)
{
	//HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_RESET);
	spi_buf[1] = spi_buf[1] | 0x01;
}

void LED2_E2_ON(void)
{
	//HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_SET);
	spi_buf[1] = spi_buf[1] & 0xFD;
}

void LED2_E2_OFF(void)
{
	//HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_RESET);
	spi_buf[1] = spi_buf[1] | 0x02;
}

void LED2_F2_ON(void)
{
	//HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_SET);
	spi_buf[1] = spi_buf[1] & 0xFB;
}

void LED2_F2_OFF(void)
{
	//HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_RESET);
	spi_buf[1] = spi_buf[1] | 0x04;
}

void LED2_G2_ON(void)
{
	//HAL_GPIO_WritePin(GPIOE, GPIO_PIN_15, GPIO_PIN_SET);
	spi_buf[1] = spi_buf[1] & 0xBF;
}

void LED2_G2_OFF(void)
{
	//HAL_GPIO_WritePin(GPIOE, GPIO_PIN_15, GPIO_PIN_RESET);
	spi_buf[1] = spi_buf[1] | 0x40;
}
//---------------------------------------------------------

//---- четвертая цифра---------------------------------------
void LED2_A1_ON(void)
{
	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
	spi_buf[0] = spi_buf[0] & 0xF7;
}

void LED2_A1_OFF(void)
{
	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
	spi_buf[0] = spi_buf[0] | 0x08;
}

void LED2_B1_ON(void)
{
	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
	spi_buf[0] = spi_buf[0] & 0xEF;
}

void LED2_B1_OFF(void)
{
	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
	spi_buf[0] = spi_buf[0] | 0x10;
}

void LED2_C1_ON(void)
{
	//HAL_GPIO_WritePin(GPIOG, GPIO_PIN_2, GPIO_PIN_SET);
	spi_buf[0] = spi_buf[0] & 0xDF;
}

void LED2_C1_OFF(void)
{
	//HAL_GPIO_WritePin(GPIOG, GPIO_PIN_2, GPIO_PIN_RESET);
	spi_buf[0] = spi_buf[0] | 0x20;
}

void LED2_D1_ON(void)
{
	//HAL_GPIO_WritePin(GPIOG, GPIO_PIN_3, GPIO_PIN_SET);
	spi_buf[0] = spi_buf[0] & 0xFE;
}

void LED2_D1_OFF(void)
{
	//HAL_GPIO_WritePin(GPIOG, GPIO_PIN_3, GPIO_PIN_RESET);
	spi_buf[0] = spi_buf[0] | 0x01;
}

void LED2_E1_ON(void)
{
	//HAL_GPIO_WritePin(GPIOG, GPIO_PIN_4, GPIO_PIN_SET);
	spi_buf[0] = spi_buf[0] & 0xFD;
}

void LED2_E1_OFF(void)
{
	//AL_GPIO_WritePin(GPIOG, GPIO_PIN_4, GPIO_PIN_RESET);
	spi_buf[0] = spi_buf[0] | 0x02;
}

void LED2_F1_ON(void)
{
	//HAL_GPIO_WritePin(GPIOG, GPIO_PIN_5, GPIO_PIN_SET);
	spi_buf[0] = spi_buf[0] & 0xFB;
}

void LED2_F1_OFF(void)
{
	//HAL_GPIO_WritePin(GPIOG, GPIO_PIN_5, GPIO_PIN_RESET);
	spi_buf[0] = spi_buf[0] | 0x04;
}

void LED2_G1_ON(void)
{
	//HAL_GPIO_WritePin(GPIOG, GPIO_PIN_6, GPIO_PIN_SET);
	spi_buf[0] = spi_buf[0] & 0xBF;
}

void LED2_G1_OFF(void)
{
	//HAL_GPIO_WritePin(GPIOG, GPIO_PIN_6, GPIO_PIN_RESET);
	spi_buf[0] = spi_buf[0] | 0x40;
}
//---------------------------------------------------------


//----Управление первой цифрой-----------------------------
void dig1_set_0(void)
{
	LED1_A2_ON();
	LED1_B2_ON();
	LED1_C2_ON();
	LED1_D2_ON();
	LED1_E2_ON();
	LED1_F2_ON();
	LED1_G2_OFF();
}

void dig1_set_1(void)
{
	LED1_A2_OFF();
	LED1_B2_OFF();
	LED1_C2_OFF();
	LED1_D2_OFF();
	LED1_E2_ON();
	LED1_F2_ON();
	LED1_G2_OFF();
}

void dig1_set_2(void)
{
	LED1_A2_ON();
	LED1_B2_ON();
	LED1_C2_OFF();
	LED1_D2_ON();
	LED1_E2_ON();
	LED1_F2_OFF();
	LED1_G2_ON();
}

void dig1_set_3(void)
{
	LED1_A2_ON();
	LED1_B2_OFF();
	LED1_C2_OFF();
	LED1_D2_ON();
	LED1_E2_ON();
	LED1_F2_ON();
	LED1_G2_ON();
}

void dig1_set_4(void)
{
	LED1_A2_OFF();
	LED1_B2_OFF();
	LED1_C2_ON();
	LED1_D2_OFF();
	LED1_E2_ON();
	LED1_F2_ON();
	LED1_G2_ON();
}

void dig1_set_5(void)
{
	LED1_A2_ON();
	LED1_B2_OFF();
	LED1_C2_ON();
	LED1_D2_ON();
	LED1_E2_OFF();
	LED1_F2_ON();
	LED1_G2_ON();
}

void dig1_set_6(void)
{
	LED1_A2_ON();
	LED1_B2_ON();
	LED1_C2_ON();
	LED1_D2_ON();
	LED1_E2_OFF();
	LED1_F2_ON();
	LED1_G2_ON();
}

void dig1_set_7(void)
{
	LED1_A2_OFF();
	LED1_B2_OFF();
	LED1_C2_OFF();
	LED1_D2_ON();
	LED1_E2_ON();
	LED1_F2_ON();
	LED1_G2_OFF();
}

void dig1_set_8(void)
{
	LED1_A2_ON();
	LED1_B2_ON();
	LED1_C2_ON();
	LED1_D2_ON();
	LED1_E2_ON();
	LED1_F2_ON();
	LED1_G2_ON();
}

void dig1_set_9(void)
{
	LED1_A2_ON();
	LED1_B2_OFF();
	LED1_C2_ON();
	LED1_D2_ON();
	LED1_E2_ON();
	LED1_F2_ON();
	LED1_G2_ON();
}

void dig1_set_off(void)
{
	LED1_A2_OFF();
	LED1_B2_OFF();
	LED1_C2_OFF();
	LED1_D2_OFF();
	LED1_E2_OFF();
	LED1_F2_OFF();
	LED1_G2_OFF();
}

//-----------------------------------------------------------


//----Управление второй цифрой-----------------------------
void dig2_set_0(void)
{
	LED1_A1_ON();
	LED1_B1_ON();
	LED1_C1_ON();
	LED1_D1_ON();
	LED1_E1_ON();
	LED1_F1_ON();
	LED1_G1_OFF();
}

void dig2_set_1(void)
{
	LED1_A1_OFF();
	LED1_B1_OFF();
	LED1_C1_OFF();
	LED1_D1_OFF();
	LED1_E1_ON();
	LED1_F1_ON();
	LED1_G1_OFF();
}

void dig2_set_2(void)
{
	LED1_A1_ON();
	LED1_B1_ON();
	LED1_C1_OFF();
	LED1_D1_ON();
	LED1_E1_ON();
	LED1_F1_OFF();
	LED1_G1_ON();
}

void dig2_set_3(void)
{
	LED1_A1_ON();
	LED1_B1_OFF();
	LED1_C1_OFF();
	LED1_D1_ON();
	LED1_E1_ON();
	LED1_F1_ON();
	LED1_G1_ON();
}

void dig2_set_4(void)
{
	LED1_A1_OFF();
	LED1_B1_OFF();
	LED1_C1_ON();
	LED1_D1_OFF();
	LED1_E1_ON();
	LED1_F1_ON();
	LED1_G1_ON();
}

void dig2_set_5(void)
{
	LED1_A1_ON();
	LED1_B1_OFF();
	LED1_C1_ON();
	LED1_D1_ON();
	LED1_E1_OFF();
	LED1_F1_ON();
	LED1_G1_ON();
}

void dig2_set_6(void)
{
	LED1_A1_ON();
	LED1_B1_ON();
	LED1_C1_ON();
	LED1_D1_ON();
	LED1_E1_OFF();
	LED1_F1_ON();
	LED1_G1_ON();
}

void dig2_set_7(void)
{
	LED1_A1_OFF();
	LED1_B1_OFF();
	LED1_C1_OFF();
	LED1_D1_ON();
	LED1_E1_ON();
	LED1_F1_ON();
	LED1_G1_OFF();
}

void dig2_set_8(void)
{
	LED1_A1_ON();
	LED1_B1_ON();
	LED1_C1_ON();
	LED1_D1_ON();
	LED1_E1_ON();
	LED1_F1_ON();
	LED1_G1_ON();
}

void dig2_set_9(void)
{
	LED1_A1_ON();
	LED1_B1_OFF();
	LED1_C1_ON();
	LED1_D1_ON();
	LED1_E1_ON();
	LED1_F1_ON();
	LED1_G1_ON();
}

void dig2_set_off(void)
{
	LED1_A1_OFF();
	LED1_B1_OFF();
	LED1_C1_OFF();
	LED1_D1_OFF();
	LED1_E1_OFF();
	LED1_F1_OFF();
	LED1_G1_OFF();
}
//-----------------------------------------------------------

//----Управление третьей цифрой-----------------------------
void dig3_set_0(void)
{
	LED2_A2_ON();
	LED2_B2_ON();
	LED2_C2_ON();
	LED2_D2_ON();
	LED2_E2_ON();
	LED2_F2_ON();
	LED2_G2_OFF();
}

void dig3_set_1(void)
{
	LED2_A2_OFF();
	LED2_B2_OFF();
	LED2_C2_OFF();
	LED2_D2_OFF();
	LED2_E2_ON();
	LED2_F2_ON();
	LED2_G2_OFF();
}

void dig3_set_2(void)
{
	LED2_A2_ON();
	LED2_B2_ON();
	LED2_C2_OFF();
	LED2_D2_ON();
	LED2_E2_ON();
	LED2_F2_OFF();
	LED2_G2_ON();
}

void dig3_set_3(void)
{
	LED2_A2_ON();
	LED2_B2_OFF();
	LED2_C2_OFF();
	LED2_D2_ON();
	LED2_E2_ON();
	LED2_F2_ON();
	LED2_G2_ON();
}

void dig3_set_4(void)
{
	LED2_A2_OFF();
	LED2_B2_OFF();
	LED2_C2_ON();
	LED2_D2_OFF();
	LED2_E2_ON();
	LED2_F2_ON();
	LED2_G2_ON();
}

void dig3_set_5(void)
{
	LED2_A2_ON();
	LED2_B2_OFF();
	LED2_C2_ON();
	LED2_D2_ON();
	LED2_E2_OFF();
	LED2_F2_ON();
	LED2_G2_ON();
}

void dig3_set_6(void)
{
	LED2_A2_ON();
	LED2_B2_ON();
	LED2_C2_ON();
	LED2_D2_ON();
	LED2_E2_OFF();
	LED2_F2_ON();
	LED2_G2_ON();
}

void dig3_set_7(void)
{
	LED2_A2_OFF();
	LED2_B2_OFF();
	LED2_C2_OFF();
	LED2_D2_ON();
	LED2_E2_ON();
	LED2_F2_ON();
	LED2_G2_OFF();
}

void dig3_set_8(void)
{
	LED2_A2_ON();
	LED2_B2_ON();
	LED2_C2_ON();
	LED2_D2_ON();
	LED2_E2_ON();
	LED2_F2_ON();
	LED2_G2_ON();
}

void dig3_set_9(void)
{
	LED2_A2_ON();
	LED2_B2_OFF();
	LED2_C2_ON();
	LED2_D2_ON();
	LED2_E2_ON();
	LED2_F2_ON();
	LED2_G2_ON();
}

void dig3_set_off(void)
{
	LED2_A2_OFF();
	LED2_B2_OFF();
	LED2_C2_OFF();
	LED2_D2_OFF();
	LED2_E2_OFF();
	LED2_F2_OFF();
	LED2_G2_OFF();
}
//-----------------------------------------------------------

//----Управление четвертой цифрой-----------------------------
void dig4_set_0(void)
{
	LED2_A1_ON();
	LED2_B1_ON();
	LED2_C1_ON();
	LED2_D1_ON();
	LED2_E1_ON();
	LED2_F1_ON();
	LED2_G1_OFF();
}

void dig4_set_1(void)
{
	LED2_A1_OFF();
	LED2_B1_OFF();
	LED2_C1_OFF();
	LED2_D1_OFF();
	LED2_E1_ON();
	LED2_F1_ON();
	LED2_G1_OFF();
}

void dig4_set_2(void)
{
	LED2_A1_ON();
	LED2_B1_ON();
	LED2_C1_OFF();
	LED2_D1_ON();
	LED2_E1_ON();
	LED2_F1_OFF();
	LED2_G1_ON();
}

void dig4_set_3(void)
{
	LED2_A1_ON();
	LED2_B1_OFF();
	LED2_C1_OFF();
	LED2_D1_ON();
	LED2_E1_ON();
	LED2_F1_ON();
	LED2_G1_ON();
}

void dig4_set_4(void)
{
	LED2_A1_OFF();
	LED2_B1_OFF();
	LED2_C1_ON();
	LED2_D1_OFF();
	LED2_E1_ON();
	LED2_F1_ON();
	LED2_G1_ON();
}

void dig4_set_5(void)
{
	LED2_A1_ON();
	LED2_B1_OFF();
	LED2_C1_ON();
	LED2_D1_ON();
	LED2_E1_OFF();
	LED2_F1_ON();
	LED2_G1_ON();
}

void dig4_set_6(void)
{
	LED2_A1_ON();
	LED2_B1_ON();
	LED2_C1_ON();
	LED2_D1_ON();
	LED2_E1_OFF();
	LED2_F1_ON();
	LED2_G1_ON();
}

void dig4_set_7(void)
{
	LED2_A1_OFF();
	LED2_B1_OFF();
	LED2_C1_OFF();
	LED2_D1_ON();
	LED2_E1_ON();
	LED2_F1_ON();
	LED2_G1_OFF();
}

void dig4_set_8(void)
{
	LED2_A1_ON();
	LED2_B1_ON();
	LED2_C1_ON();
	LED2_D1_ON();
	LED2_E1_ON();
	LED2_F1_ON();
	LED2_G1_ON();
}

void dig4_set_9(void)
{
	LED2_A1_ON();
	LED2_B1_OFF();
	LED2_C1_ON();
	LED2_D1_ON();
	LED2_E1_ON();
	LED2_F1_ON();
	LED2_G1_ON();
}

void dig4_set_off(void)
{
	LED2_A1_OFF();
	LED2_B1_OFF();
	LED2_C1_OFF();
	LED2_D1_OFF();
	LED2_E1_OFF();
	LED2_F1_OFF();
	LED2_G1_OFF();
}
//-----------------------------------------------------------

void dig1_set_c(void)
{
	LED1_A2_ON();
	LED1_B2_ON();
	LED1_C2_ON();
	LED1_D2_ON();
	LED1_E2_OFF();
	LED1_F2_OFF();
	LED1_G2_OFF();
}

void dig1_set_y(void)
{
	LED1_A2_ON();
	LED1_B2_OFF();
	LED1_C2_ON();
	LED1_D2_OFF();
	LED1_E2_ON();
	LED1_F2_ON();
	LED1_G2_ON();
}

void dig1_set_a(void)
{
	LED1_A2_OFF();
	LED1_B2_ON();
	LED1_C2_ON();
	LED1_D2_ON();
	LED1_E2_ON();
	LED1_F2_ON();
	LED1_G2_ON();
}

void dig1_set_p(void)
{
	LED1_A2_OFF();
	LED1_B2_ON();
	LED1_C2_ON();
	LED1_D2_ON();
	LED1_E2_ON();
	LED1_F2_OFF();
	LED1_G2_ON();
}

void dig1_set_dash(void)
{
	LED1_A2_OFF();
	LED1_B2_OFF();
	LED1_C2_OFF();
	LED1_D2_OFF();
	LED1_E2_OFF();
	LED1_F2_OFF();
	LED1_G2_ON();
}

void dig1_set_b(void)
{
	LED1_A2_ON();
	LED1_B2_ON();
	LED1_C2_ON();
	LED1_D2_OFF();
	LED1_E2_OFF();
	LED1_F2_ON();
	LED1_G2_ON();
}



void dig1_set(uint8_t number) // установка 3 цифры
{
	if(number == 0)
	{
		dig1_set_0();
	}
	else if(number == 1)
	{
		dig1_set_1();
	}
	else if(number == 2)
	{
		dig1_set_2();
	}
	else if(number == 3)
	{
		dig1_set_3();
	}
	else if(number == 4)
	{
		dig1_set_4();
	}
	else if(number == 5)
	{
		dig1_set_5();
	}
	else if(number == 6)
	{
		dig1_set_6();
	}
	else if(number == 7)
	{
		dig1_set_7();
	}
	else if(number == 8)
	{
		dig1_set_8();
	}
	else if(number == 9)
	{
		dig1_set_9();
	}
}

void dig2_set(uint8_t number) // установка 3 цифры
{
	if(number == 0)
	{
		dig2_set_0();
	}
	else if(number == 1)
	{
		dig2_set_1();
	}
	else if(number == 2)
	{
		dig2_set_2();
	}
	else if(number == 3)
	{
		dig2_set_3();
	}
	else if(number == 4)
	{
		dig2_set_4();
	}
	else if(number == 5)
	{
		dig2_set_5();
	}
	else if(number == 6)
	{
		dig2_set_6();
	}
	else if(number == 7)
	{
		dig2_set_7();
	}
	else if(number == 8)
	{
		dig2_set_8();
	}
	else if(number == 9)
	{
		dig2_set_9();
	}
}

void dig3_set(uint8_t number) // установка 3 цифры
{
	if(number == 0)
	{
		dig3_set_0();
	}
	else if(number == 1)
	{
		dig3_set_1();
	}
	else if(number == 2)
	{
		dig3_set_2();
	}
	else if(number == 3)
	{
		dig3_set_3();
	}
	else if(number == 4)
	{
		dig3_set_4();
	}
	else if(number == 5)
	{
		dig3_set_5();
	}
	else if(number == 6)
	{
		dig3_set_6();
	}
	else if(number == 7)
	{
		dig3_set_7();
	}
	else if(number == 8)
	{
		dig3_set_8();
	}
	else if(number == 9)
	{
		dig3_set_9();
	}
}

void dig4_set(uint8_t number) // установка 4 цифры
{
	if(number == 0)
	{
		dig4_set_0();
	}
	else if(number == 1)
	{
		dig4_set_1();
	}
	else if(number == 2)
	{
		dig4_set_2();
	}
	else if(number == 3)
	{
		dig4_set_3();
	}
	else if(number == 4)
	{
		dig4_set_4();
	}
	else if(number == 5)
	{
		dig4_set_5();
	}
	else if(number == 6)
	{
		dig4_set_6();
	}
	else if(number == 7)
	{
		dig4_set_7();
	}
	else if(number == 8)
	{
		dig4_set_8();
	}
	else if(number == 9)
	{
		dig4_set_9();
	}
}


void minute_display(uint8_t minute) // установка минут на дисплее
{
	dig3_set(minute/10);
	dig4_set(minute%10);
}

void hour_display(uint8_t hour) // установка минут на дисплее
{
	dig1_set(hour/10);
	dig2_set(hour%10);
}

void status_register_display(uint16_t register_number) // функция отрисовки статусного регистра АХХХ на дисплее
{
	dig1_set_p();

	switch( (register_number/100)%10 )
	{
		case 0:

			dig2_set_0();

		break;

		case 1:

			dig2_set_1();

		break;

		case 2:

			dig2_set_2();

		break;

		case 3:

			dig2_set_3();

		break;

		case 4:

			dig2_set_4();

		break;

		case 5:

			dig2_set_5();

		break;

		case 6:

			dig2_set_6();

		break;

		case 7:

			dig2_set_7();

		break;

		case 8:

			dig2_set_8();

		break;

		case 9:

			dig2_set_9();

		break;

	}

	switch( (register_number/10)%10 )
	{
		case 0:

			dig3_set_0();

		break;

		case 1:

			dig3_set_1();

		break;

		case 2:

			dig3_set_2();

		break;

		case 3:

			dig3_set_3();

		break;

		case 4:

			dig3_set_4();

		break;

		case 5:

			dig3_set_5();

		break;

		case 6:

			dig3_set_6();

		break;

		case 7:

			dig3_set_7();

		break;

		case 8:

			dig3_set_8();

		break;

		case 9:

			dig3_set_9();

		break;

	}

	switch( register_number%10 )
	{
		case 0:

			dig4_set_0();

		break;

		case 1:

			dig4_set_1();

		break;

		case 2:

			dig4_set_2();

		break;

		case 3:

			dig4_set_3();

		break;

		case 4:

			dig4_set_4();

		break;

		case 5:

			dig4_set_5();

		break;

		case 6:

			dig4_set_6();

		break;

		case 7:

			dig4_set_7();

		break;

		case 8:

			dig4_set_8();

		break;

		case 9:

			dig4_set_9();

		break;

	}


}

void control_register_display(uint16_t register_number) // функция отрисовки статусного регистра АХХХ на дисплее
{
	dig1_set_y();

	switch( (register_number/100)%10 )
	{
		case 0:

			dig2_set_0();

		break;

		case 1:

			dig2_set_1();

		break;

		case 2:

			dig2_set_2();

		break;

		case 3:

			dig2_set_3();

		break;

		case 4:

			dig2_set_4();

		break;

		case 5:

			dig2_set_5();

		break;

		case 6:

			dig2_set_6();

		break;

		case 7:

			dig2_set_7();

		break;

		case 8:

			dig2_set_8();

		break;

		case 9:

			dig2_set_9();

		break;

	}

	switch( (register_number/10)%10 )
	{
		case 0:

			dig3_set_0();

		break;

		case 1:

			dig3_set_1();

		break;

		case 2:

			dig3_set_2();

		break;

		case 3:

			dig3_set_3();

		break;

		case 4:

			dig3_set_4();

		break;

		case 5:

			dig3_set_5();

		break;

		case 6:

			dig3_set_6();

		break;

		case 7:

			dig3_set_7();

		break;

		case 8:

			dig3_set_8();

		break;

		case 9:

			dig3_set_9();

		break;

	}

	switch( register_number%10 )
	{
		case 0:

			dig4_set_0();

		break;

		case 1:

			dig4_set_1();

		break;

		case 2:

			dig4_set_2();

		break;

		case 3:

			dig4_set_3();

		break;

		case 4:

			dig4_set_4();

		break;

		case 5:

			dig4_set_5();

		break;

		case 6:

			dig4_set_6();

		break;

		case 7:

			dig4_set_7();

		break;

		case 8:

			dig4_set_8();

		break;

		case 9:

			dig4_set_9();

		break;

	}


}

void number_display(uint8_t number)
{
	dig1_set_off();

	switch( (number/100)%10 )
	{
		case 0:

			dig2_set_0();

		break;

		case 1:

			dig2_set_1();

		break;

		case 2:

			dig2_set_2();

		break;

		case 3:

			dig2_set_3();

		break;

		case 4:

			dig2_set_4();

		break;

		case 5:

			dig2_set_5();

		break;

		case 6:

			dig2_set_6();

		break;

		case 7:

			dig2_set_7();

		break;

		case 8:

			dig2_set_8();

		break;

		case 9:

			dig2_set_9();

		break;

	}

	switch( (number/10)%10 )
	{
		case 0:

			dig3_set_0();

		break;

		case 1:

			dig3_set_1();

		break;

		case 2:

			dig3_set_2();

		break;

		case 3:

			dig3_set_3();

		break;

		case 4:

			dig3_set_4();

		break;

		case 5:

			dig3_set_5();

		break;

		case 6:

			dig3_set_6();

		break;

		case 7:

			dig3_set_7();

		break;

		case 8:

			dig3_set_8();

		break;

		case 9:

			dig3_set_9();

		break;

	}

	switch( number%10 )
	{
		case 0:

			dig4_set_0();

		break;

		case 1:

			dig4_set_1();

		break;

		case 2:

			dig4_set_2();

		break;

		case 3:

			dig4_set_3();

		break;

		case 4:

			dig4_set_4();

		break;

		case 5:

			dig4_set_5();

		break;

		case 6:

			dig4_set_6();

		break;

		case 7:

			dig4_set_7();

		break;

		case 8:

			dig4_set_8();

		break;

		case 9:

			dig4_set_9();

		break;

	}
}

void number_change_display(uint8_t number)
{
	dig1_set_dash();

	switch( (number/100)%10 )
	{
		case 0:

			dig2_set_0();

		break;

		case 1:

			dig2_set_1();

		break;

		case 2:

			dig2_set_2();

		break;

		case 3:

			dig2_set_3();

		break;

		case 4:

			dig2_set_4();

		break;

		case 5:

			dig2_set_5();

		break;

		case 6:

			dig2_set_6();

		break;

		case 7:

			dig2_set_7();

		break;

		case 8:

			dig2_set_8();

		break;

		case 9:

			dig2_set_9();

		break;

	}

	switch( (number/10)%10 )
	{
		case 0:

			dig3_set_0();

		break;

		case 1:

			dig3_set_1();

		break;

		case 2:

			dig3_set_2();

		break;

		case 3:

			dig3_set_3();

		break;

		case 4:

			dig3_set_4();

		break;

		case 5:

			dig3_set_5();

		break;

		case 6:

			dig3_set_6();

		break;

		case 7:

			dig3_set_7();

		break;

		case 8:

			dig3_set_8();

		break;

		case 9:

			dig3_set_9();

		break;

	}

	switch( number%10 )
	{
		case 0:

			dig4_set_0();

		break;

		case 1:

			dig4_set_1();

		break;

		case 2:

			dig4_set_2();

		break;

		case 3:

			dig4_set_3();

		break;

		case 4:

			dig4_set_4();

		break;

		case 5:

			dig4_set_5();

		break;

		case 6:

			dig4_set_6();

		break;

		case 7:

			dig4_set_7();

		break;

		case 8:

			dig4_set_8();

		break;

		case 9:

			dig4_set_9();

		break;

	}
}

void ibutton_a_register_display(uint16_t register_number) // функция отрисовки I-button регистра группы А на дисплее
{
	dig1_set_a();

	switch( (register_number/100)%10 )
	{
		case 0:

			dig2_set_0();

		break;

		case 1:

			dig2_set_1();

		break;

		case 2:

			dig2_set_2();

		break;

		case 3:

			dig2_set_3();

		break;

		case 4:

			dig2_set_4();

		break;

		case 5:

			dig2_set_5();

		break;

		case 6:

			dig2_set_6();

		break;

		case 7:

			dig2_set_7();

		break;

		case 8:

			dig2_set_8();

		break;

		case 9:

			dig2_set_9();

		break;

	}

	switch( (register_number/10)%10 )
	{
		case 0:

			dig3_set_0();

		break;

		case 1:

			dig3_set_1();

		break;

		case 2:

			dig3_set_2();

		break;

		case 3:

			dig3_set_3();

		break;

		case 4:

			dig3_set_4();

		break;

		case 5:

			dig3_set_5();

		break;

		case 6:

			dig3_set_6();

		break;

		case 7:

			dig3_set_7();

		break;

		case 8:

			dig3_set_8();

		break;

		case 9:

			dig3_set_9();

		break;

	}

	switch( register_number%10 )
	{
		case 0:

			dig4_set_0();

		break;

		case 1:

			dig4_set_1();

		break;

		case 2:

			dig4_set_2();

		break;

		case 3:

			dig4_set_3();

		break;

		case 4:

			dig4_set_4();

		break;

		case 5:

			dig4_set_5();

		break;

		case 6:

			dig4_set_6();

		break;

		case 7:

			dig4_set_7();

		break;

		case 8:

			dig4_set_8();

		break;

		case 9:

			dig4_set_9();

		break;

	}


}

void ibutton_b_register_display(uint16_t register_number) // функция отрисовки I-button регистра группы В на дисплее
{
	dig1_set_b();

	switch( (register_number/100)%10 )
	{
		case 0:

			dig2_set_0();

		break;

		case 1:

			dig2_set_1();

		break;

		case 2:

			dig2_set_2();

		break;

		case 3:

			dig2_set_3();

		break;

		case 4:

			dig2_set_4();

		break;

		case 5:

			dig2_set_5();

		break;

		case 6:

			dig2_set_6();

		break;

		case 7:

			dig2_set_7();

		break;

		case 8:

			dig2_set_8();

		break;

		case 9:

			dig2_set_9();

		break;

	}

	switch( (register_number/10)%10 )
	{
		case 0:

			dig3_set_0();

		break;

		case 1:

			dig3_set_1();

		break;

		case 2:

			dig3_set_2();

		break;

		case 3:

			dig3_set_3();

		break;

		case 4:

			dig3_set_4();

		break;

		case 5:

			dig3_set_5();

		break;

		case 6:

			dig3_set_6();

		break;

		case 7:

			dig3_set_7();

		break;

		case 8:

			dig3_set_8();

		break;

		case 9:

			dig3_set_9();

		break;

	}

	switch( register_number%10 )
	{
		case 0:

			dig4_set_0();

		break;

		case 1:

			dig4_set_1();

		break;

		case 2:

			dig4_set_2();

		break;

		case 3:

			dig4_set_3();

		break;

		case 4:

			dig4_set_4();

		break;

		case 5:

			dig4_set_5();

		break;

		case 6:

			dig4_set_6();

		break;

		case 7:

			dig4_set_7();

		break;

		case 8:

			dig4_set_8();

		break;

		case 9:

			dig4_set_9();

		break;

	}


}


