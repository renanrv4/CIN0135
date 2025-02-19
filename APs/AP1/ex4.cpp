#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// A atividade pedia a correção dos erros
int main() {
    string message = "\nLearn from your mistakes!";
    cout << message << endl;
    int len = message.length();
    cout << "Length of the string: " << len << endl;
    int a, b;
    srand(12);
    a = rand();
    b = rand();
    cout << "\nRandom number: " << a << endl;
    cout << "\nRandom number: " << b << endl;
    return 0;
}
