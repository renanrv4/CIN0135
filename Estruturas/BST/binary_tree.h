#ifndef _BST_
#define _BST_

#include <iostream>

using namespace std;

class BST {
    private:
        struct BSTNode {
            BSTNode* left;
            int element;
            BSTNode* right;
            BSTNode(int e) { left = NULL; element = e; right = NULL; }
        };
        BSTNode* root;
    public:
        
        BST() { root = NULL; }

        void insert(int item) {
            if(root == NULL) {
                root = new BSTNode(item);
                return;
            }
            BSTNode* current = root;
            BSTNode* parent = NULL;
            while(current != NULL) {
                parent = current;
                if(item < current->element) {
                    current = current->left;
                } else {
                    current = current->right;
                }
            }
            if(item < parent->element) {
                parent->left = new BSTNode(item);
            } else {
                parent->right = new BSTNode(item);
            }
        }

        void search(BSTNode* node, int item) {
            if(node == NULL) { cout << "Não está na árvore" << "\n"; return; }
            if(item < node->element) {
                search(node->left, item);
            } else if (item > node->element) {
                search(node->right, item);
            } else {
                cout << "Encontrei" << "\n";
            }
        }
        void search(int item) { search(root, item); };

        BSTNode* remove(BSTNode* node, int item) {
            if(node == NULL) {
                return NULL;
            }
            if(item < node->element) {
                node->left = remove(node->left, item);
            } else if (item > node->element) {
                node->right = remove(node->right, item);
            } else {
                if(node->left == NULL) {
                    BSTNode* r_node = node->right;
                    delete node;
                    return r_node;
                } else if(node->right == NULL) {
                    BSTNode* l_node = node->left;
                    delete node;
                    return l_node;
                } else {
                    BSTNode* temp_node = node->right;
                    while(temp_node->left != NULL) {
                        temp_node = temp_node->left;
                    }
                    node->element = temp_node->element;
                    node->right = remove(node->right, temp_node->element);
                }
            }
            return node;
        }
        void remove(int item) { remove(root, item); }
        
        void preorder(BSTNode* node) {
            if(node == NULL) { return; }
            cout << node->element << " ";
            preorder(node->left);
            preorder(node->right);
        }
        void preorder() { preorder(root); }
        
        void inorder(BSTNode* node) {
            if(node == NULL) { return; }
            inorder(node->left);
            cout << node->element << " ";
            inorder(node->right);
        }
        void inorder() { inorder(root); }

        void postorder(BSTNode* node) {
            if(node == NULL) { return; }
            postorder(node->left);
            postorder(node->right);
            cout << node->element << " ";
        }
        void postorder() { postorder(root); }

};

#endif