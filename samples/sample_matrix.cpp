#include <iostream>
#include "TSquareMatrix.h"
int main()
{
  TTriangleDynamicMatrix<int> a(5), b(5), c(5);
  TSquareDynamicMatrix<int> f(5), d(5), v(5);
  TDynamicVector<int> k(5), r(5);
  setlocale(LC_ALL, "Russian");
  std::cout << "“естирование класс работы с матрицами" << std::endl;
  for (int i = 0; i < 5; i++)
    for (int j = 0; j <= i; j++)
    {
      a[i][j] = i * 10 + j;
      b[i][j] = (i * 10 + j) * 100;
    }
  c = a + b;
  cout << "Matrix a = " << endl << a << endl;
  cout << "Matrix b = " << endl << b << endl;
  cout << "Matrix c = a + b" << endl << c << endl;
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
    {
      f[i][j] = i + 1;
      d[i][j] = i + 1;
    }
  v = f * d;
  r = v * k;
  cout << "Matrix f = " << endl << f << endl;
  cout << "Matrix d = " << endl << d << endl;
  cout << "Matrix v = f + d" << endl << v << endl;
  cout << "Vector k = " << endl << k << endl;
  cout << "Vector r = v * k" << endl << r << endl;
}