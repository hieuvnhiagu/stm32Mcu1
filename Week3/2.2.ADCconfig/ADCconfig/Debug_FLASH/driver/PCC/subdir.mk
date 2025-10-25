################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../driver/PCC/PCC.c 

OBJS += \
./driver/PCC/PCC.o 

C_DEPS += \
./driver/PCC/PCC.d 


# Each subdirectory must supply rules for building sources it contributes
driver/PCC/%.o: ../driver/PCC/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@driver/PCC/PCC.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


