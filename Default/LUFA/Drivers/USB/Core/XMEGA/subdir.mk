################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LUFA/Drivers/USB/Core/XMEGA/Device_XMEGA.c \
../LUFA/Drivers/USB/Core/XMEGA/EndpointStream_XMEGA.c \
../LUFA/Drivers/USB/Core/XMEGA/Endpoint_XMEGA.c \
../LUFA/Drivers/USB/Core/XMEGA/Host_XMEGA.c \
../LUFA/Drivers/USB/Core/XMEGA/PipeStream_XMEGA.c \
../LUFA/Drivers/USB/Core/XMEGA/Pipe_XMEGA.c \
../LUFA/Drivers/USB/Core/XMEGA/USBController_XMEGA.c \
../LUFA/Drivers/USB/Core/XMEGA/USBInterrupt_XMEGA.c 

C_DEPS += \
./LUFA/Drivers/USB/Core/XMEGA/Device_XMEGA.d \
./LUFA/Drivers/USB/Core/XMEGA/EndpointStream_XMEGA.d \
./LUFA/Drivers/USB/Core/XMEGA/Endpoint_XMEGA.d \
./LUFA/Drivers/USB/Core/XMEGA/Host_XMEGA.d \
./LUFA/Drivers/USB/Core/XMEGA/PipeStream_XMEGA.d \
./LUFA/Drivers/USB/Core/XMEGA/Pipe_XMEGA.d \
./LUFA/Drivers/USB/Core/XMEGA/USBController_XMEGA.d \
./LUFA/Drivers/USB/Core/XMEGA/USBInterrupt_XMEGA.d 


# Each subdirectory must supply rules for building sources it contributes
LUFA/Drivers/USB/Core/XMEGA/%.o: ../LUFA/Drivers/USB/Core/XMEGA/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Common" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/USB" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/Board" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/Misc" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/Peripheral" -D__AVR_ATmega32U2__=1 -U__AVR_ATmega16__ -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


