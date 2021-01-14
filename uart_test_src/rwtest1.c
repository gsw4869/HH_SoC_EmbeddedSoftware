#include <stdio.h>
#include <psu_init.h>
#include <xuartps_hw.h>
#include "rwtest.h"
#include "rwtest1.h"

void control_rwtest()
{
	unsigned int addr=Control_addr;
	unsigned int r1=Xil_In32(addr);
	printf("\nControl (UART) Register:\nReset value:0x%08x\n\n",r1);

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("Reserved value(31:9): 0x%x\n",shownum(Xil_In32(addr),9,31));
	PSU_Mask_Write(addr, 0xFFFFFE00U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),9,31));
	printf("Reserved value(changed): 0x%x\n\n",shownum(Xil_In32(addr),9,31));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("STPBRK value(8,7): 0x%x\n",shownum(Xil_In32(addr),7,8));
	PSU_Mask_Write(addr, 0x180U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),7,8));
	printf("STPBRK value(changed): 0x%x\n\n",shownum(Xil_In32(addr),7,8));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("RSTTO value(6): 0x%x\n",shownum(Xil_In32(addr),6,6));
	PSU_Mask_Write(addr, 0x40U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),6,6));
	printf("STPBRK value(changed): 0x%x\n\n",shownum(Xil_In32(addr),6,6));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("TXDIS value(5,4): 0x%x\n",shownum(Xil_In32(addr),4,5));
	PSU_Mask_Write(addr, 0x30U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),4,5));
	printf("TXDIS value(changed): 0x%x\n\n",shownum(Xil_In32(addr),4,5));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("RXDIS value(3,2): 0x%x\n",shownum(Xil_In32(addr),2,3));
	PSU_Mask_Write(addr, 0xCU, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),2,3));
	printf("RXDIS value(changed): 0x%x\n\n",shownum(Xil_In32(addr),2,3));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("TXRES value(1): 0x%x\n",shownum(Xil_In32(addr),1,1));
	PSU_Mask_Write(addr, 0x2U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),1,1));
	printf("TXRES value(changed): 0x%x\n\n",shownum(Xil_In32(addr),1,1));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("RXRES value(0): 0x%x\n",shownum(Xil_In32(addr),0,0));
	PSU_Mask_Write(addr, 0x1U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),0,0));
	printf("RXRES value(changed): 0x%x\n\n",shownum(Xil_In32(addr),0,0));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);

}

void bdiv_rwtest()
{
	unsigned int addr=Baud_rate_divider_addr;
	unsigned int r1=Xil_In32(addr);
	printf("\nBaud_rate_divider (UART) Register:\nReset value:0x%08x\n\n",r1);

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("Reserved value(31:8): %x\n",shownum(Xil_In32(addr),8,31));
	PSU_Mask_Write(addr, 0xFFFFFF00U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),8,31));
	printf("Reserved value(changed): %x\n\n",shownum(Xil_In32(addr),8,31));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("BDIV(7:0): %x\n",shownum(Xil_In32(addr),0,7));
	PSU_Mask_Write(addr, 0xFFU, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),0,7));
	printf("BDIV(changed): %x\n\n",shownum(Xil_In32(addr),0,7));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);

}

void byte_status_rwtest()
{
	unsigned int addr=Rx_FIFO_byte_status_addr;
	unsigned int r1=Xil_In32(addr);
	printf("\nRx_FIFO_byte_status (UART) Register:\nReset value:0x%08x\n\n",r1);

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("Reserved value(31:12): %x\n",shownum(Xil_In32(addr),12,31));
	PSU_Mask_Write(addr, 0xFFFFF000U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),12,31));
	printf("Reserved value(changed): %x\n\n",shownum(Xil_In32(addr),12,31));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("byte_status(11:0): %x\n",shownum(Xil_In32(addr),0,11));
	PSU_Mask_Write(addr, 0xFFFU, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),0,11));
	printf("byte_status(changed): %x\n\n",shownum(Xil_In32(addr),0,11));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);


}

void TX_RX_FIFO_test()
{
	unsigned int addr=FIFO_addr;
	unsigned int r1=Xil_In32(addr);
	printf("\nTX_RX_FIFO:\nReset value:0x%08x\n\n",r1);

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("Reserved value(31:8): 0x%x\n",shownum(Xil_In32(addr),8,31));
	PSU_Mask_Write(addr, 0xFFFFFF00U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),8,31));
	printf("Reserved value(changed): 0x%x\n\n",shownum(Xil_In32(addr),8,31));


	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("FIFO(7:0): 0x%x\n",shownum(Xil_In32(addr),0,7));
	PSU_Mask_Write(addr, 0xFFU, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),0,7));
	printf("FIFO(changed): 0x%x\n\n",shownum(Xil_In32(addr),0,7));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);


}
