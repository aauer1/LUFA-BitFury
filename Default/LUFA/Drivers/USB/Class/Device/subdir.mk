################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LUFA/Drivers/USB/Class/Device/AudioClassDevice.c \
../LUFA/Drivers/USB/Class/Device/CDCClassDevice.c \
../LUFA/Drivers/USB/Class/Device/HIDClassDevice.c \
../LUFA/Drivers/USB/Class/Device/MIDIClassDevice.c \
../LUFA/Drivers/USB/Class/Device/MassStorageClassDevice.c \
../LUFA/Drivers/USB/Class/Device/RNDISClassDevice.c 

C_DEPS += \
./LUFA/Drivers/USB/Class/Device/AudioClassDevice.d \
./LUFA/Drivers/USB/Class/Device/CDCClassDevice.d \
./LUFA/Drivers/USB/Class/Device/HIDClassDevice.d \
./LUFA/Drivers/USB/Class/Device/MIDIClassDevice.d \
./LUFA/Drivers/USB/Class/Device/MassStorageClassDevice.d \
./LUFA/Drivers/USB/Class/Device/RNDISClassDevice.d 


# Each subdirectory must supply rules for building sources it contributes
LUFA/Drivers/USB/Class/Device/%.o: ../LUFA/Drivers/USB/Class/Device/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Common" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/USB" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/Board" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/Misc" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/Peripheral" -D__AVR_ATmega32U2__=1 -U__AVR_ATmega16__ -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


