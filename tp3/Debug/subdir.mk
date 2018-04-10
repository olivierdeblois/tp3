################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Cheque.cpp \
../Client.cpp \
../Compte.cpp \
../ContratException.cpp \
../Date.cpp \
../Epargne.cpp \
../validationFormat.cpp 

OBJS += \
./Cheque.o \
./Client.o \
./Compte.o \
./ContratException.o \
./Date.o \
./Epargne.o \
./validationFormat.o 

CPP_DEPS += \
./Cheque.d \
./Client.d \
./Compte.d \
./ContratException.d \
./Date.d \
./Epargne.d \
./validationFormat.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


