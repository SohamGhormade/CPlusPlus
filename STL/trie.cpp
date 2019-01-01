#include <iostream>
using namespace std;

/**
 * pg 737 Algorithms textbook.
 * Implement Trie in C++
*/
template <class V>
class TrieST
{
  private:
    const int R = 256;
    class Node
    {
        private :
         V value;
         Node[] next = new Node[R];
    };
    Node* root = new Node();

public:
 V get(String key )
 {}
