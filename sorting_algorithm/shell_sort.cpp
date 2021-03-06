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
void shellSort(vector<T>& vec)
{
    size_t N = vec.size();
    size_t h = 1;

    while (h < N / 3)
    {
        h = 3 * h + 1;
    }

    while (h >= 1)
    {
        for (int i = h; i < N; ++i)
        {
            for (int j = i; j >= h && vec[j] < vec[j - h]; j -= h) 
            {
                swap(vec[j], vec[j - h]);
            }
        }
        h = h / 3;
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
                swap(arr[j], arr[j - h]);
            }
        }
        h = h / 3;
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    // std::vector<int> vec = SortTestHelper::generateNearlyOrderedIntVector(100000);
    int n = 10000;
    std::vector<int> vec = SortTestHelper::generateRandomIntVector(n, 0, n);
    std::vector<int> vec2 = vec;
    SortTestHelper::testSort("Shell Sort", shellSort, vec);

    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    SortTestHelper::testSort("Shell Sort", shellSort, arr, n);
    return 0;
}
