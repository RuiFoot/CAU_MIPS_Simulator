#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct Register {
	const char* name;
	unsigned char addr;
}Register;
typedef struct MIPSRegister {
	Register* info;
	int value;
}MIPSRegister;



int REG(unsigned int A, unsigned int V, unsigned int nRW);
void printRegister(int s, int e);
void resetRegister(void);