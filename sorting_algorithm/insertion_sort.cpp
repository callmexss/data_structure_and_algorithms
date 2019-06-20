/***********************************************
 *
 *      Filename: insertion_sort.cpp
 *
 *        Author: xss - callmexss@126.com
 *   Description: insertion sort
 *        Create: 2017-12-06 21:28:36
 *
 ***********************************************/


#include <iostream>

#include "sorttesthelper.h"

using namespace std;


void InsertionSort(int *num, int len)
{
    int i, j ,temp;

    for (i = 1; i < len; i++)
    {
        temp = num[i];

        for (j = i; j > 0 && num[j-1] > temp; j--)
        {
            num[j] = num[j-1];
        }

        num[j] = temp;
            
    }

}


void Insert(int num[], int len)
{
    int i, temp;
    temp = num[len];

    for (i = len - 1; i >= 0 && temp < num[i]; i--)
    {
        num[i+1] = num[i];
    }
    num[i+1] = temp;
}


void InsertionSortRecursion(int num[], int len)
{
    if (len > 0)
    {
        InsertionSortRecursion(num, len - 1);
        Insert(num, len);
    }
}

int main(int argc, const char *argv[])
{
    // int num[] = {3, 1, 4, 9, 2, 6, 5, 3};
    //InsertionSort(num, 8);
    int n = 30;
    int *num = SortTestHelper::generateRandomArray(n);
    InsertionSortRecursion(num, n);

    SortTestHelper::printArray(num, n);

    delete[] num;
    
    return 0;
}


// reference: http://www.cnblogs.com/zhuorongtan/archive/2012/09/22/2698339.html
