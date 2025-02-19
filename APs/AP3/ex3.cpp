#include <bits/stdc++.h>
#define ull unsigned long long int
using namespace std;

ull factorial_loop(int);
ull factorial_recursive(int);

//Fatorial usando loop e recursão
int main() {
    for(int i = 0; i <= 20; i++) {
        cout << "Factorial of " << i << " with loops: " << factorial_loop(i) << "\n";
        cout << "Factorial of " << i << " with recursion: " << factorial_recursive(i) << "\n";
    }
    return 0;
}

// Função para calcular o fatorial de um número n com loops
ull factorial_loop(int n) {
    ull res = 1;
    if(n == 0) {
        return 1;
    } else if(n == 1) {
        return 1;
    } else {
        while(n != 1) {
            res = res*n;
            n--;
        }
    }
    return res;
}

// Função para calcular o fatorial de um número n com recursão
ull factorial_recursive(int n) {
    if(n == 0) {
        return 1;
    }
    if(n == 1) {
        return 1;
    }
    return n * factorial_recursive(n-1);
}