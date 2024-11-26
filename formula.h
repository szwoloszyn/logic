#ifndef FORMULA_H
#define FORMULA_H
#include <iostream>
#include <vector>
#include "atom.h"


class Formula
{
    std::vector < Atom > vals{};
    std::vector < bool > outputs{};

public:
    Formula(int size);
    bool isLast() const;
    void next();
    void zeroit();
    void print_vals() const;
    Atom operator[](int which) const;

    bool isTautology() const;
    bool isPossible() const;
    bool isFake() const;
    void printInfo() const;
};

#endif // FORMULA_H
