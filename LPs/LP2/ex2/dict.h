#ifndef _DICT_
#define _DICT_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int TABLE_SIZE = 200003;
const int P = 31;
const int M = 1e9 + 9;

class Dict {
    private:
        vector<string> array_keys;
        vector<string> array_words;

        long long hash_function(const string& key) {
            long long hash_value = 0;
            long long p_pow = 1;
            for (size_t i = 0; i < key.length(); i++) {
                hash_value = (hash_value + (key[i] - 'a' + 1) * p_pow) % M;
                p_pow = (p_pow * P) % M;
            }
            return hash_value % TABLE_SIZE;
        }
    public:
        Dict() {
            array_keys.assign(TABLE_SIZE, "");
            array_words.assign(TABLE_SIZE, "");
        }
        void insert(const string& key, const string& word) {
            int index = hash_function(key);
            int i = 0;
            while(!array_keys[index].empty()) {
                index = (index + i * i) % TABLE_SIZE;
                i++;
            }
            array_keys[index] = key;
            array_words[index] = word;
        }
        void search(const string& key) {
            int index = hash_function(key);
            int i = 0;
            while(!array_keys[index].empty()) {
                if(array_keys[index] == key) {
                    cout << array_words[index] << "\n";
                    return;
                }
                index = (index + i * i) % TABLE_SIZE;
                i++;
            }
            cout << "eh" << "\n";
        }
};

#endif