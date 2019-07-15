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
int partition_update(T arr[], int l, int r)
{
    swap(arr[l], arr[rand() % (r - l + 1) + l]);
    T pivot = arr[l];

    int i = l + 1, j = r;
    while (true)
    {
        while (i <= r && arr[i] < pivot) i++;
        while (j >= l + 1 && arr[j] > pivot) j--;
        if (i > j) break;
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    swap(arr[l], arr[j]);
    // SortTestHelper::printArray(arr, r - l + 1);
    return j;
}

template <typename T>
int partition(T arr[], int p, int r)
{
    T pivot = arr[r];
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
        return;

    int q = partition_update(arr, p, r);
    // cout << q << endl;
    quickSort(arr, p, q - 1);
    quickSort(arr, q + 1, r);
}

template <typename T>
void quickSort(T arr[], int n)
{
    srand(time(NULL));
    quickSort(arr, 0, n - 1);
}


template <typename T>
int partition(vector<T> &vec, int l, int r)
{
    T pivot = vec[r];

    int i = l;
    for (int j = l; j <= r - 1; ++j)
    {
        if (vec[j] < pivot)
        {
            swap(vec[j], vec[i++]);
        }
    }
    swap(vec[i], vec[r]);
    return i;
}

template <typename T>
void quickSort(vector<T> &vec, int l, int r)
{
    if (l >= r)
        return;

    int p = partition(vec, l, r);
    quickSort(vec, l, p - 1);
    quickSort(vec, p + 1, r);
}

template <typename T>
void quickSort(vector<T> &vec)
{
    quickSort(vec, 0, vec.size() - 1);
}

int main(int argc, char const *argv[])
{
    /* code */
    int n = 100000;
    // int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr = SortTestHelper::generateNearlyOrderedArray(n, 1);
    // SortTestHelper::printArray(arr, n);
    // SortTestHelper::testSort("Quick Sort", quickSort, arr, n);
    quickSort(arr, n);
    // SortTestHelper::printArray(arr, n);
    vector<int> vec = SortTestHelper::generateRandomIntVector(n, 0, n);
    SortTestHelper::testSort("Quick Sort", quickSort, vec);

    int arrTest[] = {1, 3, 4, 2, 5, 7, 9};
    // quickSort(arr, sizeof(arrTest)/sizeof(int));
    SortTestHelper::testSort("Quick Sort", quickSort, arrTest, sizeof(arrTest) / sizeof(int));
    delete[] arr;
    return 0;
}
