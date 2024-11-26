#include "functions.h"
#include <cmath>
#include <iostream>
int binToDec(unsigned long long bin)
{
    std::cout << bin << "\n";
    unsigned long long dec = 0;
    int count = 0;
    while(bin != 0) {
        dec += bin%2*pow(2,count);
        count++;
        bin /= 10;
    }
    return dec;
}

int decToBin(unsigned long long dec)
{
    unsigned long long bin = 0;
    int i = 1;
    while(dec != 0) {
        bin += i*(dec%2);
        i *= 10;
        dec /= 2;
    }
    return bin;
}
