#include <bits/stdc++.h>
#include "product.h"

using namespace std;

const Product& isLowerCode(const Product&, const Product&);

int main() {
    Product* parr[3];
    FreshFood* ff;
    parr[0] = new Product(1111L, "Bottle");
    parr[1] = new PrepackedFood(12.50, 121212L, "Butter");
    parr[2] = new FreshFood(0.38, 15.33, 999L, "Pepper");

    ff = new FreshFood(0.55, 19.99, 900L, "Lemon");
    
    ff->print();
    // O único método utilizado vai ser o método print da classe Base
    for(int i = 0; i < 3; i++) {
        parr[i]->print();
    }
    cin.get();

    // Utilizando downcast para utilizar o print das classes filhas
    cout << "Downcast------" << "\n";
    static_cast<PrepackedFood*>(parr[1])->print();
    static_cast<FreshFood*>(parr[2])->print();
    cin.get();

    // Utilizando upcast
    cout << "Upcast--------" << "\n";
    static_cast<Product*>(ff)->print();
    cin.get();

    // Comparação de códigos
    cout << "Lower codes--------" << "\n";
    isLowerCode(*parr[0], *parr[1]).print();

    // Comparação de códigos
    isLowerCode(*parr[1], *parr[2]).print();

    // Comparação de códigos
    isLowerCode(*parr[0], *parr[2]).print(); 
    return 0;
}

const Product& isLowerCode(const Product& p1, const Product& p2) {
    if(p1.getBCode() < p2.getBCode()) {
        return p1;
    } else {
        return p2;
    }
}