#include <bits/stdc++.h>
#include "product.h"

using namespace std;

// Utilizando os conceitos de herança para criar objetos
int main() {
    Product p1(12345L, "Beans"), p2;
    p1.print();

    p2.setBCode(9283L); p2.setName("Meat");
    p2.print();

    PrepackedFood pf1(10.399, 19220L, "Chocolate"), pf2;
    pf1.print();

    pf2.scanner();
    pf2.print();

    FreshFood ff1(10.87, 24.99, 22L, "Watermelon"), ff2;
    ff1.print();

    ff2.scanner();
    ff2.print();

    cout << "\n-------------------------------"
         << "\n-------------------------------"
         << "\nAgain in detail: \n"
         << fixed << setprecision(2)
         << "\nBarcode:       " << ff2.getBCode()
         << "\nName:          " << ff2.getName()
         << "\nPrice per Lbs: " << ff2.getPKilo()
         << "\nWeight:        " << ff2.getWeight()
         << "\nEnd price:     " << ff2.getPKilo() * ff2.getWeight()
         << "\n";

    return 0;
}