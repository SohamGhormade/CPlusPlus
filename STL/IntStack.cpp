#include<iostream>
using namespace std;
#ifndef INT_STACK_CPP
#define INT_STACK_CPP
/**
 * @brief Linked list implementation of Stack using int.
 *        Based on STL API.
 *
*/
class IntStack
{
    private:
            struct Node
            {
                int data;
                Node* next;
            }*top;
    public:
           IntStack()
           {
               top =NULL;
           }

           bool empty() const
           {
               return top == NULL;
           }

           /**
            * Removes an element from the top of the stack.
           */
           int pop()
           {
               int result = 0;

               if(top ==NULL)
                 {
                     cout<<"Stack is empty! cannot pop more elements."<<endl;
                     return result;
                 }
                 else
               {
                 result = top->data;
                 top = top->next;
                 return result;
               }
           }
           /**
            * @brief Adds an element to top of the stack
           */
           void push(const int i)
           {
               Node *temp = new Node();
               temp->data = i;
               temp->next = NULL;
              if(top == NULL)
              {
                  top = temp;
              }
              else
              {
                  // store the current top element
                   Node* t = top;
                   // overwrite the top element with current value
                   top = temp;
                   // point to old top
                   top->next = t;
              }
           }

        //    void emplace(const int i)
        //    {

        //    }
          size_t size()
          {
              size_t result = 0;
              Node*temp = top;
              while(temp!=NULL)
                {
                    temp =temp->next;
                    result++;
                }
              return result;
          }
};

#endif