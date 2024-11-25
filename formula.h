#ifndef FORMULA_H
#define FORMULA_H

#define AND &&
#define OR ||
#define implies >
#define eq /
#define NOT -
class Formula
{
    bool value;
public:
    Formula(bool a = false);
    Formula operator&&(Formula a) const; // operator alternatywy
    Formula operator||(Formula a) const; // operator koniunkcji
    Formula operator>(Formula a) const; // operator alternatywy
    Formula operator/(Formula a) const; // operator alternatywy
    Formula operator-() const; // operator negacji

    void operator=(bool val); // operator przypisania wartosci do wartosci
    bool get_value() const;

};

#endif // FORMULA_H
