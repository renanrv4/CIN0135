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
        int count_el;
        int qtd_el;
    public:
        
        BST(int size = 0) { root = NULL; count_el = 0; qtd_el = size; }

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

        void preorder(BSTNode* node) {
            if(node == NULL) { return; }
            if(count_el == qtd_el-1) {
                cout << node->element;
            } else {
                cout << node->element << " ";
            }
            count_el++;
            preorder(node->left);
            preorder(node->right);
        }
        void preorder() { count_el = 0; preorder(root); }

        void inorder(BSTNode* node) {
            if(node == NULL) { return; }
            inorder(node->left);
            if(count_el == qtd_el-1) {
                cout << node->element;
            } else {
                cout << node->element << " ";
            }
            count_el++;
            inorder(node->right);
        }
        void inorder() { count_el = 0; inorder(root); }

        void postorder(BSTNode* node) {
            if(node == NULL) { return; }
            postorder(node->left);
            postorder(node->right);
            if(count_el == qtd_el-1) {
                cout << node->element;
            } else {
                cout << node->element << " ";
            }
            count_el++;
        }
        void postorder() { count_el = 0; postorder(root); }

};

#endif