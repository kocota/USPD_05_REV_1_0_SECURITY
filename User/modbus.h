#ifndef MODBUS
#define MODBUS

#include "stm32f4xx_hal.h"

unsigned int CRC16( unsigned char * pucFrame, unsigned int usLen );


//---- Описание регистров статуса -----------------------------

#define VERSION_REG                      0x1000 // (4096) версия прошивки контроллера
#define SECURITY_STATUS_REG              0x1001 // (4097) статус режима охраны (0 - резерв ;1- включена из центра; 2 - отключена из центра; 3 - включена таблеткой 4 - отключена таблеткой; 5 - тревога открытия двери; 6 - процесс постановки на охрану; 7 - не удаётся поставить на охрану; )
#define STATUS_LOOP_REG                  0x1002 // (4098) состояние шлейфов сигнализации (номер бита соответствует номеру шлейфа (6 шлейфов) 1 - замкнут)
#define ERROR_LOOP_REG                   0x1003 // (4099) неисправные шлейфы (номер бита соответствует номеру шлейфа (6 шлейфов))
#define ALARM_LOOP_REG                   0x1004 // (4100) сработавшие шлейфы
#define TIME_CURRENT_YEAR_REG            0x1005 // (4101) текущий год
#define TIME_CURRENT_MONTH_REG           0x1006 // (4102) текущий месяц
#define TIME_CURRENT_DAY_REG             0x1007 // (4103) текущий день
#define TIME_CURRENT_HOUR_REG			 0x1008 // (4104) текущий час
#define TIME_CURRENT_MINUTE_REG          0x1009 // (4105) текущая минута
#define TIME_CURRENT_SECOND_REG          0x100A // (4106) текущая секунда
#define TIME_CURRENT_WEEKDAY_REG         0x100B // (4107) текущий день недели
#define ADDRESS_PROCESSED_EVENT_H_REG    0x100C // (4108) адрес начала записи событий
#define ADDRESS_PROCESSED_EVENT_L_REG    0x100D // (4109) адрес начала записи событий
#define ADDRESS_LAST_EVENT_H_REG         0x100E // (4110) адрес последнего записанного события
#define ADDRESS_LAST_EVENT_L_REG         0x100F // (4111) адрес последнего записанного события
#define SYSTEM_STATUS_REG                0x1010 // (4112) наименование последнего события системы (1 - включение питания; 2 - выключение питания; 3 - перезагрузка модема; 4 - перезагрузка контроллера; 5 - защитное время сеанса связи; 6 - включение сигнализации; 7 - отключение сигнализации; 8 - невозможность встать на сигнализацию; 9 - неисправность шлейфов сигнализации; 10 - тревога; 11 - пропала связь GSM;  12 - появилась связь GSM)
#define POWER_ON_REG                     0x1011 // (4113) наличие основного питания
#define ERROR_RTC_REG                    0x1012 // (4114) статус работы кварца на 32кГц
#define POWER_ON_LIGHTING_REG            0x1013 // (4115) наличие основного питания освещения

#define IBUTTON_COMPLETE_0_REG           0x1015 // (4117) нулевой байт идентифицированной таблетки
#define IBUTTON_COMPLETE_1_REG           0x1016 // (4118) первый байт идентифицированной таблетки
#define IBUTTON_COMPLETE_2_REG           0x1017 // (4119) второй байт идентифицированной таблетки
#define IBUTTON_COMPLETE_3_REG           0x1018 // (4120) третий байт идентифицированной таблетки
#define IBUTTON_COMPLETE_4_REG           0x1019 // (4121) четвертый байт идентифицированной таблетки
#define IBUTTON_COMPLETE_5_REG           0x101A // (4122) пятый байт идентифицированной таблетки
#define IBUTTON_COMPLETE_6_REG           0x101B // (4123) шестой байт идентифицированной таблетки
#define IBUTTON_COMPLETE_7_REG           0x101C // (4124) седьмой байт идентифицированной таблетки

#define CE_303_ERROR_REG                 0x101E // (4126) ошибка опроса счётчика 0 - нет ошибок 1 - таймаут 2 - ошибка данный  10 - при смене номера счётчика
#define CE_303_CURRENT_A_REG             0x101F // (4127) ток фазы А
#define CE_303_CURRENT_B_REG             0x1020 // (4128) ток фазы В
#define CE_303_CURRENT_C_REG             0x1021 // (4129) ток фазы С
#define CE_303_CURRENT_MIL_A_REG         0x1022 // (4130) милиамперы фаза А
#define CE_303_CURRENT_MIL_B_REG         0x1023 // (4131) милиамперы фаза В
#define CE_303_CURRENT_MIL_C_REG         0x1024 // (4132) милиамперы фаза С
#define CE_303_VOLT_A_REG                0x1025 // (4133) напряжение фаза А
#define CE_303_VOLT_B_REG                0x1026 // (4134) напряжение фаза В
#define CE_303_VOLT_C_REG                0x1027 // (4135) напряжение фаза С
#define CE_303_VOLT_MIL_A_REG            0x1028 // (4136) миливольты фаза А
#define CE_303_VOLT_MIL_B_REG            0x1029 // (4137) миливольты фаза В
#define CE_303_VOLT_MIL_C_REG            0x102A // (4138) миливольты фаза С
#define CE_303_POWER_A_REG               0x102B // (4139) мощность фаза А
#define CE_303_POWER_B_REG               0x102C // (4140) мощность фаза В
#define CE_303_POWER_C_REG               0x102D // (4141) мощность фаза С
#define CE_303_POWER_MIL_A_REG           0x102E // (4142) мощность миливатт фаза А
#define CE_303_POWER_MIL_B_REG           0x102F // (4143) мощность миливатт фаза В
#define CE_303_POWER_MIL_C_REG           0x1030 // (4144) мощность миливатт фаза С
#define LIGHTING_STATUS_REG              0x1031 // (4145) регистр статуса освещение
#define LIGHTING_ALARM_REG               0x1032 // (4146) регистр аварий освещение
#define MONTH_LIGHTING_OFF_REG           0x1033 // (4147) месяц выключения освещения по расписанию(последний раз)
#define DAY_LIGHTING_OFF_REG             0x1034 // (4148) день выключения освещения по расписанию(последний раз)
#define HOUR_LIGHTING_OFF_REG            0x1035 // (4149) час выключения освещения по расписанию(последний раз)
#define MINUTE_LIGHTING_OFF_REG          0x1036 // (4150) минута выключения освещения по расписанию(последний раз)
#define MONTH_LIGHTING_ON_REG            0x1037 // (4151) месяц включения освещения по расписанию(последний раз)
#define DAY_LIGHTING_ON_REG              0x1038 // (4152) день включения освещения по расписанию(последний раз)
#define HOUR_LIGHTING_ON_REG             0x1039 // (4153) час включения освещения по расписанию(последний раз)
#define MINUTE_LIGHTING_ON_REG           0x103A // (4154) минута включения освещения по расписанию(последний раз)
#define CURRENT_PHASE_A_REG              0x103B // (4155) текущий ток  фаза А *0,1А          // регистры освещения
#define CURRENT_PHASE_B_REG              0x103C // (4156) текущий ток  фаза В *0,1А          // регистры освещения
#define CURRENT_PHASE_C_REG              0x103D // (4157) текущий ток  фаза С *0,1А          // регистры освещения
#define CURRENT_VOLTAGE_A_REG            0x103E // (4158) текущее напряжение А
#define CURRENT_VOLTAGE_B_REG            0x103F // (4159) текущее напряжение В
#define CURRENT_VOLTAGE_C_REG            0x1040 // (4160) текущее напряжение С
#define CE_303_TOTAL_POWER_H_REG         0x1041 // (4161) общее показание счетчика H, старший байт   // регистры сигнализации
#define CE_303_TOTAL_POWER_L_REG         0x1042 // (4162) общее показание счетчика L, младший байт   // регистры сигнализации
#define CE_303_TOTAL_POWER_M_REG         0x1043 // (4163) общее показание счетчика M, миливатт       // регистры сигнализации
#define CE_303_TARIF1_POWER_H_REG        0x1044 // (4164) тариф 1
#define CE_303_TARIF1_POWER_L_REG        0x1045 // (4165) тариф 1
#define CE_303_TARIF1_POWER_MIL_REG      0x1046 // (4166) тариф 1
#define CE_303_TARIF2_POWER_H_REG        0x1047 // (4167) тариф 2
#define CE_303_TARIF2_POWER_L_REG        0x1048 // (4168) тариф 2
#define CE_303_TARIF2_POWER_MIL_REG      0x1049 // (4169) тариф 2
#define CE_303_TARIF3_POWER_H_REG        0x104A // (4170) тариф 3
#define CE_303_TARIF3_POWER_L_REG        0x104B // (4171) тариф 3
#define CE_303_TARIF3_POWER_MIL_REG      0x104C // (4172) тариф 3
#define CE_303_TARIF4_POWER_H_REG        0x104D // (4173) тариф 4
#define CE_303_TARIF4_POWER_L_REG        0x104E // (4174) тариф 4
#define CE_303_TARIF4_POWER_MIL_REG      0x104F // (4175) тариф 4
#define CE_303_TARIF5_POWER_H_REG        0x1050 // (4176) тариф 5
#define CE_303_TARIF5_POWER_L_REG        0x1051 // (4177) тариф 5
#define CE_303_TARIF5_POWER_MIL_REG      0x1052 // (4178) тариф 5
#define SIGNAL_LEVEL_REG                 0x1053 // (4179) уровень сигнала

#define ADVANCED_LOOP_REG                0x1055 // (4181) плата расширения, входы 1..6
#define ADDITIONAL_INPUT_REG1            0x1056 // (4182) Регистр дополнительных входов 1-8
#define ADDITIONAL_INPUT_REG2            0x1057 // (4183) Регистр дополнительных входов 9-14
#define ICCID_NUMBER_REG1                0x1058 // (4184) ICCID номер 1
#define ICCID_NUMBER_REG2                0x1059 // (4185) ICCID номер 2
#define ICCID_NUMBER_REG3                0x105A // (4186) ICCID номер 3
#define ICCID_NUMBER_REG4                0x105B // (4187) ICCID номер 4
#define ICCID_NUMBER_REG5                0x105C // (4188) ICCID номер 5
#define ICCID_NUMBER_REG6                0x105D // (4189) ICCID номер 6
#define ICCID_NUMBER_REG7                0x105E // (4190) ICCID номер 7
#define ICCID_NUMBER_REG8                0x105F // (4191) ICCID номер 8


// -------------------------------------------------------


//---- Описание регистров управления ---------------------

#define SECURITY_CONTROL_REG             0x1090 // (4240) включение охранной функции ( 0 - отключить из центра; 1- включить из центра; 2 -отключить с таблетки; 3 - включить с таблетки )
#define CONTROL_LOOP_REG                 0x1091 // (4241) перечень контролируемых шлейфов ( 1- контролировать; 0 - не контролировать (номер бита соответствует номеру шлейфа) )
#define FILTER_TIME_LOOP_REG             0x1092 // (4242) фильтр ложных срабатываний ( время срабатывания (шаг 0,01 секунды) )
#define QUANTITY_FALSE_LOOP_REG          0x1093 // (4243) количество ложных срабатываений ( количество срабатываний с временем меньше фильтра до подачи сигнала неисправность шлейфа )
#define TIME_FALSE_LOOP_REG              0x1094 // (4244) время обнуления ложных срабатываний ( время в минутах )
#define ALARM_LOOP_CLEAR_REG             0x1095 // (4245) сбросить сработавшие шлейфы ( 1 - сброс, возвращается в 0 автоматически )
#define FALSE_LOOP_CLEAR_REG             0x1096 // (4246) сброс неисправностей шлейфов
#define SECURITY_TIME_MAX_REG            0x1097 // (4247) время постановки на охрану в секундах
#define TIME_UPDATE_REG                  0x1098	// (4248) переменная установки нового времени, сбрасывается автоматически
#define TIME_YEAR_REG                    0x1099 // (4249) переменная года который необходимо установить
#define TIME_MONTH_REG                   0x109A // (4250) переменная месяца который необходимо установить
#define TIME_DAY_REG                     0x109B // (4251) переменная дня который необходимо установить
#define TIME_HOUR_REG                    0x109C // (4252) переменная часа который необходимо установить
#define TIME_MINUTE_REG                  0x109D // (4253) переменная минуты которую необходимо установить
#define TIME_SECONDS_REG                 0x109E // (4254) переменная секунд которую надо установить
#define TIME_WEEKDAY_REG                 0x109F // (4255) переменная дня недели который необходимо установить
#define MODBUS_IDLE_TIME_MAX_REG         0x10A0 // (4256) максимальное время сеанса связибез передачи данных в минутах
#define TIME_CONNECTION_TEST_REG         0x10A1 // (4257) время между тестовыми звонками на свой номер
#define EVENT_READ_REG                   0x10A2 // (4258) инициализирует чтение из памяти
#define EVENT_ADDRESS_HIGH_REG           0x10A3 // (4259) старший байт адреса чтения памяти
#define EVENT_ADDRESS_LOW_REG            0x10A4 // (4260) младший байт адреса чтения памяти
#define MODEM_RING_TRY_LOAD_REG          0x10A5 // (4261) количество попыток дозвона в центр до паузы
#define MODEM_RING_PAUSE_LOAD_REG        0x10A6 // (4262) время паузы после неудачных попыток дозвона в минутах
#define MODEM_RING_PAUSE2_LOAD_REG       0x10A7 // (4263) время между звонками в центр в секундах
#define RING_MINUTE_TIME_REG             0x10A8 // (4264) время с последнего звонка до перезагрузки модема в минутах
#define RING_HOUR_TIME_REG               0x10A9 // (4265) время с последнего звонка до перезагрузки модема в часах

#define ID_HIGH_REG                      0x10AB // (4267) ID устройства, старший байт
#define ID_LOW_REG                       0x10AC // (4268) ID устройства, младший байт
#define RESET_CONTROL_REG                0x10AD // (4269) регистр управления перезагрузкой
#define METER_POLLING_REG                0x10AE // (4270) включение опроса счётчика ( 1 - счётчик опрашивается 0 - нет )
#define IP_1_REG                         0x10AF // (4271) IP сервера
#define IP_2_REG                         0x10B0 // (4272) IP сервера
#define IP_3_REG                         0x10B1 // (4273) IP сервера
#define IP_4_REG                         0x10B2 // (4274) IP сервера
#define PORT_HIGH_REG                    0x10B3 // (4275) номер порта сервера, старший байт
#define PORT_LOW_REG                     0x10B4 // (4276) номер порта сервера, младший байт
#define METER_ID_HIGH_REG                0x10B5 // (4277) номер прибора учета, старший байт
#define METER_ID_LOW_REG                 0x10B6 // (4278) номер прибора учета, младший байт
#define GPRS_CALL_REG                    0x10B7 // (4279) флаг что устройство по GPRS звонит в центр ( 1 - звонит, сбросить в 0 )

#define MUTE_REG                         0x10B9 // (4281) регистр управления отключением звука при тревоге открытия двери (1 - звук отключен, 0 - звук включен)

#define LIGHT_CONTROL_REG                0x10C1 // (4289) регистр управления освещением (бит 0 - управление фазой А, бит 1 - управление фазой В, бит 2 - управление фазой С, бит 3- управление от каскада, бит 4 - контроль второй линии, бит 5 - работать по расписанию)
#define LIGHTING_ALARM_RESET_REG         0x10C2 // (4290) регистр сброса аварий освещения (запись 1 для сброса аварий освещения)
#define CURRENT_MEASUREMENT_ACCURACY_REG 0x10C3 // (4291) точность отслеживания тока (амперы, изменение тока приводит к сообщению в центр)
#define MAX_CURRENT_PHASE_A              0x10C4 // (4292) максимальный ток фаза А
#define MAX_CURRENT_PHASE_B              0x10C5 // (4293) максимальный ток фаза В
#define MAX_CURRENT_PHASE_C              0x10C6 // (4294) максммальный ток фаза С
#define LIGHTING_SWITCHING_REG           0x10C7 // (4295) включение функции освещения (1 - функция освещения включена, 0 - функция освещения выключена)
#define ALARM_SWITCHING_REG              0x10C8 // (4296) включение охранной функции (1 - функция охраны включена, 0 - функция охраны выключена)
#define ARMING_TIMELEFT                  0x10C9 // (4297) время постановки на охрану


//--------------------------------------------------------


//----Описание регистров бутлоадера-----------------------

#define BOOTLOADER_VERSION_REG           0x100

#define START_ADDRESS_FIRMWARE_HIGH_REG  0x102
#define START_ADDRESS_FIRMWARE_2_REG     0x103
#define START_ADDRESS_FIRMWARE_3_REG     0x104
#define START_ADDRESS_FIRMWARE_LOW_REG   0x105
#define END_ADDRESS_FIRMWARE_HIGH_REG    0x106
#define END_ADDRESS_FIRMWARE_LOW_REG     0x107
#define CRC_FIRMWARE_HIGH_REG            0x108
#define CRC_FIRMWARE_LOW_REG             0x109
#define JUMP_VECTOR_HIGH_REG             0x10A
#define JUMP_VECTOR_2_REG                0x10B
#define JUMP_VECTOR_3_REG                0x10C
#define JUMP_VECTOR_LOW_REG              0x10D
#define FIRMWARE_CORRECTNESS_REG         0x10E
#define WORKING_MODE_REG                 0x10F
#define READY_DOWNLOAD_REG               0x110
#define DOWNLOAD_TIMEOUT_REG             0x111
#define JUMP_ATTEMPT_REG                 0x112
#define MAX_JUMP_ATTEMPT_REG             0x113
#define END_ADDRESS_FIRMWARE_2_REG       0x114
#define END_ADDRESS_FIRMWARE_3_REG       0x115
#define ADDRESS_TO_WRITE_2_REG           0x116
#define ADDRESS_TO_WRITE_3_REG           0x117

#define CLEAR_PAGE_NUMBER_REG            0x11F
#define CLEAR_PAGE_ON_REG                0x120
#define WRITE_ARRAY_REG                  0x121
#define READ_ARRAY_REG                   0x122
#define ADDRESS_TO_WRITE_HIGH_REG        0x123
#define ADDRESS_TO_WRITE_LOW_REG         0x124
#define BYTE_QUANTITY_REG                0x125
#define PACKET_CRC_HIGH_REG              0x126
#define PACKET_CRC_LOW_REG               0x127
#define PACKET_DATA_0_REG                0x128
#define PACKET_DATA_1_REG                0x129
#define PACKET_DATA_2_REG                0x12A
#define PACKET_DATA_3_REG                0x12B
#define PACKET_DATA_4_REG                0x12C


//--------------------------------------------------------

//----Описание регистров учетных записей I-button -----------------------

#define IBUTTON1_BYTE_0_REG     0x1310 // А1 номер ключа 1
#define IBUTTON1_BYTE_1_REG     0x1311 // А2
#define IBUTTON1_BYTE_2_REG     0x1312 // А3
#define IBUTTON1_BYTE_3_REG     0x1313 // А4
#define IBUTTON1_BYTE_4_REG     0x1314 // А5
#define IBUTTON1_BYTE_5_REG     0x1315 // А6
#define IBUTTON1_BYTE_6_REG     0x1316 // А7
#define IBUTTON1_BYTE_7_REG     0x1317 // А8

#define IBUTTON2_BYTE_0_REG     0x1320 // А9 номер ключа 2
#define IBUTTON2_BYTE_1_REG     0x1321 // А10
#define IBUTTON2_BYTE_2_REG     0x1322 // А11
#define IBUTTON2_BYTE_3_REG     0x1323 // А12
#define IBUTTON2_BYTE_4_REG     0x1324 // А13
#define IBUTTON2_BYTE_5_REG     0x1325 // А14
#define IBUTTON2_BYTE_6_REG     0x1326 // А15
#define IBUTTON2_BYTE_7_REG     0x1327 // А16

#define IBUTTON3_BYTE_0_REG     0x1330 // А17 номер ключа 3
#define IBUTTON3_BYTE_1_REG     0x1331 // А18
#define IBUTTON3_BYTE_2_REG     0x1332 // А19
#define IBUTTON3_BYTE_3_REG     0x1333 // А20
#define IBUTTON3_BYTE_4_REG     0x1334 // А21
#define IBUTTON3_BYTE_5_REG     0x1335 // А22
#define IBUTTON3_BYTE_6_REG     0x1336 // А23
#define IBUTTON3_BYTE_7_REG     0x1337 // А24

#define IBUTTON4_BYTE_0_REG     0x1340 // А25 номер ключа 4
#define IBUTTON4_BYTE_1_REG     0x1341 // А26
#define IBUTTON4_BYTE_2_REG     0x1342 // А27
#define IBUTTON4_BYTE_3_REG     0x1343 // А28
#define IBUTTON4_BYTE_4_REG     0x1344 // А29
#define IBUTTON4_BYTE_5_REG     0x1345 // А30
#define IBUTTON4_BYTE_6_REG     0x1346 // А31
#define IBUTTON4_BYTE_7_REG     0x1347 // А32

#define IBUTTON5_BYTE_0_REG     0x1350 // А33 номер ключа 5
#define IBUTTON5_BYTE_1_REG     0x1351 // А34
#define IBUTTON5_BYTE_2_REG     0x1352 // А35
#define IBUTTON5_BYTE_3_REG     0x1353 // А36
#define IBUTTON5_BYTE_4_REG     0x1354 // А37
#define IBUTTON5_BYTE_5_REG     0x1355 // А38
#define IBUTTON5_BYTE_6_REG     0x1356 // А39
#define IBUTTON5_BYTE_7_REG     0x1357 // А40

#define IBUTTON6_BYTE_0_REG     0x1360 // А41 номер ключа 6
#define IBUTTON6_BYTE_1_REG     0x1361 // А42
#define IBUTTON6_BYTE_2_REG     0x1362 // А43
#define IBUTTON6_BYTE_3_REG     0x1363 // А44
#define IBUTTON6_BYTE_4_REG     0x1364 // А45
#define IBUTTON6_BYTE_5_REG     0x1365 // А46
#define IBUTTON6_BYTE_6_REG     0x1366 // А47
#define IBUTTON6_BYTE_7_REG     0x1367 // А48

#define IBUTTON7_BYTE_0_REG     0x1370 // А49 номер ключа 7
#define IBUTTON7_BYTE_1_REG     0x1371 // А50
#define IBUTTON7_BYTE_2_REG     0x1372 // А51
#define IBUTTON7_BYTE_3_REG     0x1373 // А52
#define IBUTTON7_BYTE_4_REG     0x1374 // А53
#define IBUTTON7_BYTE_5_REG     0x1375 // А54
#define IBUTTON7_BYTE_6_REG     0x1376 // А55
#define IBUTTON7_BYTE_7_REG     0x1377 // А56

#define IBUTTON8_BYTE_0_REG     0x1380 // А57 номер ключа 8
#define IBUTTON8_BYTE_1_REG     0x1381 // А58
#define IBUTTON8_BYTE_2_REG     0x1382 // А59
#define IBUTTON8_BYTE_3_REG     0x1383 // А60
#define IBUTTON8_BYTE_4_REG     0x1384 // А61
#define IBUTTON8_BYTE_5_REG     0x1385 // А62
#define IBUTTON8_BYTE_6_REG     0x1386 // А63
#define IBUTTON8_BYTE_7_REG     0x1387 // А64

#define IBUTTON9_BYTE_0_REG     0x1390 // номер ключа 9
#define IBUTTON9_BYTE_1_REG     0x1391
#define IBUTTON9_BYTE_2_REG     0x1392
#define IBUTTON9_BYTE_3_REG     0x1393
#define IBUTTON9_BYTE_4_REG     0x1394
#define IBUTTON9_BYTE_5_REG     0x1395
#define IBUTTON9_BYTE_6_REG     0x1396
#define IBUTTON9_BYTE_7_REG     0x1397

#define IBUTTON10_BYTE_0_REG     0x13A0 // номер ключа 10
#define IBUTTON10_BYTE_1_REG     0x13A1
#define IBUTTON10_BYTE_2_REG     0x13A2
#define IBUTTON10_BYTE_3_REG     0x13A3
#define IBUTTON10_BYTE_4_REG     0x13A4
#define IBUTTON10_BYTE_5_REG     0x13A5
#define IBUTTON10_BYTE_6_REG     0x13A6
#define IBUTTON10_BYTE_7_REG     0x13A7

#define IBUTTON11_BYTE_0_REG     0x13B0 // номер ключа 11
#define IBUTTON11_BYTE_1_REG     0x13B1
#define IBUTTON11_BYTE_2_REG     0x13B2
#define IBUTTON11_BYTE_3_REG     0x13B3
#define IBUTTON11_BYTE_4_REG     0x13B4
#define IBUTTON11_BYTE_5_REG     0x13B5
#define IBUTTON11_BYTE_6_REG     0x13B6
#define IBUTTON11_BYTE_7_REG     0x13B7

#define IBUTTON12_BYTE_0_REG     0x13C0 // номер ключа 12
#define IBUTTON12_BYTE_1_REG     0x13C1
#define IBUTTON12_BYTE_2_REG     0x13C2
#define IBUTTON12_BYTE_3_REG     0x13C3
#define IBUTTON12_BYTE_4_REG     0x13C4
#define IBUTTON12_BYTE_5_REG     0x13C5
#define IBUTTON12_BYTE_6_REG     0x13C6
#define IBUTTON12_BYTE_7_REG     0x13C7

#define IBUTTON13_BYTE_0_REG     0x13D0 // номер ключа 13
#define IBUTTON13_BYTE_1_REG     0x13D1
#define IBUTTON13_BYTE_2_REG     0x13D2
#define IBUTTON13_BYTE_3_REG     0x13D3
#define IBUTTON13_BYTE_4_REG     0x13D4
#define IBUTTON13_BYTE_5_REG     0x13D5
#define IBUTTON13_BYTE_6_REG     0x13D6
#define IBUTTON13_BYTE_7_REG     0x13D7

#define IBUTTON14_BYTE_0_REG     0x13E0 // номер ключа 14
#define IBUTTON14_BYTE_1_REG     0x13E1
#define IBUTTON14_BYTE_2_REG     0x13E2
#define IBUTTON14_BYTE_3_REG     0x13E3
#define IBUTTON14_BYTE_4_REG     0x13E4
#define IBUTTON14_BYTE_5_REG     0x13E5
#define IBUTTON14_BYTE_6_REG     0x13E6
#define IBUTTON14_BYTE_7_REG     0x13E7

#define IBUTTON15_BYTE_0_REG     0x13F0 // номер ключа 15
#define IBUTTON15_BYTE_1_REG     0x13F1
#define IBUTTON15_BYTE_2_REG     0x13F2
#define IBUTTON15_BYTE_3_REG     0x13F3
#define IBUTTON15_BYTE_4_REG     0x13F4
#define IBUTTON15_BYTE_5_REG     0x13F5
#define IBUTTON15_BYTE_6_REG     0x13F6
#define IBUTTON15_BYTE_7_REG     0x13F7

#define IBUTTON16_BYTE_0_REG     0x1400 // номер ключа 16
#define IBUTTON16_BYTE_1_REG     0x1401
#define IBUTTON16_BYTE_2_REG     0x1402
#define IBUTTON16_BYTE_3_REG     0x1403
#define IBUTTON16_BYTE_4_REG     0x1404
#define IBUTTON16_BYTE_5_REG     0x1405
#define IBUTTON16_BYTE_6_REG     0x1406
#define IBUTTON16_BYTE_7_REG     0x1407

#define IBUTTON17_BYTE_0_REG     0x1410 // номер ключа 17
#define IBUTTON17_BYTE_1_REG     0x1411
#define IBUTTON17_BYTE_2_REG     0x1412
#define IBUTTON17_BYTE_3_REG     0x1413
#define IBUTTON17_BYTE_4_REG     0x1414
#define IBUTTON17_BYTE_5_REG     0x1415
#define IBUTTON17_BYTE_6_REG     0x1416
#define IBUTTON17_BYTE_7_REG     0x1417

#define IBUTTON18_BYTE_0_REG     0x1420 // номер ключа 18
#define IBUTTON18_BYTE_1_REG     0x1421
#define IBUTTON18_BYTE_2_REG     0x1422
#define IBUTTON18_BYTE_3_REG     0x1423
#define IBUTTON18_BYTE_4_REG     0x1424
#define IBUTTON18_BYTE_5_REG     0x1425
#define IBUTTON18_BYTE_6_REG     0x1426
#define IBUTTON18_BYTE_7_REG     0x1427

#define IBUTTON19_BYTE_0_REG     0x1430 // номер ключа 19
#define IBUTTON19_BYTE_1_REG     0x1431
#define IBUTTON19_BYTE_2_REG     0x1432
#define IBUTTON19_BYTE_3_REG     0x1433
#define IBUTTON19_BYTE_4_REG     0x1434
#define IBUTTON19_BYTE_5_REG     0x1435
#define IBUTTON19_BYTE_6_REG     0x1436
#define IBUTTON19_BYTE_7_REG     0x1437

#define IBUTTON20_BYTE_0_REG     0x1440 // номер ключа 20
#define IBUTTON20_BYTE_1_REG     0x1441
#define IBUTTON20_BYTE_2_REG     0x1442
#define IBUTTON20_BYTE_3_REG     0x1443
#define IBUTTON20_BYTE_4_REG     0x1444
#define IBUTTON20_BYTE_5_REG     0x1445
#define IBUTTON20_BYTE_6_REG     0x1446
#define IBUTTON20_BYTE_7_REG     0x1447

#define IBUTTON21_BYTE_0_REG     0x1450 // номер ключа 21
#define IBUTTON21_BYTE_1_REG     0x1451
#define IBUTTON21_BYTE_2_REG     0x1452
#define IBUTTON21_BYTE_3_REG     0x1453
#define IBUTTON21_BYTE_4_REG     0x1454
#define IBUTTON21_BYTE_5_REG     0x1455
#define IBUTTON21_BYTE_6_REG     0x1456
#define IBUTTON21_BYTE_7_REG     0x1457

#define IBUTTON22_BYTE_0_REG     0x1460 // номер ключа 22
#define IBUTTON22_BYTE_1_REG     0x1461
#define IBUTTON22_BYTE_2_REG     0x1462
#define IBUTTON22_BYTE_3_REG     0x1463
#define IBUTTON22_BYTE_4_REG     0x1464
#define IBUTTON22_BYTE_5_REG     0x1465
#define IBUTTON22_BYTE_6_REG     0x1466
#define IBUTTON22_BYTE_7_REG     0x1467

#define IBUTTON23_BYTE_0_REG     0x1470 // номер ключа 23
#define IBUTTON23_BYTE_1_REG     0x1471
#define IBUTTON23_BYTE_2_REG     0x1472
#define IBUTTON23_BYTE_3_REG     0x1473
#define IBUTTON23_BYTE_4_REG     0x1474
#define IBUTTON23_BYTE_5_REG     0x1475
#define IBUTTON23_BYTE_6_REG     0x1476
#define IBUTTON23_BYTE_7_REG     0x1477

#define IBUTTON24_BYTE_0_REG     0x1480 // номер ключа 24
#define IBUTTON24_BYTE_1_REG     0x1481
#define IBUTTON24_BYTE_2_REG     0x1482
#define IBUTTON24_BYTE_3_REG     0x1483
#define IBUTTON24_BYTE_4_REG     0x1484
#define IBUTTON24_BYTE_5_REG     0x1485
#define IBUTTON24_BYTE_6_REG     0x1486
#define IBUTTON24_BYTE_7_REG     0x1487

#define IBUTTON25_BYTE_0_REG     0x1490 // номер ключа 25
#define IBUTTON25_BYTE_1_REG     0x1491
#define IBUTTON25_BYTE_2_REG     0x1492
#define IBUTTON25_BYTE_3_REG     0x1493
#define IBUTTON25_BYTE_4_REG     0x1494
#define IBUTTON25_BYTE_5_REG     0x1495
#define IBUTTON25_BYTE_6_REG     0x1496
#define IBUTTON25_BYTE_7_REG     0x1497

#define IBUTTON26_BYTE_0_REG     0x14A0 // номер ключа 26
#define IBUTTON26_BYTE_1_REG     0x14A1
#define IBUTTON26_BYTE_2_REG     0x14A2
#define IBUTTON26_BYTE_3_REG     0x14A3
#define IBUTTON26_BYTE_4_REG     0x14A4
#define IBUTTON26_BYTE_5_REG     0x14A5
#define IBUTTON26_BYTE_6_REG     0x14A6
#define IBUTTON26_BYTE_7_REG     0x14A7

#define IBUTTON27_BYTE_0_REG     0x14B0 // номер ключа 27
#define IBUTTON27_BYTE_1_REG     0x14B1
#define IBUTTON27_BYTE_2_REG     0x14B2
#define IBUTTON27_BYTE_3_REG     0x14B3
#define IBUTTON27_BYTE_4_REG     0x14B4
#define IBUTTON27_BYTE_5_REG     0x14B5
#define IBUTTON27_BYTE_6_REG     0x14B6
#define IBUTTON27_BYTE_7_REG     0x14B7

#define IBUTTON28_BYTE_0_REG     0x14C0 // номер ключа 28
#define IBUTTON28_BYTE_1_REG     0x14C1
#define IBUTTON28_BYTE_2_REG     0x14C2
#define IBUTTON28_BYTE_3_REG     0x14C3
#define IBUTTON28_BYTE_4_REG     0x14C4
#define IBUTTON28_BYTE_5_REG     0x14C5
#define IBUTTON28_BYTE_6_REG     0x14C6
#define IBUTTON28_BYTE_7_REG     0x14C7

#define IBUTTON29_BYTE_0_REG     0x14D0 // номер ключа 29
#define IBUTTON29_BYTE_1_REG     0x14D1
#define IBUTTON29_BYTE_2_REG     0x14D2
#define IBUTTON29_BYTE_3_REG     0x14D3
#define IBUTTON29_BYTE_4_REG     0x14D4
#define IBUTTON29_BYTE_5_REG     0x14D5
#define IBUTTON29_BYTE_6_REG     0x14D6
#define IBUTTON29_BYTE_7_REG     0x14D7

#define IBUTTON30_BYTE_0_REG     0x14E0 // номер ключа 30
#define IBUTTON30_BYTE_1_REG     0x14E1
#define IBUTTON30_BYTE_2_REG     0x14E2
#define IBUTTON30_BYTE_3_REG     0x14E3
#define IBUTTON30_BYTE_4_REG     0x14E4
#define IBUTTON30_BYTE_5_REG     0x14E5
#define IBUTTON30_BYTE_6_REG     0x14E6
#define IBUTTON30_BYTE_7_REG     0x14E7

#define IBUTTON31_BYTE_0_REG     0x14F0 // номер ключа 31
#define IBUTTON31_BYTE_1_REG     0x14F1
#define IBUTTON31_BYTE_2_REG     0x14F2
#define IBUTTON31_BYTE_3_REG     0x14F3
#define IBUTTON31_BYTE_4_REG     0x14F4
#define IBUTTON31_BYTE_5_REG     0x14F5
#define IBUTTON31_BYTE_6_REG     0x14F6
#define IBUTTON31_BYTE_7_REG     0x14F7

#define IBUTTON32_BYTE_0_REG     0x1500 // номер ключа 32
#define IBUTTON32_BYTE_1_REG     0x1501
#define IBUTTON32_BYTE_2_REG     0x1502
#define IBUTTON32_BYTE_3_REG     0x1503
#define IBUTTON32_BYTE_4_REG     0x1504
#define IBUTTON32_BYTE_5_REG     0x1505
#define IBUTTON32_BYTE_6_REG     0x1506
#define IBUTTON32_BYTE_7_REG     0x1507

#define IBUTTON33_BYTE_0_REG     0x1510 // номер ключа 33
#define IBUTTON33_BYTE_1_REG     0x1511
#define IBUTTON33_BYTE_2_REG     0x1512
#define IBUTTON33_BYTE_3_REG     0x1513
#define IBUTTON33_BYTE_4_REG     0x1514
#define IBUTTON33_BYTE_5_REG     0x1515
#define IBUTTON33_BYTE_6_REG     0x1516
#define IBUTTON33_BYTE_7_REG     0x1517

#define IBUTTON34_BYTE_0_REG     0x1520 // номер ключа 34
#define IBUTTON34_BYTE_1_REG     0x1521
#define IBUTTON34_BYTE_2_REG     0x1522
#define IBUTTON34_BYTE_3_REG     0x1523
#define IBUTTON34_BYTE_4_REG     0x1524
#define IBUTTON34_BYTE_5_REG     0x1525
#define IBUTTON34_BYTE_6_REG     0x1526
#define IBUTTON34_BYTE_7_REG     0x1527

#define IBUTTON35_BYTE_0_REG     0x1530 // номер ключа 35
#define IBUTTON35_BYTE_1_REG     0x1531
#define IBUTTON35_BYTE_2_REG     0x1532
#define IBUTTON35_BYTE_3_REG     0x1533
#define IBUTTON35_BYTE_4_REG     0x1534
#define IBUTTON35_BYTE_5_REG     0x1535
#define IBUTTON35_BYTE_6_REG     0x1536
#define IBUTTON35_BYTE_7_REG     0x1537

#define IBUTTON36_BYTE_0_REG     0x1540 // номер ключа 36
#define IBUTTON36_BYTE_1_REG     0x1541
#define IBUTTON36_BYTE_2_REG     0x1542
#define IBUTTON36_BYTE_3_REG     0x1543
#define IBUTTON36_BYTE_4_REG     0x1544
#define IBUTTON36_BYTE_5_REG     0x1545
#define IBUTTON36_BYTE_6_REG     0x1546
#define IBUTTON36_BYTE_7_REG     0x1547

#define IBUTTON37_BYTE_0_REG     0x1550 // номер ключа 37
#define IBUTTON37_BYTE_1_REG     0x1551
#define IBUTTON37_BYTE_2_REG     0x1552
#define IBUTTON37_BYTE_3_REG     0x1553
#define IBUTTON37_BYTE_4_REG     0x1554
#define IBUTTON37_BYTE_5_REG     0x1555
#define IBUTTON37_BYTE_6_REG     0x1556
#define IBUTTON37_BYTE_7_REG     0x1557

#define IBUTTON38_BYTE_0_REG     0x1560 // номер ключа 38
#define IBUTTON38_BYTE_1_REG     0x1561
#define IBUTTON38_BYTE_2_REG     0x1562
#define IBUTTON38_BYTE_3_REG     0x1563
#define IBUTTON38_BYTE_4_REG     0x1564
#define IBUTTON38_BYTE_5_REG     0x1565
#define IBUTTON38_BYTE_6_REG     0x1566
#define IBUTTON38_BYTE_7_REG     0x1567

#define IBUTTON39_BYTE_0_REG     0x1570 // номер ключа 39
#define IBUTTON39_BYTE_1_REG     0x1571
#define IBUTTON39_BYTE_2_REG     0x1572
#define IBUTTON39_BYTE_3_REG     0x1573
#define IBUTTON39_BYTE_4_REG     0x1574
#define IBUTTON39_BYTE_5_REG     0x1575
#define IBUTTON39_BYTE_6_REG     0x1576
#define IBUTTON39_BYTE_7_REG     0x1577

#define IBUTTON40_BYTE_0_REG     0x1580 // номер ключа 40
#define IBUTTON40_BYTE_1_REG     0x1581
#define IBUTTON40_BYTE_2_REG     0x1582
#define IBUTTON40_BYTE_3_REG     0x1583
#define IBUTTON40_BYTE_4_REG     0x1584
#define IBUTTON40_BYTE_5_REG     0x1585
#define IBUTTON40_BYTE_6_REG     0x1586
#define IBUTTON40_BYTE_7_REG     0x1587

#define IBUTTON41_BYTE_0_REG     0x1590 // номер ключа 41
#define IBUTTON41_BYTE_1_REG     0x1591
#define IBUTTON41_BYTE_2_REG     0x1592
#define IBUTTON41_BYTE_3_REG     0x1593
#define IBUTTON41_BYTE_4_REG     0x1594
#define IBUTTON41_BYTE_5_REG     0x1595
#define IBUTTON41_BYTE_6_REG     0x1596
#define IBUTTON41_BYTE_7_REG     0x1597

#define IBUTTON42_BYTE_0_REG     0x15A0 // номер ключа 42
#define IBUTTON42_BYTE_1_REG     0x15A1
#define IBUTTON42_BYTE_2_REG     0x15A2
#define IBUTTON42_BYTE_3_REG     0x15A3
#define IBUTTON42_BYTE_4_REG     0x15A4
#define IBUTTON42_BYTE_5_REG     0x15A5
#define IBUTTON42_BYTE_6_REG     0x15A6
#define IBUTTON42_BYTE_7_REG     0x15A7

#define IBUTTON43_BYTE_0_REG     0x15B0 // номер ключа 43
#define IBUTTON43_BYTE_1_REG     0x15B1
#define IBUTTON43_BYTE_2_REG     0x15B2
#define IBUTTON43_BYTE_3_REG     0x15B3
#define IBUTTON43_BYTE_4_REG     0x15B4
#define IBUTTON43_BYTE_5_REG     0x15B5
#define IBUTTON43_BYTE_6_REG     0x15B6
#define IBUTTON43_BYTE_7_REG     0x15B7

#define IBUTTON44_BYTE_0_REG     0x15C0 // номер ключа 44
#define IBUTTON44_BYTE_1_REG     0x15C1
#define IBUTTON44_BYTE_2_REG     0x15C2
#define IBUTTON44_BYTE_3_REG     0x15C3
#define IBUTTON44_BYTE_4_REG     0x15C4
#define IBUTTON44_BYTE_5_REG     0x15C5
#define IBUTTON44_BYTE_6_REG     0x15C6
#define IBUTTON44_BYTE_7_REG     0x15C7

#define IBUTTON45_BYTE_0_REG     0x15D0 // номер ключа 45
#define IBUTTON45_BYTE_1_REG     0x15D1
#define IBUTTON45_BYTE_2_REG     0x15D2
#define IBUTTON45_BYTE_3_REG     0x15D3
#define IBUTTON45_BYTE_4_REG     0x15D4
#define IBUTTON45_BYTE_5_REG     0x15D5
#define IBUTTON45_BYTE_6_REG     0x15D6
#define IBUTTON45_BYTE_7_REG     0x15D7

#define IBUTTON46_BYTE_0_REG     0x15E0 // номер ключа 46
#define IBUTTON46_BYTE_1_REG     0x15E1
#define IBUTTON46_BYTE_2_REG     0x15E2
#define IBUTTON46_BYTE_3_REG     0x15E3
#define IBUTTON46_BYTE_4_REG     0x15E4
#define IBUTTON46_BYTE_5_REG     0x15E5
#define IBUTTON46_BYTE_6_REG     0x15E6
#define IBUTTON46_BYTE_7_REG     0x15E7

#define IBUTTON47_BYTE_0_REG     0x15F0 // номер ключа 47
#define IBUTTON47_BYTE_1_REG     0x15F1
#define IBUTTON47_BYTE_2_REG     0x15F2
#define IBUTTON47_BYTE_3_REG     0x15F3
#define IBUTTON47_BYTE_4_REG     0x15F4
#define IBUTTON47_BYTE_5_REG     0x15F5
#define IBUTTON47_BYTE_6_REG     0x15F6
#define IBUTTON47_BYTE_7_REG     0x15F7

#define IBUTTON48_BYTE_0_REG     0x1600 // номер ключа 48
#define IBUTTON48_BYTE_1_REG     0x1601
#define IBUTTON48_BYTE_2_REG     0x1602
#define IBUTTON48_BYTE_3_REG     0x1603
#define IBUTTON48_BYTE_4_REG     0x1604
#define IBUTTON48_BYTE_5_REG     0x1605
#define IBUTTON48_BYTE_6_REG     0x1606
#define IBUTTON48_BYTE_7_REG     0x1607

#define IBUTTON49_BYTE_0_REG     0x1610 // номер ключа 49
#define IBUTTON49_BYTE_1_REG     0x1611
#define IBUTTON49_BYTE_2_REG     0x1612
#define IBUTTON49_BYTE_3_REG     0x1613
#define IBUTTON49_BYTE_4_REG     0x1614
#define IBUTTON49_BYTE_5_REG     0x1615
#define IBUTTON49_BYTE_6_REG     0x1616
#define IBUTTON49_BYTE_7_REG     0x1617

#define IBUTTON50_BYTE_0_REG     0x1620 // номер ключа 50
#define IBUTTON50_BYTE_1_REG     0x1621
#define IBUTTON50_BYTE_2_REG     0x1622
#define IBUTTON50_BYTE_3_REG     0x1623
#define IBUTTON50_BYTE_4_REG     0x1624
#define IBUTTON50_BYTE_5_REG     0x1625
#define IBUTTON50_BYTE_6_REG     0x1626
#define IBUTTON50_BYTE_7_REG     0x1627

#define IBUTTON51_BYTE_0_REG     0x1630 // номер ключа 51
#define IBUTTON51_BYTE_1_REG     0x1631
#define IBUTTON51_BYTE_2_REG     0x1632
#define IBUTTON51_BYTE_3_REG     0x1633
#define IBUTTON51_BYTE_4_REG     0x1634
#define IBUTTON51_BYTE_5_REG     0x1635
#define IBUTTON51_BYTE_6_REG     0x1636
#define IBUTTON51_BYTE_7_REG     0x1637

#define IBUTTON52_BYTE_0_REG     0x1640 // номер ключа 52
#define IBUTTON52_BYTE_1_REG     0x1641
#define IBUTTON52_BYTE_2_REG     0x1642
#define IBUTTON52_BYTE_3_REG     0x1643
#define IBUTTON52_BYTE_4_REG     0x1644
#define IBUTTON52_BYTE_5_REG     0x1645
#define IBUTTON52_BYTE_6_REG     0x1646
#define IBUTTON52_BYTE_7_REG     0x1647

#define IBUTTON53_BYTE_0_REG     0x1650 // номер ключа 53
#define IBUTTON53_BYTE_1_REG     0x1651
#define IBUTTON53_BYTE_2_REG     0x1652
#define IBUTTON53_BYTE_3_REG     0x1653
#define IBUTTON53_BYTE_4_REG     0x1654
#define IBUTTON53_BYTE_5_REG     0x1655
#define IBUTTON53_BYTE_6_REG     0x1656
#define IBUTTON53_BYTE_7_REG     0x1657

#define IBUTTON54_BYTE_0_REG     0x1660 // номер ключа 54
#define IBUTTON54_BYTE_1_REG     0x1661
#define IBUTTON54_BYTE_2_REG     0x1662
#define IBUTTON54_BYTE_3_REG     0x1663
#define IBUTTON54_BYTE_4_REG     0x1664
#define IBUTTON54_BYTE_5_REG     0x1665
#define IBUTTON54_BYTE_6_REG     0x1666
#define IBUTTON54_BYTE_7_REG     0x1667

#define IBUTTON55_BYTE_0_REG     0x1670 // номер ключа 55
#define IBUTTON55_BYTE_1_REG     0x1671
#define IBUTTON55_BYTE_2_REG     0x1672
#define IBUTTON55_BYTE_3_REG     0x1673
#define IBUTTON55_BYTE_4_REG     0x1674
#define IBUTTON55_BYTE_5_REG     0x1675
#define IBUTTON55_BYTE_6_REG     0x1676
#define IBUTTON55_BYTE_7_REG     0x1677

#define IBUTTON56_BYTE_0_REG     0x1680 // номер ключа 56
#define IBUTTON56_BYTE_1_REG     0x1681
#define IBUTTON56_BYTE_2_REG     0x1682
#define IBUTTON56_BYTE_3_REG     0x1683
#define IBUTTON56_BYTE_4_REG     0x1684
#define IBUTTON56_BYTE_5_REG     0x1685
#define IBUTTON56_BYTE_6_REG     0x1686
#define IBUTTON56_BYTE_7_REG     0x1687

#define IBUTTON57_BYTE_0_REG     0x1690 // номер ключа 57
#define IBUTTON57_BYTE_1_REG     0x1691
#define IBUTTON57_BYTE_2_REG     0x1692
#define IBUTTON57_BYTE_3_REG     0x1693
#define IBUTTON57_BYTE_4_REG     0x1694
#define IBUTTON57_BYTE_5_REG     0x1695
#define IBUTTON57_BYTE_6_REG     0x1696
#define IBUTTON57_BYTE_7_REG     0x1697

#define IBUTTON58_BYTE_0_REG     0x16A0 // номер ключа 58
#define IBUTTON58_BYTE_1_REG     0x16A1
#define IBUTTON58_BYTE_2_REG     0x16A2
#define IBUTTON58_BYTE_3_REG     0x16A3
#define IBUTTON58_BYTE_4_REG     0x16A4
#define IBUTTON58_BYTE_5_REG     0x16A5
#define IBUTTON58_BYTE_6_REG     0x16A6
#define IBUTTON58_BYTE_7_REG     0x16A7

#define IBUTTON59_BYTE_0_REG     0x16B0 // номер ключа 59
#define IBUTTON59_BYTE_1_REG     0x16B1
#define IBUTTON59_BYTE_2_REG     0x16B2
#define IBUTTON59_BYTE_3_REG     0x16B3
#define IBUTTON59_BYTE_4_REG     0x16B4
#define IBUTTON59_BYTE_5_REG     0x16B5
#define IBUTTON59_BYTE_6_REG     0x16B6
#define IBUTTON59_BYTE_7_REG     0x16B7

#define IBUTTON60_BYTE_0_REG     0x16C0 // номер ключа 60
#define IBUTTON60_BYTE_1_REG     0x16C1
#define IBUTTON60_BYTE_2_REG     0x16C2
#define IBUTTON60_BYTE_3_REG     0x16C3
#define IBUTTON60_BYTE_4_REG     0x16C4
#define IBUTTON60_BYTE_5_REG     0x16C5
#define IBUTTON60_BYTE_6_REG     0x16C6
#define IBUTTON60_BYTE_7_REG     0x16C7

#define IBUTTON61_BYTE_0_REG     0x16D0 // номер ключа 61 /////////////////////////////////
#define IBUTTON61_BYTE_1_REG     0x16D1
#define IBUTTON61_BYTE_2_REG     0x16D2
#define IBUTTON61_BYTE_3_REG     0x16D3
#define IBUTTON61_BYTE_4_REG     0x16D4
#define IBUTTON61_BYTE_5_REG     0x16D5
#define IBUTTON61_BYTE_6_REG     0x16D6
#define IBUTTON61_BYTE_7_REG     0x16D7

#define IBUTTON62_BYTE_0_REG     0x16E0 // номер ключа 62
#define IBUTTON62_BYTE_1_REG     0x16E1
#define IBUTTON62_BYTE_2_REG     0x16E2
#define IBUTTON62_BYTE_3_REG     0x16E3
#define IBUTTON62_BYTE_4_REG     0x16E4
#define IBUTTON62_BYTE_5_REG     0x16E5
#define IBUTTON62_BYTE_6_REG     0x16E6
#define IBUTTON62_BYTE_7_REG     0x16E7

#define IBUTTON63_BYTE_0_REG     0x16F0 // номер ключа 63
#define IBUTTON63_BYTE_1_REG     0x16F1
#define IBUTTON63_BYTE_2_REG     0x16F2
#define IBUTTON63_BYTE_3_REG     0x16F3
#define IBUTTON63_BYTE_4_REG     0x16F4
#define IBUTTON63_BYTE_5_REG     0x16F5
#define IBUTTON63_BYTE_6_REG     0x16F6
#define IBUTTON63_BYTE_7_REG     0x16F7

#define IBUTTON64_BYTE_0_REG     0x1700 // номер ключа 64
#define IBUTTON64_BYTE_1_REG     0x1701
#define IBUTTON64_BYTE_2_REG     0x1702
#define IBUTTON64_BYTE_3_REG     0x1703
#define IBUTTON64_BYTE_4_REG     0x1704
#define IBUTTON64_BYTE_5_REG     0x1705
#define IBUTTON64_BYTE_6_REG     0x1706
#define IBUTTON64_BYTE_7_REG     0x1707

#define IBUTTON65_BYTE_0_REG     0x1710 // номер ключа 65
#define IBUTTON65_BYTE_1_REG     0x1711
#define IBUTTON65_BYTE_2_REG     0x1712
#define IBUTTON65_BYTE_3_REG     0x1713
#define IBUTTON65_BYTE_4_REG     0x1714
#define IBUTTON65_BYTE_5_REG     0x1715
#define IBUTTON65_BYTE_6_REG     0x1716
#define IBUTTON65_BYTE_7_REG     0x1717

#define IBUTTON66_BYTE_0_REG     0x1720 // номер ключа 66
#define IBUTTON66_BYTE_1_REG     0x1721
#define IBUTTON66_BYTE_2_REG     0x1722
#define IBUTTON66_BYTE_3_REG     0x1723
#define IBUTTON66_BYTE_4_REG     0x1724
#define IBUTTON66_BYTE_5_REG     0x1725
#define IBUTTON66_BYTE_6_REG     0x1726
#define IBUTTON66_BYTE_7_REG     0x1727

#define IBUTTON67_BYTE_0_REG     0x1730 // номер ключа 67
#define IBUTTON67_BYTE_1_REG     0x1731
#define IBUTTON67_BYTE_2_REG     0x1732
#define IBUTTON67_BYTE_3_REG     0x1733
#define IBUTTON67_BYTE_4_REG     0x1734
#define IBUTTON67_BYTE_5_REG     0x1735
#define IBUTTON67_BYTE_6_REG     0x1736
#define IBUTTON67_BYTE_7_REG     0x1737

#define IBUTTON68_BYTE_0_REG     0x1740 // номер ключа 68
#define IBUTTON68_BYTE_1_REG     0x1741
#define IBUTTON68_BYTE_2_REG     0x1742
#define IBUTTON68_BYTE_3_REG     0x1743
#define IBUTTON68_BYTE_4_REG     0x1744
#define IBUTTON68_BYTE_5_REG     0x1745
#define IBUTTON68_BYTE_6_REG     0x1746
#define IBUTTON68_BYTE_7_REG     0x1747

#define IBUTTON69_BYTE_0_REG     0x1750 // номер ключа 69
#define IBUTTON69_BYTE_1_REG     0x1751
#define IBUTTON69_BYTE_2_REG     0x1752
#define IBUTTON69_BYTE_3_REG     0x1753
#define IBUTTON69_BYTE_4_REG     0x1754
#define IBUTTON69_BYTE_5_REG     0x1755
#define IBUTTON69_BYTE_6_REG     0x1756
#define IBUTTON69_BYTE_7_REG     0x1757

#define IBUTTON70_BYTE_0_REG     0x1760 // номер ключа 70
#define IBUTTON70_BYTE_1_REG     0x1761
#define IBUTTON70_BYTE_2_REG     0x1762
#define IBUTTON70_BYTE_3_REG     0x1763
#define IBUTTON70_BYTE_4_REG     0x1764
#define IBUTTON70_BYTE_5_REG     0x1765
#define IBUTTON70_BYTE_6_REG     0x1766
#define IBUTTON70_BYTE_7_REG     0x1767

#define IBUTTON71_BYTE_0_REG     0x1770 // номер ключа 71
#define IBUTTON71_BYTE_1_REG     0x1771
#define IBUTTON71_BYTE_2_REG     0x1772
#define IBUTTON71_BYTE_3_REG     0x1773
#define IBUTTON71_BYTE_4_REG     0x1774
#define IBUTTON71_BYTE_5_REG     0x1775
#define IBUTTON71_BYTE_6_REG     0x1776
#define IBUTTON71_BYTE_7_REG     0x1777

#define IBUTTON72_BYTE_0_REG     0x1780 // номер ключа 72
#define IBUTTON72_BYTE_1_REG     0x1781
#define IBUTTON72_BYTE_2_REG     0x1782
#define IBUTTON72_BYTE_3_REG     0x1783
#define IBUTTON72_BYTE_4_REG     0x1784
#define IBUTTON72_BYTE_5_REG     0x1785
#define IBUTTON72_BYTE_6_REG     0x1786
#define IBUTTON72_BYTE_7_REG     0x1787

#define IBUTTON73_BYTE_0_REG     0x1790 // номер ключа 73
#define IBUTTON73_BYTE_1_REG     0x1791
#define IBUTTON73_BYTE_2_REG     0x1792
#define IBUTTON73_BYTE_3_REG     0x1793
#define IBUTTON73_BYTE_4_REG     0x1794
#define IBUTTON73_BYTE_5_REG     0x1795
#define IBUTTON73_BYTE_6_REG     0x1796
#define IBUTTON73_BYTE_7_REG     0x1797

#define IBUTTON74_BYTE_0_REG     0x17A0 // номер ключа 74
#define IBUTTON74_BYTE_1_REG     0x17A1
#define IBUTTON74_BYTE_2_REG     0x17A2
#define IBUTTON74_BYTE_3_REG     0x17A3
#define IBUTTON74_BYTE_4_REG     0x17A4
#define IBUTTON74_BYTE_5_REG     0x17A5
#define IBUTTON74_BYTE_6_REG     0x17A6
#define IBUTTON74_BYTE_7_REG     0x17A7

#define IBUTTON75_BYTE_0_REG     0x17B0 // номер ключа 75
#define IBUTTON75_BYTE_1_REG     0x17B1
#define IBUTTON75_BYTE_2_REG     0x17B2
#define IBUTTON75_BYTE_3_REG     0x17B3
#define IBUTTON75_BYTE_4_REG     0x17B4
#define IBUTTON75_BYTE_5_REG     0x17B5
#define IBUTTON75_BYTE_6_REG     0x17B6
#define IBUTTON75_BYTE_7_REG     0x17B7

#define IBUTTON76_BYTE_0_REG     0x17C0 // номер ключа 76
#define IBUTTON76_BYTE_1_REG     0x17C1
#define IBUTTON76_BYTE_2_REG     0x17C2
#define IBUTTON76_BYTE_3_REG     0x17C3
#define IBUTTON76_BYTE_4_REG     0x17C4
#define IBUTTON76_BYTE_5_REG     0x17C5
#define IBUTTON76_BYTE_6_REG     0x17C6
#define IBUTTON76_BYTE_7_REG     0x17C7

#define IBUTTON77_BYTE_0_REG     0x17D0 // номер ключа 77
#define IBUTTON77_BYTE_1_REG     0x17D1
#define IBUTTON77_BYTE_2_REG     0x17D2
#define IBUTTON77_BYTE_3_REG     0x17D3
#define IBUTTON77_BYTE_4_REG     0x17D4
#define IBUTTON77_BYTE_5_REG     0x17D5
#define IBUTTON77_BYTE_6_REG     0x17D6
#define IBUTTON77_BYTE_7_REG     0x17D7

#define IBUTTON78_BYTE_0_REG     0x17E0 // номер ключа 78
#define IBUTTON78_BYTE_1_REG     0x17E1
#define IBUTTON78_BYTE_2_REG     0x17E2
#define IBUTTON78_BYTE_3_REG     0x17E3
#define IBUTTON78_BYTE_4_REG     0x17E4
#define IBUTTON78_BYTE_5_REG     0x17E5
#define IBUTTON78_BYTE_6_REG     0x17E6
#define IBUTTON78_BYTE_7_REG     0x17E7

#define IBUTTON79_BYTE_0_REG     0x17F0 // номер ключа 79
#define IBUTTON79_BYTE_1_REG     0x17F1
#define IBUTTON79_BYTE_2_REG     0x17F2
#define IBUTTON79_BYTE_3_REG     0x17F3
#define IBUTTON79_BYTE_4_REG     0x17F4
#define IBUTTON79_BYTE_5_REG     0x17F5
#define IBUTTON79_BYTE_6_REG     0x17F6
#define IBUTTON79_BYTE_7_REG     0x17F7

#define IBUTTON80_BYTE_0_REG     0x1800 // номер ключа 80
#define IBUTTON80_BYTE_1_REG     0x1801
#define IBUTTON80_BYTE_2_REG     0x1802
#define IBUTTON80_BYTE_3_REG     0x1803
#define IBUTTON80_BYTE_4_REG     0x1804
#define IBUTTON80_BYTE_5_REG     0x1805
#define IBUTTON80_BYTE_6_REG     0x1806
#define IBUTTON80_BYTE_7_REG     0x1807

#define IBUTTON81_BYTE_0_REG     0x1810 // номер ключа 81
#define IBUTTON81_BYTE_1_REG     0x1811
#define IBUTTON81_BYTE_2_REG     0x1812
#define IBUTTON81_BYTE_3_REG     0x1813
#define IBUTTON81_BYTE_4_REG     0x1814
#define IBUTTON81_BYTE_5_REG     0x1815
#define IBUTTON81_BYTE_6_REG     0x1816
#define IBUTTON81_BYTE_7_REG     0x1817

#define IBUTTON82_BYTE_0_REG     0x1820 // номер ключа 82
#define IBUTTON82_BYTE_1_REG     0x1821
#define IBUTTON82_BYTE_2_REG     0x1822
#define IBUTTON82_BYTE_3_REG     0x1823
#define IBUTTON82_BYTE_4_REG     0x1824
#define IBUTTON82_BYTE_5_REG     0x1825
#define IBUTTON82_BYTE_6_REG     0x1826
#define IBUTTON82_BYTE_7_REG     0x1827

#define IBUTTON83_BYTE_0_REG     0x1830 // номер ключа 83
#define IBUTTON83_BYTE_1_REG     0x1831
#define IBUTTON83_BYTE_2_REG     0x1832
#define IBUTTON83_BYTE_3_REG     0x1833
#define IBUTTON83_BYTE_4_REG     0x1834
#define IBUTTON83_BYTE_5_REG     0x1835
#define IBUTTON83_BYTE_6_REG     0x1836
#define IBUTTON83_BYTE_7_REG     0x1837

#define IBUTTON84_BYTE_0_REG     0x1840 // номер ключа 84
#define IBUTTON84_BYTE_1_REG     0x1841
#define IBUTTON84_BYTE_2_REG     0x1842
#define IBUTTON84_BYTE_3_REG     0x1843
#define IBUTTON84_BYTE_4_REG     0x1844
#define IBUTTON84_BYTE_5_REG     0x1845
#define IBUTTON84_BYTE_6_REG     0x1846
#define IBUTTON84_BYTE_7_REG     0x1847

#define IBUTTON85_BYTE_0_REG     0x1850 // номер ключа 85
#define IBUTTON85_BYTE_1_REG     0x1851
#define IBUTTON85_BYTE_2_REG     0x1852
#define IBUTTON85_BYTE_3_REG     0x1853
#define IBUTTON85_BYTE_4_REG     0x1854
#define IBUTTON85_BYTE_5_REG     0x1855
#define IBUTTON85_BYTE_6_REG     0x1856
#define IBUTTON85_BYTE_7_REG     0x1857

#define IBUTTON86_BYTE_0_REG     0x1860 // номер ключа 86
#define IBUTTON86_BYTE_1_REG     0x1861
#define IBUTTON86_BYTE_2_REG     0x1862
#define IBUTTON86_BYTE_3_REG     0x1863
#define IBUTTON86_BYTE_4_REG     0x1864
#define IBUTTON86_BYTE_5_REG     0x1865
#define IBUTTON86_BYTE_6_REG     0x1866
#define IBUTTON86_BYTE_7_REG     0x1867

#define IBUTTON87_BYTE_0_REG     0x1870 // номер ключа 87
#define IBUTTON87_BYTE_1_REG     0x1871
#define IBUTTON87_BYTE_2_REG     0x1872
#define IBUTTON87_BYTE_3_REG     0x1873
#define IBUTTON87_BYTE_4_REG     0x1874
#define IBUTTON87_BYTE_5_REG     0x1875
#define IBUTTON87_BYTE_6_REG     0x1876
#define IBUTTON87_BYTE_7_REG     0x1877

#define IBUTTON88_BYTE_0_REG     0x1880 // номер ключа 88
#define IBUTTON88_BYTE_1_REG     0x1881
#define IBUTTON88_BYTE_2_REG     0x1882
#define IBUTTON88_BYTE_3_REG     0x1883
#define IBUTTON88_BYTE_4_REG     0x1884
#define IBUTTON88_BYTE_5_REG     0x1885
#define IBUTTON88_BYTE_6_REG     0x1886
#define IBUTTON88_BYTE_7_REG     0x1887

#define IBUTTON89_BYTE_0_REG     0x1890 // номер ключа 89
#define IBUTTON89_BYTE_1_REG     0x1891
#define IBUTTON89_BYTE_2_REG     0x1892
#define IBUTTON89_BYTE_3_REG     0x1893
#define IBUTTON89_BYTE_4_REG     0x1894
#define IBUTTON89_BYTE_5_REG     0x1895
#define IBUTTON89_BYTE_6_REG     0x1896
#define IBUTTON89_BYTE_7_REG     0x1897

#define IBUTTON90_BYTE_0_REG     0x18A0 // номер ключа 90
#define IBUTTON90_BYTE_1_REG     0x18A1
#define IBUTTON90_BYTE_2_REG     0x18A2
#define IBUTTON90_BYTE_3_REG     0x18A3
#define IBUTTON90_BYTE_4_REG     0x18A4
#define IBUTTON90_BYTE_5_REG     0x18A5
#define IBUTTON90_BYTE_6_REG     0x18A6
#define IBUTTON90_BYTE_7_REG     0x18A7

#define IBUTTON91_BYTE_0_REG     0x18B0 // номер ключа 91
#define IBUTTON91_BYTE_1_REG     0x18B1
#define IBUTTON91_BYTE_2_REG     0x18B2
#define IBUTTON91_BYTE_3_REG     0x18B3
#define IBUTTON91_BYTE_4_REG     0x18B4
#define IBUTTON91_BYTE_5_REG     0x18B5
#define IBUTTON91_BYTE_6_REG     0x18B6
#define IBUTTON91_BYTE_7_REG     0x18B7

#define IBUTTON92_BYTE_0_REG     0x18C0 // номер ключа 92
#define IBUTTON92_BYTE_1_REG     0x18C1
#define IBUTTON92_BYTE_2_REG     0x18C2
#define IBUTTON92_BYTE_3_REG     0x18C3
#define IBUTTON92_BYTE_4_REG     0x18C4
#define IBUTTON92_BYTE_5_REG     0x18C5
#define IBUTTON92_BYTE_6_REG     0x18C6
#define IBUTTON92_BYTE_7_REG     0x18C7

#define IBUTTON93_BYTE_0_REG     0x18D0 // номер ключа 93
#define IBUTTON93_BYTE_1_REG     0x18D1
#define IBUTTON93_BYTE_2_REG     0x18D2
#define IBUTTON93_BYTE_3_REG     0x18D3
#define IBUTTON93_BYTE_4_REG     0x18D4
#define IBUTTON93_BYTE_5_REG     0x18D5
#define IBUTTON93_BYTE_6_REG     0x18D6
#define IBUTTON93_BYTE_7_REG     0x18D7

#define IBUTTON94_BYTE_0_REG     0x18E0 // номер ключа 94
#define IBUTTON94_BYTE_1_REG     0x18E1
#define IBUTTON94_BYTE_2_REG     0x18E2
#define IBUTTON94_BYTE_3_REG     0x18E3
#define IBUTTON94_BYTE_4_REG     0x18E4
#define IBUTTON94_BYTE_5_REG     0x18E5
#define IBUTTON94_BYTE_6_REG     0x18E6
#define IBUTTON94_BYTE_7_REG     0x18E7

#define IBUTTON95_BYTE_0_REG     0x18F0 // номер ключа 95
#define IBUTTON95_BYTE_1_REG     0x18F1
#define IBUTTON95_BYTE_2_REG     0x18F2
#define IBUTTON95_BYTE_3_REG     0x18F3
#define IBUTTON95_BYTE_4_REG     0x18F4
#define IBUTTON95_BYTE_5_REG     0x18F5
#define IBUTTON95_BYTE_6_REG     0x18F6
#define IBUTTON95_BYTE_7_REG     0x18F7

#define IBUTTON96_BYTE_0_REG     0x1900 // номер ключа 96
#define IBUTTON96_BYTE_1_REG     0x1901
#define IBUTTON96_BYTE_2_REG     0x1902
#define IBUTTON96_BYTE_3_REG     0x1903
#define IBUTTON96_BYTE_4_REG     0x1904
#define IBUTTON96_BYTE_5_REG     0x1905
#define IBUTTON96_BYTE_6_REG     0x1906
#define IBUTTON96_BYTE_7_REG     0x1907

#define IBUTTON97_BYTE_0_REG     0x1910 // номер ключа 97
#define IBUTTON97_BYTE_1_REG     0x1911
#define IBUTTON97_BYTE_2_REG     0x1912
#define IBUTTON97_BYTE_3_REG     0x1913
#define IBUTTON97_BYTE_4_REG     0x1914
#define IBUTTON97_BYTE_5_REG     0x1915
#define IBUTTON97_BYTE_6_REG     0x1916
#define IBUTTON97_BYTE_7_REG     0x1917

#define IBUTTON98_BYTE_0_REG     0x1920 // номер ключа 98
#define IBUTTON98_BYTE_1_REG     0x1921
#define IBUTTON98_BYTE_2_REG     0x1922
#define IBUTTON98_BYTE_3_REG     0x1923
#define IBUTTON98_BYTE_4_REG     0x1924
#define IBUTTON98_BYTE_5_REG     0x1925
#define IBUTTON98_BYTE_6_REG     0x1926
#define IBUTTON98_BYTE_7_REG     0x1927

#define IBUTTON99_BYTE_0_REG     0x1930 // номер ключа 99
#define IBUTTON99_BYTE_1_REG     0x1931
#define IBUTTON99_BYTE_2_REG     0x1932
#define IBUTTON99_BYTE_3_REG     0x1933
#define IBUTTON99_BYTE_4_REG     0x1934
#define IBUTTON99_BYTE_5_REG     0x1935
#define IBUTTON99_BYTE_6_REG     0x1936
#define IBUTTON99_BYTE_7_REG     0x1937

#define IBUTTON100_BYTE_0_REG     0x1940 // номер ключа 100
#define IBUTTON100_BYTE_1_REG     0x1941
#define IBUTTON100_BYTE_2_REG     0x1942
#define IBUTTON100_BYTE_3_REG     0x1943
#define IBUTTON100_BYTE_4_REG     0x1944
#define IBUTTON100_BYTE_5_REG     0x1945
#define IBUTTON100_BYTE_6_REG     0x1946
#define IBUTTON100_BYTE_7_REG     0x1947

#define IBUTTON101_BYTE_0_REG     0x1950 // номер ключа 101
#define IBUTTON101_BYTE_1_REG     0x1951
#define IBUTTON101_BYTE_2_REG     0x1952
#define IBUTTON101_BYTE_3_REG     0x1953
#define IBUTTON101_BYTE_4_REG     0x1954
#define IBUTTON101_BYTE_5_REG     0x1955
#define IBUTTON101_BYTE_6_REG     0x1956
#define IBUTTON101_BYTE_7_REG     0x1957

#define IBUTTON102_BYTE_0_REG     0x1960 // номер ключа 102
#define IBUTTON102_BYTE_1_REG     0x1961
#define IBUTTON102_BYTE_2_REG     0x1962
#define IBUTTON102_BYTE_3_REG     0x1963
#define IBUTTON102_BYTE_4_REG     0x1964
#define IBUTTON102_BYTE_5_REG     0x1965
#define IBUTTON102_BYTE_6_REG     0x1966
#define IBUTTON102_BYTE_7_REG     0x1967

#define IBUTTON103_BYTE_0_REG     0x1970 // номер ключа 103
#define IBUTTON103_BYTE_1_REG     0x1971
#define IBUTTON103_BYTE_2_REG     0x1972
#define IBUTTON103_BYTE_3_REG     0x1973
#define IBUTTON103_BYTE_4_REG     0x1974
#define IBUTTON103_BYTE_5_REG     0x1975
#define IBUTTON103_BYTE_6_REG     0x1976
#define IBUTTON103_BYTE_7_REG     0x1977

#define IBUTTON104_BYTE_0_REG     0x1980 // номер ключа 104
#define IBUTTON104_BYTE_1_REG     0x1981
#define IBUTTON104_BYTE_2_REG     0x1982
#define IBUTTON104_BYTE_3_REG     0x1983
#define IBUTTON104_BYTE_4_REG     0x1984
#define IBUTTON104_BYTE_5_REG     0x1985
#define IBUTTON104_BYTE_6_REG     0x1986
#define IBUTTON104_BYTE_7_REG     0x1987

#define IBUTTON105_BYTE_0_REG     0x1990 // номер ключа 105
#define IBUTTON105_BYTE_1_REG     0x1991
#define IBUTTON105_BYTE_2_REG     0x1992
#define IBUTTON105_BYTE_3_REG     0x1993
#define IBUTTON105_BYTE_4_REG     0x1994
#define IBUTTON105_BYTE_5_REG     0x1995
#define IBUTTON105_BYTE_6_REG     0x1996
#define IBUTTON105_BYTE_7_REG     0x1997

#define IBUTTON106_BYTE_0_REG     0x19A0 // номер ключа 106
#define IBUTTON106_BYTE_1_REG     0x19A1
#define IBUTTON106_BYTE_2_REG     0x19A2
#define IBUTTON106_BYTE_3_REG     0x19A3
#define IBUTTON106_BYTE_4_REG     0x19A4
#define IBUTTON106_BYTE_5_REG     0x19A5
#define IBUTTON106_BYTE_6_REG     0x19A6
#define IBUTTON106_BYTE_7_REG     0x19A7

#define IBUTTON107_BYTE_0_REG     0x19B0 // номер ключа 107
#define IBUTTON107_BYTE_1_REG     0x19B1
#define IBUTTON107_BYTE_2_REG     0x19B2
#define IBUTTON107_BYTE_3_REG     0x19B3
#define IBUTTON107_BYTE_4_REG     0x19B4
#define IBUTTON107_BYTE_5_REG     0x19B5
#define IBUTTON107_BYTE_6_REG     0x19B6
#define IBUTTON107_BYTE_7_REG     0x19B7

#define IBUTTON108_BYTE_0_REG     0x19C0 // номер ключа 108
#define IBUTTON108_BYTE_1_REG     0x19C1
#define IBUTTON108_BYTE_2_REG     0x19C2
#define IBUTTON108_BYTE_3_REG     0x19C3
#define IBUTTON108_BYTE_4_REG     0x19C4
#define IBUTTON108_BYTE_5_REG     0x19C5
#define IBUTTON108_BYTE_6_REG     0x19C6
#define IBUTTON108_BYTE_7_REG     0x19C7

#define IBUTTON109_BYTE_0_REG     0x19D0 // номер ключа 109
#define IBUTTON109_BYTE_1_REG     0x19D1
#define IBUTTON109_BYTE_2_REG     0x19D2
#define IBUTTON109_BYTE_3_REG     0x19D3
#define IBUTTON109_BYTE_4_REG     0x19D4
#define IBUTTON109_BYTE_5_REG     0x19D5
#define IBUTTON109_BYTE_6_REG     0x19D6
#define IBUTTON109_BYTE_7_REG     0x19D7

#define IBUTTON110_BYTE_0_REG     0x19E0 // номер ключа 110
#define IBUTTON110_BYTE_1_REG     0x19E1
#define IBUTTON110_BYTE_2_REG     0x19E2
#define IBUTTON110_BYTE_3_REG     0x19E3
#define IBUTTON110_BYTE_4_REG     0x19E4
#define IBUTTON110_BYTE_5_REG     0x19E5
#define IBUTTON110_BYTE_6_REG     0x19E6
#define IBUTTON110_BYTE_7_REG     0x19E7

#define IBUTTON111_BYTE_0_REG     0x19F0 // номер ключа 111
#define IBUTTON111_BYTE_1_REG     0x19F1
#define IBUTTON111_BYTE_2_REG     0x19F2
#define IBUTTON111_BYTE_3_REG     0x19F3
#define IBUTTON111_BYTE_4_REG     0x19F4
#define IBUTTON111_BYTE_5_REG     0x19F5
#define IBUTTON111_BYTE_6_REG     0x19F6
#define IBUTTON111_BYTE_7_REG     0x19F7

#define IBUTTON112_BYTE_0_REG     0x1A00 // номер ключа 112
#define IBUTTON112_BYTE_1_REG     0x1A01
#define IBUTTON112_BYTE_2_REG     0x1A02
#define IBUTTON112_BYTE_3_REG     0x1A03
#define IBUTTON112_BYTE_4_REG     0x1A04
#define IBUTTON112_BYTE_5_REG     0x1A05
#define IBUTTON112_BYTE_6_REG     0x1A06
#define IBUTTON112_BYTE_7_REG     0x1A07

#define IBUTTON113_BYTE_0_REG     0x1A10 // номер ключа 113
#define IBUTTON113_BYTE_1_REG     0x1A11
#define IBUTTON113_BYTE_2_REG     0x1A12
#define IBUTTON113_BYTE_3_REG     0x1A13
#define IBUTTON113_BYTE_4_REG     0x1A14
#define IBUTTON113_BYTE_5_REG     0x1A15
#define IBUTTON113_BYTE_6_REG     0x1A16
#define IBUTTON113_BYTE_7_REG     0x1A17

#define IBUTTON114_BYTE_0_REG     0x1A20 // номер ключа 114
#define IBUTTON114_BYTE_1_REG     0x1A21
#define IBUTTON114_BYTE_2_REG     0x1A22
#define IBUTTON114_BYTE_3_REG     0x1A23
#define IBUTTON114_BYTE_4_REG     0x1A24
#define IBUTTON114_BYTE_5_REG     0x1A25
#define IBUTTON114_BYTE_6_REG     0x1A26
#define IBUTTON114_BYTE_7_REG     0x1A27

#define IBUTTON115_BYTE_0_REG     0x1A30 // номер ключа 115
#define IBUTTON115_BYTE_1_REG     0x1A31
#define IBUTTON115_BYTE_2_REG     0x1A32
#define IBUTTON115_BYTE_3_REG     0x1A33
#define IBUTTON115_BYTE_4_REG     0x1A34
#define IBUTTON115_BYTE_5_REG     0x1A35
#define IBUTTON115_BYTE_6_REG     0x1A36
#define IBUTTON115_BYTE_7_REG     0x1A37

#define IBUTTON116_BYTE_0_REG     0x1A40 // номер ключа 116
#define IBUTTON116_BYTE_1_REG     0x1A41
#define IBUTTON116_BYTE_2_REG     0x1A42
#define IBUTTON116_BYTE_3_REG     0x1A43
#define IBUTTON116_BYTE_4_REG     0x1A44
#define IBUTTON116_BYTE_5_REG     0x1A45
#define IBUTTON116_BYTE_6_REG     0x1A46
#define IBUTTON116_BYTE_7_REG     0x1A47

#define IBUTTON117_BYTE_0_REG     0x1A50 // номер ключа 117
#define IBUTTON117_BYTE_1_REG     0x1A51
#define IBUTTON117_BYTE_2_REG     0x1A52
#define IBUTTON117_BYTE_3_REG     0x1A53
#define IBUTTON117_BYTE_4_REG     0x1A54
#define IBUTTON117_BYTE_5_REG     0x1A55
#define IBUTTON117_BYTE_6_REG     0x1A56
#define IBUTTON117_BYTE_7_REG     0x1A57

#define IBUTTON118_BYTE_0_REG     0x1A60 // номер ключа 118
#define IBUTTON118_BYTE_1_REG     0x1A61
#define IBUTTON118_BYTE_2_REG     0x1A62
#define IBUTTON118_BYTE_3_REG     0x1A63
#define IBUTTON118_BYTE_4_REG     0x1A64
#define IBUTTON118_BYTE_5_REG     0x1A65
#define IBUTTON118_BYTE_6_REG     0x1A66
#define IBUTTON118_BYTE_7_REG     0x1A67

#define IBUTTON119_BYTE_0_REG     0x1A70 // номер ключа 119
#define IBUTTON119_BYTE_1_REG     0x1A71
#define IBUTTON119_BYTE_2_REG     0x1A72
#define IBUTTON119_BYTE_3_REG     0x1A73
#define IBUTTON119_BYTE_4_REG     0x1A74
#define IBUTTON119_BYTE_5_REG     0x1A75
#define IBUTTON119_BYTE_6_REG     0x1A76
#define IBUTTON119_BYTE_7_REG     0x1A77

#define IBUTTON120_BYTE_0_REG     0x1A80 // номер ключа 120
#define IBUTTON120_BYTE_1_REG     0x1A81
#define IBUTTON120_BYTE_2_REG     0x1A82
#define IBUTTON120_BYTE_3_REG     0x1A83
#define IBUTTON120_BYTE_4_REG     0x1A84
#define IBUTTON120_BYTE_5_REG     0x1A85
#define IBUTTON120_BYTE_6_REG     0x1A86
#define IBUTTON120_BYTE_7_REG     0x1A87

#define IBUTTON121_BYTE_0_REG     0x1A90 // номер ключа 121
#define IBUTTON121_BYTE_1_REG     0x1A91
#define IBUTTON121_BYTE_2_REG     0x1A92
#define IBUTTON121_BYTE_3_REG     0x1A93
#define IBUTTON121_BYTE_4_REG     0x1A94
#define IBUTTON121_BYTE_5_REG     0x1A95
#define IBUTTON121_BYTE_6_REG     0x1A96
#define IBUTTON121_BYTE_7_REG     0x1A97

#define IBUTTON122_BYTE_0_REG     0x1AA0 // номер ключа 122
#define IBUTTON122_BYTE_1_REG     0x1AA1
#define IBUTTON122_BYTE_2_REG     0x1AA2
#define IBUTTON122_BYTE_3_REG     0x1AA3
#define IBUTTON122_BYTE_4_REG     0x1AA4
#define IBUTTON122_BYTE_5_REG     0x1AA5
#define IBUTTON122_BYTE_6_REG     0x1AA6
#define IBUTTON122_BYTE_7_REG     0x1AA7

#define IBUTTON123_BYTE_0_REG     0x1AB0 // номер ключа 123
#define IBUTTON123_BYTE_1_REG     0x1AB1
#define IBUTTON123_BYTE_2_REG     0x1AB2
#define IBUTTON123_BYTE_3_REG     0x1AB3
#define IBUTTON123_BYTE_4_REG     0x1AB4
#define IBUTTON123_BYTE_5_REG     0x1AB5
#define IBUTTON123_BYTE_6_REG     0x1AB6
#define IBUTTON123_BYTE_7_REG     0x1AB7

#define IBUTTON124_BYTE_0_REG     0x1AC0 // номер ключа 124
#define IBUTTON124_BYTE_1_REG     0x1AC1
#define IBUTTON124_BYTE_2_REG     0x1AC2
#define IBUTTON124_BYTE_3_REG     0x1AC3
#define IBUTTON124_BYTE_4_REG     0x1AC4
#define IBUTTON124_BYTE_5_REG     0x1AC5
#define IBUTTON124_BYTE_6_REG     0x1AC6
#define IBUTTON124_BYTE_7_REG     0x1AC7

#define IBUTTON125_BYTE_0_REG     0x1AD0 // номер ключа 125
#define IBUTTON125_BYTE_1_REG     0x1AD1
#define IBUTTON125_BYTE_2_REG     0x1AD2
#define IBUTTON125_BYTE_3_REG     0x1AD3
#define IBUTTON125_BYTE_4_REG     0x1AD4
#define IBUTTON125_BYTE_5_REG     0x1AD5
#define IBUTTON125_BYTE_6_REG     0x1AD6
#define IBUTTON125_BYTE_7_REG     0x1AD7

#define IBUTTON126_BYTE_0_REG     0x1AE0 // номер ключа 126
#define IBUTTON126_BYTE_1_REG     0x1AE1
#define IBUTTON126_BYTE_2_REG     0x1AE2
#define IBUTTON126_BYTE_3_REG     0x1AE3
#define IBUTTON126_BYTE_4_REG     0x1AE4
#define IBUTTON126_BYTE_5_REG     0x1AE5
#define IBUTTON126_BYTE_6_REG     0x1AE6
#define IBUTTON126_BYTE_7_REG     0x1AE7

#define IBUTTON127_BYTE_0_REG     0x1AF0 // номер ключа 127
#define IBUTTON127_BYTE_1_REG     0x1AF1
#define IBUTTON127_BYTE_2_REG     0x1AF2
#define IBUTTON127_BYTE_3_REG     0x1AF3
#define IBUTTON127_BYTE_4_REG     0x1AF4
#define IBUTTON127_BYTE_5_REG     0x1AF5
#define IBUTTON127_BYTE_6_REG     0x1AF6
#define IBUTTON127_BYTE_7_REG     0x1AF7

#define IBUTTON128_BYTE_0_REG     0x1B00 // номер ключа 128
#define IBUTTON128_BYTE_1_REG     0x1B01
#define IBUTTON128_BYTE_2_REG     0x1B02
#define IBUTTON128_BYTE_3_REG     0x1B03
#define IBUTTON128_BYTE_4_REG     0x1B04
#define IBUTTON128_BYTE_5_REG     0x1B05
#define IBUTTON128_BYTE_6_REG     0x1B06
#define IBUTTON128_BYTE_7_REG     0x1B07

#define IBUTTON129_BYTE_0_REG     0x1B10 // номер ключа 129
#define IBUTTON129_BYTE_1_REG     0x1B11
#define IBUTTON129_BYTE_2_REG     0x1B12
#define IBUTTON129_BYTE_3_REG     0x1B13
#define IBUTTON129_BYTE_4_REG     0x1B14
#define IBUTTON129_BYTE_5_REG     0x1B15
#define IBUTTON129_BYTE_6_REG     0x1B16
#define IBUTTON129_BYTE_7_REG     0x1B17

#define IBUTTON130_BYTE_0_REG     0x1B20 // номер ключа 130
#define IBUTTON130_BYTE_1_REG     0x1B21
#define IBUTTON130_BYTE_2_REG     0x1B22
#define IBUTTON130_BYTE_3_REG     0x1B23
#define IBUTTON130_BYTE_4_REG     0x1B24
#define IBUTTON130_BYTE_5_REG     0x1B25
#define IBUTTON130_BYTE_6_REG     0x1B26
#define IBUTTON130_BYTE_7_REG     0x1B27

#define IBUTTON131_BYTE_0_REG     0x1B30 // номер ключа 131
#define IBUTTON131_BYTE_1_REG     0x1B31
#define IBUTTON131_BYTE_2_REG     0x1B32
#define IBUTTON131_BYTE_3_REG     0x1B33
#define IBUTTON131_BYTE_4_REG     0x1B34
#define IBUTTON131_BYTE_5_REG     0x1B35
#define IBUTTON131_BYTE_6_REG     0x1B36
#define IBUTTON131_BYTE_7_REG     0x1B37

#define IBUTTON132_BYTE_0_REG     0x1B40 // номер ключа 132
#define IBUTTON132_BYTE_1_REG     0x1B41
#define IBUTTON132_BYTE_2_REG     0x1B42
#define IBUTTON132_BYTE_3_REG     0x1B43
#define IBUTTON132_BYTE_4_REG     0x1B44
#define IBUTTON132_BYTE_5_REG     0x1B45
#define IBUTTON132_BYTE_6_REG     0x1B46
#define IBUTTON132_BYTE_7_REG     0x1B47

#define IBUTTON133_BYTE_0_REG     0x1B50 // номер ключа 133
#define IBUTTON133_BYTE_1_REG     0x1B51
#define IBUTTON133_BYTE_2_REG     0x1B52
#define IBUTTON133_BYTE_3_REG     0x1B53
#define IBUTTON133_BYTE_4_REG     0x1B54
#define IBUTTON133_BYTE_5_REG     0x1B55
#define IBUTTON133_BYTE_6_REG     0x1B56
#define IBUTTON133_BYTE_7_REG     0x1B57

#define IBUTTON134_BYTE_0_REG     0x1B60 // номер ключа 134
#define IBUTTON134_BYTE_1_REG     0x1B61
#define IBUTTON134_BYTE_2_REG     0x1B62
#define IBUTTON134_BYTE_3_REG     0x1B63
#define IBUTTON134_BYTE_4_REG     0x1B64
#define IBUTTON134_BYTE_5_REG     0x1B65
#define IBUTTON134_BYTE_6_REG     0x1B66
#define IBUTTON134_BYTE_7_REG     0x1B67

#define IBUTTON135_BYTE_0_REG     0x1B70 // номер ключа 135
#define IBUTTON135_BYTE_1_REG     0x1B71
#define IBUTTON135_BYTE_2_REG     0x1B72
#define IBUTTON135_BYTE_3_REG     0x1B73
#define IBUTTON135_BYTE_4_REG     0x1B74
#define IBUTTON135_BYTE_5_REG     0x1B75
#define IBUTTON135_BYTE_6_REG     0x1B76
#define IBUTTON135_BYTE_7_REG     0x1B77

#define IBUTTON136_BYTE_0_REG     0x1B80 // номер ключа 136
#define IBUTTON136_BYTE_1_REG     0x1B81
#define IBUTTON136_BYTE_2_REG     0x1B82
#define IBUTTON136_BYTE_3_REG     0x1B83
#define IBUTTON136_BYTE_4_REG     0x1B84
#define IBUTTON136_BYTE_5_REG     0x1B85
#define IBUTTON136_BYTE_6_REG     0x1B86
#define IBUTTON136_BYTE_7_REG     0x1B87

#define IBUTTON137_BYTE_0_REG     0x1B90 // номер ключа 137
#define IBUTTON137_BYTE_1_REG     0x1B91
#define IBUTTON137_BYTE_2_REG     0x1B92
#define IBUTTON137_BYTE_3_REG     0x1B93
#define IBUTTON137_BYTE_4_REG     0x1B94
#define IBUTTON137_BYTE_5_REG     0x1B95
#define IBUTTON137_BYTE_6_REG     0x1B96
#define IBUTTON137_BYTE_7_REG     0x1B97

#define IBUTTON138_BYTE_0_REG     0x1BA0 // номер ключа 138
#define IBUTTON138_BYTE_1_REG     0x1BA1
#define IBUTTON138_BYTE_2_REG     0x1BA2
#define IBUTTON138_BYTE_3_REG     0x1BA3
#define IBUTTON138_BYTE_4_REG     0x1BA4
#define IBUTTON138_BYTE_5_REG     0x1BA5
#define IBUTTON138_BYTE_6_REG     0x1BA6
#define IBUTTON138_BYTE_7_REG     0x1BA7

#define IBUTTON139_BYTE_0_REG     0x1BB0 // номер ключа 139
#define IBUTTON139_BYTE_1_REG     0x1BB1
#define IBUTTON139_BYTE_2_REG     0x1BB2
#define IBUTTON139_BYTE_3_REG     0x1BB3
#define IBUTTON139_BYTE_4_REG     0x1BB4
#define IBUTTON139_BYTE_5_REG     0x1BB5
#define IBUTTON139_BYTE_6_REG     0x1BB6
#define IBUTTON139_BYTE_7_REG     0x1BB7

#define IBUTTON140_BYTE_0_REG     0x1BC0 // номер ключа 140
#define IBUTTON140_BYTE_1_REG     0x1BC1
#define IBUTTON140_BYTE_2_REG     0x1BC2
#define IBUTTON140_BYTE_3_REG     0x1BC3
#define IBUTTON140_BYTE_4_REG     0x1BC4
#define IBUTTON140_BYTE_5_REG     0x1BC5
#define IBUTTON140_BYTE_6_REG     0x1BC6
#define IBUTTON140_BYTE_7_REG     0x1BC7

#define IBUTTON141_BYTE_0_REG     0x1BD0 // номер ключа 141
#define IBUTTON141_BYTE_1_REG     0x1BD1
#define IBUTTON141_BYTE_2_REG     0x1BD2
#define IBUTTON141_BYTE_3_REG     0x1BD3
#define IBUTTON141_BYTE_4_REG     0x1BD4
#define IBUTTON141_BYTE_5_REG     0x1BD5
#define IBUTTON141_BYTE_6_REG     0x1BD6
#define IBUTTON141_BYTE_7_REG     0x1BD7

#define IBUTTON142_BYTE_0_REG     0x1BE0 // номер ключа 142
#define IBUTTON142_BYTE_1_REG     0x1BE1
#define IBUTTON142_BYTE_2_REG     0x1BE2
#define IBUTTON142_BYTE_3_REG     0x1BE3
#define IBUTTON142_BYTE_4_REG     0x1BE4
#define IBUTTON142_BYTE_5_REG     0x1BE5
#define IBUTTON142_BYTE_6_REG     0x1BE6
#define IBUTTON142_BYTE_7_REG     0x1BE7

#define IBUTTON143_BYTE_0_REG     0x1BF0 // номер ключа 143
#define IBUTTON143_BYTE_1_REG     0x1BF1
#define IBUTTON143_BYTE_2_REG     0x1BF2
#define IBUTTON143_BYTE_3_REG     0x1BF3
#define IBUTTON143_BYTE_4_REG     0x1BF4
#define IBUTTON143_BYTE_5_REG     0x1BF5
#define IBUTTON143_BYTE_6_REG     0x1BF6
#define IBUTTON143_BYTE_7_REG     0x1BF7

#define IBUTTON144_BYTE_0_REG     0x1C00 // номер ключа 144
#define IBUTTON144_BYTE_1_REG     0x1C01
#define IBUTTON144_BYTE_2_REG     0x1C02
#define IBUTTON144_BYTE_3_REG     0x1C03
#define IBUTTON144_BYTE_4_REG     0x1C04
#define IBUTTON144_BYTE_5_REG     0x1C05
#define IBUTTON144_BYTE_6_REG     0x1C06
#define IBUTTON144_BYTE_7_REG     0x1C07

#define IBUTTON145_BYTE_0_REG     0x1C10 // номер ключа 145
#define IBUTTON145_BYTE_1_REG     0x1C11
#define IBUTTON145_BYTE_2_REG     0x1C12
#define IBUTTON145_BYTE_3_REG     0x1C13
#define IBUTTON145_BYTE_4_REG     0x1C14
#define IBUTTON145_BYTE_5_REG     0x1C15
#define IBUTTON145_BYTE_6_REG     0x1C16
#define IBUTTON145_BYTE_7_REG     0x1C17

#define IBUTTON146_BYTE_0_REG     0x1C20 // номер ключа 146
#define IBUTTON146_BYTE_1_REG     0x1C21
#define IBUTTON146_BYTE_2_REG     0x1C22
#define IBUTTON146_BYTE_3_REG     0x1C23
#define IBUTTON146_BYTE_4_REG     0x1C24
#define IBUTTON146_BYTE_5_REG     0x1C25
#define IBUTTON146_BYTE_6_REG     0x1C26
#define IBUTTON146_BYTE_7_REG     0x1C27

#define IBUTTON147_BYTE_0_REG     0x1C30 // номер ключа 147
#define IBUTTON147_BYTE_1_REG     0x1C31
#define IBUTTON147_BYTE_2_REG     0x1C32
#define IBUTTON147_BYTE_3_REG     0x1C33
#define IBUTTON147_BYTE_4_REG     0x1C34
#define IBUTTON147_BYTE_5_REG     0x1C35
#define IBUTTON147_BYTE_6_REG     0x1C36
#define IBUTTON147_BYTE_7_REG     0x1C37

#define IBUTTON148_BYTE_0_REG     0x1C40 // номер ключа 148
#define IBUTTON148_BYTE_1_REG     0x1C41
#define IBUTTON148_BYTE_2_REG     0x1C42
#define IBUTTON148_BYTE_3_REG     0x1C43
#define IBUTTON148_BYTE_4_REG     0x1C44
#define IBUTTON148_BYTE_5_REG     0x1C45
#define IBUTTON148_BYTE_6_REG     0x1C46
#define IBUTTON148_BYTE_7_REG     0x1C47

#define IBUTTON149_BYTE_0_REG     0x1C50 // номер ключа 149
#define IBUTTON149_BYTE_1_REG     0x1C51
#define IBUTTON149_BYTE_2_REG     0x1C52
#define IBUTTON149_BYTE_3_REG     0x1C53
#define IBUTTON149_BYTE_4_REG     0x1C54
#define IBUTTON149_BYTE_5_REG     0x1C55
#define IBUTTON149_BYTE_6_REG     0x1C56
#define IBUTTON149_BYTE_7_REG     0x1C57

#define IBUTTON150_BYTE_0_REG     0x1C60 // номер ключа 150
#define IBUTTON150_BYTE_1_REG     0x1C61
#define IBUTTON150_BYTE_2_REG     0x1C62
#define IBUTTON150_BYTE_3_REG     0x1C63
#define IBUTTON150_BYTE_4_REG     0x1C64
#define IBUTTON150_BYTE_5_REG     0x1C65
#define IBUTTON150_BYTE_6_REG     0x1C66
#define IBUTTON150_BYTE_7_REG     0x1C67

#define IBUTTON151_BYTE_0_REG     0x1C70 // номер ключа 151
#define IBUTTON151_BYTE_1_REG     0x1C71
#define IBUTTON151_BYTE_2_REG     0x1C72
#define IBUTTON151_BYTE_3_REG     0x1C73
#define IBUTTON151_BYTE_4_REG     0x1C74
#define IBUTTON151_BYTE_5_REG     0x1C75
#define IBUTTON151_BYTE_6_REG     0x1C76
#define IBUTTON151_BYTE_7_REG     0x1C77

#define IBUTTON152_BYTE_0_REG     0x1C80 // номер ключа 152
#define IBUTTON152_BYTE_1_REG     0x1C81
#define IBUTTON152_BYTE_2_REG     0x1C82
#define IBUTTON152_BYTE_3_REG     0x1C83
#define IBUTTON152_BYTE_4_REG     0x1C84
#define IBUTTON152_BYTE_5_REG     0x1C85
#define IBUTTON152_BYTE_6_REG     0x1C86
#define IBUTTON152_BYTE_7_REG     0x1C87

#define IBUTTON153_BYTE_0_REG     0x1C90 // номер ключа 153
#define IBUTTON153_BYTE_1_REG     0x1C91
#define IBUTTON153_BYTE_2_REG     0x1C92
#define IBUTTON153_BYTE_3_REG     0x1C93
#define IBUTTON153_BYTE_4_REG     0x1C94
#define IBUTTON153_BYTE_5_REG     0x1C95
#define IBUTTON153_BYTE_6_REG     0x1C96
#define IBUTTON153_BYTE_7_REG     0x1C97

#define IBUTTON154_BYTE_0_REG     0x1CA0 // номер ключа 154
#define IBUTTON154_BYTE_1_REG     0x1CA1
#define IBUTTON154_BYTE_2_REG     0x1CA2
#define IBUTTON154_BYTE_3_REG     0x1CA3
#define IBUTTON154_BYTE_4_REG     0x1CA4
#define IBUTTON154_BYTE_5_REG     0x1CA5
#define IBUTTON154_BYTE_6_REG     0x1CA6
#define IBUTTON154_BYTE_7_REG     0x1CA7

#define IBUTTON155_BYTE_0_REG     0x1CB0 // номер ключа 155
#define IBUTTON155_BYTE_1_REG     0x1CB1
#define IBUTTON155_BYTE_2_REG     0x1CB2
#define IBUTTON155_BYTE_3_REG     0x1CB3
#define IBUTTON155_BYTE_4_REG     0x1CB4
#define IBUTTON155_BYTE_5_REG     0x1CB5
#define IBUTTON155_BYTE_6_REG     0x1CB6
#define IBUTTON155_BYTE_7_REG     0x1CB7

#define IBUTTON156_BYTE_0_REG     0x1CC0 // номер ключа 156
#define IBUTTON156_BYTE_1_REG     0x1CC1
#define IBUTTON156_BYTE_2_REG     0x1CC2
#define IBUTTON156_BYTE_3_REG     0x1CC3
#define IBUTTON156_BYTE_4_REG     0x1CC4
#define IBUTTON156_BYTE_5_REG     0x1CC5
#define IBUTTON156_BYTE_6_REG     0x1CC6
#define IBUTTON156_BYTE_7_REG     0x1CC7

#define IBUTTON157_BYTE_0_REG     0x1CD0 // номер ключа 157
#define IBUTTON157_BYTE_1_REG     0x1CD1
#define IBUTTON157_BYTE_2_REG     0x1CD2
#define IBUTTON157_BYTE_3_REG     0x1CD3
#define IBUTTON157_BYTE_4_REG     0x1CD4
#define IBUTTON157_BYTE_5_REG     0x1CD5
#define IBUTTON157_BYTE_6_REG     0x1CD6
#define IBUTTON157_BYTE_7_REG     0x1CD7

#define IBUTTON158_BYTE_0_REG     0x1CE0 // номер ключа 158
#define IBUTTON158_BYTE_1_REG     0x1CE1
#define IBUTTON158_BYTE_2_REG     0x1CE2
#define IBUTTON158_BYTE_3_REG     0x1CE3
#define IBUTTON158_BYTE_4_REG     0x1CE4
#define IBUTTON158_BYTE_5_REG     0x1CE5
#define IBUTTON158_BYTE_6_REG     0x1CE6
#define IBUTTON158_BYTE_7_REG     0x1CE7

#define IBUTTON159_BYTE_0_REG     0x1CF0 // номер ключа 159
#define IBUTTON159_BYTE_1_REG     0x1CF1
#define IBUTTON159_BYTE_2_REG     0x1CF2
#define IBUTTON159_BYTE_3_REG     0x1CF3
#define IBUTTON159_BYTE_4_REG     0x1CF4
#define IBUTTON159_BYTE_5_REG     0x1CF5
#define IBUTTON159_BYTE_6_REG     0x1CF6
#define IBUTTON159_BYTE_7_REG     0x1CF7

#define IBUTTON160_BYTE_0_REG     0x1D00 // номер ключа 160
#define IBUTTON160_BYTE_1_REG     0x1D01
#define IBUTTON160_BYTE_2_REG     0x1D02
#define IBUTTON160_BYTE_3_REG     0x1D03
#define IBUTTON160_BYTE_4_REG     0x1D04
#define IBUTTON160_BYTE_5_REG     0x1D05
#define IBUTTON160_BYTE_6_REG     0x1D06
#define IBUTTON160_BYTE_7_REG     0x1D07

#define IBUTTON161_BYTE_0_REG     0x1D10 // номер ключа 161
#define IBUTTON161_BYTE_1_REG     0x1D11
#define IBUTTON161_BYTE_2_REG     0x1D12
#define IBUTTON161_BYTE_3_REG     0x1D13
#define IBUTTON161_BYTE_4_REG     0x1D14
#define IBUTTON161_BYTE_5_REG     0x1D15
#define IBUTTON161_BYTE_6_REG     0x1D16
#define IBUTTON161_BYTE_7_REG     0x1D17

#define IBUTTON162_BYTE_0_REG     0x1D20 // номер ключа 162
#define IBUTTON162_BYTE_1_REG     0x1D21
#define IBUTTON162_BYTE_2_REG     0x1D22
#define IBUTTON162_BYTE_3_REG     0x1D23
#define IBUTTON162_BYTE_4_REG     0x1D24
#define IBUTTON162_BYTE_5_REG     0x1D25
#define IBUTTON162_BYTE_6_REG     0x1D26
#define IBUTTON162_BYTE_7_REG     0x1D27

#define IBUTTON163_BYTE_0_REG     0x1D30 // номер ключа 163
#define IBUTTON163_BYTE_1_REG     0x1D31
#define IBUTTON163_BYTE_2_REG     0x1D32
#define IBUTTON163_BYTE_3_REG     0x1D33
#define IBUTTON163_BYTE_4_REG     0x1D34
#define IBUTTON163_BYTE_5_REG     0x1D35
#define IBUTTON163_BYTE_6_REG     0x1D36
#define IBUTTON163_BYTE_7_REG     0x1D37

#define IBUTTON164_BYTE_0_REG     0x1D40 // номер ключа 164
#define IBUTTON164_BYTE_1_REG     0x1D41
#define IBUTTON164_BYTE_2_REG     0x1D42
#define IBUTTON164_BYTE_3_REG     0x1D43
#define IBUTTON164_BYTE_4_REG     0x1D44
#define IBUTTON164_BYTE_5_REG     0x1D45
#define IBUTTON164_BYTE_6_REG     0x1D46
#define IBUTTON164_BYTE_7_REG     0x1D47

#define IBUTTON165_BYTE_0_REG     0x1D50 // номер ключа 165
#define IBUTTON165_BYTE_1_REG     0x1D51
#define IBUTTON165_BYTE_2_REG     0x1D52
#define IBUTTON165_BYTE_3_REG     0x1D53
#define IBUTTON165_BYTE_4_REG     0x1D54
#define IBUTTON165_BYTE_5_REG     0x1D55
#define IBUTTON165_BYTE_6_REG     0x1D56
#define IBUTTON165_BYTE_7_REG     0x1D57

#define IBUTTON166_BYTE_0_REG     0x1D60 // номер ключа 166
#define IBUTTON166_BYTE_1_REG     0x1D61
#define IBUTTON166_BYTE_2_REG     0x1D62
#define IBUTTON166_BYTE_3_REG     0x1D63
#define IBUTTON166_BYTE_4_REG     0x1D64
#define IBUTTON166_BYTE_5_REG     0x1D65
#define IBUTTON166_BYTE_6_REG     0x1D66
#define IBUTTON166_BYTE_7_REG     0x1D67

#define IBUTTON167_BYTE_0_REG     0x1D70 // номер ключа 167
#define IBUTTON167_BYTE_1_REG     0x1D71
#define IBUTTON167_BYTE_2_REG     0x1D72
#define IBUTTON167_BYTE_3_REG     0x1D73
#define IBUTTON167_BYTE_4_REG     0x1D74
#define IBUTTON167_BYTE_5_REG     0x1D75
#define IBUTTON167_BYTE_6_REG     0x1D76
#define IBUTTON167_BYTE_7_REG     0x1D77

#define IBUTTON168_BYTE_0_REG     0x1D80 // номер ключа 168
#define IBUTTON168_BYTE_1_REG     0x1D81
#define IBUTTON168_BYTE_2_REG     0x1D82
#define IBUTTON168_BYTE_3_REG     0x1D83
#define IBUTTON168_BYTE_4_REG     0x1D84
#define IBUTTON168_BYTE_5_REG     0x1D85
#define IBUTTON168_BYTE_6_REG     0x1D86
#define IBUTTON168_BYTE_7_REG     0x1D87

#define IBUTTON169_BYTE_0_REG     0x1D90 // номер ключа 169
#define IBUTTON169_BYTE_1_REG     0x1D91
#define IBUTTON169_BYTE_2_REG     0x1D92
#define IBUTTON169_BYTE_3_REG     0x1D93
#define IBUTTON169_BYTE_4_REG     0x1D94
#define IBUTTON169_BYTE_5_REG     0x1D95
#define IBUTTON169_BYTE_6_REG     0x1D96
#define IBUTTON169_BYTE_7_REG     0x1D97

#define IBUTTON170_BYTE_0_REG     0x1DA0 // номер ключа 170
#define IBUTTON170_BYTE_1_REG     0x1DA1
#define IBUTTON170_BYTE_2_REG     0x1DA2
#define IBUTTON170_BYTE_3_REG     0x1DA3
#define IBUTTON170_BYTE_4_REG     0x1DA4
#define IBUTTON170_BYTE_5_REG     0x1DA5
#define IBUTTON170_BYTE_6_REG     0x1DA6
#define IBUTTON170_BYTE_7_REG     0x1DA7

#define IBUTTON171_BYTE_0_REG     0x1DB0 // номер ключа 171
#define IBUTTON171_BYTE_1_REG     0x1DB1
#define IBUTTON171_BYTE_2_REG     0x1DB2
#define IBUTTON171_BYTE_3_REG     0x1DB3
#define IBUTTON171_BYTE_4_REG     0x1DB4
#define IBUTTON171_BYTE_5_REG     0x1DB5
#define IBUTTON171_BYTE_6_REG     0x1DB6
#define IBUTTON171_BYTE_7_REG     0x1DB7

#define IBUTTON172_BYTE_0_REG     0x1DC0 // номер ключа 172
#define IBUTTON172_BYTE_1_REG     0x1DC1
#define IBUTTON172_BYTE_2_REG     0x1DC2
#define IBUTTON172_BYTE_3_REG     0x1DC3
#define IBUTTON172_BYTE_4_REG     0x1DC4
#define IBUTTON172_BYTE_5_REG     0x1DC5
#define IBUTTON172_BYTE_6_REG     0x1DC6
#define IBUTTON172_BYTE_7_REG     0x1DC7

#define IBUTTON173_BYTE_0_REG     0x1DD0 // номер ключа 173
#define IBUTTON173_BYTE_1_REG     0x1DD1
#define IBUTTON173_BYTE_2_REG     0x1DD2
#define IBUTTON173_BYTE_3_REG     0x1DD3
#define IBUTTON173_BYTE_4_REG     0x1DD4
#define IBUTTON173_BYTE_5_REG     0x1DD5
#define IBUTTON173_BYTE_6_REG     0x1DD6
#define IBUTTON173_BYTE_7_REG     0x1DD7

#define IBUTTON174_BYTE_0_REG     0x1DE0 // номер ключа 174
#define IBUTTON174_BYTE_1_REG     0x1DE1
#define IBUTTON174_BYTE_2_REG     0x1DE2
#define IBUTTON174_BYTE_3_REG     0x1DE3
#define IBUTTON174_BYTE_4_REG     0x1DE4
#define IBUTTON174_BYTE_5_REG     0x1DE5
#define IBUTTON174_BYTE_6_REG     0x1DE6
#define IBUTTON174_BYTE_7_REG     0x1DE7

#define IBUTTON175_BYTE_0_REG     0x1DF0 // номер ключа 175
#define IBUTTON175_BYTE_1_REG     0x1DF1
#define IBUTTON175_BYTE_2_REG     0x1DF2
#define IBUTTON175_BYTE_3_REG     0x1DF3
#define IBUTTON175_BYTE_4_REG     0x1DF4
#define IBUTTON175_BYTE_5_REG     0x1DF5
#define IBUTTON175_BYTE_6_REG     0x1DF6
#define IBUTTON175_BYTE_7_REG     0x1DF7

#define IBUTTON176_BYTE_0_REG     0x1E00 // номер ключа 176
#define IBUTTON176_BYTE_1_REG     0x1E01
#define IBUTTON176_BYTE_2_REG     0x1E02
#define IBUTTON176_BYTE_3_REG     0x1E03
#define IBUTTON176_BYTE_4_REG     0x1E04
#define IBUTTON176_BYTE_5_REG     0x1E05
#define IBUTTON176_BYTE_6_REG     0x1E06
#define IBUTTON176_BYTE_7_REG     0x1E07

#define IBUTTON177_BYTE_0_REG     0x1E10 // номер ключа 177
#define IBUTTON177_BYTE_1_REG     0x1E11
#define IBUTTON177_BYTE_2_REG     0x1E12
#define IBUTTON177_BYTE_3_REG     0x1E13
#define IBUTTON177_BYTE_4_REG     0x1E14
#define IBUTTON177_BYTE_5_REG     0x1E15
#define IBUTTON177_BYTE_6_REG     0x1E16
#define IBUTTON177_BYTE_7_REG     0x1E17

#define IBUTTON178_BYTE_0_REG     0x1E20 // номер ключа 178
#define IBUTTON178_BYTE_1_REG     0x1E21
#define IBUTTON178_BYTE_2_REG     0x1E22
#define IBUTTON178_BYTE_3_REG     0x1E23
#define IBUTTON178_BYTE_4_REG     0x1E24
#define IBUTTON178_BYTE_5_REG     0x1E25
#define IBUTTON178_BYTE_6_REG     0x1E26
#define IBUTTON178_BYTE_7_REG     0x1E27

#define IBUTTON179_BYTE_0_REG     0x1E30 // номер ключа 179
#define IBUTTON179_BYTE_1_REG     0x1E31
#define IBUTTON179_BYTE_2_REG     0x1E32
#define IBUTTON179_BYTE_3_REG     0x1E33
#define IBUTTON179_BYTE_4_REG     0x1E34
#define IBUTTON179_BYTE_5_REG     0x1E35
#define IBUTTON179_BYTE_6_REG     0x1E36
#define IBUTTON179_BYTE_7_REG     0x1E37

#define IBUTTON180_BYTE_0_REG     0x1E40 // номер ключа 180
#define IBUTTON180_BYTE_1_REG     0x1E41
#define IBUTTON180_BYTE_2_REG     0x1E42
#define IBUTTON180_BYTE_3_REG     0x1E43
#define IBUTTON180_BYTE_4_REG     0x1E44
#define IBUTTON180_BYTE_5_REG     0x1E45
#define IBUTTON180_BYTE_6_REG     0x1E46
#define IBUTTON180_BYTE_7_REG     0x1E47

#define IBUTTON181_BYTE_0_REG     0x1E50 // номер ключа 181
#define IBUTTON181_BYTE_1_REG     0x1E51
#define IBUTTON181_BYTE_2_REG     0x1E52
#define IBUTTON181_BYTE_3_REG     0x1E53
#define IBUTTON181_BYTE_4_REG     0x1E54
#define IBUTTON181_BYTE_5_REG     0x1E55
#define IBUTTON181_BYTE_6_REG     0x1E56
#define IBUTTON181_BYTE_7_REG     0x1E57

#define IBUTTON182_BYTE_0_REG     0x1E60 // номер ключа 182
#define IBUTTON182_BYTE_1_REG     0x1E61
#define IBUTTON182_BYTE_2_REG     0x1E62
#define IBUTTON182_BYTE_3_REG     0x1E63
#define IBUTTON182_BYTE_4_REG     0x1E64
#define IBUTTON182_BYTE_5_REG     0x1E65
#define IBUTTON182_BYTE_6_REG     0x1E66
#define IBUTTON182_BYTE_7_REG     0x1E67

#define IBUTTON183_BYTE_0_REG     0x1E70 // номер ключа 183
#define IBUTTON183_BYTE_1_REG     0x1E71
#define IBUTTON183_BYTE_2_REG     0x1E72
#define IBUTTON183_BYTE_3_REG     0x1E73
#define IBUTTON183_BYTE_4_REG     0x1E74
#define IBUTTON183_BYTE_5_REG     0x1E75
#define IBUTTON183_BYTE_6_REG     0x1E76
#define IBUTTON183_BYTE_7_REG     0x1E77

#define IBUTTON184_BYTE_0_REG     0x1E80 // номер ключа 184
#define IBUTTON184_BYTE_1_REG     0x1E81
#define IBUTTON184_BYTE_2_REG     0x1E82
#define IBUTTON184_BYTE_3_REG     0x1E83
#define IBUTTON184_BYTE_4_REG     0x1E84
#define IBUTTON184_BYTE_5_REG     0x1E85
#define IBUTTON184_BYTE_6_REG     0x1E86
#define IBUTTON184_BYTE_7_REG     0x1E87

#define IBUTTON185_BYTE_0_REG     0x1E90 // номер ключа 185
#define IBUTTON185_BYTE_1_REG     0x1E91
#define IBUTTON185_BYTE_2_REG     0x1E92
#define IBUTTON185_BYTE_3_REG     0x1E93
#define IBUTTON185_BYTE_4_REG     0x1E94
#define IBUTTON185_BYTE_5_REG     0x1E95
#define IBUTTON185_BYTE_6_REG     0x1E96
#define IBUTTON185_BYTE_7_REG     0x1E97

#define IBUTTON186_BYTE_0_REG     0x1EA0 // номер ключа 186
#define IBUTTON186_BYTE_1_REG     0x1EA1
#define IBUTTON186_BYTE_2_REG     0x1EA2
#define IBUTTON186_BYTE_3_REG     0x1EA3
#define IBUTTON186_BYTE_4_REG     0x1EA4
#define IBUTTON186_BYTE_5_REG     0x1EA5
#define IBUTTON186_BYTE_6_REG     0x1EA6
#define IBUTTON186_BYTE_7_REG     0x1EA7

#define IBUTTON187_BYTE_0_REG     0x1EB0 // номер ключа 187
#define IBUTTON187_BYTE_1_REG     0x1EB1
#define IBUTTON187_BYTE_2_REG     0x1EB2
#define IBUTTON187_BYTE_3_REG     0x1EB3
#define IBUTTON187_BYTE_4_REG     0x1EB4
#define IBUTTON187_BYTE_5_REG     0x1EB5
#define IBUTTON187_BYTE_6_REG     0x1EB6
#define IBUTTON187_BYTE_7_REG     0x1EB7

#define IBUTTON188_BYTE_0_REG     0x1EC0 // номер ключа 188
#define IBUTTON188_BYTE_1_REG     0x1EC1
#define IBUTTON188_BYTE_2_REG     0x1EC2
#define IBUTTON188_BYTE_3_REG     0x1EC3
#define IBUTTON188_BYTE_4_REG     0x1EC4
#define IBUTTON188_BYTE_5_REG     0x1EC5
#define IBUTTON188_BYTE_6_REG     0x1EC6
#define IBUTTON188_BYTE_7_REG     0x1EC7

#define IBUTTON189_BYTE_0_REG     0x1ED0 // номер ключа 189
#define IBUTTON189_BYTE_1_REG     0x1ED1
#define IBUTTON189_BYTE_2_REG     0x1ED2
#define IBUTTON189_BYTE_3_REG     0x1ED3
#define IBUTTON189_BYTE_4_REG     0x1ED4
#define IBUTTON189_BYTE_5_REG     0x1ED5
#define IBUTTON189_BYTE_6_REG     0x1ED6
#define IBUTTON189_BYTE_7_REG     0x1ED7

#define IBUTTON190_BYTE_0_REG     0x1EE0 // номер ключа 190
#define IBUTTON190_BYTE_1_REG     0x1EE1
#define IBUTTON190_BYTE_2_REG     0x1EE2
#define IBUTTON190_BYTE_3_REG     0x1EE3
#define IBUTTON190_BYTE_4_REG     0x1EE4
#define IBUTTON190_BYTE_5_REG     0x1EE5
#define IBUTTON190_BYTE_6_REG     0x1EE6
#define IBUTTON190_BYTE_7_REG     0x1EE7

#define IBUTTON191_BYTE_0_REG     0x1EF0 // номер ключа 191
#define IBUTTON191_BYTE_1_REG     0x1EF1
#define IBUTTON191_BYTE_2_REG     0x1EF2
#define IBUTTON191_BYTE_3_REG     0x1EF3
#define IBUTTON191_BYTE_4_REG     0x1EF4
#define IBUTTON191_BYTE_5_REG     0x1EF5
#define IBUTTON191_BYTE_6_REG     0x1EF6
#define IBUTTON191_BYTE_7_REG     0x1EF7

#define IBUTTON192_BYTE_0_REG     0x1F00 // номер ключа 192
#define IBUTTON192_BYTE_1_REG     0x1F01
#define IBUTTON192_BYTE_2_REG     0x1F02
#define IBUTTON192_BYTE_3_REG     0x1F03
#define IBUTTON192_BYTE_4_REG     0x1F04
#define IBUTTON192_BYTE_5_REG     0x1F05
#define IBUTTON192_BYTE_6_REG     0x1F06
#define IBUTTON192_BYTE_7_REG     0x1F07

#define IBUTTON193_BYTE_0_REG     0x1F10 // номер ключа 193
#define IBUTTON193_BYTE_1_REG     0x1F11
#define IBUTTON193_BYTE_2_REG     0x1F12
#define IBUTTON193_BYTE_3_REG     0x1F13
#define IBUTTON193_BYTE_4_REG     0x1F14
#define IBUTTON193_BYTE_5_REG     0x1F15
#define IBUTTON193_BYTE_6_REG     0x1F16
#define IBUTTON193_BYTE_7_REG     0x1F17

#define IBUTTON194_BYTE_0_REG     0x1F20 // номер ключа 194
#define IBUTTON194_BYTE_1_REG     0x1F21
#define IBUTTON194_BYTE_2_REG     0x1F22
#define IBUTTON194_BYTE_3_REG     0x1F23
#define IBUTTON194_BYTE_4_REG     0x1F24
#define IBUTTON194_BYTE_5_REG     0x1F25
#define IBUTTON194_BYTE_6_REG     0x1F26
#define IBUTTON194_BYTE_7_REG     0x1F27

#define IBUTTON195_BYTE_0_REG     0x1F30 // номер ключа 195
#define IBUTTON195_BYTE_1_REG     0x1F31
#define IBUTTON195_BYTE_2_REG     0x1F32
#define IBUTTON195_BYTE_3_REG     0x1F33
#define IBUTTON195_BYTE_4_REG     0x1F34
#define IBUTTON195_BYTE_5_REG     0x1F35
#define IBUTTON195_BYTE_6_REG     0x1F36
#define IBUTTON195_BYTE_7_REG     0x1F37

#define IBUTTON196_BYTE_0_REG     0x1F40 // номер ключа 196
#define IBUTTON196_BYTE_1_REG     0x1F41
#define IBUTTON196_BYTE_2_REG     0x1F42
#define IBUTTON196_BYTE_3_REG     0x1F43
#define IBUTTON196_BYTE_4_REG     0x1F44
#define IBUTTON196_BYTE_5_REG     0x1F45
#define IBUTTON196_BYTE_6_REG     0x1F46
#define IBUTTON196_BYTE_7_REG     0x1F47

#define IBUTTON197_BYTE_0_REG     0x1F50 // номер ключа 197
#define IBUTTON197_BYTE_1_REG     0x1F51
#define IBUTTON197_BYTE_2_REG     0x1F52
#define IBUTTON197_BYTE_3_REG     0x1F53
#define IBUTTON197_BYTE_4_REG     0x1F54
#define IBUTTON197_BYTE_5_REG     0x1F55
#define IBUTTON197_BYTE_6_REG     0x1F56
#define IBUTTON197_BYTE_7_REG     0x1F57

#define IBUTTON198_BYTE_0_REG     0x1F60 // номер ключа 198
#define IBUTTON198_BYTE_1_REG     0x1F61
#define IBUTTON198_BYTE_2_REG     0x1F62
#define IBUTTON198_BYTE_3_REG     0x1F63
#define IBUTTON198_BYTE_4_REG     0x1F64
#define IBUTTON198_BYTE_5_REG     0x1F65
#define IBUTTON198_BYTE_6_REG     0x1F66
#define IBUTTON198_BYTE_7_REG     0x1F67

#define IBUTTON199_BYTE_0_REG     0x1F70 // номер ключа 199
#define IBUTTON199_BYTE_1_REG     0x1F71
#define IBUTTON199_BYTE_2_REG     0x1F72
#define IBUTTON199_BYTE_3_REG     0x1F73
#define IBUTTON199_BYTE_4_REG     0x1F74
#define IBUTTON199_BYTE_5_REG     0x1F75
#define IBUTTON199_BYTE_6_REG     0x1F76
#define IBUTTON199_BYTE_7_REG     0x1F77



//--------------------------------------------------------


//----биты состояния байта SECURITY_STATUS_REG статус режима охраны------

#define RESERVED_0          0x00 // зарезервированно
#define ENABLED_BY_SERVER   0x01 // включена из центра
#define DISABLED_BY_SERVER  0x02 // отключена из центра
#define ENABLED_BY_IBUTTON  0x03 // включена таблеткой
#define DISABLED_BY_IBUTTON 0x04 // отключена таблеткой
#define DOOR_OPEN_ALARM     0x05 // тревога открытия двери
#define ARMING_PROCESS      0x06 // процесс постановки на охрану
#define ARMING_ERROR        0x07 // не удается поставить на охрану
#define DOOR_OPEN_POWER_OFF 0x08 // открытие двери плюс отключение основного питания

//-----------------------------------------------------------------------

//----биты security_control регистра-------------------------------------
//#define DISABLE_FROM_SERVER      0x02 // отключить из центра
//#define ENABLE_FROM_SERVER       0x01 // включить из центра
//#define DISABLE_FROM_IBUTTON     0x00 // отключить с таблетки
//#define ENABLE_FROM_IBUTTON      0x03 // ввключить с таблетки
//#define SECURITY_CONTROL_DEFAULT 0x04 // состояние покоя

#define DISABLE_FROM_SERVER      0x02 // отключить из центра
#define ENABLE_FROM_SERVER       0x01 // включить из центра
#define DISABLE_FROM_IBUTTON     0x04 // отключить с таблетки
#define ENABLE_FROM_IBUTTON      0x03 // ввключить с таблетки
#define SECURITY_CONTROL_DEFAULT 0x00 // состояние покоя
//-----------------------------------------------------------------------

//----биты time_update регистра------------------------------------------
#define SET_TIME_DEFAULT 0x00
#define SET_TIME         0x01
//-----------------------------------------------------------------------

//----биты gprs_call_reg регистра------------------------------------------
#define CALL_OFF  0x00
#define CALL_ON   0x01
//-----------------------------------------------------------------------

//----биты system_status регистра------------------------------------------
#define POWER_ON     0x01
#define POWER_OFF    0x02
#define MODEM_RESET  0x03
#define MCU_RESET    0x04
#define SESSION_QUARD_TIME 0x05
#define TURN_ON_STATE_ALARM 0x06
#define TURN_OFF_STATE_ALARM 0x07
#define TURN_ON_ALARM_ERROR 0x08
#define ERROR_LOOP 0x09
#define ALARM_STATE 0x0A
#define LOST_GSM_CONNECTION 0x0B
#define RESTORED_GSM_CONNECTION 0x0C
//-----------------------------------------------------------------------

//----биты mute_reg регистра------------------------------------------
#define MUTE_OFF  0x00
#define MUTE_ON   0x01
//-----------------------------------------------------------------------

//----биты LIGHTING_SWITCHING_REG регистра, включение функции освещения----
#define LIGHTING_ON  0x01 // функция освещения включена
#define LIGHTING_OFF 0x00 // функция освещения выключена
//-------------------------------------------------------------------------

//----биты ALARM_SWITCHING_REG регистра, включение охранной функции--------
#define ALARM_ON  0x01 // охранная функция включена
#define ALARM_OFF 0x00 // охранная функция выключена
//-------------------------------------------------------------------------

//----биты LIGHT_CONTROL_REG регистра-------------------------------
#define PHASE_A_SWITCH_OFF      0x00
#define PHASE_A_SWITCH_ON       0x01
#define PHASE_A_SWITCH_DEFAULT  0x02
#define PHASE_B_SWITCH_OFF      0x00
#define PHASE_B_SWITCH_ON       0x02
#define PHASE_C_SWITCH_OFF      0x00
#define PHASE_C_SWITCH_ON       0x04
//------------------------------------------------------------------

//----структура переменной статусных регистров---------------------
typedef struct
{
	uint16_t version_reg;
	uint16_t security_status_reg;
	uint16_t status_loop_reg;
	uint16_t error_loop_reg;
	uint16_t alarm_loop_reg;
	uint16_t time_current_year_reg;
	uint16_t time_current_month_reg;
	uint16_t time_current_day_reg;
	uint16_t time_current_hour_reg;
	uint16_t time_current_minute_reg;
	uint16_t time_current_second_reg;
	uint16_t time_current_weekday_reg;
	uint16_t address_processed_event_h_reg;
	uint16_t address_processed_event_l_reg;
	uint16_t address_last_event_h_reg;
	uint16_t address_last_event_l_reg;
	uint16_t system_status_reg;
	uint16_t power_on_reg;
	uint16_t error_rtc_reg;
	uint16_t power_on_lighting_reg;
	uint16_t reserved_2;
	uint16_t ibutton_complite_0_reg;
	uint16_t ibutton_complite_1_reg;
	uint16_t ibutton_complite_2_reg;
	uint16_t ibutton_complite_3_reg;
	uint16_t ibutton_complite_4_reg;
	uint16_t ibutton_complite_5_reg;
	uint16_t ibutton_complite_6_reg;
	uint16_t ibutton_complite_7_reg;
	uint16_t reserved_3;
	uint16_t ce303_error_reg;
	uint16_t ce303_current_a_reg;
	uint16_t ce303_current_b_reg;
	uint16_t ce303_current_c_reg;
	uint16_t ce303_current_mil_a_reg;
	uint16_t ce303_current_mil_b_reg;
	uint16_t ce303_current_mil_c_reg;
	uint16_t ce303_volt_a_reg;
	uint16_t ce303_volt_b_reg;
	uint16_t ce303_volt_c_reg;
	uint16_t ce303_volt_mil_a_reg;
	uint16_t ce303_volt_mil_b_reg;
	uint16_t ce303_volt_mil_c_reg;

	uint16_t ce303_power_a_reg;
	uint16_t ce303_power_b_reg;
	uint16_t ce303_power_c_reg;
	uint16_t ce303_power_mil_a_reg;
	uint16_t ce303_power_mil_b_reg;
	uint16_t ce303_power_mil_c_reg;

	uint16_t lighting_status_reg;
	uint16_t lighting_alarm_reg;
	uint16_t month_lighting_off_reg;
	uint16_t day_lighting_off_reg;
	uint16_t hour_lighting_off_reg;
	uint16_t minute_lighting_off_reg;
	uint16_t month_lighting_on_reg;
	uint16_t day_lighting_on_reg;
	uint16_t hour_lighting_on_reg;
	uint16_t minute_lighting_on_reg;
	uint16_t current_phase_a_reg;
	uint16_t current_phase_b_reg;
	uint16_t current_phase_c_reg;
	uint16_t current_voltage_a_reg;
	uint16_t current_voltage_b_reg;
	uint16_t current_voltage_c_reg;
	uint16_t ce303_total_power_h_reg;
	uint16_t ce303_total_power_l_reg;
	uint16_t ce303_total_power_m_reg;
	uint16_t ce303_tarif1_power_h_reg;
	uint16_t ce303_tarif1_power_l_reg;
	uint16_t ce303_tarif1_power_mil_reg;
	uint16_t ce303_tarif2_power_h_reg;
	uint16_t ce303_tarif2_power_l_reg;
	uint16_t ce303_tarif2_power_mil_reg;
	uint16_t ce303_tarif3_power_h_reg;
	uint16_t ce303_tarif3_power_l_reg;
	uint16_t ce303_tarif3_power_mil_reg;
	uint16_t ce303_tarif4_power_h_reg;
	uint16_t ce303_tarif4_power_l_reg;
	uint16_t ce303_tarif4_power_mil_reg;
	uint16_t ce303_tarif5_power_h_reg;
	uint16_t ce303_tarif5_power_l_reg;
	uint16_t ce303_tarif5_power_mil_reg;
	uint16_t signal_level_reg;

	uint16_t advanced_loop_reg;
	uint16_t additional_input_reg1;
	uint16_t additional_input_reg2;
	uint16_t iccid_number_reg1;
	uint16_t iccid_number_reg2;
	uint16_t iccid_number_reg3;
	uint16_t iccid_number_reg4;
	uint16_t iccid_number_reg5;
	uint16_t iccid_number_reg6;
	uint16_t iccid_number_reg7;
	uint16_t iccid_number_reg8;

} status_register_struct;
//------------------------------------------------------------------

//----структура переменной управляющих регистров--------------------
typedef struct
{
	uint16_t security_control_reg;
	uint16_t control_loop_reg;
	uint16_t filter_time_loop_reg;
	uint16_t quantity_false_loop_reg;
	uint16_t time_false_loop_reg;
	uint16_t alarm_loop_clear_reg;
	uint16_t false_loop_clear_reg;
	uint16_t security_time_max_reg;
	uint16_t time_update_reg;
	uint16_t time_year_reg;
	uint16_t time_month_reg;
	uint16_t time_day_reg;
	uint16_t time_hour_reg;
	uint16_t time_minute_reg;
	uint16_t time_seconds_reg;
	uint16_t time_weekday_reg;
	uint16_t modbus_idle_time_max_reg;
	uint16_t time_connection_test_reg;
	uint16_t event_read_reg;
	uint16_t event_address_high_reg;
	uint16_t event_address_low_reg;
	uint16_t modem_ring_try_load_reg;
	uint16_t modem_ring_pause_load_reg;
	uint16_t modem_ring_pause2_load_reg;
	uint16_t ring_minute_time_reg;
	uint16_t ring_hour_time_reg;

	uint16_t id_high_reg;
	uint16_t id_low_reg;
	uint16_t reset_control_reg;
	uint16_t meter_polling_reg;
	uint16_t ip1_reg;
	uint16_t ip2_reg;
	uint16_t ip3_reg;
	uint16_t ip4_reg;
	uint16_t port_high_reg;
	uint16_t port_low_reg;
	uint16_t meter_id_high_reg;
	uint16_t meter_id_low_reg;
	uint16_t gprs_call_reg;

	uint16_t mute_reg; // переменная управления отключением звука при тревоге открытия двери

	uint16_t light_control_reg; // переменная управления освещением
	uint16_t lighting_alarm_reset_reg;
	uint16_t current_measurement_accuracy_reg;
	uint16_t max_current_phase_a;
	uint16_t max_current_phase_b;
	uint16_t max_current_phase_c;
	uint16_t lighting_switching_reg;
	uint16_t alarm_switching_reg;
	uint16_t arming_timeleft_reg;


} control_register_struct;
//------------------------------------------------------------------

//----структура переменной регистров загрузчика---------------------

typedef struct
{
	uint16_t bootloader_version_reg;
	uint16_t start_address_firmware_high_reg;
	uint16_t start_address_firmware_2_reg;
	uint16_t start_address_firmware_3_reg;
	uint16_t start_address_firmware_low_reg;
	uint16_t end_address_firmware_high_reg;
	uint16_t end_address_firmware_low_reg;
	uint16_t crc_firmware_high_reg;
	uint16_t crc_firmware_low_reg;
	uint16_t jump_vector_high_reg;
	uint16_t jump_vector_2_reg;
	uint16_t jump_vector_3_reg;
	uint16_t jump_vector_low_reg;
	uint16_t firmware_correctness_reg;
	uint16_t working_mode_reg;
	uint16_t ready_download_reg;
	uint16_t download_timeout_reg;
	uint16_t jump_attempt_reg;
	uint16_t max_jump_attempt_reg;
	uint16_t end_address_firmware_2_reg;
	uint16_t end_address_firmware_3_reg;
	uint16_t address_to_write_2_reg;
	uint16_t address_to_write_3_reg;

	uint16_t clear_page_number_reg;
	uint16_t clear_page_on_reg;
	uint16_t write_array_reg;
	uint16_t read_array_reg;
	uint16_t address_to_write_high_reg;
	uint16_t address_to_write_low_reg;
	uint16_t byte_quantity_reg;
	uint16_t packet_crc_high_reg;
	uint16_t packet_crc_low_reg;
	uint16_t packet_data_0_reg;
	uint16_t packet_data_1_reg;
	uint16_t packet_data_2_reg;
	uint16_t packet_data_3_reg;
	uint16_t packet_data_4_reg;


} bootloader_register_struct;
//------------------------------------------------------------------

//----структура переменной регистров учетных записей I-button-------

typedef struct
{
	uint16_t ibutton1_byte_0_reg;
	uint16_t ibutton1_byte_1_reg;
	uint16_t ibutton1_byte_2_reg;
	uint16_t ibutton1_byte_3_reg;
	uint16_t ibutton1_byte_4_reg;
	uint16_t ibutton1_byte_5_reg;
	uint16_t ibutton1_byte_6_reg;
	uint16_t ibutton1_byte_7_reg;

	uint16_t ibutton2_byte_0_reg;
	uint16_t ibutton2_byte_1_reg;
	uint16_t ibutton2_byte_2_reg;
	uint16_t ibutton2_byte_3_reg;
	uint16_t ibutton2_byte_4_reg;
	uint16_t ibutton2_byte_5_reg;
	uint16_t ibutton2_byte_6_reg;
	uint16_t ibutton2_byte_7_reg;

	uint16_t ibutton3_byte_0_reg;
	uint16_t ibutton3_byte_1_reg;
	uint16_t ibutton3_byte_2_reg;
	uint16_t ibutton3_byte_3_reg;
	uint16_t ibutton3_byte_4_reg;
	uint16_t ibutton3_byte_5_reg;
	uint16_t ibutton3_byte_6_reg;
	uint16_t ibutton3_byte_7_reg;

	uint16_t ibutton4_byte_0_reg;
	uint16_t ibutton4_byte_1_reg;
	uint16_t ibutton4_byte_2_reg;
	uint16_t ibutton4_byte_3_reg;
	uint16_t ibutton4_byte_4_reg;
	uint16_t ibutton4_byte_5_reg;
	uint16_t ibutton4_byte_6_reg;
	uint16_t ibutton4_byte_7_reg;

	uint16_t ibutton5_byte_0_reg;
	uint16_t ibutton5_byte_1_reg;
	uint16_t ibutton5_byte_2_reg;
	uint16_t ibutton5_byte_3_reg;
	uint16_t ibutton5_byte_4_reg;
	uint16_t ibutton5_byte_5_reg;
	uint16_t ibutton5_byte_6_reg;
	uint16_t ibutton5_byte_7_reg;

	uint16_t ibutton6_byte_0_reg;
	uint16_t ibutton6_byte_1_reg;
	uint16_t ibutton6_byte_2_reg;
	uint16_t ibutton6_byte_3_reg;
	uint16_t ibutton6_byte_4_reg;
	uint16_t ibutton6_byte_5_reg;
	uint16_t ibutton6_byte_6_reg;
	uint16_t ibutton6_byte_7_reg;

	uint16_t ibutton7_byte_0_reg;
	uint16_t ibutton7_byte_1_reg;
	uint16_t ibutton7_byte_2_reg;
	uint16_t ibutton7_byte_3_reg;
	uint16_t ibutton7_byte_4_reg;
	uint16_t ibutton7_byte_5_reg;
	uint16_t ibutton7_byte_6_reg;
	uint16_t ibutton7_byte_7_reg;

	uint16_t ibutton8_byte_0_reg;
	uint16_t ibutton8_byte_1_reg;
	uint16_t ibutton8_byte_2_reg;
	uint16_t ibutton8_byte_3_reg;
	uint16_t ibutton8_byte_4_reg;
	uint16_t ibutton8_byte_5_reg;
	uint16_t ibutton8_byte_6_reg;
	uint16_t ibutton8_byte_7_reg;

	uint16_t ibutton9_byte_0_reg;
	uint16_t ibutton9_byte_1_reg;
	uint16_t ibutton9_byte_2_reg;
	uint16_t ibutton9_byte_3_reg;
	uint16_t ibutton9_byte_4_reg;
	uint16_t ibutton9_byte_5_reg;
	uint16_t ibutton9_byte_6_reg;
	uint16_t ibutton9_byte_7_reg;

	uint16_t ibutton10_byte_0_reg;
	uint16_t ibutton10_byte_1_reg;
	uint16_t ibutton10_byte_2_reg;
	uint16_t ibutton10_byte_3_reg;
	uint16_t ibutton10_byte_4_reg;
	uint16_t ibutton10_byte_5_reg;
	uint16_t ibutton10_byte_6_reg;
	uint16_t ibutton10_byte_7_reg;

	uint16_t ibutton11_byte_0_reg;
	uint16_t ibutton11_byte_1_reg;
	uint16_t ibutton11_byte_2_reg;
	uint16_t ibutton11_byte_3_reg;
	uint16_t ibutton11_byte_4_reg;
	uint16_t ibutton11_byte_5_reg;
	uint16_t ibutton11_byte_6_reg;
	uint16_t ibutton11_byte_7_reg;

	uint16_t ibutton12_byte_0_reg;
	uint16_t ibutton12_byte_1_reg;
	uint16_t ibutton12_byte_2_reg;
	uint16_t ibutton12_byte_3_reg;
	uint16_t ibutton12_byte_4_reg;
	uint16_t ibutton12_byte_5_reg;
	uint16_t ibutton12_byte_6_reg;
	uint16_t ibutton12_byte_7_reg;

	uint16_t ibutton13_byte_0_reg;
	uint16_t ibutton13_byte_1_reg;
	uint16_t ibutton13_byte_2_reg;
	uint16_t ibutton13_byte_3_reg;
	uint16_t ibutton13_byte_4_reg;
	uint16_t ibutton13_byte_5_reg;
	uint16_t ibutton13_byte_6_reg;
	uint16_t ibutton13_byte_7_reg;

	uint16_t ibutton14_byte_0_reg;
	uint16_t ibutton14_byte_1_reg;
	uint16_t ibutton14_byte_2_reg;
	uint16_t ibutton14_byte_3_reg;
	uint16_t ibutton14_byte_4_reg;
	uint16_t ibutton14_byte_5_reg;
	uint16_t ibutton14_byte_6_reg;
	uint16_t ibutton14_byte_7_reg;

	uint16_t ibutton15_byte_0_reg;
	uint16_t ibutton15_byte_1_reg;
	uint16_t ibutton15_byte_2_reg;
	uint16_t ibutton15_byte_3_reg;
	uint16_t ibutton15_byte_4_reg;
	uint16_t ibutton15_byte_5_reg;
	uint16_t ibutton15_byte_6_reg;
	uint16_t ibutton15_byte_7_reg;

	uint16_t ibutton16_byte_0_reg;
	uint16_t ibutton16_byte_1_reg;
	uint16_t ibutton16_byte_2_reg;
	uint16_t ibutton16_byte_3_reg;
	uint16_t ibutton16_byte_4_reg;
	uint16_t ibutton16_byte_5_reg;
	uint16_t ibutton16_byte_6_reg;
	uint16_t ibutton16_byte_7_reg;

	uint16_t ibutton17_byte_0_reg;
	uint16_t ibutton17_byte_1_reg;
	uint16_t ibutton17_byte_2_reg;
	uint16_t ibutton17_byte_3_reg;
	uint16_t ibutton17_byte_4_reg;
	uint16_t ibutton17_byte_5_reg;
	uint16_t ibutton17_byte_6_reg;
	uint16_t ibutton17_byte_7_reg;

	uint16_t ibutton18_byte_0_reg;
	uint16_t ibutton18_byte_1_reg;
	uint16_t ibutton18_byte_2_reg;
	uint16_t ibutton18_byte_3_reg;
	uint16_t ibutton18_byte_4_reg;
	uint16_t ibutton18_byte_5_reg;
	uint16_t ibutton18_byte_6_reg;
	uint16_t ibutton18_byte_7_reg;

	uint16_t ibutton19_byte_0_reg;
	uint16_t ibutton19_byte_1_reg;
	uint16_t ibutton19_byte_2_reg;
	uint16_t ibutton19_byte_3_reg;
	uint16_t ibutton19_byte_4_reg;
	uint16_t ibutton19_byte_5_reg;
	uint16_t ibutton19_byte_6_reg;
	uint16_t ibutton19_byte_7_reg;

	uint16_t ibutton20_byte_0_reg;
	uint16_t ibutton20_byte_1_reg;
	uint16_t ibutton20_byte_2_reg;
	uint16_t ibutton20_byte_3_reg;
	uint16_t ibutton20_byte_4_reg;
	uint16_t ibutton20_byte_5_reg;
	uint16_t ibutton20_byte_6_reg;
	uint16_t ibutton20_byte_7_reg;

	uint16_t ibutton21_byte_0_reg;
	uint16_t ibutton21_byte_1_reg;
	uint16_t ibutton21_byte_2_reg;
	uint16_t ibutton21_byte_3_reg;
	uint16_t ibutton21_byte_4_reg;
	uint16_t ibutton21_byte_5_reg;
	uint16_t ibutton21_byte_6_reg;
	uint16_t ibutton21_byte_7_reg;

	uint16_t ibutton22_byte_0_reg;
	uint16_t ibutton22_byte_1_reg;
	uint16_t ibutton22_byte_2_reg;
	uint16_t ibutton22_byte_3_reg;
	uint16_t ibutton22_byte_4_reg;
	uint16_t ibutton22_byte_5_reg;
	uint16_t ibutton22_byte_6_reg;
	uint16_t ibutton22_byte_7_reg;

	uint16_t ibutton23_byte_0_reg;
	uint16_t ibutton23_byte_1_reg;
	uint16_t ibutton23_byte_2_reg;
	uint16_t ibutton23_byte_3_reg;
	uint16_t ibutton23_byte_4_reg;
	uint16_t ibutton23_byte_5_reg;
	uint16_t ibutton23_byte_6_reg;
	uint16_t ibutton23_byte_7_reg;

	uint16_t ibutton24_byte_0_reg;
	uint16_t ibutton24_byte_1_reg;
	uint16_t ibutton24_byte_2_reg;
	uint16_t ibutton24_byte_3_reg;
	uint16_t ibutton24_byte_4_reg;
	uint16_t ibutton24_byte_5_reg;
	uint16_t ibutton24_byte_6_reg;
	uint16_t ibutton24_byte_7_reg;

	uint16_t ibutton25_byte_0_reg;
	uint16_t ibutton25_byte_1_reg;
	uint16_t ibutton25_byte_2_reg;
	uint16_t ibutton25_byte_3_reg;
	uint16_t ibutton25_byte_4_reg;
	uint16_t ibutton25_byte_5_reg;
	uint16_t ibutton25_byte_6_reg;
	uint16_t ibutton25_byte_7_reg;

	uint16_t ibutton26_byte_0_reg;
	uint16_t ibutton26_byte_1_reg;
	uint16_t ibutton26_byte_2_reg;
	uint16_t ibutton26_byte_3_reg;
	uint16_t ibutton26_byte_4_reg;
	uint16_t ibutton26_byte_5_reg;
	uint16_t ibutton26_byte_6_reg;
	uint16_t ibutton26_byte_7_reg;

	uint16_t ibutton27_byte_0_reg;
	uint16_t ibutton27_byte_1_reg;
	uint16_t ibutton27_byte_2_reg;
	uint16_t ibutton27_byte_3_reg;
	uint16_t ibutton27_byte_4_reg;
	uint16_t ibutton27_byte_5_reg;
	uint16_t ibutton27_byte_6_reg;
	uint16_t ibutton27_byte_7_reg;

	uint16_t ibutton28_byte_0_reg;
	uint16_t ibutton28_byte_1_reg;
	uint16_t ibutton28_byte_2_reg;
	uint16_t ibutton28_byte_3_reg;
	uint16_t ibutton28_byte_4_reg;
	uint16_t ibutton28_byte_5_reg;
	uint16_t ibutton28_byte_6_reg;
	uint16_t ibutton28_byte_7_reg;

	uint16_t ibutton29_byte_0_reg;
	uint16_t ibutton29_byte_1_reg;
	uint16_t ibutton29_byte_2_reg;
	uint16_t ibutton29_byte_3_reg;
	uint16_t ibutton29_byte_4_reg;
	uint16_t ibutton29_byte_5_reg;
	uint16_t ibutton29_byte_6_reg;
	uint16_t ibutton29_byte_7_reg;

	uint16_t ibutton30_byte_0_reg;
	uint16_t ibutton30_byte_1_reg;
	uint16_t ibutton30_byte_2_reg;
	uint16_t ibutton30_byte_3_reg;
	uint16_t ibutton30_byte_4_reg;
	uint16_t ibutton30_byte_5_reg;
	uint16_t ibutton30_byte_6_reg;
	uint16_t ibutton30_byte_7_reg;

	uint16_t ibutton31_byte_0_reg;
	uint16_t ibutton31_byte_1_reg;
	uint16_t ibutton31_byte_2_reg;
	uint16_t ibutton31_byte_3_reg;
	uint16_t ibutton31_byte_4_reg;
	uint16_t ibutton31_byte_5_reg;
	uint16_t ibutton31_byte_6_reg;
	uint16_t ibutton31_byte_7_reg;

	uint16_t ibutton32_byte_0_reg;
	uint16_t ibutton32_byte_1_reg;
	uint16_t ibutton32_byte_2_reg;
	uint16_t ibutton32_byte_3_reg;
	uint16_t ibutton32_byte_4_reg;
	uint16_t ibutton32_byte_5_reg;
	uint16_t ibutton32_byte_6_reg;
	uint16_t ibutton32_byte_7_reg;

	uint16_t ibutton33_byte_0_reg;
	uint16_t ibutton33_byte_1_reg;
	uint16_t ibutton33_byte_2_reg;
	uint16_t ibutton33_byte_3_reg;
	uint16_t ibutton33_byte_4_reg;
	uint16_t ibutton33_byte_5_reg;
	uint16_t ibutton33_byte_6_reg;
	uint16_t ibutton33_byte_7_reg;

	uint16_t ibutton34_byte_0_reg;
	uint16_t ibutton34_byte_1_reg;
	uint16_t ibutton34_byte_2_reg;
	uint16_t ibutton34_byte_3_reg;
	uint16_t ibutton34_byte_4_reg;
	uint16_t ibutton34_byte_5_reg;
	uint16_t ibutton34_byte_6_reg;
	uint16_t ibutton34_byte_7_reg;

	uint16_t ibutton35_byte_0_reg;
	uint16_t ibutton35_byte_1_reg;
	uint16_t ibutton35_byte_2_reg;
	uint16_t ibutton35_byte_3_reg;
	uint16_t ibutton35_byte_4_reg;
	uint16_t ibutton35_byte_5_reg;
	uint16_t ibutton35_byte_6_reg;
	uint16_t ibutton35_byte_7_reg;

	uint16_t ibutton36_byte_0_reg;
	uint16_t ibutton36_byte_1_reg;
	uint16_t ibutton36_byte_2_reg;
	uint16_t ibutton36_byte_3_reg;
	uint16_t ibutton36_byte_4_reg;
	uint16_t ibutton36_byte_5_reg;
	uint16_t ibutton36_byte_6_reg;
	uint16_t ibutton36_byte_7_reg;

	uint16_t ibutton37_byte_0_reg;
	uint16_t ibutton37_byte_1_reg;
	uint16_t ibutton37_byte_2_reg;
	uint16_t ibutton37_byte_3_reg;
	uint16_t ibutton37_byte_4_reg;
	uint16_t ibutton37_byte_5_reg;
	uint16_t ibutton37_byte_6_reg;
	uint16_t ibutton37_byte_7_reg;

	uint16_t ibutton38_byte_0_reg;
	uint16_t ibutton38_byte_1_reg;
	uint16_t ibutton38_byte_2_reg;
	uint16_t ibutton38_byte_3_reg;
	uint16_t ibutton38_byte_4_reg;
	uint16_t ibutton38_byte_5_reg;
	uint16_t ibutton38_byte_6_reg;
	uint16_t ibutton38_byte_7_reg;

	uint16_t ibutton39_byte_0_reg;
	uint16_t ibutton39_byte_1_reg;
	uint16_t ibutton39_byte_2_reg;
	uint16_t ibutton39_byte_3_reg;
	uint16_t ibutton39_byte_4_reg;
	uint16_t ibutton39_byte_5_reg;
	uint16_t ibutton39_byte_6_reg;
	uint16_t ibutton39_byte_7_reg;

	uint16_t ibutton40_byte_0_reg;
	uint16_t ibutton40_byte_1_reg;
	uint16_t ibutton40_byte_2_reg;
	uint16_t ibutton40_byte_3_reg;
	uint16_t ibutton40_byte_4_reg;
	uint16_t ibutton40_byte_5_reg;
	uint16_t ibutton40_byte_6_reg;
	uint16_t ibutton40_byte_7_reg;

	uint16_t ibutton41_byte_0_reg;
	uint16_t ibutton41_byte_1_reg;
	uint16_t ibutton41_byte_2_reg;
	uint16_t ibutton41_byte_3_reg;
	uint16_t ibutton41_byte_4_reg;
	uint16_t ibutton41_byte_5_reg;
	uint16_t ibutton41_byte_6_reg;
	uint16_t ibutton41_byte_7_reg;

	uint16_t ibutton42_byte_0_reg;
	uint16_t ibutton42_byte_1_reg;
	uint16_t ibutton42_byte_2_reg;
	uint16_t ibutton42_byte_3_reg;
	uint16_t ibutton42_byte_4_reg;
	uint16_t ibutton42_byte_5_reg;
	uint16_t ibutton42_byte_6_reg;
	uint16_t ibutton42_byte_7_reg;

	uint16_t ibutton43_byte_0_reg;
	uint16_t ibutton43_byte_1_reg;
	uint16_t ibutton43_byte_2_reg;
	uint16_t ibutton43_byte_3_reg;
	uint16_t ibutton43_byte_4_reg;
	uint16_t ibutton43_byte_5_reg;
	uint16_t ibutton43_byte_6_reg;
	uint16_t ibutton43_byte_7_reg;

	uint16_t ibutton44_byte_0_reg;
	uint16_t ibutton44_byte_1_reg;
	uint16_t ibutton44_byte_2_reg;
	uint16_t ibutton44_byte_3_reg;
	uint16_t ibutton44_byte_4_reg;
	uint16_t ibutton44_byte_5_reg;
	uint16_t ibutton44_byte_6_reg;
	uint16_t ibutton44_byte_7_reg;

	uint16_t ibutton45_byte_0_reg;
	uint16_t ibutton45_byte_1_reg;
	uint16_t ibutton45_byte_2_reg;
	uint16_t ibutton45_byte_3_reg;
	uint16_t ibutton45_byte_4_reg;
	uint16_t ibutton45_byte_5_reg;
	uint16_t ibutton45_byte_6_reg;
	uint16_t ibutton45_byte_7_reg;

	uint16_t ibutton46_byte_0_reg;
	uint16_t ibutton46_byte_1_reg;
	uint16_t ibutton46_byte_2_reg;
	uint16_t ibutton46_byte_3_reg;
	uint16_t ibutton46_byte_4_reg;
	uint16_t ibutton46_byte_5_reg;
	uint16_t ibutton46_byte_6_reg;
	uint16_t ibutton46_byte_7_reg;

	uint16_t ibutton47_byte_0_reg;
	uint16_t ibutton47_byte_1_reg;
	uint16_t ibutton47_byte_2_reg;
	uint16_t ibutton47_byte_3_reg;
	uint16_t ibutton47_byte_4_reg;
	uint16_t ibutton47_byte_5_reg;
	uint16_t ibutton47_byte_6_reg;
	uint16_t ibutton47_byte_7_reg;

	uint16_t ibutton48_byte_0_reg;
	uint16_t ibutton48_byte_1_reg;
	uint16_t ibutton48_byte_2_reg;
	uint16_t ibutton48_byte_3_reg;
	uint16_t ibutton48_byte_4_reg;
	uint16_t ibutton48_byte_5_reg;
	uint16_t ibutton48_byte_6_reg;
	uint16_t ibutton48_byte_7_reg;

	uint16_t ibutton49_byte_0_reg;
	uint16_t ibutton49_byte_1_reg;
	uint16_t ibutton49_byte_2_reg;
	uint16_t ibutton49_byte_3_reg;
	uint16_t ibutton49_byte_4_reg;
	uint16_t ibutton49_byte_5_reg;
	uint16_t ibutton49_byte_6_reg;
	uint16_t ibutton49_byte_7_reg;

	uint16_t ibutton50_byte_0_reg;
	uint16_t ibutton50_byte_1_reg;
	uint16_t ibutton50_byte_2_reg;
	uint16_t ibutton50_byte_3_reg;
	uint16_t ibutton50_byte_4_reg;
	uint16_t ibutton50_byte_5_reg;
	uint16_t ibutton50_byte_6_reg;
	uint16_t ibutton50_byte_7_reg;

	uint16_t ibutton51_byte_0_reg;
	uint16_t ibutton51_byte_1_reg;
	uint16_t ibutton51_byte_2_reg;
	uint16_t ibutton51_byte_3_reg;
	uint16_t ibutton51_byte_4_reg;
	uint16_t ibutton51_byte_5_reg;
	uint16_t ibutton51_byte_6_reg;
	uint16_t ibutton51_byte_7_reg;

	uint16_t ibutton52_byte_0_reg;
	uint16_t ibutton52_byte_1_reg;
	uint16_t ibutton52_byte_2_reg;
	uint16_t ibutton52_byte_3_reg;
	uint16_t ibutton52_byte_4_reg;
	uint16_t ibutton52_byte_5_reg;
	uint16_t ibutton52_byte_6_reg;
	uint16_t ibutton52_byte_7_reg;

	uint16_t ibutton53_byte_0_reg;
	uint16_t ibutton53_byte_1_reg;
	uint16_t ibutton53_byte_2_reg;
	uint16_t ibutton53_byte_3_reg;
	uint16_t ibutton53_byte_4_reg;
	uint16_t ibutton53_byte_5_reg;
	uint16_t ibutton53_byte_6_reg;
	uint16_t ibutton53_byte_7_reg;

	uint16_t ibutton54_byte_0_reg;
	uint16_t ibutton54_byte_1_reg;
	uint16_t ibutton54_byte_2_reg;
	uint16_t ibutton54_byte_3_reg;
	uint16_t ibutton54_byte_4_reg;
	uint16_t ibutton54_byte_5_reg;
	uint16_t ibutton54_byte_6_reg;
	uint16_t ibutton54_byte_7_reg;

	uint16_t ibutton55_byte_0_reg;
	uint16_t ibutton55_byte_1_reg;
	uint16_t ibutton55_byte_2_reg;
	uint16_t ibutton55_byte_3_reg;
	uint16_t ibutton55_byte_4_reg;
	uint16_t ibutton55_byte_5_reg;
	uint16_t ibutton55_byte_6_reg;
	uint16_t ibutton55_byte_7_reg;

	uint16_t ibutton56_byte_0_reg;
	uint16_t ibutton56_byte_1_reg;
	uint16_t ibutton56_byte_2_reg;
	uint16_t ibutton56_byte_3_reg;
	uint16_t ibutton56_byte_4_reg;
	uint16_t ibutton56_byte_5_reg;
	uint16_t ibutton56_byte_6_reg;
	uint16_t ibutton56_byte_7_reg;

	uint16_t ibutton57_byte_0_reg;
	uint16_t ibutton57_byte_1_reg;
	uint16_t ibutton57_byte_2_reg;
	uint16_t ibutton57_byte_3_reg;
	uint16_t ibutton57_byte_4_reg;
	uint16_t ibutton57_byte_5_reg;
	uint16_t ibutton57_byte_6_reg;
	uint16_t ibutton57_byte_7_reg;

	uint16_t ibutton58_byte_0_reg;
	uint16_t ibutton58_byte_1_reg;
	uint16_t ibutton58_byte_2_reg;
	uint16_t ibutton58_byte_3_reg;
	uint16_t ibutton58_byte_4_reg;
	uint16_t ibutton58_byte_5_reg;
	uint16_t ibutton58_byte_6_reg;
	uint16_t ibutton58_byte_7_reg;

	uint16_t ibutton59_byte_0_reg;
	uint16_t ibutton59_byte_1_reg;
	uint16_t ibutton59_byte_2_reg;
	uint16_t ibutton59_byte_3_reg;
	uint16_t ibutton59_byte_4_reg;
	uint16_t ibutton59_byte_5_reg;
	uint16_t ibutton59_byte_6_reg;
	uint16_t ibutton59_byte_7_reg;

	uint16_t ibutton60_byte_0_reg;
	uint16_t ibutton60_byte_1_reg;
	uint16_t ibutton60_byte_2_reg;
	uint16_t ibutton60_byte_3_reg;
	uint16_t ibutton60_byte_4_reg;
	uint16_t ibutton60_byte_5_reg;
	uint16_t ibutton60_byte_6_reg;
	uint16_t ibutton60_byte_7_reg;

	uint16_t ibutton61_byte_0_reg;
	uint16_t ibutton61_byte_1_reg;
	uint16_t ibutton61_byte_2_reg;
	uint16_t ibutton61_byte_3_reg;
	uint16_t ibutton61_byte_4_reg;
	uint16_t ibutton61_byte_5_reg;
	uint16_t ibutton61_byte_6_reg;
	uint16_t ibutton61_byte_7_reg;

	uint16_t ibutton62_byte_0_reg;
	uint16_t ibutton62_byte_1_reg;
	uint16_t ibutton62_byte_2_reg;
	uint16_t ibutton62_byte_3_reg;
	uint16_t ibutton62_byte_4_reg;
	uint16_t ibutton62_byte_5_reg;
	uint16_t ibutton62_byte_6_reg;
	uint16_t ibutton62_byte_7_reg;

	uint16_t ibutton63_byte_0_reg;
	uint16_t ibutton63_byte_1_reg;
	uint16_t ibutton63_byte_2_reg;
	uint16_t ibutton63_byte_3_reg;
	uint16_t ibutton63_byte_4_reg;
	uint16_t ibutton63_byte_5_reg;
	uint16_t ibutton63_byte_6_reg;
	uint16_t ibutton63_byte_7_reg;

	uint16_t ibutton64_byte_0_reg;
	uint16_t ibutton64_byte_1_reg;
	uint16_t ibutton64_byte_2_reg;
	uint16_t ibutton64_byte_3_reg;
	uint16_t ibutton64_byte_4_reg;
	uint16_t ibutton64_byte_5_reg;
	uint16_t ibutton64_byte_6_reg;
	uint16_t ibutton64_byte_7_reg;

	uint16_t ibutton65_byte_0_reg;
	uint16_t ibutton65_byte_1_reg;
	uint16_t ibutton65_byte_2_reg;
	uint16_t ibutton65_byte_3_reg;
	uint16_t ibutton65_byte_4_reg;
	uint16_t ibutton65_byte_5_reg;
	uint16_t ibutton65_byte_6_reg;
	uint16_t ibutton65_byte_7_reg;

	uint16_t ibutton66_byte_0_reg;
	uint16_t ibutton66_byte_1_reg;
	uint16_t ibutton66_byte_2_reg;
	uint16_t ibutton66_byte_3_reg;
	uint16_t ibutton66_byte_4_reg;
	uint16_t ibutton66_byte_5_reg;
	uint16_t ibutton66_byte_6_reg;
	uint16_t ibutton66_byte_7_reg;

	uint16_t ibutton67_byte_0_reg;
	uint16_t ibutton67_byte_1_reg;
	uint16_t ibutton67_byte_2_reg;
	uint16_t ibutton67_byte_3_reg;
	uint16_t ibutton67_byte_4_reg;
	uint16_t ibutton67_byte_5_reg;
	uint16_t ibutton67_byte_6_reg;
	uint16_t ibutton67_byte_7_reg;

	uint16_t ibutton68_byte_0_reg;
	uint16_t ibutton68_byte_1_reg;
	uint16_t ibutton68_byte_2_reg;
	uint16_t ibutton68_byte_3_reg;
	uint16_t ibutton68_byte_4_reg;
	uint16_t ibutton68_byte_5_reg;
	uint16_t ibutton68_byte_6_reg;
	uint16_t ibutton68_byte_7_reg;

	uint16_t ibutton69_byte_0_reg;
	uint16_t ibutton69_byte_1_reg;
	uint16_t ibutton69_byte_2_reg;
	uint16_t ibutton69_byte_3_reg;
	uint16_t ibutton69_byte_4_reg;
	uint16_t ibutton69_byte_5_reg;
	uint16_t ibutton69_byte_6_reg;
	uint16_t ibutton69_byte_7_reg;

	uint16_t ibutton70_byte_0_reg;
	uint16_t ibutton70_byte_1_reg;
	uint16_t ibutton70_byte_2_reg;
	uint16_t ibutton70_byte_3_reg;
	uint16_t ibutton70_byte_4_reg;
	uint16_t ibutton70_byte_5_reg;
	uint16_t ibutton70_byte_6_reg;
	uint16_t ibutton70_byte_7_reg;

	uint16_t ibutton71_byte_0_reg;
	uint16_t ibutton71_byte_1_reg;
	uint16_t ibutton71_byte_2_reg;
	uint16_t ibutton71_byte_3_reg;
	uint16_t ibutton71_byte_4_reg;
	uint16_t ibutton71_byte_5_reg;
	uint16_t ibutton71_byte_6_reg;
	uint16_t ibutton71_byte_7_reg;

	uint16_t ibutton72_byte_0_reg;
	uint16_t ibutton72_byte_1_reg;
	uint16_t ibutton72_byte_2_reg;
	uint16_t ibutton72_byte_3_reg;
	uint16_t ibutton72_byte_4_reg;
	uint16_t ibutton72_byte_5_reg;
	uint16_t ibutton72_byte_6_reg;
	uint16_t ibutton72_byte_7_reg;

	uint16_t ibutton73_byte_0_reg;
	uint16_t ibutton73_byte_1_reg;
	uint16_t ibutton73_byte_2_reg;
	uint16_t ibutton73_byte_3_reg;
	uint16_t ibutton73_byte_4_reg;
	uint16_t ibutton73_byte_5_reg;
	uint16_t ibutton73_byte_6_reg;
	uint16_t ibutton73_byte_7_reg;

	uint16_t ibutton74_byte_0_reg;
	uint16_t ibutton74_byte_1_reg;
	uint16_t ibutton74_byte_2_reg;
	uint16_t ibutton74_byte_3_reg;
	uint16_t ibutton74_byte_4_reg;
	uint16_t ibutton74_byte_5_reg;
	uint16_t ibutton74_byte_6_reg;
	uint16_t ibutton74_byte_7_reg;

	uint16_t ibutton75_byte_0_reg;
	uint16_t ibutton75_byte_1_reg;
	uint16_t ibutton75_byte_2_reg;
	uint16_t ibutton75_byte_3_reg;
	uint16_t ibutton75_byte_4_reg;
	uint16_t ibutton75_byte_5_reg;
	uint16_t ibutton75_byte_6_reg;
	uint16_t ibutton75_byte_7_reg;

	uint16_t ibutton76_byte_0_reg;
	uint16_t ibutton76_byte_1_reg;
	uint16_t ibutton76_byte_2_reg;
	uint16_t ibutton76_byte_3_reg;
	uint16_t ibutton76_byte_4_reg;
	uint16_t ibutton76_byte_5_reg;
	uint16_t ibutton76_byte_6_reg;
	uint16_t ibutton76_byte_7_reg;

	uint16_t ibutton77_byte_0_reg;
	uint16_t ibutton77_byte_1_reg;
	uint16_t ibutton77_byte_2_reg;
	uint16_t ibutton77_byte_3_reg;
	uint16_t ibutton77_byte_4_reg;
	uint16_t ibutton77_byte_5_reg;
	uint16_t ibutton77_byte_6_reg;
	uint16_t ibutton77_byte_7_reg;

	uint16_t ibutton78_byte_0_reg;
	uint16_t ibutton78_byte_1_reg;
	uint16_t ibutton78_byte_2_reg;
	uint16_t ibutton78_byte_3_reg;
	uint16_t ibutton78_byte_4_reg;
	uint16_t ibutton78_byte_5_reg;
	uint16_t ibutton78_byte_6_reg;
	uint16_t ibutton78_byte_7_reg;

	uint16_t ibutton79_byte_0_reg;
	uint16_t ibutton79_byte_1_reg;
	uint16_t ibutton79_byte_2_reg;
	uint16_t ibutton79_byte_3_reg;
	uint16_t ibutton79_byte_4_reg;
	uint16_t ibutton79_byte_5_reg;
	uint16_t ibutton79_byte_6_reg;
	uint16_t ibutton79_byte_7_reg;

	uint16_t ibutton80_byte_0_reg;
	uint16_t ibutton80_byte_1_reg;
	uint16_t ibutton80_byte_2_reg;
	uint16_t ibutton80_byte_3_reg;
	uint16_t ibutton80_byte_4_reg;
	uint16_t ibutton80_byte_5_reg;
	uint16_t ibutton80_byte_6_reg;
	uint16_t ibutton80_byte_7_reg;

	uint16_t ibutton81_byte_0_reg;
	uint16_t ibutton81_byte_1_reg;
	uint16_t ibutton81_byte_2_reg;
	uint16_t ibutton81_byte_3_reg;
	uint16_t ibutton81_byte_4_reg;
	uint16_t ibutton81_byte_5_reg;
	uint16_t ibutton81_byte_6_reg;
	uint16_t ibutton81_byte_7_reg;

	uint16_t ibutton82_byte_0_reg;
	uint16_t ibutton82_byte_1_reg;
	uint16_t ibutton82_byte_2_reg;
	uint16_t ibutton82_byte_3_reg;
	uint16_t ibutton82_byte_4_reg;
	uint16_t ibutton82_byte_5_reg;
	uint16_t ibutton82_byte_6_reg;
	uint16_t ibutton82_byte_7_reg;

	uint16_t ibutton83_byte_0_reg;
	uint16_t ibutton83_byte_1_reg;
	uint16_t ibutton83_byte_2_reg;
	uint16_t ibutton83_byte_3_reg;
	uint16_t ibutton83_byte_4_reg;
	uint16_t ibutton83_byte_5_reg;
	uint16_t ibutton83_byte_6_reg;
	uint16_t ibutton83_byte_7_reg;

	uint16_t ibutton84_byte_0_reg;
	uint16_t ibutton84_byte_1_reg;
	uint16_t ibutton84_byte_2_reg;
	uint16_t ibutton84_byte_3_reg;
	uint16_t ibutton84_byte_4_reg;
	uint16_t ibutton84_byte_5_reg;
	uint16_t ibutton84_byte_6_reg;
	uint16_t ibutton84_byte_7_reg;

	uint16_t ibutton85_byte_0_reg;
	uint16_t ibutton85_byte_1_reg;
	uint16_t ibutton85_byte_2_reg;
	uint16_t ibutton85_byte_3_reg;
	uint16_t ibutton85_byte_4_reg;
	uint16_t ibutton85_byte_5_reg;
	uint16_t ibutton85_byte_6_reg;
	uint16_t ibutton85_byte_7_reg;

	uint16_t ibutton86_byte_0_reg;
	uint16_t ibutton86_byte_1_reg;
	uint16_t ibutton86_byte_2_reg;
	uint16_t ibutton86_byte_3_reg;
	uint16_t ibutton86_byte_4_reg;
	uint16_t ibutton86_byte_5_reg;
	uint16_t ibutton86_byte_6_reg;
	uint16_t ibutton86_byte_7_reg;

	uint16_t ibutton87_byte_0_reg;
	uint16_t ibutton87_byte_1_reg;
	uint16_t ibutton87_byte_2_reg;
	uint16_t ibutton87_byte_3_reg;
	uint16_t ibutton87_byte_4_reg;
	uint16_t ibutton87_byte_5_reg;
	uint16_t ibutton87_byte_6_reg;
	uint16_t ibutton87_byte_7_reg;

	uint16_t ibutton88_byte_0_reg;
	uint16_t ibutton88_byte_1_reg;
	uint16_t ibutton88_byte_2_reg;
	uint16_t ibutton88_byte_3_reg;
	uint16_t ibutton88_byte_4_reg;
	uint16_t ibutton88_byte_5_reg;
	uint16_t ibutton88_byte_6_reg;
	uint16_t ibutton88_byte_7_reg;

	uint16_t ibutton89_byte_0_reg;
	uint16_t ibutton89_byte_1_reg;
	uint16_t ibutton89_byte_2_reg;
	uint16_t ibutton89_byte_3_reg;
	uint16_t ibutton89_byte_4_reg;
	uint16_t ibutton89_byte_5_reg;
	uint16_t ibutton89_byte_6_reg;
	uint16_t ibutton89_byte_7_reg;

	uint16_t ibutton90_byte_0_reg;
	uint16_t ibutton90_byte_1_reg;
	uint16_t ibutton90_byte_2_reg;
	uint16_t ibutton90_byte_3_reg;
	uint16_t ibutton90_byte_4_reg;
	uint16_t ibutton90_byte_5_reg;
	uint16_t ibutton90_byte_6_reg;
	uint16_t ibutton90_byte_7_reg;

	uint16_t ibutton91_byte_0_reg;
	uint16_t ibutton91_byte_1_reg;
	uint16_t ibutton91_byte_2_reg;
	uint16_t ibutton91_byte_3_reg;
	uint16_t ibutton91_byte_4_reg;
	uint16_t ibutton91_byte_5_reg;
	uint16_t ibutton91_byte_6_reg;
	uint16_t ibutton91_byte_7_reg;

	uint16_t ibutton92_byte_0_reg;
	uint16_t ibutton92_byte_1_reg;
	uint16_t ibutton92_byte_2_reg;
	uint16_t ibutton92_byte_3_reg;
	uint16_t ibutton92_byte_4_reg;
	uint16_t ibutton92_byte_5_reg;
	uint16_t ibutton92_byte_6_reg;
	uint16_t ibutton92_byte_7_reg;

	uint16_t ibutton93_byte_0_reg;
	uint16_t ibutton93_byte_1_reg;
	uint16_t ibutton93_byte_2_reg;
	uint16_t ibutton93_byte_3_reg;
	uint16_t ibutton93_byte_4_reg;
	uint16_t ibutton93_byte_5_reg;
	uint16_t ibutton93_byte_6_reg;
	uint16_t ibutton93_byte_7_reg;

	uint16_t ibutton94_byte_0_reg;
	uint16_t ibutton94_byte_1_reg;
	uint16_t ibutton94_byte_2_reg;
	uint16_t ibutton94_byte_3_reg;
	uint16_t ibutton94_byte_4_reg;
	uint16_t ibutton94_byte_5_reg;
	uint16_t ibutton94_byte_6_reg;
	uint16_t ibutton94_byte_7_reg;

	uint16_t ibutton95_byte_0_reg;
	uint16_t ibutton95_byte_1_reg;
	uint16_t ibutton95_byte_2_reg;
	uint16_t ibutton95_byte_3_reg;
	uint16_t ibutton95_byte_4_reg;
	uint16_t ibutton95_byte_5_reg;
	uint16_t ibutton95_byte_6_reg;
	uint16_t ibutton95_byte_7_reg;

	uint16_t ibutton96_byte_0_reg;
	uint16_t ibutton96_byte_1_reg;
	uint16_t ibutton96_byte_2_reg;
	uint16_t ibutton96_byte_3_reg;
	uint16_t ibutton96_byte_4_reg;
	uint16_t ibutton96_byte_5_reg;
	uint16_t ibutton96_byte_6_reg;
	uint16_t ibutton96_byte_7_reg;

	uint16_t ibutton97_byte_0_reg;
	uint16_t ibutton97_byte_1_reg;
	uint16_t ibutton97_byte_2_reg;
	uint16_t ibutton97_byte_3_reg;
	uint16_t ibutton97_byte_4_reg;
	uint16_t ibutton97_byte_5_reg;
	uint16_t ibutton97_byte_6_reg;
	uint16_t ibutton97_byte_7_reg;

	uint16_t ibutton98_byte_0_reg;
	uint16_t ibutton98_byte_1_reg;
	uint16_t ibutton98_byte_2_reg;
	uint16_t ibutton98_byte_3_reg;
	uint16_t ibutton98_byte_4_reg;
	uint16_t ibutton98_byte_5_reg;
	uint16_t ibutton98_byte_6_reg;
	uint16_t ibutton98_byte_7_reg;

	uint16_t ibutton99_byte_0_reg;
	uint16_t ibutton99_byte_1_reg;
	uint16_t ibutton99_byte_2_reg;
	uint16_t ibutton99_byte_3_reg;
	uint16_t ibutton99_byte_4_reg;
	uint16_t ibutton99_byte_5_reg;
	uint16_t ibutton99_byte_6_reg;
	uint16_t ibutton99_byte_7_reg;

	uint16_t ibutton100_byte_0_reg;
	uint16_t ibutton100_byte_1_reg;
	uint16_t ibutton100_byte_2_reg;
	uint16_t ibutton100_byte_3_reg;
	uint16_t ibutton100_byte_4_reg;
	uint16_t ibutton100_byte_5_reg;
	uint16_t ibutton100_byte_6_reg;
	uint16_t ibutton100_byte_7_reg;

	uint16_t ibutton101_byte_0_reg;
	uint16_t ibutton101_byte_1_reg;
	uint16_t ibutton101_byte_2_reg;
	uint16_t ibutton101_byte_3_reg;
	uint16_t ibutton101_byte_4_reg;
	uint16_t ibutton101_byte_5_reg;
	uint16_t ibutton101_byte_6_reg;
	uint16_t ibutton101_byte_7_reg;

	uint16_t ibutton102_byte_0_reg;
	uint16_t ibutton102_byte_1_reg;
	uint16_t ibutton102_byte_2_reg;
	uint16_t ibutton102_byte_3_reg;
	uint16_t ibutton102_byte_4_reg;
	uint16_t ibutton102_byte_5_reg;
	uint16_t ibutton102_byte_6_reg;
	uint16_t ibutton102_byte_7_reg;

	uint16_t ibutton103_byte_0_reg;
	uint16_t ibutton103_byte_1_reg;
	uint16_t ibutton103_byte_2_reg;
	uint16_t ibutton103_byte_3_reg;
	uint16_t ibutton103_byte_4_reg;
	uint16_t ibutton103_byte_5_reg;
	uint16_t ibutton103_byte_6_reg;
	uint16_t ibutton103_byte_7_reg;

	uint16_t ibutton104_byte_0_reg;
	uint16_t ibutton104_byte_1_reg;
	uint16_t ibutton104_byte_2_reg;
	uint16_t ibutton104_byte_3_reg;
	uint16_t ibutton104_byte_4_reg;
	uint16_t ibutton104_byte_5_reg;
	uint16_t ibutton104_byte_6_reg;
	uint16_t ibutton104_byte_7_reg;

	uint16_t ibutton105_byte_0_reg;
	uint16_t ibutton105_byte_1_reg;
	uint16_t ibutton105_byte_2_reg;
	uint16_t ibutton105_byte_3_reg;
	uint16_t ibutton105_byte_4_reg;
	uint16_t ibutton105_byte_5_reg;
	uint16_t ibutton105_byte_6_reg;
	uint16_t ibutton105_byte_7_reg;

	uint16_t ibutton106_byte_0_reg;
	uint16_t ibutton106_byte_1_reg;
	uint16_t ibutton106_byte_2_reg;
	uint16_t ibutton106_byte_3_reg;
	uint16_t ibutton106_byte_4_reg;
	uint16_t ibutton106_byte_5_reg;
	uint16_t ibutton106_byte_6_reg;
	uint16_t ibutton106_byte_7_reg;

	uint16_t ibutton107_byte_0_reg;
	uint16_t ibutton107_byte_1_reg;
	uint16_t ibutton107_byte_2_reg;
	uint16_t ibutton107_byte_3_reg;
	uint16_t ibutton107_byte_4_reg;
	uint16_t ibutton107_byte_5_reg;
	uint16_t ibutton107_byte_6_reg;
	uint16_t ibutton107_byte_7_reg;

	uint16_t ibutton108_byte_0_reg;
	uint16_t ibutton108_byte_1_reg;
	uint16_t ibutton108_byte_2_reg;
	uint16_t ibutton108_byte_3_reg;
	uint16_t ibutton108_byte_4_reg;
	uint16_t ibutton108_byte_5_reg;
	uint16_t ibutton108_byte_6_reg;
	uint16_t ibutton108_byte_7_reg;

	uint16_t ibutton109_byte_0_reg;
	uint16_t ibutton109_byte_1_reg;
	uint16_t ibutton109_byte_2_reg;
	uint16_t ibutton109_byte_3_reg;
	uint16_t ibutton109_byte_4_reg;
	uint16_t ibutton109_byte_5_reg;
	uint16_t ibutton109_byte_6_reg;
	uint16_t ibutton109_byte_7_reg;

	uint16_t ibutton110_byte_0_reg;
	uint16_t ibutton110_byte_1_reg;
	uint16_t ibutton110_byte_2_reg;
	uint16_t ibutton110_byte_3_reg;
	uint16_t ibutton110_byte_4_reg;
	uint16_t ibutton110_byte_5_reg;
	uint16_t ibutton110_byte_6_reg;
	uint16_t ibutton110_byte_7_reg;

	uint16_t ibutton111_byte_0_reg;
	uint16_t ibutton111_byte_1_reg;
	uint16_t ibutton111_byte_2_reg;
	uint16_t ibutton111_byte_3_reg;
	uint16_t ibutton111_byte_4_reg;
	uint16_t ibutton111_byte_5_reg;
	uint16_t ibutton111_byte_6_reg;
	uint16_t ibutton111_byte_7_reg;

	uint16_t ibutton112_byte_0_reg;
	uint16_t ibutton112_byte_1_reg;
	uint16_t ibutton112_byte_2_reg;
	uint16_t ibutton112_byte_3_reg;
	uint16_t ibutton112_byte_4_reg;
	uint16_t ibutton112_byte_5_reg;
	uint16_t ibutton112_byte_6_reg;
	uint16_t ibutton112_byte_7_reg;

	uint16_t ibutton113_byte_0_reg;
	uint16_t ibutton113_byte_1_reg;
	uint16_t ibutton113_byte_2_reg;
	uint16_t ibutton113_byte_3_reg;
	uint16_t ibutton113_byte_4_reg;
	uint16_t ibutton113_byte_5_reg;
	uint16_t ibutton113_byte_6_reg;
	uint16_t ibutton113_byte_7_reg;

	uint16_t ibutton114_byte_0_reg;
	uint16_t ibutton114_byte_1_reg;
	uint16_t ibutton114_byte_2_reg;
	uint16_t ibutton114_byte_3_reg;
	uint16_t ibutton114_byte_4_reg;
	uint16_t ibutton114_byte_5_reg;
	uint16_t ibutton114_byte_6_reg;
	uint16_t ibutton114_byte_7_reg;

	uint16_t ibutton115_byte_0_reg;
	uint16_t ibutton115_byte_1_reg;
	uint16_t ibutton115_byte_2_reg;
	uint16_t ibutton115_byte_3_reg;
	uint16_t ibutton115_byte_4_reg;
	uint16_t ibutton115_byte_5_reg;
	uint16_t ibutton115_byte_6_reg;
	uint16_t ibutton115_byte_7_reg;

	uint16_t ibutton116_byte_0_reg;
	uint16_t ibutton116_byte_1_reg;
	uint16_t ibutton116_byte_2_reg;
	uint16_t ibutton116_byte_3_reg;
	uint16_t ibutton116_byte_4_reg;
	uint16_t ibutton116_byte_5_reg;
	uint16_t ibutton116_byte_6_reg;
	uint16_t ibutton116_byte_7_reg;

	uint16_t ibutton117_byte_0_reg;
	uint16_t ibutton117_byte_1_reg;
	uint16_t ibutton117_byte_2_reg;
	uint16_t ibutton117_byte_3_reg;
	uint16_t ibutton117_byte_4_reg;
	uint16_t ibutton117_byte_5_reg;
	uint16_t ibutton117_byte_6_reg;
	uint16_t ibutton117_byte_7_reg;

	uint16_t ibutton118_byte_0_reg;
	uint16_t ibutton118_byte_1_reg;
	uint16_t ibutton118_byte_2_reg;
	uint16_t ibutton118_byte_3_reg;
	uint16_t ibutton118_byte_4_reg;
	uint16_t ibutton118_byte_5_reg;
	uint16_t ibutton118_byte_6_reg;
	uint16_t ibutton118_byte_7_reg;

	uint16_t ibutton119_byte_0_reg;
	uint16_t ibutton119_byte_1_reg;
	uint16_t ibutton119_byte_2_reg;
	uint16_t ibutton119_byte_3_reg;
	uint16_t ibutton119_byte_4_reg;
	uint16_t ibutton119_byte_5_reg;
	uint16_t ibutton119_byte_6_reg;
	uint16_t ibutton119_byte_7_reg;

	uint16_t ibutton120_byte_0_reg;
	uint16_t ibutton120_byte_1_reg;
	uint16_t ibutton120_byte_2_reg;
	uint16_t ibutton120_byte_3_reg;
	uint16_t ibutton120_byte_4_reg;
	uint16_t ibutton120_byte_5_reg;
	uint16_t ibutton120_byte_6_reg;
	uint16_t ibutton120_byte_7_reg;

	uint16_t ibutton121_byte_0_reg;
	uint16_t ibutton121_byte_1_reg;
	uint16_t ibutton121_byte_2_reg;
	uint16_t ibutton121_byte_3_reg;
	uint16_t ibutton121_byte_4_reg;
	uint16_t ibutton121_byte_5_reg;
	uint16_t ibutton121_byte_6_reg;
	uint16_t ibutton121_byte_7_reg;

	uint16_t ibutton122_byte_0_reg;
	uint16_t ibutton122_byte_1_reg;
	uint16_t ibutton122_byte_2_reg;
	uint16_t ibutton122_byte_3_reg;
	uint16_t ibutton122_byte_4_reg;
	uint16_t ibutton122_byte_5_reg;
	uint16_t ibutton122_byte_6_reg;
	uint16_t ibutton122_byte_7_reg;

	uint16_t ibutton123_byte_0_reg;
	uint16_t ibutton123_byte_1_reg;
	uint16_t ibutton123_byte_2_reg;
	uint16_t ibutton123_byte_3_reg;
	uint16_t ibutton123_byte_4_reg;
	uint16_t ibutton123_byte_5_reg;
	uint16_t ibutton123_byte_6_reg;
	uint16_t ibutton123_byte_7_reg;

	uint16_t ibutton124_byte_0_reg;
	uint16_t ibutton124_byte_1_reg;
	uint16_t ibutton124_byte_2_reg;
	uint16_t ibutton124_byte_3_reg;
	uint16_t ibutton124_byte_4_reg;
	uint16_t ibutton124_byte_5_reg;
	uint16_t ibutton124_byte_6_reg;
	uint16_t ibutton124_byte_7_reg;

	uint16_t ibutton125_byte_0_reg;
	uint16_t ibutton125_byte_1_reg;
	uint16_t ibutton125_byte_2_reg;
	uint16_t ibutton125_byte_3_reg;
	uint16_t ibutton125_byte_4_reg;
	uint16_t ibutton125_byte_5_reg;
	uint16_t ibutton125_byte_6_reg;
	uint16_t ibutton125_byte_7_reg;

	uint16_t ibutton126_byte_0_reg;
	uint16_t ibutton126_byte_1_reg;
	uint16_t ibutton126_byte_2_reg;
	uint16_t ibutton126_byte_3_reg;
	uint16_t ibutton126_byte_4_reg;
	uint16_t ibutton126_byte_5_reg;
	uint16_t ibutton126_byte_6_reg;
	uint16_t ibutton126_byte_7_reg;

	uint16_t ibutton127_byte_0_reg;
	uint16_t ibutton127_byte_1_reg;
	uint16_t ibutton127_byte_2_reg;
	uint16_t ibutton127_byte_3_reg;
	uint16_t ibutton127_byte_4_reg;
	uint16_t ibutton127_byte_5_reg;
	uint16_t ibutton127_byte_6_reg;
	uint16_t ibutton127_byte_7_reg;

	uint16_t ibutton128_byte_0_reg;
	uint16_t ibutton128_byte_1_reg;
	uint16_t ibutton128_byte_2_reg;
	uint16_t ibutton128_byte_3_reg;
	uint16_t ibutton128_byte_4_reg;
	uint16_t ibutton128_byte_5_reg;
	uint16_t ibutton128_byte_6_reg;
	uint16_t ibutton128_byte_7_reg;

	uint16_t ibutton129_byte_0_reg;
	uint16_t ibutton129_byte_1_reg;
	uint16_t ibutton129_byte_2_reg;
	uint16_t ibutton129_byte_3_reg;
	uint16_t ibutton129_byte_4_reg;
	uint16_t ibutton129_byte_5_reg;
	uint16_t ibutton129_byte_6_reg;
	uint16_t ibutton129_byte_7_reg;

	uint16_t ibutton130_byte_0_reg;
	uint16_t ibutton130_byte_1_reg;
	uint16_t ibutton130_byte_2_reg;
	uint16_t ibutton130_byte_3_reg;
	uint16_t ibutton130_byte_4_reg;
	uint16_t ibutton130_byte_5_reg;
	uint16_t ibutton130_byte_6_reg;
	uint16_t ibutton130_byte_7_reg;

	uint16_t ibutton131_byte_0_reg;
	uint16_t ibutton131_byte_1_reg;
	uint16_t ibutton131_byte_2_reg;
	uint16_t ibutton131_byte_3_reg;
	uint16_t ibutton131_byte_4_reg;
	uint16_t ibutton131_byte_5_reg;
	uint16_t ibutton131_byte_6_reg;
	uint16_t ibutton131_byte_7_reg;

	uint16_t ibutton132_byte_0_reg;
	uint16_t ibutton132_byte_1_reg;
	uint16_t ibutton132_byte_2_reg;
	uint16_t ibutton132_byte_3_reg;
	uint16_t ibutton132_byte_4_reg;
	uint16_t ibutton132_byte_5_reg;
	uint16_t ibutton132_byte_6_reg;
	uint16_t ibutton132_byte_7_reg;

	uint16_t ibutton133_byte_0_reg;
	uint16_t ibutton133_byte_1_reg;
	uint16_t ibutton133_byte_2_reg;
	uint16_t ibutton133_byte_3_reg;
	uint16_t ibutton133_byte_4_reg;
	uint16_t ibutton133_byte_5_reg;
	uint16_t ibutton133_byte_6_reg;
	uint16_t ibutton133_byte_7_reg;

	uint16_t ibutton134_byte_0_reg;
	uint16_t ibutton134_byte_1_reg;
	uint16_t ibutton134_byte_2_reg;
	uint16_t ibutton134_byte_3_reg;
	uint16_t ibutton134_byte_4_reg;
	uint16_t ibutton134_byte_5_reg;
	uint16_t ibutton134_byte_6_reg;
	uint16_t ibutton134_byte_7_reg;

	uint16_t ibutton135_byte_0_reg;
	uint16_t ibutton135_byte_1_reg;
	uint16_t ibutton135_byte_2_reg;
	uint16_t ibutton135_byte_3_reg;
	uint16_t ibutton135_byte_4_reg;
	uint16_t ibutton135_byte_5_reg;
	uint16_t ibutton135_byte_6_reg;
	uint16_t ibutton135_byte_7_reg;

	uint16_t ibutton136_byte_0_reg;
	uint16_t ibutton136_byte_1_reg;
	uint16_t ibutton136_byte_2_reg;
	uint16_t ibutton136_byte_3_reg;
	uint16_t ibutton136_byte_4_reg;
	uint16_t ibutton136_byte_5_reg;
	uint16_t ibutton136_byte_6_reg;
	uint16_t ibutton136_byte_7_reg;

	uint16_t ibutton137_byte_0_reg;
	uint16_t ibutton137_byte_1_reg;
	uint16_t ibutton137_byte_2_reg;
	uint16_t ibutton137_byte_3_reg;
	uint16_t ibutton137_byte_4_reg;
	uint16_t ibutton137_byte_5_reg;
	uint16_t ibutton137_byte_6_reg;
	uint16_t ibutton137_byte_7_reg;

	uint16_t ibutton138_byte_0_reg;
	uint16_t ibutton138_byte_1_reg;
	uint16_t ibutton138_byte_2_reg;
	uint16_t ibutton138_byte_3_reg;
	uint16_t ibutton138_byte_4_reg;
	uint16_t ibutton138_byte_5_reg;
	uint16_t ibutton138_byte_6_reg;
	uint16_t ibutton138_byte_7_reg;

	uint16_t ibutton139_byte_0_reg;
	uint16_t ibutton139_byte_1_reg;
	uint16_t ibutton139_byte_2_reg;
	uint16_t ibutton139_byte_3_reg;
	uint16_t ibutton139_byte_4_reg;
	uint16_t ibutton139_byte_5_reg;
	uint16_t ibutton139_byte_6_reg;
	uint16_t ibutton139_byte_7_reg;

	uint16_t ibutton140_byte_0_reg;
	uint16_t ibutton140_byte_1_reg;
	uint16_t ibutton140_byte_2_reg;
	uint16_t ibutton140_byte_3_reg;
	uint16_t ibutton140_byte_4_reg;
	uint16_t ibutton140_byte_5_reg;
	uint16_t ibutton140_byte_6_reg;
	uint16_t ibutton140_byte_7_reg;

	uint16_t ibutton141_byte_0_reg;
	uint16_t ibutton141_byte_1_reg;
	uint16_t ibutton141_byte_2_reg;
	uint16_t ibutton141_byte_3_reg;
	uint16_t ibutton141_byte_4_reg;
	uint16_t ibutton141_byte_5_reg;
	uint16_t ibutton141_byte_6_reg;
	uint16_t ibutton141_byte_7_reg;

	uint16_t ibutton142_byte_0_reg;
	uint16_t ibutton142_byte_1_reg;
	uint16_t ibutton142_byte_2_reg;
	uint16_t ibutton142_byte_3_reg;
	uint16_t ibutton142_byte_4_reg;
	uint16_t ibutton142_byte_5_reg;
	uint16_t ibutton142_byte_6_reg;
	uint16_t ibutton142_byte_7_reg;

	uint16_t ibutton143_byte_0_reg;
	uint16_t ibutton143_byte_1_reg;
	uint16_t ibutton143_byte_2_reg;
	uint16_t ibutton143_byte_3_reg;
	uint16_t ibutton143_byte_4_reg;
	uint16_t ibutton143_byte_5_reg;
	uint16_t ibutton143_byte_6_reg;
	uint16_t ibutton143_byte_7_reg;

	uint16_t ibutton144_byte_0_reg;
	uint16_t ibutton144_byte_1_reg;
	uint16_t ibutton144_byte_2_reg;
	uint16_t ibutton144_byte_3_reg;
	uint16_t ibutton144_byte_4_reg;
	uint16_t ibutton144_byte_5_reg;
	uint16_t ibutton144_byte_6_reg;
	uint16_t ibutton144_byte_7_reg;

	uint16_t ibutton145_byte_0_reg;
	uint16_t ibutton145_byte_1_reg;
	uint16_t ibutton145_byte_2_reg;
	uint16_t ibutton145_byte_3_reg;
	uint16_t ibutton145_byte_4_reg;
	uint16_t ibutton145_byte_5_reg;
	uint16_t ibutton145_byte_6_reg;
	uint16_t ibutton145_byte_7_reg;

	uint16_t ibutton146_byte_0_reg;
	uint16_t ibutton146_byte_1_reg;
	uint16_t ibutton146_byte_2_reg;
	uint16_t ibutton146_byte_3_reg;
	uint16_t ibutton146_byte_4_reg;
	uint16_t ibutton146_byte_5_reg;
	uint16_t ibutton146_byte_6_reg;
	uint16_t ibutton146_byte_7_reg;

	uint16_t ibutton147_byte_0_reg;
	uint16_t ibutton147_byte_1_reg;
	uint16_t ibutton147_byte_2_reg;
	uint16_t ibutton147_byte_3_reg;
	uint16_t ibutton147_byte_4_reg;
	uint16_t ibutton147_byte_5_reg;
	uint16_t ibutton147_byte_6_reg;
	uint16_t ibutton147_byte_7_reg;

	uint16_t ibutton148_byte_0_reg;
	uint16_t ibutton148_byte_1_reg;
	uint16_t ibutton148_byte_2_reg;
	uint16_t ibutton148_byte_3_reg;
	uint16_t ibutton148_byte_4_reg;
	uint16_t ibutton148_byte_5_reg;
	uint16_t ibutton148_byte_6_reg;
	uint16_t ibutton148_byte_7_reg;

	uint16_t ibutton149_byte_0_reg;
	uint16_t ibutton149_byte_1_reg;
	uint16_t ibutton149_byte_2_reg;
	uint16_t ibutton149_byte_3_reg;
	uint16_t ibutton149_byte_4_reg;
	uint16_t ibutton149_byte_5_reg;
	uint16_t ibutton149_byte_6_reg;
	uint16_t ibutton149_byte_7_reg;

	uint16_t ibutton150_byte_0_reg;
	uint16_t ibutton150_byte_1_reg;
	uint16_t ibutton150_byte_2_reg;
	uint16_t ibutton150_byte_3_reg;
	uint16_t ibutton150_byte_4_reg;
	uint16_t ibutton150_byte_5_reg;
	uint16_t ibutton150_byte_6_reg;
	uint16_t ibutton150_byte_7_reg;

	uint16_t ibutton151_byte_0_reg;
	uint16_t ibutton151_byte_1_reg;
	uint16_t ibutton151_byte_2_reg;
	uint16_t ibutton151_byte_3_reg;
	uint16_t ibutton151_byte_4_reg;
	uint16_t ibutton151_byte_5_reg;
	uint16_t ibutton151_byte_6_reg;
	uint16_t ibutton151_byte_7_reg;

	uint16_t ibutton152_byte_0_reg;
	uint16_t ibutton152_byte_1_reg;
	uint16_t ibutton152_byte_2_reg;
	uint16_t ibutton152_byte_3_reg;
	uint16_t ibutton152_byte_4_reg;
	uint16_t ibutton152_byte_5_reg;
	uint16_t ibutton152_byte_6_reg;
	uint16_t ibutton152_byte_7_reg;

	uint16_t ibutton153_byte_0_reg;
	uint16_t ibutton153_byte_1_reg;
	uint16_t ibutton153_byte_2_reg;
	uint16_t ibutton153_byte_3_reg;
	uint16_t ibutton153_byte_4_reg;
	uint16_t ibutton153_byte_5_reg;
	uint16_t ibutton153_byte_6_reg;
	uint16_t ibutton153_byte_7_reg;

	uint16_t ibutton154_byte_0_reg;
	uint16_t ibutton154_byte_1_reg;
	uint16_t ibutton154_byte_2_reg;
	uint16_t ibutton154_byte_3_reg;
	uint16_t ibutton154_byte_4_reg;
	uint16_t ibutton154_byte_5_reg;
	uint16_t ibutton154_byte_6_reg;
	uint16_t ibutton154_byte_7_reg;

	uint16_t ibutton155_byte_0_reg;
	uint16_t ibutton155_byte_1_reg;
	uint16_t ibutton155_byte_2_reg;
	uint16_t ibutton155_byte_3_reg;
	uint16_t ibutton155_byte_4_reg;
	uint16_t ibutton155_byte_5_reg;
	uint16_t ibutton155_byte_6_reg;
	uint16_t ibutton155_byte_7_reg;

	uint16_t ibutton156_byte_0_reg;
	uint16_t ibutton156_byte_1_reg;
	uint16_t ibutton156_byte_2_reg;
	uint16_t ibutton156_byte_3_reg;
	uint16_t ibutton156_byte_4_reg;
	uint16_t ibutton156_byte_5_reg;
	uint16_t ibutton156_byte_6_reg;
	uint16_t ibutton156_byte_7_reg;

	uint16_t ibutton157_byte_0_reg;
	uint16_t ibutton157_byte_1_reg;
	uint16_t ibutton157_byte_2_reg;
	uint16_t ibutton157_byte_3_reg;
	uint16_t ibutton157_byte_4_reg;
	uint16_t ibutton157_byte_5_reg;
	uint16_t ibutton157_byte_6_reg;
	uint16_t ibutton157_byte_7_reg;

	uint16_t ibutton158_byte_0_reg;
	uint16_t ibutton158_byte_1_reg;
	uint16_t ibutton158_byte_2_reg;
	uint16_t ibutton158_byte_3_reg;
	uint16_t ibutton158_byte_4_reg;
	uint16_t ibutton158_byte_5_reg;
	uint16_t ibutton158_byte_6_reg;
	uint16_t ibutton158_byte_7_reg;

	uint16_t ibutton159_byte_0_reg;
	uint16_t ibutton159_byte_1_reg;
	uint16_t ibutton159_byte_2_reg;
	uint16_t ibutton159_byte_3_reg;
	uint16_t ibutton159_byte_4_reg;
	uint16_t ibutton159_byte_5_reg;
	uint16_t ibutton159_byte_6_reg;
	uint16_t ibutton159_byte_7_reg;

	uint16_t ibutton160_byte_0_reg;
	uint16_t ibutton160_byte_1_reg;
	uint16_t ibutton160_byte_2_reg;
	uint16_t ibutton160_byte_3_reg;
	uint16_t ibutton160_byte_4_reg;
	uint16_t ibutton160_byte_5_reg;
	uint16_t ibutton160_byte_6_reg;
	uint16_t ibutton160_byte_7_reg;

	uint16_t ibutton161_byte_0_reg;
	uint16_t ibutton161_byte_1_reg;
	uint16_t ibutton161_byte_2_reg;
	uint16_t ibutton161_byte_3_reg;
	uint16_t ibutton161_byte_4_reg;
	uint16_t ibutton161_byte_5_reg;
	uint16_t ibutton161_byte_6_reg;
	uint16_t ibutton161_byte_7_reg;

	uint16_t ibutton162_byte_0_reg;
	uint16_t ibutton162_byte_1_reg;
	uint16_t ibutton162_byte_2_reg;
	uint16_t ibutton162_byte_3_reg;
	uint16_t ibutton162_byte_4_reg;
	uint16_t ibutton162_byte_5_reg;
	uint16_t ibutton162_byte_6_reg;
	uint16_t ibutton162_byte_7_reg;

	uint16_t ibutton163_byte_0_reg;
	uint16_t ibutton163_byte_1_reg;
	uint16_t ibutton163_byte_2_reg;
	uint16_t ibutton163_byte_3_reg;
	uint16_t ibutton163_byte_4_reg;
	uint16_t ibutton163_byte_5_reg;
	uint16_t ibutton163_byte_6_reg;
	uint16_t ibutton163_byte_7_reg;

	uint16_t ibutton164_byte_0_reg;
	uint16_t ibutton164_byte_1_reg;
	uint16_t ibutton164_byte_2_reg;
	uint16_t ibutton164_byte_3_reg;
	uint16_t ibutton164_byte_4_reg;
	uint16_t ibutton164_byte_5_reg;
	uint16_t ibutton164_byte_6_reg;
	uint16_t ibutton164_byte_7_reg;

	uint16_t ibutton165_byte_0_reg;
	uint16_t ibutton165_byte_1_reg;
	uint16_t ibutton165_byte_2_reg;
	uint16_t ibutton165_byte_3_reg;
	uint16_t ibutton165_byte_4_reg;
	uint16_t ibutton165_byte_5_reg;
	uint16_t ibutton165_byte_6_reg;
	uint16_t ibutton165_byte_7_reg;

	uint16_t ibutton166_byte_0_reg;
	uint16_t ibutton166_byte_1_reg;
	uint16_t ibutton166_byte_2_reg;
	uint16_t ibutton166_byte_3_reg;
	uint16_t ibutton166_byte_4_reg;
	uint16_t ibutton166_byte_5_reg;
	uint16_t ibutton166_byte_6_reg;
	uint16_t ibutton166_byte_7_reg;

	uint16_t ibutton167_byte_0_reg;
	uint16_t ibutton167_byte_1_reg;
	uint16_t ibutton167_byte_2_reg;
	uint16_t ibutton167_byte_3_reg;
	uint16_t ibutton167_byte_4_reg;
	uint16_t ibutton167_byte_5_reg;
	uint16_t ibutton167_byte_6_reg;
	uint16_t ibutton167_byte_7_reg;

	uint16_t ibutton168_byte_0_reg;
	uint16_t ibutton168_byte_1_reg;
	uint16_t ibutton168_byte_2_reg;
	uint16_t ibutton168_byte_3_reg;
	uint16_t ibutton168_byte_4_reg;
	uint16_t ibutton168_byte_5_reg;
	uint16_t ibutton168_byte_6_reg;
	uint16_t ibutton168_byte_7_reg;

	uint16_t ibutton169_byte_0_reg;
	uint16_t ibutton169_byte_1_reg;
	uint16_t ibutton169_byte_2_reg;
	uint16_t ibutton169_byte_3_reg;
	uint16_t ibutton169_byte_4_reg;
	uint16_t ibutton169_byte_5_reg;
	uint16_t ibutton169_byte_6_reg;
	uint16_t ibutton169_byte_7_reg;

	uint16_t ibutton170_byte_0_reg;
	uint16_t ibutton170_byte_1_reg;
	uint16_t ibutton170_byte_2_reg;
	uint16_t ibutton170_byte_3_reg;
	uint16_t ibutton170_byte_4_reg;
	uint16_t ibutton170_byte_5_reg;
	uint16_t ibutton170_byte_6_reg;
	uint16_t ibutton170_byte_7_reg;

	uint16_t ibutton171_byte_0_reg;
	uint16_t ibutton171_byte_1_reg;
	uint16_t ibutton171_byte_2_reg;
	uint16_t ibutton171_byte_3_reg;
	uint16_t ibutton171_byte_4_reg;
	uint16_t ibutton171_byte_5_reg;
	uint16_t ibutton171_byte_6_reg;
	uint16_t ibutton171_byte_7_reg;

	uint16_t ibutton172_byte_0_reg;
	uint16_t ibutton172_byte_1_reg;
	uint16_t ibutton172_byte_2_reg;
	uint16_t ibutton172_byte_3_reg;
	uint16_t ibutton172_byte_4_reg;
	uint16_t ibutton172_byte_5_reg;
	uint16_t ibutton172_byte_6_reg;
	uint16_t ibutton172_byte_7_reg;

	uint16_t ibutton173_byte_0_reg;
	uint16_t ibutton173_byte_1_reg;
	uint16_t ibutton173_byte_2_reg;
	uint16_t ibutton173_byte_3_reg;
	uint16_t ibutton173_byte_4_reg;
	uint16_t ibutton173_byte_5_reg;
	uint16_t ibutton173_byte_6_reg;
	uint16_t ibutton173_byte_7_reg;

	uint16_t ibutton174_byte_0_reg;
	uint16_t ibutton174_byte_1_reg;
	uint16_t ibutton174_byte_2_reg;
	uint16_t ibutton174_byte_3_reg;
	uint16_t ibutton174_byte_4_reg;
	uint16_t ibutton174_byte_5_reg;
	uint16_t ibutton174_byte_6_reg;
	uint16_t ibutton174_byte_7_reg;

	uint16_t ibutton175_byte_0_reg;
	uint16_t ibutton175_byte_1_reg;
	uint16_t ibutton175_byte_2_reg;
	uint16_t ibutton175_byte_3_reg;
	uint16_t ibutton175_byte_4_reg;
	uint16_t ibutton175_byte_5_reg;
	uint16_t ibutton175_byte_6_reg;
	uint16_t ibutton175_byte_7_reg;

	uint16_t ibutton176_byte_0_reg;
	uint16_t ibutton176_byte_1_reg;
	uint16_t ibutton176_byte_2_reg;
	uint16_t ibutton176_byte_3_reg;
	uint16_t ibutton176_byte_4_reg;
	uint16_t ibutton176_byte_5_reg;
	uint16_t ibutton176_byte_6_reg;
	uint16_t ibutton176_byte_7_reg;

	uint16_t ibutton177_byte_0_reg;
	uint16_t ibutton177_byte_1_reg;
	uint16_t ibutton177_byte_2_reg;
	uint16_t ibutton177_byte_3_reg;
	uint16_t ibutton177_byte_4_reg;
	uint16_t ibutton177_byte_5_reg;
	uint16_t ibutton177_byte_6_reg;
	uint16_t ibutton177_byte_7_reg;

	uint16_t ibutton178_byte_0_reg;
	uint16_t ibutton178_byte_1_reg;
	uint16_t ibutton178_byte_2_reg;
	uint16_t ibutton178_byte_3_reg;
	uint16_t ibutton178_byte_4_reg;
	uint16_t ibutton178_byte_5_reg;
	uint16_t ibutton178_byte_6_reg;
	uint16_t ibutton178_byte_7_reg;

	uint16_t ibutton179_byte_0_reg;
	uint16_t ibutton179_byte_1_reg;
	uint16_t ibutton179_byte_2_reg;
	uint16_t ibutton179_byte_3_reg;
	uint16_t ibutton179_byte_4_reg;
	uint16_t ibutton179_byte_5_reg;
	uint16_t ibutton179_byte_6_reg;
	uint16_t ibutton179_byte_7_reg;

	uint16_t ibutton180_byte_0_reg;
	uint16_t ibutton180_byte_1_reg;
	uint16_t ibutton180_byte_2_reg;
	uint16_t ibutton180_byte_3_reg;
	uint16_t ibutton180_byte_4_reg;
	uint16_t ibutton180_byte_5_reg;
	uint16_t ibutton180_byte_6_reg;
	uint16_t ibutton180_byte_7_reg;

	uint16_t ibutton181_byte_0_reg;
	uint16_t ibutton181_byte_1_reg;
	uint16_t ibutton181_byte_2_reg;
	uint16_t ibutton181_byte_3_reg;
	uint16_t ibutton181_byte_4_reg;
	uint16_t ibutton181_byte_5_reg;
	uint16_t ibutton181_byte_6_reg;
	uint16_t ibutton181_byte_7_reg;

	uint16_t ibutton182_byte_0_reg;
	uint16_t ibutton182_byte_1_reg;
	uint16_t ibutton182_byte_2_reg;
	uint16_t ibutton182_byte_3_reg;
	uint16_t ibutton182_byte_4_reg;
	uint16_t ibutton182_byte_5_reg;
	uint16_t ibutton182_byte_6_reg;
	uint16_t ibutton182_byte_7_reg;

	uint16_t ibutton183_byte_0_reg;
	uint16_t ibutton183_byte_1_reg;
	uint16_t ibutton183_byte_2_reg;
	uint16_t ibutton183_byte_3_reg;
	uint16_t ibutton183_byte_4_reg;
	uint16_t ibutton183_byte_5_reg;
	uint16_t ibutton183_byte_6_reg;
	uint16_t ibutton183_byte_7_reg;

	uint16_t ibutton184_byte_0_reg;
	uint16_t ibutton184_byte_1_reg;
	uint16_t ibutton184_byte_2_reg;
	uint16_t ibutton184_byte_3_reg;
	uint16_t ibutton184_byte_4_reg;
	uint16_t ibutton184_byte_5_reg;
	uint16_t ibutton184_byte_6_reg;
	uint16_t ibutton184_byte_7_reg;

	uint16_t ibutton185_byte_0_reg;
	uint16_t ibutton185_byte_1_reg;
	uint16_t ibutton185_byte_2_reg;
	uint16_t ibutton185_byte_3_reg;
	uint16_t ibutton185_byte_4_reg;
	uint16_t ibutton185_byte_5_reg;
	uint16_t ibutton185_byte_6_reg;
	uint16_t ibutton185_byte_7_reg;

	uint16_t ibutton186_byte_0_reg;
	uint16_t ibutton186_byte_1_reg;
	uint16_t ibutton186_byte_2_reg;
	uint16_t ibutton186_byte_3_reg;
	uint16_t ibutton186_byte_4_reg;
	uint16_t ibutton186_byte_5_reg;
	uint16_t ibutton186_byte_6_reg;
	uint16_t ibutton186_byte_7_reg;

	uint16_t ibutton187_byte_0_reg;
	uint16_t ibutton187_byte_1_reg;
	uint16_t ibutton187_byte_2_reg;
	uint16_t ibutton187_byte_3_reg;
	uint16_t ibutton187_byte_4_reg;
	uint16_t ibutton187_byte_5_reg;
	uint16_t ibutton187_byte_6_reg;
	uint16_t ibutton187_byte_7_reg;

	uint16_t ibutton188_byte_0_reg;
	uint16_t ibutton188_byte_1_reg;
	uint16_t ibutton188_byte_2_reg;
	uint16_t ibutton188_byte_3_reg;
	uint16_t ibutton188_byte_4_reg;
	uint16_t ibutton188_byte_5_reg;
	uint16_t ibutton188_byte_6_reg;
	uint16_t ibutton188_byte_7_reg;

	uint16_t ibutton189_byte_0_reg;
	uint16_t ibutton189_byte_1_reg;
	uint16_t ibutton189_byte_2_reg;
	uint16_t ibutton189_byte_3_reg;
	uint16_t ibutton189_byte_4_reg;
	uint16_t ibutton189_byte_5_reg;
	uint16_t ibutton189_byte_6_reg;
	uint16_t ibutton189_byte_7_reg;

	uint16_t ibutton190_byte_0_reg;
	uint16_t ibutton190_byte_1_reg;
	uint16_t ibutton190_byte_2_reg;
	uint16_t ibutton190_byte_3_reg;
	uint16_t ibutton190_byte_4_reg;
	uint16_t ibutton190_byte_5_reg;
	uint16_t ibutton190_byte_6_reg;
	uint16_t ibutton190_byte_7_reg;

	uint16_t ibutton191_byte_0_reg;
	uint16_t ibutton191_byte_1_reg;
	uint16_t ibutton191_byte_2_reg;
	uint16_t ibutton191_byte_3_reg;
	uint16_t ibutton191_byte_4_reg;
	uint16_t ibutton191_byte_5_reg;
	uint16_t ibutton191_byte_6_reg;
	uint16_t ibutton191_byte_7_reg;

	uint16_t ibutton192_byte_0_reg;
	uint16_t ibutton192_byte_1_reg;
	uint16_t ibutton192_byte_2_reg;
	uint16_t ibutton192_byte_3_reg;
	uint16_t ibutton192_byte_4_reg;
	uint16_t ibutton192_byte_5_reg;
	uint16_t ibutton192_byte_6_reg;
	uint16_t ibutton192_byte_7_reg;

	uint16_t ibutton193_byte_0_reg;
	uint16_t ibutton193_byte_1_reg;
	uint16_t ibutton193_byte_2_reg;
	uint16_t ibutton193_byte_3_reg;
	uint16_t ibutton193_byte_4_reg;
	uint16_t ibutton193_byte_5_reg;
	uint16_t ibutton193_byte_6_reg;
	uint16_t ibutton193_byte_7_reg;

	uint16_t ibutton194_byte_0_reg;
	uint16_t ibutton194_byte_1_reg;
	uint16_t ibutton194_byte_2_reg;
	uint16_t ibutton194_byte_3_reg;
	uint16_t ibutton194_byte_4_reg;
	uint16_t ibutton194_byte_5_reg;
	uint16_t ibutton194_byte_6_reg;
	uint16_t ibutton194_byte_7_reg;

	uint16_t ibutton195_byte_0_reg;
	uint16_t ibutton195_byte_1_reg;
	uint16_t ibutton195_byte_2_reg;
	uint16_t ibutton195_byte_3_reg;
	uint16_t ibutton195_byte_4_reg;
	uint16_t ibutton195_byte_5_reg;
	uint16_t ibutton195_byte_6_reg;
	uint16_t ibutton195_byte_7_reg;

	uint16_t ibutton196_byte_0_reg;
	uint16_t ibutton196_byte_1_reg;
	uint16_t ibutton196_byte_2_reg;
	uint16_t ibutton196_byte_3_reg;
	uint16_t ibutton196_byte_4_reg;
	uint16_t ibutton196_byte_5_reg;
	uint16_t ibutton196_byte_6_reg;
	uint16_t ibutton196_byte_7_reg;

	uint16_t ibutton197_byte_0_reg;
	uint16_t ibutton197_byte_1_reg;
	uint16_t ibutton197_byte_2_reg;
	uint16_t ibutton197_byte_3_reg;
	uint16_t ibutton197_byte_4_reg;
	uint16_t ibutton197_byte_5_reg;
	uint16_t ibutton197_byte_6_reg;
	uint16_t ibutton197_byte_7_reg;

	uint16_t ibutton198_byte_0_reg;
	uint16_t ibutton198_byte_1_reg;
	uint16_t ibutton198_byte_2_reg;
	uint16_t ibutton198_byte_3_reg;
	uint16_t ibutton198_byte_4_reg;
	uint16_t ibutton198_byte_5_reg;
	uint16_t ibutton198_byte_6_reg;
	uint16_t ibutton198_byte_7_reg;

	uint16_t ibutton199_byte_0_reg;
	uint16_t ibutton199_byte_1_reg;
	uint16_t ibutton199_byte_2_reg;
	uint16_t ibutton199_byte_3_reg;
	uint16_t ibutton199_byte_4_reg;
	uint16_t ibutton199_byte_5_reg;
	uint16_t ibutton199_byte_6_reg;
	uint16_t ibutton199_byte_7_reg;

} ibutton_register_struct;

//------------------------------------------------------------------

void read_status_registers(void);
void read_control_registers(void);
void read_bootloader_registers(void);
void read_ibutton_registers(void);


#endif
