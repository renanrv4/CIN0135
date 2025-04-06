#include <iostream>
#include "binary_tree.h"

using namespace std;

int main() {
    int testes; cin >> testes;
    BST* binary_tree = new BST();
    for(int i = 0; i < testes; i++) {
        string command; cin >> command;
        if(command == "insert") {
            int num; cin >> num;
            binary_tree->insert(num);
        } else if(command == "remove") {
            int num; cin >> num;
            binary_tree->remove(num);
        } else if(command == "search") {
            int num; cin >> num;
            binary_tree->search(num);
        } else if (command == "pre") {
            binary_tree->preorder(); cout << "\n";
        } else  if (command == "in") {
            binary_tree->inorder(); cout << "\n";
        } else if (command == "post") {
            binary_tree->postorder(); cout << "\n";
        }
    }
    return 0;
}