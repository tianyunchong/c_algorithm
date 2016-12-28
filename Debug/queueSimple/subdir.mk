################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../queueSimple/queue.c 

OBJS += \
./queueSimple/queue.o 

C_DEPS += \
./queueSimple/queue.d 


# Each subdirectory must supply rules for building sources it contributes
queueSimple/%.o: ../queueSimple/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


