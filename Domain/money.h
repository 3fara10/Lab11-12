#pragma once
#include <ostream>
#include <istream>
using namespace std;
class Money {
private:
    double value;
public:
    Money();
    Money(double newValue);
    ~Money();

    double getValue() const;
    void setValue(double newValue);

    bool operator <(const Money& money) const;
    friend ostream& operator<<(ostream& os, const Money& money);
    friend istream& operator>>(istream& is, Money& money);

};