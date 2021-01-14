#include <stdio.h>
#include "xuartps.h"

#define TEST_BUFFER_SIZE 32
XUartPs Uart_PS;

int recv_test(u16 DeviceId,int num);
int trans_test(u16 DeviceId);
