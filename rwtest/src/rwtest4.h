#include <stdio.h>

#define mode_addr 0xFF000004
#define intrpt_en_addr 0xFF000008
#define intrpt_dis_addr 0xFF00000C

void mode_rwtest();
void intrpt_en_rwtest();
void intrpt_dis_rwtest();
