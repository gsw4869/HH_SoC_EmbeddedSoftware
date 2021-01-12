#include <stdio.h>
#include "xuartps.h"


#define TEST_BUFFER_SIZE 32


int baud_rate_gen_test(u16 DeviceId,int baud_rate);
int baud_rate_DIV_test(u16 DeviceId,int baud_rate);
void baud_test_combined(u16 DeviceId,int baud_rate,int BDIV);
XUartPs Uart_PS;



