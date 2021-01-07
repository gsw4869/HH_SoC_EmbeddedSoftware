#include <stdio.h>

#define Control_addr 0xFF000000
#define Baud_rate_divider_addr 0xFF000034
#define Rx_FIFO_byte_status_addr 0xFF000048
#define FIFO_addr 0xFF000030

void control_rwtest();
void bdiv_rwtest();
void byte_status_rwtest();
void TX_RX_FIFO_test();
