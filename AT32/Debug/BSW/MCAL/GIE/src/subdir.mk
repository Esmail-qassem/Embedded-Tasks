################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSW/MCAL/GIE/src/GIE_program.c 

OBJS += \
./BSW/MCAL/GIE/src/GIE_program.o 

C_DEPS += \
./BSW/MCAL/GIE/src/GIE_program.d 


# Each subdirectory must supply rules for building sources it contributes
BSW/MCAL/GIE/src/%.o: ../BSW/MCAL/GIE/src/%.c BSW/MCAL/GIE/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

