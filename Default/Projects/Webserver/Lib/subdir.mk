################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Projects/Webserver/Lib/DHCPClientApp.c \
../Projects/Webserver/Lib/DHCPCommon.c \
../Projects/Webserver/Lib/DHCPServerApp.c \
../Projects/Webserver/Lib/DataflashManager.c \
../Projects/Webserver/Lib/HTTPServerApp.c \
../Projects/Webserver/Lib/SCSI.c \
../Projects/Webserver/Lib/TELNETServerApp.c \
../Projects/Webserver/Lib/uIPManagement.c 

C_DEPS += \
./Projects/Webserver/Lib/DHCPClientApp.d \
./Projects/Webserver/Lib/DHCPCommon.d \
./Projects/Webserver/Lib/DHCPServerApp.d \
./Projects/Webserver/Lib/DataflashManager.d \
./Projects/Webserver/Lib/HTTPServerApp.d \
./Projects/Webserver/Lib/SCSI.d \
./Projects/Webserver/Lib/TELNETServerApp.d \
./Projects/Webserver/Lib/uIPManagement.d 


# Each subdirectory must supply rules for building sources it contributes
Projects/Webserver/Lib/%.o: ../Projects/Webserver/Lib/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Common" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/USB" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/Board" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/Misc" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/Peripheral" -D__AVR_ATmega32U2__=1 -U__AVR_ATmega16__ -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


