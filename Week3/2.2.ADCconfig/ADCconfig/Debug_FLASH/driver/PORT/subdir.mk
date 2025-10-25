################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../driver/PORT/PORT.c 

OBJS += \
./driver/PORT/PORT.o 

C_DEPS += \
./driver/PORT/PORT.d 


# Each subdirectory must supply rules for building sources it contributes
driver/PORT/%.o: ../driver/PORT/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@driver/PORT/PORT.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


