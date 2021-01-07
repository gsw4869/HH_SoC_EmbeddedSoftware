#include <stdio.h>
#include <psu_init.h>
#include <xuartps_hw.h>
#include "rwtest.h"

void PSU_Mask_Write(unsigned long offset, unsigned long mask,
	unsigned long val)
{
	unsigned long RegVal = 0x0;

	RegVal = Xil_In32(offset);
	RegVal &= ~(mask);
	RegVal |= (val & mask);
	Xil_Out32(offset, RegVal);
}
unsigned int shownum(unsigned int num,int pos1,int pos2)
{
	return (num<<(31-pos2))>>(31-pos2+pos1);
}

void rwtest_all()
{
	    control_rwtest();
	    printf("\n\n");
	    mode_rwtest();
	    printf("\n\n");
	    intrpt_en_rwtest();
	    printf("\n\n");
		intrpt_dis_rwtest();
		printf("\n\n");
		Intrpt_mask_test();
		printf("\n\n");
		Chnl_int_sts_rwtest();
		printf("\n\n");
	    Baud_rate_gen_test();
	    printf("\n\n");
	    Rcvr_timeout_rwtest();
	    printf("\n\n");
	    Chan_sts_test();
	    printf("\n\n");
	    TX_RX_FIFO_test();
	    printf("\n\n");
	    bdiv_rwtest();
	    printf("\n\n");
	    Rcvr_FIFO_trigger_level_rwtest();
	    printf("\n\n");
	    Tx_FIFO_trigger_test();
	    printf("\n\n");
		byte_status_rwtest();
		printf("\n\n");
}
