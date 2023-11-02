################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include 04-APP/subdir.mk
-include 03-HAL/08-POT/subdir.mk
-include 03-HAL/07-LM35/subdir.mk
-include 03-HAL/06-DC_MOTOR/subdir.mk
-include 03-HAL/05-KEYPAD/subdir.mk
-include 03-HAL/04-PUSH_BUTTON/subdir.mk
-include 03-HAL/03-CLCD/subdir.mk
-include 03-HAL/02-SSD/subdir.mk
-include 03-HAL/01-LED/subdir.mk
-include 02-MCAL/05-TIMER/subdir.mk
-include 02-MCAL/04-ADC/subdir.mk
-include 02-MCAL/03-GIE/subdir.mk
-include 02-MCAL/02-EXT/subdir.mk
-include 02-MCAL/01-DIO/subdir.mk
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

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Timer.lss \

FLASH_IMAGE += \
Timer.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Timer.elf secondary-outputs

# Tool invocations
Timer.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Timer.map -mmcu=atmega32 -o "Timer.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Timer.lss: Timer.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Timer.elf  >"Timer.lss"
	@echo 'Finished building: $@'
	@echo ' '

Timer.hex: Timer.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Timer.elf  "Timer.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Timer.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Timer.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Timer.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
