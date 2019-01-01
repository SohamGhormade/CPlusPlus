#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node *l;
    Node *r;
    Node(int d, Node *l, Node *r) : data(d), l(l), r(r){};
    Node(int d) : data(d), l(NULL), r(NULL){};
};

/**
 * Find the height of a binary tree.
*/
int height(Node *root)
{
    if (root == NULL)
        return 0;

    return max(height(root->l), height(root->r)) + 1;
}

/**
 * Preorder traversal with recursion
 * Root->Left -> Right
*/

void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << "\t";

    preorder(root->l);
    preorder(root->r);
}

/**
 * Preorder traversal without recursion
 * Root->Left -> Right
*/

void preorderNoRecursion(Node *root)
{
    stack<Node *> stk;

    stk.push(root);
    while (!stk.empty())
    {
        Node *t = stk.top();
        cout << t->data << "\t";
        stk.pop();
        if (t->r != NULL)
        {
            stk.push(t->r);
        }
        if (t->l != NULL)
        {
            stk.push(t->l);
        }
    }
}

/**
 * Returns the Lowest Common Ancestor
 *
*/
Node *lca(Node *root, int a, int b)
{
    if (a < root->data && b < root->data)
        lca(root->l, a, b);
    else if (a > root->data && b > root->data)
        lca(root->r, a, b);
    else
        return root;
}
Node *lcaIterative(Node *root, int a, int b)
{
    Node *t = root;
    while (t != NULL)
    {
        if (a < t->data && b < t->data)
            t = t->l;
        else if (a > t->data && b > t->data)
            t = t->r;
        else
            return t;
    }
    return NULL;
}
// int traverse(Node * node,int count, Node arr[])
// {
//     if(node==NULL)
//     return count;
//     if(arr!=NULL)
//     arr[count] = node;
//     count++;

//     count = traverse(node->l,count,arr);
//     count = traverse(node->r,count,arr);
//     }
/*
 * Converts Binart Tree into a min heap.
 */
Node* heapifyBinaryTree()
{

}


int main()

{

    Node *n = new Node(100);
    Node *n1 = new Node(50);
    Node *n2 = new Node(150);
    Node *n3 = new Node(25);
    Node *n4 = new Node(75);
    Node *n5 = new Node(125);
    Node *n6 = new Node(175);
    Node *n7 = new Node(110);

    n->l = n1;
    n->r = n2;

    n1->l = n3;
    n1->r = n4;

    n2->l = n5;
    n2->r = n6;

    n5->l = n7;

    cout << "The height of the BST is:" << height(NULL) << endl;
    cout << "The height of the BST is:" << height(n) << endl;
    cout << "The preorder traversal of the BST is:\n" << endl;
    preorder(n);
    cout << "The preorder traversal of the BST w/ recursion is:\n" << endl;
    preorderNoRecursion(n);
    cout << "The LCA of the BST is:" << lca(n, 110, 175)->data << endl;
       cout << "The LCA of the BST is:" << lcaIterative(n, 110, 175)->data << endl;
}