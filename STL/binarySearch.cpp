#include <iostream>
using namespace std;
/**
 * Search for specified element,num, in a sorted array,a, using binary search
 * Returns true if element is found,false otherwise
*/
bool binarySearch(int a[], int lower, int upper, int num)
{
    bool found = false;
    int mid ;
    while (lower<=upper)
    {
        mid = (lower + upper) / 2;
        if (a[mid] == num)
        {
            cout << "Element found at index " << mid << endl;
            found = true;
        }

        if (a[mid] < num)
        {
            lower = mid + 1;
        }
        else

            upper = mid - 1;
    }
    if(!found)
     cout << "Element not present in array" << endl;
    return found;
}
int main(int argc, char const *argv[])
{
    int a[10] = {11, 2, 9, 13, 57, 25, 17, 1, 90, 3};

    bool b = binarySearch(a, 0, 9, 55); /* code */
    /* code */
    return 0;
}
