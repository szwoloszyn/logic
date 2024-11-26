#ifndef FORMULA_H
#define FORMULA_H
#include <iostream>
#include <vector>
#include "atom.h"
#include "functions.h"

class Formula
{
    std::vector < Atom > vals{};

public:
    Formula(int size);
    bool isLast() const;
    void next();
};

#endif // FORMULA_H
