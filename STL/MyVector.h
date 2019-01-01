/**
 * Header file for a C++ vector.
 * Dynamic array implementation.
 *
*/
#include<iterator>
using namespace std;
#ifndef MY_VECTOR
#define MY_VECTOR

template<class T>
class MyVector{
    private:
            T[] arr_;

    public:
           /**
            * @brief Constructor
           */
           MyVector();
           /**
            * @brief Destructor
           */
           ~MyVector();
           void push_back(const T& d);
           void resize (size_t n);
           void pop_back();
           size_t size() const;
           bool empty() const;
           void insert(int index, T d);
};
#endif