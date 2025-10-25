################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../driver/ADC/ADC.c 

OBJS += \
./driver/ADC/ADC.o 

C_DEPS += \
./driver/ADC/ADC.d 


# Each subdirectory must supply rules for building sources it contributes
driver/ADC/%.o: ../driver/ADC/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@driver/ADC/ADC.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


