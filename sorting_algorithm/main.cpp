/*
 * File:          main.cpp
 * File Created:  Friday, 21st June 2019 8:14:20 pm
 * Author:        xss (callmexss@126.com)
 * Description:   main test for sort algorithms
 * -----
 * Last Modified: Friday, 21st June 2019 8:14:25 pm
 * Modified By:   xss (callmexss@126.com)
 * -----
 */


#include <iostream>

#include "sortalg.h"
#include "sorttesthelper.h"


int main(int argc, char const *argv[])
{
    size_t n = 100000;
    // int* arr = SortTestHelper::generateRandomArray(n, 0, n);
    int* arr = SortTestHelper::generateNearlyOrderedArray(n, 100);

    int* arrSelection = SortTestHelper::copyIntArray(arr, n);
    int* arrInsertion = SortTestHelper::copyIntArray(arr, n);
    int* arrBubble = SortTestHelper::copyIntArray(arr, n);

    SortTestHelper::testSort("Selection Sort", selectionSort, arrSelection, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arrInsertion, n);
    SortTestHelper::testSort("Bubble Sort", bubbleSort, arrBubble, n);

    delete[] arr;
    delete[] arrSelection;
    delete[] arrInsertion;
    delete[] arrBubble;
    return 0;
}
