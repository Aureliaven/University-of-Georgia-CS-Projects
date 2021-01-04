// driver
#include "Matrix.h"

int main() {
  Matrix a(3, 3);
  a.at(0,0) = 3;
  a.at(0,1) = 2;
  a.at(0,2) = 4;
  a.at(1,0) = 1;
  a.at(1,1) = 2;
  a.at(1,2) = 0;
  a.at(2,0) = 2;
  a.at(2,1) = 5;
  a.at(2,2) = 0;
  cout << "Matrix A" << endl;
  cout << a << endl;

  Matrix b(a);
  cout << "Matrix B (Copy of A)" << endl;
  cout << b << endl;

  Matrix c = a + b;
  cout << "Matrix C (Sum of A and B)" << endl;
  cout << c << endl;

  Matrix d = c - 3;
  cout << "Matrix D (C - 3)" << endl;
  cout << d << endl;

  Matrix e(2, 2);
  Matrix f(1, 2);
  e.at(0,0) = 2;
  e.at(0,1) = 3;
  e.at(1,0) = 1;
  e.at(1,1) = 2;
  f.at(0,0) = 2;
  f.at(0,1) = 3;
  cout << "Matrices E and F" << endl;
  cout << e << endl;
  cout << f << endl;

  Matrix g = e * f;
  cout << "Matrix G (Product of E and F)" << endl;
  cout << g << endl;
  cout << "Negative G" << endl;
  cout << -g << endl;
  
  Matrix h = g / 2;
  cout << "Matrix H (G / 2)" << endl;
  cout << h << endl;

  Matrix i = g * 2;
  cout << "Matrix I (G * 2)" << endl;
  cout << i << endl;
  
  return 0;
}
