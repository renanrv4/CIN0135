#ifndef _LINKEDQUEUE_
#define _LINKEDQUEUE_

#include "queue.h"

using namespace std;

template <typename E>
class LinkedQueue : public Queue<E> {
    private:
        struct Node {
            E elem;
            Node *next;
            Node(const E& elemv, Node* nextv = NULL) { elem = elemv; next = nextv; }
            Node(Node* nextv = NULL) { next = nextv; }
        };
        Node* front;
        Node* rear;
        int size;
    public:
        LinkedQueue() {
            front = rear = new Node;
            size = 0;
        }
        ~LinkedQueue() { clear(); delete front; }
        void clear() {
            while(front->next == NULL) {
                rear = front;
                delete rear;
            }
            rear = front;
            size = 0;
        }

        void enqueue(const E& item) {
            rear->next = new Node(item, NULL);
            rear = rear->next; size++;
        }
        void dequeue() {
            if(size > 0) {
                Node* temp_node = front->next;
                front->next = temp_node->next;
                if(rear == temp_node) { rear = front; }
                delete temp_node;
                size--;
            }
        }

        const E& frontValue() const {
            if(size > 0) {
                return front->next->element;
            }
        }
        int length() const { return size; }
};

#endif