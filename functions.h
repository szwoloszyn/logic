#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "formula.h"

Atom myExpr(Formula v);
int binToDec(unsigned long long bin);
int decToBin(unsigned long long dec);
std::vector<bool> check_all_options(int quaintity, Formula &v);
void print_output(Atom answer, Formula v);
#endif // FUNCTIONS_H
