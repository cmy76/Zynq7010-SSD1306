# Zynq7010-SSD1306
A Zynq-Based SSD1306 OLED Driver
## 硬件准备
1. 使用Vivado 2022.1创建裸机工程，然后添加EMIO的I2C并MAKE EXTERNAL到Y17和Y16引脚。  
2. 设置Y17和Y16的电平水平为LVCMOS33，默认为PULLUP。  
3. 生成bit流文件，然后export hardware
## 软件准备
1. 新建空工程。  
2. 导入OLED_Init.h和.c文件。 

## Hardware Preparation
1. Create a bare-metal project using Vivado 2022.1 and add EMIO I2C with MAKE EXTERNAL to pins Y17 and Y16.
2. Set the voltage level of pins Y17 and Y16 to LVCMOS33 with PULLUP as default.
3. Generate the bitstream file and export hardware.

## Software Preparation
1. Create a new empty project.
2. Import OLED_Init.h and .c files.
