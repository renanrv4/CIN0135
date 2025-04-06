#include "openhash.h"

using namespace std;

int main() {
    int t; cin >> t;
    Hash* h = new Hash;
    for(int i = 0; i < t; i++) {
        int num; cin >> num;
        h->insert(num);
    }
    h->print();
    return 0;
}