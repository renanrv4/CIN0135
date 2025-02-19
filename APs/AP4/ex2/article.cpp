#include "article.h"
#include <iostream>
#include <iomanip>

using namespace std;

int Article::count = 0;

Article::Article(long number, const string& name, double price) {
    setNumber(number); setName(name); setPrice(price);
    ++count;
    cout << "An object of type Article" << name << " is created." << "\n";
    cout << "This is the " << getCount() << " Article." << "\n";
}

Article::Article(const Article& copyctt){
    setNumber(copyctt.number); setName(copyctt.name); setPrice(copyctt.price);
    ++count;
    cout << "A copy of type Article is created." << "\n";
    cout << "This is the " << getCount() << " Article." << "\n";
}

Article::~Article() {
    --count;
    cout << "The object of type Article " << name << " is destroyed.";
    cout << "There are still " << getCount() << " articles.";
}

void Article::print() {
    ios_base::fmtflags savedFlags = std::cout.flags();
    cout << fixed << setprecision(2)
    << "-----------------------------------------\n"
    << "Article data:\n"
    << "  Number ....:  " << number    << '\n'
    << "  Name   ....:  " << name  << '\n'
    << "  Sales price:  " << price    << '\n'
    << "-----------------------------------------"
    << "\n";
    cout.flags(savedFlags);
    cout << "  --- Go on with return --- ";
    cin.get();
}
