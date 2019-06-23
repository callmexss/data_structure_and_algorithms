/*
 * File:          shell_sort.cpp
 * File Created:  Sunday, 23rd June 2019 9:22:14 pm
 * Author:        xss (callmexss@126.com)
 * Description:   shell sort 
 * -----
 * Last Modified: Sunday, 23rd June 2019 9:22:17 pm
 * Modified By:   xss (callmexss@126.com)
 * -----
 */

#include <vector>
#include <iostream>
#include <algorithm>

#include "sorttesthelper.h"

using namespace std;

template <typename T>
void selectionSort(vector<T>& vec)
{
    size_t n = vec.size();
    for (int i = 0; i < n; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (vec[j] < vec[minIndex])
            {
                minIndex = j;
            }
        }
        swap(vec[i], vec[minIndex]);
    }
}


template <typename T>
void shellSort(T arr[], int n)
{
    int h = 1;

    while (h < n / 3)
    {
        h = 3 * h + 1;
    }

    while (h >= 1)
    {
        for (int i = h; i < n; ++i)
        {
            for (int j = i; j >= h && arr[j] < arr[j - h];  j -= h)
            {
                std::swap(arr[j], arr[j - h]);
            }
        }
        h = h / 3;
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    std::vector<int> vec = SortTestHelper::generateNearlyOrderedIntVector();
    SortTestHelper::testSort("Selection Sort", selectionSort, vec);
    int n = 1000000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, 10000);
    SortTestHelper::testSort("Shell Sort", shellSort, arr, n);
    return 0;
}
