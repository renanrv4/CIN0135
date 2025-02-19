#include <bits/stdc++.h>
#include "fraction.h"
#include "fraction.cpp"

using namespace std;

int main() {
    try {
        Fraction c(5,0);
    }
    catch(Fraction::DivError& ) {
        cout << "\nError on initializing: "
            << "\nThe denominator is 0\n";
    }

    Fraction a(1,3), b(3);
    
    try {
        cout << "\nSome test output:\n\n";
        cout << " a = " << a << endl;
        cout << " b = " << b << endl;
        cout << " a + b = " << (a + b) << endl;
        cout << " a - b = " << (a - b) << endl;
        cout << " a * b = " << (a * b) << endl;
        b = 0;
        cout << " a / b = " << (a / b) << endl;   // Error!
    }
    catch(Fraction::DivError& ) {
        cout << "\nError on dividing: "
        << "\nNo division by zero! 0\n";
    }

    cout << "  --a =  " <<  --a << endl;
    cout << "  ++a  = " <<  ++a << endl;
    
    a += Fraction(1,2);
    cout << " a+= 1/2;  a = " << a << endl;
    
    a -= Fraction(1,2);
    cout << " a-= 1/2;  a = " << a << endl;
    
    cout << "-b = " << -b << endl;
    
    cout << "\nAnd now your input: \n";
    try {
        cin  >> a;
    }
    catch(Fraction::DivError&) {
        cerr << "\nError: The denominator is 0\n";
        exit(1);
    }
    cout << "\nYour input: " << a  << endl;
    return 0;
}