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

/**
 * selection sort
 */
template <typename T>
void selectionSort(T arr[], int n)
{
    int minIndex = 0;
    for (int i = 0; i < n; i++)
    {
        minIndex = i;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

/**
 * insertion sort
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