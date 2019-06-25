/*
 * File:          sortalg.h
 * File Created:  Friday, 21st June 2019 8:10:44 pm
 * Author:        xss (callmexss@126.com)
 * Description:   a series of sort algorithms
 * -----
 * Last Modified: Friday, 21st June 2019 8:10:49 pm
 * Modified By:   xss (callmexss@126.com)
 * -----
 */

#include <algorithm>
#include <vector>

/**
 * Selection Sort
 */
template <typename T>
void selectionSort(T arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        int minIndex = i;
        for (int j = i; j < n; ++j)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

template <typename T>
void selectionSort(std::vector<T> &vec)
{
    size_t n = vec.size();
    for (int i = 0; i < n; ++i)
    {
        // choose the smallest one
        int minIndex = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (vec[j] < vec[minIndex])
                minIndex = j;
        }
        std::swap(vec[i], vec[minIndex]);
    }
}

/**
 * Insertion Sort
 * ! high efficiency when the array is nearly ordered
 */
template <typename T>
void insertionSort(T arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        T e = arr[i];
        int j; // will point to the location where e should be at when inner loop is over 

        // find a location for e
        for (j = i; j > 0 && arr[j - 1] > e; j--)
        {
            // swap operation is slow
            // std::swap(arr[j], arr[j - 1]);
            // put previous element to current location if it is larger than e
            arr[j] = arr[j - 1];
        }
        arr[j] = e;
    }
}

template <typename T>
void insertionSort(std::vector<T> &vec)
{
    size_t n = vec.size();
    for (int i = 0; i < n; ++i)
    {
        // find a location for current value
        int j;
        T e = vec[i];
        for (j = i; j > 0 && vec[j - 1] > e; j--)
        {
            vec[j] = vec[j - 1];
        }
        vec[j] = e;
    }
}

/**
 * Bubble Sort
 */
template <typename T>
void bubbleSort(T arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        bool swapFlag = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                swapFlag = true;
            }
        }
        if (!swapFlag)
        {
            break;
        }
    }
}

template <typename T>
void bubbleSort(std::vector<T> &vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        bool swapFlag = false;
        for (int j = 0; j < vec.size() - i - 1; ++j)
        {
            if (vec[j] > vec[j + 1])
            {
                std::swap(vec[j], vec[j + 1]);
                swapFlag = true;
            }
        }
        if (!swapFlag)
            break;
    }
}

/**
 * Shell Sort
 */
template <typename T>
void shellSort(T arr[], int n)
{
    int h = 1;
    while (h < n)
    {
        h = h * 3 + 1;
    }

    while (h >= 1)
    {
        for (int i = h; i < n; ++i)
        {
            for (int j = i; j >= h && arr[j] < arr[j - h]; j -= h)
            {
                std::swap(arr[j], arr[j - h]);
            }
        }
        h = h / 3;
    }
}

/**
 * Merge Sort
 */
template <typename T>
void mergeSort(T arr[], int n)
{
    mergeSort(arr, 0, n - 1);
}

template <typename T>
void mergeSort(T arr[], int p, int r)
{
    if (p >= r)
        return;

    int q = p + (r - p) / 2;
    mergeSort(arr, p, q);
    mergeSort(arr, q + 1, r);

    merge(arr, p, q, r);
}

template <typename T>
void merge(T arr[], int p, int q, int r)
{
    T *tmp = new T[r - p + 1];
    int i, j, k;

    for (i = p, j = q + 1, k = 0; i <= q && j <= r; )
    {
        if (arr[i] < arr[j])
            tmp[k++] = arr[i++];
        else
            tmp[k++] = arr[j++];
    }

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

    std::copy(tmp, tmp + r - p + 1, arr + p);
}