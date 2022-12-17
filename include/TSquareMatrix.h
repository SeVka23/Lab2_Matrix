#ifndef __TSquareDynamicMatrix_H__
#define __TSquareDynamicMatrix_H__

#include <iostream>
#include "TTriangleMatrix.h"

using namespace std;

template<class T>
class TSquareDynamicMatrix : protected TDynamicVector<TDynamicVector<T>>
{
  using TDynamicVector<TDynamicVector<T>>::pMem;
  using TDynamicVector<TDynamicVector<T>>::len;
public:
  using TDynamicVector<TDynamicVector<T>>::operator[];
  using TDynamicVector<TDynamicVector<T>>::size;
  TSquareDynamicMatrix();
  TSquareDynamicMatrix(int n);
  TSquareDynamicMatrix(const TSquareDynamicMatrix<T>& m);
  bool operator==(const TSquareDynamicMatrix<T>& m);
  bool operator!=(const TSquareDynamicMatrix<T>& m);
  TSquareDynamicMatrix<T> operator*(const T& v);
  TDynamicVector<T> operator*(TDynamicVector<T>& v);
  TSquareDynamicMatrix<T> operator+(const TSquareDynamicMatrix<T>& m);
  TSquareDynamicMatrix<T> operator-(const TSquareDynamicMatrix<T>& m);
  TSquareDynamicMatrix<T> operator*(const TSquareDynamicMatrix<T>& m);
  TSquareDynamicMatrix<T> operator=(const TSquareDynamicMatrix<T>& m);
  friend istream& operator>>(istream& istr, const TSquareDynamicMatrix<T>& m);
  friend ostream& operator<<(ostream& ostr, const TSquareDynamicMatrix<T>& m);
};
#endif

template<class T>
inline TSquareDynamicMatrix<T>::TSquareDynamicMatrix()
{
  this->len = NULL;
  this->pMem = nullptr;
}

template<class T>
inline TSquareDynamicMatrix<T>::TSquareDynamicMatrix(int n)
{
  if (n <= 0) throw "error";
  this->len = n;
  if (this->pMem != nullptr)
    delete[] this->pMem;
  this->pMem = new TDynamicVector<T>[this->len];
  for (int i = 0; i < this->len; i++)
    this->pMem[i] = TDynamicVector<T>(len);
}

template<class T>
inline TSquareDynamicMatrix<T>::TSquareDynamicMatrix(const TSquareDynamicMatrix<T>& m)
{
  if (m.len == 0)
    this->pMem = 0;
  if (m.len > 0)
    this->len = m.len;
  this->pMem = new TDynamicVector<T>[len];
  for (int i = 0; i < len; i++)
    this->pMem[i] = m.pMem[i];
}

template<class T>
inline bool TSquareDynamicMatrix<T>::operator==(const TSquareDynamicMatrix<T>& m)
{
  return TDynamicVector < TDynamicVector<T>> :: operator==(m);
}

template<class T>
inline bool TSquareDynamicMatrix<T>::operator!=(const TSquareDynamicMatrix<T>& m)
{
  return TDynamicVector < TDynamicVector<T>> :: operator!=(m);
}

template<class T>
inline TSquareDynamicMatrix<T> TSquareDynamicMatrix<T>::operator*(const T& v)
{
  TSquareDynamicMatrix<T> res(*this);
  for (int i = 0; i < len; i++)
    res.pMem[i] = pMem[i] * v;
  return res;
}

template<class T>
inline TDynamicVector<T> TSquareDynamicMatrix<T>::operator*(TDynamicVector<T>& v)
{
  if (this->len != v.size()) throw "error";
  TDynamicVector<T> res(this->len);
  for (int i = 0; i < len; i++)
  {
    res[i] = 0;
    for (int j = 0; j < len; j++)
      res[i] += this->pMem[i][j] * v[j];
  }
  return res;
}

template<class T>
inline TSquareDynamicMatrix<T> TSquareDynamicMatrix<T>::operator+(const TSquareDynamicMatrix<T>& m)
{
  if (m.len != len) throw "error";
  TSquareDynamicMatrix<T> res(*this);
  for (int i = 0; i < len; i++)
    res.pMem[i] = pMem[i] + m.pMem[i];
  return res;
}

template<class T>
inline TSquareDynamicMatrix<T> TSquareDynamicMatrix<T>::operator-(const TSquareDynamicMatrix<T>& m)
{
  if (m.len != len) throw "error";
  TSquareDynamicMatrix<T> res(*this);
  for (int i = 0; i < len; i++)
    res.pMem[i] = pMem[i] - m.pMem[i];
  return res;
}

template<class T>
inline TSquareDynamicMatrix<T> TSquareDynamicMatrix<T>::operator*(const TSquareDynamicMatrix<T>& m)
{
  if (m.len != len) throw "error";
  TSquareDynamicMatrix<T> res(*this);
  for (int i = 0; i < len; i++)
    for (int j = 0; j < len; j++)
    {
      res[i][j] = 0;
      for (int k = 0; k < len; k++)
        res.pMem[i][j] += pMem[i][k] * m.pMem[k][j];
    }
  return res;
}

template<class T>
inline TSquareDynamicMatrix<T> TSquareDynamicMatrix<T>::operator=(const TSquareDynamicMatrix<T>& m)
{
  TDynamicVector<TDynamicVector<T>>::operator=(m);
  return *this;
}

template<class T>
std::istream& operator>>(std::istream& istr, TSquareDynamicMatrix<T>& m)
{
  std::cout << "Enter your matrix = " << std::endl;
  for (int i = 0; i < m.size(); i++)
  {
    for (int j = 0; j < i + 1; j++)
    {
      istr >> m[i][j];
    }
  }
  return istr;
}

template<class T>
std::ostream& operator<<(std::ostream& ostr, TSquareDynamicMatrix<T>& m)
{
  for (int i = 0; i < m.size(); i++)
  {
    for (int j = 0; j < m.size(); j++)
    {
      ostr << m[i][j] << ' ';
    }
    std::cout << std::endl;
  }
  return ostr;
}