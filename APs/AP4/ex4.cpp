#include <bits/stdc++.h>

void sieveOfEratosthenes(int);

using namespace std;

// Usando o algoritmo "Sieve of Erastosthenes" para encontrar todos os números primos entre 0 e 1000
int main() {
    sieveOfEratosthenes(1000);
    return 0;
}

void sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true);

    // Base
    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p * p <= n; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }
    cout << "Prime numbers up to " << n << " are:\n";
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}
