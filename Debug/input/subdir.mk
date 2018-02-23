################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../input/ActionEvent.c \
../input/InputEvent.c 

OBJS += \
./input/ActionEvent.o \
./input/InputEvent.o 

C_DEPS += \
./input/ActionEvent.d \
./input/InputEvent.d 


# Each subdirectory must supply rules for building sources it contributes
input/%.o: ../input/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


