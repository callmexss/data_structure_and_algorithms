/***********************************************
 *
 *      Filename: insertion_sort.cpp
 *
 *        Author: xss - callmexss@126.com
 *   Description: insertion sort
 *        Create: 2017-12-06 21:28:36
 *
 ***********************************************/

#include <iostream>

#include "sorttesthelper.h"

using namespace std;

template <typename T>
void InsertionSort(T arr[], int len)
{
    int i, j;
    T temp;

    for (i = 1; i < len; i++)
    {
        temp = arr[i];

        for (j = i; j > 0 && arr[j - 1] > temp; j--)
        {
            arr[j] = arr[j - 1];
        }

        arr[j] = temp;
    }
}

template <typename T>
void Insert(T arr[], int len)
{
    int i;
    T temp;
    temp = arr[len];

    for (i = len - 1; i >= 0 && temp < arr[i]; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[i + 1] = temp;
}

template <typename T>
void InsertionSortRecursion(T arr[], int len)
{
    if (len > 0)
    {
        InsertionSortRecursion(arr, len - 1);
        Insert(arr, len);
    }
}

int main(int argc, const char *argv[])
{
    // int num[] = {3, 1, 4, 9, 2, 6, 5, 3};
    //InsertionSort(num, 8);
    int n = 100000;
    int *num = SortTestHelper::generateNearlyOrderedArray(n);
    // InsertionSortRecursion(num, n);

    // SortTestHelper::printArray(num, n);

    SortTestHelper::testSort("Insertion Sort", InsertionSort, num, n);

    delete[] num;

    return 0;
}

// reference: http://www.cnblogs.com/zhuorongtan/archive/2012/09/22/2698339.html
