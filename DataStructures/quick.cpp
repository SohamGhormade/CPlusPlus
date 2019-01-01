#include <iostream>
#include <assert.h>
#include <stdbool.h>
using namespace std;
class Quick
{
  private:
    int static partition(int a[], int left, int right)
    {
        int pivot = a[(left + right) / 2];
        while (left <= right)
        {
            while (a[left] < pivot)
                left++;
            while (a[right] > pivot)
                right--;
            if (left <= right)
            {
                swap(a, left, right);
                left++;
                right--;
            }
        }
    }
    void static swap(int a[], int i, int j)
    {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

  public:
    //Uses QuickSort algorithm to sort given array
    void static sort(int *a, int left, int right)
    {
        int pivotIndex = partition(a, left, right);
        if (left < pivotIndex - 1)
            sort(a, left, pivotIndex - 1);
        if (pivotIndex < right)
            sort(a, pivotIndex, right);
    }
};
int main(int argc, char const *argv[])
{
    int a[] = {5, 1, 2, 4, 6, 10, 3, 7};
    Quick::sort(a, 0, 8);
    bool result = true;
    int r[] = {1, 2, 3, 4, 5, 6, 7, 10};
    for (int i = 0; i < 8; i++)
        if (a[i] != r[i])
            result = false;

    assert(result);

    /* code */
    return 0;
}
