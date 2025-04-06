#include "array.h"
#include <iostream>
#include <string>

using namespace std;

// Implementando uma lista baseada em arrays 
int main() {
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        cout << "Caso " << i+1 << "\n";
        int qtd_entradas; cin >> qtd_entradas; 
        Array<int>* arr = new Array<int>(qtd_entradas);
        for(int j = 0; j < qtd_entradas; j++) {
            string command; cin >> command;
            if(command == "insert") {
                int item; cin >> item;
                arr->insert(item);
            } else if (command == "remove") {
                arr->remove();
            } else if (command == "count") {
                int num; cin >> num;
                cout << arr->count(num) << "\n";
            } else if(command == "prev") {
                arr->prev();
            } else if(command == "next") {
                arr->next();
            }
        }
    }
    return 0;
}