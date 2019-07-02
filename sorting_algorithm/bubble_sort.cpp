/*
 * File:          bubble_sort.cpp
 * File Created:  Saturday, 22nd June 2019 8:34:43 am
 * Author:        xss (callmexss@126.com)
 * Description:   bubble sort
 * -----
 * Last Modified: Saturday, 22nd June 2019 8:34:46 am
 * Modified By:   xss (callmexss@126.com)
 * -----
 */

#include "sorttesthelper.h"

using namespace std;

template <typename T>
void bubbleSort(T arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        // ? why n - i - 1
        // - when we compare, we will do the operation between j and j + 1, so we will end at the last but one
        // - each time we finish one loop, there must be a member in the right place, so the next turn we minus one
        // see an example 1, 7, 3, 2
        // - n = 4, i = 0, n - 0 - 1 = 3, j < 3
        //   j = 0: [1, 7], 3, 2 -> j = 1: 1, [3, 7], 2 -> j = 2: 1, 3, [2, 7] -> j = 3: next loop
        // - n = 4, i = 1, n - 1 - 1 = 2, j < 2
        //   j = 0: [1, 3], 2, 7 -> j = 1: 1, [2, 3], 7 -> j = 2: next loop
        // - n = 4, i = 2, n - 2 - 1 = 1, j < 1
        //   j = 0: [1, 2], 3, 7 -> j = 1: next loop 
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template <typename T>
void bubbleSortOptimize(T arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        bool change = false;
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                change = true;
            }
        }
        if (!change)
        {
            break;
        }
    }
}

int main(int argc, char const *argv[])
{
    int n = 20000;
    int *arr = SortTestHelper::generateRandomArray(n);
    int *arr1 = SortTestHelper::copyIntArray(arr, n);
    SortTestHelper::testSort("Bubble Sort", bubbleSort, arr, n);
    SortTestHelper::testSort("Bubble Sort Optimize", bubbleSortOptimize, arr1, n);
    delete[] arr1;
    delete[] arr;
    return 0;
}
