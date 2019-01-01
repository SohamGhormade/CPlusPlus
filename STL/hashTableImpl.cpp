#include<iostream>
/**
 * Node class.Key Value Pair.
*/
template<class K,class V>
struct HashNode
{
    K k;
    V v;
    HashNode<K,V>*next;
    HashNode(Key k, Value v, HashNode<K,V> *next):
    k(k),v(v),next(next){}

};

const int TABLE_SIZE = 10;

/**
 * Hash Function.
*/
template<class K>
struct KeyHash
{
    unsigned ulong hash(K k) const
    {
        return reinterpret_cast<unsigned>(k)%TABLE_SIZE;
    }
};


