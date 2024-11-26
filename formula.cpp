#include "formula.h"
#include <cmath>
#include <string>
Formula::Formula(int size)
{
    for(auto i=0; i<size; ++i) {
        this->vals.push_back(Atom(false));
    }

}

bool Formula::isLast() const
{
    for(auto x : vals) {
        if(!x.get_value()) {
            return false;
        }
    }
    return true;
}

void Formula::next()
{
    // TESTOWE DANE:
    vals[1] = true;
    vals[vals.size()-1] = true;
    // -------
    if(this->isLast()) {
        return;
    }
    // myvect -> wektor wartosci logicznych mojego vals
    std::vector<int> myvect(vals.size());
    for(auto i=0; i<vals.size(); ++i) {
        if(this->vals[i].get_value()) {
            myvect[i] = 1;
        }
        else {
            myvect[i] = 0;
        }
    }
    // converting vector values to binary number - to easily get combinations
    int bin = 0;
    for(auto i=0; i<myvect.size(); ++i) {
        bin += myvect[i]*(std::pow(10,i));
    }
    // TODO add bin += 1 in binary !
    for(auto &x : myvect) {
        x = 0;
    }
    for (int i = 0; bin !=0; ++i) {
        myvect[i] = bin%2;
        bin /= 10;
    }
    for(auto &x : myvect) {
        std::cout << x << " ";
    }
    //std::cout << bin << '\n';
}
