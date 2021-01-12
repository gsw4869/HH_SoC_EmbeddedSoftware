#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include <psu_init.h>
#include <xil_io.h>
#include <xuartps_hw.h>
#include "reset_test.h"
#include "xuartps.h"
#include "tx_fifo_trigger_level.h"


int tx_fifo_trigger_level_test(u16 DeviceId,char* a,char* b,int i,int level)
{
	int Status;
	XUartPs_Config *Config;
	unsigned int SentCount;
	unsigned int ReceivedCount;
	u16 Index;
	u32 LoopCount = 0;

	/*
	 * Initialize the UART driver so that it's ready to use.
	 * Look up the configuration in the config table, then initialize it.
	 */
	Config = XUartPs_LookupConfig(DeviceId);
	if (NULL == Config) {
		return XST_FAILURE;
	}

	Status = XUartPs_CfgInitialize(&Uart_PS, Config, Config->BaseAddress);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	/* Check hardware build. */
	Status = XUartPs_SelfTest(&Uart_PS);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}
	//PSU_Mask_Write(intrpt_dis_addr_1,0x400,0x400);//disable interrupt
	PSU_Mask_Write(Tx_FIFO_trigger_1,0x3F,level);//set trigger level

	sprintf(a,"\ni:%d\nBefore : Channel sts TTRIG : %d  Tx_FIFO_trigger_level : %d chan_int : %x",i,(Xil_In32(Chan_sts_1)&0x2000)>>13,Xil_In32(Tx_FIFO_trigger_1),Xil_In32(0xFF010014));

	XUartPs_SetOperMode(&Uart_PS, XUARTPS_OPER_MODE_REMOTE_LOOP);

	for(int t=0;t<i;t++)
	{
		XUartPs_WriteReg(0xFF010000,XUARTPS_FIFO_OFFSET,'*');
	}

	sprintf(b,"After : Channel sts TTRIG : %d  Tx_FIFO_trigger_level : %d chan_int : %x",(Xil_In32(Chan_sts_1)&0x2000)>>13,Xil_In32(Tx_FIFO_trigger_1),Xil_In32(0xFF010014));

	if((i>=level&&!(Xil_In32(Chan_sts_1)&0x2000))||(i<level&&(Xil_In32(Chan_sts_1)&0x2000)))
	{
		XUartPs_SetOperMode(&Uart_PS, XUARTPS_OPER_MODE_NORMAL);
		return XST_FAILURE;
	}
	PSU_Mask_Write(0xFF010014,0xFFFFFFFF,0xFFFFFFFF);

	XUartPs_SetOperMode(&Uart_PS, XUARTPS_OPER_MODE_NORMAL);


	return XST_SUCCESS;
}
