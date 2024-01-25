#include "Fraction.h"
#include <string>
#include <iostream>


Fraction::Fraction(int a, int b): num(a), denom(b)
{
    // with simplify commented in it is stuck in an eternal while loop
    simplify();
}

Fraction Fraction::reciprocal()
{
    return Fraction(denom, num);
}

Fraction Fraction::multiply(int a) const
{
    return Fraction(num*a, denom);
}

double Fraction::toDouble() const
{

    return (double)num/denom;

}

std::string Fraction::toString() const{
    if (num == 0){
        return "0";
    } else {
        return std::to_string(num) + "/" + std::to_string(denom);
    }
}

void Fraction::simplify(){

    int n = num;
    int d = denom;
    while (d != 0)
    {
        int temp = d;
        d = n % d;
        n = temp;
    }

    int gcd = n;

    num = num / gcd;
    denom = denom / gcd;
}