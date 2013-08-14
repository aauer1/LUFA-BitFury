################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LUFA/Drivers/USB/Class/Host/AndroidAccessoryClassHost.c \
../LUFA/Drivers/USB/Class/Host/AudioClassHost.c \
../LUFA/Drivers/USB/Class/Host/CDCClassHost.c \
../LUFA/Drivers/USB/Class/Host/HIDClassHost.c \
../LUFA/Drivers/USB/Class/Host/MIDIClassHost.c \
../LUFA/Drivers/USB/Class/Host/MassStorageClassHost.c \
../LUFA/Drivers/USB/Class/Host/PrinterClassHost.c \
../LUFA/Drivers/USB/Class/Host/RNDISClassHost.c \
../LUFA/Drivers/USB/Class/Host/StillImageClassHost.c 

C_DEPS += \
./LUFA/Drivers/USB/Class/Host/AndroidAccessoryClassHost.d \
./LUFA/Drivers/USB/Class/Host/AudioClassHost.d \
./LUFA/Drivers/USB/Class/Host/CDCClassHost.d \
./LUFA/Drivers/USB/Class/Host/HIDClassHost.d \
./LUFA/Drivers/USB/Class/Host/MIDIClassHost.d \
./LUFA/Drivers/USB/Class/Host/MassStorageClassHost.d \
./LUFA/Drivers/USB/Class/Host/PrinterClassHost.d \
./LUFA/Drivers/USB/Class/Host/RNDISClassHost.d \
./LUFA/Drivers/USB/Class/Host/StillImageClassHost.d 


# Each subdirectory must supply rules for building sources it contributes
LUFA/Drivers/USB/Class/Host/%.o: ../LUFA/Drivers/USB/Class/Host/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Common" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/USB" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/Board" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/Misc" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/Peripheral" -D__AVR_ATmega32U2__=1 -U__AVR_ATmega16__ -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


