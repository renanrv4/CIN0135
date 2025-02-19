#include <bits/stdc++.h>

using namespace std;

int min(int, ...);

int main() {
    cout << min(12, 93, 244, 45, 21, 1, 0) << "\n";
    return 0;
}

// Encontrando o menor número com um tamanho variável de argumentos
int min(int number, ...) {
    unsigned int minarg, arg;
    va_list args;
    if(number == 0) { return 0; }
    va_start(args, number);
    minarg = number;
    while((arg = va_arg(args, unsigned int)) != 0) {
        if(arg < minarg) {
            minarg = arg;
        }
    }
    va_end(args);
    return minarg;
}