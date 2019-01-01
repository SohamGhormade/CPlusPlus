#include<iostream>
#include<assert.h>
using namespace std;
// 14 mins whiteboard
// 11 mins code
//Implement a linked list in C++.
//works fine.
template <class T>
class LinkedList
{
    private:
    struct Node{
        T data;
        Node* next;
    };
    Node *f = NULL ,*l = NULL;//TODO initialize pointers.
    int n = 0;//size TODO:initialize variable to zero in C++.

    public:

    bool isEmpty()
    {
        return n==0;
    }

    int size()
    {
        return n;
    }

//O(1)
    void insertAtBeg(T v)
    {
        Node* oldF = f;
        f = new Node();
        f->data = v;
        if(oldF == NULL)
        {
          l = f;
        }

        else
        f->next = oldF;
        n++;//imp!
    }

    void insertAtEnd(T v)
    {

        Node * oldL = l;
        l = new Node();
        l-> data = v;
        if(oldL == NULL)
         f= l;
         else
         oldL->next = l;

         n++;

    }

    //O(1)
    T removeAtBeg()
    {
        if(isEmpty()) {
            cout<<"List is empty .No elements left to remove."<<endl;
            return;//TODO :verify for edge cases that you return immediately or throw exception
            }
        T item = f->data;
        f = f->next;

        n--;
        return item;
    }

    //O(n)
    T removeAtEnd()
    {
              if(isEmpty()) cout<<"List is empty .No elements left to remove."<<endl;
        T item = l->data;
        Node*q = f;
        while(q->next !=l)
       {
          q = q->next;
       }
        q-> next = NULL;
        l = q;
        n--;
        return item;

    }
};


int main()
{
    LinkedList<char> linkedList;
    assert(linkedList.isEmpty());

     linkedList.insertAtBeg('T');
    assert(!linkedList.isEmpty());
    assert(1 == linkedList.size());

    linkedList.insertAtBeg('R');
    assert(2 == linkedList.size());

    linkedList.insertAtBeg('O');
    assert(3 == linkedList.size());

    linkedList.insertAtBeg('S');
    assert(4 == linkedList.size());

    linkedList.insertAtBeg('A');
    assert(5 == linkedList.size());

    linkedList.insertAtEnd('E');
    assert(6 == linkedList.size());

    assert('A'==linkedList.removeAtBeg());
    assert(5 == linkedList.size());

    assert('E'==linkedList.removeAtEnd());
    assert(4 == linkedList.size());

    return 1;
}