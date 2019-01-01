/**
 * FIFO queue implementation based on STL API.
*/
#include<iostream>
using namespace std;

template<class T>
class MyQueue
{
    private:
            struct Node{

                T data;
                Node* next;
            }*front_,*back_;
            int count;

    public:
           MyQueue()
           {
               front_ = back_ = NULL;
               count = 0;
           }

           ~MyQueue()
           {}

           /**
            * Adds element to the back of the queue.
           */
           void push(T val)
           {
            Node* temp = new Node();
            temp->data = val;
            temp->next = NULL;
            if(empty())
            {
                front_ = back_ = temp;
            }
            else
            {
               Node* oldBack = back_;
               back_ = temp;
               back_->next = oldBack;
            }
            count++;
           }
           /**
            * Removes element from front of queue.
           */
           void pop()
           {
            if(empty())
            {
                cout<<"Queue is empty!cannot pop elements"<<endl;
                return;
            }
            else
            {
               front_ = front_->next;
            }
            count++;
           }
           size_t size() const
           {
               return count;

           }
           bool empty() const
           {
               return(front_ == NULL || back_ == NULL);
           }
           /*
           *Returns the last popped element.
           */
           T front()
           {
               return front_->data;
           }

         /**
          * Returns the last pushed element.
          *
         */
           T back()
           {
               return back_->data;
           }


};