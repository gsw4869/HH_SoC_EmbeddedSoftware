#include <stdio.h>

#define Chan_sts 0xFF00002C
#define Intrpt_mask 0xFF000010
#define Baud_rate_gen 0xFF000018
#define Tx_FIFO_trigger 0xFF000044

void Chan_sts_test();
void Intrpt_mask_test();
void Baud_rate_gen_test();
void Tx_FIFO_trigger_test();
