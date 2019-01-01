#include <iostream>
#include<stdbool.h>
#include<assert.h>

using namespace std;
//Implement an R-way trie in C++.
template <class T>
class MyTrie
{
  private:
    int R = 256; //radix
    class Node
    {
      public:
        T val;
        Node *next;
    };
    Node *root;
    Node get(string key, Node *x, int d)
    {
        if (x == NULL)
            return NULL;
        if (key.length() == d)
            return x.val;
        char c = key[d];
        return get(key, x->next[c], d + 1);
    }

    Node put(string key, T v, Node *x, int d)
    {
        if (x == NULL)
        {
            x = new Node();
        }
        if (key.length() == d)
        {
            x->val = val;
        }

        char c = key[d];
        x->next[c] = put(key, x->next[c], d + 1);
        return x;
    }

  public:
    void put(string key, T v)
    {
        root = put(key, v, root, 0);
    }
    T get(string key)
    {
        if (key == NULL)
            return NULL;
        Node *n = get(key, root, 0);
        if (n == NULL)
            return NULL;
        return n->val;
    }
};
int main(int argc, char const *argv[])
{
    MyTrie<int> myTrie;
    myTrie.put("sea", 3);
    assert(myTrie.get("sea") == 33);
    myTrie.put("shore", 13);
    myTrie.put("sells", 31);
    myTrie.put("she", 2);
    myTrie.put("shells", 3);
    assert(myTrie.get("sells") == 31);
    assert(myTrie.get("shells") == 3);
    /* code */
    return 0;
}
