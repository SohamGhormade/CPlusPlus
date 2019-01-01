#include <iostream>
#include <assert.h>
#include<string>
using namespace std;
// Implement a queue in C++.
//Whiteboard 9 mins
// code ? mins
class ExceptionWithMessage : exception// custom exception class derived from base C++ exception class.
// the base class does not have a string parameter as argument
{
  private:
    string message;

  public:
    ExceptionWithMessage(string str)
    {
        message = str;
    }
};
template <class T>
class queue
{
  private:
    int n = 0;
    struct Node
    {
        T data;
        Node *next;
    };
    Node *f =NULL, *l =NULL;

  public:
    //O(1)
    void enqueue(T v)
    {
        Node *oldL = l;
        l = new Node();
        l->data = v;

        if (oldL == NULL)
            f = l;
        else
            oldL->next = l;

        n++;
    }

    //O(1)
    T dequeue()
    {
        if (isEmpty())
            throw new ExceptionWithMessage("No elements to remove.");

        T item = f->data;
        f = f->next;
        n--;
        return item;
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
int main(int argc, char const *argv[])
{
    queue<int> q;
    assert(q.isEmpty());
    assert(q.size()==0);

    q.enqueue(5);
    q.enqueue(1);
    q.enqueue(7);
    q.enqueue(3);

    assert(q.size()==4);
    assert(q.dequeue()==5);
    assert(q.dequeue()==1);
    assert(q.dequeue()==7);
    assert(q.dequeue()==3);
    assert(q.isEmpty());
    assert(q.size()==0);

   /* code */
    return 0;
}
