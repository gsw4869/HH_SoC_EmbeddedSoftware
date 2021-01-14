#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include <psu_init.h>
#include <xil_io.h>
#include <xuartps_hw.h>
#include "reset_test.h"
#include "xuartps.h"
#include "baud_rate.h"
#include "regaddr.h"

static u8 SendBuffer[TEST_BUFFER_SIZE];	/* Buffer for Transmitting Data */
static u8 RecvBuffer[TEST_BUFFER_SIZE];	/* Buffer for Receiving Data */

int baud_rate_gen_test(u16 DeviceId,int baud_rate)
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
		SendBuffer[Index] = 0x55;
		RecvBuffer[Index] = 0;
	}

	//XUartPs_SetOperMode(&Uart_PS, XUARTPS_OPER_MODE_LOCAL_LOOP);

	PSU_Mask_Write(Baud_rate_gen_1, 0x0000FFFFU,XPAR_PSU_UART_1_UART_CLK_FREQ_HZ/baud_rate/7);
	PSU_Mask_Write(Baud_rate_divider_addr_1, 0xFFU, 0x6);


	for(i=0;i<=2000;i++)
	{
		/* Block sending the buffer. */
		SentCount = XUartPs_Send(&Uart_PS, SendBuffer, TEST_BUFFER_SIZE);
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

	}

	PSU_Mask_Write(Baud_rate_gen_1, 0x0000FFFFU,0x7c);
	PSU_Mask_Write(Baud_rate_divider_addr_1, 0xFFU, 0x6);

	return XST_SUCCESS;
}

int baud_rate_DIV_test(u16 DeviceId,int baud_rate)
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
			SendBuffer[Index] = 0x55;
			RecvBuffer[Index] = 0;
		}


		PSU_Mask_Write(Baud_rate_gen_1, 0x0000FFFFU,0x7c);
		PSU_Mask_Write(Baud_rate_divider_addr_1, 0xFFU, (XPAR_PSU_UART_1_UART_CLK_FREQ_HZ/0x7c/baud_rate)-1);


		for(i=0;i<=2000;i++)
		{
			/* Block sending the buffer. */
			SentCount = XUartPs_Send(&Uart_PS, SendBuffer, TEST_BUFFER_SIZE);
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

		}

		PSU_Mask_Write(Baud_rate_gen_1, 0x0000FFFFU,0x7c);
		PSU_Mask_Write(Baud_rate_divider_addr_1, 0xFFU, 0x6);

		return XST_SUCCESS;
}

void baud_rate_test()
{
	int mode=0;
	int baud_rate_gen=115200;
	int baud_rate_div=115200;
	printf("Please select test mode \n");
	scanf("%d",&mode);
	if(!mode)
	{
		  int Status;
		  printf("Baud rate gen test \n");
		  printf("Please select Baud rate(ex 38400 57600 115200) \n");
		  scanf("%d",&baud_rate_gen);
		  sleep(1);
		  Status = baud_rate_gen_test(XPAR_XUARTPS_1_DEVICE_ID,baud_rate_gen);
		  sleep(1);

		  if (Status == 0) {
			 print("\nComplete Baud rate gen test\r\n");
		  }
		  else {
			 print("\nBaud rate gen test failed\r\n");
		  }
	}
	else if(mode)
	{
		  int Status;
		  printf("Baud rate div test \n");
		  printf("Please select Baud rate(ex 38400 57600 115200) \n");
		  scanf("%d",&baud_rate_div);
		  sleep(1);

		  Status =  baud_rate_DIV_test(XPAR_XUARTPS_1_DEVICE_ID,baud_rate_div);;
		  sleep(1);

		  if (Status == 0) {
			 print("\nComplete Baud rate div test\r\n");
		  }
		  else {
			 print("\nBaud rate test div failed\r\n");
		  }
	}
}

void baud_test_combined(u16 DeviceId,int baud_rate,int BDIV)
{
	int Status;
	int i=0;
	int CD;
	u16 Index;
	u32 LoopCount = 0;
	unsigned int SentCount;

	XUartPs_Config *Config;

	unsigned int ReceivedCount;

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
		SendBuffer[Index] = 0x55;
		RecvBuffer[Index] = 0;
	}

	CD=(XPAR_PSU_UART_1_UART_CLK_FREQ_HZ/(BDIV+1)/baud_rate)-1;
	printf("%d\n",CD);
	while(1)
	{
		if(BDIV<=3)
		{
			printf("The value of BDIV should be greater than 3,please input BDIV again\n");
			scanf("%d",&BDIV);
		}
		else
		{
			break;
		}

	}
	sleep(1);
	PSU_Mask_Write(Baud_rate_gen_1, 0x0000FFFFU,CD);
	PSU_Mask_Write(Baud_rate_divider_addr_1, 0xFFU, BDIV);

	for(i=0;i<=1000;i++)
	{
		SentCount = XUartPs_Send(&Uart_PS, SendBuffer, TEST_BUFFER_SIZE);
		if (SentCount != TEST_BUFFER_SIZE) {
			return XST_FAILURE;
		}

		while (XUartPs_IsSending(&Uart_PS)) {
			LoopCount++;
		}
	}


	PSU_Mask_Write(Baud_rate_gen_1, 0x0000FFFFU,0x7c);
	PSU_Mask_Write(Baud_rate_divider_addr_1, 0xFFU, 0x6);
	printf("\n");
	sleep(1);
}
