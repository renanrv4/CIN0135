#include <iostream>
#include <iomanip>

using namespace std;

// Correção de erros no código original
int main() {
  char ch;
  string word;
  cout << "Let's go! Press the return key: ";
  cin >> ch;
  cout << "Enter a word containing three characters at most: ";
  cin >> setprecision(3) >> word;
  cout << "Your input: " << ch << endl;
  cout << "Your input: " << word << endl;
  return 0;
}
