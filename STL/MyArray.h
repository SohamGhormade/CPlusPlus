#include "MyInterator.h"
template<class T>
class MyArray{
     private:
            MyIterator<T> begin_;
            MyIterator<T> end_;
            int count_;
            T[] arr_;
     public:
            MyArray(int size);
            ~MyArray();
            size_t size() const;
            bool empty() const;
};

