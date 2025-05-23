#ifndef _FRACTION_
#define _FRACTION_

#include <iostream>
#include <cstdlib>
#include <stdexcept>

using namespace std;

class Fraction {
    private:
        long numerator, denominator;
    public:
        class DivError { };

        Fraction(long numerator=0, long denominator=1) throw (DivError);
        Fraction(double n);
        Fraction(long m=0) : numerator(m), denominator(1) {}
        Fraction(int m)    : numerator(m), denominator(1) {}

        void simplify();
        operator double() {
            return (double)numerator/ (double)denominator;
        }
        Fraction operator-() const {
            return Fraction(-numerator, denominator);
        }
        Fraction& operator+=(const Fraction& a) {
            numerator = a.numerator * denominator + numerator * a.denominator;
            denominator = a.denominator * denominator;
            return *this;
        }
        Fraction& operator-=(const Fraction& a) {
            numerator = a.numerator*denominator - numerator * a.denominator;
            denominator = a.denominator * denominator;
            return *this;
        }
        Fraction& operator++() {
            numerator = numerator + denominator;
            return *this;
        }
        Fraction& operator--() {
            numerator -= denominator;
            return *this;
        }

        friend Fraction operator+(const Fraction&, const Fraction&);
        friend Fraction operator-(const Fraction&, const Fraction&);
        friend Fraction operator*(const Fraction&, const Fraction&);
        friend Fraction operator/(const Fraction&, const Fraction&) throw (Fraction::DivError);
        friend ostream& operator<< (ostream& os, const Fraction& a);
        friend istream& operator>> (istream& is, Fraction& a) throw (Fraction::DivError);  
};

#endif