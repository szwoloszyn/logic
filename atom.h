#ifndef ATOM_H
#define ATOM_H

#define AND &&
#define OR ||
#define implies >
#define eq /
#define NOT ~
class Atom
{
    bool value;
public:
    Atom(bool a = false);
    Atom operator&&(Atom a) const; // operator alternatywy
    Atom operator||(Atom a) const; // operator koniunkcji
    Atom operator>(Atom a) const; // operator alternatywy
    Atom operator/(Atom a) const; // operator alternatywy
    Atom operator~() const; // operator negacji

    void operator=(bool val); // operator przypisania wartosci do wartosci
    bool get_value() const;

};

#endif // ATOM_H
