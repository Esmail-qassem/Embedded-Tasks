################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSW/MCAL/TIMER0/src/TIMER0_program.c 

OBJS += \
./BSW/MCAL/TIMER0/src/TIMER0_program.o 

C_DEPS += \
./BSW/MCAL/TIMER0/src/TIMER0_program.d 


# Each subdirectory must supply rules for building sources it contributes
BSW/MCAL/TIMER0/src/%.o: ../BSW/MCAL/TIMER0/src/%.c BSW/MCAL/TIMER0/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\Embedded-Tasks\AT32\BSW\MCAL" -I"D:\Embedded-Tasks\AT32\BSW\HAL" -I"D:\Embedded-Tasks\AT32\App" -I"D:\Embedded-Tasks\AT32\BSW\LIB" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


