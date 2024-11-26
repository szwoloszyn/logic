#ifndef FORMULA_H
#define FORMULA_H
#include <iostream>
#include <vector>
#include "atom.h"


class Formula
{
    std::vector < Atom > vals{};

public:
    Formula(int size);
    bool isLast() const;
    void next();
    void print_vals() const;
    Atom operator[](int which) const;
};

#endif // FORMULA_H
