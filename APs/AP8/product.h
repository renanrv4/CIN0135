#ifndef _PRODUCT_
#define _PRODUCT_

#include <bits/stdc++.h>

using namespace std;

class Product {
    private:
        long barcode;
        string name;
    public:
        Product(long b=0L, const string& n="noname") {
            barcode = b;
            name = n;
        }
        void setBCode(long b) { barcode = b; }
        long getBCode() const { return barcode; }
        void setName(const string& n) { name = n; }
        string getName() const { return name; }

        virtual void scanner() {
            cout << "Barcode: " << "\n";
            cin >> barcode;
            cout << "Name: "    << "\n";
            cin >> name;
            cin.sync(); cin.clear();
        }
        virtual void print() const {
            cout << "---------- Product Info ----------" << "\n"
                    << "Barcode: " << barcode << "\n"
                    << "Name: "    << name << "\n"; 
        }


};

class PrepackedFood : public Product {
    private:
        double uprice;
    public:
        PrepackedFood(double p=0.0, long b=0L, const string& n="noname") {
            Product::setBCode(b);
            Product::setName(n);
            uprice = p;
        }
        void setUPrice(double p) { uprice = p; }
        double getUPrice() const { return uprice; }
        void scanner() {
            Product::scanner();
            cout << "Unit price: " << "\n";
            cin >> uprice;
        }
        void print() const {
            Product::print();
            cout << fixed << setprecision(2) << "Unit price: " << uprice << "\n";
        }

};

class FreshFood : public Product {
    private:
        double weight;
        double prkilo;
    public:
        FreshFood(double w=0.0, double pk=0.0, long b=0L, const string& n="noname") {
            Product::setBCode(b);
            Product::setName(n);
            weight = w; prkilo = pk;
        }
        void setWeight(double w) { weight = w; }
        double getWeight() const { return weight; }
        void setPKilo(double pk) { prkilo = pk; }
        double getPKilo() const { return prkilo; }
        
        void scanner() {
            Product::scanner();
            cout << "Weight: " << "\n"; cin >> weight;
            cout << "Price per kilo: " << "\n"; cin >> prkilo;
        }
        void print() const {
            Product::print();
            cout << "Weight: " << weight << "\n"
                 << "Price per kilo: " << prkilo << "\n";
        }

};      

#endif