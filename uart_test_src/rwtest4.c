#include <stdio.h>
#include <psu_init.h>
#include <xuartps_hw.h>
#include "rwtest.h"
#include "rwtest4.h"

void mode_rwtest()
{
	unsigned int addr=0xFF000004;
	unsigned int r1=Xil_In32(addr);
	printf("\nMode (UART) Register:\nReset value:0x%08x\n\n",r1);

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("Reserved value(31:14): %x\n",shownum(Xil_In32(addr),14,31));
	PSU_Mask_Write(addr, 0xFFFFC000U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),14,31));
	printf("Reserved value(changed): %x\n\n",shownum(Xil_In32(addr),14,31));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("WSIZE(13:12): %x\n",shownum(Xil_In32(addr),12,13));
	PSU_Mask_Write(addr, 0x00003000U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),12,13));
	printf("WSIZE(changed): %x\n\n",shownum(Xil_In32(addr),12,13));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("CHMODE(9:8): %x\n",shownum(Xil_In32(addr),8,9));
	PSU_Mask_Write(addr, 0x00000300U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),8,9));
	printf("Reserved value(changed): %x\n\n",shownum(Xil_In32(addr),8,9));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("NBSTOP(7:6): %x\n",shownum(Xil_In32(addr),6,7));
	PSU_Mask_Write(addr, 0x000000C0U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),6,7));
	printf("NBSTOP(changed): %x\n\n",shownum(Xil_In32(addr),6,7));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("PAR(5:3): %x\n",shownum(Xil_In32(addr),3,5));
	PSU_Mask_Write(addr, 0x00000038U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),3,5));
	printf("PAR(changed): %x\n\n",shownum(Xil_In32(addr),3,5));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("CHRL(2:1): %x\n",shownum(Xil_In32(addr),1,2));
	PSU_Mask_Write(addr, 0x00000006U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),1,2));
	printf("CHRL(changed): %x\n\n",shownum(Xil_In32(addr),1,2));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("CLKS(0): %x\n",shownum(Xil_In32(addr),0,0));
	PSU_Mask_Write(addr, 0x0000001U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),0,0));
	printf("CLKS(changed): %x\n\n",shownum(Xil_In32(addr),0,0));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);


}
void intrpt_en_rwtest()
{
	unsigned int addr=0xFF000008;
	unsigned int r1=Xil_In32(addr);
	printf("\nIntrpt_en (UART) Register:\nReset value:0x%08x\n\n",r1);

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
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
	printf("TIMEOUT(changed): %x\n\n",shownum(Xil_In32(addr),7,7));

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
	PSU_Mask_Write(addr, 0x4U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),1,1));
	printf("REMPTY(changed): %x\n\n",shownum(Xil_In32(addr),1,1));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("RTRIG(0): %x\n",shownum(Xil_In32(addr),0,0));
	PSU_Mask_Write(addr, 0x4U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),0,0));
	printf("RTRIG(changed): %x\n\n",shownum(Xil_In32(addr),0,0));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);


}

void intrpt_dis_rwtest()
{
	unsigned int addr=0xFF00000C;
	unsigned int r1=Xil_In32(addr);
	printf("\nIntrpt_dis (UART) Register:\nReset value:0x%08x\n\n",r1);

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
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
	printf("TIMEOUT(changed): %x\n\n",shownum(Xil_In32(addr),7,7));

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
	PSU_Mask_Write(addr, 0x4U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),1,1));
	printf("REMPTY(changed): %x\n\n",shownum(Xil_In32(addr),1,1));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);
	printf("RTRIG(0): %x\n",shownum(Xil_In32(addr),0,0));
	PSU_Mask_Write(addr, 0x4U, ~(r1));
	printf("set 0x%x\n",shownum(~(r1),0,0));
	printf("RTRIG(changed): %x\n\n",shownum(Xil_In32(addr),0,0));

	PSU_Mask_Write(addr,0xFFFFFFFFU,r1);

}

