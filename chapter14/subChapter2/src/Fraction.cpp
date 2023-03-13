#include "Fraction.h"
#include <cassert>
#include <iostream>
#include <numeric>
Fraction::Fraction(int numerator, int denumerator):
 m_numerator{numerator}, m_denumerator{denumerator}
{
    //The denumerotor has to be different to zero, because a division of 0 is not allowed.
    assert(m_denumerator!=0);
}

void Fraction::print()
{
    std::cout << m_numerator << "/"<<m_denumerator<< "\n";
}

void Fraction::reduce()
{
    int gcdNumber = std::gcd(m_denumerator, m_numerator);
    if (gcdNumber!=1)
        m_numerator = m_numerator/gcdNumber;
        m_denumerator = m_denumerator/gcdNumber; 
}

Fraction operator*(const Fraction &fraction, int number)
{
    int numerator = fraction.m_numerator * number;
    Fraction f  {numerator, fraction.m_denumerator};
    f.reduce();
    return f;
}

Fraction operator*(int number, const Fraction &fraction)
{
   return fraction* number;
}

Fraction operator*(const Fraction &fraction1, const Fraction &fraction2)
{
    Fraction f{fraction1.m_numerator* fraction2.m_numerator, fraction1.m_denumerator * fraction2.m_denumerator};
    f.reduce();
    return f ;
}

std::ostream &operator<<(std::ostream &os, const Fraction& f)
{
    return os << f.m_numerator << "/ "<< f.m_denumerator;
}

std::istream &operator>>(std::istream &is, Fraction& f)
{
    is >> f.m_numerator;
    is.ignore(std::numeric_limits<std::streamsize>::max(), '/');
    is >> f.m_denumerator;
    return is;
}
