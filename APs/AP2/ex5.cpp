#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int seed; cin >> seed;
    srand(seed);

    // Printar 20 números aleatórios de 1 a 100
    for (int i = 0; i < 20; ++i) {
        int random_number = (rand() % 100) + 1;
        cout << random_number << " ";
    }
    cout << "\n";

    return 0;
}
