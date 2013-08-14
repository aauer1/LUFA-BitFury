################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Demos/DualRole/ClassDriver/MouseHostDevice/Descriptors.c \
../Demos/DualRole/ClassDriver/MouseHostDevice/DeviceFunctions.c \
../Demos/DualRole/ClassDriver/MouseHostDevice/HostFunctions.c \
../Demos/DualRole/ClassDriver/MouseHostDevice/MouseHostDevice.c 

C_DEPS += \
./Demos/DualRole/ClassDriver/MouseHostDevice/Descriptors.d \
./Demos/DualRole/ClassDriver/MouseHostDevice/DeviceFunctions.d \
./Demos/DualRole/ClassDriver/MouseHostDevice/HostFunctions.d \
./Demos/DualRole/ClassDriver/MouseHostDevice/MouseHostDevice.d 


# Each subdirectory must supply rules for building sources it contributes
Demos/DualRole/ClassDriver/MouseHostDevice/%.o: ../Demos/DualRole/ClassDriver/MouseHostDevice/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Common" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/USB" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/Board" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/Misc" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/Peripheral" -D__AVR_ATmega32U2__=1 -U__AVR_ATmega16__ -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


