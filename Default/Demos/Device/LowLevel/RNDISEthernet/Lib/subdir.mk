################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Demos/Device/LowLevel/RNDISEthernet/Lib/ARP.c \
../Demos/Device/LowLevel/RNDISEthernet/Lib/DHCP.c \
../Demos/Device/LowLevel/RNDISEthernet/Lib/Ethernet.c \
../Demos/Device/LowLevel/RNDISEthernet/Lib/ICMP.c \
../Demos/Device/LowLevel/RNDISEthernet/Lib/IP.c \
../Demos/Device/LowLevel/RNDISEthernet/Lib/ProtocolDecoders.c \
../Demos/Device/LowLevel/RNDISEthernet/Lib/RNDIS.c \
../Demos/Device/LowLevel/RNDISEthernet/Lib/TCP.c \
../Demos/Device/LowLevel/RNDISEthernet/Lib/UDP.c \
../Demos/Device/LowLevel/RNDISEthernet/Lib/Webserver.c 

C_DEPS += \
./Demos/Device/LowLevel/RNDISEthernet/Lib/ARP.d \
./Demos/Device/LowLevel/RNDISEthernet/Lib/DHCP.d \
./Demos/Device/LowLevel/RNDISEthernet/Lib/Ethernet.d \
./Demos/Device/LowLevel/RNDISEthernet/Lib/ICMP.d \
./Demos/Device/LowLevel/RNDISEthernet/Lib/IP.d \
./Demos/Device/LowLevel/RNDISEthernet/Lib/ProtocolDecoders.d \
./Demos/Device/LowLevel/RNDISEthernet/Lib/RNDIS.d \
./Demos/Device/LowLevel/RNDISEthernet/Lib/TCP.d \
./Demos/Device/LowLevel/RNDISEthernet/Lib/UDP.d \
./Demos/Device/LowLevel/RNDISEthernet/Lib/Webserver.d 


# Each subdirectory must supply rules for building sources it contributes
Demos/Device/LowLevel/RNDISEthernet/Lib/%.o: ../Demos/Device/LowLevel/RNDISEthernet/Lib/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Common" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/USB" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/Board" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/Misc" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/Peripheral" -D__AVR_ATmega32U2__=1 -U__AVR_ATmega16__ -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


