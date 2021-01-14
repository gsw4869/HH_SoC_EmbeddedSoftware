#include "mode_switch.h"

#include <stdio.h>
#include <psu_init.h>
#include <xuartps_hw.h>
#include "includelib.h"



void normal_test()
{
	char recv_buff[100];
	PSU_Mask_Write(0xFF010004,0x300U,0x000U);
	scanf("%s",recv_buff);
	printf("%s\n\n",recv_buff);
	PSU_Mask_Write(0xFF010004, 0x300U, 0x000);
}

void remote_loop_test()
{
	PSU_Mask_Write(0xFF010004,0x300U,0x300U);
	sleep(20);
	PSU_Mask_Write(0xFF010004, 0x300U, 0x000);
	printf("\n");
}
void local_loop_test()
{

	unsigned int addr=0xFF010004;
	int i=0;
	int count=0;
	int auok=1;
	char send_buff[8]="abcdefg";
	char recv_buff[8];
	PSU_Mask_Write(addr, 0x300U, 0x200);
	recv_buff[0]=inbyte();
	for(i=0;i<=7;i++)
	{
		outbyte(send_buff[i]);
		recv_buff[i]=inbyte();
	}
	PSU_Mask_Write(addr, 0x300U, 0x000);
	printf("value: %s\n",recv_buff);
	for(i=0;i<=7;i++)
	{
		if(send_buff[i]==recv_buff[i])
		{
			auok=1;
		}
		else
		{
			auok=0;
		}
	}
	if(auok==1)
	{
		printf("Local loop test is ok\n\n");
	}
	else
	{
		printf("Local loop test is wrong\n\n");
	}
}

void automatic_echo_test()
{
	PSU_Mask_Write(0xFF010004,0x300U,0x100U);
	char rcv_buffer[100];
	scanf("%s",rcv_buffer);
	PSU_Mask_Write(0xFF010004,0x300U,0x00U);
	sleep(1);
	printf("\nreceive value  %s\n\n",rcv_buffer);

}
