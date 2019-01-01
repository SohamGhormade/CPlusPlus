#include<iostream>
#include<assert.h>
#include<string>
using namespace std;

//Implement HashTable in C++.
// 11 mins code
// TODO fix errors
// hashtable.cpp:61:24: error: invalid cast from type ‘std::__cxx11::basic_string<char>’ to type ‘int’
//                  return (int)key % m;// choose a different hashing function if # of keys is going to be large.

// hashtable.cpp:70:27: error: no match for ‘operator=’ (operand types are ‘SequentialSearch<std::__cxx11::basic_string<char>, int>’ and ‘SequentialSearch<std::__cxx11::basic_string<char>, int>*’)
//                      ss[i] = new SequentialSearch<K,V>();
template <typename K, typename V>
class KeyValuePair
{
    public:
           K key;
           V value;
           KeyValuePair<K,V> * next;
};

template <typename K, typename V>
class SequentialSearch
{
    private:
             KeyValuePair<K,V> *first;
    public:
             V get(K key)
             {
                 for(KeyValuePair<K,V> * x = first;x!=NULL;x++)
                 {
                     if(x->key == key)
                     {
                         return x->value;
                     }
                 }
                 return NULL;
             }
             void put(K key, V value)
             {
                 for(KeyValuePair<K,V> * x = first;x!=NULL;x++)
                 {
                     if(x->key == key)
                     {
                         x->value = value;
                     }
                 }
                 KeyValuePair<K,V>* oldF = first;
                 first = new KeyValuePair<K,V>();
                 first->key = key;
                 first->value = value;
                 first-> next = oldF;

             }
};

template <typename K, typename V>
class HashTable
{
    private:
            int m = 297;
            SequentialSearch<K,V>* ss;
            long hash(K key)
            {
                return reinterpret_cast<long>(&key) % m; // choose a different hashing function if # of keys is going to be large.
                // or increase the value of m.
            }
    public:
            HashTable()
            {
                ss = new SequentialSearch<K, V>[m];
                // for(int i = 0; i< m;i++)
                // {
                //     ss[i] = new SequentialSearch<K,V>();
                // }
            }

            V get(K key)
            {
                ss[hash(key)].get(key);
            }

            void put(K key, V value)
            {
                ss[hash(key)].put(key, value);
            }

};
int main(int argc, char const *argv[])
{
    HashTable<string,int> hashTable;
    hashTable.put("hi",4);
    hashTable.put("hello",44);
    // hashTable.put("abc",5);
    // hashTable.put("xyz",55);

    // assert(hashTable.get("xyz")==55);
    // hashTable.put("xyz",555);
    // assert(hashTable.get("xyz")==555);
    // assert(hashTable.get("abc")==5);
    // assert(hashTable.get("hi")==4);

    /* code */
    return 0;
}


