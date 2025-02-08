################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Services/Stack/subdir.mk
-include BSW/MCAL/TWI/src/subdir.mk
-include BSW/MCAL/TIMER2/src/subdir.mk
-include BSW/MCAL/TIMER1/src/subdir.mk
-include BSW/MCAL/TIMER0/src/subdir.mk
-include BSW/MCAL/PORT/src/subdir.mk
-include BSW/MCAL/GIE/src/subdir.mk
-include BSW/MCAL/EXT/src/subdir.mk
-include BSW/MCAL/DIO/src/subdir.mk
-include BSW/MCAL/ADC/src/subdir.mk
-include BSW/HAL/Power_Management/src/subdir.mk
-include BSW/HAL/LCD_OLED/src/subdir.mk
-include BSW/HAL/Internal_EEPROM/src/subdir.mk
-include BSW/HAL/EEPROM/src/subdir.mk
-include BSW/HAL/CLCD/src/subdir.mk
-include App/TrafficLights/src/subdir.mk
-include App/Fixed_Point/src/subdir.mk
-include App/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := AT32
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
AT32.lss \

FLASH_IMAGE += \
AT32.hex \

EEPROM_IMAGE += \
AT32.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: main-build

# Main-build Target
main-build: AT32.elf secondary-outputs

# Tool invocations
AT32.elf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,AT32.map -mmcu=atmega32 -o "AT32.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

AT32.lss: AT32.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S AT32.elf  >"AT32.lss"
	@echo 'Finished building: $@'
	@echo ' '

AT32.hex: AT32.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex AT32.elf  "AT32.hex"
	@echo 'Finished building: $@'
	@echo ' '

AT32.eep: AT32.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex AT32.elf  "AT32.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: AT32.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 AT32.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) AT32.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents main-build

-include ../makefile.targets
