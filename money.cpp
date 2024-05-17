#include "Money.h"

Money::Money()
{
    this->value = 0;
}

Money::Money(double newValue)
{
    this->value = newValue;
}

Money::~Money()
{
}

double Money::getValue() const
{
    return this->value;
}

void Money::setValue(double newValue)
{
    this->value = newValue;
}

bool Money::operator<(const Money& money) const
{
    return this->value < money.value;
}

ostream& operator<<(ostream& os, const Money& money)
{
    os << money.getValue();
    return os;
}

istream& operator>>(istream& is, Money& money)
{
    is >> money.value;
    return is;
}
