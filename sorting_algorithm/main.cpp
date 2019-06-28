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
#include <vector>

#include "sortalg.h"
#include "sorttesthelper.h"

using namespace std;


int main(int argc, char const *argv[])
{
    size_t n = 5000;
    int* arr = SortTestHelper::generateRandomArray(n, 0, n);
    // int* arr = SortTestHelper::generateNearlyOrderedArray(n, 100);

    cout << "---------------------- Array test ---------------------- " << endl;

    int* arrSelection = SortTestHelper::copyIntArray(arr, n);
    int* arrInsertion = SortTestHelper::copyIntArray(arr, n);
    int* arrBubble = SortTestHelper::copyIntArray(arr, n);
    int* arrShell = SortTestHelper::copyIntArray(arr, n);
    int* arrMerge = SortTestHelper::copyIntArray(arr, n);
    int* arrQuick = SortTestHelper::copyIntArray(arr, n);

    SortTestHelper::testSort("Selection Sort", selectionSort, arrSelection, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arrInsertion, n);
    SortTestHelper::testSort("Bubble Sort", bubbleSort, arrBubble, n);
    SortTestHelper::testSort("Shell Sort", shellSort, arrShell, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arrMerge, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arrQuick, n);

    vector<int> vec = SortTestHelper::generateRandomIntVector(n, 0, n);
    vector<int> vecSelection = vec;
    vector<int> vecInsertion = vec;
    vector<int> vecBubble = vec;
    vector<int> vecShell = vec;
    vector<int> vecMerge = vec;

    cout << "---------------------- Vector test ---------------------- " << endl;

    SortTestHelper::testSort("Selection Sort", selectionSort, vecSelection);
    SortTestHelper::testSort("Insertion Sort", insertionSort, vecInsertion);
    SortTestHelper::testSort("Bubble Sort", bubbleSort, vecBubble);
    SortTestHelper::testSort("Shell Sort", shellSort, vec);
    SortTestHelper::testSort("Merge Sort", mergeSort, vec);

    delete[] arr;
    delete[] arrSelection;
    delete[] arrInsertion;
    delete[] arrBubble;
    delete[] arrMerge;
    return 0;
}
