################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/Fixed_Point/src/Fixed_Point.c 

OBJS += \
./App/Fixed_Point/src/Fixed_Point.o 

C_DEPS += \
./App/Fixed_Point/src/Fixed_Point.d 


# Each subdirectory must supply rules for building sources it contributes
App/Fixed_Point/src/%.o: ../App/Fixed_Point/src/%.c App/Fixed_Point/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


