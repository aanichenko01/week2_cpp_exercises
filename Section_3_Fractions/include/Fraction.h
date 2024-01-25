#pragma once
#include <string>

class Fraction {
    public:
    Fraction(int a, int b);

    Fraction reciprocal();

    Fraction multiply(int a) const;

    double toDouble() const;

    std::string toString() const;
    
    private:
    void simplify();
    
    int num;
    int denom;

};