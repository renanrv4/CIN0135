#include <bits/stdc++.h>

using namespace std;

int main() {
    // O valor final de x será 6, pois o valor de i só é alterado após a atribuição de x
    int x = 0, i = -2; 
    x = -4 * i++ - 6 % 4;
    cout << x << "\n";
    return 0;
}