#include "fraction.h"
#include <bits/stdc++.h>

using namespace std;

void Fraction::simplify() {
    if( numerator == 0) {
        denominator = 1;
        return;
    }
    long a = (numerator < 0) ? -numerator : numerator,
         b = denominator, help;
    while( b != 0) {
        help = a % b;  a = b;  b = help;
    }
    numerator /= a;
    denominator  /= a;
}

Fraction::Fraction(long n, long d) throw (Fraction::DivError){
    if(d == 0) { throw DivError(); }
    if(n < 0) {
        n = -n, d = -d;
        numerator = n; denominator = d;
    } else {
        numerator = n; denominator = d;
    }

}

Fraction::Fraction(double n) {
    n *= 1000;
    n += (n>=0.0) ? 0.5 : -0.5;
    numerator = (long)n;
    denominator = 1000;
    simplify();
}

Fraction operator+ (const Fraction& a, const Fraction& b) {
    Fraction fract(0, 1);
    fract.denominator = a.denominator * b.denominator;
    fract.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    fract.simplify();
    return fract;
}

Fraction operator- (const Fraction& a, const Fraction& b) {
    Fraction fract(0, 1);
    fract.denominator = a.denominator * b.denominator;
    fract.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
    return fract;
}

Fraction operator* (const Fraction& a, const Fraction& b) {
    Fraction fract(0, 1);
    fract.numerator = a.numerator * b.numerator;
    fract.denominator = a.denominator * b.denominator;
    fract.simplify();
    return fract;
}

Fraction operator/ (const Fraction& a, const Fraction& b) throw (Fraction::DivError){
    if(b.numerator == 0) { throw Fraction::DivError(); }
    Fraction fract(0, 1);
    fract.numerator = a.numerator * b.denominator;
    fract.denominator = a.denominator * b.numerator;

    if(fract.denominator < 0) {
        fract.numerator = -fract.numerator;
        fract.denominator = -fract.denominator;
    }
    fract.simplify();
    return fract;
}

ostream& operator<< (ostream& os, const Fraction& a) {
    os << a.numerator << "/" << a.denominator << "\n";
    return os;
}

istream& operator>> (istream& is, Fraction& a) throw (Fraction::DivError) {
    is >> a.numerator >> a.denominator;
    if(!is) { return is; }

    if(a.denominator == 0) {
        cout << "Error: the denominator is 0\n"
             << "The new denominator is:\n";    
        is >> a.denominator;
        if(a.denominator == 0) { throw Fraction::DivError(); }
    }
    if(a.denominator < 0) {
        a.numerator = -a.numerator;
        a.denominator = -a.denominator;
    }
    return is;
}