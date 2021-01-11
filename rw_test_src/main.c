#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include <psu_init.h>
#include <xil_io.h>

#include "includelib.h"



int main()
{
//	unsigned int a[14];
//	reset_all(a);
//    //init_platform();
//    print_reset(a);
//    rwtest_all();
//    cleanup_platform();
	init_platform();

	printf("normal test\n");
	sleep(1);
	normal_test();
	printf("automatic echo test\n");
	sleep(1);
	automatic_echo_test();
	printf("local loop test\n");
	sleep(1);
	local_loop_test();
	printf("remote loop test\n");
	sleep(1);
	remote_loop_test();
	printf("End of test\n");

    cleanup_platform();
    return 0;
}
