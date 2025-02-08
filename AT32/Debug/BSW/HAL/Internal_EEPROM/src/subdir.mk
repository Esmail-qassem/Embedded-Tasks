################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSW/HAL/Internal_EEPROM/src/Int_EEPROM.c 

OBJS += \
./BSW/HAL/Internal_EEPROM/src/Int_EEPROM.o 

C_DEPS += \
./BSW/HAL/Internal_EEPROM/src/Int_EEPROM.d 


# Each subdirectory must supply rules for building sources it contributes
BSW/HAL/Internal_EEPROM/src/%.o: ../BSW/HAL/Internal_EEPROM/src/%.c BSW/HAL/Internal_EEPROM/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\Embedded-Tasks\AT32\BSW\MCAL" -I"D:\Embedded-Tasks\AT32\BSW\HAL" -I"D:\Embedded-Tasks\AT32\App" -I"D:\Embedded-Tasks\AT32\BSW\LIB" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


