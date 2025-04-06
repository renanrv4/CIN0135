#include <iostream>
#include <string>
#include "linked_stack.h"

using namespace std;

int main() {
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        cout << "Caso " << i+1 << "\n";
        LinkedStack<int>* lstack = new LinkedStack<int>;
        string command; cin >> command;
        while(true) {
            if(command == "end") {
                break;
            } else if(command == "push") {
                int num; cin >> num;
                lstack->push(num);
            } else if(command == "pop") {
                int num; cin >> num;
                int top_sum = 0;
                for(int i = 0; i < num; i++) {
                    top_sum += lstack->topValue();
                    lstack->pop();
                }
                cout << top_sum << "\n";
            }
            cin >> command;
        }
    }
    return 0;
}