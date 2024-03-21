################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/ArmingTask.c \
../User/CallRingCenteerTask.c \
../User/DisplayTask.c \
../User/EventWriteTask.c \
../User/IbuttonTask.c \
../User/LedTask\ .c \
../User/M95Task.c \
../User/MainTask.c \
../User/MeterTask.c \
../User/ModbusPacketTask.c \
../User/ModbusTask.c \
../User/ReadRegistersTask.c \
../User/SecurityTask.c \
../User/ce303.c \
../User/da04_11gwa.c \
../User/fm25v02.c \
../User/gpio.c \
../User/ibutton.c \
../User/m95.c \
../User/modbus.c 

OBJS += \
./User/ArmingTask.o \
./User/CallRingCenteerTask.o \
./User/DisplayTask.o \
./User/EventWriteTask.o \
./User/IbuttonTask.o \
./User/LedTask\ .o \
./User/M95Task.o \
./User/MainTask.o \
./User/MeterTask.o \
./User/ModbusPacketTask.o \
./User/ModbusTask.o \
./User/ReadRegistersTask.o \
./User/SecurityTask.o \
./User/ce303.o \
./User/da04_11gwa.o \
./User/fm25v02.o \
./User/gpio.o \
./User/ibutton.o \
./User/m95.o \
./User/modbus.o 

C_DEPS += \
./User/ArmingTask.d \
./User/CallRingCenteerTask.d \
./User/DisplayTask.d \
./User/EventWriteTask.d \
./User/IbuttonTask.d \
./User/LedTask\ .d \
./User/M95Task.d \
./User/MainTask.d \
./User/MeterTask.d \
./User/ModbusPacketTask.d \
./User/ModbusTask.d \
./User/ReadRegistersTask.d \
./User/SecurityTask.d \
./User/ce303.d \
./User/da04_11gwa.d \
./User/fm25v02.d \
./User/gpio.d \
./User/ibutton.d \
./User/m95.d \
./User/modbus.d 


# Each subdirectory must supply rules for building sources it contributes
User/%.o: ../User/%.c User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../User -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
User/LedTask\ .o: ../User/LedTask\ .c User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../User -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"User/LedTask .d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-User

clean-User:
	-$(RM) ./User/ArmingTask.d ./User/ArmingTask.o ./User/CallRingCenteerTask.d ./User/CallRingCenteerTask.o ./User/DisplayTask.d ./User/DisplayTask.o ./User/EventWriteTask.d ./User/EventWriteTask.o ./User/IbuttonTask.d ./User/IbuttonTask.o ./User/LedTask\ .d ./User/LedTask\ .o ./User/M95Task.d ./User/M95Task.o ./User/MainTask.d ./User/MainTask.o ./User/MeterTask.d ./User/MeterTask.o ./User/ModbusPacketTask.d ./User/ModbusPacketTask.o ./User/ModbusTask.d ./User/ModbusTask.o ./User/ReadRegistersTask.d ./User/ReadRegistersTask.o ./User/SecurityTask.d ./User/SecurityTask.o ./User/ce303.d ./User/ce303.o ./User/da04_11gwa.d ./User/da04_11gwa.o ./User/fm25v02.d ./User/fm25v02.o ./User/gpio.d ./User/gpio.o ./User/ibutton.d ./User/ibutton.o ./User/m95.d ./User/m95.o ./User/modbus.d ./User/modbus.o

.PHONY: clean-User

