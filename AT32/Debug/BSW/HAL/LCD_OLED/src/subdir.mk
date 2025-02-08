################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSW/HAL/LCD_OLED/src/OLED.c 

OBJS += \
./BSW/HAL/LCD_OLED/src/OLED.o 

C_DEPS += \
./BSW/HAL/LCD_OLED/src/OLED.d 


# Each subdirectory must supply rules for building sources it contributes
BSW/HAL/LCD_OLED/src/%.o: ../BSW/HAL/LCD_OLED/src/%.c BSW/HAL/LCD_OLED/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\Embedded-Tasks\AT32\BSW\MCAL" -I"D:\Embedded-Tasks\AT32\BSW\HAL" -I"D:\Embedded-Tasks\AT32\App" -I"D:\Embedded-Tasks\AT32\BSW\LIB" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


