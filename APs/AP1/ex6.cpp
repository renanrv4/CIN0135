#include <bits/stdc++.h>

using namespace std;

// Calculando a média de "n" números
int main() {
    int n; cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        int number_i; cin >> number_i;
        sum = sum + number_i;
    }
    int average = sum/n;
    cout << average << "\n";
    return 0;
}