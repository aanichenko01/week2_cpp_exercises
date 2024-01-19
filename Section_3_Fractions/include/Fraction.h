#pragma once
#include <string>

class Fraction {
    public:
    Fraction(int a, int b);
    Fraction reciprocal();
    Fraction multiply(int a);
    double toDouble();
    std::string toString();
    
    private:
    int num;
    int denom;


};