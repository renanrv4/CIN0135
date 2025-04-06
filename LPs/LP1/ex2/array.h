#ifndef _ARRAY_
#define _ARRAY_

#include <stdexcept>

using namespace std;

template <typename E>
class Array {
    private:
        int maxsize;
        int listsize;
        int currpos;
        E* listarray;
    
    public:
        Array(int size = 0) {
            maxsize = size;
            listsize = currpos = 0;
            listarray = new E[maxsize];
        }

        ~Array() { delete [] listarray; }
        void clear() {
            delete [] listarray;
            listsize = currpos = 0;
            listarray = new E[maxsize];
        }

        void insert(const E& item) {
            if(listsize < maxsize) {
                for(int i = listsize; i > currpos; i--) {
                    listarray[i] = listarray[i-1];
                }
                listarray[currpos] = item;
                listsize++;
            } else {
                throw runtime_error("Tamanho excedido");            
            }
        }

        E remove() {
            if(listsize > 0) {
                E item = listarray[currpos];
                for(int i = currpos; i < listsize-1; i++) {
                    listarray[i] = listarray[i+1];
                }
                listsize--;
                return item;
            } else {
                throw length_error("Lista vazia");
            }
        }


        void moveToStart() { currpos = 0; }
        void moveToEnd() { currpos = listsize; }
        void prev() { if(currpos != 0) { currpos--; } }
        void next() { if(currpos < listsize) { currpos++; } }

        int length() const { return listsize; }
        int curr() const { return currpos; }

        void moveToPos(int pos) {
            if(pos >= 0 && pos <= listsize) {
                currpos = pos;
            } else {
                throw length_error("Index inválido");
            }
        }

        const E& getValue() const {
            if(listsize > 0) {
                return listarray[currpos];
            } else {
                throw length_error("Lista vazia");
            }
        }
};

#endif