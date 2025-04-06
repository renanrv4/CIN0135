#include "binary_tree.h"

int main() {
    int n_data; cin >> n_data;
    BST* binary_tree = new BST(n_data);
    for(int i = 0; i < n_data; i++) {
        int num; cin >> num;
        binary_tree->insert(num);
    }
    cout << "Pre order : "; binary_tree->preorder(); cout << "\n";
    cout << "In order  : "; binary_tree->inorder(); cout << "\n";
    cout << "Post order: "; binary_tree->postorder(); cout << "\n";
    return 0;
}