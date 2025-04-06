#ifndef _BST_
#define _BST_

#include <string>

using namespace std;

class BST {
    private:
        struct BSTNode {
            BSTNode* left;
            char letter;
            BSTNode* right;
            BSTNode(char l) { left = NULL; letter = l; right = NULL; }
        };
        BSTNode* root;
        string preorder_tree;
    public:
        BST() {
            root = NULL;
            preorder_tree = "";
        }

        void insert(char addLetter) {
            if(root == NULL) { root = new BSTNode(addLetter); return; }
            BSTNode* current = root;
            BSTNode* parent = NULL;
            while(current != NULL) {
                parent = current;
                if(addLetter < current->letter) {
                    current = current->left;
                } else {
                    current = current->right;
                }
            }
            if(addLetter < parent->letter) {
                parent->left = new BSTNode(addLetter);
            } else {
                parent->right = new BSTNode(addLetter);
            }
        }

        void preorder(BSTNode* node) {
            if(node == NULL) { return; }
            preorder_tree += node->letter;
            preorder(node->left);
            preorder(node->right);
        }
        string preorder() { preorder(root); return preorder_tree; }
};

#endif