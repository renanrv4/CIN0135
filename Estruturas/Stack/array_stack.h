#ifndef _ARRAYSTACK_
#define _ARRAYSTACK_

#include "stack.h"

using namespace std;

template <typename E>
class ArrayStack : public Stack<E>{
    private:
        int maxsize;
        int top;
        E* stack;
    public:
        ArrayStack(int size = 0) {
            maxsize = size; top = 0;
            stack = new E[maxsize];
        }
        ~ArrayStack() { delete [] stack; clear(); }
        void clear() { top = 0; }

        void push(const E& item) {
            if(top != maxsize) {
                stack[top++] = item;
            }
        }
        void pop() { if(top != 0) { stack[--top]; } }

        const E& topValue() const {
            if(top != 0) {
                return stack[top-1];
            }
        }
        
        int length() const { return top; }
};

#endif