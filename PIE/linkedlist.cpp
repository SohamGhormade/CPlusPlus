#include <iostream>
using namespace std;
struct Node
{
  public:
    int data;
    Node *next;
    Node(int data, Node *next) : data(data), next(next)
    {
    }
};

struct ListNode
{
  public:
    int data;
    ListNode *next;
    ListNode*prev;
    ListNode*child;
    ListNode(int data, ListNode *next,ListNode *prev,ListNode * child) :
     data(data), next(next),prev(prev),child(child)
    {
    }
};

Node *findMToLastElement(Node *head, int m)
{
    Node *current;
    Node *m_behind;
    int count = 0;
    for (m_behind = head; m_behind != NULL; m_behind = m_behind->next)
    {
        count++;
        if (count == m)
        {
            break;
        }
    }

    for (current = m_behind; current != NULL; current = current->next)
    {
        m_behind = m_behind->next;
    }

    return m_behind;
}
/**
 * Flatten a doubly linked linked list.
*/
void FlattenList(ListNode *head,ListNode ** tail)
{
    ListNode * current;
    for(current= head;current!=*tail;current=current ->next)
    {
        if(current->child!=NULL)
        {
            (*tail)->next = current->child;
            current->child->prev = *tail;
        }


    }

}
int main()
{
    Node *head = NULL;
    Node *n2 = new Node(3, NULL);
    Node *n1 = new Node(2, n2);
    head = new Node(1, n1);

    cout<<"m to last element "<<findMToLastElement(head,1)->data<<endl;
    return 0;
}