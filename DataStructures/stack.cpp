#include <iostream>
#include <assert.h>
using namespace std;
// 13 mins to code after C#
// 19 mins on whiteboard
template <class T>
class Stack
{
  private:
    struct Node
    {
        T data;
        Node *next;
    } * top;

    int n;

  public:
    Stack()
    {
        top = NULL;
        n = 0;
    }
    void push(T v)
    {
        Node *oldTop = top;
        top = new Node();
        top->data = v;
        top->next = oldTop;
        n++;
    }

    bool isEmpty()
    {
        return n == 0;
    }

    int size()
    {
        return n;
    }

    T pop()
    {
        T item;
        if (isEmpty())
            cout << "Stack is empty" << endl;
        else
        {
            item = top->data;
            top = top->next;
        }
        n--;
        return item;
    }
};
template <class T>
class ResizingStack
{
  private:
    T* a;

    int n;
    int size;

    void resize(int l)
    {
        T* t = new T[l];
        size = l;
        for (int i = 0; i < n; i++)
            a[i] = t[i];
        a = t;
    }

  public:
    ResizingStack()
    {
        a = new T[1];
        size = 1;
        n = 0;
    }
    void push(T v)
    {
        if (n == size - 1)
            resize(2 * size);
        a[n++] = v;
    }

    bool isEmpty()
    {
        return n == 0;
    }

    int GetSize()
    {
        return n;
    }

    T pop()
    {
        if (n < size/4)
            resize(size/2);
        T item;
        if (isEmpty())
            cout << "Stack is empty" << endl;
        else
        {
            item = a[--n];
        }

        return item;
    }
};

int main()
{
    ResizingStack<string> *rs = new ResizingStack<string>();
    assert(rs->isEmpty());
    rs->push("abc");
    assert(!rs->isEmpty());
    assert(1 == rs->GetSize());
    rs->push("xyz");
    assert(2 == rs->GetSize());
    rs->push("pqr");
    assert(3 == rs->GetSize());

    assert("pqr" == rs->pop());
    assert(2 == rs->GetSize());
    assert("xyz" == rs->pop());
    assert(1 == rs->GetSize());

    Stack<string> *s = new Stack<string>();
    assert(s->isEmpty());
    s->push("abc");
    assert(!s->isEmpty());
    assert(1 == s->size());
    s->push("xyz");
    assert(2 == s->size());
    s->push("pqr");
    assert(3 == s->size());

    assert("pqr" == s->pop());
    assert(2 == s->size());
    assert("xyz" == s->pop());
    assert(1 == s->size());
}