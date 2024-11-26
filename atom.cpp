#include "atom.h"




Atom::Atom(bool a)
{
    this->value = a;
}

bool Atom::get_value() const
{
    return this->value;
}

Atom Atom::operator&&(Atom a) const
{
    if(this->value && a.value) {
        return Atom(true);
    }
    return Atom(false);
}

Atom Atom::operator||(Atom a) const
{
    if(this->value || a.value) {
        return Atom(true);
    }
    return Atom(false);
}

Atom Atom::operator>(Atom a) const
{
    if(this->value == true && a.value == false) {
        return Atom(false);
    }
    return Atom(true);
}

Atom Atom::operator/(Atom a) const
{
    if(this->value == true && a.value == true) {
        return Atom(true);
    }
    if(this->value == false && a.value == false) {
        return Atom(true);
    }
    return Atom(false);
}

Atom Atom::operator~() const
{
    if(this->value) {
        return Atom(false);
    }
    return Atom(true);
}

void Atom::operator=(bool val)
{
    this->value = val;
}
