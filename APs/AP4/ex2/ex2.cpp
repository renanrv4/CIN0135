#include "article.h"
#include "article.cpp"
#include <iostream>
#include <string>

using namespace std;

void test();

Article Article1( 1111,"volley ball", 59.9);
// Utilizando construtores-cópia e métodos de acesso
int main() {
    cout << "\nThe first statement in main().\n" << endl;
    Article Article2( 2222,"gym-shoes", 199.99);
    Article1.print();
    Article2.print();
    Article& shoes = Article2;
    shoes.setNumber(2233);
    shoes.setName("jogging-shoes");
    shoes.setPrice( shoes.getPrice() - 50.0);
    cout << "\nThe new values of the shoes object:\n";
    shoes.print();
    cout << "\nThe first call to test()." << endl;
    test();
    cout << "\nThe second call to test()." << endl;
    test();
    cout << "\nThe last statement in main().\n" << endl;
    return 0;
}

void test() {
    Article shirt(108, "T-shirt", 30.50);
    shirt.print();
    static Article net(200, "Net", 40.85);
    net.print();
    Article copyArticle(shirt);
    copyArticle.print();
    cout << "End of test" << "\n";
}
