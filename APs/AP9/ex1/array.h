#ifndef _ARRAY_
#define _ARRAY_

#include <cassert>
#include <iostream>

using namespace std;

template <typename E>
class Array {
    private:
        int maxsize;
        int listsize;
        int curr;
        E* listArray;
    public:
        Array(int size = 0) {
            maxsize = size;
            listsize = curr = 0;
            listArray = new E[maxsize];
        }

        ~Array() { delete [] listArray; }

        void clear() {
            delete [] listArray;
            listsize = curr = 0;
            listArray = new E[maxsize];
        }

        void insert(const E& item) {
            assert(listsize < maxsize && "List capacity exceeded");
            for(int i = listsize; i > curr; i--) {
                listArray[i] = listArray[i-1];
            }
            listArray[curr] = item; listsize++;
        }

        void append(const E& item) {
            assert(listsize < maxsize && "List capacity exceeded");
            listArray[listsize++] = item;
        }

        E remove() {
            assert (((curr >= 0) &&  (curr <= listsize)) && "Empty list");
            if(curr == listsize) {
                E item = listArray[curr];
                return item;
            } else {
                E item = listArray[curr];
                for(int i = curr; i < listsize-1; i++) {
                    listArray[i] = listArray[i+1];
                }
                listsize--;
                return item;
            }
        }

        void moveToStart() { curr = 0; }
        void moveToEnd() { curr = listsize; }
        void prev() { if(curr != 0) { curr--; } }
        void next() { if(curr < listsize) { curr++; cout << curr << "\n"; }}

        int length() const { return listsize; }
        int currPos() const { return curr; }

        void moveToPos(int pos) {
            assert(((pos >= 0)&& (pos <= listsize)) && "Último elemento");
            curr = pos;
        }

        const E& getValue() const {
            assert( (curr >= 0)&&(curr < listsize) && "Empty List");
            return listArray[curr];
        }

        int count(E x) {
            int qtd = 0;
            for(int i = 0; i < listsize; i++) {
                if(listArray[i] == x) { qtd++; }
            }
            return qtd;
        }
};

#endif