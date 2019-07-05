#include <iostream>
#include <cassert>

#include "../sorting_algorithm/sorttesthelper.h"
#include "../sorting_algorithm/sortalg.h"


using namespace std;

template <typename T>
int binarySearch(T arr[], int n, int target)
{
    if (n <= 0)
        return -1;

    // arr[left...right]
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

template <typename T>
int __binarySearch(T arr[], int l, int r, T target)
{
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            return __binarySearch(arr, l, mid - 1, target);
        else
            return __binarySearch(arr, mid + 1, r, target);
    }
    return -1;
}

template <typename T>
int binarySearch2(T arr[], int n, T target)
{
    int l = 0;
    int r = n - 1;

    return __binarySearch(arr, l, r, target);
}


int main()
{
    const int n = 5;
    int arr[n] = {1, 2, 3, 7, 4};

    assert(binarySearch(arr, n, 7) == 3);
    assert(binarySearch2(arr, n, 7) == 3);

    int n1 = 50;
    int *arr1 = SortTestHelper::generateRandomArray(n1, 0, 100);
    quickSort(arr1, n1);
    SortTestHelper::printArray(arr1, n1);
    cout << binarySearch(arr1, n1, 1) << endl;
    cout << binarySearch2(arr1, n1, 1) << endl;
    cout << binarySearch(arr1, n1, 50) << endl;
    cout << binarySearch2(arr1, n1, 50) << endl;

    
    return 0;
}
