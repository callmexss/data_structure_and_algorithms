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
#include <ctime>

#include "sortalg.h"
#include "sorttesthelper.h"

using namespace std;

int main(int argc, char const *argv[])
{
    size_t n = 100000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    // int* arr = SortTestHelper::generateNearlyOrderedArray(n, 100);

    cout << "---------------------- Array test ---------------------- " << endl;

    int *arrSelection = SortTestHelper::copyIntArray(arr, n);
    int *arrInsertion = SortTestHelper::copyIntArray(arr, n);
    int *arrBubble = SortTestHelper::copyIntArray(arr, n);
    int *arrShell = SortTestHelper::copyIntArray(arr, n);
    int *arrMerge = SortTestHelper::copyIntArray(arr, n);
    int *arrQuick = SortTestHelper::copyIntArray(arr, n);
    int *arrHeap = SortTestHelper::copyIntArray(arr, n);
    int *arrHeap1 = SortTestHelper::copyIntArray(arr, n);
    int *arrHeap2 = SortTestHelper::copyIntArray(arr, n);

    // SortTestHelper::testSort("Selection Sort", selectionSort, arrSelection, n);
    // SortTestHelper::testSort("Insertion Sort", insertionSort, arrInsertion, n);
    // SortTestHelper::testSort("Bubble Sort", bubbleSort, arrBubble, n);
    SortTestHelper::testSort("Shell Sort", shellSort, arrShell, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arrMerge, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arrQuick, n);
    SortTestHelper::testSort("Heap Sort", heapSort, arrHeap, n);
    SortTestHelper::testSort("Heap Sort 1", heapSort1, arrHeap1, n);
    SortTestHelper::testSort("Heap Sort 2", heapSort2, arrHeap2, n);

    delete[] arr;
    delete[] arrSelection;
    delete[] arrInsertion;
    delete[] arrBubble;
    delete[] arrMerge;
    delete[] arrQuick;
    delete[] arrHeap;
    delete[] arrHeap1;
    delete[] arrHeap2;

    cout << "---------------------- Vector test ---------------------- " << endl;

    vector<int> vec = SortTestHelper::generateRandomIntVector(n, 0, n);
    vector<int> vecSelection = vec;
    vector<int> vecInsertion = vec;
    vector<int> vecBubble = vec;
    vector<int> vecShell = vec;
    vector<int> vecMerge = vec;

    // SortTestHelper::testSort("Selection Sort", selectionSort, vecSelection);
    // SortTestHelper::testSort("Insertion Sort", insertionSort, vecInsertion);
    // SortTestHelper::testSort("Bubble Sort", bubbleSort, vecBubble);
    // SortTestHelper::testSort("Shell Sort", shellSort, vec);
    SortTestHelper::testSort("Merge Sort", mergeSort, vec);

    cout << "Heap test:" << endl;
    // MaxHeap<int> maxHeap = MaxHeap<int>(100);
    const int testN = 5;
    int *arrTest = SortTestHelper::generateRandomArray(testN);
    // MaxHeap<int> maxHeap = MaxHeap<int>(arrTest, 10);
    // srand(time(NULL));
    // for (int i = 0; i < 10; i++)
    // {
    //     maxHeap.insert(rand() % 100);
    // }

    // while (!maxHeap.isEmpty())
    // {
    //     cout << maxHeap.extractMax() << endl;
    // }

    int arrGiven[testN] = {59, 21, 22, 9, 19};

    SortTestHelper::printArray(arrGiven, testN);
    heapSort(arrGiven, testN);
    SortTestHelper::printArray(arrGiven, testN);
    delete[] arrTest;

    return 0;
}
