#include <bits/stdc++.h>
#include "myMacros.h"

using namespace std;

// Usando Macros
int main() {
    char cont = 'y';
    while(cont == 'y') {
        cout << "Choose a function - ABS < 0 > or MAX < 1 >" << "\n";
        int func; cin >> func;
        if(func == 0) {
            cout << "Choose a number (negative or positive): " << "\n";
            int num; cin >> num;
            cout << "The module value of the number is: " << ABS(num) << "\n"; 
        } else if(func == 1) {
            cout << "Choose two numbers and discover which one is bigger: " << "\n";
            int num1, num2; cin >> num1 >> num2;
            cout << "The greater number is: " << MAX(num1, num2) << "\n";
        }
        cout << "You want to continue or not? (y/n): " << "\n";
        cin >> cont;
    }
    return 0;
}