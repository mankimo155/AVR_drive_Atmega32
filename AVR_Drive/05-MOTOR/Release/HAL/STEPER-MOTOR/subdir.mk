################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/STEPER-MOTOR/STM-pro.c 

OBJS += \
./HAL/STEPER-MOTOR/STM-pro.o 

C_DEPS += \
./HAL/STEPER-MOTOR/STM-pro.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/STEPER-MOTOR/%.o: ../HAL/STEPER-MOTOR/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


