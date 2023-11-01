################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/DIO/subdir.mk
-include HAL/PUSHBUTTON/subdir.mk
-include HAL/KEYPAD/subdir.mk
-include HAL/CLCD/subdir.mk
-include APP/subdir.mk
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
FOOTBALL_TASK.lss \

FLASH_IMAGE += \
FOOTBALL_TASK.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: FOOTBALL_TASK.elf secondary-outputs

# Tool invocations
FOOTBALL_TASK.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,FOOTBALL_TASK.map -mmcu=atmega32 -o "FOOTBALL_TASK.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

FOOTBALL_TASK.lss: FOOTBALL_TASK.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S FOOTBALL_TASK.elf  >"FOOTBALL_TASK.lss"
	@echo 'Finished building: $@'
	@echo ' '

FOOTBALL_TASK.hex: FOOTBALL_TASK.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex FOOTBALL_TASK.elf  "FOOTBALL_TASK.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: FOOTBALL_TASK.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 FOOTBALL_TASK.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) FOOTBALL_TASK.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
