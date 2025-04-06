#include <iostream>
#include <vector>
#include "binary_tree.h"

int main() {
    string input;
    vector<string> tree_leaves;
    while(input != "$") {
        cin >> input;
        if(input == "*" || input == "$") {
            BST* binary_tree = new BST();
            for(int i = tree_leaves.size() -1; i >= 0; i--) {
                for(char letter : tree_leaves[i]) {
                    binary_tree->insert(letter);
                }
            }
            cout << binary_tree->preorder() << "\n";
            tree_leaves.clear();
        } else {
            tree_leaves.push_back(input);
        }
    }
    return 0;
}