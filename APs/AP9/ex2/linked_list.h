#ifndef _LINKEDLIST_
#define _LINKEDLIST_

#include <cassert>
#include <iostream>

using namespace std;

template <typename E>
class LinkedList {
    private:
        struct Node {
            int item;
            Node* next;
            Node(int it, Node* n = NULL) {
                item = it; next = n;
            }
            Node(Node* n = NULL) {
                next = n;
            }
        };
        Node* head;
        Node* tail;
        Node* curr;
        int size;
    public:
        LinkedList() {
            head = tail = curr = new Node; 
            size = 0;
        }
        ~LinkedList() { clear(); }
        void clear() {
            while(head != NULL) {
                curr = head;
                head = head->next;
                delete curr;
            }
            curr = tail = head = new Node;
            size = 0;
        }

        void insert(const E& item) {
            curr->next = new Node(item, curr->next);
            if(tail == curr) {
                tail = curr->next;
            }
            size++;
        }
        void append(const E& item) {
            tail = tail->next = new Node(item, NULL);
            size++;
        }
        E remove() {
            if(curr->next != NULL) {
                E item = curr->next->item;
                Node* temp_node = curr->next;
                if(tail = curr->next) { tail = curr; }
                curr->next = temp_node->next;
                delete temp_node;
                size--;
                return item;
            }
        }
        void moveToStart() { curr = head; }
        void moveToEnd() { curr = tail; }
        void prev() {
            if(curr = head) { return; }
            Node* temp = head;
            while(temp->next != curr) { temp = temp->next; }
            curr = temp;
        }
        void next() {
            if(curr != tail) {
                curr = curr->next;
            }
        }

        int length() { return size; }
        int currPos() {
            Node* temp = head;
            int i;
            for(i = 0; curr != temp; i++) {
                temp = temp->next;
            }
            return i;
        }

        void moveToPos(int pos) {
            if(pos >= 0 && pos <= size) {
                curr = head;
                for(int i = 0; i < pos; i++) {
                    curr = curr->next;
                }
            }
        }
        const E& getValue() const {
            if(curr->next != NULL) {
                return curr->next->item;
            }
        }

        int count(int num) {
            Node* temp_curr = curr;
            curr = head->next; int qtd = 0;
            while(curr != NULL) {
                if(curr->item == num) {
                    qtd++;
                }
                curr = curr->next;
            }
            curr = temp_curr;
            return qtd;
        }
};

#endif