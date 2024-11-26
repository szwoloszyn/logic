#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "formula.h"

Atom myExpr(Formula v);
int binToDec(unsigned long long bin);
int decToBin(unsigned long long dec);
void check_all_options(int quaintity);
void print_output(Atom answer, Formula v);
#endif // FUNCTIONS_H
