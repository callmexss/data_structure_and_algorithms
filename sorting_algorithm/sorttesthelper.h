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


namespace SortTestHelper 
{
    int * generateRandomArray(int n=10, int rangeL=0, int rangeR=100)
    {
        assert(rangeL < rangeR);

        int * arr = new int[n];
        srand(time(NULL));
        for (int i = 0; i < n; i++)
        {
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }
        return arr;
    }

    template<typename T>
    void printArray(T arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
    
} // namespace SortTestHelper  
