#include <iostream>
#include <iomanip>
using namespace std;
double x = 0.5,
fun(void);

int main() {
    while(x < 10.0) {
        x += fun();	
        cout << "\tWithin main(): " << setw(5) << x << endl;
    }
    return 0;
}

// A variável estática de x irá receber os valores 0, 1, 2, 3, 4.
/* 
O seu valor não é declarado novamente justamente por causa do modificador estático, ou seja,
a declaração de uma variável estática só ocorre uma vez ao decorrer do programa
*/
double fun() {
    static double x = 0;
    cout << "Within fun(): " << setw(5) << x++;
    return x;
}
