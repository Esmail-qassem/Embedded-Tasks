################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSW/HAL/CLCD/src/CLCD_program.c 

OBJS += \
./BSW/HAL/CLCD/src/CLCD_program.o 

C_DEPS += \
./BSW/HAL/CLCD/src/CLCD_program.d 


# Each subdirectory must supply rules for building sources it contributes
BSW/HAL/CLCD/src/%.o: ../BSW/HAL/CLCD/src/%.c BSW/HAL/CLCD/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


