#include <iostream>
#include <algorithm>
#include <vector>

#include "formula.h"
#include "functions.h"

using namespace std;
// ZMIENIC ILOSC ZMIENNYCH LOGICZNYCH:
constexpr int ILE = 3;

Atom myExpr(Formula v)
{
    Atom ans;
    ans = true; //TU WYRAZENIE LOGICZNE np takie:
    ans = (~v[0] and v[0]) > v[2];
    return ans;
}


int main()
{
    Atom p{0};
    Atom q{1};
    auto ans = ~p implies q;

    Formula a{ILE};
    a.printInfo();

}
