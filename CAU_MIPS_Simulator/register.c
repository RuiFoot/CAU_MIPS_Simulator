#include "register.h"

Register registerMap[33] = {
		{ "r0", 0x00 },{ "at", 0x01 },
		{ "v0", 0x02 },{ "v1", 0x03 },
		{ "a0", 0x04 },{ "a1", 0x05 },
		{ "a2", 0x06 },{ "a3", 0x07 },
		{ "t0", 0x08 },{ "t1", 0x09 },
		{ "t2", 0x0A },{ "t3", 0x0B },
		{ "t4", 0x0C },{ "t5", 0x0D },
		{ "t6", 0x0E },{ "t7", 0x0F },
		{ "s0", 0x10 },{ "s1", 0x11 },
		{ "s2", 0x12 },{ "s3", 0x13 },
		{ "s4", 0x14 },{ "s5", 0x15 },
		{ "s6", 0x16 },{ "s7", 0x17 },
		{ "t8", 0x18 },{ "t9", 0x19 },
		{ "k0", 0x1A },{ "k1", 0x1B },
		{ "gp", 0x1C },{ "sp", 0x1D },
		{ "fp", 0x1E },{ "ra", 0x1F },
		{ NULL, 0 }
};
static MIPSRegister R[33] = {
	{ &registerMap[0],0}, { &registerMap[1],0 },
	  { &registerMap[2],0 },{ &registerMap[3],0 },
	  { &registerMap[4],0 }, { &registerMap[5],0 },
	  { &registerMap[6],0 },{ &registerMap[7],0 },
	  { &registerMap[8],0 },{ &registerMap[9],0 },
	  { &registerMap[10],0 },{ &registerMap[11],0 },
	  { &registerMap[12],0 },{ &registerMap[13],0 },
	  { &registerMap[14],0 },{ &registerMap[15],0 },
	  { &registerMap[16],0 },{ &registerMap[17],0 },
	  { &registerMap[18],0 },{ &registerMap[19],0 },
	  { &registerMap[20],0 },{ &registerMap[21],0 },
	  { &registerMap[22],0 },{ &registerMap[23],0 },
	  { &registerMap[24],0 },{ &registerMap[25],0 },
	  { &registerMap[26],0 },{ &registerMap[27],0 },
	  { &registerMap[28],0 },{ &registerMap[29],0 },
	  { &registerMap[30],0 },{ &registerMap[31],0 },
	  { NULL,0 }
};

// Register Read, Write
int REG(unsigned int A, unsigned int V, unsigned int nRW) {
	if (nRW) { //Write
		if (0 < A && A < 33) {
			R[A].value = V;
		}
		return 1;
	}
	else { // read
		return R[A].value;
	}
}

//start -> end 위치까지 Register print
void printRegister(int s, int e) {
	for (int i = s; i < e; i++) {
		printf(" R%d[%s] = %x\n", i, R[i].info->name, R[i].value);
	}
}

void resetRegister(void) {
	for (int i = 0; i < 32; i++) {
		R[i].value = 0;
	}
}