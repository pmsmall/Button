################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../button.c \
../cursor.c \
../enviroment.c \
../graphics.c \
../rgba.c \
../test.c 

OBJS += \
./button.o \
./cursor.o \
./enviroment.o \
./graphics.o \
./rgba.o \
./test.o 

C_DEPS += \
./button.d \
./cursor.d \
./enviroment.d \
./graphics.d \
./rgba.d \
./test.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


