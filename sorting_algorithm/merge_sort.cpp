/*
 * File:          merge_sort.cpp
 * File Created:  Monday, 24th June 2019 10:50:15 am
 * Author:        xss (callmexss@126.com)
 * Description:   merge sort
 * -----
 * Last Modified: Monday, 24th June 2019 10:50:17 am
 * Modified By:   xss (callmexss@126.com)
 * -----
 */

#include "sorttesthelper.h"

using namespace std;

template <typename T>
void merge(T *arr, int p, int q, int r)
{
    // cout << p << " " << q << " " << r << endl;
    T *tmp = new T[r - p + 1];
    int i, j, k;

    for (i = p, j = q + 1, k = 0; i <= q && j <= r;)
    {
        if (arr[i] <= arr[j])
            tmp[k++] = arr[i++];
        else
            tmp[k++] = arr[j++];
    }

    // cout << "Merge half: ";
    // SortTestHelper::printArray(arr, k);

    if (i == q + 1)
    {
        for (; j <= r;)
            tmp[k++] = arr[j++];
    }
    else
    {
        for (; i <= q;)
            tmp[k++] = arr[i++];
    }
    
    // SortTestHelper::printArray(tmp, r - p + 1);

    copy(tmp, tmp + r - p + 1, arr + p);
    delete[] tmp;
}

template <typename T>
void mergeSort(T arr[], int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    // cout << "mid: " << mid << endl;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // cout << "Before merge: ";
    // SortTestHelper::printArray(arr, right - left + 1);

    merge(arr, left, mid, right);
}

template <typename T>
void mergeSort(T arr[], int n)
{
    mergeSort(arr, 0, n - 1);
}

int main(int argc, char const *argv[])
{
    /* code */
    int n = 10000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    // SortTestHelper::printArray(arr, n);
    mergeSort(arr, n);
    // SortTestHelper::printArray(arr, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr, n);

    delete[] arr;
    return 0;
}
