#include "date.h"
#include "date.cpp"
#include <iostream>

using namespace std;

int main() {
    Date today, birthday, assign;
    // Data de hoje
    today.init();
    today.print();
    // Data específica
    birthday.init(6, 1, 2005);
    birthday.print();

    // Alguns testes
    assign = today;
    assign.print();

    Date* pbirth = &birthday;
    pbirth->print();

    Date &dref = today;
    dref.init(12, 31, 2024);
    today.print();
    return 0;
}