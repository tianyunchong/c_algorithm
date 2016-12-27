################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../multiStringMatch/ac/ac.c 

OBJS += \
./multiStringMatch/ac/ac.o 

C_DEPS += \
./multiStringMatch/ac/ac.d 


# Each subdirectory must supply rules for building sources it contributes
multiStringMatch/ac/%.o: ../multiStringMatch/ac/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


