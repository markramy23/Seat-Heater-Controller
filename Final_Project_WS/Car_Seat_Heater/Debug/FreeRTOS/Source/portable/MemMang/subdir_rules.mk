################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/Source/portable/MemMang/%.obj: ../FreeRTOS/Source/portable/MemMang/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1260/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="E:/Courses/RTOS/Final Project/Final_Project_WS/Car_Seat_Heater" --include_path="E:/Courses/RTOS/Final Project/Final_Project_WS/Car_Seat_Heater/HAL" --include_path="E:/Courses/RTOS/Final Project/Final_Project_WS/Car_Seat_Heater/HAL/RGB Led" --include_path="E:/Courses/RTOS/Final Project/Final_Project_WS/Car_Seat_Heater/HAL/Temp Sensor" --include_path="E:/Courses/RTOS/Final Project/Final_Project_WS/Car_Seat_Heater/MCAL/ADC" --include_path="E:/Courses/RTOS/Final Project/Final_Project_WS/Car_Seat_Heater/HAL" --include_path="E:/Courses/RTOS/Final Project/Final_Project_WS/Car_Seat_Heater/Common" --include_path="E:/Courses/RTOS/Final Project/Final_Project_WS/Car_Seat_Heater/FreeRTOS/Source/include" --include_path="E:/Courses/RTOS/Final Project/Final_Project_WS/Car_Seat_Heater/FreeRTOS/Source/portable/CCS/ARM_CM4F" --include_path="E:/Courses/RTOS/Final Project/Final_Project_WS/Car_Seat_Heater/MCAL" --include_path="E:/Courses/RTOS/Final Project/Final_Project_WS/Car_Seat_Heater/MCAL/GPIO" --include_path="E:/Courses/RTOS/Final Project/Final_Project_WS/Car_Seat_Heater/MCAL/GPTM" --include_path="E:/Courses/RTOS/Final Project/Final_Project_WS/Car_Seat_Heater/MCAL/UART" --include_path="C:/ti/ccs1260/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="FreeRTOS/Source/portable/MemMang/$(basename $(<F)).d_raw" --obj_directory="FreeRTOS/Source/portable/MemMang" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


