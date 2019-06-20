'''
File:          selection_sort.py
File Created:  Thursday, 20th June 2019 9:20:16 pm
Author:        xss (callmexss@126.com)
Description:   selection sort
-----
Last Modified: Thursday, 20th June 2019 9:21:18 pm
Modified By:   xss (callmexss@126.com)
-----
'''
import pyhandy


def selection_sort(arr):
    for i in range(len(arr)):
        min_index = i
        for j in range(i + 1, len(arr)):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]


if __name__ == '__main__':
    worker = pyhandy.pyhandy.RandomWorker()
    arr = worker.gen_list(scope=(0, 100))
    selection_sort(arr)
    print(arr)

