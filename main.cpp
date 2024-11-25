#include <iostream>
#include <algorithm>
#include <vector>

#include "formula.h"

using namespace std;

constexpr int ILE = 3;

Formula myExpr(std::vector<Formula> v)
{
    Formula ans;
    ans = true; //TU WYRAZENIE LOGICZNE np takie:
    ans = (v[0] AND v[1]) implies v[2];
    return ans;
}

void print(std::vector<Formula> v)
{
    for( auto &x : v) {
        std::cout << x.get_value() << " ";
    }
}
void print_all_options(int quantity)
{
    std::vector < Formula > v(quantity);
    std::vector < bool > curr(quantity);
    for( auto i = 0; i < quantity; ++i) {
        curr[i] = true;
        v[i] = curr[i];
    }
    curr[0] = false;
    do {
        for(auto i = 0; i < v.size(); ++i) {
            v[i] = curr[i];
        }
        Formula answer;
        answer = myExpr(v);
        std::cout << "dla danych: "; print(v);
        if(answer.get_value()) std::cout <<  "\nTRUE\n";
        else std::cout << "\nFALSE\n";

    }while(std::next_permutation( curr.begin(), curr.end()));
}


int main()
{
    Formula p{0};
    Formula q{1};
    auto ans = -p implies q;
    //cout << "answer is: " << ans.get_value() << '\n';
    print_all_options(ILE);
}
