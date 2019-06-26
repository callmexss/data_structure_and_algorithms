/*
 * File:          quick_sort.cpp
 * File Created:  Monday, 24th June 2019 5:49:41 pm
 * Author:        xss (callmexss@126.com)
 * Description:   quick sort
 * -----
 * Last Modified: Monday, 24th June 2019 5:49:45 pm
 * Modified By:   xss (callmexss@126.com)
 * -----
 */

#include "sorttesthelper.h"

using namespace std;

template <typename T>
int partition(T arr[], int p, int r)
{
    int pivot = arr[r];
    int i = p;
    // arr[p, r - 1]
    for (int j = p; j <= r - 1; ++j)
    {
        if (arr[j] < pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

template <typename T>
void quickSort(T arr[], int p, int r)
{
    if (p >= r)
        return ;
    
    int q = partition(arr, p, r);
    // cout << q << endl;
    quickSort(arr, p, q - 1);
    quickSort(arr, q + 1 , r);
}

template <typename T>
void quickSort(T arr[], int n)
{
    quickSort(arr, 0, n - 1);
}

int main(int argc, char const *argv[])
{
    /* code */
    int n = 100000;
    int *arr = SortTestHelper::generateRandomArray(n);
    // SortTestHelper::printArray(arr, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr, n);
    // SortTestHelper::printArray(arr, n);
    delete[] arr;
    return 0;
}

