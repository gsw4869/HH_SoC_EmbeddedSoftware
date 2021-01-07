#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include <psu_init.h>
#include <xil_io.h>
#include <xuartps_hw.h>

#define Con_Reg 0xFF000000
#define Mode_Reg 0xFF000004
#define Intr_Reg 0xFF000008
#define Intr_dis 0xFF00000C
#define Intr_mask 0xFF000010
#define Chnl_int 0xFF000014
#define Baud_gen 0xFF000018
#define Rcvr_time 0xFF00001C
#define Rcvr_FIFO_tri 0xFF000020
#define Chan_sts 0xFF00002C
#define TX_RX_FIFO 0xFF000030
#define Baud_div 0xFF000034
#define Tx_FIFO 0xFF000044
#define Rx_FIFO_stat 0xFF000048

void reset_all(unsigned int *res);
void print_reset(unsigned int *res);
