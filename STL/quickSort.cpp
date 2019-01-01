#include <iostream>
using namespace std;
// forward declarations
int n = 10;
int split(int *a, int lower, int upper);
void print(int *a, int n);
void quickSort(int *a, int lower, int upper);
void swap(int *a, int i1, int i2);

/**
 * Apply QuickSort algorithm to input array to sort it.
*/

void quickSort(int a[], int lower, int upper)
{
    print(a, n);
    if (upper > lower) //base condition
    {
        int pivotIndex = split(a, lower, upper);
        quickSort(a, lower, pivotIndex - 1);
        quickSort(a, pivotIndex + 1, upper);
    }

}

/**
 * Partitions the array into two for further sorting.
 * @returns the pivot index
 */

int split(int a[], int lower, int upper)
{

    int p = lower + 1; //left ptr
    int q = upper;     // right ptr
    int t;             //temp
    int pivot = a[lower];

    while (q >= p)
    {
        while (a[p] < pivot)
            p++;

        while (a[q] > pivot)
            q--;

        if (q > p)
        {
            swap(a, p, q);
        }
    }
    swap(a, q, lower);
    return q;
}

void swap(int a[], int i1, int i2)
{
    int t = a[i1];
    a[i1] = a[i2];
    a[i2] = t;
}

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << "\t";

    cout << endl;
}

/**
 * client code
 * */
int main(int argc, char const *argv[])
{
    int a[10] = {11, 2, 9, 13, 57, 25, 17, 1, 90, 3};
   // int a[5] = {3, 4, 5, 1, 2};

    quickSort(a, 0, n - 1);

    int a1;
    cin >> a1;
    /* code */
    return 0;
}
