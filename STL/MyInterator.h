#include<iterator>
using namespace std;

#ifndef MY_ITERATOR
#define MY_ITERATOR

template<class T>
class MyIterator:iterator<input_iterator_tag, T>
{       T* p;
        public:
                MyIterator(T* x) :p(x) {}
                MyIterator(const MyIterator& mit) : p(mit.p) {}
                MyIterator& operator++() {++p;return *this;}
                MyIterator operator++(int) {MyIterator tmp(*this); operator++(); return tmp;}
                bool operator==(const MyIterator& rhs) const {return p==rhs.p;}
                bool operator!=(const MyIterator& rhs) const {return p!=rhs.p;}
                int& operator*() {return *p;}

};
#endif