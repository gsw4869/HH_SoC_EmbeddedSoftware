#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include <psu_init.h>
#include <xil_io.h>
#include <xuartps_hw.h>
#include "reset_test.h"
#include "xuartps.h"
#include "regaddr.h"
#include "control_test.h"

static u8 SendBuffer1[TEST_BUFFER_SIZE];
static u8 SendBuffer2[TEST_BUFFER_SIZE];
static u8 SendBuffer3[TEST_BUFFER_SIZE];
static u8 SendBuffer4[TEST_BUFFER_SIZE];/* Buffer for Transmitting Data */
static u8 RecvBuffer[TEST_BUFFER_SIZE];	/* Buffer for Receiving Data */

int trans_test(u16 DeviceId)
{
	int Status;
	XUartPs_Config *Config;
	unsigned int SentCount;
	unsigned int ReceivedCount;
	u16 Index;
	u32 LoopCount = 0;
	int i=0;
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

	for (Index = 0; Index < TEST_BUFFER_SIZE; Index++) {
		SendBuffer1[Index] = '1';
		SendBuffer2[Index] = '2';
		SendBuffer3[Index] = '3';
		SendBuffer4[Index] = '4';
	}

	XUartPs_SetOperMode(&Uart_PS, XUARTPS_OPER_MODE_NORMAL);
	printf("function start\n");
	sleep(1);

	PSU_Mask_Write(Control_addr_1, 0x30U,0x20U); //10
	{
		SentCount = XUartPs_Send(&Uart_PS, SendBuffer1, TEST_BUFFER_SIZE);
	}
	sleep(1);

	PSU_Mask_Write(Control_addr_1, 0x30U,0x30U); //11
	{
		SentCount = XUartPs_Send(&Uart_PS, SendBuffer2, TEST_BUFFER_SIZE);
	}
	sleep(1);

	PSU_Mask_Write(Control_addr_1, 0x30U,0x00U); //00
	{
		SentCount = XUartPs_Send(&Uart_PS, SendBuffer3, TEST_BUFFER_SIZE);
	}
	sleep(1);

	PSU_Mask_Write(Control_addr_1, 0x30U,0x10U); //01,enable transmitter
	{
		SentCount = XUartPs_Send(&Uart_PS, SendBuffer4, TEST_BUFFER_SIZE);
	}
}

int recv_test(u16 DeviceId,int num)
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

	/* Use local loopback mode. */
	XUartPs_SetOperMode(&Uart_PS, XUARTPS_OPER_MODE_LOCAL_LOOP);
	PSU_Mask_Write(Control_addr_1, 0xcU,0x4U);

	/*
	 * Initialize the send buffer bytes with a pattern and zero out
	 * the receive buffer.
	 */
	for (Index = 0; Index < TEST_BUFFER_SIZE; Index++) {
		SendBuffer1[Index] = '0' + Index;
		RecvBuffer[Index] = 0;
	}

	/* Block sending the buffer. */
	SentCount = XUartPs_Send(&Uart_PS, SendBuffer1, TEST_BUFFER_SIZE);
	if (SentCount != TEST_BUFFER_SIZE) {
		return XST_FAILURE;
	}

	/*
	 * Wait while the UART is sending the data so that we are guaranteed
	 * to get the data the 1st time we call receive, otherwise this function
	 * may enter receive before the data has arrived
	 */
	while (XUartPs_IsSending(&Uart_PS)) {
		LoopCount++;
	}


	/* Block receiving the buffer. */
	ReceivedCount = 0;
	while (ReceivedCount < TEST_BUFFER_SIZE) {
		if(ReceivedCount==num)
		{
			PSU_Mask_Write(Control_addr_1, 0xcU,0x8U);//disable receiver
		}
		RecvBuffer[ReceivedCount]=XUartPs_ReadReg(0xFF010000, XUARTPS_FIFO_OFFSET);
		ReceivedCount++;

	}




	/*
	 * Check the receive buffer against the send buffer and verify the
	 * data was correctly received
//	 */

	for (Index = 0; Index < num; Index++) {
		if (SendBuffer1[Index] != RecvBuffer[Index]) {
			XUartPs_SetOperMode(&Uart_PS, XUARTPS_OPER_MODE_NORMAL);
			return XST_FAILURE;
		}
	}


	/* Restore to normal mode. */
	XUartPs_SetOperMode(&Uart_PS, XUARTPS_OPER_MODE_NORMAL);

	printf("recv_data(local loopback):\n ");
	usleep(1000);

	SentCount = XUartPs_Send(&Uart_PS, RecvBuffer,TEST_BUFFER_SIZE);
	if (SentCount != TEST_BUFFER_SIZE) {
		return XST_FAILURE;
	}

	/*
	 * Wait while the UART is sending the data so that we are guaranteed
	 * to get the data the 1st time we call receive, otherwise this function
	 * may enter receive before the data has arrived
	 */
	while (XUartPs_IsSending(&Uart_PS)) {
		LoopCount++;
	}


	return XST_SUCCESS;

}
