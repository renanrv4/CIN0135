#ifndef _OPENHASH_
#define _OPENHASH_

#include <string>
#include <iostream>

#define SIZE 10

using namespace std;

// Hash Table com política open hash
class Hash {
    private:
        struct Node {
            int key;
            Node* next;
            Node(int k) { key = k; next = NULL; }
        };
        Node* hash_table[SIZE];

        int hash_function(int value) {
            return value % SIZE;
        }
    public:
        Hash() {
            for(int i = 0; i < SIZE; i++) {
                hash_table[i] = NULL;
            }
        }

        void insert(int value) {
            int index = hash_function(value);
            Node* new_node = new Node(value);
            if(hash_table[index] == NULL) {
                hash_table[index] = new_node;
            } else {
                Node* temp_node = hash_table[index];
                while(temp_node->next != NULL) {
                    temp_node = temp_node->next;
                }
                temp_node->next = new_node;
            }
        }
        void remove(int value) {
            int index = hash_function(value);
            Node* curr = hash_table[index];
            Node* prev = NULL;
            while(curr != NULL) {
                if(curr->key == value) {
                    if(prev == NULL) {
                        hash_table[index] = curr->next;
                    } else {
                        prev->next = curr->next;
                    }
                    delete curr;
                    return;
                }
                prev = curr;
                curr = curr->next;
            }

        }

        void print() {
            for (int i = 0; i < SIZE; i++) {
                cout << i << " ";
                Node* curr = hash_table[i];
                while (curr != NULL) {
                    cout << curr->key << " -> ";
                    curr = curr->next;
                }
                cout << "NULL" << endl;
            }
        }
};

#endif