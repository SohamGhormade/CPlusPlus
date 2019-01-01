#include<iostream>
using namespace std;
    /**
     * BST node definition.
    */
template <class T>
            class Node
            {
                public:
                T data;
                struct Node* left;
                struct Node* right;
            };

template <class T>
class BST
{
    private:


    public:
    /**
     * add element to BST.
    */
           void insert(Node<T> ** e,T val);
           /**
            * Left->Root->Right
           */
           void inorder(Node<T> *e);
           /**
            * Root->Left->Right
           */
           void preorder(Node<T> *e);
           /**
            * Left->Right->Root
           */
           void postorder(Node<T> *e);
           /**
            * Searches the specified element in BST.
            * Returns True if the element has been deleted.
           */
           bool search(Node<T> **root, int num,Node<T> **parent,Node<T> **x);
           /**
            * Deletes the specified element in BST.
           */
           void del(Node<T> **root, int num);
};

/**
 * @brief inserts a given element to BST.
 *
 */

template<class T>
void BST<T>:: insert(Node<T> ** e,T val)
{
    if(*e==NULL)
    {
        *e = new Node<T>();
        (*e)->data = val;
        (*e)->left = NULL;
        (*e)->right = NULL;
    }
    else
    {
        // search for the element in the BST
        if(val < (*e)->data)
           insert(&((*e)->left), val);
        else
        if(val > (*e)->data)
           insert(&((*e)->right), val);

    }

}
/**
 *
*/
template<class T>
void BST<T>:: inorder(Node<T> * e)
{
    if(e!=NULL)
    {
        inorder(e->left);
        cout<<e->data<<" \t";
        inorder(e->right);
    }
    else
    {
        return;
    }
}


template<class T>
void BST<T>:: preorder(Node<T> * e)
{
    if(e!=NULL)
    {
        cout<<e->data<<" \t";
        preorder(e->left);
        preorder(e->right);
    }
    else
    {
        return;
    }
}

template<class T>
void BST<T>:: postorder(Node<T> * e)
{
    if(e!=NULL)
    {
        postorder(e->left);
        postorder(e->right);
        cout<<e->data<<" \t";
    }
    else
    {
        return;
    }
}

/**
* Searches the specified element in BST.
*/
template <class T>
bool BST<T>::search(Node<T> **root, int num, Node<T> **parent, Node<T> **x)
{
    *parent = NULL;
    *x = NULL;

    if (*root == NULL)
    {
        cout << "BST is empty --there are no elements" << endl;
        return false;
    }

    Node<T> *q = *root;

    while (q != NULL)
    {
        if (q->data == num)
        {
            cout << "Element found" << endl;
            *x = q;
            return true;
        }
        *parent = q;
        if (num < q->data)
            q = q->left;
        else
            q = q->right;
    }
    cout << "Element not found" << endl;
    return false;
}

template <class T>
void BST<T>:: del(Node<T> **root, int num)
{
if(root ==NULL)
{
    cout << "BST is empty --there are no elements" << endl;
    return;
}
Node<T>* parent=NULL;
Node<T>* x=NULL, *xsucc = NULL;
bool found = search(root,num,&parent,&x);
if(!found)
{
    cout << "Element not found" << endl;
    return;
}

// two non-null children
if(x->right !=NULL && x->left !=NULL)
{
    parent = x;
    // in order successor
    xsucc = x->right;
    // check left children of current sucessor
    while(xsucc->left!=NULL )
    {
         parent = xsucc;
         xsucc = xsucc ->left;

    }

    // copy data of successor into x ,because current will be deleted and
    // replaced by its sucessor
    x->data = xsucc->data;
    x = xsucc;

}

// if node to be deleted has no children
if(x->right ==NULL && x->left ==NULL)
{
    if(parent->right == x)
    parent->right =NULL;
    else
    parent ->left = NULL;

}

// if node to be deleted has one right child
if(x->right !=NULL && x->left ==NULL)
{
    if(parent->right == x)
    parent->right =x->right;
    else
    parent ->left = x->right;

}

// if node to be deleted has one left child
if(x->right ==NULL && x->left !=NULL)
{
    if(parent->right == x)
    parent->right =x->left;
    else
    parent ->left = x->left;

}
}

int main()
{
    Node<int> *n =NULL ;
    BST<int>* bst = new BST<int>();
    bst->insert(&n,1);
    bst->insert(&n,2);
    bst->insert(&n,3);
    bst->insert(&n,4);
    bst->insert(&n,5);
    cout<<"Inorder"<<endl;
    bst->inorder(n);
    cout<<"preorder"<<endl;
    bst->preorder(n);
    cout<<"postorder"<<endl;
    bst->postorder(n);
    n =NULL;
    int i =0;
    int a [] = {11,9,13,8,10,12,14,15,7};
    while(i <=8)
    {
        bst->insert(&n, a[i]);
        i++;
    }
    cout<<"Inorder"<<endl;
  bst->inorder(n);

  bst->del(&n,10);
 cout<<"Inorder"<<endl;
  bst->inorder(n);
  bst->del(&n,14);

  bst->inorder(n);
  bst->del(&n,8);
 cout<<"Inorder"<<endl;
  bst->inorder(n);
  bst->del(&n,13);
    int a1;
    cin>>a1;
}