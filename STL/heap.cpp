#include<iostream>
/**
 * Max Heap implementation.
*/
template <class T>
class Heap
{
    private:
            T* pq;
            int n;// size
            /**
             * Swim to the top.
             * Reheapify bottom-up.
            */
            void swim(int k)
            {
                int parent = k / 2;
                while (k > 1 && pq[parent] < pq[k])
                {
                    swap(k,parent);
                    k = parent;
                }
            }
/**
 * Sink to the bottom.
*/
            void sink(int k)
            {
                int child = 0;

                while(child <= n)
                {
                   child = 2 *k;
                   if(pq[child]<pq[child + 1]) child++;//??

                    if(pq[child] > pq[k])
                     swap(child, k);

                     k = child;

                }

            }
            void swap(T a, T b)
            {
                T temp = pq[a];
                pq[b] = pq[a];
                pq[a] = temp;
            }

          public:
            Heap()
            {
                pq = new T[1];
                n = 1;
            }
            ~Heap();
            int size()
            {
                return n;
            }

            bool isEmpty() const
            {
                return n ==0 ;

            }

            T delMax()
            {
                T max = pq[1];
                swap(1,--n);
                sink(1);
            }

            void insert(T val)
            {
                pq[n++] = val;
                swim(n);
            }

};
