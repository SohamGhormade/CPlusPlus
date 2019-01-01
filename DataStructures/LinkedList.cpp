#include <iostream>
#include <exception>
#include <assert.h>

using namespace std;
template <class T>
class LinkedList
{
  private:
    class Node
    {
      public:
        T data;
        Node *next;
    };

    Node *f, *l; //
    int n;       //size
  public:
    bool isEmpty()
    {
        return f == NULL;
    }
    int size()
    {
        return n;
    }
    void insertAtBeg(T v)
    {
        Node *t = new Node();
        t->data = v;
        if (isEmpty())
        {
            f = t;
            l = f;
        }
        else

        {
            Node *oldF = f;
            f = t;
            f->next = oldF;
        }
        n++;
    }

    void insertAtEnd(T v)
    {
        Node *t = new Node();
        t->data = v;
        if (isEmpty())
        {
            f = t;
            l = f;
        }
        else

        {
            Node *oldL = l;
            l = t;
            oldL->next = l;
        }
        n++;
    }

    T removeAtBeg()
    {
        T item;
        if (isEmpty())
            cout << "No elements to remove!" << endl;
        else
        {
            item = f->data;
            f = f->next;
        }
        n--;
        return item;
    }
    T removeAtEnd()
    {
        T item;
        if (isEmpty())
            cout << "No elements to remove!" << endl;
        else
        {
            Node *q = f;
            while (q->next != l)
                q = q->next;

            item = f->data;
            q = q->next;
        }
        n--;
        return item;
    }


};
 int main()
    {
        /* code */
        LinkedList<char> *l = new LinkedList<char>();
        assert(l->isEmpty());

        l->insertAtBeg('x');
        assert(!l->isEmpty());
        assert(l->size() == 1);

        l->insertAtBeg('b');
        assert(l->size() == 2);

        l->insertAtEnd('j');
        assert(l->size() == 3);

        l->removeAtBeg();
        assert(l->size() == 2);

        l->removeAtEnd();
        assert(l->size() == 1);
        return 0;
    }