#include <iostream>
#include <assert.h>
#include <string>

using namespace std;
// Implement stack in C++.
// Both resizing and linked list based implementations.
// time in mins :whiteboard  computer
//                 13            24
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
class Stack
{
  private:
    struct Node
    {
        T data;
        Node *next;
    };
    Node *top;
    int n =0;// TODO initialize variables in C++.Otherwise they will be assigned garbage values.

  public:
    void push(T v)
    {
        Node *oldT = top;
        top = new Node();
        top->data = v;
        top->next = oldT;
        n++;
    }

    T pop()
    {
        if (isEmpty())
            throw new ExceptionWithMessage("No elements present in the stack.");
        T item = top->data;
        top = top->next;
        n--;
        return item;
    }

    bool isEmpty()
    {
        return n == 0;
    }

    int size()
    {
        return n;
    }
};

template <class T>
class MyStack
{
  private:
    int n = 0;
    int aSize = 1;
    T *a = new T[1];
    void resize(int size)
    {
        T *t = new T[size];
        aSize = size;

        int l = n < size ? n : size;
        for (int i = 0; i < l; i++)
        {
            t[i] = a[i];
        }
        t = a;
    }

  public:
    void push(T v)
    {
        if (n == aSize)
            resize(2 * n);
        a[n++] = v;
    }

    T pop()
    {
        if (isEmpty())
            throw new ExceptionWithMessage("No elements present in the stack.");

        T item = a[--n];
        a[n] = NULL;
        return item;
    }

    bool isEmpty()
    {
        return n == 0;
    }

    int size()
    {
        return n;
    }
};
int main(int argc, char const *argv[])
{
    MyStack<char> stack;

    assert(stack.isEmpty());
    stack.push('X');
    assert(!stack.isEmpty());
    assert(stack.size() == 1);

    stack.push('A');
    assert(stack.size() == 2);
    stack.push('P');
    stack.push('B');
    stack.push('U');
    assert(stack.size() == 5);

    assert('U' == stack.pop());
    assert(stack.size() == 4);

    assert('B' == stack.pop());
    assert(stack.size() == 3);

    assert('P' == stack.pop());
    assert(stack.size() == 2);

    assert('A' == stack.pop());
    assert(stack.size() == 1);

    stack.push('Z');
    assert('Z' == stack.pop());
    assert('X' == stack.pop());
    assert(stack.isEmpty());
    /* code */
    return 0;
}
