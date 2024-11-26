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
    ans = (~v[0] and v[1]) > v[2];
    return ans;
}


int main()
{
    Atom p{0};
    Atom q{1};
    auto ans = ~p implies q;
    //cout << "answer is: " << ans.get_value() << '\n';
    //print_all_options(ILE);
    Formula a{3};
    while (!a.isLast()) {
        //a.print_vals();
        a.next();
    }

    a.next();
    //a.print_vals();

    check_all_options(ILE);

    unsigned long long num = 10110100000;
    //cout << decToBin(binToDec(num) );
}
