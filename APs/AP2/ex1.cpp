#include <bits/stdc++.h>

using namespace std;

int main() {
    // Item A - Printar o número 0.123456 na esquerda com um output com o tamanho de 15 caracteres.
    cout << setw(15) << 0.123456 << "\n";
    
    // Item B - Printar o número 23.987 com 2 casas decimais fixadas justificadas na direita do output 
    cout << setprecision(2) << right << setw(12) << fixed << 23.987 << "\n";

    // Item C - Printar o número -123.456 como número científico com 4 casas decimais de precisão
    cout << setw(10) << scientific << setprecision(4) << -123.456 << "\n";
    
    return 0;
}