/***********************************************
 *
 *      Filename: insertion_sort.cpp
 *
 *        Author: xss - callmexss@126.com
 *   Description: ---
 *        Create: 2017-12-06 21:28:36
 *
 ***********************************************/


#include <iostream>

using namespace std;

void InsertionSort(int num[], int len)
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

int main(int argc, const char *argv[])
{
    int num[] = {3, 1, 4, 9, 2, 6, 5, 3};
    InsertionSort(num, 8);
    for (int i = 0; i < 8; i++)
    {
        cout << num[i] << " ";
    }
    cout << endl;
    
    return 0;
}
