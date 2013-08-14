################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Projects/Webserver/Lib/uip/clock.c \
../Projects/Webserver/Lib/uip/timer.c \
../Projects/Webserver/Lib/uip/uip-split.c \
../Projects/Webserver/Lib/uip/uip.c \
../Projects/Webserver/Lib/uip/uip_arp.c 

C_DEPS += \
./Projects/Webserver/Lib/uip/clock.d \
./Projects/Webserver/Lib/uip/timer.d \
./Projects/Webserver/Lib/uip/uip-split.d \
./Projects/Webserver/Lib/uip/uip.d \
./Projects/Webserver/Lib/uip/uip_arp.d 


# Each subdirectory must supply rules for building sources it contributes
Projects/Webserver/Lib/uip/%.o: ../Projects/Webserver/Lib/uip/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Common" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/USB" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/Board" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/Misc" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/Peripheral" -D__AVR_ATmega32U2__=1 -U__AVR_ATmega16__ -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


