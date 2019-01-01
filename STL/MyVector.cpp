#include "MyVector.h"


template<class T>
MyVector<T>::MyVector()
{
    arr_ =new T[1];
}

template<class T>
MyVector<T>::~MyVector()
{
    arr_ = NULL;
}

template<class T>
void MyVector<T>::push_back(const T& val)
{
    arr_[0] = val;
}

template<class T>
void MyVector<T>::pop_back()
{

}