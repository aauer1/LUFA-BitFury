################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Demos/Device/LowLevel/Keyboard/Descriptors.c \
../Demos/Device/LowLevel/Keyboard/Keyboard.c 

C_DEPS += \
./Demos/Device/LowLevel/Keyboard/Descriptors.d \
./Demos/Device/LowLevel/Keyboard/Keyboard.d 


# Each subdirectory must supply rules for building sources it contributes
Demos/Device/LowLevel/Keyboard/%.o: ../Demos/Device/LowLevel/Keyboard/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Common" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/USB" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/Board" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/Misc" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/Peripheral" -D__AVR_ATmega32U2__=1 -U__AVR_ATmega16__ -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


