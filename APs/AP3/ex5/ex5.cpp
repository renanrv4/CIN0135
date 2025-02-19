#include <bits/stdc++.h>

using namespace std;
namespace Tool1 { 
    #include "tool1.h" 
}
namespace Tool2 {
    #include "tool2.h"
}

int main() {
    // Testing both namespaces
    double n1, n2;
    cout << "Choose two values: " << "\n";
    cin >> n1 >> n2;
    cout << "Sum of the values: " << "\n";
    cout << Tool1::calculate(n1, n2) << "\n";
    cout << "Product of the values" << "\n";
    cout << Tool2::calculate(n1, n2) << "\n"; 
    return 0;
}