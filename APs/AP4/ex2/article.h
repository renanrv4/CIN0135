#ifndef _ARTICLE_
#define _ARTICLE_

#include <string>

using namespace std;

class Article {
    private:
        long number;
        string name;
        double price;
        static int count;
    public:
        Article(long number=0, const string& name="noname", double price=0.0);
        Article(const Article& copy_constructor);
        ~Article();
        void print();

        inline long getNumber() { return number; }
        inline const string& getName() { return name; }
        inline double getPrice() { return price; }
        inline static int getCount() { return count; }

        void setNumber(long n) {
            number = n;
        }
        bool setName(const string& s) {
            if(s.size() < 1) {
                return false;
            }
            name = s;
            return true;
        }
        void setPrice(double p) {
            price = p > 0.0 ? p : 0.0;
        }
};

#endif