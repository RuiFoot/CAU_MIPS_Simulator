#include "memory.h"
#include "ALU.h"
#include "register.h"
#include <string.h>

#define PROG_START	0x00400000
#define PROG_END	0x00500000
#define DATA_START	0x10000000
#define DATA_END	0x10100000
#define STAK_START	0x7FF00000
#define STAK_END	0x80000000

//123456789

int main() {

	int z = 0;

	printf("----------MIPS Simulater----------\n");
	
	int s = 0;
	int e = 32;

	unsigned int addr = 1;
	unsigned int val = 0x0000012;

	int reg;
	reg = REG(addr, val, WR);
	reg = REG(addr, val, RD);
	printf("register %d : %x",  addr, reg);

	/*
	setRegister(1, 321354);
	setRegister(3, 165413);
	printRegister(s, e);
	printf("\n\n\n\n");
	resetRegister();
	printRegister(s, e);

	ret = REG(addr, val, WR);


	int ret;

	show_memory(0x00400000, 0x00400100);

	reset_memory();

	val = 0xAABBCCDD;
	addr = PROG_START;

	ret = MEM(addr, val, WR, BYTE);

	ret = MEM(addr, val, RD, BYTE);

	printf("%x", ret);
	*/
	return 0;
}