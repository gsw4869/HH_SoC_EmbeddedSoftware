#include <stdio.h>
#include "regaddr.h"

#define TEST_BUFFER_SIZE 32
XUartPs Uart_PS;

int tx_fifo_trigger_level_test(u16 DeviceId,char* a,char* res,int i,int level);
