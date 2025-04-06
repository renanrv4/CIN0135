#ifndef _LINKEDSTACK_
#define _LINKEDSTACK_

#include "stack.h"

using namespace std;

template <typename E>
class LinkedStack : public Stack<E> {
    private:
        struct Node {
            int item;
            Node* next;
            Node(int it, Node* n = NULL) { item = it; next = n; }
            Node(Node* n = NULL) { next = n; }
        };
        Node* top;
        int size;
    public:
        LinkedStack() { top = NULL; size = 0; }
        ~LinkedStack() { clear(); }
        void clear() {
            while(top != NULL) {
                Node* temp = top;
                top = top->next;
                delete temp;
            }
            size = 0; 
        }

        void push(const E& item) { top = new Node(item, top); size++; }
        void pop() {
            if(top != NULL) {
                Node* temp = top;
                top = top->next;
                delete temp;
                size--;
            }
        }

        const E& topValue() const {
            if(top != NULL) {
                return top->item;
            }
        }
        int length() const { return size; }
};

#endif