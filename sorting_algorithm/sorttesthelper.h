/*
 * File:          sorttesthelper.h
 * File Created:  Thursday, 20th June 2019 8:32:58 am
 * Author:        xss (callmexss@126.com)
 * Description:   helper function for sort algorithm test
 * -----
 * Last Modified: Thursday, 20th June 2019 8:33:03 am
 * Modified By:   xss (callmexss@126.com)
 * -----
 */

#include <iostream>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>

namespace SortTestHelper
{

int *generateRandomArray(int n = 10, int rangeL = 0, int rangeR = 100)
{
    assert(rangeL < rangeR);

    int *arr = new int[n];
    srand(time(NULL));
    for (int i = 0; i < n; ++i)
    {
        arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
    }
    return arr;
}

std::vector<int> generateRandomIntVector(int n = 10, int rangeL = 0, int rangeR = 100)
{
    assert(rangeL < rangeR);
    std::vector<int> vec;
    srand(time(NULL));
    for (int i = 0; i < n; ++i)
    {
        vec.push_back(rand() % (rangeR - rangeL) + rangeL);
    }
    return vec;
}

int *generateNearlyOrderedArray(int n = 1000, int swapTimes = 10)
{
    int *arr = new int[n];
    for (int i = 0; i < n; ++i)
        arr[i] = i;

    srand(time(NULL));

    for (int i = 0; i < swapTimes; ++i)
    {
        int posx = rand() % n;
        int posy = rand() % n;
        std::swap(arr[posx], arr[posy]);
    }

    return arr;
}

std::vector<int> generateNearlyOrderedIntVector(int n = 1000, int swapTimes = 10)
{
    std::vector<int> vec;
    for (int i = 0; i < n; ++i)
    {
        vec.push_back(i);
    }
    for (int i = 0; i < swapTimes; ++i)
    {
        int posx = rand() % n;
        int posy = rand() % n;
        std::swap(vec[posx], vec[posy]);
    }
    return vec;
}

template <typename T>
void printArray(T arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void printVector(const std::vector<T> &vec)
{
    for (auto const &val : vec)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

template <typename T>
bool isSorted(T arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        if (arr[i] > arr[i + 1])
            return false;
    }

    return true;
}

template <typename T>
bool isSorted(std::vector<T> vec)
{
    for (int i = 0; i < vec.size() - 1; ++i)
    {
        if (vec[i] > vec[i + 1])
            return false;
    }
    return true;
}

template <typename T>
void testSort(std::string sortName, void (*sort)(T[], int n), T arr[], int n)
{
    clock_t startTime = clock();
    sort(arr, n);
    clock_t endTime = clock();
    assert(isSorted(arr, n));

    std::cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << std::endl;
}

template <typename T>
void testSort(std::string sortName, void (*sort)(std::vector<T> &), std::vector<T> &vec)
{
    clock_t startTime = clock();
    sort(vec);
    clock_t endTime = clock();
    assert(isSorted(vec));

    std::cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << std::endl;
}

int *copyIntArray(int a[], int n)
{
    int *arr = new int[n];
    std::copy(a, a + n, arr);
    return arr;
}

} // namespace SortTestHelper
