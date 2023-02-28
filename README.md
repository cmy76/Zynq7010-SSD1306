# Zynq7010-SSD1306
A Zynq-Based SSD1306 OLED Driver
## 硬件准备
1. 使用Vivado 2022.1创建裸机工程，然后添加EMIO的I2C并MAKE EXTERNAL到Y17和Y16引脚。  
2. 设置Y17和Y16的电平水平为LVCMOS33，默认为PULLUP。  
3. 生成bit流文件，然后export hardware
## 软件准备
1. 新建helloworld工程。  
2. 导入OLED_Init.h文件。  
