#include "MyArray.h"
template<class T>
MyArray<T>::MyArray(int size)
{
  arr_ = new T[size];
  begin_ = 0;
}

template<class T>
MyArray<T>::MyArray(int size)
{
  arr_ = new T[size];
  begin = 0;
  end =0;
}