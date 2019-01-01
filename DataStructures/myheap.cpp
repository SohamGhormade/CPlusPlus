#include <iostream>
#include <assert.h>
using namespace std;
//Works Fine.
//Implement a *Min* Heap in C++.
template <class T>
class Heap
{
  private:
    T *a; //note the difference---[] at the end for array
    int n;

    //bottom-up reheapify
    // up-> limit is k =1 and we are traversing parents of current element
    void swim(int k)
    {
        while (k > 1)
        {
            if (a[k] < a[k / 2])
                swap(k, k / 2);
            k = k / 2;
        }
    }
    //top down reheapify
    // bottom -> n =1 is the limit and we are traversing children of current element

    void sink(int k)
    {
        int child = 0;
        while (child <= n)
        {
            child = 2 * k;
            if (a[child] > a[child + 1])
                child++;

            if (a[k] > a[child])
                swap(k, child);
            k = child;
        }
    }
    void swap(int i, int j)
    {
        T t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

  public:
    Heap()
    {
        a = new T[100]; //hack
        a[0] = 'Z';     //sentinel
        n = 0;
    }
    void insert(T v)
    {
        a[++n] = v;
        swim(n);
    }
    T peek()
    {
        return a[1];
    }
    T delMin()
    {
        T t = a[1];
        swap(1, n - 1);
        a[n - 1] = NULL; //avoid loittering
        //myheap.cpp:62:18: warning: converting to non-pointer type ‘char’ from NULL [-Wconversion-null]
        //a[n - 1] = NULL; //avoid loittering
        sink(1);
        n--;
        return t;
    }

    int size()
    {
        return n;
    }
    bool isEmpty()
    {
        return n == 0;
    }
};

int main()
{
    Heap<char> heap;
    assert(heap.isEmpty());

    heap.insert('S');
    assert(!heap.isEmpty());
    assert(heap.size() == 1);
    assert('S' == heap.peek());

    heap.insert('E');
    assert('E' == heap.peek());

    heap.insert('A');
    assert('A' == heap.peek());

    heap.insert('R');
    assert('A' == heap.peek());

    heap.insert('C');
    heap.insert('H');
    assert(heap.size() == 6);
    assert('A' == heap.peek());
    assert('A' == heap.delMin());
    assert(heap.size() == 5);
    assert('C' == heap.delMin());
    assert(heap.size() == 4);

    return 1;
}
