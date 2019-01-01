/**
 * FIFO queue implementation based on STL API.
*/
#include<iostream>
using namespace std;

template<class T>
class MyQueue
{
    private:
            class Node{
                T data;
                Node* next;
            }*front,*back;
            int count;

    public:
           MyQueue()
           {
               front = back = NULL;
               count = 0;
           }

           ~MyQueue()
           {}

           /**
            * Adds element to the back of the queue.
           */
           void push(T val) const
           {
            Node* temp = new Node();
            temp->data = val;
            temp->next = NULL;
            if(empty())
            {
                front = back = temp;
            }
            else
            {
               Node* oldBack = back;
               back = temp;
               back->next = oldBack;
            }
            count++;
           }
           /**
            * Removes element from front of queue.
           */
           void pop() const
           {
            if(empty())
            {
                cout<<"Queue is empty!cannot pop elements"<<endl;
                return;
            }
            else
            {
               front = front->next;
            }
            count++;
           }
           size_t size()
           {
               return count;

           }
           bool empty()
           {
               return(front == NULL || back == NULL);
           }
           Node* front()
           {
               return front;
           }

           Node* back()
           {
               return back;
           }


};