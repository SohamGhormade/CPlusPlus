#include <iostream>
#include <vector>
using namespace std;
/**
 * Node class.
*/
template <class K, class V>
struct Node
{
    K key;
    V value;
    Node *next;
    Node(K key, V value, Node *next)

    {
        this->key = key;
        this->value = value;
        this->next = next;
    }
};

/**
 * Implement a Sequential Search Symbol Table from Algorithms Sedgewick book.
*/
template <class K, class V>
class SequentialSearchST
{
  private:
    Node<K, V> *first;

  public:
    SequentialSearchST()
    {
        first = NULL;
    }
    /**
     * Returns the value for a given key.
    */
    V get(K key)
    {
        for (Node<K, V> *p = first; p != NULL; p = p->next)
        {
            if (p->key == key)

                return p->value;
        }
        return NULL;
    }
    /**
     * Updates value if not null.
     * Adds value if key does not exist
    */
    void put(K key, V value)
    {   cout << "print blow up 1" << endl;
        if(!first)
        {    first = new Node<K,V>(key, value, first);}
        cout << "print blow up 2" << endl;
        for (Node<K, V> *p = first; p != NULL; p = p->next)
        {
            if (p->key == key)

                p->value = value;
            return;
        }
       cout << "print blow up 1" << endl;
        first = new Node<K,V>(key, value, first);
        cout << "print blow up 2" << endl;
    }
};

/**
 *Hastable in C++
*/
template <class K, class V>
class SeparateChainingHashST
{
  private:
    int m;
    SequentialSearchST<K, V> **st;
    int hash(K key)
    {
        return key % m;
    }

  public:
    SeparateChainingHashST()
    {
        m = 997;
        st = new SequentialSearchST<K, V> *[m]();
    }

    V get(K key)
    {
        return st[hash(key)]->get(key);
    }

    void put(K key, V value)
    {
        cout << "print" << endl;
        st[hash(key)]->put(key, value);
        cout << "print" << endl;
    }
};

int main(int argc, char const *argv[])
{
    SeparateChainingHashST<int, int> *h = new SeparateChainingHashST<int, int>();

    cout << "print" << endl;
    h->put(109, 100);
    cout << "print" << endl;
    h->put(200, 600);
    h->put(300, 400);
    h->put(400, 500);
    cout << "print" << endl;
    cout << h->get(1) << endl;
    cout << h->get(2) << endl;
    cout << h->get(3) << endl;
    /* code */
    return 0;
}
