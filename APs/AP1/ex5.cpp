#include <bits/stdc++.h>

using namespace std;

int main() {
    string str = "I have learned something new again!";
    cout << "The lenght of the string is: " << str.length() << "\n";

    // Lendo valores do terminal
    string line1, line2;
    cout << "Line 1: " << "\n";
    getline(cin, line1);
    cout << "Line 2: " << "\n";
    getline(cin, line2);

    string newstr = line1 + " * " + line2;
    cout << "The new string is: " << "\n" << newstr << "\n";

    return 0;
}