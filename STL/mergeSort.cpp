#include <iostream>
using namespace std;
// forward declarations
int n = 10;
int split(int *a, int lower, int upper);
void print(int *a, int n);
void quickSort(int *a, int lower, int upper);
void mergeSort(int a, int b, int c, int aLength, int bLength);
void swap(int *a, int i1, int i2);

/**
 * Apply QuickSort algorithm to input array to sort it.
*/

void quickSort(int a[], int lower, int upper)
{
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
 * Merges two sorted arrays.
*/
void mergeSort(int *a, int *b, int *c, int aLength, int bLength)
{
    int i = 0;
    int j = 0;
    int k = 0;
    for (i = j = k = 0; i <= aLength + bLength - 1;)
    {
        if (a[j] <= b[k])
            c[i++] = a[j++];
        else
            c[i++] = b[k++];

        if (j == aLength || k == bLength)
            break;
    }

    while (j < aLength)
        c[i++] = a[j++];
    while (k < aLength)
        c[i++] = b[k++];
}

/**
 * client code
 * */
int main(int argc, char const *argv[])
{
    int aLength = 5;
    int bLength = 5;
    int c[10];
    int a[5] = {11, 2, 9, 13, 57}; //input unsorted array of length n
    int b[5] = {25, 17, 1, 90, 3};
    printf("\nBefore sorting:\n");
    print(a, aLength);
    print(b, bLength);
    printf("\nAfter sorting:\n");
    quickSort(a, 0, aLength - 1);
    quickSort(b, 0, bLength - 1);
    print(a, aLength);
    print(b, bLength);
    printf("\nAfter merge:\n");
    mergeSort(a,b,c,aLength,bLength);
    print(c,aLength+bLength);
    int a1;
    cin >> a1;
    /* code */
    return 0;
}
