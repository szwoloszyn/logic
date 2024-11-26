#include "functions.h"
#include <cmath>
#include <iostream>


//Atom myExpr(std::vector<Atom> v)
//{
//    Atom ans;
//    ans = true; //TU WYRAZENIE LOGICZNE np takie:
//    ans = (v[0] AND v[1]) implies v[2];
//    return ans;
//}

int binToDec(unsigned long long bin)
{
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

void check_all_options(int quantity)
{
    Formula v{quantity};
    Atom answer;

    while(!v.isLast()) {
        answer = myExpr(v);
        print_output(answer, v);
        v.next();
    }
    answer = myExpr(v);
    print_output(answer, v);
}

void print_output(Atom answer, Formula v)
{
    std::cout << "input: ";
    v.print_vals();
    std::cout << "output: ";
    if(answer.get_value()) {
        std::cout << "TRUE\n";
    }
    else {
        std::cout << "FALSE\n";
    }
}

