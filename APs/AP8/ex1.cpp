#include <bits/stdc++.h>
#include "product.h"

using namespace std;

void record();

// Adicionando objetos derivados da classe Product
int main() {
    cout << "\nAdding customers" << endl;
    char c;
    while(true) {
        cin.sync();
        cout << "\nAnother customer (y/n)?   ";
        cin  >> c;
        if(c == 'y' || c == 'Y'){
            record();
        } else {
            break;
        }
    }
    return 0;
}

void record() {
    Product* parr[100];

    int i, j, cnt = 0;
    double tt_price = 0.0;
    for(i = 0; i < 100; i++) {
        cin.sync();
        cout << "\nWhat is the next article?" << endl;
        cout << "  0 = No more article\n"
             << "  1 = Fresh Food\n"
             << "  2 = Prepacked article\n"
             << "? " ;
        cin  >> j;
        if(j <= 0 || j >= 3) {
            break;
        }
        switch (j) {
            case 1:
                parr[i] = new FreshFood;
                parr[i]->scanner();
                tt_price += static_cast<FreshFood*>(parr[i])->getPKilo() * static_cast<FreshFood*>(parr[i])->getWeight();
                break;
            case 2:
                parr[i] = new PrepackedFood;
                parr[i]->scanner();
                tt_price += static_cast<PrepackedFood*>(parr[i])->getUPrice();
                break;
        }
    }
    cnt = i;
    for(i = 0; i < cnt; i++) {
        parr[i]->print();
    }
    cout << "The total price is: " << "\n"
         << fixed << setprecision(2) << tt_price;
}