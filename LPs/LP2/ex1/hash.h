#ifndef _HASH_
#define _HASH_

#include <iostream>
#include <string>

using namespace std;

class Hash {
    private:
        struct HashElement {
            string key_val;
            bool occupied;
            HashElement(string key_val = "", bool occupied = false) {
                this->key_val = key_val;
                this->occupied = occupied;
            }
        };
        HashElement* hash_table;

        bool* ocuppied_list;
        int num_elements;

        int hash_function(const string& key) {
            int sum = 0;
            for(int i = 0; i < key.length(); i++) {
                sum = sum + (key[i]*(i+1));
            }
            return (19 * sum) % 101;
        }
    public:
        Hash() {
            num_elements = 0;
            hash_table = new HashElement[101];
        }
        ~Hash() {
            delete [] hash_table;
            hash_table = nullptr;
        }

        void insert(const string& key) {
            int index = hash_function(key);
            int final = 0; bool found = false;
            for(int j = 0; j < 20; j++) {
                int new_index = (index + (j * j) + (23 * j)) % 101;
                if(hash_table[new_index].key_val == "" && hash_table[new_index].occupied == false && !found) {
                    final = new_index; found = true;
                } else if(hash_table[new_index].key_val == key && hash_table[new_index].occupied == true) {
                    return;
                }
            }
            if(found) {
                hash_table[final] = HashElement(key, true);
                num_elements++;
            }
        }
        void remove(const string& key) {
            int index = hash_function(key);
            int i = 0;
            while(i < 20) {
                int new_index = (index + (i * i) + (23 * i)) % 101;
                if(hash_table[new_index].key_val == key) {
                    hash_table[new_index].key_val = "";
                    hash_table[new_index].occupied = false;
                    num_elements--;
                    return;
                }
                i++;
            }
        }
        void print() {
            cout << num_elements << "\n";
            for(int i = 0; i < 101; i++) {
                if(hash_table[i].key_val != "" || hash_table[i].occupied == true) {
                    cout << i << ":" << hash_table[i].key_val << "\n";
                }
            }
        }

};

#endif