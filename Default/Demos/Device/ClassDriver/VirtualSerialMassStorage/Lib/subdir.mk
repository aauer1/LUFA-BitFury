################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Demos/Device/ClassDriver/VirtualSerialMassStorage/Lib/DataflashManager.c \
../Demos/Device/ClassDriver/VirtualSerialMassStorage/Lib/SCSI.c 

C_DEPS += \
./Demos/Device/ClassDriver/VirtualSerialMassStorage/Lib/DataflashManager.d \
./Demos/Device/ClassDriver/VirtualSerialMassStorage/Lib/SCSI.d 


# Each subdirectory must supply rules for building sources it contributes
Demos/Device/ClassDriver/VirtualSerialMassStorage/Lib/%.o: ../Demos/Device/ClassDriver/VirtualSerialMassStorage/Lib/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Common" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/USB" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/Board" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/Misc" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/Peripheral" -D__AVR_ATmega32U2__=1 -U__AVR_ATmega16__ -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


