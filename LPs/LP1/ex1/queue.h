#ifndef _QUEUE_
#define _QUEUE_

using namespace std;

template <typename E>
class Link {
    public:
        E elem;
        Link *next;

        Link(const E& elemv, Link* nextv = NULL) {
            elem = elemv; next = nextv;
        }
        Link(Link* nextv = NULL) {
            next = nextv;
        }
};

template <typename E>
class Queue {
    private:
        Link<E>* head;
        Link<E>* tail;
        int size;

        void init() {
            tail = head = new Link<E>;
            size = 0;
        }
    public:
        Queue() { init(); }
        ~Queue() {
            while(!empty()) {
                pop();
            }
            delete head;
        }

        void push(const E& element) {
            head->next = new Link<E>(element, head->next);
            size++;
            if(size == 1) {
                tail = head->next;
            }
            
        }
        void pop() {
            if(size > 0) {
                Link<E>* lhead = head->next;
                head->next = lhead->next;
                if(lhead == tail) { tail = head; }
                delete lhead;
                size--;
            }
        }
        E front() {
            if(!empty()) {
                return head->next->elem;
            }   
        }
        bool empty() {
            return size == 0;
        }
};

#endif