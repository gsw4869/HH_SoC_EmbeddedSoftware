#include <stdio.h>

#define Chnl_int_sts_addr 0xFF000014
#define Rcvr_timeout_addr 0xFF00001C
#define Rcvr_FIFO_trigger_level_addr 0xFF000020

void Rcvr_timeout_rwtest();
void Chnl_int_sts_rwtest();
void Rcvr_FIFO_trigger_level_rwtest();
