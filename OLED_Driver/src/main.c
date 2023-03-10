/******************************************************************************
*
* Copyright (C) 2009 - 2014 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* Use of the Software is limited solely to applications:
* (a) running on a Xilinx device, or
* (b) that interact with a Xilinx device through a bus or interconnect.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
*
******************************************************************************/

/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

#include <stdio.h>
#include "xil_printf.h"
#include "xiicps.h"
#include "sleep.h"
#include "OLED_init.h"


#define IIC_DEV_ID 			XPAR_PS7_I2C_0_DEVICE_ID
#define IIC_RATE 			200000
#define SLAVE_ADDR			0x40


#define MODE1				0
#define PRESCALE			254


static 	XIicPs IicPs;
static 	XIicPs_Config * IicPs_Cfg;

int initIic();
s32 writeReg(XIicPs * iicPs, u16 slaveAddr, u8 * Cfg_Ptr);
void OLED_DisplayTest(XIicPs * iicPs);
int main()
{
    s32 status = initIic();
    if(status == XST_SUCCESS)
    	print("Init success");
    else
    	print("Failed");
    while(1){
    	OLED_DisplayTest(&IicPs);
    }
    return 0;
}

void OLED_DisplayTest(XIicPs * iicPs)
{
	OLED_Clear(iicPs);
	OLED_ShowChar(iicPs, 1,4,'e',8);
	//OLED_ShowChar(iicPs, 1,1,'e',16);
	//OLED_ShowChar(iicPs, 1,2,'l',16);
	//OLED_ShowChar(iicPs, 1,3,'l',16);
	//OLED_ShowChar(iicPs, 1,4,'o',16);
	//OLED_ShowString(iicPs, 0,4,(char *)("LoRa stm32 gd32 "),16);
	//OLED_ShowString(iicPs, 0,6,(char *)("esp32...IoT."),16);
}

int initIic()
{
	int status;
	// 1.????IIC????
	IicPs_Cfg = XIicPs_LookupConfig(IIC_DEV_ID);
	// 2.??????
	status = XIicPs_CfgInitialize(&IicPs, IicPs_Cfg, IicPs_Cfg->BaseAddress);
	if(status != XST_SUCCESS)
	{
		print("initial IIC failed \n");
		return XST_FAILURE;
	}
	//????IIC????
	status = XIicPs_SetSClk(&IicPs, IIC_RATE);
	if(status != XST_SUCCESS)
	{
		print("set IIC clock rate failed \n");
		return XST_FAILURE;
	}
	OLED_Init(&IicPs);
	return XST_SUCCESS;
}
