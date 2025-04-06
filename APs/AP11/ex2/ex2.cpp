#include <iostream>
#include "closed_hash.h"

using namespace std;

int main() {
    int m; cin >> m;
    Hash ht(m); string cmd, word;
    while (cin >> cmd && cmd != "fim") {
        cin >> word;
        if (cmd == "add") {
            ht.add(word);
        } else if (cmd == "rmv") {
            ht.remove(word);
        } else if (cmd == "sch") {
            int pos = ht.search(word);
            cout << word << " " << pos << endl;
        }
    }
    return 0;
}