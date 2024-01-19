#include "Fraction.h"

Fraction::Fraction(int a, int b): num(a), denom(b)
{

}

Fraction Fraction::reciprocal()
{
    return Fraction(denom, num);
}

Fraction Fraction::multiply(int a)
{
    return Fraction(num*a, denom);
}

double Fraction::toDouble()
{
    return (double)num/denom;
}

std::string Fraction::toString(){
    if (num == 0){
        return "0";
    } else {
        return std::to_string(num) + "/" + std::to_string(denom);
    }
}

Fraction Fraction::simplify(){
//    int test = numeric::gcd(6, 20);
}