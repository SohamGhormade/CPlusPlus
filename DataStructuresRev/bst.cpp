#include <iostream>
#include <assert.h>
// works fine.
// TODO always double check pointer types for function calls and check LHS and RHS types match for
// assignment operations.
// 26 mins whiteboard
// 29 mins code
using namespace std;
//Implement BST in C++.
template <class T>
class BST
{
  private:
    struct Node
    {
        T data;
        Node *left, *right;
    };
    Node *root;
    void insert(T value, Node **current)
    {
        if (*current == NULL)
        {
            *current = new Node();
            (*current)->data = value;
            (*current)->left = (*current)->right = NULL;
            return;
        }

        if (value > (*current)->data)
            insert(value, &((*current)->right));
        else
            insert(value, &((*current)->left));
    }

    void pre(Node *current)
    {
        if (current != NULL)
        {
            cout << current->data << " ";
            pre(current->left);
            pre(current->right);
        }
        else
            return;
    }
    void post(Node *current)
    {
        if (current != NULL)
        {
            post(current->left);
            post(current->right);
            cout << current->data << " ";
        }
        else
            return;
    }
    void in(Node *current)
    {

        if (current != NULL)
        {
            in(current->left);
            cout << current->data << " ";
            in(current->right);
        }

        else
            return;
    }
    bool search(T value, Node **x, Node **parent)
    {
        *x = *parent = NULL;
        if (root == NULL)
        {
            return false;
        }

        Node *q = root;
        while (q != NULL)
        {
            if (q->data == value)
            {
                *x = q;
                cout << "Found " << q->data << endl;
                if (*parent == NULL)
                    cout << "Parent is null since x is root." << endl;
                else
                    cout << "Parent " << (*parent)->data << endl;
                return true;
            }
            *parent = q;
            if (value > q->data)
                q = q->right;

            else
                q = q->left;
        }
        return false;
    }

  public:
    void insert(T value)
    {
        insert(value, &root);
    }

    void deleteV(T value)
    {
        Node *x, *parent;
        bool found = search(value, &x, &parent);
        if (!found)
        {
            cout << "Element to delete not found" << endl;
            return;
        }

        // the successor will be deleted in following 1 child case
        // we copy the xsucc data value into x for deletion of x.
        // 2 children
        if (x->left != NULL && x->right != NULL)
        {
            // find leftmost successor
            // the sucessor will be deleted.
            Node *xsucc = x->right;
            parent = x;
            while (xsucc->left != NULL)
            {
                parent = xsucc;
                xsucc = xsucc->left;
            }
            x->data = xsucc->data;
            x = xsucc;
        }

        // no children
        if (x->left == NULL && x->right == NULL)
        {
            if (parent->left == x)
                parent->left = NULL;
            else
                parent->right = NULL;
        }

        // 1 left child
        if (x->left != NULL && x->right == NULL)
        {
            if (parent->left == x)
                parent->left = x->left;
            else
                parent->right = x->left;
        }

        // 1 right child
        if (x->left == NULL && x->right != NULL)
        {
            if (parent->left == x)
                parent->left = x->right;
            else
                parent->right = x->right;
        }
    }

    void pre()
    {
        cout << "pre" << endl;
        pre(root);
        cout << endl;
    }

    void post()
    {
        cout << "post" << endl;
        post(root);
        cout << endl;
    }

    void in()
    {
        cout << "in" << endl;
        in(root);
        cout << endl;
    }
};
int main(int argc, char const *argv[])
{
    BST<char> *bst = new BST<char>();// with static allocation we get
    //Segmentation fault (core dumped) i.e BST<char> bst; TODO find out why stack allocation does not work.
    bst->insert('S');
    bst->insert('E');
    bst->insert('A');
    bst->insert('R');
    bst->insert('C');
    bst->insert('H');
    bst->in();
    bst->pre();
    bst->post();

    bst->deleteV('A');
    bst->in();

    bst->deleteV('C');
    bst->in();

    bst->deleteV('H');
    bst->in();
    /* code */
    return 0;
}
