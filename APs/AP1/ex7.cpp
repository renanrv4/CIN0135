#include <iostream>
using namespace std;

// Teste: Usando o debugger para observar o caminho que o código faz
int main() {
    
    cout << "Hello world!" << endl;
    
    int n = 10;
    n += n;

    cout << "Value of n: " << n << endl;

    // Array estático
    int array[10];
    for (int i=0; i<10; i++) {
        array[i] = 10+i;
    }
    cout << array[9];

    // Array Dinâmico alocado na memória
    int *array2 = new int[10];
    for (int i=0; i<10; i++) {
        array2[i] = 10+i;
    }
    cout << array2[9];
    return 0;
}

