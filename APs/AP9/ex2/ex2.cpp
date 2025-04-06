#include "linked_list.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        cout << "Caso " << i+1 << "\n";
        int qtd_entradas; cin >> qtd_entradas; 
        LinkedList<int>* llist = new LinkedList<int>;
        for(int j = 0; j < qtd_entradas; j++) {
            string command; cin >> command;
            if(command == "insert") {
                int item; cin >> item;
                llist->insert(item);
            } else if (command == "remove") {
                llist->remove();
            } else if (command == "count") {
                int num; cin >> num;
                cout << llist->count(num) << "\n";
            } else if(command == "prev") {
                llist->prev();
            } else if(command == "next") {
                llist->next();
            }
        }
    }

    return 0;
}