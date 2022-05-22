#include "memory.h"

int MEM(unsigned int A, int V, int nRW, int S) {

	unsigned int memSelect, offset; // A = memSelect << 20 + offset
	unsigned char* pM;
	//	unsigned char cdata;
	//	unsigned short int sdata;
	//	unsigned int idata;

	if (nRW > 1 || S > 2) {
		printf("Error: Invalid range of nRW or S"); fflush(stdout);
		exit(1);
	}

	memSelect = A >> 20;
	offset = A & 0xFFFFF;
	if (memSelect == 0x004) pM = progMEM;         // program memory

	else if (memSelect == 0x100) pM = dataMEM;  // data memory

	else if (memSelect == 0x7FF) pM = stakMEM;  // stack

	else {
		printf("Error: No memory with address: %08x\n", A); fflush(stdout);
		exit(1);
	}

	if (S == 0) {  // byte
		if (nRW == 0) {	// read
			return pM[offset];
			
		}
		else {	// write
			pM[offset] = (unsigned char)V;
			printf("PROG BYTE WR: A=%08x, %02x\n", A, pM[offset]);
			return 1;
		}
	}
	else if (S == 1) { // half word
		offset = offset & 0xfffffffe;	// for aligned access
		if (nRW == 0) {	// read
			return (pM[offset] << 8) + pM[offset + 1];
		}
		else {	// write
			pM[offset] = (unsigned char)((V >> 8) & 0xff);
			pM[offset + 1] = (unsigned char)(V & 0xff);
			printf("PROG HALF WD: A=%08x, %02x%02x\n", A, pM[offset], pM[offset+1]);
			return 1;
		}
	}
	else if (S == 2) { // word
		offset = offset & 0xfffffffc;	// for aligned access
		if (nRW == 0) {	// read
			return (pM[offset] << 24) + (pM[offset + 1] << 16) + (pM[offset + 2] << 8) + pM[offset + 3];
		}
		else {	// write
			pM[offset] = (unsigned char)((V >> 24) & 0xff);
			pM[offset + 1] = (unsigned char)((V >> 16) & 0xff);
			pM[offset + 2] = (unsigned char)((V >> 8) & 0xff);
			pM[offset + 3] = (unsigned char)(V & 0xff);
			printf("PROG WORD WR: A=%08x, %02x%02x%02x%02x\n", A, pM[offset], pM[offset+1], pM[offset + 2], pM[offset + 3]);
			return 1;
		}
	}
	return 0;
}

void show_memory(unsigned int start, unsigned int end) {
	printf("Memory startPC : 0x%X endPC : 0x%X\n", start, end);
	for (int i = start; i <= end; i += 4) {
		printf("address = 0x%X , value = %08x\n", i, MEM(i, 0, RD, WORD));
	}
}

void reset_memory(void)
{
	int i;
	for (i = 0; i < 0x100000; i++) {
		progMEM[i] = 0;
		dataMEM[i] = 0;
		stakMEM[i] = 0;
	}
}
