#pragma once
#include <stdio.h>
#include <stdlib.h>
int MEM(unsigned int A, int V, int nRW, int S);
void reset_memory(void);


static unsigned char progMEM[0x100000], dataMEM[0x100000], stakMEM[0x100000];

enum accessType { RD, WR };
enum accessSize { BYTE, HALF, WORD };