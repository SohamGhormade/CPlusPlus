#include <iostream>
#include <assert.h>
#include <unordered_map>
using namespace std;
// use STL
// TODO C exercise is pending.It is not Object oriented.

// 16 mins on whiteboard
//Implement hashtable in C++
template <class K, class V> // note the syntax
class SequentialSearch
{
  private:
    class Node
    {
      public:
        K key;
        V val;
        Node *next;
    };

    Node *f;

  public:
    void put(K k, V v)
    {
        for (Node *x = f; x != NULL; x = x->next)
            if (x->key == k)
            {
                x->val = v;
                return;
            }
        Node *oldF = f;
        f = new Node();
        f->key = k;
        f->val = v;
        f->next = oldF;
    }
    V get(K key)
    {
        for (Node *x = f; x != NULL; x = x->next) //#include <iostream> for NULL
            if (x->key == key)
            {
                return x->val;
            }
        return NULL;
    }
};

template <class K, class V>
class Hashtable
{
  private:
    int m; // size of hashtable
    SequentialSearch<K, V> *ss[];
    int hash(K key)
    {
        return key % m;
    }

  public:
    void put(K key, V val)
    {
        ss[hash(key)]->put(key, val);
    }

    V get(K key)
    {
        return ss[hash(key)]->get(key);
    }
    Hashtable() : Hashtable(297) // C++ 11
    {
    }

    Hashtable(int m)
    {
        this->m = m;
        *ss = new SequentialSearch<K, V>[m];
        for (int i = 0; i < m; i++)
        {
            ss[i] = new SequentialSearch<K, V>();
        }
    }
};
int main()
{
    Hashtable<char, int> *map = new Hashtable<char, int>();
    map->put('S', 5);
    map->put('E', 10);
    map->put('A', 8);
    map->put('R', 19);
    map->put('C', 21);
    map->put('H', 61);
    assert(map->get('S') == 5);
    assert(map->get('E') == 10);
    assert(map->get('A') == 8);
    assert(map->get('R') == 19);
    assert(map->get('C') == 21);
    assert(map->get('H') == 61);
    assert(map->get('Q') == NULL);
    map->put('E', 11);
    assert(map->get('E') == 11);
    unordered_map<int, char> m;
    m[1] = 'A';
    m[8] = 'B';
    m[81] = 'X';
    m[46] = 'Z';
    unordered_map<int, char>::const_iterator got = m.find(1);
    if (got == m.end())
        cout << "not found";
    else
        cout << got->first << " is " << got->second;

    //This code works fine.
    //You can run to verify independently.
    //g++ -o h myhashtable.cpp >> ./h
}
