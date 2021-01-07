#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include <psu_init.h>
#include <xil_io.h>
#include <xuartps_hw.h>
#include "reset_test.h"

void reset_all(unsigned int *res)
{

	res[0]=Xil_In32(Con_Reg);
	res[1]=Xil_In32(Mode_Reg);
	res[2]=Xil_In32(Intr_Reg);
	res[3]=Xil_In32(Intr_dis);
	res[4]=Xil_In32(Intr_mask);
	res[5]=Xil_In32(Chnl_int);
	res[6]=Xil_In32(Baud_gen);
	res[7]=Xil_In32(Rcvr_time);
	res[8]=Xil_In32(Rcvr_FIFO_tri);
	res[9]=Xil_In32(Chan_sts);
	res[10]=Xil_In32(TX_RX_FIFO);
	res[11]=Xil_In32(Baud_div);
	res[12]=Xil_In32(Tx_FIFO);
	res[13]=Xil_In32(Rx_FIFO_stat);

}

void print_reset(unsigned int *res)
{
	printf("Reset value:\n\n");
	printf("Control (UART) Register's reset value is:0x%08x\n\n",res[0]);
	printf("Mode (UART) Register's reset value is:0x%08x\n\n",res[1]);
	printf("Intrpt_en (UART) Register's reset value is:0x%08x\n\n",res[2]);
	printf("Intrpt_dis (UART) Register's reset value is:0x%08x\n\n",res[3]);
	printf("Intrpt_mask (UART) Register's reset value is:0x%08x\n\n",res[4]);
	printf("Chnl_int_sts (UART) Register's reset value is:0x%08x\n\n",res[5]);
	printf("Baud_rate_gen (UART) Register's reset value is:0x%08x\n\n",res[6]);
	printf("Rcvr_timeout (UART) Register's reset value is:0x%08x\n\n",res[7]);
	printf("Rcvr_FIFO_trigger_level (UART) Register's reset value is:0x%08x\n\n",res[8]);
	printf("Channel_sts (UART) Register's reset value is:0x%08x\n\n",res[9]);
	printf("TX_RX_FIFO (UART) Register's reset value is:0x%08x\n\n",res[10]);
	printf("Baud_rate_divider (UART) Register's reset value is:0x%08x\n\n",res[11]);
	printf("Tx_FIFO_trigger_level (UART) Register's reset value is:0x%08x\n\n",res[12]);
	printf("Rx_FIFO_byte_status (UART) Register's reset value is:0x%08x\n\n",res[13]);

}
