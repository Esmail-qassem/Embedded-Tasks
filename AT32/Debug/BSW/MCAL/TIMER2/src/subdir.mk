################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSW/MCAL/TIMER2/src/TIMER2_program.c 

OBJS += \
./BSW/MCAL/TIMER2/src/TIMER2_program.o 

C_DEPS += \
./BSW/MCAL/TIMER2/src/TIMER2_program.d 


# Each subdirectory must supply rules for building sources it contributes
BSW/MCAL/TIMER2/src/%.o: ../BSW/MCAL/TIMER2/src/%.c BSW/MCAL/TIMER2/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


