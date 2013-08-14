################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LUFA/Drivers/USB/Core/AVR8/Template/Template_Endpoint_Control_R.c \
../LUFA/Drivers/USB/Core/AVR8/Template/Template_Endpoint_Control_W.c \
../LUFA/Drivers/USB/Core/AVR8/Template/Template_Endpoint_RW.c \
../LUFA/Drivers/USB/Core/AVR8/Template/Template_Pipe_RW.c 

C_DEPS += \
./LUFA/Drivers/USB/Core/AVR8/Template/Template_Endpoint_Control_R.d \
./LUFA/Drivers/USB/Core/AVR8/Template/Template_Endpoint_Control_W.d \
./LUFA/Drivers/USB/Core/AVR8/Template/Template_Endpoint_RW.d \
./LUFA/Drivers/USB/Core/AVR8/Template/Template_Pipe_RW.d 


# Each subdirectory must supply rules for building sources it contributes
LUFA/Drivers/USB/Core/AVR8/Template/%.o: ../LUFA/Drivers/USB/Core/AVR8/Template/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Common" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/USB" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/Board" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/Misc" -I"/home/andreas/Daten/source/avr/LUFA-120730/LUFA/Drivers/Peripheral" -D__AVR_ATmega32U2__=1 -U__AVR_ATmega16__ -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


