################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/DIO/subdir.mk
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
EXT_INT_EXAMPLE.lss \

FLASH_IMAGE += \
EXT_INT_EXAMPLE.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: EXT_INT_EXAMPLE.elf secondary-outputs

# Tool invocations
EXT_INT_EXAMPLE.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,EXT_INT_EXAMPLE.map -mmcu=atmega32 -o "EXT_INT_EXAMPLE.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

EXT_INT_EXAMPLE.lss: EXT_INT_EXAMPLE.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S EXT_INT_EXAMPLE.elf  >"EXT_INT_EXAMPLE.lss"
	@echo 'Finished building: $@'
	@echo ' '

EXT_INT_EXAMPLE.hex: EXT_INT_EXAMPLE.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex EXT_INT_EXAMPLE.elf  "EXT_INT_EXAMPLE.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: EXT_INT_EXAMPLE.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 EXT_INT_EXAMPLE.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) EXT_INT_EXAMPLE.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
