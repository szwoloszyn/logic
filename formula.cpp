#include "formula.h"
#include "functions.h"
#include <cmath>
#include <string>
Formula::Formula(int size)
{
    for(auto i=0; i<size; ++i) {
        this->vals.push_back(Atom(false));
    }
    this->outputs = check_all_options(size, *this);
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
        //vals[1] = true;
        //vals[vals.size()-1] = true;
    // -------
    if(this->isLast()) {
        return;
    }
    // myvect -> logic values of vals vector
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
    auto bin = 0uLL;
    for(auto i=0; i<myvect.size(); ++i) {
        bin += myvect[i]*(std::pow(10,i));
    }
    // adding bin += 1 in binary by converting to decimal adding and reconverting to binary
    auto dec = binToDec(bin);
    dec ++;
    bin = decToBin(dec);
    // zeroing myvect (could do without it ig)
    for(auto &x : myvect) {
        x = 0;
    }
    for (int i = 0; bin !=0; ++i) {
        myvect[i] = bin%2;
        bin /= 10;
    }
    for(auto i=0; i<vals.size(); ++i) {
        vals[i] = bool(myvect[i]);
    }
}

void Formula::zeroit()
{
    for(auto &x : vals) {
        x = false;
    }
}

void Formula::print_vals() const
{
    for(auto &x : vals) {
        std::cout << x.get_value() << " ";
    }
    std::cout << '\n';
}

Atom Formula::operator[](int which) const
{
    if(which >= vals.size()) {
        std::cerr << "invalid index, returning [0]";
        return vals[0];
    }
    return vals[which];
}

bool Formula::isTautology() const
{
    for(auto x : outputs) {
        if(!x) {
            return false;
        }
    }
    return true;
}

bool Formula::isPossible() const
{
    for(auto x : outputs) {
        if(x) {
            return true;
        }
    }
    return false;
}

bool Formula::isFake() const
{
    for(auto x : outputs) {
        if(x) {
            return false;
        }
    }
    return true;
}

void Formula::printInfo() const
{
    std::cout << "\n-------\n";
    if(isTautology()) {
        std::cout << "formula is tautology\n";
    }
    else if(isPossible()) {
        std::cout << "formula is possible\n";
    }
    else {
        std::cout << "formula is fake\n";
    }
}
