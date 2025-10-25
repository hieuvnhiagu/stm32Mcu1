################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../driver/GPIO/GPIO.c 

OBJS += \
./driver/GPIO/GPIO.o 

C_DEPS += \
./driver/GPIO/GPIO.d 


# Each subdirectory must supply rules for building sources it contributes
driver/GPIO/%.o: ../driver/GPIO/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@driver/GPIO/GPIO.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


