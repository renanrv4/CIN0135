#include <bits/stdc++.h>

using namespace std;

int main() {
    string s1 = "As time by ...", s2 = "goes ";
    // Adicionando uma substring s2 dentro de s1
    s1.insert(s1.find("by"), s2);
    cout << "Result 1: " << "\n";
    cout << s1 << "\n";

    // Apagando "..." de s1
    s1.erase(s1.find("by") + 3);
    cout << "Result 2: " << "\n";
    cout << s1 << "\n";

    // Substituindo "time" por "Bill"
    s1.replace(s1.find("time"), 4, "Bill");
    cout << "Result 3: " << "\n";
    cout << s1 << "\n";
    return 0;
}