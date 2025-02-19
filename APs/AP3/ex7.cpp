#include <iostream>
using namespace std;

void swap(float*, float*);

// Trocando os valores de x e y passando por referência
int main() {
  float x = 2.1;
  float y = 3.2;

  swap(&x, &y);
  cout << "x = " << x << ", y = " << y << endl;

  return 0;
}

void swap(float *p1, float *p2) {
    float temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
