#include <iostream>
#include <string>

#include "array.h"

void removeFromArray(Array<char>* array) {
    array->moveToStart();
    while(array->curr() != array->length()) {
        char temp = array->getValue();
        array->next();
        if((temp == '(' && array->getValue() == ')') || (temp == '[' && array->getValue() == ']')) {
            array->remove(); array->prev(); array->remove();
            array->moveToStart();
        }
    }
}

int main() {
    int t; cin >> t; cin.ignore();
    for(int i = 0; i < t; i++) {
        Array<char>* ar = new Array<char>(128);
        string seq; getline(cin, seq);
        for(int j = 0; j < seq.size(); j++) {
            ar->insert(seq.at(j));
            ar->next();
        }
        removeFromArray(ar);
        if(ar->length() > 0) {
            cout << "No" << "\n";
        } else {
            cout << "Yes" << "\n";
        }
        delete ar;
    }
    return 0;
}