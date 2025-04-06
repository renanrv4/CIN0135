#include <iostream>
#include <string>

#include "queue.h"

int calcNumberCrossingBridges(Queue<int>& left_q, Queue<int>& right_q, int len) {
    int n_cross = 0;
    bool left_side = true;
    while(!left_q.empty() || !right_q.empty()) {
        int load = 0;
        Queue<int>& current = left_side ? left_q : right_q;
        while(!current.empty() && load + current.front() <= len) {
            load += current.front();
            current.pop();
        }
        n_cross++; if(left_side) { left_side = false; } else { left_side = true; }
    }
    return n_cross;
}

int main() {
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        int length, m; cin >> length >> m;
        length = length * 100;
        Queue<int> left, right;
        for(int j = 0; j < m; j++) {
            int l; string s; cin >> l >> s;
            if(s == "left") {
                left.push(l);
            } else {
                right.push(l);
            }
        }
        cout << calcNumberCrossingBridges(left, right, length) << "\n";
    }
    return 0;
}