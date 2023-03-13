#pragma once
#include <iostream>
class Fraction
{
private:
    int m_numerator{0};
    int m_denumerator{1};
public:
    Fraction(int numerator=0, int denumerator=1);
    ~Fraction(){};
    void print();
    void reduce();
    friend Fraction operator*(const Fraction& fraction, int number);
    friend Fraction operator*( int number, const Fraction& fraction);
    friend Fraction operator*(const Fraction& fraction1, const Fraction& fraction2);
    friend std::ostream& operator<<(std::ostream& os, const Fraction& f);
    friend std::istream& operator>>(std::istream& is, Fraction& f);
};


