#ifndef __TTriangleDynamicMatrix_H__
#define __TTriangleDynamicMatrix_H__

#include <iostream>
#include "TVector.h"

using namespace std;

template<class T>
class TTriangleDynamicMatrix : protected TDynamicVector<TDynamicVector<T>>
{
  using TDynamicVector<TDynamicVector<T>>::pMem;
  using TDynamicVector<TDynamicVector<T>>::len;
public:
  using TDynamicVector<TDynamicVector<T>>::operator[];
  using TDynamicVector<TDynamicVector<T>>::size;
  TTriangleDynamicMatrix();
  TTriangleDynamicMatrix(int n);
  TTriangleDynamicMatrix(const TTriangleDynamicMatrix<T>& m);
  bool operator==(const TTriangleDynamicMatrix<T>& m);
  bool operator!=(const TTriangleDynamicMatrix<T>& m);
  TTriangleDynamicMatrix<T> operator*(const T& v);
  TDynamicVector<T> operator*(TDynamicVector<T>& v);
  TTriangleDynamicMatrix<T> operator+(const TTriangleDynamicMatrix<T>& m);
  TTriangleDynamicMatrix<T> operator-(const TTriangleDynamicMatrix<T>& m);
  TTriangleDynamicMatrix<T> operator*(const TTriangleDynamicMatrix<T>& m);
  TTriangleDynamicMatrix<T> operator=(const TTriangleDynamicMatrix<T>& m);
  friend istream& operator>>(istream& istr, const TTriangleDynamicMatrix<T>& m);
  friend ostream& operator<<(ostream& ostr, const TTriangleDynamicMatrix<T>& m);
};
#endif

template<class T>
inline TTriangleDynamicMatrix<T>::TTriangleDynamicMatrix()
{
  this->len = NULL;
  this->pMem = nullptr;
}

template<class T>
inline TTriangleDynamicMatrix<T>::TTriangleDynamicMatrix(int n)
{
  if (n <= 0) throw "error";
  this->len = n;
  if (this->pMem != nullptr)
    delete[] this->pMem;
  this->pMem = new TDynamicVector<T>[this->len];
  for (int i = 0; i < this->len; i++)
    this->pMem[i] = TDynamicVector<T>(i + 1);
}

template<class T>
inline TTriangleDynamicMatrix<T>::TTriangleDynamicMatrix(const TTriangleDynamicMatrix<T>& m)
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
inline bool TTriangleDynamicMatrix<T>::operator==(const TTriangleDynamicMatrix<T>& m)
{
  return TDynamicVector < TDynamicVector<T>> :: operator==(m);
}

template<class T>
inline bool TTriangleDynamicMatrix<T>::operator!=(const TTriangleDynamicMatrix<T>& m)
{
  return TDynamicVector < TDynamicVector<T>> :: operator!=(m);
}

template<class T>
inline TTriangleDynamicMatrix<T> TTriangleDynamicMatrix<T>::operator*(const T& v)
{
  TTriangleDynamicMatrix<T> res(*this);
  for (int i = 0; i < len; i++)
    res.pMem[i] = pMem[i] * v;
  return res;
}

template<class T>
inline TDynamicVector<T> TTriangleDynamicMatrix<T>::operator*(TDynamicVector<T>& v)
{
  if (this->len != v.size()) throw "error";
  TDynamicVector<T> res(this->len);
  for (int i = 0; i < len; i++)
  {
    res[i] = 0;
    for (int j = 0; j <= i; j++)
      res[j] += this->pMem[i][j] * v[i];
  }
  return res;
}

template<class T>
inline TTriangleDynamicMatrix<T> TTriangleDynamicMatrix<T>::operator+(const TTriangleDynamicMatrix<T>& m)
{
  if (m.len != len) throw "error";
  TTriangleDynamicMatrix<T> res(*this);
  for (int i = 0; i < len; i++)
    res.pMem[i] = pMem[i] + m.pMem[i];
  return res;
}

template<class T>
inline TTriangleDynamicMatrix<T> TTriangleDynamicMatrix<T>::operator-(const TTriangleDynamicMatrix<T>& m)
{
  if (m.len != len) throw "error";
  TTriangleDynamicMatrix<T> res(*this);
  for (int i = 0; i < len; i++)
    res.pMem[i] = pMem[i] - m.pMem[i];
  return res;
}

template<class T>
inline TTriangleDynamicMatrix<T> TTriangleDynamicMatrix<T>::operator*(const TTriangleDynamicMatrix<T>& m)
{
  if (m.len != len) throw "error";
  TTriangleDynamicMatrix<T> res(*this);
  for (int i = 0; i < len; i++)
    for (int j = 0; j <= i; j++)
    {
      res[i][j] = 0;
      for (int k = j; k <= i; k++)
        res.pMem[i][j] += m.pMem[i][k] * pMem[k][j];
    }
  return res;
}

template<class T>
inline TTriangleDynamicMatrix<T> TTriangleDynamicMatrix<T>::operator=(const TTriangleDynamicMatrix<T>& m)
{
  TDynamicVector<TDynamicVector<T>>::operator=(m);
  return *this;
}

template<class T>
std::istream& operator>>(std::istream& istr, TTriangleDynamicMatrix<T>& m)
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
std::ostream& operator<<(std::ostream& ostr, TTriangleDynamicMatrix<T>& m)
{
  for (int i = 0; i < m.size(); i++)
  {
    for (int j = 0; j < i + 1; j++)
    {
      ostr << m[i][j] << ' ';
    }
    std::cout << std::endl;
  }
  return ostr;
}