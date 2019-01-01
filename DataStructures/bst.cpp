#include <assert.h>
#include <iostream>
#include <new>
using namespace std;
//It works fine.
//TODO review.
// deletion of two children,memory management with pointers and ptrs of ptrs.
// insertion case.
template <class T>
class BST
{
  private:
    struct Node
    {
        Node *L, *R;
        T data;
    };
    Node *root;

    void insert(T v, Node **root) // pointer to pointer
    {
        if (*root == NULL)
        {
            *root = new Node();
            (*root)->data = v;
            (*root)->L = NULL; // use brackets for ensuring that *root is processed before anything else.-> is processed first and then * ptr.
            (*root)->R = NULL;
            return;
        }

        if ((*root)->data > v)
            insert(v, &((*root)->L));
        else
            insert(v, &((*root)->R)); //NOTE
    }

    bool search(Node *root, Node **x, Node **parent, T v)
    {
        *parent = NULL;
        *x = NULL;
        if (root == NULL)
            return false;
        Node *q = root;
        while (q != NULL)
        {
            if (q->data == v)
            {
                *x = q;
                cout << "Found " << q->data << " with parent  " << (*parent)->data << endl;
                return true;
            }
            *parent = q;

            if (q->data > v)
            {
                q = q->L;
            }
            else
                q = q->R;
        }
    }

    void del(T v, Node **r)
    {
        Node *x, *parent;
        bool b = search(root, &x, &parent, v);
        if (!b)
            return;

        // two children
        if (x->L != NULL && x->R != NULL)
        {
            Node *xsucc = x->R;
            parent = x;
            // find the leftmost successor
            while (xsucc->L != NULL)
            {
                parent = xsucc;
                xsucc = xsucc->L;
            }
            // copy the data from successor into x
            x->data = xsucc->data;
            x = xsucc;
        }

        // no children
        if (x->L == NULL && x->R == NULL)
        {
            if (parent->L == x)
                parent->L = NULL;
            else
                parent->R = NULL;

            delete (x);
            return;
        }

        // right child
        if (x->L == NULL && x->R != NULL)
        {
            if (parent->L == x)
                parent->L = x->R;
            else
                parent->R = x->R;

            delete (x);
            return;
        }
        // left child
        if (x->L != NULL && x->R == NULL)
        {
            if (parent->L == x)
                parent->L = x->L;
            else
                parent->R = x->L;

            delete (x);
            return;
        }
    }
    void in(Node *root)
    {
        if (root != NULL)
        {
            in(root->L);
            cout << root->data << " ";
            in(root->R);
        }
        else
            return;
    }

    void pre(Node *root)
    {

        if (root != NULL)
        {
            cout << root->data << " ";
            pre(root->L);
            pre(root->R);
        }
        else
            return;
    }

    void post(Node *root)
    {

        if (root != NULL)
        {
            post(root->L);
            post(root->R);
            cout << root->data << " ";
        }
        else
            return;
    }

  public:
    void insert(T v)
    {
        insert(v, &root);
    }
    void del(T v)
    {
        del(v, &root);
    }
    void in()
    {
        cout << " In order traversal" << endl;
        in(root);
        cout << endl;
    }
    void pre()
    {
        cout << " Pre order traversal" << endl;
        pre(root);
        cout << endl;
    }
    void post()
    {
        cout << " Post order traversal" << endl;
        post(root);
        cout << endl;
    }
};
int main()
{
    BST<int> *b = new BST<int>();
    b->insert(10);
    b->insert(5);
    b->insert(17);
    b->insert(18);
    b->insert(2);
    b->insert(8);
    b->insert(1);
    b->insert(3);

    b->in();
    b->pre();
    b->post();
    b->del(3);
    b->in();
    b->del(5);
    b->in();
    b->del(12);
    b->in();
    return 0;
}
//output
//  In order traversal
// 1 2 3 5 8 10 17 18
//  Pre order traversal
// 10 5 2 1 3 8 17 18
//  Post order traversal
// 1 3 2 8 5 18 17 10
//  Pre order traversal
// 10 5 2 1 8 17 18