#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include <psu_init.h>
#include <xil_io.h>

#include "includelib.h"



int main()
{
//	init_platform();


	char a[100];
	char b[100];
	int level=-1;
	int status;
	int fail_count=0;

	while(level<0|level>63)
	{
		printf("input tx fifo trigger level\nTrigger set when transmitter FIFO fills to TTRIG bytes\n");
		scanf("%d",&level);
	}
	for(int i=1;i<70;i++)
	{
		status=tx_fifo_trigger_level_test(XPAR_XUARTPS_1_DEVICE_ID,a,b,i,level);
		printf("%s\n%s\n",a,b);
		if(!status)
		{
			printf("Success\n\n");
		}
		else
		{
			fail_count++;
			printf("Fail\n\n");
		}
		usleep(100000);
	}
	if(fail_count)
	{
		printf("Fail %d times\n",fail_count);
	}
	else
	{
		printf("All tests passed\n");
	}


//
//	int baud_rate;
//	int BDIV;
//	while(1)
//	{
//		printf("Set Baud rate\n");
//		scanf("%d",&baud_rate);
//		printf("Set BDIV\n");
//		scanf("%d",&BDIV);
//		baud_test_combined(XPAR_XUARTPS_1_DEVICE_ID,baud_rate,BDIV);
//	}

//    cleanup_platform();
    return 0;
}
