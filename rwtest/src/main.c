#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include <psu_init.h>
#include <xil_io.h>
#include "register.h"



int main()
{
	unsigned int a[14];
	reset_all(a);
    init_platform();
    print_reset(a);
    rwtest_all();
//    cleanup_platform();
//	init_platform();
//	PSU_Mask_Write(0xFF010004,0x300U,0X100U);
    while(1)
    {

    }
    cleanup_platform();
    return 0;
}
