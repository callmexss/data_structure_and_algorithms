/*
 * File:          selection_sort.cpp
 * File Created:  Thursday, 20th June 2019 9:03:59 pm
 * Author:        xss (callmexss@126.com)
 * Description:   selection sort
 * -----
 * Last Modified: Thursday, 20th June 2019 9:04:04 pm
 * Modified By:   xss (callmexss@126.com)
 * -----
 */


#include <iostream>
#include <algorithm>

#include "sorttesthelper.h"
#include "student.h"

using namespace std;

template<typename T>
void selectionSort(T arr[], int n)
{
    int minIndex;
    for (int i = 0; i < n; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main(int argc, char const *argv[])
{
    int n = 20;
    int *arr = SortTestHelper::generateRandomArray(n);
    SortTestHelper::printArray(arr, n);
    selectionSort(arr, n);
    SortTestHelper::printArray(arr, n);
    delete[] arr;

    float arr1[10] = {3.3, 2.2, 4.4, 1.1};
    selectionSort(arr1, 4);
    SortTestHelper::printArray(arr1, 4);

    Student d[4] = {{"D", 90}, {"C", 100}, {"B", 95}, {"A", 95}};
    selectionSort(d, 4);
    SortTestHelper::printArray(d, 4);

    n = 10000;
    int *newarr = SortTestHelper::generateRandomArray(n);
    SortTestHelper::testSort("Selection Sort", selectionSort, newarr, n);

    return 0;
}
