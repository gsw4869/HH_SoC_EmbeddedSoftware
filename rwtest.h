#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include <psu_init.h>
#include <xil_io.h>
#include <xuartps_hw.h>

#define Chan_sts 0xFF00002C
#define Intrpt_mask 0xFF000010
#define Baud_rate_gen 0xFF000018
#define Tx_FIFO_trigger 0xFF000044

unsigned int shownum(unsigned int num,int pos1,int pos2)
{
	return (num<<(31-pos2))>>(31-pos2+pos1);
}
void control_rwtest()
{
	unsigned int addr=UART0_CONTROL_REG0_OFFSET;
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

}

void bdiv_rwtest()
{
	unsigned int addr=0xFF000034;
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
}

void byte_status_rwtest()
{
	unsigned int addr=0xFF000048;
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

}

void Chnl_int_sts_rwtest()
{
	unsigned int addr=0xFF000014;
	unsigned int r1=Xil_In32(addr);
	printf("\nChnl_int_sts (UART) Register:\nReset value:0x%08x\n\n",r1);

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("Write in same reset value:\nResult:0x%08x\n\n",Xil_In32(addr));

	printf("Reserved value(31:14): %x\n",shownum(Xil_In32(addr),14,31));
	PSU_Mask_Write(addr, 0xFFFFC000U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),14,31));
	printf("Reserved value(changed): %x\n\n",shownum(Xil_In32(addr),14,31));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("RBRK(13): %x\n",shownum(Xil_In32(addr),13,13));
	PSU_Mask_Write(addr, 0x2000U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),13,13));
	printf("RBRK(changed): %x\n\n",shownum(Xil_In32(addr),13,13));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("TOVR(12): %x\n",shownum(Xil_In32(addr),12,12));
	PSU_Mask_Write(addr, 0x1000U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),12,12));
	printf("TOVR(changed): %x\n\n",shownum(Xil_In32(addr),12,12));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("TNFUL(11): %x\n",shownum(Xil_In32(addr),11,11));
	PSU_Mask_Write(addr, 0x800U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),11,11));
	printf("TNFUL(changed): %x\n\n",shownum(Xil_In32(addr),11,11));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("TTRIG(10): %x\n",shownum(Xil_In32(addr),10,10));
	PSU_Mask_Write(addr, 0x400U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),10,10));
	printf("TTRIG(changed): %x\n\n",shownum(Xil_In32(addr),10,10));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("DMSI(9): %x\n",shownum(Xil_In32(addr),9,9));
	PSU_Mask_Write(addr, 0x200U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),9,9));
	printf("DMSI(changed): %x\n\n",shownum(Xil_In32(addr),9,9));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("TIMEOUT(8): %x\n",shownum(Xil_In32(addr),8,8));
	PSU_Mask_Write(addr, 0x100U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),8,8));
	printf("TIMEOUT(changed): %x\n\n",shownum(Xil_In32(addr),8,8));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("PARE(7): %x\n",shownum(Xil_In32(addr),7,7));
	PSU_Mask_Write(addr, 0x80U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),7,7));
	printf("PARE(changed): %x\n\n",shownum(Xil_In32(addr),7,7));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("FRAME(6): %x\n",shownum(Xil_In32(addr),6,6));
	PSU_Mask_Write(addr, 0x40U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),6,6));
	printf("FRAME(changed): %x\n\n",shownum(Xil_In32(addr),6,6));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("ROVR(5): %x\n",shownum(Xil_In32(addr),5,5));
	PSU_Mask_Write(addr, 0x20U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),5,5));
	printf("ROVR(changed): %x\n\n",shownum(Xil_In32(addr),5,5));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("TFUL(4): %x\n",shownum(Xil_In32(addr),4,4));
	PSU_Mask_Write(addr, 0x10U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),4,4));
	printf("TFUL(changed): %x\n\n",shownum(Xil_In32(addr),4,4));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("TEMPTY(3): %x\n",shownum(Xil_In32(addr),3,3));
	PSU_Mask_Write(addr, 0x8U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),3,3));
	printf("TEMPTY(changed): %x\n\n",shownum(Xil_In32(addr),3,3));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("RFUL(2): %x\n",shownum(Xil_In32(addr),2,2));
	PSU_Mask_Write(addr, 0x4U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),2,2));
	printf("RFUL(changed): %x\n\n",shownum(Xil_In32(addr),2,2));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("REMPTY(1): %x\n",shownum(Xil_In32(addr),1,1));
	PSU_Mask_Write(addr, 0x2U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),1,1));
	printf("REMPTY(changed): %x\n\n",shownum(Xil_In32(addr),1,1));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("RTRIG(0): %x\n",shownum(Xil_In32(addr),0,0));
	PSU_Mask_Write(addr, 0x1U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),0,0));
	printf("RTRIG(changed): %x\n\n",shownum(Xil_In32(addr),0,0));
}

void Rcvr_timeout_rwtest()
{
	unsigned int addr=0xFF00001C;
	unsigned int r1=Xil_In32(addr);
	printf("\nRcvr_timeout (UART) Register:\nReset value:0x%08x\n\n",r1);

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("Reserved value(31:8): %x\n",shownum(Xil_In32(addr),8,31));
	PSU_Mask_Write(addr, 0xFFFFFF00U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),8,31));
	printf("Reserved value(changed): %x\n\n",shownum(Xil_In32(addr),8,31));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("RTO(7:0): %x\n",shownum(Xil_In32(addr),0,7));
	PSU_Mask_Write(addr, 0xFFU, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),0,7));
	printf("RTO(changed): %x\n\n",shownum(Xil_In32(addr),0,7));

}

void Rcvr_FIFO_trigger_level_rwtest()
{
	unsigned int addr=0xFF000020;
	unsigned int r1=Xil_In32(addr);
	printf("\nRcvr_FIFO_trigger_level (UART) Register:\nReset value:0x%08x\n\n",r1);

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("Reserved value(31:6): %x\n",shownum(Xil_In32(addr),6,31));
	PSU_Mask_Write(addr, 0xFFFFFFC0U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),6,31));
	printf("Reserved value(changed): %x\n\n",shownum(Xil_In32(addr),6,31));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("RTRIG(5:0): %x\n",shownum(Xil_In32(addr),0,5));
	PSU_Mask_Write(addr, 0x3FU, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),0,5));
	printf("RTRIG(changed): %x\n\n",shownum(Xil_In32(addr),0,5));
}



void Chan_sts_test()
{
	unsigned int addr=Chan_sts;
	unsigned int r1=Xil_In32(addr);
	printf("\nChan_sts:\nReset value:0x%08x\n\n",r1);

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("Reserved value(31:15): 0x%x\n",shownum(Xil_In32(addr),15,31));
	PSU_Mask_Write(addr, 0xFFFF8000U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),15,31));
	printf("Reserved value(changed): 0x%x\n\n",shownum(Xil_In32(addr),15,31));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("TNFUL(14): 0x%x\n",shownum(Xil_In32(addr),14,14));
	PSU_Mask_Write(addr, 0x4000U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),14,14));
	printf("TNFUL(changed): 0x%x\n\n",shownum(Xil_In32(addr),14,14));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("TTRIG(13): 0x%x\n",shownum(Xil_In32(addr),13,13));
	PSU_Mask_Write(addr, 0x2000U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),13,13));
	printf("TTRIG(changed): 0x%x\n\n",shownum(Xil_In32(addr),13,13));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("FDELT(12): 0x%x\n",shownum(Xil_In32(addr),12,12));
	PSU_Mask_Write(addr, 0x1000U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),12,12));
	printf("FDELT(changed): 0x%x\n\n",shownum(Xil_In32(addr),12,12));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("TACTIVE(11): 0x%x\n",shownum(Xil_In32(addr),11,11));
	PSU_Mask_Write(addr, 0x800U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),11,11));
	printf("TACTIVE(changed): 0x%x\n\n",shownum(Xil_In32(addr),11,11));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("RACTIVE(10): 0x%x\n",shownum(Xil_In32(addr),10,10));
	PSU_Mask_Write(addr, 0x400U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),10,10));
	printf("RACTIVE(changed): 0x%x\n\n",shownum(Xil_In32(addr),10,10));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("TFUL(4): 0x%x\n",shownum(Xil_In32(addr),4,4));
	PSU_Mask_Write(addr, 0x10U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),4,4));
	printf("TFUL(changed): 0x%x\n\n",shownum(Xil_In32(addr),4,4));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("TEMPTY(3): 0x%x\n",shownum(Xil_In32(addr),3,3));
	PSU_Mask_Write(addr, 0x8U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),3,3));
	printf("TEMPTY(changed): 0x%x\n\n",shownum(Xil_In32(addr),3,3));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("RFUL(2): 0x%x\n",shownum(Xil_In32(addr),2,2));
	PSU_Mask_Write(addr, 0x4U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),2,2));
	printf("RFUL(changed): 0x%x\n\n",shownum(Xil_In32(addr),2,2));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("REMPTY(1): 0x%x\n",shownum(Xil_In32(addr),1,1));
	PSU_Mask_Write(addr, 0x2U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),1,1));
	printf("REMPTY(changed): 0x%x\n\n",shownum(Xil_In32(addr),1,1));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("RTRIG(0): 0x%x\n",shownum(Xil_In32(addr),0,0));
	PSU_Mask_Write(addr, 0x1U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),0,0));
	printf("RTRIG(changed): 0x%x\n\n",shownum(Xil_In32(addr),0,0));
}

void Intrpt_mask_test()
{
	unsigned int addr=Intrpt_mask;
	unsigned int r1=Xil_In32(addr);
	printf("\nIntrpt_mask:\nReset value:0x%08x\n\n",r1);

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("Reserved value(31:14): 0x%x\n",shownum(Xil_In32(addr),14,31));
	PSU_Mask_Write(addr, 0xFFFFC000U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),14,31));
	printf("Reserved value(changed): 0x%x\n\n",shownum(Xil_In32(addr),14,31));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("RBRK(13): 0x%x\n",shownum(Xil_In32(addr),13,13));
	PSU_Mask_Write(addr, 0x2000U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),13,13));
	printf("RBRK(changed): 0x%x\n\n",shownum(Xil_In32(addr),13,13));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("TOVR(12): 0x%x\n",shownum(Xil_In32(addr),12,12));
	PSU_Mask_Write(addr, 0x1000U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),12,12));
	printf("TOVR(changed): 0x%x\n\n",shownum(Xil_In32(addr),12,12));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("TNFUL(11): 0x%x\n",shownum(Xil_In32(addr),11,11));
	PSU_Mask_Write(addr, 0x800U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),11,11));
	printf("TNFUL(changed): 0x%x\n\n",shownum(Xil_In32(addr),11,11));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("TTRIG(10): 0x%x\n",shownum(Xil_In32(addr),10,10));
	PSU_Mask_Write(addr, 0x400U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),10,10));
	printf("TTRIG(changed): 0x%x\n\n",shownum(Xil_In32(addr),10,10));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("DMSI(9): 0x%x\n",shownum(Xil_In32(addr),9,9));
	PSU_Mask_Write(addr, 0x200U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),9,9));
	printf("DMSI(changed): 0x%x\n\n",shownum(Xil_In32(addr),9,9));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("TIMEOUT(8): 0x%x\n",shownum(Xil_In32(addr),8,8));
	PSU_Mask_Write(addr, 0x100U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),8,8));
	printf("TIMEOUT(changed): 0x%x\n\n",shownum(Xil_In32(addr),8,8));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("PARE(7): 0x%x\n",shownum(Xil_In32(addr),7,7));
	PSU_Mask_Write(addr, 0x80U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),7,7));
	printf("PARE(changed): 0x%x\n\n",shownum(Xil_In32(addr),7,7));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("FRAME(6): 0x%x\n",shownum(Xil_In32(addr),6,6));
	PSU_Mask_Write(addr, 0x40U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),6,6));
	printf("FRAME(changed): 0x%x\n\n",shownum(Xil_In32(addr),6,6));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("ROVR(5): 0x%x\n",shownum(Xil_In32(addr),5,5));
	PSU_Mask_Write(addr, 0x20U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),5,5));
	printf("ROVR(changed): 0x%x\n\n",shownum(Xil_In32(addr),5,5));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("TFUL(4): 0x%x\n",shownum(Xil_In32(addr),4,4));
	PSU_Mask_Write(addr, 0x10U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),4,4));
	printf("TFUL(changed): 0x%x\n\n",shownum(Xil_In32(addr),4,4));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("TEMPTY(3): 0x%x\n",shownum(Xil_In32(addr),3,3));
	PSU_Mask_Write(addr, 0x8U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),3,3));
	printf("TEMPTY(changed): 0x%x\n\n",shownum(Xil_In32(addr),3,3));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("RFUL(2): 0x%x\n",shownum(Xil_In32(addr),2,2));
	PSU_Mask_Write(addr, 0x4U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),2,2));
	printf("RFUL(changed): 0x%x\n\n",shownum(Xil_In32(addr),2,2));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("REMPTY(1): 0x%x\n",shownum(Xil_In32(addr),1,1));
	PSU_Mask_Write(addr, 0x2U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),1,1));
	printf("REMPTY(changed): 0x%x\n\n",shownum(Xil_In32(addr),1,1));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("RTRIG(0): 0x%x\n",shownum(Xil_In32(addr),0,0));
	PSU_Mask_Write(addr, 0x1U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),0,0));
	printf("RTRIG(changed): 0x%x\n\n",shownum(Xil_In32(addr),0,0));
}

void Baud_rate_gen_test()
{
	unsigned int addr=Baud_rate_gen;
	unsigned int r1=Xil_In32(addr);
	printf("\nBaud_rate_gen:\nReset value:0x%08x\n\n",r1);

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("Reserved value(31:16): 0x%x\n",shownum(Xil_In32(addr),16,31));
	PSU_Mask_Write(addr, 0xFFFF0000U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),16,31));
	printf("Reserved value(changed): 0x%x\n\n",shownum(Xil_In32(addr),16,31));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("CD(15:0): 0x%x\n",shownum(Xil_In32(addr),0,15));
	PSU_Mask_Write(addr, 0x0000FFFFU, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),0,15));
	printf("Reserved value(changed): 0x%x\n\n",shownum(Xil_In32(addr),0,15));
}

void Tx_FIFO_trigger_test()
{
	unsigned int addr=Tx_FIFO_trigger;
	unsigned int r1=Xil_In32(addr);
	printf("\nTx_FIFO_trigger:\nReset value:0x%08x\n\n",r1);

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("Reserved value(31:6): 0x%x\n",shownum(Xil_In32(addr),6,31));
	PSU_Mask_Write(addr, 0xFFFFFFC0U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),6,31));
	printf("Reserved value(changed): 0x%x\n\n",shownum(Xil_In32(addr),6,31));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("TTRIG(5:0): 0x%x\n",shownum(Xil_In32(addr),0,5));
	PSU_Mask_Write(addr, 0x3FU, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),0,5));
	printf("TTRIG(changed): 0x%x\n\n",shownum(Xil_In32(addr),0,5));
}

void TX_RX_FIFO_test()
{
	unsigned int addr=0xFF000030;
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

}

