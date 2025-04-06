#ifndef _CLOSEDAHSH_
#define _CLOSEDHASH_

#include <vector>
#include <string>

using namespace std;

class Hash {
    private:
        vector<string> table;
        int size;
        int hash_function(const string& s) {
            int sum = 0;
            for (int i = 0; i < s.size(); i++) {    
                sum += s[i];
            }
            return sum % size;
        }
    public:
        Hash(int len = 0) { size = len; table.resize(size, ""); }
        void add(const string& word) {
            int index = hash_function(word);
            while(table[index] != "") {
                index = (index + 1) % size; 
            }
            table[index] = word;
        }
        void remove(const string& word) {
            int index = hash_function(word);
            while(table[index] != "") {
                if(table[index] == word) {
                    table[index] = "";
                    return;
                }
                index = (index + 1) % size;
            }
        }
        int search(const string& word) {
            int index = hash_function(word);
            while (table[index] != "") {
                if (table[index] == word) {
                    return index;
                }
                index = (index + 1) % size;
            }
            return -1;
        }
};

#endif