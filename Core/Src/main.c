/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "stdio.h"
#include "ibutton.h"
#include "fm25v02.h"
#include "gpio.h"
#include "string.h"
#include "m95.h"
#include "modbus.h"
#include "da04_11gwa.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
 ADC_HandleTypeDef hadc1;

I2C_HandleTypeDef hi2c1;

IWDG_HandleTypeDef hiwdg;

RTC_HandleTypeDef hrtc;

SPI_HandleTypeDef hspi2;
SPI_HandleTypeDef hspi3;

TIM_HandleTypeDef htim2;

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;
UART_HandleTypeDef huart3;
UART_HandleTypeDef huart6;
DMA_HandleTypeDef hdma_usart3_tx;
DMA_HandleTypeDef hdma_usart3_rx;
DMA_HandleTypeDef hdma_usart6_tx;
DMA_HandleTypeDef hdma_usart6_rx;

osThreadId defaultTaskHandle;
/* USER CODE BEGIN PV */

osMessageQId ModbusQueueHandle;
osMessageQId MeterQueueHandle;
osTimerId AT_TimerHandle;
osTimerId Ring_Center_TimerHandle;
osMutexId UartMutexHandle;
osSemaphoreId TransmissionStateHandle;
osSemaphoreId ReceiveStateHandle;
osSemaphoreId RS485TransmissionStateHandle;

osThreadId IbuttonTaskHandle;
osThreadId SecurityTaskHandle;
osThreadId M95TaskHandle;
osThreadId ModbusTaskHandle;
osThreadId MainTaskHandle;
osThreadId ModbusPacketTaskHandle;
osThreadId CallRingCenterTaskHandle;
osThreadId LedTaskHandle;
osThreadId ArmingTaskHandle;
osThreadId ReadRegistersTaskHandle;
osThreadId EventWriteTaskHandle;
osThreadId GetCurrentTaskHandle;
osThreadId MeterTaskHandle;
osThreadId MeterPacketTaskHandle;
osThreadId DisplayTaskHandle;


osThreadId CurrentID;
osMutexId Fm25v02MutexHandle;

osSemaphoreId ModbusPacketReceiveHandle;
osSemaphoreId CallRingCenterHandle;

volatile uint8_t security_state = 0x00;
RTC_TimeTypeDef security_time;
RTC_DateTypeDef security_date;

uint8_t flash[20];
uint8_t flash1[20];

uint8_t modem_tx_data[256];
uint8_t modem_rx_data[256];
char modem_rx_buffer[256];
uint8_t modbus_buffer[20][256];
uint8_t modem_rx_number = 0;
uint8_t modbus_buffer_number = 0;

volatile uint8_t read_rx_state;

extern control_register_struct control_registers;

uint8_t meter_data[256];
uint8_t meter_rx_buffer[256];
uint8_t meter_rx_number = 0;
/*
extern uint16_t data_in[3];
volatile uint32_t cur_data[3] = {0,0,0};
volatile uint16_t cur_counter = 0;
volatile uint32_t cur_a_average;
volatile uint32_t cur_b_average;
volatile uint32_t cur_c_average;
volatile uint32_t cur_a;
volatile uint32_t cur_b;
volatile uint32_t cur_c;

double data_lux;
bool gain=0;        // Gain setting, 0 = X1, 1 = X16;
unsigned char time = 2;
unsigned int ms;
unsigned int data0, data2;
double lux;    // Resulting lux value
*/

volatile uint8_t modem_reset_state = 0;

volatile uint16_t key1_state = 0;
volatile uint8_t key1_on_state = 0;
volatile uint8_t key1_press_state = 0;

volatile uint16_t key2_state = 0;
volatile uint8_t key2_on_state = 0;
volatile uint8_t key2_press_state = 0;

volatile uint16_t key3_state = 0;
volatile uint8_t key3_on_state = 0;
volatile uint8_t key3_press_state = 0;

volatile uint16_t key4_state = 0;
volatile uint8_t key4_on_state = 0;
volatile uint8_t key4_press_state = 0;

volatile uint16_t key_speed = 0;
volatile uint16_t key_delay = 200;

volatile uint8_t key1_off_state = 0;
volatile uint8_t key2_off_state = 0;

volatile uint16_t reset_display_time_state = 30001;

extern volatile uint8_t control_register_increment_state;
extern volatile uint8_t control_register_decrement_state;
extern volatile uint8_t control_register_save_state;

extern volatile uint16_t register_menu_state;
extern volatile uint16_t register_content_menu_state;

extern uint8_t spi_buf[4];

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_RTC_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_USART3_UART_Init(void);
static void MX_USART6_UART_Init(void);
static void MX_IWDG_Init(void);
static void MX_SPI2_Init(void);
static void MX_TIM2_Init(void);
static void MX_ADC1_Init(void);
static void MX_I2C1_Init(void);
static void MX_SPI3_Init(void);
static void MX_USART2_UART_Init(void);
void StartDefaultTask(void const * argument);

/* USER CODE BEGIN PFP */

void Callback_AT_Timer(void const * argument);
void Callback_Ring_Center_Timer(void const * argument);

void ThreadIbuttonTask(void const * argument);
void ThreadSecurityTask(void const * argument);
void ThreadM95Task(void const * argument);
void ThreadModbusTask(void const * argument);
void ThreadMainTask(void const * argument);
void ThreadModbusPacketTask(void const * argument);
void ThreadCallRingCenterTask(void const * argument);
void ThreadLedTask(void const * argument);
void ThreadArmingTask(void const * argument);
void ThreadReadRegistersTask(void const * argument);
void ThreadEventWriteTask(void const * argument);
void ThreadGetCurrentTask(void const * argument);
void ThreadMeterTask(void const * argument);
void ThreadMeterPacketTask(void const * argument);
void ThreadDisplayTask(void const * argument);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
	  if (huart->Instance == USART3)
	  {
		  osSemaphoreRelease(TransmissionStateHandle);
	  }

	  if (huart->Instance == USART6)
	  {
		  //LED8_TOGGLE();
		  osSemaphoreRelease(RS485TransmissionStateHandle);
		  HAL_GPIO_WritePin(GPIOG, GPIO_PIN_10, GPIO_PIN_RESET); // устанавливаем микросхему на прием
		  HAL_UART_Receive_DMA(&huart6, &meter_data[0], 1); // включаем прием со счетчика

	  }

}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{

	  if (huart->Instance == USART3)
	  {
		  //LED_VD5_TOGGLE();
		  modem_rx_buffer[modem_rx_number++] = modem_rx_data[0];
		  osMessagePut(ModbusQueueHandle, (uint32_t)modem_rx_data[0], 2000);
		  HAL_UART_Receive_DMA(&huart3, &modem_rx_data[0], 1);
	  }

	  if (huart->Instance == USART6)
	  {
		  //LED7_TOGGLE();
		  meter_data[0] = meter_data[0]&0x7F;
		  meter_rx_buffer[meter_rx_number++] = meter_data[0];
		  HAL_GPIO_WritePin(GPIOG, GPIO_PIN_10, GPIO_PIN_RESET); // устанавливаем микросхему на прием
		  HAL_UART_Receive_DMA(&huart6, &meter_data[0], 1); // включаем прием со счетчика

		  //if(meter_rx_number>10){meter_rx_number=0;}

	  }

}

/*
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
  if(hadc->Instance == ADC1)
  {
	//LED_VD5_TOGGLE();

	cur_data[0] = cur_data[0] + data_in[0];
	cur_data[1] = cur_data[1] + data_in[1];
	cur_data[2] = cur_data[2] + data_in[2];

	cur_counter++;

	if(cur_counter>=100)
	{
		cur_counter=0;

		cur_a_average = cur_data[0]/100;
		cur_b_average = cur_data[1]/100;
		cur_c_average = cur_data[2]/100;

		cur_data[0] = 0;
		cur_data[1] = 0;
		cur_data[2] = 0;

		cur_a = cur_a_average*1300/4095; // 283
		cur_b = cur_b_average*1300/4095; // 283
		cur_c = cur_c_average*1300/4095; // 283

	}



	//osThreadResume(GetCurrentTaskHandle);
    //for (uint8_t i = 0; i < ADC_CHANNELS_NUM; i++)
    //{
      //adcVoltage[i] = adcData[i] * 3.3 / 4095;
    //}
  }
}

*/

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_RTC_Init();
  MX_USART1_UART_Init();
  MX_USART3_UART_Init();
  MX_USART6_UART_Init();
  MX_IWDG_Init();
  MX_SPI2_Init();
  MX_TIM2_Init();
  MX_ADC1_Init();
  MX_I2C1_Init();
  MX_SPI3_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */

  BUZ_ON();
  HAL_Delay(50);
  BUZ_OFF();

  if( ((RCC->BDCR)&0x02) != 0 ) // Проверяем, запустился ли часовой кварц, если запустился включаем светодиод
  {
	  //LED_VD4_ON();
  }
  else
  {
	  //LED_VD4_OFF();
  }

    /*
  		for(uint16_t i=0x1000; i<=0x10FF; i++)
	{
		fm25v02_write(2*i, 0x00);
		fm25v02_write(2*i+1, 0x00);
	}

	fm25v02_write(2*IP_1_REG, 0x00);
	fm25v02_write(2*IP_1_REG+1, 195);
	fm25v02_write(2*IP_2_REG, 0x00);
	fm25v02_write(2*IP_2_REG+1, 208);
	fm25v02_write(2*IP_3_REG, 0x00);
	fm25v02_write(2*IP_3_REG+1, 163);
	fm25v02_write(2*IP_4_REG, 0x00);
	fm25v02_write(2*IP_4_REG+1, 67);
	fm25v02_write(2*PORT_HIGH_REG, 0x00);
	fm25v02_write(2*PORT_HIGH_REG+1, 136);
	fm25v02_write(2*PORT_LOW_REG, 0x00);
	fm25v02_write(2*PORT_LOW_REG+1, 234);

	fm25v02_write(2*ID_HIGH_REG, 0x00);
	fm25v02_write(2*ID_HIGH_REG+1, 0x00);

	fm25v02_write(2*ID_LOW_REG, 0x00);
	fm25v02_write(2*ID_LOW_REG+1, 0x00);
	*/

  /* USER CODE END 2 */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */

  osMutexDef(UartMutex);
  UartMutexHandle = osMutexCreate(osMutex(UartMutex));

  osMutexDef(Fm25v02Mutex);
  Fm25v02MutexHandle = osMutexCreate(osMutex(Fm25v02Mutex));

  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */

  osSemaphoreDef(TransmissionState);
  TransmissionStateHandle = osSemaphoreCreate(osSemaphore(TransmissionState), 1);

  osSemaphoreDef(ReceiveState);
  ReceiveStateHandle = osSemaphoreCreate(osSemaphore(ReceiveState), 1);

  osSemaphoreDef(RS485TransmissionState);
  RS485TransmissionStateHandle = osSemaphoreCreate(osSemaphore(RS485TransmissionState), 1);

  osSemaphoreDef(ModbusPacketReceive);
  ModbusPacketReceiveHandle = osSemaphoreCreate(osSemaphore(ModbusPacketReceive), 1);

  osSemaphoreDef(CallRingCenter);
  CallRingCenterHandle = osSemaphoreCreate(osSemaphore(CallRingCenter), 1);

  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */

  osTimerDef(AT_Timer, Callback_AT_Timer);
  AT_TimerHandle = osTimerCreate(osTimer(AT_Timer), osTimerOnce, NULL);

  osTimerDef(Ring_Center_Timer, Callback_Ring_Center_Timer);
  Ring_Center_TimerHandle = osTimerCreate(osTimer(Ring_Center_Timer), osTimerOnce, NULL);

  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */

  osMessageQDef(ModbusQueue, 256, uint8_t);
  ModbusQueueHandle = osMessageCreate(osMessageQ(ModbusQueue), NULL);

  osMessageQDef(MeterQueue, 256, uint8_t);
  MeterQueueHandle = osMessageCreate(osMessageQ(MeterQueue), NULL);

  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */

  osThreadDef(IbuttonTask, ThreadIbuttonTask, osPriorityNormal, 0, 128);
  IbuttonTaskHandle = osThreadCreate(osThread(IbuttonTask), NULL);

  osThreadDef(SecurityTask, ThreadSecurityTask, osPriorityNormal, 0, 128);
  SecurityTaskHandle = osThreadCreate(osThread(SecurityTask), NULL);

  osThreadDef(M95Task, ThreadM95Task, osPriorityNormal, 0, 128);
  M95TaskHandle = osThreadCreate(osThread(M95Task), NULL);

  osThreadDef(ModbusTask, ThreadModbusTask, osPriorityNormal, 0, 128);
  ModbusTaskHandle = osThreadCreate(osThread(ModbusTask), NULL);

  osThreadDef(MainTask, ThreadMainTask, osPriorityNormal, 0, 128);
  MainTaskHandle = osThreadCreate(osThread(MainTask), NULL);

  osThreadDef(ModbusPacketTask, ThreadModbusPacketTask, osPriorityNormal, 0, 128);
  ModbusPacketTaskHandle = osThreadCreate(osThread(ModbusPacketTask), NULL);

  osThreadDef(CallRingCenterTask, ThreadCallRingCenterTask, osPriorityNormal, 0, 128);
  CallRingCenterTaskHandle = osThreadCreate(osThread(CallRingCenterTask), NULL);

  osThreadDef(LedTask, ThreadLedTask, osPriorityNormal, 0, 128);
  LedTaskHandle = osThreadCreate(osThread(LedTask), NULL);

  osThreadDef(ArmingTask, ThreadArmingTask, osPriorityNormal, 0, 128);
  ArmingTaskHandle = osThreadCreate(osThread(ArmingTask), NULL);

  osThreadDef(ReadRegistersTask, ThreadReadRegistersTask, osPriorityNormal, 0, 128);
  ReadRegistersTaskHandle = osThreadCreate(osThread(ReadRegistersTask), NULL);

  osThreadDef(EventWriteTask, ThreadEventWriteTask, osPriorityNormal, 0, 128);
  EventWriteTaskHandle = osThreadCreate(osThread(EventWriteTask), NULL);

  osThreadDef(MeterTask, ThreadMeterTask, osPriorityNormal, 0, 128);
  MeterTaskHandle = osThreadCreate(osThread(MeterTask), NULL);

  osThreadDef(DisplayTask, ThreadDisplayTask, osPriorityNormal, 0, 128);
  DisplayTaskHandle = osThreadCreate(osThread(DisplayTask), NULL);

  /* USER CODE END RTOS_THREADS */

  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI|RCC_OSCILLATORTYPE_HSE
                              |RCC_OSCILLATORTYPE_LSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */

  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.ScanConvMode = ENABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 3;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_10;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_15CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_12;
  sConfig.Rank = 2;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_13;
  sConfig.Rank = 3;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief IWDG Initialization Function
  * @param None
  * @retval None
  */
static void MX_IWDG_Init(void)
{

  /* USER CODE BEGIN IWDG_Init 0 */

  /* USER CODE END IWDG_Init 0 */

  /* USER CODE BEGIN IWDG_Init 1 */

  /* USER CODE END IWDG_Init 1 */
  hiwdg.Instance = IWDG;
  hiwdg.Init.Prescaler = IWDG_PRESCALER_32;
  hiwdg.Init.Reload = 4000;
  if (HAL_IWDG_Init(&hiwdg) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN IWDG_Init 2 */

  /* USER CODE END IWDG_Init 2 */

}

/**
  * @brief RTC Initialization Function
  * @param None
  * @retval None
  */
static void MX_RTC_Init(void)
{

  /* USER CODE BEGIN RTC_Init 0 */

  /* USER CODE END RTC_Init 0 */

  RTC_TimeTypeDef sTime = {0};
  RTC_DateTypeDef sDate = {0};

  /* USER CODE BEGIN RTC_Init 1 */

  /* USER CODE END RTC_Init 1 */

  /** Initialize RTC Only
  */
  hrtc.Instance = RTC;
  hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
  hrtc.Init.AsynchPrediv = 127;
  hrtc.Init.SynchPrediv = 255;
  hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
  hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
  hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
  if (HAL_RTC_Init(&hrtc) != HAL_OK)
  {
    Error_Handler();
  }

  /* USER CODE BEGIN Check_RTC_BKUP */

  /* USER CODE END Check_RTC_BKUP */

  /** Initialize RTC and set the Time and Date
  */
  sTime.Hours = 0x0;
  sTime.Minutes = 0x0;
  sTime.Seconds = 0x0;
  sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
  sTime.StoreOperation = RTC_STOREOPERATION_RESET;
  //if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BCD) != HAL_OK)
  //{
    //Error_Handler();
  //}
  sDate.WeekDay = RTC_WEEKDAY_MONDAY;
  sDate.Month = RTC_MONTH_JANUARY;
  sDate.Date = 0x1;
  sDate.Year = 0x0;

  //if (HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BCD) != HAL_OK)
  //{
    //Error_Handler();
  //}
  /* USER CODE BEGIN RTC_Init 2 */

  /* USER CODE END RTC_Init 2 */

}

/**
  * @brief SPI2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI2_Init(void)
{

  /* USER CODE BEGIN SPI2_Init 0 */

  /* USER CODE END SPI2_Init 0 */

  /* USER CODE BEGIN SPI2_Init 1 */

  /* USER CODE END SPI2_Init 1 */
  /* SPI2 parameter configuration*/
  hspi2.Instance = SPI2;
  hspi2.Init.Mode = SPI_MODE_MASTER;
  hspi2.Init.Direction = SPI_DIRECTION_2LINES;
  hspi2.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi2.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi2.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi2.Init.NSS = SPI_NSS_SOFT;
  hspi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_32;
  hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi2.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi2.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI2_Init 2 */

  /* USER CODE END SPI2_Init 2 */

}

/**
  * @brief SPI3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI3_Init(void)
{

  /* USER CODE BEGIN SPI3_Init 0 */

  /* USER CODE END SPI3_Init 0 */

  /* USER CODE BEGIN SPI3_Init 1 */

  /* USER CODE END SPI3_Init 1 */
  /* SPI3 parameter configuration*/
  hspi3.Instance = SPI3;
  hspi3.Init.Mode = SPI_MODE_MASTER;
  hspi3.Init.Direction = SPI_DIRECTION_1LINE;
  hspi3.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi3.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi3.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi3.Init.NSS = SPI_NSS_SOFT;
  hspi3.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_32;
  hspi3.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi3.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi3.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi3.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI3_Init 2 */

  /* USER CODE END SPI3_Init 2 */

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 83;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 999;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief USART3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 9600;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */

  /* USER CODE END USART3_Init 2 */

}

/**
  * @brief USART6 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART6_UART_Init(void)
{

  /* USER CODE BEGIN USART6_Init 0 */

  /* USER CODE END USART6_Init 0 */

  /* USER CODE BEGIN USART6_Init 1 */

  /* USER CODE END USART6_Init 1 */
  huart6.Instance = USART6;
  huart6.Init.BaudRate = 9600;
  huart6.Init.WordLength = UART_WORDLENGTH_8B;
  huart6.Init.StopBits = UART_STOPBITS_1;
  huart6.Init.Parity = UART_PARITY_EVEN;
  huart6.Init.Mode = UART_MODE_TX_RX;
  huart6.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart6.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart6) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART6_Init 2 */

  /* USER CODE END USART6_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();
  __HAL_RCC_DMA2_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Stream1_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Stream1_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream1_IRQn);
  /* DMA1_Stream3_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Stream3_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream3_IRQn);
  /* DMA2_Stream1_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA2_Stream1_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(DMA2_Stream1_IRQn);
  /* DMA2_Stream6_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA2_Stream6_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(DMA2_Stream6_IRQn);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5
                          |GPIO_PIN_6|GPIO_PIN_15|GPIO_PIN_1, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13|GPIO_PIN_1, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0|GPIO_PIN_1, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12|GPIO_PIN_5, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10|GPIO_PIN_11, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_11, GPIO_PIN_SET);

  /*Configure GPIO pins : PE2 PE3 PE4 PE5
                           PE6 PE15 PE1 */
  GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5
                          |GPIO_PIN_6|GPIO_PIN_15|GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : PC13 PC1 PC11 */
  GPIO_InitStruct.Pin = GPIO_PIN_13|GPIO_PIN_1|GPIO_PIN_11;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PA0 PA1 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PA4 PA5 PA6 PA7 */
  GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PC4 PC5 */
  GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PE7 PE8 PE9 PE10
                           PE0 */
  GPIO_InitStruct.Pin = GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10
                          |GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : PB12 PB5 */
  GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PD10 PD11 */
  GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_11;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

void Callback_AT_Timer(void const * argument)
{

	read_rx_state = NOT_ACTIVE;

}

void Callback_Ring_Center_Timer(void const * argument)
{
	modem_reset_state = 1;
	//NVIC_SystemReset();
}

/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN 5 */
  /* Infinite loop */
  for(;;)
  {
	HAL_IWDG_Refresh(&hiwdg);
	//LED_VD3_TOGGLE();

	osDelay(1000);
  }
  /* USER CODE END 5 */
}

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM1 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM1) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

	if(htim->Instance == TIM2)
	{
		TIM2->CNT = 0;

//----программа обработки кнопки 1----------------------------------------------

		if( HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_7) == GPIO_PIN_RESET)
		{
			//spi_buf[0] = 1;
			if(key1_state<key_delay)
			{
				key1_state++;
			}
			else if(key1_state==key_delay)
			{
				key1_state++;
				key1_press_state = 1;

			}

			key1_off_state = 0;

		}
		else
		{

			if( (key1_state>5)&&(key1_state<key_delay) )
			{
				key1_state = 0;
				key1_on_state = 1;

				//key_speed = 0;
				key_delay = 200;
			}
			else if(key1_state>=key_delay)
			{
				key1_state = 0;

				//key_speed = 0;
				key_delay = 200;
			}
			//else if(key1_state == 0)
			//{
				//key_delay = 200;
			//}
			//else if(key1_state>0)
			//{
				//key_delay = 200;
			//}

			if(key1_off_state<20)
			{
				key1_off_state++;
				if(key1_off_state==20)
				{
					key_delay = 200;
				}
			}

		}

		if(key1_on_state == 1) // обработчик короткого нажатия кнопки 1
		{
			key1_on_state = 0; // обнуление состояния короткого нажатия на кнопку 1

			reset_display_time_state = 0;

			if(register_menu_state > 0)
			{
				if(register_content_menu_state == 0)
				{
					register_menu_state--;
					//reset_display_time_state = 0;
				}
				else if(register_content_menu_state == 2)
				{
					control_register_decrement_state = 1;
				}
			}

		}

		if(key1_press_state == 1) // обработчик длительного нажатия кнопки 1
		{
			key1_press_state = 0; // обнуление состояния длинного нажатия на кнопку 1

			reset_display_time_state = 0;

			if(register_menu_state > 0)
			{
				if(register_content_menu_state == 0)
				{
					register_menu_state--;

					if(key_delay>10)
					{
						key_delay = key_delay - 10;
					}

					//register_menu_state = register_menu_state - ( 1+(key_speed/10) );
				}
				else if(register_content_menu_state == 2)
				{
					control_register_decrement_state = 1;

					if(key_delay>5)
					{
						key_delay = key_delay - 5;
					}

				}
			}

			key1_state = 0;


		}

//----------------------------------------------------------------------------------

//----программа обработки кнопки 2----------------------------------------------

		if( HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_8) == GPIO_PIN_RESET)
		{
			//spi_buf[0] = 2;
			if(key2_state<key_delay)
			{

				key2_state++;

			}
			else if(key2_state==key_delay)
			{
				key2_state++;
				key2_press_state = 1;
			}

			key2_off_state = 0;

		}
		else
		{
			if( (key2_state>5)&&(key2_state<key_delay) )
			{
				key2_state = 0;
				key2_on_state = 1;

				//key_speed = 0;
				key_delay = 200;
			}
			else if(key2_state>=key_delay)
			{
				key2_state = 0;

				//key_speed = 0;
				key_delay = 200;
			}
			//else if(key2_state == 0)
			//{
				//key_delay = 200;
			//}
			//else if(key2_state>0)
			//{
				//key_delay = 200;
			//}
			if(key2_off_state<20)
			{
				key2_off_state++;
				if(key2_off_state==20)
				{
					key_delay = 200;
				}
			}

		}

		if(key2_on_state == 1) // обработчик короткого нажатия кнопки 2
		{
			key2_on_state = 0; // обнуление состояния короткого нажатия на кнопку 2

			reset_display_time_state = 0;

			if(register_menu_state < MAX_MENU_NUMBER)
			{
				if(register_content_menu_state == 0)
				{
					register_menu_state++;

				}
				else if(register_content_menu_state == 2)
				{
					control_register_increment_state = 1;
				}
			}

		}
		if(key2_press_state == 1) // обработчик длительного нажатия кнопки 2
		{
			key2_press_state = 0; // обнуление состояния длинного нажатия на кнопку 2

			reset_display_time_state = 0;

			if(register_menu_state < MAX_MENU_NUMBER)
			{
				if(register_content_menu_state == 0)
				{
					register_menu_state++;

					if(key_delay>10)
					{
						key_delay = key_delay - 10;
					}

					//register_menu_state = register_menu_state + ( 1+(key_speed/10) );
				}
				else if(register_content_menu_state == 2)
				{
					control_register_increment_state = 1;

					if(key_delay>5)
					{
						key_delay = key_delay - 5;
					}

				}
			}

			key2_state = 0;
		}

//----------------------------------------------------------------------------------

		//----программа обработки кнопки 3----------------------------------------------

				if( HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_9) == GPIO_PIN_RESET)
				{
					if(key3_state<2000)
					{

						key3_state++;

					}
					else if(key3_state==2000)
					{
						key3_state++;
						key3_press_state = 1;
					}
				}
				else
				{
					if( (key3_state>5)&&(key3_state<2000) )
					{
						key3_state = 0;
						key3_on_state = 1;
					}
					else if(key3_state>=2000)
					{
						key3_state = 0;
					}
				}

				if(key3_on_state == 1) // обработчик короткого нажатия кнопки 3
				{
					key3_on_state = 0; // обнуление состояния короткого нажатия на кнопку 3

					reset_display_time_state = 0;

					if(register_content_menu_state == 1)
					{
						register_content_menu_state--;
						//reset_display_time_state = 0;
					}
				}
				if(key3_press_state == 1) // обработчик длительного нажатия кнопки 3
				{
					key3_press_state = 0; // обнуление состояния длинного нажатия на кнопку 3
				}

		//----------------------------------------------------------------------------------

				//----программа обработки кнопки 4----------------------------------------------

						if( HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_10) == GPIO_PIN_RESET)
						{
							if(key4_state<2000)
							{

								key4_state++;

							}
							else if(key4_state==2000)
							{
								key4_state++;
								key4_press_state = 1;
							}
						}
						else
						{
							if( (key4_state>5)&&(key4_state<2000) )
							{
								key4_state = 0;
								key4_on_state = 1;
							}
							else if(key4_state>=2000)
							{
								key4_state = 0;
							}
						}

						if(key4_on_state == 1) // обработчик короткого нажатия кнопки 4
						{
							key4_on_state = 0; // обнуление состояния короткого нажатия на кнопку 4

							reset_display_time_state = 0;

							if(register_content_menu_state == 0)
							{
								register_content_menu_state++;
								//reset_display_time_state = 0;
							}
						}
						if(key4_press_state == 1) // обработчик длительного нажатия кнопки 4
						{
							key4_press_state = 0; // обнуление состояния длинного нажатия на кнопку 4

							if( (register_content_menu_state == 1) && (register_menu_state >= Y1) && (register_menu_state <= MAX_B_NUMBER) )
							{
								register_content_menu_state = 2;
								//LED_VD4_ON();
							}

							else if( register_content_menu_state == 2 )
							{
								//register_content_menu_state = 1;
								control_register_save_state = 1;
								//LED_VD4_OFF();
							}
						}

				//----------------------------------------------------------------------------------

		if( reset_display_time_state < 30000)
		{
			reset_display_time_state++;
		}

		else if( reset_display_time_state == 30000)
		{
			register_content_menu_state = 0;
			register_menu_state = 0;
			reset_display_time_state = 30001;
		}


	}

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */

	NVIC_SystemReset();

  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
