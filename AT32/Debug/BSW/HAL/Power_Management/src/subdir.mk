################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSW/HAL/Power_Management/src/PwrMng.c 

OBJS += \
./BSW/HAL/Power_Management/src/PwrMng.o 

C_DEPS += \
./BSW/HAL/Power_Management/src/PwrMng.d 


# Each subdirectory must supply rules for building sources it contributes
BSW/HAL/Power_Management/src/%.o: ../BSW/HAL/Power_Management/src/%.c BSW/HAL/Power_Management/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\Embedded-Tasks\AT32\BSW\MCAL" -I"D:\Embedded-Tasks\AT32\BSW\HAL" -I"D:\Embedded-Tasks\AT32\App" -I"D:\Embedded-Tasks\AT32\BSW\LIB" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


