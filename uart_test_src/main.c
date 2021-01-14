#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include <psu_init.h>
#include <xil_io.h>

#include "includelib.h"



int main()
{
	init_platform();
	int i=0;
	int status=0;
	char a[100];

	printf("start\n");
	sleep(1);

	trans_test(XPAR_XUARTPS_1_DEVICE_ID);
	usleep(10000);
	printf("\n\n");

	for(i=0;i<33;i++)
	{
		printf("disable receiver after receive %d bytes\n",i);
		usleep(10000);

		status=recv_test(XPAR_XUARTPS_1_DEVICE_ID,i);

		if(status)
		{
			printf("\nFail\n\n");
		}
		else
		{
			printf("\nSuccess\n\n");
		}

		usleep(10000);
	}



	cleanup_platform();

	return 0;
}
