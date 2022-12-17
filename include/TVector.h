#ifndef __TDynamicVector_H__
#define __TDynamicVector_H__

#include <iostream>

using namespace std;

template<class T>
class TDynamicVector
{
protected:
  int len;
  T* pMem;
public:
  TDynamicVector();
  TDynamicVector(int n);
  TDynamicVector(T* arr, int s);
  TDynamicVector(const TDynamicVector<T>& v);
  TDynamicVector(TDynamicVector<T>&& v) noexcept;
  ~TDynamicVector();
  int size();
  void Resize(int nlen);
  T& operator[](int i);
  const T& operator[](int i) const;
  bool operator==(const TDynamicVector<T>& v);
  bool operator!=(const TDynamicVector<T>& v);
  TDynamicVector<T> operator+(T n);
  TDynamicVector<T> operator-(double n);
  TDynamicVector<T> operator*(double n);
  TDynamicVector<T> operator+(const TDynamicVector<T>& v);
  TDynamicVector<T> operator-(const TDynamicVector<T>& v);
  TDynamicVector<T> operator*(const TDynamicVector<T>& v);
  TDynamicVector<T>& operator=(const TDynamicVector<T>& v);
  TDynamicVector<T>& operator=(TDynamicVector<T>&& v) noexcept;
  friend istream& operator>>(istream& istr, const TDynamicVector<T>& v);
  friend ostream& operator<<(ostream& ostr, const TDynamicVector<T>& v);
};
#endif

template<class T>
TDynamicVector<T>::TDynamicVector()
{
  len = NULL;
  pMem = nullptr;
}

template<class T>
inline TDynamicVector<T>::TDynamicVector(int n)
{
  if (n <= 0) throw "error";
  len = n;
  pMem = new T[len];
  for (int i = 0; i < len; i++)
    pMem[i] = 1;
}

template<class T>
inline TDynamicVector<T>::TDynamicVector(T* arr, int s)
{
  len = s;
  pMem = new T[len];
  for (int i = 0; i < len; i++)
    pMem[i] = arr[i];
}

template<class T>
inline TDynamicVector<T>::TDynamicVector(const TDynamicVector<T>& v)
{
  len = v.len;
  if (v.len == 0)
    pMem = nullptr;
  else
    pMem = new T[len];
  for (int i = 0; i < len; i++)
    pMem[i] = v.pMem[i];
}

template<class T>
inline TDynamicVector<T>::TDynamicVector(TDynamicVector<T>&& v) noexcept
{
  pMem = v.pMem;
  len = v.len;
  v.pMem = nullptr;
  v.len = 0;
}

template<class T>
inline TDynamicVector<T>::~TDynamicVector()
{
  if (pMem != nullptr)
  {
    delete[] pMem;
    pMem = nullptr;
  }
  len = NULL;
}

template<class T>
inline int TDynamicVector<T>::size()
{
  return len;
}

template<class T>
inline void TDynamicVector<T>::Resize(int nlen)
{
  if (nlen < 0) throw "error";
  TDynamicVector<T> res(*this);
  delete[] pMem;
  pMem = new T[nlen];
  for (int i = 0; i < min(nlen, res.len); i++)
  {
    pMem[i] = res.pMem[i];
  }
  if (nlen > res.len)
    for (int j = res.len; j < nlen; j++)
      pMem[j] = 0;
  len = nlen;
}

template<class T>
inline T& TDynamicVector<T>::operator[](int i)
{
  if (len == 0) throw "error";
  if ((i < 0) || (i > len)) throw "not found";
  return pMem[i];
}

template<class T>
inline const T& TDynamicVector<T>::operator[](int i) const
{
  if (len == 0) throw "error";
  if ((i < 0) || (i > len)) throw "not found";
  return pMem[i];
}

template<class T>
inline bool TDynamicVector<T>::operator==(const TDynamicVector<T>& v)
{
  if (len != v.len) return false;
  else
  {
    for (int i = 0; i < len; i++)
      if (pMem[i] != v.pMem[i])
        return false;
  }
  return true;
}

template<class T>
inline bool TDynamicVector<T>::operator!=(const TDynamicVector<T>& v)
{
  if (len != v.len) return true;
  else
  {
    for (int i = 0; i < len; i++)
      if (pMem[i] != v.pMem[i])
        return true;
  }
  return false;
}

template<class T>
inline TDynamicVector<T> TDynamicVector<T>::operator+(T n)
{
  if (n == 0) return *this;
  TDynamicVector<T> res(*this);
  {
    for (int i = 0; i < len; i++)
      res.pMem[i] = res.pMem[i] + n;
  }
  return res;
}

template<class T>
inline TDynamicVector<T> TDynamicVector<T>::operator-(double n)
{
  if (n == 0) return *this;
  TDynamicVector<T> res(*this);
  {
    for (int i = 0; i < len; i++)
      res.pMem[i] = res.pMem[i] - n;
  }
  return res;
}

template<class T>
inline TDynamicVector<T> TDynamicVector<T>::operator*(double n)
{
  if (n == 0) pMem = nullptr;
  TDynamicVector<T> res(*this);
  {
    for (int i = 0; i < len; i++)
      res.pMem[i] = res.pMem[i] * n;
  }
  return res;
}

template<class T>
inline TDynamicVector<T> TDynamicVector<T>::operator+(const TDynamicVector<T>& v)
{
  TDynamicVector<T> res(*this);
  if ((len == v.len) && (v.pMem != 0) && (pMem != 0))
  {
    for (int i = 0; i < len; i++)
      res.pMem[i] = res.pMem[i] + v.pMem[i];
  }
  else
    throw "error";
  return res;
}

template<class T>
inline TDynamicVector<T> TDynamicVector<T>::operator-(const TDynamicVector<T>& v)
{
  TDynamicVector<T> res(*this);
  if ((len == v.len) && (v.pMem != 0) && (pMem != 0))
  {
    for (int i = 0; i < len; i++)
      res.pMem[i] = res.pMem[i] - v.pMem[i];
  }
  else
    throw "error";
  return res;
}

template<class T>
inline TDynamicVector<T> TDynamicVector<T>::operator*(const TDynamicVector<T>& v)
{
  TDynamicVector<T> res(*this);
  if ((len == v.len) && (v.pMem != 0) && (pMem != 0))
  {
    for (int i = 0; i < len; i++)
      res.pMem[i] = res.pMem[i] * v.pMem[i];
  }
  else
    throw "error";
  return res;
}

template<class T>
inline TDynamicVector<T>& TDynamicVector<T>::operator=(const TDynamicVector<T>& v)
{
  if (this == &v) return *this;
  if (v.pMem == 0)
  {
    delete[] pMem;
    pMem = 0;
    len = 0;
    return *this;
  }
  if (pMem != 0)
    delete[] pMem;
  len = v.len;
  pMem = new T[len];
  for (int i = 0; i < len; i++)
    pMem[i] = v.pMem[i];
  return *this;
}

template<class T>
inline TDynamicVector<T>& TDynamicVector<T>::operator=(TDynamicVector<T>&& v) noexcept
{
  if (this != &v)
  {
    delete[] pMem;
    pMem = v.pMem;
    len = v.len;
    v.pMem = nullptr;
    v.len = 0;
  }
  return *this;
}

template <class T>
std::ostream& operator<<(std::ostream& ostr, TDynamicVector<T>& v)
{
  for (int i = 0; i < v.size(); i++)
    ostr << v[i] << ' ';
  return ostr;
}

template <class T>
std::istream& operator>>(std::istream& istr, TDynamicVector<T>& v)
{
  T a = 0;
  std::cout << "Enter your vector = " << std::endl;
  for (int i = 0; i < v.size(); i++)
  {
    istr >> a;
    v[i] = a;
  }
  return istr;
}