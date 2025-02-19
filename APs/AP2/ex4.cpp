#include <bits/stdc++.h>

using namespace std;

// Tabela de multiplicação 
int main() {
    cout << setw(4) << " ";
    for (int col = 1; col <= 10; ++col) {
        cout << setw(4) << col;
    }
    cout << "\n";

    for (int row = 1; row <= 10; ++row) {
        cout << setw(4) << row;
        for (int col = 1; col <= 10; ++col) {
            cout << setw(4) << row * col;
        }
        cout << "\n";
    }
    return 0;
}
