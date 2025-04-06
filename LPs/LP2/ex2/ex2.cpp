#include "dict.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    Dict dict;
    string input, word, key;
    while (true) {
        getline(cin, input);
        if(input.empty()) {
            break;
        } else {
            int space_pos = input.find(' ');
            word = input.substr(0, space_pos);
            key = input.substr(space_pos+1);
            dict.insert(key, word);
        }
    }
    while(true) {
        string key_input;
        getline(cin, key_input);
        if(key_input.empty()) {
            break;
        } else {
            dict.search(key_input);
        }
    }
    return 0;
}