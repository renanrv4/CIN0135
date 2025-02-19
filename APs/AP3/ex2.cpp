#include <bits/stdc++.h>

using namespace std;

bool palindrome(string);

// Encontrando palíndromos
int main() {
    string str;
    char yn = 'y';
    while(yn == 'y') {
        cin >> str;
        bool ispalindrome = palindrome(str);
        if(ispalindrome) {
            cout << "WOW!! We found a palindrome." << "\n";
        } else {
            cout << "Well, we tried but it is not a palindrome." << "\n";
        }
        cout << "You want to continue? (y/n)";
        cin >> yn;
    }
    return 0;
}

bool palindrome(string word) {
    for(int i = word.size(); i > 0; i--) {
        if(word[i-1] != word[(word.size()-1) - (i-1)]) {
            return false;
        }
    }
    return true;
}