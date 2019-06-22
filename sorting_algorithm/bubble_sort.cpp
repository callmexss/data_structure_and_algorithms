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

template <typename T>
void bubbleSort(T arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int n = 10000;
    int *arr = SortTestHelper::generateRandomArray(n);
    SortTestHelper::testSort("Bubble Sort", bubbleSort, arr, n);
    delete[] arr;
    return 0;
}
