################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Demos/Device/ClassDriver/RNDISEthernet/Lib/ARP.c \
../Demos/Device/ClassDriver/RNDISEthernet/Lib/DHCP.c \
../Demos/Device/ClassDriver/RNDISEthernet/Lib/Ethernet.c \
../Demos/Device/ClassDriver/RNDISEthernet/Lib/ICMP.c \
../Demos/Device/ClassDriver/RNDISEthernet/Lib/IP.c \
../Demos/Device/ClassDriver/RNDISEthernet/Lib/ProtocolDecoders.c \
../Demos/Device/ClassDriver/RNDISEthernet/Lib/TCP.c \
../Demos/Device/ClassDriver/RNDISEthernet/Lib/UDP.c \
../Demos/Device/ClassDriver/RNDISEthernet/Lib/Webserver.c 

C_DEPS += \
./Demos/Device/ClassDriver/RNDISEthernet/Lib/ARP.d \
./Demos/Device/ClassDriver/RNDISEthernet/Lib/DHCP.d \
./Demos/Device/ClassDriver/RNDISEthernet/Lib/Ethernet.d \
./Demos/Device/ClassDriver/RNDISEthernet/Lib/ICMP.d \
./Demos/Device/ClassDriver/RNDISEthernet/Lib/IP.d \
./Demos/Device/ClassDriver/RNDISEthernet/Lib/ProtocolDecoders.d \
./Demos/Device/ClassDriver/RNDISEthernet/Lib/TCP.d \
./Demos/Device/ClassDriver/RNDISEthernet/Lib/UDP.d \
./Demos/Device/ClassDriver/RNDISEthernet/Lib/Webserver.d 


# Each subdirectory must supply rules for building sources it contributes
Demos/Device/ClassDriver/RNDISEthernet/Lib/%.o: ../Demos/Device/ClassDriver/RNDISEthernet/Lib/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Common" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/USB" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/Board" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/Misc" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/Peripheral" -D__AVR_ATmega32U2__=1 -U__AVR_ATmega16__ -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


