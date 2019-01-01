#include <iostream>
#include<exception>
using namespace std;

template<class T>  class Stack1
{
    private:
            struct Node
            {
                T data;
                Node*next;
            }*top;

    public:
           Stack1()
           {
               top = nullptr;
           }
           ~Stack1()
           {}

           void push(T value)
           {
               Node *n = new Node();
               n->data = value;
               n->next = nullptr;

               if(top == nullptr)
               {
                   top = n;
               }
               else
               {
                   Node *t = top;
                    n->next =t;
                    top = n;
                }
               }

           T pop()
           {
               if(top==nullptr)
               {
                   throw new exception();
               }
               else
               {
                   T item = top->data;
                   top = top->next;
                   delete top;
                   return item;
               }
           }
            void print()
            {
                Node * t= top;
                while(t!=nullptr)
                {
                    cout<<t->data<<",";
                    t=t->next;
                }
            cout<<endl;
            }
};
int main()
{
    Stack1<int> *stk = new Stack1<int>();
    stk->push(1);
    stk->print();

    stk->push(2);
    stk->print();

    int i = stk->pop();
    cout<<i<<endl;
    stk->print();

    int j = stk->pop();
    cout<<j<<endl;
    stk->print();

    cout<<"Hi"<<endl;
    int s;
    cin>>s;


}

