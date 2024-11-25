#include "formula.h"




Formula::Formula(bool a)
{
    this->value = a;
}

bool Formula::get_value() const
{
    return this->value;
}

Formula Formula::operator&&(Formula a) const
{
    if(this->value && a.value) {
        return Formula(true);
    }
    return Formula(false);
}

Formula Formula::operator||(Formula a) const
{
    if(this->value || a.value) {
        return Formula(true);
    }
    return Formula(false);
}

Formula Formula::operator>(Formula a) const
{
    if(this->value == true && a.value == false) {
        return Formula(false);
    }
    return Formula(true);
}

Formula Formula::operator/(Formula a) const
{
    if(this->value == true && a.value == true) {
        return Formula(true);
    }
    if(this->value == false && a.value == false) {
        return Formula(true);
    }
    return Formula(false);
}

Formula Formula::operator-() const
{
    if(this->value) {
        return Formula(false);
    }
    return Formula(true);
}

void Formula::operator=(bool val)
{
    this->value = val;
}
