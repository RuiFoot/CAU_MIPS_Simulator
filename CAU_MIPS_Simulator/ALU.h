#pragma once
#include <stdio.h>
#include <stdlib.h>
int addSubtract(int X, int Y, int C);
// Logic unit
int logicOperation(int X, int Y, int C);
// Shift unit
// V: 5 bit shift amount
int shiftOperation(int V, int Y, int C);
int checkSetLess(int X, int Y);
int checkZero(int S);
// ALU
int ALU(int X, int Y, int C, int* Z);