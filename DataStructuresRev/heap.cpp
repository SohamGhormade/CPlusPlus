//Implement a min heap in C++.
#include <iostream>
#include <assert.h>

using namespace std;
//15 mins whiteboard
//12 mins code
template <class T>
class Heap
{
  private:
    int n;
    T *a;

    // bottom up reheapify
    void swim(int k)
    {
        while (k > 1)
        {
            if (a[k] < a[k / 2])
                swap(k, k / 2);
            k = k / 2;
        }
    }
    // top down reheapify
    void sink(int k)
    {
        int child = 0;
        while (2 * k < n)
        {
            child = 2 * k;
            if (a[child] > a[child + 1])
                child++;

            if (a[child] < a[k])
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
        a = new T[1000];
        a[0] = 10000; //sentinel
    }
    void insert(T value)
    {
        a[++n] = value;
        swim(n);
    }

    T delMin()
    {
        T min = a[1];
        swap(1, n - 1);
        a[n - 1] = NULL;
        n--;
        sink(1);
        return min;
    }
    T peek()
    {
        return a[1];
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
    Heap<int> *heap = new Heap<int>();
    assert(heap->isEmpty());

    heap->insert(20);
    assert(heap->peek() == 20);
    assert(!heap->isEmpty());
    assert(heap->size() == 1);

    heap->insert(2);
    assert(heap->peek() == 2);
    assert(heap->size() == 2);

    heap->insert(4);
    assert(heap->peek() == 2);
    assert(heap->size() == 3);

    heap->insert(50);
    assert(heap->peek() == 2);
    assert(heap->size() == 4);

    heap->insert(7);
    assert(heap->peek() == 2);
    assert(heap->size() == 5);

    heap->insert(3);
    assert(heap->peek() == 2);
    assert(heap->size() == 6);

    heap->insert(1);
    assert(heap->peek() == 1);
    assert(heap->size() == 7);

    assert(1 == heap->delMin());
    assert(heap->peek() == 2);
    assert(heap->size() == 6);

    assert(2 == heap->delMin());
    cout<<heap->peek()<<endl;
    assert(heap->peek() == 4);
    assert(heap->size() == 5);

    heap->insert(3);
    assert(heap->size() == 6);

    assert(3 == heap->delMin());
    assert(heap->peek() == 4);
    assert(heap->size() == 5);

    return 1;
}