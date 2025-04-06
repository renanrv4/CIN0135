#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

int main() {
    int testes; cin >> testes;
    for(int i = 0; i < testes; i++) {
        int n_ops; cin >> n_ops; cin.ignore();
        Hash ht;
        for(int j = 0; j < n_ops; j++) {
            string operation;
            getline(cin, operation);
            if (operation.substr(0, 3) == "ADD") {
                string key = operation.substr(4);
                ht.insert(key);
            } else if (operation.substr(0, 3) == "DEL") {
                string key = operation.substr(4);
                ht.remove(key);
            }
        }
        ht.print();
    }

    return 0;
}